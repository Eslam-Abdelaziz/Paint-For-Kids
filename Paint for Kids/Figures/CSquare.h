#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;
	int length;
public:
	CSquare(Point, int, GfxInfo FigureGfxInfo);
	virtual bool isInside(int x, int y);
	virtual void DrawMe(GUI* pOut) const;
	void printInfo(GUI* pGUI, int);
	virtual void Save(ofstream& OutFile);	//Save the figure parameters to the file
	void Load(ifstream& Infile);	//Load the figure parameters to the file
	virtual CSquare* Clone() const;
	int resize(float);  //resize figure

	string GetFigName();
};

#endif