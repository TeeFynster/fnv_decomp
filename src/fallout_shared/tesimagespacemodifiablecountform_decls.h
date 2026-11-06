// fallout_shared/tesimagespacemodifiablecountform_decls.h: declares TESImageSpaceModifiableCountForm_6_
#ifndef TESIMAGESPACEMODIFIABLECOUNTFORM_DECLS_H
#define TESIMAGESPACEMODIFIABLECOUNTFORM_DECLS_H

#include "../../include/BGSCameraPath.h"
#include "../../include/TESForm.h"
#include "../../include/TESImageSpaceModifier.h"

class TESImageSpaceModifiableCountForm_6_
{
  public:
    void* vtable;
    TESImageSpaceModifier* m_pImageSpaceModifier[6];
    void InitItem(TESForm* owner);
};
extern const char DAT_0101cc80[];
extern const char DAT_0101cc30[];
extern const char DAT_0101cbe8[];
int __cdecl Warning(const char*, ...);
#endif
