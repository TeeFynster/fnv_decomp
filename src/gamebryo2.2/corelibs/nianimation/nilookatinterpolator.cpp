#include "../../../../include/NiLookAtInterpolator.h"
#include "../../../../include/NiAVObjectPalette.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTPointerMap.h"

// src/gamebryo2.2/corelibs/nianimation/nilookatinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nilookatinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3f90;

// @fnv 0x00a4be10
const NiRTTI* NiLookAtInterpolator::GetRTTI() const
{
    return (const NiRTTI*)&g_011f3f90;
}

extern "C" void __cdecl FUN_00a4be20();
extern "C" void __cdecl __Dummy_00b6fef0(void* p, unsigned int flags);

// @fnv 0x00a4c5c0
void* __thiscall NiLookAtInterpolator::FUN_00a4c5c0(unsigned int flags)
{
    FUN_00a4be20();
    if (flags & 1)
    {
        __Dummy_00b6fef0(this, 0x44);
    }
    return this;
}

// @fnv 0x00a4b8d0
bool NiLookAtInterpolator::ResolveTargetObject(NiAVObjectPalette* pkPalette)
{
    if (m_pkLookAt)
        return true;
    NiAVObject* pkTarget = (NiAVObject*)pkPalette->FindAVObject((const NiFixedString&)m_kTargetNodeName);
    if (pkTarget)
    {
        m_pkLookAt = pkTarget;
        return true;
    }
    return false;
}

struct CloningProcess
{
    // Clone lookup 0x00a53c30 is also bound to NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, NiObject*>::GetAt.
    NiTPointerMap<NiObject*, NiObject*>* m_pCloneMap;
};

// @fnv 0x00a4bb80
void __thiscall NiLookAtInterpolator::ProcessClone(CloningProcess& kCloning)
{
    bool bCloned;
    NiObject* pkClone;
    NiLookAtInterpolator* pkDest;
    ((NiObject*)this)->NiObject::ProcessClone(kCloning);
    pkClone = 0;
    kCloning.m_pCloneMap->GetAt(this, pkClone);
    pkDest = (NiLookAtInterpolator*)pkClone;
    bCloned = kCloning.m_pCloneMap->GetAt((NiObject*)m_pkLookAt, pkClone);
    if (bCloned)
        pkDest->m_pkLookAt = (NiAVObject*)pkClone;
    else
        pkDest->m_pkLookAt = m_pkLookAt;
}

struct ObjType
{
    virtual void G0();
    virtual void G1();
    virtual void G2();
    virtual void G3();
    virtual void G4();
    virtual void G5();
    virtual void G6();
    virtual void G7();
    virtual void G8();
    virtual void G9();
    virtual void G10();
    virtual void G11();
    virtual void G12();
    virtual void G13();
    virtual void G14();
    virtual void G15();
    virtual void G16();
    virtual void G17();
    virtual void G18();
    virtual void G19();
    virtual void G20();
    virtual bool RegisterStreamables(NiStream*);
};
struct BaseInterp
{
    bool __thiscall BSTextureSet_RegisterStreamables(NiStream*);
};

// @fnv 0x00a4bbe0
bool __thiscall NiLookAtInterpolator::RegisterStreamables(NiStream& arStream)
{
    NiStream* kStream = &arStream;
    unsigned int ui;
    if (!((BaseInterp*)this)->BSTextureSet_RegisterStreamables(kStream))
        return false;
    for (ui = 0; ui < 3; ++ui)
    {
        ObjType* pkObj = ((ObjType**)m_pItems)[ui];
        if (pkObj)
        {
            if (!pkObj->RegisterStreamables(kStream))
                return false;
        }
    }
    kStream->RegisterFixedString(m_kTargetNodeName);
    return true;
}

// Placement construction uses the allocation already obtained from the game allocator.
inline void* operator new(unsigned int, NiLookAtInterpolator* p) throw() { return p; }

