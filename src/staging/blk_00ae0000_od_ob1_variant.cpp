#include "../../include/NiTMapItem.h"
#include "../../include/NiTListItem.h"

// src/staging/blk_00ae0000_od_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/staging/blk_00ae0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00ae0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include <stddef.h>
#pragma pack(push, 4)
#include "../../include/BSAudio.h"
#include "../../include/BSFile.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiObjPtr.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiRefObject.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
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
long __cdecl Object_SeekStreamIfPresent(void* stream, long offset, int whence, int pad);
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
long __cdecl Runtime_SeekStreamOrFail_00af1cf0(void* stream, long offset, int whence, int pad);
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
void __cdecl FileFinder_GetFile_(const char* a, int b, unsigned int c);
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
int __cdecl CloseAndDeleteFile(BSFile* f);
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
long Runtime_SeekStreamOrFail(void* stream, long offset, int whence, int pad);
struct FUN_00aefd90_Class
{
    void __thiscall BSWin32GameSound_SetEmitterFront(int a, int b, int c);
};
int __cdecl tell_func_00af2290(int param_1);
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
struct BSFileDelete : public BSFile
{
    virtual ~BSFileDelete();
    void* FUN_00afff20(unsigned int flags);
};
BSFileDelete::~BSFileDelete()
{}
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
struct S_00ae9290_Class
{
    void* p;

