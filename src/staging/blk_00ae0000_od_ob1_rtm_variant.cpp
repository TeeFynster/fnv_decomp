// src/staging/blk_00ae0000_od_ob1_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00ae0000_od.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /Od /Ob1 /Oy- /GS /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/staging/blk_00ae0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/BSAudio.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiPoint3.h"
extern int DAT_010a42b4;
void* __cdecl _fnv_zlib_memset(void* p, int c, unsigned int n);
struct FUN_00af30a0_Class
{
    void* vtbl;
    char m_acCharacterBuffer[128];
    void* m_pObjectAt84;
    void* m_pObjectAt88;
    char bVisible;
    int m_iValueAt90;
    char m_cValueAt94;
    char m_cValueAt95;
    void* BSSystemUtility_BSSystemUtility();
};
struct FUN_00ae8dc0_Class
{
    bool IsEqual(int a, int b);
};
extern "C" long __cdecl _fseek(void* stream, long offset, int whence);
long __cdecl Object_SeekStreamIfPresent(void* stream, long offset, int whence, int iWhenceArg);
extern int DAT_010a39d8;
struct FUN_00ad7000_stub
{
    void FUN_00ad7000();
};
struct FUN_00aea210_Class
{
    void* vtbl;
    void SetVtableAndProcessState_00aea210();
};
struct FUN_00aea890_Class
{
    void* vtbl;
    int m_kPointA;
    int m_kPointB;
    int* BSWin32AudioListener_GetPosition();
};
extern int DAT_010a3bb4;
struct FUN_00aeaab0_Class
{
    void* vtbl;
    char m_acCharacterBuffer[64];
    void* m_pObjectAt84;
    void* m_pObjectAt88;
    char bVisible;
    int m_iValueAt90;
    void SetVtableAndProcessState_00aeaab0();
};
extern "C" long __cdecl _fseek(void* stream, long offset, int whence);
long __cdecl Runtime_SeekStreamOrFail_00af1cf0(void* stream, long offset, int whence, int iWhenceArg);
extern int DAT_010a4288;
struct FUN_00af2f20_Class
{
    void __thiscall SetVirtualTable_00af2f20();
};
struct FUN_00af3120_Class
{
    void __thiscall SetVirtualTable_00af3120();
};
extern int DAT_010a42cc;
struct FUN_00af33f0_Class
{
    void* vtbl;
    int x;
    void* SetVtableAndProcessState_00af33f0();
};
extern int DAT_010a42cc;
struct FUN_00af3420_Class
{
    void* vtbl;
    void __thiscall SetVirtualTable_00af3420();
};
extern int DAT_010a42dc;
struct FUN_00af35c0_Class
{
    void* vtbl;
    void SetVirtualTable_00af35c0();
};
extern int DAT_010a42ec;
struct FUN_00af38d0_Class
{
    void* vtbl;
    char bVisible;
    void* m_pObjectAt84;
    void* BSCacheDriveSystemUtility_BSCacheDriveSystemUtility();
};
extern int DAT_010a42fc;
struct FUN_00af39c0_Class
{
    void* vtbl;
    void SetVirtualTable_00af39c0();
};
extern int DAT_010a4318;
struct FUN_00af3a80_Class
{
    void* p;
    void InitPointer();
};
extern int DAT_010a4328;
struct FUN_00af3b20_Class
{
    void* vtbl;
    int i;
    void* __thiscall BSSysInfoSystemUtility_BSSysInfoSystemUtility();
};
extern int DAT_010a4328;
struct FUN_00af3b50_Class
{
    void __thiscall SetVTable();
};
void __cdecl SwapByteQuadWords(void* p, int a2);
struct FUN_00afd960_Class
{
    void* vtbl;
    int iField;
    void ProcessState_00afd960();
};
struct FileFinder
{
    static NiFile* __cdecl GetFile(const char*, int, unsigned int, unsigned int);
};
void __cdecl FileFinder_GetFile_(const char* apPath, int b, unsigned int c);
extern int DAT_010a39d8;
struct FUN_00ad6f40_Class
{
    void FUN_00ad6f40();
};
struct FUN_00aea1b0_Class
{
    void* vtbl;
    int x;
    void* FUN_00ad6f40();
    FUN_00aea1b0_Class();
};
extern int DAT_010a3b7c;
struct FUN_00aea730_Class
{
    void* vtbl;
    int m_kPointA;
    int m_kPointB;
    FUN_00aea730_Class* BSWin32AudioListener_BSWin32AudioListener(int v);
};
extern MemoryManager g_memoryManager;
struct FUN_00aeaa80_Class
{
    void __thiscall FUN_00aea770();
    void* __thiscall FUN_00aeaa80(unsigned int flags);
};
struct FUN_00aefcf0_Class
{
    void* vtbl;
    void __thiscall BSWin32GameSound_SetEmitterPosition_00aefcf0(float a, float b, float c);
};
struct FUN_00af1d20_Class
{
    void* BSWin32GameSound_OggVorbisFile_OggVorbisFile();
};
int __cdecl CloseAndDeleteFile(BSFile* apFile);
struct DownloadableContentManager
{
    static void __cdecl GetRandomGenerator();
};
char __cdecl Runtime_EvaluateValue_00af2750();
struct FUN_00af2c50_Class
{
    bool return_0_5(int a, int b);
};
extern int DAT_010a42dc;
struct FUN_00af3570_Class
{
    void* vtbl;
    int a[8];
    void* __thiscall BSSystemUtilitiesStrings_BSSystemUtilitiesStrings();
};
void __cdecl _sprintf_s(char* dst, unsigned int size, const char* fmt, ...);
struct FUN_00afd860_Class
{
    unsigned char m_acCharacterBuffer[4];
    int iValue;
    void __thiscall BSHash_MakeHashString(char* dst);
};
struct FUN_00afdbc0_Class
{
    void* vtbl;
    void* p;
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    bool IsIndexInRange(int idx);
};
extern int DAT_010a3370;
void* __cdecl _NiMalloc(unsigned int);
struct FUN_00ae7b40_Class
{
    void* vtbl;
    int iCount;
    void* pItems;
    int iCapacity;
    FUN_00ae7b40_Class(int n);
};
extern int DAT_010a3390;
void* __cdecl _NiMalloc(unsigned int);
struct FUN_00ae7bc0_Class
{
    void* vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00ae7bc0_Class(int count);
};
extern int DAT_010a33b0;
void* __cdecl NiMalloc(unsigned int size);
struct FUN_00ae7c40_Class
{
    void* __thiscall InitBuffer(int size);
};
size_t __cdecl _strlen(const char* s);
int __cdecl _strnicmp(const char* s1, const char* s2, size_t n);
int __cdecl _strcpy_s(char* dst, size_t size, const char* src);
void CopyRelativeDataPath(const char* source, char* destination, size_t size);
struct FUN_00afd8b0_Class
{
    unsigned int uiMagic;
    unsigned int uiSize;
    unsigned int uiType;
    unsigned int uiFlags;
    unsigned int uiElapsedMilliseconds;
    unsigned int uiLength;
    unsigned int uiHash;
    unsigned int uiCRC;
    unsigned short m_usPassCountLocal;
    void* __thiscall BSArchiveHeader_BSArchiveHeader();
};
extern BSAudio* DAT_011f6d98;
struct FUN_00af1ba0_Class
{
    char pad[0x198];
    void* pAudio;
    bool EnsureAudio();
};
struct S00a0d390
{
    void* vtbl;
    int pad;
    void* p;

