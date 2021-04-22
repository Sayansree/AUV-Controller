#include "thrusterPlugin.h"

ThrusterPlugin::ThrusterPlugin(){
    if((HOME_PATH=getenv("HOME"))=="")
        HOME_PATH=getpwuid(getuid())->pw_dir;
    fd=-1;
    configure();
    openPipe();
}
ThrusterPlugin::~ThrusterPlugin(){
    close(fd);
    unlink(THRUSTER_PIPE.c_str());
}
void ThrusterPlugin::openPipe(){
    mkfifo(THRUSTER_PIPE.c_str(),0666);
    fd = open(THRUSTER_PIPE.c_str(),O_WRONLY);
}
void ThrusterPlugin::configure(){
    boost::property_tree::ptree root;
    try{
        boost::property_tree::read_json(HOME_PATH+CONFIG_FILE,root);
        THRUSTER_PIPE = root.get_child("Pipes").get<std::string>("ThrusterFIFO");
        root =root.get_child("Thruster").get_child("TransformMatrix");
        for (std::pair<const std::__cxx11::string, boost::property_tree::ptree> &rows : root){
            std::vector<double> row;
            for (std::pair<const std::__cxx11::string, boost::property_tree::ptree> &cols : rows.second)
                row.push_back(cols.second.get_value<double>());
            weights.push_back(row);
        }
    }catch(const boost::property_tree::ptree_error msg){
     //cout<<msg.what();
     //todo add log error
    }
    N=weights.size();
    
}
uint8_t ThrusterPlugin::encode(double inp){
    uint8_t out=0;
    inp=(inp+1)*127+1;
    if(inp>255)return 255;
    if(inp<1)return 1;
    return (uint8_t)inp;
}
uint8_t* ThrusterPlugin::encode(double inp[]){
    uint8_t out[N];
    for(int i=0; i<N; i++)
        out[i]=encode(inp[i]);
    return out;
}
void ThrusterPlugin::drive(double dof[]){
    double throttle[N];
    for(int i=0; i<N; i++){
        throttle[i]=0;
        for(int j=0; j<weights[i].size(); j++)
            throttle[i]+=weights[i][j]*dof[j];
    }
    uint8_t *packet=encode(throttle);
    writePipe(packet);
}
void ThrusterPlugin::writePipe(uint8_t *packet){
    write(fd,packet,N);
}