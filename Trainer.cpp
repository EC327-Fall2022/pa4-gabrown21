#include"Trainer.h"
#include"GameObject.h"
#include<iostream>
#include<math.h>
#include<time.h>
#include<stdio.h>
#include<iomanip>

using namespace std;

Trainer::Trainer():GameObject('T')
{
    name = "Defualt";
    speed = 5;
    is_at_center = false;
    is_IN_GYM = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    current_center = 0;
    current_gym= 0;
    destination.x = 0.0;
    destination.y = 0.0;
    state = STOPPED;
    cout<<"Trainer deafult constructed"<<endl;
}

Trainer::Trainer(char in_code):GameObject(in_code)
{
    display_code = in_code;
    name = "Defualt";
    speed = 5;
    is_at_center = false;
    is_IN_GYM = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    current_center = 0;
    current_gym= 0;
    destination.x = 0;
    destination.y = 0;
    delta.x = 0;
    delta.y = 0;
    cout<<"Trainer constructed"<<endl;
    state = STOPPED;
}

Trainer::Trainer(string in_name,int in_id,char in_code,unsigned int in_speed,Point2D in_loc):GameObject(in_loc,in_id,in_code)
{
    display_code = in_code;
    name = in_name;
    speed = in_speed;
    is_at_center = false;
    is_IN_GYM = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    current_center = 0;
    current_gym= 0;
    destination.x = 0;
    destination.y = 0;
    delta.x = 0;
    delta.y = 0;
    state = STOPPED;
    cout<<"Trainer constructed"<<endl;
}

void Trainer::StartMoving(Point2D dest)
{
    SetupDestination(dest);

    if(location.x == dest.x && location.y == dest.y)
    {
        cout<<display_code<<id_num<<": I'm already there. See?"<<endl;

    }
    else if(state == FAINTED)
    {
        cout<<display_code<< id_num<<": My pokemon have fainted. I may move, but you cannot see me."<<endl;
    }
    else{
        state = MOVING;
        cout<<display_code<<id_num<<": On my way"<<endl;
        
    }
}

void Trainer::StartMovingToGym(PokemonGym* gym)
{
    SetupDestination(gym -> GetLocation());
    if(state == FAINTED)
    {
        cout<<display_code<<id_num<<" : My Pokemon have fainted. I may move, but you cannot see me. "<<endl;
    }
    else if(location.x == (gym ->GetLocation().x) && location.y == (gym -> GetLocation().y))
    {
        cout<<display_code<<id_num<<": I'm already there. See?"<<endl;
        state = IN_GYM;
    }
    else
    {
        current_gym = gym;
        cout<<display_code<<id_num<<": On my way"<<endl;
        state = MOVING_TO_GYM;
    }
}
void Trainer::StartMovingToCenter(PokemonCenter* center)
{
    SetupDestination(center -> GetLocation());
    if(state == FAINTED)
    {
        cout<<display_code<<id_num<<" : My Pokemon have fainted. I may move, but you cannot see me. "<<endl;
    }
    else if(location.x == (center ->GetLocation().x) && location.y == (center -> GetLocation().y))
    {
        cout<<display_code<<id_num<<": I'm already there. See?"<<endl;
        state = AT_CENTER;
    }
    else
    {
        current_center = center;
        cout<<display_code<<id_num<<": On my way"<<endl;
        state = MOVING_TO_CENTER;
    }
}

