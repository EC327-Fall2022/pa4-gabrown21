#include "Building.h"
#include<iostream>
#include "GameObject.h"

using namespace std;

Building::Building():GameObject('B')
{
    cout<<"Building defualt constructed"<<endl;

}

Building::Building(char in_code, int in_id, Point2D in_loc):GameObject(in_loc, in_id, in_code)
{
    id_num = in_id;
    location = in_loc;
    display_code = in_code;
    cout<<"Building defualt constructed"<<endl;
}

void Building::AddOneTrainer()
{
    trainer_count = 1+trainer_count;
}

void Building::RemoveOneTrainer()
{
    trainer_count = trainer_count -1;
}

void Building::ShowStatus()
{
    cout<<display_code<<" "<<id_num<<" located at "<<location<<endl;
    if(trainer_count == 1)
    {
       cout<<trainer_count<<" trainer is in this building"<<endl;
    }
    else
    { 
        cout<<trainer_count<<" trainers are in this building"<<endl;
    }
}

bool Building::ShouldBeVisible()
{
        return true;
}

Building::~Building()
{
    cout<<"Building destructed"<<endl;
}