    void __thiscall ClearAll();
    void __thiscall SetVtableAndProcessState_00ae8c30();
};
void __cdecl _NiFree(void* p);
long Runtime_SeekStreamOrFail(void* stream, long offset, int whence, int iOrigin);
struct FUN_00aefd90_Class
{
    void __thiscall BSWin32GameSound_SetEmitterFront(int a, int b, int c);
};
int __cdecl tell_func_00af2290(int apObject);
struct FUN_00af2ed0_Class
{
    void* vtbl;
    char b1;
    int i1;
    char b2;
    char pad[0x1c];
    int i2;
    char pad2[0x14];
    int i3;
    FUN_00af2ed0_Class* BSSaveDataSystemUtility_BSSaveDataSystemUtility();
};
extern int DAT_010a42ec;
struct FUN_00af3900_Class
{
    void __thiscall SetVirtualTable_00af3900();
};
struct FUN_00af3980_Class
{
    void* vtbl;
    char bVisible;
    char m_cValueAt95;
    int iCount;
    char pad[0x84c - 0xc];
    int iField084c;
    FUN_00af3980_Class();
};
struct FUN_00af3a40_Class
{
    void* vtbl;
    char bVisible;
    void* m_pObjectAt84;
    void* m_pObjectAt88;
    char m_cValueAt94;
    char m_cValueAt95;
    char pad[0x44 - 0x11];
    int m_iValueAt90;
    char c48;
    int i4c;
    void* __thiscall ResetState();
};
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);
extern int DAT_010a33d0;
struct FUN_00ae78a0_cls
{
    void* m_vtbl;
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
    void* m_h34;
    int unk38;
    int unk3C;
    void* m_h40;
    void FUN_00aa63c0();
    void CloseAudioManagerHandles();
};
struct FUN_00ae8010_node
{
    FUN_00ae8010_node* m_00;
    FUN_00ae8010_node* m_04;
    void* m_08;
};
struct FUN_00ae8010_alloc
{
    unsigned int m_uiCount;
    void FreeNode(FUN_00ae8010_node* node);
};
struct FUN_00ae8010_cls
{
    FUN_00ae8010_node* m_00;
    FUN_00ae8010_node* m_04;
    FUN_00ae8010_alloc m_08;
    void* PopFront();
};
struct FUN_00ae8010_pad
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};
struct FUNPayload_b4549
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
};
class FUN_00ae8b40_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FUNPayload_b4549 m_payload;
    FUNPayload_b4549* GetPayload(FUNPayload_b4549* out);
};
class FUN_00ae8b90_cls
{
  public:
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f(float value);

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int m_flags10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    float m_f24;

    void SetFlagAndApplyValue(bool flag);
};
struct AE91F0MapItem
{
    AE91F0MapItem* m_pkNext;
    void* m_key;
    void* m_val;
};
// NiTMapBase::RemoveAll
class AE91F0Map
{
  public:
    virtual ~AE91F0Map();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void ClearValue(AE91F0MapItem* pkItem);
    virtual void vfunc05();
    virtual void DeleteItem(AE91F0MapItem* pkItem);

    unsigned int m_uiHashSize;
    AE91F0MapItem** m_ppkHashTable;
    unsigned int m_uiCount;

    void ClearAll();
};
extern int(__stdcall* FUN_00fdf1c4)(char*);
struct S_00ae9290_Object
{
// @fnv 0x00ae9290
    virtual void FUN_00ae9290_f0()
    {}
    virtual void FUN_00ae9290_f1()
    {}
};
struct S_00ae9290_Class
{
    void* p;

    void __thiscall UpdateState_00ae9290();
};
// src: GUESS 0x00ae9290 (confidence: low)
void __thiscall S_00ae9290_Class::UpdateState_00ae9290()
{
    if (this->p != 0)
    {
        char* p = (char*)this->p;

        if (FUN_00fdf1c4(p + 4) == 0)
            ((S_00ae9290_Object*)p)->FUN_00ae9290_f1();
    }
}
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
struct FUN_00aea0a0_Class
{
    void* vtbl;
    unsigned long m_tick;
    int m_zero;

    void* __thiscall InitTimer();
};
extern "C" int(__stdcall* DAT_00fdf060)(void);
struct FUN_00aea0d0_Class
{
    void* vtbl;
    unsigned int m_kPointB;
    unsigned int m_kPointA;
    void Init();
};
struct FUN_00aea800_cls
{
    int unk00;
    void BSWin32AudioListener_Init();
};
extern "C" const double DAT_010a3be8;
struct FNVRenderInterface_00aea8b0
{
    virtual void __stdcall Function00() = 0;
    virtual void __stdcall Function04() = 0;
    virtual void __stdcall Function08() = 0;
    virtual void __stdcall Function0C() = 0;
    virtual void __stdcall Function10() = 0;
    virtual void __stdcall Function14() = 0;
    virtual void __stdcall Function18() = 0;
    virtual void __stdcall Function1C() = 0;
    virtual void __stdcall Function20() = 0;
    virtual void __stdcall Function24() = 0;
    virtual void __stdcall Function28() = 0;
    virtual void __stdcall Function2C() = 0;
    virtual void __stdcall Function30() = 0;
    virtual void __stdcall ApplyParameters(float a, float b, float c, float d, float e, float f, int enable) = 0;
    virtual void __stdcall ApplyColor(float red, float green, float blue, int enable) = 0;
    virtual void __stdcall Function3C() = 0;
    virtual void __stdcall Function40() = 0;
    virtual void __stdcall Commit() = 0;
};
struct FNVColorRenderer_00aea8b0
{
    unsigned int unknown00;
    float red;
    float blue;
    float green;
    unsigned int unknown10, unknown14, unknown18, unknown1C;
    unsigned int unknown20, unknown24, unknown28, unknown2C;
    unsigned int unknown30, unknown34, unknown38, unknown3C;
    unsigned int unknown40, unknown44;
    FNVRenderInterface_00aea8b0* renderer;
    float scale4c, scale50, scale54;
    float scale58, scale5c, scale60;
    void ApplyToRenderer();
};
struct S_00aea990_Triple
{
    int unk00;
    int unk04;
    int unk08;
};
struct S_00aea990_Class
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
    S_00aea990_Triple unk4c;
    S_00aea990_Triple unk58;

    void __thiscall CopyTriplePair(int* p, int* q);
};
struct FUN_00aea9d0_Listener
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void __stdcall vf3C(float value, int flag)
    {}
};
struct FUN_00aea9d0_Obj
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
    FUN_00aea9d0_Listener* unk48;

    void __thiscall NotifyListenerValue(float value);
};
struct S_00aeaa10_P3
{
    float x;
    float y;
    float z;
};
struct S_00aeaa10_Obj
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void __stdcall FUN_x40(float x, float y, float z, bool flag);
};
struct S_00aeaa10_Cls
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
    S_00aeaa10_P3 pos;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    S_00aeaa10_Obj* obj;
    void BSWin32AudioListener_SetVelocity(const S_00aeaa10_P3* p);
};
void* __cdecl _fnv_zlib_memset(void* p, int c, int n);
struct MMStub
{
    void* __thiscall Allocate(unsigned int size);
};
extern MMStub g_mmStub;
extern const NiPoint3 NiPoint3_ZERO;
struct Stub1A4
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* pBuf;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct FUN_00ae9360_Base
{
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
    FUN_00ae9360_Base();
    virtual ~FUN_00ae9360_Base();
};
struct FUN_00aeae10 : public FUN_00ae9360_Base
{
    int unk198;
    int unk19C;
    int unk1A0;
    Stub1A4 unk1A4;
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
    unsigned short unk20C;
    unsigned short unk20E;
    unsigned short unk210;
    unsigned short unk212;
    unsigned short unk214;
    unsigned short unk216;
    NiPoint3 unk218;
    char unk224;
    int unk228;
    int unk22C;
    FUN_00aeae10();
    virtual ~FUN_00aeae10();
};
struct SndGuid
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};
struct SndEffectDesc
{
    unsigned long dwSize;
    unsigned long dwFlags;
    SndGuid guidDSFXClass;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
};
struct SndWaveFormat
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned long nSamplesPerSec;
    unsigned long nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};
