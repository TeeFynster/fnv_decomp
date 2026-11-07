// gamebryo2.2/corelibs/nianimation/nibsplinetransforminterpolator.cpp: NiBSplineTransformInterpolator, SplineWork, BSplineTransformLoad (15 functions)

#include "../../../../include/NiBSplineInterpolator.h"
#include "../../../../include/NiBSplineTransformInterpolator.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/BSFadeNode.h"
#include <string.h>
#include <new>

inline void NiBinaryStream::ReadScalar(void* value, unsigned int size)
{
    unsigned int componentSize = size;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, value, size, &componentSize, 1);
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
{
    unsigned int written = m_pfnWrite(this, p, n, sizes, count);
    m_uiAbsoluteCurrentPos += written;
    return written;
}

inline NiQuatTransform& NiQuatTransform::operator=(const NiQuatTransform& rhs)
{
    memcpy(this, &rhs, sizeof(*this));
    return *this;
}

// Declaration-only adapters supply entry points absent from the shared headers.
// All object storage and virtual slots come from the shared classes.
class InterpolatorCalls : public NiInterpolator
{
public:
    void ConstructInterpolator();
    void CopyInterpolatorFields(NiBSplineInterpolator*, CloningProcess&);
};
class BSplineInterpolatorCalls : public NiBSplineInterpolator
{
public:
    void CopyBSplineFields(NiBSplineInterpolator*, CloningProcess&);
    bool EqualBSplineFields(NiBSplineInterpolator*);
    void DestroyBSplineInterpolator();
    void SaveBSplineFields(NiStream&);
    void AddBSplineViewerStrings(NiViewerStringsArray*);
};
class BSplineTransformConstruction : public NiBSplineTransformInterpolator
{
public:
    BSplineTransformConstruction(int, unsigned short, unsigned short, unsigned short, int) throw();
};
class BSplineBasisCalls : public NiBSplineBasisData
{
public:
    NiBSplineBasisData* CloneBasis(CloningProcess&);
};
class QuatTransformCalls : public NiQuatTransform
{
public:
    bool EqualQuatTransform(const NiQuatTransform*);
};
// Loads the base interpolator and transform, then reads the translation, rotation and scale handles from the stream.
// @fnv 0x00a50470
void NiBSplineTransformInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineInterpolator::LoadBinary(stream);
    m_kDefaultTransform.LoadBinary(stream);
    stream.m_pkIstr->ReadScalar(&m_kTransCPHandle, 4);
    stream.m_pkIstr->ReadScalar(&m_kRotCPHandle, 4);
    stream.m_pkIstr->ReadScalar(&m_kScaleCPHandle, 4);
}

// Maps channel 0 to 3, 1 to 4 and 2 to 1, returning 0 for any other channel.
// @fnv 0x00a4fde0
// src: XBOX_PDB 0x00a4fde0
unsigned int __stdcall NiBSplineTransformInterpolator_GetDimension(unsigned short usChannel)
{
    switch (usChannel)
    {
    case 0:
        return 3;
    case 1:
        return 4;
    case 2:
        return 1;
    }
    return 0;
}

// Returns 3 for channels 0, 1 and 2, and 0 for any other channel value.
// @fnv 0x00a4fe20
// src: XBOX_PDB 0x00a4fe20
unsigned int __stdcall NiBSplineTransformInterpolator_GetDegree(unsigned short usChannel)
{
    switch (usChannel)
    {
    case 0:
        return 3;
    case 1:
        return 3;
    case 2:
        return 3;
    }
    return 0;
}


// Returns the stored handle for channel 0, 1 or 2 (translation, rotation, scale), or 0xffff for any other channel.
// @fnv 0x00a4fe50
unsigned int __fastcall GetChannelHandle(NiBSplineTransformInterpolator* self, int, unsigned short usChannel)
{
    switch (usChannel)
    {
    case 0:
        return self->m_kTransCPHandle;
    case 1:
        return self->m_kRotCPHandle;
    case 2:
        return self->m_kScaleCPHandle;
    }
    return 0xffff;
}


