#include "../../include/BSStringT.h"

// src/staging/blk_00580000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <stddef.h>
#include "../../include/Mat3.h"
#include "../../include/SL.h"
#include "../../include/TESModel.h"
#include "../../include/TESWeatherList.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/TESSoundFile.h"
#include "../../include/TESSound.h"
#include "../../include/TESFile.h"
#include "../../include/NiFormArray.h"
#include "../../include/NiTLargeArray.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NP.h"
#include "../../include/BSAudio.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/PerkEntryConditionSet.h"
#include "../../include/StrMem.h"
#include "../../include/TES.h"

struct FUN_004fc990_t
{
    void __thiscall BGSPlaceableWater_SetFlag(int, bool);
};

struct FUN_00580310_t
{
    void __thiscall SetFlag400(bool b);
};

// @fnv 0x00580310
void __thiscall FUN_00580310_t::SetFlag400(bool abEnabled)
{
    ((FUN_004fc990_t*)this)->BGSPlaceableWater_SetFlag(0x400, abEnabled);
}

namespace fnv_00580540 {
struct FUN_004fc990_t
{
    void BGSPlaceableWater_SetFlag(int, bool);
};

struct FUN_00580540_t
{
    void SetValue(int value);
};

// @fnv 0x00580540
void FUN_00580540_t::SetValue(int value)
{
    reinterpret_cast<FUN_004fc990_t*>(this)->BGSPlaceableWater_SetFlag(2, reinterpret_cast<bool&>(value));
}
}  // namespace fnv_00580540

namespace fnv_00580560 {
struct FUN_004fc990_t
{
    void BGSPlaceableWater_SetFlag(int, bool);
    void SetFlag80(bool argument0);
};

// @fnv 0x00580560
void FUN_004fc990_t::SetFlag80(bool abEnabled)
{
    BGSPlaceableWater_SetFlag(0x80, abEnabled);
}
}  // namespace fnv_00580560

namespace fnv_00580580 {
struct FUN_004fc990_t
{
    void BGSPlaceableWater_SetFlag(int, bool);
};
struct FUN_00580580_t
{
    void SetFlag100(bool a);
};
// @fnv 0x00580580
void FUN_00580580_t::SetFlag100(bool abEnabled)
{
    ((FUN_004fc990_t*)this)->BGSPlaceableWater_SetFlag(0x100, abEnabled);
}
}  // namespace fnv_00580580

namespace fnv_005805a0 {
struct FUN_004fc990_t
{
    void BGSPlaceableWater_SetFlag(int, bool);
};

struct FUN_005805a0_t
{
    void SetFlag8000000(bool argument0);
};

// @fnv 0x005805a0
void FUN_005805a0_t::SetFlag8000000(bool abEnabled)
{
    ((FUN_004fc990_t*)this)->BGSPlaceableWater_SetFlag(0x8000000, abEnabled);
}
}  // namespace fnv_005805a0

struct FUN_00581fb0_Class
{
    void __thiscall TESImageSpaceModifiableCountForm_6_SetFormImageSpaceModifying(int index, int value);
};

// @fnv 0x00581fb0
// src: XBOX_PDB 0x00581fb0
void __thiscall FUN_00581fb0_Class::TESImageSpaceModifiableCountForm_6_SetFormImageSpaceModifying(int index, int value)
{
    *(int*)((char*)this + index * 4 + 4) = value;
}

struct FUN_005822a0_cls
{
    int __thiscall TESImageSpaceModifiableCountForm_6_GetFormImageSpaceModifying(int index);
};

// @fnv 0x005822a0
// src: XBOX_PDB 0x005822a0
int __thiscall FUN_005822a0_cls::TESImageSpaceModifiableCountForm_6_GetFormImageSpaceModifying(int index)
{
    return *(int*)((char*)this + index * 4 + 4);
}

extern int DAT_01031fcc;
struct FUN_00588fd0Class
{
    void FUN_005891c0(int);
    int* NiTMap_TESFile_TESWorldSpace_OFFSET_DATA_NiTMap(int a);
};
// Calls FUN_005891c0 with a, stores the address of DAT_01031fcc into this, and returns this.
// @fnv 0x00588fd0
// src: EXE 0x00588fd0
int* FUN_00588fd0Class::NiTMap_TESFile_TESWorldSpace_OFFSET_DATA_NiTMap(int a)
{
    FUN_005891c0(a);
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_01031fcc);
    return reinterpret_cast<int*>(this);
}

struct FUN_0058bc00_obj
{
    void __fastcall Object_ReleaseStorage();
};

// @fnv 0x0058b830
// src: GUESS 0x0058b830 (confidence: low)
void __fastcall Runtime_ForwardCall_0058b830(FUN_0058bc00_obj* this_ptr)
{
    this_ptr->Object_ReleaseStorage();
}

struct FUN_0058cac0_Class
{
    unsigned int* pFlags;
    bool IsFlag20Set() const;
};

// @fnv 0x0058cac0
bool FUN_0058cac0_Class::IsFlag20Set() const
{
    return (*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0x44) & 0x20) ? true : false;
}

struct FUN_00573eb0_Class
{
    int NiPathInterpolator_GetBit(int);
    int NiPathInterpolator_GetFollow();
};

// @fnv 0x0058cae0
// src: XBOX_PDB 0x0058cae0
int FUN_00573eb0_Class::NiPathInterpolator_GetFollow()
{
    return NiPathInterpolator_GetBit(0x20);
}

struct FUN_0058cba0_class
{
    enum Flag
    {
        FLAG_NONE = 0
    };
    bool EffectSetting_IsFlagSetAny(Flag flag);
};

// @fnv 0x0058cba0
// src: XBOX_PDB 0x0058cba0
bool FUN_0058cba0_class::EffectSetting_IsFlagSetAny(Flag flag)
{
    return (*(int*)((char*)this + 0x58) & (int)flag) != 0;
}

struct FUN_0058ccd0_class
{
    bool IsFlagSet() const;
};

