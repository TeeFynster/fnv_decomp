
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV64_NIPOINTER_INLINE_BODIES
#define FNV64_NIFIXEDSTRING_OWN_BODIES
#include "../../include/NiRefObject.h"
#include "../../include/NiPointer.h"
#include "../../include/NiTArray.h"
#include "../../include/NiTObjectArray.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiObject.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiShaderConstantMapEntry.h"
#include "../../include/NiFixedString.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiPoint2.h"
#include "../../include/NiD3DRenderState.h"
#include "../../include/NiD3DShaderFactory.h"
#include "../../include/NiTexturingProperty.h"

// Forwards p to the shader factory at offset 0xf8, then passes the pointer at 0x10f8 to its second method.
// @fnv 0x00e87980
// src: COMMUNITY 0x00e87980
void NiD3DRenderState::ApplyMaterial(void* apData)
{
    ((NiD3DShaderFactory*)((char*)this + 0xf8))->UpdateShaderMaterialCache(apData);
    ((NiD3DShaderFactory*)((char*)this + 0xf8))->NiDX9MaterialManager_UpdateToDevice(*(void**)((char*)this + 0x10f8));
}

struct FUN_009ba5f0_shell
{
    void SetChildObject(int);
};

struct FUN_00c89c80_obj
{
    void CopyFromSource(unsigned int uiMaxSize);
};

// @fnv 0x00c89c80
void FUN_00c89c80_obj::CopyFromSource(unsigned int pDest)
{
    if (this && *(void**)((char*)this + 8))
    {
        void* p = *(void**)((char*)this + 8);
        ((FUN_009ba5f0_shell*)pDest)->SetChildObject(*(int*)((char*)p + 0xc));
        *(int*)((char*)pDest + 0xc) = *(int*)((char*)p + 0x14);
        *(int*)((char*)pDest + 0x10) = *(int*)((char*)p + 0x18);
        *(unsigned int*)((char*)pDest + 8) = *(unsigned char*)((char*)p + 0x1c);
    }
    else
    {
        ((FUN_009ba5f0_shell*)pDest)->SetChildObject(0);
        *(int*)((char*)pDest + 0xc) = 0;
        *(int*)((char*)pDest + 0x10) = 0;
    }
}

extern MemoryManager DAT_011f6238;

struct KeyPair
{
    void* m_pFirst;
    void* m_pSecond;

    static void* operator new(unsigned int auiSize) throw()
    {
        return DAT_011f6238.Allocate(auiSize);
    }

    KeyPair(void* apFirst, void* apSecond) throw() : m_pFirst(apFirst), m_pSecond(apSecond)
    {}
};

template <> void NiTArray<KeyPair*, NiTMallocInterface<KeyPair*> >::SetSize(unsigned int);
template <> void NiTArray<KeyPair*, NiTMallocInterface<KeyPair*> >::SetAt(unsigned int, KeyPair* const&);

// Adds pair lookup and insertion to the standard NiTPrimitiveArray layout (data +4, four shorts +8..+0xe).
struct KeyPairArray : NiTPrimitiveArray<KeyPair*>
{
    int FindPairIndex(void* apFirst, void* apSecond);
    bool BSAnimNoteListener_Register(void* apFirst, void* apSecond);
};

// @fnv 0x00a41520
// src: COMMUNITY 0x00a41520
bool KeyPairArray::BSAnimNoteListener_Register(void* apFirst, void* apSecond)
{
    if (FindPairIndex(apFirst, apSecond) == -1)
    {
        KeyPair* pEntry = new KeyPair(apFirst, apSecond);

        unsigned int ItemUpdateArray = m_usSize;
        if (ItemUpdateArray >= m_usMaxSize)
            SetSize(m_usGrowBy + ItemUpdateArray);

        SetAt(ItemUpdateArray, pEntry);
    }
    return false;
}

extern MemoryManager g_memoryManager;
class NiNode;
// NiPointer has no array deallocator in its shared declaration; preserve the game's cookie-aware heap release here.
void __stdcall DestroyArrayElements(void* elements, unsigned int size, int count,
                                   void (__thiscall* destructor)(void*));
