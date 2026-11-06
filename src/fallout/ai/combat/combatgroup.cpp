#include "../../../../include/SettingT.h"
#include "../../../../include/CombatState.h"
#include "../../../../include/CombatManager.h"
#include "../../../../include/ActorCombatGroup.h"
#include "../../../../include/CombatSearchDoor.h"
#include "../../../../include/CombatTarget.h"
// NiPoint3_helper_combatgroup: local type (was include/NiPoint3_helper.h, which had no evidence of one real class); its methods are 0x00439ef0 NiPoint3::operator-
#include "../../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
// In-class bodies of the former NiPoint3_ext stand-in.
inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const
{
    return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const
{
    return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z);
}
inline float NiPoint3::operator*(const NiPoint3& point) const
{
    return x * point.x + y * point.y + z * point.z;
}
inline NiPoint3 operator*(float scalar, const NiPoint3& point)
{
    return NiPoint3(scalar * point.x, scalar * point.y, scalar * point.z);
}

class NiPoint3_helper_combatgroup
{
  public:
    float x;
    float y;
    float z;

    NiPoint3 operator*(float scalar) const;
    NiPoint3 FUN_00439ef0(const NiPoint3& point) const;
};
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPoint3.h"
// 0x00575650 writes the four-float stack output consumed by the location evaluator.
struct EventPositionOutput_00575650 { float x, y, z, w; };
#include "../../../../include/CombatController.h"
#include "../../../../include/BSSimpleArray.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/Actor.h"
#include "../../../../include/BGSCameraPath.h"
#include "../../../../include/CombatTargetTimestamp.h"
#include "../../../../include/MobileObject.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/PathingSolution.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/Setting.h"
#include "../../../../include/Sky.h"
#include "../../../../include/SkyObject.h"
#include "../../../../include/TESCombatStyle.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TimeoutTimer.h"
#include "../../../../include/PathingAvoidNodeArray.h"

// src/fallout/ai/combat/combatgroup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatgroup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00985980_shell
{
    float f0;
    float f4;
    float f8;
    float fc;
    void* p10;
    void CopyFrom(FUN_00985980_shell* other);
};

// Copies f8, fc and p10 from another instance into this one.
// @fnv 0x00985980
void FUN_00985980_shell::CopyFrom(FUN_00985980_shell* other)
{
    f8 = other->f8;
    fc = other->fc;
    p10 = other->p10;
}

struct ArrHelper
{
    bool FUN_0076b610() const;
};

struct FUN_00986c40_shell
{
    char pad[0x18];
    ArrHelper arr;
    bool FUN_00986c40() const;
};

// @fnv 0x00986c40
bool FUN_00986c40_shell::FUN_00986c40() const
{
    return arr.FUN_0076b610();
}

struct FUN_0096a2b0_stub
{
    void FUN_0096a2b0(int state);
};

void FUN_0096a2b0_stub::FUN_0096a2b0(int state)
{}

struct FUN_009871c0_shell
{
    void FUN_009871c0(int state);
};

// @fnv 0x009871c0
void FUN_009871c0_shell::FUN_009871c0(int state)
{
    ((FUN_0096a2b0_stub*)((char*)this + 8))->FUN_0096a2b0(state);
}

extern double _gModifierZero;

struct FUN_009871e0_shell
{
    bool __thiscall IsModifierZero();
};

// Returns whether the float at offset 0x5c of this object equals _gModifierZero.
// @fnv 0x009871e0
bool __thiscall FUN_009871e0_shell::IsModifierZero()
{
    return (*(float*)((char*)this + 0x5c)) == _gModifierZero;
}

// Exe 0x009877c0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct CombatgroupOffset08View
{
    unsigned int GetFlags();
};

struct FUN_009877c0_shell : CombatgroupOffset08View
{
    unsigned int GetFlagsFromSubobject();
};

// @fnv 0x009877c0
unsigned int FUN_009877c0_shell::GetFlagsFromSubobject()
{
    return ((CombatgroupOffset08View*)((char*)this + 0x138))->GetFlags();
}

struct GlobalObject_00869f00
{
    void Clear(bool);
};

struct FUN_009877e0_shell
{
    void ClearGlobalObject();
};

// @fnv 0x009877e0
void FUN_009877e0_shell::ClearGlobalObject()
{
    ((GlobalObject_00869f00*)((char*)this + 0x138))->Clear(true);
}

struct FUN_00987800_shell
{
    char GetByteAtOffset154();
};

// @fnv 0x00987800
char FUN_00987800_shell::GetByteAtOffset154()
{
    return ((char*)this)[0x154];
}

namespace fnv_00988750 {
// Exe 0x00988750: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct CombatgroupOffset08View
{
    unsigned int GetFlags() const;
};

struct FUN_00988750_shell
{
    unsigned int GetFlags() const;
};

// @fnv 0x00988750
unsigned int FUN_00988750_shell::GetFlags() const
{
    return ((CombatgroupOffset08View*)(this + 0x110))->GetFlags();
}
}  // namespace fnv_00988750

struct FUN_0098ebc0_obj
{
    void __thiscall GetElementAt(int a1);
};

struct FUN_00988770_shell
{
    void __thiscall ForwardToMember(int a1);
};

// @fnv 0x00988770
void __thiscall FUN_00988770_shell::ForwardToMember(int a1)
{
    ((FUN_0098ebc0_obj*)((char*)this + 0x110))->GetElementAt(a1);
}

struct BSSimpleArray_NavMeshSearchNode
{
    void FUN_006dad90(unsigned int) const;
};

struct FUN_00988790_shell
{
    char pad[0x18];
    BSSimpleArray_NavMeshSearchNode m_aiIndexedValues;
    void FUN_00988790(unsigned int idx) const;
};

// @fnv 0x00988790
void FUN_00988790_shell::FUN_00988790(unsigned int auiIndex) const
{
    m_aiIndexedValues.FUN_006dad90(auiIndex);
}

// Calls FUN_009865d0 with arg; if it returns non-null, returns byte at offset 0x64, otherwise 0.
// @fnv 0x009891a0
unsigned char __thiscall ActorCombatGroup::GetByteAtOffset100(int arg)
{
    void* result = FUN_009865d0(arg);
    if (result)
        return ((unsigned char*)result)[0x64];
    return 0;
}

struct FUN_0098a310_shell
{
    int m_field;
    int __thiscall GetFieldOrZero(int param);
};

struct FUN_009865f0_stub
{
    int m_kPointA;
    int m_field;
    FUN_009865f0_stub* __thiscall FUN_009865f0(int param);
};

// Calls FUN_009865f0 with param and returns the resulting object's m_field, or 0 if the call returns null.
// @fnv 0x0098a310
int __thiscall FUN_0098a310_shell::GetFieldOrZero(int param)
{
    FUN_009865f0_stub* result = reinterpret_cast<FUN_009865f0_stub*>(this)->FUN_009865f0(param);
    if (result)
        return result->m_field;
    return 0;
}

struct FUN_009865f0_shell
{
    int __thiscall FUN_009865f0(int a1);
};

int __thiscall FUN_009865f0_shell::FUN_009865f0(int a1)
{
    return 0;
}

struct FUN_0098a360_shell
{
    void __thiscall FUN_0098a360(int a1, int a2);
};

// Calls FUN_009865f0 with a1; if it returns non-null, stores a2 at offset 4 of the result.
// @fnv 0x0098a360
void __thiscall FUN_0098a360_shell::FUN_0098a360(int a1, int a2)
{
    int v1 = ((FUN_009865f0_shell*)this)->FUN_009865f0(a1);
    if (v1 != 0)
        *(int*)(v1 + 4) = a2;
}



struct FUN_0098de60_shell
{
    unsigned char pad[0x138];
    BSSimpleArray<unsigned int> arr;  // +0x138
    int GetArrayItem(char index);
};

// Returns 0 if index is negative, otherwise returns the element at index from arr.
// @fnv 0x0098de60
int FUN_0098de60_shell::GetArrayItem(char index)
{
    if (index < 0)
        return 0;
    return arr.GetAt(index);
}

extern int DAT_0108d6f4;

struct FUN_0098ed30_class
{
    void* vtable;
    void FUN_0098fab0(int a, int b);
    void* FUN_0098ed30();
};

// Sets the vtable to DAT_0108d6f4, calls FUN_0098fab0 with 0 and 0, and returns this.
// @fnv 0x0098ed30
void* FUN_0098ed30_class::FUN_0098ed30()
{
    vtable = &DAT_0108d6f4;
    FUN_0098fab0(0, 0);
    return this;
}

struct FUN_0098efa0_shell
{
    void* __thiscall FUN_0098efa0(int count);
};

// Allocates a byte array of count * 0x68 bytes and returns the pointer.
// @fnv 0x0098efa0
void* FUN_0098efa0_shell::FUN_0098efa0(int count)
{
    return new char[count * 0x68];
}

extern "C" void* __cdecl Reallocate(void*, unsigned int);

struct FUN_0098efd0_shell
{
    void* __thiscall FUN_0098efd0(void* a, unsigned int b);
};

// @fnv 0x0098efd0
void* __thiscall FUN_0098efd0_shell::FUN_0098efd0(void* a, unsigned int b)
{
    return Reallocate(a, b * 0x68);
}

namespace fnv_0098f020 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};

extern int DAT_0108d708;

struct FUN_0098f020_shell
{
    int m_iWordAt00;
    void ResetGlobalObject();
};

// @fnv 0x0098f020
void FUN_0098f020_shell::ResetGlobalObject()
{
    m_iWordAt00 = (int)&DAT_0108d708;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_0098f020

struct FUN_00985a50_shell
{
    float f0;
    float f4;
    float f8;
    float fc;
    void* p10;
    void FUN_00985a50(BGSLoadFormBuffer* buffer, FUN_0098de60_shell* obj);
};

// @fnv 0x00985a50
void FUN_00985a50_shell::FUN_00985a50(BGSLoadFormBuffer* buffer, FUN_0098de60_shell* obj)
{
    buffer->ReadFormIdentifier(this);
    buffer->ReadTypedData((void*)(&f4), 4u);
    buffer->ReadTypedData((void*)(&f8), 4u);
    buffer->ReadTypedData((void*)(&fc), 4u);
    char c = -1;
    buffer->ReadTypedData((void*)(&c), 1u);
    if (c != -1)
        p10 = (void*)obj->GetArrayItem(c);
    else
        p10 = 0;
}

struct FUN_00985ae0_shell
{
    void __thiscall FUN_00985ae0(BGSSaveFormBuffer* buffer, int a1);
};

// Writes the object's first 0x10 bytes and the 4 bytes at offset 0x10 to the save buffer.
// @fnv 0x00985ae0
void __thiscall FUN_00985ae0_shell::FUN_00985ae0(BGSSaveFormBuffer* buffer, int aiUnused)
{
    buffer->SaveData(this, 0x10u, 0);
    buffer->SaveData((char*)this + 0x10, 4u, 0);
}

struct FUN_00985b10_shell
{
    void __thiscall FUN_00985b10(BGSLoadFormBuffer* buffer, int a2);
};
// @fnv 0x00985b10
void __thiscall FUN_00985b10_shell::FUN_00985b10(BGSLoadFormBuffer* buffer, int aiUnused)
{
    buffer->ReadTypedData((void*)(this), 0x10u);
    buffer->ReadTypedData((void*)((void*)((char*)this + 0x10)), 4u);
}





// @fnv 0x0098eec0
template <>
unsigned int __thiscall BSSimpleArray<CombatTarget>::Add(const CombatTarget& aValue)
{
    unsigned int iElementIndex = ReserveIndex();
    InitializeItems((CombatTarget*)pBuffer + iElementIndex, 1);
    *(CombatTarget*)((CombatTarget*)pBuffer + iElementIndex) = aValue;
    return iElementIndex;
}

extern int DAT_0108d708;
struct FUN_0098fbe0_shell
{
    void FUN_0098fbe0(int, int);
};
struct FUN_0098eff0_shell
{
    void* vtable;
    void* __thiscall FUN_0098eff0();
};

// Sets the vtable pointer to DAT_0108d708, calls FUN_0098fbe0 with 0, 0, and returns this.
// @fnv 0x0098eff0
void* __thiscall FUN_0098eff0_shell::FUN_0098eff0()
{
    vtable = (void*)&DAT_0108d708;
    reinterpret_cast<FUN_0098fbe0_shell*>(this)->FUN_0098fbe0(0, 0);
    return this;
}



TESForm* __cdecl _ref_004839c0(unsigned int);
struct Holder00985930
{
    unsigned int m_data;
    void __thiscall FUN_00985930(int a1, int a2);
};
// @fnv 0x00985930
void __thiscall Holder00985930::FUN_00985930(int a1, int aiUnused)
{
    *(Actor**)&m_data = m_data ? dynamic_cast<Actor*>(_ref_004839c0(m_data)) : (Actor*)0;
}

struct FUN_0098f560
{
    char data[16];
    ~FUN_0098f560();
};
struct FUN_009863b0
{
    char pad[24];
    FUN_0098f560 m18;
    FUN_0098f560 m28;
    ~FUN_009863b0();
};
// Destructor for a structure holding two 16-byte members, destroying both in turn.
// @fnv 0x009863b0
FUN_009863b0::~FUN_009863b0()
{}

// @fnv 0x009865b0
unsigned char ActorCombatGroup::FUN_009865b0(void* param)
{
    return (FUN_009865d0((int)param) != 0) ? true : false;
}

namespace fnv_009866d0 {

struct FUN_009866d0_shell
{
    bool __thiscall FUN_009866d0(Actor* target);
};
// Iterates the actors in this collection and returns false as soon as one actor fails FUN_008b0670 on target; otherwise returns true.
// @fnv 0x009866d0
bool __thiscall FUN_009866d0_shell::FUN_009866d0(Actor* target)
{
    unsigned int count = ((ActorCombatGroup*)this)->GetCount();
    for (unsigned int i = 0; i < count; ++i)
    {
        Actor* actor = ((ActorCombatGroup*)this)->GetIntAt((int)i);
        if (actor && !actor->FUN_008b0670(target))
            return false;
    }
    return true;
}
}  // namespace fnv_009866d0

struct FUN_00986950_shell
{
    void* p0;
    int a4;
    float f8;
    float fc;
    void* p10;
    void* __thiscall FUN_00986950(void* a1);
};
// Stores a1 into p0 and resets a4 to 0, f8 and fc to -1.0, and p10 to null, then returns this.
// @fnv 0x00986950
void* __thiscall FUN_00986950_shell::FUN_00986950(void* a1)
{
    p0 = a1;
    a4 = 0;
    f8 = -1.0f;
    fc = -1.0f;
    p10 = 0;
    return this;
}

struct FUN_00986a80_shell : public FUN_009865f0_shell
{
    char __thiscall FUN_00986a80(int param);
};
// @fnv 0x00986a80
char __thiscall FUN_00986a80_shell::FUN_00986a80(int param)
{
    return (FUN_009865f0(param) != 0);
}

namespace fnv_00986aa0 {


struct FUN_005a4320_shell
{
    Actor* FUN_00968630(unsigned int);
};

struct FUN_00986aa0_shell : PathingSolution
{
    bool __thiscall FUN_00986aa0(Actor* actor);
};
// @fnv 0x00986aa0
bool __thiscall FUN_00986aa0_shell::FUN_00986aa0(Actor* actor)
{
    unsigned int count = GetVirtualNodeCount();
    for (unsigned int i = 0; i < count; ++i)
    {
        Actor* target = reinterpret_cast<FUN_005a4320_shell*>(this)->FUN_00968630(i);
        if (!actor->FUN_008b0670(target))
            return false;
    }
    return true;
}
}  // namespace fnv_00986aa0

struct FUN_009874b0_shell : ActorCombatGroup
{
    void __thiscall FUN_009874b0(int a1);
};

// Calls FUN_009865d0 with a1 to get a CombatTarget and, if non-null, increments the ushort at offset 0x4a in its m_data.
// @fnv 0x009874b0
void __thiscall FUN_009874b0_shell::FUN_009874b0(int a1)
{
    CombatTarget* pcombatTarget;
    pcombatTarget = (CombatTarget*)FUN_009865d0(a1);
    if (pcombatTarget)
        ++((unsigned short*)pcombatTarget->m_data)[0x4a / 2];
}


struct FUN_009874f0_obj
{
    void __thiscall DecrementField4A(int);
};
// Decrements the target counter at offset 0x4A when a target is found.
// @fnv 0x009874f0
void __thiscall FUN_009874f0_obj::DecrementField4A(int a1)
{
    CombatTarget* p = (CombatTarget*)reinterpret_cast<ActorCombatGroup*>(this)->FUN_009865d0(a1);
    if (p)
        (*reinterpret_cast<short*>(p->m_data + 0x4A))--;
}

struct ThreeInts_00989010
{
    int a;
    int b;
    int c;
};
struct StandIn_00989010
{
    ThreeInts_00989010 t;
    int v;
    void __thiscall SetTripleAndValue(ThreeInts_00989010* src, int val);
};
// Copies the three-int struct pointed to by src into t and stores val in v.
// @fnv 0x00989010
void __thiscall StandIn_00989010::SetTripleAndValue(ThreeInts_00989010* apTriple, int aiValue)
{
    t = *apTriple;
    v = aiValue;
}


CombatTargetTimestamp* __fastcall FUN_004300a0(CombatTargetTimestamp*);
struct MyClass
{
    int GetResultForArg(int arg);
    void UpdateTargetPerception(int a1, int a2, int* a3, CombatTargetTimestamp* a4, bool* a5, bool* a6);
};
// @fnv 0x00989040
int MyClass::GetResultForArg(int arg)
{
    int result;
    bool b1;
    // Storage is initialized by FUN_004300a0; the shared type has no default constructor.
    unsigned int stamp;
    bool b2;
    result = -100;
    FUN_004300a0(reinterpret_cast<CombatTargetTimestamp*>(&stamp));
    b1 = false;
    b2 = false;
    UpdateTargetPerception(0, arg, &result, reinterpret_cast<CombatTargetTimestamp*>(&stamp), &b1, &b2);
    return result;
}

extern float DAT_0108d540;

// Looks up the combat target for apTarget and returns its timestamp, or the negated DAT_0108d540 if none is found.
// @fnv 0x00989090
CombatTargetTimestamp ActorCombatGroup::GetLastDetectedTimestamp(Actor* apTarget)
{
    CombatTarget* pcombatTarget;
    pcombatTarget = (CombatTarget*)FUN_009865d0((int)apTarget);
    if (pcombatTarget)
        return *reinterpret_cast<CombatTargetTimestamp*>(pcombatTarget->m_data + 0x50);
    return CombatTargetTimestamp(-DAT_0108d540);
}


namespace fnv_009890e0 {


struct CoordinateTriple
{
    float _00;
    float _04;
    float _08;
    void* _0c;
    unsigned int __thiscall _ref_0084e3a0();
};
// ActorCombatGroup query at 0x009890e0; its shared header lacks GetDetectedTargetLocation.
struct DetectedTargetLocationQuery
{
    bool __thiscall GetDetectedTargetLocation(Actor* apTarget, CoordinateTriple& arLastDetectedLocation);
};
// @fnv 0x009890e0
bool __thiscall DetectedTargetLocationQuery::GetDetectedTargetLocation(Actor* apTarget, CoordinateTriple& arLastDetectedLocation)
{
    CombatTarget* pcombatTarget;
    pcombatTarget = (CombatTarget*)((ActorCombatGroup*)this)->FUN_009865d0((int)apTarget);
    if (pcombatTarget != 0)
    {
        if (((CoordinateTriple*)((char*)pcombatTarget + 0x18))->_ref_0084e3a0())
        {
            arLastDetectedLocation = *((CoordinateTriple*)((char*)pcombatTarget + 0x18));
            return true;
        }
    }
    return false;
}
}  // namespace fnv_009890e0

struct Calendar
{
    unsigned int __thiscall GetDaysPassed();
};
struct TESAmmoInitCalls
{
    unsigned int __thiscall GetFieldBC();
};
struct FUN_009891d0_class
{
    char _pad[0x28];
    int m28;
    void __thiscall FUN_009891d0(TESAmmoInitCalls* p1, Calendar* p2);
};
// @fnv 0x009891d0
void __thiscall FUN_009891d0_class::FUN_009891d0(TESAmmoInitCalls* p1, Calendar* pCalendar)
{
    unsigned int v2;
    if (m28 != 0)
    {
        unsigned int v1;
        v1 = p1->GetFieldBC();
        v2 = pCalendar->GetDaysPassed();
        if (v2 != 0)
        {
            if (((FUN_0098a310_shell*)this)->GetFieldOrZero(v1) == (int)v2)
            {
                ((FUN_0098a360_shell*)this)->FUN_0098a360(v1, 0);
            }
        }
    }
}

// The shared Actor has no returning FUN_00575650(buffer, reference, radius) overload.
struct Ref_997440
{
    int __thiscall FUN_00575650(void* a, Ref_997440* b, float c);
};
struct S989970
{
    void __thiscall FindClosestRef(int v);
    void __thiscall FUN_00989970(Ref_997440* p, float f);
};
struct B16
{
    int a;
    int b;
    int c;
    int d;
};
// @fnv 0x00989970
void __thiscall S989970::FUN_00989970(Ref_997440* apRef, float afValue)
{
    B16 b;
    FindClosestRef(apRef->FUN_00575650(&b, apRef, afValue));
}

struct FUN_0098a340_shell
{
    int __thiscall FUN_0098a340(int a1);
};
struct FUN_0098a410_shell
{
    unsigned int __thiscall GetCount();
    void* __thiscall GetIntAt(int);
    void* FindByValue(unsigned int value);
};
// @fnv 0x0098a410
void* FUN_0098a410_shell::FindByValue(unsigned int value)
{
    unsigned int count = GetCount();
    for (unsigned int i = 0; i < count; ++i)
    {
        if (((FUN_0098a340_shell*)this)->FUN_0098a340(i) == value)
            return GetIntAt(i);
    }
    return 0;
}

extern int DAT_011f18b4[];

// @fnv 0x0098e980
int __cdecl FUN_0098e980(int index)
{
    return DAT_011f18b4[index];
}

struct CombatClusterMember
{
    void* pActor;
    unsigned int m_uiGoalFlags;
    float m_fClusterOffsetX;
    float m_fClusterOffsetY;
    void* pCluster;
};

// Appends a copy of the given combat member to the array and returns the index it was stored at.
// @fnv 0x0098f180
template <>
unsigned int __thiscall BSSimpleArray<CombatClusterMember>::Add(const CombatClusterMember& aValue)
{
    unsigned int iElementIndex = ReserveIndex();
    InitializeItems(&reinterpret_cast<CombatClusterMember*>(pBuffer)[iElementIndex], 1);
    reinterpret_cast<CombatClusterMember*>(pBuffer)[iElementIndex] = aValue;
    return iElementIndex;
}


struct FUN_00985bb0_Class
{
    char _pad[16];
    CombatTargetTimestamp _ts;
    char _pad14[4];
    float _f18;
    float __thiscall FUN_00985bb0();
};
// Returns the difference between the stored _f18 value and the elapsed time from _ts.
// @fnv 0x00985bb0
float __thiscall FUN_00985bb0_Class::FUN_00985bb0()
{
    return _f18 - _ts.GetElapsedTime();
}

struct FUN_00986560_shell
{
    char pad[8];
    void __thiscall FUN_00986560(int a1);
};
struct FUN_0098ef10_shell
{
    void* __thiscall FUN_0098ef10(int a1);
    void __thiscall FUN_0098ef10(int a1, int a2);
};
struct FUN_009926e0_shell
{
    void __thiscall SwapAndDispatch(void* a, void* b);
};
extern void* BGSSaveLoadGlobalDataWorldspacePtr;
// @fnv 0x00986560
void __thiscall FUN_00986560_shell::FUN_00986560(int a1)
{
    void* v = reinterpret_cast<FUN_0098ef10_shell*>(reinterpret_cast<char*>(this) + 8)->FUN_0098ef10(a1);
    reinterpret_cast<FUN_009926e0_shell*>(BGSSaveLoadGlobalDataWorldspacePtr)
        ->SwapAndDispatch(this, *reinterpret_cast<void**>(v));
    reinterpret_cast<FUN_0098ef10_shell*>(reinterpret_cast<char*>(this) + 8)->FUN_0098ef10(a1, 1);
}


struct SearchNode
{
    TESForm* p;
};
struct MyArr : CombatgroupOffset08View
{
    SearchNode* __thiscall FUN_006dad90(unsigned int) const;
};
struct C00986670
{
    char pad[0x18];
    MyArr arr;
    SearchNode* __thiscall FUN_00986670(unsigned int);
};
// Scans arr for the first SearchNode whose p->FUN_0084e3a0() equals a1 and returns it, or 0 if none match.
// @fnv 0x00986670
SearchNode* __thiscall C00986670::FUN_00986670(unsigned int a1)
{
    unsigned int i;
    for (i = 0; i < arr.GetFlags(); i++)
    {
        SearchNode* n = arr.FUN_006dad90(i);
        if (n->p->FUN_0084e3a0() == a1)
            return n;
    }
    return 0;
}

struct FUN_00986b70_shell : ActorCombatGroup
{
    void __thiscall FUN_00986b70();
};

struct Actor_vfn
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc(bool);
};

