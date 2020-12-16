/**
 *   @file: household.cc
 * @author: Ethan Dowalter
 *   @date: July 7, 2020
 *  @brief: Household class implementation
 */

#include "household.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;


/// Default constructor
Household::Household(string head, string add, int occ, int inc){
    house_head = head;            //default is empty string
    address = add;                //default is empty string
    occupants = occ;              //default 0
    income = inc;                 //default 0
}


/// Setters
void Household::set_head(const string& hd){
    house_head = hd;
}

void Household::set_address(const string& add){
    address = add;
}

void Household::set_occupants(int num){
    if (num > 0){               //must be people living in household
        occupants = num;
    }
}

void Household::set_income(int inc){
    income = inc;
}


/// Getters
string Household::get_head()const{
    return house_head;
}

string Household::get_address()const{
    return address;
}

int Household::get_occupants()const{
    return occupants;
}

int Household::get_income()const{
    return income;
}


/// Input and output
void Household::input(istream& ins){
    string tmp;                 //used to read in house_head and adress
    if (&ins == &cin){          //taking input from a user
        // while (ins.peek() == '\n' || ins.peek() == '\r'){
        //     ins.ignore();           //skip over unneeded chars that are left after normal ins >> input
        // }

        cout << "Please enter the name of the head of household : ";
        getline(ins, tmp);
        house_head = tmp;

        cout << "Now enter the house address : ";
        getline(ins, tmp);
        address = tmp;

        cout << "And the number of occupants residing there : ";
        ins >> occupants;

        cout << "Finally, enter the annual household income : ";
        ins >> income;

    } else {                    //taking input from a file
        while (ins.peek() == '\n' || ins.peek() == '\r'){
            ins.ignore();           //skip over unneeded chars that are left after normal ins >> input
        }
        getline(ins, tmp);
        house_head = tmp;
        getline(ins, tmp);
        address = tmp;
        ins >> occupants;
        ins >> income;
    }
    
}

void Household::output(ostream& outs)const{
    if (&outs == &cout)                   //prints labels if printing to screen
    {
        outs << setw(26) << "Head of household : " << house_head << endl;
        outs << setw(26) <<"Address : " << address << endl;
        outs << setw(26) <<"Number of occupants : " << occupants << endl;
        outs << setw(26) <<"Annual household income : " << income << endl;
        outs << endl;
    } else {                            //else info goes into file w/o labels
        outs << house_head << endl;
        outs << address << endl;
        outs << occupants << endl;
        outs << income << endl;
    }
    
    
}


/// Overloaded i/o operators
istream& operator >> (istream& ins, Household& h){
    h.input(ins);
    return ins;
}

ostream& operator << (ostream& outs, const Household& h){
    h.output(outs);
    return outs;
}