/////////////////////////////////////////////////////////////////////////////
// cmdCPPObjectWatcher.cpp : command file
//

#include "StdAfx.h"
#include "CPPObjectWatcherPlugIn.h"
#include "CustomEventWatcher.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN CPPObjectWatcher command
//

#pragma region CPPObjectWatcher command



// Do NOT put the definition of class CCommandCPPObjectWatcher in a header
// file.  There is only ONE instance of a CCommandCPPObjectWatcher class
// and that instance is the static theCPPObjectWatcherCommand that appears
// immediately below the class definition.

class CCommandCPPObjectWatcher : public CRhinoCommand
{
public:
  // The one and only instance of CCommandCPPObjectWatcher is created below.
  // No copy constructor or operator= is required.  Values of
  // member variables persist for the duration of the application.

  // CCommandCPPObjectWatcher::CCommandCPPObjectWatcher()
  // is called exactly once when static theCPPObjectWatcherCommand is created.
	CCommandCPPObjectWatcher() {}

  // CCommandCPPObjectWatcher::~CCommandCPPObjectWatcher()
  // is called exactly once when static theCPPObjectWatcherCommand is
  // destroyed.  The destructor should not make any calls to
  // the Rhino SDK.  If your command has persistent settings,
  // then override CRhinoCommand::SaveProfile and CRhinoCommand::LoadProfile.
  ~CCommandCPPObjectWatcher() {}

  // Returns a unique UUID for this command.
  // If you try to use an id that is already being used, then
  // your command will not work.  Use GUIDGEN.EXE to make unique UUID.
	UUID CommandUUID()
	{
		// {E326F0E7-A772-4F5C-AC7E-C9A49FC33469}
    static const GUID CPPObjectWatcherCommand_UUID =
    { 0xE326F0E7, 0xA772, 0x4F5C, { 0xAC, 0x7E, 0xC9, 0xA4, 0x9F, 0xC3, 0x34, 0x69 } };
    return CPPObjectWatcherCommand_UUID;
	}

  // Returns the English command name.
	const wchar_t* EnglishCommandName() { return L"CPPObjectWatcher"; }

  // Returns the localized command name.
	const wchar_t* LocalCommandName() { return L"CPPObjectWatcher"; }

  // Rhino calls RunCommand to run the command.
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );

  // Declare event watcher as member variable
	CCustomEventWatcher m_watcher;
	bool m_bRegistered;
};

// The one and only CCommandCPPObjectWatcher object.  
// Do NOT create any other instance of a CCommandCPPObjectWatcher class.
static class CCommandCPPObjectWatcher theCPPObjectWatcherCommand;

CRhinoCommand::result CCommandCPPObjectWatcher::RunCommand( const CRhinoCommandContext& context )
{
  // CCommandCPPObjectWatcher::RunCommand() is called when the user runs the "CPPObjectWatcher"
  // command or the "CPPObjectWatcher" command is run by a history operation.

	//Register the event watcher
  if( IDYES == RhinoMessageBox( L"Watch object events?",
                                L"Object Watcher",
                                MB_YESNO | MB_ICONQUESTION) 
                               )
  {
    if( !m_bRegistered )
    {
      m_bRegistered = true;
      m_watcher.Register();
    }
	//Enable the event watcher
    m_watcher.Enable( true );
  }
  else 
  {
	//Disable the event watcher
    m_watcher.Enable( false );
  }

  return CRhinoCommand::success;
}

#pragma endregion

//
// END CPPObjectWatcher command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
