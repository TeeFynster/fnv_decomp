#include "../../../../include/NiTArray.h"
// gamebryo2.2/corelibs/nimain/niparticlesdata.cpp: particle data (14 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiParticlesData.h"
#include <string.h>

class IMemoryHeap;
#include "MemoryManager.h"

// The shared stream keeps its layout opaque; retain the original inline writer access.
inline WriteStream* NiStream::GetWriter()
{
    return reinterpret_cast<WriteStream*&>(m_pkOstr);
}

extern MemoryManager g_memoryManager;

// @fnv 0x00a968a0
void NiParticlesData::SetRotations(NiQuaternion* pkRotations)
{
    g_memoryManager.Deallocate(m_pkRotations);
    m_pkRotations = pkRotations;
}

void __cdecl _NiFreeAlias(void* p);

// Clamps param_3 to 0x10, frees the pointer at this_ptr+0x68, stores the clamped byte at +0x6c and param_2 at +0x68.
// @fnv 0x00a968e0
// src: COMMUNITY 0x00a968e0
void __fastcall NiParticlesData_ReplaceSubTextureOffsets(char* this_ptr, int, void* param_2, unsigned char param_3)
{
    if (param_3 >= 0x10)
    {
        param_3 = 0x10;
    }
    _NiFreeAlias(*(void**)(this_ptr + 0x68));
    *(unsigned char*)(this_ptr + 0x6c) = param_3;
    *(void**)(this_ptr + 0x68) = param_2;
}

extern const char* const g_011f5f0c_arg1;

// @fnv 0x00a967d0
// src: COMMUNITY 0x00a967d0
const char* const* __cdecl NiParticlesData_GetRTTI()
{
    return &g_011f5f0c_arg1;
}

// Methods absent from the shared declaration use the shared particle layout.
struct ParticleDataMethods : NiParticlesData
{
    void SetPointer(void* p);
    void* Destroy(unsigned int flags);
};

// @fnv 0x00a968c0
void __thiscall ParticleDataMethods::SetPointer(void* apPointer)
{
    g_memoryManager.Deallocate(m_pkRotationAxes);
    m_pkRotationAxes = static_cast<NiPoint3*>(apPointer);
}

void __fastcall FUN_00a67c00(void* object);

extern char DAT_010a05e4[];

// @fnv 0x00a96600
// src: EXE 0x00a96600
void* NiParticlesData_CreateObject()
{
    NiParticlesData* p = (NiParticlesData*)BSFadeNode::operator new(sizeof(NiParticlesData));
    if (p)
    {
        FUN_00a67c00(p);
        *(void**)p = DAT_010a05e4;
        p->m_pfRadii = 0;
        p->m_usActive = 0;
        p->m_pfSizes = 0;
        p->m_pkRotations = 0;
        p->m_pfRotationAngles = 0;
        p->m_pkRotationAxes = 0;
        p->m_pucTextureIndices = 0;
        p->m_pkSubTextureOffsets = 0;
        p->m_ucSubTextureOffsetCount = 0;
        p->m_bHasRadii = false;
        p->SetDataConsistency(0);
        p->m_bSaveVertexData = false;
        return p;
    }
    return 0;
}

void __cdecl _delete(void*, unsigned int);
void __cdecl ReleaseStorage_00a96800();
// Calls FUN_00a96800, then deletes this with size 0x70 if flags has bit 0 set, and returns this.
// @fnv 0x00a96a10
void* __thiscall ParticleDataMethods::Destroy(unsigned int flags)
{
    ReleaseStorage_00a96800();
    if (flags & 1)
        _delete(this, 0x70);
    return this;
}

// Copies the last active particle's vertex, color, normal, radii, sizes, rotation and texture data into the given slot, then decrements m_usActive.
// @fnv 0x00a964c0
void NiParticlesData::vf41(unsigned short index)
{
    unsigned short last = m_usActive - 1;
    if (index != last)
    {
        m_pkVertex[index] = m_pkVertex[last];
        if (m_pkColor)
            m_pkColor[index] = m_pkColor[last];
        if (m_pkNormal)
            m_pkNormal[index] = m_pkNormal[last];
        if (m_pfRadii)
            m_pfRadii[index] = m_pfRadii[last];
        if (m_pfSizes)
            m_pfSizes[index] = m_pfSizes[last];
        if (m_pkRotations)
            memcpy(&m_pkRotations[index], &m_pkRotations[last], sizeof(NiQuaternion));
        if (m_pfRotationAngles)
            m_pfRotationAngles[index] = m_pfRotationAngles[last];
        if (m_pkRotationAxes)
            m_pkRotationAxes[index] = m_pkRotationAxes[last];
        if (m_pucTextureIndices)
            m_pucTextureIndices[index] = m_pucTextureIndices[last];
    }
    --m_usActive;
}

