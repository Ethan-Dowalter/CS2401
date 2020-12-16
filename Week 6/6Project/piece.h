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

        bool operator == (const Piece &other) const;
        bool operator != (const Piece &other) const;

    private:
        bool empty;
        bool black;
        bool white;
};

#endif