
// src/bsshader/imagespaceeffecttv.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffecttv.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/MemoryManager.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiTexture.h"

extern MemoryManager g_memoryManager_011f6238;
void __cdecl PipboyFree(void* pvMem);

extern NiTexture* g_pkDistortMap_01200840;
extern NiTexture* g_pkScanlines_0120083c;

void __cdecl FUN_00b55840(const char* pPath, int iFlags, NiTexture** ppTexture, int a4, int a5);

struct PipboySourceTexture
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
    virtual unsigned int GetWidth();
    virtual unsigned int GetHeight();
};

struct PipboyPass
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    int unk04;
    int unk08;
    int unk0c;

    PipboyPass()
    {
        unk00 = 0;
        unk01 = 0;
        unk02 = 0;
        unk04 = 0;
        unk08 = 0;
        unk0c = 0;
    }
    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager_011f6238.Game_DoHeapAlloc(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        PipboyFree(pvMem);
    }
    void ImageSpaceTexture_SetTexture_00ba37f0(NiTexture* pkTexture);
    void NiShader_SetImplementation(int iValue);
    PipboySourceTexture* ImageSpaceTexture_GetTexture();
};

struct PipboyConstantsBase
{
    int unk00;
};

struct PipboyConstants : PipboyConstantsBase
{
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
    unsigned char unk054;
    unsigned char unk55;
    unsigned char unk56;
    unsigned char unk057;
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

    PipboyConstants();
    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager_011f6238.Game_DoHeapAlloc(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        PipboyFree(pvMem);
    }
    void FUN_00b8ab10(int a1, int a2);
    void FUN_00b8a790(int iIndex, float f0, float f1, float f2, float f3);
};

template <class T> struct PipboyArray
{
    void* m_vtbl;
    T* m_pBase;
    void FUN_00a90180(unsigned int uiSize);
    __declspec(noalias) void FUN_00ba3aa0(unsigned int uiIndex, T const& kElem);
    T& GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
};

extern float g_f011ae600;
extern float g_f011ae604;
extern float g_f011ae608;
extern float g_f0120081c;
extern float g_f01200820;
extern float g_f01200824;
extern float g_f01200828;
extern float g_f0120082c;
extern float g_f01200830;
extern float g_f01200834;

struct PipboyGeometryData
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
    void* unk120;
    void* unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    void* unk134;
};
struct PipboyGeometry
{
    int unk00;
    int unk04;
    PipboyGeometryData* unk08;
};

static const char s_szScanlines[] = "Data\\Textures\\Pipboy3000\\PipboyScanlines.dds";
static const char s_szDistortMap[] = "Data\\Textures\\Pipboy3000\\PipboyDistortEffectMap.dds";
extern const char g_szPipboyEnd[] = "";

struct PipboyShader2
{
    int unk00;
    unsigned char unk04;
    unsigned char unk005;
    unsigned char unk006;
    unsigned char unk007;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    PipboyArray<PipboyConstantsBase*> m_kConstants;
    unsigned int unk020;
    unsigned int unk024;
    PipboyArray<PipboyPass*> m_kPasses;

    void SetTextureArraySize(int iCount);
    void FUN_00ba3ba0(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    void FUN_00ba3c70(int iIndex, void* pkData, PipboyConstants* pkConstants, int a4);
    void SetupPipboyPasses(PipboyGeometry* pkGeometry, int iUnused);
};

// Configures the Pipboy shader passes, loads scanline and distortion textures, and sets up constants with texel size and global parameters.
// @fnv 0x00bb9200
void PipboyShader2::SetupPipboyPasses(PipboyGeometry* pkGeometry, int iUnused)
{
    SetTextureArraySize(1);
    m_kPasses.FUN_00a90180(4);

    FUN_00b55840(s_szDistortMap, 1, &g_pkDistortMap_01200840, 0, 0);
    FUN_00b55840(s_szScanlines, 1, &g_pkScanlines_0120083c, 0, 0);
    NiTexture* pkScanlines = g_pkScanlines_0120083c;
    NiTexture* pkDistort = g_pkDistortMap_01200840;

    m_kPasses.FUN_00ba3aa0(1, new PipboyPass);
    m_kPasses.GetAt(1)->NiShader_SetImplementation(0);
    m_kPasses.GetAt(1)->ImageSpaceTexture_SetTexture_00ba37f0(0);
    m_kPasses.FUN_00ba3aa0(2, new PipboyPass);
    m_kPasses.GetAt(2)->NiShader_SetImplementation(0);
    m_kPasses.GetAt(2)->ImageSpaceTexture_SetTexture_00ba37f0(pkDistort);
    m_kPasses.FUN_00ba3aa0(3, new PipboyPass);
    m_kPasses.GetAt(3)->NiShader_SetImplementation(3);
    m_kPasses.GetAt(3)->ImageSpaceTexture_SetTexture_00ba37f0(pkScanlines);

    float fTexelX = 0;
    float fTexelY = 0;
    if (m_kPasses.GetAt(0))
    {
        PipboySourceTexture* pkSource = m_kPasses.GetAt(0)->ImageSpaceTexture_GetTexture();
        fTexelX = 1.0f / (float)pkSource->GetWidth();
        fTexelY = 1.0f / (float)pkSource->GetHeight();
    }

    PipboyConstants* pkConst = new PipboyConstants;
    pkConst->FUN_00b8ab10(0, 5);
    pkConst->unk55 = 0;
    pkConst->unk56 = 0;
    pkConst->FUN_00b8a790(0, fTexelX, fTexelY, 0.0f, 0.0f);
    pkConst->FUN_00b8a790(1, g_f011ae600, 0.0f, 0.0f, 0.0f);
    pkConst->FUN_00b8a790(2, g_f0120081c, g_f01200820, g_f011ae604, 0.0f);
    pkConst->FUN_00b8a790(3, g_f01200824, g_f01200828, g_f011ae608, 0.0f);
    pkConst->FUN_00b8a790(4, g_f0120082c, g_f01200830, g_f01200834, 1.0f);

    m_kConstants.FUN_00ba3aa0(0, pkConst);
    FUN_00ba3ba0(0, 1, 2, 3, 0, 0, 0);
    FUN_00ba3c70(0, pkGeometry->unk08->unk134, pkConst, 0);
}
