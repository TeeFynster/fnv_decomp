#define FNV64_NIANIMATIONKEY_OWN_KEY_ACCESSOR // Preserve the out-of-line accessor call in exe color-key code.

// src/gamebryo2.2/corelibs/nianimation/nicolorkey.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nicolorkey.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiColorA.h"

struct blob16
{
    char b[16];
};
#include "../../../../include/NiAnimationKey.h"
typedef char _sizecheck_NiAnimationKey[sizeof(NiAnimationKey) == 4 ? 1 : -1];
struct ColorAnimationKey : public NiAnimationKey
{
    static int RegisterObjectLoader();
    static void RegisterSupportedFunctions(int, int);
    static NiAnimationKey* CreateObjectFromStream(NiStream*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveToStream(NiStream*, NiAnimationKey*, unsigned int);
    static void SaveBinary(NiStream*, NiAnimationKey*);
    static void Copy(NiAnimationKey*, void*);
    static NiAnimationKey* CreateArray(unsigned int);
    static void DeleteArray(NiAnimationKey*);
    static bool Insert(float, NiAnimationKey**, unsigned int*);
    static float ComputeMaxCurvature(NiAnimationKey*, unsigned int);
    static void Interpolate(float, void*, void*, void*);
    static void InterpolateD1(float, void*, void*, void*);
    static void InterpolateD2(float, void*, void*, void*);
    static bool Equal(void*, void*);
    static void FillDerivedVals(NiAnimationKey*, unsigned int, unsigned char);
    void SetColor(void*);
    void* GetColor();
    static struct blob16 InterpolatePosition(float, ColorAnimationKey*, int, unsigned int, unsigned int*,
                                             unsigned char);
    ColorAnimationKey* GetKeyPointerByIndex(unsigned int, unsigned char);
    static unsigned char GetKeySize(int);
    static int* GetInterpFunction(int);
    static int* GetCreateFunction(int);
    static int* GetSaveFunction(int);
    static int* GetEqualFunction(int);
    static int* GetCopyFunction(int);
    static int* GetArrayFunction(int);
    static int* GetDeleteFunction(int);
    static int* GetInsertFunction(int);
    static void SetDefault(void*);
    static struct blob16 GenInterpDefault(float, ColorAnimationKey*, int, unsigned int, unsigned char);
    void* __vecDelDtor(unsigned int);
    char m_kRgbaColor[16];
};
typedef char _sizecheck_NiColorKey[sizeof(ColorAnimationKey) == 20 ? 1 : -1];

typedef char _sizecheck_NiColorA[sizeof(NiColorA) == 16 ? 1 : -1];

typedef void(__cdecl* InterpFn)(float, const char*, const char*, void*);
extern InterpFn DAT_011f3cd8[];
extern double DAT_010241b0;

// Returns a table color directly when count is one or f matches DAT_010241b0; otherwise interpolates adjacent entries and updates pIdx.
// @fnv 0x00a296c0
NiColorA __cdecl InterpolateColor(float afTime, const char* table, unsigned int interp, unsigned int count,
                                   unsigned int* pIdx, unsigned char stride)
{
    if (count == 1 || afTime == DAT_010241b0)
    {
        return *(const NiColorA*)(table + 4);
    }
    unsigned int idx = *pIdx;
    unsigned int last = count - 1;
    float prevVal = *(const float*)(table + stride * idx);
    if (afTime < prevVal)
    {
        prevVal = *(const float*)table;
        idx = 0;
    }
    float fCurTime = 0.0f;
    unsigned int i = idx + 1;
    __assume(i <= last);
    for (; i <= last; ++i, ++idx)
    {
        fCurTime = *(const float*)(table + stride * i);
        if (afTime <= fCurTime)
            break;
        prevVal = fCurTime;
    }
    // The original temporary is initialized below without invoking a constructor.
    float colorStorage[4];
    NiColorA& color = *reinterpret_cast<NiColorA*>(colorStorage);
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
    color.a = 0.0f;
    float t = (afTime - prevVal) / (fCurTime - prevVal);
    DAT_011f3cd8[interp](t, table + stride * idx, table + stride * i, &color);
    *pIdx = idx;
    return color;
}
