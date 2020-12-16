/*****************************************************
This is a sample of what the main should like for the second phase of 
the Othello game.The only change is that the game now announces a 
winner.
	John Dolan	Ohio University		Fall 2019
*************************************************************/
#include<iostream>
#include "othello.h"
using namespace std;
using namespace main_savitch_14;


int main(){
   	Othello mygame;
	game::who winner;
	winner=mygame.play();

	int blackTiles = mygame.evaluate();
	int whiteTiles = 64 - blackTiles;
	
	if (winner == game::HUMAN)
		std::cout << "Player 1 Wins " << blackTiles << '-' << whiteTiles << std::endl;
	else if (winner == game::COMPUTER)
		std::cout << "Player 2 Wins " << whiteTiles << '-' << blackTiles << std::endl;
	else
		std::cout << "It's a tie!" << std::endl;
	
return 0;
}