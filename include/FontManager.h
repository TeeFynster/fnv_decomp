#pragma once

#include "NiPoint3.h"

class Font;
class NiNode;
class NiTriShape;
class TextParams;
class TextNode;
struct TextString;
struct PageTable;
struct SStr;
struct Info_;
struct RunNode;
struct LayoutString;
struct LayoutBlock;
struct LayoutResult;

class FontManager
{
public:
    Font* pFont[8];
    bool bUseNewFonts;
    unsigned char _pad21[3];

    void* __vecDelDtor(unsigned int);
    static void* operator new(unsigned int size);
    static void operator delete(void* memory);

    static FontManager* pInstance;
    static void Init();
    static FontManager* Instance();
    static void Free();
    static FontManager* Get();
    static FontManager* __stdcall GetFontManager(bool);

    Font* GetFont(int);
    Font* GetFont(unsigned int);
    const char* GetFontFile(unsigned int);
    int GetCharType(char);
    TextString CollectTo(char*, int*, int, int, int*, char*, bool);
    SStr Font_CollectTo(const char*, int*, unsigned int, unsigned int,
                     int*, char*, bool);
    LayoutString Font_CollectTo(const char*, int*, unsigned int, unsigned int,
                             unsigned int*, char*, bool);
    RunNode* ParseLayout(SStr*, Info_*);
    LayoutBlock* ParseLayout(LayoutString&, LayoutResult*);
    void* PrepareFontText(void*, void*);
    void* BuildFontTextData(void*, void*);
    bool AddTextToNode(TextString, void*, NiNode*);
    NiTriShape* BuildTextShape(TextString, NiPoint3, int, int);
    void UseNewFonts(bool);
    NiPoint3 GetFontManager(char*, int, float, int);
    float GetFontPadding(int);
    bool CreateTextRun(TextString, TextParams*, TextNode*);
    NiPoint3 GetStringDimensions(const char*, int, float, int);
    void SetByteAtOffset20();
    void VATSEffect_SetBodyPartEnabled(PageTable*, int, unsigned char);
};
