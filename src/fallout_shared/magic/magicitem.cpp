// fallout_shared/magic/magicitem.cpp: MagicItem and model loading helpers (18 functions)

#include "layout_support.h"
#define FNV64_BSSIMPLELIST_DEFINED
#include "../../../include/NiFile.h"
#include "../../../include/TESSound.h"
#include "../../../include/MagicItem.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/EffectItem.h"
#include "../../../include/MagicItemForm.h"
#include "../../../include/MagicItemObject.h"
#include "../../../include/TESCreature.h"
#include "../../../include/TESAnimation.h"
#include "../../../include/TESBipedModelForm.h"
#include "../../../include/TESModel.h"
#include "../../../include/TESObjectARMO.h"
#include "../../../include/TESObjectWEAP.h"
#include "../../../include/TESModelList.h"
#include "../../../include/TESNPC.h"

FNV_STATIC_ASSERT(sizeof(TESForm) == 0x18);

FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 0x30);

FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);

FNV_STATIC_ASSERT(sizeof(TESModel) == 0x18);

FNV_STATIC_ASSERT(sizeof(EffectItemList) == 0x10);

FNV_STATIC_ASSERT(sizeof(MagicItem) == 0x1C);

class Model
{
  public:
    void SetManualRefCount(int);
    void Model_IncManualRefCount();
    const char* Modelloader_GetReferencedThis();
};
class KFModel;
class ModelLoader
{
  public:
    void QueueMagicEffectModel(MagicItem*, EffectSetting*, int);
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
    bool ModelLoader_FindModel(const char*, NiPointer<Model>&);
    KFModel* LoadKF(const char*);
    BSSimpleList<const char*>* GetModelFileList(const char*, bool, bool, int);
};
void MagicItem_IncrementGlobalCounter();
extern ModelLoader* g_modelLoader;
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
// Game path concatenation helper at 0x00406d50.
int AppendModelPath(char*, unsigned int, const char*);
char* strrchr_0040ab30(char*, int);
extern "C" const char* strrchr(const char*, int);
extern "C" int _strnicmp(const char*, const char*, unsigned int);
extern "C" void FormHeapFreeAndLog(const void*);

// Looks up the TESForm for auiID and returns it cast to MagicItemForm or MagicItemObject, otherwise null.
// @fnv 0x0040a250
MagicItem* MagicItem::GetMagicItemByID(unsigned int auiID)
{
    MagicItemObject* pObject;
    TESForm* pForm;
    MagicItemForm* pFormItem;
    pForm = TESForm::GetFormByID(auiID);
    if (pForm)
    {
        pFormItem = dynamic_cast<MagicItemForm*>(pForm);
        pObject = dynamic_cast<MagicItemObject*>(pForm);
        if (pFormItem)
            return pFormItem;
        if (pObject)
            return pObject;
    }
    return 0;
}

// Initializes every EffectItem in the list with apForm and counts how many are hostile, storing the count.
// @fnv 0x0040c030
void MagicItem::LoadEffectsFromForm(TESForm* apForm)
{
    EffectItemList* pIter = this;
    m_iEffectCount = 0;
    while (pIter)
    {
        if (EffectItem* pItem = pIter->GetItem())
        {
            pItem->InitItem(apForm);
            if (pItem->IsHostile())
                m_iEffectCount++;
        }
        pIter = (EffectItemList*)pIter->GetNext();
    }
}

// @fnv 0x0040b470
bool MagicItem::IsLoaded()
{
    EffectSetting* pSelfEffectSetting = GetEffectSettingForRange(MagicSystem::SELF);
    if (pSelfEffectSetting && pSelfEffectSetting->TESModel::GetModelLength() > 0 && !pSelfEffectSetting->IsModelLoaded())
        return false;

    EffectItemList* pIter = this;
    if (!pIter->IsEmpty())
    {
        while (pIter)
        {
            EffectItem* pItem = pIter->GetItem();
            EffectSetting* pEffect = pItem ? pItem->GetEffectSetting() : 0;
            if (pEffect && pEffect->IsAssociatedFormUsed() && !pEffect->HasEffectID())
                return false;
            pIter = (EffectItemList*)pIter->GetNext();
        }
    }
    return true;
}

