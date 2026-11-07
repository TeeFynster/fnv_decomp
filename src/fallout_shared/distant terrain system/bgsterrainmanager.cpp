
// fallout_shared/distant terrain system/bgsterrainmanager.cpp
#include "../../../include/BGSTerrainManager.h"
#include "../../../include/BGSDistantTreeBlock.h"
#include "bgsterrainmanager_decls.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/TES.h"
#include "../../../include/NiNode.h"
// NiNodeHolder_bgsterrainmanager: local type (was include/NiNodeHolder.h, which had no evidence of one real class); its methods are 0x00559450 NiPointer<PathingSolution>::operator->, 0x0066b0d0 NiPointer<PathingSolution>::operator=
#include "../../../include/NiRefObject.h"

class NiNode;
class CleanupObject;

class NiNodeHolder_bgsterrainmanager
{
public:
    NiRefObject* value;

    NiNodeHolder_bgsterrainmanager(NiRefObject* p);
    ~NiNodeHolder_bgsterrainmanager();
    operator NiNode*() const;
    void FUN_0066b0d0(CleanupObject* object);
    CleanupObject* Modelloader_GetReferencedThis();
};
#include "../../../include/TESObjectREFR.h"
#include "../../../include/BGSTerrainNode.h"

// 0x00485b60 is not declared by the shared headers; this preserves its ECX-only call ABI.
unsigned int __fastcall GetTerrainReferenceID(TESObjectREFR* reference);

// Returns null if path is missing or not found, otherwise opens the file and returns the result of ReadAnimationFromStream on it.
// @fnv 0x004d52f0
BGSTerrainManager* LoadBGSTerrainManager(const char* path)
{
    BSFile* file = 0;
    if (!path || !FileFinder::Exist(path, 0, 0, 0xFFFFFFFF))
    {
        return 0;
    }
    file = FileFinder::GetFile(path, NiFile::READ_ONLY, 0x4000, 0x10);
    return ReadAnimationFromStream(file);
}

void __cdecl BGSTerrainChunk_ResetCullResults();
void __cdecl BGSDistantObjectBlock_ResetCullResults();

// @fnv 0x006fd130
void BGSTerrainManager::ResetMultiBoundResults()
{
    if (pRootTerrainNode)
    {
        BGSTerrainChunk_ResetCullResults();
        BGSDistantObjectBlock_ResetCullResults();
    }
}

void __cdecl SetSoundListFlag(bool);

// @fnv 0x006fd1f0
// src: XBOX_PDB 0x006fd1f0
void __cdecl BGSTerrainManager_EnableLODWaterProcessing(bool abEnable)
{
    SetSoundListFlag(abEnable);
}

extern int DAT_011d8598;

// @fnv 0x006fcda0
// src: COMMUNITY 0x006fcda0
int __cdecl BGSDistantTreeBlock_GetBlockCount()
{
    return DAT_011d8598;
}

struct FUN_006fd980_shell
{
    void BGSTerrainNode_UnloadDataRecurse(int);
};

// If the root node is non-null, calls FUN_006fd980(7) on it.
// @fnv 0x006fce00
// src: XBOX_PDB 0x006fce00
void __thiscall BGSTerrainManager::UnloadAll_006fce00()
{
    if (pRootTerrainNode != 0)
        ((FUN_006fd980_shell*)pRootTerrainNode)->BGSTerrainNode_UnloadDataRecurse(7);
}

struct BGSTerrainChunk
{
    int __thiscall BGSTerrainChunk_GetTexture(int);
};

// @fnv 0x006fce30
NiTexture* BGSTerrainManager::GetDiffuseTextureForPoint(void* point)
{
    NiTexture* result = 0;
    BGSTerrainChunk* obj = GetChunkForPoint(point);
    if (obj)
    {
        result = (NiTexture*)obj->BGSTerrainChunk_GetTexture(0);
    }
    return result;
}

struct GlobalObject_00869f00
{
    void Remove(unsigned int, bool);
};

// Scans the array at offset 0x2c for entries equal to apTreeRef and removes each match, decrementing the count.
// @fnv 0x006fcf30
void BGSTerrainManager::RemoveTerrainReference(TESObjectREFR* apTreeRef)
{
    unsigned int icount = ((BSSimpleArray<unsigned int>*)(&kTerrainReferences))->GetSize();
    unsigned int i = 0;
    while (i < icount)
    {
        if (*((BSSimpleArray<TESObjectREFR*>*)(&kTerrainReferences))->GetAtPointer((int)i) == apTreeRef)
        {
            ((GlobalObject_00869f00*)(&kTerrainReferences))->Remove(i, true);
            icount--;
        }
        else
        {
            i++;
        }
    }
}


