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
    unsigned int potion_count;
    unsigned int battle_count;
    Point2D location1;
    char command;

    model.ShowStatus();
    view.Clear();
    model.Display(view);
    view.Draw();

    while(loop_continue == true)
    {

        cout<<"Enter game command: ";
        cin>>command;

        switch(command)
        {
            case 'm':
            {
                cin>>in1>>location1.x>>location1.y;
                DoMoveCommand(model,in1,location1);
                
            }
            break;
            case 'c':
            {
                cin>>in1>>in2;
                DoMoveToCenterCommand(model,in1,in2);
            }
            break;
            case 'g':
            {
                cin>>in1>>in2;
                DoMoveToGymCommand(model,in1,in2);
            }
            break;
            case 's':
            {
                cin>>in1;
                DoStopCommand(model,in1);
            }
            break;
            case 'p':
            {
                cin>>in1>>potion_count;
                DoRecoverInCenterCommand(model,in1,potion_count);

            }
            break;
            case 'b':
            {
                cin>>in1>>battle_count;
                DoBattleCommand(model,in1,battle_count);
            }
            break;
            case 'a':
            {
                DoAdvanceCommand(model,view);
            }
            break;
            case 'r':
            {
                DoRunCommand(model,view);
            }
            break;
            case 'q':
            {
                cout<<" Program Terminated "<<endl;
                loop_continue = false;
            }
            break;
        }
    }
}
