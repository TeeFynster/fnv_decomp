#include "../../include/InterfaceManager.h"
// fallout_shared/bgsbodypart.cpp: BGSBodyPart, BodyPartInfo, BGSTextureModel, SomeClass (15 functions)

#include "../../include/BSStringT.h"

#include "../../include/BGSTextureModel.h"
#include "../../include/TESFile.h"
#include "../../include/BGSBodyPart.h"
#include "../../include/BGSDebris.h"
#include "../../include/BGSExplosion.h"
#include "../../include/BGSImpactDataSet.h"
#include "../../include/BodyPartInfo.h"
#include "../../include/Actor.h"
#include "../../include/EffectSetting.h"

extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)
int Warning(const char*, ...);
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
// Not DialogueItem: 0x005e3fa0 is a folded getter returning the dword at this + 0x6c.
class FUN_005e3fa0_Field6C
{
  public:
    unsigned int FUN_005e3fa0();
};
class Tile;

#include "../../include/IO_TASK_PRIORITY.h"

extern "C" NiPoint3 NiPoint3_ZERO;

class ModelLoader
{
  public:
    void ProcessModelRequest(TESModel*, int, QueuedFile*, bool, bool, bool, bool);
};
extern ModelLoader* g_modelLoader;

extern "C" void* memset(void*, int, unsigned int);

class Queueable18
{
  public:
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void QueueResourceLoad(IO_TASK_PRIORITY, QueuedFile*) = 0;
};

// @fnv 0x005e3a00
void BodyPartInfo::Initialize()
{
    m_ucPartID = 5;
    m_fDamageMultiplier = 1.0f;
    m_cActorValue = -1;
    m_ucHealthPercent = 100;
    m_ucHitChance = 0;
    m_ucLimbReplacementType = 0;
    m_pExplosion = 0;
    m_pDebrisObject = 0;
    m_fExplosionChance = 0.0f;
    m_fDebrisScale = 1.0f;
    m_fValue4 = 1.0f;
    m_ucSeverable = 0;
    m_pRelatedObject1 = 0;
    m_pRelatedObject2 = 0;
    m_fValue3 = 1.0f;
    m_kPoint1 = NiPoint3_ZERO;
    m_kPoint2 = NiPoint3_ZERO;
    m_pRelatedObject3 = 0;
    m_pRelatedObject4 = 0;
    m_ucByte1 = 0;
    m_ucByte2 = 0;
}

// Queues the model and each present Data sub-object's queueable for loading at the given priority.
// @fnv 0x005e45e0
void BGSBodyPart::QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* queuedFile)
{
    if (static_cast<const TESModel&>(m_kModel).GetModelLength())
        g_modelLoader->ProcessModelRequest(&m_kModel, priority, queuedFile, true, true, false, false);
    if (Data.m_pExplosion)
        ((Queueable18*)((char*)Data.m_pExplosion + 0x18))->QueueResourceLoad(priority, queuedFile);
    if (Data.m_pDebrisObject)
        ((Queueable18*)((char*)Data.m_pDebrisObject + 0x64))->QueueResourceLoad(priority, queuedFile);
    if (Data.m_pRelatedObject1)
        ((Queueable18*)((char*)Data.m_pRelatedObject1 + 0x18))->QueueResourceLoad(priority, queuedFile);
    if (Data.m_pRelatedObject2)
        ((Queueable18*)((char*)Data.m_pRelatedObject2 + 0x64))->QueueResourceLoad(priority, queuedFile);
    if (Data.m_pRelatedObject3)
        ((BGSPreloadable*)((char*)Data.m_pRelatedObject3 + 0x18))->QueueResourceLoad(priority, queuedFile);
    if (Data.m_pRelatedObject4)
        ((BGSPreloadable*)((char*)Data.m_pRelatedObject4 + 0x18))->QueueResourceLoad(priority, queuedFile);
}

// Zeroes the 0x54-byte Data block, calls Data.Initialize(), then FUN_005e3d20().
// @fnv 0x005e3af0
BGSBodyPart::BGSBodyPart()
{
    memset(&Data, 0, 0x54);
    Data.Initialize();
    InitializeData_005e3d20();
}

