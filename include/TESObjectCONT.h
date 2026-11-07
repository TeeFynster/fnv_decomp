#pragma once

#include <stddef.h>

#include "TESBoundAnimObject.h"
#include "TESContainer.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESScriptableForm.h"
#include "TESWeightForm.h"
#include "TESMagicCasterForm.h"
#include "TESMagicTargetForm.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSOpenCloseForm.h"
#include "TESObjectCONTData.h"

class TESSound;

class __declspec(novtable) TESObjectCONT : public TESBoundAnimObject,
                                           public TESContainer,
                                           public TESFullName,
                                           public TESModelTextureSwap,
                                           public TESScriptableForm,
                                           public TESWeightForm,
                                           public TESMagicCasterForm,
                                           public TESMagicTargetForm,
                                           public BGSDestructibleObjectForm,
                                           public BGSOpenCloseForm
{
public:
    TESObjectCONT();
    virtual ~TESObjectCONT();

    void ResetFormData();
    bool IsFormInitialized() const;
    void ReadTypedData(TESFile* file, void* data, unsigned short size);
    void SetImpactDataSet_004fb0b0(unsigned int);
    bool Load(TESFile* file);

    // Overrides of primary slots 8 and 34; all 96 slots are inherited.
    virtual bool LoadForm(TESFile* modInfo);
    virtual void InitItem(void);

    unsigned char layoutPadding89[3]; // 0x89
    TESSound* m_pOpenSound;            // 0x8C
    TESSound* m_pSecondarySound;       // 0x90
    TESSound* pLoopingSound;           // 0x94
    TESObjectCONTData Data;           // 0x98
    unsigned char layoutPadding99[3]; // 0x99
};

#if defined(_M_IX86)
typedef char TESObjectCONT_size_check[(sizeof(TESObjectCONT) == 156) ? 1 : -1];
typedef char TESObjectCONT_padding89_offset_check[(offsetof(TESObjectCONT, layoutPadding89) == 137) ? 1 : -1];
typedef char TESObjectCONT_open_sound_offset_check[(offsetof(TESObjectCONT, m_pOpenSound) == 140) ? 1 : -1];
typedef char TESObjectCONT_secondary_sound_offset_check[(offsetof(TESObjectCONT, m_pSecondarySound) == 144) ? 1 : -1];
typedef char TESObjectCONT_looping_sound_offset_check[(offsetof(TESObjectCONT, pLoopingSound) == 148) ? 1 : -1];
typedef char TESObjectCONT_data_offset_check[(offsetof(TESObjectCONT, Data) == 152) ? 1 : -1];
typedef char TESObjectCONT_padding99_offset_check[(offsetof(TESObjectCONT, layoutPadding99) == 153) ? 1 : -1];
#endif
