/***************************************************************
 * Name:      IGGUIMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2018-03-14
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef IGGUIMAIN_H
#define IGGUIMAIN_H

//(*Headers(IGGUIDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class IGGUIDialog: public wxDialog
{
    public:

        IGGUIDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~IGGUIDialog();

    private:

        //(*Handlers(IGGUIDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(IGGUIDialog)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(IGGUIDialog)
        wxBoxSizer* BoxSizer1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button1;
        wxButton* Button2;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // IGGUIMAIN_H