// Scans the effect list for the best non-detrimental effect by range then cost and returns its EffectSetting, or null if none.
// @fnv 0x0040a300
EffectSetting* MagicItem::GetEffectSettingForRange(MagicSystem::Range aeRange)
{
    struct BestEffect
    {
        MagicSystem::Range range;
        EffectItem* item;
        int cost;
    } best;
    EffectItemList* pIter;
    best.item = 0;
    pIter = this;
    if (pIter->IsEmpty())
        return 0;
    best.cost = -1;
    best.range = aeRange;
    while (pIter)
    {
        struct CurrentEffect
        {
            EffectItem* item;
            int cost;
            MagicSystem::Range range;
        } current;
        current.item = pIter->GetItem();
        current.cost = static_cast<int>(current.item->GetCost(0));
        current.range = static_cast<MagicSystem::Range>(current.item->GetRange());
        if (!current.item->IsDetrimental() &&
            (current.range > best.range || (current.range == best.range && current.cost > best.cost)))
        {
            best.item = current.item;
            best.cost = current.cost;
            best.range = static_cast<MagicSystem::Range>(current.item->GetRange());
        }
        pIter = (EffectItemList*)pIter->GetNext();
    }
    return best.item ? best.item->GetEffectSetting() : 0;
}

// @fnv 0x0040b6b0
bool MagicItem::IsLoading()
{
    EffectSetting* pSelfEffectSetting = GetEffectSettingForRange(MagicSystem::SELF);
    {
        bool m_bHeaderParsed = true;
        if (pSelfEffectSetting && pSelfEffectSetting->TESModel::GetModelLength() > 0 && !pSelfEffectSetting->IsModelLoaded())
        {
            m_bHeaderParsed = false;
            if (!pSelfEffectSetting->HasNoAssociatedActorValue())
                return false;
        }
        EffectItemList* pIter = this;
        if (!pIter->IsEmpty())
        {
            while (pIter)
            {
                EffectItem* pItem = pIter->GetItem();
                EffectSetting* pEffect = pItem ? pItem->GetEffectSetting() : 0;
                if (pEffect && pEffect->IsAssociatedFormUsed() && !pEffect->HasEffectID())
                {
                    m_bHeaderParsed = false;
                    if (!pEffect->UsesAssociatedActorValue())
                        return false;
                }
                pIter = (EffectItemList*)pIter->GetNext();
            }
        }
        if (m_bHeaderParsed)
            return false;
        return true;
    }
}

