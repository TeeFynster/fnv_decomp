// Declarations used only by fallout_shared/bgsradiation.cpp.
#ifndef FNV_BGS_RADIATION_DECLS_H
#define FNV_BGS_RADIATION_DECLS_H

extern unsigned int DAT_011ca87c;
extern BGSRadiationStage** DAT_011ca880;
BGSRadiationStage* BGSRadiationStage_GetStage(unsigned int index);
void InsertRadiationStage(BGSRadiationStage* stage);
extern "C" void* __cdecl __RTDynamicCast(void* source, long vfDelta, void* sourceType, void* targetType,
                                         int isReference);
#endif
