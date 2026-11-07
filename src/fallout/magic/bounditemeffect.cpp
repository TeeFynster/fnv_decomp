#include "../../../include/BoundItemEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/BSSimpleList.h"
#include "../../../include/Character.h"
#include "../../../include/TESNPC.h"
#include "../../../include/ActiveEffect.h"
#include "../../../include/AssociatedItemEffect.h"
#include "../../../include/EffectItemList.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/MagicItem.h"
#include "../../../include/TESBipedModelForm.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESModel.h"
#include "../../../include/TESObjectARMO.h"
#include "../../../include/TESObjectWEAP.h"
#include "../../../include/TESSound.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/TESSaveLoadGame.h"
#include "../../../include/EffectItem.h"

// src/fallout/magic/bounditemeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/bounditemeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Returns true if apTarget is a Character, using a dynamic_cast to check the type.
// @fnv 0x008099c0
bool __thiscall BoundItemEffect::IsTargetCharacter(MagicTarget* apTarget)
{
    Character* pActor = dynamic_cast<Character*>(apTarget);
    return pActor != 0;
}

// @fnv 0x00807eb0: scalar deleting destructor emitted for BoundItemEffect.

// Calls the base AssociatedItemEffect constructor, installs the vtable, and zeroes the derived fields at offsets 0x4c through 0xa8.
// @fnv 0x00807e10
BoundItemEffect::BoundItemEffect(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect)
    : AssociatedItemEffect(apCaster, apSpell, apEffect)
{
    m_pkWeaponEntry = 0;
    int i;
    for (i = 0; i < 0x14; i++)
        m_apArmorEntries[i] = 0;
    unka0 = 0.0f;
    m_bModifierActive = 0;
    m_bShowShader = 0;
    m_bLoadWeaponModel = 0;
    m_bLoadArmorModel = 0;
    pending = 0;
}

struct RefS
{
    TESBoundObject* GetBaseObject();
};

struct XDataS
{
    void RemoveInventoryItem();
};

struct XListS
{
    XDataS** GetItem();
};

struct EntryS
{
    XListS* GetExtendData() const;
    TESBoundObject* GetType();
    void Cleanup();
    ~EntryS();
};

struct EffItemS
{
    void* GetUnk0c();
};

struct LoaderS
{
    void ProcessModelRequest(const char* apPath, bool abFlag, unsigned int auiPriority);
};

extern LoaderS* g_modelLoader;

// @fnv 0x00807ee0
BoundItemEffect::~BoundItemEffect()
{
    if (m_pkWeaponEntry && m_bLoadWeaponModel)
    {
        TESBoundObject* pObject = ((EntryS*)m_pkWeaponEntry)->GetType();
        TESObjectWEAP* pWeap = dynamic_cast<TESObjectWEAP*>(pObject);
        if (pWeap && ((const TESModel*)((const char*)&pWeap->m_kModelFilePath - sizeof(void*)))->GetModelLength() > 0)
            g_modelLoader->ProcessModelRequest(pWeap->GetModelFilePath(), false, 1);
    }
    if (m_bLoadArmorModel)
    {
        int iSex = 0;
        if (FUN_0059bb30() && FUN_0059bb30()->GetMagicTargetReference())
        {
            TESNPC* pNPC = dynamic_cast<TESNPC*>(((RefS*)FUN_0059bb30()->GetMagicTargetReference())->GetBaseObject());
            if (pNPC)
                iSex = pNPC->GetSex();
        }
        for (int i = 0; i < 20; i++)
        {
            if (m_apArmorEntries[i] && ((EntryS*)m_apArmorEntries[i])->GetType())
            {
                TESBipedModelForm* pBiped = dynamic_cast<TESBipedModelForm*>(((EntryS*)m_apArmorEntries[i])->GetType());
                if (pBiped)
                {
                    m_bLoadArmorModel = true;
                    g_modelLoader->ProcessModelRequest(pBiped->GetBipedModel(iSex), false, 1);
                }
            }
        }
    }
    if (m_pkWeaponEntry)
    {
        XDataS* pXData = ((EntryS*)m_pkWeaponEntry)->GetExtendData() ? *((EntryS*)m_pkWeaponEntry)->GetExtendData()->GetItem() : 0;
        if (pXData)
            pXData->RemoveInventoryItem();
        ((EntryS*)m_pkWeaponEntry)->Cleanup();
        delete (EntryS*)m_pkWeaponEntry;
    }
    for (int j = 0; j < 20; j++)
    {
        if (m_apArmorEntries[j])
        {
            XDataS* pXData2 = ((EntryS*)m_apArmorEntries[j])->GetExtendData() ? *((EntryS*)m_apArmorEntries[j])->GetExtendData()->GetItem() : 0;
            if (pXData2)
                pXData2->RemoveInventoryItem();
            ((EntryS*)m_apArmorEntries[j])->Cleanup();
            delete (EntryS*)m_apArmorEntries[j];
        }
    }
    if (m_bShowShader && FUN_0044ddc0() && ((EffItemS*)GetHavokWorldObjectCountInSceneGraph_0084e3a0()))
    {
        EffectSetting* pHolder = (EffectSetting*)FUN_0044ddc0()->FUN_0040a300(0);
        EffItemS* pFound = (EffItemS*)FUN_0044ddc0()->FindCostliestEffectItem((int)((EffItemS*)GetHavokWorldObjectCountInSceneGraph_0084e3a0())->GetUnk0c(), 0);
        if (((const TESModel*)((const char*)&pHolder->m_kModelFilePath - sizeof(void*)))->GetModelLength() > 0 && ((EffItemS*)GetHavokWorldObjectCountInSceneGraph_0084e3a0()) == pFound)
            g_modelLoader->ProcessModelRequest(pHolder->GetModelFilePath(), false, 1);
        m_bShowShader = false;
    }
}

void* __cdecl FormHeap_Allocate(unsigned int uiSize);
void* operator new(unsigned int);

// Allocates a BoundItemEffect from the caster, item and effect item.
// @fnv 0x008085f0
// src: XBOX_PDB 0x008085f0
BoundItemEffect* __cdecl BoundItemEffect_Instantiate(MagicCaster* pkCaster, MagicItem* pkItem, EffectItem* pkEffectItem)
{
    return new BoundItemEffect(pkCaster, pkItem, pkEffectItem);
}

struct AEEntry
{
    void* pExtendData;
    int iCount;
    TESBoundObject* pType;

    AEEntry(AEEntry* apSource);
    TESBoundObject* GetType();
};

struct AERef
{
    TESBoundObject* GetBaseObject();
};

struct AECaster
{
    virtual void v00();
    virtual AERef* GetCasterRef();
};

struct AEModelLoader
{
    void ProcessModelRequest(const char* apPath, int aiUnk1, int aiUnk2, int aiUnk3, bool abUnk4, bool abUnk5,
                             bool abUnk6);
};

