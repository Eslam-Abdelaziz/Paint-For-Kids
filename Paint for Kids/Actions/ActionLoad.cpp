#include "ActionLoad.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "../Figures/CSquare.h"
#include "../Figures/CElipse.h"
#include "../Figures/CHexagon.h"

ActionLoad::ActionLoad(ApplicationManager* pApp) : Action(pApp)
{}

void ActionLoad::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Enter file name to load from: ");
	string fileName = pGUI->GetSrting();

	if (fileName.length() == 0)
	{
		pGUI->PrintMessage("Loading is Canceled");
		return;
	}
	if (fileName.length() < 4 || fileName.substr(fileName.length() - 4) != ".txt")
	{
		fileName += ".txt";
	}

	ifstream inFile;
	inFile.open("Saved_Files/" + fileName, ios::in);
	if (!inFile.is_open())
	{
		pGUI->PrintMessage("Error: File not found");
		return;
	}

	// getting data
	string  drawColor, fillColor, bgColor;
	int figCount;
	inFile >> drawColor >> fillColor >> bgColor;
	inFile >> figCount;

	int figType = -1;
	CFigure* figure = nullptr;
	Point p;
	p.x = 0;
	p.y = 0;

	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;
	SqrGfxInfo.DrawClr = pGUI->getDrawColor();
	SqrGfxInfo.FillClr = pGUI->getFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	pManager->reset();//reset all figures

	for (int i = 0; i < figCount; i++)
	{
		inFile >> figType;
		switch (figType)
		{
		case ITM_SQUR:
			figure = new CSquare(p, 1, SqrGfxInfo);
			break;
		case ITM_ELPS:
			figure = new CElipse(p, p, SqrGfxInfo);
			break;
		case ITM_HEX:
			figure = new CHexagon(p, p, SqrGfxInfo);
			break;
		}
		figure->Load(inFile);
		pManager->AddFigure(figure);
	}
	inFile.close();
	pGUI->PrintMessage("Loading is done");
}