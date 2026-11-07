// bsshader/bsshaderpplightingproperty.cpp: BSShaderPPLightingProperty, CopyProperty, Target, OwnerX and more (34 functions)

#include "../../include/BSShaderPPLightingProperty.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiNode.h"
extern NiTexture* DAT_011f9510;
#include "../../include/MemoryManager.h"
#include "../../include/BSFaceGenMorphData.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSShaderTextureSet.h"
#include "../../include/Bound.h"
#include "../../include/GO.h"
#include "../../include/NiAlphaProperty.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiStream.h"
#include "../../include/NiTexture.h"
#include "../../include/StrArr.h"
#include "../../include/NiPoint3.h"
// @fnv 0x00b68d30
void BSShaderPPLightingProperty::EnsureNormalMap()
{
    if (!spTextures[1][0].m_pObject)
        reinterpret_cast<void (__thiscall*)(BSShaderPPLightingProperty*, unsigned int, NiTexture*)>(
            (*reinterpret_cast<void***>(this))[0x100 / 4])(this, 0, DAT_011f9510);
}

// @fnv 0x00b67260
// src: XBOX_PDB 0x00b67260
int __fastcall BSShaderPPLightingProperty_GetTexture(char* pThis, int, int idx1, int idx2)
{
    return ((int**)(pThis + 0xAC))[idx1][idx2];
}

struct NewObj
{
    char pad[0x104];
    NewObj();
    static void* operator new(unsigned int n)
    {
        return BSFadeNode::operator new(n);
    }
};
struct SelfStub
{
    void BSShaderLightingProperty_CopyMembers(NewObj*, int);
};
// @fnv 0x00b67610
// src: XBOX_PDB 0x00b67610
NewObj* __fastcall BSShaderPPLightingProperty_CreateClone(SelfStub* self, int edx, int arg)
{
    NewObj* pObj = new NewObj();
    self->BSShaderLightingProperty_CopyMembers(pObj, arg);
    (*(void(__thiscall***)(SelfStub*, NewObj*))self)[0x34](self, pObj);
    return pObj;
}

extern char const* const g_0120043c_arg1;
// @fnv 0x00b671b0
// src: XBOX_PDB 0x00b671b0
char const* const* __cdecl BSShaderPPLightingProperty_GetRTTI()
{
    return &g_0120043c_arg1;
}

// @fnv 0x00b671c0
// src: XBOX_PDB 0x00b671c0
int __fastcall BSShaderPPLightingProperty_GetClampNI(char* self, int)
{
    return *reinterpret_cast<int*>(self + 0xd8);
}

// @fnv 0x00b671d0
// src: XBOX_PDB 0x00b671d0
void __fastcall BSShaderPPLightingProperty_SetClampNI(char* self, int, int v)
{
    *reinterpret_cast<int*>(self + 0xd8) = v;
}

// @fnv 0x00b671e0
// src: XBOX_PDB 0x00b671e0
unsigned short __fastcall BSShaderPPLightingProperty_GetTextureCount(char* self, int)
{
    return *reinterpret_cast<unsigned short*>(self + 0xa8);
}

// @fnv 0x00b671f0
// src: XBOX_PDB 0x00b671f0
unsigned short __fastcall BSShaderPPLightingProperty_QLandscapeTextureCount(char* self, int)
{
    return *reinterpret_cast<unsigned short*>(self + 0xc8);
}

extern "C"
{
    __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
    __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
}

// Preserve reference-count inlining and legacy stream access in this translation unit.
inline void NiRefObject::IncRefCount() { InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount)); }
inline void NiRefObject::DecRefCount() { if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0) DeleteThis(); }
inline void NiRefObject::DecRef() { if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0) DeleteThis(); }
inline void NiRefObject::AcquireReference() { InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount)); }
inline void NiTexture::DecRefCount() { if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0) DeleteThis(); }
inline GO& GO::operator=(void* value) { if (m_pObject != value) { if (m_pObject) static_cast<NiRefObject*>(m_pObject)->DecRefCount(); m_pObject = value; } return *this; }
inline NiBinaryStream* NiStream::GetBinaryStream() { return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c); }
inline unsigned int NiStream::version() { return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4); }
inline void StrArr::AppendReference(char*& value) { unsigned int i = m_usSize; if (i >= m_usMaxSize) SetSize(i + m_usGrowBy); SetAt(i, value); }
inline Bound::Bound() {}

template <class T> struct SmartPtr_00b67200
{
    T* m_pObject;
    SmartPtr_00b67200& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct Container_00b67200
{
    char pad[0xac];
    SmartPtr_00b67200<NiRefObject>* m_apArray[1];
};

// Assigns pObject into the smart-pointer array slot at [index1][index2], updating the reference count via SmartPtr assignment.
// @fnv 0x00b67200
void __fastcall SetArrayElement(Container_00b67200* this_ptr, int unused_edx, unsigned int index1, unsigned int index2,
                                NiRefObject* pObject)
{
    this_ptr->m_apArray[index1][index2] = pObject;
}

// @fnv 0x00b67280
// src: XBOX_PDB 0x00b67280
int __fastcall BSShaderPPLightingProperty_GetBaseTexture(char* self, int)
{
    return **reinterpret_cast<int**>(self + 0xac);
}

struct ContainerClass
{
    char _pad[0xac];
    NiRefObject** m_ppData;
};

extern int(__stdcall* DAT_00fdf1c4)(void*);
extern void(__stdcall* DAT_00fdf1c0)(void*);

// @fnv 0x00b67290
void __fastcall SetManagedObjectAt(ContainerClass* pThis, int, int index, NiRefObject* pNew)
{
    NiRefObject** pSlot = &pThis->m_ppData[index];
    NiRefObject* pOld = *pSlot;
    if (pOld != pNew)
    {
        if (pOld)
        {
            if (!DAT_00fdf1c4((void*)((char*)pOld + 4)))
                pOld->DeleteThis();
        }
        *pSlot = pNew;
        if (pNew)
        {
            DAT_00fdf1c0((void*)((char*)pNew + 4));
        }
    }
}

namespace fnv_00b672e0 {
extern int(__stdcall* DAT_00fdf1c4)(int*);
extern void(__stdcall* DAT_00fdf1c0)(int*);

// @fnv 0x00b672e0
void __fastcall ReplaceArrayElement(void* pThis, int, int index, void* value)
{
    void** arr = *(void***)((char*)pThis + 0xb0);
    void** slot = &arr[index];
    void* pCurrent = *slot;
    if (pCurrent != value)
    {
        if (pCurrent)
        {
            if (DAT_00fdf1c4((int*)((char*)pCurrent + 4)) == 0)
            {
                typedef void(__thiscall * DtorFn)(void*);
                ((DtorFn*)*(void**)pCurrent)[1](pCurrent);
            }
        }
        *slot = value;
        if (value)
            DAT_00fdf1c0((int*)((char*)value + 4));
    }
}
}  // namespace fnv_00b672e0

namespace fnv_00b67330 {

extern int(__stdcall* DAT_00fdf1c4)(unsigned int*);
extern int(__stdcall* DAT_00fdf1c0)(unsigned int*);

// Replaces the NiRefObject pointer at index idx in the array at self+0xb4, releasing the old object and retaining the new one.
// @fnv 0x00b67330
void __fastcall SetRefAt(void* self, int, int idx, NiRefObject* pValue)
{
    NiRefObject** arr = *(NiRefObject***)((char*)self + 0xb4);
    NiRefObject** slot = arr + idx;
    NiRefObject* old = *slot;
    if (old != pValue)
    {
        if (old)
        {
            if (DAT_00fdf1c4(&old->m_uiRefCount) == 0)
                old->DeleteThis();
        }
        *slot = pValue;
        if (pValue)
            DAT_00fdf1c0(&pValue->m_uiRefCount);
    }
}
}  // namespace fnv_00b67330

void __cdecl __Dummy_00b6fef0(void*, unsigned int);
void __fastcall ReleaseStorage_00b66850(void*);
// Calls FUN_00b66850 on self, then if bit 0 of flags is set calls __Dummy_00b6fef0 with self and 0x14, and returns self.
// @fnv 0x00b67580
void* __fastcall FUN_00b67580(void* self, int, unsigned char flags)
{
    ReleaseStorage_00b66850(self);
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x14);
    return self;
}

