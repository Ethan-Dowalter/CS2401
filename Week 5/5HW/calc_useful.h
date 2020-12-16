/**
 *        @file: calc_useful.h
 *      @author: Ethan Dowalter
 *        @date: July 29, 2020
 *       @brief: Defenition for a node_iterator class used for a template list
 */

/********************************************************
     These are a couple of functions that are useful in writing
     calculators. The evaluate is given in two forms, allowing for
     either floating point or integer calculators.
       John Dolan			Spring 2014
**********************************************************/

double evaluate(double num1, double num2, char op);
int evaluate(int num1, int num2, char op);
bool isop(char op);
