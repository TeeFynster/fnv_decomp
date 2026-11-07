
// src/havok/common/scenedata/scene/hkxscene.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/scene/hkxscene.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkBaseObject.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkMatrix3.h"
#include "../../../../../include/hkMemoryRouter.h"

typedef hkReferencedObject Ref;
struct Alloc
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotC();
    virtual void freeBlock(void*, int);
};
struct FUN_00cb0c00_class
{
    char* value;
    void Object_UpdateFields_00cb0c00();
};
typedef FUN_00cb0c00_class String;
extern int DAT_010e99d8, DAT_0102e388;
struct Root
{
    Ref* ptr;
    __forceinline ~Root()
    {
        if (ptr)
            ptr->removeReference();
        ptr = 0;
    }
};
struct Scene
{
    void* unk00;
    int unk04;
    String unk08, unk0c;
    float unk10;
    Root unk14;
    hkArray<Ref*> unk18, unk24, unk30, unk3c, unk48, unk54, unk60, unk6c;
    void ClearScene();
};
// @fnv 0x00e4a750
void Scene::ClearScene()
{
    unk00 = &DAT_010e99d8;
    {
        Alloc* allocator = reinterpret_cast<Alloc*>(hkMemoryRouter::getInstance().m_heap);
        Ref** p = unk6c.m_data;
        int n = unk6c.m_iElementCount;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk6c.m_iElementCount = 0;
        if (!(unk6c.m_iCapacityState & 0x80000000))
            allocator->freeBlock(unk6c.m_data, (unk6c.m_iCapacityState & 0x3fffffff) * 4);
        unk6c.m_data = 0;
        unk6c.m_iCapacityState = 0x80000000;
    }
    {
        Alloc* allocator = reinterpret_cast<Alloc*>(hkMemoryRouter::getInstance().m_heap);
        Ref** p = unk60.m_data;
        int n = unk60.m_iElementCount;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk60.m_iElementCount = 0;
        if (!(unk60.m_iCapacityState & 0x80000000))
            allocator->freeBlock(unk60.m_data, (unk60.m_iCapacityState & 0x3fffffff) * 4);
        unk60.m_data = 0;
        unk60.m_iCapacityState = 0x80000000;
    }
    {
        Alloc* allocator = reinterpret_cast<Alloc*>(hkMemoryRouter::getInstance().m_heap);
        Ref** p = unk54.m_data;
        int n = unk54.m_iElementCount;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk54.m_iElementCount = 0;
        if (!(unk54.m_iCapacityState & 0x80000000))
            allocator->freeBlock(unk54.m_data, (unk54.m_iCapacityState & 0x3fffffff) * 4);
        unk54.m_data = 0;
        unk54.m_iCapacityState = 0x80000000;
    }
    {
        Alloc* allocator = reinterpret_cast<Alloc*>(hkMemoryRouter::getInstance().m_heap);
        Ref** p = unk48.m_data;
        int n = unk48.m_iElementCount;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk48.m_iElementCount = 0;
        if (!(unk48.m_iCapacityState & 0x80000000))
            allocator->freeBlock(unk48.m_data, (unk48.m_iCapacityState & 0x3fffffff) * 4);
        unk48.m_data = 0;
        unk48.m_iCapacityState = 0x80000000;
    }
    {
        Alloc* allocator = reinterpret_cast<Alloc*>(hkMemoryRouter::getInstance().m_heap);
        Ref** p = unk3c.m_data;
        int n = unk3c.m_iElementCount;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk3c.m_iElementCount = 0;
        if (!(unk3c.m_iCapacityState & 0x80000000))
            allocator->freeBlock(unk3c.m_data, (unk3c.m_iCapacityState & 0x3fffffff) * 4);
        unk3c.m_data = 0;
        unk3c.m_iCapacityState = 0x80000000;
    }
    {
        Alloc* allocator = reinterpret_cast<Alloc*>(hkMemoryRouter::getInstance().m_heap);
        Ref** p = unk30.m_data;
        int n = unk30.m_iElementCount;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk30.m_iElementCount = 0;
        if (!(unk30.m_iCapacityState & 0x80000000))
            allocator->freeBlock(unk30.m_data, (unk30.m_iCapacityState & 0x3fffffff) * 4);
        unk30.m_data = 0;
        unk30.m_iCapacityState = 0x80000000;
    }
    {
        Alloc* allocator = reinterpret_cast<Alloc*>(hkMemoryRouter::getInstance().m_heap);
        Ref** p = unk24.m_data;
        int n = unk24.m_iElementCount;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk24.m_iElementCount = 0;
        if (!(unk24.m_iCapacityState & 0x80000000))
            allocator->freeBlock(unk24.m_data, (unk24.m_iCapacityState & 0x3fffffff) * 4);
        unk24.m_data = 0;
        unk24.m_iCapacityState = 0x80000000;
    }
    {
        Alloc* allocator = reinterpret_cast<Alloc*>(hkMemoryRouter::getInstance().m_heap);
        Ref** p = unk18.m_data;
        int n = unk18.m_iElementCount;
        for (int i = 0; i < n; ++i)
        {
            if (p[i])
                p[i]->removeReference();
            p[i] = 0;
        }
        unk18.m_iElementCount = 0;
        if (!(unk18.m_iCapacityState & 0x80000000))
            allocator->freeBlock(unk18.m_data, (unk18.m_iCapacityState & 0x3fffffff) * 4);
        unk18.m_data = 0;
        unk18.m_iCapacityState = 0x80000000;
    }
    unk14.~Root();
    unk0c.Object_UpdateFields_00cb0c00();
    unk08.Object_UpdateFields_00cb0c00();
    unk00 = &DAT_0102e388;
}



