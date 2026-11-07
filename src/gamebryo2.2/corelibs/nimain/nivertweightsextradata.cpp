#include "../../../../include/NiTArray.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiExtraData.h"

// src/gamebryo2.2/corelibs/nimain/nivertweightsextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nivertweightsextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


extern "C" char __stdcall FUN_00a7b3d0(NiObject*);

// @fnv 0x00a89b00
// src: XBOX_PDB 0x00a89b00
char __stdcall NiVertWeightsExtraData_IsEqual(NiObject* pObject)
{
    char b = FUN_00a7b3d0(pObject);
    return b != 0;
}

extern "C" void* g_011f5b78;

// @fnv 0x00a89b20
// src: COMMUNITY 0x00a89b20
void* __cdecl NiVertWeightsExtraData_GetRTTI()
{
    return &g_011f5b78;
}



extern void* DAT_0109ee9c;

// @fnv 0x00a89b80
void* __cdecl CreateNiExtraData()
{
    NiExtraData* p = (NiExtraData*)BSFadeNode::operator new(0xc);
    if (p)
    {
        p->FUN_00a7b2e0();
        *reinterpret_cast<void**>(p) = &DAT_0109ee9c;
    }
    else
    {
        p = 0;
    }
    return p;
}

struct NiVertWeightsExtraData : NiExtraData
{
    void* FUN_00a89bb0(unsigned int);
};
struct FUN_00a7b300_shell
{
    void DestroyFields_00a7b300();
};
void __cdecl _delete(void*, unsigned int);
// @fnv 0x00a89bb0
void* NiVertWeightsExtraData::FUN_00a89bb0(unsigned int flags)
{
    *(void**)this = (void*)&DAT_0109ee9c;
    ((FUN_00a7b300_shell*)this)->DestroyFields_00a7b300();
    if (flags & 1)
        _delete(this, 12);
    return this;
}

struct A89C70RTTI
{
    const char* m_pcName;
    const A89C70RTTI* m_pBaseRTTI;

    const char* GetName() const
    {
        return m_pcName;
    }
};

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

typedef NiTArray<char*, NiTMallocInterface<char*> > A89C70StringArray;

extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcText);
struct A89C70Base
{
    void GetViewerStrings(A89C70StringArray* pkStrings);
};

struct A89C70Object : A89C70Base
{
    static A89C70RTTI ms_kRTTI;

    void NiVertWeightsExtraData_GetViewerStrings(A89C70StringArray* pkStrings);
};

// Calls the base GetViewerStrings, then adds the RTTI name string to the string array.
// @fnv 0x00a89c70
// src: XBOX_PDB 0x00a89c70
void A89C70Object::NiVertWeightsExtraData_GetViewerStrings(A89C70StringArray* pkStrings)
{
    A89C70Base::GetViewerStrings(pkStrings);
    char* pcString = NiViewerStrings_NiGetViewerString_Title(ms_kRTTI.GetName());
    pkStrings->Add(pcString);
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);

struct FUN_00a89b30_cls
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    void CopyMembers_00a7b330(void* obj, unsigned int a1);
    void* NiVertWeightsExtraData_CreateClone(unsigned int a1);
};

// @fnv 0x00a89b30
// src: XBOX_PDB 0x00a89b30
void* FUN_00a89b30_cls::NiVertWeightsExtraData_CreateClone(unsigned int a1)
{
    FUN_00a89b30_cls* p = (FUN_00a89b30_cls*)Object_DispatchCommandFour(0xc);
    if (p != 0)
    {
        ((NiExtraData*)p)->FUN_00a7b2e0();
        p->m_vtbl = (void*)&DAT_0109ee9c;
    }
    else
    {
        p = 0;
    }
    this->CopyMembers_00a7b330(p, a1);
    return p;
}

struct S_00a89be0_Bin
{
    int unk0;
    unsigned int m_uiPos;
    unsigned int(__cdecl* m_pfnRead)(S_00a89be0_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* v, unsigned int bytes, unsigned int* sizes, unsigned int n)
    {
        return m_pfnRead(this, v, bytes, sizes, n);
    }
};

struct S_00a89be0_Stream
{
    char unk[0xd8];
    unsigned int m_uiFormatVersion;
    char unk2[0x24c - 0xdc];
    S_00a89be0_Bin* m_pBin;
};

void __stdcall FUN_00a7b4a0(S_00a89be0_Stream*);

static __forceinline void BinRead(S_00a89be0_Bin* b, void* v, unsigned int bytes, unsigned int n)
{
    unsigned int sz = 4;
    b->m_uiPos += b->Read(v, bytes, &sz, n);
}
static __forceinline void LoadU32(S_00a89be0_Stream* s, unsigned int* v, unsigned int n)
{
    BinRead(s->m_pBin, v, 4, n);
}

// @fnv 0x00a89be0
// src: XBOX_PDB 0x00a89be0
void __stdcall NiVertWeightsExtraData_LoadBinary(S_00a89be0_Stream* s)
{
    if (s->m_uiFormatVersion < 0x5000010)
    {
        FUN_00a7b4a0(s);
        unsigned int count;
        LoadU32(s, &count, 1);
        for (unsigned int i = 0; i < count; i++)
        {
            unsigned int dummy;
            LoadU32(s, &dummy, 1);
        }
    }
}
