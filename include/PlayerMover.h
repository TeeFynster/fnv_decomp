#pragma once

#include "ActorMover.h"
#include "NiPoint3.h"

class BGSLoadFormBuffer;

class PlayerMover : public ActorMover
{
public:
    ~PlayerMover();

    void SetMoveModePreference(unsigned int auMode);
    void ClearMoveModePreference(unsigned int auMode);
    void* FUN_009e9e00(unsigned int auFlags);
    void ResetVtableAndDestroyActorMover();
    void SaveGame_009ea5a0(BGSSaveFormBuffer* apBuffer);

    void Revert(BGSLoadFormBuffer* apBuffer);
    void LoadGame(BGSLoadFormBuffer* apBuffer);
    void InitLoadGame(BGSLoadFormBuffer* apBuffer);
    void SetMovementValue(float fTimeSinceScaleStart);
    void Update(float fTimeSinceScaleStart);
    void SetMoverMode(unsigned int auMode);
    void UpdatePlayerStatus(unsigned int auMode, bool abSet);
    void SetSideVec(const NiPoint3& arSideVec);
    void ClearMode(unsigned int auMode);
    unsigned int GetActorStateFlags();

    NiPoint3 m_kSideVec;
    unsigned int ByteAndFlagState;
    unsigned int m_uiMode;
    float m_fValue;
};