struct SndBufferDesc
{
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwBufferBytes;
    unsigned long dwReserved;
    SndWaveFormat* lpwfxFormat;
    SndGuid guid3DAlgorithm;
};
struct SndUnknown
{
    virtual long __stdcall QueryInterface(const SndGuid* riid, void* ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct SndParamObject : public SndUnknown
{
    virtual long __stdcall SetAllParameters(const void* params);
};
struct SndBuffer : public SndUnknown
{
    virtual long __stdcall GetCaps(void* caps);
    virtual long __stdcall GetCurrentPosition(unsigned long* a, unsigned long* b);
    virtual long __stdcall GetFormat(void* a, unsigned long b, unsigned long* c);
    virtual long __stdcall GetVolume(long* v);
    virtual long __stdcall GetPan(long* v);
    virtual long __stdcall GetFrequency(unsigned long* v);
    virtual long __stdcall GetStatus(unsigned long* v);
    virtual long __stdcall Initialize(void* a, void* b);
    virtual long __stdcall Lock(unsigned long offset, unsigned long bytes, void** p1, unsigned long* b1, void** p2,
                                unsigned long* b2, unsigned long flags);
    virtual long __stdcall Play(unsigned long a, unsigned long b, unsigned long c);
    virtual long __stdcall SetCurrentPosition(unsigned long a);
    virtual long __stdcall SetFormat(void* a);
    virtual long __stdcall SetVolume(long v);
    virtual long __stdcall SetPan(long v);
    virtual long __stdcall SetFrequency(unsigned long v);
    virtual long __stdcall Stop();
    virtual long __stdcall Unlock(void* p1, unsigned long b1, void* p2, unsigned long b2);
    virtual long __stdcall Restore();
    virtual long __stdcall SetFX(unsigned long count, SndEffectDesc* desc, unsigned long* results);
    virtual long __stdcall AcquireResources(unsigned long a, unsigned long b, unsigned long* c);
    virtual long __stdcall GetObjectInPath(const SndGuid* obj, unsigned long idx, const SndGuid* iid, void* out);
};
struct Snd3DBuffer : public SndUnknown
{
    virtual long __stdcall GetAllParameters(void* a);
    virtual long __stdcall GetConeAngles(unsigned long* a, unsigned long* b);
    virtual long __stdcall GetConeOrientation(void* a);
    virtual long __stdcall GetConeOutsideVolume(long* a);
    virtual long __stdcall GetMaxDistance(float* a);
    virtual long __stdcall GetMinDistance(float* a);
    virtual long __stdcall GetMode(unsigned long* a);
    virtual long __stdcall GetPosition(void* a);
    virtual long __stdcall GetSourceVelocity(void* a);
    virtual long __stdcall SetAllParameters(const void* a, unsigned long b);
    virtual long __stdcall SetConeAngles(unsigned long a, unsigned long b, unsigned long c);
    virtual long __stdcall SetConeOrientation(float a, float b, float c, unsigned long d);
    virtual long __stdcall SetConeOutsideVolume(long a, unsigned long b);
    virtual long __stdcall SetMaxDistance(float a, unsigned long b);
    virtual long __stdcall SetMinDistance(float a, unsigned long b);
};
struct SndDevice : public SndUnknown
{
    virtual long __stdcall CreateSoundBuffer(SndBufferDesc* desc, SndBuffer** out, void* outer);
};
struct SndStream
{
    int iState;
    unsigned int uiPos;
    unsigned int uiHeadSize;
    unsigned int uiBodySize;
    unsigned int uiTailSize;
    unsigned int uiTailPos;
    char* pHead;
    char* pBody;
    char* pTail;
};
struct SndHeap
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
struct SndFloatHolder
{
    int unk00;
    float fValue;
};
extern SndHeap g_SndHeap;
extern SndFloatHolder g_SndFloatHolder;
extern float g_fSndZeroFallback;
extern float g_fSndMinDistance;
extern float g_fSndConeValue;
extern float g_fSnd150;
extern float g_fSndReverb1;
extern float g_fSndReverb2;
extern const SndGuid g_IID_SndBuffer8;
extern const SndGuid g_IID_Snd3DBuffer;
extern const SndGuid g_GUID_SndFX;
extern const SndGuid g_IID_SndFXParams;
void* __cdecl SndMemCopy(void* dst, const void* src, unsigned int n);
void* __cdecl SndMemSet(void* dst, int c, unsigned int n);
void __cdecl SndLog(const char* fmt, ...);
class FUN_00aec530_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void SetVolume(float f);
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void SetPosition(float x, float y, float z);

    void Release(int a);
    bool IsStreaming();
    bool IsLooping();
    void UpdateFlags();
    void UpdateDistance();
    void BSWin32GameSound_Prepare();

    int unk04;
    unsigned int m_uiValue1;
    int unk0C;
    int unk10;
    int m_iValueAt14;
    int unk18;
    short unk1C;
    short m_sFrequency;
    int unk20;
    float m_fPlaybackVolume;
    int unk28;
    int unk2C;
    int unk30;
    short unk34;
    char m_cFileName[0x11A];
    float m_fUnk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int m_iLoopStart;
    int m_iLoopEnd;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    SndDevice* m_pDirectInputDevice;
    SndBuffer* m_pBuffer8;
    int unk1A0;
    SndBufferDesc m_kDesc;
    char* m_pData;
    SndBuffer* m_pBuffer;
    int unk1D0;
    Snd3DBuffer* m_p3DBuffer;
    int unk1D8;
    unsigned int m_uiSize;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    float m_afReverb[5];
    int unk204;
    SndParamObject* m_pReverb;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    SndStream* m_pBinaryStream;
};
class S_Subsys
{
  public:
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual int __stdcall Query();
};
class FUN_00aed420_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
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
    S_Subsys* m_198;
    S_Subsys* m_19c;
    S_Subsys* m_1a0;
    bool BSWin32GameSound_Pause();
};
struct IDSBufStub
{
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetCaps(void*);
    virtual long __stdcall GetCurrentPosition(unsigned long*, unsigned long*);
    virtual long __stdcall GetFormat(void*, unsigned long, unsigned long*);
    virtual long __stdcall GetVolume(long*);
    virtual long __stdcall GetPan(long*);
    virtual long __stdcall GetFrequency(unsigned long*);
    virtual long __stdcall GetStatus(unsigned long*);
    virtual long __stdcall Initialize(void*, void*);
    virtual long __stdcall Lock(unsigned long, unsigned long, void**, unsigned long*, void**, unsigned long*,
                                unsigned long);
    virtual long __stdcall Play(unsigned long, unsigned long, unsigned long);
    virtual long __stdcall SetCurrentPosition(unsigned long);
    virtual long __stdcall SetFormat(const void*);
    virtual long __stdcall SetVolume(long);
    virtual long __stdcall SetPan(long);
    virtual long __stdcall SetFrequency(unsigned long);
    virtual long __stdcall Stop();
};
struct AudioSoundStub
{
    void* vtbl;
    int unk04;
    unsigned int uiFlags;
    int unk0c;
    unsigned int uiState;
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
    void* pAudio198;
    IDSBufStub* pBuffer;
    IDSBufStub* pBuffer3D;
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
    int* pStatus;

