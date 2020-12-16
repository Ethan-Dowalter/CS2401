/**
 *        @file: Dnode.h
 *      @author: Ethan Dowalter
 *        @date: July 27, 2020
 *       @brief: Template node class for a doubly linked list
 */

#include<iostream>
#ifndef DNODE_H
#define DNODE_H

template <class T>
class Dnode{
    public:
        /// Default constructor
        Dnode(const T& item = T(), Dnode* p = NULL, Dnode* n = NULL){
            datafield = item;
            previousptr=p;
            nextptr = n;}
        
        /// Getters
        T& data(){
            return datafield;}
        Dnode *previous(){
            return previousptr;}
        Dnode *next(){
            return nextptr;}
        const T& data() const{
            return datafield;}
        const Dnode *previous() const{
            return previousptr;}
        const Dnode *next() const{
            return nextptr;}

        /// Setters
        void set_data(int d){
            datafield = d;}
        void set_previous(Dnode * p){
            previousptr = p;}
        void set_next(Dnode *n){
            nextptr = n;}
    private:
        T datafield;
        Dnode *nextptr;
        Dnode *previousptr;
};

#endif