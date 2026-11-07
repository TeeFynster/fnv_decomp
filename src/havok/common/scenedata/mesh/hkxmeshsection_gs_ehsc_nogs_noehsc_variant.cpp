
// src/havok/common/scenedata/mesh/hkxmeshsection_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/scenedata/mesh/hkxmeshsection.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/scenedata/mesh/hkxmeshsection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxmeshsection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkxMeshSection.h"
#include "../../../../../include/hkxIndexBuffer.h"
extern int DAT_010e9b7c;
struct IndexArray
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    IndexArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct FUN_00e61720
{
    void* m_vptr;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pMeshVertexBuffer;
    IndexArray m_kIndexBuffers;
    void* m_iMaterialIndex;
    IndexArray m_kUserChannels;
    FUN_00e61720(void* arg);
    void UpdateState_00e61770(void* arg);
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
class hkMemoryAllocatorE6;
void __cdecl hkArrayUtil__reserve(hkMemoryAllocatorE6& alloc, void* pArray, int iReqElem, int iElemSize);
class hkMemoryRouterE6
{
  public:
    static hkMemoryRouterE6& GetMonitorStream();
    hkMemoryAllocatorE6& heap()
    {
        return *m_pStreamAllocator;
    }
    void* m_aiEntries;
    void* m_pTemp;
    void* m_pDebugAllocator;
    void* m_pSolver;
    hkMemoryAllocatorE6* m_pStreamAllocator;
};
class hkReferencedObjectE6
{
  public:
    virtual ~hkReferencedObjectE6();
    void RetainReference() const;
    void removeReference() const;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
template <class T> class hkRefPtrE6
{
  public:
    hkRefPtrE6(const hkRefPtrE6& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->RetainReference();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    ~hkRefPtrE6()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    __forceinline hkRefPtrE6& operator=(const hkRefPtrE6& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->RetainReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = rp.m_pRetainedObject;
        return *this;
    }
    T* m_pRetainedObject;
};
class hkRefVariantE6 : public hkRefPtrE6<hkReferencedObjectE6>
{
  public:
    hkRefVariantE6(const hkRefVariantE6& o) : hkRefPtrE6<hkReferencedObjectE6>(o)
    {}
    __forceinline hkRefVariantE6& operator=(const hkRefVariantE6& o)
    {
        if (this != &o)
        {
            hkReferencedObjectE6* p = o.m_pRetainedObject;
            if (p)
                p->RetainReference();
            if (m_pRetainedObject)
                m_pRetainedObject->removeReference();
            m_pRetainedObject = p;
        }
        return *this;
    }
};
template <class T> class hkArrayE6
{
  public:
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline hkArrayE6& operator=(const hkArrayE6& a)
    {
        hkMemoryAllocatorE6& alloc = hkMemoryRouterE6::GetMonitorStream().heap();
        int oldSize = m_iElementCount;
        int newSize = a.m_iElementCount;
        int copiedSize = newSize > oldSize ? oldSize : newSize;
        if (getCapacity() < newSize)
        {
            int cap2 = 2 * getCapacity();
            int newCap = newSize < cap2 ? cap2 : newSize;
            hkArrayUtil__reserve(alloc, this, newCap, sizeof(T));
        }
        T* pDestroy = m_data + newSize;
        for (int i = 0; i < oldSize - newSize; i++)
            pDestroy[i].~T();
        const T* pSrc = a.m_data;
        T* pDst = m_data;
        for (int i = 0; i < copiedSize; i++)
            pDst[i] = pSrc[i];
        pSrc = a.m_data + copiedSize;
        pDst = m_data + copiedSize;
        for (int i = 0; i < newSize - copiedSize; i++)
            new (&pDst[i]) T(pSrc[i]);
        m_iElementCount = newSize;
        return *this;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class hkxVertexBufferE6;
class hkxMaterialE6;
class hkxMeshSectionE6 : public hkReferencedObjectE6
{
  public:
    hkxMeshSectionE6& UpdateState_00e61770(const hkxMeshSectionE6& o);
    hkRefPtrE6<hkReferencedObjectE6> m_pMeshVertexBuffer;
    hkArrayE6<hkRefPtrE6<hkReferencedObjectE6> > m_kIndexBuffers;
    hkRefPtrE6<hkReferencedObjectE6> m_iMaterialIndex;
    hkArrayE6<hkRefVariantE6> m_kUserChannels;
};


struct hkGeometryTriangle
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iMaterialIndex;
};

class hkVector4;

struct hkGeometryData
{
    hkArray<hkVector4> m_kVertices;
    hkArray<hkGeometryTriangle> m_uiTriangleCount;
};

struct hkContainerAllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* unk10;
};

hkContainerAllocHolder* hkMemoryRouter_getInstance();
void ResizeAudioStream(void* alloc, void* array, int elemSize);

class hkErrStreamData
{
  public:
    hkErrStreamData(void* buf, int size) throw();
    ~hkErrStreamData() throw();
    hkErrStreamData& operator<<(const char* str) throw();
    void* unk00;
    int unk04;
    void* unk08;
};

class hkErrorData
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};

extern hkErrorData* DAT_01268360;

static inline void PushBackTriangle(hkArray<hkGeometryTriangle>& arr, const hkGeometryTriangle& t)
{
    hkContainerAllocHolder* holder = hkMemoryRouter_getInstance();
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(holder->unk10, &arr, sizeof(hkGeometryTriangle));
    arr.m_data[arr.m_iElementCount++] = t;
}

class hkxMeshSectionImpl : public hkxMeshSection
{
  public:
    void hkxMeshSection_collectVertexPositions(hkGeometryData& geometry);
    void hkxMeshSection_appendGeometry(hkGeometryData& geometry, int materialIndex);
};

// @fnv 0x00e61530
// src: XBOX_PDB 0x00e61530
void hkxMeshSectionImpl::hkxMeshSection_appendGeometry(hkGeometryData& geometry, int materialIndex)
{
    hkxMeshSection_collectVertexPositions(geometry);

    for (int ib = 0; ib < m_kIndexBuffers.m_iElementCount; ib++)
    {
        hkxIndexBuffer* ibuffer = m_kIndexBuffers.m_data[ib];
        int numIndices = ibuffer->m_kIndices16.m_iElementCount | ibuffer->m_kIndices32.m_iElementCount;
        bool is16 = ibuffer->m_kIndices16.m_iElementCount > 0;

        int ci = 0;
        while (ci < numIndices)
        {
            hkGeometryTriangle tri;
            switch (ibuffer->m_eIndexType)
            {
            case 1:
                tri.m_kPointA = is16 ? ibuffer->m_kIndices16.m_data[ci] : ibuffer->m_kIndices32.m_data[ci];
                tri.m_kPointB = is16 ? ibuffer->m_kIndices16.m_data[ci + 1] : ibuffer->m_kIndices32.m_data[ci + 1];
                tri.m_iThirdValue = is16 ? ibuffer->m_kIndices16.m_data[ci + 2] : ibuffer->m_kIndices32.m_data[ci + 2];
                ci += 3;
                break;
            case 2:
                if (ci < 2)
                {
                    ci++;
                    continue;
                }
                if (ci == 2)
                {
                    tri.m_kPointA = is16 ? ibuffer->m_kIndices16.m_data[0] : ibuffer->m_kIndices32.m_data[0];
                    tri.m_kPointB = is16 ? ibuffer->m_kIndices16.m_data[1] : ibuffer->m_kIndices32.m_data[1];
                    tri.m_iThirdValue = is16 ? ibuffer->m_kIndices16.m_data[2] : ibuffer->m_kIndices32.m_data[2];
                    ci = 3;
                }
                else
                {
                    hkGeometryTriangle& last = geometry.m_uiTriangleCount.m_data[geometry.m_uiTriangleCount.m_iElementCount - 1];
                    tri.m_kPointA = last.m_iThirdValue;
                    tri.m_kPointB = last.m_kPointB;
                    tri.m_iThirdValue = is16 ? ibuffer->m_kIndices16.m_data[ci] : ibuffer->m_kIndices32.m_data[ci];
                    ci++;
                }
                break;
            default: {
                char buf[512];
                hkErrStreamData ostr(buf, sizeof(buf));
                ostr << "Unsupported index buffer type - Ignoring";
                DAT_01268360->message(1, 0xabbaa883, buf, ".\\Mesh\\hkxMeshSection.cpp", 141);
            }
                ci = numIndices;
                continue;
            }

            tri.m_iMaterialIndex = materialIndex;
            PushBackTriangle(geometry.m_uiTriangleCount, tri);
        }
    }
}
