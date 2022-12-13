#include "WildPokemon.h"

#include <iostream>

using namespace std;

WildPokemon::WildPokemon():GameObject('W')
{
    attack = 5;
    health = 2;
    variant = false;
    in_combat = false;

    
}

WildPokemon::WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc):GameObject(in_loc, id, 'W')
{
    attack = 5;
    health = 2;
    cout << "health: " << health << endl;
    variant = false;
    in_combat = false;
    cout << "WildPokemon constructed" << endl;
}

void WildPokemon::follow(Trainer* t)
{
    current_trainer = t;
}

bool WildPokemon::get_variant()
{
    return variant;
}

double WildPokemon::get_attack()
{
    return attack;
}

double WildPokemon::get_health()
{
    return health;
}

bool WildPokemon::get_in_combat()
{
    return in_combat;
}

bool WildPokemon::Update()
{
    switch(state)
    {
        case IN_ENVIRONMENT:
            return true;
            break;
        case DEAD:
            return true;
            break;
        case IN_TRAINER:
            return true;
            break;
        default:
            state = IN_ENVIRONMENT;
            return false;
            break;
    }
}

void WildPokemon::ShowStatus()
{
    cout << "WildPokemon status: " << name << " Status: " << endl;
    GameObject::ShowStatus();
    switch (state)
    {
        case IN_ENVIRONMENT:
        {
            cout << "in the environment" << endl;
        }
        break;
        case DEAD:
        {
            cout << "dead" << endl;
        }
        break;
        case IN_TRAINER:
        {
            cout << "is following trainer" << endl;
        }
        break;
    }
}

bool WildPokemon::IsAlive()
{
    if (health == 0)
    {
        return false;
    }
    else 
    {
        return true;
    }
}

WildPokemon::~WildPokemon()
{
    cout << "WildPokemon destructed" << endl;
}

bool WildPokemon:: ShouldBeVisible()
{
    if (IsAlive() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string WildPokemon::GetName()
{
    return name;
}

Trainer* WildPokemon::GetTrainer()
{
    return current_trainer;
}

Point2D WildPokemon::GetWPLocation()
{
    return location;
}

void WildPokemon::UpdateLocation(Point2D trainer_location)
{
    state = IN_TRAINER;
    location = trainer_location;
}