#include "FoodRepoDynamic.h"
#include "UI.h"
/*
//#ifdef _MSC_VER
#include <crtdbg.h>
#else
#define _ASSERT(expr) ((void)0)

#define _ASSERTE(expr) ((void)0)
//#endifoodRepo* v,
*/
int main()
{

	//testsHumanRepo();

	FoodRepoDynamic* repo = createRepoDynamic(5);
	solRepoDynamic* repo2=createRepoSol(5);
    UndoDynamic* repoU=createRepoUndo(5);
    RedoDynamic* repoR=createRepoRedo(5);
	Controller ctrl = createController(repo);
	Controller2 ctrl2=createControllerSol(repo2);
	ControllerUndo ctrlU=createControllerUndo(repoU);
	ControllerRedo ctrlR=createControllerRedo(repoR);

	addFood(&ctrl,&ctrlU,&ctrlR, "Lapte",2,"dairy",21,02,2017);

    //addSol(&ctrl2,"da",5);
	UI ui = createUI(&ctrl,&ctrl2,&ctrlU,&ctrlR);

	startUI(&ui);

    Destroy(repo);
    DestroySol(repo2);
    DestroyUndo(repoU);
    DestroyRedo(repoR);
	return 0;
}
