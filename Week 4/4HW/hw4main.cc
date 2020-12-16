/**
 *        @file: hw4main.cc
 *      @author: Ethan Dowalter
 *        @date: July 23, 2020
 *       @brief: Testing out a simple template class container
 */

/******************************************************************
     Homework 4 - main.cc
     This is the driver for your lab. It calls each of the functions.
     Notice here that the one class we wrote works for either integers
     or strings.
	John Dolan		Ohio University
	Summer 2019
********************************************************************/

#include<iostream>
#include<cstdlib>
#include "tarray.h"
using namespace std;

int main(){
    Tarray <int> nums;
    Tarray<string> words;

    nums.add(rand());
    nums.add(rand());
    nums.add(rand());
    nums.add(rand());

   for(nums.start(); nums.is_item(); nums.advance())
	cout<<nums.current()<<endl;

    words.add("CS");
    words.add("is");
    words.add("the");
    words.add("bestest");
    words.add("major");
    words.add("at");
    words.add("Ohio");
    words.add("University");

   words.start();
   while(words.is_item() && words.current() != "major")
   	words.advance();

    words.remove_current();
   for(words.start(); words.is_item(); words.advance())
	cout<<words.current()<<' ';

return 0;
}