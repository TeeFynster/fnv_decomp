
// src/gamebryo2.2/corelibs/nianimation/nimorphdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nimorphdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiMorphData.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"

// Missing member declarations use explicit-this adapters. The unused EDX
// argument preserves the original thiscall stack arguments.
void* __fastcall DestroyMorphTarget(NiMorphData::MorphTarget*, int, unsigned char);
void __fastcall ReleaseMorphTarget(NiMorphData::MorphTarget*);
typedef void* (__thiscall* DestroyMorphTargetFn)(NiMorphData::MorphTarget*, unsigned char);
typedef void (__thiscall* ReleaseMorphTargetFn)(NiMorphData::MorphTarget*);

extern "C" void* g_011f3e74;

// Returns the address of the global g_011f3e74.
// @fnv 0x00a415e0
// src: COMMUNITY 0x00a415e0
void* __cdecl NiMorphData_GetRTTI()
{
    return &g_011f3e74;
}

extern int DAT_010976fc;
void __cdecl _delete(void*, unsigned int);
// @fnv 0x00a41a00
void* __fastcall DestroyMorphData(NiMorphData* self, int, unsigned int auiFlags)
{
    void* p = self->m_pMorphTargets;
    *(void**)self = (void*)&DAT_010976fc;
    if (p)
        ((DestroyMorphTargetFn)DestroyMorphTarget)((NiMorphData::MorphTarget*)p, 3);
    ((NiRefObject*)self)->NiRefObject::~NiRefObject();
    if (auiFlags & 1)
        _delete(self, 0x18);
    return self;
}

// @fnv 0x00a41710
bool __fastcall RegisterMorphStreamables(NiMorphData* self, int, NiStream& kStream)
{
    if (!self->NiObject::RegisterStreamables(kStream))
        return false;
    unsigned int ui;
    NiMorphData::MorphTarget* pkTarget;
    for (ui = 0; ui < self->m_uiNumTargets; ui++)
    {
        pkTarget = (ui < self->m_uiNumTargets ? &self->m_pMorphTargets[ui] : 0);
        kStream.RegisterFixedString(pkTarget->m_kName);
    }
    return true;
}

// @fnv 0x00a57850
void __fastcall RegisterMorphTargetName(NiMorphData::MorphTarget* self, int, NiStream& kStream)
{
    kStream.RegisterFixedString(self->m_kName);
}

extern int DAT_0109b220;
// @fnv 0x00a415f0
NiMorphData::MorphTarget* __fastcall InitializeMorphTarget(NiMorphData::MorphTarget* self)
{
    self->m_pkVertexPositions = 0;
    *(int*)&self->m_kName = DAT_0109b220;
    *(volatile float*)&self->m_fMorphWeight = 0.0f;
    self->m_spTargetInterpolator.m_pObject = 0;
    return self;
}

extern MemoryManager DAT_011f6238;
extern void* DAT_00fdf1c4;

typedef int(__stdcall* ReleaseFn_b9415)(int p);

// @fnv 0x00a41610
void __fastcall ReleaseMorphTarget(NiMorphData::MorphTarget* self)
{
    DAT_011f6238.Deallocate(self->m_pkVertexPositions);
    ReleaseFn_b9415 pfnRelease = (ReleaseFn_b9415)DAT_00fdf1c4;
    NiRefObject* pRefItem = (NiRefObject*)self->m_spTargetInterpolator.m_pObject;
    if (pRefItem != 0)
    {
        if (pfnRelease((int)&pRefItem->m_uiRefCount) == 0)
            pRefItem->DeleteThis();
    }
    if ((int)self->m_kName.m_kHandle != DAT_0109b220)
        pfnRelease((int)self->m_kName.m_kHandle - 8);
}

namespace fnv_00a41660 {
extern char* DAT_0109b220;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
}  // namespace fnv_00a41660

// @fnv 0x00a41660
void* __fastcall DestroyMorphTarget(NiMorphData::MorphTarget* self, int, unsigned char flags)
{
    if (flags & 2)
    {
        int count = *(int*)((char*)self - 4);
        NiMorphData::MorphTarget* pEntry = self + count;
        while (--count >= 0)
        {
            --pEntry;
            DAT_011f6238.Deallocate(pEntry->m_pkVertexPositions);
            NiRefObject* ref = (NiRefObject*)pEntry->m_spTargetInterpolator.m_pObject;
            if (ref)
            {
                if (fnv_00a41660::InterlockedDecrement((volatile long*)&ref->m_uiRefCount) == 0)
                    ref->DeleteThis();
            }
            char* pName = pEntry->m_kName.m_kHandle;
            if (pName != fnv_00a41660::DAT_0109b220)
                fnv_00a41660::InterlockedDecrement((long volatile*)(pName - 8));
        }
        void* header = (char*)self - 4;
        if (flags & 1)
            DAT_011f6238.Deallocate(header);
        return header;
    }
    ((ReleaseMorphTargetFn)ReleaseMorphTarget)(self);
    if (flags & 1)
        DAT_011f6238.Deallocate(self);
    return self;
}


