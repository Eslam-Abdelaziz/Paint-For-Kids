#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
color CFigure::GetFigColor()
{
	return FigGfxInfo.FillClr;
}


bool CFigure::IsFigureFilled()
{
	return FigGfxInfo.isFilled;
}

color CFigure::stringToColor(string s)
{
	int r, g, b;
	int i = 1;
	string temp = "";
	while (s[i] != ',')
	{
		temp += s[i];
		i++;
	}
	r = stoi(temp);
	i++;
	temp = "";
	while (s[i] != ',')
	{
		temp += s[i];
		i++;
	}
	g = stoi(temp);
	i++;
	temp = "";
	while (s[i] != ')')
	{
		temp += s[i];
		i++;
	}
	b = stoi(temp);
	color c;
	c.ucRed = r;
	c.ucGreen = g;
	c.ucBlue = b;
	return c;
}

void CFigure::setDrawandFillClr(string drawColorString, string fill) // set the draw and fill color of the figure
{
	ChngDrawClr(stringToColor(drawColorString));

	if (fill == "NO_FILL") {
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = NULL;
	}
	else
	{
		ChngFillClr(stringToColor(fill));// Convert the fill to a color and assign it to FigGfxInfo.FillClr
	}
}

int CFigure::getHidden()
{
	return  !Shown;
}

void CFigure::show(bool s)
{
	Shown = s;

}

bool CFigure::isShown() {
	return Shown;
}
