
// src/gamebryo2.2/corelibs/niparticle/nipsysresetonloopctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysresetonloopctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/StrArr.h"
#include "../../../../include/NiStream.h"
// BaseHack_nipsysresetonloopctlr: local type (was include/BaseHack.h, which had no evidence of one real class); its methods are 0x00a57130 NiExtraDataController::SaveBinary, 0x00a6d730 NiTimeController::SaveBinary, 0x00c31b80 NiPSysVolumeEmitter::IsEqual
class NiObject;
struct NiStream;

class BaseHack_nipsysresetonloopctlr
{
public:
    void __thiscall FUN_00a6d730(NiStream&);
    bool FUN_00c31b80(NiObject*);
};

extern "C"
{
    extern void* g_012026a8;
}

// @fnv 0x00c28400
// src: COMMUNITY 0x00c28400
void* __cdecl NiPSysResetOnLoopCtlr_GetRTTI()
{
    return &g_012026a8;
}

void __cdecl FUN_00a6d290();
void __cdecl _delete(void* p, unsigned int size);

struct NiPSysResetOnLoopCtlr
{
    NiPSysResetOnLoopCtlr* __thiscall Destroy(unsigned int flags);
};

// Calls FUN_00a6d290, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00c28410
NiPSysResetOnLoopCtlr* __thiscall NiPSysResetOnLoopCtlr::Destroy(unsigned int flags)
{
    FUN_00a6d290();
    if (flags & 1)
        _delete(this, 0x38);
    return this;
}

extern char const* const g_01202538_arg1;
struct RTTI_00c284f0
{
    int _00;
    RTTI_00c284f0* m_pkBase;
};
struct Obj_00c284f0
{
    virtual void _u0();
    virtual void _u1();
    virtual RTTI_00c284f0* GetRTTI();
};
struct Cls_00c284f0
{
    bool __thiscall IsTargetOfType();
};
// Checks whether the object at offset 0x2c exists and its RTTI chain contains g_01202538_arg1, returning true if found.
// @fnv 0x00c284f0
bool __thiscall Cls_00c284f0::IsTargetOfType()
{
    Obj_00c284f0* pkTarget = *(Obj_00c284f0**)((char*)this + 0x2c);
    if (!pkTarget)
        return false;
    RTTI_00c284f0* pkRTTI = pkTarget->GetRTTI();
    for (; pkRTTI; pkRTTI = pkRTTI->m_pkBase)
    {
        if (pkRTTI == (RTTI_00c284f0*)&g_01202538_arg1)
            return true;
    }
    return false;
}

void __stdcall FUN_00a6d830(StrArr*);
char* __cdecl _FUN_00a7d330(void*);
// Appends the string returned by _FUN_00a7d330(g_012026a8) to pkStrings, growing the array if the position is at or past its size.
// @fnv 0x00c28520
// src: XBOX_PDB 0x00c28520
void __stdcall NiPSysResetOnLoopCtlr_GetViewerStrings(StrArr* pkStrings)
{
    FUN_00a6d830(pkStrings);
    char* pcString = _FUN_00a7d330(g_012026a8);
    unsigned int uiPos = pkStrings->m_usSize;
    unsigned int uiSize = pkStrings->m_usMaxSize;
    if (uiPos >= uiSize)
    {
        pkStrings->SetSize(uiPos + pkStrings->m_usGrowBy);
    }
    pkStrings->SetAt(uiPos, pcString);
}

#include "../../../../include/NiMemObject.h"
void __fastcall FUN_00a6d220(void* object);
extern float DAT_01015f5c;
extern int DAT_010be8e4;

struct CloningProcess
{
};
struct CloneableObj
{
    void* vtable;
    void FUN_00a6cfe0(CloneableObj* object, void* argument);
};
struct FUN_00c28430_Object : CloneableObj
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
    float value34;
};
struct FUN_00c28430_class : CloneableObj
{
    FUN_00c28430_Object* CreateCloneableObject(void* volatile argument);
};
// @fnv 0x00c28430
FUN_00c28430_Object* FUN_00c28430_class::CreateCloneableObject(void* volatile argument)
{
    FUN_00c28430_Object* object = (FUN_00c28430_Object*)NiMemObject::operator new(0x38);
    if (object)
    {
        FUN_00a6d220(object);
        object->value34 = DAT_01015f5c;
        object->vtable = &DAT_010be8e4;
        FUN_00a6cfe0(object, argument);
    }
    else
    {
        object = 0;
        void* copy = argument;
        FUN_00a6cfe0(object, copy);
    }
    return object;
}

extern double _DAT_010241b0;
struct FUN_00c28490_shell
{
    int unk00;
    int unk04;
    unsigned short flags;
    unsigned short unk0a;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    float unk28;
    char* unk2c;
    int unk30;
    float unk34;
    char DontDoUpdate(float value);
    void NiPSysResetOnLoopCtlr_Update(float* p);
};
// Clears two flags, and if unk2c is set and FUN_00a36250(*p) returns 0, resets unk34 to unk28 and sets unk2c[0xd8] when unk34 exceeds unk28.
// @fnv 0x00c28490
// src: XBOX_PDB 0x00c28490
void FUN_00c28490_shell::NiPSysResetOnLoopCtlr_Update(float* pfValue)
{
    flags &= 0xfff9;
    if (unk2c != 0)
    {
        if (DontDoUpdate(*pfValue) == 0)
        {
            if ((double)unk34 == _DAT_010241b0)
                unk34 = unk28;
            if (unk34 > unk28)
                unk2c[0xd8] = 1;
            unk34 = unk28;
        }
    }
}

void __cdecl NiTimeController_RegisterStreamables();

// @fnv 0x00a2f8b0
// src: XBOX_PDB 0x00a2f8b0
void __cdecl NiInterpController_RegisterStreamables()
{
    NiTimeController_RegisterStreamables();
}


struct C27120Class : BaseHack_nipsysresetonloopctlr
{
    void NiInterpController_SaveBinary(NiStream& s);
};

// @fnv 0x00c27120
// src: XBOX_PDB 0x00c27120
void C27120Class::NiInterpController_SaveBinary(NiStream& s)
{
    FUN_00a6d730(s);
}

struct NiStream;

struct SubNiPSysResetOnLoopCtlr : NiPSysResetOnLoopCtlr
{
    void FUN_00a6d5e0(NiStream& stream);
    void NiPSysResetOnLoopCtlr_LoadBinary(NiStream& stream);
};

// @fnv 0x00c283e0
// src: XBOX_PDB 0x00c283e0
void SubNiPSysResetOnLoopCtlr::NiPSysResetOnLoopCtlr_LoadBinary(NiStream& stream)
{
    FUN_00a6d5e0(stream);
}

void __cdecl NiTimeController_IsEqual();
// @fnv 0x00c283f0
// src: XBOX_PDB 0x00c283f0
void __cdecl NiInterpController_IsEqual()
{
    NiTimeController_IsEqual();
}
