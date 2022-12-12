#include<iostream>
#include "Vector2D.h"

using namespace std;
//Defaulkt constructor setting x and y to 0
Vector2D::Vector2D()
{
    x = 0;
    y = 0;
}
//Parameter constructor in order to set x and y values       
Vector2D::Vector2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}
//Operator overload for * in order to multiply vector by constant
Vector2D operator * (Vector2D& v1, double d)
{
    Vector2D vector;
    vector.x = v1.x*d;
    vector.y = v1.y*d;
    return vector;

}
//Operator overload for * in order to divide vector by constant
Vector2D operator / (Vector2D& v1, double d)
{
    if(d == 0)
    {
        return v1;
    }
    else
    {
        Vector2D vector;
        vector.x = v1.x/d;
        vector.y = v1.y/d;

        return vector;
    }
}
//Operator overload in order to print a vector in vector form
ostream& operator << (ostream &stream, const Vector2D &vector)
{
    stream << "<" << vector.x << "," << vector.y << ">";
    return stream;
}




