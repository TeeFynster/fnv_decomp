
// src/staging/blk_00ec0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/MemoryManager.h"
#include "../../include/MoviePlayer.h"
#include "../../include/BGSMoviePlayer.h"

extern BGSMoviePlayer* DAT_0126fac4;
// @fnv 0x00ec16b0
// src: COMMUNITY 0x00ec16b0
int __stdcall MoviePlayer_PlaySequenceThread(int a)
{
    DAT_0126fac4->SetPlaybackOption(a);
    return 0;
}

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct FUN_00ec1a40_Class
{
    void* NiTMap_char_const_char_NewItem();
};
// @fnv 0x00ec1a40
// src: XBOX_PDB 0x00ec1a40
void* FUN_00ec1a40_Class::NiTMap_char_const_char_NewItem()
{
    void* result = g_memoryManager.Allocate(0xc);
    return result;
}

extern "C" int __cdecl _NiStricmp(const char*, const char*);

struct FUN_00ec1c90_class
{
    int __thiscall AreStringsEqualIgnoreCase(const char* a, const char* b);
};

// Returns nonzero when the two strings compare equal ignoring case, via _NiStricmp.
// @fnv 0x00ec1c90
int __thiscall FUN_00ec1c90_class::AreStringsEqualIgnoreCase(const char* pcStringA, const char* pcStringB)
{
    return !_NiStricmp(pcStringA, pcStringB);
}

extern int __cdecl __stricmp(const char*, const char*);

struct FUN_00ec1dc0_Class
{
    int __thiscall IsStringEqualIgnoreCase(const char* a, const char* b);
};

// Returns nonzero when the two strings are equal ignoring case, using __stricmp.
// @fnv 0x00ec1dc0
int __thiscall FUN_00ec1dc0_Class::IsStringEqualIgnoreCase(const char* pcStringA, const char* pcStringB)
{
    return !__stricmp(pcStringA, pcStringB);
}

struct FUN_00ec1f20Class
{
    void Movie_ClearData();
    void* Movie_Movie();
};

// @fnv 0x00ec1f20
// src: COMMUNITY 0x00ec1f20
void* FUN_00ec1f20Class::Movie_Movie()
{
    Movie_ClearData();
    return this;
}

struct FUN_00ec1f40Class
{
    void __thiscall Movie_Stop();
    void __thiscall Movie_Stop_Thunk();
};

// @fnv 0x00ec1f40
// src: GUESS 0x00ec1f40 (confidence: medium)
void __thiscall FUN_00ec1f40Class::Movie_Stop_Thunk()
{
    Movie_Stop();
}

namespace fnv_00ec20a0 {
extern MemoryManager g_memoryManager;
// @fnv 0x00ec20a0
// src: GUESS 0x00ec20a0 (confidence: medium)
void __stdcall Object_ReleaseStorage_00ec20a0(void* apMemory)
{
    g_memoryManager.Deallocate(apMemory);
}
}  // namespace fnv_00ec20a0

// @fnv 0x00ec29b0
void BGSMoviePlayer::RequestInterruption()
{
    ((char*)this)[0x21] = 1;
}

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
// If m_002c is below 5, calls SetThreadPriorityLevel with m_002c + 1.
// @fnv 0x00ec2c10
// src: GUESS 0x00ec2c10 (confidence: high)
void __thiscall FUN_00ec2c10::IncreaseThreadPriorityUpToFive()
{
    if (m_002c < 5)
        SetThreadPriorityLevel(m_002c + 1);
}

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
// Resets all fields of the structure: integer fields to 0, f to 1.0, g and h to 0.0, and j to false.
// @fnv 0x00ec1570
// src: COMMUNITY 0x00ec1570
void __fastcall Movie_ClearData(FUN_00ec1570_t* p)
{
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->f = 1.0f;
    p->g = 0.0f;
    p->h = 0.0f;
    p->i = 0;
    p->j = false;
}

struct FUN_00ec15e0_shell
{
    void __thiscall FUN_00ec15e0();
};
struct FUN_00ec19d0_class
{
    void* __thiscall FUN_00ec19d0(unsigned int flags);
};
// @fnv 0x00ec19d0
void* __thiscall FUN_00ec19d0_class::FUN_00ec19d0(unsigned int flags)
{
    ((FUN_00ec15e0_shell*)this)->FUN_00ec15e0();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}

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
// @fnv 0x00ec1f60
unsigned char FUN_00ec1f60_Class::InitAndCheck(int aiValue, unsigned char b)
{
    *(int*)((char*)this + 0x20) = 2;
    *(unsigned char*)((char*)this + 0x24) = 1;
    if (!((FUN_00ec0cd0_Class*)this)->InitPlayback(aiValue, 1, b, 0))
    {
        *(unsigned char*)((char*)this + 0x24) = 0;
        return 0;
    }
    *(unsigned char*)((char*)this + 0x24) = 0;
    return 1;
}

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
// If a movie is set, warns when another is already paused, calls DisableThreadPriorityBoost on it, stores it as the paused movie and clears the active movie pointer.
// @fnv 0x00ec2a10
void __thiscall FUN_00ec2a10_class::PauseMovie()
{
    if (!m_000c)
        return;
    if (m_0010)
        FNV_Warning(
            "DEFAULT: Trying to pause a movie while another movie is already paused.  This is not currently supported.");
    ((FUN_00ec1fb0_class*)m_000c)->DisableThreadPriorityBoost();
    m_0010 = m_000c;
    m_000c = 0;
}

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
// Stores a into m_0014, clears m_0004, calls the callback at m_001c, then clears m_001c.
// @fnv 0x00ec2d40
void __thiscall FUN_00ec2d40_class::SetValueAndReset(int aiValue)
{
    m_0014 = aiValue;
    m_0004 = 0;
    ((void(__thiscall*)(void))this->m_001c)();
    m_001c = 0;
}

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
// Returns v10() divided by a when c is true, otherwise v11() divided by b, as a float.
// @fnv 0x00ec2aa0
float __thiscall FUN_00ec2aa0_Class::ComputeRatio(unsigned int auiDivisorA, unsigned int auiDivisorB, bool abUseFirst)
{
    if (abUseFirst)
        return (float)v10() / auiDivisorA;
    else
        return (float)v11() / auiDivisorB;
}

extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int priority);

// Maps a level 0-5 to a thread priority, stores the level in m_002c and applies the priority to the thread handle at offset 8.
// @fnv 0x00ec18a0
void __thiscall FUN_00ec2c10::SetThreadPriorityLevel(int aiLevel)
{
    int b;
    switch (aiLevel)
    {
    case 0:
        b = -2;
        break;
    case 1:
        b = -1;
        break;
    case 2:
        b = 0;
        break;
    case 3:
        b = 1;
        break;
    case 4:
        b = 2;
        break;
    case 5:
        b = 15;
        break;
    default:
        b = 0;
        break;
    }
    m_002c = aiLevel;
    SetThreadPriority(*(void**)((char*)this + 8), b);
}

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
// If m_000c is clear and m_0010 is set, moves m_0010 into m_000c, clears m_0010 and calls UnpauseBink on it.
// @fnv 0x00ec2a60
// src: COMMUNITY 0x00ec2a60
void __thiscall FUN_00ec2a60_class::MoviePlayer_Resume()
{
    if (m_000c)
        return;
    if (m_0010)
    {
        m_000c = m_0010;
        m_0010 = 0;
        ((FUN_00ec1fd0_shell*)m_000c)->UnpauseBink();
    }
}

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

// If c is set, returns half of the difference between v11() and b times a; otherwise returns 0.0f.
// @fnv 0x00ec2bb0
// src: COMMUNITY 0x00ec2bb0
float FUN_00ec2bb0_Class::MoviePlayer_CalculateYOffset(float afValue, unsigned int b, bool abEnabled)
{
    if (!abEnabled)
        return 0.0f;
    return (v11() - b * afValue) / 2.0;
}

extern "C" __declspec(dllimport) int __stdcall GetExitCodeThread(void* hThread, unsigned long* pExitCode);

struct FUN_00ec17c0_Class
{
    int m_0000;
    int m_0004;
    void* m_0008;
    bool MoviePlayer_GetPlayingSequence();
};

// Returns true when m_0008 is set and GetExitCodeThread reports exit code 0x103 for it.
// @fnv 0x00ec17c0
// src: XBOX_PDB 0x00ec17c0
bool FUN_00ec17c0_Class::MoviePlayer_GetPlayingSequence()
{
    if (!m_0008)
        return false;
    unsigned long iexitCode;
    GetExitCodeThread(m_0008, &iexitCode);
    return iexitCode == 0x103;
}

struct FUN_00ec19a0_Class
{
    int m_0000;
    void* m_0004;
    void __thiscall WaitForStoredHandle();
};

extern "C" __declspec(dllimport) void __stdcall FUN_00fdf1c8(void* a, int b);

// If m_0004 is non-null, calls FUN_00fdf1c8 with m_0004 and -1.
// @fnv 0x00ec19a0
// src: GUESS 0x00ec19a0 (confidence: medium)
void FUN_00ec19a0_Class::WaitForStoredHandle()
{
    if (m_0004)
        FUN_00fdf1c8(m_0004, -1);
}

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
// Clears the third field of the struct, then deallocates it through g_memoryManager.
// @fnv 0x00ec1a60
void __thiscall FUN_00ec1a60_class::FreeStruct(FUN_00ec1a60_t* pStruct)
{
    pStruct->c = 0;
    FUN_00ec1a60_t* q = pStruct;
    ((MemoryManager*)&g_memoryManager)->Deallocate(q);
}

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
// @fnv 0x00ec1b80
void __thiscall FUN_00ec1b80_Class::Initialize()
{
    int pad1;
    int pad2;
    m_0000 = (int)&DAT_010f1ca4;
    ((FUN_00ec1b80_Map*)this)->RemoveAll();
    _NiFree((void*)m_0008);
}

void* __cdecl _NiMalloc(unsigned int size);
unsigned int __cdecl _strlen(const char* s);
int __cdecl _strcpy_s(char* dest, unsigned int size, const char* src);

struct FUN_00ec1cc0_Class
{
    void __thiscall AssignString(void* a, const char* b, int c);
};

// Stores a string into a+4 (copying it when this+0x10 is set) and stores c into a+8.
// @fnv 0x00ec1cc0
void __thiscall FUN_00ec1cc0_Class::AssignString(void* apTarget, const char* apString, int aiValue)
{
    if (*(unsigned char*)((char*)this + 0x10))
    {
        unsigned int uiLen = _strlen(apString) + 1;
        *(void**)((char*)apTarget + 4) = _NiMalloc(uiLen);
        void* dest = *(void**)((char*)apTarget + 4);
        _strcpy_s((char*)dest, uiLen, apString);
    }
    else
    {
        *(void**)((char*)apTarget + 4) = (void*)apString;
    }
    *(int*)((char*)apTarget + 8) = aiValue;
}

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
// @fnv 0x00ec1d30
// src: GUESS 0x00ec1d30 (confidence: low)
void __thiscall FUN_00ec1d30_Class::UpdateState_00ec1d30()
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    m_ppVirtualMethodTable = (int)&DAT_010f1c20;
    FUN_00ec1a90();
}

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