    void __thiscall UpdateState_00ae9290();
};
// @fnv 0x00ae9290
// src: GUESS 0x00ae9290 (confidence: low)
void __thiscall S_00ae9290_Class::UpdateState_00ae9290()
{
    if (this->p != 0)
    {
        char* p = (char*)this->p;

        if (FUN_00fdf1c4((char*)&((NiRefObject*)p)->m_uiRefCount) == 0)
            ((NiRefObject*)p)->DeleteThis();
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
int __cdecl CallProcAndAccumulate(void* arg0, int a, int b, FUN_00af2180_cls* p);
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
int __cdecl WildcardMatch(const char* str, const char* pat);
bool HasWildcardChars(const char* s);
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
class FUN_00aff180_base
{
  public:
    virtual ~FUN_00aff180_base();
    FUN_00aff180_base();
};
class FUN_00aff180 : public FUN_00aff180_base
{
  public:
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1c;
    unsigned int m_unk20;
    unsigned int m_unk24;
    unsigned int m_unk28;
    unsigned char m_unk2c;
    unsigned char m_unk2d;
    unsigned char m_unk2e;
    unsigned char m_unk2f;
    unsigned char m_unk30;
    unsigned char m_unk31;
    unsigned char m_unk32;
    unsigned char m_unk33;
    unsigned int m_unk34;
    unsigned int m_unk38;
    unsigned int m_unk3c;
    unsigned int m_unk40;
    unsigned char m_unk44;
    unsigned char m_unk45;
    unsigned char m_unk46;
    unsigned char m_unk47;
    unsigned int m_unk48;
    unsigned int m_unk4c;
    unsigned int m_unk50;
    unsigned int m_unk54;
    unsigned int m_unk58;
    unsigned int m_unk5c;
    unsigned int m_unk60;
    unsigned int m_unk64;
    unsigned int m_unk68;
    unsigned int m_unk6c;
    unsigned int m_unk70;
    unsigned int m_unk74;
    unsigned int m_unk78;
    unsigned int m_unk7c;
    unsigned int m_unk80;
    unsigned int m_unk84;
    unsigned int m_unk88;
    unsigned int m_unk8c;
    unsigned int m_unk90;
    unsigned int m_unk94;
    unsigned int m_unk98;
    unsigned int m_unk9c;
    unsigned int m_unka0;
    unsigned int m_unka4;
    unsigned int m_unka8;
    unsigned int m_unkac;
    unsigned int m_unkb0;
    unsigned int m_unkb4;
    unsigned int m_unkb8;
    unsigned int m_unkbc;
    unsigned int m_unkc0;
    unsigned int m_unkc4;
    unsigned int m_unkc8;
    unsigned int m_unkcc;
    unsigned int m_unkd0;
    unsigned int m_unkd4;
    unsigned int m_unkd8;
    unsigned int m_unkdc;
    unsigned int m_unke0;
    unsigned int m_unke4;
    unsigned int m_unke8;
    unsigned int m_unkec;
    unsigned int m_unkf0;
    unsigned int m_unkf4;
    unsigned int m_unkf8;
    unsigned int m_unkfc;
    unsigned int m_unk100;
    unsigned int m_unk104;
    unsigned int m_unk108;
    unsigned int m_unk10c;
    unsigned int m_unk110;
    unsigned int m_unk114;
    unsigned int m_unk118;
    unsigned int m_unk11c;
    unsigned int m_unk120;
    unsigned int m_unk124;
    unsigned int m_unk128;
    unsigned int m_unk12c;
    unsigned int m_unk130;
    unsigned int m_unk134;
    unsigned int m_unk138;
    unsigned int m_unk13c;
    unsigned int m_unk140;
    unsigned int m_unk144;
    unsigned int m_unk148;
    unsigned int m_unk14c;
    unsigned int m_unk150;
    FUN_00aff180();
    virtual ~FUN_00aff180();
};
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

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

inline NiObjPtr& NiObjPtr::operator=(const NiObjPtr& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = other.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

inline NiObjPtr::~NiObjPtr()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

struct AE8DE0_Record
{
    int unk00;
    int m_04;
    NiObjPtr m_08;
};

class AE8DE0_Class
{
  public:
    int unk00;

    void UpdateFields_00ae8de0(AE8DE0_Record* a1, int a2, NiObjPtr a3);
};

// @fnv 0x00ae8de0
// src: GUESS 0x00ae8de0 (confidence: low)
void AE8DE0_Class::UpdateFields_00ae8de0(AE8DE0_Record* a1, int a2, NiObjPtr a3)
{
    a1->m_04 = a2;
    a1->m_08 = a3;
}

extern int DAT_010a3308;
extern int DAT_010a33b0;
void __cdecl NiFree(void* p);

struct ScopeGuard_b10070
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    __forceinline ~ScopeGuard_b10070()
    {}
};

struct FUN_00ae8e70_cls
{
    void* vtbl;
    int unk04;
    void* m_08;

    void ClearAll();
    void SetVtableAndProcessState_00ae8e70();
};

// @fnv 0x00ae8e70
// src: GUESS 0x00ae8e70 (confidence: low)
void FUN_00ae8e70_cls::SetVtableAndProcessState_00ae8e70()
{
    *(void**)this = (void*)&DAT_010a3308;
    {
        ScopeGuard_b10070 g;
        ClearAll();
    }
    *(void**)this = (void*)&DAT_010a33b0;
    ClearAll();
    NiFree(m_08);
}

struct SoundList936
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    SoundList936()
    {
        m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }
    ~SoundList936();
};

struct FUN_00ae9360
{
    virtual void V00();
    int unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020;
    int unk024, unk028, unk02C, unk030, unk034, unk038, unk03C, unk040;
    int unk044, unk048, unk04C, unk050, unk054, unk058, unk05C, unk060;
    int unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080;
    int unk084, unk088, unk08C, unk090, unk094, unk098, unk09C, unk0A0;
    int unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0;
    int unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0;
    int unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC, unk100;
    int unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120;
    int unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140;
    int unk144, unk148, unk14C, unk150, unk154, unk158, unk15C, unk160;
    int unk164, unk168, unk16C, unk170, unk174, unk178, unk17C, unk180;
    int unk184, unk188;
    SoundList936 m_kList;

    FUN_00ae9360();
    void BSGameSound_Init();
};

// @fnv 0x00ae9360
FUN_00ae9360::FUN_00ae9360()
{
    BSGameSound_Init();
}

extern "C" double __cdecl sqrt(double);
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime();
inline float SqrtA810(float f)
{
    return (float)sqrt(f);
}
struct Pt3A810
{
    float x, y, z;
    Pt3A810()
    {}
    Pt3A810(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    Pt3A810 operator-(const Pt3A810& pt) const
    {
        return Pt3A810(x - pt.x, y - pt.y, z - pt.z);
    }
    float Length() const
    {
        return SqrtA810(x * x + y * y + z * z);
    }
};
struct SpeedA810
{
    void* vtbl;
    Pt3A810 m_pos;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    unsigned long m_lastTime;
    float m_speed;
    void BSWin32AudioListener_SetPosition(const Pt3A810& pos);
};
// @fnv 0x00aea810
// src: COMMUNITY 0x00aea810
void SpeedA810::BSWin32AudioListener_SetPosition(const Pt3A810& pos)
{
    unsigned long uiNow = timeGetTime();
    Pt3A810 kDelta = pos - m_pos;
    m_speed = kDelta.Length() / ((uiNow - m_lastTime) * 1000) * DAT_010a3be8;
    m_pos = pos;
    m_lastTime = uiNow;
}

struct WavFmt
{
    unsigned short wFormatTag;
    unsigned short wChannels;
    unsigned int dwSamplesPerSec;
    unsigned int dwAvgBytesPerSec;
    unsigned short wBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short wCbSize;
};

struct SndInfo
{
    int unk0;
    int f4;
    int f8;
};


struct AF1d80
{
    unsigned int unk000;
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
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    void* m2d0;
    int m2d4;
    SndInfo* m2d8;
    unsigned char m2dc;
    unsigned char unk2dd;
    unsigned char unk2de;
    unsigned char unk2df;
    AF1d80();
    bool BSWin32GameSound_OggVorbisFile_OpenFile(void* p);
    unsigned int BSWin32GameSound_OggVorbisFile_Read(void* p, unsigned int n);
    void UpdateAndReleaseTarget();
    ~AF1d80()
    {
        UpdateAndReleaseTarget();
    }
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }

    __forceinline int SamplesPerSec()
    {
        return this->m2d8 ? this->m2d8->f8 : 0;
    }
    __forceinline unsigned int Channels()
    {
        return this->m2d8 ? this->m2d8->f4 : 1;
    }
    __forceinline unsigned int BytesPerFrame()
    {
        return (this->m2d8 ? this->m2d8->f4 : 1) * (this->m2d4 * 2);
    }
};

struct AudioBuffer
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int m8;
    unsigned int unk00c;
    unsigned int unk010;
    int m14;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned short m34;
    char m36;
    unsigned char unk037;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    unsigned char unk158;
    unsigned char unk159;
    unsigned short m15a;
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
    unsigned int unk1a0;
    unsigned int m1a4;
    unsigned int m1a8;
    unsigned int m1ac;
    unsigned int unk1b0;
    WavFmt* m1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    void* m1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int m1dc;
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
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    AF1d80* m22c;

    __forceinline unsigned int Flags()
    {
        return this->m8;
    }
    __forceinline bool Any()
    {
        return (this->m8 & 0x4000000) || (this->m8 & 0x2000000);
    }

    __forceinline void* GetBuffer()
    {
        return this->m1c8;
    }
    __forceinline void* AllocSnd(unsigned int n)
    {
        void* p = g_memoryManager.Allocate(n);
        return p;
    }

    __forceinline bool Setup(bool& bHalf, unsigned int& nSize)
    {
        void* p;
        if (this->Any() && ((this->m8 & 0x2000) || (this->m8 & 0x1000)))
            this->m8 |= 0x10;
        this->m8 &= 0xfdffffff;
        this->m8 &= 0xfbffffff;
        bHalf = (this->Flags() & 0x400000) || (this->Flags() & 0x100000);
        nSize = 0;
        this->m1a4 = 0x24;
        this->m1b4->wCbSize = 0;
        this->m1b4->wFormatTag = 1;
        this->m1b4->dwSamplesPerSec = this->m22c->SamplesPerSec();
        this->m1b4->wBitsPerSample = 0x10;
        this->m1b4->wChannels = this->m22c->Channels();
        this->m1b4->wBlockAlign = (this->m1b4->wBitsPerSample / 8) * this->m1b4->wChannels;
        this->m1b4->dwAvgBytesPerSec = this->m1b4->dwSamplesPerSec * this->m1b4->wBlockAlign;
        this->m1ac = this->m22c->BytesPerFrame();
        this->m1dc = this->m1ac;
        if (bHalf)
            nSize = this->m1ac + (this->m1b4->dwAvgBytesPerSec >> 1);
        else
            nSize = this->m1ac;
        p = g_memoryManager.Allocate(nSize);
        this->m1c8 = p;
        _fnv_zlib_memset(this->GetBuffer(), 0, nSize);
        this->m34 = this->m1b4->dwSamplesPerSec;
        this->m15a = this->m34;
        this->m14 = this->m1dc / (2 * this->m22c->Channels()) / (this->m34 / 1000);
        this->m22c->BSWin32GameSound_OggVorbisFile_Read(this->m1c8, this->m1ac);
        if ((this->Flags() & 1) || (this->m22c->Channels() > 1))
        {
            this->m1a8 = 0x40;
            this->m8 &= 0xfffffffd;
            this->m8 |= 1;
        }
        else
        {
            this->m1a8 = 0x30010;
        }
        this->m1a8 |= 0x2a0;
        if (bHalf)
        {
            this->m1ac = this->m1ac + (this->m1b4->dwAvgBytesPerSec >> 1);
            this->m1dc = this->m1ac;
            this->m14 = this->m14 + 0x1f4;
        }
        return this->SetFlagState(true);
    }
    bool BSWin32GameSound_OpenOgg();
    bool SetFlagState(bool);
};

