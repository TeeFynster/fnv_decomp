
// src/staging/blk_00600000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/NiTMallocInterface.h"
#include "../../include/Setting.h"
#include "../../include/NiTArray.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/TESForm.h"
#include "../../include/TESResponseList.h"
#include "../../include/TESRaceForm.h"
#include "../../include/TESTopicInfo.h"
#include "../../include/TopicInfoArray.h"
#include "../../include/StartMenu.h"

extern "C" void __cdecl FUN_00600fd0(int, int);

struct FUN_00600ad0_cls
{
    const char* v;
    void __thiscall FUN_00600fd0(int, int);
    FUN_00600ad0_cls* __thiscall BSTCaseInsensitiveStringMap_IDLE_ANIM_ROOT_BSTCaseInsensitiveStringMap(int a, bool b);
};

// Calls FUN_00600fd0 with the two arguments, sets v to a string literal, and returns this.
// @fnv 0x00600ad0
// src: EXE 0x00600ad0
FUN_00600ad0_cls* __thiscall FUN_00600ad0_cls::BSTCaseInsensitiveStringMap_IDLE_ANIM_ROOT_BSTCaseInsensitiveStringMap(int a, bool b)
{
    FUN_00600fd0(a, b);
    v = "@\r`";
    return this;
}

struct FUN_00600d70_shell
{
    void ForwardCall_00600d70();
};

struct FUN_00600b00_shell
{
    const char* m_p;
    void ForwardCall_00600d70();
    ~FUN_00600b00_shell();
};

// @fnv 0x00600b00
FUN_00600b00_shell::~FUN_00600b00_shell()
{
    m_p = "@\r`";
    ForwardCall_00600d70();
}

extern int DAT_0104a068;
struct FUN_00600d10_class
{
    int m_vft;
    void FUN_00601000(int a, int b);
    FUN_00600d10_class(int a, int b);
};
// Calls FUN_00601000 with the two arguments, then stores the address of DAT_0104a068 into m_vft.
// @fnv 0x00600d10
FUN_00600d10_class::FUN_00600d10_class(int aiArg1, int aiArg2)
{
    FUN_00601000(aiArg1, aiArg2);
    m_vft = (int)&DAT_0104a068;
}

extern "C" void __cdecl NiTMapBase_DFALL_NiTMapItem_char_const_IDLE_ANIM_ROOT_char_const_IDLE_ANIM_ROOT_Init(int);
extern int DAT_0104a090;

struct FUN_006010d0_Class
{
    int m_field_0;
    int __thiscall NiTMapBase_DFALL_NiTMapItem_char_const_IDLE_ANIM_ROOT_char_const_IDLE_ANIM_ROOT_Init(int);
    int __thiscall InitializeWithGlobal(int param);
};

// Calls FUN_00601100 with param, stores the address of DAT_0104a090 in m_field_0, and returns this.
// @fnv 0x006010d0
int __thiscall FUN_006010d0_Class::InitializeWithGlobal(int param)
{
    NiTMapBase_DFALL_NiTMapItem_char_const_IDLE_ANIM_ROOT_char_const_IDLE_ANIM_ROOT_Init(param);
    m_field_0 = (int)&DAT_0104a090;
    return (int)this;
}

struct FUN_006053f0_class
{
    void TESNPC_SetWeight(float value);
};

// @fnv 0x006053f0
// src: COMMUNITY 0x006053f0
void FUN_006053f0_class::TESNPC_SetWeight(float value)
{
    *(float*)((char*)this + 0x1f8) = value;
}

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

GlobalObject_0045cf30 g_011cb99c;

// @fnv 0x00605d50
// src: COMMUNITY 0x00605d50
unsigned char General_bFaceGenTexturing_Get()
{
    return g_011cb99c.Bool()[0];
}

extern int DAT_0104ab04;
struct GlobalObject_00869f00
{
    void Clear(bool);
    void Reset();
};
// @fnv 0x0060bac0
void GlobalObject_00869f00::Reset()
{
    *(int*)this = (int)&DAT_0104ab04;
    this->Clear(true);
}

extern "C" void __cdecl Object_ProcessState_0060be00(void*, void*, void*, void*);

struct FUN_0060bb40_class
{
    void __thiscall ForwardCall_0060bb40(void* a, void* b, void* c);
};

// @fnv 0x0060bb40
// src: GUESS 0x0060bb40 (confidence: low)
void __thiscall FUN_0060bb40_class::ForwardCall_0060bb40(void* apArg1, void* apArg2, void* apArg3)
{
    Object_ProcessState_0060be00(apArg1, apArg2, apArg3, (char*)this + 8);
}

namespace fnv_0060bdd0 {
extern void* DAT_0104ab04;
struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
    AX* BSSimpleArray_BGSHeadPart_1024_BSSimpleArray_BGSHeadPart_1024();
};
// @fnv 0x0060bdd0
// src: COMMUNITY 0x0060bdd0
AX* AX::BSSimpleArray_BGSHeadPart_1024_BSSimpleArray_BGSHeadPart_1024()
{
    *reinterpret_cast<void**>(this) = &DAT_0104ab04;
    BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}
}  // namespace fnv_0060bdd0

// @fnv 0x0060be50
// src: GUESS 0x0060be50 (confidence: low)
void Runtime_ProcessEntries_0060be50(int start, int end, const float* apfSrc)
{
    for (; start != end; start += 4)
        *(float*)start = *apfSrc;
}

extern "C" void __cdecl CallWithFlagValues(void*, void*, void*);

// @fnv 0x0060bed0
// src: GUESS 0x0060bed0 (confidence: medium)
void __cdecl Runtime_CallWithFlagValues_Thunk(void* apArg1, void* apArg2, void* apArg3)
{
    CallWithFlagValues(apArg1, apArg2, apArg3);
}

extern "C" void __cdecl UninitCopyChecked(int, int, int, int);

// @fnv 0x0060c270
// src: GUESS 0x0060c270 (confidence: low)
void __cdecl Runtime_ForwardCall_0060c270(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    UninitCopyChecked(aiArg1, aiArg2, aiArg3, aiArg4);
}

struct FUN_0060c5c0_class
{
    FUN_0060c5c0_class* TESQuest_Data_Init();
};

// Clears the two leading bytes and the float at offset 4 of this object, then returns this.
// @fnv 0x0060c5c0
// src: COMMUNITY 0x0060c5c0
FUN_0060c5c0_class* FUN_0060c5c0_class::TESQuest_Data_Init()
{
    *(char*)this = 0;
    *((char*)this + 1) = 0;
    *(float*)((char*)this + 4) = 0.0f;
    return this;
}

struct FUN_0060fd90_Class
{
    bool __thiscall IsFlag2Set();
};
// @fnv 0x0060fd90
bool __thiscall FUN_0060fd90_Class::IsFlag2Set()
{
    return (((unsigned char*)this)[0] & 2) != 0;
}

struct FUN_00610190_cls
{
    bool IsFlagSet();
};

// @fnv 0x00610190
bool FUN_00610190_cls::IsFlagSet()
{
    if (*(unsigned char*)this & 1)
        return true;
    return false;
}

struct FUN_006130c0_Class
{
    void* TESRace_GetSkillBonus(int index);
};

// @fnv 0x006130c0
// src: COMMUNITY 0x006130c0
void* FUN_006130c0_Class::TESRace_GetSkillBonus(int index)
{
    return &((char*)this)[0x50 + index * 2];
}

struct FUN_00613870_Class
{
    int TESRace_GetDefaultHair(int index);
};

// @fnv 0x00613870
// src: COMMUNITY 0x00613870
int FUN_00613870_Class::TESRace_GetDefaultHair(int index)
{
    return *(int*)((char*)this + 0x94 + index * 4);
}

struct FUN_00613890_Class
{
    void __thiscall SetIndexedInt(int index, int value);
};

