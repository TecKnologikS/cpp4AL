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
    if (argc > 1) {
        std::cout << argv[0] << "says hello, " << argv[1] << "!" << std::endl;
        GPIOClass* gpio = new GPIOClass(argv[0]); 
        cout << gpio << argc[0] << " command " << argv[1] << endl;
        if(strncmp(argv[1], "enable", 0)) {
            gpio->setval_gpio("1");
        } else if(strncmp(argv[1], "disable", 0)) {
                gpio->setval_gpio("0");
        } else if(strncmp(argv[1], "change", 0)) {
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
