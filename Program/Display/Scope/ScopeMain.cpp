/***************************************************************
 * Name:      ScopeMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Prakash Gautam (pranphy@gmail.com)
 * Created:   2014-08-17
 * Copyright: Prakash Gautam (http://pranphy.wordpress.com/)
 * License:
 **************************************************************/

#include "ScopeMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(ScopeFrame)
#include <wx/string.h>
#include <wx/intl.h>
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

//(*IdInit(ScopeFrame)
const long ScopeFrame::ID_STATICTEXT1 = wxNewId();
const long ScopeFrame::ID_SLIDER1 = wxNewId();
const long ScopeFrame::ID_PANEL2 = wxNewId();
const long ScopeFrame::ID_PANEL1 = wxNewId();
const long ScopeFrame::idMenuQuit = wxNewId();
const long ScopeFrame::idMenuAbout = wxNewId();
const long ScopeFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ScopeFrame,wxFrame)
    //(*EventTable(ScopeFrame)
    //*)
END_EVENT_TABLE()

ScopeFrame::ScopeFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ScopeFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(581,450));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,16), wxSize(600,434), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1 = new wxFlexGridSizer(2, 2, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(5, 2, 0, 0);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("XPOS"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Slider1 = new wxSlider(Panel1, ID_SLIDER1, 0, 0, 100, wxDefaultPosition, wxSize(143,27), 0, wxDefaultValidator, _T("ID_SLIDER1"));
    FlexGridSizer2->Add(Slider1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxSize(351,265), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->SetBackgroundColour(wxColour(55,168,28));
    FlexGridSizer1->Add(Panel2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    SetSizer(FlexGridSizer1);
    Layout();
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ScopeFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ScopeFrame::OnAbout);
    //*)
}

ScopeFrame::~ScopeFrame()
{
    //(*Destroy(ScopeFrame)
    //*)
}

void ScopeFrame::OnQuit(wxCommandEvent& event)
{
    Destroy();
    Close();
}

void ScopeFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