void __cdecl __Dummy_00b6fef0(void*, unsigned int);
void __fastcall FUN_00b669f0(void*);
// Calls FUN_00b669f0 on self, then if bit 0 of flags is set calls __Dummy_00b6fef0(self, 0x74), and returns self.
// @fnv 0x00b675a0
void* __fastcall FUN_00b675a0(void* self, int, unsigned char flags)
{
    FUN_00b669f0(self);
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x74);
    return self;
}

extern void* DAT_010a91d4;
extern void* DAT_010a91d8;
extern int _fnv_particle_shader_renderer_level;
extern unsigned char DAT_011f91d8;
extern bool DAT_011f9427;
extern int DAT_011f95e4;
extern int __cdecl BSShaderManager_GetAccumulator();

struct TargetClass_00b683e0
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40(void* arg1, void* ebx, void* pLocal, int zero1, int val, int zero2);
};

// Selects a renderer pointer based on particle shader settings, calls V40 with it, and returns the low 16 bits of the resulting local value.
// @fnv 0x00b683e0
// src: XBOX_PDB 0x00b683e0
unsigned short __fastcall BSShaderPPLightingProperty_GetNumberofPasses(TargetClass_00b683e0* this_ptr, int unused_edx, void* arg1)
{
    unsigned int uiResult = 0;
    void* ebx;
    if (!DAT_011f9427 && DAT_011f95e4 != 0 && (DAT_011f91d8 & 0x20) != 0 && _fnv_particle_shader_renderer_level >= 2)
        ebx = DAT_010a91d8;
    else
        ebx = DAT_010a91d4;

    this_ptr->V40(arg1, ebx, &uiResult, 0, BSShaderManager_GetAccumulator(), 0);
    return (unsigned short)uiResult;
}

void __cdecl __Dummy_00b6fef0(void*, unsigned int);
void __fastcall FUN_00b67380(void*);
// Calls FUN_00b67380 on self, then if bit 0 of flags is set calls __Dummy_00b6fef0(self, 0x104), and returns self.
// @fnv 0x00b68fb0
void* __fastcall FUN_00b68fb0(void* self, int, unsigned char flags)
{
    FUN_00b67380(self);
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x104);
    return self;
}

namespace fnv_00b675c0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);

struct FUN_00b675c0_shell
{
    char _p0[0x38];
    int m_38;
    char _p1[0xDC - 0x38 - 4];
    NiRefObject* m_dc;
    void AssignRefObj(NiRefObject* p);
};
// Releases the old m_dc reference, stores p and increments its ref count if different, then resets m_38 to 0.
// @fnv 0x00b675c0
void FUN_00b675c0_shell::AssignRefObj(NiRefObject* apRefObj)
{
    if (m_dc != apRefObj)
    {
        if (m_dc)
            m_dc->DecRefCount();
        m_dc = apRefObj;
        if (m_dc)
            m_dc->IncRefCount();
    }
    m_38 = 0;
}
}  // namespace fnv_00b675c0

extern MemoryManager g_memoryManager;
inline void operator delete[](void* p)
{
    g_memoryManager.Deallocate(p);
}

struct FUN_00ba8cd0
{
    ~FUN_00ba8cd0();
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

struct NiPtr_b67380
{
    NiRefObject* m_pObject;
    ~NiPtr_b67380()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    NiPtr_b67380& operator=(NiRefObject* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = p;
        }
        return *this;
    }
};

struct FUN_00b71410
{
    virtual ~FUN_00b71410();
    char m_pad04[0xa0];
};

struct FUN_00b67380 : FUN_00b71410
{
    NiPtr_b67380 m_spA4;              // +0xa4
    unsigned short m_usElementCount;  // +0xa8
    GO* m_apArrays[6];                // +0xac
    int* m_pC4;                       // +0xc4
    int m_iC8;                        // +0xc8
    int* m_pCC;                       // +0xcc
    NiPtr_b67380 m_spD0;              // +0xd0
    int m_iD4;                        // +0xd4
    int m_iD8;                        // +0xd8
    NiPtr_b67380 m_spDC;              // +0xdc
    float m_fE0;                      // +0xe0
    int m_aiE4[7];                    // +0xe4
    FUN_00ba8cd0* m_p100;             // +0x100
    virtual ~FUN_00b67380();
};

// Releases the six arrays and their element slots, clears the smart pointers and scalars, and deletes m_p100.
// @fnv 0x00b67380
FUN_00b67380::~FUN_00b67380()
{
    if (m_apArrays[0])
    {
        for (int k = 0; k < 6; k++)
        {
            for (int j = 0; j < m_usElementCount; j++)
                m_apArrays[k][j] = 0;
            delete[] m_apArrays[k];
        }
        delete[] m_pCC;
        delete[] m_pC4;
    }
    m_spDC = 0;
    m_iD4 = 0;
    m_fE0 = 0.0f;
    m_spD0 = 0;
    delete m_p100;
}

class NiGeometry;
class ShadowSceneLight;
struct BSShaderProperty__RenderPassArray
{
    void Add(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*,
             ShadowSceneLight*);
};
struct FUN_00b68c10_t
{
    void CreateChildIfMissing(int);
    BSShaderProperty__RenderPassArray* GetRenderPassArray(NiGeometry* pkGeometry);
};

// @fnv 0x00b68c10
BSShaderProperty__RenderPassArray* FUN_00b68c10_t::GetRenderPassArray(NiGeometry* pkGeometry)
{
    if (*(float*)((char*)this + 0xe0) > 0.0f)
        return 0;
    CreateChildIfMissing(1);
    BSShaderProperty__RenderPassArray* pkPasses = *(BSShaderProperty__RenderPassArray**)((char*)this + 0x50);
    if (*(int*)((char*)pkPasses + 0x10) == 0)
    {
        void* pkSkin = *(void**)((char*)pkGeometry + 0x9c);
        bool bHasAnimation = false;
        if (pkSkin)
            bHasAnimation = (*(unsigned short*)((char*)pkSkin + 0x18) >> 9) & 1;
        bool bSpecular = (*(unsigned int*)((char*)this + 0x24) & 0x20) > 0;
        if ((*(unsigned int*)((char*)this + 0x20) & 2) > 0)
        {
            if (bSpecular)
            {
                if (bHasAnimation)
                    pkPasses->Add(pkGeometry, 0x2eb, true, 0, 0, 0, 0, 0);
                else
                    pkPasses->Add(pkGeometry, 0x2e5, true, 0, 0, 0, 0, 0);
            }
            else
            {
                if (bHasAnimation)
                    pkPasses->Add(pkGeometry, 0x2df, true, 0, 0, 0, 0, 0);
                else
                    pkPasses->Add(pkGeometry, 0x2d9, true, 0, 0, 0, 0, 0);
            }
        }
        else
        {
            if (bSpecular)
            {
                if (bHasAnimation)
                    pkPasses->Add(pkGeometry, 0x2ea, true, 0, 0, 0, 0, 0);
                else
                    pkPasses->Add(pkGeometry, 0x2e4, true, 0, 0, 0, 0, 0);
            }
            else
            {
                if (bHasAnimation)
                    pkPasses->Add(pkGeometry, 0x2de, true, 0, 0, 0, 0, 0);
                else
                    pkPasses->Add(pkGeometry, 0x2d8, true, 0, 0, 0, 0, 0);
            }
        }
    }
    return *(BSShaderProperty__RenderPassArray**)((char*)this + 0x50);
}

struct Helper
{
    void BSShaderLightingProperty_LoadBinary(NiStream& stream);
};

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& stream, T& value)
{
    unsigned int uiSize = sizeof(T);
    int iBytesRead = (*reinterpret_cast<NiBinaryStream::ReadFn*>(reinterpret_cast<char*>(&stream) + 8))(&stream, &value, uiSize, &uiSize, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&stream) + 4) += iBytesRead;
}

struct FUN_00b68dc0_class
{
    unsigned char m_ucPadding[0xD8];
    unsigned int m_uiValueD8;
    unsigned char m_ucPaddingE0[4];
    unsigned int m_uiValueE0;
    unsigned int m_uiValueE4;
    unsigned int m_uiValueE8;
    unsigned int m_uiValueEC;

    void LoadFromStream(NiStream& stream);
};

