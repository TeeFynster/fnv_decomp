// gamebryo2.2/corelibs/nianimation/nibsplinedata.cpp: NiBSplineData (7 functions)

#include "../../../../include/NiBSplineBasisData.h"
#include "../../../../include/NiBSplineData.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiStream.h"
#include "nibsplinedata_decls.h"

// Preserve the per-transfer component size temporary used by the stream callbacks.
inline unsigned int* ComponentSize(const unsigned int& size)
{
    return const_cast<unsigned int*>(&size);
}

// Reads the control point count and compact control point count from the stream, allocating and reading the corresponding float and short arrays.
// @fnv 0x00a52870
void NiBSplineData::LoadBinary(NiStream& stream)
{
    ReadGroup(stream);

    NiBinaryStream* pStream = stream.m_pkIstr;
    unsigned int* puiControlPointCount = &m_uiControlPointCount;
    pStream->m_uiAbsoluteCurrentPos += pStream->m_pfnRead(pStream, puiControlPointCount, 4, ComponentSize(4), 1);
    if (*puiControlPointCount)
    {
        float* pfControlPoints = (float*)_NiMalloc_00aa1070(*puiControlPointCount * 4);
        unsigned int controlPointBytes = *puiControlPointCount * 4;
        m_pfControlPoints = pfControlPoints;
        pStream = stream.m_pkIstr;
        pStream->m_uiAbsoluteCurrentPos += pStream->m_pfnRead(
            pStream, pfControlPoints, controlPointBytes, ComponentSize(4), 1);
    }

    pStream = stream.m_pkIstr;
    puiControlPointCount = &m_uiCompactControlPointCount;
    pStream->m_uiAbsoluteCurrentPos += pStream->m_pfnRead(pStream, puiControlPointCount, 4, ComponentSize(4), 1);
    if (*puiControlPointCount)
    {
        short* psCompactControlPoints = (short*)_NiMalloc_00aa1070(*puiControlPointCount * 2);
        unsigned int compactControlPointBytes = *puiControlPointCount * 2;
        m_psCompactControlPoints = psCompactControlPoints;
        pStream = stream.m_pkIstr;
        pStream->m_uiAbsoluteCurrentPos += pStream->m_pfnRead(
            pStream, psCompactControlPoints, compactControlPointBytes, ComponentSize(2), 1);
    }
}

// Evaluates the B-spline at the given time using the basis weights and control points, accumulating the weighted result into value.
// @fnv 0x00a526b0
void NiBSplineData::CalculateSplineValue(float time, float* value, unsigned int dimension,
                                         NiBSplineBasisData* basisData, unsigned int handle, float offset,
                                         float halfRange)
{
    NiBSplineBasis_float_3_& basis = basisData->GetBSplineBasis();
    int iCount, max;
    basis.Compute(time, iCount, max);
    float points[16];
    NiCompUtility_DecompressFloatArray(m_psCompactControlPoints + dimension * iCount + handle, dimension * 4, offset, halfRange, points,
                 dimension * 4);
    unsigned int index = 0;
    time = basis.weights[0];
    for (unsigned int j = 0; j < dimension; ++j)
        value[j] = points[index++] * time;
    int i = iCount + 1;
    if (i <= max)
    {
        float* pfNextWeight = &basis.weights[i - iCount];
        iCount = max - i + 1;
        do
        {
            time = *pfNextWeight;
            for (unsigned int j = 0; j < dimension; ++j)
                value[j] += points[index++] * time;
            ++pfNextWeight;
        } while (--iCount);
    }
}

extern int DAT_01099e54;
void __cdecl _NiFreeAlias(void*);
void __fastcall FUN_00a5d3d0(void*);
void __cdecl FUN_00aa1460(void*, unsigned int);

// @fnv 0x00a52510
void* __fastcall FUN_00a52510(void** pThis, int, unsigned int flags)
{
    *pThis = &DAT_01099e54;
    _NiFreeAlias(pThis[2]);
    _NiFreeAlias(pThis[3]);
    FUN_00a5d3d0(pThis);
    if (flags & 1)
    {
        FUN_00aa1460(pThis, 0x18);
    }
    return pThis;
}

// @fnv 0x00a51e50
bool __fastcall IsSplineDataEqual(NiBSplineData* self, int, NiObject* pkObject)
{
    if (self->NiObject::IsSameAs(pkObject))
    {
        NiBSplineData* pkData = static_cast<NiBSplineData*>(pkObject);
        if (pkData->m_uiControlPointCount == self->m_uiControlPointCount &&
            pkData->m_uiCompactControlPointCount == self->m_uiCompactControlPointCount)
            return true;
    }
    return false;
}

