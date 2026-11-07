
// src/bsshader/imagespaceeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiAccumulator.h"
#include "../../include/MemoryManager.h"

struct ImageSpaceEffectParam;
class ImageSpaceTexture;

// These three allocation callers pass a writable reference to the array entry.
// Using NiTArray::SetAt(unsigned int, const T&) reuses an argument stack slot,
// removing the original push/pop ecx in 0x00ba3b50 (68 vs 70 bytes),
// 0x00ba3ba0 (82 vs 84), and 0x00ba3c00 (96 vs 98). Retain only this
// mutable-reference call interface until the shared template supports it.
// These members are used only at their recorded offsets, never sized or constructed.
template <class T> struct ImageSpaceMutableArraySlot
{
    void SetAt(unsigned int uiIndex, T& element);
};

// Retained locally: include/ImageSpaceEffect.h is not available.
// Both the parent pass list and its child texture list belong to this same 0x58-byte class.
struct ImageSpaceEffect
{
    virtual ~ImageSpaceEffect();
    virtual void Render(int, int, int, int);
    virtual void Setup(int, int);
    virtual void Shutdown();
    virtual void BorrowTextures(int);
    virtual void ReturnTextures();
    virtual bool IsActive() const;
    virtual bool UpdateParams(int);
    bool bIsActive;
    bool bParamsChanged;
    NiTPrimitiveArray<ImageSpaceEffect*> pEffectList;
    NiTPrimitiveArray<ImageSpaceEffectParam*> pEffectParamList;
    NiTPrimitiveArray<ImageSpaceTexture*> pTextures;
    struct EffectInput
    {
        int iTexIndex;
        int iFilterMode;
    };
    NiTPrimitiveArray<EffectInput*> pEffectInputs;
    NiTPrimitiveArray<int> pEffectOutput;

    void SetEffectAt(int, ImageSpaceEffect*, ImageSpaceEffectParam*, int);
    void SetArrayEntry(int, int, int, int, int);
    void SetThreeInputs(unsigned int, int, int, int, int, int, int);
    void SetEntryRanges(unsigned int, int, int, int, int, int, int, int, int);
    void SetAccumulatorAt(unsigned int, NiAccumulator*, NiCamera const*);
    void ProcessItems(int, int, int, int);
    void SetTextureArraySize(int count);
    void SetEffectParams(unsigned int uiIndex);
};

// Stores the effect, its parameter and output index into the three arrays at the given effect index.
// @fnv 0x00ba3c70
void ImageSpaceEffect::SetEffectAt(int aiEffectIndex, ImageSpaceEffect* apEffect, ImageSpaceEffectParam* apParam,
                                     int aiOutput)
{
    pEffectList.SetAt(aiEffectIndex, apEffect);
    pEffectParamList.SetAt(aiEffectIndex, apParam);
    pEffectOutput.SetAt(aiEffectIndex, aiOutput);
}

extern MemoryManager g_memoryManager;
// Allocates a 16-byte block, stores the four arguments in it, and sets it at index a1 in the array at offset 0x38.
// @fnv 0x00ba3b50
void ImageSpaceEffect::SetArrayEntry(int uiIndex, int a2, int a3, int a4, int a5)
{
    int* p = (int*)g_memoryManager.Game_DoHeapAlloc(16);
    p[0] = a2;
    p[1] = a4;
    p[2] = a3;
    int t = (int)p;
    p[3] = a5;
    reinterpret_cast<ImageSpaceMutableArraySlot<int>*>(&pEffectInputs)->SetAt((unsigned int)uiIndex, t);
}

// Sets the child-effect, parameter, input and output array capacities to count.
// @fnv 0x00ba3f90
void ImageSpaceEffect::SetTextureArraySize(int count)
{
    reinterpret_cast<NiTPrimitiveArray<ImageSpaceTexture*>*>(&pEffectList)->SetSize(count);
    reinterpret_cast<NiTPrimitiveArray<ImageSpaceTexture*>*>(&pEffectParamList)->SetSize(count);
    reinterpret_cast<NiTPrimitiveArray<ImageSpaceTexture*>*>(&pEffectInputs)->SetSize(count);
    reinterpret_cast<NiTPrimitiveArray<ImageSpaceTexture*>*>(&pEffectOutput)->SetSize(count);
}

// @fnv 0x00ba3ba0
void ImageSpaceEffect::SetThreeInputs(unsigned int auiIndex, int aiValue0, int aiValue1, int aiValue2, int aiValue3, int aiValue4,
                          int aiValue5)
{
    int* p = (int*)g_memoryManager.Game_DoHeapAlloc(24);
    p[0] = aiValue0;
    p[1] = aiValue3;
    p[2] = aiValue1;
    p[3] = aiValue4;
    p[4] = aiValue2;
    unsigned int t = auiIndex;
    int iEntry = (int)p;
    p[5] = aiValue5;
    reinterpret_cast<ImageSpaceMutableArraySlot<int>*>(&pEffectInputs)->SetAt(t, iEntry);
}

