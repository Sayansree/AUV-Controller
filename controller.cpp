/* written by Sayansree Paria
 * email : sayansreeparia@gmail.com
 * github : https://github.com/Sayansree
 */

#include "controller.h"

controller::controller(){
    for(int i = PITCH; i <= HEAVE; i++)
        dof.push_back(new model());
}
controller::~controller(){

}
void controller::configure(){
    for(model *m:dof){
        
    }
}