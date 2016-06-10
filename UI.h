

#pragma once
#include "Controller.h"

typedef struct
{
	Controller* ctrl;
	Controller2* ctrl2;
	ControllerUndo* ctrlU;
	ControllerRedo* ctrlR;
} UI;

UI createUI(Controller* c,Controller2* c2,ControllerUndo* cU,ControllerRedo* cR);
void startUI(UI* ui);
