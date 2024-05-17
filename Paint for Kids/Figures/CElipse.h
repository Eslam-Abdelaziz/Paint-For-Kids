#ifndef CELIPSE_H
#define CELIPSE_H

#include "CFigure.h"

class CElipse : public CFigure
{
private:
	Point One;
	Point Two;

public:

	CElipse(Point p1, Point p2, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool isInside(int x, int y);
	void printInfo(GUI* pGUI, int);
	virtual void Save(ofstream& OutFile);	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile);	//Load the figure parameters to the file
	virtual CElipse* Clone() const;
	int resize(float);  //resize figure

	string GetFigName();

};

#endif