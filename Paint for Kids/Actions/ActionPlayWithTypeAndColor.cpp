#include "ActionPlayWithTypeAndColor.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
ActionPlayWithTypeAndColor::ActionPlayWithTypeAndColor(ApplicationManager* pApp) :Action(pApp)
{
	correct = 0;
	wrong = 0;
}
void ActionPlayWithTypeAndColor::Execute() {
	GUI* pGUI = pManager->GetGUI();
	int Count = 0;
	int flag = 0;

	Fig = pManager->GetRandomColorType(Count, Fig_Type_color);
	if (Fig != "Empty") {
		stringstream print;
		print << pManager->colorToString(Fig_Type_color);
		pGUI->PrintMessage("Select all " + print.str() + " " + Fig);

		while (Count > 0)
		{
			pGUI->GetPointClicked(p.x, p.y);
			if (p.y > UI.ToolBarHeight || p.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				CFigure* r = pManager->GetFigure(p.x, p.y);
				if (r != NULL)
				{
					if (r->GetFigColor() == Fig_Type_color && r->GetFigName() == Fig)
					{
						if (!r->getHidden()) {
							correct++;
							Count--;
						}
					}
					else {
						if (!r->getHidden())
							wrong++;
					}
					r->show(false);
					pManager->UpdateInterface();
					pGUI->PrintMessage("Correct Ans = " + to_string(correct) + "                                              "
						+ "Wrong Ans = " + to_string(wrong) + "                                                 ..CONTINUE!");
				}
				else
				{
					pGUI->PrintMessage("Correct Ans = " + to_string(correct) + "                                              "
						+ "Wrong Ans = " + to_string(wrong) + "                  Select a Figure Please");

				}
			}
			else
			{
				pGUI->PrintMessage("Toolbar clicked, game aborted.");
				Count = -1;
			}
			


		}
		pGUI->PrintMessage("The game ended ,your grade is " + to_string(correct) + "/" + to_string((correct + wrong)));
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
		//pGUI->PrintMessage("Select any icon from toolbar please!");
		//pGUI->CreatePlayToolBar();
	}
	else
	{
		pGUI->PrintMessage("There aren't any Colored Figures , Select another icon from toolbar");
		return;
	}
}
