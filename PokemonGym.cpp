#include"PokemonGym.h"
#include"Building.h"
#include<iostream>
using namespace std;
//Deafult Constructor
PokemonGym::PokemonGym()
{
    display_code = 'G';
    state = NOT_DEFEATED;
    max_num_of_battles = 10;
    num_battle_remaining = max_num_of_battles;
    health_cost_per_battle = 1;
    PokeDollar_cost_per_battle = 1.0;
    experience_per_battle = 2;
    cout<<"PokemonGym deafult Constructed"<<endl;
    
}
//Default Constructor that when constructed also constructs building parameter constructor
PokemonGym::PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id,Point2D in_loc):Building('G',in_id,in_loc)
{
    id_num = in_id;
    max_num_of_battles = max_battle;
    num_battle_remaining = max_battle;
    health_cost_per_battle = health_loss;
    experience_per_battle = exp_per_battle;
    PokeDollar_cost_per_battle = PokeDollar_cost;
    location = in_loc;
    cout<<"PokemonGym constructed"<<endl;
}
//Calculate cost to battle a certian amount of times that is inputted
double PokemonGym::GetPokeDollarCost(unsigned int battle_qty)
{
    double cost;
    cost = battle_qty*PokeDollar_cost_per_battle;
    return cost;
}
//How much health would be needed to battle this certain amount of times
unsigned int PokemonGym::GetHealthCost(unsigned int battle_qty)
{
    unsigned int healthneeded;
    healthneeded = battle_qty*health_cost_per_battle;
    return healthneeded;
}
//Return number of battles remaining at the gym
unsigned int PokemonGym::GetNumBattlesRemaining()
{
    return num_battle_remaining;
}
//determining if ityou are able to battle
bool PokemonGym:: IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health)
{
    //checking that you can afford it and your health is high enough to battle
    if(budget>(battle_qty*PokeDollar_cost_per_battle)&& health>(health_cost_per_battle*battle_qty))
    {
        return true;
    }
    else
    {
        return false;
    }
}
//calculating and returning the amount of experience gathered from the battles
unsigned int PokemonGym:: TrainPokemon(unsigned int battle_units)
{
    //if there are still battles left return experience from battles entered
    if(num_battle_remaining >= battle_units)
    {
        num_battle_remaining = num_battle_remaining - battle_units;
        unsigned int experience;
        experience = battle_units*experience_per_battle;
        return experience;
    }
    //If you complete all battles return experience calculated from battles remaining in the gym
    else
    {
        unsigned int experience;
        
        experience = num_battle_remaining * experience_per_battle;
        return experience;
        num_battle_remaining = 0;

    }
}   
//return exp per battle
unsigned int PokemonGym:: GetExperiencePerBattle()
{
    return experience_per_battle;
}
//Updating what is happening at the gym
bool PokemonGym::Update()
{
    //if gym has no more battles and it hasnt been set to defeated yet make the gym beaten and return true once
    if(num_battle_remaining == 0 && state == NOT_DEFEATED)
    {
        state = DEFEATED; 
        display_code = 'g';
        cout<<display_code<<id_num<<" has been beaten"<<endl;
        return true;
    }
    //if gym hasnt been defeated yet or it has been defeated in the past return false
    else
    {
        return false;
    }
}
//Determining if this gym has been passed
bool PokemonGym:: passed()
{
    if(num_battle_remaining == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Output all information about the gym
void PokemonGym::ShowStatus()
{
    cout<<"PokemonGymStatus: ";
    Building::ShowStatus();
    cout<<endl;
    cout<<"Max number of battles: "<<max_num_of_battles<<endl;
    cout<<"Health cost per battle: "<<health_cost_per_battle<<endl;
    cout<<"PokeDollar cost per battle: "<<PokeDollar_cost_per_battle<<endl;
    cout<<"Experience per battle: "<<experience_per_battle<<endl;
    cout<<num_battle_remaining<<" battle(s) are remaining for this PokemonGym"<<endl;
    
}

PokemonGym:: ~PokemonGym()
{
    cout<<"PokemonGym destructed"<<endl;
}


