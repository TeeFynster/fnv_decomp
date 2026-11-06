#pragma once

#include "NiPSysVolumeEmitter.h"

class NiPSysBoxEmitter : public NiPSysVolumeEmitter
{
public:
    virtual void LoadBinary(NiStream& stream);

    void CopyMemberData(NiPSysModifier* pkDest, CloningProcess& kProcess);
    void CopyTo(NiPSysModifier* pkDest, CloningProcess& kProcess);

    float width;
    float height;
    float depth;
};
