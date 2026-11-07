#include "../../include/hkArray.h"

// src/staging/blk_00c60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/NiMemObject.h"
#include "../../include/NiTPointerList.h"
#include "../../include/NiPointer.h"  // bodies defined below (not layout_support.h's FNV64_NIPOINTER_INLINE_BODIES)
#include "../../include/layout_support.h"
#include "../../include/AutoMemContext.h"

#include "../../include/NiTransform.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiPoint3.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/Pair.h"
#include "../../include/NiPoint3.h"
#include "../../include/StrArr.h"
#include "../../include/Vec4.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkVector4.h"

#include "../../include/NiObject.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiStream.h"
#include "../../include/NiUpdateData.h"
#include "../../include/Transform.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; this unit defines inline bodies for both NiPoint3 and the stand-in in different forms (constructor/temporary, operand order), so one NiPoint3 cannot carry both.
#include "../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void SetComponents(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other) const;
    bool HasEqualComponents(const char* other);
    void ScaleComponents(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void SubtractIntoVector();
    LocalVec3 SubtractIntoVector(const LocalVec3& other);
    LocalVec3 SubtractIntoVector(const LocalVec3& other) const;
    LocalVec3 SubtractIntoVector(LocalVec3* other);
    LocalVec3 SubtractIntoVector(const LocalVec3* other);
    void SubtractIntoVector(LocalVec3* output, const LocalVec3* other);
    LocalVec3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& other) const;
    LocalVec3 ProcessAndReturnValue_0053d280(float divisor);
    float NiPoint3_XYLength();
    float NiPoint3_XYLength() const;
    void ComputeValue_0063c8a0(const LocalVec3* other);
    void ComputeValue_0063c8a0(void* other);
    void FUN_006815c0();
    float CVec3_Distance(LocalVec3* other);
    float CVec3_Distance(const LocalVec3& other) const;
    LocalVec3 TransformPointByMatrix4(const Mat& matrix);
    LocalVec3 TransformPointByMatrix4(const Matrix4* matrix);
    void Normalize_00b12790();
    LocalVec3 Diff_00b13040(void* other);
    LocalVec3 Diff_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& AddComponents(void* other);
    void ProcessEntries_00ddc870();
    void FUN_00e0f6e0();
};
#include "../../include/Data.h"
#include "../../include/Mat3.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiNode.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/NiCollisionObject.h"
#include "../../include/NiInterpolator.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTMap.h"
#include "../../include/NiMatrix3.h"
#include "../../include/bhkNiCollisionObject.h"
#include "../../include/bhkWorld.h"
#include <intrin.h>
#include <string.h>
#include "../../include/NiRefObject.h"
class bhkPoseArray;
class bhkRagdollShareData;
typedef NiTMapBase<DFALL<NiTMapItem<const char*, NiPointer<bhkPoseArray> > >, const char*, NiPointer<bhkPoseArray> > PoseMapBase;
typedef NiTMapBase<DFALL<NiTMapItem<const char*, NiPointer<bhkRagdollShareData> > >, const char*, NiPointer<bhkRagdollShareData> > RagdollMapBase;
typedef NiTMapBase<DFALL<NiTMapItem<NiAVObject*, short> >, NiAVObject*, short> ObjectMapBase;

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct Heap : MemoryManager
{
    void* Allocate(unsigned int);
};
inline void* MemoryManager::Allocate(unsigned int size)
{
    return static_cast<Heap*>(this)->Allocate(size);
}
extern MemoryManager _g_memoryManager;
__forceinline hkMemoryAllocator& GetRouterHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router.m_heap);
}
inline LocalVec3::LocalVec3() {}
__forceinline LocalVec3& LocalVec3::operator*=(float scale) { x *= scale; y *= scale; z *= scale; return *this; }
inline NiTransform::NiTransform() {}
__forceinline NiTransform& CopyTransform(NiTransform& dest, const NiTransform& source)
{
    memcpy(&dest, &source, sizeof(dest));
    return dest;
}
inline Mat3::Mat3() {}
inline void NiInterpolator::IncRefCount() { InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount)); }
inline void NiInterpolator::DecRefCount() { if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount))) DeleteThis(); }
template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew) { if (m_pObject != 0) m_pObject->IncRefCount(); }
template <class T> inline NiPointer<T>::NiPointer(const NiPointer& kSrc) : m_pObject(kSrc.m_pObject) { if (m_pObject != 0) m_pObject->IncRefCount(); }
template <class T> inline NiPointer<T>::~NiPointer() { if (m_pObject != 0) m_pObject->DecRefCount(); }
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew) {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& kSrc)
{
    if (m_pObject != kSrc.m_pObject) {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
inline Pair::Pair(int aa, int bb) : a(aa), b(bb) {}
inline NiUpdateData::NiUpdateData()
{
    *reinterpret_cast<float*>(this) = 0.0f;
    reinterpret_cast<char*>(this)[4] = 0;
    reinterpret_cast<char*>(this)[5] = 0;
    reinterpret_cast<char*>(this)[6] = 0;
    reinterpret_cast<char*>(this)[7] = 0;
    reinterpret_cast<char*>(this)[8] = 0;
}
namespace fnv_00c6b860 { void* __cdecl FUN_00a5b690(unsigned int value); }
extern char* DAT_0109b220;
inline NiFixedString::NiFixedString(unsigned int value) : m_kHandle(static_cast<char*>(fnv_00c6b860::FUN_00a5b690(value))) {}

extern "C" void __cdecl NiFreeAlias(void*);
template <class TAlloc, class TKEY, class TVAL>
inline NiTMapBase<TAlloc, TKEY, TVAL>::~NiTMapBase()
{
    RemoveAll();
    NiFreeAlias(m_ppkHashTable);
}

template <> inline NiPointer<bhkPoseArray>::~NiPointer()
{
    reinterpret_cast<NiPointer<NiRefObject>*>(this)->~NiPointer();
}
template <> inline NiPointer<bhkPoseArray>& NiPointer<bhkPoseArray>::operator=(const NiPointer& other)
{
    reinterpret_cast<NiPointer<NiRefObject>&>(*this) = reinterpret_cast<const NiPointer<NiRefObject>&>(other);
    return *this;
}
template <> inline NiPointer<bhkRagdollShareData>::~NiPointer()
{
    reinterpret_cast<NiPointer<NiRefObject>*>(this)->~NiPointer();
}
template <> inline NiPointer<bhkRagdollShareData>& NiPointer<bhkRagdollShareData>::operator=(const NiPointer& other)
{
    reinterpret_cast<NiPointer<NiRefObject>&>(*this) = reinterpret_cast<const NiPointer<NiRefObject>&>(other);
    return *this;
}
template <> inline NiPointer<bhkPoseArray>& NiPointer<bhkPoseArray>::operator=(bhkPoseArray* object)
{
    reinterpret_cast<NiPointer<NiRefObject>&>(*this) = reinterpret_cast<NiRefObject*>(object);
    return *this;
}

// Allocates a block of a * 56 bytes from _g_memoryManager and returns the pointer.
// @fnv 0x00c7a5d0
// src: COMMUNITY 0x00c7a5d0
void* __stdcall BSSimpleArray_bhkRagdollController_BoneTransf_1024_Allocate(unsigned int a)
{
    return _g_memoryManager.Allocate(a * 56);
}

// Allocates a+n bytes from _g_memoryManager, aligns the returned pointer to 16 bytes and stores the alignment offset in the byte before it.
// @fnv 0x00c66170
// src: XBOX_PDB 0x00c66170
void* __stdcall bhkMemoryAllocator_blockAlloc(unsigned int uiSize)
{
    unsigned char n = 0x10;
    unsigned char* p = (unsigned char*)_g_memoryManager.Allocate(uiSize + n);
    n -= (unsigned char)((unsigned int)p & 0xf);
    p += n;
    p[-1] = n;
    return p;
}

// @fnv 0x00c661a0
// src: XBOX_PDB 0x00c661a0
void __stdcall bhkMemoryAllocator_blockFree(void* apBlock, void* apUnused)
{
    if (apBlock)
    {
        unsigned char* q = static_cast<unsigned char*>(apBlock);
        reinterpret_cast<MemoryManager*>(&_g_memoryManager)->Deallocate(q - q[-1]);
    }
}

extern float DAT_012677c4;
extern int DAT_012677c8;

// @fnv 0x00c66210
// src: COMMUNITY 0x00c66210
void __cdecl bhkWorld_ClearPickData()
{
    DAT_012677c8 = 0;
    DAT_012677c4 = 0.0f;
}

// @fnv 0x00c66260
void SetFlagFromField(unsigned short* pFlags, unsigned int* pSource)
{
    if (pSource[3])
        pFlags[6] |= 1;
    else
        pFlags[6] &= 0xfffe;
}

// @fnv 0x00c662b0
// src: COMMUNITY 0x00c662b0
bool __cdecl bhkWorld_DebugDisplayObject(void* pObject, void* pOther)
{
    return reinterpret_cast<bool(__thiscall*)(void*, bool)>(reinterpret_cast<void***>(
        reinterpret_cast<void**>(pObject)[0])[48])(pObject, reinterpret_cast<void**>(pOther)[3] != 0);
}

namespace fnv_00c66480 {
extern int DAT_010c3b98;

struct FUN_00c66480_cls
{
    void* p;
    FUN_00c66480_cls* FUN_00c66480(bool f);
};
// Sets p to point at DAT_010c3b98 and, when f has bit 0 set, deallocates this via _g_memoryManager, then returns this.
// @fnv 0x00c66480
FUN_00c66480_cls* FUN_00c66480_cls::FUN_00c66480(bool abFree)
{
    p = (void*)&DAT_010c3b98;
    if (abFree & 1)
        ((MemoryManager*)&_g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00c66480

namespace fnv_00c664b0 {
extern int DAT_010c3bac;

struct FUN_00c664b0_cls
{
    int* m_p;
    FUN_00c664b0_cls* __thiscall FUN_00c664b0(int flag);
};
// @fnv 0x00c664b0
FUN_00c664b0_cls* __thiscall FUN_00c664b0_cls::FUN_00c664b0(int aiFlags)
{
    m_p = &DAT_010c3bac;
    if (aiFlags & 1)
        ((MemoryManager*)&_g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00c664b0

namespace fnv_00c664e0 {
extern char DAT_010c3bb8;

struct FUN_00c664e0
{
    void* vft;
    FUN_00c664e0(int);
};
// Sets the vtable pointer and, when bit 0 of f is set, deallocates this object through the memory manager.
// @fnv 0x00c664e0
FUN_00c664e0::FUN_00c664e0(int aiFlags)
{
    vft = &DAT_010c3bb8;
    if (aiFlags & 1)
        ((MemoryManager*)&_g_memoryManager)->Deallocate(this);
}
}  // namespace fnv_00c664e0

extern int DAT_010c3af8;
void __stdcall UpdateFields_00cbf1a0();
struct FUN_00c66540_class
{
    int __thiscall InitVtableAndCall(int);
};
// @fnv 0x00c66540
int __thiscall FUN_00c66540_class::InitVtableAndCall(int aiUnused)
{
    *(int*)this = (int)&DAT_010c3af8;
    UpdateFields_00cbf1a0();
    return (int)this;
}

namespace fnv_00c66600 {
extern int DAT_010a47b8;

struct FUN_00c66600
{
    void* m_p;
    FUN_00c66600(void* p);
};

// Stores the address of DAT_010a47b8 in m_p and, when the low bit of p is set, deallocates this object through _g_memoryManager.
// @fnv 0x00c66600
FUN_00c66600::FUN_00c66600(void* p)
{
    m_p = &DAT_010a47b8;
    if ((unsigned char)p & 1)
        ((MemoryManager*)&_g_memoryManager)->Deallocate(this);
}
}  // namespace fnv_00c66600

extern "C" void* __cdecl bhkUtilFunctions_GetNiAVObject(void*);

struct FUN_00c66fb0_Class
{
    void* m_pObject;
    void* bhkPickData_GetNiAVObject();
};

// @fnv 0x00c66fb0
// src: XBOX_PDB 0x00c66fb0
void* FUN_00c66fb0_Class::bhkPickData_GetNiAVObject()
{
    void* p = *(void**)((char*)this + 0x80);
    if (p)
        return bhkUtilFunctions_GetNiAVObject(p);
    return 0;
}

// @fnv 0x00c66fd0
// src: XBOX_PDB 0x00c66fd0
char* __fastcall bhkPickData_GethkRigidBody(struct BhkPickData* self)
{
    char* p = *(char**)((char*)self + 0x80);
    if (p && p[0x18] == 1)
        return p + p[0x10];
    return 0;
}

struct FUN_005533f0_cls
{
    void bhkWorld_AddEntityListener(unsigned int);
};
struct FUN_00c6a620_cls
{
    void* m_auiShapeKeys[9];
    void* m_field;
    void SetField(void* a);
};
// @fnv 0x00c6a620
void FUN_00c6a620_cls::SetField(void* pValue)
{
    ((FUN_005533f0_cls*)this)->bhkWorld_AddEntityListener((unsigned int)pValue);
    m_field = pValue;
}

struct FUN_00c6c870_class
{
    void __thiscall bhkCharacterListener_contactPointRemovedCallback(unsigned int a, unsigned int b);
};

// @fnv 0x00c6c870
// src: XBOX_PDB 0x00c6c870
void __thiscall FUN_00c6c870_class::bhkCharacterListener_contactPointRemovedCallback(unsigned int auiUnused, unsigned int auiSource)
{
    unsigned int* p = *(unsigned int**)((char*)auiSource + 0x48);
    if ((p[7] & 0x7f) == 0x1e && *(unsigned int*)((char*)this + 0x6c) > 0)
        *(unsigned int*)((char*)this + 0x6c) = *(unsigned int*)((char*)this + 0x6c) - 1;
}

struct FUN_00c6cba0_class
{
    void bhkCharacterController_UpdateState();
};

// @fnv 0x00c6cba0
// src: COMMUNITY 0x00c6cba0
void FUN_00c6cba0_class::bhkCharacterController_UpdateState()
{
    if (*(int*)((char*)this + 0x520) != 0xb)
    {
        *(int*)((char*)this + 0x3f0) = *(int*)((char*)this + 0x520);
        *(int*)((char*)this + 0x520) = 0xb;
    }
}

struct FUN_00c6cca0
{
    hkReferencedObject* ref;
    void release();
};

// @fnv 0x00c6cca0
void FUN_00c6cca0::release()
{
    if (ref)
        ref->removeReference();
    ref = 0;
}

int __fastcall hkpCharacterContext_getState(char*);

struct FUN_00c6d120_cls
{
    int __thiscall bhkCharacterController_GetUseZ();
};

// Calls FUN_00ca9600 on the object at offset 0x3e0 and returns 1 if the result is 4, 5 or 6, otherwise 0.
// @fnv 0x00c6d120
// src: COMMUNITY 0x00c6d120
int __thiscall FUN_00c6d120_cls::bhkCharacterController_GetUseZ()
{
    int r = hkpCharacterContext_getState((char*)this + 0x3e0);
    if (r == 5 || r == 6 || r == 4)
        return 1;
    return 0;
}

extern float DAT_01267bcc;

struct FUN_00c6d4b0_Class
{
    void bhkCharacterController_Jump(float f);
};

// @fnv 0x00c6d4b0
// src: COMMUNITY 0x00c6d4b0
void FUN_00c6d4b0_Class::bhkCharacterController_Jump(float afValue)
{
    *(float*)((char*)this + 0x540) = DAT_01267bcc * afValue;
    *(int*)((char*)this + 0x520) = 1;
}

struct FUN_00c6e2e0_cls
{
    char pad[0x4e8];
    float f_4e8;
    char pad2[0x5c];
    float f_548;
    void __thiscall bhkCharacterController_UpdateFalling();
};
// @fnv 0x00c6e2e0
// src: COMMUNITY 0x00c6e2e0
void __thiscall FUN_00c6e2e0_cls::bhkCharacterController_UpdateFalling()
{
    f_548 = f_4e8 + f_548;
}

// @fnv 0x00c6ead0
void* __cdecl GetValidatedPointer(void* apObject)
{
    void* r = 0;
    if (apObject)
    {
        unsigned int t = *(unsigned int*)((char*)apObject + 0xc);
        if (t == 10)
        {
            apObject = *(void**)((char*)apObject + 0x34);
            t = *(unsigned int*)((char*)apObject + 0xc);
        }
        if (t == 0x17 || t == 0x1e || t == 0x1f)
            r = apObject;
    }
    return r;
}

struct FUN_00c6fd40_class
{
    int* bhkCharacterController_GetBumpedBody();
};

// @fnv 0x00c6fd40
// src: COMMUNITY 0x00c6fd40
int* FUN_00c6fd40_class::bhkCharacterController_GetBumpedBody()
{
    int* p = *(int**)((char*)this + 0x630);
    if (p)
        return *(int**)((char*)p + 0xc);
    return 0;
}

struct FUN_00c6fd60_Class
{
    void* bhkCharacterController_GetBumpedCharacterController();
};
// @fnv 0x00c6fd60
// src: XBOX_PDB 0x00c6fd60
void* __thiscall FUN_00c6fd60_Class::bhkCharacterController_GetBumpedCharacterController()
{
    void* p = *(void**)((char*)this + 0x638);
    if (p)
        return *(void**)((char*)p + 0xc0);
    return 0;
}

extern float DAT_011b02dc;
extern float DAT_01267c14;
extern float DAT_01267c18;

// @fnv 0x00c74550
// src: XBOX_PDB 0x00c74550
void bhkWindListener_SetWind(float afScale, float afValue)
{
    DAT_01267c14 = DAT_011b02dc * afScale;
    DAT_01267c18 = afValue;
}

struct FUN_00c74870_Class
{
    void bhkRagdollController_SetGrabIKIntrpGain(int a, float b);
};

// @fnv 0x00c74870
// src: COMMUNITY 0x00c74870
void __thiscall FUN_00c74870_Class::bhkRagdollController_SetGrabIKIntrpGain(int aiSlotIndex, float afValue)
{
    ((float*)((char*)this + 0x1b4))[aiSlotIndex * 12] = afValue;
}

struct FUN_00c74890_Class
{
    void __thiscall bhkRagdollController_SetGrabIKTarget(int a, int b);
};

// @fnv 0x00c74890
// src: COMMUNITY 0x00c74890
void __thiscall FUN_00c74890_Class::bhkRagdollController_SetGrabIKTarget(int aiSlot, int aiValue)
{
    int idx = aiSlot * 3 + 0x1b;
    ((int*)this)[idx * 4] = aiValue;
}

struct FUN_00c748b0_class
{
    void SetFlagIfUnset();
};

// @fnv 0x00c748b0
void FUN_00c748b0_class::SetFlagIfUnset()
{
    if (!*(int*)((char*)this + 0x194))
    {
        *(char*)((char*)this + 0x181) = 1;
        *(int*)((char*)this + 0x194) = 1;
    }
}

struct FUN_00c748d0_C
{
    void SetSlotFloats(int a, float b, float c);
};
// Writes two floats at offsets 0x134 and 0x138 of the 80-byte element selected by a.
// @fnv 0x00c748d0
void FUN_00c748d0_C::SetSlotFloats(int aiIndex, float afValue1, float afValue2)
{
    char* p = (char*)this + aiIndex * 80;
    *(float*)(p + 0x134) = afValue1;
    *(float*)(p + 0x138) = afValue2;
}

extern void* DAT_010c4c64;
extern "C" void __cdecl NiFreeAlias(void*);
// @fnv 0x00c75cc0
// src: GUESS 0x00c75cc0 (confidence: medium)
void __fastcall Object_ReleaseStorage_00c75cc0(PoseMapBase* self, void*)
{
    *reinterpret_cast<void**>(self) = &DAT_010c4c64;
    self->RemoveAll();
    ::NiFreeAlias(self->m_ppkHashTable);
}

namespace fnv_00c75e00 {
extern "C" void NiFreeAlias(void*);
extern int DAT_010c4ca4;
// @fnv 0x00c75e00
void __fastcall Init(RagdollMapBase* self, void*)
{
    *reinterpret_cast<void**>(self) = &DAT_010c4ca4;
    self->RemoveAll();
    ::NiFreeAlias(self->m_ppkHashTable);
}
}  // namespace fnv_00c75e00

// @fnv 0x00c75f60
template <> void ObjectMapBase::SetValue(NiTMapItem<NiAVObject*, short>* pData, NiAVObject* key, short value)
{
    pData->m_key = key;
    pData->m_val = value;
}

namespace fnv_00c75f80 {
extern int DAT_010c4cf8;
void NiFreeAlias(void*);
// @fnv 0x00c75f80
void __fastcall Init(ObjectMapBase* self, void*)
{
    *reinterpret_cast<void**>(self) = &DAT_010c4cf8;
    self->RemoveAll();
    ::NiFreeAlias(self->m_ppkHashTable);
}
}  // namespace fnv_00c75f80

struct FUN_00c76220_Class
{
    int hkaRagdollInstance_getRigidBodyOfBone(int idx);
};

// @fnv 0x00c76220
// src: HAVOK_LIB 0x00c76220
int FUN_00c76220_Class::hkaRagdollInstance_getRigidBodyOfBone(int aiIndex)
{
    int* p = *(int**)((char*)this + 0x20);
    int v = p[aiIndex];
    if (v < 0)
        return 0;
    int* q = *(int**)((char*)this + 8);
    return q[v];
}

struct FUN_00c76320_class
{
    int __thiscall GetNestedValue();
};

// Follows pointers at offsets 0x48, 8, 0, 8 and returns the int at offset 0x350 of the last object, or 0 if any link is null.
// @fnv 0x00c76320
int __thiscall FUN_00c76320_class::GetNestedValue()
{
    void* p = *(void**)((char*)this + 0x48);
    if (p)
    {
        void* q = *(void**)((char*)p + 8);
        void* r = *(void**)((char*)q + 0);
        if (r)
        {
            void* s = *(void**)((char*)r + 8);
            if (s)
                return *(int*)((char*)s + 0x350);
        }
    }
    return 0;
}

// @fnv 0x00c7a570
void* __fastcall DeletePoseMap(NiTMap<const char*, NiPointer<bhkPoseArray> >* self, void*, bool abFree)
{
    self->NiTMap::~NiTMap();
    if (abFree & 1)
        _g_memoryManager.Deallocate(self);
    return self;
}

// @fnv 0x00c7a590
void* __fastcall DeleteRagdollMap(NiTMap<const char*, NiPointer<bhkRagdollShareData> >* self, void*, bool abFree)
{
    self->NiTMap::~NiTMap();
    if (abFree & 1)
        _g_memoryManager.Deallocate(self);
    return self;
}

void __stdcall FUN_00c76240();

void __cdecl operator delete(void*, unsigned int);

struct FUN_00c7a8b0_class
{
    void* FUN_00c7a8b0(unsigned int a);
};

// Calls FUN_00c76240, deletes this with size 0x20 when bit 0 of a is set, and returns this.
// @fnv 0x00c7a8b0
void* FUN_00c7a8b0_class::FUN_00c7a8b0(unsigned int uiFlags)
{
    FUN_00c76240();
    if (uiFlags & 1)
        operator delete(this, 0x20);
    return this;
}

// @fnv 0x00c7fc20
// src: GUESS 0x00c7fc20 (confidence: medium)
void* __stdcall Object_AllocateStorage_00c7fc20(unsigned int a)
{
    return _g_memoryManager.Allocate(a * 8);
}

struct FUN_00c66560_class
{
    void UpdateFields_00cbf1a0();
    void* __thiscall ProcessAndReturnValue_00c66560(int a);
};
// @fnv 0x00c66560
// src: GUESS 0x00c66560 (confidence: low)
void* __thiscall FUN_00c66560_class::ProcessAndReturnValue_00c66560(int a)
{
    UpdateFields_00cbf1a0();
    return this;
}

void __cdecl ProcessPendingItems();
// @fnv 0x00c68a00
// src: COMMUNITY 0x00c68a00
void __fastcall bhkWorld_ProcessBatchRemovals(bhkWorld* self, void*, bool a)
{
    ProcessPendingItems();
    self->ReleaseBodies();
    self->ClearReferences();
    if (a)
        self->FlushEntries();
    else
        self->ClearEntries();
}

struct FUN_00c75ad0_T
{
    float f_0;
    float f_4;
    float f_8;
    float f_c;
    float f_10;
    float f_14;
    float f_18;
    float f_1c;
    float f_20;
    float f_24;
    float f_28;
    float f_2c;
    float f_30;
    float f_34;
};
struct FUN_00c75ad0_Class
{
    void* m_pObject;
    void* m_pData;
    void bhkRagdollController_SetFeedback(FUN_00c75ad0_T* p);
};
// @fnv 0x00c75ad0
// src: COMMUNITY 0x00c75ad0
void FUN_00c75ad0_Class::bhkRagdollController_SetFeedback(FUN_00c75ad0_T* p)
{
    FUN_00c75ad0_T** slot = *(FUN_00c75ad0_T***)((char*)this + 0x2a4);
    *(FUN_00c75ad0_T**)((char*)slot + 0x18) = p;
    *(char*)((char*)this + 0x28c) = 1;
    *(char*)((char*)this + 0x28d) = *(char*)p;
    FUN_00c75ad0_T* d = *(FUN_00c75ad0_T**)*(void**)((char*)this + 0x4c);
    d->f_0 = p->f_8;
    d->f_4 = p->f_1c;
    d->f_8 = p->f_14;
    d->f_c = p->f_10;
    d->f_10 = p->f_c;
    d->f_14 = p->f_30;
    d->f_18 = p->f_34;
    d->f_1c = p->f_18;
    d->f_20 = p->f_20;
    d->f_24 = p->f_24;
    d->f_28 = p->f_28;
    d->f_2c = p->f_2c;
}

extern int DAT_010c4db8;
extern int DAT_010c4dc0;
struct FUN_00c7a630_class
{
    int* vtbl;
    int* m_p;
    int* m_kPointA;
    int* m_kPointB;
    void __thiscall SetVtableAndProcessState_00c7a630();
};
// @fnv 0x00c7a630
// src: GUESS 0x00c7a630 (confidence: low)
void __thiscall FUN_00c7a630_class::SetVtableAndProcessState_00c7a630()
{
    vtbl = (int*)&DAT_010c4db8;
    if (m_p)
    {
        ((void(__stdcall*)(void*))DAT_010c4dc0)(m_p);
        m_p = 0;
        m_kPointB = 0;
        m_kPointA = 0;
    }
}

extern int DAT_0108ffb4;
struct FUN_009ba5f0_shell
{
    void SetChildObject(int);
};
struct FUN_00c7fb40
{
    int* p;
    void UpdateFields_00c7fb40();
};
// @fnv 0x00c7fb40
// src: GUESS 0x00c7fb40 (confidence: low)
void FUN_00c7fb40::UpdateFields_00c7fb40()
{
    p = &DAT_0108ffb4;
    ((FUN_009ba5f0_shell*)this)->SetChildObject(0);
}

bool __cdecl AreVectorsEqual(NiPoint3 const& a, NiPoint3 const& b, float c);

// Checks each of three consecutive point pairs with AreVectorsEqual and returns false as soon as one pair fails, otherwise true.
// @fnv 0x00c6b5f0
// src: XBOX_PDB 0x00c6b5f0
bool __cdecl CloseTo(NiPoint3 const* apPointsA, NiPoint3 const* apPointsB, float c)
{
    unsigned int i;
    for (i = 0; i < 3; ++i)
    {
        NiPoint3 pointA;
        NiPoint3 pointB;
        pointA.x = apPointsA[i].x;
        pointA.y = apPointsA[i].y;
        pointA.z = apPointsA[i].z;
        pointB.x = apPointsB[i].x;
        pointB.y = apPointsB[i].y;
        pointB.z = apPointsB[i].z;
        if (!AreVectorsEqual(pointA, pointB, c))
            return false;
    }
    return true;
}

struct FUN_00c663d0_Ref
{
    virtual void v0();
    virtual void v1();
    volatile long m_uiRefCount;
};
// Copy-assigns a ref-counted pointer: releases the old object when its count drops to zero, then retains the new one.
// @fnv 0x00c663d0
template <> NiPointer<FUN_00c663d0_Ref>& NiPointer<FUN_00c663d0_Ref>::operator=(const NiPointer& kSrc)
{
    FUN_00c663d0_Ref* pOld = m_pObject;
    if (pOld != kSrc.m_pObject)
    {
        if (pOld)
        {
            if (InterlockedDecrement(&pOld->m_uiRefCount) == 0)
                pOld->v1();
        }
        m_pObject = kSrc.m_pObject;
        if (m_pObject)
            InterlockedIncrement(&m_pObject->m_uiRefCount);
    }
    return *this;
}

struct FUN_00c66e20_vtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float);
};
struct FUN_00c66e20_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void bhkWorld_UpdateListeners(float a);
};
// If m_8 is set, iterates the objects in the array at offset 0x70 up to the count at 0x74 and calls v6(a) on each non-null object when a is non-zero.
// @fnv 0x00c66e20
// src: COMMUNITY 0x00c66e20
void FUN_00c66e20_Class::bhkWorld_UpdateListeners(float afValue)
{
    if (m_8)
    {
        for (int i = 0; i < *(int*)((char*)this + 0x74); ++i)
        {
            FUN_00c66e20_vtbl* obj = (FUN_00c66e20_vtbl*)(*(int**)((char*)this + 0x70))[i];
            if (obj && afValue != 0.0f)
                obj->v6(afValue);
        }
    }
}

struct NiPoint3_ZERO_s
{
    int x, y, z;
};
extern NiPoint3_ZERO_s NiPoint3_ZERO;
extern int DAT_011f4270;
extern int DAT_011f4274;

struct FUN_00c6d9f0_s
{
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    FUN_00c6d9f0_s();
};

// Initialises the object's fields: f0 to 0 and three groups of f4/f8/fc, f10/f14/f18, f1c/f20/f24 to NiPoint3_ZERO.x, DAT_011f4270 and DAT_011f4274.
// @fnv 0x00c6d9f0
FUN_00c6d9f0_s::FUN_00c6d9f0_s()
{
    f0 = 0;
    f4 = NiPoint3_ZERO.x;
    f8 = DAT_011f4270;
    fc = DAT_011f4274;
    f10 = NiPoint3_ZERO.x;
    f14 = DAT_011f4270;
    f18 = DAT_011f4274;
    f1c = NiPoint3_ZERO.x;
    f20 = DAT_011f4270;
    f24 = DAT_011f4274;
}

extern int DAT_010c4dc0;
struct FUN_00c7a690_class
{
    int* vtbl;
    int* m_p;
    int* m_kPointA;
    int* m_kPointB;
    void* __thiscall FUN_00c7a690(int a);
};
// Sets the vtable, frees m_p via DAT_010c4dc0 and clears the pointers, then deallocates this if bit 0 of a is set.
// @fnv 0x00c7a690
void* __thiscall FUN_00c7a690_class::FUN_00c7a690(int aiFlags)
{
    void* old = m_p;
    vtbl = &DAT_010c4db8;
    if (old)
    {
        ((void(__stdcall*)(void*)) * (void**)(void*)&DAT_010c4dc0)(old);
        m_p = 0;
        m_kPointB = 0;
        m_kPointA = 0;
    }
    if (aiFlags & 1)
        ((MemoryManager*)&_g_memoryManager)->Deallocate(this);
    return this;
}

struct FUN_00c747d0_Class
{
    char pad[0x43];
    char m_43;
    char pad2[0x220 - 0x44];
    char m_220;
    char pad3[0x222 - 0x221];
    unsigned char m_222;
    char m_223;
    void bhkRagdollController_SetFootIKActive(bool abActive);
};

// @fnv 0x00c747d0
// src: COMMUNITY 0x00c747d0
void FUN_00c747d0_Class::bhkRagdollController_SetFootIKActive(bool abActive)
{
    unsigned char bprevActive = m_222;
    int bNewActive;
    if (m_43 == 0)
    {
        if (m_220 != 0 && abActive)
            bNewActive = 1;
        else
            bNewActive = 0;
    }
    else
    {
        bNewActive = bprevActive;
    }
    m_222 = (unsigned char)bNewActive;
    if (bprevActive != 0 && (unsigned char)bNewActive == 0)
        m_223 = 1;
}

extern int DAT_010c4ce4;
extern void* DAT_010c4cec;
extern MemoryManager _g_memoryManager;

struct FUN_00c7a6e0_class
{
    int* vtbl;
    int* m_p;
    int* m_kPointA;
    int* m_kPointB;
    FUN_00c7a6e0_class* __thiscall FUN_00c7a6e0(unsigned int flags);
};

// Sets the vtable, frees m_p via DAT_010c4cec and clears the pointers, then deallocates this if flags bit 0 is set.
// @fnv 0x00c7a6e0
FUN_00c7a6e0_class* __thiscall FUN_00c7a6e0_class::FUN_00c7a6e0(unsigned int flags)
{
    int* p = this->m_p;
    this->vtbl = &DAT_010c4ce4;
    if (p)
    {
        ((void(__stdcall*)(void*))DAT_010c4cec)(p);
        this->m_p = 0;
        this->m_kPointB = 0;
        this->m_kPointA = 0;
    }
    if (flags & 1)
    {
        _g_memoryManager.Deallocate(this);
    }
    return this;
}

extern int DAT_010c3b80;
struct FUN_00c66420
{
    int* vtbl;
    int __thiscall Init(int a);
};
// Sets the object's vtbl to DAT_010c3b80 and, if bit 0 of a is set, deallocates this via the memory manager; returns this.
// @fnv 0x00c66420
int FUN_00c66420::Init(int aiFlags)
{
    vtbl = &DAT_010c3b80;
    if (aiFlags & 1)
        _g_memoryManager.Deallocate(this);
    return (int)this;
}

extern int DAT_010c3b8c;

struct FUN_00c66450
{
    int* vtbl;
    FUN_00c66450(char a);
};

// Sets the object's vtbl to DAT_010c3b8c and, if bit 0 of a is set, deallocates the object via _g_memoryManager.
// @fnv 0x00c66450
FUN_00c66450::FUN_00c66450(char acFlags)
{
    vtbl = &DAT_010c3b8c;
    if (acFlags & 1)
        _g_memoryManager.Deallocate(this);
}

void __cdecl SetNiPoint3FromHkVector4(const hkVector4&, void*);
struct FUN_00c66be0_class
{
    void bhkWorld_GetOrigin(unsigned int a);
};
// @fnv 0x00c66be0
// src: XBOX_PDB 0x00c66be0
void FUN_00c66be0_class::bhkWorld_GetOrigin(unsigned int auiVectorAddress)
{
    SetNiPoint3FromHkVector4(*(const hkVector4*)auiVectorAddress, (char*)this + 0x60);
}

struct FUN_00c67110_v
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
};
struct FUN_00c67110_s
{
    int p0;
    int p4;
    int p8;
    int pc;
    FUN_00c67110_v* pv;
};
// @fnv 0x00c67110
// src: COMMUNITY 0x00c67110
void bhkWorld_RemoveObject(FUN_00c67110_s* pObject)
{
    FUN_00c67110_v* v = pObject->pv;
    if (v)
        v->v40();
}

struct FUN_00c671f0_Ref
{
    virtual void v0();
    virtual void v1();
    volatile long m_uiRefCount;
};

struct FUN_00c671f0_Obj
{
    char pad[8];
    void* m_pSharedOwner;
};

// @fnv 0x00c671f0
void __cdecl ReleaseOwnerReference(FUN_00c671f0_Obj* pObj)
{
    FUN_00c671f0_Obj* pOwner = (FUN_00c671f0_Obj*)pObj->m_pSharedOwner;
    if (pOwner)
    {
        FUN_00c671f0_Ref* pOld = *(FUN_00c671f0_Ref**)((char*)pOwner + 0x1c);
        if (pOld)
        {
            if (InterlockedDecrement(&pOld->m_uiRefCount) == 0)
                pOld->v1();
            *(FUN_00c671f0_Ref**)((char*)pOwner + 0x1c) = 0;
        }

        FUN_00c671f0_Ref* pCurRef = *(FUN_00c671f0_Ref**)((char*)pOwner + 0x1c);
        if (pCurRef && *(void**)((char*)pCurRef + 8) != pOwner)
        {
            void(__thiscall * fn)(FUN_00c671f0_Ref*, FUN_00c671f0_Obj*) =
                *(void(__thiscall**)(FUN_00c671f0_Ref*, FUN_00c671f0_Obj*))((char*)*(void**)pCurRef + 0x8c);
            fn(pCurRef, pOwner);
        }
    }
}

struct FUN_00c67fc0
{
    int m_field;
    hkMemoryRouter m_router;

    FUN_00c67fc0();
};

// @fnv 0x00c67fc0
FUN_00c67fc0::FUN_00c67fc0() : m_field(0)
{}

struct AddReferenceHelper
{
    void __thiscall RetainReference();
};

struct FUN_00c68a40_Class
{
    void __thiscall bhkWorld_AddBatchedEntities();
};

struct FUN_00c676e0_Class
{
    void __thiscall ClearIndexedValues();
};

struct FUN_00c6aac0_Class
{
    void __thiscall bhkWorld_AddBatchedActions();
};

struct FUN_00c67850_Class
{
    void __thiscall ProcessConstraints();
};

struct FUN_00c97d30_Class
{
    void __thiscall hkpWorld_addConstraint(hkReferencedObject* a);
};

struct FUN_00c6b320_Base
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void* v37()
    {
        return 0;
    }
};

struct FUN_00c6b320_Class : FUN_00c6b320_Base
{
    unsigned char pad_04[0x14];
    unsigned int m_18;
    unsigned char pad_1c[0x28];
    void** m_ppData;
    unsigned int m_uiItemCount;

    void __thiscall bhkWorld_Add_00c6b320(hkReferencedObject* a);
};

// @fnv 0x00c6b320
// src: XBOX_PDB 0x00c6b320
void __thiscall FUN_00c6b320_Class::bhkWorld_Add_00c6b320(hkReferencedObject* a)
{
    if (this == 0)
        return;

    void* world = this->v37();
    if (world == 0)
        return;

    if (this->m_18 > 0)
    {
        if (this->m_uiItemCount >= 0xc8)
        {
            ((FUN_00c68a40_Class*)this)->bhkWorld_AddBatchedEntities();
            ((FUN_00c676e0_Class*)this)->ClearIndexedValues();
            ((FUN_00c6aac0_Class*)this)->bhkWorld_AddBatchedActions();
            ((FUN_00c67850_Class*)this)->ProcessConstraints();
        }

        ((AddReferenceHelper*)a)->RetainReference();

        unsigned int count = this->m_uiItemCount;
        void** array = this->m_ppData;
        array[count] = a;
        ++this->m_uiItemCount;
    }
    else
    {
        if (a == 0)
            return;

        if (*(int*)((char*)a + 8) != 0)
            return;

        void* p = *(void**)((char*)a + 0x14);
        if (p != 0 && *(int*)((char*)p + 0xcc) == 0)
            return;

        p = *(void**)((char*)a + 0x18);
        if (p != 0 && *(int*)((char*)p + 0xcc) == 0)
            return;

        ((FUN_00c97d30_Class*)world)->hkpWorld_addConstraint(a);
    }
}

extern int DAT_010c4314;
extern int DAT_01267b60;
struct FUN_00c6b950 : NiCollisionObject
{
    unsigned short m_iThirdValue;
    int m_10;
    FUN_00c6b950(void* a);
};
// @fnv 0x00c6b950
FUN_00c6b950::FUN_00c6b950(void* a) : NiCollisionObject(a)
{
    *(int*)this = (int)&DAT_010c4314;
    m_10 = 0;
    ++DAT_01267b60;
    m_iThirdValue = 0x41;
}

// These collision operations are absent from the shared class declaration.
// An unused EDX parameter keeps the original ECX/stack calling convention.
void SetCollisionInterpolator(bhkNiCollisionObject*, void*);
// @fnv 0x00c6bb70
// Keep this external entry independent of the stream tag used by each header snapshot.
void __fastcall LinkCollisionObject(bhkNiCollisionObject* self, void*, void* stream)
{
    NiStream& aStream = *static_cast<NiStream*>(stream);
    self->NiCollisionObject::LinkObject(aStream);
    NiAVObject* p = self->m_pkSceneObject;
    if (p)
        p->m_uFlags = (p->m_uFlags & 0xffffffef) | 6;
    reinterpret_cast<void (__thiscall*)(bhkNiCollisionObject*, void*)>(SetCollisionInterpolator)(self, aStream.GetLoadedObject());
}

void __cdecl bhkNiCollisionObject_SynchronizeRec(int a, int b);

// Saves the thread-local value, sets it to b, calls FUN_00c6c110(a, 0), then restores the saved value.
// @fnv 0x00c6c3d0
void __cdecl SetTlsValueAndReset(int aiArg, int aiValue)
{
    struct TLSData
    {
        unsigned char pad[0x2c0];
        int value;
    };
    static __declspec(thread) TLSData tls;

    int oldValue = tls.value;
    tls.value = aiValue;
    bhkNiCollisionObject_SynchronizeRec(aiArg, 0);
    tls.value = oldValue;
}

void __cdecl operator delete(void*, unsigned int);
struct FUN_00c6c290_holder
{
    void FUN_00c6c290();
};
struct FUN_00c6c410_cls : FUN_00c6c290_holder
{
    void* __thiscall FUN_00c6c410(unsigned int a);
};
// Calls the base cleanup, then frees this object with operator delete when bit 0 of a is set, and returns this.
// @fnv 0x00c6c410
void* FUN_00c6c410_cls::FUN_00c6c410(unsigned int auiFlags)
{
    FUN_00c6c290();
    if (auiFlags & 1)
        operator delete(this, 0x14);
    return this;
}

extern double DAT_01011588;

struct FUN_00c6c720_class
{
    void __thiscall AccumulateValue(int index, float value);
};

// If the float at this+0x50[index] equals FLT_MIN it stores value there, otherwise adds value to it and stores the sum scaled by DAT_01011588.
// @fnv 0x00c6c720
void __thiscall FUN_00c6c720_class::AccumulateValue(int index, float value)
{
    float* p = (float*)((char*)this + 0x50);
    if (p[index] == 1.1754943508222875e-38f)
        p[index] = value;
    else
    {
        value += p[index];
        p[index] = value * DAT_01011588;
    }
}

extern int DAT_010c446c;
struct FUN_00c6c770_Class
{
    int* vtbl;
    FUN_00c6c770_Class* __thiscall FUN_00c6c770(unsigned int a);
};
// Sets the vtable pointer and, when bit 0 of a is set, frees this object through the memory manager; returns this.
// @fnv 0x00c6c770
FUN_00c6c770_Class* __thiscall FUN_00c6c770_Class::FUN_00c6c770(unsigned int auiFlags)
{
    vtbl = &DAT_010c446c;
    if (auiFlags & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

extern int DAT_010c446c;
struct FUN_00c6cb70_class
{
    int* vtbl;
    void* __thiscall FUN_00c6cb70(int a);
};
// Sets the vtable pointer and, when bit 0 of a is set, frees the object via the memory manager, then returns this.
// @fnv 0x00c6cb70
void* __thiscall FUN_00c6cb70_class::FUN_00c6cb70(int aiFlags)
{
    vtbl = &DAT_010c446c;
    if (aiFlags & 1)
        _g_memoryManager.Deallocate((char*)this - *(unsigned char*)((char*)this - 1));
    return this;
}

void __cdecl operator delete(void*, unsigned int);
struct FUN_00cd2de0
{
    int m_iWordAt00;
    void Init();
};
struct FUN_00c6cda0_cls : FUN_00cd2de0
{
    FUN_00c6cda0_cls* FUN_00c6cda0(int ab);
};
// Calls Init, then if bit 0 of ab is set deletes this with size 0x14 and returns this.
// @fnv 0x00c6cda0
FUN_00c6cda0_cls* FUN_00c6cda0_cls::FUN_00c6cda0(int abDelete)
{
    FUN_00cd2de0::Init();
    if (abDelete & 1)
        operator delete(this, 0x14);
    return this;
}

struct FUN_00cc2350_s
{
    void FUN_00cc2350();
};
struct FUN_00c6d100_s : FUN_00cc2350_s
{
    FUN_00c6d100_s* FUN_00c6d100(bool a);
};
// Calls FUN_00cc2350, then deletes this with size 0x18 when a is set, and returns this.
// @fnv 0x00c6d100
FUN_00c6d100_s* FUN_00c6d100_s::FUN_00c6d100(bool abFree)
{
    FUN_00cc2350();
    if (abFree & 1)
        operator delete(this, 0x18);
    return this;
}

struct S_00c85ce0
{
    void bhkWorldObject_SetCollisionGroup(unsigned int);
};
struct FUN_00c6d770_class
{
    char pad[0x594];
    void* m_594;
    void* m_598;
    void bhkCharacterController_SetCollisionGroup(unsigned int a);
};
// Forwards a to FUN_00c85ce0 on m_594 and m_598 when each pointer is non-null.
// @fnv 0x00c6d770
// src: COMMUNITY 0x00c6d770
void FUN_00c6d770_class::bhkCharacterController_SetCollisionGroup(unsigned int auiValue)
{
    if (m_594)
        ((S_00c85ce0*)m_594)->bhkWorldObject_SetCollisionGroup(auiValue);
    if (m_598)
        ((S_00c85ce0*)m_598)->bhkWorldObject_SetCollisionGroup(auiValue);
}

struct FUN_008d1160_Class
{
    void FUN_00c705c0();
};
struct FUN_00c70c60_Class : FUN_008d1160_Class
{
    char* __thiscall FUN_00c70c60(unsigned char abFree);
};
// Calls FUN_00c705c0, then if abFree bit 0 is set and this is non-null, frees the block at this minus the byte at this[-1]; returns this.
// @fnv 0x00c70c60
char* FUN_00c70c60_Class::FUN_00c70c60(unsigned char abFree)
{
    FUN_00c705c0();
    if ((abFree & 1) && this)
        _g_memoryManager.Deallocate(reinterpret_cast<char*>(this) - reinterpret_cast<unsigned char*>(this)[-1]);
    return reinterpret_cast<char*>(this);
}

extern int DAT_010c4b2c;
struct FUN_00c74760
{
    int* vtbl;
    int m_uiRefCount;
    unsigned char m_bFlag;
    int m_iFadeIndex;
    int m_iState2;
    FUN_00c74760();
};

// @fnv 0x00c74760
FUN_00c74760::FUN_00c74760()
{
    m_iFadeIndex = 0;
    m_iState2 = 0;
    m_uiRefCount = 1;
    m_bFlag = 1;
    vtbl = &DAT_010c4b2c;
}

// Allocates a+0x10 bytes from _g_memoryManager, aligns the returned pointer to 16 bytes and stores the alignment offset in the byte before it.
// @fnv 0x00c74ea0
// src: COMMUNITY 0x00c74ea0
void* MemoryManager_AlignedAllocate16(unsigned int uiSize)
{
    unsigned char* p = (unsigned char*)((Heap*)&_g_memoryManager)->Allocate(uiSize + 0x10);
    unsigned char n = (unsigned char)(0x10 - ((unsigned char)p & 0xf));
    p += n;
    p[-1] = n;
    return p;
}

// The allocator getter returns a four-byte value wrapper.
struct RouterReturnValue_c60000
{
    void* m_p;
};
RouterReturnValue_c60000 __cdecl _D1A0E0GetMemoryRouter();

// @fnv 0x00c74f90
// src: GUESS 0x00c74f90 (confidence: low)
void __cdecl Runtime_UpdateState_00c74f90(void* a)
{
    if (a)
    {
        void* r = *(void**)((char*)_D1A0E0GetMemoryRouter().m_p + 0x10);
        void* vt = *(void**)r;
        void* fn = *(void**)((char*)vt + 8);
        ((void(__thiscall*)(void*, void*, unsigned int))fn)(r, a, 0x30);
    }
}


void __cdecl _NiFree(void* p);
extern int DAT_010c4ca4;


// @fnv 0x00c76070
void* __fastcall FUN_00c76070(RagdollMapBase* self, void*, unsigned int flags)
{
    *reinterpret_cast<void**>(self) = &DAT_010c4ca4;
    self->RemoveAll();
    _NiFree(self->m_ppkHashTable);
    if (flags & 1)
        _g_memoryManager.Deallocate(self);
    return self;
}

// @fnv 0x00c7a5b0
void* __fastcall DeleteObjectMap(NiTMap<NiAVObject*, short>* self, void*, unsigned int flags)
{
    self->NiTMap::~NiTMap();
    if (flags & 1)
        _g_memoryManager.Deallocate(self);
    return self;
}

extern int DAT_010c5398;
struct FUN_00c7fb20
{
    int* m_vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00c7fb20();
};
// @fnv 0x00c7fb20
FUN_00c7fb20::FUN_00c7fb20()
{
    m_iWordAt04 = 0;
    m_8 = 1;
    m_iThirdValue = 0;
    m_10 = 0;
    m_vtbl = &DAT_010c5398;
}

extern int DAT_011afe5c;

// Maps param_1 (0, 1, 4, or other) to 1, 2, 3, or 2 and stores it in DAT_011afe5c.
// @fnv 0x00c661d0
// src: COMMUNITY 0x00c661d0
void __cdecl bhkWorldCinfo_SetSimulationType(int aiCode)
{
    switch (aiCode)
    {
    case 0:
        DAT_011afe5c = 1;
        break;
    case 1:
        DAT_011afe5c = 2;
        break;
    case 4:
        DAT_011afe5c = 3;
        break;
    default:
        DAT_011afe5c = 2;
        break;
    }
}

extern unsigned char DAT_012677a3;

// @fnv 0x00c66230
// src: XBOX_PDB 0x00c66230
void __cdecl bhkWorld_SetPickCountOverride(unsigned char a)
{
    DAT_012677a3 = a;
}

struct FUN_00c66250_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
};

// @fnv 0x00c66250
// src: COMMUNITY 0x00c66250
void bhkWorld_NI2HKObject(FUN_00c66250_cls* p)
{
    p->m_0c |= 0x40;
}

class FUN_00c66280_obj
{
  public:
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual int v2c(void* p, int zero, bool flag);
};

struct FUN_00c66280_arg
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
    int m_10;
};

// Calls the virtual method v2c on a1, passing a2->m_0c, zero, and whether a2->m_10 is nonzero, and returns its result.
// @fnv 0x00c66280
int CallVirtualWithArg(FUN_00c66280_obj* pObj, FUN_00c66280_arg* a2)
{
    return pObj->v2c(a2->m_0c, 0, a2->m_10 != 0);
}

struct FUN_00c662d0_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void* vf3C();
};

struct FUN_00c81b40_Tgt
{
    void UpdateCountdown();
};

struct FUN_00c81ae0_Tgt
{
    void InitOnce();
};

struct Param2Struct
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

// If param_1 is non-null, gets its vf3C result and calls UpdateCountdown or InitOnce on it depending on whether param_2->unk0C is zero.
// @fnv 0x00c662d0
void __cdecl DispatchOnParamFlag(FUN_00c662d0_Obj* pObj, Param2Struct* pParams)
{
    if (pObj != NULL)
    {
        void* pResult = pObj->vf3C();

        if (pResult != NULL)
        {
            if (pParams->unk0C == 0)
            {
                ((FUN_00c81b40_Tgt*)pResult)->UpdateCountdown();
            }
            else
            {
                ((FUN_00c81ae0_Tgt*)pResult)->InitOnce();
            }
        }
    }
}

extern int DAT_010c3bc4;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00c66510_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;

    void BaseRelease();
    FUN_00c66510_cls* FUN_00c66510(unsigned char acFlags);
};

// Sets the vtable pointer, calls BaseRelease, and if bit 0 of acFlags is set frees this through the allocator from FUN_00c85750 using m_uSize.
// @fnv 0x00c66510
FUN_00c66510_cls* FUN_00c66510_cls::FUN_00c66510(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010c3bc4;
    BaseRelease();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        reinterpret_cast<void (__thiscall*)(hkMemoryAllocator*, void*, unsigned int)>((*reinterpret_cast<void***>(pAllocator))[2])(pAllocator, this, m_uSize);
    }
    return this;
}

extern __declspec(thread) int DAT_000002b4;

struct ThreadMemoryScope
{
    int previous;
    ThreadMemoryScope() : previous(DAT_000002b4)
    {
        DAT_000002b4 = 16;
    }
    ~ThreadMemoryScope()
    {
        DAT_000002b4 = previous;
    }
};

struct ThreadObserver
{
    virtual void onInit();
    virtual void onShutdown();
    virtual void notify(int enabled);
};

extern ThreadObserver* DAT_01268450;

// Creates a ThreadMemoryScope and, if DAT_01268450 is non-null, calls its notify with 1.
// @fnv 0x00c66570
void __cdecl NotifyThreadObserverEnabled()
{
    ThreadMemoryScope scope;
    if (DAT_01268450 != 0)
    {
        DAT_01268450->notify(1);
    }
}

extern int DAT_010c3bb8;

struct FUN_00c665f0_cls
{
    int m_vptr00;

    void SetVptr00();
};

// @fnv 0x00c665f0
// src: GUESS 0x00c665f0 (confidence: low)
void FUN_00c665f0_cls::SetVptr00()
{
    m_vptr00 = (int)&DAT_010c3bb8;
}

class FUN_00c66de0_cls;

class FUN_00c66de0_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual FUN_00c66de0_cls* v94();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    FUN_00c66de0_cls* m_350;
    void Reset(bool flag);
    void bhkWorld_Link(bool flag);
};

// If this is non-null, stores this (or null when flag is false) into the m_350 field of the object returned by v94, then calls Reset(flag).
// @fnv 0x00c66de0
// src: XBOX_PDB 0x00c66de0
void FUN_00c66de0_cls::bhkWorld_Link(bool flag)
{
    if (this != 0)
    {
        FUN_00c66de0_cls* p = this->v94();
        if (p != 0)
            p->m_350 = flag ? this : 0;
    }
    this->Reset(flag);
}

extern __declspec(thread) int hkThreadHeapState;

struct HavokOwner
{
    virtual void release(unsigned int flag);
};

struct HavokThreadStateScope
{
    int previousState;

    HavokThreadStateScope() : previousState(hkThreadHeapState)
    {
        hkThreadHeapState = 16;
    }

    ~HavokThreadStateScope()
    {
        hkThreadHeapState = previousState;
    }
};

struct FUN_00c66e70_Class
{
    int unk00;
    int unk04;
    int unk08;
    char* objectData;

    void bhkWorld_KillCinfo(char destroy);
};

// If destroy is set, releases the HavokOwner stored before objectData and clears objectData.
// @fnv 0x00c66e70
// src: XBOX_PDB 0x00c66e70
void FUN_00c66e70_Class::bhkWorld_KillCinfo(char destroy)
{
    HavokThreadStateScope scope;
    if (destroy)
    {
        if (objectData)
        {
            HavokOwner* owner = reinterpret_cast<HavokOwner*>(objectData - 0xf0);
            if (owner)
                owner->release(1);
        }
        objectData = 0;
    }
}

struct FUN_00c66f90_Result
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct FUN_00c66f90_Class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual FUN_00c66f90_Result* vf94();

    bool bhkWorld_HasActiveItems();
};

// @fnv 0x00c66f90
// src: XBOX_PDB 0x00c66f90
bool FUN_00c66f90_Class::bhkWorld_HasActiveItems()
{
    bool result = false;
    FUN_00c66f90_Result* object = vf94();

    if (object)
        result = object->unk2C != 0;

    return result;
}

struct UpdateParams
{
    float fTime;
    bool b0;
    bool b1;
    bool b2;
    bool b3;
    bool b4;
    UpdateParams() : fTime(0.0f), b0(false), b1(false), b2(false), b3(false), b4(false)
    {}
};

struct SubObj
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short usFlags;
};

struct Target
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual int GetID();  // 0x94
    virtual void v38();
    virtual void SetSource(Target* p);  // 0x9c
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
    int unk0c;
    char unk10;
    char unk11;
    char unk12;
    char unk13;
    char unk14;
    char unk15;
    char bEnabled;
};

struct Updater
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void Update(UpdateParams* p);  // 0xb8
};

struct ControlledObj
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
    virtual SubObj* GetSub();  // 0x3c
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void Activate(bool b);  // 0xc0
    int unk04;
    Updater* pUpdater;
    unsigned short usFlags;
    Target* pTarget;
};

struct UpdateData
{
    Target* pSource;
    int unk04;
    int unk08;
    unsigned int bPending : 1;
    int unk10;
    int iCount;
    int iMode;
};

extern bool DAT_011afe58;
void __cdecl AssignSystemGroup(Target* t, UpdateData* d);

// Updates the controlled object's sub-object and flags from the update data, syncs the target source, runs the updater, and increments the data count.
// @fnv 0x00c66ff0
// src: COMMUNITY 0x00c66ff0
void __cdecl bhkWorld_AddObject(ControlledObj* pControlledObj, UpdateData* data)
{
    Target* target = pControlledObj->pTarget;
    if (target)
    {
        SubObj* sub = pControlledObj->GetSub();
        if (sub)
        {
            if (data->iCount == 0)
                sub->usFlags |= 0x100;
            else
                sub->usFlags &= ~0x100;
        }
        bool bPending = data->bPending;
        if (bPending)
            pControlledObj->usFlags |= 4;
        else
            pControlledObj->usFlags &= ~4;
        if (bPending)
            pControlledObj->usFlags |= 8;
        if (DAT_011afe58)
            AssignSystemGroup(target, data);
        int iSourceID = data->pSource->GetID();
        if (target->GetID() != iSourceID)
        {
            if (data->iMode)
                pControlledObj->usFlags |= 0x40;
            else
                pControlledObj->usFlags &= ~0x40;
            target->SetSource(data->pSource);
        }
        UpdateParams params;
        pControlledObj->pUpdater->Update(&params);
        if (data->pSource->bEnabled)
            pControlledObj->Activate(true);
    }
    data->bPending = 0;
    data->iCount++;
}

struct FUN_00c85d20_Class
{
    void __thiscall bhkWorldObject_EnableCollision(bool enabled);
};

struct FUN_00c67130_First
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00c85d20_Class* unk10;
};

struct FUN_00c67130_Second
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

// If first->unk10 is set, calls its FUN_00c85d20 with whether second->unk0c is non-zero.
// @fnv 0x00c67130
void __cdecl SetEnabledFromFlag(FUN_00c67130_First* first, FUN_00c67130_Second* second)
{
    if (first->unk10)
    {
        first->unk10->bhkWorldObject_EnableCollision(second->unk0c != 0);
    }
}

// SetBodyFloat94
//
// Copies a float that arrives in a parameter record into the physics body that
// is reachable through the object stored in a world record:
//
//   record->m_pObject->vtable[16]()  ->  holder
//   holder->m_pPhysicsBody->m_f94           =  param->m_f0c
//
// The call goes through the object's slot table (slot 16, offset 0x40) and the
// slot is invoked with the object as its "this" argument.

struct BhkPhysBody
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    float m_f94;
};

// Result handed back by the slot call; m_pPhysicsBody points at the physics body.
struct BhkPhysResult
{
    int unk00;
    int unk04;
    BhkPhysBody* m_pPhysicsBody;
};

struct BhkPhysObject;

// Slot 16 of the object's slot table: takes the object, returns the holder.
typedef BhkPhysResult*(__fastcall* BhkPhysGetResult)(BhkPhysObject* pSelf);

struct BhkPhysSlotTable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    BhkPhysGetResult m_fnGetResult;
};

struct BhkPhysObject
{
    BhkPhysSlotTable* m_pSlots;
};

// World record: the physics object it refers to sits at offset 0x10.
struct BhkPhysRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BhkPhysObject* m_pObject;
};

// Parameter record: the float to copy sits at offset 0xc.
struct BhkPhysParam
{
    int unk00;
    int unk04;
    int unk08;
    float m_f0c;
};

// Gets the physics result from the record's object and writes pParam->m_f0c into the body's m_f94, returning early if the object or result is null.
// @fnv 0x00c67150
void SetBodyFloat94(BhkPhysRecord* pRecord, BhkPhysParam* pParam)
{
    BhkPhysObject* pObject = pRecord->m_pObject;
    if (pObject == 0)
        return;

    BhkPhysGetResult fnGetResult = pObject->m_pSlots->m_fnGetResult;
    BhkPhysResult* pResult = fnGetResult(pObject);
    if (pResult == 0)
        return;

    pResult->m_pPhysicsBody->m_f94 = pParam->m_f0c;
}

struct FUN_00c67180_Target
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    float m_90;
};

struct FUN_00c67180_Holder
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_00c67180_Target* m_pFlagTarget;
};

struct FUN_00c67180_Node
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual FUN_00c67180_Holder* GetHolder();
};

struct FUN_00c67180_Arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    float m_0c;
};

struct FUN_00c67180_Owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_00c67180_Node* m_pReferencedNode;
};

// Gets the holder from owner's node and copies arg's m_0c float into the holder target's m_90, returning early if node or holder is null.
// @fnv 0x00c67180
void __cdecl SetTargetFloat(FUN_00c67180_Owner* owner, FUN_00c67180_Arg* volatile arg)
{
    FUN_00c67180_Node* node = owner->m_pReferencedNode;
    if (node == 0)
        return;
    FUN_00c67180_Holder* holder = node->GetHolder();
    if (holder == 0)
        return;
    FUN_00c67180_Target* target = holder->m_pFlagTarget;
    target->m_90 = arg->m_0c;
}

struct FUN_00561580_class
{
    void bhkRigidBody_SetActive(bool enabled);
};
struct FUN_00c671b0_dispatch
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual FUN_00561580_class* vf40();
};
struct FUN_00c671b0_source
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00c671b0_dispatch* dispatcher;
};
struct FUN_00c671b0_state
{
    int unk00;
    int unk04;
    int unk08;
    int enabled;
};
// @fnv 0x00c671b0
void __cdecl SetEnabledOnDispatcherObject(FUN_00c671b0_source* source, FUN_00c671b0_state* state)
{
    if (source)
    {
        FUN_00c671b0_dispatch* dispatcher = source->dispatcher;
        if (dispatcher)
        {
            FUN_00561580_class* object = dispatcher->vf40();
            if (object)
                object->bhkRigidBody_SetActive(state->enabled != 0);
        }
    }
}

class C67240RefObject
{
  public:
    void SetLayer(unsigned int uiLayer);
};

struct C67240WorldObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C67240RefObject* m_pPointer;
};

struct C67240Params
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiLayer;
};

// @fnv 0x00c67240
void ApplyLayerToRefObject(C67240WorldObject* pkWorldObject, C67240Params* pkParams)
{
    if (pkWorldObject->m_pPointer)
        pkWorldObject->m_pPointer->SetLayer(pkParams->m_uiLayer);
}

struct C67260Bool
{
    char m_cBooleanValue;

    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct C67260Entity
{
    C67260Bool isActive_00c9bff0() const;
};

struct C67260Shape
{
    int unk00;
    int unk04;
    C67260Entity* m_pkEntity;
};

class C67260Body
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual C67260Shape* GetShape();
};

struct C67260CollisionObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C67260Body* m_pkBody;
};

struct C67260Context
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    int iCount;
};

// If the object's body shape has an entity whose check returns true, increments pkContext->iCount, then clears pkContext->bRecurse.
// @fnv 0x00c67260
void CountEntityAndClearRecurse(C67260CollisionObject* pkObject, C67260Context* pkContext)
{
    C67260Body* pkBody = pkObject->m_pkBody;
    if (!pkBody)
        return;
    C67260Shape* pkShape = pkBody->GetShape();
    if (!pkShape)
        return;
    C67260Entity* pkEntity = pkShape->m_pkEntity;
    if (pkEntity ? (bool)pkEntity->isActive_00c9bff0() : false)
        pkContext->iCount++;
    pkContext->bRecurse = false;
}

void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
struct BodyView : hkReferencedObject
{
    void* world;
};
struct SpaceView
{
    void DispatchOrQueue(BodyView*);
};
extern __declspec(thread) int threadContext;
struct ContextGuard
{
    int previous;
    ContextGuard() : previous(threadContext)
    {
        threadContext = 16;
    }
    ~ContextGuard()
    {
        threadContext = previous;
    }
};
struct WorldView
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual SpaceView* vfn37();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    BodyView** bodies;
    unsigned int count;
    void ReleaseBodies();
};
// @fnv 0x00c67cd0
void WorldView::ReleaseBodies()
{
    ContextGuard guard;
    if (count > 0)
    {
        if (count >= 100)
            count = 100;
        SpaceView* space = vfn37();
        if (space)
        {
            for (unsigned int i = 0; i < count; ++i)
            {
                if (bodies[i] && bodies[i]->world)
                    space->DispatchOrQueue(bodies[i]);
                if (bodies[i])
                    bodies[i]->removeReference();
            }
            FUN_00ec61c0(bodies, 0, count * sizeof(BodyView*));
            count = 0;
        }
    }
}

namespace fnv_00c67df0 {
void* _fnv_zlib_memset(void*, int, unsigned int);
extern unsigned int DAT_0126fd98;
struct ThreadContext
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    unsigned int context;
};
extern __declspec(thread) ThreadContext threadContext;
struct ContextGuard
{
    unsigned int saved;
    ContextGuard(unsigned int value)
    {
        saved = threadContext.context;
        threadContext.context = value;
    }
    ~ContextGuard()
    {
        threadContext.context = saved;
    }
};
struct PendingItem
{
    int unk00, unk04;
    void* owner;
};
struct PendingQuery
{
    void __thiscall hkpWorld_removeConstraint(char*, PendingItem*);
};
struct PendingWorld : FUN_00c6b320_Base
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    PendingItem** items;
    unsigned int count;
    void __thiscall ProcessPendingItems();
};
// @fnv 0x00c67df0
void PendingWorld::ProcessPendingItems()
{
    ContextGuard guard(16);
    if (count)
    {
        if (count >= 200)
            count = 200;
        PendingQuery* query = (PendingQuery*)v37();
        if (query)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                if (items[index] && items[index]->owner)
                {
                    char status;
                    query->hkpWorld_removeConstraint(&status, items[index]);
                }
                if (items[index])
                    ((hkReferencedObject*)items[index])->removeReference();
            }
            _fnv_zlib_memset(items, 0, count * sizeof(PendingItem*));
            count = 0;
        }
    }
}
}  // namespace fnv_00c67df0

class C67F20RefObject
{
  public:
    virtual ~C67F20RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

struct C67F20Heap
{
    void Deallocate(void* pvMem);
};

extern C67F20Heap g_kC67F20Heap;

struct C67F20Node
{
    int unk00;
    C67F20Node* m_pkNext;

    ~C67F20Node();

    static void operator delete(void* pvMem)
    {
        g_kC67F20Heap.Deallocate(pvMem);
    }
};

class C67F20List
{
  public:
    NiPointer<C67F20RefObject> m_spOwner;
    C67F20Node* m_pkHead;

    void DeleteListNodesAndReleaseOwner();
};

// Deletes every node in the list, unlinking each one, then releases the owner pointer.
// @fnv 0x00c67f20
// src: GUESS 0x00c67f20 (confidence: medium)
void C67F20List::DeleteListNodesAndReleaseOwner()
{
    while (m_pkHead)
    {
        C67F20Node* pkNext = m_pkHead->m_pkNext;
        m_pkHead->m_pkNext = 0;
        delete m_pkHead;
        m_pkHead = pkNext;
    }
    m_spOwner = NiPointer<C67F20RefObject>(0);
}

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* section);
struct CriticalSection
{
    void* debugInfo;
    long lockCount;
    long recursionCount;
    void* ownerThread;
    void* semaphore;
    unsigned long spinCount;
    CriticalSection()
    {
        InitializeCriticalSection(this);
    }
    ~CriticalSection()
    {
        DeleteCriticalSection(this);
    }
};
struct LifoAllocator
{
    void* current;
    void* end;
    void* firstNonLifoEnd;
    unsigned int slabSize;
    void* buffer;
    void* backingAllocator;
    int allocationCount;
};
struct HavokRouter
{
    void* temporaryAllocator;
    void* heapAllocator;
    void* debugAllocator;
    LifoAllocator stackAllocator;
};
struct RouterSlot
{
    int state;
    HavokRouter memory;
    RouterSlot();
    ~RouterSlot();
};
struct FUN_00c67fe0
{
    CriticalSection lock;
    RouterSlot routers[16];
    int state;
    FUN_00c67fe0();
};
// @fnv 0x00c67fe0
FUN_00c67fe0::FUN_00c67fe0() : state(0)
{}

extern int DAT_012681e0;

struct FNVEntryKey
{
    unsigned int lo;
    unsigned int hi;
};

class FNVEntryTarget
{
  public:
    void hkDebugDisplay_setGeometryColor(unsigned int a, unsigned int b, int c);
};

class FUN_00c688b0_cls
{
  public:
    unsigned int unk00[4];
    unsigned int m_0x10;
    unsigned char unk14[0x68];
    FNVEntryKey* m_0x7c;
    unsigned int m_0x80;

    void ProcessEntries_00c688b0();
};

// If m_0x10 is nonzero, calls FUN_00c984a0 on each of the m_0x80 entries in m_0x7c in reverse order, then resets m_0x80 to 0.
// @fnv 0x00c688b0
// src: GUESS 0x00c688b0 (confidence: low)
void FUN_00c688b0_cls::ProcessEntries_00c688b0()
{
    if (m_0x10 == 0)
        goto done;
    {
        unsigned int n = m_0x80;
        if (n != 0)
        {
            do
            {
                --n;
                FNVEntryKey* item = &m_0x7c[n];
                FNVEntryTarget* target = *reinterpret_cast<FNVEntryTarget**>(&DAT_012681e0);
                target->hkDebugDisplay_setGeometryColor(item->hi, item->lo, 0);
            } while (n != 0);
        }
    }
done:
    m_0x80 = 0;
}

struct S_00c68900_Node;

struct S_00c68900_Ref
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8()
    {}
    virtual void v9()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void* v14()
    {
        return 0;
    }
};

struct S_00c68900_Node
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual NiNode* v3()
    {
        return 0;
    }

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S_00c68900_Ref* m_pReference;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int m_flags;
};

struct S_00c68900_Context
{
    int unk00;
    unsigned char m_bEnableState;
    unsigned int unk08;
};

typedef void(__cdecl* S_00c68900_Callback)(void* object, S_00c68900_Context* context);

void __cdecl FUN_005171c4(S_00c68900_Node* node, S_00c68900_Context* context, S_00c68900_Callback callback);

// @fnv 0x00c68900
// src: COMMUNITY 0x00c68900
void __cdecl bhkWorld_DoObjectRec(S_00c68900_Node* node, S_00c68900_Context* context, S_00c68900_Callback callback)
{
    if (!node)
        return;

    void* object;
    if (node->m_pReference)
        object = node->m_pReference->v14();
    else
        object = 0;

    if (!context->unk08)
        node->m_flags = (node->m_flags & 0xffffffef) | 6;

    if (object)
        callback(object, context);

    if (context->m_bEnableState)
    {
        NiNode* items = node->v3();
        if (items)
        {
            unsigned int index = 0;
            while (index < items->m_kChildren.m_usSize)
            {
                S_00c68900_Node* child = reinterpret_cast<S_00c68900_Node*>(items->m_kChildren.m_pBase[index].m_pObject);
                FUN_005171c4(child, context, callback);
                ++index;
            }
        }
    }
}

class Fnv68990Flagged
{
  public:
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int m_flags;
};

class Fnv68990Inner
{
  public:
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual Fnv68990Flagged* GetFlagged();
};

class Fnv68990Holder
{
  public:
    unsigned int unk00, unk04, unk08, unk0C;
    Fnv68990Inner* m_pInner;
};

class Fnv68990Arg
{
  public:
    unsigned int unk00, unk04, unk08;
    unsigned int m_flag0C;
};

// If the holder's inner object and its flagged object exist, sets or clears bit 0x40 in the flagged object's m_flags based on arg->m_flag0C.
// @fnv 0x00c68990
void SetFlaggedBit40(Fnv68990Holder* holder, Fnv68990Arg* arg)
{
    Fnv68990Inner* inner = holder->m_pInner;
    if (inner == 0)
    {
        return;
    }
    Fnv68990Flagged* f = inner->GetFlagged();
    if (f == 0)
    {
        return;
    }
    if (arg->m_flag0C != 0)
    {
        f->m_flags |= 0x40;
    }
    else
    {
        f->m_flags &= 0xffffffbf;
    }
}

// Physics shape bookkeeping: fetch the body that owns the shape and ask it
// to re-create the shape when the shape is missing or has the "static" type.
struct PhysShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAc;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBc;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCc;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDc;
    int unkE0;
    int unkE4;
    unsigned char m_nShapeType;
};

struct PhysBody
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
    virtual PhysBody* v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57(int a);
    int m_iWordAt04;
    PhysShape* m_pShape;
};

struct PhysOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    PhysBody* m_pPhysicsBody;
};

// Gets the body from pOwner, resolves its shape body, and calls v57(4) when the shape is missing or its m_nShapeType is 5.
// @fnv 0x00c689c0
// src: COMMUNITY 0x00c689c0
void __cdecl bhkWorld_FixedToKeyframedObject(PhysOwner* pOwner)
{
    PhysBody* pBody = pOwner->m_pPhysicsBody;
    if (pBody != 0)
    {
        PhysBody* pShapeBody = pBody->v16();
        if (pShapeBody != 0)
        {
            PhysShape* pShape = pShapeBody->m_pShape;
            unsigned int uiShapeType = 0;
            if (pShape != 0)
                uiShapeType = pShape->m_nShapeType;
            if (pShape == 0 || uiShapeType == 5)
            {
                pShapeBody->v57(4);
            }
        }
    }
}

extern __declspec(thread) unsigned int g_havokThreadState[174];

struct ScopedHavokThreadMode
{
    unsigned int oldMode;
    ScopedHavokThreadMode() : oldMode(g_havokThreadState[173])
    {
        g_havokThreadState[173] = 16;
    }
    ~ScopedHavokThreadMode()
    {
        g_havokThreadState[173] = oldMode;
    }
};

struct FUN_00c674d0_Call
{
    void __thiscall bhkWorld_AddEntities(unsigned int resource, unsigned int count);
};

// Clamps the count at offset 0x30 to 3000, passes it with the resource at 0x2c to FUN_00c674d0, then resets the count to 0.
// @fnv 0x00c68a40
// src: COMMUNITY 0x00c68a40
void FUN_00c68a40_Class::bhkWorld_AddBatchedEntities()
{
    ScopedHavokThreadMode threadMode;
    unsigned int& count = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x30);
    if (count > 0)
    {
        if (count >= 3000)
            count = 3000;
        reinterpret_cast<FUN_00c674d0_Call*>(this)->bhkWorld_AddEntities(
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x2c), count);
        count = 0;
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* p);

class RefObj_b5063
{
  public:
    virtual void Reserved_b5063();
    virtual void DeleteThis();
    volatile long m_refs;
};

class Owner_b5063
{
  public:
    RefObj_b5063* m_pEntryObject;
    void LockOwner();
    void LockOwnerAndRelease();
};

struct Holder_b5063
{
    Owner_b5063* m_pOwnerObject;
    Holder_b5063(Owner_b5063* owner) : m_pOwnerObject(owner)
    {}
    ~Holder_b5063()
    {
        RefObj_b5063* obj = m_pOwnerObject->m_pEntryObject;
        if (obj != 0)
        {
            if (InterlockedDecrement(&obj->m_refs) == 0)
            {
                obj->DeleteThis();
            }
        }
    }
};

// Creates a Holder_b5063 for this owner, then calls LockOwner; the holder releases the owner's reference on destruction.
// @fnv 0x00c68ae0
void Owner_b5063::LockOwnerAndRelease()
{
    Holder_b5063 holder(this);
    LockOwner();
}

namespace fnv_00c68bc0 {
// FUN_00c68bc0 (42 bytes)
//
// The first virtual of bhkWorldCinfo (its vftable lives at 0x010c3c44 and its
// slot 0 points here; the sibling hkpWorldCinfo::FUN_005535c0 at 0x005535c0
// is the same routine built with /Od).
//
//   push esi / mov esi,ecx     `this` is parked in a callee-saved register
//   call 0x00553540            hkpWorldCinfo's initialiser, called on `this`
//   test byte ptr [esp+8],1    the caller's flag, only its low bit matters
//   je    <end>
//   call 0x00c85750            the global audio/system manager
//   movzx edx,word ptr [esi+4] this->unk04
//   mov   ecx,[eax+0x10]       the manager's sink object
//   mov   eax,[ecx] / mov eax,[eax+8]   its vtable slot 2
//   push  edx / push esi / call eax
//   mov   eax,esi / pop esi / ret 4      the function returns `this`

struct BhkWorldCinfo;

struct WorldSink
{
    virtual void v00();
    virtual void v04();
    virtual void v08(BhkWorldCinfo* pWorld, unsigned short w);  // vtable +0x08
};

struct BhkWorldCinfo
{
    void* vtbl;            // +0x00 (the real vtable pointer)
    unsigned short unk04;  // +0x04
    void FUN_00553540();
    BhkWorldCinfo* FUN_00c68bc0(int flag);
};

extern hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

// Calls FUN_00553540, and if flag bit 0 is set notifies the system manager's sink with this and unk04, then returns this.
// @fnv 0x00c68bc0
BhkWorldCinfo* BhkWorldCinfo::FUN_00c68bc0(int flag)
{
    this->FUN_00553540();

    if (flag & 1)
    {
        hkMemoryRouter* sys = hkMemoryRouter_getInstance();
        reinterpret_cast<WorldSink*>(sys->m_heap)->v08(this, this->unk04);
    }

    return this;
}
}  // namespace fnv_00c68bc0

struct FUN_00c68f50_cls;

struct FUN_00aa4060_cls
{
    void MemoryManager_Deallocate(FUN_00c68f50_cls* node);
};

extern FUN_00aa4060_cls DAT_011f6238;

struct FUN_00c68f50_cls
{
    NiPointer<FUN_00c663d0_Ref> m_key;
    FUN_00c68f50_cls* m_next;

    void LockOwnerAndRelease();
    void RemoveKey(FUN_00c663d0_Ref** pKey);
};

// @fnv 0x00c68f50
void FUN_00c68f50_cls::RemoveKey(FUN_00c663d0_Ref** pKey)
{
    FUN_00c663d0_Ref* key = *pKey;
    if (key == 0)
    {
        return;
    }
    FUN_00c68f50_cls* head_next = m_next;
    if (head_next == 0 && m_key.m_pObject == 0)
    {
        return;
    }
    FUN_00c68f50_cls* cur = this;
    FUN_00c68f50_cls* prev = this;
    do
    {
        if (cur->m_key.m_pObject == key)
        {
            goto found;
        }
        prev = cur;
        cur = cur->m_next;
    } while (cur != 0);
    return;

found:
    if (cur == this)
    {
        if (head_next != 0)
        {
            m_next = head_next->m_next;
            m_key = head_next->m_key;
            head_next->m_next = 0;
            head_next->LockOwnerAndRelease();
            DAT_011f6238.MemoryManager_Deallocate(head_next);
            return;
        }
        FUN_00c663d0_Ref* obj = m_key.m_pObject;
        if (obj == 0)
        {
            return;
        }
        if (InterlockedDecrement(&obj->m_uiRefCount) == 0)
        {
            obj->v1();
        }
        m_key.m_pObject = 0;
        return;
    }
    prev->m_next = cur->m_next;
    cur->m_next = 0;
    cur->LockOwnerAndRelease();
    DAT_011f6238.MemoryManager_Deallocate(cur);
}

struct CpuOpaque;
extern CpuOpaque DAT_01267824;
// @fnv 0x00c69220
// src: COMMUNITY 0x00c69220
CpuOpaque* __cdecl bhkWorld_GetRTTI()
{
    return &DAT_01267824;
}

// @fnv 0x00c69230
// src: COMMUNITY 0x00c69230
int __cdecl bhkWorld_GetCinfoSize()
{
    return 240;
}

extern void* DAT_011afe90;

struct S_00c69f50_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

S_00c69f50_Obj* GetExtraDataChecked(S_00c69f50_Obj* obj);
void bhkWorld_DoObjectRec(S_00c69f50_Obj* obj, int* ctx, void* g);

// @fnv 0x00c69f50
// src: XBOX_PDB 0x00c69f50
bool bhkWorld_UpdatePosition(S_00c69f50_Obj* obj, unsigned char ucValue, unsigned char ucForce)
{
    bool result = false;
    if (obj)
    {
        S_00c69f50_Obj* info;
        if (ucForce || ((info = GetExtraDataChecked(obj)) ? (info->unk0c & 2) : 0))
        {
            int ctx[7];
            result = true;
            *(unsigned char*)&ctx[1] = ucValue;
            void* g = DAT_011afe90;
            ctx[0] = 0;
            ctx[2] = 2;
            if (g)
            {
                bhkWorld_DoObjectRec(obj, &ctx[0], g);
            }
        }
    }
    return result;
}

struct DispatchState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int flags;
};

struct DispatchPacket
{
    unsigned int status;
    unsigned char mode;
    unsigned int opcode;
    unsigned int selection;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

extern DispatchState* __cdecl GetExtraDataChecked(int object);
extern "C" void __cdecl bhkWorld_DoObjectRec(int object, DispatchPacket* packet, unsigned int dispatcher);
extern "C" unsigned int DAT_011afe94;

// @fnv 0x00c6a040
// src: XBOX_PDB 0x00c6a040
unsigned char __cdecl bhkWorld_Enable(int object, unsigned char selection, unsigned char mode, unsigned char overrideCheck)
{
    unsigned char result = 0;
    if (object)
    {
        if (!overrideCheck)
        {
            DispatchState* state = GetExtraDataChecked(object);
            if (!state)
                goto exit;

            unsigned int value = state->flags;
            unsigned int& flags = value;
            if (!(flags &= 2))
                goto exit;
        }

        DispatchPacket packet;
        packet.mode = mode;
        result = 1;
        packet.status = 0;
        packet.opcode = 3;
        packet.selection = selection;

        if (DAT_011afe94)
            bhkWorld_DoObjectRec(object, &packet, DAT_011afe94);
    }
exit:
    return result;
}

class C6A2E0AVObject;
class C6A2E0CollisionObject;

struct C6A2E0Context
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    int iCount;
    void* pUserData;
    void* pAuxiliaryData;
    unsigned int uiFilterFlags;
};

typedef void (*C6A2E0Callback)(C6A2E0CollisionObject*, C6A2E0Context*);

struct C6A2E0Properties
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiValue1;
};

extern "C" C6A2E0Properties* GetExtraDataChecked(C6A2E0AVObject* pkObject);
void bhkWorld_DoObjectRec(C6A2E0AVObject* pkObject, C6A2E0Context* pkContext, C6A2E0Callback pfnCallback);
extern C6A2E0Callback g_pfnC6A2E0Callback;

static inline unsigned int C6A2E0IsEnabled(C6A2E0AVObject* pkObject)
{
    C6A2E0Properties* pkProps = GetExtraDataChecked(pkObject);
    return pkProps ? (pkProps->m_uiValue1 & 2) : 0;
}

// @fnv 0x00c6a2e0
// src: COMMUNITY 0x00c6a2e0
bool bhkWorld_KillHavok(C6A2E0AVObject* pkObject, bool bRecurse, bool bForce)
{
    bool bResult = false;
    if (pkObject && (bForce || C6A2E0IsEnabled(pkObject)))
    {
        C6A2E0Context kContext;
        kContext.bRecurse = bRecurse;
        bResult = true;
        kContext.pCurrentObject = 0;
        kContext.uiTraversalFlags = 4;
        if (g_pfnC6A2E0Callback)
            bhkWorld_DoObjectRec(pkObject, &kContext, g_pfnC6A2E0Callback);
    }
    return bResult;
}

class FUN_00c6a810_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short unk14;
    unsigned char m_16;
    void bhkWorld_SetDebugDisplay(void* target, unsigned char value);
};

struct FlagRequestB3610
{
    unsigned char flag;
    int type;
    int value;
    int unk0C;
    int unk10;
    int unk14;
};

struct FlagFrameB3610
{
    int zero;
    FlagRequestB3610 req;
};

extern void* DAT_011afea0;
void __cdecl SpawnHelperB3610(void* target, FlagRequestB3610* req, void* ctx);

// Stores value into m_16 and, if target is non-null and DAT_011afea0 is set, sends a flag request with type 6 and the stored flag's boolean value.
// @fnv 0x00c6a810
// src: XBOX_PDB 0x00c6a810
void FUN_00c6a810_cls::bhkWorld_SetDebugDisplay(void* target, unsigned char value)
{
    if (m_16 != value)
    {
        m_16 = value;
    }
    if (target != 0)
    {
        FlagFrameB3610 frame;
        frame.zero = 0;
        frame.req.flag = 1;
        frame.req.type = 6;
        frame.req.value = m_16 != 0;
        if (DAT_011afea0 != 0)
        {
            SpawnHelperB3610(target, (FlagRequestB3610*)&frame, DAT_011afea0);
        }
    }
}

// Deleting destructor of FUN_00c6b070: runs the base cleanup, then optionally
// releases the block (the allocator stores the block size just below the object).
struct FUN_00c6aca0_holder
{
    void* FUN_00c6aca0();
};

struct FUN_00c6b070_cls : public FUN_00c6aca0_holder
{
    FUN_00c6b070_cls* FUN_00c6b070(unsigned char auFlags);
};

// @fnv 0x00c6b070
FUN_00c6b070_cls* FUN_00c6b070_cls::FUN_00c6b070(unsigned char auFlags)
{
    this->FUN_00c6aca0();

    if (auFlags & 1)
    {
        if (this != 0)
        {
            unsigned char* pBlock = (unsigned char*)this;
            reinterpret_cast<MemoryManager*>(&_g_memoryManager)->Deallocate(pBlock - pBlock[-1]);
        }
    }

    return this;
}

struct FUN_00c6b670_tls
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int unk02B4;
    unsigned int unk02B8;
    unsigned int unk02BC;
    unsigned int unk02C0;
};

extern __declspec(thread) FUN_00c6b670_tls g_fun00c6b670Tls;

struct FUN_00c6b670_helper
{
    void Call();
};

struct FUN_00c6b670_obj
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual bool v2D();
    unsigned int unk04;
    FUN_00c6b670_helper* m_08;
    unsigned short m_0c;
};

struct FUN_00c6b670_cls : FUN_00c6b670_obj
{
    void UpdateState(int a1);
};

// Checks the TLS state and m_0c flags, calls v2B/v2A/v29 or v2D as needed, then invokes m_08->Call() if m_08 is set.
// @fnv 0x00c6b670
void FUN_00c6b670_cls::UpdateState(int a1)
{
    FUN_00c6b670_tls* tls = &g_fun00c6b670Tls;
    int state = (int)tls->unk02C0;
    if (state == 3)
        goto L_a2;
    if (((unsigned char)(m_0c >> 6)) & 1)
    {
        if (state == 2)
            goto L_a2;
        v2B();
        v2A();
        m_0c &= 0xffbf;
        return;
    }
    if (!((unsigned char)m_0c & 1))
        goto L_a2;
    if (v2D())
    {
        FUN_00c6b670_tls* tls = &g_fun00c6b670Tls;
        if (tls->unk02C0 != 2)
        {
            v2A();
            return;
        }
        goto L_a2;
    }
    FUN_00c6b670_tls* tls2 = &g_fun00c6b670Tls;
    if (tls2->unk02C0 != 1)
    {
        v29();
        return;
    }
L_a2:
    if (m_08)
        m_08->Call();
}

struct FUN_00c6b730_target
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(int a1);
};

struct FUN_00c6b730_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00c6b730_target* m_pFlagTarget;
    void Helper(int a1);
    void DispatchToTarget(int a1);
};

// If the target pointer is non-null, calls its v15 with a1, then calls Helper with a1.
// @fnv 0x00c6b730
void FUN_00c6b730_cls::DispatchToTarget(int a1)
{
    FUN_00c6b730_target* target = m_pFlagTarget;
    if (target != 0)
        target->v15(a1);
    Helper(a1);
}

struct S_00c6b760_Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual bool v5c(S_00c6b760_Obj* other);
};

struct S_00c6b760_Cls
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_0c;
    unsigned short unk0e;
    S_00c6b760_Obj* m_10;
    bool FUN_00a81060(S_00c6b760_Cls* other);
    bool bhkNiCollisionObject_IsEqual(S_00c6b760_Cls* other);
};

// Compares this object with another: first via FUN_00a81060, then compares m_10 (via v5c or null check) and m_0c.
// @fnv 0x00c6b760
// src: XBOX_PDB 0x00c6b760
bool S_00c6b760_Cls::bhkNiCollisionObject_IsEqual(S_00c6b760_Cls* other)
{
    bool r = FUN_00a81060(other);
    if (r)
    {
        S_00c6b760_Obj* p = m_10;
        if (p != 0)
        {
            S_00c6b760_Obj* a = other->m_10;
            r = p->v5c(a);
        }
        else
        {
            r = other->m_10 == 0;
        }
        r = r & (other->m_0c == m_0c);
    }
    return r;
}

// candidate for FUN_00c6b7b0
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
extern "C" void* FUN_00a5b690(void* p);
extern char* DAT_0109b220;

class FnvProbeObj
{
  public:
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void* v39(NiFixedString* name);
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7C;
    int m_i80;
    float m_f84;
};

// If a is non-null, resolves a target object from b (or falls back to a) and returns whether its m_f84 is greater than zero.
// @fnv 0x00c6b7b0
// src: XBOX_PDB 0x00c6b7b0
bool bhkNiCollisionObject_GetFaceUp(FnvProbeObj* pObj, void* b)
{
    bool result = false;
    if (pObj)
    {
        FnvProbeObj* obj = pObj;
        FnvProbeObj* target = 0;
        if (b)
        {
            NiFixedString name(static_cast<const char*>(FUN_00a5b690(b)), 0);
            target = (FnvProbeObj*)obj->v39(&name);
        }
        if (!target)
            target = obj;
        result = target->m_f84 > 0.0f;
    }
    return result;
}

namespace fnv_00c6b860 {
extern void* DAT_0109b220;
void* __cdecl FUN_00a5b690(unsigned int value);

struct FUN_00c6b860_Object
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual FUN_00c6b860_Object* Find(NiFixedString*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    float unk88;
};
// @fnv 0x00c6b860
// src: XBOX_PDB 0x00c6b860
bool __cdecl bhkNiCollisionObject_GetLeftUp(FUN_00c6b860_Object* object, unsigned int key)
{
    bool result = false;
    if (object)
    {
        FUN_00c6b860_Object* selected = 0;
        if (key)
        {
            NiFixedString name(key);
            selected = object->Find(&name);
        }
        if (!selected)
            selected = object;
        result = selected->unk88 > 0.0f;
    }
    return result;
}
}  // namespace fnv_00c6b860

extern int DAT_01267b70;

// @fnv 0x00c6b940
// src: COMMUNITY 0x00c6b940
void* __cdecl bhkNiCollisionObject_GetRTTI()
{
    return &DAT_01267b70;
}

struct CloneProcess;
struct MapProxy
{
    bool FUN_00a53c30(NiInterpolator*, NiInterpolator*&);
};
struct CloneProcess
{
    MapProxy* map;
};
struct OwnerProxy
{
    int unk00, unk04, unk08;
    unsigned short unk0c, unk0e;
    NiInterpolator* object;
    void NiCollisionObject_CopyMembers(OwnerProxy*, CloneProcess*);
    void bhkNiCollisionObject_SetWorldObject(NiInterpolator*);
    void bhkNiCollisionObject_CopyMembers(OwnerProxy*, CloneProcess*);
};
// @fnv 0x00c6ba30
// src: XBOX_PDB 0x00c6ba30
void OwnerProxy::bhkNiCollisionObject_CopyMembers(OwnerProxy* dest, CloneProcess* process)
{
    NiCollisionObject_CopyMembers(dest, process);
    dest->unk0c = unk0c;
    NiPointer<NiInterpolator> source = object;
    if (source)
    {
        NiPointer<NiInterpolator> clone;
        NiInterpolator* result;
        if (process->map->FUN_00a53c30(source, result))
            clone = result;
        else
            clone = static_cast<NiInterpolator*>(source->MakeClone(*reinterpret_cast<CloningProcess*>(process)));
        dest->bhkNiCollisionObject_SetWorldObject(clone);
        clone = 0;
        source = 0;
    }
}

bool __cdecl AreVectorsEqual(NiPoint3 const& a, NiPoint3 const& b, float c);
bool __cdecl CloseTo(NiPoint3 const* a, NiPoint3 const* b, float c);

typedef void(__cdecl* TransformCallback)(bhkNiCollisionObject*, int);
extern bool DAT_01267b6c;
extern TransformCallback DAT_01267b68;

// @fnv 0x00c6bbb0
void __fastcall UpdateWorldTransform(bhkNiCollisionObject* self, void*, const NiTransform& kWorld)
{
    NiAVObject* pkObject = self->m_pkSceneObject;
    if (!pkObject)
        return;

    NiNode* pkParent = pkObject->m_pkParent;
    if ((unsigned char)(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(self) + 0xc) >> 3) & 1)
    {
        float localStorage[sizeof(NiTransform) / sizeof(float)];
        NiTransform& kLocal = *reinterpret_cast<NiTransform*>(localStorage);
        if (pkParent)
        {
            pkParent->m_kWorld.FUN_004b4880(kLocal);
            CopyTransform(kLocal, kLocal * kWorld);
        }
        else
        {
            memcpy(&kLocal, &kWorld, sizeof(kLocal));
        }
        pkObject->m_kLocal.m_Rotate = kLocal.m_Rotate;
        memcpy(&pkObject->m_kLocal.m_Translate, &kLocal.m_Translate, sizeof(NiPoint3));
    }

    int iResult = 0;
    if (DAT_01267b6c)
    {
        iResult = 3;
    }
    else
    {
        if (!CloseTo((const NiPoint3*)&pkObject->m_kWorld.m_Rotate, (const NiPoint3*)&kWorld.m_Rotate,
                          0.001f))
            iResult = 2;
        if (!AreVectorsEqual(pkObject->m_kWorld.m_Translate, kWorld.m_Translate, 0.01f))
            iResult |= 1;
        if (!iResult)
            return;
    }

    pkObject->m_kWorld.m_Rotate = kWorld.m_Rotate;
    memcpy(&pkObject->m_kWorld.m_Translate, &kWorld.m_Translate, sizeof(NiPoint3));
    if (DAT_01267b68 && (unsigned char)(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(self) + 0xc) >> 2) & 1)
        DAT_01267b68(self, iResult);
}

struct TreeFlagged_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
};

struct TreeHost_cls
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
    virtual TreeFlagged_cls* v14();
};

// @fnv 0x00c6bd00
// src: XBOX_PDB 0x00c6bd00
void bhkNiCollisionObject_ResetSim(NiAVObject* node, bool recurse)
{
    if (node == 0)
    {
        return;
    }

    TreeHost_cls* host = reinterpret_cast<TreeHost_cls*>(node->m_spCollisionObject.m_pObject);
    if (host != 0)
    {
        TreeFlagged_cls* flagged = host->v14();
        if (flagged != 0)
        {
            flagged->m_0c |= 0x40;
        }
    }

    if (recurse)
    {
        NiNode* child = node->IsSceneNode();
        if (child != 0)
        {
            unsigned int n = child->m_kChildren.m_usSize;
            if (n != 0)
            {
                do
                {
                    --n;
                    NiAVObject* item = child->m_kChildren.m_pBase[n];
                    bhkNiCollisionObject_ResetSim(item, true);
                } while (n != 0);
            }
        }
    }
}

class C6C0E0RefObject
{
  public:
    void SetFlag(int iFlag);
};

struct C6C0E0WorldObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C6C0E0RefObject* m_pPointer;
};

class C6C0E0CollisionObject
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual C6C0E0WorldObject* GetWorldObject();
};

class C6C0E0AVObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C6C0E0CollisionObject* m_spCollisionObject;
};

// If the object has a collision object with a world object and ref object, forwards the flag to the ref object's SetFlag.
// @fnv 0x00c6c0e0
void SetCollisionRefFlag(C6C0E0AVObject* pkObject, int aiFlag)
{
    C6C0E0CollisionObject* pkCollision = pkObject->m_spCollisionObject;
    if (pkCollision)
    {
        C6C0E0WorldObject* pkWorldObject = pkCollision->GetWorldObject();
        C6C0E0RefObject* pkRefObject;
        if (pkWorldObject && (pkRefObject = pkWorldObject->m_pPointer) != 0)
            pkRefObject->SetFlag(aiFlag);
    }
}

struct C6C210RTTI;
extern const C6C210RTTI g_kC6C210EntityRTTI;

class C6C210StringPtr
{
  public:
    void operator=(const char* pcString);
};

struct C6C210HavokEntity
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    C6C210StringPtr m_name;
};

class C6C210RefObject
{
  public:
    C6C210RefObject* DynamicCast(const C6C210RTTI* pkRTTI);
};

class C6C210Entity : public C6C210RefObject
{
  public:
    int unk00;
    int unk04;
    C6C210HavokEntity* m_pkHavokEntity;
};

struct C6C210WorldObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C6C210RefObject* m_pPointer;
};

class C6C210CollisionObject
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual C6C210WorldObject* GetWorldObject();
};

class C6C210AVObject
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual NiNode* IsSceneNode();

    int unk04;
    const char* m_pcName;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C6C210CollisionObject* m_spCollisionObject;
};

// @fnv 0x00c6c210
void PropagateNameToHavokEntity(C6C210AVObject* pkObject)
{
    if (!pkObject)
        return;

    C6C210CollisionObject* pkCollision = pkObject->m_spCollisionObject;
    if (pkCollision)
    {
        C6C210WorldObject* pkWorldObject = pkCollision->GetWorldObject();
        C6C210RefObject* pkRefObject;
        if (pkWorldObject && (pkRefObject = pkWorldObject->m_pPointer) != 0)
        {
            C6C210Entity* pkEntity = (C6C210Entity*)pkRefObject->DynamicCast(&g_kC6C210EntityRTTI);
            if (pkEntity)
                pkEntity->m_pkHavokEntity->m_name = pkObject->m_pcName;
        }
    }

    NiNode* pkNode = pkObject->IsSceneNode();
    if (pkNode)
    {
        int iCount = pkNode->m_kChildren.m_usSize;
        for (int i = 0; i < iCount; i++)
            PropagateNameToHavokEntity(reinterpret_cast<C6C210AVObject*>(pkNode->m_kChildren.m_pBase[i].m_pObject));
    }
}

class C6C290Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void Detach();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            vfunc01();
    }
};

extern int g_iC6C290Count;

class C6C290Base
{
  public:
    virtual ~C6C290Base();
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_00c6c290 : public C6C290Base
{
  public:
    NiPointer<C6C290Object> m_pReferencedObject;

    void bhkNiCollisionObject_SetWorldObject(int iValue);
    virtual ~FUN_00c6c290();
};

// Decrements g_iC6C290Count, detaches the held C6C290Object if present, then calls FUN_00c6b980(0).
// @fnv 0x00c6c290
FUN_00c6c290::~FUN_00c6c290()
{
    g_iC6C290Count--;
    if (m_pReferencedObject)
        m_pReferencedObject->Detach();
    bhkNiCollisionObject_SetWorldObject(0);
}

class BC6C330BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BC6C330BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BC6C330Stream
{
  public:
    void ResetStreamState();

    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    unsigned int m_uiFileVersion;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BC6C330BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void BC6C330BinaryStreamLoad(BC6C330BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BC6C330LoadBinary(BC6C330Stream& kStream, T& value)
{
    BC6C330BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

class BC6C330CollisionObject
{
  public:
    virtual void LoadBinary(BC6C330Stream& kStream);
};

class BC6C330HavokCollision : public BC6C330CollisionObject
{
  public:
    virtual void LoadBinary(BC6C330Stream& kStream);
    void bhkNiCollisionObject_LoadBinary(BC6C330Stream& kStream);

    int unk04;
    int unk08;
    unsigned short m_usFlags;
};

// @fnv 0x00c6c330
// src: XBOX_PDB 0x00c6c330
void BC6C330HavokCollision::bhkNiCollisionObject_LoadBinary(BC6C330Stream& kStream)
{
    BC6C330CollisionObject::LoadBinary(kStream);
    BC6C330LoadBinary(kStream, m_usFlags);
    kStream.ResetStreamState();
}

extern int DAT_010c446c;

struct FUN_00c6c830_cls
{
    int m_vptr00;

    void SetVptr00();
};

// @fnv 0x00c6c830
// src: GUESS 0x00c6c830 (confidence: low)
void FUN_00c6c830_cls::SetVptr00()
{
    m_vptr00 = (int)&DAT_010c446c;
}

struct S_00c6c840_Param
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    unsigned char unk20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned char unk2c;
    unsigned char unk2d;
    unsigned char unk2e;
    unsigned char unk2f;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned char unk34;
    unsigned char unk35;
    unsigned char unk36;
    unsigned char unk37;
    unsigned char unk38;
    unsigned char unk39;
    unsigned char unk3a;
    unsigned char unk3b;
    unsigned char unk3c;
    unsigned char unk3d;
    unsigned char unk3e;
    unsigned char unk3f;
    unsigned char unk40;
    unsigned char unk41;
    unsigned char unk42;
    unsigned char unk43;
    unsigned char unk44;
    unsigned char unk45;
    unsigned char unk46;
    unsigned char unk47;
    void* m_pObject_48;
};

struct S_00c6c840_Value
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    int m_value_1c;
};

struct S_00c6c840_Base
{
    void __thiscall bhkCharacterController_SetLinearVelocity_Ni(void* a);
};

struct S_00c6c840_class
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    unsigned char unk20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned char unk2c;
    unsigned char unk2d;
    unsigned char unk2e;
    unsigned char unk2f;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned char unk34;
    unsigned char unk35;
    unsigned char unk36;
    unsigned char unk37;
    unsigned char unk38;
    unsigned char unk39;
    unsigned char unk3a;
    unsigned char unk3b;
    unsigned char unk3c;
    unsigned char unk3d;
    unsigned char unk3e;
    unsigned char unk3f;
    unsigned char unk40;
    unsigned char unk41;
    unsigned char unk42;
    unsigned char unk43;
    unsigned char unk44;
    unsigned char unk45;
    unsigned char unk46;
    unsigned char unk47;
    unsigned char unk48;
    unsigned char unk49;
    unsigned char unk4a;
    unsigned char unk4b;
    unsigned char unk4c;
    unsigned char unk4d;
    unsigned char unk4e;
    unsigned char unk4f;
    unsigned char unk50;
    unsigned char unk51;
    unsigned char unk52;
    unsigned char unk53;
    unsigned char unk54;
    unsigned char unk55;
    unsigned char unk56;
    unsigned char unk57;
    unsigned char unk58;
    unsigned char unk59;
    unsigned char unk5a;
    unsigned char unk5b;
    unsigned char unk5c;
    unsigned char unk5d;
    unsigned char unk5e;
    unsigned char unk5f;
    unsigned char unk60;
    unsigned char unk61;
    unsigned char unk62;
    unsigned char unk63;
    unsigned char unk64;
    unsigned char unk65;
    unsigned char unk66;
    unsigned char unk67;
    unsigned char unk68;
    unsigned char unk69;
    unsigned char unk6a;
    unsigned char unk6b;
    int unk6c;

    void __thiscall bhkCharacterListener_contactPointAddedCallback(int a, S_00c6c840_Param* b);
};

struct S_00c6c840_Pad
{
    unsigned char pad000;
    unsigned char pad001;
    unsigned char pad002;
    unsigned char pad003;
    unsigned char pad004;
    unsigned char pad005;
    unsigned char pad006;
    unsigned char pad007;
    unsigned char pad008;
    unsigned char pad009;
    unsigned char pad00a;
    unsigned char pad00b;
    unsigned char pad00c;
    unsigned char pad00d;
    unsigned char pad00e;
    unsigned char pad00f;
    unsigned char pad010;
    unsigned char pad011;
    unsigned char pad012;
    unsigned char pad013;
    unsigned char pad014;
    unsigned char pad015;
    unsigned char pad016;
    unsigned char pad017;
    unsigned char pad018;
    unsigned char pad019;
    unsigned char pad01a;
    unsigned char pad01b;
    unsigned char pad01c;
    unsigned char pad01d;
    unsigned char pad01e;
    unsigned char pad01f;
    unsigned char pad020;
    unsigned char pad021;
    unsigned char pad022;
    unsigned char pad023;
    unsigned char pad024;
    unsigned char pad025;
    unsigned char pad026;
    unsigned char pad027;
    unsigned char pad028;
    unsigned char pad029;
    unsigned char pad02a;
    unsigned char pad02b;
    unsigned char pad02c;
    unsigned char pad02d;
    unsigned char pad02e;
    unsigned char pad02f;
    unsigned char pad030;
    unsigned char pad031;
    unsigned char pad032;
    unsigned char pad033;
    unsigned char pad034;
    unsigned char pad035;
    unsigned char pad036;
    unsigned char pad037;
    unsigned char pad038;
    unsigned char pad039;
    unsigned char pad03a;
    unsigned char pad03b;
    unsigned char pad03c;
    unsigned char pad03d;
    unsigned char pad03e;
    unsigned char pad03f;
    unsigned char pad040;
    unsigned char pad041;
    unsigned char pad042;
    unsigned char pad043;
    unsigned char pad044;
    unsigned char pad045;
    unsigned char pad046;
    unsigned char pad047;
    unsigned char pad048;
    unsigned char pad049;
    unsigned char pad04a;
    unsigned char pad04b;
    unsigned char pad04c;
    unsigned char pad04d;
    unsigned char pad04e;
    unsigned char pad04f;
    unsigned char pad050;
    unsigned char pad051;
    unsigned char pad052;
    unsigned char pad053;
    unsigned char pad054;
    unsigned char pad055;
    unsigned char pad056;
    unsigned char pad057;
    unsigned char pad058;
    unsigned char pad059;
    unsigned char pad05a;
    unsigned char pad05b;
    unsigned char pad05c;
    unsigned char pad05d;
    unsigned char pad05e;
    unsigned char pad05f;
    unsigned char pad060;
    unsigned char pad061;
    unsigned char pad062;
    unsigned char pad063;
    unsigned char pad064;
    unsigned char pad065;
    unsigned char pad066;
    unsigned char pad067;
    unsigned char pad068;
    unsigned char pad069;
    unsigned char pad06a;
    unsigned char pad06b;
    unsigned char pad06c;
    unsigned char pad06d;
    unsigned char pad06e;
    unsigned char pad06f;
    unsigned char pad070;
    unsigned char pad071;
    unsigned char pad072;
    unsigned char pad073;
    unsigned char pad074;
    unsigned char pad075;
    unsigned char pad076;
    unsigned char pad077;
    unsigned char pad078;
    unsigned char pad079;
    unsigned char pad07a;
    unsigned char pad07b;
    unsigned char pad07c;
    unsigned char pad07d;
    unsigned char pad07e;
    unsigned char pad07f;
    unsigned char pad080;
    unsigned char pad081;
    unsigned char pad082;
    unsigned char pad083;
    unsigned char pad084;
    unsigned char pad085;
    unsigned char pad086;
    unsigned char pad087;
    unsigned char pad088;
    unsigned char pad089;
    unsigned char pad08a;
    unsigned char pad08b;
    unsigned char pad08c;
    unsigned char pad08d;
    unsigned char pad08e;
    unsigned char pad08f;
    unsigned char pad090;
    unsigned char pad091;
    unsigned char pad092;
    unsigned char pad093;
    unsigned char pad094;
    unsigned char pad095;
    unsigned char pad096;
    unsigned char pad097;
    unsigned char pad098;
    unsigned char pad099;
    unsigned char pad09a;
    unsigned char pad09b;
    unsigned char pad09c;
    unsigned char pad09d;
    unsigned char pad09e;
    unsigned char pad09f;
    unsigned char pad0a0;
    unsigned char pad0a1;
    unsigned char pad0a2;
    unsigned char pad0a3;
    unsigned char pad0a4;
    unsigned char pad0a5;
    unsigned char pad0a6;
    unsigned char pad0a7;
    unsigned char pad0a8;
    unsigned char pad0a9;
    unsigned char pad0aa;
    unsigned char pad0ab;
    unsigned char pad0ac;
    unsigned char pad0ad;
    unsigned char pad0ae;
    unsigned char pad0af;
    unsigned char pad0b0;
    unsigned char pad0b1;
    unsigned char pad0b2;
    unsigned char pad0b3;
    unsigned char pad0b4;
    unsigned char pad0b5;
    unsigned char pad0b6;
    unsigned char pad0b7;
    unsigned char pad0b8;
    unsigned char pad0b9;
    unsigned char pad0ba;
    unsigned char pad0bb;
    unsigned char pad0bc;
    unsigned char pad0bd;
    unsigned char pad0be;
    unsigned char pad0bf;
    unsigned char pad0c0;
    unsigned char pad0c1;
    unsigned char pad0c2;
    unsigned char pad0c3;
    unsigned char pad0c4;
    unsigned char pad0c5;
    unsigned char pad0c6;
    unsigned char pad0c7;
    unsigned char pad0c8;
    unsigned char pad0c9;
    unsigned char pad0ca;
    unsigned char pad0cb;
    unsigned char pad0cc;
    unsigned char pad0cd;
    unsigned char pad0ce;
    unsigned char pad0cf;
    unsigned char pad0d0;
    unsigned char pad0d1;
    unsigned char pad0d2;
    unsigned char pad0d3;
    unsigned char pad0d4;
    unsigned char pad0d5;
    unsigned char pad0d6;
    unsigned char pad0d7;
    unsigned char pad0d8;
    unsigned char pad0d9;
    unsigned char pad0da;
    unsigned char pad0db;
    unsigned char pad0dc;
    unsigned char pad0dd;
    unsigned char pad0de;
    unsigned char pad0df;
    unsigned char pad0e0;
    unsigned char pad0e1;
    unsigned char pad0e2;
    unsigned char pad0e3;
    unsigned char pad0e4;
    unsigned char pad0e5;
    unsigned char pad0e6;
    unsigned char pad0e7;
    unsigned char pad0e8;
    unsigned char pad0e9;
    unsigned char pad0ea;
    unsigned char pad0eb;
    unsigned char pad0ec;
    unsigned char pad0ed;
    unsigned char pad0ee;
    unsigned char pad0ef;
    unsigned char pad0f0;
    unsigned char pad0f1;
    unsigned char pad0f2;
    unsigned char pad0f3;
    unsigned char pad0f4;
    unsigned char pad0f5;
    unsigned char pad0f6;
    unsigned char pad0f7;
    unsigned char pad0f8;
    unsigned char pad0f9;
    unsigned char pad0fa;
    unsigned char pad0fb;
    unsigned char pad0fc;
    unsigned char pad0fd;
    unsigned char pad0fe;
    unsigned char pad0ff;
    unsigned char pad100;
    unsigned char pad101;
    unsigned char pad102;
    unsigned char pad103;
    unsigned char pad104;
    unsigned char pad105;
    unsigned char pad106;
    unsigned char pad107;
    unsigned char pad108;
    unsigned char pad109;
    unsigned char pad10a;
    unsigned char pad10b;
    unsigned char pad10c;
    unsigned char pad10d;
    unsigned char pad10e;
    unsigned char pad10f;
    unsigned char pad110;
    unsigned char pad111;
    unsigned char pad112;
    unsigned char pad113;
    unsigned char pad114;
    unsigned char pad115;
    unsigned char pad116;
    unsigned char pad117;
    unsigned char pad118;
    unsigned char pad119;
    unsigned char pad11a;
    unsigned char pad11b;
    unsigned char pad11c;
    unsigned char pad11d;
    unsigned char pad11e;
    unsigned char pad11f;
    unsigned char pad120;
    unsigned char pad121;
    unsigned char pad122;
    unsigned char pad123;
    unsigned char pad124;
    unsigned char pad125;
    unsigned char pad126;
    unsigned char pad127;
    unsigned char pad128;
    unsigned char pad129;
    unsigned char pad12a;
    unsigned char pad12b;
    unsigned char pad12c;
    unsigned char pad12d;
    unsigned char pad12e;
    unsigned char pad12f;
    unsigned char pad130;
    unsigned char pad131;
    unsigned char pad132;
    unsigned char pad133;
    unsigned char pad134;
    unsigned char pad135;
    unsigned char pad136;
    unsigned char pad137;
    unsigned char pad138;
    unsigned char pad139;
    unsigned char pad13a;
    unsigned char pad13b;
    unsigned char pad13c;
    unsigned char pad13d;
    unsigned char pad13e;
    unsigned char pad13f;
    unsigned char pad140;
    unsigned char pad141;
    unsigned char pad142;
    unsigned char pad143;
    unsigned char pad144;
    unsigned char pad145;
    unsigned char pad146;
    unsigned char pad147;
    unsigned char pad148;
    unsigned char pad149;
    unsigned char pad14a;
    unsigned char pad14b;
    unsigned char pad14c;
    unsigned char pad14d;
    unsigned char pad14e;
    unsigned char pad14f;
    unsigned char pad150;
    unsigned char pad151;
    unsigned char pad152;
    unsigned char pad153;
    unsigned char pad154;
    unsigned char pad155;
    unsigned char pad156;
    unsigned char pad157;
    unsigned char pad158;
    unsigned char pad159;
    unsigned char pad15a;
    unsigned char pad15b;
    unsigned char pad15c;
    unsigned char pad15d;
    unsigned char pad15e;
    unsigned char pad15f;
    unsigned char pad160;
    unsigned char pad161;
    unsigned char pad162;
    unsigned char pad163;
    unsigned char pad164;
    unsigned char pad165;
    unsigned char pad166;
    unsigned char pad167;
    unsigned char pad168;
    unsigned char pad169;
    unsigned char pad16a;
    unsigned char pad16b;
    unsigned char pad16c;
    unsigned char pad16d;
    unsigned char pad16e;
    unsigned char pad16f;
    unsigned char pad170;
    unsigned char pad171;
    unsigned char pad172;
    unsigned char pad173;
    unsigned char pad174;
    unsigned char pad175;
    unsigned char pad176;
    unsigned char pad177;
    unsigned char pad178;
    unsigned char pad179;
    unsigned char pad17a;
    unsigned char pad17b;
    unsigned char pad17c;
    unsigned char pad17d;
    unsigned char pad17e;
    unsigned char pad17f;
    unsigned char pad180;
    unsigned char pad181;
    unsigned char pad182;
    unsigned char pad183;
    unsigned char pad184;
    unsigned char pad185;
    unsigned char pad186;
    unsigned char pad187;
    unsigned char pad188;
    unsigned char pad189;
    unsigned char pad18a;
    unsigned char pad18b;
    unsigned char pad18c;
    unsigned char pad18d;
    unsigned char pad18e;
    unsigned char pad18f;
    unsigned char pad190;
    unsigned char pad191;
    unsigned char pad192;
    unsigned char pad193;
    unsigned char pad194;
    unsigned char pad195;
    unsigned char pad196;
    unsigned char pad197;
    unsigned char pad198;
    unsigned char pad199;
    unsigned char pad19a;
    unsigned char pad19b;
    unsigned char pad19c;
    unsigned char pad19d;
    unsigned char pad19e;
    unsigned char pad19f;
    unsigned char pad1a0;
    unsigned char pad1a1;
    unsigned char pad1a2;
    unsigned char pad1a3;
    unsigned char pad1a4;
    unsigned char pad1a5;
    unsigned char pad1a6;
    unsigned char pad1a7;
    unsigned char pad1a8;
    unsigned char pad1a9;
    unsigned char pad1aa;
    unsigned char pad1ab;
    unsigned char pad1ac;
    unsigned char pad1ad;
    unsigned char pad1ae;
    unsigned char pad1af;
    unsigned char pad1b0;
    unsigned char pad1b1;
    unsigned char pad1b2;
    unsigned char pad1b3;
    unsigned char pad1b4;
    unsigned char pad1b5;
    unsigned char pad1b6;
    unsigned char pad1b7;
    unsigned char pad1b8;
    unsigned char pad1b9;
    unsigned char pad1ba;
    unsigned char pad1bb;
    unsigned char pad1bc;
    unsigned char pad1bd;
    unsigned char pad1be;
    unsigned char pad1bf;
    unsigned char pad1c0;
    unsigned char pad1c1;
    unsigned char pad1c2;
    unsigned char pad1c3;
    unsigned char pad1c4;
    unsigned char pad1c5;
    unsigned char pad1c6;
    unsigned char pad1c7;
    unsigned char pad1c8;
    unsigned char pad1c9;
    unsigned char pad1ca;
    unsigned char pad1cb;
    unsigned char pad1cc;
    unsigned char pad1cd;
    unsigned char pad1ce;
    unsigned char pad1cf;
    unsigned char pad1d0;
    unsigned char pad1d1;
    unsigned char pad1d2;
    unsigned char pad1d3;
    unsigned char pad1d4;
    unsigned char pad1d5;
    unsigned char pad1d6;
    unsigned char pad1d7;
    unsigned char pad1d8;
    unsigned char pad1d9;
    unsigned char pad1da;
    unsigned char pad1db;
    unsigned char pad1dc;
    unsigned char pad1dd;
    unsigned char pad1de;
    unsigned char pad1df;
    unsigned char pad1e0;
    unsigned char pad1e1;
    unsigned char pad1e2;
    unsigned char pad1e3;
    unsigned char pad1e4;
    unsigned char pad1e5;
    unsigned char pad1e6;
    unsigned char pad1e7;
    unsigned char pad1e8;
    unsigned char pad1e9;
    unsigned char pad1ea;
    unsigned char pad1eb;
    unsigned char pad1ec;
    unsigned char pad1ed;
    unsigned char pad1ee;
    unsigned char pad1ef;
    unsigned char pad1f0;
    unsigned char pad1f1;
    unsigned char pad1f2;
    unsigned char pad1f3;
    unsigned char pad1f4;
    unsigned char pad1f5;
    unsigned char pad1f6;
    unsigned char pad1f7;
    unsigned char pad1f8;
    unsigned char pad1f9;
    unsigned char pad1fa;
    unsigned char pad1fb;
    unsigned char pad1fc;
    unsigned char pad1fd;
    unsigned char pad1fe;
    unsigned char pad1ff;
    unsigned char pad200;
    unsigned char pad201;
    unsigned char pad202;
    unsigned char pad203;
    unsigned char pad204;
    unsigned char pad205;
    unsigned char pad206;
    unsigned char pad207;
    unsigned char pad208;
    unsigned char pad209;
    unsigned char pad20a;
    unsigned char pad20b;
    unsigned char pad20c;
    unsigned char pad20d;
    unsigned char pad20e;
    unsigned char pad20f;
    unsigned char pad210;
    unsigned char pad211;
    unsigned char pad212;
    unsigned char pad213;
    unsigned char pad214;
    unsigned char pad215;
    unsigned char pad216;
    unsigned char pad217;
    unsigned char pad218;
    unsigned char pad219;
    unsigned char pad21a;
    unsigned char pad21b;
    unsigned char pad21c;
    unsigned char pad21d;
    unsigned char pad21e;
    unsigned char pad21f;
    unsigned char pad220;
    unsigned char pad221;
    unsigned char pad222;
    unsigned char pad223;
    unsigned char pad224;
    unsigned char pad225;
    unsigned char pad226;
    unsigned char pad227;
    unsigned char pad228;
    unsigned char pad229;
    unsigned char pad22a;
    unsigned char pad22b;
    unsigned char pad22c;
    unsigned char pad22d;
    unsigned char pad22e;
    unsigned char pad22f;
    unsigned char pad230;
    unsigned char pad231;
    unsigned char pad232;
    unsigned char pad233;
    unsigned char pad234;
    unsigned char pad235;
    unsigned char pad236;
    unsigned char pad237;
    unsigned char pad238;
    unsigned char pad239;
    unsigned char pad23a;
    unsigned char pad23b;
    unsigned char pad23c;
    unsigned char pad23d;
    unsigned char pad23e;
    unsigned char pad23f;
    unsigned char pad240;
    unsigned char pad241;
    unsigned char pad242;
    unsigned char pad243;
    unsigned char pad244;
    unsigned char pad245;
    unsigned char pad246;
    unsigned char pad247;
    unsigned char pad248;
    unsigned char pad249;
    unsigned char pad24a;
    unsigned char pad24b;
    unsigned char pad24c;
    unsigned char pad24d;
    unsigned char pad24e;
    unsigned char pad24f;
    unsigned char pad250;
    unsigned char pad251;
    unsigned char pad252;
    unsigned char pad253;
    unsigned char pad254;
    unsigned char pad255;
    unsigned char pad256;
    unsigned char pad257;
    unsigned char pad258;
    unsigned char pad259;
    unsigned char pad25a;
    unsigned char pad25b;
    unsigned char pad25c;
    unsigned char pad25d;
    unsigned char pad25e;
    unsigned char pad25f;
    unsigned char pad260;
    unsigned char pad261;
    unsigned char pad262;
    unsigned char pad263;
    unsigned char pad264;
    unsigned char pad265;
    unsigned char pad266;
    unsigned char pad267;
    unsigned char pad268;
    unsigned char pad269;
    unsigned char pad26a;
    unsigned char pad26b;
    unsigned char pad26c;
    unsigned char pad26d;
    unsigned char pad26e;
    unsigned char pad26f;
    unsigned char pad270;
    unsigned char pad271;
    unsigned char pad272;
    unsigned char pad273;
    unsigned char pad274;
    unsigned char pad275;
    unsigned char pad276;
    unsigned char pad277;
    unsigned char pad278;
    unsigned char pad279;
    unsigned char pad27a;
    unsigned char pad27b;
    unsigned char pad27c;
    unsigned char pad27d;
    unsigned char pad27e;
    unsigned char pad27f;
    unsigned char pad280;
    unsigned char pad281;
    unsigned char pad282;
    unsigned char pad283;
    unsigned char pad284;
    unsigned char pad285;
    unsigned char pad286;
    unsigned char pad287;
    unsigned char pad288;
    unsigned char pad289;
    unsigned char pad28a;
    unsigned char pad28b;
    unsigned char pad28c;
    unsigned char pad28d;
    unsigned char pad28e;
    unsigned char pad28f;
    unsigned char pad290;
    unsigned char pad291;
    unsigned char pad292;
    unsigned char pad293;
    unsigned char pad294;
    unsigned char pad295;
    unsigned char pad296;
    unsigned char pad297;
    unsigned char pad298;
    unsigned char pad299;
    unsigned char pad29a;
    unsigned char pad29b;
    unsigned char pad29c;
    unsigned char pad29d;
    unsigned char pad29e;
    unsigned char pad29f;
    unsigned char pad2a0;
    unsigned char pad2a1;
    unsigned char pad2a2;
    unsigned char pad2a3;
    unsigned char pad2a4;
    unsigned char pad2a5;
    unsigned char pad2a6;
    unsigned char pad2a7;
    unsigned char pad2a8;
    unsigned char pad2a9;
    unsigned char pad2aa;
    unsigned char pad2ab;
    unsigned char pad2ac;
    unsigned char pad2ad;
    unsigned char pad2ae;
    unsigned char pad2af;
    unsigned char pad2b0;
    unsigned char pad2b1;
    unsigned char pad2b2;
    unsigned char pad2b3;
    unsigned char pad2b4;
    unsigned char pad2b5;
    unsigned char pad2b6;
    unsigned char pad2b7;
    unsigned char pad2b8;
    unsigned char pad2b9;
    unsigned char pad2ba;
    unsigned char pad2bb;
    unsigned char pad2bc;
    unsigned char pad2bd;
    unsigned char pad2be;
    unsigned char pad2bf;
    unsigned char pad2c0;
    unsigned char pad2c1;
    unsigned char pad2c2;
    unsigned char pad2c3;
    unsigned char pad2c4;
    unsigned char pad2c5;
    unsigned char pad2c6;
    unsigned char pad2c7;
    unsigned char pad2c8;
    unsigned char pad2c9;
    unsigned char pad2ca;
    unsigned char pad2cb;
    unsigned char pad2cc;
    unsigned char pad2cd;
    unsigned char pad2ce;
    unsigned char pad2cf;
    unsigned char pad2d0;
    unsigned char pad2d1;
    unsigned char pad2d2;
    unsigned char pad2d3;
    unsigned char pad2d4;
    unsigned char pad2d5;
    unsigned char pad2d6;
    unsigned char pad2d7;
    unsigned char pad2d8;
    unsigned char pad2d9;
    unsigned char pad2da;
    unsigned char pad2db;
    unsigned char pad2dc;
    unsigned char pad2dd;
    unsigned char pad2de;
    unsigned char pad2df;
    unsigned char pad2e0;
    unsigned char pad2e1;
    unsigned char pad2e2;
    unsigned char pad2e3;
    unsigned char pad2e4;
    unsigned char pad2e5;
    unsigned char pad2e6;
    unsigned char pad2e7;
    unsigned char pad2e8;
    unsigned char pad2e9;
    unsigned char pad2ea;
    unsigned char pad2eb;
    unsigned char pad2ec;
    unsigned char pad2ed;
    unsigned char pad2ee;
    unsigned char pad2ef;
    unsigned char pad2f0;
    unsigned char pad2f1;
    unsigned char pad2f2;
    unsigned char pad2f3;
    unsigned char pad2f4;
    unsigned char pad2f5;
    unsigned char pad2f6;
    unsigned char pad2f7;
    unsigned char pad2f8;
    unsigned char pad2f9;
    unsigned char pad2fa;
    unsigned char pad2fb;
    unsigned char pad2fc;
    unsigned char pad2fd;
    unsigned char pad2fe;
    unsigned char pad2ff;
    unsigned char pad300;
    unsigned char pad301;
    unsigned char pad302;
    unsigned char pad303;
    unsigned char pad304;
    unsigned char pad305;
    unsigned char pad306;
    unsigned char pad307;
    unsigned char pad308;
    unsigned char pad309;
    unsigned char pad30a;
    unsigned char pad30b;
    unsigned char pad30c;
    unsigned char pad30d;
    unsigned char pad30e;
    unsigned char pad30f;
    unsigned char pad310;
    unsigned char pad311;
    unsigned char pad312;
    unsigned char pad313;
    unsigned char pad314;
    unsigned char pad315;
    unsigned char pad316;
    unsigned char pad317;
    unsigned char pad318;
    unsigned char pad319;
    unsigned char pad31a;
    unsigned char pad31b;
    unsigned char pad31c;
    unsigned char pad31d;
    unsigned char pad31e;
    unsigned char pad31f;
    unsigned char pad320;
    unsigned char pad321;
    unsigned char pad322;
    unsigned char pad323;
    unsigned char pad324;
    unsigned char pad325;
    unsigned char pad326;
    unsigned char pad327;
    unsigned char pad328;
    unsigned char pad329;
    unsigned char pad32a;
    unsigned char pad32b;
    unsigned char pad32c;
    unsigned char pad32d;
    unsigned char pad32e;
    unsigned char pad32f;
    unsigned char pad330;
    unsigned char pad331;
    unsigned char pad332;
    unsigned char pad333;
    unsigned char pad334;
    unsigned char pad335;
    unsigned char pad336;
    unsigned char pad337;
    unsigned char pad338;
    unsigned char pad339;
    unsigned char pad33a;
    unsigned char pad33b;
    unsigned char pad33c;
    unsigned char pad33d;
    unsigned char pad33e;
    unsigned char pad33f;
    unsigned char pad340;
    unsigned char pad341;
    unsigned char pad342;
    unsigned char pad343;
    unsigned char pad344;
    unsigned char pad345;
    unsigned char pad346;
    unsigned char pad347;
    unsigned char pad348;
    unsigned char pad349;
    unsigned char pad34a;
    unsigned char pad34b;
    unsigned char pad34c;
    unsigned char pad34d;
    unsigned char pad34e;
    unsigned char pad34f;
    unsigned char pad350;
    unsigned char pad351;
    unsigned char pad352;
    unsigned char pad353;
    unsigned char pad354;
    unsigned char pad355;
    unsigned char pad356;
    unsigned char pad357;
    unsigned char pad358;
    unsigned char pad359;
    unsigned char pad35a;
    unsigned char pad35b;
    unsigned char pad35c;
    unsigned char pad35d;
    unsigned char pad35e;
    unsigned char pad35f;
    unsigned char pad360;
    unsigned char pad361;
    unsigned char pad362;
    unsigned char pad363;
    unsigned char pad364;
    unsigned char pad365;
    unsigned char pad366;
    unsigned char pad367;
    unsigned char pad368;
    unsigned char pad369;
    unsigned char pad36a;
    unsigned char pad36b;
    unsigned char pad36c;
    unsigned char pad36d;
    unsigned char pad36e;
    unsigned char pad36f;
    unsigned char pad370;
    unsigned char pad371;
    unsigned char pad372;
    unsigned char pad373;
    unsigned char pad374;
    unsigned char pad375;
    unsigned char pad376;
    unsigned char pad377;
    unsigned char pad378;
    unsigned char pad379;
    unsigned char pad37a;
    unsigned char pad37b;
    unsigned char pad37c;
    unsigned char pad37d;
    unsigned char pad37e;
    unsigned char pad37f;
    unsigned char pad380;
    unsigned char pad381;
    unsigned char pad382;
    unsigned char pad383;
    unsigned char pad384;
    unsigned char pad385;
    unsigned char pad386;
    unsigned char pad387;
    unsigned char pad388;
    unsigned char pad389;
    unsigned char pad38a;
    unsigned char pad38b;
    unsigned char pad38c;
    unsigned char pad38d;
    unsigned char pad38e;
    unsigned char pad38f;
    unsigned char pad390;
    unsigned char pad391;
    unsigned char pad392;
    unsigned char pad393;
    unsigned char pad394;
    unsigned char pad395;
    unsigned char pad396;
    unsigned char pad397;
    unsigned char pad398;
    unsigned char pad399;
    unsigned char pad39a;
    unsigned char pad39b;
    unsigned char pad39c;
    unsigned char pad39d;
    unsigned char pad39e;
    unsigned char pad39f;
    unsigned char pad3a0;
    unsigned char pad3a1;
    unsigned char pad3a2;
    unsigned char pad3a3;
    unsigned char pad3a4;
    unsigned char pad3a5;
    unsigned char pad3a6;
    unsigned char pad3a7;
    unsigned char pad3a8;
    unsigned char pad3a9;
    unsigned char pad3aa;
    unsigned char pad3ab;
    unsigned char pad3ac;
    unsigned char pad3ad;
    unsigned char pad3ae;
    unsigned char pad3af;
    unsigned char pad3b0;
    unsigned char pad3b1;
    unsigned char pad3b2;
    unsigned char pad3b3;
    unsigned char pad3b4;
    unsigned char pad3b5;
    unsigned char pad3b6;
    unsigned char pad3b7;
    unsigned char pad3b8;
    unsigned char pad3b9;
    unsigned char pad3ba;
    unsigned char pad3bb;
    unsigned char pad3bc;
    unsigned char pad3bd;
    unsigned char pad3be;
    unsigned char pad3bf;
    unsigned char pad3c0;
    unsigned char pad3c1;
    unsigned char pad3c2;
    unsigned char pad3c3;
    unsigned char pad3c4;
    unsigned char pad3c5;
    unsigned char pad3c6;
    unsigned char pad3c7;
    unsigned char pad3c8;
    unsigned char pad3c9;
    unsigned char pad3ca;
    unsigned char pad3cb;
    unsigned char pad3cc;
    unsigned char pad3cd;
    unsigned char pad3ce;
    unsigned char pad3cf;
    unsigned char pad3d0;
    unsigned char pad3d1;
    unsigned char pad3d2;
    unsigned char pad3d3;
    unsigned char pad3d4;
    unsigned char pad3d5;
    unsigned char pad3d6;
    unsigned char pad3d7;
    unsigned char pad3d8;
    unsigned char pad3d9;
    unsigned char pad3da;
    unsigned char pad3db;
    unsigned char pad3dc;
    unsigned char pad3dd;
    unsigned char pad3de;
    unsigned char pad3df;
    unsigned char pad3e0;
    unsigned char pad3e1;
    unsigned char pad3e2;
    unsigned char pad3e3;
    unsigned char pad3e4;
    unsigned char pad3e5;
    unsigned char pad3e6;
    unsigned char pad3e7;
    unsigned char pad3e8;
    unsigned char pad3e9;
    unsigned char pad3ea;
    unsigned char pad3eb;
    unsigned char pad3ec;
    unsigned char pad3ed;
    unsigned char pad3ee;
    unsigned char pad3ef;
    unsigned char pad3f0;
    unsigned char pad3f1;
    unsigned char pad3f2;
    unsigned char pad3f3;
    unsigned char pad3f4;
    unsigned char pad3f5;
    unsigned char pad3f6;
    unsigned char pad3f7;
    unsigned char pad3f8;
    unsigned char pad3f9;
    unsigned char pad3fa;
    unsigned char pad3fb;
    unsigned char pad3fc;
    unsigned char pad3fd;
    unsigned char pad3fe;
    unsigned char pad3ff;
    unsigned char pad400;
    unsigned char pad401;
    unsigned char pad402;
    unsigned char pad403;
    unsigned char pad404;
    unsigned char pad405;
    unsigned char pad406;
    unsigned char pad407;
    unsigned char pad408;
    unsigned char pad409;
    unsigned char pad40a;
    unsigned char pad40b;
    unsigned char pad40c;
    unsigned char pad40d;
    unsigned char pad40e;
    unsigned char pad40f;
};

struct S_00c6c840_Outer : S_00c6c840_Pad, S_00c6c840_class
{
    void __thiscall bhkCharacterController_SetLinearVelocity_Ni(void* a);
};

extern int DAT_011f426c;

// Checks whether the value's low 7 bits equal 0x1e; if so increments unk6c and, when unk69 is set, calls FUN_00926980 with DAT_011f426c.
// @fnv 0x00c6c840
// src: XBOX_PDB 0x00c6c840
void __thiscall S_00c6c840_class::bhkCharacterListener_contactPointAddedCallback(int a, S_00c6c840_Param* b)
{
    S_00c6c840_Value* value = reinterpret_cast<S_00c6c840_Value*>(b->m_pObject_48);

    if ((value->m_value_1c & 0x7f) == 0x1e)
    {
        ++unk6c;

        if (unk69 != 0)
        {
            static_cast<S_00c6c840_Outer*>(this)->bhkCharacterController_SetLinearVelocity_Ni(&DAT_011f426c);
        }
    }
}

extern int g_unk012686d4;

// @fnv 0x00c6cd90
// src: COMMUNITY 0x00c6cd90
void* bhkShapeCollection_GetRTTI()
{
    return &g_unk012686d4;
}

namespace fnv_00c6cdc0 {
extern "C" void* __cdecl hkMemoryRouter_getInstance();

struct S_00c85750_vtbl
{
    void* unk00;
    void* unk04;
    void(__thiscall* unk08)(void*, void*, int);
};

struct S_00c85750_interface
{
    S_00c85750_vtbl* vtbl;
};

// If pObject is non-null, gets the owner via FUN_00c85750 and calls its interface vtbl unk08 with pObject and 0x80.
// @fnv 0x00c6cdc0
// src: GUESS 0x00c6cdc0 (confidence: low)
void __cdecl Object_UpdateFields_00c6cdc0(void* pObject)
{
    if (pObject != 0)
    {
        hkMemoryRouter* pOwner = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        S_00c85750_interface* pInterface = reinterpret_cast<S_00c85750_interface*>(pOwner->m_heap);
        S_00c85750_vtbl* pVtbl = pInterface->vtbl;
        pVtbl->unk08(pInterface, pObject, 0x80);
    }
}
}  // namespace fnv_00c6cdc0

extern int g_spawnCount;

struct SpawnBase
{
    SpawnBase();
    virtual ~SpawnBase();
    int unk04;
    int unk08;
};

struct SpawnField
{
    SpawnField(int a1);
    ~SpawnField();
    int unk00;
};

struct SpawnSlot
{
    int m_00;
    SpawnSlot() : m_00(0)
    {}
};

struct FUN_00c6ce80_cls : SpawnBase, SpawnSlot
{
    virtual ~FUN_00c6ce80_cls();
    SpawnField m_10;

    FUN_00c6ce80_cls();
};

// Increments g_spawnCount and initializes the SpawnField member m_10 with 0.
// @fnv 0x00c6ce80
FUN_00c6ce80_cls::FUN_00c6ce80_cls() : m_10(0)
{
    ++g_spawnCount;
}

// @fnv 0x00c6cee0
// src: COMMUNITY 0x00c6cee0
int __cdecl bhkCharacterProxy_GetCinfoSize()
{
    return 0x80;
}

struct FUN_00c6cef0_target
{
    void ahkpCharacterProxy_checkSupport(int a, int b);
};

struct FUN_00c6cef0_cls
{
    int unk00;
    int unk04;
    FUN_00c6cef0_target* m_08;
    void bhkCharacterController_UnMarkWrite();
    void CallTargetWithArgs(int a, int b);
};

// If this and m_08 are non-null, calls FUN_00cac110 before and after forwarding a and b to m_08's FUN_00cafd00.
// @fnv 0x00c6cef0
void FUN_00c6cef0_cls::CallTargetWithArgs(int a, int b)
{
    if (this != 0)
    {
        FUN_00c6cef0_target* target = m_08;
        if (target != 0)
        {
            bhkCharacterController_UnMarkWrite();
            target->ahkpCharacterProxy_checkSupport(a, b);
            bhkCharacterController_UnMarkWrite();
        }
    }
}

extern void __cdecl FUN_00cabf50();
void __cdecl operator delete(void*, unsigned int);

struct FUN_00c6d010_Class
{
    FUN_00c6d010_Class* __thiscall FUN_00c6d010(unsigned char flags);
};

// Calls FUN_00cabf50, then frees this with operator delete when bit 0 of flags is set, and returns this.
// @fnv 0x00c6d010
FUN_00c6d010_Class* __thiscall FUN_00c6d010_Class::FUN_00c6d010(unsigned char flags)
{
    FUN_00cabf50();

    if (flags & 1)
    {
        ::operator delete(this, 0x3e0);
    }

    return this;
}

extern int DAT_012685a4;

// @fnv 0x00c6d0e0
// src: COMMUNITY 0x00c6d0e0
int __cdecl bhkCachingShapePhantom_GetRTTI()
{
    return reinterpret_cast<int>(&DAT_012685a4);
}

// @fnv 0x00c6d0f0
// src: COMMUNITY 0x00c6d0f0
int bhkCachingShapePhantom_GetCInfoSize()
{
    return 0x60;
}

class C6D1E0Base
{
  public:
    C6D1E0Base();
    virtual ~C6D1E0Base();
};

class FUN_00c6d1e0 : public C6D1E0Base
{
  public:
    FUN_00c6d1e0(int a, int b);
    virtual ~FUN_00c6d1e0();

    void Init(int a, int b);
};

// Constructs the object and forwards both arguments to Init.
// @fnv 0x00c6d1e0
FUN_00c6d1e0::FUN_00c6d1e0(int a, int b)
{
    Init(a, b);
}

extern int DAT_01268444;

// @fnv 0x00c6d250
// src: COMMUNITY 0x00c6d250
void* __cdecl bhkCollisionBox_GetRTTI()
{
    return &DAT_01268444;
}

namespace fnv_00c6d260 {
struct FUN_00aa4060_class
{
    void __thiscall MemoryManager_Deallocate(void* p);
};

extern FUN_00aa4060_class DAT_011f6238;

struct FUN_00c6d260_class
{
    void __thiscall UpdateFields_00cbe880();
    FUN_00c6d260_class* __thiscall ScalarDeletingDestructor(unsigned int flags);
};

// @fnv 0x00c6d260
FUN_00c6d260_class* __thiscall FUN_00c6d260_class::ScalarDeletingDestructor(unsigned int flags)
{
    UpdateFields_00cbe880();
    if ((flags & 1) && this)
    {
        DAT_011f6238.MemoryManager_Deallocate((char*)this - ((unsigned char*)this)[-1]);
    }
    return this;
}
}  // namespace fnv_00c6d260

extern int DAT_012680f8;
extern int DAT_012686d0;
extern int DAT_012681a0;

struct FUN_00c87c30_owner
{
    FUN_00c87c30_owner();
    virtual void unkB0();
    ~FUN_00c87c30_owner();
    unsigned int m_04;
    unsigned int m_08;
};

struct FUN_00c8b090_owner
{
    void SetListShape(unsigned int a);
};

struct ChainA_cls : public FUN_00c87c30_owner
{
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls()
    {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct ChainB_cls : public ChainA_cls
{
    virtual void unkB1();
    ChainB_cls()
    {
        DAT_012686d0 += 1;
    }
};

struct FUN_00c6d290 : public ChainB_cls
{
    virtual void unkC2();
    FUN_00c6d290(unsigned int a);
};

// Calls the base SetListShape with a, then increments DAT_012681a0.
// @fnv 0x00c6d290
FUN_00c6d290::FUN_00c6d290(unsigned int a)
{
    ((FUN_00c8b090_owner*)this)->SetListShape(a);
    DAT_012681a0 += 1;
}

extern int g_unk012681a8;

// @fnv 0x00c6d310
// src: COMMUNITY 0x00c6d310
void* __cdecl bhkListShape_GetRTTI()
{
    return &g_unk012681a8;
}

void __cdecl operator delete(void*, unsigned int);

struct FUN_00c6d320_class
{
    void FUN_00c8adf0();
    void* __thiscall FUN_00c6d320(char flags);
};

// Calls FUN_00c8adf0, then frees this with operator delete when bit 0 of flags is set, and returns this.
// @fnv 0x00c6d320
void* __thiscall FUN_00c6d320_class::FUN_00c6d320(char flags)
{
    FUN_00c8adf0();
    if (flags & 1)
    {
        operator delete(this, 0x14);
    }
    return this;
}

__declspec(thread) unsigned int hkThreadModeSlots[174];

struct CallbackTarget
{
    void FUN_00c905b0();
};
extern CallbackTarget* DAT_01267bb8;

struct ScopedThreadMode
{
    unsigned int previous;

    __forceinline ScopedThreadMode() : previous(hkThreadModeSlots[173])
    {
        hkThreadModeSlots[173] = 16;
    }

    __forceinline ~ScopedThreadMode()
    {
        hkThreadModeSlots[173] = previous;
    }
};

// Sets thread mode slot 173 to 16 for the scope, then calls FUN_00c905b0 on DAT_01267bb8 if it is non-null.
// @fnv 0x00c6d340
void __cdecl RunCallbackIfPresent()
{
    ScopedThreadMode scope;
    if (DAT_01267bb8)
        DAT_01267bb8->FUN_00c905b0();
}

// A counted, polymorphic object: the vtable pointer sits at object offset 0,
// the reference counter at object offset 4, and the release handler is the
// second virtual of the class (vtable slot 1, i.e. vtable offset 4).
struct FNV_RefCounted
{
    virtual void v0();
    virtual void v1();
    volatile long m_iObjectReferenceCount;
};

// The global that owns the object; it is cleared once the object is released.
extern FNV_RefCounted* FNV_g_refCounted;

// Decrements the global ref-counted object's reference count and calls its v1() when it reaches zero, then clears the global pointer.
// @fnv 0x00c6d3c0
// src: COMMUNITY 0x00c6d3c0
void bhkCharacterControllerCinfo_ReleaseDefaultShape()
{
    if (FNV_g_refCounted)
    {
        FNV_RefCounted* pObject = FNV_g_refCounted;
        if (InterlockedDecrement(&FNV_g_refCounted->m_iObjectReferenceCount) == 0)
        {
            pObject->v1();
        }
        FNV_g_refCounted = 0;
    }
}

extern "C" double __cdecl sqrt(double dValue);

inline float BC6D6B0Sqrtf(float fValue)
{
    return (float)sqrt(fValue);
}

inline float BC6D6B0Sqrt(float fValue)
{
    return BC6D6B0Sqrtf(fValue);
}

class BC6D6B0Point3
{
  public:
    float x;
    float y;
    float z;

    BC6D6B0Point3 operator-(const BC6D6B0Point3& kPt) const
    {
        BC6D6B0Point3 kResult;
        kResult.x = x - kPt.x;
        kResult.y = y - kPt.y;
        kResult.z = z - kPt.z;
        return kResult;
    }

    float Length() const
    {
        return BC6D6B0Sqrt(x * x + y * y + z * z);
    }
};

struct BC6D6B0Bound
{
    BC6D6B0Point3 m_kCenter;
    float m_fBoundRadius;
};

extern BC6D6B0Bound g_kC6D6B0DefaultBound;

class BC6D6B0AVObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BC6D6B0Bound* m_pkWorldBound;
};

class BC6D6B0Tracker
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    float m_fHitDistance;

    void UpdateDistance(const BC6D6B0Point3& kPos, BC6D6B0AVObject* pkObject);
};

// @fnv 0x00c6d6b0
void BC6D6B0Tracker::UpdateDistance(const BC6D6B0Point3& kPos, BC6D6B0AVObject* pkObject)
{
    if (!pkObject)
        return;
    const BC6D6B0Bound* pkBound = pkObject->m_pkWorldBound ? pkObject->m_pkWorldBound : &g_kC6D6B0DefaultBound;
    float fDist = (kPos - pkBound->m_kCenter).Length() - pkBound->m_fBoundRadius;
    m_fHitDistance = fDist > 0.0f ? fDist : 0.0f;
}

struct S_00c6d7a0_Handler
{
    void bhkWorldObject_SetAVObject(int arg, int dflt);
};

struct S_00c6d7a0_Obj
{
    int unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134,
        unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174,
        unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4,
        unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4,
        unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234,
        unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260, unk264, unk268, unk26c, unk270, unk274,
        unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c, unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4,
        unk2b8, unk2bc;
    int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc, unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4,
        unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c, unk320, unk324, unk328, unk32c, unk330, unk334,
        unk338, unk33c;
    int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c, unk360, unk364, unk368, unk36c, unk370, unk374,
        unk378, unk37c;
    int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c, unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4,
        unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc, unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4,
        unk3f8, unk3fc;
    int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c, unk420, unk424, unk428, unk42c, unk430, unk434,
        unk438, unk43c;
    int unk440, unk444, unk448, unk44c, unk450, unk454, unk458, unk45c, unk460, unk464, unk468, unk46c, unk470, unk474,
        unk478, unk47c;
    int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c, unk4a0, unk4a4, unk4a8, unk4ac, unk4b0, unk4b4,
        unk4b8, unk4bc;
    int unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc, unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4,
        unk4f8, unk4fc;
    int unk500, unk504, unk508, unk50c, unk510, unk514, unk518, unk51c, unk520, unk524, unk528, unk52c, unk530, unk534,
        unk538, unk53c;
    int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c, unk560, unk564, unk568, unk56c, unk570, unk574,
        unk578, unk57c;
    int unk580, unk584, unk588, unk58c, unk590;
    S_00c6d7a0_Handler* unk594;
    S_00c6d7a0_Handler* unk598;
    void bhkCharacterController_SetNiObject(int arg);
};

// Forwards arg to the handler objects at unk594 and unk598, calling each with a default of 0 when present.
// @fnv 0x00c6d7a0
// src: XBOX_PDB 0x00c6d7a0
void S_00c6d7a0_Obj::bhkCharacterController_SetNiObject(int arg)
{
    if (unk594)
        unk594->bhkWorldObject_SetAVObject(arg, 0);
    if (unk598)
        unk598->bhkWorldObject_SetAVObject(arg, 0);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* p);

class RefObject
{
  public:
    virtual void v0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

class Holder
{
  public:
    char m_00[0x59c];
    int m_iIndex;
    int m_5a0;
    NiPointer<RefObject> m_aspObj[2];
    RefObject* GetCurrentObject();
};

// @fnv 0x00c6d960
RefObject* Holder::GetCurrentObject()
{
    return m_iIndex < 2 ? m_aspObj[m_iIndex] : NiPointer<RefObject>(0);
}

class C6DE10NiObject
{
  public:
    virtual ~C6DE10NiObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
            DeleteThis();
    }
};

class C6DE10ReferencedObject
{
  public:
    void RetainReference();
    void removeReference();
};

template <class T> class C6DE10RefPtr
{
  public:
    C6DE10RefPtr() : m_pRetainedObject(0)
    {}
    ~C6DE10RefPtr()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }

    C6DE10RefPtr& operator=(T* e)
    {
        if (e)
            e->RetainReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = e;
        return *this;
    }

    T* m_pRetainedObject;
};

class FUN_00c6de10
{
  public:
    ~FUN_00c6de10();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    NiPointer<C6DE10NiObject> m_spNode;
    C6DE10RefPtr<C6DE10ReferencedObject> m_spShape;
};

// Destructor that releases the referenced shape by assigning null to m_spShape, dropping its reference.
// @fnv 0x00c6de10
FUN_00c6de10::~FUN_00c6de10()
{
    m_spShape = 0;
}

// LookupFirstByKey - lookup helper.
//
//   0x00c6dec0  mov ecx, [esp+8]        ; the container (this for the inner call)
//   0x00c6dec4  sub esp, 8              ; 8-byte result block
//   0x00c6dec7  xor eax, eax            ; the shared zero (result + 3rd argument)
//   0x00c6dec9  test ecx, ecx
//   0x00c6decb  je   0x00c6dee0
//   0x00c6decd  push eax                ; third argument = 0
//   0x00c6dece  mov eax, [esp+0x10]     ; first argument
//   0x00c6ded2  push eax
//   0x00c6ded3  lea edx, [esp+8]        ; &result
//   0x00c6ded7  push edx
//   0x00c6ded8  call 0x00c6d840         ; container->Find(&result, key, 0)
//   0x00c6dedd  mov eax, [esp]          ; result.m_pFirst
//   0x00c6dee0  add esp, 8
//   0x00c6dee3  ret

struct FnvLookup_Result
{
    void* m_pFirst;
    void* m_pSecond;
};

struct FnvLookup_Container
{
    void __thiscall FnvLookup_Find(FnvLookup_Result* pOut, unsigned int uiKey, void* pExtra);
};

// Looks up uiKey in pContainer and returns the first pointer of the result, or null if pContainer is null.
// @fnv 0x00c6dec0
void* __cdecl LookupFirstByKey(unsigned int uiKey, FnvLookup_Container* pContainer)
{
    FnvLookup_Result result;
    void* pRes = 0;
    if (pContainer)
    {
        pContainer->FnvLookup_Find(&result, uiKey, 0);
        pRes = result.m_pFirst;
    }
    return pRes;
}

struct C6E030State
{
    int unk00;
    int m_iArrayLength;
};

struct C6E030Body
{
    C6E030State* GetState();
};

struct C6E030Holder
{
    int unk00;
    int unk04;
    C6E030Body* m_pkBody;

    void ResetState();
};

// @fnv 0x00c6e030
void C6E030Holder::ResetState()
{
    if (this && m_pkBody)
        m_pkBody->GetState()->m_iArrayLength = 0;
}

struct SettingHolder
{
    void* FUN_00653290(const void* key);
};
struct FUN_00c6e280_cls
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    SettingHolder* m_5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    float m_5f0;
    float GetSettingFloat();
};
extern char DAT_0126832c;
extern float DAT_010c72bc;

// @fnv 0x00c6e280
float FUN_00c6e280_cls::GetSettingFloat()
{
    volatile float result;
    SettingHolder* h = m_5a4;
    if (h != 0)
    {
        void* r = h->FUN_00653290(&DAT_0126832c);
        if (r != 0)
        {
            void* p = *(void**)((char*)r + 8);
            if (p != 0)
            {
                result = *(float*)((char*)p + 0x10);
            }
            else
            {
                result = DAT_010c72bc;
            }
            result = result;
            return result;
        }
    }
    result = m_5f0;
    return result;
}

void __cdecl bhkCharacterController_RemoveCollisionDebug();
struct ControllerShell
{
    int& selectedMode()
    {
        return *reinterpret_cast<int*>((char*)this + 0x59c);
    }
    int& availableMode(int index)
    {
        return *reinterpret_cast<int*>((char*)this + 0x5a4 + index * 4);
    }
    unsigned int& flags()
    {
        return *reinterpret_cast<unsigned int*>((char*)this + 0x414);
    }
    int bhkCharacterProxy_GethkPosition();
    int GetCurrentObject(int);
    void bhkCharacterController_SetShape(int);
    void SetMode(int);
    void CallVirtualReset(int value)
    {
        typedef void(__thiscall * VirtualFunc)(ControllerShell*, int);
        VirtualFunc* methods = *reinterpret_cast<VirtualFunc**>(this);
        methods[0x34](this, value);
    }
};
// @fnv 0x00c70830
void ControllerShell::SetMode(int mode)
{
    if (selectedMode() != mode && mode < 2 && availableMode(mode) != 0)
    {
        bool paused = (flags() >> 15) & 1;
        if (paused)
            bhkCharacterController_RemoveCollisionDebug();
        selectedMode() = mode;
        bhkCharacterController_SetShape(GetCurrentObject(bhkCharacterProxy_GethkPosition()));
        if (paused)
            CallVirtualReset(0);
    }
}

extern double DAT_01011588;

class FUN_00c708a0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned char m_414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54C;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55C;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56C;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57C;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58C;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    int m_59c;
    int m_5a0;
    unsigned int unk5A4;
    unsigned int unk5A8;
    unsigned int unk5AC;
    unsigned int unk5B0;
    unsigned int unk5B4;
    unsigned int unk5B8;
    unsigned int unk5BC;
    unsigned int unk5C0;
    unsigned int unk5C4;
    unsigned int unk5C8;
    unsigned int unk5CC;
    unsigned int unk5D0;
    unsigned int unk5D4;
    unsigned int unk5D8;
    unsigned int unk5DC;
    unsigned int unk5E0;
    unsigned int unk5E4;
    unsigned int unk5E8;
    unsigned int unk5EC;
    float m_5f0;
    float m_5f4;
    float m_5f8;
    unsigned int unk5FC;
    int m_600;
    void SetMode(int a1);
    void bhkCharacterController_SetSize(float a1);
};

// @fnv 0x00c708a0
// src: COMMUNITY 0x00c708a0
void FUN_00c708a0_cls::bhkCharacterController_SetSize(float afValue)
{
    if ((m_414 & 1) != 0)
    {
        return;
    }
    double scaled = (double)m_5f4 * DAT_01011588;
    double d = (afValue > scaled) ? (double)(float)scaled : (double)afValue;
    if (d <= 0.0)
    {
        d = m_5f0;
    }
    afValue = (float)d;
    if (afValue != m_5f8)
    {
        if (m_5a0 == 2)
        {
            m_5a0 = m_59c;
            SetMode(0);
        }
        m_600 = 2;
        m_5f8 = afValue;
    }
}

struct C70B60Point3
{
    float x;
    float y;
    float z;
};

extern const C70B60Point3 g_kC70B60Zero;

int __fastcall hkpCharacterContext_getState(char* pcState);

struct C70B60UpdateData
{
    float m_fTime;
    int unk04;
    int unk08;
    int unk0C;
    C70B60Point3 m_kValue;
};

class C70B60Character
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void ApplyUpdate(C70B60UpdateData* pkData);

    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    char m_acState[4];

    void bhkCharacterController_ChangeSize(float fTime);
    void bhkCharacterController_MoveImmobile(C70B60UpdateData* pkData, bool bForce);
};

// @fnv 0x00c70b60
// src: XBOX_PDB 0x00c70b60
void C70B60Character::bhkCharacterController_MoveImmobile(C70B60UpdateData* pkData, bool bForce)
{
    bool bStatic = hkpCharacterContext_getState(m_acState) == 2;
    if (bForce && bStatic)
    {
        pkData->m_kValue = g_kC70B60Zero;
        ApplyUpdate(pkData);
        return;
    }
    bhkCharacterController_ChangeSize(pkData->m_fTime);
}

namespace fnv_00c70bd0 {
struct RefCountedObj_b4889
{
    virtual void v0();
    virtual void Destroy();
    long m_iRef;
};

struct PoolNode_b4889
{
    RefCountedObj_b4889* m_pEntryObject;
    PoolNode_b4889* m_pNext;
};

struct ListNode_b4889
{
    PoolNode_b4889* m_pInventoryEntryData;
    ListNode_b4889* m_pNext;
    void Release();
};

struct PoolAllocator_b4889
{
    void Free(void* apPtr);
};

extern PoolAllocator_b4889 DAT_011f6238;

class FUN_00c70bd0_cls
{
  public:
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int unk02B4;
    unsigned int unk02B8;
    unsigned int unk02BC;
    unsigned int unk02C0;
    unsigned int unk02C4;
    unsigned int unk02C8;
    unsigned int unk02CC;
    unsigned int unk02D0;
    unsigned int unk02D4;
    unsigned int unk02D8;
    unsigned int unk02DC;
    unsigned int unk02E0;
    unsigned int unk02E4;
    unsigned int unk02E8;
    unsigned int unk02EC;
    unsigned int unk02F0;
    unsigned int unk02F4;
    unsigned int unk02F8;
    unsigned int unk02FC;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030C;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031C;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032C;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033C;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034C;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035C;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036C;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037C;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038C;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039C;
    unsigned int unk03A0;
    unsigned int unk03A4;
    unsigned int unk03A8;
    unsigned int unk03AC;
    unsigned int unk03B0;
    unsigned int unk03B4;
    unsigned int unk03B8;
    unsigned int unk03BC;
    unsigned int unk03C0;
    unsigned int unk03C4;
    unsigned int unk03C8;
    unsigned int unk03CC;
    unsigned int unk03D0;
    unsigned int unk03D4;
    unsigned int unk03D8;
    unsigned int unk03DC;
    unsigned int unk03E0;
    unsigned int unk03E4;
    unsigned int unk03E8;
    unsigned int unk03EC;
    unsigned int unk03F0;
    unsigned int unk03F4;
    unsigned int unk03F8;
    unsigned int unk03FC;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040C;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041C;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042C;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043C;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044C;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045C;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046C;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047C;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048C;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049C;
    unsigned int unk04A0;
    unsigned int unk04A4;
    unsigned int unk04A8;
    unsigned int unk04AC;
    unsigned int unk04B0;
    unsigned int unk04B4;
    unsigned int unk04B8;
    unsigned int unk04BC;
    unsigned int unk04C0;
    unsigned int unk04C4;
    unsigned int unk04C8;
    unsigned int unk04CC;
    unsigned int unk04D0;
    unsigned int unk04D4;
    unsigned int unk04D8;
    unsigned int unk04DC;
    unsigned int unk04E0;
    unsigned int unk04E4;
    unsigned int unk04E8;
    unsigned int unk04EC;
    unsigned int unk04F0;
    unsigned int unk04F4;
    unsigned int unk04F8;
    unsigned int unk04FC;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050C;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051C;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052C;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053C;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054C;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055C;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056C;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057C;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058C;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059C;
    unsigned int unk05A0;
    unsigned int unk05A4;
    unsigned int unk05A8;
    unsigned int unk05AC;
    unsigned int unk05B0;
    unsigned int unk05B4;
    unsigned int unk05B8;
    unsigned int unk05BC;
    unsigned int unk05C0;
    unsigned int unk05C4;
    unsigned int unk05C8;
    unsigned int unk05CC;
    unsigned int unk05D0;
    unsigned int unk05D4;
    unsigned int unk05D8;
    unsigned int unk05DC;
    unsigned int unk05E0;
    unsigned int unk05E4;
    unsigned int unk05E8;
    unsigned int unk05EC;
    unsigned int unk05F0;
    unsigned int unk05F4;
    unsigned int unk05F8;
    unsigned int unk05FC;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060C;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061C;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062C;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063C;
    unsigned int unk0640;
    unsigned int unk0644;
    PoolNode_b4889* m_648;
    ListNode_b4889* m_64c;

    void ClearList();
};

// Releases and frees all pooled nodes and list nodes until both m_648 and m_64c are empty, decrementing object refcounts and destroying them at zero.
// @fnv 0x00c70bd0
void FUN_00c70bd0_cls::ClearList()
{
    for (;;)
    {
        if (m_64c == 0 && m_648 == 0)
        {
            break;
        }
        PoolNode_b4889* cur = m_648;
        if (cur != 0)
        {
            RefCountedObj_b4889* obj = cur->m_pEntryObject;
            if (obj != 0)
            {
                if (InterlockedDecrement(&obj->m_iRef) == 0)
                {
                    obj->Destroy();
                }
            }
            DAT_011f6238.Free(cur);
        }
        ListNode_b4889* head = m_64c;
        if (head != 0)
        {
            m_64c = head->m_pNext;
            m_648 = head->m_pInventoryEntryData;
            head->m_pNext = 0;
            head->Release();
            DAT_011f6238.Free(head);
        }
        else
        {
            m_648 = 0;
        }
    }
}
}  // namespace fnv_00c70bd0

struct FUN_00c747b0_Class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual int vfB4(char* value);
    int UpdateState_00c747b0();
};

// @fnv 0x00c747b0
// src: GUESS 0x00c747b0 (confidence: low)
int FUN_00c747b0_Class::UpdateState_00c747b0()
{
    char value;
    int result = this->vfB4(&value);

    if (result != 0)
        return result - 4;

    return 0;
}

struct C74820Slot
{
    bool m_bModifierActive;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

class C74820Controller
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    unsigned char unk40;
    unsigned char unk41;
    unsigned char unk42;
    bool m_bFlagAt0x43;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    C74820Slot m_akSlots[2];
    unsigned char unk21C;
    bool m_bDefault;
    bool m_bEnableState;

    void SetSlotActive(int iSlot, bool bActive);
};

// @fnv 0x00c74820
void C74820Controller::SetSlotActive(int iSlot, bool bActive)
{
    if (bActive)
        m_bEnableState = !m_bFlagAt0x43 ? m_bDefault != 0 : m_bEnableState;
    if (m_bEnableState)
        m_akSlots[iSlot].m_bModifierActive = bActive;
}

struct MapEntry
{
    MapEntry* next;
    unsigned int key;
    unsigned short value;
};

struct MapTable
{
    virtual void Destroy();
    virtual unsigned int Hash(unsigned int key);
    virtual bool Equal(unsigned int lhs, unsigned int rhs);
    virtual void Initialize(MapEntry* entry, unsigned int key, unsigned int value);
    virtual void OnResize();
    virtual MapEntry* AllocateEntry();

    unsigned int bucketCount;
    MapEntry** buckets;
    unsigned int count;

    void InsertOrUpdate(unsigned int key, unsigned int value);
};

// Looks up key in the hash bucket, updates the entry's value if found, otherwise allocates, initializes and prepends a new entry and increments count.
// @fnv 0x00c74910
void MapTable::InsertOrUpdate(unsigned int key, unsigned int value)
{
    unsigned int bucket = Hash(key);
    MapEntry* entry = buckets[bucket];
    while (entry)
    {
        if (Equal(key, entry->key))
        {
            entry->value = (unsigned short)value;
            return;
        }
        entry = entry->next;
    }

    MapEntry* newEntry = AllocateEntry();
    Initialize(newEntry, key, value);
    newEntry->next = buckets[bucket];
    buckets[bucket] = newEntry;
    ++count;
}

struct FUN_00c74990_node
{
    FUN_00c74990_node* next;
    unsigned int key;
    unsigned short value;
};

class FUN_00c74990_cls
{
  public:
    virtual void GetPad();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeyEqual(unsigned int a, unsigned int b);
    unsigned int m_uiHashSize;
    FUN_00c74990_node** m_ppkHashTable;
    unsigned int m_uiCount;
    bool LookupValue(unsigned int key, unsigned short* out);
};

// Hashes the key, walks the bucket chain comparing keys, and writes the matching node's value to out, returning whether a match was found.
// @fnv 0x00c74990
bool FUN_00c74990_cls::LookupValue(unsigned int key, unsigned short* pusValue)
{
    unsigned int idx = KeyToHashIndex(key);
    FUN_00c74990_node* cur = m_ppkHashTable[idx];
    while (cur != 0)
    {
        if (IsKeyEqual(key, cur->key))
        {
            *pusValue = cur->value;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

void* FUN_00ec7230(void* pvDst, const void* pvSrc, unsigned int uiSize);

struct C749F0Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
};

// Overlap-safe element move.
// @fnv 0x00c749f0
void __stdcall CopyEntries(C749F0Entry* pkDst, const C749F0Entry* pkSrc, unsigned int ItemUpdateArray)
{
    if (ItemUpdateArray > 0)
    {
        if (pkDst < pkSrc)
        {
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
                FUN_00ec7230(&pkDst[i], &pkSrc[i], sizeof(C749F0Entry));
        }
        else if (pkDst > pkSrc)
        {
            for (int i = ItemUpdateArray - 1; i >= 0; i--)
                FUN_00ec7230(&pkDst[i], &pkSrc[i], sizeof(C749F0Entry));
        }
    }
}

namespace fnv_00c74f50 {
void* __cdecl hkMemoryRouter_getInstance();

// If param_1 is nonzero, obtains a result object via FUN_00c85750 and calls vf08 on its unk10 target with param_1 and 0x38.
// @fnv 0x00c74f50
// src: GUESS 0x00c74f50 (confidence: low)
void __cdecl hkMemoryRouter_UpdateState_00c74f50(int aiValue)
{
    if (aiValue != 0)
    {
        hkMemoryRouter* result = static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
        GetRouterHeap(*result).blockFree(reinterpret_cast<void*>(aiValue), 0x38);
    }
}
}  // namespace fnv_00c74f50

namespace fnv_00c74f70 {
// FUN_00c74f70 : cdecl one-arg entry point.  The argument is null checked; if
// it is present the game allocator is fetched from the global allocator
// holder and its virtual slot 2 is asked to release the block with a fixed
// 0x48 byte size.

struct AllocClass
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p, unsigned int size);
};

hkMemoryRouter* hkMemoryRouter_getInstance();

// @fnv 0x00c74f70
// src: GUESS 0x00c74f70 (confidence: low)
void __cdecl hkMemoryRouter_UpdateState_00c74f70(void* p)
{
    if (p)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        AllocClass* allocator = reinterpret_cast<AllocClass*>(holder->m_heap);
        allocator->v2(p, 0x48);
    }
}
}  // namespace fnv_00c74f70

extern __declspec(thread) int g_tlsRoutingMode;

struct RoutingModeScope
{
    int previousMode;

    RoutingModeScope() : previousMode(g_tlsRoutingMode)
    {
        g_tlsRoutingMode = 16;
    }
    ~RoutingModeScope()
    {
        g_tlsRoutingMode = previousMode;
    }
};

struct RouteTarget
{
    virtual void Run(int mode);
};

struct RouteWrapper
{
    RouteTarget* target;
    void RunTargetWithMode();
};

// Saves the thread routing mode, sets it to 16, and if target is non-null calls target->Run(1), then restores the previous mode.
// @fnv 0x00c75100
void RouteWrapper::RunTargetWithMode()
{
    RoutingModeScope modeScope;
    if (target)
        target->Run(1);
}

class C75850Shape
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual int GetType();

    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    void* m_pResource;

    int hkpRagdollConstraintData_getTwistMotor();
    int hkpRagdollConstraintData_getConeMotor();
    int hkpRagdollConstraintData_getPlaneMotor();
};

struct C75850Entry
{
    int unk00;
    int unk04;
    int unk08;
    C75850Shape* m_pkShape;
};

struct C75850Group
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    C75850Entry** m_ppkEntries;
    int m_iArrayLength;
};

class C75850Body
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    C75850Group* m_pkActorGroup;

    int IsBodyValid();
};

// @fnv 0x00c75850
int C75850Body::IsBodyValid()
{
    bool bValid = true;
    C75850Group* pkGroup = m_pkActorGroup;
    if (pkGroup)
    {
        for (int i = 0; i < pkGroup->m_iArrayLength && bValid; i++)
        {
            C75850Shape* pkShape = pkGroup->m_ppkEntries[i]->m_pkShape;
            if (pkShape->GetType() == 0xd || pkShape->GetType() == 0xc)
            {
                bValid = false;
            }
            else
            {
                switch (pkShape->GetType())
                {
                case 2:
                    if (!pkShape->m_pResource)
                        bValid = false;
                    break;
                case 7:
                    if (!pkShape->hkpRagdollConstraintData_getTwistMotor() || !pkShape->hkpRagdollConstraintData_getConeMotor() || !pkShape->hkpRagdollConstraintData_getPlaneMotor())
                        bValid = false;
                    break;
                }
            }
        }
    }
    if (bValid && m_pkActorGroup)
        return 1;
    return 0;
}

template <class T> static T& member_at(void* object, unsigned int offset)
{
    return *reinterpret_cast<T*>(reinterpret_cast<unsigned char*>(object) + offset);
}

extern const double DAT_010290b0;

struct FUN_00c759f0_Class
{
    void bhkRagdollController_ResetDriveGains();
};

// @fnv 0x00c759f0
// src: COMMUNITY 0x00c759f0
void FUN_00c759f0_Class::bhkRagdollController_ResetDriveGains()
{
    void* sourceOwner = member_at<void*>(this, 0x2a4);
    void* source = member_at<void*>(sourceOwner, 0x18);
    if (source)
    {
        void* destination = *member_at<void**>(this, 0x4c);
        member_at<float>(destination, 0x0c) = member_at<float>(source, 0x10);
        member_at<float>(destination, 0x10) =
            member_at<float>(member_at<void*>(member_at<void*>(this, 0x2a4), 0x18), 0x0c);
        member_at<float>(destination, 0x1c) =
            member_at<float>(member_at<void*>(member_at<void*>(this, 0x2a4), 0x18), 0x18);
        member_at<float>(this, 0x290) = member_at<float>(member_at<void*>(member_at<void*>(this, 0x2a4), 0x18), 0x04);
        double scale = 0.25;
        member_at<unsigned int>(this, 0x29c) = static_cast<unsigned int>(
            static_cast<float>(member_at<unsigned int>(member_at<void*>(member_at<void*>(this, 0x2a4), 0x18), 0x38)) *
            scale);
        member_at<unsigned int>(this, 0x298) = static_cast<unsigned int>(
            static_cast<float>(member_at<unsigned int>(member_at<void*>(member_at<void*>(this, 0x2a4), 0x18), 0x3c)) *
            scale);
    }
}

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

// @fnv 0x00c75ce0
template <> void PoseMapBase::SetValue(NiTMapItem<const char*, NiPointer<bhkPoseArray> >* item, const char* key, NiPointer<bhkPoseArray> value)
{
    item->m_key = key;
    item->m_val = value;
}

// @fnv 0x00c75e20
template <> void RagdollMapBase::SetValue(NiTMapItem<const char*, NiPointer<bhkRagdollShareData> >* item, const char* key, NiPointer<bhkRagdollShareData> value)
{
    item->m_key = key;
    item->m_val = value;
}

// @fnv 0x00c75ed0
template <> NiTMap<const char*, NiPointer<bhkRagdollShareData> >::~NiTMap()
{
    RemoveAll();
}

class FUN_00c75f40_cls
{
  public:
    void AllocBytes(unsigned int size);
};

extern FUN_00c75f40_cls g_pool_00c75f40;

// @fnv 0x00c75f40
void __stdcall AllocCountedBytes(unsigned int count)
{
    unsigned int size = count * 4;
    g_pool_00c75f40.AllocBytes(size);
}

namespace fnv_00c76010 {
struct S_00aa4060_cls
{
    void __thiscall MemoryManager_Deallocate(NiTMapItem<NiAVObject*, short>* a);
};

extern S_00aa4060_cls DAT_011f6238;

// @fnv 0x00c76010
// src: GUESS 0x00c76010 (confidence: low)
void __stdcall NiTMapItem_UpdateState_00c76010(NiTMapItem<NiAVObject*, short>* pRecord)
{
    pRecord->m_val = 0;
    DAT_011f6238.MemoryManager_Deallocate(pRecord);
}
}  // namespace fnv_00c76010

// @fnv 0x00c760b0
ObjectMapBase* __fastcall DeleteObjectMapBase(ObjectMapBase* self, void*, unsigned int flags)
{
    *reinterpret_cast<void**>(self) = &fnv_00c75f80::DAT_010c4cf8;
    self->RemoveAll();
    NiFreeAlias(self->m_ppkHashTable);
    if (flags & 1)
        _g_memoryManager.Deallocate(self);
    return self;
}

struct FUN_00c76180_cls
{
    int m_04;
    int unk08;
    int m_0c;
    virtual int v0();
    virtual int v1(int a);
    virtual void v2(int a);
    virtual int v3(int a, int b);
    void Helper0(int a, int b, int c);
    void SetValue(int a1, int a2);
};

// @fnv 0x00c76180
void FUN_00c76180_cls::SetValue(int aiValue, int a2)
{
    if (m_04 != 0)
    {
        if (a2 == m_0c)
        {
            m_04 = v3(m_04, aiValue);
        }
        else
        {
            int t = v1(aiValue);
            Helper0(t, m_04, a2);
            v2(m_04);
            m_04 = t;
        }
    }
    else
    {
        m_04 = v1(aiValue);
        m_0c = aiValue;
    }
}

class C761F0Bool
{
  public:
    C761F0Bool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }

    char m_cBooleanValue;
};

class C761F0Character
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char m_uiContentCount;

    C761F0Bool hkpEntity_isFixedOrKeyframed() const;
};

// @fnv 0x00c761f0
// src: HAVOK_LIB 0x00c761f0
C761F0Bool C761F0Character::hkpEntity_isFixedOrKeyframed() const
{
    return m_uiContentCount == 5 || m_uiContentCount == 4;
}

struct RefTarget_b5394
{
    unsigned int m_iRefCount;
    void DecRefCount();
    void IncRefCount();
};

struct VirtTarget_b5394
{
    virtual ~VirtTarget_b5394();
};

struct StrTarget_b5394
{
    void Release();
};

struct Heap_b5394
{
    void Free(void* p);
};

extern Heap_b5394 g_strHeap_b5394;

class Base_b5394
{
  public:
    virtual ~Base_b5394();
};

class FUN_00c76240_cls : public Base_b5394
{
  public:
    unsigned int m_04;
    RefTarget_b5394* m_08;
    VirtTarget_b5394* m_0c;
    RefTarget_b5394* m_10;
    RefTarget_b5394* m_14;
    unsigned int m_18;
    char* m_1c;
    virtual ~FUN_00c76240_cls();
};

// Destructor that decrements reference counts on m_08, m_10 and m_14, deletes m_0c, and releases and frees the string at m_1c.
// @fnv 0x00c76240
FUN_00c76240_cls::~FUN_00c76240_cls()
{
    if (m_08)
        m_08->DecRefCount();
    delete m_0c;
    if (m_10)
        m_10->DecRefCount();
    if (m_14)
        m_14->DecRefCount();
    char* str = m_1c;
    if (str)
    {
        ((StrTarget_b5394*)str)->Release();
        char* base = str - (unsigned char)str[-1];
        g_strHeap_b5394.Free(base);
    }
}

struct FUN_00c762f0_Data
{
    int unk00;
    int unk04;
    int* unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int* unk20;
};

struct FUN_00c762f0_Prefix00
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
};

struct FUN_00c762f0_Prefix4C
{
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
};

struct FUN_00c762f0_Owner : public FUN_00c762f0_Prefix00
{
    FUN_00c762f0_Data* unk48;
    FUN_00c762f0_Prefix4C unk4C;
    int unk2B8;

    int __thiscall bhkRagdollController_GetHeadRigidBody();
};

// Looks up data->unk20[unk2B8]; if non-negative, returns data->unk08 at that index, otherwise 0.
// @fnv 0x00c762f0
// src: COMMUNITY 0x00c762f0
int FUN_00c762f0_Owner::bhkRagdollController_GetHeadRigidBody()
{
    FUN_00c762f0_Data* data = unk48;
    if (data != 0)
    {
        int index = unk2B8;
        int value = data->unk20[index];
        if (value >= 0)
        {
            return data->unk08[value];
        }
    }
    return 0;
}

struct C78090Vertex
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    unsigned int m_uiValue1;

    bool IsHidden() const
    {
        return (m_uiValue1 >> 1) & 1;
    }
};

struct C78090Triangle
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    short m_asVertex0;
    short m_asVertex1;
    short m_asVertex2;
    short unk1A;
};

struct C78090TriangleEntry
{
    C78090Triangle* m_pkTriangle;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
};

struct C78090Mesh
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    C78090Vertex** m_ppkVertices;
    unsigned int m_uiVertexCount;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    C78090TriangleEntry* m_pkTriangles;
    int m_iTriangleCount;

    C78090Vertex* GetVertex(unsigned int uiIndex) const
    {
        return m_uiVertexCount > uiIndex ? m_ppkVertices[uiIndex] : 0;
    }

    bool HasVisibleVertex();
};

// Scans the mesh's triangles and returns true as soon as any of a triangle's three vertices exists and is not hidden.
// @fnv 0x00c78090
bool C78090Mesh::HasVisibleVertex()
{
    bool bFound = false;
    for (int i = 0; i < m_iTriangleCount && !bFound; i++)
    {
        C78090Triangle& kTri = *m_pkTriangles[i].m_pkTriangle;
        C78090Vertex* pkVertex2 = GetVertex(kTri.m_asVertex2);
        C78090Vertex* pkVertex1 = GetVertex(kTri.m_asVertex1);
        C78090Vertex* pkVertex0 = GetVertex(kTri.m_asVertex0);
        bFound = (pkVertex2 && !pkVertex2->IsHidden()) || (pkVertex1 && !pkVertex1->IsHidden()) ||
                 (pkVertex0 && !pkVertex0->IsHidden());
    }
    return bFound;
}

struct FUN_00c79d60_R
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned int m_30;
};

struct FUN_00c79d60_Q
{
    FUN_00c79d60_R* m_00;
    FUN_00c79d60_R* m_04;
    FUN_00c79d60_R* m_08;
};

struct FUN_00c79d60_P
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    FUN_00c79d60_Q* m_a0;
};

struct FUN_00c79d60_W
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37(FUN_00c79d60_P* p, int flag);
    virtual void v38();
    virtual void v39();
    virtual void v3a(FUN_00c79d60_P* p);
};

struct FUN_00c79d60_V
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual FUN_00c79d60_W* v03();
};

class FUN_00c79d60_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    FUN_00c79d60_V* m_58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    FUN_00c79d60_P* m_84;
    void bhkRagdollController_ShowDebugLines(bool a1, bool a2, bool a3);
};

// Sets or clears bit 0 of the m_30 flags on the three entries in m_84->m_a0 based on a1/a2/a3, then calls v3a or v37 on the object from m_58->v03().
// @fnv 0x00c79d60
// src: COMMUNITY 0x00c79d60
void FUN_00c79d60_cls::bhkRagdollController_ShowDebugLines(bool abFlag1, bool abFlag2, bool abFlag3)
{
    FUN_00c79d60_Q* q = m_84->m_a0;
    FUN_00c79d60_R* r = q->m_00;
    if (!abFlag1)
    {
        r->m_30 |= 1u;
    }
    else
    {
        r->m_30 &= 0xfffffffeu;
    }
    r = m_84->m_a0->m_04;
    if (!abFlag2)
    {
        r->m_30 |= 1u;
    }
    else
    {
        r->m_30 &= 0xfffffffeu;
    }
    r = m_84->m_a0->m_08;
    if (!abFlag3)
    {
        r->m_30 |= 1u;
    }
    else
    {
        r->m_30 &= 0xfffffffeu;
    }
    FUN_00c79d60_W* w = m_58->v03();
    if (w != 0)
    {
        if (!abFlag1 && !abFlag2 && !abFlag3)
        {
            w->v3a(m_84);
        }
        else if (m_84->m_18 == 0)
        {
            w->v37(m_84, 1);
        }
    }
}

// FUN_00c7a230: thiscall, 1 bool arg, /MT /O2 /GS /EHsc /Gy
struct ListItem
{
    int unk00;
    int unk04;
    int m_08;
};

struct ListMgr
{
    void bhkWorld_Add_00c6b320(ListItem* item);
    void bhkWorld_Remove_00c68d50(ListItem* item);
};

struct ListLevel3
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    ListMgr* m_350;
};

struct ListLevel2
{
    int unk00;
    int unk04;
    ListLevel3* m_08;
};

struct ListLevel1
{
    ListLevel2* m_00;
};

struct ListOwner
{
    int unk00;
    int unk04;
    ListLevel1* m_08;
    int unk0C;
    int unk10;
    ListItem** m_14;
    int m_18;
};

class FUN_00c7a230_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    ListOwner* m_48;
    void bhkRagdollController_UpdateConstraintsWorld(bool abActive);
};

// @fnv 0x00c7a230
// src: COMMUNITY 0x00c7a230
void FUN_00c7a230_cls::bhkRagdollController_UpdateConstraintsWorld(bool abActive)
{
    ListOwner* owner = m_48;
    int firstFlag = (owner->m_14[0] != 0) ? owner->m_14[0]->m_08 : 0;
    ListLevel1* lv = owner->m_08;
    ListLevel2* l2 = lv->m_00;
    if (l2 == 0)
    {
        return;
    }
    ListLevel3* d = l2->m_08;
    if (d == 0)
    {
        return;
    }
    if (abActive)
    {
        if (firstFlag != 0)
        {
            return;
        }
    }
    else
    {
        if (firstFlag == 0)
        {
            return;
        }
    }
    ListMgr* mgr = d->m_350;
    if (abActive)
    {
        for (int i = 0; i < owner->m_18; ++i)
        {
            ListItem* item = owner->m_14[i];
            if (item->m_08 == 0)
            {
                mgr->bhkWorld_Add_00c6b320(item);
            }
        }
    }
    else
    {
        for (int i = 0; i < owner->m_18; ++i)
        {
            ListItem* item = owner->m_14[i];
            if (item->m_08 != 0)
            {
                mgr->bhkWorld_Remove_00c68d50(item);
            }
        }
    }
}

struct Behavior;
struct Record
{
    unsigned int unk00, unk04, unk08;
    Behavior* behavior;
};
struct CountBlock
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int count;
};
struct InputMap
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    Record** records;
    unsigned int unk18, unk1c;
    int* indices;
    unsigned int unk24, unk28;
    CountBlock* counts;
};
struct StateFlag
{
    bool enabled;
    StateFlag(bool value) : enabled(value)
    {}
};
extern int DAT_01268370;
struct Behavior
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int GetKind();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    float valueAC;
    Behavior* hkpMalleableConstraintData_getWrappedConstraintData();
    void hkpLimitedHingeConstraintData_setMotorActive(Record*, StateFlag);
    void SetFlagAndClearFloats(Record*, StateFlag);
    void hkpRagdollConstraintData_setTarget(int*);
};
// @fnv 0x00c7a2d0
void __cdecl EnableBehaviorsByKind(InputMap* input)
{
    int count = input->counts->count;
    for (int i = 0; i < count; ++i)
    {
        int index = input->indices[i] - 1;
        if (index < 0)
            continue;
        Record* item = input->records[index];
        if (!item)
            continue;
        Behavior* behavior = item->behavior;
        if (behavior->GetKind() == 13)
            behavior = behavior->hkpMalleableConstraintData_getWrappedConstraintData();
        if (!behavior)
            continue;
        switch (behavior->GetKind())
        {
        case 2:
            behavior->hkpLimitedHingeConstraintData_setMotorActive(item, true);
            behavior->valueAC = 0.0f;
            break;
        case 7:
            behavior->SetFlagAndClearFloats(item, true);
            behavior->hkpRagdollConstraintData_setTarget(&DAT_01268370);
            break;
        }
    }
}

struct UpdateOptions
{
    unsigned char enabled;
    UpdateOptions(bool value) : enabled(value)
    {}
};

struct ObjectView
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual int GetKind();

    ObjectView* hkpMalleableConstraintData_getWrappedConstraintData();
    void SetFlagAndClearFloats(struct ComponentEntry* entry, UpdateOptions options);
    void hkpLimitedHingeConstraintData_setMotorActive(struct ComponentEntry* entry, UpdateOptions options);
};

struct ComponentEntry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    ObjectView* view;
};

struct ObjectCount
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int count;
};

struct ObjectContext
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    ComponentEntry** entries;
    void* unk18;
    void* unk1c;
    int* indices;
    void* unk24;
    void* unk28;
    ObjectCount* length;
};

// @fnv 0x00c7a380
void __cdecl UpdateEntriesByKind(ObjectContext* context)
{
    const int count = context->length->count;
    for (int index = 0; index < count; ++index)
    {
        int entryIndex = context->indices[index] - 1;
        if (entryIndex >= 0)
        {
            ComponentEntry* entry = context->entries[entryIndex];
            if (entry != 0)
            {
                ObjectView* view = entry->view;
                if (view->GetKind() == 13)
                    view = view->hkpMalleableConstraintData_getWrappedConstraintData();
                if (view != 0)
                {
                    int kind = view->GetKind();
                    switch (kind)
                    {
                    case 2:
                        view->hkpLimitedHingeConstraintData_setMotorActive(entry, false);
                        break;
                    case 7:
                        view->SetFlagAndClearFloats(entry, false);
                        break;
                    }
                }
            }
        }
    }
}

struct ReallocationManager : MemoryManager
{
    void* Reallocate(void* memory, unsigned int bytes);
};

// Calls the memory manager's reallocation routine with the given memory block and a byte size of count * 56.
// @fnv 0x00c7a600
// src: GUESS 0x00c7a600 (confidence: medium)
void* __stdcall Object_Reallocate_Thunk(void* memory, unsigned int count)
{
    return static_cast<ReallocationManager*>(&_g_memoryManager)->Reallocate(memory, count * 56);
}

struct S_00c7a660_Foo
{
    int* vtbl;
    void* m_p;
    void* m_kPointA;
    void* m_kPointB;

    void __thiscall SetVirtualTable_00c7a660();
};

// Sets the vtable, and if m_p is non-null calls DAT_010c4cec on it then clears m_p and the two following pointers.
// @fnv 0x00c7a660
// src: GUESS 0x00c7a660 (confidence: low)
void __thiscall S_00c7a660_Foo::SetVirtualTable_00c7a660()
{
    vtbl = &DAT_010c4ce4;

    void* p = m_p;
    if (p)
    {
        (*(void(__stdcall**)(void*)) & DAT_010c4cec)(p);

        m_p = 0;
        m_kPointB = 0;
        m_kPointA = 0;
    }
}

struct S_c7a730
{
    virtual void* unk_v0(unsigned int n);
    virtual void* unk_v1(unsigned int n);
    void* unk04;
    int unk08;
    unsigned int unk0c;
    void SetValue(unsigned int newCap, int oldSize);
    int AppendSlot();
};

// Grows the buffer when full (doubling up to 0x400, then +0x400) and returns the index of the next appended slot.
// @fnv 0x00c7a730
int S_c7a730::AppendSlot()
{
    if (unk08 == unk0c)
    {
        if (unk0c == 0)
        {
            unk04 = unk_v1(4);
            unk0c = 4;
        }
        else
        {
            unsigned int newCap = unk0c + 0x400;
            if (unk0c <= 0x400)
                newCap = unk0c * 2;
            SetValue(newCap, unk08);
            unk0c = newCap;
        }
    }
    unk08++;
    return unk08 - 1;
}

struct U16Array
{
    virtual void v0();
    virtual unsigned short* Allocate(unsigned int n);
    virtual void Free(unsigned short* p);
    unsigned short* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void SetOrReplace(unsigned int newCap, unsigned int oldSize);

    __forceinline void SetSize(unsigned int n)
    {
        if (n == 0)
        {
            if (m_data)
            {
                Free(m_data);
                m_data = 0;
                m_pRayCursor = 0;
                m_iElementCount = 0;
            }
        }
        else if (n > m_pRayCursor)
        {
            if (m_pRayCursor == 0)
                m_data = Allocate(n);
            else
                SetOrReplace(n, m_iElementCount);
            m_pRayCursor = n;
            m_iElementCount = n;
        }
        else if (n < m_iElementCount)
        {
            unsigned int quarter = m_pRayCursor >> 2;
            m_iElementCount = n;
            if (n <= quarter)
            {
                SetOrReplace(n, n);
                m_pRayCursor = n;
            }
        }
        else
        {
            m_iElementCount = n;
        }
    }
};

struct FUN_00c7a790_Data
{
    char m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    float m_34;
    int m_38;
    int m_3c;
    U16Array m_ppData;

    void CopyFrom(const FUN_00c7a790_Data& src);
};

// Copies the U16Array contents and all scalar fields from src into this object.
// @fnv 0x00c7a790
void FUN_00c7a790_Data::CopyFrom(const FUN_00c7a790_Data& src)
{
    m_ppData.SetSize(src.m_ppData.m_iElementCount);
    for (unsigned int i = 0; i < src.m_ppData.m_iElementCount; i++)
        m_ppData.m_data[i] = src.m_ppData.m_data[i];
    m_00 = src.m_00;
    m_04 = src.m_04;
    m_08 = src.m_08;
    m_0c = src.m_0c;
    m_10 = src.m_10;
    m_14 = src.m_14;
    m_18 = src.m_18;
    m_1c = src.m_1c;
    m_20 = src.m_20;
    m_24 = src.m_24;
    m_28 = src.m_28;
    m_2c = src.m_2c;
    m_30 = src.m_30;
    m_34 = src.m_34;
    m_38 = src.m_38;
    m_3c = src.m_3c;
}

namespace fnv_00c7a990 {
struct S_arr
{
    int* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiValue1;
};

struct S_node
{
    virtual void* v0();
    virtual void* v1();
    virtual S_node* Query();
    int m_unk04;
    int m_unk08;
};

struct S_listentry
{
    S_node* m_pReferencedNode;
    S_listentry* m_pNext;
};

struct S_item
{
    int m_unk00;
    int m_unk04;
    int m_value08;
    int m_unk0C;
    int m_unk10;
    S_listentry m_list14;
};

extern "C" void* hkMemoryRouter_getInstance();
extern "C" void ResizeAudioStream(void* allocator, S_arr* arr, unsigned int growBy);
extern int DAT_0126818c;

static __forceinline bool S_IsKind(S_node* r)
{
    while (r)
    {
        if ((void*)r == (void*)&DAT_0126818c)
            return true;
        r = *(S_node**)((char*)r + 4);
    }
    return false;
}

// Appends item->m_value08 to arr, then walks item->m_list14 and appends each matching node's m_value08 to arr2, growing both arrays as needed.
// @fnv 0x00c7a990
void CollectItemValues(S_item* item, S_arr* pValues, S_arr* pLinkedValues)
{
    if (item == 0)
    {
        return;
    }
    int value = item->m_value08;
    hkMemoryRouter* holder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    if (pValues->m_uiSize == (pValues->m_uiValue1 & 0x3fffffff))
    {
        ResizeAudioStream(holder->m_heap, pValues, 4);
    }
    int* slot = pValues->m_pBuffer + pValues->m_uiSize;
    for (int k = 0; k < 1; k++)
        slot[k] = value;
    unsigned int uiIncrement = 1;
    pValues->m_uiSize += uiIncrement;

    S_listentry* entry = &item->m_list14;
    while (entry != 0)
    {
        S_node* node = entry->m_pReferencedNode;
        if (node == 0)
        {
            break;
        }
        S_node* r = node->Query();
        bool found = S_IsKind(r);
        S_node* pSelectedNode = found ? node : 0;
        if (pSelectedNode != 0)
        {
            S_item* obj = (S_item*)pSelectedNode;
            int v = obj->m_value08;
            holder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
            if (pLinkedValues->m_uiSize == (pLinkedValues->m_uiValue1 & 0x3fffffff))
            {
                ResizeAudioStream(holder->m_heap, pLinkedValues, 4);
            }
            int* piLinkedSlot = pLinkedValues->m_pBuffer + pLinkedValues->m_uiSize;
            for (int k = 0; k < 1; k++)
                piLinkedSlot[k] = v;
            pLinkedValues->m_uiSize += uiIncrement;
        }
        entry = entry->m_pNext;
    }
}
}  // namespace fnv_00c7a990

namespace fnv_00c7b0b0 {
struct FUN_00c85750_Object
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void __thiscall v4(int a, int b);
};

void* __cdecl hkMemoryRouter_getInstance();

struct FUN_00c7b0b0_class
{
    volatile int unk00;
    volatile int unk04;
    volatile int unk08;

    void __thiscall UpdateState_00c7b0b0();
};

// @fnv 0x00c7b0b0
// src: GUESS 0x00c7b0b0 (confidence: low)
void FUN_00c7b0b0_class::UpdateState_00c7b0b0()
{
    void* pObject = hkMemoryRouter_getInstance();
    FUN_00c85750_Object* pTarget = reinterpret_cast<FUN_00c85750_Object*>(
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(pObject) + 0x10));

    int value = unk08;
    unk04 = 0;

    if ((value & 0x80000000) == 0)
    {
        int count = value & 0x3fffffff;
        count *= 0xd0;
        pTarget->v4(unk00, count);
    }

    unk08 = 0x80000000;
    unk00 = 0;
}
}  // namespace fnv_00c7b0b0

namespace fnv_00c7b130 {
hkMemoryRouter* hkMemoryRouter_getInstance();

struct FUN_00c7b130_cls
{
    int m_iWordAt00;
    void UpdateState_00c7b130();
};

// @fnv 0x00c7b130
// src: GUESS 0x00c7b130 (confidence: low)
void FUN_00c7b130_cls::UpdateState_00c7b130()
{
    int value = m_iWordAt00;
    hkMemoryRouter* slot = hkMemoryRouter_getInstance();
    slot->m_stack.m_next.m_storage = reinterpret_cast<void*>(value);
}
}  // namespace fnv_00c7b130

struct NiRTTI;

extern const NiRTTI g_C7B140CollisionRTTI;
extern const NiRTTI g_C7B140FilterRTTI;
extern const NiRTTI g_C7B140BodyRTTI;
extern const NiRTTI g_C7B140NodeRTTI;

struct C7B140Object
{
    C7B140Object* DynamicCast(const NiRTTI* pkRTTI);
};

struct C7B140Collision : C7B140Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C7B140Object* m_pkWorldObject;
};

struct C7B140AVObject : C7B140Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C7B140Object* m_spCollisionObject;
};

void __cdecl CollectItemValues(C7B140Object* pkBody, void* pArg1, void* pArg2);

// Recursively visits the object's collision body (skipping filter collisions) and calls CollectItemValues on it, then recurses into child nodes.
// @fnv 0x00c7b140
void __cdecl ApplyToCollisionBodies(C7B140AVObject* pkObject, void* pArg1, void* pArg2)
{
    if (!pkObject)
        return;
    if (pkObject->m_spCollisionObject)
    {
        C7B140Collision* pkCollision =
            (C7B140Collision*)pkObject->m_spCollisionObject->DynamicCast(&g_C7B140CollisionRTTI);
        if (pkCollision)
        {
            C7B140Object* pkFilter = pkCollision->DynamicCast(&g_C7B140FilterRTTI);
            if (pkCollision->m_pkWorldObject)
            {
                C7B140Object* pkBody = pkCollision->m_pkWorldObject->DynamicCast(&g_C7B140BodyRTTI);
                if (pkBody && !pkFilter)
                    CollectItemValues(pkBody, pArg1, pArg2);
            }
        }
    }
    NiNode* pkNode = (NiNode*)pkObject->DynamicCast(&g_C7B140NodeRTTI);
    if (pkNode)
    {
        for (unsigned int i = 0; i < pkNode->m_kChildren.m_usSize; i++)
            ApplyToCollisionBodies(reinterpret_cast<C7B140AVObject*>(pkNode->m_kChildren.m_pBase[i].m_pObject), pArg1, pArg2);
    }
}

hkMemoryRouter* GetAllocHolder() throw();
namespace fnv_00c7bf50 {
struct SpawnedAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* p, unsigned int size);
};

struct FUN_00c7bf50_cls
{
    void* m_pData;
    int m_04;
    unsigned int m_08;

    void UpdateState_00c7bf50();
};

// @fnv 0x00c7bf50
// src: GUESS 0x00c7bf50 (confidence: low)
void FUN_00c7bf50_cls::UpdateState_00c7bf50()
{
    hkMemoryRouter* holder = ::GetAllocHolder();
    SpawnedAllocator* alloc = reinterpret_cast<SpawnedAllocator*>(holder->m_heap);
    unsigned int flags = m_08;
    m_04 = 0;
    if ((flags & 0x80000000u) == 0)
    {
        alloc->Free(m_pData, (flags & 0x3fffffffu) * 2);
    }
    m_pData = 0;
    m_08 = 0x80000000u;
}
}  // namespace fnv_00c7bf50

namespace fnv_00c7bf90 {
struct SpawnedAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* p, unsigned int size);
};

struct FUN_00c7bf90_cls
{
    void* m_pData;
    int m_04;
    unsigned int m_08;

    void ReleaseBuffer();
};

// @fnv 0x00c7bf90
void FUN_00c7bf90_cls::ReleaseBuffer()
{
    hkMemoryRouter* holder = ::GetAllocHolder();
    SpawnedAllocator* alloc = reinterpret_cast<SpawnedAllocator*>(holder->m_heap);
    unsigned int flags = m_08;
    m_04 = 0;
    if ((flags & 0x80000000u) == 0)
    {
        alloc->Free(m_pData, (flags & 0x3fffffffu) * 48);
    }
    m_pData = 0;
    m_08 = 0x80000000u;
}
}  // namespace fnv_00c7bf90

namespace fnv_00c7fc40 {
struct FNVHeapAllocator
{
    void* FUN_00aa4150(void* address, unsigned int bytes);
};
extern FNVHeapAllocator DAT_011f6238;

// @fnv 0x00c7fc40
void* __stdcall AllocateDoubleArray(void* address, unsigned int elementCount)
{
    return DAT_011f6238.FUN_00aa4150(address, elementCount * sizeof(double));
}
}  // namespace fnv_00c7fc40

struct FUN_00c7fc60_cls
{
    virtual void* Slot0();
    virtual void* Alloc(unsigned int count);
    int* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    void Grow(unsigned int newCap, unsigned int oldSize);
    unsigned int PushSlot();
};

// Ensures capacity by allocating or growing the buffer, then increments iSize and returns the index of the newly added slot.
// @fnv 0x00c7fc60
unsigned int FUN_00c7fc60_cls::PushSlot()
{
    if (iSize == SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = (int*)Alloc(4);
            SimpleArrayStorage = 4;
            goto tail;
        }
        unsigned int newCap = (SimpleArrayStorage > 0x400) ? SimpleArrayStorage + 0x400 : SimpleArrayStorage * 2;
        Grow(newCap, iSize);
        SimpleArrayStorage = newCap;
    }
tail:
    ++iSize;
    return iSize - 1;
}

extern float DAT_011afe68;
extern float DAT_011afe64;
extern float DAT_011afe6c;
extern float DAT_011afe70;
extern float DAT_012677b0;
extern float DAT_012677ac;
extern unsigned int DAT_012677b4;
extern unsigned int DAT_012677b8;
extern bool DAT_01267b4c;
extern float DAT_01267b38;
extern float DAT_011ac3a0;
struct SettingFloat
{
    float* Float();
};
extern SettingFloat DAT_01267b34;
float __cdecl BSMIN(float, float);

// Accumulates elapsed time, clamps it, and computes the number of simulation steps and step size according to the current time mode.
// @fnv 0x00c66760
// src: COMMUNITY 0x00c66760
void __cdecl bhkWorld_SetDeltaTime(float elapsed, bool singleStep, bool force)
{
    DAT_011afe68 = elapsed;
    bool forced = force || DAT_01267b4c;
    DAT_011afe64 = elapsed + DAT_012677b0;
    if (DAT_011afe64 > 166.6666717529296875f)
        DAT_011afe64 = 166.6666717529296875f;
    if (DAT_011afe64 <= 0.0f)
    {
        DAT_012677b4 = 0;
        DAT_012677ac = 0.0f;
        return;
    }
    unsigned int maxSteps = singleStep ? 1 : 3;
    switch (DAT_012677b8)
    {
    case 10:
        DAT_011afe6c += (DAT_011afe64 - DAT_011afe6c) * DAT_011afe70;
        DAT_012677ac = DAT_011afe6c;
        DAT_012677b4 = 1;
        DAT_012677b0 = 0.0f;
        break;
    case 0:
        DAT_012677ac = DAT_011ac3a0 * DAT_01267b38;
        DAT_012677b4 = (unsigned int)(DAT_011afe64 / DAT_012677ac);
        if (DAT_012677b4 > maxSteps)
            DAT_012677b4 = maxSteps;
        if (DAT_012677b4)
        {
            DAT_012677b0 = DAT_011afe64 - DAT_012677b4 * DAT_012677ac;
            DAT_011afe64 -= DAT_012677b0;
            DAT_012677b0 = BSMIN(DAT_012677b0, *DAT_01267b34.Float());
        }
        else if (!forced && DAT_011afe64 < DAT_012677ac * 0.5)
        {
            DAT_012677b0 = DAT_011afe64;
            DAT_012677ac = DAT_011afe64 = 0.0f;
        }
        else
        {
            DAT_012677ac = DAT_011afe64;
            DAT_012677b4 = 1;
            DAT_012677b0 = 0.0f;
        }
        break;
    case 2:
        DAT_012677b4 = 1;
        DAT_012677ac = elapsed;
        break;
    case 1:
    adaptive:
        if (!forced && DAT_011afe64 < 0.008333333767950534820556640625f)
        {
            DAT_012677b4 = 0;
            DAT_012677b0 = DAT_011afe64;
            DAT_012677ac = DAT_011afe64 = 0.0f;
        }
        else
        {
            DAT_012677b0 = 0.0f;
            DAT_012677b4 = (unsigned int)(DAT_011afe64 / DAT_01267b38);
            if (DAT_012677b4 > maxSteps)
                DAT_012677b4 = maxSteps;
            if (DAT_012677b4 == 0)
            {
                DAT_012677b4 = 1;
                DAT_012677ac = DAT_011afe64;
            }
            else
            {
                DAT_012677ac = DAT_011afe64 / DAT_012677b4;
            }
        }
        break;
    default:
        goto adaptive;
    }
}

struct Allocator
{
    virtual void v00();
    virtual void* Allocate(unsigned int n);
};

hkMemoryRouter* GetAllocHolder() throw();

struct hkBoolArg
{
    char m_cBooleanValue;
    hkBoolArg(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct OwnerA
{
    virtual void a00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
};
struct OwnerB
{
    virtual void b00();
};
struct Owner : OwnerA, OwnerB
{
};

struct WorldEntry
{
    int unk00;
};
extern WorldEntry* DAT_012677a8;

struct ChildBase
{
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    ChildBase(Owner* owner, int id);
    virtual ~ChildBase();
    void removeReference();
    void Attach(WorldEntry* w, hkBoolArg b, int a, int c);
    static void* operator new(unsigned int n)
    {
        ChildBase* p = (ChildBase*)(&GetAllocHolder()->heap())->blockAlloc(n);
        p->m_usMemSizeAndFlags = (unsigned short)n;
        return p;
    }
    static void operator delete(void* p, unsigned int n);
};

struct Child : ChildBase
{
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    void* m_350;
    int unk354;
    int unk358;
    int unk35C;
    Child(Owner* owner, int id) : ChildBase(owner, id)
    {
        m_350 = 0;
    }
    virtual ~Child();
};

struct SimObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    void* m_80;
};
void __cdecl NotifySim(void* p);

struct Controller
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void AddChild(Child* c);
    virtual void v90();
    virtual SimObject* GetSim();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void SetOwner(OwnerB* p);
    void CreateChildAndNotifySim(OwnerB* p);
};

// @fnv 0x00c66c90
void Controller::CreateChildAndNotifySim(OwnerB* p)
{
    ThreadMemoryScope scope;
    Owner* owner = static_cast<Owner*>(p);
    Child* child = new Child(owner, 0x111d4);
    if (DAT_012677a8)
        child->Attach(DAT_012677a8, true, 0, 1);
    AddChild(child);
    child->removeReference();
    SetOwner(p);
    SimObject* sim = GetSim();
    if (sim)
        NotifySim(sim->m_80);
}

struct BC66F10FilterBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiFilterInfo;
};

struct BC66F10Pad
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct BC66F10WorldObject : public BC66F10Pad, public BC66F10FilterBase
{
};

class BC66F10RefObject
{
  public:
    void SetSystemGroup(unsigned int uiRenderPassIndex);

    int unk00;
    int unk04;
    BC66F10WorldObject* m_pkWorldObject;
};

struct BC66F10Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_uiSystemGroup;
};

extern unsigned int g_auiC66F10LayerGroups[];
extern unsigned int g_uiC66F10NextGroup;

// Resolves a system group from the object's filter info or the entry's group, stores it on the entry and applies it via SetSystemGroup.
// @fnv 0x00c66f10
bool __cdecl AssignSystemGroup(BC66F10RefObject* pkObject, BC66F10Entry* pkEntry)
{
    bool bAssigned = false;
    BC66F10FilterBase* pkFilter = pkObject->m_pkWorldObject;
    unsigned int uiFilterInfo = pkFilter ? pkFilter->m_uiFilterInfo : 0;
    unsigned int uiRenderPassIndex = uiFilterInfo >> 16;
    if (pkEntry->m_uiSystemGroup == 0)
    {
        if (uiRenderPassIndex == 0)
        {
            uiRenderPassIndex = g_auiC66F10LayerGroups[uiFilterInfo & 0x7f];
            if (uiRenderPassIndex == 0)
            {
                g_uiC66F10NextGroup = (g_uiC66F10NextGroup + 1) & 0xffff;
                if (g_uiC66F10NextGroup == 0)
                    g_uiC66F10NextGroup = 10;
                uiRenderPassIndex = g_uiC66F10NextGroup;
            }
            bAssigned = true;
        }
        pkEntry->m_uiSystemGroup = uiRenderPassIndex;
    }
    else
    {
        bAssigned = true;
    }
    if (bAssigned)
        pkObject->SetSystemGroup(pkEntry->m_uiSystemGroup);
    return bAssigned;
}

__declspec(thread) int g_tlsMemContext_00c67850 = 0x3b;

struct ScopedMemContext_00c67850
{
    int m_old;
    ScopedMemContext_00c67850(int val)
    {
        m_old = g_tlsMemContext_00c67850;
        g_tlsMemContext_00c67850 = val;
    }
    ~ScopedMemContext_00c67850()
    {
        g_tlsMemContext_00c67850 = m_old;
    }
};

struct EntityWithCC
{
    int unk00[51];
    int m_cc;
};

struct ConstraintItem : public hkReferencedObject
{
    int m_08;
    int unk0c;
    int unk10;
    EntityWithCC* m_14;
    EntityWithCC* m_18;
};

extern "C" void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);

struct WorldImpl : public FUN_00c6b320_Base
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    ConstraintItem** m_ppData;
    unsigned int m_uiItemCount;

    ConstraintItem*& GetAt(unsigned int i)
    {
        return m_ppData[i];
    }
};

// @fnv 0x00c67850
void FUN_00c67850_Class::ProcessConstraints()
{
    WorldImpl* self = (WorldImpl*)this;
    ScopedMemContext_00c67850 ctx(16);
    if (self->m_uiItemCount > 0 && self->m_30 == 0)
    {
        if (self->m_uiItemCount >= 200)
        {
            self->m_uiItemCount = 200;
        }
        FUN_00c97d30_Class* pWorld = (FUN_00c97d30_Class*)self->v37();
        if (pWorld)
        {
            for (unsigned int i = 0; i < self->m_uiItemCount; ++i)
            {
                if (self->GetAt(i))
                {
                    ConstraintItem* item = self->GetAt(i);
                    if (item->m_08 == 0 && (!item->m_14 || item->m_14->m_cc != 0) &&
                        (!item->m_18 || item->m_18->m_cc != 0))
                    {
                        pWorld->hkpWorld_addConstraint(item);
                    }
                }
                if (self->GetAt(i))
                {
                    self->GetAt(i)->removeReference();
                }
            }
            _fnv_zlib_memset(self->m_ppData, 0, self->m_uiItemCount * 4);
            self->m_uiItemCount = 0;
        }
    }
}

extern __declspec(thread) int g_C687B0AllocTag;

struct C687B0AllocTagScope
{
    int m_iSaved;

    C687B0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_C687B0AllocTag;
        g_C687B0AllocTag = aiAllocationTag;
    }
    ~C687B0AllocTagScope()
    {
        g_C687B0AllocTag = m_iSaved;
    }
};

class C687B0ObjectBase
{
  public:
    virtual ~C687B0ObjectBase();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
};

class C687B0Listener
{
};

class C687B0Object : public C687B0ObjectBase, public C687B0Listener
{
  public:
    C687B0Object();

    static void* operator new(unsigned int uiSize)
    {
        void* p = GetRouterHeap(hkMemoryRouter::getInstance()).blockAlloc(uiSize);
        static_cast<C687B0Object*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);
};

struct C687B0World
{
    void hkpWorld_getCinfo(C687B0Object* pkObject);
};

class C687B0Owner
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual C687B0World* GetWorld();

    int unk04;
    void* m_pkActive;
    C687B0Listener* m_pkListener;

    C687B0Listener* GetOrCreateListener(bool* pbCreated);
};

// @fnv 0x00c687b0
C687B0Listener* C687B0Owner::GetOrCreateListener(bool* pbCreated)
{
    C687B0AllocTagScope kScope(0x10);
    *pbCreated = (m_pkListener == 0);
    if (*pbCreated)
    {
        m_pkListener = new C687B0Object();
        if (m_pkActive)
        {
            C687B0Object* pkObject = static_cast<C687B0Object*>(m_pkListener);
            C687B0World* pkWorld = GetWorld();
            if (pkWorld)
                pkWorld->hkpWorld_getCinfo(pkObject);
        }
    }
    return m_pkListener;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plAddend);

class CC68B50Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};

extern CC68B50Heap g_kC68B50Heap;

class CC68B50Object
{
  public:
    virtual ~CC68B50Object();

    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }

    volatile long m_lRefCount;
};

template <> NiPointer<CC68B50Object>::~NiPointer();
template <> NiPointer<CC68B50Object>& NiPointer<CC68B50Object>::operator=(const NiPointer& kOther);

struct CC68B50Node
{
    static void* operator new(unsigned int uiSize)
    {
        return g_kC68B50Heap.Allocate(uiSize);
    }
    static void operator delete(void* pvMem);

    CC68B50Node(const NiPointer<CC68B50Object>& spRetainedObject) throw() : m_pReferencedObject(spRetainedObject), m_pkNext(0)
    {}

    NiPointer<CC68B50Object> m_pReferencedObject;
    CC68B50Node* m_pkNext;
};

class CC68B50Stack
{
  public:
    NiPointer<CC68B50Object> m_spTop;
    CC68B50Node* m_pkNext;

    void Push(const NiPointer<CC68B50Object>& spRetainedObject);
};

// @fnv 0x00c68b50
void CC68B50Stack::Push(const NiPointer<CC68B50Object>& apObject)
{
    if (apObject)
    {
        if (m_spTop)
        {
            CC68B50Node* pkNode = new CC68B50Node(m_spTop);
            pkNode->m_pkNext = m_pkNext;
            m_pkNext = pkNode;
            m_spTop = apObject;
        }
        else
        {
            m_spTop = apObject;
        }
    }
}

struct C68CB0Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned char m_ucFlags;
};

class C68CB0Phantom
{
  public:
    void RetainReference();

    int unk00;
    int unk04;
    int unk08;
    C68CB0Collidable* m_pkCollidable;
};

struct C68CB0Result
{
    C68CB0Result(const C68CB0Result& kOther);

    int m_iValue;
};

class C68CB0HavokWorld
{
  public:
    C68CB0Phantom* RegisterPhantom(C68CB0Phantom* pkPhantom);
};

class C68CB0World
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual C68CB0HavokWorld* GetHavokWorld();

    void FlushPendingEntities();
    void FlushPendingActions();
    void FlushPendingConstraints();
    void FlushPendingPhantoms();

    bool bhkWorld_Remove_00c68cb0(C68CB0Phantom* pkPhantom);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiBatchLock;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    C68CB0Phantom** m_ppkPendingPhantoms;
    unsigned int m_uiNumPendingPhantoms;
};

// @fnv 0x00c68cb0
// src: XBOX_PDB 0x00c68cb0
bool C68CB0World::bhkWorld_Remove_00c68cb0(C68CB0Phantom* pkPhantom)
{
    bool bResult = false;
    C68CB0HavokWorld* pkWorld = GetHavokWorld();
    if (pkWorld && pkPhantom)
    {
        bResult = true;
        if (m_uiBatchLock > 0)
        {
            C68CB0Collidable* pkCollidable = pkPhantom->m_pkCollidable;
            if (pkCollidable && !(pkCollidable->m_ucFlags & 0x30))
            {
                pkCollidable->m_ucFlags |= 0x20;
                if (m_uiNumPendingPhantoms >= 200)
                {
                    FlushPendingEntities();
                    FlushPendingActions();
                    FlushPendingConstraints();
                    FlushPendingPhantoms();
                }
                pkPhantom->RetainReference();
                m_ppkPendingPhantoms[m_uiNumPendingPhantoms++] = pkPhantom;
                return bResult;
            }
        }
        else
        {
            C68CB0Collidable* pkCollidable = pkPhantom->m_pkCollidable;
            if (pkCollidable && !(pkCollidable->m_ucFlags & 0x30))
                pkWorld->RegisterPhantom(pkPhantom);
        }
    }
    return bResult;
}

class C68D50Entity
{
  public:
    void RetainReference();
};

struct C68D50Result
{
    C68D50Result(const C68D50Result& kOther);

    int m_iValue;
};

class C68D50HavokWorld
{
  public:
    C68D50Result RegisterEntity(C68D50Entity* pkEntity);
};

class C68D50World
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual C68D50HavokWorld* GetHavokWorld();

    void FlushPendingEntities();
    void FlushPendingActions();
    void FlushPendingConstraints();
    void FlushPendingPhantoms();

    bool bhkWorld_Remove_00c68d50(C68D50Entity* pkEntity);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiBatchLock;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    C68D50Entity** m_ppkPendingEntities;
    unsigned int m_uiNumPendingEntities;
};

// @fnv 0x00c68d50
// src: XBOX_PDB 0x00c68d50
bool C68D50World::bhkWorld_Remove_00c68d50(C68D50Entity* pkEntity)
{
    bool bResult = false;
    C68D50HavokWorld* pkWorld = GetHavokWorld();
    if (pkWorld && pkEntity)
    {
        if (m_uiBatchLock > 0)
        {
            if (m_uiNumPendingEntities >= 200)
            {
                FlushPendingEntities();
                FlushPendingActions();
                FlushPendingConstraints();
                FlushPendingPhantoms();
            }
            pkEntity->RetainReference();
            m_ppkPendingEntities[m_uiNumPendingEntities++] = pkEntity;
        }
        else
        {
            pkWorld->RegisterEntity(pkEntity);
        }
        bResult = true;
    }
    return bResult;
}

static inline void AppendReportString(StrArr* array, char* value)
{
    unsigned int index = array->m_usSize;
    if (index >= array->m_usMaxSize)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, value);
}
extern const char* const g_012681e8_arg1;
extern unsigned int DAT_012677a4;
extern unsigned int DAT_01268154;
extern int DAT_01268188;
extern "C" unsigned int DAT_012681fc;
extern unsigned int DAT_012681bc;
extern int DAT_012680f8;
extern int DAT_01268238;
extern unsigned int DAT_01268654;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
struct ReportBool
{
    bool value;
    ReportBool(bool b) : value(b)
    {}
};
char* __cdecl NiGetViewerString(const char*, ReportBool);
char* __cdecl NiGetViewerString_00a7d510(const char*, unsigned int);
struct ReportOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* debug;
    unsigned char unk14;
    bool enabled;
    void bhkSerializable_GetViewerStrings(StrArr*);
    void AppendReport(StrArr*);
};
// @fnv 0x00c69240
void ReportOwner::AppendReport(StrArr* result)
{
    ThreadMemoryScope scope;
    bhkSerializable_GetViewerStrings(result);
    AppendReportString(result, NiViewerStrings_NiGetViewerString_Title(g_012681e8_arg1));
    ReportBool enabledValue(enabled);
    AppendReportString(result, NiGetViewerString("Enabled", enabledValue));
    ReportBool debugValue(debug != 0);
    AppendReportString(result, NiGetViewerString("Vis Debug", debugValue));
    AppendReportString(result, NiGetViewerString_00a7d510("Worlds", DAT_012677a4));
    AppendReportString(result, NiGetViewerString_00a7d510("Actions", DAT_01268154));
    AppendReportString(result, NiGetViewerString_00a7d510("Contraints", DAT_01268188));
    AppendReportString(result, NiGetViewerString_00a7d510("Entities", DAT_012681fc));
    AppendReportString(result, NiGetViewerString_00a7d510("RigidBodies", DAT_012681bc));
    AppendReportString(result, NiGetViewerString_00a7d510("Shapes", DAT_012680f8));
    AppendReportString(result, NiGetViewerString_00a7d510("Phantoms", DAT_01268238));
    AppendReportString(result, NiGetViewerString_00a7d510("MoppBVTreeShapes", DAT_01268654));
}

struct CollisionObjectCountContext
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    float fValue;
    int unk;
    int unkCur;
    int unkValue;
};

typedef void (*CollisionObjectCountCallback)(NiCollisionObject*, CollisionObjectCountContext*);
void bhkWorld_DoObjectRec(NiAVObject* pkObject, CollisionObjectCountContext* pkContext,
                  CollisionObjectCountCallback pfnCallback);
extern CollisionObjectCountCallback DAT_011afec8;

// If pkObject is non-null and enabled (or bForce), fills a context with fValue and traversal flags and runs the collision-object callback over it.
// @fnv 0x00c6a190
bool ApplyCollisionObjectCount(NiAVObject* pkObject, float fValue, bool bRecurse, bool bForce)
{
    bool bResult = false;
    if (pkObject && (bForce || C6A2E0IsEnabled((C6A2E0AVObject*)pkObject)))
    {
        CollisionObjectCountContext kContext;
        bResult = true;
        kContext.pCurrentObject = 0;
        kContext.bRecurse = bRecurse;
        kContext.uiTraversalFlags = 0x10;
        kContext.fValue = fValue;
        if (DAT_011afec8)
            bhkWorld_DoObjectRec(pkObject, &kContext, DAT_011afec8);
    }
    return bResult;
}

#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTPrimitiveArray.h"
// Gamebryo NiTArray.inl: the original inlines Add (with SetAtGrow) and calls SetSize / SetAt out of line
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    T value = element;
    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, value);
    return uiIndex;
}
typedef NiTPrimitiveArray<char*> ViewerStrings;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString(const char*, bool);
char* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);
int __cdecl BSsprintf(char*, int, const char*, ...);

struct ViewerSceneObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    float m_vScale;
};
class ViewerCollision
{
  public:
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual bool IsKeyframed();
    unsigned int m_iObjectReferenceCount;
    ViewerSceneObject* m_sceneObject;
    unsigned short m_flags;
    void* m_pEntity;
    void WriteToStream(ViewerStrings* strings);
    bool GetActive() const
    {
        return (m_flags & 1) != 0;
    }
    bool GetReset() const
    {
        return (m_flags & 64) != 0;
    }
    bool GetNotify() const
    {
        return (m_flags & 4) != 0;
    }
    bool GetSetLocal() const
    {
        return (m_flags & 8) != 0;
    }
    bool GetFaceDown() const
    {
        bool faceDown = false;
        if (m_sceneObject)
            faceDown = m_sceneObject->m_vScale < 0.0f;
        return faceDown;
    }
    void AppendDebugInfo(ViewerStrings* strings);
};
// Appends collision debug strings: base info, bhkWorldObject pointer, and the active/reset/notify/setlocal/keyframe/facedown flags.
// @fnv 0x00c6c430
void ViewerCollision::AppendDebugInfo(ViewerStrings* strings)
{
    ThreadMemoryScope memoryScope;
    WriteToStream(strings);
    strings->Add(NiViewerStrings_NiGetViewerString_Title(reinterpret_cast<const char*>(DAT_01267b70)));
    char buffer[32];
    BSsprintf(buffer, 32, "0x%8X", m_pEntity);
    strings->Add(NiGetViewerString_00a7d5e0("bhkWorldObject", buffer));
    strings->Add(NiGetViewerString("bActive", GetActive()));
    strings->Add(NiGetViewerString("bReset", GetReset()));
    strings->Add(NiGetViewerString("bNotify", GetNotify()));
    strings->Add(NiGetViewerString("bSetLocal", GetSetLocal()));
    strings->Add(NiGetViewerString("bKeyframe", IsKeyframed()));
    strings->Add(NiGetViewerString("bFaceDown", GetFaceDown()));
}

// Whether the world's constraint list contains an entry for the given object (checked under the world lock).

struct D8A0Entry
{
    void* m_pvObject;
    int unk04;
    int unk08;
    int unk0C;
};

struct D8A0World
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    D8A0Entry* m_pkEntryArray;
    int m_iArrayLength;

    bool Contains(void* pvObject) const
    {
        for (int i = 0; i < m_iArrayLength; i++)
        {
            if (m_pkEntryArray[i].m_pvObject == pvObject)
                return true;
        }
        return false;
    }
};

class D8A0Wrapper
{
  public:
    int unk00;
    int unk04;
    D8A0World* m_pkWorld;

    void ToggleLock();
    bool ContainsObject(void* pvObject);
};

// Locks the wrapper, checks whether m_pkWorld contains pvObject, unlocks, and returns whether it was found.
// @fnv 0x00c6d8a0
bool D8A0Wrapper::ContainsObject(void* pvObject)
{
    D8A0World* pkWorld = m_pkWorld;
    bool bFound = false;
    if (pkWorld)
    {
        ToggleLock();
        bFound = pkWorld->Contains(pvObject);
        ToggleLock();
    }
    return bFound;
}

extern __declspec(thread) int g_iC6DF60AllocTag;

struct BC6DF60AllocTagScope
{
    int m_iSaved;

    BC6DF60AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC6DF60AllocTag;
        g_iC6DF60AllocTag = aiAllocationTag;
    }
    ~BC6DF60AllocTagScope()
    {
        g_iC6DF60AllocTag = m_iSaved;
    }
};

hkMemoryRouter* BC6DF60GetRouter();

class BC6DF60Phantom
{
  public:
    void* operator new(unsigned int uiNumBytes) throw()
    {
        return GetRouterHeap(*BC6DF60GetRouter()).blockAlloc(uiNumBytes);
    }
    void operator delete(void* pvMem)
    {
        GetRouterHeap(*BC6DF60GetRouter()).blockFree(pvMem, sizeof(BC6DF60Phantom));
    }

    BC6DF60Phantom(bool bFlag);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
};

class BC6DF60Wrapper
{
  public:
    void LinkPhantom(BC6DF60Phantom* pkPhantom);
    BC6DF60Phantom* GetOrCreatePhantom(bool* pbCreated);

    int unk00;
    int unk04;
    void* m_pkWorld;
    BC6DF60Phantom* m_pkPhantom;
};

// Returns m_pkPhantom, creating it and linking it to m_pkWorld when absent, and stores whether it was created in *pbCreated.
// @fnv 0x00c6df60
BC6DF60Phantom* BC6DF60Wrapper::GetOrCreatePhantom(bool* pbCreated)
{
    BC6DF60AllocTagScope kScope(0x10);
    bool bCreate = m_pkPhantom == 0;
    *pbCreated = bCreate;
    if (bCreate)
    {
        m_pkPhantom = new BC6DF60Phantom(true);
        if (m_pkWorld)
            LinkPhantom(m_pkPhantom);
    }
    return m_pkPhantom;
}

// Apply the current water settings: scaled shader parameters and the quarter-size reflection dimensions.

extern double g_dC75910SpeedScale;
extern double g_dC75910DepthScale;

struct C75910Settings
{
    int unk00;
    int unk04;
    int unk08;
    float m_fAmplitude;
    float m_fEmissionSpeed;
    int unk14;
    float m_fFogDepth;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;
};

struct C75910Source
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    C75910Settings* m_pkSettings;
};

struct C75910ShaderParams
{
    int unk00;
    int unk04;
    int unk08;
    float m_fEmissionSpeed;
    float m_fAmplitude;
    int unk14;
    int unk18;
    float m_fFogDepth;
};

class C75910Water
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    C75910ShaderParams** m_ppkParams;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    unsigned int m_uiReflectHeight;
    unsigned int m_uiReflectWidth;
    int unk2A0;
    C75910Source* m_pkSource;

    void UpdateShaderParams();
};

// Copies scaled settings from m_pkSource->m_pkSettings into the shader params and computes reflection width/height as a quarter of the settings values.
// @fnv 0x00c75910
void C75910Water::UpdateShaderParams()
{
    if (!m_pkSource->m_pkSettings)
        return;

    C75910ShaderParams* pkParams = *m_ppkParams;
    pkParams->m_fEmissionSpeed = (float)(m_pkSource->m_pkSettings->m_fEmissionSpeed * g_dC75910SpeedScale);
    pkParams->m_fAmplitude = (float)(m_pkSource->m_pkSettings->m_fAmplitude * 0.10000000149011612);
    pkParams->m_fFogDepth = (float)(m_pkSource->m_pkSettings->m_fFogDepth * g_dC75910DepthScale);
    m_uiReflectWidth = (unsigned int)((float)m_pkSource->m_pkSettings->m_uiImageWidth * 0.25);
    m_uiReflectHeight = (unsigned int)((float)m_pkSource->m_pkSettings->m_uiImageHeight * 0.25);
}

// @fnv 0x00c75d90
template <> NiTMap<const char*, NiPointer<bhkPoseArray> >::~NiTMap()
{
    RemoveAll();
}

inline void* operator new(unsigned int, void* pvMem)
{
    return pvMem;
}
inline void operator delete(void*, void*)
{}

class MemberC76
{
  public:
    MemberC76();
    ~MemberC76();

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30;
};

class ElementC76
{
  public:
    ElementC76() : m_iValue(0)
    {}

    int m_iValue;
    MemberC76 m_kMember;
};

// @fnv 0x00c760f0
void __stdcall ConstructElementArray(ElementC76* pkArray, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkArray[i]) ElementC76;
}

class NiRTTI;
extern const char g_01267e64_arg1[];
struct FilterInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned int flags;
};
struct PhysicsWorldObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FilterInfo collidable;
};
struct PhysicsBody
{
    int unk00;
    int unk04;
    PhysicsWorldObject* world;
    FilterInfo* GetCollidable()
    {
        return world ? &world->collidable : 0;
    }
};

struct SearchObject
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual NiNode* GetNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    NiObject* collision;
};
// Recursively searches object and its child nodes for a PhysicsBody whose collidable layer field equals layer, returning it or null.
// @fnv 0x00c7ff40
PhysicsBody* __cdecl FindPhysicsBodyByLayer(SearchObject* object, unsigned int layer)
{
    PhysicsBody* result = 0;
    if (object)
    {
        if (object->collision)
        {
            NiObject* collision = object->collision->DynamicCast((const NiRTTI*)g_01267e64_arg1);
            if (collision)
            {
                PhysicsBody* body = *reinterpret_cast<PhysicsBody**>(reinterpret_cast<char*>(collision) + 0x10);
                if (body)
                {
                    FilterInfo* collidable = body->GetCollidable();
                    unsigned int flags = collidable ? collidable->flags : 0;
                    if (((flags >> 8) & 31) == layer)
                        return body;
                }
            }
        }
        NiNode* node = object->GetNode();
        if (node)
        {
            unsigned int i = 0;
            while (!result)
            {
                if (i >= node->m_kChildren.m_usSize)
                    break;
                SearchObject* child = reinterpret_cast<SearchObject*>(node->m_kChildren.m_pBase[i].m_pObject);
                result = FindPhysicsBodyByLayer(child, layer);
                ++i;
            }
        }
    }
    return result;
}

extern char DAT_012677a1;
extern CollisionObjectCountCallback DAT_011afeb0;
extern CollisionObjectCountCallback DAT_011afe88;
struct S_00c69e10_Obj
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
struct S_00c69e10_Ctx
{
    void* owner;
    bool kind;
    int type;
    int flag;
    int value;
    int unk14;
    int one;
};
static inline unsigned int C69E10IsEnabled(S_00c69e10_Obj* o)
{
    C6A2E0Properties* info = GetExtraDataChecked((C6A2E0AVObject*)o);
    return info ? (info->m_uiValue1 & 2) : 0;
}
struct S_00c69e10_This
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    char unk14;
    bool SetCollisionObjectFlag(S_00c69e10_Obj* obj, bool kind, bool f, int value, bool force);
};
// If obj is non-null and enabled (or force is set), builds a context from kind, f and value and dispatches it through the collision-object callbacks.
// @fnv 0x00c69e10
bool S_00c69e10_This::SetCollisionObjectFlag(S_00c69e10_Obj* obj, bool kind, bool abFlag, int value, bool force)
{
    bool ret = false;
    if (obj != 0)
    {
        bool ok = force;
        if (!ok)
        {
            if (C69E10IsEnabled(obj) != 0)
                ok = true;
        }
        if (ok)
        {
            S_00c69e10_Ctx r;
            unk14 = 1;
            r.owner = this;
            r.kind = kind;
            if (DAT_012677a1)
            {
                r.type = 10;
                if (DAT_011afeb0)
                    bhkWorld_DoObjectRec((NiAVObject*)obj, (CollisionObjectCountContext*)&r, DAT_011afeb0);
            }
            int fl = abFlag != 0;
            if (obj->unk1c == 0)
                fl = 0;
            r.flag = fl;
            r.type = 0;
            r.value = value;
            r.unk14 = 0;
            r.one = 1;
            if (DAT_011afe88)
                bhkWorld_DoObjectRec((NiAVObject*)obj, (CollisionObjectCountContext*)&r, DAT_011afe88);
            ret = true;
        }
    }
    return ret;
}

struct S_c6c1d0_Target
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char m_type;
};

struct S_c6c1d0_Link
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_offset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    unsigned char m_kind;
};

struct S_c6c1d0_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_c6c1d0_Link m_link;
};

struct S_c6c1d0_Holder
{
    int unk00;
    int unk04;
    S_c6c1d0_Node* m_node;
};

struct S_c6c1d0_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_c6c1d0_Holder* m_holder;

    __forceinline static S_c6c1d0_Target* FindTarget(S_c6c1d0_Holder* holder)
    {
        S_c6c1d0_Node* node = holder->m_node;
        S_c6c1d0_Link* link = 0;
        if (node != 0)
            link = &node->m_link;
        if (link->m_kind != 1)
            return 0;
        return (S_c6c1d0_Target*)((char*)link + link->m_offset);
    }

    bool bhkNiCollisionObject_QKeyframe();
};

// Finds the target via m_holder and returns true when its m_type is 4 or 5, otherwise false (true when no target).
// @fnv 0x00c6c1d0
// src: XBOX_PDB 0x00c6c1d0
bool S_c6c1d0_Cls::bhkNiCollisionObject_QKeyframe()
{
    bool result = true;
    S_c6c1d0_Target* target = this->m_holder ? FindTarget(this->m_holder) : 0;
    if (target)
    {
        unsigned int type = target->m_type;
        if (type == 4 || type == 5)
            result = true;
        else
            result = false;
    }
    return result;
}

struct Group148;
struct Scene148
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Group148* AsGroup();
    int unk04;
    char* name;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    Group148* FUN_00653290(const void* rtti);
};
struct Group148 : Scene148
{
    Scene148** children;
    unsigned short capacity, count;
};
struct Container148
{
    Scene148* bhkWorldObject_GetAVObject(int);
};
extern int DAT_011f4428;
extern const char DAT_010c43d8[];
extern char* DAT_0109b220;
char* FUN_00a5b690(const char*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct FUN_00c6e0b0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    Container148* m_594;

    void* __thiscall bhkCharacterController_GetCollisionDebugNode();
};

// @fnv 0x00c6e0b0
// src: COMMUNITY 0x00c6e0b0
void* FUN_00c6e0b0_Class::bhkCharacterController_GetCollisionDebugNode()
{
    Scene148* result = 0;
    if (unk414 & 0x8000)
    {
        if (m_594)
        {
            Scene148* object = m_594->bhkWorldObject_GetAVObject(0);
            if (object)
            {
                Group148* group = object->AsGroup();
                if (group && group->count > 0)
                {
                    Scene148* child = group->children[0];
                    if (child)
                    {
                        Group148* cast = child->FUN_00653290(&DAT_011f4428);
                        if (cast)
                        {
                            char* text = FUN_00a5b690(DAT_010c43d8);
                            unsigned int count = cast->count;
                            unsigned int index = 0;
                            while (index < count && !result)
                            {
                                Scene148* entry = cast->children[index];
                                if (entry && entry->name == text)
                                    result = entry;
                                ++index;
                            }
                            if (text != DAT_0109b220)
                                InterlockedDecrement((volatile long*)(text - 8));
                        }
                    }
                }
            }
        }
        if (!result)
            unk414 &= ~0x8000u;
    }
    return result;
}

struct Owner134
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual int Query(void**);
};
struct Entry134
{
    int unk00, unk04;
    Owner134* owner;
};
struct List134
{
    int unk00, unk04, unk08, unk0c;
    Entry134* head;
};
struct State134
{
    int unk00, unk04;
    List134* list;
    void Object_DoNothing();
};
struct Input134
{
};
struct Node134
{
    int unk00, unk04, unk08, unk0c;
    State134* state;
};
Node134* __cdecl bhkUtilFunctions_FindNextCollisionObject(Input134*);
__forceinline Owner134* Resolve134(Input134* input)
{
    Node134* node;
    State134* state;
    List134* list;
    Entry134** slot;
    Entry134* first;
    if (!input)
        goto absent;
    node = bhkUtilFunctions_FindNextCollisionObject(input);
    if (!node)
        goto absent;
    state = node->state;
    if (!state)
        goto absent;
    list = state->list;
    if (!list)
        goto absent;
    state->Object_DoNothing();
    slot = &list->head;
    state->Object_DoNothing();
    if (!slot)
        goto absent;
    first = *slot;
    return first ? first->owner : 0;
absent:
    return 0;
}
// @fnv 0x00c75180
// src: COMMUNITY 0x00c75180
int __stdcall bhkRagdollController_GetCapsuleBoneShapeInfo(Input134* input)
{
    Owner134* owner = Resolve134(input);
    int result = 0;
    if (owner)
        result = owner->Query((void**)&input);
    return result;
}

// @fnv 0x00c66240
void NiAVObject::FUN_00c66240(NiObject* a)
{
    bhkRefObject_SethkObject(a);
}

// 0x00c66300  inc dword [ecx+0x18]; ret
struct C00c66300
{
    char pad00[0x18];
    int m18;
    void bhkWorld_StartBatchingAdds();
};

// @fnv 0x00c66300
// src: XBOX_PDB 0x00c66300
void C00c66300::bhkWorld_StartBatchingAdds()
{
    ++m18;
}

struct FUN_00c66310_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void bhkWorld_StartBatchingRemovals();
};

// @fnv 0x00c66310
// src: XBOX_PDB 0x00c66310
void FUN_00c66310_class::bhkWorld_StartBatchingRemovals()
{
    ++unk1c;
}

extern "C" unsigned int DAT_011afec4;

static inline unsigned int C6A120IsEnabled(int object)
{
    DispatchState* pkState = GetExtraDataChecked(object);
    return pkState ? (pkState->flags & 2) : 0;
}

// @fnv 0x00c6a120
bool __cdecl SetSelectionValue(int object, float value, unsigned char mode, unsigned char overrideCheck)
{
    bool bResult = false;
    if (object)
    {
        if (overrideCheck || C6A120IsEnabled(object))
        {
            bResult = true;
            DispatchPacket kPacket;
            kPacket.status = 0;
            kPacket.mode = mode;
            kPacket.opcode = 0xf;
            *(float*)&kPacket.selection = value;
            if (DAT_011afec4)
                bhkWorld_DoObjectRec(object, &kPacket, DAT_011afec4);
        }
    }
    return bResult;
}

void __cdecl FUN_00a810b0();
// @fnv 0x00c6b5e0
// src: XBOX_PDB 0x00c6b5e0
void __cdecl bhkNiCollisionObject_SetSceneGraphObject()
{
    FUN_00a810b0();
}

extern "C" double __cdecl fabs(double);
extern "C" double __cdecl acos(double);

inline float AH_fabsf(float _X)
{
    return ((float)fabs((double)_X));
}
inline float AH_acosf(float _X)
{
    return ((float)acos((double)_X));
}
inline float AH_fabs(float _X)
{
    return (AH_fabsf(_X));
}
inline float AH_acos(float _X)
{
    return (AH_acosf(_X));
}

namespace AHMath {
inline float fabs(float r)
{
    return AH_fabs(r);
}
inline float acos(float r)
{
    if (AHMath::fabs(r) >= 1.0f)
    {
        r = (r > 0) ? 0 : 3.14159265358979f;
        return r;
    }
    return AH_acos(r);
}
}

struct C74C20Quat
{
    float m_vec[4];
    float GetAngle() const;
};

// Returns twice the arc-cosine of the absolute value of m_vec[3], clamped by AHMath::acos.
// @fnv 0x00c74c20
float C74C20Quat::GetAngle() const
{
    float angle = AHMath::fabs(m_vec[3]);
    angle = AHMath::acos(angle);
    angle *= 2.0f;
    return angle;
}

// @fnv 0x00c7be90
template <> NiTMapItem<const char*, NiPointer<bhkPoseArray> >* NiTMap<const char*, NiPointer<bhkPoseArray> >::NewItem()
{
    NiTMapItem<const char*, NiPointer<bhkPoseArray> >* p = static_cast<NiTMapItem<const char*, NiPointer<bhkPoseArray> >*>(_g_memoryManager.Allocate(sizeof(*p)));
    if (p)
        p->m_val.m_pObject = 0;
    else
        p = 0;
    return p;
}

struct FUN_00c7bf10_cls
{
    void* m_obj;
    int m_flags;
    int m_uiContentCount;
    void __thiscall UpdateState_00c7bf10();
};

// @fnv 0x00c7bf10
// src: GUESS 0x00c7bf10 (confidence: low)
void __thiscall FUN_00c7bf10_cls::UpdateState_00c7bf10()
{
    hkMemoryRouter* holder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* obj = &GetRouterHeap(*holder);
    int state = m_uiContentCount;
    m_flags = 0;
    if ((state & 0x80000000) == 0)
    {
        obj->bufFree(m_obj, (state & 0x3fffffff) * 8);
    }
    m_obj = 0;
    m_uiContentCount = 0x80000000;
}

// If pkObject is enabled, calls FUN_00c68900 with pkContext and pfnCallback and returns true; otherwise returns false.
// @fnv 0x00c68ec0
// src: COMMUNITY 0x00c68ec0
bool _bhkWorld_DoObjects(C6A2E0AVObject* pkObject, CollisionObjectCountContext* pkContext,
                  CollisionObjectCountCallback pfnCallback)
{
    bool bHandled = false;
    if (pkObject)
    {
        if (C6A2E0IsEnabled(pkObject))
        {
            bHandled = true;
            bhkWorld_DoObjectRec((NiAVObject*)pkObject, pkContext, pfnCallback);
        }
    }
    return bHandled;
}

extern __declspec(thread) int DAT_012722b4;
struct S69580_Scope
{
    int old;
    S69580_Scope() : old(DAT_012722b4)
    {
        DAT_012722b4 = 16;
    }
    ~S69580_Scope()
    {
        DAT_012722b4 = old;
    }
};
struct S69580_Ref
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};
struct S69580_Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S69580_Ref* owner;
    void FUN_00c90510();
};
struct S69580_Queue
{
    S69580_Ref* last;
    int num;
    void RemoveKey(NiPointer<S69580_Ref>* key);
};
void S69580_Insert(S69580_Queue* q, S69580_Ref* r);
__declspec(noinline) void S69580_Queue::RemoveKey(NiPointer<S69580_Ref>* key)
{
    S69580_Insert(this, key->m_pObject);
}
struct S69580_Access
{
    void DispatchOrQueue(S69580_Item* item);
};
struct S69580_World
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual S69580_Access* GetAccess();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    S69580_Item** items;
    unsigned int count;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    S69580_Queue queue;
    void ProcessPendingItems();
    void ReleaseBodies();
    void ClearReferences();
    void FlushEntries();
    bool AddItem(S69580_Item* item);
};
// Adds an item to the world's pending list, flushing it when full, or dispatches it via the access object.
// @fnv 0x00c69580
bool S69580_World::AddItem(S69580_Item* item)
{
    S69580_Scope scope;
    bool result = false;
    S69580_Access* access = GetAccess();
    if (access && item)
    {
        S69580_Ref* owner = item->owner;
        if (owner)
        {
            NiPointer<S69580_Ref> key(owner);
            queue.RemoveKey(&key);
        }
        if (unk1c > 0)
        {
            if (count >= 100)
            {
                ProcessPendingItems();
                ReleaseBodies();
                ClearReferences();
                FlushEntries();
            }
            item->FUN_00c90510();
            items[count++] = item;
        }
        else
        {
            access->DispatchOrQueue(item);
        }
        result = true;
    }
    return result;
}

struct Form
{
    int unk0, unk4, unk8;
    unsigned int flags;
};
struct Info
{
    int unk0;
    volatile char unk4;
    int unk8, unk12, unk16, unk20, unk24;
};
extern void* DAT_011afea4;
Form* __cdecl GetExtraDataChecked(void* p);
void __cdecl bhkWorld_DoObjectRec(void* p, Info* info, void* g);
// @fnv 0x00c6a3d0
// src: XBOX_PDB 0x00c6a3d0
bool __cdecl bhkWorld_SetGroup(void* p, int b, char c, char abForce)
{
    bool r = false;
    if (p)
    {
        Form* f = 0;
        unsigned int bits = 0;
        if (!abForce)
        {
            f = GetExtraDataChecked(p);
            if (f)
            {
                bits = f->flags;
                bits &= 2;
            }
        }
        if (abForce || (f && bits))
        {
            Info info;
            unsigned char cc = *(volatile unsigned char*)&c;
            int bb = b;
            info.unk4 = cc;
            void* g = DAT_011afea4;
            r = true;
            info.unk0 = 0;
            info.unk8 = 7;
            info.unk12 = bb;
            if (g)
                bhkWorld_DoObjectRec(p, &info, g);
        }
    }
    return r;
}

class NameEntry16
{
  public:
    unsigned int m_key;
    char unk04[0xC];
};

class SearchOwner
{
  public:
    char unk00[0x78];
    NameEntry16* m_pEntries;
    int m_uiItemCount;
    char unk80[0x40];
    unsigned int* FindEntry(unsigned int* out, unsigned int key, unsigned int zero);
};

class LookupTarget
{
  public:
    char unk00[0xC0];
    unsigned int m_val0xc0;
};

// If an entry with key 0x1300 exists, returns m_val0xc0 of the object FindEntry returns for that key; otherwise returns 0.
// @fnv 0x00c6d900
// src: COMMUNITY 0x00c6d900
unsigned int __stdcall bhkCharacterController_Getbhk(SearchOwner* owner)
{
    if (owner != 0)
    {
        for (int i = 0; i < owner->m_uiItemCount; ++i)
        {
            if (owner->m_pEntries[i].m_key == 0x1300)
            {
                unsigned int out[2];
                unsigned int* r = owner->FindEntry(out, 0x1300, 0);
                return ((LookupTarget*)*r)->m_val0xc0;
            }
        }
    }
    return 0;
}

extern int DAT_010c4b60;

struct FUN_00c747a0_Class
{
    int* vtbl;
    void SetVirtualTable_00c747a0();
};

// @fnv 0x00c747a0
// src: GUESS 0x00c747a0 (confidence: low)
void FUN_00c747a0_Class::SetVirtualTable_00c747a0()
{
    vtbl = &DAT_010c4b60;
}

void __cdecl FUN_00cc00e0();

// @fnv 0x00c74900
// src: GUESS 0x00c74900 (confidence: low)
void __cdecl Object_ForwardCall_00c74900()
{
    FUN_00cc00e0();
}

struct Motion_c672
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int m_uiMotionFlags;
};

struct BodyBase_c672
{
    int unk00, unk04, unk08, unk0c;
};

struct Body_c672 : public BodyBase_c672, public Motion_c672
{
};

class Entity_c672
{
  public:
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void UpdateMotion();

    int unk04;
    Body_c672* m_pkBody;

    void Object_DoNothing();
    Motion_c672* GetMotion()
    {
        return m_pkBody ? static_cast<Motion_c672*>(m_pkBody) : 0;
    }
};

struct EntityRef_c672
{
    int unk00, unk04, unk08, unk0c;
    Entity_c672* m_pkEntity;
};

struct MotionParams_c672
{
    int unk00, unk04, unk08;
    int m_iRequired;
    int m_iMotionType;
};

// Updates the motion type on the entity's body when the new type differs from the current one and matches the required type, then calls UpdateMotion.
// @fnv 0x00c672a0
// src: COMMUNITY 0x00c672a0
void __cdecl bhkWorld_ChangeLayerObject(EntityRef_c672* pkRef, MotionParams_c672* pkParams)
{
    Entity_c672* pkEntity = pkRef->m_pkEntity;
    int iNewType = pkParams->m_iMotionType;
    int iRequired = pkParams->m_iRequired;
    Body_c672* pkBody = pkEntity->m_pkBody;
    Motion_c672* pkMotion = pkBody ? static_cast<Motion_c672*>(pkBody) : 0;
    unsigned int uiFlags = pkMotion ? pkMotion->m_uiMotionFlags : 0;
    unsigned int uiType = uiFlags & 0x7f;
    if (iNewType != uiType && (iRequired == 0 || iRequired == uiType))
    {
        unsigned int uiNew = ((uiFlags ^ iNewType) & 0x7f) ^ uiFlags;
        if (pkBody)
        {
            pkEntity->Object_DoNothing();
            Motion_c672* pkWrite = static_cast<Motion_c672*>(pkBody);
            pkEntity->Object_DoNothing();
            if (pkWrite)
                pkWrite->m_uiMotionFlags = uiNew;
        }
        pkEntity->UpdateMotion();
    }
}

struct OwnerFlags
{
    int unk00, unk04, unk08, unk0c;
    unsigned int flags;
};
struct OwnerBinding
{
    int unk00, unk04, unk08;
    OwnerFlags* owner;
};
struct OffsetKindRecord
{
    int unk00, unk04, unk08, unk0c;
    signed char offset;
    char unk11, unk12, unk13;
    int unk14;
    unsigned char kind;
};
struct EntityRecord
{
    int unk00, unk04, unk08, unk0c;
    OffsetKindRecord link;
};
struct Processor
{
    void RemoveEntities(EntityRecord**, unsigned int);
};
struct World
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual Processor* GetProcessor();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    EntityRecord** entries;
    unsigned int count;
    void ClearEntries();
};
struct WorldObjectC67
{
    int unk00, unk04, unk08;
    unsigned long m_ulUserData;
    unsigned long getUserData() const
    {
        return m_ulUserData;
    }
};
struct BhkObjectC67
{
    int unk00, unk04, unk08, unk0c;
    unsigned int m_uiValue1;
};
inline WorldObjectC67* GetEntityC67(const OffsetKindRecord* c)
{
    if (c->kind == 1)
        return (WorldObjectC67*)((char*)c + c->offset);
    return 0;
}
void* _fnv_zlib_memset(void*, int, unsigned int);
// Processes up to 3000 entity entries via the processor, clears a flag on each entry's user data, releases references, and zeroes the entry array.
// @fnv 0x00c679a0
void World::ClearEntries()
{
    ContextGuard context;
    if (count > 0)
    {
        if (count >= 3000)
            count = 3000;
        Processor* processor = GetProcessor();
        if (processor)
        {
            processor->RemoveEntities(entries, count);
            for (unsigned int i = 0; i < count; ++i)
            {
                WorldObjectC67* pWorldObject = GetEntityC67(&entries[i]->link);
                if (pWorldObject)
                {
                    BhkObjectC67* obj = (BhkObjectC67*)pWorldObject->getUserData();
                    if (obj)
                        obj->m_uiValue1 &= ~32u;
                }
                ((hkReferencedObject*)entries[i])->removeReference();
            }
            _fnv_zlib_memset(entries, 0, count * 4);
            count = 0;
        }
    }
}

struct FUN_00c6a270_Context
{
    int m_00;
    unsigned char m_04;
    unsigned int m_08;
    unsigned int m_0C;
    int unk10;
    int unk14;
    int unk18;
};

extern "C" unsigned int DAT_011afea8;
extern "C" unsigned int DAT_011afeb8;

// Unless param_4 is set, requires bit 2 of the extra-data flags, then calls the DAT_011afeb8 callback on param_1 with a context built from param_2 and param_3.
// @fnv 0x00c6a270
// src: XBOX_PDB 0x00c6a270
bool __cdecl bhkWorld_Activate(int param_1, unsigned char param_2, unsigned char param_3, char abForce)
{
    bool result = false;
    if (param_1 != 0)
    {
        int iFlag = 0;
        if (abForce == 0)
        {
            DispatchState* state = GetExtraDataChecked(param_1);
            if (state != 0)
                iFlag = state->flags & 2;
        }
        else
            iFlag = 1;
        if (iFlag != 0)
        {
            FUN_00c6a270_Context context;
            result = true;
            context.m_04 = param_3;
            context.m_00 = 0;
            context.m_08 = 0xC;
            context.m_0C = param_2;
            if (DAT_011afeb8 != 0)
                bhkWorld_DoObjectRec(reinterpret_cast<NiAVObject*>(param_1),
                             reinterpret_cast<CollisionObjectCountContext*>(&context),
                             reinterpret_cast<CollisionObjectCountCallback>(DAT_011afeb8));
        }
    }
    return result;
}

struct FUN_00c6a440_Context
{
    int m_00;
    unsigned char m_04;
    unsigned int m_08;
    unsigned int m_0C;
    int unk10;
    int unk14;
    int unk18;
};

extern "C" unsigned int DAT_011afea8;

// Unless param_3 is set, requires bit 2 of the extra-data flags; calls the DAT_011afea8 callback and returns whether the context's m_0C ends up nonzero.
// @fnv 0x00c6a440
bool __cdecl HasCollisionObject(int param_1, unsigned char param_2, char param_3)
{
    bool result = false;
    if (param_1 != 0)
    {
        int iFlag = 0;
        if (param_3 == 0)
        {
            DispatchState* state = GetExtraDataChecked(param_1);
            if (state != 0)
                iFlag = state->flags & 2;
        }
        else
            iFlag = 1;
        if (iFlag != 0)
        {
            FUN_00c6a440_Context context;
            context.m_04 = param_2;
            context.m_00 = 0;
            context.m_08 = 8;
            context.m_0C = 0;
            if (DAT_011afea8 != 0)
                bhkWorld_DoObjectRec(reinterpret_cast<NiAVObject*>(param_1),
                             reinterpret_cast<CollisionObjectCountContext*>(&context),
                             reinterpret_cast<CollisionObjectCountCallback>(DAT_011afea8));
            result = context.m_0C != 0;
        }
    }
    return result;
}

struct Tmp_c6c1
{
    float m_f00;
    unsigned char m_b04;
    unsigned char m_b05;
    unsigned char m_b06;
    unsigned char m_b07;
    unsigned char m_b08;
};
// This operation is not declared by the shared scene-object header.
void __cdecl FUN_00a68bf0();

// Updates collision-bearing objects and their children, then updates the world bound.
// @fnv 0x00c6c110
// src: XBOX_PDB 0x00c6c110
void bhkNiCollisionObject_SynchronizeRec(NiAVObject* apNode, bool bForce)
{
    if (apNode)
    {
        NiCollisionObject* p = apNode->m_spCollisionObject;
        int r = 0;
        if (p)
            r = reinterpret_cast<int>(p->IsBhkNiCollisionObject());
        if (r || bForce)
        {
            reinterpret_cast<void(__thiscall*)(NiAVObject*)>(FUN_00a68bf0)(apNode);
            Tmp_c6c1 t;
            t.m_f00 = 0.0f;
            t.m_b04 = 0;
            t.m_b05 = 0;
            t.m_b06 = 0;
            t.m_b07 = 0;
            t.m_b08 = 0;
            apNode->UpdateWorldData(*reinterpret_cast<NiUpdateData*>(&t));
            bForce = true;
        }
        NiNode* c = apNode->IsSceneNode();
        if (c)
        {
            for (unsigned int i = 0; i < c->m_kChildren.m_usSize; ++i)
                bhkNiCollisionObject_SynchronizeRec(c->m_kChildren.m_pBase[i], bForce);
        }
        apNode->UpdateWorldBound();
    }
}

struct CBinaryStream
{
    void* m_ppVirtualMethodTable;                                                                                      // +0x00
    unsigned int m_uiStreamFlags;                                                                        // +0x04
    void* m_pvUnk08;                                                                                     // +0x08
    unsigned int(__cdecl* m_pfnRead)(CBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);  // +0x0c

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void BinLoad(CBinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

class FakeThis00a81040
{
  public:
    void FUN_00a81040(NiStream& kStream);
};

class CollisionLoad : public FakeThis00a81040
{
  public:
    int unk00;              // +0x00
    int unk04;              // +0x04
    int unk08;              // +0x08
    unsigned short m_us0c;  // +0x0c
    unsigned short unk0e;   // +0x0e
    int m_i10;              // +0x10

    void bhkNiCollisionObject_SaveBinary(void* stream);
};

// Calls the base routine FUN_00a81040, then loads m_us0c from the stream with BinLoad and passes m_i10 to kStream.v30.
// @fnv 0x00c6c380
// src: XBOX_PDB 0x00c6c380
void CollisionLoad::bhkNiCollisionObject_SaveBinary(void* stream)
{
    NiStream& kStream = *static_cast<NiStream*>(stream);
    FUN_00a81040(kStream);
    BinLoad(**reinterpret_cast<CBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x250), &m_us0c);
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_i10));
}

extern double DAT_0103c7c8;
static inline float Min(float a, float b)
{
    return b < a ? b : a;
}
struct FUN_00c6cc10_cls
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    float m_f528;
    float m_f52c;
    float Evaluate(float p, float q);
};
// Adds m_f528 times the lesser of m_f52c and q to p, decrements m_f52c by q, and steps m_f528 down by DAT_0103c7c8 or zeroes it when m_f52c is not positive.
// @fnv 0x00c6cc10
float FUN_00c6cc10_cls::Evaluate(float afBase, float afAmount)
{
    float result = afBase;
    if (m_f52c > 0.0f)
    {
        float consumed = Min(m_f52c, afAmount);
        result += m_f528 * consumed;
        m_f52c -= afAmount;
        m_f528 = (float)(m_f528 - DAT_0103c7c8);
    }
    else
        m_f528 = 0.0f;
    return result;
}

extern unsigned int DAT_01030394;
extern unsigned int DAT_0103078c;
extern unsigned int DAT_010306b4;
extern unsigned int DAT_010c4694;
extern unsigned int DAT_0126810c;
extern unsigned int DAT_01268208;
extern unsigned int DAT_012685a0;

struct bhkRefInitBase
{
    bhkRefInitBase();
    ~bhkRefInitBase();
    unsigned int m_vft;
    unsigned int m_04;
    unsigned int m_08;
};

struct S00c6d040_A : public bhkRefInitBase
{
    unsigned int m_0c;
    unsigned int m_10;
    S00c6d040_A()
    {
        m_0c = 0;
        m_10 = 0;
        m_vft = (unsigned int)&DAT_01030394;
        DAT_0126810c += 1;
    }
};

struct S00c6d040_B : public S00c6d040_A
{
    S00c6d040_B()
    {
        m_vft = (unsigned int)&DAT_0103078c;
        DAT_01268238 += 1;
    }
};

struct S00c6d040_C : public S00c6d040_B
{
    unsigned char m_14;
    S00c6d040_C()
    {
        m_vft = (unsigned int)&DAT_010306b4;
        DAT_01268208 += 1;
        m_14 = 0;
    }
};

struct FUN_00c6d040 : public S00c6d040_C
{
    FUN_00c6d040(unsigned int a);
    void bhkCachingShapePhantom_Init(unsigned int a);
};

// Constructs the object by setting the vft, calling FUN_00cc2530 with a, incrementing DAT_012685a0, and zeroing m_14.
// @fnv 0x00c6d040
FUN_00c6d040::FUN_00c6d040(unsigned int a)
{
    m_vft = (unsigned int)&DAT_010c4694;
    bhkCachingShapePhantom_Init(a);
    DAT_012685a0 += 1;
    m_14 = 0;
}

struct FUN_00c6d7e0_Child
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int m_uiValue1;
};

struct FUN_00c6d7e0_Parent
{
    int unk00;
    int unk04;
    FUN_00c6d7e0_Child* m_pChildObject;
};

unsigned int __stdcall bhkShape_GetSubshapeMaterial(int v);
extern unsigned int DAT_01267bc8;

// With a set and a child object, returns whether DAT_01267bc8 gave 0 for c (or child m_uiValue1 & 0x1f); otherwise 1 if a or b is set, else 0.
// @fnv 0x00c6d7e0
// src: COMMUNITY 0x00c6d7e0
char __cdecl bhkCharacterController_IsShapeConsideredPenetrating(FUN_00c6d7e0_Parent* apParent, bool abFlag1, bool abFlag2, int aiValue)
{
    if (!abFlag1 && abFlag2 != abFlag1)
        return 1;
    try
    {
        if (abFlag1 == 0)
            goto RETA;
    }
    catch (...)
    {
        throw;
    }
    if (apParent != 0 && apParent->m_pChildObject != 0)
    {
        unsigned int t;
        if (aiValue != -1)
        {
            t = bhkShape_GetSubshapeMaterial(aiValue);
        }
        else
        {
            t = apParent->m_pChildObject->m_uiValue1 & 0x1f;
        }
        unsigned char r = 0;
        if (DAT_01267bc8)
        {
            r = (unsigned char)((unsigned char(__cdecl*)(unsigned int))DAT_01267bc8)(t);
        }
        return !r;
    }
RETA:
    return abFlag1;
}

class FUN_00c6def0_obj;
class FUN_00c6def0_sub
{
  public:
    float FUN_00c86430();
};
class FUN_00c6def0_obj
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    FUN_00c6def0_sub m_e0;
    int m_e4;
    unsigned char m_e8;
};

extern float DAT_01267bc0;
extern "C" bool __cdecl bhkRigidBody_IsMotionTypeDynamic(unsigned int* p);
// Returns true if p is non-null and either FUN_00c8cce0 accepts m_e8 and m_e0.FUN_00c86430() exceeds DAT_01267bc0, or (m_2c & 0x7f) == 6.
// @fnv 0x00c6def0
// src: COMMUNITY 0x00c6def0
bool __cdecl bhkCharacterController_IsHurtfulBody(FUN_00c6def0_obj* p)
{
    bool result = false;
    if (p != 0)
    {
        unsigned int v = p->m_e8;
        if (bhkRigidBody_IsMotionTypeDynamic(&v))
        {
            float f = p->m_e0.FUN_00c86430();
            if (f > DAT_01267bc0)
                result = true;
        }
        if (!result)
        {
            if ((p->m_2c & 0x7f) == 6)
                result = true;
        }
    }
    return result;
}

struct S00c6e050_Sub
{
    void AddEntry(int a, long long b);
};
struct S00c6e050_Ptr
{
    int unk00;
    int unk04;
    S00c6e050_Sub* m_08;
    bool ContainsObject(int a);
    void Object_DoNothing();
};
struct S00c6e050_Obj
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038c;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039c;
    int unk03a0;
    int unk03a4;
    int unk03a8;
    int unk03ac;
    int unk03b0;
    int unk03b4;
    int unk03b8;
    int unk03bc;
    int unk03c0;
    int unk03c4;
    int unk03c8;
    int unk03cc;
    int unk03d0;
    int unk03d4;
    int unk03d8;
    int unk03dc;
    int unk03e0;
    int unk03e4;
    int unk03e8;
    int unk03ec;
    int unk03f0;
    int unk03f4;
    int unk03f8;
    int unk03fc;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040c;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041c;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042c;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043c;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044c;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045c;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046c;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047c;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048c;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049c;
    int unk04a0;
    int unk04a4;
    int unk04a8;
    int unk04ac;
    int unk04b0;
    int unk04b4;
    int unk04b8;
    int unk04bc;
    int unk04c0;
    int unk04c4;
    int unk04c8;
    int unk04cc;
    int unk04d0;
    int unk04d4;
    int unk04d8;
    int unk04dc;
    int unk04e0;
    int unk04e4;
    int unk04e8;
    int unk04ec;
    int unk04f0;
    int unk04f4;
    int unk04f8;
    int unk04fc;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050c;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051c;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052c;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053c;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054c;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055c;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056c;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057c;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058c;
    int unk0590;
    S00c6e050_Ptr* m_594;
    void __thiscall bhkCharacterController_SetBSReference(volatile int a, volatile int b);
};
// Unless m_594->ContainsObject(a), calls FUN_00a29680, then m_594->m_08->AddEntry(a, b), then FUN_00a29680 again.
// @fnv 0x00c6e050
// src: XBOX_PDB 0x00c6e050
void S00c6e050_Obj::bhkCharacterController_SetBSReference(volatile int a, volatile int b)
{
    S00c6e050_Ptr* p = m_594;
    if (!p)
        return;
    if (p->ContainsObject(a))
        return;
    S00c6e050_Sub* s = p->m_08;
    long long v = (long long)b;
    if (!s)
        return;
    p->Object_DoNothing();
    s->AddEntry(a, v);
    p->Object_DoNothing();
}

extern "C" double __cdecl acos(double);
extern "C" double __cdecl fabs(double);

// Returns acos(fValue), except returns 0.0f when |fValue| is at least 1 and positive, and pi when it is at least 1 and not positive.
// @fnv 0x00c74a70
float ClampedAcos(float fValue)
{
    if ((float)fabs(fValue) >= 1.0f)
        return (fValue > 0.0f) ? 0.0f : 3.1415927f;
    return (float)acos(fValue);
}

struct Bone_c75
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    NiTransform m_kLocal;
};
struct Rec_c75
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
};
struct Info_c75
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    int m_iArrayLength;
};
struct Holder_c75
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    Info_c75* m_pkInfo;
};
struct Skel_c75
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    float m_fScale;
};
extern NiTransform __cdecl HK2NI_00c74d50(Rec_c75* pkRec);
class FUN_00c75b40_cls
{
  public:
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    Skel_c75* m_58;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    Rec_c75* m_94;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    Bone_c75** m_a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned unk1a0;
    unsigned unk1a4;
    unsigned unk1a8;
    unsigned unk1ac;
    unsigned unk1b0;
    unsigned unk1b4;
    unsigned unk1b8;
    unsigned unk1bc;
    unsigned unk1c0;
    unsigned unk1c4;
    unsigned unk1c8;
    unsigned unk1cc;
    unsigned unk1d0;
    unsigned unk1d4;
    unsigned unk1d8;
    unsigned unk1dc;
    unsigned unk1e0;
    unsigned unk1e4;
    unsigned unk1e8;
    unsigned unk1ec;
    unsigned unk1f0;
    unsigned unk1f4;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    Holder_c75* m_2a4;
    void UpdateBoneLocalTransforms();
};
// @fnv 0x00c75b40
void FUN_00c75b40_cls::UpdateBoneLocalTransforms()
{
    int iCount = m_2a4->m_pkInfo->m_iArrayLength;
    float fInv = 1.0f / m_58->m_fScale;
    for (int i = 0; i < iCount; i++)
    {
        Bone_c75* pkBone = m_a4[i];
        NiTransform kXform = HK2NI_00c74d50(&m_94[i]);
        kXform.m_Translate.x *= fInv;
        int* __restrict px = (int*)&pkBone->m_kLocal.m_Translate.x;
        *px = *(int*)&kXform.m_Translate.x;
        kXform.m_Translate.y *= fInv;
        *(int*)&pkBone->m_kLocal.m_Translate.y = *(int*)&kXform.m_Translate.y;
        kXform.m_Translate.z *= fInv;
        *(int*)&pkBone->m_kLocal.m_Translate.z = *(int*)&kXform.m_Translate.z;
        pkBone->m_kLocal.m_Rotate = kXform.m_Rotate;
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

// @fnv 0x00c7beb0
template <> void NiTMap<const char*, NiPointer<bhkPoseArray> >::DeleteItem(NiTMapItem<const char*, NiPointer<bhkPoseArray> >* item)
{
    item->m_val = 0;
    if (item)
    {
        item->~NiTMapItem();
        _g_memoryManager.Deallocate(item);
    }
}

#include <xmmintrin.h>
namespace fnv_00c69010 {
extern __m128 DAT_01267e30;
extern float DAT_01267b38;
extern int DAT_012677a4;
extern "C" void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);
struct ConstructorPhysics;
struct ConstructorParent : FUN_00c87c30_owner
{
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual ConstructorPhysics* v25();
    ConstructorPhysics* GetPhysics()
    {
        return v25();
    }
    NiPointer<C67F20RefObject> object;
};
struct ConstructorArray
{
    void* data;
    int size;
    unsigned int capacity;
    ConstructorArray() : data(0), size(0), capacity(0x80000000)
    {}
    ~ConstructorArray();
};
struct ConstructorList : C67F20List
{
    ConstructorList()
    {
        m_pkHead = 0;
    }
};
struct ConstructorArgument
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int context;
};
struct ConstructorPhysics
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    float value1;
    float value2;
};
struct FUN_00c69010 : ConstructorParent
{
    void CreateChildAndNotifySim(void*);
    unsigned int unk10;
    bool flag14, flag15, flag16;
    unsigned int unk18, unk1c, unk20, unk24, unk28;
    void* buffer2c;
    unsigned int unk30;
    void* buffer34;
    unsigned int unk38;
    void* buffer3c;
    unsigned int unk40;
    void* buffer44;
    unsigned int unk48;
    void* buffer4c;
    unsigned int unk50, unk54, unk58, unk5c;
    __m128 vector60;
    ConstructorArray array70;
    ConstructorArray array7c;
    float value88, value8c;
    ConstructorList list90;
    FUN_00c69010(ConstructorArgument*);
};
inline float MinValue(float value, float limit)
{
    return value < limit ? value : limit;
}
// Allocates and zeroes five buffers, caps DAT_01267b38 at 1.0, calls list90.FUN_00c67f20 and CreateChildAndNotifySim, and copies two floats from GetPhysics().
// @fnv 0x00c69010
FUN_00c69010::FUN_00c69010(ConstructorArgument* argument)
    : unk10(0), flag14(false), flag15(false), flag16(false), unk18(0), unk1c(0), unk20(0), unk24(0), unk28(0), unk30(0),
      unk38(0), unk40(0), unk48(0), unk50(0), vector60(DAT_01267e30)
{
    ThreadMemoryScope scope;
    ++DAT_012677a4;
    buffer2c = _g_memoryManager.Allocate(12000);
    _fnv_zlib_memset(buffer2c, 0, 12000);
    buffer34 = _g_memoryManager.Allocate(800);
    _fnv_zlib_memset(buffer34, 0, 800);
    buffer3c = _g_memoryManager.Allocate(400);
    _fnv_zlib_memset(buffer3c, 0, 400);
    buffer44 = _g_memoryManager.Allocate(800);
    _fnv_zlib_memset(buffer44, 0, 800);
    buffer4c = _g_memoryManager.Allocate(12000);
    _fnv_zlib_memset(buffer4c, 0, 12000);
    float minimum = MinValue(DAT_01267b38, 1.0f);
    DAT_01267b38 = minimum;
    list90.DeleteListNodesAndReleaseOwner();
    CreateChildAndNotifySim(argument ? &argument->context : 0);
    value88 = GetPhysics()->value1;
    value8c = GetPhysics()->value2;
}
}  // namespace fnv_00c69010

#include <math.h>
struct FUN_00c6cbc0_class
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    float unk528;
    float unk52C;

    void __thiscall UpdateLargestAbsoluteThreshold(float threshold, float value);
};

// Stores threshold and value into unk528 and unk52C when the absolute value of threshold exceeds the absolute value of unk528.
// @fnv 0x00c6cbc0
// src: GUESS 0x00c6cbc0 (confidence: medium)
void __thiscall FUN_00c6cbc0_class::UpdateLargestAbsoluteThreshold(float threshold, float value)
{
    if (fabs(threshold) > fabs(unk528))
    {
        unk528 = threshold;
        unk52C = value;
    }
}

extern float DAT_0104da48;

__declspec(align(16)) struct C_00c6cde0
{
    __m128 m00;
    __m128 m10;
    float m20;
    float m24;
    float m28;
    unsigned int unk2c;
    __m128 m30;
    float m40;
    float m44;
    unsigned int m48;
    float m4c;
    float m50;
    unsigned int m54;
    float m58;
    float m5c;
    float m60;
    float m64;
    float m68;
    unsigned int m6c;
    unsigned char m70;
    void InitializeVectorDefaults();
};

// Sets defaults: two zeroed vectors, a (0,1,0,0) vector, and fixed float and integer values including one read from DAT_0104da48.
// @fnv 0x00c6cde0
// src: GUESS 0x00c6cde0 (confidence: medium)
void C_00c6cde0::InitializeVectorDefaults()
{
    __m128 v1 = _mm_setr_ps(0.0f, 0.0f, 0.0f, 0.0f);
    this->m00 = v1;
    this->m10 = v1;
    this->m20 = 1.0f;
    this->m24 = 0.0f;
    this->m28 = 0.1f;
    this->m48 = 0;
    this->m54 = 4;
    this->m40 = 0.0f;
    this->m44 = 0.0f;
    this->m6c = 10;
    this->m4c = 0.05f;
    this->m50 = 10.0f;
    this->m58 = 10.0f;
    this->m5c = DAT_0104da48;
    this->m70 = 0;
    this->m60 = 0.0f;
    this->m64 = 1.5707964f;
    this->m68 = 1.0f;
    this->m30 = _mm_setr_ps(0.0f, 1.0f, 0.0f, 0.0f);
}

struct FUN_00c6d150_class
{
    void bhkCharacterController_ClearPush();
};

// If the int at offset 0x590 is nonzero, zeroes the 16 bytes at offset 0x580 and sets the int at 0x590 to 0.
// @fnv 0x00c6d150
// src: COMMUNITY 0x00c6d150
void FUN_00c6d150_class::bhkCharacterController_ClearPush()
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x590) != 0)
    {
        *reinterpret_cast<__m128*>(reinterpret_cast<char*>(this) + 0x580) = _mm_setzero_ps();
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x590) = 0;
    }
}

extern float DAT_01267e30;
struct S_00c6d5c0
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int m_414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    __m128 m_4f0;
    __m128 m_500;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    float m_524;
    void bhkCharacterController_ApplyVelocityMod();
};
// If m_524 is positive, adds m_500 scaled by m_524 to m_4f0 when m_414 lacks 0x1800; otherwise resets m_500 from DAT_01267e30.
// @fnv 0x00c6d5c0
// src: COMMUNITY 0x00c6d5c0
void S_00c6d5c0::bhkCharacterController_ApplyVelocityMod()
{
    if (m_524 > 0.0f)
    {
        __m128 v = _mm_load_ss(&m_524);
        if ((m_414 & 0x1800) == 0)
        {
            m_4f0 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0), m_500), m_4f0);
        }
    }
    else
        m_500 = *(__m128*)&DAT_01267e30;
}

namespace fnv_00c6fd80 {

using ::NiMemObject;
class FUN_00a5ecb0 : public NiMemObject
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    NiPoint3 position;
    float scale;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    FUN_00a5ecb0(unsigned int);
    void AssignFixedString(const NiFixedString&);
};
struct Scene047
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Scene047* asNode();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void attach(FUN_00a5ecb0*, const void*);
    virtual void v36();
    virtual void clone(FUN_00a5ecb0*, int);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    float scale;
    int unk09c;
    int unk0a0;
    unsigned short unk0a4;
    unsigned short count;
    SettingHolder* NiNode_GetAtChecked(int);
};
struct Handler047
{
    Scene047* bhkWorldObject_GetAVObject(int);
};
extern char DAT_010c43d8;
extern char DAT_011f4428;
extern char DAT_011a9b7c;
NiPoint3* __cdecl FUN_00458620(NiPoint3*, const NiPoint3*);
struct Controller047
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    NiPoint3 offset;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    Handler047* handler;
    int bhkCharacterController_GetCollisionDebugNode();
    Scene047* GetCurrentObject();
    void AttachSceneNode(Scene047* node);
};
// Clones node into a new object, sets its position to offset times 1/node->scale and its scale to |1/node->scale|, then attaches it to the current object.
// @fnv 0x00c6fd80
void Controller047::AttachSceneNode(Scene047* node)
{
    ThreadMemoryScope memoryScope;
    if (bhkCharacterController_GetCollisionDebugNode())
        return;
    if (!node)
    {
        if (!handler)
            goto done;
        Scene047* object = handler->bhkWorldObject_GetAVObject(0);
        if (!object)
            goto done;
        node = object->asNode();
        if (!node)
            goto done;
        if (node->count)
        {
            SettingHolder* child = node->NiNode_GetAtChecked(0);
            if (!child)
                goto done;
            node = (Scene047*)child->FUN_00653290(&DAT_011f4428);
        }
        if (!node)
            goto done;
    }
    if (!GetCurrentObject())
        goto done;
    {
        FUN_00a5ecb0* created = new FUN_00a5ecb0(0);
        node->clone(created, 1);
        created->AssignFixedString(NiFixedString(static_cast<const char*>(&DAT_010c43d8)));
        float inverse = 1.0f / node->scale;
        NiPoint3 buffer;
        const NiPoint3* result = FUN_00458620(&buffer, &offset);
        NiPoint3 scaled;
        scaled.x = result->x * inverse;
        scaled.y = result->y * inverse;
        scaled.z = result->z * inverse;
        memcpy(&created->position, &scaled, sizeof(scaled));
        if (node->scale != 0.0f)
        {
            float value = 1.0f / node->scale;
            value = fabs(value);
            created->scale = value;
        }
        GetCurrentObject()->attach(created, &DAT_011a9b7c);
        unk414 |= 0x8000;
    }
done:;
}
}  // namespace fnv_00c6fd80

namespace fnv_00c74ed0 {
struct __declspec(align(16)) FUN_00c74ed0
{
    short channel0, channel1, channel2, channel3, channel4, channel5, channel6, channel7;
    __m128 initialVector;
    float initialValue, factor0, factor1, factor2, factor3, unk34, unk38, unk3c;
    __m128 currentPosition, currentScale, previousPosition, previousScale;
    unsigned char enabled, dirty;
    FUN_00c74ed0();
};
extern "C" float DAT_01012054;
extern "C" __m128 DAT_01267e30;
extern "C" __m128 DAT_012683b0;
// Sets channel0-4 to -1, factor0-3 to 1.0, the vector fields from DAT_01267e30 and DAT_012683b0, enabled to 1 and dirty to 0.
// @fnv 0x00c74ed0
FUN_00c74ed0::FUN_00c74ed0()
{
    double initial = DAT_01012054;
    channel0 = -1;
    channel1 = -1;
    channel2 = -1;
    channel3 = -1;
    channel4 = -1;
    _mm_store_ps(reinterpret_cast<float*>(&initialVector), DAT_01267e30);
    initialValue = (float)initial;
    factor3 = factor2 = factor1 = factor0 = 1.0f;
    currentPosition = DAT_01267e30;
    currentScale = DAT_012683b0;
    previousPosition = DAT_01267e30;
    previousScale = DAT_012683b0;
    enabled = 1;
    dirty = 0;
}
}  // namespace fnv_00c74ed0

extern "C" void __cdecl bhkNiCollisionObject_CopyMembers();
// @fnv 0x00c657f0
// src: XBOX_PDB 0x00c657f0
void __cdecl bhkPCollisionObject_CopyMembers()
{
    bhkNiCollisionObject_CopyMembers();
}

extern "C" void __cdecl FUN_00c6bb70();
// @fnv 0x00c65810
// src: XBOX_PDB 0x00c65810
void __cdecl bhkCollisionObject_LinkObject()
{
    FUN_00c6bb70();
}

extern "C" void __cdecl bhkNiCollisionObject_SaveBinary();
// @fnv 0x00c65820
// src: XBOX_PDB 0x00c65820
void __cdecl bhkCollisionObject_SaveBinary()
{
    bhkNiCollisionObject_SaveBinary();
}

struct Key
{
    int a;
    int b;
    int c;
    Key(int v);
    ~Key();
};
struct Tag
{
    char b;
    Tag() : b(0)
    {}
    Tag(const Tag& o);
};

struct Result
{
    bool ok;
    Result(const Result& o);
};
Result hkpHavokSnapshot_save_00cc0d60(Pair pc, Tag t, int x, int y);

struct Owner67430
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void* GetTarget();
    bool bhkWorld_SaveSnapshot(int v);
};

// Builds a Key from v and returns the ok flag of FUN_00cc0d60 called with GetTarget() and the key's c field.
// @fnv 0x00c67430
// src: COMMUNITY 0x00c67430
bool Owner67430::bhkWorld_SaveSnapshot(int aiKey)
{
    Key key(aiKey);
    Result r = hkpHavokSnapshot_save_00cc0d60(Pair(reinterpret_cast<int>(GetTarget()), key.c), Tag(), 0, 0);
    return r.ok != 0;
}

namespace sc68e90 {

struct Handler;

struct Event
{
    int unk00;
    int unk04;
    int m_iType;
};

extern Handler* DAT_011afe88[];

void bhkWorld_DoObjectRec(void* pvContext, Event* pkEvent, Handler* pkHandler);

// Looks up the handler for pkEvent->m_iType in DAT_011afe88 and calls FUN_00c68900 with pvContext, pkEvent, and the handler if found.
// @fnv 0x00c68e90
// src: COMMUNITY 0x00c68e90
void bhkWorld_DoObjects(void* pvContext, Event* pkEvent)
{
    Handler* pkHandler = DAT_011afe88[pkEvent->m_iType];
    if (pkHandler)
        bhkWorld_DoObjectRec(pvContext, pkEvent, pkHandler);
}

}

extern C6A2E0Callback DAT_011afeac;

struct ObjectProperties
{
    unsigned int unk00, unk04, unk08, flags;
};

// If object is non-null and enabled (or skipFlagCheck), fills a C6A2E0Context and calls FUN_00c68900 when DAT_011afeac is set; returns 1 if enabled, else 0.
// @fnv 0x00c6a4c0
unsigned char __cdecl TraverseObject(C6A2E0AVObject* object, void* userData, unsigned int count, bool recurse,
                                     bool skipFlagCheck)
{
    unsigned char result = 0;
    C6A2E0Context context;
    if (object != 0)
    {
        unsigned int enabled = skipFlagCheck ? 1 : C6A2E0IsEnabled(object);
        if (enabled)
        {
            result = 1;
            context.bRecurse = recurse;
            context.pCurrentObject = 0;
            context.uiTraversalFlags = 9;
            context.iCount = count;
            context.pUserData = userData;
            C6A2E0Callback callback = DAT_011afeac;
            if (callback != 0)
                bhkWorld_DoObjectRec(object, &context, callback);
        }
    }
    return result;
}

extern float DAT_01267bcc;

struct Owner274
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    __m128 velocity;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    float selectedDuration;

    void UpdateMaxVelocity(const float* param_1, float param_2);
};

static inline float Len2(__m128 v)
{
    __m128 s = _mm_mul_ps(v, v);
    float r;
    _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(s, s, 0xaa), _mm_add_ss(_mm_shuffle_ps(s, s, 0x55), s)));
    return r;
}
// @fnv 0x00c6d4d0
void Owner274::UpdateMaxVelocity(const float* param_1, float afDuration)
{
    __m128 values;
    float* p = (float*)&values;
    p[0] = param_1[0] * DAT_01267bcc;
    p[1] = param_1[1] * DAT_01267bcc;
    p[2] = param_1[2] * DAT_01267bcc;
    p[3] = 0.0f;
    float scale = 1.0f / afDuration;
    __m128 s4 = _mm_load_ss(&scale);
    __m128 scaled = _mm_mul_ps(_mm_shuffle_ps(s4, s4, 0), values);
    if (Len2(scaled) > Len2(velocity))
    {
        selectedDuration = afDuration;
        velocity = scaled;
    }
}

struct FUN_00c74780_StandIn
{
    void __thiscall FUN_005545f0();
    int __thiscall FUN_00c74780(unsigned char param_2);
};

// Calls FUN_005545f0, conditionally calls DAT_011f6238.FUN_00aa4060 when param_2 has bit 0 set, and returns this as an int.
// @fnv 0x00c74780
int __thiscall FUN_00c74780_StandIn::FUN_00c74780(unsigned char param_2)
{
    this->FUN_005545f0();

    if (param_2 & 1)
        DAT_011f6238.MemoryManager_Deallocate(reinterpret_cast<FUN_00c68f50_cls*>(this));

    return reinterpret_cast<int>(this);
}

struct QuatResult
{
    __m128 value;

    void __thiscall hkQuaternion_setInverseMul(const float* a, const float* b);
};

// Combines the two 4-float vectors a and b with SSE (cross terms, w-scaled terms, 4-component dot in w) and stores the result in value.
// @fnv 0x00c74b70
// src: COMMUNITY 0x00c74b70
void __thiscall QuatResult::hkQuaternion_setInverseMul(const float* a, const float* b)
{
    __m128 xmm1 = _mm_load_ps(a);
    __m128 xmm0 = _mm_load_ps(b);

    __m128 xmm3 = _mm_mul_ps(_mm_shuffle_ps(xmm0, xmm0, 201), _mm_shuffle_ps(xmm1, xmm1, 210));
    __m128 xmm2;

    xmm2 = _mm_shuffle_ps(xmm0, xmm0, _MM_SHUFFLE(3, 1, 0, 2));
    __m128 xmm4 = _mm_shuffle_ps(xmm1, xmm1, _MM_SHUFFLE(3, 0, 2, 1));
    xmm2 = _mm_mul_ps(xmm2, xmm4);
    xmm3 = _mm_sub_ps(xmm3, xmm2);

    xmm2 = _mm_shuffle_ps(xmm1, xmm1, _MM_SHUFFLE(3, 3, 3, 3));
    xmm2 = _mm_shuffle_ps(xmm2, xmm2, 0);
    xmm2 = _mm_mul_ps(xmm2, xmm0);
    xmm2 = _mm_add_ps(xmm2, xmm3);

    xmm3 = _mm_shuffle_ps(xmm0, xmm0, _MM_SHUFFLE(3, 3, 3, 3));
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    xmm4 = _mm_shuffle_ps(xmm3, xmm3, 0);
    xmm4 = _mm_mul_ps(xmm4, xmm1);

    xmm2 = _mm_sub_ps(xmm2, xmm4);
    xmm1 = _mm_shuffle_ps(xmm0, xmm0, 78);
    xmm1 = _mm_add_ps(xmm1, xmm0);

    xmm0 = _mm_shuffle_ps(xmm1, xmm1, _MM_SHUFFLE(2, 3, 0, 1));
    xmm0 = _mm_add_ps(xmm0, xmm1);

    xmm1 = xmm2;
    xmm0 = _mm_shuffle_ps(xmm0, xmm0, 0);
    xmm2 = _mm_unpackhi_ps(xmm2, xmm0);
    xmm1 = _mm_shuffle_ps(xmm1, xmm2, 0xc4);

    QuatResult result;
    result.value = xmm1;
    *this = result;
}

struct SavedNodeTransform
{
    NiAVObject* object;
    NiMatrix3 rotation;
    NiPoint3 translation;
    float scale;
};
struct SavedNodeArray
{
    int unk00;
    SavedNodeTransform* data;
    unsigned int size;
};
void __cdecl bhkWorld_SetMotion(NiNode*, int, bool, bool, bool);
void __cdecl SetFlagRecursive(int, void*);
// @fnv 0x00c75c00
void __cdecl RestoreNodeTransforms(NiNode* root, SavedNodeArray* saved, int flags, int mode)
{
    for (unsigned int i = 0; i < saved->size; ++i)
    {
        memcpy(&saved->data[i].object->m_kLocal.m_Translate, &saved->data[i].translation, sizeof(NiPoint3));
        saved->data[i].object->m_kLocal.m_Rotate = saved->data[i].rotation;
    }
    NiUpdateData update;
    root->Update(update);
    if (mode != 4 && mode != 0)
        bhkWorld_SetMotion(root, mode, true, false, true);
    if ((unsigned char)flags)
        SetFlagRecursive(flags, root);
}

struct XBase0
{
    int a0;
    int a4;
    int a8;
    int ac;
};
struct XBase1
{
    int b0;
};
struct XDerived : XBase0, XBase1
{
};
struct XObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual XBase1* v4();
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
};
struct XRef
{
    int f0;
    int f4;
    int f8;
    XObj** p;
};

// @fnv 0x00c7ffd0
// src: COMMUNITY 0x00c7ffd0
int __cdecl bhkUtilFunctions_FindbhkShapeCollection(XRef* apRef)
{
    XObj** ppObj = apRef->p;
    if (!ppObj)
        ppObj = (XObj**)apRef;
    int r = 0;
    if (ppObj)
    {
        XObj* o = *ppObj;
        if (o->m_iThirdValue == 8 || o->m_iThirdValue == 10)
        {
            XDerived* d = static_cast<XDerived*>(o->v4());
            r = d ? d->a8 : 0;
        }
        else
        {
            XObj* o2 = *ppObj;
            if (o2 && o2->m_iThirdValue == 9)
                r = o2->m_8;
        }
    }
    return r;
}

// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00c66630();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00c66630();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00c66630
    virtual void FUN_00c66630();
};

Derived::Derived()
{}

namespace fnv_00c66640 {
// sub ecx,0xc; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0xc).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00c66640();
    int unk04;
    int unk08;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00c66640();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00c66640
// src: GUESS 0x00c66640 (confidence: low)
    virtual void AdjustThisAndForward_00c66640();
};

Derived::Derived()
{}
}  // namespace fnv_00c66640

// FUN_00c66650 : MSVC this-adjusting thunk  (sub ecx, 0x10 ; jmp <impl>)
struct A1_00c66650
{
    A1_00c66650();
    virtual void FUN_00c66650();
    char pad[0x0c];
};
struct A2_00c66650
{
    A2_00c66650();
    virtual void FUN_00c66650();
};
struct Own_00c66650 : A1_00c66650, A2_00c66650
{
    Own_00c66650();
    virtual void key_fn();
// @fnv 0x00c66650
    void FUN_00c66650();
};
Own_00c66650::Own_00c66650()
{}
void Own_00c66650::key_fn()
{}
Own_00c66650* make_00c66650()
{
    static Own_00c66650 o;
    return &o;
}

namespace fnv_00c66660 {
// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x14).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00c66660();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00c66660();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00c66660
// src: GUESS 0x00c66660 (confidence: low)
    virtual void AdjustThisAndForward_00c66660();
};

Derived::Derived()
{}
}  // namespace fnv_00c66660

namespace fnv_00c70810 {
// 'sub ecx,0x410; jmp FUN_00c70c60' == MSVC adjustor thunk (11 bytes, thiscall).
// Derived overrides a virtual that both bases declare; the second base's vtable gets a thunk
// that moves `this` back by the first base's size (0x410).
struct PrimaryBase
{
    virtual void FUN_00c70810();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
};

struct SecondaryBase
{
    virtual void FUN_00c70810();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00c70810
    virtual void FUN_00c70810();
};

Derived::Derived()
{}
}  // namespace fnv_00c70810

namespace fnv_00c70820 {
// sub ecx,0x3e0; jmp FUN_00c70c60
// MSVC this-adjusting (adjustor) thunk: a derived class overrides a virtual
// declared by both of its bases, so the secondary base's vtable slot holds a
// thunk that walks `this` back to the derived object (the size of the primary
// base, 0x3e0) and tail-jumps to the derived override.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00c70820();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00c70820();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00c70820
// src: GUESS 0x00c70820 (confidence: low)
    virtual void AdjustThisAndForward_00c70820();
};

Derived::Derived()
{}
}  // namespace fnv_00c70820

// @fnv 0x00c76030
void* __fastcall DeletePoseMapBase(PoseMapBase* self, void*, unsigned int flags)
{
    *reinterpret_cast<void**>(self) = &DAT_010c4c64;
    self->RemoveAll();
    NiFreeAlias(self->m_ppkHashTable);
    if (flags & 1)
        _g_memoryManager.Deallocate(self);
    return self;
}

extern volatile float DAT_01267b50;
extern float DAT_012677ac, DAT_01267b38, DAT_011afe60, DAT_011afe68, DAT_01267b14, DAT_01267b20;
extern unsigned int DAT_012677b8;
extern const float DAT_010162c0;
extern const double DAT_010290b8, DAT_01011590;
double FUN_00ec9e10(double);
inline float ceilf_(float _X)
{
    return ((float)FUN_00ec9e10((double)_X));
}
int hkMath_hkFloatToInt(float);
struct C66A00Res
{
    int f000;
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    int f088;
    int f08c;
    int f090;
    int f094;
    int f098;
    int f09c;
    int f0a0;
    int f0a4;
    int f0a8;
    int f0ac;
    int f0b0;
    int f0b4;
    int f0b8;
    int f0bc;
    int f0c0;
    int f0c4;
    int f0c8;
    int f0cc;
    int f0d0;
    int f0d4;
    int f0d8;
    int f0dc;
    int f0e0;
    int f0e4;
    int f0e8;
    int f0ec;
    int f0f0;
    int f0f4;
    int f0f8;
    int f0fc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    int f130;
    int f134;
    int f138;
    int f13c;
    int f140;
    int f144;
    int f148;
    int f14c;
    int f150;
    int f154;
    int f158;
    int f15c;
    int f160;
    int f164;
    int f168;
    int f16c;
    int f170;
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    int f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    int f1c4;
    int f1c8;
    int f1cc;
    int f1d0;
    int f1d4;
    int f1d8;
    int f1dc;
    int f1e0;
    float f1e4;
    float f1e8;
    int f1ec;
    int f1f0;
    int f1f4;
    int f1f8;
    int f1fc;
    int f200;
    int f204;
    int f208;
    int f20c;
    int f210;
    int f214;
    int f218;
    int f21c;
    int f220;
    int f224;
    int f228;
    int f22c;
    float f230;
    float f234;
    int f238;
    int f23c;
    int f240;
    int f244;
    int f248;
    int f24c;
    int f250;
    int f254;
    int f258;
    int f25c;
    int f260;
    int f264;
    int f268;
    int f26c;
    int f270;
    int f274;
    int f278;
    int f27c;
    int f280;
    int f284;
    int f288;
    int f28c;
    int f290;
    int f294;
    int f298;
    int f29c;
    int f2a0;
    int f2a4;
    int f2a8;
    int f2ac;
    int f2b0;
    int f2b4;
    int f2b8;
    int f2bc;
    int f2c0;
    int f2c4;
    int f2c8;
    int f2cc;
    int f2d0;
    int f2d4;
    int f2d8;
    int f2dc;
    int f2e0;
    int f2e4;
    int f2e8;
    int f2ec;
    int f2f0;
    int f2f4;
    int f2f8;
    int f2fc;
    float f300;
};

struct C66A00This
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual C66A00Res* Unk_25();
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    float f088;
    float f08c;
    void bhkWorld_ScaleSolverInfo();
};

// Depending on whether DAT_012677b8 is 2, computes a step count, its reciprocal and interval values from DAT globals and stores them in the Unk_25() object.
// @fnv 0x00c66a00
// src: COMMUNITY 0x00c66a00
void C66A00This::bhkWorld_ScaleSolverInfo()
{
    C66A00Res* world = this ? Unk_25() : 0;
    if (DAT_012677b8 != 2)
    {
        double ratio = (float)(DAT_012677ac / DAT_01267b38);
        float scaled = (float)(4.0 * ratio);
        float clamped = scaled < DAT_01011590 ? DAT_010162c0 : scaled;
        int steps = (int)clamped;
        world->f2f4 = steps;
        world->f300 = 1.0f / steps;
        DAT_01267b50 = DAT_011afe60;
        const float& blend = const_cast<const float&>(DAT_01267b50);
        float interval = (float)((1.0 - blend) * DAT_010290b8 + ratio * blend * DAT_010290b8);
        world->f1e4 = interval;
        world->f230 = world->f1e8 / interval;
        world->f234 = interval / world->f1e8;
    }
    else
    {
        float ratio = DAT_011afe68 / DAT_01267b14;
        float steps = ceilf_(ratio);
        float interval = DAT_01267b14;
        if (steps < DAT_01267b20)
        {
            steps = DAT_01267b20;
            interval = DAT_011afe68 / DAT_01267b20;
        }
        float first = world->f1e4;
        f088 = first;
        float adjustedFirst = (float)(first + (DAT_011afe68 / (interval * steps) - 1.0));
        float second = world->f1e8;
        f08c = second;
        float adjustedSecond = (float)(second + (DAT_011afe68 / (interval * steps) - 1.0));
        world->f1e4 = adjustedFirst;
        world->f1e8 = adjustedSecond;
        int count = hkMath_hkFloatToInt(steps);
        world->f2f4 = count;
        world->f300 = 1.0f / count;
    }
}

struct C67320Vec4
{
    __m128 v;
    void operator=(const C67320Vec4& rhs)
    {
        v = rhs.v;
    }
    __forceinline void Scale(__m128 s)
    {
        v = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), v);
    }
    bool Near(const C67320Vec4& rhs, float epsilon) const;
};
struct C67320Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float amount;
    float scale;
};
struct C67320Node
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void GetPosition(C67320Vec4*);
    virtual void v54();
    virtual void SetPosition(const C67320Vec4*);
};
struct C67320Root
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
    virtual C67320Node* GetNode();
};
struct C67320Source
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
    virtual C67320Info* GetInfo();
    int unk04;
    int unk08;
    int unk0c;
    C67320Root* root;
};
struct C67320Params
{
    int unk00;
    int unk04;
    int unk08;
    C67320Vec4* vector;
};

extern float DAT_01017d10;
extern float DAT_01017d00;
__forceinline bool C67320Vec4::Near(const C67320Vec4& rhs, float epsilon) const
{
    C67320Vec4 diff;
    diff.v = _mm_sub_ps(v, rhs.v);
    diff.v = _mm_and_ps(diff.v, *reinterpret_cast<const __m128*>(&DAT_01017d10));
    __m128 eps = _mm_set_ps1(epsilon);
    return (_mm_movemask_ps(_mm_cmple_ps(diff.v, eps)) & 7) == 7;
}
// Adds params->vector to the node position; if info->amount < 1 it scales by info->scale first and skips when amount is 0 or the scaled vector is near zero.
// @fnv 0x00c67320
// src: COMMUNITY 0x00c67320
void __cdecl bhkWorld_ShiftPosition(C67320Source* source, C67320Params* params)
{
    C67320Info* info = source->GetInfo();
    C67320Root* root = source->root;
    if (!root)
        return;
    C67320Node* __restrict node = root->GetNode();
    if (!node || !params->vector)
        return;
    C67320Vec4 delta;
    delta.v = params->vector->v;
    if (info && info->amount < 1.0f)
    {
        if (info->amount == 0.0f)
            return;
        float scale = info->scale;
        delta.Scale(_mm_load_ss(&scale));
        if (delta.Near(*reinterpret_cast<const C67320Vec4*>(&DAT_01267e30), DAT_01017d00))
            return;
    }
    C67320Vec4 position;
    node->GetPosition(&position);
    position.v = _mm_add_ps(position.v, delta.v);
    node->SetPosition(&position);
}

extern unsigned int DAT_011b0808;
extern float DAT_01267bcc;
extern __declspec(thread) int g_audioThreadMode;
struct MyAlloc
{
    virtual void v00();
    virtual void* v04(unsigned int size);
};
struct AddRefT
{
    void FUN_00c90510();
};
extern CallbackTarget* DAT_01267bb8;
extern int DAT_010c4944;
extern int DAT_010c496c;
extern float DAT_01267e30;
struct Vec4f
{
    __m128 v;
};
struct ThreadScope
{
    int previous;
    ThreadScope() : previous(g_audioThreadMode)
    {
        g_audioThreadMode = 16;
    }
    ~ThreadScope()
    {
        g_audioThreadMode = previous;
    }
};
struct AllocHeader
{
    void* m_ppVirtualMethodTable;
    unsigned short m_iElementCount;
    unsigned short m_refs;
};
struct EntryBase
{
    static void* operator new(unsigned int n)
    {
        hkMemoryRouter* h = hkMemoryRouter_getInstance();
        void* p = ((MyAlloc*)h->m_heap)->v04(n);
        ((AllocHeader*)p)->m_iElementCount = (unsigned short)n;
        return p;
    }
    static void operator delete(void* p, unsigned int n);
};
struct FUN_00cbc460 : EntryBase
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    FUN_00cbc460();
    void registerState(hkReferencedObject* obj, int id);
};
struct FUN_00cd47e0 : EntryBase
{
    int unk00, unk04, unk08;
    FUN_00cd47e0();
};
struct FUN_00cd44c0 : EntryBase
{
    int unk00, unk04;
    FUN_00cd44c0();
};
struct FUN_00cd4260 : EntryBase
{
    int unk00, unk04;
    FUN_00cd4260();
};
struct FUN_00cd3f90 : EntryBase
{
    int unk00, unk04, unk08;
    FUN_00cd3f90();
};
struct FUN_00cd3c90 : EntryBase
{
    int unk00, unk04;
    FUN_00cd3c90();
};
static void* AllocEntry(unsigned int size)
{
    hkMemoryRouter* h = hkMemoryRouter_getInstance();
    void* p = ((MyAlloc*)h->m_heap)->v04(size);
    ((AllocHeader*)p)->m_iElementCount = (unsigned short)size;
    return p;
}
struct RefPtr
{
    CallbackTarget* p;
    RefPtr() : p(0)
    {}
    ~RefPtr()
    {
        if (p)
            ((CallbackTarget*)p)->FUN_00c905b0();
    }
    RefPtr& operator=(CallbackTarget* mgr)
    {
        if (mgr)
            ((AddRefT*)mgr)->FUN_00c90510();
        if (p)
            ((CallbackTarget*)p)->FUN_00c905b0();
        p = mgr;
        return *this;
    }
};
struct FUN_00c6cde0
{
    FUN_00c6cde0();
    ~FUN_00c6cde0();
};
struct InitialDefaults
{
    int m_80;
    int m_84;
    int m_88;
    volatile float m_8c;
    volatile float m_90;
    char m_94;
    char m_95;
    char m_96;
    char m_97;
    char m_98;
    char m_99;
    char m_9a;
    char m_9b;
    int m_9c;
    int m_a0;
    InitialDefaults()
    {
        m_80 = 0;
        m_84 = 0;
        m_8c = 0.0f;
        m_90 = 1.0f;
        m_88 = 0;
        m_95 = 0;
        m_96 = 0;
        m_97 = 0;
        m_98 = 0;
        m_9c = 0;
        m_a0 = 0;
    }
};
struct FUN_00c6da50 : FUN_00c6cde0
{
    Vec4f m_00;
    Vec4f m_10;
    float m_20;
    float m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    float m_40;
    float m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    float m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    InitialDefaults defaults;
    RefPtr m_a4;
    float m_a8;
    float m_ac;
    int m_b0;
    int m_b4;
    FUN_00c6da50(bool a1);
};
// Initializes fields and a wrapping counter; if a1, creates the global DAT_01267bb8 with seven entries on first use and stores it in m_a4.
// @fnv 0x00c6da50
FUN_00c6da50::FUN_00c6da50(bool a1)
{
    m_a8 = (float)(DAT_01267bcc * 31.0);
    m_b0 = 1;
    m_b4 = 0;
    m_ac = 1.0f;
    ThreadScope scope;
    int cnt = DAT_011b0808 + 1;
    cnt &= 0xffff;
    DAT_011b0808 = cnt;
    if (cnt == 0)
    {
        DAT_011b0808 = 10;
        cnt = 10;
    }
    m_58 = 100.0f;
    defaults.m_84 = (cnt << 16) | 0x1e;
    m_54 = 4;
    m_00.v = *(const __m128*)&DAT_01267e30;
    m_10.v = *(const __m128*)&DAT_01267e30;
    m_24 = 0.0f;
    m_40 = 0.0f;
    m_44 = 0.0f;
    m_48 = 0;
    m_20 = 1.0f;
    if (a1)
    {
        if (DAT_01267bb8 == 0)
        {
            FUN_00cbc460* sm = new FUN_00cbc460();
            DAT_01267bb8 = (CallbackTarget*)sm;
            FUN_00cd47e0* pEntry0 = new FUN_00cd47e0();
            ((FUN_00cbc460*)DAT_01267bb8)->registerState((hkReferencedObject*)pEntry0, 0);
            ((CallbackTarget*)pEntry0)->FUN_00c905b0();
            FUN_00cd44c0* pEntry5 = new FUN_00cd44c0();
            ((FUN_00cbc460*)DAT_01267bb8)->registerState((hkReferencedObject*)pEntry5, 5);
            ((CallbackTarget*)pEntry5)->FUN_00c905b0();
            FUN_00cd4260* pEntry1 = new FUN_00cd4260();
            ((FUN_00cbc460*)DAT_01267bb8)->registerState((hkReferencedObject*)pEntry1, 1);
            ((CallbackTarget*)pEntry1)->FUN_00c905b0();
            FUN_00cd3f90* pEntry2 = new FUN_00cd3f90();
            ((FUN_00cbc460*)DAT_01267bb8)->registerState((hkReferencedObject*)pEntry2, 2);
            ((CallbackTarget*)pEntry2)->FUN_00c905b0();
            char* pEntry3 = (char*)AllocEntry(8);
            ((AllocHeader*)pEntry3)->m_refs = 1;
            ((AllocHeader*)pEntry3)->m_ppVirtualMethodTable = &DAT_010c4944;
            ((FUN_00cbc460*)DAT_01267bb8)->registerState((hkReferencedObject*)pEntry3, 3);
            ((CallbackTarget*)pEntry3)->FUN_00c905b0();
            char* pEntry4 = (char*)AllocEntry(8);
            ((AllocHeader*)pEntry4)->m_refs = 1;
            ((AllocHeader*)pEntry4)->m_ppVirtualMethodTable = &DAT_010c496c;
            ((FUN_00cbc460*)DAT_01267bb8)->registerState((hkReferencedObject*)pEntry4, 4);
            ((CallbackTarget*)pEntry4)->FUN_00c905b0();
            FUN_00cd3c90* pEntry6 = new FUN_00cd3c90();
            ((FUN_00cbc460*)DAT_01267bb8)->registerState((hkReferencedObject*)pEntry6, 6);
            ((CallbackTarget*)pEntry6)->FUN_00c905b0();
        }
        m_a4 = DAT_01267bb8;
    }
}

struct __declspec(align(16)) C6E180Vec4
{
    __m128 vector;
};

struct C6E180Transform
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_vScale;
    int unk14;
    int unk18;
    int unk1c;
    C6E180Vec4 m_translate;
    C6E180Vec4 m_rotate;
};

struct C6E180Cast
{
    int unk00;
    int unk04;
    C6E180Transform* m_kMotionTransform;
};

class GlobalObjectO2_00a7b610
{
  public:
    int unk00;
};

struct C6E180Object
{
    C6E180Cast* __thiscall FUN_00653290(const GlobalObjectO2_00a7b610* pType);
};

extern GlobalObjectO2_00a7b610 g_0126832c;
extern float DAT_010c72bc;
extern float DAT_01267e30;

struct C6E180Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    C6E180Object* m_pkNode;

    void __thiscall bhkCharacterController_SetCapsuleRadius(float fNewScale);
};

// Sets the motion transform's scale to fNewScale, adding (old - new scale) to the translate Z component and subtracting it from the rotate Z component.
// @fnv 0x00c6e180
// src: COMMUNITY 0x00c6e180
void __thiscall C6E180Owner::bhkCharacterController_SetCapsuleRadius(float fNewScale)
{
    if (m_pkNode)
    {
        C6E180Cast* pkCast = m_pkNode->FUN_00653290(&g_0126832c);
        if (pkCast)
        {

            float delta =
                (pkCast->m_kMotionTransform ? pkCast->m_kMotionTransform->m_vScale : DAT_010c72bc) - fNewScale;
            C6E180Vec4 kPos;
            kPos.vector = (pkCast->m_kMotionTransform ? pkCast->m_kMotionTransform->m_translate
                                                      : *(const C6E180Vec4*)&DAT_01267e30)
                              .vector;
            C6E180Vec4 kRot;
            kRot.vector =
                (pkCast->m_kMotionTransform ? pkCast->m_kMotionTransform->m_rotate : *(const C6E180Vec4*)&DAT_01267e30)
                    .vector;
            kPos.vector.m128_f32[2] = kPos.vector.m128_f32[2] + delta;
            kRot.vector.m128_f32[2] = kRot.vector.m128_f32[2] - delta;

            if (pkCast->m_kMotionTransform)
            {
                C6E180Transform* t = pkCast->m_kMotionTransform;
                C6E180Vec4 value = kPos;
                t->m_translate.vector = value.vector;
                t->m_translate.vector.m128_f32[3] = t->m_vScale;
            }
            if (pkCast->m_kMotionTransform)
            {
                C6E180Transform* t = pkCast->m_kMotionTransform;
                C6E180Vec4 value = kRot;
                t->m_rotate.vector = value.vector;
                t->m_rotate.vector.m128_f32[3] = t->m_vScale;
            }
            if (pkCast->m_kMotionTransform)
            {
                pkCast->m_kMotionTransform->m_vScale = fNewScale;
            }
        }
    }
}

class NiD3DPixelShader;
namespace fnv_00c705c0 {
extern "C" void _ReadWriteBarrier();
extern int DAT_010c49c4, DAT_010c49b4, DAT_010c4998, DAT_010c446c;
struct TargetWorld
{
    unsigned int unk000;
    unsigned int unk004;
    Data* m_data;
};
struct FUN_00cac980_Holder
{
    TargetWorld* hkpCharacterProxy_getShapePhantom();
    void RemoveItem(void*);
};
struct DtorBase
{
    virtual void baseMethod();
    unsigned int unk004;
    FUN_00cac980_Holder* m_object;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    void FUN_00cabf50();
    ~DtorBase();
};
struct SecondaryBase
{
    virtual void secondaryMethod();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    void hkpCharacterContext_UpdateFields_00ca95e0();
    ~SecondaryBase();
};
struct ListenerBase
{
    virtual void listenerMethod();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    ~ListenerBase()
    {}
};
} // namespace fnv_00c705c0
template <> NiPointer<NiD3DPixelShader>::~NiPointer();
inline void hkReferencedObject::removeReference() const
{
    reinterpret_cast<CallbackTarget*>(const_cast<hkReferencedObject*>(this))->FUN_00c905b0();
}
namespace fnv_00c705c0 {
struct HavokPointer
{
    hkReferencedObject* p;
    void reset()
    {
        if (p)
            static_cast<const hkReferencedObject*>(p)->removeReference();
        p = 0;
    }
    ~HavokPointer()
    {
        reset();
    }
};
struct Allocator705
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void*, unsigned int);
};
struct Array705
{
    void* data;
    unsigned int count;
    unsigned int capacity;
    ~Array705()
    {
        hkMemoryRouter* holder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        Allocator705* allocator = reinterpret_cast<Allocator705*>(holder->m_heap);
        _ReadWriteBarrier();
        count = 0;
        if (!(capacity & 0x80000000))
        {
            void* memory = data;
            allocator->Free(memory, (capacity & 0x3fffffff) * 0x70);
        }
        data = 0;
        capacity = 0x80000000;
    }
};
void __fastcall BSFadeNode_FreeLinkedNodesRecursively(void*);
struct Last705
{
    unsigned int value;
    ~Last705()
    {
        BSFadeNode_FreeLinkedNodesRecursively(this);
    }
};
struct Scope705
{
    unsigned int previous;
    Scope705(Array705& a) : previous(hkThreadModeSlots[173])
    {
        _ReadWriteBarrier();
        hkThreadModeSlots[173] = 16;
        a.count = 0;
    }
    ~Scope705()
    {
        hkThreadModeSlots[173] = previous;
    }
};
struct FUN_00c705c0 : DtorBase, SecondaryBase, ListenerBase
{
    virtual void baseMethod();
    virtual void secondaryMethod();
    virtual void listenerMethod();
    NiPointer<NiRefObject> ref594;
    NiPointer<NiRefObject> ref598;
    unsigned int unk59c, unk5a0;
    NiPointer<NiD3DPixelShader> shaders[2];
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    HavokPointer ref60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    HavokPointer ref630;
    unsigned int unk634;
    HavokPointer ref638;
    Array705 array;
    Last705 last;
    void bhkCharacterController_UnMarkWrite();
    ~FUN_00c705c0();
};
// Destructor that, if world data's m_350 is set, removes this from m_object, then resets the ref630, ref638 and ref60c Havok pointers.
// @fnv 0x00c705c0
FUN_00c705c0::~FUN_00c705c0()
{
    Scope705 mode(array);
    TargetWorld* world = m_object ? m_object->hkpCharacterProxy_getShapePhantom() : 0;
    Data* data = world->m_data;
    if (data && *reinterpret_cast<void**>(reinterpret_cast<char*>(data) + 0x350))
    {
        FUN_00cac980_Holder* object = m_object;
        if (object)
        {
            bhkCharacterController_UnMarkWrite();
            object->RemoveItem(static_cast<ListenerBase*>(this));
            bhkCharacterController_UnMarkWrite();
        }
    }
    ref630.reset();
    ref638.reset();
    ref60c.reset();
}
}  // namespace fnv_00c705c0

extern "C" void _ReadWriteBarrier(void);
struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_0126832c;
extern const float DAT_01016410;
extern float DAT_010c72bc;
struct C70940Vec
{
    __m128 q;
};
extern float DAT_01267e30;
struct C70940Node
{
    int unk00, unk04, unk08, unk0c;
    float scale;
    int unk14, unk18, unk1c;
    C70940Vec vecA, vecB;
    __forceinline void SetA(const C70940Vec& value)
    {
        vecA = value;
        vecA.q.m128_f32[3] = scale;
    }
    __forceinline void SetB(const C70940Vec& value)
    {
        vecB = value;
        vecB.q.m128_f32[3] = scale;
    }
};
struct C70940Cast
{
    int unk00, unk04;
    C70940Node* node;
    __forceinline float GetScale() const
    {
        return node ? node->scale : DAT_010c72bc;
    }
};
struct C70940Src
{
    C70940Cast* FUN_00653290(GlobalObjectO2_00a7b610 const*);
};
struct C70940Obj
{
    void SetMode(int state);
    void bhkCharacterController_ChangeSize(float delta);
    __forceinline unsigned char GetFlags() const
    {
        return flags414 >> 20;
    }
    __forceinline float GetCurrent() const
    {
        return current5f8;
    }
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    unsigned int flags414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int state5a0;
    C70940Src* src5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    float target5f0;
    int unk5f4;
    float current5f8;
    int unk5fc;
    int mode600;
};
// While mode600 is 2, moves the cast scale toward GetCurrent() by delta*5.0, shifts vecA and vecB Z, then updates mode600 and state5a0 on arrival.
// @fnv 0x00c70940
// src: XBOX_PDB 0x00c70940
void C70940Obj::bhkCharacterController_ChangeSize(float delta)
{
    if (mode600 != 2)
        return;
    float value;
    C70940Cast* cast;
    if (src5a4 && (cast = src5a4->FUN_00653290(&g_0126832c)) != 0)
    {
        if (GetFlags() & 1)
            delta = DAT_01016410;
        C70940Node* node = cast->node;
        float step = cast->GetScale();
        value = step;
        step = delta * 5.0;
        if (value > GetCurrent())
        {
            float candidate = value - step;
            if (candidate <= GetCurrent())
            {
                step = GetCurrent() - value;
                value = GetCurrent();
            }
            else
            {
                step = -step;
                value = candidate;
            }
        }
        else
        {
            _ReadWriteBarrier();
            float candidate = *static_cast<volatile float*>(&step) + value;
            if (candidate >= GetCurrent())
            {
                step = GetCurrent() - value;
                value = GetCurrent();
            }
            else
            {
                value = candidate;
            }
        }
        C70940Vec a;
        a.q = (node ? &node->vecA : reinterpret_cast<const C70940Vec*>(&DAT_01267e30))->q;
        C70940Vec b;
        b.q = (node ? &node->vecB : reinterpret_cast<const C70940Vec*>(&DAT_01267e30))->q;
        a.q.m128_f32[2] -= step;
        b.q.m128_f32[2] += step;
        if (node)
        {
            node->vecA = a;
            node->vecA.q = a.q;
            node->vecA.q.m128_f32[3] = node->scale;
        }
        C70940Node* nodeB = cast->node;
        if (nodeB)
        {
            nodeB->vecB = b;
            nodeB->vecB.q = b.q;
            nodeB->vecB.q.m128_f32[3] = nodeB->scale;
        }
        if (cast->node)
            cast->node->scale = value;
    }
    else
    {
        value = GetCurrent();
    }
    if (value == GetCurrent())
    {
        if (value == target5f0)
        {
            if (state5a0 != 2)
            {
                SetMode(state5a0);
                state5a0 = 2;
            }
            mode600 = 0;
        }
        else
        {
            mode600 = 1;
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

extern __declspec(thread) unsigned int t_uiMemContextC73;
inline AutoMemContext::AutoMemContext(int context)
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(t_uiMemContextC73);
    t_uiMemContextC73 = context;
}
inline AutoMemContext::~AutoMemContext()
{
    t_uiMemContextC73 = m_eMemoryContext;
}

struct EntryC73
{
    int iA;
    int iB;
};
template <> __forceinline hkArray<EntryC73>::~hkArray()
{
    hkMemoryAllocator& kHeap = GetRouterHeap(hkMemoryRouter::getInstance());
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        kHeap.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(EntryC73));
}

struct __declspec(align(16)) DescriptorC73
{
    DescriptorC73();
    int iValue;
    void* pvHandle;
    int unk08;
    hkArray<EntryC73> kArray;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
};

struct PropertyC73
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    short unk14;
    char bEnabled;
    char unk17;
    int Configure(void*, int);
};
struct InputC73
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    void* pvHandle;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    int unk84;
    PropertyC73* pkProperty;
    float fValue8c;
    float fValue90;
    char unk94;
    char unk95;
    char unk96;
    char bFlag97;
    char bFlag98;
    char unk99;
    char unk9a;
    char unk9b;
    int iValue9c;
    int unka0;
    int unka4;
    float fValuea8;
    float fValueac;
    int unkb0;
    int iValueb4;
    float GetA() const
    {
        return fValuea8;
    }
    float GetB() const
    {
        return fValueac;
    }
};
struct ResourceC73
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void SetProperty(PropertyC73*);
    volatile long m_lRefs;
    void* pvHandle;
    int unk0c;
    int unk10;
    int unk14;
    ResourceC73(DescriptorC73*);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_lRefs))
            v004();
    }
};
struct FlagsC73
{
    int unk00;
    unsigned int m_uiValue1;
    void SetBit(unsigned int b, bool on)
    {
        if (on)
            m_uiValue1 |= b;
        else
            m_uiValue1 &= ~b;
    }
};
struct NodeC73
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    bool m_bDecalsEnabled;
    void Apply(FlagsC73*);
};
int __cdecl MakeValueC73(float, float, float, float);
extern float DAT_010c44ac;
struct ControllerC73
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void Toggle(int);
    int unk004;
    NodeC73* pkNode;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    FlagsC73 kFlags;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    float fScale;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    int iValue520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    float fValue534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    float fValue54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    NiPointer<ResourceC73> kPrimary;
    ResourceC73* pkSecondary;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    int iValue604;
    void SetScale(float f)
    {
        fScale = f;
    }
    void Initialize(InputC73*);
    ResourceC73* GetSource();
    void Update(InputC73*);
    void Sync();
    void bhkCharacterController_Init(InputC73*);
};

// Initialises the controller from pkInput, configures its primary and secondary resources, copies input values, and applies flags to pkNode.
// @fnv 0x00c73ed0
// src: COMMUNITY 0x00c73ed0
void ControllerC73::bhkCharacterController_Init(InputC73* pkInput)
{
    AutoMemContext kContext(0x10);
    SetScale(pkInput->fValueac * pkInput->fValuea8);
    Initialize(pkInput);
    ResourceC73* pkCur = kPrimary.m_pObject;
    if (!pkCur)
    {
        DescriptorC73 kDesc;
        kDesc.iValue = pkInput->unk84;
        ResourceC73* pkSource = GetSource();
        kDesc.pvHandle = pkSource ? pkSource->pvHandle : 0;
        kPrimary = new ResourceC73(&kDesc);
    }
    if (pkInput->pkProperty)
    {
        if (kPrimary.m_pObject)
        {
            kPrimary.m_pObject->SetProperty(pkInput->pkProperty);
            ResourceC73* pkRes = kPrimary.m_pObject;
            PropertyC73* pkProp = pkInput->pkProperty;
            pkProp->Configure(pkRes, MakeValueC73(1.0f, 1.0f, 0.0f, DAT_010c44ac));
            if (pkInput->pkProperty->bEnabled)
                Toggle(0);
        }
        if (pkSecondary)
            pkSecondary->SetProperty(pkInput->pkProperty);
    }
    iValue520 = pkInput->iValue9c;
    fValue534 = pkInput->fValue8c;
    fValue54c = pkInput->fValue90;
    iValue604 = pkInput->iValueb4;
    pkInput->pvHandle = kPrimary.m_pObject ? kPrimary.m_pObject->pvHandle : 0;
    Update(pkInput);
    if (pkNode->m_bDecalsEnabled)
        pkNode->m_bDecalsEnabled = true;
    else
        pkNode->m_bDecalsEnabled = true;
    FlagsC73& kFlagsRef = kFlags;
    kFlagsRef.SetBit(0x2000000, pkInput->bFlag97 != 0);
    kFlagsRef.SetBit(0x4000000, pkInput->bFlag98 != 0);
    NodeC73* pkN = pkNode;
    if (pkN)
    {
        Sync();
        pkN->Apply(&kFlagsRef);
        Sync();
    }
}

struct Scalar74
{
    __m128 value;
    __forceinline Scalar74(__m128 v) : value(v)
    {}
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
struct Vec74
{
    __m128 value;
    __forceinline Scalar74 component(int i) const
    {
        switch (i)
        {
        case 0:
            return value;
        case 1:
            return _mm_shuffle_ps(value, value, 0x55);
        case 2:
            return _mm_shuffle_ps(value, value, 0xaa);
        default:
            return _mm_shuffle_ps(value, value, 0xff);
        }
    }
    __forceinline void cross(const Vec74& a, const Vec74& b)
    {
        __m128 p = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 q = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(p, q);
    }
    __forceinline void subtractScaled(const Scalar74& s, const Vec74& a)
    {
        value = _mm_sub_ps(value, _mm_mul_ps(s.broadcast(), a.value));
    }
    __forceinline void addScaled(const Scalar74& s, const Vec74& a)
    {
        value = _mm_add_ps(value, _mm_mul_ps(s.broadcast(), a.value));
    }
    __forceinline Scalar74 dot(const Vec74& a) const
    {
        __m128 p = _mm_mul_ps(value, a.value);
        __m128 h = _mm_add_ps(_mm_shuffle_ps(p, p, 0x4e), p);
        __m128 k = _mm_shuffle_ps(h, h, 0xb1);
        return _mm_add_ps(h, k);
    }
    __forceinline void splat(const Scalar74& s)
    {
        value = s.broadcast();
    }
    __forceinline void combine(const Vec74& xyz, const Vec74& w)
    {
        value = _mm_shuffle_ps(xyz.value, _mm_unpackhi_ps(xyz.value, w.value), 0xc4);
    }
};
struct Quat74
{
    Vec74 value;
    void setMulInverse(const Quat74& a, const Quat74& b);
};
// Combines quaternions a and b: xyz from b cross a, minus a.w times b, plus b.w times a, with w set from the 4D dot of a and b.
// @fnv 0x00c74ac0
// src: COMMUNITY 0x00c74ac0
void Quat74::setMulInverse(const Quat74& a, const Quat74& b)
{
    Vec74 xyz;
    xyz.cross(b.value, a.value);
    xyz.subtractScaled(a.value.component(3), b.value);
    xyz.addScaled(b.value.component(3), a.value);
    Vec74 w;
    w.splat(a.value.dot(b.value));
    value.combine(xyz, w);
}

inline float MulPart(float a, float b)
{
    return a * b;
}
inline float GetFade(unsigned char a)
{
    if (!a)
        return 1.0f;
    return 0.0f;
}
struct V3Local
{
    float x, y, z;
    float Y() const
    {
        return y;
    }
    float Z() const
    {
        return z;
    }
};
union V4Local
{
    __m128 q;
    struct
    {
        float x, y, z, w;
    };
};
static float DAT_01267c20;
void SetScaleLocal(float v)
{
    DAT_01267c20 = v;
}
extern float DAT_01267dfc;
extern const float DAT_010ec7f0[4];
struct SourceLocal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    V3Local position;
};
// A 16-byte position result of 0x00c7f840 (also bound to S00c78160_V4), not the 64-byte Transform.
struct TransformedPosition
{
    __m128 value;
    void hkVector4_setTransformedInversePos_00c7f840(void*, __m128*);
};
struct DescriptorLocal
{
    unsigned short w0, w1, w2, w3, w4, w5;
    float m0c;
    __m128 direction;
    float m20, m24, weight0, weight1, m30, m34, m38, m3c;
    __m128 position;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    void FUN_00c74ed0();
};
void __cdecl hkaTwoJointsIkSolver_solve(void*, DescriptorLocal*, void*);
struct StateLocal
{
    SourceLocal* source;
    float blend, weight;
    unsigned char active, fading;
    unsigned short unk0e;
    __m128 position, direction;
};
struct ControllerLocal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    void* target;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    StateLocal states[2];
    unsigned short ids[7];
    unsigned char active, unk21f;
    void bhkRagdollController_DoGrabIK(void* arg);
};
// For each active state, blends position when not fading, moves weight toward 1 (0 if fading), then deactivates it once faded out or emits via FUN_00cdbae0.
// @fnv 0x00c751f0
// src: COMMUNITY 0x00c751f0
void ControllerLocal::bhkRagdollController_DoGrabIK(void* arg)
{
    float zero = 0.0f;
    unsigned char result;
    unsigned short* idsAt = ids + 1;
    for (int i = 0; i < 2; ++i)
    {
        StateLocal* state = &states[i];
        if (state->active)
        {
            unsigned char fading = state->fading;
            float fadeTarget;
            if (!fading)
            {
                V3Local point = state->source->position;
                V4Local scaled;
                scaled.x = DAT_01267c20 * point.x;
                scaled.y = DAT_01267c20 * point.Y();
                scaled.z = DAT_01267c20 * point.Z();
                scaled.w = zero;
                __m128 direction = _mm_setr_ps(0.0f, 1.0f, 0.0f, 0.0f);
                if (state->weight > zero)
                {

                    __m128 blend = _mm_set1_ps(state->blend);
                    state->position =
                        _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(DAT_010ec7f0), blend), state->position),
                                   _mm_mul_ps(scaled.q, blend));
                    __m128 blend2 = _mm_shuffle_ps(_mm_load_ss(&state->blend), _mm_load_ss(&state->blend), 0);
                    state->direction =
                        _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(DAT_010ec7f0), blend2), state->direction),
                                   _mm_mul_ps(blend2, direction));
                }
                else
                {
                    state->position = *(__m128*)&scaled;
                    state->direction = direction;
                }
            }
            if (!state->fading)
                fadeTarget = 1.0f;
            else
                fadeTarget = zero;
            fadeTarget = (fadeTarget - state->weight) * DAT_01267dfc + state->weight;
            state->weight = fadeTarget;
            if (state->weight < 0.01f && fading)
            {
                state->fading = 0;
                state->weight = zero;
                state->active = 0;
            }
            else
            {
                TransformedPosition transformed;
                transformed.hkVector4_setTransformedInversePos_00c7f840(arg, &state->position);
                DescriptorLocal descriptor;
                descriptor.FUN_00c74ed0();
                descriptor.weight0 = state->weight;
                descriptor.weight1 = state->weight;
                descriptor.w0 = idsAt[-1];
                descriptor.w1 = idsAt[0];
                descriptor.w2 = idsAt[1];
                descriptor.direction = _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f);
                descriptor.position = transformed.value;
                hkaTwoJointsIkSolver_solve(&result, &descriptor, target);
            }
        }
        idsAt += 3;
    }
    if (!states[0].active && !states[1].active)
        active = 0;
}

#include <xmmintrin.h>
#include <math.h>
class Transform;
namespace fnv_00c77460 {
extern __m128 DAT_01017d10;
extern __m128 DAT_010ec7f0;
extern __m128 DAT_010c71e0;
extern const float DAT_01013ea4 = 0.01f;
extern const float DAT_01012054 = -1.0f;

struct __declspec(align(16)) Vec
{
    __m128 q;
    struct Component
    {
        const float& value;
        Component(const float& f) : value(f)
        {}
        operator double() const
        {
            return value;
        }
    };
    Component z() const
    {
        return Component(q.m128_f32[2]);
    }
    void FUN_00c7f7a0(const Vec*, const Transform*);
    __forceinline Vec& operator=(const Vec& b)
    {
        q = b.q;
        return *this;
    }
    void interpolate(const Vec& a, const Vec& b, const float& f)
    {
        __m128 t = _mm_load1_ps(&f);
        q = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, t), a.q), _mm_mul_ps(t, b.q));
    }
    int near3(const Vec& b, float eps) const
    {
        __m128 d = _mm_and_ps(_mm_sub_ps(q, b.q), DAT_01017d10);
        __m128 e = _mm_set1_ps(eps);
        return (_mm_movemask_ps(_mm_cmple_ps(d, e)) & 7) == 7;
    }
    __forceinline void normalize()
    {
        __m128 half = _mm_set_ss(0.5f), three = _mm_set_ss(3.0f), zero = _mm_set_ss(0.0f);
        __m128 sq = _mm_mul_ps(q, q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        __m128 len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), xy);
        __m128 mask = _mm_cmpeq_ss(len, zero);
        __m128 approx = _mm_rsqrt_ss(len);
        __m128 scale = _mm_andnot_ps(
            mask, _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, approx), approx))));
        q = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), q);
    }
    __forceinline void rotate(const Vec& rot, const Vec& dir)
    {
        __m128 r = _mm_shuffle_ps(rot.q, rot.q, 0xff);
        __m128 base = _mm_add_ps(DAT_010c71e0, _mm_mul_ps(r, r));
        __m128 ret = _mm_mul_ps(base, dir.q);
        __m128 prod = _mm_mul_ps(rot.q, dir.q);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
        ret = _mm_add_ps(ret, _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), rot.q));
        __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(rot.q, rot.q, 0xc9), _mm_shuffle_ps(dir.q, dir.q, 0xd2)),
                                  _mm_mul_ps(_mm_shuffle_ps(rot.q, rot.q, 0xd2), _mm_shuffle_ps(dir.q, dir.q, 0xc9)));
        ret = _mm_add_ps(ret, _mm_mul_ps(r, cross));
        q = _mm_add_ps(ret, ret);
    }
};
struct RayInput
{
    Vec from, to;
    bool collection;
    unsigned filter;
    int unk28, unk2c;
    RayInput() : collection(false)
    {}
};
struct RayOutput
{
    Vec normal;
    float fraction;
    int shapeKey, unk18, unk1c;
    int otherKey, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    void* object40;
    int unk44, unk48, unk4c;
    void* object50;
    int unk54, unk58, unk5c;
    RayOutput()
    {
        fraction = 1.0f;
        shapeKey = -1;
        object40 = 0;
        otherKey = -1;
        object50 = 0;
    }
};
struct PickData
{
    RayInput input;
    RayOutput output;
    Vec extra;
    int unkA0, unkA4, unkA8;
    bool flagAC;
    PickData(unsigned id)
    {
        unkA0 = 0;
        unkA4 = 0;
        unkA8 = 0;
        flagAC = false;
        input.filter = id;
    }
};
struct RayWorld
{
    void hkpCachingShapePhantomRay_castRay(const RayInput*, RayOutput*);
};

struct Body
{
    int unk00, unk04, unk08, unk0c;
    Transform* transform;
    int unk14, unk18;
    unsigned char* flags;
    Transform* hkaPose_calculateBoneModelSpace(int);
    Transform* getTransform()
    {
        if (!(*flags & 2))
            return transform;
        return hkaPose_calculateBoneModelSpace(0);
    }
};
struct CastObject
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual bool cast(PickData*);
};
struct RayRefObject
{
    int unk000;
    int unk004;
    RayRefObject* object;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    CastObject* world;
    CastObject* resolve()
    {
        if (this && object)
            return object->world;
        return 0;
    }
};
struct RefLink
{
    RayRefObject* object;
};
struct OwnerRef
{
    int unk00, unk04;
    RefLink* link;
};
struct CachedRay
{
    Vec from, to, normal;
    float fraction;
    int unk34, unk38, unk3c;
};
struct CacheGroup
{
    Vec header;
    CachedRay rays[3];
};
extern "C" void __cdecl FUN_00c82870(int, unsigned __int64);
struct ControllerRay
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    Vec position;

    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    OwnerRef* owner;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    unsigned filter;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    Body* body;
    int unk08c;
    RayWorld* world;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    bool useRayWorld;
    int unk228;
    CacheGroup* cache;
    int mode;
    int unk234;
    unsigned short rayIndex, groupIndex;
    int unk23c;
    bool keepNormal;
    bool* bhkRagdollController_castRay(bool* hitOut, const Vec& from, const Vec& to, float* fraction, Vec& normal);
    CastObject* pLoadedObject()
    {
        if (owner)
        {
            return owner->link->object->resolve();
        }
        return 0;
    }
};
// Reuses a cached ray result if from/to match, else casts via an object or ray world; writes hit, fraction and normal and updates the cache.
// @fnv 0x00c77460
// src: XBOX_PDB 0x00c77460
bool* ControllerRay::bhkRagdollController_castRay(bool* hitOut, const Vec& from, const Vec& to, float* fraction, Vec& normal)
{
    bool hit = false;
    if (cache[groupIndex].rays[rayIndex].fraction != DAT_01012054 &&
        cache[groupIndex].rays[rayIndex].from.near3(from, DAT_01013ea4) &&
        cache[groupIndex].rays[rayIndex].to.near3(to, DAT_01013ea4))
    {
        normal = cache[groupIndex].rays[rayIndex].normal;
        Vec previous;
        previous.interpolate(cache[groupIndex].rays[rayIndex].from, cache[groupIndex].rays[rayIndex].to,
                             cache[groupIndex].rays[rayIndex].fraction);
        *fraction = (from.z() - previous.z()) / (from.z() - to.z());
        hit = true;
    }
    else
    {
        unsigned filterId = filter;
        FUN_00c82870(39, 0x2002200e);
        unsigned computedFilter = (filterId << 16) | 39;
        PickData pick(computedFilter);
        pick.input.from = from;
        pick.extra.q = *reinterpret_cast<__m128*>(&DAT_01267e30);
        pick.input.to = to;
        if (!useRayWorld)
        {
            if (pLoadedObject()->cast(&pick))
            {
                *fraction = pick.output.fraction;
                Vec n = pick.output.normal;
                n.normalize();
                normal = n;
                hit = true;
            }
        }
        else if (world)
        {
            RayInput input;
            RayOutput output;
            input.filter = computedFilter;
            input.from = from;
            input.to = to;
            world->hkpCachingShapePhantomRay_castRay(&input, &output);
            if (output.object50)
            {
                *fraction = output.fraction;
                Vec n = output.normal;
                n.normalize();
                normal = n;
                hit = true;
            }
        }
    }
    Vec local;
    Vec contact;
    contact.interpolate(from, to, hit ? *fraction : 0.0f);
    if (!hit)
    {
        cache[groupIndex].rays[rayIndex].fraction = DAT_01012054;
    }
    else
    {
        local.FUN_00c7f7a0(&position, body->getTransform());
        Vec up;
        up.q = _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f);
        Vec rotated;
        rotated.rotate(*reinterpret_cast<const Vec*>(&reinterpret_cast<const ::Transform*>(body->getTransform())->m_f10), up);
        if (mode == 2 && fabsf(rotated.z()) > 0.2f)
        {
            if (contact.z() > local.z() - 2.0)
                *fraction = (from.z() - contact.z() + 2.0) / (from.z() - to.z());
        }
        if (!keepNormal)
            normal = up;
        cache[groupIndex].rays[rayIndex].from = from;
        cache[groupIndex].rays[rayIndex].to = to;
        cache[groupIndex].rays[rayIndex].normal = normal;
        cache[groupIndex].rays[rayIndex].fraction = *fraction;
    }
    ++rayIndex;
    *hitOut = hit;
    return hitOut;
}
}  // namespace fnv_00c77460

struct S00c79e20_StrPtr
{
    const char* m_str;
};
struct S00c79e20_Bone
{
    S00c79e20_StrPtr m_name;
    bool m_bLockTranslation;
};
struct S00c79e20_Skeleton
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S00c79e20_Bone* m_kBones;
    int m_iBoneCount;
};
struct S00c79e20_Mapping
{
    short m_sBoneA;
    short m_sBoneB;
    int unk04;
    int unk08;
    int unk0c;
    __m128 m_vTranslation;
    __m128 m_rotation;
    __m128 m_vScale;
};
struct S00c79e20_MapperData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    const S00c79e20_Bone& boneA(int i) const
    {
        return m_pSkeletonA->m_kBones[i];
    }
    const S00c79e20_Bone& boneB(int i) const
    {
        S00c79e20_Skeleton* s = m_pSkeletonB;
        return s->m_kBones[i];
    }
    S00c79e20_Skeleton* m_pSkeletonA;
    S00c79e20_Skeleton* m_pSkeletonB;
    S00c79e20_Mapping* m_kMappings;
    int m_numMappings;
    int size() const
    {
        return m_numMappings;
    }
};
template <class T> struct S00c79e20_RefPtr
{
    T* m_pRetainedObject;
    T* operator->() const
    {
        return m_pRetainedObject;
    }
    operator T*() const
    {
        return m_pRetainedObject;
    }
    T* val() const
    {
        return m_pRetainedObject;
    }
};
struct S00c79e20_Mapper
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00c79e20_MapperData* m_mappers[2];
};
struct S00c79e20_RTTI
{
    const char* m_name;
    const S00c79e20_RTTI* m_base;
};
extern S00c79e20_RTTI DAT_012683c8;
struct S00c79e20_Target
{
    virtual void v00();
    virtual void v04();
    virtual const S00c79e20_RTTI* GetRTTI() const;
    void* FUN_00653290(const S00c79e20_RTTI* rtti);
    bool IsKindOfType(const S00c79e20_RTTI* rtti) const
    {
        for (const S00c79e20_RTTI* r = GetRTTI(); r; r = r->m_base)
        {
            if (r == rtti)
                return true;
        }
        return false;
    }
};
static inline bool S00c79e20_IsKindOf(const S00c79e20_RTTI* rtti, const S00c79e20_Target* obj)
{
    return obj && obj->IsKindOfType(rtti);
}
struct S00c79e20_Node
{
    int unk00;
    int unk04;
    int unk08;
    S00c79e20_Target* m_target;
};
struct S00c79e20_Owner
{
    int unk00;
    int unk04;
    S00c79e20_Node** m_kNodeCollection;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* m_remap;
    S00c79e20_Target* GetTarget(int bone) const
    {
        int idx = m_remap[bone];
        if (idx < 0)
            return 0;
        S00c79e20_Node* n = m_kNodeCollection[idx];
        if (!n)
            return 0;
        return n->m_target;
    }
};
struct S00c79e20_Ostream
{
    void* m_vtbl;
    int m_iObjectReferenceCount;
    void* m_pStreamWriter;
    void FUN_00cb1600(char* buf, int size);
    S00c79e20_Ostream(char* buf, int size)
    {
        FUN_00cb1600(buf, size);
    }
    ~S00c79e20_Ostream()
    {
        FUN_00cc00e0();
    }
    void FUN_00cc00e0();
    S00c79e20_Ostream& ProcessAndReturnValue_00cc01c0(const char* s);
    S00c79e20_Ostream& WriteName(const S00c79e20_StrPtr& s);
    S00c79e20_Ostream& WriteFloat(float f);
    S00c79e20_Ostream& operator<<(const char* s)
    {
        return ProcessAndReturnValue_00cc01c0(s);
    }
    S00c79e20_Ostream& operator<<(const S00c79e20_StrPtr& s)
    {
        return WriteName(s);
    }
    S00c79e20_Ostream& operator<<(float f)
    {
        return WriteFloat(f);
    }
};
struct S00c79e20_Error
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void message(int type, int id, const char* desc, const char* file, int line);
};
extern S00c79e20_Error* DAT_01268360;
extern const float DAT_01013ea4;
extern const char str_010c4d7c[];
extern const char str_010c4d88[];
extern const char str_010c4d90[];
extern const char str_010c4db0[];
extern const char str_010c4d38[];

struct S00c79e20_SimdReal
{
    float m_vValue;
    S00c79e20_SimdReal(const __m128& r)
    {
        _mm_store_ss(&m_vValue, r);
    }
    operator const float&() const
    {
        return m_vValue;
    }
};
static __forceinline S00c79e20_SimdReal S00c79e20_Length3(const __m128& v)
{
    __m128 r = _mm_mul_ps(v, v);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(r, r, 0x55), r);
    r = _mm_shuffle_ps(r, r, 0xaa);
    r = _mm_add_ss(r, s);
    return _mm_sqrt_ss(r);
}

struct S00c79e20_Ctrl
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    S00c79e20_Owner* m_pOwnerObject;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    S00c79e20_RefPtr<S00c79e20_Mapper> m_mapper;
    bool bhkRagdollController_CheckMappersForWarnings();
};

// Logs mappings where bone B locks translation, no target matches and translation length exceeds 0.01; returns true if it logged or a mapper is missing.
// @fnv 0x00c79e20
// src: XBOX_PDB 0x00c79e20
bool S00c79e20_Ctrl::bhkRagdollController_CheckMappersForWarnings()
{
    bool warned = false;
    if (!m_mapper || !m_mapper->m_mappers[0] || !m_mapper->m_mappers[1])
    {
        warned = true;
        goto done;
    }

    for (int i = 0; i < m_mapper->m_mappers[0]->size(); i++)
    {
        const S00c79e20_Mapping& m = m_mapper->m_mappers[0]->m_kMappings[i];
        short a = m.m_sBoneA;
        short b = m.m_sBoneB;
        const S00c79e20_Bone& boneA = m_mapper->m_mappers[0]->boneA(a);
        const S00c79e20_Bone& boneB = m_mapper->m_mappers[0]->boneB(b);
        S00c79e20_Target* t = m_pOwnerObject->GetTarget(b);
        void* p = !t ? 0 : t->FUN_00653290(&DAT_012683c8);
        if (boneB.m_bLockTranslation && !p)
        {
            S00c79e20_SimdReal len = S00c79e20_Length3(m.m_vTranslation);
            if (len.m_vValue > 0.01f)
            {
                {
                    char buf[512];
                    S00c79e20_Ostream os(buf, sizeof(buf));
                    os.ProcessAndReturnValue_00cc01c0(str_010c4d7c)
                        .WriteName(boneA.m_name)
                        .ProcessAndReturnValue_00cc01c0(str_010c4d88)
                        .WriteName(boneB.m_name)
                        .ProcessAndReturnValue_00cc01c0(str_010c4d90)
                        .WriteFloat(len)
                        .ProcessAndReturnValue_00cc01c0(str_010c4db0);
                    DAT_01268360->message(1, 0xbadbadba, buf, str_010c4d38, 0xc1f);
                }
                warned = true;
            }
        }
    }
    for (int i = 0; i < m_mapper->m_mappers[1]->size(); i++)
    {
        const S00c79e20_Mapping& m = m_mapper->m_mappers[1]->m_kMappings[i];
        short a = m.m_sBoneA;
        short b = m.m_sBoneB;
        const S00c79e20_Bone& boneA = m_mapper->m_mappers[1]->boneA(a);
        const S00c79e20_Bone& boneB = m_mapper->m_mappers[1]->boneB(b);
        S00c79e20_Target* t = m_pOwnerObject->GetTarget(a);
        void* p = !t ? 0 : (t->IsKindOfType(&DAT_012683c8) ? t : 0);
        if (boneB.m_bLockTranslation && !p)
        {
            S00c79e20_SimdReal len = S00c79e20_Length3(m.m_vTranslation);
            if (len.m_vValue > 0.01f)
            {
                {
                    char buf[512];
                    S00c79e20_Ostream os(buf, sizeof(buf));
                    os.ProcessAndReturnValue_00cc01c0(str_010c4d7c)
                        .WriteName(boneA.m_name)
                        .ProcessAndReturnValue_00cc01c0(str_010c4d88)
                        .WriteName(boneB.m_name)
                        .ProcessAndReturnValue_00cc01c0(str_010c4d90)
                        .WriteFloat(len)
                        .ProcessAndReturnValue_00cc01c0(str_010c4db0);
                    DAT_01268360->message(1, 0xbadbadba, buf, str_010c4d38, 0xc39);
                }
                warned = true;
            }
        }
    }
done:
    return warned;
}

struct SmallFlag
{
    char value;
    SmallFlag()
    {}
    SmallFlag(bool b) : value(b)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct S_00c7fb50_item;
struct S_00c7fb50_portal;
struct S_00c7fb50_node;
struct S_00c7fb50_vtable
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    int(__thiscall* get_type)(S_00c7fb50_node*);
};
struct S_00c7fb50_node
{
    S_00c7fb50_vtable* vtbl;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    unsigned short index_1c;
    SmallFlag Broken(const S_00c7fb50_item* x) const;
};
struct S_00c7fb50_data
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    SmallFlag* bytes_1c;
};
struct S_00c7fb50_item
{
    void* unk00;
    void* unk04;
    void* unk08;
    S_00c7fb50_node* node_0c;
    void* unk10;
    void* next_14;
    void* next_18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    S_00c7fb50_data* data_30;
    const S_00c7fb50_node* Data() const
    {
        return node_0c;
    }
    S_00c7fb50_node* DataRw()
    {
        return node_0c;
    }
    S_00c7fb50_portal* BodyA() const
    {
        return (S_00c7fb50_portal*)next_14;
    }
    S_00c7fb50_portal* BodyB() const
    {
        return (S_00c7fb50_portal*)next_18;
    }
};
struct PortalEntry
{
    S_00c7fb50_item* item;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct S_00c7fb50_portal
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6c;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7c;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9c;
    void* unk_a0;
    void* unk_a4;
    void* unk_a8;
    PortalEntry* items_ac;
    unsigned short count_b0;
    int Count() const
    {
        return count_b0;
    }
    const PortalEntry& At(int i) const
    {
        return items_ac[i];
    }
};
extern "C" void _ReadWriteBarrier(void);
inline SmallFlag S_00c7fb50_node::Broken(const S_00c7fb50_item* x) const
{
    return x->data_30->bytes_1c[index_1c];
}
// Returns portal if all items are type 11 or broken type 12; otherwise recurses into the other body of the first item that is neither.
// @fnv 0x00c7fb50
// src: COMMUNITY 0x00c7fb50
S_00c7fb50_portal* __cdecl bhkUtilFunctions_FindConstrainedSystemRoot(S_00c7fb50_portal* portal)
{
    if (portal)
    {

        bool all = true;
        for (int i = 0; i < portal->Count(); ++i)
        {
            if (!all)
                break;
            const S_00c7fb50_node* node = portal->At(i).item->Data();
            all = node->vtbl->get_type((S_00c7fb50_node*)node) == 11;
        }
        if (!all)
        {
            for (int j = 0; j < portal->Count(); ++j)
            {
                S_00c7fb50_item* item = portal->At(j).item;
                if (item->Data()->vtbl->get_type((S_00c7fb50_node*)item->Data()) != 11)
                {
                    bool broken = false;
                    if (item->Data()->vtbl->get_type((S_00c7fb50_node*)item->Data()) == 12)
                    {
                        S_00c7fb50_node* data = item->DataRw();
                        broken = data->Broken(item);
                    }
                    if (!broken)
                    {
                        S_00c7fb50_portal* next = item->BodyA() == portal ? item->BodyB() : item->BodyA();
                        return bhkUtilFunctions_FindConstrainedSystemRoot(next);
                    }
                }
            }
        }
    }
    return portal;
}

namespace fnv_00c68de0 {
#include <windows.h>
// Reconstruction of FUN_00c68de0 (0x00c68de0, 74 bytes).
// __thiscall member of a Havok-style world object:
//   * +0x10 holds a pointer to a polymorphic object whose vtable slot 3 takes a float
//   * a TLS index global is passed to TlsGetValue, the result is fed to a byte-copy helper
//   * a global holder's +0x18 member is called virtually (vtable slot 9) when non-null
//   * the last statement tail-calls the inherited cleanup at 0x00c688b0

struct FNV_C68DE0_VA
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(float f);
};

struct FNV_C68DE0_VB
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
};

struct FNV_C68DE0_HOLDER
{
    void* h00;
    void* h04;
    void* h08;
    void* h0c;
    void* h10;
    void* h14;
    FNV_C68DE0_VB* h18;
};

extern unsigned int FNV_C68DE0_tlsIndex;
extern FNV_C68DE0_HOLDER* FNV_C68DE0_holder;

void __cdecl hkMonitorStream_reset(void* p);

struct FNV_C68DE0_OWNER
{
    void* o00;
    void* o04;
    void* o08;
    void* o0c;
    FNV_C68DE0_VA* o10;
    void ProcessEntries_00c688b0();
    void bhkWorld_UpdateDebugger();
};

// If o10 is set, calls o10->v3(0.0f), passes the TLS value to FUN_00cb0da0 and calls w9 on the holder's h18 object, then calls FUN_00c688b0.
// @fnv 0x00c68de0
// src: COMMUNITY 0x00c68de0
void FNV_C68DE0_OWNER::bhkWorld_UpdateDebugger()
{
    if (o10)
    {
        o10->v3(0.0f);
        hkMonitorStream_reset((void*)TlsGetValue(FNV_C68DE0_tlsIndex));
        FNV_C68DE0_VB* b = FNV_C68DE0_holder->h18;
        if (b)
        {
            b->w9();
        }
    }
    ProcessEntries_00c688b0();
}
}  // namespace fnv_00c68de0

namespace fnv_00c6aac0 {
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

extern __declspec(thread) int g_hkTlsMemoryState;

struct hkAllocatorStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void deallocate(void* p, int nbytes);
    template <class T> void bufFreeT(T* p, int n)
    {
        deallocate(p, n * sizeof(T));
    }
};

hkMemoryRouter* hkMemoryRouter_getInstance();

struct hkWorldObjectStub;

template <class T>
static __forceinline void hkLocalArrayStub_destroy(hkArrayBase<T>& self);

template <class T>
static __forceinline void hkLocalArrayStub_destroy(hkArrayBase<T>& self)
{
        hkMemoryRouter* router = hkMemoryRouter_getInstance();
        hkAllocatorStub* alloc = reinterpret_cast<hkAllocatorStub*>(router->m_heap);
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc->deallocate(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

struct hkLocalArrayStubPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { hkLocalArrayStub_destroy(self); }
};

struct hkEntityStub
{
    int unk00;
    int unk04;
    struct ActionWorld* m_pOwningWorld;
};

// 0x00c97370 belongs to Havok hkpWorld (action insertion), not the bhkWorld wrapper.
struct ActionWorld
{
    void AddEntityStub(struct hkEntityRefStub* e);
};

struct hkEntityRefStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void GetConstraints(hkArray<hkEntityStub*, hkLocalArrayStubPolicy>* out);
    int unk04;
    ActionWorld* m_pOwningWorld;
    void removeReference();
};

struct TlsStateScope
{
    int m_saved;
    TlsStateScope()
    {
        m_saved = g_hkTlsMemoryState;
        g_hkTlsMemoryState = 0x10;
    }
    ~TlsStateScope()
    {
        g_hkTlsMemoryState = m_saved;
    }
};

struct FUN_00c6aac0_Base
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual ActionWorld* GetWorld();
};

struct FUN_00c6aac0_Owner : FUN_00c6aac0_Base
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    hkEntityRefStub** m_pDataAtOffset94;
    unsigned int m_pendingCount;

    void bhkWorld_AddBatchedActions();
};

// @fnv 0x00c6aac0
// src: COMMUNITY 0x00c6aac0
void FUN_00c6aac0_Owner::bhkWorld_AddBatchedActions()
{
    TlsStateScope scope;
    if (m_pendingCount > 0)
    {
        if (m_pendingCount >= 100)
            m_pendingCount = 100;
        ActionWorld* world = GetWorld();
        if (world)
        {
            for (unsigned int i = 0; i < m_pendingCount; i++)
            {
                if (m_pDataAtOffset94[i] && !m_pDataAtOffset94[i]->m_pOwningWorld)
                {
                    hkArray<hkEntityStub*, hkLocalArrayStubPolicy> list;
                    m_pDataAtOffset94[i]->GetConstraints(&list);
                    bool ok = true;
                    for (int j = 0; j < list.m_iElementCount; j++)
                    {
                        if (!ok)
                            break;
                        ok = list.m_data[j]->m_pOwningWorld == world;
                    }
                    if (ok)
                        world->AddEntityStub(m_pDataAtOffset94[i]);
                }
                if (m_pDataAtOffset94[i])
                    m_pDataAtOffset94[i]->removeReference();
            }
            fnv_zlib_memset(m_pDataAtOffset94, 0, m_pendingCount * 4);
            m_pendingCount = 0;
        }
    }
}
}  // namespace fnv_00c6aac0

extern float DAT_011b05a8;
extern __m128 DAT_010c71e0;

class S00c78160_Simd
{
  public:
    __forceinline S00c78160_Simd(const __m128& x) : m_vValue(x)
    {}
    __forceinline S00c78160_Simd(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }

  private:
    __m128 m_vValue;
};

struct S00c78160_Quat;
struct hkQsTransform;

class S00c78160_V4
{
  public:
    __forceinline S00c78160_V4()
    {}
    __forceinline S00c78160_V4(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline S00c78160_V4(const S00c78160_V4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const S00c78160_V4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline __m128& getQuad()
    {
        return m_vComponents;
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void add4(const S00c78160_V4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setAdd4(const S00c78160_V4& a, const S00c78160_V4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setSub4(const S00c78160_V4& a, const S00c78160_V4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const S00c78160_V4& a, const S00c78160_V4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(const S00c78160_Simd& s)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
    }
    __forceinline void addMul4(const S00c78160_V4& x, const S00c78160_V4& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setAddMul4(const S00c78160_V4& a, const S00c78160_V4& x, const S00c78160_V4& y)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setAddMul4(const S00c78160_V4& a, const S00c78160_V4& b, const S00c78160_Simd& r)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents));
    }
    __forceinline void setBroadcast(const S00c78160_V4& v, int i)
    {
        if (i == 0)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0);
        else if (i == 1)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 85);
        else if (i == 2)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 170);
        else if (i == 3)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 255);
    }
    __forceinline void broadcast(int i)
    {
        if (i == 0)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0);
        else if (i == 1)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 85);
        else if (i == 2)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 170);
        else if (i == 3)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 255);
    }
    __forceinline S00c78160_Simd dot3(const S00c78160_V4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 85), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 170), xySum);
    }
    __forceinline S00c78160_Simd length3() const
    {
        return _mm_sqrt_ss(this->dot3(*this).getQuad());
    }
    __forceinline S00c78160_Simd lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = this->dot3(*this).getQuad();
        const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const __m128 approx = _mm_rsqrt_ss(len2);
        const __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize3()
    {
        __m128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    __forceinline void setCross(const S00c78160_V4& v0, const S00c78160_V4& v1)
    {
        __m128 cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 201),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 210));
        __m128 cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 210),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 201));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void SetRotatedDirection(const S00c78160_Quat& quat, const S00c78160_V4& direction);
    void hkVector4_setTransformedInversePos_00c7f840(const hkQsTransform& t, const S00c78160_V4& v);
    void FUN_00c7f7a0(const hkQsTransform& t, const S00c78160_V4& v);

  private:
    __m128 m_vComponents;
};

struct S00c78160_Quat
{
    S00c78160_V4 m_vec;
    __forceinline const S00c78160_V4& getImag() const
    {
        return m_vec;
    }
};

__forceinline void S00c78160_V4::SetRotatedDirection(const S00c78160_Quat& quat, const S00c78160_V4& direction)
{
    S00c78160_V4 minusHalf;
    minusHalf.getQuad() = DAT_010c71e0;
    S00c78160_V4 qreal;
    qreal.setBroadcast(quat.m_vec, 3);
    S00c78160_V4 q2minus1;
    q2minus1.setAddMul4(minusHalf, qreal, qreal);
    S00c78160_V4 ret;
    ret.setMul4(direction, q2minus1);
    S00c78160_V4 imagDotDir;
    imagDotDir.getQuad() = quat.getImag().dot3(direction).getQuad();
    imagDotDir.broadcast(0);
    ret.addMul4(imagDotDir, quat.getImag());
    S00c78160_V4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);
    this->setAdd4(ret, ret);
}


#include "../../include/hkQsTransform.h"


struct S00c78160_Pose
{
    int unk00, unk04, unk08, unk0c;
    hkQsTransform* m_pModelPose;
    int unk14, unk18;
    unsigned int* m_pBoneFlags;
    const hkQsTransform& hkaPose_calculateBoneModelSpace(int boneIdx);
    const S00c78160_V4& hkaPose_accessBoneLocalSpace(int boneIdx);
    __forceinline const hkQsTransform& getBoneModelSpace(int boneIdx)
    {
        if (!(m_pBoneFlags[boneIdx] & 2))
            return m_pModelPose[boneIdx];
        return hkaPose_calculateBoneModelSpace(boneIdx);
    }
};

struct S00c78160_This
{
    int unk00, unk04, unk08, unk0c;
    hkQsTransform m_kMotionTransform;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84;
    S00c78160_Pose* m_pose;
    int unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    short unkb0;
    bool m_b2;
    char unkb3;
    int unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    S00c78160_V4 m_target;
    int unke0, unke4, unke8, unkec;
    S00c78160_Pose* m_f0;
    int unkf4, unkf8, unkfc, unk100, unk104, unk108, unk10c;
    int unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c;
    int unk130, unk134, unk138, unk13c, unk140;
    short m_bone;
    short unk146;
    int unk148, unk14c;
    S00c78160_V4 m_offset;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c;
    bool m_190;
    char unk191, unk192, unk193;
    int unk194, unk198, unk19c, unk1a0;
    bool m_1a4;
    void bhkRagdollController_AdjustCurrentTarget();
};

// @fnv 0x00c78160
// src: XBOX_PDB 0x00c78160
void S00c78160_This::bhkRagdollController_AdjustCurrentTarget()
{
    S00c78160_V4 direction;
    direction.hkVector4_setTransformedInversePos_00c7f840(m_kMotionTransform, m_target);
    direction.normalize3();
    S00c78160_V4 up(0.0f, 1.0f, 0.0f, 0.0f);
    m_1a4 = up.dot3(direction) < 0.0f;
    S00c78160_V4 position;
    if (m_b2 || m_1a4)
    {
        if (m_b2)
        {
            S00c78160_V4 offset = m_offset;
            offset.SetRotatedDirection(reinterpret_cast<const S00c78160_Quat&>(m_pose->getBoneModelSpace(m_bone).m_rotation), offset);
            offset.SetRotatedDirection(reinterpret_cast<const S00c78160_Quat&>(m_kMotionTransform.m_rotation), offset);
            offset.mul4(3.0f);
            position.setZero4();
            if (m_190)
                position.add4(m_f0->hkaPose_accessBoneLocalSpace(1));
            position.FUN_00c7f7a0(m_pose->getBoneModelSpace(m_bone), position);
            position.FUN_00c7f7a0(m_kMotionTransform, position);
            m_target.setAdd4(position, offset);
        }
        else
        {
            S00c78160_V4 local;
            local.hkVector4_setTransformedInversePos_00c7f840(m_kMotionTransform, m_target);
            float height = 5.0f;
            if (((float*)&local)[0] < 0.0f)
                height = -5.0f;
            position.setZero4();
            if (m_190)
            {
                const S00c78160_V4& head = m_f0->hkaPose_accessBoneLocalSpace(1);
                position.add4(head);
            }
            position.FUN_00c7f7a0(m_pose->getBoneModelSpace(m_bone), position);
            ((float*)&position)[0] += height;
            position.FUN_00c7f7a0(m_kMotionTransform, position);
            m_target = position;
        }
    }
    position.setZero4();
    if (m_190)
        position.add4(m_f0->hkaPose_accessBoneLocalSpace(1));
    position.FUN_00c7f7a0(m_pose->getBoneModelSpace(m_bone), position);
    position.FUN_00c7f7a0(m_kMotionTransform, position);
    S00c78160_V4 difference;
    difference.setSub4(m_target, position);
    float distance = difference.length3();
    difference.normalize3();
    if (distance > DAT_011b05a8)
        m_target.setAddMul4(position, difference, DAT_011b05a8);
}

#include <xmmintrin.h>
namespace fnv_00c79a50 {
extern const __m128 DAT_010c71e0;
extern const __m128 DAT_010c7170;
extern const __m128 DAT_010c44d0;
extern const __m128 DAT_010c4c00;
extern const __m128 DAT_010c4c10;

struct SceneTransform
{
    Mat3 rotation;
    LocalVec3 position;
    float scale;
};

__forceinline __m128 Dot3(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(p, p, 0x55);
    y = _mm_add_ss(y, p);
    __m128 z = _mm_shuffle_ps(p, p, 0xaa);
    return _mm_add_ss(z, y);
}
__forceinline __m128 Cross(const __m128& a, const __m128& b)
{
    __m128 x = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 y = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(x, y);
}
__forceinline __m128 Rotate(const __m128& q, const __m128& p)
{
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 cross = Cross(q, p);
    __m128 dot = Dot3(p, q);
    __m128 t = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), p);
    __m128 d = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    __m128 c = _mm_mul_ps(cross, w);
    __m128 sum = _mm_add_ps(c, _mm_add_ps(t, d));
    return _mm_add_ps(sum, sum);
}

__forceinline __m128 RotateInverseRaw(const __m128& q, const __m128& t)
{
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 cross = Cross(t, q);
    __m128 dot = Dot3(t, q);
    cross = _mm_mul_ps(cross, w);
    __m128 a = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), t);
    __m128 b = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    __m128 sum = _mm_add_ps(cross, _mm_add_ps(a, b));
    return _mm_add_ps(sum, sum);
}
struct SimdQuaternion;
class SimdVector
{
    __m128 quad;

  public:
    __forceinline operator __m128() const
    {
        return quad;
    }
    __forceinline __m128& Raw()
    {
        return quad;
    }
    __forceinline const __m128& Raw() const
    {
        return quad;
    }
    __forceinline void operator=(const SimdVector& v)
    {
        quad = v.quad;
    }
    __forceinline void operator=(const __m128& v)
    {
        quad = v;
    }
    __forceinline void Sum(const SimdVector& a, const SimdVector& b)
    {
        quad = _mm_add_ps(a.quad, b.quad);
    }
    __forceinline void Difference(const SimdVector& a, const SimdVector& b)
    {
        quad = _mm_sub_ps(a.quad, b.quad);
    }
    __forceinline void Product(const SimdVector& a, const SimdVector& b)
    {
        quad = _mm_mul_ps(a.quad, b.quad);
    }
    __forceinline void AddProduct(const SimdVector& a, const SimdVector& b)
    {
        quad = _mm_add_ps(quad, _mm_mul_ps(a.quad, b.quad));
    }
    __forceinline void AccumulateProduct(const SimdVector& a, const SimdVector& b, const SimdVector& c)
    {
        quad = _mm_add_ps(a.quad, _mm_mul_ps(b.quad, c.quad));
    }
    __forceinline void Negate(const SimdVector& v)
    {
        quad = _mm_xor_ps(v.quad, DAT_010c44d0);
    }
    __forceinline void Conjugate(const SimdVector& v)
    {
        quad = v.quad;
        quad = _mm_xor_ps(quad, DAT_010c4c00);
    }
    __forceinline void ClearW(const SimdVector& v)
    {
        quad = _mm_and_ps(v, DAT_010c4c10);
    }
    __forceinline void Broadcast(const SimdVector& v, int i)
    {
        if (i == 0)
            quad = _mm_shuffle_ps(v.quad, v.quad, 0);
        else
            quad = _mm_shuffle_ps(v.quad, v.quad, 0xff);
    }
    __forceinline __m128 Dot(const SimdVector& v) const
    {
        __m128 product = _mm_mul_ps(quad, v.quad);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    }
    __forceinline void Cross(const SimdVector& a, const SimdVector& b)
    {
        quad = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.quad, a.quad, 0xc9), _mm_shuffle_ps(b.quad, b.quad, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(a.quad, a.quad, 0xd2), _mm_shuffle_ps(b.quad, b.quad, 0xc9)));
    }
    __forceinline void Reciprocal3(const SimdVector& v);
    __forceinline void Rotate(const SimdQuaternion&, const SimdVector&);
    __forceinline void RotateBack(const SimdQuaternion&, const SimdVector&);
};
__forceinline __m128 RefineReciprocal(__m128 input)
{
    __m128 estimate = _mm_rcp_ps(input);
    return _mm_sub_ps(_mm_add_ps(estimate, estimate), _mm_mul_ps(_mm_mul_ps(estimate, input), estimate));
}
__forceinline void SimdVector::Reciprocal3(const SimdVector& v)
{
    SimdVector xyz1;
    xyz1.quad = _mm_shuffle_ps(v.quad, _mm_unpackhi_ps(v.quad, DAT_010c7170), 0xc4);
    quad = RefineReciprocal(xyz1.quad);
}
struct SimdQuaternion
{
    SimdVector q;
    __forceinline const SimdVector& Imaginary() const
    {
        return q;
    }
    __forceinline void Inverse(const SimdQuaternion& other)
    {
        q.Conjugate(other.Imaginary());
    }
    void setMul(const SimdQuaternion*, const SimdQuaternion*);
};
__forceinline void SimdVector::RotateBack(const SimdQuaternion& rotation, const SimdVector& direction)
{
    quad = RotateInverseRaw(rotation.q.Raw(), direction.Raw());
}
__forceinline void SimdVector::Rotate(const SimdQuaternion& rotation, const SimdVector& direction)
{
    SimdVector half;
    half = DAT_010c71e0;
    SimdVector w;
    w.Broadcast(rotation.q, 3);
    SimdVector factor;
    factor.AccumulateProduct(half, w, w);
    SimdVector result;
    result.Product(direction, factor);
    SimdVector dot;
    dot.Raw() = rotation.Imaginary().Dot(direction);
    dot.Broadcast(dot, 0);
    result.AddProduct(dot, rotation.Imaginary());
    SimdVector cross;
    cross.Cross(rotation.Imaginary(), direction);
    result.AddProduct(w, cross);
    Sum(result, result);
}
struct SimdTransform
{
    SimdVector position;
    SimdQuaternion rotation;
    SimdVector scale;
    __forceinline void SetInverse(const SimdTransform& p)
    {
        position.RotateBack(p.rotation, p.position);
        position.Negate(position);
        rotation.Inverse(p.rotation);
        SimdVector reciprocal;
        reciprocal.Reciprocal3(p.scale);
        scale.ClearW(reciprocal);
    }
    __forceinline void SetMul(const SimdTransform& a, const SimdTransform& b)
    {
        SimdVector extra;
        extra.Rotate(a.rotation, b.position);
        position.Sum(a.position, extra);
        rotation.setMul(&a.rotation, &b.rotation);
        scale.Product(a.scale, b.scale);
    }
    __forceinline void SetInverseMul(const SimdTransform& a, const SimdTransform& b)
    {
        SimdTransform inverse;
        inverse.SetInverse(a);
        SetMul(inverse, b);
    }
};
struct TransformArg
{
    const SimdTransform* p;
    TransformArg(const SimdTransform* v) : p(v)
    {}
};
__declspec(noalias) void __cdecl HK2NI_00c74d50(SceneTransform*, TransformArg);
struct DirtyObject
{
    int unk00, unk04, unk08, unk0c, unk10;
    bool dirty;
};
struct SceneOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual DirtyObject* GetObject();
};
struct SceneChildLocal
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    SceneOwner* owner;
    int unk20, unk24, unk28, unk2c, unk30;
    Mat3 m34;
    LocalVec3 m58;
};
struct Hierarchy
{
    int unk00, unk04, unk08;
    short* parents;
    int unk10, unk14, unk18;
    int count;
};
struct TransformSet
{
    Hierarchy* hierarchy;
    SimdTransform* local;
    int unk08, unk0c;
    SimdTransform* world;
    int unk14, unk18;
    unsigned* flags;
    __forceinline SimdTransform& GetLocal(int i, int bytes);
    void syncLocalSpace();
    SimdTransform* hkaPose_calculateBoneModelSpace(int);
    __forceinline SimdTransform* GetWorld(int index)
    {
        if (!(flags[index] & 2))
            return &world[index];
        return hkaPose_calculateBoneModelSpace(index);
    }
};
struct SourceNode
{
    int unk00, unk04, unk08;
    Hierarchy* hierarchy;
};
struct ScaleOwner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94;
    float scale;
};
struct PoseControllerLocal
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    ScaleOwner* owner;
    int unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84;
    TransformSet* transforms;
    int unk8c, unk90, unk94, unk98, unk9c, unka0;
    SceneChildLocal** children;
    int unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    int unk2a0;
    SourceNode* source;
    void bhkRagdollController_SetSGPoseLocalSpace();
};

// @fnv 0x00c79a50
// src: COMMUNITY 0x00c79a50
void PoseControllerLocal::bhkRagdollController_SetSGPoseLocalSpace()
{
    int count = source->hierarchy->count;
    transforms->syncLocalSpace();
    float reciprocalScale = 1.0f / owner->scale;
    int i = 0;
    if (count > 0)
    {
        int bytes = 0;
        do
        {
            SceneChildLocal* child = children[i];
            SimdTransform& value = transforms->GetLocal(i, bytes);
            SceneTransform converted;
            HK2NI_00c74d50(&converted, TransformArg(&value));
            converted.position *= reciprocalScale;
            memcpy(&child->m58, &converted.position, sizeof(LocalVec3));
            memcpy(&child->m34, &converted.rotation, sizeof(Mat3));
            SceneOwner* owner = child->owner;
            if (owner)
            {
                DirtyObject* obj = owner->GetObject();
                if (obj)
                    obj->dirty = true;
            }
            bytes += sizeof(SimdTransform);
        } while (++i < count);
    }
}

__forceinline SimdTransform& TransformSet::GetLocal(int i, int bytes)
{
    if (flags[i] & 1)
    {
        short parent = hierarchy->parents[i];
        SimdTransform* world = this->world;
        if (parent != -1)
        {
            (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(local) + bytes))
                .SetInverseMul(*GetWorld(parent),
                               (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(world) + bytes)));
        }
        else
        {
            SimdTransform& dest = (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(local) + bytes));
            dest.position = (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(world) + bytes)).position;
            dest.rotation.q = (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(world) + bytes)).rotation.q;
            dest.scale = (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(world) + bytes)).scale;
        }
        flags[i] &= ~1u;
    }
    return (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(local) + bytes));
}

// src: COMMUNITY 0x00c66320
inline void SimdQuaternion::setMul(const SimdQuaternion* a, const SimdQuaternion* b)
{
    SimdVector v;
    v.Cross(a->Imaginary(), b->Imaginary());
    SimdVector aw;
    aw.Broadcast(a->q, 3);
    v.AddProduct(aw, b->Imaginary());
    SimdVector bw;
    bw.Broadcast(b->q, 3);
    v.AddProduct(bw, a->Imaginary());
    SimdVector dot;
    dot.Raw() = a->q.Dot(b->q);
    dot.Broadcast(dot, 0);
    SimdVector product;
    product.Product(a->q, b->q);
    SimdVector result;
    result.Difference(product, dot);
    __m128 hi = _mm_unpackhi_ps(v.Raw(), result.Raw());
    q.Raw() = _mm_shuffle_ps(v.Raw(), hi, 0xc4);
}
}  // namespace fnv_00c79a50

struct P103Transform
{
    __m128 translation;
    __m128 rotation;
    __m128 scale;
    __forceinline P103Transform& operator=(const P103Transform& other)
    {
        translation = other.translation;
        rotation = other.rotation;
        scale = other.scale;
        return *this;
    }
};
struct P103Quaternion
{
    __m128 value;
    __declspec(noinline) void setMul(const __m128* a, const __m128* b);
};
extern __m128 DAT_010c71e0;
extern const float DAT_01011d78, DAT_01012068, DAT_01012054;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;
// src: COMMUNITY 0x00c66320
__declspec(noinline) __declspec(noalias) void P103Quaternion::setMul(const __m128* a, const __m128* b)
{
    P103Quaternion left = *(const P103Quaternion*)a;
    P103Quaternion right = *(const P103Quaternion*)b;
    __m128 q = left.value, r = right.value;
    __m128 prod = _mm_mul_ps(q, r);
    __m128 sy = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), sy);
    __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
    __m128 na = _mm_mul_ps(_mm_shuffle_ps(r, r, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
    __m128 pa = _mm_mul_ps(_mm_shuffle_ps(r, r, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
    __m128 xyz = _mm_sub_ps(pa, na);
    __m128 qw = _mm_shuffle_ps(q, q, 0xff);
    qw = _mm_shuffle_ps(qw, qw, 0);
    xyz = _mm_add_ps(_mm_mul_ps(qw, r), xyz);
    __m128 rw = _mm_shuffle_ps(r, r, 0xff);
    rw = _mm_shuffle_ps(rw, rw, 0);
    xyz = _mm_add_ps(_mm_mul_ps(rw, q), xyz);
    value = _mm_shuffle_ps(xyz, _mm_unpackhi_ps(xyz, real), 0xc4);
}

struct P103Skeleton
{
    unsigned int unk00, unk04, unk08;
    short* parents;
    unsigned int unk10, unk14, unk18;
    int count;
};
struct P103Pose
{
    P103Skeleton* skeleton;
    P103Transform* local;
    unsigned int unk08, unk0c;
    P103Transform* model;
    unsigned int unk14, unk18;
    unsigned int* flags;
    unsigned int unk20, unk24;
    bool localSynced;
    bool modelSynced;
    P103Transform* accessBoneModelSpace(int bone, int mode);
    P103Transform* hkaPose_calculateBoneModelSpace(int bone);
    void hkaPose_setToReferencePose();
    __forceinline void storeModel(int selected, const P103Transform& target);
    __forceinline const P103Transform& localAt(int index);
    P103Transform* modelAt(int bone)
    {
        if (!(flags[bone] & 2))
            return model + bone;
        return hkaPose_calculateBoneModelSpace(bone);
    }
};
static __forceinline __m128 P103Rotate(const __m128& q, const __m128& v)
{
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 square = _mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0);
    __m128 base = _mm_mul_ps(v, square);
    __m128 product = _mm_mul_ps(q, v);
    __m128 sy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 sz = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sy);
    __m128 dot = _mm_shuffle_ps(sz, sz, 0);
    base = _mm_add_ps(_mm_mul_ps(dot, q), base);
    __m128 qd2 = _mm_shuffle_ps(q, q, 0xd2);
    __m128 vc9 = _mm_shuffle_ps(v, v, 0xc9);
    __m128 a = _mm_mul_ps(vc9, qd2);
    __m128 qc9 = _mm_shuffle_ps(q, q, 0xc9);
    __m128 vd2 = _mm_shuffle_ps(v, v, 0xd2);
    __m128 b = _mm_mul_ps(vd2, qc9);
    __m128 cross = _mm_sub_ps(b, a);
    base = _mm_add_ps(_mm_mul_ps(w, cross), base);
    return _mm_add_ps(base, base);
}
static __forceinline __m128 P103RotateInverse(const __m128& q, const __m128& v)
{
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 square = _mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0);
    __m128 base = _mm_mul_ps(v, square);
    __m128 product = _mm_mul_ps(q, v);
    __m128 sy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 sz = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sy);
    __m128 dot = _mm_shuffle_ps(sz, sz, 0);
    base = _mm_add_ps(_mm_mul_ps(dot, q), base);
    __m128 vd2 = _mm_shuffle_ps(v, v, 0xd2);
    __m128 qc9 = _mm_shuffle_ps(q, q, 0xc9);
    __m128 a = _mm_mul_ps(qc9, vd2);
    __m128 vc9 = _mm_shuffle_ps(v, v, 0xc9);
    __m128 qd2 = _mm_shuffle_ps(q, q, 0xd2);
    __m128 b = _mm_mul_ps(qd2, vc9);
    __m128 cross = _mm_sub_ps(b, a);
    base = _mm_add_ps(_mm_mul_ps(w, cross), base);
    return _mm_add_ps(base, base);
}
static __forceinline __m128 P103Dot3(const __m128& a, const __m128& b)
{
    __m128 product = _mm_mul_ps(a, b);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    return sum;
}
static __forceinline float P103Angle(const __m128& dot)
{
    float f;
    _mm_store_ss(&f, dot);
    return (float)(1.5707963705062866 - (float)acos((double)f));
}
static __forceinline void P103SetInverse(P103Transform& out, const P103Transform& t)
{
    out.translation = _mm_xor_ps(P103RotateInverse(t.rotation, t.translation), DAT_010c44d0);
    out.rotation = _mm_xor_ps(t.rotation, DAT_010c4c00);
    __m128 scale = t.scale;
    scale = _mm_shuffle_ps(scale, _mm_unpackhi_ps(scale, DAT_010c7170), 0xc4);
    __m128 r = _mm_rcp_ps(scale);
    __m128 c = _mm_mul_ps(r, scale);
    c = _mm_mul_ps(c, r);
    r = _mm_add_ps(r, r);
    r = _mm_sub_ps(r, c);
    out.scale = _mm_and_ps(r, DAT_010c4c10);
}
static __forceinline void P103SetMul(P103Transform& out, const P103Transform& t1, const P103Transform& t2)
{
    __m128 temp = _mm_add_ps(P103Rotate(t1.rotation, t2.translation), t1.translation);
    out.translation = temp;
    ((P103Quaternion*)&out.rotation)->setMul(&t1.rotation, &t2.rotation);
    out.scale = _mm_mul_ps(t1.scale, t2.scale);
}
__forceinline const P103Transform& P103Pose::localAt(int index)
{
    if (flags[index] & 1)
    {
        P103Transform* source = model;
        short parent = skeleton->parents[index];
        if (parent != -1)
        {
            P103Transform* p = modelAt(parent);
            P103Transform& dest = local[index];
            P103Transform inverse;
            P103SetInverse(inverse, *p);
            P103SetMul(dest, inverse, source[index]);
        }
        else
            local[index] = source[index];
        flags[index] &= ~1u;
    }
    return local[index];
}
__forceinline void P103Pose::storeModel(int selected, const P103Transform& target)
{
    int count = skeleton->count;
    flags[selected] |= 4;
    for (int index = selected + 1; index < count; ++index)
    {
        short parent = skeleton->parents[index];
        if (parent != -1 && (flags[parent] & 4))
        {
            localAt(index);
            flags[index] |= 4;
            localSynced = false;
        }
    }
    for (int index = selected + 1; index < count; ++index)
    {
        unsigned int f = flags[index];
        if (f & 4)
            flags[index] = (f & ~4u) | 2;
    }
    model[selected] = target;
    flags[selected] = 1;
    modelSynced = false;
}
struct P103Controller
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    P103Pose* referencePose;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    P103Pose* pose;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    float pitchLimit;
    float yawLimit;
    unsigned int unk13c;
    unsigned int unk140;
    short bone;
    short unk146;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    bool unk180;
    bool changed;
    short unk182;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    bool enabled;
    unsigned char unk191;
    short unk192;
    int forceChanged;
    unsigned int unk198;
    float pitch;
    float yaw;
    void bhkRagdollController_AdjustCurrentTarget();
    bool bhkRagdollController_BoneTrack(int mode, const P103Transform& transform);
    void bhkRagdollController_DoLookAtIK(P103Transform* transform);
};
// Stores the bone's transform in pose, combines it with the given transform, and sets pitch/yaw from referencePose, marking changed past the limits.
// @fnv 0x00c7aa60
// src: XBOX_PDB 0x00c7aa60
void P103Controller::bhkRagdollController_DoLookAtIK(P103Transform* transform)
{
    bhkRagdollController_AdjustCurrentTarget();
    if (changed || !enabled)
    {
        forceChanged = 1;
        bhkRagdollController_BoneTrack(1, *transform);
    }
    P103Transform& target = *pose->accessBoneModelSpace(bone, 1);
    ((P103Quaternion*)&target.rotation)->setMul(&target.rotation, (const __m128*)&unk0c0);
    pose->storeModel(bone, target);
    if (enabled)
    {
        P103Transform* boneTransform = pose->modelAt(bone);
        P103Transform combined;
        combined.translation =
            _mm_add_ps(P103Rotate(transform->rotation, boneTransform->translation), transform->translation);
        ((P103Quaternion*)&combined.rotation)->setMul(&transform->rotation, &boneTransform->rotation);
        combined.scale = _mm_mul_ps(transform->scale, boneTransform->scale);
        changed = bhkRagdollController_BoneTrack(0, combined) || forceChanged != 0;
        __m128 right = _mm_setr_ps(1.0f, 0.0f, 0.0f, 0.0f);
        __m128 axis = _mm_setr_ps(0.0f, 1.0f, 0.0f, 0.0f);
        __m128 negativeZ = _mm_setr_ps(0.0f, 0.0f, -1.0f, 0.0f);
        P103Transform* reference = referencePose->modelAt(1);
        __m128 forward = P103Rotate(reference->rotation, axis);
        float pitchValue = P103Angle(P103Dot3(forward, negativeZ));
        pitch = pitchValue;
        yaw = P103Angle(P103Dot3(forward, right));
        if (fabs(yaw) > yawLimit)
            changed = true;
        if (fabs(pitchValue) > pitchLimit)
            changed = true;
        referencePose->hkaPose_setToReferencePose();
    }
}


class NiAVObjV : public NiRefObject
{
  public:
    virtual void v02();
    virtual NiNode* v03();

    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NiNode* m_pkParent;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    NiTransform m_kLocal;
    NiTransform m_kWorld;

    NiAVObjV* GetObjectByName_00a59e20(const NiFixedString& kName);
    void AssignFixedString(const NiFixedString& kName);
    void UpdateProperties();
    void NiAVObject_Update(NiUpdateData& updateData);
};

struct bhkSubData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct bhkWorldSub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    bhkSubData sub;
};

struct bhkCollisionProxy : public bhkNiCollisionObject
{
    unsigned short m_ucFlags;
    bool GetFlag(unsigned int bit) const { return (m_ucFlags >> bit) & 1; }
    bhkWorld* m_pkWorld;
    void bhkNiCollisionObject_SetDebugDisplay(bool bEnable);
};

extern unsigned int DAT_0126fd98;

struct CollisionTlsGuard
{
    int saved;
    CollisionTlsGuard(unsigned int id)
    {
        saved = DAT_000002b4;
        DAT_000002b4 = id;
    }
    ~CollisionTlsGuard()
    {
        DAT_000002b4 = saved;
    }
};

// If bEnable, creates a bhkColDisp node under the parent and sets flag 0x10; otherwise looks up bhkColDisp children of the parent and clears flag 0x10.
// @fnv 0x00c6bd60
// src: XBOX_PDB 0x00c6bd60
void bhkCollisionProxy::bhkNiCollisionObject_SetDebugDisplay(bool bEnable)
{
    CollisionTlsGuard guard(0x10);

    if (bEnable)
    {
        if (GetFlag(4))
        {
            return;
        }
        bhkWorld* world = m_pkWorld;
        if (world)
        {
            bhkSubData* updateData = world->m_pHavokObject ? &reinterpret_cast<bhkWorldSub*>(world->m_pHavokObject)->sub : 0;
            int val = updateData ? updateData->unk1C : 0;
            if ((val & 0x7F) == 0x11)
            {
                return;
            }

            NiAVObjV* pkObj = (NiAVObjV*)m_pkSceneObject;
            NiNode* a = 0;
            if (!pkObj || !(a = pkObj->v03()))
            {
                a = pkObj->m_pkParent;
            }

            NiNode* fScale = new NiNode(0);
            fScale->NiAVObject::SetName(NiFixedString("bhkColDisp"));

            if (a)
            {
                float s = a->m_kWorld.m_fScale;
                fScale->m_kLocal.m_fScale = fabsf(1.0f / s);
                a->AttachChildInAvailableSlot(static_cast<NiAVObject*>(fScale), true);
                NiUpdateData sub;
                fScale->NiAVObject_Update(sub);
            }

            // This call uses slot 0xCC with a one-node signature absent from the shared header.
        NiPointer<NiAVObjV> pNode = reinterpret_cast<NiAVObjV* (__thiscall*)(bhkWorld*, NiNode*)>((*reinterpret_cast<void***>(world))[51])(world, fScale);
            if (pNode)
            {
                if (a)
                {
                    pNode->UpdateProperties();
                    NiUpdateData sub;
                    pNode->NiAVObject_Update(sub);
                }
            }
            else
            {
                if (a && fScale)
                {
                    NiPointer<NiAVObjV> spOld;
                    a->RemoveObject2(fScale, reinterpret_cast<NiAVObject**>(&spOld));
                }
            }

            m_ucFlags |= 0x10;
        }
    }
    else
    {
        if (!GetFlag(4))
        {
            return;
        }

        NiAVObjV* pkObj = (NiAVObjV*)m_pkSceneObject;
        NiNode* a = pkObj ? pkObj->v03() : 0;
        if (m_pkWorld)
        {
            // This call uses slot 0xD0 with no arguments; preserve its original call signature.
            reinterpret_cast<void (__thiscall*)(bhkWorld*)>((*reinterpret_cast<void***>(m_pkWorld))[52])(m_pkWorld);
        }
        if (!a)
        {
            a = pkObj->m_pkParent;
        }

        if (a)
        {
            unsigned int count = a->m_kChildren.m_usSize;
            unsigned int i = 0;
            for (; i < count; ++i)
            {
                NiAVObjV* b = reinterpret_cast<NiAVObjV*>(a->m_kChildren.m_pBase[i].m_pObject);
                NiAVObjV* pkColDisp =
                    b ? b->GetObjectByName_00a59e20(NiFixedString("bhkColDisp")) : 0;
                if (pkColDisp)
                {
                    NiPointer<NiAVObjV> spOld;
                    a->RemoveObject2(reinterpret_cast<NiAVObject*>(pkColDisp), reinterpret_cast<NiAVObject**>(&spOld));
                }
            }
        }

        m_ucFlags &= ~0x10;
    }
}

struct WorldProxy;
struct ContainerProxy
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    WorldProxy* world;
};
struct BodyProxy
{
    int unk00, unk04;
    ContainerProxy* unk08;
};
struct LinkProxy
{
    BodyProxy* hkpCharacterProxy_getShapePhantom();
    LinkProxy* ahkpCharacterProxy_GetCdPoints();
    int unk00, unk04;
};
struct ConstraintProxy
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4c();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5c();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6c();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7c();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8c();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void attach(WorldProxy*);
    virtual void detach();
    void Detach()
    {
        if (this)
            detach();
    }
    void Attach(WorldProxy* w)
    {
        if (this)
            attach(w);
    }
};
struct WorldProxy
{
    void bhkWorld_SetDebugObjectColor(ConstraintProxy*, void*);
};
void* PackColorBigEndian(float, float, float, float);
struct C70CharacterController
{
    int unk000;
    int unk004;
    LinkProxy* link;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    unsigned int flags;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    ConstraintProxy* constraint594;
    ConstraintProxy* constraint598;
    void ToggleAndUpdate();
    void bhkCharacterController_SetSize(float);
    void bhkCharacterController_SetCapsuleRadius(float);
    void bhkCharacterController_SetWorld(WorldProxy*);
};
// Moves the character controller between worlds by detaching constraints from the old world and attaching them to the new one.
// @fnv 0x00c70c90
// src: XBOX_PDB 0x00c70c90
void C70CharacterController::bhkCharacterController_SetWorld(WorldProxy* world)
{
    BodyProxy* body = link ? link->hkpCharacterProxy_getShapePhantom() : 0;
    WorldProxy* current = body->unk08 ? body->unk08->world : 0;
    if (current != world)
    {
        if (current)
        {
            ToggleAndUpdate();
            constraint594->Detach();
            constraint598->Detach();
        }
        if (link)
            link->ahkpCharacterProxy_GetCdPoints()->unk04 = 0;
        if (world)
        {
            if (constraint594)
            {
                if (!(*(unsigned char*)&flags & 1) && !((unsigned char)(flags >> 20) & 1))
                {
                    bhkCharacterController_SetSize((float)(DAT_01267bcc * 0.009999999776482582));
                    bhkCharacterController_SetCapsuleRadius((float)(DAT_01267bcc * 0.009999999776482582));
                    bhkCharacterController_SetSize(0.0f);
                }
                constraint594->attach(world);
                ConstraintProxy* c = constraint594;
                world->bhkWorld_SetDebugObjectColor(c, PackColorBigEndian(1.0f, 1.0f, 0.0f, 0.75f));
            }
            constraint598->Attach(world);
        }
    }
}

// Releases the two owned array buffers.

inline hkMemoryRouter& C71120GetMemoryRouter()
{
    return *reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
}

template <class T> inline void C71120ReleaseBuffer(hkMemoryAllocator& alloc, T* p, int numElem)
{
    alloc.bufFree(p, numElem * sizeof(T));
}

template <class T>
static __forceinline void C71120Array_destroy(hkArrayBase<T>& self);

template <class T>
static __forceinline void C71120Array_destroy(hkArrayBase<T>& self)
{
        hkMemoryAllocator& alloc = GetRouterHeap(C71120GetMemoryRouter());
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            C71120ReleaseBuffer(alloc, self.m_data, self.m_iCapacityState & 0x3fffffff);
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

struct C71120ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { C71120Array_destroy(self); }
};

template <class T>
static __forceinline void C71120ArrayBase_destroy(hkArrayBase<T>& self);

template <class T>
static __forceinline void C71120ArrayBase_destroy(hkArrayBase<T>& self)
{
        hkMemoryAllocator& alloc = GetRouterHeap(C71120GetMemoryRouter());
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

struct C71120ArrayBasePolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { C71120ArrayBase_destroy(self); }
};

class FUN_00c71120
{
  public:
    ~FUN_00c71120();
    int m_iID;
    hkArray<int, C71120ArrayBasePolicy> m_kIndices;
    hkArray<float, C71120ArrayPolicy> m_kWeights;
};

// Destructor for FUN_00c71120; the body is empty because the C71120ArrayBase and C71120Array members handle their own cleanup.
// @fnv 0x00c71120
FUN_00c71120::~FUN_00c71120()
{}

// Force emission of the destructor.
void C71120Destroy(void* pvObject)
{
    static_cast<FUN_00c71120*>(pvObject)->FUN_00c71120::~FUN_00c71120();
}

// @fnv 0x00c75fa0
template <> NiTMap<NiAVObject*, short>::~NiTMap()
{
    RemoveAll();
}

struct C6A540ActionList : FUN_00c68f50_cls
{
    void RemoveKey(FUN_00c663d0_Ref** pKey);
};

void C6A540ActionList::RemoveKey(FUN_00c663d0_Ref** pKey)
{
    if (!*pKey)
        return;
    if (!m_next && !m_key.m_pObject)
        return;
    FUN_00c68f50_cls* pPrev = this;
    FUN_00c68f50_cls* pNode = this;
    while (pNode->m_key.m_pObject != *pKey)
    {
        pPrev = pNode;
        pNode = pNode->m_next;
        if (!pNode)
            return;
    }
    if (pNode == this)
    {
        FUN_00c68f50_cls* pNext = m_next;
        if (pNext)
        {
            m_next = pNext->m_next;
            m_key = pNext->m_key;
            pNext->m_next = 0;
            pNext->LockOwnerAndRelease();
            DAT_011f6238.MemoryManager_Deallocate(pNext);
        }
        else
        {
            FUN_00c663d0_Ref* pObject = m_key.m_pObject;
            if (pObject && InterlockedDecrement(&pObject->m_uiRefCount) == 0)
                pObject->v1();
            m_key.m_pObject = 0;
        }
    }
    else
    {
        pPrev->m_next = pNode->m_next;
        pNode->m_next = 0;
        pNode->LockOwnerAndRelease();
        DAT_011f6238.MemoryManager_Deallocate(pNode);
    }
}

struct Item_c6a540
{
    virtual void v00();
    virtual void DeleteThis();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual int v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49(float afValue);
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct Shell_c6a540
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0c;
    int uNewnk;
    int uTmpnk;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    C6A540ActionList m_kList;
    void bhkWorld_UpdateActions(float afValue);
};

// Iterates m_kList; items whose v37() returns false are removed from the list, others get v49(afValue).
// @fnv 0x00c6a540
// src: COMMUNITY 0x00c6a540
void Shell_c6a540::bhkWorld_UpdateActions(float afValue)
{
    FUN_00c68f50_cls* pIter = &m_kList;
    while (pIter && (pIter->m_next || pIter->m_key.m_pObject))
    {
        Item_c6a540* pItem = (Item_c6a540*)pIter->m_key.m_pObject;
        FUN_00c68f50_cls* pNext = pIter->m_next;
        if (pItem)
        {
            if (!pItem->v37())
            {
                if (pIter == &m_kList)
                    pNext = pIter;
                NiPointer<Item_c6a540> spItem = pItem;
                m_kList.RemoveKey((FUN_00c663d0_Ref**)&spItem);
            }
            else
                pItem->v49(afValue);
        }
        pIter = pNext;
    }
}

struct ReleaseObject
{
    void FUN_00c905b0();
};
struct FUN_00cbf430
{
    ~FUN_00cbf430();
    static void operator delete(void* p)
    {
        DAT_011f6238.MemoryManager_Deallocate((FUN_00c68f50_cls*)p);
    }
};
struct ShutdownMode
{
    int value;
    ShutdownMode(int v) : value(v)
    {}
};
struct ShutdownInterface
{
    virtual void v00(int);
    virtual void v01();
    virtual void v02(ShutdownMode);
};
extern FUN_00cbf430* DAT_012677d0;
static ShutdownInterface* DAT_012677d4;
int __cdecl ShutdownIfInitialized();
void __cdecl hkMemorySystem_replaceInstance(int);
void __cdecl NotifyThreadObserverEnabled();
void __cdecl RunCallbackIfPresent();

namespace QuitCalls {
void __cdecl bhkCharacterControllerCinfo_ReleaseDefaultShape();
}

// Runs FUN_00c66570, FUN_00c6d340 and FUN_00c6d3c0, releases DAT_012677a8, deletes DAT_012677d0, calls v02(3) and v00(0) on DAT_012677d4, then clears it.
// @fnv 0x00c66670
// src: XBOX_PDB 0x00c66670
void __cdecl bhkWorld_QuitSystem()
{
    ThreadMemoryScope scope;
    NotifyThreadObserverEnabled();
    RunCallbackIfPresent();
    QuitCalls::bhkCharacterControllerCinfo_ReleaseDefaultShape();
    if (DAT_012677a8)
    {
        ((ReleaseObject*)DAT_012677a8)->FUN_00c905b0();
        DAT_012677a8 = 0;
    }
    if (DAT_012677d0)
        delete DAT_012677d0;
    ShutdownIfInitialized();
    DAT_012677d4->v02(3);
    DAT_012677d4->v00(0);
    DAT_012677d4 = 0;
    hkMemorySystem_replaceInstance(0);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct __declspec(align(16)) Mat44
{
    Vec4 r0, r1, r2, r3;
};
struct Mat9
{
    float f[9];
};

extern __declspec(thread) int g_tlsMemContext;
extern char DAT_012677a1;
extern float DAT_01267e30;
extern float DAT_012683b0;
extern Mat9 DAT_011a9448;
struct RTTIObj
{
    int m_00;
};
extern RTTIObj g_012683c8;
bool __cdecl NiObject_IsKindOf(const RTTIObj* rtti, struct C69960Node* obj);
struct RetC
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
RetC* __cdecl GetExtraDataChecked(struct C69960Arg* a);
void* __cdecl MemoryManager_AlignedAllocate16(int size);
void __cdecl FUN_0056df80(void* dst, void* src);
void __cdecl bhkWorld_DoObjects(struct C69960Arg* a, void* ctx);
void __cdecl bhkWorld_DoObjectRec(struct C69960Arg* a, void* ctx, int cb);
struct NodeBase
{
    virtual void Slot00();
    virtual void Release04();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual int Get40();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual bool GetB4();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void GetD4(void* out);
    virtual void GetD8(void* out);
    virtual void CallDC(const void* p);
    virtual void CallE0(const void* p);
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};
struct __declspec(align(16)) C69960Node : NodeBase
{
    Vec4 m_20;
    Vec4 m_30;
    C69960Node(C69960Node* a);
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
};
struct ResObj
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual ResObj* Get38();
    int m_04;
    int m_08;
    int m_0c;
    C69960Node* m_10;
    virtual void Extra3c();
    virtual void Extra40();
    virtual void Extra44();
    virtual void Extra48();
    virtual void Extra4c();
    virtual void Extra50();
    virtual void Extra54();
    virtual void Extra58();
    virtual void Extra5c();
    virtual void Extra60();
    virtual void Extra64();
    virtual void Extra68();
    virtual void Extra6c();
    virtual void Extra70();
    virtual void Extra74();
    virtual void Extra78();
    virtual void Extra7c();
    virtual void Extra80();
    virtual void Extra84();
    virtual void Extra88();
    virtual void Extra8c();
    virtual void Extra90();
    virtual void Extra94();
    virtual void Extra98();
    virtual void Extra9c();
    virtual void Extraa0();
    virtual void Extraa4();
    virtual void Extraa8();
    virtual void Extraac();
    virtual void Extrab0();
    virtual bool GetB4();
    void __thiscall bhkNiCollisionObject_SetWorldObject(C69960Node* a);
    void __thiscall AttachTarget(void* a);
};
struct C69960Arg
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    ResObj* m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    Mat9 m_34;
    NiPoint3 m_58;
    void __thiscall AttachTarget(void* a);
};
struct LocalRef
{
    void* m_ptr;
    LocalRef(int a);
    ~LocalRef();
};
struct __declspec(align(16)) Obj60
{
    Vec4 m_00;
    void __thiscall FUN_00cb26e0(void* a);
};
struct __declspec(align(16)) Obj74
{
    Vec4 m_00;
    void __thiscall setMul(void* a, void* b);
};
struct __declspec(align(16)) ObjAC
{
    Vec4 m_00;
    void __thiscall setTransformedPos_00c7f640(void* a, void* b);
};
struct Ctx
{
    void* m_00;
    char m_04;
    char m_05;
    char m_06;
    char m_07;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
};
__forceinline unsigned int IsEnabled(C69960Arg* obj)
{
    RetC* result = GetExtraDataChecked(obj);
    return result ? (result->m_0c & 2) : 0;
}

struct MemScope
{
    int saved;
    __forceinline MemScope()
    {
        saved = g_tlsMemContext;
        g_tlsMemContext = 0x10;
    }
    __forceinline ~MemScope()
    {
        g_tlsMemContext = saved;
    }
};

__forceinline void Rotate(__m128& out, const __m128& q, const __m128& v)
{
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 crossA = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
    __m128 crossB = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
    __m128 cross = _mm_sub_ps(crossB, crossA);
    __m128 product = _mm_mul_ps(v, q);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    cross = _mm_mul_ps(cross, w);
    __m128 square = _mm_mul_ps(w, w);
    square = _mm_add_ps(square, DAT_010c71e0);
    square = _mm_mul_ps(square, v);
    __m128 projection = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    __m128 total = _mm_add_ps(cross, _mm_add_ps(square, projection));
    out = _mm_add_ps(total, total);
}
__forceinline void RotateInverse(__m128& out, const __m128& qp, const __m128& vp)
{
    __m128 q = qp;
    __m128 v = vp;
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 crossB = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
    __m128 crossA = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
    __m128 cross = _mm_sub_ps(crossA, crossB);
    __m128 product = _mm_mul_ps(qp, v);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    cross = _mm_mul_ps(cross, w);
    __m128 square = _mm_mul_ps(w, w);
    square = _mm_add_ps(square, DAT_010c71e0);
    square = _mm_mul_ps(square, v);
    __m128 projection = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    __m128 total = _mm_add_ps(cross, _mm_add_ps(square, projection));
    out = _mm_add_ps(total, total);
}

struct Host
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    char m_14;
    char m_15;
    char m_16;
    char m_17;
    int m_18;
    bool __thiscall bhkWorld_AddObjectsAndMoveController(C69960Arg* arg1, C69960Arg* arg2);
};
// @fnv 0x00c69960
// src: XBOX_PDB 0x00c69960
bool __thiscall Host::bhkWorld_AddObjectsAndMoveController(C69960Arg* apSource, C69960Arg* apTarget)
{
    __m128 matrixStorage[4];
    Mat44& matTransform = *reinterpret_cast<Mat44*>(matrixStorage);
    __declspec(align(16)) unsigned int objACStorage[4];
    ObjAC& objAC = *reinterpret_cast<ObjAC*>(&objACStorage);
    __declspec(align(16)) unsigned int bufBStorage[4];
    Vec4& bufB = *reinterpret_cast<Vec4*>(&bufBStorage);
    __declspec(align(16)) unsigned int bufAStorage[4];
    Vec4& bufA = *reinterpret_cast<Vec4*>(&bufAStorage);
    __declspec(align(16)) unsigned int obj74Storage[4];
    Obj74& obj74 = *reinterpret_cast<Obj74*>(&obj74Storage);
    __declspec(align(16)) unsigned int obj60Storage[4];
    Obj60& obj60 = *reinterpret_cast<Obj60*>(&obj60Storage);
    __declspec(align(16)) unsigned int vTempStorage[4];
    Vec4& vTemp = *reinterpret_cast<Vec4*>(&vTempStorage);
    Ctx ctx;
    MemScope memory;
    bool flagA = false;
    int state2 = 0;
    ResObj* result1 = 0;
    if (apSource && apTarget && IsEnabled(apTarget))
    {
        {
            ResObj* p1 = apSource->m_1c;
            state2 = 0;
            if (p1)
            {
                result1 = p1->Get38();
                if (result1)
                {
                    C69960Node* node = result1->m_10;
                    state2 = 1;
                    if (node && !result1->GetB4())
                    {
                        m_14 = 1;
                        flagA = 1;
                        if (apTarget != apSource)
                        {
                            C69960Node* work = 0;
                            if (NiObject_IsKindOf(&g_012683c8, node))
                            {
                                work = node;
                                goto main_block;
                            }
                            {
                                LocalRef smart(node->Get40());
                                C69960Node* work2 = (C69960Node*)smart.m_ptr;
                                if (work2)
                                {
                                    result1->bhkNiCollisionObject_SetWorldObject(0);
                                    work = new C69960Node(work2);
                                    work2->GetD4(&bufA);
                                    work2->GetD8(&bufB);
                                    (*reinterpret_cast<__m128*>(&work->m_30)) = (*reinterpret_cast<__m128*>(&bufA));
                                    (*reinterpret_cast<__m128*>(&work->m_20)) = (*reinterpret_cast<__m128*>(&bufB));
                                    work->CallDC(&DAT_01267e30);
                                    work->CallE0(&DAT_012683b0);
                                    result1->bhkNiCollisionObject_SetWorldObject(work);
                                    if (InterlockedDecrement((long*)&work2->m_04) == 0)
                                        work2->Release04();
                                    smart.m_ptr = 0;
                                }
                            }
                        main_block:
                            if (work)
                            {
                                FUN_0056df80(&matTransform, &apSource->m_34);
                                Rotate((*reinterpret_cast<__m128*>(&vTemp)), (*reinterpret_cast<__m128*>(&work->m_20)), (*reinterpret_cast<__m128*>(&work->m_30)));
                                objAC.setTransformedPos_00c7f640(&matTransform, &vTemp);
                                obj60.FUN_00cb26e0(&matTransform);
                                obj74.setMul(&work->m_20, &obj60);
                                RotateInverse((*reinterpret_cast<__m128*>(&vTemp)), (*reinterpret_cast<__m128*>(&work->m_20)), (*reinterpret_cast<__m128*>(&objAC.m_00)));
                                (*reinterpret_cast<__m128*>(&work->m_30)) = (*reinterpret_cast<__m128*>(&vTemp));
                                (*reinterpret_cast<__m128*>(&work->m_20)) = (*reinterpret_cast<__m128*>(&obj74.m_00));
                                ((ResObj*)apTarget)->AttachTarget(result1);
                                apSource->AttachTarget(0);
                                apSource->m_30 = (apSource->m_30 & ~0x10) | 6;
                            }
                            else
                            {
                                ((ResObj*)apTarget)->AttachTarget(result1);
                                apSource->AttachTarget(0);
                                apSource->m_34 = DAT_011a9448;
                                apSource->m_58 = *(const NiPoint3*)&DAT_011f426c;
                                apSource->m_30 = (apSource->m_30 & ~0x10) | 6;
                            }
                        }
                    }
                }
            }
        }
        {
            ctx.m_00 = this;
            ctx.m_04 = 1;
            if (DAT_012677a1)
            {
                ctx.m_08 = 0xa;
                bhkWorld_DoObjects(apTarget, &ctx);
            }
            ctx.m_08 = 0;
            ctx.m_0c = state2;
            ctx.m_10 = 0;
            ctx.m_14 = 0;
            ctx.m_18 = 1;
            int cb = (int)DAT_011afe88;
            if (cb)
                bhkWorld_DoObjectRec(apTarget, &ctx, cb);
        }
    }
    return flagA;
}

struct Stub65800 : BC6C330HavokCollision
{
    void bhkNiCollisionObject_LoadBinary(BC6C330Stream& kStream);
    void bhkCollisionObject_LoadBinary(BC6C330Stream& kStream);
};

// @fnv 0x00c65800
// src: XBOX_PDB 0x00c65800
void Stub65800::bhkCollisionObject_LoadBinary(BC6C330Stream& kStream)
{
    bhkNiCollisionObject_LoadBinary(kStream);
}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    __if_exists(A::destroy) { A::destroy(*this); }
    __if_not_exists(A::destroy) { clearAndDeallocate(); }
}
