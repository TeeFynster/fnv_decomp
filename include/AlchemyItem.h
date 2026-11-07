#pragma once

#include "MagicItemObject.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "BGSMessageIcon.h"
#include "TESScriptableForm.h"
#include "TESWeightForm.h"
#include "BGSEquipType.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSPickupPutdownSounds.h"

class SpellItem;
class TESSound;

class AlchemyItem : public MagicItemObject,
                    public TESModelTextureSwap,
                    public TESIcon,
                    public BGSMessageIcon,
                    public TESScriptableForm,
                    public TESWeightForm,
                    public BGSEquipType,
                    public BGSDestructibleObjectForm,
                    public BGSPickupPutdownSounds
{
public:
    AlchemyItem();
    virtual ~AlchemyItem();

    virtual void ClearData();
    void ResetFormData();
    virtual void InitItem();

    void* CombatController_GetTarget();
    int CombatController_GetTarget(int, int, bool);
    bool AlchemyItem_IsFlagSet(unsigned int);
    bool AlchemyItem_IsFlagSet(int);
    bool FUN_00981420();
    void SetSound(TESSound* sound);
    unsigned int GetFieldC8();
    void FUN_00874460(SpellItem* item);

    union
    {
        unsigned char formData[0x20];
        struct
        {
            int unk0B8;
            unsigned char unk0BC;
            unsigned char unkBD[3];
            int unk0C0;
            float unk0C4;
            int unk0C8;
            unsigned char unkCC[0xC];
        };
    };
};
