/* written by Sayansree Paria
 * email : sayansreeparia@gmail.com
 * github : https://github.com/Sayansree
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "HAUVC-Model/model.h"
#include <iostream>
#include <vector>
#include "json/json.h"
class controller{
    public:
        controller();
        ~controller();
        void configure();

    private:
        std::vector<model*> dof;
        
};
#endif
