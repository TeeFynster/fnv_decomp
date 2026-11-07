#pragma once

#include "NiTimeController.h"
#include "NiFloatData.h"
#include "StrArr.h"

class NiFloatController : public NiTimeController
{
public:
    virtual ~NiFloatController();
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);

    void LoadBinary_00a57970(NiStream& stream);
    TimedAnimationKey* GetFloatKeys(unsigned int& numKeys, NiAnimationKey::KeyType& keyType,
                                    unsigned char& keySize);
    void ProcessClone_00a57a40(CloningProcess& process);
    void LinkObject_00a57a70(NiStream& stream);
    bool RegisterStreamables_00a57ad0(NiStream& stream);
    void __thiscall SaveBinary_00a57b00(NiStream& stream);
    bool IsEqual_00a57b20(NiFloatController* other);
    void CopyInterpTo(NiFloatController* destination, void* process);
    void AppendString(StrArr* strings);
    void FUN_00a6cfe0(NiFloatController* destination, void* process);
    bool NiTimeController_IsEqual(NiFloatController* other);
    void FUN_00a6d830(StrArr* strings);

    unsigned int unk34;
    NiFloatData* m_spFloatData;
};
