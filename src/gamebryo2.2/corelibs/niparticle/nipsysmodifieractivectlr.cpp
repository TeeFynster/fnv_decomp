// gamebryo2.2/corelibs/niparticle/nipsysmodifieractivectlr.cpp: NiPSysAirFieldAirFrictionCtlr, StandIn, NiPSysModifierActiveCtlr (13 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiPSysAirFieldAirFrictionCtlr.h"
#include "../../../../include/NiPSysModifierBoolCtlr.h"
#include "../../../../include/StrArr.h"

// @fnv 0x00c32de0
void NiPSysAirFieldAirFrictionCtlr::CopyMemberData(NiPSysAirFieldAirFrictionCtlr* destination, CloningProcess& cloning)
{
    NiPSysModifierCtlr::CopyMemberData(destination, cloning);
}

void __fastcall NiPSysModifierCtlr_NiPSysModifierCtlr(void*);
extern int DAT_010c0d2c;

// @fnv 0x00c32b60
// src: EXE 0x00c32b60
void* __fastcall NiPSysModifierBoolCtlr_NiPSysModifierBoolCtlr(void* pThis)
{
    NiPSysModifierCtlr_NiPSysModifierCtlr(pThis);
    *(int**)pThis = &DAT_010c0d2c;
    return pThis;
}

void* __fastcall FUN_00a532d0(void* p, int, bool bValue);

// Reads a bool via virtual call at offset 0xf0, allocates a 0x18-byte BSFadeNode, and constructs it with that bool, returning null on allocation failure.
// @fnv 0x00c32b80
// src: XBOX_PDB 0x00c32b80
void* __fastcall NiPSysModifierBoolCtlr_CreatePoseInterpolator(void* pThis, int, unsigned short usUnused)
{
    bool bValue;
    (*(void(__thiscall**)(void*, bool*))(*(int*)pThis + 0xf0))(pThis, &bValue);
    void* p = BSFadeNode::operator new(0x18);
    if (p)
        return ((void*(__thiscall*)(void*, bool))FUN_00a532d0)(p, bValue);
    return 0;
}

// @fnv 0x00c32bc0
// src: GUESS 0x00c32bc0 (confidence: low)
bool __fastcall Object_InvokeVirtualMethod_00c32bc0(const void* pThis, int, void* pkInterpolator, unsigned short usIndex)
{
    return (*(bool(__thiscall**)(void*))(*(int*)pkInterpolator + 0xa4))(pkInterpolator);
}

struct FUN_00c29d50_shell
{
    void __thiscall NiPSysModifierActiveCtlr_GetTargetBoolValue(char* pOut);
};

// @fnv 0x00c29d50
// src: XBOX_PDB 0x00c29d50
void __thiscall FUN_00c29d50_shell::NiPSysModifierActiveCtlr_GetTargetBoolValue(char* pOut)
{
    *pOut = *(char*)(*(int*)((char*)this + 0x3c) + 0x14);
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_012026d0;

// @fnv 0x00c29d40
// src: COMMUNITY 0x00c29d40
GlobalObjectO2_00a7b610* __cdecl NiPSysModifierActiveCtlr_GetRTTI()
{
    return &g_012026d0;
}

extern char const* const g_012026d0_arg1;

// @fnv 0x00c32be0
// src: COMMUNITY 0x00c32be0
const char* __cdecl NiPSysModifierBoolCtlr_GetRTTI()
{
    return reinterpret_cast<const char*>(&g_012026d0_arg1);
}

struct BaseStandIn
{
    bool IsTargetParticleSystem(NiObjectNET*);
};
struct PsStandIn
{
    NiPSysModifier* FUN_00c1b0f0(void*);
};
struct StandIn
{
    bool NiPSysModifierActiveCtlr_InterpTargetIsCorrectType(NiObjectNET*);
};
// @fnv 0x00c29dd0
// src: XBOX_PDB 0x00c29dd0
bool StandIn::NiPSysModifierActiveCtlr_InterpTargetIsCorrectType(NiObjectNET* pkTarget)
{
    NiPSysModifier* pkModifier;
    if (!((BaseStandIn*)this)->IsTargetParticleSystem(pkTarget))
        return false;
    pkModifier = ((PsStandIn*)pkTarget)->FUN_00c1b0f0((void*)((char*)this + 0x38));
    return pkModifier;
}

extern "C" void* __cdecl NiViewerStrings_NiGetViewerString_Title(const void*);
struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_012026d0;
class NiPSysModifierActiveCtlr : public NiPSysModifierBoolCtlr
{
public:
    NiPSysModifierActiveCtlr() throw()
    {}
    virtual ~NiPSysModifierActiveCtlr();

    void __thiscall GetViewerStrings_00c29e00(StrArr*);
    void CopyMemberData(NiPSysModifierActiveCtlr* destination, void* cloning);
    NiPSysModifierActiveCtlr* CreateClone_00c29d80(void* cloning);
};
// @fnv 0x00c29e00
// src: XBOX_PDB 0x00c29e00
void __thiscall NiPSysModifierActiveCtlr::GetViewerStrings_00c29e00(StrArr* pArray)
{
    AppendModifierInfo(pArray);
    char* p = (char*)NiViewerStrings_NiGetViewerString_Title((const void*)*(void**)(void*)&g_012026d0);
    unsigned int uiIndex = pArray->m_usSize;
    unsigned int n = pArray->m_usMaxSize;
    if (uiIndex >= n)
        pArray->SetSize(pArray->m_usGrowBy + uiIndex);
    pArray->SetAt(uiIndex, p);
}

// FUN_00c29d60 (0x00c29d60, 31 bytes)
//
//   mov edx, dword ptr [ecx + 0x3c]      ; target = this->unk3c
//   mov eax, dword ptr [esp + 4]          ; the 4-byte stack argument
//   cmp byte ptr [edx + 0x14], al         ; target->unk14 != (unsigned char)arg
//   je  <ret 4>
//   mov ecx, edx                          ; this of the virtual call
//   mov edx, dword ptr [ecx]              ; vptr
//   mov dword ptr [esp + 4], eax          ; the argument is forwarded in place
//   mov eax, dword ptr [edx + 0x98]       ; vtable slot 0x98 -> 38
//   jmp eax
//   ret 4
//
// The two `this->unk3c` accesses must NOT be routed through a local pointer:
// with a local, cl 2008 coalesces the pointer into the incoming ECX and the
// call needs no `mov ecx, edx` copy (29 bytes).  Spelling both accesses as
// `this->unk3c->...` keeps the two memory descriptors distinct, so the
// pointer is materialised in EDX and copied into ECX for the virtual call.

struct FNV_C29D60_VtableBase
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
};

