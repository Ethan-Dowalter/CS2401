/**
 *        @file: parent.h
 *      @author: Ethan Dowalter
 *        @date: August 1, 2020
 *       @brief: 
 */

#include <iostream>
#ifndef PARENT_H
#define PARENT_H
using namespace std;

class AnimalHome{
    public:
        AnimalHome();
        virtual void input(istream &ins);
        virtual void output(ostream &outs);
    protected:
        int occupants;
};

#endif