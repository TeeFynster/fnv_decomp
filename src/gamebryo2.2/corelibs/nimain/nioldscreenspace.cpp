// gamebryo2.2/corelibs/nimain/nioldscreenspace.cpp: NiScreenPolygon, NiScreenGeometry, Holder, HolderBase and more (45 functions)

extern "C" void* __cdecl memset(void*, int, unsigned int);
#pragma intrinsic(memset)
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
#include "../../../../include/ImageSpaceTexture.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiPoint2.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiTPrimitiveArray.h"
#include "../../../../include/NiTObjectArray.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiProperty.h"
#include "../../../../include/NiPropertyState.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiScreenGeometry.h"
#include "../../../../include/NiScreenGeometryData.h"
#include "../../../../include/NiScreenPolygon.h"
#include "../../../../include/NiScreenSpaceCamera.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/StrArr.h"

inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes,
                                              unsigned int* sizes, unsigned int components)
{
    unsigned int count = (*(NIBINARYSTREAM_READFN*)((char*)this + 8))(this, buffer, bytes, sizes, components);
    *(unsigned int*)((char*)this + 4) += count;
    return count;
}
inline void NiRefObject::DecRef()
{
    if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
        DeleteThis();
}
inline void NiRefObject::AcquireReference()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}

typedef NiPointer<NiScreenPolygon> ScreenPolygonPtr;
typedef NiPointer<NiScreenGeometry> ScreenGeometryPtr;
typedef NiTArray<ScreenPolygonPtr, NiTMallocInterface<ScreenPolygonPtr> > ScreenPolygonArray;
typedef NiTArray<ScreenGeometryPtr, NiTMallocInterface<ScreenGeometryPtr> > ScreenGeometryArray;
template <> __declspec(noinline) void ScreenPolygonArray::SetAt(unsigned int, const ScreenPolygonPtr&) throw();
template <> __declspec(noinline) void ScreenGeometryArray::SetAt(unsigned int, const ScreenGeometryPtr&) throw();

// The seven-property state is separate from the NiObject-derived screen polygon.
// Zeroes the properties array, then assigns the contents of other into this object.
// @fnv 0x00a89810
NiPropertyState* __fastcall CopyScreenPropertyState(NiPropertyState* self, void*, const NiPropertyState& other)
{
    memset(self->m_aspProps, 0, sizeof(self->m_aspProps));
    for (unsigned short i = 0; i < 7; ++i)
    {
        NiProperty* old = self->m_aspProps[i];
        if (old != other.m_aspProps[i])
        {
            if (old)
            {
                if (!InterlockedDecrement((volatile long*)&old->m_uiRefCount))
                    old->DeleteThis();
            }
            self->m_aspProps[i] = other.m_aspProps[i];
            if (self->m_aspProps[i])
                InterlockedIncrement((volatile long*)&self->m_aspProps[i]->m_uiRefCount);
        }
    }
    return self;
}

// The shared polygon currently exposes these legacy fields as opaque pointers.
template <class T> inline T& ScreenPolygonMember(ScreenReference*& member)
{
    return reinterpret_cast<T&>(member);
}


extern NiRTTI g_011f5e5c;
// Returns the address of the global object g_011f5e5c.
// @fnv 0x00a8ff70
// src: COMMUNITY 0x00a8ff70
NiRTTI* __cdecl NiScreenGeometry_GetRTTI()
{
    return &g_011f5e5c;
}

extern void* DAT_0109f81c;

// @fnv 0x00a8ff80
// src: EXE 0x00a8ff80
void* __cdecl NiScreenGeometry_CreateObject()
{
    void* p = BSFadeNode::operator new(0xc4);
    if (p)
    {
        ((BSFadeNode*)p)->FUN_00a744a0();
        *(void**)p = &DAT_0109f81c;
        return p;
    }
    return 0;
}


extern NiRTTI g_011f5e64;

// Returns the address of the global object g_011f5e64.
// @fnv 0x00a8ffb0
// src: COMMUNITY 0x00a8ffb0
NiRTTI* __cdecl NiScreenPolygon_GetRTTI()
{
    return &g_011f5e64;
}

namespace fnv_00a8ffc0 {
void __fastcall ConstructNiRefObject(NiRefObject*);

extern int DAT_0109f914;

// @fnv 0x00a8ffc0
// src: EXE 0x00a8ffc0
void* __cdecl NiScreenPolygon_CreateObject()
{
    void* p = BSFadeNode::operator new(0x1c);
    if (p)
    {
        ConstructNiRefObject((NiRefObject*)p);
        unsigned short* pusField0c = reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(p) + 0xc);
        *pusField0c = 0;
        unsigned* puiField10 = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(p) + 0x10);
        *puiField10 = 0;
        puiField10[1] = 0;
        puiField10[2] = 0;
        *reinterpret_cast<unsigned*>(p) = reinterpret_cast<unsigned>(&DAT_0109f914);
        return p;
    }
    return 0;
}
}  // namespace fnv_00a8ffc0

namespace fnv_00a90040 {
void __fastcall FUN_00a89760(void*);
extern int DAT_0109f81c;
void __cdecl __Dummy_00b6fef0(void*, unsigned int);

// @fnv 0x00a90040
void* __fastcall DestroyScreenGeometry(NiScreenGeometry* self, void*, unsigned int flags)
{
    *(int*)self = (int)&DAT_0109f81c;
    FUN_00a89760(self);
    if (flags & 1)
        __Dummy_00b6fef0(self, 0xc4);
    return self;
}
}  // namespace fnv_00a90040

extern "C" void* g_011f5e54;

// @fnv 0x00a90ab0
// src: COMMUNITY 0x00a90ab0
void* __cdecl NiScreenGeometryData_GetRTTI()
{
    return &g_011f5e54;
}


extern NiRTTI g_011f5e6c;

// @fnv 0x00a91690
// src: COMMUNITY 0x00a91690
NiRTTI* NiScreenSpaceCamera_GetRTTI()
{
    return &g_011f5e6c;
}



struct Holder
{
    void ImageSpaceEffectFullScreenBlur_BorrowTextures(int);
};
// @fnv 0x00ba4530
// src: COMMUNITY 0x00ba4530
void Holder::ImageSpaceEffectFullScreenBlur_BorrowTextures(int)
{
    ImageSpaceTexture* p = (ImageSpaceTexture*)((char*)this + 0x58);
    p->CreateRenderTargetTexture((BSTextureManager::RenderTargetType)0x18);
    ((NiTPrimitiveArray<int>*)((char*)this + 0x28))->SetAt(2, (int&)p);
    p = (ImageSpaceTexture*)((char*)this + 0x68);
    p->CreateRenderTargetTexture((BSTextureManager::RenderTargetType)0x18);
    ((NiTPrimitiveArray<int>*)((char*)this + 0x28))->SetAt(3, (int&)p);
}


// @fnv 0x00a2e620
template <class T, class Allocator>
__declspec(noinline) void NiTArray<T, Allocator>::RemoveAll() throw()
{
    for (unsigned short i = 0; i < this->m_usSize; ++i)
    {
        NiRefObject* p = this->m_pBase[i].m_pObject;
        T* pp = &this->m_pBase[i];
        if (p)
        {
            if (InterlockedDecrement((volatile long*)&p->m_uiRefCount) == 0)
                p->DeleteThis();
            pp->m_pObject = 0;
        }
    }
    this->m_usSize = 0;
    this->m_usESize = 0;
}

// Calls NiObject::RegisterStreamables, then registers streamables on 7 objects reached through the pointer at this+8, returning false if the base call fails.
// @fnv 0x00a900c0
bool __fastcall RegisterScreenPolygonStreamables(NiScreenPolygon* self, void*, NiStream& stream)
{
    if (!self->NiObject::RegisterStreamables(stream))
        return false;
    unsigned int i;
    for (i = 0; i < 28; i += 4)
        (*(NiProperty**)((char*)self->unk08 + i))->RegisterStreamables(stream);
    return true;
}

