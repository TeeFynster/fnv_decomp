#pragma once

#include "TESBoundObject.h"

class TESBoundAnimObject : public TESBoundObject
{
public:
    TESBoundAnimObject();
    virtual ~TESBoundAnimObject();

    virtual void Set3D(NiAVObject* object, bool debugPrint);

    NiNode* Create3DModel(TESObjectREFR* reference);
    void ReadTypedData(TESFile* file, void* buffer, unsigned short size);

    // Alternate names for slots already inherited from TESBoundObject.
    void __vslot_10();
    void v0();
    void vfn_00();
    void vfn_138();
    void vfn_13c();
    void vfn_140();
    void vfn_144();
    void vfn_148();
    void vfn_14c();
    void vfn_150(NiAVObject* object);
    void vfn_154();
    void vfn_158();
    void vfn_15c();
    void vfn_160();
    void vfn_164();
    void vfn_168();
    void vfn_16c();
    void vfn_170();
    void vfn_174();
};
