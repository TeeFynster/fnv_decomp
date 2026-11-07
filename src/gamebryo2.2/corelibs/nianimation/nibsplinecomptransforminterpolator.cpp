// gamebryo2.2/corelibs/nianimation/nibsplinecomptransforminterpolator.cpp (11 functions)
#include "NiRefObject_inline.h"

#include "../../../../include/StrArr.h"
#include "../../../../include/NiBSplineCompTransformInterpolator.h"
#include "../../../../include/NiBSplineData.h"
#include "../../../../include/NiBSplineInterpolator.h"
#include "../../../../include/NiBSplineTransformInterpolator.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiQuaternion.h"
// NiStream.h currently supplies BSStreamHeader itself; BSStreamHeader.h duplicates that definition.
#include "../../../../include/NiStream.h"
#include "NiMemObject.h"
#include <string.h>

inline NiQuatTransform& NiQuatTransform::operator=(const NiQuatTransform& rhs)
{
    memcpy(this, &rhs, sizeof(*this));
    return *this;
}

inline NiQuaternion& NiQuaternion::operator=(const NiQuaternion& rhs)
{
    memcpy(this, &rhs, sizeof(*this));
    return *this;
}

inline void NiBinaryStream::ReadComp(void* value, unsigned int size, unsigned int componentSize)
{
    unsigned int uiComponentSize = componentSize;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, value, size, &uiComponentSize, 1);
}

extern double _DAT_010241b0;

// NiBSplineInterpolator's copy helper is not declared by the shared header.
struct SplineBaseOperations
{
    void CopyTo(NiBSplineInterpolator*, CloningProcess&);
    void Construct(int, int);
};

// @fnv 0x00a51140
void NiBSplineCompTransformInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineTransformInterpolator::LoadBinary(stream);

    stream.m_pkIstr->ReadComp(m_afOffsetAndHalfRange, 0x18, 4);
}

// Copies the spline transform interpolator's translation, rotation and scale control-point handles and an extra field into destination.
// @fnv 0x00a4fec0
__declspec(noinline) void NiBSplineCompTransformInterpolator::CopyMemberData(NiBSplineCompTransformInterpolator* destination,
                                                        CloningProcess& cloningProcess)
{
    reinterpret_cast<SplineBaseOperations*>(this)->CopyTo(destination, cloningProcess);
    destination->m_kDefaultTransform = m_kDefaultTransform;
    destination->m_kTransCPHandle = m_kTransCPHandle;
    destination->m_kRotCPHandle = m_kRotCPHandle;
    destination->m_kScaleCPHandle = m_kScaleCPHandle;
}

// @fnv 0x00a50f60
bool NiBSplineCompTransformInterpolator::Update(float time, NiObjectNET* target, NiQuatTransform& value)
{
    if (m_fLastTime == time)
    {
        NiQuatTransform* transformValue = &m_kDefaultTransform;
        value = *transformValue;
        if (transformValue->scale == _DAT_010241b0 && transformValue->qy == _DAT_010241b0 &&
            transformValue->x == _DAT_010241b0)
            return false;
        return true;
    }

    float normalizedTime = (time - m_fStartTime) / (m_fEndTime - m_fStartTime);
    float decodedValue[4];
    NiPoint3 translation;
    if (m_kTransCPHandle != 0xffff)
    {
        m_spTransformData.m_pObject->CalculateSplineValue(normalizedTime, decodedValue, 3,
                                                          m_spSplineBasisData.m_pObject, m_kTransCPHandle,
                                                          m_afOffsetAndHalfRange[0], m_afOffsetAndHalfRange[1]);
        translation.x = decodedValue[0];
        translation.y = decodedValue[1];
        translation.z = decodedValue[2];
        memcpy(&m_kDefaultTransform.x, &translation, sizeof(translation));
    }
    if (m_kRotCPHandle != 0xffff)
    {
        m_spTransformData.m_pObject->CalculateSplineValue(normalizedTime, decodedValue, 4,
                                                          m_spSplineBasisData.m_pObject, m_kRotCPHandle,
                                                          m_afOffsetAndHalfRange[2], m_afOffsetAndHalfRange[3]);
        NiQuaternion& rotation = *reinterpret_cast<NiQuaternion*>(&m_kDefaultTransform.qx);
        rotation = *reinterpret_cast<NiQuaternion*>(decodedValue);
        rotation.EnsureCanonicalSign();
    }
    if (m_kScaleCPHandle != 0xffff)
    {
        m_spTransformData.m_pObject->CalculateSplineValue(normalizedTime, decodedValue, 1,
                                                          m_spSplineBasisData.m_pObject, m_kScaleCPHandle,
                                                          m_afOffsetAndHalfRange[4], m_afOffsetAndHalfRange[5]);
        m_kDefaultTransform.scale = decodedValue[0];
    }

    NiQuatTransform* transformValue = &m_kDefaultTransform;
    value = *transformValue;
    if (transformValue->scale == _DAT_010241b0 && transformValue->qy == _DAT_010241b0 &&
        transformValue->x == _DAT_010241b0)
        return false;
    m_fLastTime = time;
    return true;
}

