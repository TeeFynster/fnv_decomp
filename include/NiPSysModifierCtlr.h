#pragma once

#include "NiSingleInterpController.h"
#include "NiFixedString.h"
#include "NiPSysModifier.h"

class NiPSysModifierCtlr : public NiSingleInterpController
{
public:
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);
    virtual void vf59();

    void CopyMemberData(NiPSysModifierCtlr* destination, CloningProcess& process);
    void CopyMemberData(NiPSysModifierCtlr* source, void* process);

    NiFixedString m_kTargetModifierName;
    NiPSysModifier* m_pkTargetModifier;
};