// @fnv 0x00613890
void __thiscall FUN_00613890_Class::SetIndexedInt(int index, int value)
{
    *(int*)((char*)this + 0x94 + index * 4) = value;
}

void __fastcall Object_ForwardCall_00618940(void*);

// @fnv 0x00618920
// src: GUESS 0x00618920 (confidence: low)
void __fastcall Object_ForwardCall_00618920(void* self)
{
    Object_ForwardCall_00618940(self);
}

// @fnv 0x0061bbf0
// src: COMMUNITY 0x0061bbf0
char TESTopic_IsFormTypeDialogueChild(unsigned char a)
{
    if (a == 0x46)
        return 1;
    return 0;
}

extern int DAT_0104d450;
struct FUN_0061bef0_class
{
    void* vtbl;
    void __thiscall FUN_0061c120(void* a, void* b);
    FUN_0061bef0_class(void* a, void* b);
};
// Calls FUN_0061c120 with the two arguments, then sets the object's vtbl to &DAT_0104d450.
// @fnv 0x0061bef0
FUN_0061bef0_class::FUN_0061bef0_class(void* apArg1, void* apArg2)
{
    FUN_0061c120(apArg1, apArg2);
    vtbl = &DAT_0104d450;
}

namespace fnv_0061bf50 {
extern int DAT_0104d458;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0061bf50_Class
{
    void InitAndClear();
};
// @fnv 0x0061bf50
void __thiscall FUN_0061bf50_Class::InitAndClear()
{
    *reinterpret_cast<int**>(this) = &DAT_0104d458;
    reinterpret_cast<GlobalObject_00869f00*>(this)->Clear(true);
}
}  // namespace fnv_0061bf50

// @fnv 0x0061f420
// src: GUESS 0x0061f420 (confidence: low)
bool Object_ComputeValue_0061f420(unsigned int auiValue, unsigned int auiOther)
{
    if (auiValue < auiOther)
        return true;
    return false;
}


struct FUN_0061f440 : TESResponseList
{
    void ClearResponses();
};

// @fnv 0x0061f440
void FUN_0061f440::ClearResponses()
{
    TESResponseList::ClearResponses();
}

extern int DAT_0104d948;
struct FUN_0061fa10_class
{
    void __thiscall NiTMapBase_DFALL_NiTMapItem_TESObjectREFR_int_TESObjectREFR_int_NiTMapBase(int);
    int __thiscall NiTMap_TESObjectREFR_int_NiTMap(int a);
};
// Calls FUN_0061fa70 with a, stores the address of DAT_0104d948 at this, and returns this.
// @fnv 0x0061fa10
// src: EXE 0x0061fa10
int __thiscall FUN_0061fa10_class::NiTMap_TESObjectREFR_int_NiTMap(int a)
{
    NiTMapBase_DFALL_NiTMapItem_TESObjectREFR_int_TESObjectREFR_int_NiTMapBase(a);
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0104d948);
    return reinterpret_cast<int>(this);
}

extern void NiFreeAlias(void*);
extern int DAT_0104a0b0;

struct FUN_00600eb0_cls
{
    void* vtbl;
    int a;
    void* b;
    void RemoveAll();
    void SetVtableAndProcessState_00600eb0();
};

// Sets the vtable pointer, calls RemoveAll, then frees the b pointer via NiFreeAlias.
// @fnv 0x00600eb0
// src: GUESS 0x00600eb0 (confidence: low)
void FUN_00600eb0_cls::SetVtableAndProcessState_00600eb0()
{
    *reinterpret_cast<void**>(this) = &DAT_0104a0b0;
    RemoveAll();
    NiFreeAlias(b);
}

extern int DAT_0104d968;
void NiFreeAlias(void*);

struct NiTPointerMapIntInt : public NiTPointerMap<int, int>
{
    void ReleaseStorage_0061fb40();
};

// Resets the vtable pointer, removes all entries, then frees the pointer stored at offset 8.
// @fnv 0x0061fb40
// src: GUESS 0x0061fb40 (confidence: medium)
void NiTPointerMapIntInt::ReleaseStorage_0061fb40()
{
    *(int**)this = &DAT_0104d968;
    RemoveAll();
    NiFreeAlias(*(void**)((char*)this + 8));
}

extern int DAT_0104a060;
void __cdecl MyDeallocate(void*);
struct FUN_00600b90_Cls
{
    void* m0;
    void* m4;
    void __thiscall ReleaseMemberStorage();
};
// Sets m0 to the address of DAT_0104a060 and frees the m4 pointer via MyDeallocate.
// @fnv 0x00600b90
// src: GUESS 0x00600b90 (confidence: medium)
void __thiscall FUN_00600b90_Cls::ReleaseMemberStorage()
{
    m0 = (void*)&DAT_0104a060;
    MyDeallocate(m4);
}

void __cdecl Deallocate(void*);

struct FUN_00600ee0_cls
{
    void* FUN_00600ee0(unsigned int flags);
};