// @fnv 0x00aebff0
// src: COMMUNITY 0x00aebff0
bool AudioBuffer::BSWin32GameSound_OpenOgg()
{
    this->m22c = new AF1d80();
    if (!this->m22c->BSWin32GameSound_OggVorbisFile_OpenFile(&this->m36))
    {
        delete this->m22c;
        this->m22c = 0;
        return false;
    }
    bool bHalf;
    unsigned int nSize;
    return Setup(bHalf, nSize);
}

typedef NiTListItem<void* > AE8150_Node;
typedef AE8150_Node* AE8150_Pos;
struct AE8150_List
{
    AE8150_Node* m_pkHead;
    AE8150_Node* m_pkTail;
    AE8150_Pos GetHeadPos() const
    {
        return m_pkHead;
    }
    void* const& GetNext(AE8150_Pos& kPos) const
    {
        void* const& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
    AE8150_Pos FindPos(void* const& element, AE8150_Pos kPos = 0) const
    {
        if (kPos == 0)
            kPos = GetHeadPos();
        while (kPos)
        {
            AE8150_Pos kPrev = kPos;
            if (element == GetNext(kPos))
                return kPrev;
        }
        return 0;
    }
    void Reserve() const
    {
        int unused[15];
        (void)unused;
    }
    void* NiTPointerListBase_RemovePos_0(AE8150_Pos& kPos);
    void* NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSTextureManager_RenderedTextureData_RemovePos(void* const& element);
};
// @fnv 0x00ae8150
// src: XBOX_PDB 0x00ae8150
void* AE8150_List::NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSTextureManager_RenderedTextureData_RemovePos(void* const& element)
{
    AE8150_Pos kPos = FindPos(element);
    Reserve();
    return kPos ? NiTPointerListBase_RemovePos_0(kPos) : element;
}

struct MapStorageBase : BucketTableStorage
{
    inline ~MapStorageBase()
    {
        ClearAll();
        _NiFree(data);
    }
};
struct FUN_00ae8c60 : MapStorageBase
{
    ~FUN_00ae8c60();
};
// @fnv 0x00ae8c60
FUN_00ae8c60::~FUN_00ae8c60()
{
    ClearAll();
}

void __cdecl NiFree8D10(void* pvMem);




class MapBase8D10
{
  public:
    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }
    virtual ~MapBase8D10()
    {
        RemoveAll();
        NiFree8D10(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(NiTMapItem<const char*, void*>* pkItem, const char* key, void* val);
    virtual void ClearValue(NiTMapItem<const char*, void*>* pkItem);
    virtual NiTMapItem<const char*, void*>* NewItem();
    virtual void DeleteItem(NiTMapItem<const char*, void*>* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, void*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    NiTMapItem<const char*, void*>** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00ae8d10 : public MapBase8D10
{
  public:
    virtual ~FUN_00ae8d10();
};

// @fnv 0x00ae8d10
FUN_00ae8d10::~FUN_00ae8d10()
{
    RemoveAll();
}

struct FUN_00ae93f0 : FUN_00ae9360_Base
{
    virtual ~FUN_00ae93f0();
};
struct AudioCleanupHelper
{
    __forceinline ~AudioCleanupHelper();
    __forceinline static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct AudioStreamStorage
{
    int state;
    unsigned int position;
    unsigned int headSize;
    unsigned int bodySize;
    unsigned int tailSize;
    unsigned int tailPosition;
    void* head;
    void* body;
    void* tail;
};
struct FUN_00aeafb0 : FUN_00ae93f0
{

    int unk198;
    SndUnknown* unk19C;
    SndUnknown* unk1A0;
    Stub1A4 unk1A4;
    void* unk1C8;
    int unk1CC;
    int unk1D0;
    SndUnknown* unk1D4;
    SndUnknown* unk1D8;
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
    AudioStreamStorage* unk228;
    AudioCleanupHelper* unk22C;
    virtual ~FUN_00aeafb0();
};

// @fnv 0x00aeafb0
FUN_00aeafb0::~FUN_00aeafb0()
{
    if (unk19C)
    {
        while (unk19C->Release())
        {
        }
        unk19C = 0;
    }
    if (unk1D4)
    {
        while (unk1D4->Release())
        {
        }
        unk1D4 = 0;
    }
    if (unk1A0)
    {
        --DAT_011f7128;
        while (unk1A0->Release())
        {
        }
        unk1A0 = 0;
    }
    if (unk1D8)
    {
        while (unk1D8->Release())
        {
        }
        unk1D8 = 0;
    }
    if (unk1A4.pBuf)
    {
        void* buffer = unk1A4.pBuf;
        g_memoryManager.Deallocate(buffer);
        unk1A4.pBuf = 0;
    }
    if (unk1C8)
    {
        void* buffer = unk1C8;
        g_memoryManager.Deallocate(buffer);
        unk1C8 = 0;
    }
    if (unk228)
    {
        if (unk228->head)
        {
            void* buffer = unk228->head;
            g_memoryManager.Deallocate(buffer);
        }
        if (unk228->tail)
        {
            void* buffer = unk228->tail;
            g_memoryManager.Deallocate(buffer);
        }
        if (unk228->body)
        {
            void* buffer = unk228->body;
            g_memoryManager.Deallocate(buffer);
        }
        {
            void* buffer = unk228;
            g_memoryManager.Deallocate(buffer);
        }
    }
    if (unk22C)
    {
        delete unk22C;
        unk22C = 0;
    }
}

struct VolumeCurve
{
    float GetVolumeValue();
};
VolumeCurve* __stdcall BSAudioManager_QInstance_00ad9060(float, unsigned int);
double __cdecl FUN_00ecbc80(double);
struct VolumeBuffer
{
    virtual int __stdcall slot0();
    virtual int __stdcall slot1();
    virtual int __stdcall slot2();
    virtual int __stdcall slot3();
    virtual int __stdcall slot4();
    virtual int __stdcall slot5();
    virtual int __stdcall slot6();
    virtual int __stdcall slot7();
    virtual int __stdcall slot8();
    virtual int __stdcall slot9();
    virtual int __stdcall slot10();
    virtual int __stdcall slot11();
    virtual int __stdcall slot12();
    virtual int __stdcall slot13();
    virtual int __stdcall slot14();
    virtual long __stdcall SetVolume(long);
};
struct BSWin32GameSound
{
    int unk00;
    int unk04;
    int flags08;
    int unk0c;
    int flags10;
    int unk14;
    unsigned short attenuation18, percent1a, attenuation1c, attenuation1e, attenuation20, unk22;
    float volume24;
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
    VolumeBuffer* buffer19c;
    VolumeBuffer* buffer1a0;
    bool FUN_00ae9cf0();
    bool FUN_00ae9d10();
    __forceinline unsigned short GetPercent() const
    {
        return percent1a;
    }
    bool IsFlag10Set(unsigned int uiFlag) const
    {
        return (flags10 & uiFlag) != 0;
    }
    bool IsFlag08Set(unsigned int uiFlag) const
    {
        return (flags08 & uiFlag) != 0;
    }
    bool SetVolume_00aed660(float volume);
};
// @fnv 0x00aed660
// src: XBOX_PDB 0x00aed660
bool BSWin32GameSound::SetVolume_00aed660(float volume)
{
    unsigned int scaled;
    long result3;
    volume24 = volume;
    float scaleA = GetPercent();
    long attenuationTmp = 0;
    long adjusted3 = 0;
    scaleA /= 100.0;
    if (buffer19c)
    {
        volume = volume > 1.0 ? 1.0f : volume;
        volume = volume < 0.0 ? 0.0f : volume;
        volume = BSAudioManager_QInstance_00ad9060(volume, flags08)->GetVolumeValue();
        if (!IsFlag10Set(0x200) && IsFlag10Set(0x10000) && !IsFlag08Set(0x1000))
            volume = 0.00001f;
        volume = volume < 9.999999747378752e-06 ? 0.00001f : volume;
        attenuationTmp = (int)((float)FUN_00ecbc80(volume) * 2000.0);
        attenuationTmp -= attenuation18 + attenuation1c + attenuation20;
        if (FUN_00ae9cf0() || FUN_00ae9d10())
            attenuationTmp -= attenuation1e;
        if (flags10 & 0x8)
        {
        }
        attenuationTmp = attenuationTmp > -10000 ? attenuationTmp : -10000;
        attenuationTmp = attenuationTmp < -1 ? attenuationTmp : -1;
        scaled = (unsigned int)(scaleA * -10000.0);
        adjusted3 = attenuationTmp + scaled;
        adjusted3 = adjusted3 > -10000 ? adjusted3 : -10000;
        adjusted3 = adjusted3 < -1 ? adjusted3 : -1;
        if (!IsFlag10Set(0x400))
        {
            result3 = 0x80004005;
            if (buffer1a0)
                buffer1a0->SetVolume(adjusted3);
            if (buffer19c)
                result3 = buffer19c->SetVolume(attenuationTmp);
            if (result3 >= 0)
                return true;
            else
                return false;
        }
        else
        {
            if (buffer1a0)
                buffer1a0->SetVolume(-10000);
            return buffer19c->SetVolume(-10000) >= 0;
        }
    }
    else
        return false;
}

#include <math.h>

float __cdecl NiSqrt_004579e0(float);
inline float P010Root(float f)
{
    return NiSqrt_004579e0(f);
}
struct P010Vec
{
    float x, y, z;
    P010Vec()
    {}
    P010Vec(float a, float b, float c) : x(a), y(b), z(c)
    {}
    inline P010Vec operator-(const P010Vec& r) const
    {
        return P010Vec(x - r.x, y - r.y, z - r.z);
    }
    inline P010Vec operator+(const P010Vec& r) const
    {
        return P010Vec(x + r.x, y + r.y, z + r.z);
    }
    inline float DotProduct(const P010Vec& r) const
    {
        return x * r.x + y * r.y + z * r.z;
    }
    inline float FUN_00457990() const
    {
        return P010Root(x * x + y * y + z * z);
    }
};
inline P010Vec __cdecl FUN_004a3760(float s, const P010Vec& r)
{
    return P010Vec(s * r.x, s * r.y, s * r.z);
}
struct P010Listener
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual const P010Vec* Position();
};
struct P010Audio
{
    int unk00, unk04, unk08, unk0c;
    P010Listener* listener;
    __forceinline static P010Audio* Get()
    {
        return (P010Audio*)DAT_011f6d98;
    }
    __forceinline P010Listener* Listener()
    {
        return listener;
    }
};
struct P010Sound
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void __stdcall SetPosition(float, float, float, int);
};
struct P010Object;
struct P010ObjectVtable
{
    void* slot00;
    void* slot04;
    void* slot08;
    void* slot0c;
    void* slot10;
    void* slot14;
    void* slot18;
    void* slot1c;
    void* slot20;
    void* slot24;
    void* slot28;
    void* slot2c;
    void* slot30;
    void* slot34;
    void* slot38;
    void(__thiscall* update)(P010Object*, float);
};
struct P010Object
{
    P010ObjectVtable* vtable;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned short unk1c, volume;
    unsigned int unk20;
    float unk24;
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
    float unk13c;
    float unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    float unk150;
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
    P010Vec origin;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
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
    P010Sound* sound1d4;
    P010Sound* sound1d8;
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
    unsigned short attenuation20c, attenuation20e;
    unsigned short attenuation210, attenuation212;
    unsigned short attenuation214, attenuation216;
    P010Vec position;
    bool dirty;
    bool FUN_00ae9cf0();
    bool FUN_00ae9d10();
    inline bool IsProjected() const
    {
        return (unk8 & 0x10000000) != 0;
    }
    inline bool IsLine() const
    {
        return (unk10 & 0x8000) != 0;
    }
    inline void SetDistance(float d)
    {
        unk150 = d;
    }
    inline void SetVolume(unsigned short a)
    {
        volume = a;
        vtable->update(this, unk24);
    }
    void BSWin32GameSound_SetEmitterPosition(float x, float y, float z);
};
// @fnv 0x00aef090
// src: XBOX_PDB 0x00aef090
void P010Object::BSWin32GameSound_SetEmitterPosition(float x, float y, float z)
{
    P010Vec tempVector;
    P010Vec output;
    output = *(const P010Vec*)&NiPoint3_ZERO;
    tempVector = *(const P010Vec*)&NiPoint3_ZERO;
    bool changed = false;
    if ((FUN_00ae9cf0() || FUN_00ae9d10()) && unk198)
    {
        float distance;
        P010Listener* listener;
        {
            P010Vec current, delta8, toListener4;

            float local41, local1, ratio7, lowVal, mid4, highVal;
            {
                if (P010Audio::Get()->Listener())
                {
                    listener = P010Audio::Get()->Listener();
                    tempVector = *listener->Position();
                    if (unk8 & 0x40000)
                    {
                        x = tempVector.x;
                        y = tempVector.y;
                        z = tempVector.z;
                    }
                    if (position.x != x || position.y != y || position.z != z)
                    {
                        position.x = x;
                        position.y = y;
                        position.z = z;
                        changed = true;
                    }
                }
                dirty = true;
                if (sound1d4)
                {
                    if ((!IsProjected() || !IsLine()) && changed)
                    {
                        sound1d4->SetPosition(float(x * DAT_010a3be8), float(z * DAT_010a3be8), float(y * DAT_010a3be8),
                                              1);
                        if (sound1d8)
                            sound1d8->SetPosition(float(x * DAT_010a3be8), float(z * DAT_010a3be8),
                                                  float(y * DAT_010a3be8), 1);
                    }
                    else if (P010Audio::Get()->Listener() && IsProjected() && IsLine())
                    {
                        local41 = 0.0f;
                        local1 = 0.0f;
                        ratio7 = 0.0f;
                        current = *P010Audio::Get()->Listener()->Position();
                        delta8 = origin - position;
                        toListener4 = current - position;
                        local41 = toListener4.DotProduct(delta8);
                        if (local41 <= 0.0)
                            output = position;
                        else
                        {
                            local1 = delta8.DotProduct(delta8);
                            if (local1 <= local41)
                                output = origin;
                            else
                            {
                                ratio7 = local41 / local1;
                                output = position + FUN_004a3760(ratio7, delta8);
                            }
                        }
                        sound1d4->SetPosition(float(output.x * DAT_010a3be8), float(output.z * DAT_010a3be8),
                                              float(output.y * DAT_010a3be8), 1);
                        if (sound1d8)
                            sound1d8->SetPosition(float(output.x * DAT_010a3be8), float(output.z * DAT_010a3be8),
                                                  float(output.y * DAT_010a3be8), 1);
                    }
                }
                SetDistance((tempVector - position).FUN_00457990());
                distance = unk150;
                if (IsProjected() && IsLine() && P010Audio::Get()->Listener())
                {
                    distance = (output - *P010Audio::Get()->Listener()->Position()).FUN_00457990();
                }
                if (fabs(unk13c - unk140) > 10.0)
                {
                    lowVal = (unk13c - unk140) * 0.25 + unk140;
                    mid4 = (unk13c - unk140) * 0.5 + unk140;
                    highVal = (unk13c - unk140) * 0.75 + unk140;
                    if (distance >= unk13c)
                    {
                        SetVolume(10000);
                    }
                    else if (distance > highVal && unk13c - highVal > 0.0)
                    {
                        SetVolume((unsigned short)(attenuation212 + (attenuation214 - attenuation212) *
                                                                        ((distance - highVal) / (unk13c - highVal))));
                    }
                    else if (distance > mid4 && highVal - mid4 > 0.0)
                    {
                        SetVolume((unsigned short)(attenuation210 + (attenuation212 - attenuation210) *
                                                                        ((distance - mid4) / (highVal - mid4))));
                    }
                    else if (distance > lowVal && mid4 - lowVal > 0.0)
                    {
                        SetVolume((unsigned short)(attenuation20e + (attenuation210 - attenuation20e) *
                                                                        ((distance - lowVal) / (mid4 - lowVal))));
                    }
                    else if (distance > unk140 && lowVal - unk140 > 0.0)
                    {
                        SetVolume((unsigned short)(attenuation20c + (attenuation20e - attenuation20c) *
                                                                        ((distance - unk140) / (lowVal - unk140))));
                    }
                    else
                    {
                        SetVolume(0);
                    }
                }
                else
                {
                    if (distance >= unk13c)
                    {
                        SetVolume(10000);
                    }
                    else
                    {
                        SetVolume(0);
                    }
                }
                vtable->update(this, unk24);
            }
        }
    }
}

extern "C" char* __cdecl strcpy(char* dst, const char* src);
extern "C" char* __cdecl strstr(const char* s, const char* sub);
extern "C" int __cdecl tolower(int c);

struct OggFile
{
    virtual ~OggFile();
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
    bool bGood;
    void Close();
    __forceinline bool IsGood() const
    {
        return bGood;
    }
};

struct OvCallbacks
{
    unsigned int(__cdecl* read_func)(void* ptr, unsigned int size, unsigned int nmemb, void* datasource);
    int(__cdecl* seek_func)(void* datasource, __int64 offset, int whence);
    int(__cdecl* close_func)(void* datasource);
    long(__cdecl* tell_func)(void* datasource);
};

unsigned int __cdecl CallProcAndAccumulate(void* ptr, unsigned int size, unsigned int nmemb, void* datasource);
int __cdecl DispatchHandlerEvent(void* datasource, __int64 offset, int whence);
long __cdecl tell_func_00af2290(void* datasource);

struct OggStream;
extern "C" int __cdecl ov_open_callbacks(void* datasource, OggStream* vf, char* initial, long ibytes,
                                         OvCallbacks callbacks);
struct VorbisInfo;
extern "C" VorbisInfo* __cdecl ov_info(OggStream* vf, int link);
extern "C" long __cdecl ov_seekable(OggStream* vf);
extern "C" __int64 __cdecl ov_pcm_total(OggStream* vf, int i);

struct OggStream
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
    OggFile* pFile;
    int iTotal;
    VorbisInfo* iInfo;
    bool bOpen;

    bool BSWin32GameSound_OggVorbisFile_OpenFile(const char* name);
};

// @fnv 0x00af1e00
// src: COMMUNITY 0x00af1e00
bool OggStream::BSWin32GameSound_OggVorbisFile_OpenFile(const char* name)
{
    // Legacy target lowercases259 bytes after strcpy, including the unused tail beyond NUL.
    char path3[260];
    strcpy(path3, name);
    for (int i4 = 0; i4 < 259; i4++)
        path3[i4] = tolower(path3[i4]);
    char* ext3 = strstr(path3, ".ogg");
    if (!ext3)
    {
        ext3 = strstr(path3, ".mp3");
        if (!ext3)
            ext3 = strstr(path3, ".wav");
        if (ext3)
        {
            ext3[1] = 'o';
            ext3[2] = 'g';
            ext3[3] = 'g';
        }
        else
        {
            return false;
        }
    }
    pFile = (OggFile*)FileFinder::GetFile(path3, 0, 0x4000, 0x10);
    if (!pFile || !pFile->IsGood())
    {
        if (pFile)
        {
            delete pFile;
            pFile = 0;
        }
        return false;
    }
    OvCallbacks cb_ = {CallProcAndAccumulate, DispatchHandlerEvent, 0, tell_func_00af2290};
    int ret = ov_open_callbacks(pFile, this, 0, 0, cb_);
    if (ret)
    {
        pFile->Close();
        delete pFile;
        pFile = 0;
        return false;
    }
    bOpen = true;
    iInfo = ov_info(this, -1);
    if (ov_seekable(this))
        iTotal = static_cast<int>(ov_pcm_total(this, 0));
    return true;
}

extern "C" unsigned short __cdecl FUN_00ec3bda(unsigned short value);

inline void NiEndianSwap(unsigned int& uiValue, Flag kFlag)
{
    unsigned int* puiValue = &uiValue;
    *puiValue = FUN_00ec3bad(*puiValue);
}
inline void NiEndianSwap(unsigned short& usValue, Flag kFlag)
{
    unsigned short* pusValue = &usValue;
    *pusValue = FUN_00ec3bda(*pusValue);
}

struct ArchiveHeader
{
    unsigned int m_uiMagic;
    unsigned int m_uiSize;
    unsigned int m_uiType;
    FUN_00afd920_Class m_kFlags;
    unsigned int m_uiValueBeforeCount;
    unsigned int m_uiCharacterCount;
    unsigned int m_uiHash;
    unsigned int m_uiCRC;
    unsigned short m_usElementCount;

    void ProcessState_00afd9d0();
};

// @fnv 0x00afd9d0
// src: GUESS 0x00afd9d0 (confidence: low)
void ArchiveHeader::ProcessState_00afd9d0()
{
    NiEndianSwap(m_uiMagic, Flag());
    NiEndianSwap(m_uiSize, Flag());
    NiEndianSwap(m_uiType, Flag());
    m_kFlags.UpdateValue();
    NiEndianSwap(m_uiValueBeforeCount, Flag());
    NiEndianSwap(m_uiCharacterCount, Flag());
    NiEndianSwap(m_uiHash, Flag());
    NiEndianSwap(m_uiCRC, Flag());
    NiEndianSwap(m_usElementCount, Flag());
}


inline void* operator new[](unsigned int size)
{
    return g_memoryManager.Allocate(size);
}
inline void operator delete[](void* p)
{
    g_memoryManager.Deallocate(p);
}

unsigned int FUN_00ecdb00(const unsigned short*);
void FUN_00ec44d0(void*, const void*, unsigned int);

inline void CopyChars(unsigned short* destination, const unsigned short* source, unsigned int size)
{
    FUN_00ec44d0(destination, source, size);
}

struct WideString
{
    unsigned short* data;
    unsigned short length;
    unsigned short capacity;
    bool BSStringT_wchar_t_Set(const unsigned short* input, unsigned int reserve);
};

// @fnv 0x00afff50
// src: COMMUNITY 0x00afff50
bool WideString::BSStringT_wchar_t_Set(const unsigned short* input, unsigned int reserve)
{
    unsigned int a;
    a = input ? FUN_00ecdb00(input) : 0;
    unsigned int newSize = a > reserve ? a : reserve;
    unsigned short* required;
    if (newSize <= capacity)
    {
        if (newSize)
        {
            if (input)
            {
                CopyChars(data, input, 2 * a + 2);
            }
            else
            {
                *data = 0;
            }
        }
        else
        {
            if (data)
                delete[] data;
            data = 0;
            newSize = 0;
            capacity = newSize <= 0xffff ? (unsigned short)newSize : 0xffff;
        }
    }
    else
    {
        required = data;
        data = new unsigned short[newSize + 1];
        if (input)
        {
            CopyChars(data, input, 2 * a + 2);
        }
        else
        {
            *data = 0;
        }
        if (required)
            delete[] required;
        capacity = newSize <= 0xffff ? (unsigned short)newSize : 0xffff;
    }
    length = a <= 0xffff ? (unsigned short)a : 0xffff;
    return a != 0;
}

struct AE92D0_Range
{
    int m_kRayStart;
    int m_kRayEnd;
    int m_uiItemCount;
    AE92D0_Range()
    {
        m_uiItemCount = 0;
        m_kRayStart = 0;
        m_kRayEnd = 0;
    }
    ~AE92D0_Range();
};
struct AE92D0_Object
{
    virtual ~AE92D0_Object();
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
    AE92D0_Range m_range;
    AE92D0_Object(int unused);
    void BSGameSound_Init();
};
// @fnv 0x00ae92d0
AE92D0_Object::AE92D0_Object(int unused)
{
    BSGameSound_Init();
}

void* __cdecl FUN_00ec7230(void* dst, const void* src, unsigned int size);

class FUN_005eee10
{
  public:
    typedef const char* Elem;
    void** m_vtbl;
    const char** m_data;
    unsigned int m_iElementCount;
    ~FUN_005eee10();

    void FUN_0042fb60(const char** pDst, const char** pSrc, unsigned int ItemUpdateArray)
    {
        if (ItemUpdateArray <= 0)
            return;
        if (pDst < pSrc)
        {
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
                FUN_00ec7230(&pDst[i], &pSrc[i], sizeof(const char*));
        }
        else if (pDst > pSrc)
        {
            for (int i = ItemUpdateArray - 1; i >= 0; i--)
                FUN_00ec7230(&pDst[i], &pSrc[i], sizeof(const char*));
        }
    }

    void RemoveRange(unsigned int uiIndex, unsigned int ItemUpdateArray)
    {
        unsigned int uiMove;
        unsigned int uiTail = m_iElementCount - uiIndex - ItemUpdateArray;
        uiMove = uiTail < ItemUpdateArray ? uiTail : ItemUpdateArray;
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
            (m_data + uiIndex + i)->~Elem();
        FUN_0042fb60(m_data + uiIndex, m_data + m_iElementCount - uiMove, uiMove);
        m_iElementCount -= ItemUpdateArray;
    }
};

class FileFinderImpl
{
  public:
    FUN_005eee10 m_ppData;
    ~FileFinderImpl();
};

extern FileFinderImpl* DAT_011f81dc;

// @fnv 0x00afdcf0
FileFinderImpl::~FileFinderImpl()
{
    unsigned int uiSize = m_ppData.m_iElementCount;
    unsigned int uiIndex = uiSize;
    while (uiIndex--)
    {
        const char* item = m_ppData.m_data[uiIndex];
        g_memoryManager.Deallocate((void*)item);
        m_ppData.RemoveRange(uiIndex, 1);
    }
    if (DAT_011f81dc == this)
    {
        DAT_011f81dc = 0;
    }
}

struct GuidAF
{
    unsigned int a;
    unsigned short b, c;
    unsigned char d[8];
};
extern int DAT_01093f04;
extern GuidAF DAT_01100f94, DAT_01100fb4;
extern GuidAF DAT_01101004, DAT_01100fd4;
struct Setting_01017720_011f96a0
{
    int vtable;
    unsigned int value;
};
extern Setting_01017720_011f96a0 g_011f7130, g_011f713c;
extern unsigned int DAT_01202800;
extern void* __cdecl _memmove(void*, const void*, unsigned int);
struct OutputAF;
struct AudioAF
{
    int u0, u4, u8, uc;
    void* p10;
    inline OutputAF* GetOutput()
    {
        return (OutputAF*)p10;
    }
    static inline AudioAF* Instance()
    {
        return (AudioAF*)DAT_011f6d98;
    }
};
struct OutputAF
{
    virtual void x0();
    virtual void x4();
    virtual void x8();
    virtual void xc();
    virtual void x10();
    virtual void x14();
    virtual void x18();
    virtual void x1c();
    virtual void x20();
    virtual void x24();
    virtual void x28();
    virtual unsigned int x2c();
};
struct BufferAF
{
    virtual long __stdcall Query(void*, void**);
    virtual void x04();
    virtual void x08();
    virtual void x0c();
    virtual void x10();
    virtual long __stdcall Format(void*, unsigned long, unsigned long*);
    virtual void x18();
    virtual void x1c();
    virtual void x20();
    virtual void x24();
    virtual void x28();
    virtual long __stdcall Lock(unsigned long, unsigned long, void**, unsigned long*, void**, unsigned long*,
                                unsigned long);
    virtual void x30();
    virtual void x34();
    virtual void x38();
    virtual void x3c();
    virtual void x40();
    virtual void x44();
    virtual void x48();
    virtual long __stdcall Unlock(void*, unsigned long, void*, unsigned long);
    virtual void x50();
    virtual long __stdcall Effect(unsigned long, void*, void*);
    virtual void x58();
    virtual long __stdcall Object(void*, unsigned long, void*, void**);
};
struct DeviceAF
{
    virtual void x00();
    virtual void x04();
    virtual void x08();
    virtual long __stdcall Create(void*, void**, void*);
};
struct EffectObjectAF
{
    virtual void x00();
    virtual void x04();
    virtual void x08();
    virtual void x0c();
    virtual void x10();
    virtual long __stdcall Set(unsigned int);
};
struct EffectAF
{
    unsigned int size, flags;
    GuidAF guid;
    unsigned int reserved1, reserved2;
};
struct DescAF
{
    unsigned int size, flags, bytes, reserved;
    void* format;
    GuidAF guid;
};
inline bool& EnableAF()
{
    return &g_011f7130 ? *(bool*)&g_011f7130.value : (*(bool*)&DAT_01202800 = false, *(bool*)&DAT_01202800);
}
inline unsigned int& LimitAF()
{
    return &g_011f713c ? g_011f713c.value : (DAT_01202800 = 0, DAT_01202800);
}
inline void* AllocateAF(unsigned int size)
{
    void* p = g_memoryManager.Allocate(size);
    return p;
}
inline void FreeAF(void* p)
{
    g_memoryManager.Deallocate(p);
}
inline void ZeroAF(void* dest, unsigned int size)
{
    _fnv_zlib_memset(dest, 0, size);
}
inline void CopyAF(void* dest, const void* source, unsigned int size)
{
    _memmove(dest, source, size);
}
struct AF1430
{
    unsigned int unk000;
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
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    DeviceAF* device;
    BufferAF* source;
    BufferAF* buffer;
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
    BufferAF* created;
    unsigned int unk1d4;
    void* unkEffect;
    unsigned int unk1dc;
    void* object;
    __forceinline unsigned int Flags()
    {
        return unk008;
    }
    __forceinline bool Any()
    {
        return (unk008 & 0x4000000) || (unk008 & 0x2000000);
    }
    bool BSWin32GameSound_PrepareReverb();
};
// @fnv 0x00af1430
// src: COMMUNITY 0x00af1430
bool AF1430::BSWin32GameSound_PrepareReverb()
{
    void* src1Bytes2;
    unsigned long srcn8;
    void* src2Bytes;
    unsigned long CNA;
    {
        DescAF desc;
        {
            unsigned long n;
            {
                EffectAF effect;
                {
                    void* CSAB;
                    void* CSA6;
                    void* CSA2;
                    void* free1_2;
                    void* allocatedB;
                    unsigned int count30;
                    unsigned long n222;
                    void* dst2BytesTmp;
                    long hRefId2;
                    void* dst2Bytes3;
                    if ((Flags() & 0x20) || !EnableAF() || !device || !source || !AudioAF::Instance()->GetOutput() ||
                        !AudioAF::Instance()->GetOutput()->x2c() || Any() || LimitAF() <= (unsigned int)DAT_011f7128)
                        return false;
                    dst2BytesTmp = 0;
                    dst2Bytes3 = 0;
                    n = 0;
                    n222 = 0;
                    src1Bytes2 = 0;
                    src2Bytes = 0;
                    CNA = 0;
                    srcn8 = 0;
                    _fnv_zlib_memset(&desc, 0, 0x24);
                    desc.size = 0x24;
                    if (Flags() & 1)
                        desc.flags = 0x40;
                    else
                        desc.flags = 0x30010;
                    desc.flags |= 0x2a0;
                    desc.bytes = unk1dc + (unsigned int)(unk1dc * 0.25);
                    desc.guid = *(GuidAF*)&DAT_01093f04;
                    allocatedB = g_memoryManager.Allocate(0x12);
                    desc.format = allocatedB;
                    source->Format(desc.format, 0x12, &n);
                    DAT_011f7128++;
                    if (device->Create(&desc, (void**)&created, 0) < 0)
                    {
                        (free1_2 = desc.format, g_memoryManager.Deallocate(free1_2));
                        return false;
                    }
                    created->Query((void*)&DAT_01100f94, (void**)&buffer);
                    if (buffer)
                        buffer->Query((void*)&DAT_01100fb4, &unkEffect);
                    else
                    {
                        (CSA2 = desc.format, g_memoryManager.Deallocate(CSA2));
                        return false;
                    }
                    effect.size = 0x20;
                    effect.flags = 0;
                    effect.guid = DAT_01101004;
                    effect.reserved1 = 0;
                    effect.reserved2 = 0;
                    hRefId2 = buffer->Effect(1, &effect, 0);
                    hRefId2 = buffer->Object(&DAT_01101004, 0, &DAT_01100fd4, &object);
                    if (hRefId2 >= 0)
                    {
                        count30 = unk154;
                        if (AudioAF::Instance()->GetOutput())
                        {
                            count30 = AudioAF::Instance()->GetOutput()->x2c();
                        }
                        if (count30 > 0)
                        {
                            --count30;
                            hRefId2 = ((EffectObjectAF*)object)->Set(count30);
                        }
                    }
                    n = 0;
                    if (buffer->Lock(0, 0, &dst2BytesTmp, &n, &dst2Bytes3, &n222, 2) < 0)
                    {
                        (CSA6 = desc.format, g_memoryManager.Deallocate(CSA6));
                        return false;
                    }
                    if (source->Lock(0, 0, &src1Bytes2, &CNA, &src2Bytes, &srcn8, 2) >= 0)
                    {
                        ZeroAF(dst2BytesTmp, desc.bytes);
                        CopyAF(dst2BytesTmp, src1Bytes2, unk1ac);
                        source->Unlock(src1Bytes2, CNA, src2Bytes, srcn8);
                    }
                    buffer->Unlock(dst2BytesTmp, n, dst2Bytes3, n222);
                    (CSAB = desc.format, g_memoryManager.Deallocate(CSAB));
                    return true;
                }
            }
        }
    }
}

struct AudioVec
{
    float x, y, z;
    AudioVec()
    {}
    AudioVec(float a, float b, float c) : x(a), y(b), z(c)
    {}
// src: GUESS 0x00439ef0 (confidence: high)
    inline AudioVec SubtractIntoVector(const AudioVec& rhs) const
    {
        const AudioVec* self = this;
        return AudioVec(self->x - rhs.x, self->y - rhs.y, self->z - rhs.z);
    }
    AudioVec FUN_00439e90(const AudioVec&) const;
    inline float DotProduct(const AudioVec& rhs) const
    {
        const AudioVec* self = this;
        float result = self->x * rhs.x + self->y * rhs.y + self->z * rhs.z;
        return result;
    }
    float FUN_00457990() const;
};
AudioVec __cdecl FUN_004a3760(float, const AudioVec&);

extern "C" double __cdecl fabs(double);
extern "C" const double DAT_010290f8;
__forceinline float Absolute(float value)
{
    return float(fabs(value));
}
struct Listener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual const AudioVec& Position();
};
struct AudioSystem
{
    unsigned int unk00, unk04, unk08, unk0c;
    Listener* listener;
    __forceinline Listener* GetListener()
    {
        return listener;
    }
};
__forceinline AudioSystem* GetSystem()
{
    return reinterpret_cast<AudioSystem*>(DAT_011f6d98);
}
struct PositionOutput
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
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void __stdcall SetPosition(float, float, float, unsigned int);
};
struct AudioSound
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
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void Refresh(float);
    unsigned int unk004;
    unsigned int flags;
    unsigned int unk00c;
    unsigned int state;
    unsigned int unk014;
    unsigned int unk018;
    unsigned short unk1c;
    unsigned short attenuation;
    unsigned int unk020;
    float volume;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    float outer;
    float inner;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    float distance;
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
    AudioVec source;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
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
    PositionOutput* primary;
    PositionOutput* secondary;
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
    unsigned short level0;
    unsigned short level1;
    unsigned short level2;
    unsigned short level3;
    unsigned short level4;
    unsigned short unk216;
    AudioVec point;

    unsigned char FUN_00ae9cf0();
    unsigned char FUN_00ae9d10();
    __forceinline bool IsSegment()
    {
        return (flags & 0x10000000) != 0;
    }
    __forceinline bool HasSegment()
    {
        return (state & 0x8000) != 0;
    }
    __forceinline void Attenuate(unsigned short value)
    {
        attenuation = value;
        Refresh(volume);
    }
    void BSWin32GameSound_UpdateEmitterPosition();
};

