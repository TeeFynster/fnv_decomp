#include "../../../../include/NiUnionBV.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiD3DShaderProgram.h"
#include "../../../../include/NiGPUProgram.h"
#include "../../../../include/NiRefObject.h"

// src/gamebryo2.2/corelibs/nicollision/niunionbv_o2_noo1_nooy_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nicollision/niunionbv.cpp lists /MT /O1 /Oy /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// MSVC 2008 cl does not accept the .inl extension as a source file, so this identical unit is compiled as .cpp by the matcher; the .inl is the source of record.
//
//
// gamebryo2.2/corelibs/nicollision/niunionbv.inl
//
// Inline definitions for NiD3DShaderProgram: Nivid3D shader program
// wrappers over D3D9 GPU programs. A program object owns the compiled
// code block and the creator/device handles that produced it; the
// accessors below read out the stored descriptors.
//
// Standalone build: base chain sizes taken from the MSVC 2008 layout
// evidence - NiGPUProgram is 12 bytes and NiD3DShaderProgram is 44
// bytes, with m_uiProgramCodeSize at offset 20.
//
typedef unsigned int NiUInt32;
#include "../../../../include/NiMemObject.h"
class NiD3DShaderProgramCreator;
class Direct3DDeviceInterface;
class NiD3DRenderer;
class NiD3DRenderState;
struct P03MM
{
    void* Allocate(unsigned int);
};
typedef P03MM MemoryManager;
extern MemoryManager g_memoryManager;
NiUnionBV* __fastcall NiUnionBV_Clone(void* self);
// FUN_00e9ecc0 - 6-byte leaf stub of the retail binary.
//
// The original code is "mov eax, 4 ; ret": the function simply hands the
// constant 4 back to its caller.  A plain "return 4;" is folded by VC9 at the
// pack's /O1 into the shorter "push 4 ; pop eax ; ret" sequence, so the value
// is materialised from a relocated address expression instead.  That keeps
// the original six-byte "mov eax, <imm32> ; ret" shape byte for byte.
extern int g_fnv_00e9ecc0_value_anchor;
int bhkCharacterStateFlying_Update();

class A64330Obj
{
  public:
    int unk00;
    int** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, int* const& value);

    unsigned int NiTArray_void_cdecl_NiStream_NiObject_NiTMallocInterface_void_cdecl_NiStream_NiObject_AddFirstEmpty(int* const& value);
};

// @fnv 0x00a64330
// src: XBOX_PDB 0x00a64330
unsigned int A64330Obj::NiTArray_void_cdecl_NiStream_NiObject_NiTMallocInterface_void_cdecl_NiStream_NiObject_AddFirstEmpty(int* const& value)
{
    int* element = value;

    if (element == 0)
        return 0xffffffffu;

    unsigned short i;
    for (i = 0; i < m_usSize; ++i)
    {
        if (m_pBase[i] == 0)
        {
            m_pBase[i] = element;
            ++m_usESize;
            return i;
        }
    }

    unsigned int uiSize = m_usSize;
    if (uiSize >= m_usMaxSize)
        SetSize(uiSize + m_usGrowBy);

    SetAt(uiSize, value);
    return uiSize;
}

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

// @fnv 0x00e9efe0
// src: XBOX_PDB 0x00e9efe0
NiUnionBV* __cdecl NiUnionBV_CreateFromStream(unsigned int a1)
{
    NiUnionBV* p = new (g_memoryManager.Allocate(sizeof(NiUnionBV))) NiUnionBV;
    p->LoadBinary(*(NiStream*)a1);
    return p;
}

struct Items
{
    void NiTArray_void_cdecl_NiStream_NiObject_NiTMallocInterface_void_cdecl_NiStream_NiObject_AddFirstEmpty(unsigned int*);
};
struct UnionLoadBase
{
    void nullsub_3(void* stream);
};
unsigned int NiBoundingVolume_CreateFromStream(void*);
// @fnv 0x00e9f020
// This loading helper is not declared by the shared class.
// src: GAMEBRYO_SRC 0x00e9f020
void __fastcall NiUnionBV_LoadBinary(NiUnionBV* self, void*, char* stream)
{
    unsigned int num;
    ((UnionLoadBase*)self)->nullsub_3(stream);
    NiBinaryStream* in = *(NiBinaryStream**)(stream + 0x24c);
    {
        unsigned int sz = 4;
        *(unsigned int*)((char*)in + 0x04) +=
            (*(NiBinaryStream::NIBINARYSTREAM_READFN*)((char*)in + 0x08))(in, &num, 4, &sz, 1);
    }
    for (unsigned int i = 0; i < num; ++i)
    {
        unsigned int item = NiBoundingVolume_CreateFromStream(stream);
        if (item)
        {
            unsigned int max = self->m_kBoundingVolumes.m_usSize;
            for (unsigned int j = 0; j < max; ++j)
            {
                if (item == (unsigned int)self->m_kBoundingVolumes.m_pBase[j])
                    goto found;
            }
            ((Items*)&self->m_kBoundingVolumes)->NiTArray_void_cdecl_NiStream_NiObject_NiTMallocInterface_void_cdecl_NiStream_NiObject_AddFirstEmpty(&item);
        found:;
        }
    }
}

struct E9E8C0Item
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual bool IsDifferent(E9E8C0Item* pkOther);
};

