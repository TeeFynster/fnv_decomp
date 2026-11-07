
// src/fallout_shared/audiomarkerdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/audiomarkerdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct MediaLocation
{
    const char* LocationName;
    int pad0;
    float m_fLayerOneTriggerPercent;
    float m_fLayerTwoTriggerPercent;
    unsigned int pController;
    bool m_bUseControllerValues;
    virtual bool AudioMarkerData_Compare(MediaLocation* apCompare);
    virtual bool IsValid(MediaLocation* apCompare);
    virtual bool v3(MediaLocation* apCompare);
    virtual bool v4(MediaLocation* apCompare);
};
// @fnv 0x005897c0
// src: XBOX_PDB 0x005897c0
bool MediaLocation::AudioMarkerData_Compare(MediaLocation* apCompare)
{
    if (v4(apCompare))
        return true;
    if (*(unsigned int*)((char*)this + 0x24) != *(unsigned int*)((char*)apCompare + 0x24))
        return true;
    if (*(bool*)((char*)this + 0x28) != *(bool*)((char*)apCompare + 0x28))
        return true;
    if (m_fLayerOneTriggerPercent != apCompare->m_fLayerOneTriggerPercent)
        return true;
    if (m_fLayerTwoTriggerPercent != apCompare->m_fLayerTwoTriggerPercent)
        return true;
    return false;
}