    bool BSWin32GameSound_Stop();
};
struct S_00af01e0_Snd
{
    virtual int __stdcall v00();
    virtual int __stdcall v04();
    virtual int __stdcall v08();
    virtual int __stdcall v0c();
    virtual int __stdcall v10();
    virtual int __stdcall v14();
    virtual int __stdcall v18();
    virtual int __stdcall v1c();
    virtual int __stdcall v20();
    virtual int __stdcall v24();
    virtual int __stdcall v28();
    virtual int __stdcall v2c();
    virtual int __stdcall v30();
    virtual int __stdcall v34();
    virtual int __stdcall v38();
    virtual int __stdcall v3c();
    virtual int __stdcall v40();
    virtual int __stdcall v44(unsigned int b);
};
struct S_00af01e0_Cls
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    short unk158;
    unsigned short unk15a;
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
    S_00af01e0_Snd* unk19c;
    int BSWin32GameSound_SetFrequency(float f);
};
extern "C" void* fnv_zlib_memset(void* dst, int c, int n);
void Warning_005b5e40(const char* pcFormat, ...);
struct AF0320WaveFormat
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned int nSamplesPerSec;
    unsigned int nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};
struct AF0320SoundBuffer
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetCaps(void* pCaps);
    virtual long __stdcall GetCurrentPosition(unsigned int* pPlay, unsigned int* pWrite);
    virtual long __stdcall GetFormat(AF0320WaveFormat* pFormat, unsigned int uiSize, unsigned int* puiWritten);
    virtual long __stdcall GetVolume(long* plVolume);
    virtual long __stdcall GetPan(long* plPan);
    virtual long __stdcall GetFrequency(unsigned int* puiFrequency);
    virtual long __stdcall GetStatus(unsigned int* puiStatus);
    virtual long __stdcall Initialize(void* pDS, void* pDesc);
    virtual long __stdcall Lock(unsigned int a, unsigned int b, void** c, unsigned int* d, void** e, unsigned int* f,
                                unsigned int g);
    virtual long __stdcall Play(unsigned int a, unsigned int b, unsigned int c);
    virtual long __stdcall SetCurrentPosition(unsigned int uiPosition);
};
class AF0320Sound
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int m_iDurationMs;
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
    AF0320SoundBuffer* m_pCacheEntry;

    void SeekToPosition(unsigned int uiPositionMs);
};
struct FUN_00af13f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_flags10;
    void SetFlag20000(unsigned char enable);
};
extern int DAT_011f7128;
struct FUN_00af1af0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    void* m_1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    void* m_1d8;
    void BSWin32GameSound_RemoveEffects();
};
struct NiStdObject
{
    virtual void __stdcall v00() = 0;
    virtual void __stdcall v01() = 0;
    virtual int __stdcall v02() = 0;
    virtual void __stdcall v03() = 0;
    virtual void __stdcall v04() = 0;
    virtual void __stdcall v05() = 0;
    virtual void __stdcall v06() = 0;
    virtual void __stdcall v07() = 0;
    virtual void __stdcall v08() = 0;
    virtual void __stdcall v09() = 0;
    virtual void __stdcall v10() = 0;
    virtual void __stdcall v11() = 0;
    virtual void __stdcall v12() = 0;
    virtual void __stdcall v13() = 0;
    virtual void __stdcall v14() = 0;
    virtual void __stdcall v15() = 0;
    virtual void __stdcall v16() = 0;
    virtual void __stdcall v17() = 0;
    virtual void __stdcall v18() = 0;
};
struct S_00af1c00_Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual int __stdcall v2c(unsigned int, unsigned int, void**, void**, int, int, int);
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual int __stdcall v4c(void*, void*, int, int);
};
void __cdecl FUN_00ec44d0(void*, const void*, unsigned int);
void __cdecl FUN_00ec61c0(void*, int, unsigned int);
struct S_00af1c00_cls
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
    S_00af1c00_Obj* m_19c;
    bool BSWin32GameSound_Write(int a1, unsigned int a2, unsigned int a3, char* a4);
};
struct FUN_00af1d80_tgt
{
    virtual int Tick(int flag);
};
void __cdecl ov_clear_00ee81e6(void* self);
struct FUN_00af1d80_cls
{
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
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    FUN_00af1d80_tgt* m_2d0;
    int unk2d4;
    int unk2d8;
    unsigned char m_2dc;
    void UpdateAndReleaseTarget();
};
struct FUN_00af2100_cls
{
    unsigned int BSWin32GameSound_OggVorbisFile_Read(unsigned char* p, unsigned int n);
};
unsigned int __cdecl ov_read_00ee8204(FUN_00af2100_cls* self, unsigned char* p, unsigned int n, unsigned int a,
                                  unsigned int b, unsigned int c, unsigned int* out);
