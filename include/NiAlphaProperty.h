#pragma once

#include "NiProperty.h"
#include <stddef.h>

class NiAlphaProperty : public NiProperty
{
  public:
    enum AlphaFunction  // values: Xbox PDB NiAlphaProperty::AlphaFunction
    {
        ALPHA_ONE = 0,
        ALPHA_ZERO = 1,
        ALPHA_SRCCOLOR = 2,
        ALPHA_INVSRCCOLOR = 3,
        ALPHA_DESTCOLOR = 4,
        ALPHA_INVDESTCOLOR = 5,
        ALPHA_SRCALPHA = 6,
        ALPHA_INVSRCALPHA = 7,
        ALPHA_DESTALPHA = 8,
        ALPHA_INVDESTALPHA = 9,
        ALPHA_SRCALPHASAT = 10,
        ALPHA_MAX_MODES = 11
    };

    NiAlphaProperty();
    virtual ~NiAlphaProperty();
    virtual void LoadBinary(NiStream& stream);

    void SetFlag512(bool enable);
    void SetFlags(unsigned short flags);

    void NiAlphaProperty_SetAlphaBlending(bool enable);
    void NiAlphaProperty_SetTestRef(unsigned char value);
    void NiAlphaProperty_SetSrcBlendMode(int value);
    void NiAlphaProperty_SetDestBlendMode(int value);
    void NiAlphaProperty_SetNoSorter(bool enable);
    void NiAlphaProperty_SetBit(bool enable, unsigned short flags);
    void NiAlphaProperty_SetBit(bool enable, unsigned int flags);
    void ForwardCall_00439320();
    void* FUN_004392f0(unsigned int flags);


    unsigned short m_usAlphaArg;
    unsigned char m_ucAlphaArg2;
    unsigned char m_ucPad1b;
};
