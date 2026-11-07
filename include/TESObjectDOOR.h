#pragma once

#include <stddef.h>

#include "TESBoundAnimObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESScriptableForm.h"
#include "TESMagicCasterForm.h"
#include "TESMagicTargetForm.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSOpenCloseForm.h"
#include "MagicTarget.h"

class Actor;
class DoorAccessData;
class NiAVObject;
class NiFixedString;
class NiNode;
class TESFile;
class TESForm;
class TESObjectREFR;
class TESSound;

class TESObjectDOOR : public TESBoundAnimObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESScriptableForm,
                      public TESMagicCasterForm,
                      public TESMagicTargetForm,
                      public BGSDestructibleObjectForm,
                      public BGSOpenCloseForm
{
public:
    TESObjectDOOR();
    virtual ~TESObjectDOOR();

    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void InitItem();

    void ResetFormData();
    bool Load(TESFile*);
    bool IsTeleportDoor();
    bool IsRandomDoor();
    bool IsAutomaticDoor();
    bool IsFlag4Set();
    bool IsSlidingDoor();
    void SetMinimalUse(bool);
    void FUN_00517500();
    void* FUN_005174d0(unsigned int);
    bool Activate(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int);
    TESObjectREFR* FindRandomTeleportTarget(TESObjectREFR*, TESObjectREFR*);
    void QueueDoorTeleport(TESObjectREFR*);
    TESSound* GetOpenSound();
    void ClearRandomTeleportList();
    BSSimpleList<TESForm*>* TESDataHandler_GetFactions();
    NiNode* Create3DModel(TESObjectREFR*);
    bool HasEntry(TESForm* destination);

    static NiFixedString* GetOpenSequenceName();
    static bool ProcessDoorActivation(TESObjectREFR*, Actor*, bool, bool);
    static bool ProcessDoorActivation(DoorAccessData*, Actor*, TESObjectREFR*, bool, bool);
    static void UpdateDoorNode(NiAVObject*);
    TESSound* m_pOpenSound;
    TESSound* m_pSecondarySound;
    TESSound* m_pLoopingSound;
    unsigned char cFlags;
    unsigned char unk85[3];
    BSSimpleList<TESForm*> m_kRandomTeleportTargets;
};

#if defined(_M_IX86)
typedef char TESObjectDOOR_size_check[(sizeof(TESObjectDOOR) == 144) ? 1 : -1];
typedef char TESObjectDOOR_open_sound_offset_check[(offsetof(TESObjectDOOR, m_pOpenSound) == 120) ? 1 : -1];
typedef char TESObjectDOOR_secondary_sound_offset_check[(offsetof(TESObjectDOOR, m_pSecondarySound) == 124) ? 1 : -1];
typedef char TESObjectDOOR_looping_sound_offset_check[(offsetof(TESObjectDOOR, m_pLoopingSound) == 128) ? 1 : -1];
typedef char TESObjectDOOR_flags_offset_check[(offsetof(TESObjectDOOR, cFlags) == 132) ? 1 : -1];
typedef char TESObjectDOOR_teleport_targets_offset_check[(offsetof(TESObjectDOOR, m_kRandomTeleportTargets) == 136) ? 1 : -1];
#endif
