#include "ActionResize.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <math.h>

//Constructor
ActionResize::ActionResize(ApplicationManager* pApp, float factor) :Action(pApp)
{
	resizeFactor = factor;

}
//Execute Method
void ActionResize::Execute()
{
	vector<CFigure*>& figlist = pManager->getselectedfigure();
	GUI* pGUI = pManager->GetGUI();
	for (int i = 0; i < figlist.size(); i++) {

		int x = figlist[i]->resize(resizeFactor);
		if (x == -1) {
			pGUI->ClearDrawArea();
			pGUI->PrintMessage(" The shape can't be resized! Shape will be out of draw area");
		}
		else if (x == -2) {
			pGUI->ClearDrawArea();
			pGUI->PrintMessage("The shape can't be small ! ");
		}

		else {
			pGUI->ClearStatusBar();
			pGUI->ClearDrawArea();
		}
	}

}


