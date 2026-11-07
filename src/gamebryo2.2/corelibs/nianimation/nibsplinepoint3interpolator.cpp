// gamebryo2.2/corelibs/nianimation/nibsplinepoint3interpolator.cpp: NiBSplinePoint3Interpolator, NiBSplineTransformInterpolator (13 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiBSplinePoint3Interpolator.h"
#include "../../../../include/NiBSplineTransformInterpolator.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/StrArr.h"

// The shared header declares these helpers but does not yet expose the stream state.
inline void NiBinaryStream::ReadUInt(unsigned int& value)
{
    unsigned int size = 4;
    reinterpret_cast<unsigned int*>(this)[1] +=
        (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 8))(
            this, &value, 4, &size, 1);
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
{
    unsigned int written =
        (*reinterpret_cast<NIBINARYSTREAM_WRITEFN*>(reinterpret_cast<char*>(this) + 12))(
            this, p, n, sizes, count);
    reinterpret_cast<unsigned int*>(this)[1] += written;
    return written;
}

// Loads the base interpolator, the point3 value, and the control point handle from the stream.
// @fnv 0x00a50910
void NiBSplinePoint3Interpolator::LoadBinary(NiStream& stream)
{
    NiBSplineInterpolator::LoadBinary(stream);
    m_kPoint3Value.LoadBinary(stream);
    (*reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x24c))->ReadUInt(m_kPoint3CPHandle);
}

// The shared base header does not yet declare its clone-copy helper.
struct BSplineCloneBase
{
    void __thiscall FUN_00a57fd0(BSplineCloneBase*, CloningProcess&);
};

// Calls FUN_00a57fd0, then copies the four int fields at offsets 0x1C-0x28 from this into dest.
// @fnv 0x00a50680
void NiBSplineTransformInterpolator::CopyUnknownFields(NiBSplineTransformInterpolator* dest, CloningProcess& process)
{
    reinterpret_cast<BSplineCloneBase*>(this)->FUN_00a57fd0(
        reinterpret_cast<BSplineCloneBase*>(dest), process);
    int* p = (int*)this;
    int* d = (int*)dest;
    d[7] = p[7];
    d[8] = p[8];
    d[9] = p[9];
    d[10] = p[10];
}

// These file-local entry points provide routines not yet declared by the shared header.
extern char const* const g_011f4014_arg1;

// @fnv 0x00a506b0
void* __fastcall NiBSplinePoint3Interpolator_GetRTTI(NiBSplinePoint3Interpolator*, void*)
{
    return (void*)&g_011f4014_arg1;
}

void __fastcall FUN_00a57f80(void*);
void __cdecl __Dummy_00b6fef0(void*, int);

// @fnv 0x00a506f0
void* __fastcall NiBSplinePoint3Interpolator_Destroy(NiBSplinePoint3Interpolator* self, void*, unsigned char a2)
{
    FUN_00a57f80(self);
    if (a2 & 1)
        __Dummy_00b6fef0(self, 0x2c);
    return self;
}

// @fnv 0x00a50640
unsigned int __fastcall NiBSplinePoint3Interpolator_GetChannelValue(NiBSplinePoint3Interpolator* self, void*, unsigned short usChannel)
{
    if (usChannel != 0)
        return 0xFFFF;
    return self->m_kPoint3CPHandle;
}

// @fnv 0x00a50660
void __fastcall NiBSplinePoint3Interpolator_SetPoint3ControlHandle(NiBSplinePoint3Interpolator* self, void*, unsigned int kControlHandle, unsigned short usChannel)
{
    if (!usChannel)
        self->m_kPoint3CPHandle = kControlHandle;
}

extern int DAT_010996dc;
struct FUN_00a57f20_shell
{
    void __thiscall FUN_00a57f20(int, int);
};

// @fnv 0x00a50840
// src: EXE 0x00a50840
void* __cdecl NiBSplinePoint3Interpolator_CreateObject()
{
    void* p = BSFadeNode::operator new(0x2c);
    if (p)
    {
        ((FUN_00a57f20_shell*)p)->FUN_00a57f20(0, 0);
        *(void**)p = &DAT_010996dc;
        *(int*)((char*)p + 0x28) = 0xffff;
    }
    else
    {
        p = 0;
    }
    return p;
}

// @fnv 0x00a506c0
void* __fastcall NiBSplinePoint3Interpolator_Construct(NiBSplinePoint3Interpolator* self, void*, int a1, int aiValue, int a3)
{
    ((FUN_00a57f20_shell*)self)->FUN_00a57f20(a1, a3);
    *(void**)self = (void*)&DAT_010996dc;
    self->m_kPoint3CPHandle = aiValue;
    return self;
}

