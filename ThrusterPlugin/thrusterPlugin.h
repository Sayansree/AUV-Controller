/* written by Sayansree Paria
 * email : sayansreeparia@gmail.com
 * github : https://github.com/Sayansree
 */

#ifndef THRUSTER_PLUGIN_H
#define THRUSTER_PLUGIN_H
#define CONFIG_FILE "/.config/AUV/config.json"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

class ThrusterPlugin{
    public:
        ThrusterPlugin();
        ~ThrusterPlugin();
        void configure();
        void write(double[]);
        

    private:
        int N;
        std::strinf HOME_PATH;
        std::vector<std::vector<double>> weights;
        double* trim(double[]);
        double trim(double);
        
};
#endif
