
// src/staging/blk_00ee0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern "C" void __cdecl _Call_a5d3a0();
extern int DAT_011011ec;

struct FUN_00ee88b0
{
    int m_vftable;
    FUN_00ee88b0();
};

// @fnv 0x00ee88b0
FUN_00ee88b0::FUN_00ee88b0()
{
    _Call_a5d3a0();
    m_vftable = (int)&DAT_011011ec;
}

extern const char* _EmptyFS;
struct FUN_00ee8a10
{
    const char* m_pString;
    unsigned int m_uiCharacterCount;
    unsigned int m_uiMaxLength;
    unsigned int m_uiValue1;
    unsigned int m_uiRefCount;
    FUN_00ee8a10(const FUN_00ee8a10& src);
};

// Copy constructor: shares src's string buffer with interlocked refcount increment/decrement and copies the remaining fields.
// @fnv 0x00ee8a10
FUN_00ee8a10::FUN_00ee8a10(const FUN_00ee8a10& src)
{
    const char* newStr = src.m_pString;
    if (m_pString != newStr)
    {
        if (newStr != _EmptyFS)
            InterlockedIncrement((volatile long*)(newStr - 8));
        if (m_pString != _EmptyFS)
            InterlockedDecrement((volatile long*)(m_pString - 8));
        m_pString = newStr;
    }
    m_uiCharacterCount = src.m_uiCharacterCount;
    m_uiMaxLength = src.m_uiMaxLength;
    m_uiValue1 = src.m_uiValue1;
    m_uiRefCount = src.m_uiRefCount;
}

namespace fnv_00eea710 {
extern "C" void* _EmptyFS;

struct FUN_00eea710_class
{
    void* m_vftable;
    void* m_field_04;
    void* m_field_08;
    void* m_field_0c;
    void* m_field_10;
    void* m_field_14;
    void* m_field_18;
    void AssignRefCounted(void** p);
};

// Assigns the reference-counted pointer from p to m_field_18, incrementing the new target's count and decrementing the old one when they differ.
// @fnv 0x00eea710
void FUN_00eea710_class::AssignRefCounted(void** apSource)
{
    void* src = *apSource;
    if (m_field_18 != src)
    {
        if (src != _EmptyFS)
            InterlockedIncrement((volatile long*)((char*)src - 8));
        if (m_field_18 != _EmptyFS)
            InterlockedDecrement((volatile long*)((char*)m_field_18 - 8));
        m_field_18 = src;
    }
}
}  // namespace fnv_00eea710

struct FUN_00ee89f0
{
    const char* m_pString;
    unsigned int m_uiCharacterCount;
    unsigned int m_uiMaxLength;
    unsigned int m_uiValue1;
    unsigned int m_uiRefCount;
    FUN_00ee89f0();
};

// @fnv 0x00ee89f0
FUN_00ee89f0::FUN_00ee89f0()
{
    m_pString = _EmptyFS;
    m_uiCharacterCount = 0;
    m_uiMaxLength = 0;
    m_uiValue1 = 0;
    m_uiRefCount = 0;
}

struct FUN_00eea650_stand_in
{
    void* m_vftable;
    unsigned int m_uiUnknown1;
    unsigned int m_uiUnknown2;
    const char* m_pString;

    void AssignReferencedString_00eea650(const FUN_00ee8a10& src);
};

// Copies the source string pointer, incrementing its refcount and decrementing the old string's refcount when they differ.
// @fnv 0x00eea650
// src: GUESS 0x00eea650 (confidence: high)
void FUN_00eea650_stand_in::AssignReferencedString_00eea650(const FUN_00ee8a10& aSource)
{
    const char* pcSourceString = aSource.m_pString;
    if (m_pString != pcSourceString)
    {
        if (pcSourceString != _EmptyFS)
            InterlockedIncrement(reinterpret_cast<volatile long*>(const_cast<char*>(pcSourceString) - 8));

        if (m_pString != _EmptyFS)
            InterlockedDecrement(reinterpret_cast<volatile long*>(const_cast<char*>(m_pString) - 8));

        m_pString = pcSourceString;
    }
}

__declspec(dllimport) int __stdcall gethostname(char* name, int namelen);

// @fnv 0x00ee6d8c
// src: COMMUNITY 0x00ee6d8c
int __stdcall gethostname_0(char* name, int namelen)
{
    return gethostname(name, namelen);
}

