// AUTHOR INFO
// Full name: Alyssa Perry 
// Student ID: 2347996
// Chapman Email: alperry@chapman.edu 
// Course number and section: CPSC-350-02
// Assignment or exercise number: PA5: Scare Games

#ifndef MONSTER_H
#define MONSTER_H

#include <cstdlib>
#include <string>

using namespace std;

class Monster{
    public:
        Monster(); // default constructor
        Monster(string name, int screamPowerLvl); // overloaded constructor
        virtual ~Monster(); // default destructor
        string getName();
        int getScreamPowerLvl();

        // ** BEGIN CODE FROM SOURCE: https://stackoverflow.com/questions/10575766/comparison-operator-overloading **
        bool operator>(const Monster& other) const; // overloaded comparison operator
        // bool operator==(const Monster& other);
        // ** END CODE FROM SOURCE: https://stackoverflow.com/questions/10575766/comparison-operator-overloading **

    private:
        string m_name;
        int m_screamPowerLvl;

};

#endif