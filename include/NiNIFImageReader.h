#pragma once

#include "NiImageReader.h"

class NiNIFImageReader : public NiImageReader
{
public:
    void* m_0x0;
    void* m_0x4;
    float m_0x8;
    void* m_0xc;
    void* m_0x10;
    void* m_0x14;
    void* m_0x18;
    void* m_0x1c;
    void* m_0x20;
    void* m_0x24;
    void* m_0x28;
    void* m_0x2c;
    void* m_0x30;
    void* m_0x34;
    void* m_0x38;
    void* m_0x3c;
    void* m_0x40;
    void* m_0x44;

    NiNIFImageReader* InitFromInputs(const NiNIFImageReader* s, float f,
                                    const NiNIFImageReader* t,
                                    const NiNIFImageReader* u,
                                    NiNIFImageReader* d);
};
