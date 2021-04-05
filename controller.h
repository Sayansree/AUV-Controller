/* written by Sayansree Paria
 * email : sayansreeparia@gmail.com
 * github : https://github.com/Sayansree
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H
#define CONTROLLER_CONFIG_FILE "config.json"
#include "HAUVC-Model/model.h"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
class controller{
    public:
        controller();
        ~controller();
        void configure();
        void setMode(actionMode,axis);
        double* update(action[6]);

    private:
        std::vector<model*> dof;
        std::string DOF_NAME[6]={"PITCH","ROLL","YAW","SURGE","SWAY","HEAVE"};
        void init();
        
};
#endif
