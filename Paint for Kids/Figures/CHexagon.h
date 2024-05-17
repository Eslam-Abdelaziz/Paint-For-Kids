#ifndef CHexagon_H
#define CHexagon_H

#include "CFigure.h"
#include "..\ApplicationManager.h"
#include <fstream>
#include <iostream>

class CHexagon : public CFigure
{
private:
	int Height;
	int SideLen;
	Point TopLeft;
	Point BottomRight;
	int Area;
	
public:
	
	ApplicationManager* pManager = NULL;	//Actions needs AppMngr to do their job
	CHexagon(Point, Point, GfxInfo FigureGfxInfo);
	void printInfo(GUI* pGUI, int);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool isInside(int, int);	//whether the point is inside the figure or not
	virtual void Save(ofstream& OutFile);	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile);	//Load the figure parameters to the file
	virtual CHexagon* Clone() const;
	int resize(float);  //resize figure

	string GetFigName();
};

#endif
