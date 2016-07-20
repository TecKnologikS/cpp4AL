#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "GPIOClass.h"

using namespace std;

int main(int argc, char* argv[]) { 

    if (argc > 1) {
        GPIOClass* gpio = new GPIOClass("" + argv[0]); 
        switch(argv[1]) {
            case "enable":
                gpio->setval_gpio("1");
                break;
            case "disable":
                gpio->setval_gpio("0");
                break;
            case "change":
                string inputstate;
                gpio->getval_gpio(inputstate); 
                if(inputstate == "0")
                {
                    gpio->setval_gpio("1");
                } else {
                    gpio->setval_gpio("0");
                }
                break;
            default:
                return 0;
                break;
        }
        return 1;
    } else {
        return 0;
    }
}