// FUN_00ee6d92: 6-byte 'jmp [IAT]' forwarder to WSOCK32 ordinal 13 (listen, stdcall, 2 args).
extern "C" __declspec(dllimport) int __stdcall listen(unsigned int s, int backlog);

// @fnv 0x00ee6d92
// src: COMMUNITY 0x00ee6d92
int __stdcall listen_0(unsigned int s, int backlog)
{
    return listen(s, backlog);
}

// FUN_00ee6d98: 6-byte 'jmp [IAT]' forwarder to WSOCK32 ordinal 2 (bind, stdcall, 3 args).
extern "C" __declspec(dllimport) int __stdcall bind(unsigned int s, const void* name, int namelen);

// @fnv 0x00ee6d98
// src: COMMUNITY 0x00ee6d98
int __stdcall bind_0(unsigned int s, const void* name, int namelen)
{
    return bind(s, name, namelen);
}

extern "C"
{
    __declspec(dllimport) char* __stdcall inet_ntoa(unsigned int addr);
}

// @fnv 0x00ee6da4
// src: COMMUNITY 0x00ee6da4
char* __stdcall inet_ntoa_0(unsigned int addr)
{
    return inet_ntoa(addr);
}

// FUN_00ee6daa — import forwarding stub: a tail jump through the ws2_32
// import table slot to ntohs. The wrapper's own argument is already in the
// callee's argument position, so with matching __stdcall cleanup the /O2
// tail call compiles to a single `jmp dword ptr [__imp__ntohs@4]` (6 bytes).
//
// Target: size 6, /MT /O2 /GS /EHsc /Gy.

__declspec(dllimport) unsigned short __stdcall ntohs(unsigned short netshort);

// @fnv 0x00ee6daa
// src: COMMUNITY 0x00ee6daa
unsigned short __stdcall ntohs_0(unsigned short netshort)
{
    return ntohs(netshort);
}

// FUN_00ee6db0: 6-byte 'jmp [IAT]' forwarder to WSOCK32 ordinal 1 (accept, stdcall, 3 args).
extern "C" __declspec(dllimport) unsigned int __stdcall accept(unsigned int s, void* addr, int* addrlen);

// @fnv 0x00ee6db0
// src: COMMUNITY 0x00ee6db0
int __stdcall accept_0(unsigned int s, void* addr, int* addrlen)
{
    return accept(s, addr, addrlen);
}

extern "C" int __cdecl __WSAFDIsSet(unsigned long, void*);

extern void(__cdecl* const FUN_00DF3880)();

// @fnv 0x00ee6db6
// src: COMMUNITY 0x00ee6db6
void __cdecl _WSAFDIsSet_0()
{

    FUN_00DF3880();
}

extern "C" void(__cdecl* DAT_00fdf37c)();

// @fnv 0x00ee6dbc
// src: COMMUNITY 0x00ee6dbc
void __cdecl select_0()
{
    DAT_00fdf37c();
}

extern "C" __declspec(dllimport) void __cdecl ImportedFunction();

// @fnv 0x00ee6dc2
// src: COMMUNITY 0x00ee6dc2
void __cdecl NiRenderedTexture_SaveToFile()
{
    ImportedFunction();
}

struct D3DXPLANE;
struct D3DXMATRIX;

extern "C" __declspec(dllimport) D3DXPLANE* __stdcall D3DXPlaneTransform(D3DXPLANE* output, const D3DXPLANE* plane,
                                                                         const D3DXMATRIX* matrix);

// @fnv 0x00ee6dc8
// src: COMMUNITY 0x00ee6dc8
D3DXPLANE* __stdcall D3DXPlaneTransform_00ee6dc8(D3DXPLANE* output, const D3DXPLANE* plane, const D3DXMATRIX* matrix)
{
    return D3DXPlaneTransform(output, plane, matrix);
}

extern "C" __declspec(dllimport) void* __stdcall D3DXPlaneNormalize(void* pout, const void* pp);

// @fnv 0x00ee6dce
// src: COMMUNITY 0x00ee6dce
void* __stdcall D3DXPlaneNormalize_00ee6dce(void* pout, const void* pp)
{
    return D3DXPlaneNormalize(pout, pp);
}

typedef void(__cdecl* PFN_D3DXMatrixInverse)(void);
extern "C" PFN_D3DXMatrixInverse __imp__D3DXMatrixInverse;

