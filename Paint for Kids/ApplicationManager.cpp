#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddElipse.h"
#include "Actions\ActionAddHexagon.h"
#include "Actions\ActionSelect.h"
#include "Actions\DrowColor.h"
#include "Actions\FillColor.h"
#include "Actions\BKColor.h"
#include "Actions\ExitAction.h"
#include "Actions\SaveAction.h"
#include "Actions\ActionLoad.h"
#include "Actions\ActionPlay.h"
#include "Actions\ActionDraw.h"
#include "Actions\ActionResize.h"
#include "Actions\ActionBringToFront.h"
#include "Actions\ActionBringToBack.h"
#include "Actions\ActionDelete.h"
#include "Actions\ActionPlayWithType.h"
#include "Actions\ActionPlayWithFillColor.h"
#include "Actions\ActionPlayWithTypeAndColor.h"



//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();	

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;

		case DRAW_ELPS:
			newAct = new ActionAddElipse(this);
			///create AddLineAction here
			break;
		case DRAW_HEX:
			newAct = new ActionAddHexagon(this);
			break;
		case SELECT  :
			newAct = new ActionSelect(this);
			break;
		case CHNG_DRAW_CLR:
			newAct = new DrowColor(this);
			break;
		case CHNG_FILL_CLR:
			newAct = new FillColor(this);
			break;
		case CHNG_BK_CLR:
			newAct = new BKColor(this);
			break;
		case SAVE:
			newAct = new SaveAction(this);
			break;
		case LOAD:
			newAct = new ActionLoad(this);
			break;
			// action resize
		case RESIZE_QUARTER:
			newAct = new ActionResize(this, 0.25);
			break;
		case RESIZE_HALF:
			newAct = new ActionResize(this, 0.5);
			break;
		case RESIZE_DOUBLE:
			newAct = new ActionResize(this, 2);
			break;
		case RESIZE_QUADRUPLE:
			newAct = new ActionResize(this, 4);
			break;
		case BRNG_FRNT:
			newAct = new ActionBringToFront(this);
			break;
		case SEND_BACK:
			newAct = new ActionBringToBack(this);
			break;
		case DEL:
			newAct = new ActionDelete(this);
			break;
		case EXIT:
			///create ExitAction here
			newAct = new ExitAction(this);
			break;
		case TO_PLAY:
			newAct = new ActionPlay(this);
			break;
		case TO_DRAW:
			newAct = new ActionDraw(this);
			break;
			//play mode
		case PLAYWITHTYPE:
			newAct = new ActionPlayWithType(this);
			break;
		case PLAYWITHCOLOR:
			newAct = new ActionPlayWithFillColor(this);
			break;
		case PLAYWITHTYPECOLOR:
			newAct = new ActionPlayWithTypeAndColor(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i =0;i < FigCount;i++)
	{
		if (FigList[i]->isInside(x, y))
		{
			return FigList[i];
		}
	}

	///Add your code here to search for a figure given a point x,y	
	return NULL;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pGUI->ClearDrawArea();

	for (int i = 0; i < FigCount; i++) {
		if (!FigList[i]->getHidden())
		{
			FigList[i]->DrawMe(pGUI);
		}
	}

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}
////////////// select function ///////////
int ApplicationManager::GetFigureIndex(CFigure* x)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == x)
		{
			return i;
		}
	}
	return -1;
}
/*
vector<CFigure*>& ApplicationManager::GetFigtList()
{
	return FigList;
}*/

void ApplicationManager::pushselectedfigure(CFigure* pfig)
{
	selectedfigure.push_back(pfig);
}

void ApplicationManager::popselectedfigure(CFigure* pfig)
{
	for (int i = 0; i < selectedfigure.size(); i++) {
		if (pfig == selectedfigure[i]) {
			selectedfigure.erase(selectedfigure.begin() + i);
			break;
		}
		
	}
}

void ApplicationManager::changeDrawColor(color c) {
		for (int i = 0; i < selectedfigure.size(); i++) {
			selectedfigure[i]->ChngDrawClr(c);
		}
}

void ApplicationManager::changeFillColor(color c) {

	for (int i = 0; i < selectedfigure.size(); i++) {
		selectedfigure[i]->ChngFillClr(c);
	}
}



vector<CFigure*>& ApplicationManager::getselectedfigure()
{
	return selectedfigure;
}


////////////// save & load functions ///////////

int ApplicationManager::getFigCount() const // get the number of selected figures
{
	return FigCount;
}

void ApplicationManager::saveAll(ofstream& OutFile) // save all figures in a file
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}
}


void ApplicationManager::DeleteFigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			delete FigList[i];
			FigList[i] = NULL;
			shiftFigList(i);
			FigCount--;
			break;
		}
	}
}

