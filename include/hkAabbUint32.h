#pragma once

// Havok 7.1 hkAabbUint32 (32 bytes, 16-aligned): quantized min/max corners with per-axis expansion bytes.
// FNV reads the dword at +0x0c as the shape key, and Havok writes the max corner and its expansion bytes with
// one 16-byte store, so both halves carry a dword view.
class __declspec(align(16)) hkAabbUint32
{
public:
#ifdef FNV64_HKAABBUINT32_OUTLINE_ASSIGN
    void operator=(const hkAabbUint32&); // exe caller 0x00d35770 requires the out-of-line copy
#endif
    unsigned int m_kMinimumCorner[3];
    union
    {
        struct
        {
            unsigned char m_ucExpansionMin[3];
            unsigned char m_ucExpansionShift;
        };
        unsigned int m_uiCollisionShapeKey;
    };
    union
    {
        unsigned int m_kMaximumCorner[4];
        struct
        {
            unsigned int m_kMaximumCornerXYZ[3];
            unsigned char m_ucExpansionMax[3];
            unsigned char m_ucShapeKeyByte;
        };
    };
};

typedef char hkAabbUint32_size_check[(sizeof(hkAabbUint32) == 32) ? 1 : -1];