// Reads a base object via FUN_00b70260, then loads m_uiValueD8, an optional byte for versions below 0x17, and m_uiValueE0 through m_uiValueEC from the stream.
// @fnv 0x00b68dc0
void FUN_00b68dc0_class::LoadFromStream(NiStream& stream)
{
    reinterpret_cast<Helper*>(this)->BSShaderLightingProperty_LoadBinary(stream);

    NiBinaryStreamLoad(*stream.GetBinaryStream(), m_uiValueD8);

    stream.ResetStreamState();

    if (stream.version() < 0x17)
    {
        unsigned char ucUnused;
        NiBinaryStreamLoad(*stream.GetBinaryStream(), ucUnused);
    }

    NiBinaryStreamLoad(*stream.GetBinaryStream(), m_uiValueE0);
    NiBinaryStreamLoad(*stream.GetBinaryStream(), m_uiValueE4);
    NiBinaryStreamLoad(*stream.GetBinaryStream(), m_uiValueE8);
    NiBinaryStreamLoad(*stream.GetBinaryStream(), m_uiValueEC);
}

static __forceinline void S_BinRead(NiBinaryStream* bin, void* v, unsigned int bytes)
{
    unsigned int sz = 4;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(bin) + 4) += (*reinterpret_cast<NiBinaryStream::ReadFn*>(reinterpret_cast<char*>(bin) + 0xc))(bin, v, bytes, &sz, 1);
}

struct S_00b68ed0_Obj
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    void BSShaderLightingProperty_SaveBinary(NiStream*);
    void ReadFromStream(NiStream* s);
};
// @fnv 0x00b68ed0
void S_00b68ed0_Obj::ReadFromStream(NiStream* apStream)
{
    BSShaderLightingProperty_SaveBinary(apStream);
    S_BinRead(*reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(apStream) + 0x250), &unkd8, 4);
    apStream->SaveLinkID(reinterpret_cast<const NiObject*>(unka4));
    S_BinRead(*reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(apStream) + 0x250), &unke0, 4);
    S_BinRead(*reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(apStream) + 0x250), &unke4, 4);
    S_BinRead(*reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(apStream) + 0x250), &unke8, 4);
    S_BinRead(*reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(apStream) + 0x250), &unkec, 4);
}

struct CopyAllocator
{
    void* Allocate(unsigned int);
};
extern CopyAllocator copyAllocator;
inline void* operator new[](unsigned int size)
{
    return copyAllocator.Allocate(size);
}
struct CopyPtr
{
    NiRefObject* ptr;
    CopyPtr();
    ~CopyPtr();
    CopyPtr& operator=(const CopyPtr& other)
    {
        if (ptr != other.ptr)
        {
            if (ptr)
                ptr->DecRefCount();
            ptr = other.ptr;
            if (ptr)
                ptr->IncRefCount();
        }
        return *this;
    }
};
struct CopyProperty
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    float field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    int fielda0;
    CopyPtr texture;
    unsigned short count;
    unsigned short fieldaa;
    CopyPtr* maps[6];
    unsigned char* flags;
    unsigned short fieldc8;
    unsigned short fieldca;
    unsigned char* modes;
    CopyPtr ptrd0;
    int fieldd4;
    int fieldd8;
    CopyPtr ptrdc;
    float fielde0;
    int fielde4;
    float fielde8;
    float fieldec;
    void CopyTo(CopyProperty* dest);
};
// @fnv 0x00b676a0
void CopyProperty::CopyTo(CopyProperty* dest)
{
    if (dest->count != count)
    {
        for (int map = 0; map < 6; ++map)
        {
            delete[] dest->maps[map];
            dest->maps[map] = new CopyPtr[count];
        }
        g_memoryManager.Deallocate(dest->modes);
        g_memoryManager.Deallocate(dest->flags);
        dest->modes = new unsigned char[count];
        dest->flags = new unsigned char[count];
        dest->count = count;
    }
    for (int index = 0; index < count; ++index)
    {
        for (int map = 0; map < 6; ++map)
            dest->maps[map][index] = maps[map][index];
        dest->modes[index] = modes[index];
        dest->flags[index] = flags[index];
    }
    dest->ptrd0 = ptrd0;
    dest->fieldc8 = fieldc8;
    dest->fieldd8 = fieldd8;
    dest->ptrdc = ptrdc;
    dest->fielde0 = fielde0;
    dest->fielde4 = fielde4;
    dest->fieldd4 = fieldd4;
    dest->field84 = field84;
    dest->field88 = field88;
    dest->field8c = field8c;
    dest->field90 = field90;
    dest->field30 = field30;
    dest->fielde8 = fielde8;
    dest->fieldec = fieldec;
    dest->texture = texture;
}

struct TexFormat_b68660
{
    int unk00;
    int m_iType;
};

struct TexData_b68660
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    TexFormat_b68660 m_eFormat;
};

struct TexSet_b68660
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    unsigned short m_usCapacity;
    SmartPtr_00b67200<NiRefObject>* m_apTextures[6];
    bool* m_pbC4;
    unsigned short m_usElementCount;
    bool* m_pbCC;

    void Grow();
    void BSShaderPPLightingProperty_SetLandscapeTextureSet(unsigned int uiIndex, BSShaderTextureSet* pSource);
};

// @fnv 0x00b68660
// src: COMMUNITY 0x00b68660
void TexSet_b68660::BSShaderPPLightingProperty_SetLandscapeTextureSet(unsigned int uiIndex, BSShaderTextureSet* pSource)
{
    if (m_usCapacity < 10)
        Grow();
    m_pbCC[uiIndex] = false;
    m_pbC4[uiIndex] = false;
    for (int i = 0; i < 6; i++)
    {
        SmartPtr_00b67200<NiRefObject>** ppRow = &m_apTextures[i];
        SmartPtr_00b67200<NiRefObject>* pSlot = &(*ppRow)[uiIndex];
        if (pSource)
            pSource->GetTexture(static_cast<BSShaderProperty::TextureTypeEnum>(i),
                                *reinterpret_cast<NiPointer<NiTexture>*>(pSlot));
        else
            *pSlot = 0;
        if (i == 1)
        {
            NiTexture* pTexture = (NiTexture*)(*ppRow)[uiIndex].m_pObject;
            if (pTexture && reinterpret_cast<TexData_b68660*>(pTexture->m_pkRendererData))
            {
                TexFormat_b68660* pFormat = &reinterpret_cast<TexData_b68660*>(pTexture->m_pkRendererData)->m_eFormat;
                if (pFormat)
                {
                    int iType = pFormat->m_iType;
                    m_pbCC[uiIndex] = iType == 5 || iType == 6 || iType == 1;
                }
            }
        }
    }
    unsigned short n;
    for (n = 0; n < 9; n++)
    {
        if (!m_apTextures[0][n].m_pObject)
            break;
    }
    m_usElementCount = n > 0 ? n - 1 : 0;
}

struct ShaderProp_b68770
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int shaderType;
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
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int iValueE4;
    void SetFlag(unsigned int flag, bool on);
    void SetFloat(float v);
};

// Recursively applies shader flags 15, 16 and 36 and a float value to geometry objects whose shader type is 8-12, optionally setting iValueE4.
// @fnv 0x00b68770
// src: XBOX_PDB 0x00b68770
void __cdecl BSShaderPPLightingProperty_SetRefractionRecurse(NiAVObject* obj, bool abFlag15, float afFloatValue, bool abFlag16, float afValueE4,
                          bool abFlag36)
{
    if (!obj)
        return;
    if (obj->IsTriBasedGeometry())
    {
        ShaderProp_b68770* prop = reinterpret_cast<ShaderProp_b68770*>(
            static_cast<NiGeometry*>(obj)->m_PropertyState.m_aspProps[NiProperty::SHADE]);
        if (prop && prop->shaderType >= 8 && prop->shaderType <= 12)
        {
            prop->SetFlag(15, abFlag15);
            prop->SetFlag(16, abFlag15 && abFlag16);
            prop->SetFlag(36, abFlag15 && abFlag36);
            prop->SetFloat(afFloatValue);
            if (abFlag16)
                prop->iValueE4 = (int)afValueE4;
        }
    }
    else
    {
        NiNode* node = obj->IsSceneNode();
        if (node)
        {
            unsigned int count = node->m_kChildren.m_usSize;
            for (unsigned int i = 0; i < count; i++)
            {
                NiAVObject* child = node->m_kChildren.m_pBase[i].m_pObject;
                if (child)
                    BSShaderPPLightingProperty_SetRefractionRecurse(child, abFlag15, afFloatValue, abFlag16, afValueE4, abFlag36);
            }
        }
    }
}

