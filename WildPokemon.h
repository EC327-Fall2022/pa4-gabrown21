#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H
#include "Trainer.h"
class WildPokemon
{
    protected:
        double attack;
        double health;
        bool variant;
        bool in_combat;
        string name;
        Trainer* current_trainer;
    public:
        void follow(Trainer* t);
        bool get_variant();
        double get_attack();
        double get_health();
        bool get_in_combat();
        bool Update();
        void ShowStatus();
        bool isAlive();
};

#endif