#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class ActionPlayWithFillColor :public Action
{
	Point p;
	int correct;
	int wrong;
	color Fig_Color;
	//int flag;
public:
	ActionPlayWithFillColor(ApplicationManager* pApp);
	virtual void Execute();
};

