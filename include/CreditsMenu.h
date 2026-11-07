#pragma once

#include "Menu.h"
#include "NiFixedString.h"

class NiNode;
class CreditNode;
class CreditSceneNode;
class CreditString;
class CreditTextureName;
class CreditTextureSource;
class OutputA;

class CreditsMenu : public Menu
{
public:
    struct NiNodePtr
    {
        NiNode* m_pObject;
        ~NiNodePtr();
        operator NiNode*() const;
        NiNode* operator->() const;
    };

    struct CreditNodePtr
    {
        CreditSceneNode* data;
        void FUN_0066b0d0(CreditSceneNode*);
        CreditSceneNode* Modelloader_GetReferencedThis();
    };

    struct NiFixedStringArray
    {
        int unk00;
        int unk04;
        int unk08;
        int unk0C;
        int unk10;
        ~NiFixedStringArray();
        unsigned int GetSize();
        NiFixedString& GetAt(unsigned int);
    };

    struct CreditColor
    {
        float r, g, b, a;
    };

    struct CreditBackgrounds
    {
        void FUN_007614c0(const CreditTextureName&);
    };

    CreditsMenu();
    virtual ~CreditsMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);

    union
    {
        Tile* m_pFirstTile;
        Tile* tile;
    };
    union
    {
        Tile* m_pCurrentLineTile;
        Tile* m_pSecondTile;
        Tile* background;
    };
    union
    {
        struct
        {
            NiNodePtr m_pController;
        };
        CreditNodePtr root;
    };
    union
    {
        unsigned int cursor;
        unsigned int index;
        unsigned int m34;
        unsigned int m_34;
    };
    union
    {
        unsigned int length;
        unsigned int m38;
        int m_38;
    };
    union
    {
        char* buffer;
        char* text;
        char* m3c;
        char* m_3c;
    };
    int font;
    union
    {
        int align;
        int iAlignment;
    };
    union
    {
        int x;
        int iX;
    };
    union
    {
        int y;
        int iY;
    };
    CreditColor color;
    union
    {
        struct
        {
            NiFixedStringArray kLines;
        };
        CreditBackgrounds backgrounds;
        struct
        {
            unsigned char unk60[0x10];
            union
            {
                unsigned int m_uiPlaybackFlags;
                int height;
            };
        };
    };
    float fLineDelay;
    float m_fPackageValue;
    unsigned int uiLineIndex;

    int FUN_0075f1c0();
    void FUN_0075f910();
    bool IsKeyHandled(int, int);
    bool IsWellFormedMenu();
    void InitCreditsRoot();
    void AdvanceToNewline();
    void SkipKey();
    void WriteTextUntilDelimiter(OutputA*);
    void WriteTextUntilDelimiter(CreditString&);
    CreditNode* CreateImage(CreditTextureSource*, int, int, float);
    CreditSceneNode* CreateImage(const CreditString&, int, int, float);
};
