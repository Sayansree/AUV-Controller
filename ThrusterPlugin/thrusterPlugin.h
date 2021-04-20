/* written by Sayansree Paria
 * email : sayansreeparia@gmail.com
 * github : https://github.com/Sayansree
 */

#ifndef THRUSTER_PLUGIN_H
#define THRUSTER_PLUGIN_H
#include <vector>

class ThrusterPlugin{
    public:
        ThrusterPlugin();
        ~ThrusterPlugin();
        void configure(std::vector<std::vector<double>>);
        void write(double[]);
        

    private:
        int N;
        std::vector<std::vector<double>> weights;
        double* trim(double[]);
        double trim(double);
        
};
#endif
