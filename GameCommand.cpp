#include<iostream>
#include"GameCommand.h"
#include"GameCommand.h"

void DoMoveCommand(Model& model,int trainer_id,Point2D p1)
{
    PokemonCenter* current_center;
    PokemonGym* current_gym;
    Trainer* trainer;
    trainer = model.GetTrainerPtr(trainer_id);
    //Why is trainer pointer pointing to game object
    if(trainer != 0)
    {
        if(trainer -> GetState() == AT_CENTER)
        {
            current_center = trainer->GetCurrentCenter();
            current_center -> RemoveOneTrainer();
        }
        else if(trainer -> GetState() == IN_GYM)
        {
            current_gym = trainer ->GetCurrentGym();
            current_gym ->RemoveOneTrainer();
        }  
    cout<<"Moving"<<trainer->GetName()<<" to "<<p1<<endl;
    trainer ->StartMoving(p1);
    }
    else
    {
        cout<<"Error: Please enter valid command!"<<endl;
    }
}

void DoMoveToCenterCommand(Model& model,int trainer_id, int center_id)
{
 
    PokemonCenter* center = model.GetPokemonCenterPtr(center_id);
    Trainer* trainer = model.GetTrainerPtr(trainer_id);
    PokemonGym* current_gym;
    PokemonCenter* current_center;

    if(trainer != 0 || center != 0)
    {
        if(trainer -> GetState() == AT_CENTER)
        {
            current_center = trainer ->GetCurrentCenter();
            current_center -> RemoveOneTrainer();
        }
        else if(trainer -> GetState() == IN_GYM)
        {
            current_gym = trainer->GetCurrentGym();
            current_gym ->RemoveOneTrainer();
        }
        cout<<"Moving "<<trainer->GetName()<<" to pokemon center "<<center ->GetId()<<endl;
        trainer -> StartMovingToCenter(center);
    }
    else
    {
        cout<<"Error: Please enter a valid command! "<<endl;
    }

}

void DoMoveToGymCommand(Model& model, int trainer_id,int gym_id)
{
    Trainer* trainer = model.GetTrainerPtr(trainer_id);
    PokemonGym* gym = model.GetPokemonGymPtr(gym_id);
    PokemonCenter* current_center;
    PokemonGym* current_gym;
    if(trainer != 0 || gym != 0)
    {
        if(trainer -> GetState() == AT_CENTER)
        {
                current_center = trainer -> GetCurrentCenter();
                current_center->RemoveOneTrainer();
        }
        else if(trainer -> GetState() == IN_GYM)
        {
            current_gym = trainer->GetCurrentGym();
            current_gym->RemoveOneTrainer(); 
        }
        cout<<"Moving "<<trainer->GetName()<<" to gym "<<gym ->GetId()<<endl;
        trainer -> StartMovingToGym(gym);
    }
    else{
            cout<<"Error: Please enter a valid command! "<<endl;
    }
}

void DoStopCommand(Model& model, int trainer_id)
{
    if(model.GetTrainerPtr(trainer_id)==0)
    {
        cout<<"Error: Please enter a valid command"<<endl;
    }
    else
    {
        cout<<"Stopping "<<model.GetTrainerPtr(trainer_id)->GetName();
        model.GetTrainerPtr(trainer_id)->Stop();
    }
}

void DoBattleCommand(Model& model, int trainer_id,unsigned int battles)
{
    if(model.GetTrainerPtr(trainer_id) == 0)
    {
        cout<<"Error: Please enter a valid command!"<<endl;

    }
    else
    {
        
            cout<<model.GetTrainerPtr(trainer_id)->GetName()<<" is battling"<<endl;
            model.GetTrainerPtr(trainer_id)->StartBattling(battles);
    }
}

void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed)
{
    if(model.GetTrainerPtr(trainer_id) == 0)
    {
        cout<<"Error: Please enter a valid command!"<<endl;

    }
    else
    {
            cout<<"Recovering "<<model.GetTrainerPtr(trainer_id)->GetName()<<"'s Pokemons health"<<endl;
            model.GetTrainerPtr(trainer_id)->StartRecoveringHealth(potions_needed);
    }
}

void DoAdvanceCommand(Model& model,View& view)
{
    model.Update();
    cout<<"Advancing one tick"<<endl;
    model.ShowStatus();
    view.Clear();
    model.Display(view);
    view.Draw();
}

void DoRunCommand(Model& model,View& view)
{
    bool update = model.Update();
    int count = 0;
    while(count<4 && update != true)
    {
        update = model.Update();
        count++;
    }
    model.Display(view);
    cout<<"Advancing to next event."<<endl;
    model.ShowStatus();
    view.Clear();
    model.Display(view);
    view.Draw();

}