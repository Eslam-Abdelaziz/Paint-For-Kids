#include "BKColor.h"
#include "..\GUI\GUI.h"
#include "..\ApplicationManager.h"


BKColor::BKColor(ApplicationManager* AppMgr) :Action(AppMgr) {

}
void BKColor::Execute() {
    GUI* g = pManager->GetGUI();
    Point P;
    g->PrintMessage("Please Choose color to Back ground ");
    g->GetPointClicked(P.x, P.y);
    if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == 6) {
        UI.BkGrndColor = g->pWind->GetColor(P.x, P.y);
        g->ClearStatusBar();
        g->ClearDrawArea();

    }
    else
    {
        g->PrintMessage("please pic color from tool colors");
    }

}


