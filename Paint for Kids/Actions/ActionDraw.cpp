#pragma once
#include "ActionDraw.h"
#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionDraw::ActionDraw(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionDraw::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->CreateDrawToolBar();
	pGUI->PrintMessage("Switched to Draw Mode! Let's Draw! ");
}