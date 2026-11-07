#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/StrArr.h"


// src/gamebryo2.2/corelibs/nimain/nivectorextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nivectorextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int g_011f5e84;

// @fnv 0x00a92070
// src: COMMUNITY 0x00a92070
int* __cdecl NiVectorExtraData_GetRTTI()
{
    return &g_011f5e84;
}

struct NiVectorExtraData : NiExtraData
{
    float m_afVectorComponents[4];
    bool IsEqual_00a92020(NiObject* pObject);
};

// @fnv 0x00a92020
// src: XBOX_PDB 0x00a92020
bool NiVectorExtraData::IsEqual_00a92020(NiObject* pObject)
{
    if (pObject)
    {
        NiVectorExtraData* pExtra = static_cast<NiVectorExtraData*>(pObject);
        if (m_afVectorComponents[0] != pExtra->m_afVectorComponents[0])
            return false;
        if (m_afVectorComponents[1] != pExtra->m_afVectorComponents[1])
            return false;
        if (m_afVectorComponents[2] != pExtra->m_afVectorComponents[2])
            return false;
        if (m_afVectorComponents[3] != pExtra->m_afVectorComponents[3])
            return false;
        return true;
    }
    return false;
}

struct Holder00a92080
{
    void* FUN_00a92080(unsigned int);
};
void __cdecl DestroyFields_00a7b300();
void __cdecl _delete(void*, unsigned int);
extern int DAT_0109fb94;
// @fnv 0x00a92080
void* Holder00a92080::FUN_00a92080(unsigned int flags)
{
    *(void**)this = (void*)&DAT_0109fb94;
    DestroyFields_00a7b300();
    if (flags & 1)
        _delete(this, 0x1c);
    return this;
}

struct CloningProcess
{
};
extern int DAT_0109fb94;
struct FUN_00a920b0_shell : NiVectorExtraData
{
    NiObject* NiVectorExtraData_CreateClone(CloningProcess&);
};
// Allocates a NiVectorExtraData, initialises its four floats to zero, copies this object's four floats into it and returns it.
// @fnv 0x00a920b0
// src: XBOX_PDB 0x00a920b0
NiObject* FUN_00a920b0_shell::NiVectorExtraData_CreateClone(CloningProcess& kCloning)
{
    NiVectorExtraData* pkObject = (NiVectorExtraData*)BSFadeNode::operator new(sizeof(NiVectorExtraData));
    if (pkObject)
    {
        ((NiExtraData*)pkObject)->FUN_00a7b2e0();
        *(void**)pkObject = (void*)&DAT_0109fb94;
        pkObject->m_afVectorComponents[0] = pkObject->m_afVectorComponents[1] = pkObject->m_afVectorComponents[2] =
            pkObject->m_afVectorComponents[3] = 0.0f;
    }
    else
    {
        pkObject = 0;
    }
    ((NiExtraData*)this)->CopyMembers_00a7b330(pkObject, &kCloning);
    pkObject->m_afVectorComponents[0] = m_afVectorComponents[0];
    pkObject->m_afVectorComponents[1] = m_afVectorComponents[1];
    pkObject->m_afVectorComponents[2] = m_afVectorComponents[2];
    pkObject->m_afVectorComponents[3] = m_afVectorComponents[3];
    return pkObject;
}

// The shared NiExtraData header does not declare its StrArr viewer overload.
extern void __fastcall GetExtraDataViewerStrings(NiExtraData* self, void*, StrArr* strings);

char* __cdecl _FUN_00a7d330(char* pString);
void* __cdecl _NiMalloc(unsigned int uiSize);
int __cdecl _NiSprintf(char* pBuffer, unsigned int uiSize, const char* pFormat, double EntryPointTwoValueFunctionData,
                       double fSecondFunctionValue, double fValue3, double fValue4);