// 0x0045cec0 is NiPointer<NiNode>::~NiPointer; its ECX callback entry is shared by these array deletes.
void __fastcall DestroyNiNodePointerElement(void* element);

// Deletes the NiPointer<NiNode> elements and releases the allocation including its element-count cookie.
// @fnv 0x00b7ce30
void __cdecl DeleteNiNodePointerArray(NiPointer<NiNode>* pNodePointerArray)
{
    if (pNodePointerArray)
    {
        unsigned int* cookie = (unsigned int*)pNodePointerArray - 1;
        DestroyArrayElements(pNodePointerArray, sizeof(*pNodePointerArray), *cookie,
                             (void (__thiscall*)(void*))DestroyNiNodePointerElement);
        g_memoryManager.Deallocate(cookie);
    }
}

void* __cdecl _NiMalloc_00aa1070(unsigned int auiSize);
void __cdecl _NiFree_00aa10f0(void* apMemory);

template <> inline KeyPair** NiTMallocInterface<KeyPair*>::Allocate(unsigned int auiCount)
{
    return (KeyPair**)_NiMalloc_00aa1070(sizeof(KeyPair*) * auiCount);
}

// Resizes the key-pair array to auiNewSize, clearing dropped entries, reallocating, copying old entries and freeing the old buffer.
// @fnv 0x00a90180
template <> void NiTArray<KeyPair*, NiTMallocInterface<KeyPair*> >::SetSize(unsigned int auiNewSize)
{
    if (auiNewSize == this->m_usMaxSize)
        return;

    if (auiNewSize < this->m_usSize)
    {
        for (unsigned short i = (unsigned short)auiNewSize; i < this->m_usSize; i++)
        {
            if (this->m_pBase[i] != 0)
            {
                this->m_pBase[i] = 0;
                this->m_usESize += 0xffff;
            }
        }
        this->m_usSize = (unsigned short)auiNewSize;
    }

    KeyPair** oldEntries = this->m_pBase;
    this->m_usMaxSize = (unsigned short)auiNewSize;

    if (auiNewSize > 0)
    {
        this->m_pBase = NiTMallocInterface<KeyPair*>::Allocate(this->m_usMaxSize);

        for (unsigned short i = 0; i < this->m_usSize; i++)
            this->m_pBase[i] = oldEntries[i];

        for (unsigned short j = this->m_usSize; j < this->m_usMaxSize; j++)
            this->m_pBase[j] = 0;
    }
    else
    {
        this->m_pBase = 0;
    }

    _NiFree_00aa10f0(oldEntries);
}

// Stores the entry pointer at the given index, growing the count and adjusting the non-null entry counter when the slot's nullness changes.
// @fnv 0x00ba3aa0
template <> void NiTArray<KeyPair*, NiTMallocInterface<KeyPair*> >::SetAt(unsigned int auiIndex, KeyPair* const& entry)
{
    if (auiIndex >= this->m_usSize)
    {
        this->m_usSize = (unsigned short)(auiIndex + 1);
        if (entry != 0)
        {
            this->m_usESize++;
        }
    }
    else
    {
        if (entry != 0)
        {
            KeyPair** pEntries = this->m_pBase;
            if (pEntries[auiIndex] == 0)
            {
                this->m_usESize++;
            }
        }
        else
        {
            KeyPair** pEntries = this->m_pBase;
            if (pEntries[auiIndex] != 0)
            {
                unsigned short minusOne = 0xffff;
                this->m_usESize += minusOne;
            }
        }
    }
    KeyPair** store = this->m_pBase;
    store[auiIndex] = entry;
}

struct C89CD0Target
{
    void process(void* arg);
};

struct C89CD0Holder
{
    int unk00;
    int unk04;
    C89CD0Target* m_pkTarget;

    void ProcessTarget(void* arg);
};

