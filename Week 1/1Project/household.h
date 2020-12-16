/**
 *   @file: household.h
 * @author: Ethan Dowalter
 *   @date: July 7, 2020
 *  @brief: Household class definition, see professor explanation below
 */

/*************************************************
      This is a class describing a single household. It has private member 
      variables for the name of the head of the household, the street address 
      of the household, the number of people living in the household, and
      the household income. The functions allow access to and modification
      of those attributes either by the application programmer or by the 
      user through the input functions. 
  **********************************************************/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
  
  class Household{
	public:
		Household(string head = "", string add = "", int occ = 0, int inc = 0);
		// Mutators
		void set_head(const string& hd);
		void set_address(const string& add);
		void set_occupants(int num);
		void set_income(int inc);
		// Accessors
		string get_head()const;
		string get_address()const;
		int get_occupants()const;
		int get_income() const;
		// Input and output
		void input(istream& ins);
		void output(ostream& outs)const;
  private:
	  string house_head;
	  string address;
	  int occupants;
	  int income;
  };

  //overloaded i/o operators
  istream& operator >>(istream& ins, Household& h);
  ostream& operator <<(ostream& outs, const Household& h);

#endif
