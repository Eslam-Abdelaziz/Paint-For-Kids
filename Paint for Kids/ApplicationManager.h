#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include <vector>

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;  //Actual number of figures
	//Vector for drawn figures 
	//vector<CFigure*> FigList;
	vector<CFigure*> selectedfigure;  //selectedFigures array
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	//Pointers to Input and Output classes
	GUI* pGUI;	

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window	
	// Get the ID of Figure in Runtime (based on it's index in the figure vector)
	int GetFigureIndex(CFigure* x);
	// Get a refrence to the Figure list
	//vector<CFigure*>& GetFigtList();
	// Push selected figures into selectedfigure Vector
	void pushselectedfigure(CFigure* pFig);
	// Pop selected figures from selectedfigure Vector
	void popselectedfigure(CFigure* pFig);

	vector<CFigure*>& getselectedfigure();// Get selected figure


	// Move the selected figure to the beginning of the figure list 
	void ApplicationManager::bringBack(CFigure* r);
	// Move the selected figure to the end of the figure list 
	void ApplicationManager::bringFront(CFigure* r);

	//delete 
 	void DeleteFigure(); //// Action Delete Figures  
	void shiftFigList(int _figCount); // After delete figure shift elements and delete null

	// for Save & Load Actions
	int getFigCount() const; //Returns the number of figures
	void saveAll(ofstream& OutFile); //Saves all figures in a file	
	void reset(); //Resets the application and deletes all figures/
	


	void changeDrawColor(color);
	void changeFillColor(color);

	color GetRandomColor(int& Count)const;
	string GetRandomColorType(int& Count, color& FigColor) const;
	virtual color ConvertStringToColor(string s) const;  //convert from string to color type
	virtual string ConvertColorToString(color c) const; //Convert color to string 


	string ApplicationManager::getColorName(color c);

	string colorToString(color c);

	string GetRandomFigure(int& Count)const;
	void showAllFigure();


};

#endif