// fallout_shared/teswaterform_decls.h: unit-local helpers and external declarations
#ifndef FNV_TESWATERFORM_DECLS_H
#define FNV_TESWATERFORM_DECLS_H

#include "layout_support.h"
#include "../../include/TESForm.h"

TESForm* __cdecl GetFormByID(unsigned int);
int __cdecl Warning(const char*, ...);
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern int DAT_01184118;

extern float g_splatterDefaultSecond;
extern float DAT_010249d8;
extern float DAT_0101b268;
extern float DAT_010313d4;
extern float DAT_01013974;
extern float DAT_01018180;
extern float DAT_010231a4;
extern float DAT_010162c0;
extern float DAT_010231a8;
extern float DAT_010181bc;
extern float DAT_01013d84;
extern float DAT_0101b2d0;
extern float DAT_01022958;

template <int N> struct EndianSizeTag
{
};
void BSEndian(unsigned int*, EndianSizeTag<4>);
#include <malloc.h>

#endif
