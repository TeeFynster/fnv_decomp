#include "../../../../include/SettingT.h"
// fallout/ai/combat/combatstate.cpp: CombatState, Host, Holder and shared BSSimpleArray specializations (141 functions)

#include "../../../../include/ActorCombatGroup.h"
#include "../../../../include/CombatActor.h"
#include "../../../../include/CombatState.h"
#include "../../../../include/BSSimpleArray.h"
#include "../../../../include/SETTING_VALUE.h"
// CombatCoverPointData_combatstate: local type (was include/CombatCoverPointData.h, which had no evidence of one real class); its methods are 0x005dc960 Main::GameOver, 0x0067fdb0 PackageSchedule::SetStartDayOfWeek, 0x009a2ea0 CombatCoverLocation::LoadGameBGS
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;

class CombatCoverPointData_combatstate
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

    void Copy(void*);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    bool IsHideCover();
    bool IsCrouchCover();
    bool IsStandCover();
    bool IsLedgeCover();
    bool IsValidCover();
    unsigned char GetCoverHeight();
    bool IsReserved();
    void SetReserved(bool);
    bool IsDirty();
    void SetDirty(bool);
    void* __vecDelDtor(unsigned int);
};
// Effects_combatstate: local type (was include/Effects.h, which had no evidence of one real class); its methods are 0x00405c00 EffectItemList::GetEffectScore, 0x004065e0 EffectItemList::GetAssociatedSkill
class EffectLink;
class ImageSpaceEffect;
class LightObject;

class Effects_combatstate
{
public:
    union
    {
        char prefix[200];
        struct
        {
            unsigned int unk00;
            unsigned int unk04;
            unsigned int unk08;
            EffectLink* lights;
            char unk10[184];
        };
    };
    ImageSpaceEffect* noise;

    EffectLink* Head() const { return lights; }
    LightObject* Next(EffectLink*& iter) const;
    void DispelAllEffects();
    float FUN_00405c00(int, int, int);
    int count();
};
#include "../../../../include/Actor.h"
#include "../../../../include/ActiveEffect.h"
#include "../../../../include/AlchemyItem.h"
#include "../../../../include/InventoryChanges.h"
#include "../../../../include/CombatController.h"
#include "../../../../include/PathingRequest.h"
#include "../../../../include/PathingRequestCoveredMove.h"
#include "../../../../include/BGSSaveGameBuffer.h"
#include "../../../../include/GameSettingCollection.h"
#include "../../../../include/Setting.h"
#include "../../../../include/AnimIdle.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/CombatTargetTimestamp.h"
#include "../../../../include/EffectSetting.h"
#include "../../../../include/MagicCaster.h"
#include "../../../../include/MobileObject.h"
#include "../../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}

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
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/PathingCoverLocation.h"
#include "../../../../include/PathingLocation.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/SL.h"
#include "../../../../include/TES.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESWorldSpace.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TimeoutTimer.h"
#include "../../../../include/V4.h"
#include <string.h>
#pragma intrinsic(memcpy)

// Unit declarations not supplied by the shared headers.
// CombatState field accesses below retain offsets checked against the game image;
// the shared declaration does not expose those fields yet.
class CombatLocations
{
  public:
    virtual void Clear();
};
class CombatLOS
{
  public:
    bool BaseProcess_HasCachedValues();
    void BaseProcess_GetCachedRadius(CombatLocations*);
};



class GlobalObject_0044f440
{
  public:
    float FUN_00450410();
};
float RandomFloat(float, float);
bool RandomBoolean(float);
extern GlobalObject_0044f440 DAT_011d57d0;
extern GlobalObject_0044f440 DAT_011d5944;
extern GlobalObject_0044f440 DAT_011d5750;
extern GlobalObject_0044f440 DAT_011d5968;
extern GlobalObject_0044f440 DAT_011d5874;
extern GlobalObject_0044f440 DAT_011d58e8;
extern GlobalObject_0044f440 DAT_011d5988;
extern GlobalObject_0044f440 DAT_011d5794;
extern GlobalObject_0044f440 DAT_011d57b8;
extern GlobalObject_0044f440 DAT_011d581c;
extern GlobalObject_0044f440 DAT_011d5894;
extern GlobalObject_0044f440 DAT_011d5930;
extern GlobalObject_0044f440 DAT_011d58d8;
extern GlobalObject_0044f440 DAT_011d5868;
extern GlobalObject_0044f440 DAT_011d5834;
extern GlobalObject_0044f440 DAT_011d58c4;
extern GlobalObject_0044f440 DAT_011d5908;
extern GlobalObject_0044f440 DAT_011d585c;
extern const float DAT_01017870;
extern const float DAT_01017718;
extern const float DAT_010162c0;
extern const float DAT_01016088;
extern const float DAT_01016248;
extern const float DAT_0101e570;
#include "../../../../include/Projectile.h"
// Gets or adds the InventoryChanges for this reference and returns the count of the given object in it, or 0 if none.
// @fnv 0x00575610
int CombatState::GetInventoryItemCount(TESForm* object)
{
    struct
    {
        int result;
        InventoryChanges* inventory;
    } locals;
    locals.result = 0;
    locals.inventory = InventoryChanges::GetOrAddInventoryChanges((TESObjectREFR*)this);
    if (locals.inventory)
        locals.result = locals.inventory->GetObjectCount(object);
    return locals.result;
}
// If los is set and its check passes, calls los->FUN_008be220(this); otherwise calls Clear().
// @fnv 0x008be1b0
void CombatState::ProcessCoverLOSResult()
{
    if (*(CombatLOS**)((char*)this + 0x68) && (*(CombatLOS**)((char*)this + 0x68))->BaseProcess_HasCachedValues())
        (*(CombatLOS**)((char*)this + 0x68))->BaseProcess_GetCachedRadius(this ? (CombatLocations*)((char*)this + 0xa8) : 0);
    else
        ((CombatLocations*)((char*)this + 0xa8))->Clear();
}

// @fnv 0x0064bf90
void CombatState::UpdateCombatStateData(int state, float* pfX, float* pfY, float delta)
{
    (*(float*)((char*)this + 0x17c)) -= delta;
    if ((*(float*)((char*)this + 0x17c)) <= 0.0)
    {
        switch (state)
        {
        case -1:
        case 0:
        case 8:
        case 11:
            if (RandomBoolean(DAT_01017870))
            {
                (*(float*)((char*)this + 0x17c)) = RandomFloat(DAT_010162c0, DAT_01017718);
                (*(float*)((char*)this + 0x180)) = 0.0f;
                (*(float*)((char*)this + 0x184)) = 0.0f;
            }
            else
            {
                (*(float*)((char*)this + 0x17c)) = RandomFloat(DAT_01016248, DAT_01016088);
                (*(float*)((char*)this + 0x184)) = RandomFloat(DAT_011d5944.FUN_00450410(), DAT_011d57d0.FUN_00450410());
                (*(float*)((char*)this + 0x180)) = RandomFloat(DAT_011d5968.FUN_00450410(), DAT_011d5750.FUN_00450410());
            }
            break;
        case 2:
        case 4:
            if (RandomBoolean(DAT_01017870))
            {
                (*(float*)((char*)this + 0x17c)) = RandomFloat(DAT_01017718, DAT_0101e570);
                (*(float*)((char*)this + 0x180)) = 0.0f;
                (*(float*)((char*)this + 0x184)) = 0.0f;
            }
            else
            {
                (*(float*)((char*)this + 0x17c)) = RandomFloat(DAT_01016248, DAT_01016088);
                (*(float*)((char*)this + 0x184)) = RandomFloat(DAT_011d58e8.FUN_00450410(), DAT_011d5874.FUN_00450410());
                (*(float*)((char*)this + 0x180)) = RandomFloat(DAT_011d5794.FUN_00450410(), DAT_011d5988.FUN_00450410());
            }
            break;
        case 3:
        case 9:
        case 12:
            (*(float*)((char*)this + 0x17c)) = RandomFloat(DAT_010162c0, DAT_01017718);
            if (RandomBoolean(DAT_01017870))
            {
                (*(float*)((char*)this + 0x180)) = 0.0f;
                (*(float*)((char*)this + 0x184)) = 0.0f;
            }
            else
            {
                (*(float*)((char*)this + 0x184)) = RandomFloat(DAT_011d581c.FUN_00450410(), DAT_011d57b8.FUN_00450410());
                (*(float*)((char*)this + 0x180)) = RandomFloat(DAT_011d5930.FUN_00450410(), DAT_011d5894.FUN_00450410());
            }
            break;
        case 1:
        case 6:
            (*(float*)((char*)this + 0x17c)) = RandomFloat(DAT_01016248, DAT_01016088);
            (*(float*)((char*)this + 0x184)) = 0.0f;
            if (RandomBoolean(DAT_01016248))
                (*(float*)((char*)this + 0x180)) = 0.0f;
            else
                (*(float*)((char*)this + 0x180)) = RandomFloat(DAT_011d5868.FUN_00450410(), DAT_011d58d8.FUN_00450410());
            break;
        case 5:
            if (RandomBoolean(DAT_01017870))
            {
                (*(float*)((char*)this + 0x17c)) = RandomFloat(DAT_01017718, DAT_0101e570);
                (*(float*)((char*)this + 0x180)) = 0.0f;
                (*(float*)((char*)this + 0x184)) = 0.0f;
            }
            else
            {
                (*(float*)((char*)this + 0x17c)) = RandomFloat(DAT_01016248, DAT_01016088);
                (*(float*)((char*)this + 0x184)) = RandomFloat(DAT_011d58c4.FUN_00450410(), DAT_011d5834.FUN_00450410());
                (*(float*)((char*)this + 0x180)) = RandomFloat(DAT_011d585c.FUN_00450410(), DAT_011d5908.FUN_00450410());
            }
            break;
        }
    }
    *pfX += ((float*)this)[0x60];
    *pfY += ((float*)this)[0x61];
}

typedef char _sizecheck_CombatCoverLocation[sizeof(CombatCoverPointData_combatstate) == 120 ? 1 : -1];

// @fnv 0x005dc960
bool CombatCoverPointData_combatstate::IsReserved()
{
    return reinterpret_cast<bool*>(&unk00)[1];
}
struct CoordinateTriple;
struct CombatAvoidanceSphere
{
    void Copy(void*);
    void SetLocation(int);
    void SetPoint(void*, TESForm*);
    void SetTargetForm(TESForm*);
    void AssignReference(TESObjectREFR*);
    void SetRadius(float);
    void SetFlag(unsigned int, bool);
    void SetWorldLocation(void*);
    void* GetPoint();
    TESObjectREFR* GetRef();
    TESForm* GetReferenceSpace();
    CoordinateTriple* GetWorldForwardVector();
    int GetLocation();
    float GetRadius();
    bool GetFlag(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    void IsWithinSphere();
    char m_cBuffer[16];
    TESObjectREFR* pRef;
    int iLocation;
    float fRadius;
    unsigned int iFlags;
};
typedef char _sizecheck_CombatLocation[sizeof(CombatAvoidanceSphere) == 32 ? 1 : -1];
struct FUN_00819a50_shell : public CombatAvoidanceSphere
{
    void CombatLocation_SetRadius(float);
};

// @fnv 0x00819a50
// src: COMMUNITY 0x00819a50
void FUN_00819a50_shell::CombatLocation_SetRadius(float afRadius)
{
    fRadius = afRadius;
}

struct FUN_00997c10_shell
{
    void __thiscall CoverSearch_Reset();
    void __thiscall CombatState_ClearSecondaryCoverSearch();
};

// @fnv 0x00997c10
// src: COMMUNITY 0x00997c10
void __thiscall FUN_00997c10_shell::CombatState_ClearSecondaryCoverSearch()
{
    ((FUN_00997c10_shell*)((char*)this + 0x128))->CoverSearch_Reset();
}

struct FUN_009989f0_shell
{
    unsigned char __thiscall GetByteAtOffsetC7();
};

// @fnv 0x009989f0
unsigned char __thiscall FUN_009989f0_shell::GetByteAtOffsetC7()
{
    return ((unsigned char*)this)[0xc7];
}

struct FUN_00998a10_shell
{
    unsigned char field_c5;
    unsigned char GetFieldC5();
};

// @fnv 0x00998a10
unsigned char FUN_00998a10_shell::GetFieldC5()
{
    return *(unsigned char*)((char*)this + 0xc5);
}

struct CombatTargetMapLock
{
    void AcquireLock();
};

struct FUN_0099c210_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    CombatTargetMapLock m_lock;
    void LockCombatTargetMap();
};

// @fnv 0x0099c210
void __thiscall FUN_0099c210_shell::LockCombatTargetMap()
{
    m_lock.AcquireLock();
}

struct FUN_009a0680_shell
{
    void __thiscall ClearAndDeletePointer();
};

// Deletes the pointer stored at offset 0x18c and sets that field to null.
// @fnv 0x009a0680
void __thiscall FUN_009a0680_shell::ClearAndDeletePointer()
{
    void* ptr = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x18c);
    operator delete(ptr);
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x18c) = 0;
}

void __cdecl operator delete(void*);

struct FUN_009a0a40_shell
{
    char pad[0xc4];
    void* field_c4;
};

// Deletes the pointer stored at field_c4 and sets it to null.
// @fnv 0x009a0a40
void __fastcall FreeAndClearFieldC4(FUN_009a0a40_shell* thisp)
{
    void* p = thisp->field_c4;
    operator delete(p);
    thisp->field_c4 = 0;
}

struct CoordinateTriple
{
    void BGSWorldLocation_SaveGame(void*);
};

struct FUN_009a2d80_shell
{
    void SaveFieldsAndTimeStamp(void* buffer);
};

// Calls FUN_00527b70 on this and SaveTimeStamp on the object at offset 0x10, passing buffer to both.
// @fnv 0x009a2d80
// src: GUESS 0x009a2d80 (confidence: medium)
void FUN_009a2d80_shell::SaveFieldsAndTimeStamp(void* buffer)
{
    reinterpret_cast<CoordinateTriple*>(this)->BGSWorldLocation_SaveGame(buffer);
    reinterpret_cast<CombatTargetTimestamp*>(reinterpret_cast<char*>(this) + 0x10)->SaveTimeStamp(buffer);
}

struct GlobalObject_00869f00
{
    int* m_ptr;
    void Clear(bool);
};

extern int DAT_0108e068;

// @fnv 0x009a3410
// src: GUESS 0x009a3410 (confidence: low)
void __fastcall CombatState_UpdateState_009a3410(GlobalObject_00869f00* this_)
{
    this_->m_ptr = &DAT_0108e068;
    this_->Clear(true);
}

namespace fnv_009a35f0 {
struct GlobalObject_00869f00
{
    int m_Data;
    void __thiscall Clear(bool);
};

extern int DAT_0108e090;

struct FUN_009a35f0_shell : GlobalObject_00869f00
{
    void UpdateState_009a35f0();
};

// @fnv 0x009a35f0
// src: GUESS 0x009a35f0 (confidence: low)
void FUN_009a35f0_shell::UpdateState_009a35f0()
{
    m_Data = reinterpret_cast<int>(&DAT_0108e090);
    this->Clear(true);
}
}  // namespace fnv_009a35f0

struct FUN_006d3280_s
{
    bool a, b, c, d, e, f;
    FUN_006d3280_s* ClearFlags();
};
// Sets all six boolean flags of this object to false and returns this.
// @fnv 0x006d3280
FUN_006d3280_s* FUN_006d3280_s::ClearFlags()
{
    a = false;
    b = false;
    c = false;
    d = false;
    e = false;
    f = false;
    return this;
}

void _Deallocate(void*);
struct FUN_006d3370_s
{
    void ForwardCall_006d33a0();
    FUN_006d3370_s* FUN_006d3370(unsigned int flags);
};
// Calls FUN_006d33a0, then frees this with _Deallocate if flags has bit 1 set, and returns this.
// @fnv 0x006d3370
FUN_006d3370_s* FUN_006d3370_s::FUN_006d3370(unsigned int flags)
{
    ForwardCall_006d33a0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// The 0x54-byte elements are PathingCoverLocation objects. Retain this element
// view until the shared header exposes its deleting destructor at 0x006dc4d0.
struct Elem
{
    int v[21];
    void FUN_006dc4d0(int);
};

// 0x006a8500 releases pBuffer through virtual slot 2 and then clears it.
void __fastcall ReleaseCombatCoverArrayBuffer(BSSimpleArray<Elem, 1024>*);

// @fnv 0x006dbde0
template <>
void BSSimpleArray<Elem, 1024>::Clear(bool freeStorage)
{
    if (pBuffer)
    {
        ReleaseElements(pBuffer, iSize);
        if (freeStorage)
        {
            ReleaseCombatCoverArrayBuffer(this);
            pBuffer = 0;
            SimpleArrayStorage = 0;
        }
        iSize = 0;
    }
}

// Calls the deleting destructor with flag 0 for each cover location.
// @fnv 0x006dbee0
template <>
void BSSimpleArray<Elem, 1024>::ReleaseElements(Elem* apElements, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++)
        apElements[i].FUN_006dc4d0(0);
}

// @fnv 0x009052c0
template <>
Elem& BSSimpleArray<Elem, 1024>::GetAt(int index)
{
    return *(pBuffer + index);
}

struct IMH
{
    CombatState* CombatController_GetCombatState();
};

// @fnv 0x0097beb0
// src: COMMUNITY 0x0097beb0
void CombatController_FindCombatLocation(IMH* pIMH, int iUnused, int iValue)
{
    CombatState* t = pIMH->CombatController_GetCombatState();
    t->FindCombatLocation_0099ac20(iValue);
}

struct FUN_0097ee60_shell
{
    V4 v;
    void AssignV4(V4* o);
};
// Copies the 16 bytes pointed to by o without invoking V4::operator=.
// @fnv 0x0097ee60
void FUN_0097ee60_shell::AssignV4(V4* apValue)
{
    memcpy(&v, apValue, sizeof(v));
}

extern Setting originalRuntimeFloatSetting413;
struct CombatTimeStampHelper
{
    float GetElapsedTime();
};
struct UnknownClass
{
    char _pad[0x94];
    CombatTimeStampHelper ts;
    bool IsElapsedTimeAtLeastSetting();
};
// Returns true if ts.GetElapsedTime() is greater than or equal to the value from originalRuntimeFloatSetting413.Float().
// @fnv 0x0097eee0
bool UnknownClass::IsElapsedTimeAtLeastSetting()
{
    return (ts.GetElapsedTime() >= *originalRuntimeFloatSetting413.Float() ? 1 : 0);
}

struct FUN_0097ef30_shell
{
    bool CombatGroup_IsSearching();
};
// @fnv 0x0097ef30
// src: XBOX_PDB 0x0097ef30
bool FUN_0097ef30_shell::CombatGroup_IsSearching()
{
    return 0 < *(unsigned int*)((char*)this + 0xd0);
}

namespace fnv_00997400 {
struct CoordinateTriple
{
    int a;
    int b;
    int c;
    int d;
};

struct TESObjectREFR_STUB
{
    CoordinateTriple TESObjectREFR_GetWorldLocation();
};

struct CombatAvoidanceSphere
{
    CoordinateTriple m_cBuffer;
    TESObjectREFR* pRef;
    void CombatLocation_SetTarget(TESObjectREFR* apRef);
};

// @fnv 0x00997400
// src: COMMUNITY 0x00997400
void CombatAvoidanceSphere::CombatLocation_SetTarget(TESObjectREFR* apRef)
{
    pRef = apRef;
    m_cBuffer = reinterpret_cast<TESObjectREFR_STUB*>(pRef)->TESObjectREFR_GetWorldLocation();
}
}  // namespace fnv_00997400

struct WL16_997440
{
    int v0;
    int v4;
    int v8;
    int vC;
};
struct Ref_997440
{
    WL16_997440 TESObjectREFR_GetWorldLocation();
};
struct Outer_997440
{
    WL16_997440 loc;
    Ref_997440* pRef;
    void CopyRefValue();
};
// If pRef is set, copies the value returned by pRef->FUN_00575650() into loc.
// @fnv 0x00997440
void Outer_997440::CopyRefValue()
{
    if (pRef)
        loc = pRef->TESObjectREFR_GetWorldLocation();
}

extern float DAT_0108df70;
struct CH
{
    int v;
    void __thiscall CombatTargetTimestamp(float);
};
struct Unk975C0
{
    char _0[24];
    float f18;
    int i1c;
    BSSimpleArray<Elem, 1024> s20;
    void CoverSearch_Reset();
};
// @fnv 0x009975c0
// src: COMMUNITY 0x009975c0
void Unk975C0::CoverSearch_Reset()
{
    CH data;
    f18 = 0.0f;
    data.CombatTargetTimestamp(-DAT_0108df70);
    i1c = data.v;
    s20.Clear(true);
}

namespace fnv_00997ba0 {
struct FUN_00997c10_shell
{
    void CombatState_ClearSecondaryCoverSearch();
};
struct FUN_009a0680_shell
{
    void ClearAndDeletePointer();
};
struct FUN_00997ba0_shell
{
    void CombatState_ClearCoverLocation(int);
    void CombatState_ClearStandardCoverSearch();
    void ReleaseStageHolder(int);
    void CombatState_ChangeProcessLevel(int, int);
};
// When a is zero and b is non-zero, calls FUN_009a03d0(0), FUN_00997bf0, ReleaseStageHolder(0), FUN_00997c10 and ClearAndDeletePointer.
// @fnv 0x00997ba0
// src: COMMUNITY 0x00997ba0
void FUN_00997ba0_shell::CombatState_ChangeProcessLevel(int aiFirst, int aiSecond)
{
    if (aiFirst == 0 && aiSecond != 0)
    {
        CombatState_ClearCoverLocation(0);
        CombatState_ClearStandardCoverSearch();
        ReleaseStageHolder(0);
        ((FUN_00997c10_shell*)this)->CombatState_ClearSecondaryCoverSearch();
        ((FUN_009a0680_shell*)this)->ClearAndDeletePointer();
    }
}
}  // namespace fnv_00997ba0

namespace fnv_00997bf0 {
struct FUN_00997c10_shell
{
    void CoverSearch_Reset();
};
struct FUN_00997bf0_shell
{
    void CombatState_ClearStandardCoverSearch();
};
// @fnv 0x00997bf0
// src: COMMUNITY 0x00997bf0
void FUN_00997bf0_shell::CombatState_ClearStandardCoverSearch()
{
    ((FUN_00997c10_shell*)((char*)this + 0xec))->CoverSearch_Reset();
}
}  // namespace fnv_00997bf0

struct TESAmmoInitCalls
{
    MobileObject* GetFieldBC();
};

struct FUN_00997cb0_Class
{
    void CombatState_Update();
    void CombatState_UpdateImmediateData();
    void CombatState_UpdatePeriodicData();
    void CombatState_UpdateLow();
};

// @fnv 0x00997cb0
// src: COMMUNITY 0x00997cb0
void FUN_00997cb0_Class::CombatState_Update()
{
    if ((*reinterpret_cast<TESAmmoInitCalls**>(reinterpret_cast<char*>(this) + 0x1c4))
            ->GetFieldBC()
            ->GetCurrentProcessLevel() == 0)
    {
        CombatState_UpdateImmediateData();
        CombatState_UpdatePeriodicData();
    }
    else
    {
        CombatState_UpdateLow();
    }
}

namespace fnv_00998980 {

extern Setting originalRuntimeFloatSetting411;
struct CombatTimeStampHelper
{
    float GetElapsedTime();
};

// Returns whether the elapsed time from _ts is less than the float value of originalRuntimeFloatSetting411.
// @fnv 0x00998980
}  // namespace fnv_00998980

// src: XBOX_PDB 0x00998980
bool CombatState::GetHasBuffered360LineOfSight_00998980()
{
    using namespace fnv_00998980;
    return (double)((fnv_00998980::CombatTimeStampHelper*)((char*)this + 0x98))->GetElapsedTime() < *originalRuntimeFloatSetting411.Float();
}


struct FUN_009989d0_shell
{
    bool HasCombatFlag(int);
    bool TESCombatStyle_GetIgnoreThreats();
};
// @fnv 0x009989d0
// src: XBOX_PDB 0x009989d0
bool FUN_009989d0_shell::TESCombatStyle_GetIgnoreThreats()
{
    return HasCombatFlag(0x10);
}

struct FUN_00998a30_shell
{
    bool CombatController_GetAttackerCanSneak();
};
// @fnv 0x00998a30
// src: XBOX_PDB 0x00998a30
bool FUN_00998a30_shell::CombatController_GetAttackerCanSneak()
{
    return *(bool*)((char*)this + 0xd4);
}

extern double _gModifierZero;
struct FUN_009990c0_s
{
    int a;
    float value;
    bool IsNegative();
};
// Returns true when value is less than _gModifierZero.
// @fnv 0x009990c0
bool FUN_009990c0_s::IsNegative()
{
    return value < _gModifierZero;
}

struct FUN_00999100_shell
{
    bool bhkCharacterListener_ClearFlag(int);
    bool CombatState_ClearTargetUnreachable();
};
// @fnv 0x00999100
// src: XBOX_PDB 0x00999100
bool FUN_00999100_shell::CombatState_ClearTargetUnreachable()
{
    return bhkCharacterListener_ClearFlag(3);
}

struct Modifier
{
    float GetValue();
};
extern double _gModifierZero;
struct Holder
{
    unsigned char _pad[0xB4];
    Modifier mod;
    bool IsModifierZero();
};
// Returns whether the holder's modifier value equals _gModifierZero.
// @fnv 0x00999120
bool Holder::IsModifierZero()
{
    return mod.GetValue() == _gModifierZero;
}

// Returns true when state is neither 3 nor 4.
// @fnv 0x0099a3e0
// src: XBOX_PDB 0x0099a3e0
bool TESWorldSpace::CombatProcedureBeInCover_GetBehindCover()
{
    return *(int*)m_kSourceFiles != 3 && *(int*)m_kSourceFiles != 4;
}

struct RegionPoint
{
    float __thiscall GetX(void);
};

struct CombatTimeStampCtor
{
    void __thiscall CombatTargetTimestamp(float);
};

struct CombatTimeStamp4
{
    float v;
};

extern float DAT_0108df70;

struct FUN_0099a5e0_shell
{
    void __thiscall UpdateCombatTimestamps(int);
};

// Stores a new combat timestamp at this+0x9c and, if the timestamp at this+0xa4 equals -DAT_0108df70, replaces it with a new one.
// @fnv 0x0099a5e0
void FUN_0099a5e0_shell::UpdateCombatTimestamps(int)
{
    CombatTimeStamp4 a;
    CombatTimeStamp4 b;
    reinterpret_cast<CombatTimeStampCtor*>(&a)->CombatTargetTimestamp(Actor::GetActorScale());
    *(CombatTimeStamp4*)((char*)this + 0x9c) = a;
    if (((RegionPoint*)((char*)this + 0xa4))->GetX() == -DAT_0108df70)
    {
        reinterpret_cast<CombatTimeStampCtor*>(&b)->CombatTargetTimestamp(Actor::GetActorScale());
        *(CombatTimeStamp4*)((char*)this + 0xa4) = b;
    }
}

struct FUN_0097f220_t
{
    void CombatTimer_ForceTrigger();
};
struct FUN_0099a650_shell : CombatState
{
    void CombatState_ResetEmbeddedWeaponSwitchTimer(int a, bool b);
};
// If the flag is false, calls FUN_0097f220 on the object at offset 0x214 of this CombatState.
// @fnv 0x0099a650
// src: COMMUNITY 0x0099a650
void FUN_0099a650_shell::CombatState_ResetEmbeddedWeaponSwitchTimer(int aiUnused, bool b)
{
    if (!b)
        ((FUN_0097f220_t*)((char*)this + 0x214))->CombatTimer_ForceTrigger();
}

namespace fnv_0099a6b0 {

struct S9a0c50
{
    void UpdateModifierState(int);
};

struct S9a1280
{
    void CombatState_BoostConfidence(int);
};

struct FUN_0099a6b0_Class
{
    void CombatState_DamagedByAttacker(int, int);
};

// @fnv 0x0099a6b0
// src: XBOX_PDB 0x0099a6b0
void FUN_0099a6b0_Class::CombatState_DamagedByAttacker(int p1, int p2)
{
    if (((CombatTargetTimestamp*)((char*)this + 0xa0))->GetElapsedTime() > 1.0)
    {
        ((S9a0c50*)this)->UpdateModifierState(1);
    }
    CombatTargetTimestamp ts(Actor::GetActorScale());
    *(CombatTargetTimestamp*)((char*)this + 0xa0) = ts;
    if (*(unsigned char*)((char*)this + 0xd8) == 2)
    {
        ((S9a1280*)this)->CombatState_BoostConfidence(1);
    }
}
}  // namespace fnv_0099a6b0

namespace fnv_0099a720 {

extern Setting g_011ce058;

struct FUN_0099a720_cls
{
    void EvaluateWeaponScores();
    void CombatState_Disarmed();
};

// @fnv 0x0099a720
// src: XBOX_PDB 0x0099a720
void FUN_0099a720_cls::CombatState_Disarmed()
{
    if (*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x64) <
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x58))
    {
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x64) =
            *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x58);
        reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x1d4)->Start(*g_011ce058.Float());
    }
    EvaluateWeaponScores();
}
}  // namespace fnv_0099a720