void __fastcall FUN_00a57f80(void* pThis);

// Calls the spline base destructor, then frees pThis when flags has bit 0 set.
// @fnv 0x00a50e50
void* __fastcall FUN_00a50e50(void* pThis, int, unsigned int flags)
{
    FUN_00a57f80(pThis);
    if (flags & 1)
    {
        NiMemObject::operator delete(pThis, 0x60);
    }
    return pThis;
}

extern int g_011f4004;

// @fnv 0x00a50e40
// src: COMMUNITY 0x00a50e40
int* __cdecl NiBSplineCompTransformInterpolator_GetRTTI()
{
    return &g_011f4004;
}

struct SplineTransformOperations
{
    bool IsEqual(NiObject*);
    void SaveBinary(NiStream&);
    NiBSplineTransformInterpolator* Construct(int, int, int, int, int);
};
// @fnv 0x00a50e00
bool __fastcall IsEqualCompTransform(NiBSplineCompTransformInterpolator* self, int, NiObject* pkObject)
{
    NiBSplineCompTransformInterpolator* pkDest;
    unsigned int ui;
    if (!reinterpret_cast<SplineTransformOperations*>(self)->IsEqual(pkObject))
        return false;
    pkDest = (NiBSplineCompTransformInterpolator*)pkObject;
    for (ui = 0; ui < 6; ui++)
    {
        if (self->m_afOffsetAndHalfRange[ui] != pkDest->m_afOffsetAndHalfRange[ui])
            return false;
    }
    return true;
}

extern int g_011f4004;
char* _FUN_00a7d330(const char*);
struct Holder
{
    void LoadBSplineTransform(StrArr*);
    void AppendString(StrArr*);
};
// @fnv 0x00a511c0
void Holder::AppendString(StrArr* pkStrings)
{
    LoadBSplineTransform(pkStrings);
    char* s = _FUN_00a7d330((const char*)g_011f4004);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiCapacity = pkStrings->m_usMaxSize;
    if (uiSize >= uiCapacity)
    {
        unsigned int grow = pkStrings->m_usGrowBy;
        pkStrings->SetSize(uiSize + grow);
    }
    pkStrings->SetAt(uiSize, s);
}

// @fnv 0x00a51180
void __fastcall SaveCompTransform(NiBSplineCompTransformInterpolator* self, int, NiStream& stream)
{
    reinterpret_cast<SplineTransformOperations*>(self)->SaveBinary(stream);
    NiBinaryStream* __restrict output = stream.m_pkOstr;
    unsigned int size = 4;
    output->m_uiAbsoluteCurrentPos += output->m_pfnWrite(output, self->m_afOffsetAndHalfRange, 0x18, &size, 1);
}

