#include "StdAfx.h"

//Declaration of CCustomEventWatcher class

/*
The MRhinoEventWatcher class has virtual functions that you can override in a subclass
to be notified when events occur in Rhino.
The CPPObjectWatcher creates an instance of this class and enables/disables it

NOTE!!!!!
The class is named an event WATCHER for a reason; it should only watch and never change
the objects that are in the rhino database. This will mess up things like the undo stack.
*/
class CCustomEventWatcher : public CRhinoEventWatcher
{
public:
  CCustomEventWatcher();
  ~CCustomEventWatcher();
 
  // override virtual function when add object
  void OnAddObject(
		CRhinoDoc& doc,
		CRhinoObject& object
		);

  // override virtual function when delete object
  void OnDeleteObject(
		CRhinoDoc& doc,
		CRhinoObject& object
		);

  // override virtual function when replace object
  void OnReplaceObject(
		CRhinoDoc& doc,
		CRhinoObject& old_object,
		CRhinoObject& new_object
		);

  // override virtual function when undelete object
  void OnUnDeleteObject(
		CRhinoDoc& doc,
		CRhinoObject& object
		);
};