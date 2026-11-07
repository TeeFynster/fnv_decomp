
// src/gamebryo2.2/corelibs/nianimation/nirollcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nirollcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/NiRollController.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/StrArr.h"

extern const char* const g_011f3f58_arg1;

// @fnv 0x00a485a0
// src: COMMUNITY 0x00a485a0
const char* const* __cdecl NiFloatController_GetRTTI()
{
    return &g_011f3f58_arg1;
}

extern void* g_011f3f58;

// @fnv 0x00a485b0
// src: COMMUNITY 0x00a485b0
void* __cdecl NiRollController_GetRTTI()
{
    return &g_011f3f58;
}


void __fastcall FUN_00a6d220(void*);
extern int DAT_01098634;

// @fnv 0x00a48750
// src: EXE 0x00a48750
void* __cdecl NiRollController_CreateObject()
{
    void* pFadeNode = BSFadeNode::operator new(0x3c);
    if (pFadeNode)
    {
        FUN_00a6d220(pFadeNode);
        *(int*)((char*)pFadeNode + 0x38) = 0;
        *(int*)((char*)pFadeNode + 0x34) = 0;
        *(int*)pFadeNode = (int)&DAT_01098634;
        return pFadeNode;
    }
    return 0;
}

void __cdecl _delete(void*, unsigned int);
// Calls FUN_00a57990, frees this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00a485c0
void* NiRollController::DestroyIfFlagged(unsigned int flags)
{
	FUN_00a57990();
	if (flags & 1)
		_delete(this, 0x3c);
	return this;
}

void __stdcall FUN_00a6d830(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// Appends the string returned by _FUN_00a7d330(g_011f3f58) to the StrArr, growing it via SetSize when full, then stores it with SetAt.
// @fnv 0x00a48790
// src: XBOX_PDB 0x00a48790
void NiRollController::GetViewerStrings_00a48790(StrArr* pStrArr)
{
    FUN_00a6d830(pStrArr);
    char* pkString = _FUN_00a7d330((const char*)g_011f3f58);
    unsigned int uiSize = pStrArr->m_usSize;
    unsigned int uiMaxSize = pStrArr->m_usMaxSize;
    if (uiSize >= uiMaxSize)
        pStrArr->SetSize(uiSize + pStrArr->m_usGrowBy);
    pStrArr->SetAt(uiSize, pkString);
}

// Initializes storage allocated for a roll controller.
static inline NiRollController* InitializeRollController(NiRollController* controller)
{
    FUN_00a6d220(controller);
    controller->m_spFloatData = 0;
    // Preserve the original initialization store order.
    *(volatile unsigned int*)&controller->unk34 = 0;
    *(int*)controller = (int)&DAT_01098634;
    return controller;
}

// Allocates a new controller, copies this object's state into it via the cloning process, and returns the clone.
// @fnv 0x00a486f0
// src: XBOX_PDB 0x00a486f0
NiObject* NiRollController::CreateClone_00a486f0(CloningProcess& kCloning)
{
    NiRollController* allocation = (NiRollController*)NiObject::operator new(sizeof(NiRollController));
    NiRollController* pkClone = allocation ? InitializeRollController(allocation) : 0;
    CopyInterpTo(pkClone, &kCloning);
    return pkClone;
}

void __cdecl LinkObject_00a57a70();

// @fnv 0x00a48560
// src: XBOX_PDB 0x00a48560
void __cdecl NiRollController_LinkObject()
{
    LinkObject_00a57a70();
}

void __cdecl RegisterStreamables_00a57ad0();
// @fnv 0x00a48570
// src: XBOX_PDB 0x00a48570
void __cdecl NiRollController_RegisterStreamables()
{
    RegisterStreamables_00a57ad0();
}

void __cdecl SaveBinary_00a57b00();

// @fnv 0x00a48580
// src: XBOX_PDB 0x00a48580
void __cdecl NiRollController_SaveBinary() {
    SaveBinary_00a57b00();
}

void __cdecl IsEqual_00a57b20();

// @fnv 0x00a48590
// src: XBOX_PDB 0x00a48590
void __cdecl NiRollController_IsEqual()
{
    IsEqual_00a57b20();
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

void __cdecl LoadBinary_00a57970();
// @fnv 0x00a48550
// src: XBOX_PDB 0x00a48550
void __cdecl NiRollController_LoadBinary() { LoadBinary_00a57970(); }

// one matrix row per macro use, entries in column order (the original update stores them in this order)
#define ROLL_M3_ROW(r, a, b, c) m_pEntry[r][0] = a; m_pEntry[r][1] = b; m_pEntry[r][2] = c;
// Inline the Z rotation used by the original update.
inline void NiMatrix3::MakeZRotation(float fAngleDifference)
{
    float sn, cs;
    fnv_SinCos(fAngleDifference, sn, cs);
    ROLL_M3_ROW(0, cs, sn, 0.0f)
    ROLL_M3_ROW(1, -sn, cs, 0.0f)
    ROLL_M3_ROW(2, 0.0f, 0.0f, 1.0f)
}
#undef ROLL_M3_ROW

// 0x00a26b40 is NiFloatKey interpolation; no shared key definition is needed here.
float __cdecl InterpolateRollKey(float fTime, NiFloatKey* pkKeys, int eType,
    unsigned int uiNumKeys, unsigned int& uiLastIdx, unsigned char ucSize);

// @fnv 0x00a485e0
// src: XBOX_PDB 0x00a485e0
void NiRollController::Update_00a485e0(NiUpdateData& kUpdateData)
{
    if (!m_pkTarget || DontDoUpdate(kUpdateData.fTime))
        return;

    unsigned int uiNumKeys;
    int eType;
    unsigned char ucSize;
    NiFloatKey* pkKeys = GetFloatKeys(uiNumKeys, eType, ucSize);
    float fRoll = InterpolateRollKey(m_fControllerTime, pkKeys, eType, uiNumKeys, unk34, ucSize);

    NiMatrix3 kRot;
    kRot = ((NiAVObject*)m_pkTarget)->m_kLocal.m_Rotate;
    NiMatrix3 kRoll;
    kRoll.MakeZRotation(-fRoll);
    kRot = static_cast<const NiMatrix3&>(kRot) * kRoll;
    ((NiAVObject*)m_pkTarget)->m_kLocal.m_Rotate = kRot;
}
