/**
 *        @file: llist.cc
 *      @author: Ethan Dowalter
 *        @date: July 25, 2020
 *       @brief: Implementation of a doubly linked list of ints
 */

/************************************************************************
     This is the implementation file for the LList class which is a 
container based on a doubly linked list. The student is required to 
write the rearview function as well as the copy constructor. Note that 
the copy constructor will not be able to use the add function to produce 
a true copy because of the strange behavior of the add function, which 
treats all numbers divisible by five differently than other numbers.
	John Dolan		Ohio University		Spring 2018
************************************************************************/
#include<iostream>
#include "llist.h"
using namespace std;

LList::LList(const LList& other){
    nodecount = 0;
    head = tail = NULL;
    node *cursor = other.head;
    while (cursor != NULL)
    {
        add_item(cursor->data());       //will not copy in the same order b/c the way add_item treats ints divisible by 5
        cursor = cursor->next();
    }
}

void LList::frontview()const{
    node* cursor = head;
    while (cursor != NULL){
        cout << cursor->data() << ' ';
        cursor = cursor->next();
    }
}

// The student is required to write the implementation of this function
void LList::rearview()const{
    node *cursor = tail;
    while (cursor != NULL)
    {
        cout << cursor->data() << ' ';
        cursor = cursor->previous();
    }
}


void LList::add_item(int item){
    if(head == NULL){
        head = tail = new node(item);
        nodecount++;
    }
    else if(item%5 == 0 && nodecount > 3){
        int i = 0;
        node* cursor = head;
        while(i < nodecount/2){
            cursor = cursor->next();
            i++;
        }
        cursor->previous()->set_next(new node(item,cursor->previous(),cursor));
        cursor->set_previous(cursor->previous()->next());
        nodecount++;
    }
    else{
        tail->set_next(new node(item, tail));
        tail = tail->next();
        nodecount++;
    }
}

LList::~LList(){
    node* rmptr;
    while(head != NULL){
        rmptr=head;
        head = head->next();
        delete rmptr;
    }
}