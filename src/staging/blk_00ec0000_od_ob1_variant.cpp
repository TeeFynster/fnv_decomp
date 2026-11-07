#include "../../include/NiTMapItem.h"

// src/staging/blk_00ec0000_od_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/staging/blk_00ec0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00ec0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/BGSMoviePlayer.h"
#include "../../include/MemoryManager.h"
#include "../../include/AutoMemContext.h"
extern BGSMoviePlayer* DAT_0126fac4;
int __stdcall MoviePlayer_PlaySequenceThread(int a);
extern MemoryManager g_memoryManager;
struct FUN_00ec1a40_Class
{
    void* NiTMap_char_const_char_NewItem();
};
extern "C" int __cdecl _NiStricmp(const char*, const char*);
struct FUN_00ec1c90_class
{
    int __thiscall AreStringsEqualIgnoreCase(const char* a, const char* b);
};
extern int __cdecl __stricmp(const char*, const char*);
struct FUN_00ec1dc0_Class
{
    int __thiscall IsStringEqualIgnoreCase(const char* a, const char* b);
};
struct FUN_00ec1f20Class
{
    void Movie_ClearData();
    void* Movie_Movie();
};
struct FUN_00ec1f40Class
{
    void __thiscall Movie_Stop();
    void __thiscall Movie_Stop_Thunk();
};
struct FUN_00ec29b0_class
{
    void FUN_00ec29b0();
};
struct FUN_00ec2c10
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int m_002c;
    void __thiscall SetThreadPriorityLevel(int);
    void __thiscall IncreaseThreadPriorityUpToFive();
};
struct FUN_00ec1570_t
{
    int a;
    int b;
    int c;
    int d;
    int e;
    float f;
    float g;
    float h;
    int i;
    bool j;
};
void __fastcall Movie_ClearData(FUN_00ec1570_t* p);
struct FUN_00ec15e0_shell
{
    void __thiscall FUN_00ec15e0();
};
struct FUN_00ec19d0_class
{
    void* __thiscall FUN_00ec19d0(unsigned int flags);
};
struct FUN_00ec0cd0_Class
{
    unsigned char __thiscall InitPlayback(int a, int b, unsigned char c, int d);
};
struct FUN_00ec1f60_Class
{
    int m_0020;
    unsigned char m_0024;
    unsigned char InitAndCheck(int a, unsigned char b);
};
void __cdecl FNV_Warning(const char*);
struct FUN_00ec1fb0_class
{
    void __thiscall DisableThreadPriorityBoost();
};
struct FUN_00ec2a10_class
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    void __thiscall PauseMovie();
};
struct FUN_00ec2d40_class
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    void __thiscall SetValueAndReset(int a);
};
struct FUN_00ec2aa0_Class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual unsigned int v10();
    virtual unsigned int v11();
    float __thiscall ComputeRatio(unsigned int a, unsigned int b, bool c);
};
extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int priority);
struct FUN_00ec1fd0_shell
{
    void __thiscall UnpauseBink();
};
struct FUN_00ec2a60_class
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    void __thiscall MoviePlayer_Resume();
};
struct FUN_00ec2bb0_Class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual unsigned int v10();
    virtual unsigned int v11();
    float MoviePlayer_CalculateYOffset(float, unsigned int, bool);
};
extern "C" __declspec(dllimport) int __stdcall GetExitCodeThread(void* hThread, unsigned long* pExitCode);
struct FUN_00ec17c0_Class
{
    int m_0000;
    int m_0004;
    void* m_0008;
    bool MoviePlayer_GetPlayingSequence();
};
struct FUN_00ec19a0_Class
{
    int m_0000;
    void* m_0004;
    void __thiscall WaitForStoredHandle();
};
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf1c8(void* a, int b);
struct FUN_00ec1a60_t
{
    int a;
    int b;
    int c;
};
struct FUN_00ec1a60_class
{
    void __thiscall FreeStruct(FUN_00ec1a60_t* p);
};
extern "C" void __cdecl _NiFree(void*);
extern int DAT_010f1ca4;
struct FUN_00ec1b80_Map
{
    void __thiscall RemoveAll();
};
struct FUN_00ec1b80_Class
{
    int m_0000;
    int m_0004;
    int m_0008;
    void __thiscall Initialize();
};
void* __cdecl _NiMalloc(unsigned int size);
unsigned int __cdecl _strlen(const char* s);
int __cdecl _strcpy_s(char* dest, unsigned int size, const char* src);
struct FUN_00ec1cc0_Class
{
    void __thiscall AssignString(void* a, const char* b, int c);
};
extern int DAT_010f1c20;
struct FUN_00ec1a90_Class
{
    int m_ppVirtualMethodTable;
    void __thiscall FUN_00ec1a90();
};
struct FUN_00ec1d30_Class : FUN_00ec1a90_Class
{
    void __thiscall UpdateState_00ec1d30();
};
struct FUN_00ec0460_cls
{
    virtual void __stdcall v00(void);
    virtual void __stdcall v01(void);
    virtual void __stdcall v02(void);
    virtual void __stdcall v03(void);
    virtual void __stdcall v04(void);
    virtual void __stdcall v05(void);
    virtual void __stdcall v06(void);
    virtual void __stdcall v07(void);
    virtual void __stdcall v08(void);
    virtual void __stdcall v09(void);
    virtual void __stdcall v10(void);
    virtual void __stdcall v11(void);
    virtual void __stdcall v12(void);
    virtual void __stdcall v13(void);
    virtual void __stdcall v14(void);
    virtual void __stdcall v15(void);
    virtual void __stdcall v16(void);
    virtual void __stdcall v17(void);
    virtual void __stdcall v18(void);
    virtual void __stdcall v19(void);
    virtual void __stdcall v20(void);
    virtual void __stdcall v21(void);
    virtual void __stdcall v22(void);
    virtual void __stdcall v23(void);
    virtual void __stdcall v24(void);
    virtual void __stdcall v25(void);
    virtual void __stdcall v26(void);
    virtual void __stdcall v27(void);
    virtual void __stdcall v28(void);
    virtual void __stdcall v29(void);
    virtual void __stdcall v30(void);
    virtual void __stdcall v31(void);
    virtual void __stdcall v32(void);
    virtual void __stdcall v33(void);
    virtual void __stdcall v34(void);
    virtual void __stdcall v35(void);
    virtual void __stdcall v36(void);
    virtual void __stdcall v37(void);
    virtual void __stdcall v38(void);
    virtual void __stdcall v39(void);
    virtual void __stdcall v40(void);
    virtual void __stdcall v41(void);
    virtual void __stdcall v42(void);
    virtual void __stdcall v43(void);
    virtual void __stdcall v44(void);
    virtual void __stdcall v45(void);
    virtual void __stdcall v46(void);
    virtual void __stdcall v47(void);
    virtual void __stdcall v48(void);
    virtual void __stdcall v49(void);
    virtual void __stdcall v50(void);
    virtual void __stdcall v51(void);
    virtual void __stdcall v52(void);
    virtual void __stdcall v53(void);
    virtual void __stdcall v54(void);
    virtual void __stdcall v55(void);
    virtual void __stdcall v56(void);
    virtual void __stdcall v57(int a, int b);
    virtual void __stdcall v58(void);
    virtual void __stdcall v59(void);
    virtual void __stdcall v60(void);
    virtual void __stdcall v61(void);
    virtual void __stdcall v62(void);
    virtual void __stdcall v63(void);
    virtual void __stdcall v64(void);
    virtual void __stdcall v65(void);
    virtual void __stdcall v66(void);
    virtual void __stdcall v67(int a, int b, int c);
    virtual void __stdcall v68(void);
    virtual void __stdcall v69(int a, int b, int c);
};
void __cdecl Setup_Renderstate(FUN_00ec0460_cls* p);
struct GridDesc
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
    unsigned int cols;
    unsigned int rows;
    unsigned int extraX;
    unsigned int extraY;
    int unk34;
    int unk38;
    unsigned int cellSize;
};
void __cdecl Object_UpdateFields_00ec0720(int target, float x, float y, float sx, float sy, unsigned int w, unsigned int h);
void __cdecl Runtime_ProcessEntries_00ec0550(GridDesc* grid, float startX, float startY, float scaleX, float scaleY);
struct NiPlaybackFrameSize
{
    unsigned int uiWidth;
    unsigned int uiHeight;
};
class NiPlaybackManager
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual int GetRenderer();
    float GetFrameRate(unsigned int uiWidth, unsigned int uiHeight, bool bLooping);
    float GetWidthScale(float fRate, unsigned int uiWidth, bool bLooping);
    float GetHeightScale(float fRate, unsigned int uiHeight, bool bLooping);
};
void* __cdecl CreatePlaybackTextures(int iRenderer, unsigned int uiWidth, unsigned int uiHeight, int iCount, int iFlags,
                                     int iFormat);