extern AEModelLoader* g_pAEModelLoader;

// Copies the effect and its item entries, queues their models, and copies the modifier state.
// @fnv 0x008082c0
ActiveEffect* BoundItemEffect::Copy()
{
    BoundItemEffect* pNewInstance = new BoundItemEffect(m_pEffectInstance, pSpell, pEffect);
    AssociatedItemEffect::CopyData(pNewInstance);
    if (m_pkWeaponEntry)
        pNewInstance->m_pkWeaponEntry = (InventoryStackRecord*)new AEEntry((AEEntry*)m_pkWeaponEntry);
    for (int i = 0; i < 20; i++)
    {
        if (m_apArmorEntries[i])
            pNewInstance->m_apArmorEntries[i] = (InventoryStackRecord*)new AEEntry((AEEntry*)m_apArmorEntries[i]);
    }

    if (m_pkWeaponEntry && m_bLoadWeaponModel)
    {
        TESBoundObject* pType = ((AEEntry*)m_pkWeaponEntry)->GetType();
        TESObjectWEAP* pWeapon = dynamic_cast<TESObjectWEAP*>(pType);
        if (pWeapon && ((const TESModel*)((const char*)&pWeapon->m_kModelFilePath - sizeof(void*)))->GetModelLength() > 0)
        {
            pNewInstance->m_bLoadWeaponModel = true;
            g_pAEModelLoader->ProcessModelRequest(pWeapon->GetModelFilePath(), 0, 0, 0, true, true, false);
        }
    }

    if (m_bLoadArmorModel)
    {
        int iSex = 0;
        if (((AECaster*)FUN_0059bb30())->GetCasterRef())
        {
            TESNPC* pNPC = dynamic_cast<TESNPC*>(((AECaster*)FUN_0059bb30())->GetCasterRef()->GetBaseObject());
            if (pNPC)
                iSex = pNPC->GetSex();
        }
        for (int j = 0; j < 20; j++)
        {
            if (m_apArmorEntries[j] && ((AEEntry*)m_apArmorEntries[j])->GetType())
            {
                TESBipedModelForm* pBiped = dynamic_cast<TESBipedModelForm*>(((AEEntry*)m_apArmorEntries[j])->GetType());
                if (pBiped)
                {
                    pNewInstance->m_bLoadArmorModel = true;
                    g_pAEModelLoader->ProcessModelRequest(pBiped->GetBipedModel(iSex), 0, 0, 0, true, true, false);
                }
            }
        }
    }
    pNewInstance->m_bModifierActive = m_bModifierActive;
    return pNewInstance;
}

struct ItemData
{
    void SetEquippedState(bool);
};
struct ItemList
{
    ItemData** GetItem();
};
struct ItemEntry
{
    TESObjectWEAP* GetType();
    ItemList* GetExtendData();
};
struct Proc
{
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf00a();
    virtual void vf00b();
    virtual void vf00c();
    virtual void vf00d();
    virtual void vf00e();
    virtual void vf00f();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf01a();
    virtual void vf01b();
    virtual void vf01c();
    virtual void vf01d();
    virtual void vf01e();
    virtual void vf01f();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf02a();
    virtual void vf02b();
    virtual void vf02c();
    virtual void vf02d();
    virtual void vf02e();
    virtual void vf02f();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf03a();
    virtual void vf03b();
    virtual void vf03c();
    virtual void vf03d();
    virtual void vf03e();
    virtual void vf03f();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf04a();
    virtual void vf04b();
    virtual void vf04c();
    virtual void vf04d();
    virtual void vf04e();
    virtual void vf04f();
    virtual void vf050();
    virtual void vf051();
    virtual ItemEntry* GetEntry();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf05a();
    virtual void vf05b();
    virtual void vf05c();
    virtual void vf05d();
    virtual void vf05e();
    virtual void vf05f();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf06a();
    virtual void vf06b();
    virtual void vf06c();
    virtual void vf06d();
    virtual void vf06e();
    virtual void vf06f();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf07a();
    virtual void vf07b();
    virtual void vf07c();
    virtual void vf07d();
    virtual void vf07e();
    virtual void vf07f();
    virtual void vf080();
    virtual void vf081();
    virtual void vf082();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void vf089();
    virtual void vf08a();
    virtual void vf08b();
    virtual void vf08c();
    virtual void vf08d();
    virtual void vf08e();
    virtual void vf08f();
    virtual void vf090();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf09a();
    virtual void vf09b();
    virtual void vf09c();
    virtual void vf09d();
    virtual void vf09e();
    virtual void vf09f();
    virtual void vf0a0();
    virtual void vf0a1();
    virtual void vf0a2();
    virtual void vf0a3();
    virtual void vf0a4();
    virtual void vf0a5();
    virtual void vf0a6();
    virtual void vf0a7();
    virtual void vf0a8();
    virtual void vf0a9();
    virtual void vf0aa();
    virtual void vf0ab();
    virtual void vf0ac();
    virtual void vf0ad();
    virtual void vf0ae();
    virtual void vf0af();
    virtual void vf0b0();
    virtual void vf0b1();
    virtual void vf0b2();
    virtual void vf0b3();
    virtual void vf0b4();
    virtual void vf0b5();
    virtual void vf0b6();
    virtual void vf0b7();
    virtual void vf0b8();
    virtual void vf0b9();
    virtual void vf0ba();
    virtual void vf0bb();
    virtual void vf0bc();
    virtual void vf0bd();
    virtual void vf0be();
    virtual void vf0bf();
    virtual void vf0c0();
    virtual void vf0c1();
    virtual void vf0c2();
    virtual void vf0c3();
    virtual void vf0c4();
    virtual void vf0c5();
    virtual void vf0c6();
    virtual void vf0c7();
    virtual void vf0c8();
    virtual void vf0c9();
    virtual void vf0ca();
    virtual void vf0cb();
    virtual void vf0cc();
    virtual void vf0cd();
    virtual void vf0ce();
    virtual void vf0cf();
    virtual void vf0d0();
    virtual void vf0d1();
    virtual void vf0d2();
    virtual void vf0d3();
    virtual void vf0d4();
    virtual void vf0d5();
    virtual void vf0d6();
    virtual void vf0d7();
    virtual void vf0d8();
    virtual void vf0d9();
    virtual void vf0da();
    virtual void vf0db();
    virtual void vf0dc();
    virtual void vf0dd();
    virtual void vf0de();
    virtual void vf0df();
    virtual void vf0e0();
    virtual void vf0e1();
    virtual void vf0e2();
    virtual void vf0e3();
    virtual void vf0e4();
    virtual void vf0e5();
    virtual void vf0e6();
    virtual void vf0e7();
    virtual void vf0e8();
    virtual void vf0e9();
    virtual void vf0ea();
    virtual void vf0eb();
    virtual void vf0ec();
    virtual void vf0ed();
    virtual void vf0ee();
    virtual void vf0ef();
    virtual void vf0f0();
    virtual void vf0f1();
    virtual void vf0f2();
    virtual void vf0f3();
    virtual void vf0f4();
    virtual void vf0f5();
    virtual void vf0f6();
    virtual void vf0f7();
    virtual void vf0f8();
    virtual void vf0f9();
    virtual void vf0fa();
    virtual void vf0fb();
    virtual void vf0fc();
    virtual void vf0fd();
    virtual void vf0fe();
    virtual void vf0ff();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf10a();
    virtual void vf10b();
    virtual void vf10c();
    virtual void vf10d();
    virtual void vf10e();
    virtual void vf10f();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual bool IsReady();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf11a();
    virtual void vf11b();
    virtual void vf11c();
    virtual void vf11d();
    virtual void vf11e();
    virtual void vf11f();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf12a();
    virtual void vf12b();
    virtual void vf12c();
    virtual void vf12d();
    virtual void vf12e();
    virtual void vf12f();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf13a();
    virtual void vf13b();
    virtual void vf13c();
    virtual void vf13d();
    virtual void vf13e();
    virtual void vf13f();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf14a();
    virtual void vf14b();
    virtual void Equip(TESObjectWEAP*);
};
struct ActorObj
{
    Proc* GetProcess();
    bool IsBusy();
};
extern ActorObj* player;
struct TargetObj
{
    ActorObj* GetActor();
};
struct Changes
{
    static Changes* GetChanges(ActorObj*);
    ItemData* Find(TESObjectARMO*, bool);
};

