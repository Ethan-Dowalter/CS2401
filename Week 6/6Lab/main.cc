/**
 *        @file: main.cc
 *      @author: Ethan Dowalter
 *        @date: August 9, 2020
 *       @brief: Learning how to think recursively
 */

#include <iostream>
using namespace std;

///Prints all even numbers from 0 up to n (including n if n is even)
void counting(int n);

///Takes a string and two indices and reverses string only between the two indices
void reversing(string &s, int start, int end);



int main(){
    /// Part 1
    int x;
	for(int j=0; j<3; ++j){
        cout<<"Enter a number: ";
        cin>>x;
        cout<<"The even numbers counting to there:\n";
        counting(x);
	}

    /// Part 2
    string s;
    int start, end;
    cout<<"Enter a string:";
    while (cin.peek() == '\n' || cin.peek() == '\r')
    {
        cin.ignore();
    }
    getline(cin,s);
    cout<<"Now enter two numbers that are within the bounds of the string.";
    cin>>start>>end;
    cout<<"This is how your words look now:\n";
    reversing(s,start,end);
    cout<<s<<endl;

    return 0;
}



void counting(int n){
    if (n % 2 == 1)     //makes sure n is even
    {
        n--;
    }
    if (n == 0)         //base case
    {
        cout << n << endl;
        return;
    }
    else
    {
        cout << n << endl;      //since n is even, print it
        counting(n - 2);        //recursive call
    }
}

void reversing(string &s, int start, int end){
    if (start > end)        //base case
    {
        return;
    }
    else
    {
        char tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;           //swap start and end
        start++;                //move start up a spot
        end--;                  //move end back a spot
        reversing(s, start, end);       //recursive call
    }
}