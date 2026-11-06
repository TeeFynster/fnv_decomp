// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSDEFAULTOBJECTMANAGER_H
#define FNV_BGSDEFAULTOBJECTMANAGER_H

#include "layout_support.h"
#include "../../include/TESForm.h"
#include "../../include/DEFAULT_OBJECT.h"
FNV_STATIC_ASSERT(sizeof(BGSDefaultObjectManager) == 160);
FNV_STATIC_ASSERT(offsetof(BGSDefaultObjectManager, m_apDefaultObjects) == 24);
#endif