// @fnv 0x00808800
void BoundItemEffect::Update(float delta)
{
    if (!m_bModifierActive)
    {
        if (m_fEffectMagnitude >= unka0)
        {
            DoSummon();
            m_bModifierActive = true;
        }
    }
    else
    {
        ActorObj* actor = ((TargetObj*)FUN_0059bb30()) ? ((TargetObj*)FUN_0059bb30())->GetActor() : 0;
        TESObjectWEAP* weaponA = dynamic_cast<TESObjectWEAP*>(((TESForm*)FUN_006733e0()));
        if (actor && actor->GetProcess() && weaponA)
        {
            actor->GetProcess()->Equip(weaponA);
            if (pending && actor->GetProcess()->GetEntry())
            {
                ItemEntry* entry2 = actor->GetProcess()->GetEntry();
                if (weaponA == entry2->GetType() && entry2->GetExtendData())
                {
                    pending = false;
                    ItemData* data = *entry2->GetExtendData()->GetItem();
                    data->SetEquippedState(true);
                }
            }
            if (actor == player && !actor->GetProcess()->IsReady() && !actor->IsBusy())
                Dispel(false);
        }
        else if (pending)
        {
            TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(((TESForm*)FUN_006733e0()));
            if (armor)
            {
                Changes* changes3 = Changes::GetChanges(actor);
                ItemData* data = changes3->Find(armor, true);
                if (data)
                {
                    pending = false;
                    data->SetEquippedState(true);
                }
            }
        }
    }
}

namespace fnv_00809a00 {

struct FormIDEntry;

// 0x004be5a0 (defined in inventorychanges.cpp) returns an inventory entry's save size; the object here is an InventoryStackRecord, not an EffectItem
struct InventoryEntrySaveSizeView

{

    unsigned short __thiscall FUN_004be5a0();
};


extern TESSaveLoadGame* g_TESSaveLoadGame;

struct GlobalObject_0045cf30

{

    unsigned char* __thiscall Bool();
};

extern GlobalObject_0045cf30 g_011de4e8;

extern TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int formID);

extern void __cdecl ProgramFlow(const char* format, ...);

}  // namespace fnv_00809a00

// @fnv 0x00809a00
unsigned short __thiscall BoundItemEffect::GetSaveSize(::Actor* apActor)

{
    using namespace fnv_00809a00;

    unsigned short usSize9 = 0;

    usSize9 += ((AssociatedItemEffect*)this)->AssociatedItemEffect::GetSaveSize((::Actor*)apActor);

    unsigned short usBaseSize8 = usSize9;

    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())

    {

        usSize9 += 4;

        usSize9 += 2;
    }

    usSize9 += 1;

    if (m_pkWeaponEntry != 0)

    {

        usSize9 += ((fnv_00809a00::InventoryEntrySaveSizeView*)m_pkWeaponEntry)->FUN_004be5a0();
    }

    int i6;

    for (i6 = 0; i6 < 20; ++i6)

    {

        usSize9 += 1;

        if (m_apArmorEntries[i6] != 0)

        {

            usSize9 += ((fnv_00809a00::InventoryEntrySaveSizeView*)m_apArmorEntries[i6])->FUN_004be5a0();
        }
    }

    if (g_011de4e8.Bool()[0] != 0)

    {

        FormIDEntry* pHeader = (FormIDEntry*)g_TESSaveLoadGame->FUN_004fd3e0();

        if (pHeader != 0)

        {

            TESForm* pForm = TESForm_GetFormByNumericID(*(unsigned int*)pHeader);

            ProgramFlow("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",

                         usSize9 - usBaseSize8,

                         *(unsigned int*)pHeader,

                         pForm->GetName(),

                         *(unsigned int*)((char*)pHeader + 5),

                         0x29b,

                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\BoundItemEffect.cpp");
        }

        else

        {

            ProgramFlow("GetSaveSize(): %-5i ending at line %i in file %s",

                         usSize9 - usBaseSize8,

                         0x29b,

                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\BoundItemEffect.cpp");
        }
    }

    if (g_TESSaveLoadGame->FUN_008df040() >= 0x41)

    {

        usSize9 += 4;

        usSize9 += 1;
    }

    if (g_TESSaveLoadGame->FUN_008df040() >= 0x6b)

    {

        usSize9 += 1;
    }

    return usSize9;
}

// Adapted from contributor Worker18 (2026-10-23); independently verified and modified.

struct Obj12
{

    Obj12();

    ~Obj12();

    int f00, f04, f08;

    void __thiscall ItemChange_LoadGame();

    int __thiscall FUN_004459e0(int a);
};

struct Sound
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

    virtual int VCall130();
};

struct FUN_008579e0_shell
{

    void __thiscall TESSaveLoadGame_LoadGameDataOLD(void* buf, unsigned int n);
};

struct TimeGlobal : FUN_008579e0_shell
{

    unsigned int __thiscall GetTimeStamp();
};


struct FormHeader
{
    void* formID;
};

extern TESSaveLoadGame* DAT_011de45c;

extern "C" Sound* __cdecl _ref_004839c0(void* a);

void __cdecl Warning_005b5e40(const char* fmt, ...);

