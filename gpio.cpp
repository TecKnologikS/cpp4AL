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
        gpio->export_gpio();
        gpio->setdir_gpio("out"); 
        cout << " gpio " << argv[1] << " command " << argv[2] << endl;
        if(argv[2].compare("enable") == 0) {
            gpio->setval_gpio("1");
            cout << "enable to 1" << endl;
        } else if(argv[2].compare("disable") == 0) {
            gpio->setval_gpio("0");
            cout << "disable to 0" << endl;
        } else if(argv[2].compare("change") == 0) {
            string inputstate;
            gpio->getval_gpio(inputstate); 
            if(inputstate == "0")
            {
                gpio->setval_gpio("1");
                cout << "change to 1" << endl;
            } else {
                gpio->setval_gpio("0");
                cout << "change to 0" << endl;
            }
        } else {
            cout << "nothin" << endl;
            return 0;
        }
        return 1;
    } else {
        return 0;
    }
}
