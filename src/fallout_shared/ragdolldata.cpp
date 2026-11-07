// fallout_shared/ragdolldata.cpp: RagDollData, RagDollRefUpdater, RagDollWalker and more (17 functions)

#include "layout_support.h"
#include "../../include/TESObjectREFR.h"

#include "../../include/NiAVObject.h"
#include "../../include/NiNode.h"
#include "../../include/NiUpdateData.h"
#include "../../include/bhkWorldObject.h"
#include "../../include/bhkCollisionObject.h"
#include "../../include/bhkFilter.h"
class RagdollCollisionFlags : public bhkCollisionObject
{
  public:
    void SetFlags(bool abSet, unsigned short uFlags);
};

typedef void (__thiscall* RagdollCollisionUpdate)(bhkCollisionObject*, int, int, int);

bhkCollisionObject* bhkNiCollisionObject_GetbhkNiCollisionObject(NiNode*);
struct TransformEntry
{
    signed char id;
    NiPoint3 translate;
    NiPoint3 rotate;
};
// Retained locally: include/ has no RagDollData.h. The former RagDollDataEx
// used this layout and called RagDollData routines at 0x004da340, 0x004da010 and 0x004d9bd0.
class RagDollData
{
  public:
    unsigned char count;
    TransformEntry* bones;
    bool FindBoneIndex(NiNode*, unsigned int&);
    void ReadFromActor(TESObjectREFR* apRef);
    void ReadFromRef(TESObjectREFR* apRef);
    bool ApplyToAnimationData(NiNode* apNode, unsigned int& auiIndex, unsigned int auiDepth);
    bool UpdateDataFromReference(TESObjectREFR* apRef);
};

// Returns the negation of operator== for this matrix compared with another matrix.
// @fnv 0x004d9ab0
bool NiMatrix3::operator!=(const NiMatrix3& matrix) const
{
    return !(*this == matrix);
}

// Recursively applies stored bone translation and rotation to node and its children, advancing index while bones remain.
// @fnv 0x004d9dc0
bool RagDollData::FindBoneIndex(NiNode* node, unsigned int& ruiIndex)
{
    bool result = true;
    if (node && ruiIndex < count)
    {
        bhkCollisionObject* collision = bhkNiCollisionObject_GetbhkNiCollisionObject(node);
        if (collision)
        {
            {
                int id = collision->bhkNiCollisionObject_GetWorldObject()->bhkWorldObject_GetCollisionFilter().CFilter_GetPart();
                if (bones[ruiIndex].id != id)
                    return false;
            }
            node->NiAVObject_SetTranslate(bones[ruiIndex].translate);
            NiMatrix3 rotation;
            rotation.FromEulerAnglesXYZ(bones[ruiIndex].rotate.x, bones[ruiIndex].rotate.y, bones[ruiIndex].rotate.z);
            node->SetRotate_0043fa80(&rotation);
            collision->bhkNiCollisionObject_SetReset(true);
            reinterpret_cast<RagdollCollisionUpdate>((*reinterpret_cast<void***>(collision))[0xb0 / 4])(collision, 1, 0, 0);
            ++ruiIndex;
        }
        NiUpdateData update(0.0f, false, false);
        node->UpdateWorldData(update);
        unsigned int children = node->FUN_0043b480();
        for (unsigned int i = 0; i < children; ++i)
        {
            NiNode* childNode;
            {
                NiAVObject* child = node->FUN_0043b4a0(i);
                childNode = child ? child->IsSceneNode() : 0;
            }
            if (childNode && !FindBoneIndex(childNode, ruiIndex))
                result = false;
            if (ruiIndex >= count)
                break;
        }
    }
    return result;
}

struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
typedef char _sizecheck_CFilter[sizeof(CFilter) == 4 ? 1 : -1];
struct FUN_004d9da0_shell : public CFilter
{
    unsigned int CFilter_GetPart();
};

// @fnv 0x004d9da0
// src: XBOX_PDB 0x004d9da0
unsigned int FUN_004d9da0_shell::CFilter_GetPart()
{
    return (iFilter >> 8) & 0x1f;
}