// @fnv 0x005e3d80
void BGSBodyPart::InitItem(TESForm* form)
{
    if (!form || static_cast<const TESForm*>(form)->GetInitialized())
        return;
    unsigned int formID = ((FUN_005e3fa0_Field6C*)this)->FUN_005e3fa0();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, form->GetFile(-1));
        Data.m_pDebrisObject = dynamic_cast<BGSExplosion*>(TESForm::GetFormByID(formID));
    }
    formID = (unsigned int)((Actor*)this)->GetProcess();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, form->GetFile(-1));
        Data.m_pExplosion = dynamic_cast<BGSDebris*>(TESForm::GetFormByID(formID));
    }
    formID = (unsigned int)((EffectSetting*)this)->GetCastSound();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, form->GetFile(-1));
        Data.m_pRelatedObject2 = dynamic_cast<BGSExplosion*>(TESForm::GetFormByID(formID));
    }
    formID = (unsigned int)((EffectSetting*)this)->GetEnchantEffectShader();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, form->GetFile(-1));
        Data.m_pRelatedObject1 = dynamic_cast<BGSDebris*>(TESForm::GetFormByID(formID));
    }
    formID = (unsigned int)((InterfaceManager*)this)->GetAVEffect();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, form->GetFile(-1));
        ((InterfaceManager*)this)
            ->BGSTerminal_SetPassword((Tile*)dynamic_cast<BGSImpactDataSet*>(TESForm::GetFormByID(formID)));
    }
    formID = FUN_005e3fc0();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, form->GetFile(-1));
        FUN_00994ef0(dynamic_cast<BGSImpactDataSet*>(TESForm::GetFormByID(formID)));
    }
}

// Reads BPTN/PNMA/BPNN/BPNT/BPNI/BPND/NAM1/NAM2-5 chunks from a TESFile into the body part's names, model, data and debris scale, defaulting zero scales to 0.1.
// @fnv 0x005e4100
bool BGSBodyPart::Load(TESFile* file)
{
    void* pChunkBuffer;
    {
        bool badScale;
        if (!file)
            return false;
        if (file->GetChunkID() == 0x4e545042)
        {
            char* partName = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(partName, 0);
            m_kPartName.Set(partName, 0);
            if (!file->NextChunk())
                return false;
        }
        if (file->GetChunkID() == 0x4d414e50)
        {
            TESModel::LoadModelData((TESModel*)&m_kRagdollModel, file);
            if (!file->NextChunk())
                return false;
        }
        if (file->GetChunkID() != 0x4e4e5042)
            return false;
        pChunkBuffer = (char*)_alloca(file->GetChunkSize());
        file->GetChunkData(pChunkBuffer, 0);
        NodeName.Set((char*)pChunkBuffer, 0);
        if (!file->NextChunk())
            return false;
        if (file->GetChunkID() != 0x544e5042)
            return false;
        pChunkBuffer = (char*)_alloca(file->GetChunkSize());
        file->GetChunkData(pChunkBuffer, 0);
        TargetName.Set((char*)pChunkBuffer, 0);
        if (!file->NextChunk())
            return false;
        if (file->GetChunkID() == 0x494e5042)
        {
            pChunkBuffer = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(pChunkBuffer, 0);
            m_kVATSNodeName.Set((char*)pChunkBuffer, 0);
            if (!file->NextChunk())
                return false;
        }
        if (file->GetChunkID() != 0x444e5042)
            return false;
        if (file->IsEndianConversionRequired())
            Data.SwapEndianFields();
        file->GetChunkData(&Data, 0x54);
        if (file->IsEndianConversionRequired())
            Data.SwapEndianFields();
        badScale = false;
        if (Data.m_fValue4 == 0.0)
        {
            Data.m_fValue4 = 0.1f;
            badScale = true;
        }
        if (Data.m_fValue3 == 0.0)
        {
            Data.m_fValue3 = 0.1f;
            badScale = true;
        }
        if (Data.m_fDebrisScale == 0.0)
        {
            Data.m_fDebrisScale = 0.1f;
            badScale = true;
        }
        if (badScale)
            Warning("MODELS: Debris scale value of zero loaded.  Please set to non-zero value in editor.");
        if (!file->NextChunk())
            return false;
        if (file->GetChunkID() != 0x314d414e)
            return false;
        if (file->GetChunkSize())
        {
            char* modelName = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(modelName, 0);
            m_kModel.SetModelFilePath(modelName);
        }
        if (((TESFileFormVersion*)file)->GetFormVersion() < 3)
        {
            if (!file->NextChunk() || file->GetChunkID() != 0x324d414e)
                return ((TESFileFormVersion*)file)->GetFormVersion() < 2;
            if (file->GetChunkSize())
            {
                char* modelName2 = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(modelName2, 0);
            }
            if (!file->NextChunk() || file->GetChunkID() != 0x334d414e)
                return ((TESFileFormVersion*)file)->GetFormVersion() < 2;
            if (file->GetChunkSize())
            {
                char* modelName3 = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(modelName3, 0);
            }
        }
        if (!file->NextChunk() || file->GetChunkID() != 0x344d414e)
            return ((TESFileFormVersion*)file)->GetFormVersion() < 2;
        if (file->GetChunkSize())
        {
            char* goreName = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(goreName, 0);
            m_kGoreName.Set(goreName, 0);
        }
        if (!file->NextChunk() || file->GetChunkID() != 0x354d414e)
            return true;
        if (file->GetChunkSize())
            TESModel::LoadTextureSwapData(&m_kModel, file);
        return true;
    }
}

// @fnv 0x005e3be0
BGSTextureModel::BGSTextureModel()
{
}

void __fastcall _ref_006815c0(void*);

