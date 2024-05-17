#include "ExitAction.h"
#include "..\ApplicationManager.h"

ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp)
{}

//Execute action (Exit action)
void ExitAction::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Do you want to save your game? Type Y for yes");
	if (pGUI->GetSrting() == "y")
	{
		ActionType ActType = SAVE;
		Action* pAct = pManager->CreateAction(ActType);
		pManager->ExecuteAction(pAct);
	}
	else
	{
		pGUI->PrintMessage("Good Bye :)");
	}
}