// @fnv 0x006fd060
// src: COMMUNITY 0x006fd060
void __thiscall BGSTerrainManager::TriggerLODApocalypse()
{
    pRootTerrainNode->ProcessBlock();
}

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern unsigned char DAT_0119f188;
extern GlobalObject_0045cf30 g_011d86ac;
struct FUN_006fea70_obj
{
    void SetValue(int);
};
// @fnv 0x006fcdb0
void BGSTerrainManager::UpdateMorphParameters(void* a1)
{
    if (DAT_0119f188 && *g_011d86ac.Bool() && pRootTerrainNode)
        ((FUN_006fea70_obj*)pRootTerrainNode)->SetValue((int)a1);
}

// @fnv 0x006fce70
NiTexture* BGSTerrainManager::GetNormalTextureForPoint(void* a1)
{
    NiTexture* result = 0;
    BGSTerrainChunk* chunk = GetChunkForPoint(a1);
    if (chunk)
        result = (NiTexture*)chunk->BGSTerrainChunk_GetTexture(1);
    return result;
}

struct Unk006fec90
{
    int __thiscall GetActiveMenu(int);
};
// @fnv 0x006fceb0
BGSTerrainChunk* BGSTerrainManager::GetChunkForPoint(void* a1)
{
    int unused = 0;
    if (pRootTerrainNode)
        return (BGSTerrainChunk*)((Unk006fec90*)pRootTerrainNode)->GetActiveMenu((int)a1);
    return 0;
}

struct FUN_006fed30_Callee
{
    int __thiscall BGSTerrainNode_GetTreeBlockForPoint(int);
};
// @fnv 0x006fcef0
BGSDistantTreeBlock* BGSTerrainManager::GetDistantTreeBlockForPoint(void* a)
{
    int unused = 0;
    if (pRootTerrainNode)
        return (BGSDistantTreeBlock*)((FUN_006fed30_Callee*)pRootTerrainNode)->BGSTerrainNode_GetTreeBlockForPoint((int)a);
    return 0;
}

// @fnv 0x006fd010
void BGSTerrainManager::AddTerrainReference(TESObjectREFR* a1)
{
    unsigned int tmp = GetTerrainReferenceID(a1);
    {
        BGSDistantTreeBlock* p = GetDistantTreeBlockForPoint((void*)((const TESObjectREFR*)a1)->GetPos());
        if (p)
            p->ClearInstanceFlag(tmp);
    }
}

struct S_00587f40_Lock
{
    void BSCriticalSection_Enter(int a);
    void FUN_004538c0();
};
extern S_00587f40_Lock DAT_011ca60c;

struct S_00587f40_List
{
    int unk00;
    int unk04;
    void RemoveAll();
    ~S_00587f40_List();
};

struct S_00587f40_Map
{
    void* GetFirstPos();
    void GetNext(void*& pos, unsigned int& key, S_00587f40_List*& val);
    void RemoveAll();
};

struct S_00587f40
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    S_00587f40_Map m_map;
    int unk54;
    int unk58;
    int unk5C;
    S_00587f40_List m_kNode;
    void ClearAllLists();
};

// @fnv 0x00587f40
void S_00587f40::ClearAllLists()
{
    DAT_011ca60c.BSCriticalSection_Enter(0);
    m_kNode.RemoveAll();
    void* pos = m_map.GetFirstPos();
    while (pos)
    {
        unsigned int key = 0;
        S_00587f40_List* list = 0;
        m_map.GetNext(pos, key, list);
        if (list)
        {
            list->RemoveAll();
            delete list;
        }
    }
    m_map.RemoveAll();
    DAT_011ca60c.FUN_004538c0();
}

// @fnv 0x006fcfa0
void BGSTerrainManager::UpdateTerrainReference(TESObjectREFR* ref, bool addIfMissing)
{
    unsigned int formId = GetTerrainReferenceID(ref);
    BGSDistantTreeBlock* block = GetDistantTreeBlockForPoint((void*)((const TESObjectREFR*)ref)->GetPos());
    if (block)
    {
        block->MarkTreeInstance(formId, true);
    }
    else if (addIfMissing)
    {
        kTerrainReferences.Add((TESObjectREFR* const&)ref);
    }
}

struct tagRECT
{
    long left, top, right, bottom;
};
void __cdecl SetRectCenterAndHalfExtents(tagRECT*);

extern TES* g_TES;

extern NiNodeHolder_bgsterrainmanager DAT_011d86bc;
extern GlobalObject_0045cf30 DAT_011d869c;
extern GlobalObject_0045cf30 DAT_011d8680;


struct LodNode
{
    void UpdateTerrainNode(const NiPoint3&, bool);
    void UpdateBlock(const NiPoint3&, bool);
    void BGSTerrainNode_UpdateTrees(const NiPoint3&);
};

struct RefArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    TESObjectREFR*& FUN_00877a30(unsigned int);
    unsigned int FUN_0044ddc0();
    void FUN_008454f0(bool);
    void FUN_006f2290(unsigned int, bool);
    void BSSimpleArray_TESAmmo_1024_SetAt(unsigned int, TESObjectREFR* const&);
};

struct LocalRefArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LocalRefArray();
    ~LocalRefArray();
    unsigned int FUN_0044ddc0();
    void FUN_007cb2e0(TESObjectREFR* const&);
    TESObjectREFR*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
};

