
// src/bsshader/tallgrassgroup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/tallgrassgroup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/NiAVObject.h"
#include "../../include/NiNode.h"

extern unsigned int DAT_011f9ef8;

void* __cdecl fnv_zlib_memset(void* dst, void* src, unsigned int size);

struct FUN_00bd8750_cls
{
    void UpdateBounds();
};

struct FUN_00bd8a70_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short m_10;
    unsigned short m_12;
    void* m_14;
    void* m_18;
    void TallGrassGroup_Clear();
};

// Clears the two buffers sized by m_10, sets each entry's float at offset 8 to -10.0, subtracts m_12 from DAT_011f9ef8, zeroes m_12, then calls UpdateBounds.
// @fnv 0x00bd8a70
// src: COMMUNITY 0x00bd8a70
void FUN_00bd8a70_cls::TallGrassGroup_Clear()
{
    fnv_zlib_memset(m_18, 0, (unsigned int)m_10 * 4);
    fnv_zlib_memset(m_14, 0, (unsigned int)m_10 << 4);

    for (int iIndex = 0; iIndex < (int)m_10; ++iIndex)
        *(float*)((char*)m_14 + iIndex * 16 + 8) = -10.0f;

    DAT_011f9ef8 -= m_12;
    m_12 = 0;
    ((FUN_00bd8750_cls*)this)->UpdateBounds();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

inline void NiAVObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pObject;
    }
    return *this;
}

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

struct MM
{
    void Deallocate(void* p);
};
extern MM _g_memoryManager;

class FUN_00bd8f90
{
  public:
    NiPointer<NiAVObject> m_pReferencedObject;
    NiPointer<NiAVObject> m_spNode;
    NiPointer<NiAVObject> m_spUnk08;
    NiPointer<NiAVObject> m_spUnk0C;
    int unk10;
    void* m_pUnk14;
    void* m_pUnk18;

    void Reset();
    ~FUN_00bd8f90();
};

// @fnv 0x00bd8f90
FUN_00bd8f90::~FUN_00bd8f90()
{
    static_cast<NiNode*>(m_spNode.operator->())->RemoveObject(m_pReferencedObject);
    NiNode* pkParent = m_spNode->m_pkParent;
    if (pkParent)
        pkParent->RemoveObject(m_spNode);
    m_pReferencedObject = 0;
    m_spNode = 0;
    m_spUnk0C = 0;
    m_spUnk08 = 0;
    Reset();
    if (m_pUnk14)
    {
        _g_memoryManager.Deallocate(m_pUnk14);
        m_pUnk14 = 0;
    }
    void* p18 = m_pUnk18;
    _g_memoryManager.Deallocate(p18);
    m_pUnk18 = 0;
}

// Reconstructed from the current target's disassembly and Ghidra draft.

// No prior contributor candidate was supplied for this claim.

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

void* __cdecl Object_DispatchCommandFour(unsigned int);

struct RefObject
{

    virtual void NoOp();

    virtual void DeleteThis();

    volatile long refCount;

    void Release()
    {

        if (InterlockedDecrement(&refCount) == 0)

            DeleteThis();
    }

    void Retain()
    {
        InterlockedIncrement(&refCount);
    }
};

struct ModelSource : RefObject
{

    unsigned int unk08;

    void* vertices;

    unsigned int vertexCount;

    RefObject* material;

    int unk18;

    int unk1c;

    int unk20;

    int unk24;

    int unk28;

    unsigned short strandCount;

    unsigned short unk2e;

    unsigned char useStyleOne;

    unsigned char useTextureFlag;
};

struct OutputData : RefObject
{

    void* m08;

    void* m0c;

    void* m10;

    void* m14;

    void* m18;

    void* m1c;

    unsigned int m20;

    volatile unsigned int m24;

    int m28;

    int m2c;

    int m30;

    int m34;

    int m38;

    int m3c;

    int m40;

    int m44;

    int m48;

    int m4c;

    int m50;

    int m54;

    int m58;

