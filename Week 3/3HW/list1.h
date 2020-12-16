/**
 *        @file: list1.h
 *      @author: Ethan Dowalter
 *        @date: July 15, 2020
 *       @brief: Learning about linked lists
 */

#include <iostream>
#include <string>

struct Node{
    std::string data;
    Node *link;
};

class Lilist{
    public:
        Lilist() {head = NULL;}
        void add(std::string item);
        void show();
        Node* search(std::string item);
        void move_front_to_back();
    private:
        Node *head;
};

void Lilist::add(std::string item){
    Node *tmp;
    if (head == NULL)
    {
        head = new Node;
        head -> data = item;
        head -> link = NULL;
    }
    else
    {
        for (tmp = head; tmp -> link != NULL; tmp = tmp -> link);
        tmp -> link = new Node;
        tmp = tmp -> link;
        tmp -> data = item;
        tmp -> link = NULL;
    }
}

void Lilist::show(){
    for (Node *tmp = head; tmp != NULL; tmp = tmp -> link)
    {
        std::cout << tmp -> data << "   ";
    }
}

Node* Lilist::search(std::string item){
    Node *tmp = head;           //temp pointer to search through list
    while (tmp != NULL)
    {
        if (tmp -> data == item)        //if it's a match, return that thing in the list
        {
            return tmp;
        }
        tmp = tmp -> link;      //moves tmp to next in list
    }
    return tmp;
}

void Lilist::move_front_to_back(){
    Node *first = head, *last = head;       //temp pointers to store the first and last things in list
    head = head -> link;                    //move head to 2nd spot
    while (last -> link != NULL)            //move last to last thing in list, just before NULL
    {
        last = last -> link;
    }
    last -> link = first;                   //make the last thing point back to the first
    first -> link = NULL;                   //make the first thing point to NULL, making it the new end
}