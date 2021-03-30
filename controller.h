/* written by Sayansree Paria
 * email : sayansreeparia@gmail.com
 * github : https://github.com/Sayansree
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "HAUVC-Model/model.h"
#include <iostream>
#include <vector>

class controller{
    public:
        controller();
        ~controller();
        void Configure();

    private:
        std::vector<model*> dof;
        
};
#endif