struct BSPPL_b68880;
struct Node
{
    int m00;
    int m04;
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
    Node* m30;
};
struct PropObj
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual int vfn_30();
    int m04;
    int m08;
    Node* m0c;
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
    NiAlphaProperty* m9c_arr[1];
    NiAlphaProperty* FUN_00a59d30(unsigned int);
    void UpdateProperties();
};
#include "../../include/NiMemObject.h"
struct FUN_00bb4540 : NiMemObject
{
    FUN_00bb4540(BSPPL_b68880*);
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    int fc4;
    int fc8;
    int fcc;
    int fd0;
    int fd4;
    int fd8;
    int fdc;
    int fe0;
    int fe4;
    int fe8;
    int fec;
    int ff0;
    int ff4;
    int ff8;
    int ffc;
    int f100;
    int f104;
};

extern unsigned char DAT_011f94a6;
extern char DAT_011f9422;
extern int DAT_012007b0;
extern int DAT_011f3728;
bool __cdecl NiObject_IsExactKindOf(void*, void*);
__pragma(comment(
    linker,
    "/alternatename:?FUN_004a2020@BSPPL_b68880@@QAE_NH@Z=?FUN_004a2020@BSShaderPPLightingProperty@@QAE_NH@Z")) struct
    BSPPL_b68880
{
    bool FUN_004a2020(int);
    FUN_00bb4540* BSShaderPPLightingProperty_ClarifyShader(PropObj*, int, int);
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    union
    {
        int m20;
        unsigned char m20b;
    };
    unsigned char m24;
    unsigned char m25;
    unsigned char m26;
    unsigned char m27;
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
};
// Checks the PropObj's flags and alpha property and returns a new FUN_00bb4540 built from this, or null after updating m58/m38/m20.
// @fnv 0x00b68880
// src: XBOX_PDB 0x00b68880
FUN_00bb4540* BSPPL_b68880::BSShaderPPLightingProperty_ClarifyShader(PropObj* pProp, int aiArg2, int aiArg3)
{
    if (pProp && !pProp->vfn_30())
    {
        NiAlphaProperty** sub9c = pProp->m9c_arr;
        if (sub9c == 0)
            pProp->UpdateProperties();
        if ((unsigned)(m24 & 2) > 0 || (unsigned)(m20 & 0x4000) > 0)
        {
            m58 = 1;
        }
        else if ((unsigned)(m20 & 0x800) > 0)
        {
            if (DAT_011f94a6)
            {
                if (FUN_004a2020(0x1c) || NiObject_IsExactKindOf(&DAT_012007b0, this) || DAT_011f9422)
                    return new FUN_00bb4540(this);
            }
            m58 = 0xf;
            if (FUN_004a2020(0x1a) || FUN_004a2020(0x1b))
            {
                if (!(m20b & 0x20))
                    m38 = 0;
                m20 |= 0x20;
            }
        }
        else
        {
            if (FUN_004a2020(0x12))
                return new FUN_00bb4540(this);
            bool f13 = FUN_004a2020(0x13);
            NiAlphaProperty* prop = pProp->FUN_00a59d30(0);
            if (!prop && !f13)
                goto tail;
            if (!prop)
            {
                NiAlphaProperty* alpha = new NiAlphaProperty();
                alpha->m_usAlphaArg &= ~1;
                prop = alpha;
            }
            if ((prop->m_usAlphaArg & 1) || FUN_004a2020(0x1a) || FUN_004a2020(0x1b))
            {
                if (!(m20b & 0x20))
                    m38 = 0;
                m20 |= 0x20;
            }
            if ((prop->m_usAlphaArg & 1) && DAT_011f9422)
                return new FUN_00bb4540(this);
        tail:
            if (FUN_004a2020(0x1a) || FUN_004a2020(0x1b))
            {
                if (DAT_011f9422)
                    return new FUN_00bb4540(this);
                if (!(m20b & 0x20))
                    m38 = 0;
                m20 |= 0x20;
            }
            if (DAT_011f94a6)
            {
                Node* node = pProp->m0c;
                if (node)
                {
                    do
                    {
                        NiObject_IsExactKindOf(&DAT_011f3728, node);
                        node = node->m30;
                    } while (node);
                }
            }
        }
    }
    else
    {
        m58 = 0;
    }
    return 0;
}

// Allocates and returns a new NewObj instance.
// @fnv 0x00b68d50
NewObj* __cdecl CreateNewObj()
{
    return new NewObj();
}

extern const double DAT_01012060;
extern int DAT_01000000;

struct FUN_0066b0d0
{
    BSShaderTextureSet* m_pObject;
    FUN_0066b0d0& operator=(BSShaderTextureSet* apObject);
    operator BSShaderTextureSet*() const
    {
        return m_pObject;
    }
};

class ShaderProp_b68
{
  public:
    int unk;
    int unkCur;
    int unkValue;
    int unk0C;
    int uNewnk;
    int uTmpnk;
    int unk18;
    int unk1C;
    unsigned int m_uiValue1;
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
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA;
    FUN_0066b0d0 m_spTextureSet;
    int unkACur;
    int unkAC;
    int unkB;
    int unkBCur;
    int unkBValue;
    int unkBC;
    int unkC;
    int unkCCur;
    int unkCValue;
    int unkCC;
    int unkD;
    int unkDCur;
    int unkDValue;
    int unkDC;
    float m_fAlpha;

    void BSShaderProperty_PostLinkObject(ShaderProp_b68* apOther);
    void BSShaderPPLightingProperty_LoadTextureSet(float* apAlpha, int aiFlag);
    void BSShaderPPLightingProperty_PostLinkObject(ShaderProp_b68* apOther);
};

template <class T> inline T Min_b68(T a, T b)
{
    return a < b ? a : b;
}
template <class T> inline T Max_b68(T a, T b)
{
    return a > b ? a : b;
}
inline float NiClamp_b68(float fValue, float fMin, float fScaledValue)
{
    if (fValue < fMin)
        return fMin;
    if (fValue > fScaledValue)
        return fScaledValue;
    return fValue;
}

