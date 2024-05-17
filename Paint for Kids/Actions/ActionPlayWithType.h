#ifndef ACTION_PLAY_WITH_TYPE_H
#define ACTION_PLAY_WITH_TYPE_H
#include "Action.h"

//Play With Type Action class
class ActionPlayWithType :public Action
{
	Point p;
	int correct;
	int wrong;
	string Fig;
public:
	// Constructor For Play With Type Action Class 
	ActionPlayWithType(ApplicationManager* pApp);
	//Excute Play With Type Action
	virtual void Execute();
};

#endif


#pragma once