void _NiFreeAlias(void*);
extern MemoryManager g_memoryManager;
struct S_e7f900
{
    void FUN_00e7f900(int);
};
struct V0
{
    virtual void f(int);
};
struct InnerA
{
    void* p0;
    int pad;
    void* p8;
};
struct HostA
{
    void* p0;
    int p4;
    int p8;
    InnerA* p12;
    void ReleaseResources();
};
// @fnv 0x00a90ac0
void HostA::ReleaseResources()
{
    InnerA* pInner = p12;
    p8 = 0;
    if (pInner)
    {
        void* ecxVal = pInner->p0;
        if (ecxVal)
        {
            if (*(int*)((char*)ecxVal - 4))
                ((V0*)ecxVal)->f(3);
            else
                g_memoryManager.Deallocate((char*)ecxVal - 4);
        }
        void* r = pInner->p8;
        if (r)
            ((S_e7f900*)r)->FUN_00e7f900(1);
        g_memoryManager.Deallocate(pInner);
    }
    _NiFreeAlias(p0);
}

struct Caller74690
{
    void __thiscall FUN_00a74690(StrArr*);
};
char* __cdecl _FUN_00a7d330(const char*);
struct Outer913a0 : Caller74690
{
    void __thiscall AppendGlobalString(StrArr*);
};
// Appends the string returned by _FUN_00a7d330(g_011f5e5c) to pkStrings, growing the array by its grow amount when full.
// @fnv 0x00a913a0
void __thiscall Outer913a0::AppendGlobalString(StrArr* pkStrings)
{
    FUN_00a74690(pkStrings);
    char* psz = _FUN_00a7d330(*(const char**)&g_011f5e5c);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiMax = pkStrings->m_usMaxSize;
    if (uiSize >= uiMax)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, psz);
}

namespace fnv_00a91890 {

// Declaration-only adapters provide legacy base calls missing from the shared camera API.
struct CameraViewerCalls
{
    void __thiscall NiCamera_GetViewerStrings(StrArr*);
};
char* __cdecl _FUN_00a7d330(const char*);
// Calls the base implementation, then appends the string returned by _FUN_00a7d330 to pkStrings, growing it if needed.
// @fnv 0x00a91890
void __fastcall AppendScreenSpaceCameraStrings(NiScreenSpaceCamera* self, void*, StrArr* pkStrings)
{
    reinterpret_cast<CameraViewerCalls*>(self)->NiCamera_GetViewerStrings(pkStrings);
    char* tmp = _FUN_00a7d330(*(const char**)&g_011f5e6c);
    unsigned int sz = *(unsigned short*)((char*)pkStrings + 0xa);
    if (sz >= *(unsigned short*)((char*)pkStrings + 8))
    {
        pkStrings->SetSize(*(unsigned short*)((char*)pkStrings + 0xe) + sz);
    }
    pkStrings->SetAt(sz, tmp);
}
}  // namespace fnv_00a91890

void __cdecl _delete(void*, unsigned int);

// Destroys the geometry data, frees it when flags has bit 0 set, and returns its address.
// @fnv 0x00a91910
void* __fastcall DestroyScreenGeometryData(NiScreenGeometryData* self, void*, unsigned int flags)
{
    self->NiScreenGeometryData::~NiScreenGeometryData();
    if (flags & 1)
        _delete(self, 0x70);
    return self;
}

// @fnv 0x00a91e60
void* __thiscall NiScreenSpaceCamera::FUN_00a91e60(unsigned int flags)
{
    FUN_00a915d0();
    if (flags & 1)
        _delete(this, 0x134);
    return this;
}

// @fnv 0x00a91ee0
// src: EXE 0x00a91ee0
BSFadeNode* NiScreenSpaceCamera_CreateObject()
{
    void* p = BSFadeNode::operator new(0x134);
    if (p)
        return (BSFadeNode*)((NiScreenSpaceCamera*)p)->NiScreenSpaceCamera_00a91d80();
    return 0;
}

namespace fnv_00a90560 {

extern MemoryManager g_memoryManager;
extern int DAT_0109f914;
void __cdecl _delete(void*, unsigned int);
struct FUN_00a90560_host : NiRefObject
{
    char _pad[8];
    void* m1;
    void* m2;
    void* m3;
    void* __thiscall FUN_00a90560(unsigned int);
};
// @fnv 0x00a90560
void* __thiscall FUN_00a90560_host::FUN_00a90560(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_0109f914;
    g_memoryManager.Deallocate(m1);
    g_memoryManager.Deallocate(m2);
    g_memoryManager.Deallocate(m3);
    this->NiRefObject::~NiRefObject();
    if (auiFlags & 1)
        fnv_00a90560::_delete(this, 0x1c);
    return this;
}
}  // namespace fnv_00a90560


extern MemoryManager _g_memoryManager;
inline void* NiPoint2::operator new[](size_t size)
{
    return _g_memoryManager.Allocate(size);
}
inline bool NiPoint3::operator!=(const NiPoint3& point)
{
    return !(x == point.x && y == point.y && z == point.z);
}

inline NiColor::NiColor() {}
inline void* NiColor::operator new[](size_t size)
{
    return _g_memoryManager.Allocate(size);
}
inline NiColorA::NiColorA(float red, float green, float blue, float alpha)
    : r(red), g(green), b(blue), a(alpha) {}
// NiColorA has no class allocator; use the game allocator for this unit's arrays.
inline void* __cdecl operator new[](size_t size)
{
    return _g_memoryManager.Allocate(size);
}

// Legacy stream entry points use thiscall; the shared color has no stream methods.
void __fastcall LoadScreenColor(NiColorA*, void*, NiStream&);
void __fastcall SaveScreenColor(NiColorA*, void*, NiStream&);

inline unsigned int NiStreamFileVersion(NiStream& kStream)
{
    return *(unsigned int*)((char*)&kStream + 0xd8);
}
inline NiBinaryStream* NiStreamInput(NiStream& kStream)
{
    return *(NiBinaryStream**)((char*)&kStream + 0x24c);
}
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    pkIstr->BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& kStream, T& val)
{
    NiBinaryStreamLoad(NiStreamInput(kStream), &val, 1);
}



// Loads vertex count, vertex colors, and optional texture and color arrays from the stream, then reads the stream link.
// @fnv 0x00a90d70
void __fastcall LoadScreenPolygon(NiScreenPolygon* self, void*, NiStream& kStream)
{
    self->NiObject::LoadBinary(kStream);

    unsigned char bHasTexture;
    unsigned char bHasColor;
    unsigned short i;

    ReadBinaryValue(kStream, ScreenPolygonMember<unsigned short>(self->unk0C));
    ScreenPolygonMember<NiColor*>(self->unk10) = new NiColor[ScreenPolygonMember<unsigned short>(self->unk0C)];
    for (i = 0; i < ScreenPolygonMember<unsigned short>(self->unk0C); i++)
        ScreenPolygonMember<NiColor*>(self->unk10)[i].LoadBinary(kStream);

    if (NiStreamFileVersion(kStream) < 0x4010000)
    {
        ReadBinaryValue(kStream, (unsigned int&)ScreenPolygonMember<NiPoint2*>(self->unk14));
        bHasTexture = ScreenPolygonMember<NiPoint2*>(self->unk14) != 0;
    }
    else
    {
        ReadBinaryValue(kStream, bHasTexture);
    }
    if (bHasTexture)
    {
        ScreenPolygonMember<NiPoint2*>(self->unk14) = new NiPoint2[ScreenPolygonMember<unsigned short>(self->unk0C)];
        for (i = 0; i < ScreenPolygonMember<unsigned short>(self->unk0C); i++)
            ScreenPolygonMember<NiPoint2*>(self->unk14)[i].LoadBinary(kStream);
    }

    if (NiStreamFileVersion(kStream) < 0x4010000)
    {
        ReadBinaryValue(kStream, (unsigned int&)ScreenPolygonMember<NiColorA*>(self->unk18));
        bHasColor = ScreenPolygonMember<NiColorA*>(self->unk18) != 0;
    }
    else
    {
        ReadBinaryValue(kStream, bHasColor);
    }
    if (bHasColor)
    {
        ScreenPolygonMember<NiColorA*>(self->unk18) = new NiColorA[ScreenPolygonMember<unsigned short>(self->unk0C)];
        for (i = 0; i < ScreenPolygonMember<unsigned short>(self->unk0C); i++)
            reinterpret_cast<void (__thiscall*)(NiColorA*, NiStream&)>(LoadScreenColor)(
                &ScreenPolygonMember<NiColorA*>(self->unk18)[i], kStream);
    }

    kStream.ReadUnsignedInteger();
}

