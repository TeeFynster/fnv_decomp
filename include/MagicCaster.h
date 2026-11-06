#pragma once
#include <stddef.h>

class ActiveEffect;
class Actor;
class EffectItem;
class MagicEffectCollection;
class MagicItem;
class MagicProjectile;
class MagicTarget;
class NiPoint3;
class NiNode;
class SpellItem;
class TESBoundObject;
class TESObjectCELL;
class TESObjectREFR;
class hkpRigidBody;
struct blob12;


class MagicCaster
{
  public:
    enum State
    {
        NO_SPELL = 0,
        AIM = 1,
        CAST = 2,
        RELEASE = 3,
        FIND_TARGETS = 4,
        ERR_SPELL_DISABLED = 5,
        ERR_ALREADY_CASTING = 6,
        ERR_CANNOT_CAST = 7,
    };

    MagicEffectCollection* apTargetLight;
    State eState;

    virtual void CastSpellOnCaster(SpellItem* spell, bool immediate);
    virtual void CastSpellOnSelf(SpellItem* spell, bool immediate);
    virtual void CastSpellAtLocation(SpellItem* spell, bool immediate);
    virtual void CastMagicItem(MagicItem* item, bool arg1, MagicTarget* target, float value, bool arg2);
    virtual void CastSpellAtTarget(SpellItem* spell, MagicTarget* target, bool immediate);
    virtual void CastMagicItemOnObject(MagicItem* item, TESBoundObject* object, bool immediate);
    virtual MagicTarget* GetSpellTarget();
    virtual void UpdateCastState();
    virtual void CompleteCast();
    virtual void SpellCast(MagicItem* item, bool immediate);
    virtual bool CanCast(MagicItem* item, float* value, int* reason, bool flag);
    virtual TESObjectREFR* GetCasterReference();
    virtual NiNode* GetMagicNode();
    virtual MagicItem* GetSelectedMagicItem();
    virtual bool HasActiveEffect(ActiveEffect* effect);
    virtual float GetCasterEffectiveness(bool flag, float value);
    virtual void SetSelectedMagicItem(MagicItem* item);
    virtual MagicTarget* GetCurrentMagicTarget();
    virtual void SetMagicTarget(MagicTarget* target);
    virtual ActiveEffect* CreateActiveEffect(MagicItem* item, EffectItem* effect, TESBoundObject* source);

    MagicCaster();
    void UpdateCaster(float delta);
    bool CastSpell(MagicItem* item, MagicTarget* target, bool immediate);
    void EndAim();
    bool CanCastSpellOnObject(TESBoundObject* object);
    void RemoveCastingArt();
    void LaunchMagicProjectile(MagicItem* item, TESObjectCELL* cell, blob12 position,
                               MagicProjectile* projectile, TESObjectREFR* target, bool flag, float arg1, float arg2);
    void LaunchMagicProjectile(MagicItem* item, MagicProjectile* projectile, TESObjectREFR* target,
                               bool flag, float arg1, float arg2);
    void LaunchMagicProjectile(float value, TESBoundObject* object, bool arg1, float impulseRadiusSquared, bool arg2);
    void CreateSpellImpactEffect(blob12 position, TESObjectCELL* cell, MagicItem* item, EffectItem* effect,
                                 void* data, float arg1, float arg2);
    void ApplyMagicEffectToActor(Actor* actor, blob12 position, EffectItem* effect, float value);
    void ExplodeRigidBody(hkpRigidBody* body, blob12 position, EffectItem* effect, float value);
    bool CanCastOnTarget(MagicTarget* target, MagicItem* item);
    Actor* GetCasterActor();
    Actor* FUN_00815410();
    int GetState();
    void SetMagicLight(MagicEffectCollection* light);
    MagicEffectCollection* GetMagicLight();
    void UpdateMagicCaster(float delta);
    unsigned int GetCasterHandle();
    static MagicCaster* GetCasterByHandle(unsigned int handle);
    void FireRefData();
    void ApplyMagicEffect(MagicItem* item, ActiveEffect* effect, TESObjectCELL* cell, blob12 position,
                          MagicTarget* target, MagicProjectile* projectile, void* data, bool* flag, float value);
    bool RunExplosionLOSPick(blob12 position, Actor* actor);
    void CreateMagicProjectile(MagicItem* item, int type, blob12 position, void* data);
    bool AddEffectToTarget(MagicTarget* target, blob12 position, MagicItem* item, ActiveEffect* effect, bool immediate);
    bool AddEffectToTarget(MagicTarget* target, NiPoint3 position, MagicItem* item, ActiveEffect* effect, bool immediate);
    void SetState(int state, char* reason);
    void SetState(MagicCaster::State state, char* reason);
    void* __vecDelDtor(unsigned int flags);
    void SetSelectedMagicItem(int spell);
    void SetCurrentSpellState(int state);
};

typedef char MagicCaster_size_check[(sizeof(MagicCaster) == 12) ? 1 : -1];
typedef char MagicCaster_light_offset_check[(offsetof(MagicCaster, apTargetLight) == 4) ? 1 : -1];
typedef char MagicCaster_state_offset_check[(offsetof(MagicCaster, eState) == 8) ? 1 : -1];
