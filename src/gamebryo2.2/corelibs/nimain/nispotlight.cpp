#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPointLight.h"
#include "../../../../include/NiSpotLight.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nimain/nispotlight.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nispotlight.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_011f5ec4;

// @fnv 0x00a94d50
// src: COMMUNITY 0x00a94d50
GlobalObjectO2_00a7b610* __cdecl NiSpotLight_GetRTTI()
{
    return &g_011f5ec4;
}

struct NiSpotLight;

extern "C" void __cdecl _FUN_00a72010();
extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);

struct NiSpotLightShell
{
    NiSpotLightShell* __thiscall FUN_00a94d60(unsigned int flags);
};

// Calls _FUN_00a72010, then if flags has bit 1 set calls __Dummy_00b6fef0 on this with size 0x114, and returns this.
// @fnv 0x00a94d60
NiSpotLightShell* __thiscall NiSpotLightShell::FUN_00a94d60(unsigned int flags)
{
    _FUN_00a72010();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x114);
    return this;
}


// @fnv 0x00a94e20
// src: EXE 0x00a94e20
void* __cdecl NiSpotLight_CreateObject()
{
    void* p = BSFadeNode::operator new(0x114);
    if (p)
        return ((BSFadeNode*)p)->FUN_00a94ce0();
    return 0;
}



// Calls the base NiPointLight comparison, then checks that the spot light's three float fields match the other object's.
// @fnv 0x00a94c80
bool NiSpotLight::IsEqual(NiObject* pObject) const
{
    NiSpotLight* pOther = (NiSpotLight*)pObject;
    if (((NiPointLight*)this)->IsEqual_00a7d730(pObject))
    {
        if (m_f0108 == pOther->m_f0108 && m_f0110 == pOther->m_f0110 && m_f010c == pOther->m_f010c)
            return true;
    }
    return false;
}

struct C_00a7d7a0
{
    void __thiscall UpdateWorldData_00a7d7a0(NiUpdateData&);
};
struct S_00a94d90
{
    void __thiscall NiSpotLight_UpdateWorldData(NiUpdateData&);
};
// Calls the base update, copies three floats from offsets 0x68/0x74/0x80 to 0xFC/0x100/0x104, and increments the counter at 0xA8.
// @fnv 0x00a94d90
// src: XBOX_PDB 0x00a94d90
void __thiscall S_00a94d90::NiSpotLight_UpdateWorldData(NiUpdateData& UpdateData)
{
    ((C_00a7d7a0*)this)->UpdateWorldData_00a7d7a0(UpdateData);
    *(volatile float*)((char*)this + 0xFC) = *(volatile float*)((char*)this + 0x68);
    *(volatile float*)((char*)this + 0x100) = *(volatile float*)((char*)this + 0x74);
    *(volatile float*)((char*)this + 0x104) = *(volatile float*)((char*)this + 0x80);
    ++*(volatile int*)((char*)this + 0xA8);
}



struct NiPointLightViewerStrings
{
    void __thiscall FUN_00a7d960(StrArr* strings);
};

char* __cdecl _FUN_00a7d330(void* object);
char* __cdecl NiGetViewerString_00a7d550(char const* name, float value);

struct FUN_00a94f70_shell : NiSpotLightShell
{
    void __thiscall AppendViewerStrings(StrArr* strings);
};

// Appends the spot light's base viewer strings plus m_kWorldDir, m_fOuterSpotAngle, m_fInnerSpotAngle and m_fSpotExponent entries to the string array.
// @fnv 0x00a94f70
void FUN_00a94f70_shell::AppendViewerStrings(StrArr* strings)
{
    char* value;
    unsigned int index;

    reinterpret_cast<NiPointLightViewerStrings*>(this)->FUN_00a7d960(strings);

    value = _FUN_00a7d330(*reinterpret_cast<void**>(&g_011f5ec4));

    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0xfc)->GetViewerString_00a59af0("m_kWorldDir");

    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d550("m_fOuterSpotAngle", *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x108));

    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d550("m_fInnerSpotAngle", *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x10c));

    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d550("m_fSpotExponent", *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x110));

    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);
}

struct S_00a94ce0_Base
{
    virtual void vf0();
    S_00a94ce0_Base();
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
    unsigned char unk9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
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
};
struct S_00a94ce0_V3
{
    float a;
    float b;
    float c;
};
struct S_00a94ce0_Mid : S_00a94ce0_Base
{
    S_00a94ce0_V3 unkfc;
    __forceinline S_00a94ce0_Mid()
    {
        S_00a94ce0_V3 t;
        t.a = 1.0f;
        t.b = 0.0f;
        t.c = 0.0f;
        unkfc = t;
    }
};
struct FUN_00a94ce0 : S_00a94ce0_Mid
{
    float unk108;
    float unk10c;
    float unk110;
    FUN_00a94ce0();
    virtual void vf0();
};
// Initializes the object: sets unk9d to 4, unk110 to 1.0f, and unk108 and unk10c to 0.0f.
// @fnv 0x00a94ce0
FUN_00a94ce0::FUN_00a94ce0()
{
    unk9d = 4;
    unk110 = 1.0f;
    unk108 = 0.0f;
    unk10c = 0.0f;
}

