// gamebryo2.2/corelibs/nianimation/nirotkey.cpp: TimedRotationKey (5 functions)

#include "nirotkey_decls.h"

// The original interpolation temporaries leave their components uninitialized.
inline NiQuaternion::NiQuaternion() {}

#define KEY_TIME(keys, index, size)                                                                                    \
    (*reinterpret_cast<const float*>(reinterpret_cast<const char*>(keys) + (index) * (size)))
#define KEY_AT(keys, index, size)                                                                                      \
    reinterpret_cast<const TimedRotationKey*>(reinterpret_cast<const char*>(keys) + (index) * (size))

// @fnv 0x00a28740
NiQuaternion __cdecl TimedRotationKey::InterpolatePosition(float fTime, TimedRotationKey* pkKeys,
                                                           NiAnimationKey::KeyType eType, unsigned int uiNumKeys,
                                                           unsigned int& ruiLastIndex, unsigned char ucKeySize)
{
    NiQuaternion kEulerResult;
    NiQuaternion kResult;
    if (uiNumKeys == 1 || fTime == DAT_010241b0)
    {
        if (eType != NiAnimationKey::EULERKEY)
            return pkKeys[0].m_kRotationValue;
    }
    if (eType == NiAnimationKey::EULERKEY)
    {
        DAT_011f3cc0[eType](fTime, pkKeys, 0, &kEulerResult);
        return kEulerResult;
    }
    {
        unsigned int uiLowerIndex = ruiLastIndex;
        unsigned int uiLastKey = uiNumKeys - 1;
        float fLowerTime = KEY_TIME(pkKeys, uiLowerIndex, ucKeySize);
        if (fLowerTime > fTime)
        {
            uiLowerIndex = 0;
            fLowerTime = KEY_TIME(pkKeys, 0, ucKeySize);
        }

        unsigned int uiUpperIndex = uiLowerIndex + 1;
        float fNextTime = 0.0f;
        // Interpolation requires a key following the cached lower key.
        __assume(uiUpperIndex <= uiLastKey);
        while (uiUpperIndex <= uiLastKey)
        {
            fNextTime = KEY_TIME(pkKeys, uiUpperIndex, ucKeySize);
            if (fTime <= fNextTime)
                break;
            fLowerTime = fNextTime;
            ++uiLowerIndex;
            ++uiUpperIndex;
        }

        const TimedRotationKey* pkLower = KEY_AT(pkKeys, uiLowerIndex, ucKeySize);
        const TimedRotationKey* pkUpper = KEY_AT(pkKeys, uiUpperIndex, ucKeySize);
        float fInterpFactor = (fTime - fLowerTime) / (fNextTime - fLowerTime);
        DAT_011f3cc0[eType](fInterpFactor, pkLower, pkUpper, &kResult);
        ruiLastIndex = uiLowerIndex;
        return kResult;
    }
}

// 22-byte covered span: ctor thunk (11 B) + 5 B int3 padding + 6 B static-address accessor.
void UpdateState_00a3ca30();

// Compares the four floats of pThis with those of q and returns 1 only if all four are exactly equal.
// @fnv 0x00a92660
// src: GUESS 0x00a92660 (confidence: high)
int __fastcall Object_HasEqualFloatComponents(const float* pThis, int, const float* q)
{
    return pThis[0] == q[0] && pThis[1] == q[1] && pThis[2] == q[2] && pThis[3] == q[3];
}

void __cdecl FUN_00a57010();
extern void* _DAT_01097054;

struct FUN_00a3ca30_shell
{
    void* m;
    void UpdateState_00a3ca30();
};

// @fnv 0x00a3ca30
// src: GUESS 0x00a3ca30 (confidence: low)
void FUN_00a3ca30_shell::UpdateState_00a3ca30()
{
    m = &_DAT_01097054;
    FUN_00a57010();
}

extern void* _DAT_011f3740;

// @fnv 0x00a3ca40
// src: COMMUNITY 0x00a3ca40
void* __cdecl NiKeyBasedInterpolator_GetRTTI()
{
    return &_DAT_011f3740;
}

struct FUN_00a3e9a0_src
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};

class FUN_00a3e9a0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FUN_00a3e9a0_src* m_18;
    unsigned int unk1C;
    float* m_20;
    float m_24;

    float NiPathInterpolator_PathLength(unsigned int a, unsigned int b, float c);
    float GetAccumulatedValue();
};

void __cdecl _NiFree_00aa10f0(float* p);
void* __cdecl _NiMalloc_00aa1070(unsigned int n);

// If m_24 is negative, allocates a float array sized from m_18->m_08, fills running sums via FUN_00a3e680, stores the last value in m_24, and returns m_24.
// @fnv 0x00a3e9a0
float FUN_00a3e9a0_cls::GetAccumulatedValue()
{
    if (m_24 < 0.0f)
    {
        unsigned int count = m_18 ? m_18->m_08 : 0;
        unsigned int bytes = count * 4;
        _NiFree_00aa10f0(m_20);
        m_20 = (float*)_NiMalloc_00aa1070(bytes);
        m_20[0] = 0.0f;
        unsigned int uiIndex = 0;
        unsigned int last = count - 1;
        if (last != 0)
        {
            do
            {
                volatile float t = NiPathInterpolator_PathLength(uiIndex, uiIndex + 1, 1.0f);
                float* p = m_20;
                p[uiIndex + 1] = p[uiIndex] + t;
                uiIndex = uiIndex + 1;
            } while (uiIndex < last);
        }
        *(volatile float*)&m_24 = m_20[count - 1];
    }
    return m_24;
}