typedef int(__cdecl* FUN_00af2180_ProcFn)(void* self, void* arg0, int product, int* out, int one);
struct FUN_00af2180_cls
{
    int unk00;
    int m_04;
    FUN_00af2180_ProcFn m_08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    unsigned char m_2c;
};
int __cdecl CallProcAndAccumulate(void* arg0, int iLeft, int iRight, FUN_00af2180_cls* p);
class AF2200Handler
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void Handle(void* pvEvent, void* pvData);
};
int DispatchHandlerEvent(void* pvHandler, void* pvEvent, void* pvUnused, void* pvData);
struct FUN_00af2c30_cls
{
    int unk00;
    void nullsub_324();
};
struct FUN_00af2c60_cls
{
    void* vtbl;
    void __thiscall nullsub_325();
};
// FUN_00af2c70 - an empty __thiscall member function in an /Od module.
//
// The original is 11 bytes:
//   55           push ebp
//   8b ec        mov  ebp, esp
//   51           push ecx
//   89 4d fc     mov  dword ptr [ebp-4], ecx   <- the /Od spill of `this`
//   8b e5        mov  esp, ebp
//   5d           pop  ebp
//   c3           ret
//
// Under /Od MSVC 2008 always gives a member function a frame and always
// homes `this` at [ebp-4]; with no locals at all the frame is just the
// single `push ecx`, which is why the epilogue is `mov esp,ebp; pop ebp; ret`
// instead of a bare `pop ebp; ret`.
//
// The class name is deliberately tag-free so that the tag appears exactly
// once, in the mangled name of the member function itself.
struct FnvEmptyThiscall70_Class
{
    void nullsub_326();
};
// FUN_00af2c80 - an empty __thiscall member function in an /Od module.
//
// The original is 11 bytes:
//   55           push ebp
//   8b ec        mov  ebp, esp
//   51           push ecx
//   89 4d fc     mov  dword ptr [ebp-4], ecx   <- the /Od spill of `this`
//   8b e5        mov  esp, ebp
//   5d           pop  ebp
//   c3           ret
//
// Under /Od MSVC 2008 always gives a member function a frame and always
// homes `this` at [ebp-4]; with no locals at all the frame is just the
// single `push ecx`, which is why the epilogue is `mov esp,ebp; pop ebp; ret`
// instead of a bare `pop ebp; ret`.
struct FnvEmptyThiscall_Class
{
    void DoNothing_00af2c80();
};
extern "C" __declspec(dllimport) bool __cdecl SteamAPI_IsSteamRunning();
extern "C" __declspec(dllimport) unsigned int __cdecl SteamUser();
struct SteamUserObj
{
    virtual void v0();
    virtual bool v1();
};
typedef void(__cdecl* FUN_00af2db0_Notify)(int code, int value);
struct FUN_00af2db0_cls
{
    unsigned char m_flag00;
    FUN_00af2db0_Notify m_pfnNotify;
    void UpdateSteamRunningFlag();
};
extern "C" int __cdecl toupper(int c);
extern unsigned int g_uiMatchFlags;
int __cdecl WildcardMatch(const char* pcString, const char* pcPattern);
bool HasWildcardChars(const char* pcString);
int __cdecl FUN_00ec3bad(int value);
struct AllocatorToken
{
    unsigned char state;
};
struct FUN_00afd920_Class
{
    int value;
    void __thiscall UpdateValue();
};
struct AFD980Value
{
    unsigned __int64 m_uiCurrentValue;

    void ReverseBytes();
};
struct Flag
{
    bool m_kPointB;
};
struct FUN_00afdb80_cls
{
    char pad00[8];
    unsigned int* m_08;

    void UpdateFields_00afdb80();
};
unsigned int* __cdecl FUN_00ec3bad(unsigned int* value);
struct FUN_00afdc00_Item
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    bool Test(int idx);
};
class FUN_00afdc00_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_uiItemCount;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    FUN_00afdc00_Item* m_pItems;
    bool BSArchive_IsFileEntryInArchive(int a1);
};
struct S_00aff060_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;

    int __thiscall BSSystemFile_DoFlush();
};
extern int(__stdcall* DAT_00fdf138)(void*);
extern "C" __declspec(dllimport) int __stdcall CopyFileA(const char* lpExistingFileName, const char* lpNewFileName,
                                                         unsigned char bFailIfExists);
int __cdecl CopyFileChecked(const char* lpExistingFileName, const char* lpNewFileName, unsigned char bFailIfExists);
struct BucketTableStorage
{
    struct Node
    {
        Node* next;
    };
    unsigned int bucketCount;
    Node** data;
    unsigned int count;
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void FreeItem(Node*);
    virtual void unk14();
    virtual void FreeNode(Node*);

    void ClearAll()
    {
        for (unsigned int i = 0; i < bucketCount; ++i)
        {
            while (data[i])
            {
                Node* node = data[i];
                data[i] = data[i]->next;
                FreeItem(node);
                FreeNode(node);
            }
        }
        count = 0;
    }
};
struct FUN_00ae8ce0 : BucketTableStorage
{
    virtual ~FUN_00ae8ce0();
};
struct FUN_00ae8d90
{
    int* m_vtbl;
    int m_auiShapeKeys;
    void* m_data;
    ~FUN_00ae8d90();
};
struct AudioVoice
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void __stdcall SetMinDistance(float dist, int flags);
    virtual void __stdcall SetMaxDistance(float dist, int flags);
};
struct SoundObj
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void SetPosition(NiPoint3 pos);

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
    float minDistance;
    float maxDistance;
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
    void* unk198;
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
    AudioVoice* voice;
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
    NiPoint3 position;
    bool is3D;

    bool IsPlaying();
    void BSWin32GameSound_SetMinMax(float maxDist, float minDist);
};
extern const double DAT_010a3e68;
extern const double DAT_010a3e60;
double FUN_00ecbc80(double);
struct AudioAttenuation
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
    short first;
    short second;
    short third;
    short fourth;
    short fifth;
    void SetAttenuationValues(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
};
class CAF0290SoundBuffer
{
  public:
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetCaps(void* pCaps);
    virtual long __stdcall GetCurrentPosition(unsigned long* pulPlay, unsigned long* pulWrite);
    virtual long __stdcall GetFormat(void* pFormat, unsigned long ulSize, unsigned long* pulWritten);
    virtual long __stdcall GetVolume(long* plVolume);
    virtual long __stdcall GetPan(long* plPan);
    virtual long __stdcall GetFrequency(unsigned long* pulFrequency);
};
class CAF0290Sound
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
    unsigned short unk158;
    unsigned short m_usBaseFrequency;
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
    void* m_pvPlaying;
    CAF0290SoundBuffer* m_pCacheEntry;

    float GetFrequencyRatio();
};
struct AudioFile
{
    virtual AudioFile* Destroy(unsigned int);
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Seek(int offset, int origin);
    int position;
    int(__cdecl* read)(AudioFile*, void*, int, int*, int);
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    bool valid;
    __forceinline bool IsValid()
    {
        return valid;
    }
    char unk2d;
    short unk2e;
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
};
struct AudioState
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
    int position;
    AudioFile* file;
};
AudioFile* __cdecl OpenAudioFile(const char*, int, unsigned int, unsigned int);
void __cdecl AudioWarning(const char*, ...);
extern int DAT_010a2484;
extern int DAT_010a2480;
extern int DAT_010a2488;
int __stdcall AudioFileOp(AudioState* state, unsigned int op, void* data, int size);
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* lpFileName, unsigned long dwDesiredAccess,
                                                             unsigned long dwShareMode, void* lpSecurityAttributes,
                                                             unsigned long dwCreationDisposition,
                                                             unsigned long dwFlagsAndAttributes, void* hTemplateFile);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
struct S_008785e0
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    unsigned char m_unk0c;
    unsigned char m_unk0d;
    unsigned char m_unk0e;
    unsigned char m_unk0f;
    void* m_unk10;

    int BSSystemFile_DoSeek(int a1, int a2, int a3, int a4);
    int OpenFile(const char* lpFileName);
};
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* lpBuffer, unsigned long nNumberOfBytesToRead,
                                                        unsigned long* lpNumberOfBytesRead, void* lpOverlapped);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
typedef unsigned long DWORD;
typedef void* HANDLE;
enum
{
    ERROR_SUCCESS = 0,
    ERROR_FILE_NOT_FOUND = 2,
    ERROR_PATH_NOT_FOUND = 3,
    ERROR_WRITE_PROTECT = 19
};
struct Win32ReadFile
{
    void* pVtable;
    int unk04;
    int unk08;
    bool bInvalid;
    HANDLE hFile;

