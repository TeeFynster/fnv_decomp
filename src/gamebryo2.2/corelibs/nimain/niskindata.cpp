// gamebryo2.2/corelibs/nimain/niskindata.cpp: NiSkinData, FakeSkin, SkinDataLike, SkinDataBounds and more (11 functions)

#include "niskindata_packet.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/GO.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiSkinData.h"
#include "../../../../include/NiSphere.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiPoint3.h"
#include <string.h>

// Keep the stream accessors local while approved stream storage is opaque.
inline unsigned int SkinFileVersion(const NiStream& stream)
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(&stream) + 0xd8);
}

inline NiBinaryStream* SkinInputStream(NiStream& stream)
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x24c);
}

inline void NiBinaryStream::Write(const void* pv, unsigned int uiBytes, unsigned int uiComponentSize)
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) +=
        (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 12))(
            this, pv, uiBytes, &uiComponentSize, 1);
}

inline void NiBinaryStream::ReadComp(void* value, unsigned int bytes, unsigned int component)
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) +=
        (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(
            this, value, bytes, &component, 1);
}
// Checks whether the root bone or any bone name is present in context.map, returning true on the first hit.
// @fnv 0x00a862d0
bool NiSkinData::MapSkinData(SkinMapContext& context)
{
    ShaderBufferRecord* result;
    if (context.map->GetAt(root, result))
        return true;
    unsigned int count = bones->count;
    for (unsigned int i = 0; i < count; ++i)
        if (context.map->GetAt(names[i], result))
            return true;
    return false;
}

// NiStream has no error setter declaration; keep its out-of-line call here.
struct SkinLoadError
{
    __declspec(noinline) void SetError(int value);
};

// @fnv 0x00a632e0
void SkinLoadError::SetError(int value)
{
    *(int*)((char*)this + 0x3b8) = value;
}

extern int g_011f5b24;

// Returns the address of the global variable g_011f5b24.
// @fnv 0x00a84d20
int __cdecl GetGlobalAddress()
{
    return (int)&g_011f5b24;
}

struct FakeSkin : NiObject
{
    GO m_sp;
    void NiSkinData_LinkObject(void* streamObject);
};
// @fnv 0x00a84ce0
// src: XBOX_PDB 0x00a84ce0
void FakeSkin::NiSkinData_LinkObject(void* streamObject)
{
    NiStream& kStream = *static_cast<NiStream*>(streamObject);
    NiObject::LinkObject(kStream);
    if (SkinFileVersion(kStream) >= 0x4000001 && SkinFileVersion(kStream) < 0xa010065)
        m_sp = kStream.GetLoadedObject();
}

extern int DAT_0109e574;
// @fnv 0x00a84d30
// src: EXE 0x00a84d30
void* __cdecl NiSkinData_CreateObject()
{
    void* p = BSFadeNode::operator new(0x48);
    if (p)
    {
        ((BSFadeNode*)p)->NiObject::NiObject();
        *(int*)p = (int)&DAT_0109e574;
        *(int*)((char*)p + 8) = 0;
        *(int*)((char*)p + 0x40) = 0;
        return p;
    }
    return 0;
}

struct SkinCompareEntry
{
    unsigned short key;
    unsigned short unk02;
    float value;
};

struct SkinCompareOps
{
    bool CompareSub(void* other);
    bool CompareTail(void* other);
    bool CompareRoot(void* other);
    char unk00[0x10];
};

struct SkinShape
{
    char unk00[0x34];
    SkinCompareOps m_34;
    SkinCompareEntry* m_44;
    unsigned short m_48;
    unsigned short unk4a;
};

struct FUN_00a84d70_cls
{
    char unk00[0x0c];
    char unk0c[0x28];
    char unk34[0x0c];
    SkinShape* m_40;
    unsigned int m_44;
    bool Equals(FUN_00a84d70_cls* other);
};