// @fnv 0x0040a420
void MagicItem::Preload(bool immediate)
{
    EffectSetting* pSelfEffectSetting = GetEffectSettingForRange(MagicSystem::SELF);
    bool bProceed = false;
    bool bLoad = false;
    if (immediate || IsLoaded())
    {
        bProceed = true;
        bLoad = true;
    }
    else if (IsLoading())
    {
        bProceed = true;
        bLoad = false;
    }
    if (!bProceed)
    {
        g_modelLoader->QueueMagicEffectModel(this, pSelfEffectSetting, 0);
        return;
    }
    if (pSelfEffectSetting)
    {
        if (bLoad && pSelfEffectSetting->TESModel::GetModelLength() > 0)
            g_modelLoader->LoadFile(pSelfEffectSetting->GetModelFilePath(), 0, true, false, false, false);
        pSelfEffectSetting->IncEffectLoadedCount();
    }
    EffectItemList* pIter = this;
    if (!pIter->IsEmpty())
    {
        while (pIter)
        {
            struct CurrentEffect
            {
                EffectItem* item;
                EffectSetting* effect;
            } current;
            current.item = pIter->GetItem();
            current.effect = current.item->GetEffectSetting();
            if (current.effect->IsAssociatedFormUsed())
            {
                if (bLoad)
                {
                    TESForm* form = current.effect->FUN_005f5f80();
                    if (form && current.effect->IsFlagSet_00403e60(0x10000))
                    {
                        TESObjectWEAP* weapon = dynamic_cast<TESObjectWEAP*>(form);
                        // Address the TESModel base from shared layout without nullable base-cast temporaries.
                        if (weapon && weapon->TESModel::GetModelLength() > 0)
                            g_modelLoader->LoadFile(
                                reinterpret_cast<TESModel*>(reinterpret_cast<char*>(weapon) +
                                    offsetof(TESObjectWEAP, m_kModelFilePath) -
                                    offsetof(TESModel, m_kModelFilePath))->GetModelFilePath(),
                                0, true, false, false, false);
                    }
                    else if (form && current.effect->IsFlagSet_00403e60(0x20000))
                    {
                        TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(form);
                        if (armor)
                        {
                            g_modelLoader->LoadFile(armor->GetBipedModel(0), 0, true, false, false, false);
                            g_modelLoader->LoadFile(armor->GetBipedModel(1), 0, true, false, false, false);
                        }
                    }
                    else if (form && current.effect->IsFlagSet_00403e60(0x40000))
                    {
                        TESNPC* pNPC = dynamic_cast<TESNPC*>(form);
                        if (pNPC)
                        {
                            struct ModelFileIteration
                            {
                                BSSimpleList<const char*>* list;
                                BSSimpleList<const char*>* iter;
                            } modelFiles;
                            modelFiles.list = pNPC->GetModelFiles(true, true);
                            modelFiles.iter = modelFiles.list;
                            while (modelFiles.iter && !modelFiles.iter->IsEmpty())
                            {
                                const char* filename = modelFiles.iter->GetItem();
                                g_modelLoader->LoadFile(filename, 0, true, false, false, false);
                                modelFiles.iter = modelFiles.iter->GetNext();
                            }
                            modelFiles.list->RemoveAll();
                            delete modelFiles.list;
                        }
                        TESCreature* creature = dynamic_cast<TESCreature*>(form);
                        if (creature)
                        {
                            g_modelLoader->LoadFile(creature->GetModelFilePath(), 0, true, false, false, false);
                            struct ModelPaths
                            {
                                BSSimpleList<const char*>* node;
                                const char* base;
                                BSSimpleList<const char*>* files;
                                char* slash;
                                const char* filename;
                            } modelPaths;
                            modelPaths.filename = creature->GetModelFilePath();
                            modelPaths.files = creature->TESModelList::FUN_00717e50();
                            char path[260];
                            TaskQueueInterface::CopyStringToBuffer(path, 260, modelPaths.filename);
                            modelPaths.slash = strrchr_0040ab30(path, '\\');
                            modelPaths.node = modelPaths.files;
                            while (modelPaths.slash && modelPaths.node)
                            {
                                modelPaths.slash[1] = 0;
                                const char* name = modelPaths.node->GetItem();
                                if (name)
                                {
                                    AppendModelPath(path, 260, name);
                                    g_modelLoader->LoadFile(path, 0, true, false, false, false);
                                }
                                modelPaths.node = modelPaths.node->GetNext();
                            }
                            modelPaths.base = strrchr(modelPaths.filename, '\\');
                            if (modelPaths.base && !_strnicmp(modelPaths.base + 1, "Skeleton", 8))
                            {
                                BSSimpleList<const char*>* files =
                                    g_modelLoader->GetModelFileList(modelPaths.filename, false, false, 0);
                                BSSimpleList<const char*>* node = files;
                                while (node)
                                {
                                    const char* name = node->GetItem();
                                    if (name)
                                        g_modelLoader->LoadKF(name);
                                    delete[] name;
                                    node = node->GetNext();
                                }
                                files->RemoveAll();
                                delete files;
                            }
                            if (creature->TESAnimation::HasSpecialAnimations())
                            {
                                modelPaths.slash[1] = 0;
                                AppendModelPath(path, 260, "SpecialAnims");
                                AppendModelPath(path, 260, "\\");
                                modelPaths.slash = strrchr_0040ab30(path, '\\');
                                BSSimpleList<const char*>* anim = static_cast<BSSimpleList<const char*>*>(creature->TESAnimation::GetKFFileList());
                                while (anim)
                                {
                                    modelPaths.slash[1] = 0;
                                    const char* name = anim->GetItem();
                                    if (name)
                                    {
                                        AppendModelPath(path, 260, name);
                                        g_modelLoader->LoadKF(path);
                                    }
                                    anim = anim->GetNext();
                                }
                            }
                        }
                    }
                }
                if (!current.effect->HasEffectID() && !current.effect->UsesAssociatedActorValue() &&
                    current.effect->IsFlagSet_00403e60(0x40000))
                    MagicItem_IncrementGlobalCounter();
                current.effect->UpdateCounter();
            }
            pIter = (EffectItemList*)pIter->GetNext();
        }
    }
}

