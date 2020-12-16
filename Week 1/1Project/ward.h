/**
 *   @file: ward.h
 * @author: Ethan Dowalter
 *   @date: July 7, 2020
 *  @brief: Ward class definition, contains an array of household classes
 */

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#ifndef WARD_H
#define WARD_H

class Ward{
    public:
        static const size_t CAP = 200;          //max capacity of a ward is 200 households

        /// Default constructor
        Ward();

        /// Input and output
        void add(Household& h);
        void display(ostream& outs);
        void remove(string name);
        Household find(string name);
        void display_richest();
        void display_avg_income();
        void display_avg_people();
        void sort_by_income();
        void sort_by_name();
        void load(istream& ins);
        void save(ostream& outs);

    private:
        Household data[CAP];        //array of households in ward
        size_t used;                //keeps track of number of households in ward
};

/// Overloaded i/o operators
istream& operator >>(istream& ins, Ward& h);
ostream& operator <<(ostream& outs, const Ward& h);

#endif