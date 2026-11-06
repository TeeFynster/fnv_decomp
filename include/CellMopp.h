#pragma once

#include "NiRefObject.h"
#include "NiPoint3.h"
#include "NiQuaternion.h"
#include "NiPointer.h"
#include "NiTObjectArray.h"

class bhkRigidBody;
class bhkWorld;
namespace Local { class NiPoint3; }

class CellMopp : public NiRefObject
{
public:
    NiTObjectArray<NiPointer<bhkRigidBody> > m_kThirdFollowingStreamField;

    virtual ~CellMopp();

    void* __thiscall Destroy(unsigned int flags);
    void Remove();
    void Kill();
    int LookupFirstFormID();
    bool IsCreated();
    bool PlaceGridObjects(bhkWorld* p1, const NiPoint3* pPos, int p3);
    void PlaceGridObjects(bhkWorld*, const Local::NiPoint3&, const NiQuaternion&);
};
