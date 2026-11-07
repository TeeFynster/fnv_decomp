
// src/fallout/ai/highprocess_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (FleePackage, TESPackage). The skeleton of src/fallout/ai/highprocess.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "../../../include/Actor.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/FleePackage.h"
#include "../../../include/Setting.h"
#include "../../../include/NiPoint3.h"

namespace PackagePathing {
struct List;
struct Cell
{
    bool FUN_00425fd0();
};
struct Package
{
    virtual void PackageTypeAnchor();
    int FUN_0041ca90();
    void SpectatorPackage_CopyThreatInfoList(List*);
    bool SpectatorPackage_IsComplete();
    NiPoint3 SpectatorPackage_GetEventCenter();
    void SpectatorPackage_Update(Actor*);
    void SpectatorPackage_LookAtCombatants(Actor*, int);
    void SpectatorPackage_MakeCombatComment(Actor*, int);
    unsigned int FUN_004fb070();
    void SetWaterForm(unsigned int);
    float BGSProjectile_GetMuzzleFlashDuration();
    int SpectatorPackage_CreateAvoidNodeArray();
    void AddAvoidedRef(void*);
};
struct List
{
    unsigned int unk0, unk4, unk8, unkc;
    List();
    ~List();
    int FUN_0044ddc0();
    void** BSSimpleArray_NiAVObject_1024_GetAt(int);
};
struct Process
{
    bool GetPathCoordinate(NiPoint3*);
};
struct Race
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
    virtual bool Flag();
};
struct Base
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
    Race race;
};
struct Location
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
    Location(const NiPoint3&, Actor*);
    ~Location();
};
struct Request
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    Request();
    ~Request();
    void InitFromActor(Actor*);
    void SetCantOpenDoors(bool);
    void SetPathingLocation(const Location&);
    void PathingRequestHide_SetMinHideDistance(float);
    void FUN_006d3b00(float);
    void FUN_006d61e0(int);
};

struct System
{
    bool Actor_CheckAttackDisarm(Actor*, int);
};
extern System* DAT_011f1958;
extern Setting DAT_011cd814, DAT_011cddb8, DAT_011cd990, DAT_011cdfe4;
struct Timer
{
    unsigned int FUN_00825c00();
};
extern Timer DAT_011f6394;
extern float DAT_01012054, DAT_0101e6ec;
extern double DAT_0102e430, DAT_010240c0;

}