// @fnv 0x0040ab30
// src: XBOX_PDB 0x0040ab30
char* strrchr_0040ab30(char* pcString, int cChar)
{
    return (char*)strrchr((const char*)pcString, cChar);
}

struct FUN_0040c110_obj
{
    void Model_DecRefCount();
};
void __fastcall Model_DecRefCount(void*);

struct FUN_0040c110_ptr
{
    struct Target
    {
        void Release();
    }* m_pObject;
};

void __fastcall Model_DecRefCount(FUN_0040c110_ptr::Target*);

// @fnv 0x0040c110
// src: GUESS 0x0040c110 (confidence: high)
void __fastcall MagicItem_ReleaseModelReference(FUN_0040c110_ptr* _this)
{
    if (_this->m_pObject)
        Model_DecRefCount(_this->m_pObject);
}

extern int DAT_01202800;

// Returns pThis[1] when pThis is non-null, otherwise resets DAT_01202800 to 0 and returns it.
// @fnv 0x0043d4d0
// src: XBOX_PDB 0x0043d4d0
int& __fastcall Setting_Int(int* pThis)
{
    return pThis ? pThis[1] : (DAT_01202800 = 0, DAT_01202800);
}

struct FUN_004047f0_arg
{
    const BSStringT<char>* s;
};
const char* __fastcall Modelloader_GetReferencedThis(const BSStringT<char>*);
void __fastcall FUN_00403970(BSStringT<char>*);
// @fnv 0x004047f0
BSStringT<char>* __fastcall AssignFromString(BSStringT<char>* this_ptr, FUN_004047f0_arg aStringArg)
{
    FUN_00403970(this_ptr);
    this_ptr->Set(Modelloader_GetReferencedThis(aStringArg.s), 0);
    return this_ptr;
}

struct FUN_0040c0e0_arg
{
    const char* s;
};
void __fastcall FUN_00403970(BSStringT<char>*);
// @fnv 0x0040c0e0
// src: GUESS 0x0040c0e0 (confidence: medium)
BSStringT<char>* __fastcall BSStringT_InitializeCString(BSStringT<char>* this_ptr, FUN_0040c0e0_arg aCString)
{
    FUN_00403970(this_ptr);
    this_ptr->Set(aCString.s, 0);
    return this_ptr;
}

extern int DAT_011c3438;

// @fnv 0x0040ab50
// src: GUESS 0x0040ab50 (confidence: medium)
void MagicItem_IncrementGlobalCounter()
{
    DAT_011c3438 += 1;
}

void operator delete(void*);
const char* strrchr(const char*, int);

