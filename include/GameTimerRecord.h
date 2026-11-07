#pragma once

class GameTimerRecord
{
public:
    unsigned char m_ucFirstTimerByte;
    unsigned char layoutPadding1;
    unsigned short layoutPadding2;
    float m_fFirstTimerValue;
    float m_fSecondTimerValue;
    float fTimeSinceScaleStart;
    float m_fFourthTimerValue;
    unsigned int m_uiFirstTimerValue;
    unsigned int m_uiSecondTimerValue;
    bool m_bFirstTimerFlag;
    bool m_bSecondTimerFlag;
    unsigned short layoutPadding1E;

    void Update();
    void Update(unsigned int);
    float GetSeconds();
    float GetUnmodifiedSeconds();
    unsigned int GetTime();
    unsigned int GetTime() const;
    unsigned int GetStartTime();
    void ClampAt(unsigned int);
    bool QEnabled();
    bool GetSecondsIsZero();
    void SetGlobalTimeMultiplier(float, bool);
    static void SetGlobalTimeMultiplierCache();
    void RestoreGlobalTimeMultiplierCache();
    static float QGlobalTimeMultiplier();
    static float QGlobalTimeMultiplierTarget();
    static void UpdateGlobalTimeMultiplier();
    void SetUseGlobalTimeMultiplierTarget(bool);
    bool QUseGlobalTimeMultiplierTarget();
    float GetRealTimeSeconds();
    void Enable();
    void Disable();
    void Init(unsigned int);
    int GetSection();
    void BSTimer_Disable();
};
