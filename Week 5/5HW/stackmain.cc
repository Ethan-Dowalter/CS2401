/**
 *        @file: stackmain.cc
 *      @author: Ethan Dowalter
 *        @date: July 29, 2020
 *       @brief: Using a stack to build a RPN notation calculator
 */

/*****************************************************************
	Lab Assignment 8 - working with a stack
	It's sometimes tricky to set up the loop that reads the 
expression from the keyboard, so I am giving that to you. You have to 
fill in the rest of the main.
	John Dolan Spring 2019
			Ohio University
			Home of the Bobcats 
******************************************************************/
#include <stack> 
#include <iostream>
#include "calc_useful.h"
using namespace std; 

int main(){
    // declare your stack here
    stack<int> nums;
    char c;
    int onenum, twonum, choice;
    
    do
    {
        start:
        while (nums.size() > 0)     //clear list from potential error in last loop
        {
            nums.pop();
        }
        
        cout << endl;
        cout << "1) Evaluate an expression in RPN notation.\n";
        cout << "2) Quit\n";
        while (cin.peek() == '\n' || cin.peek() == '\r' || cin.peek() == ' ')
        {
            cin.ignore();
        }
        cin >> choice;

        if (choice == 1)
        {
            cout<<"Please enter your expression:\n";
            while (cin.peek() == '\n' || cin.peek() == '\r' || cin.peek() == ' ')
            {
                cin.ignore();
            }
            c = cin.get(); // priming read for the sentinel loop.
            while(c != '\n')
            {
                if(isdigit(c))
                {
                    cin.putback(c);
                    cin>>onenum;
                    // stack operation here.
                    nums.push(onenum);
                }
                else if(isop(c))
                {
                    // if the stack is empty here you have an error.
                    if (nums.empty() || nums.size() < 2)
                    {
                        cout << "Error. Too many operators for operands.\n";
                        goto start;
                    }
                    
                    // here is where you have to pop a couple of numbers,
                    onenum = nums.top();
                    nums.pop();
                    twonum = nums.top();
                    nums.pop();
                    // apply the operator to the numbers
                    // and then push the result back into the stack	
                    nums.push(evaluate(twonum, onenum, c));
                }
                c = cin.get(); // reading at the bottom of the sentinel loop
            }
            // this is where you get your final answer off the stack
            onenum = nums.top();
            nums.pop();
            // it should be the only number left on the stack at this point
            if(! nums.empty())
            {
                cout<<"Error. Insufficient operators for operands.\n";
                goto start;
            }
            cout << "The answer is: " << onenum << endl;
        }
        else if (choice != 2)
        {
            cout << "Invalid choice.\n";
        }
    } while (choice != 2);

    return 0;
}