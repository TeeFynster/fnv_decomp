#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiProperty.h"
#include "../../../../include/NiVertexColorProperty.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nimain/nivertexcolorproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nivertexcolorproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.



extern int DAT_0109b72c;

// Allocates a 0x1c-byte NiProperty, constructs it, sets a short field at offset 0x18 to 8 and installs the vtable, returning the object or null.
// @fnv 0x00a5f280
// src: EXE 0x00a5f280
NiProperty* NiVertexColorProperty_CreateObject()
{
    NiVertexColorProperty* p = static_cast<NiVertexColorProperty*>(BSFadeNode::operator new(0x1c));
    if (p)
    {
        p->NiProperty::NiProperty();
        p->m_uiObjectFlags = 8;
        *reinterpret_cast<int*>(p) = reinterpret_cast<int>(&DAT_0109b72c);
        return p;
    }
    return 0;
}

// Base routines not yet exposed by the shared NiProperty declaration.
struct PropertyRoutines
{
    bool IsEqual(NiObject*);
    void CopyMembers(NiVertexColorProperty*, unsigned int);
    void AppendString(StrArr*);
};
// @fnv 0x00a5f090
bool NiVertexColorProperty::IsVertexColorPropertyEqual(NiObject* pkObject)
{
    NiVertexColorProperty* pkVC;
    if (reinterpret_cast<PropertyRoutines*>(this)->IsEqual(pkObject))
    {
        pkVC = (NiVertexColorProperty*)pkObject;
        if ((pkVC->m_uiObjectFlags & 0x30) == (m_uiObjectFlags & 0x30))
        {
            if ((pkVC->m_uiObjectFlags & 8) == (m_uiObjectFlags & 8))
                return true;
        }
    }
    return false;
}

extern double* _g_011f4430;
char* __cdecl _FUN_00a7d330(double* value);
char* __cdecl BuildSourceString(const char* name, unsigned int value);
char* __cdecl BuildLightingEnumString(const char* name, unsigned int value);