void Trainer::StartBattling(unsigned int num_battles)
{
    
    Point2D gym_loc = (current_gym -> GetLocation());
    bool able_to_battle;
    able_to_battle = current_gym -> IsAbleToBattle(num_battles, PokeDollars,health);
    //Cant do this below
    if(location.x == gym_loc.x && location.y == gym_loc.y)    
    {
        is_IN_GYM = true;
    }
    else 
    {
        is_IN_GYM = true;
    }
    if(state == FAINTED)
    {
        cout<<display_code<<": My Pokemon have fainted so no more battles for me..."<<endl;
    }
    if(is_IN_GYM == false )
    {
        cout<<display_code<<id_num<<": I can only battle in a PokemonGym"<<endl;
    }
    else if(able_to_battle == false)
    {
        cout<<display_code<<id_num<<": Cannot battle! This Pokemon does not have enough health"<<endl;
    }
    else if(current_gym -> GetPokeDollarCost(num_battles) > PokeDollars)
    {
        cout<<display_code<<id_num<<": Not enough money for battles"<<endl;
    }
    else if(current_gym->passed()==true || current_gym == NULL)
    {
        cout<<display_code<<id_num<<": Cannot battle! This PokemonGym has no more trainers to battle!"<<endl;
    }
    else
    {
        cout<<display_code<<id_num<<": Started to battle at the PokemonGym "<<id_num<<" with "<<num_battles<<" battles"<<endl;
        state = BATTLING_IN_GYM;
        battles_to_buy = num_battles;
    }
}

void Trainer::StartRecoveringHealth(unsigned int num_potions)
{
    Point2D center_loc = current_center -> GetLocation();
    if(center_loc.x == location.x && center_loc.y == location.y)
    {
        is_at_center = true;

    }
    else
    {
        is_at_center = false;
    }
    if(is_at_center == false)
    {
        cout<<display_code<<id_num<<": I can only recover health at a Pokemon Center!"<<endl;
    }
    else if(current_center -> HasPotions() == false)
    {
        cout<<display_code<<id_num<<": Cannot recover! No potion remaining in this Pokemon Center"<<endl;

    }
    else if(current_center->CanAffordPotion(num_potions, PokeDollars) == false)
    {
        cout<<display_code<<id_num<<": Not enough moeny to recover helath!"<<endl;
    }
    else
    {
        cout<<display_code<<id_num<<": Started recovering with "<<num_potions<<" potion(s) at Pokemon Center "<< current_center ->GetId()<<endl;
        potions_to_buy = num_potions;
        state = RECOVERING_HEALTH;   
        potions_to_buy = num_potions;     
    }
}

void Trainer::Stop()
{
    state = STOPPED;
    cout<<display_code<<id_num<<": Stopping..."<<endl;
}

