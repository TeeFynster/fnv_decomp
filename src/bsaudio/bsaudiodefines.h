// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/bsaudio/bsaudiodefines.h
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x00ae7f90  NiTPointerListBase<NiTPointerAllocator<unsigned int>,SoundMessageRecord*>::RemoveHead  (117 bytes)
//   0x00ae8770  BSAudioDefinition::BSAudioDefinition  (189 bytes)
//   0x00ae8830  BSAudioDefinition::~BSAudioDefinition  (129 bytes)
//   0x00ae88c0  BSAudioDefinition::operator=  (304 bytes)
//   0x00ae8a40  BSSoundInfo::BSSoundInfo  (173 bytes)
//   0x00ae8af0  BSSoundInfo::~BSSoundInfo  (74 bytes)
//
// (572 bytes) and BSSoundInfo (596 bytes); member names and offsets match
#ifndef FNV_BSAUDIODEFINES_H
#define FNV_BSAUDIODEFINES_H


#include "../../include/NiPoint3.h"
#include "bsaudiodefines_decls.h"
#include <string.h>

class SoundMessageRecord;

FNV_STATIC_ASSERT(sizeof(NiPoint3) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiPoint3, x) == 0x0);
FNV_STATIC_ASSERT(offsetof(NiPoint3, y) == 0x4);
FNV_STATIC_ASSERT(offsetof(NiPoint3, z) == 0x8);

#pragma pack(push, 4)
class BSAudioDefinition
{
  public:
    char* pName;                       // +0x0, 4 bytes
    char Name[260];                    // +0x4, 260 bytes
    char* pFileName;                   // +0x108, 4 bytes
    char FileName[260];                // +0x10C, 260 bytes
    float fFirstValue;                 // +0x210, 4 bytes
    float fSecondValue;                // +0x214, 4 bytes
    NiPoint3 Location;                 // +0x218, 12 bytes
    unsigned int uiSoundFlags;         // +0x224, 4 bytes
    float m_fMinimumDistance;          // +0x228, 4 bytes
    float m_fMaximumDistance;          // +0x22C, 4 bytes
    unsigned int m_uiSoundParameterA;  // +0x230, 4 bytes
    unsigned int m_uiSoundParameterB;  // +0x234, 4 bytes
    unsigned int m_uiSoundParameter6;  // +0x238, 4 bytes

// @fnv 0x00ae8770
    BSAudioDefinition()
    {
        Name[0] = 0;
        FileName[0] = 0;
        pName = Name;
        pFileName = FileName;
        fFirstValue = 0.0f;
        fSecondValue = 0.0f;
        Location = NiPoint3::ZERO;
        uiSoundFlags = 0;
        m_fMinimumDistance = 0.0f;
        m_fMaximumDistance = 0.0f;
        m_uiSoundParameterA = 0;
        m_uiSoundParameterB = 0;
        m_uiSoundParameter6 = 0;
    }

// @fnv 0x00ae8830
    ~BSAudioDefinition()
    {
        pName = 0;
        pFileName = 0;
        fFirstValue = 0.0f;
        fSecondValue = 0.0f;
        uiSoundFlags = 0;
        m_fMinimumDistance = 0.0f;
        m_fMaximumDistance = 0.0f;
        m_uiSoundParameterA = 0;
        m_uiSoundParameterB = 0;
        m_uiSoundParameter6 = 0;
    }

// @fnv 0x00ae88c0
    BSAudioDefinition& operator=(const BSAudioDefinition& aCopy)
    {
        Name[0] = 0;
        FileName[0] = 0;
        if (aCopy.pName)
        {
            char* pSrcName = aCopy.pName;
            char* pDstName = pName;
            strcpy(pDstName, pSrcName);
        }
        if (aCopy.pFileName)
        {
            char* pDstFile = aCopy.pFileName;
            char* pSrcFile = pFileName;
            strcpy(pSrcFile, pDstFile);
        }
        fFirstValue = aCopy.fFirstValue;
        fSecondValue = aCopy.fSecondValue;
        Location = aCopy.Location;
        uiSoundFlags = aCopy.uiSoundFlags;
        m_fMinimumDistance = aCopy.m_fMinimumDistance;
        m_fMaximumDistance = aCopy.m_fMaximumDistance;
        m_uiSoundParameterA = aCopy.m_uiSoundParameterA;
        m_uiSoundParameterB = aCopy.m_uiSoundParameterB;
        m_uiSoundParameter6 = aCopy.m_uiSoundParameter6;
        return *this;
    }
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSAudioDefinition) == 572);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, pName) == 0);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, Name) == 4);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, pFileName) == 264);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, FileName) == 268);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, fFirstValue) == 528);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, fSecondValue) == 532);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, Location) == 536);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, uiSoundFlags) == 548);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, m_fMinimumDistance) == 552);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, m_fMaximumDistance) == 556);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, m_uiSoundParameterA) == 560);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, m_uiSoundParameterB) == 564);
FNV_STATIC_ASSERT(offsetof(BSAudioDefinition, m_uiSoundParameter6) == 568);

