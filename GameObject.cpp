#include <iostream>
#include "GameObject.h"
//parameter constructor definition
 GameObject::GameObject(char in_code)
 {
    display_code = in_code;
    id_num = 1;
    state = 0;
    location.x = 0;
    location.y = 0;
    cout<<"GameObject constructed"<<endl;
 }
//parameter constructor definition 
GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
    display_code = in_code;
    id_num = in_id;
    location.x = in_loc.x;
    location.y = in_loc.y;
    state = 0;
    cout<<"GameObject constructed"<<endl;
}

Point2D GameObject::GetLocation()
{
    return location;
}

int GameObject::GetId()
{
    return id_num;
}

char GameObject::GetState()
{
    return state;
}
//Display id num display code and location
void GameObject:: ShowStatus()
{
    cout<<display_code<<" "<<id_num<<" at "<<location;
}

GameObject::~GameObject()
{
    cout<<"GameObject destructed"<<endl;
}

void GameObject::DrawSelf(char* ptr)
{
    ptr[0] = display_code;
    ptr[1] = id_num +48;
}