    int Read(void* apBuffer, unsigned int auiSize, int aiUnused, unsigned __int64* apuiRead);
};
class FUN_00aff090_cls
{
  public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0C;
    HANDLE m_hHandle;
    void CloseHandleWrapper();
};
struct FUN_00aee580_wfx
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned short nSamplesPerSecLo;
    unsigned short nSamplesPerSecHi;
    unsigned short nAvgBytesPerSecLo;
    unsigned short nAvgBytesPerSecHi;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};
struct FUN_00aee580_buf
{
    virtual long __stdcall QueryInterface(void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps(void* pCaps) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned int* pdwPlay, unsigned int* pdwWrite) = 0;
    virtual long __stdcall GetFormat(FUN_00aee580_wfx* pFormat, unsigned int dwSize, unsigned int* pdwWritten) = 0;
    virtual long __stdcall GetVolume(long* plVolume) = 0;
    virtual long __stdcall GetPan(long* plPan) = 0;
    virtual long __stdcall GetFrequency(unsigned int* pdwFrequency) = 0;
    virtual long __stdcall GetStatus(unsigned int* pdwStatus) = 0;
    virtual long __stdcall Initialize(void* pDS, void* pDesc) = 0;
    virtual long __stdcall Lock(unsigned int dwOffset, unsigned int dwBytes, void** ppv1, unsigned int* pdw1,
                                void** ppv2, unsigned int* pdw2, unsigned int dwFlags) = 0;
    virtual long __stdcall Play(unsigned int dwReserved, unsigned int dwPriority, unsigned int dwFlags) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned int dwNewPosition) = 0;
    virtual long __stdcall SetFormat(FUN_00aee580_wfx* pFormat) = 0;
    virtual long __stdcall SetVolume(long lVolume) = 0;
    virtual long __stdcall SetPan(long lPan) = 0;
    virtual long __stdcall SetFrequency(unsigned int dwFrequency) = 0;
    virtual long __stdcall Stop() = 0;
};
struct FUN_00aee580_stream
{
    int iState;
    unsigned int uiElapsedMilliseconds;
    unsigned int uiEnd;
    unsigned int uiWrap;
    unsigned int uiLength;
    unsigned int uiLastPos;
    char* pData18;
    char* pData1C;
    char* pData20;
};
struct FUN_00aee580_audio
{
    int pad[5];
    unsigned int ulFadeStartTimeTick;
    int pad18;
    unsigned int uiFlags;
};
struct FUN_00aee580_cls
{
    virtual void v00();
    virtual bool v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30(int iArg);
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    int unk04;
    unsigned int uiFlags08;
    int unk0c;
    unsigned int uiFlags10;
    int iSize;
    int pad18[(0x15c - 0x18) / 4];
    unsigned int m_uiState;
    int iVolume;
    int pad164[(0x198 - 0x164) / 4];
    void* p198;
    FUN_00aee580_buf* pBuffer;
    int pad1a0[(0x1dc - 0x1a0) / 4];
    unsigned int uiBufferSize;
    int pad1e0[(0x228 - 0x1e0) / 4];
    FUN_00aee580_stream* pStream;
    bool UpdateStreamBuffer(int iArg);
};
extern double DAT_010290f8;
extern int DAT_01000000;
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
struct FUN_00aea150_Class
{
    unsigned int unk00;
    unsigned int unk04;
    int unk08;

    void BSAudioSynchTimer_Restart();
};
struct xFlags
{
    unsigned int u;
};
struct xMMCKINFO
{
    unsigned int ckid;
    unsigned int cksize;
    unsigned int fccType;
    unsigned int dwDataOffset;
    unsigned int dwFlags;
};
struct xMMIOINFO
{
    unsigned int dwFlags;
    unsigned int fccIOProc;
    void* pIOProc;
    unsigned int wErrorRet;
    void* htask;
    int cchBuffer;
    char* pchBuffer;
    char* pchNext;
    char* pchEndRead;
    char* pchEndWrite;
    int lBufOffset;
    int lDiskOffset;
    unsigned int adwInfo[3];
    unsigned int dwReserved1;
    unsigned int dwReserved2;
    void* hmmio;
};
struct xPCMWAVEFORMAT
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned int nSamplesPerSec;
    unsigned int nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
};
struct xWAVEFORMATEX
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned int nSamplesPerSec;
    unsigned int nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};
struct xSamplerChunk
{
    unsigned int adwData[11];
    unsigned int m_dwLoopStart;
    unsigned int dwLoopEnd;
    unsigned int adwRest[2];
};
struct xGuid
{
    unsigned int adw[4];
};
struct xAudioSettings
{
    unsigned int adwData[8];
    unsigned int dwHardware;
    unsigned int adwRest[15];
};
struct xAudio
{
    char _pad0[0x40];
    xAudioSettings m_kSettings;
};
struct xMemoryManager
{
    void* Allocate(unsigned int uiSize);
};
extern "C" void*(__stdcall* xmmioOpen)(char* pszFile, xMMIOINFO* pInfo, unsigned int dwFlags);
extern "C" unsigned int(__stdcall* xmmioDescend)(void* h, xMMCKINFO* pck, const xMMCKINFO* pckParent,
                                                 unsigned int uFlags);
extern "C" unsigned int(__stdcall* xmmioClose)(void* h, unsigned int uFlags);
extern "C" int(__stdcall* xmmioRead)(void* h, char* pch, int cch);
extern "C" unsigned int(__stdcall* xmmioAscend)(void* h, xMMCKINFO* pck, unsigned int uFlags);
extern "C" unsigned int(__stdcall* xmmioGetInfo)(void* h, xMMIOINFO* pInfo, unsigned int uFlags);
extern "C" unsigned int(__stdcall* xmmioAdvance)(void* h, xMMIOINFO* pInfo, unsigned int uFlags);
extern "C" char* __cdecl xStrstr(char* s, const char* sub);
extern "C" int __cdecl strcpy_s(char* dst, unsigned int n, const char* src);
extern "C" void* __cdecl xMemcpy(void* d, const void* s, unsigned int n);
void xWarning(const char* fmt, ...);
long __stdcall xWavIOProc(char* a, unsigned int b, long c, long d);
extern xGuid xg_kGuid2D;
extern xGuid xg_kGuid3D;
struct xAudioPtr
{
    xAudio* p;
};
extern xAudioPtr xg_kAudio;
extern xMemoryManager xg_kMemoryManager;
struct xFmtPtr
{
    xWAVEFORMATEX* p;
};
// memset called as a __cdecl member: same pushes, but the pointer temp is numbered before the size temp
struct xMemsetTarget
{
    void* __cdecl FUN_00ec61c0(int, unsigned int);
};
struct xCharPtr
{
    char* p;
};
struct xGameSound
{
    void* m_vtbl;
    char _pad04[4];
    xFlags m_kFlags;
    char _pad0c[4];
    unsigned int m_uiFlags2;
    int m_iDuration;
    char _pad18[0x1c];
    unsigned short m_usFrequency;
    char m_acInputFilePath[0x40];
    char _pad76[0x14c - 0x76];
    unsigned int m_uiSize14c;
    char _pad150[0x15a - 0x150];
    unsigned short m_usFrequency2;
    char _pad15c[0x174 - 0x15c];
    unsigned int m_uiLoopStart;
    unsigned int m_uiLoopEnd;
    char _pad17c[0x1a4 - 0x17c];
    unsigned int m_uiDescSize;
    unsigned int m_uiDescFlags;
    unsigned int m_uiBufferBytes;
    char _pad1b0[4];
    xFmtPtr m_pDataFormat;
    xGuid m_kAlgorithm;
    xCharPtr m_pData;
    int m_iUnk1cc;
    char _pad1d0[0x1dc - 0x1d0];
    unsigned int m_uiValue5;
    bool CheckFile();
    bool Finish(bool bSuccess);
    bool TryStream();
    void ResetFile(bool b);
    bool BSWin32GameSound_Open();
};
int __cdecl FUN_00ec3bad(int value);
struct Marker
{
    char b;
};
struct FUN_00afdb20_Class
{
    int unk00;
    int unk04;
    int m_08;
    int m_0c;
    void UpdateFields_00afdb20();
};
extern "C" int DAT_010472d0;
struct FUN_009b7940_shell
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int a, unsigned int b);
};
struct FUN_00afe9f0_Class : public FUN_009b7940_shell
{
    void* SetVtableAndProcessState_00afe9f0(unsigned int a);
};
struct FUN_00ae8090_Node
{
    FUN_00ae8090_Node* next;
    FUN_00ae8090_Node* prev;
    unsigned int value;
};
struct FUN_00ae8090_Allocator
{
    unsigned int count;
    void NiTPointerAllocator_unsigned_int_Deallocate(FUN_00ae8090_Node* node);
};
struct FUN_00ae8090_Locals
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
};
class FUN_00ae8090_Class
{
  public:
    FUN_00ae8090_Node* head;
    FUN_00ae8090_Node* tail;
    FUN_00ae8090_Allocator allocator;

