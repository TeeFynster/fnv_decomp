
// src/staging/blk_00660000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/Setting.h"
#include "../../include/BSSimpleList.h"
#include "../../include/Actor.h"
#include "../../include/ActorPackageData.h"
#include "../../include/AutoMemHelper.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSLoadGameBuffer.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/TESForm.h"
#include "../../include/TESPackage.h"
#include "../../include/SL.h"
#include "../../include/bhkCharacterController.h"
#include "../../include/bhkConvexShape.h"
#include "../../include/NiPoint3.h"
#include "../../include/BGSSaveLoadChangesMap.h"

void __cdecl CopyConstructEntry(int a, int b);

struct FUN_006601f0_Class
{
    void __thiscall CopyConstructEntry_Thunk(int a, int b);
};

// @fnv 0x006601f0
// src: GUESS 0x006601f0 (confidence: medium)
void __thiscall FUN_006601f0_Class::CopyConstructEntry_Thunk(int aiArg1, int aiArg2)
{
    CopyConstructEntry(aiArg1, aiArg2);
}

extern "C" void __cdecl Object_DispatchIteratorRange_00660340(void*, void*, void*, void*);

// @fnv 0x00660210
// src: GUESS 0x00660210 (confidence: low)
void __cdecl Runtime_ForwardCall_00660210(void* a1, void* a2, void* a3, void* a4)
{
    Object_DispatchIteratorRange_00660340(a1, a2, a3, a4);
}

extern "C" void __cdecl Object_DispatchIteratorRange_006603a0(void* a, void* b, void* c, void* d);

// @fnv 0x00660230
// src: GUESS 0x00660230 (confidence: low)
void __cdecl Runtime_ForwardCall_00660230(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    Object_DispatchIteratorRange_006603a0(apArg1, apArg2, apArg3, apArg4);
}

extern "C" int __cdecl ConstructInPlace(int, int);

struct FUN_00660300_Class
{
    int __thiscall ConstructInPlace_Thunk(int a, int b);
};

// @fnv 0x00660300
// src: GUESS 0x00660300 (confidence: medium)
int __thiscall FUN_00660300_Class::ConstructInPlace_Thunk(int aiArg1, int aiArg2)
{
    return ConstructInPlace(aiArg1, aiArg2);
}

extern "C" void __cdecl CopyConstructElement(int, int);

struct FUN_00660320_Class
{
    void __thiscall CopyConstructElement_Thunk(int a, int b);
};

// @fnv 0x00660320
// src: GUESS 0x00660320 (confidence: medium)
void __thiscall FUN_00660320_Class::CopyConstructElement_Thunk(int aiFirst, int aiSecond)
{
    CopyConstructElement(aiFirst, aiSecond);
}

extern const char* const g_011d5ba8_arg1;

struct FUN_00661d30_cls
{
    const char* const* GetArg1Ptr();
};

// @fnv 0x00661d30
const char* const* FUN_00661d30_cls::GetArg1Ptr()
{
    return &g_011d5ba8_arg1;
}

extern "C" void* __cdecl NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectTREE_NiPointer_BSTreeModel_NiTMapBase(void*);
extern int DAT_01066434;

struct FUN_00665c50
{
    void* __thiscall NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectTREE_NiPointer_BSTreeModel_NiTMapBase(int a);
    void* __thiscall Set(int a);
};

// Calls FUN_00665f50 with a, stores the address of DAT_01066434 into this, and returns this.
// @fnv 0x00665c50
void* __thiscall FUN_00665c50::Set(int a)
{
    NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectTREE_NiPointer_BSTreeModel_NiTMapBase(a);
    *reinterpret_cast<void**>(this) = &DAT_01066434;
    return this;
}

struct FUN_00665f10_class
{
    int __thiscall Identity(int a);
};

// @fnv 0x00665f10
int __thiscall FUN_00665f10_class::Identity(int aiValue)
{
    return aiValue;
}

// NiTPointerMap::DeleteItem: clears the value and returns the node to the NiTPointerAllocator pool (the item
// count's empty base at 0xc).
// @fnv 0x00666050
template <>
void NiTPointerMap<unsigned int, FormChangeRecord*>::DeleteItem(NiTMapItem<unsigned int, FormChangeRecord*>* pkItem)
{
    pkItem->m_val = 0;
    m_kItemCount.Deallocate(pkItem);
}

extern Setting originalRuntimeFloatSetting1297;

// @fnv 0x0066b0b0
// src: XBOX_PDB 0x0066b0b0
float BSTreeManager_GetSizeConversion()
{
    return *originalRuntimeFloatSetting1297.Float();
}

extern "C" void* __cdecl BSTreeManager_GetInstance(int);
struct Flt
{
    operator unsigned int();
};
// @fnv 0x0066b660
unsigned int __cdecl GetFltValueAtOffset16()
{
    return ((Flt*)((char*)BSTreeManager_GetInstance(1) + 0x10))->operator unsigned int();
}

struct FUN_0066dd80_Class
{
    bool IsFlag8Set() const;
};

// @fnv 0x0066dd80
bool FUN_0066dd80_Class::IsFlag8Set() const
{
    return (*(const unsigned int*)((const char*)this + 0x12c) & 8) ? true : false;
}

// Returns true when type is 7 or 8, false otherwise.
// @fnv 0x0066de80
// src: XBOX_PDB 0x0066de80
bool ActionPoints_IsThrownAttackAction(int type)
{
    switch (type)
    {
    case 7:
    case 8:
        return true;
    default:
        return false;
    }
}

extern int DAT_01068884;

struct FUN_0067ad20_Class
{
    int* vtbl;
    FUN_0067ad20_Class();
};

// @fnv 0x0067ad20
FUN_0067ad20_Class::FUN_0067ad20_Class()
{
    vtbl = &DAT_01068884;
}

extern int DAT_01068884;

struct FUN_0067ad70_Class
{
    void SetVtableAndProcessState_0067ad70();
};

// @fnv 0x0067ad70
// src: GUESS 0x0067ad70 (confidence: low)
void FUN_0067ad70_Class::SetVtableAndProcessState_0067ad70()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_01068884);
}

extern int DAT_01068aa4;


ActorPackageData::ActorPackageData()
{}

// @fnv 0x0067d920
ActorPackageData* ActorPackageData::FUN_0067d920()
{
    *(int**)this = &DAT_01068aa4;
    return this;
}

extern "C" int DAT_01068aa4;

struct FUN_0067d970_Class
{
    int m;
    void __thiscall SetM();
};

// @fnv 0x0067d970
// src: GUESS 0x0067d970 (confidence: low)
void __thiscall FUN_0067d970_Class::SetM()
{
    m = (int)&DAT_01068aa4;
}

struct FUN_0067f4b0_class
{
    unsigned char b;
    int a;
    int c;
    void PackageLocation_SetLocObjectType(int d);
};

