#include "DrowColor.h"
#include "..\GUI\GUI.h"
#include "..\ApplicationManager.h"


DrowColor::DrowColor(ApplicationManager* AppMgr) :Action(AppMgr) {

}
void DrowColor::Execute() {
    GUI* g = pManager->GetGUI();
    Point P;
    g->PrintMessage("Please Choose color to drow with");
    g->GetPointClicked(P.x, P.y);
    if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == 6) {
        UI.DrawColor = g->pWind->GetColor(P.x, P.y);
        g->ClearStatusBar();
        pManager->changeDrawColor(g->pWind->GetColor(P.x, P.y));
    }
    else
    {
        g->PrintMessage("please pic color from tool colors");
    }
    
}


