// gamebryo2.2/corelibs/nimain/console/niavobject_console.cpp: NiAVObject (1 function)
#include "../../../../../include/NiAVObject.h"
#include "../../../../../include/NiCollisionObject.h"
// @fnv 0x00a68c60
void NiAVObject::UpdateWorldData(NiUpdateData& aUpdateData)
{
    NiCollisionObject* pCollisionObject = m_spCollisionObject.m_pObject;
    if (pCollisionObject)
        pCollisionObject->Unk_24(aUpdateData);
    else
        UpdateWorldLoc();
}