// @fnv 0x00a4c5a0
// src: EXE 0x00a4c5a0
void* __cdecl NiLookAtInterpolator_CreateObject()
{
    void* p = NiLookAtInterpolator::operator new(0x44);
    if (p)
        return ::new ((NiLookAtInterpolator*)p) NiLookAtInterpolator(0, 0, 0);
    return 0;
}

// Iterates three pointers starting at offset 0x38 and calls v47 on each non-null one.
// @fnv 0x00a4b900
void NiLookAtInterpolator::Collapse()
{
    unsigned int ui;
    NiInterpolator** pp = m_pItems;
    for (ui = 3; ui > 0; --ui)
    {
        NiInterpolator* p = *pp;
        if (p)
            p->Collapse();
        pp++;
    }
}

// Calls the two-float virtual method on each of the three NiInterpolator pointers stored at offset 0x38, skipping null entries.
// @fnv 0x00a4b9f0
void __thiscall NiLookAtInterpolator::SetActiveTimeRange(float afValue1, float afValue2)
{
    unsigned int ui;
    for (ui = 0; ui < 3; ui++)
    {
        NiInterpolator* p = m_pItems[ui];
        if (p)
            p->SetActiveTimeRange(afValue1, afValue2);
    }
}

extern "C" const float g_01098b04;
extern "C" const float g_01015f5c;
extern "C" const double g_010231b0;
extern "C" const double g_010241b0;

// @fnv 0x00a4b930
void __thiscall NiLookAtInterpolator::GetItemsRange(float* pfMin, float* pfMax)
{
    float a;
    float b;
    *pfMin = g_01098b04;
    *pfMax = g_01015f5c;
    NiInterpolator** pp = m_pItems;
    unsigned int n = 3;
    do
    {
        NiInterpolator* item = *pp;
        if (item != 0)
        {
            item->GetInterpolatorTimeRange(a, b);
            if (a != b)
            {
                if (*pfMin > a)
                    *pfMin = a;
                if (*pfMax < b)
                    *pfMax = b;
            }
        }
        ++pp;
    } while (--n != 0);
    if (*pfMin == g_010231b0 && *pfMax == g_010241b0)
    {
        *pfMin = 0.0f;
        *pfMax = 0.0f;
    }
}

extern "C" void* g_0109b220;
extern "C" void* g_011f49e0;
void* __cdecl FUN_00a5b690(void* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* pTarget);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* pTarget);

struct RegObj
{
    int m_i00;
    int m_i04;
    void* m_08;
};

// @fnv 0x00a4bae0
bool __fastcall ResolveLookAtName(NiLookAtInterpolator* self)
{
    RegObj* pRegObj = (RegObj*)self->m_pkLookAt;
    void* p = pRegObj->m_08;
    if (p != 0)
    {
        char* pNewHandle = (char*)FUN_00a5b690(p);
        long(__stdcall * pfnDecrement)(volatile long*) = InterlockedDecrement;
        if (self->m_kTargetNodeName.m_kHandle != pNewHandle)
        {
            if (pNewHandle != g_0109b220)
                (void)InterlockedIncrement((volatile long*)((char*)pNewHandle - 8));
            if (self->m_kTargetNodeName.m_kHandle != g_0109b220)
                (void)pfnDecrement((volatile long*)((char*)self->m_kTargetNodeName.m_kHandle - 8));
            self->m_kTargetNodeName.m_kHandle = pNewHandle;
        }
        if (pNewHandle != g_0109b220)
            (void)pfnDecrement((volatile long*)((char*)pNewHandle - 8));
        self->m_pkLookAt = 0;
        return true;
    }
    char* pFallbackHandle = (char*)g_011f49e0;
    if (self->m_kTargetNodeName.m_kHandle != pFallbackHandle)
    {
        if (pFallbackHandle != g_0109b220)
            (void)InterlockedIncrement((volatile long*)((char*)pFallbackHandle - 8));
        if (self->m_kTargetNodeName.m_kHandle != g_0109b220)
            (void)InterlockedDecrement((volatile long*)((char*)self->m_kTargetNodeName.m_kHandle - 8));
        self->m_kTargetNodeName.m_kHandle = pFallbackHandle;
    }
    return false;
}

