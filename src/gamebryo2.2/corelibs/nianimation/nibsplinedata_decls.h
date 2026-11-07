// Private spline basis declarations and allocation helpers for nibsplinedata.cpp.
#ifndef FNV_NIBSPLINEDATA_DECLS_H
#define FNV_NIBSPLINEDATA_DECLS_H

class NiBSplineBasis_float_3_
{
  public:
    int count;
    float weights[4];
    void Compute(float, int&, int&);
};

void* __cdecl _NiMalloc_00aa1070(unsigned int size);
void __cdecl NiCompUtility_DecompressFloatArray(const short*, unsigned int, float, float, float*, unsigned int);
#endif
