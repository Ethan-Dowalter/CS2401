/**
 *   @file: ward.cc
 * @author: Ethan Dowalter
 *   @date: July 7, 2020
 *  @brief: Ward class implementation
 */

#include "ward.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

/// Default constructor
Ward::Ward(){
    used = 0;
}


/// Input and output
void Ward::add(Household& h){
    data[used] = h;             //add the house to the end of the list
    used++;                     //add one to the number of houses
}

void Ward::display(ostream& outs){
    for (size_t i = 0; i < used; i++){
        outs << data[i];
    }
}

void Ward::remove(string name){
    for (size_t i = 0; i < used; i++){
        if (data[i].get_head() == name){
            Household tmp;                      //temporary variable for swapping two indices
            tmp = data[i];                      //swap house that is being removed with last house in list
            data[i] = data[used - 1];
            data[used-1] = tmp;
            used--;                             //remove a house from the total, making the removed house invisible
            cout << "Household successfully removed." << endl << endl;
            return;
        }
    }
    cout << "Could not find a household with that name attatched." << endl << endl;
}

Household Ward::find(string name){
    for (size_t i = 0; i < used; i++){
        if (data[i].get_head() == name){
            return data[i];
        }
    }
    cout << "Could not find a household with that name attatched." << endl;
    Household failSearch;               //empty household to return if search fails
    return failSearch;
}

void Ward::display_richest(){
    if (used > 0){                  //don't do anything if empty ward
        int highestIncome = data[0].get_income();           //stores highest income of the ward
        size_t indexOfRichest = 0;                          //index at which the richest house is
        for (size_t i = 1; i < used; i++){
            if (data[i].get_income() > highestIncome){
                highestIncome = data[i].get_income();
                indexOfRichest = i;
            }
        }
        cout << data[indexOfRichest];
    }
}

void Ward::display_avg_income(){
    double totalIncome = 0;               //total income of ward
    for (size_t i = 0; i < used; i++)
    {
        totalIncome += data[i].get_income();
    }
    cout << fixed << setprecision(2);
    cout << "The average income in the ward is $" << totalIncome / used << endl << endl;
}

void Ward::display_avg_people(){
    double totalPeople = 0;                   //total people in ward
    for (size_t i = 0; i < used; i++)
    {
        totalPeople += data[i].get_occupants();
    }
    cout << fixed << setprecision(2);
    cout << "The average number of residents per household is " << totalPeople / used << endl << endl;
}

void Ward::sort_by_income(){
    bool done = false;
    Household tmp;
    while (!done){
        done = true;
        for (size_t i = 0; i < used - 1; i++){
            if (data[i+1].get_income() < data[i].get_income()){
                done = false;
                tmp = data[i+1];
                data[i+1] = data[i];
                data[i] = tmp;
            }
        }       
    }    
}

void Ward::sort_by_name(){
    bool done = false;
    Household tmp;
    while (!done){
        done = true;
        for (size_t i = 0; i < used - 1; i++){
            if (data[i+1].get_head() < data[i].get_head()){         //sorts by first name
                done = false;
                tmp = data[i+1];
                data[i+1] = data[i];
                data[i] = tmp;
            }
        }       
    }    
}

void Ward::load(istream& ins){
    while (ins >> data[used]){
        used++;
    }
}

void Ward::save(ostream& outs){
    for (size_t i = 0; i < used; i++){
        outs << data[i].get_head() << endl;
        outs << data[i].get_address() << endl;
        outs << data[i].get_occupants() << endl;
        outs << data[i].get_income() << endl;
    }
}