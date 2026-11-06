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
    bhkWorldObject* FUN_006fa820();
    void FUN_004d9fa0(bool);
};
