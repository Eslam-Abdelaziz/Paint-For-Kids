#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class ActionPlayWithTypeAndColor : public Action
{
	Point p;
	int correct;
	int wrong;
	color Fig_Type_color;
	string Fig;

public:
	ActionPlayWithTypeAndColor(ApplicationManager* pApp);


	virtual void Execute();
};