// @fnv 0x0058ccd0
bool FUN_0058ccd0_class::IsFlagSet() const
{
    return (((int*)((char*)this + 0x44))[0] & 1) ? true : false;
}

struct FUN_0058ce30_Class
{
    bool IsFlag2Set() const;
};

// @fnv 0x0058ce30
bool FUN_0058ce30_Class::IsFlag2Set() const
{
    return ((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0x44) & 2) != 0) ? true
                                                                                                           : false;
}

extern int DAT_01033470;
struct FUN_0058f820_class
{
    int m_iWordAt00;
    void InitContainerItemExtra(int);
    int __thiscall ProcessAndReturnValue_0058f820(int a);
};
// @fnv 0x0058f820
// src: GUESS 0x0058f820 (confidence: low)
int __thiscall FUN_0058f820_class::ProcessAndReturnValue_0058f820(int a)
{
    InitContainerItemExtra(a);
    m_iWordAt00 = (int)&DAT_01033470;
    return (int)this;
}

extern "C" char* __cdecl ___insecure_strcpy(char* dst, const char* src);

struct FUN_00591a00_Class
{
    char* __thiscall CopyString(const char* src);
};

// Copies src into the object's storage with ___insecure_strcpy and returns a pointer to that storage.
// @fnv 0x00591a00
char* __thiscall FUN_00591a00_Class::CopyString(const char* apSource)
{
    ___insecure_strcpy(reinterpret_cast<char*>(this), apSource);
    return reinterpret_cast<char*>(this);
}

struct FUN_00591a20_Class
{
    int IsFlagBit4Set();
};

// @fnv 0x00591a20
int FUN_00591a20_Class::IsFlagBit4Set()
{
    return ((*(int*)((char*)this + 4)) & 0x10) ? 1 : 0;
}

struct FUN_00594d20_Class
{
    int __thiscall Stack_ExpressionOperand_32_empty();
};

// @fnv 0x00594d20
// src: XBOX_PDB 0x00594d20
int __thiscall FUN_00594d20_Class::Stack_ExpressionOperand_32_empty()
{
    return *(int*)((char*)this + 0x200) == -1;
}

struct FUN_00594d40_class
{
    void ResetField();
};

// @fnv 0x00594d40
void FUN_00594d40_class::ResetField()
{
    *(int*)((char*)this + 0x200) = 0xffffffff;
}

struct FUN_00598020_Class
{
    unsigned char GetByteAtOffset55();
};

// @fnv 0x00598020
unsigned char FUN_00598020_Class::GetByteAtOffset55()
{
    return ((const unsigned char*)this)[0x37];
}

extern "C" void _NiFreeAlias(void*);
extern int DAT_0103200c;
struct FUN_00589190 : NiTPointerMap<int, int>
{
    void Init();
};
// Sets the map's vtable pointer, removes all entries, and frees the pointer stored at offset 8.
// @fnv 0x00589190
void FUN_00589190::Init()
{
    *(int*)((char*)this + 0) = (int)&DAT_0103200c;
    RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
}

extern "C" void Deallocate(void*);
struct FUN_00589030_Class
{
    void __thiscall FUN_00589130();
    void* __thiscall FUN_00589030(unsigned int flags);
};

