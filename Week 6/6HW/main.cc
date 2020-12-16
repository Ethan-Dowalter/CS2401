/**
 *        @file: main.cc
 *      @author: Ethan Dowalter
 *        @date: August 5, 2020
 *       @brief: Testing out some queues
 */

#include <iostream>
#include <queue>
#include "chore.h"
using namespace std;

int main(){
    priority_queue<Chore> q;
    Chore tmp;

    for (size_t i = 0; i < 5; i++)
    {
        tmp.input();
        q.push(tmp);
    }
    
    for (size_t i = 0; i < 5; i++)
    {
        q.top().output();
        q.pop();
    }
    

    return 0;
}