void __cdecl FNV_Warning(const char*, ...);
class NiPlaybackFile
{
  public:
    NiPlaybackFrameSize* m_pkSize;
    int m_iRenderer;
    void* m_pkTextures;
    int m_unk0C;
    int m_unk10;
    float m_fTextureScale;
    float m_fWidthScale;
    float m_fHeightScale;
    int m_iFadeIndex;

    bool FindString(const char* pcName, bool bQuiet, bool bLoop, bool bFlag);
    bool InitPlayback(const char* pcName, bool bQuiet, bool bLoop, bool bLooping);
};
extern "C" __declspec(dllimport) void __stdcall BinkClose(int handle);
void __cdecl ReleaseInterfaceArray(int value);
struct FUN_00ec1020_cls
{
    int m_00;
    int m_04;
    int m_08;
    void Movie_Stop();
};
struct FUN_00ec14d0_bink
{
    void* m_00;
    unsigned int m_04;
};
int __cdecl LockNextTile(unsigned int a, int* p1, int* p2, int* p3, int* p4, int* p5, int* p6);
int __cdecl ApplyLastEffect(unsigned int a);
extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(void* hBink);
extern "C" __declspec(dllimport) int __stdcall BinkCopyToBufferRect(void* hBink, void* dest, int destPitch,
                                                                    unsigned int destHeight, unsigned int destX,
                                                                    unsigned int destY, unsigned int srcX,
                                                                    unsigned int srcY, unsigned int srcWidth,
                                                                    unsigned int srcHeight, unsigned int flags);