__forceinline hkMatrix3::hkMatrix3() {}

__forceinline void hkMatrix3::operator=(const hkMatrix3& matrix)
{
    m_kColumn0 = matrix.m_kColumn0;
    m_kColumn1 = matrix.m_kColumn1;
    m_kColumn2 = matrix.m_kColumn2;
}

struct FUN_00cb0a60
{
    FUN_00cb0a60();

    const char* m_pcText;
};

class FUN_00e4a6a0 : public hkReferencedObject
{
  public:
    FUN_00e4a6a0() throw();
    virtual ~FUN_00e4a6a0() throw();

    FUN_00cb0a60 m_kSceneName;
    FUN_00cb0a60 m_kSceneFileName;
    float m_fNumFrames;
    void* m_pAabbRootNode;
    hkArray<void*> m_kSelectionSets;
    hkArray<void*> m_kCameras;
    hkArray<void*> m_ppLights;
    hkArray<void*> m_kMeshList;
    hkArray<void*> m_kMaterials;
    hkArray<void*> m_kInplaceTextures;
    hkArray<void*> m_kExternalTextures;
    hkArray<void*> m_kSkinBindings;
    unsigned int unk78, unk7C;
    hkMatrix3 m_kAppliedTransform;
};

// Initializes m_fNumFrames and m_pAabbRootNode, then copies the identity matrix returned by hkMatrix3::GetIdentityTransform into m_kAppliedTransform.
// @fnv 0x00e4a6a0
FUN_00e4a6a0::FUN_00e4a6a0() throw() : m_fNumFrames(0.0f), m_pAabbRootNode(0)
{
    m_kAppliedTransform = hkMatrix3::GetIdentityTransform();
}

extern int DAT_010e929c;
extern int DAT_0102e388;



template <class T>
__forceinline void ClearAndRelease(hkArray<T>& array) throw()
{
    Alloc& heap = reinterpret_cast<Alloc&>(hkMemoryRouter::getInstance().heap());
    array.m_iElementCount = 0;
    if ((array.m_iCapacityState & 0x80000000) == 0)
        heap.freeBlock(array.m_data, (array.m_iCapacityState & 0x3fffffff) * sizeof(T));
    array.m_data = 0;
    array.m_iCapacityState = 0x80000000;
}

struct Entry_e4a4
{
    hkReferencedObject* m_pCollisionShape;
    hkReferencedObject* m_iMaterialIndex;
    int unk08, unk0C, unk10, unk14, unk18, unk1C;
    ~Entry_e4a4() throw()
    {
        m_pCollisionShape->removeReference();
        if (m_iMaterialIndex)
            m_iMaterialIndex->removeReference();
    }
};

struct Name_e4a4
{
    int unk00;
    void Object_UpdateFields_00cb0c00() throw();
};

struct Mesh_e4a4
{
    int* m_vtbl;
    int unk04;
    hkArray<Entry_e4a4> m_entries;
    hkArray<short> m_ppIndices;
    hkArray<int> m_iSlotIds;
    Name_e4a4 m_name;
    void ReleaseEntriesAndIndexArrays();
};

// Calls each entry destructor, invokes FUN_00cb0c00 on m_name, releases the slot ID, index, and entry arrays, then updates m_vtbl.
// @fnv 0x00e4a460
// src: GUESS 0x00e4a460 (confidence: medium)
void Mesh_e4a4::ReleaseEntriesAndIndexArrays()
{
    m_vtbl = &DAT_010e929c;
    int n = m_entries.GetLogicalSize();
    for (int i = 0; i < n; i++)
        m_entries[i].~Entry_e4a4();
    m_name.Object_UpdateFields_00cb0c00();
    ClearAndRelease(m_iSlotIds);
    ClearAndRelease(m_ppIndices);
    ClearAndRelease(m_entries);
    m_vtbl = &DAT_0102e388;
}