struct ParticleViewFrame
{
    unsigned int unk_00;
    unsigned int unk_04;
    unsigned int unk_08;
    unsigned int unk_0c;
    unsigned int unk_10;
    unsigned int unk_14;
    unsigned int unk_18;
    unsigned int unk_1c;
    unsigned int unk_20;
    unsigned int unk_24;
    unsigned int unk_28;
    unsigned int unk_2c;
    unsigned int unk_30;
    unsigned int unk_34;
    unsigned int unk_38;
    unsigned int unk_3c;
    unsigned int unk_40;
    unsigned int unk_44;
    unsigned int unk_48;
    unsigned int unk_4c;
    unsigned int unk_50;
    unsigned int unk_54;
    unsigned int unk_58;
    unsigned int unk_5c;
    unsigned int unk_60;
    NiPoint3 axisX, axisY, axisZ;
};
extern MemoryManager g_memoryManager;
inline void* operator new[](unsigned int bytes, MemoryManager& manager)
{
    return manager.Allocate(bytes);
}
struct ParticleViewData : NiParticlesData
{
    void NiParticlesData_QuickSortParticles(int, int);
    void NiParticlesData_SortParticles(ParticleViewFrame*);
};
// @fnv 0x00a96910
// src: XBOX_PDB 0x00a96910
void ParticleViewData::NiParticlesData_SortParticles(ParticleViewFrame* pViewFrame)
{
    if (!m_pusParticleIndices)
    {
        m_pusParticleIndices = new (g_memoryManager) unsigned short[m_usVertices];
        m_pfSortValues = new (g_memoryManager) float[m_usVertices];
    }
    for (unsigned short i = 0; i < m_usActive; ++i)
        m_pusParticleIndices[i] = i;
    if (m_usActive > 1)
    {
        NiPoint3 viewDirection;
        viewDirection.x = pViewFrame->axisX.y;
        viewDirection.y = pViewFrame->axisY.y;
        viewDirection.z = pViewFrame->axisZ.y;
        for (unsigned short i = 0; i < m_usActive; ++i)
        {
            const NiPoint3& p = m_pkVertex[i];
            m_pfSortValues[i] = p.Dot(viewDirection);
        }
        NiParticlesData_QuickSortParticles(0, m_usActive - 1);
    }
}

void* __cdecl Object_DispatchCommandFour(unsigned int uiSize);
__forceinline NiParticlesData* InitializeParticleData(NiParticlesData* p) throw()
{
    if (p)
    {
        FUN_00a67c00(p);
        *(void**)p = DAT_010a05e4;
        p->m_pfRadii = 0;
        p->m_usActive = 0;
        p->m_pfSizes = 0;
        p->m_pkRotations = 0;
        p->m_pfRotationAngles = 0;
        p->m_pkRotationAxes = 0;
        p->m_pucTextureIndices = 0;
        p->m_pkSubTextureOffsets = 0;
        p->m_ucSubTextureOffsetCount = 0;
        p->m_bHasRadii = false;
        p->FUN_00a67050(0);
        p->m_bSaveVertexData = false;
        return p;
    }
    return 0;
}


// Allocates particle data, initializes it, and enables radii.
// @fnv 0x00a96660
NiParticlesData* __cdecl CreateParticlesDataWithRadii()
{
    NiParticlesData* pkObj = InitializeParticleData((NiParticlesData*)Object_DispatchCommandFour(sizeof(NiParticlesData)));
    pkObj->m_bHasRadii = true;
    return pkObj;
}

inline bool EqualParticleRotation(const NiQuaternion& left, const NiQuaternion& right)
{
    return left.m_fVectorX == right.m_fVectorX && left.m_fVectorY == right.m_fVectorY &&
           left.m_fVectorZ == right.m_fVectorZ && left.m_fScalarPart == right.m_fScalarPart;
}
inline bool EqualParticleAxis(const NiPoint3& left, const NiPoint3& right)
{
    return left.x == right.x && left.y == right.y && left.z == right.z;
}
inline bool EqualParticleOffset(const NiColorA& left, const NiColorA& right)
{
    return left.r == right.r && left.g == right.g && left.b == right.b && left.a == right.a;
}
struct GeometryEquality : NiGeometryData
{
    bool NiGeometryData_IsEqual(NiObject* other);
};

