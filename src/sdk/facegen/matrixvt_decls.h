#include "../../../include/FaceGenMatrix.h"
// sdk/facegen/matrixvt_decls.h: declares FaceGenCoordinateValue, FR2MatrixVTCData, FaceGenCoordinateBasis
#ifndef ARMY_LUNA_2061_MATRIXVT_DECLS_H
#define ARMY_LUNA_2061_MATRIXVT_DECLS_H


#include "matrixvt_types_FR2MatrixVTC_float_.h"
struct FaceGenCoordinateValue
{
  public:
    unsigned int value;
    unsigned int layoutPadding;
    const float* NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt();
};

class FR2MatrixVTCData
{
  public:
    float* first;
    float* last;
    float* end;
    unsigned int layoutPadding0;
    unsigned int layoutPadding1;
    unsigned int layoutPadding2;
    void SetElementCount(unsigned int count);
};

class FaceGenCoordinateBasis
{
  public:
    FaceGenCoordinateValue ForwardCall_0060b370(unsigned int row, unsigned int col);
};

template <class T> class FaceGenMatrix;



void __cdecl ReportAssertionViolation(const char* file, unsigned int line);
float __cdecl SquareFloat(float value);

#endif
