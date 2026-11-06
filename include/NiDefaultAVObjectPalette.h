#pragma once

#include "NiAVObjectPalette.h"
#include "NiTFixedStringMap_NiAVObject___.h"

class NiAVObject;
class NiFixedString;
class NiStream;
class CloningProcess;

class NiDefaultAVObjectPalette : public NiAVObjectPalette
{
public:
    virtual void LoadBinary(NiStream&);
    virtual void ProcessClone(CloningProcess&);
    virtual NiAVObject* FindAVObject(const NiFixedString&);
    virtual void AddNamedAVObject(const NiFixedString&, NiAVObject*);
    virtual void vf37(NiAVObject*);
    virtual NiAVObject* vf38();

    void BuildPalette();
    void ProcessCloneBase(CloningProcess&);

    union
    {
        NiTFixedStringMap_NiAVObject___ m_kObjectMap;
        unsigned char unk08[0x10];
    };
    NiAVObject* m_pkScene;
};