// @fnv 0x00ec0460
// src: COMMUNITY 0x00ec0460
void __cdecl Setup_Renderstate(FUN_00ec0460_cls* p)
{
    p->v57(0x1b, 0);
    p->v67(0, 4, 2);
    p->v67(0, 2, 2);
    p->v67(0, 5, 2);
    p->v67(0, 1, 4);
    p->v69(0, 6, 2);
    p->v69(0, 5, 2);
    p->v69(0, 7, 2);
    p->v69(0, 1, 3);
    p->v69(0, 2, 3);
}

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

// @fnv 0x00ec0550
// src: GUESS 0x00ec0550 (confidence: low)
void __cdecl Runtime_ProcessEntries_00ec0550(GridDesc* grid, float startX, float startY, float scaleX, float scaleY)
{
    float x;
    unsigned int row;
    unsigned int col_2;
    float stepY;
    float y_;
    float stepX4;

    stepX4 = (float)grid->cellSize * scaleX;
    stepY = (float)grid->cellSize * scaleY;
    y_ = startY;
    for (row = 0; row < grid->rows; row++)
    {
        x = startX;
        for (col_2 = 0; col_2 < grid->cols; col_2++)
        {
            Object_UpdateFields_00ec0720(grid->unk00, x, y_, scaleX, scaleY, grid->cellSize, grid->cellSize);
            x += stepX4;
        }
        if (grid->extraX)
        {
            Object_UpdateFields_00ec0720(grid->unk00, x, y_, scaleX, scaleY, grid->extraX, grid->cellSize);
        }
        y_ += stepY;
    }
    if (grid->extraY)
    {
        x = startX;
        for (col_2 = 0; col_2 < grid->cols; col_2++)
        {
            Object_UpdateFields_00ec0720(grid->unk00, x, y_, scaleX, scaleY, grid->cellSize, grid->extraY);
            x += stepX4;
        }
        if (grid->extraX)
        {
            Object_UpdateFields_00ec0720(grid->unk00, x, y_, scaleX, scaleY, grid->extraX, grid->extraY);
        }
    }
}

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

// Loads the playback size if needed, queries the manager for renderer, frame rate and scales, allocates textures and warns on failure.
// @fnv 0x00ec0cd0
bool NiPlaybackFile::InitPlayback(const char* pcName, bool bQuiet, bool bLoop, bool bLooping)
{
    if (m_pkSize == 0 && !FindString(pcName, bQuiet, bLoop, false))
        return false;

    m_iRenderer = ((NiPlaybackManager*)DAT_0126fac4)->GetRenderer();
    m_fTextureScale = ((NiPlaybackManager*)DAT_0126fac4)->GetFrameRate(m_pkSize->uiWidth, m_pkSize->uiHeight, bLooping);
    m_fWidthScale = ((NiPlaybackManager*)DAT_0126fac4)->GetWidthScale(m_fTextureScale, m_pkSize->uiWidth, bLooping);
    m_fHeightScale = ((NiPlaybackManager*)DAT_0126fac4)->GetHeightScale(m_fTextureScale, m_pkSize->uiHeight, bLooping);
    m_pkTextures = CreatePlaybackTextures(m_iRenderer, m_pkSize->uiWidth, m_pkSize->uiHeight, 4, 0x100, 0x16);
    if (m_pkTextures == 0)
    {
        if (!bQuiet)
            FNV_Warning("Could not allocate textures for %s playback.", pcName);
        m_iFadeIndex = 0;
        return false;
    }
    return true;
}

extern "C" __declspec(dllimport) void __stdcall BinkClose(int handle);
void __cdecl ReleaseInterfaceArray(int value);

struct FUN_00ec1020_cls
{
    int m_00;
    int m_04;
    int m_08;
    void Movie_Stop();
};

// @fnv 0x00ec1020
// src: COMMUNITY 0x00ec1020
void FUN_00ec1020_cls::Movie_Stop()
{
    if (m_00 != 0)
    {
        BinkClose(m_00);
    }
    if (m_08 != 0)
    {
        ReleaseInterfaceArray(m_08);
    }
    Movie_ClearData((FUN_00ec1570_t*)this);
}

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

// @fnv 0x00ec14d0
unsigned char __cdecl DecodeBinkFrame(FUN_00ec14d0_bink* a1, unsigned int a2, int a3)
{
    int result2 = 1;
    int v1;
    int v2;
    int v3;
    int v8;
    int vB;
    int v7;

    BinkDoFrame(a1);
    while (LockNextTile(a2, &v7, &vB, &v8, &v3, &v2, &v1) != 0)
    {
        result2 = BinkCopyToBufferRect(a1, (void*)v7, vB, a1->m_04, 0, 0, v8, v3, v2, v1,
                                       ((a3 != 0 ? -1 : 0) & 0x80000000u) | 3u);
        ApplyLastEffect(a2);
    }
    return result2 != 0;
}

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