// The object held in this->unk3c: a byte flag at +0x14 and a virtual at
// vtable offset 0x98 (slot 38, i.e. right after the 38 base slots).
struct FNV_C29D60_Target : FNV_C29D60_VtableBase
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned char unk14;
    virtual void GetViewerStrings_00c29e00(unsigned int nValue);
};

// The owner of the function: the target pointer sits at +0x3c.
struct FNV_C29D60_Owner
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
    FNV_C29D60_Target* unk3c;
    void NiPSysModifierActiveCtlr_SetTargetBoolValue(unsigned int nValue);
};

// @fnv 0x00c29d60
// src: XBOX_PDB 0x00c29d60
void FNV_C29D60_Owner::NiPSysModifierActiveCtlr_SetTargetBoolValue(unsigned int nValue)
{
    if (this->unk3c->unk14 != (unsigned char)nValue)
    {
        this->unk3c->GetViewerStrings_00c29e00(nValue);
    }
}

// @fnv 0x00c29d80
// src: XBOX_PDB 0x00c29d80
NiPSysModifierActiveCtlr* NiPSysModifierActiveCtlr::CreateClone_00c29d80(void* pvCloning)
{
    NiPSysModifierActiveCtlr* pkClone = new NiPSysModifierActiveCtlr;
    CopyMemberData(pkClone, pvCloning);
    return pkClone;
}

extern "C" void __cdecl jmp_0xc32bf0();

// @fnv 0x00c29d30
// src: XBOX_PDB 0x00c29d30
void NiPSysModifierActiveCtlr_LinkObject()
{
    jmp_0xc32bf0();
}

#include <windows.h>
void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct RefCountedStandIn
{
    virtual void Unk0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};

struct NewStandIn
{
    RefCountedStandIn* FUN_00a52f00(void* pArg);
};

struct ArgStandIn
{
    char unk00[0xd8];
    unsigned int m_d8;
    void* FUN_00a63430();
};

// The shared header does not declare the bool-controller LinkObject override.
// This fastcall helper preserves its thiscall ABI while using the shared layout.
// @fnv 0x00c32bf0
// src: XBOX_PDB 0x00c32bf0
void __fastcall NiPSysModifierBoolCtlr_LinkObject(NiPSysModifierBoolCtlr* controller, int, ArgStandIn* arg)
{
    controller->NiPSysModifierCtlr::LinkObject(*reinterpret_cast<NiStream*>(arg));
    RefCountedStandIn*& interpolator = *reinterpret_cast<RefCountedStandIn**>(&controller->m_spControllerInterpolator);
    if (arg->m_d8 >= 0xa010068)
    {
        return;
    }
    void* pSource = arg->FUN_00a63430();
    void* n = Object_DispatchCommandFour(0x20);
    RefCountedStandIn* pNew;
    if (n != 0)
    {
        pNew = ((NewStandIn*)n)->FUN_00a52f00(pSource);
    }
    else
    {
        pNew = 0;
    }
    RefCountedStandIn* pOld = interpolator;
    if (pOld != pNew)
    {
        if (pOld != 0)
        {
            if (InterlockedDecrement((LONG*)&pOld->m_uiRefCount) == 0)
            {
                pOld->DeleteThis();
            }
        }
        interpolator = pNew;
        if (pNew != 0)
        {
            InterlockedIncrement((LONG*)&pNew->m_uiRefCount);
        }
    }
}
