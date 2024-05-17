#include "CHexagon.h"


CHexagon::CHexagon(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	TopLeft = P1;
	BottomRight = P2;
	Height = abs(P2.y - P1.y);
	SideLen = abs(P2.x - P1.x);
}

void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawHexagon(TopLeft, BottomRight, FigGfxInfo, Selected);
}
/*
bool CHexagon::isInside(int x, int y)
{
	Point vertices[6];
	vertices[0] = TopLeft;
	vertices[1] = Point((int)(TopLeft.x + 0.25 * (BottomRight.x - TopLeft.x)), (int)(TopLeft.y));
	vertices[2] = Point(static_cast<int>(BottomRight.x - 0.25 * (BottomRight.x - TopLeft.x)), static_cast<int>(TopLeft.y));
	vertices[3] = BottomRight;
	vertices[4] = Point(static_cast<int>(BottomRight.x - 0.25 * (BottomRight.x - TopLeft.x)), static_cast<int>(BottomRight.y));
	vertices[5] = Point(static_cast<int>(TopLeft.x + 0.25 * (BottomRight.x - TopLeft.x)), static_cast<int>(BottomRight.y));

	int count = 0;

	for (int i = 0; i < 6; i++)
	{
		int x1 = vertices[i].x;
		int y1 = vertices[i].y;
		int x2 = vertices[(i + 1) % 6].x;
		int y2 = vertices[(i + 1) % 6].y;

		if (((y1 <= y && y < y2) || (y2 <= y && y < y1)) &&
			x < (x2 - x1) * (y - y1) / (y2 - y1) + x1)
		{
			count++;
		}
	}

	return (count % 2 == 1);
}
*/

bool CHexagon::isInside(int x, int y) {
	int lengthx = abs(TopLeft.x - BottomRight.x);
	int lengthy = abs(TopLeft.y - BottomRight.y);

	int xCenter = (BottomRight.x + TopLeft.x) / 2;
	int yCenter = (BottomRight.y + TopLeft.y) / 2;

	int arrx[6] = { TopLeft.x,TopLeft.x + lengthx, TopLeft.x + 1.5 * lengthx,TopLeft.x + lengthx,TopLeft.x,TopLeft.x - 0.5 * lengthx };
	int arry[6] = { TopLeft.y,TopLeft.y,TopLeft.y + 0.5 * lengthy,TopLeft.y + lengthy,TopLeft.y + lengthy,TopLeft.y + 0.5 * lengthy };

	float areax1 = (0.5) * abs(x * (arry[0] - arry[1]) + arrx[0] * (arry[1] - y) + arrx[1] * (y - arry[0]));
	float areax2 = (0.5) * abs(x * (arry[1] - arry[2]) + arrx[1] * (arry[2] - y) + arrx[2] * (y - arry[1]));
	float areax3 = (0.5) * abs(x * (arry[2] - arry[3]) + arrx[2] * (arry[3] - y) + arrx[3] * (y - arry[2]));
	float areax4 = (0.5) * abs(x * (arry[3] - arry[4]) + arrx[3] * (arry[4] - y) + arrx[4] * (y - arry[3]));
	float areax5 = (0.5) * abs(x * (arry[4] - arry[5]) + arrx[4] * (arry[5] - y) + arrx[5] * (y - arry[4]));
	float areax6 = (0.5) * abs(x * (arry[5] - arry[0]) + arrx[5] * (arry[0] - y) + arrx[0] * (y - arry[5]));
	float areax = areax1 + areax2 + areax3 + areax4 + areax5 + areax6;

	float totalarea = lengthy * lengthx * 1.5;
	Area = totalarea;
	if (areax == totalarea)
		return true;
	else
		return false;
}



void CHexagon::Save(ofstream& OutFile)	//Save the figure parameters to the file
{
	OutFile << endl << ITM_HEX << "\t" << ID << "\t" << TopLeft.x << "\t" << TopLeft.y << "\t" << BottomRight.x << "\t" << BottomRight.y << "\t";
	OutFile << "(" << (int)FigGfxInfo.DrawClr.ucRed << "," << (int)FigGfxInfo.DrawClr.ucGreen << "," << (int)FigGfxInfo.DrawClr.ucBlue << ")" << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << "(" << (int)FigGfxInfo.FillClr.ucRed << "," << (int)FigGfxInfo.FillClr.ucGreen << "," << (int)FigGfxInfo.FillClr.ucBlue << ")" << endl;
	else
		OutFile << "NO_FILL";
}
void CHexagon::printInfo(GUI* pGUI, int x)
{
	pGUI->ClearStatusBar();

	stringstream msg;
	msg << "ID:" << x + 1 << " Hexagon" ", Side Length:" << SideLen << " , Height:" << Height << " , Area:" << ((3 * sqrt(3)) / 2) * pow(SideLen, 2);
	pGUI->PrintMessage(msg.str());
}
void CHexagon::Load(ifstream& Infile)	//Load the figure parameters to the file
{
    // Declare variables for x, y, len, drawColorString, and fill
    string drawColorString, fill;
    // Read values from the file into object data members
    Infile >> ID;
    Infile >> TopLeft.x;
    Infile >> TopLeft.y;
    Infile >> BottomRight.x;
    Infile >> BottomRight.y;
    Infile >> drawColorString >> fill;//read colors from file into strings first to convert to color later

    setDrawandFillClr(drawColorString, fill); //set the draw and fill colors
}
CHexagon* CHexagon::Clone() const
{
    return new CHexagon(*this); // Assuming you have a copy constructor for CEllipse
}



int CHexagon::resize(float resizeFactor)
{
	// Check if the new size 
	int minSize = 30;
	if (Height < minSize || SideLen < minSize) {
    // Set the shape to the minimum size
    Height = minSize;
    SideLen = minSize;
    return -2;
}    
	// Calculate the center of the hexagon
	Point center;
	int horiaontalDiff = SideLen / 2;
	int verticalDiff = Height / 2;
	center.x = TopLeft.x + horiaontalDiff;
	center.y = TopLeft.y + verticalDiff;
	// Check if the resized hexagon goes outside the UI boundaries
	if ((center.y - (verticalDiff * resizeFactor) > UI.height - UI.StatusBarHeight) || (center.y - (verticalDiff * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}
	if ((center.y + (verticalDiff * resizeFactor) > UI.height - UI.StatusBarHeight) || (center.y + (verticalDiff * resizeFactor) < UI.ToolBarHeight)) {
		return -1;
	}
	// Perform the resize operation

	TopLeft.x = center.x - (horiaontalDiff * resizeFactor);
	TopLeft.y = center.y - (verticalDiff * resizeFactor);
	BottomRight.x = center.x + (horiaontalDiff * resizeFactor);
	BottomRight.y = center.y + (verticalDiff * resizeFactor);
	Height *= resizeFactor;
	SideLen *= resizeFactor;
	return 1;
}

string CHexagon::GetFigName() {
    return "Hexagon";
}