// For routines absent from the shared declaration, an unused EDX parameter
// preserves the original member-function ABI while using the shared object layout.
// @fnv 0x00a5f3a0
void __fastcall AppendVertexColorProperties(NiVertexColorProperty* self, void*, StrArr* strings)
{
    reinterpret_cast<PropertyRoutines*>(self)->AppendString(strings);

    char* value = _FUN_00a7d330(_g_011f4430);
    unsigned int index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    unsigned int sourceMode = (self->m_uiObjectFlags >> 4) & 3;
    value = BuildSourceString("Source Mode", sourceMode);
    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    unsigned int lightingMode = (self->m_uiObjectFlags >> 3) & 1;
    value = BuildLightingEnumString("Lighting Mode", lightingMode);
    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
void __stdcall CreateVertexBufferSet(void* self, unsigned int arg);

// @fnv 0x00a5f210
void* __fastcall CloneVertexColorProperty(NiVertexColorProperty* self, void*, unsigned int a1)
{
    if (self->m_spControllers != 0)
    {
        NiVertexColorProperty* p = static_cast<NiVertexColorProperty*>(Object_DispatchCommandFour(0x1c));
        if (p)
        {
            p->NiProperty::NiProperty();
            *reinterpret_cast<int*>(p) = reinterpret_cast<int>(&DAT_0109b72c);
            p->m_uiObjectFlags = 8;
        }
        else
        {
            p = 0;
        }
        reinterpret_cast<PropertyRoutines*>(self)->CopyMembers(p, a1);
        p->m_uiObjectFlags = self->m_uiObjectFlags;
        return p;
    }
    else
    {
        CreateVertexBufferSet(self, a1);
        return self;
    }
}

extern "C" unsigned int __cdecl strlen(const char* s);

void* __cdecl NiMalloc(unsigned int size);
int __cdecl FUN_00a305b0(char* buffer, unsigned int size, const char* format, ...);

// Allocates a buffer and formats name with a lighting enum value (LIGHTING_E, LIGHTING_E_A_D, or UNKNOWN) into it, returning the buffer.
// @fnv 0x00a5f160
char* __cdecl BuildLightingEnumString(const char* name, unsigned int value)
{
    unsigned int size = strlen(name) + 0x1a;
    char* buffer = (char*)NiMalloc(size);
    switch (value)
    {
    case 0:
        FUN_00a305b0(buffer, size, "%s = LIGHTING_E", name);
        break;
    case 1:
        FUN_00a305b0(buffer, size, "%s = LIGHTING_E_A_D", name);
        break;
    default:
        FUN_00a305b0(buffer, size, "%s = UNKNOWN!!!", name);
        break;
    }
    return buffer;
}

void* _NiMalloc(unsigned int);
int _NiSprintf(char*, unsigned int, const char*, ...);

// Allocates a string of uiLen + 0x1a bytes and formats pcPrefix with a source name selected by eMode into it, returning the string.
// @fnv 0x00a5f0d0
char* BuildSourceString(const char* pcPrefix, int eMode)
{
    char* pcString;
    unsigned int uiLen = strlen(pcPrefix);

    pcString = (char*)_NiMalloc(uiLen + 0x1a);

    switch (eMode)
    {
    case 0:
        _NiSprintf(pcString, uiLen + 0x1a, "%s = SOURCE_IGNORE", pcPrefix);
        break;

    case 1:
        _NiSprintf(pcString, uiLen + 0x1a, "%s = SOURCE_EMISSIVE", pcPrefix);
        break;

    case 2:
        _NiSprintf(pcString, uiLen + 0x1a, "%s = SOURCE_AMB_DIFF", pcPrefix);
        break;

    default:
        _NiSprintf(pcString, uiLen + 0x1a, "%s = UNKNOWN!!!", pcPrefix);
        break;
    }

    return pcString;
}

namespace f2b {
struct Bin
{
    unsigned int unk00;
    unsigned int m_uiPos;
    unsigned int(__cdecl* m_pfnRead)(Bin*, void*, unsigned int, unsigned int*, unsigned int);
};
struct Stream
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int m_uiFormatVersion;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    Bin* m_pkBin;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned short m_usFlags;
};
struct BinX : Bin
{
    unsigned int BinaryRead(void* p, unsigned int bytes, unsigned int* sizes, unsigned int n)
    {
        unsigned int r = m_pfnRead(this, p, bytes, sizes, n);
        m_uiPos += r;
        return r;
    }
};
template <class T> static __forceinline void BinLoad(BinX* b, T* v, unsigned int n = 1)
{
    unsigned int sz = sizeof(T);
    b->BinaryRead(v, n * sizeof(T), &sz, n);
}
template <class T> static __forceinline void BinRead(Stream* s, T* v)
{
    BinLoad((BinX*)s->m_pkBin, v);
}
static __forceinline void SetBits(unsigned short& f, unsigned int v, unsigned int mask, unsigned int shift)
{
    f = (unsigned short)((f & ~mask) | (v << shift));
}
// @fnv 0x00a5f2b0
void __fastcall ReadFromStream(NiVertexColorProperty* self, void*, Stream* apStream)
{
    self->NiProperty::LoadBinary(*reinterpret_cast<NiStream*>(apStream));
    if (apStream->m_uiFormatVersion < 0xa000102)
        self->m_uiObjectFlags = apStream->m_usFlags & 7;
    else
        BinRead(apStream, &self->m_uiObjectFlags);
    if (apStream->m_uiFormatVersion < 0x14010002)
    {
        {
            unsigned int uiFlags;
            BinRead(apStream, &uiFlags);
            SetBits(self->m_uiObjectFlags, uiFlags, 0x30, 4);
        }
        {
            unsigned int b;
            BinRead(apStream, &b);
            SetBits(self->m_uiObjectFlags, b, 0x08, 3);
        }
    }
}
}
