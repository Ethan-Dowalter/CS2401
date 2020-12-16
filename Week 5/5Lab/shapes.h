/**
 *        @file: shapes.h
 *      @author: Ethan Dowalter
 *        @date: July 31, 2020
 *       @brief: Contains defenitions for a parents "Shape" class with its 3 children classes
 */

#include <iostream>
using namespace std;
#ifndef SHAPES_H
#define SHAPES_H

class Shape{
    public:
        Shape();
        virtual void input();
        virtual double area() = 0;
        double cost();
    protected:
        double thickness, cost_per_cubic_unit;
};

class Circle:public Shape{
    public:
        Circle();
        void input();
        double area();
    private:
        double radius;
};

class Rectangle:public Shape{
    public:
        Rectangle();
        void input();
        double area();
    private:
        double length, width;
};

class Trapezoid:public Shape{
    public:
        Trapezoid();
        void input();
        double area();
    private:
        double base1, base2, height;
};

#endif