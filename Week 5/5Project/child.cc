/**
 *        @file: child.cc
 *      @author: Ethan Dowalter
 *        @date: August 1, 2020
 *       @brief: 
 */

#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include "child.h"
using namespace std;

static const char micro = 230;              //ascii code for lowercase greek "Mu" for micro units

Dune::Dune(){
    grainSize_um = 0;
    cubic_yards = 0;
    occupants = 0;
}

void Dune::input(istream &ins){
    if (&ins == &cin)
    {
        int tmp;
        cout << "Enter the desired avg sand particle size(" << micro << "m) : ";
        ins >> tmp;
        grainSize_um = tmp;
        cout << "Enter the desired number of cubic yards : ";
        ins >> tmp;
        cubic_yards = tmp;
    }
    else
    {
        ins >> grainSize_um;
        ins >> cubic_yards;
    }
    AnimalHome::input(ins);
}

void Dune::output(ostream &outs){
    outs << "Dune" << endl;
    if (&outs == &cout)
    {
        outs << "Avg grain size = " << grainSize_um << ' ' << micro << 'm' << endl;
        outs << "Cubic yards = " << cubic_yards << " cy" << endl;
    }
    else
    {
        outs << grainSize_um << endl;
        outs << cubic_yards << endl;
    }
    AnimalHome::output(outs);
}





MeerkatWarren::MeerkatWarren(){
    entrences = 0;
    avg_depth_ft = 0;
    is_two_levels = false;
    occupants = 0;
}

void MeerkatWarren::input(istream &ins){
    if (&ins == &cin)
    {
        int itmp;
        double dtmp;
        cout << "Enter the desired number of entrences : ";
        ins >> itmp;
        entrences = itmp;
        cout << "Enter the desired avg depth(ft) : ";
        ins >> dtmp;
        avg_depth_ft = dtmp;
        if (avg_depth_ft >= 2)
        {
            cout << "Is it a double decker burrow? (0 - no, 1 - yes) : ";
            ins >> itmp;
            is_two_levels = itmp;
        }
        else
        {
            is_two_levels = false;
        }
    }
    else
    {
        ins >> entrences;
        ins >> avg_depth_ft;
        ins >> is_two_levels;
    }
    AnimalHome::input(ins);
}

void MeerkatWarren::output(ostream &outs){
    outs << "MeerkatWarren" << endl;
    if (&outs == &cout)
    {
        outs << "Entrences = " << entrences << endl;
        outs << "Avg depth = " << avg_depth_ft << " ft" << endl;
        if (is_two_levels == true)
        {
            outs << "Levels = 2" << endl;
        }
        else
        {
            outs << "Levels = 1" << endl;
        }
    }
    else
    {
        outs << entrences << endl;
        outs << avg_depth_ft << endl;
        outs << is_two_levels << endl;
    }
    AnimalHome::output(outs);
}





TreeHollow::TreeHollow(){
    occupants = 0;
}

void TreeHollow::input(istream &ins){
    if (&ins == &cin)
    {
        double tmp;
        cout << "Enter the desired diameter(in) : ";
        ins >> tmp;
        diameter_in = tmp;
        cout << "Enter the desired depth(in) : ";
        ins >> tmp;
        depth_in = tmp;
    }
    else
    {
        ins >> diameter_in;
        ins >> depth_in;
    }
    AnimalHome::input(ins);
}

void TreeHollow::output(ostream &outs){
    outs << "TreeHollow" << endl;
    if (&outs == &cout)
    {
        outs << "Diameter = " << diameter_in << " in" << endl;
        outs << "Depth = " << depth_in << " in" << endl;
    }
    else
    {
        outs << diameter_in << endl;
        outs << depth_in << endl;
    }
    AnimalHome::output(outs);
}





Pasture::Pasture(){
    acres = 0;
    perimeter = 0;
    is_barbed_wire = false;
    occupants = 0;
}

void Pasture::input(istream &ins){
    if (&ins == &cin)
    {
        double tmp;
        cout << "Enter the desired acreage : ";
        ins >> tmp;
        acres = tmp;
        do
        {
            cout << "Note: Perimeter should be greater than or equal to the circumference of a ";
            cout << "circle with given acreage ( >= sqrt(43560 * acres / pi) * 2 * pi)" << endl;
            cout << "Enter the desired perimeter(ft) : ";
            ins >> tmp;
            perimeter = tmp;
        } while (perimeter < sqrt(43560 * acres / M_PI) * 2 * M_PI);            //check for a valid perimeter
        cout << "What kind of fencing? (0 - normal wooden, 1 - barbed wire) : ";
        ins >> tmp;
        is_barbed_wire = tmp;
    }
    else
    {
        ins >> acres;
        ins >> perimeter;
        ins >> is_barbed_wire;
    }
    AnimalHome::input(ins);
}

