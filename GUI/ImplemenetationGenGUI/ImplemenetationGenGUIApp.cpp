/***************************************************************
 * Name:      ImplemenetationGenGUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2018-03-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "ImplemenetationGenGUIApp.h"

//(*AppHeaders
#include "ImplemenetationGenGUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ImplemenetationGenGUIApp);

bool ImplemenetationGenGUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ImplemenetationGenGUIFrame* Frame = new ImplemenetationGenGUIFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