// Iterates all entries via GetCount/GetIntAt and calls vfn_3fc(false) on each actor.
// @fnv 0x00986b70
void __thiscall FUN_00986b70_shell::FUN_00986b70()
{
    unsigned int count = ((ActorCombatGroup*)this)->GetCount();
    for (unsigned int i = 0; i < count; ++i)
    {
        Actor_vfn* actor = (Actor_vfn*)((ActorCombatGroup*)this)->GetIntAt((int)i);
        actor->vfn_3fc(false);
    }
}

class GameSettingCollection;
namespace fnv_009897a0 {


using ::SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting412;
struct Host
{
    char pad[0x50];
    CombatTargetTimestamp stamp;
    bool IsElapsedTimeBelowSetting();
};
// Returns whether stamp.GetElapsedTime() is less than the float value of originalRuntimeFloatSetting412.
// @fnv 0x009897a0
bool Host::IsElapsedTimeBelowSetting()
{
    return (double)stamp.GetElapsedTime() < *(((Setting*)&originalRuntimeFloatSetting412)->Float());
}
}  // namespace fnv_009897a0

struct FUN_0098a2e0_shell
{
    char pad[0x14c];
    int m_kPointA;
    int m_kPointB;
    bool __thiscall FUN_0098a2e0();
};

// @fnv 0x0098a2e0
bool __thiscall FUN_0098a2e0_shell::FUN_0098a2e0()
{
    if (!m_kPointB && m_kPointA)
        return true;
    return false;
}

struct CombatGroup_GetCount
{
    unsigned int __thiscall GetCount();
};
struct MyNode_0098a3c0
{
    int m0;
    int m1;
};
struct MyArr_0098a3c0
{
    MyNode_0098a3c0* __thiscall FUN_006dad90(unsigned int) const;
};
struct FUN_0098a3c0_shell
{
    char pad[0x18];
    MyArr_0098a3c0 arr;
    void __thiscall FUN_0098a3c0();
};
// Iterates over the array's nodes up to GetCount() and sets each node's m1 field to 0.
// @fnv 0x0098a3c0
void __thiscall FUN_0098a3c0_shell::FUN_0098a3c0()
{
    MyNode_0098a3c0* pNode;
    unsigned int idx;
    unsigned int cnt;
    cnt = ((CombatGroup_GetCount*)this)->GetCount();
    for (idx = 0; idx < cnt; idx++)
    {
        pNode = arr.FUN_006dad90(idx);
        pNode->m1 = 0;
    }
}

namespace fnv_0098a470 {
struct RegionPoint
{
    float GetX();
};

struct FUN_0098a470_shell
{
    char pad[0x40];
    unsigned int m_kPointA;
    RegionPoint p44;
    CombatTargetTimestamp p45;
    bool FUN_0098a470(unsigned int a, float b);
};
// @fnv 0x0098a470
bool FUN_0098a470_shell::FUN_0098a470(unsigned int a, float fTime)
{
    if (p44.GetX() == _gModifierZero)
        return true;
    if (m_kPointA != a)
        return true;
    if (((CombatTargetTimestamp*)((char*)this + 0x44))->GetElapsedTime() > fTime)
        return true;
    return false;
}
}  // namespace fnv_0098a470


struct FUN_0098c590_shell
{
    CombatSearchDoor* FindParentSpaceNode(int param);
};
struct FUN_0098c780_shell
{
    void ClearReservedFlag(int param);
};
// Looks up a CombatSearchDoor by param and clears its bReserved flag when found.
// @fnv 0x0098c780
void FUN_0098c780_shell::ClearReservedFlag(int param)
{
    CombatSearchDoor* psearchDoor = ((FUN_0098c590_shell*)this)->FindParentSpaceNode(param);
    if (psearchDoor)
        psearchDoor->bReserved = false;
}

struct FUN_0098ed60_shell : GlobalObject_00869f00
{
    void __thiscall FUN_0098ed60();
};
// @fnv 0x0098ed60
void __thiscall FUN_0098ed60_shell::FUN_0098ed60()
{
    *(void**)this = &DAT_0108d6f4;
    Clear(true);
}

struct S0098a4d0
{
    float __thiscall ComputeAverageRatio();
};
struct FUN_00990500_host
{
    S0098a4d0* p0;
    char pad[16];
    float f14;
    float __thiscall GetCachedValue();
};
// Returns f14, computing and storing it from p0->ComputeAverageRatio() first when f14 equals _gModifierZero.
// @fnv 0x00990500
float __thiscall FUN_00990500_host::GetCachedValue()
{
    if (f14 == _gModifierZero)
        f14 = p0->ComputeAverageRatio();
    return f14;
}


extern Setting originalRuntimeFloatSetting403;
extern Setting originalRuntimeFloatSetting404;
extern Setting originalRuntimeFloatSetting405;
extern Setting originalRuntimeFloatSetting406;
extern Setting originalRuntimeFloatSetting407;
extern Setting originalRuntimeFloatSetting408;
extern Setting originalRuntimeFloatSetting409;
extern Setting originalRuntimeFloatSetting410;

extern Setting g_011cef50;
struct AvoidSphere
{
    float GetRadius() const;
};
struct Flt
{
    operator unsigned int();
};
struct RegionPoint
{
    float GetX();
};
extern float DAT_0108d540;
// ActorCombatGroup view: 0x00987220 and 0x00989880 need declarations and fields absent from its shared header.
struct TargetExpiryGroupView
{
    char pad00[0xd0];
    unsigned int ItemUpdateArray;
    Flt spSphere;
    bool FUN_00987220(CombatTarget* pMember);
    void* FUN_00989880(Actor* pActor, float fRadius);
};
// @fnv 0x00987220
bool TargetExpiryGroupView::FUN_00987220(CombatTarget* pMember)
{
    if (((FUN_0098a2e0_shell*)this)->FUN_0098a2e0())
    {
        if (((CombatTargetTimestamp*)((char*)pMember + 0x50))->GetElapsedTime() > *originalRuntimeFloatSetting403.Float())
            return true;
        if (((CombatTargetTimestamp*)((char*)pMember + 0x50))->GetElapsedTime() > *originalRuntimeFloatSetting404.Float() &&
            !FUN_00989880((*reinterpret_cast<Actor**>(pMember->m_data)), *originalRuntimeFloatSetting405.Float()))
            return true;
    }
    if (((CombatTargetTimestamp*)((char*)pMember + 0x58))->GetElapsedTime() > *originalRuntimeFloatSetting406.Float())
    {
        if ((*reinterpret_cast<unsigned short*>(pMember->m_data + 0x4a)) == 0)
            return true;
        if (((CombatTargetTimestamp*)((char*)pMember + 0x58))->GetElapsedTime() > *originalRuntimeFloatSetting407.Float())
        {
            bool bnoSphere = false;
            if (ItemUpdateArray == 1 && spSphere && ((AvoidSphere*)(unsigned int)spSphere)->GetRadius() == 0.0)
                bnoSphere = true;
            if (bnoSphere || !FUN_00989880((*reinterpret_cast<Actor**>(pMember->m_data)), *originalRuntimeFloatSetting408.Float()))
                return true;
        }
    }
    if (ItemUpdateArray != 0)
    {
        if (ItemUpdateArray > (*reinterpret_cast<unsigned short*>(pMember->m_data + 0x48)) + *g_011cef50.Int())
            return true;
        if (((CombatTargetTimestamp*)((char*)this + 0xe8))->GetElapsedTime() < *originalRuntimeFloatSetting410.Float() &&
            ((CombatTargetTimestamp*)((char*)pMember + 0x60))->GetElapsedTime() >= *originalRuntimeFloatSetting410.Float() &&
            ((RegionPoint*)((char*)pMember + 0x50))->GetX() == -DAT_0108d540 &&
            ((CombatTargetTimestamp*)((char*)pMember + 0x58))->GetElapsedTime() > *originalRuntimeFloatSetting409.Float())
            return true;
    }
    if ((*reinterpret_cast<Actor**>(pMember->m_data))->FUN_00437bd0() || ((*reinterpret_cast<Actor**>(pMember->m_data))->HasHealth(false) && !(*reinterpret_cast<Actor**>(pMember->m_data))->GetIsDying()))
        return true;
    return false;
}

struct FUN_0098de30_class
{
    unsigned char FUN_0098de30(unsigned int*);
};
struct FUN_009859c0_shell
{
    void __thiscall FUN_009859c0(BGSSaveFormBuffer* buffer, FUN_0098de30_class* obj);
};
// Saves the form ID, three 4-byte fields, and a byte derived from the object at offset 16 (0xFF if null) to the buffer.
// @fnv 0x009859c0
void __thiscall FUN_009859c0_shell::FUN_009859c0(BGSSaveFormBuffer* buffer, FUN_0098de30_class* obj)
{
    buffer->SerializeFormData(*(void**)this, 0);
    buffer->SaveData((char*)this + 4, 4u, 0);
    buffer->SaveData((char*)this + 8, 4u, 0);
    buffer->SaveData((char*)this + 12, 4u, 0);
    char result = 0xFF;
    if (*(unsigned int*)((char*)this + 16))
        result = obj->FUN_0098de30(*(unsigned int**)((char*)this + 16));
    buffer->SaveData(&result, 1u, 0);
}




struct ActorV
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual const char* V130();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void* V1d0();
};

void FNV_Warning(const char*, ...);
struct S00986a80
{
    bool FUN_00986a80(ActorV*);
};
struct S00986aa0
{
    bool FUN_00986aa0(ActorV*);
};
struct S00992700
{
    void FUN_00992700(void*, ActorV*);
};

extern Setting g_011f1878;
int __cdecl FUN_005d8550(unsigned int);


void FUN_004b6360(void*, NiPoint3*, int);
struct FUN_0097f220_t
{
    void FUN_0097f220();
};
// ActorCombatGroup insertion at 0x009867d0 returns bool and accepts ActorV*, unlike its shared declaration.
struct CombatMemberInsertionView
{
    unsigned int m_uiActorFormID;
    bool FUN_009867d0(ActorV* apActor);
};

// @fnv 0x009867d0
bool CombatMemberInsertionView::FUN_009867d0(ActorV* apActor)
{
    // The original leaves this storage uninitialized until the color is copied below.
    float colorA[4];
    float color[3];
    if (!apActor)
        return false;
    if (((S00986a80*)this)->FUN_00986a80(apActor))
        return true;
    if (!((S00986aa0*)this)->FUN_00986aa0(apActor))
        return false;
    if (((ActorCombatGroup*)this)->FUN_009865b0(apActor))
    {
        FNV_Warning("COMBAT: Trying to add actor %08X %s to Combat Group member list when they are a target.",
                    ((TESForm*)apActor)->FUN_0084e3a0(),
                    ((BGSCameraPath*)apActor)->HasNameForWarning() ? apActor->V130()
                                                                   : ((MobileObject*)apActor)->GetFullName());
        return false;
    }
    {
        FUN_00986950_shell member;
        ((BSSimpleArray<CombatClusterMember>*)((char*)this + 0x18))
            ->Add(*(const CombatClusterMember*)member.FUN_00986950(apActor));
    }
    ((S00992700*)BGSSaveLoadGlobalDataWorldspacePtr)->FUN_00992700(this, apActor);
    if (*g_011f1878.Bool() && apActor->V1d0())
    {
        *reinterpret_cast<NiColorA*>(colorA) = *(NiColorA*)FUN_005d8550(m_uiActorFormID);
        reinterpret_cast<NiPoint3*>(color)->Set(colorA[0], colorA[1], colorA[2]);
        FUN_004b6360(apActor->V1d0(), reinterpret_cast<NiPoint3*>(color), 0);
    }
    ((FUN_0097f220_t*)((char*)this + 0xb0))->FUN_0097f220();
    return true;
}

struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};

struct FUN_0098f040_shell
{
    CombatClusterMember* pBuffer;
    unsigned int iSize;
    unsigned int iAllocSize;
    virtual void v0();
    virtual CombatClusterMember* Allocate(unsigned int);
    void UpdateThreat(unsigned int, unsigned int);
    void FUN_0098f040(unsigned int auiNewSize, bool abFreeMemory);
};

// Resizes the buffer to auiNewSize: clears when zero, reallocates and grows when larger than capacity, shrinks and optionally frees when smaller.
// @fnv 0x0098f040
void FUN_0098f040_shell::FUN_0098f040(unsigned int auiNewSize, bool abFreeMemory)
{
    if (!auiNewSize)
    {
        ((GlobalObject_00869f00*)this)->Clear(abFreeMemory);
    }
    else if (auiNewSize > iAllocSize)
    {
        if (!iAllocSize)
        {
            pBuffer = Allocate(auiNewSize);
            iAllocSize = auiNewSize;
        }
        else
        {
            UpdateThreat(auiNewSize, iSize);
            iAllocSize = auiNewSize;
        }
        ((BSSimpleArray<CombatClusterMember>*)this)->InitializeItems(&pBuffer[iSize], auiNewSize - iSize);
        iSize = auiNewSize;
    }
    else if (auiNewSize < iSize)
    {
        ((FUN_0072ba80_shell*)this)->FUN_0072ba80(&pBuffer[auiNewSize], iSize - auiNewSize);
        iSize = auiNewSize;
        if (abFreeMemory && auiNewSize <= iAllocSize >> 2)
        {
            UpdateThreat(auiNewSize, auiNewSize);
            iAllocSize = auiNewSize;
        }
    }
    else
    {
        ((BSSimpleArray<CombatClusterMember>*)this)->InitializeItems(&pBuffer[iSize], auiNewSize - iSize);
        iSize = auiNewSize;
    }
}

struct FUN_00986500_shell : ActorCombatGroup
{
    void FUN_00986560(int i);
    void RemoveByTarget(int target);
};
struct FUN_0096a2b0_stub2
{
    CombatTarget* FUN_0096a2b0(int i);
};
// Scans the array at this+8 for a CombatTarget whose first int equals target, then calls FUN_00986560 with that index and returns.
// @fnv 0x00986500
void FUN_00986500_shell::RemoveByTarget(int target)
{
    for (int i = 0; i < ((CombatgroupOffset08View*)((char*)this + 8))->GetFlags(); ++i)
    {
        CombatTarget* combatTarget = ((FUN_0096a2b0_stub2*)((char*)this + 8))->FUN_0096a2b0(i);
        if (*(int*)combatTarget == target)
        {
            FUN_00986560(i);
            return;
        }
    }
}



struct FUN_00986610_shell
{
    char pad[8];
    BSSimpleArray<CombatClusterMember> arr;
    void* FUN_00986610(unsigned int value);
};

// Scans the combat member array for the first member whose actor's FUN_0084e3a0 result equals value, returning it or null.
// @fnv 0x00986610
void* FUN_00986610_shell::FUN_00986610(unsigned int value)
{
    for (unsigned int i = 0; i < ((CombatgroupOffset08View*)((char*)this + 8))->GetFlags(); ++i)
    {
        CombatClusterMember* m = (CombatClusterMember*)((FUN_0098ef10_shell*)((char*)this + 8))->FUN_0098ef10(i);
        if (((TESForm*)m->pActor)->FUN_0084e3a0() == value)
            return m;
    }
    return 0;
}

struct XIdle;
struct XArr
{
    void SetAt(unsigned int, XIdle*);
};
struct _Mem_20a4
{
    void SetSize(unsigned int, bool);
};
struct FUN_00986b00_shell
{
    char pad[0x18];
    CombatgroupOffset08View arr;
    void CopyArrayTo(XArr* dst);
};
// Resizes dst to the source array's count and copies each element from arr into dst by index.
// @fnv 0x00986b00
void FUN_00986b00_shell::CopyArrayTo(XArr* dst)
{
    unsigned int i;
    ((_Mem_20a4*)dst)->SetSize(arr.GetFlags(), true);
    for (i = 0; i < arr.GetFlags(); ++i)
        dst->SetAt(i, (XIdle*)((MyArr*)&arr)->FUN_006dad90(i));
}



struct FUN_00986bd0_shell : ActorCombatGroup
{
    Actor* GetIntAt(int);
    unsigned int GetCount();
    void FUN_00986bd0();
};
// Iterates all members, calls SkyObject::Update on each with this and the member, then clears the object at offset 0x18.
// @fnv 0x00986bd0
void FUN_00986bd0_shell::FUN_00986bd0()
{
    unsigned int imemberCount = GetCount();
    for (unsigned int i = 0; i < imemberCount; ++i)
    {
        Actor* pmember = GetIntAt(i);
        reinterpret_cast<SkyObject*>(BGSSaveLoadGlobalDataWorldspacePtr)
            ->Update(reinterpret_cast<Sky*>(this), reinterpret_cast<int>(pmember));
    }
    reinterpret_cast<GlobalObject_00869f00*>(reinterpret_cast<char*>(this) + 0x18)->Clear(false);
}

class CoordinateTriple
{
  public:
    void FUN_00527b70(void* pBuffer);
};



// @fnv 0x009856e0
void CombatTarget::FUN_009856e0(CombatWriter* pBuffer, SavedCombatState* pGroup)
{
    reinterpret_cast<BGSSaveFormBuffer*>(pBuffer)->SerializeFormData(*reinterpret_cast<Actor**>(m_data), 0);

    reinterpret_cast<BGSSaveFormBuffer*>(pBuffer)->SaveData((char*)this + 4, 4u, 0);
    reinterpret_cast<BGSSaveFormBuffer*>(pBuffer)->SaveData((char*)this + 0x48, 2u, 0);
    reinterpret_cast<BGSSaveFormBuffer*>(pBuffer)->SaveData((char*)this + 0x4A, 2u, 0);
    reinterpret_cast<BGSSaveFormBuffer*>(pBuffer)->SaveData((char*)this + 0x64, 1u, 0);
    reinterpret_cast<BGSSaveFormBuffer*>(pBuffer)->SaveData((char*)this + 0x65, 1u, 0);

    ((CoordinateTriple*)((char*)this + 8))->FUN_00527b70(reinterpret_cast<BGSSaveFormBuffer*>(pBuffer));
    ((CoordinateTriple*)((char*)this + 0x18))->FUN_00527b70(reinterpret_cast<BGSSaveFormBuffer*>(pBuffer));
    ((CoordinateTriple*)((char*)this + 0x28))->FUN_00527b70(reinterpret_cast<BGSSaveFormBuffer*>(pBuffer));
    ((CoordinateTriple*)((char*)this + 0x38))->FUN_00527b70(reinterpret_cast<BGSSaveFormBuffer*>(pBuffer));

    ((CombatTargetTimestamp*)((char*)this + 0x50))->SaveTimeStamp(reinterpret_cast<BGSSaveFormBuffer*>(pBuffer));
    ((CombatTargetTimestamp*)((char*)this + 0x54))->SaveTimeStamp(reinterpret_cast<BGSSaveFormBuffer*>(pBuffer));
    ((CombatTargetTimestamp*)((char*)this + 0x58))->SaveTimeStamp(reinterpret_cast<BGSSaveFormBuffer*>(pBuffer));
    ((CombatTargetTimestamp*)((char*)this + 0x4C))->SaveTimeStamp(reinterpret_cast<BGSSaveFormBuffer*>(pBuffer));
    ((CombatTargetTimestamp*)((char*)this + 0x5C))->SaveTimeStamp(reinterpret_cast<BGSSaveFormBuffer*>(pBuffer));
    ((CombatTargetTimestamp*)((char*)this + 0x60))->SaveTimeStamp(reinterpret_cast<BGSSaveFormBuffer*>(pBuffer));
}

struct FUN_00527ba0_Class
{
    char pad[0x10];
    void __thiscall FUN_00527ba0(void* pBuffer);
};



struct FUN_00985800_shell
{
    void* pActor;
    int m4;
    FUN_00527ba0_Class m8;
    FUN_00527ba0_Class m18;
    FUN_00527ba0_Class m28;
    FUN_00527ba0_Class m38;
    char m48[2];
    char m4a[2];
    CombatTargetTimestamp m4c;
    CombatTargetTimestamp m50;
    CombatTargetTimestamp m54;
    CombatTargetTimestamp m58;
    CombatTargetTimestamp m5c;
    CombatTargetTimestamp m60;
    char m64;
    char m65;

