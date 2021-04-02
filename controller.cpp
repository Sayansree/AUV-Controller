/* written by Sayansree Paria
 * email : sayansreeparia@gmail.com
 * github : https://github.com/Sayansree
 */

#include "controller.h"

controller::controller(){
    init();
}
controller::~controller(){

}
void controller::configure(){
    std::fstream connfigFile;
    std::stringstream strStream;
    
    connfigFile.open(CONTROLLER_CONFIG_FILE ,std::ios::in); 
    strStream << connfigFile.rdbuf(); 
    std::string jsonString = strStream.str();
    for(int i = PITCH; i <= HEAVE; i++){

        
    }
        
    
}
void controller::init(){
    for(int i = PITCH; i <= HEAVE; i++)
        dof.push_back(new model());
}