extern int DAT_011a8400;
extern int DAT_011a8404;
extern int DAT_011a8408;
extern int DAT_011f3704;
extern int DAT_011f3708;
extern int DAT_011f370c;
extern int DAT_011f3710;
extern float DAT_01096b8c;
extern int DAT_0109957c;

// The shared classes do not declare the parameterized constructors. Keep the
// original thiscall entry point here, operating on their checked layouts.
// @fnv 0x00a4fff0
NiBSplineTransformInterpolator* SplineTransformOperations::Construct(int aiArg1, int aiArg2, int aiArg3,
                                                                    int aiArg4, int aiArg5)
{
    NiBSplineTransformInterpolator* self = reinterpret_cast<NiBSplineTransformInterpolator*>(this);
    reinterpret_cast<SplineBaseOperations*>(self)->Construct(aiArg1, aiArg5);
    *reinterpret_cast<int*>(self) = (int)&DAT_0109957c;
    reinterpret_cast<int&>(self->m_kDefaultTransform.x) = DAT_011a8400;
    reinterpret_cast<int&>(self->m_kDefaultTransform.y) = DAT_011a8404;
    reinterpret_cast<int&>(self->m_kDefaultTransform.z) = DAT_011a8408;
    reinterpret_cast<int&>(self->m_kDefaultTransform.qx) = DAT_011f3704;
    reinterpret_cast<int&>(self->m_kDefaultTransform.qy) = DAT_011f3708;
    reinterpret_cast<int&>(self->m_kDefaultTransform.qz) = DAT_011f370c;
    reinterpret_cast<int&>(self->m_kDefaultTransform.qw) = DAT_011f3710;
    self->m_kDefaultTransform.scale = DAT_01096b8c;
    self->m_kTransCPHandle = aiArg2;
    self->m_kRotCPHandle = aiArg3;
    self->m_kScaleCPHandle = aiArg4;
    return self;
}

static const float NI_INFINITY = 3.402823466e+38f;
extern int DAT_0109991c;

__forceinline NiBSplineCompTransformInterpolator* NewCompTransform()
{
    NiBSplineCompTransformInterpolator* result =
        static_cast<NiBSplineCompTransformInterpolator*>(NiObject::operator new(sizeof(NiBSplineCompTransformInterpolator)));
    if (result)
    {
        reinterpret_cast<SplineTransformOperations*>(result)->Construct(0, 0xffff, 0xffff, 0xffff, 0);
        // Keep vtable installation before the range stores, as in the original constructor.
        *reinterpret_cast<volatile int*>(result) = (int)&DAT_0109991c;
        volatile float* ranges = result->m_afOffsetAndHalfRange;
        ranges[0] = NI_INFINITY;
        ranges[1] = NI_INFINITY;
        ranges[2] = NI_INFINITY;
        ranges[3] = NI_INFINITY;
        ranges[4] = NI_INFINITY;
        ranges[5] = NI_INFINITY;
        return result;
    }
    return 0;
}

// @fnv 0x00a50f00
NiBSplineTransformInterpolator* __cdecl CreateEvaluator()
{
    return NewCompTransform();
}

// @fnv 0x00a50e70
NiBSplineCompTransformInterpolator* __fastcall CloneCompTransform(NiBSplineCompTransformInterpolator* self, int,
                                                                CloningProcess& cloning)
{
    NiBSplineCompTransformInterpolator* destination = NewCompTransform();
    self->CopyMemberData(destination, cloning);
    destination->m_afOffsetAndHalfRange[0] = self->m_afOffsetAndHalfRange[0];
    destination->m_afOffsetAndHalfRange[1] = self->m_afOffsetAndHalfRange[1];
    destination->m_afOffsetAndHalfRange[2] = self->m_afOffsetAndHalfRange[2];
    destination->m_afOffsetAndHalfRange[3] = self->m_afOffsetAndHalfRange[3];
    destination->m_afOffsetAndHalfRange[4] = self->m_afOffsetAndHalfRange[4];
    destination->m_afOffsetAndHalfRange[5] = self->m_afOffsetAndHalfRange[5];
    return destination;
}
