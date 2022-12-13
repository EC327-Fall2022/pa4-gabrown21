#include<iostream>
#include"Point2D.h"
#include"Vector2D.h"
#include"Trainer.h"
#include"PokemonCenter.h"
#include"PokemonGym.h"
#include"Model.h"
#include"View.h"
#include"GameObject.h"
#include"Building.h"
#include"GameCommand.h"
#include"WildPokemon.h"
#include"Input_Handling.h"
#include<iostream>

using namespace std;

int main()
{
    View view;
    Model model;
    bool loop_continue;
    loop_continue = true;
    srand((unsigned int)time(NULL));
    int in1;
    double in2;
    double in3;
    char input;
    int id_trainer;
    int id_center;
    int id_gym;
    double x, y;
    unsigned int potion_count;
    unsigned int battle_count;
    Point2D point;
    char command;

    model.ShowStatus();
    view.Clear();
    model.Display(view);
    view.Draw();

    while(loop_continue == true)
    {

        cout<<"Enter game command: ";
        cin>>command;
    try
    {
        switch (command)
    {
        case 'm':
        {
            cin >> in1 >> in2 >> in3;
            if (in2 > 20 || in2 < 0 || in3 > 20 || in3 < 0)
            {
                throw Invalid_Input("Please enter a coordinate in the grid");
            }
            point.x = in2;
            point.y = in3;
            id_trainer = in1;
            DoMoveCommand(model, id_trainer, point);
        }
        break;
        case 'c':
        {
            cin >> in1 >> in2;
            id_trainer = in1;
            id_center = static_cast<int>(in2);
            DoMoveToCenterCommand(model, id_trainer, id_center);
        }
        break;
        case 'g':
        {
            cin >> in1 >> in2;
            id_trainer = in1;
            id_gym = static_cast<int>(in2);
            DoMoveToGymCommand(model, id_trainer, id_gym);
        }
        break;
        case 's':
        {
            cin >> in1;
            id_trainer = in1;
            DoStopCommand(model, id_trainer);
        }
        break;
        case 'p':
        {
            cin >> in1 >> in2;
            if (in2 <= 0)
            {
                throw Invalid_Input("Please enter a positive potion value");
            }
            id_trainer = in1;
            potion_count = static_cast<unsigned int>(in2);
            DoRecoverInCenterCommand(model, id_trainer, potion_count);
        }
        break;
        case 'b':
        {
            cin >> in1 >> in2;
            if (in2 <= 0)
            {
                throw Invalid_Input("Please enter a positive battle value");
            }
            id_trainer = in1;
            battle_count = static_cast<unsigned int>(in2);
            DoBattleCommand(model, id_trainer, battle_count);
        }
        break;
        case 'a':
        {
            DoAdvanceCommand(model, view);
        }
        break;
        case 'r':
        {
            DoRunCommand(model, view);
        }
        break;
        case 'q':
        {
            loop_continue = false;
            model.GetTrainerPtr(1)->~Trainer();
            model.GetTrainerPtr(2)->~Trainer();
            model.GetPokemonCenterPtr(1)->~PokemonCenter();
            model.GetPokemonCenterPtr(2)->~PokemonCenter();
            model.GetPokemonGymPtr(1)->~PokemonGym();
            model.GetPokemonGymPtr(2)->~PokemonGym();
            model.GetWildPokemonPtr(1)->~WildPokemon();
            model.GetWildPokemonPtr(2)->~WildPokemon();
        }
        break;
        case 'n':
        {
            cin >> input >> in1 >> in2 >> in3;
            if (input != 'g' && input != 'c' && input != 't' && input != 'w')
            {
                throw Invalid_Input("Enter a valid object type");
            }
            if (in1 > 9 || in1 < 0)
            {
                throw Invalid_Input("Enter a proper ID value");
            }
            if (in2 > 20 || in2 < 0 || in3 > 20 || in3 < 0)
            {
                throw Invalid_Input("Enter a coordinate in the grid");
            }
            model.NewCommand(input, in1, in2, in3);
            view.Clear();
            model.Display(view);
            view.Draw();

        }
    }
}
    catch(Invalid_Input& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
    }
    
    
}

}
