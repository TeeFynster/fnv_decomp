#pragma once

class BGSLoadGameBuffer;
class BGSLoadFormBuffer;
class BGSSaveGameBuffer;
class BGSSaveFormBuffer;
class TESForm;

class BGSLoadGameSubBuffer
{
public:
    char* pBuffer;

    BGSLoadGameSubBuffer();
    BGSLoadGameSubBuffer(int initial);

    void SetBuffer(char* buffer);
    void ResetReadPosition();
    void RestoreAnimation(TESForm* form);
    void ReadAnimationState(TESForm* form);
    void LoadHavokData(TESForm* form);
    void LoadHavokData(void* form);
    void SaveAnimation(TESForm* form);
    void SaveFormState(TESForm* form);
    void SaveGame(BGSSaveGameBuffer* buffer);
    void LoadGame(BGSLoadGameBuffer* buffer);
    BGSLoadFormBuffer* CreateFormBuffer(TESForm* form);
    void RenderCopyData(BGSSaveFormBuffer* buffer);
    void DeleteBuffer();
};