    void __thiscall FUN_00985800(BGSLoadFormBuffer* pBuffer, ActorCombatGroup* pGroup);
};

// @fnv 0x00985800
void FUN_00985800_shell::FUN_00985800(BGSLoadFormBuffer* pBuffer, ActorCombatGroup* pGroup)
{
    pBuffer->ReadFormIdentifier(this);

    pBuffer->ReadTypedData((void*)(&m4), 4u);
    pBuffer->ReadTypedData((void*)(m48), 2u);
    pBuffer->ReadTypedData((void*)(m4a), 2u);
    pBuffer->ReadTypedData((void*)(&m64), 1u);
    pBuffer->ReadTypedData((void*)(&m65), 1u);

    m8.FUN_00527ba0(pBuffer);
    m18.FUN_00527ba0(pBuffer);
    m28.FUN_00527ba0(pBuffer);

    if (pBuffer->GetVersion() >= 0x0e)
        m38.FUN_00527ba0(pBuffer);

    reinterpret_cast<CombatTargetTimestamp*>(&m50)->LoadGame(pBuffer);
    reinterpret_cast<CombatTargetTimestamp*>(&m54)->LoadGame(pBuffer);
    reinterpret_cast<CombatTargetTimestamp*>(&m58)->LoadGame(pBuffer);
    reinterpret_cast<CombatTargetTimestamp*>(&m4c)->LoadGame(pBuffer);
    reinterpret_cast<CombatTargetTimestamp*>(&m5c)->LoadGame(pBuffer);

    if (pBuffer->GetVersion() >= 0x0d)
        reinterpret_cast<CombatTargetTimestamp*>(&m60)->LoadGame(pBuffer);
}

double DAT_0101db88;


struct FUN_00985be0_shell : public FUN_00985bb0_Class
{
    NiColorA* GetEffectColor(NiColorA* result);
};

// Reads a value from FUN_00985bb0 and returns a color: magenta above 50, blue above DAT_0101db88, otherwise yellow, all with alpha 0.5.
// @fnv 0x00985be0
NiColorA* FUN_00985be0_shell::GetEffectColor(NiColorA* result)
{
    NiColorA color(0.0f, 0.0f, 0.0f, 0.0f);

    {
        float value = FUN_00985bb0_Class::FUN_00985bb0();

        if (value > 50.0)
        {
            color = NiColorA(1.0f, 0.0f, 1.0f, 0.5f);
        }
        else if (value > DAT_0101db88)
        {
            color = NiColorA(0.0f, 0.0f, 1.0f, 0.5f);
        }
        else
        {
            color = NiColorA(1.0f, 1.0f, 0.0f, 0.5f);
        }

        *result = color;
    }

    return result;
}



void __cdecl FUN_004b6630(NiAVObject*);

struct ActorDispatchBase
{
    virtual NiAVObject* M001() = 0;
    virtual NiAVObject* M002() = 0;
    virtual NiAVObject* M003() = 0;
    virtual NiAVObject* M004() = 0;
    virtual NiAVObject* M005() = 0;
    virtual NiAVObject* M006() = 0;
    virtual NiAVObject* M007() = 0;
    virtual NiAVObject* M008() = 0;
    virtual NiAVObject* M009() = 0;
    virtual NiAVObject* M010() = 0;
    virtual NiAVObject* M011() = 0;
    virtual NiAVObject* M012() = 0;
    virtual NiAVObject* M013() = 0;
    virtual NiAVObject* M014() = 0;
    virtual NiAVObject* M015() = 0;
    virtual NiAVObject* M016() = 0;
    virtual NiAVObject* M017() = 0;
    virtual NiAVObject* M018() = 0;
    virtual NiAVObject* M019() = 0;
    virtual NiAVObject* M020() = 0;
    virtual NiAVObject* M021() = 0;
    virtual NiAVObject* M022() = 0;
    virtual NiAVObject* M023() = 0;
    virtual NiAVObject* M024() = 0;
    virtual NiAVObject* M025() = 0;
    virtual NiAVObject* M026() = 0;
    virtual NiAVObject* M027() = 0;
    virtual NiAVObject* M028() = 0;
    virtual NiAVObject* M029() = 0;
    virtual NiAVObject* M030() = 0;
    virtual NiAVObject* M031() = 0;
    virtual NiAVObject* M032() = 0;
    virtual NiAVObject* M033() = 0;
    virtual NiAVObject* M034() = 0;
    virtual NiAVObject* M035() = 0;
    virtual NiAVObject* M036() = 0;
    virtual NiAVObject* M037() = 0;
    virtual NiAVObject* M038() = 0;
    virtual NiAVObject* M039() = 0;
    virtual NiAVObject* M040() = 0;
    virtual NiAVObject* M041() = 0;
    virtual NiAVObject* M042() = 0;
    virtual NiAVObject* M043() = 0;
    virtual NiAVObject* M044() = 0;
    virtual NiAVObject* M045() = 0;
    virtual NiAVObject* M046() = 0;
    virtual NiAVObject* M047() = 0;
    virtual NiAVObject* M048() = 0;
    virtual NiAVObject* M049() = 0;
    virtual NiAVObject* M050() = 0;
    virtual NiAVObject* M051() = 0;
    virtual NiAVObject* M052() = 0;
    virtual NiAVObject* M053() = 0;
    virtual NiAVObject* M054() = 0;
    virtual NiAVObject* M055() = 0;
    virtual NiAVObject* M056() = 0;
    virtual NiAVObject* M057() = 0;
    virtual NiAVObject* M058() = 0;
    virtual NiAVObject* M059() = 0;
    virtual NiAVObject* M060() = 0;
    virtual NiAVObject* M061() = 0;
    virtual NiAVObject* M062() = 0;
    virtual NiAVObject* M063() = 0;
    virtual NiAVObject* M064() = 0;
    virtual NiAVObject* M065() = 0;
    virtual NiAVObject* M066() = 0;
    virtual NiAVObject* M067() = 0;
    virtual NiAVObject* M068() = 0;
    virtual NiAVObject* M069() = 0;
    virtual NiAVObject* M070() = 0;
    virtual NiAVObject* M071() = 0;
    virtual NiAVObject* M072() = 0;
    virtual NiAVObject* M073() = 0;
    virtual NiAVObject* M074() = 0;
    virtual NiAVObject* M075() = 0;
    virtual NiAVObject* M076() = 0;
    virtual NiAVObject* M077() = 0;
    virtual NiAVObject* M078() = 0;
    virtual NiAVObject* M079() = 0;
    virtual NiAVObject* M080() = 0;
    virtual NiAVObject* M081() = 0;
    virtual NiAVObject* M082() = 0;
    virtual NiAVObject* M083() = 0;
    virtual NiAVObject* M084() = 0;
    virtual NiAVObject* M085() = 0;
    virtual NiAVObject* M086() = 0;
    virtual NiAVObject* M087() = 0;
    virtual NiAVObject* M088() = 0;
    virtual NiAVObject* M089() = 0;
    virtual NiAVObject* M090() = 0;
    virtual NiAVObject* M091() = 0;
    virtual NiAVObject* M092() = 0;
    virtual NiAVObject* M093() = 0;
    virtual NiAVObject* M094() = 0;
    virtual NiAVObject* M095() = 0;
    virtual NiAVObject* M096() = 0;
    virtual NiAVObject* M097() = 0;
    virtual NiAVObject* M098() = 0;
    virtual NiAVObject* M099() = 0;
    virtual NiAVObject* M100() = 0;
    virtual NiAVObject* M101() = 0;
    virtual NiAVObject* M102() = 0;
    virtual NiAVObject* M103() = 0;
    virtual NiAVObject* M104() = 0;
    virtual NiAVObject* M105() = 0;
    virtual NiAVObject* M106() = 0;
    virtual NiAVObject* M107() = 0;
    virtual NiAVObject* M108() = 0;
    virtual NiAVObject* M109() = 0;
    virtual NiAVObject* M110() = 0;
    virtual NiAVObject* M111() = 0;
    virtual NiAVObject* M112() = 0;
    virtual NiAVObject* M113() = 0;
    virtual NiAVObject* M114() = 0;
    virtual NiAVObject* M115() = 0;
    virtual NiAVObject* M116() = 0;
};

struct ActorDispatch : ActorDispatchBase
{
    virtual NiAVObject* M117() = 0;
};

struct FUN_0098f1f0_caller
{
    void __thiscall RemoveEntries(unsigned int index, int flag);
};

struct FUN_009869a0_shell
{
    unsigned char pad00[0xEC];
    Actor* m_pActor;

    void FUN_009869a0(Actor* apActor);
};

// @fnv 0x009869a0
void FUN_009869a0_shell::FUN_009869a0(Actor* apActor)
{
    unsigned int i;
    CombatClusterMember* combatMember;

    for (i = 0; i < reinterpret_cast<MyArr*>(reinterpret_cast<unsigned char*>(this) + 0x18)->GetFlags(); ++i)
    {
        combatMember = reinterpret_cast<CombatClusterMember*>(
            reinterpret_cast<MyArr*>(reinterpret_cast<unsigned char*>(this) + 0x18)->FUN_006dad90(i));

        if (combatMember->pActor == apActor)
        {
            reinterpret_cast<SkyObject*>(BGSSaveLoadGlobalDataWorldspacePtr)
                ->Update(reinterpret_cast<Sky*>(this), reinterpret_cast<int>(apActor));

            reinterpret_cast<FUN_0098f1f0_caller*>(reinterpret_cast<unsigned char*>(this) + 0x18)->RemoveEntries(i, 1);

            if (*reinterpret_cast<Actor**>(reinterpret_cast<unsigned char*>(this) + 0xEC) == apActor)
                *reinterpret_cast<Actor**>(reinterpret_cast<unsigned char*>(this) + 0xEC) = 0;

            if (*g_011f1878.Bool())
            {
                if (reinterpret_cast<ActorDispatch*>(apActor)->M117())
                    FUN_004b6630(reinterpret_cast<ActorDispatch*>(apActor)->M117());
            }

            break;
        }
    }
}



struct B006815c0 : public NiPoint3
{
    B006815c0();
};





extern float _DAT_010162c0;

struct FUN_00989eb0_shell
{
    void __thiscall UpdateBoundsFromActors(B006815c0* points, int index);
    void __thiscall FUN_00989eb0(NiPoint3* result);
};

// @fnv 0x00989eb0
void FUN_00989eb0_shell::FUN_00989eb0(NiPoint3* result)
{
    B006815c0 points[8];

    this->UpdateBoundsFromActors(points, 0);

    *reinterpret_cast<NiPoint3_helper_combatgroup*>(result) = (const NiPoint3_helper_combatgroup&)(points[0] + points[7]).FUN_0053d280(_DAT_010162c0);

    NiPoint3 difference = ((NiPoint3*)&points[0])->operator-(*(NiPoint3*)&points[7]);

    ((const TESCombatStyle*)&difference)->UpdateCombatStyle();
}

struct FUN_0098a390_shell
{
    char pad[0x18];
    MyArr m_aiIndexedValues;
    void __thiscall SetElementValue(unsigned int a1, unsigned int a2);
};

// @fnv 0x0098a390
void FUN_0098a390_shell::SetElementValue(unsigned int uiIndex, unsigned int uiValue)
{
    reinterpret_cast<CombatClusterMember*>(m_aiIndexedValues.FUN_006dad90(uiIndex))->m_uiGoalFlags = uiValue;
}



namespace identity {

struct FUN_009871c0_shell
{
    CombatTarget* __thiscall FUN_009871c0(int index);
};
}

struct ActorVirtual
{
    virtual void f000();
    virtual void f001();
    virtual void f002();
    virtual void f003();
    virtual void f004();
    virtual void f005();
    virtual void f006();
    virtual void f007();
    virtual void f008();
    virtual void f009();
    virtual void f010();
    virtual void f011();
    virtual void f012();
    virtual void f013();
    virtual void f014();
    virtual void f015();
    virtual void f016();
    virtual void f017();
    virtual void f018();
    virtual void f019();
    virtual void f020();
    virtual void f021();
    virtual void f022();
    virtual void f023();
    virtual void f024();
    virtual void f025();
    virtual void f026();
    virtual void f027();
    virtual void f028();
    virtual void f029();
    virtual void f030();
    virtual void f031();
    virtual void f032();
    virtual void f033();
    virtual void f034();
    virtual void f035();
    virtual void f036();
    virtual void f037();
    virtual void f038();
    virtual void f039();
    virtual void f040();
    virtual void f041();
    virtual void f042();
    virtual void f043();
    virtual void f044();
    virtual void f045();
    virtual void f046();
    virtual void f047();
    virtual void f048();
    virtual void f049();
    virtual void f050();
    virtual void f051();
    virtual void f052();
    virtual void f053();
    virtual void f054();
    virtual void f055();
    virtual void f056();
    virtual void f057();
    virtual void f058();
    virtual void f059();
    virtual void f060();
    virtual void f061();
    virtual void f062();
    virtual void f063();
    virtual void f064();
    virtual void f065();
    virtual void f066();
    virtual void f067();
    virtual void f068();
    virtual void f069();
    virtual void f070();
    virtual void f071();
    virtual void f072();
    virtual void f073();
    virtual void f074();
    virtual void f075();
    virtual void f076();
    virtual void f077();
    virtual void f078();
    virtual void f079();
    virtual void f080();
    virtual void f081();
    virtual void f082();
    virtual void f083();
    virtual void f084();
    virtual void f085();
    virtual void f086();
    virtual void f087();
    virtual void f088();
    virtual void f089();
    virtual void f090();
    virtual void f091();
    virtual void f092();
    virtual void f093();
    virtual void f094();
    virtual void f095();
    virtual void f096();
    virtual void f097();
    virtual void f098();
    virtual void f099();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f150();
    virtual void f151();
    virtual void f152();
    virtual void f153();
    virtual void f154();
    virtual void f155();
    virtual void f156();
    virtual void f157();
    virtual void f158();
    virtual void f159();
    virtual void f160();
    virtual void f161();
    virtual void f162();
    virtual void f163();
    virtual void f164();
    virtual void f165();
    virtual void f166();
    virtual void f167();
    virtual void f168();
    virtual void f169();
    virtual void f170();
    virtual void f171();
    virtual void f172();
    virtual void f173();
    virtual void f174();
    virtual void f175();
    virtual void f176();
    virtual void f177();
    virtual void f178();
    virtual void f179();
    virtual void f180();
    virtual void f181();
    virtual void f182();
    virtual void f183();
    virtual void f184();
    virtual void f185();
    virtual void f186();
    virtual void f187();
    virtual void f188();
    virtual void f189();
    virtual void f190();
    virtual void f191();
    virtual void f192();
    virtual void f193();
    virtual void f194();
    virtual void f195();
    virtual void f196();
    virtual void f197();
    virtual void f198();
    virtual void f199();
    virtual void f200();
    virtual void f201();
    virtual void f202();
    virtual void f203();
    virtual void f204();
    virtual void f205();
    virtual void f206();
    virtual void f207();
    virtual void f208();
    virtual void f209();
    virtual void f210();
    virtual void f211();
    virtual void f212();
    virtual void f213();
    virtual void f214();
    virtual void f215();
    virtual void f216();
    virtual void f217();
    virtual void f218();
    virtual void f219();
    virtual void f220();
    virtual void f221();
    virtual void f222();
    virtual void f223();
    virtual void f224();
    virtual void f225();
    virtual void f226();
    virtual void f227();
    virtual void f228();
    virtual void f229();
    virtual void f230();
    virtual void f231();
    virtual void f232();
    virtual void f233();
    virtual void f234();
    virtual void f235();
    virtual void f236();
    virtual void f237();
    virtual void f238();
    virtual void f239();
    virtual void f240();
    virtual void f241();
    virtual void f242();
    virtual void f243();
    virtual void f244();
    virtual void f245();
    virtual void f246();
    virtual void f247();
    virtual void f248();
    virtual void f249();
    virtual void f250();
    virtual void f251();
    virtual void f252();
    virtual void f253();
    virtual void f254();
    virtual void f255();
    virtual void f256();
    virtual void f257();
    virtual void f258();
    virtual void f259();
    virtual void f260();
    virtual void f261();
    virtual void f262();
    virtual void f263();
    virtual void f264();
    virtual void f265();
    virtual void f266();
    virtual int GetID();
};

extern Actor* _g_thePlayer;

struct FUN_0098cf70_shell
{
    void CountActorsPerNode();
};

