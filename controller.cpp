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
    boost::property_tree::ptree root,degree,basefuc,vel,disp,limit;
    try{
        boost::property_tree::read_json("file.json",root);
        root =root.get_child("Controller");
        for(int i = PITCH; i <= HEAVE; i++){
            degree=root.get_child(DOF_NAME[i]);
            basefuc=degree.get_child("BaseFunction");
            vel=degree.get_child("Velocity");
            disp=degree.get_child("Displacement");
            limit=degree.get_child("ILimit");
            dof[i]->setCoeff(basefuc.get<double>("A2"),
                            basefuc.get<double>("A1"),
                            basefuc.get<double>("A0"));
            dof[i]->setILimits(limit.get<double>("Lo"),
                               limit.get<double>("Hi"));
            dof[i]->setVelWeights(vel.get<double>("Kp"),
                                  vel.get<double>("Ki"),
                                  vel.get<double>("Kd"));
            dof[i]->setDispWeights(disp.get<double>("Kp"),
                                   disp.get<double>("Ki"),
                                   disp.get<double>("Kd"));
        }
    }catch(const boost::property_tree::ptree_error msg){
     //cout<<msg.what();
     //todo add log error
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
void controller::setMode(actionMode mode, axis ax){
    dof[ax]->setMode(mode);
}