#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "SaveAction.h"
#include <fstream>
#include <iostream>
#include <iomanip>

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{
}

template<typename T> void SaveAction::saveElement(ofstream& outFile, T content, const int& width, const char& separator)
{
	outFile << left << setw(width) << setfill(separator) << content;
}

string SaveAction::colorToString(color c)
{
	string s = "(" + to_string(c.ucRed) + "," + to_string(c.ucGreen) + "," + to_string(c.ucBlue) + ")";
	return s;
}

void SaveAction::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	bool notPrevious = true;
	ofstream outFile;
	string fileName;

	do {
		if (notPrevious)
		{
			pGUI->PrintMessage("Enter file name to save to: ");
			notPrevious = false;
		}
		else
		{
			pGUI->PrintMessage("File name is invalid please try again: ");
		}

		//get file name from user
		fileName = pGUI->GetSrting();

		//check if it is valid.
		if (fileName.length() == 0)
		{
			pGUI->PrintMessage("Saving is Canceled");
			return;
		}
		else if (fileName.length() <= 4 || fileName.substr(fileName.length() - 4) != ".txt")
			fileName += ".txt";

		//open file and save all figures
		outFile.open("Saved_Files/" + fileName, ios::out | ios::trunc);

	} while (!outFile.is_open());

	if (outFile.is_open())
	{
		color drawing_color = pGUI->getDrawColor();
		string drawingcolor = colorToString(drawing_color);
		color filling_color = pGUI->getFillColor();
		string fillingcolor = colorToString(filling_color);
		color background_color = pGUI->getBackgroundColor();
		string backgroundcolor = colorToString(background_color);

		//save drawing, filling and background colors to file
		saveElement(outFile, drawingcolor, 15, ' ');
		saveElement(outFile, fillingcolor, 15, ' ');
		saveElement(outFile, backgroundcolor, 15, ' ');
		outFile << endl;

		//save number of figures
		saveElement(outFile, pManager->getFigCount(), 6, ' ');

		// save all figures
		pManager->saveAll(outFile);
		pGUI->PrintMessage("File Saved Successfully");
	}
	else
	{
		pGUI->PrintMessage("Error: Cannot open file to save");
	}
}

