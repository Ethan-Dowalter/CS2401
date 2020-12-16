/**
 *   @file: main.cc
 * @author: Ethan Dowalter
 *   @date: July 1, 2020
 *  @brief: User inputs a filename that should contain a list of numbers, then 3 additional numbers to add to the file. 
 *          Program then adds them to the file and performs a reverse bubble sort from least to greatest.
 */

/******************************************************
   A primitive main solution for lab2 - cs2401
*****************************************************/
#include<iostream>
#include<fstream>
#include "numlist.cc"
using namespace std;

int main(){
     NumList num1;
     int tmp;
     ifstream ifs;
     string filename;
     cout<<"Please enter the name of your number file.\n";
     cin>>filename;
     ifs.open(filename.c_str());
     if(ifs.fail()){
	     cout<<"Input file failed to open.\n";
	     return -1;
     }
     num1.load_from_file(ifs);
     ifs.close();
     cout<<"Please enter three numbers to add to the list.\n";
     cin>>tmp;
     num1.insert(tmp); //1
     cin>>tmp;
     num1.insert(tmp); //2
     cin>>tmp;
     num1.insert(tmp); //3
     num1.b_sort();
     num1.see_all();

     size_t found = filename.find('.');         //stores position of the '.' from the filename
     filename.insert(found,"sorted");           //inserts "sorted" before the '.'

     ofstream ofs(filename.c_str());
     num1.save_to_file(ofs);
     ofs.close();

return 0;
}