// Calls FUN_00589130, frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00589030
void* __thiscall FUN_00589030_Class::FUN_00589030(unsigned int flags)
{
    FUN_00589130();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00580680_Class
{
    virtual ~FUN_00580680_Class();
    virtual void TESWaterForm_SetRemappedWaterForm(int a);
};

// @fnv 0x00580680
// src: XBOX_PDB 0x00580680
void FUN_00580680_Class::TESWaterForm_SetRemappedWaterForm(int a)
{
    if (this == (FUN_00580680_Class*)a)
    {
        *(int*)((char*)this + 0x80) = 0;
        (*(void(__thiscall*)(FUN_00580680_Class*, int))(*(int**)this)[0x4c / 4])(this, 0x80000000);
    }
    else
    {
        *(int*)((char*)this + 0x80) = a;
        (*(void(__thiscall*)(FUN_00580680_Class*, int))(*(int**)this)[0x48 / 4])(this, 0x80000000);
    }
}

struct BFC_s
{
    BFC_s();
};
extern int DAT_01031838;
struct S82000
{
    void __thiscall ClearArray();
};
struct FUN_00581fd0 : BFC_s
{
    FUN_00581fd0();
};
// Sets the object's vtable pointer to DAT_01031838, then calls ClearArray on this.
// @fnv 0x00581fd0
FUN_00581fd0::FUN_00581fd0()
{
    *(int*)this = (int)&DAT_01031838;
    ((S82000*)this)->ClearArray();
}

struct FUN_00582000_Class
{
    int m_iWordAt00;
    int m_cByteAtOffset1[6];
    void __thiscall ClearArray();
};

// @fnv 0x00582000
void __thiscall FUN_00582000_Class::ClearArray()
{
    for (unsigned int i = 0; i < 6; ++i)
        m_cByteAtOffset1[i] = 0;
}

void __cdecl TESForm_AddChunk_00485910(int, int);
struct FUN_00582040_Class
{
    void ReleaseSoundSlots();
};
// @fnv 0x00582040
void FUN_00582040_Class::ReleaseSoundSlots()
{
    for (unsigned int i = 0; i < 6; ++i)
    {
        if (((int*)this)[i + 1])
        {
            int v = ((TESSound*)((int*)this)[i + 1])->Deallocate();
            TESForm_AddChunk_00485910(0x44414900 + i, v);
        }
    }
}

// @fnv 0x005822c0
TESWeatherList::TESWeatherList()
{
    ClearWeatherSounds();
}

// @fnv 0x00582be0
int __cdecl CompareSecondElement(unsigned int* pFirst, unsigned int* pSecond)
{
    int iResult;
    if (pFirst[1] > pSecond[1])
        iResult = -1;
    else
        iResult = pFirst[1] < pSecond[1];
    return iResult;
}

extern "C" unsigned char __cdecl TESObjectCELL_IsFormTypeCellChild(unsigned char a);

// Returns 1 for characters 0x39 and 0x44, otherwise delegates to FUN_005548a0 with the same character.
// @fnv 0x00588a60
// src: COMMUNITY 0x00588a60
unsigned char __cdecl TESWorldSpace_IsFormTypeWorldChild(unsigned char a)
{
    if (a == 0x39)
        return 1;
    if (a == 0x44)
        return 1;
    return TESObjectCELL_IsFormTypeCellChild(a);
}

void __cdecl Deallocate(void*);
struct FUN_00589230_t
{
    void __thiscall FUN_00589230();
};

struct FUN_00589060_t
{
    void* __thiscall FUN_00589060(unsigned int flags);
};

// Calls FUN_00589230 on this, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00589060
void* __thiscall FUN_00589060_t::FUN_00589060(unsigned int flags)
{
    ((FUN_00589230_t*)this)->FUN_00589230();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct Helper89330
{
    void __thiscall FUN_00589330();
};
void __cdecl _Deallocate(void*);
struct FUN_00589090_Cls
{
    void* __thiscall FUN_00589090(unsigned int flags);
};
// @fnv 0x00589090
void* __thiscall FUN_00589090_Cls::FUN_00589090(unsigned int flags)
{
    ((Helper89330*)this)->FUN_00589330();
    if (flags & 1)
        _Deallocate(this);
    return this;
}


void* __cdecl NiMalloc(unsigned int size);
struct FUN_005890c0
{
    int* pVTable;
    unsigned int uiSize;
    void* pMem;
    unsigned int ItemUpdateArray;
    FUN_005890c0(unsigned int size);
};
// Sets the vtable, stores size, allocates size*4 bytes with NiMalloc and zeroes them with memset.
// @fnv 0x005890c0
FUN_005890c0::FUN_005890c0(unsigned int size)
{
    pVTable = &DAT_0103200c;
    uiSize = size;
    ItemUpdateArray = 0;
    unsigned int uiAllocBytes = uiSize * 4;
    pMem = NiMalloc(uiAllocBytes);
    memset(pMem, 0, uiSize * 4);
}

namespace fnv_005891c0 {
extern "C" void* __cdecl _NiMalloc(unsigned int size);
void* __cdecl memset(void* dst, int c, unsigned int n);
extern int DAT_0103202c;
struct FUN_005891c0_Class
{
    int* pVTable;
    int count;
    int* pData;
    int zero;
    FUN_005891c0_Class(int n);
};
// Sets the vtable, stores n as count, allocates count*4 bytes, zeroes the buffer and stores it in pData.
// @fnv 0x005891c0
FUN_005891c0_Class::FUN_005891c0_Class(int aiCount)
{
    pVTable = &DAT_0103202c;
    count = aiCount;
    zero = 0;
    int size = count * 4;
    pData = (int*)_NiMalloc(size);
    memset(pData, 0, count * 4);
}
}  // namespace fnv_005891c0

void __cdecl _NiFree(void*);
extern int DAT_0103202c;
struct FUN_00589290_Class
{
    void __thiscall SetVtableAndProcessState_00589290();
};
// @fnv 0x00589290
// src: GUESS 0x00589290 (confidence: low)
void __thiscall FUN_00589290_Class::SetVtableAndProcessState_00589290()
{
    *(void**)this = (void*)&DAT_0103202c;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    _NiFree(*((void**)(((char*)this) + 8)));
}

namespace fnv_005892c0 {
extern "C" void* NiMalloc(unsigned int);
extern "C" void* memset(void*, int, unsigned int);
extern int DAT_0103204c;
struct FUN_005892c0_t
{
    void* __thiscall InitArray(unsigned int count);
};
// Sets the vtable, stores count, allocates count*4 bytes with NiMalloc, zeroes the buffer, and returns this.
// @fnv 0x005892c0
void* __thiscall FUN_005892c0_t::InitArray(unsigned int count)
{
    unsigned int size;
    *(int*)this = (int)&DAT_0103204c;
    ((unsigned int*)this)[1] = count;
    ((unsigned int*)this)[3] = 0;
    size = ((unsigned int*)this)[1] << 2;
    ((unsigned int*)this)[2] = (unsigned int)NiMalloc(size);
    memset(*(void**)((unsigned int*)this + 2), 0, ((unsigned int*)this)[1] << 2);
    return this;
}
}  // namespace fnv_005892c0

extern int DAT_0103204c;
void __cdecl _NiFree(void*);
struct FUN_00589390_Holder
{
    void __thiscall SetVtableAndProcessState_00589390();
};
// @fnv 0x00589390
// src: GUESS 0x00589390 (confidence: low)
void __thiscall FUN_00589390_Holder::SetVtableAndProcessState_00589390()
{
    *(int*)this = (int)&DAT_0103204c;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    _NiFree(*(void**)((char*)this + 8));
}

void __cdecl Deallocate(void* p);
struct FUN_005893c0Class
{
    void* __thiscall InitAndMaybeFree(unsigned int flags);
};
// Calls Init on this object, then frees this if bit 0 of flags is set, and returns this.
// @fnv 0x005893c0
void* __thiscall FUN_005893c0Class::InitAndMaybeFree(unsigned int flags)
{
    ((FUN_00589190*)this)->Init();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_005893f0_Class
{
    void __thiscall SetVtableAndProcessState_00589290();
    void* __thiscall FUN_005893f0(unsigned int flags);
};

// @fnv 0x005893f0
void* __thiscall FUN_005893f0_Class::FUN_005893f0(unsigned int flags)
{
    SetVtableAndProcessState_00589290();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00589420_Class
{
    void __thiscall SetVtableAndProcessState_00589390();
    void* __thiscall FUN_00589420(unsigned int flags);
};

// @fnv 0x00589420
void* FUN_00589420_Class::FUN_00589420(unsigned int flags)
{
    SetVtableAndProcessState_00589390();
    if (flags & 1)
        operator delete(this);
    return this;
}

float __cdecl NiSqrt_004579e0(float);

struct FUN_00589850_Class
{
    float m_iWordAt00;
    float m_cByteAtOffset1;
    float __thiscall NiPoint3_XYLength();
};

// @fnv 0x00589850
// src: XBOX_PDB 0x00589850
float __thiscall FUN_00589850_Class::NiPoint3_XYLength()
{
    return NiSqrt_004579e0(this->m_iWordAt00 * this->m_iWordAt00 + this->m_cByteAtOffset1 * this->m_cByteAtOffset1);
}

struct FUN_004726b0_class
{
    int __thiscall TESFile_GetTESChunk();
};
struct FUN_00589890_Class
{
    bool AudioBuoyMarker_Load(FUN_004726b0_class* apData);
};
// @fnv 0x00589890
// src: COMMUNITY 0x00589890
bool FUN_00589890_Class::AudioBuoyMarker_Load(FUN_004726b0_class* apData)
{
    if (!apData)
        return false;
    if (apData->TESFile_GetTESChunk() != 0x4b524d4d)
        return false;
    return true;
}

struct FUN_0058b680_Class
{
    unsigned int __thiscall BGSCameraPath_GetIndexForChild(TESForm* form);
};
// @fnv 0x0058b680
// src: COMMUNITY 0x0058b680
unsigned int __thiscall FUN_0058b680_Class::BGSCameraPath_GetIndexForChild(TESForm* form)
{
    unsigned int result = 0xFFFFFFFF;
    if (reinterpret_cast<NiFormArray**>(reinterpret_cast<char*>(this) + 0x2C)[0])
        result = reinterpret_cast<NiFormArray**>(reinterpret_cast<char*>(this) + 0x2C)[0]->GetIndexOfForm(form);
    return result;
}

struct TESTopicInfo;
struct FUN_0058b630_shell
{
    TESSound* GetCameraPathAt(unsigned int index);
};
struct FUN_0058b6c0_shell
{
    void RemoveSoundAt(unsigned int index);
};
// @fnv 0x0058b6c0
void FUN_0058b6c0_shell::RemoveSoundAt(unsigned int index)
{
    TESSound* next;
    TESSound* prev;
    if (*(unsigned int*)((char*)this + 0x2c))
    {
        next = ((FUN_0058b630_shell*)this)->GetCameraPathAt(index + 1);
        prev = ((FUN_0058b630_shell*)this)->GetCameraPathAt(index - 1);
        if (next)
            ((TES*)next)->SetDawnSound(prev);
        ((NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >*)*(unsigned int*)((char*)this + 0x2c))->RemoveAt(index);
        ((NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >*)*(unsigned int*)((char*)this + 0x2c))->Compact();
    }
}

struct Holder680
{
    int __thiscall BGSCameraPath_GetIndexForChild(int);
};
struct Holder6c0
{
    void __thiscall RemoveSoundAt(int);
};
struct Holder730
{
    char _pad[0x2c];
    int m_2c;
    void __thiscall BGSCameraPath_RemoveChild(int);
};
// If a1 and m_2c are both nonzero, calls FUN_0058b680 with a1 and passes its result to RemoveSoundAt.
// @fnv 0x0058b730
// src: COMMUNITY 0x0058b730
void __thiscall Holder730::BGSCameraPath_RemoveChild(int a1)
{
    int v;
    if (a1 != 0 && m_2c != 0)
    {
        v = ((Holder680*)this)->BGSCameraPath_GetIndexForChild(a1);
        ((Holder6c0*)this)->RemoveSoundAt(v);
    }
}

class BGSCameraPath;

namespace fnv_0058b770 {
struct FUN_0058b770
{
    NiFormArray forms;
    NiTPrimitiveArray<BGSCameraPath*> arr;
    FUN_0058b770();
};
// @fnv 0x0058b770
FUN_0058b770::FUN_0058b770() : arr(0, 1)
{}
}  // namespace fnv_0058b770

namespace fnv_0058bc60 {
extern "C" void __cdecl _Deallocate(void*);

struct FUN_0058bc60_Class
{
    void* FUN_0058bc60(unsigned int flags);
};

// @fnv 0x0058bc60
void* FUN_0058bc60_Class::FUN_0058bc60(unsigned int flags)
{
    ((FUN_0058bc00_obj*)this)->Object_ReleaseStorage();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_0058bc60

void __fastcall Runtime_ForwardCall_0058b830(FUN_0058bc00_obj* this_ptr);
void __cdecl _Deallocate(void* p);
struct FUN_0058bc90_Holder
{
    void* __thiscall FUN_0058bc90(unsigned int flags);
};
// @fnv 0x0058bc90
void* __thiscall FUN_0058bc90_Holder::FUN_0058bc90(unsigned int flags)
{
    Runtime_ForwardCall_0058b830((FUN_0058bc00_obj*)this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0058cb60_Class
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned short m_8;
    unsigned int m_iThirdValue;
    int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned char m_1c;
    int m_20;
    int __thiscall NiTransformData_GetRotAnim(unsigned int* a, int* b, unsigned char* c);
};
// Writes m_8, m_10 and m_1c to the three output pointers and returns m_20.
// @fnv 0x0058cb60
// src: XBOX_PDB 0x0058cb60
int __thiscall FUN_0058cb60_Class::NiTransformData_GetRotAnim(unsigned int* a, int* piValue, unsigned char* c)
{
    *a = m_8;
    *piValue = m_10;
    *c = m_1c;
    return m_20;
}

struct FUN_0058f7f0_Class
{
    int* __thiscall ImpactSwap_GetAltFootstepMaterialName(int a);
};

// Returns a pointer to the entry at offset 0x30 plus a*0x1e if its first byte is nonzero, otherwise returns 0.
// @fnv 0x0058f7f0
// src: COMMUNITY 0x0058f7f0
int* __thiscall FUN_0058f7f0_Class::ImpactSwap_GetAltFootstepMaterialName(int aiIndex)
{
    if (*(char*)((char*)this + 0x30 + aiIndex * 0x1e))
        return (int*)((char*)this + 0x30 + aiIndex * 0x1e);
    return 0;
}

void __cdecl Deallocate(void*);

struct FUN_0058f850_class
{
    void __thiscall FUN_0058f900();
    void* __thiscall FUN_0058f850(unsigned int flags);
};

// Calls FUN_0058f900, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0058f850
void* __thiscall FUN_0058f850_class::FUN_0058f850(unsigned int flags)
{
    FUN_0058f900();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_01033490;
void __cdecl _Deallocate(void* p);
struct FUN_0058f960_Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
    void __thiscall UpdateFields_0058f960();
};
// @fnv 0x0058f960
// src: GUESS 0x0058f960 (confidence: low)
void __thiscall FUN_0058f960_Obj::UpdateFields_0058f960()
{
    m_iWordAt00 = (int)&DAT_01033490;
    if (m_8 != 0)
    {
        void* p = m_8;
        _Deallocate(p);
    }
}

struct FUN_0058f9a0_Class
{
    void __thiscall UpdateFields_0058f960();
    void* __thiscall FUN_0058f9a0(unsigned int flags);
};
// Calls FUN_0058f960, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0058f9a0
void* FUN_0058f9a0_Class::FUN_0058f9a0(unsigned int flags)
{
    UpdateFields_0058f960();
    if (flags & 1)
        operator delete(this);
    return this;
}


struct FUN_00591170 : ::BSStringT<char>
{
    PerkEntryConditionSet cond;
    ~FUN_00591170();
};
// Destructor that destroys the contained condition object and the base object.
// @fnv 0x00591170
FUN_00591170::~FUN_00591170()
{}

// @fnv 0x005912d0
// m_kSoundFile is the shared BSStringT<char>: its default constructor (0x004037b0) runs as the member's
TESSoundFile::TESSoundFile()
{
}

extern unsigned int DAT_011ca87c;
extern void** DAT_011ca880;

// Returns the pointer stored at index in the array DAT_011ca880 if index is within DAT_011ca87c, otherwise returns 0.
// @fnv 0x005922a0
// src: XBOX_PDB 0x005922a0
void* BGSRadiationStage_GetStage(unsigned int index)
{
    return index >= 0 && index < DAT_011ca87c ? DAT_011ca880[index] : 0;
}

// Returns true when aiType is 1 and the int at aiParam+4 is one of 0,1,2,3,9,10; otherwise false.
// @fnv 0x00594d60
bool IsValidTypeValue(int aiParam, int aiType)
{
    bool bResult = false;
    if (aiType == 1)
    {
        int iValue = *(int*)(aiParam + 4);
        switch (iValue)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 9:
        case 10:
            bResult = true;
            break;
        }
    }
    return bResult;
}

class TESFullName;
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* a, TESFile* f);
};
// Partial loader layout retained until include/ provides AudioMarkerData.
struct AudioMarkerData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_iThirdValue;
    unsigned int m_10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int m_24;
    char m_28;
    bool LoadFromFile(TESFile* apFile);
};
// @fnv 0x00589600
bool AudioMarkerData::LoadFromFile(TESFile* apFile)
{
    if (!apFile)
        return false;
    if (apFile->GetChunkID() != 0x4b524d4d)
        return false;
    unsigned int uiChunkValue = 0;
    if (!apFile->NextChunk())
        return false;
    if (apFile->GetChunkID() == 0x4c4c5546)
        TESFullNameLoader::LoadFullNameChunk((TESFullName*)this, apFile);
    else
        return false;
    if (!apFile->NextChunk())
        return false;
    if (apFile->GetChunkID() == 0x4d414e43)
    {
        apFile->GetChunkData(&uiChunkValue);
        m_24 = uiChunkValue;
    }
    else
        return false;
    if (!apFile->NextChunk())
        return false;
    if (apFile->GetChunkID() == 0x4d414e42)
    {
        apFile->GetChunkData(&uiChunkValue);
        m_28 = uiChunkValue == 1;
    }
    else
        return false;
    if (!apFile->NextChunk())
        return false;
    if (apFile->GetChunkID() == 0x4d414e4d)
        apFile->GetChunkData(&m_iThirdValue);
    else
        return false;
    if (!apFile->NextChunk())
        return false;
    if (apFile->GetChunkID() == 0x4d414e4e)
        apFile->GetChunkData(&m_10);
    else
        return false;
    return true;
}

void* __cdecl operator new(unsigned int size);
void __cdecl _fnv_zlib_memset(void* dst, int val, unsigned int count);
struct ContainerItemExtra
{
    void* pVTable;
    int iCount;
    void* pItem;
    int m_0c;
    void* __thiscall InitContainerItemExtra(int count);
};
// Sets the vtable, stores count, zeroes m_0c, and if count is nonzero allocates count*4 bytes for pItem and zero-fills them.
// @fnv 0x0058f880
void* __thiscall ContainerItemExtra::InitContainerItemExtra(int count)
{
    this->pVTable = &DAT_01033490;
    this->iCount = count;
    this->m_0c = 0;
    if (count)
    {
        unsigned int sz3 = this->iCount * 4;
        void* p2 = operator new(sz3);
        this->pItem = p2;
        _fnv_zlib_memset(this->pItem, 0, this->iCount * 4);
    }
    return this;
}

struct Flt
{
    operator unsigned int();
};
struct FUN_0058cb00_Class
{
    char _pad[0x2c];
    int NiTransformInterpolator_GetRotData(unsigned int* a, int* b, unsigned char* c);
};
// If the field at offset 0x2c is nonzero, forwards a, b and c to FUN_0058cb60 on that object; otherwise zeroes all three outputs and returns 0.
// @fnv 0x0058cb00
// src: XBOX_PDB 0x0058cb00
int FUN_0058cb00_Class::NiTransformInterpolator_GetRotData(unsigned int* puiValue, int* piValue, unsigned char* pbValue)
{
    if ((unsigned int)*(Flt*)((char*)this + 0x2c))
        return ((FUN_0058cb60_Class*)(unsigned int)*(Flt*)((char*)this + 0x2c))
            ->NiTransformData_GetRotAnim(puiValue, piValue, pbValue);
    *puiValue = 0;
    *piValue = 0;
    *pbValue = 0;
    return 0;
}

void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);
void __cdecl _FUN_00485910(int, int);
void __cdecl _FUN_00485910(int, float);

// @fnv 0x00589560
void TESModel::WriteToStream()
{
    TESForm_AddChunkArray(0x4c4c5546, GetFullName(), GetModelLength() + 1);

    // These stream fields are not yet named in the shared definition.
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x24) != 0)
        _FUN_00485910(0x4d414e43, *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x24));

    _FUN_00485910(0x4d414e42, *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x28) != 0);
    _FUN_00485910(0x4d414e4d, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x0c));
    _FUN_00485910(0x4d414e4e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x10));
}