// @fnv 0x00c89cd0
void C89CD0Holder::ProcessTarget(void* arg)
{
    C89CD0Holder* pkHolder = this;
    if (pkHolder)
    {
        C89CD0Target* pkTarget = pkHolder->m_pkTarget;
        if (pkTarget)
            pkTarget->process(arg);
    }
}

struct Target
{
    void UpdateState_00c89bf0(void* apArg);
};

struct FUN_00c89cf0_cls
{
    int unk00;
    int unk04;
    Target* m_pFlagTarget;

    void DispatchToTarget(void* apArg);
};

// @fnv 0x00c89cf0
void FUN_00c89cf0_cls::DispatchToTarget(void* apArg)
{
    if (this != 0)
    {
        if (m_pFlagTarget != 0)
            m_pFlagTarget->UpdateState_00c89bf0(apArg);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long volatile*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}
inline void NiAVObject::IncRefCount() { NiRefObject::IncRefCount(); }
inline void NiAVObject::DecRefCount() { NiRefObject::DecRefCount(); }
inline void NiShaderConstantMapEntry::IncRefCount() { NiRefObject::IncRefCount(); }
inline void NiShaderConstantMapEntry::DecRefCount() { NiRefObject::DecRefCount(); }

template <> inline NiPointer<NiShaderConstantMapEntry>::NiPointer(NiShaderConstantMapEntry* pObject) throw()
    : m_pObject(pObject)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <> inline NiPointer<NiShaderConstantMapEntry>::~NiPointer() throw()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <> inline NiPointer<NiShaderConstantMapEntry>& NiPointer<NiShaderConstantMapEntry>::operator=(const NiPointer& ptr) throw()
{
    if (m_pObject != ptr.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = ptr.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

typedef NiPointer<NiObject> ObjectPtr;

ObjectPtr* __cdecl NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(unsigned int auiCount);
void __cdecl ReleaseObjectArray(ObjectPtr* pkArray);

// Resizes the object array to uiMaxSize, releasing surplus elements and reallocating m_pBase while preserving existing entries.
// @fnv 0x00a47770
template <> void NiTArray<ObjectPtr, NiTNewInterface<ObjectPtr> >::SetSize(unsigned int uiCapacity)
{
    if (uiCapacity == this->m_usMaxSize)
        return;

    unsigned short i;
    if (uiCapacity < this->m_usSize)
    {
        for (i = (unsigned short)uiCapacity; i < this->m_usSize; i++)
        {
            if (this->m_pBase[i] != ObjectPtr(0))
            {
                this->m_pBase[i] = 0;
                this->m_usESize--;
            }
        }
        this->m_usSize = (unsigned short)uiCapacity;
    }

    ObjectPtr* pSaveBase = this->m_pBase;
    this->m_usMaxSize = (unsigned short)uiCapacity;
    if (uiCapacity > 0)
    {
        this->m_pBase = NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(this->m_usMaxSize);
        for (i = 0; i < this->m_usSize; i++)
            this->m_pBase[i] = pSaveBase[i];
        for (i = this->m_usSize; i < this->m_usMaxSize; i++)
            this->m_pBase[i] = 0;
    }
    else
    {
        this->m_pBase = 0;
    }
    ReleaseObjectArray(pSaveBase);
}

extern char* DAT_0109b220;
extern long DAT_011f4400;
void __cdecl RemoveGlobalConstant(char** name);

inline __declspec(nothrow) NiFixedString::NiFixedString(const NiFixedString& o)
{
    if (o.m_kHandle != DAT_0109b220)
        InterlockedIncrement((long*)(o.m_kHandle - 8));
    m_kHandle = o.m_kHandle;
}
inline NiFixedString::~NiFixedString()
{
    if (m_kHandle != DAT_0109b220)
        InterlockedDecrement((long*)(m_kHandle - 8));
}

struct S_00e87690_Com
{
    virtual long __stdcall v0() throw();
    virtual long __stdcall v1() throw();
    virtual long __stdcall Release() throw();
};

void __cdecl DeleteNiNodePointerArray(void* buffer) throw();

typedef NiTArray<NiPointer<NiShaderConstantMapEntry>, NiTNewInterface<NiPointer<NiShaderConstantMapEntry> > > ShaderEntryArray;

template <> void ShaderEntryArray::RemoveAll() throw();
template <> unsigned int ShaderEntryArray::AddFirstEmpty(const NiPointer<NiShaderConstantMapEntry>&);
template <> inline ShaderEntryArray::~NiTArray() throw()
{
    DeleteNiNodePointerArray(m_pBase);
}

inline NiRefObject::~NiRefObject() throw()
{
    InterlockedDecrement(&DAT_011f4400);
}

// The shader-map base adds its program-type word at +8 to NiRefObject's vtable and reference count.
struct ShaderConstantMapBase : NiRefObject
{
    int unk08;
    virtual ~ShaderConstantMapBase() throw() {}
};

struct FUN_00e87690 : ShaderConstantMapBase
{
    ShaderEntryArray a1;
    ShaderEntryArray a2;
    int unk2c;
    int unk30;
    int unk34;
    S_00e87690_Com* unk38;
    int unk3c;
    int unk40;
    virtual ~FUN_00e87690() throw();
};

// Walks a1 and a2 entries, adjusting refcounts and calling RemoveGlobalConstant on the name for flag type 4, then clears unk3c, releases unk38 and zeros unk40.
// @fnv 0x00e87690
FUN_00e87690::~FUN_00e87690() throw()
{
    for (unsigned int i = 0; i < a1.m_usMaxSize; i++)
    {
        NiShaderConstantMapEntry* p = a1.m_pBase[i].m_pObject;
        if (p)
        {
            InterlockedIncrement((long*)&p->m_uiRefCount);
            if ((p->m_uiValue1 & 0xf0000000) == 0x40000000)
            {
                NiFixedString k(p->m_kControlPoint);
                RemoveGlobalConstant(&k.m_kHandle);
            }
            if (!InterlockedDecrement((long*)&p->m_uiRefCount))
                p->DeleteThis();
        }
    }
    a1.RemoveAll();
    for (unsigned int i = 0; i < a2.m_usMaxSize; i++)
    {
        NiShaderConstantMapEntry* p = a2.m_pBase[i].m_pObject;
        if (p)
        {
            InterlockedIncrement((long*)&p->m_uiRefCount);
            if ((p->m_uiValue1 & 0xf0000000) == 0x40000000)
                RemoveGlobalConstant(&p->m_kControlPoint.m_kHandle);
            if (!InterlockedDecrement((long*)&p->m_uiRefCount))
                p->DeleteThis();
        }
    }
    a2.RemoveAll();
    unk3c = 0;
    if (unk38)
        unk38->Release();
    unk38 = 0;
    unk40 = 0;
}

struct FUN_00e878c0_cls
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
    int m_34;

    int NiD3DShaderConstantMap_InsertEntry(NiShaderConstantMapEntry* apObj);
};

// Holds a reference on apObj while calling FUN_00e87800 on the sub-object at unk0c; sets m_34 to 0x30 if it returns -1, and returns m_34.
// @fnv 0x00e878c0
// src: COMMUNITY 0x00e878c0
int FUN_00e878c0_cls::NiD3DShaderConstantMap_InsertEntry(NiShaderConstantMapEntry* apObj)
{
    NiShaderConstantMapEntry* pObj = apObj;
    *(NiShaderConstantMapEntry* volatile*)&apObj = pObj;
    if (pObj != 0)
    {
        InterlockedIncrement((long volatile*)&pObj->m_uiRefCount);
    }
    ShaderEntryArray* sub = (ShaderEntryArray*)&unk0c;
    bool failed = sub->AddFirstEmpty(*(const NiPointer<NiShaderConstantMapEntry>*)&apObj) == -1;
    if (pObj != 0 && InterlockedDecrement((long volatile*)&pObj->m_uiRefCount) == 0)
    {
        pObj->DeleteThis();
    }
    if (failed)
    {
        m_34 = 0x30;
    }
    return m_34;
}

namespace fnv_00e87920 {

struct FUN_00e87920_cls
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
    int m_34;

    int NiD3DShaderConstantMap_InsertEntry_00e87920(NiShaderConstantMapEntry* apObj);
};

// Holds a reference on apObj while calling FUN_00e87800 on the sub-object at unk1c; sets m_34 to 0x30 if it returns -1, and returns m_34.
// @fnv 0x00e87920
// src: GAMEBRYO_LIB 0x00e87920
int FUN_00e87920_cls::NiD3DShaderConstantMap_InsertEntry_00e87920(NiShaderConstantMapEntry* apObj)
{
    NiShaderConstantMapEntry* pObj = apObj;
    *(NiShaderConstantMapEntry* volatile*)&apObj = pObj;
    if (pObj != 0)
    {
        InterlockedIncrement((long volatile*)&pObj->m_uiRefCount);
    }
    ShaderEntryArray* sub = (ShaderEntryArray*)&unk1c;
    bool failed = sub->AddFirstEmpty(*(const NiPointer<NiShaderConstantMapEntry>*)&apObj) == -1;
    if (pObj != 0 && InterlockedDecrement((long volatile*)&pObj->m_uiRefCount) == 0)
    {
        pObj->DeleteThis();
    }
    if (failed)
    {
        m_34 = 0x30;
    }
    return m_34;
}
}  // namespace fnv_00e87920

class TextureMapTransform
{
  public:
    int unk00;
    int unk04;
    float unk08;
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

    static void* operator new(size_t size) throw()
    {
        return DAT_011f6238.Allocate(size);
    }
    TextureMapTransform(const NiPoint2& kTranslate, float m_fRotation, const NiPoint2& kScale,
                       const NiPoint2& kTargetCenter, int eMethod) throw();

    NiPoint2 GetTranslate() const
    {
        return *(NiPoint2*)((char*)this + 0);
    }
    float GetRotate() const
    {
        return *(float*)((char*)this + 8);
    }
    NiPoint2 GetScale() const
    {
        return *(NiPoint2*)((char*)this + 0xc);
    }
    NiPoint2 GetNavMeshData() const
    {
        return *(NiPoint2*)((char*)this + 0x14);
    }
    int GetTransformMethod() const
    {
        return *(int*)((char*)this + 0x44);
    }
};

inline NiTexturingProperty::Map::TexturePtr::TexturePtr(const TexturePtr& kPtr) : m_pObject(kPtr.m_pObject)
{
    if (m_pObject)
        InterlockedIncrement((long volatile*)((char*)m_pObject + 4));
}

// Copy-constructs a NiTexturingProperty::Map, copying flags and texture, and deep-copying the texture transform if present.
// @fnv 0x00a6a8b0
NiTexturingProperty::Map::Map(const Map& kMap) : m_usFlags(kMap.m_usFlags), m_spTexture(kMap.m_spTexture)
{
    if (kMap.m_pTextureTransform)
    {
        m_pTextureTransform =
            new TextureMapTransform(kMap.m_pTextureTransform->GetTranslate(), kMap.m_pTextureTransform->GetRotate(),
                                   kMap.m_pTextureTransform->GetScale(), kMap.m_pTextureTransform->GetNavMeshData(),
                                   kMap.m_pTextureTransform->GetTransformMethod());
    }
    else
    {
        m_pTextureTransform = 0;
    }
}

#include <string.h>
void __cdecl FUN_00ec61c0(void* apDst, int aiValue, unsigned int auiSize);

struct FUN_004eba20
{
    FUN_004eba20();
    virtual ~FUN_004eba20();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};

template <class T, class TAlloc>
inline NiTArray<T, TAlloc>::NiTArray(unsigned int uiCapacity, unsigned int uiStep)
{
    this->m_usMaxSize = (unsigned short)uiCapacity;
    this->m_usGrowBy = (unsigned short)uiStep;
    this->m_usSize = 0;
    this->m_usESize = 0;
    if (this->m_usMaxSize > 0)
        this->m_pBase = TAlloc::Allocate(this->m_usMaxSize);
    else
        this->m_pBase = 0;
}
// the two array flavours only pick the allocator policy (new/delete vs malloc/free) for the shared base
template <typename T>
inline NiTObjectArray<T>::NiTObjectArray(unsigned int uiCapacity, unsigned int uiStep)
    : NiTArray<T, NiTNewInterface<T> >(uiCapacity, uiStep)
{}
template <typename T>
inline NiTPrimitiveArray<T>::NiTPrimitiveArray(unsigned int uiCapacity, unsigned int uiStep)
    : NiTArray<T, NiTMallocInterface<T> >(uiCapacity, uiStep)
{}

template <class T> struct TFixedArray
{
    unsigned int m_uiSize;
    T* m_pData;
    int unk0c;
    TFixedArray(unsigned int uiSize) : m_uiSize(uiSize), unk0c(0)
    {
        m_pData = (T*)_NiMalloc_00aa1070(uiSize * sizeof(T));
        FUN_00ec61c0(m_pData, 0, m_uiSize * sizeof(T));
    }
    virtual ~TFixedArray();
};
template <class T> struct RenderStateGroup : TFixedArray<T>
{
    RenderStateGroup() : TFixedArray<T>(0x25)
    {}
    virtual ~RenderStateGroup();
};

struct ColorA
{
    float r, g, b, a;
    ColorA(float fR = 0.0f, float fG = 0.0f, float fB = 0.0f, float fA = 0.0f) : r(fR), g(fG), b(fB), a(fA)
    {}
};

struct FUN_00b8a9e0 : FUN_004eba20
{
    int m_24;
    int m_28;
    ColorA m_kFogTint;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    NiPointer<NiRefObject> m_4c;
    NiPointer<NiRefObject> m_50;
    bool m_abFlags[3];
    NiTObjectArray<NiRefObject*> m_58;
    NiTPrimitiveArray<int> m_68;
    RenderStateGroup<int> m_78;

    FUN_00b8a9e0();
    virtual ~FUN_00b8a9e0();
};

// Zero-initializes m_24, m_28, m_3c, m_40, m_44, m_48 and the m_abFlags array; other members use their default constructors.
// @fnv 0x00b8a9e0
FUN_00b8a9e0::FUN_00b8a9e0() : m_24(0), m_28(0), m_3c(0), m_40(0), m_44(0), m_48(0)
{
    memset(m_abFlags, 0, sizeof(m_abFlags));
}

#include <windows.h>

typedef NiPointer<NiGeometry> GeometryPtr;

GeometryPtr* FUN_00c1d740(unsigned int ItemUpdateArray);
void ReleaseObjectArray(GeometryPtr* pBase);

// Sets the array capacity to uiMaxSize, clearing entries past it, copying entries into a new buffer from FUN_00c1d740 and releasing the old buffer.
// @fnv 0x00c1e9a0
template <> void NiTArray<GeometryPtr, NiTNewInterface<GeometryPtr> >::SetSize(unsigned int uiCapacity)
{
    if (uiCapacity == this->m_usMaxSize)
        return;

    unsigned short i;
    if (uiCapacity < this->m_usSize)
    {
        for (i = (unsigned short)uiCapacity; i < this->m_usSize; i++)
        {
            if (this->m_pBase[i] != GeometryPtr(0))
            {
                this->m_pBase[i] = (NiGeometry*)0;
                this->m_usESize--;
            }
        }
        this->m_usSize = (unsigned short)uiCapacity;
    }

    GeometryPtr* pSaveBase = this->m_pBase;
    this->m_usMaxSize = (unsigned short)uiCapacity;
    if (uiCapacity > 0)
    {
        this->m_pBase = FUN_00c1d740(this->m_usMaxSize);
        for (i = 0; i < this->m_usSize; i++)
            this->m_pBase[i] = pSaveBase[i];
        for (i = this->m_usSize; i < this->m_usMaxSize; i++)
            this->m_pBase[i] = (NiGeometry*)0;
    }
    else
    {
        this->m_pBase = 0;
    }
    ReleaseObjectArray(pSaveBase);
}

void __cdecl FUN_00aa1460(void* apSelf, unsigned int auiSize);
void __cdecl RemoveGlobalConstant(void** appRef);

struct FUN_00e7de30_cls
{
    void UpdateReferenceState_00e7de30();
};

struct FUN_00e891f0_cls
{
    void NiD3DTextureStageGroup_RemoveAllStageStates();
    void ClearFields();
};

struct GlobalRefOwner
{
    void FindOrAdd(void* apRef);
};
extern GlobalRefOwner* DAT_0126f6cc;

struct RefHolder
{
    int unk00;
    int unk04;
    void* m_08;
};

struct FUN_00e7ecd0_cls
{
    int unk00;
    int m_04;
    void* m_08;
    int m_0c;
    FUN_00e891f0_cls* m_10;
    int m_14;
    RefHolder* m_18;
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
    int unk58;
    unsigned short m_5c;
    unsigned char m_5e;
    unsigned char m_5f;

    void NiD3DTextureStage_ReturnStageToPool();
};

// If m_5f is 0, calls FUN_00e7de30 then FUN_00aa1460(this, 0x68); otherwise resets m_10, m_18 and other fields and passes this to DAT_0126f6cc->FindOrAdd.
// @fnv 0x00e7ecd0
// src: COMMUNITY 0x00e7ecd0
void FUN_00e7ecd0_cls::NiD3DTextureStage_ReturnStageToPool()
{
    void* ref;

    if (m_5f == 0)
    {
        ((FUN_00e7de30_cls*)this)->UpdateReferenceState_00e7de30();
        FUN_00aa1460(this, 0x68);
        return;
    }

    FUN_00e891f0_cls* obj = m_10;
    m_08 = 0;
    obj->NiD3DTextureStageGroup_RemoveAllStageStates();
    m_10->ClearFields();

    RefHolder* holder = m_18;
    if (holder != 0)
    {
        if (holder->m_08 != DAT_0109b220)
        {
            InterlockedIncrement((LONG*)((char*)holder->m_08 - 8));
        }
        ref = holder->m_08;
        RemoveGlobalConstant(&ref);
        if (ref != DAT_0109b220)
        {
            InterlockedDecrement((LONG*)((char*)ref - 8));
        }
    }

    m_18 = 0;
    m_04 = 0;
    m_0c = 0;
    m_5c = 0;
    m_14 = 0;
    m_5e = 0;

    ref = this;
    DAT_0126f6cc->FindOrAdd(&ref);
}

NiPointer<NiShaderConstantMapEntry>* AllocateGOArray(unsigned int auiCount);
void __cdecl DeleteNiNodePointerArray(NiPointer<NiShaderConstantMapEntry>* pArray);

// Resizes the array to uiMaxSize, clearing excess elements and reallocating the backing pointer array while preserving existing entries.
// @fnv 0x00e87510
template <> void ShaderEntryArray::SetSize(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;

    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != NiPointer<NiShaderConstantMapEntry>(0))
            {
                m_pBase[i] = NiPointer<NiShaderConstantMapEntry>(0);
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }

    NiPointer<NiShaderConstantMapEntry>* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = AllocateGOArray(m_usMaxSize);
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = NiPointer<NiShaderConstantMapEntry>(0);
    }
    else
    {
        m_pBase = 0;
    }

    DeleteNiNodePointerArray(pSaveBase);
}

