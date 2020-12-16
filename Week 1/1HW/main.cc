/**
 *        @file: main.cc
 *      @author: Ethan Dowalter
 *        @date: July 3, 2020
 *       @brief: Takes two durations of time and a constant from the user, then displays various operations performed with them
 */

#include <iostream>
#include <iomanip>
#include "MyTime.cc"
using namespace std;

/**  
 *   Function - boolToString
 *            > converts bool value to "True" or "False"
 *   @param result - bool value, 0 or 1
 *   @return - string of either "True" or "False"
 */
string boolToString (bool result);



int main(){
    /// Ask user for the inputs
    cout << "Give me a duration of time (H:MM). A = ";
    MyTime A;           //first duration
    cin >> A;
    cout << "Give me another duration of time (H:MM). B = ";
    MyTime B;           //second duration
    cin >> B;
    cout << "Now, give me a constant (non-zero). C = ";
    int C;              //constant to multiply and divide with
    cin >> C;

    /// Display operations and results in an orderly table
    cout << endl << setw(10) << left << "Operation" << setw(8) << left << "| Result" << endl;
    cout << "    A + B | " << A + B << endl;
    cout << "    A - B | " << A - B << endl;
    cout << "    A * C | " << A * C << endl;
    cout << "    B * C | " << B * C << endl;
    cout << "    A / C | " << A / C << endl;
    cout << "    B / C | " << B / C << endl;
    cout << "   A == B | " << boolToString(A == B) << endl;
    cout << "    A > B | " << boolToString(A > B) << endl;
    cout << "   A >= B | " << boolToString(A >= B) << endl;
    cout << "    A < B | " << boolToString(A < B) << endl;
    cout << "   A <= B | " << boolToString(A <= B) << endl;
    cout << endl;
    return 0;
}



string boolToString (bool result){
    string temp;            //1 or 0 converted to true or false
    if (result == true){
        temp = "True";      //1 means true
    } else {
        temp = "False";     //0 means false
    }
    return temp;
}