// @fnv 0x00ba3cb0
void ImageSpaceEffect::SetAccumulatorAt(unsigned int auiIndex, NiAccumulator* apAccum, NiCamera const* apCamera)
{
    reinterpret_cast<NiTPrimitiveArray<int>*>(&pTextures)->SetAt(auiIndex, reinterpret_cast<int&>(apAccum));
    if (apAccum)
        apAccum->SetSortingCamera(apCamera);
}

struct TextureInputRange
{
    int m_iStart;
    int m_iEnd;
};

// Four 8-byte texture/filter pairs allocated by 0x00ba3c00, separate from the effect object.
struct TextureInputQuad
{
    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager.Game_DoHeapAlloc(uiSize);
    }

    TextureInputRange m_akRanges[4];
};

// Allocates a TextureInputQuad, fills its four ranges from the start/end arguments, and stores it in pEffectInputs at uiIndex.
// @fnv 0x00ba3c00
void ImageSpaceEffect::SetEntryRanges(unsigned int uiIndex, int iStart0, int iStart1, int iStart2, int iStart3, int iEnd0,
                                   int iEnd1, int iEnd2, int iEnd3)
{
    TextureInputQuad* pkEntry = new TextureInputQuad;
    pkEntry->m_akRanges[0].m_iStart = iStart0;
    pkEntry->m_akRanges[0].m_iEnd = iEnd0;
    pkEntry->m_akRanges[1].m_iStart = iStart1;
    pkEntry->m_akRanges[1].m_iEnd = iEnd1;
    pkEntry->m_akRanges[2].m_iStart = iStart2;
    pkEntry->m_akRanges[2].m_iEnd = iEnd2;
    pkEntry->m_akRanges[3].m_iStart = iStart3;
    TextureInputQuad* pkElement = pkEntry;
    pkEntry->m_akRanges[3].m_iEnd = iEnd3;
    reinterpret_cast<ImageSpaceMutableArraySlot<TextureInputQuad*>*>(&pEffectInputs)->SetAt(uiIndex, pkElement);
}

// @fnv 0x00ba3f20
void ImageSpaceEffect::ProcessItems(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    BorrowTextures(aiArg3);
    for (int i = 0; (unsigned int)i < pEffectList.m_usSize; i++)
    {
        SetEffectParams(i);
        UpdateParams(aiArg3);
        int iValue = *(volatile int*)&aiArg4;
        pEffectList.m_pBase[i]->Render(aiArg1, aiArg2, reinterpret_cast<int>(pEffectParamList.m_pBase[i]), iValue);
    }
    ReturnTextures();
}

// Gamebryo NiTArray.inl bodies the original inlines
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetAllocatedSize() const
{
    return m_usMaxSize;
}
template <class T, class TAlloc> inline T& NiTArray<T, TAlloc>::GetAt(unsigned int uiIndex)
{
    return m_pBase[uiIndex];
}


template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::SetAt(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element != T(0))
            m_usESize++;
    }
    else
    {
        if (element != T(0))
        {
            if (m_pBase[uiIndex] == T(0))
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != T(0))
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}


// Assigns the input and output textures of a child effect and sets their filter modes.
// ImageSpaceTexture::SetFilterMode is absent from its shared header; the existing
// NiAccumulator::SetSortingCamera binding uses the same folded +8 setter at 0x00d47a40.
// @fnv 0x00ba3e30
void ImageSpaceEffect::SetEffectParams(unsigned int uiEffectIndex)
{
    ImageSpaceEffect* pkEffect = pEffectList.GetAt(uiEffectIndex);
    int iCount = pkEffect->pTextures.GetAllocatedSize();
    EffectInput* pkInputs = pEffectInputs.GetAt(uiEffectIndex);
    int iOutputIndex = pEffectOutput.GetAt(uiEffectIndex);

    for (int i = 1; i < iCount; i++)
    {
        EffectInput* pkInput = &pkInputs[i - 1];
        int iParam = pkInput->iTexIndex;
        if (iParam >= 0)
        {
            int iValue = pkInput->iFilterMode;
            ImageSpaceTexture* pkParam = pTextures.GetAt(iParam);
            pkEffect->pTextures.SetAt(i, pkParam);
            if (pkParam)
                reinterpret_cast<NiAccumulator*>(pkParam)->SetSortingCamera(reinterpret_cast<const NiCamera*>(iValue));
        }
    }

    ImageSpaceTexture* pkOutput = pTextures.GetAt(iOutputIndex);
    pkEffect->pTextures.SetAt(0, pkOutput);
    if (pkOutput)
        reinterpret_cast<NiAccumulator*>(pkOutput)->SetSortingCamera(0);
}
