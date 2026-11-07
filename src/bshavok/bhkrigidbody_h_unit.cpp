#include "../../include/hkArray.h"
// bshavok/bhkrigidbody_h_unit.cpp: WorldObject (4 functions)

#include "bhkrigidbody.h"

extern __declspec(thread) unsigned int g_ThreadMemoryContext;
struct MemoryContextGuard
{
    unsigned int previous;
    __forceinline MemoryContextGuard() : previous(g_ThreadMemoryContext)
    {
        g_ThreadMemoryContext = 16;
    }
    __forceinline ~MemoryContextGuard()
    {
        g_ThreadMemoryContext = previous;
    }
};
struct AllocationManager
{
    void* Game_DoHeapAlloc(unsigned int size);
};
extern AllocationManager DAT_011f6238;
struct FUN_00c8f510
{
    unsigned int value;
    FUN_00c8f510();
    ~FUN_00c8f510();
};
__forceinline void* __cdecl operator new(unsigned int size, AllocationManager& allocator)
{
    unsigned char* storage = static_cast<unsigned char*>(allocator.Game_DoHeapAlloc(0xf0));
    unsigned char adjustment = static_cast<unsigned char>(16 - (reinterpret_cast<unsigned int>(storage) & 15));
    storage += adjustment;
    storage[-1] = adjustment;
    return storage;
}
void __cdecl operator delete(void* memory, AllocationManager& allocator);
struct FUN_00c8f5a0_Class
{
    void* virtualFunctions;
    unsigned int referenceCount;
    void* havokObject;
    FUN_00c8f510* rigidBodyInfo;
    void bhkRigidBody_CopyCinfo(FUN_00c8f510* info);
    FUN_00c8f510* GetOrCreateRigidBodyInfo(unsigned char* wasCreated);
};
// @fnv 0x00c8f5a0
FUN_00c8f510* FUN_00c8f5a0_Class::GetOrCreateRigidBodyInfo(unsigned char* wasCreated)
{
    MemoryContextGuard context;
    const bool needsCreation = rigidBodyInfo == 0;
    *wasCreated = needsCreation;
    if (needsCreation)
    {
        rigidBodyInfo = new (DAT_011f6238) FUN_00c8f510();
        if (havokObject)
            bhkRigidBody_CopyCinfo(rigidBodyInfo);
    }
    return rigidBodyInfo;
}

class C8F670Heap
{
  public:
    void Deallocate(void* pvMem);
};

extern C8F670Heap g_memoryManager;

struct C8F670Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct C8F670MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8F670Allocator* m_pStreamAllocator;

    C8F670Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" C8F670MemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();

struct C8F670Pair
{
    int m_iKey;
    int m_iValue;
};

template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
        C8F670Allocator& alloc = hkMemoryRouter_getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    
}

class __declspec(novtable) C8F670Object
{
  public:
    virtual ~C8F670Object() throw()
    {}

    static void operator delete(void* pvMem)
    {
        if (pvMem)
        {
            unsigned char ucOffset = static_cast<unsigned char*>(pvMem)[-1];
            g_memoryManager.Deallocate(static_cast<char*>(pvMem) - ucOffset);
        }
    }

    void* DestroyObject(unsigned int uiFlags);

    int unk04;
    int unk08;
    hkArray<C8F670Pair> m_kPairs;
};

// Calls the object's destructor and, when uiFlags has bit 0 set, frees the object, then returns this.
// @fnv 0x00c8f670
void* C8F670Object::DestroyObject(unsigned int uiFlags)
{
    this->C8F670Object::~C8F670Object();
    if (uiFlags & 1)
        operator delete(this);
    return this;
}

class C8D9BinaryStream
{
  public:
    virtual void v00();
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(C8D9BinaryStream* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents = 1)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    template <class T> unsigned int Write(const T* pValue, unsigned int uiElementCount)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, uiElementCount * sizeof(T), &uiSize, uiElementCount);
    }
};

