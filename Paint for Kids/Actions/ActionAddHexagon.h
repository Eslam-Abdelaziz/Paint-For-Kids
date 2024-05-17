#pragma once
#ifndef ACTION_ADD_HEXAGON_H
#define ACTION_ADD_HEXAGON_H
#include "Action.h"

//Add Hexagon Action class
class ActionAddHexagon :public Action
{
public:
	// Constructor For Add Hexagon Action Class 
	ActionAddHexagon(ApplicationManager* pApp);
	//Add Hexagon to the ApplicationManager
	virtual void Execute();
};

#endif