// NiBinaryStream keeps its transfer callbacks opaque in the shared declaration.
inline unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
                                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytes = (*(WriteFunction*)((char*)this + 12))(
        this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *(unsigned int*)((char*)this + 4) += uiBytes;
    return uiBytes;
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                              unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytes = (*(ReadFunction*)((char*)this + 8))(
        this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *(unsigned int*)((char*)this + 4) += uiBytes;
    return uiBytes;
}

static __forceinline unsigned int countBytes(const volatile unsigned int& count)
{
    return count * 4;
}
// @fnv 0x00a417b0
// src: XBOX_PDB 0x00a417b0
void __cdecl NiPoint3_SaveBinary(void* owner, void* source, unsigned int elementCount)
{
    NiBinaryStream* __restrict buffer = *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(owner) + 0x250);
    unsigned int stride = 4;
    buffer->BinaryWrite(source, countBytes(elementCount), &stride, 1);
}

// @fnv 0x00a417f0
bool __fastcall EqualMorphTargets(NiMorphData::MorphTarget* self, int, NiMorphData::MorphTarget* other, unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i)
    {
        NiPoint3 b = other->m_pkVertexPositions[i];
        NiPoint3 a = self->m_pkVertexPositions[i];
        if (!(a.x == b.x))
            return false;
        if (!(a.y == b.y))
            return false;
        if (!(a.z == b.z))
            return false;
    }
    if (self->m_kName.m_kHandle != other->m_kName.m_kHandle)
        return false;
    return true;
}

// NiMorphData::SaveBinary: base data, target/vertex counts, relative flag, then each morph
// target's name and vertex array. WriteBinaryArray multiplies by the uiSize variable (Gamebryo form).
template <class T> inline unsigned int WriteBinaryArray(NiBinaryStream& kStream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

inline unsigned int NiStream::version()
{
    return *(unsigned int*)((char*)this + 0xD8);
}

inline NiBinaryStream& NiStream::Istr()
{
    return **(NiBinaryStream**)((char*)this + 0x24C);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *(NiBinaryStream**)((char*)this + 0x250);
}

// The shared stream lacks the fixed-string save overload. Preserve its thiscall ABI.
void __fastcall SaveMorphTargetString(NiStream*, int, const NiFixedString&);
typedef void (__thiscall* SaveMorphTargetStringFn)(NiStream*, const NiFixedString&);

inline void SerializeValue(NiStream& kStream, const unsigned int& uiValue)
{
    WriteBinaryArray(*kStream.GetBinaryStream(), &uiValue, 1);
}

inline void SerializeValue(NiStream& kStream, const char& cValue)
{
    WriteBinaryArray(*kStream.GetBinaryStream(), &cValue, 1);
}

inline void SerializeValue(NiStream& kStream, const float* pfValues, unsigned int uiNumEls)
{
    WriteBinaryArray(*kStream.GetBinaryStream(), pfValues, uiNumEls);
}

inline void SerializeValue(NiStream& kStream, const NiPoint3* pkValues, unsigned int uiNumEls)
{
    SerializeValue(kStream, (const float*)pkValues, uiNumEls * 3);
}

inline void SaveMorphTarget(NiMorphData::MorphTarget* self, NiStream& kStream, unsigned int m_uiScaleCount)
{
    ((SaveMorphTargetStringFn)SaveMorphTargetString)(&kStream, self->m_kName);
    if (m_uiScaleCount)
        SerializeValue(kStream, self->m_pkVertexPositions, m_uiScaleCount);
}

// Preserve this unit's original base-save entry point and thiscall ABI.
void __fastcall SaveMorphDataBase(NiObject*, int, NiStream&);
typedef void (__thiscall* SaveMorphDataBaseFn)(NiObject*, NiStream&);

// @fnv 0x00a41d90
void __fastcall SaveMorphData(NiMorphData* self, int, NiStream& kStream)
{
    ((SaveMorphDataBaseFn)SaveMorphDataBase)(self, kStream);
    SerializeValue(kStream, self->m_uiNumTargets);
    SerializeValue(kStream, self->m_uiNumVertsPerTarget);
    char cRelative = self->m_bTargetsAreRelative;
    SerializeValue(kStream, cRelative);
    for (unsigned int i = 0; i < self->m_uiNumTargets; i++)
        SaveMorphTarget(&self->m_pMorphTargets[i], kStream, self->m_uiNumVertsPerTarget);
}

struct ViewerStrings
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& element);
    inline unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    __forceinline unsigned int AddInl(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAtInl(uiIndex, element);
        return uiIndex;
    }
    __forceinline void SetAtInl(unsigned int uiIndex, char* const& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else if (element != 0)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != 0)
                m_usESize--;
        }
        m_pBase[uiIndex] = element;
    }
};

