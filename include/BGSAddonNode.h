#pragma once

#include "TESBoundObject.h"
#include "TESModelTextureSwap.h"
#include "AddonData.h"

class TESFile;
class TESSound;

class BGSAddonNode : public TESBoundObject, public TESModelTextureSwap
{
public:
    typedef ::_AddonNodeFlags _AddonNodeFlags;
    typedef _AddonNodeFlags::Flags AddonNodeFlags;
    typedef ::AddonData AddonData;

    BGSAddonNode();

    virtual void InitItem(void);
    virtual bool LoadForm(TESFile* file);
    bool Load(TESFile* file);

    void ResetFormData();
    bool FUN_00448bf0();
    unsigned int GetIndex();
    void SetIndex(unsigned int index);
    unsigned int GetGrass();
    int FUN_0059e300();
    unsigned short GetShortAtOffset58();
    bool IsMasterParticleSystem() const;

    unsigned int uiIndex;
    TESSound* SoundAssetTmp;
    AddonData kData;
    unsigned int uiParticleSystemIndex;
};