// The original equality entry is non-const; the shared declaration only exposes
// the const overload. This helper adds its method without duplicating the layout.
struct ParticlesEquality : NiParticlesData
{
    bool IsParticleDataEqual(NiObject*);
};

// @fnv 0x00a96a30
bool ParticlesEquality::IsParticleDataEqual(NiObject* apOther)
{
    if (!static_cast<GeometryEquality*>(static_cast<NiGeometryData*>(this))->NiGeometryData_IsEqual(apOther))
        return false;
    NiParticlesData* other = static_cast<NiParticlesData*>(apOther);
    if ((m_pfRadii && !other->m_pfRadii) || (!m_pfRadii && other->m_pfRadii))
        return false;
    if (m_pfRadii)
    {
        for (unsigned short i = 0; i < m_usVertices; ++i)
            if (m_pfRadii[i] != other->m_pfRadii[i])
                return false;
    }
    if (m_usActive != other->m_usActive)
        return false;
    if ((m_pfSizes && !other->m_pfSizes) || (!m_pfSizes && other->m_pfSizes))
        return false;
    if (m_pfSizes)
    {
        for (unsigned short i = 0; i < m_usActive; ++i)
            if (m_pfSizes[i] != other->m_pfSizes[i])
                return false;
    }
    if ((m_pkRotations && !other->m_pkRotations) || (!m_pkRotations && other->m_pkRotations))
        return false;
    if (m_pkRotations)
    {
        for (unsigned int i = 0; i < m_usActive; ++i)
        {
            if (!EqualParticleRotation(m_pkRotations[i], other->m_pkRotations[i]))
                return false;
        }
    }
    if (m_pfRotationAngles)
    {
        for (unsigned int i = 0; i < m_usActive; ++i)
            if (m_pfRotationAngles[i] != other->m_pfRotationAngles[i])
                return false;
    }
    if (m_pkRotationAxes)
    {
        for (unsigned int i = 0; i < m_usActive; ++i)
        {
            if (!EqualParticleAxis(m_pkRotationAxes[i], other->m_pkRotationAxes[i]))
                return false;
        }
    }
    if (m_pucTextureIndices)
    {
        for (unsigned int i = 0; i < m_usActive; ++i)
            if (m_pucTextureIndices[i] != other->m_pucTextureIndices[i])
                return false;
    }
    if (m_pkSubTextureOffsets)
    {
        for (unsigned int i = 0; i < m_ucSubTextureOffsetCount; ++i)
        {
            if (!EqualParticleOffset(m_pkSubTextureOffsets[i], other->m_pkSubTextureOffsets[i]))
                return false;
        }
    }
    return true;
}

struct BinaryStream
{
    unsigned int unk00, position, unk08;
    unsigned int(__cdecl* writer)(BinaryStream*, const void*, unsigned int, const unsigned int*, unsigned int);
    void Write(const void* data, unsigned int size)
    {
        unsigned int component = size;
        position += writer(this, data, size, &component, 1);
    }
};
// Writes presence flags for radii, sizes, rotations, angles, axes and texture indices, then the sub-texture offset count and each offset to the stream.
// @fnv 0x00a97290
void NiParticlesData::SaveBinary(NiStream& stream)
{
    NiGeometryData::SaveBinary(stream);
    bool hasRadii = m_pfRadii != 0;
    reinterpret_cast<BinaryStream*>(stream.GetWriter())->Write(&hasRadii, 1);
    reinterpret_cast<BinaryStream*>(stream.GetWriter())->Write(&m_usActive, 2);
    bool hasSizes = m_pfSizes != 0;
    reinterpret_cast<BinaryStream*>(stream.GetWriter())->Write(&hasSizes, 1);
    bool hasRotations = m_pkRotations != 0;
    reinterpret_cast<BinaryStream*>(stream.GetWriter())->Write(&hasRotations, 1);
    bool hasAngles = m_pfRotationAngles != 0;
    reinterpret_cast<BinaryStream*>(stream.GetWriter())->Write(&hasAngles, 1);
    bool hasAxes = m_pkRotationAxes != 0;
    reinterpret_cast<BinaryStream*>(stream.GetWriter())->Write(&hasAxes, 1);
    bool hasIndices = m_pucTextureIndices != 0;
    reinterpret_cast<BinaryStream*>(stream.GetWriter())->Write(&hasIndices, 1);
    reinterpret_cast<BinaryStream*>(stream.GetWriter())->Write(&m_ucSubTextureOffsetCount, 1);
    for (unsigned int i = 0; i < m_ucSubTextureOffsetCount; i++)
        m_pkSubTextureOffsets[i].SaveBinary(stream);
}

