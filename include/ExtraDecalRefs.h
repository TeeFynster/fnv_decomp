#pragma once

#include "BSExtraData.h"
#include "MagicTarget.h"

class BSExtraDataEx;
class NiPoint3;
class ReferenceIntersectionData;
class TESForm;
class TESObjectREFR;

class ExtraDecalRefs : public BSExtraData
{
public:
    ExtraDecalRefs();
    void InitItem_00433db0(TESForm* form);

    ReferenceIntersectionData* FindDecalReference(TESObjectREFR*);
    void Copy(BSExtraDataEx* apSource);
    void SetDecalRefData(TESObjectREFR* ref, const NiPoint3& intersect, const NiPoint3& normal);

    BSSimpleList<ReferenceIntersectionData*> m_kDecalReferences;
};
