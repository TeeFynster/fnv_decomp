
// tesobjectrefr_ctx_variant.cpp: context variant of src/fallout_shared/tesobjectrefr.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "tesobjectrefr_decls.h"
#include "../../include/AutoMemHelper.h"
#include "../../include/BaseExtraList.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/ExtraScript.h"
#include "../../include/InventoryChanges.h"
#include "../../include/Script.h"
GarbageCollectorUpdateState* FUN_00446ef0();
void* FUN_0056a8c0();
void FUN_005743f0();
void FUN_00575c90(unsigned char value);
float FUN_005790b0();
float FUN_005790d0();
void FUN_0057acc0(unsigned int index);

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSExtraData;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct ScriptHeaderData;
struct ScriptReferencedObject;
struct CStringArgument;
struct ScriptCompiler;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
struct TESObjectWEAP;
struct TESQuest;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00565730_shell : public TESObjectREFR
{
    void FUN_00565730();
};

struct ShellH;
struct XActor
{
    ShellH* GetExtra() const;
};
struct RefH
{
    bool IsDeleted() const;
};
struct FUN_00419ed0_shell
{
    void FUN_00419ed0(Script*);
};
struct FUN_00419f80_shell
{
    void FUN_00419f80(ScriptLocals*);
};
TESContainer* __fastcall GetContainer(TESObjectREFR*);
TESBoundObject* __fastcall _FNV_GetObjectReference(TESObjectREFR*);
Script* FUN_004826d0(TESBoundObject*);
struct VRefStandin
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v49();
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
    virtual void v64();
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
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
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
    virtual TESBoundObject* GetBaseObj();
};

// @fnv 0x00565730
void FUN_00565730_shell::FUN_00565730()
{
    TESBoundObject* pObj;
    ExtraScript* pExtra;
    Script* pScript;
    TESContainer* pCont;
    InventoryChanges* pinventory;
    if (((RefH*)this)->IsDeleted())
        return;
    AutoMemHelper tempMemContext(0x15, true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectREFR.cpp", 0x196e);
    pExtra = (ExtraScript*)((BaseExtraList*)((XActor*)this)->GetExtra())->GetExtraData(0xd);
    if (pExtra && pExtra->pScript)
        return;
    pObj = ((VRefStandin*)this)->GetBaseObj();
    if (!pObj)
        pObj = _FNV_GetObjectReference(this);
    pScript = FUN_004826d0(pObj);
    if (pScript)
    {
        ((FUN_00419ed0_shell*)((XActor*)this)->GetExtra())->FUN_00419ed0(pScript);
        ((FUN_00419f80_shell*)((XActor*)this)->GetExtra())->FUN_00419f80(pScript->GetOrCreateScriptLocals());
    }
    pCont = GetContainer(this);
    if (pCont)
    {
        pinventory = InventoryChanges::CreateForReference(this);
        pinventory->FUN_004d1960();
    }
}
