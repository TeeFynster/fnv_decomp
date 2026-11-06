#ifndef FNV_NITFIXEDSTRINGMAP_DECLS_H
#define FNV_NITFIXEDSTRINGMAP_DECLS_H

#include "layout_support.h"
#include "NiFixedString.h"

class NiAVObject;
extern NiFixedString EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

#include "../../../../include/NiTFixedStringMap.h"
typedef NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString, NiAVObject*> >, NiAVObject*> NiAVObjectFixedStringMap;
typedef NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString, const char*> >, const char*> NiCharFixedStringMap;
FNV_STATIC_ASSERT(sizeof(NiAVObjectFixedStringMap) == 16);
FNV_STATIC_ASSERT(offsetof(NiAVObjectFixedStringMap, m_uiHashSize) == 4);
FNV_STATIC_ASSERT(offsetof(NiAVObjectFixedStringMap, m_ppkHashTable) == 8);
FNV_STATIC_ASSERT(offsetof(NiAVObjectFixedStringMap, m_kItemCount) == 12);
#endif