unsigned char __cdecl DecodeBinkFrame(FUN_00ec14d0_bink* a1, unsigned int a2, int a3);
// EnableSoundSystem: enables the Bink direct-sound output path.
// The Bink library is reached through the executable's import table; the
// address of the direct-sound entry point is passed to BinkSetSoundSystem.
extern "C" __declspec(dllimport) void __stdcall BinkOpenDirectSound(void* apDirectSound);
extern "C" __declspec(dllimport) void __stdcall BinkSetSoundSystem(void* system, unsigned int flags);
class FUN_00ec1680_cls
{
  public:
    void EnableSoundSystem(bool bEnableSound);
};
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pvSecurity, unsigned long ulStackSize,
                                                              unsigned long(__stdcall* pfnStart)(void*), void* pvParam,
                                                              unsigned long ulFlags, unsigned long* pulThreadId);
extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void* hThread);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long ulMilliseconds);
void __cdecl FUN_00aa2740(unsigned long ulThreadId, const char* pcName);
struct BEC16D0Setting
{
    void* m_pvVtable;
    int m_iValue;
};
extern BEC16D0Setting g_kEC16D0PrioritySetting;
extern int g_iEC16D0DefaultSetting;
struct BEC16D0Semaphore
{
    volatile long m_lCount;
    void* m_pSemaphore;
};
class BEC16D0MoviePlayerThread
{
  public:
    int unk00;
    int unk04;
    void* m_hThread;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    short unk20;
    bool m_bFlag22;
    bool m_bFlag23;
    bool m_bFlag24;
    float m_fValue28;
    int unk2C;
    BEC16D0Semaphore m_kStartSemaphore;

    void SetPriority(int iPriority);
    void MoviePlayer_StartSequence(void* pvParam, bool bFlag22, int iPriority, bool bFlag23, bool bFlag24, float fValue28);
};
extern int DAT_010f1ca4;
void __cdecl _NiFree_00aa10f0(int aValue);
extern MemoryManager DAT_011f6238;
struct FUN_00ec1df0_cls
{
    int m_vptr;
    int m_04;
    int m_08;

    void BaseCleanup();

    FUN_00ec1df0_cls* FUN_00ec1df0(unsigned int acFlags);
};
extern "C" __declspec(dllimport) int __stdcall SetThreadPriorityBoost(void* hThread, int fDisable);
extern "C" __declspec(dllimport) void __stdcall _BinkPause_8(void*, int);
struct S_00ec2b20
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual unsigned int v10();
    virtual unsigned int v11();
    virtual unsigned int v12();
    virtual unsigned int v13();
    float __thiscall ComputeAdjustedValue(float a, unsigned int b, bool c);
};
extern int DAT_0126fae0;
extern int DAT_0126fae4;
extern int DAT_01202800;
struct FUN_00ec2c40_cls
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int m_002c;
    void __thiscall SetThreadPriorityLevel(int);
    void MoviePlayer_DecreaseSequenceThreadPriority();
};
// Look up the file name registered under a key and copy it into a MAX_PATH buffer.
extern "C" int __cdecl strcpy_s(char* pcDest, unsigned int uiSize, const char* pcSrc);
class EC2DF0NameMap
{
  public:
    bool GetAt(unsigned int uiKey, const char*& rpcName) const;
};
class EC2DF0Registry
{
  public:
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
    EC2DF0NameMap m_kNames;

    bool GetNameByKey(unsigned int uiKey, char* pcPath);
};

struct ThreadData2490
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
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
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
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int context;
};
extern __declspec(thread) ThreadData2490 g_thread2490;
struct Scope2490
{
    unsigned int previous;
    Scope2490()
    {
        unsigned int current = g_thread2490.context;
        previous = current;
        g_thread2490.context = 20;
    }
    ~Scope2490()
    {
        unsigned int restored = previous;
        g_thread2490.context = restored;
    }
};
// Movie has the 0x28-byte playback layout; constructor 0x00ec1f20, background initializer 0x00ec1f60. No shared Movie.h yet.
struct Movie
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    Movie();
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void*);
    unsigned char InitAndCheck(int, unsigned char);
};
struct FUN_00ec2490_Class
{
    int unk00, unk04, unk08;
    Movie* movie;
    int unk10;
    Movie* cached;
    bool hasCached;
    void PauseMovie();
    void MoviePlayer_Stop();
    unsigned char BGSMoviePlayer_PlayBackground(int, unsigned char);
};
// @fnv 0x00ec2490
// src: COMMUNITY 0x00ec2490
unsigned char FUN_00ec2490_Class::BGSMoviePlayer_PlayBackground(int value, unsigned char option)
{
    Scope2490 scope;
    PauseMovie();
    if (hasCached && cached)
    {
        movie = cached;
        cached = 0;
        hasCached = false;
    }
    else
    {
        movie = new Movie;
    }
    unsigned char result = movie->InitAndCheck(value, option);
    if (!result)
        MoviePlayer_Stop();
    return result;
}

namespace fnv_00ec2ca0 {

struct SpawnedObject
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

    SpawnedObject();
    static __forceinline void* operator new(unsigned int size) throw()
    {
        return DAT_011f6238.Allocate(size);
    }
    void FUN_00ec0ac0(int a, int b, int c, int d);
};

