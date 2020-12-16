/**
 *        @file: part2.cc
 *      @author: Ethan Dowalter
 *        @date: July 9, 2020
 *       @brief: Learning how to use dynamic variables
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int * ptr;
    ptr = new int;
    cout << &ptr << endl;
    *ptr = 2401;
    for (int i = 0; i < 10; i++)
    {
        ++(ptr);
        cout << *ptr << " is stored at " << ptr << endl;
    }
    
    return 0;
}