#pragma once

#include "BSAudio.h"

class IDirectSound8;
class IDirectSoundBuffer;

class BSWin32Audio : public BSAudio
{
public:
    IDirectSound8* pDirectSound;
    IDirectSoundBuffer* pPrimaryBuffer;
    unsigned char Caps[96];
    void* hWnd;

    void Shutdown();
};
