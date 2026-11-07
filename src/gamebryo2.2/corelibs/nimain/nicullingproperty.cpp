#include "../../../../include/NiTArray.h"

// src/gamebryo2.2/corelibs/nimain/nicullingproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nicullingproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiCullingProperty.h"
#include "../../../../include/NiProperty.h"
#include "../../../../include/NiStream.h"

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f5d20;

// @fnv 0x00a8f520
// src: COMMUNITY 0x00a8f520
GlobalObjectO2_00a7b610* __cdecl NiCullingProperty_GetRTTI()
{
    return &g_011f5d20;
}

struct FUN_00a8fce0_shell
{
    void* __thiscall FUN_00a8fce0();
};
extern int DAT_011f5e40;

// Allocates a 0x14-byte object, runs its constructor, and stores the resulting pointer in DAT_011f5e40 (or 0 if allocation fails).
// @fnv 0x00a8fd80
// src: COMMUNITY 0x00a8fd80
void __cdecl NiSingleShaderMaterialLibrary__SDMInit()
{
    void* p = BSFadeNode::operator new(0x14);
    if (p)
    {
        FUN_00a8fce0_shell* object = reinterpret_cast<FUN_00a8fce0_shell*>(p);
        DAT_011f5e40 = (int)object->FUN_00a8fce0();
    }
    else
    {
        DAT_011f5e40 = 0;
    }
}

extern int DAT_0109f68c;
struct CloningProcess
{
    void* m_pCloneMap;
};
// Allocates a NiCullingProperty, initialises its vtable and flags, runs the cloning routine, then copies m_usFlags and returns it.
// @fnv 0x00a8f530
// src: XBOX_PDB 0x00a8f530
NiCullingProperty* NiCullingProperty::CreateClone_00a8f530(CloningProcess& kCloning)
{
    NiCullingProperty* p = static_cast<NiCullingProperty*>(BSFadeNode::operator new(0x1c));
    if (p)
    {
        p->NiProperty::NiProperty();
        p->m_usFlags &= 0xfffe;
        *(void**)p = &DAT_0109f68c;
    }
    else
        p = 0;
    NiProperty_CopyMembers(p, kCloning);
    p->m_usFlags = m_usFlags;
    return p;
}

// Calls NiProperty::LoadBinary then reads 2 bytes from the stream into m_usFlags, advancing the stream position.
// @fnv 0x00a8f650
// src: XBOX_PDB 0x00a8f650
void __thiscall NiCullingProperty::LoadBinary_00a8f650(NiStream& stream)
{
    NiProperty::LoadBinary(stream);
    // NiStream's shared definition keeps this field in opaque storage.
    NiBinaryStream* __restrict input = *(NiBinaryStream**)((char*)&stream + 0x24c);
    unsigned int size = 2;
    // The shared stream header does not yet expose the position and read callback.
    unsigned int& position = *(unsigned int*)((char*)input + 4);
    position += (*(NiBinaryStream::ReadFunction*)((char*)input + 8))(input, &m_usFlags, 2, &size, 1);
}

extern void* __cdecl Object_DispatchCommandFour(unsigned int);
extern "C" void __fastcall FUN_00a5c200(void*);
extern int DAT_0109f68c;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

__forceinline void DecCullingPropertyRef(NiCullingProperty* property)
{
    if (InterlockedDecrement((volatile long*)&property->m_uiRefCount) == 0)
        property->DeleteThis();
}

struct NiPointerProperty
{
    NiCullingProperty* pointer;
    __forceinline void operator=(NiCullingProperty* fresh)
    {
        if (pointer != fresh)
        {
            if (pointer)
                DecCullingPropertyRef(pointer);
            pointer = fresh;
            if (pointer)
                InterlockedIncrement((volatile long*)&pointer->m_uiRefCount);
        }
    }
};
struct GlobalObjectO2_00a7b610
{
    int unk00;
    int unk04;
    NiPointerProperty cullingProperty;
};

