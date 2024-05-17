#ifndef ACTION_BRING_TO_BACK_H
#define ACTION_BRING_TO_BACK_H
#include "Action.h"

//Bring to Back Action class
class ActionBringToBack : public Action
{
public:
	// Constructor For Bring to Back Action Class 
	ActionBringToBack(ApplicationManager* pApp);
	//Excute Bring to Back Action
	virtual void Execute();
};

#endif


#include "ActionBringToBack.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <math.h>
//#include "SaveAction.h"

ActionBringToBack::ActionBringToBack(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionBringToBack::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	//Step 1 - Read point clicked from the user
	pGUI->PrintMessage("Click on any shape");
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();

	//Step 2 - Get selected figure from figure list
	CFigure* r = pManager->GetFigure(P1.x, P1.y);

	//Step 3 - Check if no figure is selected
	if (!r) { return; }

	pManager->bringBack(r);

}