// For each virtual node, resets f4A and counts non-player actors whose GetID matches the node's ID.
// @fnv 0x0098cf70
void FUN_0098cf70_shell::CountActorsPerNode()
{
    {
        unsigned int uiNodeCount = reinterpret_cast<PathingSolution*>(this)->GetVirtualNodeCount();
        {
            unsigned int uiActorCount = reinterpret_cast<ActorCombatGroup*>(this)->GetCount();
            {
                unsigned int i = 0;
                for (; i < uiNodeCount; ++i)
                {
                    {
                        CombatTarget* target = reinterpret_cast<identity::FUN_009871c0_shell*>(this)->FUN_009871c0(i);
                        *reinterpret_cast<short*>(target->m_data + 0x4A) = 0;
                        {
                            unsigned int j = 0;
                            for (; j < uiActorCount; ++j)
                            {
                                {
                                    Actor* actor = reinterpret_cast<ActorCombatGroup*>(this)->GetIntAt((int)j);
                                    if (actor == _g_thePlayer)
                                        continue;

                                    if (reinterpret_cast<ActorVirtual*>(actor)->GetID() ==
                                        *reinterpret_cast<int*>(target))
                                    {
                                        ++*reinterpret_cast<short*>(target->m_data + 0x4A);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// @fnv 0x0098ed80
template <>
void __thiscall BSSimpleArray<CombatTarget>::SetSize(unsigned int auiCount, bool abShrink)
{
    if (auiCount == 0)
    {
        Clear(abShrink);
    }
    else if (auiCount > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = this->_Allocate(auiCount);
            SimpleArrayStorage = auiCount;
        }
        else
        {
            ReallocateStorage(auiCount, iSize);
            SimpleArrayStorage = auiCount;
        }

        InitializeItems(pBuffer + iSize, auiCount - iSize);
        iSize = auiCount;
    }
    else if (auiCount < iSize)
    {
        ReleaseElements(pBuffer + auiCount, iSize - auiCount);
        iSize = auiCount;

        if (abShrink && auiCount <= SimpleArrayStorage / 4)
        {
            ReallocateStorage(auiCount, auiCount);
            SimpleArrayStorage = auiCount;
        }
    }
    else
    {
        InitializeItems(pBuffer + iSize, auiCount - iSize);
        iSize = auiCount;
    }
}





struct FUN_008d7f40_shell
{
    void FUN_008d7f40(float value);
};

struct InnerObj
{
    bool FUN_0097ef30();
};

struct FUN_0097fa50_Class
{
    bool FUN_0097fa50();
};

struct FUN_00986150_shell
{
    void FUN_00986150();
    void RecountActors();
    void FUN_0098d030();
    void UpdateChoiceSelection();
    void FUN_0098a580();
    void FUN_0098c870();
    void UpdateGroups();
    unsigned int GetCount();
};

extern Setting originalRuntimeFloatSetting487;
extern Setting originalRuntimeFloatSetting488;
extern Setting originalRuntimeFloatSetting493;
extern Setting g_011ceb44;
extern double _DAT_01012060;

// @fnv 0x00986150
void FUN_00986150_shell::FUN_00986150()
{
    this->RecountActors();

    if (reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0xa8)->CheckTimer())
    {
        reinterpret_cast<FUN_0098cf70_shell*>(this)->CountActorsPerNode();
        this->FUN_0098d030();
        reinterpret_cast<FUN_008d7f40_shell*>(reinterpret_cast<char*>(this) + 0xa8)->FUN_008d7f40(_DAT_010162c0);
    }

    this->UpdateChoiceSelection();
    this->FUN_0098a580();

    if (reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x50)->CheckTimer())
    {
        this->FUN_0098c870();
        reinterpret_cast<FUN_008d7f40_shell*>(reinterpret_cast<char*>(this) + 0x50)
            ->FUN_008d7f40(*originalRuntimeFloatSetting493.Float());
    }

    if (this->GetCount() > 1)
        this->UpdateGroups();

    if (*reinterpret_cast<signed char*>(reinterpret_cast<char*>(this) + 0x154) == -1)
    {
        if (!reinterpret_cast<FUN_0097fa50_Class*>(reinterpret_cast<char*>(this) + 0xb8)->FUN_0097fa50())
        {
            if (!reinterpret_cast<InnerObj*>(this)->FUN_0097ef30())
            {
                reinterpret_cast<FUN_008d7f40_shell*>(reinterpret_cast<char*>(this) + 0xb8)
                    ->FUN_008d7f40(*g_011ceb44.Float());
            }
        }
        else if (reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0xb8)->CheckTimer())
        {
            *reinterpret_cast<signed char*>(reinterpret_cast<char*>(this) + 0x154) = 0;

            if (*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xc8) > _DAT_01012060)
            {
                float ratio = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xc0) /
                              *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xc8);

                if (ratio > *originalRuntimeFloatSetting487.Float() && ratio < *originalRuntimeFloatSetting488.Float())
                {
                    *reinterpret_cast<signed char*>(reinterpret_cast<char*>(this) + 0x154) = 1;
                }
            }
        }
    }
}

struct Pair8
{
    int a;
    int b;
};

struct Obj8
{
    int m0;
    int m4;
    Obj8();
    void* operator new(unsigned int size, void* where);
    void operator delete(void* p, void* where);
};

struct Walker8
{
    void __thiscall ConstructArray(Pair8* arr, unsigned int count);
};

// Placement-constructs an Obj8 in each of the count elements of arr.
// @fnv 0x00845300
void __thiscall Walker8::ConstructArray(Pair8* apPairs, unsigned int count)
{
    unsigned int i;
    for (i = 0; i < count; i++)
    {
        new (&apPairs[i]) Obj8();
    }
}

struct EventVector
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int w;
    void FUN_0097ede0();
};
struct TimeStamp
{
    unsigned int value;
    void FUN_004300a0();
};
struct TimeValue
{
    float value;
    void FUN_00435de0(float time);
};
float __cdecl FUN_00435dd0();
extern float DAT_0108d540;
struct EventSource
{
    EventVector FUN_00575650();
};
struct EventRecord
{
    EventSource* source;
    unsigned int status;
    EventVector primary;
    EventVector secondary;
    EventVector tertiary;
    EventVector quaternary;
    unsigned short type;
    unsigned short subtype;
    TimeValue initialTime;
    TimeValue previousTime;
    TimeStamp start;
    TimeValue timeNow;
    TimeStamp last;
    TimeValue endTime;
    unsigned char started;
    unsigned char ended;
    EventRecord* Init(EventSource* src, unsigned short eventType);
};
// Initialises the event record from a source and event type: clears vectors and status, sets times, and copies the source's event vector into primary.
// @fnv 0x00985410
EventRecord* EventRecord::Init(EventSource* apSource, unsigned short eventType)
{
    source = apSource;
    status = 0;
    primary.FUN_0097ede0();
    secondary.FUN_0097ede0();
    tertiary.FUN_0097ede0();
    quaternary.FUN_0097ede0();
    type = eventType;
    subtype = 0;
    initialTime.FUN_00435de0(-DAT_0108d540);
    previousTime.FUN_00435de0(-DAT_0108d540);
    start.FUN_004300a0();
    timeNow.FUN_00435de0(FUN_00435dd0());
    last.FUN_004300a0();
    endTime.FUN_00435de0(-DAT_0108d540);
    started = 0;
    ended = 0;
    primary = apSource->FUN_00575650();
    return this;
}

struct CombatStamp_985520
{
    float fTime;
    float __thiscall GetTime();
};

struct Block16_985520
{
    int a;
    int b;
    int c;
    int d;
};

struct CombatMemberData_985520
{
    void* pActor;
    int iValue04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Block16_985520 m18;
    Block16_985520 m28;
    Block16_985520 m38;
    unsigned short w48;
    unsigned short w4A;
    CombatStamp_985520 m4C;
    CombatStamp_985520 m50;
    CombatStamp_985520 m54;
    CombatStamp_985520 m58;
    CombatStamp_985520 m5C;
    CombatStamp_985520 m60;
    unsigned char b64;
    unsigned char b65;

    void __thiscall MergeCombatData(CombatMemberData_985520* pOther);
};

// Merges another member's combat data into this one: takes max iValue04, copies newer timestamps with their blocks, and accumulates w4A, b64 and b65.
// @fnv 0x00985520
void CombatMemberData_985520::MergeCombatData(CombatMemberData_985520* pOther)
{
    if (iValue04 < pOther->iValue04)
        iValue04 = pOther->iValue04;
    if (m50.GetTime() < pOther->m50.GetTime())
    {
        m50 = pOther->m50;
        m18 = pOther->m18;
    }
    if (m4C.GetTime() < pOther->m4C.GetTime())
    {
        m4C = pOther->m4C;
        m28 = pOther->m28;
    }
    if (m54.GetTime() < pOther->m54.GetTime())
        m54 = pOther->m54;
    if (m58.GetTime() < pOther->m58.GetTime())
        m58 = pOther->m58;
    if (m60.GetTime() < pOther->m60.GetTime())
    {
        m60 = pOther->m60;
        m38 = pOther->m38;
    }
    w4A += pOther->w4A;
    b64 += pOther->b64;
    b65 += pOther->b65;
}

struct TimeInput
{
    float __thiscall FUN_00527a40(FUN_00985bb0_Class* owner);
};
extern float _DAT_0108d5a0;
extern double _DAT_0108d598;
extern double _DAT_01020758;
float __cdecl FUN_0040ebd0(float value, float limit);

struct CombatClock : FUN_00985bb0_Class
{
    float __thiscall GetAdjustedTime(TimeInput* timeInput);
};
// @fnv 0x00985b40
float CombatClock::GetAdjustedTime(TimeInput* timeInput)
{
    float elapsed;
    {
        float current = FUN_00985bb0();
        elapsed = timeInput->FUN_00527a40(this);
        elapsed = FUN_0040ebd0(elapsed, _DAT_0108d5a0);
        current -= elapsed / _DAT_0108d598;
        if (*reinterpret_cast<int*>(&_pad14[0]) != 0)
            current += _DAT_01020758;
        return current;
    }
}



struct FUN_00986740_shell
{
    void* unk00;
    void* unk04;
    BSSimpleArray<CombatClusterMember> arr;

    void __thiscall FUN_00986740(FUN_00986740_shell* other);
};



// @fnv 0x00986740
void __thiscall FUN_00986740_shell::FUN_00986740(FUN_00986740_shell* other)
{
    other->arr.CopyTo<1024>(&arr);
}

struct FUN_00986760_sub
{
    unsigned int __thiscall FUN_0044ddc0(int flag);
    unsigned int __thiscall FUN_0044ddc0();
    void* __thiscall FUN_0096a2b0(int i);
};

struct FUN_00986760_arg
{
    void __thiscall FUN_006f2290(unsigned int v);
    void __thiscall FUN_0047a110(int i, void* p);
};

struct FUN_00986760_cls
{
    char pad[8];
    FUN_00986760_sub m_08;
    void __thiscall FUN_00986760(int a1);
};

// Passes the result of FUN_0044ddc0(1) to the argument's FUN_006f2290, then forwards each indexed element from FUN_0096a2b0 to FUN_0047a110.
// @fnv 0x00986760
void FUN_00986760_cls::FUN_00986760(int pTarget)
{
    unsigned int i;
    ((FUN_00986760_arg*)pTarget)->FUN_006f2290(m_08.FUN_0044ddc0(1));
    for (i = 0; i < m_08.FUN_0044ddc0(); i++)
    {
        ((FUN_00986760_arg*)pTarget)->FUN_0047a110(i, m_08.FUN_0096a2b0(i));
    }
}



struct Group_987820
{
    unsigned int GetCount();
    Actor* GetAt(int idx);
    void RemoveByTarget(Actor* apTarget);
    void FUN_00987820(Actor* apTarget);
};
// Calls FUN_00980a30 on each member's controller with apTarget, then calls RemoveByTarget if apTarget->IsActor() is nonzero.
// @fnv 0x00987820
void Group_987820::FUN_00987820(Actor* apTarget)
{
    unsigned int p = GetCount();
    unsigned int h;
    for (h = 0; h < p; ++h)
    {
        Actor* j = GetAt(h);
        CombatController* e = j->GetCombatController();
        if (e)
        {
            e->FUN_00980a30(reinterpret_cast<int>(apTarget));
        }
    }
    if (apTarget->IsActor())
    {
        RemoveByTarget(apTarget);
    }
}

struct ResultQuad
{
    unsigned int x, y, z, w;
};
struct ResultLookup
{
    void* FUN_009871c0(int);
};
struct ResultTimer
{
    float FUN_00435e00();
};
struct ResultQuery
{
    bool TryGetQuadForState(int state, ResultQuad* output, float threshold);
};
// Looks up a record for state; if found and threshold exceeds its timer value, copies the quad at offset 40 into output and returns true.
// @fnv 0x00989140
bool ResultQuery::TryGetQuadForState(int state, ResultQuad* output, float threshold)
{
    void* result = ((ResultLookup*)this)->FUN_009871c0(state);
    if (result && threshold > ((ResultTimer*)((char*)result + 76))->FUN_00435e00())
    {
        *output = *(ResultQuad*)((char*)result + 40);
        return true;
    }
    return false;
}

float __cdecl FUN_00435dd0();

struct B989230Stamp
{
    B989230Stamp(float fTime);

    unsigned int m_uiEventId;
};

struct B989230Quad
{
    float x;
    float y;
    float z;
    float w;
};



// Actor::FUN_00575650 has no matching POD return; the output-buffer form changes 0x00989230.
class B989230Ref
{
  public:
    B989230Quad FUN_00575650();
};

struct B989230Entry
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
    B989230Quad m_kPathOffset;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    B989230Stamp m_kStamp;
};

class B989230Tracker
{
  public:
    B989230Entry* FUN_009865d0(B989230Ref* pkRef);
    void UpdateEntryFromRef(int iUnused, B989230Ref* pkRef);
};

// Looks up the entry for pkRef and, if found, refreshes its stamp from FUN_00435dd0 and its quad from pkRef->FUN_00575650.
// @fnv 0x00989230
void B989230Tracker::UpdateEntryFromRef(int iUnused, B989230Ref* pkRef)
{
    if (pkRef)
    {
        B989230Entry* pkEntry = FUN_009865d0(pkRef);
        if (pkEntry)
        {
            B989230Stamp kStamp(FUN_00435dd0());
            pkEntry->m_kStamp = kStamp;
            pkEntry->m_kPathOffset = pkRef->FUN_00575650();
        }
    }
}

struct AvoidVector
{
    float x, y, z;
};
struct AvoidPosition
{
    AvoidVector point;
    unsigned space;
    float FUN_00527a40(const AvoidPosition&);
    AvoidVector& FUN_006815c0();
};
struct AvoidActor
{
    AvoidPosition FUN_00575650();
};
struct AvoidanceVectorData
{
    float x, y, z, r0, r1, r2, r3, r4, r5;
    AvoidanceVectorData(const AvoidVector&);
};
struct AvoidSetting
{
    float* FUN_00403e20();
};
extern AvoidSetting DAT_011cea50, DAT_011ceb2c, DAT_011ce900;
struct AvoidWork
{
    unsigned FUN_005a4320();
    AvoidActor* FUN_00968630(unsigned);
    PathingAvoidNodeArray* BuildAvoidNodes(AvoidActor*, PathingAvoidNodeArray*);
};
// @fnv 0x009895a0
PathingAvoidNodeArray* AvoidWork::BuildAvoidNodes(AvoidActor* actor, PathingAvoidNodeArray* apExistingNodes)
{
    PathingAvoidNodeArray* h = apExistingNodes;
    unsigned p = FUN_005a4320();
    float a = *DAT_011cea50.FUN_00403e20() * *DAT_011cea50.FUN_00403e20();
    AvoidPosition i = actor->FUN_00575650();
    for (unsigned uiIndex = 0; uiIndex < p; ++uiIndex)
    {
        AvoidActor* other = FUN_00968630(uiIndex);
        AvoidPosition location = other->FUN_00575650();
        if (i.FUN_00527a40(location) < a)
        {
            if (!h)
                h = new PathingAvoidNodeArray;
            h->AppendNode(AvoidanceVectorData(location.FUN_006815c0()), *DAT_011ce900.FUN_00403e20(),
                          *DAT_011ceb2c.FUN_00403e20());
        }
    }
    return h;
}

struct B9897F0Quad
{
    float x;
    float y;
    float z;
    float w;
};



class B9897F0Point
{
  public:
    float GetSquaredDistance(const B9897F0Quad& kOther);
};

class B9897F0List
{
  public:
    unsigned int GetCount();
    Actor* GetAt(unsigned int uiIndex);
    Actor* FUN_009897f0(B9897F0Point* pkPoint, float fRadius, Actor* pkExclude);
};

// Scans the list for the first entry other than pkExclude whose squared distance to pkPoint is less than the squared radius, returning it or 0.
// @fnv 0x009897f0
Actor* B9897F0List::FUN_009897f0(B9897F0Point* pkPoint, float afRadius, Actor* pkExclude)
{
    float fRadiusSq = afRadius * afRadius;
    unsigned int ItemUpdateArray = GetCount();
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        Actor* pkRef = GetAt(i);
        if (pkRef != pkExclude)
        {
            B9897F0Quad kPosition;
        pkRef->FUN_00575650(reinterpret_cast<::Position*>(&kPosition));
            if (pkPoint->GetSquaredDistance(kPosition) < fRadiusSq)
                return pkRef;
        }
    }
    return 0;
}

// Builds a 16 byte result block from the actor, then hands it to the group
// helper together with the radius and the actor.

struct LocalResult16
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
};

// Actor side: fills the caller supplied result block and returns its address.
// This call needs the result-buffer address returned in EAX; the shared overload returns void.
struct ActorRef00989880
{
    int __thiscall FUN_00575650(void* pResult);
};

// Group side: takes the result block, the radius and the actor.
struct GroupRef00989880
{
    void* __thiscall FUN_009897f0(int aResult, float aRadius, Actor* pActor);
};

// @fnv 0x00989880
void* TargetExpiryGroupView::FUN_00989880(Actor* pActor, float afRadius)
{
    LocalResult16 tResult;
    return ((GroupRef00989880*)this)
        ->FUN_009897f0(((ActorRef00989880*)pActor)->FUN_00575650(&tResult), afRadius, pActor);
}

extern NiPoint3 NiPoint3_ZERO;
extern "C" void* _alloca(unsigned int size);
float __cdecl FUN_004579e0(float v);



struct FUN_004941c0_shell
{
    float x;
    float y;
    float z;
    NiPoint3* ScaleByInverse(float s);
};
struct FUN_00457910_shell
{
    float x;
    float y;
    float z;
    float FUN_00457910();
};
struct ActorPos
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* GetPos();
};
struct FUN_005a4320_shell : ActorCombatGroup
{
    unsigned int FUN_005a4320();
    ActorPos* FUN_00968630(unsigned int);
};
struct Grp_Call2 : FUN_005a4320_shell
{
    bool FUN_009899a0();
};

// @fnv 0x009899a0
bool Grp_Call2::FUN_009899a0()
{
    unsigned int a3 = GetCount();
    unsigned int b = FUN_005a4320();
    if (a3 == 0 || b == 0 || (a3 == 1 && b == 1))
        return false;
    NiPoint3* arr1 = (NiPoint3*)_alloca(a3 * sizeof(NiPoint3));
    NiPoint3* arr2 = (NiPoint3*)_alloca(b * sizeof(NiPoint3));
    NiPoint3_helper_combatgroup v29 = reinterpret_cast<const NiPoint3_helper_combatgroup&>(NiPoint3_ZERO);
    NiPoint3_helper_combatgroup vTmp = reinterpret_cast<const NiPoint3_helper_combatgroup&>(NiPoint3_ZERO);
    for (unsigned int i = 0; i < a3; i++)
    {
        ActorPos* obj = (ActorPos*)GetIntAt((int)i);
        reinterpret_cast<NiPoint3_helper_combatgroup&>(arr1[i]) = *reinterpret_cast<NiPoint3_helper_combatgroup*>(obj->GetPos());
        ((NiPoint3*)&v29)->operator+=(arr1[i]);
    }
    for (unsigned int j = 0; j < b; j++)
    {
        ActorPos* obj = FUN_00968630(j);
        reinterpret_cast<NiPoint3_helper_combatgroup&>(arr2[j]) = *reinterpret_cast<NiPoint3_helper_combatgroup*>(obj->GetPos());
        ((NiPoint3*)&vTmp)->operator+=(arr2[j]);
    }
    NiPoint3 sum23 = reinterpret_cast<const NiPoint3&>(v29) + reinterpret_cast<const NiPoint3&>(vTmp);
    ((FUN_004941c0_shell*)&v29)->ScaleByInverse((float)a3);
    ((FUN_004941c0_shell*)&vTmp)->ScaleByInverse((float)b);
    ((FUN_004941c0_shell*)&sum23)->ScaleByInverse((float)(a3 + b));
    NiPoint3 d23 = ((NiPoint3*)&vTmp)->operator-(reinterpret_cast<const NiPoint3&>(v29));
    NiPoint3 d5 = ((NiPoint3*)&sum23)->operator-(reinterpret_cast<const NiPoint3&>(v29));
    float f6 = ((NiPoint3*)&d5)->Dot(d23);
    float t20 = FUN_004579e0(f6);
    float t4 = ((FUN_00457910_shell*)&d23)->FUN_00457910();
    NiPoint3 base = reinterpret_cast<const NiPoint3&>(v29) + ((NiPoint3_helper_combatgroup*)&d23)->operator*(t20);
    NiPoint3 resid8 = ((NiPoint3*)&v29)->operator-(base);
    unsigned int countA21 = 0;
    unsigned int countB = 0;
    for (unsigned int i = 0; i < a3; i++)
    {
        NiPoint3 diff = ((NiPoint3*)&arr1[i])->operator-(base);
        if (((NiPoint3*)&diff)->Dot(resid8) < 0.0)
            countA21++;
    }
    for (unsigned int j = 0; j < b; j++)
    {
        NiPoint3 diff = ((NiPoint3*)&arr2[j])->operator-(base);
        if (((NiPoint3*)&diff)->Dot(resid8) < 0.0)
            countB++;
    }
    float ratioA22 = (float)countA21 / (float)a3;
    float ratioB7 = (float)countB / (float)b;
    if ((ratioA22 > 0.33f && ratioB7 > 0.33f) || (ratioA22 < 0.67f && ratioB7 < 0.67f))
        return true;
    return false;
}

struct Tag_00989e20_cls
{
    int unk00;
    void FUN_004a7290();
};

struct Helper_00989e20_cls
{
    void FUN_00439ef0(Tag_00989e20_cls* p0, NiPoint3* p1);
    NiPoint3* FUN_00439e90(NiPoint3* p0, NiPoint3* p1, NiPoint3* p2);
};

struct Vec_00989e20_cls
{
    NiPoint3* FUN_0053d280(float value) const;
};

struct Blk_00989e20_cls
{
    int a0;
    Tag_00989e20_cls t;
    int a8;
    int ac;
};

struct FUN_00989e20_cls
{
    void ExpandBounds(B006815c0* arr, int n);
    void FUN_00989e20(NiPoint3* out);
};

// @fnv 0x00989e20
void FUN_00989e20_cls::FUN_00989e20(NiPoint3* out)
{
    // These output buffers must not invoke NiPoint3 default constructors.
    float v88[3];
    float v7c3[3];
    B006815c0 arr[8];
    Blk_00989e20_cls pa0;

    this->ExpandBounds(arr, 0);
    *reinterpret_cast<NiPoint3_helper_combatgroup*>(out) = *reinterpret_cast<NiPoint3_helper_combatgroup*>(((Vec_00989e20_cls*)((Helper_00989e20_cls*)arr)->FUN_00439e90((NiPoint3*)v7c3, (NiPoint3*)&arr[7], (NiPoint3*)v88))
                ->FUN_0053d280(_DAT_010162c0));
    ((Helper_00989e20_cls*)arr)->FUN_00439ef0(&pa0.t, (NiPoint3*)&arr[7]);
    pa0.t.FUN_004a7290();
}

struct BoundsVector
{
    float x, y, z;
    float& FUN_004a51b0(unsigned int axis);
};
struct BoundsActor
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual const BoundsVector& GetBoundsPoint();
};
extern bool DAT_0108d57c[8][3];
struct BoundsGroup
{
    unsigned int FUN_00990890();
    BoundsActor* GetIntAt(unsigned int index);
    void ExpandBounds(BoundsVector* points, bool append);
};

// Initializes or expands eight corner points from each actor's bounds point, taking per-axis min/max according to the corner sign table.
// @fnv 0x00989f40
void BoundsGroup::ExpandBounds(BoundsVector* points, bool append)
{
    if (!append)
    {
        for (unsigned int corner = 0; corner < 8; ++corner)
        {
            for (unsigned int axis = 0; axis < 3; ++axis)
            {
                points[corner].FUN_004a51b0(axis) = DAT_0108d57c[corner][axis] ? -DAT_0108d540 : DAT_0108d540;
            }
        }
    }
    unsigned int count = FUN_00990890();
    for (unsigned int index = 0; index < count; ++index)
    {
        BoundsActor* actor = GetIntAt(index);
        BoundsVector position = actor->GetBoundsPoint();
        for (unsigned int corner = 0; corner < 8; ++corner)
        {
            for (unsigned int axis = 0; axis < 3; ++axis)
            {
                float value = position.FUN_004a51b0(axis);
                if (DAT_0108d57c[corner][axis])
                {
                    if (value > points[corner].FUN_004a51b0(axis))
                        points[corner].FUN_004a51b0(axis) = value;
                }
                else
                {
                    if (value < points[corner].FUN_004a51b0(axis))
                        points[corner].FUN_004a51b0(axis) = value;
                }
            }
        }
    }
}

namespace fnv_0098a110 {
extern unsigned char DAT_0108d57c[8][3];
extern float DAT_0108d540;
struct PointAccess
{
    float x, y, z;
    float& FUN_004a51b0(unsigned int);
};
struct CombatActorAccess
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const PointAccess& Position();
};
struct CornerAccumulator
{
    unsigned int FUN_005a4320();
    CombatActorAccess* FUN_00968630(unsigned int);
    void UpdateBoundsFromActors(PointAccess*, bool);
};
// Initializes 8 corner points from DAT_0108d57c signs and DAT_0108d540, then expands each corner per axis with every actor's position.
// @fnv 0x0098a110
void CornerAccumulator::UpdateBoundsFromActors(PointAccess* points, bool initialized)
{
    unsigned int f, eb;
    unsigned int s;
    unsigned int cf;
    CombatActorAccess* q;
    PointAccess b;
    unsigned int ba, k;
    float l;
    if (!initialized)
    {
        for (f = 0; f < 8; ++f)
        {
            for (eb = 0; eb < 3; ++eb)
            {
                points[f].FUN_004a51b0(eb) = DAT_0108d57c[f][eb] ? -DAT_0108d540 : DAT_0108d540;
            }
        }
    }
    s = FUN_005a4320();
    for (cf = 0; cf < s; ++cf)
    {
        q = FUN_00968630(cf);
        b = q->Position();
        for (ba = 0; ba < 8; ++ba)
        {
            for (k = 0; k < 3; ++k)
            {
                l = b.FUN_004a51b0(k);
                if (DAT_0108d57c[ba][k])
                {
                    if (l > points[ba].FUN_004a51b0(k))
                        points[ba].FUN_004a51b0(k) = l;
                }
                else
                {
                    if (l < points[ba].FUN_004a51b0(k))
                        points[ba].FUN_004a51b0(k) = l;
                }
            }
        }
    }
}
}  // namespace fnv_0098a110

struct SearchNodeArrayOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    MyArr_0098a3c0 nodes;
};

// @fnv 0x0098a340
int FUN_0098a340_shell::FUN_0098a340(int index)
{
    return reinterpret_cast<SearchNodeArrayOwner*>(this)->nodes.FUN_006dad90(index)->m1;
}

struct FUN_0098a4d0_sub
{
    virtual int Slot0(int arg);
    virtual void Slot1();
    virtual void Slot2();
    virtual double Slot3(int arg);
};

struct FUN_0098a4d0_item
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
    FUN_0098a4d0_sub sub;
};

struct FUN_0098a4d0_class : FUN_0098a410_shell
{
    float ComputeAverageRatio();
};

// Averages, over all items from GetCount, the ratio of Slot3(16) to Slot0(16) and returns the mean.
// @fnv 0x0098a4d0
float FUN_0098a4d0_class::ComputeAverageRatio()
{
    float total = 0.0f;
    unsigned int itemCount = GetCount();
    for (unsigned int i = 0; i < itemCount; i++)
    {
        FUN_0098a4d0_item* item = (FUN_0098a4d0_item*)GetIntAt(i);
        total = item->sub.Slot3(16) / item->sub.Slot0(16) + total;
    }
    total = total / itemCount;
    return total;
}


// The returned position carries a fourth value after its three coordinates.
struct ItemPositionResult
{
    NiPoint3 position;
    float w;
};