struct StageHolder
{
    bool GetDone();
};
struct FUN_0099a9a0_shell
{
    void UpdateStageHolders();
    void CombatState_ClearCoverLocation(int);
    void ReleaseStageHolder(int);
};
// Checks the StageHolder pointers at offsets 0xE4 and 0xE8 and calls FUN_009a03d0(0) or ReleaseStageHolder(0) for each one that is not done.
// @fnv 0x0099a9a0
void FUN_0099a9a0_shell::UpdateStageHolders()
{
    if (*(StageHolder**)((char*)this + 0xE4) && !(*(StageHolder**)((char*)this + 0xE4))->GetDone())
        this->CombatState_ClearCoverLocation(0);
    if (*(StageHolder**)((char*)this + 0xE8) && !(*(StageHolder**)((char*)this + 0xE8))->GetDone())
        this->ReleaseStageHolder(0);
}

struct CTSHelper
{
    float GetElapsedTime();
};
struct D3
{
    int a, b, c;
};
extern double DAT_010718b8;

struct FUN_0099ab50_Class
{
    bool CombatState_GetLastSeenTargetLocation(D3* dest);
};

// Checks the item pointer at 0x1c4 and elapsed time against DAT_010718b8; if valid, copies the D3 at 0x84 into dest and returns true, else false.
// @fnv 0x0099ab50
// src: XBOX_PDB 0x0099ab50
bool FUN_0099ab50_Class::CombatState_GetLastSeenTargetLocation(D3* dest)
{
    void* p = (*(AlchemyItem**)((char*)this + 0x1c4))->CombatController_GetTarget();
    if (p == 0 || ((CTSHelper*)((char*)this + 0x98))->GetElapsedTime() > DAT_010718b8)
        return false;
    *dest = *(D3*)((char*)this + 0x84);
    return true;
}

namespace fnv_0099abc0 {

float __cdecl CombatUtilities_GetTargetFiringZOffset(Actor*, int, int);
struct FUN_0099abc0_This
{
    bool CombatState_GetLastSeenTargetLocation(NiPoint3&);
    bool UpdateLastSeenFiringLocation(NiPoint3&);
};
// Checks the point via FUN_0099ab50, then adds FUN_009a8460's result for the target actor to the point's z and returns true.
// @fnv 0x0099abc0
bool FUN_0099abc0_This::UpdateLastSeenFiringLocation(NiPoint3& arLastSeenFiringLocation)
{
    Actor* ptarget;
    if (!CombatState_GetLastSeenTargetLocation(arLastSeenFiringLocation))
        return false;
    ptarget = (Actor*)(*(AlchemyItem**)((char*)this + 0x1c4))->CombatController_GetTarget();
    arLastSeenFiringLocation.z += CombatUtilities_GetTargetFiringZOffset(ptarget, 2, 1);
    return true;
}
}  // namespace fnv_0099abc0

struct MagicItem;

struct FUN_0099b520_shell : MagicCaster
{
    void CombatLocation_SetSpace(MagicItem* spell);
};
// @fnv 0x0099b520
// src: COMMUNITY 0x0099b520
void FUN_0099b520_shell::CombatLocation_SetSpace(MagicItem* spell)
{
    SetSelectedMagicItem((int)spell);
}

struct FUN_0099b580_shell
{
    void _ref_0084e3a0();
    void CallReferencedFunction();
};
// @fnv 0x0099b580
void FUN_0099b580_shell::CallReferencedFunction()
{
    _ref_0084e3a0();
}

struct FUN_00989010_t
{
    void SetTripleAndValue(int, int);
};
struct FUN_0099b8b0_shell : FUN_00989010_t
{
    void CombatLocation_SetPoint(int a, int b);
};
// Calls SetTripleAndValue with the two arguments, then writes 0 to the field at offset 0x10 of this object.
// @fnv 0x0099b8b0
// src: XBOX_PDB 0x0099b8b0
void FUN_0099b8b0_shell::CombatLocation_SetPoint(int a, int b)
{
    SetTripleAndValue(a, b);
    *(int*)((char*)this + 0x10) = 0;
}

struct FUN_0099c1f0_shell
{
    bool PathingCoverLocation_GetHeight();
};
// @fnv 0x0099c1f0
// src: XBOX_PDB 0x0099c1f0
bool FUN_0099c1f0_shell::PathingCoverLocation_GetHeight()
{
    return *(bool*)((char*)this + 0x4c);
}

struct ParentSpaceNode
{
    int a;
    int b;
    int c;
};
bool __cdecl CombatState_CheckCoverLOS(void*, ParentSpaceNode*, int);
// @fnv 0x0099cb00
// src: XBOX_PDB 0x0099cb00
bool __cdecl CombatState_CheckTargetsCoverLOS_0099cb00(void* p1, BSSimpleArray<ParentSpaceNode, 1024>* pNodes)
{
    unsigned int i;
    ParentSpaceNode node;
    for (i = 0; i < pNodes->GetSize(); ++i)
    {
        node = pNodes->GetAt(i);
        if (CombatState_CheckCoverLOS(p1, &node, 0))
            return true;
    }
    return false;
}

namespace fnv_009a0260 {
struct CoordinateTriple
{
    int v[4];
    CoordinateTriple* FUN_0043a3c0(int, int, bool, bool);
};
struct FUN_009a0260_s
{
    void CombatState_CheckMovement_009a02a0(CoordinateTriple*);
    void CombatState_CheckMovement(int a, int b, bool c, bool d);
};
// @fnv 0x009a0260
// src: XBOX_PDB 0x009a0260
void FUN_009a0260_s::CombatState_CheckMovement(int a, int b, bool c, bool d)
{
    CoordinateTriple loc;
    CombatState_CheckMovement_009a02a0(loc.FUN_0043a3c0(a, b, c, d));
}
}  // namespace fnv_009a0260

namespace fnv_009a0650 {
struct FUN_009a0680_shell
{
    void ClearAndDeletePointer();
};
struct FUN_009a0650_shell : FUN_009a0680_shell
{
    void SetField18C(int v);
};
// Calls ClearAndDeletePointer, then stores v at offset 0x18c of this object.
// @fnv 0x009a0650
void FUN_009a0650_shell::SetField18C(int aiValue)
{
    ClearAndDeletePointer();
    *(int*)((char*)this + 0x18c) = aiValue;
}
}  // namespace fnv_009a0650

struct Inner097
{
    int data[4];
    void BGSWorldLocation_BGSWorldLocation();
    NiPoint3* FUN_006815c0();
};
struct FUN_009a08d0_Cls
{
    unsigned char b0;
    unsigned char b1;
    int i4;
    Inner097 u8;
    float f18;
    float f1c;
    FUN_009a08d0_Cls* CombatLocationTarget_CombatLocationTarget();
};
// @fnv 0x009a08d0
// src: XBOX_PDB 0x009a08d0
FUN_009a08d0_Cls* FUN_009a08d0_Cls::CombatLocationTarget_CombatLocationTarget()
{
    b0 = 0;
    b1 = 0;
    i4 = 0;
    u8.BGSWorldLocation_BGSWorldLocation();
    f18 = 0.0f;
    f1c = 0.0f;
    return this;
}

struct FUN_009a0b30_self
{
    float GetScaledValue();
};

// Returns 0.9 times the float at offset 0x18 of the pointer stored at offset 0xc4, or 0.0 if that pointer is null.
// @fnv 0x009a0b30
float FUN_009a0b30_self::GetScaledValue()
{
    return (
        float)(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xc4)
                   ? *reinterpret_cast<float*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0xc4) + 0x18) *
                         (double)0.9f
                   : 0.0);
}

namespace fnv_009a0be0 {

struct Obj_1c4
{
    AnimIdle* __thiscall FUN_004f9bf0();
};
using ::SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting424;

struct FUN_009a0be0_Class
{
    float __thiscall GetIdleAdjustedValue();
};

// Returns the float at this+0xc4 offset 0x1c, adding the runtime float setting when the idle's section is not 0xf, 6 or 0.
// @fnv 0x009a0be0
float FUN_009a0be0_Class::GetIdleAdjustedValue()
{
    AnimIdle* idle = ((Obj_1c4*)*(void**)((char*)this + 0x1c4))->FUN_004f9bf0();
    if (idle)
    {
        int section = idle->GetSection();
        if (section != 0xf && section != 6 && section != 0)
        {
            return *(float*)(*(char**)((char*)this + 0xc4) + 0x1c) +
                   reinterpret_cast<Setting*>(&originalRuntimeFloatSetting424)->Float()[0];
        }
    }
    return *(float*)(*(char**)((char*)this + 0xc4) + 0x1c);
}
}  // namespace fnv_009a0be0

namespace fnv_009a0d00 {
struct E006950d0;

struct S5460
{
    unsigned int __thiscall BSSimpleArray_NiPoint2_1024_AddUninitialized(void);
};

struct S006950d0
{
    E006950d0* __thiscall GetElement(unsigned int);
};

struct Entry
{
    void* ptr;
    CombatTargetTimestamp ts;
};

struct FUN_009a0d00_shell
{
    void __thiscall StoreEntry(const void* apCopy);
};

// @fnv 0x009a0d00
void __thiscall FUN_009a0d00_shell::StoreEntry(const void* apCopy)
{
    if (!apCopy)
        return;
    unsigned int count = ((S5460*)((char*)this + 0x164))->BSSimpleArray_NiPoint2_1024_AddUninitialized();
    ((Entry*)((S006950d0*)((char*)this + 0x164))->GetElement(count))->ptr = (void*)apCopy;
    CombatTargetTimestamp ts(Actor::GetActorScale());
    ((Entry*)((S006950d0*)((char*)this + 0x164))->GetElement(count))->ts = ts;
}
}  // namespace fnv_009a0d00

namespace fnv_009a0ec0 {
struct S20;
struct H4
{
    S20* __thiscall GetIndexedValue_006b3160(unsigned int);
};
struct FUN_007881d0_shell
{
    unsigned int __thiscall BSSimpleArray_CombatMember_1024_AddUninitialized(void);
};
struct CombatTimeStamp_ctor
{
    void __thiscall CombatTargetTimestamp(float);
};

struct FUN_009a0ec0_Block
{
    unsigned int v[4];
};
struct FUN_009a0ec0_Ts
{
    unsigned int v;
};
struct FUN_009a0ec0_Node
{
    FUN_009a0ec0_Block block;
    FUN_009a0ec0_Ts ts;
};

struct FUN_009a0ec0_shell
{
    void __thiscall SetNodeBlockAndTimestamp(const FUN_009a0ec0_Block* a1);
};

// @fnv 0x009a0ec0
void __thiscall FUN_009a0ec0_shell::SetNodeBlockAndTimestamp(const FUN_009a0ec0_Block* apBlock)
{
    FUN_009a0ec0_Ts timeStamp;
    unsigned int index = reinterpret_cast<FUN_007881d0_shell*>(reinterpret_cast<char*>(this) + 0x174)->BSSimpleArray_CombatMember_1024_AddUninitialized();
    reinterpret_cast<FUN_009a0ec0_Node*>(
        reinterpret_cast<H4*>(reinterpret_cast<char*>(this) + 0x174)->GetIndexedValue_006b3160(index))
        ->block = *apBlock;
    reinterpret_cast<CombatTimeStamp_ctor*>(&timeStamp)->CombatTargetTimestamp(Actor::GetActorScale());
    reinterpret_cast<FUN_009a0ec0_Node*>(
        reinterpret_cast<H4*>(reinterpret_cast<char*>(this) + 0x174)->GetIndexedValue_006b3160(index))
        ->ts = timeStamp;
}
}  // namespace fnv_009a0ec0

namespace fnv_009a1010 {

struct TESAmmoInitCalls
{
    unsigned int __thiscall GetFieldBC();
};

struct FUN_009a1010_Class
{
    void CombatState_UpdateCombatStrength();
};

// @fnv 0x009a1010
// src: XBOX_PDB 0x009a1010
void FUN_009a1010_Class::CombatState_UpdateCombatStrength()
{
    Actor* ptarget = (Actor*)(*(TESAmmoInitCalls**)((char*)this + 0x1c4))->GetFieldBC();
    *(float*)((char*)this + 0xd4) = ptarget->Actor_GetWeaponDamagePerSecond();
    *(float*)((char*)this + 0xd0) = ptarget->GetCombatRating(*(float*)((char*)this + 0xd4));
}
}  // namespace fnv_009a1010

namespace fnv_009a2bf0 {

struct CoordinateTriple
{
    void BGSWorldLocation_SaveGame(void*);
    void* field00;
    void* field04;
    void* field08;
    void* field0C;
};

struct FUN_009a2bf0_shell : CoordinateTriple
{
    void* field10;
    void* field14;
    void* field18;
    void* field1C;
    void CombatLocation_SaveGameBGS(BGSSaveFormBuffer* a_buffer);
};

// @fnv 0x009a2bf0
// src: COMMUNITY 0x009a2bf0
void FUN_009a2bf0_shell::CombatLocation_SaveGameBGS(BGSSaveFormBuffer* a_buffer)
{
    BGSWorldLocation_SaveGame(a_buffer);
    a_buffer->SaveData((void*)&field14, 4, 0);
    a_buffer->SaveData((void*)&field18, 4, 0);
    a_buffer->SaveData((void*)&field1C, 4, 0);
    a_buffer->SerializeFormData(field10, 0);
}
}  // namespace fnv_009a2bf0

struct FUN_00527ba0_Class
{
    void __thiscall BGSLoadGameBuffer_LoadBGSWorldLocation(void*);
};

struct FUN_009a2c60_Class
{
    void __thiscall LoadFormData(void*);
};

// @fnv 0x009a2c60
void FUN_009a2c60_Class::LoadFormData(void* buffer)
{
    ((FUN_00527ba0_Class*)this)->BGSLoadGameBuffer_LoadBGSWorldLocation(buffer);
    ((BGSLoadFormBuffer*)buffer)->ReadTypedData((void*)((char*)this + 0x14), 4);
    ((BGSLoadFormBuffer*)buffer)->ReadTypedData((void*)((char*)this + 0x18), 4);
    ((BGSLoadFormBuffer*)buffer)->ReadTypedData((void*)((char*)this + 0x1c), 4);
    ((BGSLoadFormBuffer*)buffer)->ReadFormIdentifier((void*)((char*)this + 0x10));
}

namespace fnv_009a2d20 {

struct FUN_009a2d20_s
{
    int a;
    CombatTargetTimestamp ts;
    void SaveFields_009a2d20(BGSSaveFormBuffer* buf);
};
// @fnv 0x009a2d20
// src: GUESS 0x009a2d20 (confidence: medium)
void FUN_009a2d20_s::SaveFields_009a2d20(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SaveData(this, 4, 0);
    ts.SaveTimeStamp(apBuffer);
}
}  // namespace fnv_009a2d20

class BGSLoadGameBuffer;
namespace fnv_009a2d50 {

struct FUN_009a2d50_s
{
    int a;
    CombatTargetTimestamp ts;
    void LoadValueAndTimestamp(BGSLoadFormBuffer* buf);
};
// Reads 4 bytes of this object from buf, then loads the ts member from the same buffer.
// @fnv 0x009a2d50
// src: GUESS 0x009a2d50 (confidence: medium)
void FUN_009a2d50_s::LoadValueAndTimestamp(BGSLoadFormBuffer* buf)
{
    buf->ReadTypedData(this, 4);
    ts.LoadGame((::BGSLoadGameBuffer*)buf);
}
}  // namespace fnv_009a2d50

class BGSLoadGameBuffer;
namespace fnv_009a2db0 {

struct FUN_00527ba0_t
{
    void BGSLoadGameBuffer_LoadBGSWorldLocation(BGSLoadGameBuffer*);
};
struct FUN_009a2db0_shell : FUN_00527ba0_t
{
    void LoadWorldLocationAndTimestamp(BGSLoadGameBuffer* buf);
};
// @fnv 0x009a2db0
// src: GUESS 0x009a2db0 (confidence: high)
void FUN_009a2db0_shell::LoadWorldLocationAndTimestamp(BGSLoadGameBuffer* buf)
{
    BGSLoadGameBuffer_LoadBGSWorldLocation(buf);
    ((CombatTargetTimestamp*)((char*)this + 0x10))->LoadGame((::BGSLoadGameBuffer*)buf);
}
}  // namespace fnv_009a2db0

namespace fnv_009a3130 {

struct CoordinateTriple
{
    void BGSWorldLocation_SaveGame(void*);
};
struct CombatSaveData
{
    unsigned char unk0;
    unsigned char unk1;
    void* pRef;
    unsigned char unk08[16];
    int unk18;
    int unk1C;
    void SaveState_009a3130(BGSSaveFormBuffer*);
};
// @fnv 0x009a3130
// src: GUESS 0x009a3130 (confidence: medium)
void CombatSaveData::SaveState_009a3130(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData((void*)&unk0, 1, 0);
    apSaveGameBuffer->SaveData((void*)&unk1, 1, 0);
    apSaveGameBuffer->SaveData((void*)&unk18, 4, 0);
    apSaveGameBuffer->SaveData((void*)&unk1C, 4, 0);
    apSaveGameBuffer->SerializeFormData(pRef, 0);
    ((CoordinateTriple*)((char*)this + 8))->BGSWorldLocation_SaveGame(apSaveGameBuffer);
}
}  // namespace fnv_009a3130

namespace fnv_009a31b0 {

struct Sub08
{
    void BGSLoadGameBuffer_LoadBGSWorldLocation(BGSLoadFormBuffer*);
};
struct Holder
{
    void CombatState_LocationTarget_LoadGame(BGSLoadFormBuffer*);
};
// Reads bytes at offsets 0, 1, 0x18 and 0x1C, a value at offset 4, and delegates offset 8 to FUN_00527ba0, all via the load buffer.
// @fnv 0x009a31b0
// src: COMMUNITY 0x009a31b0
void Holder::CombatState_LocationTarget_LoadGame(BGSLoadFormBuffer* pBuffer)
{
    pBuffer->ReadTypedData(this, 1);
    pBuffer->ReadTypedData((void*)((char*)this + 1), 1);
    pBuffer->ReadTypedData((void*)((char*)this + 0x18), 4);
    pBuffer->ReadTypedData((void*)((char*)this + 0x1C), 4);
    pBuffer->ReadFormIdentifier((void*)((char*)this + 4));
    ((Sub08*)((char*)this + 8))->BGSLoadGameBuffer_LoadBGSWorldLocation(pBuffer);
}
}  // namespace fnv_009a31b0

// @fnv 0x009a3280
template <>
Elem& BSSimpleArray<Elem, 1024>::GetElement(unsigned int index)
{
    return GetAt((int)index);
}

struct Elem54
{
    char data[0x54];
};
struct RetObj
{
    void FUN_006e4430();
};
struct Helper
{
    void FUN_009a32a0(unsigned int, int);
    RetObj* FUN_009052c0(unsigned int, void*);
};
struct Host
{
    int unk0;
    Elem54* arr;
    unsigned int cnt;
    void ProcessElements(Helper*);
};
// Calls FUN_009a32a0 with cnt and 1, then for each of cnt elements calls FUN_009052c0(i, &arr[i]) and FUN_006e4430 on the result.
// @fnv 0x009a3780
void Host::ProcessElements(Helper* apHelper)
{
    apHelper->FUN_009a32a0(cnt, 1);
    for (unsigned int i = 0; i < cnt; ++i)
    {
        apHelper->FUN_009052c0(i, &arr[i])->FUN_006e4430();
    }
}

struct FUN_009cc490_shell
{
    void CombatState_SetLocationUnreachable(unsigned int flags);
};
// @fnv 0x009cc490
// src: XBOX_PDB 0x009cc490
void FUN_009cc490_shell::CombatState_SetLocationUnreachable(unsigned int flags)
{
    *(unsigned int*)((char*)this + 4) |= flags;
}

struct CCL
{
    int v;
};
struct FUN_009d6730_shell : CombatState
{
    CCL* CombatState_GetMaybeFleeTimer0A0(CCL* out);
};
// @fnv 0x009d6730
// src: COMMUNITY 0x009d6730
CCL* FUN_009d6730_shell::CombatState_GetMaybeFleeTimer0A0(CCL* out)
{
    *out = *(CCL*)((char*)this + 0xa0);
    return out;
}

struct FUN_009d6c80_shell
{
    void CombatState_UnreserveCoverLocation(CombatCoverPointData_combatstate*);
    void CombatState_UnreserveSecondaryCoverLocation();
};
// @fnv 0x009d6c80
// src: COMMUNITY 0x009d6c80
void FUN_009d6c80_shell::CombatState_UnreserveSecondaryCoverLocation()
{
    CombatState_UnreserveCoverLocation(*(CombatCoverPointData_combatstate**)((char*)this + 0xe8));
}

struct FUN_009d7c20_shell : CombatState
{
    void CombatState_ReserveCoverLocation(CombatCoverPointData_combatstate*);
    void CombatState_ReserveSecondaryCoverLocation();
};
// @fnv 0x009d7c20
// src: XBOX_PDB 0x009d7c20
void FUN_009d7c20_shell::CombatState_ReserveSecondaryCoverLocation()
{
    CombatState_ReserveCoverLocation(*(CombatCoverPointData_combatstate**)((char*)this + 0xe8));
}

struct RefX
{
    bool TESForm_GetDisabledOrDeleted();
};
struct FUN_00981340_shell
{
    void FreeSlot(int);
};
struct FUN_0097cfc0_shell
{
    void* GetActionAtIndex(int);
};
struct FUN_0099a530_shell
{
    void CombatState_CheckReferences();
};
// @fnv 0x0099a530
// src: XBOX_PDB 0x0099a530
void FUN_0099a530_shell::CombatState_CheckReferences()
{
    void* a = *(void**)((char*)this + 0x19c);
    void* b = *(void**)((char*)this + 0x1a0);
    for (unsigned int i = 0; i < 5; ++i)
    {
        void* pSlotObj = ((FUN_0097cfc0_shell*)this)->GetActionAtIndex(i);
        if (pSlotObj && *(void**)pSlotObj && ((RefX*)*(void**)pSlotObj)->TESForm_GetDisabledOrDeleted())
            ((FUN_00981340_shell*)this)->FreeSlot(i);
    }
    if (a != ((FUN_0097cfc0_shell*)this)->GetActionAtIndex(3) || b != ((FUN_0097cfc0_shell*)this)->GetActionAtIndex(4))
    {
        ((FUN_00981340_shell*)this)->FreeSlot(3);
        ((FUN_00981340_shell*)this)->FreeSlot(4);
    }
}

namespace fnv_009a2f50 {

// Exe 0x009a2f50: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct CombatstateOffset08View
{
    unsigned int GetFlags();
};

struct FUN_009a3280_shell
{
    void* FUN_009a3280(int);
};
struct FUN_009a2f50_shell
{
    void CombatCoverSearch_SaveGameBGS(BGSSaveFormBuffer* buffer);
};
// @fnv 0x009a2f50
// src: COMMUNITY 0x009a2f50
void FUN_009a2f50_shell::CombatCoverSearch_SaveGameBGS(BGSSaveFormBuffer* buffer)
{
    buffer->SaveData(this, 12, 0);
    buffer->SaveData((char*)this + 12, 12, 0);
    buffer->SaveData((char*)this + 24, 4, 0);
    buffer->SaveData((char*)this + 56, 1, 0);
    buffer->SaveData((char*)this + 48, 4, 0);
    buffer->SaveData((char*)this + 52, 4, 0);
    ((CombatTargetTimestamp*)((char*)this + 28))->SaveTimeStamp(buffer);
    unsigned int flags = ((char*)this + 32) ? ((CombatstateOffset08View*)((char*)this + 32))->GetFlags() : 0;
    buffer->SaveVariableSizedValue(flags);
    for (unsigned int i = 0; i < flags; ++i)
    {
        void* cover = ((FUN_009a3280_shell*)((char*)this + 32))->FUN_009a3280(i);
        ((void(__thiscall*)(void*, BGSSaveFormBuffer*))(*((int**)cover))[0])(cover, buffer);
    }
}
}  // namespace fnv_009a2f50

namespace fnv_009a3050 {

struct Helper
{
    void FUN_009a32a0(unsigned int, int);
};
struct FUN_009a3280_shell
{
    PathingCoverLocation* FUN_009a3280(int);
};
struct CombatSaveGameData
{
    void CombatCoverSearch_LoadGameBGS(BGSLoadFormBuffer* buffer);
};
// Reads this object's fields from the buffer, then loads a count and each of that many PathingCoverLocation entries via LoadGame.
// @fnv 0x009a3050
// src: COMMUNITY 0x009a3050
void CombatSaveGameData::CombatCoverSearch_LoadGameBGS(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(this, 0xc);
    buffer->ReadTypedData((char*)this + 0xc, 0xc);
    buffer->ReadTypedData((char*)this + 0x18, 4);
    buffer->ReadTypedData((char*)this + 0x38, 1);
    buffer->ReadTypedData((char*)this + 0x30, 4);
    buffer->ReadTypedData((char*)this + 0x34, 4);
    ((CombatTargetTimestamp*)((char*)this + 0x1c))->LoadGame(buffer);
    unsigned int count = buffer->ReadElementCount();
    ((Helper*)((char*)this + 0x20))->FUN_009a32a0(count, 1);
    unsigned int i = 0;
    for (; i < count; ++i)
    {
        PathingCoverLocation* cover = ((FUN_009a3280_shell*)((char*)this + 0x20))->FUN_009a3280(i);
        cover->LoadGame(buffer);
    }
}
}  // namespace fnv_009a3050

struct FUN_0097ee20_shell
{
    char _pad[0x10];
    int f10;
    int f14;
    float f18;
    int f1c;
    void BGSWorldLocation_BGSWorldLocation();
    FUN_0097ee20_shell* CombatLocation_CombatLocation();
};

// Calls FUN_0097ede0, then sets f10 to 0, f14 to -1, f18 to 0.0f and f1c to 0, returning this.
// @fnv 0x0097ee20
// src: XBOX_PDB 0x0097ee20
FUN_0097ee20_shell* FUN_0097ee20_shell::CombatLocation_CombatLocation()
{
    BGSWorldLocation_BGSWorldLocation();
    f10 = 0;
    f14 = -1;
    f18 = 0.0f;
    f1c = 0;
    return this;
}

struct Container
{
    bool CombatState_CheckShouldUpdateDetection(int, TESWorldSpace*);
};

// @fnv 0x0099a360
// src: XBOX_PDB 0x0099a360
bool Container::CombatState_CheckShouldUpdateDetection(int, TESWorldSpace* param2)
{
    if (param2 != *(TESWorldSpace**)((char*)this + 0x1c0))
        return true;
    bool bResult = true;
    if (*(int*)((char*)this + 0x6c) > 0)
    {
        TESWorldSpace* SoundAssetTmp = ((TES*)(*(TES**)((char*)this + 0x1c4)))->GetHitSound();
        if (SoundAssetTmp)
        {
            if (((int (__thiscall*)(TESWorldSpace*))(*(void***)SoundAssetTmp)[13])(SoundAssetTmp) == 7)
            {
                TESWorldSpace* pHitSoundCopy = SoundAssetTmp;
                if (pHitSoundCopy->CombatProcedureBeInCover_GetBehindCover())
                    bResult = false;
            }
        }
    }
    return bResult;
}

namespace fnv_0099a680 {

struct FUN_0099a680_s
{
    char pad[0x9c];
    CombatTargetTimestamp stamp;
    void SetStampFromActor(int);
};
// @fnv 0x0099a680
void FUN_0099a680_s::SetStampFromActor(int)
{
    CombatTargetTimestamp t(Actor::GetActorScale());
    stamp = t;
}
}  // namespace fnv_0099a680

struct S81
{
    void FinishedPackageTask();
};
struct C99
{
    char _pad[0x1C4];
    S81* f1C4;
    int* GetActionAtIndex(int);
    void CombatState_ClearReferencePointer(int, int);
    void CombatState_PreActivateReference(int);
};
// Looks up entry 2, calls f1C4->FUN_00981380() if its value equals a, then calls FUN_0099a420(a, 1).
// @fnv 0x0099a780
// src: XBOX_PDB 0x0099a780
void C99::CombatState_PreActivateReference(int a)
{
    int* b = GetActionAtIndex(2);
    if (b && *b == a)
        f1C4->FinishedPackageTask();
    CombatState_ClearReferencePointer(a, 1);
}

namespace fnv_0099a7d0 {
bool __fastcall IsFleeing_00981990(void*);
void* __fastcall _FNV_GetObjectReference(void*);
int __fastcall _FNV_GetFormType(void*);
int __fastcall _ref_0084e3a0(void*);
struct CTSHelper
{
    void CombatTargetTimestamp(float);
};

// @fnv 0x0099a7d0
}  // namespace fnv_0099a7d0

// src: XBOX_PDB 0x0099a7d0
void CombatState::ActivatedReference(TESObjectREFR* apRef, TESBoundObject* apObject, int aiCount, bool abActivatedScriptOnly)
{
    using namespace fnv_0099a7d0;
    if (IsFleeing_00981990((*(void**)((char*)this + 0x1c4))))
    {
        if (_FNV_GetFormType(_FNV_GetObjectReference(apRef)) == 0x1c)
        {
            (*(unsigned int*)((char*)this + 0xdc)) = _ref_0084e3a0(apRef);
            unsigned int ts;
            ((fnv_0099a7d0::CTSHelper*)&ts)->CombatTargetTimestamp(Actor::GetActorScale());
            (*(unsigned int*)((char*)this + 0xe0)) = ts;
        }
    }
}