// Compares this object with another: root, sub-block, count, then each shape's ops, tail, count and entry keys/values; returns true if all match.
// @fnv 0x00a84d70
bool FUN_00a84d70_cls::Equals(FUN_00a84d70_cls* other)
{
    if (!reinterpret_cast<SkinCompareOps*>(this)->CompareRoot(other))
    {
        return false;
    }
    if (reinterpret_cast<SkinCompareOps*>(&unk0c)->CompareSub(&other->unk0c))
    {
        return false;
    }
    if (m_44 != other->m_44)
    {
        return false;
    }
    for (unsigned int i = 0; i < m_44; ++i)
    {
        SkinShape* pShape = m_40 + i;
        SkinShape* pOtherShape = other->m_40 + i;
        if (reinterpret_cast<SkinCompareOps*>(pShape)->CompareSub(pOtherShape))
        {
            return false;
        }
        if (pShape->m_34.CompareTail(&pOtherShape->m_34))
        {
            return false;
        }
        if (pShape->m_48 != pOtherShape->m_48)
        {
            return false;
        }
        for (unsigned int j = 0; j < pShape->m_48; ++j)
        {
            if (pShape->m_44[j].key != pOtherShape->m_44[j].key)
            {
                return false;
            }
            if (pShape->m_44[j].value != pOtherShape->m_44[j].value)
            {
                return false;
            }
        }
    }
    return true;
}

struct S_00a84e70_Pool
{
    void* Game_DoHeapAlloc(unsigned int size);
    void MemoryManager_Deallocate(void* p);
};
extern S_00a84e70_Pool DAT_011f6238;

struct S_00a84e70_Elem
{
    int unk00;
    int unk04;
    int unk08;
    static void* operator new[](unsigned int size)
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
};

struct S_00a84e70_Array
{
    S_00a84e70_Elem* m_data;
    unsigned int m_pRayCursor;
    unsigned int m_uiItemCount;
    void Reserve(unsigned int newCapacity);
};

// @fnv 0x00a84e70
void S_00a84e70_Array::Reserve(unsigned int newCapacity)
{
    if (newCapacity == m_pRayCursor)
    {
        return;
    }
    S_00a84e70_Elem* newData;
    if (newCapacity > 0)
    {
        newData = new S_00a84e70_Elem[newCapacity];
        for (unsigned int i = 0; i < m_uiItemCount; i++)
        {
            newData[i] = m_data[i];
        }
    }
    else
    {
        newData = 0;
    }
    DAT_011f6238.MemoryManager_Deallocate(m_data);
    m_data = newData;
    m_pRayCursor = newCapacity;
}

template <class T> inline void SkinSaveBinary(NiStream& kStream, T& val)
{
    NiBinaryStream* pkBS = *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x250);
    pkBS->Write(&val, sizeof(T), sizeof(T));
}

struct SkinTransform
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    float tx, ty, tz;
    float scale;
    void SaveBinary(NiStream& kStream);
};

struct SkinBoneVertData
{
    unsigned short m_usBoneIndex;
    float m_fWeight;
};

struct SkinBoneData
{
    SkinTransform m_kSkinToBoneTransform;
    NiSphere m_kBound;
    SkinBoneVertData* m_pkVertexWeights;
    unsigned short m_usVertexWeightCount;
};

struct SkinObjectBase : NiObject
{
    int unk08;
    void SaveBinary(NiStream& kStream);
};

struct SkinDataLike : SkinObjectBase
{
    SkinTransform m_kSkinTransform;
    SkinBoneData* m_pBoneData;
    unsigned int m_uiBoneCount;
    void NiSkinData_SaveBinary(void* streamObject);
};

// Saves the skin object base, transform, bone count, vertex-weight flag and each bone's transform, bound, vertex count and optional vertex weights to the stream.
// @fnv 0x00a85250
// src: XBOX_PDB 0x00a85250
void SkinDataLike::NiSkinData_SaveBinary(void* streamObject)
{
    NiStream& kStream = *static_cast<NiStream*>(streamObject);
    SkinObjectBase::SaveBinary(kStream);
    m_kSkinTransform.SaveBinary(kStream);
    SkinSaveBinary(kStream, m_uiBoneCount);
    bool bHasVertexWeights = m_pBoneData->m_pkVertexWeights != 0;
    SkinSaveBinary(kStream, bHasVertexWeights);

    for (unsigned int i = 0; i < m_uiBoneCount; i++)
    {
        SkinBoneData* pkBoneData = &m_pBoneData[i];
        pkBoneData->m_kSkinToBoneTransform.SaveBinary(kStream);
        pkBoneData->m_kBound.SaveBinary(kStream);
        SkinSaveBinary(kStream, pkBoneData->m_usVertexWeightCount);
        if (bHasVertexWeights)
        {
            for (unsigned int j = 0; j < pkBoneData->m_usVertexWeightCount; j++)
            {
                SkinBoneVertData* pkVert = &pkBoneData->m_pkVertexWeights[j];
                SkinSaveBinary(kStream, pkVert->m_usBoneIndex);
                SkinSaveBinary(kStream, pkVert->m_fWeight);
            }
        }
    }
}

