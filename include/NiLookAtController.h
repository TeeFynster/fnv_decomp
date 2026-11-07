#pragma once

#include "NiTimeController.h"
#include "NiAVObject.h"

class StrArr;

class NiLookAtController : public NiTimeController
{
public:
    NiLookAtController();
    virtual ~NiLookAtController();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void Update(NiUpdateData& update);

    void* Destroy(unsigned int flags);
    void* FUN_00a4cd40(unsigned int flags);
    void LinkObject_00a4c840(NiStream& stream);
    NiLookAtController* CreateClone_00a4cd60(void* process);
    void LoadBinary_00a4ce20(NiStream& stream);
    bool RegisterStreamables_00a4c860(NiStream& stream);
    void SaveBinary_00a4cea0(NiStream* stream);
    bool IsEqual_00a4c890(NiLookAtController* other);
    void LookupAndLinkItem(void* item);
    void AppendString(StrArr* strings);
    void SetBit(bool value, unsigned short mask);
    bool GetBit(unsigned short mask) const;
    void SetField(unsigned short value, unsigned short mask, unsigned short position);
    unsigned short GetField(unsigned short mask, unsigned short position) const;
    bool GetFlip() const;
    unsigned short GetAxis() const;
    bool IsActive() const;

    char _pad[0x04];
    NiAVObject* m_pkLookAt;
};
