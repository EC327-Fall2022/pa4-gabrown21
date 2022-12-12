#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H

#include<iostream>
#include "Building.h"
#include "Point2D.h"

//enum
enum PokemonCenterStates { POTIONS_AVAILABLE = 0, NO_POTIONS_AVAILABLE = 1};
//Creat class PokemonCenter that inherits from building
class PokemonCenter: public Building
{
    //private member variables
    private:
        unsigned int potion_capacity;
        unsigned int num_potions_remaining;
        double pokedollar_cost_per_potion;
    
    public:
    //constructors
        PokemonCenter();
        PokemonCenter(int, double, unsigned int, Point2D);
        virtual ~PokemonCenter();
    //public member functions
        bool HasPotions();
        unsigned int GetNumPotionRemaining();
        bool CanAffordPotion(unsigned int potion, double budget);
        double GetPokeDollarCost(unsigned int potion);
        unsigned int DistributePotion(unsigned int potion_needed);
        bool Update();
        void ShowStatus();

};

#endif