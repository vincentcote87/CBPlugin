/***************************************************************
 * Name:      IGGUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2018-03-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "IGGUIApp.h"

//(*AppHeaders
#include "IGGUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(IGGUIApp);

bool IGGUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	IGGUIDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
