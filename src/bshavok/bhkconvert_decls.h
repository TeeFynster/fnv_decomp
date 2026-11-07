#include "../../include/BSSimpleList.h"
#pragma once

#include "../../include/NiPoint3.h"
#include "../../include/NiTransform.h"
#include "../../include/hkRotation.h"
#include "../../include/hkTransform.h"

class BGSPerkEntry;

float HK2NI(float);
hkRotation& VisitAndFetchThree(hkRotation&, const NiMatrix3&);
hkVector4& NI2HK(hkVector4&, const NiPoint3&);