int __fastcall FUN_0044ddc0(Obj12* p);

extern char DAT_01015718;

extern char DAT_010156a8;

extern char DAT_01015588;

extern char DAT_01015500;

extern char DAT_010154a0;

extern char DAT_01015440;

extern char DAT_01079810;

// @fnv 0x00809e60
void BoundItemEffect::LoadGame(Actor* apActor)

{

    ((AssociatedItemEffect*)this)->FUN_00806e30(apActor);

    unsigned short w18 = 0;

    int flag = 0;

    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {

        unsigned int i;

        DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&i, 4);

        if (i != 0x424c4f4b)
        {

            FormHeader* rec = (FormHeader*)DAT_011de45c->BGSProjectile_GetExplosion();

            if (rec != 0)
            {

                Sound* pForm;

                pForm = _ref_004839c0(rec->formID);

                Warning_005b5e40(&DAT_01015718, &DAT_01079810, 0x2da, rec->formID, pForm->VCall130(),
                             *(unsigned char*)((char*)rec + 9), *(int*)((char*)rec + 5));
            }
            else
            {

                Warning_005b5e40(&DAT_010156a8, &DAT_01079810, 0x2da, DAT_011de45c->FUN_008df040());
            }
        }

        flag = DAT_011de45c->GetTimeStamp();

        DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&w18, 2);
    }

    unsigned char n1c;

    DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&n1c, 1);

    if (n1c)
    {

        m_pkWeaponEntry = (InventoryStackRecord*)new Obj12;

        ((Obj12*)m_pkWeaponEntry)->ItemChange_LoadGame();
    }

    int rec2 = 0;

    for (; rec2 < 0x14; rec2++)
    {

        DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&n1c, 1);

        if (n1c)
        {

            m_apArmorEntries[rec2] = (InventoryStackRecord*)new Obj12;

            ((Obj12*)m_apArmorEntries[rec2])->ItemChange_LoadGame();

            if (!::FUN_0044ddc0((Obj12*)m_apArmorEntries[rec2]))
            {
                delete (Obj12*)m_apArmorEntries[rec2];
                m_apArmorEntries[rec2] = 0;
            }
        }
    }

    m_bModifierActive = 1;

    if ((int)DAT_011de45c->FUN_008df040() >= 0x41)
    {

        DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&unka0, 4);

        DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&m_bModifierActive, 1);
    }

    if ((int)DAT_011de45c->FUN_008df040() >= 0x6b)
    {

        DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&pending, 1);
    }

    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {

        unsigned int ts;

        ts = DAT_011de45c->GetTimeStamp();

        FormHeader* tag = (FormHeader*)DAT_011de45c->BGSProjectile_GetExplosion();

        if (tag != 0)
        {

            Sound* snd2 = _ref_004839c0(tag->formID);

            if ((unsigned int)ts > (unsigned int)w18 + (unsigned int)flag)
            {

                Warning_005b5e40(&DAT_01015588, (int)((unsigned int)ts - ((unsigned int)w18 + (unsigned int)flag)),
                             &DAT_01079810, 0x302, tag->formID, snd2->VCall130(), *(unsigned char*)((char*)tag + 9),
                             *(int*)((char*)tag + 5));
            }
            else if ((unsigned int)ts < (unsigned int)w18 + (unsigned int)flag)
            {

                Warning_005b5e40(&DAT_01015500, (int)(((unsigned int)w18 + (unsigned int)flag) - (unsigned int)ts),
                             &DAT_01079810, 0x302, tag->formID, snd2->VCall130(), *(unsigned char*)((char*)tag + 9),
                             *(int*)((char*)tag + 5));
            }
        }
        else
        {

            if ((unsigned int)ts > (unsigned int)w18 + (unsigned int)flag)
            {

                Warning_005b5e40(&DAT_010154a0, (int)((unsigned int)ts - ((unsigned int)w18 + (unsigned int)flag)),
                             &DAT_01079810, 0x302, DAT_011de45c->FUN_008df040());
            }
            else if ((unsigned int)ts < (unsigned int)w18 + (unsigned int)flag)
            {

                Warning_005b5e40(&DAT_01015440, (int)(((unsigned int)w18 + (unsigned int)flag) - (unsigned int)ts),
                             &DAT_01079810, 0x302, DAT_011de45c->FUN_008df040());
            }
        }
    }
}

namespace fnv_00809bd0 {
struct SaveHeader
{
    unsigned int id;
    unsigned char unk04;
    unsigned char flags;
};

TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
void __cdecl ProgramFlow(const char*, ...);
void __cdecl FNV_Warning(const char*, ...);
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
struct ValueReferencePair
{
    void ItemChange_SaveGameTES();
};

}  // namespace fnv_00809bd0

// Writes the effect's bound-item references and version-gated fields to the save stream, with optional block header and debug logging.
// @fnv 0x00809bd0
void BoundItemEffect::SaveGame(Actor* arg)
{
    using namespace fnv_00809bd0;
    AssociatedItemEffect::FUN_00806de0((::Actor*)arg);
    bool present;
    int iSlot;
    unsigned short blockSize = 0;
    unsigned int blockStart = 0;
    {
        unsigned int uiTimestamp = g_TESSaveLoadGame->FUN_00825c00();
        if (*g_011de4e8.Bool())
            uiTimestamp = g_TESSaveLoadGame->FUN_00825c00();
        if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned int tag = 0x424c4f4b;
            g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&tag, 4);
            blockStart = g_TESSaveLoadGame->FUN_00825c00();
            g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&blockSize, 2);
        }
        present = false;
        if (m_pkWeaponEntry)
            present = true;
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&present, 1);
        if (present)
            ((ValueReferencePair*)m_pkWeaponEntry)->ItemChange_SaveGameTES();
        for (iSlot = 0; iSlot < 20; iSlot++)
        {
            present = false;
            if (m_apArmorEntries[iSlot])
                present = true;
            g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&present, 1);
            if (present)
                ((ValueReferencePair*)m_apArmorEntries[iSlot])->ItemChange_SaveGameTES();
        }
        if (g_TESSaveLoadGame->FUN_008df040() >= 65)
        {
            g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&unka0, 4);
            g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_bModifierActive, 1);
        }
        if (g_TESSaveLoadGame->FUN_008df040() >= 107)
            g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&pending, 1);
        if (*g_011de4e8.Bool())
        {
            unsigned int uiHeaderPos = g_TESSaveLoadGame->FUN_00825c00();
            SaveHeader* pSaveHeader = (SaveHeader*)g_TESSaveLoadGame->FUN_004fd3e0();
            if (pSaveHeader)
            {
                TESForm* form = TESForm_GetFormByNumericID(pSaveHeader->id);
                ProgramFlow("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                             uiHeaderPos - uiTimestamp, pSaveHeader->id, form->GetName(),
                             *(unsigned int*)&pSaveHeader->flags, 721,
                             "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\BoundItemEffect.cpp");
            }
            else
            {
                ProgramFlow("SaveGame(): %-5i ending at line %i in file %s", uiHeaderPos - uiTimestamp, 721,
                             "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\BoundItemEffect.cpp");
            }
        }
        if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned int uiFinishPos = g_TESSaveLoadGame->FUN_00825c00();
            unsigned int uiBeginPos = blockStart;
            if (uiFinishPos > uiBeginPos + 65535)
                FNV_Warning("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Magic\\BoundItemEffect.cpp", 721);
            *(unsigned short*)blockStart = (unsigned short)(uiFinishPos - uiBeginPos);
        }
    }
}