// If bEnableSound is set, installs BinkOpenDirectSound as the Bink sound system with flags 0.
// @fnv 0x00ec1680
void FUN_00ec1680_cls::EnableSoundSystem(bool bEnableSound)
{
    if (bEnableSound)
    {
        BinkSetSoundSystem((void*)&BinkOpenDirectSound, 0);
    }
}

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

// Creates the movie player thread, stores the flags and value, sets its priority, resumes it and waits on the start semaphore.
// @fnv 0x00ec16d0
// src: COMMUNITY 0x00ec16d0
void BEC16D0MoviePlayerThread::MoviePlayer_StartSequence(void* pvParam, bool bFlag22, int iPriority, bool bFlag23, bool bFlag24,
                                            float fValue28)
{
    unsigned long ulThreadId3;
    m_hThread = CreateThread(0, 0, (unsigned long(__stdcall*)(void*))MoviePlayer_PlaySequenceThread, pvParam, 4, &ulThreadId3);
    FUN_00aa2740(ulThreadId3, "MoviePlayer");
    m_bFlag22 = bFlag22;
    m_bFlag23 = bFlag23;
    m_bFlag24 = bFlag24;
    m_fValue28 = fValue28;
    if (iPriority == -1)
    {
        int* piPriority = &g_kEC16D0PrioritySetting ? &g_kEC16D0PrioritySetting.m_iValue
                                                    : (g_iEC16D0DefaultSetting = 0, &g_iEC16D0DefaultSetting);
        SetPriority(*piPriority);
    }
    else
    {
        SetPriority(iPriority);
    }
    ResumeThread(m_hThread);
    ulThreadId3 = 0;
    {
        BEC16D0Semaphore* pkSemaphore = &m_kStartSemaphore;
        WaitForSingleObject(pkSemaphore->m_pSemaphore, 0xffffffff);
        InterlockedDecrement(&pkSemaphore->m_lCount);
    }
}

extern int DAT_010f1ca4;
void __cdecl _NiFree_00aa10f0(int aValue);

struct FUN_00ec1df0_pool
{
    void MemoryManager_Deallocate(void* apMemory);
};
extern FUN_00ec1df0_pool DAT_011f6238;

struct FUN_00ec1df0_cls
{
    int m_vptr;
    int m_04;
    int m_08;

    void BaseCleanup();

    FUN_00ec1df0_cls* FUN_00ec1df0(unsigned int acFlags);
};

// @fnv 0x00ec1df0
FUN_00ec1df0_cls* FUN_00ec1df0_cls::FUN_00ec1df0(unsigned int acFlags)
{
    int unk00;
    int unk04;
    m_vptr = (int)&DAT_010f1ca4;
    BaseCleanup();
    _NiFree_00aa10f0(m_08);
    if (acFlags & 1)
    {
        DAT_011f6238.MemoryManager_Deallocate(this);
    }
    return this;
}

namespace fnv_00ec1ee0 {
extern int DAT_010f1c20;

class FUN_00ec1ee0_pool
{
  public:
    void MemoryManager_Deallocate(void* apMemory);
};
extern FUN_00ec1ee0_pool DAT_011f6238;

struct FUN_00ec1ee0_frame
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

struct FUN_00ec1ee0_cls
{
    int m_vptr;
    int unk04;

    void BaseCleanup();

    FUN_00ec1ee0_cls* FUN_00ec1ee0(unsigned int auiFlags);
};

// @fnv 0x00ec1ee0
FUN_00ec1ee0_cls* FUN_00ec1ee0_cls::FUN_00ec1ee0(unsigned int auiFlags)
{
    FUN_00ec1ee0_frame frame;
    m_vptr = (int)&DAT_010f1c20;
    BaseCleanup();
    if (auiFlags & 1)
    {
        DAT_011f6238.MemoryManager_Deallocate(this);
    }
    return this;
}
}  // namespace fnv_00ec1ee0

extern "C" __declspec(dllimport) int __stdcall SetThreadPriorityBoost(void* hThread, int fDisable);

// @fnv 0x00ec1fb0
void FUN_00ec1fb0_class::DisableThreadPriorityBoost()
{
    SetThreadPriorityBoost(reinterpret_cast<void*>(reinterpret_cast<int*>(this)[0]), 1);
}

extern "C" __declspec(dllimport) void __stdcall _BinkPause_8(void*, int);

// @fnv 0x00ec1fd0
void __thiscall FUN_00ec1fd0_shell::UnpauseBink()
{
    _BinkPause_8(*(void**)this, 0);
}

namespace fnv_00ec25e0 {
struct FUN_00aa4060_Obj
{
    void __thiscall MemoryManager_Deallocate(FUN_00ec1f40Class* p);
};
extern FUN_00aa4060_Obj DAT_011f6238;

struct FUN_00ec25e0_cls
{
    int m_0000;
    int m_0004;
    int m_0008;
    FUN_00ec1f40Class* m_000c;
    void __thiscall MoviePlayer_Resume();
    void __thiscall MoviePlayer_Stop();
};

// If m_000c is set, calls FUN_00ec1f40 and DAT_011f6238.FUN_00aa4060 on it, clears m_000c, then calls FUN_00ec2a60.
// @fnv 0x00ec25e0
// src: COMMUNITY 0x00ec25e0
void __thiscall FUN_00ec25e0_cls::MoviePlayer_Stop()
{
    if (m_000c != 0)
    {
        FUN_00ec1f40Class* t2 = m_000c;
        FUN_00ec1f40Class* p = t2;
        p != 0 ? (p->Movie_Stop_Thunk(), (((0, 1) & 1) ? DAT_011f6238.MemoryManager_Deallocate(p) : (void)0), p) : 0;
        m_000c = 0;
    }
    MoviePlayer_Resume();
}
}  // namespace fnv_00ec25e0

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
// Returns v13() as a float when c is set, otherwise v13() plus half of (v10() minus b times a).
// @fnv 0x00ec2b20
float __thiscall S_00ec2b20::ComputeAdjustedValue(float afScale, unsigned int auiValue, bool abDirect)
{
    if (abDirect)
        return (float)v13();
    return (float)((double)v13() + ((double)v10() - (double)auiValue * afScale) / 2.0);
}

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