struct PosObj
{
    bool IsEqual(const PosObj* other);
};
struct TileObj
{
    bool CheckItem(void* item, int a, int b);
};
struct MgrObj
{
    TileObj* GetTile();
};
struct ItemObj
{
    float GetScore();
    unsigned int GetID();
    PosObj* GetPosObj();
    float GetDistance(NiPoint3* pos);
};
struct ActorObj
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual void vf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void vf264();
    virtual void vf268();
    virtual void vf26c();
    virtual void vf270();
    virtual void vf274();
    virtual void vf278();
    virtual void vf27c();
    virtual void vf280();
    virtual void vf284();
    virtual void vf288();
    virtual void vf28c();
    virtual void vf290();
    virtual void vf294();
    virtual void vf298();
    virtual void vf29c();
    virtual void vf2a0();
    virtual void vf2a4();
    virtual void vf2a8();
    virtual void vf2ac();
    virtual void vf2b0();
    virtual void vf2b4();
    virtual void vf2b8();
    virtual void vf2bc();
    virtual void vf2c0();
    virtual void vf2c4();
    virtual void vf2c8();
    virtual void vf2cc();
    virtual void vf2d0();
    virtual void vf2d4();
    virtual void vf2d8();
    virtual void vf2dc();
    virtual void vf2e0();
    virtual void vf2e4();
    virtual void vf2e8();
    virtual void vf2ec();
    virtual void vf2f0();
    virtual void vf2f4();
    virtual void vf2f8();
    virtual void vf2fc();
    virtual void vf300();
    virtual void vf304();
    virtual void vf308();
    virtual void vf30c();
    virtual void vf310();
    virtual void vf314();
    virtual void vf318();
    virtual void vf31c();
    virtual void vf320();
    virtual void vf324();
    virtual void vf328();
    virtual void vf32c();
    virtual void vf330();
    virtual void vf334();
    virtual void vf338();
    virtual void vf33c();
    virtual void vf340();
    virtual void vf344();
    virtual void vf348();
    virtual void vf34c();
    virtual void vf350();
    virtual void vf354();
    virtual void vf358();
    virtual void vf35c();
    virtual void vf360();
    virtual void vf364();
    virtual void vf368();
    virtual void vf36c();
    virtual void vf370();
    virtual void vf374();
    virtual void vf378();
    virtual void vf37c();
    virtual void vf380();
    virtual void vf384();
    virtual void vf388();
    virtual void vf38c();
    virtual void vf390();
    virtual void vf394();
    virtual void vf398();
    virtual void vf39c();
    virtual void vf3a0();
    virtual void vf3a4();
    virtual void vf3a8();
    virtual void vf3ac();
    virtual void vf3b0();
    virtual void vf3b4();
    virtual void vf3b8();
    virtual void vf3bc();
    virtual void vf3c0();
    virtual void vf3c4();
    virtual void vf3c8();
    virtual void vf3cc();
    virtual void vf3d0();
    virtual void vf3d4();
    virtual void vf3d8();
    virtual void vf3dc();
    virtual void vf3e0();
    virtual void vf3e4();
    virtual void vf3e8();
    virtual void vf3ec();
    virtual void vf3f0();
    virtual void vf3f4();
    virtual void vf3f8();
    virtual void vf3fc();
    virtual void vf400();
    virtual void vf404();
    virtual void vf408();
    virtual void vf40c();
    virtual void vf410();
    virtual void vf414();
    virtual void vf418();
    virtual void vf41c();
    virtual void vf420();
    virtual void vf424();
    virtual MgrObj* GetMgr();
    ItemPositionResult GetPos();
};
struct ItemList
{
    unsigned int GetCount();
    ItemObj* GetAt(unsigned int i);
    ItemObj* FindBestItem(ActorObj* actor, unsigned char thresh, ItemObj* target);
};

// @fnv 0x0098bc00
ItemObj* ItemList::FindBestItem(ActorObj* actor, unsigned char aucThreshold, ItemObj* target)
{
    MgrObj* mgr_2 = actor->GetMgr();
    ItemPositionResult kPos = actor->GetPos();
    int bestIdx3 = -1;
    float best = 0.0f;
    bool found3 = false;
    unsigned int count7 = GetCount();
    for (unsigned int i4 = 0; i4 < count7; i4++)
    {
        ItemObj* item = GetAt(i4);
        float score2 = item->GetScore();
        float bonus2 = 0.0f;
        if (target && item->GetID() == target->GetID() && item->GetPosObj()->IsEqual(target->GetPosObj()))
            bonus2 += 5.0;
        if (score2 + bonus2 < aucThreshold)
            continue;
        float dist6 = item->GetDistance(&kPos.position) + bonus2;
        if (score2 < best)
            continue;
        if (mgr_2 && !mgr_2->GetTile()->CheckItem(item, 1, 0))
            continue;
        bestIdx3 = i4;
        best = score2;
    }
    if (bestIdx3 != -1)
        return GetAt(bestIdx3);
    return 0;
}

struct CombatEntryObj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void* vfn_428();
    bool FUN_008b3840(struct Probe16* p);
};
struct Probe16
{
    int a, b, c;
    void FUN_006815c0();
};
struct RefTarget
{
    bool FUN_00981420();
};
struct CombatGroupTarget
{
    void AddItem(Probe16* p);
};
struct CombatSearchCls
{
    unsigned int FUN_00990890();
    CombatEntryObj* GetIntAt(int i);
    bool CheckOtherEntriesForTarget(CombatEntryObj* a1, CombatGroupTarget* a2);
};
// @fnv 0x0098c7b0
bool CombatSearchCls::CheckOtherEntriesForTarget(CombatEntryObj* pExcludeEntry, CombatGroupTarget* pGroupTarget)
{
    unsigned int count = FUN_00990890();
    if (count <= 1)
        return false;
    bool bFound = false;
    for (unsigned int i = 0; i < count; ++i)
    {
        CombatEntryObj* p2 = GetIntAt(i);
        if (p2 != pExcludeEntry)
        {
            void* r2 = p2->vfn_428();
            if (r2 != 0)
            {
                if (((RefTarget*)r2)->FUN_00981420())
                {
                    Probe16 probe;
                    probe.FUN_006815c0();
                    if (p2->FUN_008b3840(&probe))
                    {
                        pGroupTarget->AddItem(&probe);
                        bFound = true;
                    }
                }
            }
        }
    }
    return bFound;
}

struct FUN_0098cb30_inner
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00A();
    virtual void v00B();
    virtual void v00C();
    virtual void v00D();
    virtual void v00E();
    virtual void v00F();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01A();
    virtual void v01B();
    virtual void v01C();
    virtual void v01D();
    virtual void v01E();
    virtual void v01F();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02A();
    virtual void v02B();
    virtual void v02C();
    virtual void v02D();
    virtual void v02E();
    virtual void v02F();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03A();
    virtual void v03B();
    virtual void v03C();
    virtual void v03D();
    virtual void v03E();
    virtual void v03F();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04A();
    virtual void v04B();
    virtual void v04C();
    virtual void v04D();
    virtual void v04E();
    virtual void v04F();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05A();
    virtual void v05B();
    virtual void v05C();
    virtual void v05D();
    virtual void v05E();
    virtual void v05F();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06A();
    virtual void v06B();
    virtual void v06C();
    virtual void v06D();
    virtual void v06E();
    virtual void v06F();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07A();
    virtual void v07B();
    virtual void v07C();
    virtual void v07D();
    virtual void v07E();
    virtual void v07F();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v08A();
    virtual void v08B();
    virtual void v08C();
    virtual void v08D();
    virtual void v08E();
    virtual void v08F();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v09A();
    virtual void v09B();
    virtual void v09C();
    virtual void v09D();
    virtual void v09E();
    virtual void v09F();
    virtual void v0A0();
    virtual void v0A1();
    virtual void v0A2();
    virtual void v0A3();
    virtual void v0A4();
    virtual void v0A5();
    virtual void v0A6();
    virtual void v0A7();
    virtual void v0A8();
    virtual void v0A9();
    virtual void v0AA();
    virtual void v0AB();
    virtual void v0AC();
    virtual void v0AD();
    virtual void v0AE();
    virtual void v0AF();
    virtual void v0B0();
    virtual void v0B1();
    virtual void v0B2();
    virtual void v0B3();
    virtual void v0B4();
    virtual void v0B5();
    virtual void v0B6();
    virtual void v0B7();
    virtual void v0B8();
    virtual void v0B9();
    virtual void v0BA();
    virtual void v0BB();
    virtual void v0BC();
    virtual void v0BD();
    virtual void v0BE();
    virtual void v0BF();
    virtual void v0C0();
    virtual void v0C1();
    virtual void v0C2();
    virtual void v0C3();
    virtual void v0C4();
    virtual void v0C5();
    virtual void v0C6();
    virtual void v0C7();
    virtual void v0C8();
    virtual void v0C9();
    virtual void v0CA();
    virtual void v0CB();
    virtual void v0CC();
    virtual void v0CD();
    virtual void v0CE();
    virtual void v0CF();
    virtual void v0D0();
    virtual void v0D1();
    virtual void v0D2();
    virtual void v0D3();
    virtual void v0D4();
    virtual void v0D5();
    virtual void v0D6();
    virtual void v0D7();
    virtual void v0D8();
    virtual void v0D9();
    virtual void v0DA();
    virtual void v0DB();
    virtual void v0DC();
    virtual void v0DD();
    virtual void v0DE();
    virtual void v0DF();
    virtual void v0E0();
    virtual void v0E1();
    virtual void v0E2();
    virtual void v0E3();
    virtual void v0E4();
    virtual void v0E5();
    virtual void v0E6();
    virtual void v0E7();
    virtual void v0E8();
    virtual void v0E9();
    virtual void v0EA();
    virtual void v0EB();
    virtual void v0EC();
    virtual void v0ED();
    virtual void v0EE();
    virtual void v0EF();
    virtual void v0F0();
    virtual void v0F1();
    virtual void v0F2();
    virtual void v0F3();
    virtual void v0F4();
    virtual void v0F5();
    virtual void v0F6();
    virtual void v0F7();
    virtual void v0F8();
    virtual void v0F9();
    virtual void v0FA();
    virtual void v0FB();
    virtual void v0FC();
    virtual void v0FD();
    virtual void v0FE();
    virtual void v0FF();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual int v10A();
};

struct FUN_0098cb30_obj
{
    FUN_0098cb30_inner* m_pInner;
    int unk04;
    int unk08;
    float m_iThirdValue;
};

struct FUN_0098cb30_res
{
    FUN_0098cb30_res* FUN_00586150();
    float FUN_00453700();
    bool FUN_00981990();
};

struct FUN_0098cb30_cls
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
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    float m_c0;
    unsigned int FUN_00990890();
    FUN_0098cb30_obj* FUN_00988790(unsigned int idx);
    float GetModifierSum(FUN_0098cb30_inner* a1);
};

extern double _gModifierZero;

// Sums per-entry modifier values for entries matching a1 (or all others), skipping non-positive values, and returns m_c0 when a1 is null.
// @fnv 0x0098cb30
float FUN_0098cb30_cls::GetModifierSum(FUN_0098cb30_inner* apInner)
{
    if (apInner == 0)
    {
        return m_c0;
    }
    float fSum = 0.0f;
    unsigned int count = FUN_00990890();
    for (unsigned int i = 0; i < count; i++)
    {
        int r;
        FUN_0098cb30_obj* pObj = FUN_00988790(i);
        r = pObj->m_pInner->v10A();
        if (apInner == pObj->m_pInner && r != 0)
        {
            float fValue = ((FUN_0098cb30_res*)r)->FUN_00586150()->FUN_00453700();
            if (fValue > _gModifierZero)
            {
                fSum += fValue;
            }
        }
        else if (r == 0 || !((FUN_0098cb30_res*)r)->FUN_00981990())
        {
            if (pObj->m_iThirdValue > _gModifierZero)
            {
                fSum += pObj->m_iThirdValue;
            }
        }
    }
    return fSum;
}

class B8EB30Group;

class B8EB30GroupInfo
{
  public:
    B8EB30Group* GetGroup();
};



extern Actor* g_thePlayer;

class B8EB30Group
{
  public:
    void UpdateBase();
    unsigned int GetCount();
    Actor* GetAt(int iIndex);
    void RemoveMemberAt(Actor* pkActor);
    void RemoveActorsNotInGroup(void* pvUnused);
};

// @fnv 0x0098eb30
void B8EB30Group::RemoveActorsNotInGroup(void* pvUnused)
{
    UpdateBase();
    for (unsigned int i = 0; i < GetCount(); i++)
    {
        Actor* pkActor2 = GetAt(i);
        if (pkActor2 == g_thePlayer)
            continue;
        B8EB30GroupInfo* pkInfo = reinterpret_cast<B8EB30GroupInfo*>(pkActor2->GetCombatController());
        if (!pkInfo || pkInfo->GetGroup() != this)
        {
            RemoveMemberAt(pkActor2);
            i--;
        }
    }
}

class B98EBC0Array
{
  public:
    int* FUN_006bf670(int iIndex);
    int* GetElementAt(int iIndex);
};

// @fnv 0x0098ebc0
int* B98EBC0Array::GetElementAt(int iIndex)
{
    return FUN_006bf670(iIndex);
}

struct SimpleArrayRemove
{
    virtual ~SimpleArrayRemove();
    virtual void* Allocate(unsigned int ItemUpdateArray);

    void** pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;

    void Clear(bool bFree);
    bool FUN_006f3170();
    unsigned int FUN_00869600();
    void FUN_0042fb60(void* pDest, void* pSrc, unsigned int ItemUpdateArray);
    void FUN_0072ba80(void* pStart, unsigned int ItemUpdateArray);
    void FUN_006a8500();

    void FUN_0098ebe0(unsigned int uiStart, unsigned int ItemUpdateArray, bool bShrink);
};

// @fnv 0x0098ebe0
void SimpleArrayRemove::FUN_0098ebe0(unsigned int uiStart, unsigned int ItemUpdateArray, bool bShrink)
{
    if (ItemUpdateArray >= uiSize)
    {
        Clear(bShrink);
        return;
    }
    if (bShrink && FUN_006f3170())
    {
        unsigned int uiNewAlloc = FUN_00869600();
        void** pData = (void**)Allocate(uiNewAlloc);
        FUN_0042fb60(pData, pBuffer, uiStart);
        FUN_0072ba80(&pBuffer[uiStart], ItemUpdateArray);
        FUN_0042fb60(&pData[uiStart], &pBuffer[uiStart] + ItemUpdateArray, uiSize - ItemUpdateArray);
        FUN_006a8500();
        pBuffer = pData;
        uiAllocSize = uiNewAlloc;
    }
    else
    {
        FUN_0072ba80(&pBuffer[uiStart], ItemUpdateArray);
        FUN_0042fb60(&pBuffer[uiStart], &pBuffer[uiStart] + ItemUpdateArray, uiSize - uiStart - ItemUpdateArray);
    }
    uiSize = uiSize - ItemUpdateArray;
}

unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
struct RemovalOperations
{
    void FUN_0072ba80(void*, unsigned int);
    void FUN_0098f960(void*, void*, unsigned int);
};
struct RemovalArray : RemovalOperations
{
    void* unk00;
    char* unk04;
    unsigned int unk08;
    void FUN_0098ef10(unsigned int first, unsigned int count);
};
// @fnv 0x0098ef10
void RemovalArray::FUN_0098ef10(unsigned int first, unsigned int count)
{
    unsigned int moved = FUN_0042f5a0(unk08 - first - count, count);
    FUN_0072ba80(unk04 + first * 104, count);
    FUN_0098f960(unk04 + first * 104, unk04 + unk08 * 104 - moved * 104, moved);
    unk08 -= count;
}

void* operator new(unsigned int uiSize, void* pvWhere);
void operator delete(void* pvMem, void* pvWhere);

class C98F840Element
{
  public:
    C98F840Element();

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
};

class C98F840Allocator
{
  public:
    void FUN_0098f840(C98F840Element* pkElements, unsigned int ItemUpdateArray);
};

// @fnv 0x0098f840
void C98F840Allocator::FUN_0098f840(C98F840Element* pkElements, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkElements[i]) C98F840Element;
}

struct FUN_009d3390_sub
{
    int unk00;
    unsigned char CallA();
    unsigned char CallB();
};

struct FUN_009d3390_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_009d3390_sub m14;
    int unk18;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    unsigned char m74;

    unsigned char FUN_009d3390();
};

// Returns 1 if the sub-object's CallA or CallB returns nonzero, or if m74 is nonzero; otherwise 0.
// @fnv 0x009d3390
unsigned char FUN_009d3390_cls::FUN_009d3390()
{
    return (m14.CallA() != 0 || m14.CallB() != 0 || m74 != 0) ? 1 : 0;
}

struct Member08
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member08();
};
struct Member18
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member18();
};
struct SharedList
{
    unsigned int unk00;
    unsigned int unk04;
    ~SharedList();
};
struct Member110
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member110();
};
struct Member120
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member120();
};
struct Member138
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member138();
    unsigned int FUN_0044ddc0();
    char*& FUN_006a7ad0(unsigned int);
};
extern CombatManager* g_011f1958;
struct FUN_00985f90
{
    unsigned int unk000;
    unsigned int unk004;
    Member08 member08;
    Member18 member18;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    SharedList memberd4;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    Member110 member110;
    Member120 member120;
    SharedList member130;
    Member138 member138;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    SharedList member158;
    unsigned int FUN_005a4320();
    void* FUN_00968630(unsigned int);
    unsigned int FUN_00990890();
    void* GetIntAt(unsigned int);
    void RebuildDebugVisuals(bool);
    ~FUN_00985f90();
};
// @fnv 0x00985f90
FUN_00985f90::~FUN_00985f90()
{
    unsigned int count = FUN_005a4320();
    for (unsigned int i = 0; i < count; i++)
    {
        void* actor = FUN_00968630(i);
        g_011f1958->SwapAndDispatch(this, actor);
    }
    unsigned int targetCount = FUN_00990890();
    for (unsigned int j = 0; j < targetCount; j++)
    {
        void* target = GetIntAt(j);
        g_011f1958->FUN_008d0600(this, target);
    }
    for (unsigned int k = 0; k < member138.FUN_0044ddc0(); k++)
    {
        char* pEntry = member138.FUN_006a7ad0(k);
        delete pEntry;
    }
    RebuildDebugVisuals(true);
}

struct ActorMergeData;
struct MergeActor : ActorV
{
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void SetCombatGroup(ActorMergeData* group);
    unsigned int FUN_0084e3a0();
};
struct MergeTarget
{
    MergeActor* actor;
    void MergeCombatData(MergeTarget* other);
};
struct MergeMember
{
    MergeActor* actor;
    void CopyFrom(MergeMember* other);
};
struct MergeTargets : CombatgroupOffset08View
{
    unsigned int unk00, unk04, unk08, unk0c;
    MergeTarget* FUN_0096a2b0(unsigned int index);
};
struct MergeMembers : CombatgroupOffset08View
{
    MergeMember* FUN_006dad90(unsigned int index);
};
struct MergeEntries
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int FUN_007cb2e0(int& entry);
};
struct ActorMergeData
{
    unsigned int unk00, unk04;
    MergeTargets targets;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    MergeEntries entries;
    unsigned int unk148, unk14c, unk150;
    char state;
    MergeTargets* FUN_00413f40();
    MergeMembers* FUN_00500940();
    bool FUN_009866d0(MergeActor* actor);
    bool FUN_009867d0(MergeActor* actor);
    bool FUN_00986410(MergeActor* actor);
    MergeMember* FUN_009865f0(MergeActor* actor);
    MergeTarget* FUN_009865d0(MergeActor* actor);
    char GetFlagsFromSubobject();
    int GetArrayItem(unsigned char index);
    void ClearGlobalObject();
    char GetByteAtOffset154();
    bool MergeFrom(ActorMergeData* other);
};

// Merges another combat group's targets, entries and members into this one, warning on members or targets that cannot be added, and copies its state.
// @fnv 0x00987530
bool ActorMergeData::MergeFrom(ActorMergeData* other)
{
    MergeTargets* otherMembers = other->FUN_00413f40();
    for (unsigned int i = 0; i < otherMembers->GetFlags(); ++i)
    {
        MergeTarget* target = otherMembers->FUN_0096a2b0(i);
        if (!FUN_009866d0(target->actor))
            return false;
    }
    for (unsigned int j = 0; j < targets.GetFlags(); ++j)
    {
        MergeTarget* target = targets.FUN_0096a2b0(j);
        if (!other->FUN_009866d0(target->actor))
            return false;
    }
    for (unsigned int k = 0; k < other->GetFlagsFromSubobject(); ++k)
    {
        int entry = other->GetArrayItem((unsigned char)k);
        entries.FUN_007cb2e0(entry);
    }
    other->ClearGlobalObject();
    MergeMembers* otherState = other->FUN_00500940();
    for (unsigned int m = 0; m < otherState->GetFlags(); ++m)
    {
        MergeMember* member = otherState->FUN_006dad90(m);
        if (FUN_009867d0(member->actor))
        {
            member->actor->SetCombatGroup(this);
            MergeMember* destination = FUN_009865f0(member->actor);
            if (destination)
                destination->CopyFrom(member);
        }
        else
            FNV_Warning("COMBAT: Error merging groups.  Could not add member %08X %s", member->actor->FUN_0084e3a0(),
                        member->actor->V130());
    }
    for (unsigned int n = 0; n < otherMembers->GetFlags(); ++n)
    {
        MergeTarget* target = otherMembers->FUN_0096a2b0(n);
        if (FUN_00986410(target->actor))
        {
            MergeTarget* destination = FUN_009865d0(target->actor);
            if (destination)
                destination->MergeCombatData(target);
        }
        else
            FNV_Warning("COMBAT: Error merging groups.  Could not add target %08X %s", target->actor->FUN_0084e3a0(),
                        target->actor->V130());
    }
    char otherTargets = other->GetByteAtOffset154();
    if (otherTargets != -1)
        state = otherTargets;
    return true;
}

