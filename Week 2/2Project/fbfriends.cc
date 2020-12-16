/**
 *        @file: fbfriends.cc
 *      @author: Ethan Dowalter
 *        @date: July 13, 2020
 *       @brief: Class implementation for fbfriends class
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "fbfriends.h"
using namespace std;

FBFriends::FBFriends(){
    data = new Friend[5];
    used = 0;
    capacity = 5;
    current_index = 0;
}

//The functions known as the Big 3
FBFriends::~FBFriends(){
    delete [] data;
}

FBFriends::FBFriends(const FBFriends& other){
    capacity = other.capacity;
	used = other.used;
	data = new Friend[capacity];
	copy(other.data, other.data + used, data);
}

void FBFriends::operator = (const FBFriends& other){
    if (&other == this)					//checks for self-assignment
	{
		return;
	}
	
	delete [] data;						//delete old array

	capacity = other.capacity;			//copy new array
	used = other.used;
	data = new Friend[capacity];
	copy(other.data, other.data + used, data);
}

// Functions for the internal iterator
void FBFriends::start(){
    current_index = 0;
}

void FBFriends::advance(){
    current_index += 1;
}

bool FBFriends::is_item(){
    return current_index < used;            //friends are only stored at indeces which are less than used
}

Friend FBFriends::current(){
    return data[current_index];
}

void FBFriends::remove_current(){
    if (used == capacity)           //increase size of array in case it is full, b/c the current friend is thrown on the end
    {
        resize();
    }
    
    data[used] = data [current_index];              //throw the current friend past the end of the list, effectively getting rid of them
    for (int i = current_index; i < used; i++)      //shift the rest of the friends down the list by one to fill the gap
    {
        data[i] = data[i + 1];
    }
    used--;                         //decrease size of list by one
}

void FBFriends::insert(const Friend& f){
    if (is_friend(f))               //checks to see if f is already a friend
    {
        cout << "Already in list.\n";
        return;
    }
    
    used++;
    if (used > capacity)            //resize if necessary
    {
        resize();
    }
    
    for (int i = used - 1; i > current_index; i--)          //shift all friends past current index (inclusive) to the right one to make room for the insert
    {
        data[i] = data[i - 1];
    }

    data[current_index] = f;            //insert goes in between what was the current index and the one preceeding it
}

void FBFriends::attach(const Friend& f){
    used++;
    if (used > capacity)            //resize if necessary
    {
        resize();
    }
    
    for (int i = used - 1; i > current_index + 1; i--)      //shift all friends past current index (exclusive) to the right one to make room for the insert
    {
        data[i] = data[i - 1];
    }

    data[current_index + 1] = f;        //insert goes in between current index and what was right after it
}

void FBFriends::show_all(std::ostream& outs)const{
    for (int i = 0; i < used; i++)
    {
        outs << data[i] << endl;
    }
}

void FBFriends::bday_sort(){
    bool done = false;
    Friend tmp;
    while (!done)
    {
        done = true;
        for (int i = 0; i < used - 1; i++)
        {
            if (data[i].get_bday() > data[i + 1].get_bday())
            {
                done = false;
                tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
            }
        }
    }
}

Friend FBFriends::find_friend(const std::string& name)const{
    for (int i = 0; i < used; i++)
    {
        if (data[i].get_name() == name)
        {
            return data[i];
        }
    }
    return Friend();
}

bool FBFriends::is_friend(const Friend& f) const{
    for (int i = 0; i < used; i++)
    {
        if (data[i] == f)
        {
            return true;
        }
    }
    return false;
}

void FBFriends::load(std::istream& ins){
    while (ins >> data[used])
    {
        used++;
        if (used == capacity)
        {
            resize();
        }
    }
}

void FBFriends::save(std::ostream& outs){
    for (int i = 0; i < used; i++)
    {
        outs << data[i];
    }
}

//Private functions
void FBFriends::resize(){
    Friend *tmp;
	tmp = new Friend[capacity + 5];
	copy(data, data + used, tmp);
	delete [] data;
	capacity += 5;
	data = tmp;
}