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
    NiObject* __thiscall FUN_004eec20(CloningProcess* arCloneData);
    void FUN_004eec40(NiTPrimitiveArray<const char*>* pkStrings);
    float FUN_004eec60(float afTime);
    void FUN_004eecb0();
    bool AttachToOwner(NiAVObject* target, int argument);
    unsigned short __thiscall FUN_004efb10();
    void FUN_004efb20(float afTime);
    void FUN_004efbc0(float value);
    void FUN_004efc90(BGSSaveFormBuffer* buffer, float value);
    void FUN_004efd10(BGSLoadFormBuffer* pBuffer, float fBaseTime);

    static bool PlayAnimSounds(NiControllerSequence*, TESObjectREFR*);
    static bool __cdecl PlayAnimSounds(NiControllerSequenceX*, TESObjectREFR*);
    static const NiRTTI ms_kRTTI;

    NiPointer<TESAnimGroup> m_spAnimGroup;
};