// @fnv 0x00ee6dda
// src: COMMUNITY 0x00ee6dda
void __cdecl D3DXMatrixInverse_00ee6dda()
{
    __imp__D3DXMatrixInverse();
}

// FUN_00ee6de0: 6-byte 'jmp [IAT]' forwarder to d3dx9_38 D3DXMatrixMultiply (stdcall, 3 args).
extern "C" __declspec(dllimport) void* __stdcall D3DXMatrixMultiply(void* pOut, const void* pM1, const void* pM2);

// @fnv 0x00ee6de0
// src: COMMUNITY 0x00ee6de0
void* __stdcall D3DXMatrixMultiply_00ee6de0(void* pOut, const void* pM1, const void* pM2)
{
    return D3DXMatrixMultiply(pOut, pM1, pM2);
}

// FUN_00ee6de6: 6-byte jmp [IAT] stub forwarding to stdcall d3dx9_38 D3DXLoadSurfaceFromSurface (8 stack args).
extern "C" __declspec(dllimport) int __stdcall D3DXLoadSurfaceFromSurface(void* pDestSurface, const void* pDestPalette,
                                                                          const void* pDestRect, void* pSrcSurface,
                                                                          const void* pSrcPalette, const void* pSrcRect,
                                                                          unsigned int Filter, unsigned int ColorKey);

// @fnv 0x00ee6de6
// src: COMMUNITY 0x00ee6de6
int __stdcall D3DXLoadSurfaceFromSurface_00ee6de6(void* pDestSurface, const void* pDestPalette, const void* pDestRect, void* pSrcSurface,
                           const void* pSrcPalette, const void* pSrcRect, unsigned int Filter, unsigned int ColorKey)
{
    return D3DXLoadSurfaceFromSurface(pDestSurface, pDestPalette, pDestRect, pSrcSurface, pSrcPalette, pSrcRect, Filter,
                                      ColorKey);
}

// FUN_00ee6dec: 6-byte jmp [IAT] stub forwarding to stdcall d3dx9_38 D3DXVec3Normalize.
extern "C" __declspec(dllimport) void* __stdcall D3DXVec3Normalize(void* pOut, const void* pV);

// @fnv 0x00ee6dec
// src: COMMUNITY 0x00ee6dec
void* __stdcall D3DXVec3Normalize_00ee6dec(void* pOut, const void* pV)
{
    return D3DXVec3Normalize(pOut, pV);
}

// Import thunk for D3DXVec3TransformNormal (d3dx9_38.dll).
// The linker emits such a thunk as a single indirect jump through the
// import address table entry of the imported routine, so the body is a
// tail jump to the imported address held in a global pointer.
typedef void(__cdecl* FNVImportEntry)(void);
extern FNVImportEntry g_D3DXVec3TransformNormal;

// @fnv 0x00ee6df2
// src: COMMUNITY 0x00ee6df2
void D3DXVec3TransformNormal_00ee6df2(void)
{
    g_D3DXVec3TransformNormal();
}

// FUN_00ee6df8: 6-byte jmp [IAT] stub forwarding to stdcall d3dx9_38 D3DXVec3TransformCoord.
extern "C" __declspec(dllimport) void* __stdcall D3DXVec3TransformCoord(void* pOut, const void* pV, const void* pM);

// @fnv 0x00ee6df8
// src: COMMUNITY 0x00ee6df8
void* __stdcall D3DXVec3TransformCoord_00ee6df8(void* pOut, const void* pV, const void* pM)
{
    return D3DXVec3TransformCoord(pOut, pV, pM);
}

struct D3DXMATRIX;

extern "C" __declspec(dllimport) D3DXMATRIX* __stdcall D3DXMatrixMultiplyTranspose(D3DXMATRIX* output,
                                                                                   const D3DXMATRIX* first,
                                                                                   const D3DXMATRIX* second);

// @fnv 0x00ee6dfe
// src: COMMUNITY 0x00ee6dfe
D3DXMATRIX* __stdcall D3DXMatrixMultiplyTranspose_00ee6dfe(D3DXMATRIX* output, const D3DXMATRIX* first, const D3DXMATRIX* second)
{
    return D3DXMatrixMultiplyTranspose(output, first, second);
}