    unsigned int FUN_00ae7f90();
    unsigned int PopFront();
    unsigned int NiTPointerListBase_RemovePos_0(FUN_00ae8090_Node** position);
};
struct ObjC
{
    int m_00;
    int m_04;
    unsigned int m_08;
    int unk0c;
    int unk10;
    int unk14;
    char* m_18;
    char* m_1c;
};
int __cdecl FUN_00ecadb8();
struct AED080_Cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual bool v0c();
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
    virtual void v3c(float a);
    virtual void v16();
    virtual void v44(int a);
    int unk004;
    int m_08;
    int unk00c;
    int m_10;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    float m_24;
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
    int m_14c;
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
    IDSBufStub* m_198;
    IDSBufStub* m_19c;
    IDSBufStub* m_1a0;
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
    unsigned int m_1dc;
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
    ObjC* m_228;
    bool BSWin32GameSound_Write(int a1, unsigned int a2, unsigned int a3, char* a4);
    void ClearCallback();
    bool BSWin32GameSound_Play(bool p);
};
// DirectSound buffer copy and auxiliary stream-state duplication.
typedef unsigned int U32;
typedef unsigned short U16;
struct GuidValue
{
    U32 data0;
    U32 data1;
    U32 data2;
    U32 data3;
};
struct WaveFormat
{
    U16 tag;
    U16 channels;
    U32 m_uiSamplesPerSecond;
    U32 averageBytes;
    U16 blockAlign;
    U16 m_usBitsPerSample;
};
struct AudioInterface
{

    virtual long __stdcall QueryInterface(const void*, void**) = 0;

    virtual long __stdcall AddRef() = 0;

    virtual long __stdcall Release() = 0;

    virtual long __stdcall CreateBuffer(void*, void**, void*) = 0;

    virtual long __stdcall v10() = 0;

    virtual long __stdcall v14(WaveFormat*, U32, U32*) = 0;

    virtual long __stdcall v18() = 0;

    virtual long __stdcall v1c() = 0;

    virtual long __stdcall v20() = 0;

    virtual long __stdcall v24() = 0;

    virtual long __stdcall v28() = 0;

    virtual long __stdcall Lock(U32, U32, void**, U32*, void**, U32*, U32) = 0;

    virtual long __stdcall v30() = 0;

    virtual long __stdcall v34() = 0;

    virtual long __stdcall v38() = 0;

    virtual long __stdcall v3c() = 0;

    virtual long __stdcall v40() = 0;

    virtual long __stdcall SetValue(float, U32) = 0;

    virtual long __stdcall v48() = 0;

    virtual long __stdcall Unlock(void*, U32, void*, U32) = 0;
};
struct CopyState
{
    U32 idle;
    U32 active;
    U32 byteCount;
    U32 segmentSize;
    U32 thirdSize;
    U32 index;
    void* bytes;
    void* segments;
    void* third;
};
struct AudioConfig
{

    U32 m_00;

    U32 m_04;

    U32 m_08;

    U32 m_0c;

    U32 m_10;

    U32 m_14;

    U32 m_18;

    U32 m_1c;

    U32 m_20;

    U32 m_24;

    U32 m_28;

    U32 m_2c;

    U32 m_30;

    U32 m_34;

    U32 m_38;

    U32 m_3c;

    U32 m_40;

    U32 m_44;

    U32 m_48;

    U32 m_4c;

    U32 m_50;

    U32 m_54;

    U32 m_58;

    U32 m_5c;
};
struct AudioMemory
{
    void* __thiscall Game_DoHeapAlloc(U32 size);
};
struct AudioOptionsSource
{
    U32 unk00;
    U32 unk04;
    U32 unk08;
    U32 unk0c;
    U32 unk10;
    U32 unk14;
    U32 unk18;
    U32 unk1c;
    U32 unk20;
    U32 unk24;
    U32 unk28;
    U32 unk2c;
    U32 unk30;
    U32 unk34;
    U32 unk38;
    U32 unk3c;
    AudioConfig options;
};
extern AudioMemory DAT_011f6238;
extern GuidValue DAT_01093f04, DAT_01100fe4;
extern GuidValue DAT_01100f94, DAT_01100fb4;
extern const float DAT_010a3dcc;
extern const char DAT_010a4168[], DAT_010a4130[], DAT_010a40f0[], DAT_010a40b0[], DAT_010a4074[], DAT_010a4038[];
extern const char DAT_010a3ffc[], DAT_010a3fc0[], DAT_010a3f84[], DAT_010a3f48[], DAT_010a3f0c[], DAT_010a3ed0[];
extern void __cdecl FUN_00ec65a6(char*, U32, const char*);
class AudioBuffer
{

  public:
    virtual void v00() = 0;

    virtual void v04() = 0;

    virtual void v08() = 0;

    virtual void v0c() = 0;

    virtual void v10() = 0;

    virtual void v14() = 0;

    virtual void v18() = 0;

    virtual void v1c() = 0;

    virtual void v20() = 0;

    virtual void v24() = 0;

    virtual void OnCopied() = 0;

    unsigned int unk_004;

    unsigned int m_flags;

    unsigned int unk_00c;

    unsigned int m_uiContentCount;

    int m_playLength;

    unsigned int unk_018;

    unsigned int unk_01c;

    unsigned int unk_020;

    unsigned int unk_024;

    unsigned int unk_028;

    unsigned int unk_02c;

    unsigned int unk_030;

    unsigned short m_sampleRate;
    unsigned short m_unused36;

    unsigned int unk_038;

