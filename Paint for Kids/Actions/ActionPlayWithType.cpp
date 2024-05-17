#include "ActionPlayWithType.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionPlayWithType::ActionPlayWithType(ApplicationManager* pApp) :Action(pApp)
{
	correct = 0;
	wrong = 0;
}
void ActionPlayWithType::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int Count = 0; 
	int flag = 0;
	// Get a random figure type
	Fig = pManager->GetRandomFigure(Count);
	if (Fig != "Empty")
	{
		pGUI->PrintMessage("SELECT ALL " + Fig);
		while (Count > 0)
		{
			// Get the user's click position

			pGUI->GetPointClicked(p.x, p.y);
			if (p.y > UI.ToolBarHeight || p.x > (UI.MenuItemWidth * PLAY_ITM_COUNT-80))
			{
				CFigure* r = pManager->GetFigure(p.x, p.y);

				// Check if a figure is clicked
				if (r != NULL)
				{
					// Check if the clicked figure matches the  type (Fig)

					if (r->GetFigName() == Fig)
					{
						if (!r->getHidden())
						{
							correct++;
							Count--;
						}
					}
					else
					{
						if (!r->getHidden())
							wrong++;
					}

					r->show(false);

					pGUI->PrintMessage("Correct answers = " + to_string(correct) + "                                              "
						+ "Wrong answers = " + to_string(wrong) + "                        ..CONTINUE!");
					pManager->UpdateInterface();
				}
				else
				{
					pGUI->PrintMessage("Correct answers = " + to_string(correct) + "                                              "
						+ "Wrong answers = " + to_string(wrong) + "                  Select a Figure Please");
				}
			}
			else
			{
				pGUI->PrintMessage("Toolbar clicked, game aborted.");
				Count = -1;
			}
			
		}
		pGUI->PrintMessage("The game ended, your grade is " + to_string(correct) + "/" + to_string(correct + wrong));
		pGUI->ClearDrawArea();

		if (flag == 0)
		{
			pGUI->GetPointClicked(p.x, p.y);
			pManager->showAllFigure();
			pGUI->PrintMessage("Select  icon from toolbar ");
			pGUI->CreatePlayToolBar();

		}
		else
		{
			pManager->showAllFigure();
			pGUI->PrintMessage("Select  icon from toolbar ");
			pGUI->CreatePlayToolBar();
		}
	

		//pGUI->GetPointClicked(p.x, p.y);
		//pManager->showAllFigure();
		//pGUI->PrintMessage("Sleected any icon from toolbar please!");
		//pGUI->CreatePlayToolBar();

	}
	else
	{
		pGUI->PrintMessage("Empty Drawing Area , please selecte Draw Icon or playing another game ");
		return;
	}

}