// @fnv 0x00a92290
void __fastcall AppendVectorViewerStrings(NiVectorExtraData* self, void* unused, StrArr* pStringArray)
{
    GetExtraDataViewerStrings(self, unused, pStringArray);

    char* pcVectorString = _FUN_00a7d330(reinterpret_cast<char*>(g_011f5e84));

    unsigned int uiIndex = pStringArray->m_usSize;
    unsigned int ItemUpdateArray = pStringArray->m_usMaxSize;
    if (uiIndex >= ItemUpdateArray)
    {
        pStringArray->SetSize(static_cast<unsigned int>(pStringArray->m_usGrowBy) + uiIndex);
    }
    pStringArray->SetAt(uiIndex, pcVectorString);

    pcVectorString = static_cast<char*>(_NiMalloc(0x37));

    _NiSprintf(pcVectorString, 0x37, "Vector = (%5.3f,%5.3f,%5.3f,%5.3f)", self->m_afVectorComponents[0],
               self->m_afVectorComponents[1], self->m_afVectorComponents[2], self->m_afVectorComponents[3]);

    uiIndex = pStringArray->m_usSize;
    ItemUpdateArray = pStringArray->m_usMaxSize;
    if (uiIndex >= ItemUpdateArray)
    {
        pStringArray->SetSize(static_cast<unsigned int>(pStringArray->m_usGrowBy) + uiIndex);
    }
    pStringArray->SetAt(uiIndex, pcVectorString);
}

struct S_00a921f0_File
{
    int unk00;
    unsigned int m_uiPos;
    int unk08;
    unsigned int(__cdecl* m_pfnWrite)(S_00a921f0_File*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int Write(const void* p, unsigned int n, unsigned int size, unsigned int cnt)
    {
        unsigned int sizes = size;
        unsigned int w = m_pfnWrite(this, p, n, &sizes, cnt);
        m_uiPos += w;
        return w;
    }
};

struct S_00a921f0_Stream
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    S_00a921f0_File* m_pFile;
};

static __forceinline void S_00a921f0_SaveFloat(S_00a921f0_Stream& s, const float* pf)
{
    s.m_pFile->Write(pf, sizeof(float), sizeof(float), 1);
}

class FUN_00a921f0_cls : public NiVectorExtraData
{
  public:
    void SaveToStream(S_00a921f0_Stream& s);
};

// @fnv 0x00a921f0
void FUN_00a921f0_cls::SaveToStream(S_00a921f0_Stream& aStream)
{
    NiExtraData::SaveBinary(reinterpret_cast<NiStream&>(aStream));
    S_00a921f0_SaveFloat(aStream, &m_afVectorComponents[0]);
    S_00a921f0_SaveFloat(aStream, &m_afVectorComponents[1]);
    S_00a921f0_SaveFloat(aStream, &m_afVectorComponents[2]);
    S_00a921f0_SaveFloat(aStream, &m_afVectorComponents[3]);
}

struct S_00a92110_File
{
    int unk00;
    unsigned int m_uiPos;
    unsigned int(__cdecl* m_pfnWrite)(S_00a92110_File*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int Write(const void* p, unsigned int n, unsigned int size, unsigned int cnt)
    {
        unsigned int sizes = size;
        unsigned int w = m_pfnWrite(this, p, n, &sizes, cnt);
        m_uiPos += w;
        return w;
    }
};

struct FUN_00a59be0_tmp
{
    float v[3];
    void FUN_00a59be0(S_00a921f0_Stream* s);
};

class FUN_00a92110_cls : public NiVectorExtraData
{
  public:
    void NiVectorExtraData_LoadBinary(S_00a921f0_Stream* s);
};

// @fnv 0x00a92110
// src: XBOX_PDB 0x00a92110
void FUN_00a92110_cls::NiVectorExtraData_LoadBinary(S_00a921f0_Stream* s)
{
    NiExtraData::LoadBinary(reinterpret_cast<NiStream&>(*s));
    if ((unsigned int)s->unk0d8 < 0x500000e)
    {
        FUN_00a59be0_tmp tmp;
        tmp.FUN_00a59be0(s);
        m_afVectorComponents[0] = tmp.v[0];
        m_afVectorComponents[1] = tmp.v[1];
        m_afVectorComponents[2] = tmp.v[2];
        m_afVectorComponents[3] = 0.0f;
        return;
    }
    reinterpret_cast<S_00a92110_File*>(s->unk24c)->Write(&m_afVectorComponents[0], 4, 4, 1);
    reinterpret_cast<S_00a92110_File*>(s->unk24c)->Write(&m_afVectorComponents[1], 4, 4, 1);
    reinterpret_cast<S_00a92110_File*>(s->unk24c)->Write(&m_afVectorComponents[2], 4, 4, 1);
    reinterpret_cast<S_00a92110_File*>(s->unk24c)->Write(&m_afVectorComponents[3], 4, 4, 1);
}
