#ifndef VECTOR2D_H
#define VECTOR2D_H
#include<iostream>
using namespace std;

class Vector2D
{
    //initialize variables
    public:
        double x;
        double y;
//Constructors
        Vector2D();
        Vector2D(double in_x, double in_y);
    
};

Vector2D operator * (Vector2D& v1, double d);

Vector2D operator / (Vector2D& v1, double d);

ostream& operator << (ostream &stream, const Vector2D &vector);


#endif