// @fnv 0x0067f4b0
// src: XBOX_PDB 0x0067f4b0
void FUN_0067f4b0_class::PackageLocation_SetLocObjectType(int aiValue)
{
    b = 5;
    c = aiValue;
}

struct FUN_00666020
{
    void* vtbl;
    int a;
    void* b;
    void RemoveAll();
    void Init();
};
extern "C" void _NiFreeAlias(void*);
// @fnv 0x00666020
void FUN_00666020::Init()
{
    *(const char**)this = "pbf";
    RemoveAll();
    _NiFreeAlias(b);
}

struct S6
{
    short a;
    short b;
    short c;
};
// Copies each S6 element from the range [a1, a2) into consecutive elements starting at a3, returning the advanced destination pointer.
// @fnv 0x00660030
S6* __cdecl CopyTripleShorts(S6* apBegin, S6* apEnd, S6* apDest)
{
    for (; apBegin != apEnd; ++apDest, ++apBegin)
        *apDest = *apBegin;
    return apDest;
}

struct FUN_00661d40_shell
{
    void __thiscall SetVTableAndDestroy();
    void* __thiscall FUN_00661d60(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// @fnv 0x00661d60
void* __thiscall FUN_00661d40_shell::FUN_00661d60(unsigned int flags)
{
    this->SetVTableAndDestroy();
    if (flags & 1)
        _delete(this, 8);
    return this;
}

extern const char* DAT_0119b49c[];
// @fnv 0x00661da0
// src: COMMUNITY 0x00661da0
const char* BSFaceGenManager_GetCustomMorphText(int i)
{
    return DAT_0119b49c[i];
}

struct StatisticalArray
{
    int _pad[3];
    int m_base;
    unsigned int __thiscall EvaluateValue_0065cc30();
    int __thiscall GetElementChecked_00662890(unsigned int);
};
unsigned int __cdecl FUN_00ec7c56();
// Bounds-checks index a against the array count, then returns m_base plus a times 0x38.
// @fnv 0x00662890
// src: GUESS 0x00662890 (confidence: medium)
int __thiscall StatisticalArray::GetElementChecked_00662890(unsigned int uiIndex)
{
    if (uiIndex >= EvaluateValue_0065cc30())
        FUN_00ec7c56();
    do
    {
    } while (0);
    return uiIndex * 0x38 + m_base;
}

void __cdecl Deallocate(void* p);

struct FUN_00665c80_Class
{
    void __thiscall FUN_00665fc0();
    void* __thiscall FUN_00665c80(unsigned int flags);
};

// Calls FUN_00665fc0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00665c80
void* __thiscall FUN_00665c80_Class::FUN_00665c80(unsigned int flags)
{
    FUN_00665fc0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct Inner0080
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual int Func(int a, int b);
};
struct FUN_00665f20_Holder
{
    Inner0080* p;
    void __thiscall AdvanceState(int a);
    void __thiscall CallInnerFuncAndForward(int a);
};
// Calls the inner object's Func with a twice, then passes the result to AdvanceState.
// @fnv 0x00665f20
void __thiscall FUN_00665f20_Holder::CallInnerFuncAndForward(int a)
{
    AdvanceState(p->Func(a, a));
}

void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void* dest, int value, unsigned int count);
extern int $SG6086;
struct FUN_00665f50_Class
{
    int* vtbl;
    int count;
    int* data;
    int zero;
    void* __thiscall NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectTREE_NiPointer_BSTreeModel_NiTMapBase(int a);
};
// @fnv 0x00665f50
// src: EXE 0x00665f50
void* __thiscall FUN_00665f50_Class::NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectTREE_NiPointer_BSTreeModel_NiTMapBase(int aiCount)
{
    vtbl = &$SG6086;
    count = aiCount;
    zero = 0;
    unsigned int size = count * 4;
    data = (int*)_NiMalloc(size);
    memset(data, 0, count * 4);
    return this;
}

struct FUN_006661b0_Class
{
    void __thiscall FUN_006661e0();
    void* __thiscall FUN_006661b0(unsigned int flags);
};

// @fnv 0x006661b0
void* __thiscall FUN_006661b0_Class::FUN_006661b0(unsigned int flags)
{
    FUN_006661e0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct FUN_00666270_Holder
{
    void* __thiscall InitAndMaybeDeallocate(unsigned int);
};
// Calls Init on this object, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00666270
void* __thiscall FUN_00666270_Holder::InitAndMaybeDeallocate(unsigned int flags)
{
    ((FUN_00666020*)this)->Init();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl ReleaseEntries_006665c0();
void __cdecl Deallocate(void*);
struct FUN_00666570_Class
{
    void __thiscall ReleaseEntries_006665c0();
    void* __thiscall FUN_00666570(unsigned int flags);
};
// Calls FUN_006665c0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00666570
void* __thiscall FUN_00666570_Class::FUN_00666570(unsigned int flags)
{
    ReleaseEntries_006665c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct T_
{
    void SetValue(void*);
};
struct FUN_0066c9c0_Class
{
    T_ a;
    T_ b;
    void hkContactPoint_set(T_& x, T_& y, float f);
};
// @fnv 0x0066c9c0
// src: XBOX_PDB 0x0066c9c0
void FUN_0066c9c0_Class::hkContactPoint_set(T_& x, T_& y, float afValue)
{
    a.SetValue(&x);
    ((T_*)((char*)&a) + 16)->SetValue(&y);
    ((bhkCharacterController*)((char*)&a + 16))->GetVectorElement(3) = afValue;
}

struct Date
{
    ~Date();
};
struct FUN_0066da50 : Date
{
    ~FUN_0066da50();
    void hkArray_hkVector4_hkContainerHeapAllocator_clearAndDeallocate();
};
// @fnv 0x0066da50
FUN_0066da50::~FUN_0066da50()
{
    hkArray_hkVector4_hkContainerHeapAllocator_clearAndDeallocate();
}

struct H_A100
{
    void* GetSizeMasked();
};
struct H_6db70
{
    void hkMemoryAllocator_bufFree_hkpRootCdBodyPair(void* a, void* b);
};
struct FUN_0066dae0_Class
{
    void* p;
    unsigned int pad;
    unsigned int state;
    void __thiscall DestroyRange();
    void __thiscall hkArrayBase_hkVector4_clearAndDeallocate(void* a);
};
// @fnv 0x0066dae0
// src: XBOX_PDB 0x0066dae0
void __thiscall FUN_0066dae0_Class::hkArrayBase_hkVector4_clearAndDeallocate(void* pTarget)
{
    DestroyRange();
    if (!(state & 0x80000000))
        ((H_6db70*)pTarget)->hkMemoryAllocator_bufFree_hkpRootCdBodyPair(p, ((H_A100*)this)->GetSizeMasked());
    p = 0;
    state = 0x80000000;
}

namespace fnv_0066db30 {
struct T_
{
    void SetValue(void* a);
};
// Calls FUN_004a3f10 with c on each of b 16-byte elements starting at a.
// @fnv 0x0066db30
// src: GUESS 0x0066db30 (confidence: medium)
void Runtime_AssignVectorValueToElements(void** apElements, int iCount, void* c)
{
    for (int i = 0; i < iCount; ++i)
        ((T_*)((char*)apElements + i * 16))->SetValue(c);
}
}  // namespace fnv_0066db30

struct FUN_0066db70_Class
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4(int, int)
    {}
    void __thiscall hkMemoryAllocator_bufFree_hkpRootCdBodyPair(int a, int b);
};
// Calls the virtual v4 with a and b shifted left by 4 bits; the local t is set to 0x10 and unused.
// @fnv 0x0066db70
// src: XBOX_PDB 0x0066db70
void __thiscall FUN_0066db70_Class::hkMemoryAllocator_bufFree_hkpRootCdBodyPair(int a, int b)
{
    int t = 0x10;
    this->v4(a, b << 4);
}

void __cdecl Deallocate(void* p);
struct FUN_0066df40_Class
{
    void __thiscall ClearEffectsAndRegisterOwner();
    void* __thiscall FUN_0066e300(unsigned int flags);
};
// Calls FUN_0066df40, frees this with Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0066e300
void* __thiscall FUN_0066df40_Class::FUN_0066e300(unsigned int flags)
{
    ClearEffectsAndRegisterOwner();
    if (flags & 1)
        Deallocate(this);
    return this;
}

// @fnv 0x00671a70
// src: COMMUNITY 0x00671a70
void TESPackage::SandboxSetLocationIsLinkedRef(bool set)
{
    set ? *reinterpret_cast<unsigned short*>(&specificFlags) |= 0x40 : *reinterpret_cast<unsigned short*>(&specificFlags) &= ~0x40;
}

// @fnv 0x00671ad0
// src: COMMUNITY 0x00671ad0
void __thiscall TESPackage::SandboxSetAllowEating(bool a)
{
    a ? *reinterpret_cast<unsigned short*>(&specificFlags) &= ~1 : *reinterpret_cast<unsigned short*>(&specificFlags) |= 1;
}


// Sets or clears bit 1 of the 16-bit field at offset 0x24 based on the boolean argument.
// @fnv 0x00671b30
// src: COMMUNITY 0x00671b30
void TESPackage::SandboxSetAllowSleeping(bool a)
{
    a ? *reinterpret_cast<unsigned short*>(&specificFlags) &= 0xfffffffd : *reinterpret_cast<unsigned short*>(&specificFlags) |= 2;
}

// @fnv 0x00671b90
// src: COMMUNITY 0x00671b90
void __thiscall TESPackage::SandboxSetAllowConversation(bool b)
{
    b ? *reinterpret_cast<unsigned short*>(&specificFlags) &= ~4 : *reinterpret_cast<unsigned short*>(&specificFlags) |= 4;
}

// @fnv 0x00671bf0
// src: COMMUNITY 0x00671bf0
void __thiscall TESPackage::SandboxSetAllowIdleMarkers(bool a)
{
    a ? *reinterpret_cast<unsigned short*>(&specificFlags) &= ~8 : *reinterpret_cast<unsigned short*>(&specificFlags) |= 8;
}


// @fnv 0x00671c50
// src: COMMUNITY 0x00671c50
void __thiscall TESPackage::SandboxSetAllowFurniture(bool bSet)
{
    bSet ? *reinterpret_cast<unsigned short*>(&specificFlags) &= ~0x10 : *reinterpret_cast<unsigned short*>(&specificFlags) |= 0x10;
}


// Sets or clears bit 0x20 in the 16-bit flags field at offset 0x24 based on b.
// @fnv 0x00671cb0
void __thiscall TESPackage::SetFlag20(bool abSet)
{
    abSet ? *reinterpret_cast<unsigned short*>(&specificFlags) &= ~0x20 : *reinterpret_cast<unsigned short*>(&specificFlags) |= 0x20;
}


// @fnv 0x0067ac70
void __thiscall TESPackage::SetFlag100(bool bSet)
{
    bSet ? behaviorFlags |= 0x100 : behaviorFlags &= ~0x100;
}

struct FUN_0067ad70_cls
{
    virtual ~FUN_0067ad70_cls();
    void* __thiscall DestroyAndFree(unsigned int);
};
void __cdecl _Deallocate(void*);
// Runs the destructor, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0067ad40
void* __thiscall FUN_0067ad70_cls::DestroyAndFree(unsigned int flags)
{
    this->FUN_0067ad70_cls::~FUN_0067ad70_cls();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUNObj
{
    void __thiscall PackageLocation_SaveGame(void*);
};
struct Holder
{
    int _0;
    FUNObj* q;
    void __thiscall SaveToBuffer(void*);
};
// @fnv 0x0067b000
void __thiscall Holder::SaveToBuffer(void* apBuffer)
{
    unsigned char b;
    b = q != 0;
    ((BGSSaveFormBuffer*)apBuffer)->SaveData(&b, 1u, 0);
    if (b)
        q->PackageLocation_SaveGame(apBuffer);
}

extern int DAT_010689e4;

struct FUN_0067c3f0_Class : public FUN_0067ad20_Class
{
    unsigned char b;
    unsigned char c;
    FUN_0067c3f0_Class();
};

// Sets the vtable pointer to DAT_010689e4 and initializes b to 1 and c to 0.
// @fnv 0x0067c3f0
FUN_0067c3f0_Class::FUN_0067c3f0_Class()
{
    vtbl = &DAT_010689e4;
    b = 1;
    c = 0;
}

namespace fnv_0067d940 {
extern "C" void __cdecl Deallocate(void*);

struct FUN_0067d940_Class
{
    void __thiscall SetM();
    void* __thiscall FUN_0067d940(unsigned int flags);
};

// Calls FUN_0067d970, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0067d940
void* __thiscall FUN_0067d940_Class::FUN_0067d940(unsigned int flags)
{
    SetM();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_0067d940

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<1>);
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<2>);
struct FUN_0067eff0_Class
{
    void __thiscall PACK_LOC_FILE_Endian();
};
// @fnv 0x0067eff0
// src: XBOX_PDB 0x0067eff0
void __thiscall FUN_0067eff0_Class::PACK_LOC_FILE_Endian()
{
    BSEndian(reinterpret_cast<unsigned char*>(this) + 4, EndianSizeTag<1>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 8, EndianSizeTag<2>());
}

namespace fnv_0067ff10 {
template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<0>);
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<1>);
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<2>);

struct FUN_0067ff10_Class
{
    unsigned char d[4];
    void __thiscall OBJ_WEAP_VATS_SPECIAL_Endian();
};

// @fnv 0x0067ff10
// src: XBOX_PDB 0x0067ff10
void __thiscall FUN_0067ff10_Class::OBJ_WEAP_VATS_SPECIAL_Endian()
{
    BSEndian(&d[4], EndianSizeTag<1>());
    BSEndian(&d[8], EndianSizeTag<0>());
    BSEndian(&d[12], EndianSizeTag<2>());
}
}  // namespace fnv_0067ff10

struct FUN_0067b170
{
    int pad[4];
    unsigned char flag;
    int pad2[3];
    FUN_0067b170();
};
// If the package type is 15 or 28, lazily allocates packageData and stores b in its flag field.
// @fnv 0x00672b70
void TESPackage::SetPackageFlag(bool abFlag)
{
    if (GetPackType() == 15 || GetPackType() == 28)
    {
        FUN_0067b170* p = 0;
        if (!packageData)
        {
            p = new FUN_0067b170();
            packageData = reinterpret_cast<TESPackageData*>(p);
        }
        else
        {
            p = reinterpret_cast<FUN_0067b170*>(packageData);
        }
        p->flag = abFlag;
    }
}

void __cdecl BSEndian(unsigned char* p, EndianSizeTag<1>);

struct FUN_0067b100_Class
{
    unsigned char b0;
    unsigned char b4;
    unsigned char b0c;
    unsigned char b14;
    void __thiscall PACK_DIALOGUE_DATA_Endian();
};

// @fnv 0x0067b100
// src: XBOX_PDB 0x0067b100
void __thiscall FUN_0067b100_Class::PACK_DIALOGUE_DATA_Endian()
{
    BSEndian((unsigned char*)this, EndianSizeTag<1>());
    BSEndian((unsigned char*)this + 4, EndianSizeTag<1>());
    BSEndian((unsigned char*)this + 0x14, EndianSizeTag<1>());
    BSEndian((unsigned char*)this + 0xc, EndianSizeTag<1>());
}

extern int DAT_01268324;
struct FUN_0066d6a0 : bhkConvexShape
{
    FUN_0066d6a0(int a);
};
// @fnv 0x0066d6a0
FUN_0066d6a0::FUN_0066d6a0(int a)
{
    bhkCapsuleShape_Init_00cab820(a);
    ++DAT_01268324;
}

struct GlobalObject_0045cfe0
{
    int* Int();
};
struct Pair8
{
    GlobalObject_0045cfe0* a;
    GlobalObject_0045cfe0* b;
};
// @fnv 0x00670670
int FindPairValue(int aiThreshold, Pair8* apPairs, int aiCount)
{
    int i;
    int v = -1;
    int w8 = 0;
    for (i = 0; i < aiCount && v < 0; i++)
    {
        if (aiThreshold <= apPairs[i].a->Int()[0])
        {
            v = apPairs[i].b->Int()[0];
        }
        else
        {
            w8 = apPairs[i].b->Int()[0];
        }
    }
    return v < 0 ? w8 : v;
}

// If GetPackType() is 15 or 28, lazily allocates the object at offset 0x28 and stores value at its offset 4.
// @fnv 0x00672c40
void TESPackage::SetExtraValue(float value)
{
    if (GetPackType() == 15 || GetPackType() == 28)
    {
        FUN_0067b170* extra = 0;
        if (!*reinterpret_cast<FUN_0067b170**>(&packageData))
            *reinterpret_cast<FUN_0067b170**>(&packageData) = extra = new FUN_0067b170;
        else
            extra = *reinterpret_cast<FUN_0067b170**>(&packageData);
        *(float*)((char*)extra + 4) = value;
    }
}

#include "../../include/PackageList.h"
// @fnv 0x0067e3a0
PackageList::~PackageList()
{
    ClearPackageList();
}

// @fnv 0x00660400
template <class T> struct BSSimpleList;
// src: GUESS 0x00660400 (confidence: medium)
BSSimpleList<int>* BSSimpleList_GetNext_Thunk(BSSimpleList<int>* a)
{
    return a->GetNext();
}

void* __cdecl operator new(unsigned int);


struct FUN_0044d000
{
    int pad[9];
    FUN_0044d000(int a, int b, int c, int d);
};

struct FUN_00665e30_Class
{
    int pad;
    int* data;
    FUN_0044d000* __thiscall LockFreeMap_TESObjectREFR_BSTreeNode_AllocateInterface(int index);
};

// @fnv 0x00665e30
// src: COMMUNITY 0x00665e30
FUN_0044d000* __thiscall FUN_00665e30_Class::LockFreeMap_TESObjectREFR_BSTreeNode_AllocateInterface(int index)
{
    AutoMemHelper helper(6, true, "..\\BSMain\\ThreadSafeStructures.h", 398);
    return new FUN_0044d000((int)this, (int)(data + index * 3), (int)(data + index * 3 + 1),
                            (int)(data + index * 3 + 2));
}

void* __cdecl operator new(unsigned int);

struct DetectionViewData;

struct List_009e03e0
{
    void* padding[2];

