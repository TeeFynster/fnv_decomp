#pragma once

union BSPackedTask__PackedTaskVariantData
{
  public:
    union
    {                      // overlapping CodeView storage
        bool bData;        // +0x0, 1 bytes
        char pcDataA[4];   // +0x0, 4 bytes
        short psDataA[2];  // +0x0, 4 bytes
        int iData;         // +0x0, 4 bytes
        float fData;       // +0x0, 4 bytes
        void* pData;       // +0x0, 4 bytes
    };
};

class BSPackedTask
{
public:
    union
    {
        struct { int f0; int f1; int f2; char buf[20]; };
        BSPackedTask__PackedTaskVariantData m_akPackedTaskVariantData[8]; // exe: eight 4-byte packed lanes at +0
    };
};
