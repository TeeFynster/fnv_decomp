
// src/gamebryo2.2/corelibs/nimain/bspackedadditionalgeometrydata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/bspackedadditionalgeometrydata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
struct FakeBase
{
    void FUN_00a734c0();
};
extern int DAT_0102e1dc;
// @fnv 0x00a7f740
// src: EXE 0x00a7f740
void* BSPackedAdditionalGeometryData_CreateObject()
{
    void* p = BSFadeNode::operator new(52);
    if (p)
    {
        ((FakeBase*)p)->FUN_00a734c0();
        *(void**)p = (void*)&DAT_0102e1dc;
        ((int*)p)[11] = 0;
        ((int*)p)[12] = 0;
        return p;
    }
    return 0;
}

struct StringList
{
    int unk00;
    void** items;
    unsigned short capacity;
    unsigned short count;
    unsigned short unk0C;
    unsigned short growth;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, void*);
};
struct Owner
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
    const char* name;
    void NiAdditionalGeometryData_GetViewerStrings(StringList*);
    void AppendNameStrings(StringList*);
};
extern "C" const char* g_011f4aac;
extern const char str_0109deec[];
extern char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
extern char* __cdecl NiGetViewerString_00a7d510(const char*, const char*);
// Calls FUN_00a73e40 on list, then appends the strings from FUN_00a7d330(g_011f4aac) and FUN_00a7d510(str_0109deec, name), growing the list as needed.
// @fnv 0x00a7f780
void Owner::AppendNameStrings(StringList* list)
{
    char* text;
    unsigned int index;
    NiAdditionalGeometryData_GetViewerStrings(list);
    text = NiViewerStrings_NiGetViewerString_Title(g_011f4aac);
    index = list->count;
    if (index >= list->capacity)
        list->FUN_0096ad30(list->growth + index);
    list->FUN_0096ae90(index, &text);
    text = NiGetViewerString_00a7d510(str_0109deec, name);
    index = list->count;
    if (index >= list->capacity)
        list->FUN_0096ad30(list->growth + index);
    list->FUN_0096ae90(index, &text);
}

struct S_00a7f680_Base
{
    void NiAdditionalGeometryData_SaveBinary(void* p);
};
struct S_00a7f680_Out
{
    int unk00;
    int unk04;
    int unk08;
    int(__cdecl* unk0C)(S_00a7f680_Out*, void*, unsigned, unsigned*, int);
};

static __forceinline void S_00a7f680_Save(S_00a7f680_Out* o, void* v)
{
    unsigned sz = 4;
    o->unk04 += o->unk0C(o, v, 4, &sz, 1);
}

struct FUN_00a7f680_cls : S_00a7f680_Base
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
    void SaveFields(void* p);
};

// @fnv 0x00a7f680
void FUN_00a7f680_cls::SaveFields(void* p)
{
    NiAdditionalGeometryData_SaveBinary(p);
    S_00a7f680_Save(*(S_00a7f680_Out**)((char*)p + 0x250), &unk2c);
    S_00a7f680_Save(*(S_00a7f680_Out**)((char*)p + 0x250), &unk30);
}

class A7F6E0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A7F6E0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class A7F6E0Stream
{
  public:
    int unk000;
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
    unsigned int m_uiFileVersion;
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
    A7F6E0BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void A7F6E0BinaryStreamLoad(A7F6E0BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A7F6E0LoadBinary(A7F6E0Stream& kStream, T& value)
{
    A7F6E0BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

class A7F6E0Object
{
  public:
    void LoadBinaryBase(A7F6E0Stream& kStream);
    void LoadBinary(A7F6E0Stream& kStream);

    void* m_ppVirtualMethodTable;
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
    float m_fValue0;
    float m_fValue1;
};

// Loads the base object data from kStream, then reads m_fValue0 and m_fValue1 as binary values.
// @fnv 0x00a7f6e0
void A7F6E0Object::LoadBinary(A7F6E0Stream& kStream)
{
    LoadBinaryBase(kStream);
    A7F6E0LoadBinary(kStream, m_fValue0);
    A7F6E0LoadBinary(kStream, m_fValue1);
}
