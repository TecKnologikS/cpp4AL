#ifndef GPIO_CLASS_H
#define GPIO_CLASS_H

#include <string>
using namespace std;
class GpioClass
{
public:
    GpioClass();  // creer un gpio avec comme valeur par default 4
    GpioClass(string x); // creer un gpio avec la valeur x en param
    int export_gpio(); // export 
    int unexport_gpio(); // unexport
    int setdir_gpio(string dir); // change le sens du GPIO 
    int setval_gpio(string val); // change la veleur du gpio (out)
    int getval_gpio(string& val); // recup la valeur du gpio (in/out)
    string get_gpionum(); // retourn le numero du gpio en fonction de la valeur passer en param
private:
    string gpionum; // numero du gpio de l objet
};

#endif
