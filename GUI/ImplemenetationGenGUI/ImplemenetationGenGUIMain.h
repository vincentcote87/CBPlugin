/***************************************************************
 * Name:      ImplemenetationGenGUIMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2018-03-14
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef IMPLEMENETATIONGENGUIMAIN_H
#define IMPLEMENETATIONGENGUIMAIN_H

//(*Headers(ImplemenetationGenGUIFrame)
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)

class ImplemenetationGenGUIFrame: public wxFrame
{
    public:

        ImplemenetationGenGUIFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ImplemenetationGenGUIFrame();
        bool useSourceDefault = true;
        bool useHeaderDefault = true;
        bool useTestDefault = true;
        bool canGrab = false;
        wxString* getSourceDir();
        wxString* getTestDir();
        wxString* getHeaderDir();

    private:

        //(*Handlers(ImplemenetationGenGUIFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnRadioButton1Select(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnRadioButton2Select(wxCommandEvent& event);
        void OnRadioButton1Select1(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnRadioBox1Select(wxCommandEvent& event);
        void OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event);
        void OnRadioBox1Select1(wxCommandEvent& event);
        void OnSourceSelectDirChanged(wxFileDirPickerEvent& event);
        void OnTestSelectDirChanged(wxFileDirPickerEvent& event);
        void OnHeaderSelectDirChanged(wxFileDirPickerEvent& event);
        void OnOKClick2(wxCommandEvent& event);
        //*)

        //(*Identifiers(ImplemenetationGenGUIFrame)
        static const long ID_RADIOBOX1;
        static const long ID_STATICTEXT1;
        static const long ID_DIRPICKERCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_DIRPICKERCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_DIRPICKERCTRL3;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(ImplemenetationGenGUIFrame)
        wxBoxSizer* BoxSizer1;
        wxButton* Button1;
        wxButton* Button2;
        wxDirPickerCtrl* HeaderSelect;
        wxDirPickerCtrl* SourceSelect;
        wxDirPickerCtrl* TestSelect;
        wxFileDialog* FileDialog1;
        wxRadioBox* RadioBox1;
        wxStaticText* HeaderText;
        wxStaticText* SourceText;
        wxStaticText* TestText;
        wxStatusBar* StatusBar1;
        //*)
        wxString* Header;
        wxString* Source;
        wxString* Test;
        DECLARE_EVENT_TABLE()
};

#endif // IMPLEMENETATIONGENGUIMAIN_H
