/* written by Sayansree Paria
 * email : sayansreeparia@gmail.com
 * github : https://github.com/Sayansree
 */

#ifndef THRUSTER_PLUGIN_H
#define THRUSTER_PLUGIN_H


class ThrusterPlugin{
    public:
        ThrusterPlugin();
        ~ThrusterPlugin();
        void configure(double [][6],int);
        double* write(double[6]);
        double* trim(double[]);

    private:
        int N;
        
};
#endif
