#pragma once

#include "NiFloatController.h"

class NiFloatKey;
class StrArr;

class NiRollController : public NiFloatController
{
public:
    NiRollController();
    virtual ~NiRollController();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void Update(NiUpdateData& update);

    using NiFloatController::GetFloatKeys;
    NiFloatKey* GetFloatKeys(unsigned int& numKeys, int& keyType,
                            unsigned char& keySize);
    void AppendString(StrArr* strings);
    void GetViewerStrings_00a48790(StrArr* strings);
    NiObject* CreateClone_00a486f0(CloningProcess& process);
    void Update_00a485e0(NiUpdateData& update);
    void FUN_00a57990();
    void* DestroyIfFlagged(unsigned int flags);
};
