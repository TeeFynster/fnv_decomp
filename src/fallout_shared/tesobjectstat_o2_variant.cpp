// TESObjectSTAT destructor adjustment thunk, compiled with /O2.

#include "tesobjectstat_load.h"
#include "../../include/FileEntryList.h"
#include "../../include/ShortPoint3.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESBoundObject__BOUND_DATA.h"
#include "../../include/TESGlobal.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESObject.h"
#include "../../include/TESObjectSTAT.h"

// Emitting the real class's vtables also emits the secondary-base destructor
// adjustment thunk at 0x0051b6d0, which subtracts 0x30 from this.
TESObjectSTAT::TESObjectSTAT()
{
    SetFormType((ENUM_FORM_ID)0x20);
    m_cType = (char)0xFF;
    m_pSoundForm = 0;
}
