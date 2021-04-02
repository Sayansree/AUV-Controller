/* written by Sayansree Paria
 * email : sayansreeparia@gmail.com
 * github : https://github.com/Sayansree
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H
#define CONTROLLER_CONFIG_FILE "controller.config"
#include "HAUVC-Model/model.h"
#include "json/json.h"
#include <iostream>
#include <vector>
#include <fstream>

class controller{
    public:
        controller();
        ~controller();
        void configure();

    private:
        std::vector<model*> dof;
        void init();
        
};
#endif
