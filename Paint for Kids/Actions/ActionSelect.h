#ifndef ACTION_SELECT_H
#define ACTION_SELECT_H

#include "Action.h"

//Select Action class
class ActionSelect : public Action
{
public:
	// Constructor For Select Action Class 
	ActionSelect(ApplicationManager* pApp);
	//Excute Select Action
	virtual void Execute();
};

#endif // ACTION_SELECT_H