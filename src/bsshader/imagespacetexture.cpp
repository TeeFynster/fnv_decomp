// bsshader/imagespacetexture.cpp: free functions (1 function)

#include "imagespacetexture_decls.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/TESEnchantableForm.h"

// @fnv 0x0041fd00
void TESEnchantableForm::SetCastingType(int aeCastingType)
{
    m_eCastingType = static_cast<MagicSystem__CastingType>(aeCastingType);
}