struct A4BC40Transform
{
    bool operator==(const A4BC40Transform& kOther) const;

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

// The shared interpolator lacks the IsEqual override at 0x00ba87d0.
class A4BC40Base
{
  public:
    bool BaseIsEqual(NiObject* pkObject);
};

// @fnv 0x00a4bc40
bool NiLookAtInterpolator::IsEqual(NiObject* apObject) const
{
    NiObject* pkObject = apObject;
    if (!((A4BC40Base*)this)->BaseIsEqual(pkObject))
        return false;

    const NiLookAtInterpolator* pkData = (const NiLookAtInterpolator*)pkObject;
    if (m_usFlags != pkData->m_usFlags)
        return false;

    if ((m_pkLookAt && !pkData->m_pkLookAt) || (!m_pkLookAt && pkData->m_pkLookAt))
        return false;
    if (m_pkLookAt && pkData->m_pkLookAt && !((const NiObject*)m_pkLookAt)->IsEqual((NiObject*)pkData->m_pkLookAt))
        return false;

    if (!((const A4BC40Transform&)m_kTransform == (const A4BC40Transform&)pkData->m_kTransform))
        return false;

    for (unsigned int i = 0; i < 3; i++)
    {
        const NiObject* pkKey = m_pItems[i];
        NiObject* pkOtherKey = pkData->m_pItems[i];
        if ((pkKey && !pkOtherKey) || (!pkKey && pkOtherKey))
            return false;
        if (pkKey && pkOtherKey && !pkKey->IsEqual(pkOtherKey))
            return false;
    }
    return true;
}

// @fnv 0x00a4c5e0
NiObject* NiLookAtInterpolator::MakeClone(CloningProcess& kCloning)
{
    NiLookAtInterpolator* allocated = static_cast<NiLookAtInterpolator*>(NiLookAtInterpolator::operator new(0x44));
    NiLookAtInterpolator* node = allocated ? ::new (allocated) NiLookAtInterpolator(0, 0, 0) : 0;
    CopyMembers_00a4c4b0(node, kCloning);
    return node;
}

struct Arg_b9286
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m08;
    unsigned short m0a;
    unsigned short m0c;
    unsigned short m0e;
    void __thiscall FUN_0096ad30(unsigned int n);
    void __thiscall FUN_0096ae90(unsigned int n, void** out);
};

struct Holder_b9286
{
    void __thiscall NiQuatTransform_GetViewerStrings(Arg_b9286* a);
    void __thiscall NiInterpolator_GetViewerStrings(Arg_b9286* a);
};

struct Obj_b9286
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void Visit(Arg_b9286* a);
};

extern "C" void* g_011f3f90;
extern "C" void* __cdecl NiViewerStrings_NiGetViewerString_Title(void* p);
extern "C" void* __cdecl NiGetViewerString_00a7d5a0(const char* s, void* p);

// @fnv 0x00a4c780
void NiLookAtInterpolator::GetViewerStrings(NiViewerStringsArray* apStrings)
{
    Arg_b9286* a = (Arg_b9286*)apStrings;
    ((Holder_b9286*)this)->NiInterpolator_GetViewerStrings(a);
    void* p = NiViewerStrings_NiGetViewerString_Title(g_011f3f90);
    unsigned int b = a->m0a;
    unsigned int c = a->m08;
    if (b >= c)
    {
        a->FUN_0096ad30((unsigned int)a->m0e + b);
    }
    a->FUN_0096ae90(b, &p);
    p = NiGetViewerString_00a7d5a0("m_pkLookAt", m_pkLookAt);
    b = a->m0a;
    c = a->m08;
    if (b >= c)
    {
        a->FUN_0096ad30((unsigned int)a->m0e + b);
    }
    a->FUN_0096ae90(b, &p);
    reinterpret_cast<Holder_b9286*>(&m_kTransform)->NiQuatTransform_GetViewerStrings(a);
    Obj_b9286** pp = (Obj_b9286**)m_pItems;
    for (unsigned int i = 3; i != 0; --i)
    {
        Obj_b9286* o = *pp;
        if (o)
        {
            o->Visit(a);
        }
        ++pp;
    }
}

