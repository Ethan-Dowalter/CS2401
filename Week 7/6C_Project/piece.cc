/**
 *        @file: piece.cc
 *      @author: Ethan Dowalter
 *        @date: August 9, 2020
 *       @brief: Implementation for the Piece class used in Othello game
 */

#include <iostream>
#include "piece.h"
#include "colors.h"
using namespace std;

void Piece::flip(){    
    if (!empty)
    {
        bool tmp = black;       //swap values of black and white
        black = white;
        white = tmp;
    }
}

void Piece::printSqaure() const{
    char box = 219;             //ascii char for a black box
    if (empty)
    {
        cout << GREEN << B_GREEN << box << RESET;
    } 
    else if (black)
    {
        cout << B_BLACK << BLACK << box << RESET;
    }
    else if (white) 
    {
        cout << B_WHITE << WHITE << box << RESET;
    }
}

bool Piece::operator == (const Piece &other) const{
    return black == other.isBlack() && white == other.isWhite() && empty == other.isEmpty();
}

bool Piece::operator != (const Piece &other) const{
    return black == other.isWhite() && white == other.isBlack() && !empty;
}

void Piece::operator = (const Piece &other){
    empty = other.isEmpty();
    black = other.isBlack();
    white = other.isWhite();
}