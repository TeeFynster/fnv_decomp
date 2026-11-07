
// src/gamebryo2.2/corelibs/niparticle/nipsysemitterdeclinationctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterdeclinationctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiPSysEmitterDeclinationCtlr
{
    void GetTargetValueAtOffset20(float& fValue);
};

// @fnv 0x00c2a1b0
// src: GUESS 0x00c2a1b0 (confidence: medium)
void __thiscall NiPSysEmitterDeclinationCtlr::GetTargetValueAtOffset20(float& fValue)
{
    void* p = *(void**)((char*)this + 0x3C);
    fValue = *(float*)((char*)p + 0x20);
}

extern "C" void* g_01202758;

// @fnv 0x00c2b9a0
// src: COMMUNITY 0x00c2b9a0
void* __cdecl NiPSysEmitterDeclinationCtlr_GetRTTI()
{
    return &g_01202758;
}

namespace fnv_00c2b9b0 {
struct NiPSysEmitterDeclinationCtlr
{
    void SetTargetValueAtOffset20(float fValue);
};

// @fnv 0x00c2b9b0
// src: GUESS 0x00c2b9b0 (confidence: medium)
void NiPSysEmitterDeclinationCtlr::SetTargetValueAtOffset20(float fValue)
{
    void* pMember = *(void**)((char*)this + 0x3c);
    *(float*)((char*)pMember + 0x20) = fValue;
}
}  // namespace fnv_00c2b9b0

struct NiObject;

__declspec(nothrow) NiObject* __cdecl NiViewerStrings_NiGetViewerString_Title(void* p);

struct ObjArray
{
    void* m_vtbl;
    NiObject** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    __declspec(nothrow) void FUN_0096ad30(unsigned int uiMaxSize);
    __declspec(nothrow) void FUN_0096ae90(unsigned int uiIndex, NiObject* const& element);
    void Add(NiObject* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            FUN_0096ad30(uiIndex + m_usGrowBy);
        FUN_0096ae90(uiIndex, element);
    }
};

struct FUN_00c2ba10_class
{
    __declspec(nothrow) void NiPSysModifierFloatCtlr_GetViewerStrings(ObjArray* arr);
    void NiPSysEmitterDeclinationCtlr_GetViewerStrings(ObjArray* arr);
};

// @fnv 0x00c2ba10
// src: XBOX_PDB 0x00c2ba10
void FUN_00c2ba10_class::NiPSysEmitterDeclinationCtlr_GetViewerStrings(ObjArray* pArray)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(pArray);
    NiObject* obj = NiViewerStrings_NiGetViewerString_Title(g_01202758);
    pArray->Add(obj);
}

struct S_00c2b9c0_Base
{
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
    S_00c2b9c0_Base() throw();
    virtual void vf0() throw();
    static void* operator new(unsigned int n) throw();
};
struct S_00c2b9c0_Obj : S_00c2b9c0_Base
{
    S_00c2b9c0_Obj() throw()
    {}
    virtual void vf0() throw();
};
struct FUN_00c2b9c0_class
{
    void FUN_00c32de0(S_00c2b9c0_Base* obj, unsigned int a) throw();
    S_00c2b9c0_Base* CreateObject(unsigned int a) throw();
};
// Allocates a new S_00c2b9c0_Obj, initializes it via FUN_00c32de0 with a, and returns it as S_00c2b9c0_Base.
// @fnv 0x00c2b9c0
S_00c2b9c0_Base* FUN_00c2b9c0_class::CreateObject(unsigned int a) throw()
{
    S_00c2b9c0_Base* p = new S_00c2b9c0_Obj;
    FUN_00c32de0(p, a);
    return p;
}