extern char DAT_01183040;
extern char DAT_01186ab0;
extern "C" void* __cdecl FUN_00ec43fb(int input, int mode, const void* type, const void* name, int flags);

struct ControllerArchive : FUN_00581fb0_Class
{
    void __thiscall LoadControllerArchive(int source);
};

// Loads an archive from source and copies six entries into the base object via FUN_00581fb0.
// @fnv 0x005821b0
void ControllerArchive::LoadControllerArchive(int source)
{
    FUN_005822a0_cls* loaded = static_cast<FUN_005822a0_cls*>(FUN_00ec43fb(source, 0, &DAT_01183040, &DAT_01186ab0, 0));
    if (loaded == 0)
        return;
    for (unsigned int i = 0; i < 6; ++i)
    {
        TESImageSpaceModifiableCountForm_6_SetFormImageSpaceModifying(i, loaded->TESImageSpaceModifiableCountForm_6_GetFormImageSpaceModifying(i));
    }
}

namespace fnv_00582220 {
extern int DAT_01183040;
extern int DAT_01186ab0;
FUN_005822a0_cls* __cdecl FUN_00ec43fb(int key, int zero, void* first, void* second, int trailing);
struct FUN_00582220_Class : FUN_005822a0_cls
{
    bool __thiscall IsNotEqual(int key);
};
// Compares this object against the result of FUN_00ec43fb for the given key over six indices, returning true if any differ or no comparison exists.
// @fnv 0x00582220
bool FUN_00582220_Class::IsNotEqual(int key)
{
    FUN_005822a0_cls* comparison = FUN_00ec43fb(key, 0, &DAT_01183040, &DAT_01186ab0, 0);
    if (!comparison)
    {
        return true;
    }
    for (unsigned int index = 0; index < 6; ++index)
    {
        if (TESImageSpaceModifiableCountForm_6_GetFormImageSpaceModifying(index) != comparison->TESImageSpaceModifiableCountForm_6_GetFormImageSpaceModifying(index))
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_00582220

class MapDtorWrap_b9454 : public NiTPointerMap<int, int>
{
  public:
    virtual void unk00();
    ~MapDtorWrap_b9454();
};

class FUN_00589130_cls : public MapDtorWrap_b9454
{
  public:
    virtual ~FUN_00589130_cls();
};

// Destructor that clears all entries from the underlying NiTPointerMap by calling RemoveAll.
// @fnv 0x00589130
FUN_00589130_cls::~FUN_00589130_cls()
{
    reinterpret_cast<NiTPointerMap<int, int>*>(this)->RemoveAll();
}

struct FUN_00589230_Base
{
    virtual ~FUN_00589230_Base();
};

struct FUN_00589230 : FUN_00589230_Base
{
    void FUN_00438af0();
    virtual ~FUN_00589230();
};

// @fnv 0x00589230
FUN_00589230::~FUN_00589230()
{
    FUN_00438af0();
}

struct Base_589330
{
    virtual ~Base_589330();
    int unk04;
    int unk08;
};

class FUN_00589330_cls : public Base_589330
{
  public:
    int unk0C;
    void FUN_00438af0();

    virtual ~FUN_00589330_cls();
};

// Destructor of FUN_00589330_cls that calls FUN_00438af0 before the base destructor runs.
// @fnv 0x00589330
FUN_00589330_cls::~FUN_00589330_cls()
{
    FUN_00438af0();
}

struct FUN_00591300
{
    ~FUN_00591300();
};

struct FUN_0046ffb0
{
    ~FUN_0046ffb0();
};

class FUN_00589500 : public FUN_00591300
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    FUN_0046ffb0 member2c;

    ~FUN_00589500();
};

// Empty destructor for the class; destroys the base subobject and the member at offset 0x2c.
// @fnv 0x00589500
FUN_00589500::~FUN_00589500()
{}

struct S_00589770_Class;

typedef void(__thiscall* S_00589770_VFn)(S_00589770_Class*, S_00589770_Class*);

struct S_00589770_Class
{
    S_00589770_VFn* pVTable;
    int unk04;
    int unk08;
    float unk0c;
    float unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    unsigned char unk28;

    void __thiscall CopyFrom(S_00589770_Class* arg);
};

// @fnv 0x00589770
void __thiscall S_00589770_Class::CopyFrom(S_00589770_Class* pSource)
{
    this->pVTable[2](this, pSource);

    this->unk24 = pSource->unk24;
    this->unk28 = pSource->unk28;
    this->unk0c = pSource->unk0c;
    this->unk10 = pSource->unk10;
}

void __fastcall Runtime_ForwardCall_0058b830(FUN_0058bc00_obj* this_ptr);

struct FUN_0058b450
{
    ~FUN_0058b450();
};

struct FUN_0058b7d0 : FUN_0058b450
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_0058bc00_obj m_18;

    ~FUN_0058b7d0();
};

// @fnv 0x0058b7d0
FUN_0058b7d0::~FUN_0058b7d0()
{
    Runtime_ForwardCall_0058b830(&m_18);
}

void* __cdecl FUN_0096afc0(unsigned int size);

struct FUN_0058bcc0
{
    virtual ~FUN_0058bcc0();
    void* m_04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;