struct FUN_00a94e40_arg;
struct StreamCb;
struct FUN_00a94e40_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    float m_f0108;
    float m_f010c;
    float m_f0110;
    void __thiscall SaveToStream(FUN_00a94e40_arg* a);
    void __thiscall NiSpotLight_LoadBinary(FUN_00a94e40_arg* a);
};

struct StreamCb
{
    int unk00;
    int m_04;
    int(__cdecl* m_08)(StreamCb*, void*, unsigned int, unsigned int*, unsigned int);
};

struct FUN_00a94e40_arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    unsigned int m_00d8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    StreamCb* m_024c;
};

// @fnv 0x00a94e40
// src: XBOX_PDB 0x00a94e40
void __thiscall FUN_00a94e40_cls::NiSpotLight_LoadBinary(FUN_00a94e40_arg* apArg)
{
    SaveToStream(apArg);
    StreamCb* s = apArg->m_024c;
    {
        unsigned int n = 4;
        s->m_04 += s->m_08(s, &m_f0108, 4, &n, 1);
    }
    if (apArg->m_00d8 >= 0x14020005)
    {
        StreamCb* t = apArg->m_024c;
        {
            unsigned int n = 4;
            t->m_04 += t->m_08(t, &m_f010c, 4, &n, 1);
        }
    }
    s = apArg->m_024c;
    {
        unsigned int n = 4;
        s->m_04 += s->m_08(s, &m_f0110, 4, &n, 1);
    }
}

struct BinaryWriter;
typedef int(__cdecl* WriteProc)(BinaryWriter*, const void*, unsigned int, unsigned int*, int);
struct BinaryWriter
{
    int unk00;
    unsigned int byteCount;
    int unk08;
    WriteProc callback;
    __forceinline int WriteValue(const void* data)
    {
        unsigned int length = 4;
        return callback(this, data, 4, &length, 1);
    }
};
struct NiStreamArg
{
    BinaryWriter* writer()
    {
        return *(BinaryWriter**)((char*)this + 0x250);
    }
};
struct LightBaseSerialization
{
    void SavePointLight(NiStreamArg* stream);
};
struct LightSerialization
{
    void WriteSpotLightData(NiStreamArg* stream);
};
// Calls the base light serialization, then writes m_f0108, m_f010c and m_f0110 to the stream's writer, accumulating byte counts.
// @fnv 0x00a94ee0
void LightSerialization::WriteSpotLightData(NiStreamArg* stream)
{
    ((LightBaseSerialization*)this)->SavePointLight(stream);
    NiSpotLight* spot = (NiSpotLight*)this;
    unsigned int bytes;
    BinaryWriter* output = stream->writer();
    output->byteCount += output->WriteValue(&spot->m_f0108);
    output = stream->writer();
    output->byteCount += output->WriteValue(&spot->m_f010c);
    output = stream->writer();
    output->byteCount += output->WriteValue(&spot->m_f0110);
}

class BA94DD0CloningProcess;

class BA94DD0FadeNode
{
  public:
    static void* operator new(unsigned int uiSize);

    BA94DD0FadeNode() throw();
    virtual ~BA94DD0FadeNode();

    void CopyMemberData(BA94DD0FadeNode* pkDest, BA94DD0CloningProcess& kCloning);
    BA94DD0FadeNode* Clone(BA94DD0CloningProcess& kCloning);

    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
};

// @fnv 0x00a94dd0
BA94DD0FadeNode* BA94DD0FadeNode::Clone(BA94DD0CloningProcess& kCloning)
{
    BA94DD0FadeNode* pkClone = new BA94DD0FadeNode;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

class NiStream;

extern "C" void __cdecl NiAmbientLight_LinkObject(void* thisPtr, NiStream& stream);

// @fnv 0x00a94c60
// src: XBOX_PDB 0x00a94c60
void __cdecl NiSpotLight_LinkObject(void* thisPtr, NiStream& stream)
{
    NiAmbientLight_LinkObject(thisPtr, stream);
}

extern "C" void __cdecl _FUN_00a75c10();

// @fnv 0x00a94c70
// src: XBOX_PDB 0x00a94c70
void __cdecl NiSpotLight_RegisterStreamables()
{
    _FUN_00a75c10();
}
