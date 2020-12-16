/**
 *        @file: dlist.h
 *      @author: Ethan Dowalter
 *        @date: July 27, 2020
 *       @brief: Defenition for a template list class
 */

#include <iostream>
#include "dnode.h"
#include "iterator.h"
#ifndef DLIST_H
#define DLIST_H

template <class T>
class Dlist{
    public:
        /// Default constructor
        Dlist();

        /// Big 3
        ~Dlist();
        Dlist(const Dlist &other);
        void operator = (const Dlist &other);

        /// Iterator functions
        typedef Node_iterator<T> iterator;
        iterator begin(){
            return iterator(head);}
        iterator end(){
            return iterator(NULL);}
        iterator r_begin(){
            return iterator(tail);}
        iterator r_end(){
            return iterator(NULL);}
        void insert_before(iterator spot, T &item);
        void insert_after(iterator spot, T &item);
        void remove(iterator spot);

        /// Other insert and remove functions
        void front_insert(T& item);
        void rear_insert(T& item);
        void front_remove();
        void rear_remove();

        /// Testing functions
        void show() const;
        void reverse_show() const;

        /// Misc
        int size()const{
            return nodecount;}
    private:
        Dnode<T> *head;
        Dnode<T> *tail;
        int nodecount;
};

#include "dlist.template"
#endif