// FUN_00ee6e04: 6-byte jmp [IAT] stub forwarding to stdcall d3dx9_38 D3DXMatrixRotationYawPitchRoll (4 args).
extern "C" __declspec(dllimport) void* __stdcall D3DXMatrixRotationYawPitchRoll(void* pOut, unsigned int Yaw,
                                                                                unsigned int Pitch, unsigned int Roll);

// @fnv 0x00ee6e04
// src: COMMUNITY 0x00ee6e04
void* __stdcall D3DXMatrixRotationYawPitchRoll_00ee6e04(void* pOut, unsigned int Yaw, unsigned int Pitch, unsigned int Roll)
{
    return D3DXMatrixRotationYawPitchRoll(pOut, Yaw, Pitch, Roll);
}

extern "C" __declspec(dllimport) long __stdcall DirectInput8Create(void* hinst, unsigned long dwVersion,
                                                                   const void* riidltf, void** ppvOut, void* punkOuter);

// @fnv 0x00ee7f10
// src: COMMUNITY 0x00ee7f10
long __stdcall DirectInput8Create_0(void* hinst, unsigned long dwVersion, const void* riidltf, void** ppvOut, void* punkOuter)
{
    return DirectInput8Create(hinst, dwVersion, riidltf, ppvOut, punkOuter);
}

// FUN_00ee81e0: forwards to DSOUND ordinal 11 (DirectSoundCreate8), tail-jumped through the IAT.
extern "C" __declspec(dllimport) long __stdcall DirectSoundCreate8(const void* pcGuidDevice, void** ppDS8,
                                                                   void* pUnkOuter);

// @fnv 0x00ee81e0
// src: COMMUNITY 0x00ee81e0
long __stdcall DirectSoundCreate8_00ee81e0(const void* pcGuidDevice, void** ppDS8, void* pUnkOuter)
{
    return DirectSoundCreate8(pcGuidDevice, ppDS8, pUnkOuter);
}

// FUN_00ee81e6: forwards to libvorbisfile ov_clear (1 arg, cdecl), tail-jumped through the IAT.
extern "C" __declspec(dllimport) int __cdecl ov_clear(void* vf);

// @fnv 0x00ee81e6
// src: COMMUNITY 0x00ee81e6
int __cdecl ov_clear_00ee81e6(void* vf)
{
    return ov_clear(vf);
}

// FUN_00ee81ec: forwards to libvorbisfile ov_pcm_total (2 args, cdecl, 64-bit return), tail-jumped through the IAT.
extern "C" __declspec(dllimport) __int64 __cdecl ov_pcm_total(void* vf, int i);

// @fnv 0x00ee81ec
// src: COMMUNITY 0x00ee81ec
__int64 __cdecl ov_pcm_total_00ee81ec(void* vf, int i)
{
    return ov_pcm_total(vf, i);
}

// FUN_00ee81f2: forwards to libvorbisfile ov_seekable (1 arg, cdecl), tail-jumped through the IAT.
extern "C" __declspec(dllimport) int __cdecl ov_seekable(void* vf);

// @fnv 0x00ee81f2
// src: COMMUNITY 0x00ee81f2
int __cdecl ov_seekable_00ee81f2(void* vf)
{
    return ov_seekable(vf);
}

// FUN_00ee81f8: forwards to libvorbisfile ov_info (2 args, tail-jumped through the IAT).
extern "C" __declspec(dllimport) void* __cdecl ov_info(void* vf, int link);

// @fnv 0x00ee81f8
// src: COMMUNITY 0x00ee81f8
void* __cdecl ov_info_00ee81f8(void* vf, int link)
{
    return ov_info(vf, link);
}

extern "C" void(__cdecl* const FUN_00fdf438)();

// @fnv 0x00ee81fe
// src: COMMUNITY 0x00ee81fe
__declspec(noreturn) void __cdecl ov_open_callbacks_00ee81fe()
{
    typedef void(__cdecl * noreturn_func_t)();
    noreturn_func_t func = (noreturn_func_t)FUN_00fdf438;
    func();
}

// FUN_00ee8204: 6-byte 'jmp [IAT]' forwarder to libvorbisfile ov_read (cdecl, 7 args).
extern "C" __declspec(dllimport) int __cdecl ov_read(void* vf, char* buffer, int length, int bigendianp, int word,
                                                     int sgned, int* bitstream);

