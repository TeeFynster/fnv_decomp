// src/havok/common/scenedata/mesh/hkxvertexbuffer.cpp
// Functions are listed by their @fnv annotations; all eight retain the original PC bytes.
#include "../../../../../include/hkArray.h"
#include "../../../../../include/FinishingFlag.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkxVertexDescription.h"

typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef float hkReal;

extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* array, int count, int size) throw();
extern "C" void __cdecl ResizeAudioStream(hkMemoryAllocator*, void*, int) throw();


template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int doubled = 2 * capacity;
        int requested = n < doubled ? doubled : n;
        hkArrayUtil__reserve(alloc, this, requested, sizeof(T));
    }
}
template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*) { return hkMemoryRouter_getInstance()->heap(); }
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray() { clearAndDeallocate(); }
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if (!(m_iCapacityState & DONT_DEALLOCATE_FLAG))
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
    m_data = 0;
    m_iCapacityState = DONT_DEALLOCATE_FLAG;
}

extern "C" void _ReadWriteBarrier();
inline void* __cdecl operator new(unsigned int, void* where) throw() { return where; }
inline void __cdecl operator delete(void*, void*) throw() {}
struct hkxVertexDescriptionElementDecl
{
    hkUint32 m_uiByteOffset;
    hkUint16 m_type;
    hkUint16 m_eDataUsage;
    hkUint32 m_uiByteStride;
    hkxVertexDescriptionElementDecl()
    {
        m_uiByteOffset = 0;
        m_type = 0;
        _ReadWriteBarrier();
        m_eDataUsage = 0;
        m_uiByteStride = 0;
    }
};

inline bool hkxVertexDescription::operator==(const hkxVertexDescription& other) const
{
    return Equals(other);
}

inline void hkxVertexDescription::clear()
{
    for (int i = 0; i < m_kElementDeclarations.m_iElementCount; ++i)
        m_kElementDeclarations.m_data[i].~hkxVertexDescriptionElementDecl();
    m_kElementDeclarations.m_iElementCount = 0;
}

