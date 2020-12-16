/**
 *        @file: college.h
 *      @author: Ethan Dowalter
 *        @date: July 20, 2020
 *       @brief: Definition for College class, which contains a student and info about all the classes they've taken
 */

#ifndef COLLEGE_H
#define COLLEGE_H
#include <iostream>
#include "node.h"
#include "course.h"

class College{
    public:
        /// Default constructor
        College();

        /// Big 3
        ~College();
        College(const College &other);
        void operator = (const College &other);

        void load(std::istream &ins);
        void save(std::ostream &outs);
        void set_name(std::string newName);
        void add(course courseName);
        void display(std::ostream &outs);
        void remove(std::string courseName);
        double hours();
        double gpa();

    private:
        std::string name;
        node *head;
};

#endif