    void RemoveAll();
};

struct G2 : public List_009e03e0
{
    void AddHead(DetectionViewData** value);
};



struct DetectionViewData
{
    void* formId;
    SL* list;
    unsigned char data[12];
    unsigned int value;
    int padding[3];

    DetectionViewData();
    void LoadGame(BGSLoadGameBuffer* buffer);
    void ActorCause_LoadGameBGS(BGSLoadGameBuffer* buffer);
};

// @fnv 0x0066e440
// src: COMMUNITY 0x0066e440
void DetectionViewData::ActorCause_LoadGameBGS(BGSLoadGameBuffer* buffer)
{
    buffer->ReadTypedData(data, 12);
    buffer->ReadTypedData(&value, 4);
    buffer->ReadFormIdentifier(this);

    unsigned int count = buffer->ReadElementCount();
    if (count)
    {
        if (list)
            list->RemoveAll();
        else
            list = new SL;

        for (int i = 0; i < count; ++i)
        {
            DetectionViewData* state = new DetectionViewData;
            state->LoadGame(buffer);
            list->AddHead(reinterpret_cast<SkySoundObj**>(&state));
        }
    }
}

void* __cdecl operator new(unsigned int);
void __cdecl ReportAssertionViolation(char const*, int);

struct FUN_0067caa0
{
    int m_auiShapeKeys[9];