// @fnv 0x00b68fe0
// src: XBOX_PDB 0x00b68fe0
void ShaderProp_b68::BSShaderPPLightingProperty_PostLinkObject(ShaderProp_b68* apOther)
{
    BSShaderProperty_PostLinkObject(apOther);
    if (!((m_uiValue1 & (unsigned int)&DAT_01000000) > 0))
    {
        if (!m_spTextureSet)
            m_spTextureSet = new BSShaderTextureSet;
        BSShaderPPLightingProperty_LoadTextureSet(&apOther->m_fAlpha, 0);
    }
    float fCurrentAlpha = m_fAlpha;
    float fTemp = fCurrentAlpha < DAT_01012060 ? 0.0f : fCurrentAlpha;
    m_fAlpha = Min_b68(fTemp, 1.0f);
}

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString(const char*, bool);
char* __cdecl NiGetViewerString_00a7d490(const char*, unsigned short);
char* __cdecl NiGetViewerString_00a7d4d0(const char*, int);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);
char* __cdecl NiGetViewerString_00a7d5a0(const char*, void*);
char* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);
const char* __cdecl BSUtilities_GetTextureName(void*);
struct Extra
{
    int unk00;
    int unk04;
    int unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
};
struct ExtraPtr
{
    Extra* object;
    operator Extra*() const
    {
        return object;
    }
    Extra* operator->() const
    {
        return object;
    }
};
struct TexturePtr
{
    void* object;
    operator void*() const
    {
        return object;
    }
};
struct Target
{
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
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual int ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual float v10c();
    virtual float v110();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned short unkA8, unkAA;
    TexturePtr* unkac;
    TexturePtr* unkb0;
    TexturePtr* unkb4;
    TexturePtr* unkb8;
    TexturePtr* unkbc;
    TexturePtr* unkc0;
    int unkC4, unkC8;
    unsigned char* unkcc;
    int unkD0, unkD4, unkD8;
    ExtraPtr unkdc;
    float unke0;
    int unke4;
    void BSShaderLightingProperty_GetViewerStrings(StrArr*);
    void BSShaderPPLightingProperty_GetViewerStrings(StrArr* a);
};
// @fnv 0x00b690d0
// src: XBOX_PDB 0x00b690d0
void Target::BSShaderPPLightingProperty_GetViewerStrings(StrArr* apStrings)
{
    char* value;
    const char* name;
    BSShaderLightingProperty_GetViewerStrings(apStrings);
    {
        value = NiViewerStrings_NiGetViewerString_Title(g_0120043c_arg1);
        apStrings->AppendReference(value);
    }
    if (!((unk20 & 0x4000) > 0))
    {
        if (name = BSUtilities_GetTextureName(unkac[0]))
        {
            {
                value = NiGetViewerString_00a7d5e0("base diff", name);
                apStrings->AppendReference(value);
            }
        }
        else
        {
            {
                value = NiGetViewerString_00a7d5a0("base diff", unkac[0]);
                apStrings->AppendReference(value);
            }
        }
        if (name = BSUtilities_GetTextureName(unkb0[0]))
        {
            {
                value = NiGetViewerString_00a7d5e0("base normal", name);
                apStrings->AppendReference(value);
            }
        }
        else
        {
            {
                value = NiGetViewerString_00a7d5a0("base normal", unkb0[0]);
                apStrings->AppendReference(value);
            }
        }
        if (unkac[1])
        {
            if (name = BSUtilities_GetTextureName(unkac[1]))
            {
                value = NiGetViewerString_00a7d5e0("multi diff", name);
                apStrings->AddFirstEmpty(value);
            }
            else
            {
                value = NiGetViewerString_00a7d5a0("multi diff", unkac[1]);
                apStrings->AddFirstEmpty(value);
            }
        }
        if (unkb0[1])
        {
            if (name = BSUtilities_GetTextureName(unkb0[1]))
            {
                value = NiGetViewerString_00a7d5e0("multi normal", name);
                apStrings->AddFirstEmpty(value);
            }
            else
            {
                value = NiGetViewerString_00a7d5a0("multi normal", unkb0[1]);
                apStrings->AddFirstEmpty(value);
            }
        }
    }
    else
    {
        {
            value = NiGetViewerString("landscape texturing", true);
            apStrings->AppendReference(value);
        }
        {
            value = NiGetViewerString_00a7d490("landscape textures", unkA8);
            apStrings->AppendReference(value);
        }
        for (int i = 0; i < 9; ++i)
        {
            if (unkac[i].object != 0)
            {
                if (name = BSUtilities_GetTextureName(unkac[i]))
                {
                    {
                        value = NiGetViewerString_00a7d5e0("base tex", name);
                        apStrings->AppendReference(value);
                    }
                }
                else
                {
                    {
                        value = NiGetViewerString_00a7d5a0("base tex", unkac[i]);
                        apStrings->AppendReference(value);
                    }
                }
                if (unkb0[i])
                {
                    if (name = BSUtilities_GetTextureName(unkb0[i]))
                    {
                        value = NiGetViewerString_00a7d5e0(" normal map", name);
                        apStrings->AddFirstEmpty(value);
                    }
                    else
                    {
                        value = NiGetViewerString_00a7d5a0(" normal map", unkb0[i]);
                        apStrings->AddFirstEmpty(value);
                    }
                }
                if (unkcc[i])
                {
                    value = NiGetViewerString(" specular", true);
                    apStrings->AppendReference(value);
                }
                if (unkb4[i])
                {
                    if (name = BSUtilities_GetTextureName(unkb4[i]))
                    {
                        value = NiGetViewerString_00a7d5e0(" glow map", name);
                        apStrings->AddFirstEmpty(value);
                    }
                    else
                    {
                        value = NiGetViewerString_00a7d5a0(" glow map", unkb4[i]);
                        apStrings->AddFirstEmpty(value);
                    }
                }
            }
        }
    }
    if (unkb8[0].object != 0)
    {
        if (name = BSUtilities_GetTextureName(unkb8[0]))
        {
            {
                value = NiGetViewerString_00a7d5e0("heightmap texture", name);
                apStrings->AppendReference(value);
            }
        }
        else
        {
            {
                value = NiGetViewerString_00a7d5a0("heightmap texture", unkb8[0]);
                apStrings->AppendReference(value);
            }
        }
    }
    if (unkb4[0].object != 0)
    {
        if (name = BSUtilities_GetTextureName(unkb4[0]))
        {
            {
                value = NiGetViewerString_00a7d5e0("glow/skin sst/hair layer texture", name);
                apStrings->AppendReference(value);
            }
        }
        else
        {
            {
                value = NiGetViewerString_00a7d5a0("glow/skin sst/hair layer texture", unkb4[0]);
                apStrings->AppendReference(value);
            }
        }
    }
    if (unkbc[0].object != 0)
    {
        if (name = BSUtilities_GetTextureName(unkbc[0]))
        {
            {
                value = NiGetViewerString_00a7d5e0("envmap texture", name);
                apStrings->AppendReference(value);
            }
        }
        else
        {
            {
                value = NiGetViewerString_00a7d5a0("envmap texture", unkbc[0]);
                apStrings->AppendReference(value);
            }
        }
    }
    if (unkc0[0].object != 0)
    {
        if (name = BSUtilities_GetTextureName(unkc0[0]))
        {
            {
                value = NiGetViewerString_00a7d5e0("envmap mask texture", name);
                apStrings->AppendReference(value);
            }
        }
        else
        {
            {
                value = NiGetViewerString_00a7d5a0("envmap mask texture", unkc0[0]);
                apStrings->AppendReference(value);
            }
        }
    }
    if (!ve0())
    {
        value = NiGetViewerString("clamp", true);
        apStrings->AppendReference(value);
    }
    if ((unk20 & 0x8000) > 0)
    {
        value = NiGetViewerString_00a7d550("refraction power", unke0);
        apStrings->AppendReference(value);
    }
    else if ((unk20 & 0x10000) > 0)
    {
        {
            value = NiGetViewerString_00a7d550("refraction power", unke0);
            apStrings->AppendReference(value);
        }
        {
            value = NiGetViewerString_00a7d4d0("refraction period", unke4);
            apStrings->AppendReference(value);
        }
    }
    if ((unk20 & 1) > 0)
    {
        value = NiGetViewerString_00a7d550("specular lod", v10c());
        apStrings->AppendReference(value);
    }
    if ((unk20 & 128) > 0)
    {
        value = NiGetViewerString_00a7d550("envmap lod", v110());
        apStrings->AppendReference(value);
    }
    if (unkdc)
    {
        {
            value = NiGetViewerString_00a7d5a0("spTexEffectData", unkdc.object);
            apStrings->AppendReference(value);
        }
        {
            value = NiGetViewerString_00a7d550("Fill Color R", unkdc->unk0c);
            apStrings->AppendReference(value);
        }
        {
            value = NiGetViewerString_00a7d550("Fill Color G", unkdc->unk10);
            apStrings->AppendReference(value);
        }
        {
            value = NiGetViewerString_00a7d550("Fill Color R", unkdc->unk14);
            apStrings->AppendReference(value);
        }
        {
            value = NiGetViewerString_00a7d550("Fill Color A", unkdc->unk18);
            apStrings->AppendReference(value);
        }
        {
            value = NiGetViewerString_00a7d550("Edge Color R", unkdc->unk1c);
            apStrings->AppendReference(value);
        }
        {
            value = NiGetViewerString_00a7d550("Edge Color G", unkdc->unk20);
            apStrings->AppendReference(value);
        }
        {
            value = NiGetViewerString_00a7d550("Edge Color R", unkdc->unk24);
            apStrings->AppendReference(value);
        }
        {
            value = NiGetViewerString_00a7d550("Edge Color A", unkdc->unk28);
            apStrings->AppendReference(value);
        }
        {
            value = NiGetViewerString_00a7d550("Edge Falloff", unkdc->unk54);
            apStrings->AppendReference(value);
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int);
};
extern MemoryManagerAllocHelper _g_memoryManager;
extern bool DAT_011fa00c;

template <class T> class TextureArrayPtr
{
  public:
    T* object;
    TextureArrayPtr()
    {
        *(T* volatile*)&object = 0;
    }
    ~TextureArrayPtr()
    {
        if (object)
            object->DecRefCount();
    }
    TextureArrayPtr& operator=(T* value)
    {
        if (object != value)
        {
            if (object)
                object->DecRefCount();
            object = value;
        }
        return *this;
    }
    static void* operator new[](unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
    static void operator delete[](void* p)
    {}
};

struct FUN_00b71720
{
    FUN_00b71720();
    virtual ~FUN_00b71720();
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int field6c;
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    void SetFlag(unsigned int flag)
    {
        if (!(field20 & flag))
            field38 = 0;
        *(volatile unsigned int*)&field20 |= flag;
    }
};

struct ShaderVector8
{
    float x1, y1, z1, w1;
    float x2, y2, z2, w2;
    ShaderVector8() : x1(0.0f), y1(0.0f), z1(0.0f), w1(0.0f), x2(0.0f), y2(0.0f), z2(0.0f), w2(0.0f)
    {}
};

struct FUN_00b66f50 : FUN_00b71720
{
    ShaderVector8 vectors;
    TextureArrayPtr<NiTexture> referencea4;
    unsigned short count;
    TextureArrayPtr<NiTexture>* textures[6];
    unsigned char* channels;
    unsigned int fieldc8;
    unsigned char* enabled;
    TextureArrayPtr<NiTexture> referenced0;
    unsigned int fieldd4, fieldd8;
    TextureArrayPtr<NiTexture> referencedc;
    float valuee0;
    unsigned int fielde4;
    float valuee8, valueec;
    unsigned int fieldf0, fieldf4, fieldf8, fieldfc;
    void* field100;
    FUN_00b66f50();
    virtual ~FUN_00b66f50();
};

// Initialises the object: allocates six texture pointer arrays of size count, two enabled/channels byte arrays, and sets default fields and flags.
// @fnv 0x00b66f50
FUN_00b66f50::FUN_00b66f50()
{
    count = 2;
    for (int group = 0; group < 6; ++group)
    {
        textures[group] = new TextureArrayPtr<NiTexture>[count];
        for (int index = 0; index < count; ++index)
            textures[group][index] = (NiTexture*)0;
    }
    enabled = (unsigned char*)_g_memoryManager.Allocate(2);
    enabled[0] = 0;
    enabled[1] = 0;
    channels = (unsigned char*)_g_memoryManager.Allocate(2);
    channels[0] = 30;
    channels[1] = 30;
    referenced0 = (NiTexture*)0;
    referencedc = (NiTexture*)0;
    valuee0 = 0.0f;
    fielde4 = 0;
    fieldd8 = 3;
    fieldd4 = 0;
    if (DAT_011fa00c)
    {
        SetFlag(0x2000);
    }
    valuee8 = 8.0f;
    field100 = 0;
    field1c = 8;
    valueec = 1.0f;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
struct Pool
{
    void* Game_DoHeapAlloc(unsigned int uiSize);
    void MemoryManager_Deallocate(void* p);
};
extern Pool DAT_011f6238;

struct NiPtrX
{
    NiRefObject* m_pObject;
    NiPtrX(NiRefObject* p = 0);
    ~NiPtrX();
    NiPtrX& operator=(NiRefObject* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiPtrX& operator=(const NiPtrX& p)
    {
        if (m_pObject != p.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = p.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    static void* operator new[](unsigned int s)
    {
        return DAT_011f6238.Game_DoHeapAlloc(s);
    }
    static void operator delete[](void* p)
    {
        DAT_011f6238.MemoryManager_Deallocate(p);
    }
};
struct OwnerX
{
    char pad[0xa8];
    unsigned short m_usSize;
    unsigned short pad2;
    NiPtrX* m_apArrays[6];
    void* m_pc4;
    int unkc8;
    void* m_pcc;
    void GrowArrays();
};
// @fnv 0x00b68450
void OwnerX::GrowArrays()
{
    if (m_usSize >= 10)
        return;
    NiPtrX* apNew[6];
    int i;
    for (i = 0; i < 6; i++)
    {
        apNew[i] = new NiPtrX[10];
        for (int j = 0; j < m_usSize; j++)
            apNew[i][j] = 0;
    }
    for (i = 0; i < 6; i++)
    {
        for (int j = 0; j < m_usSize; j++)
            apNew[i][j] = m_apArrays[i][j];
        delete[] m_apArrays[i];
        m_apArrays[i] = apNew[i];
    }
    DAT_011f6238.MemoryManager_Deallocate(m_pcc);
    m_pcc = DAT_011f6238.Game_DoHeapAlloc(10);
    DAT_011f6238.MemoryManager_Deallocate(m_pc4);
    m_pc4 = DAT_011f6238.Game_DoHeapAlloc(10);
    m_usSize = 10;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

struct RefPtr
{
    NiRefObject* ptr;
    RefPtr& operator=(NiRefObject* value)
    {
        if (ptr != value)
        {
            if (ptr)
                ptr->DecRef();
            ptr = value;
            if (ptr)
                ptr->AcquireReference();
        }
        return *this;
    }
};
struct Property
{
    virtual void Unk00();
    virtual void Unk04();
    virtual void* GetKind();
    bool IsSameKind(void* kind)
    {
        return GetKind() == kind;
    }
};
struct Geometry
{
    unsigned int opaqueTag;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short typeFlags;
    unsigned short unk0e;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    int enabled;
    unsigned int unk2c;
    Property* property;
};
struct WorldBound865
{
    float x, y, z, radius;
};
struct CallerArg
{
    unsigned int unk00;
    unsigned int unk04;
    void* debugName;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    WorldBound865 worldBound;
    WorldBound865* GetBoundingVolume()
    {
        return &worldBound;
    }
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    Geometry* geometry;
    void UpdateProperties();
    NiAlphaProperty* FUN_00a59d30(int);
};
extern NiRefObject* DAT_011f9528;
extern char DAT_011f4aac;
extern int DAT_011f91c0;
extern char DAT_010ae238;
extern char DAT_010ae1f0;
extern void* __cdecl BSShaderManager_CreateTangentSpaceSimple(CallerArg*);
extern void __cdecl Warning_005b5e40(void*, void*);
struct RefHandle
{
    void* ptr;
    void FUN_0066b0d0(void*);
};
struct SelfObj
{
    virtual void UnkV000();
    virtual void UnkV004();
    virtual void UnkV008();
    virtual void UnkV00c();
    virtual void UnkV010();
    virtual void UnkV014();
    virtual void UnkV018();
    virtual void UnkV01c();
    virtual void UnkV020();
    virtual void UnkV024();
    virtual void UnkV028();
    virtual void UnkV02c();
    virtual void UnkV030();
    virtual void UnkV034();
    virtual void UnkV038();
    virtual void UnkV03c();
    virtual void UnkV040();
    virtual void UnkV044();
    virtual void UnkV048();
    virtual void UnkV04c();
    virtual void UnkV050();
    virtual void UnkV054();
    virtual void UnkV058();
    virtual void UnkV05c();
    virtual void UnkV060();
    virtual void UnkV064();
    virtual void UnkV068();
    virtual void UnkV06c();
    virtual void UnkV070();
    virtual void UnkV074();
    virtual void UnkV078();
    virtual void UnkV07c();
    virtual void UnkV080();
    virtual void UnkV084();
    virtual void UnkV088();
    virtual void UnkV08c();
    virtual void UnkV090();
    virtual void UnkV094();
    virtual void UnkV098();
    virtual void UnkV09c();
    virtual void UnkV0a0();
    virtual void UnkV0a4();
    virtual void UnkV0a8();
    virtual void UnkV0ac();
    virtual void UnkV0b0();
    virtual void UnkV0b4();
    virtual void UnkV0b8();
    virtual void UnkV0bc();
    virtual void UnkV0c0();
    virtual void UnkV0c4();
    virtual void UnkV0c8();
    virtual void UnkV0cc();
    virtual void UnkV0d0();
    virtual void UnkV0d4();
    virtual void UnkV0d8();
    virtual void UnkV0dc();
    virtual void UnkV0e0();
    virtual void UpdateMode(int);
    virtual void UnkV0e8();
    virtual void UnkV0ec();
    virtual void UnkV0f0();
    virtual void UnkV0f4();
    virtual void UnkV0f8();
    virtual void UnkV0fc();
    virtual void UnkV100();
    virtual void UnkV104();
    virtual void Refresh();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int primaryFlags;
    unsigned int secondaryFlags;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    int switchState;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    RefPtr* lightingPointer;
    unsigned int unkb0;
    unsigned int unkb4;
    Geometry* geometry;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    RefHandle activeHandle;
    void SetSecondaryFlag(unsigned int mask, bool enabled)
    {
        unsigned int& flags = secondaryFlags;
        if (enabled)
        {
            if (!(flags & mask))
                switchState = 0;
            flags |= mask;
        }
        else
        {
            if (flags & mask)
                switchState = 0;
            flags &= ~mask;
        }
    }
    bool GetSecondaryFlag(unsigned int mask)
    {
        return (secondaryFlags & mask) > 0;
    }
    bool BSShaderPPLightingProperty_SetupGeometry(CallerArg* arg);
};
// Checks and may create the argument's bounding volume, updates secondary flag 0x20, conditionally stores a handle, applies flag-gated updates, then refreshes.
// @fnv 0x00b67a40
// src: XBOX_PDB 0x00b67a40
bool SelfObj::BSShaderPPLightingProperty_SetupGeometry(CallerArg* arg)
{
    if (arg->GetBoundingVolume() == 0)
        arg->UpdateProperties();
    bool b = arg->geometry->enabled || GetSecondaryFlag(0x20);
    if (b)
        SetSecondaryFlag(0x20, true);
    else
        SetSecondaryFlag(0x20, false);
    Geometry* geom = arg->geometry;
    if (geom && !activeHandle.ptr && !((primaryFlags & 0x1000) > 0))
    {
        bool bSameKind = geom->property ? geom->property->IsSameKind(&DAT_011f4aac) : false;
        if (!bSameKind && !(geom->typeFlags & 0xf000))
        {
            activeHandle.FUN_0066b0d0(BSShaderManager_CreateTangentSpaceSimple(arg));
        }
    }
    if ((primaryFlags & 0x100000) > 0)
    {
        *lightingPointer = DAT_011f9528;
        UpdateMode(3);
    }
    if ((primaryFlags & 0x40000) > 0)
    {
        NiAlphaProperty* pAffectedObj = arg->FUN_00a59d30(0);
        if (pAffectedObj && DAT_011f91c0 < 5)
        {
            pAffectedObj->m_usAlphaArg &= 0xfffe;
            pAffectedObj->m_ucAlphaArg2 = 0x80;
        }
    }
    Refresh();
    unsigned int flags = primaryFlags;
    if ((flags & 0x800) <= 0)
    {
        if ((flags & 0x10000000) <= 0 && geometry->opaqueTag)
        {
            Warning_005b5e40(&DAT_010ae238, arg->debugName);
            return true;
        }
    }
    if ((flags & 0x10000000) > 0 || (flags & 0x800) > 0)
    {
        if (!geometry->opaqueTag)
            Warning_005b5e40(&DAT_010ae1f0, arg->debugName);
    }
    return true;
}

extern "C" void _ReadWriteBarrier(void);

struct Material
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    float alpha;
};
struct Props
{
    NiAlphaProperty* alpha;
    unsigned int unk004;
    Material* material;
};
struct Geom
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    Bound* bound;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    Props props;

    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    void* skin;
    NiAlphaProperty* FUN_00a59d30(unsigned int);
};
struct Camera
{
    NiPoint3& ShadowSceneNode_GetCameraPos(NiPoint3&);
};
struct Context
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    bool flag164;
    bool flag165;
    unsigned short unk166;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    Camera* camera;
    unsigned int unk198;
    void* renderer;
};
struct Pass
{
    unsigned int unk000;
    unsigned short id;
    unsigned short unk006;
    bool flag8;
    unsigned char flag9;
    unsigned short unk00a;
    unsigned int* stamp;
};
struct Passes
{
    unsigned int unk000;
    Pass** data;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int count;
    unsigned int Size() const
    {
        return count;
    }
    Pass* Last() const
    {
        return data[count - 1];
    }
};
struct Renderer
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int stamp;
};
struct GlobalRenderer
{
    unsigned int unk000;
    unsigned int unk004;
    Renderer* renderer;
};
extern GlobalRenderer* DAT_011f4748;
extern Bound DAT_011f4288;
extern float DAT_011f9458, DAT_011f9460, DAT_011f9468, DAT_011f946c, DAT_011f9470;
extern int _fnv_particle_shader_renderer_level;
struct DistanceScale
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    float scale;
};
struct ScaleContext
{
    unsigned int unk000;
    unsigned int unk004;
    DistanceScale* object;
};
int BSShaderManager_GetAccumulator();
float LinearInterpolate(float, float, float, float, float);
bool BSShaderManager_GetShadows();
bool Object_ComputeValue_00b66760(unsigned int);
struct Fake_FUN_004a2020
{
    bool GetFlag(unsigned int) const;
};
struct Shader
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void Build1(Geom*, unsigned int, unsigned short*, void*, Context*, unsigned char);
    virtual void Build2(Geom*, unsigned int, unsigned short*, void*, Context*, unsigned char);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int flags;
    unsigned int flags2;
    float opacity;
    float alpha;
    unsigned int unk030;
    float distance;
    unsigned int key;
    Passes* mainPasses;
    Passes* special7;
    Passes* special8;
    Passes* special9;
    unsigned int unk04c;
    unsigned int unk050;
    Passes* special15;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    bool dirty;
    void EnsureNewObj(int);
    void EnsureBa9740Obj(int);
    void EnsureAllocated(int);
    void CreateSpawnedObjectIfMissing(int);
    void FUN_00ba95e0(int);
    void BSShaderPPLightingProperty_AddDepthMapPass_2x(Geom*, bool, bool, Context*);
    void BSShaderProperty_AddConstAlphaPass(Geom*, bool, bool);
    void SetPassEnabled(Geom*, bool, bool);
    void AddPasses(Geom*, bool);
    bool GetFlag(int n)
    {
        return ((Fake_FUN_004a2020*)this)->GetFlag(n);
    }
    void BSShaderProperty_SetAlpha(float);
    void SortShadowSceneLights(Bound*);
    Passes* GetPasses(Geom*, unsigned int, unsigned short*, unsigned int, Context*, unsigned char);
};
// Selects a pass list by type and may update distance, material alpha, or pass IDs before returning it.
// @fnv 0x00b67be0
Passes* Shader::GetPasses(Geom* geom, unsigned int pass, unsigned short* output, unsigned int type, Context* context,
                          unsigned char update)
{
    Props* properties = &geom->props;
    bool skipFade = context->flag165 || context->flag164;
    unsigned int renderKey = pass | (type << 8);
    if (type == 7)
    {
        if ((flags & 0x8000) > 0 || (flags & 0x10000) > 0)
            return 0;
        EnsureNewObj(1);
        if (0 != special7->count)
        {
            Pass* firstPass = special7->data[0];
            if (0 < firstPass->flag9)
                *firstPass->stamp = DAT_011f4748->renderer->stamp;
        }
        else if (update && properties)
        {
            NiAlphaProperty* prop = geom->FUN_00a59d30(0);
            if (prop == 0)
                prop = properties->alpha;
            bool alphaTest = prop && (bool)(int)((unsigned short)(prop->m_usAlphaArg >> 9) & 1);
            BSShaderPPLightingProperty_AddDepthMapPass_2x(geom, geom->skin != 0, alphaTest, context);
        }
        return special7;
    }
    if (type == 8)
    {
        if ((flags & 0x8000) > 0 || (flags & 0x10000) > 0 || (flags2 & 0x10) > 0)
            return special8;
        EnsureBa9740Obj(1);
        if ((bool)special8->count)
        {
            Pass* firstPass = special8->data[0];
            if (firstPass->flag9 > 0)
                *firstPass->stamp = DAT_011f4748->renderer->stamp;
        }
        if (special8->count == 0 && update && properties)
        {
            NiAlphaProperty* prop = geom->FUN_00a59d30(0);
            if (prop == 0)
                prop = properties->alpha;
            bool alphaTest = prop && (bool)(int)((unsigned short)(prop->m_usAlphaArg >> 9) & 1);
            BSShaderProperty_AddConstAlphaPass(geom, geom->skin != 0, alphaTest);
        }
        return special8;
    }
    if (type == 9)
    {
        EnsureAllocated(1);
        SetPassEnabled(geom, (flags & 2) > 0, (flags & 0x100000) > 0);
        return special9;
    }
    if (15 == type)
    {
        CreateSpawnedObjectIfMissing(1);
        if (!special15->count)
            AddPasses(geom, geom->skin != 0);
        return special15;
    }
    FUN_00ba95e0(-1);
    float previousDistance = distance;
    bool fade20000;
    bool fade80 = (bool)(int)((flags & 0x80) > 0 && DAT_011f9460 > 0.0f);
    fade20000 = (bool)(int)((flags & 0x20000) > 0 && DAT_011f9468 > 0.0f);
    bool fade1 = (bool)(int)((flags & 1) > 0 && DAT_011f9458 > 0.0f);
    bool fade4000000 =
        (bool)(int)(((flags & 0x4000000) > 0 || GetFlag(27) == true) && DAT_011f9470 > 0.0f && !GetFlag(35));
    bool stillFade;
    stillFade = fade4000000;
    Bound bound;
    bound = geom->bound ? *geom->bound : DAT_011f4288;
    if ((fade20000 || fade80 || fade1 || fade4000000) && !skipFade)
    {
        // These legacy vector operations use three scalar components.
        float posStorage[3];
        NiPoint3& pos = *reinterpret_cast<NiPoint3*>(posStorage);
        context->camera->ShadowSceneNode_GetCameraPos(pos);
        float deltaStorage[3];
        NiPoint3& delta = *reinterpret_cast<NiPoint3*>(deltaStorage);
        delta.x = bound.x - pos.x;
        delta.y = bound.y - pos.y;
        delta.z = bound.z - pos.z;
        distance = delta.FUN_00457990() - bound.radius;
        if (((ScaleContext*)BSShaderManager_GetAccumulator())->object)
            distance *= ((ScaleContext*)BSShaderManager_GetAccumulator())->object->scale;
        if (distance != previousDistance)
        {
            if (fade20000)
            {
                if ((distance < DAT_011f9468 && DAT_011f9468 <= previousDistance) ||
                    (DAT_011f9468 <= distance && DAT_011f9468 > previousDistance))
                    key = 0;
            }
            else if (fade80)
            {
                if ((distance < DAT_011f9460 && DAT_011f9460 <= previousDistance) ||
                    (distance >= DAT_011f9460 && previousDistance < DAT_011f9460))
                    key = 0;
            }
            else if (fade4000000)
            {
                if ((distance < DAT_011f9470 && DAT_011f9470 <= previousDistance) ||
                    (distance >= DAT_011f9470 && previousDistance < DAT_011f9470))
                    key = 0;
            }
            if (fade1)
            {
                if ((distance < DAT_011f9458 && DAT_011f9458 <= previousDistance) ||
                    (distance >= DAT_011f9458 && DAT_011f9458 > previousDistance))
                    key = 0;
            }
        }
    }
    properties = &geom->props;
    if (properties)
    {
        float materialAlpha;
        if (properties->material)
        {
            materialAlpha = properties->material->alpha * alpha;
            if (fade4000000)
            {
                if (DAT_011f9470 != 0.0f && distance >= DAT_011f9470)
                    stillFade = false;
                else if (DAT_011f946c != 0.0f && DAT_011f9470 != 0.0f && distance >= DAT_011f946c &&
                         distance < DAT_011f9470)
                    materialAlpha = LinearInterpolate(0.0f, 1.0f, DAT_011f9470, DAT_011f946c, distance);
            }
        }
        else
            materialAlpha = alpha;
        BSShaderProperty_SetAlpha(materialAlpha);
    }
    unsigned char updatePasses = update;
    if (key != renderKey || !updatePasses || dirty)
    {
        dirty = false;
        _ReadWriteBarrier();  // Keep the dirty reset before inspecting rebuild flags.
        if ((((flags & 0x4000000) > 0 || GetFlag(5)) && (GetFlag(11) || GetFlag(28))) || GetFlag(5) ||
            (geom->props.alpha->m_usAlphaArg & 1))
            SortShadowSceneLights(&bound);
        if (updatePasses == true)
        {
            mainPasses->count = 0;
            if (opacity == 0.0f)
                return mainPasses;
            if (fade4000000 && !stillFade)
                return mainPasses;
            key = renderKey;
        }
        else
            *output = 0;
        if (1 == _fnv_particle_shader_renderer_level)
            Build1(geom, pass, output, context->renderer, context, updatePasses);
        else if (_fnv_particle_shader_renderer_level >= 2)
            Build2(geom, pass, output, context->renderer, context, updatePasses);
        if (BSShaderManager_GetShadows())
        {
            if (updatePasses)
            {
                Props* propertyRef;
                propertyRef = &geom->props;
                if (propertyRef)
                {
                    NiAlphaProperty* prop = geom->FUN_00a59d30(0);
                    if (prop == 0)
                        prop = propertyRef->alpha;
                    bool alphaTest = prop && (bool)(int)((unsigned short)(prop->m_usAlphaArg >> 9) & 1);
                    void* skin;
                    skin = geom->skin;
                    EnsureNewObj(1);
                    special7->count = 0;
                    BSShaderPPLightingProperty_AddDepthMapPass_2x(geom, skin != 0, alphaTest, context);
                }
            }
            else
                goto finish;
        }
        if (updatePasses && mainPasses->Size() > 0)
        {
            Pass* last = mainPasses->Last();
            if (last)
                last->flag8 = true;
        }
    finish:
        Passes* passList = mainPasses;
        unsigned long passCount = passList->count;
        if (passCount > 1)
        {
            Pass* firstPass = passList->data[0];
            if (Object_ComputeValue_00b66760(firstPass->id))
            {
                --firstPass->id;
                return mainPasses;
            }
        }
        if (passCount > 2)
        {
            for (unsigned int index = 0; index < passCount; ++index)
            {
                Pass* entry = passList->data[index];
                unsigned int id = entry->id;
                if (id == 0xfc || id == 0x102)
                {
                    --entry->id;
                    passList = mainPasses;
                    index = passList->count;
                }
                passCount = mainPasses->count;
            }
        }
    }
    return mainPasses;
}

struct Elem;
struct Sub;
struct Q
{
    int z0;
    int t;
};
struct Elem
{
    int x0, x1, x2, x3, x4, x5, x6, x7, x8;
    Sub* p24;
};
struct Sub
{
    int a0, a1, a2, a3, a4;
    Q q;
};
struct Cls
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int m_flags20;
    int unk24, unk28, unk2C, unk30, unk34;
    int m_38;
    int unk3C, unk40, unk44, unk48, unk4C, unk50, unk54;
    int unk58, unk5C, unk60, unk64, unk68, unk6C, unk70;
    int unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4;
    unsigned short m_a8;
    unsigned short unkAA;
    int unkAC;
    Elem** volatile m_b0;
    int unkB4, unkB8, unkBC, unkC0, unkC4, unkC8;
    unsigned char* m_cc;
    void UpdateFlags();
};