    int m5c;

    int m60;

    int m64;

    int m68;

    int m6c;

    int m70;

    int m74;

    int m78;

    void* parent;

    int m80;

    RefObject* m84;
    int m88;
    int m8c;
    int m90;
    int m94;
    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
    static void operator delete(void*);
    OutputData();

    void NiAVObject_AttachProperty(int);

    void FUN_00a67260(void*);

    void SetSize_Thunk(int);

    void NiAdditionalGeometryData_SetDataBlock(int, void*, int, int);

    void NiAdditionalGeometryData_SetDataStream(int, int, int, int, int, int, int);

    void FUN_00b57e30(int, int);
};

struct C1AClass : RefObject
{
    void Attach(RefObject*);
    void* m08;
    void* m0c;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    int m70;
    int m74;
    int m78;
    int m7c;
    int m80;
    int m84;
    int m88;
    int m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    int ma0;
    int ma4;
    int ma8;
    int mac;
    int mb0;
    int mb4;
    OutputData* mb8;
    OutputData* GetData() const
    {
        return mb8;
    }
    int mbc;
    int mc0;
    int mc4;
    int mc8;
    int mcc;
    int md0;
    int md4;
    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
    static void operator delete(void*);
};
struct StyleOne : C1AClass
{
    StyleOne(RefObject*);
};
struct StyleTwo : C1AClass
{
    StyleTwo(RefObject*);
};
void __cdecl FinalizeRoot(C1AClass*, int, int);

struct C469Class : RefObject
{

    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;

    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;

    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;

    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    int m70;
    int m74;

    int m78;
    int m7c;
    int m80;
    int m84;
    int m88;
    int m8c;
    int m90;

    int m94;
    int m98;
    int m9c;
    int ma0;
    int ma4;
    int ma8;

    RefObject* child;
    int mb0;

    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
    static void operator delete(void*);
    C469Class();

    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void AttachRoot(C1AClass*, int);
};

struct SmallRef : RefObject
{

    int m08;

    RefObject* m0c;

    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
    static void operator delete(void*);
    SmallRef();
};

struct OtherRef : RefObject
{

    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
    static void operator delete(void*);
    OtherRef();
};

struct GridBuffer : RefObject
{

    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
    static void operator delete(void*);
    GridBuffer(int, int);

    void SetSize_Thunk(int);

    void NiAdditionalGeometryData_SetDataBlock(int, void*, int, int);

    void NiAdditionalGeometryData_SetDataStream(int, int, int, int, int, int, int);
};

struct BufferSubobject
{

    void FUN_00b600e0();

    __forceinline BufferSubobject()
    {
        FUN_00b600e0();
    }
};

struct HeapAllocator
{
    void* Game_DoHeapAlloc(unsigned int);
};

struct QuadIndex
{
    unsigned int first, second, third, fourth;
};

extern HeapAllocator DAT_011f6238;

__forceinline void* __cdecl operator new[](unsigned int bytes, HeapAllocator& alloc)
{
    return alloc.Game_DoHeapAlloc(bytes);
}

extern int DAT_011f91c0;

extern char DAT_011f941e;

template <class T> __forceinline void ResetShared(T*& member, T* next)
{

    if (member != next)
    {

        if (member)
            member->Release();

        member = next;

        if (next)
            next->Retain();
    }
}

template <class T> __forceinline void ResetSharedRef(T*& member, T* const& next)
{
    T* old = member;
    if (old != next)
    {
        if (old)
            old->Release();
        T* fresh = next;
        member = fresh;
        if (fresh)
            fresh->Retain();
    }
}

template <class T> struct RefPtr
{

    T* m_pObject;

    RefPtr() : m_pObject(0)
    {}

    ~RefPtr()
    {
        if (m_pObject)
            m_pObject->Release();
    }

    T* operator->() const
    {
        return m_pObject;
    }
};

struct FUN_00bd8ae0
{

    RefPtr<C1AClass> m00;

    RefPtr<C469Class> m04;

