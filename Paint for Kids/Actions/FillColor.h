
#ifndef FILL_COLOR_H
#define FILL_COLOR_H

#include "Action.h"

//Select Action class
class FillColor : public Action
{
public:
	// Constructor For Select Action Class 
	FillColor(ApplicationManager* pApp);
	//Excute Select Action
	virtual void Execute();
};

#endif // ACTION_SELECT_H