// @fnv 0x00ee8204
// src: COMMUNITY 0x00ee8204
int __cdecl ov_read_00ee8204(void* vf, char* buffer, int length, int bigendianp, int word, int sgned, int* bitstream)
{
    return ov_read(vf, buffer, length, bigendianp, word, sgned, bitstream);
}

extern "C" void (*DAT_00fdf398)();

// @fnv 0x00ee820a
// src: XBOX_PDB 0x00ee820a
void __cdecl XInputManager_KillRumbles()
{
    DAT_00fdf398();
}

extern "C" __declspec(dllimport) void __stdcall RtlUnwind(void* TargetFrame, void* TargetIp, void* ExceptionRecord,
                                                          void* ReturnValue);

// @fnv 0x00ee8210
// src: COMMUNITY 0x00ee8210
void __stdcall RtlUnwind_0(void* TargetFrame, void* TargetIp, void* ExceptionRecord, void* ReturnValue)
{
    RtlUnwind(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

struct FUN_00ee88d0_base
{
    virtual ~FUN_00ee88d0_base();
};

struct FUN_00ee88d0_cls : FUN_00ee88d0_base
{
    virtual ~FUN_00ee88d0_cls();
};

// @fnv 0x00ee88d0
FUN_00ee88d0_cls::~FUN_00ee88d0_cls()
{}

class FUN_00eea550_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_20;

    void NiMaterialResource_SetSource(int value);
};

// @fnv 0x00eea550
// src: COMMUNITY 0x00eea550
void FUN_00eea550_cls::NiMaterialResource_SetSource(int value)
{
    m_20 = value;
}

struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    int value;
    void NiMaterialResource_SetExtraData(int value);
};
// @fnv 0x00eea560
// src: COMMUNITY 0x00eea560
void CpuObject::NiMaterialResource_SetExtraData(int value)
{
    this->value = value;
}

namespace fnv_00eea570 {
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    int value;
    void NiMaterialResource_SetObjectType(int value);
};
// @fnv 0x00eea570
// src: COMMUNITY 0x00eea570
void CpuObject::NiMaterialResource_SetObjectType(int value)
{
    this->value = value;
}
}  // namespace fnv_00eea570

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern const char* _EmptyFS;
extern volatile long DAT_011f4400;
extern unsigned int UNK_0101dce4;

struct FixedStringOwner
{
    void* m_vftable;
    unsigned int m_uiUnknown04;
    const char* m_firstString;
    const char* m_secondString;
    const char* m_thirdString;
    const char* m_fourthString;
    const char* m_fifthString;

    void ReleaseStrings();
};

// Decrements the reference count of each non-empty string member, resets the vftable, and decrements the global counter.
// @fnv 0x00eea5e0
void FixedStringOwner::ReleaseStrings()
{
    if (m_fifthString != _EmptyFS)
        InterlockedDecrement(reinterpret_cast<volatile long*>(const_cast<char*>(m_fifthString) - 8));
    if (m_fourthString != _EmptyFS)
        InterlockedDecrement(reinterpret_cast<volatile long*>(const_cast<char*>(m_fourthString) - 8));
    if (m_thirdString != _EmptyFS)
        InterlockedDecrement(reinterpret_cast<volatile long*>(const_cast<char*>(m_thirdString) - 8));
    if (m_secondString != _EmptyFS)
        InterlockedDecrement(reinterpret_cast<volatile long*>(const_cast<char*>(m_secondString) - 8));
    if (m_firstString != _EmptyFS)
        InterlockedDecrement(reinterpret_cast<volatile long*>(const_cast<char*>(m_firstString) - 8));

    m_vftable = &UNK_0101dce4;
    InterlockedDecrement(&DAT_011f4400);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern const char* _EmptyFS;

struct FixedStringHolder
{
    void* m_vftable;
    unsigned int m_uiUnknown1;
    unsigned int m_uiUnknown2;
    unsigned int m_uiUnknown3;
    const char* m_pString;

    void AssignReferencedString_00eea690(const char** source);
};

// Assigns the string from source to m_pString, incrementing the new string's refcount and decrementing the old one unless either is _EmptyFS.
// @fnv 0x00eea690
// src: GUESS 0x00eea690 (confidence: high)
void FixedStringHolder::AssignReferencedString_00eea690(const char** source)
{
    const char* newString = *source;
    if (m_pString != newString)
    {
        if (newString != _EmptyFS)
        {
            InterlockedIncrement(reinterpret_cast<volatile long*>(const_cast<char*>(newString) - 8));
        }
        if (m_pString != _EmptyFS)
        {
            InterlockedDecrement(reinterpret_cast<volatile long*>(const_cast<char*>(m_pString) - 8));
        }
        m_pString = newString;
    }
}

class FUN_00eea4f0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    int* NiMaterialResource_GetSemantic();
};