// @fnv 0x004d9fa0
// src: COMMUNITY 0x004d9fa0
void bhkCollisionObject::bhkNiCollisionObject_SetReset(bool abTF)
{
    static_cast<RagdollCollisionFlags*>(this)->SetFlags(abTF, 0x40);
}

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int* p, EndianSizeTag<4>);

struct FUN_004d9280
{
    void __thiscall EndianSwap();
};

// Byte-swaps the six 4-byte words following the object's first word via BSEndian.
// @fnv 0x004d9280
void __thiscall FUN_004d9280::EndianSwap()
{
    BSEndian((int*)this + 1, EndianSizeTag<4>());
    BSEndian((int*)this + 2, EndianSizeTag<4>());
    BSEndian((int*)this + 3, EndianSizeTag<4>());
    BSEndian((int*)this + 4, EndianSizeTag<4>());
    BSEndian((int*)this + 5, EndianSizeTag<4>());
    BSEndian((int*)this + 6, EndianSizeTag<4>());
}

// Sets or clears the given flag bits in the 16-bit flags field at offset 0xc of this object.
// @fnv 0x004d9fc0
void RagdollCollisionFlags::SetFlags(bool abSet, unsigned short uFlags)
{
    if (abSet)
        ((unsigned short*)((char*)this + 0xc))[0] |= uFlags;
    else
        ((unsigned short*)((char*)this + 0xc))[0] &= ~uFlags;
}

// Recursively counts node and its descendants for which FUN_004a8b00 returns true, returning the total count.
// @fnv 0x004da180
// src: GUESS 0x004da180 (confidence: medium)
unsigned char NiAVObject_CountCollisionNodes(NiNode* node)
{
    unsigned char count = 0;
    if (node)
    {
        if (bhkNiCollisionObject_GetbhkNiCollisionObject(node))
            ++count;
        unsigned int total = node->FUN_0043b480();
        for (unsigned int i = 0; i < total; ++i)
        {
            NiAVObject* object = node->FUN_0043b4a0(i);
            NiNode* child = object ? object->IsSceneNode() : 0;
            if (child)
                count += NiAVObject_CountCollisionNodes(child);
        }
    }
    return count;
}

// TESFileAccessor_ragdolldata: local type (was include/TESFileAccessor.h, which had no evidence of one real class); its methods are 0x00401680 TESFile::QEndian
class TESFileAccessor_ragdolldata
{
public:
    bool GetChunkData();
};
namespace fnv_004d94a0 {
struct FUN_004d94a0_shell : public RagDollData
{
    bool LoadRagdollChunk(TESFile*);
};

void* __cdecl operator new(unsigned int);
template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<1>);
struct FUN_004d9280
{
    void EndianSwap();
};
struct FUN_0055a400 : FUN_004d9280
{
    char pad[0x1c];
    FUN_0055a400();
};
// @fnv 0x004d94a0
bool FUN_004d94a0_shell::LoadRagdollChunk(TESFile* apFile)
{
    bool bretval = false;
    if (apFile->GetChunkID() == 0x44475258)
    {
        unsigned int isize = apFile->GetChunkSize();
        *(unsigned char*)this = isize / sizeof(FUN_0055a400);
        if (isize % *(unsigned char*)this == 0)
        {
            *(FUN_0055a400**)((char*)this + 4) = new FUN_0055a400[*(unsigned char*)this];
            apFile->GetChunkData(*(FUN_0055a400**)((char*)this + 4), isize);
            if (((TESFileAccessor_ragdolldata*)apFile)->GetChunkData())
            {
                for (unsigned int I = 0; I < *(unsigned char*)this; I++)
                    (*(FUN_0055a400**)((char*)this + 4))[I].EndianSwap();
            }
            bretval = true;
        }
        else
            *(unsigned char*)this = 0;
    }
    if (apFile->GetChunkID() == 0x42475258)
    {
        apFile->GetChunkData((char*)this + 8, 0xc);
        if (((TESFileAccessor_ragdolldata*)apFile)->GetChunkData())
        {
            BSEndian((unsigned char*)this + 8, EndianSizeTag<1>());
            BSEndian((unsigned char*)this + 0xc, EndianSizeTag<1>());
            BSEndian((unsigned char*)this + 0x10, EndianSizeTag<1>());
        }
        bretval = true;
    }
    return bretval;
}
}  // namespace fnv_004d94a0

