#include "FillColor.h"
#include "..\GUI\GUI.h"
#include "..\ApplicationManager.h"


FillColor::FillColor(ApplicationManager* AppMgr) :Action(AppMgr) {

}
void FillColor::Execute() {
    GUI* g = pManager->GetGUI();
    Point P;
    g->PrintMessage("Please Choose color to fill with");
    g->GetPointClicked(P.x, P.y);
    if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == 6) {
        UI.FillColor = g->pWind->GetColor(P.x, P.y);
        g->setFillColor(g->pWind->GetColor(P.x, P.y));
        g->ClearStatusBar();
        pManager->changeFillColor(g->pWind->GetColor(P.x, P.y));
    }
    else
    {
        g->PrintMessage("please pic color from tool colors");
    }

}


