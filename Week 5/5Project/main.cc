/**
 *        @file: main.cc
 *      @author: Ethan Dowalter
 *        @date: August 1, 2020
 *       @brief: 
 */

#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include "parent.h"
#include "child.h"
using namespace std;

/// Prints out the menu to user and returns the selected option
int menuChoice();

/// Converts code from file to a number to be used in a switch statement
int convertCode(string code);

int main(){
    AnimalHome *tmp;                //used for inputting AnimalHomes
    string fileCode;                //indicates what kind of home it is
    int numCode;                    //each fileCode corresponds to a number
    int choice;                     //menu choice from the user
    list<AnimalHome*> homes;        //master list of all homes
    list<AnimalHome*>::iterator it; //external iterator for masater list
    ifstream fin;                   //file input
    ofstream fout;                  //file output

    /// Look for file to load from
    fin.open("datafile.txt");
    if (!fin.fail())             //check for failure
    {
        fin >> fileCode;                    //priming read
        numCode = convertCode(fileCode);    //converts string to a number
        while (!fin.eof())
        {
            switch(numCode){
                case 1:
                    tmp = new Dune;
                    tmp->input(fin);
                    homes.push_back(tmp);
                    break;
                case 2:
                    tmp = new MeerkatWarren;
                    tmp->input(fin);
                    homes.push_back(tmp);
                    break;
                case 3:
                    tmp = new TreeHollow;
                    tmp->input(fin);
                    homes.push_back(tmp);
                    break;
                case 4:
                    tmp = new Pasture;
                    tmp->input(fin);
                    homes.push_back(tmp);
                    break;
                case 5:
                    tmp = new Mound;
                    tmp->input(fin);
                    homes.push_back(tmp);
                    break;
                case 6:
                    tmp = new FreshAquarium;
                    tmp->input(fin);
                    homes.push_back(tmp);
                    break;
                default:
                    break;
            }
            fin >> fileCode;
            numCode = convertCode(fileCode);
        }
        fin.close();
    }
    else
    {
        cout << "Error reading from datafile." << endl;
    }
    


    /// Print menu for what kind of animal home user wants w/ option to print list
    do
    {
        /// User input
        choice = menuChoice();
        switch(choice){
            /// Put into container
            case 0:
                break;
            case 1:
                tmp = new Dune;
                tmp->input(cin);
                homes.push_back(tmp);
                break;
            case 2:
                tmp = new MeerkatWarren;
                tmp->input(cin);
                homes.push_back(tmp);
                break;
            case 3:
                tmp = new TreeHollow;
                tmp->input(cin);
                homes.push_back(tmp);
                break;
            case 4:
                tmp = new Pasture;
                tmp->input(cin);
                homes.push_back(tmp);
                break;
            case 5:
                tmp = new Mound;
                tmp->input(cin);
                homes.push_back(tmp);
                break;
            case 6:
                tmp = new FreshAquarium;
                tmp->input(cin);
                homes.push_back(tmp);
                break;
            case 7:
                for (it = homes.begin(); it != homes.end(); ++it)
                {
                    (*it)->output(cout);
                }
                break;
            default:
                cout << "Please enter a valid choice." << endl << endl;
                break;
        }
    } while (choice != 0);
    
    /// Save user changes to file
    fout.open("datafile.txt");
    if (!fout.fail())
    {
        for (it = homes.begin(); it != homes.end(); ++it)
        {
            (*it)->output(fout);
        }
    }
    else
    {
        cout << "Error saving to datafile." << endl << endl;
    }
    
    return 0;
}   



/// Function definitions
int menuChoice(){
    cout << "Choose from the following options:" << endl;
    cout << "1) Order a sand dune for golden mole(s)" << endl;
    cout << "2) Order a warren for meerkat(s)" << endl;
    cout << "3) Order a tree hollow for barn owl(s)" << endl;
    cout << "4) Order a pasture for livestock" << endl;
    cout << "5) Order a mound for termite colony" << endl;
    cout << "6) Order a freshwater aquarium" << endl;
    cout << "7) Display the list of homes so far" << endl;
    cout << "0) Save and quit" << endl;
    int choice;
    cin >> choice;
    return choice;
}

int convertCode(string code){
    if      (code == "Dune")          {return 1;}
    else if (code == "MeerkatWarren") {return 2;}
    else if (code == "TreeHollow")    {return 3;}
    else if (code == "Pasture")       {return 4;}
    else if (code == "Mound")         {return 5;}
    else if (code == "FreshAquarium") {return 6;}
    else                              {return 0;}
}