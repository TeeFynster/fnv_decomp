#pragma once

#include "NiObject.h"

class NiAVObject;
class NiNode;
class TESObjectCELL;
class TESForm;
class BGSSaveGameBuffer;
class BGSLoadGameBuffer;

class BSTempEffect : public NiObject
{
  public:
    struct _Type
    {
        enum Type
        {
            GEO_DECAL = 1,
            PARTICLE = 2,
            SIMPLE_DECAL = 3,
            MAGIC_HIT = 4,
            MAGIC_MODEL_HIT = 5,
            MAGIC_SHADER_HIT = 6
        };
    };
    typedef _Type::Type Type;

    BSTempEffect();
    BSTempEffect(TESObjectCELL* apCell, float afLifetime);
    virtual ~BSTempEffect();
    virtual void DeleteThis();
    virtual const NiRTTI* GetRTTI() const;

    virtual void Initialize();
    virtual void Detach();
    virtual bool Update(float afTime);
    virtual NiAVObject* Get3D();
    virtual int GetType();
    virtual bool IsSaveable();
    virtual unsigned short GetSaveSize();
    // MSVC assigns each overload group in reverse declaration order.
    virtual void SaveGame();
    virtual void SaveGame(BGSSaveGameBuffer* apBuffer);
    virtual bool LoadGame();
    virtual void LoadGame(BGSLoadGameBuffer* apBuffer);
    virtual void InitLoadGame(BGSLoadGameBuffer* apBuffer);
    virtual void ApplyLoadBuffer(BGSLoadGameBuffer* apBuffer);
    virtual bool ShouldDelete();

    NiNode* Get3D() const;
    Type GetType() const;
    bool IsSaveable() const;
    void SaveGameBGS(BGSSaveGameBuffer* buffer);
    void SaveGameTES();
    void LoadGameBGS(BGSLoadGameBuffer* buffer);
    bool LoadGameTES();
    void SetTarget(TESForm* target);
    bool IsFirstPerson() const;
    void IncRefCount();
    void DecRefCount();

    float m_fParticleParameter5;
    TESObjectCELL* pCell;
    float m_fFirstFloatValue;
    bool bInitialized;
    unsigned char layoutPadding15[3];
};
