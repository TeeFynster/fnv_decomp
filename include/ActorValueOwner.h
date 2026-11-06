#pragma once

namespace ActorValue
{
    enum Index;
}

class Actor;
class TESForm;

class ActorValueOwner
{
public:
    ActorValueOwner();

    virtual int GetBaseActorValue(ActorValue::Index actorValue);
    virtual float GetBaseActorValueFloat(ActorValue::Index actorValue);
    virtual int GetActorValue(ActorValue::Index actorValue);
    virtual float GetCurrentActorValue(ActorValue::Index actorValue);
    virtual float GetPermanentActorValueFloat(ActorValue::Index actorValue);
    virtual float GetTemporaryActorValue(ActorValue::Index actorValue);
    virtual float GetDamageActorValue(ActorValue::Index actorValue);
    virtual int GetPermanentActorValue(ActorValue::Index actorValue);
    virtual float GetPermanentActorValueAdjustment(ActorValue::Index actorValue);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();

    Actor* GetActorOwner();
    float GetActorValueFloatByIndex(ActorValue::Index index);
    float GetActorValueFloatByIndex(int index);
    int GetActorValueAsInteger(ActorValue::Index index);
    int GetActorValueAsInteger(int index);
};
