#pragma once

#include "NiBoundingVolume.h"
#include "NiTexturingProperty.h"

class NiObject;

class NiUnionBV : public NiBoundingVolume
{
public:
    NiTPrimitiveArray<NiBoundingVolume*> m_kBoundingVolumes;
    void* m_pkEntry;

    NiUnionBV() throw();

    virtual void LoadBinary(NiStream& kStream);
    virtual void __thiscall SaveBinary(NiStream& kStream);
    virtual ~NiUnionBV();
    virtual int F3() const;
    virtual void v10();
    virtual void v5(NiBoundingVolume*, void*);
    virtual NiBoundingVolume* v6();
    virtual NiBoundingVolume* Clone();
    virtual void Copy(const NiBoundingVolume& kABV);
    virtual int IsEqual(const NiBoundingVolume& kABV) const;
    virtual bool IsDifferent(NiBoundingVolume* pkOther);
    virtual void AddViewerStrings(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings);

    NiUnionBV* NiUnionBV_NiUnionBV(void* pkOtherRaw);
    void NiUnionBV_RemoveAllBoundingVolumes();
    void AddViewerStrings_00e9f0b0(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings);
};
