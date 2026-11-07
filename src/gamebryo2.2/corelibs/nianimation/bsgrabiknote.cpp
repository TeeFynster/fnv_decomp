
// src/gamebryo2.2/corelibs/nianimation/bsgrabiknote.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/bsgrabiknote.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"

extern "C" void* g_011f3ef0;

// @fnv 0x00a44350
// src: COMMUNITY 0x00a44350
void* __cdecl BSGrabIKNote_GetRTTI()
{
    return &g_011f3ef0;
}

struct FUN_00a44360_shell
{
    void* Destroy(unsigned int flags);
};

void __cdecl FUN_00a44830();
void __cdecl _delete(void* p, unsigned int size);

// Calls FUN_00a44830, then frees this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00a44360
void* __thiscall FUN_00a44360_shell::Destroy(unsigned int flags)
{
    FUN_00a44830();
    if (flags & 1)
        _delete(this, 0x1c);
    return this;
}

struct FUN_00a44310_shell
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    unsigned int m_10;
    float m_14;
    unsigned int m_18;
    bool Matches(const void*);
    bool Equals(const void* pOther);
};

// @fnv 0x00a44310
bool FUN_00a44310_shell::Equals(const void* pOther)
{
    if (Matches(pOther) && m_10 == *(const unsigned int*)((const char*)pOther + 0x10) &&
        m_14 == *(const float*)((const char*)pOther + 0x14) &&
        m_18 == *(const unsigned int*)((const char*)pOther + 0x18))
        return true;
    return false;
}

extern int DAT_01097d34;

struct ViewerStrings;

struct ArmNoteBase
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    unsigned int m_eType;
    float m_fTime;
    void BaseGetViewerStrings(ViewerStrings* pkStrings);
};

struct BSGrabIKNote : ArmNoteBase
{
    unsigned int m_eArm;
    float m_fGain;
    unsigned int m_eAnimationState;
    void* Clone(CloningProcess* process);
    void GetViewerStrings_00a44650(ViewerStrings* pkStrings);
};

// @fnv 0x00a44380
// src: EXE 0x00a44380
void* __cdecl BSGrabIKNote_CreateObject()
{
    BSGrabIKNote* node = static_cast<BSGrabIKNote*>(BSFadeNode::operator new(28));
    if (node)
    {
        reinterpret_cast<BSFadeNode*>(node)->_Call_a5d3a0();
        node->m_fTime = 0.0f;
        node->m_eType = 1;
        node->m_fGain = 0.0f;
        node->m_ppVirtualMethodTable = &DAT_01097d34;
        node->m_eAnimationState = 0;
        return node;
    }
    return 0;
}

struct BSAnimNote_shell
{
    char __thiscall BSAnimNote_RegisterStreamables(NiStream&);
};

struct FUN_00a43f10_shell : BSAnimNote_shell
{
    bool __thiscall BSGrabIKNote_RegisterStreamables(NiStream&);
};

// @fnv 0x00a43f10
// src: XBOX_PDB 0x00a43f10
bool FUN_00a43f10_shell::BSGrabIKNote_RegisterStreamables(NiStream& arStream)
{
    return BSAnimNote_shell::BSAnimNote_RegisterStreamables(arStream);
}

struct FUN_00a44850_holder
{
    void CopyMembersStreamAndFields(FUN_00a44850_holder*, CloningProcess*);
};
// @fnv 0x00a443c0
void* BSGrabIKNote::Clone(CloningProcess* process)
{
    BSGrabIKNote* node = static_cast<BSGrabIKNote*>(BSFadeNode::operator new(28));
    if (node)
    {
        reinterpret_cast<BSFadeNode*>(node)->_Call_a5d3a0();
        node->m_fTime = 0.0f;
        node->m_eType = 1;
        node->m_fGain = 0.0f;
        node->m_ppVirtualMethodTable = (void*)&DAT_01097d34;
        node->m_eAnimationState = 0;
    }
    else
        node = 0;
    ((FUN_00a44850_holder*)this)->CopyMembersStreamAndFields((FUN_00a44850_holder*)node, process);
    *(void**)((char*)node + 0x10) = *(void**)((char*)this + 0x10);
    *(float*)((char*)node + 0x14) = *(float*)((char*)this + 0x14);
    *(unsigned int*)((char*)node + 0x18) = *(unsigned int*)((char*)this + 0x18);
    return node;
}

struct S_00a44530_Bin;
typedef int(__cdecl* S_00a44530_ReadFn)(S_00a44530_Bin*, void*, int, unsigned int*, int);
struct S_00a44530_Bin
{
    int unk00;
    int unk04;
    S_00a44530_ReadFn unk08;
};
struct S_00a44530_Stream
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
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_00a44530_Bin* unk24c;
};
__forceinline void S_00a44530_BinRead(S_00a44530_Bin* b, void* v, int bytes, int n)
{
    unsigned int sz = 4;
    b->unk04 += b->unk08(b, v, bytes, &sz, n);
}
__forceinline void S_00a44530_Load(S_00a44530_Stream* s, void* v)
{
    S_00a44530_BinRead(s->unk24c, v, 4, 1);
}
struct S_00a44530_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void __thiscall ReadBinaryFields(S_00a44530_Stream* stream);
    void __thiscall LoadFromStream(S_00a44530_Stream* stream);
};
// Calls ReadBinaryFields, then reads three 4-byte values from the stream into unk10, unk14 and unk18.
// @fnv 0x00a44530
void __thiscall S_00a44530_Class::LoadFromStream(S_00a44530_Stream* stream)
{
    ReadBinaryFields(stream);
    S_00a44530_Load(stream, &unk10);
    S_00a44530_Load(stream, &unk14);
    S_00a44530_Load(stream, &unk18);
}