NiScreenGeometryData* __fastcall ConstructScreenGeometryData(NiScreenGeometryData*);

// @fnv 0x00a90b20
// src: EXE 0x00a90b20
void* __cdecl NiScreenGeometryData_CreateObject()
{
    NiScreenGeometryData* object = static_cast<NiScreenGeometryData*>(BSFadeNode::operator new(0x70));

    if (object)
        return ConstructScreenGeometryData(object);

    return 0;
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct ObjA8F260 : NiRefObject
{
    int m_08;
    int m_0c;
    int m_10;

    ObjA8F260() throw()
    {
        *(volatile int*)&m_08 = 0;
        *(volatile int*)&m_0c = 0;
        *(volatile int*)&m_10 = 0;
    }

    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

// Allocates an ObjA8F260, stores the two arguments in m_08 and m_0c, and returns it.
// @fnv 0x00a8f260
void* __cdecl CreateObjA8F260(int aiValue08, int aiValue0c)
{
    ObjA8F260* p = new ObjA8F260();
    p->m_08 = aiValue08;
    p->m_0c = aiValue0c;
    return p;
}


// Processes cloning for the base object and both arrays (NiObject vtable slot 26).
// @fnv 0x00a90100
void __fastcall ProcessScreenSpaceCameraClones(NiScreenSpaceCamera* self, void*, CloningProcess& cloning)
{
    self->NiAVObject::ProcessClone(cloning);
    for (unsigned int i = 0; i < self->m_kObjectPointers.m_usSize; i++)
    {
        NiObject* p = static_cast<NiObject*>(self->m_kObjectPointers.m_pBase[i]);
        if (p)
            p->ProcessClone(cloning);
    }
    for (unsigned int i = 0; i < self->m_kFloatValues.m_usSize; i++)
    {
        NiObject* p = static_cast<NiObject**>(self->m_kFloatValues.m_pData)[i];
        if (p)
            p->ProcessClone(cloning);
    }
}

extern int DAT_0109f814;


extern MemoryManager g_011f6238;

struct FUN_00a902e0_cls
{
    int m_vptr00;
    int m_04;
    void* m_08;
    void* m_0c;
    void* m_10;

    FUN_00a902e0_cls* FUN_00a902e0(unsigned char acFlags);
};

// @fnv 0x00a902e0
FUN_00a902e0_cls* FUN_00a902e0_cls::FUN_00a902e0(unsigned char acFlags)
{
    if (acFlags & 2)
    {
        char* base = (char*)this - 4;
        int i = *(int*)base;
        FUN_00a902e0_cls* p = (FUN_00a902e0_cls*)((char*)this + i * 20);
        i = i - 1;
        if (i >= 0)
        {
            do
            {
                p = (FUN_00a902e0_cls*)((char*)p - 20);
                void* a = p->m_08;
                p->m_vptr00 = (int)&DAT_0109f814;
                g_011f6238.Deallocate(a);
                g_011f6238.Deallocate(p->m_0c);
                g_011f6238.Deallocate(p->m_10);
            } while (--i >= 0);
        }
        if (acFlags & 1)
        {
            g_011f6238.Deallocate(base);
        }
        return (FUN_00a902e0_cls*)base;
    }

    void* a = m_08;
    m_vptr00 = (int)&DAT_0109f814;
    g_011f6238.Deallocate(a);
    g_011f6238.Deallocate(m_0c);
    g_011f6238.Deallocate(m_10);
    if (acFlags & 1)
    {
        g_011f6238.Deallocate(this);
    }
    return this;
}



struct ScrElement
{
    int unk00;
    unsigned short m_usPolygons;
    unsigned short m_usVertices;
    NiPoint2* m_pkVertex;
    NiColorA* m_pkColor;
    NiPoint2* m_pkTexture;
};
template <class T> inline T& ScreenGeometryField(void* object, unsigned int offset)
{
    return *(T*)((char*)object + offset);
}
template <class T> inline const T& ScreenGeometryField(const void* object, unsigned int offset)
{
    return *(const T*)((const char*)object + offset);
}
bool CompareScreenGeometryBase();

// Compares this geometry against pkOther: base fields, m_b58, element counts, then each element's polygon/vertex counts and vertex, color and texture arrays.
// @fnv 0x00a903a0
bool __fastcall IsScreenGeometryDataEqual(NiScreenGeometryData* self, void*, const NiScreenGeometryData* pkOther)
{
    if (!reinterpret_cast<bool (__thiscall*)(NiScreenGeometryData*, const NiScreenGeometryData*)>(
            CompareScreenGeometryBase)(self, pkOther))
        return false;
    if (ScreenGeometryField<bool>(pkOther, 0x58) != ScreenGeometryField<bool>(self, 0x58))
        return false;
    unsigned int ItemUpdateArray = ScreenGeometryField<unsigned short>(pkOther, 0x6c);
    if (ItemUpdateArray != ScreenGeometryField<unsigned short>(self, 0x6c))
        return false;
    if (ScreenGeometryField<unsigned short>(pkOther, 0x6a) != ScreenGeometryField<unsigned short>(self, 0x6a))
        return false;

    unsigned int i = 0;
    if (i < ItemUpdateArray)
    {
        ScrElement** ppkOtherElements = ScreenGeometryField<ScrElement**>(pkOther, 0x64);
        ScrElement** ppkElements = ScreenGeometryField<ScrElement**>(self, 0x64);
        for (; i < ItemUpdateArray; i++)
        {
            ScrElement* pkA = ppkOtherElements[i];
            ScrElement* pkB = ppkElements[i];
            if (pkA)
            {
                if (pkB == 0)
                    return false;
                unsigned int uiPolygons = pkA->m_usPolygons;
                unsigned int uiVertices = pkA->m_usVertices;
                if (uiPolygons != pkB->m_usPolygons)
                    return false;
                if (uiVertices != pkB->m_usVertices)
                    return false;
                NiPoint2* pkVA = pkA->m_pkVertex;
                NiPoint2* pkVB = pkB->m_pkVertex;
                NiColorA* pkCA = pkA->m_pkColor;
                NiColorA* pkCB = pkB->m_pkColor;
                NiPoint2* pkTA = pkA->m_pkTexture;
                NiPoint2* pkTB = pkB->m_pkTexture;
                for (unsigned int j = 0; j < uiPolygons; j++)
                {
                    if (pkVA[j].ForwardCall_0051c330(pkVB[j]))
                        return false;
                    if (pkCA[j] != pkCB[j])
                        return false;
                    for (unsigned int k = 0; k < uiVertices; k++)
                    {
                        if (pkTA[j * uiVertices + k].ForwardCall_0051c330(pkTB[j * uiVertices + k]))
                            return false;
                    }
                }
            }
            else if (pkB)
            {
                return false;
            }
        }
    }
    return true;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_0109f914;


extern MemoryManager DAT_011f6238;

struct Sub_a905c0
{
    void* FUN_00a89810(void* arg);
};

struct SpawnedObj_a905c0
{
    void* m_pVTable;
    unsigned int unk04;
    void* m_08;
    unsigned short m_0c;
    unsigned short unk0e;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;

    void FUN_00a5d3a0();
    SpawnedObj_a905c0() throw();
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

SpawnedObj_a905c0::SpawnedObj_a905c0() throw()
{
    FUN_00a5d3a0();
    m_pVTable = (void*)&DAT_0109f914;
    m_0c = 0;
    unk10 = 0;
    unk14 = 0;
    unk18 = 0;
}

struct OwnerCls_a905c0
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_08;

    void CreateVertexBufferSet(SpawnedObj_a905c0* p, unsigned int arg);
    SpawnedObj_a905c0* CreateSpawnedObj(unsigned int arg);
};

// Allocates a SpawnedObj_a905c0, initializes it with arg, then stores a sub-object created from m_08 into m_08 and returns it.
// @fnv 0x00a905c0
SpawnedObj_a905c0* OwnerCls_a905c0::CreateSpawnedObj(unsigned int arg)
{
    SpawnedObj_a905c0* p = new SpawnedObj_a905c0();
    CreateVertexBufferSet(p, arg);
    void* pAlloc = DAT_011f6238.Game_DoHeapAlloc(0x1c);
    p->m_08 = pAlloc ? ((Sub_a905c0*)pAlloc)->FUN_00a89810(m_08) : 0;
    return p;
}

struct PropSrc
{
    NiProperty* Next();
    unsigned int Count();
};

struct FUN_00a90640_cls
{
    int unk00;
    int unk04;
    NiProperty** m_08;
    void nullsub_3(PropSrc* src);
    void AddPropsFromSource(PropSrc* src);
};

// Calls FUN_00a89af0, then iterates src's items and stores each item with GetType() <= 7 into m_08 by kind, releasing the previous entry.
// @fnv 0x00a90640
void FUN_00a90640_cls::AddPropsFromSource(PropSrc* pSource)
{
    nullsub_3(pSource);
    unsigned int n = pSource->Count();
    if (n == 0)
        return;
    do
    {
        --n;
        NiProperty* item = pSource->Next();
        NiProperty** ppSlots = m_08;
        if (item != 0 && item->GetType() <= 7)
        {
            NiProperty** slot = &ppSlots[item->GetType()];
            NiProperty* old = *slot;
            if (old != item)
            {
                if (old != 0)
                    old->DecRef();
                *slot = item;
                item->AcquireReference();
            }
        }
    } while (n != 0);
}

extern "C" void* g_011f5e74;
extern "C" unsigned int g_011f5e78;
extern "C" void __cdecl FUN_00fdb140(void);
extern "C" int __cdecl FUN_00ec658f(void(__cdecl*)(void));



// @fnv 0x00a908b0
template <> __declspec(noinline) void ScreenPolygonArray::SetAt(unsigned int uiIndex, const ScreenPolygonPtr& element) throw()
{
    NiScreenPolygon* const* ppElem = &element.m_pObject;
    if ((g_011f5e78 & 1) == 0)
    {
        g_011f5e78 |= 1;
        g_011f5e74 = 0;
        FUN_00ec658f(FUN_00fdb140);
    }
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (*ppElem != g_011f5e74)
            m_usESize += 1;
    }
    else
    {
        if (*ppElem != g_011f5e74)
        {
            if (m_pBase[uiIndex].m_pObject == g_011f5e74)
                m_usESize += 1;
        }
        else if (m_pBase[uiIndex].m_pObject != g_011f5e74)
        {
            m_usESize -= 1;
        }
    }

    NiScreenPolygon** slot = &m_pBase[uiIndex].m_pObject;
    NiRefObject* cur = *slot;
    if (cur != *ppElem)
    {
        if (cur)
        {
            if (!InterlockedDecrement((volatile long*)&cur->m_uiRefCount))
                cur->DeleteThis();
        }
        NiScreenPolygon* pNew = *ppElem;
        *slot = pNew;
        if (pNew)
            InterlockedIncrement((volatile long*)&pNew->m_uiRefCount);
    }
}

inline void StrArr::SetAt(unsigned int uiIndex, char*& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element)
            m_usESize++;
    }
    else
    {
        if (element)
        {
            if (!m_pBase[uiIndex])
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex])
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}
inline unsigned int StrArr::AddInline(char* element)
{
    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}

