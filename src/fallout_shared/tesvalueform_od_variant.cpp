
// src/fallout_shared/tesvalueform_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesvalueform.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/tesvalueform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesvalueform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/TESValueForm.h"
#include "../../include/TESSaveLoadGame.h"

// @fnv 0x0048e7f0
// src: XBOX_PDB 0x0048e7f0
void TESValueForm::CopyComponent(BaseFormComponent* component)
{
    TESValueForm* form = dynamic_cast<TESValueForm*>(component);
    if (!form)
        return;
    SetFormValue(form->GetValueFromForm());
}

// @fnv 0x0048e9b0
// src: GUESS 0x0048e9b0 (confidence: medium)
unsigned short TESValueForm::GetFlaggedDataSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    if (aiFlags & 2)
        isize += 4;
    return isize;
}

namespace fnv_0048e9e0 {
extern TESSaveLoadGame* g_TESSaveLoadGame;

}  // namespace fnv_0048e9e0

// @fnv 0x0048e9e0
// src: XBOX_PDB 0x0048e9e0
void TESValueForm::SaveGame_0048e9e0(unsigned int flags)
{
    if (flags & 2)
        fnv_0048e9e0::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&iValue, 4);
}


namespace fnv_0048ea10 {
extern TESSaveLoadGame* g_TESSaveLoadGame;

}  // namespace fnv_0048ea10

// @fnv 0x0048ea10
// src: XBOX_PDB 0x0048ea10
void TESValueForm::LoadGame_0048ea10(unsigned int a, unsigned int b)
{
    if (a & 2)
        fnv_0048ea10::g_TESSaveLoadGame->ReadTypedData(&iValue, 4);
}


// @fnv 0x0048ea40
// src: COMMUNITY 0x0048ea40
void TESValueForm::SaveGameBGS_0048ea40(BGSSaveFormBuffer* aBuffer)
{
    if (reinterpret_cast<BGSLoadFormBuffer*>(aBuffer)->GetChangeFlags(2).operator bool())
        aBuffer->SaveData(&iValue, 4, 0);
}


// @fnv 0x0048ea80
void TESValueForm::LoadGame(BGSLoadFormBuffer* buffer)
{
    if (buffer->GetChangeFlags(2u).operator bool())
        buffer->ReadTypedData(static_cast<void*>(&iValue), 4u);
}

struct BaseData
{
    void* ExtraDataList_GetLevCreaOriginalBase();
};
struct Item
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
    virtual bool v64();
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
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual bool v134();
    bool TESForm_IsStillLoading();
    void* BGSSaveFormBuffer_GetForm();
    BaseData* BSFile_GetDevice();
};
struct Collection
{
    int unk00;
    unsigned int ProcessArray_GetProcessLevelTail(int);
    Item* ProcessArray_GetItem(unsigned int);
};
struct Holder
{
    int unk00;
    Collection items;
    Item* ProcessLists_GetActorRefInHigh(void*, int);
};
// @fnv 0x00970a20
// src: XBOX_PDB 0x00970a20
Item* Holder::ProcessLists_GetActorRefInHigh(void* key, int unused)
{
    Item* current = 0;
    Item* result = 0;
    for (unsigned int index = 0; index < items.ProcessArray_GetProcessLevelTail(0); index++)
    {
        result = items.ProcessArray_GetItem(index);
        if (result && !current && !result->TESForm_IsStillLoading())
        {
            Item* actor = 0;
            if (result && result->v64())
                actor = result;
            if (actor)
            {
                void* target = 0;
                if (actor->v134())
                    target = actor->BGSSaveFormBuffer_GetForm();
                if (target && key == target)
                    current = actor;
                else if (actor->BSFile_GetDevice()->ExtraDataList_GetLevCreaOriginalBase() == key)
                    current = actor;
            }
        }
    }
    return current;
}

// @fnv 0x0048e840
bool TESValueForm::IsEqualToBase(BaseFormComponent* other)
{
    TESValueForm* form = dynamic_cast<TESValueForm*>(other);
    if (!form)
        return true;
    if (GetValueFromForm() != form->GetValueFromForm())
        return true;
    return false;
}