struct StreamFile;
typedef unsigned int(__cdecl* StreamFileReadFn)(StreamFile* stream, void* buf, unsigned int size, unsigned int* io,
                                                unsigned int count);

struct StreamFile
{
    void* m_00;
    unsigned int m_04;
    void* m_08;
    StreamFileReadFn m_0c;
};

struct StreamOwner
{
    unsigned char unk000[0x250];
    StreamFile* m_250;
};

class FUN_00a445c0_cls
{
  public:
    void FUN_00a44a90(StreamOwner* stream);
    void ReadFromStream(StreamOwner* stream);

  public:
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
};
static unsigned int StreamReadPart(StreamFile* f, void* buf)
{
    unsigned int n = 4;
    return f->m_0c(f, buf, 4, &n, 1);
}
// Reads three 4-byte values from the stream into m_10, m_14 and m_18, advancing the stream position after each read.
// @fnv 0x00a445c0
void FUN_00a445c0_cls::ReadFromStream(StreamOwner* stream)
{
    FUN_00a44a90(stream);
    StreamFile* f = stream->m_250;
    f->m_04 += StreamReadPart(f, &m_10);
    f = stream->m_250;
    f->m_04 += StreamReadPart(f, &m_14);
    f = stream->m_250;
    f->m_04 += StreamReadPart(f, &m_18);
}

char* NiGetViewerStr(const char* pcName, const char* pcValue);
char* NiGetViewerString_00a7d550(const char* pcName, float fValue);

struct ViewerStrings
{
    void* m_ppVirtualMethodTable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    unsigned int Add(char* element)
    {
        unsigned int i = m_usSize;
        if (i >= m_usMaxSize)
            SetSize(i + m_usGrowBy);
        SetAt(i, element);
        return i;
    }
};

// Appends the arm, gain and state viewer strings to pkStrings after the base viewer strings.
// @fnv 0x00a44650
// src: XBOX_PDB 0x00a44650
void BSGrabIKNote::GetViewerStrings_00a44650(ViewerStrings* pkStrings)
{
    BaseGetViewerStrings(pkStrings);
    switch (m_eArm)
    {
    case 0:
        pkStrings->Add(NiGetViewerStr("Arm", "Left"));
    case 1:
        pkStrings->Add(NiGetViewerStr("Arm", "Right"));
    default:
        pkStrings->Add(NiGetViewerStr("Arm", ""));
    }
    pkStrings->Add(NiGetViewerString_00a7d550("Gain", m_fGain));
    switch (m_eAnimationState)
    {
    case 1:
        pkStrings->Add(NiGetViewerStr("State", "Start"));
    case 2:
        pkStrings->Add(NiGetViewerStr("State", "Stop"));
    default:
        pkStrings->Add(NiGetViewerStr("State", "None"));
    }
}

struct TextKeyHandlerBase
{
    bool FUN_00a44930(const char* apTextKey);
};
struct S00a44430_Str
{
    int m_kHandle;
    void AssignString(const char* apStr);
    bool NiString_ToFloat(float* apOut);
    void ReleaseHandle();
};
int FUN_00ec8a19(const char*, const char*, int);
int FUN_00ecc7b0(char*, const char*, int);
extern const char str_01097dc4[];
extern const char str_010477f4[];
extern const char str_010639ec[];

struct S00a44430_Obj : TextKeyHandlerBase
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned int m_10;
    float m_14;
    unsigned int m_18;
    bool BSGrabIKNote_ParseTextKey(const char* apTextKey);
};

// Parses apTextKey for a prefix, side flag, gain value, and mode string, storing results in m_10, m_14, and m_18.
// @fnv 0x00a44430
// src: XBOX_PDB 0x00a44430
bool S00a44430_Obj::BSGrabIKNote_ParseTextKey(const char* apTextKey)
{
    bool bret = FUN_00a44930(apTextKey);
    const char* ptext = (const char*)*(void**)((char*)apTextKey + 4);
    if (FUN_00ec8a19(ptext, str_01097dc4, 6) == 0)
    {
        ptext += 6;
        if (*ptext == ' ' && (ptext[1] == 'R' || ptext[1] == 'L'))
        {
            m_10 = (ptext[1] == 'R');
            bret = true;
        }
        ptext += 2;
        if (bret && *ptext == ' ')
        {
            ++ptext;
            int gainBuf[1];
            FUN_00ecc7b0((char*)gainBuf, ptext, 4);
            S00a44430_Str gainStr;
            gainStr.AssignString((const char*)gainBuf);
            if (!gainStr.NiString_ToFloat(&m_14))
                bret = false;
            ptext += 4;
            gainStr.ReleaseHandle();
            if (bret && *ptext == ' ')
            {
                ++ptext;
                if (FUN_00ec8a19(ptext, str_010477f4, 5) == 0)
                    m_18 = 1;
                if (FUN_00ec8a19(ptext, str_010639ec, 4) == 0)
                    m_18 = 2;
            }
        }
        else
        {
            bret = false;
        }
    }
    return bret;
}