struct S_00e98aa0_Holder
{
    NiPointer<NiRefObject> m_sp0;
    NiPointer<NiRefObject> m_sp4;
    void SetObject(NiRefObject* p);
};

// Assigns p to m_sp0 and null to m_sp4 through the reference-counting pointer assignment.
// @fnv 0x00e98aa0
void S_00e98aa0_Holder::SetObject(NiRefObject* apRefObj)
{
    m_sp0 = apRefObj;
    m_sp4 = 0;
}

template <class T, class TAlloc>
inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiSlot, const T& kItem)
{
    if (uiSlot >= this->m_usMaxSize)
        SetSize(uiSlot + this->m_usGrowBy);
    SetAt(uiSlot, kItem);
    return uiSlot;
}

// @fnv 0x00c1f360
template <> unsigned int NiTArray<GeometryPtr, NiTNewInterface<GeometryPtr> >::AddFirstEmpty(const GeometryPtr& kItem)
{
    if (kItem == GeometryPtr(0))
        return (unsigned int)~0;

    for (unsigned short i = 0; i < this->m_usSize; i++)
    {
        if (this->m_pBase[i] == GeometryPtr(0))
        {
            this->m_pBase[i] = kItem;
            this->m_usESize++;
            return i;
        }
    }

    return SetAtGrow(this->m_usSize, kItem);
}