#pragma pack(push, 4)
class BSSoundInfo
{
  public:
    unsigned int m_uiSoundID;                // +0x0, 4 bytes
    float m_fSoundVolume;            // +0x4, 4 bytes
    float m_fFadeDuration;           // +0x8, 4 bytes
    unsigned int m_uiValueAt0C;      // +0xC, 4 bytes
    unsigned int m_uiPlaybackFlags;  // +0x10, 4 bytes
    bool m_bValueAt14;               // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    BSAudioDefinition m_kAudioDefinition;  // +0x18, 572 bytes

// @fnv 0x00ae8a40
    BSSoundInfo(BSSoundInfo* aCopy)
    {
        m_uiSoundID = aCopy->m_uiSoundID;
        m_fSoundVolume = aCopy->m_fSoundVolume;
        m_fFadeDuration = aCopy->m_fFadeDuration;
        m_uiValueAt0C = aCopy->m_uiValueAt0C;
        m_uiPlaybackFlags = aCopy->m_uiPlaybackFlags;
        m_bValueAt14 = aCopy->m_bValueAt14;
        m_kAudioDefinition = aCopy->m_kAudioDefinition;
    }

// @fnv 0x00ae8af0
    ~BSSoundInfo()
    {
        m_uiSoundID = 0;
        m_fSoundVolume = 0.0f;
        m_fFadeDuration = 0.0f;
        m_uiValueAt0C = 0;
        m_uiPlaybackFlags = 0;
        m_bValueAt14 = false;
    }
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSSoundInfo) == 596);
FNV_STATIC_ASSERT(offsetof(BSSoundInfo, m_uiSoundID) == 0);
FNV_STATIC_ASSERT(offsetof(BSSoundInfo, m_fSoundVolume) == 4);
FNV_STATIC_ASSERT(offsetof(BSSoundInfo, m_fFadeDuration) == 8);
FNV_STATIC_ASSERT(offsetof(BSSoundInfo, m_uiValueAt0C) == 12);
FNV_STATIC_ASSERT(offsetof(BSSoundInfo, m_uiPlaybackFlags) == 16);
FNV_STATIC_ASSERT(offsetof(BSSoundInfo, m_bValueAt14) == 20);
FNV_STATIC_ASSERT(offsetof(BSSoundInfo, m_kAudioDefinition) == 24);

template <class Allocator, class T>
// @fnv 0x00ae7f90
T NiTPointerListBase<Allocator, T>::RemoveHead()
{
    NiTListItem<T>* pOldHead;
    int iPad1;
    int iPad2;
    int iPad3;
    T kElement;
    kElement = reinterpret_cast<T>(m_pkHead);
    m_pkHead = m_pkHead->m_pkNext;
    if (m_pkHead)
        m_pkHead->m_pkPrev = 0;
    else
        m_pkTail = 0;
    pOldHead = reinterpret_cast<NiTListItem<T>*>(reinterpret_cast<NiTListItem<T>*>(kElement)->m_element);
    reinterpret_cast<NiTListItem<T>*>(kElement)->m_element = 0;
    m_kItemCount.Deallocate(reinterpret_cast<NiTListItem<T>*>(kElement));
    m_kItemCount.m_uiCount--;
    return reinterpret_cast<T>(pOldHead);
}

// @fnv 0x00ae86d0
SoundMessageRecord::~SoundMessageRecord()
{
    if (pObject)
        NiObjectGarbage_Add(pObject);
}

#endif
