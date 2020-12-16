/**
 *        @file: othello.cc
 *      @author: Ethan Dowalter
 *        @date: August 9, 2020
 *       @brief: Implementation for the Othello class, used to play Othello
 */

#include <iostream>
#include <iomanip>
#include "game.h"
#include "othello.h"
#include "colors.h"
using namespace std;

Othello::Othello(){
    restart();
}

void Othello::make_move(const std::string& move){
    /// Get indices for where the move is
    size_t row = move[0] - 'A';
    size_t col = move[1] - '1';

    /// Already know move is valid
    if (next_mover() == HUMAN)
    {
        board[row][col].setBlack();
    }
    else
    {
        board[row][col].setWhite();
    }
    
    /// Look down
    if (row < 6)        //no need to look down if move is in row G or H
    {
        if (board[row + 1][col] != board[row][col])
        {
            for (size_t i = row + 1; i < 8; i++)
            {
                if (board[i + 1][col] == board[row][col])
                {
                    for (size_t j = row + 1; j <= i; j++)
                    {
                        board[j][col].flip();
                    }
                    break;
                }
                else if (board[i + 1][col].isEmpty())
                {
                    break;
                }
            }
        }
    }

    /// Look down-right
    if (row < 6 && col < 6)        //no need to look down-right if move is in row G or H or column 7 or 8
    {
        if (board[row + 1][col + 1] != board[row][col])
        {
            for (size_t i = row + 1, j = col + 1; i < 8 && j < 8; i++, j++)
            {
                if (board[i + 1][j + 1] == board[row][col])
                {
                    for (size_t x = row + 1, y = col + 1; x <= i && y <= j; x++, y++)
                    {
                        board[x][y].flip();
                    }
                    break;
                }
                else if (board[i + 1][j + 1].isEmpty())
                {
                    break;
                }
            }
        }
    }
    
    /// Look right
    if (col < 6)        //no need to look right if move is in column 7 or 8
    {
        if (board[row][col + 1] != board[row][col])
        {
            for (size_t i = col + 1; i < 8; i++)
            {
                if (board[row][i + 1] == board[row][col])
                {
                    for (size_t j = col + 1; j <= i; j++)
                    {
                        board[row][j].flip();
                    }
                    break;
                }
                else if (board[row][i + 1].isEmpty())
                {
                    break;
                }
            }
        }
    }

    /// Look up-right
    if (row > 1 && col < 6)        //no need to look up-right if move is in row A or B or column 7 or 8
    {
        if (board[row - 1][col + 1] != board[row][col])
        {
            for (size_t i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++)
            {
                if (board[i - 1][j + 1] == board[row][col])
                {
                    for (size_t x = row - 1, y = col + 1; x >= i && y <= j; x--, y++)
                    {
                        board[x][y].flip();
                    }
                    break;
                }
                else if (board[i - 1][j + 1].isEmpty())
                {
                    break;
                }
            }
        }
    }

    /// Look up
    if (row > 1)        //no need to look up if move is in row A or B
    {
        if (board[row - 1][col] != board[row][col])
        {
            for (size_t i = row - 1; i >= 0; i--)
            {
                if (board[i - 1][col] == board[row][col])
                {
                    for (size_t j = row - 1; j >= i; j--)
                    {
                        board[j][col].flip();
                    }
                    break;
                }
                else if (board[i - 1][col].isEmpty())
                {
                    break;
                }
            }
        }
    }

    /// Look up-left
    if (row > 1 && col > 1)        //no need to look up-left if move is in row A or B or column 1 or 2
    {
        if (board[row - 1][col - 1] != board[row][col])
        {
            for (size_t i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            {
                if (board[i - 1][j - 1] == board[row][col])
                {
                    for (size_t x = row - 1, y = col - 1; x >= i && y >= j; x--, y--)
                    {
                        board[x][y].flip();
                    }
                    break;
                }
                else if (board[i - 1][j - 1].isEmpty())
                {
                    break;
                }
            }
        }
    }

    /// Look left
    if (col > 1)        //no need to look left if move is in column 1 or 2
    {
        if (board[row][col - 1] != board[row][col])
        {
            for (size_t i = col - 1; i >= 0; i--)
            {
                if (board[row][i - 1] == board[row][col])
                {
                    for (size_t j = col - 1; j >= i; j--)
                    {
                        board[row][j].flip();
                    }
                    break;
                }
                else if (board[row][i - 1].isEmpty())
                {
                    break;
                }
            }
        }
    }

    /// Look down-left
    if (row < 6 && col > 1)        //no need to look down-left if move is in row G or H or column 1 or 2
    {
        if (board[row + 1][col - 1] != board[row][col])
        {
            for (size_t i = row + 1, j = col - 1; i < 8 && j >= 0; i++, j--)
            {
                if (board[i + 1][j - 1] == board[row][col])
                {
                    for (size_t x = row + 1, y = col - 1; x <= i && y >= j; x++, y--)
                    {
                        board[x][y].flip();
                    }
                    break;
                }
                else if (board[i + 1][j - 1].isEmpty())
                {
                    break;
                }
            }
        }
    }
    
    //call parent function to increment move counter
    game::make_move(move);
} 

void Othello::restart( ){
    for (size_t i = 0; i < 8; i++)          //clean board
    {
        for (size_t j = 0; j < 8; j++)
        {
            board[i][j].setEmpty();
        }
    }
    
    board[3][3].setWhite();             //set start positions
    board[3][4].setBlack();
    board[4][3].setBlack();
    board[4][4].setWhite();

    // board[0][0].setBlack();          //for testing purposes
    // board[0][1].setBlack();
    // board[0][2].setBlack();
    // board[0][3].setBlack();
    // board[0][4].setBlack();
    // board[0][5].setBlack();
    // board[0][6].setBlack();
    // board[0][7].setBlack();

    // board[1][0].setBlack();
    // board[1][1].setWhite();
    // board[1][2].setWhite();
    // board[1][3].setWhite();
    // board[1][4].setWhite();
    // board[1][5].setWhite();
    // board[1][6].setWhite();
    // board[1][7].setBlack();

    // board[2][0].setBlack();
    // board[2][1].setWhite();
    // board[2][2].setWhite();
    // board[2][3].setWhite();
    // board[2][4].setWhite();
    // board[2][5].setWhite();
    // board[2][6].setWhite();
    // board[2][7].setBlack();

    // board[3][0].setBlack();
    // board[3][1].setWhite();
    // board[3][2].setWhite();
    // board[3][3].setWhite();
    // board[3][4].setWhite();
    // board[3][5].setWhite();
    // board[3][6].setWhite();
    // board[3][7].setBlack();

    // board[4][0].setBlack();
    // board[4][1].setWhite();
    // board[4][2].setWhite();
    // board[4][3].setWhite();
    // board[4][4].setWhite();
    // board[4][5].setWhite();
    // board[4][6].setWhite();
    // board[4][7].setBlack();

    // board[5][0].setBlack();
    // board[5][1].setWhite();
    // board[5][2].setWhite();
    // board[5][3].setWhite();
    // board[5][4].setWhite();
    // board[5][5].setWhite();
    // board[5][6].setWhite();
    // board[5][7].setBlack();

    // board[6][0].setBlack();
    // board[6][1].setWhite();
    // board[6][2].setWhite();
    // board[6][3].setWhite();
    // board[6][4].setWhite();
    // board[6][5].setWhite();
    // board[6][6].setWhite();
    // board[6][7].setBlack();

    // board[7][0].setBlack();
    // board[7][1].setBlack();
    // board[7][2].setBlack();
    // board[7][3].setBlack();
    // board[7][4].setBlack();
    // board[7][5].setBlack();
    // board[7][6].setBlack();
    // board[7][7].setBlack();

    //call parent function to set move count to 0
    game::restart();
}

// main_savitch_14::game* Othello::clone( ) const{

// }

// void Othello::compute_moves(std::queue<std::string>& moves) const{

// }

void Othello::display_status( ) const{
    cout << setw(7) << right << '1';            //Column labels
    for (size_t i = 2; i <= 8; i++)
    {
        cout << setw(8) << right << i;
    }
    cout << endl;
    
    /// Generate an 8x8 grid of square tiles that change color according to what piece (or lack thereof) is on them
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t x = 0; x < 3; x++)          //each tile is 3 characters tall and 7 characters wide so it looks like a square
        {
            if (x == 1)                         //Row labels
            {
                char row = i + 65;
                cout << ' ' << row << ' ';
            }
            else
            {
                cout << "   ";
            }
            
            for (size_t j = 0; j < 8; j++)      //board tiles
            {
                for (size_t y = 0; y < 7; y++)
                {
                    board[i][j].printSqaure();
                }
                cout << ' ';                    //space between each tile
            }
            cout << endl;
        }
        cout << endl;               //space between each row
    }
}

// int Othello::evaluate( ) const{

// }

// bool Othello::is_game_over( ) const{

// }

bool Othello::is_legal(const std::string& move) const{
    /// Only need to consider first four legal moves
    if (move == "C4" || move == "D3" || move == "E6" || move == "F5")
    {
        return true;
    }
    return false;
}    