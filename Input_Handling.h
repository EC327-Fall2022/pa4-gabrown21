#ifndef INVALID_HANDLING_H
#define INVALID_HANDLING_H
#include<iostream>

class Invalid_Input
{


    public :
    Invalid_Input(string in_ptr) : msg_ptr (in_ptr) { }
    const string msg_ptr;

    private:
    Invalid_Input ();
};
#endif