void ApplicationManager::shiftFigList(int _figCount)
{
	for (int j = _figCount; j < FigCount-1; j++)
	{
		FigList[j] = FigList[j + 1];
		
	}

}
/// <summary>
/// 
/// </summary>
void ApplicationManager::reset()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	pGUI->ClearDrawArea();
}

string ApplicationManager::GetRandomFigure(int& Count)const
{
	Count = 0;
	int random;
	string FigureName;
	if (FigCount != 0)
	{
		if (FigCount != 1)
		{
			// Generate a random index within the range of FigCount
			random = rand() % (FigCount);
			// Get the figure name associated with the randomly chosen figure
			FigureName = FigList[random]->GetFigName();
			// Count of the randomly chosen figure type in the FigList
			for (int i = 0; i < FigCount; i++)
			{
				if (FigList[random]->GetFigName() == FigList[i]->GetFigName())
				{

					Count++;
				}
			}
		}
		// Special case when there is only one figure in the list
		else
		{
			FigureName = FigList[0]->GetFigName();
			Count = 1;
		}
		return FigureName;
	}
	else
	{
		return "Empty";
	}
}




void ApplicationManager::bringBack(CFigure* r)
{
	CFigure* temp;

	// If a figure is found, return a pointer to it.
	// If this point (x,y) does not belong to any figure, return NULL
	for (int i = 0; i < FigCount; i++)
	{

		if (FigList[i] == r)
		{
			if (i == 0)
			{
				pGUI->PrintMessage("Selected Figure is aleready in Back");
				break;
			}
			// Temporary pointer will point at the selected figure
			temp = FigList[i];

			// Move the selected figure to the beginning of the figure list using the temporary pointer
			for (int j = i; j > 0; j--)
			{
				FigList[j] = FigList[j - 1];
			}
			FigList[0] = temp;

			break;
		}
	}

	return;
}




void ApplicationManager::bringFront(CFigure* r)
{
	CFigure* temp;

	// If a figure is found, return a pointer to it.
	// If this point (x, y) does not belong to any figure, return NULL
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == r)
		{
			if (i == FigCount - 1)
			{
				pGUI->PrintMessage("Selected Figure is aleready in Front");
				break;
			}
			// Temporary pointer will point at the selected figure
			temp = FigList[i];

			// Move the selected figure to the end of the figure list using the temporary pointer
			for (int j = i; j < FigCount - 1; j++)
			{
				FigList[j] = FigList[j + 1];
			}
			FigList[FigCount - 1] = temp;

			break;
		}
	}
	return;
}



//show all figure
void ApplicationManager::showAllFigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->show(true);
	}
}



color ApplicationManager::GetRandomColor(int& Count)const {
	Count = 0;
	int random;
	color FigureColor;
	bool flag = false;

	if (FigCount != 0) {
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->IsFigureFilled())
			{
				flag = true;
				break;
			}
		}
		if (flag == true) {
			if (FigCount != 1)
			{
				do {
					random = rand() % FigCount;
				} while (!FigList[random]->IsFigureFilled());

				FigureColor = FigList[random]->GetFigColor();

				for (int i = 0; i < FigCount; i++)
				{
					if (FigList[random]->GetFigColor() == FigList[i]->GetFigColor())
					{
						Count++;
					}
				}
			}
			else
			{
				FigureColor = FigList[0]->GetFigColor();
				Count = 1;
			}
			return FigureColor;
		}

	}

	return UI.BkGrndColor;
}


string ApplicationManager::GetRandomColorType(int& Count, color& FigColor) const
{
	Count = 0;
	int random;
	string Figure;
	bool flag = false;

	if (FigCount != 0)
	{
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->IsFigureFilled())
			{
				flag = true;
				break;
			}
		}
		if (flag = true) {
			if (FigCount != 1)
			{
				do {
					random = rand() % FigCount;
				} while (!FigList[random]->IsFigureFilled());
				FigColor = FigList[random]->GetFigColor(); //COLOR
				Figure = FigList[random]->GetFigName();	//TYPE
				for (int i = 0; i < FigCount; i++)
				{
					if (FigColor == FigList[i]->GetFigColor() && Figure == FigList[i]->GetFigName())
					{
						Count++;
					}
				}
			}
			else
			{
				FigColor = FigList[0]->GetFigColor();
				Figure = FigList[0]->GetFigName();
				Count = 1;

			}
		}

		return Figure;
	}
	else return "Empty";
}

// convert color to string

string ApplicationManager::colorToString(color c)
{
	string s = "(" + to_string(c.ucRed) + "," + to_string(c.ucGreen) + "," + to_string(c.ucBlue) + ")";
	return s;
}


