/**
 *        @file: friend.cc
 *      @author: Ethan Dowalter
 *        @date: July 13, 2020
 *       @brief: Class implementation for Friend class
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "friend.h"
using namespace std;

Friend::Friend(){
    name = "";
}

string Friend::get_name()const{
    return name;
}

Date Friend::get_bday()const{
    return bday;
}

bool Friend::operator == (const Friend& other)const{
    if (name != other.get_name() || bday != other.get_bday())
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Friend::operator != (const Friend& other)const{
    if (name == other.get_name())
    {
        return false;
    }
    else if (bday == other.get_bday())
    {
        return false;
    } 
    else
    {
        return true;
    }
}

void Friend::output(std::ostream& outs)const{
    outs << name << endl;
    outs << bday << endl;
}

void Friend::input(std::istream& ins){
    string tmp;                 //string for reading in the name with getline       
    if (&ins == &cin)           //taking input from keyboard
    {
        cout << "Please enter the name of your friend : ";
        while (ins.peek() == '\n' || ins.peek() == '\r'){
            ins.ignore();           //skip over unneeded chars that are left after normal ins >> input
        }
        getline(ins, tmp);
        name = tmp;

        cout << "Now enter your friend's birthday : ";
        ins >> bday;
    }
    else                        //taking input from file
    {
        while (ins.peek() == '\n' || ins.peek() == '\r'){
            ins.ignore();           //skip over unneeded chars that are left after normal ins >> input
        }
        getline(ins, tmp);
        name = tmp;
        ins >> bday;
    }
}

ostream& operator << (std::ostream& outs,const Friend& f){
    f.output(outs);
    return outs;
}

istream& operator >> (std::istream& ins,Friend& f){
    f.input(ins);
    return ins;
}