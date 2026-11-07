#pragma once

#include "Menu.h"
#include "ListBoxBase.h"
#include "BSSimpleList.h"

class BGSPerk;
class PerkRankList;

// TraitMenu (FNV menu class 1084): ctor 0x007e6780 installs vftable 0x010779bc; MenuSystem::GetMenuById allocates 0x8c.
class TraitMenu : public Menu
{
public:
    template <class T> struct ListBoxItem;

    class PerkListBoxStorage : public ListBoxBase
    {
    public:
        ~PerkListBoxStorage();

        virtual void vf06();
        virtual void vf07();
        virtual void Sort(int (__cdecl*)(ListBoxItem<BGSPerk*>*, ListBoxItem<BGSPerk*>*));

        BSSimpleList<ListBoxItem<BGSPerk*>*> m_kItems;
        Tile* m_pListTile;
        Tile* m_pSelectedTile;
        Tile* m_pHighlightedTile;
        const char* pTemplateName;
        unsigned short m_usSelectedIndex;
        unsigned char unk1E[2];
        float m_fFirstListValue;
        float m_fSecondListValue;
        float m_fThirdListValue;
        unsigned short usFlags;
        unsigned char unk2E[2];

        void Initialize(Tile*, const char*);
        Tile* AddItemTile(BGSPerk*, const char*, int, int);
        Tile* Selected();
        bool IsSelected(Tile*);
        void Deselect(Tile*);
        void Select(Tile*);
        int GetSelectedCount();
        void Traverse(void (__cdecl*)(Tile*), int, int);
        void Traverse(void (__cdecl*)(Tile*, void*), int, int);
        void UpdateScrollTile(bool);
        BGSPerk* GetItemForTile(Tile*);
        PerkRankList* FindItemData(Tile*);
    };

    class PerkListBox
    {
    public:
        virtual bool Highlight(Tile*);
        virtual Tile* GetHighlightedItem();
        virtual Tile* GetTileForButton(int);
        virtual bool BelongsTo(const Menu*);
        virtual void ScrollToHighlight();
        virtual Tile* GetTileAt(unsigned int, bool);
        virtual void vf06();
        virtual void vf07();
        virtual void Sort(int (__cdecl*)(ListBoxItem<BGSPerk*>*, ListBoxItem<BGSPerk*>*));

        unsigned char unk04[0x2C];

        void Initialize(Tile*, const char*);
        Tile* AddItemTile(BGSPerk*, const char*, int, int);
        Tile* Selected();
        bool IsSelected(Tile*);
        void Deselect(Tile*);
        void Select(Tile*);
        int GetSelectedCount();
        void Traverse(void (__cdecl*)(Tile*), int, int);
        void Traverse(void (__cdecl*)(Tile*, void*), int, int);
        void UpdateScrollTile(bool);
        BGSPerk* GetItemForTile(Tile*);
        PerkRankList* FindItemData(Tile*);
    };

    // BSSimpleList<BGSPerk*> node at +0x84: the ctor 0x007e6780 builds it with the two-dword list ctor 0x0096a2d0.
    class PerkList
    {
    public:
        BGSPerk* unk00;
        PerkList* next;

        ~PerkList();
        void AddTail(BGSPerk*&);
    };

    TraitMenu();
    virtual ~TraitMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);
    virtual bool HandleControllerInput(int, Tile*);

    int GetMenuID_007e68a0();
    void DoIdle_007e73c0();
    bool HasAllNineTiles();
    void SetTileById(int, Tile*);
    void PopulatePerkList();
    void UpdateValueDifferenceMessage();
    void UpdatePerkTile(int, Tile*);
    void UpdateEffectChanges(Tile*);
    void RefreshTile(Tile*);
    void UpdatePerkList();
    void HandleTileAction(int, Tile*);
    bool HandleKey(int, int);
    bool HandleButton(int, float);

    union
    {
        unsigned char layoutExtension[0x64];
        struct
        {
            union
            {
                Tile* m_pTiles[9];
                struct
                {
                    Tile* tile28;
                    Tile* tile2c;
                    Tile* tile30;
                    Tile* tile34;
                    Tile* tile38;
                    union { Tile* tile3c; Tile* tile3C; };
                    union { Tile* tile40; Tile* m_40; };
                    Tile* tile44;
                    union { Tile* tile48; Tile* scroll; };
                };
            };
            union { int firstValue; int selected; int iNumSelected; };
            union { int lastValue; int count; int iMaxSelected; };
            union
            {
                struct { PerkListBox box; };
                struct { PerkListBox list54; };
                struct { PerkListBox kList; };
                struct { PerkListBox list; };
                struct { PerkListBoxStorage entries; };
            };
            PerkList perks;
        };
    };
};
