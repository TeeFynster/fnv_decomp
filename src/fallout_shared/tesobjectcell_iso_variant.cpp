// src/fallout_shared/tesobjectcell_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesobjectcell.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy /GF (unit lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton.

#include "tesobjectcell_packet.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/IngredientItem.h"
#include <stddef.h>
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int TESTerrainLODManager_GetGrassNode();
NiAVObject* TESMain_GetWeatherRoot();

struct ExpiredRefPosition3
{
    float x, y, z;
};
struct FUN_00546af0_shell : public TESObjectCELL
{
    unsigned int GetDetachTime();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern TESDataHandler* g_dataHandler;
struct RefNode;
struct RefrShell;
struct ZoneShell
{
    bool ShouldCellRecalc(FUN_00546af0_shell* cell);
};
struct Modelish
{
    bool InventoryChanges_IsEmpty();
};
struct RefNode
{
    bool FUN_008256d0();
    RefrShell** FUN_006815c0();
    RefNode* FUN_00726070();
    void FUN_0063f7b0();
};
// The shared EffectItemList::vf01 returns void; this call consumes its Boolean result.
struct EffectItemListBoolQuery
{
    virtual void Destroy();
    virtual bool Query();
};
struct Obj34
{
    void UpdateSoundLevel(RefrShell* refr);
};
// ExtraShell_tesobjectcell_iso_variant: local type (was include/ExtraShell.h, which had no evidence of one real class); its methods are 0x00411ec0 ExtraDataList::CopyList, 0x004127e0 ExtraDataList::CompareList, 0x00418520 ExtraDataList::GetContainerChanges, 0x00418750 ExtraDataList::HasLeveledItem
#include "../../include/ExtraDataList.h"

class OpacityFadeState;
class RefNode;
class RefrShell;

class ExtraShell_tesobjectcell_iso_variant : public ExtraDataList
{
public:
    ExtraShell_tesobjectcell_iso_variant();

