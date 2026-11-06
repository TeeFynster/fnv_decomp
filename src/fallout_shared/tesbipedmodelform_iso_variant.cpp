// src/fallout_shared/tesbipedmodelform_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesbipedmodelform.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include "tesbipedmodelform_decls.h"
#include "layout_support.h"
#include "../../include/TESForm.h"
#include "tesbipedmodelform_types_TESBipedModelForm.h"
#include "tesbipedmodelform_types_BIPED_OBJECT.h"
#include "tesbipedmodelform_types_SEX.h"
#include "tesbipedmodelform_types_BGSBipedModelList.h"

class FUN_00480400
{
  public:
    virtual ~FUN_00480400();
    void FreeModels();

    BipedModelForm m_kBipedModelForm;
    TESModelTextureSwap bipedModel[2];
    TESModelTextureSwap groundModel[2];
    TESIcon icon[2];
    BGSMessageIcon messageIcon[2];
    TESModelRDT modelRDT;
};

// @fnv 0x00480400
FUN_00480400::~FUN_00480400()
{
    FreeModels();
}
