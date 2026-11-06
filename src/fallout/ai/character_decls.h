// fallout/ai/character_decls.h: player and actor call declarations
#ifndef FNV_CHARACTER_DECLS_H
#define FNV_CHARACTER_DECLS_H

#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/Character.h"
#include "../../../include/PlayerCharacter.h"

class MusicMarkerReference;

class AudioMarkerDataCalls
{
  public:
    void* GetData();
};

class CharacterActorCalls
{
  public:
    void InitLoadGame(BGSLoadFormBuffer* buffer);
    void ApplyLoadBuffer(BGSLoadFormBuffer* buffer);
    void Revert(BGSLoadFormBuffer* buffer);
    void LoadGame(BGSLoadFormBuffer* buffer);
};
#endif
