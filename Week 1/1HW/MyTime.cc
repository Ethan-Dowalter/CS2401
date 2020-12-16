/**
 *        @file: MyTime.cc
 *      @author: Ethan Dowalter
 *        @date: July 3, 2020
 *       @brief: The implementation file for the MyTime class
 */

#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/// Default constructor
MyTime::MyTime(int h, int m){
	hours = h;
	minutes = m;
}



/// Setter
void MyTime::Reset(int h, int m){
	hours = h;
	minutes = m;
}



/// Helper functions
void MyTime::simplify(){
    hours += minutes/60;
	minutes = minutes%60;
}

MyTime MyTime::operator + (const MyTime& t1) const{
	MyTime tmp;
    tmp.hours = t1.hours + hours;
	tmp.minutes = t1.minutes + minutes;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator - (const MyTime& t1) const{
	MyTime tmp;
	tmp.minutes = abs((hours*60+minutes) - (t1.hours*60+t1.minutes));
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator * (int num) const{
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes *= num;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator / (int num) const{
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes /= num;
	tmp.simplify();
	return tmp;
}

bool MyTime::operator == (const MyTime& t1) const{
	return t1.hours == hours && t1.minutes == minutes;
}

bool MyTime::operator < (const MyTime& t1) const{
	return (hours*60 + minutes) < (t1.hours*60 + t1.minutes);
}

bool MyTime::operator <= (const MyTime& t1) const{
	return (hours*60 + minutes) <= (t1.hours*60 + t1.minutes);
}

bool MyTime::operator > (const MyTime& t1) const{
	return (hours*60 + minutes) > (t1.hours*60 + t1.minutes);
}

bool MyTime::operator >= (const MyTime& t1) const{
	return (hours*60 + minutes) >= (t1.hours*60 + t1.minutes);
}

void MyTime::input(istream&ins){
	char junk;
	ins>>hours;
  	ins.get(junk);
	ins>>minutes;
	simplify();
}

void MyTime::output(ostream& outs) const{
	outs << hours << ':' << setw(2) << setfill('0') << minutes;
}

istream& operator >> (istream& ins, MyTime& t1){
	t1.input(ins);
	return ins;
}

ostream& operator << (ostream& outs, const MyTime& t1){
    t1.output(outs);
	return outs;
}