    FUN_0058bcc0(unsigned short a1, unsigned short a2);
};

// Initializes the object with two unsigned shorts, zeroes two fields, and allocates m_08 bytes into m_04 when m_08 is nonzero.
// @fnv 0x0058bcc0
FUN_0058bcc0::FUN_0058bcc0(unsigned short ausValue, unsigned short a2)
{
    m_08 = ausValue;
    m_0e = a2;
    m_0a = 0;
    m_0c = 0;
    if (m_08 > 0)
        m_04 = FUN_0096afc0(m_08);
    else
        m_04 = 0;
}


struct Node_58cbc0
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pMem, unsigned int);
    Node_58cbc0(unsigned short usChildren);
    void SetLocalRotate(const Mat3& kRot);
    void AttachObject(void* pObj);
};

struct NodePtr_58cbc0
{
    Node_58cbc0* m_pObject;
    NodePtr_58cbc0& operator=(Node_58cbc0* pObj);
    operator Node_58cbc0*() const;
};

struct Source_58cbc0
{
    Mat3 GetRotation();
};

void* __fastcall GetRenderObject_58cbc0(Node_58cbc0* pNode);

extern bool g_bNodeDirty_58cbc0;

struct Owner_58cbc0
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    NodePtr_58cbc0 m_pController;
    int unk64;
    Source_58cbc0* pSource;

    bool IsFlagSet() const;
    void SetNode(Node_58cbc0* pNode);
};

