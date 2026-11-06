
//
// The covered PC function at 0x00568e50 is a two-call accessor:
//
//     return GetExtraData()->GetExtraRadioData();
//
// non-virtual TESObjectREFR::GetExtraData() getter returns its address.
// The linker folds that getter with every other identical
// "return &this->member" getter, which is why the BSFile vtable slot 6
// resolves to the same address.  ExtraDataList::GetExtraRadioData() looks the
// radio extra up by its type index and hands back its data pointer.

#include "layout_support.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/ExtraDataList.h"

// @fnv 0x00568e50
ExtraRadioData* TESObjectREFR::GetExtraRadioData()
{
    return GetExtraData()->GetExtraRadioData();
}
