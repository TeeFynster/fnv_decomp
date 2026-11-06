#pragma once

#include "TESForm.h"
#include "UnsignedIntArray16.h"
#include "StatsChunkData.h"
#include "UInt32ChunkData.h"

class TESCombatStyle : public TESForm
{
public:
    UnsignedIntArray16 m_kUnsignedIntArray16;
    StatsChunkData Data;
    UInt32ChunkData m_kUInt32ChunkData;

    TESCombatStyle();
    void ResetFormData();
    bool Load(TESFile*);
    float GetRandomValue();
    float UpdateCombatStyle();
    void UpdateCombatStyle() const;
};
