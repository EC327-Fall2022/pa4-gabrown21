#ifndef POINT2D_H
#define POINT2D_H
#include<iostream>
#include "Vector2D.h"

using namespace std;

//Creating class Point2D
class Point2D {
    public: 
    //Member variables public
        double x;
        double y;//constructors
        Point2D();
        Point2D(double in_x, double in_y);

};

ostream& operator<<(ostream& stream,const Point2D& other);

double GetDistanceBetween(Point2D& p1, Point2D& p2);

Point2D operator+(Point2D& p1, Vector2D& v1);

Vector2D operator-(Point2D& p1, Point2D& p2);

#endif