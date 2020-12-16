/**
 *        @file: part3.cc
 *      @author: Ethan Dowalter
 *        @date: July 9, 2020
 *       @brief: Learning how to use dynamic arrays
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
using namespace std;


int main(){
    int * ptr;
    size_t capacity = 5;
    size_t used = 0;
    int * tmpptr;
    ptr = new int[capacity];
    for(size_t i=0; i<25; ++i){
	    ptr[used] = rand(); // you will need #include<cstdlib>
				            // at the top for this to work
	    //cout<< ptr[used] << endl;
	    used++;
        if(used == capacity){
            tmpptr = new int[capacity + 5];
            copy(ptr, ptr + used, tmpptr);
            capacity += 5;
            delete []ptr;
            ptr = tmpptr;
            cout << "Resized. \n";
	    }
    }

    tmpptr[2] = 0;
    for (size_t i = 0; i < used; i++)
    {
        cout << *(ptr + i) << endl;
    }

    return 0;
}

