#ifndef TRAINER_H
#define TRAINER_H

#include"GameObject.h"
#include"PokemonGym.h"
#include"PokemonCenter.h"
#include<iostream>
#include<vector>
#include "WildPokemon.h"
#include "Model.h"
class Model;

enum TrainerStates {
STOPPED = 0,
MOVING = 1,
FAINTED = 2,
AT_CENTER = 3,
IN_GYM = 4,
MOVING_TO_CENTER = 5,
MOVING_TO_GYM = 6,
BATTLING_IN_GYM = 7,
RECOVERING_HEALTH = 8
};

class Trainer:public GameObject
{
    public:
        Trainer();
        Trainer(char);
        Trainer(string,int,char,unsigned int,Point2D);
        virtual ~Trainer();
        void StartMoving(Point2D);
        void StartMovingToGym(PokemonGym*);
        void StartMovingToCenter(PokemonCenter*);
        void StartBattling(unsigned int);
        void StartRecoveringHealth(unsigned int);
        void Stop();
        bool HasFainted();
        bool ShouldBeVisible();
        void ShowStatus();
        bool Update();
        string GetName();
        PokemonCenter* GetCurrentCenter();
        PokemonGym* GetCurrentGym();
        int GetState();
        void StartFollowingWildPokemon(Model* model, int, int);

    protected:
        bool UpdateLocation();
        void SetupDestination(Point2D dest);

    private: 
        double speed;
        bool is_at_center;
        bool is_IN_GYM;
        unsigned int health;
        unsigned int experience;
        double PokeDollars;
        unsigned int battles_to_buy;
        unsigned int potions_to_buy;
        string name;
        vector<WildPokemon*> WildPokemonVector;
        PokemonCenter* current_center;
        PokemonGym* current_gym;
        Point2D destination;
        Vector2D delta;

};

static double GetRandomAmountOfPokeDollars();

#endif