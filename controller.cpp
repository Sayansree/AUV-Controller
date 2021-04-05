/* written by Sayansree Paria
 * email : sayansreeparia@gmail.com
 * github : https://github.com/Sayansree
 */

#include "controller.h"

controller::controller(){
    init();
    configure();
}
controller::~controller(){

}
void controller::configure(){
    std::fstream connfigFile;
    std::stringstream strStream;
    
    connfigFile.open(CONTROLLER_CONFIG_FILE ,std::ios::in); 
    strStream << connfigFile.rdbuf(); 
    std::string jsonString = strStream.str();

    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    Json::Value root;
    std::string errors;

    bool parsingSuccessful = reader->parse(jsonString.c_str(),
        jsonString.c_str() + jsonString.size(), &root, &errors);
    delete reader;

    if (!parsingSuccessful){
        //to do add log failure
    }
    for(int i = PITCH; i <= HEAVE; i++){
        Json::Value data=root["Controller"][DOF_NAME[i]];
        dof[i]->setCoeff(data["BaseFunction"]["a2"].asDouble(),
                         data["BaseFunction"]["a1"].asDouble(),
                         data["BaseFunction"]["a0"].asDouble());
        dof[i]->setILimits(data["ILimits"]["lo"].asDouble(),
                           data["ILimits"]["hi"].asDouble());
        dof[i]->setVelWeights(data["velocity"]["Kp"].asDouble(),
                              data["velocity"]["Ki"].asDouble(),
                              data["velocity"]["Kd"].asDouble());
        dof[i]->setDispWeights(data["displacement"]["Kp"].asDouble(),
                              data["displacement"]["Ki"].asDouble(),
                              data["displacement"]["Kd"].asDouble());
    }    
}
void controller::init(){
    for(int i = PITCH; i <= HEAVE; i++)
        dof.push_back(new model());
}
double* controller::update(action actionSet[]){
    double output[6];
    for(int i = PITCH; i <= HEAVE; i++){
        output[i]=dof[i]->update(actionSet[i]);
    }
    return output;
}
int main()
{
    controller *c=new controller();
}