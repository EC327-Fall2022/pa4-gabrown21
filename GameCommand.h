#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H
#include"Point2D.h"
#include"Model.h"
#include"View.h"


void DoMoveCommand(Model&, int,Point2D);
void DoMoveToCenterCommand(Model&,int,int);
void DoMoveToGymCommand(Model&,int,int);
void DoStopCommand(Model&,int);
void DoBattleCommand(Model&,int,unsigned int);
void DoRecoverInCenterCommand(Model&,int,unsigned int);
void DoAdvanceCommand(Model&,View&);
void DoRunCommand(Model&,View&);

#endif