// @fnv 0x0058cbc0
void Owner_58cbc0::SetNode(Node_58cbc0* pNode)
{
    if (IsFlagSet())
    {
        m_pController = pNode;
    }
    else if (pNode)
    {
        m_pController = new Node_58cbc0(0);
        if (pSource)
        {
            ((Node_58cbc0*)m_pController)->SetLocalRotate(pSource->GetRotation());
        }
        ((Node_58cbc0*)m_pController)->AttachObject(GetRenderObject_58cbc0(pNode));
    }
    g_bNodeDirty_58cbc0 = true;
}

struct ModelComponent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* Name();
};
class ModelLoader
{
  public:
    void ModelLoader_ReleaseFile(const char*);
};
extern ModelLoader* DAT_011c3b3c;
extern bool DAT_011ca729;
class TESRace;
class BSSimpleListTESRaceSize
{
  public:
    int GetSize();
};
extern BSSimpleListTESRaceSize DAT_011f2250;
BSAudio* BSAudio_QInstance();

// BSAudio's shared declaration still returns the former sound-handle stand-in.
// Declare the same entry point with the checked handle type for this unit.
class BSAudioWithSoundHandle : public BSAudio
{
public:
    BSSoundHandle GetSoundHandleByEditorID(const char* editorID, unsigned int flags);
};

