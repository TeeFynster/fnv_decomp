#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBlendInterpolator.h"
#include "../../../../include/NiBlendQuaternionInterpolator.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiColorA.h"

// src/gamebryo2.2/corelibs/nianimation/niblendquaternioninterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niblendquaternioninterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern float DAT_0109696c;

struct NiQuadWords
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

// These operations must inline here to preserve the original blend code.
inline NiQuaternion::NiQuaternion()
{}

inline NiQuaternion& NiQuaternion::operator=(const NiQuaternion& src)
{
    *(NiQuadWords*)this = *(const NiQuadWords*)&src;
    return *this;
}

inline void NiQuaternion::SetValues(float w, float x, float y, float z)
{
    m_fVectorX = w;
    m_fVectorY = x;
    m_fVectorZ = y;
    m_fScalarPart = z;
}

inline float NiQuaternion::Dot(const NiQuaternion& p, const NiQuaternion& q)
{
    return p.m_fVectorX * q.m_fVectorX + p.m_fVectorY * q.m_fVectorY +
           p.m_fVectorZ * q.m_fVectorZ + p.m_fScalarPart * q.m_fScalarPart;
}

class NiBlendInterpolator__InterpArrayItem
{
public:
    NiInterpolator* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    int m_cPriority;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
};

inline bool NiBlendInterpolator::GetUpdateTimeForItem(float& fTime, unsigned char uc)
{
    NiBlendInterpolator__InterpArrayItem& kItem = m_pInterpArray[uc];
    if (!kItem.m_spControllerInterpolator || kItem.m_fNormalizedWeight == 0.0f)
        return false;
    if (m_uiObjectFlags & 1)
        fTime = kItem.m_fLastEvaluationTime;
    return fTime != DAT_0109696c;
}

// The shared color header has no stream helper yet; retain its original thiscall ABI locally.
void LoadNiColorABinary();
typedef void (__thiscall *NiColorABinaryLoader)(NiColorA* color, NiStream& stream);

// @fnv 0x00a554c0
void NiBlendQuaternionInterpolator::LoadBinary(NiStream& kStream)
{
    NiBlendInterpolator::LoadBinary(kStream);
    reinterpret_cast<NiColorABinaryLoader>(&LoadNiColorABinary)(
        reinterpret_cast<NiColorA*>(&m_kQuaternionValue), kStream);
}

// @fnv 0x00a554e0
void NiBlendQuaternionInterpolator::SaveBinary(NiStream& kStream)
{
    NiBlendInterpolator::SaveBinary(kStream);
    ((NiQuaternion*)((char*)this + 0x30))->SaveBinary(&kStream);
}

extern int g_011f4064;

// @fnv 0x00a55500
// src: COMMUNITY 0x00a55500
int* __cdecl NiBlendQuaternionInterpolator_GetRTTI()
{
    return &g_011f4064;
}

void __fastcall NiBlendInterpolator_NiBlendInterpolator(void*);
extern int DAT_011f4208;
extern int DAT_011f420c;
extern int DAT_011f4210;
extern int DAT_011f4214;
extern int DAT_0109a3ac;

// @fnv 0x00a55470
// src: EXE 0x00a55470
void* __cdecl NiBlendQuaternionInterpolator_CreateObject()
{
    void* p = BSFadeNode::operator new(0x40);
    if (p)
    {
        NiBlendInterpolator_NiBlendInterpolator(p);
        *(int**)((char*)p + 0) = &DAT_0109a3ac;
        *(int*)((char*)p + 0x30) = DAT_011f4208;
        *(int*)((char*)p + 0x34) = DAT_011f420c;
        *(int*)((char*)p + 0x38) = DAT_011f4210;
        *(int*)((char*)p + 0x3c) = DAT_011f4214;
        return p;
    }
    return 0;
}

// Returns whether the given NiInterpolator supports quaternion values.
// @fnv 0x00a55450
// src: XBOX_PDB 0x00a55450
bool __stdcall NiBlendQuaternionInterpolator_InterpolatorIsCorrectType(NiInterpolator* pkInterpolator)
{
    return pkInterpolator->IsQuaternionValueSupported();
}

// @fnv 0x00a55510
void* NiBlendQuaternionInterpolator::CloneInterpolator(void* kCloning)
{
    void* pkObject = BSFadeNode::operator new(0x40);
    if (pkObject)
    {
        NiBlendInterpolator_NiBlendInterpolator(pkObject);
        *(int*)pkObject = (int)&DAT_0109a3ac;
        *(NiQuadWords*)((char*)pkObject + 0x30) = *(NiQuadWords*)&DAT_011f4208;
    }
    else
    {
        pkObject = 0;
    }
    NiBlendInterpolator::CopyMembers(pkObject, kCloning);
    *(NiQuadWords*)((char*)pkObject + 0x30) = *(NiQuadWords*)((char*)this + 0x30);
    return pkObject;
}

// @fnv 0x00a55920
bool NiBlendQuaternionInterpolator::Interpolate(float fTime, void* pkInterpTarget, NiQuaternion* kValue)
{
    bool bReturnValue = false;
    unsigned char ucCount = *(unsigned char*)((char*)this + 0xe);
    if (ucCount == 1)
    {
        bReturnValue = UpdateSingle(fTime, pkInterpTarget, (NiQuadWords*)kValue);
    }
    else if (ucCount > 0)
    {
        NormalizeWeights();
        bReturnValue = BlendValues(fTime, pkInterpTarget, *(NiQuaternion*)kValue);
    }
    *(float*)((char*)this + 8) = fTime;
    return bReturnValue;
}

char* __cdecl _FUN_00a7d330(int);

