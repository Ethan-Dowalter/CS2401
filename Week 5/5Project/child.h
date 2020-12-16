/**
 *        @file: child.h
 *      @author: Ethan Dowalter
 *        @date: August 1, 2020
 *       @brief: 
 */

#include <iostream>
#include "parent.h"
#ifndef CHILD_H
#define CHILD_H
using namespace std;

class Dune:public AnimalHome{
    public:
        Dune();
        void input(istream &ins);
        void output(ostream &outs);
    private:
        int grainSize_um;           //average sand grain diameter in micrometers
        int cubic_yards;            //cubic yards of sand
};

class MeerkatWarren:public AnimalHome{
    public:
        MeerkatWarren();
        void input(istream &ins);
        void output(ostream &outs);
    private:
        int entrences;              //total number of access points to the warren
        double avg_depth_ft;        //average depth of the tunnel network in ft
        bool is_two_levels;         //whether or not the tunnel network has one or two main levels
        
};

class TreeHollow:public AnimalHome{
    public:
        TreeHollow();
        void input(istream &ins);
        void output(ostream &outs);
    private:
        double diameter_in;         //diameter of the entrence in inches
        double depth_in;            //depth of the cavity in inches
};

class Pasture:public AnimalHome{
    public:
        Pasture();
        void input(istream &ins);
        void output(ostream &outs);
    private:
        double acres;               //acreage to be fenced in
        double perimeter;           //perimeter of pasture that is to be fenced in
        bool is_barbed_wire;        //whether or not fence is barbed wire or wooden
};

class Mound:public AnimalHome{
    public:
        Mound();
        void input(istream &ins);
        void output(ostream &outs);
    private:
        double height_ft;           //height of termite mound in ft
        int num_queens;             //number of queens in the colony
};

class FreshAquarium:public AnimalHome{
    public:
        FreshAquarium();
        void input(istream &ins);
        void output(ostream &outs);
    private:
        bool is_round;              //whether or not tank is circular or rectangular
        double radius_ft;           //radius of aquarium in ft (only if round)
        double length_ft;           //length of aqaurium in ft (only if not round)
        double width_ft;            //width of aqaurium in ft (only if not round)
        double depth_ft;            //depth of aqaurium in ft
};

#endif