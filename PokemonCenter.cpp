#include "PokemonCenter.h"
#include "building.h"
#include <iostream>
using namespace std;
//Defualt constructor
PokemonCenter::PokemonCenter()
{
    display_code = 'C';
    potion_capacity = 100;
    num_potions_remaining = potion_capacity;
    pokedollar_cost_per_potion = 5;
    state = POTIONS_AVAILABLE;
    cout<<" PokemonCenter defualt constructed"<<endl;
}
//Parameter constructor that when getting constructed constructs buildings parametger constructor
PokemonCenter::PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc):Building('C',in_id, in_loc)
{
    id_num = in_id;
    location = in_loc;
    pokedollar_cost_per_potion = potion_cost;
    potion_capacity = potion_cap;
    num_potions_remaining = potion_cap;
    state = POTIONS_AVAILABLE;
    cout<<"PokemonCenter constructed"<<endl;

}
//Determining if center has potions
bool PokemonCenter::HasPotions()
{
    if(num_potions_remaining > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Return remaining potions
unsigned int PokemonCenter::GetNumPotionRemaining()
{
    return num_potions_remaining;
}
//Determining if the user can afford to purchase potion
bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget)
{
    if(budget<pokedollar_cost_per_potion*potion)
    {
        return false;
    }
    else
    {
        return true;
    }
}
//Determine how much it would cost for however many of potions you want
double PokemonCenter::GetPokeDollarCost(unsigned int potion)
{
    double pokecost = potion* pokedollar_cost_per_potion;
    return pokecost;
}
//Setting the potions at the center after some are bought
unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed)
{
    if(num_potions_remaining >= potion_needed)
    {
        num_potions_remaining = num_potions_remaining-potion_needed;
        return potion_needed;
    }
    else
    {
        num_potions_remaining = 0;
        return num_potions_remaining;
    }
}
//Update
bool PokemonCenter::Update()
{
    if(state == POTIONS_AVAILABLE && num_potions_remaining == 0)
    {
        state = NO_POTIONS_AVAILABLE;
        display_code = 'c';
        cout<<"PokemonCenter "<<id_num<<" has ran out of potions"<<endl;
        return true;
    }
    else
    {
        return false;
    }
}

void PokemonCenter::ShowStatus()
{
    cout<<"PokemonCenter Status: ";
    Building::ShowStatus();
    cout<<"PokeDolllars per potion: "<<pokedollar_cost_per_potion<<endl;
    cout<<"has "<<num_potions_remaining<<" potion(s) remaining"<<endl;

}

PokemonCenter:: ~PokemonCenter()
{
    cout<<"PokemonCenter destructed"<<endl;
}