struct Call_439090
{
    bool operator==(const Call_439090& a) const;
};

int _memcmp(const void*, const void*, unsigned int);

struct FUN_004d9780_shell
{
    unsigned char m_ucValue;
    TransformEntry* m_pTransformEntry;
    bool RagDollData_Compare(FUN_004d9780_shell* apCompare);
};

// @fnv 0x004d9780
// src: XBOX_PDB 0x004d9780
bool FUN_004d9780_shell::RagDollData_Compare(FUN_004d9780_shell* apCompare)
{
    if (!apCompare)
        return true;
    if (m_ucValue != apCompare->m_ucValue)
        return true;
    if (*(Call_439090*)((char*)this + 8) == *(Call_439090*)((char*)apCompare + 8))
        return true;
    if (m_ucValue && _memcmp(m_pTransformEntry, apCompare->m_pTransformEntry, m_ucValue * 0x1c))
        return true;
    return false;
}

extern void __cdecl _Deallocate(void*);
extern void* __cdecl __memcpy(void*, const void*, unsigned int);
extern unsigned int _data_011c16bc;

struct DoorTeleportLoadData
{
    unsigned int data[7];

    DoorTeleportLoadData();
};

struct FUN_004d9670_shell
{
    // 12-byte block at +0x08 that FUN_004d9670 copies by value (3 dword moves); identity unknown
    struct Payload0C
    {
        unsigned int value0;
        unsigned int value1;
        unsigned int value2;
    };

    unsigned char count;
    DoorTeleportLoadData* items;
    Payload0C data;

    void RagDollData_Copy(const FUN_004d9670_shell* source);
};

// Copies count, data and the items array from source into this object, reallocating the items buffer.
// @fnv 0x004d9670
// src: COMMUNITY 0x004d9670
void FUN_004d9670_shell::RagDollData_Copy(const FUN_004d9670_shell* source)
{
    if (source)
    {
        DoorTeleportLoadData* oldItems = items;
        _Deallocate(oldItems);

        count = source->count;
        data = source->data;

        items = new DoorTeleportLoadData[count];

        __memcpy(items, source->items, count * sizeof(DoorTeleportLoadData));
    }
}

struct FUN_004d93c0_bone
{
    signed char unk00;
    float translate[3];
    float rotate[3];
    void EndianSwap();
};

struct FUN_004d93c0_name
{
    unsigned int m_00;
    unsigned int m_04;
    bool Matches(const char* name);
};

struct FUN_004d93c0_cls
{
    unsigned char m_uiItemCount;
    FUN_004d93c0_bone* m_kBones;
    FUN_004d93c0_name m_name;
    void RagDollData_Save();
};

bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl AppendChunk(unsigned int tag, void* p, unsigned int size);
void __cdecl TESForm_AddChunkArray_00485710(unsigned int tag, void* p, unsigned int n);
extern char DAT_011f426c[];

// @fnv 0x004d93c0
// src: COMMUNITY 0x004d93c0
void FUN_004d93c0_cls::RagDollData_Save()
{
    if (m_uiItemCount != 0)
    {
        if (TESForm_QEndianSwapOnSave())
        {
            for (unsigned int i = 0; i < m_uiItemCount; i++)
            {
                m_kBones[i].EndianSwap();
            }
        }
        AppendChunk(0x44475258, m_kBones, m_uiItemCount * 28);
        if (TESForm_QEndianSwapOnSave())
        {
            for (unsigned int uiSwapIndex = 0; uiSwapIndex < m_uiItemCount; uiSwapIndex++)
            {
                m_kBones[uiSwapIndex].EndianSwap();
            }
        }
    }
    if (m_name.Matches(DAT_011f426c))
    {
        TESForm_AddChunkArray_00485710(0x42475258, &m_name, 3);
    }
}