template <class T> inline void WriteSplineValue(NiBinaryStream* stream, T* value)
{
    unsigned int size = sizeof(T);
    stream->m_uiAbsoluteCurrentPos += stream->m_pfnWrite(stream, value, sizeof(T), &size, 1);
}

inline void NiBinaryStream::BinaryWrite(const void* buffer, unsigned int totalBytes, unsigned int elementSize)
{
    unsigned int size = elementSize;
    m_uiAbsoluteCurrentPos += m_pfnWrite(this, buffer, totalBytes, &size, 1);
}

// Saves the base spline data, then writes the control point count and array, followed by the compact control points.
// @fnv 0x00a52950
void __fastcall SaveSplineControlPoints(NiBSplineData* self, int, NiStream& stream)
{
    self->NiObject::SaveBinary(stream);
    WriteSplineValue(stream.m_pkOstr, &self->m_uiControlPointCount);
    if (self->m_uiControlPointCount != 0)
    {
        void* buf = self->m_pfControlPoints;
        unsigned int bytes = self->m_uiControlPointCount * 4;
        stream.m_pkOstr->BinaryWrite(buf, bytes, 4);
    }
    WriteSplineValue(stream.m_pkOstr, &self->m_uiCompactControlPointCount);
    if (self->m_uiCompactControlPointCount != 0)
    {
        stream.m_pkOstr->BinaryWrite(self->m_psCompactControlPoints, self->m_uiCompactControlPointCount * 2, 2);
    }
}

extern void* g_011f4034;
extern const char str_01099f08[];
extern const char str_01099ee8[];

void* __cdecl NiViewerStrings_NiGetViewerString_Title(void* pv);
void* __cdecl NiGetViewerString_00a7d510(const char* pcName, unsigned int uiValue);

struct ArrayArg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void FUN_0096ad30(unsigned int uiNewEnd);
    void FUN_0096ae90(unsigned int uiPos, void* pvData);
};

// @fnv 0x00a52a20
void __fastcall GetSplineViewerStrings(NiBSplineData* self, int, ArrayArg& kStream)
{
    self->NiObject::AddViewerStrings(reinterpret_cast<NiViewerStringsArray*>(&kStream));
    {
        void* p = NiViewerStrings_NiGetViewerString_Title(g_011f4034);
        unsigned int uiPos = kStream.m_0a;
        if (uiPos >= kStream.m_08)
        {
            kStream.FUN_0096ad30(uiPos + kStream.m_0e);
        }
        kStream.FUN_0096ae90(uiPos, &p);
    }
    {
        void* q = NiGetViewerString_00a7d510(str_01099f08, self->m_uiControlPointCount);
        unsigned int uiPos = kStream.m_0a;
        if (uiPos >= kStream.m_08)
        {
            kStream.FUN_0096ad30(uiPos + kStream.m_0e);
        }
        kStream.FUN_0096ae90(uiPos, &q);
    }
    {
        void* r = NiGetViewerString_00a7d510(str_01099ee8, self->m_uiCompactControlPointCount);
        unsigned int uiPos = kStream.m_0a;
        if (uiPos >= kStream.m_08)
        {
            kStream.FUN_0096ad30(uiPos + kStream.m_0e);
        }
        kStream.FUN_0096ae90(uiPos, &r);
    }
}

// Evaluates a B-spline at fTime by accumulating weighted control points into afPos using basis weights and uiDimension.
// @fnv 0x00a52550
void __fastcall CalculateSplineValue(NiBSplineData* self, int, float fTime, float* afPos, unsigned int uiDimension,
                                     NiBSplineBasisData* pkBasisData, unsigned int uiControlPointOffset)
{
    NiBSplineBasis_float_3_& kBasis = pkBasisData->GetBSplineBasis();
    int iMax;
    int& iMin = (int&)fTime;
    kBasis.Compute(fTime, iMin, iMax);

    const int iFirst = iMin;
    const float* pkSource = &self->m_pfControlPoints[uiControlPointOffset + iFirst * uiDimension];
    float fBasisValue = kBasis.weights[0];
    unsigned int j;
    for (j = 0; j < uiDimension; j++)
        afPos[j] = fBasisValue * (*pkSource++);

    int i = iFirst + 1;
    if (i <= iMax)
    {
        const float* pfW = &kBasis.weights[i - iFirst];
        int& n = iMin;
        n = iMax - i + 1;
        do
        {
            fBasisValue = *pfW;
            for (j = 0; j < uiDimension; j++)
                afPos[j] += fBasisValue * (*pkSource++);
            pfW++;
        } while (--n);
    }
}
