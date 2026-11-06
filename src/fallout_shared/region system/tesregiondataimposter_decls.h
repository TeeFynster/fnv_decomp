// fallout_shared/region system/tesregiondataimposter_decls.h: local imposter and list declarations
#ifndef FNV_TESREGIONDATAIMPOSTER_DECLS_H
#define FNV_TESREGIONDATAIMPOSTER_DECLS_H


#include "../../../include/BSSimpleList.h"

class TESForm;
class QuantityData;

#include "../../../include/TESFile.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESTopicInfoData.h"

template <int N> struct EndianSizeTag
{
};
void BSEndian(unsigned int* value, EndianSizeTag<4>);
void* __cdecl operator new[](unsigned int size);
void __cdecl operator delete[](void* data);

#endif
