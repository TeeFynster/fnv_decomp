#include "../../../../include/NiTArray.h"
// gamebryo2.2/corelibs/nianimation/niblendtransforminterpolator.cpp: NiBlendTransformInterpolator, BlendTransformInterpolator (9 functions)

#include "../../../../include/NiBlendTransformInterpolator.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiObjectNET.h"
class NiRTTI;

// @fnv 0x00a41110
bool NiBlendTransformInterpolator::Update(float fTime, NiObjectNET* pkObject, NiQuatTransform& kTransform)
{
    bool bSuccess = false;
    if (m_ucInterpCount == 1)
        bSuccess = UpdateAccumulatedTransform(fTime, pkObject, kTransform);
    else if (m_ucInterpCount > 0)
    {
        NormalizeWeights();
        bSuccess = UpdateSingleInterpolator(fTime, pkObject, kTransform);
    }
    m_fLastTime = fTime;
    return bSuccess;
}

struct FUN_00a40a40_shell : public NiBlendTransformInterpolator
{
    void* NiBlendTransformInterpolator_GetRTTI();
};

extern "C" const NiRTTI* g_011f3e64;

// @fnv 0x00a40a40
// src: COMMUNITY 0x00a40a40
void* FUN_00a40a40_shell::NiBlendTransformInterpolator_GetRTTI()
{
    return &g_011f3e64;
}

struct FUN_00a40a20_shell : public NiBlendTransformInterpolator
{
    bool NiBlendTransformInterpolator_IsEqual(NiObject*);
};

struct FUN_00a36fd0_tgt
{
    char NiBlendInterpolator_IsEqual(NiObject*);
};

// @fnv 0x00a40a20
// src: XBOX_PDB 0x00a40a20
bool FUN_00a40a20_shell::NiBlendTransformInterpolator_IsEqual(NiObject* pkObject)
{
    return ((FUN_00a36fd0_tgt*)this)->NiBlendInterpolator_IsEqual(pkObject);
}

class FUN_00a40980_base
{
  public:
    virtual ~FUN_00a40980_base();
    FUN_00a40980_base(int a, float b, int c);
    int m_i04;
};

class FUN_00a40980 : public FUN_00a40980_base
{
  public:
    FUN_00a40980(int a, float b, int c);
    virtual ~FUN_00a40980();
};

// Forwards the three constructor arguments to the base class constructor.
// @fnv 0x00a40980
FUN_00a40980::FUN_00a40980(int a, float b, int c) : FUN_00a40980_base(a, b, c)
{}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct NiBlendObject_b9169
{
    virtual void Update();
    char m04[0x2c];
    NiBlendObject_b9169() throw();
};

struct NiBlendObjectDerived_b9169 : NiBlendObject_b9169
{
    virtual void Update();
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

struct NiUpdateOwner_b9169
{
    void NiBlendInterpolator_CopyMembers(NiBlendObject_b9169* p, int a);
};

struct FUN_00a40a50_cls : NiUpdateOwner_b9169
{
    NiBlendObject_b9169* CreateBlendObject(int a1);
};

// @fnv 0x00a40a50
NiBlendObject_b9169* FUN_00a40a50_cls::CreateBlendObject(int aiValue)
{
    NiBlendObject_b9169* p = new NiBlendObjectDerived_b9169();
    NiBlendInterpolator_CopyMembers(p, aiValue);
    return p;
}

extern unsigned int DAT_011a8400;
extern unsigned int DAT_011a8404;
extern unsigned int DAT_011a8408;
extern unsigned int DAT_011f3704;
extern unsigned int DAT_011f3708;
extern unsigned int DAT_011f370c;
extern unsigned int DAT_011f3710;
extern float DAT_01096b8c;

void __stdcall NiBlendInterpolator_LoadBinary(void* a1);

class FUN_00a40ab0_obj
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int m_uiD8;
};

class QuatBlockArg
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    void Apply(FUN_00a40ab0_obj* apObj);
};

// @fnv 0x00a40ab0
// src: XBOX_PDB 0x00a40ab0
void __stdcall NiBlendTransformInterpolator_LoadBinary(FUN_00a40ab0_obj* a1)
{
    NiBlendInterpolator_LoadBinary(a1);
    if (a1->m_uiD8 < 0xa01006e)
    {
        QuatBlockArg b;
        *(volatile float*)&b.m_1C = DAT_01096b8c;
        b.m_00 = DAT_011a8400;
        b.m_04 = DAT_011a8404;
        b.m_08 = DAT_011a8408;
        b.m_0C = DAT_011f3704;
        b.m_10 = DAT_011f3708;
        b.m_14 = DAT_011f370c;
        b.m_18 = DAT_011f3710;
        b.Apply(a1);
    }
}

