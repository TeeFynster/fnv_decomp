#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiFloatInterpolator.h"
#include "../../../../include/NiMorphData.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"

// Flag variant: 0x00a41a40 matches /MT /O2 /GS /Gy without /EHsc.
extern MemoryManager _g_memoryManager;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                              unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesRead;
    return uiBytesRead;
}

template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiStream& kStream, T& kValue)
{
    NiBinaryStreamLoad(*kStream.m_pkIstr, &kValue, 1);
}
inline void ReadBinaryValue(NiStream& kStream, bool& bValue)
{
    unsigned char ucValue;
    ReadBinaryValue(kStream, ucValue);
    bValue = (ucValue == 1);
}
template <class T> inline T ReadValue(NiStream& kStream)
{
    T value;
    ReadBinaryValue(kStream, value);
    return value;
}

inline void NiInterpolator::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiInterpolator::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}
inline void NiMorphData::MorphTarget::SetTargetInterpolator(NiInterpolator* pkInterp)
{
    m_spTargetInterpolator = pkInterp;
}
inline NiFixedString& NiFixedString::operator=(const NiFixedString& kString)
{
    if (m_kHandle != kString.m_kHandle)
    {
        char* kHandle = kString.m_kHandle;
        NiGlobalStringTable::IncRefCount(kHandle);
        NiGlobalStringTable::DecRefCount(m_kHandle);
        m_kHandle = kHandle;
    }
    return *this;
}
inline void SetMorphTargetName(NiMorphData::MorphTarget* target, const NiFixedString& name)
{
    target->m_kName = name;
}
inline void ReplaceTargetVerts(NiMorphData::MorphTarget* target, NiPoint3* vertices)
{
    _g_memoryManager.Deallocate(target->m_pkVertexPositions);
    target->m_pkVertexPositions = vertices;
}
inline void* __cdecl operator new[](size_t size)
{
    return _g_memoryManager.Allocate(size);
}

// The shared MorphTarget lacks LoadBinary; preserve its original thiscall entry point.
void __fastcall LoadMorphTarget(NiMorphData::MorphTarget*, int, NiStream&, unsigned int);
typedef void (__thiscall* LoadMorphTargetFn)(NiMorphData::MorphTarget*, NiStream&, unsigned int);
inline void* NiMemObject::operator new[](size_t size)
{
    return _g_memoryManager.Allocate(size);
}

typedef void*(__cdecl* KeyCreateFn)(NiStream& kStream, unsigned int uiNumKeys);
typedef void(__cdecl* KeyFillFn)(void* pkKeys, unsigned int uiNumKeys, unsigned char ucSize);
extern unsigned char DAT_011f3758[];
extern KeyCreateFn DAT_011f3db0[];
extern KeyFillFn DAT_011f3780[];
int __cdecl FUN_00a305b0(char*, unsigned int, const char*, ...);
struct MorphKeyHelpers
{
    static unsigned char GetKeySize(unsigned int type) { return DAT_011f3758[type]; }
    static KeyCreateFn GetCreate(unsigned int type) { return DAT_011f3db0[type]; }
    static KeyFillFn GetFill(unsigned int type) { return DAT_011f3780[type]; }
};

// @fnv 0x00a41a40
void __fastcall LoadMorphData(NiMorphData* self, int, NiStream& kStream)
{
    self->NiObject::LoadBinary(kStream);
    ReadBinaryValue(kStream, self->m_uiNumTargets);
    ReadBinaryValue(kStream, self->m_uiNumVertsPerTarget);
    ReadBinaryValue(kStream, self->m_bTargetsAreRelative);
    self->m_pMorphTargets = new NiMorphData::MorphTarget[self->m_uiNumTargets];
    for (unsigned int i = 0; i < self->m_uiNumTargets; i++)
    {
        if (kStream.m_uiNifFileVersion < 0x0a010068)
        {
            unsigned int uiNumKeys;
            ReadBinaryValue(kStream, uiNumKeys);
            const unsigned int eType = ReadValue<unsigned int>(kStream);
            if (uiNumKeys > 0)
            {
                unsigned char ucSize = MorphKeyHelpers::GetKeySize(eType);
                void* pkKeys = MorphKeyHelpers::GetCreate(eType)(kStream, uiNumKeys);
                MorphKeyHelpers::GetFill(eType)(pkKeys, uiNumKeys, ucSize);
                NiFloatInterpolator* pkInterp = new NiFloatInterpolator(0);
                pkInterp->SetKeyData(pkKeys, uiNumKeys, eType);
                self->m_pMorphTargets[i].SetTargetInterpolator(pkInterp);
                pkInterp->Collapse();
            }
            char acName[256];
            FUN_00a305b0(acName, 256, "MT %d", i);
            SetMorphTargetName(&self->m_pMorphTargets[i], static_cast<const char*>(acName));
            NiPoint3* pkVerts = new NiPoint3[self->m_uiNumVertsPerTarget];
            for (unsigned int j = 0; j < self->m_uiNumVertsPerTarget; ++j)
                pkVerts[j].LoadBinary(kStream);
            ReplaceTargetVerts(&self->m_pMorphTargets[i], pkVerts);
        }
        else
        {
            ((LoadMorphTargetFn)LoadMorphTarget)(&self->m_pMorphTargets[i], kStream, self->m_uiNumVertsPerTarget);
        }
    }
}

