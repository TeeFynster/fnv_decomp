#pragma once

class NiStream;

class NiAnimationKey
{
public:

    enum KeyType
    {
        NOINTERP,
        LINKEY,
        BEZKEY,
        TCBKEY,
        EULERKEY,
        STEPKEY,
        NUMKEYTYPES
    };

    enum KeyContent
    {
        FLOATKEY,
        POSKEY,
        ROTKEY,
        COLORKEY,
        TEXTKEY,
        BOOLKEY
    };


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
    void SetTime(float);
    static unsigned char GetKeySize(int, int);
    static int* GetCurvatureFunction(int, int);
    static int* GetInterpFunction(int, int);
    static int* GetInterpD1Function(int, int);
    static int* GetInterpD2Function(int, int);
    static int* GetFillDerivedFunction(int, int);
    static int* GetCreateFunction(int, int);
    static int* GetSaveFunction(int, int);
    static int* GetEqualFunction(int, int);
    static int* GetCopyFunction(int, int);
    static int* GetArrayFunction(int, int);
    static int* GetDeleteFunction(int, int);
    static int* GetInsertFunction(int, int);
    static void AddKeyToArray(int, int, void*, unsigned int, float, float, NiAnimationKey**, unsigned int*);
    static void RemoveKeyFromArray(int, int, NiAnimationKey**, unsigned int*, float, float);
    static void SetCreateFunction(int, int, int*);
    static void SetCurvatureFunction(int, int, int*);
    static void SetInterpFunction(int, int, int*);
    static void SetInterpD1Function(int, int, int*);
    static void SetInterpD2Function(int, int, int*);
    static void SetEqualFunction(int, int, int*);
    static void SetCopyFunction(int, int, int*);
    static void SetArrayFunction(int, int, int*);
    static void SetDeleteFunction(int, int, int*);
    static void SetInsertFunction(int, int, int*);
    static void SetSaveFunction(int, int, int*);
    static void SetFillDerivedValsFunction(int, int, int*);
    static void SetKeySize(int, int, unsigned char);
    static bool OkayToInsert(float, void*, unsigned int, unsigned int*, unsigned char);
    void* __vecDelDtor(unsigned int);

    float GetTime() const { return m_fTime; }

#ifdef FNV64_NIANIMATIONKEY_OWN_KEY_ACCESSOR
    NiAnimationKey* GetKeyPointerByIndex(unsigned int, unsigned char);
#else
    NiAnimationKey* GetKeyPointerByIndex(unsigned int uiIndex, unsigned char ucKeySize)
    {
        return (NiAnimationKey*)((char*)this + uiIndex * ucKeySize);
    }
#endif

    static bool FindKeyIndex(float fTime, NiAnimationKey* pkKeys, unsigned int uiNumKeys,
        unsigned int& uiIndex, unsigned char ucKeySize);

    float m_fTime;
};
