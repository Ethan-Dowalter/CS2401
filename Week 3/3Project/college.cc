/**
 *        @file: college.cc
 *      @author: Ethan Dowalter
 *        @date: July 20, 2020
 *       @brief: Implementation for the College class
 */

#include <iostream>
#include <string>
#include "node.h"
#include "course.h"
#include "college.h"
using namespace std;

/// Default constructor
College::College(){
    name = "";
    head = NULL;
}


/// Big 3
College::~College(){
    node *cursor = head;
    while (head != NULL && cursor != NULL)      //cursor and head take turns deleting nodes, one "leap-frogging" over the other in a loop
    {
        cursor = head->link();
        delete head;
        if (cursor != NULL)
        {
            head = cursor->link();
            delete cursor;
        }
    }
}

College::College(const College &other){
    name = other.name;
    head = NULL;
    node *cursor = other.head;          //points at list which is being copied
    while (cursor != NULL)
    {
        add(cursor->data());            //copies the node into the list
        cursor = cursor->link();
    }
}

void College::operator = (const College &other){
    if (&other == this)
    {
        return;
    }

    delete head;
    
    name = other.name;
    head = NULL;
    node *cursor = other.head;          //points at list which is being copied
    while (cursor != NULL)
    {
        add(cursor->data());            //copies the node into the list
        cursor = cursor->link();
    }
}


void College::load(std::istream &ins){
    string username;
    getline(ins, username);
    name = username;

    course tmp;                     //used to read in courses from the file
    node *cursor;                   //makes sure new courses are put in order
    while (ins >> tmp)
    {
        if (head == NULL)           //create a new node at head for first course
        {
            head = new node;
            head->set_data(tmp);
            head->set_link(NULL);
            cursor = head;
        }
        else                        //create a new node at end of list for next course
        {
            cursor->set_link(new node);
            cursor = cursor->link();
            cursor->set_data(tmp);
            cursor->set_link(NULL);
        }
    }
}

void College::save(std::ostream &outs){
    outs << name << endl;
    node *cursor;               //goes through list one by one to rewrite file
    for (cursor = head; cursor != NULL; cursor = cursor->link())
    {
        outs << cursor->data();
    }
}

void College::set_name(std::string newName){
    name = newName;
}

void College::add(course newCourse){
    node *cursor1, *cursor2;
    if (head == NULL)           //create new node if list is empty
    {
        head = new node;
        head->set_data(newCourse);
        head->set_link(NULL);
    }
    else                        //put course in correct spot in list
    {
        for (cursor1 = head; cursor1 != NULL && cursor1->data() <= newCourse; cursor1 = cursor1->link());               //cursor1 goes until its right after the spot where badCourse needs to be
        for (cursor2 = head; cursor2->link() != cursor1 && cursor2->link() != NULL; cursor2 = cursor2->link());         //cursor2 goes until right before cursor1, which is correct spot to keep order sorted
        
        if (cursor1 == head)                //special case for inserting before head
        {
            cursor2 = new node;
            cursor2->set_data(newCourse);
            cursor2->set_link(cursor1);
            head = cursor2;
        }
        else
        {
            cursor2->set_link(new node);
            cursor2 = cursor2->link();
            cursor2->set_data(newCourse);
            cursor2->set_link(cursor1);
        }
        
        
    }
}

void College::display(std::ostream &outs){
    for (node *cursor = head; cursor != NULL; cursor = cursor->link())
    {
        outs << cursor->data();
    }
}

void College::remove(std::string badCourse){
    if (head == NULL)
    {
        cout << "There are no courses to remove." << endl;
        return;
    }
    
    size_t size = badCourse.size();
    for (size_t i = 0; i < size; i++)       //makes sure course number is uppercase
    {
        badCourse[i] = toupper(badCourse[i]);
    } 

    node *cursor1 = head->link();       //will point at the badCourse
    node *cursor2 = head;               //points to the course directly before badCourse
    while (cursor1 != NULL)
    {
        if (cursor1->data().get_course_number() == badCourse)
        {
            cursor2->set_link(cursor1->link());     //makes cursor2's course skip over the badCourse, removing it from the list
            delete cursor1;                         //delete it to save memory
            return;
        }
        cursor1 = cursor1->link();                  //increment both cursors
        cursor2 = cursor2->link();
    }

    cout << "Course is not in list." << endl;
}

double College::hours(){
    node *cursor = head;            //goes through list one by one
    double totalHours = 0;          //tracks total credit hours
    while (cursor != NULL)
    {
        totalHours += cursor->data().get_hours();
        cursor = cursor->link();
    }
    return totalHours;
}

double College::gpa(){
    node *cursor = head;            //goes through list one by one        
    double totalPoints = 0;         //tracks total gpa points (grade in course * credit hours of course)
    double totalHours = 0;          //tracks total credit hours
    double gpa;                     //final calculated gpa
    while (cursor != NULL)
    {
        totalPoints += cursor->data().get_number_grade() * cursor->data().get_hours();
        totalHours += cursor->data().get_hours();
        cursor = cursor->link();
    }
    gpa = totalPoints / totalHours;
    return gpa;
}
