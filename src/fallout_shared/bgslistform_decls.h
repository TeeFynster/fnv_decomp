#include "../../include/BSSimpleList.h"
// fallout_shared/bgslistform_decls.h: local list interfaces and shared form definitions
#ifndef FNV_BGSLISTFORM_DECLS_H
#define FNV_BGSLISTFORM_DECLS_H

#include "layout_support.h"

#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSLoadGameBuffer.h"
#include "../../include/BGSRadiationStage.h"
#include "../../include/TESForm.h"



#include "../../include/BGSListForm.h"

FNV_STATIC_ASSERT(sizeof(BGSListForm) == 36);
FNV_STATIC_ASSERT(offsetof(BGSListForm, m_kFormList) == 24);
FNV_STATIC_ASSERT(offsetof(BGSListForm, m_uiFormCount) == 32);

int Warning(const char*, ...);
#endif