template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::SetAt(unsigned int uiIndex, const T& element)
{
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != T(0))
                m_usESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
// The viewer appends through the array helpers; SetAt remains the call at 0x0096ae90.
template <class Value, class Storage> inline unsigned int NiTArray<Value, Storage>::SetAtGrow(unsigned int slot, const Value& incoming)
{
    if (slot >= m_usMaxSize) // src: GAMEBRYO_SRC (shape)
        SetSize(slot + m_usGrowBy);
    SetAt(slot, incoming);
    return slot;
}

template <class Value, class Storage> inline unsigned int NiTArray<Value, Storage>::Add(const Value& incoming)
{
    return this->SetAtGrow(this->m_usSize, incoming);
}

template <class Value, class Storage> inline unsigned int NiTArray<Value, Storage>::GetSize() const
{
    return this->m_usSize;
}

template <class Value, class Storage> inline const Value& NiTArray<Value, Storage>::GetAt(unsigned int slot) const
{
    return this->m_pBase[slot];
}

typedef NiTArray<char*, NiTMallocInterface<char*> > ParticleViewerStringsArray;

char* CreateDebugString(const char* pcName);
char* CreateDebugString(const char* pcName, unsigned short usValue);
char* CreateDebugString(const char* pcName, unsigned int uiValue);
char* CreateDebugString(const char* pcName, int iValue);
char* CreateDebugString(const char* pcName, const char* pcValue);
char* CreateDebugString(const char* pcName, void* pvValue);
char* CreateDebugString(const char* pcName, unsigned char ucValue);

extern const char* g_pcParticlesDataName;

class NiGeometryDataViewer
{
  public:
    virtual void v0();
    void GetViewerStrings(ParticleViewerStringsArray* pkStrings);
};

// Appends the base geometry viewer strings plus the particle radii, sizes, rotations, texture indices and sub-texture offsets to pkStrings.
// @fnv 0x00a97420
void NiParticlesData::GetViewerStrings(NiViewerStringsArray* strings)
{
    ParticleViewerStringsArray* pkStrings = reinterpret_cast<ParticleViewerStringsArray*>(strings);
    ((NiGeometryDataViewer*)this)->GetViewerStrings(pkStrings);

    pkStrings->Add(CreateDebugString(g_pcParticlesDataName));
    pkStrings->Add(CreateDebugString("m_pfRadii", (void*)m_pfRadii));
    pkStrings->Add(CreateDebugString("m_usActive", m_usActive));
    pkStrings->Add(CreateDebugString("m_pfSizes", (void*)m_pfSizes));
    pkStrings->Add(CreateDebugString("m_pkRotations", (void*)m_pkRotations));
    pkStrings->Add(CreateDebugString("m_pfRotationAngles", (void*)m_pfRotationAngles));
    pkStrings->Add(CreateDebugString("m_pkRotationAxes", (void*)m_pkRotationAxes));
    pkStrings->Add(CreateDebugString("m_pucTextureIndices", (void*)m_pucTextureIndices));
    pkStrings->Add(CreateDebugString("m_ucSubTextureOffsetCount", m_ucSubTextureOffsetCount));
    pkStrings->Add(CreateDebugString("m_pkSubTextureOffsets", (void*)m_pkSubTextureOffsets));
}

class RenderOrderSorter : public NiParticlesData
{
  public:
    void NiParticlesData_QuickSortParticles(int left, int right);
};
// Partitions m_pusParticleIndices between left and right around a pivot value from m_pfSortValues, then recurses on both sub-ranges.
// @fnv 0x00a966c0
// src: XBOX_PDB 0x00a966c0
void RenderOrderSorter::NiParticlesData_QuickSortParticles(int left, int right)
{
    int iLeft = left;
    int iRight = right;
    unsigned short usValue = m_pusParticleIndices[left];
    float fPivotValue = m_pfSortValues[m_pusParticleIndices[left]];
    while (left < right)
    {
        while ((m_pfSortValues[m_pusParticleIndices[right]] <= fPivotValue) && (left < right))
            right--;
        if (left != right)
        {
            m_pusParticleIndices[left] = m_pusParticleIndices[right];
            left++;
        }
        while ((m_pfSortValues[m_pusParticleIndices[left]] >= fPivotValue) && (left < right))
            left++;
        if (left != right)
        {
            m_pusParticleIndices[right] = m_pusParticleIndices[left];
            right--;
        }
    }
    m_pusParticleIndices[left] = usValue;
    int pivot = left;
    left = iLeft;
    right = iRight;
    if (left < pivot)
        NiParticlesData_QuickSortParticles(left, pivot - 1);
    if (right > pivot)
        NiParticlesData_QuickSortParticles(pivot + 1, right);
}