// @fnv 0x00ec2ca0
// src: COMMUNITY 0x00ec2ca0
int __stdcall MoviePlayer_MovieLoadingThread(int a1)
{
    SpawnedObject* obj = new SpawnedObject();
    obj->FUN_00ec0ac0(a1, 1, 1, 1);
    reinterpret_cast<FUN_00ec2d40_class*>(DAT_0126fac4)->SetValueAndReset((int)obj);
    return 0;
}
}  // namespace fnv_00ec2ca0

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf1c0(void*);
struct MovieSemaphore
{
    int unk00;
    void* handle;
};
extern __declspec(thread) int g_tlsAllocTag;

struct ScopedAllocTag
{
    int saved;
    __forceinline ScopedAllocTag(int previous)
    {
        saved = previous;
        g_tlsAllocTag = 0x14;
    }
    __forceinline ~ScopedAllocTag()
    {
        int old = saved;
        g_tlsAllocTag = old;
    }
};

extern MemoryManager g_movieMem;

struct MovieBoolSetting
{
    int vtbl;
    bool value;
};
extern MovieBoolSetting g_0126fac8;

unsigned int __cdecl _strlen(const char* s);
char* __cdecl _strcpy(char* dst, const char* src);
char* __cdecl MovieStrtok(char* s, const char* delim);
int __cdecl MovieStricmp(const char* a, const char* b);
void __cdecl FNV_Warning(const char* fmt, ...);
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

extern const char g_movieDelims[];
extern const char g_movieExt[];
extern const char g_movieWarnFmt[];

struct MoviePlayerA
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void Lock();
    virtual void Unlock();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual unsigned long GetThreadId();
    virtual bool CanQueue(bool first);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    bool unk20;
    bool unk21;
    bool unk22;
    bool unk23;
    bool unk24;
    char unk25;
    char unk26;
    char unk27;
    int unk28;
    int unk2c;
    MovieSemaphore semaphore30;
    int unk38;
    bool unk3c;

    void MoviePlayer_Play(const char* name, bool first, int a, int b, bool c, bool d, int e, bool f, bool g);
// src: COMMUNITY 0x00ec1a00
    void MoviePlayer_SignalBinkOpen()
    {
        MovieSemaphore* semaphore = &semaphore30;
        ReleaseSemaphore(semaphore->handle, 1, 0);
        FUN_00fdf1c0(semaphore);
        unk3c = true;
    }
    void MoviePlayer_PlaySequence(const char* list);
};

// @fnv 0x00ec2760
// src: XBOX_PDB 0x00ec2760
void MoviePlayerA::MoviePlayer_PlaySequence(const char* list)
{
    char* ext2;
    int tidTmp3 = g_tlsAllocTag;
    ScopedAllocTag tag(tidTmp3);
    Lock();
    unsigned int size;
    size = _strlen(list) + 1;
    char* buf2 = (char*)g_movieMem.Allocate(size);
    _strcpy(buf2, list);
    char* tok_2 = MovieStrtok(buf2, g_movieDelims);
    bool first = true;
    unk3c = 0;
    while (tok_2)
    {
        if (!unk21 && CanQueue(first))
        {
            ext2 = tok_2 + _strlen(tok_2) - 3;
            if (MovieStricmp(ext2, g_movieExt) == 0)
            {
                bool* setting =
                    &g_0126fac8 ? &g_0126fac8.value : (*(bool*)& DAT_01202800 = false, (bool*)&DAT_01202800);
                MoviePlayer_Play(tok_2, first, 1, 0, *setting, unk22, 0, unk23, unk24);
            }
            else
            {
                FNV_Warning(g_movieWarnFmt, tok_2);
            }
        }
        tok_2 = MovieStrtok(0, g_movieDelims);
    }
    g_movieMem.Deallocate(buf2);
    unk21 = 0;
    if (!unk20)
        unk08 = 0;
    {
        unsigned long previous5 = GetCurrentThreadId();
        if (previous5 != GetThreadId() && !unk3c)
            MoviePlayer_SignalBinkOpen();
    }
    Unlock();
}

void __cdecl NiFree1BB0(void* pvMem);

extern MemoryManager g_kMemoryManager1BB0;



