#pragma once

#include "bhkNiCollisionObject.h"
#include "NiRTTI.h"

class NiAVObject;
struct hkpRigidBody;
class bhkWorldObject;
class bhkWorldObjectV;

class bhkCollisionObject : public bhkNiCollisionObject
{
  public:
    virtual ~bhkCollisionObject();
    virtual const NiRTTI* GetRTTI() const;

    static const NiRTTI ms_kRTTI;

    static bhkCollisionObject* GetFromNiAVObject(NiAVObject* object);
    static bhkCollisionObject* GetFromRigidBody(const hkpRigidBody* body);
    static NiObject* CreateObject();

    bhkWorldObjectV* GetWorldObject();
    bhkWorldObject* bhkNiCollisionObject_GetWorldObject();
    void bhkNiCollisionObject_SetReset(bool);
};