struct BinStream
{
    int unk0;
    int pos;
    int(__cdecl* readFn)(BinStream*, void*, int, void*, int);
    int Read(void* dest, int bytes, unsigned int elem)
    {
        unsigned int count = elem;
        int readBytes = readFn(this, dest, bytes, &count, 1);
        pos += readBytes;
        return readBytes;
    }
};
void* __cdecl _NiMalloc_00aa1070(unsigned int size);
void __cdecl ReadElements(NiStream* stream, float* arr, unsigned int count);
void __cdecl FUN_00ec61c0(void* p, int val, unsigned int n);
struct AllocSvc
{
    void* __thiscall Game_DoHeapAlloc(unsigned int n);
    void __thiscall MemoryManager_Deallocate(void* p);
};
extern AllocSvc DAT_011f6238;
struct ArrNew
{
    static void* operator new[](unsigned int n)
    {
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
};
extern float DAT_011a9ea4;
extern float DAT_011a9ea8;
extern float DAT_011a9eac;
extern float DAT_011a9eb0;
extern char DAT_011f5f0c;
struct Axis12 : ArrNew
{
    float ax;
    float ay;
    float az;
    void __thiscall FUN_00a59be0(NiStream* stream);
};
struct RTTILink
{
    const char* name;
    RTTILink* base;
};
struct RTTIView
{
    virtual void s0();
    virtual void s1();
    virtual RTTILink* GetRTTIChain();
};
template <class T> inline T* NewArray(unsigned short count)
{
    unsigned int elements = count;
    return new T[elements];
}
// Allocate quaternion storage without calling constructors; loading supplies every component.
inline NiQuaternion* NewParticleRotations(unsigned short count)
{
    unsigned int elements = count;
    return (NiQuaternion*)new ArrNew[elements][sizeof(NiQuaternion)];
}
// NiStream stores the user version, file version and input at +0x4, +0xd8 and +0x24c.
// Read its opaque storage directly to preserve the loader's original instruction selection.
// Reads particle-related values and flags from the stream, allocates arrays, and fills several arrays with defaults depending on version.
// @fnv 0x00a96cf0
void NiParticlesData::LoadBinary(NiStream& input)
{
    NiStream* stream = &input;
    union ReadValue
    {
        float radius;
        unsigned char flag;
    } value;
    NiGeometryData::LoadBinary(*stream);
    if (stream->m_uiNifFileVersion < 0x4010007)
    {
        BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
        kReadStream->Read(&value.radius, 2, 2);
    }
    m_pfRadii = (float*)_NiMalloc_00aa1070((unsigned int)m_usVertices * 4);
    if (stream->m_uiNifFileVersion < 0xa00010d)
    {
        BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
        kReadStream->Read(&value.radius, 4, 4);
        for (unsigned short i = 0; i < m_usVertices; i++)
        {
            m_pfRadii[i] = value.radius;
        }
    }
    else
    {
        unsigned char flag;
        BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
        kReadStream->Read(&flag, 1, 1);
        if (flag != 0 && stream->m_kHeader.m_uiVersion < 0x13)
        {
            ReadElements(stream, m_pfRadii, (unsigned int)m_usVertices);
        }
        else
        {
            for (unsigned short i = 0; i < m_usVertices; i++)
            {
                m_pfRadii[i] = 1.0f;
            }
        }
    }
    {
        BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
        kReadStream->Read(&m_usActive, 2, 2);
    }
    unsigned char sizeFlag;
    if (stream->m_uiNifFileVersion < 0x4010007)
    {
        BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
        kReadStream->Read(&m_pfSizes, 4, 4);
        sizeFlag = (m_pfSizes != 0);
    }
    else
    {
        BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
        kReadStream->Read(&sizeFlag, 1, 1);
    }
    m_pfSizes = (float*)_NiMalloc_00aa1070((unsigned int)m_usVertices * 4);
    if (sizeFlag != 0 && stream->m_kHeader.m_uiVersion < 0x13)
    {
        BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
        kReadStream->Read(m_pfSizes, (unsigned int)m_usVertices * 4, 4);
    }
    else
    {
        for (unsigned short i = 0; i < m_usVertices; i++)
        {
            m_pfSizes[i] = 1.0f;
        }
    }
    if (m_bHasRadii)
    {
        unsigned char flag;
        if (stream->m_uiNifFileVersion < 0x4010000)
        {
            BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
            kReadStream->Read(&m_pkRotations, 4, 4);
            flag = (m_pkRotations != 0);
        }
        else
        {
            BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
            kReadStream->Read(&flag, 1, 1);
        }
        m_pkRotations = NewParticleRotations(m_usVertices);
        if (flag != 0)
        {
            for (unsigned int i = 0; i < m_usVertices; i++)
            {
                ((NiColorA*)&m_pkRotations[i])->LoadBinary(*stream);
            }
        }
        else
        {
            for (unsigned int i = 0; i < m_usVertices; i++)
            {
                memcpy(&m_pkRotations[i], &DAT_011a9ea4, sizeof(NiQuaternion));
            }
        }
    }
    else if (stream->m_uiNifFileVersion >= 0x5000008)
    {
        unsigned char flag;
        BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
        kReadStream->Read(&flag, 1, 1);
        if (flag != 0)
        {
            m_pkRotations = NewParticleRotations(m_usVertices);
            if (stream->m_kHeader.m_uiVersion < 0x13)
            {
                for (unsigned short i = 0; i < m_usVertices; i++)
                {
                    ((NiColorA*)&m_pkRotations[i])->LoadBinary(*stream);
                }
            }
            if (stream->m_uiNifFileVersion <= 0xa000100)
            {
                RTTILink* pRttiChain = ((RTTIView*)this)->GetRTTIChain();
                while (pRttiChain != 0)
                {
                    if (pRttiChain == (void*)&DAT_011f5f0c)
                    {
                        goto keepRot;
                    }
                    pRttiChain = pRttiChain->base;
                }
                DAT_011f6238.MemoryManager_Deallocate(m_pkRotations);
                m_pkRotations = 0;
            keepRot:;
            }
        }
    }
    if (stream->m_uiNifFileVersion >= 0xa030005)
    {
        {
            unsigned char flag;
            BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
            kReadStream->Read(&flag, 1, 1);
            if (flag != 0)
            {
                m_pfRotationAngles = (float*)_NiMalloc_00aa1070((unsigned int)m_usVertices * 4);
                if (stream->m_kHeader.m_uiVersion < 0x13)
                {
                    for (unsigned short i = 0; i < m_usVertices; i++)
                    {
                        BinStream* s2 = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
                        s2->Read(&m_pfRotationAngles[i], 4, 4);
                    }
                }
            }
        }
        {
            BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
            kReadStream->Read(&value.flag, 1, 1);
            if (value.flag != 0)
            {
                m_pkRotationAxes = (NiPoint3*)NewArray<Axis12>(m_usVertices);
                if (stream->m_kHeader.m_uiVersion < 0x13)
                {
                    for (unsigned short i = 0; i < m_usVertices; i++)
                    {
                        ((Axis12*)&m_pkRotationAxes[i])->FUN_00a59be0(stream);
                    }
                }
            }
        }
    }
    if (stream->m_kHeader.m_uiVersion > 0x11)
    {
        BinStream* kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
        kReadStream->Read(&value.flag, 1, 1);
        if (value.flag != 0)
        {
            m_pucTextureIndices = (unsigned char*)_NiMalloc_00aa1070((unsigned int)m_usVertices);
            FUN_00ec61c0(m_pucTextureIndices, 0, (unsigned int)m_usVertices);
        }
        kReadStream = reinterpret_cast<BinStream*&>(stream->m_pkIstr);
        kReadStream->Read(&m_ucSubTextureOffsetCount, 1, 1);
        if (m_ucSubTextureOffsetCount > 0)
        {
            m_pkSubTextureOffsets = (NiColorA*)_NiMalloc_00aa1070((unsigned int)m_ucSubTextureOffsetCount * 16);
            for (unsigned short i = 0; i < m_ucSubTextureOffsetCount; i++)
            {
                m_pkSubTextureOffsets[i].LoadBinary(*stream);
            }
        }
    }
}
