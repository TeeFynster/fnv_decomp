#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/Character.h"

// Private character call declarations; Character and load buffers use the shared definitions.
#ifndef FNV_CHARACTER_DECLS_H
#define FNV_CHARACTER_DECLS_H

#define PlayerCharacter PlayerCharacter_ActorHeader
#include "actor_rtti_character.h"
#undef PlayerCharacter

class MusicMarkerReference;
class PlayerCharacter
{
  public:
    MusicMarkerReference* GetMusicMarkerReference();
};

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