struct BIItemData
{
    void ExtraDataList_RemoveCannotWearExtra();
    void ExtraDataList_ClearScriptLocals();
};
struct BIItemNode
{
    BIItemData** FUN_006815c0();
};

struct BIEntry
{
    BIItemNode* Modelloader_GetReferencedThis();
    TESBoundObject* FUN_0044ddc0();
    void ClearExtraDataList();
    ~BIEntry();
};

struct BIChanges
{
    BIItemData* FUN_004bfda0(void* pkForm, int iFlag);
};
struct BIWornList
{
    BIEntry* InventoryChanges_GetWornItem();
};
struct BIWornSlot
{
    BIWornList* FUN_00418520();
};

class BIProcess
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void SetDirty(int iFlag);  // +0x450
    int FUN_0045cd60();
};

struct BISound
{
    unsigned int m_uiID;
    unsigned int m_uiState;
    unsigned int m_uiValue1;
    ~BISound();
};

class BIActor
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void UnequipItem(void* pkForm, int iA, int iB, int iC, int iD, int iE, int iF, int iG, int iH,
                             int iI);  // +0x17c
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual int IsAlive();  // +0x1d0
    void QueueUnEquipObject(void* pkForm, int iA, int iB, int iC, int iD, int iE);
    int FUN_00575610(TESBoundObject* pkBase);
    void Actor_QueueEquipObject(TESBoundObject* pkBase, int iA, int iB, int iC, int iD, int iE);
    BIWornSlot* BSFile_GetDevice(int iSlot, int iFlag);
    TESBoundObject* BGSSaveFormBuffer_GetForm();
    BIProcess* FUN_008d8520();
    BISound FUN_00933270(const char* pcName, int iA, unsigned int uiFlags, int iB);
};

struct BINode
{
    BINode* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

class BIShader
{
  public:
    BIShader(BIActor* pkActor, const char* pcModel, float fTime);
    virtual ~BIShader();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual bool Init();  // +0xc4
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    int unk04[14];
};

struct BIModelLoader
{
    void ModelLoader_ReleaseModel(const char* pcPath, int iA, int iB);
};
struct BIShaderManager
{
    void ProcessLists_AddTempEffect(BIShader* pkShader);
};
extern BIModelLoader* DAT_011c3b3c;
extern BIShaderManager DAT_011e0e80;

struct BITarget
{
    BIActor* FUN_00822b40();
};

BIChanges* FUN_004bf220(BIActor* pkActor);
bool BoundItemEffect_FindConflictingBoundItems(BIActor* pkActor, BIEntry* pkEntry, void* pkEffect);

// The shared headers do not yet declare this state-setting helper.
struct EffectStateSetter
{
    void FUN_007037c0(int iFlag);
};

// @fnv 0x008091a0
void BoundItemEffect::Finish()
{
    BIActor* pkActor = FUN_0059bb30() ? ((BITarget*)FUN_0059bb30())->FUN_00822b40() : 0;
    if (m_bModifierActive && pkActor)
    {
        TESObjectWEAP* pkWeapon = dynamic_cast<TESObjectWEAP*>((TESForm*)FUN_006733e0());
        TESObjectARMO* pkArmorRes = dynamic_cast<TESObjectARMO*>((TESForm*)FUN_006733e0());
        if (pkWeapon)
        {
            BIItemData* pkData = 0;
            BIChanges* pkChanges = FUN_004bf220(pkActor);
            pkData = pkChanges->FUN_004bfda0(pkWeapon, 0);
            if (pkData)
                pkData->ExtraDataList_RemoveCannotWearExtra();
            pkActor->QueueUnEquipObject(pkWeapon, 1, 0, 0, 0, 1);
            pkActor->UnequipItem(pkWeapon, 0, 1, 0, 0, 0, 0, 0, 1, 0);
            if (m_pkWeaponEntry)
            {
                bool bEquipped = false;
                pkData = ((BIEntry*)m_pkWeaponEntry)->Modelloader_GetReferencedThis() ? *((BIEntry*)m_pkWeaponEntry)->Modelloader_GetReferencedThis()->FUN_006815c0() : 0;
                if (pkActor->FUN_00575610(((BIEntry*)m_pkWeaponEntry)->FUN_0044ddc0()) >= 1)
                {
                    bEquipped = true;
                    pkActor->Actor_QueueEquipObject(((BIEntry*)m_pkWeaponEntry)->FUN_0044ddc0(), 1, 0, 1, 0, 1);
                }
                if (m_bLoadWeaponModel)
                {
                    TESBoundObject* pkBase = ((BIEntry*)m_pkWeaponEntry)->FUN_0044ddc0();
                    TESObjectWEAP* pkOldWeapon = dynamic_cast<TESObjectWEAP*>(pkBase);
                    if (pkOldWeapon && ((const TESModel*)((const char*)&pkOldWeapon->m_kModelFilePath - sizeof(void*)))->GetModelLength() > 0)
                        DAT_011c3b3c->ModelLoader_ReleaseModel(pkOldWeapon->GetModelFilePath(), 0, 1);
                    m_bLoadWeaponModel = false;
                }
                if (pkData)
                    pkData->ExtraDataList_ClearScriptLocals();
                ((BIEntry*)m_pkWeaponEntry)->ClearExtraDataList();
                delete (BIEntry*)m_pkWeaponEntry;
                m_pkWeaponEntry = 0;
                pkActor->FUN_008d8520()->SetDirty(1);
            }
        }
        else if (pkArmorRes)
        {
            int iSexCur = 0;
            TESNPC* pkNPC = dynamic_cast<TESNPC*>(pkActor->BGSSaveFormBuffer_GetForm());
            if (pkNPC)
                iSexCur = pkNPC->GetSex();
            BIItemData* pkArmorData = 0;
            BIChanges* pkArmorChanges = FUN_004bf220(pkActor);
            pkArmorData = pkArmorChanges->FUN_004bfda0(pkArmorRes, 0);
            if (pkArmorData)
                pkArmorData->ExtraDataList_RemoveCannotWearExtra();
            pkActor->QueueUnEquipObject(pkArmorRes, 1, 0, 0, 0, 1);
            pkActor->UnequipItem(pkArmorRes, 0, 1, 0, 0, 0, 0, 0, 1, 0);
            for (int i = 0; i < 0x14; i++)
            {
                if (pkArmorRes->FUN_00480af0(i, 0, 0) && m_apArmorEntries[i])
                {
                    BIEntry* pkEntry = (BIEntry*)m_apArmorEntries[i];
                    BIItemData* pkEntryData = 0;
                    if (pkEntry->Modelloader_GetReferencedThis())
                        pkEntryData = *pkEntry->Modelloader_GetReferencedThis()->FUN_006815c0();
                    if (pkEntry)
                    {
                        bool bKeepModel = false;
                        bool bEquipped = false;
                        if (pkActor->FUN_00575610(pkEntry->FUN_0044ddc0()) >= 1)
                        {
                            pkActor->Actor_QueueEquipObject(pkEntry->FUN_0044ddc0(), 1, 0, 1, 0, 1);
                            BIEntry* pkWorn = pkActor->BSFile_GetDevice(i, 0)->FUN_00418520()->InventoryChanges_GetWornItem();
                            if (!pkWorn || pkWorn->FUN_0044ddc0() != pkEntry->FUN_0044ddc0())
                                bKeepModel = BoundItemEffect_FindConflictingBoundItems(pkActor, pkEntry, this);
                            delete pkWorn;
                            bEquipped = true;
                        }
                        if (m_bLoadArmorModel && pkEntry->FUN_0044ddc0() && !bKeepModel)
                        {
                            TESBipedModelForm* pkBiped = dynamic_cast<TESBipedModelForm*>(pkEntry->FUN_0044ddc0());
                            if (pkBiped)
                                DAT_011c3b3c->ModelLoader_ReleaseModel(pkBiped->GetBipedModel(iSexCur), 0, 1);
                        }
                        if (pkEntryData)
                            pkEntryData->ExtraDataList_ClearScriptLocals();
                        pkEntry->ClearExtraDataList();
                        delete pkEntry;
                        pkEntry = 0;
                    }
                    m_apArmorEntries[i] = 0;
                }
            }
            m_bLoadArmorModel = false;
        }
        if (pkActor->IsAlive() && pkActor->FUN_008d8520() && !pkActor->FUN_008d8520()->FUN_0045cd60() &&
            FUN_0044ddc0() && GetHavokWorldObjectCountInSceneGraph_0084e3a0())
        {
            EffectSetting* pkModelOut = (EffectSetting*)FUN_0044ddc0()->FUN_0040a300(0);
            void* pvFound = FUN_0044ddc0()->FindCostliestEffectItem((int)((BINode*)GetHavokWorldObjectCountInSceneGraph_0084e3a0())->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), 0);
            if (GetHavokWorldObjectCountInSceneGraph_0084e3a0() == pvFound)
            {
                if (((const TESModel*)((const char*)FUN_007df1d0() + sizeof(TESForm)))->GetModelLength() > 0)
                {
                    BIShader* pkShader = 0;
                    pkShader = new BIShader(pkActor, pkModelOut->GetModelFilePath(), -1.0f);
                    if (pkShader->Init())
                        DAT_011e0e80.ProcessLists_AddTempEffect(pkShader);
                    else
                        delete pkShader;
                    if (m_bShowShader)
                    {
                        DAT_011c3b3c->ModelLoader_ReleaseModel(pkModelOut->GetModelFilePath(), 0, 1);
                        m_bShowShader = false;
                    }
                }
                pkActor->FUN_00933270("ITMBoundDisappear", 0, 0x40000102, 1);
            }
        }
        ((EffectStateSetter*)this)->FUN_007037c0(0);
        m_bModifierActive = false;
    }
}

