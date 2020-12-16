/**
 *        @file: chore.h
 *      @author: Ethan Dowalter
 *        @date: August 5, 2020
 *       @brief: Chore class, which contains the name and priority number of a chore
 */

#include <iostream>
using namespace std;

class Chore{
    public:
        Chore(){
            name = "";
            priority = 0;}
        bool operator < (const Chore &other) const{
            return priority < other.priority;}
        void input();
        void output() const;
    private:
        string name;            //description of chore
        int priority;           //priority of chore, higher = more important
};

void Chore::input(){
    cout << "What is the name of the chore? : ";
    while (cin.peek() == '\n' || cin.peek() == '\r')
    {
        cin.ignore();
    }
    getline(cin, name);
    cout << "What should the priority be? (Larger number = higher priority) : ";
    cin >> priority;
}

void Chore::output() const{
    cout << "Chore : " << name << endl;
    cout << "Priority : " << priority << endl;
    cout << endl;
}