struct DebugPoint
{
    float x, y, z;
};
struct DebugMaterial
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    DebugMaterial();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void FUN_0049ed90(bool);
};
struct DebugUpdate
{
    float time;
    int flags, unk08;
    DebugUpdate(float, int, int);
};
struct DebugNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void Attach(DebugNode*, bool);
    virtual void v56();
    virtual void v57();
    virtual void Detach(DebugNode*);
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    DebugNode(int);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    DebugNode* FUN_009611e0();
    void FUN_004bc1f0(float, float, float);
    void FUN_00440460(const DebugPoint&);
    void FUN_00439410(DebugMaterial*);
    void FUN_00a5a040();
    void FUN_00a59c60(const DebugUpdate&);
};
struct DebugNodePtr
{
    DebugNode* ptr;
    DebugNode* FUN_00559450();
    void FUN_0066b0d0(DebugNode*);
};
void* FUN_00aa13e0(unsigned int);
void FUN_00aa13f0(void*);
__forceinline void* DebugNode::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void DebugNode::operator delete(void* p)
{
    FUN_00aa13f0(p);
}
__forceinline void* DebugMaterial::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void DebugMaterial::operator delete(void* p)
{
    FUN_00aa13f0(p);
}
struct DebugDetach
{
    void FUN_0087ac60();
};
bool FUN_008c7aa0();
DebugDetach* __stdcall FUN_004537b0(DebugNode*);
struct DebugScene
{
    DebugNode* FUN_00524cf0();
};
struct DebugGroup;
struct DebugActor
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const DebugPoint& Position();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual DebugGroup* Group();
    unsigned int FUN_00575ca0();
    DebugScene* FUN_008d6f30();
    float FUN_008be1b0();
};
extern DebugActor* DAT_011dea3c;
extern DebugActor* DAT_011dea24;

extern Setting DAT_011f1824, DAT_011f1858, DAT_011f1814;
extern bool DAT_011a4d34;
extern float DAT_011a4d2c;
struct DebugSearchPoint
{
    const DebugPoint& FUN_006815c0();
    unsigned int FUN_0084e3a0();
    NiColorA GetEffectColor();
};
struct DebugMember
{
    DebugActor* actor;
    int unk04, unk08, unk0c;
    DebugSearchPoint* point;
};
struct DebugPair
{
    DebugActor* first;
    DebugActor* second;
    char unk08;
    bool blue, green;
    char unk0b;
};
struct DebugPoints
{
    int unk00, unk04, unk08, unk0c;
    unsigned int FUN_0044ddc0();
    DebugSearchPoint*& FUN_006a7ad0(unsigned int);
};
struct DebugPairs
{
    int unk00, unk04, unk08, unk0c;
    unsigned int FUN_0044ddc0();
    DebugPair* FUN_006a7af0(unsigned int);
};
struct DebugBuilder
{
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    DebugBuilder(DebugPoint, float);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    DebugNode* CreateSortAdjustNode();
};
__forceinline void* DebugBuilder::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void DebugBuilder::operator delete(void* p)
{
    FUN_00aa13f0(p);
}
struct DebugBuilderPtr
{
    DebugBuilder* ptr;
    DebugBuilderPtr(DebugBuilder*);
    ~DebugBuilderPtr();
    DebugBuilder* FUN_00559450();
};
struct DebugSearch
{
    float FUN_00508050();
    DebugPoint GetLocationAndReturn();
    void UpdateNavMeshes(DebugBuilderPtr&);
};
struct DebugSearchPtr
{
    DebugSearch* ptr;
    DebugSearch* FUN_00559450();
};
const NiColorA& FUN_005d8550(int);
DebugNode* FUN_00c5a0f0(const DebugPoint&, const DebugPoint&, float, float, const NiColorA*, const NiColorA*);
DebugNode* FUN_00c58f00(float, int, const NiColorA*);
DebugNode* FUN_00c58d30(float, float, float, int, int, const NiColorA*);
DebugNode* FUN_00c56680(float, int, int, const NiColorA*);
void AttachLightingPropertyRecursive(DebugNode*);
void FUN_00b57e30(DebugNode*, int, int);
struct DebugGroup
{
    unsigned int id;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    DebugSearchPtr search;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    DebugPairs pairs;
    DebugNodePtr searchNode;
    bool searchDirty;
    char unk135, unk136, unk137;
    DebugPoints points;
    int unk148, unk14c, unk150, unk154;
    DebugNodePtr debug;
    unsigned int FUN_00990890();
    DebugMember* FUN_00988790(unsigned int);
    DebugActor* GetIntAt(unsigned int);
    unsigned int FUN_00988750();
    DebugSearchPoint* ForwardToMember(unsigned int);
    void RebuildDebugVisuals(bool);
};
// @fnv 0x009878b0
void DebugGroup::RebuildDebugVisuals(bool clearOnly)
{
    if (debug.FUN_00559450() && debug.FUN_00559450()->FUN_009611e0())
    {
        if (!FUN_008c7aa0())
            debug.FUN_00559450()->FUN_009611e0()->Detach(debug.FUN_00559450());
        else
            FUN_004537b0(debug.FUN_00559450())->FUN_0087ac60();
    }
    debug.FUN_0066b0d0(0);
    if (clearOnly)
        return;
    if (!DAT_011dea3c->FUN_008d6f30() || !DAT_011dea3c->FUN_008d6f30()->FUN_00524cf0())
        return;
    unsigned int space = DAT_011dea3c->FUN_00575ca0();
    DebugActor* selected3 = 0;
    if (DAT_011dea24 && DAT_011dea24->IsActor())
    {
        DebugActor* selectedActor = DAT_011dea24;
        if (selectedActor->Group() == this)
            selected3 = selectedActor;
    }
    if (*DAT_011f1824.FUN_00408d60() && !DAT_011a4d34 && selected3)
    {
        for (unsigned int i = 0; i < points.FUN_0044ddc0(); ++i)
        {
            DebugSearchPoint* spot = points.FUN_006a7ad0(i);
            if (!debug.FUN_00559450())
                debug.FUN_0066b0d0(new DebugNode(0));
            NiColorA color(0.5f, 0.0f, 0.5f, 0.5f);
            bool found3 = false;
            DebugPoint position = spot->FUN_006815c0();
            unsigned int count2 = FUN_00990890();
            for (unsigned int j = 0; j < count2; ++j)
            {
                DebugMember* member = FUN_00988790(j);
                if (member->point == spot && member->actor->FUN_00575ca0() == space)
                {
                    DebugPoint origin = member->actor->Position();
                    NiColorA start(0.5f, 0.0f, 0.5f, 0.5f);
                    NiColorA end_2(1.0f, 1.0f, 1.0f, 0.5f);
                    DebugNode* arrow = FUN_00c5a0f0(origin, position, 4.0f, 4.0f, &start, &end_2);
                    debug.FUN_00559450()->Attach(arrow, true);
                    found3 = true;
                }
            }
            if (found3)
            {
                for (unsigned int k = 0; k < 5; ++k)
                {
                    DebugNode* circle = FUN_00c58f00(DAT_011a4d2c, 36, &color);
                    circle->FUN_004bc1f0(position.x, position.y, k * 25.0 + position.z);
                    debug.FUN_00559450()->Attach(circle, true);
                }
                DebugNode* marker = FUN_00c58d30(16.0f, 16.0f, 400.0f, 10, 10, &color);
                marker->FUN_00440460(position);
                debug.FUN_00559450()->Attach(marker, true);
            }
        }
    }
    if (*DAT_011f1858.FUN_00408d60())
    {
        if (!debug.FUN_00559450())
            debug.FUN_0066b0d0(new DebugNode(0));
        unsigned int memberCount = FUN_00990890();
        for (unsigned int n = 0; n < memberCount; ++n)
        {
            DebugActor* memberActor3 = GetIntAt(n);
            if (memberActor3->FUN_00575ca0() != space)
                continue;
            float radius = memberActor3->FUN_008be1b0() * 1.5;
            NiColorA memberColor = FUN_005d8550((int)id);
            memberColor.a = 0.5f;
            DebugNode* cylinder2 = FUN_00c58d30(radius, radius, 16.0f, 10, 10, &memberColor);
            cylinder2->FUN_00440460(memberActor3->Position());
            debug.FUN_00559450()->Attach(cylinder2, true);
        }
    }
    DebugNode* extra = 0;
    if (*DAT_011f1814.FUN_00408d60() && selected3)
    {
        if (!debug.FUN_00559450())
            debug.FUN_0066b0d0(new DebugNode(0));
        unsigned int pointCount = FUN_00988750();
        for (unsigned int p = 0; p < pointCount; ++p)
        {
            DebugSearchPoint* point = ForwardToMember(p);
            if (point->FUN_0084e3a0() != space)
                continue;
            NiColorA pointColor3 = point->GetEffectColor();
            DebugNode* sphere = FUN_00c56680(32.0f, 10, 10, &pointColor3);
            sphere->FUN_00440460(point->FUN_006815c0());
            debug.FUN_00559450()->Attach(sphere, true);
        }
        for (unsigned int q = 0; q < pairs.FUN_0044ddc0(); ++q)
        {
            DebugPair* pair = pairs.FUN_006a7af0(q);
            DebugActor* pairActor = 0;
            if (pair->first && pair->first->FUN_00575ca0() == space)
                pairActor = pair->first;
            else if (pair->second && pair->second->FUN_00575ca0() == space)
                pairActor = pair->second;
            if (!pairActor)
                continue;
            NiColorA pairColor_(0.0f, 0.0f, 0.0f, 0.0f);
            if (pair->blue)
                pairColor_ = NiColorA(0.0f, 0.0f, 1.0f, 0.5f);
            else if (pair->green)
                pairColor_ = NiColorA(0.0f, 1.0f, 0.0f, 0.5f);
            else
                pairColor_ = NiColorA(1.0f, 1.0f, 0.0f, 0.5f);
            DebugPoint pairPosition = pairActor->Position();
            DebugNode* pillarX = FUN_00c58d30(32.0f, 32.0f, 256.0f, 10, 10, &pairColor_);
            pillarX->FUN_00440460(pairPosition);
            debug.FUN_00559450()->Attach(pillarX, true);
        }
        if (search.FUN_00559450() && searchDirty && selected3->FUN_00575ca0() == space)
        {
            DebugBuilderPtr builder(
                new DebugBuilder(search.FUN_00559450()->GetLocationAndReturn(), search.FUN_00559450()->FUN_00508050()));
            search.FUN_00559450()->UpdateNavMeshes(builder);
            searchNode.FUN_0066b0d0(builder.FUN_00559450()->CreateSortAdjustNode());
            searchDirty = false;
        }
        extra = searchNode.FUN_00559450();
    }
    if (debug.FUN_00559450())
    {
        DebugMaterial* material = new DebugMaterial;
        material->FUN_0049ed90(true);
        debug.FUN_00559450()->FUN_00439410(material);
        AttachLightingPropertyRecursive(debug.FUN_00559450());
        FUN_00b57e30(debug.FUN_00559450(), 0, 0);
        if (extra)
            debug.FUN_00559450()->Attach(extra, true);
        DAT_011dea3c->FUN_008d6f30()->FUN_00524cf0()->Attach(debug.FUN_00559450(), true);
        debug.FUN_00559450()->FUN_00a5a040();
        DebugUpdate update(0.0f, 0, 0);
        debug.FUN_00559450()->FUN_00a59c60(update);
    }
}

namespace CombatAssessment {
// These records are filled by the game and copied as raw storage.


struct PositionData;
typedef PositionData Position;
struct Target;
struct Group;
struct SenseData;
typedef SenseData Sense;
struct Hit;
extern float DAT_0108d540;
float __cdecl FUN_00435dd0();
float __cdecl FUN_0040ebd0(float, float);

extern Setting DAT_011cd45c, DAT_011ce9b4;
struct Time
{
    int value;
    void FUN_00435de0(float);
    float FUN_006a7f50();
    float FUN_00435e00();
};


struct PositionData
{
    float pointStorage[3];
    int cell;
    void FUN_0097ede0();
    float FUN_00527a40(Position*);
    void SetTripleAndValue(NiPoint3*, void*);
    int FUN_0084e3a0();
};
typedef PositionData Position;
struct SenseData
{
    int unk00;
    int unk04;
    int score;
    float pointStorage[3];
    Time time;
    bool detected;
    char unk1d;
    bool visible;
    char unk1f;
    int score20;
    void FUN_0066e590();
};
typedef SenseData Sense;
struct Target
{
    int unk00;
    int score;
    Position lastKnown;
    Position search;
    Position seen;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    short state;
    short unk4a;
    Time seenTime;
    Time activeTime;
    Time updateTime;
    Time alertTime;
    Time hitTime;
    Time cooldown;
    unsigned char visibleCount;
    unsigned char detectedCount;
    short unk66;
};
struct Hit
{
    int unk00;
    float pointStorage[3];
    Time time;
};
struct Process
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual Hit* vf8(Actor*);
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual Sense* v504(Actor*, int);
};
struct DetectionViewData
{
    bool FUN_0099a360();
};

extern Actor* DAT_011dea3c;
void __cdecl MarkBaseExtraListScriptEvent(void*, void*, int);
struct Manager
{
    void TryStartDialogue(Actor*, Actor*, int, int, int, int);
};
extern Manager* DAT_011f1708;
struct Group
{
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    short state;
    Target* FUN_009865d0(Actor*);
    unsigned int FUN_00990890();
    Actor* GetIntAt(unsigned int);
    bool FUN_0097ef30();
    void StoreRecord(Position*, float, int);
    void UpdateTargetPerception(Actor*, Actor*, int*, Time*, bool*, bool*);
};
// @fnv 0x009887b0
void Group::UpdateTargetPerception(Actor* selected, Actor* subject, int* result, Time* timestamp, bool* visible,
                                   bool* detected)
{
    Time temp4Local2;
    Time temp3Local31;
    Time temp2Local6;
    Time temp1Local7;
    Time temp0Local20;
    Sense* reusedLocal18;
    float strengthLocal6;
    Position impactLocal48;
    Hit* hitLocal9;
    Actor* member2Local23;
    unsigned int index2Local31;
    CombatState* stateLocal7;
    int scoreLocal7;
    Position originLocal30;
    Position destinationLocal23;
    Actor* memberLocal19;
    Sense* senseLocal1;
    Sense fallbackLocal15;
    unsigned int indexLocal5;
    Actor* bestLocal4;
    Position nearestLocal9;
    Position currentLocal8;
    Time newestLocal2;
    unsigned int countLocal20;
    int maximumLocal6;
    bool missingLocal40;
    int highestLocal52;
    int previousLocal5;
    Target* targetLocal40;

    *visible = false;
    *detected = false;
    *result = -100;
    temp0Local20.FUN_00435de0(-DAT_0108d540);
    *timestamp = temp0Local20;
    targetLocal40 = FUN_009865d0(subject);
    if (targetLocal40)
    {
        previousLocal5 = targetLocal40->score;
        if (targetLocal40->updateTime.FUN_006a7f50() < FUN_00435dd0())
        {
            maximumLocal6 = -100;
            highestLocal52 = -100;
            missingLocal40 = false;
            if (!targetLocal40->search.FUN_0084e3a0())
                missingLocal40 = true;
            bestLocal4 = 0;
            targetLocal40->detectedCount = 0;
            targetLocal40->visibleCount = 0;
            nearestLocal9.FUN_0097ede0();
            newestLocal2.FUN_00435de0(-DAT_0108d540);
            countLocal20 = FUN_00990890();
            for (indexLocal5 = 0; indexLocal5 < countLocal20; indexLocal5++)
            {
                memberLocal19 = GetIntAt(indexLocal5);
                senseLocal1 = reinterpret_cast<Process*>(memberLocal19->FUN_008d8520())->v504(subject, 0);
                fallbackLocal15.FUN_0066e590();
                if (memberLocal19->FUN_00931850() && subject->FUN_00931850())
                {
                    memberLocal19->FUN_00575650(reinterpret_cast<::Position*>(&originLocal30));
                    subject->FUN_00575650(reinterpret_cast<::Position*>(&destinationLocal23));
                    if (originLocal30.FUN_00527a40(&destinationLocal23) < 67108864.0)
                    {
                        fallbackLocal15.score = 1;
                        senseLocal1 = &fallbackLocal15;
                    }
                }
                if (senseLocal1)
                {
                    if (senseLocal1->visible)
                        targetLocal40->visibleCount++;
                    if (senseLocal1->detected)
                        targetLocal40->detectedCount++;
                    if (memberLocal19 == selected)
                    {
                        *visible = senseLocal1->visible;
                        *detected = senseLocal1->detected;
                    }
                    scoreLocal7 = senseLocal1->score;
                    if (senseLocal1->score20 != 0x7fffffff)
                    {
                        if (highestLocal52 < senseLocal1->score20)
                            highestLocal52 = senseLocal1->score20;
                        if (scoreLocal7 == (int)*DAT_011cd45c.FUN_00403e20() + 1 &&
                            senseLocal1->score20 > *DAT_011cd45c.FUN_00403e20())
                            scoreLocal7 = (int)*DAT_011cd45c.FUN_00403e20();
                    }
                    stateLocal7 = reinterpret_cast<CombatState*>(memberLocal19->GetCombatController());
                    if (!stateLocal7 || stateLocal7->FUN_004030b0() != subject ||
                        reinterpret_cast<DetectionViewData*>(stateLocal7->FUN_00586150(memberLocal19, subject))->FUN_0099a360())
                    {
                        if (senseLocal1 && scoreLocal7 > maximumLocal6)
                        {
                            maximumLocal6 = scoreLocal7;
                            bestLocal4 = memberLocal19;
                        }
                    }
                    else
                    {
                        if (previousLocal5 > maximumLocal6)
                        {
                            maximumLocal6 = previousLocal5;
                            bestLocal4 = memberLocal19;
                        }
                    }
                    if (missingLocal40 && senseLocal1->time.FUN_006a7f50() > newestLocal2.FUN_006a7f50())
                    {
                        nearestLocal9.SetTripleAndValue(reinterpret_cast<NiPoint3*>(senseLocal1->pointStorage), memberLocal19->FUN_00575ca0());
                        newestLocal2 = senseLocal1->time;
                    }
                }
            }
            if (maximumLocal6 <= (int)*DAT_011cd45c.FUN_00403e20() && targetLocal40->cooldown.FUN_00435e00() < 1.0)
                maximumLocal6 = (int)(*DAT_011cd45c.FUN_00403e20() + 1.0);
            if (FUN_0097ef30() && previousLocal5 <= 0 && maximumLocal6 > 0)
            {
                if (targetLocal40->activeTime.FUN_006a7f50() != -DAT_0108d540)
                    DAT_011f1708->TryStartDialogue(bestLocal4, subject, 4, 9, 1, 0);
                else
                {
                    for (index2Local31 = 0; index2Local31 < countLocal20; index2Local31++)
                    {
                        member2Local23 = GetIntAt(index2Local31);
                        if (member2Local23 != DAT_011dea3c)
                            MarkBaseExtraListScriptEvent(member2Local23->GetCombatTarget(), member2Local23->FUN_005d43c0(), 0x8000);
                    }
                    DAT_011f1708->TryStartDialogue(bestLocal4, subject, 4, 3, 1, 0);
                }
            }
            targetLocal40->score = maximumLocal6;
            {
                temp1Local7.FUN_00435de0(FUN_00435dd0());
                targetLocal40->updateTime = temp1Local7;
            }
            subject->FUN_00575650(reinterpret_cast<::Position*>(&currentLocal8));
            if (maximumLocal6 > 0)
            {
                temp2Local6.FUN_00435de0(FUN_00435dd0());
                targetLocal40->activeTime = temp2Local6;
            }
            if (targetLocal40->activeTime.FUN_00435e00() < *DAT_011ce9b4.FUN_00403e20())
                targetLocal40->search = currentLocal8;
            else if (missingLocal40)
                targetLocal40->search = nearestLocal9;
            if (maximumLocal6 > (int)*DAT_011cd45c.FUN_00403e20())
            {
                {
                    temp3Local31.FUN_00435de0(FUN_00435dd0());
                    targetLocal40->alertTime = temp3Local31;
                }
                targetLocal40->lastKnown = currentLocal8;
                targetLocal40->state = this->state;
            }
            if (targetLocal40->detectedCount)
            {
                targetLocal40->seen = currentLocal8;
                {
                    temp4Local2.FUN_00435de0(FUN_00435dd0());
                    targetLocal40->seenTime = temp4Local2;
                }
            }
            if (highestLocal52 > *DAT_011cd45c.FUN_00403e20() && FUN_0097ef30())
            {
                hitLocal9 = reinterpret_cast<Process*>(subject->FUN_008d8520())->vf8(subject);
                if (hitLocal9 && hitLocal9->time.FUN_00435e00() < 5.0 &&
                    hitLocal9->time.FUN_006a7f50() > targetLocal40->hitTime.FUN_006a7f50())
                {
                    strengthLocal6 = 0;
                    if (highestLocal52 > 0)
                        strengthLocal6 = FUN_0040ebd0((float)(highestLocal52 / 20.0), 5.0f) + 55.0;
                    else
                        strengthLocal6 = (highestLocal52 - (int)*DAT_011cd45c.FUN_00403e20()) / 2.0 + 40.0;
                    impactLocal48.FUN_0097ede0();
                    impactLocal48.SetTripleAndValue(reinterpret_cast<NiPoint3*>(hitLocal9->pointStorage), subject->FUN_00575ca0());
                    StoreRecord(&impactLocal48, strengthLocal6, 0);
                    targetLocal40->hitTime = hitLocal9->time;
                }
            }
        }
        else
        {
            reusedLocal18 = selected ? reinterpret_cast<Process*>(selected->FUN_008d8520())->v504(subject, 0) : 0;
            if (reusedLocal18)
            {
                *visible = reusedLocal18->visible;
                *detected = reusedLocal18->detected;
            }
        }
        *result = targetLocal40->score;
        *timestamp = targetLocal40->activeTime;
    }
}
}

using ::SettingT;
class GameSettingCollection;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting382;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting383;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting384;
float& __fastcall FUN_00403e20(float* pValue);
extern float DAT_010162c0;

struct Pos9892
{
    float x;
    float y;
    float z;

    Pos9892 FUN_00439e90(const Pos9892& kOther) const;
    Pos9892 FUN_00439ef0(const Pos9892& kOther) const;
    Pos9892 FUN_0053d280(float fScale) const;
    float FUN_004a7290() const;
};

struct FUN_006915d0
{
    float m_af[9];

    FUN_006915d0(const Pos9892& kPos);
};

struct AvoidArray9892 : PathingAvoidNodeArray
{
    void AppendNode(const FUN_006915d0& kNode, float fA, float fB);
};

struct AvoidMember9892
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Pos9892* GetPos();
};

struct FUN_009892a0_shell
{
    unsigned int FUN_005a4320();
    AvoidMember9892* FUN_00968630(unsigned int uiIndex);
    PathingAvoidNodeArray* FUN_009892a0(AvoidMember9892* pActor, const Pos9892* pTarget, float fRadius,
                                        PathingAvoidNodeArray* pAvoidArray, AvoidMember9892* pIgnore);
};