class NiNode;
namespace fnv_00808680 {

// Local ModelLoader declarations retained: include/ModelLoader.h is not available.
class ModelLoader
{
  public:
    NiNode* LoadFile(const char* pPath, int iLOD, bool bUnk1, bool bUnk2, bool bUnk3, bool bUnk4);
    void ModelLoader_ReleaseModel(const char* pPath, bool bUnk, unsigned int uiUnk);
};
extern const char kMagicModelHitEffectName[];
extern const char g_011d4c84_arg1[];
float __cdecl GetAnimValueByPrefix(NiNode* pNode, const char* pName, const char* pArg);

// Loads the model, sets fHitEffectTime from FUN_004b6220 for non-type-4 items with a node, and calls FUN_00445300 when the selected range item differs.
}  // namespace fnv_00808680

// @fnv 0x00808680
void BoundItemEffect::Start()
{
    using namespace fnv_00808680;
    void* pTarget = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    if (!FUN_006733e0() || !pTarget)
    {
        Dispel(false);
        return;
    }
    if (FUN_0044ddc0() && GetHavokWorldObjectCountInSceneGraph_0084e3a0())
    {
        EffectSetting* pBaseEffect = (EffectSetting*)FUN_0044ddc0()->FUN_0040a300(0);
        ::EffectItem* pRangeItem = FUN_0044ddc0()->FindCostliestEffectItem(((EffectItem*)GetHavokWorldObjectCountInSceneGraph_0084e3a0())->GetRange(), 0);
        if (((const TESModel*)((const char*)pBaseEffect + sizeof(TESForm)))->GetModelLength() > 0)
        {
            ::NiNode* pNode = ((ModelLoader*)g_modelLoader)
                                ->LoadFile(pBaseEffect->GetModelFilePath(), 0, true, false, false, false);
            bool bIsType4 = FUN_0044ddc0()->GetSpellType() == 4;
            if (!bIsType4)
            {
                if (pNode)
                    unka0 = GetAnimValueByPrefix(pNode, kMagicModelHitEffectName, g_011d4c84_arg1);
            }
            else
            {
                unka0 = 0.0f;
            }
            if (GetHavokWorldObjectCountInSceneGraph_0084e3a0() != pRangeItem)
                ((ModelLoader*)g_modelLoader)->ModelLoader_ReleaseModel(pBaseEffect->GetModelFilePath(), false, 1);
        }
    }
}

