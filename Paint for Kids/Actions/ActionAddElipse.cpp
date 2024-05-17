#include "ActionAddElipse.h"
#include "..\Figures\CElipse.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionAddElipse::ActionAddElipse(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddElipse::Execute()
{
	Point P1, P2;
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getDrawColor();
	SqrGfxInfo.FillClr = pGUI->getFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	//Step 1 - Read Ellipse data from the user
		//Read 1st point and store in point P1
	pGUI->PrintMessage("New Elipse: Click at first point");
	pGUI->GetPointClicked(P1.x, P1.y);
	P1 = pGUI->ValidatePoint(P1);
	//Read 2nd point and store in point P2
	pGUI->PrintMessage("New Elipse: Click at second point");
	pGUI->GetPointClicked(P2.x, P2.y);
	P2 = pGUI->ValidatePoint(P2);
	//Clear status bar
	pGUI->ClearStatusBar();

	//Step 2 - Create a Ellipse with the parameters read from the user
	CElipse* R = new CElipse(P1, P2, SqrGfxInfo);

	//Step 3 - Add the Ellipse to the list of figures
	pManager->AddFigure(R);
	//SaveAction saveAction(pManager);
	//saveAction.SaveActionStack();
}