class MapBase1BB0
{
  public:
    static void operator delete(void* pvMem)
    {
        g_kMemoryManager1BB0.Deallocate(pvMem);
    }
    virtual ~MapBase1BB0()
    {
        RemoveAll();
        NiFree1BB0(m_ppkHashTable);
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
class FUN_00ec1bb0 : public MapBase1BB0
{
  public:
    virtual ~FUN_00ec1bb0();
};

// @fnv 0x00ec1bb0
FUN_00ec1bb0::~FUN_00ec1bb0()
{
    RemoveAll();
}

struct TlsData
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) TlsData g_tls;


inline unsigned int GetAllocContext()
{
    return g_tls.m_2b4;
}
inline void SetAllocContext(unsigned int v)
{
    g_tls.m_2b4 = v;
}

struct ScopedAllocContext
{
    unsigned int m_saved;
    inline ScopedAllocContext(unsigned int ctx)
    {
        m_saved = GetAllocContext();
        g_tls.m_2b4 = ctx;
    }
    inline ~ScopedAllocContext()
    {
        SetAllocContext(m_saved);
    }
};

// @fnv 0x00ec1ff0
// src: GUESS 0x00ec1ff0 (confidence: low)
void* __stdcall Runtime_AllocateStorage_00ec1ff0(unsigned int size)
{
    ScopedAllocContext ctx(0x14);
    return DAT_011f6238.Allocate(size);
}

extern __declspec(thread) unsigned int t_uiMemContextEC2200;
extern MemoryManager g_kMemoryEC2200;
inline unsigned int GetMemContextEC2200()
{
    return t_uiMemContextEC2200;
}
inline void SetMemContextEC2200(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextEC2200 = m_uiGeometryShaderFlags;
}
inline AutoMemContext::AutoMemContext(int context)
{
    m_eMemoryContext = (MEM_CONTEXT)GetMemContextEC2200();
    SetMemContextEC2200(context);
}
inline AutoMemContext::~AutoMemContext()
{
    SetMemContextEC2200(m_eMemoryContext);
}
class PlaybackFileEC2200
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return g_kMemoryEC2200.Allocate(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        g_kMemoryEC2200.Deallocate(pvMem);
    }
    PlaybackFileEC2200();
    bool FindString(const char* pcName, bool bA, bool bB, bool bC);
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
};
class PlaybackEC2200
{
  public:
    void Close();
    bool MoviePlayer_MovieLoadingThreadWithSettings(const char* pcName, bool bA, bool bB, bool bC);
    int unk00;
    int unk04;
    int unk08;
    PlaybackFileEC2200* m_pFile;
};

// @fnv 0x00ec2200
// src: COMMUNITY 0x00ec2200
bool PlaybackEC2200::MoviePlayer_MovieLoadingThreadWithSettings(const char* pcName, bool bA, bool bB, bool bC)
{
    AutoMemContext kContext(20);
    m_pFile = new PlaybackFileEC2200;
    bool bSuccess = m_pFile->FindString(pcName, bA, bB, bC);
    if (!bSuccess)
        Close();
    return bSuccess;
}

extern "C" __declspec(thread) int tls_memContext;

inline int GetMemContext()
{
    return tls_memContext;
}
inline void SetMemContext(int aiMemoryContext)
{
    tls_memContext = aiMemoryContext;
}

struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = GetMemContext();
        SetMemContext(aiMemoryContext);
    }
    ~MemContextGuard()
    {
        SetMemContext(m_iSaved);
    }
};

class BSMovieJob
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    BSMovieJob();
    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pv);
    bool Movie_Play(void* pFile, bool a, bool b, bool c, bool d, bool e, bool f, bool g, float fScale);
};

class BSMovieThread
{
  public:
    int unk00, unk04, unk08;
    BSMovieJob* m_pkCurrent;
    int unk10;
    BSMovieJob* m_pkSaved;
    bool m_bPending;
    int unk1c, unk20, unk24;
    float m_fScale;
    void PauseMovie();
    void MoviePlayer_Stop();
    bool MoviePlayer_Play(void* pFile, bool a, bool b, bool c, bool d, bool e, bool bReuse, bool f, bool g);
};

// @fnv 0x00ec2320
// src: COMMUNITY 0x00ec2320
bool BSMovieThread::MoviePlayer_Play(void* pFile, bool a, bool b, bool c, bool d, bool e, bool bReuse, bool f, bool g)
{
    MemContextGuard kGuard(20);
    if (!bReuse)
    {
        PauseMovie();
        if (m_bPending && m_pkSaved)
        {
            m_pkCurrent = m_pkSaved;
            m_pkSaved = 0;
            m_bPending = false;
        }
        else
        {
            m_pkCurrent = new BSMovieJob;
        }
    }
    bool bResult = m_pkCurrent->Movie_Play(pFile, a, b, c, d, e, f, g, m_fScale);
    MoviePlayer_Stop();
    return bResult;
}

struct ThreadContext
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
    int m_uiMemoryContext;
};
extern __declspec(thread) ThreadContext g_threadContext;
__forceinline int GetMemoryContext()
{
    return g_threadContext.m_uiMemoryContext;
}
__forceinline void SetMemoryContext(int value)
{
    g_threadContext.m_uiMemoryContext = value;
}

struct HeapZoneGuard
{
    int saved;
    __forceinline HeapZoneGuard(int zone)
    {
        saved = GetMemoryContext();
        g_threadContext.m_uiMemoryContext = zone;
    }
    __forceinline ~HeapZoneGuard()
    {
        SetMemoryContext(saved);
    }
};

struct EC1060Target
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
    __forceinline unsigned char IsReady() const
    {
        return unk20 != 0;
    }
    unsigned char __thiscall Update(unsigned char a, unsigned char b, int c);
};

struct EC2650Owner
{
    int unk00;
    int unk04;
    int unk08;
    EC1060Target* unk0c;
    unsigned char MoviePlayer_Update(unsigned char a, unsigned char b);
};

// @fnv 0x00ec2650
// src: COMMUNITY 0x00ec2650
unsigned char EC2650Owner::MoviePlayer_Update(unsigned char a, unsigned char b)
{
    HeapZoneGuard guard(0x14);
    if (unk0c && unk0c->IsReady())
    {
        return unk0c->Update(a, b, 0);
    }
    return 0;
}

