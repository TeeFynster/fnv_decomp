
// src/bsshader/tileshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/tileshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/TileShaderProperty.h"
#include "../../include/NiTexture.h"
#include "../../include/NiStream.h"
#include "../../include/NiBinaryStream.h"

extern "C" void* g_012007d8;

// @fnv 0x00bb7d60
// src: XBOX_PDB 0x00bb7d60
void* __cdecl TileShaderProperty_GetRTTI()
{
    return &g_012007d8;
}

struct TallGrassShader
{
    void InitializeConstants(unsigned int);
    char _pad[0x38];
    unsigned int m_comb;
    BSShaderProperty::ShaderPassList* m_aiIndexedValues;
    BSShaderProperty::ShaderPassList* SetupGeometryGroup(NiGeometry*, unsigned int, unsigned int, unsigned int,
                                                         unsigned int, unsigned int);
};
// @fnv 0x00bb7a60
BSShaderProperty::ShaderPassList* TallGrassShader::SetupGeometryGroup(NiGeometry* apGeometry, unsigned int auiValue1,
                                                                      unsigned int auiValue2, unsigned int auiValue3,
                                                                      unsigned int auiValue4, unsigned int auiValue5)
{
    InitializeConstants(1);
    if (m_aiIndexedValues->m_uiCount == 0)
    {
        m_aiIndexedValues->Add(apGeometry, 0x42, true, 0, 0, 0, 0, 0);
        m_aiIndexedValues->m_kRenderPasses.m_pBase[m_aiIndexedValues->m_uiCount - 1]->m_ucLightIndex = 1;
        m_comb = (auiValue3 << 8) | auiValue1;
    }
    return m_aiIndexedValues;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
inline void NiTexture::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiTexture::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
// Replaces m_spTexture.m_pObject with apTexture, releasing the old texture and incrementing the new one's reference count when they differ.
// @fnv 0x00bb7a10
// src: XBOX_PDB 0x00bb7a10
void TileShaderProperty::SetTileTexture(NiTexture* apTexture)
{
    if (m_spTexture.m_pObject != apTexture)
    {
        if (m_spTexture.m_pObject)
            m_spTexture.m_pObject->DecRefCount();
        m_spTexture.m_pObject = apTexture;
        if (apTexture)
            apTexture->IncRefCount();
    }
}

// @fnv 0x00bb7ac0
void TileShaderProperty::CopyTileShaderProperty(TileShaderProperty* dst, int flag)
{
    CopyMemberData(dst, reinterpret_cast<CloningProcess*>(flag));

    NiTexture* pOldTile = dst->m_spTexture.m_pObject;
    if (pOldTile != m_spTexture.m_pObject)
    {
        if (pOldTile)
            pOldTile->DecRefCount();
        NiTexture* pTileTexture = m_spTexture.m_pObject;
        dst->m_spTexture.m_pObject = pTileTexture;
        if (pTileTexture)
            pTileTexture->IncRefCount();
    }

    reinterpret_cast<unsigned int&>(dst->m_kFogTint.r) = reinterpret_cast<unsigned int&>(m_kFogTint.r);
    reinterpret_cast<unsigned int&>(dst->m_kFogTint.g) = reinterpret_cast<unsigned int&>(m_kFogTint.g);
    reinterpret_cast<unsigned int&>(dst->m_kFogTint.b) = reinterpret_cast<unsigned int&>(m_kFogTint.b);
    reinterpret_cast<unsigned int&>(dst->m_kFogTint.a) = reinterpret_cast<unsigned int&>(m_kFogTint.a);
    dst->m_iUnk8C = m_iUnk8C;
    dst->m_fAlpha = m_fAlpha;
    dst->m_bUnk93 = m_bUnk93;
    dst->m_bUnk90 = m_bUnk90;
}

// @fnv 0x00bb7e70
TileShaderProperty* TileShaderProperty::CreateTilePropertyClone(int flag)
{
    TileShaderProperty* result = new TileShaderProperty(false);
    CopyTileShaderProperty(result, flag);
    return result;
}

inline NiColorA::NiColorA(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA)
{}

template <> inline BSStringT<char>::BSStringT() : pString(0), sLen(0), sMaxLen(0)
{}

// Initializes the object's texture pointers, color, float fields, flags and integer fields to their default values.
// @fnv 0x00bb7c30
TileShaderProperty::TileShaderProperty(bool bFlag)
{
    m_spTexture = 0;
    m_spTexture2 = 0;
    m_kFogTint.r = 1.0f;
    m_kFogTint.g = 1.0f;
    m_kFogTint.b = 1.0f;
    m_kFogTint.a = 1.0f;
    m_fAlpha = 1.0f;
    m_afUnk7C[1] = 0.0f;
    m_afUnk7C[0] = 0.0f;
    m_iUnk8C = 3;
    m_bUnk93 = bFlag;
    m_bUnk90 = false;
    m_bUnk91 = false;
    iShader = 0x20;
    iShaderPropertyType = 0x13;
    m_bUnkAC = false;
    m_bUnk92 = false;
    m_afUnk7C[3] = 1.0f;
    m_afUnk7C[2] = 1.0f;
}

// the stream's write/read go through its two function pointers; the position counter advances by what they report
inline unsigned int NiBinaryStream::BinaryWrite(const void* pvSrc, unsigned int uiBytes, unsigned int* puiSizes,
                                                unsigned int uiParts)
{
    unsigned int uiDone;
    uiDone = m_pfnWrite(this, pvSrc, uiBytes, puiSizes, uiParts);
    this->m_uiAbsoluteCurrentPos += uiDone;
    return uiDone;
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvDst, unsigned int uiBytes, unsigned int* puiSizes,
                                               unsigned int uiParts)
{
    unsigned int uiDone;
    uiDone = m_pfnRead(this, pvDst, uiBytes, puiSizes, uiParts);
    this->m_uiAbsoluteCurrentPos += uiDone;
    return uiDone;
}

// The shared BSShaderProperty header does not yet declare these two base stream methods.
// This call interface supplies only their declarations, with no duplicate object layout.
struct BSShaderPropertyStreamIO
{
    void BSShaderProperty_LoadBinary(NiStream* stream);
    void BSShaderProperty_SaveBinary(NiStream* stream);
};
void __cdecl _NiFree_00aa10f0(unsigned int v);
template <class T> inline void LoadBin(NiBinaryStream& kStream, T& val)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&val, sizeof(T), &uiSize, 1);
}

