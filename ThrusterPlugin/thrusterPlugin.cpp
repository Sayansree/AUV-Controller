#include "thrusterPlugin.h"

ThrusterPlugin::ThrusterPlugin(){

}
ThrusterPlugin::~ThrusterPlugin(){

}
void ThrusterPlugin::configure(std::vector<std::vector<double>> weights){
    this->weights=weights;
}
double* ThrusterPlugin::trim(double inp[]){
    double out[weights.size()];
    for(int i=0; i<weights.size(); i++)
        out[i]=trim(inp[i]);
    return out;
}
void ThrusterPlugin::write(double dof[]){
    double throttle[weights.size()];
    for(int i=0; i<weights.size(); i++){
        throttle[i]=0;
        for(int j=0; j<weights[i].size(); j++)
            throttle[i]+=weights[i][j]*dof[j];
    }
    
}