void __stdcall AppendCameraPathEntries(StrArr* apViewerStrings);
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcText);
char* __cdecl NiGetViewerString_00a7d490(const char* pcPrefix, unsigned short usValue);
char* __cdecl NiGetViewerString_00a7d5a0(const char* pcPrefix, const void* pvValue);

extern NiRTTI ms_RTTI_ScreenPolygon;



// Appends the RTTI name, m_usVertices, m_pkVertex, m_pkTexture, m_pkColor and the seven property names/pointers to the ViewerStrings list.
// @fnv 0x00a913f0
void __fastcall AppendScreenPolygonStrings(NiScreenPolygon* self, void*, StrArr* apViewerStrings)
{
    AppendCameraPathEntries(apViewerStrings);
    apViewerStrings->AddInline(NiViewerStrings_NiGetViewerString_Title(ms_RTTI_ScreenPolygon.m_pcName));
    apViewerStrings->AddInline(NiGetViewerString_00a7d490("m_usVertices", ScreenPolygonMember<unsigned short>(self->unk0C)));
    apViewerStrings->AddInline(NiGetViewerString_00a7d5a0("m_pkVertex", self->unk10));
    apViewerStrings->AddInline(NiGetViewerString_00a7d5a0("m_pkTexture", self->unk14));
    apViewerStrings->AddInline(NiGetViewerString_00a7d5a0("m_pkColor", self->unk18));
    for (unsigned int i = 0; i < 7; i++)
    {
        NiProperty* pkProp = reinterpret_cast<NiPropertyState*>(self->unk08)->m_aspProps[i];
        const char* pcRTTIName = pkProp->GetRTTI()->m_pcName;
        apViewerStrings->AddInline(NiGetViewerString_00a7d5a0(pcRTTIName, pkProp));
    }
}

void* NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(unsigned int ItemUpdateArray) throw();

struct ScreenCameraUpdateData
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bParallelUpdate;
    bool m_bFoundParticles;
    bool m_bFoundMorphController;
    bool m_bSceneGraphChange;

    ScreenCameraUpdateData(float fTime = 0.0f, bool m_bUpdateEnabled = false, bool m_bRender = false,
                           bool m_bInterpolate = false, bool m_bTimeToDie = false, bool m_bVisible = false)
        : m_fTime(fTime), m_bUpdate(m_bUpdateEnabled), m_bParallelUpdate(m_bRender), m_bFoundParticles(m_bInterpolate),
          m_bFoundMorphController(m_bTimeToDie), m_bSceneGraphChange(m_bVisible)
    {}
};

extern void* ScreenObjectArrayVtable;
extern void* ScreenFloatArrayVtable;
extern void* ScreenObjectPrimitiveArrayVtable;
extern void* ScreenFloatPrimitiveArrayVtable;

template <class T>
inline void InitializeScreenCameraArray(NiScreenSpaceCamera::PrimitiveArray<T>& array,
    void* arrayVtable, void* primitiveVtable, unsigned short maxSize, unsigned short growBy)
{
    *reinterpret_cast<void**>(&array) = arrayVtable;
    array.m_usMaxSize = maxSize;
    array.m_usGrowBy = growBy;
    array.m_usSize = 0;
    array.m_usESize = 0;
    array.m_pBase = (T*)NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(array.m_usMaxSize);
    *reinterpret_cast<void**>(&array) = primitiveVtable;
}

struct ScreenCameraUpdates
{
    void UpdateWorldData(ScreenCameraUpdateData&) throw();
    void UpdateWorldBound() throw();
};

