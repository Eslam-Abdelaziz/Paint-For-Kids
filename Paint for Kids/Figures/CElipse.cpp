#include "CElipse.h"


//CElipse::CElipse() {}
CElipse::CElipse(Point p1, Point p2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	One = p1;
	Two = p2;
}

void CElipse::DrawMe(GUI* pGUI) const
{
	// Call Output::DrawRect to draw a Square on the screen
	pGUI->DrawElipse(One, Two, FigGfxInfo, Selected);
}
bool CElipse::isInside(int x, int y) {
	double height = abs(Two.x - One.x) / 2;
	double width = abs(Two.y - One.y) / 2;
	double x0 = (Two.x + One.x) / 2;
	double y0 = (Two.y + One.y) / 2;
	return ((pow((x - x0) / height, 2) + pow((y - y0) / width, 2)) <= 1);
}

void CElipse::printInfo(GUI* pGUI, int x)
{
	pGUI->ClearStatusBar();
	Point center;
	center.x = 0.5 * (Two.x + One.x);
	center.y = 0.5 * (Two.y + One.y);
	float height = abs(Two.x - One.x) / 2;
	float width = abs(Two.y - One.y) / 2;
	stringstream msg;
	msg << "ID:" << x + 1 << " Ellipse , Center (" << center.x << " , " << center.y << " , Area:" << 3.14 * height * width << ")";
	pGUI->PrintMessage(msg.str());
}

void CElipse::Save(ofstream& OutFile)	//Save the figure parameters to the file
{
	OutFile << endl << ITM_ELPS << "\t" << ID << "\t" << One.x << "\t" << One.y << "\t" << Two.x << "\t" <<Two.y << "\t";
	OutFile << "(" << (int)FigGfxInfo.DrawClr.ucRed << "," << (int)FigGfxInfo.DrawClr.ucGreen << "," << (int)FigGfxInfo.DrawClr.ucBlue << ")" << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << "(" << (int)FigGfxInfo.FillClr.ucRed << "," << (int)FigGfxInfo.FillClr.ucGreen << "," << (int)FigGfxInfo.FillClr.ucBlue << ")" << endl;
	else
		OutFile << "NO_FILL";
}
void CElipse::Load(ifstream& Infile)	//Load the figure parameters to the file
{
	// Declare variables for x, y, len, drawColorString, and fill
	string drawColorString, fill;

	// Read values from the file into object data members
	Infile >> ID;
	Infile >> One.x;
	Infile >> One.y;
	Infile >> Two.x;
	Infile >> Two.y;
	Infile >> drawColorString >> fill;//read colors from file into strings first to convert to color later

	setDrawandFillClr(drawColorString, fill); //set the draw and fill colors
}
CElipse* CElipse::Clone() const
{
	return new CElipse(*this);
}


int CElipse::resize(float resizeFactor)
{
	//Calculate the center of the ellipse
	Point Center;
	Center.x = (One.x + Two.x) / 2;
	Center.y = (One.y + Two.y) / 2;

	//Calculate the horizontal and vertical radii of the ellipse
	int horizontal = abs(One.x - Center.x);
	int vertical = abs(One.y - Center.y);



	if (resizeFactor > 1)
	{
		if ((Center.x - horizontal * resizeFactor) < 0 || (Center.x + horizontal * resizeFactor) > UI.width) {
			return -1;
		}
	}
	//Check if resizing would go beyond the specified boundaries
	if ((Center.y - (vertical * resizeFactor) > UI.height - UI.StatusBarHeight) || (Center.y - (vertical * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}
	if ((Center.y + (vertical * resizeFactor) > UI.height - UI.StatusBarHeight) || (Center.y + (vertical * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}

	// Check if the shape becomes too small
	if (horizontal * resizeFactor < 10 || vertical * resizeFactor < 10) {
		return -2;  // Return an error code if the shape becomes too small
	}

	//Perform the resizing

	else {
		One.x = Center.x + horizontal * resizeFactor;
		Two.x = Center.x - horizontal * resizeFactor;

		One.y = Center.y + vertical * resizeFactor;
		Two.y = Center.y - vertical * resizeFactor;
	}



	return 1;
}

string CElipse::GetFigName() {
	return "Ellipse";
}
