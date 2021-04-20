#include "thrusterPlugin.h"

ThrusterPlugin::ThrusterPlugin(){

}
ThrusterPlugin::~ThrusterPlugin(){

}
void ThrusterPlugin::configure(std::vector<std::vector<double>> weights){
    this->weights=weights;
    N=weights.size();
}
double ThrusterPlugin::trim(double inp){
    if(inp>1)return 1;
    if(inp<-1)return -1;
}
double* ThrusterPlugin::trim(double inp[]){
    double out[N];
    for(int i=0; i<N; i++)
        out[i]=trim(inp[i]);
    return out;
}
void ThrusterPlugin::write(double dof[]){
    double throttle[N];
    for(int i=0; i<N; i++){
        throttle[i]=0;
        for(int j=0; j<weights[i].size(); j++)
            throttle[i]+=weights[i][j]*dof[j];
    }
    double *trimmed=trim(throttle);
    
}