/* written by Sayansree Paria
 * email : sayansreeparia@gmail.com
 * github : https://github.com/Sayansree
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H
#define CONFIG_FILE "/.config/AUV/config.json"
#include "HAUVC-Model/model.h"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

class controller{
    public:
        controller();
        ~controller();
        void configureController();
        void configureThrusterPlugin();
        void setMode(actionMode,axis);
        double* update(action[6]);

    private:
        std::vector<model*> dof;
        std::string DOF_NAME[6]={"PITCH","ROLL","YAW","SURGE","SWAY","HEAVE"};
        std::string HOME_PATH;
        void init();
        
};
#endif