extern BGSTerrainManager* DAT_011d8670;

// @fnv 0x006fca90
// src: XBOX_PDB 0x006fca90
void BGSTerrainManager::Update_006fca90(const NiPoint3& arPos, int aiFlags)
{
    if (DAT_0119f188 && *g_011d86ac.Bool())
    {
        NiPoint3 pos = arPos;
        aiFlags |= 1;
        tagRECT rect;
        g_TES->FUN_00451020(&rect, 0.0f);
        SetRectCenterAndHalfExtents(&rect);
        if (DAT_011d8670 && DAT_011d8670 != this)
        {
            BGSTerrainManager* pOld = DAT_011d8670;
            DAT_011d8670 = this;
            pOld->UnloadAll_006fce00();
            if (DAT_011d86bc)
            {
                ((NiNode*)DAT_011d86bc)->DetachAllChildren_00572160();
            }
        }
        DAT_011d8670 = this;
        if (pRootTerrainNode)
        {
            bool b1 = (aiFlags & 1) != 0;
            bool b2 = (aiFlags & 2) != 0;
            bool b4 = (aiFlags & 4) != 0;
            bool m_bShaderFeatureActive = (aiFlags & 8) != 0;
            if (b1)
            {
                ((LodNode*)pRootTerrainNode)->UpdateTerrainNode(pos, b4);
                g_TES->TES_InitDistantTextureBlending();
                if (*DAT_011d869c.Bool())
                {
                    ((LodNode*)pRootTerrainNode)->UpdateBlock(pos, b2);
                }
            }
            if (m_bShaderFeatureActive && *DAT_011d8680.Bool())
            {
                unsigned int count;
                ((LodNode*)pRootTerrainNode)->BGSTerrainNode_UpdateTrees(pos);
                if (BGSDistantTreeBlock_GetBlockCount() > 0u && ((RefArray*)&kTerrainReferences)->FUN_0044ddc0() > 0)
                {
                    LocalRefArray kept;
                    count = ((RefArray*)&kTerrainReferences)->FUN_0044ddc0();
                    for (unsigned int i = 0; i < count; i++)
                    {
                        unsigned int val = GetTerrainReferenceID(((RefArray*)&kTerrainReferences)->FUN_00877a30(i));
                        BGSDistantTreeBlock* pBlock = GetDistantTreeBlockForPoint((void*)((const TESObjectREFR*)((RefArray*)&kTerrainReferences)->FUN_00877a30(i))->GetPos());
                        if (pBlock)
                        {
                            pBlock->MarkTreeInstance(val, true);
                        }
                        else
                        {
                            kept.FUN_007cb2e0(((RefArray*)&kTerrainReferences)->FUN_00877a30(i));
                        }
                    }
                    ((RefArray*)&kTerrainReferences)->FUN_008454f0(true);
                    if (kept.FUN_0044ddc0() > 0)
                    {
                        unsigned int keptCount = kept.FUN_0044ddc0();
                        ((RefArray*)&kTerrainReferences)->FUN_006f2290(keptCount, true);
                        for (unsigned int j = 0; j < keptCount; j++)
                        {
                            ((RefArray*)&kTerrainReferences)->BSSimpleArray_TESAmmo_1024_SetAt(j, kept.BSSimpleArray_NiAVObject_1024_GetAt(j));
                        }
                    }
                }
            }
        }
    }
    bNeedsImmediateUpdate = 0;
}

class TerrainRefProxy
{
  public:
    unsigned int GetRawId();
};

class TerrainTempBuffer
{
  public:
    TerrainTempBuffer(int aInit);
    ~TerrainTempBuffer();
    void Push(TerrainRefProxy* apRef);
    void Assign(unsigned int aValue);

    unsigned int m_00, m_04, m_08, m_0C, m_10, m_14, m_18, m_1C, m_20;
    unsigned int m_24, m_28, m_2C, m_30, m_34, m_38, m_3C, m_40, m_44;
    unsigned int m_48, m_4C, m_50, m_54, m_58, m_5C, m_60, m_64, m_68;
    unsigned int m_6C, m_70, m_74, m_78, m_7C, m_80, m_84, m_88;
};

void __cdecl UpdateSceneEntryRadii(TerrainRefProxy* apRef, TerrainTempBuffer* apBuf);
void __cdecl BGSDistantObjectBlock_ResetCullResults();

// @fnv 0x006fd080
void BGSTerrainManager::UpdateMultiBoundResults(NiCamera* apCamera)
{
    TerrainTempBuffer tempBuffer(0);
    tempBuffer.Push((TerrainRefProxy*)apCamera);
    tempBuffer.Assign(((TerrainRefProxy*)apCamera)->GetRawId());
    if (pRootTerrainNode != 0)
    {
        UpdateSceneEntryRadii((TerrainRefProxy*)apCamera, &tempBuffer);
        BGSDistantObjectBlock_ResetCullResults();
    }
}