class C8D9HavokData
{
  public:
    void SwapEndian();
};

class C8D9Stream
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SaveLinkID(void* pkObject);
    unsigned int unk[(0x1e4 - 4) / 4];
    unsigned char m_ucMode;
    unsigned char unk1e5, unk1e6, unk1e7;
    unsigned int unk1e8[(0x250 - 0x1e8) / 4];
    C8D9BinaryStream* m_pBackingStream;
};

template <class T> inline void C8D9SaveBinary(C8D9Stream* pkStream, const T& kValue)
{
    pkStream->m_pBackingStream->Write(&kValue, 1);
}

struct C8D9Node
{
    void* m_item;
    C8D9Node* m_pkNext;
};

struct C8D9List
{
    C8D9Node m_kHead;
    unsigned int ItemsInList() const
    {
        unsigned int ItemUpdateArray = 0;
        for (const C8D9Node* pkNode = &m_kHead; pkNode && pkNode->m_item; pkNode = pkNode->m_pkNext)
            ItemUpdateArray++;
        return ItemUpdateArray;
    }
};

class FUN_00c8d960_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va();
    virtual void vaCur();
    virtual void vaValue();
    virtual void vac();
    virtual void vb();
    virtual C8D9HavokData* CreateHavokData(bool* pbCreated);

    unsigned int unk;
    unsigned int unkCur;
    unsigned int unk0c;
    unsigned int m_uiValue1;
    C8D9List m_kList;

    void bhkEntity_SaveBinary(C8D9Stream* pkStream);
    void bhkRigidBody_SaveBinary(C8D9Stream* pkStream);
};

// Creates Havok data, swaps endianness when not in mode 1, saves list count and item link IDs, then swaps endianness back.
// @fnv 0x00c8d960
// src: XBOX_PDB 0x00c8d960
void FUN_00c8d960_cls::bhkRigidBody_SaveBinary(C8D9Stream* pkStream)
{
    bool bCreated;
    C8D9HavokData* pkData = CreateHavokData(&bCreated);
    if (pkStream->m_ucMode != 1)
        pkData->SwapEndian();

    bhkEntity_SaveBinary(pkStream);

    C8D9SaveBinary(pkStream, m_kList.ItemsInList());

    for (C8D9Node* pkIter = &m_kList.m_kHead; pkIter && pkIter->m_item; pkIter = pkIter->m_pkNext)
        pkStream->SaveLinkID(pkIter->m_item);

    C8D9SaveBinary(pkStream, m_uiValue1);

    if (pkStream->m_ucMode != 1)
        pkData->SwapEndian();
}

struct DebugShape
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
    int unk50;
    int unk54;
    NiPoint3 pos;
};

extern void FUN_00458620(NiPoint3* dst, NiPoint3* src);
extern void* BSTestObjects_CreateCoordinateJack(float r);

struct WorldObject
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
    virtual void v55(void* p, int flag);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59(void* out);
    void* AddDebugNodeToWorld(void* a1);
    void* bhkRigidBody_CreateDisplayGeometry(void* a1);
};

// Gets a node from AddDebugNodeToWorld, creates a shape with 6.0f, sets its position, attaches it, and returns the node.
// @fnv 0x00c8d2f0
// src: XBOX_PDB 0x00c8d2f0
void* WorldObject::bhkRigidBody_CreateDisplayGeometry(void* a1)
{
    WorldObject* pDebugNode = (WorldObject*)AddDebugNodeToWorld(a1);
    if (pDebugNode != 0)
    {
        __m128 src;
        v59(&src);
        NiPoint3 p;
        FUN_00458620(&p, (NiPoint3*)&src);
        DebugShape* __restrict pDebugShape = (DebugShape*)BSTestObjects_CreateCoordinateJack(6.0f);
        if (pDebugShape != 0)
        {
            pDebugShape->pos = p;
            pDebugNode->v55(pDebugShape, 1);
        }
    }
    return pDebugNode;
}