// Allocates a NiCullingProperty, initialises it via FUN_00a5c200, clears flag bit 0, sets its vtable, and assigns it to g_011f5d20.cullingProperty.
// @fnv 0x00a8f5b0
void __cdecl CreateCullingProperty()
{
    NiCullingProperty* allocated = static_cast<NiCullingProperty*>(Object_DispatchCommandFour(sizeof(NiCullingProperty)));
    NiCullingProperty* fresh;
    if (allocated)
    {
        FUN_00a5c200(allocated);
        allocated->m_usFlags &= 0xfffe;
        *(void**)allocated = &DAT_0109f68c;
        fresh = allocated;
    }
    else
    {
        fresh = 0;
    }
    g_011f5d20.cullingProperty = fresh;
}

extern NiCullingProperty* DAT_011f5d28;

// If the global ref-counted object exists, decrements its reference count, destroys it when the count reaches zero, and clears the global pointer.
// @fnv 0x00a8f620
// src: XBOX_PDB 0x00a8f620
void __cdecl NiCullingProperty__SDMShutdown()
{
    if (DAT_011f5d28 != 0)
    {
        NiCullingProperty* p = DAT_011f5d28;
        if (InterlockedDecrement((volatile long*)&DAT_011f5d28->m_uiRefCount) == 0)
        {
            p->DeleteThis();
        }
        DAT_011f5d28 = 0;
    }
}

void* __cdecl _NiMalloc_00aa1070(unsigned int bytes);

struct FUN_00a7b690
{
    virtual void baseVirtual();
    FUN_00a7b690();
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
};

struct FNV_A90A50_ArrayBase
{
    virtual void arrayVirtual();
    void* data;
    unsigned short length;
    unsigned short allocated;
    unsigned short size;
    unsigned short capacity;
    FNV_A90A50_ArrayBase()
    {
        length = 4;
        capacity = 4;
        allocated = 0;
        size = 0;
        data = _NiMalloc_00aa1070(16);
    }
};

struct FNV_A90A50_Array : FNV_A90A50_ArrayBase
{
    virtual void arrayVirtual();
    FNV_A90A50_Array()
    {}
};

struct FUN_00a90a50 : FUN_00a7b690
{
    unsigned char unk58;
    unsigned char unk59;
    unsigned short unk5a;
    unsigned int unk5c;
    FNV_A90A50_Array member60;
    virtual void baseVirtual();
    FUN_00a90a50();
};

// Constructor that zero-initialises unk58, unk59 and unk5c and default-constructs the member60 array.
// @fnv 0x00a90a50
FUN_00a90a50::FUN_00a90a50() : unk58(0), unk59(0), unk5c(0)
{}

template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    return SetAtGrow(m_usSize, element);
}

typedef NiTArray<char*, NiTMallocInterface<char*> > BA8F690StringArray;

extern const char* g_pcA8F690Name;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
char* __cdecl NiGetViewerString(const char* pcName, bool bValue);

// The shared headers lack the viewer-string overrides; forward the unused EDX
// argument so these file-local entry points retain the original thiscall code.
void __fastcall NiProperty_GetViewerStrings(NiProperty* property, void*, BA8F690StringArray* strings);

// Appends the class name and a "bCulled" string derived from bit 0 of m_usFlags to the viewer string array.
// @fnv 0x00a8f690
void __fastcall NiCullingProperty_GetViewerStrings(NiCullingProperty* property, void* unusedEDX, BA8F690StringArray* pkStrings)
{
    NiProperty_GetViewerStrings(property, unusedEDX, pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(g_pcA8F690Name));
    bool bCulled = ((unsigned char)property->m_usFlags & 1) != 0;
    pkStrings->Add(NiGetViewerString("bCulled", bCulled));
}

extern int DAT_0109f68c;
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// Allocates a NiProperty, clears the low bit of the 0x18 field, sets the vtable to DAT_0109f68c, and returns it.
// @fnv 0x00a8f580
NiProperty* __cdecl CreateProperty()
{
    NiCullingProperty* pProperty = (NiCullingProperty*)BSFadeNode::operator new(0x1c);
    if (pProperty)
    {
        ::new (pProperty) NiProperty();
        pProperty->m_usFlags &= 0xFFFE;
        *(void**)pProperty = (void*)&DAT_0109f68c;
        return pProperty;
    }
    return 0;
}