// Preloads the magic item's effect models and, per effect, loads weapon, armor, NPC or creature models and animation files via g_modelLoader.
// @fnv 0x0040ab70
void __fastcall PreloadModels(MagicItem* magicItem)
{
    EffectItemList* pCurrentElementNext;
    EffectSetting* pavEffectSetting = magicItem->GetEffectSettingForRange(MagicSystem::SELF);

    if (!magicItem->IsLoading())
    {
        magicItem->Preload(true);
        magicItem->Unload(true);
        return;
    }

    if (pavEffectSetting)
    {
        int icount = 0;
        if (pavEffectSetting->HasNoAssociatedActorValue())
            icount = pavEffectSetting->FUN_004089c0();
        if (pavEffectSetting->TESModel::GetModelLength() > 0)
        {
            NiPointer<Model> spmodel(0);
            g_modelLoader->ModelLoader_FindModel(pavEffectSetting->GetModelFilePath(), spmodel);
            if (spmodel)
                ((Model*)spmodel)->SetManualRefCount(icount);
        }
    }

    pCurrentElementNext = magicItem;
    if (!pCurrentElementNext->IsEmpty())
    {
        while (pCurrentElementNext)
        {
            EffectItem* pitem = pCurrentElementNext->GetItem();
            EffectSetting* pes = pitem->GetEffectSetting();
            TESForm* pform = pes->FUN_005f5f80();
            int icount = 0;
            if (pes->UsesAssociatedActorValue())
                icount = pes->FUN_004087e0();
            if (icount)
            {
                if (pform && pes->IsFlagSet_00403e60(0x10000))
                {
                    TESObjectWEAP* pweapon = dynamic_cast<TESObjectWEAP*>(pform);
                    if (pweapon && pweapon->TESModel::GetModelLength() > 0)
                    {
                        NiPointer<Model> spmodel(0);
                        g_modelLoader->ModelLoader_FindModel(
                            reinterpret_cast<TESModel*>(reinterpret_cast<char*>(pweapon) +
                                offsetof(TESObjectWEAP, m_kModelFilePath) -
                                offsetof(TESModel, m_kModelFilePath))->GetModelFilePath(), spmodel);
                        if (spmodel)
                            ((Model*)spmodel)->SetManualRefCount(icount);
                    }
                }
                else if (pform && pes->IsFlagSet_00403e60(0x20000))
                {
                    TESObjectARMO* parmor = dynamic_cast<TESObjectARMO*>(pform);
                    if (parmor)
                    {
                        NiPointer<Model> spmodel(0);
                        g_modelLoader->ModelLoader_FindModel(parmor->GetBipedModel(0),
                                                    spmodel);
                        if (spmodel)
                            ((Model*)spmodel)->SetManualRefCount(icount);
                        g_modelLoader->ModelLoader_FindModel(parmor->GetBipedModel(1),
                                                    spmodel);
                        if (spmodel)
                            ((Model*)spmodel)->SetManualRefCount(icount);
                    }
                }
                else if (pform && pes->IsFlagSet_00403e60(0x40000))
                {
                    TESNPC* pnpc = dynamic_cast<TESNPC*>(pform);
                    if (pnpc)
                    {
                        BSSimpleList<const char*>* modelList = pnpc->GetModelFiles(true, true);
                        BSSimpleList<const char*>* pCurrentElementNext = modelList;
                        while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
                        {
                            const char* pfilename = pCurrentElementNext->GetItem();
                            NiPointer<Model> spmodel(0);
                            g_modelLoader->ModelLoader_FindModel(pfilename, spmodel);
                            if (spmodel)
                                ((Model*)spmodel)->SetManualRefCount(icount);
                            pCurrentElementNext = pCurrentElementNext->GetNext();
                        }
                        modelList->RemoveAll();
                        delete modelList;
                    }
                    TESCreature* pcreature = dynamic_cast<TESCreature*>(pform);
                    if (pcreature)
                    {
                        NiPointer<Model> spmodel(0);
                        const char* plastBackSlash;
                        BSSimpleList<const char*>* pfilelist;
                        char* plastSlash;
                        const char* pfilename;
                        g_modelLoader->ModelLoader_FindModel(pcreature->GetModelFilePath(),
                                                    spmodel);
                        if (spmodel)
                        {
                            char path[260];
                            BSSimpleList<const char*>* pcreatureFileList;
                            for (int i = 0; i < icount; i++)
                                ((Model*)spmodel)->Model_IncManualRefCount();
                            pfilename = ((Model*)spmodel)->Modelloader_GetReferencedThis();
                            pfilelist = pcreature->TESModelList::FUN_00717e50();
                            TaskQueueInterface::CopyStringToBuffer(path, 260, pfilename);
                            plastSlash = strrchr_0040ab30(path, '\\');
                            pcreatureFileList = pfilelist;
                            while (plastSlash && pcreatureFileList)
                            {
                                plastSlash[1] = 0;
                                const char* pitem = pcreatureFileList->GetItem();
                                if (pitem)
                                {
                                    AppendModelPath(path, 260, pitem);
                                    NiPointer<Model> spmodel(0);
                                    g_modelLoader->ModelLoader_FindModel(path, spmodel);
                                    if (spmodel)
                                        ((Model*)spmodel)->SetManualRefCount(icount);
                                }
                                pcreatureFileList = pcreatureFileList->GetNext();
                            }
                            plastBackSlash = strrchr(pfilename, '\\');
                            if (plastBackSlash && !_strnicmp(plastBackSlash + 1, "Skeleton", 8))
                            {
                                BSSimpleList<const char*>* pkfList =
                                    g_modelLoader->GetModelFileList(pfilename, false, false, 0);
                                {
                                    BSSimpleList<const char*>* pFilenameList = pkfList;
                                    while (pFilenameList)
                                    {
                                        const char* pitem = pFilenameList->GetItem();
                                        if (pitem)
                                        {
                                            for (int i = 0; i < icount; i++)
                                                g_modelLoader->LoadKF(pitem);
                                        }
                                        delete pitem;
                                        pFilenameList = pFilenameList->GetNext();
                                    }
                                }
                                pkfList->RemoveAll();
                                delete pkfList;
                            }
                            if (pcreature->TESAnimation::HasSpecialAnimations())
                            {
                                plastSlash[1] = 0;
                                AppendModelPath(path, 260, "SpecialAnims");
                                AppendModelPath(path, 260, "\\");
                                plastSlash = strrchr_0040ab30(path, '\\');
                                BSSimpleList<const char*>* pspecialList =
                                    static_cast<BSSimpleList<const char*>*>(pcreature->TESAnimation::GetKFFileList());
                                while (pspecialList)
                                {
                                    plastSlash[1] = 0;
                                    const char* pitem = pspecialList->GetItem();
                                    if (pitem)
                                    {
                                        AppendModelPath(path, 260, pitem);
                                        for (int i = 0; i < icount; i++)
                                            g_modelLoader->LoadKF(path);
                                    }
                                    pspecialList = pspecialList->GetNext();
                                }
                            }
                        }
                    }
                }
            }
            pCurrentElementNext = static_cast<EffectItemList*>(pCurrentElementNext->GetNext());
        }
    }
}

