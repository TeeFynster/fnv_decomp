
// tesobjectcell_ctx_variant.cpp: context variant of src/fallout_shared/tesobjectcell.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "tesobjectcell_packet.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/TESForm.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int TESTerrainLODManager_GetGrassNode();
NiAVObject* TESMain_GetWeatherRoot();

#include "../../include/BSSimpleList.h"

class Cell_Sub;

class FUN_00544f60
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48;
    BSSimpleList<TESObjectREFR*> list4C;
    BSSimpleList<TESObjectREFR*> list54;
    int unk5c, unk60;

    FUN_00544f60();
};

struct CellC4Holder
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c;
    int f20, f24, f28, f2c, f30, f34, f38, f3c;
    int f40, f44, f48, f4c, f50, f54, f58, f5c;
    int f60, f64, f68, f6c, f70, f74, f78, f7c;
    int f80, f84, f88, f8c, f90, f94, f98, f9c;
    int fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc;
    int fc0;
    FUN_00544f60* unkC4;
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;


class FUN_00439f90_shell
{
  public:
    bool TESObjectREFR_IsMultiBoundRef();
};

class FUN_00569ac0_shell
{
  public:
    TESObjectREFR* TESObjectREFR_GetMultiBoundRef();
};

class FUN_005656d0_shell
{
  public:
    bool TESObjectREFR_HasScript();
};

class FUN_0056a250_shell
{
  public:
    bool TESObjectREFR_IsActivatingChildren();
};

class FUN_00545740_shell
{
  public:
    void GetOrCreateFaceGenNode(TESObjectREFR*);
};

class FUN_00545960_shell
{
  public:
    void* TESObjectCELL_GetMultiBoundNode(TESObjectREFR*);
};

class FUN_00587870_shell
{
  public:
    BSSimpleList<TESObjectREFR*>* TESWorldSpace_GetOverlappedMultiBoundRefs(TESObjectCELL*);
};

class BSSimpleList_standin
{
  public:
    void FUN_0063f7b0();
};


class CellSubTarget
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0a();
    virtual void Unk_0b();
    virtual void Unk_0c();
    virtual void Unk_0d();
    virtual void Unk_0e();
    virtual void Unk_0f();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1a();
    virtual void Unk_1b();
    virtual void Unk_1c();
    virtual void Unk_1d();
    virtual void Unk_1e();
    virtual void Unk_1f();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2a();
    virtual void Unk_2b();
    virtual void Unk_2c();
    virtual void Unk_2d();
    virtual void Unk_2e();
    virtual void Unk_2f();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37(CellSubTarget* a, int val);
};

class Cell_Sub : public TESObjectCELL
{
  public:
    void TESObjectCELL_CreateLoadedData();
};

// @fnv 0x00544ce0
// src: COMMUNITY 0x00544ce0
void Cell_Sub::TESObjectCELL_CreateLoadedData()
{
    if (((CellC4Holder*)this)->unkC4 == 0)
    {
        ((CellC4Holder*)this)->unkC4 = new FUN_00544f60();
    }
    CellRefLockEnter();
    BSSimpleList<TESObjectREFR*> localList9;
    BSSimpleList<TESObjectREFR*>* iter = (BSSimpleList<TESObjectREFR*>*)GetRefList_009604f0();
    while (iter != 0 && !iter->IsEmpty())
    {
        TESObjectREFR* item5 = iter->GetItem();
        iter = iter->GetNext();
        if (!((TESForm*)item5)->GetDeleted() || g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
        {
            if (((FUN_00439f90_shell*)item5)->TESObjectREFR_IsMultiBoundRef())
            {
                ((FUN_00545740_shell*)this)->GetOrCreateFaceGenNode(item5);
                if (((FUN_00569ac0_shell*)item5)->TESObjectREFR_GetMultiBoundRef())
                {
                    localList9.AddHead(item5);
                }
            }
            else
            {
                if (!((TESForm*)item5)->IsActor())
                {
                    if (((FUN_005656d0_shell*)item5)->TESObjectREFR_HasScript())
                    {
                        ((CellC4Holder*)this)->unkC4->list4C.AddHead(item5);
                    }
                }
                if (((FUN_0056a250_shell*)item5)->TESObjectREFR_IsActivatingChildren())
                {
                    ((CellC4Holder*)this)->unkC4->list54.AddHead(item5);
                }
            }
        }
    }
    CellRefLockLeave();
    while (!localList9.IsEmpty())
    {
        TESObjectREFR* item3 = localList9.GetItem();
        ((BSSimpleList_standin*)&localList9)->FUN_0063f7b0();
        TESObjectREFR* other = ((FUN_00569ac0_shell*)item3)->TESObjectREFR_GetMultiBoundRef();
        CellSubTarget* a8 = (CellSubTarget*)((FUN_00545960_shell*)this)->TESObjectCELL_GetMultiBoundNode(item3);
        CellSubTarget* b2 = (CellSubTarget*)((FUN_00545960_shell*)this)->TESObjectCELL_GetMultiBoundNode(other);
        if (a8 != b2)
        {
            b2->Unk_37(a8, 1);
        }
    }
    TESWorldSpace* extra9 = GetParentWorldSpace();
    if (extra9 != 0)
    {
        iter = ((FUN_00587870_shell*)extra9)->TESWorldSpace_GetOverlappedMultiBoundRefs(this);
        while (iter != 0 && !iter->IsEmpty())
        {
            ((FUN_00545740_shell*)this)->GetOrCreateFaceGenNode(iter->GetItem());
            iter = iter->GetNext();
        }
    }
}
