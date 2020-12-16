/**
 *        @file: part1.cc
 *      @author: Ethan Dowalter
 *        @date: July 9, 2020
 *       @brief: Learning the difference between static and automatic variables
 */

#include <iostream>
#include <iomanip>
using namespace std;

void pretty();

int main(){
    for (size_t i = 0; i < 6; i++)
    {
        pretty();
    }
    
    return 0;
}

void pretty(){
    static int x = 0;
    x++;
    for (int i = 0; i < x; i++)
    {
        cout << '*';
    }
    cout << endl;    
}