NiCamera* __fastcall ConstructScreenCameraBase(NiCamera*);
extern void* ScreenSpaceCameraVtable;
// Initializes the screen-space camera and its orthographic frustum, then updates world data and world bound.
// @fnv 0x00a91d80
// src: EXE 0x00a91d80
NiScreenSpaceCamera* NiScreenSpaceCamera::NiScreenSpaceCamera_00a91d80()
{
    ConstructScreenCameraBase(this);
    *reinterpret_cast<void**>(this) = &ScreenSpaceCameraVtable;
    InitializeScreenCameraArray(m_kObjectPointers, &ScreenObjectArrayVtable, &ScreenObjectPrimitiveArrayVtable, 5, 5);
    InitializeScreenCameraArray(m_kFloatValues, &ScreenFloatArrayVtable, &ScreenFloatPrimitiveArrayVtable, 5, 5);
    m_kViewFrustum.m_bOrthographic = true;
    ScreenCameraUpdateData kData;
    reinterpret_cast<ScreenCameraUpdates*>(this)->UpdateWorldData(kData);
    reinterpret_cast<ScreenCameraUpdates*>(this)->UpdateWorldBound();
    return this;
}

struct ScreenCameraCopyOperation
{
    void Copy(NiScreenSpaceCamera*, unsigned int);
};

// Allocates and initializes a screen-space camera, copies the source camera into it, and returns it.
// @fnv 0x00a91e90
NiScreenSpaceCamera* __fastcall CreateScreenSpaceCamera(NiScreenSpaceCamera* self, void*, unsigned int a1)
{
    NiScreenSpaceCamera* p = (NiScreenSpaceCamera*)NiScreenSpaceCamera::operator new(sizeof(NiScreenSpaceCamera));
    NiScreenSpaceCamera* r = p ? p->NiScreenSpaceCamera_00a91d80() : 0;
    reinterpret_cast<ScreenCameraCopyOperation*>(self)->Copy(r, a1);
    return r;
}

struct ElemRef
{
    virtual void Free(int flags);
};

// This effect exposes its embedded array through a reference: owning a
// NiTPrimitiveArray here would add an automatic array destructor to 0x00ba4480.
// The original only destroys the three textures and NodeBase after the loop.
inline NiTPrimitiveArray<ElemRef*>& ScreenEffectEntries(void* array)
{
    return *static_cast<NiTPrimitiveArray<ElemRef*>*>(array);
}



void __stdcall FUN_00ec5fce(void* p, unsigned int size, unsigned int count, void (*ctor)());
void FUN_00ba3a00();

struct NodeBase
{
    virtual void vfn_00();
    ~NodeBase();
};

struct FUN_00ba4480 : NodeBase
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_uiEntryArrayVtable;
    ElemRef** m_ents;
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
    ImageSpaceTexture m_vec58[3];
    ~FUN_00ba4480();
};

// @fnv 0x00ba4480
FUN_00ba4480::~FUN_00ba4480()
{
    for (int i = 0; i < 11; ++i)
    {
        if (m_ents[i] != 0)
        {
            ElemRef* pEntry = m_ents[i];
            if (pEntry)
                pEntry->Free(1);
            ElemRef* tmp = 0;
            ScreenEffectEntries(&m_uiEntryArrayVtable).SetAt((unsigned int)i, tmp);
        }
    }
}

class NiPSysBaseA90
{
  public:
    NiPSysBaseA90() throw();
    virtual ~NiPSysBaseA90();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80;
    int unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    int unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0;
};

class NiPSysDerivedA90 : public NiPSysBaseA90
{
  public:
    NiPSysDerivedA90() throw()
    {}
    virtual ~NiPSysDerivedA90();
};

class NiPSysOwnerA90
{
  public:
    void CopyMemberData(NiPSysBaseA90* pkDest, void* pvProcess);
    NiPSysBaseA90* NiScreenGeometry_CreateClone(void* pvProcess);
};

// @fnv 0x00a90070
// src: XBOX_PDB 0x00a90070
NiPSysBaseA90* NiPSysOwnerA90::NiScreenGeometry_CreateClone(void* pvProcess)
{
    NiPSysDerivedA90* pkClone = new NiPSysDerivedA90;
    CopyMemberData(pkClone, pvProcess);
    return pkClone;
}

inline void NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes, unsigned int)
{
    unsigned int size = bytes;
    unsigned int written = (*(NIBINARYSTREAM_WRITEFN*)((char*)this + 0xc))(
        this, buffer, bytes, &size, 1);
    *(unsigned int*)((char*)this + 4) += written;
}
inline void SaveRaw(NiStream& stream, void* buffer, unsigned int bytes)
{
    (*(NiBinaryStream**)((char*)&stream + 0x250))->BinaryWrite(buffer, bytes, bytes);
}



// The polygon-specific link override is not yet declared in the shared header.
void __fastcall LinkScreenPolygon(NiScreenPolygon*, void*, NiStream&);

// Links the object then writes vertex count, vertex colors, optional texture and color arrays, and property link IDs to the stream.
// @fnv 0x00a90f70
void __fastcall SaveScreenPolygon(NiScreenPolygon* self, void*, NiStream& kStream)
{
    reinterpret_cast<void (__thiscall*)(NiScreenPolygon*, NiStream&)>(LinkScreenPolygon)(self, kStream);
    NiStream& s = kStream;
    SaveRaw(s, &ScreenPolygonMember<unsigned short>(self->unk0C), 2);
    for (unsigned short i = 0; i < ScreenPolygonMember<unsigned short>(self->unk0C); i++)
        ScreenPolygonMember<NiColor*>(self->unk10)[i].SaveBinary(kStream);
    bool bTex = ScreenPolygonMember<NiPoint2*>(self->unk14) != 0;
    SaveRaw(s, &bTex, 1);
    if (bTex)
        for (unsigned short i = 0; i < ScreenPolygonMember<unsigned short>(self->unk0C); i++)
            ScreenPolygonMember<NiPoint2*>(self->unk14)[i].SaveBinary(&kStream);
    bool bCol = ScreenPolygonMember<NiColorA*>(self->unk18) != 0;
    SaveRaw(s, &bCol, 1);
    if (bCol)
        for (unsigned short i = 0; i < ScreenPolygonMember<unsigned short>(self->unk0C); i++)
            reinterpret_cast<void (__thiscall*)(NiColorA*, NiStream&)>(SaveScreenColor)(
                &ScreenPolygonMember<NiColorA*>(self->unk18)[i], kStream);
    unsigned int uiProps = 7;
    SaveRaw(s, &uiProps, 4);
    if (uiProps > 0)
        for (unsigned short i = 0; i < uiProps; i++)
            s.SaveLinkID(reinterpret_cast<const NiObject*>(reinterpret_cast<NiPropertyState*>(self->unk08)->m_aspProps[i]));
}

struct ElemA90
{
    int unk00;
    unsigned short m_usPolygons;
    unsigned short m_usVertices;
    NiPoint2* m_pkVertex;
    NiColorA* m_pkColor;
    NiPoint2* m_pkTexture;
};