// Stores kControlHandle into the translation, rotation or scale control-point handle field selected by usChannel (0, 1 or 2).
// @fnv 0x00a4fe80
void __fastcall SetControlPointHandle(NiBSplineTransformInterpolator* self, int, unsigned int kControlHandle,
                                      unsigned short usChannel)
{
    switch (usChannel)
    {
    case 0:
        self->m_kTransCPHandle = kControlHandle;
        break;
    case 1:
        self->m_kRotCPHandle = kControlHandle;
        break;
    case 2:
        self->m_kScaleCPHandle = kControlHandle;
        break;
    }
}

extern double _DAT_010241b0;

// Returns true when the given channel has no control points and its stored value differs from _DAT_010241b0; false otherwise.
// @fnv 0x00a50090
// src: XBOX_PDB 0x00a50090
bool __fastcall NiBSplineTransformInterpolator_GetChannelPosed(NiBSplineTransformInterpolator* self, int, unsigned short usChannel)
{
    switch (usChannel)
    {
    case 0:
        if (self->vf56(usChannel) > 0)
            return false;
        return self->m_kDefaultTransform.x != _DAT_010241b0;
    case 1:
        if (self->vf56(usChannel) > 0)
            return false;
        return self->m_kDefaultTransform.qy != _DAT_010241b0;
    case 2:
        if (self->vf56(usChannel) > 0)
            return false;
        return self->m_kDefaultTransform.scale != _DAT_010241b0;
    default:
        return false;
    }
}




// @fnv 0x00a50110
// src: XBOX_PDB 0x00a50110
NiBSplineTransformInterpolator* __fastcall NiBSplineTransformInterpolator_CreateClone(NiBSplineTransformInterpolator* self, int, CloningProcess* kCloning)
{
    NiBSplineTransformInterpolator* pkObject = ::new (BSFadeNode::operator new(sizeof(NiBSplineTransformInterpolator))) BSplineTransformConstruction(0, 0xffff, 0xffff, 0xffff, 0);
    reinterpret_cast<BSplineInterpolatorCalls*>(self)->CopyBSplineFields(pkObject, *kCloning);
    pkObject->m_kDefaultTransform = self->m_kDefaultTransform;
    pkObject->m_kTransCPHandle = self->m_kTransCPHandle;
    pkObject->m_kRotCPHandle = self->m_kRotCPHandle;
    pkObject->m_kScaleCPHandle = self->m_kScaleCPHandle;
    return pkObject;
}

// Allocates and constructs a spline transform interpolator with invalid control-point handles.
// @fnv 0x00a50180
// src: EXE 0x00a50180
NiBSplineTransformInterpolator* NiBSplineTransformInterpolator_CreateObject()
{
    return ::new (BSFadeNode::operator new(sizeof(NiBSplineTransformInterpolator))) BSplineTransformConstruction(0, 0xffff, 0xffff, 0xffff, 0);
}



// Returns true if the object passes FUN_00a57e90, its quaternion matches, and the trans, rot and scale CP handles all match the other object's.
// @fnv 0x00a501b0
// src: GAMEBRYO_LIB 0x00a501b0
bool __fastcall NiBSplineTransformInterpolator_IsEqual(NiBSplineTransformInterpolator* self, int, NiBSplineTransformInterpolator* pkObject)
{
    if (reinterpret_cast<BSplineInterpolatorCalls*>(self)->EqualBSplineFields(pkObject) && static_cast<QuatTransformCalls&>(self->m_kDefaultTransform).EqualQuatTransform(&pkObject->m_kDefaultTransform) &&
        pkObject->m_kTransCPHandle == self->m_kTransCPHandle && pkObject->m_kRotCPHandle == self->m_kRotCPHandle &&
        pkObject->m_kScaleCPHandle == self->m_kScaleCPHandle)
        return true;
    return false;
}

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);



// @fnv 0x00a50070
NiBSplineTransformInterpolator* __fastcall DestroyBSplineTransform(NiBSplineTransformInterpolator* self, int, unsigned char acFlags)
{
    reinterpret_cast<BSplineInterpolatorCalls*>(self)->DestroyBSplineInterpolator();
    if (acFlags & 1)
    {
        FUN_00aa1460(self, sizeof(NiBSplineTransformInterpolator));
    }
    return self;
}

