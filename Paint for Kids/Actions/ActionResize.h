#ifndef ACTION_RESIZE_H
#define ACTION_RESIZE_H
#include "Action.h"

//Resize Action class
class ActionResize : public Action
{
	float resizeFactor;
public:
	// Constructor For Resize Action Class 
	ActionResize(ApplicationManager* pApp, float);
	//Excute Resize Action
	virtual void Execute();
};

#endif


