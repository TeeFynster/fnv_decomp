#pragma once

#include "ListBoxBase.h"
#include "BSSimpleList.h"

class Tile;
template <class T> class ListBoxItem;

// src: XBOX_PDB (ListBox<int>, sizeof 48); RTTI gives ListBoxBase and BSSimpleList<ListBoxItem<T>*> bases.
// Vftable 0x0107286c: six base slots, then destructor, RemoveAll and Sort.
template <class T>
    class ListBox : public ListBoxBase, public BSSimpleList<ListBoxItem<T>*>
    {
    public:
        unsigned int AddItem(unsigned int mask);
        bool Highlight(Tile* tile);
        void ResetItems();
        unsigned int GetVisibleEntryCount();
        bool SetSelection(Tile* tile);
        bool SetSelection(Tile* tile, int mode);
        virtual ~ListBox();
        virtual void RemoveAll();
        virtual void Sort(int (__cdecl* apCompare)(ListBoxItem<T>*, ListBoxItem<T>*));

        Tile* m_pListTile;
        Tile* m_pSelectedTile;
        Tile* m_pHighlightedTile;
        const char* pTemplateName;
        unsigned short m_usSelectedIndex;
        unsigned short unk1E;
        float m_fFirstListValue;
        float m_fSecondListValue;
        float m_fThirdListValue;
        unsigned short usFlags;
        unsigned short unk2E;

        ListBox();
        void Initialize(Tile* apParent, const char* apTemplateName);
        Tile* AddItem(T aData, const char* apTemplateName,
                      int (__cdecl* apCompare)(ListBoxItem<T>*, ListBoxItem<T>*), const char* apName);
        bool RemoveItem(Tile* apTile);
        bool RemoveAt(unsigned int auiIndex, bool abFiltered);
        bool IsListItem(Tile* apTile);
        bool IsListItem(void* apTile);
        bool IsEmpty();
        T GetSelectedData();
        T GetSelectedData(Tile* apTile);
        T GetDataAt(unsigned int auiIndex, bool abFiltered);
        Tile* GetTileForData(const T& aData);
        Tile* GetTileForData(T& aData);
        unsigned int NumItems();
        unsigned int CountUnfilteredItems();
        void SetEnabled(bool abEnabled);
        bool IsEnabled();
        T GetHighlightedData();
        void ClearHighlight();
        void SetHighlightEnabled(bool abHighlight);
        ListBoxItem<T>* GetAt(unsigned int auiIndex, bool abFiltered);
        void SetFlag(int aeFlag, bool abSet);
        bool GetFlag(int aeFlag);
        bool ListBox_StartMenu_Option_IsEnabled();
        void Traverse(void (__cdecl* apCallback)(Tile*, T), int aiFirst, int aiLast);
        void vfn_00();
        Tile* GetSelectedTile();
        void Filter(bool (__cdecl* apFilter)(T));
        void SetSelectedTile(Tile* apTile, bool abSelected);
        void ClearSelection(bool abClear);
        void BSSimpleArray_BSStringT_char_1024_BSSimpleArray();
        void FUN_007a1c90();
        void FUN_007a27f0();
        void FUN_007a36e0();
        void FUN_007a43a0();
        void FUN_007a50f0();
        void ListBox_TESQuest_SetEnabled(bool a);
        void SetEnabledTrait(bool a);
        void ListBox_BGSNote_SetEnabled(bool a);
        void ListBox_BGSNote_SetVisible(bool a);
        void ListBox_TESChallenge_SetEnabled(bool a);
        void FUN_007312e0();
        Tile* FindItemData(T& item);
        void UpdateScrollSelection(bool a);
        int GetFilteredCount(int a);
        Tile* ListBox_unsigned_int_GetLastItem();
        Tile* GetNextEnabledTile(int aiKey);
        void AddTile(Tile* apTile);
        void ListBox_TESRecipe_SetTotalListHeight();
        Tile* ListBox_TESRecipe_GetLastItem();
        void RefreshHighlight();
        void vfn_08();
        void vfn_0c();
        using ListBoxBase::GetTileAt;
        Tile* GetTileAt(int index, bool a);
    };