// If m_002c exceeds the current limit (DAT_0126fae4 or DAT_01202800), calls SetThreadPriorityLevel with m_002c - 1.
// @fnv 0x00ec2c40
// src: COMMUNITY 0x00ec2c40
void FUN_00ec2c40_cls::MoviePlayer_DecreaseSequenceThreadPriority()
{
    int* q = (&DAT_0126fae0 != 0) ? &DAT_0126fae4 : (DAT_01202800 = 0, &DAT_01202800);
    if (m_002c > *q)
    {
        SetThreadPriorityLevel(m_002c - 1);
    }
}

namespace fnv_00ec2d80 {
struct S_00ec2f00_Class
{
    void __thiscall AddOrUpdate(int a, char* b);
};

struct S_00aa3e40_Class
{
    char* __thiscall Game_DoHeapAlloc(char* a);
};

struct S_00ec2d80_Class
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
    int m_0030;
    int m_0034;
    int m_0038;
    int m_003c;
    S_00ec2f00_Class m_0040;

    void __thiscall UpdateFields_00ec2d80(int a, int b);
};

extern S_00aa3e40_Class DAT_011f6238;

char* __cdecl FUN_00ec6130(int a);
void __cdecl FUN_00ec65a6(char* a, char* b, int c);

// @fnv 0x00ec2d80
// src: GUESS 0x00ec2d80 (confidence: low)
void __thiscall S_00ec2d80_Class::UpdateFields_00ec2d80(int a, int b)
{
    char* p;
    char* oB;
    char* n;
    char* m;
    char* l;
    char* k;
    char* j;

    oB = FUN_00ec6130(b);
    n = DAT_011f6238.Game_DoHeapAlloc(oB + 1);
    p = n;

    FUN_00ec65a6(p, oB + 1, b);
    this->m_0040.AddOrUpdate(a, p);
}
}  // namespace fnv_00ec2d80

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

// Looks up uiKey in m_kNames and, if found, copies the name into pcPath with strcpy_s and returns true; otherwise returns false.
// @fnv 0x00ec2df0
bool EC2DF0Registry::GetNameByKey(unsigned int uiKey, char* pcPath)
{
    const char* pcFile = 0;
    char* pcDest;             // declared but never used in this build
    unsigned int uiDestSize;  // declared but never used in this build
    if (m_kNames.GetAt(uiKey, pcFile))
    {
        const char* pcSource = pcFile;
        strcpy_s(pcPath, 260, pcSource);
        return true;
    }
    return false;
}

struct EC0280Vertex
{
    float x;
    float y;
    float z;
    float rhw;
    float u;
    float v;
};
struct EC0280Device
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
    virtual void __stdcall v37();
    virtual void __stdcall v38();
    virtual void __stdcall v39();
    virtual void __stdcall v40();
    virtual void __stdcall v41();
    virtual void __stdcall v42();
    virtual void __stdcall v43();
    virtual void __stdcall v44();
    virtual void __stdcall v45();
    virtual void __stdcall v46();
    virtual void __stdcall v47();
    virtual void __stdcall v48();
    virtual void __stdcall v49();
    virtual void __stdcall v50();
    virtual void __stdcall v51();
    virtual void __stdcall v52();
    virtual void __stdcall v53();
    virtual void __stdcall v54();
    virtual void __stdcall v55();
    virtual void __stdcall v56();
    virtual void __stdcall v57();
    virtual void __stdcall v58();
    virtual void __stdcall v59();
    virtual void __stdcall v60();
    virtual void __stdcall v61();
    virtual void __stdcall v62();
    virtual void __stdcall v63();
    virtual void __stdcall v64();
    virtual void __stdcall v65();
    virtual void __stdcall v66();
    virtual void __stdcall v67();
    virtual void __stdcall v68();
    virtual void __stdcall v69();
    virtual void __stdcall v70();
    virtual void __stdcall v71();
    virtual void __stdcall v72();
    virtual void __stdcall v73();
    virtual void __stdcall v74();
    virtual void __stdcall v75();
    virtual void __stdcall v76();
    virtual void __stdcall v77();
    virtual void __stdcall v78();
    virtual void __stdcall v79();
    virtual void __stdcall v80();
    virtual void __stdcall v81();
    virtual void __stdcall v82();
    virtual long __stdcall DrawPrimitiveUP(int eType, unsigned int ItemUpdateArray, const void* pvData, unsigned int uiStride);
    virtual void __stdcall v84();
    virtual void __stdcall v85();
    virtual void __stdcall v86();
    virtual long __stdcall SetVertexDeclaration(void* pkDecl);
    virtual long __stdcall GetVertexDeclaration(void** ppkDecl);
    virtual long __stdcall SetFVF(unsigned int uiFVF);
};
struct EC0280RenderState
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
    virtual void SetTexture(int a, int b);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void SetStage(int a, int b);
    virtual void v36();
    virtual void Commit();
};
struct EC0280Renderer
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    EC0280RenderState* m_pCurrentRenderState;
};
extern EC0280Renderer* g_pkEC0280Renderer;

