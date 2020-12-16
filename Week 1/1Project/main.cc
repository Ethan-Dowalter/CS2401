/**
 *   @file: main.cc
 * @author: Ethan Dowalter
 *   @date: July 7, 2020
 *  @brief: See professor explanation below
 */

/******************************************************
This is the main for CS2401 Project 1, Fall 2016
You are to write two classes, one called Household which stores 
information about a single household, and another called Ward which 
stores information about 200 of these households.
You can see the necessary memeber functions of the Ward class below.

John Dolan			Fall 2016
*************************************************************/
#include<iostream>
#include<fstream>
#include "household.cc"
#include "ward.cc"
using namespace std;

// The menu function displays the menu and returns the user's choice
int menu();

int main(){
    Household tmp;
    Ward neighborhood;
    int choice;
    string name;
    ofstream outs;
    ifstream ins;
    ins.open("households.txt");

    // if the file is not there we will assume that this is the first 
    // time the program has been run on this machine

    if(!ins.fail()){
	neighborhood.load(ins);
	ins.close();
    }

    do{
	choice = menu();
	switch(choice){
	    case 1: 
		cin>>tmp;
		neighborhood.add(tmp);	
		break;
	    case 2:
		neighborhood.display(cout);
		break;
	    case 3:
		cout<<"Name the head of household for the household you wish to remove:";
		while(cin.peek() == '\n' || cin.peek() == '\r')
			cin.ignore();
		getline(cin,name);
		neighborhood.remove(name);
		break;
	    case 4:
		cout<<"Name the head of household for the household you wish to view:";
                while(cin.peek() == '\n' || cin.peek() == '\r')
                        cin.ignore();
		getline(cin,name);
		tmp = neighborhood.find(name);
		cout<<tmp;
		break;
	    case 5:
		neighborhood.display_richest();
		break;
	    case 6:
		neighborhood.display_avg_income();
		break;
	    case 7:
		neighborhood.display_avg_people();
		break;
	    case 8:
		neighborhood.sort_by_income();
		break;
	    case 9:
		neighborhood.sort_by_name();
		break;
	    case 0:
		cout<<"Good-bye.\n";
		break;
	    default:
		cout<<"Not an option.\n";
		break;
	    } // bottom of the switch
	} while(choice != 0); 
        // bottom of the while
    	outs.open("households.txt");
	if(outs.fail())
	    cout<<"Unable to save data to file.\n";
	else
	    neighborhood.save(outs);
	outs.close();
return 0;
} // bottom of the main

int menu(){
   int choice;
   cout<<"Managing the Ward.\nChoose from the selections below:\n";
   cout<<"1) Add a new household.\n";
   cout<<"2) Display all households in the Ward.\n";
   cout<<"3) Remove a household from the Ward.\n";
   cout<<"4) Find out information about a particular household.\n";
   cout<<"5) Display household with the greatest inome.\n";
   cout<<"6) Display the average income for households in the Ward.\n";
   cout<<"7) Display average number of people living in the household.\n";
   cout<<"8) Sort by income - requires an additional choice 2 to view.\n";
   cout<<"9) Sort by name - requires an addtional choice 2 to view.\n";
   cout<<"0) Quit, saving all changes to the database.\n";
   cin>>choice;
   // clear out the extra newline character
   if(cin.peek() == '\n') cin.ignore();
   return choice;
}

