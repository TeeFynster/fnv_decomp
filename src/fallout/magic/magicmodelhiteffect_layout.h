#pragma once

#include "../../../include/MagicHitEffect.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/BGSLoadGameSubBuffer.h"

class MagicModelHitEffect : public MagicHitEffect
{
  public:
    virtual bool Update(float afTime);                                                              // v94
    virtual int GetType();                                                                          // v9C
    virtual bool IsSaveable();                                                                      // vA0
    virtual unsigned short GetSaveSize();                                                           // vA4
    virtual void SaveGame();                                                                        // vAC
    virtual void SaveGame(BGSSaveGameBuffer* apBuffer);                                             // vA8
    virtual bool LoadGame();                                                                        // vB4
    virtual void LoadGame(BGSLoadGameBuffer* apBuffer);                                             // vB0
    virtual void InitLoadGame(BGSLoadGameBuffer* apBuffer);                                         // vB8
    virtual void ApplyLoadBuffer(BGSLoadGameBuffer* apBuffer);                                      // vBC
    virtual bool Init();                                                                            // vC4
    virtual void AttachToTarget();                                                                  // vCC
    virtual unsigned short GetSaveSize(ActiveEffect* apEffect, TESObjectREFR* apTarget);            // vD0
    virtual void SaveGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);                         // vD4
    virtual void LoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);                         // vD8
    virtual void InitLoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);                     // vDC
    virtual void FinishLoadGameTES(ActiveEffect* apEffect, TESObjectREFR* apTarget, void* apData);  // vE0
    bool m_bFirstPerson;                                                                            // +0x28, 1 bytes
    bool b3rdPerson;                                                                                // +0x29, 1 bytes
    unsigned char layoutPadding2A[2];
    const char* pFilename;                      // +0x2C, 4 bytes
    NiPointer<NiAVObject> spRetainedObject;     // +0x30, 4 bytes
    NiPointer<NiAVObject> m_spTargetObject;     // +0x34, 4 bytes
    BGSLoadGameSubBuffer m_kLoadGameSubBuffer;  // +0x38, 4 bytes
};