// Calls FUN_00600eb0 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00600ee0
void* FUN_00600ee0_cls::FUN_00600ee0(unsigned int flags)
{
    ((FUN_00600eb0_cls*)this)->SetVtableAndProcessState_00600eb0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_00600e50_class
{
    void __thiscall FUN_00600e50();
    void* __thiscall FUN_00600f10(unsigned int flags);
};

// Calls FUN_00600e50, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00600f10
void* FUN_00600e50_class::FUN_00600f10(unsigned int flags)
{
    FUN_00600e50();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00600d90_shell
{
    void FUN_00600d90();
    void* FUN_00600f40(unsigned int flags);
};
// @fnv 0x00600f40
void* FUN_00600d90_shell::FUN_00600f40(unsigned int flags)
{
    FUN_00600d90();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_005ffbd0_cls
{
    void ReleaseMemberStorage();
};
void __cdecl Deallocate(void*);
struct FUN_00600f70_cls
{
    void* FUN_00600f70(unsigned int flags);
};
// @fnv 0x00600f70
void* FUN_00600f70_cls::FUN_00600f70(unsigned int flags)
{
    ((FUN_005ffbd0_cls*)this)->ReleaseMemberStorage();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_00600fa0 {
struct FUN_005ffbd0_cls
{
    void ForwardCall_005ffbd0();
    void* __thiscall FUN_00600fa0(unsigned int flags);
};
void __cdecl operator delete(void*);
// Calls FUN_005ffbd0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x00600fa0
void* __thiscall FUN_005ffbd0_cls::FUN_00600fa0(unsigned int flags)
{
    ForwardCall_005ffbd0();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_00600fa0

extern int DAT_0104a0d0;
struct FUN_006010a0_holder
{
    void __thiscall NiTStringTemplateMap_NiTMap_char_const_IDLE_ANIM_ROOT_IDLE_ANIM_ROOT_NiTStringTemplateMap(int, bool);
};
struct FUN_00600fd0 : FUN_006010a0_holder
{
    FUN_00600fd0(int, bool);
};
// @fnv 0x00600fd0
FUN_00600fd0::FUN_00600fd0(int a, bool b)
{
    NiTStringTemplateMap_NiTMap_char_const_IDLE_ANIM_ROOT_IDLE_ANIM_ROOT_NiTStringTemplateMap(a, b);
    *(void**)this = (void*)&DAT_0104a0d0;
}

struct FUN_00601070_shell : FUN_00600b00_shell
{
    void* __thiscall FUN_00601070(unsigned int flags);
};

// Calls FUN_00600d70, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x00601070
void* __thiscall FUN_00601070_shell::FUN_00601070(unsigned int flags)
{
    ForwardCall_00600d70();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_0104a070;
struct FUN_006010a0_Class
{
    int* m_vft;
    int m_field_4;
    int m_field_8;
    int m_field_c;
    unsigned char m_field_10;
    FUN_006010a0_Class* __thiscall NiTStringTemplateMap_NiTMap_char_const_IDLE_ANIM_ROOT_IDLE_ANIM_ROOT_NiTStringTemplateMap(int a, unsigned char b);
};
// Calls InitializeWithGlobal on this, sets the vtable to DAT_0104a070, stores b in m_field_10 and returns this.
// @fnv 0x006010a0
// src: EXE 0x006010a0
FUN_006010a0_Class* __thiscall FUN_006010a0_Class::NiTStringTemplateMap_NiTMap_char_const_IDLE_ANIM_ROOT_IDLE_ANIM_ROOT_NiTStringTemplateMap(int a, unsigned char b)
{
    ((FUN_006010d0_Class*)this)->InitializeWithGlobal(a);
    m_vft = &DAT_0104a070;
    m_field_10 = b;
    return this;
}

void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dest, int c, unsigned int count);
struct FUN_00601100_cls
{
    void* vtbl;
    int a;
    void* b;
    int c;
    FUN_00601100_cls* __thiscall NiTMapBase_DFALL_NiTMapItem_char_const_IDLE_ANIM_ROOT_char_const_IDLE_ANIM_ROOT_Init(int size);
};
// Sets the vtable, stores size, allocates size*4 bytes, zeroes them into b, and returns this.
// @fnv 0x00601100
// src: COMMUNITY 0x00601100
FUN_00601100_cls* __thiscall FUN_00601100_cls::NiTMapBase_DFALL_NiTMapItem_char_const_IDLE_ANIM_ROOT_char_const_IDLE_ANIM_ROOT_Init(int size)
{
    int n;
    vtbl = &DAT_0104a0b0;
    a = size;
    c = 0;
    n = a * 4;
    b = (void*)NiMalloc(n);
    memset(b, 0, a * 4);
    return this;
}

extern "C" void* __cdecl DAT_01199fc4[];

// @fnv 0x00605d40
// src: XBOX_PDB 0x00605d40
void* __cdecl TESRace_GetHeadPartNodeName(int index)
{
    return DAT_01199fc4[index];
}

int __cdecl CallWithFlag(int*);
// Computes a value from a and b via CallWithFlag and passes both results with c to FUN_0060be50.
// @fnv 0x0060bb70
// src: GUESS 0x0060bb70 (confidence: low)
void __cdecl Runtime_ProcessRangeWithCallFlags(int a, int b, float const* c)
{
    Runtime_ProcessEntries_0060be50(CallWithFlag(&a), CallWithFlag(&b), c);
}

namespace fnv_0060bc60 {
extern "C" void __cdecl Deallocate(void*);

struct FUN_006013a0_shell
{
    void SetVtableAndProcessState_0060b9b0();
    void* __thiscall FUN_0060bc60(int flags);
};

// Calls FUN_0060b9b0, frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0060bc60
void* __thiscall FUN_006013a0_shell::FUN_0060bc60(int flags)
{
    SetVtableAndProcessState_0060b9b0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_0060bc60

struct FUN_006013a0_shell
{
    void __thiscall ForwardCall_006013a0();
    FUN_006013a0_shell* __thiscall FUN_0060bc90(unsigned int flags);
};

// Calls FUN_006013a0, deletes this when flags has bit 1 set, and returns this.
// @fnv 0x0060bc90
FUN_006013a0_shell* __thiscall FUN_006013a0_shell::FUN_0060bc90(unsigned int flags)
{
    ForwardCall_006013a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct FUN_0060bcc0_holder
{
    void* __thiscall FUN_0060bcc0(unsigned int);
};
// Calls Reset on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0060bcc0
void* __thiscall FUN_0060bcc0_holder::FUN_0060bcc0(unsigned int flags)
{
    ((GlobalObject_00869f00*)this)->Reset();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_0060bcf0_class
{
    void __thiscall FUN_0060bae0();
    void* __thiscall FUN_0060bcf0(unsigned int flags);
};
// Calls FUN_0060bae0, then frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0060bcf0
void* __thiscall FUN_0060bcf0_class::FUN_0060bcf0(unsigned int flags)
{
    FUN_0060bae0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0060bd90_cls
{
    char _0[8];
    unsigned short m8;
    char _a[4];
    unsigned short mE;
    void __thiscall NiTObjectArray_NiPointer_NiTexture_SetAt(unsigned int, unsigned int);
    unsigned int __thiscall NiTObjectArray_NiPointer_NiTexture_SetAtGrow(unsigned int, unsigned int);
};
// Grows the array to mE + a when a is at least m8, then calls FUN_0060c120(a, b) and returns a.
// @fnv 0x0060bd90
// src: COMMUNITY 0x0060bd90
unsigned int __thiscall FUN_0060bd90_cls::NiTObjectArray_NiPointer_NiTexture_SetAtGrow(unsigned int uiIndex, unsigned int b)
{
    if (uiIndex >= m8)
    {
        ((NiTArray<int, NiTMallocInterface<int> >*)this)->SetSize((unsigned int)(mE + uiIndex));
    }
    NiTObjectArray_NiPointer_NiTexture_SetAt(uiIndex, b);
    return uiIndex;
}

extern "C" void* __cdecl FUN_00ec7ce3(void* dst, unsigned int dstSize, void* src, unsigned int srcSize);

// @fnv 0x0060c290
// src: GUESS 0x0060c290 (confidence: low)
void* __cdecl Runtime_UpdateState_0060c290(char* apSource, char* pDest, char* pEnd)
{
    int nCount = (pDest - apSource) >> 2;
    void* pResult4 = (void*)(pEnd - nCount * 4);
    if (nCount > 0)
        FUN_00ec7ce3(pResult4, nCount * 4, apSource, nCount * 4);
    return pResult4;
}

// Copies the float value pointed to by param_3 into param_2 consecutive floats starting at param_1.
// @fnv 0x0060c410
// src: GUESS 0x0060c410 (confidence: high)
void __cdecl Runtime_FillFloatRange(float* afDest, unsigned int auiCount, float* afValue)
{
    for (; auiCount > 0; auiCount--, afDest++)
    {
        *afDest = *afValue;
    }
}

void Deallocate(void*);
struct FUN_0060f410_class
{
    void* __thiscall FUN_0060f410(unsigned int flags);
    void __thiscall FUN_0060f5f0();
};
// Calls FUN_0060f5f0, then frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0060f410
void* __thiscall FUN_0060f410_class::FUN_0060f410(unsigned int flags)
{
    FUN_0060f5f0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct S_00616a60
{
    void __thiscall TESReputation_GetPositiveRatio();
    void __thiscall TESReputation_GetNegativeRatio();
    void __thiscall TESReputation_GetReputationPct(int);
};
// Calls FUN_00616a20 when a equals 1, otherwise calls FUN_00616a40.
// @fnv 0x00616a60
// src: COMMUNITY 0x00616a60
void __thiscall S_00616a60::TESReputation_GetReputationPct(int a)
{
    if (a == 1)
    {
        TESReputation_GetPositiveRatio();
        return;
        return;
    }
    TESReputation_GetNegativeRatio();
}

struct FUN_00618890_cls
{
    void __thiscall FUN_006188c0();
    FUN_00618890_cls* __thiscall FUN_00618890(unsigned int flags);
};
// Calls FUN_006188c0, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x00618890
FUN_00618890_cls* __thiscall FUN_00618890_cls::FUN_00618890(unsigned int flags)
{
    FUN_006188c0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __fastcall UpdateState_0061bcf0(void*);
void __cdecl operator delete(void*);
struct FUN_0061c090_class
{
    void* __thiscall FUN_0061c090(unsigned int flags);
};
// @fnv 0x0061c090
void* __thiscall FUN_0061c090_class::FUN_0061c090(unsigned int flags)
{
    UpdateState_0061bcf0(this);
    if (flags & 1)
        operator delete(this);
    return this;
}

void __fastcall Object_ForwardCall_00618940(void*);
void __cdecl operator delete(void*);
struct FUN_0061c0c0_class
{
    void* __thiscall FUN_0061c0c0(unsigned int flags);
};
// Calls FUN_00618940 on this, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0061c0c0
void* __thiscall FUN_0061c0c0_class::FUN_0061c0c0(unsigned int flags)
{
    Object_ForwardCall_00618940(this);
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0061bf50_class
{
    void __thiscall InitAndClear();
    void* __thiscall FUN_0061c0f0(unsigned int flags);
};

// Calls InitAndClear, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0061c0f0
void* __thiscall FUN_0061bf50_class::FUN_0061c0f0(unsigned int flags)
{
    InitAndClear();
    if (flags & 1)
        operator delete(this);
    return this;
}

// @fnv 0x0061f220
void __thiscall TESTopicInfo::MarkAsRefusal()
{
    if (!IsRefusal())
    {
        m_bGoodbye = 1;
        MarkAsModified(0x80000000);
    }
}

struct FUN_005545d0_Class
{
    void FUN_005545f0();
    void* FUN_0061f550(unsigned int flags);
};
// Calls FUN_005545f0, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x0061f550
void* __thiscall FUN_005545d0_Class::FUN_0061f550(unsigned int flags)
{
    FUN_005545f0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_0061fa40_class
{
    void __thiscall FUN_0061fae0();
    void* __thiscall FUN_0061fa40(unsigned int flags);
};

// Calls FUN_0061fae0, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0061fa40
void* __thiscall FUN_0061fa40_class::FUN_0061fa40(unsigned int flags)
{
    FUN_0061fae0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_0061fa70 {
extern "C" void* __cdecl NiMalloc(unsigned int size);
extern "C" void* __cdecl memset(void* dst, int c, unsigned int n);
struct FUN_0061fa70_class
{
    int __thiscall NiTMapBase_DFALL_NiTMapItem_TESObjectREFR_int_TESObjectREFR_int_NiTMapBase(int a);
};
// Sets the vtable, stores the count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x0061fa70
// src: EXE 0x0061fa70
int __thiscall FUN_0061fa70_class::NiTMapBase_DFALL_NiTMapItem_TESObjectREFR_int_TESObjectREFR_int_NiTMapBase(int aiCount)
{
    *reinterpret_cast<void**>(this) = &DAT_0104d968;
    reinterpret_cast<int*>(this)[1] = aiCount;
    reinterpret_cast<int*>(this)[3] = 0;
    unsigned int iAllocationSize = (unsigned int)reinterpret_cast<int*>(this)[1] << 2;
    reinterpret_cast<int*>(this)[2] = (int)NiMalloc(iAllocationSize);
    memset((void*)reinterpret_cast<int*>(this)[2], 0, (unsigned int)reinterpret_cast<int*>(this)[1] << 2);
    return (int)this;
}
}  // namespace fnv_0061fa70

void _Deallocate(void*);
struct FUN_0061fb70_Cls
{
    void* __thiscall FUN_0061fb70(unsigned int flags);
};
// @fnv 0x0061fb70
void* __thiscall FUN_0061fb70_Cls::FUN_0061fb70(unsigned int flags)
{
    ((NiTPointerMapIntInt*)this)->ReleaseStorage_0061fb40();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

class ActorCombatGroup;
struct FUN_00601000
{
    int* vft;
    ActorCombatGroup** p;
    unsigned short a;
    unsigned short c;
    unsigned short b;
    unsigned short d;
    FUN_00601000(short x, short y);
};
// Sets the vtable, stores x and y, zeroes c and b, and allocates a elements into p when a is positive, otherwise p is null.
// @fnv 0x00601000
FUN_00601000::FUN_00601000(short x, short y)
{
    vft = (int*)&DAT_0104a060;
    a = x;
    d = y;
    c = 0;
    b = 0;
    if (a > 0)
        p = NiTMallocInterface<ActorCombatGroup*>::Allocate(a);
    else
        p = 0;
}

namespace fnv_0060bd20 {
extern int DAT_0104aae0;
struct FUN_0060bd20_class
{
    int* m_vft;
    ActorCombatGroup** m_p;
    unsigned short m8;
    unsigned short m_kPointA;
    unsigned short m_iThirdValue;
    unsigned short m_usTrailingValue;
    FUN_0060bd20_class(unsigned short a, unsigned short b);
};
// @fnv 0x0060bd20
FUN_0060bd20_class::FUN_0060bd20_class(unsigned short a, unsigned short b)
{
    m_vft = &DAT_0104aae0;
    m8 = a;
    m_usTrailingValue = b;
    m_kPointA = 0;
    m_iThirdValue = 0;
    if (m8 > 0)
        m_p = NiTMallocInterface<ActorCombatGroup*>::Allocate(m8);
    else
        m_p = 0;
}
}  // namespace fnv_0060bd20

struct FUN_00616c20_cls
{
    void __thiscall AddReputationValue(int, float);
};
extern Setting originalRuntimeFloatSetting51;
extern Setting originalRuntimeFloatSetting50;
struct FUN_00616c20_shell : FUN_00616c20_cls
{
    void __thiscall TESReputation_CommitCrime(bool b);
};
// Reads one of two runtime float settings depending on b and passes it to FUN_00615730 with index 0.
// @fnv 0x00616c20
// src: XBOX_PDB 0x00616c20
void __thiscall FUN_00616c20_shell::TESReputation_CommitCrime(bool abUseFirstSetting)
{
    float f;
    if (abUseFirstSetting)
        f = *originalRuntimeFloatSetting51.Float();
    else
        f = *originalRuntimeFloatSetting50.Float();
    AddReputationValue(0, f);
}

struct FUN_00619a90_shell
{
    void ProcessTopicInfoList(int a);
};
struct BSSimpleListShell
{
    FUN_00619a90_shell** GetItem();
    BSSimpleListShell* GetNext();
    bool _ref_008256d0();
};
struct DH
{
    BSSimpleListShell* FUN_004612e0();
};
extern DH* g_dataHandler;
// If a is non-zero, walks the list from g_dataHandler and calls ProcessTopicInfoList(a) on each item until _ref_008256d0 is true.
// @fnv 0x00619b60
// src: COMMUNITY 0x00619b60
void TESTopic_ClearAllSaidOnceInfosForQuest(int a)
{
    if (a)
    {
        BSSimpleListShell* list = g_dataHandler->FUN_004612e0();
        while (list && !list->_ref_008256d0())
        {
            (*list->GetItem())->ProcessTopicInfoList(a);
            list = list->GetNext();
        }
    }
}

namespace fnv_0061c120 {
extern int DAT_0104d448;
struct FUN_0061c120
{
    void* vtbl;
    ActorCombatGroup** m_pData;
    unsigned int m_usSize;
    unsigned int m_usAllocSize;
    unsigned int m_uiMaxSize;
    unsigned int m_uiMax;
    FUN_0061c120(unsigned int size, unsigned int max);
};
// Initialises the array: sets the vtable, stores size and max, zeroes allocation fields, and allocates m_pData when size is non-zero.
// @fnv 0x0061c120
FUN_0061c120::FUN_0061c120(unsigned int size, unsigned int max)
{
    vtbl = (void*)&DAT_0104d448;
    m_usSize = size;
    m_uiMax = max;
    m_usAllocSize = 0;
    m_uiMaxSize = 0;
    if (m_usSize > 0)
        m_pData = NiTMallocInterface<ActorCombatGroup*>::Allocate(m_usSize);
    else
        m_pData = 0;
}
}  // namespace fnv_0061c120

void* __cdecl FUN_00ec7ce3(void* dst, unsigned int dstSize, void* src, unsigned int srcSize);

// Computes the element count between param_1 and param_2, copies that many 4-byte elements from param_1 to param_3, and returns the end pointer in param_3.
// @fnv 0x0060c3c0
// src: GUESS 0x0060c3c0 (confidence: low)
void* __cdecl Object_ProcessAndReturnValue_0060c3c0(void* pBegin, void* pEnd, void* pDest)
{
    unsigned int count = ((char*)pEnd - (char*)pBegin) >> 2;
    void* result = (char*)pDest + count * 4;
    if (count > 0)
    {
        FUN_00ec7ce3(pDest, count << 2, pBegin, count << 2);
    }
    return result;
}

struct GlobalObject_0040c150 : public StartMenu
{
    bool __thiscall GetReputationRank(int value);
    char const* TESReputation_GetThresholdIcon();
};

extern GlobalObject_0040c150 g_011cba18;
extern GlobalObject_0040c150 g_011cba4c;
extern GlobalObject_0040c150 g_011cba64;
extern GlobalObject_0040c150 g_011cbaa0;
extern GlobalObject_0040c150 g_011cbab0;
extern GlobalObject_0040c150 g_011cbbaec;
extern GlobalObject_0040c150 g_011cbb40;
extern GlobalObject_0040c150 g_011cbb4c;
extern GlobalObject_0040c150 g_011cbb80;
extern GlobalObject_0040c150 g_011cbb8c;
extern GlobalObject_0040c150 g_011cbbcc;
extern GlobalObject_0040c150 g_011cbbfc;
extern GlobalObject_0040c150 g_011cbcf0;
extern GlobalObject_0040c150 g_011cbd08;
extern GlobalObject_0040c150 g_011cbd38;
extern GlobalObject_0040c150 g_011cbd44;

// @fnv 0x006167d0
// src: COMMUNITY 0x006167d0
char const* GlobalObject_0040c150::TESReputation_GetThresholdIcon()
{
    const StartMenu* menuTable[4][4] = {{&g_011cbbfc, &g_011cbbcc, &g_011cbbaec, &g_011cbd44},
                                  {&g_011cbcf0, &g_011cba4c, &g_011cbb4c, &g_011cbb8c},
                                  {&g_011cbb80, &g_011cba18, &g_011cbab0, &g_011cbd08},
                                  {&g_011cbb40, &g_011cbaa0, &g_011cba64, &g_011cbd38}};

    char row = 0;
    char column = 0;
    row = this->GetReputationRank(1);
    column = this->GetReputationRank(0);
    return menuTable[column][row]->GetMenuTitle();
}

extern int DAT_0104d9cc[];
struct FUN_0061fea0_shell
{
    void ClearList();
};
struct FUN_0061fc50 : FUN_0061fea0_shell
{
    virtual ~FUN_0061fc50();
};
// @fnv 0x0061fc50
FUN_0061fc50::~FUN_0061fc50()
{
    reinterpret_cast<FUN_0061fea0_shell*>(this)->ClearList();
}

class FNVNode;
class FNVHeap;

FNVHeap* MemoryManager_Instance();

class FNVHeap
{
  public:
    FNVNode* FUN_00aa42e0();
};

class FNVBaseObj
{
  public:
    virtual ~FNVBaseObj();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FNVBaseObj();
};

class FUN_0060ba40_cls : public FNVBaseObj
{
  public:
    virtual ~FUN_0060ba40_cls();
    FNVNode* m_10;
    FUN_0060ba40_cls();
    void BSSimpleArray_float_1024_InitialSetup(unsigned int a, unsigned int b);
};

// Initializes m_10 from FUN_00401020()->FUN_00aa42e0() and calls FUN_006b3eb0 with 0, 0.
// @fnv 0x0060ba40
FUN_0060ba40_cls::FUN_0060ba40_cls()
{
    m_10 = MemoryManager_Instance()->FUN_00aa42e0();
    BSSimpleArray_float_1024_InitialSetup(0, 0);
}

class FUN_0060bac0_base
{
  public:
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    ~FUN_0060bac0_base();
};

class FUN_0060bae0_cls : public FUN_0060bac0_base
{
  public:
    virtual void unk00();
    void Clear(int flag);
    ~FUN_0060bae0_cls();
};

// @fnv 0x0060bae0
FUN_0060bae0_cls::~FUN_0060bae0_cls()
{
    Clear(1);
}

struct S_0060bba0_TagBase
{
};
struct S_0060bba0_TagA : S_0060bba0_TagBase
{
};
struct S_0060bba0_TagB
{
};
struct S_0060bba0_TagC
{
};
S_0060bba0_TagB std_Move_cat_unsigned_char(int*);
S_0060bba0_TagA return_value(int*, int*);
int CallWithFlag(int*);
void CallWithFlagByte(int, int, int, S_0060bba0_TagA, S_0060bba0_TagB, S_0060bba0_TagC);

// Calls CallWithFlagByte with CallWithFlag results for param1 and param2, param3, and FUN_0065fd70/FUN_0065e750 results plus a TagC.
// @fnv 0x0060bba0
// src: GUESS 0x0060bba0 (confidence: low)
void __cdecl Object_DispatchIteratorRange_0060bba0(int param1, int param2, int param3)
{
    CallWithFlagByte(CallWithFlag(&param1), CallWithFlag(&param2), param3, return_value(&param1, &param3),
                     std_Move_cat_unsigned_char(&param3), S_0060bba0_TagC());
}

struct B60BC10PtrCatTag
{
};

struct B60BC10RangeCheckedTag
{
};

B60BC10PtrCatTag __cdecl B60BC10PtrCat(void*& first, void*& dest);
void __cdecl B60BC10FillOpt(void* first, void* last, void* value, void* extra, B60BC10PtrCatTag ptrCat,
                            B60BC10RangeCheckedTag checked);

// Calls B60BC10FillOpt with first, last, value and extra, passing a pointer-category tag built from first and a range-checked tag.
// @fnv 0x0060bc10
void __cdecl FillRange(void* first, void* last, void* value, void* extra)
{
    B60BC10FillOpt(first, last, value, extra, B60BC10PtrCat(first, first), B60BC10RangeCheckedTag());
}

struct C60BE00CheckedTag
{
};

struct C60BE00PtrCategory
{
};

struct C60BE00Element;
struct C60BE00Allocator;

C60BE00PtrCategory C60BE00PtrCat(C60BE00Element** ppDest);
C60BE00Element* C60BE00Unchecked(C60BE00Element** ppIter);
void C60BE00UninitCopy(C60BE00Element* pFirst, C60BE00Element* pLast, C60BE00Element* pDest, C60BE00Allocator* pAlloc,
                       C60BE00PtrCategory category, C60BE00CheckedTag tag);

// std::uninitialized_copy
// Copies the element range [_First, _Last) to _Dest using _Al, passing the destination pointer category and a checked tag to C60BE00UninitCopy.
// @fnv 0x0060be00
// src: GUESS 0x0060be00 (confidence: low)
void Object_ProcessState_0060be00(C60BE00Element* _First, C60BE00Element* _Last, C60BE00Element* _Dest, C60BE00Allocator* _Al)
{
    C60BE00UninitCopy(C60BE00Unchecked(&_First), C60BE00Unchecked(&_Last), _Dest, _Al, C60BE00PtrCat(&_Dest),
                      C60BE00CheckedTag());
}

// A one-byte class.  Under /Od an empty brace initialiser zero-initialises the
// object in place, which is the "xor eax,eax" + byte store the original shows.
struct FNV_Flag1
{
    unsigned char m_kPointB;
};

// Stand-ins for the two game callees.  The names are not canonical symbols, so
// the checker binds the call targets from the original's own bytes.
extern "C" unsigned char __cdecl FUN_0065e750_standin(void* a, void* b);
extern "C" void __cdecl FUN_0060c290_standin(void* a, void* b, void* c, unsigned char d, unsigned char e,
                                             unsigned char f);

// Calls FUN_0065e750_standin with &p1 and &p3, then passes p1, p2, p3, p4, the returned byte and a zero flag byte to FUN_0060c290_standin.
// @fnv 0x0060be80
void CallWithFlagByte(void* p1, void* apArg2, void* apArg3, unsigned char p4)
{
    unsigned char ucResult;
    FNV_Flag1 RunFourthVirtual = {};
    ucResult = FUN_0065e750_standin(&p1, &apArg3);
    FUN_0060c290_standin(p1, apArg2, apArg3, p4, ucResult, RunFourthVirtual.m_kPointB);
}

struct S_0060c2e0_Flag
{
    unsigned char v;
};

struct S_0060c2e0_Ret
{
    unsigned char v;
    S_0060c2e0_Ret(int);
};

extern "C" S_0060c2e0_Ret __cdecl return_value(void* value);
extern "C" void __cdecl ProcessFloatRange(void* a, void* b, void* c, int d, int e);

// Calls ProcessFloatRange with a1, a2, a3 plus the byte returned by FUN_0065fd70(&a1) and a zero flag byte.
// @fnv 0x0060c2e0
void __cdecl CallWithFlagValues(void* a1, void* a2, void* a3)
{
    ProcessFloatRange(a1, a2, a3, return_value(&a1).v, S_0060c2e0_Flag().v);
}

class B616A20Meter
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    float m_fMaximum;
    float m_fCurrent;

    float TESReputation_GetPositiveRatio();
};

// @fnv 0x00616a20
// src: XBOX_PDB 0x00616a20
float B616A20Meter::TESReputation_GetPositiveRatio()
{
    return m_fCurrent / m_fMaximum;
}

// variant A: direct member expression
struct FUN_00616a40_cls
{
    unsigned int m_i00;
    unsigned int m_i04;
    unsigned int m_i08;
    unsigned int m_i0C;
    unsigned int m_i10;
    unsigned int m_i14;
    unsigned int m_i18;
    unsigned int m_i1C;
    unsigned int m_i20;
    unsigned int m_i24;
    unsigned int m_i28;
    unsigned int m_i2C;
    unsigned int m_i30;
    unsigned int m_i34;
    unsigned int m_i38;
    unsigned int m_i3C;
    float m_f40;
    float m_f44;
    float m_f48;
    float __thiscall TESReputation_GetNegativeRatio();
};

// @fnv 0x00616a40
// src: XBOX_PDB 0x00616a40
float __thiscall FUN_00616a40_cls::TESReputation_GetNegativeRatio()
{
    return m_f48 / m_f40;
}

struct Comparison
{
    char __thiscall GetReputationRank(int);
    char __thiscall TESReputation_GetReputationThreshold(char mode);
};
// Reads two comparison results and maps their combination, depending on mode, to a result code (0-6).
// @fnv 0x00616a90
// src: COMMUNITY 0x00616a90
char Comparison::TESReputation_GetReputationThreshold(char mode)
{
    char second = GetReputationRank(1);
    char first = GetReputationRank(0);
    if (second == 0 && first == 0)
        return 1;
    if (mode == 0)
    {
        if (second == 1 && first == 1)
            return 3;
        if (second == 3)
        {
            if (first == 2)
                return 2;
            if (first == 3)
                return 5;
        }
        if (second == 2)
        {
            if (first == 3)
                return 2;
            else if (first == 2)
                return 4;
        }
    }
    else if (mode == 1)
    {
        if (second == 1 && first == 0)
            return 4;
        if (second == 2)
        {
            if (first == 0)
                return 5;
            if (first == 1)
                return 2;
        }
        if (second == 3)
        {
            if (first == 0)
                return 6;
            else if (first == 1)
                return 3;
        }
    }
    else if (mode == 2)
    {
        if (first == 1 && second == 0)
            return 4;
        if (first == 2)
        {
            if (second == 0)
                return 5;
            if (second == 1)
                return 2;
        }
        if (first == 3)
        {
            if (second == 0)
                return 6;
            else if (second == 1)
                return 3;
        }
    }
    return 0;
}

extern "C" void __cdecl BSEndian_00401080(void* p, bool flag);

struct FUN_00616c70_flag
{
    bool m_bValue;
};

struct FUN_00616c70_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void InitializeFields();
};

// Initializes the four fields at offsets 0, 4, 8 and 0x10 by calling FUN_00401080 on each with a default flag value.
// @fnv 0x00616c70
void FUN_00616c70_cls::InitializeFields()
{
    FUN_00616c70_flag a = {};
    BSEndian_00401080(this, a.m_bValue);
    FUN_00616c70_flag b = {};
    BSEndian_00401080((char*)this + 4, b.m_bValue);
    FUN_00616c70_flag c5 = {};
    BSEndian_00401080((char*)this + 8, c5.m_bValue);
    FUN_00616c70_flag d = {};
    BSEndian_00401080((char*)this + 0x10, d.m_bValue);
}

int __cdecl FUN_00406d50(char* destination, unsigned int capacity, const char* source);
extern const char DAT_01013444[];
extern const char DAT_01044c28[];

struct OutputStringDC
{
    void FUN_00438390(const char* text);
};

struct FUN_00616e20_shell
{
    bool TESResponse_TestAudioFullPath(OutputStringDC* output, const char* first, const char* second, const char* third,
                      const char* fourth, const char* fifth);
};

// @fnv 0x00616e20
// src: COMMUNITY 0x00616e20
bool FUN_00616e20_shell::TESResponse_TestAudioFullPath(OutputStringDC* output, const char* pcFirst, const char* pcSecond,
                                      const char* pcThird, const char* pcFourth, const char* pcFifth)
{
    bool succeeded2;
    char buffer[260];
    char* destination = buffer;
    destination[0] = 0;
    FUN_00406d50(destination, 260, pcFirst);
    FUN_00406d50(destination, 260, DAT_01013444);
    FUN_00406d50(destination, 260, pcSecond);
    FUN_00406d50(destination, 260, DAT_01013444);
    FUN_00406d50(destination, 260, pcThird);
    FUN_00406d50(destination, 260, DAT_01013444);
    FUN_00406d50(destination, 260, pcFourth);
    FUN_00406d50(destination, 260, DAT_01044c28);
    FUN_00406d50(destination, 260, pcFifth);
    succeeded2 = true;
    output->FUN_00438390(buffer);
    return succeeded2;
}

struct KeyObj
{
    unsigned int GetKey();
};

struct Entry
{
    KeyObj* key;
};

struct EntryListNode
{
    Entry** Item();
    EntryListNode* Next();
    void SetItem(Entry* const& item);
    int GetSize();
};

struct SortOwner
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    EntryListNode* GetList();
    bool SortList();
};

// Bubble-sorts the linked list by comparing each entry's key and swapping adjacent items when the next key is greater, then returns true.
// @fnv 0x0061ba90
bool SortOwner::SortList()
{
    V34();
    int count = GetList()->GetSize();
    for (int i = 0; i < count - 1; i++)
    {
        EntryListNode* nodeB = GetList();
        while (nodeB && *nodeB->Item())
        {
            if (nodeB->Next())
            {
                Entry* first4 = *nodeB->Item();
                Entry* second3 = *nodeB->Next()->Item();
                if (first4 && second3)
                {
                    int firstKey = first4->key ? first4->key->GetKey() : -1;
                    int kSecondKey = second3->key ? second3->key->GetKey() : -1;
                    if (kSecondKey > firstKey)
                    {
                        nodeB->SetItem(second3);
                        nodeB->Next()->SetItem(first4);
                    }
                }
            }
            nodeB = nodeB->Next();
        }
    }
    return true;
}

class ThisBase_b5727
{
  public:
    virtual ~ThisBase_b5727();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    ThisBase_b5727(int aValue);
};

class ThisMember_b5727
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ThisMember_b5727(int aValue);
    ~ThisMember_b5727();
};

class FUN_0061f460 : public ThisBase_b5727
{
  public:
    virtual ~FUN_0061f460();
    unsigned char m_14;
    ThisMember_b5727 m_18;

    FUN_0061f460();
};

// Initializes the base with 0, sets m_14 to 1 and constructs m_18 with 0x25.
// @fnv 0x0061f460
FUN_0061f460::FUN_0061f460() : ThisBase_b5727(0), m_18(0x25)
{
    m_14 = 1;
}

class F4D0Base
{
  public:
    F4D0Base();
    virtual ~F4D0Base();
};

struct F4D0List
{
    F4D0List();

    int unk00;
    int unk04;
};

class FUN_0061f4d0 : public F4D0Base
{
  public:
    FUN_0061f4d0(void* pkOwner);
    virtual ~FUN_0061f4d0();

    void* m_pkOwnerManager;
    bool m_bEnableState;
    F4D0List m_kList;
};

// @fnv 0x0061f4d0
FUN_0061f4d0::FUN_0061f4d0(void* pkOwner)
{
    m_pkOwnerManager = pkOwner;
    m_bEnableState = true;
}

struct RangeCheckedTag60C
{
};

struct ScalarPtrTag60C
{
};

typedef int* Iter60C;
typedef int Alloc60C;

ScalarPtrTag60C __cdecl PtrCat60C(Iter60C& kFirst, Iter60C& kDest);
Iter60C __cdecl CheckedBase60C(Iter60C& kIter);
void __cdecl UninitCopy60C(Iter60C pFirst, Iter60C pLast, Iter60C pDest, Alloc60C kAlloc, ScalarPtrTag60C kPtrCat,
                           RangeCheckedTag60C kTag);

// Copies elements from the checked range [kFirst, kLast) into kDest using UninitCopy60C with a PtrCat60C tag.
// @fnv 0x0060c320
void __cdecl UninitCopyChecked(Iter60C kFirst, Iter60C kLast, Iter60C kDest, Alloc60C kAlloc)
{
    UninitCopy60C(CheckedBase60C(kFirst), CheckedBase60C(kLast), kDest, kAlloc, PtrCat60C(kFirst, kDest),
                  RangeCheckedTag60C());
}

// Range helper: compute the range end, then forward the unwrapped start, count and output with an empty tag.

struct C380Tag
{
};

float* C380Unwrap(float** ppfFirst);
void C380Process(float* pfFirst, unsigned int ItemUpdateArray, float* pfOut, C380Tag kTag);

// @fnv 0x0060c380
void ProcessFloatRange(float* pfFirst, unsigned int ItemUpdateArray, float* pfOut)
{
    float* pfLast = pfFirst + ItemUpdateArray;
    C380Process(C380Unwrap(&pfFirst), ItemUpdateArray, pfOut, C380Tag());
}

// Find the list entry that resolves to the given form and return its key (0 when none).

class F1A0Form
{
  public:
    bool IsReference();
};

class F1A0Entry
{
  public:
    F1A0Form* GetForm(bool bReference);
    unsigned char GetKey();
};

class F1A0Node
{
  public:
    bool IsEmpty();
    F1A0Entry** GetItem();
    F1A0Node* GetNext();
};

class F1A0Owner
{
  public:
    F1A0Node* GetList();
    unsigned char GetKeyForForm(F1A0Form* pkForm);
};

// Walks the owner's list and returns the key of the entry whose form matches pkForm, or 0 if none matches.
// @fnv 0x0060f1a0
unsigned char F1A0Owner::GetKeyForForm(F1A0Form* pkForm)
{
    F1A0Node* pkNode = GetList();
    while (pkNode && !pkNode->IsEmpty())
    {
        F1A0Entry* pkEntry = *pkNode->GetItem();
        if (pkForm == pkEntry->GetForm(pkForm->IsReference()))
            return pkEntry->GetKey();
        pkNode = pkNode->GetNext();
    }
    return 0;
}

class B616890Setting
{
  public:
    const char* String();
};

extern B616890Setting g_k616890A0;
extern B616890Setting g_k616890A1;
extern B616890Setting g_k616890A2;
extern B616890Setting g_k616890A3;
extern B616890Setting g_k616890B0;
extern B616890Setting g_k616890B1;
extern B616890Setting g_k616890B2;
extern B616890Setting g_k616890B3;
extern B616890Setting g_k616890C0;
extern B616890Setting g_k616890C1;
extern B616890Setting g_k616890C2;
extern B616890Setting g_k616890C3;
extern B616890Setting g_k616890D0;
extern B616890Setting g_k616890D1;
extern B616890Setting g_k616890D2;
extern B616890Setting g_k616890D3;

class B616890Menu
{
  public:
    char GetIndex(bool bFirst);
    const char* GetSelectedSettingString();
};

// Reads the selected row and column via GetIndex, then returns the String() of the matching entry in the 4x4 settings table.
// @fnv 0x00616890
const char* B616890Menu::GetSelectedSettingString()
{
    B616890Setting* aapkSettings3[4][4] = {{&g_k616890A0, &g_k616890A1, &g_k616890A2, &g_k616890A3},
                                           {&g_k616890B0, &g_k616890B1, &g_k616890B2, &g_k616890B3},
                                           {&g_k616890C0, &g_k616890C1, &g_k616890C2, &g_k616890C3},
                                           {&g_k616890D0, &g_k616890D1, &g_k616890D2, &g_k616890D3}};
    char cColumn = 0;
    char cRow3 = 0;
    cColumn = GetIndex(true);
    cRow3 = GetIndex(false);
    return aapkSettings3[cRow3][cColumn]->String();
}

struct CleanupItem
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual ~CleanupItem();
    void FUN_0061f340(unsigned int);
};
struct CleanupArray
{
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void FUN_0061bd20(unsigned int, CleanupItem* const&);
};
struct CleanupTopic
{
    ~CleanupTopic();
    CleanupArray* FUN_00717e50();
};
struct CleanupList
{
    CleanupTopic** FUN_006815c0();
    void FUN_0063f7b0();
};
CleanupItem* GetTopicInfoByIndex(CleanupTopic*, unsigned int);
struct CleanupBase
{
    virtual ~CleanupBase();
    unsigned int field04, field08, field0c, field10, field14;
    CleanupList* FUN_005d8a70();
    void FUN_00483710();
};
struct CleanupSecondary
{
    virtual ~CleanupSecondary();
    unsigned int field04, field08, field0c, field10;
};
struct CleanupMember8
{
    unsigned int field00, field04;
    ~CleanupMember8();
};
struct CleanupMember12
{
    unsigned int field00, field04, field08;
    ~CleanupMember12();
};
struct FUN_006186d0 : CleanupBase, CleanupSecondary
{
    CleanupMember8 field2c;
    CleanupMember12 field34;
    CleanupMember12 field40;
    virtual ~FUN_006186d0();
};
// Walks the cleanup list, deletes each topic's items and the topic itself, then calls FUN_00483710.
// @fnv 0x006186d0
FUN_006186d0::~FUN_006186d0()
{
    CleanupList* list = FUN_005d8a70();
    while (list && *list->FUN_006815c0())
    {
        CleanupTopic* topic = *list->FUN_006815c0();
        unsigned int count = topic->FUN_00717e50()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        for (unsigned int i = 0; i < count; ++i)
        {
            CleanupItem* item = GetTopicInfoByIndex(topic, i);
            if (item)
            {
                CleanupItem* pNullItem = 0;
                topic->FUN_00717e50()->FUN_0061bd20(i, pNullItem);
                item->FUN_0061f340(0xffff);
                delete item;
            }
        }
        delete topic;
        topic = 0;
        list->FUN_0063f7b0();
    }
    FUN_00483710();
}

struct VFString
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;

    VFString();
    ~VFString();
    operator const char*() const;
};

struct VFVoiceType
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual const char* GetEditorID();
};

struct VFBaseData
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual VFVoiceType* GetVoiceType();
};

struct VFForm
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    VFBaseData kBaseData;

    int GetFormType();
    VFVoiceType* GetTalkingActivatorVoice();
};

struct VFFile
{
    const char* GetFilename();
};

struct VFTopicInfo
{
    VFFile* GetFile(int aiIndex);
    VFForm* GetSpeaker();
};

struct VFVoiceOwner
{
    VFVoiceType* GetVoiceType(int aiUnk);
};

struct VFSetting
{
    const char* GetString();
};

VFVoiceOwner* __cdecl VFGetVoiceOwner(VFForm* apForm);

extern VFSetting g_kVoiceExtension;

struct VFDialogue
{
    void BuildResponseName(void* apTopic, void* apQuest, VFTopicInfo* apInfo, VFString* apName);
    bool BuildPath(char* apBuffer, const char* apPrefix, const char* apPlugin, const char* apVoice, const char* apName,
                   const char* apExtension);
    bool BuildVoiceFilePath(VFForm* apSpeaker, void* apTopic, void* apQuest, VFTopicInfo* apInfo, char* apBuffer);
};

// @fnv 0x00616fa0
bool VFDialogue::BuildVoiceFilePath(VFForm* apSpeaker, void* apTopic, void* apQuest, VFTopicInfo* apInfo,
                                    char* apBuffer)
{
    VFString kUnused;
    VFString kName2;
    BuildResponseName(apTopic, apQuest, apInfo, &kName2);
    VFVoiceType* pVoice4 = 0;
    VFFile* pFile = apInfo->GetFile(0);
    if (!pFile)
        return false;

    const char* pPlugin = 0;
    if (apInfo && apInfo->GetSpeaker())
        pVoice4 = apInfo->GetSpeaker()->kBaseData.GetVoiceType();
    if (!pVoice4)
    {
        if (apSpeaker->GetFormType() == 0x2a)
            pVoice4 = apSpeaker->kBaseData.GetVoiceType();
        else if (apSpeaker->GetFormType() == 0x2b)
            pVoice4 = apSpeaker->kBaseData.GetVoiceType();
        else if (apSpeaker->GetFormType() == 0x16)
            pVoice4 = apSpeaker->GetTalkingActivatorVoice();
        else
        {
            VFVoiceOwner* pOwner4 = VFGetVoiceOwner(apSpeaker);
            if (!pOwner4)
                return false;
            pVoice4 = pOwner4->GetVoiceType(0);
        }
    }
    if (!pVoice4)
        return false;

    const char* pVoiceName2 = pVoice4->GetEditorID();
    if (!pVoiceName2)
        return false;

    const char* pPrefix5 = "Data\\Sound\\Voice";
    if (pFile)
    {
        pPlugin = pFile->GetFilename();
        if (!pPlugin)
            return false;
    }
    const char* pExtension_ = g_kVoiceExtension.GetString();
    bool bResult = BuildPath(apBuffer, pPrefix5, pPlugin, pVoiceName2, kName2, pExtension_);
    if (bResult)
        return true;
    return true;
}

struct CopyMap
{
    void SetAt(unsigned int, unsigned int);
};
struct FUN_0061f870_shell
{
    char _0[0x18];
    void SetCopyMapEntry(unsigned int a);
};
// @fnv 0x0061f870
void FUN_0061f870_shell::SetCopyMapEntry(unsigned int uiKey)
{
    ((CopyMap*)((char*)this + 0x18))->SetAt(uiKey, 5);
}

struct AHPtrMapBase
{
    virtual ~AHPtrMapBase();
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
struct FUN_0061fae0 : public AHPtrMapBase
{
    virtual ~FUN_0061fae0();
    void RemoveAll();
};
// Destructor that calls RemoveAll to clear the hash table entries.
// @fnv 0x0061fae0
FUN_0061fae0::~FUN_0061fae0()
{
    RemoveAll();
}

extern "C" int __cdecl tolower(int);

class StringHashTable
{
  public:
    int unk00;
    unsigned int m_uiBuckets;

    unsigned int NiTStringTemplateMap_NiTMap_char_const_TESForm_TESForm_HashChar(unsigned char ucChar, unsigned int uiHash);
    unsigned int HashKey(const char* pcKey);
};

// Computes a hash of pcKey by folding lowercased characters through FUN_00659210 and returns the result modulo m_uiBuckets.
// @fnv 0x00600b20
unsigned int StringHashTable::HashKey(const char* pcKey)
{
    unsigned int uiHash = 0;
    if (1)
    {
    }
    if (1)
    {
    }
    while (*pcKey)
        uiHash = NiTStringTemplateMap_NiTMap_char_const_TESForm_TESForm_HashChar((unsigned char)tolower(*pcKey++), uiHash);
    return uiHash % m_uiBuckets;
}

struct FUN_00600d40 : FUN_00600b00_shell
{
    virtual ~FUN_00600d40();
};
// @fnv 0x00600d40
FUN_00600d40::~FUN_00600d40()
{}

struct FUN_00600d90_node
{
    FUN_00600d90_node* next;
    void* value;
};

void __cdecl _NiFree_00aa10f0(void* value);

struct FUN_00600e50
{
    virtual ~FUN_00600e50();
    unsigned int bucketCount;
    FUN_00600d90_node** buckets;
    unsigned int reserved;
    unsigned char ownsValues;
};

struct FUN_00600d90 : FUN_00600e50
{
    virtual ~FUN_00600d90();
};

// If ownsValues is set, walks every bucket's node list and calls FUN_00aa10f0 on each node's value.
// @fnv 0x00600d90
FUN_00600d90::~FUN_00600d90()
{
    if (ownsValues)
    {
        for (unsigned int i = 0; i < bucketCount; ++i)
        {
            FUN_00600d90_node* node = buckets[i];
            while (node != 0)
            {
                FUN_00600d90_node* current = node;
                node = node->next;
                _NiFree_00aa10f0(current->value);
            }
        }
    }
}

struct FUN_00600eb0_base
{
    virtual ~FUN_00600eb0_base();
};

struct FUN_00600e50_cls : public FUN_00600eb0_base
{
    void FUN_00438af0();
    virtual ~FUN_00600e50_cls();
};

// Destructor that calls FUN_00438af0.
// @fnv 0x00600e50
FUN_00600e50_cls::~FUN_00600e50_cls()
{
    FUN_00438af0();
}

// Destructor with an empty body; the base array is destroyed implicitly.
// @fnv 0x006197f0
TopicInfoArray::~TopicInfoArray()
{}

struct Path618
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ~Path618();
};

struct Queue618
{
    int unk00;
    int unk04;
    ~Queue618();
};

struct FUN_006188c0
{
    int m_iId;
    Path618 m_kPath;
    Queue618 m_kQueue;
    ~FUN_006188c0();
};

// Destructor with an empty body; members m_kPath and m_kQueue are destroyed implicitly.
// @fnv 0x006188c0
FUN_006188c0::~FUN_006188c0()
{}



// Casts the form to TESRaceForm and returns its race via GetFormRace, or null if the cast fails.
// @fnv 0x00617270
// src: COMMUNITY 0x00617270
TESRace* __cdecl TESRaceForm_GetFormRace(TESForm* form)
{
    TESRaceForm* pRaceForm;
    pRaceForm = dynamic_cast<TESRaceForm*>(form);
    {
        TESRace* result;
        if (pRaceForm)
            result = pRaceForm->GetFormRace();
        else
            result = 0;
        return result;
    }
}
