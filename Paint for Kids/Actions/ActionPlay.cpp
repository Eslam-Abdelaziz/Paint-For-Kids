#include "ActionPlay.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionPlay::ActionPlay(ApplicationManager* pApp) :Action(pApp)
{

}

void ActionPlay::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->CreatePlayToolBar();
	pGUI->PrintMessage("Switched to Play Mode! Let's Play!");
}