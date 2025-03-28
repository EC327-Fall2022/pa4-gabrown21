#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H
#include "Trainer.h"
enum WildPokemonStates{
    IN_ENVIRONMENT = 0,
    DEAD = 1,
    IN_TRAINER = 2
};

class Trainer;

class WildPokemon: public GameObject
{
    protected:
    double attack;
    double health;
    bool variant;
    bool in_combat;
    string name;
    Trainer* current_trainer;

    public:
    WildPokemon();
    WildPokemon(string, double, double, bool, int, Point2D);
    void follow(Trainer* t);
    bool get_variant();
    double get_attack();
    double get_health();
    bool get_in_combat();
    bool Update();
    void ShowStatus();
    bool IsAlive();
    ~WildPokemon();
    bool ShouldBeVisible();
    string GetName();
    Trainer* GetTrainer();
    Point2D GetWPLocation();
    void UpdateLocation(Point2D);
};

#endif