extern char str_01098800[];

// @fnv 0x00a55980
void NiBlendQuaternionInterpolator::AppendInterpolatorStrings(StrArr* pkStrings)
{
    NiBlendInterpolator::AppendInterpolatorStrings(pkStrings);

    char* pString = _FUN_00a7d330(g_011f4064);

    unsigned int uiIndex = pkStrings->m_usSize;
    unsigned int uiSize = pkStrings->m_usMaxSize;
    if (uiIndex >= uiSize)
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIndex);

    pkStrings->SetAt(uiIndex, pString);

    pString = reinterpret_cast<NiQuaternion*>(reinterpret_cast<unsigned char*>(this) + 0x30)
                  ->FormatToBuffer(str_01098800);

    uiIndex = pkStrings->m_usSize;
    uiSize = pkStrings->m_usMaxSize;
    if (uiIndex >= uiSize)
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIndex);

    pkStrings->SetAt(uiIndex, pString);
}

// Compare the blend base, then compare the cached quaternion at offset 0x30.
// @fnv 0x00a55590
unsigned char NiBlendQuaternionInterpolator::CheckWithOffset(void* pkParam)
{
    if (!Probe(pkParam))
    {
        return false;
    }
    return !(*(const NiQuaternion*)&m_kQuaternionValue != *(const NiQuaternion*)((char*)pkParam + 0x30));
}

extern float DAT_0109696c;
extern int DAT_011f4208;
extern int DAT_011f420c;
extern int DAT_011f4210;
extern int DAT_011f4214;

// @fnv 0x00a555c0
bool NiBlendQuaternionInterpolator::UpdateSingle(float t, void* p2, NiQuadWords* out)
{
    if ((m_uiObjectFlags & 1) != 0)
    {
        t = m_fSingleInterpolatorTime;
    }
    if (t == DAT_0109696c)
    {
        out->m_00 = DAT_011f4208;
        out->m_04 = DAT_011f420c;
        out->m_08 = DAT_011f4210;
        out->m_0c = DAT_011f4214;
        ((NiQuadWords*)&m_kQuaternionValue)->m_00 = out->m_00;
        ((NiQuadWords*)&m_kQuaternionValue)->m_04 = out->m_04;
        ((NiQuadWords*)&m_kQuaternionValue)->m_08 = out->m_08;
        ((NiQuadWords*)&m_kQuaternionValue)->m_0c = out->m_0c;
        return false;
    }
    NiInterpolator* tgt = m_pSingleInterpolator;
    NiQuadWords* pCachedQuad = (NiQuadWords*)&m_kQuaternionValue;
    if (tgt->UpdateQuaternion(t, (NiObjectNET*)p2, *(NiQuaternion*)pCachedQuad) == false)
    {
        out->m_00 = DAT_011f4208;
        out->m_04 = DAT_011f420c;
        out->m_08 = DAT_011f4210;
        *(volatile int*)&out->m_0c = DAT_011f4214;
        pCachedQuad->m_00 = *(volatile int*)&out->m_00;
        pCachedQuad->m_04 = out->m_04;
        pCachedQuad->m_08 = out->m_08;
        pCachedQuad->m_0c = out->m_0c;
        return false;
    }
    out->m_00 = pCachedQuad->m_00;
    out->m_04 = pCachedQuad->m_04;
    out->m_08 = pCachedQuad->m_08;
    out->m_0c = pCachedQuad->m_0c;
    return true;
}

// @fnv 0x00a556b0
bool NiBlendQuaternionInterpolator::BlendValues(float fTime, void* pkTarget, NiQuaternion& kValue)
{
    m_kQuaternionValue.SetValues(0.0f, 0.0f, 0.0f, 0.0f);
    bool bModified = false;
    float fTotalWeight = 0.0f;
    for (unsigned char uc = 0; uc < m_ucArraySize; uc++)
    {
        NiBlendInterpolator__InterpArrayItem& kItem = m_pInterpArray[uc];
        if (kItem.m_spControllerInterpolator && kItem.m_fNormalizedWeight > 0.0f)
        {
            float fUpdateTime = fTime;
            if (!GetUpdateTimeForItem(fUpdateTime, uc))
                continue;
            NiQuaternion kQuat;
            if (kItem.m_spControllerInterpolator->UpdateQuaternion(fUpdateTime, (NiObjectNET*)pkTarget, (NiQuaternion&)kQuat))
            {
                if (fTotalWeight > 0.0f)
                {
                    float fCos = NiQuaternion::Dot(m_kQuaternionValue, kQuat);
                    if (fCos < 0.0f)
                        kQuat = kQuat.Negate();
                }
                kQuat = kQuat.ScaleFourComponents(m_pInterpArray[uc].m_fNormalizedWeight);
                m_kQuaternionValue = m_kQuaternionValue.ScaleFourComponents(fTotalWeight);
                float fZ = m_kQuaternionValue.m_fScalarPart;
                float fY = m_kQuaternionValue.m_fVectorZ;
                float fX = m_kQuaternionValue.m_fVectorY;
                float fW = m_kQuaternionValue.m_fVectorX;
                m_kQuaternionValue.Sum4(kQuat, fW, fX, fY, fZ);
                m_kQuaternionValue.FUN_00a38560();
                bModified = true;
                fTotalWeight += m_pInterpArray[uc].m_fNormalizedWeight;
            }
        }
    }
    if (!bModified)
    {
        m_kQuaternionValue = *(NiQuaternion*)&DAT_011f4208;
        kValue = m_kQuaternionValue;
        return false;
    }
    kValue = m_kQuaternionValue;
    return true;
}
