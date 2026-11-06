#pragma once

#include "NiObject.h"

class NiAVObject;
class NiUpdateData;

class NiCollisionObject : public NiObject
{
  public:
    NiCollisionObject();
    NiCollisionObject(NiAVObject*);
    NiCollisionObject(void*);

    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);
    virtual bool IsEqual(NiObject*) const;
    virtual void GetViewerStrings(NiViewerStringsArray*);
    virtual void AddViewerStrings(NiViewerStringsArray*);

    virtual void SetSceneObject(NiAVObject*);
    virtual void Unk_24(NiUpdateData&);
    virtual void Unk25();
    virtual void vf38();
    virtual void vf39();

    using NiObject::Clone;
    NiCollisionObject* Clone(CloningProcess&);
    NiCollisionObject* Construct();
    void Unk24(void* state);

    NiAVObject* m_pkSceneObject;
};