// @fnv 0x00ec0280
void __cdecl DrawTexturedQuad(EC0280Device* pkDevice, float fX, float fY, float fScaleX, float fScaleY, int iWidth,
                              int iHeight)
{
    EC0280Vertex akVertsVal[4];
    {
        void* pkDecl_2;
        EC0280Renderer* pkRenderer5;
        EC0280RenderState* _pkRet1;
        EC0280Renderer* pkRendererTmp;
        EC0280RenderState* pkRetVal;
        EC0280Renderer* pkRenderer4;
        EC0280RenderState* pkRet4;
        akVertsVal[0].x = fX;
        akVertsVal[0].y = fY;
        akVertsVal[0].z = 0.0f;
        akVertsVal[0].rhw = 1.0f;
        akVertsVal[0].u = 0.0f;
        akVertsVal[0].v = 0.0f;
        akVertsVal[1] = akVertsVal[0];
        akVertsVal[1].y = iHeight * fScaleY + fY;
        akVertsVal[1].v = 1.0f;
        akVertsVal[2] = akVertsVal[0];
        akVertsVal[2].x = iWidth * fScaleX + fX;
        akVertsVal[2].u = 1.0f;
        akVertsVal[3] = akVertsVal[2];
        akVertsVal[3].y = akVertsVal[1].y;
        akVertsVal[3].v = 1.0f;

        {
            pkRenderer5 = g_pkEC0280Renderer;
            EC0280RenderState* kPkState1 = _pkRet1;
            kPkState1 = pkRenderer5->m_pCurrentRenderState;
            kPkState1->SetStage(0, 1);
            pkRendererTmp = g_pkEC0280Renderer;
            EC0280RenderState* pkState2 = pkRetVal;
            pkState2 = pkRendererTmp->m_pCurrentRenderState;
            pkState2->SetTexture(0, 0);
            pkDecl_2 = 0;
            pkDevice->GetVertexDeclaration(&pkDecl_2);
            pkDevice->SetFVF(0x104);
            pkDevice->DrawPrimitiveUP(5, 2, akVertsVal, sizeof(EC0280Vertex));
            pkDevice->SetFVF(0);
            pkDevice->SetVertexDeclaration(pkDecl_2);
            pkRenderer4 = g_pkEC0280Renderer;
            EC0280RenderState* pkState5 = pkRet4;
            pkState5 = pkRenderer4->m_pCurrentRenderState;
            pkState5->Commit();
        }
    }
}

struct FUN_00ec0720_Vertex
{
    float x;
    float y;
    float z;
    float rhw;
    float u;
    float v;
};

struct FUN_00ec0720_Device : FUN_00ec0460_cls
{
    virtual void __stdcall v70();
    virtual void __stdcall v71();
    virtual void __stdcall v72();
    virtual void __stdcall v73();
    virtual void __stdcall v74();
    virtual void __stdcall v75();
    virtual void __stdcall v76();
    virtual void __stdcall v77();
    virtual void __stdcall v78();
    virtual void __stdcall v79();
    virtual void __stdcall v80();
    virtual void __stdcall v81();
    virtual void __stdcall v82();
    virtual void __stdcall v83(int a, int b, const void* c, unsigned int d);
    virtual void __stdcall v84();
    virtual void __stdcall v85();
    virtual void __stdcall v86();
    virtual void __stdcall v87();
    virtual void __stdcall v88();
    virtual void __stdcall v89(unsigned int a);
    virtual void __stdcall v90();
    virtual void __stdcall v91();
    virtual void __stdcall v92(int a);
};

// @fnv 0x00ec0720
// src: GUESS 0x00ec0720 (confidence: low)
void __cdecl Object_UpdateFields_00ec0720(FUN_00ec0720_Device* pDevice, float x, float y, float fScaleX, float fScaleY, int iWidth,
                          int iHeight)
{
    FUN_00ec0720_Vertex vertices[12];

    vertices[0].x = x;
    vertices[0].y = y;
    vertices[0].z = 0.0f;
    vertices[0].rhw = 1.0f;
    vertices[0].u = 0.0f;
    vertices[0].v = 0.0f;

    vertices[1] = vertices[0];
    vertices[1].x = (float)iWidth * fScaleX + x;
    vertices[1].y = y;

    vertices[2] = vertices[1];

    vertices[3] = vertices[1];
    vertices[3].y = (float)iHeight * fScaleY + y;

    vertices[4] = vertices[3];

    vertices[5] = vertices[3];
    vertices[5].x = x;

    vertices[6] = vertices[5];

    vertices[7] = vertices[0];

    vertices[8] = vertices[0];

    vertices[9] = vertices[3];

    vertices[10] = vertices[2];

    vertices[11] = vertices[6];

    pDevice->v67(0, 2, 0);
    pDevice->v67(0, 5, 0);
    pDevice->v92(0);
    pDevice->v89(0x104);
    pDevice->v83(2, 6, vertices, 0x18);
}