    FUN_0067caa0();
};

// @fnv 0x00672d10
// src: XBOX_PDB 0x00672d10
Schedule206* __thiscall TESPackage::GetOrCreateUseWeaponPackageData()
{
    if (GetPackType() == 0x10)
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Package.cpp", 0x607);
    }

    FUN_0067caa0* result = 0;
    if (!packageData)
    {
        result = new FUN_0067caa0;
        packageData = reinterpret_cast<TESPackageData*>(result);
    }
    else
    {
        result = reinterpret_cast<FUN_0067caa0*>(packageData);
    }
    return reinterpret_cast<Schedule206*>(result);
}

struct C0130Iterator
{
    void* m_pkContainer;
    char* m_pPtr;
};

struct C0130ScalarPtrTag
{
};

struct C0130RangeCheckedTag
{
};

C0130ScalarPtrTag __cdecl C0130PtrCat(C0130Iterator& first, C0130Iterator& dest);
char* __cdecl C0130CheckedBase(C0130Iterator& iter);
char* __cdecl C0130CopyOpt(char* first, char* last, C0130Iterator dest, C0130ScalarPtrTag ptrCat,
                           C0130RangeCheckedTag checked);

// Copies the range between the checked base pointers of first and last into dest, passing the pointer-category tag and a range-checked tag.
// @fnv 0x00660130
// src: GUESS 0x00660130 (confidence: medium)
char* __cdecl Runtime_CopyCheckedRange(C0130Iterator first, C0130Iterator last, C0130Iterator dest)
{
    return C0130CopyOpt(C0130CheckedBase(first), C0130CheckedBase(last), dest, C0130PtrCat(first, dest),
                        C0130RangeCheckedTag());
}