    int FUN_00418520();
    bool FUN_00418750();
    short ExtraDataList_GetCount();
    bool ExtraDataList_CompareList(ExtraShell_tesobjectcell_iso_variant*);
    void ExtraDataList_SetCount(int);
    void ExtraDataList_CopyList(ExtraShell_tesobjectcell_iso_variant*);
    signed char GetExtraByteValue();
    void ExtraDataList_RemoveHotkey();
    OpacityFadeState* GetOffsetC();
    void FUN_0041aeb0();
    void ExtraDataList_RemoveScript();
    void* ExtraDataList_GetModelSwap();
    RefNode* ExtraDataList_GetDroppedItemList();
    void ExtraDataList_RemoveDroppedItemList();
    void ExtraDataList_SetItemDropper(int a);
    RefrShell* ExtraDataList_GetAshPileRef();
};
struct RefrShell
{

    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void V49(int a);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool V64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual bool V88();
    virtual void v89();
    virtual void v90();
    virtual ExpiredRefPosition3 V91();
    virtual void V92(ExpiredRefPosition3* p);
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void V130(bool b);
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool V139(int a);
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void* V165();
    virtual void* V166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void V201(int a, int b, int c);
    bool TESObjectREFR_GetRefPersists_005653d0();
    bool TESObjectREFR_GetRespawn();
    bool IsExpired(unsigned int a);
    bool TESObjectREFR_HasQuestObject();
    void TESObjectREFR_MarkAsDeleted();
    ZoneShell* FUN_00567d20();
    bool TESForm_GetDestructible();
    bool FUN_00440d80();
    bool TESObjectREFR_GetPersistFlagValue();
    void TESObjectREFR_Lock();
    void TESForm_SetEmpty(bool b);
    void SetFlag2000(bool b);
    bool Actor_GetRespawn();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    TESBoundObject* BGSSaveFormBuffer_GetForm();
    void TESObjectREFR_SetLocationOnReference(ExpiredRefPosition3* p);
    void TESObjectREFR_SetAngleOnReference(ExpiredRefPosition3 p);
};
struct Calendar
{
    unsigned int FUN_00867e30();
};
struct DHShell : public TESDataHandler
{
    bool FUN_00469860(unsigned int id);
};
extern Calendar g_calendar;
unsigned int __cdecl TESObjectCELL_GetHoursToRespawnCell();
bool __fastcall BGSEncounterZone_ShouldReset(void* zone);
Obj34* __cdecl BGSDestructibleObjectForm_GetDestructionForm(void* p);
void __cdecl Script_InitActionList(RefrShell* refr, ExtraShell_tesobjectcell_iso_variant* extra);
bool __cdecl Script_SetActionFlag(RefrShell* refr, ExtraShell_tesobjectcell_iso_variant* extra, unsigned int a);
ExtraShell_tesobjectcell_iso_variant* __fastcall BSFile_GetDevice(RefrShell* refr);
struct CellShell : public FUN_00546af0_shell
{
    ZoneShell* FUN_00546c20();
    RefNode* GetRefList_009604f0();
    void SetDetachTime(unsigned int a, bool b);
    void* FUN_0054ddd0();
    bool FUN_00550200(ExpiredRefPosition3* p);
    bool TESObjectCELL_HandleExpiredReferences();
};
// @fnv 0x0054df30
// src: XBOX_PDB 0x0054df30
bool CellShell::TESObjectCELL_HandleExpiredReferences()
{
    if (g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
        return false;
    unsigned long _type;
    bool _changed;
    bool _allowed;
    ZoneShell* _special;
    unsigned int _oldState;
    RefNode* _item;
    bool _done;
    _oldState = g_calendar.FUN_00867e30();
    _changed = 0;
    _done = 0;
    _type = GetDetachTime();
    if (_type == 0)
    {
        CellRefLockEnter();
        RefNode* a;
        a = GetRefList_009604f0();
        for (; 0 != a && !a->FUN_008256d0();)
        {
            RefrShell* flag6;
            flag6 = *a->FUN_006815c0();
            a = a->FUN_00726070();
            switch (static_cast<int>(flag6->BGSSaveFormBuffer_GetForm()->FUN_00401170()))
            {
            case 0x1b:
                if (flag6->TESObjectREFR_GetRefPersists_005653d0())
                {
                    flag6->V130(!flag6->TESObjectREFR_GetRespawn());
                }
                break;
            case 0x2a:
            case 0x2b:
                if (flag6->TESObjectREFR_GetRefPersists_005653d0())
                {
                    RefrShell* c;
                    c = flag6;
                    if (c->IsExpired(_oldState))
                    {
                        flag6->V130(!flag6->TESObjectREFR_GetRespawn());
                    }
                }
                break;
            }
        }
        CellRefLockLeave();
        return true;
    }
    _allowed = 0;
    _special = FUN_00546c20();
    if (_type == 0xffffffff)
    {
        _changed = 1;
        _done = 1;
        _allowed = 1;
    }
    else
    {
        if (_oldState - _type > TESObjectCELL_GetHoursToRespawnCell())
            _allowed = 1;
        if (0 != _special)
        {
            if (BGSEncounterZone_ShouldReset(_special))
                _changed = _special->ShouldCellRecalc(this);
            else
                _changed = 0;
        }
        else
        {
            _changed = _allowed;
        }
    }
    CellRefLockEnter();
    {
        _item = GetRefList_009604f0();
        for (; 0 != _item && !_item->FUN_008256d0();)
        {
            RefrShell* refr2;
            refr2 = *_item->FUN_006815c0();
            _item = _item->FUN_00726070();
            if (_done && ((DHShell*)g_dataHandler)->FUN_00469860(refr2->GetHavokWorldObjectCountInSceneGraph_0084e3a0()))
            {
                if (!refr2->V88() && !refr2->TESObjectREFR_HasQuestObject())
                    refr2->V49(1);
                continue;
            }
            RefrShell* cnt;
            cnt = 0;
            if (refr2->V64())
                cnt = refr2;
            if (0 != cnt)
            {
                if (!cnt->IsExpired(_oldState))
                    continue;
            }
            else
            {
                if (_allowed)
                {
                    if (refr2->TESForm_GetDestructible())
                    {
                        Obj34* v;
                        v = BGSDestructibleObjectForm_GetDestructionForm(refr2->BGSSaveFormBuffer_GetForm());
                        v->UpdateSoundLevel(refr2);
                        if (!!BSFile_GetDevice(refr2)->ExtraDataList_GetModelSwap())
                            refr2->SetFlag2000(true);
                    }
                }
                ZoneShell* q;
                q = refr2->FUN_00567d20();
                if (q != _special)
                {
                    if (q)
                    {
                        if (!BGSEncounterZone_ShouldReset(q))
                            continue;
                    }
                }
                else
                {
                    if (!_changed)
                        continue;
                }
            }
            if (0 != cnt)
            {
                if (cnt->Actor_GetRespawn())
                {
                    cnt->V201(1, 0, 0);
                    RefNode* i;
                    i = BSFile_GetDevice(cnt)->ExtraDataList_GetDroppedItemList();
                    if (0 != i)
                    {
                        for (; 0 != i && !i->FUN_008256d0();)
                        {
                            RefrShell* tmp;
                            tmp = *i->FUN_006815c0();
                            BSFile_GetDevice(tmp)->ExtraDataList_SetItemDropper(0);
                            if (!tmp->V88())
                                tmp->TESObjectREFR_MarkAsDeleted();
                            i->FUN_0063f7b0();
                        }
                        BSFile_GetDevice(cnt)->ExtraDataList_RemoveDroppedItemList();
                    }
                    ExpiredRefPosition3 b;
                    cnt->V92(&b);
                    bool s;
                    s = 0;
                    if (cnt->V166() == this)
                    {
                        s = 1;
                    }
                    else
                    {
                        if (cnt->V165() == FUN_0054ddd0())
                        {
                            if (FUN_00550200(&b))
                                s = 1;
                        }
                    }
                    if (s)
                    {
                        cnt->TESObjectREFR_SetLocationOnReference(&b);
                        cnt->TESObjectREFR_SetAngleOnReference(cnt->V91());
                    }
                }
                else
                {
                    if (cnt->V139(0))
                    {
                        if (!cnt->V88() && !cnt->TESObjectREFR_HasQuestObject())
                        {
                            cnt->TESObjectREFR_MarkAsDeleted();
                            RefrShell* x;
                            x = BSFile_GetDevice(cnt)->ExtraDataList_GetAshPileRef();
                            if (!!x)
                                x->TESObjectREFR_MarkAsDeleted();
                        }
                        RefNode* p;
                        p = BSFile_GetDevice(cnt)->ExtraDataList_GetDroppedItemList();
                        if (!!p)
                        {
                            for (; p && !p->FUN_008256d0();)
                            {
                                RefrShell* y;
                                y = *p->FUN_006815c0();
                                BSFile_GetDevice(y)->ExtraDataList_SetItemDropper(0);
                                if (!y->V88())
                                    y->TESObjectREFR_MarkAsDeleted();
                                p->FUN_0063f7b0();
                            }
                            BSFile_GetDevice(cnt)->ExtraDataList_RemoveDroppedItemList();
                        }
                    }
                }
            }
            else
            {
                switch (static_cast<int>(refr2->BGSSaveFormBuffer_GetForm()->FUN_00401170()))
                {
                case 0x1b:
                    if (refr2->TESObjectREFR_GetRespawn())
                    {
                        refr2->V130(0);
                        if (!!reinterpret_cast<Modelish*>(BSFile_GetDevice(refr2)->FUN_00418520()))
                        {
                            if (!reinterpret_cast<Modelish*>(BSFile_GetDevice(refr2)->FUN_00418520())->InventoryChanges_IsEmpty())
                                refr2->TESObjectREFR_Lock();
                        }
                    }
                    break;
                case 0x26:
                    refr2->TESForm_SetEmpty(false);
                    break;
                case 0x1d:
                    if (refr2->FUN_00440d80() && !refr2->TESObjectREFR_GetPersistFlagValue() && !refr2->V88())
                    {
                        IngredientItem* j;
                        j = dynamic_cast<IngredientItem*>(refr2->BGSSaveFormBuffer_GetForm());
                        if (0 != j)
                        {
                            if (reinterpret_cast<EffectItemListBoolQuery&>(reinterpret_cast<char*>(j)[
                                    offsetof(IngredientItem, m_iEffectCount) -
                                    offsetof(EffectItemList, m_iEffectCount)]).Query())
                                refr2->V49(0);
                        }
                    }
                    break;
                }
            }
            Script_InitActionList(refr2, BSFile_GetDevice(refr2));
            Script_SetActionFlag(refr2, BSFile_GetDevice(refr2), 0x80000000);
        }
    }
    CellRefLockLeave();
    SetDetachTime(0, false);
    return _changed;
}
