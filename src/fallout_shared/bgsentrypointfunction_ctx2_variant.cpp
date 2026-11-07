
// bgsentrypointfunction_ctx2_variant.cpp: context variant of src/fallout_shared/bgsentrypointfunction.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "../../include/Actor.h"
#include "../../include/ExtraDataList.h"
#include "../../include/InventoryChanges.h"
#include "../../include/Script.h"
#include "../../include/TESContainer.h"
#include "../../include/TESLeveledList.h"

struct BoundObj5e5f50
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual void b43();
    virtual void b44();
    virtual void b45();
    virtual void b46();
    virtual void b47();
    virtual void b48();
    virtual void b49();
    virtual void b50();
    virtual void b51();
    virtual void b52();
    virtual void b53();
    virtual void b54();
    virtual void b55();
    virtual void b56();
    virtual bool IsLeveledOrPlayable();
};
struct InventoryItemEntry
{
    int m_iCountDelta;
    BoundObj5e5f50* pObj;
};
struct ListShell
{
    bool FUN_008256d0();
    InventoryItemEntry** FUN_006815c0();
    ListShell* FUN_00726070();
};
struct LevForm5e5f50
{
    virtual void vfn00();
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    TESLeveledList list;
};
struct DataLeveledList5e5f50
{
    LevForm5e5f50* FUN_00726070();
};
Script* __fastcall ExtraDataList_GetScript(ExtraDataList*);
Script* __cdecl TESScriptableForm_GetFormScript(BoundObj5e5f50*);
bool __cdecl BGSEntryPointFunction_CheckFunctionArguments(int, int, void*, int, unsigned char, void**, void*);

// @fnv 0x005e5f50
// src: XBOX_PDB 0x005e5f50
void __cdecl BGSEntryPointFunction_AddLeveledListToTargetFunction(void* apPerkOwner, int aeFunctionType, unsigned char acArgumentCount,
                          void** apFunctionArgument, void* apData)
{
    if (!BGSEntryPointFunction_CheckFunctionArguments(1, 3, apPerkOwner, aeFunctionType, acArgumentCount, apFunctionArgument, apData))
        return;
    DataLeveledList5e5f50* pfunctionData = (DataLeveledList5e5f50*)apData;
    Actor* ptarget = (Actor*)*apFunctionArgument;
    TESContainer tempcont;
    pfunctionData->FUN_00726070()->list.PopulateContainerFromReference(apPerkOwner, &tempcont);
    InventoryChanges* pinventory = InventoryChanges::CreateForReference(ptarget);
    ListShell* pCurrentElementNext = tempcont.FUN_00717e50();
    if (pinventory)
    {
        while (pCurrentElementNext && !pCurrentElementNext->FUN_008256d0() && *pCurrentElementNext->FUN_006815c0())
        {
            InventoryItemEntry* pdata = *pCurrentElementNext->FUN_006815c0();
            BoundObj5e5f50* pboundObject = 0;
            if (pdata->pObj && pdata->pObj->IsLeveledOrPlayable())
                pboundObject = pdata->pObj;
            if (pboundObject)
            {
                Script* pScript = TESScriptableForm_GetFormScript(pdata->pObj);
                if (pScript)
                {
                    ExtraDataList* pExtra = 0;
                    for (int n = 0; n < pdata->m_iCountDelta; n++)
                    {
                        pExtra = new ExtraDataList;
                        pExtra->ExtraDataList_SetCount(1);
                        if (pExtra && !ExtraDataList_GetScript(pExtra))
                        {
                            pExtra->ExtraDataList_SetScript(pScript);
                            pExtra->ExtraDataList_SetScriptLocals(ExtraDataList_GetScript(pExtra)->GetOrCreateScriptLocals());
                        }
                    }
                    ptarget->AddItem((TESForm*)pboundObject, pExtra, 1);
                }
                else
                    ptarget->AddItem((TESForm*)pboundObject, 0, pdata->m_iCountDelta);
            }
            pCurrentElementNext = pCurrentElementNext->FUN_00726070();
        }
    }
}