struct FUN_0099b540_s
{
    char pad[0x1c];
    unsigned int flags;
    void SetFlags(unsigned int mask, bool set);
};
// Sets or clears the bits of flags selected by mask, according to set.
// @fnv 0x0099b540
void FUN_0099b540_s::SetFlags(unsigned int mask, bool set)
{
    if (set)
        flags |= mask;
    else
        flags &= ~mask;
}

struct FUN_009a0600_shell
{
    unsigned char _pad[0xE4];
    CombatCoverPointData_combatstate* m_pCurrentCoverPoint;
    CombatCoverPointData_combatstate* m_pAlternateCoverPoint;
    bool CombatState_IsCoverLocationValid(CombatCoverPointData_combatstate* apCoverLocation);
};
// @fnv 0x009a0600
// src: XBOX_PDB 0x009a0600
bool FUN_009a0600_shell::CombatState_IsCoverLocationValid(CombatCoverPointData_combatstate* apCoverLocation)
{
    if (!apCoverLocation)
        return false;
    return apCoverLocation == m_pCurrentCoverPoint || apCoverLocation == m_pAlternateCoverPoint;
}

namespace fnv_009a0a80 {
struct Host
{
    unsigned char pad0[0xC4];
    unsigned char* field_C4;
    unsigned char pad1[0x1C4 - 0xC4 - 4];
    AlchemyItem* field_1C4;
    bool GetHasBufferedDetection_0097ee90();
    bool CombatState_CheckUseLocationTargetMaxDistance();
};
// @fnv 0x009a0a80
// src: XBOX_PDB 0x009a0a80
bool Host::CombatState_CheckUseLocationTargetMaxDistance()
{
    void* tmp = ((AlchemyItem*)field_1C4)->CombatController_GetTarget();
    if (tmp != 0)
    {
        if (GetHasBufferedDetection_0097ee90() || field_1C4->FUN_00981420())
            return true;
    }
    if (tmp == 0 && field_C4 != 0 && *field_C4 == 2)
        return true;
    return false;
}
}  // namespace fnv_009a0a80

struct Target
{
    float f[8];
};
struct FUN_009a0b00_s
{
    char pad[0xc4];
    Target* t;
    bool CombatState_CheckUseLocationTargetMaxDistance();
    float GetScaledValue();
    float CombatState_GetLocationTargetDistance();
};
// Returns t->f[7] when FUN_009a0a80() succeeds, otherwise returns the result of GetScaledValue().
// @fnv 0x009a0b00
// src: COMMUNITY 0x009a0b00
float FUN_009a0b00_s::CombatState_GetLocationTargetDistance()
{
    if (CombatState_CheckUseLocationTargetMaxDistance())
        return t->f[7];
    return GetScaledValue();
}

namespace fnv_009a0b70 {

extern Setting originalRuntimeFloatSetting424;
extern double const DAT_0101de30;

struct InnerData
{
    char pad0;
    unsigned char flag;
    char pad[0x16];
    float val18;
    float val1c;
};

struct FUN_009a0b70_shell
{
    char pad_c4[0xc4];
    InnerData* ptr;
    float GetInterpolatedValue();
};

// Returns ptr->val1c plus the runtime float setting when ptr->flag is set, otherwise interpolates between ptr->val18 and ptr->val1c using DAT_0101de30.
// @fnv 0x009a0b70
float FUN_009a0b70_shell::GetInterpolatedValue()
{
    if (ptr->flag)
        return ptr->val1c + *originalRuntimeFloatSetting424.Float();
    return (ptr->val1c - ptr->val18) * DAT_0101de30 + ptr->val18;
}
}  // namespace fnv_009a0b70

extern int DAT_0108e068;
struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
};
struct FUN_009a33e0_shell : AX
{
    FUN_009a33e0_shell* BSSimpleArray_TESObjectWEAP_1024_BSSimpleArray_TESObjectWEAP_1024();
};
// Sets the object's vtable pointer to DAT_0108e068, calls FUN_006b3eb0(0, 0), and returns this.
// @fnv 0x009a33e0
// src: XBOX_PDB 0x009a33e0
FUN_009a33e0_shell* FUN_009a33e0_shell::BSSimpleArray_TESObjectWEAP_1024_BSSimpleArray_TESObjectWEAP_1024()
{
    *(int**)this = &DAT_0108e068;
    BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

extern int DAT_0108e07c;
struct FUN_009a39f0_t
{
    void UpdateState_009a39f0(unsigned int, unsigned int);
};
struct FUN_009a3430_shell : FUN_009a39f0_t
{
    FUN_009a3430_shell* BSSimpleArray_UnreachableCoverLocation_1024_BSSimpleArray_UnreachableCoverLocation_1024();
};
// Sets the object's vtable pointer to DAT_0108e07c, calls FUN_009a39f0(0, 0), and returns this.
// @fnv 0x009a3430
// src: COMMUNITY 0x009a3430
FUN_009a3430_shell* FUN_009a3430_shell::BSSimpleArray_UnreachableCoverLocation_1024_BSSimpleArray_UnreachableCoverLocation_1024()
{
    *(int**)this = &DAT_0108e07c;
    UpdateState_009a39f0(0, 0);
    return this;
}

namespace fnv_009a3460 {
extern int DAT_0108e07c;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_009a3460_shell : GlobalObject_00869f00
{
    void ResetVirtualTableAndClear_009a3460();
};
// @fnv 0x009a3460
// src: GUESS 0x009a3460 (confidence: medium)
void FUN_009a3460_shell::ResetVirtualTableAndClear_009a3460()
{
    *(int**)this = &DAT_0108e07c;
    Clear(true);
}
}  // namespace fnv_009a3460

extern int DAT_0108e090;
struct FUN_009a3bc0_t
{
    void Initialize(unsigned int, unsigned int);
};
struct FUN_009a35c0_shell : FUN_009a3bc0_t
{
    FUN_009a35c0_shell* BSSimpleArray_UnreachableLocation_1024_BSSimpleArray_UnreachableLocation_1024();
};
// Sets the object's vtable pointer to DAT_0108e090, calls Initialize with 0, 0, and returns this.
// @fnv 0x009a35c0
// src: COMMUNITY 0x009a35c0
FUN_009a35c0_shell* FUN_009a35c0_shell::BSSimpleArray_UnreachableLocation_1024_BSSimpleArray_UnreachableLocation_1024()
{
    *(int**)this = &DAT_0108e090;
    Initialize(0, 0);
    return this;
}

namespace fnv_00997480 {
struct S12
{
    int a, b, c;
};
struct S6
{
    short a, b, c;
};

struct RetObj
{
    void FUN_006e4430(const RetObj*);
};

struct FUN_00997480_shell
{
    void CombatCoverLocation_Copy(const FUN_00997480_shell* apCopy);
};

// @fnv 0x00997480
// src: COMMUNITY 0x00997480
void FUN_00997480_shell::CombatCoverLocation_Copy(const FUN_00997480_shell* apCopy)
{
    *(bool*)((char*)this + 0) = *(bool*)((char*)apCopy + 0);
    *(bool*)((char*)this + 1) = *(bool*)((char*)apCopy + 1);
    *(unsigned char*)((char*)this + 2) = *(unsigned char*)((char*)apCopy + 2);
    *(int*)((char*)this + 4) = *(int*)((char*)apCopy + 4);
    *(S12*)((char*)this + 8) = *(S12*)((char*)apCopy + 8);
    ((RetObj*)((char*)this + 0x14))->FUN_006e4430((RetObj*)((char*)apCopy + 0x14));
    *(unsigned int*)((char*)this + 0x68) = *(unsigned int*)((char*)apCopy + 0x68);
    *(unsigned int*)((char*)this + 0x6c) = *(unsigned int*)((char*)apCopy + 0x6c);
    *(S6*)((char*)this + 0x70) = *(S6*)((char*)apCopy + 0x70);
}
}  // namespace fnv_00997480

namespace fnv_00997520 {
struct S12
{
    int a, b, c;
};
struct S4
{
    int a;
};
struct Helper;
struct Host
{
    void ProcessElements(Helper*);
};
struct Unk975C0
{
    void CoverSearch_Reset();
};
struct FUN_00997520_shell : Unk975C0
{
    void CoverSearch_Set(const void* apParam);
};

// @fnv 0x00997520
// src: COMMUNITY 0x00997520
void FUN_00997520_shell::CoverSearch_Set(const void* apParam)
{
    if (!apParam)
    {
        CoverSearch_Reset();
        return;
    }
    *(S12*)((char*)this + 0) = *(S12*)((char*)apParam + 0);
    *(S12*)((char*)this + 0xc) = *(S12*)((char*)apParam + 0xc);
    *(float*)((char*)this + 0x18) = *(float*)((char*)apParam + 0x18);
    *(S4*)((char*)this + 0x1c) = *(S4*)((char*)apParam + 0x1c);
    ((Host*)((char*)apParam + 0x20))->ProcessElements((Helper*)((char*)this + 0x20));
    *(int*)((char*)this + 0x30) = *(int*)((char*)apParam + 0x30);
    *(int*)((char*)this + 0x34) = *(int*)((char*)apParam + 0x34);
    *(char*)((char*)this + 0x38) = *(char*)((char*)apParam + 0x38);
}
}  // namespace fnv_00997520

namespace fnv_00997aa0 {
struct FUN_00981340_shell
{
    void FreeSlot(int);
};

struct FUN_009a0680_shell : FUN_00981340_shell
{
    void ClearAndDeletePointer();
};

struct FUN_0099a9a0_shell : FUN_009a0680_shell
{
    void CombatState_ClearCoverLocation(int);
    void ReleaseStageHolder(int);
};

struct FUN_009a0a40_shell : FUN_0099a9a0_shell
{
};

void __fastcall FreeAndClearFieldC4(FUN_009a0a40_shell*);

struct PrimaryBase : FUN_009a0a40_shell
{
    int pad[9];
    void CombatState_DeleteInventoryData();
};

struct GlobalObject_00869f00;
void __fastcall CombatState_UpdateState_009a3410(GlobalObject_00869f00*);

struct Base_009a3410
{
    int pad;
    ~Base_009a3410()
    {
        CombatState_UpdateState_009a3410((GlobalObject_00869f00*)this);
    }
};

struct FUN_006e4d00_shell
{
    int pad;
    void CallMemberFunction();
    ~FUN_006e4d00_shell()
    {
        CallMemberFunction();
    }
};

struct FUN_009a3460_shell
{
    int pad;
    void ResetVirtualTableAndClear_009a3460();
    ~FUN_009a3460_shell()
    {
        ResetVirtualTableAndClear_009a3460();
    }
};

struct FUN_009a35f0_class
{
    int pad;
    void UpdateState_009a35f0();
    ~FUN_009a35f0_class()
    {
        UpdateState_009a35f0();
    }
};

struct Ptr2_006e9e20
{
    int pad;
    ~Ptr2_006e9e20();
};

struct FUN_00997aa0 : PrimaryBase, Base_009a3410
{
    char pad_28[0xec - 0x28];
    FUN_006e4d00_shell m_ec;
    char pad_f0[0x128 - 0xf0];
    FUN_006e4d00_shell m_128;
    char pad_12c[0x164 - 0x12c];
    FUN_009a3460_shell m_164;
    char pad_168[0x174 - 0x168];
    FUN_009a35f0_class m_174;
    char pad_178[0x224 - 0x178];
    Ptr2_006e9e20 m_224;

    ~FUN_00997aa0();
};

// @fnv 0x00997aa0
FUN_00997aa0::~FUN_00997aa0()
{
    CombatState_DeleteInventoryData();
    CombatState_ClearCoverLocation(0);
    ReleaseStageHolder(0);
    ClearAndDeletePointer();
    FreeAndClearFieldC4(this);
    for (unsigned int i = 0; i < 5; ++i)
    {
        FreeSlot(i);
    }
}
}  // namespace fnv_00997aa0

namespace fnv_00997c30 {
struct TESAmmoInitCalls
{
    void* GetFieldBC();
};

bool __cdecl CombatController_CheckHasEquip(void*, int);

struct FUN_00997cb0_Class
{
    void CombatState_Update();
};

struct SubObj
{
    virtual void vf0();
    virtual void vf1();
    virtual bool vf2(bool);
};

struct FUN_00997c30_shell : FUN_00997cb0_Class
{
    void EvaluateWeaponScores();
    void InitAmmoState();
};

// @fnv 0x00997c30
void FUN_00997c30_shell::InitAmmoState()
{
    void* local4 = (void*)((TESAmmoInitCalls*)*(void**)((char*)this + 0x1c4))->GetFieldBC();
    *(char*)((char*)this + 0x75) = CombatController_CheckHasEquip(local4, 0);
    EvaluateWeaponScores();
    CombatState_Update();
    *(char*)((char*)this + 0xc8) = ((SubObj*)((char*)local4 + 0xa4))->vf2(true);
    *(char*)((char*)this + 0xc9) = *(char*)((char*)this + 0xc8);
    *(char*)((char*)this + 0x1c8) = 0;
}
}  // namespace fnv_00997c30

namespace fnv_00999160 {

struct TESAmmoInitCalls
{
    unsigned int GetFieldBC();
};

struct MyClass
{
    void UpdateTargetPerception(int, int, int*, CombatTargetTimestamp*, bool*, bool*);
};

extern Setting g_011cf198;
extern Setting originalRuntimeFloatSetting492;

struct FUN_00999160_struct
{
    char pad_00[0x1c4];
    EffectSetting* field_1C4;

    void EvaluateWeaponScores();
    void CombatState_UpdateCombatStrength();
    void UpdateRangeValue();

    void CombatState_UpdateLow();
};

// Reads count and target from field_1C4, calls UpdateTargetPerception with this's offsets when target is set, then runs timer-gated updates at 0x204 and 0x20c.
// @fnv 0x00999160
// src: XBOX_PDB 0x00999160
void FUN_00999160_struct::CombatState_UpdateLow()
{
    unsigned int count = ((TESAmmoInitCalls*)field_1C4)->GetFieldBC();
    int target = (int)((AlchemyItem*)field_1C4)->CombatController_GetTarget();
    if (target)
    {
        ((MyClass*)field_1C4->GetCastSound())->UpdateTargetPerception(count, target, (int*)((char*)this + 0x6c),
                                                          (CombatTargetTimestamp*)((char*)this + 0x94),
                                                          (bool*)((char*)this + 0x70), (bool*)((char*)this + 0x71));
    }
    if (*(bool*)((char*)this + 0x77))
    {
        EvaluateWeaponScores();
    }
    if (((TimeoutTimer*)((char*)this + 0x204))->CheckTimer())
    {
        CombatState_UpdateCombatStrength();
        ((TimeoutTimer*)((char*)this + 0x204))->Start(*g_011cf198.Float());
    }
    if (((TimeoutTimer*)((char*)this + 0x20c))->CheckTimer())
    {
        UpdateRangeValue();
        ((TimeoutTimer*)((char*)this + 0x20c))->Start(*originalRuntimeFloatSetting492.Float());
    }
}
}  // namespace fnv_00999160

struct WEAPStub;




struct FUN_0099a2d0_shell
{
    WEAPStub* GetBestWeapon();
};

// Scores weapon types 0-6 via FUN_0097ac90 and returns the weapon from FUN_0097c150 with the highest score, or null for type 6.
// @fnv 0x0099a2d0
WEAPStub* FUN_0099a2d0_shell::GetBestWeapon()
{
    float bestScoreA = 0.0f;
    WEAPStub* kBestWeapon = 0;
    for (unsigned int i = 0; i < 7; ++i)
    {
        float fScore2;
        int weaponType = i;
        fScore2 = ((CombatState*)this)->FUN_0097ac90(weaponType);
        if (fScore2 > bestScoreA)
        {
            bestScoreA = fScore2;
            kBestWeapon = (weaponType != 6) ? (kBestWeapon = ((CombatState*)this)->FUN_0097c150(weaponType)) : 0;
        }
    }
    return kBestWeapon;
}

namespace fnv_0099a840 {

extern Setting originalRuntimeFloatSetting425;
extern Setting originalRuntimeFloatSetting426;

struct FUN_0099a840_shell
{
    void CombatState_UsedCombatItem(void* apItem);
};

// @fnv 0x0099a840
// src: XBOX_PDB 0x0099a840
void FUN_0099a840_shell::CombatState_UsedCombatItem(void* apItem)
{
    for (unsigned int i = 0; i < 2; ++i)
    {
        if (*(void**)((char*)this + 0x1a4 + i * 4) == apItem)
        {
            float val = 0.0f;
            switch (i + 17)
            {
            case 17:
                val = *originalRuntimeFloatSetting425.Float();
            case 18:
                val = *originalRuntimeFloatSetting426.Float();
                break;
            }
            ((TimeoutTimer*)((char*)this + 0x1ac + i * 8))->Start(val);
            break;
        }
    }
}
}  // namespace fnv_0099a840

namespace fnv_0099a8d0 {

struct LocS
{
    void* GetLocation();
};

struct FUN_005407b0_Class
{
    char pad0[0x14];
    LocS loc;
    void UpdateState_005407b0(char);
};

struct Field18C
{
    char pad0[0x14];
    int state;
};

struct FUN_0099a8d0_struct;
bool __fastcall CombatState_GetHasTarget360LineOfSight(FUN_0099a8d0_struct*);

struct FUN_009a0680_shell
{
    void ClearAndDeletePointer();
};

struct FUN_00999100_shell : FUN_009a0680_shell
{
    bool CombatState_ClearTargetUnreachable();
};

struct FUN_0099a8d0_struct : FUN_00999100_shell
{
    char pad0[0xe4];
    FUN_005407b0_Class* field_E4;
    char padE8[0x18c - 0xe8];
    Field18C* field_18C;
    char pad190[0x1c4 - 0x190];
    AlchemyItem* field_1C4;

    bool CombatState_CheckCoverSafe(void*, void*, NiPoint3*, void*, int);
    void EvaluateWeaponScores();

    void CombatState_TargetChanged();
};

// @fnv 0x0099a8d0
// src: XBOX_PDB 0x0099a8d0
void FUN_0099a8d0_struct::CombatState_TargetChanged()
{
    void* ptr4 = ((AlchemyItem*)field_1C4)->CombatController_GetTarget();
    if (field_E4 && ptr4)
    {
        unsigned int local_14[3];
        bool bSafe = CombatState_CheckCoverSafe(&field_E4->loc, field_E4->loc.GetLocation(), (NiPoint3*)&local_14, ptr4, 0);
        if (!bSafe || !CombatState_GetHasTarget360LineOfSight(this))
        {
            field_E4->UpdateState_005407b0(1);
        }
    }
    if (field_18C)
    {
        if (field_18C->state == 0 || field_18C->state == 1)
        {
            ClearAndDeletePointer();
        }
    }
    CombatState_ClearTargetUnreachable();
    EvaluateWeaponScores();
}
}  // namespace fnv_0099a8d0

extern int DAT_0106cbc0;

struct StandInShell
{
    StandInShell* FUN_006dcc40(void*);
};

struct FUN_0099aa80_struct : StandInShell
{
    void* vtable;
    char pad4[0x28 - 4];
    NiPoint3 pt28;
    NiPoint3 pt34;
    NiPoint3 pt40;
    char b4c;
    char b4d;
    char b4e;
    char b4f;
    char b50;
    char b51;
    char b52;

    FUN_0099aa80_struct* PathingCoverLocation_PathingCoverLocation(FUN_0099aa80_struct* other);
};

// @fnv 0x0099aa80
// src: EXE 0x0099aa80
FUN_0099aa80_struct* FUN_0099aa80_struct::PathingCoverLocation_PathingCoverLocation(FUN_0099aa80_struct* other)
{
    FUN_006dcc40(other);
    vtable = &DAT_0106cbc0;
    memcpy(&pt28, &other->pt28, sizeof(pt28));
    memcpy(&pt34, &other->pt34, sizeof(pt34));
    memcpy(&pt40, &other->pt40, sizeof(pt40));
    b4c = other->b4c;
    b4d = other->b4d;
    b4e = other->b4e;
    b4f = other->b4f;
    b50 = other->b50;
    b51 = other->b51;
    b52 = other->b52;
    return this;
}

struct Member
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual NiPoint3* GetPos();
};

namespace fnv_0099ca00 {
extern const float DAT_01017718;

bool __cdecl CombatState_CheckCoverLOS(void*, NiPoint3*, int);

struct FUN_0099ca00_struct
{
    char pad0[0x1c4];
    EffectSetting* field_1C4;