struct EC1060Size
{
    int a, b;
    unsigned int width, height;
};
struct EC1060Rect
{
    unsigned int left, top, right, bottom;
};
struct EC1060Viewport
{
    float lo, hi;
    unsigned int x, y;
};
struct EC1060Player
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
    virtual void v10();
    virtual void v11();
    virtual bool v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual bool v16(bool);
    char pad[21];
    bool paused;
};
struct EC1060Renderer
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual EC1060Size& v53();
};
struct EC1060Device
{
    virtual void __stdcall v0();
    virtual void __stdcall v1();
    virtual void __stdcall v2();
    virtual void __stdcall v3();
    virtual void __stdcall v4();
    virtual void __stdcall v5();
    virtual void __stdcall v6();
    virtual void __stdcall v7();
    virtual void __stdcall v8();
    virtual void __stdcall v9();
    virtual void __stdcall v10();
    virtual void __stdcall v11();
    virtual void __stdcall v12();
    virtual void __stdcall v13();
    virtual void __stdcall v14();
    virtual void __stdcall v15();
    virtual void __stdcall v16();
    virtual void __stdcall v17(int, int, int, int);
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
    virtual void __stdcall v37();
    virtual void __stdcall v38();
    virtual void __stdcall v39();
    virtual void __stdcall v40();
    virtual void __stdcall v41();
    virtual void __stdcall v42();
    virtual void __stdcall v43(int, int, int, unsigned int, float, int);
    virtual void __stdcall v44();
    virtual void __stdcall v45();
    virtual void __stdcall v46();
    virtual void __stdcall v47(EC1060Rect*);
};
extern "C" char DAT_011f4748;
extern "C" char DAT_011f9426;
extern "C" char DAT_011ad840;
extern "C" char DAT_011ad844;
extern "C" char DAT_011ad848;
extern "C" char DAT_011ad84c;
extern "C" char DAT_010f1be4;
extern "C" __declspec(dllimport) int __stdcall BinkWait(void*);
extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(void*);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);
void __cdecl ProgramFlow(const char*, ...);
void __cdecl Blit_RAD_3D_image_pow2(unsigned int, float, float, float, float);
struct EC1060Bink
{
    int a, b;
    unsigned int frames;
};
struct EC1060File
{
    EC1060Bink* apDirectSound;
    EC1060Device* device;
    unsigned int texture, frame, decoded;
    float scale, x, y;
    int state;
    bool Update(bool, bool, bool);
};
// @fnv 0x00ec1060
bool EC1060File::Update(bool arg1, bool abLoop, bool abNoClip)
{
    EC1060Viewport h, i;
    EC1060Rect a, s;
    EC1060Size *eb, *cf, *q, *b;
    unsigned char p = false;
    if (!((EC1060Player*)DAT_0126fac4)->v16(arg1))
        return false;
    bool f = ((EC1060Player*)DAT_0126fac4)->paused;
    if (!f)
    {
        if (!BinkWait(apDirectSound))
        {
            p = DecodeBinkFrame((FUN_00ec14d0_bink*)apDirectSound, texture, 0);
            if (p)
            {
                decoded++;
                ProgramFlow(&DAT_010f1be4, frame, decoded);
            }
            BinkNextFrame(apDirectSound);
            frame++;
        }
        else if (!(unsigned char)(state == 2))
        {
            Sleep(1);
            return true;
        }
    }
    device->v43(0, 0, 1, 0xff000000, 1.0f, 0);
    if (!abNoClip && *(unsigned char*)&DAT_011f9426)
    {
        eb = &(*(EC1060Renderer* volatile*)&DAT_011f4748)->v53();
        h.x = eb->width;
        cf = &(*(EC1060Renderer* volatile*)&DAT_011f4748)->v53();
        h.y = cf->height;
        h.lo = 0.0f;
        h.hi = 1.0f;
        a.left = (unsigned int)(h.x * *(float*)&DAT_011ad840);
        a.right = (unsigned int)((*(float*)&DAT_011ad844 - *(float*)&DAT_011ad840) * h.x);
        a.top = (unsigned int)(h.y * *(float*)&DAT_011ad84c);
        a.bottom = (unsigned int)((*(float*)&DAT_011ad848 - *(float*)&DAT_011ad84c) * h.y);
        device->v47(&a);
    }
    if (!((EC1060Player*)DAT_0126fac4)->v12())
        device->v41();
    Blit_RAD_3D_image_pow2(texture, x, y, scale, scale);
    if (!((EC1060Player*)DAT_0126fac4)->v12())
        device->v42();
    if (!(unsigned char)(state == 2))
        device->v17(0, 0, 0, 0);
    if (!abNoClip && *(unsigned char*)&DAT_011f9426)
    {
        q = &(*(EC1060Renderer* volatile*)&DAT_011f4748)->v53();
        i.x = q->width;
        b = &(*(EC1060Renderer* volatile*)&DAT_011f4748)->v53();
        i.y = b->height;
        i.lo = 0.0f;
        i.hi = 1.0f;
        s.left = 0;
        s.top = 0;
        s.right = i.x;
        s.bottom = i.y;
        device->v47(&s);
    }
    if (frame >= apDirectSound->frames && !abLoop)
        return false;
    return true;
}

class StrMapW
{
  public:
    void* vtbl;
    unsigned int m_uiHashSize;
    unsigned int HashKey(const char* pKey);
};
// Computes a rolling hash over the characters of pKey and returns it modulo m_uiHashSize.
// @fnv 0x00ec1c30
unsigned int StrMapW::HashKey(const char* pKey)
{
    unsigned int uiHash = 0;
    while (*pKey)
    {
        char c = *pKey;
        uiHash = uiHash + (c + (uiHash << 5));
        pKey++;
    }
    return uiHash % m_uiHashSize;
}

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);

