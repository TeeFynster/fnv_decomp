#pragma once

#include "TESBoundTreeObject.h"
#include "TESModelTree.h"
#include "TESIconTree.h"
#include "BGSDestructibleObjectForm.h"
#include "NiTPrimitiveArray_unsigned_int_.h"
#include "TreeRecordData.h"
#include "NiPoint2.h"

class TreeDimensions;

class TESObjectTREE : public TESBoundTreeObject,
                      public TESModelTree,
                      public TESIconTree,
                      public BGSDestructibleObjectForm
{
public:
    NiTPrimitiveArray_unsigned_int_ m_kSeedArray;
    TreeRecordData Data;
    NiPoint2 m_kBillboardDimensions;

    TESObjectTREE();
    TreeRecordData* GetData();
    NiPoint2* GetDimensions();
    TreeDimensions* NiAVObject_GetWorldTranslate();
    bool TESObjectTREE_IsLargeEnoughForDistantLOD();
    void UpdateRustleSpeed(const float speed);
    virtual void InitItem();
    bool Load(TESFile* file);
    // TESForm vtable slot 8 (TESObjectTREE vftable 0x0102bc94 slot 8 = 0x0051bbc0)
    bool LoadForm(TESFile* file);

    virtual void Reserved97();
    virtual void Reserved98();
    virtual void Reserved99();
    virtual void Reserved100();
    virtual void Reserved101();
    virtual void Reserved102();
    virtual void Reserved103();
    virtual void Reserved104();
    virtual void Reserved105();
    virtual void Reserved106();
    virtual void Reserved107();
    virtual void Reserved108();
    virtual void Reserved109();
    virtual void Reserved110();
    virtual double GetTreeScale(float scale);
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
};