void NiFree(void* p);
class NiTStringMapBase
{
  public:
    unsigned int m_uiHashSize;
    NiTMapItem<const char*, char*>** m_ppkHashTable;
    unsigned int m_uiCount;
    virtual void ClearValue(NiTMapItem<const char*, char*>* pkItem);
    virtual void DeleteItem(NiTMapItem<const char*, char*>* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, char*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    virtual ~NiTStringMapBase()
    {
        RemoveAll();
        NiFree(m_ppkHashTable);
    }
};
class NiTStringMapMid : public NiTStringMapBase
{
  public:
    virtual ~NiTStringMapMid()
    {
        RemoveAll();
    }
};
class NiTStringMapCopy : public NiTStringMapMid
{
  public:
    bool m_bCopy;
    virtual ~NiTStringMapCopy();
};
// @fnv 0x00ec1a90
NiTStringMapCopy::~NiTStringMapCopy()
{
    if (m_bCopy)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            NiTMapItem<const char*, char*>* pkItem = m_ppkHashTable[i];
            while (pkItem)
            {
                NiTMapItem<const char*, char*>* pkSave = pkItem;
                pkItem = pkItem->m_pkNext;
                NiFree((char*)pkSave->m_key);
            }
        }
    }
}


// RTTI vftable 0x010f1cc4 is NiTMap<const char*, char*>; its nodes use the same key/value types.
struct BaseE40
{
    unsigned int m_uiHashSize;
    NiTMapItem<const char*, char*>** m_ppkHashTable;
    int m_uiCount;
    virtual ~BaseE40()
    {
        FUN_00438af0();
        _NiFree_00aa10f0((int)m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(int key) const;
    virtual bool IsKeysEqual(int a, int b) const;
    virtual void SetValue(NiTMapItem<const char*, char*>* pkItem, int key, int val);
    virtual void ClearValue(NiTMapItem<const char*, char*>* pkItem);
    virtual NiTMapItem<const char*, char*>* NewItem();
    virtual void DeleteItem(NiTMapItem<const char*, char*>* pkItem);
    void FUN_00438af0()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, char*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    static void operator delete(void* p)
    {
        DAT_011f6238.Deallocate(p);
    }
};
struct FUN_00ec1e40 : BaseE40
{
// @fnv 0x00ec1e40
    virtual ~FUN_00ec1e40()
    {
        FUN_00438af0();
    }
};
void MakeE40()
{
    new FUN_00ec1e40;
}

template <class TKEY, class TVAL> class NiTMapItem;
template <class T> class DFALL;
namespace fnv_00ec15e0 {
extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(void*, long, long, const char*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
class MovieSemaphore
{
  public:
    long count;
    void* handle;
    long maximum;
    ~MovieSemaphore()
    {
        CloseHandle(handle);
    }
};

extern MemoryManager g_movieHeap;
inline void NiFree(void* p)
{
    g_movieHeap.Deallocate(p);
}
typedef void* NiTMapIterator;
// Unit-local view of NiTMapBase for 0x00ec15e0 (namespace fnv_00ec15e0): built on the shared NiTMapBase, that code does not compile or does not match.
template <class A, class K, class V> class NiTMapBase_00ec15e0
{
  public:
    virtual ~NiTMapBase_00ec15e0();
    unsigned int hashSize;
    NiTMapItem<K, V>** buckets;
    unsigned int count;
    NiTMapIterator GetFirstPos() const
    {
        for (unsigned int i = 0; i < hashSize; i++)
        {
            if (buckets[i])
                return buckets[i];
        }
        return 0;
    }
    void GetNext(NiTMapIterator& pos, K& key, V& val) const;
    void RemoveAll();
};
// Unit-local view of NiTMap for 0x00ec15e0 (namespace fnv_00ec15e0): built on the shared NiTMap, that code does not compile or does not match.
template <class K, class V> class NiTMap_00ec15e0 : public NiTMapBase_00ec15e0<DFALL<NiTMapItem<K, V> >, K, V>
{
  public:
    virtual ~NiTMap_00ec15e0();
};
// Unit-local view of NiTStringTemplateMap for 0x00ec15e0 (namespace fnv_00ec15e0): built on the shared NiTStringTemplateMap, that code does not compile or does not match.
template <class Base, class V> class NiTStringTemplateMap_00ec15e0 : public Base
{
  public:
    bool copyStrings;
    virtual ~NiTStringTemplateMap_00ec15e0();
};
template <class V> class NiTStringMap : public NiTStringTemplateMap_00ec15e0<NiTMap_00ec15e0<const char*, V>, V>
{
  public:
};
template <class V> class BSTCaseInsensitiveStringMap : public NiTStringMap<V>
{
  public:
    virtual ~BSTCaseInsensitiveStringMap()
    {}
};
class BSMoviePlayer
{
  public:
    virtual void Run();
    int unk04, unk08, unk0c, unk10, unk14;
    unsigned char unk18, unk19, unk1a, unk1b;
    int unk1c;
    unsigned char unk20, unk21, unk22, unk23, unk24, unk25, unk26, unk27;
    int unk28, unk2c;
    MovieSemaphore semaphore;
    int unk3c;
    BSTCaseInsensitiveStringMap<char*> strings;
    void MoviePlayer_Stop();
// src: GUESS 0x00ec2e50 (confidence: low)
    void ReleaseStorage_00ec2e50()
    {
        NiTMapIterator pos = strings.GetFirstPos();
        while (pos)
        {
            const char* key = 0;
            char* val = 0;
            strings.GetNext(pos, key, val);
            NiFree(val);
        }
        strings.RemoveAll();
    }
    virtual ~BSMoviePlayer();
};
// @fnv 0x00ec15e0
BSMoviePlayer::~BSMoviePlayer()
{
    while (unk0c != 0)
        MoviePlayer_Stop();
    ReleaseStorage_00ec2e50();
}
}  // namespace fnv_00ec15e0

template <class TKEY, class TVAL> class NiTMapItem;
template <class T> class DFALL;
namespace fnv_00ec20c0 {
extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(void*, long, long, const char*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
class MovieSemaphore
{
  public:
    long count;
    void* handle;
    long maximum;
    MovieSemaphore(long initial = 0, long maxCount = 1) : count(initial), maximum(maxCount)
    {
        handle = CreateSemaphoreA(0, count, maximum, 0);
    }
    ~MovieSemaphore()
    {
        CloseHandle(handle);
    }
};
void* __cdecl NiMalloc(unsigned int size);
extern "C" void* __cdecl memset(void* dst, int val, unsigned int size);
inline void* NiAllocBytes(unsigned int uiBytes)
{
    return NiMalloc(uiBytes);
}
inline void NiZeroBytes(void* pvDest, unsigned int uiBytes)
{
    memset(pvDest, 0, uiBytes);
}
// Unit-local view of NiTMapBase for 0x00ec20c0 (namespace fnv_00ec20c0): built on the shared NiTMapBase, that code does not compile or does not match.
template <class A, class K, class V> class NiTMapBase_00ec20c0
{
  public:
    virtual ~NiTMapBase_00ec20c0();
    unsigned int hashSize;
    NiTMapItem<K, V>** buckets;
    unsigned int count;
    NiTMapBase_00ec20c0(unsigned int uiHashSize)
    {
        hashSize = uiHashSize;
        count = 0;
        buckets = (NiTMapItem<K, V>**)NiAllocBytes(sizeof(NiTMapItem<K, V>*) * hashSize);
        NiZeroBytes(buckets, sizeof(NiTMapItem<K, V>*) * hashSize);
    }
};
// Unit-local view of NiTMap for 0x00ec20c0 (namespace fnv_00ec20c0): built on the shared NiTMap, that code does not compile or does not match.
template <class K, class V> class NiTMap_00ec20c0 : public NiTMapBase_00ec20c0<DFALL<NiTMapItem<K, V> >, K, V>
{
  public:
    NiTMap_00ec20c0(unsigned int size = 37) : NiTMapBase_00ec20c0<DFALL<NiTMapItem<K, V> >, K, V>(size)
    {}
    virtual ~NiTMap_00ec20c0()
    {}
};
// Unit-local view of NiTStringTemplateMap for 0x00ec20c0 (namespace fnv_00ec20c0): built on the shared NiTStringTemplateMap, that code does not compile or does not match.
template <class Base, class V> class NiTStringTemplateMap_00ec20c0 : public Base
{
  public:
    bool copyStrings;
    NiTStringTemplateMap_00ec20c0(unsigned int size = 37, bool copy = true) : Base(size), copyStrings(copy)
    {}
    virtual ~NiTStringTemplateMap_00ec20c0()
    {}
};
template <class V> class NiTStringMap : public NiTStringTemplateMap_00ec20c0<NiTMap_00ec20c0<const char*, V>, V>
{
  public:
    NiTStringMap(unsigned int size = 37, bool copy = true) : NiTStringTemplateMap_00ec20c0<NiTMap_00ec20c0<const char*, V>, V>(size, copy)
    {}
    virtual ~NiTStringMap()
    {}
};
template <class V> class BSTCaseInsensitiveStringMap : public NiTStringMap<V>
{
  public:
    BSTCaseInsensitiveStringMap(unsigned int size = 37, bool copy = true) : NiTStringMap<V>(size, copy)
    {}
    virtual ~BSTCaseInsensitiveStringMap()
    {}
};
class BSMoviePlayer
{
  public:
    virtual void Run();
    int unk04, unk08, unk0c, unk10, unk14;
    unsigned char unk18, unk19, unk1a, unk1b;
    int unk1c;
    unsigned char unk20, unk21, unk22, unk23, unk24, unk25, unk26, unk27;
    int unk28, unk2c;
    MovieSemaphore semaphore;
    int unk3c;
    BSTCaseInsensitiveStringMap<char*> strings;
    BSMoviePlayer();
};
// @fnv 0x00ec20c0
BSMoviePlayer::BSMoviePlayer()
    : unk04(0), unk08(0), unk0c(0), unk10(0), unk14(0), unk18(0), unk19(0), unk1c(0), unk20(0), unk21(0), unk22(0),
      unk23(1), unk24(1), unk2c(0)
{}
}  // namespace fnv_00ec20c0

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern double DAT_01012060;

struct S0ERTTI
{
    const char* m_pcName;
    const S0ERTTI* m_pBaseRTTI;
};
extern S0ERTTI DAT_0126f59c;
struct S0ERenderer;
extern S0ERenderer* DAT_011f4748;

struct S0EObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual const S0ERTTI* GetRTTI() const;

    bool IsKindOfType(const S0ERTTI* pkRTTI) const
    {
        const S0ERTTI* pkTmp = GetRTTI();
        while (pkTmp)
        {
            if (pkTmp == pkRTTI)
                return true;
            pkTmp = pkTmp->m_pBaseRTTI;
        }
        return false;
    }
};

struct S0ESurface;

struct S0EBufferData : S0EObject
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S0ESurface* m_pkSurface;

    S0ESurface* GetSurface() const
    {
        return m_pkSurface;
    }
};

struct S0ETargetGroup
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual S0EObject* GetRenderTargetBuffer(unsigned int uiIndex);
};

struct S0ERenderer
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual S0ETargetGroup* GetDefaultRenderTargetGroup();