inline hkxVertexDescriptionElementDecl& hkxVertexDescription::AllocatePair()
{
    hkMemoryAllocator* alloc = &hkMemoryRouter_getInstance()->heap();
    hkArray<hkxVertexDescriptionElementDecl>& a = m_kElementDeclarations;
    if (a.m_iElementCount == (a.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(alloc, &a, sizeof(hkxVertexDescriptionElementDecl));
    new (a.m_data + a.m_iElementCount) hkxVertexDescriptionElementDecl;
    return a.m_data[a.m_iElementCount++];
}

// No include/ vertex-data header exists yet; these are the reflected 0x54-byte members.
class hkxVertexBufferVertexData
{
public:
    hkArray<hkVector4> m_kVectorData;
    hkArray<hkReal> m_kFloatData;
    hkArray<hkUint32> m_kUInt32Data;
    hkArray<hkUint16> m_kUInt16Data;
    hkArray<hkUint8> m_kUInt8Data;
    hkUint32 m_uiVertexCount;
    hkUint32 m_uiVectorDataStride;
    hkUint32 m_uiFloatDataStride;
    hkUint32 m_uiUInt32DataStride;
    hkUint32 m_uiUInt16DataStride;
    hkUint32 m_uiUInt8DataStride;
    hkxVertexBufferVertexData(FinishingFlag flag)
        : m_kVectorData(flag), m_kFloatData(flag), m_kUInt32Data(flag), m_kUInt16Data(flag), m_kUInt8Data(flag) {}
    void ResizeVertexData(int count) throw();
    __declspec(noinline) void ClearFields();
    void DestroyArrays();
};

// No include/ vertex-buffer header exists yet; reflected size is 0x68 (data +0x08, description +0x5c).
class hkxVertexBuffer : public hkReferencedObject
{
public:
    hkxVertexBuffer(FinishingFlag flag) throw();
    virtual ~hkxVertexBuffer();
    hkxVertexBufferVertexData m_data;
    hkxVertexDescription m_kCreateDesc;
    void setNumVertices(int count, const hkxVertexDescription& desc) throw();
    void copyVertex(const hkxVertexBuffer* src, int srcIndex, int dstIndex);
    void CopyFrom(const hkxVertexBuffer& src, bool resize) throw();
    void* getVertexDataPtr(const hkxVertexDescriptionElementDecl& decl);
    const void* getVertexDataPtr(const hkxVertexDescriptionElementDecl& decl) const;
    void Destroy();
    hkxVertexBuffer* DeleteThis(unsigned int flags) throw();
};

// @fnv 0x00e3e220
__declspec(noinline) void hkxVertexBufferVertexData::ClearFields()
{
    m_kVectorData.m_iElementCount = 0;
    m_kFloatData.m_iElementCount = 0;
    m_kUInt32Data.m_iElementCount = 0;
    m_kUInt16Data.m_iElementCount = 0;
    m_kUInt8Data.m_iElementCount = 0;
    m_uiVertexCount = 0;
    m_uiVectorDataStride = 0;
    m_uiFloatDataStride = 0;
    m_uiUInt32DataStride = 0;
    m_uiUInt16DataStride = 0;
    m_uiUInt8DataStride = 0;
}

// @fnv 0x00e3e250
void hkxVertexBufferVertexData::ResizeVertexData(int aiVertexCount) throw()
{
    m_uiVertexCount = aiVertexCount;
    m_kUInt8Data.setSize(m_uiUInt8DataStride * aiVertexCount);
    m_kUInt16Data.setSize(m_uiUInt16DataStride * aiVertexCount / sizeof(hkUint16));
    m_kUInt32Data.setSize(m_uiUInt32DataStride * aiVertexCount / sizeof(hkUint32));
    m_kFloatData.setSize(m_uiFloatDataStride * aiVertexCount / sizeof(hkReal));
    m_kVectorData.setSize(m_uiVectorDataStride * aiVertexCount / sizeof(hkVector4));
}

// @fnv 0x00e3e380
hkxVertexBuffer::hkxVertexBuffer(FinishingFlag flag) throw()
    : hkReferencedObject(flag), m_data(flag), m_kCreateDesc(flag) {}

template <typename T> inline T min2E3E6(T a, T b) { return a < b ? a : b; }
void __cdecl hkString_memCpy(void* dst, const void* src, int size) throw();

// @fnv 0x00e3e670
void hkxVertexBuffer::CopyFrom(const hkxVertexBuffer& kOther, bool bResizeToMatch) throw()
{
    bool bSameDesc = m_kCreateDesc == kOther.m_kCreateDesc;
    if (bResizeToMatch)
        setNumVertices(kOther.m_data.m_uiVertexCount, m_kCreateDesc);

    if (bSameDesc)
    {
        unsigned int numVerts = min2E3E6(kOther.m_data.m_uiVertexCount, m_data.m_uiVertexCount);
        if (m_data.m_uiUInt8DataStride > 0)
            hkString_memCpy(m_data.m_kUInt8Data.begin(), kOther.m_data.m_kUInt8Data.begin(),
                         m_data.m_uiUInt8DataStride * numVerts);
        if (m_data.m_uiUInt16DataStride > 0)
            hkString_memCpy(m_data.m_kUInt16Data.begin(), kOther.m_data.m_kUInt16Data.begin(),
                         m_data.m_uiUInt16DataStride * numVerts);
        if (m_data.m_uiUInt32DataStride > 0)
            hkString_memCpy(m_data.m_kUInt32Data.begin(), kOther.m_data.m_kUInt32Data.begin(),
                         m_data.m_uiUInt32DataStride * numVerts);
        if (m_data.m_uiFloatDataStride > 0)
            hkString_memCpy(m_data.m_kFloatData.begin(), kOther.m_data.m_kFloatData.begin(),
                         m_data.m_uiFloatDataStride * numVerts);
        if (m_data.m_uiVectorDataStride > 0)
            hkString_memCpy(m_data.m_kVectorData.begin(), kOther.m_data.m_kVectorData.begin(),
                         m_data.m_uiVectorDataStride * numVerts);
    }
    else
    {
        for (unsigned int i = 0; i < kOther.m_data.m_uiVertexCount; i++)
            copyVertex(&kOther, i, i);
    }
}

extern int DAT_0102e388;
// @fnv 0x00e3e760
void hkxVertexBuffer::Destroy()
{
    hkMemoryAllocator* target = &hkMemoryRouter_getInstance()->heap();
    hkArray<hkxVertexDescriptionElementDecl>& a = m_kCreateDesc.m_kElementDeclarations;
    int count = a.m_iCapacityState;
    a.m_iElementCount = 0;
    if (!(count & 0x80000000))
    {
        unsigned int size = (unsigned int)(count & 0x3fffffff) * 12;
        target->bufFree(a.m_data, size);
    }
    a.m_data = 0;
    a.m_iCapacityState = 0x80000000;
    m_data.DestroyArrays();
    *(int*)this = (int)(unsigned int)&DAT_0102e388;
}

// @fnv 0x00e3e7b0
hkxVertexBuffer* hkxVertexBuffer::DeleteThis(unsigned int flags) throw()
{
    Destroy();
    if (flags & 1)
        hkMemoryRouter_getInstance()->heap().blockFree(this, m_usMemSizeAndFlags);
    return this;
}

class MemoryUtils
{
public:
    static void* CopyRegion(void* dst, const void* src, int size);
    static void* SetMemory(void* dst, int val, int size);
};

// Copies data between buffers, using stride-sized array copies for matching descriptions and per-element copies otherwise.
// @fnv 0x00e3e030
// src: XBOX_PDB 0x00e3e030
void hkxVertexBuffer::copyVertex(const hkxVertexBuffer* src, int srcIndex, int dstIndex)
{
    bool bSameDesc = (m_kCreateDesc == src->m_kCreateDesc);
    unsigned int aiUsageCounts[257];
    MemoryUtils::SetMemory(aiUsageCounts, 0, sizeof(aiUsageCounts));

    if (dstIndex >= (int)m_data.m_uiVertexCount || srcIndex >= (int)src->m_data.m_uiVertexCount)
    {
        return;
    }

    if (bSameDesc)
    {
        if (m_data.m_uiUInt8DataStride > 0)
        {
            MemoryUtils::CopyRegion(m_data.m_kUInt8Data.m_data, src->m_data.m_kUInt8Data.m_data,
                                    m_data.m_uiUInt8DataStride);
        }
        if (m_data.m_uiUInt16DataStride > 0)
        {
            MemoryUtils::CopyRegion(m_data.m_kUInt16Data.m_data, src->m_data.m_kUInt16Data.m_data,
                                    m_data.m_uiUInt16DataStride);
        }
        if (m_data.m_uiUInt32DataStride > 0)
        {
            MemoryUtils::CopyRegion(m_data.m_kUInt32Data.m_data, src->m_data.m_kUInt32Data.m_data,
                                    m_data.m_uiUInt32DataStride);
        }
        if (m_data.m_uiFloatDataStride > 0)
        {
            MemoryUtils::CopyRegion(m_data.m_kFloatData.m_data, src->m_data.m_kFloatData.m_data,
                                    m_data.m_uiFloatDataStride);
        }
        if (m_data.m_uiVectorDataStride > 0)
        {
            MemoryUtils::CopyRegion(m_data.m_kVectorData.m_data, src->m_data.m_kVectorData.m_data,
                                    m_data.m_uiVectorDataStride);
        }
        return;
    }

    const hkxVertexDescription& srcDesc = src->m_kCreateDesc;
    const hkxVertexBuffer* srcBuf = src;

    for (int i = 0; i < m_kCreateDesc.m_kElementDeclarations.m_iElementCount; ++i)
    {
        const hkxVertexDescriptionElementDecl& decl = m_kCreateDesc.m_kElementDeclarations.m_data[i];
        const hkxVertexDescriptionElementDecl* srcDecl = srcDesc.getElementDecl(
            (hkxVertexDescription::DataUsage)decl.m_eDataUsage, aiUsageCounts[decl.m_eDataUsage]);
        if (!srcDecl)
        {
            continue;
        }
        if (decl.m_type != srcDecl->m_type)
        {
            continue;
        }
        aiUsageCounts[decl.m_eDataUsage]++;
        void* dstData = getVertexDataPtr(decl);
        const void* srcData = srcBuf->getVertexDataPtr(*srcDecl);

        int size = 0;
        switch (decl.m_type)
        {
        case hkxVertexDescription::HKX_DT_UINT8:
            size = 4;
            break;
        case hkxVertexDescription::HKX_DT_INT16:
            size = 4;
            break;
        case hkxVertexDescription::HKX_DT_UINT32:
            size = 4;
            break;
        case hkxVertexDescription::HKX_DT_FLOAT:
            size = 4;
            break;
        case hkxVertexDescription::HKX_DT_FLOAT2:
            size = 8;
            break;
        case hkxVertexDescription::HKX_DT_FLOAT3:
            size = 16;
            break;
        case hkxVertexDescription::HKX_DT_FLOAT4:
            size = 16;
            break;
        }

        MemoryUtils::CopyRegion((char*)dstData + decl.m_uiByteStride * dstIndex,
                                (const char*)srcData + srcDecl->m_uiByteStride * srcIndex, size);
    }
}

// Rebuilds desc from input, computes offsets and strides, then sizes each data array for n vertices.
// @fnv 0x00e3e3a0
// src: XBOX_PDB 0x00e3e3a0
void hkxVertexBuffer::setNumVertices(int aiCount, const hkxVertexDescription& input) throw()
{
    if (aiCount == m_data.m_uiVertexCount && input.Equals(m_kCreateDesc))
        return;
    m_kCreateDesc.clear();
    m_data.ClearFields();
    for (int i = 0; i < input.m_kElementDeclarations.m_iElementCount; ++i)
    {
        const hkxVertexDescriptionElementDecl& src = input.m_kElementDeclarations.m_data[i];
        hkxVertexDescriptionElementDecl& dst = m_kCreateDesc.AllocatePair();
        dst.m_type = src.m_type;
        dst.m_eDataUsage = src.m_eDataUsage;
        switch (src.m_type)
        {
        case 1:
            dst.m_uiByteOffset = m_data.m_uiUInt8DataStride;
            m_data.m_uiUInt8DataStride += 4;
            break;
        case 2:
            dst.m_uiByteOffset = m_data.m_uiUInt16DataStride;
            m_data.m_uiUInt16DataStride += 4;
            break;
        case 3:
            dst.m_uiByteOffset = m_data.m_uiUInt32DataStride;
            m_data.m_uiUInt32DataStride += 4;
            break;
        case 4:
            dst.m_uiByteOffset = m_data.m_uiFloatDataStride;
            m_data.m_uiFloatDataStride += 4;
            break;
        case 5:
            dst.m_uiByteOffset = m_data.m_uiFloatDataStride;
            m_data.m_uiFloatDataStride += 8;
            break;
        case 6:
        case 7:
            dst.m_uiByteOffset = m_data.m_uiVectorDataStride;
            m_data.m_uiVectorDataStride += 16;
            break;
        }
    }
    for (int i = 0; i < m_kCreateDesc.m_kElementDeclarations.m_iElementCount; ++i)
    {
        hkxVertexDescriptionElementDecl& dst = m_kCreateDesc.m_kElementDeclarations.m_data[i];
        switch (dst.m_type)
        {
        case 1:
            dst.m_uiByteStride = m_data.m_uiUInt8DataStride;
            break;
        case 2:
            dst.m_uiByteStride = m_data.m_uiUInt16DataStride;
            break;
        case 3:
            dst.m_uiByteStride = m_data.m_uiUInt32DataStride;
            break;
        case 4:
        case 5:
            dst.m_uiByteStride = m_data.m_uiFloatDataStride;
            break;
        case 6:
        case 7:
            dst.m_uiByteStride = m_data.m_uiVectorDataStride;
            break;
        }
    }
    m_data.m_uiVertexCount = aiCount;
    m_data.m_kUInt8Data.setSize(m_data.m_uiUInt8DataStride * aiCount);
    m_data.m_kUInt16Data.setSize((m_data.m_uiUInt16DataStride * aiCount) / 2);
    m_data.m_kUInt32Data.setSize((m_data.m_uiUInt32DataStride * aiCount) / 4);
    m_data.m_kFloatData.setSize((m_data.m_uiFloatDataStride * aiCount) / 4);
    m_data.m_kVectorData.setSize((m_data.m_uiVectorDataStride * aiCount) / 16);
}
