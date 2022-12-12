#include<iostream>
#include<cmath>
#include "Point2D.h"

using namespace std;

//Setting x and y 
Point2D::Point2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}
//Default constructor to set x and y to 0
Point2D::Point2D()
{
    x = 0;
    y = 0;
}
//Fidning distance between two Point2D
double GetDistanceBetween(Point2D& p1, Point2D& p2)
{
    double distance;
    distance = sqrt((pow((p1.x-p2.x),2))+ (pow((p1.y-p2.y),2)));
    return distance;
}
//Overloading << operator to return (x,y)
ostream& operator<<(ostream &stream,const Point2D &point)
{
    stream << "(" << point.x << "," << point.y << ")";
    return stream;
}
//Overloading + operator to add point and vector together and set x and y to the new point
Point2D operator + (Point2D &p1, Vector2D &v1)
{
    Point2D point;
    point.x =p1.x + v1.x;
    point.y =p1.y + v1.y;

    return point;
}
//Overloading operator in order to return vector from point a to point b
Vector2D operator - (Point2D &p1,Point2D &p2)
{
    Vector2D vector;
    vector.x = p1.x - p2.x;
    vector.y = p1.y - p2.y;

    return vector;
}