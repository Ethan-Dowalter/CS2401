/**
 *        @file: othello.h
 *      @author: Ethan Dowalter
 *        @date: August 9, 2020
 *       @brief: Definition for the Othello class, used to play Othello
 */

#ifndef OTHELLO_H
#define OTHELLO_H
#include <iostream>
#include "game.h"
#include "piece.h"
using namespace std;

class Othello:public main_savitch_14::game{
    public:
        Othello();
        void make_move(const std::string& move);
        void restart();
        //main_savitch_14::game* clone() const;
        //void compute_moves(std::queue<std::string>& moves) const;
        void display_status() const;
        //int evaluate() const;
        //bool is_game_over() const;
        bool is_legal(const std::string& move) const;

        
    private:
        Piece board [8][8];
};

#endif