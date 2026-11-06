#pragma once

#include "Actor.h"

class BipedAnim;
class BGSLoadFormBuffer;

class Character : public Actor
{
public:
    BipedAnim* pBiped;
    float m_fFirstResetValue;
    float m_fSecondValue;
    bool m_bTrespassing;
    bool m_bActorGuard;
    unsigned short layoutPadding1C2;
    float m_fThirdValue;

    virtual void Unk_137(void);
    virtual void Unk_138(void);

    Character(bool);
    virtual ~Character();
    void* operator new(unsigned int);

    MagicTarget* GetMagicTarget();
    void InitLoadGame(BGSLoadFormBuffer* buffer);
    void ApplyLoadBuffer(BGSLoadFormBuffer* buffer);
    void Revert(BGSLoadFormBuffer* buffer);
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    void* GetCurrentMusicMarker();
    bool GetActorGuard();
    void SetActorGuardState(bool guard);
    void Reset3D();
};