bool Trainer::HasFainted()
{
    if(health == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

bool Trainer::ShouldBeVisible()
{
    if(HasFainted() != false)
    {
        return true;
    }
    else{
        return false;
    }
}
//Need to print state specific status information
void Trainer::ShowStatus()
{
    cout<<name<<" status: ";
    switch(state)
    {
        case STOPPED:
        {
            cout<<"Stopped"<<endl;
        }
            break;
        
        case MOVING:
        {
            cout<<"moving at a speed of "<<speed<<" to destination <"<<destination.x<<","<<destination.y<<"> at each step of "<<delta<<"."<<endl;
            
            break;
        }
        case MOVING_TO_GYM:
        {
            cout<<"heading to PokemonGym "<<current_gym -> GetId()<<" at a speed of "<<speed<<" at each step of "<<delta<<endl;
           
            break;
        }
        case MOVING_TO_CENTER:
        {
            cout<<" heading to Pokemon Center "<<current_center -> GetId()<<" at a speed of "<<speed<<" at each step of "<<delta<<endl;
          
            break;
        }
        case IN_GYM:
        {
            cout<<"inside PokemonGym "<<current_gym -> GetId()<<endl;
          
            break;
        }
        case AT_CENTER:
        {
            cout<<"inside Pokemon Center "<<current_center->GetId()<<endl;
            
            break;
        }
        case BATTLING_IN_GYM:
        {
            cout<<"battling in PokemonGym "<<current_gym -> GetId()<<endl;
           
            break;
        }
        case RECOVERING_HEALTH:
        {
            cout<<" recovering health in Pokemon Center "<<current_center -> GetId()<<endl;

            break;
        }
    }
    
    GameObject::ShowStatus();

}
//Create update function
bool Trainer::Update()
{
    switch(state)
    {
        case STOPPED:
        {
            cout<<"Health: "<<health<<endl;
            cout<<"PokeDollars: "<<PokeDollars<<endl;
            cout<<"Experience: "<<experience<<endl;
            return false;
            
        }
            break;
        
        case MOVING:
        {
            bool in_or_out = UpdateLocation();
            if(in_or_out == true)
            {
                if(health == 0)
                {
                    cout<<name<<" is out of health and can't move"<<endl;
                    state = FAINTED;
                }
                else
                {
                    state = STOPPED;
                    cout<<"Health: "<<health<<endl;
                    cout<<"PokeDollars: "<<PokeDollars<<endl;
                    cout<<"Experience: "<<experience<<endl;
                    return true;
                }
            }
            else
            {
                if(health == 0)
                {
                    cout<<name<<" is out of health and can't move"<<endl;
                    state = FAINTED;
                }
                else
                {
                    cout<<"Health: "<<health<<endl;
                    cout<<"PokeDollars: "<<PokeDollars<<endl;
                    cout<<"Experience: "<<experience<<endl;
                    return false;
                }
            }
        }
            break;
        
        case MOVING_TO_GYM:
        {
            bool in_or_out = UpdateLocation();
            if(in_or_out == true)
            {
                if(health == 0)
                {
                    cout<<name<<" is out of health and can't move"<<endl;
                    state = FAINTED;
                    return true;
                }
                else
                {
                    if(state == MOVING_TO_GYM)
                    {
                        current_gym -> AddOneTrainer();
                    }
                    cout<<"Health: "<<health<<endl;
                    cout<<"PokeDollars: "<<PokeDollars<<endl;
                    cout<<"Experience: "<<experience<<endl;
                    state = IN_GYM;
                    return true;
                }
            }
            else
            {
                if(health == 0)
                {
                    cout<<name<<" is out of health and can't move"<<endl;
                    state = FAINTED;
                }
                else
                {
                    if(state == IN_GYM)
                    {
                        current_gym ->RemoveOneTrainer();
                    }
                    //double randPokeDollars = GetRandomAmountOfPokeDollars();
                    //PokeDollars = PokeDollars + randPokeDollars;
                    cout<<"Health: "<<health<<endl;
                    cout<<"PokeDollars: "<<PokeDollars<<endl;
                    cout<<"Experience: "<<experience<<endl;
                    state = MOVING_TO_GYM;
                    return false;
                }
            }
        }
            break;
        
        case MOVING_TO_CENTER:
        {
            bool in_or_out = UpdateLocation();
            if(in_or_out == true)
            {
                if(health == 0)
                {
                    cout<<name<<" is out of health and can't move"<<endl;
                    state = FAINTED;
                }
                else
                {
                    if(state == MOVING_TO_CENTER)
                    {
                        current_center -> AddOneTrainer();

                    }
                    cout<<"Health: "<<health<<endl;
                    cout<<"PokeDollars: "<<PokeDollars<<endl;
                    cout<<"Experience: "<<experience<<endl;
                    state = AT_CENTER;
                    return true;
                }
            }
            else
            {
                if(health == 0)
                {
                    cout<<name<<" is out of health and can't move"<<endl;
                    state = FAINTED;
                }
                else
                {
                    if(state == IN_GYM)
                    {
                        current_gym -> RemoveOneTrainer();
                    }
                    else if(state == AT_CENTER)
                    {
                        current_center -> RemoveOneTrainer();
                    }
                    /*double randPokeDollars=GetRandomAmountOfPokeDollars();
                        PokeDollars=PokeDollars+randPokeDollars;*/
                    cout<<"Health: "<<health<<endl;
                    cout<<"PokeDollars: "<<PokeDollars<<endl;
                    cout<<"Experience: "<<experience<<endl;
                    state = MOVING_TO_CENTER;
                    return false;
                }
            }
        }
            break;
        case IN_GYM:
        {
            cout<<"Health: "<<health<<endl;
            cout<<"PokeDollars: "<<PokeDollars<<endl;
            cout<<"Experience: "<<experience<<endl;
            return false;
        }
            break;
        
        case AT_CENTER:
        {
            cout<<"Health: "<<health<<endl;
            cout<<"PokeDollars: "<<PokeDollars<<endl;
            cout<<"Experience: "<<experience<<endl;
            return false;
        }
            break;
        case BATTLING_IN_GYM:
        {
            health = health - (current_gym -> GetHealthCost(battles_to_buy));
            PokeDollars = PokeDollars - (current_gym -> GetPokeDollarCost(battles_to_buy));
            unsigned int experience_gained = (current_gym -> TrainPokemon(battles_to_buy));
            experience = experience_gained + experience;
            cout<<"Health: "<<health<<endl;
            cout<<"PokeDollars: "<<PokeDollars<<endl;
            cout<<"Experience: "<<experience<<endl;
            //Update battles remaining

            cout<<"**"<<name<<" completed "<<battles_to_buy<<" battle(s)!"<<endl;
            cout<<"**"<<name<<" gained "<<experience_gained<<" experience!"<<endl;
                if(health == 0)
                {
                    
                    state = FAINTED;
                }
                else
                {
                    state = IN_GYM;
                    return true;
                }
        }
        break;
        case RECOVERING_HEALTH:
        {
            unsigned int potions_recieved = current_center -> DistributePotion(potions_to_buy);
            unsigned int recovered_health = potions_to_buy*5;
            health =  recovered_health + health;
            PokeDollars = PokeDollars - (current_center -> GetPokeDollarCost(potions_to_buy));
            cout<<"**"<<name<<" recovered "<<recovered_health<<" health!"<<endl;
            cout<<"**"<<name<<" bought "<<potions_recieved<<" potion(s)!"<<endl;
            cout<<"Health: "<<health<<endl;
            cout<<"PokeDollars: "<<PokeDollars<<endl;
            cout<<"Experience: "<<experience<<endl;
            state = AT_CENTER;
            return true;
        }
        break;
    }
}

bool Trainer::UpdateLocation()
{
    if(fabs(destination.x - location.x)<=fabs(delta.x) && fabs(destination.y - location.y)<=fabs(delta.y))
    {

        location.x = destination.y;
        location.y = destination.y;
        cout<<" arrived"<<endl;
        return true;
    }
    else
    {
        if(health == 0)
        {
            cout<<name<<" is out of health and can't move"<<endl;
            state = FAINTED;
            return false;
        }
        else
        {
            cout<<display_code<<id_num<<" step.. "<<endl;
            health= health-1;
            location.x = location.x + delta.x;
            location.y = location.y + delta.y;
            cout<<" moved"<<endl;
            double addPokeDollars = GetRandomAmountOfPokeDollars();
            PokeDollars = PokeDollars + addPokeDollars;
            return false;
        }
    }

}
void Trainer::SetupDestination(Point2D dest)
{
    destination = dest;
    delta.x = (destination.x - location.x)*(speed/GetDistanceBetween(destination,location));
    delta.y = (destination.y - location.y)*(speed/GetDistanceBetween(destination,location));

}

static double GetRandomAmountOfPokeDollars()
{
    srand(time(NULL));
    float low = 5.0;
    float high = 10.0;
    float rand_PokeDollar = low + static_cast<float>(rand())*static_cast<float>(high-low)/RAND_MAX;
    return rand_PokeDollar;

}
int Trainer::GetState()
{
    return state;
}
string Trainer::GetName()
{
    return name;
}

Trainer:: ~Trainer()
{
    cout<<"Trainer destructed"<<endl;
}

PokemonCenter* Trainer::GetCurrentCenter()
{
    return current_center;
}
PokemonGym* Trainer::GetCurrentGym()
{
    return current_gym;
}