    bool CombatState_CheckTargetsCoverLOS(void* arg1, Member* ignore);
};

// @fnv 0x0099ca00
// src: XBOX_PDB 0x0099ca00
bool FUN_0099ca00_struct::CombatState_CheckTargetsCoverLOS(void* arg1, Member* pIgnoreMember)
{
    ActorCombatGroup* group = (ActorCombatGroup*)field_1C4->GetCastSound();
    unsigned int count = group->GetVirtualNodeCount();
    for (unsigned int i = 0; i < count; ++i)
    {
        Member* member = group->CombatGroup_GetTarget((int)i);
        if (member == pIgnoreMember)
        {
            continue;
        }
        Inner097 loc;
        loc.BGSWorldLocation_BGSWorldLocation();
        NiPoint3 pos;
        if (group->TryGetQuadForState(i, &loc, DAT_01017718))
        {
            pos = *loc.FUN_006815c0();
        }
        else
        {
            pos = *member->GetPos();
        }
        if (CombatState_CheckCoverLOS(arg1, &pos, 0))
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_0099ca00

namespace fnv_0099cb70 {
extern const float DAT_01017718;

struct Arr_006cee30
{
    void BSSimpleArray_ParentSpaceNode_1024_SetReservedSize(int);
    void AddItem(NiPoint3*);
};

struct FUN_0099cb70_struct
{
    char pad0[0x1c4];
    EffectSetting* field_1C4;

    void CollectCastSoundPositions(Arr_006cee30* array);
};

// @fnv 0x0099cb70
void FUN_0099cb70_struct::CollectCastSoundPositions(Arr_006cee30* array)
{
    ActorCombatGroup* group = (ActorCombatGroup*)field_1C4->GetCastSound();
    unsigned int count = group->GetVirtualNodeCount();
    array->BSSimpleArray_ParentSpaceNode_1024_SetReservedSize(count);
    for (unsigned int i = 0; i < count; ++i)
    {
        Member* member = group->CombatGroup_GetTarget((int)i);
        Inner097 loc;
        loc.BGSWorldLocation_BGSWorldLocation();
        NiPoint3 pos;
        if (group->TryGetQuadForState(i, &loc, DAT_01017718))
        {
            pos = *loc.FUN_006815c0();
        }
        else
        {
            pos = *member->GetPos();
        }
        array->AddItem(&pos);
    }
}
}  // namespace fnv_0099cb70

namespace fnv_009a02a0 {
struct CoordinateTriple
{
    double BGSWorldLocation_GetDistanceSquared(CoordinateTriple*);
};

struct LocationTarget
{
    unsigned char type;
    char pad[7];
    CoordinateTriple location;
};

struct ABD_005f92d0
{
    bool GetFlag(unsigned int) const;
};

struct FUN_009a02a0_struct : ABD_005f92d0
{
    char pad0[0xc4];
    LocationTarget* pAssociatedObject;

    float GetIdleAdjustedValue();
    bool HasItemWithinRadius(const CoordinateTriple& loc, float f);

    bool CombatState_CheckMovement_009a02a0(const CoordinateTriple& arWorldLocation, bool abCheckLocationReachable,
                      bool abIgnoreCombatAreaCheck);
};

// @fnv 0x009a02a0
// src: XBOX_PDB 0x009a02a0
bool FUN_009a02a0_struct::CombatState_CheckMovement_009a02a0(const CoordinateTriple& arWorldLocation, bool abCheckLocationReachable,
                                       bool abIgnoreCombatAreaCheck)
{
    if (pAssociatedObject)
    {
        if ((pAssociatedObject->type == 1 && !GetFlag(0x100)) || pAssociatedObject->type == 2 ||
            (pAssociatedObject->type == 3 && !abIgnoreCombatAreaCheck))
        {
            float fmaxDistance = GetIdleAdjustedValue();
            if (((CoordinateTriple&)arWorldLocation).BGSWorldLocation_GetDistanceSquared(&pAssociatedObject->location) >
                fmaxDistance * fmaxDistance)
            {
                return false;
            }
        }
    }
    if (abCheckLocationReachable && HasItemWithinRadius(arWorldLocation, -1.0f))
    {
        return false;
    }
    return true;
}
}  // namespace fnv_009a02a0

namespace fnv_009a0470 {
struct StageHolder
{
    bool GetDone();
};

struct FUN_009d6c80_shell
{
    void CombatState_UnreserveCoverLocation(CombatCoverPointData_combatstate*);
};

struct FUN_006d3370_s
{
    ~FUN_006d3370_s();
};

struct FUN_009a0470_shell : FUN_009d6c80_shell
{
    void StoreEntry(int);
    void ReleaseStageHolder(bool);
};

// @fnv 0x009a0470
void FUN_009a0470_shell::ReleaseStageHolder(bool bParam)
{
    if (*(void**)((char*)this + 0xe8))
    {
        if (bParam)
        {
            StoreEntry(*(int*)(*(char**)((char*)this + 0xe8) + 0x68));
        }
        if (((StageHolder*)*(void**)((char*)this + 0xe8))->GetDone())
        {
            CombatState_UnreserveCoverLocation((CombatCoverPointData_combatstate*)*(void**)((char*)this + 0xe8));
        }
        delete (FUN_006d3370_s*)*(void**)((char*)this + 0xe8);
        *(void**)((char*)this + 0xe8) = 0;
    }
}
}  // namespace fnv_009a0470

namespace fnv_009a06c0 {
void* __cdecl operator new(unsigned int);

struct TESObjectREFRHelper
{
    void SetTargetingState(bool);
};

struct FUN_00981340_shell
{
    void FreeSlot(int);
};

struct FUN_009a06c0_struct : FUN_00981340_shell
{
    char pad0[0x190];
    SL* array_190[1];

    void SetArrayEntry(int arg1, TESObjectREFRHelper* arg2, int arg3);
};

// @fnv 0x009a06c0
void FUN_009a06c0_struct::SetArrayEntry(int aiIndex, TESObjectREFRHelper* apRefr, int aiValue)
{
    FreeSlot(aiIndex);
    if (apRefr)
    {
        array_190[aiIndex] = new SL();
        array_190[aiIndex]->a = (int)apRefr;
        array_190[aiIndex]->b = aiValue;
        if (apRefr)
        {
            apRefr->SetTargetingState(true);
        }
    }
}
}  // namespace fnv_009a06c0

namespace fnv_009a0c50 {
extern double _gModifierZero;

extern Setting originalRuntimeFloatSetting429;

struct CameraShotHelper
{
    float GetField4C();
};

struct FieldC4
{
    unsigned char byte0;
};

struct Ref_997440
{
    int TESObjectREFR_GetWorldLocation(void*, int, float, float);
};

struct Local18
{
    int data[4];
};

struct FUN_009a0c50_class
{
    char pad0[0xc4];
    FieldC4* field_C4;
    char padC8[0x1c4 - 0xc8];
    CombatController* field_1C4;

    void CombatState_SetLocationTargetLocation(int);
    void UpdateModifierState(bool arg_8);
};

// If field_C4 is null or its byte0 is 3 and arg_8 is set, computes a modifier value and applies it via FUN_009a0910 when it exceeds _gModifierZero.
// @fnv 0x009a0c50
void FUN_009a0c50_class::UpdateModifierState(bool arg_8)
{
    if (field_C4)
    {
        if (field_C4->byte0 != 3 || !arg_8)
        {
            return;
        }
    }
    float f = ((CameraShotHelper*)field_1C4->GetCurrentCombatStyle())->GetField4C();
    if (f > _gModifierZero)
    {
        Ref_997440* pRef = (Ref_997440*)field_1C4->GetFieldBC();
        {
            Local18 localData;
            CombatState_SetLocationTargetLocation(pRef->TESObjectREFR_GetWorldLocation(&localData, 3, f * *originalRuntimeFloatSetting429.Float(), f));
        }
    }
}
}  // namespace fnv_009a0c50

namespace fnv_009a0d70 {
struct CTSHelper
{
    float GetElapsedTime();
};

// Exe 0x009a0d70: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct CombatstateOffset08View
{
    unsigned int GetFlags();
};

struct FUN_00844160_shell
{
    unsigned int BSSimpleArray_GroupMemberData_1024_GetAt(unsigned int);
};

struct ActorAvoidanceDataArray
{
    void FUN_00983720(unsigned int, unsigned int);
};

struct FUN_009a0d70_shell
{
    bool ContainsItem(void* apItem);
};

// Scans the array at offset 0x164, removing entries whose elapsed time exceeds 10.0, and returns true if any remaining entry's pointer equals apItem.
// @fnv 0x009a0d70
bool FUN_009a0d70_shell::ContainsItem(void* apItem)
{
    for (unsigned int i = 0; i < ((CombatstateOffset08View*)((char*)this + 0x164))->GetFlags(); ++i)
    {
        void* entry = (void*)((FUN_00844160_shell*)((char*)this + 0x164))->BSSimpleArray_GroupMemberData_1024_GetAt(i);
        if (((CTSHelper*)((char*)entry + 4))->GetElapsedTime() > 10.0)
        {
            ((ActorAvoidanceDataArray*)((char*)this + 0x164))->FUN_00983720(i, 1);
            --i;
            continue;
        }
        if (*(void**)entry == apItem)
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_009a0d70

namespace fnv_009a0e10 {
struct CTSHelper
{
    float GetElapsedTime();
};

// Exe 0x009a0e10: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct CombatstateOffset08View
{
    unsigned int GetFlags();
};

struct FUN_00844160_entry
{
    void* item;
    CTSHelper timer;
};

struct FUN_00844160_shell : CombatstateOffset08View
{
    FUN_00844160_entry* BSSimpleArray_GroupMemberData_1024_GetAt(unsigned int);
};

struct ActorAvoidanceDataArray : FUN_00844160_shell
{
    void FUN_00983720(unsigned int, unsigned int);
};

struct FUN_009a0e10_shell
{
    char pad[0x164];
    ActorAvoidanceDataArray avoidanceData;

    void CollectAvoidanceItems(BSSimpleArray<void*, 1024>* apArray);
};

// Removes avoidance entries whose timer exceeds 10 seconds and adds the remaining entries' items to the array.
// @fnv 0x009a0e10
void FUN_009a0e10_shell::CollectAvoidanceItems(BSSimpleArray<void*, 1024>* apArray)
{
    apArray->GrowCapacity(avoidanceData.GetFlags());
    for (unsigned int i = 0; i < avoidanceData.GetFlags(); ++i)
    {
        FUN_00844160_entry* entry = avoidanceData.BSSimpleArray_GroupMemberData_1024_GetAt(i);
        if (entry->timer.GetElapsedTime() > 10.0)
        {
            avoidanceData.FUN_00983720(i, 1);
            --i;
            continue;
        }
        apArray->Add(entry->item);
    }
}
}  // namespace fnv_009a0e10

namespace fnv_009a0f40 {
extern const float runtimeFloatSettingDefault1296;

struct CoordinateTriple
{
    double BGSWorldLocation_GetDistanceSquared(const CoordinateTriple*);
};

struct CTSHelper
{
    float GetElapsedTime();
};

struct Item : CoordinateTriple
{
    char pad[0x10];
    CTSHelper time;
};

// Exe 0x009a0f40: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct CombatstateOffset08View
{
    unsigned int GetFlags();
};

struct MyArr : CombatstateOffset08View
{
    Item* BSSimpleArray_CombatMember_1024_GetAt(unsigned int) const;
    void RemoveEntries(unsigned int, int);
};

struct FUN_009a0f40_struct
{
    char pad0[0x174];
    MyArr array_174;

    bool HasItemWithinRadius(const CoordinateTriple* arWorldLocation, float afRadius);
};

// @fnv 0x009a0f40
bool FUN_009a0f40_struct::HasItemWithinRadius(const CoordinateTriple* arWorldLocation, float afRadius)
{
    float maxDistSq = 0.0f;
    if (afRadius == -1.0)
    {
        maxDistSq = runtimeFloatSettingDefault1296;
    }
    else
    {
        maxDistSq = afRadius * afRadius;
    }

    for (unsigned int i = 0; i < array_174.GetFlags(); ++i)
    {
        Item* item = array_174.BSSimpleArray_CombatMember_1024_GetAt(i);
        if (item->time.GetElapsedTime() > 10.0)
        {
            array_174.RemoveEntries(i, 1);
            --i;
            continue;
        }
        if (item->BGSWorldLocation_GetDistanceSquared(arWorldLocation) < maxDistSq)
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_009a0f40

struct Member14
{
    virtual void SaveGame(BGSSaveFormBuffer*);
};

struct FUN_00982c20
{
    void Save(BGSSaveFormBuffer*);
};

struct FUN_009a2de0_struct
{
    char byte0;
    char byte1;
    char byte2;
    char pad3;
    int dword4;
    char data8[12];
    Member14 member14;
    char pad18[0x68 - 0x14 - sizeof(Member14)];
    int dword68;
    int dword6c;
    FUN_00982c20 member70;

    void CombatCoverLocation_SaveGameBGS(BGSSaveFormBuffer* buffer);
};

// Serializes byte1, byte0, byte2, dword4, data8, member14, dword68, dword6c and member70 into the save buffer.
// @fnv 0x009a2de0
// src: COMMUNITY 0x009a2de0
void FUN_009a2de0_struct::CombatCoverLocation_SaveGameBGS(BGSSaveFormBuffer* buffer)
{
    buffer->SaveData((void*)&byte1, 1, 0);
    buffer->SaveData((void*)&byte0, 1, 0);
    buffer->SaveData((void*)&byte2, 1, 0);
    buffer->SaveData((void*)&dword4, 4, 0);
    buffer->SaveData(data8, 12, 0);
    member14.SaveGame(buffer);
    buffer->SaveData((void*)&dword68, 4, 0);
    buffer->SaveData((void*)&dword6c, 4, 0);
    member70.Save(buffer);
}

namespace fnv_009a2ea0 {

struct Member14
{
    virtual void unk0();
    virtual void LoadGame(BGSLoadFormBuffer*);
};

struct Member70
{
    void CoverReservationInfo_LoadGameBGS(BGSLoadFormBuffer*);
};

struct FUN_009a2ea0_struct
{
    char byte0;
    char byte1;
    char byte2;
    char pad3;
    int dword4;
    char data8[12];
    Member14 member14;
    char pad18[0x68 - 0x14 - sizeof(Member14)];
    int dword68;
    int dword6c;
    Member70 member70;

    void CombatCoverLocation_LoadGameBGS(BGSLoadFormBuffer* buffer);
};

// Reads byte1, byte0, byte2, dword4, data8, dword68 and dword6c from the buffer and calls member14.LoadGame and member70.FUN_00982ca0.
// @fnv 0x009a2ea0
// src: COMMUNITY 0x009a2ea0
void FUN_009a2ea0_struct::CombatCoverLocation_LoadGameBGS(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData((void*)&byte1, 1);
    buffer->ReadTypedData((void*)&byte0, 1);
    buffer->ReadTypedData((void*)&byte2, 1);
    buffer->ReadTypedData((void*)&dword4, 4);
    buffer->ReadTypedData(data8, 12);
    member14.LoadGame(buffer);
    buffer->ReadTypedData((void*)&dword68, 4);
    buffer->ReadTypedData((void*)&dword6c, 4);
    member70.CoverReservationInfo_LoadGameBGS(buffer);
}
}  // namespace fnv_009a2ea0

namespace fnv_009a3610 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};
struct UCL_009a3610
{
    unsigned int m_uiData;
    char pad[0x10];
};
typedef BSSimpleArray<fnv_009a3610::UCL_009a3610, 1024> FUN_009a3610_arr;

// @fnv 0x009a3610
}
template <> void BSSimpleArray<fnv_009a3610::UCL_009a3610, 1024>::SetSize(unsigned int aiNewSize, bool abFreeMemory)
{
    using namespace fnv_009a3610;
    if (aiNewSize == 0)
    {
        ((fnv_009a3610::GlobalObject_00869f00*)this)->Clear(abFreeMemory);
    }
    else if (aiNewSize > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = _Allocate(aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
        else
        {
            ReallocateStorage(aiNewSize, iSize);
            SimpleArrayStorage = aiNewSize;
        }
        InitializeItems(&pBuffer[iSize], aiNewSize - iSize);
        iSize = aiNewSize;
    }
    else if (aiNewSize < iSize)
    {
        ((FUN_0072ba80_shell*)this)->FUN_0072ba80(&pBuffer[aiNewSize], iSize - aiNewSize);
        iSize = aiNewSize;
        if (abFreeMemory && aiNewSize <= SimpleArrayStorage >> 2)
        {
            ReallocateStorage(aiNewSize, aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
    }
    else
    {
        InitializeItems(&pBuffer[iSize], aiNewSize - iSize);
        iSize = aiNewSize;
    }
}
namespace fnv_009a3610 {
}  // namespace fnv_009a3610

struct TESObjectWEAP;

bool __fastcall TESObjectWEAP_IsMeleeWeapon(TESObjectWEAP*);
int __fastcall GetCurrentWeapon(int);

struct ActH2
{
    void* GetActiveWeapon();
};

struct S981990
{
    bool CombatController_CombatPlanContainsAction(int);
};

// @fnv 0x009a9630
// src: XBOX_PDB 0x009a9630
bool CombatUtilities_IsActorUsingMelee(void* apActor)
{
    TESObjectWEAP* weapon = 0;
    void* pcombatController = (*(void*(__thiscall**)(void*))(*(char**)apActor + 0x428))(apActor);
    if (pcombatController)
    {
        weapon = (TESObjectWEAP*)GetCurrentWeapon((int)pcombatController);
    }
    else
    {
        weapon = (TESObjectWEAP*)((ActH2*)apActor)->GetActiveWeapon();
    }

    if (!weapon || TESObjectWEAP_IsMeleeWeapon(weapon))
    {
        return true;
    }

    if (pcombatController &&
        (((S981990*)pcombatController)->CombatController_CombatPlanContainsAction(7) || ((S981990*)pcombatController)->CombatController_CombatPlanContainsAction(8)))
    {
        return true;
    }

    return false;
}

namespace fnv_009a0910 {
struct FUN_009a0a40_shell;
struct FUN_009a08d0_Cls;

struct FUN_009a0910_Vector
{
    float x;
    float y;
    float z;
    float w;
};

void __fastcall FreeAndClearFieldC4(FUN_009a0a40_shell*);
float __cdecl _FUN_00404010(float, float);

unsigned int _data_011c16bc;

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting423;

struct FUN_009a08d0_Cls
{
    unsigned char flag;
    int field4;
    FUN_009a0910_Vector value;
    float value18;
    float value1c;

    FUN_009a08d0_Cls();
};

struct FUN_009a0910_shell
{
    unsigned char padding[0xc4];
    FUN_009a08d0_Cls* fieldC4;

    void CombatState_SetLocationTargetLocation(FUN_009a0910_Vector* value, unsigned char flag, float value10, float value14);
};

// Calls FreeAndClearFieldC4, allocates a FUN_009a08d0_Cls into fieldC4 and stores the flag, vector, and two clamped float values.
// @fnv 0x009a0910
// src: XBOX_PDB 0x009a0910
void FUN_009a0910_shell::CombatState_SetLocationTargetLocation(FUN_009a0910_Vector* apVector, unsigned char flag, float value10, float value14)
{
    FreeAndClearFieldC4(reinterpret_cast<FUN_009a0a40_shell*>(this));

    fieldC4 = new FUN_009a08d0_Cls;

    fieldC4->flag = flag;
    fieldC4->field4 = 0;
    fieldC4->value = *apVector;

    fieldC4->value18 = _FUN_00404010(value10, *originalRuntimeFloatSetting423.Float());
    fieldC4->value1c = _FUN_00404010(value14, *originalRuntimeFloatSetting423.Float());
}
}  // namespace fnv_009a0910

namespace fnv_009a3480 {
struct CombatTargetEntry
{
    Actor* actor;
    unsigned int field_4;
};

}  // namespace fnv_009a3480

// @fnv 0x009a3480
template <>
void BSSimpleArray<fnv_009a3480::CombatTargetEntry, 1024>::SetSize(unsigned int count, bool clear)
{
    if (count == 0)
    {
        Clear(clear);
    }
    else if (count > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = _Allocate(count);
            SimpleArrayStorage = count;
        }
        else
        {
            ReallocateStorage(count, iSize);
            SimpleArrayStorage = count;
        }

        InitializeItems(pBuffer + iSize, count - iSize);
        iSize = count;
    }
    else if (count < iSize)
    {
        ReleaseElements(pBuffer + count, iSize - count);
        iSize = count;

        if (clear && count <= (SimpleArrayStorage >> 2))
        {
            ReallocateStorage(count, count);
            SimpleArrayStorage = count;
        }
    }
    else
    {
        InitializeItems(pBuffer + iSize, count - iSize);
        iSize = count;
    }
}


extern Setting originalRuntimeFloatSetting357;
bool RandomBoolean(float);
extern const float fCombatTimerReset999260a;
extern const float fCombatTimerReset999260b;
extern double _gModifierZero;

struct FUN_00999260_shell
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
    unsigned int iFlags;
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
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    CombatController* pController;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    CombatController::CombatTimer timer1e4;
    CombatController::CombatTimer timer1ec;
    void UpdateCombatFlags();
};

// Refreshes the two combat timers when expired and sets iFlags bits from the runtime float setting and the controller's value source.
// @fnv 0x00999260
void FUN_00999260_shell::UpdateCombatFlags()
{
    int iActor = (int)pController->GetFieldBC();
    if (timer1e4.FUN_008d7f80())
    {
        iFlags &= 0xffff00ff;
        if (RandomBoolean(*originalRuntimeFloatSetting357.Float()))
        {
            iFlags |= 0x100;
        }
        timer1e4.FUN_008d7f40(fCombatTimerReset999260a);
    }
    if (timer1ec.FUN_008d7f80())
    {
        iFlags &= 0xffffff00;
        float fValue = ((ActiveEffect*)pController->GetCurrentCombatStyle())->GetFloatAtOffset1C();
        if (RandomBoolean(fValue / 100.0))
        {
            iFlags |= 1;
        }
        if (fValue > _gModifierZero)
        {
            iFlags |= 2;
        }
        timer1ec.FUN_008d7f40(fCombatTimerReset999260b);
    }
}

// Menu event hook: on event 15 forward the argument to the active list, and refresh when the
// tracked item's id matches the event id.

class AA10List
{
  public:
    void HandleEvent(int iArg);
};

class AA10Source
{
  public:
    AA10List* GetList();
};

class AA10Item
{
  public:
    unsigned int GetID();
};

class AA10Menu
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
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    AA10Item* m_pkTrackedItem;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    AA10Source* m_pkSource;

    void Refresh();
    void HandleMenuEvent(int iArg, unsigned int uiEvent);
};

// Handles event 15 by forwarding iArg to the source list, and refreshes when the tracked item's ID equals uiEvent.
// @fnv 0x0099aa10
void AA10Menu::HandleMenuEvent(int iArg, unsigned int uiEvent)
{
    switch (uiEvent)
    {
    case 15:
        m_pkSource->GetList()->HandleEvent(iArg);
        break;
    }

    if (m_pkTrackedItem)
    {
        unsigned int uiItemID = m_pkTrackedItem->GetID();
        if (uiItemID == uiEvent)
            Refresh();
    }
}

struct Seg99
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
    NiPoint3 start;
    NiPoint3 end;
};

struct Timer99
{
    bool CombatController_GetAttackerCanSneak();
    float FUN_00453700();
    float GetFieldCC();
};

float BSMIN(float, float);
float GetScaleOrHeightDelta(TESObjectREFR*, int);
bool NavMeshMath_LineToLineSegment2DIntersection(NiPoint3*, NiPoint3*, NiPoint3*, NiPoint3*, NiPoint3*);

struct Combat99
{
    char unk000;
    char unk001;
    char unk002;
    char unk003;
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
    int unk0d4;
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
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    Timer99* pTimer;
    bool CombatState_CheckLedgeCoverAngle(Seg99* apSeg, NiPoint3* apFrom, NiPoint3* apTarget, TESObjectREFR* apRef);
};

// @fnv 0x0099cec0
// src: XBOX_PDB 0x0099cec0
bool Combat99::CombatState_CheckLedgeCoverAngle(Seg99* apSeg, NiPoint3* apFrom, NiPoint3* apTarget, TESObjectREFR* apRef)
{
    float fTop3 = BSMIN(apSeg->start.z, apSeg->end.z);
    if (apTarget->z >= fTop3)
    {
        return false;
    }
    else
    {
        NiPoint3 kTarget4 = *apTarget;
        kTarget4.z += GetScaleOrHeightDelta(apRef, 1);
        if (kTarget4.z >= fTop3)
        {
            return false;
        }
        else
        {
            NiPoint3 kHit3;
            bool bHitB = NavMeshMath_LineToLineSegment2DIntersection(&apSeg->start, &apSeg->end, &kTarget4, apFrom, &kHit3);
            if (!bHitB)
                return false;
            float m_fGlyphExtent = kHit3.z - kTarget4.z;
            NiPoint3 kDiff9 = kHit3 - kTarget4;
            float fDist6 = kDiff9.Length();
            NiPoint3 kDiffVal = kHit3 - *apFrom;
            float fLen2 = kDiffVal.Length();
            float fScaledTmp = m_fGlyphExtent * fLen2 / fDist6;
            float fLimit3 = pTimer->CombatController_GetAttackerCanSneak() ? pTimer->FUN_00453700() : pTimer->GetFieldCC();
            if (fLimit3 > fScaledTmp)
                return false;
        }
    }
    return true;
}

namespace fnv_0099e190 {
struct PosHolder;

struct MyTimer
{
    float t;
    MyTimer(float v);
    MyTimer(const MyTimer& o);
    float Get();
};

struct Picker
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
    Picker(void* p);
    Picker();
    ~Picker();
    NiPoint3 GetPoint();
};

struct MyMover
{
    void CombatLocation_SetPoint(NiPoint3* p, int a);
};

struct MyActor
{
    virtual void v0();
    float FUN_008be1b0();
    void TESObjectREFR_GetWorldLocation(PosHolder* out);
};

struct MyRef
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
    virtual void v64();
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
    virtual NiPoint3* GetPos();
};

struct MyProc
{
    MyActor* GetFieldBC();
    MyRef* CombatController_GetTarget();
};

struct PosHolder
{
    float unk00, unk04, unk08;
    int unk0C;
    NiPoint3* Self();
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0(int a, int b);
};

struct Result
{
    float EvaluateThreats();
};

struct Mgr
{
    Result* FUN_00825c00(NiPoint3 v, MyActor* a, float f1, float f2, MyTimer t, float f3);
};

extern Mgr* DAT_011f1958;
extern NiPoint3 DAT_011a9484;
float CombatTimer_GetTimer();
bool FUN_006d7490(Picker* a, NiPoint3* b, Picker* c, int d);
bool CombatUtilities_CalculateLOS(MyActor* a, MyRef* r, NiPoint3* v, NiPoint3* w, int x, int y);
int RandomUnsignedInt(int n);

struct FUN_0099e190_cls
{
    char unk000[0x184];
    MyTimer timer;
    signed char last;
    char pad189[0x1c4 - 0x189];
    MyProc* proc;
    bool CombatState_CheckMovement(NiPoint3* v, int x);
    bool SelectAndMoveToPoint(MyMover* mover, unsigned int mask1, unsigned int mask2, float dist, float minDist);
};

// Tests up to four candidate points around the actor against masks and distance limits, then moves the mover to a chosen valid point.
// @fnv 0x0099e190
bool FUN_0099e190_cls::SelectAndMoveToPoint(MyMover* mover, unsigned int mask1, unsigned int mask2, float dist,
                                            float minDist)
{
    MyActor* A9 = proc->GetFieldBC();
    MyRef* ref = proc->CombatController_GetTarget();
    float radius = A9->FUN_008be1b0() + 8.0;
    PosHolder h7;
    A9->TESObjectREFR_GetWorldLocation(&h7);
    NiPoint3 pp = *h7.Self();
    NiPoint3 T = *ref->GetPos();
    Picker p4(A9);
    NiPoint3 D_ = pp - T;
    D_.Normalize();
    NiPoint3 s = D_.Cross(DAT_011a9484);
    NiPoint3 A5[4];
    signed char slot[4];
    signed char dirOf[4];
    int n = 0;
    for (unsigned int i = 0; i < 4; i++)
    {
        slot[i] = -1;
        unsigned int bit = 1 << i;
        if (mask1 & bit)
        {
            NiPoint3 off;
            switch (bit)
            {
            case 1:
                memcpy(&off, &s, sizeof(off));
                break;
            case 2:
                memcpy(&off, &s.Neg(), sizeof(off));
                break;
            case 4:
                memcpy(&off, &D_.Neg(), sizeof(off));
                break;
            case 8:
                memcpy(&off, &D_, sizeof(off));
                break;
            }
            NiPoint3 target = pp + off * dist;
            NiPoint3 end = target + off * radius;
            if (DAT_011f1958->FUN_00825c00(target, A9, 0.0f, 0.0f, MyTimer(0.0f), 0.0f)->EvaluateThreats() > 0.0)
                continue;
            Picker hit;
            if (!FUN_006d7490(&p4, &end, &hit, 0))
            {
                if (minDist < dist)
                {
                    NiPoint3 diff3 = pp - hit.GetPoint();
                    float len = diff3.Length();
                    if (minDist > len - radius)
                        continue;
                    memcpy(&target, &(pp + off * (len - radius)), sizeof(target));
                }
                else
                {
                    continue;
                }
            }
            if (mask2 & bit)
            {
                if (!CombatUtilities_CalculateLOS(A9, ref, &target, &T, 0, -1))
                    continue;
            }
            if (!CombatState_CheckMovement(&target, h7.GetHavokWorldObjectCountInSceneGraph_0084e3a0(1, 0)))
                continue;
            memcpy(&A5[n], &target, sizeof(target));
            slot[i] = n;
            dirOf[n] = i;
            n++;
        }
    }
    if (n == 0)
        return false;
    if (last != -1 && timer.Get() < 10.0 && slot[last] != -1)
    {
        mover->CombatLocation_SetPoint(&A5[slot[last]], 0);
        return true;
    }
    int aK = RandomUnsignedInt(n);
    last = dirOf[aK];
    timer = CombatTimer_GetTimer();
    mover->CombatLocation_SetPoint(&A5[slot[last]], 0);
    return true;
}

}  // namespace fnv_0099e190

struct TargetPosition
{
    float x, y, z;
    unsigned space;
};
struct TargetRef
{
    TargetPosition TESObjectREFR_GetWorldLocation();
};
struct TargetParameters
{
    unsigned char flag;
    TargetRef* reference;
    TargetPosition position;
    float nearRange, farRange;
    TargetParameters();
};
struct TargetSetting
{
    float* Setting_Float_00403e20();
};
extern TargetSetting DAT_011cf0d8;
float BSMAX_00404010(float, float);
struct TargetWork
{
    unsigned unk0;
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    TargetParameters* parameters;
    void FreeAndClearFieldC4();
    void CombatState_SetLocationTargetRef(TargetRef*, unsigned char, float, float);
};
// @fnv 0x009a0790
// src: XBOX_PDB 0x009a0790
void TargetWork::CombatState_SetLocationTargetRef(TargetRef* reference, unsigned char flag, float nearRange, float farRange)
{
    FreeAndClearFieldC4();
    if (!reference)
        return;
    parameters = new TargetParameters;
    parameters->flag = flag;
    parameters->reference = reference;
    parameters->position = reference->TESObjectREFR_GetWorldLocation();
    parameters->nearRange = BSMAX_00404010(nearRange, *DAT_011cf0d8.Setting_Float_00403e20());
    parameters->farRange = BSMAX_00404010(farRange, *DAT_011cf0d8.Setting_Float_00403e20());
}

TESForm* __cdecl TESForm_GetFormByNumericID(TESObjectREFR* p);

class FUN_009a3220_cls
{
  public:
    char unk00[4];
    TESObjectREFR* m_04;
    void CombatState_LocationTarget_InitLoadGameBGS(int unkArg);
};

// Re-resolves m_04 through FUN_004839c0 and dynamic_cast to TESObjectREFR, or clears it to null when m_04 is null.
// @fnv 0x009a3220
// src: COMMUNITY 0x009a3220
void FUN_009a3220_cls::CombatState_LocationTarget_InitLoadGameBGS(int unkArg)
{
    m_04 = m_04 != 0 ? dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(m_04)) : 0;
}

// Grows, shrinks or clears the array to count elements, reallocating storage when needed and optionally shrinking capacity.
// @fnv 0x009a32a0
template <>
void BSSimpleArray<Elem, 1024>::SetSize(unsigned int count, bool shrink)
{
    if (count == 0)
    {
        Clear(shrink);
    }
    else if (count > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = _Allocate(count);
            SimpleArrayStorage = count;
        }
        else
        {
            ReallocateStorage(count, iSize);
            SimpleArrayStorage = count;
        }
        InitializeItems(pBuffer + iSize, count - iSize);
        iSize = count;
    }
    else if (count < iSize)
    {
        ReleaseElements(pBuffer + count, iSize - count);
        iSize = count;
        if (shrink && count <= (SimpleArrayStorage >> 2))
        {
            ReallocateStorage(count, count);
            SimpleArrayStorage = count;
        }
    }
    else
    {
        InitializeItems(pBuffer + iSize, count - iSize);
        iSize = count;
    }
}

struct LocS
{
    int v0;
    int v4;
    int v8;
    int vC;
    float DistTo(LocS* other);
};
struct Loc2S
{
    int v0;
    int v4;
    int v8;
    int vC;
};
struct CellS
{
    Loc2S GetLoc2();
};
struct RefS
{
    LocS GetLocationPointer();
    CellS* GetContainingCell();
};
struct IfaceS
{
    CombatState* GetTile();
};
struct Sub30S
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual bool IsFlagV();
};
struct ActorBaseS
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
    Sub30S data30;
};

struct NodeS
{
    RefS* ref;
    void* other;
    unsigned char level;
    unsigned char flag9;
    unsigned char flagA;
};
struct NodeArrS
{
    NodeS& GetAt(int);
    unsigned int GetSize();
};
struct GlobalIntS
{
    unsigned int* Int();
};
extern GlobalIntS g_011cfc98;
bool __cdecl CombatUtilities_CanActorExistInSpace(Actor*, Loc2S*);
struct CombatNodeFinder
{
    int unk000;
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
    int unk0d4;
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
    NodeArrS nodes;
    RefS* FindNearestCombatNode(Actor* actor, float maxDist, bool checkCell);
};

// Scans nodes for a valid, in-range reference (optionally cell-checked and tile-tested) and returns the closest one to the actor, or null.
// @fnv 0x0098c3d0
RefS* CombatNodeFinder::FindNearestCombatNode(Actor* actor, float maxDist, bool checkCell)
{
    if (actor->IsCreature() && ((ActorBaseS*)actor->GetActorBase())->data30.IsFlagV())
        return 0;
    IfaceS* iface3 = (IfaceS*)actor->GetCombatController();
    LocS actorLoc2 = actor->TESObjectREFR_GetWorldLocation<LocS>();
    RefS* bestX = 0;
    float bestDist5 = maxDist * maxDist;
    for (unsigned int i = 0; i < nodes.GetSize(); i++)
    {
        NodeS& node5 = nodes.GetAt(i);
        if (!node5.ref || !node5.other)
            continue;
        if (node5.level > *g_011cfc98.Int() || node5.flagA || node5.flag9)
            continue;
        CellS* cell2 = node5.ref->GetContainingCell();
        if (!cell2)
            continue;
        if (checkCell)
        {
            Loc2S cellLoc = cell2->GetLoc2();
            if (!CombatUtilities_CanActorExistInSpace(actor, &cellLoc))
                continue;
        }
        LocS nodeLoc2 = node5.ref->GetLocationPointer();
        if (iface3 && !iface3->GetTile()->TestLoc(&nodeLoc2, 1, 0))
            continue;
        float dist4 = actorLoc2.DistTo(&nodeLoc2);
        if (dist4 < bestDist5)
        {
            bestX = node5.ref;
            bestDist5 = dist4;
        }
    }
    return bestX;
}

struct CombatWorld
{
    int a, b, c, d;
    void* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    float ComputeWeightedDistance(const CombatWorld&, const NiPoint3&);
    float BGSWorldLocation_GetDistanceSquared(const CombatWorld&);
};

namespace fnv_00997cf0 {

struct CombatStamp
{
    int value;
    void FUN_00435de0(float);
    float AStarSearch_EvaluateValue_006a7f50();
    double FUN_00435e00();
};

struct CombatTimers
{
    int a, b;
    bool CombatTimer_IsSet();
    bool FUN_008d7f80();
    void TESWeightForm_InitializeDataComponent();
    void FUN_008d7f40(float);
    void CombatTimer_ForceTrigger();
};
struct CombatMode
{
    unsigned char type;
    bool active;
    short unk02;
    CombatActor* actor;
    CombatWorld world;
    float nearDistance, farDistance;
};
struct CombatPackage
{
    int FUN_00825c00();
};
struct CombatMap
{
    void UpdateTargetPerception(CombatActor*, CombatActor*, int*, CombatStamp*, bool*, bool*);
    CombatActor* FindNearestActor(CombatActor*, CombatActor*, float);
    CombatActor* GetFieldAtOffset16(CombatActor*);
};
struct CombatOptions
{
    bool TESCombatStyle_GetIgnoreThreats();
};
struct CombatPath
{
    bool PathingCoverLocation_CheckDynamicCoverValid(int);
};
struct CombatPathOwner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    CombatPath path;
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
    int index;
};
struct CombatHazard
{
    float EvaluateThreats(NiPoint3, CombatActor*, float, float, void*, float);
};
struct CombatHazardHolder
{
    CombatHazard* FUN_00825c00();
};
struct CombatSetting
{
    float* Setting_Float_00403e20();
};
extern CombatSetting DAT_011cf45c, DAT_011cfbcc, DAT_011ceed8;
extern CombatHazardHolder* DAT_011f1958;
extern CombatActor* DAT_011dea3c;
extern bool DAT_011f1ae4, DAT_011a4d34;
extern float DAT_011a5310, DAT_011a530c, DAT_011a5308, DAT_0108df70;
float CombatTimer_GetTimer();
float FUN_00476b70(float, float);
bool CombatUtilities_IsActorUsingMelee(CombatActor*);
struct CombatUpdate
{
    int unk000;
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
    float chaseDistance;
    int targetState;
    bool visible, detected, known;
    signed char status;
    bool differentSpace;
    unsigned char unk075;
    bool changed, updateNow;
    int unk078;
    int unk07c;
    float danger;
    NiPoint3 targetPosition;
    unsigned int flags;
    CombatStamp targetTime;
    CombatStamp seenTime;
    int unk09c;
    int unk0a0;
    CombatStamp idleTime;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    void* hazardData;
    CombatMode* mode;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    void* temporary;
    CombatStamp temporaryTime;
    CombatPathOwner* path;
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
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    CombatActor* previousTarget;
    CombatController* controller;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    CombatTimers stanceTimer;
    CombatTimers pathTimer;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    CombatTimers chaseTimer;