    unsigned int unk_03c;

    unsigned int unk_040;

    unsigned int unk_044;

    unsigned int unk_048;

    unsigned int unk_04c;

    unsigned int unk_050;

    unsigned int unk_054;

    unsigned int unk_058;

    unsigned int unk_05c;

    unsigned int unk_060;

    unsigned int unk_064;

    unsigned int unk_068;

    unsigned int unk_06c;

    unsigned int unk_070;

    unsigned int unk_074;

    unsigned int unk_078;

    unsigned int unk_07c;

    unsigned int unk_080;

    unsigned int unk_084;

    unsigned int unk_088;

    unsigned int unk_08c;

    unsigned int unk_090;

    unsigned int unk_094;

    unsigned int unk_098;

    unsigned int unk_09c;

    unsigned int unk_0a0;

    unsigned int unk_0a4;

    unsigned int unk_0a8;

    unsigned int unk_0ac;

    unsigned int unk_0b0;

    unsigned int unk_0b4;

    unsigned int unk_0b8;

    unsigned int unk_0bc;

    unsigned int unk_0c0;

    unsigned int unk_0c4;

    unsigned int unk_0c8;

    unsigned int unk_0cc;

    unsigned int unk_0d0;

    unsigned int unk_0d4;

    unsigned int unk_0d8;

    unsigned int unk_0dc;

    unsigned int unk_0e0;

    unsigned int unk_0e4;

    unsigned int unk_0e8;

    unsigned int unk_0ec;

    unsigned int unk_0f0;

    unsigned int unk_0f4;

    unsigned int unk_0f8;

    unsigned int unk_0fc;

    unsigned int unk_100;

    unsigned int unk_104;

    unsigned int unk_108;

    unsigned int unk_10c;

    unsigned int unk_110;

    unsigned int unk_114;

    unsigned int unk_118;

    unsigned int unk_11c;

    unsigned int unk_120;

    unsigned int unk_124;

    unsigned int unk_128;

    unsigned int unk_12c;

    unsigned int unk_130;

    unsigned int unk_134;

    unsigned int unk_138;

    unsigned int unk_13c;

    unsigned int unk_140;

    unsigned int unk_144;

    unsigned int m_copy148;

    unsigned int m_copy14c;

    unsigned int unk_150;

    unsigned int unk_154;

    unsigned short m_unused158;
    unsigned short m_sampleCount;

    unsigned int unk_15c;

    unsigned int unk_160;

    unsigned int unk_164;

    unsigned int unk_168;

    unsigned int unk_16c;

    unsigned int unk_170;

    unsigned int unk_174;

    unsigned int unk_178;

    unsigned int unk_17c;

    unsigned int unk_180;

    unsigned int unk_184;

    unsigned int unk_188;

    unsigned int unk_18c;

    unsigned int unk_190;

    unsigned int unk_194;

    AudioInterface* m_device;

    AudioInterface* m_buffer;

    unsigned int m_ctrl1a0;

    unsigned int m_descSize;

    unsigned int m_descFlags;

    unsigned int m_bufferBytes;

    unsigned int unk_1b0;

    WaveFormat* m_eVertexFormat;

    GuidValue m_algo;

    unsigned int m_oldBuffer;

    AudioInterface* m_duplicate;

    unsigned int m_ctrl1d0;

    AudioInterface* m_iBufferSize;

    unsigned int m_ctrl1d8;

    unsigned int m_totalBytes;

    unsigned int unk_1e0;

    unsigned int unk_1e4;

    unsigned int unk_1e8;

    unsigned int unk_1ec;

    unsigned int unk_1f0;

    unsigned int unk_1f4;

    unsigned int unk_1f8;

    unsigned int unk_1fc;

    unsigned int unk_200;

    unsigned int unk_204;

    unsigned int unk_208;

    unsigned int unk_20c;

    unsigned int unk_210;

    unsigned int unk_214;

    unsigned int unk_218;

    unsigned int unk_21c;

    unsigned int unk_220;

    unsigned int unk_224;

    CopyState* m_copyState;

    void __thiscall FUN_00ae97a0(AudioBuffer*, bool);

    bool __thiscall SetFlagState(bool);

    __forceinline bool IsBuffered()
    {
        return (m_flags & 0x10) || (m_flags & 0x4000000) || (m_flags & 0x2000000);
    }
    __forceinline bool Any()
    {
        return (m_flags & 0x4000000) || (m_flags & 0x2000000);
    }
    void __thiscall BSWin32GameSound_Copy(AudioBuffer*, bool);
};
struct FUN_00aea020_cls
{
    int unk00;
    FUN_00aea020_cls();
    ~FUN_00aea020_cls();
};
extern BSAudio* DAT_011f6d98;
void __cdecl BSWin32Audio_Create();
struct FUN_00af33f0
{
    void* vtbl;
    int x;
    FUN_00af33f0();
    ~FUN_00af33f0();
};
void* __cdecl BSMsgDialogSystemUtility_QInstance();
namespace Worker114 {
struct FUN_00ae9360_Base
{
    virtual ~FUN_00ae9360_Base();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned short flags034;
    char fileName[260];
    unsigned short unk13a;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    FUN_00ae9360_Base();
};
}
struct Allocate114
{
    void* Game_DoHeapAlloc(unsigned int);
};
struct FUN_00aeac20 : Worker114::FUN_00ae9360_Base
{
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned short unk20c;
    unsigned short unk20e;
    unsigned short unk210;
    unsigned short unk212;
    unsigned short unk214;
    unsigned short unk216;
    NiPoint3 position218;
    unsigned char flag224;
    unsigned int unk228, unk22c;
    FUN_00aeac20(const char* name);
    virtual ~FUN_00aeac20();
};
extern "C" int __cdecl _splitpath_s(const char* source, char* drive, unsigned int driveSize, char* directory,
                                    unsigned int directorySize, char* filename, unsigned int filenameSize,
                                    char* extension, unsigned int extensionSize);
extern "C" int __cdecl _makepath_s(char* result, unsigned int resultSize, const char* drive, const char* directory,
                                   const char* filename, const char* extension);
extern unsigned int DAT_011f804c;
void __cdecl WildCard_MakeString(char* result, const char* source);
extern "C" __declspec(dllimport) int __stdcall WriteFile(void*, const void*, unsigned long, unsigned long*, void*);
struct SystemFileWriter : Win32ReadFile
{
    int BSSystemFile_DoWrite(void* buf, DWORD len, int unused, unsigned __int64* outRead);
};

namespace ListenerDestruction {
struct ListenerBase
{
    virtual ~ListenerBase() = 0;
    int state04, state08, state0c, state10;
    int state14, state18, state1c, state20;
    int state24, state28, state2c, state30;
    int state34, state38, state3c, state40;
    int environment;
};
inline ListenerBase::~ListenerBase()
{
    environment = 0;
}
struct FUN_00aea770 : ListenerBase
{
    IDSBufStub* listener;
// @fnv 0x00aea770
    virtual __declspec(noinline) ~FUN_00aea770()
    {
        if (listener)
        {
            listener->Release();
            listener = 0;
        }
    }
};
void DestroyListener(void* object)
{
    static_cast<FUN_00aea770*>(object)->FUN_00aea770::~FUN_00aea770();
}
}