struct PoolBounds
{
    void MemoryManager_Deallocate(void* p) throw();
};
struct PointList
{
    NiPoint3* m_data;
    unsigned int m_pRayCursor;
    unsigned int m_uiItemCount;
    PointList() throw() : m_data(0), m_pRayCursor(0), m_uiItemCount(0)
    {}
    ~PointList() throw()
    {
        reinterpret_cast<PoolBounds*>(&DAT_011f6238)->MemoryManager_Deallocate(m_data);
    }
    __declspec(noalias) void Reserve(unsigned int capacity) throw();
    void Append(const NiPoint3& p) throw()
    {
        if (m_uiItemCount == m_pRayCursor)
            Reserve(m_pRayCursor > 0 ? 2 * m_pRayCursor : 1);
        memcpy(m_data + m_uiItemCount, &p, sizeof(p));
        ++m_uiItemCount;
    }
};
// NiSphere does not yet declare the bounding and transform operations.
struct BoundBuilder
{
    void ComputeBoundingSphere(unsigned int count, NiPoint3* points) throw();
    void FUN_00a7fdd0(const NiSphere& bound, const SkinTransform& transform) throw();
};

struct SkinDataBounds : SkinObjectBase
{
    SkinTransform m_kSkinTransform;
    SkinBoneData* m_pBoneData;
    unsigned int m_uiBoneCount;
    void NiSkinData_ComputeBoneBounds(NiPoint3* vertices);
};

// For each bone, collects vertex positions from its weighted vertices, computes their bounding sphere, and transforms it into bone space.
// @fnv 0x00a853c0
// src: XBOX_PDB 0x00a853c0
void SkinDataBounds::NiSkinData_ComputeBoneBounds(NiPoint3* vertices)
{
    PointList points;
    for (unsigned int i = 0; i < m_uiBoneCount; ++i)
    {
        for (unsigned int j = 0; j < m_pBoneData[i].m_usVertexWeightCount; ++j)
        {
            NiPoint3* pVertex = vertices + m_pBoneData[i].m_pkVertexWeights[j].m_usBoneIndex;
            points.Append(*pVertex);
        }
        reinterpret_cast<BoundBuilder*>(&m_pBoneData[i].m_kBound)
            ->ComputeBoundingSphere(points.m_uiItemCount, points.m_data);
        reinterpret_cast<BoundBuilder*>(&m_pBoneData[i].m_kBound)
            ->FUN_00a7fdd0(m_pBoneData[i].m_kBound, m_pBoneData[i].m_kSkinToBoneTransform);
        points.m_uiItemCount = 0;
    }
}

#include <windows.h>
extern int DAT_0109e574;

struct a84ef0_Counted
{
    virtual void v00();
    virtual void Release();
    int refCount;
};

struct a84ef0_Mgr
{
    void MemoryManager_Deallocate(unsigned int value);
};

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00a84ef0_cls
{
    int m_vptr;
    int unk04;
    a84ef0_Counted* m_pCounted;
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
    int unk34;
    int unk38;
    int unk3c;
    unsigned int m_uValue;

    void BaseCleanupA();
    void BaseCleanupB();
    FUN_00a84ef0_cls* FUN_00a84ef0(unsigned char acFlags);
};

// @fnv 0x00a84ef0
FUN_00a84ef0_cls* FUN_00a84ef0_cls::FUN_00a84ef0(unsigned char acFlags)
{
    m_vptr = (int)&DAT_0109e574;
    BaseCleanupA();
    ((a84ef0_Mgr*)&DAT_011f6238)->MemoryManager_Deallocate(m_uValue);
    a84ef0_Counted* pCounted = m_pCounted;
    if (pCounted != 0)
    {
        if (InterlockedDecrement((long volatile*)&pCounted->refCount) == 0)
        {
            pCounted->Release();
        }
    }
    BaseCleanupB();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x48);
    }
    return this;
}

