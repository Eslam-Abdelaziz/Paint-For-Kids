#include "CSquare.h"

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}


void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
}
bool CSquare::isInside(int x, int y) {
	int x1 = TopLeftCorner.x;
	int y1 = TopLeftCorner.y;
	int x2 = TopLeftCorner.x + length;
	int y2 = TopLeftCorner.y + length;
	return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}
void CSquare::Save(ofstream& OutFile)
{
	OutFile << endl << ITM_SQUR << "\t" << ID << "\t" << TopLeftCorner.x << "\t" << TopLeftCorner.y << "\t" << length << "\t";
	OutFile << "(" << (int)FigGfxInfo.DrawClr.ucRed << "," << (int)FigGfxInfo.DrawClr.ucGreen << "," << (int)FigGfxInfo.DrawClr.ucBlue << ")" << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << "(" << (int)FigGfxInfo.FillClr.ucRed << "," << (int)FigGfxInfo.FillClr.ucGreen << "," << (int)FigGfxInfo.FillClr.ucBlue << ")" << endl;
	else
		OutFile << "NO_FILL";
}
void CSquare::printInfo(GUI* pGUI, int x)
{
	pGUI->ClearStatusBar();
	stringstream msg;
	msg << "ID:" << x + 1 << " Square , P1 (" << TopLeftCorner.x << " , " << (TopLeftCorner.y) << ") , P2 (" << TopLeftCorner.x + length << " , " << TopLeftCorner.y + length << " , Area:" << pow(length, 2);
	pGUI->PrintMessage(msg.str());
}
void CSquare::Load(ifstream& Infile)
{
	// Declare variables for x, y, len, drawColorString, and fill
	int x, y, len;
	string drawColorString, fill;

	// Read values from the file into object data members
	Infile >> ID;
	Infile >> TopLeftCorner.x;
	Infile >> TopLeftCorner.y;
	Infile >> length;
	Infile >> drawColorString >> fill;//read colors from file into strings first to convert to color later

	setDrawandFillClr(drawColorString, fill); //set the draw and fill colors
}
CSquare* CSquare::Clone() const {
	return new CSquare(*this);
}


int CSquare::resize(float resizeFactor)
{
	//check size of shape
	if (length < 100 && resizeFactor < 1)
	{
		return -2;
	}
	//Calculate the center of the square
	Point Center;
	int sideDisplacement = length / 2;
	Center.x = (TopLeftCorner.x + sideDisplacement);
	Center.y = (TopLeftCorner.y + sideDisplacement);
	//Check if resizing would go beyond the specified vertical boundaries
	if ((Center.y - (sideDisplacement * resizeFactor) > UI.height - UI.StatusBarHeight) || (Center.y - (sideDisplacement * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}
	if ((Center.y + (sideDisplacement * resizeFactor) > UI.height - UI.StatusBarHeight) || (Center.y + (sideDisplacement * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}
	//Perform the resizing
	TopLeftCorner.x = Center.x - sideDisplacement * resizeFactor;
	TopLeftCorner.y = Center.y - sideDisplacement * resizeFactor;


	length *= resizeFactor;
	return 1;
}

string CSquare::GetFigName() {
	return "Square";
}