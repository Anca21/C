

#pragma once
#include "FoodRepoDynamic.h"


typedef struct
{
	FoodRepoDynamic* repo;


} Controller;
typedef struct
{
    solRepoDynamic* repo2;

}Controller2;
typedef struct
{
    UndoDynamic* repoU;
}ControllerUndo;
typedef struct
{
    RedoDynamic* repoR;
}ControllerRedo;
Controller2 createControllerSol(solRepoDynamic* r2);
Controller createController(FoodRepoDynamic* r);
ControllerUndo createControllerUndo(UndoDynamic* rU);
ControllerRedo createControllerRedo(RedoDynamic* rR);

void addFood(Controller* c,ControllerUndo* cU,ControllerRedo* cR,  char name[], double quantity, char category[],int day,int month,int year);
void addSol(Controller2* c2,char category[],double quantity);

FoodRepoDynamic* getRepo(Controller* c);
solRepoDynamic* getRepo2(Controller2* c2);
UndoDynamic* getRepoUndo(ControllerUndo* cU);
RedoDynamic* getRepoRedo(ControllerRedo* cR);

void UndoController(Controller* c,ControllerUndo* cU,ControllerRedo* cR);
void RedoController(Controller* c,ControllerRedo* cR);
//void RedoController(Controller* c);

void DeleteFood(Controller* c,ControllerUndo* cU,ControllerRedo* cR,char deleteObj[]);
void Update(Controller* c,ControllerUndo* cU,ControllerRedo* cR,char Name[],char NewName[],double newQuantity,char newCategory[],int newDay,int newMonth,int newYear);
void Statistics(Controller* c, Controller2* c2,char solution[]);
void checkC(Controller* c,char categ[],int noDays);