// Serializes the host's flag, element count and each element's polygon/vertex/color/texture data to the save stream.
// @fnv 0x00a90b40
void __fastcall SaveScreenGeometryData(NiScreenGeometryData* self, void*, NiStream& stream)
{
    self->NiTriShapeData::SaveBinary(stream);
    char cByte = ScreenGeometryField<bool>(self, 0x58);
    SaveRaw(stream, &cByte, 1);
    unsigned int ItemUpdateArray = ScreenGeometryField<unsigned short>(self, 0x6a);
    SaveRaw(stream, &ItemUpdateArray, 4);
    unsigned int i = 0;
    if (i < ItemUpdateArray)
    {
        do
        {
            ElemA90* pElement = ScreenGeometryField<ElemA90**>(self, 0x64)[i];
            unsigned short usPolygonCount = pElement ? pElement->m_usPolygons : 0;
            SaveRaw(stream, &usPolygonCount, 2);
            if (usPolygonCount != 0)
            {
                NiColorA* pkColor = pElement->m_pkColor;
                NiPoint2* pkTexture = pElement->m_pkTexture;
                unsigned short usVertexCount = pElement->m_usVertices;
                NiPoint2* pkVertex = pElement->m_pkVertex;
                bool bHasVertex = pkVertex != 0;
                SaveRaw(stream, &bHasVertex, 1);
                if (bHasVertex)
                {
                    for (unsigned int j = 0; j < usPolygonCount; ++j)
                        pkVertex[j].SaveBinary(&stream);
                }
                bool bHasColor = pkColor != 0;
                SaveRaw(stream, &bHasColor, 1);
                if (bHasColor)
                {
                    for (unsigned int j = 0; j < usPolygonCount; ++j)
                        reinterpret_cast<void (__thiscall*)(NiColorA*, NiStream&)>(SaveScreenColor)(
                            &pkColor[j], stream);
                }
                SaveRaw(stream, &usVertexCount, 2);
                if (usVertexCount != 0)
                {
                    unsigned int uiTextureCount = usPolygonCount * usVertexCount;
                    if (uiTextureCount > 0)
                    {
                        NiPoint2* pTextureCursor = pkTexture;
                        unsigned int k = uiTextureCount;
                        do
                        {
                            pTextureCursor->SaveBinary(&stream);
                            ++pTextureCursor;
                            --k;
                        } while (k != 0);
                    }
                }
            }
            ++i;
        } while (i < ItemUpdateArray);
    }
}

struct Pool00a91290
{
    void ReleaseResources();
};
extern Pool00a91290* DAT_011f5e50;
inline void DestroyPool(Pool00a91290* p)
{
    if (p)
    {
        p->ReleaseResources();
        g_011f6238.Deallocate(p);
    }
}

// @fnv 0x00a91930
void __cdecl DestroyGlobalPool()
{
    DestroyPool(DAT_011f5e50);
}

void __cdecl NiCamera_LoadBinary();

// @fnv 0x00a90000
// src: XBOX_PDB 0x00a90000
void __cdecl NiScreenSpaceCamera_LoadBinary()
{
    NiCamera_LoadBinary();
}

void NiCamera_SaveBinary();

// @fnv 0x00a90020
// src: XBOX_PDB 0x00a90020
void NiScreenSpaceCamera_SaveBinary()
{
    NiCamera_SaveBinary();
}

extern "C" void __cdecl IsEqualTo();

// @fnv 0x00a90030
// src: XBOX_PDB 0x00a90030
extern "C" void __cdecl NiScreenSpaceCamera_IsEqual()
{
    IsEqualTo();
}

template <class T, class Allocator> inline T& NiTArray<T, Allocator>::GetAt(unsigned int i)
{
    return this->m_pBase[i];
}
template <class T, class Allocator> inline unsigned int NiTArray<T, Allocator>::Add(const T& kItem)
{
    unsigned int size = this->m_usSize;
    if (size >= this->m_usMaxSize) SetSize(size + this->m_usGrowBy);
    SetAt(size, kItem);
    return size;
}
inline NiTPrimitiveArray<ScreenPolygonPtr>& ScreenCameraArrayA(NiScreenSpaceCamera* self)
{
    return reinterpret_cast<NiTPrimitiveArray<ScreenPolygonPtr>&>(self->m_kObjectPointers);
}
inline NiTPrimitiveArray<ScreenGeometryPtr>& ScreenCameraArrayB(NiScreenSpaceCamera* self)
{
    return reinterpret_cast<NiTPrimitiveArray<ScreenGeometryPtr>&>(self->m_kFloatValues);
}

// Calls the base stream routine, re-adds the original elements of both arrays, then calls FUN_00a2e620 on each.
// @fnv 0x00a91f00
void __fastcall LoadScreenSpaceCamera(NiScreenSpaceCamera* self, void*, NiStream& kStream)
{
    self->NiCamera::LoadBinary(kStream);
    unsigned int ItemUpdateArray = ScreenCameraArrayA(self).m_usSize;
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        ScreenCameraArrayA(self).Add(ScreenCameraArrayA(self).GetAt(i));
    ScreenCameraArrayA(self).RemoveAll();
    ItemUpdateArray = ScreenCameraArrayB(self).m_usSize;
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        ScreenCameraArrayB(self).Add(ScreenCameraArrayB(self).GetAt(i));
    ScreenCameraArrayB(self).RemoveAll();
}

extern "C" void* __cdecl FUN_00ec44d0(void* pvDest, const void* pvSrc, unsigned int uiSize);

class A72BB0_StreamBase
{
  public:
    virtual void Unk_00();
};

class A72BB0_DataStream : public A72BB0_StreamBase
{
  public:
    virtual void* Allocate(unsigned int uiSize);
    virtual void SetBuffer(void* pvData, int iUnk);
    virtual void Unk_03();
    virtual void ReleaseBuffer(int iUnk);

    unsigned int m_uiSize;
    void* m_pResource;
    bool m_bCopied;
    bool m_bSmallOwner;
};



template <class T, class Allocator>
inline unsigned int NiTArray<T, Allocator>::SetAtGrow(unsigned int index, const T& value)
{
    if (index >= this->m_usMaxSize) SetSize(index + this->m_usGrowBy);
    SetAt(index, value);
    return index;
}

template <> void NiTArray<A72BB0_DataStream*, NiTMallocInterface<A72BB0_DataStream*> >::SetAt(unsigned int, A72BB0_DataStream* const&);

class A72BB0_DataStreamOwner
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual A72BB0_DataStream* CreateStream();

    int unk04;
    int unk08;
    unsigned short m_usVertexCount;
    unsigned short unk0e;
    int unk10;
    int unk14;
    int unk18;
    NiTPrimitiveArray<A72BB0_DataStream*> m_kStreams;

    bool __thiscall NiAdditionalGeometryData_SetDataBlock(unsigned int uiIndex, void* pvData, unsigned int uiSize, bool bCopy);
};

template <> __declspec(noinline) void NiTArray<A72BB0_DataStream*, NiTMallocInterface<A72BB0_DataStream*> >::SetAt(unsigned int index, A72BB0_DataStream* const& value)
{
    if (index < this->m_usSize)
    {
        if ((this->m_pBase[index] != 0) != (value != 0))
        {
            if (value)
                ++this->m_usESize;
            else
                --this->m_usESize;
        }
    }
    else
    {
        this->m_usSize = (unsigned short)(index + 1);
        if (value)
            ++this->m_usESize;
    }
    this->m_pBase[index] = value;
}

// Uses or creates the stream at uiIndex, optionally allocates a buffer and copies pvData, then stores the stream and bCopy flag.
// @fnv 0x00a72bb0
// src: COMMUNITY 0x00a72bb0
bool A72BB0_DataStreamOwner::NiAdditionalGeometryData_SetDataBlock(unsigned int uiIndex, void* pvData, unsigned int uiSize, bool bCopy)
{
    A72BB0_DataStream* pkStream = 0;
    if (uiIndex < m_kStreams.GetSize())
        pkStream = m_kStreams.GetAt(uiIndex);

    if (!pkStream)
    {
        pkStream = CreateStream();
        if (!pkStream)
            return false;
    }
    else if (pkStream->m_uiSize != uiSize)
    {
        pkStream->ReleaseBuffer(0);
        pkStream->m_pResource = 0;
    }

    if (!pkStream->m_pResource)
    {

        if (bCopy)
        {
            pkStream->m_bSmallOwner = m_usVertexCount < 0x40;
            void* pvBuffer = pkStream->Allocate(uiSize);
            if (pvData)
                FUN_00ec44d0(pvBuffer, pvData, uiSize);
            pkStream->SetBuffer(pvBuffer, 0);
            pvData = pvBuffer;
        }

        pkStream->m_uiSize = uiSize;
        pkStream->m_pResource = pvData;
    }

    m_kStreams.SetAtGrow(uiIndex, pkStream);
    pkStream->m_bCopied = bCopy;
    return true;
}




