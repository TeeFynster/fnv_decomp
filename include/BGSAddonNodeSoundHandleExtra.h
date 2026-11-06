#pragma once

#include "NiExtraData.h"
#include "BSSoundHandle.h"

class BGSAddonNodeSoundHandleExtra : public NiExtraData
{
public:
    BGSAddonNodeSoundHandleExtra();
    virtual ~BGSAddonNodeSoundHandleExtra();

    virtual const NiRTTI* GetRTTI() const;
    virtual void vf37();

    void FUN_004f9270();
    void* FUN_004f9240(unsigned int flags);

    BSSoundHandle m_kData;
};