struct MaterialDeviceView;

struct MaterialDeviceMethods
{
    void* QueryInterface;
    void* AddRef;
    void* Release;
    void* TestCooperativeLevel;
    void* GetAvailableTextureMem;
    void* EvictManagedResources;
    void* GetDirect3D;
    void* GetDeviceCaps;
    void* GetDisplayMode;
    void* GetCreationParameters;
    void* SetCursorProperties;
    void* SetCursorPosition;
    void* ShowCursor;
    void* CreateAdditionalSwapChain;
    void* GetSwapChain;
    void* GetNumberOfSwapChains;
    void* Reset;
    void* Present;
    void* GetBackBuffer;
    void* GetRasterStatus;
    void* SetDialogBoxMode;
    void* SetGammaRamp;
    void* GetGammaRamp;
    void* CreateTexture;
    void* CreateVolumeTexture;
    void* CreateCubeTexture;
    void* CreateVertexBuffer;
    void* CreateIndexBuffer;
    void* CreateRenderTarget;
    void* CreateDepthStencilSurface;
    void* UpdateSurface;
    void* UpdateTexture;
    void* GetRenderTargetData;
    void* GetFrontBufferData;
    void* StretchRect;
    void* ColorFill;
    void* CreateOffscreenPlainSurface;
    void* SetRenderTarget;
    void* GetRenderTarget;
    void* SetDepthStencilSurface;
    void* GetDepthStencilSurface;
    void* BeginScene;
    void* EndScene;
    void* Clear;
    void* SetTransform;
    void* GetTransform;
    void* MultiplyTransform;
    void* SetViewport;
    void* GetViewport;
    long(__stdcall* SetMaterial)(MaterialDeviceView* device, const void* material);
};

