#ifndef IMAGESPACEMANAGER_ARRAY_H
#define IMAGESPACEMANAGER_ARRAY_H
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTArray.h"
#include "NiMemObject.h"
// yUI CommonLib/Gamebryo/NiTArray.hpp. Boolean receiver evidence: the
// DepthOfFieldTextures::kTextureStates field and covered caller at b8bc20.
typedef char ImageSpaceTextureStates_size_check[(sizeof(NiTArray<bool, NiTMallocInterface<bool> >) == 16) ? 1 : -1];
#endif
