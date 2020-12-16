/**
 *        @file: calc_useful.cc
 *      @author: Ethan Dowalter
 *        @date: July 27, 2020
 *       @brief: Defenition for a node_iterator class used for a template list
 */

/******************************************************
   The implementations of the calculator-useful functions
	John Dolan			Spring 2014
******************************************************/

bool isop(char op){
        return op =='+' || op == '-' || op == '*' || op == '/';
}

int evaluate(int num1, int num2, char op){
    if(op == '+') return num1 + num2;
    if(op == '-') return num1-num2;
    if(op == '*') return num1*num2;
    if(op == '/') return num1/num2;
    else return 0;
}

double evaluate(double num1, double num2, char op){
    if(op == '+') return num1 + num2;
    if(op == '-') return num1-num2;
    if(op == '*') return num1*num2;
    if(op == '/') return num1/num2;
    else return 0;
}
