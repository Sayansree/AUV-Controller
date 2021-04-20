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
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <pwd.h>

class ThrusterPlugin{
    public:
        ThrusterPlugin();
        ~ThrusterPlugin();
        void drive(double[]);
        

    private:
        int N,fd;
        std::string HOME_PATH,THRUSTER_PIPE;
        std::vector<std::vector<double>> weights;
        void configure();
        void openPipe();
        double* trim(double[]);
        double trim(double);
        
};
#endif