struct C0190Iterator
{
    void* m_pkContainer;
    char* m_pPtr;
};

struct C0190ScalarPtrTag
{
};

struct C0190RangeCheckedTag
{
};

C0190ScalarPtrTag __cdecl C0190PtrCat(C0190Iterator& first, C0190Iterator& dest);
char* __cdecl C0190CheckedBase(C0190Iterator& iter);
char* __cdecl C0190CopyOpt(char* first, char* last, C0190Iterator dest, C0190ScalarPtrTag ptrCat,
                           C0190RangeCheckedTag checked);

// @fnv 0x00660190
// src: GUESS 0x00660190 (confidence: low)
char* __cdecl Runtime_EvaluateValue_00660190(C0190Iterator first, C0190Iterator last, C0190Iterator dest)
{
    return C0190CopyOpt(C0190CheckedBase(first), C0190CheckedBase(last), dest, C0190PtrCat(first, dest),
                        C0190RangeCheckedTag());
}

void __cdecl BSSimpleList_GetNext_Thunk(void* a1, unsigned char flag);

// @fnv 0x00660250
void __cdecl CallWithUninitializedFlag(void* a1)
{
    unsigned char flag;
    BSSimpleList_GetNext_Thunk(a1, flag);
}

void* operator new(unsigned int uiSize, void* pvWhere);

struct C6602B0Entry
{
    short m_sA;
    short m_sB;
    short m_sC;
};

// std::_Construct
// Copy-constructs a C6602B0Entry from kValue into the storage at pkDest using placement new.
// @fnv 0x006602b0
void CopyConstructEntry(C6602B0Entry* pkDest, const C6602B0Entry& kValue)
{
    void* pvDest = pkDest;
    ::new (pvDest) C6602B0Entry(kValue);
}

extern "C" bool __cdecl std_Move_cat_unsigned_char(void* a, void* b);
extern "C" void* __cdecl CallWithFlag(void* a);
extern "C" void __cdecl CopyConstructRange(void* a1, void* a2, void* a3, void* a4, bool a5, bool a6);
struct SpawnedFlagBox
{
    bool v;
};

// @fnv 0x006603a0
// src: GUESS 0x006603a0 (confidence: low)
extern "C" void __cdecl Object_DispatchIteratorRange_006603a0(void* a, void* b, void* c, void* d)
{
    SpawnedFlagBox flagA3 = {};
    bool flagB;
    flagB = std_Move_cat_unsigned_char(&a, &c);
    CopyConstructRange(CallWithFlag(&a), CallWithFlag(&b), c, d, flagB, flagA3.v);
}

// std::_Construct for a 0x58-byte element: copy-construct in place.

void* __cdecl operator new(unsigned int uiSize, void* pvMem);
void __cdecl operator delete(void* pvObject, void* pvMem);

struct C60490Element
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

    C60490Element(const C60490Element& kOther);
};

// Copy-constructs a C60490Element from kVal into the memory pointed to by pkPtr.
// @fnv 0x00660490
void __cdecl CopyConstructElement(C60490Element* pkPtr, const C60490Element& kVal)
{
    void* pvVptr = pkPtr;
    ::new (pvVptr) C60490Element(kVal);
}

struct FUN_006665c0_Item
{
    int unk00;
    int unk04;
    int Dispose(int flags);
};

struct FUN_006665c0_Entry
{
    int unk00;
    FUN_006665c0_Item* m_item;
};

void __cdecl FormHeapFreeAndLog_00401030(void* p);
void __cdecl _TlsFree(void* p);

struct FUN_006665c0_cls
{
    int unk00;
    void* m_04;
    FUN_006665c0_Entry* m_08;

    unsigned int GetCount();
    void ReleaseEntries_006665c0();
};

// @fnv 0x006665c0
// src: GUESS 0x006665c0 (confidence: medium)
void FUN_006665c0_cls::ReleaseEntries_006665c0()
{
    unsigned int i;
    FUN_006665c0_Item* item;
    FUN_006665c0_Item* pItemCopy;
    {
        void* pEntries;
        for (i = 0; i < GetCount(); i++)
        {
            item = m_08[i].m_item;
            pItemCopy = item;
            (void)((pItemCopy != 0) ? pItemCopy->Dispose(1) : 0);
        }
        pEntries = m_08;
        FormHeapFreeAndLog_00401030(pEntries);
    }
    _TlsFree(m_04);
}

extern const double g_dblConst;
extern int g_timerA;
extern int g_timerB;
extern unsigned char g_counter;

float* __fastcall Setting_Float_00403e20(void* obj);
int* __fastcall Setting_Int(void* obj);

struct FUN_0066ca50_cls
{
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    int unk34;
    int unk35;
    int unk36;
    int unk37;
    int unk38;
    int unk39;
    int unk40;
    int unk41;
    int unk42;
    int unk43;
    int unk44;
    int unk45;
    int unk46;
    int unk47;
    int unk48;
    int unk49;
    int unk50;
    int unk51;
    int unk52;
    int unk53;
    int unk54;
    int unk55;
    int unk56;
    int unk57;
    int unk58;
    int unk59;
    int unk60;
    float m_f4;

    bool BSTreeNode_CheckForCollision(float dt);
};

// @fnv 0x0066ca50
// src: COMMUNITY 0x0066ca50
bool FUN_0066ca50_cls::BSTreeNode_CheckForCollision(float dt)
{
    if (dt == g_dblConst)
    {
        return true;
    }
    else if (m_f4 == g_dblConst)
    {
        m_f4 = (float)((double)(dt + *Setting_Float_00403e20(&g_timerA)) +
                       (*Setting_Float_00403e20(&g_timerA) / *Setting_Int(&g_timerB)) * g_counter);
        g_counter++;
        g_counter %= *Setting_Int(&g_timerB);
        return true;
    }
    else
    {
        bool result = false;
        if (dt > m_f4)
        {
            m_f4 = dt + *Setting_Float_00403e20(&g_timerA);
            result = true;
        }
        return result;
    }
}

struct SpawnedObject
{
    int GetRefPtr();
    bool IsReady() const;
    float GetValue();
};

extern int DAT_011ca278;
extern int DAT_011dea3c;