    static S0ERenderer* GetRenderer()
    {
        return DAT_011f4748;
    }
};

struct S0EDevice
{
    virtual void __stdcall v00();
    virtual void __stdcall v01();
    virtual void __stdcall v02();
    virtual void __stdcall v03();
    virtual void __stdcall v04();
    virtual void __stdcall v05();
    virtual void __stdcall v06();
    virtual void __stdcall v07();
    virtual void __stdcall v08();
    virtual void __stdcall v09();
    virtual void __stdcall v10();
    virtual void __stdcall v11();
    virtual void __stdcall v12();
    virtual void __stdcall v13();
    virtual void __stdcall v14();
    virtual void __stdcall v15();
    virtual void __stdcall v16();
    virtual void __stdcall v17();
    virtual void __stdcall v18();
    virtual void __stdcall v19();
    virtual void __stdcall v20();
    virtual void __stdcall v21();
    virtual void __stdcall v22();
    virtual void __stdcall v23();
    virtual void __stdcall v24();
    virtual void __stdcall v25();
    virtual void __stdcall v26();
    virtual void __stdcall v27();
    virtual void __stdcall v28();
    virtual void __stdcall v29();
    virtual void __stdcall v30();
    virtual void __stdcall v31();
    virtual void __stdcall v32();
    virtual void __stdcall v33();
    virtual void __stdcall v34();
    virtual void __stdcall v35();
    virtual void __stdcall v36();
    virtual long __stdcall SetRenderTarget(unsigned long RenderTargetIndex, S0ESurface* pRenderTarget);
};


