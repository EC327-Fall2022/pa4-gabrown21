#include"PokemonGym.h"
#include"PokemonCenter.h"
#include"Model.h"
#include<stdlib.h>
#include<iostream>
#include"Input_Handling.h"
Model::Model()
{
    time = 0;
    Point2D trainer_location1;
    trainer_location1.x = 5;
    trainer_location1.y = 1;
    Trainer* trainer1 = new Trainer("Ash", 1, 'T', 1, trainer_location1);
    object_ptrs.push_back(trainer1);
    active_ptrs.push_back(trainer1);
    trainer_ptrs.push_back(trainer1);

    Point2D trainer_location2;
    trainer_location2.x = 10;
    trainer_location2.y = 1;
    Trainer* trainer2 = new Trainer("Misty", 2, 'T', 2, trainer_location2);
    object_ptrs.push_back(trainer2);
    active_ptrs.push_back(trainer2);
    trainer_ptrs.push_back(trainer2);

    Point2D center_location1;
    center_location1.x = 1;
    center_location1.y = 20;
    PokemonCenter* center1 = new PokemonCenter(1, 1, 100, center_location1);
    object_ptrs.push_back(center1);
    active_ptrs.push_back(center1);
    center_ptrs.push_back(center1);

    Point2D center_location2;
    center_location2.x = 10;
    center_location2.y = 20;
    PokemonCenter* center2 = new PokemonCenter(2, 2, 200, center_location2);
    object_ptrs.push_back(center2);
    active_ptrs.push_back(center2);
    center_ptrs.push_back(center2);

    Point2D gym_location1;
    gym_location1.x = 0;
    gym_location1.y = 0;
    PokemonGym* gym1 = new PokemonGym(10, 1, 2, 3, 1, gym_location1);
    object_ptrs.push_back(gym1);
    active_ptrs.push_back(gym1);
    gym_ptrs.push_back(gym1);

    Point2D gym_location2;
    gym_location2.x = 5;
    gym_location2.y = 5;
    PokemonGym* gym2 = new PokemonGym(20, 5, 7.5, 4, 2, gym_location2);
    object_ptrs.push_back(gym2);
    active_ptrs.push_back(gym2);
    gym_ptrs.push_back(gym2);

    Point2D wpokemon_location1;
    wpokemon_location1.x = 10;
    wpokemon_location1.y = 12;
    WildPokemon* wp1 = new WildPokemon("Eve", 5, 2, true, 1, wpokemon_location1);
    object_ptrs.push_back(wp1);
    active_ptrs.push_back(wp1);
    WildPokemon_ptrs.push_back(wp1);
    cout << "Health: " << wp1 -> GetName();

    Point2D wpokemon_location2;
    wpokemon_location2.x = 15;
    wpokemon_location2.y = 5;
    WildPokemon* wp2 = new WildPokemon("Vaporeon", 5, 2, true, 2, wpokemon_location2);
    object_ptrs.push_back(wp2);
    active_ptrs.push_back(wp2);
    WildPokemon_ptrs.push_back(wp2);

    num_objects = 8;
    num_trainers = 2;
    num_centers = 2;
    num_gym = 2;
    num_wildpokemon = 2;

    cout << "Model default constructed" << endl;

}

Model::~Model()
{
    cout << "Model destructed" << endl;
}

Trainer* Model::GetTrainerPtr(int id)
{
    for (list <Trainer*> :: iterator iter1 = trainer_ptrs.begin(); iter1 != trainer_ptrs.end(); iter1++)
    {
        if ((*iter1) -> GetId() == id)
        {
            return *iter1;
        }
    }
    return nullptr;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
    for(list <PokemonCenter*> :: iterator iter =center_ptrs.begin(); iter != center_ptrs.end(); iter++)
    {
        if((*iter)->GetId() == id)
            return *iter;
    }
    return nullptr;
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
    for(list <PokemonGym*> :: iterator iter = gym_ptrs.begin(); iter != gym_ptrs.end(); iter++)
    {
    if((*iter)->GetId() == id)
            return *iter; 
    }
    return nullptr;
}

WildPokemon* Model::GetWildPokemonPtr(int id)
{
     for(list <WildPokemon*> :: iterator iter = WildPokemon_ptrs.begin(); iter != WildPokemon_ptrs.end(); iter++)
    {
        cout << "health: " << (*iter) -> GetName() << endl;
    if((*iter)->GetId() == id)
        return *iter; 
    }
    return nullptr;
}