struct SplineVector
{
    float x, y, z;
    SplineVector(float a, float b, float c) : x(a), y(b), z(c)
    {}
};
struct SplineQuaternion
{
    float w, x, y, z;
    SplineQuaternion(float a, float b, float c, float d)
    {
        Set(a, b, c, d);
    }
    void Set(float, float, float, float);
    void NormalizeQuaternion();
};
inline bool IsTransformValid(const NiQuatTransform& transform)
{
    return transform.scale != -3.4028234663852886e+38 || transform.qy != -3.4028234663852886e+38 ||
           transform.x != -3.4028234663852886e+38;
}
class BSplineDataCalls : public NiBSplineData
{
public:
    void EvaluateSplineData(float, float*, unsigned, NiBSplineBasisData*, unsigned);
};
// Samples translation, rotation and scale from the spline data at the given time, caches the transform, and returns whether it is valid.
// @fnv 0x00a50200
bool __fastcall EvaluateSpline(NiBSplineTransformInterpolator* self, int, float time, void*, NiQuatTransform& output)
{
    if (self->m_fLastTime == time)
    {
        output = self->m_kDefaultTransform;
        if (!IsTransformValid(self->m_kDefaultTransform))
            return false;
        return true;
    }
    float ratio = (time - self->m_fStartTime) / (self->m_fEndTime - self->m_fStartTime);
    float values[4];
    if (self->m_kTransCPHandle != 0xffff)
    {
        static_cast<BSplineDataCalls*>(self->m_spTransformData.m_pObject)->EvaluateSplineData(ratio, values, 3, self->m_spSplineBasisData.m_pObject, self->m_kTransCPHandle);
        reinterpret_cast<SplineVector&>(self->m_kDefaultTransform.x) = SplineVector(values[0], values[1], values[2]);
    }
    if (self->m_kRotCPHandle != 0xffff)
    {
        static_cast<BSplineDataCalls*>(self->m_spTransformData.m_pObject)->EvaluateSplineData(ratio, values, 4, self->m_spSplineBasisData.m_pObject, self->m_kRotCPHandle);
        SplineQuaternion quat(values[0], values[1], values[2], values[3]);
        quat.NormalizeQuaternion();
        reinterpret_cast<SplineQuaternion&>(self->m_kDefaultTransform.qx) = quat;
    }
    if (self->m_kScaleCPHandle != 0xffff)
    {
        static_cast<BSplineDataCalls*>(self->m_spTransformData.m_pObject)->EvaluateSplineData(ratio, values, 1, self->m_spSplineBasisData.m_pObject, self->m_kScaleCPHandle);
        self->m_kDefaultTransform.scale = values[0];
    }
    output = self->m_kDefaultTransform;
    if (!IsTransformValid(self->m_kDefaultTransform))
        return false;
    self->m_fLastTime = time;
    return true;
}

template <class T>
inline void SaveBinaryScalar(NiBinaryStream& stream, const T* value, unsigned int count = 1)
{
    unsigned int size = sizeof(T);
    stream.BinaryWrite(value, count * size, &size, 1);
}

template <class T> inline void SaveBinaryValue(NiStream& stream, const T& value)
{
    SaveBinaryScalar(*stream.m_pkOstr, &value);
}

// Saves the base interpolator, default transform and control-point handles.
// @fnv 0x00a503e0
void __fastcall SaveBSplineTransform(NiBSplineTransformInterpolator* self, int, NiStream& stream)
{
    reinterpret_cast<BSplineInterpolatorCalls*>(self)->SaveBSplineFields(stream);
    self->m_kDefaultTransform.SaveBinary(&stream);
    SaveBinaryValue(stream, self->m_kTransCPHandle);
    SaveBinaryValue(stream, self->m_kRotCPHandle);
    SaveBinaryValue(stream, self->m_kScaleCPHandle);
}

extern unsigned int _DAT_011f3fe4;
extern unsigned char _DAT_010996bc;
extern unsigned char _DAT_010996ac;
extern unsigned char _DAT_01099698;
unsigned int __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int);
unsigned int __cdecl NiGetViewerString_00a7d510(const unsigned char*, unsigned int);