// @fnv 0x00eea4f0
// src: XBOX_PDB 0x00eea4f0
int* FUN_00eea4f0_cls::NiMaterialResource_GetSemantic()
{
    return &unk0C;
}

struct FUN_00eea500_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int* __thiscall NiMaterialResource_GetLabel();
};

// @fnv 0x00eea500
// src: XBOX_PDB 0x00eea500
int* FUN_00eea500_Holder::NiMaterialResource_GetLabel()
{
    return &unk10;
}

struct FnvCpu_FUN_00eea520_CpuObject
{
    char* NiMaterialResource_GetDefaultValue();
};
// @fnv 0x00eea520
// src: XBOX_PDB 0x00eea520
char* FnvCpu_FUN_00eea520_CpuObject::NiMaterialResource_GetDefaultValue()
{
    return reinterpret_cast<char*>(this) + 24;
}

extern volatile long DAT_011f4400;
extern const char* _EmptyFS;
struct FixedStringBase
{
    virtual void Release();
    unsigned int m_unknown04;
    FixedStringBase();
};
FixedStringBase::FixedStringBase() : m_unknown04(0)
{
    InterlockedIncrement(&DAT_011f4400);
}
struct StringValue
{
    const char* value;
    StringValue() : value(_EmptyFS)
    {}
};
struct MemberCount
{
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;
    unsigned int m_flags;
    MemberCount() : m_iElementCount(0), m_pRayCursor(0), m_flags(0)
    {}
};
struct FUN_00eea580 : FixedStringBase
{
    StringValue m_pHeadNode, m_iSecondInteger, m_third, m_fourth, m_fifth;
    unsigned int m_sState;
    MemberCount m_counts;
    FUN_00eea580();
    virtual void Release();
};
// @fnv 0x00eea580
FUN_00eea580::FUN_00eea580()
{
    m_sState = 1;
}

class ItemEE88
{
  public:
    unsigned short NiMaterialNodeLibrary_GetVersion();
};

class FUN_00ee8850_C
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ItemEE88** m_ppItems;
    int unk10;
    unsigned int m_uiNumItems;
    char unk18[0x8cc];
    unsigned short m_usValue0;
    unsigned short m_usValue2;

    unsigned int GetTotalValue(int iType);
};

// Returns a base value from m_usValue0 or m_usValue2 shifted left by 16, plus the sum of FUN_00eea4e0 over all m_ppItems.
// @fnv 0x00ee8850
unsigned int FUN_00ee8850_C::GetTotalValue(int iType)
{
    unsigned int uiResult = 0;
    switch (iType)
    {
    case 0:
        uiResult = m_usValue0 << 16;
        break;
    case 2:
        uiResult = m_usValue2 << 16;
        break;
    }
    for (unsigned int i = 0; i < m_uiNumItems; i++)
    {
        ItemEE88* pkItem = m_ppItems[i];
        if (pkItem)
            uiResult += pkItem->NiMaterialNodeLibrary_GetVersion();
    }
    return uiResult;
}

// @fnv 0x00eea4e0
// src: COMMUNITY 0x00eea4e0
unsigned short __fastcall NiMaterialNodeLibrary_GetVersion(char* self, int edx)
{
    return *reinterpret_cast<unsigned short*>(self + 0x18);
}

struct D3DXVECTOR4;
struct D3DXMATRIX;
extern "C" __declspec(dllimport) D3DXVECTOR4* __stdcall D3DXVec4Transform(D3DXVECTOR4* output, const D3DXVECTOR4* input,
                                                                          const D3DXMATRIX* matrix);

// @fnv 0x00ee6e34
// src: COMMUNITY 0x00ee6e34
D3DXVECTOR4* __stdcall D3DXVec4Transform_0(D3DXVECTOR4* output, const D3DXVECTOR4* input, const D3DXMATRIX* matrix)
{
    return D3DXVec4Transform(output, input, matrix);
}
