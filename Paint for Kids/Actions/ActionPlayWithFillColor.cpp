#include "ActionPlayWithFillColor.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
#include <sstream>
ActionPlayWithFillColor::ActionPlayWithFillColor(ApplicationManager* pApp) : Action(pApp)
{
	correct = 0;
	wrong = 0;
	
}
void ActionPlayWithFillColor::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int Count = 0;
	int flag = 0;
	Fig_Color = pManager->GetRandomColor(Count);

	
	if (Fig_Color != UI.BkGrndColor)
	{
		stringstream print;
		print << pManager->colorToString(Fig_Color);
		pGUI->PrintMessage("Select all " + print.str() + " Figures");
		while (Count > 0)
		{
			pGUI->GetPointClicked(p.x, p.y);
			if (p.y > UI.ToolBarHeight || p.x > (UI.MenuItemWidth * PLAY_ITM_COUNT-80))
			{
				CFigure* r = pManager->GetFigure(p.x, p.y);
				if (r != NULL)
				{
					if (r->GetFigColor() == Fig_Color)
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
					pManager->UpdateInterface();

					pGUI->PrintMessage("Correct answers = " + to_string(correct) + "                                            " + "Wrong answers = " + to_string(wrong) + "                                                 ..CONTINUE!");
				}

				else
				{
					pGUI->PrintMessage("Correct answers = " + to_string(correct) + "                                           " + "Wrong answers = " + to_string(wrong) + "                  Select a Figure Please");
				}
			}
			else
			{
				flag = 1;
				pGUI->PrintMessage("Toolbar clicked, game aborted.");
				Count = -1;
			}

		}
		pGUI->PrintMessage("The game ended, your grade is " + to_string(correct) + "/" + to_string((correct + wrong)));

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
		//pGUI->PrintMessage("Select  icon from toolbar ");
		//pGUI->CreatePlayToolBar();
	}
	else
	{
		pGUI->PrintMessage("Empty Drawing Area , please selecte Draw Icon or playing another game ");
		return;
	}
}
