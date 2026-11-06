#ifndef BHKCOLLISIONOBJECT_H
#define BHKCOLLISIONOBJECT_H


#include "layout_support.h"
#include "../../include/bhkCollisionObject.h"
#include "../../include/bhkNiCollisionObject.h"
#include "bhkcollisionobject_decls.h"

// @fnv 0x0056d5b0
const NiRTTI* bhkCollisionObject::GetRTTI() const
{
    return &ms_kRTTI;
}

// @fnv 0x0043b610
bhkCollisionObject* bhkCollisionObject::GetFromNiAVObject(NiAVObject* object)
{
    const char* collision = reinterpret_cast<BGSBodyPart*>(object)->GetPartName();
    return reinterpret_cast<bhkCollisionObject*>(
        DynamicCastByRTTI(const_cast<NiRTTI*>(&ms_kRTTI), reinterpret_cast<NiNode*>(const_cast<char*>(collision))));
}

// @fnv 0x004b5a20
bhkCollisionObject* bhkCollisionObject::GetFromRigidBody(const hkpRigidBody* body)
{
    NiAVObject* collision = NiShader::DynamicCast(reinterpret_cast<NiAVObject*>(const_cast<hkpRigidBody*>(body)));
    return reinterpret_cast<bhkCollisionObject*>(
        DynamicCastByRTTI(const_cast<NiRTTI*>(&ms_kRTTI), reinterpret_cast<NiNode*>(collision)));
}

#endif
