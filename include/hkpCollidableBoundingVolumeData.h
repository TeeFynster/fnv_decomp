#pragma once

struct hkFinishLoadedObjectFlagCD2C;

class hkpCollidableBoundingVolumeData
{
public:
    hkpCollidableBoundingVolumeData();  // 0x00d01a60 (hkpCollidable::BoundingVolumeData::BoundingVolumeData)
    hkpCollidableBoundingVolumeData(hkFinishLoadedObjectFlagCD2C flag);
    void invalidate();

    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_ucUnknownByte;
    unsigned short m_uiNumChildShapeAabbs;
    unsigned short m_uiCapacityChildShapeAabbs;
    void* m_pChildShapeAabbs;
    void* m_pChildShapeKeys;
};