color ApplicationManager::ConvertStringToColor(string x) const {
	if (x == "WHITE") return WHITE;
	if (x == "LIGHTYELLOW") return LIGHTYELLOW;
	if (x == "ORANGE") return ORANGE;
	if (x == "PINK") return PINK;
	if (x == "ROSE") return ROSE;
	if (x == "RED") return RED;
	if (x == "DARKRED") return DARKRED;
	if (x == "TAN") return TAN;
	if (x == "ROSYBROWN") return ROSYBROWN;
	if (x == "BROWN") return BROWN;
	if (x == "LAVENDER") return LAVENDER;
	if (x == "PURPLE") return PURPLE;
	if (x == "MEDIUMPURPLE") return MEDIUMPURPLE;
	if (x == "LIGHTGREEN") return LIGHTGREEN;
	if (x == "GREEN") return GREEN;
	if (x == "TEAL") return TEAL;
	if (x == "TURQUOISE") return TURQUOISE;
	if (x == "SKYBLUE") return SKYBLUE;
	if (x == "BLUE") return BLUE;
	if (x == "GRAY") return GRAY;
	if (x == "DARKGRAY") return DARKGRAY;
	if (x == "BLACK") return BLACK;
	if (x == "LIGHTGOLDENRODYELLOW") return LIGHTGOLDENRODYELLOW;
	return BLACK;
}
string ApplicationManager::ConvertColorToString(color x) const {

	if (x == WHITE) return "WHITE";
	if (x == LIGHTYELLOW) return "LIGHTYELLOW";
	if (x == ORANGE) return "ORANGE";
	if (x == PINK) return "PINK";
	if (x == ROSE) return "ROSE";
	if (x == RED) return "RED";
	if (x == DARKRED) return "DARKRED";
	if (x == TAN) return "TAN";
	if (x == ROSYBROWN) return "ROSYBROWN";
	if (x == BROWN) return "BROWN";


	if (x == BROWN) return "yellow";
	

	if (x == LAVENDER) return "LAVENDER";
	if (x == PURPLE) return "PURPLE";
	if (x == MEDIUMPURPLE) return "MEDIUMPURPLE";
	if (x == LIGHTGREEN) return "LIGHTGREEN";
	if (x == GREEN) return "GREEN";
	if (x == TEAL) return "TEAL";
	if (x == TURQUOISE) return "TURQUOISE";
	if (x == INDIGO) return "INDIGO";
	if (x == SKYBLUE) return "SKYBLUE";
	if (x == BLUE) return "BLUE";
	if (x == GRAY) return "GRAY";
	if (x == DARKGRAY) return "DARKGRAY";
	if (x == BLACK) return "BLACK";
	if (x == LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
	return "InValid";
}

string ApplicationManager::getColorName(color c)
{
	if ((c.ucBlue == BLACK.ucBlue) && (c.ucGreen == BLACK.ucGreen) && (c.ucRed == BLACK.ucRed))
		return "BLACK";
	if ((c.ucBlue == PINK.ucBlue) && (c.ucGreen == PINK.ucGreen) && (c.ucRed == PINK.ucRed))
		return "PINK";
	if ((c.ucBlue == LIGHTBLUE.ucBlue) && (c.ucGreen == LIGHTBLUE.ucGreen) && (c.ucRed == LIGHTBLUE.ucRed))
		return "LIGHTBLUE";
	if ((c.ucBlue == MAROON.ucBlue) && (c.ucGreen == MAROON.ucGreen) && (c.ucRed == MAROON.ucRed))
		return "MAROON";
	if ((c.ucBlue == ORANGE.ucBlue) && (c.ucGreen == ORANGE.ucGreen) && (c.ucRed == ORANGE.ucRed))
		return "ORANGE";
	if ((c.ucBlue == BLUE.ucBlue) && (c.ucGreen == BLUE.ucGreen) && (c.ucRed == BLUE.ucRed))
		return "BLUE";
	if ((c.ucBlue == WHITE.ucBlue) && (c.ucGreen == WHITE.ucGreen) && (c.ucRed == WHITE.ucRed))
		return "WHITE";
	if ((c.ucBlue == RED.ucBlue) && (c.ucGreen == RED.ucGreen) && (c.ucRed == RED.ucRed))
		return "RED";
	if ((c.ucBlue == YELLOW.ucBlue) && (c.ucGreen == YELLOW.ucGreen) && (c.ucRed == YELLOW.ucRed))
		return "YELLOW";
	if ((c.ucBlue == GREEN.ucBlue) && (c.ucGreen == GREEN.ucGreen) && (c.ucRed == GREEN.ucRed))
		return "GREEN";
		return"NO-FILL";
}