    void CombatState_UpdateImmediateData();
    bool GetHasBuffered360LineOfSight_00998980();
    void CombatState_CheckReferences();
    void CombatState_ClearCoverLocation(bool);
    void CombatState_SetLocationTargetRef(CombatActor*, int, float, float);
    void CombatState_SetLocationTargetLocation(CombatActor*, int, float, float);
    void FreeAndClearFieldC4();
    void UpdateModifierState(bool);
    bool CombatState_CheckUseLocationTargetMaxDistance();
    float GetInterpolatedValue();
    void EvaluateWeaponScores();
};
// Updates the combat target, detection state, path and stance timers, mode activation, danger level and chase timer for the controller's owner.
// @fnv 0x00997cf0
// src: XBOX_PDB 0x00997cf0
void CombatUpdate::CombatState_UpdateImmediateData()
{
    CombatStamp timeD3;
    CombatWorld worldB;
    CombatWorld worldAB;
    CombatStamp timeC3;
    CombatStamp timeB_1;
    CombatStamp timeA;
    CombatWorld ownLocation3;
    CombatWorld targetLocation;
    unsigned char stance;
    CombatActor* follow;
    float range_;
    // Defer point initialization to Set; /Od otherwise calls the empty default constructor.
    float weights_26[sizeof(NiPoint3) / sizeof(float)];
    float distance_1;
    bool fleeing_3;
    CombatActor* aFoundOther;
    CombatActor* found;
    CombatActor* current;
    float nearRange;
    float searchRange5;
    float farRange_5;
    CombatPackage* package2;
    int state_7;
    CombatActor* target4;
    float oldDangerX;
    void* space_41;
    CombatActor* owner_21;
    owner_21 = (CombatActor*)controller->GetFieldBC();
    {
        target4 = (CombatActor*)controller->CombatController_GetTarget();
        space_41 = owner_21->TESObjectREFR_GetSpace();
        if (target4 && space_41 != target4->TESObjectREFR_GetSpace())
        {
            if (!differentSpace)
            {
                if (visible)
                    controller->ForcePlanUpdate();
                differentSpace = true;
            }
        }
        else
            differentSpace = false;
        if (target4)
        {
            if (controller->GetFieldC5() || previousTarget != target4)
            {
                state_7 = -100;
                ((CombatMap*)controller->FUN_004fb070())->UpdateTargetPerception(owner_21, target4, &state_7, &targetTime, &visible,
                                                                   &detected);
                targetState = state_7;
                controller->SetByteAtOffsetC5(false);
            }
            if (detected)
            {
                timeA.FUN_00435de0(CombatTimer_GetTimer());
                seenTime = timeA;
                targetPosition = *(NiPoint3*)((const TESObjectREFR*)target4)->GetPos();
                package2 = (CombatPackage*)controller->FUN_004f9bf0();
                if (!package2 || package2->FUN_00825c00() != 13)
                {
                    status = -1;
                    changed = false;
                }
            }
            if (detected && !known && controller->CombatController_CombatPlanContainsAction(24))
                controller->ForcePlanUpdate();
            if (!GetHasBuffered360LineOfSight_00998980() && status == -1)
                status = 0;
        }
        else
        {
            targetState = -1;
            detected = false;
            timeB_1.FUN_00435de0(-DAT_0108df70);
            targetTime = timeB_1;
            timeC3.FUN_00435de0(-DAT_0108df70);
            seenTime = timeC3;
            status = -1;
        }
        CombatState_CheckReferences();
        if (pathTimer.CombatTimer_IsSet())
        {
            if (pathTimer.FUN_008d7f80())
            {
                CombatState_ClearCoverLocation(false);
                pathTimer.TESWeightForm_InitializeDataComponent();
            }
        }
        else if (path && path->index != -1 && !path->path.PathingCoverLocation_CheckDynamicCoverValid(path->index))
            pathTimer.FUN_008d7f40(2.0f);
        if (DAT_011f1ae4)
        {
            if (!mode || mode->type == 2)
            {
                nearRange = DAT_011a5310;
                farRange_5 = DAT_011a530c;
                searchRange5 = DAT_011a5308;
                if (CombatUtilities_IsActorUsingMelee(owner_21))
                {
                    nearRange *= 2;
                    farRange_5 *= 2;
                }
                if (farRange_5 + 256.0 > searchRange5)
                    searchRange5 = farRange_5 + 256.0;
                if (DAT_011a4d34)
                {
                    current = 0;
                    if (mode && mode->actor && ((TESForm*)mode->actor)->IsActor())
                        current = mode->actor;
                    found = ((CombatMap*)controller->FUN_004fb070())->FindNearestActor(owner_21, current, searchRange5);
                    if (found)
                        CombatState_SetLocationTargetRef(found, 2, nearRange, farRange_5);
                    else
                        FreeAndClearFieldC4();
                }
                else
                {
                    aFoundOther = ((CombatMap*)controller->FUN_004fb070())->GetFieldAtOffset16(owner_21);
                    if (aFoundOther)
                        CombatState_SetLocationTargetLocation(aFoundOther, 2, nearRange, farRange_5);
                    else
                        FreeAndClearFieldC4();
                }
            }
        }
        else if (!DAT_011f1ae4 && mode && mode->type == 2)
            FreeAndClearFieldC4();
        if (mode)
        {
            if (mode->type == 3 && mode->world.GetHavokWorldObjectCountInSceneGraph_0084e3a0() != space_41)
                UpdateModifierState(true);
            if (mode->actor)
                mode->world = *mode->actor->TESObjectREFR_GetWorldLocation(&worldAB);
            reinterpret_cast<NiPoint3*>(weights_26)->Set(1.0f, 1.0f, 0.25f);
            distance_1 = mode->world.ComputeWeightedDistance(*owner_21->TESObjectREFR_GetWorldLocation(&worldB), *reinterpret_cast<NiPoint3*>(weights_26));
            fleeing_3 = false;
            if ((mode->type == 0 || mode->type == 1) && target4 && controller->TESPackage_GetPretendInCombat() &&
                !controller->TESPackage_GetContinueDuringCombat())
                fleeing_3 = true;
            if (fleeing_3)
                mode->active = true;
            else
            {
                if (mode->farDistance > mode->nearDistance && CombatState_CheckUseLocationTargetMaxDistance())
                {
                    range_ = GetInterpolatedValue();
                    if (mode->active)
                    {
                        if (distance_1 > range_ * range_)
                            mode->active = false;
                    }
                    else
                    {
                        if (distance_1 < range_ * range_)
                            mode->active = true;
                    }
                }
                else
                {
                    mode->active = false;
                    if (distance_1 < mode->nearDistance * mode->nearDistance)
                        mode->active = true;
                }
            }
            switch (mode->type)
            {
            case 0:
                if (mode->active && !fleeing_3)
                {
                    FreeAndClearFieldC4();
                    controller->FinishedPackageTask();
                }
                break;
            case 1:
                if (controller->CombatController_GetAttackerCanSneak() && mode->actor && ((TESForm*)mode->actor)->IsActor())
                {
                    if (distance_1 < *DAT_011cf45c.Setting_Float_00403e20() * *DAT_011cf45c.Setting_Float_00403e20())
                    {
                        follow = mode->actor;
                        stance = follow->FUN_004997b0();
                        if (stance != owner_21->FUN_004997b0())
                        {
                            if (!stanceTimer.CombatTimer_IsSet())
                            {
                                if (follow == DAT_011dea3c)
                                    stanceTimer.FUN_008d7f40(FUN_00476b70(0.5f, 1.0f));
                                else
                                    stanceTimer.FUN_008d7f40(FUN_00476b70(0.1f, 0.5f));
                            }
                            else if (stanceTimer.FUN_008d7f80())
                            {
                                controller->SetFieldC7(stance);
                                stanceTimer.TESWeightForm_InitializeDataComponent();
                            }
                        }
                        else
                            stanceTimer.TESWeightForm_InitializeDataComponent();
                    }
                    else if (controller->GetByteAtOffsetC7())
                        controller->SetFieldC7(0);
                }
                break;
            }
        }
        oldDangerX = danger;
        if (!((CombatOptions*)controller->GetCurrentCombatStyle())->TESCombatStyle_GetIgnoreThreats())
        {
            if (danger > *DAT_011cfbcc.Setting_Float_00403e20() || (flags & 0x100))
            {
                danger = DAT_011f1958->FUN_00825c00()->EvaluateThreats(*(NiPoint3*)((const TESObjectREFR*)owner_21)->GetPos(), owner_21, 0, 0,
                                                                       hazardData, 0);
                if (danger >= *DAT_011cfbcc.Setting_Float_00403e20() && oldDangerX < *DAT_011cfbcc.Setting_Float_00403e20())
                    controller->ForcePlanUpdate();
            }
            else
                danger = 0;
        }
        if (idleTime.AStarSearch_EvaluateValue_006a7f50() != -DAT_0108df70 && !owner_21->Actor_IsAttacking())
        {
            timeD3.FUN_00435de0(-DAT_0108df70);
            idleTime = timeD3;
        }
        if (target4 && chaseDistance > 0.0)
        {
            owner_21->TESObjectREFR_GetWorldLocation(&ownLocation3);
            target4->TESObjectREFR_GetWorldLocation(&targetLocation);
            if (ownLocation3.BGSWorldLocation_GetDistanceSquared(targetLocation) < chaseDistance * chaseDistance)
                chaseTimer.CombatTimer_ForceTrigger();
        }
        if (updateNow || (chaseTimer.CombatTimer_IsSet() && chaseTimer.FUN_008d7f80()))
            EvaluateWeaponScores();
        UpdateModifierState(false);
        if (temporary && temporaryTime.FUN_00435e00() > *DAT_011ceed8.Setting_Float_00403e20())
            temporary = 0;
        previousTarget = target4;
    }
}
}  // namespace fnv_00997cf0

struct UpdateActor
{
    void Notify(int);
};
struct UpdateEffect
{
    int Type();
};
struct UpdateRef
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
    virtual int Query(float);
};
struct UpdateController
{
    UpdateActor* Actor();
    UpdateRef* Ref();
    unsigned char Flag();
    void Changed();
    bool Active();
    bool Ready();
    UpdateEffect* Effect();
};
struct DurationTracker
{
    int time;
    int state;
    bool Started();
    bool Expired();
    bool Randomize();
    void Reset(float);
    void Clear();
};
struct UpdateArray
{
    unsigned Count();
    int& At(unsigned);
};
struct UpdateSetting
{
    float* Float();
};
extern UpdateSetting originalRuntimeFloatSetting381, originalRuntimeFloatSetting380, originalRuntimeFloatSetting359,
    originalRuntimeFloatSetting360, originalRuntimeFloatSetting361, g_011cf198, originalRuntimeFloatSetting492;
extern const float DAT_010162c0, updateInterval;
unsigned GetRandomNumberInRange(int, int);
bool RandomBoolean(float);
struct UpdateWorld
{
    bool Test(UpdateActor*, int, int);
};
extern UpdateWorld* BGSSaveLoadGlobalDataWorldspacePtr;
struct UpdateManager
{
    void Notify(UpdateController*, int, int, int);
};
extern UpdateManager* DAT_011f1708;
struct UpdateResult
{
    int status;
    int detail;
    UpdateResult();
    ~UpdateResult();
};
struct UpdateRequest
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Poll(UpdateResult*);
};
struct UpdatePointer
{
    UpdateRequest* Get();
    void Set(int);
};
struct UpdateState
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    UpdateArray targets;
    int unk028;
    int unk02c;
    int unk030;
    int target;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    float threshold;
    int unk05c;
    int unk060;
    float elapsed;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int pending;
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
    int unk0d4;
    bool notified;
    char unk0d9;
    char unk0da;
    char unk0db;
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
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    UpdateController* controller;
    bool force;
    char unk1c9;
    char unk1ca;
    char unk1cb;
    DurationTracker timer1cc;
    DurationTracker timer1d4;
    DurationTracker timer1dc;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    DurationTracker timer204;
    DurationTracker timer20c;
    DurationTracker timer214;
    int unk21c;
    int unk220;
    UpdatePointer request;
    int requestState;
    void Changed();
    void Tick();
    void RefreshA();
    void RefreshB();
    bool Cancel();
    bool Allowed();
    bool Request(bool);
    bool GetFlag(unsigned);
    void Update();
    bool Special();
    void CombatState_UpdatePeriodicData();
};
// @fnv 0x00998a50
// src: XBOX_PDB 0x00998a50
void UpdateState::CombatState_UpdatePeriodicData()
{
    UpdateActor* count = controller->Actor();
    UpdateRef* ref = controller->Ref();
    {
        int actor = targets.Count();
        if (actor > 1)
        {
            unsigned char flag = controller->Flag();
            if (!timer214.Started() && !flag)
                timer214.Reset(*originalRuntimeFloatSetting381.Float());
            if ((timer214.Started() && timer214.Expired()) || force)
            {
                bool randomize = timer214.Randomize();
                if (RandomBoolean(*originalRuntimeFloatSetting380.Float()) || force || randomize)
                {
                    int selected = 0;
                    if (randomize && target)
                    {
                        int remaining = GetRandomNumberInRange(0, actor - 1);
                        for (unsigned index = 0; index < targets.Count(); ++index)
                        {
                            int entry = targets.At(index);
                            if (entry == target)
                                continue;
                            if (remaining == 0)
                            {
                                selected = entry;
                                break;
                            }
                            --remaining;
                        }
                    }
                    else
                    {
                        int choice = GetRandomNumberInRange(0, actor);
                        selected = targets.At(choice);
                    }
                    if (selected != target)
                    {
                        target = selected;
                        Changed();
                        controller->Changed();
                    }
                }
                timer214.Clear();
            }
        }
    }
    if (pending)
    {
        if (!timer1dc.Started())
            timer1dc.Reset(*originalRuntimeFloatSetting359.Float());
        if (timer1dc.Expired())
        {
            if (!ref || BGSSaveLoadGlobalDataWorldspacePtr->Test(count, pending, ref->Query(DAT_010162c0)))
                pending = 0;
            else
                timer1dc.Reset(*originalRuntimeFloatSetting359.Float());
        }
    }
    else
        timer1dc.Clear();
    if (timer1d4.Expired())
    {
        Tick();
        if (elapsed < threshold)
        {
            timer1d4.Reset(*originalRuntimeFloatSetting360.Float());
            elapsed = 0.0f;
        }
        else
            timer1d4.Reset(*originalRuntimeFloatSetting361.Float());
    }
    if (timer204.Expired())
    {
        RefreshA();
        timer204.Reset(*g_011cf198.Float());
    }
    if (timer20c.Expired())
    {
        RefreshB();
        timer20c.Reset(*originalRuntimeFloatSetting492.Float());
    }
    if (request.Get())
    {
        UpdateResult result;
        if (request.Get()->Poll(&result))
        {
            switch (result.status)
            {
            case 0:
                Cancel();
                requestState = -1;
                break;
            default:
                if (requestState == 1 && Allowed() && ref)
                {
                    if (!Request(false))
                        requestState = -1;
                }
                else
                    requestState = -1;
                break;
            }
            if (requestState == -1)
                request.Set(0);
        }
    }
    else if (Allowed() && ref)
    {
        if (!timer1cc.Started())
            timer1cc.Reset(updateInterval);
        if (timer1cc.Expired())
        {
            bool bRequested = false;
            if (GetFlag(2) && Request(true))
                bRequested = true;
            if (!bRequested)
                Request(false);
            timer1cc.Reset(updateInterval);
        }
    }
    else
        timer1cc.Clear();
    Update();
    if (controller->Active())
    {
        if (!controller->Ready() && !notified)
        {
            notified = true;
            count->Notify(0);
            DAT_011f1708->Notify(controller, 2, 3, 1);
        }
    }
    else
    {
        bool clear = true;
        if (controller->Effect() && controller->Effect()->Type() == 6 && Special())
            clear = false;
        if (clear)
            notified = false;
    }
}

namespace CombatWeapons {
struct Weapon;
struct Ammo;
struct Entry;
struct Item;
struct Controller;
struct Process;
struct Profile
{
    int value;
    Profile(int, int, const char*, int);
    ~Profile();
};

struct Location
{
    NiPoint3 point;
    void* cell;
    float BGSWorldLocation_GetDistanceSquared(const Location&);
};

struct Item
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
    Effects_combatstate effects;
    int FUN_00401170();
};
struct Extra
{
    bool ExtraDataList_GetCanNotWear();
};
struct Extras
{
    Extra** FUN_006815c0();
};
struct Entry
{
    Weapon* FUN_0044ddc0();
    float ItemChange_GetItemHealth(int);
    Extras* Modelloader_GetReferencedThis();
};
struct AmmoState
{
    void FUN_006ecd40(int);
    int FUN_00726070();
};
struct Animation
{
    bool Animation_ReloadAnimQueued();
};
struct Equip
{
    unsigned int unk0, unk4, unk8;
    Equip(Ammo*, int);
};
struct Process
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual Entry* Equipped();
    virtual AmmoState* Ammunition();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void EquipAmmo(Equip*);
};
struct Weapon : Item
{
    Ammo* TESObjectWEAP_GetCurrentAmmo(Actor*);
    unsigned char GetByteAt102();
    int TESObjectWEAP_GetCombatWeaponType();
    bool TESObjectWEAP_IsEmbeddedWeapon();
    Projectile* GetOrFallback(Actor*);
};
struct InventoryIterator
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    InventoryIterator();
    ~InventoryIterator();
};
struct Inventory
{
    bool AdvanceInventoryIterator(InventoryIterator*, Entry**, int);
    Ammo* FindInventoryItem(Weapon*, bool*);
    int FUN_004c8f30(Ammo*);
};
Inventory* FUN_004bf220(Actor*);
struct CombatData
{
    bool HasCombatFlag(unsigned int);
};
struct Controller
{
    Actor* GetFieldBC();
    Actor* CombatController_GetTarget();
    CombatData* GetCurrentCombatStyle();
    Weapon* GetCurrentWeapon();
};
struct WeaponScore
{
    Weapon* weapon;
    float health, damage, range;
    bool inRange;
};
struct Scores
{
    unsigned int unk0, unk4, unk8, unkc;
    Scores(int, int);
    ~Scores();
    unsigned int BSSimpleArray_CombatMember_1024_AddUninitialized();
    WeaponScore& GetIndexedValue_006b3160(unsigned int);
    WeaponScore& BSSimpleArray_CombatMember_1024_GetAt(unsigned int);
    unsigned int FUN_0044ddc0();
    void RemoveEntries(unsigned int, int);
};
struct Ammos
{
    unsigned int unk0, unk4, unk8, unkc;
    Ammos(int, int);
    ~Ammos();
    void FUN_007cb2e0(Ammo* const&);
    bool BSSimpleArray_BGSBodyPart_1024_IsInArray(Ammo* const&);
};
struct WeaponList
{
    unsigned int unk0, unk4, unk8, unkc;
    void FUN_007cb2e0(Weapon* const&);
};
struct Timer
{
    void FUN_008d7f40(float);
};

extern Setting DAT_011ce4ac, DAT_011cf660;
extern const char DAT_0108dfb0[];
extern double DAT_01017a40, DAT_01012060, DAT_0106b798, DAT_0102f078;
extern float DAT_0108dfac, DAT_010162c0;
void* ourMemset(void*, int, unsigned int);
float ComputeWeaponDamage(Actor*, Weapon*, float, CombatData*, int, int);
void CombatUtilities_ComputeOptimalWeaponRanges(Controller*, Weapon*, float&, float&, float&);
float BSMAX_00404010(float, float);
struct System
{
    bool IsThreatWithinLimits(Actor*, int, const NiPoint3&, float);
};
extern System* DAT_011f1958;
struct Manager
{
    unsigned int unk0, unk4, unk8;
    Weapon* bestWeapons[6];
    WeaponList ranged;
    Weapon* current;
    unsigned int types;
    float categoryScore[7];
    float maxDamage, maxRanged, maxScore, unk64, maxRange;
    unsigned int unk6c, unk70;
    unsigned char unk74, unk75, unk76, flag;
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    Item* aids[2];
    unsigned int unk1ac, unk1b0, unk1b4, unk1b8, aidTypes, unk1c0;
    Controller* controller;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    Timer timer;
    void CombatState_DeleteInventoryData();
    void FUN_00442a80(int);
    void EvaluateWeaponScores();
};
// Scans the actor's inventory for aids, weapons and ammo, scores each weapon by damage and range, fills bestWeapons/categoryScore, and updates the timer.
// @fnv 0x009993c0
void Manager::EvaluateWeaponScores()
{
    Profile profile(43, 1, DAT_0108dfb0, 838);
    Actor* actor = controller->GetFieldBC();
    Actor* target = controller->CombatController_GetTarget();
    CombatData* dataSlot17 = controller->GetCurrentCombatStyle();
    float distance = 0.0f;
    if (target)
    {
        Location sourcePointSlot0 = actor->TESObjectREFR_GetWorldLocation<Location>();
        Location targetPointSlot14 = target->TESObjectREFR_GetWorldLocation<Location>();
        distance = sourcePointSlot0.BGSWorldLocation_GetDistanceSquared(targetPointSlot14);
    }
    CombatState_DeleteInventoryData();
    flag = 0;
    maxDamage = 0.0f;
    maxRanged = 0.0f;
    maxScore = 0.0f;
    maxRange = 0.0f;
    types = 0;
    aidTypes = 0;
    ourMemset(categoryScore, 0, 28);
    ourMemset(aids, 0, 8);
    float aidScoresSlot19[2];
    ourMemset(aidScoresSlot19, 0, 8);
    Scores scoresSlot20(32, 0);
    Ammos ammosSlot1(32, 0);
    Entry* entry = 0;
    InventoryIterator iteratorSlot1;
    Inventory* inventorySlot40 = FUN_004bf220(actor);
    while (inventorySlot40->AdvanceInventoryIterator(&iteratorSlot1, &entry, 0))
    {
        Item* item = entry->FUN_0044ddc0();
        switch (item->FUN_00401170())
        {
        case 47: {
            Item* aid = item;
            for (unsigned int n = 0; n < 2; n++)
            {
                float scoreSlot25 = 0.0f;
                unsigned int effect = n + 17;
                switch (effect)
                {
                case 17:
                    scoreSlot25 = aid->effects.FUN_00405c00(0, 0, 16);
                    scoreSlot25 += aid->effects.FUN_00405c00(34, 0, 16);
                    break;
                case 18:
                    if (!dataSlot17->HasCombatFlag(256))
                        scoreSlot25 = aid->effects.FUN_00405c00(12, 0, 77);
                    break;
                }
                if (scoreSlot25 > aidScoresSlot19[n])
                {
                    aids[n] = item;
                    aidScoresSlot19[n] = scoreSlot25;
                    aidTypes |= 1 << effect;
                    break;
                }
            }
            break;
        }
        case 40: {
            Weapon* weaponSlot32Slot15 = (Weapon*)item;
            if (actor->Actor_CanUseWeapon((::Weapon*)weaponSlot32Slot15, 1))
            {
                unsigned int index = scoresSlot20.BSSimpleArray_CombatMember_1024_AddUninitialized();
                ourMemset(&scoresSlot20.GetIndexedValue_006b3160(index), 0, 20);
                scoresSlot20.GetIndexedValue_006b3160(index).weapon = weaponSlot32Slot15;
                scoresSlot20.GetIndexedValue_006b3160(index).health = entry->ItemChange_GetItemHealth(1) / 100.0f;
            }
            break;
        }
        case 41:
            ammosSlot1.FUN_007cb2e0((Ammo*)item);
            break;
        }
    }
    Weapon* forcedSlot30 = 0;
    Entry* equippedSlot10 = ((Process*)actor->FUN_008d8520())->Equipped();
    if (equippedSlot10 && equippedSlot10->Modelloader_GetReferencedThis() && *equippedSlot10->Modelloader_GetReferencedThis()->FUN_006815c0() &&
        (*equippedSlot10->Modelloader_GetReferencedThis()->FUN_006815c0())->ExtraDataList_GetCanNotWear())
        forcedSlot30 = equippedSlot10->FUN_0044ddc0();
    if (!forcedSlot30)
    {
        float bestOutsideSlot13 = 0.0f;
        Weapon* outsideWeaponSlot0 = 0;
        float bestInsideSlot33 = 0.0f;
        for (unsigned int i = 0; i < scoresSlot20.FUN_0044ddc0(); i++)
        {
            WeaponScore* scoreSlot25 = &scoresSlot20.BSSimpleArray_CombatMember_1024_GetAt(i);
            Weapon* weaponSlot32Slot15 = scoreSlot25->weapon;
            Actor* ownerSlot16 = (equippedSlot10 && weaponSlot32Slot15 == equippedSlot10->FUN_0044ddc0()) ? actor : 0;
            Ammo* ammoSlot1 = weaponSlot32Slot15->TESObjectWEAP_GetCurrentAmmo(ownerSlot16);
            if (ammoSlot1 && !ammosSlot1.BSSimpleArray_BGSBodyPart_1024_IsInArray(ammoSlot1))
            {
                bool special = false;
                Ammo* alternativeSlot0 = inventorySlot40->FindInventoryItem(weaponSlot32Slot15, &special);
                if (alternativeSlot0 && ammosSlot1.BSSimpleArray_BGSBodyPart_1024_IsInArray(alternativeSlot0))
                {
                    if (equippedSlot10 && weaponSlot32Slot15 == equippedSlot10->FUN_0044ddc0())
                    {
                        Animation* animation = (Animation*)actor->GetAnimData();
                        bool busySlot0 = actor->Actor_IsReloading() || (animation && animation->Animation_ReloadAnimQueued());
                        if (!busySlot0)
                        {
                            Process* process = (Process*)actor->FUN_008d8520();
                            int countSlot11 = inventorySlot40->FUN_004c8f30(alternativeSlot0);
                            Equip* replacement = new Equip(alternativeSlot0, countSlot11);
                            process->EquipAmmo(replacement);
                            process->Ammunition()->FUN_006ecd40(0);
                            actor->Actor_QueueReload();
                        }
                    }
                }
                else
                {
                    scoresSlot20.RemoveEntries(i, 1);
                    i--;
                    continue;
                }
            }
            else if (equippedSlot10 && weaponSlot32Slot15 == equippedSlot10->FUN_0044ddc0())
            {
                AmmoState* state = ((Process*)actor->FUN_008d8520())->Ammunition();
                if (state)
                {
                    Animation* animation2Slot1 = (Animation*)actor->GetAnimData();
                    Weapon* active = equippedSlot10->FUN_0044ddc0();
                    if (animation2Slot1 && active)
                    {
                        bool emptySlot0 = state && state->FUN_00726070() <= 0 && active && active->GetByteAt102() > 0;
                        bool busy2Slot10 =
                            actor->Actor_IsReloading() || (animation2Slot1 && animation2Slot1->Animation_ReloadAnimQueued());
                        if (emptySlot0 && !busy2Slot10)
                            actor->Actor_QueueReload();
                    }
                }
            }
            scoreSlot25->damage = ComputeWeaponDamage(actor, weaponSlot32Slot15, scoreSlot25->health, dataSlot17, 0, 0);
            if (scoreSlot25->damage <= DAT_01012060)
            {
                scoresSlot20.RemoveEntries(i, 1);
                i--;
                continue;
            }
            scoreSlot25->inRange = 1;
            scoreSlot25->range = 0.0f;
            int categorySlot22 = scoreSlot25->weapon->TESObjectWEAP_GetCombatWeaponType();
            if (target && (categorySlot22 == 1 || categorySlot22 == 0))
            {
                float nearRange = 0.0f;
                float middleRangeSlot34 = 0.0f;
                float farRangeSlot1 = 0.0f;
                CombatUtilities_ComputeOptimalWeaponRanges(controller, weaponSlot32Slot15, nearRange, middleRangeSlot34, farRangeSlot1);
                scoreSlot25->range = farRangeSlot1;
                if (controller->GetCurrentWeapon() == weaponSlot32Slot15)
                    farRangeSlot1 *= *DAT_011ce4ac.Setting_Float_00403e20();
                if (distance > farRangeSlot1 * farRangeSlot1)
                {
                    scoreSlot25->inRange = 0;
                    if (scoreSlot25->damage > bestOutsideSlot13)
                    {
                        bestOutsideSlot13 = scoreSlot25->damage;
                        outsideWeaponSlot0 = weaponSlot32Slot15;
                    }
                }
                else if (scoreSlot25->damage > bestInsideSlot33)
                    bestInsideSlot33 = scoreSlot25->damage;
            }
        }
        if (bestInsideSlot33 > DAT_01012060)
            outsideWeaponSlot0 = 0;
        for (unsigned int j = 0; j < scoresSlot20.FUN_0044ddc0(); j++)
        {
            WeaponScore* candidateSlot0 = &scoresSlot20.BSSimpleArray_CombatMember_1024_GetAt(j);
            Weapon* weapon2Slot11 = candidateSlot0->weapon;
            int category2Slot19 = candidateSlot0->weapon->TESObjectWEAP_GetCombatWeaponType();
            float value = candidateSlot0->damage;
            if (weapon2Slot11 == current)
                value += DAT_0106b798;
            if (weapon2Slot11 == outsideWeaponSlot0)
                candidateSlot0->inRange = 1;
            if (!candidateSlot0->inRange)
            {
                value /= DAT_0102f078;
                if (candidateSlot0->range > maxRange && candidateSlot0->damage > bestInsideSlot33)
                    maxRange = candidateSlot0->range;
            }
            if (weapon2Slot11->TESObjectWEAP_IsEmbeddedWeapon() && candidateSlot0->inRange)
                ranged.FUN_007cb2e0(weapon2Slot11);
            maxDamage = BSMAX_00404010(maxDamage, candidateSlot0->damage);
            if (category2Slot19 == 1 || category2Slot19 == 0)
                maxRanged = BSMAX_00404010(maxRanged, candidateSlot0->damage);
            maxScore = BSMAX_00404010(maxScore, value);
            types |= 1 << category2Slot19;
            if (value > categoryScore[category2Slot19])
            {
                bestWeapons[category2Slot19] = weapon2Slot11;
                categoryScore[category2Slot19] = value;
            }
        }
        categoryScore[6] = ComputeWeaponDamage(actor, 0, 1.0f, dataSlot17, 0, 0);
        maxDamage = BSMAX_00404010(maxDamage, categoryScore[6]);
        maxScore = BSMAX_00404010(maxScore, categoryScore[6]);
        types |= 64;
    }
    else
    {
        int category3 = forcedSlot30->TESObjectWEAP_GetCombatWeaponType();
        bestWeapons[category3] = forcedSlot30;
        categoryScore[category3] = DAT_0108dfac;
        types |= 1 << category3;
        maxDamage = categoryScore[category3];
        maxScore = categoryScore[category3];
        if (category3 == 1 || category3 == 0)
            maxRanged = categoryScore[category3];
    }
    if (target && bestWeapons[0])
    {
        int projectile = bestWeapons[0]->GetOrFallback(actor)->BGSProjectile_GetExplosion();
        if (!DAT_011f1958->IsThreatWithinLimits(actor, projectile, *(const NiPoint3*)((const Actor*)target)->GetPos(), DAT_010162c0))
            FUN_00442a80(projectile);
    }
    timer.FUN_008d7f40(*DAT_011cf660.Setting_Float_00403e20());
}
}