template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
        return SetAtGrow(m_usSize, element);
    }
typedef NiTArray<const char*, NiTMallocInterface<const char*> > AGViewerStrings;
extern "C" const char* DAT_011f3e64;
void __stdcall NiBlendInterpolator_GetViewerStrings(AGViewerStrings* pkStrings);
const char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcText);

// @fnv 0x00a41170
// src: XBOX_PDB 0x00a41170
void __stdcall NiBlendTransformInterpolator_GetViewerStrings(AGViewerStrings* pkStrings)
{
    NiBlendInterpolator_GetViewerStrings(pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(DAT_011f3e64));
}

void __cdecl NiBlendInterpolator_CopyMembers();

// @fnv 0x00a40aa0
// src: XBOX_PDB 0x00a40aa0
void __cdecl NiBlendTransformInterpolator_CreateCloneInPlace()
{
    NiBlendInterpolator_CopyMembers();
}

#include <math.h>
inline void RoundedProduct(float& out, float a, float b)
{
    out = a * b;
}
inline double AddComponents(double left, double right)
{
    return left + right;
}
struct BlendPoint
{
    float x, y, z;
    BlendPoint& operator+=(const BlendPoint& p)
    {
        const float& sourceX = p.x;
        float& targetX = x;
        targetX = (float)AddComponents(sourceX, targetX);
        y += p.y;
        z += p.z;
        return *this;
    }
    BlendPoint& operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
};
inline BlendPoint operator*(float f, const BlendPoint& p)
{
    BlendPoint r;
    r.x = f * p.x;
    r.y = f * p.y;
    r.z = f * p.z;
    return r;
}
// local form of NiQuaternion: 0x00a40c10 needs POD construction and inline component assignment; the shared ctor/operator= split changes bytes.
struct BlendQuaternion
{
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
    BlendQuaternion Negate() const;
    BlendQuaternion& operator*=(double f)
    {
        m_fVectorX *= f;
        m_fVectorY *= f;
        m_fVectorZ *= f;
        m_fScalarPart *= f;
        return *this;
    }
    BlendQuaternion operator+=(const BlendQuaternion& p)
    {
        m_fVectorX += p.m_fVectorX;
        m_fVectorY = static_cast<const volatile BlendQuaternion&>(*this).m_fVectorY + p.m_fVectorY;
        m_fVectorZ = static_cast<const volatile BlendQuaternion&>(*this).m_fVectorZ + p.m_fVectorZ;
        m_fScalarPart += p.m_fScalarPart;
        return *this;
    }
    void ScaleXYZ(double f)
    {
        m_fVectorY *= f;
        m_fVectorZ *= f;
        m_fScalarPart *= f;
    }
    float HemisphereDot(const BlendQuaternion& p) const
    {
        double d = m_fVectorY * p.m_fVectorY;
        d += m_fVectorX * p.m_fVectorX;
        d += m_fVectorZ * p.m_fVectorZ;
        d += m_fScalarPart * p.m_fScalarPart;
        return (float)d;
    }
    float Dot(const BlendQuaternion& p) const
    {
        return m_fVectorX * p.m_fVectorX + m_fVectorY * p.m_fVectorY + m_fVectorZ * p.m_fVectorZ +
               m_fScalarPart * p.m_fScalarPart;
    }
};
extern BlendPoint DAT_011f426c;
extern BlendQuaternion DAT_011f49ec;
extern float DAT_01096b8c;
extern float DAT_0109696c;
extern const float DAT_01015f5c;
struct NiBlendInterpolator__InterpArrayItem
{
    NiInterpolator* interpolator;
    float weight;
    float normalizedWeight;
    unsigned char priority;
    float easeSpinner;
    float updateTime;
};
struct BlendTransform
{
    BlendPoint m_kTranslate;
    BlendQuaternion m_kRotate;
    float m_fScale;
    BlendTransform()
    {
        m_kTranslate = *(BlendPoint*)&DAT_011a8400;
        m_kRotate = *(BlendQuaternion*)&DAT_011f3704;
        m_fScale = DAT_01096b8c;
    }
};
struct BlendTransformInterpolator : NiBlendTransformInterpolator
{
    bool GetTime(NiBlendInterpolator__InterpArrayItem& item, float& time)
    {
        if (item.normalizedWeight == 0.0f)
            return false;
        if (m_uiObjectFlags & 1)
            time = item.updateTime;
        return time != DAT_0109696c;
    }
    bool NiBlendTransformInterpolator_BlendValues(float time, NiObjectNET* object, BlendTransform& output);
};
// Blends available interpolator components into output, normalizing translation and scale by their weights and rotation by its length.
// @fnv 0x00a40c10
// src: XBOX_PDB 0x00a40c10
bool BlendTransformInterpolator::NiBlendTransformInterpolator_BlendValues(float time, NiObjectNET* object, BlendTransform& output)
{
    float translationWeight = 1.0f;
    float scaleWeight = 1.0f;
    BlendPoint translation = DAT_011f426c;
    BlendQuaternion rotation = DAT_011f49ec;
    float scale = 0.0f;
    bool hasTranslation = false;
    bool hasRotation = false;
    bool hasScale = false;
    bool firstRotation = true;
    for (unsigned char iIndex = 0; iIndex < m_ucArraySize; ++iIndex)
    {
        NiBlendInterpolator__InterpArrayItem& item = m_pInterpArray[iIndex];
        if (item.interpolator && item.normalizedWeight > 0.0f)
        {
            float updateTime = time;
            if (!GetTime(item, updateTime))
            {
                translationWeight -= item.normalizedWeight;
                scaleWeight -= item.normalizedWeight;
                continue;
            }
            BlendTransform value;
            if (item.interpolator->UpdateTransform(updateTime, object, *reinterpret_cast<NiQuatTransform*>(&value)))
            {
                if (value.m_kTranslate.x != -3.4028234663852886e+38)
                {
                    hasTranslation = true;
                    translation += item.normalizedWeight * value.m_kTranslate;
                }
                else
                    translationWeight -= item.normalizedWeight;
                if (value.m_kRotate.m_fVectorY != -3.4028234663852886e+38)
                {
                    BlendQuaternion current;
                    current = value.m_kRotate;
                    if (!firstRotation)
                    {
                        if (rotation.HemisphereDot(current) < 0.0f)
                            current = current.Negate();
                    }
                    else
                        firstRotation = false;
                    hasRotation = true;
                    float w = item.normalizedWeight;
                    current.m_fVectorX *= w;
                    current.m_fVectorY *= w;
                    current.m_fVectorZ *= w;
                    rotation.m_fVectorX =
                        static_cast<const volatile BlendQuaternion&>(current).m_fVectorX + rotation.m_fVectorX;
                    rotation.m_fVectorY =
                        static_cast<const volatile BlendQuaternion&>(rotation).m_fVectorY + current.m_fVectorY;
                    rotation.m_fVectorZ =
                        static_cast<const volatile BlendQuaternion&>(rotation).m_fVectorZ + current.m_fVectorZ;
                    float weightedZ;
                    RoundedProduct(weightedZ, current.m_fScalarPart, w);
                    rotation.m_fScalarPart += weightedZ;
                }
                if (value.m_fScale != -3.4028234663852886e+38)
                {
                    hasScale = true;
                    scale += value.m_fScale * item.normalizedWeight;
                }
                else
                    scaleWeight -= item.normalizedWeight;
            }
            else
            {
                translationWeight -= item.normalizedWeight;
                scaleWeight -= item.normalizedWeight;
            }
        }
    }
    BlendTransform* __restrict result = &output;
    result->m_kTranslate.x = DAT_01015f5c;
    result->m_kRotate.m_fVectorY = DAT_01015f5c;
    result->m_fScale = DAT_01015f5c;
    if (hasTranslation || hasRotation || hasScale)
    {
        if (translationWeight == 0.0f)
            hasTranslation = false;
        if (scaleWeight < 0.0001)
            hasScale = false;
        if (hasTranslation)
        {
            translation *= 1.0f / translationWeight;
            result->m_kTranslate = translation;
        }
        if (hasRotation)
        {
            float length = (float)sqrt(rotation.Dot(rotation));
            float inverseLength = 1.0f / length;
            rotation.m_fVectorX *= inverseLength;
            rotation.ScaleXYZ(inverseLength);
            result->m_kRotate = rotation;
        }
        if (hasScale)
            result->m_fScale = scale / scaleWeight;
    }
    if (result->m_fScale == -3.4028234663852886e+38 && result->m_kRotate.m_fVectorY == -3.4028234663852886e+38 &&
        result->m_kTranslate.x == -3.4028234663852886e+38)
        return false;
    return true;
}