extern int DAT_011c3438;

// @fnv 0x0040bed0
void DecrementGlobalCounter()
{
    --DAT_011c3438;
}

// @fnv 0x0040b580
bool __fastcall IsMagicItemReady(MagicItem* magicItem)
{
    EffectSetting* current = magicItem->GetEffectSettingForRange(MagicSystem::SELF);
    if (current && current->TESModel::GetModelLength() > 0 && !current->IsModelLoaded() && !current->HasNoAssociatedActorValue())
        return false;
    EffectItemList* primary = magicItem;
    if (!primary->IsEmpty())
    {
        while (primary)
        {
            EffectItem* item = primary->GetItem();
            EffectSetting* setting = item ? item->GetEffectSetting() : 0;
            if (setting && setting->IsAssociatedFormUsed() && !setting->HasEffectID() &&
                !setting->UsesAssociatedActorValue())
                return false;
            primary = static_cast<EffectItemList*>(primary->GetNext());
        }
    }
    return true;
}

// Casts this MagicItem to MagicItemForm or MagicItemObject and calls TESSound::Deallocate on it, returning 0 if neither cast succeeds.
// @fnv 0x0040a1e0
int __fastcall MagicItemDeallocate(MagicItem* magicItem)
{
    MagicItemForm* form = dynamic_cast<MagicItemForm*>(magicItem);
    MagicItemObject* object = dynamic_cast<MagicItemObject*>(magicItem);
    if (form != 0)
        return reinterpret_cast<TESSound*>(form)->Deallocate();
    else if (object != 0)
        return reinterpret_cast<TESSound*>(object)->Deallocate();
    return 0;
}