struct Caster99a420
{
    int GetTarget();
};
struct Slot99a420
{
    int target;
};
struct Track99a420
{
    int unk00;
    int target;
};

struct Combat99a420
{
    int unk000;
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
    Track99a420* track;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
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
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    Caster99a420* caster;
    int unk190;
    int unk194;
    int unk198;
    Slot99a420* slot3;
    Slot99a420* slot4;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int target;

    Slot99a420* GetSlot(unsigned int idx);
    void ClearSlot(unsigned int idx);
    void ClearCaster();
    void CombatState_ClearReferencePointer(int aTarget, bool bKeep);
};

void __fastcall FreeAndClearFieldC4(Combat99a420* thisp);

// @fnv 0x0099a420
// src: XBOX_PDB 0x0099a420
void Combat99a420::CombatState_ClearReferencePointer(int aTarget, bool bKeep)
{
    Slot99a420* pSavedSlot3 = slot3;
    Slot99a420* pSavedSlot4 = slot4;
    for (unsigned int i = 0; i < 5; i++)
    {
        Slot99a420* pSlot = GetSlot(i);
        if (pSlot && pSlot->target == aTarget)
            ClearSlot(i);
    }
    if (!bKeep)
    {
        if (pSavedSlot3 != GetSlot(3) || pSavedSlot4 != GetSlot(4))
        {
            ClearSlot(3);
            ClearSlot(4);
        }
    }
    if (track && track->target == aTarget)
        FreeAndClearFieldC4(this);
    if (caster && caster->GetTarget() == aTarget)
        ClearCaster();
    if (target == aTarget)
        target = 0;
}

struct PointC
{
    float x, y, z;
    PointC();
    PointC operator-(const PointC&) const;
    float Squared() const;
    float Length() const;
};
struct LocationC
{
    int a, b, c, d, e, f, g, h, i, j;
    LocationC(const PointC*, void*);
    ~LocationC();
    bool Validate(float);
};
struct SegmentC
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
    PointC start, kEnd4, third;
    unsigned char b4c, b4d, b4e, b4f, b50;
    bool IsSpecial();
    bool IsOther();
    bool Test(PointC*);
    PointC GetLocation();
};
struct ActorC
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
    virtual void v64();
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
    virtual PointC* Position();
    float Radius();
    float Speed();
    void* Space();
};
struct InfoC
{
    int a, b, c, d;
    InfoC();
    void Set(PointC*, void*);
};
struct QueryC
{
    int Test(InfoC*, float, int);
};
struct OptionsC;
struct ControllerC
{
    ActorC* Actor();
    QueryC* Query();
    bool ValidateCandidate(void*, SegmentC*, ControllerC*, float, OptionsC*, bool, bool);
};
struct TimeC
{
    float value;
    TimeC(float);
    TimeC(const TimeC&);
};
struct HazardC
{
    float Evaluate(PointC, ActorC*, float, float, TimeC, float);
};
struct WorldC
{
    ControllerC* Controller();
    HazardC* Hazard();
};
extern WorldC* worldC;
extern const float defaultC;
extern const float negativeC;
bool GeometryC(const PointC*, const PointC*, const PointC*, const PointC*);
bool AllowedC(ControllerC*, SegmentC*, void*, PointC*, PointC*);
bool CollisionC(void*, void*, PointC*, PointC*, int, int);
bool ObstructedC(LocationC*, PointC*, int);
struct DestinationC
{
    void Set(PointC*, int);
};
struct OptionsC
{
    unsigned char a, b, c, d, e, f;
};
struct SearchC
{
    int unk000;
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
    int unk0d4;
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
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    ControllerC* controller;
    bool Reject(void*);
    bool Adjust(SegmentC*, PointC*, PointC*, ActorC*);
    bool CheckSpace(PointC*, void*, int, int);
    bool Blocked(LocationC*, ActorC*);
    bool FindPathCandidate(SegmentC*, DestinationC*, OptionsC*, PointC*, void*, void*, int, ActorC*, ActorC*, float,
                           float, int*, float*, bool);
};
// @fnv 0x0099c230
bool SearchC::FindPathCandidate(SegmentC* segment, DestinationC* destination, OptionsC* options, PointC* target,
                                void* first, void* second, int mode, ActorC* actor, ActorC* reference, float nearRange,
                                float farRange, int* piReason, float* pfDistance, bool force)
{
    ActorC* actor13 = controller->Actor();
    float range4 = defaultC;
    if (segment->IsSpecial() && !force && !segment->b4f && !segment->b50)
    {
        *piReason = 2;
        return false;
    }
    if (first == second && !GeometryC(&segment->GetLocation(), reference->Position(), &segment->start, &segment->kEnd4))
    {
        *piReason = 13;
        return false;
    }
    if (Reject(first))
    {
        *piReason = 3;
        return false;
    }
    int failure5 = 0;
    int prevA = 0;
    *pfDistance = 0.0f;
    float travelTime8 = negativeC;
    float radius = actor13->Radius();
    unsigned preferred3 = 1;
    if (options->b)
    {
        if (options->f)
            preferred3 = 0;
    }
    else if (segment->Test(actor->Position()))
        preferred3 = 0;
    bool _special = segment->IsSpecial() && !force;
    bool _aim = (segment->IsSpecial() || segment->IsOther()) && !force;
    unsigned cCount = (_special ? 1 : 0) + 1;
    for (unsigned iteration = 0; iteration < cCount; iteration++)
    {
        if (failure5)
            prevA = failure5;
        bool alternate4 = false;
        if (_special)
        {
            if (iteration == preferred3 && segment->b4f)
                alternate4 = true;
            else if (iteration != preferred3 && segment->b50)
                alternate4 = false;
            else
                continue;
        }
        if (!worldC->Controller()->ValidateCandidate(first, segment, controller, radius, options, force, alternate4))
        {
            failure5 = 9;
            continue;
        }
        PointC fStartB;
        PointC kEnd4;
        AllowedC(controller, segment, options, &fStartB, &kEnd4);
        if (segment->IsOther() && reference && !Adjust(segment, &fStartB, target, reference))
        {
            failure5 = 6;
            continue;
        }
        LocationC location(&fStartB, segment);
        if (!location.Validate(actor13->Radius()))
        {
            failure5 = 4;
            continue;
        }
        if (_aim)
        {
            LocationC other4(&kEnd4, segment);
            if (!other4.Validate(actor13->Radius()))
            {
                failure5 = 5;
                continue;
            }
        }
        if (!CheckSpace(&fStartB, actor->Space(), 1, 0))
        {
            failure5 = 16;
            continue;
        }
        *pfDistance = (*target - fStartB).Squared();
        if (*pfDistance > farRange * farRange)
        {
            failure5 = 7;
            continue;
        }
        if (*pfDistance < nearRange * nearRange)
        {
            failure5 = 8;
            continue;
        }
        InfoC pInfo5;
        pInfo5.Set(&fStartB, actor->Space());
        if (controller->Query()->Test(&pInfo5, range4, 0))
        {
            failure5 = 10;
            continue;
        }
        if (travelTime8 == -1.0)
        {
            PointC delta4 = *actor->Position() - fStartB;
            travelTime8 = delta4.Length() / actor->Speed();
        }
        if (worldC->Hazard()->Evaluate(fStartB, actor, travelTime8, 0.0f, TimeC(0.0f), 0.0f) > 0.0)
        {
            failure5 = 11;
            continue;
        }
        if (_aim)
        {
            if (worldC->Hazard()->Evaluate(kEnd4, actor, travelTime8, 0.0f, TimeC(0.0f), 0.0f) > 0.0)
            {
                failure5 = 12;
                continue;
            }
        }
        bool _d0x = ObstructedC(&location, target, 1);
        if (!_d0x)
            _d0x = Blocked(&location, reference);
        if (_d0x)
        {
            failure5 = 13;
            continue;
        }
        bool checkPackage = true;
        if (mode == 5)
            checkPackage = false;
        else if (force)
            checkPackage = false;
        else if (first == second)
            checkPackage = false;
        if (checkPackage)
        {
            bool clear5 = CollisionC(actor, reference, &kEnd4, target, 1, -1);
            if (!clear5)
            {
                failure5 = 14;
                continue;
            }
        }
        destination->Set(&fStartB, 0);
        return true;
    }
    if (prevA > failure5)
        *piReason = prevA;
    else
        *piReason = failure5;
    return false;
}

struct FUN_005c3420_cls
{
    int __thiscall FUN_005c3420(ParentSpaceNode* out);
};
bool __cdecl FUN_006d7490(void* a, ParentSpaceNode* b, int c, int d);
extern double DAT_0108d658;

// @fnv 0x0099cc60
// src: XBOX_PDB 0x0099cc60
bool __cdecl CombatState_CheckCoverLOS(void* pNodeA, ParentSpaceNode* pNodeB, int c)
{
    ParentSpaceNode s1;
    ParentSpaceNode s2;
    if ((unsigned char)c == 0)
    {
        ((NiPoint3*)pNodeB)->SubtractIntoVector((NiPoint3*)&s2, (const NiPoint3*)((FUN_005c3420_cls*)pNodeA)->FUN_005c3420(&s1));
        if ((double)((NiPoint3*)&s2)->FUN_004a7290() > DAT_0108d658)
        {
            return false;
        }
    }
    if (FUN_006d7490(pNodeA, pNodeB, 0, 0) == false)
    {
        return false;
    }
    return true;
}

namespace fnv_0099ccd0 {

float GetDirectionAngle(const NiPoint3& kPt);
float GetAngleDelta(float fA, float fB, float* pfOut);
namespace std {
float abs(float);
}

struct FUN_006e4820_class
{
    bool IsLedgeCover_006e4820();
};
float GetActorReach(Actor* pActor, TESObjectWEAP* pWeap);
extern const double DAT_0106cd60;
extern const double DAT_01016ff0;

struct FUN_0099ccd0_shell : Combat99
{
    bool CombatState_CheckCoverSafe(Seg99* pSeg, NiPoint3* pPos, Actor* pActor, bool bCheckAngle);
};

// @fnv 0x0099ccd0
// src: XBOX_PDB 0x0099ccd0
bool FUN_0099ccd0_shell::CombatState_CheckCoverSafe(Seg99* pSeg, NiPoint3* pPos, Actor* pActor, bool bCheckAngle)
{
    NiPoint3 kTargetPos = *((const Actor*)pActor)->GetPos();
    NiPoint3 kDiff = *pPos - kTargetPos;
    float fDistSqr9 = kDiff.FUN_004a7290();
    if (fDistSqr9 < DAT_0106cd60)
        return false;
    if (bCheckAngle)
    {
        float fDesiredHeadingAngle = GetDirectionAngle(kDiff);
        float fUnused;
        float fAngleDifference = GetAngleDelta(pActor->GetCurrentTargetDistance(0), fDesiredHeadingAngle, &fUnused);
        if (std::abs(fAngleDifference) > 0.78539818525314331)
            return true;
    }
    if (CombatUtilities_IsActorUsingMelee(pActor))
    {
        float fImpulseRadiusSquared = GetActorReach((Actor*)pActor, (TESObjectWEAP*)pActor->Actor_GetCurrentWeapon()) * DAT_01016ff0;
        if (fDistSqr9 < fImpulseRadiusSquared * fImpulseRadiusSquared)
            return false;
    }
    else
    {
        PathingLocation kLoc((const ::NiPoint3&)*pPos, (TESObjectREFR*)pActor);
        if (fnv_0099e190::FUN_006d7490((fnv_0099e190::Picker*)&kLoc, (NiPoint3*)&kTargetPos, 0, 0))
            return false;
        if (((FUN_006e4820_class*)pSeg)->IsLedgeCover_006e4820())
        {
            if (!CombatState_CheckLedgeCoverAngle(pSeg, (NiPoint3*)pPos, (NiPoint3*)((const Actor*)pActor)->GetPos(), (TESObjectREFR*)pActor))
                return false;
        }
    }
    return true;
}
}  // namespace fnv_0099ccd0

// The shared Actor does not yet declare this no-argument query.
float __fastcall Actor_GetCurrentSpeed(Actor*);
struct FUN_0099d310_field_calls
{
    float GetFieldCC();
    float FUN_00453700();
};
// Owns a covered-move request initialized through its alternate constructor.
class CoveredMoveRequestStorage
{
public:
    __forceinline CoveredMoveRequestStorage()
    {
        ((PathingRequestCoveredMove*)storage)->FUN_006e4a50();
    }
    __forceinline ~CoveredMoveRequestStorage()
    {
        ((PathingRequestCoveredMove*)storage)->~PathingRequestCoveredMove();
    }
    unsigned int storage[sizeof(PathingRequestCoveredMove) / sizeof(unsigned int)];
};


// @fnv 0x0099d310
// src: XBOX_PDB 0x0099d310
void CombatState::BuildCoveredMoveRequest(PathingRequest* param)
{
    Actor* actor = (Actor*)((TESAmmoInitCalls*)(*(S81**)((char*)this + 0x1c4)))->GetFieldBC();
    void* item = ((AlchemyItem*)(*(S81**)((char*)this + 0x1c4)))->CombatController_GetTarget();
    param->PathingRequestClosePoint_SetMinDistance(actor->FUN_008be1b0());
    param->SetMaxDistance_006e5ee0(Actor_GetCurrentSpeed(actor));
    param->PathingRequestCoveredMove_SetAttackerHeight(((FUN_0099d310_field_calls*)(*(S81**)((char*)this + 0x1c4)))->GetFieldCC());
    if (((CombatController*)(*(S81**)((char*)this + 0x1c4)))->CombatController_GetAttackerCanSneak())
    {
        param->PathingRequestCoveredMove_SetAttackerSneakHeight(((FUN_0099d310_field_calls*)(*(S81**)((char*)this + 0x1c4)))->FUN_00453700());
    }
    ((PathingRequestCoveredMove*)param)->PathingRequestCoveredMove_SetAttackerHealth((float)((int(__thiscall*)(void*, unsigned int))(*(unsigned int**)((char*)actor + 0xa4))[2])(
        (char*)actor + 0xa4, 0x10));
    if (item != 0)
    {
        if (GetHasBufferedDetection_0097ee90() && (unsigned char)((char*)this)[0x74] == 0)
        {
            ((PathingRequestCoveredMove*)param)->PathingRequestCoveredMove_SetTargetLocation(((int(__thiscall*)(void*))(*(unsigned int**)item)[0x1f4 / 4])(item));
        }
        ((fnv_0099cb70::FUN_0099cb70_struct*)this)->CollectCastSoundPositions((fnv_0099cb70::Arr_006cee30*)((PathingRequestCoveredMove*)param)->GetOffsetF4());
    }
    ((fnv_009a0e10::FUN_009a0e10_shell*)this)->CollectAvoidanceItems((BSSimpleArray<void*, 1024>*)((PathingRequestCoveredMove*)param)->PathingRequestCoveredMove_GetUnreachableCoverLocations());
    if (*((void**)((char*)this + 0xe4)) != 0 && *((unsigned char*)*((void**)((char*)this + 0xe4)) + 1) != 0)
    {
        ((PathingRequestCoveredMove*)param)->PathingRequestCoveredMove_GetUnreachableCoverLocations((char*)*((void**)((char*)this + 0xe4)) + 0x68)->FUN_007cb2e0();
    }
}

struct Sub14
{
    int GetKey_006e4570();
    int PathingCoverLocation_GetDynamicCoverObstacleTimeStamp();
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
};

struct FUN_006d3150
{
    FUN_006d3150();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Sub14 sub14;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
};

struct RetObjParam
{
    void FUN_006e4430(void*);
};

struct LocalData2C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    LocalData2C* CombatLocation_CombatLocation();
};

struct CombatDecompClass : FUN_0099a9a0_shell
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
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    FUN_006d3150* unkE8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;

    bool FindBestAdvanceLocation(void* p1, FUN_006d3150* p2, LocalData2C* p3, int p4, int p5, float p6, int p7);
    bool InitSubObject(RetObjParam* a1, int a2, int a3, float a4, int a5);
};

// Resets the object, allocates a FUN_006d3150, initialises local data and calls FUN_0099d030; on success stores two sub14 values and passes sub14 to a1.
// @fnv 0x0099e060
bool CombatDecompClass::InitSubObject(RetObjParam* pRetObj, int a2, int a3, float a4, int a5)
{
    this->ReleaseStageHolder(0);
    this->unkE8 = new FUN_006d3150();
    LocalData2C local2c;
    local2c.CombatLocation_CombatLocation();
    if (!this->FindBestAdvanceLocation(&this->unk128, this->unkE8, &local2c, a3, a2, a4, a5))
    {
        this->ReleaseStageHolder(0);
        return false;
    }
    this->unkE8->unk68 = this->unkE8->sub14.GetKey_006e4570();
    this->unkE8->unk6c = this->unkE8->sub14.PathingCoverLocation_GetDynamicCoverObstacleTimeStamp();
    pRetObj->FUN_006e4430(&this->unkE8->sub14);
    return true;
}

struct PickWeapon;
struct PickActor;
struct PickRef;
struct PickVec
{
    float x, y, z;
};
struct PickLoc
{
    float x, y, z;
    unsigned space;
    float BGSWorldLocation_GetDistanceSquared(PickLoc*);
};
struct PickBase
{
    PickWeapon* GetField158();
};
struct PickNode
{
    bool ExtraDataList_GetCanNotWear();
};
struct PickWrap
{
    PickNode* node;
    PickWrap* FUN_006815c0();
};
struct PickPtr
{
    PickWrap* Modelloader_GetReferencedThis();
};
struct PickProc
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
    virtual void v64();
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
    virtual PickPtr* GetActive();
};
struct PickExtra
{
    float ExtraDataList_GetHealth();
    void* GetExtraAmmo();
};
struct PickLock
{
    bool FUN_005021a0();
};
struct PickForm
{
    unsigned FUN_00401170();
};
struct PickWeapon
{
    bool TESObjectWEAP_IsRangedWeapon();
    bool TESObjectWEAP_IsMeleeWeapon();
    void* TESObjectWEAP_GetCurrentAmmo(PickActor*);
};
struct PickRef
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
    virtual void v64();
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
    virtual PickVec* Pos();
    PickLoc TESObjectREFR_GetWorldLocation();
    PickExtra* BSFile_GetDevice();
    bool FUN_00477ba0();
    PickWeapon* BGSSaveFormBuffer_GetForm();
    PickLock* TESObjectREFR_GetLock();
    void* TESObjectREFR_GetOwner();
    bool TESObjectREFR_IsAnOwner(PickActor*, bool);
    unsigned FUN_00575610(void*);
};
struct PickActor : PickRef
{
    virtual void a126();
    virtual void a127();
    virtual void a128();
    virtual void a129();
    virtual void a130();
    virtual void a131();
    virtual void a132();
    virtual void a133();
    virtual void a134();
    virtual bool IsCreature();
    PickBase* FUN_004181e0();
    PickProc* FUN_008d8520();
    bool Actor_CanUseWeapon(PickWeapon*, int);
};
struct PickController
{
    PickActor* GetFieldBC();
    PickRef* CombatController_GetTarget();
    bool FUN_009a0240();
    PickWeapon* FUN_0044ddc0();
    unsigned GetCurrentCombatStyle();
};
struct PickEntry
{
    float ItemChange_GetItemHealth(int);
    PickWeapon* FUN_0044ddc0();
};
struct PickIter
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
    PickIter(int, PickActor*);
    PickIter(void*, PickActor*);
    ~PickIter();
};
struct PickCollection
{
    bool FindNextRef(PickIter*, PickRef**, PickEntry**, int);
};
extern PickCollection* DAT_011c95c8;
struct PickGlobal
{
    void FUN_00483710();
};
extern PickGlobal g_011f1a60;
struct PickSetting
{
    float* Setting_Float_00403e20();
};
extern PickSetting DAT_011cfb6c;
extern PickSetting DAT_011cee9c;
extern PickSetting DAT_011cec4c;
extern PickSetting DAT_011cf320;
extern PickSetting DAT_011ce460;
extern PickSetting DAT_011cfb44;
extern PickSetting DAT_011cef08;
extern PickSetting DAT_011cfa10;
extern PickSetting DAT_011cf908;
extern PickSetting DAT_011ce260;
extern PickSetting DAT_011ce7fc;
extern PickSetting DAT_011cf0c8;
extern float DAT_0108df70;
unsigned FUN_004873d0(PickWeapon*);
float ComputeWeaponDamage(PickActor*, PickWeapon*, float, unsigned, int, int);
float BSMIN(float, float);
float NiSqrt_004579e0(float);
float BSMAX_00404010(float, float);
struct WeaponSearch
{
    int unk000;
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
    float unk058;
    float unk05c;
    int unk060;
    float unk064;
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
    int unk0d4;
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
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    PickController* controller;
    bool FUN_0097fd40();
    bool CombatState_CheckMovement_009a02a0(PickLoc*, int, int);
    void SetArrayEntry(int, PickRef*, void*);
    bool SelectBestWeaponTarget();
};
// Scans nearby refs for a weapon target, scores candidates by distance and damage, and records the best pick via SetArrayEntry.
// @fnv 0x0099f6d0
bool WeaponSearch::SelectBestWeaponTarget()
{
    PickActor* aC1 = controller->GetFieldBC();
    PickRef* aFB = controller->CombatController_GetTarget();
    if (!controller->FUN_009a0240())
        return false;
    if (unk034 || ((PickEntry*)&unk024)->FUN_0044ddc0())
        return false;
    if (aC1->IsCreature())
    {
        PickBase* aPC = aC1->FUN_004181e0();
        PickWeapon* aXi = aPC->GetField158();
        if (!aXi)
            return false;
    }
    PickPtr* aId = aC1->FUN_008d8520()->GetActive();
    if (aId && aId->Modelloader_GetReferencedThis() && aId->Modelloader_GetReferencedThis()->FUN_006815c0()->node &&
        aId->Modelloader_GetReferencedThis()->FUN_006815c0()->node->ExtraDataList_GetCanNotWear())
        return false;
    g_011f1a60.FUN_00483710();
    PickLoc aI4 = aC1->TESObjectREFR_GetWorldLocation();
    PickRef* aCr = 0;
    PickWeapon* aB8 = 0;
    PickRef* aB4 = 0;
    void* aCb = 0;
    PickWeapon* aFg = controller->FUN_0044ddc0();
    bool aC2 = FUN_0097fd40();
    float aRt = aC2 ? unk05c : unk058;
    float aKB = aRt * (1.0f + *DAT_011cfb6c.Setting_Float_00403e20());
    float aPE = 1.0f;
    if (unk064 > unk058)
    {
        aPE = *DAT_011cfa10.Setting_Float_00403e20();
        aKB = BSMIN(aKB, unk064);
    }
    if (aC2)
        aPE = *DAT_011cf908.Setting_Float_00403e20();
    float aPa = 0.0f;
    float aIt = 0.0f;
    if (aC2 || (aFg && aFg->TESObjectWEAP_IsRangedWeapon()))
    {
        aPa = *DAT_011cfb44.Setting_Float_00403e20();
        aIt = *DAT_011cef08.Setting_Float_00403e20();
    }
    else
    {
        if (!aFg)
        {
            aPa = *DAT_011cee9c.Setting_Float_00403e20();
            aIt = *DAT_011cec4c.Setting_Float_00403e20();
        }
        else
        {
            aPa = *DAT_011cf320.Setting_Float_00403e20();
            aIt = *DAT_011ce460.Setting_Float_00403e20();
        }
        bool apX = false;
        if (aFB)
        {
            PickLoc bpA = aFB->TESObjectREFR_GetWorldLocation();
            if (aI4.BGSWorldLocation_GetDistanceSquared(&bpA) < 589824.0)
                apX = true;
        }
        if (!apX && unk05c > 0.0 && unk058 > 0.0)
        {
            float cb2 = unk05c / unk058;
            if (cb2 > *DAT_011ce260.Setting_Float_00403e20() && *DAT_011cef08.Setting_Float_00403e20() > aIt)
                aIt = aIt + cb2 * (*DAT_011cef08.Setting_Float_00403e20() - aIt);
        }
    }
    aPa *= aPE;
    aIt *= aPE;
    float aB1 = 0.0f;
    float aP2 = DAT_0108df70;
    PickIter ap8(40, aC1);
    PickRef* aFC = 0;
    PickEntry* aPb = 0;
    while (DAT_011c95c8->FindNextRef(&ap8, &aFC, &aPb, 3))
    {
        float cbX = aPb ? aPb->ItemChange_GetItemHealth(0) : aFC->BSFile_GetDevice()->ExtraDataList_GetHealth();
        if (aFC->FUN_00477ba0() || cbX == 0.0)
            continue;
        PickWeapon* aRy = aPb ? aPb->FUN_0044ddc0() : aFC->BGSSaveFormBuffer_GetForm();
        float ap9 = 1.0f;
        if (cbX != -1.0)
            ap9 = cbX / FUN_004873d0(aRy);
        float ch3 = ComputeWeaponDamage(aC1, aRy, ap9, controller->GetCurrentCombatStyle(), 0, 0);
        if (aRy->TESObjectWEAP_IsMeleeWeapon())
            ch3 *= *DAT_011cf0c8.Setting_Float_00403e20();
        if (ch3 <= aKB)
            continue;
        if (aC2 && !aRy->TESObjectWEAP_IsRangedWeapon())
            continue;
        if (!aC1->Actor_CanUseWeapon(aRy, 0))
            continue;
        float cbA = 0.0f;
        if (aKB <= 0.0)
            cbA = aIt * aIt;
        else
        {
            float c_2 = ch3 / aKB;
            c_2 = BSMIN(c_2, *DAT_011ce7fc.Setting_Float_00403e20());
            float d_2 = (c_2 - 1.0) / (*DAT_011ce7fc.Setting_Float_00403e20() - 1.0);
            float b10 = aPa + d_2 * (aIt - aPa);
            cbA = b10 * b10;
        }
        PickLoc aPH = aFC->TESObjectREFR_GetWorldLocation();
        float aM4 = aPH.BGSWorldLocation_GetDistanceSquared(&aI4);
        if (aM4 >= cbA)
            continue;
        if (!CombatState_CheckMovement_009a02a0(&aPH, 1, 0))
            continue;
        if (aFC->BGSSaveFormBuffer_GetForm() && ((PickForm*)aFC->BGSSaveFormBuffer_GetForm())->FUN_00401170() == 27)
        {
            PickWeapon* base = aFC->BGSSaveFormBuffer_GetForm();
            if (base)
            {
                if (aFC->TESObjectREFR_GetLock() && aFC->TESObjectREFR_GetLock()->FUN_005021a0())
                    continue;
                if (aFC->TESObjectREFR_GetOwner() && !aFC->TESObjectREFR_IsAnOwner(aC1, true))
                    continue;
            }
        }
        PickRef* ch8 = 0;
        bool ap3 = true;
        void* ap7 = aRy->TESObjectWEAP_GetCurrentAmmo(aC1);
        if (ap7)
        {
            ap3 = false;
            if (!aPb && aFC->BSFile_GetDevice()->GetExtraAmmo())
                ap3 = true;
            if (!ap3 && aC1->FUN_00575610(ap7))
                ap3 = true;
            if (!ap3 && aPb && aFC->FUN_00575610(ap7))
            {
                ap3 = true;
                ch8 = aFC;
            }
            if (!ap3)
            {
                float cb3 = DAT_0108df70;
                PickVec cb5 = *aFC->Pos();
                PickIter dy9(ap7, aC1);
                PickRef* cbB = 0;
                PickEntry* e2x = 0;
                while (DAT_011c95c8->FindNextRef(&dy9, &cbB, &e2x, 3))
                {
                    PickLoc fA8 = cbB->TESObjectREFR_GetWorldLocation();
                    float fEA = fA8.BGSWorldLocation_GetDistanceSquared(&aI4) + fA8.BGSWorldLocation_GetDistanceSquared(&aPH);
                    if (fEA > cbA || fEA > cb3)
                        continue;
                    if (!CombatState_CheckMovement_009a02a0(&fA8, 1, 0))
                        continue;
                    ch8 = cbB;
                    cb3 = fEA;
                    aM4 = fEA;
                    ap3 = true;
                }
            }
        }
        if (ap3)
        {
            float ch2 = BSMAX_00404010(NiSqrt_004579e0(aM4), 64.0f);
            float fT7 = ch3 * 10000.0 / ch2;
            bool crA = false;
            if (fT7 > aB1)
            {
                crA = true;
            }
            else if (fT7 == aB1 && aM4 < aP2)
                crA = true;
            if (crA)
            {
                aB1 = fT7;
                aP2 = aM4;
                aCr = aFC;
                aB8 = aCr ? aRy : 0;
                aB4 = ch8;
                aCb = ch8 ? ap7 : 0;
            }
        }
    }
    g_011f1a60.FUN_00483710();
    if (aCr)
    {
        SetArrayEntry(3, aB4, aCb);
        SetArrayEntry(4, aCr, aB8);
        return true;
    }
    return false;
}