struct MaterialDeviceView
{
    MaterialDeviceMethods* methods;
};

// @fnv 0x00e94050
// src: GAMEBRYO_LIB 0x00e94050
__declspec(noinline) void NiD3DShaderFactory::NiDX9MaterialManager_UpdateToDevice(void* apDevice)
{
    MaterialDeviceView* device = (MaterialDeviceView*)apDevice;
    if (*(bool*)((char*)this + 4))
    {
        *(bool*)((char*)this + 4) = false;
        device->methods->SetMaterial(device, *(void**)this);
    }
}

// Stores element in the first null slot, else grows the array if full and appends it, returning its index; returns -1 for a null element.
// @fnv 0x00e87800
template <> unsigned int ShaderEntryArray::AddFirstEmpty(const NiPointer<NiShaderConstantMapEntry>& element)
{
    if (element == NiPointer<NiShaderConstantMapEntry>(0))
        return 0xffffffff;
    for (unsigned short i = 0; i < m_usSize; ++i)
    {
        if (m_pBase[i] == NiPointer<NiShaderConstantMapEntry>(0))
        {
            m_pBase[i] = element;
            ++m_usESize;
            return i;
        }
    }
    unsigned int oldCount = m_usSize;
    if (oldCount >= m_usMaxSize)
        SetSize(m_usGrowBy + oldCount);
    SetAt(oldCount, element);
    return oldCount;
}