// @fnv 0x00a507e0
NiObject* __fastcall NiBSplinePoint3Interpolator_Clone(NiBSplinePoint3Interpolator* self, void*, CloningProcess& kCloning)
{
    NiBSplinePoint3Interpolator* pkObject = (NiBSplinePoint3Interpolator*)BSFadeNode::operator new(44);
    if (pkObject)
    {
        ((FUN_00a57f20_shell*)pkObject)->FUN_00a57f20(0, 0);
        *(int*)pkObject = (int)&DAT_010996dc;
        pkObject->m_kPoint3CPHandle = 0xffff;
    }
    else
    {
        pkObject = 0;
    }
    reinterpret_cast<BSplineCloneBase*>(self)->FUN_00a57fd0(
        reinterpret_cast<BSplineCloneBase*>(pkObject), kCloning);
    int* dest = reinterpret_cast<int*>(&pkObject->m_kPoint3Value);
    const int* source = reinterpret_cast<const int*>(&self->m_kPoint3Value);
    dest[0] = source[0];
    dest[1] = source[1];
    dest[2] = source[2];
    pkObject->m_kPoint3CPHandle = self->m_kPoint3CPHandle;
    return (NiObject*)pkObject;
}

struct Base
{
    void FUN_00a58200(NiViewerStringsArray*);
};

char* __cdecl _FUN_00a7d330(char const*);
char* __cdecl NiGetViewerString_00a7d510(char const*, unsigned int);

// @fnv 0x00a50960
void __fastcall NiBSplinePoint3Interpolator_GetViewerStrings(NiBSplinePoint3Interpolator* self, void*, StrArr* pkStrings)
{
    reinterpret_cast<Base*>(self)->FUN_00a58200(
        reinterpret_cast<NiViewerStringsArray*>(pkStrings));

    char* pcString = _FUN_00a7d330(g_011f4014_arg1);

    {
        unsigned int index = pkStrings->m_usSize;

        if (index >= pkStrings->m_usMaxSize)
            pkStrings->SetSize(index + pkStrings->m_usGrowBy);

        pkStrings->SetAt(index, pcString);
    }

    pcString = NiGetViewerString_00a7d510("m_kPoint3CPHandle", self->m_kPoint3CPHandle);

    {
        unsigned int index = pkStrings->m_usSize;

        if (index >= pkStrings->m_usMaxSize)
            pkStrings->SetSize(index + pkStrings->m_usGrowBy);

        pkStrings->SetAt(index, pcString);
    }
}

struct BSplineData
{
    void __thiscall FUN_00a52550(float time, float* output, int components, int offset, int handle);
};
// @fnv 0x00a50710
bool __fastcall NiBSplinePoint3Interpolator_SampleBSpline(NiBSplinePoint3Interpolator* self, void*, float time, int aiUnused, NiPoint3* output)
{
    NiPoint3& lastValue = *reinterpret_cast<NiPoint3*>(&self->m_kPoint3Value);
    if (self->m_fLastTime == time)
    {
        *output = lastValue;
        return true;
    }
    if (self->m_kPoint3CPHandle != 0xffff)
    {
        float sample[3];
        reinterpret_cast<BSplineData*>(self->m_spTransformData.m_pObject)->FUN_00a52550(
            (time - self->m_fStartTime) / (self->m_fEndTime - self->m_fStartTime), sample, 3,
            reinterpret_cast<int>(self->m_spSplineBasisData.m_pObject), self->m_kPoint3CPHandle);
        NiPoint3 value;
        value.x = sample[0];
        value.y = sample[1];
        value.z = sample[2];
        lastValue = value;
    }
    *output = lastValue;
    self->m_fLastTime = time;
    return true;
}

template <class T>
inline void A50880BinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A50880SaveBinary(NiStream& kStream, const T& value)
{
    A50880BinaryStreamSave(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x250), &value);
}

struct A50880Color
{
    float r;
    float g;
    float b;

    void SaveBinary(NiStream& kStream);
};

class A50880Base
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;

    void SaveToStream(NiStream& kStream);
};

// SaveBinary
// @fnv 0x00a50880
void __fastcall NiBSplinePoint3Interpolator_SaveBinary(NiBSplinePoint3Interpolator* self, void*, NiStream& kStream)
{
    reinterpret_cast<A50880Base*>(self)->SaveToStream(kStream);
    reinterpret_cast<A50880Color*>(&self->m_kPoint3Value)->SaveBinary(kStream);
    A50880SaveBinary(kStream, self->m_kPoint3CPHandle);
}

struct S_00a508d0_Sub
{
    int unk00;
    int unk04;
    int unk08;
    bool FUN_00439090(S_00a508d0_Sub* p);
};

struct BSplineEqualityBase
{
    bool FUN_00a57e90(BSplineEqualityBase* p);
};

// @fnv 0x00a508d0
bool __fastcall NiBSplinePoint3Interpolator_IsEqual(NiBSplinePoint3Interpolator* self, void*, NiBSplinePoint3Interpolator* pOther)
{
    if (!reinterpret_cast<BSplineEqualityBase*>(self)->FUN_00a57e90(reinterpret_cast<BSplineEqualityBase*>(pOther)))
        return false;
    if (reinterpret_cast<S_00a508d0_Sub*>(&self->m_kPoint3Value)->FUN_00439090(
            reinterpret_cast<S_00a508d0_Sub*>(&pOther->m_kPoint3Value)))
        return false;
    bool r = pOther->m_kPoint3CPHandle == self->m_kPoint3CPHandle;
    return r;
}
