#pragma once

#include "MobileObject.h"
#include "MagicTarget.h"
#include "NiTransform.h"
#include "NiPoint3.h"
#include "NiPoint3.h"
#include "NiPoint2.h"
#include "NiAVObject.h"
#include "BSSoundHandle.h"
#include "NiPoint3.h"

class AcObj;
class ActorCause;
class Anim;
class Controller;
class Link;
class Node;
class ParentNode;
class ProjectileData;
class S150;
class Sound;
template <class T> struct Ptr;
class BGSProjectile;
class InventoryStackRecord;
class NiLight;
class NiRefObject;
class PickTarget;
class ProjectileSupportData;
class TESObjectWEAP;
class NiPoint3;
class hkpCollidable;

class Projectile : public MobileObject
{
public:
    enum Type
    {
        UNKNOWN,
        BEAM,
        FLAME,
        GRENADE,
        MISSILE,
        CONTINUOUS_BEAM
    };

    struct ImpactData;

    class ImpactList : public BSSimpleList<ImpactData*>
    {
    public:
        ImpactList();
        ~ImpactList();
    };

    class MovementDirection : public NiPoint3
    {
    public:
        MovementDirection();
        using NiPoint3::operator=;
    };

    virtual ~Projectile();
    virtual unsigned int GetProjectileType();
    virtual void Do3DLoaded();
    virtual void HandleTracer();
    virtual void UpdateProjectile(float timeDelta);
    virtual bool ProcessImpact();
    virtual bool IsProximityTriggered();
    virtual void UpdateProjectileState();
    virtual bool OnActorHit(Actor* actor, bool silent);
    virtual bool GetCharacterSex() const;
    virtual bool IsProximityDetonationTriggered();
    virtual bool OnCollision(Actor* actor, const NiPoint3& contactPoint,
                             const NiPoint3& contactNormal, hkpCollidable* collidable,
                             unsigned int collisionShapeKey, unsigned int hitMaterial);

    ImpactList kImpacts;
    union { bool m_bHasImpactData; unsigned char byte90; int unk90; };
    NiTransform m_kImpactTransform;
    union { unsigned int iFlags; unsigned int wordC8; Link* head; };
    union { float m_fAlpha; float floatCC; unsigned int id; };
    union { float TransformFlagFloatData; float floatD0; };
    union { float fImpulseRadiusSquared; float floatD4; float start; };
    union { float m_fFirstFloatValue; float floatD8; };
    union { float afDamageAmount; float floatDC; };
    union { float fAlpha; float floatE0; };
    union { float AlphaFloatParameters; float floatE4; };
    union { float AlphaParameterSet; float floatE8; };
    union { float WeaponAlphaParameters; float floatEC; };
    union { float WeaponReferenceParameterData; float floatF0; };
    union { float m_fFourthRecordValue; float floatF4; };
    union { TESObjectWEAP* pSourceWeapon; TESObjectWEAP* m_pFiringWeapon; unsigned int wordF8; };
    union { TESObjectREFR* WeaponHitData; unsigned int wordFC; };
    union { TESObjectREFR* m_pMagicTarget; unsigned int word100; };
    MovementDirection kMovementDirection;
    union { float fDistanceMoveds; float float110; float m_fImpactForce; };
    NiPointer<NiLight> m_pMenuLight;
    union { bool m_bFlagAfterLight; unsigned char byte118; };
    unsigned char unk119[3];
    NiPointer<NiRefObject> m_pExplosionEffect;
    NiPointer<ActorCause> m_pActorCause;
    union { float m_fLifetime; float float124; };
    BSSoundHandle kSound;
    BSSoundHandle kCountdownSound;
    union { ProjectileSupportData* pProjectileTarget; ProjectileSupportData* pTarget; unsigned int word140; };
    union { InventoryStackRecord* pRockItLauncherEntry; InventoryStackRecord* m_pTargetData; unsigned int word144; };
    union { bool m_bHasTarget; unsigned char byte148; };
    unsigned char unk149[3];
    union { float fSoundDistance; float float14C; float ObjectPointerFlagFloatData; };