// @fnv 0x004d9800
// src: XBOX_PDB 0x004d9800
bool RagDollData::UpdateDataFromReference(TESObjectREFR* apRef)
{
    unsigned int uiIndex = 0;
    bool bResultTmp = true;
    if (apRef && apRef->GetNiNode())
    {
        NiAVObject* p3D = apRef->GetNiNode();
        NiNode* pNode2 = p3D ? p3D->IsSceneNode() : 0;
        if (apRef->IsActor())
            ReadFromActor(apRef);
        if (!count)
            ReadFromRef(apRef);
        if (count)
            bResultTmp = ApplyToAnimationData(pNode2, uiIndex, 0);
        if (!bResultTmp)
            ReadFromRef(apRef);
    }
    return uiIndex == count && bResultTmp;
}


struct NiPoint3Cmp
{
    bool NotEqual(const NiPoint3& pt) const;
};

struct NiMatrix3Cmp
{
    bool NotEqual(const NiMatrix3& m) const;
};

void __cdecl bhkNiCollisionObject_ResetSim(NiAVObject* apObject, bool abFlag);
void __cdecl bhkWorld_SetMotion(NiNode* apNode, int aiVal, bool ab1, bool ab2, bool ab3);

struct RagDollRefUpdater
{
    bool bEnabled;
    void SyncRef(TESObjectREFR* apRef);
    bool ApplyToAnimationData(NiNode* apNode, unsigned int& auiCount);
    bool RagDollData_UpdateReferenceFromData(TESObjectREFR* apRef);
};

// @fnv 0x004d9910
// src: XBOX_PDB 0x004d9910
bool RagDollRefUpdater::RagDollData_UpdateReferenceFromData(TESObjectREFR* apRef)
{
    unsigned int ItemUpdateArray = 0;
    bool bResult = true;
    if (apRef && apRef->Get3DSimple() && bEnabled)
    {
        NiAVObject* p3D2 = apRef->Get3DSimple();
        NiNode* pNode4 = p3D2 ? p3D2->IsSceneNode() : 0;
        if (apRef->IsActor())
            SyncRef(apRef);
        bResult = ApplyToAnimationData(pNode4, ItemUpdateArray);
        if (p3D2)
        {
            if (((NiPoint3Cmp&)p3D2->GetTranslate_0043c490()).NotEqual(*static_cast<const TESObjectREFR*>(apRef)->GetPos()) ||
                ((NiMatrix3Cmp&)p3D2->NiAVObject_GetRotate_006a9540()).NotEqual(apRef->GetRotation()))
            {
                p3D2->NiAVObject_SetTranslate(*static_cast<const TESObjectREFR*>(apRef)->GetPos());
                p3D2->SetRotate_0043fa80(apRef->GetRotation());
                bhkNiCollisionObject_ResetSim(p3D2, true);
                NiUpdateData kData6(0.0f, false, false);
                p3D2->Update(kData6);
            }
        }
        if (!bResult)
            bhkWorld_SetMotion(pNode4, 1, 1, 0, 1);
    }
    return ItemUpdateArray == bEnabled && bResult;
}


struct RagDollWalker
{
    unsigned char count;
    TransformEntry* bones;
    bool CollectBoneTransforms(NiNode* apNode, unsigned int& arIndex, bool abSet);
};