struct MovieJob
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
    unsigned char m_0024;
};


// Sleeps 1 ms in a loop while m_0008 is set and the job is missing or its m_0024 flag is nonzero.
// @fnv 0x00ec29d0
void MoviePlayer::WaitForJobCompletion()
{
    unsigned char busy;
    while (m_0008 != 0 && (m_000c == 0 || (busy = m_000c->m_0024) != 0))
        Sleep(1);
}

struct FUN_00ec2f00_item
{
    FUN_00ec2f00_item* next;
    void* m04;
    unsigned int m08;
};

struct FUN_00ec2f00_cls
{
    virtual void v00();
    virtual int v01(void* a);
    virtual bool v02(void* a, void* b);
    virtual void v03(void* a, void* b, void* c);
    int unk04;
    FUN_00ec2f00_item** m08;
    int m0c;
    unsigned char m10;

    void AddOrUpdate(void* arg8, unsigned int argc);
};

// Finds an item in the m08 bucket matching arg8 via v02, updates it, or allocates and inserts a new one via v03.
// @fnv 0x00ec2f00
void FUN_00ec2f00_cls::AddOrUpdate(void* apKey, unsigned int uiValue)
{
    void* mem;
    FUN_00ec2f00_item* item;
    int idx = v01(apKey);
    item = m08[idx];
    int count = 0;
    while (item)
    {
        count++;
        if (v02(apKey, item->m04))
        {
            if (!m10)
            {
                item->m04 = apKey;
            }
            item->m08 = uiValue;
            return;
        }
        item = item->next;
    }
    mem = reinterpret_cast<P03MM*>(&DAT_011f6238)->Allocate(12);
    item = (FUN_00ec2f00_item*)mem;
    v03(item, apKey, (void*)uiValue);
    item->next = m08[idx];
    m08[idx] = item;
    m0c++;
}

extern "C" int __cdecl _tolower(int c);

struct FUN_00ec1d50_class
{
    int unk00;
    unsigned int unk04;

    unsigned int __thiscall HashString(const char* a);
};

// Computes a case-insensitive string hash using a shift-and-add algorithm and returns the result modulo unk04.
// @fnv 0x00ec1d50
unsigned int FUN_00ec1d50_class::HashString(const char* apString)
{
    unsigned int h = 0;
    char cLower;
    if (1)
    {
    }
    if (1)
    {
    }
    while (*apString)
        h = (h << 5) + h + (cLower = (char)_tolower(*apString++));
    return h % unk04;
}

namespace fnv_00ec1940 {
#include <windows.h>

DWORD WINAPI MoviePlayer_MovieLoadingThread(LPVOID param);
void FUN_00aa2740(DWORD threadId, const char* name);

class FUN_00ec1940_cls
{
  public:
    int unk00;
    HANDLE m_04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_1c;
    void MoviePlayer_ThreadLoadMovie(void* param, int value);
};

// Stores value in m_1c, creates a suspended thread running FUN_00ec2ca0 with param, names it MovieLoader, then resumes it.
// @fnv 0x00ec1940
// src: COMMUNITY 0x00ec1940
void FUN_00ec1940_cls::MoviePlayer_ThreadLoadMovie(void* apThreadArg, int value)
{
    DWORD threadId;
    m_1c = value;
    m_04 = CreateThread(NULL, 0, MoviePlayer_MovieLoadingThread, apThreadArg, CREATE_SUSPENDED, &threadId);
    FUN_00aa2740(threadId, "MovieLoader");
    ResumeThread(m_04);
    threadId = 0;
}
}  // namespace fnv_00ec1940

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);

struct MovieSignalState : BEC16D0MoviePlayerThread
{
    int unk38;
    unsigned char signaled;

    void MoviePlayer_SignalBinkOpen();
};

// Releases m_kStartSemaphore, increments its m_lCount, and sets the signaled flag to 1.
// @fnv 0x00ec1a00
// src: COMMUNITY 0x00ec1a00
void MovieSignalState::MoviePlayer_SignalBinkOpen()
{
    BEC16D0Semaphore* semaphore = &m_kStartSemaphore;
    ReleaseSemaphore(semaphore->m_pSemaphore, 1, 0);
    InterlockedIncrement(&semaphore->m_lCount);
    signaled = 1;
}

struct PlaybackMessage
{
    void* window;
    unsigned int message;
    unsigned int wParam;
    long lParam;
    unsigned long time;
    long cursorX;
    long cursorY;
};

extern "C" __declspec(dllimport) int __stdcall PeekMessageA(PlaybackMessage*, void*, unsigned int, unsigned int,
                                                            unsigned int);
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const PlaybackMessage*);
extern "C" __declspec(dllimport) long __stdcall DispatchMessageA(const PlaybackMessage*);

// Pumps pending Windows messages and returns false if the playback was interrupted, otherwise true.
// @fnv 0x00ec1840
bool __thiscall BGSMoviePlayer::CheckPlaybackContinue(bool allowInterruption)
{
    PlaybackMessage msg;
    while (PeekMessageA(&msg, 0, 0, 0, 1))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    unsigned char c = ((unsigned char*)this)[0x21];
    if (c)
        return false;
    return true;
}