int __cdecl ActionPoints_GetAttackAction(int a);
float __cdecl ActionPoints_GetCost(int a);
void __cdecl FUN_005e58f0(int a, int b, int c, float* d);

// Returns the object's value if it is ready, otherwise a value derived from its ref pointer, and passes it to FUN_005e58f0.
// @fnv 0x0066dce0
float __cdecl GetObjectValue(SpawnedObject* obj)
{
    int b = ActionPoints_GetAttackAction(obj ? obj->GetRefPtr() : 0);
    float f = 0.0f;
    if (obj != 0 && obj->IsReady())
    {
        f = obj->GetValue();
    }
    else
    {
        f = ActionPoints_GetCost(b);
    }
    FUN_005e58f0(0x28, DAT_011dea3c, obj ? (int)obj : DAT_011ca278, &f);
    return f;
}

extern "C" int __cdecl FUN_004019a0(void*);

struct S_0066e2b0_Class : public FUN_0066df40_Class
{
    void __thiscall ActorCause_DecRefCount();
};

// Calls FUN_004019a0 on the object at offset 0x18; if it returns 0, calls FUN_0066e300(1) on this.
// @fnv 0x0066e2b0
// src: XBOX_PDB 0x0066e2b0
void __thiscall S_0066e2b0_Class::ActorCause_DecRefCount()
{
    if (FUN_004019a0((void*)((char*)this + 0x18)) == 0)
    {
        FUN_0066df40_Class* object = this;
        FUN_0066df40_Class* first = object;

        first ? first->FUN_0066e300(1) : 0;
    }
}

struct G2;
extern G2 g_011d6124;

// Scans the list at g_011d6124 for an item whose value equals the given non-negative value and returns it, or null if not found.
// @fnv 0x0066e330
DetectionViewData* __cdecl FindStateByValue(int value)
{
    if (value < 0)
    {
        return 0;
    }
    BSSimpleList<DetectionViewData*>* node = (BSSimpleList<DetectionViewData*>*)&g_011d6124;
    while (node)
    {
        DetectionViewData* state = node->GetItem();
        if (state && state->value == (unsigned int)value)
        {
            return state;
        }
        node = node->GetNext();
    }
    return 0;
}

struct SaveItemCls
{
    void __thiscall SaveDetectionState(BGSSaveFormBuffer* buffer);
};

struct SaveNodeCls
{
    SaveItemCls** __thiscall FUN_006815c0();
    SaveNodeCls* __thiscall FUN_00726070();
};

struct DetClassCls
{
    void* m_00;
    SaveNodeCls* m_04;
    unsigned char m_08[12];
    unsigned int m_14;
    void __thiscall WriteToSaveBuffer(BGSSaveFormBuffer* buffer);
};

// @fnv 0x0066e390
void __thiscall DetClassCls::WriteToSaveBuffer(BGSSaveFormBuffer* buffer)
{
    buffer->FUN_00865e50(&this->m_08, 0xc, 0);
    buffer->FUN_00865e50(&this->m_14, 4, 0);
    buffer->FUN_00865df0(this->m_00, 0);
    unsigned int count = 0;
    unsigned int pos4 = buffer->StartVariableSizedValue();
    SaveNodeCls* node3 = this->m_04;
    while (node3 != 0)
    {
        SaveItemCls* item = *node3->FUN_006815c0();
        if (item != 0)
        {
            item->SaveDetectionState(buffer);
            count++;
        }
        node3 = node3->FUN_00726070();
    }
    buffer->SaveVariableSizedValue_00865ff0(count, pos4);
}

extern double DAT_01012060;
extern double DAT_01017a40;

class StatsGetterCls
{
  public:
    int* GetValuePtr();
};

extern StatsGetterCls DAT_011d6458;

// @fnv 0x00670700
bool __cdecl IsScaledValueAboveThreshold(float a, float b)
{
    int scaled;
    if (b > DAT_01012060)
    {
        scaled = (int)(a / b * DAT_01017a40);
    }
    else
    {
        scaled = 100;
    }
    int value = scaled;
    return value > *(&DAT_011d6458)->GetValuePtr();
}

void __cdecl BSEndian_00407a90(void* p, bool flag);
void __cdecl BSEndian_00401080(void* p, bool flag);
struct SpawnedFlag
{
    bool m_bValue;
};
struct FUN_0067ca10_cls
{
    void PACK_USE_WEAPON_DATA_PKW2_Endian();
};
// Calls FUN_00407a90 on this+6, +8 and +0xa, then FUN_00401080 on this+0xc and this+0x10, each with a zero-initialised bool.
// @fnv 0x0067ca10
// src: XBOX_PDB 0x0067ca10
void FUN_0067ca10_cls::PACK_USE_WEAPON_DATA_PKW2_Endian()
{
    SpawnedFlag a = {};
    BSEndian_00407a90((char*)this + 6, a.m_bValue);
    SpawnedFlag b = {};
    BSEndian_00407a90((char*)this + 8, b.m_bValue);
    SpawnedFlag c = {};
    BSEndian_00407a90((char*)this + 0xa, c.m_bValue);
    {
        SpawnedFlag d = {};
        BSEndian_00401080((char*)this + 0xc, d.m_bValue);
    }
    {
        SpawnedFlag e = {};
        BSEndian_00401080((char*)this + 0x10, e.m_bValue);
    }
}

// NiTMap destructor: remove all entries, then the base map destructor frees the hash table.