bool Model::Update()
{   
    time++;
    int output = 0;
    int gym_count = 0;
    int trainer_count = 0;
    list <GameObject*> :: iterator iter;
    for(iter = active_ptrs.begin(); iter != active_ptrs.end(); iter++)
    {
        if((*iter)->Update() == true)
        {
            output++;
        }
    }

    for(list <GameObject*> :: iterator iter1 = active_ptrs.begin(); iter1 != active_ptrs.end(); iter1++)
    {
        if((*iter1)->ShouldBeVisible() == false)
        {
            cout << "ShouldBeVisible: " << (*iter1) -> ShouldBeVisible() << endl;
            active_ptrs.erase(iter1);
            cout << "GameObject Removed" << endl;
            break;
        }
    }
    
    list <PokemonGym*> :: iterator iter2;
    for(iter2 = gym_ptrs.begin(); iter2 != gym_ptrs.end(); iter2++)
    {
        if((*iter2)->GetNumBattlesRemaining() == 0)
        {
            gym_count;
        }
    }

    list<Trainer*> :: iterator iter3;
    for(iter3 = trainer_ptrs.begin(); iter3 != trainer_ptrs.end(); iter3++)
    {
        if((*iter3)->HasFainted())
        {
            trainer_count;
        }
    }

    CheckTrainerWP();

    if (gym_count == gym_ptrs.size())
    {
        cout << "GAME OVER: You win! All battles done!" << endl;
        exit(0);
    }

    if(trainer_count == trainer_ptrs.size())
    {
        cout << "GAME OVER: You lose! All of your Trainers have lost!" << endl;
        exit(0);
    }

    if(output > 0)
    {
        return true;
    }

    return false;


}

void Model::Display(View& view)
{
    cout << "Time: " << time << endl;

    for ( list<GameObject*> :: iterator iter1 = active_ptrs.begin(); iter1 != active_ptrs.end(); iter1++)
    {
        view.Plot(*iter1);
    }

}

void Model::ShowStatus()
{
    cout << "Time: " << time << endl;;

    for(list<GameObject*> :: iterator iter1 = active_ptrs.begin(); iter1 != active_ptrs.end(); iter1++ )
    {
        (*iter1)->ShowStatus();
    }
}

void Model::CheckTrainerWP()
{
    Point2D trainer1_location = GetTrainerPtr(1)->GetLocation();
    Point2D trainer2_location = GetTrainerPtr(2)->GetLocation();
    Point2D wildpokemon1_location = GetWildPokemonPtr(1)->GetLocation();
    Point2D wildpokemon2_location = GetWildPokemonPtr(2)->GetLocation();

    if(GetDistanceBetween(trainer1_location , wildpokemon1_location) == 0)
    {
        GetTrainerPtr(1)->StartFollowingWildPokemon(this, 1, 1);
        return;
    }
    else if(GetDistanceBetween(trainer1_location , wildpokemon2_location) == 0)
    {
        GetTrainerPtr(1)->StartFollowingWildPokemon(this, 1, 2);
        return;
    }
    else if(GetDistanceBetween(trainer2_location , wildpokemon1_location) == 0)
    {
        GetTrainerPtr(2)->StartFollowingWildPokemon(this, 2, 1);
        return;
    }
    else if(GetDistanceBetween(trainer2_location , wildpokemon2_location) == 0)
    {
        GetTrainerPtr(2)->StartFollowingWildPokemon(this, 2, 2);
        return;
    }
}

void Model::NewCommand(char command, int in_id, double x, double y)
{
    switch(command)
    {
        case 'c': 
        {
            for(list <PokemonCenter*> :: iterator iter1 = center_ptrs.begin(); iter1 != center_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a unique PokemonCenter ID");
            }
            PokemonCenter* C = new PokemonCenter(in_id, 100, 2, Point2D(x,y));
            object_ptrs.push_back(C);
            active_ptrs.push_back(C);
            center_ptrs.push_back(C);
            cout << "New PokemonCenter created" << endl;
            break;
        }

        case 'g':
        {    
            for(list <PokemonGym*> :: iterator iter1 = gym_ptrs.begin(); iter1 != gym_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a unique PokemonGym ID");
            }
            PokemonGym* G = new PokemonGym(25,2,10,5,in_id,Point2D(x,y));
            object_ptrs.push_back(G);
            active_ptrs.push_back(G);
            gym_ptrs.push_back(G);
            cout << "New PokemonGym created" << endl;
            break;
        }

        case 't':
        {
            for(list <Trainer*> :: iterator iter1 = trainer_ptrs.begin(); iter1 != trainer_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a unique Trainer ID");
            }
            Trainer* T = new Trainer("NewTrainer",in_id,'S',1,Point2D(x,y));
            object_ptrs.push_back(T);
            active_ptrs.push_back(T);
            trainer_ptrs.push_back(T);
            cout << "New Trainer created" << endl;
            break;
        } 
        default:
        cout << "Unrecognized command code for creating new object" << endl;
    }
}