namespace SkinDataText {
extern "C" const char DAT_0109e644[];
extern "C" const char DAT_0109e60c[];
extern "C" const char DAT_0109e600[];
}
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern int __cdecl FUN_00aa1360(const char*, const char*);
extern void(__cdecl* DAT_011ac2ac)(const char*, const char*, int);
struct SkinLoadTransform
{
    void FUN_00a86c80(NiStream&);
};
template <class T> inline void SkinLoadBinary(NiStream& stream, T& value)
{
    NiBinaryStream* input = SkinInputStream(stream);
    input->ReadComp(&value, sizeof(T), sizeof(T));
}
struct SkinLoadWeight
{
    unsigned short vertex;
    float weight;
    SkinLoadWeight() : vertex(0)
    {}
    static void* operator new[](unsigned int size)
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
};
struct ResetFields
{
    SkinTransform transform;
    NiSphere bound;
    SkinLoadWeight* weights;
    unsigned short vertices;
    ResetFields() throw();
    static void* operator new[](unsigned int size)
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
};
struct SkinLoadData : SkinObjectBase
{
    SkinTransform rootParentToSkin;
    ResetFields* bones;
    unsigned int boneCount;
    void NiSkinData_LoadBinary(void* streamObject);
};
// Reads skin data from a stream: base, transform, bone count, per-bone transforms/bounds/weights, and an optional trailing flag.
// @fnv 0x00a84f50
// src: XBOX_PDB 0x00a84f50
void SkinLoadData::NiSkinData_LoadBinary(void* streamObject)
{
    NiStream& stream = *static_cast<NiStream*>(streamObject);
    NiObject::LoadBinary(stream);
    ((SkinLoadTransform*)&rootParentToSkin)->FUN_00a86c80(stream);
    SkinLoadBinary(stream, boneCount);
    bones = new ResetFields[boneCount];
    if (SkinFileVersion(stream) >= 0x04000001 && SkinFileVersion(stream) < 0x0a010065)
        stream.ReadLinkIDStub();
    bool hasWeights;
    if (SkinFileVersion(stream) >= 0x0401000d)
        SkinLoadBinary(stream, hasWeights);
    else
        hasWeights = true;
    char message[0x200];
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&stream) + 0xdc) < 11 &&
        *reinterpret_cast<int*>(reinterpret_cast<char*>(&stream) + 0x3b8) == 0 && boneCount != 0 &&
        FUN_00aa1360((const char*)&stream + 0xe0, "Meshes\\Creatures\\Rat\\mange.NIF"))
    {
        ((SkinLoadError*)&stream)->SetError(3);
        if (*((const char*)&stream + 8))
            sprintf(message, SkinDataText::DAT_0109e644, ((const char*)&stream + 8), (const char*)&stream + 0xe0);
        else
            sprintf(message, SkinDataText::DAT_0109e60c, (const char*)&stream + 0xe0);
        if (DAT_011ac2ac)
            DAT_011ac2ac(message, SkinDataText::DAT_0109e600, 0);
    }
    for (unsigned int i = 0; i < boneCount; ++i)
    {
        ResetFields& bone = bones[i];
        ((SkinLoadTransform*)&bone.transform)->FUN_00a86c80(stream);
        bone.bound.LoadBinary(stream);
        SkinLoadBinary(stream, bone.vertices);
        if (hasWeights)
        {
            bone.weights = new SkinLoadWeight[bone.vertices];
            for (unsigned int j = 0; j < bone.vertices; ++j)
            {
                SkinLoadWeight& weight = bone.weights[j];
                SkinLoadBinary(stream, weight.vertex);
                SkinLoadBinary(stream, weight.weight);
            }
        }
        else
        {
            bone.weights = 0;
        }
    }
    if (SkinFileVersion(stream) == 0x04010009)
    {
        bool unused;
        SkinLoadBinary(stream, unused);
    }
}
