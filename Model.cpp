#include"PokemonGym.h"
#include"PokemonCenter.h"
#include"Model.h"

Model::Model()
{
    time = 0;
    Point2D trainer_loc1;
    trainer_loc1.x = 5;
    trainer_loc1.y = 1;
    trainer_ptrs[0] = new Trainer("Ash",1,'T',1,trainer_loc1);
    object_ptrs[0] = trainer_ptrs[0];

    Point2D trainer_loc2;
    trainer_loc2.x = 10;
    trainer_loc2.y = 1;
    trainer_ptrs[1] = new Trainer("Misty",2,'T',2,trainer_loc2);
    object_ptrs[1] = trainer_ptrs[1];

    Point2D center_loc1;
    center_loc1.x = 1;
    center_loc1.y = 20;
    center_ptrs[0] = new PokemonCenter(1,1,100,center_loc1);
    object_ptrs[2] = center_ptrs[0];

    Point2D center_loc2;
    center_loc2.x = 10;
    center_loc2.y = 20;
    center_ptrs[1] = new PokemonCenter(2,2,200,center_loc2);
    object_ptrs[3] = center_ptrs[1];

    Point2D gym1_loc;
    gym1_loc.x = 0;
    gym1_loc.y = 0;
    gym_ptrs[0] = new PokemonGym(10,1,2,3,1,gym1_loc);
    object_ptrs[4] = gym_ptrs[0];

    Point2D gym2_loc;
    gym2_loc.x = 5;
    gym2_loc.y = 5;
    gym_ptrs[1] = new PokemonGym(20,5,7.5,4,2,gym2_loc);
    object_ptrs[5] = gym_ptrs[1];

    num_objects = 6;
    num_trainers = 2;
    num_centers = 2;
    num_gym =2;
    
    cout<<"Model deafult constructed"<<endl;


}

Model::~Model()
{
    for(int i =0;i<6;i++)
    {
        delete object_ptrs[i];
    }
    cout<<"Model destructed"<<endl;
}

Trainer* Model::GetTrainerPtr(int id)
{
    bool foundptr;
    for(int i = 0;i<num_trainers;i++)
    {
        if(id == trainer_ptrs[i]->GetId())
        {
            foundptr = true;
            return trainer_ptrs[i];
        }
        else
        {
                foundptr = false;
        }
    }
    if(foundptr == false)
        {
            return 0;
        }
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
    bool foundptr;
    
    for(int i = 0; i<10;i++ )
    {
        if(id==center_ptrs[i] -> GetId())
        {
            foundptr = true;
            return center_ptrs[i];
        }
        else
        {
            foundptr = false;
        }
    }
    if(foundptr == false)
        {
            return 0;
        }
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
    bool foundptr;
    for(int i = 0;i<10;i++)
    {
        if(id == gym_ptrs[i]->GetId())
        {
            foundptr = true;
            return gym_ptrs[i];
        }
        else{
            foundptr == false;
        }
    }
    if(foundptr == false)
        {
            return 0;
        }
}

bool Model::Update()
{
    //time++;
    bool gyms_defeated[10];
    bool all_gyms_defeated;
    int count_gym = 0;
    for(int i = 0; i<num_gym;i++)
    {
        gyms_defeated[i] = gym_ptrs[i] -> passed();

    }
    for(int i = 0; i<num_gym; i++)
    {
        if(gyms_defeated[i] == true)
        {
            count_gym++;
        }
        else if(gyms_defeated[i] == false)
        {
            all_gyms_defeated = false;
        }
    }
    if(count_gym==num_gym)
    {
        all_gyms_defeated = true;
        cout<<"GAME OVER: You win! All battles done!"<<endl;
        exit(0);
    }
    bool Fainted[10];
    bool all_fainted;
    int count_fainted = 0;
    for(int i = 0;i<num_trainers; i++)
    {
        Fainted[i]=trainer_ptrs[i]->HasFainted();

    }
    for(int i = 0; i<num_trainers;i++)
    {
        if(Fainted[i] == true)
        {
            count_fainted++;
        }
        else if(Fainted[i] == false)
        {
            all_fainted == false;
        }

    }
    if(count_fainted == num_trainers)
    {
        all_fainted = true;
        cout<<"GAME OVER: You lose! All of your Trainers' pokemon have fainted"<<endl;
        exit(0);
    }
    bool is_true[10];
    time++;
    for(int i = 0;i<num_objects;i++)
    {
        is_true[i] = object_ptrs[i]->Update();
    }
    for(int i = 0;i<num_objects; i++)
    {
        if(is_true[i] == true)
        {
            return true;
        }
    }
}

void Model::ShowStatus()
{
    cout<<"Time: "<<time<<endl;
    for(int i = 0;i<num_objects;i++)
    {
       object_ptrs[i] ->ShowStatus();
    }
}

void Model::Display(View& view)
{
    cout<< "Time: "<<time<<endl;
    for(int i = 0; i<num_objects;i++)
    {
        view.Plot(object_ptrs[i]);
    }
}
