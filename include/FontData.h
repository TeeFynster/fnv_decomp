#pragma once

class RunNode;
class SStr;
class Info_;

struct TextureFile
{
    unsigned char _unverified_iType[4];
    unsigned char _unverified_pFilename[32];
};

struct UVMap
{
    float fU;
    float fV;
};

struct FontLetter
{
    unsigned char _unverified_iTextureIndex[4];
    UVMap pMapping[4];
    float fWidth;
    float fHeight;
    float fLeadingEdge;
    float fSpacing;
    float fTopEdge;
};

class FontData
{
public:
    float fBaseLine;
    int iTextureCount;
    TextureFile pTextureFiles[8];
    FontLetter pFontLetters[256];

    static void* operator new(unsigned int size);
    RunNode* ParseLayout(SStr*, Info_*);
    RunNode* CreateTextRunNode(SStr* text, Info_* info);
};
