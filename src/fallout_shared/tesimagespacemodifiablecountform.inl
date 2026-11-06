
#include "tesimagespacemodifiablecountform_decls.h"
// @fnv 0x005820a0
void TESImageSpaceModifiableCountForm_6_::InitItem(TESForm* owner)
{
    for (unsigned int i = 0; i < 6; ++i) {
        if (m_pImageSpaceModifier[i]) {
            unsigned int formID = (unsigned int)m_pImageSpaceModifier[i];
            if (owner)
                TESForm::RemapFormIDForFile(formID, owner->GetFile(-1));
            m_pImageSpaceModifier[i] = dynamic_cast<TESImageSpaceModifier*>(TESForm::GetFormByID(formID));
            if (!m_pImageSpaceModifier[i]) {
                if (owner) {
                    if (((BGSCameraPath*)owner)->HasNameForWarning())
                        Warning(DAT_0101cc80, formID, owner->GetName());
                    else
                        Warning(DAT_0101cc30, formID, owner->GetFormID());
                } else
                    Warning(DAT_0101cbe8, formID);
            }
        }
    }
}