// Counter helpers at 0x00408910 and 0x00408730 use EffectSetting in ECX.
int __fastcall StepEffectLoadedCountTowardZero(EffectSetting*);
int __fastcall ClampEffectCounterTowardZero(EffectSetting*);

struct UnloadLoader : ModelLoader
{
    void ModelLoader_ReleaseModel(const char*, bool, bool);
    void ModelLoader_ReleaseKF(const char*, bool);
};
extern UnloadLoader* DAT_011c3b3c;
int FUN_00406d30(char*, unsigned int, const char*);

// @fnv 0x0040b800
void MagicItem::Unload(bool immediate)
{
    if (!IsMagicItemReady(this))
        return;
    EffectSetting* primary = GetEffectSettingForRange(MagicSystem::SELF);
    bool queued = false;
    if (IsLoading())
        queued = true;
    if (primary && primary->TESModel::GetModelLength())
    {
        if (!queued)
            DAT_011c3b3c->ModelLoader_ReleaseModel(primary->GetModelFilePath(), immediate, true);
        StepEffectLoadedCountTowardZero(primary);
    }
    EffectItemList* effects = this;
    if (!effects->IsEmpty())
    {
        while (effects)
        {
            EffectItem* item = effects->GetItem();
            EffectSetting* effect = item->GetEffectSetting();
            if (effect->IsAssociatedFormUsed())
            {
                if (!queued)
                {
                    TESForm* associated = effect->FUN_005f5f80();
                    if (associated && effect->IsFlagSet_00403e60(0x10000))
                    {
                        TESObjectWEAP* weapon = dynamic_cast<TESObjectWEAP*>(associated);
                        if (weapon && weapon->TESModel::GetModelLength() > 0)
                            DAT_011c3b3c->ModelLoader_ReleaseModel(
                                reinterpret_cast<TESModel*>(reinterpret_cast<char*>(weapon) +
                                    offsetof(TESObjectWEAP, m_kModelFilePath) -
                                    offsetof(TESModel, m_kModelFilePath))->GetModelFilePath(), immediate, true);
                    }
                    else if (associated && effect->IsFlagSet_00403e60(0x20000))
                    {
                        TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(associated);
                        if (armor)
                        {
                            DAT_011c3b3c->ModelLoader_ReleaseModel(armor->GetBipedModel(0), immediate, true);
                            DAT_011c3b3c->ModelLoader_ReleaseModel(armor->GetBipedModel(1), immediate, true);
                        }
                    }
                    else if (associated && effect->IsFlagSet_00403e60(0x40000))
                    {
                        TESNPC* npc3 = dynamic_cast<TESNPC*>(associated);
                        if (npc3)
                        {
                            BSSimpleList<const char*>* models71 = npc3->GetModelFiles(true, true);
                            BSSimpleList<const char*>* model15 = models71;
                            while (model15 && !model15->IsEmpty())
                            {
                                const char* path = model15->GetItem();
                                DAT_011c3b3c->ModelLoader_ReleaseModel(path, immediate, true);
                                model15 = model15->GetNext();
                            }
                            models71->RemoveAll();
                            delete models71;
                        }
                        TESCreature* creature11 = dynamic_cast<TESCreature*>(associated);
                        if (creature11)
                        {
                            DAT_011c3b3c->ModelLoader_ReleaseModel(creature11->GetModelFilePath(), immediate, true);
                            const char* modelPath6 = creature11->GetModelFilePath();
                            BSSimpleList<const char*>* modelList6 = creature11->TESModelList::FUN_00717e50();
                            BSSimpleList<const char*>* modelNode29;
                            const char* fileName12;
                            char buffer4[260];
                            FUN_00406d30(buffer4, 260, modelPath6);
                            char* separator10 = strrchr_0040ab30(buffer4, '\\');
                            modelNode29 = modelList6;
                            while (separator10 && modelNode29)
                            {
                                separator10[1] = 0;
                                const char* path = modelNode29->GetItem();
                                if (path)
                                {
                                    AppendModelPath(buffer4, 260, path);
                                    DAT_011c3b3c->ModelLoader_ReleaseModel(buffer4, immediate, true);
                                }
                                modelNode29 = modelNode29->GetNext();
                            }
                            fileName12 = strrchr(modelPath6, '\\');
                            if (fileName12 && !_strnicmp(fileName12 + 1, "Skeleton", 8))
                            {
                                BSSimpleList<const char*>* files =
                                    DAT_011c3b3c->GetModelFileList(modelPath6, false, false, 0);
                                BSSimpleList<const char*>* file = files;
                                while (file)
                                {
                                    const char* path = file->GetItem();
                                    if (path)
                                        DAT_011c3b3c->ModelLoader_ReleaseKF(path, immediate);
                                    delete[] path;
                                    file = file->GetNext();
                                }
                                files->RemoveAll();
                                delete files;
                            }
                            if (creature11->TESAnimation::HasSpecialAnimations())
                            {
                                separator10[1] = 0;
                                AppendModelPath(buffer4, 260, "SpecialAnims");
                                AppendModelPath(buffer4, 260, "\\");
                                separator10 = strrchr_0040ab30(buffer4, '\\');
                                BSSimpleList<const char*>* animation = static_cast<BSSimpleList<const char*>*>(creature11->TESAnimation::GetKFFileList());
                                while (animation)
                                {
                                    separator10[1] = 0;
                                    const char* path = animation->GetItem();
                                    if (path)
                                    {
                                        AppendModelPath(buffer4, 260, path);
                                        DAT_011c3b3c->ModelLoader_ReleaseKF(buffer4, immediate);
                                    }
                                    animation = animation->GetNext();
                                }
                            }
                        }
                    }
                }
                ClampEffectCounterTowardZero(effect);
                if (!effect->HasEffectID() && !effect->UsesAssociatedActorValue() && effect->IsFlagSet_00403e60(0x40000))
                    DecrementGlobalCounter();
            }
            effects = (EffectItemList*)effects->GetNext();
        }
    }
}