struct CameraState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ModelComponent model;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    NP node60;
    NP node64;
    int unk68;
    NP node6c;
    NP node70;
    unsigned char unk74;
    bool active;
    void ResetCameraState();
};
// @fnv 0x0058ce50
void CameraState::ResetCameraState()
{
    node60 = static_cast<void*>(0);
    node64 = static_cast<void*>(0);
    unk68 = 0;
    node70 = static_cast<void*>(0);
    active = false;
    if (static_cast<const NP&>(node6c).Modelloader_GetReferencedThis())
    {
        node6c = static_cast<void*>(0);
        DAT_011c3b3c->ModelLoader_ReleaseFile(model.Name());
    }
    if (DAT_011ca729 && !DAT_011f2250.GetSize())
    {
        DAT_011ca729 = false;
        BSSoundHandle sound = static_cast<BSAudioWithSoundHandle*>(BSAudio_QInstance())->GetSoundHandleByEditorID("UIVATSCameraOut", 0x121);
        sound.Play(false);
    }
}

struct FUN_00483370
{
    virtual ~FUN_00483370();
    unsigned int formType;
    unsigned int formFlags;
    unsigned int formId;
    unsigned int formVersion;
    unsigned int formData;
    FUN_00483370();
    void FUN_00483710();
    void FUN_004f15a0(int count);
};
struct FUN_00402c20
{
    virtual ~FUN_00402c20();
    FUN_00402c20();
};
struct FUN_00590210 : FUN_00483370, FUN_00402c20
{
    FUN_00590210();
    virtual ~FUN_00590210();
};
// Initializes the object by calling FUN_00483710 and then FUN_004f15a0 with a count of 5.
// @fnv 0x00590210
FUN_00590210::FUN_00590210()
{
    FUN_00483710();
    FUN_004f15a0(5);
}

struct FUN_00591200_base0
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ~FUN_00591200_base0();
    FUN_00591200_base0();
};

struct FUN_00591200_base1
{
    virtual void v00();
    int unk04;
    int unk08;
    FUN_00591200_base1();
    ~FUN_00591200_base1();
};

struct FUN_00591200_member
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00591200_member();
    ~FUN_00591200_member();
};

extern float g_00591200_const;

struct FUN_00591200_cls : FUN_00591200_base0, FUN_00591200_base1
{
    float m_24;
    FUN_00591200_member m_28;

    void Setup(int aArg);
    FUN_00591200_cls();
};

// Initializes the object by calling Setup with 0x66 and then assigning g_00591200_const to m_24.
// @fnv 0x00591200
FUN_00591200_cls::FUN_00591200_cls()
{
    Setup(0x66);
    m_24 = g_00591200_const;
}

struct EntryRec_cls
{
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    unsigned int m_iFourthElementInteger;
};

struct FUN_00594c80_cls
{
    EntryRec_cls m_entries[0x20];
    int m_uiItemCount;
    void AddEntry(EntryRec_cls e);
};

// Increments the entry count and stores the given entry at that index in m_entries.
// @fnv 0x00594c80
void FUN_00594c80_cls::AddEntry(EntryRec_cls aEntry)
{
    m_uiItemCount = m_uiItemCount + 1;
    m_entries[m_uiItemCount] = aEntry;
}

struct FUN_00594cd0_Entry
{
    int field00;
    int field04;
    int field08;
    int field0c;
};

struct FUN_00594cd0_Class
{
    FUN_00594cd0_Entry entries[32];
    unsigned int count;

    FUN_00594cd0_Entry* __thiscall PopEntry(FUN_00594cd0_Entry* result);
};