// @fnv 0x005e3c00
// src: XBOX_PDB 0x005e3c00
void* __fastcall PART_DATA_PART_DATA(char* pObject)
{
    _ref_006815c0(pObject + 0x2c);
    _ref_006815c0(pObject + 0x38);
    return pObject;
}

// Initializes the model and ragdoll model components.
// @fnv 0x005e3d20
// src: XBOX_PDB 0x005e3d20
void BGSBodyPart::InitializeData_005e3d20()
{
    m_kModel.Init();
    m_kRagdollModel.Init();
}

// Frees the model and ragdoll model components.
// @fnv 0x005e3d50
void __fastcall FreeBodyPartModels(BGSBodyPart* part)
{
    part->m_kModel.Free();
    part->m_kRagdollModel.Free();
}

// @fnv 0x005e3c60
BGSBodyPart::~BGSBodyPart()
{
    FreeBodyPartModels(this);
}

class PartList;
class PartNode
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual PartList* GetChildren();
    virtual void vfn10();
    virtual void vfn14();
    virtual void* GetTarget();
};

class PartList
{
  public:
    unsigned int CountItems();
    PartNode* GetItem(unsigned int);
};

class PartSink
{
  public:
    void AddEntry(unsigned int, int);
};

extern int DAT_011f49d8;
void* __cdecl NiObject_DynamicCast(void*, void*);
void* __fastcall NiGeometry_GetSkinInstance(void*);

// Recursively walks a PartNode tree; for leaf nodes with a target, looks up a PartSink and adds two entries keyed by a1 and a1+0xc8.
// @fnv 0x005e4730
void AddNodeEntries(unsigned int a1, PartNode* pNode)
{
    if (pNode == 0)
    {
        return;
    }
    if (pNode->GetChildren())
    {
        PartList* list3 = pNode->GetChildren();
        unsigned int i;
        for (i = 0; i < list3->CountItems(); i++)
        {
            AddNodeEntries(a1, list3->GetItem(i));
        }
    }
    else if (pNode->GetTarget())
    {
        void* target = pNode->GetTarget();
        void* base = NiGeometry_GetSkinInstance(target);
        PartSink* sink2 = (PartSink*)NiObject_DynamicCast(&DAT_011f49d8, base);
        if (sink2)
        {
            sink2->AddEntry((unsigned short)a1, 0);
            sink2->AddEntry(a1 + 0xc8, 1);
        }
    }
}

struct Entry_005e4810
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned short unk02;
};

struct SomeClass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    unsigned int unk34;
    Entry_005e4810* unk38;
    unsigned char unk3c;

    void SetEntryStateByKey(unsigned short param1, unsigned char param2);
};

// Clears unk3c, then for each of unk34 entries matching param1 sets unk00 to param2 and ORs every entry's unk00 into unk3c.
// @fnv 0x005e4810
void SomeClass::SetEntryStateByKey(unsigned short ausKey, unsigned char aucState)
{
    this->unk3c = 0;
    for (unsigned int i = 0; i < this->unk34; i++)
    {
        if (this->unk38[i].unk02 == ausKey)
        {
            this->unk38[i].unk00 = aucState;
        }
        this->unk3c = this->unk3c | this->unk38[i].unk00;
    }
}

namespace fnv_005e4890 {
class TreeNode;
class NodeList
{
  public:
    unsigned int FUN_0043b480();
    TreeNode* FUN_0043b4a0(unsigned int index);
};
class KeyName
{
  public:
    const char* NiGeometry_GetSkinInstance();
};
class TreeNode
{
  public:
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual NodeList* GetChildren();
    virtual void unused4();
    virtual void unused5();
    virtual KeyName* GetKeyName();
};
class FoundResult
{
  public:
    void SetEntryStateByKey(unsigned int value, int enabled);
};
extern char DAT_011f49d8[];
FoundResult* __cdecl NiObject_DynamicCast(const char*, const char*);
// Recurses into a tree node's children; for each leaf with a key name, looks up a result by name and applies key and key+200 to it.
// @fnv 0x005e4890
void __cdecl ApplyKeyToLeafNodes(unsigned int key, TreeNode* node)
{
    if (node == 0)
        return;
    if (node->GetChildren())
    {
        NodeList* children = node->GetChildren();
        for (unsigned int i = 0; i < children->FUN_0043b480(); ++i)
        {
            ApplyKeyToLeafNodes(key, children->FUN_0043b4a0(i));
        }
    }
    else if (node->GetKeyName())
    {
        KeyName* pKeyName = node->GetKeyName();
        const char* pcText = pKeyName->NiGeometry_GetSkinInstance();
        FoundResult* result = NiObject_DynamicCast(DAT_011f49d8, pcText);
        if (result != 0)
        {
            result->SetEntryStateByKey(static_cast<unsigned short>(key), 1);
            result->SetEntryStateByKey(key + 200, 0);
        }
    }
}
}  // namespace fnv_005e4890

// Emits the scalar deleting destructor at 0x005e50c0.
void DestroyBodyPart(BGSBodyPart* part)
{
    delete part;
}
