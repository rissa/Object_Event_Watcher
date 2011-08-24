/////////////////////////////////////////////////////////////////////////////
// CPPObjectWatcherPlugIn.cpp : defines the initialization routines for the plug-in.
//

#include "StdAfx.h"
#include "CPPObjectWatcherPlugIn.h"

// The plug-in object must be constructed before any plug-in classes
// derived from CRhinoCommand. The #pragma init_seg(lib) ensures that
// this happens.

#pragma warning( push )
#pragma warning( disable : 4073 )
#pragma init_seg( lib )
#pragma warning( pop )

// Rhino plug-in declaration
RHINO_PLUG_IN_DECLARE

// Rhino plug-in name
// Provide a short, friendly name for this plug-in.
RHINO_PLUG_IN_NAME( L"CPPObjectWatcher" );

// Rhino plug-in id
// Provide a unique uuid for this plug-in
RHINO_PLUG_IN_ID( L"2A74C887-BC28-46C2-B7BB-D276C43EBC6E" );

// Rhino plug-in version
// Provide a version number string for this plug-in
RHINO_PLUG_IN_VERSION( __DATE__"  "__TIME__ )

// Rhino plug-in developer declarations
// TODO: fill in the following developer declarations with
// your company information. Note, all of these declarations
// must be present or your plug-in will not load.
//
// When completed, delete the following #error directive.
RHINO_PLUG_IN_DEVELOPER_ORGANIZATION( L"Robert McNeel & Associates" );
RHINO_PLUG_IN_DEVELOPER_ADDRESS( L"3670 Woodland Park Ave N, Seattle, WA 98103" );
RHINO_PLUG_IN_DEVELOPER_COUNTRY( L"USA" );
RHINO_PLUG_IN_DEVELOPER_PHONE( L"(206)545-6877" );
RHINO_PLUG_IN_DEVELOPER_FAX( L"(206) 545-7321" );
RHINO_PLUG_IN_DEVELOPER_EMAIL( L"support@mcneel.com" );
RHINO_PLUG_IN_DEVELOPER_WEBSITE( L"http://www.mcneel.com" );
RHINO_PLUG_IN_UPDATE_URL( L"http://www.mcneel.com/support" );

// The one and only CCPPObjectWatcherPlugIn object
static CCPPObjectWatcherPlugIn thePlugIn;

/////////////////////////////////////////////////////////////////////////////
// CCPPObjectWatcherPlugIn definition

CCPPObjectWatcherPlugIn& CPPObjectWatcherPlugIn()
{ 
  // Return a reference to the one and only CCPPObjectWatcherPlugIn object
  return thePlugIn; 
}

CCPPObjectWatcherPlugIn::CCPPObjectWatcherPlugIn()
{
  // Description:
  //   CCPPObjectWatcherPlugIn constructor. The constructor is called when the
  //   plug-in is loaded and "thePlugIn" is constructed. Once the plug-in
  //   is loaded, CCPPObjectWatcherPlugIn::OnLoadPlugIn() is called. The 
  //   constructor should be simple and solid. Do anything that might fail in
  //   CCPPObjectWatcherPlugIn::OnLoadPlugIn().

  // TODO: Add construction code here
  m_plugin_version = RhinoPlugInVersion();
}

CCPPObjectWatcherPlugIn::~CCPPObjectWatcherPlugIn()
{
  // Description:
  //   CCPPObjectWatcherPlugIn destructor. The destructor is called to destroy
  //   "thePlugIn" when the plug-in is unloaded. Immediately before the
  //   DLL is unloaded, CCPPObjectWatcherPlugIn::OnUnloadPlugin() is called. Do
  //   not do too much here. Be sure to clean up any memory you have allocated
  //   with onmalloc(), onrealloc(), oncalloc(), or onstrdup().

  // TODO: Add destruction code here
}

/////////////////////////////////////////////////////////////////////////////
// Required overrides

const wchar_t* CCPPObjectWatcherPlugIn::PlugInName() const
{
  // Description:
  //   Plug-in name display string.  This name is displayed by Rhino when
  //   loading the plug-in, in the plug-in help menu, and in the Rhino 
  //   interface for managing plug-ins.

  // TODO: Return a short, friendly name for the plug-in.
  return RhinoPlugInName();
}

const wchar_t* CCPPObjectWatcherPlugIn::PlugInVersion() const
{
  // Description:
  //   Plug-in version display string. This name is displayed by Rhino 
  //   when loading the plug-in and in the Rhino interface for managing
  //   plug-ins.

  // TODO: Return the version number of the plug-in.
  return m_plugin_version;
}

GUID CCPPObjectWatcherPlugIn::PlugInID() const
{
  // Description:
  //   Plug-in unique identifier. The identifier is used by Rhino to
  //   manage the plug-ins.

  // TODO: Return a unique identifier for the plug-in.
  // {2A74C887-BC28-46C2-B7BB-D276C43EBC6E}
  return ON_UuidFromString( RhinoPlugInId() );
}

BOOL CCPPObjectWatcherPlugIn::OnLoadPlugIn()
{
  // Description:
  //   Called after the plug-in is loaded and the constructor has been
  //   run. This is a good place to perform any significant initialization,
  //   license checking, and so on.  This function must return TRUE for
  //   the plug-in to continue to load.

  // TODO: Add plug-in initialization code here.
  return CRhinoUtilityPlugIn::OnLoadPlugIn();
}

void CCPPObjectWatcherPlugIn::OnUnloadPlugIn()
{
  // Description:
  //   Called when the plug-in is about to be unloaded.  After
  //   this function is called, the destructor will be called.

  // TODO: Add plug-in cleanup code here.

  CRhinoUtilityPlugIn::OnUnloadPlugIn();
}

/////////////////////////////////////////////////////////////////////////////
// Online help overrides

BOOL CCPPObjectWatcherPlugIn::AddToPlugInHelpMenu() const
{
  // Description:
  //   Return true to have your plug-in name added to the Rhino help menu.
  //   OnDisplayPlugInHelp will be called when to activate your plug-in help.

  return TRUE;
}

BOOL CCPPObjectWatcherPlugIn::OnDisplayPlugInHelp( HWND hWnd ) const
{
  // Description:
  //   Called when the user requests help about your plug-in.
  //   It should display a standard Windows Help file (.hlp or .chm).

  // TODO: Add support for online help here.
  return CRhinoUtilityPlugIn::OnDisplayPlugInHelp( hWnd );
}

