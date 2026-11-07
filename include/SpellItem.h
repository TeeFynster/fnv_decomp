#pragma once

#include "MagicItemForm.h"

class SpellItem : public MagicItemForm
{
public:
    SpellItem();
    virtual ~SpellItem();
    virtual void ClearData();

    void ResetFormData();
    void SetValue(int value);
    int GetField38();
    int ContainsAnyFlag(unsigned int mask);
    bool FUN_0040e210(int flag);
    bool FUN_0040e210(unsigned int flag);
    bool ActiveEffect_IsExtendDuration();
    bool ContainsAnyFlag_Thunk();

    union
    {
        unsigned char spellData[0x10];
        char data_db[0x10];
        struct
        {
            unsigned int spellType;
            int cost;
            unsigned int level;
            unsigned char flags;
            unsigned char unk41[3];
        };
    };
};