// @fnv 0x008db810
// src: XBOX_PDB 0x008db810
void Actor::HighProcess_ProcessObserveCombat(Actor* actor)
{
    using namespace PackagePathing;
    // The shared hierarchy lacks these two virtual signatures; retain their calling conventions here.
    typedef PackagePathing::Package* (__thiscall *CurrentPackageCall)(Actor*);
    typedef void (__thiscall *StartCall)(Actor*, void*, int, int, int, int, int, float, float);
    PackagePathing::Package* current =
        reinterpret_cast<CurrentPackageCall>((*reinterpret_cast<void***>(this))[0x27c / 4])(this);
    PackagePathing::Package* package = 0;
    if (current && current->FUN_0041ca90() == 24)
        package = current;
    if (!package)
        return;
    if (DAT_011f1958->Actor_CheckAttackDisarm(actor, 0) || actor->GetActorValue(static_cast<ActorValue::Index>(1)) <= 0)
    {
        List targetsSlot0;
        package->SpectatorPackage_CopyThreatInfoList(&targetsSlot0);
        int count = targetsSlot0.FUN_0044ddc0();
        if (count > 0)
        {
            actor->Actor_EndInterruptPackage(0);
            reinterpret_cast<StartCall>((*reinterpret_cast<void***>(actor))[0x410 / 4])(
                actor, *targetsSlot0.BSSimpleArray_NiAVObject_1024_GetAt(0), 1, 1, 1, 0, 0, DAT_01012054, DAT_01012054);
            ::FleePackage* following = dynamic_cast< ::FleePackage*>(reinterpret_cast<TESPackage*>(actor->FUN_009344a0()));
            if (following)
            {
                for (int index = 0; index < count; index++)
                    following->AddAvoidedReference(static_cast< ::Actor*>(*targetsSlot0.BSSimpleArray_NiAVObject_1024_GetAt(index)));
            }
            return;
        }
    }
    if (package->SpectatorPackage_IsComplete())
    {
        actor->Actor_EndInterruptPackage(0);
        return;
    }
    float nearDistanceSlot10 = 0.0f;
    float farDistanceSlot35 = 0.0f;
    NiPoint3 unusedSlot11;
    int flagsSlot15 = 513;
    NiPoint3 pointSlot13 = package->SpectatorPackage_GetEventCenter();
    float distanceSlot14 = actor->GetLightLevelAtPoint(pointSlot13);
    Cell* cell = reinterpret_cast<Cell*>(actor->FUN_008d6f30());
    bool nearSlot19 = false;
    if (cell && cell->FUN_00425fd0())
    {
        nearDistanceSlot10 = *DAT_011cd814.Setting_Float_00403e20();
        farDistanceSlot35 = *DAT_011cddb8.Setting_Float_00403e20();
        if (distanceSlot14 < nearDistanceSlot10)
            nearSlot19 = true;
    }
    else
    {
        nearDistanceSlot10 = *DAT_011cd990.Setting_Float_00403e20();
        farDistanceSlot35 = *DAT_011cdfe4.Setting_Float_00403e20();
        if (distanceSlot14 < farDistanceSlot35)
            nearSlot19 = true;
    }
    package->SpectatorPackage_Update(actor);
    if (actor->FUN_008b3bb0())
    {
        package->SpectatorPackage_LookAtCombatants(actor, 1);
        package->SpectatorPackage_MakeCombatComment(actor, 1);
        unsigned int time = DAT_011f6394.FUN_00825c00();
        if (time > package->FUN_004fb070() + 1500)
        {
            package->SetWaterForm(time);
            NiPoint3 oldSlot17Slot17 = *reinterpret_cast<const NiPoint3*>(static_cast<const Actor*>(actor)->GetPos());
            PackagePathing::Request requestSlot13;
            requestSlot13.InitFromActor(actor);
            if (actor->IsCreature())
                requestSlot13.SetCantOpenDoors(reinterpret_cast<PackagePathing::Base*>(actor->FUN_004181e0())->race.Flag());
            requestSlot13.SetPathingLocation(Location(package->SpectatorPackage_GetEventCenter(), actor));
            requestSlot13.PathingRequestHide_SetMinHideDistance(package->BGSProjectile_GetMuzzleFlashDuration() + DAT_0102e430);
            requestSlot13.FUN_006d3b00(DAT_0101e6ec);
            int mode = package->SpectatorPackage_CreateAvoidNodeArray();
            requestSlot13.FUN_006d61e0(mode);
            if (!actor->Actor_SetPathfindingFlee(reinterpret_cast<PathingRequest*>(&requestSlot13)))
                return;
            if (actor->GetBlocked())
                actor->Actor_SetBlock(0);
            actor->Actor_SetMoveMode(512);
            NiPoint3 targetSlot6Slot10;
            if (reinterpret_cast<PackagePathing::Process*>(actor->m_pActorMover)->GetPathCoordinate(&targetSlot6Slot10))
            {
                float targetDistanceSlot1 = actor->GetLightLevelAtPoint(targetSlot6Slot10);
                if (targetDistanceSlot1 <= DAT_010240c0)
                    flagsSlot15 = 257;
                // 0x008dbcfc: slot 0xD4 on the process (this), BaseProcess::SetActorDetectionState; this unit names the process class Actor
                reinterpret_cast< ::BaseProcess*>(this)->SetActorDetectionState(actor, flagsSlot15, 1);
            }
        }
    }
    else if (actor->IsCharacter())
    {
        package->SpectatorPackage_LookAtCombatants(actor, 1);
        package->SpectatorPackage_MakeCombatComment(actor, 1);
    }
    if (actor->DidPathingFail())
        return;
    if (distanceSlot14 > farDistanceSlot35 * 2.0f)
    {
    }
}

