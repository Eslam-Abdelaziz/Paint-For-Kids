#include "ActionBringToFront.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <math.h>
//#include "SaveAction.h"

ActionBringToFront::ActionBringToFront(ApplicationManager* pApp) :Action(pApp)
{}

void ActionBringToFront::Execute()
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

	pManager->bringFront(r);



}

