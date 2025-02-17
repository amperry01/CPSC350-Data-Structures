// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA5: Scare Games

#include "Monster.h"

#include <cstdlib>
#include <string>

Monster::Monster(){
    m_name = "";
    m_screamPowerLvl = 0;
}

Monster::Monster(string name, int screamPowerLvl){
    m_name = name;
    m_screamPowerLvl = screamPowerLvl;
}

Monster::~Monster(){

}

string Monster::getName(){
    return m_name;
}

int Monster::getScreamPowerLvl(){
    return m_screamPowerLvl;
}

// ** BEGIN CODE FROM SOURCE: https://stackoverflow.com/questions/10575766/comparison-operator-overloading **
bool Monster::operator>(const Monster& other) const {
    return this->m_screamPowerLvl > other.m_screamPowerLvl;
}
// ** END CODE FROM SOURCE: https://stackoverflow.com/questions/10575766/comparison-operator-overloading **

// For the purposes of this project, I am going to assume no screamPowerLvl can be equal
// template <typename T>
// bool Monster<T>::operator==(const Monster& other){
//     return m_screamPowerLvl == other.m_screamPowerLvl;
// }