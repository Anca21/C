
#include "Controller.h"
#include <string.h>

Controller createController(FoodRepoDynamic* r){
	Controller c;
	c.repo = r;
	return c;
}
Controller2 createControllerSol(solRepoDynamic* r2){
    Controller2 c2;
    c2.repo2=r2;
    return c2;
}
ControllerUndo createControllerUndo(UndoDynamic* rU){
    ControllerUndo cU;
    cU.repoU=rU;
    return cU;
}
ControllerRedo createControllerRedo(RedoDynamic* rR){
    ControllerRedo cR;
    cR.repoR=rR;
    return cR;
}
void addFood(Controller* c,ControllerUndo* cU,ControllerRedo* cR, char name[],  double quantity, char category[], int day,int month,int year){

	Food f = createFood(name, quantity,category,day,month,year);
	add(c->repo,cU->repoU,cR->repoR,f);
}
void addSol(Controller2* c2,char category[],double quantity){

    sol s=createCategory(category,quantity);
    addS(c2->repo2,s);
}
/*
The function deteles an object from the list, by its name.
Input:the name of the aliment you want to delete
Output:The modified list
*/
void DeleteFood(Controller* c,ControllerUndo* cU,ControllerRedo* cR,char deleteObj[]){
    deleteFood(c->repo,cU->repoU,cR->repoR,deleteObj);
}
void Update(Controller* c,ControllerUndo* cU,ControllerRedo* cR,char Name[],char NewName[],double newQuantity,char newCategory[],int newDay,int newMonth,int newYear){
    Food f=createFood(NewName,newQuantity,newCategory,newDay,newMonth,newYear);
    update(c->repo,cU->repoU,cR->repoR,Name,f);
 }
void Statistics(Controller* c,Controller2* c2,char solution[]){
    checkString(c->repo,c2->repo2,solution);
    sortAsc(c2->repo2);
}
void checkC(Controller* c, char categ[],int noDays){
    checkCategory(c->repo,categ,noDays);
}
FoodRepoDynamic* getRepo(Controller* c){
    return c->repo;

}
solRepoDynamic* getRepo2(Controller2* c2){
    return c2->repo2;
}
UndoDynamic* getRepoUndo(ControllerUndo* cU){
    return cU->repoU;
}
RedoDynamic* getRepoRedo(ControllerRedo* cR){
    return cR->repoR;
}
void UndoController(Controller* c,ControllerUndo* cU,ControllerRedo* cR){
    CopyVector(c->repo,cU->repoU,cR->repoR);
}
void RedoController(Controller* c, ControllerRedo* cR){
    CopyVectorRedo(c->repo,cR->repoR);
}
