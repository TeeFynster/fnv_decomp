#pragma once

#include "NiControllerSequence.h"
#include "NiPointer.h"
#include "NiTPrimitiveArray.h"

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class NiControllerSequenceX;
class TESAnimGroup;
class TESObjectREFR;

class BSAnimGroupSequence : public NiControllerSequence
{
  public:
    BSAnimGroupSequence(const void*, NiAVObject*);
    virtual ~BSAnimGroupSequence();
    virtual const NiRTTI* GetRTTI() const;
    virtual bool Deactivate(float, bool);

    TESAnimGroup* GetAnimGroup() const;
    unsigned char GetPriority(const char*, unsigned int*);
    NiObject* __thiscall CreateClone(CloningProcess* arCloneData);
    void GetViewerStrings_004eec40(NiTPrimitiveArray<const char*>* pkStrings);
    float GetScaledTime(float afTime);
    void ValidateTargets();
    bool AttachToOwner(NiAVObject* target, int argument);
    unsigned short __thiscall GetSaveSize_004efb10();
    void SaveGameTES_004efb20(float afTime);
    void LoadGame_004efbc0(float value);
    void SaveGameBGS_004efc90(BGSSaveFormBuffer* buffer, float value);
    void LoadGameBGS_004efd10(BGSLoadFormBuffer* pBuffer, float fBaseTime);

    static bool PlayAnimSounds(NiControllerSequence*, TESObjectREFR*);
    static bool __cdecl PlayAnimSounds(NiControllerSequenceX*, TESObjectREFR*);
    static const NiRTTI ms_kRTTI;

    NiPointer<TESAnimGroup> m_spAnimGroup;
};