inline bool ScreenColorDiffers(const NiColorA& color, const NiColorA& other)
{
    return !(color.r == other.r && color.g == other.g && color.b == other.b && color.a == other.a);
}


// Returns true when IsSameAs succeeds and the vertex counts, vertex values, optional texture and color values, and seven property pointers match.
// @fnv 0x00a906e0
bool __fastcall IsScreenPolygonEqual(NiScreenPolygon* self, void*, NiObject* pObject)
{
    if (!self->NiObject::IsSameAs(pObject))
        return false;

    NiScreenPolygon* pPolygon = (NiScreenPolygon*)pObject;

    if (ScreenPolygonMember<unsigned short>(self->unk0C) != ScreenPolygonMember<unsigned short>(pPolygon->unk0C))
        return false;

    unsigned short i;
    for (i = 0; i < ScreenPolygonMember<unsigned short>(self->unk0C); i++)
    {
        if (ScreenPolygonMember<NiPoint3*>(self->unk10)[i] != ScreenPolygonMember<NiPoint3*>(pPolygon->unk10)[i])
            return false;
    }

    if ((ScreenPolygonMember<NiPoint2*>(self->unk14) && !ScreenPolygonMember<NiPoint2*>(pPolygon->unk14)) || (!ScreenPolygonMember<NiPoint2*>(self->unk14) && ScreenPolygonMember<NiPoint2*>(pPolygon->unk14)))
    {
        return false;
    }

    if (ScreenPolygonMember<NiPoint2*>(self->unk14))
    {
        for (i = 0; i < ScreenPolygonMember<unsigned short>(self->unk0C); i++)
        {
            if (!(ScreenPolygonMember<NiPoint2*>(self->unk14)[i] == ScreenPolygonMember<NiPoint2*>(pPolygon->unk14)[i]))
                return false;
        }
    }

    if ((ScreenPolygonMember<NiColorA*>(self->unk18) && !ScreenPolygonMember<NiColorA*>(pPolygon->unk18)) || (!ScreenPolygonMember<NiColorA*>(self->unk18) && ScreenPolygonMember<NiColorA*>(pPolygon->unk18)))
    {
        return false;
    }

    if (ScreenPolygonMember<NiColorA*>(self->unk18))
    {
        for (i = 0; i < ScreenPolygonMember<unsigned short>(self->unk0C); i++)
        {
            if (ScreenColorDiffers(ScreenPolygonMember<NiColorA*>(self->unk18)[i], ScreenPolygonMember<NiColorA*>(pPolygon->unk18)[i]))
                return false;
        }
    }

    for (i = 0; i < 7; i++)
    {
        if (reinterpret_cast<NiPropertyState*>(self->unk08)->m_aspProps[i] != reinterpret_cast<NiPropertyState*>(pPolygon->unk08)->m_aspProps[i])
            return false;
    }

    return true;
}

void ReleaseObjectArray(void*) throw();

template <class T>
inline NiScreenSpaceCamera::Array<T>::~Array() throw()
{
    ReleaseObjectArray(m_pData);
}

template <class T>
inline NiScreenSpaceCamera::PrimitiveArray<T>::~PrimitiveArray() throw()
{}

// Destroys the object by clearing elements in m_kObjectPointers and m_kFloatValues, then calling FUN_00a2e620 on both arrays.
// @fnv 0x00a915d0
NiScreenSpaceCamera::~NiScreenSpaceCamera()
{
    unsigned int i = 0;
    if (i < m_kObjectPointers.m_usElementCount)
    {
        unsigned int tmp = 0;
        do
        {
            ScreenCameraArrayA(this).SetAt(i, *reinterpret_cast<const ScreenPolygonPtr*>(&tmp));
            ++i;
        } while (i < m_kObjectPointers.m_usElementCount);
    }
    ScreenCameraArrayA(this).RemoveAll();
    unsigned int j = 0;
    if (j < m_kFloatValues.m_usElementCount)
    {
        unsigned int tmp = 0;
        do
        {
            ScreenCameraArrayB(this).SetAt(j, *reinterpret_cast<const ScreenGeometryPtr*>(&tmp));
            ++j;
        } while (j < m_kFloatValues.m_usElementCount);
    }
    ScreenCameraArrayB(this).RemoveAll();
}

inline unsigned int Version91950(NiStream& s)
{
    return *(unsigned int*)((char*)&s + 0xd8);
}
inline NiBinaryStream* Input91950(NiStream& s)
{
    return *(NiBinaryStream**)((char*)&s + 0x24c);
}
template <class T> inline void Read91950(NiBinaryStream* s, T* p, unsigned int n)
{
    unsigned int size = sizeof(T);
    unsigned int count = n * size;
    s->BinaryRead(p, count, &size, 1);
}
template <class T> inline void Load91950(NiStream& s, T& p)
{
    Read91950(Input91950(s), &p, 1);
}

struct Element91950;
template <> void NiTArray<Element91950*, NiTMallocInterface<Element91950*> >::SetAt(unsigned int, Element91950* const&);


// This loader uses the game's out-of-line color constructor; the polygon loader
// above uses its inline zero initialization.
template <class T> struct UninitializedArrayElement
{
    unsigned char storage[sizeof(T)];
    static void* operator new[](size_t size)
    {
        return _g_memoryManager.Allocate(size);
    }
};
NiColorA* __fastcall ConstructScreenColor(NiColorA*) throw();
void __stdcall ConstructScreenArray(void*, unsigned int, int, void* (__thiscall*)(void*)) throw();

struct Element91950
{
    int m00;
    unsigned short m04, m06;
    NiPoint2* m08;
    NiColorA* m0c;
    NiPoint2* m10;
};
struct Pool91950
{
    Element91950** m00;
    unsigned int m04, m08, m0c, m10;
    void AppendItems(unsigned int);
    Element91950* Get()
    {
        if (!m08)
        {
            AppendItems(m10);
            m10 *= 2;
        }
        Element91950* p = m00[0];
        m00[0] = m00[--m08];
        return p;
    }
};

void* __cdecl _NiMalloc_00aa1070(unsigned int);
// Loads the geometry base data, screen flag, legacy fields, and vertex/color/texture elements.
// @fnv 0x00a91950
void __fastcall LoadScreenGeometryData(NiScreenGeometryData* self, void*, NiStream& stream)
{
    if (Version91950(stream) < 0x0a00010f)
        self->NiGeometryData::LoadBinary(stream);
    else
        self->NiTriShapeData::LoadBinary(stream);
    unsigned char flag;
    Load91950(stream, flag);
    ScreenGeometryField<bool>(self, 0x58) = flag != 0;
    {
        unsigned short legacyCount;
        if (Version91950(stream) < 0x0a00010f)
        {
            Load91950(stream, legacyCount);
            self->m_usVertices = legacyCount;
            Load91950(stream, self->m_usTriangles);
        }
        if (Version91950(stream) < 0x0a00010f)
        {
            Load91950(stream, legacyCount);
            self->m_uiTriListLength = legacyCount;
            if (legacyCount > 0)
            {
                self->m_pusTriList = (unsigned short*)_NiMalloc_00aa1070(legacyCount * sizeof(unsigned short));
                Read91950(Input91950(stream), self->m_pusTriList, legacyCount);
            }
        }
    }
    unsigned int count = 0;
    Load91950(stream, count);
    if (count)
    {
        ScreenGeometryField<NiTPrimitiveArray<Element91950*>>(self, 0x60).SetSize(count);
        for (unsigned int i = 0; i < count; ++i)
        {
            unsigned short vertices = 0;
            Load91950(stream, vertices);
            if (vertices)
            {
                NiPoint2* points = 0;
                NiColorA* colors = 0;
                NiPoint2* textures = 0;
                unsigned short sets = 0;
                unsigned char hasPoints;
                Load91950(stream, hasPoints);
                if (hasPoints)
                {
                    points = new NiPoint2[vertices];
                    Read91950(Input91950(stream), points, vertices);
                }
                unsigned char hasColors;
                Load91950(stream, hasColors);
                if (hasColors)
                {
                    unsigned int colorCount = vertices;
                    NiColorA* pColors = reinterpret_cast<NiColorA*>(new UninitializedArrayElement<NiColorA>[colorCount]);
                    if (pColors)
                        ConstructScreenArray(pColors, sizeof(NiColorA), colorCount,
                            reinterpret_cast<void* (__thiscall*)(void*)>(ConstructScreenColor));
                    if (pColors)
                        colors = pColors;
                    else
                        colors = 0;
                    Read91950(Input91950(stream), colors, vertices);
                }
                Load91950(stream, sets);
                if (sets)
                {
                    unsigned int total = sets * vertices;
                    textures = new NiPoint2[total];
                    Read91950(Input91950(stream), textures, total);
                }
                Element91950* element = ((Pool91950*)DAT_011f5e50)->Get();
                g_011f6238.Deallocate(element->m08);
                element->m04 = vertices;
                element->m08 = points;
                g_011f6238.Deallocate(element->m0c);
                element->m0c = colors;
                g_011f6238.Deallocate(element->m10);
                element->m10 = textures;
                element->m06 = sets;
                ScreenGeometryField<NiTPrimitiveArray<Element91950*>>(self, 0x60).SetAt(i, element);
            }
        }
    }
}

