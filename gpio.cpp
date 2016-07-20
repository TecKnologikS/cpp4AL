#include <cstring>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "GPIOClass.h"

using namespace std;

int main(int argc, char* argv[]) { 
    std::cout << "nb param " << argc  << std::endl;
    if (argc > 2) {
        GPIOClass* gpio = new GPIOClass(argv[1]); 
        cout << " gpio " << argv[1] << " command " << argv[2] << endl;
        if(strncmp(argv[2], "enable", 0)) {
            gpio->setval_gpio("1");
        } else if(strncmp(argv[2], "disable", 0)) {
                gpio->setval_gpio("0");
        } else if(strncmp(argv[2], "change", 0)) {
            string inputstate;
            gpio->getval_gpio(inputstate); 
            if(inputstate == "0")
            {
                gpio->setval_gpio("1");
            } else {
                gpio->setval_gpio("0");
            }
        } else {
            return 0;
        }
        return 1;
    } else {
        return 0;
    }
}