extern double DAT_010718b8;
extern double _gModifierZero;

struct CS_Loc16
{
    int v0;
    int v4;
    int v8;
    int vC;
};

struct CS_AVOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetActorValue(int);
};

struct CS_Actor
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
    CS_AVOwner avOwner;
    float GetScaledRange(float);
    CS_Loc16 GetLocation(float);
};

struct CS_Item
{
    float GetRangeA(CS_Actor*);
    float GetDivA();
    float GetRangeB(CS_Actor*);
    float GetDivB();
    int TestLocation(const CS_Loc16&, int);
};

struct CS_Flags
{
    bool IsSet();
};

struct CS_Owner
{
    CS_Actor* GetActor();
    CS_Item* GetItem();
    CS_Flags* GetFlags();
};

struct CS_Timer
{
    float GetElapsedTime();
};

struct CS_Setting
{
    float* Float();
};
extern CS_Setting originalRuntimeFloatSetting439;

struct CS_State
{
    int unk00;
    int unk04;
    float fImpulseRadiusSquared;
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
    CS_Timer timerA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    unsigned char unkC8;
    unsigned char ucC9;
    unsigned char unkCA;
    unsigned char unkCB;
    int unkCC;
    int unkD0;
    int unkD4;
    unsigned char ucD8;
    unsigned char unkD9;
    unsigned char unkDA;
    unsigned char unkDB;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    CS_Owner* pOwner;
    void MarkDone(int);
    void UpdateRangeValue();
};

// @fnv 0x009a1060
void CS_State::UpdateRangeValue()
{
    CS_Actor* pActor2 = pOwner->GetActor();
    if (ucD8 != 1)
    {
        fImpulseRadiusSquared = 100.0f;
        if (timerA0.GetElapsedTime() < DAT_010718b8)
        {
            if (pActor2->avOwner.GetActorValue(0) != 3.0)
            {
                CS_Item* pItem5 = pOwner->GetItem();
                float fA4 = pItem5->GetRangeA(pActor2);
                float fDivA4 = pItem5->GetDivA();
                if (fA4 >= _gModifierZero && fDivA4 > _gModifierZero)
                {
                    fImpulseRadiusSquared = fA4 / fDivA4;
                    if (fImpulseRadiusSquared > _gModifierZero && pOwner->GetFlags()->IsSet())
                    {
                        float _fB = pItem5->GetRangeB(pActor2);
                        float fDivB5 = pItem5->GetDivB();
                        if (_fB >= _gModifierZero && fDivB5 > _gModifierZero)
                        {
                            float fScaled5 = pActor2->GetScaledRange(_fB);
                            float fNew2 = fScaled5 / fDivB5;
                            if (fNew2 < fImpulseRadiusSquared)
                            {
                                fImpulseRadiusSquared = fNew2;
                            }
                        }
                    }
                }
                if (ucD8 == 2 && ucC9 < 4)
                {
                    if (pItem5->TestLocation(pActor2->GetLocation(*originalRuntimeFloatSetting439.Float()), 1))
                    {
                        MarkDone(1);
                    }
                }
            }
        }
    }
}

struct Save435
{
    void FUN_00865e50(void*, unsigned, int);
    void FUN_00865df0(void*, int);
    void FUN_00865db0(void*, int);
    void SaveVariableSizedValue(unsigned);
};
struct Stamp435
{
    unsigned value;
    void SaveTimeStamp(Save435*);
};

struct Item435
{
    void SaveFields_009a2d20(Save435*);
};
struct ItemB435
{
    void SaveFieldsAndTimeStamp(Save435*);
};
struct List435
{
    unsigned first, second, third, fourth;
    unsigned FUN_0044ddc0();
    void** BSSimpleArray_NiAVObject_1024_GetAt(unsigned);
    Item435* BSSimpleArray_GroupMemberData_1024_GetAt(unsigned);
    ItemB435* BSSimpleArray_CombatMember_1024_GetAt(unsigned);
};
struct Optional435
{
    void CombatCoverLocation_SaveGameBGS(Save435*);
};
struct OptionalB435
{
    void CombatLocation_SaveGameBGS(Save435*);
};
struct OptionalC435
{
    void SaveState_009a3130(Save435*);
};
struct Float435
{
    float value;
    float AStarSearch_EvaluateValue_006a7f50();
};
struct Location435
{
    unsigned x00, x04, x08, x0c, x10, x14, x18;
    Float435 range;
    unsigned x20, x24, x28, x2c, x30, x34, x38;
    void CombatCoverSearch_SaveGameBGS(Save435*);
};
struct RefPair435
{
    void* first;
    void* second;
};
extern float DAT_0108df70;
struct Vec435
{
    float x, y, z;
};
struct Owner435
{
    unsigned char flag;
    unsigned char unk1;
    unsigned char unk2;
    unsigned char unk3;
    unsigned f04;
    unsigned f08;
    void* references[6];
    List435 list24;
    void* reference34;
    unsigned f38;
    unsigned values[7];
    unsigned f58;
    unsigned f5c;
    unsigned unk60;
    unsigned f64;
    unsigned f68;
    unsigned f6c;
    unsigned char f70;
    unsigned char f71;
    unsigned char f72;
    unsigned char f73;
    unsigned char f74;
    unsigned char f75;
    unsigned char f76;
    unsigned char f77;
    void* reference78;
    unsigned f7c;
    unsigned f80;
    Vec435 position;
    unsigned f90;
    Stamp435 s94;
    Stamp435 s98;
    Stamp435 s9c;
    Stamp435 sa0;
    Stamp435 sa4;
    TimeoutTimer pa8;
    TimeoutTimer pb0;
    TimeoutTimer pb8;
    Stamp435 sc0;
    OptionalC435* optionalC;
    unsigned char fc8;
    unsigned char fc9;
    unsigned char unkca;
    unsigned char unkcb;
    unsigned fcc;
    unsigned fd0;
    unsigned fd4;
    unsigned char fd8;
    unsigned char unkd9;
    unsigned char unkda;
    unsigned char unkdb;
    void* referencedc;
    Stamp435 se0;
    Optional435* optionalE4;
    Optional435* optionalE8;
    Location435 location1;
    Location435 location2;
    List435 list164;
    List435 list174;
    Stamp435 s184;
    unsigned char f188;
    unsigned char unk189;
    unsigned char unk18a;
    unsigned char unk18b;
    OptionalB435* optional18c;
    RefPair435* pairs[5];
    void* refs[2];
    TimeoutTimer timers[2];
    unsigned f1bc;
    void* ref1c0;
    unsigned unk1c4;
    unsigned char f1c8;
    unsigned char unk1c9;
    unsigned char unk1ca;
    unsigned char unk1cb;
    TimeoutTimer p1cc;
    TimeoutTimer p1d4;
    TimeoutTimer p1dc;
    TimeoutTimer p1e4;
    TimeoutTimer p1ec;
    TimeoutTimer p1f4;
    TimeoutTimer p1fc;
    TimeoutTimer p204;
    TimeoutTimer p20c;
    TimeoutTimer p214;
    TimeoutTimer p21c;
    unsigned unk224;
    unsigned f228;
    void SaveToStream(Save435*);
};
// Serializes the object's fields, references, lists, timers and optional sub-objects into the save buffer, writing presence flags before each optional block.
// @fnv 0x009a17a0
void Owner435::SaveToStream(Save435* pSaveBuffer)
{
    pSaveBuffer->FUN_00865e50(&flag, 1, 0);
    pSaveBuffer->FUN_00865e50(&f04, 4, 0);
    for (unsigned i = 0; i < 6; i++)
        pSaveBuffer->FUN_00865df0(references[i], 0);
    {
        unsigned count = &list24 ? list24.FUN_0044ddc0() : 0;
        pSaveBuffer->SaveVariableSizedValue(count);
        for (unsigned j = 0; j < count; j++)
        {
            void** item = list24.BSSimpleArray_NiAVObject_1024_GetAt(j);
            pSaveBuffer->FUN_00865df0(*item, 0);
        }
    }
    pSaveBuffer->FUN_00865df0(reference34, 0);
    pSaveBuffer->FUN_00865e50(&f38, 4, 0);
    for (unsigned uiValueIndex = 0; uiValueIndex < 7; uiValueIndex++)
        pSaveBuffer->FUN_00865e50(&values[uiValueIndex], 4, 0);
    pSaveBuffer->FUN_00865e50(&f58, 4, 0);
    pSaveBuffer->FUN_00865e50(&f5c, 4, 0);
    pSaveBuffer->FUN_00865e50(&f64, 4, 0);
    pSaveBuffer->FUN_00865e50(&f68, 4, 0);
    pSaveBuffer->FUN_00865e50(&f6c, 4, 0);
    pSaveBuffer->FUN_00865e50(&f70, 1, 0);
    pSaveBuffer->FUN_00865e50(&f71, 1, 0);
    pSaveBuffer->FUN_00865e50(&f72, 1, 0);
    pSaveBuffer->FUN_00865e50(&f73, 1, 0);
    pSaveBuffer->FUN_00865e50(&f74, 1, 0);
    pSaveBuffer->FUN_00865e50(&f75, 1, 0);
    pSaveBuffer->FUN_00865e50(&f76, 1, 0);
    pSaveBuffer->FUN_00865e50(&f77, 1, 0);
    pSaveBuffer->FUN_00865df0(reference78, 0);
    pSaveBuffer->FUN_00865e50(&f7c, 4, 0);
    pSaveBuffer->FUN_00865e50(&f80, 4, 0);
    pSaveBuffer->FUN_00865e50(&position, 12, 0);
    pSaveBuffer->FUN_00865e50(&f90, 4, 0);
    pSaveBuffer->FUN_00865e50(&fc8, 1, 0);
    pSaveBuffer->FUN_00865e50(&fc9, 1, 0);
    pSaveBuffer->FUN_00865e50(&fcc, 4, 0);
    pSaveBuffer->FUN_00865e50(&fd0, 4, 0);
    pSaveBuffer->FUN_00865e50(&fd4, 4, 0);
    pSaveBuffer->FUN_00865e50(&f08, 4, 0);
    pSaveBuffer->FUN_00865e50(&fd8, 1, 0);
    pSaveBuffer->FUN_00865db0(referencedc, 0);
    s94.SaveTimeStamp(pSaveBuffer);
    s98.SaveTimeStamp(pSaveBuffer);
    s9c.SaveTimeStamp(pSaveBuffer);
    sa0.SaveTimeStamp(pSaveBuffer);
    sa4.SaveTimeStamp(pSaveBuffer);
    pa8.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    pb0.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    sc0.SaveTimeStamp(pSaveBuffer);
    pb8.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    se0.SaveTimeStamp(pSaveBuffer);
    unsigned char flags = 0;
    if (optionalE4)
        flags |= 1;
    if (location1.range.AStarSearch_EvaluateValue_006a7f50() != -DAT_0108df70)
        flags |= 2;
    if (optionalE8)
        flags |= 4;
    if (location2.range.AStarSearch_EvaluateValue_006a7f50() != -DAT_0108df70)
        flags |= 8;
    if (optional18c)
        flags |= 16;
    if (optionalC)
        flags |= 32;
    pSaveBuffer->FUN_00865e50(&flags, 1, 0);
    if (optionalE4)
        optionalE4->CombatCoverLocation_SaveGameBGS(pSaveBuffer);
    if (optionalE8)
        optionalE8->CombatCoverLocation_SaveGameBGS(pSaveBuffer);
    if (optional18c)
        optional18c->CombatLocation_SaveGameBGS(pSaveBuffer);
    if (optionalC)
        optionalC->SaveState_009a3130(pSaveBuffer);
    if (location1.range.AStarSearch_EvaluateValue_006a7f50() != -DAT_0108df70)
        location1.CombatCoverSearch_SaveGameBGS(pSaveBuffer);
    if (location2.range.AStarSearch_EvaluateValue_006a7f50() != -DAT_0108df70)
        location2.CombatCoverSearch_SaveGameBGS(pSaveBuffer);
    {
        unsigned uiList164Count = &list164 ? list164.FUN_0044ddc0() : 0;
        pSaveBuffer->SaveVariableSizedValue(uiList164Count);
        for (unsigned uiList164Index = 0; uiList164Index < uiList164Count; uiList164Index++)
        {
            Item435* item2 = list164.BSSimpleArray_GroupMemberData_1024_GetAt(uiList164Index);
            item2->SaveFields_009a2d20(pSaveBuffer);
        }
    }
    {
        unsigned uiList174Count = &list174 ? list174.FUN_0044ddc0() : 0;
        pSaveBuffer->SaveVariableSizedValue(uiList174Count);
        for (unsigned m = 0; m < uiList174Count; m++)
        {
            ItemB435* item3 = list174.BSSimpleArray_CombatMember_1024_GetAt(m);
            item3->SaveFieldsAndTimeStamp(pSaveBuffer);
        }
    }
    s184.SaveTimeStamp(pSaveBuffer);
    pSaveBuffer->FUN_00865e50(&f188, 1, 0);
    unsigned char ucPairFlags = 0;
    for (unsigned n = 0; n < 5; n++)
    {
        if (pairs[n])
            ucPairFlags |= 1 << n;
    }
    pSaveBuffer->FUN_00865e50(&ucPairFlags, 1, 0);
    for (unsigned o = 0; o < 5; o++)
    {
        if (pairs[o])
        {
            pSaveBuffer->FUN_00865df0(pairs[o]->first, 0);
            pSaveBuffer->FUN_00865df0(pairs[o]->second, 0);
        }
    }
    for (unsigned uiRefTimerIndex = 0; uiRefTimerIndex < 2; uiRefTimerIndex++)
    {
        pSaveBuffer->FUN_00865df0(refs[uiRefTimerIndex], 0);
        timers[uiRefTimerIndex].SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    }
    pSaveBuffer->FUN_00865e50(&f1bc, 4, 0);
    pSaveBuffer->FUN_00865df0(ref1c0, 0);
    pSaveBuffer->FUN_00865e50(&f1c8, 1, 0);
    pSaveBuffer->FUN_00865e50(&f228, 4, 0);
    p1cc.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    p1d4.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    p1dc.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    p1e4.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    p1ec.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    p1f4.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    p1fc.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    p20c.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    p204.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    p214.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
    p21c.SaveGame((BGSSaveFormBuffer*)pSaveBuffer);
}

class TESFile9A2;

class Holder9A2
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    TESObjectREFR* m_pkRef;

    void ResolveRef(TESFile9A2* pkFile);
};

// Replaces m_pkRef with the result of FUN_004839c0 cast to TESObjectREFR, or null if m_pkRef is null.
// @fnv 0x009a2cc0
void Holder9A2::ResolveRef(TESFile9A2* pkFile)
{
    m_pkRef = m_pkRef ? dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(m_pkRef)) : 0;
}

namespace fnv_0099b5a0 {
// 0x0099b5a0  779 bytes  /MT /Od /Oy- /GS /EHsc /Gy

struct Sound99
{
    bool GetDetectedTargetLocation();
};
struct Snd99
{
    // FUN_0097ede0 fills this storage without constructing a NiPoint3.
    float pos[sizeof(NiPoint3) / sizeof(float)];
    int extra;
    void BGSWorldLocation_BGSWorldLocation();
    void* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    NiPoint3* FUN_006815c0();
};
struct Mob99
{
    void* TESObjectREFR_GetSpace();
};
struct Ammo99
{
    Sound99* BGSProjectile_GetExplosion();
};
struct Weap99
{
    void* GetOrFallback(void*);
};
struct Spell99
{
    void* GetFieldBC();
    void* CombatController_GetTarget();
    Sound99* FUN_004fb070(void*, Snd99*);
};
struct Clock99
{
    float FUN_00435e00();
};
struct SndMgr99
{
    bool IsThreatWithinLimits(void*, Sound99*, NiPoint3*, float);
};
struct A1_99
{
    void CombatLocation_SetPoint(NiPoint3*, int);
};

extern "C" NiPoint3 DAT_011f426c;
extern "C" SndMgr99* DAT_011f1958;

void __cdecl CombatUtilities_GetAttackerFiringLocation(NiPoint3*, void*);
float __cdecl CombatUtilities_GetProjectileMaximumRange(Ammo99*, float);
float __cdecl CombatUtilities_GetTargetFiringZOffset(void*, int, int);
bool __cdecl CombatUtilities_CheckProjectileArc_009a7670(void*, void*, Ammo99*, NiPoint3, NiPoint3, NiPoint3, char*, NiPoint3*, float);
float __cdecl ComputeProjectileFlightTime(Ammo99*, NiPoint3, NiPoint3, char, float);

struct FUN_0099b5a0_holder
{
    char pad00[0x84];
    NiPoint3 pt84;
    char pad90[0x98 - 0x90];
    Clock99 clk;
    char pad99[0x1c4 - 0x99];
    Spell99* p1c4;

    bool CombatState_FindGrenadeThrowLocation(A1_99* a1, char* a2, Weap99* a3);
};

// @fnv 0x0099b5a0
// src: COMMUNITY 0x0099b5a0
bool FUN_0099b5a0_holder::CombatState_FindGrenadeThrowLocation(A1_99* a1, char* acArg, Weap99* apWeapon)
{
    if (!apWeapon || !apWeapon->GetOrFallback(p1c4->GetFieldBC()))
        return false;
    Mob99* mobj3 = (Mob99*)p1c4->GetFieldBC();
    Spell99* spellB = (Spell99*)p1c4->CombatController_GetTarget();
    if (!spellB)
        return false;
    Ammo99* ammoA = (Ammo99*)apWeapon->GetOrFallback(mobj3);
    float f6 = CombatUtilities_GetProjectileMaximumRange(ammoA, 0.0f);
    // This output buffer is populated without default construction in the game.
    float posVal[sizeof(NiPoint3) / sizeof(float)];
    CombatUtilities_GetAttackerFiringLocation((NiPoint3*)posVal, mobj3);

    for (unsigned i = 0; i < 2; i++)
    {
        NiPoint3 v9;
        if (i == 0)
        {
            Snd99 s2;
            s2.BGSWorldLocation_BGSWorldLocation();
            if (!p1c4->FUN_004fb070(spellB, &s2)->GetDetectedTargetLocation())
                continue;
            if (s2.GetHavokWorldObjectCountInSceneGraph_0084e3a0() != mobj3->TESObjectREFR_GetSpace())
                continue;
            v9 = *s2.FUN_006815c0();
        }
        else
        {
            if (clk.FUN_00435e00() > 10.0)
                continue;
            v9 = pt84;
        }
        v9.z += CombatUtilities_GetTargetFiringZOffset(spellB, 2, 0);
        NiPoint3 d_ = v9.SubtractIntoVector(*(const NiPoint3*)posVal);
        float len = d_.GetSquaredXYLength();
        if (f6 * f6 < len)
            continue;
        if (len < 65536.0)
            continue;

        Sound99* snd2 = ammoA->BGSProjectile_GetExplosion();
        if (snd2)
        {
            if (!DAT_011f1958->IsThreatWithinLimits(mobj3, snd2, (NiPoint3*)&v9, 0.0f))
                continue;
        }
        NiPoint3 tB;
        if (CombatUtilities_CheckProjectileArc_009a7670(mobj3, spellB, ammoA, *(NiPoint3*)posVal, v9, DAT_011f426c, acArg, &tB, -1.0f))
        {
            if (snd2)
            {
                float r = ComputeProjectileFlightTime(ammoA, *(NiPoint3*)posVal, v9, *acArg, 0.0f);
                if (!DAT_011f1958->IsThreatWithinLimits(mobj3, snd2, (NiPoint3*)&v9, r))
                    continue;
            }
            a1->CombatLocation_SetPoint((NiPoint3*)&v9, 0);
            return true;
        }
    }
    return false;
}
}  // namespace fnv_0099b5a0

namespace fnv_0099b8e0 {
struct QPoint
{
    float x, y, z;
    QPoint();
    QPoint operator-(const QPoint& rhs) const;
};

struct QWorldLoc
{
    QPoint& GetPoint();
};

struct QTarget
{
    unsigned char type;
    char pad1[7];
    QWorldLoc loc;
};

struct QRef
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
    virtual QPoint* GetPos();
};

struct QWeapon
{
    float GetRange();
};
struct QCombatInfo
{
    float GetMinRange(QPoint* out);
    float GetMaxRange(QPoint* out);
};
struct QProcess
{
    QWeapon* GetLoadedForm();
    QCombatInfo* GetCombatInfo();
};

struct QCombatCtrl
{
    QRef* GetActor();
    QWeapon* GetLoadedForm();
    QCombatInfo* GetCombatInfo();
    QRef* GetTarget();
    float GetCoverOffset();
    float GetCoverHeight();
    bool IsFlanking();
};

struct QSetting
{
    float* Get();
};
struct QLock
{
    void Signal();
};
struct QClock
{
    unsigned int GetTime();
};
struct QLockable
{
    void Lock();
    void Unlock();
};
struct QMgr
{
    QLockable* GetLockable();
};
struct QTimer
{
    float GetValue();
};
struct QCoverMgr
{
    void Update();
};

struct QStamp
{
    int v;
    QStamp(float f);
    static float Now();
};

struct QSearchFlags
{
    bool a, b, c, d, e, f;
    QSearchFlags();
};

struct QLocElem
{
    char pad0[0x52];
    char state;
    int GetKey();
    unsigned int GetTimeStamp();
};

struct QLocSlot
{
    void Set(QLocElem* e);
    bool IsValid();
};

struct QOut
{
    QPoint pos;
    QPoint dest;
    float radius;
    QStamp stamp;
    BSSimpleArray<QLocElem, 1024> locs;
    int key;
    int result;
    bool useCover;
};

struct QState
{
    char b0;
    char b1;
    char valid;
    char b3;
    int type;
    QPoint pos;
    QLocSlot slot;
    char pad18[0x50];
    int key;
    unsigned int timeStamp;
    QSearchFlags flags;
    void SetDirty(int);
};

struct QBuilder
{
    int data[0x3c];
    QBuilder();
    ~QBuilder();
    void SetOrigin(void* src);
    void SetFirst(QPoint* p);
    void SetTarget(QPoint* p);
    void SetMinDist(float f);
    void SetMaxDist(float f);
    void SetMaxCount(int n);
    void SetFlagA(bool b);
    void SetFlagB(bool b);
    void SetFlagC(bool b);
    void SetHeight(float f);
    void SetOffset(float f);
    void SetFlank(bool b);
    void SetFlagD(bool b);
};

struct QOrigin
{
    int data[0xa];
    QOrigin(QPoint* pos, QRef* actor);
    ~QOrigin();
};

void CombatUtilities_ComputeOptimalWeaponRanges(QCombatCtrl* ctrl, int a, float* minDist, float* maxDist, float* limit);
float BSMIN(float a, float b);
int FindNearbyTriangles(QBuilder* b, BSSimpleArray<QLocElem, 1024>* arr);

extern QLock DAT_011f1a61;
extern QSetting DAT_011ce3f0;
extern QSetting DAT_011ced34;
extern QSetting DAT_011cf8d4;
extern QSetting DAT_011cf6cc;
extern QClock DAT_011f6394;
extern QMgr* DAT_011f1958;
extern const float DAT_010231a0;
extern const float DAT_01018bfc;
extern const float DAT_01022958;
extern const float DAT_01017a3c;
extern const double DAT_01011590;
extern const double DAT_01017b70;
extern const double DAT_01021928;

struct FUN_0099b8e0_cls
{
    char pad0[0x84];
    QPoint coverPos;
    char pad90[8];
    QTimer timer;
    char pad9c[0x28];
    QTarget* target;
    char padc8[0xfc];
    QCombatCtrl* ctrl;
    char pad1c8[0x34];
    QCoverMgr coverMgr;

    bool FindPathCandidate(void* slot, int a4, QSearchFlags* flags, QPoint* pos, int key, int key2, int type,
                           QRef* actor, QRef* target, float minDist, float maxDist, int* result, float* score,
                           bool flank);
    float GetTargetDist();
    bool CombatState_FindBestCoverLocation(int a1, QOut* out, QState* st, int a4, int type);
};

// @fnv 0x0099b8e0
// src: COMMUNITY 0x0099b8e0
bool FUN_0099b8e0_cls::CombatState_FindBestCoverLocation(int a1, QOut* out, QState* st, int a4, int aiSearchType)
{
    DAT_011f1a61.Signal();
    float kMinHeight = DAT_010231a0;
    float dist7 = DAT_01018bfc;
    const int fMax2 = 200;
    QRef* self2 = ctrl->GetActor();
    QRef* target = ctrl->GetTarget();
    if (!target)
    {
        return false;
    }
    float f = 0.0f;
    float fMin3 = DAT_010231a0;
    float range5 = DAT_01018bfc;
    float cap3 = DAT_01018bfc;
    CombatUtilities_ComputeOptimalWeaponRanges(ctrl, a1, &f, &range5, &cap3);
    range5 *= *DAT_011ce3f0.Get();
    range5 = BSMIN(range5, cap3);
    bool flag = false;
    bool flagB = false;
    bool flagC = false;
    bool flank = false;
    switch (aiSearchType)
    {
    case 12:
        fMin3 = *DAT_011ced34.Get();
        dist7 = *DAT_011cf8d4.Get();
        range5 = DAT_01022958;
        flagB = true;
        flagC = true;
        flank = true;
        break;
    case 10:
        range5 = DAT_01022958;
        flank = true;
        break;
    case 4:
        flank = true;
        flag = true;
        break;
    case 5:
        dist7 = DAT_01017a3c;
        range5 = DAT_01022958;
        flank = true;
        flagB = true;
        flagC = true;
        break;
    case 2:
        dist7 = ctrl->GetLoadedForm()->GetRange();
        break;
    }
    int aUres = 0;
    float score5 = 0.0f;
    if (st->key)
    {
        out->key = st->key;
        out->result = 0;
        if (aiSearchType == st->type)
        {
            float half = fMin3 / DAT_01011590;
            if (FindPathCandidate(&st->slot, a4, &st->flags, &st->pos, st->key, st->key, aiSearchType, self2, target,
                                  half, range5, &aUres, &score5, flank))
            {
                st->SetDirty(0);
                DAT_011f1a61.Signal();
                return true;
            }
            out->result = aUres;
        }
        else
        {
            out->result = 15;
        }
    }
    else
    {
        out->key = 0;
    }
    QPoint pos2;
    if (this->target && (this->target->type == 1 || this->target->type == 2))
    {
        pos2 = this->target->loc.GetPoint();
        dist7 = GetTargetDist();
    }
    else
    {
        pos2 = *self2->GetPos();
    }
    QBuilder builder2;
    QOrigin origin(&pos2, self2);
    builder2.SetOrigin(&origin);
    if (aiSearchType == 5)
    {
        QPoint lo3;
        QPoint maxPt;
        float _lo = ctrl->GetCombatInfo()->GetMinRange(&lo3);
        float hiA3 = ctrl->GetCombatInfo()->GetMaxRange(&maxPt);
        out->pos = lo3;
        QPoint dir = maxPt - lo3;
        builder2.SetTarget(&dir);
    }
    else
    {
        out->useCover = timer.GetValue() < *DAT_011cf6cc.Get();
        if (out->useCover)
        {
            out->pos = coverPos;
        }
        else
        {
            out->pos = *target->GetPos();
        }
    }
    builder2.SetFirst(&out->pos);
    builder2.SetMinDist(kMinHeight);
    builder2.SetMaxDist(dist7);
    builder2.SetMaxCount(fMax2);
    builder2.SetFlagA(flag);
    builder2.SetFlagB(flagB);
    builder2.SetFlagC(flagC);
    builder2.SetHeight(ctrl->GetCoverHeight());
    builder2.SetOffset(ctrl->GetCoverOffset());
    builder2.SetFlank(ctrl->IsFlanking());
    builder2.SetFlagD(flank);
    st->type = aiSearchType;
    st->pos = out->pos;
    out->stamp = QStamp::Now();
    out->dest = pos2;
    out->radius = dist7;
    out->locs.Clear(false);
    if (FindNearbyTriangles(&builder2, &out->locs))
    {
        DAT_011f1958->GetLockable()->Lock();
        for (unsigned int i = 0; i < out->locs.GetSize(); i++)
        {
            QLocElem* elem = &out->locs.GetAt(i);
            int _resC = 0;
            float score8 = 0.0f;
            int id = elem->GetKey();
            if (id != st->key)
            {
                unsigned int ts = elem->GetTimeStamp();
                if (ts)
                {
                    if ((DAT_011f6394.GetTime() - ts) / DAT_01017b70 < DAT_01021928)
                    {
                        elem->state = 1;
                        continue;
                    }
                }
                QSearchFlags flags;
                if (FindPathCandidate(elem, a4, &flags, &st->pos, id, 0, aiSearchType, self2, target, fMin3, range5,
                                      &_resC, &score8, flank))
                {
                    elem->state = 19;
                    st->slot.Set(elem);
                    st->key = id;
                    st->timeStamp = ts;
                    st->flags = flags;
                    st->valid = st->slot.IsValid();
                    st->SetDirty(0);
                    coverMgr.Update();
                    DAT_011f1a61.Signal();
                    return true;
                }
                elem->state = _resC;
            }
            else
            {
                elem->state = aUres;
            }
        }
        DAT_011f1958->GetLockable()->Unlock();
    }
    DAT_011f1a61.Signal();
    return false;
}
}  // namespace fnv_0099b8e0