// @fnv 0x004d9bd0
bool RagDollWalker::CollectBoneTransforms(NiNode* apNode, unsigned int& arIndex, bool abSet)
{
    bool bResult2 = true;
    if (apNode && arIndex < count)
    {
        bhkCollisionObject* pCollision = bhkNiCollisionObject_GetbhkNiCollisionObject(apNode);
        if (pCollision)
        {
            if (abSet)
            {
                bones[arIndex].id = pCollision->bhkNiCollisionObject_GetWorldObject()->bhkWorldObject_GetCollisionFilter().CFilter_GetPart();
            }
            else if (bones[arIndex].id != pCollision->bhkNiCollisionObject_GetWorldObject()->bhkWorldObject_GetCollisionFilter().CFilter_GetPart())
            {
                return false;
            }
            bones[arIndex].translate = apNode->GetTranslate_0043c490();
            apNode->NiAVObject_GetRotate_006a9540().ToEulerAnglesXYZ(
                bones[arIndex].rotate.x, bones[arIndex].rotate.y, bones[arIndex].rotate.z);
            arIndex++;
        }
        unsigned int uiCount5 = apNode->FUN_0043b480();
        for (unsigned int i3 = 0; i3 < uiCount5; i3++)
        {
            NiAVObject* pChild2 = apNode->FUN_0043b4a0(i3);
            NiNode* pChildNode = pChild2 ? pChild2->IsSceneNode() : 0;
            if (pChildNode)
            {
                if (!CollectBoneTransforms(pChildNode, arIndex, abSet))
                {
                    bResult2 = false;
                }
            }
            if (arIndex >= count)
            {
                break;
            }
        }
    }
    return bResult2;
}

struct LocalRagdollTransform
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    void RagDollData_UpdateRagDollDataFromBip01Node(TESObjectREFR* source);
};
// @fnv 0x004da340
// src: XBOX_PDB 0x004da340
void LocalRagdollTransform::RagDollData_UpdateRagDollDataFromBip01Node(TESObjectREFR* source)
{
    NiAVObject* pObject = source && source->IsActor() ? source->GetNiNode() : 0;
    NiNode* node = pObject ? pObject->IsSceneNode() : 0;
    if (node != 0)
    {
        NiAVObject* link = node->NiNode_GetAtChecked(0);
        if (link != 0)
        {
            link->NiAVObject_GetRotate_006a9540().ToEulerAnglesXYZ(
                reinterpret_cast<float&>(field08), reinterpret_cast<float&>(field0c), reinterpret_cast<float&>(field10));
        }
    }
}

extern NiPoint3 _NiPoint3_ZERO;



struct FUN_004da230_shell
{
    unsigned int unk00;
    unsigned int unk04;
    NiPoint3 position;
    void UpdateNodeFromPosition(TESObjectREFR* object);
};

// @fnv 0x004da230
void FUN_004da230_shell::UpdateNodeFromPosition(TESObjectREFR* object)
{
    if (reinterpret_cast<Call_439090&>(position) == reinterpret_cast<Call_439090&>(_NiPoint3_ZERO))
    {
        NiAVObject* pContainer;
        NiNode* pNode;

        pContainer = (object != 0 && object->IsActor()) ? object->GetNiNode() : 0;
        pNode = (pContainer != 0) ? pContainer->IsSceneNode() : 0;

        if (pNode != 0)
        {
            NiNode* node = static_cast<NiNode*>(pNode->NiNode_GetAtChecked(0));
            if (node != 0)
            {
                NiMatrix3 rotation;
                rotation.FromEulerAnglesXYZ(position.x, position.y, position.z);
                node->SetRotate_0043fa80(&rotation);
                NiUpdateData update(0.0f, false, false);
                node->UpdateWorldData(update);
            }
        }
    }
}

unsigned char NiAVObject_CountCollisionNodes(NiNode* node);
void FNV_Warning(const char* fmt, ...);

struct RagDollBoneInit : public TransformEntry
{
    RagDollBoneInit();
};

class RagDollDataInit : public RagDollData
{
  public:
    void InitFromRef(TESObjectREFR* apRef);
};

// Initializes ragdoll bone data from a reference's 3D node, collecting bone transforms and warning on failure.
// @fnv 0x004da010
void RagDollDataInit::InitFromRef(TESObjectREFR* apRef)
{
    count = 0;
    delete[] bones;
    if (apRef && apRef->GetNiNode())
    {
        NiAVObject* pObj = apRef->GetNiNode();
        NiNode* pNode = pObj ? pObj->IsSceneNode() : 0;
        count = NiAVObject_CountCollisionNodes(pNode);
        if (count)
        {
            bones = new RagDollBoneInit[count];
            unsigned int uiIndex = 0;
            if (!((RagDollWalker*)this)->CollectBoneTransforms(pNode, uiIndex, true))
                FNV_Warning("HAVOK: Failed to initialize RagDollData.");
        }
    }
}
