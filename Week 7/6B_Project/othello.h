/**
 *        @file: othello.h
 *      @author: Ethan Dowalter
 *        @date: August 9, 2020
 *       @brief: Definition for the Othello class, used to play Othello/Reversi
 */

#ifndef OTHELLO_H
#define OTHELLO_H
#include <iostream>
#include "game.h"
#include "piece.h"
using namespace std;

class Othello:public main_savitch_14::game{
    public:
        /// Default constructor
        Othello();

        /// Updates the board after a move
        void make_move(const std::string& move);

        /// Wipes the board clean and sets the default pieces
        void restart();

        //main_savitch_14::game* clone() const;

        /// Computes all possible moves for the current turn
        void compute_moves(std::queue<std::string>& moves) const;

        /// Prints the board
        void display_status() const;

        /// Counts up total black tiles minus total white tiles
        int evaluate() const;

        /// Checks to see if game is over, and passes a player if no move is available
        bool is_game_over();

        /// Checks to see if a given move is allowed
        bool is_legal(const std::string& move) const;

    private:
        Piece board [8][8];         //8x8 tile board used to play othello/reversi
};

#endif