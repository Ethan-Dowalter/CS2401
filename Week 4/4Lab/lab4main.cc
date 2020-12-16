/**
 *        @file: lab4main.cc
 *      @author: Ethan Dowalter
 *        @date: July 25, 2020
 *       @brief: Testing out a doubly linked list
 */

/******************************************************************
    This is the main for the Lab 9 Assignment of CS2401. You will need 
to implement the rearview function which should display the list 
backwards. Also, there are problems in the code which you will need to 
diagnose using gdb.
Finally you will also need to write and test the copy constructor for 
this class.
	John Dolan	School of EECS Ohio University, Athens Ohio
			Spring 2018
********************************************************************/

#include<iostream>
#include<cstdlib>
#include "llist.h"
using namespace std;

int main(){

    int n;
    LList somenums;
    for(int i = 0; i <35; ++i)
    {	
        n = rand()%700 + 1;
        somenums.add_item(n);
    }
// Once you have written the rear-view this should let you
// see the list frontwards and backwards.
    cout << "Somenums forwards:  ";
    somenums.frontview();
    cout << endl << "Somenums backwards: ";
    somenums.rearview();
// This part will be uncommented once you have written the copy constructor

{
    LList numcopy(somenums);    // call to the copy constructor
    cout << endl << "Numcopy forwards:   ";
    numcopy.frontview();        //numcopy will not be in the same order as somenums b/c the way add_item handles ints divisible by 5
    cout << endl << "Numcopy backwards:  ";
    numcopy.rearview();
}   // Line 34 - What happens here?

// Checking the original list
    cout << endl << "Somenums forwards:  ";
    somenums.frontview();
    cout << endl << "Somenums backwards: ";
    somenums.rearview();

    return 0;
}