struct StringSetting
{
    const char* FUN_00403df0();
};
extern StringSetting DAT_011c34c0;
extern StringSetting DAT_011c348c;
extern StringSetting DAT_011c34a0;
extern StringSetting DAT_011c344c;
extern StringSetting DAT_011c3458;
extern StringSetting DAT_011c34d8;
extern StringSetting DAT_011c3474;
struct FUN_0040c0e0
{
    char* data;
    unsigned short length, capacity;
    FUN_0040c0e0(const char*);
    ~FUN_0040c0e0();
};
typedef struct FUN_0040c0e0 ReturnString;
struct MagicLabel
{
    ReturnString GetNameForType(unsigned int);
};
// Returns a string setting's value chosen by type, falling back to DAT_011c3474 for any other value.
// @fnv 0x0040bef0
ReturnString MagicLabel::GetNameForType(unsigned int type)
{
    switch (type)
    {
    case 1:
        return ReturnString(DAT_011c34c0.FUN_00403df0());
    case 3:
        return ReturnString(DAT_011c348c.FUN_00403df0());
    case 4:
        return ReturnString(DAT_011c34a0.FUN_00403df0());
    case 2:
        return ReturnString(DAT_011c344c.FUN_00403df0());
    case 5:
        return ReturnString(DAT_011c3458.FUN_00403df0());
    case 6:
        return ReturnString(DAT_011c34d8.FUN_00403df0());
    default:
        return ReturnString(DAT_011c3474.FUN_00403df0());
    }
}