// @fnv 0x009892a0
PathingAvoidNodeArray* FUN_009892a0_shell::FUN_009892a0(AvoidMember9892* pActor, const Pos9892* pTarget, float fRadius,
                                                        PathingAvoidNodeArray* pAvoidArray, AvoidMember9892* pIgnore)
{
    PathingAvoidNodeArray* pResult_2 = pAvoidArray;
    Pos9892 kCenterTmp = pActor->GetPos()->FUN_00439e90(*pTarget).FUN_0053d280(DAT_010162c0);
    Pos9892 kOffsetValue = pTarget->FUN_00439ef0(kCenterTmp);
    float afValueAfterThirdFloat = kOffsetValue.FUN_004a7290() + fRadius * fRadius;
    afValueAfterThirdFloat = FUN_00403e20((float*)&originalRuntimeFloatSetting382) *
                             FUN_00403e20((float*)&originalRuntimeFloatSetting382) * afValueAfterThirdFloat;
    unsigned int uiCountTmp = FUN_005a4320();
    for (unsigned int i4 = 0; i4 < uiCountTmp; i4++)
    {
        AvoidMember9892* pMember = FUN_00968630(i4);
        if (pMember != pIgnore)
        {
            Pos9892 kPos3 = *pMember->GetPos();
            Pos9892 kDelta_ = kCenterTmp.FUN_00439ef0(kPos3);
            if (kDelta_.FUN_004a7290() < afValueAfterThirdFloat)
            {
                if (!pResult_2)
                    pResult_2 = new PathingAvoidNodeArray;
                ((AvoidArray9892*)pResult_2)
                    ->AppendNode(FUN_006915d0(kPos3), FUN_00403e20((float*)&originalRuntimeFloatSetting383),
                                 FUN_00403e20((float*)&originalRuntimeFloatSetting384));
            }
        }
    }
    return pResult_2;
}

namespace CombatRegion {

struct Group;


struct Target
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned short unk48, flags;
    unsigned int unk4c;
    NiPoint3 point;
};
struct Location
{
    unsigned int unk00, unk04, unk08, unk0c;
    bool FUN_00527a00();
    bool FUN_00527990(unsigned int*, unsigned int*);
    void* FUN_006815c0();
    void* FUN_0084e3a0();
};
struct Timer
{
    unsigned int unk00, unk04;
    bool FUN_008d7f80();
    void FUN_0097f220();
    void FUN_008d7f40(float);
};
struct Region
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    Region(const NiPoint3&, unsigned int, unsigned int);
    Region(Actor*);
    ~Region();
    bool FUN_006dd6f0(int);
    void FUN_006f4ed0(void*);
    bool FUN_0098ad70();
};
struct RegionArray
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    RegionArray(unsigned int, int, int);
    ~RegionArray();
    void FUN_006cf1b0(const Region&);
    unsigned int FUN_0044ddc0();
};
struct FloatArray
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    FloatArray(unsigned int, int, int);
    ~FloatArray();
    void AppendFloat(const float&);
};
struct Shape
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;

    Shape();
    static __forceinline void* operator new(unsigned int);
    static __forceinline void operator delete(void*)
    {}
    float FUN_004a7bd0();
    void Reset();
    void FUN_006e0320(const Region&, float);
    void FUN_0098adb0(float);
};
void* FUN_00aa13e0(unsigned int);
__forceinline void* Shape::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
struct ShapePtr
{
    Shape* value;
    Shape* FUN_00559450();
    void FUN_0066b0d0(Shape*);
};


extern Setting DAT_011ce9b4, DAT_011ce528, DAT_011cf870, DAT_011cf42c, DAT_011ce43c;
extern double DAT_0106d508;
extern float DAT_0108d540;
extern Actor* DAT_011dea3c;
struct Manager
{
    void TryStartDialogue(Actor*, Group*, int, int, int, int);
};
extern Manager* DAT_011f1708;
bool FUN_006d6f80(unsigned int, unsigned int, const NiPoint3&, NiPoint3&);
float FUN_004b1480(float);
void BuildPathNodeHolder(ShapePtr*, RegionArray*, FloatArray*);
unsigned int FUN_00944460(unsigned int, unsigned int);
struct Group
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int generation;
    ShapePtr shape;
    Timer updateTimer;
    Timer refreshTimer;
    unsigned int unke8;
    Actor* focus;
    Location location;
    NiPoint3 position;
    float radius;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned char changed;
    unsigned char unk135;
    unsigned short unk136;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int capacity;
    unsigned int count;
    unsigned int FUN_005a4320();
    bool FUN_0097ef30();
    void FUN_0098bae0();
    Target* FUN_009871c0(unsigned int);
    void FUN_0098add0();
    bool UpdateAndCheckChanged();
    unsigned int FUN_00990890();
    Actor* GetIntAt(unsigned int);
    Target* FUN_009865d0(Group*);
    void FUN_0098a580();
};
// @fnv 0x0098a580
void Group::FUN_0098a580()
{
    if (capacity)
    {
        unsigned int total = FUN_005a4320();
        bool fullSlot14 = false;
        if (!total || count >= capacity)
            fullSlot14 = true;
        if (FUN_0097ef30())
        {
            if (fullSlot14)
                FUN_0098bae0();
            else
            {
                for (unsigned int index = 0; index < total; index++)
                {
                    Target* target = FUN_009871c0(index);
                    if (target->point.FUN_00435e00() < *DAT_011ce9b4.FUN_00403e20())
                    {
                        FUN_0098bae0();
                        break;
                    }
                }
            }
        }
        else if (!fullSlot14)
        {
            unsigned int farCountSlot0 = 0;
            unsigned int flaggedSlot0 = 0;
            for (unsigned int index = 0; index < total; index++)
            {
                Target* target = FUN_009871c0(index);
                if (target->point.FUN_00435e00() >= *DAT_011ce528.FUN_00403e20())
                    farCountSlot0++;
                if (target->flags)
                    flaggedSlot0++;
            }
            if (flaggedSlot0 && farCountSlot0 == total)
                FUN_0098add0();
        }
    }
    if (FUN_0097ef30())
    {
        if (focus && (focus->FUN_008b3b90() || !focus->FUN_008b3bf0()))
            focus = 0;
        if (updateTimer.FUN_008d7f80())
        {
            if (shape.FUN_00559450() && shape.FUN_00559450()->FUN_004a7bd0() > DAT_0106d508)
            {
                shape.FUN_00559450()->Reset();
                generation++;
                refreshTimer.FUN_0097f220();
            }
            bool refreshSlot1 = false;
            if (refreshTimer.FUN_008d7f80())
            {
                refreshSlot1 = UpdateAndCheckChanged();
                refreshTimer.FUN_008d7f40(*DAT_011cf870.FUN_00403e20());
            }
            if (location.FUN_00527a00())
            {
                if (!shape.FUN_00559450() || refreshSlot1)
                {
                    unsigned int endSlot0 = 0;
                    unsigned int start = 0;
                    if (location.FUN_00527990(&start, &endSlot0))
                    {
                        NiPoint3 selected;
                        if (FUN_006d6f80(endSlot0, start, position, selected))
                        {
                            Region region(selected, start, endSlot0);
                            if (region.FUN_006dd6f0(0))
                            {
                                region.FUN_006f4ed0(location.FUN_006815c0());
                                if (!shape.FUN_00559450())
                                    shape.FUN_0066b0d0(new Shape);
                                shape.FUN_00559450()->FUN_006e0320(region, radius);
                                shape.FUN_00559450()->FUN_0098adb0(*DAT_011cf42c.FUN_00403e20());
                                changed = 1;
                            }
                        }
                    }
                }
            }
            else if (shape.FUN_00559450())
                shape.FUN_0066b0d0(0);
            if (shape.FUN_00559450())
            {
                unsigned int memberCount = FUN_00990890();
                RegionArray regionsSlot11(memberCount, 0, 0);
                FloatArray headingsSlot11(memberCount, 0, 0);
                for (unsigned int memberIndex = 0; memberIndex < memberCount; memberIndex++)
                {
                    Actor* member = GetIntAt(memberIndex);
                    if (member->FUN_00575ca0() != location.FUN_0084e3a0())
                        continue;
                    Region memberRegionSlot0(member);
                    if (memberRegionSlot0.FUN_0098ad70())
                    {
                        regionsSlot11.FUN_006cf1b0(memberRegionSlot0);
                        headingsSlot11.AppendFloat(FUN_004b1480(member->GetCurrentTargetDistance(false)));
                    }
                }
                if (regionsSlot11.FUN_0044ddc0())
                {
                    float previous = shape.FUN_00559450()->FUN_004a7bd0();
                    BuildPathNodeHolder(&shape, &regionsSlot11, &headingsSlot11);
                    if (previous != shape.FUN_00559450()->FUN_004a7bd0())
                        changed = 1;
                }
            }
            updateTimer.FUN_008d7f40(*DAT_011ce43c.FUN_00403e20());
            unsigned int actorCountSlot3 = FUN_00990890();
            unsigned int chosenSlot40 = FUN_00944460(0, actorCountSlot3);
            Actor* actor = GetIntAt(chosenSlot40);
            Group* otherSlot37 = reinterpret_cast<Group*>(actor->GetCombatTarget());
            if (actor != DAT_011dea3c && otherSlot37)
            {
                Target* target = FUN_009865d0(otherSlot37);
                if (target && target->point.FUN_006a7f50() != -DAT_0108d540)
                    DAT_011f1708->TryStartDialogue(actor, otherSlot37, 4, 1, 0, 0);
                else
                    DAT_011f1708->TryStartDialogue(actor, otherSlot37, 4, 0, 0, 0);
            }
        }
    }
}
}

// Recount the group's members: how many are flagged, and how many are alive versus not.

class CE80Process
{
  public:
    bool IsFlagged();
    bool IsAlive();
};



class CE80Group
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    unsigned int m_uiFlagged;
    unsigned int m_uiAlive;
    unsigned int m_uiOther;

    unsigned int GetCount();
    Actor* GetAt(int iIndex);
    void RecountActors();
};

// Resets the flagged, alive and other counters, then tallies each actor's process by IsFlagged and IsAlive.
// @fnv 0x0098ce80
void CE80Group::RecountActors()
{
    m_uiFlagged = 0;
    m_uiAlive = 0;
    m_uiOther = 0;
    unsigned int ItemUpdateArray = GetCount();
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        Actor* pkActor = GetAt(i);
        CE80Process* pkAI = reinterpret_cast<CE80Process*>(pkActor->GetCombatController());
        if (pkAI)
        {
            if (pkAI->IsFlagged())
                m_uiFlagged++;
            if (pkAI->IsAlive())
                m_uiAlive++;
            else
                m_uiOther++;
        }
    }
}

struct LoadPair
{
    int x, y;
    void FUN_009a5f20(BGSLoadFormBuffer*);
};
struct LoadRef
{
    int x;
    void FUN_009a5ff0(BGSLoadFormBuffer*);
};
struct LoadItem
{
    int x00, x04, x08, x0c, x10;
    LoadItem();
    void FUN_00985b10(BGSLoadFormBuffer*, void*);
};
struct LoadNode
{
    void FUN_00985800(BGSLoadFormBuffer*, void*);
};
struct MemberNode
{
    void FUN_00985a50(BGSLoadFormBuffer*, void*);
};
struct LoadExtra
{
    int x00, x04, x08, x0c;
    LoadRef ref;
    int id;
    int value;
    void FUN_00527ba0(BGSLoadFormBuffer*);
};

struct ParentNode
{
    TESObjectREFR* a;
    TESObjectREFR* b;
    char c, d, e;
};
struct LoadAnim
{
    int x00;
    int x04;
    int x08;
    int x0c;
    int x10;
    int x14;
    int x18;
    int x1c;
    int x20;
    int x24;
    int x28;
    int x2c;
    int x30;
    int x34;
    int x38;
    int x3c;
    int x40;
    int x44;
    int x48;
    int x4c;
    int x50;
    LoadAnim();
    static void* operator new(unsigned int);
    void FUN_006e0d20(BGSLoadFormBuffer*);
};
struct LoadPtr
{
    LoadAnim* p;
    LoadPtr& operator=(LoadAnim*);
    operator LoadAnim*() const;
};
struct ArrItems
{
    int x0, x4, x8, xc;
    void SetSize(unsigned int, bool);
    LoadItem*& FUN_006a7ad0(unsigned int);
};
struct ArrMembers
{
    int x0, x4, x8, xc;
    void FUN_0098f040(unsigned int, bool);
    MemberNode* FUN_006dad90(unsigned int) const;
};
struct ArrExtra
{
    int x0, x4, x8, xc;
    void FUN_0098f2f0(unsigned int, bool);
    LoadExtra* GetElementAt(unsigned int);
};
struct ArrParents
{
    int x0, x4, x8, xc;
    void FUN_006a8890(unsigned int, bool);
    ParentNode& GetAt(int);
};
struct LoadHandle
{
    int x0, x4, x8, xc;
    void FUN_00527ba0(BGSLoadFormBuffer*);
};
struct GroupLoad
{
    int unk000;
    int unk004;
    BSSimpleArray<CombatTarget> nodes;
    ArrMembers members;
    int strategy;
    char flag;
    char unk02d;
    char unk02e;
    char unk02f;
    LoadPair pair30;
    LoadPair pair38;
    int unk040;
    LoadRef ref44;
    LoadPair pair48;
    LoadPair pair50;
    LoadPair timers[10];
    LoadPair paira8;
    LoadPair pairb0;
    LoadPair pairb8;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    unsigned int active;
    LoadPtr anim;
    LoadPair paird8;
    LoadPair paire0;
    LoadRef refe8;
    int unk0ec;
    LoadHandle handle;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    ArrExtra extras;
    ArrParents parents;
    int unk130;
    char loaded;
    char unk135;
    char unk136;
    char unk137;
    ArrItems items;
    int unk148;
    int unk14c;
    int unk150;
    char flag154;
    void FUN_0098e3d0(BGSLoadFormBuffer* buffer);
};
// Reads item, node and member arrays plus strategy, flags, pairs, timers, active-state extras/parents and optional anim from the buffer.
// @fnv 0x0098e3d0
void GroupLoad::FUN_0098e3d0(BGSLoadFormBuffer* buffer)
{
    {
        unsigned int countItems = buffer->FUN_00864a60();
        items.SetSize(countItems, true);
        for (unsigned int indexItems = 0; indexItems < countItems; indexItems++)
        {
            LoadItem*& item = items.FUN_006a7ad0(indexItems);
            item = new LoadItem;
            item->FUN_00985b10(buffer, this);
        }
    }
    {
        unsigned int countNodes = buffer->FUN_00864a60();
        nodes.SetSize(countNodes, true);
        for (unsigned int indexNodes = 0; indexNodes < countNodes; indexNodes++)
        {
            LoadNode* node = reinterpret_cast<LoadNode*>(&nodes.GetAt(indexNodes));
            node->FUN_00985800(buffer, this);
        }
    }
    {
        unsigned int countMembers = buffer->FUN_00864a60();
        members.FUN_0098f040(countMembers, true);
        for (unsigned int indexMembers = 0; indexMembers < countMembers; indexMembers++)
        {
            MemberNode* member = members.FUN_006dad90(indexMembers);
            member->FUN_00985a50(buffer, this);
        }
    }
    char strategyIndex = -1;
    buffer->FUN_00864980(&strategyIndex, 1u);
    if (strategyIndex != -1)
        strategy = FUN_0098e980(strategyIndex);
    buffer->FUN_00864980(&flag, 1u);
    pair30.FUN_009a5f20(buffer);
    pair38.FUN_009a5f20(buffer);
    buffer->FUN_00864980(&unk040, 4u);
    ref44.FUN_009a5ff0(buffer);
    pair48.FUN_009a5f20(buffer);
    pairb0.FUN_009a5f20(buffer);
    paira8.FUN_009a5f20(buffer);
    for (unsigned int indexTimers = 0; indexTimers < 10; indexTimers++)
        timers[indexTimers].FUN_009a5f20(buffer);
    buffer->FUN_00864980(&active, 4u);
    if (active > 0)
    {
        buffer->FUN_008648e0((void*)&unk0ec);
        buffer->FUN_00864980(&unk100, 12u);
        paird8.FUN_009a5f20(buffer);
        paire0.FUN_009a5f20(buffer);
        if (buffer->GetVersion() >= 5)
            refe8.FUN_009a5ff0(buffer);
        handle.FUN_00527ba0(buffer);
        buffer->FUN_00864980(&unk10c, 4u);
        {
            unsigned int countExtras = buffer->FUN_00864a60();
            extras.FUN_0098f2f0(countExtras, true);
            for (unsigned int indexExtras = 0; indexExtras < countExtras; indexExtras++)
            {
                LoadExtra* extra = extras.GetElementAt(indexExtras);
                extra->FUN_00527ba0(buffer);
                buffer->FUN_00864980(&extra->value, 4u);
                buffer->FUN_008648e0((void*)&extra->id);
                extra->ref.FUN_009a5ff0(buffer);
            }
        }
        {
            unsigned int countParents = buffer->FUN_00864a60();
            parents.FUN_006a8890(countParents, true);
            for (unsigned int indexParents = 0; indexParents < countParents; indexParents++)
            {
                ParentNode& parent = parents.GetAt(indexParents);
                parent.a = dynamic_cast<TESObjectREFR*>(_ref_004839c0(buffer->FUN_008648a0()));
                parent.b = dynamic_cast<TESObjectREFR*>(_ref_004839c0(buffer->FUN_008648a0()));
                buffer->FUN_00864980(&parent.c, 1u);
                buffer->FUN_00864980(&parent.d, 1u);
                buffer->FUN_00864980(&parent.e, 1u);
            }
        }
        bool hasAnim = false;
        buffer->FUN_00864980(&hasAnim, 1u);
        if (hasAnim)
        {
            anim = new LoadAnim;
            ((LoadAnim*)anim)->FUN_006e0d20(buffer);
        }
        loaded = 1;
    }
    pair50.FUN_009a5f20(buffer);
    buffer->FUN_00864980(&unk0c0, 4u);
    buffer->FUN_00864980(&unk0c4, 4u);
    buffer->FUN_00864980(&unk0c8, 4u);
    buffer->FUN_00864980(&unk0cc, 4u);
    pairb8.FUN_009a5f20(buffer);
    buffer->FUN_00864980(&flag154, 1u);
}

struct UpdateOwner;
struct UpdateElement
{
    unsigned int data;
    void FUN_00985930(unsigned int, UpdateOwner*);
};
struct UpdateArray
{
    int unk00, unk04, unk08, unk0c;
    unsigned int FUN_0044ddc0();
    UpdateElement* FUN_0096a2b0(unsigned int);
    UpdateElement* FUN_006dad90(unsigned int);
    void FUN_0098ef10(unsigned int, unsigned int);
    void RemoveEntries(unsigned int, unsigned int);
};
extern CombatManager* DAT_011f1958;
extern const unsigned int DAT_01183028, DAT_011846d4;
void* FUN_00ec43fb(void*, int, const void*, const void*, int);
struct UpdateOwner
{
    int unk00, unk04;
    UpdateArray first, second;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    union
    {
        unsigned int id;
        Actor* actor;
    } reference;
    bool FUN_0097ef30();
    void RecountActors();
    void UpdateElements(unsigned int);
};
// @fnv 0x0098e990
void UpdateOwner::UpdateElements(unsigned int argument)
{
    unsigned int countFirst = first.FUN_0044ddc0();
    for (unsigned int indexFirst2 = 0; indexFirst2 < countFirst; indexFirst2++)
    {
        bool removeFirst = false;
        UpdateElement* elementFirst = first.FUN_0096a2b0(indexFirst2);
        elementFirst->FUN_00985930(argument, this);
        if (elementFirst->data)
            DAT_011f1958->TargetLocalActor(reinterpret_cast<Actor*>(elementFirst->data),
                                            reinterpret_cast<ActorCombatGroup*>(this));
        else
            removeFirst = true;
        if (removeFirst)
        {
            first.FUN_0098ef10(indexFirst2, 1);
            indexFirst2--;
            countFirst--;
        }
    }
    {
        unsigned int countSecond4 = second.FUN_0044ddc0();
        for (unsigned int indexSecond = 0; indexSecond < countSecond4; indexSecond++)
        {
            bool removeSecond3 = false;
            UpdateElement* elementSecond3 = second.FUN_006dad90(indexSecond);
            elementSecond3->FUN_00985930(argument, this);
            if (!elementSecond3->data)
                removeSecond3 = true;
            if (removeSecond3)
            {
                second.RemoveEntries(indexSecond, 1);
                indexSecond--;
                countSecond4--;
            }
        }
    }
    if (FUN_0097ef30())
        reference.actor = reference.id ? dynamic_cast<Actor*>(_ref_004839c0(reference.id)) : 0;
    RecountActors();
}

namespace fnv_009a1280 {
extern double DAT_01017a40;
extern double DAT_01017a10;
extern double __cdecl FUN_0047eeb0(unsigned int);



// 0x00527a40 is a world-location distance (pos + cell at +0x0c, FLT_MAX across cells; bgsworldlocation.cpp),
// so the condition holds a location here, not a TimeoutTimer.
struct ConditionLocation
{
    float x, y, z;
    void* cell;
    double FUN_00527a40(int location);
};
struct CombatCondition
{
    unsigned char mode;
    unsigned char misc1;
    unsigned char misc2;
    unsigned char misc3;
    unsigned int flags;
    ConditionLocation location;
};
struct EventEvaluator
{
    int __thiscall FUN_00575650(EventPositionOutput_00575650* values);
};

struct CombatLogic
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    CombatCondition* condition;
    unsigned char miscC8;
    unsigned char phase;
    unsigned short miscCA;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned char needsUpdate;
    unsigned char miscD9;
    unsigned char miscDA;
    unsigned char miscDB;
    unsigned int unk0dc;
    unsigned int unk0e0;
    CombatState* state;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    CombatController* controller;
    void __thiscall FUN_009a03d0(int);
    void __thiscall FUN_009a1280(bool update);
};
// @fnv 0x009a1280
void CombatLogic::FUN_009a1280(bool update)
{
    if (phase < 4)
    {
        if (FUN_0047eeb0(phase) < DAT_01017a40)
        {
            ++phase;
        }
        controller->FUN_0097f200();
        if (update && condition && condition->mode == 1)
        {
            float values[4];
            if (condition->location.FUN_00527a40(reinterpret_cast<EventEvaluator*>(controller->m_pkAttacker)->FUN_00575650(reinterpret_cast<EventPositionOutput_00575650*>(values))) < DAT_01017a10)
            {
                update = false;
            }
        }
        if (update)
        {
            needsUpdate = false;
        }
        if (state && state->type == 12)
        {
            FUN_009a03d0(0);
        }
    }
}
}  // namespace fnv_009a1280

struct CFUN98fb40Elem
{
    void* pActor;
    unsigned int m_uiGoalFlags;
    float m_fClusterOffsetX;
    float m_fClusterOffsetY;
    void* pCluster;

    CFUN98fb40Elem();
};