namespace fnv_00eea6d0 { extern char* EmptyFS; }
using fnv_00eea6d0::EmptyFS;

// Assigns kName's handle to the interpolator's name field, incrementing the new string's refcount and decrementing the old one's.
// @fnv 0x00eea6d0
// src: COMMUNITY 0x00eea6d0
void NiLookAtInterpolator::SetLookAtName(const NiFixedString& kName)
{
    char* pcNewHandle = kName.m_kHandle;
    if (m_kTargetNodeName.m_kHandle != pcNewHandle)
    {
        if (pcNewHandle != EmptyFS)
            InterlockedIncrement((long*)(pcNewHandle - 8));
        char* pcOldHandle = m_kTargetNodeName.m_kHandle;
        if (pcOldHandle != EmptyFS)
            InterlockedDecrement((long*)(pcOldHandle - 8));
        m_kTargetNodeName.m_kHandle = pcNewHandle;
    }
}

// LoadBinary: base interpolator data, flags, the linked object, the name, the transform and three linked interpolators.

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

class C630RefObject
{
  public:
    virtual void Unk00();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }

    long m_lRefCount;
};

template <class T> class C630Pointer
{
  public:
    C630Pointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }

    T* m_pObject;
};

class C630BinaryStream
{
  public:
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(C630BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void C630LoadBinary(C630BinaryStream& kStream, T& rValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&rValue, sizeof(T), &uiSize, 1);
}

// These stream accessors preserve the original binary layout.
inline unsigned int NiStream::GetFileVersion() const
{
    return *(const unsigned int*)((const char*)this + 0xD8);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *(NiBinaryStream**)((char*)this + 0x24C);
}

inline WriteStream* NiStream::GetWriter()
{
    return *(WriteStream**)((char*)this + 0x250);
}

// Loads the blend from the stream: base interpolator data, flags, target, name (version-dependent), transform, and three ref objects.
// @fnv 0x00a4c630
void NiLookAtInterpolator::LoadBinary(NiStream& arStream)
{
    NiStream& kStream = arStream;
    NiInterpolator::LoadBinary(kStream);

    C630LoadBinary(*(C630BinaryStream*)kStream.GetBinaryStream(), m_usFlags);
    m_pkLookAt = (NiAVObject*)kStream.DeserializeObject();
    if (kStream.GetFileVersion() < 0x14010001)
        kStream.ReadFixedString(m_kTargetNodeName);
    else
        kStream.ReadStringTableEntry(m_kTargetNodeName);
    m_kTransform.LoadBinary(kStream);

    for (unsigned int i = 0; i < 3; i++)
        ((C630Pointer<C630RefObject>*)m_pItems)[i] = (C630RefObject*)kStream.DeserializeObject();
}

struct BinaryOutput341
{
    void* state;
    unsigned int position;
    void* read;
    unsigned int(__cdecl* write)(BinaryOutput341*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Write(const void* data, unsigned int length, unsigned int* sizes, unsigned int count)
    {
        unsigned int bytes = write(this, data, length, sizes, count);
        position += bytes;
        return bytes;
    }
};
template <class T> inline void SaveBinary341(BinaryOutput341& output, const T& value)
{
    unsigned int size = sizeof(T);
    output.Write(&value, sizeof(T), &size, 1);
}
// The shared interpolator lacks the SaveBinary override at 0x00a724d0.
struct Interpolator341
{
    void NiInterpolator_LinkObject(NiStream*);
};

// Serializes the LookAt's flags, target link, target name, transform and three interpolator links to the stream.
// @fnv 0x00a4c700
void NiLookAtInterpolator::SaveBinary(NiStream& arStream)
{
    NiStream* stream = &arStream;
    ((Interpolator341*)this)->NiInterpolator_LinkObject(stream);
    SaveBinary341(*(BinaryOutput341*)stream->GetWriter(), m_usFlags);
    stream->SaveLinkID(reinterpret_cast<const NiObject*>(m_pkLookAt));
    stream->SerializeString((const char*)&m_kTargetNodeName);
    m_kTransform.SaveBinary(stream);
    for (unsigned int i = 0; i < 3; ++i)
        stream->SaveLinkID(reinterpret_cast<const NiObject*>(m_pItems[i]));
}

#include <windows.h>
struct S_00a4ba30_Ref
{
    virtual void v00();
    virtual void v01();
    LONG unk04;
};

struct S_00a4ba30_Ptr
{
    S_00a4ba30_Ref* m_p;
    operator NiInterpolator*() const
    {
        return (NiInterpolator*)m_p;
    }
    S_00a4ba30_Ptr& operator=(S_00a4ba30_Ref* p)
    {
        S_00a4ba30_Ref* old = m_p;
        if (old != p)
        {
            if (old)
            {
                if (!InterlockedDecrement(&old->unk04))
                    old->v01();
            }
            m_p = p;
            if (p)
                InterlockedIncrement(&p->unk04);
        }
        return *this;
    }
};

// Calls FUN_00a57050 with the two floats, then assigns each non-null unk38[i] entry's v50 result to the corresponding entry in r.
// @fnv 0x00a4ba30
NiInterpolator* __thiscall NiLookAtInterpolator::CloneForTimeRange(float a, float b)
{
    NiLookAtInterpolator* pResult = (NiLookAtInterpolator*)NiInterpolator::CloneForTimeRange(a, b);
    for (int i = 0; i < 3; i++)
    {
        if (((S_00a4ba30_Ptr*)m_pItems)[i])
            ((S_00a4ba30_Ptr*)pResult->m_pItems)[i] = (S_00a4ba30_Ref*)((NiInterpolator*)((S_00a4ba30_Ptr*)m_pItems)[i])->CloneForTimeRange(a, b);
    }
    return pResult;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

extern int DAT_0109b220;
extern int DAT_011a8400;
extern int DAT_011a8404;
extern int DAT_011a8408;
extern int DAT_011f3704;
extern int DAT_011f3708;
extern int DAT_011f370c;
extern int DAT_011f3710;
extern float DAT_01096b8c;

struct RefObj
{
    virtual void Destroy();
    virtual void DeleteThis() throw();
    long m_uiRefCount;
    inline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct SmartPtr
{
    RefObj* m_pObject;
    SmartPtr(RefObj* p = 0)
    {
        if (p)
            m_pObject = p;
        else
            memset(&m_pObject, 0, sizeof(m_pObject));
    }
    SmartPtr& operator=(RefObj* p) throw()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
            m_pObject = p;
        }
        return *this;
    }
};

// Preserve the bitwise default values used by the look-at constructor.
__declspec(nothrow) inline NiQuatTransform::NiQuatTransform()
{
    *(int*)&x = DAT_011a8400;
    *(int*)&y = DAT_011a8404;
    *(int*)&z = DAT_011a8408;
    *(int*)&qx = DAT_011f3704;
    *(int*)&qy = DAT_011f3708;
    *(int*)&qz = DAT_011f370c;
    *(int*)&qw = DAT_011f3710;
    scale = DAT_01096b8c;
}

// @fnv 0x00a4bcf0
NiLookAtInterpolator::NiLookAtInterpolator(unsigned int pkLookAt, unsigned int eAxis, bool bFlip)
    : m_usFlags(0), m_pkLookAt((NiAVObject*)pkLookAt)
{
    memset(m_pItems, 0, sizeof(m_pItems));
    if (bFlip)
        m_usFlags |= 1;
    else
        m_usFlags &= 0xFFFE;
    m_usFlags = (m_usFlags & 0xFFF9) | (eAxis * 2);
    ((SmartPtr*)m_pItems)[0] = 0;
    ((SmartPtr*)m_pItems)[1] = 0;
    ((SmartPtr*)m_pItems)[2] = 0;
}

extern "C" void _ReadWriteBarrier(void);
const float DAT_01015f5c = -3.4028234663852886e38f;
const float DAT_01017d00 = 0.0010000000474974513f;
const float DAT_01098c00 = 1.0010000467300415f;
const double DAT_01098bf8 = 0.9990000128746033;
const float DAT_01098bf0 = -1.0010000467300415f;
const double DAT_01098be8 = -0.9990000128746033;
const double DAT_010241b0 = -3.4028234663852886e38;
struct LookNode;
struct LookVector
{
    float x, y, z;
    const float& GetX() const
    {
        return x;
    }
    const float& GetY() const
    {
        return y;
    }
    const float& GetZ() const
    {
        return z;
    }
    LookVector()
    {}
    LookVector(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    LookVector operator+(const LookVector& v) const
    {
        LookVector result;
        const float* left = &x;
        const float* right = &v.x;
        for (int i = 0; i < 3; i++)
            (&result.x)[i] = left[i] + right[i];
        return result;
    }
    LookVector operator-(const LookVector& v) const
    {
        LookVector result;
        result.x = x - v.x;
        result.y = y - v.y;
        result.z = z - v.z;
        return result;
    }
    LookVector operator-() const
    {
        return LookVector(-x, -y, -z);
    }
    LookVector operator*(float k) const
    {
        LookVector result;
        result.x = x * k;
        result.y = y * k;
        result.z = z * k;
        return result;
    }
    LookVector& operator-=(const LookVector& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
    float SquaredLength() const
    {
        return x * x + y * y + z * z;
    }
    LookVector Cross(const LookVector& v) const
    {
        return LookVector(y * v.GetZ() - z * v.GetY(), z * v.GetX() - x * v.GetZ(), x * v.GetY() - y * v.GetX());
    }
    __declspec(noalias) void Unitize_004a0c10();
};
struct LookMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    LookVector FUN_004b4500(const LookVector&) const;
    LookMatrix FUN_00a588a0(const LookMatrix&) const;
    LookMatrix FUN_0043f8d0(const LookMatrix&) const;
    void FUN_004a0c90(float);
    void Identity()
    {
        m00 = 1.0f;
        m01 = 0.0f;
        m02 = 0.0f;
        m10 = 0.0f;
        m12 = 0.0f;
        m20 = 0.0f;
        m21 = 0.0f;
        m11 = 1.0f;
        m22 = 1.0f;
    }
    void Column0(const LookVector& v)
    {
        m00 = v.x;
        m10 = v.y;
        m20 = v.z;
    }
    void Column1(const LookVector& v)
    {
        m01 = v.x;
        m11 = v.y;
        m21 = v.z;
    }
    void Column2(const LookVector& v)
    {
        m02 = v.x;
        m12 = v.y;
        m22 = v.z;
    }
};
struct LookQuaternion
{
    float w, x, y, z;
    void FUN_00a6df40(const LookMatrix&);
};
struct LookTransform
{
    LookVector translation;
    LookQuaternion rotation;
    float scale;
    void Invalid()
    {
        translation.x = DAT_01015f5c;
        rotation.x = DAT_01015f5c;
        scale = DAT_01015f5c;
    }
    bool IsInvalid() const
    {
        return scale == DAT_010241b0 && rotation.x == DAT_010241b0 && translation.x == DAT_010241b0;
    }
};
struct LookNode
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    LookNode* parent;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    LookVector localPosition;
    float localScale;
    LookMatrix worldRotation;
    LookVector worldPosition;
    float worldScale;
};
extern const LookMatrix DAT_011a9448;
extern const LookVector DAT_011a9478, DAT_011a9484;

inline void NiQuatTransform::MakeInvalid()
{
    x = DAT_01015f5c;
    qy = DAT_01015f5c;
    scale = DAT_01015f5c;
}
inline bool NiQuatTransform::IsInvalid() const
{
    return scale == DAT_010241b0 && qy == DAT_010241b0 && x == DAT_010241b0;
}

// Computes the look-at transform for a node by calculating world position, orientation toward target, and optional roll/scale, storing the result in output.
// @fnv 0x00a4bec0
bool NiLookAtInterpolator::UpdateTransform(float time, NiObjectNET* apTarget, NiQuatTransform& arValue)
{
    LookNode* apNode = (LookNode*)apTarget;
    LookTransform& apTransform = (LookTransform&)arValue;
    LookNode* target = (LookNode*)m_pkLookAt;
    if (!target)
    {
        apTransform.Invalid();
        m_kTransform.MakeInvalid();
        return false;
    }
    LookVector vTargetPosition = target->worldPosition;
    LookNode* parent = apNode->parent;
    LookVector localPosition;
    if (m_pItems[0])
    {
        if (!m_pItems[0]->UpdatePoint3(time, (NiObjectNET*)apNode, (NiPoint3&)localPosition))
        {
            m_kTransform.MakeInvalid();
            return false;
        }
        (LookVector&)m_kTransform.x = localPosition;
    }
    else
        localPosition = apNode->localPosition;
    LookMatrix mParentRotation;
    LookVector worldPosition;
    if (parent)
    {
        mParentRotation = parent->worldRotation;
        float parentScale = parent->worldScale;
        worldPosition = parent->worldPosition + mParentRotation.FUN_004b4500(localPosition) * parentScale;
    }
    else
    {
        mParentRotation = DAT_011a9448;
        worldPosition = localPosition;
    }
    LookVector vDirection = vTargetPosition - worldPosition;
    LookMatrix rotation;
    if (vDirection.SquaredLength() < DAT_01017d00)
        rotation.Identity();
    else
    {
        vDirection.Unitize_004a0c10();
        LookVector vUp;
        float projection;
        if ((vDirection.z < DAT_01098c00 && vDirection.z > DAT_01098bf8) ||
            (vDirection.z > DAT_01098bf0 && vDirection.z < DAT_01098be8))
        {
            vUp = DAT_011a9478;
            projection = vDirection.y;
        }
        else
        {
            vUp = DAT_011a9484;
            projection = vDirection.z;
        }
        vUp -= vDirection * projection;
        vUp.Unitize_004a0c10();
        if (!bool(m_usFlags & 1))
            vDirection = -vDirection;

        LookVector vRight;
        vRight = vUp.Cross(vDirection);
        switch ((m_usFlags >> 1) & 3)
        {
        case 0:
            rotation.Column0(vDirection);
            rotation.Column1(vUp);
            rotation.Column2(-vRight);
            break;
        case 1:
            rotation.Column0(vRight);
            rotation.Column1(vDirection);
            rotation.Column2(-vUp);
            break;
        case 2:
            rotation.Column0(vRight);
            rotation.Column1(vUp);
            rotation.Column2(vDirection);
            break;
        }
        rotation = mParentRotation.FUN_00a588a0(rotation);
        if (m_pItems[1])
        {
            float angle;
            if (!m_pItems[1]->UpdateFloat(time, (NiObjectNET*)apNode, angle))
            {
                m_kTransform.MakeInvalid();
                return false;
            }
            LookMatrix mRollRotation;
            mRollRotation.FUN_004a0c90(-angle);
            rotation = rotation.FUN_0043f8d0(mRollRotation);
        }
    }
    LookQuaternion qRotation;
    qRotation.FUN_00a6df40(rotation);
    (LookQuaternion&)m_kTransform.qx = qRotation;
    _ReadWriteBarrier();
    if (m_pItems[2])
    {
        float amount;
        if (!m_pItems[2]->UpdateFloat(time, (NiObjectNET*)apNode, amount))
        {
            m_kTransform.MakeInvalid();
            return false;
        }
        m_kTransform.scale = amount;
    }
    if (m_kTransform.IsInvalid())
    {
        apTransform.Invalid();
        return false;
    }
    apTransform = (const LookTransform&)m_kTransform;
    m_fLastTime = time;
    return true;
}

namespace fnv_00a4c4b0 {
extern char* DAT_011f49e0;
extern char* DAT_0109b220;

struct S_00a4c4b0_Ref
{
    virtual void vf0();
    virtual void vf1();
    long m_refs;
    S_00a4c4b0_Ref* FUN_00a5d680();
};
struct S_00a4c4b0_Ptr
{
    S_00a4c4b0_Ref* m_p;
    S_00a4c4b0_Ptr& operator=(S_00a4c4b0_Ref* p)
    {
        S_00a4c4b0_Ref* old = m_p;
        if (old != p)
        {
            if (old)
            {
                if (InterlockedDecrement(&old->m_refs) == 0)
                    old->vf1();
            }
            m_p = p;
            if (p)
                InterlockedIncrement(&p->m_refs);
        }
        return *this;
    }
};
union S_00a4c4b0_Flags
{
    unsigned short w;
    struct
    {
        unsigned short b0 : 1;
        unsigned short mid : 2;
        unsigned short rest : 13;
    } f;
};
struct S_00a4c4b0_Xform
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

// Copies the flags, target, name, transform and cloned interpolators after the base data.
} // namespace fnv_00a4c4b0
using namespace fnv_00a4c4b0;

// @fnv 0x00a4c4b0
// src: XBOX_PDB 0x00a4c4b0
void __thiscall NiLookAtInterpolator::CopyMembers_00a4c4b0(NiLookAtInterpolator* dest, CloningProcess& c)
{
    ((NiObject*)this)->CopyMemberData(dest, c);
    unsigned int f = m_usFlags;
    dest->m_usFlags = f;
    dest->m_usFlags = (m_usFlags & 1) ? (f | 1) : (f & 0xfffe);
    {
        S_00a4c4b0_Flags* pDestFlags = (S_00a4c4b0_Flags*)&dest->m_usFlags;
        pDestFlags->f.mid = ((S_00a4c4b0_Flags*)&m_usFlags)->f.mid;
    }
    dest->m_pkLookAt = m_pkLookAt;
    char* s = fnv_00a4c4b0::DAT_011f49e0;
    if (dest->m_kTargetNodeName.m_kHandle != s)
    {
        if (s != fnv_00a4c4b0::DAT_0109b220)
            InterlockedIncrement((volatile LONG*)(s - 8));
        char* o = dest->m_kTargetNodeName.m_kHandle;
        if (o != fnv_00a4c4b0::DAT_0109b220)
            InterlockedDecrement((volatile LONG*)(o - 8));
        dest->m_kTargetNodeName.m_kHandle = s;
    }
    (S_00a4c4b0_Xform&)dest->m_kTransform = (const S_00a4c4b0_Xform&)m_kTransform;
    for (int i = 0; i < 3; i++)
    {
        if (m_pItems[i])
            ((S_00a4c4b0_Ptr*)dest->m_pItems)[i] = ((S_00a4c4b0_Ref*)m_pItems[i])->FUN_00a5d680();
    }
}

