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
        std::cout<<root[DOF_NAME[i]];
    }
        
    
}
void controller::init(){
    for(int i = PITCH; i <= HEAVE; i++)
        dof.push_back(new model());
}

int main()
{
    controller *c=new controller();
}