#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "GPIOClass.h"

using namespace std;

int main(int argc, char* argv[]) { 

    if (argc > 1) {
        GPIOClass* gpio = new GPIOClass(argv[0]); 
        if(argv[1] == "enable") {
            gpio->setval_gpio("1");
        } else if(argv[1] == "disable") {
                gpio->setval_gpio("0");
        } else if(argv[1] == "change") {
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