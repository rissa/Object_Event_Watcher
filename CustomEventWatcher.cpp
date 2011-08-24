#include "StdAfx.h"
#include "CustomEventWatcher.h"

//Implementation of CCustomEventWatcher class
CCustomEventWatcher::CCustomEventWatcher()
{
}

CCustomEventWatcher::~CCustomEventWatcher()
{
}

void CCustomEventWatcher::OnAddObject(
	CRhinoDoc& doc,
	CRhinoObject& object
	)
{
	RhinoApp().Print("Event watcher caught OnAddObject\n");
	//This is a good place perform any logic that you see necessary in your plug-in
}

void CCustomEventWatcher::OnDeleteObject(
	CRhinoDoc& doc,
	CRhinoObject& object
	)
{
	RhinoApp().Print("Event watcher caught OnDeleteObject\n");
	//This is a good place perform any logic that you see necessary in your plug-in
}

void CCustomEventWatcher::OnReplaceObject(
	CRhinoDoc& doc,
	CRhinoObject& old_object,
	CRhinoObject& new_object
	)
{
	RhinoApp().Print("Event watcher caught OnReplaceObject\n");
	//This is a good place perform any logic that you see necessary in your plug-in
}

void CCustomEventWatcher::OnUnDeleteObject(
	CRhinoDoc& doc,
	CRhinoObject& object
	)
{
	RhinoApp().Print("Event watcher caught OnUnDeleteObject\n");
	//This is a good place perform any logic that you see necessary in your plug-in
}