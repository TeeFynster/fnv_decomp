
// src/bsshader/imagespaceeffectinterface.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffectinterface.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/MemoryManager.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiTexture.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

extern MemoryManager g_memoryManager_011f6238;

void __cdecl PipboyFree(void* pvMem);

// The original inlines the atomic release and the virtual DeleteThis call.
inline void NiTexture::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<long volatile*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

extern NiTexture* g_pkScanlines_01200810;

extern NiTexture* g_pkDistortMap_01200814;

extern NiTexture* g_spPipboyTexture_01200818;

void __cdecl FUN_00b55840(const char* pPath, int iFlags, NiTexture** ppTexture, int a4, int a5);

struct PipboyParamBase
{
};

struct PipboyPass : PipboyParamBase
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
        return g_memoryManager_011f6238.Allocate(uiSize);
    }

    static void operator delete(void* pvMem)
    {
        PipboyFree(pvMem);
    }

    void ImageSpaceTexture_SetTexture_00ba37f0(NiTexture* pkTexture);

    void NiShader_SetImplementation(int iValue);

    NiTexture* ImageSpaceTexture_GetTexture();
};

struct PipboyConstantsBase : PipboyParamBase
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
        return g_memoryManager_011f6238.Allocate(uiSize);
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
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_00a90180(unsigned int uiSize);

    __declspec(noinline) void FUN_00ba3aa0(unsigned int uiIndex, T const& kElem)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (kElem)
                ++m_usESize;
        }
        else if (kElem)
        {
            if (!m_pBase[uiIndex])
                ++m_usESize;
        }
        else if (m_pBase[uiIndex])
            --m_usESize;
        m_pBase[uiIndex] = kElem;
    }

    __forceinline void Assign(unsigned int index, T value)
    {
        FUN_00ba3aa0(index, value);
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
};

extern float g_f011ae5e8;

extern float g_f011ae5ec;

extern float g_f011ae5f0;

extern float g_f011ae5f4;

extern float g_f011ae5f8;

extern float g_f012007e8;

extern float g_f012007f0;

extern float g_f012007f4;

extern float g_af01200800[4];

extern bool g_b012007f8;

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

struct PipboyShader
{

    int unk00;

    unsigned char unk04;

    unsigned char unk05;
    unsigned short unk06;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;

    PipboyArray<PipboyParamBase*> m_kConstants;

    PipboyArray<PipboyParamBase*> m_kPasses;

    void SetTextureArraySize(int iCount);

    void SetEntryRanges(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);

    void FUN_00ba3c70(int iIndex, void* pkData, PipboyConstants* pkConstants, int a4);

    void SetupScanlineDistortion(PipboyGeometry* pkGeometry, int iUnused);
};

// @fnv 0x00bb89b0
void PipboyShader::SetupScanlineDistortion(PipboyGeometry* pkGeometry, int iUnused)

{

    unk04 = 0;

    SetTextureArraySize(2);

    m_kPasses.FUN_00a90180(5);

    FUN_00b55840(s_szScanlines, 1, &g_pkScanlines_01200810, 0, 0);

    NiTexture* pkScanlines = g_pkScanlines_01200810;

    FUN_00b55840(s_szDistortMap, 1, &g_pkDistortMap_01200814, 0, 0);

    // The distortion snapshot is dead before the texel scale is computed.
    union DistortionTexel
    {
        NiTexture* pointer;
        float texel;
    } distortion;
    distortion.pointer = g_pkDistortMap_01200814;

    {
        PipboyParamBase* pPass = new PipboyPass;
        m_kPasses.FUN_00ba3aa0(3, pPass);
    }

    static_cast<PipboyPass*>(m_kPasses.GetAt(3))->ImageSpaceTexture_SetTexture_00ba37f0(pkScanlines);

    static_cast<PipboyPass*>(m_kPasses.GetAt(3))->NiShader_SetImplementation(3);

    {
        PipboyParamBase* pPass = new PipboyPass;
        m_kPasses.FUN_00ba3aa0(4, pPass);
    }

    NiTexture* pkDistort = distortion.pointer;
    static_cast<PipboyPass*>(m_kPasses.m_pBase[4])->ImageSpaceTexture_SetTexture_00ba37f0(pkDistort);

    static_cast<PipboyPass*>(m_kPasses.GetAt(4))->NiShader_SetImplementation(0);

    {
        PipboyParamBase* pPass = new PipboyPass;
        m_kPasses.FUN_00ba3aa0(2, pPass);
    }

    static_cast<PipboyPass*>(m_kPasses.GetAt(2))->NiShader_SetImplementation(0);

    static_cast<PipboyPass*>(m_kPasses.GetAt(2))->ImageSpaceTexture_SetTexture_00ba37f0(0);

    if (g_spPipboyTexture_01200818)
    {

        g_spPipboyTexture_01200818->DecRefCount();

        g_spPipboyTexture_01200818 = 0;
    }

    float fTexelX = 0.0f;

    float fTexelY = 0.0f;

    if (m_kPasses.m_pBase[0])
    {

        NiTexture* pkSource = static_cast<PipboyPass*>(m_kPasses.m_pBase[0])->ImageSpaceTexture_GetTexture();

        fTexelX = 1.0f / (float)pkSource->GetWidth() * g_f011ae5e8;

        fTexelY = 1.0f / (float)pkSource->GetHeight() * g_f011ae5e8;
    }

    PipboyConstants* pkConst0 = new PipboyConstants;

    pkConst0->FUN_00b8ab10(0, 4);

    pkConst0->unk55 = 1;

    pkConst0->unk56 = 1;

    pkConst0->FUN_00b8a790(0, g_f011ae5ec, g_f012007e8, g_f011ae5f4, g_f011ae5f0);

    pkConst0->FUN_00b8a790(1, g_f012007f0, g_f012007f4, g_f011ae5f8, g_b012007f8 ? 1.0f : 0.0f);

    pkConst0->FUN_00b8a790(2, g_af01200800[0], g_af01200800[1], g_af01200800[2], g_af01200800[3]);

    pkConst0->FUN_00b8a790(3, fTexelX, fTexelY, 0.0f, 0.0f);

    PipboyConstants* pkConst1 = new PipboyConstants;

    pkConst1->FUN_00b8ab10(0, 5);

    pkConst1->unk55 = 1;

    pkConst1->unk56 = 1;

    pkConst1->FUN_00b8a790(0, g_f011ae5ec, g_f012007e8, g_f011ae5f4, g_f011ae5f0);

    pkConst1->FUN_00b8a790(1, g_f012007f0, g_f012007f4, g_f011ae5f8, g_b012007f8 ? 1.0f : 0.0f);

    pkConst1->FUN_00b8a790(2, g_af01200800[0], g_af01200800[1], g_af01200800[2], g_af01200800[3]);

    pkConst1->FUN_00b8a790(3, fTexelX, fTexelY, 0.0f, 0.0f);

    pkConst1->FUN_00b8a790(4, 1.0f, 0.0f, 0.0f, 0.0f);

    m_kConstants.Assign(0, pkConst0);

    m_kConstants.Assign(1, pkConst1);

    SetEntryRanges(0, 2, 1, 3, 4, 0, 0, 0, 0);

    SetEntryRanges(1, 2, 1, 3, 4, 0, 0, 0, 0);

    FUN_00ba3c70(0, pkGeometry->unk08->unk120, pkConst0, 0);

    FUN_00ba3c70(1, pkGeometry->unk08->unk124, pkConst1, 0);
}
