#pragma once

class NiAVObject;
class NiPoint3;

// Bethesda's sound handle: 12 bytes (Xbox debug PDB Fallout_Release_Beta.pdb; RTTI names it as a template argument).
// Declarations only: a unit whose original inlines a body defines it out of class.
class BSSoundHandle
{
public:
    enum ASSUMED_STATE
    {
        ASSUMED_STATE_INITIALIZED = 0,
        ASSUMED_STATE_PLAYING = 1,
        ASSUMED_STATE_STOPPED = 2,
        ASSUMED_STATE_PAUSED = 3,
    };
    typedef void (__cdecl* CompletionCallback)(void*, bool);

    unsigned int iSoundID;   // +0x0
    bool bAssumeSuccess;     // +0x4
    ASSUMED_STATE eState;    // +0x8

    BSSoundHandle();
    BSSoundHandle(unsigned int uiSoundID);
    BSSoundHandle(const BSSoundHandle& kOther);
    ~BSSoundHandle();
    BSSoundHandle& operator=(const BSSoundHandle& kOther);
    bool operator==(unsigned int uiSoundID) const;
    bool operator==(const BSSoundHandle& kOther) const;
    bool operator!=(unsigned int uiSoundID);
    bool operator!=(const BSSoundHandle& kOther) const;

    void Clear();
    bool Play(bool bUnk);
    bool PlayAfter(unsigned int uiDelay, int iUnk);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float fVolume);
    bool SetFrequency(float fFrequency);
    bool SetModFrequency(float fFrequency);
    bool SetFrequencyVariance(unsigned char ucVariance);
    bool SetBalance(int iBalance);
    bool SetStaticAttenuation(unsigned short usAttenuation);
    int GetDuration();
    bool SetPosition(const NiPoint3& kPosition);
    bool SetPosition(float fX, float fY, float fZ);
    bool SetBeamEnd(const NiPoint3& kPosition);
    bool SetBeamEnd(float fX, float fY, float fZ);
    void SetMinMax(float fMin, float fMax);
    void SetAttenuationCurve(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e);
    void SetReverbAttenuation(unsigned short usAttenuation);
    bool SetOrientation(float fX, float fY, float fZ);
    unsigned int GetID() const;
    void SetObjectToFollow(NiAVObject* pkObject);
    void Seek(unsigned int uiPosition);
    void SetFollowsListener(bool bFollows);
    void SetCompletionCallback(CompletionCallback pfnCallback, void* pvData);
    void SetPlayCallback(CompletionCallback pfnCallback, void* pvData);
    bool Release();
    bool FadeInPlay(unsigned int uiMilliseconds);
    bool FadeOutAndRelease(unsigned int uiMilliseconds);
    bool FadeOut(unsigned int uiMilliseconds);
    void SetTimeConstraints(unsigned char a, unsigned char b);
    void SetSynchStartTime(unsigned int uiTime);
    void ClearSynchStartTime();
    void SetPriority(unsigned int uiPriority);
    void SetAssumeSuccess(bool bAssume);
    ASSUMED_STATE QState() const;
};
