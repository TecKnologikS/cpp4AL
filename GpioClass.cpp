#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "GpioClass.h"

using namespace std;

GpioClass::GpioClass()
{
    this->gpionum = "4"; //GPIO4 par default
}

GpioClass::GpioClass(string gnum)
{
    this->gpionum = gnum;  //Creation class gpio avec numero = gnum
}

int GPIOClass::export_gpio()
{
    string export_str = "/sys/class/gpio/export";
    ofstream exportgpio(export_str.c_str()); // Ouvre fichier export (convertion c++ string en string  c, obligatoire sur linux) 
    if (exportgpio < 0){
        cout << " OPERATION FAILED: Unable to export GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
    }

    exportgpio << this->gpionum ; //ecrit le numero du gpio a export
    exportgpio.close(); //ferme fichier export
    return 0;
}

int GPIOClass::unexport_gpio()
{
    string unexport_str = "/sys/class/gpio/unexport";
    ofstream unexportgpio(unexport_str.c_str()); //Ouvre fichier  unexport
    if (unexportgpio < 0){
        cout << " OPERATION FAILED: Unable to unexport GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
    }

    unexportgpio << this->gpionum ; //ecrit le numero du  GPIO à  unexport
    unexportgpio.close(); //ferme fichier  unexport
    return 0;
}

int GPIOClass::setdir_gpio(string dir)
{

    string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "/direction";
    ofstream setdirgpio(setdir_str.c_str()); // ouvre le fichier du sens du  gpio
        if (setdirgpio < 0){
            cout << " OPERATION ERREUR: Impossible de changer le sens du  GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }

        setdirgpio << dir; //change le sens du gpio dans le fichier
        setdirgpio.close(); // ferme le fichier
        return 0;
}

int GPIOClass::setval_gpio(string val)
{

    string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
    ofstream setvalgpio(setval_str.c_str()); // ouvre le fichier du gpio(x)
        if (setvalgpio < 0){
            cout << " OPERATION ERREUR: Impossible de changer la valeur du  GPIO"<< this->gpionum <<" ."<< endl;
            return -1;
        }

        setvalgpio << val ;// ecrit la valeur dans le fichier
        setvalgpio.close();// ferme le fichier de valeur
        return 0;
}

int GPIOClass::getval_gpio(string& val){

    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION ERREUR: Impossible de recup la valeur du GPIO"<< this->gpionum <<" ."<< endl;
        return -1;
            }

    getvalgpio >> val ;  //recup la valeur du gpio

    if(val != "0")
        val = "1";
    else
        val = "0";

    getvalgpio.close(); //ferme le fichier de valeur
    return 0;
}

string GPIOClass::get_gpionum(){

return this->gpionum;

}
