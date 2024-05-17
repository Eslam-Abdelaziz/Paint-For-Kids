#ifndef ACTION_ADD_ELIPSE_H
#define ACTION_ADD_ELIPSE_H
#include "Action.h"

//Add Ellipse Action class
class ActionAddElipse : public Action
{
public:
	// Constructor For Add Ellipse Action Class 
	ActionAddElipse(ApplicationManager* pApp);
	//Add Ellipse to the ApplicationManager
	virtual void Execute();
};

#endif