// Loads the base property and tile mode, then reads and assigns the tile name.
// @fnv 0x00bb7b60
// src: XBOX_PDB 0x00bb7b60
void TileShaderProperty::LoadBinary_00bb7b60(NiStream* a1)
{
    reinterpret_cast<BSShaderPropertyStreamIO*>(this)->BSShaderProperty_LoadBinary(a1);
    LoadBin(*a1->m_pkIstr, m_iUnk8C);
    char* v = 0;
    a1->ReadStreamString(v);
    m_kName.Set(v, 0);
    _NiFree_00aa10f0(reinterpret_cast<unsigned int>(v));
}

template <class T> inline void SaveBin(NiBinaryStream& kStream, const T& val)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&val, sizeof(T), &uiSize, 1);
}
// Saves the base property, tile mode and tile name.
// @fnv 0x00bb7be0
// src: XBOX_PDB 0x00bb7be0
void TileShaderProperty::SaveBinary_00bb7be0(NiStream* a1)
{
    reinterpret_cast<BSShaderPropertyStreamIO*>(this)->BSShaderProperty_SaveBinary(a1);
    SaveBin(*a1->m_pkOstr, m_iUnk8C);
    a1->SaveCString(m_kName.pString);
}
class TexturePool_bb7d
{
  public:
    void MemoryManager_Deallocate(void* pvHandle);
};
extern TexturePool_bb7d DAT_011f6238;

template <> inline BSStringT<char>::~BSStringT()
{
    if (pString)
        DAT_011f6238.MemoryManager_Deallocate(pString);
    pString = 0;
    sMaxLen = 0;
    sLen = 0;
}

// Releases the tile texture before the member and base destructors run.
// @fnv 0x00bb7d70
TileShaderProperty::~TileShaderProperty()
{
    m_spTexture = 0;
}
