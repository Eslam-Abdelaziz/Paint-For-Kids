#ifndef ACTION_BRING_TO_FRONT_H
#define ACTION_BRING_TO_FRONT_H
#include "Action.h"

//Bring to Front Action class
class ActionBringToFront : public Action
{
public:
	// Constructor For Bring to Front Action Class 
	ActionBringToFront(ApplicationManager* pApp);
	//Excute Bring to Front Action
	virtual void Execute();
};

#endif