inline E9E8C0Item*& GetComparisonItem(NiUnionBV* volume, unsigned int index)
{
    return ((E9E8C0Item**)volume->m_kBoundingVolumes.m_pBase)[index];
}

// The shared header has no bool comparison overload for this entry point.
// Keep its calling convention in a free helper, using the shared object layout.
// @fnv 0x00e9e8c0
// src: GUESS 0x00e9e8c0 (confidence: low)
bool __fastcall NiUnionBV_ProcessEntries_00e9e8c0(NiUnionBV* self, void*, NiUnionBV* pkOther)
{
    if (pkOther->F3() != 4)
        return false;
    if (self->m_kBoundingVolumes.m_usSize != pkOther->m_kBoundingVolumes.m_usSize)
        return false;
    for (unsigned int ui = 0; ui < self->m_kBoundingVolumes.m_usSize; ui++)
    {
        if (GetComparisonItem(self, ui)->IsDifferent(GetComparisonItem(pkOther, ui)))
            return false;
    }
    return true;
}

// @fnv 0x00e9e930
void NiUnionBV::v5(NiBoundingVolume* a1, void* a2)
{
    NiUnionBV* other = (NiUnionBV*)a1;
    for (unsigned int i = 0; i < m_kBoundingVolumes.m_usSize; i++)
    {
        NiBoundingVolume* obj = m_kBoundingVolumes.m_pBase[i];
        NiBoundingVolume* arg = other->m_kBoundingVolumes.m_pBase[i];
        obj->v5(arg, a2);
    }
}

// The shared header has no data fields or inline transfer bodies; use the verified x86 offsets.
inline unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
                                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesWritten =
        (*(NIBINARYSTREAM_WRITEFN*)((char*)this + 0x0c))(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *(unsigned int*)((char*)this + 0x04) += uiBytesWritten;
    return uiBytesWritten;
}

template <class T> __forceinline void SerializeValue(NiBinaryStream& kStream, const T& tValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&tValue, sizeof(T), &uiSize, 1);
}

// @fnv 0x00e9ed50
void NiUnionBV::SaveBinary(NiStream& kStream)
{
    NiBoundingVolume::SaveBinary(kStream);

    unsigned int ItemUpdateArray = m_kBoundingVolumes.m_usSize;
    SerializeValue(**(NiBinaryStream**)((char*)&kStream + 0x250), ItemUpdateArray);

    for (unsigned int i = 0; i < m_kBoundingVolumes.m_usSize; i++)
    {
        NiBoundingVolume* pkObj = m_kBoundingVolumes.m_pBase[i];
        if (pkObj)
            pkObj->SaveBinary(kStream);
    }
}

typedef unsigned int u32;
typedef unsigned short u16;

extern "C" unsigned int __cdecl strlen(const char* s);
void* __cdecl _NiMalloc_00aa1070(unsigned int size);
int __cdecl FUN_00a305b0(char* buf, unsigned int count, const char* fmt, ...);

// The shared array declares its storage and transfers; this unit supplies
// the inline add operation used by its viewer strings.
template <class T> inline u32 AddPrimitive(NiTPrimitiveArray<T>& array, T& element)
{
    u32 uiIndex = array.m_usSize;
    if (uiIndex >= array.m_usMaxSize)
        array.SetSize(uiIndex + array.m_usGrowBy);
    array.SetAt(uiIndex, element);
    return uiIndex;
}

inline NiBoundingVolume* GetBoundingVolume(const NiTPrimitiveArray<NiBoundingVolume*>& array, u32 index)
{
    return index < array.m_usSize ? array.m_pBase[index] : 0;
}

// @fnv 0x00e9f0b0
// src: GAMEBRYO_SRC 0x00e9f0b0
void NiUnionBV::AddViewerStrings_00e9f0b0(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings)
{
    u32 uiLen = strlen(pcPrefix) + 12;
    char* pcString = (char*)_NiMalloc_00aa1070(uiLen);
    FUN_00a305b0(pcString, uiLen, "%s = UNION_BV", pcPrefix);
    AddPrimitive(*pkStrings, pcString);

    for (u32 i = 0; i < m_kBoundingVolumes.m_usSize; i++)
    {
        char* pcChild = (char*)_NiMalloc_00aa1070(13);
        FUN_00a305b0(pcChild, 13, "   child %i", i);
        GetBoundingVolume(m_kBoundingVolumes, i)->AddViewerStrings(pcChild, pkStrings);
    }
}

// Constructors remain inline here so the original allocation and vtable
// initialization sequence is preserved with the shared class declarations.
inline NiBoundingVolume::NiBoundingVolume()
{}

template <class T, class A>
inline NiTArray<T, A>::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    m_usMaxSize = (unsigned short)uiMaxSize;
    m_usGrowBy = (unsigned short)uiGrowBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = (T*)_NiMalloc_00aa1070(sizeof(T) * m_usMaxSize);
    else
        m_pBase = 0;
}

template <class T>
inline NiTPrimitiveArray<T>::NiTPrimitiveArray(unsigned int uiMaxSize, unsigned int uiGrowBy) throw()
    : NiTArray<T, NiTMallocInterface<T> >(uiMaxSize, uiGrowBy)
{}

// @fnv 0x00e9edd0
NiUnionBV::NiUnionBV() throw() : m_kBoundingVolumes(2, 1), m_pkEntry(0)
{}