template <> __declspec(noinline) void NiTArray<Element91950*, NiTMallocInterface<Element91950*> >::SetAt(unsigned int i, Element91950* const& p)
{
    if (i >= this->m_usSize)
    {
        this->m_usSize = (unsigned short)(i + 1);
        if (p)
            ++this->m_usESize;
    }
    else if (p)
    {
        if (!this->m_pBase[i])
            ++this->m_usESize;
    }
    else if (this->m_pBase[i])
    {
        --this->m_usESize;
    }
    this->m_pBase[i] = p;
}

extern unsigned int g_screenNullInitialized;
extern NiRefObject* g_screenNull;
void __cdecl DestroyScreenNull();



// Sets the element at idx, updating m_usESize and reference counts on the old and new NiRefObject pointers.
// @fnv 0x00a90980
template <> __declspec(noinline) void ScreenGeometryArray::SetAt(unsigned int aiIndex, const ScreenGeometryPtr& element) throw()
{
    NiScreenGeometry* const* appElement = &element.m_pObject;
    if ((g_screenNullInitialized & 1) == 0)
    {
        g_screenNullInitialized |= 1;
        g_screenNull = 0;
        FUN_00ec658f(DestroyScreenNull);
    }
    if (aiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(aiIndex + 1);
        if (*appElement != g_screenNull)
            m_usESize++;
    }
    else
    {
        NiRefObject* pNull = g_screenNull;
        if (*appElement != pNull)
        {
            if (m_pBase[aiIndex].m_pObject == pNull)
                m_usESize++;
        }
        else
        {
            if (m_pBase[aiIndex].m_pObject != pNull)
                m_usESize--;
        }
    }
    NiScreenGeometry** slot = &m_pBase[aiIndex].m_pObject;
    NiRefObject* old = *slot;
    if (old != *appElement)
    {
        if (old)
        {
            if (!InterlockedDecrement((volatile long*)&old->m_uiRefCount))
                old->DeleteThis();
        }
        NiScreenGeometry* pNew = *appElement;
        *slot = pNew;
        if (pNew)
            InterlockedIncrement((volatile long*)&pNew->m_uiRefCount);
    }
}

template <class T> inline NiPointer<T>::NiPointer() throw() : m_pObject(0) {}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) throw() : m_pObject(pkNew)
{
    if (m_pObject) m_pObject->AcquireReference();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer& kSrc) throw() : m_pObject(kSrc.m_pObject)
{
    if (m_pObject) m_pObject->AcquireReference();
}
template <class T> inline NiPointer<T>::~NiPointer() throw()
{
    if (m_pObject) m_pObject->DecRef();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& kSrc) throw()
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject) m_pObject->DecRef();
        m_pObject = kSrc.m_pObject;
        if (m_pObject) m_pObject->AcquireReference();
    }
    return *this;
}
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }

// Gamebryo NiTArray.inl bodies the original inlines (GetAt is defined above); SetAt stays out of line, nothrow
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetSize() const
{
    return this->m_usSize;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetGrowBy() const
{
    return this->m_usGrowBy;
}
template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::SetGrowBy(unsigned int uiStep)
{
    this->m_usGrowBy = (unsigned short)uiStep;
}
template <class T, class TAlloc>
__declspec(noinline) void NiTArray<T, TAlloc>::SetAt(unsigned int uiSlot, const T& kItem) throw()
{
    if (uiSlot >= this->m_usSize)
    {
        this->m_usSize = (unsigned short)(uiSlot + 1);
        if (kItem != 0)
            this->m_usESize++;
    }
    else if (kItem != 0)
    {
        if (this->m_pBase[uiSlot] == 0)
            this->m_usESize++;
    }
    else if (this->m_pBase[uiSlot] != 0)
    {
        this->m_usESize--;
    }
    this->m_pBase[uiSlot] = kItem;
}
namespace fnv_00a916a0 {

typedef ScreenPolygonPtr NiScreenPolygonPtr;
typedef ScreenGeometryPtr NiScreenGeometryPtr;

struct CameraCopyCalls
{
    void CopyBaseMembers(NiScreenSpaceCamera* pkDest, CloningProcess& kCloning);
};

inline NiTObjectArray<NiScreenPolygonPtr>& ScreenCameraSequencesA(NiScreenSpaceCamera* self)
{
    return reinterpret_cast<NiTObjectArray<NiScreenPolygonPtr>&>(self->m_kObjectPointers);
}
inline NiTObjectArray<NiScreenGeometryPtr>& ScreenCameraSequencesB(NiScreenSpaceCamera* self)
{
    return reinterpret_cast<NiTObjectArray<NiScreenGeometryPtr>&>(self->m_kFloatValues);
}

// Copies the base camera members and clones both shared camera arrays into pkDest.
// @fnv 0x00a916a0
void __fastcall CopyScreenSpaceCameraMembers(NiScreenSpaceCamera* self, void*, NiScreenSpaceCamera* pkDest, CloningProcess& kCloning) throw()
{
    reinterpret_cast<CameraCopyCalls*>(self)->CopyBaseMembers(pkDest, kCloning);

    ScreenCameraSequencesA(pkDest).SetSize(ScreenCameraSequencesA(self).GetSize());
    ScreenCameraSequencesA(pkDest).SetGrowBy(ScreenCameraSequencesA(self).GetGrowBy());
    for (unsigned int ui = 0; ui < ScreenCameraSequencesA(self).GetSize(); ui++)
    {
        NiScreenPolygonPtr pListSequence = ScreenCameraSequencesA(self).GetAt(ui);
        if (pListSequence)
            ScreenCameraSequencesA(pkDest).SetAt(ui, (NiScreenPolygon*)pListSequence->MakeClone(kCloning));
        else
            ScreenCameraSequencesA(pkDest).SetAt(ui, 0);
    }

    ScreenCameraSequencesB(pkDest).SetSize(ScreenCameraSequencesB(self).GetSize());
    ScreenCameraSequencesB(pkDest).SetGrowBy(ScreenCameraSequencesB(self).GetGrowBy());
    for (unsigned int ui = 0; ui < ScreenCameraSequencesB(self).GetSize(); ui++)
    {
        NiScreenGeometryPtr pListSequence = ScreenCameraSequencesB(self).GetAt(ui);
        if (pListSequence)
            ScreenCameraSequencesB(pkDest).SetAt(ui, (NiScreenGeometry*)pListSequence->MakeClone(kCloning));
        else
            ScreenCameraSequencesB(pkDest).SetAt(ui, 0);
    }
}
}  // namespace fnv_00a916a0