struct Pos9f48
{
    float x, y, z;
    float w;
    float BGSWorldLocation_GetDistanceSquared(const Pos9f48& kOther);
};


// 0x0088c600 is an Actor visibility query absent from include/Actor.h.
struct AllyVisibilityQuery : Actor
{
    bool IsTargetIn360View(void* target);
};

struct Process9f48
{
    CombatState* CombatController_GetCombatState();
};

struct Group9f48
{
    bool CombatGroup_IsMember(Actor* pkMember);
    unsigned int CombatGroup_GetMemberCount();
    Actor* GetIntAt(unsigned int uiIndex);
};

struct Request9f48
{
    char m_acPad[0x10];
    Actor* m_pkTarget;
    void CombatLocation_SetTarget(Actor* pkTarget);
    void CombatLocation_SetRadius(float fImpulseRadiusSquared);
};
using ::SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting430;

struct Planner9f48
{
    char m_acPad[0x1c4];
    CombatController* m_pkController;
    bool CombatState_CheckMovement_009a02a0(Pos9f48* pkPosition, int iA, int iB);
    bool TryAssignAllyTarget(Request9f48* pkRequest, int iUnused);
};

// @fnv 0x0099f480
bool Planner9f48::TryAssignAllyTarget(Request9f48* pkRequest, int iUnused)
{
    Group9f48* pkGroupList = (Group9f48*)m_pkController->FUN_004fb070();
    if (pkRequest->m_pkTarget && pkRequest->m_pkTarget->IsActor())
    {
        Actor* pkTarget = pkRequest->m_pkTarget;
        if (pkGroupList->CombatGroup_IsMember(pkTarget))
        {
            Process9f48* pkProcess = (Process9f48*)pkTarget->GetCombatController();
            if (pkProcess && pkProcess->CombatController_GetCombatState()->GetHasBuffered360LineOfSight_00998980())
                return true;
            else if (((AllyVisibilityQuery*)pkTarget)->IsTargetIn360View(m_pkController->CombatController_GetTarget()))
                return true;
        }
    }
    Actor* pkOwner = (Actor*)m_pkController->GetFieldBC();
    Pos9f48 kOwnerPos;
    pkOwner->TESObjectREFR_GetWorldLocation((void*)&kOwnerPos);
    Actor* pkAlly = 0;
    float fClosest = 67108864.0f;
    unsigned int ItemUpdateArray = pkGroupList->CombatGroup_GetMemberCount();
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        Actor* pkMember = pkGroupList->GetIntAt(i);
        if (pkMember == pkOwner)
            continue;
        bool bUsable = false;
        Process9f48* pkOtherProcess = (Process9f48*)pkMember->GetCombatController();
        if (pkOtherProcess && pkOtherProcess->CombatController_GetCombatState()->GetHasBuffered360LineOfSight_00998980())
            bUsable = true;
        else if (((AllyVisibilityQuery*)pkMember)->IsTargetIn360View(m_pkController->CombatController_GetTarget()))
            bUsable = true;
        if (!bUsable)
            continue;
        Pos9f48 kPos;
        pkMember->TESObjectREFR_GetWorldLocation((void*)&kPos);
        float fDistance = kPos.BGSWorldLocation_GetDistanceSquared(kOwnerPos);
        if (fDistance >= fClosest)
            continue;
        if (!CombatState_CheckMovement_009a02a0(&kPos, 1, 0))
            continue;
        pkAlly = pkMember;
        fClosest = fDistance;
    }
    if (pkAlly)
    {
        pkRequest->CombatLocation_SetTarget(pkAlly);
        pkRequest->CombatLocation_SetRadius(pkAlly->FUN_008be1b0() + pkOwner->FUN_008be1b0() +
                                *originalRuntimeFloatSetting430.Setting_Float_00403e20());
        return true;
    }
    return false;
}

namespace CombatFind {

struct CombatPoint3
{
    float x, y, z;
};

struct CombatSpot;

struct CombatCell
{
    bool FUN_00439090(void* apKey);
    bool HasEqualComponents(void* apKey);
};

struct CombatPos
{
    float x, y, z, w;
    CombatPos();
    CombatCell* FUN_006815c0();
};

struct CombatRef
{
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void r074();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual CombatPoint3* GetPos();
    float FUN_008be1b0();
    float Actor_GetForwardLength();
    float FUN_00571600();
    void* TESObjectREFR_GetSpace();
    CombatPos TESObjectREFR_GetWorldLocation();
};

struct CombatSpot
{
    CombatSpot();
    void FUN_00600ab0(int aiType);
    void CombatLocation_SetRadius(float afRadius);
    void CombatLocation_Copy(void* apSource);
    void CopyRefValue();
    void CombatLocation_SetTarget(CombatRef* apRef);
    void AssignV4(CombatPos* apPos);
    void SetFlags(int aiMode, int aiFlag);
    CombatPos* FUN_006815c0();
    CombatCell* CombatLocation_GetPoint();
    int CallReferencedFunction();
    void CombatLocation_SetSpace(void* apCell);
    int iData[8];
};

struct CombatSearch
{
    CombatSearch();
    ~CombatSearch();
    void CombatCoverLocation_Copy(void* apSource);
    char pad00[0x68];
    int iCount;
    int iData[3];
};

struct CombatTimed
{
    int FUN_00825c00();
};

struct CombatTyped
{
    int iValue;
    int iType;
};

struct CombatTargetInfo
{
    bool bInvalid;
    char pad01[3];
    CombatRef* pRef;
    CombatPos kPos;
    float fRadius;
};

struct CombatSlot
{
    CombatRef* pRef;
};

struct CombatPathing
{
    bool GetDetectedTargetLocation(CombatRef* apTarget, CombatPos* apOut);
    CombatPos* FindBestItem(CombatRef* apActor, int aiRadius, CombatPos* apFrom);
};

struct CombatLocations
{
    int CombatPlannerData_GetLocation(int aiType);
    void CombatPlannerData_SetLinkLocation(int aiType);
    float CombatPlannerData_GetCombatLocationCost(int aiType);
    void SetEntry(int aiType, CombatSpot* apSpot, float afDistance);
    void CombatPlannerData_SetCombatCoverLocation(int aiType, CombatSearch* apSearch);
};

struct CombatTypeInfo
{
    bool bSkipSearch;
    bool bMeasure;
    char pad02[2];
    float fRadius;
};
extern CombatTypeInfo DAT_011a5650[];

struct CombatSetting
{
    float* Setting_Float_00403e20();
};
extern CombatSetting DAT_011cf914;
extern char DAT_011f426c;
extern const float DAT_0108df70;

int __cdecl Warning_005b5e40(const char* apFormat, ...);
float __cdecl CombatAction_GetMovementCost(CombatController* apController, CombatPos* apFrom, CombatPos* apTo);

}  // namespace CombatFind


// Finds a location for aiType using a CombatFind::CombatSpot and CombatFind::CombatSearch, then stores the result through pLocationsRes.
// @fnv 0x0099ac20
// src: EXE 0x0099ac20
bool CombatState::FindCombatLocation_0099ac20(int aiType)
{
    CombatFind::CombatRef* pActorOld = (CombatFind::CombatRef*)(*(CombatController**)((char*)this + 0x1c4))->GetFieldBC();
    CombatFind::CombatRef* pTarget = (CombatFind::CombatRef*)(*(CombatController**)((char*)this + 0x1c4))->CombatController_GetTarget();
    CombatFind::CombatPathing* pPathingTmp = (CombatFind::CombatPathing*)(*(CombatController**)((char*)this + 0x1c4))->FUN_004fb070();
    CombatFind::CombatLocations* pLocationsRes = (CombatFind::CombatLocations*)(*(CombatController**)((char*)this + 0x1c4))->FUN_005e3fc0();
    if (pLocationsRes->CombatPlannerData_GetLocation(aiType))
    {
        pLocationsRes->CombatPlannerData_SetLinkLocation(aiType);
        return true;
    }
    else if (pLocationsRes->CombatPlannerData_GetCombatLocationCost(aiType) == CombatFind::DAT_0108df70)
    {
        return false;
    }
    bool bFound = false;
    CombatFind::CombatSpot* pFinalSpot = new CombatFind::CombatSpot();
    CombatFind::CombatSearch* pSearch = new CombatFind::CombatSearch();
    pFinalSpot->FUN_00600ab0(aiType);
    pFinalSpot->CombatLocation_SetRadius(CombatFind::DAT_011a5650[aiType].fRadius);
    if ((*(CombatFind::CombatTimed**)((char*)this + 0x18c)) && (*(CombatFind::CombatTimed**)((char*)this + 0x18c))->FUN_00825c00() == aiType)
    {
        pFinalSpot->CombatLocation_Copy((*(CombatFind::CombatTimed**)((char*)this + 0x18c)));
        if ((*(CombatFind::CombatTyped**)((char*)this + 0xe4)) && (*(CombatFind::CombatTyped**)((char*)this + 0xe4))->iType == aiType)
            pSearch->CombatCoverLocation_Copy((*(CombatFind::CombatTyped**)((char*)this + 0xe4)));
        if (!CombatFind::DAT_011a5650[aiType].bSkipSearch)
        {
            pFinalSpot->CopyRefValue();
            bFound = true;
        }
    }
    bool bFlag = false;
    switch (aiType)
    {
    case 10:
    case 12:
    case 15:
        bFlag = true;
    }
    if (!bFound)
    {
        switch (aiType)
        {
        case 0:
        case 1:
            if (pTarget)
            {
                if (GetHasBufferedDetection_0097ee90())
                {
                    if (!FUN_0097fd40())
                    {
                        pFinalSpot->CombatLocation_SetTarget(pTarget);
                        bFound = true;
                    }
                }
                else
                {
                    CombatFind::CombatPos kPoint;
                    if (pPathingTmp->GetDetectedTargetLocation(pTarget, &kPoint))
                    {
                        pFinalSpot->AssignV4(&kPoint);
                        bFound = true;
                    }
                }
            }
            break;
        case 2:
        case 4:
        case 5:
            bFound = CombatState_FindBestCoverLocation((*(CombatController**)((char*)this + 0x1c4))->GetCurrentWeapon(), ((char*)this + 0xec), (::CombatSearch*)pSearch, (::CombatSpot*)pFinalSpot, aiType);
            break;
        case 3:
            bFound = SelectAndMoveToPoint((::CombatSpot*)pFinalSpot, 3, 0xf, 128.0f, 128.0f);
            break;
        case 6:
            if ((*(CombatFind::CombatTargetInfo**)((char*)this + 0xc4)) && !(*(CombatFind::CombatTargetInfo**)((char*)this + 0xc4))->bInvalid)
            {
                bFound = FindBestAdvanceLocation(((char*)this + 0xec), (::CombatSearch*)pSearch, (::CombatSpot*)pFinalSpot, aiType, (::CombatPos*)(*(CombatFind::CombatTargetInfo**)((char*)this + 0xc4))->kPos.FUN_006815c0(),
                                      0.0f, 0);
            }
            else if ((*(CombatController**)((char*)this + 0x1c4))->CombatController_GetTarget())
            {
                CombatFind::CombatPoint3 kTargetPos = *((CombatFind::CombatRef*)(*(CombatController**)((char*)this + 0x1c4))->CombatController_GetTarget())->GetPos();
                bFound = FindBestAdvanceLocation(((char*)this + 0xec), (::CombatSearch*)pSearch, (::CombatSpot*)pFinalSpot, aiType, (::CombatPos*)&kTargetPos, 0.0f, 0);
            }
            break;
        case 7:
        case 8:
        case 9:
        case 16:
            if ((*(CombatFind::CombatTargetInfo**)((char*)this + 0xc4)) && (aiType != 8 || !FUN_00461580(1 << aiType)))
            {
                if ((*(CombatFind::CombatTargetInfo**)((char*)this + 0xc4))->pRef)
                {
                    pFinalSpot->CombatLocation_SetTarget((*(CombatFind::CombatTargetInfo**)((char*)this + 0xc4))->pRef);
                    if ((*(CombatFind::CombatTargetInfo**)((char*)this + 0xc4))->pRef->IsActor())
                    {
                        CombatFind::CombatRef* pActor = (*(CombatFind::CombatTargetInfo**)((char*)this + 0xc4))->pRef;
                        pFinalSpot->CombatLocation_SetRadius(pActor->FUN_008be1b0() + pActorOld->FUN_008be1b0());
                    }
                }
                else
                {
                    pFinalSpot->AssignV4(&(*(CombatFind::CombatTargetInfo**)((char*)this + 0xc4))->kPos);
                }
                pFinalSpot->CombatLocation_SetRadius((*(CombatFind::CombatTargetInfo**)((char*)this + 0xc4))->fRadius);
                bFound = true;
            }
            break;
        case 11:
            bFound = CombatState_FindGrenadeThrowLocation((::CombatSpot*)pFinalSpot, ((char*)this + 0x76), (*(int*)((char*)this + 0x18)));
            break;
        case 10:
        case 12:
            bFound = CombatState_FindBestFleeLocation((::CombatSearch*)pSearch, (::CombatSpot*)pFinalSpot, aiType);
            break;
        case 13:
            bFound = TryAssignAllyTarget((::CombatSpot*)pFinalSpot, aiType);
            break;
        case 14:
            pFinalSpot->SetFlags(1, 1);
            bFound = true;
            break;
        case 15: {
            CombatFind::CombatPos* pCover = ((CombatFind::CombatPathing*)(*(CombatController**)((char*)this + 0x1c4))->FUN_004fb070())->FindBestItem(pActorOld, 0x32, pFinalSpot->FUN_006815c0());
            if (pCover)
            {
                pFinalSpot->AssignV4(pCover);
                bFound = true;
            }
            else if (pFinalSpot->CombatLocation_GetPoint()->FUN_00439090(&CombatFind::DAT_011f426c))
            {
                bFound = true;
            }
            if (bFound)
                pFinalSpot->SetFlags(2, 1);
            break;
        }
        case 17:
        case 18:
        case 19:
        case 20:
        case 21: {
            CombatFind::CombatSlot* pSlot = (CombatFind::CombatSlot*)GetActionAtIndex(aiType - 0x11);
            if (pSlot && pSlot->pRef)
            {
                pFinalSpot->CombatLocation_SetTarget(pSlot->pRef);
                pFinalSpot->CombatLocation_SetRadius(pSlot->pRef->FUN_00571600() + pActorOld->Actor_GetForwardLength() +
                                         *CombatFind::DAT_011cf914.Setting_Float_00403e20());
                pFinalSpot->SetFlags(2, 1);
                bFound = true;
            }
            break;
        }
        default:
            CombatFind::Warning_005b5e40("COMBAT: Invalid combat location type %i passed to CombatState::FindCombatLocation()", aiType);
        }
    }
    if (bFound)
    {
        if (!pFinalSpot->CallReferencedFunction())
            pFinalSpot->CombatLocation_SetSpace(pActorOld->TESObjectREFR_GetSpace());
        CombatFind::CombatPos kSpotPosTmp = *pFinalSpot->FUN_006815c0();
        if (kSpotPosTmp.FUN_006815c0()->HasEqualComponents(&CombatFind::DAT_011f426c) || CombatState_CheckMovement_009a02a0((::CombatPos*)&kSpotPosTmp, 1, bFlag))
        {
            float fDistance = 0.0f;
            if (CombatFind::DAT_011a5650[aiType].bMeasure)
            {
                CombatFind::CombatPos kActorPos = pActorOld->TESObjectREFR_GetWorldLocation();
                fDistance = CombatFind::CombatAction_GetMovementCost((*(CombatController**)((char*)this + 0x1c4)), &kActorPos, &kSpotPosTmp);
            }
            pLocationsRes->SetEntry(aiType, pFinalSpot, fDistance);
            if (pSearch->iCount)
                pLocationsRes->CombatPlannerData_SetCombatCoverLocation(aiType, pSearch);
            else
                delete pSearch;
            return true;
        }
    }
    delete pFinalSpot;
    delete pSearch;
    pLocationsRes->SetEntry(aiType, 0, CombatFind::DAT_0108df70);
    return false;
}

namespace fnv_0097ee90 {

using ::SettingT;

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting412;

class CTSHelper
{
  public:
    float GetElapsedTime();
};



// Returns true when ((fnv_0097ee90::CTSHelper*)((char*)this + 0x94))->GetElapsedTime() is less than the value of originalRuntimeFloatSetting412.
// @fnv 0x0097ee90
}  // namespace fnv_0097ee90

// src: XBOX_PDB 0x0097ee90
bool CombatState::GetHasBufferedDetection_0097ee90()
{
    using namespace fnv_0097ee90;
    return (double)((fnv_0097ee90::CTSHelper*)((char*)this + 0x94))->GetElapsedTime() < *originalRuntimeFloatSetting412.Float();
}


namespace fnv_0099d030 {
using ::SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting401;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting402;

class CalendarDays
{
  public:
    bool TryUseCoverItem(void* unk68, void* unk14, ::CombatController* m, float f, void* unk70, int one, bool unk75);
};

extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;

class GlobalObject_0045d260
{
  public:
    bool IsInCombat();
};
extern GlobalObject_0045d260 g_011f1a63;

}  // namespace fnv_0099d030

class Arg0Class
{
  public:
    int unk_00, unk_04, unk_08, unk_0c, unk_10, unk_14, unk_18, unk_1c, unk_20, unk_24, unk_28, unk_2c;
    int unk30;
};

class Arg1Class
{
  public:
    int unk00;
    int unk04;
    int unk08, unk0c, unk10;
    int unk14;
    int unk_18, unk_1c, unk_20, unk_24, unk_28, unk_2c, unk_30, unk_34, unk_38, unk_3c, unk_40, unk_44, unk_48, unk_4c,
        unk_50, unk_54, unk_58, unk_5c, unk_60, unk_64;
    void* unk68;
    int unk6c;
    int unk70;
    char unk74;
    bool unk75;
};



class Arg2Class : public FUN_0099b8b0_shell
{
};

namespace fnv_0099d030 {
bool FindCombatPosition(PathingRequest*, float, int);

}  // namespace fnv_0099d030


// Attempts to use a cover item, then builds a PathingRequest and calls FindCombatPosition to locate a combat position for the actor.
// @fnv 0x0099d030
// src: XBOX_PDB 0x0099d030
bool CombatState::FindBestAdvanceLocation(Arg0Class* a0, Arg1Class* a1, Arg2Class* a2, int a3, const NiPoint3& a4, float a5,
                                    void* a6)
{
    using namespace fnv_0099d030;
    float fTmp = 1024.0f;
    float f2 = 2048.0f;
    int i1_2 = 200;
    Actor* actor = (Actor*)(*(CombatController**)((char*)this + 0x1c4))->GetFieldBC();
    int i4 = (int)(*(CombatController**)((char*)this + 0x1c4))->CombatController_GetTarget();
    float val4 = (a5 != 0.0) ? a5 : 256.0f;
    if (a3 == 6)
    {
        val4 = originalRuntimeFloatSetting401.Float()[0] +
               ((1.0f - ((ActiveEffect*)(*(CombatController**)((char*)this + 0x1c4))->GetCurrentCombatStyle())->GetFloatAtOffset1C() / 100.0f) *
                (originalRuntimeFloatSetting402.Float()[0] - originalRuntimeFloatSetting401.Float()[0]));
    }
    a0->unk30 = 0;
    if (a1->unk68 != 0 && a3 == a1->unk04)
    {
        if (((CalendarDays*)fnv_0099d030::BGSSaveLoadGlobalDataWorldspacePtr->NiAVObject_GetParent())
                ->TryUseCoverItem(a1->unk68, &a1->unk14, (*(CombatController**)((char*)this + 0x1c4)), actor->FUN_008be1b0(), &a1->unk70, 1,
                                  a1->unk75))
        {
            return true;
        }
    }
    g_011f1a63.IsInCombat();
    CoveredMoveRequestStorage req2;
    this->BuildCoveredMoveRequest((::PathingRequest*)&req2);
    PathingLocation loc1(actor);
    ((::PathingRequest*)&req2)->SetOrigin(&loc1);
    PathingLocation loc2(a4, actor);
    ((::PathingRequest*)&req2)->SetDestination(&loc2);
    ((::PathingRequest*)&req2)->PathingRequestCoveredMove_SetCombatCoverSearchInfo((int)a0);
    ((::PathingRequest*)&req2)->PathingRequestCoveredMove_SetCombatCoverLocation((::Arg1Class*)a1);
    ((::PathingRequest*)&req2)->FUN_006d61e0(a6);
    ((::PathingRequest*)&req2)->FUN_00705b10(a3);
    bool retVal7 = FindCombatPosition((::PathingRequest*)&req2, val4, 0);
    if (retVal7)
    {
        a2->CombatLocation_SetPoint((int)((::PathingRequest*)&req2)->PathingRequestCoveredMove_GetCoverLocation(), 0);
    }
    ((::PathingRequest*)&req2)->PathingRequestCoveredMove_ClearCombatCoverData();
    g_011f1a63.IsInCombat();
    return retVal7;
}


namespace fnv_006d3150 {

extern NiPoint3 _NiPoint3_ZERO;

struct FUN_006d3200
{
    char pad[0x54];
    FUN_006d3200();
    ~FUN_006d3200();
};

struct FUN_006d3280_s
{
    FUN_006d3280_s* ClearFlags();
};

struct FUN_006d3150
{
    char byte0;
    char byte1;
    char byte2;
    char pad3;
    int dword4;
    NiPoint3 point8;
    FUN_006d3200 member14;
    int dword68;
    int dword6c;
    FUN_006d3280_s member70;

    FUN_006d3150();
};

// Initializes the listed fields, constructs member14, and calls ClearFlags on member70.
// @fnv 0x006d3150
FUN_006d3150::FUN_006d3150()
    : byte0(0), byte1(0), byte2(0), dword4(0), point8(_NiPoint3_ZERO), member14(), dword68(0), dword6c(-1)
{
    member70.ClearFlags();
}
}  // namespace fnv_006d3150

namespace fnv_00997600 {
extern "C" void* __cdecl memset(void*, int, size_t);

const float kFltMax = 3.402823466e+38F;

extern NiPoint3 g_zeroPt3;

extern Setting g_set804;
extern Setting g_set7ec;
extern Setting g_setdcc;

float ClampMin(float a, float b);

struct A24
{
    int unk0, unk4, unk8, unkC;
    A24();
    ~A24();
};
struct FloatW
{
    float f;
    FloatW(float v);
};
struct P2
{
    float x, y;
    P2();
    void Set(float v);
};
struct W4
{
    int v;
    W4();
};
struct B3C
{
    int unk[15];
    B3C();
    ~B3C();
};
struct C10
{
    int unk0, unk4, unk8, unkC;
    C10();
    ~C10();
};
struct D10
{
    int unk0, unk4, unk8, unkC;
    D10();
    ~D10();
};
struct E4
{
    int v;
    E4(int a);
    ~E4();
};

struct FUN_00997600
{
    char b00;
    int unk04;
    float f08;
    int unk0C, unk10, unk14, unk18, unk1C, unk20;
    A24 a24;
    int unk34;
    int unk38;
    int unk3C, unk40, unk44, unk48, unk4C, unk50, unk54;
    float f58, f5C, f60, f64, f68;
    int unk6C;
    char b70, b71, b72, b73, b74, b75, b76, b77;
    int unk78;
    int unk7C;
    float f80;
    NiPoint3 p84;
    int unk90;
    FloatW w94, w98, w9C, wA0, wA4;
    P2 pA8, pB0, pB8;
    W4 wC0;
    int unkC4;
    char bC8, bC9;
    float fCC;
    float fD0, fD4;
    char bD8;
    int unkDC;
    FloatW wE0;
    int unkE4;
    int unkE8;
    B3C bEC;
    B3C b128;
    C10 c164;
    D10 d174;
    W4 w184;
    char b188;
    int unk18C;
    int unk190, unk194, unk198, unk19C, unk1A0;
    int unk1A4, unk1A8;
    P2 arr1AC[2];
    int unk1BC;
    int unk1C0;
    int unk1C4;
    bool b1C8;
    P2 p1CC, p1D4, p1DC, p1E4, p1EC, p1F4, p1FC, p204, p20C, p214, p21C;
    E4 e224;
    int unk228;

    FUN_00997600(int a, int b);
};

// Initializes selected fields, stores a in unk1C4, sets p20C from g_set804, and computes fCC from g_setdcc and g_set7ec.
// @fnv 0x00997600
FUN_00997600::FUN_00997600(int aiUnk, int aiUnk2)
    : b00(0), unk04(0), f08(100.0f), unk34(0), unk38(0), f58(0.0f), f5C(0.0f), f60(0.0f), f64(0.0f), f68(0.0f),
      unk6C(-1), b70(0), b71(0), b72(0), b73(-1), b74(0), b75(0), b76(0), b77(0), unk78(0), unk7C(3), f80(0.0f),
      p84(g_zeroPt3), unk90(0), w94(-kFltMax), w98(-kFltMax), w9C(-kFltMax), wA0(-kFltMax), wA4(-kFltMax), unkC4(0),
      bC8(0), bC9(0), fD0(-1.0f), fD4(-1.0f), bD8(0), unkDC(0), wE0(-kFltMax), unkE4(0), unkE8(0), b188(-1), unk18C(0),
      unk1BC(0), unk1C0(0), unk1C4(aiUnk), b1C8(true), e224(0), unk228(-1)
{
    memset(&unk0C, 0, 0x18);
    memset(&unk3C, 0, 0x1c);
    memset(&unk190, 0, 0x14);
    memset(&unk1A4, 0, 8);
    p20C.Set(ClampMin(0.0f, *g_set804.GetFloat()));
    fCC = ClampMin(*g_setdcc.GetFloat(), *g_set7ec.GetFloat());
}
}  // namespace fnv_00997600

#include <string.h>

struct FUN_0099a2a0_s
{
    int a[3];
    char data[0x18];
    GlobalObject_00869f00 g;
    void CombatState_DeleteInventoryData();
};
// Zeroes the data buffer and clears the global object g.
// @fnv 0x0099a2a0
// src: XBOX_PDB 0x0099a2a0
void FUN_0099a2a0_s::CombatState_DeleteInventoryData()
{
    memset(data, 0, 0x18);
    g.Clear(false);
}

struct RefCalls_9a2a30
{
    void TESObjectREFR_SetTargeted(bool);
};

TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
struct RefSlot
{
    TESObjectREFR* ref;
};
struct MemberC4
{
    void CombatState_LocationTarget_InitLoadGameBGS(BGSLoadFormBuffer*);
};
struct Member18C
{
    void ResolveRef(BGSLoadFormBuffer*);
};
float __cdecl BSMAX_00404010(float, float);
struct HostA
{
    int unk000;
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
    float values[7];
    int unk058;
    int unk05c;
    float maximum;
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
    MemberC4* memberC4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
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
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    Member18C* member18C;
    RefSlot* slots[5];
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    Actor* actor;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    unsigned int index;
    void SetMode(unsigned int);
    void CombatState_InitLoadGameBGS(BGSLoadFormBuffer*);
};
// Calls buffer handlers, re-resolves stored references, optionally processes index, and updates maximum from values.
// @fnv 0x009a2a30
// src: COMMUNITY 0x009a2a30
void HostA::CombatState_InitLoadGameBGS(BGSLoadFormBuffer* buffer)
{
    if (memberC4)
        memberC4->CombatState_LocationTarget_InitLoadGameBGS(buffer);
    for (unsigned int i = 0; i < 5; i++)
    {
        if (slots[i])
        {
            slots[i]->ref = slots[i]->ref ? dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID((unsigned int)slots[i]->ref)) : 0;
            if (slots[i]->ref)
                ((RefCalls_9a2a30*)slots[i]->ref)->TESObjectREFR_SetTargeted(true);
        }
    }
    if (member18C)
        member18C->ResolveRef(buffer);
    actor = actor ? dynamic_cast<Actor*>(TESForm_GetFormByNumericID((unsigned int)actor)) : 0;
    if (index != -1)
        SetMode(index);
    for (unsigned int j = 0; j < 7; j++)
        maximum = BSMAX_00404010(maximum, values[j]);
}

