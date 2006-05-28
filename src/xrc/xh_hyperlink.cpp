/////////////////////////////////////////////////////////////////////////////
// Name:        hyperlink.cpp
// Purpose:     Hyperlink control
// Author:      David Norris <danorris@gmail.com>
// Modified by: Ryan Norton, Francesco Montorsi
// Created:     04/02/2005
// RCS-ID:      $Id$
// Copyright:   (c) 2005 David Norris
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

//===========================================================================
// Declarations
//===========================================================================

//---------------------------------------------------------------------------
// Pre-compiled header stuff
//---------------------------------------------------------------------------

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "hyperlink.h"
#endif

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------

#include "wx/hyperlink.h"
#include "wx/utils.h" // wxLaunchDefaultBrowser
#include "wx/xrc/xmlres.h"
#include "wx/xrc/xh_hyperlink.h"

#if wxUSE_HYPERLINKCTRL

//===========================================================================
// Implementation
//===========================================================================

//---------------------------------------------------------------------------
// wxHyperlinkCtrlXmlHandler
//---------------------------------------------------------------------------

// Register with wxWindows' dynamic class subsystem.
IMPLEMENT_DYNAMIC_CLASS(wxHyperlinkCtrlXmlHandler, wxXmlResourceHandler)

wxHyperlinkCtrlXmlHandler::wxHyperlinkCtrlXmlHandler()
{
    AddWindowStyles();
}

wxObject *wxHyperlinkCtrlXmlHandler::DoCreateResource()
{
    XRC_MAKE_INSTANCE(control, wxHyperlinkCtrl)

    SetupWindow(control);
    control->Create(m_parentAsWindow, GetID(),
        GetParamValue(wxT("label")), GetParamValue(wxT("url")),
        GetPosition(), GetSize(), GetStyle());

    return control;
}

bool wxHyperlinkCtrlXmlHandler::CanHandle(wxXmlNode *node)
{
    return IsOfClass(node, wxT("wxHyperlinkCtrl"));
}

#endif // wxUSE_HYPERLINKCTRL
