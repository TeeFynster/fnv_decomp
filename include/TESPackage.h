#pragma once

#include "TESForm.h"
#include "PTYPE.h"
#include "PackageTime.h"
#include "PackageAction.h"
#include "NiPoint3.h"
#include "PerkEntryConditionSet.h"

class Actor;
class BGSLoadFormBuffer;
class DurationData;
class LocationDescriptor;
class MobileObject;
class NiNode;
class PackageTargetRecord;
class PackageLocation206;
class PackageTarget206;
class PkgLocation;
class PkgTarget;
class Schedule206;
class PkgData;
class TESObjectCELL;
class TESObjectREFR;
class TESPackageData;
class TESPatrolPackageData;
class TESUseWeaponPackageData;
class TESWorldSpace;
enum PACKAGE_PROCEDURE_TYPE;
enum PACKAGE_TYPE;
enum PTYPE;

class TESPackage : public TESForm
{
public:
    typedef ::PackageTime PackageTime;
    typedef ::PackageAction PackageAction;

    enum
    {
        kPackageFlag_WeaponsUnequipped = 1 << 21
    };


    struct Data
    { // TESPackage::Data is a distinct nested package flags/type/behavior record, not the global ::Data.
        unsigned int uiPackageFlags;
        signed char eType;
        unsigned short usFOBehaviorFlags;
        unsigned short usPackageSpecificFlags;
    };

    union ObjectType
    {
        TESForm* form;
        TESObjectREFR* refr;
        unsigned long objectCode;
    };

    struct LocationData
    {
        unsigned char locationType;
        unsigned char pad[3];
        unsigned long radius;
        ObjectType object;
    };

    struct TargetData
    {
        unsigned char targetType;
        unsigned char pad[3];
        ObjectType target;
        unsigned long count;
        float unk0C;
    };

    TESPackage();
    virtual ~TESPackage();

    // Primary vtable slots 78 through 87.
    virtual bool IsPackageValidForActor(Actor* actor);
    virtual bool IsActorWithinPackageRadius(Actor* actor, bool ignoreDistance,
                                           float extraRadius, bool inFurniture);
    virtual bool IsActorNearOwnerPackageLocation(Actor* actor, Actor* packageOwner,
                                                bool ignoreDistance, float extraRadius,
                                                bool inFurniture);
    virtual bool IsActorInPackageRadius(Actor* actor, int extraRadius);
    virtual bool IsActorNearPackageTarget(Actor* actor, int extraRadius);
    virtual unsigned short GetSaveSize();
    virtual unsigned short SaveGameTESAlt();
    virtual unsigned short LoadGameTESAlt();
    virtual void InitLoadGameTES();
    virtual bool IsPackageDoneForActor(Actor* actor = 0);

    unsigned long procedureArrayIndex;
    unsigned long packageFlags;
    unsigned char type;
    unsigned char pad021[1];
    unsigned short behaviorFlags;
    unsigned long specificFlags;
    TESPackageData* packageData;
    LocationData* location;
    TargetData* target;
    unsigned long unk034;
    PackageTime time;
    unsigned long unk040;
    unsigned long unk044;
    unsigned long unk048;
    PackageAction onBeginAction;
    PackageAction onEndAction;
    PackageAction onChangeAction;
    unsigned long unk07C;

    Script* GetNextScript();
    TESObjectREFR* GetResolvedTargetReference(MobileObject* actor);
    void SetWaiting(bool waiting);
    float GetPackageLocationRadius(MobileObject* actor, bool arg);
    float GetActorMovementSpeed(MobileObject* actor, bool arg);
    void AssignTargetReference(TESObjectREFR* reference, bool arg);
    LocationDescriptor* HasSecondLocation();
    TESObjectCELL* GetPackageSecondLocationCell(MobileObject* actor);
    const NiPoint3 GetPackageSecondLocationPosition(MobileObject* actor);
    bool GetPackageSearchRadius(MobileObject* actor, float& radius);
    float GetPackageResult(Actor* actor, bool arg);
    bool IsFlag10Set();
    bool IsFlag80Set();
    bool HasEssentialStatus();
    PerkEntryConditionSet* GetConditions();
    int GetPackType();
    PACKAGE_TYPE GetPackType() const;
    int GetProcedureType();
    bool IsMustReachLocation();
    bool IsMustComplete();
    bool UsesPackageAnimation();
    bool IsPackageBlockingGreeting();
    bool HasTargetForActor(MobileObject* actor);
    int GetPackageTargetType();
    PackageTargetRecord* GetTarget();
    LocationDescriptor* GetLocation();
    LocationDescriptor* GetPackageSecondLocation();
    LocationDescriptor* FUN_0055b980();               // 0x0055b980: returns location (+0x2c)
    TESUseWeaponPackageData* GetWeaponUseData();      // 0x006758f0: packageData when GetPackType() == 0x10
    bool GetAlwaysSneak();                            // 0x0067a4f0: packageFlags (+0x1c) & 0x20000
    TESObjectREFR* GetTargetForActor(Actor* actor, bool arg);
    TESWorldSpace* GetPackageWorldSpace(MobileObject* actor);
    TESObjectCELL* GetPackageLocationCell(MobileObject* actor);
    const NiPoint3 GetPackageLocationPosition(MobileObject* actor);
    void SetFlag10000();
    bool IsNotFlag8000000();
    bool IsFlag4Clear();
    NiNode* GetParent();
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    void SetPackageType(int type);
    void SetProcedureType(int type);
    void SetProcedureType(PACKAGE_PROCEDURE_TYPE type);
    void SetMustReachLocation(bool enabled);
    void SetMustComplete(bool enabled);
    void SetTargetFromReference(TESObjectREFR* reference);
    void AddRef();
    int Release();
    unsigned int GetRefCount();
    void RemoveRef(TESObjectREFR* reference);
    bool GetForceUnequipWeapon() const;
    int GetPrevPath();
    const TESPatrolPackageData* GetPackagePatrolData();
    PkgData* GetData();
    float GetPackageFloatValue();
    bool IsFlag10000Set();
    void CopyScheduleFrom(DurationData* schedule);
    void ResetFormData();
    void DestroyPackage();
    void SetTrespassEnabled(bool enabled);
    bool IsScheduledForDay(bool arg);
    int CompareTo(DurationData* schedule);
    bool RunPackage();
    void SetPackageFlag(bool enabled);
    void SetExtraValue(float value);
    void SetFlag20(bool enabled);
    void SetFlag100(bool enabled);
    void SetFlag4000(bool enabled);
    bool HasFlag400000();
    void SetFlag400000(bool enabled);

