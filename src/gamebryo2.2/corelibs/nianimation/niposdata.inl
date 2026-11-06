// Fallout: New Vegas - original source reconstruction.
// Source unit:
//   d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niposdata.inl
//
// Covered function (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x004a3760  NiPosData::ComputePositionAtTime (static member)  (77 bytes)
//
// ComputePositionAtTime scales the position pIn by fTime into pOut through the out-of-line
// NiPoint3::Set member function and hands back the destination.  The static
// member is called across translation units (call at 0x004a3371), so it is
// emitted here out of line.
#ifndef FNV_NIPOSDATA_INL
#define FNV_NIPOSDATA_INL

#include "../../../../include/NiPosData.h"
// @fnv 0x004a3760
NiPoint3* NiPosData::ComputePositionAtTime(NiPoint3* pOut, float fTime, const NiPoint3* pIn)
{
    pOut->Set(fTime * pIn->x, fTime * pIn->y, fTime * pIn->z);
    return pOut;
}
#endif
