#pragma once

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;

class TimeoutTimer
{
public:
    float m_fStartTime;
    float m_fTimeout;

    TimeoutTimer();
    void FUN_00910b10();
    float FUN_006b9130();
    bool CheckTimer() const;
    void __thiscall LoadGame(BGSLoadFormBuffer* buffer);
    void SaveGame(BGSSaveFormBuffer* buffer);
    void Start(float t);
    bool Expired();
    void Reset();
    bool IsRunning();
};
