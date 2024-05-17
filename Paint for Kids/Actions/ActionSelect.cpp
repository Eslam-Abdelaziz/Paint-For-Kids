#include "ActionSelect.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{}
//test
void ActionSelect::Execute()
{
	Point P1;
	GUI* pGUI = pManager->GetGUI();
	ApplicationManager* pAPP = pManager;

	pGUI->PrintMessage("Click any shape to select it");
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();

	CFigure* r = pManager->GetFigure(P1.x, P1.y);
	if (r) {
		r->SetSelected(!r->IsSelected());

		if (r->IsSelected())
		{
			pManager->pushselectedfigure(r);
			int index = pManager->GetFigureIndex(r);
			r->printInfo(pGUI, index);
		}
		else {
			pManager->popselectedfigure(r);
		}
		pManager->UpdateInterface();
	}
}