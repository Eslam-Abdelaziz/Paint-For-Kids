#pragma once
#ifndef DROW_COLOR_H
#define DROW_COLOR_H

#include "Action.h"

//Select Action class
class DrowColor : public Action
{
public:
	// Constructor For Select Action Class 
	DrowColor(ApplicationManager* pApp);
	//Excute Select Action
	//test  githup
	//test from abdullah
	virtual void Execute();
};

#endif // ACTION_SELECT_H