    unsigned int FUN_00441110();
    int FUN_0041ca90();
    DurationData* FUN_0041d8a0();
    bool FUN_00441b00();
    bool FUN_005394a0();
    TESIdleForm* FUN_00546930();
    bool FUN_00670ed0();
    bool FUN_00670f40();
    bool FUN_00670f60();
    void FUN_00671a20(bool enabled);
    void FUN_00671a70(bool enabled);
    void FUN_00671ad0(bool enabled);
    void FUN_00671b30(bool enabled);
    void FUN_00671b90(bool enabled);
    void FUN_00671bf0(bool enabled);
    void FUN_00671c50(bool enabled);
    void FUN_00671d30(LocationDescriptor* location);
    void FUN_00671d30(PackageTarget206* target);
    void FUN_00671e10(PackageTarget206* target);
    bool FUN_006727b0();
    void FUN_00672aa0(char arg);
    Schedule206* FUN_00672d10();
    void FUN_00672fc0(PackageTargetRecord* target);
    void FUN_00672fc0(PackageLocation206* location);
    bool FUN_00673890();
    bool FUN_00674d20();
    unsigned int FUN_006758a0(MobileObject* actor);
    TESObjectREFR* FUN_00676140(MobileObject* actor);
    unsigned int FUN_00676280(MobileObject* actor);
    bool FUN_00677760(Actor* actor);
    bool FUN_00678610();
    bool FUN_0067a480();
    void FUN_0067a1b0(TESPackage* package);
    void FUN_0067a1b0(void* context);
    bool FUN_0067efd0();
    bool FUN_0067a460();                              // 0x0067a460: package flags (+0x1c) & 0x800000
    bool FUN_008e9620();                              // 0x008e9620 (HighProcess::ProcessActivate 0x008e9640)
    const NiPoint3 FUN_00675360(MobileObject* actor); // 0x00675360
    void* FUN_00674fd0(MobileObject* actor);          // 0x00674fd0
    bool FUN_008eea80();                              // 0x008eea80
    bool IsFlag28Clear();                             // 0x0067a7e0
    bool IsFlagBitSet();                              // 0x008840d0: package flags (+0x1c) & 1
    int FUN_004036b0();                               // 0x004036b0: returns +0xb8
    TESPatrolPackageData* GetPatrolData();            // 0x00675950
    bool IsTargetInRange(Actor* actor, float radius); // 0x00677570
    PackageTargetRecord* FUN_00671d10();             // 0x00671d10
    bool FUN_00674d40();                              // 0x00674d40
    unsigned int FUN_00672930();                      // 0x00672930
    NiPoint3 FUN_00675de0(Actor* actor);              // 0x00675de0
    void FUN_00675de0(NiPoint3& out, Actor* actor);   // 0x00675de0: the same call written with its return slot
    void* FUN_00675c20(Actor* actor);                 // 0x00675c20
    int FUN_00675a50(Actor* actor, float value, int flags); // 0x00675a50
    bool FUN_008a6290(); // 0x008a6290
    TESObjectREFR* FUN_004030b0(); // 0x004030b0
    float FUN_006787e0(Actor*, int, int); // 0x006787e0, explicit folded arguments
    bool FUN_008e30e0(); // 0x008e30e0
    bool FUN_008e3100(); // 0x008e3100
    bool FUN_008e3120(); // 0x008e3120
    LocationDescriptor* FUN_00672dd0(); // 0x00672dd0
    void* FUN_006751a0(MobileObject*); // 0x006751a0
    void* FUN_00675a50(Actor*); // 0x00675a50: the original uses folded stack arguments
    float FUN_00678670(MobileObject*, bool); // 0x00678670
    bool FUN_00672710(); // 0x00672710
    TESPackage* FUN_00672760(); // 0x00672760
    bool FUN_00672800(); // 0x00672800
    template <class Point> Point FUN_00675de0(Actor*); // 0x00675de0: aggregate result ABI
    float FUN_00678670(Actor*); // 0x00678670: folded stack arguments
    bool FUN_008840f0();
    void FUN_00826b40(bool); // 0x00826b40
    void FUN_00826b90(bool); // 0x00826b90
    int FUN_006733e0(); // 0x006733e0
    void FUN_00673400(int); // 0x00673400
    bool FUN_008a67d0();
    bool FUN_008b1ff0();
    bool FUN_008dade0();
    TESTopic* FUN_00903bb0();
    Script* FUN_00903bd0();
    TESTopic* FUN_00903cd0();
    TESIdleForm* FUN_00903de0();
    TESTopic* FUN_00903e00();
    Script* FUN_00903e20();
    void F671d30(PkgLocation* location);
    void F672fc0(PkgTarget* target);
    void F984f60(int arg);

    static TESPackage* CreatePackageForType(::PTYPE type);
    static TESPackage* CreatePackageForType(int type);
    static float __cdecl GetPackageDefaultFloat();
};