// Copies the entry at index count into result, then decrements count.
// Copies entries[count] to *result, decrements count, and returns result.
// @fnv 0x00594cd0
FUN_00594cd0_Entry* __thiscall FUN_00594cd0_Class::PopEntry(FUN_00594cd0_Entry* result)
{
    *result = entries[count];
    count = count - 1;
    return result;
}

struct FUN_006ab360_t
{
    int* __thiscall TESCombatStyle_GetAdvancedData();
};

// @fnv 0x0059ae10
// src: COMMUNITY 0x0059ae10
int __cdecl TESCaravanCard_Compare_0(void* apLeft, void* apRight)
{
    int y;
    int x;
    x = *((FUN_006ab360_t*)*(void**)apLeft)->TESCombatStyle_GetAdvancedData();
    y = *((FUN_006ab360_t*)*(void**)apRight)->TESCombatStyle_GetAdvancedData();
    if (x > y)
    {
        return 1;
    }
    else
    {
        if (x < y)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

struct Form_58bd30
{
    virtual ~Form_58bd30();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    Form_58bd30();
    void SetFormType(int type);
};
struct ISMForm_58bd30
{
    virtual void v00();
    unsigned int unk04;
    ISMForm_58bd30();
};
struct NodePtr_58bd30
{
    void* m_pObject;
    NodePtr_58bd30(void* object);
    ~NodePtr_58bd30();
    NodePtr_58bd30& operator=(void* object);
};
struct FUN_0058bd30 : Form_58bd30, TESModel, ISMForm_58bd30
{
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
    NodePtr_58bd30 node60;
    NodePtr_58bd30 node64;
    int unk68;
    NodePtr_58bd30 node6c;
    NodePtr_58bd30 node70;
    unsigned char unk74;
    bool unk75;
    bool unk76;
    FUN_0058bd30();
    virtual ~FUN_0058bd30();
    void Reset();
};

// Initializes the form: sets form type 0x5b, calls Reset, clears the node pointers and unk68, and sets unk74 to 0xff with unk75/unk76 false.
// @fnv 0x0058bd30
FUN_0058bd30::FUN_0058bd30() : node60(0), node64(0), node6c(0), node70(0)
{
    SetFormType(0x5b);
    Reset();
    node60 = static_cast<void*>(0);
    node64 = static_cast<void*>(0);
    node6c = static_cast<void*>(0);
    unk68 = 0;
    node70 = static_cast<void*>(0);
    unk74 = 0xff;
    unk75 = false;
    unk76 = false;
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct FNVKeywordEntry
{
    unsigned char flag0;
    unsigned char flag1;
    unsigned char flag2;
    unsigned char flag3;
    unsigned char flag4;
    char text[3];
};
extern FNVKeywordEntry DAT_0118cad0[16];
extern char DAT_0118cad5[];
struct FNVTokenParser
{
    void __thiscall SetError(int error);
    int __thiscall ParseToken(char** input, char* output, unsigned int* type, unsigned char countLeading,
                              int* leadingCount);
};
// @fnv 0x00593870
int __thiscall FNVTokenParser::ParseToken(char** input, char* output, unsigned int* type, unsigned char countLeading,
                                          int* leadingCount)
{
    int size;
    char* pRead = *input;
    char* dest = output;
    bool beginning = true;
    char c;
    *type = 16;
    while (*pRead != 0 && *pRead < '!')
    {
        ++pRead;
        if (countLeading != 0 && leadingCount != 0)
            ++*leadingCount;
    }
    while (*pRead != 0)
    {
        c = *pRead;
        short id = *reinterpret_cast<short*>(pRead + 1);
        if (c == 'X' && id >= 0x1000 && id < 0x1280)
        {
            short length = *reinterpret_cast<short*>(pRead + 3);
            length += 5;
            memcpy(dest, pRead, length);
            dest += length;
            pRead += length;
            break;
        }
        else if (c == 's' || c == 'l' || c == 'f' || c == 'G' || c == 'Z' || c == 'r')
        {
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            if (c == 'r')
            {
                beginning = false;
            }
            else
            {
                break;
            }
        }
        else if (c == 'n')
        {
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            break;
        }
        else if (c == 'z')
        {
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            break;
        }
        else if (c == '"')
        {
            *dest = c;
            ++dest;
            ++pRead;
            while (*pRead != 0 && *pRead != '"')
            {
                *dest = *pRead;
                ++dest;
                ++pRead;
            }
            if (*pRead == '"')
            {
                *dest = *pRead;
                ++dest;
                ++pRead;
            }
            break;
        }
        else
        {
            if (c == ' ' || c == '\t')
                break;
            bool i = false;
            bool s = false;
            FNVKeywordEntry* a = DAT_0118cad0;
            unsigned int h;
            unsigned int p;
            for (h = 0; h < 16; ++h)
            {
                const char* keyword = a->text;
                i = true;
                for (p = 0; *keyword != 0; ++p)
                {
                    if (*keyword != pRead[p])
                    {
                        i = false;
                        break;
                    }
                    else
                    {
                        s = true;
                        ++keyword;
                    }
                }
                if (i)
                    break;
                ++a;
            }
            *type = h;
            if (i)
            {
                if (beginning)
                {
                    const char* matchedText = DAT_0118cad5 + *type * 8;
                    for (p = 0; *matchedText != 0; ++p)
                    {
                        *dest = *matchedText;
                        ++dest;
                        ++matchedText;
                        ++pRead;
                    }
                }
                else
                {
                    *type = 16;
                }
                break;
            }
            else if (s)
                SetError(5);
            *dest = c;
            ++dest;
            beginning = false;
            ++pRead;
        }
    }
    *dest = 0;
    *input = pRead;
    size = dest - output;
    return size;
}

class FUN_0058f960
{
  public:
    virtual ~FUN_0058f960();

    void FUN_00438af0();
};

class FUN_0058f900 : public FUN_0058f960
{
  public:
    virtual ~FUN_0058f900();
};

// @fnv 0x0058f900
FUN_0058f900::~FUN_0058f900()
{
    FUN_00438af0();
}
