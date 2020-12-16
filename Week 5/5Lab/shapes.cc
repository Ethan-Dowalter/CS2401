/**
 *        @file: shapes.cc
 *      @author: Ethan Dowalter
 *        @date: July 31, 2020
 *       @brief: 
 */

#include <iostream>
#include "shapes.h"
using namespace std;

static const double PI = 3.141592653589793;

Shape::Shape(){
    thickness = cost_per_cubic_unit = 0;
}

void Shape::input(){
    double tmp;
    cout << "Enter the thickness : ";
    cin >> tmp;
    thickness = tmp;
    cout << "Enter the cost per cubic unit : ";
    cin >> tmp;
    cost_per_cubic_unit = tmp;
}

double Shape::cost(){
    return thickness * cost_per_cubic_unit * area();
}



Circle::Circle(){
    radius = 0;
    thickness = cost_per_cubic_unit = 0;
}

void Circle::input(){
    double tmp;
    cout << "Enter the radius : ";
    cin >> tmp;
    radius = tmp;
    Shape::input();
}

double Circle::area(){
    return PI * radius * radius;
}



Rectangle::Rectangle(){
    length = width = 0;
    thickness = cost_per_cubic_unit = 0;
}

void Rectangle::input(){
    double tmp;
    cout << "Enter the length : ";
    cin >> tmp;
    length = tmp;
    cout << "Enter the width : ";
    cin >> tmp;
    width = tmp;
    Shape::input();
}

double Rectangle::area(){
    return length * width;
}



Trapezoid::Trapezoid(){
    base1 = base2 = height = 0;
    thickness = cost_per_cubic_unit = 0;
}

void Trapezoid::input(){
    double tmp;
    cout << "Enter the length of the first base : ";
    cin >> tmp;
    base1 = tmp;
    cout << "Enter the length of the second base : ";
    cin >> tmp;
    base2 = tmp;
    cout << "Enter the height : ";
    cin >> tmp;
    height = tmp;
    Shape::input();
}

double Trapezoid::area(){
    return (base1 + base2) * height / 2.0;
}