class F5FC0MapBase
{
  public:
    virtual ~F5FC0MapBase();
    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00665fc0 : public F5FC0MapBase
{
  public:
    virtual ~FUN_00665fc0();
};

// Destructor that calls RemoveAll to clear the hash table entries.
// @fnv 0x00665fc0
FUN_00665fc0::~FUN_00665fc0()
{
    RemoveAll();
}

// Forward the position for the given key (obtained through a stateless helper) to the erase routine.

class D9B0Container;

struct D9B0Locate
{
    void* Find(D9B0Container* pkContainer, int iKey);
};

class D9B0Container
{
  public:
    void EraseAt(void* pvPosition);
    void EraseByKey(int iKey);
};

// Finds the entry for iKey in this container and erases it at the located position.
// @fnv 0x0066d9b0
void D9B0Container::EraseByKey(int iKey)
{
    EraseAt(D9B0Locate().Find(this, iKey));
}

// Save: write the header value, every queued item, then patch the item count in at the reserved position.

class E6D0Item
{
  public:
    void Save(BGSSaveFormBuffer* pkBuffer);
};

class E6D0Node
{
  public:
    E6D0Item** GetItem();
    E6D0Node* GetNext();
};

extern int g_iE6D0Header;
extern E6D0Node g_kE6D0Items;

// Writes the E6D0 header, saves each non-null item from the g_kE6D0Items list, and patches the item count at the recorded position.
// @fnv 0x0066e6d0
void SaveE6D0Items(BGSSaveFormBuffer* pkBuffer)
{
    pkBuffer->SaveData(&g_iE6D0Header, 4, 0);
    int aiCountValue = 0;
    unsigned int uiCountPos = pkBuffer->StartVariableSizedValue();
    E6D0Node* pkNode = &g_kE6D0Items;
    while (pkNode)
    {
        E6D0Item* pkItem = *pkNode->GetItem();
        if (pkItem)
        {
            pkItem->Save(pkBuffer);
            aiCountValue++;
        }
        pkNode = pkNode->GetNext();
    }
    pkBuffer->SaveVariableSizedValue_00865ff0(aiCountValue, uiCountPos);
}

struct ComparisonEntry
{
    int PackageLocation_GetLocType();
    int GetSecondByte();
    signed char Main_GameReset();
    signed char FUN_0086a460();
};
struct ComparisonOwner
{
    ComparisonEntry* TESPackage_GetPackageSchedule();
    int CompareTo(ComparisonEntry* other);
};

// Compares this entry against other by four key getters in order, treating -1 as unset, and returns -1, 0 or 1.
// @fnv 0x00678a80
int ComparisonOwner::CompareTo(ComparisonEntry* other)
{
    ComparisonEntry* entry = TESPackage_GetPackageSchedule();
    if ((entry->PackageLocation_GetLocType() == -1 && other->PackageLocation_GetLocType() == -1) || entry->PackageLocation_GetLocType() == other->PackageLocation_GetLocType())
    {
        if ((entry->Main_GameReset() == 0 && other->Main_GameReset() == -1) ||
            entry->Main_GameReset() == other->Main_GameReset())
        {
            if ((entry->GetSecondByte() == -1 && other->GetSecondByte() == -1) ||
                entry->GetSecondByte() == other->GetSecondByte())
            {
                if ((entry->FUN_0086a460() == -1 && other->FUN_0086a460() == -1) ||
                    entry->FUN_0086a460() == other->FUN_0086a460())
                {
                    return 0;
                }
                else
                {
                    if (entry->FUN_0086a460() != -1 &&
                        (other->FUN_0086a460() == -1 || entry->FUN_0086a460() < other->FUN_0086a460()))
                    {
                        return -1;
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
            else
            {
                if (entry->GetSecondByte() != -1 &&
                    (other->GetSecondByte() == -1 || entry->GetSecondByte() < other->GetSecondByte()))
                {
                    return -1;
                }
                else
                {
                    return 1;
                }
            }
        }
        else
        {
            if (entry->Main_GameReset() != -1 &&
                (other->Main_GameReset() == -1 || entry->Main_GameReset() < other->Main_GameReset()))
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }
    else
    {
        if (entry->PackageLocation_GetLocType() != -1 &&
            (other->PackageLocation_GetLocType() == -1 || entry->PackageLocation_GetLocType() < other->PackageLocation_GetLocType()))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
}

TESForm* __cdecl TESForm_GetFormByNumericID(void* p);
struct E640Item
{
    void __thiscall ResolveActorFormId();
};
struct E640Cls : DetClassCls
{
    void __thiscall ActorCause_InitItem(BGSSaveFormBuffer* buffer);
};
// Resolves m_00 to an Actor via dynamic_cast and calls ResolveActorFormId on each item found while walking the m_04 node list.
// @fnv 0x0066e640
// src: COMMUNITY 0x0066e640
void E640Cls::ActorCause_InitItem(BGSSaveFormBuffer* buffer)
{
    m_00 = m_00 ? dynamic_cast<Actor*>(TESForm_GetFormByNumericID(m_00)) : 0;
    SaveNodeCls* n = m_04;
    while (n)
    {
        SaveItemCls* it = *n->FUN_006815c0();
        if (it)
            ((E640Item*)it)->ResolveActorFormId();
        n = n->FUN_00726070();
    }
}

struct S_00660510_Context
{
    void __thiscall ConstructInPlace_Thunk(int dest, int src);
    void __thiscall ForwardCall_0065ea40(int element);
};

// @fnv 0x00660510
// src: GUESS 0x00660510 (confidence: low)
int __cdecl Runtime_ProcessEntries_00660510(int first, int last, int dest, S_00660510_Context* context)
{
    int start = dest;

    try
    {
        for (; first != last; dest += 0x1c, first += 0x1c)
        {
            context->ConstructInPlace_Thunk(dest, first);
        }
    }
    catch (...)
    {
        for (; start != dest; start += 0x1c)
        {
            context->ForwardCall_0065ea40(start);
        }

        throw;
    }

    return dest;
}

struct Elem6605
{
    char m_data[0x58];
};
struct Alloc6605
{
    void CopyConstructElement_Thunk(Elem6605* pDest, const Elem6605& kSrc);
    void ForwardCall_0065ea60(Elem6605* pElem);
};
struct NonscalarTag6605
{
};
struct CheckedTag6605
{
};

namespace std6605 {
// @fnv 0x006605d0
Elem6605* __cdecl CopyConstructRange(Elem6605* _First, Elem6605* _Last, Elem6605* _Dest, Alloc6605& _Al,
                                     NonscalarTag6605, CheckedTag6605)
{
    Elem6605* _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
            _Al.CopyConstructElement_Thunk(_Dest, *_First);
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
            _Al.ForwardCall_0065ea60(_Next);
        throw;
    }
    return _Dest;
}
}

float __cdecl ActionPoints_GetCost(int value);
float* __fastcall Setting_Float_00403e20(void* object);
extern unsigned char DAT_011d5f88;

// Returns FUN_0066dc70(value), multiplied by the value from FUN_00403e20(&DAT_011d5f88) unless unscaled is set.
// @fnv 0x0066dca0
// src: COMMUNITY 0x0066dca0
float __cdecl GetRequiredAPForAction(int value, bool unscaled)
{
    float baseValue = ActionPoints_GetCost(value);
    if (!unscaled)
    {
        return baseValue * *Setting_Float_00403e20(&DAT_011d5f88);
    }
    else
    {
        return baseValue;
    }
}

extern NiPoint3 DAT_011f426c;

struct SaveNodeExtended : SaveNodeCls
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    ~SaveNodeExtended();
};

struct DetClassExtended : DetClassCls
{
    void ClearAndReset();
};

// @fnv 0x0066e200
void DetClassExtended::ClearAndReset()
{
    m_00 = 0;
    while (m_04 && !reinterpret_cast<SaveNodeExtended*>(m_04)->FUN_008256d0())
    {
        SaveItemCls* item = *m_04->FUN_006815c0();
        FormHeapFreeAndLog_00401030(item);
        reinterpret_cast<SaveNodeExtended*>(m_04)->FUN_0063f7b0();
    }

    delete reinterpret_cast<SaveNodeExtended*>(m_04);
    m_04 = 0;
    *reinterpret_cast<NiPoint3*>(m_08) = DAT_011f426c;
}

extern "C" void __cdecl Runtime_ProcessEntries_00660510(void* first, void* last, void* destCont, void* destPtr, bool ptrCat, bool checked);

// copy-style dispatch: unwrap both source iterators, classify the pointer pair, forward to the worker
// Computes a pointer-category flag from first and destCont, then forwards to FUN_00660510 with a zeroed SpawnedFlagBox.
// @fnv 0x00660340
// src: GUESS 0x00660340 (confidence: low)
extern "C" void __cdecl Object_DispatchIteratorRange_00660340(void* first, void* last, void* destCont, void* destPtr)
{
    SpawnedFlagBox checked = {};
    bool ptrCat = std_Move_cat_unsigned_char(&first, &destCont);
    Runtime_ProcessEntries_00660510(CallWithFlag(&first), CallWithFlag(&last), destCont, destPtr, ptrCat, checked.v);
}

struct FUN_006e6da0
{
    int a;
};
void* __cdecl operator new(unsigned int uiSize, FUN_006e6da0* pPlace);
inline void __cdecl operator delete(void*, FUN_006e6da0*)
{}
class FUN_0065fa80
{
  public:
    FUN_0065fa80(int a);
    int unk[7];
};
// Places a FUN_0065fa80 object at pMem via placement new, passing a to its constructor.
// @fnv 0x00660410
void __cdecl ConstructInPlace(void* pMem, int a)
{
    FUN_006e6da0* pPlace = (FUN_006e6da0*)pMem;
    new (pPlace) FUN_0065fa80(a);
}

struct ElemD9E0
{
    int unk00[4];
};

struct TagD9E0
{
};

void __cdecl ResizeAudioStream(void* pAlloc, void* pArray, int iElemSize);
void __cdecl Runtime_AssignVectorValueToElements(ElemD9E0* pDest, int iCount, const ElemD9E0& kVal, TagD9E0 kTag);

// local form of hkArrayBase: 0x0066d9e0 needs the /Od append/capacity split with the call at 0x0062a100; the shared form changes bytes.
class ArrD9E0
{
  public:
    ElemD9E0* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetSizeMasked();
    void PushBack(void* pAlloc, const ElemD9E0& kVal);
};

// Appends kVal to the array, resizing the backing buffer via ResizeAudioStream when the size reaches capacity.
// @fnv 0x0066d9e0
void ArrD9E0::PushBack(void* pAlloc, const ElemD9E0& kVal)
{
    if (m_iElementCount == GetSizeMasked())
        ResizeAudioStream(pAlloc, this, 0x10);
    Runtime_AssignVectorValueToElements(m_data + m_iElementCount, 1, kVal, TagD9E0());
    m_iElementCount++;
}

struct FUN_004a4840_class
{
    char pad;
    void* __thiscall hkContainerHeapAllocator_get(int);
};

// Calls FUN_0066dae0 on this with the result of FUN_004a4840, called on a zeroed local object with this cast to int.
// @fnv 0x0066dab0
// src: XBOX_PDB 0x0066dab0
void FUN_0066da50::hkArray_hkVector4_hkContainerHeapAllocator_clearAndDeallocate()
{
    FUN_004a4840_class obj = {};
    ((FUN_0066dae0_Class*)this)->hkArrayBase_hkVector4_clearAndDeallocate(obj.hkContainerHeapAllocator_get((int)this));
}

struct FUN_00660070_cls
{
    void PrintDebugMessage_Thunk(int a);
    void CopyConstructEntry_Thunk(int a, int b);
};

// Copies 6-byte elements in [a1, a2) to a3 via a4->FUN_006601f0; on exception calls a4->FUN_0065e9a0 on those already copied; returns the new dest end.
// @fnv 0x00660070
int __cdecl CopyRange(int apSrc, int apEnd, int apDst, FUN_00660070_cls* a4)
{
    int pRollback = apDst;
    try
    {
        for (; apSrc != apEnd; apDst += 6, apSrc += 6)
        {
            a4->CopyConstructEntry_Thunk(apDst, apSrc);
        }
    }
    catch (...)
    {
        for (; pRollback != apDst; pRollback += 6)
        {
            a4->PrintDebugMessage_Thunk(pRollback);
        }
        throw;
    }
    return apDst;
}

namespace fnv_0066df40 {
void __cdecl _Deallocate(void*);

class B6DF40Effect;

class B6DF40List
{
  public:
    ~B6DF40List();

    bool IsEmpty();
    B6DF40Effect** GetItem();
    void RemoveHead();
};


extern BGSSaveLoadGame* g_BGSSaveLoadGame;

class B6DF40Owner;

class B6DF40Registry
{
  public:
    void Add(B6DF40Owner* const& pkOwner);
};

extern B6DF40Registry g_011d6124;

class B6DF40Owner
{
  public:
    void ClearEffectsAndRegisterOwner();

    int m_iArrayLength;
    B6DF40List* m_pkEffects;
    int unk08;
    int unk0C;
    int unk10;
    int m_iRefID;
};

// Frees all effects in m_pkEffects, then registers this owner with g_011d6124 unless loading a save with m_iRefID of -1.
// @fnv 0x0066df40
// src: GUESS 0x0066df40 (confidence: medium)
void B6DF40Owner::ClearEffectsAndRegisterOwner()
{
    m_iArrayLength = 0;
    while (m_pkEffects && !m_pkEffects->IsEmpty())
    {
        B6DF40Effect* pkEffect = *m_pkEffects->GetItem();
        _Deallocate(pkEffect);
        m_pkEffects->RemoveHead();
    }
    delete m_pkEffects;
    m_pkEffects = 0;
    bool bRegister = true;
    if (g_BGSSaveLoadGame->IsLoading() && m_iRefID == -1)
        bRegister = false;
    if (bRegister)
        g_011d6124.Add(this);
}
}  // namespace fnv_0066df40

extern int DAT_01068a64;
extern float DAT_010162c0;

struct S_0067caa0_Foo
{
    int* vtbl;
    int unk04;
    int unk08;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char unk10;
    unsigned char unk11;
    unsigned short unk12;
    unsigned short unk14;
    unsigned short unk16;
    float unk18;
    float unk1c;
    int unk20;

    void __thiscall FUN_0067ad20();
    S_0067caa0_Foo* __thiscall InitializeFields_0067caa0();
};

// Calls FUN_0067ad20, sets vtbl to DAT_01068a64, initializes the listed fields to constants (unk1c from DAT_010162c0), and returns this.
// @fnv 0x0067caa0
// src: GUESS 0x0067caa0 (confidence: low)
S_0067caa0_Foo* __thiscall S_0067caa0_Foo::InitializeFields_0067caa0()
{
    FUN_0067ad20();

    vtbl = &DAT_01068a64;
    unk04 = 0;
    unk08 = 0;
    unk20 = 0;
    unk0c = 0;
    unk0d = 0;
    unk0e = 1;
    unk0f = 1;
    unk10 = 0;
    unk11 = 0;
    unk12 = 1;
    unk14 = 1;
    unk16 = 6;
    unk18 = 1.0f;
    unk1c = DAT_010162c0;

    return this;
}
