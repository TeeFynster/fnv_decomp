#pragma once

#pragma pack(push, 2)

class IMAGE_AUX_SYMBOL_TOKEN_DEF
{
public:
    unsigned char bAuxType;
    unsigned char bReserved;
    unsigned long SymbolTableIndex;
    unsigned char rgbReserved[12];
};

#pragma pack(pop)