__declspec(noinline) bool InspectDefault(Elem* arg)
{
    Elem* tex = arg;
    if (tex)
    {
        Sub* data = tex->p24;
        if (data)
        {
            const Q* q = &data->q;
            if (q)
            {
                int t = q->t;
                return t == 5 || t == 6 || t == 1;
            }
        }
    }
    return false;
}
// @fnv 0x00b68b10
void Cls::UpdateFlags()
{
    if ((m_flags20 & 0x20000) > 0)
        goto tail;
    {
        bool flag = (m_flags20 & 0x80) > 0;
        Elem* p = m_b0[0];
        if (p != 0)
        {
            Sub* s = p->p24;
            if (s != 0)
            {
                Q* q = &s->q;
                if (q != 0)
                {
                    int t = q->t;
                    flag = flag | (t == 5 || t == 6 || t == 1);
                }
            }
        }
        unsigned int& uiFlags = m_flags20;
        if (flag)
        {
            if ((uiFlags & 1) == 0)
                m_38 = 0;
            uiFlags |= 1u;
        }
        else
        {
            if ((uiFlags & 1) != 0)
                m_38 = 0;
            uiFlags &= ~1u;
        }
        Elem* pDefaultElement = m_b0[1];
        if (pDefaultElement)
            (void)InspectDefault(pDefaultElement);
        else
            (void)InspectDefault(pDefaultElement);
        for (int i = 0; i < m_a8; ++i)
        {
            Elem* pElement = m_b0[i];
            if (pElement != 0)
            {
                Sub* pSub = pElement->p24;
                if (pSub != 0)
                {
                    Q* pQ = &pSub->q;
                    if (pQ != 0)
                    {
                        int t2 = pQ->t;
                        m_cc[i] = (t2 == 5 || t2 == 6 || t2 == 1) ? 1 : 0;
                    }
                }
            }
        }
    }
tail: {
    unsigned int& g = m_flags20;
    if ((g & 0x100) != 0)
        m_38 = 0;
    g &= ~0x100u;
}
}
