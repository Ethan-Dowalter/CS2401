/**
 *        @file: node_iterator.h
 *      @author: Ethan Dowalter
 *        @date: July 27, 2020
 *       @brief: Defenition for a node_iterator class used for a template list
 */

#include <iostream>
#include "dnode.h"
#ifndef NODE_ITERATOR_H
#define NODE_ITERATOR_H

template <class T>
class Node_iterator{
    public:
        Node_iterator(Dnode<T> *item = NULL){
            current = item;}
        bool operator != (const Node_iterator &other){
            return current != other.current;}
        bool operator == (const Node_iterator &other){
            return current == other.current;}
        T operator * (){
            return current->data();}
        Node_iterator operator ++ (){
            current = current->next();
            return *this;}
        Node_iterator operator ++ (int){
            Node_iterator original(current);
            current = current->next();
            return original;}
        Node_iterator operator -- (){
            current = current->previous();
            return *this;}
        Node_iterator operator -- (int){
            Node_iterator original(current);
            current = current->previous();
            return original;}
    private:
        Dnode<T> *current;
};

#endif