#pragma once

#include "TESBoundAnimObject.h"
#include "TESSoundFile.h"
#include "TESSound__SOUND_DATA.h"

class Obj;

class TESSound : public TESBoundAnimObject, public TESSoundFile
{
public:
    struct SoundPlaybackParameters
    {
        unsigned char iMin, iMax;
        signed char m_cPitchAdjustment;
        unsigned char m_ucUnused;
        unsigned int iFlags;
        unsigned short m_uiFrequency;
        unsigned char m_aucAttenuationBytes[2];
        unsigned short m_auiAttenuationCurve[5];
        unsigned short m_uiReverbAttenuation;
        unsigned int iPriority, m_uiTrailingValue1, m_uiTrailingValue2;
    };

    TESSound();
    virtual ~TESSound();

    void ResetFormData();
    bool Load(TESFile* file);
    SoundPlaybackParameters CopyBig();
    unsigned char GetHighByteOfField4E();
    unsigned char GetField45();
    char GetByteAtOffset44();
    unsigned short GetShortAt(int index);
    unsigned short GetShortAtOffset5A();
    unsigned int GetPriority_0082d720();
    unsigned int Deallocate();
    unsigned int GetFormID();
    unsigned int GetSoundID();
    const char* TESSound_GetFilename();
    unsigned char GetEndTime_0082d700();
    bool Projectile_IsEditorCreated();
    Obj* FUN_00586170();
    void TESForm_CopyAllComponents(TESForm* form);
    void CopyFromSound(TESForm* form);

    static void InitializeMagicSystem();
    static unsigned int GetPlaybackFlags(unsigned int flags);
    static TESSound* FindSoundByFilename(const char* filename);

    BSStringT<char> cFileName;
    union
    {
        TESSound__SOUND_DATA data;
        struct
        {
            unsigned char unk44[0x24];
            // The sound flag shares the trailing sound-data byte.
            char m_cSoundFlag;
            unsigned char layoutPadding69[3];
        };
    };
};
