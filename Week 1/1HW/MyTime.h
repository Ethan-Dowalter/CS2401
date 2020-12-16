/**
 *        @file: MyTime.h
 *      @author: Ethan Dowalter
 *        @date: July 3, 2020
 *       @brief: Class definition for the MyTime class
 */

#include <iostream>
using namespace std;
    
class MyTime
{   
  	public:
	  	///Default constructor
  		MyTime(int h = 0, int m = 0);   

		///Getters
    	int get_hours() const {return hours;}

    	int get_minutes() const {return minutes;}

		///Setter
    	void Reset(int h, int m);    
   
		///Helpers
    	MyTime operator + (const MyTime& t1) const;			//adds two times
 
    	MyTime operator - (const MyTime& t1) const;			//subtracts two times (answer is always positive)
 
    	MyTime operator * (int num) const;					//multiplies time by a constant

    	MyTime operator / (int num) const;					//divides time by a constant

    	bool operator == (const MyTime& t1) const;			//checks if two times are equal

    	bool operator < (const MyTime& t1) const;			//checks if first time is less than second

    	bool operator <= (const MyTime& t1) const;			//checks if first time is less than or equal to second

    	bool operator > (const MyTime& t1) const;			//checks if first time is greater than second

    	bool operator >= (const MyTime& t1) const;			//checks if first time is greater than or equal to second

    	void input(istream& ins);            				//reads in two numbers to put into hours and minutes

    	void output(ostream& outs) const;					//outputs the object onto screen

   
  	private:
      	void simplify();	// converts minutes > 59 to hours and applies absolute value

      	int hours;      	// hours can be > 24

      	int minutes;  		// 0 <= minutes <= 59
};

istream& operator >> (istream& fin, MyTime& t);				//allows use of MyTime objects as inputs
   
ostream& operator << (ostream& fout, const MyTime& t); 		//allows use of MyTime objects as outputs
