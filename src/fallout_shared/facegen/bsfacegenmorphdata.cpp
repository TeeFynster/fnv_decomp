#include "../../../include/BSFaceGenBaseMorphExtraData.h"
#include "../../../include/FaceGenMatrix.h"
// RTTI 0x0101dce4 and ctor 0x004968b0 identify the 8-byte NiRefObject base, not PathingInfo.
#include "../../../include/NiRefObject.h"
// fallout_shared/facegen/bsfacegenmorphdata.cpp: BSFaceGenMorphDataHead, DifferentialArray, BSFaceGenMorphDataHair (26 functions)

#include "../../../include/FaceGenMatrix.h"
#include "../../../include/BSFaceGenMorph.h"
#include "../../../include/BSFaceGenMorphDifferential.h"
#include "../../../include/BSFaceGenMorphStatistical.h"
#include "../../../include/NiExtraData.h"
#include "../../../include/NiGeometry.h"
#include "../../../include/NiGeometryData.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/BSFaceGenMorphData.h"
#include "../../../include/BSFaceGenMorphDataHead.h"
#include "../../../include/BSFaceGenMorphDataHair.h"
#include "../../../include/BSFadeNode.h"
#include "../../../include/NiFixedString.h"

void* __cdecl operator new(unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete(void*);
extern "C" void* __cdecl memset(void*, int, unsigned int);
int __cdecl BSstricmp(const char*, const char*);
const char* __cdecl PrepareScriptMessage(const char*, bool);
int __cdecl Warning(const char*, ...);
const char* __cdecl BSFaceGenManager_GetFaceGenExpressionText(unsigned int);
const char* __cdecl BSFaceGenManager_GetFaceGenModifierText(unsigned int);
const char* __cdecl BSFaceGenManager_GetFaceGenPhonemeText(unsigned int);
const char* __cdecl BSFaceGenManager_GetCustomMorphText(unsigned int);
extern const char DAT_01065e40[];
extern const char DAT_01065dd0[];
extern const char DAT_01065d60[];
extern const char DAT_01065ce8[];
class BGSPerkEntry;
#include "../../../include/BSSimpleList.h"
class MorphName
{
  public:
    const char* std_string_debug_c_str();
    unsigned int data[7];
};
class DifferentialEntry : public MorphName
{
  public:
    unsigned int vertexData;
};
class StatisticalEntry : public MorphName
{
  public:
    unsigned int columns;
    FaceGenMatrix<float> matrix;
};
class DifferentialArray
{
  public:
    unsigned int GetEntryCount();
    DifferentialEntry* GetCheckedElement_00662860(unsigned int);
    unsigned int data[6];
};
class StatisticalArray
{
  public:
    unsigned int EvaluateValue_0065cc30();
    StatisticalEntry* GetElementChecked_00662890(unsigned int);
    unsigned int data[6];
};
class FaceGenTriData
{
  public:
    unsigned char prefix[0xc0];
    DifferentialArray differential;
    StatisticalArray statistical;
    unsigned int std_vector_FR2Vect3TC_float_std_allocator_FR2Vect3TC_float_size();
    NiPoint3& GetCheckedElement(unsigned int);
};

// Builds differential and statistical morph arrays for expressions, modifiers, phonemes and custom morphs from the given tri data.
// @fnv 0x00660ba0
BSFaceGenMorphDataHead::BSFaceGenMorphDataHead(FaceGenTriData* tri)
{
    expressions = 0;
    modifiers = 0;
    phonemes = 0;
    custom = 0;
    if (!tri)
        return;
    // Preserve the original unoptimized stack layout for the shared loop state.
    struct MorphLocals
    {
        BSFaceGenMorph* statisticalMorph;
        unsigned int phoneme;
        unsigned int i;
        StatisticalEntry* entry;
        unsigned int modifier;
        unsigned int j;
        float* values;
        bool ReportDiagnostic, unused1, unused2, found;
        NiPoint3* points;
        unsigned int customIndex;
        unsigned int count;
        BSFaceGenMorph* differentialMorph;
        unsigned int expression;
    } local;
    // Load differential morphs by matching the four sets of names.
    for (local.i = 0; local.i < tri->differential.GetEntryCount(); local.i++)
    {
        local.found = false;
        for (local.expression = 0; local.expression < 15; local.expression++)
        {
            if (!BSstricmp(BSFaceGenManager_GetFaceGenExpressionText(local.expression), tri->differential.GetCheckedElement_00662860(local.i)->std_string_debug_c_str()))
            {
                if (!expressions)
                {
                    expressions = new BSFaceGenMorph*[15];
                    memset(expressions, 0, 60);
                }
                local.count = ((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)->std_vector_FR2Vect3TC_float_std_allocator_FR2Vect3TC_float_size();
                expressions[local.expression] = new BSFaceGenMorphDifferential(local.count);
                local.differentialMorph = expressions[local.expression];
                local.points = (NiPoint3*)((BSSimpleList<BGSPerkEntry*>*)local.differentialMorph)->GetNext();
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    local.points[local.j] =
                        NiPoint3(((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)
                                     ->GetCheckedElement(local.j)
                                     .x,
                                 ((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)
                                     ->GetCheckedElement(local.j)
                                     .y,
                                 ((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)
                                     ->GetCheckedElement(local.j)
                                     .z);
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
        for (local.modifier = 0; local.modifier < 17; local.modifier++)
        {
            if (!BSstricmp(BSFaceGenManager_GetFaceGenModifierText(local.modifier), tri->differential.GetCheckedElement_00662860(local.i)->std_string_debug_c_str()))
            {
                if (!modifiers)
                {
                    modifiers = new BSFaceGenMorph*[17];
                    memset(modifiers, 0, 68);
                }
                local.count = ((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)->std_vector_FR2Vect3TC_float_std_allocator_FR2Vect3TC_float_size();
                modifiers[local.modifier] = new BSFaceGenMorphDifferential(local.count);
                local.differentialMorph = modifiers[local.modifier];
                local.points = (NiPoint3*)((BSSimpleList<BGSPerkEntry*>*)local.differentialMorph)->GetNext();
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    local.points[local.j] =
                        NiPoint3(((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)
                                     ->GetCheckedElement(local.j)
                                     .x,
                                 ((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)
                                     ->GetCheckedElement(local.j)
                                     .y,
                                 ((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)
                                     ->GetCheckedElement(local.j)
                                     .z);
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
        for (local.phoneme = 0; local.phoneme < 16; local.phoneme++)
        {
            if (!BSstricmp(BSFaceGenManager_GetFaceGenPhonemeText(local.phoneme), tri->differential.GetCheckedElement_00662860(local.i)->std_string_debug_c_str()))
            {
                if (!phonemes)
                {
                    phonemes = new BSFaceGenMorph*[16];
                    memset(phonemes, 0, 64);
                }
                local.count = ((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)->std_vector_FR2Vect3TC_float_std_allocator_FR2Vect3TC_float_size();
                phonemes[local.phoneme] = new BSFaceGenMorphDifferential(local.count);
                local.differentialMorph = phonemes[local.phoneme];
                local.points = (NiPoint3*)((BSSimpleList<BGSPerkEntry*>*)local.differentialMorph)->GetNext();
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    local.points[local.j] =
                        NiPoint3(((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)
                                     ->GetCheckedElement(local.j)
                                     .x,
                                 ((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)
                                     ->GetCheckedElement(local.j)
                                     .y,
                                 ((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)
                                     ->GetCheckedElement(local.j)
                                     .z);
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
        for (local.customIndex = 0; local.customIndex < 1; local.customIndex++)
        {
            if (!BSstricmp(BSFaceGenManager_GetCustomMorphText(local.customIndex), tri->differential.GetCheckedElement_00662860(local.i)->std_string_debug_c_str()))
            {
                if (!custom)
                {
                    custom = new BSFaceGenMorph*[1];
                    memset(custom, 0, 4);
                }
                local.count = ((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)->std_vector_FR2Vect3TC_float_std_allocator_FR2Vect3TC_float_size();
                custom[local.customIndex] = new BSFaceGenMorphDifferential(local.count);
                local.differentialMorph = custom[local.customIndex];
                local.points = (NiPoint3*)((BSSimpleList<BGSPerkEntry*>*)local.differentialMorph)->GetNext();
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    local.points[local.j] =
                        NiPoint3(((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)
                                     ->GetCheckedElement(local.j)
                                     .x,
                                 ((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)
                                     ->GetCheckedElement(local.j)
                                     .y,
                                 ((FaceGenTriData*)&tri->differential.GetCheckedElement_00662860(local.i)->vertexData)
                                     ->GetCheckedElement(local.j)
                                     .z);
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
    }
    // Statistical morphs replace differential morphs with the same name.
    for (local.i = 0; local.i < tri->statistical.EvaluateValue_0065cc30(); local.i++)
    {
        local.found = false;
        for (local.expression = 0; local.expression < 15; local.expression++)
        {
            if (!BSstricmp(BSFaceGenManager_GetFaceGenExpressionText(local.expression), tri->statistical.GetElementChecked_00662890(local.i)->std_string_debug_c_str()))
            {
                if (!expressions)
                {
                    expressions = new BSFaceGenMorph*[15];
                    memset(expressions, 0, 60);
                }
                if (expressions[local.expression])
                {
                    Warning(DAT_01065e40,
                            PrepareScriptMessage(tri->statistical.GetElementChecked_00662890(local.i)->std_string_debug_c_str(), false));
                    delete expressions[local.expression];
                }
                local.entry = tri->statistical.GetElementChecked_00662890(local.i);
                local.count = local.entry->matrix.std_vector_float_std_allocator_float_size();
                expressions[local.expression] = new BSFaceGenMorphStatistical(local.count, local.entry->columns);
                local.statisticalMorph = expressions[local.expression];
                local.values = (float*)((BSSimpleList<BGSPerkEntry*>*)local.statisticalMorph)->GetNext();
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    ((unsigned int*)local.values)[local.j] = *(unsigned int*)local.entry->matrix.GetElementPointerChecked(local.j);
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
        for (local.modifier = 0; local.modifier < 17; local.modifier++)
        {
            if (!BSstricmp(BSFaceGenManager_GetFaceGenModifierText(local.modifier), tri->statistical.GetElementChecked_00662890(local.i)->std_string_debug_c_str()))
            {
                if (!modifiers)
                {
                    modifiers = new BSFaceGenMorph*[17];
                    memset(modifiers, 0, 68);
                }
                if (modifiers[local.modifier])
                {
                    Warning(DAT_01065dd0,
                            PrepareScriptMessage(tri->statistical.GetElementChecked_00662890(local.i)->std_string_debug_c_str(), false));
                    delete modifiers[local.modifier];
                }
                local.entry = tri->statistical.GetElementChecked_00662890(local.i);
                local.count = local.entry->matrix.std_vector_float_std_allocator_float_size();
                modifiers[local.modifier] = new BSFaceGenMorphStatistical(local.count, local.entry->columns);
                local.statisticalMorph = modifiers[local.modifier];
                local.values = (float*)((BSSimpleList<BGSPerkEntry*>*)local.statisticalMorph)->GetNext();
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    ((unsigned int*)local.values)[local.j] = *(unsigned int*)local.entry->matrix.GetElementPointerChecked(local.j);
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
        for (local.phoneme = 0; local.phoneme < 16; local.phoneme++)
        {
            if (!BSstricmp(BSFaceGenManager_GetFaceGenPhonemeText(local.phoneme), tri->statistical.GetElementChecked_00662890(local.i)->std_string_debug_c_str()))
            {
                if (!phonemes)
                {
                    phonemes = new BSFaceGenMorph*[16];
                    memset(phonemes, 0, 64);
                }
                if (phonemes[local.phoneme])
                {
                    Warning(DAT_01065d60,
                            PrepareScriptMessage(tri->statistical.GetElementChecked_00662890(local.i)->std_string_debug_c_str(), false));
                    delete phonemes[local.phoneme];
                }
                local.entry = tri->statistical.GetElementChecked_00662890(local.i);
                local.count = local.entry->matrix.std_vector_float_std_allocator_float_size();
                phonemes[local.phoneme] = new BSFaceGenMorphStatistical(local.count, local.entry->columns);
                local.statisticalMorph = phonemes[local.phoneme];
                local.values = (float*)((BSSimpleList<BGSPerkEntry*>*)local.statisticalMorph)->GetNext();
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    ((unsigned int*)local.values)[local.j] = *(unsigned int*)local.entry->matrix.GetElementPointerChecked(local.j);
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
        for (local.customIndex = 0; local.customIndex < 1; local.customIndex++)
        {
            if (!BSstricmp(BSFaceGenManager_GetCustomMorphText(local.customIndex), tri->statistical.GetElementChecked_00662890(local.i)->std_string_debug_c_str()))
            {
                if (!custom)
                {
                    custom = new BSFaceGenMorph*[1];
                    memset(custom, 0, 4);
                }
                if (custom[local.customIndex])
                {
                    Warning(DAT_01065ce8,
                            PrepareScriptMessage(tri->statistical.GetElementChecked_00662890(local.i)->std_string_debug_c_str(), false));
                    delete custom[local.customIndex];
                }
                local.entry = tri->statistical.GetElementChecked_00662890(local.i);
                local.count = local.entry->matrix.std_vector_float_std_allocator_float_size();
                custom[local.customIndex] = new BSFaceGenMorphStatistical(local.count, local.entry->columns);
                local.statisticalMorph = custom[local.customIndex];
                local.values = (float*)((BSSimpleList<BGSPerkEntry*>*)local.statisticalMorph)->GetNext();
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    ((unsigned int*)local.values)[local.j] = *(unsigned int*)local.entry->matrix.GetElementPointerChecked(local.j);
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
    }
}

void __cdecl FUN_00ec7c56();
// Bounds-checks _Pos against the container size and returns a pointer to the element at that position.
// @fnv 0x006578b0
// src: GUESS 0x006578b0 (confidence: high)
template <> float* FaceGenMatrix<float>::GetElementPointerChecked(unsigned int _Pos)
{
    if (_Pos >= std_vector_float_std_allocator_float_size())
        FUN_00ec7c56();
    do
    {
    } while (0);
    return m_pFirst + _Pos;
}

int __cdecl FUN_00ec7ce3(void* dst, unsigned int dstSize, const void* src, unsigned int count);

// Copies count bytes from first to dest and returns dest advanced by count.
// @fnv 0x00660270
// src: GUESS 0x00660270 (confidence: high)
char* __cdecl BSFaceGenMorphData_CopyBytesAndAdvance(const char* first, const char* last, char* dest)
{
    unsigned int count = last - first;
    char* result = dest + count;
    if (count > 0)
        FUN_00ec7ce3(dest, count, first, count);
    return result;
}

extern char const* const g_011d37c8_arg1;
extern NiFixedString* DAT_011d5b8c;

// @fnv 0x00662760
// src: COMMUNITY 0x00662760
void __cdecl BSFaceGenBaseMorphExtraData_InitTag()
{
    DAT_011d5b8c = new NiFixedString((char const*)&g_011d37c8_arg1);
}

void __cdecl FUN_00ec7c56();

// Bounds-checks _Pos against the array size, then returns the DifferentialEntry at data[3] + _Pos * 0x34.
// @fnv 0x00662860
// src: GUESS 0x00662860 (confidence: medium)
DifferentialEntry* DifferentialArray::GetCheckedElement_00662860(unsigned int _Pos)
{
    if (_Pos >= GetEntryCount())
        FUN_00ec7c56();
    do
    {
    } while (0);
    return (DifferentialEntry*)(data[3] + _Pos * 0x34);
}

extern NiRTTI g_011d5ba8;

// @fnv 0x00662390
const NiRTTI* BSFaceGenMorphDataHair::GetRTTI() const
{
    return &g_011d5ba8;
}

extern NiRTTI g_011d5ba0;

struct FUN_006626e0_shell
{
    NiRTTI* GetRTTI();
};

// @fnv 0x006626e0
NiRTTI* FUN_006626e0_shell::GetRTTI()
{
    return &g_011d5ba0;
}

// @fnv 0x00662840
int __fastcall GetEntryCount(int* thisPtr)
{
    return (*(thisPtr + 4) - *(thisPtr + 3)) / 0x34;
}

// @fnv 0x00661d40
BSFaceGenMorphData::~BSFaceGenMorphData()
{
}

// @fnv 0x00662820
// src: COMMUNITY 0x00662820
template <> unsigned int FaceGenMatrix<float>::std_vector_float_std_allocator_float_size()
{
    return (reinterpret_cast<int>(m_pLast) - reinterpret_cast<int>(m_pFirst)) >> 2;
}

void __cdecl _delete(void*, unsigned int);
// Destroys this head morph data, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00661db0
void* BSFaceGenMorphDataHead::FUN_00661db0(unsigned int flags)
{
    BSFaceGenMorphDataHead::~BSFaceGenMorphDataHead();
    if (flags & 1)
        _delete(this, 24);
    return this;
}

// Returns modifiers[idx] when modifiers is set and idx is in [0,16], otherwise returns 0.
// @fnv 0x00662110
// src: COMMUNITY 0x00662110
int BSFaceGenMorphDataHead::GetModifierMorph(int aiIndex)
{
    return modifiers && aiIndex > -1 && aiIndex < 0x11 ? (int)modifiers[aiIndex] : 0;
}

// Returns phonemes[idx] when phonemes is set and idx is in [0, 16), otherwise returns 0.
// @fnv 0x00662150
// src: COMMUNITY 0x00662150
int BSFaceGenMorphDataHead::GetPhonemeMorph(int aiIndex)
{
    return phonemes && aiIndex > -1 && aiIndex < 0x10 ? (int)phonemes[aiIndex] : 0;
}

// Returns custom[a] when custom is non-null and a is in [0,1), otherwise returns 0.
// @fnv 0x00662190
// src: COMMUNITY 0x00662190
int BSFaceGenMorphDataHead::GetCustomMorph(int aiIndex)
{
    return custom && aiIndex > -1 && aiIndex < 1 ? (int)custom[aiIndex] : 0;
}

void __cdecl _delete(void*, unsigned int);
// @fnv 0x006623a0
void* BSFaceGenMorphDataHair::FUN_006623a0(unsigned int flags)
{
    BSFaceGenMorphDataHair::~BSFaceGenMorphDataHair();
    if (flags & 1)
        _delete(this, 12);
    return this;
}

void __cdecl _delete(void*, unsigned int);
struct Host006626f0
{
    void UpdateFields_00662720();
    void* FUN_006626f0(unsigned int);
};
// Calls FUN_00662720, then deletes this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x006626f0
void* Host006626f0::FUN_006626f0(unsigned int flags)
{
    this->UpdateFields_00662720();
    if (flags & 1)
        _delete(this, 0x18);
    return this;
}

extern int DAT_01065fac;
void __cdecl _Deallocate(void*);
struct FUN_00662720_shell
{
    int f0;
    int f4;
    int f8;
    void* f12;
    void UpdateFields_00662720();
};
// @fnv 0x00662720
// src: GUESS 0x00662720 (confidence: low)
void FUN_00662720_shell::UpdateFields_00662720()
{
    *(void**)this = (void*)&DAT_01065fac;
    if (f12)
    {
        void* tmp = f12;
        _Deallocate(tmp);
    }
    ((NiExtraData*)this)->DestroyFields_00a7b300();
}

namespace fnv_006627e0 {
extern NiFixedString* DAT_011d5b8c;
// Calls FUN_004b9900(1) on DAT_011d5b8c if non-null, then sets DAT_011d5b8c to null.
// @fnv 0x006627e0
// src: GUESS 0x006627e0 (confidence: low)
void Object_UpdateFields_006627e0()
{
    NiFixedString* p2;
    {
        NiFixedString* p1 = DAT_011d5b8c;
        p2 = p1;
        {
            int v;
            if (p2)
                v = (int)p2->FUN_004b9900(1);
            else
                v = 0;
        }
    }
    DAT_011d5b8c = 0;
}
}  // namespace fnv_006627e0

// @fnv 0x00661d10
BSFaceGenMorphData::BSFaceGenMorphData()
{
}

// Returns the element at idx from the array, or 0 if the array is null or idx is out of range (0..14).
// @fnv 0x006620d0
// src: COMMUNITY 0x006620d0
int __thiscall BSFaceGenMorphDataHead::GetExpressionMorph(int aiIndex)
{
    return expressions == 0 || aiIndex <= -1 || aiIndex >= 0xf ? 0 : (int)expressions[aiIndex];
}

extern double _gModifierZero;
struct FUN_00662460_iface
{
    virtual void v0();
    virtual void ApplyMorph_00662460(int a, int b, float c);
};
// Forwards a, b and c to the hair morph when it and a are set and c is not below _gModifierZero.
// @fnv 0x00662460
// src: COMMUNITY 0x00662460
void BSFaceGenMorphDataHair::ApplyMorph_00662460(int aiArg1, int aiArg2, float c)
{
    if (!hairMorph || !aiArg1 || c < _gModifierZero)
        return;
    ((FUN_00662460_iface*)hairMorph)->ApplyMorph_00662460(aiArg1, aiArg2, c);
}

// @fnv 0x006623d0
BSFaceGenMorphDataHair::~BSFaceGenMorphDataHair()
{
    if (hairMorph)
        delete (BSFaceGenMorph*)hairMorph;
}

// Frees each non-null entry in the expressions, modifiers, phonemes and custom arrays, then deletes the arrays themselves.
// @fnv 0x00661de0
BSFaceGenMorphDataHead::~BSFaceGenMorphDataHead()
{
    if (expressions)
    {
        for (unsigned int expr = 0; expr < 15; ++expr)
            if (expressions[expr])
                delete expressions[expr];
        delete[] expressions;
    }
    if (modifiers)
    {
        for (unsigned int mod = 0; mod < 17; ++mod)
            if (modifiers[mod])
                delete modifiers[mod];
        delete[] modifiers;
    }
    if (phonemes)
    {
        for (unsigned int phon = 0; phon < 16; ++phon)
            if (phonemes[phon])
                delete phonemes[phon];
        delete[] phonemes;
    }
    if (custom)
    {
        for (unsigned int cust = 0; cust < 1; ++cust)
            if (custom[cust])
                delete custom[cust];
        delete[] custom;
    }
}

typedef void (__thiscall* MorphApplyFunction)(BSFaceGenMorph*, int, int, float);
// Dispatches on sel to one of four lookup functions with p2, then if the result is non-null calls v1(p3, p4, p5) on it.
// @fnv 0x00662030
// src: COMMUNITY 0x00662030
void BSFaceGenMorphDataHead::ApplyMorph(int aiSelector, int aiIndex, int aiArg1, int aiArg2, float p5)
{
    int pMorph = 0;
    switch (aiSelector)
    {
    case 1:
        pMorph = GetExpressionMorph(aiIndex);
        break;
    case 2:
        pMorph = GetModifierMorph(aiIndex);
        break;
    case 0:
        pMorph = GetPhonemeMorph(aiIndex);
        break;
    case 3:
        pMorph = GetCustomMorph(aiIndex);
        break;
    }
    if (pMorph != 0)
        ((MorphApplyFunction*)*(void**)pMorph)[1]((BSFaceGenMorph*)pMorph, aiArg1, aiArg2, p5);
}

// @fnv 0x006621d0
BSFaceGenMorphDataHair::BSFaceGenMorphDataHair(FaceGenTriData* pkTriData)
{
    hairMorph = 0;
    if (!pkTriData)
        return;
    if (!BSstricmp("HairMorph", pkTriData->differential.GetCheckedElement_00662860(0)->std_string_debug_c_str()))
    {
        unsigned int uiCountCur =
            ((FaceGenTriData*)&pkTriData->differential.GetCheckedElement_00662860(0)->vertexData)->std_vector_FR2Vect3TC_float_std_allocator_FR2Vect3TC_float_size();
        hairMorph = new BSFaceGenMorphDifferential(uiCountCur);
        NiPoint3* pkPointsTmp = (NiPoint3*)((BSSimpleList<BGSPerkEntry*>*)hairMorph)->GetNext();
        for (unsigned int i = 0; i < uiCountCur; i++)
            pkPointsTmp[i] =
                NiPoint3(((FaceGenTriData*)&pkTriData->differential.GetCheckedElement_00662860(0)->vertexData)->GetCheckedElement(i).x,
                         ((FaceGenTriData*)&pkTriData->differential.GetCheckedElement_00662860(0)->vertexData)->GetCheckedElement(i).y,
                         ((FaceGenTriData*)&pkTriData->differential.GetCheckedElement_00662860(0)->vertexData)->GetCheckedElement(i).z);
    }
}

const NiFixedString& __cdecl BSFaceGenBaseMorphExtraData_GetTag();
class GeometryBufferView
{
  public:
    int first, second, third;
    GeometryBufferView();
    void* Modelloader_GetReferencedThis();
    void CopyV3(NiPoint3*);
    void AddToA();
};
void* __cdecl _memcpy(void*, const void*, unsigned int);

// Copies the geometry's vertex stream into a new NiPoint3 array, appending extra vertices when provided, and stores the counts.
// @fnv 0x006624c0
BSFaceGenBaseMorphExtraData::BSFaceGenBaseMorphExtraData(NiGeometry* geometry, NiPoint3* apExtraVertices, unsigned int extraCount)
    : NiExtraData(BSFaceGenBaseMorphExtraData_GetTag())
{
    GeometryBufferView geometryStream;
    if (geometry && geometry->GetModelData() && geometry->GetModelData()->IsGeometryDataStreamable(true))
        geometry->GetModelData()->NiGeometryData_GetVerticesIterator(geometryStream);
    if (geometryStream.Modelloader_GetReferencedThis())
    {
        originalCount = geometry->GetVertexCount();
        count = originalCount;
        if (apExtraVertices && extraCount)
            count += extraCount;
        vertices = new NiPoint3[count];
        unsigned int i = 0;
        NiPoint3* dest = vertices;
        for (; i < originalCount; i++)
        {
            NiPoint3 vertex;
            geometryStream.CopyV3(&vertex);
            *dest = vertex;
            dest++;
            geometryStream.AddToA();
        }
        if (apExtraVertices && extraCount)
            _memcpy(vertices + originalCount, apExtraVertices, extraCount * sizeof(NiPoint3));
        geometry->GetModelData()->NiGeometryData_UnlockPackedVertexData();
    }
    else
    {
        vertices = 0;
        originalCount = 0;
        count = 0;
    }
}