struct S0EBink
{
    int unk00;
    int unk04;
    unsigned int m_uiFrames;
};

struct S0EPlaybackFile
{
    S0EBink* m_pkBink;
    S0EDevice* m_pkDevice;
    unsigned int m_uiTexture;
    unsigned int m_uiFrame;
    unsigned int m_uiDecoded;
    float m_fScale;
    float m_fVectorY;
    float m_fVectorZ;
    int m_iFadeIndex;
    bool m_bBusy;

    bool InitPlayback(const char* pcName, bool bQuiet, bool bLoop, bool bLooping);
    bool Update(bool bWait, bool b2, bool b3);
    void Movie_Stop();
    unsigned char Movie_Play(const char* pcName, bool b1, bool b2, bool b3, bool b4, bool b5, bool b6, bool b7,
                               float afFinalFloat);
};

__forceinline S0EBufferData* DynamicCastBufferData(S0EObject* pkObject)
{
    if (!pkObject)
        return 0;
    return pkObject->IsKindOfType(&DAT_0126f59c) ? (S0EBufferData*)pkObject : 0;
}

// @fnv 0x00ec0e00
// src: COMMUNITY 0x00ec0e00
unsigned char S0EPlaybackFile::Movie_Play(const char* pcName, bool b1, bool b2, bool b3, bool b4, bool b5, bool b6,
                                            bool b7, float afFinalFloat)
{
    S0EBufferData* pkCast2;
    bool bWait;
    unsigned char bRet;
    unsigned int uiStart;
    unsigned int uiNow3;

    m_iFadeIndex = 1;
    m_bBusy = true;
    if (!InitPlayback(pcName, b2, b4, b5))
    {
        m_bBusy = false;
        return false;
    }
    m_bBusy = false;

    if (b6)
        DAT_0126fac4->BeginMoviePlayback();
    if (b7)
        DAT_0126fac4->vf03();

    pkCast2 =
        DynamicCastBufferData(S0ERenderer::GetRenderer()->GetDefaultRenderTargetGroup()->GetRenderTargetBuffer(0));
    if (pkCast2)
        m_pkDevice->SetRenderTarget(0, pkCast2->GetSurface());

    bWait = b1;
    if (afFinalFloat != DAT_01012060)
        bWait = false;
    uiStart = GetTickCount();
    while (Update(bWait, b3, b5))
    {
        if (afFinalFloat != DAT_01012060)
        {
            uiNow3 = GetTickCount();
            if (uiNow3 - uiStart > (unsigned int)(afFinalFloat * 1000.0))
            {
                bWait = true;
                afFinalFloat = 0.0f;
            }
        }
    }

    bRet = m_uiFrame >= m_pkBink->m_uiFrames;
    Movie_Stop();
    if (b6)
        DAT_0126fac4->EndMoviePlayback();
    if (b7)
        DAT_0126fac4->vf04();
    return bRet;
}
