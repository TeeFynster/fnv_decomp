#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBoolInterpController.h"
#include "../../../../include/NiBoolData.h"
#include "../../../../include/NiBoolInterpolator.h"
#include "../../../../include/NiBoolTimelineInterpolator.h"
#include "../../../../include/NiKeyBasedInterpolator.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nianimation/nibooltimelineinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nibooltimelineinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f4044;

// @fnv 0x00a52d70
// src: COMMUNITY 0x00a52d70
void* __cdecl NiBoolTimelineInterpolator_GetRTTI()
{
    return &g_011f4044;
}

extern int DAT_01099fb4;


// Allocates a 0x20-byte NiBoolInterpolator, initialises its vtable, clears the field at offset 0x18 and the byte at 0x1c, and returns it (or null).
// @fnv 0x00a52fe0
NiBoolInterpolator* __cdecl CreateBoolInterpolator()
{
    NiBoolInterpolator* p = static_cast<NiBoolInterpolator*>(BSFadeNode::operator new(0x20));
    if (p)
    {
        p->LinkObject(0);
        *reinterpret_cast<void**>(p) = reinterpret_cast<void*>(&DAT_01099fb4);
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x18) = 0;
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(p) + 0x1c) = 0;
        return p;
    }
    return 0;
}

inline NiBoolTimelineInterpolator::NiBoolTimelineInterpolator() throw() : NiBoolInterpolator(static_cast<void*>(0))
{
    m_uiLastIndex = 0;
    m_bBoolValue = false;
}


void __cdecl UpdateState_00a3ca30();
void __cdecl _delete(void*, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
// Decrements the reference count of m_ptr and calls DeleteThis when it reaches zero, then calls FUN_00a3ca30 and frees this if flag bit 0 is set.
// @fnv 0x00a52f30
void* NiBoolTimelineInterpolator::ReleaseRef(unsigned int auiFlags)
{
    NiBoolData* p = m_spBoolData.m_pObject;
    if (p)
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount)) == 0)
            p->DeleteThis();
    }
    typedef void (__thiscall* DestroyBase)(NiBoolInterpolator*);
    reinterpret_cast<DestroyBase>(&UpdateState_00a3ca30)(this);
    if (auiFlags & 1)
        _delete(this, 0x20);
    return this;
}

void __cdecl FUN_00a536d0();
char* __cdecl _FUN_00a7d330(const char*);
// Appends the string returned by _FUN_00a7d330(g_011f4044) to pkStrings, growing it via SetSize when full, after calling FUN_00a536d0.
// @fnv 0x00a53020
void NiBoolTimelineInterpolator::AppendString(StrArr* pkStrings)
{
    typedef void (__thiscall* AppendBaseStrings)(NiBoolInterpolator*, StrArr*);
    reinterpret_cast<AppendBaseStrings>(&FUN_00a536d0)(this, pkStrings);
    char* pszStr = _FUN_00a7d330((const char*)g_011f4044);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pszStr);
}

extern unsigned int DAT_0109a0b4;
extern unsigned char DAT_0109a914;
// Allocates a 0x18-byte NiKeyBasedInterpolator, constructs it, sets its vtable and fields, and returns the pointer or 0.
// @fnv 0x00a53500
void* CreateNiKeyBasedInterpolator()
{
    void* p = BSFadeNode::operator new(0x18);
    if (p)
    {
        static_cast<NiKeyBasedInterpolator*>(p)->NiKeyBasedInterpolator::NiKeyBasedInterpolator();
        *(unsigned int*)p = (unsigned int)&DAT_0109a0b4;
        *(unsigned char*)((char*)p + 0xc) = DAT_0109a914;
        *(unsigned int*)((char*)p + 0x10) = 0;
        *(unsigned int*)((char*)p + 0x14) = 0;
        return p;
    }
    return 0;
}

// Constructs the object, links it to the given NiBoolData stream, zeroes two fields and sets the vtable.
// @fnv 0x00a52f00
NiBoolTimelineInterpolator::NiBoolTimelineInterpolator(NiBoolData* pkBoolData)
    : NiBoolInterpolator(pkBoolData)
{
    m_uiLastIndex = 0;
    m_bBoolValue = 0;
    *(int**)this = &DAT_01099fb4;
}

