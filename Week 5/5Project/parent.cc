/**
 *        @file: parent.cc
 *      @author: Ethan Dowalter
 *        @date: August 1, 2020
 *       @brief: 
 */

#include <iostream>
#include <fstream>
#include "parent.h"
using namespace std;

AnimalHome::AnimalHome(){
    occupants = 0;
}

void AnimalHome::input(istream &ins){
    if (&ins == &cin)
    {
        int tmp;
        cout << "Enter the number of occupants : ";
        ins >> tmp;
        occupants = tmp;
    }
    else
    {
        ins >> occupants;
    }
}

void AnimalHome::output(ostream &outs){
    if (&outs == &cout)
    {
        outs << "Occupants = " << occupants << endl << endl;
    }
    else
    {
        outs << occupants << endl;
    }
}
