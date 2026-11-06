// fallout/ai/modifierlist_decls.h: declares Modifier
#ifndef FNV_MODIFIERLIST_DECLS_H
#define FNV_MODIFIERLIST_DECLS_H


#include "layout_support.h"
#include "../../../include/ActorValueModifierList.h"

#pragma pack(push, 4)
class Modifier
{
  public:
    char cKey;
    unsigned char padding[3];
    float fValue;

    Modifier(Modifier* other);
    Modifier(char key, float value);
    void SetValue(float value);
    char GetKey();
    float GetValue();
};

class ModifierPointerList
{
  public:
    Modifier** m_ppModifiers;
    ModifierPointerList();
    ModifierPointerList(ModifierPointerList* other);
    void RemoveModifier(int key);
    ~ModifierPointerList();
};

#pragma pack(pop)

void __cdecl operator delete(void* memory);

FNV_STATIC_ASSERT(sizeof(Modifier) == 8);
FNV_STATIC_ASSERT(sizeof(ActorValueModifierList) == 0x10);

#endif
