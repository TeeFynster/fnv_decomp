#pragma once

#include "BGSSaveGameBuffer.h"
#include "FormChangeMask.h"

struct BGSChangeFlags;
class TESBoundObject;

class BGSSaveFormBuffer : public BGSSaveGameBuffer
{
public:
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();

#pragma pack(push, 1)
    struct BGSSaveLoadFormHeader
    {
        unsigned char formID[3];
        unsigned int changeFlags;
        unsigned char formInfo;
        unsigned char version;
    };
#pragma pack(pop)

    BGSSaveLoadFormHeader Header;
    unsigned char _unverified_HeaderTail[3];
    TESForm* pForm;

    BGSSaveFormBuffer();
    ~BGSSaveFormBuffer();

    using BGSSaveGameBuffer::Save;
    void Save(SaveLoadFile* file);
    void SetHeader(unsigned int formID, FormChangeMask changeFlags, int formType, unsigned char version);
    void SetHeader(unsigned int formID, FormChangeMask changeFlags, int formType, int version);
    void SetHeader(unsigned int formID, FormChangeMask changeFlags, int formType, unsigned int version);
    BGSChangeFlags GetChangeFlags();
    FormChangeMask GetChangeFlags(unsigned int flags);
    void SetChangeFlags(FormChangeMask changeFlags);
    void NotifyFormIDChanged(int formID);
    void ClearFormChangeFlags(int flags);
    int GetFormType();
    unsigned char GetVersion();
    void SetForm(TESForm* form);
    unsigned int GetFormIdentifier();
    void InitFormEntry(unsigned int formID, unsigned int changeFlags, unsigned int formType,
                       unsigned char version);
    void InitFormEntry(unsigned int formID, unsigned int changeFlags, unsigned int formType,
                       int version);
    void InitFormEntry(unsigned int formID, unsigned int changeFlags, unsigned int formType,
                       unsigned int version);
    void InitFormEntry(unsigned int formID, FormChangeMask changeFlags, int formType,
                       int version);
    void InitFormEntry(unsigned int formID, FormChangeMask changeFlags, int formType,
                       unsigned int version);
    void InitFormEntry(unsigned int formID, FormChangeMask changeFlags, TESBoundObject* base,
                       void* context);

    void SerializeFormData(void* form, int flags);
    void SaveData(void* data, int size, int flags);
    void SaveData(void* data, unsigned int size, int flags);
    void SaveData(void* data, unsigned short size, unsigned short value);
    void SaveData(const void* data, unsigned int size, int flags);
    void SaveQuaternion(void* data, unsigned int size, int flags = 0);
    void SaveIfChanged(BGSSaveFormBuffer* buffer);
    unsigned int GetPos();
    unsigned int GetSize();
    void SetChunk(unsigned int size, unsigned int position);
    TESObjectREFR* GetFormAsReference();
    Actor* GetActorReference();

    BGSChangeFlags FUN_00428110();
    void FUN_0048c9d0(BGSSaveFormBuffer* buffer);
    void FUN_0050f9c0(TESForm* form);
    void BGSSaveFormBuffer_RemoveChange(int value);
    void BGSSaveFormBuffer_RemoveChange(unsigned int value);
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void FUN_00865db0(unsigned int value, int flags);
    void FUN_00865db0(unsigned int value, unsigned int flags);
    void FUN_00865df0(void* form, int flags = 0);
    void FUN_00865e50(void* data, unsigned int size, int flags = 0);
    unsigned int StartVariableSizedValue();
    void SaveVariableSizedValue(unsigned int value);
    void SaveVariableSizedValue_00865ff0(int count, unsigned int position);
};
