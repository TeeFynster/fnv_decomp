
// src/fallout/ai/patrolpackage_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectREFR, TESPackage). The skeleton of src/fallout/ai/patrolpackage.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "../../../include/BGSLoadGameBuffer.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESPackage.h"
#include "../../../include/PatrolActorPackageData.h"

class Actor;
class TESPackage;
class TESPatrolPackageData;
class NiPoint3;
class TESObjectWEAP;
class NavMeshInfo;
class BSSimpleArray_TESObjectWEAP___1024_
{
  public:
    void SetSize(unsigned int, bool);
};
class BSSimpleArray_NavMeshInfo___1024_
{
  public:
    NavMeshInfo*& GetAt(int);
};
class LocationDescriptor
{
  public:
    void SetLocRef(TESObjectREFR*);
    TESObjectREFR* GetLocationReference();
};
class ArchiveManager
{
  public:
    void CopyArchiveName(char*, unsigned int);
};

// Adapted from another contributor's unverified prior attempt; credit retained.

class NavMeshInfo;
class NavInfoArray
{
  public:
    void SetSize(unsigned int, bool);
    NavMeshInfo*& GetAt(int);
};
struct PatrolLoadShell
{
    void* vtable;
    int iState;
    int unk08;
    bool bFlag0C;
    int unk10;
    TESPackage* pPackage;
    int unk18;
    NavInfoArray kArray;
    int unk20;
    int unk24;
    int unk28;
    bool bFlag2C;
    int unk30;
    int unk34;
    void PatrolActorPackageData_LoadGame(BGSLoadFormBuffer* apBuffer);
};
// @fnv 0x009f34e0
// src: XBOX_PDB 0x009f34e0
void PatrolLoadShell::PatrolActorPackageData_LoadGame(BGSLoadFormBuffer* apBuffer)
{
    apBuffer->ReadDataBlock(&iState, 4);
    iState = (iState >= 0 && iState <= 2) ? iState : 0;
    apBuffer->ReadDataBlock(&unk08, 4);
    apBuffer->ReadDataBlock(&unk34, 4);
    apBuffer->ReadDataBlock(&bFlag0C, 1);
    apBuffer->ReadDataBlock(&bFlag2C, 1);
    apBuffer->ReadDataBlock(&unk30, 4);
    pPackage = dynamic_cast<TESPackage*>(TESForm::GetFormByID(apBuffer->ReadFormIdentifier()));
    unsigned int ItemUpdateArray = apBuffer->ReadElementCount();
    kArray.SetSize(ItemUpdateArray, true);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        NavMeshInfo*& rEntry = kArray.GetAt(i);
        apBuffer->ReadFormIdentifier(&rEntry);
    }
}

struct ExtraHolder;

struct ExtraHolder
{
    void ExtraDataList_SetPatrolRefInUse(struct PatrolActor* actor);
};
struct PatrolActor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void* GetPatrolTarget();
};
struct PatrolPackage
{
    void* GetPatrolData();
};
struct PatrolRefArray
{
    void* vtbl;
    TESObjectREFR** pBuffer;
    unsigned int uiSize;
    unsigned int uiAlloc;
    unsigned int GetSize();
    TESObjectREFR*& GetAtRef(unsigned int);
    void RemoveAt(unsigned int, unsigned int);
    bool IsEmpty() const;
    TESObjectREFR*& GetAt(unsigned int);
};
struct PatrolData9f3610
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0C;
    PatrolActor* pActor;
    PatrolPackage* pPackage;
    void* pPatrolRefData;
    PatrolRefArray kRefs;
    bool bRepeat;
    int unk30;
    unsigned int uiIndex;

    bool SetPatrolRefIndex(unsigned int);
    void SelectClosestPatrolPoint(void*);
    void PatrolActorPackageData_InitLoadGame(BGSLoadFormBuffer* apBuf);
};

// @fnv 0x009f3610
// src: XBOX_PDB 0x009f3610
void PatrolData9f3610::PatrolActorPackageData_InitLoadGame(BGSLoadFormBuffer* apBuf)
{
    bool bAnyRemoved = false;
    unsigned int ItemUpdateArray = kRefs.GetSize();
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        bool bRemove = false;
        TESObjectREFR*& rRef = kRefs.GetAtRef(i);
        rRef =
            rRef ? dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID((unsigned int)rRef))
                 : 0;
        if (rRef)
        {
            rRef->TESObjectREFR_SetTargeted(true);
        }
        else
        {
            bAnyRemoved = true;
            bRemove = true;
            uiIndex = uiIndex > 0 ? uiIndex - 1 : 0;
        }
        if (bRemove)
        {
            kRefs.RemoveAt(i, 1);
            i--;
            ItemUpdateArray--;
        }
    }
    pActor = reinterpret_cast<PatrolActor*>(apBuf->GetActor());
    if (pPackage)
    {
        if (!pPatrolRefData)
        {
            pPatrolRefData = pPackage->GetPatrolData();
        }
        if (!SetPatrolRefIndex(uiIndex))
        {
            SelectClosestPatrolPoint(pActor->GetPatrolTarget());
        }
        if (!kRefs.IsEmpty() && bRepeat)
        {
            TESObjectREFR* pRef = kRefs.GetAt(uiIndex);
            ExtraHolder* pExtraList = pRef ? reinterpret_cast<ExtraHolder*>(pRef->BSFile_GetDevice()) : 0;
            if (pExtraList)
            {
                pExtraList->ExtraDataList_SetPatrolRefInUse(pActor);
            }
        }
    }
}
