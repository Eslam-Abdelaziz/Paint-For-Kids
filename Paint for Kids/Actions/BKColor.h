#pragma once
#ifndef BK_COLOR_H
#define BK_COLOR_H

#include "Action.h"

//Select Action class
class BKColor : public Action
{
public:
	// Constructor For Select Action Class 
	BKColor(ApplicationManager* pApp);
	//Excute Select Action
	virtual void Execute();
};

#endif // ACTION_SELECT_H