    RefPtr<ModelSource> m08;

    RefPtr<OutputData> m0c;

    unsigned short strandCount;

    unsigned short m12;

    void* lineIndices;

    void* vertexIndices;

    BufferSubobject scratch;

    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;

    int tag3c;

    int tag40;

    unsigned char tag44;

    void TallGrassGroup_Clear();

    FUN_00bd8ae0(ModelSource*, int, int, unsigned char);
};

// Initializes the object from a ModelSource, allocating index arrays, building a GridBuffer, and attaching geometry and node sub-objects.
// @fnv 0x00bd8ae0
FUN_00bd8ae0::FUN_00bd8ae0(ModelSource* source, int mode, int variant, unsigned char auFlag)
{

    tag44 = auFlag;

    strandCount = source->strandCount;

    ResetShared(m08.m_pObject, source);

    tag3c = mode;

    tag40 = variant;

    vertexIndices = new (DAT_011f6238) unsigned int[strandCount];

    lineIndices = new (DAT_011f6238) QuadIndex[strandCount];

    m12 = 0;

    ((FUN_00bd8a70_cls*)this)->TallGrassGroup_Clear();

    if (m00.m_pObject)
    {
        m00->Release();
        m00.m_pObject = 0;
    }

    RefObject* sourceBase = (RefObject*)source->unk08;

    if (source->useStyleOne == 1)
    {
        ResetShared(m00.m_pObject, (C1AClass*)new StyleOne(sourceBase));
    }
    else
    {
        ResetShared(m00.m_pObject, (C1AClass*)new StyleTwo(sourceBase));
    }

    RefObject* property;
    if (DAT_011f91c0 >= 2 && DAT_011f941e)
        property = (RefObject*)source->unk18;
    else
        property = (RefObject*)source->unk1c;
    if (property)
        m00->Attach(property);
    if (source->unk20)
        m00->Attach((RefObject*)source->unk20);

    OutputData* geometry = new OutputData;

    ResetSharedRef(geometry->m84, source->material);

    geometry->parent = this;

    if (auFlag != 0)
    {

        if (!(*(unsigned char*)&geometry->m20 & 4))
            geometry->m38 = 0;

        geometry->m20 |= 4;
    }
    else
    {

        if (*(unsigned char*)&geometry->m20 & 4)
            geometry->m38 = 0;

        geometry->m20 &= ~4;
    }

    if (source->useTextureFlag)
    {

        if (!(*(unsigned int*)&geometry->m24 & 0x2000))
            geometry->m38 = 0;

        geometry->m24 |= 0x2000;
    }
    else
    {

        if (*(unsigned int*)&geometry->m24 & 0x2000)
            geometry->m38 = 0;

        geometry->m24 &= ~0x2000;
    }

    m00->Attach(geometry);

    geometry->m58 = 2;

    ResetShared(m0c.m_pObject, geometry);

    int total = source->vertexCount * *(int*)&source->strandCount;

    GridBuffer* buffer = new GridBuffer(total, 1);

    buffer->SetSize_Thunk(1);

    buffer->NiAdditionalGeometryData_SetDataBlock(0, source->vertices, total * 4, 0);

    buffer->NiAdditionalGeometryData_SetDataStream(0, 0, 0, 1, total, 4, 4);

    m00->GetData()->FUN_00a67260(buffer);

    FinalizeRoot(m00.m_pObject, 0, 0);

    C469Class* node = new C469Class;

    if (m04.m_pObject != node)
    {
        C469Class* old = m04.m_pObject;
        if (old)
        {
            volatile long* counter = &old->refCount;
            if (InterlockedDecrement(counter) == 0)
                old->DeleteThis();
        }
        m04.m_pObject = node;
        if (node)
            node->Retain();
    }

    SmallRef* small = new SmallRef;

    OtherRef* other = new OtherRef;

    ResetShared(small->m0c, (RefObject*)other);

    ResetShared(m04->child, (RefObject*)small);

    m04->AttachRoot(m00.m_pObject, 1);
}
