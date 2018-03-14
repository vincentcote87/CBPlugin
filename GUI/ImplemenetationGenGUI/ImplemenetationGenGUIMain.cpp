/***************************************************************
 * Name:      ImplemenetationGenGUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2018-03-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "ImplemenetationGenGUIMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(ImplemenetationGenGUIFrame)
#include <wx/button.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ImplemenetationGenGUIFrame)
const long ImplemenetationGenGUIFrame::ID_RADIOBOX1 = wxNewId();
const long ImplemenetationGenGUIFrame::ID_STATICTEXT1 = wxNewId();
const long ImplemenetationGenGUIFrame::ID_DIRPICKERCTRL1 = wxNewId();
const long ImplemenetationGenGUIFrame::ID_STATICTEXT2 = wxNewId();
const long ImplemenetationGenGUIFrame::ID_DIRPICKERCTRL2 = wxNewId();
const long ImplemenetationGenGUIFrame::ID_STATICTEXT3 = wxNewId();
const long ImplemenetationGenGUIFrame::ID_DIRPICKERCTRL3 = wxNewId();
const long ImplemenetationGenGUIFrame::ID_MENUITEM1 = wxNewId();
const long ImplemenetationGenGUIFrame::idMenuAbout = wxNewId();
const long ImplemenetationGenGUIFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ImplemenetationGenGUIFrame,wxFrame)
    //(*EventTable(ImplemenetationGenGUIFrame)
    //*)
END_EVENT_TABLE()

ImplemenetationGenGUIFrame::ImplemenetationGenGUIFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ImplemenetationGenGUIFrame)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(399,324));
    FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(2, 2, 0, 0);
    wxString __wxRadioBoxChoices_1[2] =
    {
    	_("Default"),
    	_("Custom")
    };
    RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Label"), wxDefaultPosition, wxSize(88,115), 2, __wxRadioBoxChoices_1, 2, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
    FlexGridSizer2->Add(RadioBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(3, 2, 0, 0);
    HeaderText = new wxStaticText(this, ID_STATICTEXT1, _("Header Folder"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    HeaderText->Disable();
    FlexGridSizer3->Add(HeaderText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    HeaderSelect = new wxDirPickerCtrl(this, ID_DIRPICKERCTRL1, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDIRP_DIR_MUST_EXIST, wxDefaultValidator, _T("ID_DIRPICKERCTRL1"));
    HeaderSelect->Disable();
    FlexGridSizer3->Add(HeaderSelect, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SourceText = new wxStaticText(this, ID_STATICTEXT2, _("Source Folder"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    SourceText->Disable();
    FlexGridSizer3->Add(SourceText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SourceSelect = new wxDirPickerCtrl(this, ID_DIRPICKERCTRL2, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDIRP_DIR_MUST_EXIST, wxDefaultValidator, _T("ID_DIRPICKERCTRL2"));
    SourceSelect->Disable();
    FlexGridSizer3->Add(SourceSelect, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TestText = new wxStaticText(this, ID_STATICTEXT3, _("Test Folder"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    TestText->Disable();
    FlexGridSizer3->Add(TestText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TestSelect = new wxDirPickerCtrl(this, ID_DIRPICKERCTRL3, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDIRP_DIR_MUST_EXIST, wxDefaultValidator, _T("ID_DIRPICKERCTRL3"));
    TestSelect->Disable();
    FlexGridSizer3->Add(TestSelect, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonBox = new wxStdDialogButtonSizer();
    ButtonBox->AddButton(new wxButton(this, wxID_OK, wxEmptyString));
    ButtonBox->AddButton(new wxButton(this, wxID_CANCEL, wxEmptyString));
    ButtonBox->Realize();
    FlexGridSizer1->Add(ButtonBox, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    SetSizer(FlexGridSizer1);
    Layout();

    Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&ImplemenetationGenGUIFrame::OnRadioBox1Select1);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ImplemenetationGenGUIFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ImplemenetationGenGUIFrame::OnAbout);
    //*)
}

ImplemenetationGenGUIFrame::~ImplemenetationGenGUIFrame()
{
    //(*Destroy(ImplemenetationGenGUIFrame)
    //*)
}

void ImplemenetationGenGUIFrame::OnQuit(wxCommandEvent& event)
{
    event.Skip(TRUE);
}

void ImplemenetationGenGUIFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Implementation Generator"));
}

void ImplemenetationGenGUIFrame::OnRadioButton1Select(wxCommandEvent& event)
{
}

void ImplemenetationGenGUIFrame::OnButton1Click(wxCommandEvent& event)
{
    HeaderText->SetLabel(_("HAHASDF"));
    Layout();
}


void ImplemenetationGenGUIFrame::OnRadioButton1Select1(wxCommandEvent& event)
{
}

void ImplemenetationGenGUIFrame::OnButton1Click1(wxCommandEvent& event)
{
}


void ImplemenetationGenGUIFrame::OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event)
{

}

void ImplemenetationGenGUIFrame::OnRadioBox1Select1(wxCommandEvent& event)
{
    //RadioBox1->Show(,false);
    if(RadioBox1->GetSelection() == 0)
    {
        HeaderText->Enable(false);
        HeaderSelect->Enable(false);
        SourceText->Enable(false);
        SourceSelect->Enable(false);
        TestText->Enable(false);
        TestSelect->Enable(false);
    }
    else
    {
        HeaderText->Enable(true);
        HeaderSelect->Enable(true);
        SourceText->Enable(true);
        SourceSelect->Enable(true);
        TestSelect->Enable(true);
        TestText->Enable(true);
    }
    //HeaderText->SetLabel(RadioBox1->GetString(RadioBox1->GetSelection()));
    //HeaderText->Enable(true);
    Layout();
}


