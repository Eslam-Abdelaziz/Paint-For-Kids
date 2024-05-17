#include "ActionAddHexagon.h"
#include "..\Figures\CHexagon.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddHexagon::Execute()
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

	//Step 1 - Read Hexagon data from the user
		//Read 1st point and store in point P1
	pGUI->PrintMessage("New Hexagon: Click at top left point");
	pGUI->GetPointClicked(P1.x, P1.y);
	P1 = pGUI->ValidatePoint(P1);
	//Read 2nd point and store in point P2
	pGUI->PrintMessage("New Hexagon: Click at bottom right point");
	pGUI->GetPointClicked(P2.x, P2.y);
	P2 = pGUI->ValidatePoint(P2);
	//Clear status bar
	pGUI->ClearStatusBar();

	// Step 2 - Prepare data of drawn Hexagon
		//User clicked 2 points,Top left point of the Hexagon = the lowest (x,y) between the 2 points
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;
	
	Point bottomright;
	bottomright.x = P1.x > P2.x ? P1.x : P2.x;
	bottomright.y = P1.y > P2.y ? P1.y : P2.y;

	//The Side Length of the Hexagon = the absoulute difference between 2 Points on the x coordinate
	int sideLength = abs(P1.x - P2.x);
	//The Height of the Hexagon = the absoulute difference between 2 Points on the y coordinate
	int Height = abs(P1.y - P2.y);

	//Step 3 - Create a Hexagon with the parameters read from the user
	CHexagon* R = new CHexagon(topLeft, bottomright, SqrGfxInfo);

	//Step 4 - Add the Hexagon to the list of figures
	pManager->AddFigure(R);
	//SaveAction saveAction(pManager);
	//saveAction.SaveActionStack();
}