extern "C" void* g_011f3e74;

char* NiViewerStrings_NiGetViewerString_Title(const char* pcName);
char* NiGetViewerString_00a7d510(const char* pcPrefix, unsigned int uiValue);
char* NiGetViewerString_00a7d5e0(const char* pcPrefix, const char* pcValue);

void __stdcall AppendCameraPathEntries(ViewerStrings* pkStrings);

inline NiMorphData::MorphTarget* NiMorphData::GetTarget(unsigned int i) const
{
    return i < m_uiNumTargets ? &m_pMorphTargets[i] : 0;
}

inline const char* MorphTargetName(const NiMorphData::MorphTarget* target)
{
    return target->m_kName.m_kHandle;
}

// Appends the base object's strings, the target and vertex counts, a MorphTargets header, and each target's name to pkStrings.
// @fnv 0x00a41ea0
void __fastcall AppendMorphViewerStrings(NiMorphData* self, int, ViewerStrings* pkStrings)
{
    AppendCameraPathEntries(pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title((const char*)g_011f3e74));
    pkStrings->Add(NiGetViewerString_00a7d510("m_uiNumTargets", self->m_uiNumTargets));
    pkStrings->Add(NiGetViewerString_00a7d510("m_uiNumVertsPerTarget", self->m_uiNumVertsPerTarget));
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title("MorphTargets"));
    for (unsigned int i = 0; i < self->m_uiNumTargets; i++)
        pkStrings->AddInl(NiGetViewerString_00a7d5e0("m_pcName", MorphTargetName(self->GetTarget(i))));
}

template <class T> inline unsigned int FNVReadElements(NiBinaryStream& stream, const T* data, unsigned int count)
{
    unsigned int elementSize = sizeof(T);
    return stream.BinaryRead((void*)data, count * elementSize, &elementSize, 1);
}
// Reads count unsigned int elements from the input stream via FNVReadElements.
// @fnv 0x00a41770
void __cdecl ReadElements(NiStream* apStreamContext, const unsigned int* data, unsigned int count)
{
    NiBinaryStream* stream = &apStreamContext->Istr();
    FNVReadElements(*stream, data, count);
}

extern MemoryManager g_memoryManager;
template <class T> inline void NiBinIstrLoad_a41940(NiBinaryStream* pkStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    pkStream->BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
inline void* __cdecl operator new[](size_t uiSize)
{
    return g_memoryManager.Allocate(uiSize);
}

// Reads the name and optional morph weight, then allocates and fills the vertex positions.
// @fnv 0x00a41940
void __fastcall LoadMorphTarget(NiMorphData::MorphTarget* self, int, NiStream& kStream, unsigned int m_uiScaleCount)
{
    if (kStream.version() < 0x14010001)
        kStream.ReadFixedString(self->m_kName);
    else
        kStream.ReadStringTableEntry(self->m_kName);
    if (kStream.version() >= 0x0A010068 && kStream.version() < 0x14010003)
        NiBinIstrLoad_a41940(&kStream.Istr(), &self->m_fMorphWeight, 1);
    self->m_pkVertexPositions = new NiPoint3[m_uiScaleCount];
    NiBinIstrLoad_a41940(&kStream.Istr(), (float*)self->m_pkVertexPositions, m_uiScaleCount * 3);
}

typedef bool (__thiscall* EqualMorphTargetsFn)(NiMorphData::MorphTarget*, NiMorphData::MorphTarget*, unsigned int);

// Compares counts, relative flags, and each morph target after the base comparison.
// @fnv 0x00a418a0
bool __fastcall EqualMorphData(NiMorphData* self, int, NiMorphData* other)
{
    if (!self->NiObject::IsSameAs(other))
    {
        return false;
    }
    int otherCount = other->m_uiNumTargets;
    NiMorphData* pOther = other;
    unsigned int thisCount = self->m_uiNumTargets;
    if (thisCount != otherCount)
    {
        return false;
    }
    if (self->m_uiNumVertsPerTarget != other->m_uiNumVertsPerTarget)
    {
        return false;
    }
    if (self->m_bTargetsAreRelative == other->m_bTargetsAreRelative)
    {
        for (unsigned int i = 0; i < thisCount; ++i)
        {
            NiMorphData::MorphTarget* pOtherTarget = (i < otherCount) ? (pOther->m_pMorphTargets + i) : 0;
            NiMorphData::MorphTarget* pThisTarget = (i < thisCount) ? (self->m_pMorphTargets + i) : 0;
            if (!((EqualMorphTargetsFn)EqualMorphTargets)(pThisTarget, pOtherTarget, self->m_uiNumVertsPerTarget))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