void Pasture::output(ostream &outs){
    outs << "Pasture" << endl;
    if (&outs == &cout)
    {
        outs << "Acres = " << acres << " ac" << endl;
        outs << "Perimeter = " << perimeter << " ft" << endl;
        if (is_barbed_wire == true)
        {
            outs << "Fencing = Barbed wire" << endl;
        }
        else
        {
            outs << "Fencing = Wooden" << endl;
        }
    }
    else
    {
        outs << acres << endl;
        outs << perimeter << endl;
        outs << is_barbed_wire << endl;
    }
    AnimalHome::output(outs);
}





Mound::Mound(){
    height_ft = 0;
    num_queens = 0;
    occupants = 0;
}

void Mound::input(istream &ins){
    if (&ins == &cin)
    {
        int itmp;
        double dtmp;
        cout << "Enter the desired height(ft) : ";
        ins >> dtmp;
        height_ft = dtmp;
        cout << "Enter the number of queens : ";
        ins >> itmp;
        num_queens = itmp;
    }
    else
    {
        ins >> height_ft;
        ins >> num_queens;
    }
    AnimalHome::input(ins);
}

void Mound::output(ostream &outs){
    outs << "Mound" << endl;
    if (&outs == &cout)
    {
        outs << "Height = " << height_ft << " ft" << endl;
        outs << "Number of queens = " << num_queens << endl;
    }
    else
    {
        outs << height_ft << endl;
        outs << num_queens << endl;
    }
    AnimalHome::output(outs);
}





FreshAquarium::FreshAquarium(){
    is_round = false;
    radius_ft = 0;
    length_ft = 0;
    width_ft = 0;
    depth_ft = 0;
    occupants = 0;
}

void FreshAquarium::input(istream &ins){
    if (&ins == &cin)
    {
        int itmp;
        double dtmp;
        cout << "Do you want a round or rectangular aquarium? (0 - rectangular, 1 - round) : ";
        ins >> itmp;
        is_round = itmp;
        if (is_round == true)
        {
            cout << "Enter the desired radius(ft) : ";
            ins >> dtmp;
            radius_ft = dtmp;
        }
        else
        {
            cout << "Enter the desired length(ft) : ";
            ins >> dtmp;
            length_ft = dtmp;
            cout << "Enter the desired width(ft) : ";
            ins >> dtmp;
            width_ft = dtmp;
        }
        cout << "Enter the desired depth(ft) : ";
        ins >> dtmp;
        depth_ft = dtmp;
    }
    else
    {
        ins >> is_round;
        if (is_round == true)
        {
            ins >> radius_ft;
        }
        else
        {
            ins >> length_ft;
            ins >> width_ft;
        }
        ins >> depth_ft;
    }
    AnimalHome::input(ins);
}

void FreshAquarium::output(ostream &outs){
    outs << "FreshAquarium" << endl;
    if (&outs == &cout)
    {
        double volume;
        if (is_round == true)
        {
            outs << "Type = Round" << endl;
            outs << "Radius = " << radius_ft << " ft" << endl;
            outs << "Depth = " << depth_ft << " ft" << endl;
            volume = M_PI * radius_ft * radius_ft * depth_ft * 7.480519;      //1 cubic ft = 7.480519 gal according to google
            outs << "Volume = " << volume << " gal" << endl;
        }
        else
        {
            outs << "Type = Rectangular" << endl;
            outs << "Length = " << length_ft << " ft" << endl;
            outs << "Width = " << width_ft << " ft" << endl;
            outs << "Depth = " << depth_ft << " ft" << endl;
            volume = length_ft * width_ft * depth_ft * 7.480519;            //1 cubic ft = 7.480519 gal according to google
            outs << "Volume = " << volume << " gal" << endl;
        }
    }
    else
    {
        outs << is_round << endl;
        if (is_round == true)
        {
            outs << radius_ft << endl;
        }
        else
        {
            outs << length_ft << endl;
            outs << width_ft << endl;
        }
        outs << depth_ft << endl;
    }
    AnimalHome::output(outs);
}