// @fnv 0x00aed990
// src: XBOX_PDB 0x00aed990
void AudioSound::BSWin32GameSound_UpdateEmitterPosition()
{
    float x = 0.0f, coordY = 0.0f, z = 0.0f;
    AudioVec projected3 = reinterpret_cast<const AudioVec&>(NiPoint3_ZERO);
    if (FUN_00ae9cf0() || FUN_00ae9d10())
    {
        if (GetSystem()->GetListener())
        {
            if (flags & 0x40000)
            {
                Listener* listenerC3 = GetSystem()->GetListener();
                AudioVec listenerPosition = listenerC3->Position();
                x = listenerPosition.x;
                coordY = listenerPosition.y;
                z = listenerPosition.z;
                if (primary)
                {
                    primary->SetPosition(float(x * DAT_010a3be8), float(z * DAT_010a3be8), float(coordY * DAT_010a3be8),
                                         1);
                    if (secondary)
                        secondary->SetPosition(float(x * DAT_010a3be8), float(z * DAT_010a3be8),
                                               float(coordY * DAT_010a3be8), 1);
                }
            }
            else if (IsSegment() && HasSegment())
            {
                float projection = 0.0f, squaredLength = 0.0f, fractionX = 0.0f;
                AudioVec center = GetSystem()->GetListener()->Position();
                AudioVec direction2;
                direction2 = source.SubtractIntoVector(point);
                AudioVec delta;
                delta = center.SubtractIntoVector(point);
                projection = delta.DotProduct(direction2);
                if (projection <= 0.0)
                {
                    projected3 = point;
                }
                else
                {
                    squaredLength = direction2.DotProduct(direction2);
                    if (squaredLength <= projection)
                    {
                        projected3 = source;
                    }
                    else
                    {
                        fractionX = projection / squaredLength;
                        projected3 = point.FUN_00439e90(FUN_004a3760(fractionX, direction2));
                    }
                }
                if (primary)
                {
                    primary->SetPosition(float(projected3.x * DAT_010a3be8), float(projected3.z * DAT_010a3be8),
                                         float(projected3.y * DAT_010a3be8), 1);
                    if (secondary)
                        secondary->SetPosition(float(projected3.x * DAT_010a3be8), float(projected3.z * DAT_010a3be8),
                                               float(projected3.y * DAT_010a3be8), 1);
                }
            }
            float distance = this->distance;
            if (IsSegment() && HasSegment() && GetSystem()->GetListener())
            {
                distance = projected3.SubtractIntoVector(GetSystem()->GetListener()->Position()).FUN_00457990();
                this->distance = distance;
            }
            else if (GetSystem()->GetListener())
            {
                distance = point.SubtractIntoVector(GetSystem()->GetListener()->Position()).FUN_00457990();
                this->distance = distance;
            }
            if (Absolute(outer - inner) > 10.0 && outer * DAT_010290f8 > distance)
            {
                float quarter = float((outer - inner) * 0.25 + inner);
                float midpointVal = float((outer - inner) * 0.5 + inner);
                float threeQuarter2 = float((outer - inner) * 0.75 + inner);
                if (distance >= outer)
                {
                    Attenuate(10000);
                }
                else if (distance > threeQuarter2 && outer - threeQuarter2 > 0.0)
                {
                    Attenuate((unsigned short)(level3 + (level4 - level3) *
                                                            ((distance - threeQuarter2) / (outer - threeQuarter2))));
                }
                else if (distance > midpointVal && threeQuarter2 - midpointVal > 0.0)
                {
                    Attenuate((unsigned short)(level2 + (level3 - level2) * ((distance - midpointVal) /
                                                                             (threeQuarter2 - midpointVal))));
                }
                else if (distance > quarter && midpointVal - quarter > 0.0)
                {
                    Attenuate((unsigned short)(level1 +
                                               (level2 - level1) * ((distance - quarter) / (midpointVal - quarter))));
                }
                else if (distance > inner && quarter - inner > 0.0)
                {
                    Attenuate((unsigned short)(level0 + (level1 - level0) * ((distance - inner) / (quarter - inner))));
                }
                else
                {
                    Attenuate(0);
                }
            }
            else
            {
                if (distance >= outer)
                {
                    Attenuate(10000);
                }
                else
                {
                    Attenuate(0);
                }
            }
            Refresh(volume);
        }
    }
}

#pragma pack(pop)
