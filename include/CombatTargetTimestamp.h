#pragma once

#include "BGSLoadGameBuffer.h"
#include "BGSSaveGameBuffer.h"

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;

class CombatTargetTimestamp
{
public:
    float fTimeStamp;

    CombatTargetTimestamp(float);
    float ElapsedTime();
    float DisplayElapsedTime();
    float GetElapsedTime();
    void SaveGame(BGSSaveGameBuffer*);
    void LoadGame(BGSLoadGameBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void SaveTimeStamp(BGSSaveFormBuffer*);
    void SaveTimeStamp(void*);
};
