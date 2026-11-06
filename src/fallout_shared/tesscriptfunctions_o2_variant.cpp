
// src/fallout_shared/tesscriptfunctions_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesscriptfunctions.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/BGSListForm.h"
#include "../../include/NiTexturingProperty.h"
#include "../../include/Script.h"
#include "../../include/TESFaction.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESQuest.h"
#include "../../include/OBJECT_ACTION.h"
class BGSMusicType;
class FalloutAudioMedia
{
  public:
    static void PlayMedia(BGSMusicType*);
    static void EndMediaUpdate();
    static void Update();
};
extern bool ExtractArgs(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*,
                        ScriptLocals*, ...);

__declspec(nothrow) void* _NiMalloc(unsigned int);
// Keep the array construction and nonthrowing map transfer inline in this unit.
template <class T, class A>
inline __declspec(nothrow) NiTArray<T, A>::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    m_usMaxSize = (unsigned short)uiMaxSize;
    m_usGrowBy = (unsigned short)uiGrowBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = (T*)_NiMalloc(sizeof(T) * m_usMaxSize);
    else
        m_pBase = 0;
}

template <class T>
inline NiTPrimitiveArray<T>::NiTPrimitiveArray(unsigned int uiMaxSize, unsigned int uiGrowBy) throw()
    : NiTArray<T, NiTMallocInterface<T> >(uiMaxSize, uiGrowBy)
{}

// the out-of-line NiTArray::SetAt does not unwind (NiMain has no C++ exceptions)
template <> __declspec(nothrow) void NiTArray<NiTexturingProperty::Map*, NiTMallocInterface<NiTexturingProperty::Map*> >::SetAt(
    unsigned int uiIndex, NiTexturingProperty::Map* const& element);
// @fnv 0x00a6aa40
NiTexturingProperty::NiTexturingProperty() : m_uiObjectFlags(0), m_kStringArray(9, 1), m_pShaderMaps(0)
{
    Map* pkMap;
    pkMap = 0;
    m_kStringArray.SetAt(0, pkMap);
    pkMap = 0;
    m_kStringArray.SetAt(1, pkMap);
    pkMap = 0;
    m_kStringArray.SetAt(2, pkMap);
    pkMap = 0;
    m_kStringArray.SetAt(3, pkMap);
    pkMap = 0;
    m_kStringArray.SetAt(4, pkMap);
    pkMap = 0;
    m_kStringArray.SetAt(5, pkMap);
    pkMap = 0;
    m_kStringArray.SetAt(6, pkMap);
    pkMap = 0;
    m_kStringArray.SetAt(7, pkMap);
    pkMap = 0;
    m_kStringArray.SetAt(8, pkMap);
    m_uiObjectFlags &= 0xf00f;
    bool bMulti = false;
    unsigned int uiSize = m_kStringArray.m_usSize;
    for (unsigned int i = 1; i < uiSize; i++)
    {
        if (m_kStringArray.m_pBase[i])
        {
            bMulti = true;
            break;
        }
    }
    if (bMulti)
        m_uiObjectFlags |= 1;
    else
        m_uiObjectFlags &= ~1;
    m_uiObjectFlags = (m_uiObjectFlags & ~0xA) | 4;
}
