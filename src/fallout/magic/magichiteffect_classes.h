// Unit-private BSTempEffect / MagicHitEffect shared by activeeffect.cpp, magichiteffect.cpp and magicmodelhiteffect.cpp
// (no canonical header exists). PC vftables: NiObject 35 slots, BSTempEffect 49, MagicHitEffect 57; slot names and
// declares them with the same signatures these become overrides and the slot numbers do not move.
#ifndef FNV_MAGICHITEFFECT_CLASSES_H
#define FNV_MAGICHITEFFECT_CLASSES_H

#include "layout_support.h"
#include "NiObject.h"
struct NiRTTI;
class NiNode;
class BSFadeNode;
class BSMultiBoundNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class BSResizableTriShape;
class NiParticles;
class NiLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;
class CloningProcess;
class NiStream;
class FourComponentFloatVector;
class NiObjectGroup;
class NiControllerManager;
class NiAVObject;
class TESObjectCELL;
class TESObjectREFR;
class ActiveEffect;
class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
template <class T> class NiTPrimitiveArray;
#pragma pack(push, 4)
class BSTempEffect : public NiObject
{
  public:
    // NiObject slots (see the note above)
    // GetRTTI, the Is* casts, IsEqual, Get/AddViewerStrings, SetObjectBound and IsControllerManager are the shared NiObject virtuals
    virtual NiObject* MakeClone(CloningProcess& arCloning);              // v48
    virtual void LoadBinary(NiStream& arStream);                         // v4C
    virtual void LinkObject(NiStream& arStream);                         // v50
    virtual bool RegisterStreamables(NiStream& arStream);                // v54
    virtual void SaveBinary(NiStream& arStream);                         // v58
    virtual void ProcessClone(CloningProcess& arCloning);                // v68
    virtual void PostLinkObject(NiStream& arStream);                     // v6C
    virtual bool StreamCanSkip();                                        // v70
    virtual const NiRTTI* GetStreamableRTTI();                           // v74
    virtual unsigned int GetBlockAllocationSize();                       // v7C
    virtual NiObjectGroup* GetGroup();                                   // v80
    virtual void SetGroup(NiObjectGroup* apGroup);                       // v84
    // BSTempEffect slots
    virtual void Initialize();             // v8C
    virtual void Detach();                 // v90
    virtual bool Update(float afTime);     // v94
    virtual NiAVObject* Get3D();           // v98
    virtual int GetType();                 // v9C (TEMP_EFFECT_TYPE)
    virtual bool IsSaveable();             // vA0
    virtual unsigned short GetSaveSize();  // vA4
    // MSVC places overloads in reverse declaration order: SaveGame(BGSSaveGameBuffer*) is vA8, SaveGame() vAC
    virtual void SaveGame();
    virtual void SaveGame(BGSSaveGameBuffer* apBuffer);
    // LoadGame(BGSLoadGameBuffer*) is vB0, LoadGame() vB4
    virtual bool LoadGame();
    virtual void LoadGame(BGSLoadGameBuffer* apBuffer);
    virtual void InitLoadGame(BGSLoadGameBuffer* apBuffer);     // vB8
    virtual void ApplyLoadBuffer(BGSLoadGameBuffer* apBuffer);  // vBC
    virtual bool ShouldDelete();                                // vC0
    BSTempEffect(TESObjectCELL* apCell, float afLifetime);
    float m_fParticleParameter5;  // +0x08
    TESObjectCELL* pCell;         // +0x0C
    float m_fFirstFloatValue;                   // +0x10
    bool bInitialized;            // +0x14
    unsigned char layoutPadding15[3];
};
class MagicHitEffect : public BSTempEffect
{
  public:
    virtual bool Init();                                                                            // vC4
    virtual void ResetTargetPointer();                                                              // vC8
    virtual void AttachToTarget();                                                                  // vCC
    virtual unsigned short GetSaveSize(ActiveEffect* apEffect, TESObjectREFR* apTarget);            // vD0
    virtual void SaveGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);                         // vD4
    virtual void LoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);                         // vD8
    virtual void InitLoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);                     // vDC
    virtual void FinishLoadGameTES(ActiveEffect* apEffect, TESObjectREFR* apTarget, void* apData);  // vE0
    MagicHitEffect(TESObjectREFR* apTarget, ActiveEffect* apEffect);
    ActiveEffect* pEffect;   // +0x18
    TESObjectREFR* pTarget;  // +0x1C
    float m_fFirstFloatValue;              // +0x20
    bool bWasPlaying;        // +0x24
    unsigned char layoutPadding25[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTempEffect) == 0x18);
FNV_STATIC_ASSERT(offsetof(BSTempEffect, m_fParticleParameter5) == 0x8);
FNV_STATIC_ASSERT(offsetof(BSTempEffect, bInitialized) == 0x14);
FNV_STATIC_ASSERT(sizeof(MagicHitEffect) == 0x28);
FNV_STATIC_ASSERT(offsetof(MagicHitEffect, pEffect) == 0x18);
FNV_STATIC_ASSERT(offsetof(MagicHitEffect, pTarget) == 0x1C);
FNV_STATIC_ASSERT(offsetof(MagicHitEffect, m_fFirstFloatValue) == 0x20);
FNV_STATIC_ASSERT(offsetof(MagicHitEffect, bWasPlaying) == 0x24);
#endif
