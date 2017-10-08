/***************************************************************
 * Name:      ScopeApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Prakash Gautam (pranphy@gmail.com)
 * Created:   2014-08-17
 * Copyright: Prakash Gautam (http://pranphy.wordpress.com/)
 * License:
 **************************************************************/

#include "ScopeApp.h"

//(*AppHeaders
#include "ScopeMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ScopeApp);

bool ScopeApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    ScopeFrame* Frame = new ScopeFrame(0);
    Frame->Show();
    SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
