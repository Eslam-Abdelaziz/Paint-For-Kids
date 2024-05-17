#pragma once
#include "ActionDelete.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include "..\ApplicationManager.h"


ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{}

void ActionDelete::Execute()
{
	Point p = {};

	GUI* pGUI = pManager->GetGUI();

	pManager->DeleteFigure();


	pGUI->ClearDrawArea();
	pGUI->PrintMessage("Deleted Successfully");


	pManager->UpdateInterface();
}
