/**
 *        @file: node_iterator.h
 *      @author: Ethan Dowalter
 *        @date: July 27, 2020
 *       @brief: Defenition for a node_iterator class used for a template list
 */

#include <iostream>
#include "dnode.h"
#ifndef ITERATOR_H
#define ITERATOR_H

template <class T>
class Dlist;            //forward declaration

template <class T>
class Node_iterator{
    public:
        friend class Dlist<T>;

        /// Default constructor
        Node_iterator(Dnode<T> *item = NULL){
            current = item;}

        /// Iterator operators
        bool operator != (const Node_iterator &other){
            return current != other.current;}
        bool operator == (const Node_iterator &other){
            return current == other.current;}
        T operator * (){
            return current->data();}
        Node_iterator operator ++ (){       //pre-increment
            current = current->next();
            return *this;}
        Node_iterator operator ++ (int){    //post-increment
            Node_iterator original(current);
            current = current->next();
            return original;}
        Node_iterator operator -- (){       //pre-decrement
            current = current->previous();
            return *this;}
        Node_iterator operator -- (int){    //post-decrement
            Node_iterator original(current);
            current = current->previous();
            return original;}
    private:
        Dnode<T> *current;
};

#endif