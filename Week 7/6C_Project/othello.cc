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

Othello::Othello(const Othello &other){
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            board[i][j] = other.board[i][j];
        }        
    }
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
            for (size_t i = row + 1; i < 7; ++i)
            {
                if (board[i + 1][col] == board[row][col])
                {
                    for (size_t j = row + 1; j <= i; ++j)
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
            for (size_t i = row + 1, j = col + 1; i < 7 && j < 7; ++i, ++j)
            {
                if (board[i + 1][j + 1] == board[row][col])
                {
                    for (size_t x = row + 1, y = col + 1; x <= i && y <= j; ++x, ++y)
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
            for (size_t i = col + 1; i < 7; ++i)
            {
                if (board[row][i + 1] == board[row][col])
                {
                    for (size_t j = col + 1; j <= i; ++j)
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
            for (size_t i = row - 1, j = col + 1; i > 0 && j < 7; --i, ++j)
            {
                if (board[i - 1][j + 1] == board[row][col])
                {
                    for (size_t x = row - 1, y = col + 1; x >= i && y <= j; --x, ++y)
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
            for (size_t i = row - 1; i > 0; --i)
            {
                if (board[i - 1][col] == board[row][col])
                {
                    for (size_t j = row - 1; j >= i; --j)
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
            for (size_t i = row - 1, j = col - 1; i > 0 && j > 0; --i, --j)
            {
                if (board[i - 1][j - 1] == board[row][col])
                {
                    for (size_t x = row - 1, y = col - 1; x >= i && y >= j; --x, --y)
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
            for (size_t i = col - 1; i > 0; --i)
            {
                if (board[row][i - 1] == board[row][col])
                {
                    for (size_t j = col - 1; j >= i; --j)
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
            for (size_t i = row + 1, j = col - 1; i < 7 && j > 0; ++i, --j)
            {
                if (board[i + 1][j - 1] == board[row][col])
                {
                    for (size_t x = row + 1, y = col - 1; x <= i && y >= j; ++x, --y)
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
    for (size_t i = 0; i < 8; ++i)          //clean board
    {
        for (size_t j = 0; j < 8; ++j)
        {
            board[i][j].setEmpty();
        }
    }
    
    board[3][3].setWhite();             //set start positions
    board[3][4].setBlack();
    board[4][3].setBlack();
    board[4][4].setWhite();

    //call parent function to set move count to 0
    game::restart();
}

main_savitch_14::game* Othello::clone( ) const{
    return new Othello(*this);    
}

void Othello::compute_moves(queue<string>& moves) const{
    string temp = "";           //temporary string to push in moves to the queue
    for (char i = 'A'; i <= 'H'; ++i)
    {
        for (char j = '1'; j <= '8'; ++j)
        {
            temp = temp + i + j;        //concatenate the chars to form the move
            if (is_legal(temp))         //push move into queue if legal
            {
                // cout << temp << endl;        //print all legal moves
                moves.push(temp);
            }
            temp = "";                  //reset temp string
        }
    }
}

void Othello::display_status() const{
    cout << setw(7) << right << '1';            //Column labels
    for (size_t i = 2; i <= 8; ++i)
    {
        cout << setw(8) << right << i;
    }
    cout << endl;
    
    /// Generate an 8x8 grid of square tiles that change color according to what piece (or lack thereof) is on them
    for (size_t i = 0; i < 8; ++i)
    {
        for (size_t x = 0; x < 3; ++x)          //each tile is 3 characters tall and 7 characters wide so it looks like a square
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
            
            for (size_t j = 0; j < 8; ++j)      //board tiles
            {
                for (size_t y = 0; y < 7; ++y)
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

int Othello::evaluate() const{
    int total = 0;                      //counts number of black pieces on board
    for (size_t i = 0; i < 8; ++i)
    {
        for (size_t j = 0; j < 8; ++j)
        {
            if (board[i][j].isBlack())
            {
                total++;                //increment for black piece
            }
        }
    }
    return total;
}

bool Othello::is_game_over(){
    queue<string> moves;
    compute_moves(moves);
    if (moves.empty())          //checks if current player has any moves, if not game auto passes them
    {
        game::make_move("Pass");

        while (!moves.empty())
        {
            moves.pop();
        }
        
        compute_moves(moves);   //checks if next player has any moves, if not,the game is over
        if (moves.empty())
        {
            return true;
        }
    }
    return false;
}

bool Othello::is_legal(const std::string& move) const{
    /// Get indices for where the move is
    size_t row = move[0] - 'A';
    size_t col = move[1] - '1';

    if (!board[row][col].isEmpty())     //can't go where there is already a tile
    {
        return false;
    }

    Piece temp;                 //temporary piece not on board to set to either black or white based on whose turn it is
    if (next_mover() == HUMAN)
    {
        temp.setBlack();
    }
    else
    {
        temp.setWhite();
    }
    
    /// Look down
    if (row < 6)        //no need to look down if move is in row G or H
    {
        if (board[row + 1][col] != temp)
        {
            for (size_t i = row + 1; i < 7; ++i)
            {
                if (board[i + 1][col] == temp)
                {
                    return true;
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
        if (board[row + 1][col + 1] != temp)
        {
            for (size_t i = row + 1, j = col + 1; i < 7 && j < 7; ++i, ++j)
            {
                if (board[i + 1][j + 1] == temp)
                {
                    return true;
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
        if (board[row][col + 1] != temp)
        {
            for (size_t i = col + 1; i < 7; ++i)
            {
                if (board[row][i + 1] == temp)
                {
                    return true;
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
        if (board[row - 1][col + 1] != temp)
        {
            for (size_t i = row - 1, j = col + 1; i > 0 && j < 7; --i, ++j)
            {
                if (board[i - 1][j + 1] == temp)
                {
                    return true;
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
        if (board[row - 1][col] != temp)
        {
            for (size_t i = row - 1; i > 0; --i)
            {
                if (board[i - 1][col] == temp)
                {
                    return true;
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
        if (board[row - 1][col - 1] != temp)
        {
            for (size_t i = row - 1, j = col - 1; i > 0 && j > 0; --i, --j)
            {
                if (board[i - 1][j - 1] == temp)
                {
                    return true;
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
        if (board[row][col - 1] != temp)
        {
            for (size_t i = col - 1; i > 0; --i)
            {
                if (board[row][i - 1] == temp)
                {
                    return true;
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
        if (board[row + 1][col - 1] != temp)
        {
            for (size_t i = row + 1, j = col - 1; i < 7 && j > 0; ++i, --j)
            {
                if (board[i + 1][j - 1] == temp)
                {
                    return true;
                }
                else if (board[i + 1][j - 1].isEmpty())
                {
                    break;
                }
            }
        }
    }

    return false;       //false if none of the 8 directions are valid
}