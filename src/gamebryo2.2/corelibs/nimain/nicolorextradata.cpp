
// src/gamebryo2.2/corelibs/nimain/nicolorextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nicolorextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <stddef.h>

#include "../../../../include/NiColor.h"
#include "../../../../include/NiColorExtraData.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiColorA.h"

// @fnv 0x00a893b0
void NiColorExtraData::SetColor(NiColorA kColor)
{
    m_kFogTint = kColor;
}

extern void* g_011f5b68;

// @fnv 0x00a893f0
// src: COMMUNITY 0x00a893f0
void* __cdecl NiColorExtraData_GetRTTI()
{
    return &g_011f5b68;
}

extern "C" void __cdecl _FUN_00a7b300();
extern void __cdecl _delete(void*, unsigned int);
extern int DAT_0109eccc;

// @fnv 0x00a89560
NiColorExtraData* __fastcall DestroyColorExtraData(NiColorExtraData* self, void*, unsigned int flags)
{
    *reinterpret_cast<int**>(self) = &DAT_0109eccc;
    _FUN_00a7b300();
    if (flags & 1)
        _delete(self, 0x1c);
    return self;
}

extern const NiColorA kBlackColor;

// Keep construction and copying inline, as in the original clone routine.
static __forceinline NiColorExtraData* InitializeColorExtraData(NiColorExtraData* self) throw()
{
    self->NiExtraData::FUN_00a7b2e0();
    *reinterpret_cast<int**>(self) = &DAT_0109eccc;
    volatile float* pColor = &self->m_kFogTint.r;
    pColor[0] = 0.0f;
    pColor[1] = 0.0f;
    pColor[2] = 0.0f;
    pColor[3] = 0.0f;
    self->m_kFogTint = kBlackColor;
    return self;
}

static __forceinline void CopyColorExtraData(NiColorExtraData* self, NiColorExtraData* pkDest, CloningProcess& kCloning)
{
    self->NiExtraData::CopyMembers_00a7b330(pkDest, &kCloning);
    pkDest->m_kFogTint = self->m_kFogTint;
}

// @fnv 0x00a893d0
// src: XBOX_PDB 0x00a893d0
void NiColorExtraData::SaveBinary_00a893d0(NiStream& kStream)
{
    NiExtraData::SaveBinary(kStream);
    m_kFogTint.SaveBinary(kStream);
}

// @fnv 0x00a894f0
void __fastcall LoadColorExtraData(NiColorExtraData* self, void*, NiStream& kStream)
{
    self->NiExtraData::LoadBinary(kStream);
    if (kStream.m_uiNifFileVersion < 0x0500000e)
    {
        // The original initializes this temporary inline.
        float afTmpColor[3];
        NiColor& kTmpColor = reinterpret_cast<NiColor&>(afTmpColor);
        kTmpColor.r = 0.0f;
        kTmpColor.g = 0.0f;
        kTmpColor.b = 0.0f;
        kTmpColor.LoadBinary(kStream);
        float* pColor = (float*)&self->m_kFogTint;
        pColor[0] = kTmpColor.r;
        pColor[1] = kTmpColor.g;
        pColor[2] = kTmpColor.b;
        pColor[3] = 1.0f;
    }
    else
    {
        self->m_kFogTint.LoadBinary(kStream);
    }
}

// @fnv 0x00a89400
NiColorExtraData* __fastcall CloneColorExtraData(NiColorExtraData* self, void*, CloningProcess& kCloning)
{
    NiColorExtraData* pkDest = static_cast<NiColorExtraData*>(NiExtraData::operator new(sizeof(NiColorExtraData)));
    pkDest = pkDest ? InitializeColorExtraData(pkDest) : NULL;
    CopyColorExtraData(self, pkDest, kCloning);
    return pkDest;
}

// @fnv 0x00a89590
bool __fastcall EqualColorExtraData(NiColorExtraData* self, void*, NiColorExtraData* other)
{
    if (!other)
        return false;
    if (self->m_kFogTint.operator!=(other->m_kFogTint))
        return false;
    return true;
}

extern void* g_011f5b68;

struct StreamShell
{
    unsigned char unk0[8];
    unsigned short m_usSize;
    unsigned short m_usPos;
    unsigned short m_usHold;
    unsigned short m_usAdd;

    void FUN_0096ad30(unsigned int uiNewEnd);
    void FUN_0096ae90(unsigned int uiPos, void* pvData);
};

void __stdcall FUN_00a7b580(void* pv);
void* __cdecl NiViewerStrings_NiGetViewerString_Title(void* pv);

// Writes a pointer obtained from g_011f5b68 and the result of ToString("Color = ") into kStream, growing the stream when its position reaches its size.
// @fnv 0x00a895c0
void __fastcall WriteColorToStream(NiColorExtraData* self, void*, StreamShell& kStream)
{
    FUN_00a7b580(&kStream);
    void* p = NiViewerStrings_NiGetViewerString_Title(g_011f5b68);
    unsigned int uiPos = kStream.m_usPos;
    unsigned int uiSize = kStream.m_usSize;
    if (uiPos >= uiSize)
    {
        kStream.FUN_0096ad30(uiPos + kStream.m_usAdd);
    }
    kStream.FUN_0096ae90(uiPos, &p);
    p = self->m_kFogTint.GetViewerString("Color = ");
    uiPos = kStream.m_usPos;
    uiSize = kStream.m_usSize;
    if (uiPos >= uiSize)
    {
        kStream.FUN_0096ad30(uiPos + kStream.m_usAdd);
    }
    kStream.FUN_0096ae90(uiPos, &p);
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_0109eccc;
extern int DAT_011a9bd0;
extern int DAT_011a9bd4;
extern int DAT_011a9bd8;
extern int DAT_011a9bdc;

// Obtains a 0x1c byte block, calls a method on it, writes a global pointer and four global values, and returns it.
// @fnv 0x00a89490
// src: EXE 0x00a89490
unsigned int* __cdecl NiColorExtraData_CreateObject()
{
    unsigned int* ptr = (unsigned int*)Object_DispatchCommandFour(0x1c);

    if (ptr != NULL)
    {
        ((NiExtraData*)ptr)->FUN_00a7b2e0();

        ptr[0] = (unsigned int)&DAT_0109eccc;

        float f[4];
        f[0] = 0.0f;
        f[1] = 0.0f;
        f[2] = 0.0f;
        f[3] = 0.0f;

        volatile float* vf = (volatile float*)&ptr[3];
        vf[0] = f[0];
        vf[1] = f[1];
        vf[2] = f[2];
        vf[3] = f[3];

        ptr[3] = DAT_011a9bd0;
        ptr[4] = DAT_011a9bd4;
        ptr[5] = DAT_011a9bd8;
        ptr[6] = DAT_011a9bdc;

        return ptr;
    }

    return NULL;
}
