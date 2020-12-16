/**
 *        @file: piece.h
 *      @author: Ethan Dowalter
 *        @date: August 9, 2020
 *       @brief: Definition for the Piece class used in Othello game
 */

#ifndef PIECE_H
#define PIECE_H
#include <iostream>
using namespace std;

class Piece{
    public:
        Piece(){
            empty = true;
            black = white = false;}

        bool isEmpty() const{
            return empty;}
        bool isBlack() const{
            return black;}
        bool isWhite() const{
            return white;}

        void setEmpty(){
            empty = true;
            black = white = false;}
        void setBlack(){
            black = true;
            empty = white = false;}
        void setWhite(){
            white = true;
            empty = black = false;}

        void flip();
        void printSqaure() const;

        /// True equality operator, comparing each variable
        bool operator == (const Piece &other) const;
        /// Used to see of two tiles are opposites, so if black=other.white or white=other.black
        bool operator != (const Piece &other) const;
        /// Assignment operator
        void operator = (const Piece &other);

    private:
        bool empty;
        bool black;
        bool white;
};

#endif