struct BoolKey
{
    float time;
    unsigned char opposite;
};
unsigned char __cdecl InterpolateBooleanKey(float, BoolKey*, unsigned int, unsigned int, unsigned int&, unsigned char);
// Evaluates the boolean key timeline at time, updating index, cached and m_bBoolValue, and returns whether a value is available via out.
// @fnv 0x00a52d80
bool NiBoolTimelineInterpolator::EvaluateBoolAtTime(float time, void*, bool& out)
{
    unsigned char& cached = reinterpret_cast<unsigned char&>(NiBoolInterpolator::m_bBoolValue);
    if (m_fLastTime == time)
    {
        if (cached == DAT_0109a914)
        {
            out = false;
            return false;
        }
        out = cached != 0;
        return true;
    }
    if (m_spBoolData.m_pObject)
    {
        unsigned int type = m_spBoolData.m_pObject->m_eRequestType;
        unsigned char stride = m_spBoolData.m_pObject->m_ucKeyDataSize;
        BoolKey* keys = reinterpret_cast<BoolKey*>(m_spBoolData.m_pObject->m_pKeyArray);
        unsigned int count = m_spBoolData.m_pObject->m_uiNumKeys;
        if (count > 0)
        {
            m_uiLastIndex = m_uiLastKeyIndex;
            unsigned char opposite = InterpolateBooleanKey(time, keys, type, count, m_uiLastKeyIndex, stride);
            unsigned int current = m_uiLastKeyIndex;
            unsigned char result = opposite;
            unsigned char value;
            if (opposite == reinterpret_cast<unsigned char&>(m_bBoolValue))
            {
                value = !opposite;
                if (m_uiLastIndex != current && m_uiLastIndex + 1 > current)
                {
                    for (unsigned int uiIndex = m_uiLastIndex + 1; uiIndex < count; uiIndex++)
                    {
                        if (((BoolKey*)((char*)keys + stride * uiIndex))->opposite == value)
                        {
                            goto changed;
                        }
                    }
                    if (opposite != value)
                    {
                        for (unsigned int uiIndex2 = 0; uiIndex2 < current; uiIndex2++)
                        {
                            if (((BoolKey*)((char*)keys + stride * uiIndex2))->opposite == value)
                            {
                                goto changed;
                            }
                        }
                    }
                }
                else
                {
                    for (unsigned int uiIndex3 = m_uiLastIndex + 1; uiIndex3 < current && uiIndex3 < count; uiIndex3++)
                    {
                        if (((BoolKey*)((char*)keys + stride * uiIndex3))->opposite == value)
                        {
                            goto changed;
                        }
                    }
                }
            }
            goto ready;
        changed:
            result = value;
        ready:
            cached = result != 0;
            reinterpret_cast<unsigned char&>(m_bBoolValue) = opposite;
        }
    }
    if (cached == DAT_0109a914)
    {
        out = false;
        return false;
    }
    out = cached != 0;
    m_fLastTime = time;
    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plAddend);

inline void IncBoolDataRefCount(NiBoolData* data)
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&data->m_uiRefCount));
}

inline void DecBoolDataRefCount(NiBoolData* data)
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&data->m_uiRefCount)) == 0)
        data->DeleteThis();
}

inline NiPointer<NiBoolData>& NiPointer<NiBoolData>::operator=(const NiPointer& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject)
            DecBoolDataRefCount(m_pObject);
        m_pObject = other.m_pObject;
        if (m_pObject)
            IncBoolDataRefCount(m_pObject);
    }
    return *this;
}

// @fnv 0x00a53480
void NiBoolInterpolator::CopyMemberData(NiBoolInterpolator* pkDest, CloningProcess& kCloning)
{
    NiObject::CopyMemberData(pkDest, kCloning);
    pkDest->m_bBoolValue = m_bBoolValue;
    pkDest->m_spBoolData = m_spBoolData;
    pkDest->m_uiLastKeyIndex = m_uiLastKeyIndex;
}

void __cdecl j_j_j_nullsub_3();
// @fnv 0x00a514d0
// src: COMMUNITY 0x00a514d0
void __cdecl j_j_j_j_nullsub_3()
{
    j_j_j_nullsub_3();
}

void __cdecl SaveToStream();

// @fnv 0x00a52d00
// src: XBOX_PDB 0x00a52d00
void __cdecl NiBoolTimelineInterpolator_SaveBinary()
{
    SaveToStream();
}

extern void FUN_00a53600();

// @fnv 0x00a52ce0
// src: XBOX_PDB 0x00a52ce0
void NiBoolTimelineInterpolator_LoadBinary()
{
    FUN_00a53600();
}

extern void RegisterStreamables_00a3c5b0();

// @fnv 0x00a52cf0
// src: XBOX_PDB 0x00a52cf0
void NiBoolTimelineInterpolator_RegisterStreamables()
{
    RegisterStreamables_00a3c5b0();
}

bool __cdecl FUN_00a53220();
// @fnv 0x00a52d10
// src: XBOX_PDB 0x00a52d10
bool NiBoolTimelineInterpolator::IsEqual_00a52d10()
{
    typedef bool (__thiscall* IsEqualBase)(NiBoolInterpolator*);
    return reinterpret_cast<IsEqualBase>(&FUN_00a53220)(this);
}

// Allocates a timeline interpolator and copies its base state into the clone.
// @fnv 0x00a52f80
// src: XBOX_PDB 0x00a52f80
NiBoolTimelineInterpolator* NiBoolTimelineInterpolator::CreateClone_00a52f80(CloningProcess& cloning)
{
    NiBoolTimelineInterpolator* p = new NiBoolTimelineInterpolator;
    NiBoolInterpolator::CopyMemberData(p, cloning);
    return p;
}
