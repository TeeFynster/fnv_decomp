#pragma once

#include "BSRangeNode.h"

class BSBlastNode : public BSRangeNode
{
public:
    virtual ~BSBlastNode();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);

    void __vslot_0();
    void CopyMemberData(BSBlastNode* target, CloningProcess* process);
    static NiObject* CreateObject();
};