struct ExtraP;
struct ExtraListP
{
    ExtraP** FUN_006815c0();
    void FUN_005ae3d0(ExtraP**);
    void RemoveMatchingItem(ExtraP**);
};
struct ExtraP
{
    unsigned int BaseExtraList_ItemsInList();
    short ExtraDataList_GetCount();
    void ExtraDataList_SetCanNotWear(int);
    void FUN_0041b010(int);
    bool FUN_004bca60();
};
struct EntryP
{
    ExtraListP* list;
    ~EntryP();
    TESBoundObject* FUN_0044ddc0();
    ExtraListP* Modelloader_GetReferencedThis();
    void* FUN_004459e0(int);
};
struct ProcessP
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual EntryP* Equipped();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void Update(int);
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void SetWeapon(TESObjectWEAP*);
};
struct InvP
{
    EntryP* InventoryChanges_GetWornItem(int, int);
};
struct InvHolderP
{
    InvP* FUN_00418520();
};
struct ActorP
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void AddItem(TESBoundObject*, ExtraP*, int);
    ProcessP* FUN_008d8520();
    TESBoundObject* BGSSaveFormBuffer_GetForm();
    InvHolderP* BSFile_GetDevice();
    void QueueUnEquipObject(TESBoundObject*, int, ExtraP*, int, int, int);
    void Actor_QueueEquipObject(TESBoundObject*, int, int, int, int, int);
};
struct CasterP
{
    ActorP* FUN_00822b40();
};
struct ModelLoaderP
{
    void ModelLoader_LoadFile(const char*, int, int, int, int, int);
};

struct FUN_00410360 : ExtraP
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    FUN_00410360();
    static void* operator new(unsigned int n)
    {
        return FormHeap_Allocate(n);
    }
    static void operator delete(void*);
    void ExtraDataList_DuplicateExtraListForContainer(ExtraP*);
};
struct FUN_004bc550 : EntryP
{
    int u04, u08;
    FUN_004bc550(TESBoundObject*, int);
    static void* operator new(unsigned int n)
    {
        return FormHeap_Allocate(n);
    }
    static void operator delete(void*);
};
struct FUN_004bc650 : EntryP
{
    int u04, u08;
    FUN_004bc650(EntryP*);
    static void* operator new(unsigned int n)
    {
        return FormHeap_Allocate(n);
    }
    static void operator delete(void*);
};

struct EquipManagerP
{
    ExtraP* FUN_004bfda0(TESObjectARMO*, int);
};
EquipManagerP* __cdecl FUN_004bf220(ActorP*);

// Applies the effect by equipping the weapon or armor form on the caster actor, loading models and updating the equip manager.
// @fnv 0x00808a30
// src: XBOX_PDB 0x00808a30
void BoundItemEffect::DoSummon()
{
    TESObjectARMO* armor;
    ActorP* weapon = FUN_0059bb30() ? ((CasterP*)FUN_0059bb30())->FUN_00822b40() : 0;
    TESObjectWEAP* actor = dynamic_cast<TESObjectWEAP*>((TESForm*)FUN_006733e0());
    armor = dynamic_cast<TESObjectARMO*>((TESForm*)FUN_006733e0());
    if (actor)
    {
        if (weapon->FUN_008d8520()->Equipped())
        {
            ExtraP* old = 0;
            old = *weapon->FUN_008d8520()->Equipped()->list->FUN_006815c0();
            if (old->BaseExtraList_ItemsInList() < 2 || old->BaseExtraList_ItemsInList() == 2 && old->ExtraDataList_GetCount() > 1)
                old = 0;
            TESBoundObject* extra = weapon->FUN_008d8520()->Equipped()->FUN_0044ddc0();
            if (extra && !m_bLoadWeaponModel)
            {
                TESObjectWEAP* oldWeapon = dynamic_cast<TESObjectWEAP*>(extra);
                if (oldWeapon && ((const TESModel*)((const char*)&oldWeapon->m_kModelFilePath - sizeof(void*)))->GetModelLength() > 0)
                {
                    ((ModelLoaderP*)DAT_011c3b3c)->ModelLoader_LoadFile(oldWeapon->GetModelFilePath(), 0, 1, 0, 0, 0);
                    m_bLoadWeaponModel = true;
                }
            }
            weapon->QueueUnEquipObject(weapon->FUN_008d8520()->Equipped()->FUN_0044ddc0(), 1,
                                 *weapon->FUN_008d8520()->Equipped()->list->FUN_006815c0(), 0, 0, 1);
            m_pkWeaponEntry = (InventoryStackRecord*)new FUN_004bc550(extra, 0);
            if (old)
            {
                FUN_00410360* copied = new FUN_00410360;
                copied->ExtraDataList_DuplicateExtraListForContainer(old);
                ((EntryP*)m_pkWeaponEntry)->list->FUN_005ae3d0((ExtraP**)&copied);
            }
        }
        weapon->AddItem(actor, 0, 1);
        if (!weapon->FUN_008d8520()->Equipped() || weapon->FUN_008d8520()->Equipped()->FUN_0044ddc0() != actor)
            weapon->Actor_QueueEquipObject(actor, 1, 0, 1, 1, 1);
        ExtraP* newExtra = 0;
        if (weapon->FUN_008d8520() && weapon->FUN_008d8520()->Equipped() &&
            weapon->FUN_008d8520()->Equipped()->Modelloader_GetReferencedThis())
        {
            newExtra = *weapon->FUN_008d8520()->Equipped()->Modelloader_GetReferencedThis()->FUN_006815c0();
            newExtra->ExtraDataList_SetCanNotWear(1);
        }
        else
            pending = true;
        weapon->FUN_008d8520()->Update(1);
        weapon->FUN_008d8520()->SetWeapon(actor);
    }
    else if (armor)
    {
        int manager = 0;
        TESNPC* sex = dynamic_cast<TESNPC*>(weapon->BGSSaveFormBuffer_GetForm());
        if (sex)
            manager = sex->FUN_005f0cc0();
        bool worn = m_bLoadArmorModel;
        for (int slot = 0; slot < 20; slot++)
        {
            EntryP* entry = 0;
            if (armor->FUN_00480af0(slot, 0, 0))
            {
                InvP* inventory = weapon->BSFile_GetDevice()->FUN_00418520();
                if (inventory)
                    entry = inventory->InventoryChanges_GetWornItem(slot, 0);
            }
            if (entry)
            {
                if (entry->FUN_0044ddc0() && !worn)
                {
                    TESBipedModelForm* biped = dynamic_cast<TESBipedModelForm*>(entry->FUN_0044ddc0());
                    if (biped)
                    {
                        ((ModelLoaderP*)DAT_011c3b3c)
                            ->ModelLoader_LoadFile(biped->GetBipedModel(manager), 0, 1, 0, 0, 0);
                        m_bLoadArmorModel = true;
                    }
                }
                ExtraP* data = *entry->list->FUN_006815c0();
                if (data)
                {
                    data->FUN_0041b010(0);
                    if (data->FUN_004bca60())
                        entry->Modelloader_GetReferencedThis()->RemoveMatchingItem(&data);
                }
                m_apArmorEntries[slot] = (InventoryStackRecord*)new FUN_004bc650(entry);
                delete entry;
            }
        }
        ExtraP* npc = new FUN_00410360;
        weapon->AddItem((TESBoundObject*)armor, npc, 1);
        weapon->Actor_QueueEquipObject((TESBoundObject*)armor, 1, 0, 1, 0, 1);
        EquipManagerP* preload = FUN_004bf220(weapon);
        npc = preload->FUN_004bfda0(armor, 1);
        if (npc)
            npc->ExtraDataList_SetCanNotWear(1);
        else
            pending = true;
    }
    else
        Dispel(false);
}