    __declspec(property(get=GetLegacy_m_kProjectileImpactList)) BSSimpleList<ImpactData*>& m_kProjectileImpactList;
    __forceinline BSSimpleList<ImpactData*>& GetLegacy_m_kProjectileImpactList()
    {
        return kImpacts;
    }
    __declspec(property(get=GetLegacy_list)) BSSimpleList<InventoryStackRecord*>& list;
    __forceinline BSSimpleList<InventoryStackRecord*>& GetLegacy_list()
    {
        return *reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(&kImpacts);
    }
    __declspec(property(get=GetLegacy_speed)) float& speed;
    __forceinline float& GetLegacy_speed()
    {
        return *reinterpret_cast<float*>(&kImpacts);
    }
    __declspec(property(get=GetLegacy_distance)) float& distance;
    __forceinline float& GetLegacy_distance()
    {
        return *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(&kImpacts) + 4);
    }
    __declspec(property(get=GetLegacy_animation)) Ptr<Anim>& animation;
    __forceinline Ptr<Anim>& GetLegacy_animation()
    {
        return *reinterpret_cast<Ptr<Anim>*>(reinterpret_cast<unsigned char*>(&m_kImpactTransform) + 0x14);
    }
    __declspec(property(get=GetLegacy_m_ac)) AcObj*& m_ac;
    __forceinline AcObj*& GetLegacy_m_ac()
    {
        return *reinterpret_cast<AcObj**>(reinterpret_cast<unsigned char*>(&m_kImpactTransform) + 0x18);
    }
    __declspec(property(get=GetLegacy_mode)) int& mode;
    __forceinline int& GetLegacy_mode()
    {
        return *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(&m_kImpactTransform) + 0x18);
    }
    __declspec(property(get=GetLegacy_links)) Link*& links;
    __forceinline Link*& GetLegacy_links()
    {
        return *reinterpret_cast<Link**>(reinterpret_cast<unsigned char*>(&m_kImpactTransform) + 0x1c);
    }
    __declspec(property(get=GetLegacy_node)) Ptr<Node>& node;
    __forceinline Ptr<Node>& GetLegacy_node()
    {
        return *reinterpret_cast<Ptr<Node>*>(reinterpret_cast<unsigned char*>(&m_kImpactTransform) + 0x20);
    }
    __declspec(property(get=GetLegacy_target)) Ptr<ParentNode>& target;
    __forceinline Ptr<ParentNode>& GetLegacy_target()
    {
        return *reinterpret_cast<Ptr<ParentNode>*>(reinterpret_cast<unsigned char*>(&m_kImpactTransform) + 0x28);
    }
    __declspec(property(get=GetLegacy_effect)) Ptr<Node>& effect;
    __forceinline Ptr<Node>& GetLegacy_effect()
    {
        return *reinterpret_cast<Ptr<Node>*>(reinterpret_cast<unsigned char*>(&m_kImpactTransform) + 0x2c);
    }
    __declspec(property(get=GetLegacy_sound)) Sound& sound;
    __forceinline Sound& GetLegacy_sound()
    {
        return *reinterpret_cast<Sound*>(reinterpret_cast<unsigned char*>(&iFlags) + 0x0);
    }
    __declspec(property(get=GetLegacy_transform)) NiTransform& transform;
    __forceinline NiTransform& GetLegacy_transform()
    {
        return *reinterpret_cast<NiTransform*>(reinterpret_cast<unsigned char*>(&m_kImpactTransform) + 0x0);
    }
    __declspec(property(get=GetLegacy_m_kImpactPoint)) NiPoint3& m_kImpactPoint;
    __forceinline NiPoint3& GetLegacy_m_kImpactPoint()
    {
        return *reinterpret_cast<NiPoint3*>(reinterpret_cast<unsigned char*>(&kMovementDirection) + 0x0);
    }
    __declspec(property(get=GetLegacy_position)) NiPoint2& position;
    __forceinline NiPoint2& GetLegacy_position()
    {
        return *reinterpret_cast<NiPoint2*>(reinterpret_cast<unsigned char*>(&kMovementDirection) + 0x0);
    }
    __declspec(property(get=GetLegacy_positionZ)) float& positionZ;
    __forceinline float& GetLegacy_positionZ()
    {
        return *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(&kMovementDirection) + 0x8);
    }
    __declspec(property(get=GetLegacy_visualA)) NiPointer<NiAVObject>& visualA;
    __forceinline NiPointer<NiAVObject>& GetLegacy_visualA()
    {
        return *reinterpret_cast<NiPointer<NiAVObject>*>(reinterpret_cast<unsigned char*>(&m_pMenuLight) + 0x0);
    }
    __declspec(property(get=GetLegacy_visualB)) NiPointer<NiAVObject>& visualB;
    __forceinline NiPointer<NiAVObject>& GetLegacy_visualB()
    {
        return *reinterpret_cast<NiPointer<NiAVObject>*>(reinterpret_cast<unsigned char*>(&m_pExplosionEffect) + 0x0);
    }
    __declspec(property(get=GetLegacy_cause)) NiPointer<ActorCause>& cause;
    __forceinline NiPointer<ActorCause>& GetLegacy_cause()
    {
        return *reinterpret_cast<NiPointer<ActorCause>*>(reinterpret_cast<unsigned char*>(&m_pActorCause) + 0x0);
    }
    __declspec(property(get=GetLegacy_m_actorCause)) NiPointer<ActorCause>& m_actorCause;
    __forceinline NiPointer<ActorCause>& GetLegacy_m_actorCause()
    {
        return *reinterpret_cast<NiPointer<ActorCause>*>(reinterpret_cast<unsigned char*>(&m_pActorCause) + 0x0);
    }
    __declspec(property(get=GetLegacy_soundA)) BSSoundHandle& soundA;
    __forceinline BSSoundHandle& GetLegacy_soundA()
    {
        return *reinterpret_cast<BSSoundHandle*>(reinterpret_cast<unsigned char*>(&kSound) + 0x0);
    }
    __declspec(property(get=GetLegacy_m_kFirstValue)) BSSoundHandle& m_kFirstValue;
    __forceinline BSSoundHandle& GetLegacy_m_kFirstValue()
    {
        return *reinterpret_cast<BSSoundHandle*>(reinterpret_cast<unsigned char*>(&kSound) + 0x0);
    }
    __declspec(property(get=GetLegacy_soundB)) BSSoundHandle& soundB;
    __forceinline BSSoundHandle& GetLegacy_soundB()
    {
        return *reinterpret_cast<BSSoundHandle*>(reinterpret_cast<unsigned char*>(&kCountdownSound) + 0x0);
    }
    __declspec(property(get=GetLegacy_m_kSecondValue)) BSSoundHandle& m_kSecondValue;
    __forceinline BSSoundHandle& GetLegacy_m_kSecondValue()
    {
        return *reinterpret_cast<BSSoundHandle*>(reinterpret_cast<unsigned char*>(&kCountdownSound) + 0x0);
    }

    Projectile(bool bTempRef);
    Projectile(int a, int b, int c, NiPoint3 position, float magnitude, float duration);
    Type GetProjectileType() const;
    void Initialize();
    void ResetProjectile();
    bool ProcessProjectile();
    bool IsProjectileActive() const;
    void InitLoadGame(BGSLoadFormBuffer* buffer);
    void Primary();
    void Secondary();
    bool Load(TESFile* file);
    BGSProjectile* GetProjectileBase() const;
    const char* GetFullName();
    void SetByteAtOffset1B0(char c);
    void InitRagdollController(void* p0, unsigned char b1, unsigned char b2, unsigned char b3);
    void SetFormType(int type);
    float GetFirstLightParameter();
    float GetField90Float();
    float GetUnka4();
    void UpdateMotion(float delta);
    void DeleteAllNodes();
    void LoadFromStream(int, int);
    void Explode();
    PickTarget* GetPick();
    void GetLaunch(NiPoint3* pos, NiPoint3* dir, bool b);

    bool FUN_00440d80() const;
    int GetFormEditorIDLength();
    S150 TESObjectREFR_MultipleMatrixByRace(const S150& value);
    Controller* FUN_009306d0();
    void FUN_00931ed0(void* value);
    void Actor_RegisterGrabIKNote();
    MobileObject* ArrowProjectile_GetAttachedRef();
    void ArrowProjectile_ClearAttachedRef();
    void EffectSetting_SetAreaSound(int value);
    void SetActorCause_00978ed0(ActorCause* cause);
    ProjectileData* FUN_004181e0();
    unsigned int Sky_GetMode();
    void RevertBGS_009c58e0(BGSLoadFormBuffer* buffer);
    void __thiscall Projectile_SetSpeedMult(float value);
    void LoadGame_0081e980(int, int);
    void MagicBoltProjectile_UpdateBranch(float, Link*);
    void MagicBoltProjectile_SetState(int);
    void TESForm_LoadGameDataOLD(void*, unsigned int);
    void TESForm_LoadNumericID(void*, unsigned int);
    void PlayerCharacter_UpdateMouseSpring(int value);
    void FUN_009bc470();
    int BGSProjectile_GetExplosion();

    void Mark(int);
    Node* Root();
    NiPoint3& Position();
    using MobileObject::Move;
    void Relocate(NiPoint3, int, int, int);
    bool Active();
    void Reset();
};