struct CFUN98fb40Owner
{
    void __thiscall FUN_0098fb40(CombatClusterMember* pDest, unsigned int ItemUpdateArray);
};

// @fnv 0x0098fb40
void CFUN98fb40Owner::FUN_0098fb40(CombatClusterMember* pDest, unsigned int auiCount)
{
    for (unsigned int i = 0; i < auiCount; i++)
    {
        new (&pDest[i]) CFUN98fb40Elem();
    }
}

struct ScoreValue
{
    int value;
    ScoreValue(float x);
    ScoreValue();
    float FUN_006a7f50();
    float FUN_00435e00();
};
struct PoseData
{
    float a, b, c;
    int d;
    int FUN_0084e3a0();
    float FUN_00527a40(const PoseData*);
};
struct MovementPose;
struct OtherState
{
    ScoreValue GetValue98();
    bool FUN_0097ee90();
    bool IsModifierZero();
    bool HasItemWithinRadius(const PoseData*, float);
};
struct MovementPose
{
    float FUN_00639aa0();
    PoseData* GetValue98();
};
struct ConditionFlag
{
    bool FUN_0076b610();
};

extern Setting DAT_011f1840;
extern float DAT_0108d540, DAT_0101ff50, DAT_0108d660, DAT_011a4d78, DAT_011a4d74;
extern float DAT_011a4d70, DAT_011a4d6c, DAT_011a4d68, DAT_011a4d64, DAT_011a4d60;
extern float DAT_011f18b0, DAT_01032adc, DAT_011a4d5c, DAT_011a4d58, DAT_011a4d54, DAT_011a4d50;
extern double DAT_01012060, DAT_01023128, DAT_0108d658, DAT_0101db88;
struct ActorSelect
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual int GetDistanceValue();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool GetFirstCondition(int);
    virtual bool GetSecondCondition();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual ActorSelect* GetTarget();
    int FUN_004030b0();
    OtherState* FUN_00586150();
    MovementPose* FUN_00980070();
    int FUN_00567d90();
    bool FUN_00566950();
    bool IsHostileTo(ActorSelect*, int, int*, int);
    void FUN_00575650(PoseData*);
    bool FUN_008a6650(int);
};
struct CandidateLink
{
    ActorSelect* actor;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    unsigned short unk48;
    unsigned short threshold;
    int unk4c, unk50, unk54;
    ScoreValue timestamp;
};
extern bool __cdecl FUN_009a9630(ActorSelect*);
extern bool __cdecl IsWithinAimLimits(ActorSelect*, int, float, float);
extern bool __cdecl FUN_009a96f0(ActorSelect*, PoseData*);
extern float __cdecl FUN_0040ebd0(float, float);
extern float __cdecl FUN_00404010(float, float);
struct ActorPicker
{
    int unk00;
    int unk04;
    ConditionFlag condition;
    int unk0c;
    void FUN_009869a0(ActorSelect*);
    int FUN_005a4320();
    CandidateLink* FUN_009871c0(unsigned int);
    void UpdateTargetPerception(ActorSelect*, ActorSelect*, int*, ScoreValue*, bool*, bool*);
    ActorSelect* SelectActor(ActorSelect*);
};
// @fnv 0x00986c60
ActorSelect* ActorPicker::SelectActor(ActorSelect* actor)
{
    if (condition.FUN_0076b610())
        return 0;
    float bestScore7 = -DAT_0108d540;
    ScoreValue reference_2(-DAT_0108d540);
    ActorSelect* bbestActor9 = 0;
    ActorSelect* ffirstActor3 = 0;
    ActorSelect* fallbackTmp = 0;
    PoseData baactorPose_2;
    actor->FUN_00575650(&baactorPose_2);
    ActorSelect* centerA = actor->GetTarget();
    if (!centerA)
    {
        FUN_009869a0(actor);
        return 0;
    }
    ActorSelect* firstB8 = (ActorSelect*)centerA->FUN_004030b0();
    OtherState* pkState3 = centerA->FUN_00586150();
    float thresholdA = centerA->FUN_00980070()->FUN_00639aa0();
    int factionNum = actor->FUN_00567d90();
    bool hactorTypeTmp = FUN_009a9630(actor);
    unsigned int count113 = FUN_005a4320();
    for (unsigned int index = 0; index < count113; ++index)
    {
        CandidateLink* entry36 = FUN_009871c0(index);
        ActorSelect* candidate18 = entry36->actor;
        if (thresholdA > 0.0)
        {
            if (!IsWithinAimLimits(actor, candidate18->GetDistanceValue(), (float)(thresholdA * DAT_01023128),
                                   DAT_0101ff50))
                continue;
        }
        if (*DAT_011f1840.FUN_00408d60())
        {
            int candidateFaction = candidate18->FUN_00567d90();
            if (factionNum != candidateFaction)
                continue;
        }
        if (actor->FUN_00566950())
        {
            int ignored = 0;
            if (!actor->IsHostileTo(candidate18, 0, &ignored, 0))
                continue;
        }
        bool lOther = false;
        int pisValid_ = 0;
        bool bshapeChanged_2 = false;
        bool isClose = false;
        ScoreValue value3;
        UpdateTargetPerception(actor, candidate18, &pisValid_, &value3, &bshapeChanged_2, &isClose);
        if (pisValid_ < 0 && candidate18 == firstB8 && pkState3->FUN_0097ee90())
            pisValid_ = 1;
        if (pisValid_ > 0)
        {
            float score = 0.0f;
            if (count113 > 1)
            {
                if (isClose)
                    score += DAT_011a4d78;
                if (bshapeChanged_2)
                    score += DAT_011a4d74;
                if (firstB8 == candidate18)
                {
                    score += DAT_011a4d70;
                    if (!isClose)
                    {
                        if (centerA->FUN_00586150()->GetValue98().FUN_00435e00() < DAT_011a4d6c)
                            score += DAT_011a4d78;
                    }
                }
                bool kcandidateType3 = FUN_009a9630(candidate18);
                if (hactorTypeTmp == kcandidateType3)
                    score += DAT_011a4d68;
                float pmeasure9 = 0.0f;
                PoseData spose8;
                candidate18->FUN_00575650(&spose8);
                bool difference3 = spose8.FUN_0084e3a0() != baactorPose_2.FUN_0084e3a0();
                if (difference3)
                {
                    if (candidate18 == firstB8)
                        pmeasure9 = 0.0f;
                    else
                        pmeasure9 = DAT_011a4d64 * DAT_011a4d64;
                }
                else
                {
                    pmeasure9 = baactorPose_2.FUN_00527a40(&spose8);
                }
                pmeasure9 = FUN_0040ebd0(DAT_0108d660, pmeasure9);
                score += (1.0f - pmeasure9 / DAT_0108d658) * DAT_011a4d60;
                unsigned int cfsameActor = firstB8 == candidate18;
                if (entry36->threshold > cfsameActor)
                    score += DAT_011f18b0;
                if ((pkState3->IsModifierZero() || difference3) && pkState3->HasItemWithinRadius(&spose8, DAT_01032adc))
                    score -= DAT_011a4d5c;
                if (difference3 && !FUN_009a96f0(actor, &spose8))
                    score -= DAT_011a4d58;
                if (candidate18->GetFirstCondition(0) || candidate18->GetSecondCondition())
                    score -= DAT_011a4d54;
                if (candidate18->FUN_008a6650(0))
                    score -= DAT_011a4d50;
            }
            if (score > bestScore7)
            {
                bestScore7 = score;
                bbestActor9 = candidate18;
            }
        }
        else
        {
            float cutoff = entry36->timestamp.FUN_006a7f50() - DAT_0101db88;
            value3 = FUN_00404010(cutoff, value3.FUN_006a7f50());
            if (value3.FUN_006a7f50() > reference_2.FUN_006a7f50())
            {
                ffirstActor3 = candidate18;
                reference_2 = value3;
            }
        }
        fallbackTmp = candidate18;
    }
    if (!bbestActor9)
        bbestActor9 = ffirstActor3;
    if (!bbestActor9)
        bbestActor9 = fallbackTmp;
    return bbestActor9;
}

struct B989700Entry
{
    Actor* m_pkRef;
    bool IsElapsedTimeBelowSetting();
};
struct B989700List
{
    unsigned int FUN_005a4320();
    B989700Entry* FUN_009871c0(unsigned int uiIndex);
    Actor* FindRefInRadius(B9897F0Point* pkPoint, float fRadius, bool bCheck);
};
// @fnv 0x00989700
Actor* B989700List::FindRefInRadius(B9897F0Point* pkPoint, float afRadius, bool bCheck)
{
    float fRadiusSqr = afRadius * afRadius;
    unsigned int ItemUpdateArray = FUN_005a4320();
    for (unsigned int i = 0; i < ItemUpdateArray; ++i)
    {
        B989700Entry* pkEntry = FUN_009871c0(i);
        if (!bCheck || pkEntry->IsElapsedTimeBelowSetting())
        {
            B9897F0Quad kPos;
            pkEntry->m_pkRef->FUN_00575650(reinterpret_cast<::Position*>(&kPos));
            if (pkPoint->GetSquaredDistance(kPos) < fRadiusSqr)
                return pkEntry->m_pkRef;
        }
    }
    return 0;
}

struct B9898B0Group
{
    unsigned int FUN_00990890();
    Actor* GetIntAt(unsigned int uiIndex);
    Actor* FindClosestRef(B9897F0Point* pkPoint, Actor* pkExclude, float fRadius);
};
// @fnv 0x009898b0
Actor* B9898B0Group::FindClosestRef(B9897F0Point* pkPoint, Actor* pkExclude, float afMaxDist)
{
    float fBestDistSqr2 = (afMaxDist == DAT_0108d540) ? DAT_0108d540 : (float)(afMaxDist * afMaxDist);
    Actor* pkClosest = 0;
    unsigned int uiCount2 = FUN_00990890();
    for (unsigned int i = 0; i < uiCount2; ++i)
    {
        Actor* pkRef = GetIntAt(i);
        if (pkRef == pkExclude)
            continue;
        B9897F0Quad kPos;
        pkRef->FUN_00575650(reinterpret_cast<::Position*>(&kPos));
        float fDistSqr2 = pkPoint->GetSquaredDistance(kPos);
        if (fDistSqr2 < fBestDistSqr2)
        {
            fBestDistSqr2 = fDistSqr2;
            pkClosest = pkRef;
        }
    }
    return pkClosest;
}

struct AssessmentSub
{
    float GetFirstLightParameter();
    float FUN_00453700();
};

struct AssessmentProcess
{
    bool FUN_00981990();
    AssessmentSub* FUN_00586150();
};

struct AssessmentActor : FUN_0098cb30_inner
{
    float FUN_008be600();
    float GetModifiedDamagePerSecond(float);
    bool FUN_008a6650(int);
};

struct TargetAssessmentEntry
{
    AssessmentActor* actor;
    int unk04;
    float unk08;
    float unk0C;
};

struct TargetAssessmentGroup
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
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    float unkC0;
    float unkC4;
    float unkC8;
    float unkCC;

    unsigned int FUN_00990890();
    TargetAssessmentEntry* FUN_00988790(unsigned int idx);
    unsigned int FUN_005a4320();
    AssessmentActor* FUN_00968630(unsigned int idx);

    void FUN_0098c870();
};

// @fnv 0x0098c870
void TargetAssessmentGroup::FUN_0098c870()
{
    unsigned int _countLocal;
    unsigned int _totalCells;
    unsigned int _modelCount;
    unsigned int _total;
    unsigned int _sampleIndex;
    bool _attackFlag;
    TargetAssessmentEntry* _itemBuffer;
    AssessmentProcess* _pProcess;
    unsigned int _curIdx;
    AssessmentActor* _TargetModeCur;
    float _ValPitch6;
    AssessmentProcess* _process;

    unkC0 = 0.0f;
    unkC4 = 0.0f;

    _modelCount = FUN_00990890();
    _total = 0;
    for (_sampleIndex = 0; _sampleIndex < _modelCount; _sampleIndex++)
    {
        _attackFlag = false;
        _itemBuffer = FUN_00988790(_sampleIndex);
        if (_itemBuffer->actor == (AssessmentActor*)_g_thePlayer)
        {
            _itemBuffer->unk08 = ((AssessmentActor*)_g_thePlayer)->FUN_008be600();
            _itemBuffer->unk0C = ((AssessmentActor*)_g_thePlayer)->GetModifiedDamagePerSecond(_itemBuffer->unk08);
        }
        else
        {
            _pProcess = (AssessmentProcess*)_itemBuffer->actor->v10A();
            if (_pProcess)
            {
                _attackFlag = _pProcess->FUN_00981990();
                _itemBuffer->unk08 = _pProcess->FUN_00586150()->GetFirstLightParameter();
                _itemBuffer->unk0C = _pProcess->FUN_00586150()->FUN_00453700();
            }
        }

        if (!_attackFlag && _itemBuffer->unk0C >= 0.0 && _itemBuffer->unk08 >= 0.0)
        {
            unkC0 += _itemBuffer->unk0C;
            unkC4 += _itemBuffer->unk08;
            _total++;
        }
    }

    if (_total)
    {
        unkC4 = unkC4 / _total;
    }

    unkC8 = 0.0f;
    unkCC = 0.0f;

    _countLocal = FUN_005a4320();
    _totalCells = 0;
    for (_curIdx = 0; _curIdx < _countLocal; _curIdx++)
    {
        _ValPitch6 = -1.0f;
        _TargetModeCur = FUN_00968630(_curIdx);
        if (_TargetModeCur == (AssessmentActor*)_g_thePlayer)
        {
            _ValPitch6 = ((AssessmentActor*)_g_thePlayer)->GetModifiedDamagePerSecond(-1.0f);
        }
        else if (!_TargetModeCur->FUN_008a6650(0))
        {
            _process = (AssessmentProcess*)_TargetModeCur->v10A();
            if (_process)
            {
                _ValPitch6 = _process->FUN_00586150()->FUN_00453700();
            }
            else
            {
                _ValPitch6 = _TargetModeCur->GetModifiedDamagePerSecond(-1.0f);
            }
        }

        if (_ValPitch6 >= 0.0)
        {
            unkC8 += _ValPitch6;
            _totalCells++;
        }
    }

    if (_totalCells)
    {
        unkCC = unkC8 / _totalCells;
    }
}

void __cdecl FUN_005b5e40(const char* fmt, ...);
struct ActQ
{
    virtual void v000(), v001(), v002(), v003(), v004(), v005(), v006(), v007(), v008(), v009(), v010(), v011(), v012(),
        v013(), v014(), v015(), v016(), v017(), v018(), v019(), v020(), v021(), v022(), v023(), v024(), v025(), v026(),
        v027(), v028(), v029(), v030(), v031(), v032(), v033(), v034(), v035(), v036(), v037(), v038(), v039(), v040(),
        v041(), v042(), v043(), v044(), v045(), v046(), v047(), v048(), v049(), v050(), v051(), v052(), v053(), v054(),
        v055(), v056(), v057(), v058(), v059(), v060(), v061(), v062(), v063(), v064(), v065(), v066(), v067(), v068(),
        v069(), v070(), v071(), v072(), v073(), v074(), v075();
    virtual const char* GetNameQ();
    void* FUN_00474cb0();
    const char* FUN_0055d520();
    unsigned int FUN_0084e3a0();
};
struct TgtQ
{
    int unk[26];
    TgtQ* Init(ActQ* pActor, int iVal);
};
struct TgtLstQ
{
    int unk00;
    void FUN_0098eec0(TgtQ* pTarget);
};
struct GrpQ
{
    int unk00, unk04;
    TgtLstQ kTargets;
    char pad[0xc4];
    int unkD0;
    bool FUN_009865b0(ActQ*);
    bool FUN_009866d0(ActQ*);
    bool FUN_00986a80(ActQ*);
    bool FUN_00986410(ActQ* pActor);
};
// Returns early based on two actor checks, rejects actors accepted by a third check, otherwise appends a target and updates the group.
// @fnv 0x00986410
bool GrpQ::FUN_00986410(ActQ* pActor)
{
    if (!pActor)
        return false;
    if (FUN_009865b0(pActor))
        return true;
    if (!FUN_009866d0(pActor))
        return false;
    if (FUN_00986a80(pActor))
    {
        FUN_005b5e40("COMBAT: Trying to add actor %08X %s to Combat Group target list when they are a member.",
                     pActor->FUN_0084e3a0(), pActor->FUN_00474cb0() ? pActor->GetNameQ() : pActor->FUN_0055d520());
        return false;
    }
    TgtQ kTarget;
    kTargets.FUN_0098eec0(kTarget.Init(pActor, unkD0));
    DAT_011f1958->AddCombatGroupTarget(reinterpret_cast<ActorCombatGroup*>(this), reinterpret_cast<Actor*>(pActor));
    return true;
}

struct Owner_9862e0;
struct Target_9862e0
{
    virtual void v0();
    virtual void v4(Owner_9862e0* owner, void* ctx);
    int FUN_00726070();
};
struct CombatCtx
{
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
    int unk2c;
    int unk30;
    int unk34;
    CombatCtx(Owner_9862e0* owner);
    ~CombatCtx();
};
struct Owner_9862e0
{
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
    Target_9862e0* m28;
    bool m2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int m40;
    TimeValue m44;
    void FUN_0098a3c0();
    void FUN_009862e0(Target_9862e0* target);
};
// Stores target in m28; when non-null, creates CombatCtx, calls FUN_0098a3c0 and target->v4, updates m40, m44, and m2c; otherwise clears m2c.
// @fnv 0x009862e0
void Owner_9862e0::FUN_009862e0(Target_9862e0* target)
{
    m28 = target;
    if (m28)
    {
        CombatCtx ctx(this);
        FUN_0098a3c0();
        m28->v4(this, &ctx);
        m40 = m28->FUN_00726070();
        TimeValue t;
        t.FUN_00435de0(FUN_00435dd0());
        m44 = t;
        m2c = true;
    }
    else
    {
        m2c = false;
    }
}

extern const float DAT_01012054;

struct FUN_00906f60
{
    int a;
    int b;
    FUN_00906f60();
};

struct Member08_985d10
{
    int a, b, c, d;
    Member08_985d10();
    ~Member08_985d10();
};

struct Member18_985d10
{
    int a, b, c, d;
    Member18_985d10();
    ~Member18_985d10();
};

struct Member44_985d10
{
    int a;
    Member44_985d10();
};

struct MemberD4_985d10
{
    void* p;
    MemberD4_985d10(void*);
    ~MemberD4_985d10();
};

struct MemberE8_985d10
{
    float f;
    MemberE8_985d10(float);
};

struct MemberF0_985d10
{
    int a, b, c, d;
    MemberF0_985d10();
};

struct Member110_985d10
{
    int a, b, c, d;
    Member110_985d10();
    ~Member110_985d10();
};

struct Member120_985d10
{
    int a, b, c, d;
    Member120_985d10();
    ~Member120_985d10();
};

struct Member138_985d10
{
    int a, b, c, d;
    Member138_985d10();
    ~Member138_985d10();
};

struct FUN_00985d10
{
    int m_00;
    int m_04;
    Member08_985d10 m_08;
    Member18_985d10 m_18;
    int m_28;
    bool m_2c;
    FUN_00906f60 m_30;
    FUN_00906f60 m_38;
    int m_40;
    Member44_985d10 m_44;
    FUN_00906f60 m_48;
    FUN_00906f60 m_50;
    FUN_00906f60 m_58[10];
    FUN_00906f60 m_a8;
    FUN_00906f60 m_b0;
    FUN_00906f60 m_b8;
    float m_c0;
    float m_c4;
    float m_c8;
    float m_cc;
    int m_d0;
    MemberD4_985d10 m_d4;
    FUN_00906f60 m_d8;
    FUN_00906f60 m_e0;
    MemberE8_985d10 m_e8;
    int m_ec;
    MemberF0_985d10 m_f0;
    NiPoint3_helper_combatgroup m_100;
    float m_10c;
    Member110_985d10 m_110;
    Member120_985d10 m_120;
    MemberD4_985d10 m_130;
    bool m_134;
    Member138_985d10 m_138;
    int m_148;
    int m_14c;
    int m_150;
    char m_154;
    MemberD4_985d10 m_158;

    FUN_00985d10(int a1);
};

// Initializes all members of FUN_00985d10, setting m_04 to a1 and several float fields to DAT_01012054.
// @fnv 0x00985d10
FUN_00985d10::FUN_00985d10(int a1)
    : m_00(0), m_04(a1), m_28(0), m_2c(false), m_40(0), m_c0(DAT_01012054), m_c4(DAT_01012054), m_c8(DAT_01012054),
      m_cc(DAT_01012054), m_d0(0), m_d4(0), m_e8(-DAT_0108d540), m_ec(0), m_100(reinterpret_cast<const NiPoint3_helper_combatgroup&>(NiPoint3_ZERO)), m_10c(0.0f), m_130(0),
      m_134(false), m_148(0), m_14c(0), m_150(0), m_154(-1), m_158(0)
{}

struct AvoidNode9894 : AvoidanceVectorData
{
    AvoidNode9894(const NiPoint3& arPos, float afR, float afHeight);
};

struct AvoidArray9894 : PathingAvoidNodeArray
{
    void AddNode(const AvoidanceVectorData& arNode);
};

struct FUN_00989490_shell
{
    float GetBoundsSq(NiPoint3* apCenter);
    PathingAvoidNodeArray* __thiscall FUN_00989490(int a1, int a2, int a3, PathingAvoidNodeArray* apArray);
};

// Adds an avoidance node at the target center with a radius derived from the bounds square to the given pathing avoid node array.
// @fnv 0x00989490
PathingAvoidNodeArray* __thiscall FUN_00989490_shell::FUN_00989490(int aiUnused1, int aiUnused2, int aiUnused3,
                                                                   PathingAvoidNodeArray* apArray)
{
    B006815c0 kTargetCenter;
    float fBoundsSq;
    float fR = 1024.0f;
    fBoundsSq = GetBoundsSq(&kTargetCenter);
    if (fBoundsSq > fR * fR)
        fR = FUN_004579e0(fBoundsSq);
    PathingAvoidNodeArray* pArray = apArray;
    if (!pArray)
        pArray = new PathingAvoidNodeArray;
    static_cast<AvoidArray9894*>(pArray)->AddNode(
        AvoidNode9894(kTargetCenter, fR, FUN_00403e20((float*)&originalRuntimeFloatSetting384) * 4.0));
    return pArray;
}

// @fnv 0x009865d0
void* ActorCombatGroup::FUN_009865d0(int aiRef)
{
    return reinterpret_cast<FUN_00986610_shell*>(this)->FUN_00986610(reinterpret_cast<TESForm*>(aiRef)->FUN_0084e3a0());
}