struct BoundSlotItem
{
    BoundSlotItem(BIEntry* apRef);
    int unk00;
    int unk04;
    int unk08;
};


// Finds a free armor slot shared by apRef and a bound-armor effect on apActor, storing a BoundSlotItem and returning true.
// @fnv 0x0080a700
// src: XBOX_PDB 0x0080a700
bool BoundItemEffect_FindConflictingBoundItems(BIActor* apActor, BIEntry* apRef, void* apExclude)
{
    TESBipedModelForm* pBiped5 = apRef ? dynamic_cast<TESBipedModelForm*>(apRef->FUN_0044ddc0()) : 0;
    if (!apActor || !pBiped5)
    {
        return false;
    }
    BSSimpleList<ActiveEffect*>* pNode2 = static_cast<MagicTarget*>((Actor*)apActor)->GetActiveEffectList();
    while (pNode2 && !pNode2->IsEmpty())
    {
        ActiveEffect* pEffect = pNode2->GetItem();
        BoundItemEffect* pBound6 = dynamic_cast<BoundItemEffect*>(pEffect);
        if (pBound6 && (void*)pBound6 != apExclude)
        {
            TESObjectARMO* aPArmor = dynamic_cast<TESObjectARMO*>((TESForm*)pBound6->FUN_006733e0());
            if (aPArmor)
            {
                for (int i4 = 0; i4 < 20; i4++)
                {
                    if (pBiped5->FUN_00480af0(i4, 0, 0) &&
                        aPArmor->FUN_00480af0(i4, 0, 0) && !pBound6->m_apArmorEntries[i4])
                    {
                        pBound6->m_apArmorEntries[i4] = (InventoryStackRecord*)new BoundSlotItem(apRef);
                        return true;
                    }
                }
            }
        }
        pNode2 = pNode2->GetNext();
    }
    return false;
}

struct EntryA
{
    TESBoundObject* FUN_0044ddc0();
    void FUN_004bed00();
    ~EntryA();
};
struct InventoryA
{
    int FUN_004c8f30(TESBoundObject*);
};
struct ExtraA
{
    InventoryA* FUN_00418520();
};
struct ActorA
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void Equip(TESBoundObject*, int, int);
    TESBoundObject* BGSSaveFormBuffer_GetForm();
    ExtraA* BSFile_GetDevice();
    void QueueUnEquipObject(TESBoundObject*, int, int, int, int, int);
    void Actor_QueueEquipObject(TESBoundObject*, int, int, int, int, int);
};
struct TargetA
{
    ActorA* FUN_00822b40();
};
struct ModelLoaderA
{
    void ModelLoader_QueueModel_00444040(const char*, int, int, int, int, int, int);
};

// Loads saved weapon and armor models, upgrades older entries, and equips the bound object.
// @fnv 0x0080a2d0
void BoundItemEffect::InitLoadGame(Actor* arg)
{
    int actor;
    AssociatedItemEffect::FUN_00806e70((::Actor*)arg);
    ActorA* j = FUN_0059bb30() ? ((TargetA*)FUN_0059bb30())->FUN_00822b40() : 0;
    if (m_bModifierActive)
    {
        if (m_pkWeaponEntry)
        {
            TESBoundObject* object = ((EntryA*)m_pkWeaponEntry)->FUN_0044ddc0();
            TESObjectWEAP* pWeapon = dynamic_cast<TESObjectWEAP*>(object);
            if (pWeapon && ((const TESModel*)((const char*)&pWeapon->m_kModelFilePath - sizeof(void*)))->GetModelLength() > 0)
            {
                m_bLoadWeaponModel = true;
                ((ModelLoaderA*)DAT_011c3b3c)->ModelLoader_QueueModel_00444040(pWeapon->GetModelFilePath(), 0, 0, 0, 1, 0, 0);
            }
        }
        int sex = 0;
        if (j)
        {
            TESNPC* npc = dynamic_cast<TESNPC*>(j->BGSSaveFormBuffer_GetForm());
            if (npc)
                sex = npc->FUN_005f0cc0();
        }
        for (int i = 0; i < 20; i++)
        {
            if (m_apArmorEntries[i] && ((EntryA*)m_apArmorEntries[i])->FUN_0044ddc0())
            {
                TESBipedModelForm* biped = dynamic_cast<TESBipedModelForm*>(((EntryA*)m_apArmorEntries[i])->FUN_0044ddc0());
                if (biped)
                {
                    m_bLoadArmorModel = true;
                    ((ModelLoaderA*)DAT_011c3b3c)->ModelLoader_QueueModel_00444040(biped->GetBipedModel(sex), 0, 0, 0, 1, 1, 0);
                }
            }
        }
    }
    if (m_pkWeaponEntry)
    {
        ((EntryA*)m_pkWeaponEntry)->FUN_004bed00();
        if (DAT_011de45c->FUN_008df040() < 0x61)
        {
            EntryA* pWeaponCopy = (EntryA*)new FUN_004bc650((EntryP*)m_pkWeaponEntry);
            delete (EntryA*)m_pkWeaponEntry;
            m_pkWeaponEntry = (InventoryStackRecord*)pWeaponCopy;
        }
        j->QueueUnEquipObject(((EntryA*)m_pkWeaponEntry)->FUN_0044ddc0(), 1, 0, 0, 0, 1);
    }
    for (actor = 0; actor < 20; actor++)
    {
        if (m_apArmorEntries[actor])
        {
            ((EntryA*)m_apArmorEntries[actor])->FUN_004bed00();
            if (DAT_011de45c->FUN_008df040() < 0x61)
            {
                EntryA* pArmorCopy = (EntryA*)new FUN_004bc650((EntryP*)m_apArmorEntries[actor]);
                delete (EntryA*)m_apArmorEntries[actor];
                m_apArmorEntries[actor] = (InventoryStackRecord*)pArmorCopy;
            }
            j->QueueUnEquipObject(((EntryA*)m_apArmorEntries[actor])->FUN_0044ddc0(), 1, 0, 0, 0, 1);
        }
    }
    if (m_bModifierActive)
    {
        InventoryA* item = j->BSFile_GetDevice()->FUN_00418520();
        TESBoundObject* pBoundForm = dynamic_cast<TESBoundObject*>((TESForm*)FUN_006733e0());
        if (item && !item->FUN_004c8f30(pBoundForm))
        {
            j->Equip(pBoundForm, 0, 1);
            j->Actor_QueueEquipObject(pBoundForm, 1, 0, 1, 0, 1);
        }
    }
}
