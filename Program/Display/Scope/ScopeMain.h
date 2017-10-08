/***************************************************************
 * Name:      ScopeMain.h
 * Purpose:   Defines Application Frame
 * Author:    Prakash Gautam (pranphy@gmail.com)
 * Created:   2014-08-17
 * Copyright: Prakash Gautam (http://pranphy.wordpress.com/)
 * License:
 **************************************************************/

#ifndef SCOPEMAIN_H
#define SCOPEMAIN_H

//(*Headers(ScopeFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class ScopeFrame: public wxFrame
{
    public:

        ScopeFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ScopeFrame();

    private:

        //(*Handlers(ScopeFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(ScopeFrame)
        static const long ID_STATICTEXT1;
        static const long ID_SLIDER1;
        static const long ID_PANEL2;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(ScopeFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxStaticText* StaticText1;
        wxPanel* Panel2;
        wxSlider* Slider1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SCOPEMAIN_H
