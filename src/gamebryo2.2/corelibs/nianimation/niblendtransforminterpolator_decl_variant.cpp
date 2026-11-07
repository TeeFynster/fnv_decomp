
// src/gamebryo2.2/corelibs/nianimation/niblendtransforminterpolator_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00a40b30: the skeleton of src/gamebryo2.2/corelibs/nianimation/niblendtransforminterpolator.cpp
// that unit declares it this way.

#include "../../../../include/NiBlendTransformInterpolator.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiObjectNET.h"
class NiRTTI;
struct FUN_00a40a40_shell : public NiBlendTransformInterpolator
{
    void* NiBlendTransformInterpolator_GetRTTI();
};
extern "C" const NiRTTI* g_011f3e64;
struct FUN_00a40a20_shell : public NiBlendTransformInterpolator
{
    bool NiBlendTransformInterpolator_IsEqual(NiObject*);
};
struct FUN_00a36fd0_tgt
{
    char NiBlendInterpolator_IsEqual(NiObject*);
};
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
void __stdcall NiBlendTransformInterpolator_LoadBinary(FUN_00a40ab0_obj* a1);
template <class T> class AGPrimArray
{
  public:
    virtual ~AGPrimArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, const T& element);
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(const T& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};
typedef AGPrimArray<const char*> AGViewerStrings;
extern "C" const char* DAT_011f3e64;
void __stdcall NiBlendInterpolator_GetViewerStrings(AGViewerStrings* pkStrings);
const char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcText);
void __stdcall NiBlendTransformInterpolator_GetViewerStrings(AGViewerStrings* pkStrings);

extern const float DAT_01015f5c;
extern const float DAT_0109696c;
extern const double DAT_010241b0;
// The rotation part of NiQuatTransform (qx..qw) copied as plain words, as the POD assignment does.
struct QuatWords
{
    unsigned int w[4];
};
__forceinline void Invalidate850(NiQuatTransform& value)
{
    value.scale = value.qy = value.x = -3.402823466e+38F;
}
// @fnv 0x00a40b30
// src: XBOX_PDB 0x00a40b30
bool NiBlendTransformInterpolator::StoreSingleValue(float time, NiObjectNET* object, NiQuatTransform& value)
{
    if (m_uiObjectFlags & 1)
        time = m_fSingleInterpolatorTime;
    if (time == DAT_0109696c)
    {
        Invalidate850(value);
        return false;
    }
    if (m_pSingleInterpolator->UpdateTransform(time, object, value))
    {
        if (value.qy != DAT_010241b0)
        {
            NiQuaternion rotation = *reinterpret_cast<NiQuaternion*>(&value.qx);
            rotation.Normalize();
            *reinterpret_cast<QuatWords*>(&value.qx) = *reinterpret_cast<QuatWords*>(&rotation);
        }
        return true;
    }
    Invalidate850(value);
    return false;
}