#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"
// Loads the base interpolator, the quaternion transform and the translation, rotation and scale handles from the stream.
// @fnv 0x00a50500
void __fastcall GetBSplineTransformViewerStrings(NiBSplineTransformInterpolator* self, int, NiViewerStringsArray* strings)
{
    reinterpret_cast<BSplineInterpolatorCalls*>(self)->AddBSplineViewerStrings(strings);
    NiViewerStringsArray& pos = *strings;
    const char* value = (const char*)NiViewerStrings_NiGetViewerString_Title(_DAT_011f3fe4);
    unsigned int index = pos.m_usSize;
    if (index >= pos.m_usMaxSize)
        pos.SetSize(index + pos.m_usGrowBy);
    pos.SetAt(index, value);

    self->m_kDefaultTransform.GetViewerStrings(strings);
    value = (const char*)NiGetViewerString_00a7d510(&_DAT_010996bc, self->m_kTransCPHandle);
    index = pos.m_usSize;
    if (index >= pos.m_usMaxSize)
        pos.SetSize(index + pos.m_usGrowBy);
    pos.SetAt(index, value);

    value = (const char*)NiGetViewerString_00a7d510(&_DAT_010996ac, self->m_kRotCPHandle);
    index = pos.m_usSize;
    if (index >= pos.m_usMaxSize)
        pos.SetSize(index + pos.m_usGrowBy);
    pos.SetAt(index, value);

    value = (const char*)NiGetViewerString_00a7d510(&_DAT_01099698, self->m_kScaleCPHandle);
    index = pos.m_usSize;
    if (index >= pos.m_usMaxSize)
        pos.SetSize(index + pos.m_usGrowBy);
    pos.SetAt(index, value);
}

extern float g_fInitA;
extern float g_fInitB;
extern int g_vtable_00a57f20;
extern long(__stdcall* g_pfnInterlockedIncrement)(long volatile* value);

// @fnv 0x00a57f20
NiBSplineInterpolator* __fastcall ConstructBSplineInterpolator(NiBSplineInterpolator* self, int, NiBSplineData* pFirst, NiBSplineBasisData* pSecond)
{
    reinterpret_cast<InterpolatorCalls*>(self)->ConstructInterpolator();
    self->m_fStartTime = g_fInitA;
    long(__stdcall * pfnInterlockedIncrement)(long volatile*) = g_pfnInterlockedIncrement;
    self->m_fEndTime = g_fInitB;
    *(int**)self = &g_vtable_00a57f20;
    self->m_spTransformData.m_pObject = pFirst;
    if (pFirst != 0)
    {
        pfnInterlockedIncrement((long volatile*)((char*)pFirst + 4));
    }
    self->m_spSplineBasisData.m_pObject = pSecond;
    if (pSecond != 0)
    {
        pfnInterlockedIncrement((long volatile*)((char*)pSecond + 4));
    }
    return self;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

// @fnv 0x00a57fd0
void BSplineInterpolatorCalls::CopyBSplineFields(NiBSplineInterpolator* target, CloningProcess& cloning)
{
    NiBSplineInterpolator* source = this;
    reinterpret_cast<InterpolatorCalls*>(source)->CopyInterpolatorFields(target, cloning);
    target->m_fEndTime = source->m_fEndTime;
    *reinterpret_cast<volatile float*>(&target->m_fStartTime) = *reinterpret_cast<volatile float*>(&source->m_fStartTime);

    NiBSplineData* previous = *reinterpret_cast<NiBSplineData* volatile*>(&target->m_spTransformData.m_pObject);
    if (previous != source->m_spTransformData.m_pObject)
    {
        if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        target->m_spTransformData.m_pObject = source->m_spTransformData.m_pObject;
        if (target->m_spTransformData.m_pObject)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&target->m_spTransformData.m_pObject->m_uiRefCount));
    }

    if (source->m_spSplineBasisData.m_pObject)
    {
        NiBSplineBasisData* clone = static_cast<BSplineBasisCalls*>(source->m_spSplineBasisData.m_pObject)->CloneBasis(cloning);
        NiBSplineBasisData* existing = target->m_spSplineBasisData.m_pObject;
        if (existing != clone)
        {
            if (existing && InterlockedDecrement(reinterpret_cast<volatile long*>(&existing->m_uiRefCount)) == 0)
                existing->DeleteThis();
            target->m_spSplineBasisData.m_pObject = clone;
            if (clone)
                InterlockedIncrement(reinterpret_cast<volatile long*>(&clone->m_uiRefCount));
        }
    }
}
