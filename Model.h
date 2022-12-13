#ifndef MODEL_H
#define MODEL_H

#include"GameObject.h"
#include"PokemonGym.h"
#include"Trainer.h"
#include"PokemonCenter.h"
#include"View.h"
#include<list>

class WildPokemon;
class Trainer;
class Model
{
    private:
    int time;
    list<GameObject*> object_ptrs;
    list<GameObject*> active_ptrs;
    int num_objects;
    list<Trainer*> trainer_ptrs;
    int num_trainers;
    list<PokemonCenter*> center_ptrs;
    int num_centers;
    list<PokemonGym*> gym_ptrs;
    int num_gym;
    list<WildPokemon*> WildPokemon_ptrs;
    int num_wildpokemon;

    public:
        Model();
        virtual ~Model();
        Trainer* GetTrainerPtr(int id);
        PokemonCenter* GetPokemonCenterPtr(int id);
        PokemonGym* GetPokemonGymPtr(int id);
        WildPokemon* GetWildPokemonPtr(int);
        bool Update();
        void Display(View& view);
        void ShowStatus();
        void CheckTrainerWP();
        void NewCommand(char,int,double,double);

};
#endif