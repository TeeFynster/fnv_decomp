#pragma once

#if !defined(FNV64_BSSIMPLELIST_DEFINED) && !defined(FNV_EXTRADATAOBJECTS_PRIVATE_LAYOUT_SUPPORT_H)
#include "BSSimpleList.h"
#endif
#include "MagicTarget.h"

class BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
class Modifier;
class ModifierPointerList;

class ActorValueModifierList : public BSSimpleList<Modifier*>
{
public:
    bool m_bAllowZeroValueModifiers;
    unsigned char layoutPadding9;
    unsigned short layoutPaddingA;
    ModifierPointerList* m_ppModifiedActorValues;

    enum ClampStyle
    {
        ClampNone = 0
    };

    ActorValueModifierList();
    ~ActorValueModifierList();

    Modifier* GetModifierItem(char key);
    float GetActorValueModifierAmount(char key, bool& found);
    float GetActorValueModifierAmount(char key);
    void ModifyModifier(char key, float delta, ClampStyle clamp);
    void ModifierList_SetModifier(char key, float value);
    static float ModifyAndClamp(float value, float delta, ClampStyle clamp);
    void EraseModifier(Modifier* modifier);
    void CopyModifierListFrom(ActorValueModifierList* other);
    void AppendModifier(Modifier* modifier);
    void RemoveAllModifiers();
    void AddFastModifier(char key, Modifier* modifier);
    void ModifierList_SaveGameBGS(BGSSaveFormBuffer* buffer);
    void Revert();
    void LoadGame(BGSLoadFormBuffer* buffer);
    void InitLoadGame(BGSLoadFormBuffer* buffer);
};
