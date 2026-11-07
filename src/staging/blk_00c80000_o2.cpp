#include "../../include/hkArray.h"

// src/staging/blk_00c80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

// The original translation unit of FUN_00c929e0 never included <xmmintrin.h> (its inline helpers change that function's
// code): the SIMD type is declared here as xmmintrin.h declares it, and the shared headers then leave xmmintrin out.
// Exe 0x00c929e0 FUN_00c929e0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
} __m128, LocalM128;
#include "../../include/AutoMemContext.h"
#include "../../include/MEM_CONTEXT.h"
#include "../../include/NiPointer.h"
#include "../../include/NiRTTI.h"
#include "../../include/ObstacleData.h"
#include "../../include/BSSimpleList.h"
#include "../../include/NiMatrix3.h"
#include "../../include/NiTLargeArray.h"
#include "../../include/NiTLargePrimitiveArray.h"

struct BLENDKEY;
#include "../../include/hkMemoryRouter.h"
#include "../../include/AnimIdle.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiAllocator.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiColor.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiObject.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiPlane.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiStream.h"
#include "../../include/NiTriShape.h"
#include "../../include/NiUpdateData.h"
// ScriptOutBlock_blk_00c80000_o2: local type (was include/ScriptOutBlock.h, which had no evidence of one real class); no method of it is bound to a named game function
class ScriptOutBlock_blk_00c80000_o2
{
public:
    int unk00;
    int unk04;
    void* unk08;
};
// ScriptOwnerBase_blk_00c80000_o2: local type (was include/ScriptOwnerBase.h, which had no evidence of one real class); its methods are 0x00c879e0 bhkAction::CopyCinfo
class ScriptOutBlock_blk_00c80000_o2;

class ScriptOwnerBase_blk_00c80000_o2
{
public:
    void bhkAction_CopyCinfo(ScriptOutBlock_blk_00c80000_o2* pOut);
};
// ScriptTarget_blk_00c80000_o2: local type (was include/ScriptTarget.h, which had no evidence of one real class); no method of it is bound to a named game function
class ScriptTarget_blk_00c80000_o2
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    void* m_1c;
};
#include "../../include/bhkFilter.h"
#include "../../include/StrArr.h"
#include "../../include/NiPoint3.h"
#include "../../include/bhkBlendCollisionObject.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkListShape.h"
#include "../../include/bhkWorldObject.h"
#include "../../include/hkpShapeContainer.h"
#include "../../include/hkpListShapeChildInfo.h"
#include "../../include/hkpListShape.h"
#include "../../include/bhkWorld.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/NiNode.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer& kSrc) : m_pObject(kSrc.m_pObject)
{
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0) m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

inline NiColor::NiColor(float red, float green, float blue) : r(red), g(green), b(blue) {}

inline unsigned int StrArr::SetAtGrow(unsigned int index, char*& element)
{
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, element);
    return index;
}

inline unsigned int StrArr::Add(char*& element)
{
    return SetAtGrow(m_usSize, element);
}

// Keep stream transfers inline; the shared stream declarations leave these fields opaque.
inline unsigned int NiBinaryStream::BinaryRead(void* data, unsigned int bytes, int* sizes, unsigned int count)
{
    typedef int(__cdecl* Read)(void*, void*, unsigned int, int*, int);
    unsigned int read = (*(Read*)((char*)this + 8))(this, data, bytes, sizes, count);
    *(unsigned int*)((char*)this + 4) += read;
    return read;
}

inline unsigned int NiBinaryStream::BinaryRead(void* data, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int read = (*(ReadFunction*)((char*)this + 8))(this, data, bytes, sizes, count);
    *(unsigned int*)((char*)this + 4) += read;
    return read;
}
inline unsigned int NiBinaryStream::BinaryWrite(const void* data, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int written = (*(WriteFunction*)((char*)this + 12))(this, data, bytes, sizes, count);
    *(unsigned int*)((char*)this + 4) += written;
    return written;
}
inline unsigned int NiBinaryStream::Read(void* data, unsigned int bytes)
{
    unsigned int size = bytes;
    return BinaryRead(data, bytes, &size, 1);
}
inline void NiBinaryStream::ReadUInt(unsigned int& value)
{
    unsigned int size = 4;
    BinaryRead(&value, 4, &size, 1);
}
inline NiBinaryStream* ReadStream(NiStream& stream)
{
    return *(NiBinaryStream**)((char*)&stream + 0x24c);
}
inline NiBinaryStream* WriteStreamBuffer(NiStream& stream)
{
    return *(NiBinaryStream**)((char*)&stream + 0x250);
}

extern int DAT_010c53dc;
extern int DAT_01267e60;

struct FUN_00c6c290_holder
{
    void FUN_00c6c290();
};

struct FUN_00c81550_holder
{
    void SetVtableAndProcessState_00c81550();
};

// @fnv 0x00c81550
// src: GUESS 0x00c81550 (confidence: low)
void FUN_00c81550_holder::SetVtableAndProcessState_00c81550()
{
    *(int*)this = (int)&DAT_010c53dc;
    --DAT_01267e60;
    ((FUN_00c6c290_holder*)this)->FUN_00c6c290();
}

void* __cdecl bhkBlendCollisionObject_GetFirstCollisionObject(void*);
// Calls FUN_00c81c50 on arg and returns the float at offset 0x18 of the result, or 1.0f if the result is null.
// @fnv 0x00c82580
// src: XBOX_PDB 0x00c82580
float bhkBlendCollisionObject_GetBipBlendValue(void* arg)
{
    void* p = bhkBlendCollisionObject_GetFirstCollisionObject(arg);
    return p ? *(float*)((char*)p + 0x18) : 1.0f;
}

extern int DAT_011b09d8[];

// Copies the three ints of entry a from DAT_011b09d8 into the buffer c.
// @fnv 0x00c84cd0
// src: XBOX_PDB 0x00c84cd0
void __cdecl bhkShape_GetMaterialColor(int aiIndex, void* apOut)
{
    int* p = &DAT_011b09d8[aiIndex * 3];
    *(int*)apOut = p[0];
    *(int*)((char*)apOut + 4) = p[1];
    *(int*)((char*)apOut + 8) = p[2];
}

#include "../../include/bhkBoxShape.h"
#include "../../include/hkpShape.h"

// Points the Havok shape's user data back at this wrapper when b is set, otherwise clears it, then updates the reference.
// @fnv 0x00c84e50
// src: XBOX_PDB 0x00c84e50
void bhkBoxShape::bhkShape_Link(bool b)
{
    if (this && m_pHavokObject)
        static_cast<hkpShape*>(m_pHavokObject)->m_ulUserData = b ? (hkUlong)this : 0;
    UpdateReference(b);
}

struct FUN_00c87670_Class : NiObject
{
    void bhkSerializable_LinkObject(NiStream& stream);
    void* m_pad_0x8;
    void* m_field_0xc;
};
// @fnv 0x00c87670
// src: XBOX_PDB 0x00c87670
void FUN_00c87670_Class::bhkSerializable_LinkObject(NiStream& stream)
{
    NiObject::LinkObject(stream);
    if (m_field_0xc)
        ((void(__thiscall*)(FUN_00c87670_Class*, void*)) reinterpret_cast<void**>(
            reinterpret_cast<void**>(this)[0])[44])(this, m_field_0xc);
}

extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00c88a20_cls
{
    void __thiscall FUN_00c88930();
    void* __thiscall FUN_00c88a20(unsigned int flags);
};
// Calls FUN_00c88930, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c88a20
void* __thiscall FUN_00c88a20_cls::FUN_00c88a20(unsigned int flags)
{
    FUN_00c88930();
    if (flags & 1)
        operator delete(this, 0x2c);
    return this;
}

struct FUN_00cf4ce0_cls
{
    void hkpBinaryAction_setEntityA(int* arg);
};

struct FUN_00c8aa40_cls
{
    int* m_p0;
    int* m_p4;
    int* m_p8;
    void bhkBinaryAction_SetRigidBodyA(int* arg);
};

// @fnv 0x00c8aa40
// src: XBOX_PDB 0x00c8aa40
void FUN_00c8aa40_cls::bhkBinaryAction_SetRigidBodyA(int* pOther)
{
    if (this && m_p8)
        reinterpret_cast<FUN_00cf4ce0_cls*>(m_p8)->hkpBinaryAction_setEntityA(reinterpret_cast<FUN_00c8aa40_cls*>(pOther)->m_p8);
}

// @fnv 0x00c8cce0
// src: XBOX_PDB 0x00c8cce0
char bhkRigidBody_IsMotionTypeDynamic(int* piValue)
{
    char result = 0;
    int v = *piValue;
    if (v > 0 && (v <= 3 || v == 6))
        result = 1;
    return result;
}

extern MemoryManager g_memoryManager;
// @fnv 0x00c8cd00
// src: GUESS 0x00c8cd00 (confidence: medium)
void Object_ReleaseStorage_00c8cd00(void* apBlock)
{
    if (apBlock)
        g_memoryManager.Deallocate((char*)apBlock - *(const unsigned char*)((const char*)apBlock - 1));
}

// The array reset helper is not declared in the shared template; the view adds no storage.
struct BlendKeyArrayReset : NiTLargePrimitiveArray<BLENDKEY>
{
    void ResetEntriesAndCapacity();
};

struct FUN_00c9a820_class
{
    void Reset();
};

// Calls the sub-object at offset 0x38, then sets the floats at 0x54 and 0x50 to -1.0 and the int at 0x58 to 0.
// @fnv 0x00c9a820
void FUN_00c9a820_class::Reset()
{
    ((BlendKeyArrayReset*)((char*)this + 0x38))->ResetEntriesAndCapacity();
    *(float*)((char*)this + 0x54) = -1.0f;
    *(int*)((char*)this + 0x58) = 0;
    *(float*)((char*)this + 0x50) = -1.0f;
}

void __cdecl FUN_00c9ad60();
void __cdecl _delete(void* ptr, unsigned int size);
struct FUN_00c9af20_class
{
    void FUN_00c9ad60();
    void* FUN_00c9af20(int flag);
};
// @fnv 0x00c9af20
void* FUN_00c9af20_class::FUN_00c9af20(int aiFlags)
{
    FUN_00c9ad60();
    if (aiFlags & 1)
        _delete(this, 0x5c);
    return this;
}

extern int DAT_010c53b4;
extern void(__stdcall* DAT_010c53bc)(int*);
struct FUN_00c80630_holder
{
    int* m_vtbl;
    int* m_p4;
    int* m_p8;
    int* m_pc;
    void ResetHolder();
};
// @fnv 0x00c80630
void FUN_00c80630_holder::ResetHolder()
{
    int* old = m_p4;
    m_vtbl = (int*)&DAT_010c53b4;
    if (old)
    {
        DAT_010c53bc(old);
        m_p4 = 0;
        m_pc = 0;
        m_p8 = 0;
    }
}

struct FUN_00c81640_cls
{
    void* __thiscall FUN_00c81640(bool flag);
};

// @fnv 0x00c81640
void* __thiscall FUN_00c81640_cls::FUN_00c81640(bool abFree)
{
    *reinterpret_cast<void**>(this) = &DAT_010c53dc;
    --DAT_01267e60;
    reinterpret_cast<FUN_00c6c290_holder*>(this)->FUN_00c6c290();
    if (abFree & 1)
        _delete(this, 0x2c);
    return this;
}

extern NiPoint3 DAT_011a9490;
// Checks whether the NiPoint3 at offset 0x10 of p equals DAT_011a9490 and returns 1 if so, otherwise 0.
// @fnv 0x00c84ec0
// src: XBOX_PDB 0x00c84ec0
int __stdcall bhkShape_CanShare(void* apObject)
{
    NiPoint3* v = (NiPoint3*)((char*)apObject + 0x10);
    if (v->x == DAT_011a9490.x && v->y == DAT_011a9490.y && v->z == DAT_011a9490.z)
        return 1;
    return 0;
}

extern "C" void __stdcall EnterCriticalSection(void*);
extern int DAT_0126813c;
extern void* g_pEnterCriticalSection;
// @fnv 0x00c876f0
// src: XBOX_PDB 0x00c876f0
void bhkSerializable_CloneCritLock()
{
    ((void(__stdcall*)(void*))g_pEnterCriticalSection)(&DAT_0126813c);
}

extern int DAT_010c69f4;
struct FUN_00c6aca0_holder
{
    void* __thiscall FUN_00c6aca0();
};
struct FUN_00c9a040_cls
{
    void* __thiscall FUN_00c9a040(bool b);
};
// @fnv 0x00c9a040
void* __thiscall FUN_00c9a040_cls::FUN_00c9a040(bool abFree)
{
    *(void**)this = (void*)&DAT_010c69f4;
    ((FUN_00c6aca0_holder*)this)->FUN_00c6aca0();
    if (abFree & 1)
        g_memoryManager.Deallocate(this - *(unsigned char*)(this - 1));
    return this;
}

__forceinline int Sign_00c9a070(float f)
{
    return f < 0.0f ? -1 : 1;
}

struct Range_00c9a070
{
    float fHi;
    float fLo;
    Range_00c9a070(float h, float l) : fHi(h), fLo(l)
    {}
};

__forceinline void Adjust_00c9a070(float& out, float v, float fHi, float fLo)
{
    Range_00c9a070 r(fHi, fLo);
    float s = (float)Sign_00c9a070(v);
    float t = v + (r.fHi - r.fLo) * s;
    if (t * s > 0.0f)
        out -= t;
}

struct FUN_00c9a070_shell
{
    char _pad0[0xa0];
    float fLo[3];
    char _padac[0x14];
    float fHi[3];
    void AdjustVector(float* p);
};

// Adjusts each of the three components of p using the corresponding fHi/fLo bounds via Adjust_00c9a070.
// @fnv 0x00c9a070
void FUN_00c9a070_shell::AdjustVector(float* afVector)
{
    Adjust_00c9a070(afVector[0], afVector[0], fHi[0], fLo[0]);
    Adjust_00c9a070(afVector[1], afVector[1], fHi[1], fLo[1]);
    Adjust_00c9a070(afVector[2], afVector[2], fHi[2], fLo[2]);
}

namespace fnv_00c9a2c0 {

NiPoint3& SetNiPoint3FromHkVector4(NiPoint3& out, const hkVector4& in);
char* NiViewerStrings_NiGetViewerString_Title(const char*);
extern const char* g_012681e8;
extern __declspec(thread) int g_iTlsMemContext;

struct MemContextScope
{
    int iSaved;
    MemContextScope(int aiMemoryContext)
    {
        iSaved = g_iTlsMemContext;
        g_iTlsMemContext = aiMemoryContext;
    }
    ~MemContextScope()
    {
        g_iTlsMemContext = iSaved;
    }
};

struct FUN_00c9a2c0_shell
{
    char _pad0[0xa0];
    hkVector4 kWorldTotalSize;
    hkVector4 kBorderSize;
    void AppendReport(StrArr* pkStrings);
    void AppendWorldSizeStrings(StrArr* pkStrings);
};

// @fnv 0x00c9a2c0
void FUN_00c9a2c0_shell::AppendWorldSizeStrings(StrArr* pkStrings)
{
    MemContextScope kScope(0x10);
    AppendReport(pkStrings);
    char* pcString = NiViewerStrings_NiGetViewerString_Title(g_012681e8);
    (pkStrings->*static_cast<unsigned int (StrArr::*)(char*&)>(&StrArr::Add))(pcString);
    NiPoint3 kPoint;
    SetNiPoint3FromHkVector4(kPoint, kWorldTotalSize);
    pcString = static_cast<const NiPoint3&>(kPoint).FormatToBuffer("WorldTotalSize");
    (pkStrings->*static_cast<unsigned int (StrArr::*)(char*&)>(&StrArr::Add))(pcString);
    SetNiPoint3FromHkVector4(kPoint, kBorderSize);
    pcString = static_cast<const NiPoint3&>(kPoint).FormatToBuffer("BorderSize");
    (pkStrings->*static_cast<unsigned int (StrArr::*)(char*&)>(&StrArr::Add))(pcString);
}
}  // namespace fnv_00c9a2c0

extern int DAT_010c6b04;
extern "C" void __cdecl NiFree(void*);
// Scalar deletion wrapper for the shared large-array layout; no copied fields.
struct LargeArrayDeletingView : NiTLargeArray<BLENDKEY, NiTMallocInterface<BLENDKEY> >
{
    void* __thiscall FUN_00c9ae80(unsigned char b);
};
// Restores the large-array vtable, frees its buffer, and optionally deallocates this.
// @fnv 0x00c9ae80
void* __thiscall LargeArrayDeletingView::FUN_00c9ae80(unsigned char abFree)
{
    void* p = m_pBase;
    *reinterpret_cast<void**>(this) = &DAT_010c6b04;
    NiFree(p);
    if (abFree & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00c80660_t
{
    int* m_p0;
    int* m_p4;
    int* m_p8;
    int* m_pc;
    void* __thiscall FUN_00c80660(bool b);
};

// @fnv 0x00c80660
void* __thiscall FUN_00c80660_t::FUN_00c80660(bool abFree)
{
    int* p = m_p4;
    m_p0 = &DAT_010c53b4;
    if (p)
    {
        DAT_010c53bc(p);
        m_p4 = 0;
        m_pc = 0;
        m_p8 = 0;
    }
    if (abFree & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00c9aeb0_t
{
    char m_data[0x5c];
    FUN_00c9aeb0_t();
    ~FUN_00c9aeb0_t();
    static void* operator new(unsigned int);
};
// Allocates and constructs a new FUN_00c9aeb0_t object, returning its pointer.
// @fnv 0x00c9b020
// src: EXE 0x00c9b020
FUN_00c9aeb0_t* bhkBlendController_CreateObject()
{
    return new FUN_00c9aeb0_t;
}

struct FUN_00c9eba0_IFace
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
    virtual void FUN_00c9eba0_call(int a, int b, int c, int d);
};
// 0x00c9eba0 is also bound as ShapePhantom::LinearCast; its offset-8 Havok interface and no-op 0x00a29680 are unrelated to TES Script.
struct PhantomLinearCastWrapper
{
    void GetLocalData();
    void InvokeInterfaceCall(int a, int b, int c, int d);
};
extern int DAT_0126820c;
extern void(__stdcall* DAT_0126820c_enter)(int*);
extern void(__stdcall* DAT_0126820c_leave)(int*);
// @fnv 0x00c9eba0
void PhantomLinearCastWrapper::InvokeInterfaceCall(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    if (this)
    {
        FUN_00c9eba0_IFace* iface = *reinterpret_cast<FUN_00c9eba0_IFace**>(reinterpret_cast<unsigned char*>(this) + 8);
        if (iface)
        {
            DAT_0126820c_enter(&DAT_0126820c);
            GetLocalData();
            iface->FUN_00c9eba0_call(aiArg1, aiArg2, aiArg3, aiArg4);
            GetLocalData();
            DAT_0126820c_leave(&DAT_0126820c);
        }
    }
}

// The shared class has no declarations for these original base operations.
void CopyBlendCollisionObject();
void ConstructNiCollisionObject();

// Release the raw allocation if the original base constructor throws.
struct AllocationCleanup
{
    void* memory;
    __forceinline AllocationCleanup(void* block) : memory(block) {}
    __forceinline ~AllocationCleanup()
    {
        if (memory)
            ::operator delete(memory);
    }
};

// Construct through the shared layout while retaining the original inline initialization.
__forceinline bhkBlendCollisionObject* AllocateBlendCollisionObject()
{
    bhkBlendCollisionObject* object = (bhkBlendCollisionObject*)NiRefObject::operator new(sizeof(bhkBlendCollisionObject));
    AllocationCleanup cleanup(object);
    if (object)
    {
        ((void(__thiscall*)(bhkBlendCollisionObject*))&ConstructNiCollisionObject)(object);
        *(void**)object = &DAT_010c53dc;
        ++DAT_01267e60;
        object->m_f18 = 0.0f;
        *(unsigned short*)object->unk0C &= 0xfeff;
        object->m_f1c = 1.0f;
        object->m_i20 = 8;
        object->m_i24 = 0;
        object->m_i28 = 0;
        object->m_flag14 = 0;
    }
    else
    {
        cleanup.memory = 0;
        return 0;
    }
    cleanup.memory = 0;
    return object;
}

// @fnv 0x00c81670
bhkBlendCollisionObject* __fastcall CloneBlendCollisionObject(bhkBlendCollisionObject* self, void*, int value)
{
    bhkBlendCollisionObject* p = AllocateBlendCollisionObject();

    ((void(__thiscall*)(bhkBlendCollisionObject*, void*, int))&CopyBlendCollisionObject)(self, p, value);

    p->m_f1c = self->m_f1c;
    p->m_f18 = self->m_f18;
    p->m_i24 = self->m_i24;

    return p;
}

namespace fnv_00c81730 {
// Allocates and constructs a new bhkBlendCollisionObject, returning the pointer.
// @fnv 0x00c81730
bhkBlendCollisionObject* CreateBlendCollisionObject()
{
    return AllocateBlendCollisionObject();
}
}  // namespace fnv_00c81730


extern int _data_011c16bc;
extern char* _EmptyFS;
extern char const* const g_0126817c_arg1;

int* __cdecl BSUtilities_GetObjectByName_00c4b470(int, int, int);

struct StringHolder
{
    char* p;

    StringHolder(char const* str) : p(NiGlobalStringTable::AddString(str))
    {}

    ~StringHolder()
    {
        if (p != _EmptyFS)
        {
            InterlockedDecrement(reinterpret_cast<long*>(p - 8));
        }
    }
};

// Looks up a named property on param_1, dynamic-casts the result to a float-bearing object, and returns its value at offset 0x18, defaulting to 1.0f.
// @fnv 0x00c81b90
float GetFloatProperty(int aiObject, char const* apName)
{
    float result = 1.0f;

    if (aiObject != 0)
    {
        int* object;

        if (apName != 0)
        {
            {
                StringHolder str(apName);
                object = BSUtilities_GetObjectByName_00c4b470(aiObject, reinterpret_cast<int>(&str.p), 0);
            }

            if (object == 0)
            {
                object = reinterpret_cast<int*>(aiObject);
            }
        }
        else
        {
            object = reinterpret_cast<int*>(aiObject);
        }

        int* field = *reinterpret_cast<int**>(reinterpret_cast<char*>(object) + 0x1c);

        if (field != 0)
        {
            NiObject* casted = reinterpret_cast<NiObject*>(field)->DynamicCast(
                reinterpret_cast<unsigned int const*>(&g_0126817c_arg1));

            if (casted != 0)
            {
                result = *reinterpret_cast<float*>(reinterpret_cast<char*>(casted) + 0x18);
            }
        }
    }

    return result;
}

struct FUN_00c85ec0_t
{
    int* m_p0;
    int* m_p4;
    int* m_p8;
    int* m_pc;
    void CallVirtualOnNestedPointer();
};
// Follows m_p8 to a nested pointer chain and, if the final object exists, calls its vtable slot at offset 0xd8.
// @fnv 0x00c85ec0
void FUN_00c85ec0_t::CallVirtualOnNestedPointer()
{
    if (this && m_p8)
    {
        int* p = (int*)((char*)m_p8 + 0x10);
        if (p && *p)
        {
            int* q = *(int**)((char*)p);
            if (q && *(int**)((char*)q + 8))
            {
                int* r = *(int**)((char*)q + 8);
                int* s = *(int**)(char*)r;
                void** vt = (void**)(char*)s;
                void* fn = vt[0xd8 / 4];
                ((void(__thiscall*)(int*))fn)(r);
                return;
            }
        }
    }
}

struct FUN_00c87650_t : NiObject
{
    virtual void LoadBinary(NiStream& stream);
};

// Calls the base NiObject::LoadBinary, then dispatches virtual slot 43 on this with the stream.
// @fnv 0x00c87650
void FUN_00c87650_t::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    ((void(__thiscall*)(void*, NiStream&))(*(void***)this)[43])(this, stream);
}

extern "C" void __stdcall LeaveCriticalSection(void*);
void(__stdcall* DAT_0126813c_leave)(void*);
// @fnv 0x00c87700
// src: XBOX_PDB 0x00c87700
void bhkSerializable_CloneCritUnlock()
{
    DAT_0126813c_leave(&DAT_0126813c);
}

struct FUN_00c88410_t
{
    void FUN_00caa140();
    void* __thiscall FUN_00c88410(unsigned int flags);
};

// Calls FUN_00caa140, then deletes this with size 0x10 when flags has bit 0 set, and returns this.
// @fnv 0x00c88410
void* __thiscall FUN_00c88410_t::FUN_00c88410(unsigned int flags)
{
    FUN_00caa140();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

// @fnv 0x00c899c0
// src: XBOX_PDB 0x00c899c0
int __fastcall bhkConstraint_GethkEntityB(char* p, int edx)
{
    p = *(char**)(p + 8);
    int r = 0;
    if (p)
        r = *(int*)(p + 0x18);
    return r;
}

struct FUN_00c8a7e0_t
{
    void FUN_00c8a720();
    void* FUN_00c8a7e0(bool b);
};
// Calls FUN_00c8a720, then deletes this with size 0x10 when b has bit 0 set, and returns this.
// @fnv 0x00c8a7e0
void* FUN_00c8a7e0_t::FUN_00c8a7e0(bool abDelete)
{
    FUN_00c8a720();
    if (abDelete & 1)
        _delete(this, 0x10);
    return this;
}

struct FUN_00cf4d30_holder
{
    void SetRefObject(void*);
};
struct FUN_00c8aa60_holder
{
    int* m_auiShapeKeys;
    int* m_pAuxiliaryObject;
    int* m_target;
    void bhkBinaryAction_SetRigidBodyB(void* arg);
};
// @fnv 0x00c8aa60
// src: XBOX_PDB 0x00c8aa60
void FUN_00c8aa60_holder::bhkBinaryAction_SetRigidBodyB(void* arg)
{
    if (this && m_target)
    {
        void** p = (void**)arg;
        ((FUN_00cf4d30_holder*)m_target)->SetRefObject(p[2]);
    }
}

struct H_00c8c810
{
    void bhkShape_Link(bool);
    void InvokeCallbacksOnEntries();
    void ReleaseReferencedObjects();
    void bhkListShape_Link(bool b);
};
// Calls one of two methods depending on b, then forwards b to FUN_00c84e50.
// @fnv 0x00c8b410
// src: XBOX_PDB 0x00c8b410
void H_00c8c810::bhkListShape_Link(bool b)
{
    if (b)
        InvokeCallbacksOnEntries();
    else
        ReleaseReferencedObjects();
    bhkShape_Link(b);
}

namespace fnv_00c8c090 {
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base : public A51BF0Base
{
    S_00cb79d0_Base();
    int* volatile m_p0;
    int m_p4;
    int m_p8;
};

extern int DAT_01030bf4;
extern int DAT_01066d44;
extern int DAT_012680f8;
extern int DAT_012681b0;

struct Object_00c8c090 : public S_00cb79d0_Base
{
    int m_iThirdValue;
    int m_10;

    Object_00c8c090()
    {
        m_p0 = (int*)&DAT_01030bf4;
        m_iThirdValue = 0;
        m_10 = 0;
        ++DAT_012680f8;
        m_p0 = (int*)&DAT_01066d44;
        ++DAT_012681b0;
    }

    ~Object_00c8c090()
    {}
};

// Allocates and constructs a new Object_00c8c090, returning it as an S_00cb79d0_Base pointer.
// @fnv 0x00c8c090
// src: EXE 0x00c8c090
S_00cb79d0_Base* bhkTransformShape_CreateObject()
{
    return new Object_00c8c090;
}
}  // namespace fnv_00c8c090

extern int DAT_010c6fb0;
struct FUN_00c9d890_t
{
    int* m_p0;
    FUN_00c9d890_t(char b);
    ~FUN_00c9d890_t();
};
// Sets m_p0 to point at DAT_010c6fb0 and, if bit 0 of b is set, deletes this object.
// @fnv 0x00c9d890
FUN_00c9d890_t::FUN_00c9d890_t(char abDelete)
{
    m_p0 = &DAT_010c6fb0;
    if (abDelete & 1)
        operator delete(this);
}

extern __declspec(thread) unsigned int memoryCategory;

struct ScopedMemoryCategory
{
    unsigned int previous;
    ScopedMemoryCategory() : previous(memoryCategory)
    {
        memoryCategory = 16;
    }
    ~ScopedMemoryCategory()
    {
        memoryCategory = previous;
    }
};

struct ArenaAllocator
{
    virtual void Reserved();
    virtual char* Allocate(unsigned int bytes);
};

struct TemporaryArena
{
    char* start;
    char* cursor;
    char* end;
    ArenaAllocator* current;
    ArenaAllocator* allocator;
    unsigned int unk14;
    ArenaAllocator* saved;
    unsigned int unk1C;
    unsigned int unk20;
    TemporaryArena();
    static void* operator new(unsigned int bytes)
    {
        return static_cast<MemoryManager*>(&g_memoryManager)->Allocate(bytes);
    }
};

struct ArenaRegistrationFlag
{
    unsigned int value;
    ArenaRegistrationFlag() : value(1)
    {}
    ArenaRegistrationFlag(const ArenaRegistrationFlag& other) : value(other.value)
    {}
};

struct ArenaRegistry
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Register(TemporaryArena*, const char*, ArenaRegistrationFlag);
};

ArenaRegistry* hkMemorySystem_getInstance();
void hkBaseSystem_initThread(TemporaryArena*);
extern const char DAT_010c53c4[];
extern unsigned int DAT_01267e48;
extern "C" __declspec(dllimport) void __stdcall ArenaEnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall ArenaLeaveCriticalSection(void*);

struct ArenaOwner
{
    TemporaryArena* arena;
    char* buffer;
};

// If owner->arena is null, allocates a 0x5000-byte arena under a critical section, registers and initialises it, and stores it in owner->arena.
// @fnv 0x00c80130
void EnsureArenaAllocated(ArenaOwner* owner)
{
    ScopedMemoryCategory category;
    if (!owner->arena)
    {
        ArenaEnterCriticalSection(&DAT_01267e48);
        TemporaryArena scratch;
        TemporaryArena* arena = new TemporaryArena;
        hkMemorySystem_getInstance()->Register(arena, DAT_010c53c4, ArenaRegistrationFlag());
        hkBaseSystem_initThread(arena);
        arena->current = arena->allocator;
        arena->saved = arena->allocator;
        arena->start = arena->cursor = owner->buffer = arena->allocator->Allocate(0x5000);
        arena->end = arena->start + 0x5000;
        owner->arena = arena;
        ArenaLeaveCriticalSection(&DAT_01267e48);
    }
}

struct FlaggedObj_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
};

struct WalkNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual WalkNode_cls* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    FlaggedObj_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    WalkNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

// @fnv 0x00c80330
void SetFlagRecursive(bool abSet, WalkNode_cls* node)
{
    FlaggedObj_cls* f = node->m_1c;
    if (f != 0)
    {
        if (abSet)
        {
            f->m_0c |= 0x20;
        }
        else
        {
            f->m_0c &= 0xffdf;
        }
    }

    WalkNode_cls* child = node->v03();
    if (child != 0)
    {
        unsigned int i = 0;
        while (i < child->m_a6)
        {
            WalkNode_cls** arr = child->m_a0;
            WalkNode_cls* item = arr[i];
            if (item != 0)
            {
                SetFlagRecursive(abSet, item);
            }
            ++i;
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

extern MemoryManager _g_memoryManager;
struct GlobalObject_004ee810
{
    ~GlobalObject_004ee810();
};
struct FUN_00c80570_Node
{
    NiPointer<AnimIdle> key;
    FUN_00c80570_Node* next;
    void RemoveNode(const NiPointer<AnimIdle>* keyp);
};
template <> inline NiPointer<AnimIdle>& NiPointer<AnimIdle>::operator=(const NiPointer<AnimIdle>& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = other.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

// @fnv 0x00c80570
void FUN_00c80570_Node::RemoveNode(const NiPointer<AnimIdle>* apKey)
{
    AnimIdle* k = apKey->m_pObject;
    if (!k)
        return;
    FUN_00c80570_Node* nx = next;
    if (!nx && !key.m_pObject)
        return;
    FUN_00c80570_Node* cur = this;
    FUN_00c80570_Node* prev = this;
    do
    {
        if (cur->key.m_pObject == k)
            break;
        prev = cur;
        cur = cur->next;
    } while (cur);
    if (!cur)
        return;
    if (cur == this)
    {
        if (nx)
        {
            next = nx->next;
            key = nx->key;
            nx->next = 0;
            reinterpret_cast<GlobalObject_004ee810*>(nx)->~GlobalObject_004ee810();
            _g_memoryManager.Deallocate(nx);
            return;
        }
        AnimIdle* r = key.m_pObject;
        if (r)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&r->m_uiRefCount)) == 0)
                r->DeleteThis();
            key.m_pObject = 0;
        }
        return;
    }
    prev->next = cur->next;
    cur->next = 0;
    reinterpret_cast<GlobalObject_004ee810*>(cur)->~GlobalObject_004ee810();
    _g_memoryManager.Deallocate(cur);
}

struct SpawnedPtrArray
{
    void** m_pData;
    unsigned int m_uiCount;
    unsigned int m_uiCapacity;
};

extern "C" void _ReadWriteBarrier(void);
void* bhkUtilFunctions_FindConstrainedSystemRoot(void* a1);
hkMemoryRouter* hkMemoryRouter_getInstance();
void ResizeAudioStream(void* allocator, SpawnedPtrArray* arr, unsigned int growBy);

// Resolves an item from a1, grows arr by 4 if full, then stores the item at the next slot and increments the count.
// @fnv 0x00c809e0
void AppendSpawnedPtr(void* a1, SpawnedPtrArray* arr)
{
    void* item = bhkUtilFunctions_FindConstrainedSystemRoot(a1);
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    if (arr->m_uiCount == (arr->m_uiCapacity & 0x3fffffff))
    {
        ResizeAudioStream(holder->m_heap, arr, 4);
    }
    void** slot = (void**)((unsigned int)arr->m_pData + arr->m_uiCount * 4);
    _ReadWriteBarrier();
    *slot = item;
    arr->m_uiCount++;
}

inline void* __cdecl operator new(unsigned int, void* placement)
{
    return placement;
}
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);

extern NiAllocator DAT_011f6238;
struct RefNode
{
    NiRefObject* item;
    RefNode* next;
    __forceinline RefNode(NiRefObject* p)
    {
        item = p;
        if (p)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
        next = 0;
    }
};
struct RefOwner
{
    NiRefObject* item;
    RefNode* head;
    void __thiscall FUN_006e5cc0(int* param);
    void __thiscall AllocateStorage_00c80a30(int* param);
};
// If *param is set, prepends a RefNode holding item to head (when item exists) and calls FUN_006e5cc0(param).
// @fnv 0x00c80a30
// src: GUESS 0x00c80a30 (confidence: low)
void RefOwner::AllocateStorage_00c80a30(int* param)
{
    if (*param)
    {
        if (item)
        {
            void* memory = DAT_011f6238.Allocate(8);
            RefNode* node = memory ? new (memory) RefNode(item) : 0;
            node->next = head;
            head = node;
            FUN_006e5cc0(param);
            return;
        }
        FUN_006e5cc0(param);
    }
}

struct FUN_00c80b20_item8
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

struct FUN_00c80b20_cls
{
    virtual void Slot0();
    virtual void* AllocBuffer(unsigned int count);
    virtual void FreeBuffer(void* buffer);
    FUN_00c80b20_item8* m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReservedSize;
    unsigned int AppendSlot();
    void CopyItems(void* dst, void* src, unsigned int count);
    void InsertItemAt(unsigned int index, FUN_00c80b20_item8& item);
};

// Inserts an item at the given index, growing the buffer if full and shifting later items up by one slot.
// @fnv 0x00c80b20
void FUN_00c80b20_cls::InsertItemAt(unsigned int index, FUN_00c80b20_item8& item)
{
    if (index == m_uiLogicalSize)
    {
        unsigned int slot = AppendSlot();
        m_pBuffer[slot] = item;
        return;
    }
    if (m_uiLogicalSize == m_iReservedSize)
    {
        unsigned int newCap = m_iReservedSize > 0x400 ? m_iReservedSize + 0x400 : m_iReservedSize * 2;
        char* newBuf = (char*)AllocBuffer(newCap);
        CopyItems(newBuf, m_pBuffer, index);
        CopyItems(newBuf + index * 8 + 8, (char*)m_pBuffer + index * 8, m_uiLogicalSize - index);
        FreeBuffer(m_pBuffer);
        m_pBuffer = (FUN_00c80b20_item8*)newBuf;
        m_iReservedSize = newCap;
    }
    else
    {
        CopyItems((char*)m_pBuffer + index * 8 + 8, (char*)m_pBuffer + index * 8, m_uiLogicalSize - index);
    }
    m_uiLogicalSize++;
    m_pBuffer[index] = item;
}

// FUN_00c81570 : a one-line function - getter
extern int g_target_00c81570;
// @fnv 0x00c81570
// src: COMMUNITY 0x00c81570
void* bhkBlendCollisionObject_GetRTTI()
{
    return &g_target_00c81570;
}

struct FUN_00c81580_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_f18;
    float m_f1C;
    int unk20;
    int m_i24;
    void bhkPCollisionObject_CopyMembers(FUN_00c81580_cls* dest, void* other);
    void bhkBlendCollisionObject_CopyMembers(FUN_00c81580_cls* dest, void* other);
};

// @fnv 0x00c81580
// src: XBOX_PDB 0x00c81580
void FUN_00c81580_cls::bhkBlendCollisionObject_CopyMembers(FUN_00c81580_cls* dest, void* other)
{
    this->bhkPCollisionObject_CopyMembers(dest, other);
    dest->m_f1C = m_f1C;
    dest->m_f18 = m_f18;
    dest->m_i24 = m_i24;
}

class C815B0Base
{
  public:
    bool IsEqual(C815B0Base* pkOther);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class C815B0Constraint : public C815B0Base
{
  public:
    float m_fMinAngle;
    float m_fMaxAngle;

    bool bhkBlendCollisionObject_IsEqual(C815B0Constraint* pkOther);
};

// Compares the base fields via C815B0Base::IsEqual, then checks that m_fMaxAngle and m_fMinAngle match the other constraint's values.
// @fnv 0x00c815b0
// src: XBOX_PDB 0x00c815b0
bool C815B0Constraint::bhkBlendCollisionObject_IsEqual(C815B0Constraint* pkOther)
{
    bool bEqual = C815B0Base::IsEqual(pkOther);
    if (bEqual)
    {
        bEqual = pkOther->m_fMaxAngle == m_fMaxAngle;
        bEqual &= pkOther->m_fMinAngle == m_fMinAngle;
    }
    return bEqual;
}

extern int DAT_010c53dc;
extern int DAT_01267e60;

struct FUN_00c6b910_holder
{
    void NiRTTI_UpdateState_00c6b910();
};

struct FUN_00c81600_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
    unsigned short unk0e;
    unsigned int unk10;
    unsigned char m_14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    float m_18;
    float m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;

    FUN_00c81600_cls* Initialize();
};

// @fnv 0x00c81600
FUN_00c81600_cls* FUN_00c81600_cls::Initialize()
{
    reinterpret_cast<FUN_00c6b910_holder*>(this)->NiRTTI_UpdateState_00c6b910();
    *(int**)this = &DAT_010c53dc;
    DAT_01267e60++;
    m_18 = 0.0f;
    m_1c = 1.0f;
    m_24 = 0;
    m_28 = 0;
    m_14 = 0;
    m_0c &= 0xfeff;
    m_20 = 8;
    return this;
}

struct C819A0Range
{
    float m_fMinimum;
    float m_fMaximum;
};

extern C819A0Range g_akC819A0Ranges[];

class C819A0Primary
{
  public:
    virtual ~C819A0Primary();

    int unk04;
    int unk08;
    int unk0C;
};

class C819A0Secondary
{
  public:
    virtual ~C819A0Secondary();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiValue1;
};

class C819A0Object : public C819A0Primary, public C819A0Secondary
{
};

class C819A0Holder
{
  public:
    int unk00;
    int unk04;
    C819A0Object* m_pPointer;
};

class C819A0Base
{
  public:
    void Init(void* pvParam);

    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    short unk0E;
    C819A0Holder* m_pkHolder;
    int unk14;
};

class C819A0Derived : public C819A0Base
{
  public:
    void InitFromFlags(void* pvParam);

    float m_fMinimum;
    float m_fMaximum;
};

// @fnv 0x00c819a0
void C819A0Derived::InitFromFlags(void* pvParam)
{
    Init(pvParam);
    m_usFlags |= 0x28;

    C819A0Secondary* pkSecondary = m_pkHolder->m_pPointer;
    unsigned int uiFlags = pkSecondary ? pkSecondary->m_uiValue1 : 0;
    unsigned int uiIndex = (uiFlags >> 8) & 0x1f;
    m_fMinimum = g_akC819A0Ranges[uiIndex].m_fMinimum;
    m_fMaximum = g_akC819A0Ranges[uiIndex].m_fMaximum;
}

class FUN_00c81aa0_poly
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
    virtual void v39(int a);
    int unk04;
    unsigned int m_08;
};

class FUN_00c81aa0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FUN_00c81aa0_poly* m_10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    int m_24;
    void bhkBlendCollisionObject_UpdateAddedToWorld();
};

// Reads a masked type from m_10's m_08 chain and, if it is 8 or 0x1d and m_24 is nonzero, calls the poly's v39 with m_24.
// @fnv 0x00c81aa0
// src: COMMUNITY 0x00c81aa0
void FUN_00c81aa0_cls::bhkBlendCollisionObject_UpdateAddedToWorld()
{
    FUN_00c81aa0_poly* p = m_10;
    if (p != 0)
    {
        unsigned int t = p->m_08;
        if (t != 0)
        {
            t += 0x10;
            if (t != 0)
            {
                t = *(unsigned int*)(t + 0x1c);
            }
            else
            {
                t = 0;
            }
        }
        else
        {
            t = 0;
        }
        t &= 0x7f;
        if (t == 8 || t == 0x1d)
        {
            if (m_24 != 0)
            {
                p->v39(m_24);
            }
        }
    }
}

struct FUN_00c81ae0_target
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
    virtual void v39(void* arg);
};

struct FUN_00c81ae0_cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FUN_00c81ae0_target* m_10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* m_24;
    unsigned int m_28;

    void bhkBlendCollisionObject_ForceUpdateWorldData();
    void InitOnce();
};

// @fnv 0x00c81ae0
void FUN_00c81ae0_cls::InitOnce()
{
    bool first = m_28 == 0;
    m_28++;
    if (first)
    {
        bhkBlendCollisionObject_ForceUpdateWorldData();
        FUN_00c81ae0_target* obj = m_10;
        if (obj != 0)
        {
            unsigned int p = *(unsigned int*)((char*)obj + 8);
            unsigned int flags;
            if (p != 0)
            {
                p += 0x10;
                if (p != 0)
                {
                    flags = *(unsigned int*)(p + 0x1c);
                }
                else
                {
                    flags = 0;
                }
            }
            else
            {
                flags = 0;
            }
            flags &= 0x7f;
            if (flags == 8 || flags == 0x1d)
            {
                void* arg = m_24;
                if (arg != 0)
                {
                    obj->v39(arg);
                }
            }
        }
    }
}

struct TreeResult_cls
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
    virtual TreeResult_cls* v0f();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int m_24;
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
    virtual void v14();
    TreeResult_cls* __thiscall FindResult(unsigned int* rtti);
};

struct TreeNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual TreeNode_cls* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    TreeHost_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    TreeNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

extern unsigned int DAT_012043f8;

// Recursively stores value into the result's m_24 for node and all children found via v03 and m_a0.
// @fnv 0x00c81db0
void SetTreeValue(TreeNode_cls* node, unsigned int value)
{
    if (node == 0)
    {
        return;
    }

    TreeHost_cls* host = node->m_1c;
    if (host != 0)
    {
        TreeResult_cls* result = host->FindResult(&DAT_012043f8);
        if (result != 0)
        {
            TreeResult_cls* r = result->v0f();
            if (r != 0)
            {
                r->m_24 = value;
            }
        }
    }

    TreeNode_cls* child = node->v03();
    if (child != 0)
    {
        for (unsigned int i = 0; i < child->m_a6; i++)
        {
            SetTreeValue(child->m_a0[i], value);
        }
    }
}

extern unsigned __int64 selected_target_masks[];

// Sets or clears the symmetric bits for uiA and uiB in selected_target_masks according to bSelected.
// @fnv 0x00c827f0
void SetSelectionMask(unsigned int uiIndexA, unsigned int uiIndexB, bool bSelected)
{
    if (bSelected)
    {
        selected_target_masks[uiIndexA] |= (unsigned __int64)1 << uiIndexB;
        selected_target_masks[uiIndexB] |= (unsigned __int64)1 << uiIndexA;
    }
    else
    {
        selected_target_masks[uiIndexA] &= ~((unsigned __int64)1 << uiIndexB);
        selected_target_masks[uiIndexB] &= ~((unsigned __int64)1 << uiIndexA);
    }
}

extern NiColor DAT_011a9b7c;

// Writes the NiColor associated with the low 7 bits of layer into out, falling back to DAT_011a9b7c for unknown layers.
// @fnv 0x00c84470
void __cdecl GetLayerColor(unsigned int layer, NiColor& rColor)
{
    switch (layer & 0x7f)
    {
    case 1:
        rColor = NiColor(1.0f, 0.0f, 0.0f);
        break;
    case 2:
    case 10:
        rColor = NiColor(0.9f, 0.24f, 0.92f);
        break;
    case 3:
        rColor = NiColor(0.96f, 0.8f, 0.8f);
        break;
    case 4:
        rColor = NiColor(0.27f, 0.41f, 0.94f);
        break;
    case 5:
        rColor = NiColor(0.85f, 0.61f, 0.16f);
        break;
    case 6:
        rColor = NiColor(0.9f, 0.73f, 0.42f);
        break;
    case 7:
        rColor = NiColor(0.23f, 0.97f, 0.9f);
        break;
    case 8:
        rColor = NiColor(0.0f, 1.0f, 0.0f);
        break;
    case 9:
        rColor = NiColor(0.8f, 0.62f, 0.45f);
        break;
    case 11:
        rColor = NiColor(0.51f, 0.98f, 0.98f);
        break;
    case 12:
    case 14:
        rColor = NiColor(0.73f, 0.76f, 0.75f);
        break;
    case 16:
        rColor = NiColor(0.73f, 0.78f, 0.7f);
        break;
    case 13:
        rColor = NiColor(0.96f, 0.97f, 0.52f);
        break;
    case 17:
        rColor = NiColor(0.96f, 0.97f, 0.52f);
        break;
    case 18:
        rColor = NiColor(0.0f, 0.7f, 0.0f);
        break;
    case 30:
        rColor = NiColor(1.0f, 1.0f, 0.0f);
        break;
    case 31:
        rColor = NiColor(1.0f, 0.8f, 0.0f);
        break;
    case 24:
        rColor = NiColor(0.45f, 0.6f, 0.1f);
        break;
    default:
        rColor = DAT_011a9b7c;
        break;
    }
}

struct ObjA
{
    unsigned char m_flag;
    unsigned char unk01[0x1b];
    void* m_p1c;
};
extern "C" unsigned char __cdecl bhkCollisionFilter_IsCollisionEnabled(void* pA, void* pB);
// Calls FUN_00c84740 with the m_p1c pointers of p2 and p3, stores the returned byte in p1->m_flag and returns p1.
// @fnv 0x00c84880
// src: COMMUNITY 0x00c84880
ObjA* __stdcall bhkCollisionFilter_isCollisionEnabled(ObjA* p1, ObjA* p2, ObjA* p3)
{
    void* pB = p2->m_p1c;
    void* pA = p3->m_p1c;
    unsigned char result = bhkCollisionFilter_IsCollisionEnabled(pB, pA);
    p1->m_flag = result;
    return p1;
}

struct ChainNode
{
    int m_00;
    int m_04;
    int m_08;
    ChainNode* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};

unsigned char __cdecl bhkCollisionFilter_IsCollisionEnabled(int a1, int a2);

// @fnv 0x00c848b0
// src: COMMUNITY 0x00c848b0
unsigned char* __stdcall bhkCollisionFilter_isCollisionEnabled_00c848b0(unsigned char* pResult, int a2, ChainNode* pChainA, ChainNode* pChainB, int a5,
                                      int a6)
{
    ChainNode* p = pChainB;
    while (p->m_0c != 0)
    {
        p = p->m_0c;
    }
    int tailB = ((volatile ChainNode*)p)->m_1c;

    ChainNode* q = pChainA;
    while (q->m_0c != 0)
    {
        q = q->m_0c;
    }
    int tailA = q->m_1c;
    *pResult = bhkCollisionFilter_IsCollisionEnabled(tailA, tailB);
    return pResult;
}

// FUN_00c84930: stdcall 3-arg wrapper.
//   a2->m_24 and a3->m_1c are passed to the cdecl helper FUN_00c84740,
//   the resulting byte is written through the first (out) parameter, which is returned.
unsigned char __cdecl bhkCollisionFilter_IsCollisionEnabled(int a1, int a2);

struct NodeA
{
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
};

struct NodeB
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};

// @fnv 0x00c84930
// src: COMMUNITY 0x00c84930
unsigned char* __stdcall bhkCollisionFilter_isCollisionEnabled_00c84930(unsigned char* pResult, NodeA* pNodeA, NodeB* pNodeB)
{
    int v1 = pNodeB->m_1c;
    int v2 = pNodeA->m_24;
    *pResult = bhkCollisionFilter_IsCollisionEnabled(v2, v1);
    return pResult;
}

namespace fnv_00c84960 {
struct ChainNode
{
    int m_00;
    int m_04;
    int m_08;
    ChainNode* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};

unsigned char __cdecl bhkCollisionFilter_IsCollisionEnabled(int a1, int a2);

// @fnv 0x00c84960
// src: COMMUNITY 0x00c84960
unsigned char* __stdcall bhkCollisionFilter_isCollisionEnabled_00c84960(unsigned char* pResult, int aiUnused, ChainNode* pChainA, ChainNode* pChainB,
                                      int a5, int a6, int a7, int a8)
{
    ChainNode* q = pChainA;
    while (q->m_0c != 0)
    {
        q = q->m_0c;
    }
    int tailA = q->m_1c;

    ChainNode* p = pChainB;
    while (p->m_0c != 0)
    {
        p = p->m_0c;
    }
    int tailB = p->m_1c;

    *pResult = bhkCollisionFilter_IsCollisionEnabled(tailA, tailB);
    return pResult;
}
}  // namespace fnv_00c84960

struct FUN_00c84dc0_param
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

struct FUN_00c84dc0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    bool BSAnimNotes_IsEqual(FUN_00c84dc0_param* p);
    bool bhkShape_IsEqual(FUN_00c84dc0_param* p);
};

// Calls FUN_00ba87d0 on p and, if true, checks that the low 5 bits of p->m_10 XOR this->m_10 are zero.
// @fnv 0x00c84dc0
// src: XBOX_PDB 0x00c84dc0
bool FUN_00c84dc0_cls::bhkShape_IsEqual(FUN_00c84dc0_param* pParam)
{
    bool b = this->BSAnimNotes_IsEqual(pParam);
    if (b)
    {
        unsigned int x = pParam->m_10 ^ this->m_10;
        b = (x & 0x1f) == 0;
    }
    return b;
}

class FUN_00c84df0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int m_10;

    void bhkSerializable_CopyMembers(FUN_00c84df0_cls* first, FUN_00c84df0_cls* second);
    void bhkShape_CopyMembers(FUN_00c84df0_cls* first, FUN_00c84df0_cls* second);
};

// Calls FUN_00c87600 with first and second, then copies the low 5 bits of m_10 into first->m_10.
// @fnv 0x00c84df0
// src: XBOX_PDB 0x00c84df0
void FUN_00c84df0_cls::bhkShape_CopyMembers(FUN_00c84df0_cls* first, FUN_00c84df0_cls* second)
{
    bhkSerializable_CopyMembers(first, second);
    first->m_10 = m_10 & 0x1f;
}

struct FUN_00c84e80_holder
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_next;
    int __thiscall ApplyToNext(int* arg_2);
};

extern void __cdecl hkpInertiaTensorComputer_computeShapeVolumeMassProperties(void* object, float value, int* data);

// If this and m_next are non-null, passes m_next, the float at arg_2[1] and arg_2 to FUN_00cf0690; otherwise returns 1.
// @fnv 0x00c84e80
int FUN_00c84e80_holder::ApplyToNext(int* pData)
{
    int result = 0;

    if (this != 0 && m_next != 0)
    {
        float value = reinterpret_cast<float*>(pData)[1];
        hkpInertiaTensorComputer_computeShapeVolumeMassProperties(m_next, value, pData);
    }
    else
    {
        result = 1;
    }

    return result;
}

// Target class of the first virtual call
class TargetCls
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
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual int v56(int a);
};

class FUN_00c84f10_cls
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
    virtual void v49();
    virtual void v50();
    virtual TargetCls* v51();
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int bhkShape_GetSubshapeMaterial(int a);
};

// If a is not -1 and v51() returns an object, forwards a to its v56; otherwise returns m_i10 masked to 0x1f.
// @fnv 0x00c84f10
// src: XBOX_PDB 0x00c84f10
int FUN_00c84f10_cls::bhkShape_GetSubshapeMaterial(int a)
{
    if (a != -1)
    {
        TargetCls* p = v51();
        if (p)
        {
            return p->v56(a);
        }
    }
    return m_i10 & 0x1f;
}

class FUN_00c84f50_cls
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
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual FUN_00c84f50_cls* GetNext();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_flags10;
    bool bhkShape_GetSubMaterialVarType(int a1, unsigned int a2);
};

// @fnv 0x00c84f50
// src: XBOX_PDB 0x00c84f50
bool FUN_00c84f50_cls::bhkShape_GetSubMaterialVarType(int a1, unsigned int auiFlags)
{
    FUN_00c84f50_cls* p = this;
    while (a1 != -1)
    {
        FUN_00c84f50_cls* n = p->GetNext();
        if (n == 0 || n == p)
            break;
        p = n;
    }
    return ((p->m_flags10 & auiFlags) != 0) == auiFlags;
}

struct BaseThunk
{
    bool BSTextureSet_RegisterStreamables(NiStream& stream);
};

struct C_t
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
    virtual void v15(NiStream* a);
};

struct B_t
{
    int unk00;
    int unk04;
    C_t* unk08;
};

struct A_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    B_t* unk10;
};

struct FUN_00c85ac0_cls : BaseThunk
{
    int unk00;
    int unk04;
    A_t* unk08;

    void bhkWorldObject_RegisterStreamables(NiStream* a);
};

// Walks this->unk08 to a nested object and calls its v15 with the stream, then calls FUN_00a81fe0 on the stream.
// @fnv 0x00c85ac0
// src: XBOX_PDB 0x00c85ac0
void FUN_00c85ac0_cls::bhkWorldObject_RegisterStreamables(NiStream* pStream)
{
    if (this)
    {
        A_t* pa = this->unk08;
        if (pa)
        {
            B_t** ppb = &pa->unk10;
            if (ppb)
            {
                B_t* pb = *ppb;
                if (pb)
                {
                    C_t* pc = pb->unk08;
                    if (pc)
                        pc->v15(pStream);
                }
            }
        }
    }
    this->BSTextureSet_RegisterStreamables(*pStream);
}

struct TlsBlock_t
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
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

class RefLeaf_t
{
  public:
    virtual void unk00();
    virtual void unk04();
    unsigned int m_04;
};

struct Inner_t;

struct Mid_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Inner_t* m_10;
};

struct Inner_t
{
    int unk00;
    int unk04;
    RefLeaf_t* m_08;
};

struct FUN_00c85b00_cls
{
    int unk00;
    int unk04;
    Mid_t* m_08;

    void bhkWorldObject_RembhkShapeRef();
};

// @fnv 0x00c85b00
// src: XBOX_PDB 0x00c85b00
void FUN_00c85b00_cls::bhkWorldObject_RembhkShapeRef()
{
    TlsGuard_t guard;
    if (this != 0)
    {
        Mid_t* a = m_08;
        if (a)
        {
            Inner_t** pb = &a->m_10;
            Inner_t* b = 0;
            if (pb)
                b = *pb;
            if (b)
            {
                RefLeaf_t* c = b->m_08;
                if (c)
                {
                    if (InterlockedDecrement((volatile long*)&c->m_04) == 0)
                    {
                        c->unk04();
                    }
                }
            }
        }
    }
}

class BC85BA0Target
{
  public:
    int unk00;
    long m_lRefCount;
};

class BC85BA0Link
{
  public:
    int unk00;
    int unk04;
    BC85BA0Target* m_pkTarget;
};

class BC85BA0Holder
{
  public:
    BC85BA0Link* m_pkLink;
};

class BC85BA0HkObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    void* m_pvUserData;
    BC85BA0Holder m_kHolder;
};

class BC85BA0WorldObject : public bhkRefObject
{
  public:
    void bhkWorldObject_RembhkShapeRef();
    void SetHkObjectUserData(bool bAdd);

};

// @fnv 0x00c85ba0
void BC85BA0WorldObject::SetHkObjectUserData(bool bAdd)
{
    BC85BA0WorldObject* pkUser;
    if (bAdd)
    {
        if (this && ((BC85BA0HkObject*)m_pHavokObject))
        {
            BC85BA0Holder* pkHolder = &((BC85BA0HkObject*)m_pHavokObject)->m_kHolder;
            if (pkHolder && pkHolder->m_pkLink && pkHolder->m_pkLink->m_pkTarget)
                InterlockedIncrement(&pkHolder->m_pkLink->m_pkTarget->m_lRefCount);
        }
        pkUser = this;
    }
    else
    {
        ((void(__thiscall*)(bhkRefObject*))(*(void***)this)[40])(this);
        bhkWorldObject_RembhkShapeRef();
        pkUser = 0;
    }
    if (this && ((BC85BA0HkObject*)m_pHavokObject))
        ((BC85BA0HkObject*)m_pHavokObject)->m_pvUserData = pkUser;
    UpdateReference(bAdd);
}

struct S_00c85ce0_First
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00c85ce0_Inner
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
struct S_00c85ce0_Obj : S_00c85ce0_First, S_00c85ce0_Inner
{
};
struct S_00c85ce0
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vfc4();
    int unk04;
    S_00c85ce0_Obj* unk08;
    void bhkWorldObject_SetCollisionGroup(unsigned int a1);
};
// Replaces the high 16 bits of unk08->unk1c with a1, keeping the low 16 bits, then calls vfc4.
// @fnv 0x00c85ce0
// src: XBOX_PDB 0x00c85ce0
void S_00c85ce0::bhkWorldObject_SetCollisionGroup(unsigned int uiHighWord)
{
    S_00c85ce0_Obj* p = unk08;
    unsigned int old = (p && (S_00c85ce0_Inner*)p) ? ((S_00c85ce0_Inner*)p)->unk1c : 0;
    unsigned int flags = (old & 0xffff) | (uiHighWord << 16);
    if (p && (S_00c85ce0_Inner*)p)
        ((S_00c85ce0_Inner*)p)->unk1c = flags;
    vfc4();
}

struct FUN_00c87600_Base
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
};

struct FUN_00c87600_Arg : FUN_00c87600_Base
{
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void* vfB0(void* value);
};

struct FUN_00c87600_Obj : FUN_00c87600_Base
{
    virtual void vfA4(int value);
    virtual void vfA8();
    virtual void vfAC();
    virtual void* vfB0(void* value);
    virtual void* vfB4(void* value);

    void __thiscall bhkSerializable_CopyMembers(void* arg1, void* arg2);
};

struct FUN_00a5d450_helper
{
    void __thiscall CreateVertexBufferSet(void* arg1, void* arg2);
};

// Calls the base helper with arg1 and arg2, passes the result of vfB4 to arg1's vfB0, then calls vfA4 with 1.
// @fnv 0x00c87600
// src: XBOX_PDB 0x00c87600
void __thiscall FUN_00c87600_Obj::bhkSerializable_CopyMembers(void* pTarget, void* arg2)
{
    reinterpret_cast<FUN_00a5d450_helper*>(this)->CreateVertexBufferSet(pTarget, arg2);

    void* result = this->vfB4(&arg2);
    reinterpret_cast<FUN_00c87600_Arg*>(pTarget)->vfB0(result);

    this->vfA4(1);
}

// TailOne: thiscall, 18 bytes. Self virtual call at slot 0xa4 (index 41) tail-jumped with constant 1 in the stack arg.
struct FUN_00c876d0_cls
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
    virtual void Tail(int a);
    void TailOne(int a);
};

// @fnv 0x00c876d0
void FUN_00c876d0_cls::TailOne(int a)
{
    this->Tail(1);
}

class C87710HavokObject
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
    virtual unsigned int GetDataSize();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void* GetData(bool& bIsValid);

    unsigned int bhkSerializable_LoadCInfo(NiStream& kStream);
};

// Reads the object's data block of GetDataSize() bytes from the stream into the buffer returned by GetData and returns that size.
// @fnv 0x00c87710
// src: XBOX_PDB 0x00c87710
unsigned int C87710HavokObject::bhkSerializable_LoadCInfo(NiStream& kStream)
{
    bool bIsValid;
    void* pvData = GetData(bIsValid);
    unsigned int uiSize = GetDataSize();
    ReadStream(kStream)->BinaryRead(pvData, uiSize, (unsigned int*)0, 0);
    return uiSize;
}

template <class T>
inline void BC87850BinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BC87850SaveBinary(NiStream& kStream, const T& value)
{
    BC87850BinaryStreamSave(*WriteStreamBuffer(kStream), &value);
}

class BC87850RefObject
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
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void VFuncA0();
    virtual void FreeSerializeData(int iHandle);
    virtual unsigned int GetSerializeSize();
    virtual void VFuncAC();
    virtual void VFuncB0();
    virtual char* GetSerializeData(int* piHandle);

    void BaseSaveBinary(NiStream& kStream);
    void SaveSerializeData(NiStream& kStream);
};

// Gets the serialize data buffer and handle, saves the base binary, writes the buffer to the stream, then frees the serialize data.
// @fnv 0x00c87850
void BC87850RefObject::SaveSerializeData(NiStream& kStream)
{
    int iHandle;
    char* pSerializeData = GetSerializeData(&iHandle);
    BaseSaveBinary(kStream);
    unsigned int size = GetSerializeSize();
    BC87850BinaryStreamSave(*WriteStreamBuffer(kStream), pSerializeData, size);
    FreeSerializeData(iHandle);
}

struct NiObjectData
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pc;
    unsigned int m_uiFilterValue;
};

struct FUN_00c879e0_Class
{
    void* m_p0;
    void* m_p4;
    NiObjectData* m_p8;

    void __thiscall bhkAction_CopyCinfo(unsigned int* result);
};

// @fnv 0x00c879e0
// src: XBOX_PDB 0x00c879e0
void __thiscall FUN_00c879e0_Class::bhkAction_CopyCinfo(unsigned int* result)
{
    *result = (this != 0 && m_p8 != 0) ? m_p8->m_uiFilterValue : 0u;
}

struct C87A10HavokObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_ulUserData;
};

class C87A10WorldObject : public bhkRefObject
{
  public:
    void bhkAction_Link(bool bAdd);
};

// @fnv 0x00c87a10
// src: XBOX_PDB 0x00c87a10
void C87A10WorldObject::bhkAction_Link(bool bAdd)
{
    if (this && m_pHavokObject)
        ((C87A10HavokObject*)m_pHavokObject)->m_ulUserData = bAdd ? this : 0;
    UpdateReference(bAdd);
}

extern int DAT_0126817c;

// @fnv 0x00c88370
// src: COMMUNITY 0x00c88370
void* __cdecl WeaponObject_GetRTTI()
{
    return &DAT_0126817c;
}

// Constructor of a two-level Havok wrapper: attach the given Havok object (through its referenced-object base).

extern int g_iC88380RefObjectCount;
extern int g_iC88380WrapperCount;

class C88380Root
{
  public:
    C88380Root();
    virtual ~C88380Root();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};

class C88380Holder : public C88380Root
{
  public:
    C88380Holder() : m_pkHavokObject(0)
    {}
    virtual ~C88380Holder();
    void* m_pkHavokObject;
};

class C88380RefObject : public C88380Holder
{
  public:
    C88380RefObject()
    {
        ++g_iC88380RefObjectCount;
    }
    virtual ~C88380RefObject();
    void SetReferencedObject(void* pkObject);
};

class FUN_00c88380 : public C88380RefObject
{
  public:
    FUN_00c88380(hkReferencedObject* pkObject);
    virtual ~FUN_00c88380();
};

// Constructs a wrapper that stores the given Havok object via SetReferencedObject and increments the wrapper count.
// @fnv 0x00c88380
FUN_00c88380::FUN_00c88380(hkReferencedObject* pkObject)
{
    SetReferencedObject(pkObject ? (char*)pkObject + 4 : 0);
    ++g_iC88380WrapperCount;
}

extern int DAT_0126831c;

// @fnv 0x00c88400
// src: COMMUNITY 0x00c88400
int* __cdecl bhkLimitedHingeConstraint_GetRTTI()
{
    return &DAT_0126831c;
}

struct FNVTransformState
{
    int component00, component04, component08, component0c;
    int component10, component14, component18, component1c;
    int component20, component24, component28, component2c;
    int component30;
};

struct FNVTraversalNode
{
    int unknown00, unknown04, unknown08, unknown0c;
    int unknown10, unknown14;
    FNVTraversalNode* parent;
    int unknown1c, unknown20, unknown24;
    int unknown28, unknown2c, unknown30;
    FNVTransformState state;
};

struct FNVTraversalOutput : FNVTransformState
{
    void FUN_00a86bf0();
    FNVTransformState FUN_0062c250(FNVTransformState* state);
};

// Walks up the parent chain from node to stop, applying each node's state to output and finalizing when stop is reached.
// @fnv 0x00c884c0
void __cdecl AccumulateParentTransforms(FNVTraversalNode* node, FNVTraversalNode* stop, FNVTraversalOutput* output)
{
    if (node == 0)
        return;
    if (node == stop)
    {
        output->FUN_00a86bf0();
        return;
    }
    AccumulateParentTransforms(node->parent, stop, output);
    static_cast<FNVTransformState&>(*output) = output->FUN_0062c250(&node->state);
}

struct ThreadTlsBlock
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
    unsigned int m_2b4;
};
extern __declspec(thread) ThreadTlsBlock g_tls;

struct TlsFlagGuard
{
    unsigned int m_saved;
    TlsFlagGuard()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        g_tls.m_2b4 = m_saved;
    }
};

extern int DAT_012681f0;
class TlsCallTarget
{
  public:
    unsigned int Lookup(int* p);
    void Apply(unsigned int v);
};
void __cdecl CallWithArgs(TlsCallTarget* t, int a, int b);

class FUN_00c886c0_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    TlsCallTarget* m_08;
    void CallTargetWithArgs();
};

// Creates a TLS flag guard, then if m_08 is set calls CallWithArgs(t,1,1), looks up DAT_012681f0 and applies the result if nonzero.
// @fnv 0x00c886c0
void FUN_00c886c0_cls::CallTargetWithArgs()
{
    TlsFlagGuard guard;
    TlsCallTarget* t = m_08;
    if (t != 0)
    {
        CallWithArgs(t, 1, 1);
        unsigned int r = t->Lookup(&DAT_012681f0);
        if (r != 0)
        {
            t->Apply(r);
        }
    }
}

class C88930Base
{
  public:
    virtual ~C88930Base();
};

class FUN_00c88930 : public C88930Base
{
  public:
    void Release();

    virtual ~FUN_00c88930();
};

// @fnv 0x00c88930
FUN_00c88930::~FUN_00c88930()
{
    Release();
}

class SpawnedBase_b7559
{
  public:
    virtual void unk00();
    int m_04;

    SpawnedBase_b7559();
    ~SpawnedBase_b7559();
};

class FUN_00c894d0 : public SpawnedBase_b7559
{
  public:
    FUN_00c894d0(int a, int b, int c, int d, int e);
    virtual void unk00();
    void Init_b7559(int a, int b, int c, int d, int e);
};

// Constructs the object by forwarding all five arguments to Init_b7559.
// @fnv 0x00c894d0
FUN_00c894d0::FUN_00c894d0(int a, int b, int c, int d, int e)
{
    Init_b7559(a, b, c, d, e);
}

namespace fnv_00c89540 {
extern __declspec(thread) unsigned int g_tlsMemoryMode;
int __cdecl bhkUtilFunctions_FindNextCollisionObject(int);
void* __cdecl Object_DispatchCommandFour(unsigned int);
struct FUN_00c894d0
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
    FUN_00c894d0(int, int, int, int, int);
    static void* operator new(unsigned int count)
    {
        return Object_DispatchCommandFour(count);
    }
};
struct ScopedMemoryMode
{
    unsigned int previousMode;
    explicit ScopedMemoryMode(unsigned int mode) : previousMode(g_tlsMemoryMode)
    {
        g_tlsMemoryMode = mode;
    }
    ~ScopedMemoryMode()
    {
        g_tlsMemoryMode = previousMode;
    }
};
// @fnv 0x00c89540
FUN_00c894d0* __cdecl CreateResourceObject(int first, int second, int resourceId, int finalArgument)
{
    ScopedMemoryMode scopedMode(16);
    FUN_00c894d0* result = 0;
    if (resourceId != 0)
    {
        int info = bhkUtilFunctions_FindNextCollisionObject(resourceId);
        if (info != 0)
        {
            result = new FUN_00c894d0(first, second, resourceId, info, finalArgument);
        }
    }
    return result;
}
}  // namespace fnv_00c89540

extern int DAT_01268188;

class PolyBase
{
  public:
    virtual ~PolyBase();
};

class FUN_00c89640_cls : public PolyBase
{
  public:
    virtual ~FUN_00c89640_cls();
    void bhkSerializable_Kill();
};

// @fnv 0x00c89640
FUN_00c89640_cls::~FUN_00c89640_cls()
{
    bhkSerializable_Kill();
    --DAT_01268188;
}

class C896C0Object
{
  public:
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual int GetA();
    virtual int GetB();

    bool IsEqualBase(C896C0Object* pkObject);
    bool IsEqualWithValues(C896C0Object* pkObject);
};

// Compares against pkObject: if IsEqualBase passes, also requires matching GetA and GetB values; returns the combined result.
// @fnv 0x00c896c0
bool C896C0Object::IsEqualWithValues(C896C0Object* pkObject)
{
    bool bEqual = IsEqualBase(pkObject);
    if (bEqual)
    {
        int iA = pkObject->GetA();
        bEqual = GetA() == iA;
        int iB = pkObject->GetB();
        bEqual = bEqual & (GetB() == iB);
    }
    return bEqual;
}

struct S_00c89810_ResultInner
{
    void* unk0;
    void* unk4;
    int unk8;
};

struct S_00c89810_Result
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2(int value)
    {}

    S_00c89810_ResultInner* m_p4;
};

struct S_00c89810_Owner
{
    virtual void d00()
    {}
    virtual void d01()
    {}
    virtual void d02()
    {}
    virtual void d03()
    {}
    virtual void d04()
    {}
    virtual void d05()
    {}
    virtual void d06()
    {}
    virtual void d07()
    {}
    virtual void d08()
    {}
    virtual void d09()
    {}
    virtual void d0a()
    {}
    virtual void d0b()
    {}
    virtual void d0c()
    {}
    virtual void d0d()
    {}
    virtual void d0e()
    {}
    virtual void d0f()
    {}
    virtual void d10()
    {}
    virtual void d11()
    {}
    virtual void d12()
    {}
    virtual void d13()
    {}
    virtual void d14()
    {}
    virtual void d15()
    {}
    virtual void d16()
    {}
    virtual void d17()
    {}
    virtual void d18()
    {}
    virtual void d19()
    {}
    virtual void d1a()
    {}
    virtual void d1b()
    {}
    virtual void d1c()
    {}
    virtual void d1d()
    {}
    virtual void d1e()
    {}
    virtual void d1f()
    {}
    virtual void d20()
    {}
    virtual void d21()
    {}
    virtual void d22()
    {}
    virtual void d23()
    {}
    virtual void d24()
    {}
    virtual void d25()
    {}
    virtual void d26()
    {}
    virtual void d27()
    {}
    virtual void d28()
    {}
    virtual void d29()
    {}

    virtual void mA8()
    {}
    virtual void mA9()
    {}
    virtual void mAA()
    {}
    virtual void* mB4(char* value)
    {
        return 0;
    }

    void SetValueAndReset(int value);
};

// Calls mB4 to obtain a result object, invokes its v2 with value, clears m_p4->unk8, then calls mA8.
// @fnv 0x00c89810
void S_00c89810_Owner::SetValueAndReset(int value)
{
    char local;

    void* returned = this->mB4(&local);
    S_00c89810_Result* result = returned ? (S_00c89810_Result*)((char*)returned - 4) : 0;

    result->v2(value);
    result->m_p4->unk8 = 0;

    this->mA8();
}

struct FUN_00c898e0_Inner
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
    virtual void Slot21(int a);
};

struct FUN_00c898e0_Sub
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00c898e0_Inner* m_0c;
};

struct FUN_00c898e0_Holder
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
    virtual FUN_00c898e0_Sub* GetSub();
    void DispatchToInnerSlot(int arg);
    void BSTextureSet_RegisterStreamables(int a);
};

// Gets the sub-object, forwards arg to its inner object's Slot21 if present, then calls FUN_00a81fe0(arg).
// @fnv 0x00c898e0
void FUN_00c898e0_Holder::DispatchToInnerSlot(int arg)
{
    FUN_00c898e0_Sub* sub = GetSub();
    if (sub != 0)
    {
        FUN_00c898e0_Inner* p = sub->m_0c;
        if (p != 0)
        {
            p->Slot21(arg);
        }
    }
    BSTextureSet_RegisterStreamables(arg);
}

struct RefTarget
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03(int a)
    {}
};

struct FUN_00c89920_cls
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
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual unsigned char* GetRef(unsigned char* flag);
    void InvokeRefTarget(int a);
};

// Gets a reference via GetRef, adjusts it to the RefTarget base, and calls its v03 with a.
// @fnv 0x00c89920
void FUN_00c89920_cls::InvokeRefTarget(int a)
{
    unsigned char flag;
    unsigned char* r = GetRef(&flag);
    RefTarget* p = (r != 0) ? (RefTarget*)(r - 4) : (RefTarget*)0;
    p->v03(a);
}

struct FUN_00c89960_inner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned int a);
};

struct FUN_00c89960_cls
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
    virtual void v41(int flag);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void* v45(unsigned int* p);
    void __thiscall bhkSerializable_GetViewerStrings(unsigned int a);
    void bhkConstraint_GetViewerStrings(unsigned int a1);
};

// Calls FUN_00c878c0 with a1, resolves an inner object via v45, calls its v5 with a1, then v41(1).
// @fnv 0x00c89960
// src: XBOX_PDB 0x00c89960
void FUN_00c89960_cls::bhkConstraint_GetViewerStrings(unsigned int uiValue)
{
    unsigned int v = *(volatile unsigned int*)&uiValue;
    bhkSerializable_GetViewerStrings(v);
    FUN_00c89960_inner* p = (FUN_00c89960_inner*)v45(&uiValue);
    FUN_00c89960_inner* q = p ? (FUN_00c89960_inner*)((char*)p - 4) : 0;
    q->v5(v);
    v41(1);
}

class FUN_00c899b0_target
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_14;
};

class FUN_00c899b0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00c899b0_target* m_08;

    int bhkConstraint_GethkEntityA();
};

// @fnv 0x00c899b0
// src: XBOX_PDB 0x00c899b0
int FUN_00c899b0_cls::bhkConstraint_GethkEntityA()
{
    int result = 0;
    if (m_08 != 0)
    {
        result = m_08->m_14;
    }
    return result;
}

struct FUN_00c899d0_Target
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
    void* unk2c;
};

struct FUN_00c899d0_Class
{
    int unk00;
    int unk04;
    FUN_00c899d0_Target* unk08;

    void ReleaseReference(bool b);
    void bhkConstraint_Link(bool b);
};

// If this and unk08 are non-null, stores this or null into unk08->unk2c depending on b, then calls ReleaseReference(b).
// @fnv 0x00c899d0
// src: XBOX_PDB 0x00c899d0
void FUN_00c899d0_Class::bhkConstraint_Link(bool b)
{
    if (this && unk08)
    {
        unk08->unk2c = b ? this : 0;
    }
    ReleaseReference(b);
}

struct S_00c89a30_Obj;
struct S_00c89a30_Owner;
struct S_00c89a30_Obj
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
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53(S_00c89a30_Obj* o, int f);
    int unk04;
    S_00c89a30_Owner* unk08;
    void bhkWorld_Add_00c6b320(S_00c89a30_Owner* owner);
    bool bhkConstraint_Add(S_00c89a30_Obj* other);
};
// @fnv 0x00c89a30
// src: XBOX_PDB 0x00c89a30
bool S_00c89a30_Obj::bhkConstraint_Add(S_00c89a30_Obj* other)
{
    S_00c89a30_Owner* owner = this ? unk08 : 0;
    bool r = false;
    if (owner)
    {
        if (other)
        {
            int a = v37();
            int b = other->v37();
            if (a != b)
            {
                v40();
                v53(other, 1);
                other->bhkWorld_Add_00c6b320(owner);
                r = true;
            }
        }
        else
        {
            v40();
        }
    }
    return r;
}

namespace fnv_00c89d10 {
struct TlsBlock_t
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
    int m_2b4;
};

extern __declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct FUN_00c89d10_P;
class VObjA
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void Notify(FUN_00c89d10_P* p);
};

struct FUN_00c89d10_R
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
    int m_94;
};

struct FUN_00c89d10_Q
{
    int unk00;
    int unk04;
    FUN_00c89d10_R* m_08;
};

struct FUN_00c89d10_P
{
    int unk00;
    int unk04;
    class VObjA* m_08;
    int unk0C;
    int unk10;
    FUN_00c89d10_Q* m_14;
};

class FUN_00c89d10_cls
{
  public:
    int unk00;
    int unk04;
    FUN_00c89d10_P* m_08;
    void Helper(int a);
    void bhkConstraint_SethkObject(int arg);
};

// @fnv 0x00c89d10
// src: XBOX_PDB 0x00c89d10
void FUN_00c89d10_cls::bhkConstraint_SethkObject(int arg)
{
    TlsGuard_t guard;
    FUN_00c89d10_P* p = this != 0 ? m_08 : 0;
    if (arg != (int)p)
    {
        if (p != 0)
        {
            VObjA* o = p->m_08;
            if (o != 0)
            {
                FUN_00c89d10_R* r = p->m_14->m_08;
                if (r != 0)
                    r->m_94++;
                o->Notify(p);
                if (r != 0)
                    r->m_94--;
            }
        }
        Helper(arg);
    }
}
}  // namespace fnv_00c89d10

extern __declspec(thread) int DAT_tls_field;

struct FUN_009ba5f0_shell
{
    void SetChildObject(int);
    void ReleaseObject(hkReferencedObject*, int);
};
struct TlsGuard
{
    int old;
    TlsGuard() : old(DAT_tls_field)
    {
        DAT_tls_field = 16;
    }
    ~TlsGuard()
    {
        DAT_tls_field = old;
    }
};
// Sets the TLS field to 16 for the call, invokes SetChildObject on object, then calls object->removeReference().
// @fnv 0x00c8a1b0
void FUN_009ba5f0_shell::ReleaseObject(hkReferencedObject* object, int unused)
{
    TlsGuard guard;
    SetChildObject((int)object);
    object->removeReference();
}

struct S_00c8a280_Child
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

inline void S_00c8a280_Save(NiBinaryStream* b, const void* buf, unsigned int bytes)
{
    unsigned int comp = bytes;
    b->BinaryWrite(buf, bytes, &comp, 1);
}

struct S_00c8a280_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    int m_04;
    unsigned int m_08;
    S_00c8a280_Child* m_0c;
    S_00c8a280_Child* m_10;
    void hkConstraintCinfo_SaveBinary(NiStream& kStream);
};
// Writes a version value, the m_0c values of m_0c and m_10 (or 0), calls v4, then writes m_08 to the stream.
// @fnv 0x00c8a280
// src: XBOX_PDB 0x00c8a280
void S_00c8a280_Obj::hkConstraintCinfo_SaveBinary(NiStream& kStream)
{
    unsigned int uiVersion = 2;
    S_00c8a280_Save(WriteStreamBuffer(kStream), &uiVersion, 4);
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>((m_0c ? m_0c->m_0c : 0)));
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>((m_10 ? m_10->m_0c : 0)));
    v4();
    S_00c8a280_Save(WriteStreamBuffer(kStream), &m_08, 4);
}

class C8A4B0Object;

template <class T>
inline void C8A4B0BinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void C8A4B0SaveBinary(NiStream& kStream, const T& value)
{
    C8A4B0BinaryStreamSave(*WriteStreamBuffer(kStream), &value);
}

class C8A4B0Shape
{
  public:
    void SaveSphere(NiStream& kStream);
    void SaveBox(NiStream& kStream);
    void SaveCapsule(NiStream& kStream);

    int unk00;
    int unk04;
    char m_cType;
};

// Writes the shape's type byte to the stream, then dispatches to SaveSphere, SaveBox or SaveCapsule; writes a zero byte if pkShape is null.
// @fnv 0x00c8a4b0
void __stdcall SaveShape(C8A4B0Shape* pkShape, NiStream& kStream)
{
    if (pkShape)
    {
        C8A4B0SaveBinary(kStream, pkShape->m_cType);
        switch (pkShape->m_cType)
        {
        case 1:
            pkShape->SaveSphere(kStream);
            break;
        case 2:
            pkShape->SaveBox(kStream);
            break;
        case 3:
            pkShape->SaveCapsule(kStream);
            break;
        }
    }
    else
    {
        char cNone = 0;
        C8A4B0SaveBinary(kStream, cNone);
    }
}

struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;

// @fnv 0x00c8a790
// src: COMMUNITY 0x00c8a790
GlobalObject* __cdecl bhkBinaryAction_GetRTTI()
{
    return &g_global;
}

struct FUN_00c8a7a0_cls;

struct Callee_a645
{
    void Run();
};

struct FUN_00c8a7a0_cls
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
    virtual void* v2D(unsigned int* out);
    void Init(unsigned int a);
    void bhkBinaryAction_LoadBinary(unsigned int a1);
};

// Calls Run twice on the object, calls Init, then obtains a pointer via v2D and zeroes its second and third words.
// @fnv 0x00c8a7a0
// src: XBOX_PDB 0x00c8a7a0
void FUN_00c8a7a0_cls::bhkBinaryAction_LoadBinary(volatile unsigned int uiObj)
{
    unsigned int obj = uiObj;
    ((Callee_a645*)obj)->Run();
    ((Callee_a645*)obj)->Run();
    Init(obj);
    unsigned int* r = (unsigned int*)v2D((unsigned int*)&uiObj);
    r[1] = 0;
    r[2] = 0;
}

class FUN_00c8a800_cls : public ScriptOwnerBase_blk_00c80000_o2
{
  public:
    int unk00;
    int unk04;
    ScriptTarget_blk_00c80000_o2* m_pFlagTarget;
    void WriteScriptTargetInfo(ScriptOutBlock_blk_00c80000_o2* pOut);
};

// Calls the base writer, then stores the target's m_18 and m_1c into pOut->unk04 and pOut->unk08, or 0 when this or the target is null.
// @fnv 0x00c8a800
void FUN_00c8a800_cls::WriteScriptTargetInfo(ScriptOutBlock_blk_00c80000_o2* pOut)
{
    this->bhkAction_CopyCinfo(pOut);
    pOut->unk04 = (this != 0 && m_pFlagTarget != 0) ? m_pFlagTarget->m_18 : 0;
    pOut->unk08 = (this != 0 && m_pFlagTarget != 0) ? m_pFlagTarget->m_1c : 0;
}

struct Ca980Block
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_18;
    unsigned int m_1C;
};

class FUN_00c8a980_cls
{
  public:
    int unk00;
    int unk04;
    Ca980Block* m_08;
    bool BSAnimNotes_IsEqual(FUN_00c8a980_cls* p);
    bool bhkBinaryAction_IsEqual(FUN_00c8a980_cls* p);
};

// Calls FUN_00ba87d0 and, if it succeeds, also compares m_18 and m_1C of both objects' m_08 blocks, returning whether all match.
// @fnv 0x00c8a980
// src: XBOX_PDB 0x00c8a980
bool FUN_00c8a980_cls::bhkBinaryAction_IsEqual(FUN_00c8a980_cls* apOther)
{
    bool result = this->BSAnimNotes_IsEqual(apOther);
    if (result)
    {
        unsigned int a = (this != 0 && this->m_08 != 0) ? this->m_08->m_18 : 0;
        unsigned int b = (apOther != 0 && apOther->m_08 != 0) ? apOther->m_08->m_18 : 0;
        result = (a == b);
        unsigned int c = (this != 0 && this->m_08 != 0) ? this->m_08->m_1C : 0;
        unsigned int d = (apOther != 0 && apOther->m_08 != 0) ? apOther->m_08->m_1C : 0;
        result = result & (c == d);
    }
    return result;
}

extern int DAT_012681a0;

class FUN_00c8adf0_base
{
  public:
    virtual ~FUN_00c8adf0_base();
};

class FUN_00c8adf0_cls : public FUN_00c8adf0_base
{
  public:
    virtual ~FUN_00c8adf0_cls();
    void bhkSerializable_Kill();
};

// @fnv 0x00c8adf0
FUN_00c8adf0_cls::~FUN_00c8adf0_cls()
{
    bhkSerializable_Kill();
    --DAT_012681a0;
}

struct FUN_00c8b000_Node
{
    int m_00;
    void* m_04;
    void* m_08;
};

struct FUN_00c8b000_Item;

struct FUN_00c8b000_Obj
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
    virtual FUN_00c8b000_Node* v18(int a);
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
    virtual bool v52(int a);
};

struct FUN_00c8b000_Item
{
    int m_00;
    int m_04;
    FUN_00c8b000_Obj* m_08;
};

struct FUN_00c8b000_List
{
    int m_00;
    FUN_00c8b000_Item** m_04;
    int m_08;
};

struct FUN_00c8b000_cls
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
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual FUN_00c8b000_List* v45(bool* out);
    void bhkShape_CopyMembers(int a, int b);
    void UpdateListEntries(int a1, int a2);
};

// @fnv 0x00c8b000
void FUN_00c8b000_cls::UpdateListEntries(int a1, int a2)
{
    bool flag;
    FUN_00c8b000_List* list = v45(&flag);
    for (int i = 0; i < list->m_08; ++i)
    {
        FUN_00c8b000_Item* item = list->m_04[i];
        if (item != 0)
        {
            FUN_00c8b000_Obj* obj = item->m_08;
            if (obj != 0 && !obj->v52(a2))
            {
                FUN_00c8b000_Node* node = obj->v18(a2);
                FUN_00c8b000_Item* result = node != 0 ? (FUN_00c8b000_Item*)node->m_08 : 0;
                list->m_04[i] = result;
            }
        }
    }
    bhkShape_CopyMembers(a1, a2);
}

struct FileContext
{
    void NiStream_ReadMultipleLinkIDs();
};
struct H_00c8b1d0
{
    virtual void reservedVirtual0();
    virtual void reservedVirtual1();
    virtual void reservedVirtual2();
    virtual void reservedVirtual3();
    virtual void reservedVirtual4();
    virtual void reservedVirtual5();
    virtual void reservedVirtual6();
    virtual void reservedVirtual7();
    virtual void reservedVirtual8();
    virtual void reservedVirtual9();
    virtual void reservedVirtual10();
    virtual void reservedVirtual11();
    virtual void reservedVirtual12();
    virtual void reservedVirtual13();
    virtual void reservedVirtual14();
    virtual void reservedVirtual15();
    virtual void reservedVirtual16();
    virtual void reservedVirtual17();
    virtual void reservedVirtual18();
    virtual void reservedVirtual19();
    virtual void reservedVirtual20();
    virtual void reservedVirtual21();
    virtual void reservedVirtual22();
    virtual void reservedVirtual23();
    virtual void reservedVirtual24();
    virtual void reservedVirtual25();
    virtual void reservedVirtual26();
    virtual void reservedVirtual27();
    virtual void reservedVirtual28();
    virtual void reservedVirtual29();
    virtual void reservedVirtual30();
    virtual void reservedVirtual31();
    virtual void reservedVirtual32();
    virtual void reservedVirtual33();
    virtual void reservedVirtual34();
    virtual void reservedVirtual35();
    virtual void reservedVirtual36();
    virtual void reservedVirtual37();
    virtual void reservedVirtual38();
    virtual void reservedVirtual39();
    virtual void reservedVirtual40();
    virtual void reservedVirtual41();
    virtual void* GetSharedData();
    virtual void reservedVirtual43();
    virtual void reservedVirtual44();
    virtual char* GetDataPosition(FileContext* volatile* object);
    void bhkShape_LoadBinary(FileContext* object);
    void ProcessFileContext(FileContext* object);
};
void __cdecl bhkStream_SwapHKArray(char* data, void* shared, char* component);
void __cdecl LoadIntArray(FileContext* object, char* component);
// @fnv 0x00c8b1d0
void H_00c8b1d0::ProcessFileContext(FileContext* volatile object)
{
    FileContext* stableObject = object;
    stableObject->NiStream_ReadMultipleLinkIDs();
    bhkShape_LoadBinary(stableObject);
    char* data = GetDataPosition(&object);
    if (reinterpret_cast<unsigned char*>(stableObject)[0x1E5] != 1)
    {
        void* shared = GetSharedData();
        bhkStream_SwapHKArray(data, shared, data + 0x10);
        bhkStream_SwapHKArray(data, shared, data + 4);
    }
    LoadIntArray(stableObject, data + 0x10);
}

// HandleAllEntries — walks the entry array of the list object held at this+0x08
// and forwards the parameter to each entry's handler-object virtual
// (vtable slot 21), then calls the member routine FUN_00aa0ad0 on this.
//
// Count source: vtable slot 1 of the sub-object embedded at list+0x10, with
// the owner chain (this, list) null-checked; the entry walk re-checks the
// chain on every iteration and skips null slots / null handler objects.
//
// Target: __thiscall (this in ecx), callee pops 4 bytes (1 stack parameter),
// size 109, /MT /O2 /GS /EHsc /Gy.

// Sub-object embedded at list+0x10; its vtable slot 1 returns the entry
// count as an unsigned value.
struct SubObj00
{
    virtual void v0();
    virtual unsigned int GetCount();  // vtable +0x04
};

// Handler object; vtable slot 21 (+0x54) is invoked with the parameter.
struct Handler00;

// Entry object referenced by a slot; field +0x08 points at the handler
// object that receives the per-entry virtual call.
struct Entry00;

// One 16-byte slot of the entry array at list+0x18; only the first dword
// (a pointer to the entry object) is read here.
struct Slot00
{
    Entry00* p0;  // +0x00
    int unk04;
    int unk08;
    int unk0C;
};

struct Entry00
{
    int unk00;
    int unk04;
    Handler00* unk08;  // +0x08
};

struct Handler00
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
    virtual void Handle(void* param);  // vtable +0x54
};

// The list object held at this+0x08: embedded polymorphic sub-object at
// +0x10, spare dword at +0x14, entry array base at +0x18.
struct List00
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SubObj00 sub;  // +0x10
    int unk14;
    Slot00* arr;  // +0x18
};

// Owning class of the target member.
struct Owner00
{
    int unk00;
    int unk04;
    List00* unk08;  // +0x08

    void __thiscall BSPackedAdditionalGeometryData_RegisterStreamables(void* param);  // defined elsewhere
    void HandleAllEntries(void* param);
};

// Calls Handle(param) on each entry's handler in the list, then calls FUN_00aa0ad0(param).
// @fnv 0x00c8b240
void Owner00::HandleAllEntries(void* param)
{
    unsigned int count;
    if (this != 0)
    {
        List00* list = this->unk08;
        if (list != 0)
            count = list->sub.GetCount();
        else
            count = 0;
    }
    else
        count = 0;

    for (unsigned int i = 0; i < count; i++)
    {
        if (this != 0)
        {
            List00* list = this->unk08;
            if (list != 0)
            {
                Entry00* entry = list->arr[i].p0;
                if (entry != 0)
                {
                    Handler00* h = entry->unk08;
                    if (h != 0)
                        h->Handle(param);
                }
            }
        }
    }

    this->BSPackedAdditionalGeometryData_RegisterStreamables(param);
}

struct DecCountProvider
{
    virtual void Slot00();
    virtual int GetCount();
};

struct DecTarget
{
    int unk00;
    int unk04;
};

struct DecItem
{
    int unk00;
    int unk04;
    DecTarget* m_08;
};

struct DecEntry
{
    DecItem* m_00;
    int unk04;
    int unk08;
    int unk0C;
};

struct DecOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DecCountProvider m_10;
    int unk14;
    DecEntry* m_18;
};

typedef void(__stdcall* DecCallback)(void* arg);
extern "C" DecCallback DAT_00fdf1c0;

struct FUN_00c8b2b0_cls
{
    int unk00;
    int unk04;
    DecOwner* m_08;
    void InvokeCallbacksOnEntries();
};

// Calls DAT_00fdf1c0 for each entry's item target in reverse order, stopping early if the owner or count is null/zero.
// @fnv 0x00c8b2b0
void FUN_00c8b2b0_cls::InvokeCallbacksOnEntries()
{
    if (this == 0)
        return;
    DecOwner* p = m_08;
    if (p == 0)
        return;
    int n = p->m_10.GetCount();
    if (n == 0)
        return;
    DecCallback fn = DAT_00fdf1c0;
    do
    {
        DecOwner* o = m_08;
        --n;
        if (o != 0)
        {
            DecEntry* e = &o->m_18[n];
            DecItem* it = e->m_00;
            if (it != 0 && it->m_08 != 0)
                fn((void*)&it->m_08->unk04);
        }
    } while (n != 0);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(thread) int g_memoryContext;

struct MemoryContextScope
{
    int previousContext;
    MemoryContextScope()
    {
        previousContext = g_memoryContext;
        g_memoryContext = 16;
    }
    ~MemoryContextScope()
    {
        g_memoryContext = previousContext;
    }
};

struct RefCountedEntry
{
    virtual void UnusedVirtual();
    virtual void Release();
    volatile long referenceCount;
};

struct Record
{
    int firstField;
    int secondField;
    RefCountedEntry* referencedObject;
};

struct CollectionSlot
{
    Record* record;
    int key;
    int status;
    int extra;
};

struct IndexedRecords
{
    virtual void FirstVirtual();
    virtual unsigned int GetSize();
    int capacity;
    CollectionSlot* entries;
};

struct RecordCollection
{
    int header0;
    int header4;
    int header8;
    int headerC;
    IndexedRecords items;
};

struct CollectionHolderLayout
{
    int state;
    int reserved;
    RecordCollection* collection;
};

// Iterates the collection's entries backwards and releases each record's referenced object when its reference count drops to zero.
// @fnv 0x00c8b310
void H_00c8c810::ReleaseReferencedObjects()
{
    MemoryContextScope m_uiMemoryContext;
    CollectionHolderLayout* holder = reinterpret_cast<CollectionHolderLayout*>(this);

    if (this != 0)
    {
        RecordCollection* records = holder->collection;
        if (records != 0)
        {
            unsigned int count = records->items.GetSize();
            if (count != 0)
            {
                unsigned int offset = count << 4;
                do
                {
                    --count;
                    offset -= 16;
                    if (holder->collection != 0)
                    {
                        Record* record = *reinterpret_cast<Record**>(
                            reinterpret_cast<unsigned char*>(holder->collection->items.entries) + offset);
                        if (record != 0)
                        {
                            RefCountedEntry* reference = record->referencedObject;
                            if (reference != 0 && InterlockedDecrement(&reference->referenceCount) == 0)
                            {
                                reference->Release();
                            }
                        }
                    }
                } while (count != 0);
            }
        }
    }
}

extern __declspec(thread) int tls_iMemContext;

struct MemContextScope
{
    int iOld;
    MemContextScope(int iNew)
    {
        iOld = tls_iMemContext;
        tls_iMemContext = iNew;
    }
    ~MemContextScope()
    {
        tls_iMemContext = iOld;
    }
};

int __cdecl sprintf_s(char* buf, unsigned int size, const char* fmt, ...);
char* __cdecl CreateDebugString(const char* pcName);
char* __cdecl CreateDebugString(const char* pcName, int iValue);

struct ViewerStrings
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    unsigned int Add(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};


extern NiRTTI bhkListShape_ms_RTTI;

struct bhkShapeCollectionBase
{
    void GetViewerStrings_base(ViewerStrings* pkStrings);
};

// The shared bhkListShape has the layout; its viewer override is not declared yet.
struct ListShapeViewer : bhkListShape
{
    void bhkListShape_GetViewerStrings(ViewerStrings* pkStrings);
};

static inline hkpListShape* GetHkListShape(ListShapeViewer* p)
{
    return p ? reinterpret_cast<hkpListShape*>(p->m_pHavokObject) : 0;
}

// @fnv 0x00c8bcd0
// src: XBOX_PDB 0x00c8bcd0
void ListShapeViewer::bhkListShape_GetViewerStrings(ViewerStrings* pkStrings)
{
    MemContextScope kScope(0x10);
    reinterpret_cast<bhkShapeCollectionBase*>(this)->GetViewerStrings_base(pkStrings);
    pkStrings->Add(CreateDebugString(bhkListShape_ms_RTTI.m_pcName));
    hkpListShape* pHk = GetHkListShape(this);
    int iShapeCount = pHk ? static_cast<hkpShapeContainer*>(pHk)->GetNumChildShapes() : 0;
    pkStrings->Add(CreateDebugString("Shapes", iShapeCount));
    for (int i = 0; i < iShapeCount; i++)
    {
        char acBuf[32];
        sprintf_s(acBuf, 32, "Shape%d", i);
    }
}

namespace fnv_00c8be30 {
struct TlsBlock_t
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
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct Owned_t
{
    void Destroy();
};

struct PoolFree_t
{
    void Free(void* p);
};

extern PoolFree_t DAT_011f6238;

struct FUN_00c8be30_cls
{
    int unk00;
    int unk04;
    int unk08;
    Owned_t* m_0c;

    void ReleaseOwned(bool flag);
};

// If flag is set, destroys and frees the owned object at m_0c, then clears the pointer.
// @fnv 0x00c8be30
void FUN_00c8be30_cls::ReleaseOwned(bool abRelease)
{
    TlsGuard_t guard;
    if (abRelease)
    {
        Owned_t* p = m_0c;
        if (p)
        {
            p->Destroy();
            DAT_011f6238.Free(p);
        }
        m_0c = 0;
    }
}
}  // namespace fnv_00c8be30

class C8CCC0Base
{
  public:
    bool IsEqual(const C8CCC0Base& kOther) const;

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class C8CCC0Derived : public C8CCC0Base
{
  public:
    bool bhkRigidBody_IsEqual(const C8CCC0Derived& kOther) const;

    int m_iValue;
};

// Calls the base IsEqual and, if it succeeds, also compares m_iValue with the other object's m_iValue.
// @fnv 0x00c8ccc0
// src: XBOX_PDB 0x00c8ccc0
bool C8CCC0Derived::bhkRigidBody_IsEqual(const C8CCC0Derived& kOther) const
{
    bool bEqual = IsEqual(kOther);
    if (bEqual)
        bEqual = m_iValue == kOther.m_iValue;
    return bEqual;
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short);

struct SwapMatrix_c8ce70
{
    unsigned long m00;
    unsigned long m04;
    unsigned long m08;
    unsigned long m0c;
    unsigned long m10;
    unsigned long m14;
    unsigned long m18;
    unsigned long m1c;
    unsigned long m20;
    unsigned long m24;
    unsigned long m28;
    unsigned long m2c;
};

inline void Swap32_c8ce70(void* p)
{
    unsigned long* q = (unsigned long*)p;
    *q = _byteswap_ulong(*q);
}
inline void Swap16_c8ce70(void* p)
{
    unsigned short* q = (unsigned short*)p;
    *q = _byteswap_ushort(*q);
}

void __cdecl SwapEndianBlocks(SwapMatrix_c8ce70* m);

struct SwapBlock_c8ce70
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
    unsigned short unk2c;
    short unk2e;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
    SwapMatrix_c8ce70 unk70;
    float unka0;
    float unka4;
    float unka8;
    float unkac;
    float unkb0;
    float unkb4;
    float unkb8;
    float unkbc;
    float unkc0;
    float unkc4;
    float unkc8;
    float unkcc;
    float unkd0;

    void SwapEndian();
};

// @fnv 0x00c8ce70
void SwapBlock_c8ce70::SwapEndian()
{
    Swap32_c8ce70(&unk30);
    Swap32_c8ce70(&unk34);
    Swap32_c8ce70(&unk38);
    Swap32_c8ce70(&unk3c);
    Swap32_c8ce70(&unk40);
    Swap32_c8ce70(&unk44);
    Swap32_c8ce70(&unk48);
    Swap32_c8ce70(&unk4c);
    Swap32_c8ce70(&unk50);
    Swap32_c8ce70(&unk54);
    Swap32_c8ce70(&unk58);
    Swap32_c8ce70(&unk5c);
    Swap32_c8ce70(&unk60);
    Swap32_c8ce70(&unk64);
    Swap32_c8ce70(&unk68);
    Swap32_c8ce70(&unk6c);
    SwapEndianBlocks(&unk70);
    Swap32_c8ce70(&unka0);
    Swap32_c8ce70(&unka4);
    Swap32_c8ce70(&unka8);
    Swap32_c8ce70(&unkac);
    Swap16_c8ce70(&unk2e);
    Swap32_c8ce70(&unkb0);
    Swap32_c8ce70(&unkb4);
    Swap32_c8ce70(&unkb8);
    Swap32_c8ce70(&unkbc);
    Swap32_c8ce70(&unkc0);
    Swap32_c8ce70(&unkc4);
    Swap32_c8ce70(&unkc8);
    Swap32_c8ce70(&unkcc);
    Swap32_c8ce70(&unkd0);
}

class FUN_00c8d090_item
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(int a);
};

struct FUN_00c8d090_node
{
    FUN_00c8d090_item* m_pInventoryEntryData;
    FUN_00c8d090_node* m_pNext;
};

struct FUN_00c8d090_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_00c8d090_node m_14;

    bool Check(int a);
    bool CheckAndNotify(int a);
};

// Calls Check(a); if it succeeds, walks the m_14 linked list and calls v15(a) on each item, returning the Check result.
// @fnv 0x00c8d090
bool FUN_00c8d090_cls::CheckAndNotify(int a)
{
    bool ok = Check(a);
    if (ok)
    {
        FUN_00c8d090_node* node = &m_14;
        if (node != 0)
        {
            do
            {
                FUN_00c8d090_item* item = node->m_pInventoryEntryData;
                if (item == 0)
                {
                    break;
                }
                item->v15(a);
                node = node->m_pNext;
            } while (node != 0);
        }
    }
    return ok;
}

struct FUN_00c8d0d0_Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    int GetNodeCount();
};

// @fnv 0x00c8d0d0
int FUN_00c8d0d0_Object::GetNodeCount()
{
    int count = 0;
    int* node = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x14);

    while (node && *node)
    {
        ++count;
        node = *reinterpret_cast<int**>(reinterpret_cast<char*>(node) + 4);
    }

    return count;
}


extern int DAT_012681d4;

// @fnv 0x00c90820
// src: COMMUNITY 0x00c90820
int __cdecl hkReferencedObject_getLockCriticalSection(void)
{
    return DAT_012681d4 + 0x18;
}

struct C90830Stream
{
    int m_iHandle;
    unsigned short m_usFlags;

    C90830Stream() : m_iHandle(-15), m_usFlags(0x8000)
    {}
    void ResetThreadCheck() throw();
};

struct C90830CriticalSection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    C90830CriticalSection(int iSpinCount) throw();
};

class FUN_00c90830 : public hkReferencedObject
{
  public:
    int m_iFadeIndex;
    int m_iArrayLength;
    C90830Stream m_kVertexStream;
    C90830CriticalSection m_kLock;

    FUN_00c90830();
    virtual ~FUN_00c90830();
};

// @fnv 0x00c90830
FUN_00c90830::FUN_00c90830() : m_kLock(4000)
{
    m_iFadeIndex = 1;
    m_kVertexStream.ResetThreadCheck();
    m_iArrayLength = 0;
}

extern const double DAT_01012060;

struct FUN_00c90e00
{
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    float m_24;

    FUN_00c90e00(int flag);
};

// If flag is set and m_24 equals DAT_01012060, sets m_24 to 1.0f.
// @fnv 0x00c90e00
FUN_00c90e00::FUN_00c90e00(int flag)
{
    if (flag)
    {
        if ((double)m_24 == DAT_01012060)
            m_24 = 1.0f;
    }
}

namespace fnv_00c99f80 {
struct AllocIface
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct SpawnedObject18
{
    int unk00;
    unsigned short m_w04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* Tail();
};

// @fnv 0x00c99f80
void* __cdecl AllocateSpawnedObject()
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    SpawnedObject18* obj = (SpawnedObject18*)((AllocIface*)holder->m_heap)->Alloc(0x18);
    obj->m_w04 = 0x18;
    return obj->Tail();
}
}  // namespace fnv_00c99f80

extern int DAT_012681e8;

// @fnv 0x00c99fe0
// src: COMMUNITY 0x00c99fe0
void* __cdecl bhkWorldM_GetRTTI()
{
    return &DAT_012681e8;
}

struct FUN_00653290_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00653290_cls* __thiscall FUN_00653290(int* arg);
};

struct FUN_00c9a430_arg
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00653290_cls* unk0C;
};

struct FUN_00c9a430_cls
{
    int unk00;
    int unk04;
    FUN_00653290_cls* __thiscall GetMatchingObject(FUN_00c9a430_arg* arg);
};

extern int DAT_012681c0;

// @fnv 0x00c9a430
FUN_00653290_cls* __thiscall FUN_00c9a430_cls::GetMatchingObject(FUN_00c9a430_arg* arg)
{
    if (arg == 0)
        return 0;

    FUN_00653290_cls* object = arg->unk0C;
    if (object == 0)
        return 0;

    FUN_00653290_cls* result = object->FUN_00653290(&DAT_012681c0);
    if (result != 0 && (this->unk04 & result->unk10) != 0)
        return result;

    return 0;
}

struct FUN_00c9a660_cls
{
    float m_00;
    float m_04;
    float m_08;

    bool NotEqual(const FUN_00c9a660_cls* other) const;
};

// Returns true when any of the three floats differs from the corresponding float in other.
// @fnv 0x00c9a660
bool FUN_00c9a660_cls::NotEqual(const FUN_00c9a660_cls* other) const
{
    int r = (m_00 == other->m_00 && m_04 == other->m_04 && m_08 == other->m_08) ? 1 : 0;
    return !(char)r;
}

struct FUN_00c9a840_cls
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
    NiPoint3* m_pVerts;
    int unk40;
    int unk44;
    unsigned int m_uiItemCount;

    bool NiTimeController_IsEqual(FUN_00c9a840_cls* other);
    bool bhkBlendController_IsEqual(FUN_00c9a840_cls* other);
};
// @fnv 0x00c9a840
// src: XBOX_PDB 0x00c9a840
bool FUN_00c9a840_cls::bhkBlendController_IsEqual(FUN_00c9a840_cls* other)
{
    bool eq = NiTimeController_IsEqual(other);
    if (eq)
    {
        eq = (m_uiItemCount == other->m_uiItemCount);
        unsigned int i = 0;
        while (eq && i < m_uiItemCount)
        {
            unsigned int off = i * 12;
            NiPoint3* pb = (NiPoint3*)((char*)other->m_pVerts + off);
            NiPoint3* pa = (NiPoint3*)((char*)m_pVerts + off);
            eq = (pa->x == pb->x) && (pa->y == pb->y) && (pa->z == pb->z);
            i++;
        }
    }
    return eq;
}

extern double DAT_010231b0;
extern double DAT_010241b0;

struct FUN_00c9ab10_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float unk14;
    float unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    float* unk3c;
    int unk40;
    int unk44;
    int unk48;

    void bhkBlendController_FixStartAndEndTimes();
};

// @fnv 0x00c9ab10
// src: COMMUNITY 0x00c9ab10
void FUN_00c9ab10_class::bhkBlendController_FixStartAndEndTimes()
{
    float value = 0.0f;
    float result = 0.0f;

    int count = this->unk48;
    if (count != 0)
    {
        float* values = this->unk3c;
        float first = values[0];

        value = this->unk14;
        result = this->unk18;

        if (value > first || value == DAT_010231b0)
        {
            value = first;
        }

        float last = values[count * 3 - 3];

        if (result > last || result == DAT_010241b0)
        {
            result = last;
        }
    }

    this->unk14 = value;
    this->unk18 = result;
}

void* NiMalloc(unsigned int size);
void NiFree(void* p);

struct Elem_c9ac00
{
    float a;
    float b;
    float c;
    Elem_c9ac00()
    {}
    Elem_c9ac00(int i)
    {
        float f = (float)(i / 100.0);
        a = -1.0f;
        b = f;
        c = f;
    }
    Elem_c9ac00& operator=(const Elem_c9ac00& o)
    {
        a = o.a;
        b = o.b;
        c = o.c;
        return *this;
    }
    bool operator!=(const Elem_c9ac00& o) const
    {
        return a != o.a || b != o.b || c != o.c;
    }
};

struct LargeArray_c9ac00
{
    void** m_ppVirtualMethodTable;
    Elem_c9ac00* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void Resize(unsigned int uiMaxSize);
};

// @fnv 0x00c9ac00
void LargeArray_c9ac00::Resize(unsigned int uiNewMaxSize)
{
    if (uiNewMaxSize == m_uiMaxSize)
        return;

    unsigned int i;
    if (uiNewMaxSize < m_uiSize)
    {
        for (i = uiNewMaxSize; i < m_uiSize; i++)
        {
            if (m_pBase[i] != Elem_c9ac00(0))
            {
                m_pBase[i] = Elem_c9ac00(0);
                m_uiESize--;
            }
        }
        m_uiSize = uiNewMaxSize;
    }

    Elem_c9ac00* pOldElements = m_pBase;
    m_uiMaxSize = uiNewMaxSize;
    if (uiNewMaxSize > 0)
    {
        m_pBase = (Elem_c9ac00*)NiMalloc(sizeof(Elem_c9ac00) * m_uiMaxSize);
        for (i = 0; i < m_uiSize; i++)
            m_pBase[i] = pOldElements[i];
        for (i = m_uiSize; i < m_uiMaxSize; i++)
            m_pBase[i] = Elem_c9ac00(0);
    }
    else
    {
        m_pBase = 0;
    }
    NiFree(pOldElements);
}

void _NiFree_00aa10f0(int value);



struct Base_c9ad60
{
    virtual void unk00();
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

    ~Base_c9ad60();
};

class FUN_00c9ad60_cls : public Base_c9ad60
{
  public:
    NiTLargeArray<BLENDKEY, NiTMallocInterface<BLENDKEY> > m_38;

    virtual ~FUN_00c9ad60_cls();
};

template <class T, class TAlloc> NiTLargeArray<T, TAlloc>::~NiTLargeArray()
{
    _NiFree_00aa10f0(reinterpret_cast<int>(m_pBase));
}

// The m_38 large-array destructor releases its element buffer through FUN_00aa10f0.
// @fnv 0x00c9ad60
FUN_00c9ad60_cls::~FUN_00c9ad60_cls()
{}

// FUN_00c9add0 : a one-line function - getter
extern int g_target_00c9add0;
// @fnv 0x00c9add0
// src: COMMUNITY 0x00c9add0
void* bhkBlendController_GetRTTI()
{
    return &g_target_00c9add0;
}

template <class T> inline void WriteBinaryArray(NiBinaryStream& kStream, const T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(pkValue, uiNumEls * sizeof(T), &uiSize, 1);
}
inline void SwapFloat(float& f)
{
    unsigned int u = *(unsigned int*)&f;
    *(unsigned int*)&f = _byteswap_ulong(u);
}
inline void SwapPoint(NiPoint3& p)
{
    SwapFloat(p.y);
    SwapFloat(p.x);
    SwapFloat(p.z);
}
struct S_00c9af40_Base
{
    void __thiscall FUN_00a6d730(NiStream& kStream);
};
struct S_00c9af40_Obj : S_00c9af40_Base
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
    NiPoint3* unk3c;
    int unk40;
    int unk44;
    unsigned int unk48;
    void WriteToStream(NiStream& kStream);
};
// @fnv 0x00c9af40
// this function copies its points member by member, as a copy constructor with an initialiser list does
struct S_00c9af40_PointCopy
{
    float x, y, z;
    S_00c9af40_PointCopy(const NiPoint3& p) : x(p.x), y(p.y), z(p.z) {}
};

void S_00c9af40_Obj::WriteToStream(NiStream& kStream)
{
    S_00c9af40_Base::FUN_00a6d730(kStream);
    unsigned int uiPointCount = unk48;
    WriteBinaryArray(*WriteStreamBuffer(kStream), &uiPointCount, 1);
    for (unsigned int i = 0; i < uiPointCount; i++)
    {
        S_00c9af40_PointCopy kPointCopy(unk3c[i]);
        NiPoint3& kPoint = *reinterpret_cast<NiPoint3*>(&kPointCopy);
        if (*((unsigned char*)&kStream + 0x1e4) != 1)
            SwapPoint(kPoint);
        WriteBinaryArray(*WriteStreamBuffer(kStream), &kPoint, 1);
    }
}

namespace fnv_00c9b1a0 {
struct TlsBlock_t
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
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct ItemArraySub_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int unk10;
    unsigned int m_14;
    void Resize(unsigned int a);
    void SetElement(unsigned int a, unsigned int b);
};

struct FUN_00c9b1a0_cls
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
    int m_34;
    ItemArraySub_cls m_38;
    void bhkBlendController_FixStartAndEndTimes();
    void bhkBlendController_AddKey(unsigned int arg);
};

// @fnv 0x00c9b1a0
// src: COMMUNITY 0x00c9b1a0
void FUN_00c9b1a0_cls::bhkBlendController_AddKey(unsigned int arg)
{
    TlsGuard_t guard;
    ItemArraySub_cls* p = &m_38;
    unsigned int count = p->m_0C;
    if (count >= p->m_08)
    {
        p->Resize(p->m_14 + count);
    }
    p->SetElement(count, arg);
    m_34 = 0;
    bhkBlendController_FixStartAndEndTimes();
}
}  // namespace fnv_00c9b1a0

extern __declspec(thread) int g_iC9B970MemContext;

class C9B970MemContext
{
  public:
    C9B970MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iC9B970MemContext;
        g_iC9B970MemContext = aiMemoryContext;
    }
    ~C9B970MemContext()
    {
        g_iC9B970MemContext = m_iPrevious;
    }

    int m_iPrevious;
};

struct C9B970Entry
{
    int unk00;
    int unk04;
    int unk08;
};

class C9B970Array
{
  public:
    void SetSize(unsigned int uiSize);

    int unk00;
    C9B970Entry* m_pkEntryArray;
    int unk08;
    int unk0C;
    unsigned int m_uiSize;
};

class C9B970Base
{
  public:
    void CopyMemberData(C9B970Base* pkDest, void* pvCloning);

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
};

class C9B970Object : public C9B970Base
{
  public:
    void AddEntry(C9B970Entry* pkEntry);
    void CloneTo(C9B970Object* pkDest, void* pvCloning);

    int m_iValue;
    C9B970Array m_kEntries;
};

// @fnv 0x00c9b970
void C9B970Object::CloneTo(C9B970Object* pkDest, void* pvCloning)
{
    C9B970MemContext kContext(0x10);
    CopyMemberData(pkDest, pvCloning);
    pkDest->m_iValue = m_iValue;
    pkDest->m_kEntries.SetSize(m_kEntries.m_uiSize);
    for (unsigned int i = 0; i < m_kEntries.m_uiSize; i++)
        pkDest->AddEntry(&m_kEntries.m_pkEntryArray[i]);
}

namespace fnv_00c9ba40 {
extern __declspec(thread) int memoryCategory;
struct ReadScope
{
    int previous;
    ReadScope() : previous(memoryCategory)
    {
        memoryCategory = 16;
    }
    ~ReadScope()
    {
        memoryCategory = previous;
    }
};

struct SerializedPoint
{
    float first, second, third;
    SerializedPoint(float value = -1.0f, float percentage = 0.0f)
        : first(value), second(percentage / 100.0), third(percentage / 100.0)
    {}
};
struct PointCollection
{
    void Resize(unsigned int);
};
struct PointLoader
{
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
    PointCollection points;
    void FUN_00a6d5e0(NiStream*);
    void bhkBlendController_AddKey(const SerializedPoint&);
    void bhkBlendController_LoadBinary(NiStream*);
};
// @fnv 0x00c9ba40
// src: XBOX_PDB 0x00c9ba40
void PointLoader::bhkBlendController_LoadBinary(NiStream* stream)
{
    ReadScope scope;
    FUN_00a6d5e0(stream);
    unsigned int count;
    ReadStream(*stream)->ReadUInt(count);
    points.Resize(count);
    for (unsigned int i = 0; i < count; ++i)
    {
        SerializedPoint point;
        ReadStream(*stream)->BinaryRead(&point, 12, (unsigned int*)0, 0);
        if (*((unsigned char*)stream + 0x1e5) != 1)
        {
            *reinterpret_cast<unsigned long*>(&point.second) =
                _byteswap_ulong(*reinterpret_cast<unsigned long*>(&point.second));
            *reinterpret_cast<unsigned long*>(&point.first) =
                _byteswap_ulong(*reinterpret_cast<unsigned long*>(&point.first));
            *reinterpret_cast<unsigned long*>(&point.third) =
                _byteswap_ulong(*reinterpret_cast<unsigned long*>(&point.third));
        }
        bhkBlendController_AddKey(point);
    }
}
}  // namespace fnv_00c9ba40

namespace fnv_00c9bef0 {
struct TlsBlock_t
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
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct FUN_00c9bef0_cls
{
    void __thiscall CloneTo(FUN_00c9aeb0_t* obj, int arg);
    FUN_00c9aeb0_t* CreateObject(int arg);
};

// @fnv 0x00c9bef0
FUN_00c9aeb0_t* FUN_00c9bef0_cls::CreateObject(int arg)
{
    TlsGuard_t guard;
    FUN_00c9aeb0_t* obj = new FUN_00c9aeb0_t();
    this->CloneTo(obj, arg);
    return obj;
}
}  // namespace fnv_00c9bef0

struct FUN_00c9ea90_Base
{
    virtual void b0();
    FUN_00c9ea90_Base(int a, int b);
};

struct FUN_00c9ea90 : FUN_00c9ea90_Base
{
    virtual void v0();

    FUN_00c9ea90(int a1);
};

// @fnv 0x00c9ea90
FUN_00c9ea90::FUN_00c9ea90(int aiValue) : FUN_00c9ea90_Base(aiValue, 2)
{
    char* self = (char*)this;
    *(volatile int*)(self + 0x8c) = 0;
    *(volatile int*)(self + 0x90) = 0;
    *(volatile unsigned int*)(self + 0x94) = 0x80000000u;
    *(volatile int*)(self + 0x98) = 0;
    *(volatile int*)(self + 0x9c) = 0;
    *(volatile unsigned int*)(self + 0xa0) = 0x80000000u;
    char* pa = self + 0x10;
    *(unsigned char*)(pa + 0x10) = (unsigned char)((unsigned int)self - (unsigned int)pa);
}

namespace fnv_00c9eae0 {
// FUN_00c9eae0 : cdecl one-arg entry point that forwards a record pointer and
// a 16-bit count field to the game allocator's virtual slot 2.

struct FUN_00c9eae0_alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p, unsigned short count);
};

hkMemoryRouter* hkMemoryRouter_getInstance();

struct FUN_00c9eae0_rec
{
    int unk00;
    unsigned short m_w04;
};

// @fnv 0x00c9eae0
// src: GUESS 0x00c9eae0 (confidence: low)
void __cdecl Object_UpdateFields_00c9eae0(FUN_00c9eae0_rec* rec)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    FUN_00c9eae0_alloc* allocator = (FUN_00c9eae0_alloc*)holder->m_heap;
    unsigned short count = rec->m_w04;
    allocator->v2(rec, count);
}
}  // namespace fnv_00c9eae0

namespace fnv_00c9eb00 {
struct FnvCpu_FUN_00c9eb00_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};

struct FnvCpu_FUN_00c9eb00_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00d08130();
    FnvCpu_FUN_00c9eb00_CpuObject* FUN_00c9eb00(unsigned int flags);
};
// @fnv 0x00c9eb00
FnvCpu_FUN_00c9eb00_CpuObject* FnvCpu_FUN_00c9eb00_CpuObject::FUN_00c9eb00(unsigned int flags)
{
    FUN_00d08130();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        ((FnvCpu_FUN_00c9eb00_CpuAllocator*)holder->m_heap)->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00c9eb00

struct TreeResultData
{
    int unk00;
    int unk04;
    void* m_pIntegerData;
};

// Recursively walks the node tree, appending each node's result value to arr, growing arr via ResizeAudioStream when full.
// @fnv 0x00c80930
void __cdecl CollectTreeResultValues(TreeNode_cls* node, SpawnedPtrArray* arr)
{
    TreeHost_cls* host;
    TreeResult_cls* result;
    TreeResultData* data;
    void* value;
    hkMemoryRouter* holder;
    TreeNode_cls* child;
    void** slot;
    unsigned int i;

    if (node)
    {
        host = node->m_1c;
        if (host)
        {
            result = host->FindResult(&DAT_012043f8);
            if (result)
            {
                data = (TreeResultData*)result->unk10;
                if (data)
                {
                    value = data->m_pIntegerData;
                    holder = hkMemoryRouter_getInstance();
                    if (arr->m_uiCount == (arr->m_uiCapacity & 0x3fffffff))
                    {
                        ResizeAudioStream(holder->m_heap, arr, 4);
                    }
                    slot = arr->m_pData + arr->m_uiCount;
                    *slot = value;
                    slot[0] = value;
                    arr->m_uiCount++;
                }
            }
        }
        child = node->v03();
        if (child)
        {
            i = 0;
            while (i < child->m_a6)
            {
                CollectTreeResultValues(child->m_a0[i], arr);
                i++;
            }
        }
    }
}

// Give the object an emissive material of the given color, notify listeners, then update it through the owner.

extern bool g_bC11F0Debug;
extern void(__cdecl* g_pfnC11F0EmissiveChanged)(NiAVObject* pkObject, NiColor* pkColor);

void __cdecl C11F0DebugColor(int m_uiSoundID, NiColor* pkColor);

class C11F0Material
{
  public:
    C11F0Material();
    virtual ~C11F0Material();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    void SetEmittance(const NiColor& kColor)
    {
        m_kEmissive = kColor;
        m_uiRevisionID++;
    }

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    NiColor m_kEmissive;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    unsigned int m_uiRevisionID;
    int unk48;
};

class C11F0Owner
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual void UnkB4();
    virtual void UnkB8();
    virtual void UnkBC();
    virtual void UnkC0();
    virtual void UnkC4();
    virtual void UnkC8();
    virtual void UnkCC();
    virtual void UnkD0();
    virtual void UnkD4();
    virtual void UnkD8();
    virtual void UpdateObject(NiAVObject* pkObject, bool bForce);
};

// @fnv 0x00c811f0
void AttachEmissiveMaterial(NiAVObject* pkObject, C11F0Owner* pkOwner, int m_uiSoundID, NiColor* pkColor)
{
    NiColor kColor = *pkColor;
    if (g_bC11F0Debug)
        C11F0DebugColor(m_uiSoundID, &kColor);

    C11F0Material* pkMaterial = new C11F0Material;
    pkMaterial->SetEmittance(kColor);
    pkObject->AttachProperty((NiObject*)pkMaterial);

    if (g_pfnC11F0EmissiveChanged)
        g_pfnC11F0EmissiveChanged(pkObject, &kColor);

    pkOwner->UpdateObject(pkObject, true);
}

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    int uiSize = sizeof(T);
    kIstr->BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiStream* kStream, T& value)
{
    NiBinaryStreamLoad(*(NiBinaryStream**)((char*)kStream + 0x24c), &value);
}

struct C818F0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void bhkCollisionObject_LoadBinary(NiStream* p);
    void bhkBlendCollisionObject_LoadBinary(NiStream* p);
};

// @fnv 0x00c818f0
// src: XBOX_PDB 0x00c818f0
void C818F0_cls::bhkBlendCollisionObject_LoadBinary(NiStream* pStream)
{
    int buf;
    bhkCollisionObject_LoadBinary(pStream);
    ReadBinaryValue(pStream, m_18);
    ReadBinaryValue(pStream, m_1c);
    if (*(unsigned int*)((char*)pStream + 4) < 8)
    {
        ReadBinaryValue(pStream, buf);
        ReadBinaryValue(pStream, buf);
    }
}

struct S_00c81b40_Callee
{
    virtual void m_v01();
    virtual void m_v02();
    virtual void m_v03();
    virtual void m_v04();
    virtual void m_v05();
    virtual void m_v06();
    virtual void m_v07();
    virtual void m_v08();
    virtual void m_v09();
    virtual void m_v10();
    virtual void m_v11();
    virtual void m_v12();
    virtual void m_v13();
    virtual void m_v14();
    virtual void m_v15();
    virtual void m_v16();
    virtual void m_v17();
    virtual void m_v18();
    virtual void m_v19();
    virtual void m_v20();
    virtual void m_v21();
    virtual void m_v22();
    virtual void m_v23();
    virtual void m_v24();
    virtual void m_v25();
    virtual void m_v26();
    virtual void m_v27();
    virtual void m_v28();
    virtual void m_v29();
    virtual void m_v30();
    virtual void m_v31();
    virtual void m_v32();
    virtual void m_v33();
    virtual void m_v34();
    virtual void m_v35();
    virtual void m_v36();
    virtual void m_v37();
    virtual void m_v38();
    virtual void m_v39();
    virtual void m_v40(int* argument);

    int unk04;
    unsigned char* m_data8;
};

struct S_00c81b40_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00c81b40_Callee* unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int* unk24;
    int unk28;

    void UpdateCountdown();
};

// Decrements unk28; when it reaches zero, checks the callee's data flags for 8 or 0x1d and calls m_v40 with unk24.
// @fnv 0x00c81b40
void S_00c81b40_Owner::UpdateCountdown()
{
    unk28--;

    if (unk28 > 0)
        return;

    S_00c81b40_Callee* callee = unk10;
    unk28 = 0;

    if (callee == 0)
        return;

    unsigned char* data = callee->m_data8;

    if (data != 0)
        data += 0x10;

    unsigned int flags = data ? *(unsigned int*)(data + 0x1c) : 0;

    flags &= 0x7f;

    if (flags != 8 && flags != 0x1d)
        return;

    int* argument = unk24;
    if (argument == 0)
        return;

    callee->m_v40(argument);
}

char* __cdecl CreateDebugString(const char* pcName, float fValue);
char* __cdecl CreateDebugString(const char* pcName, bool bValue);
char* __cdecl CreateDebugString(const char* pcName, const char* pcValue);
extern char* g_01267e64_str;

__forceinline bool GetFlagBit8(unsigned short f)
{
    return (f >> 8) & 1;
}
__forceinline bool GetFlagBit9(unsigned short f)
{
    return (f >> 9) & 1;
}
struct FUN_00c825b0_cls
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    unsigned short unk0e;
    int unk10;
    int unk14;
    float m_f18;
    float m_f1c;
    int unk20;
    int m_i24;

    void bhkCollisionObject_AddViewerStrings(ViewerStrings* pkStrings);
    void AddToViewerStrings(ViewerStrings* pkStrings);
};

// @fnv 0x00c825b0
void FUN_00c825b0_cls::AddToViewerStrings(ViewerStrings* pkStrings)
{
    TlsGuard_t guard;
    bhkCollisionObject_AddViewerStrings(pkStrings);
    char* pcString;
    pcString = CreateDebugString(g_01267e64_str);
    pkStrings->Add(pcString);
    pcString = CreateDebugString("fHeirGain", m_f18);
    pkStrings->Add(pcString);
    pcString = CreateDebugString("fVelGain", m_f1c);
    pkStrings->Add(pcString);
    pcString = CreateDebugString("bBlendPos", GetFlagBit8(m_usFlags));
    pkStrings->Add(pcString);
    pcString = CreateDebugString("bAlwaysBlend", GetFlagBit9(m_usFlags));
    pkStrings->Add(pcString);
    char buf[64];
    sprintf_s(buf, 64, "0x%08X", m_i24);
    pcString = CreateDebugString("Stored World", buf);
    pkStrings->Add(pcString);
}

struct FUN_00c84900_vtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int FUN_00c84900_call(unsigned int value);
};
struct FUN_00c84900_object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* field20;
};
extern unsigned char __cdecl bhkCollisionFilter_IsCollisionEnabled(void* object, unsigned int value);
// Calls the caller's virtual method with value, passes the result and object->field20 to FUN_00c84740, and stores the returned byte in output.
// @fnv 0x00c84900
unsigned char* __stdcall CallAndStoreResult(unsigned char* output, FUN_00c84900_object* object, int unused,
                                            FUN_00c84900_vtbl* caller, unsigned int value)
{
    unsigned int result = caller->FUN_00c84900_call(value);
    void* field = object->field20;
    *output = bhkCollisionFilter_IsCollisionEnabled(field, result);
    return output;
}

char* __cdecl NiGetViewerString_00a7d5e0(const char* prefix, const char* str);
char* __cdecl NiGetViewerString_00a7d510(const char* prefix, unsigned int val);
char* __cdecl NiGetViewerString(const char* prefix, bool val);

extern const char* kFilterLayers[];
extern const char* kFilterParts[];

struct HavokFilterInfo
{
    unsigned int m_uFilterInfo;

    unsigned short GetGroup() const
    {
        return (unsigned short)(m_uFilterInfo >> 16);
    }
    unsigned int GetLayer() const
    {
        return m_uFilterInfo & 0x7F;
    }
    bool GetLink() const
    {
        return (m_uFilterInfo >> 15) & 1;
    }
    unsigned int GetPart() const
    {
        return (m_uFilterInfo >> 8) & 0x1F;
    }
    bool GetNoCol() const
    {
        return (m_uFilterInfo >> 14) & 1;
    }
    bool GetScaled() const
    {
        return (m_uFilterInfo >> 13) & 1;
    }

    void AppendToViewerStrings(ViewerStrings* pkStrings);
};

static __forceinline void AddString(ViewerStrings* pkStrings, char* pcString)
{
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, pcString);
}

// Formats the filter info and its group, layer, link, part, no-collision and scaled flags into prefixed strings appended to pkStrings.
// @fnv 0x00c849b0
void HavokFilterInfo::AppendToViewerStrings(ViewerStrings* pkStrings)
{
    char acBuffer[128];

    sprintf_s(acBuffer, sizeof(acBuffer), "0x%08X", m_uFilterInfo);
    AddString(pkStrings, NiGetViewerString_00a7d5e0("COLFILTER", acBuffer));

    sprintf_s(acBuffer, sizeof(acBuffer), "0x%X", GetGroup());
    AddString(pkStrings, NiGetViewerString_00a7d5e0("-GROUP", acBuffer));

    AddString(pkStrings, NiGetViewerString_00a7d5e0("-LAYER", kFilterLayers[GetLayer()]));

    AddString(pkStrings, NiGetViewerString("-LINK", GetLink()));

    if (GetLayer() == 8)
        goto LABEL_PART_STR;
    if (GetLayer() == 0x1D)
    {
    LABEL_PART_STR:
        const char* pszPart = kFilterParts[GetPart()];
        AddString(pkStrings, NiGetViewerString_00a7d5e0("-PART", pszPart));
    }
    else if (GetLink())
    {
        AddString(pkStrings, NiGetViewerString_00a7d510("-PART", GetPart()));
    }

    AddString(pkStrings, NiGetViewerString("-NOCOL", GetNoCol()));

    AddString(pkStrings, NiGetViewerString("-SCALED", GetScaled()));
}

struct FUN_00c84d50_arg
{
    int m_unk000;
    int m_unk004;
    int m_unk008;
    int m_unk00c;
    int m_unk010;
    int m_unk014;
    int m_unk018;
    int m_unk01c;
    int m_unk020;
    int m_unk024;
    int m_unk028;
    int m_unk02c;
    int m_unk030;
    int m_unk034;
    int m_unk038;
    int m_unk03c;
    int m_unk040;
    int m_unk044;
    int m_unk048;
    int m_unk04c;
    int m_unk050;
    int m_unk054;
    int m_unk058;
    int m_unk05c;
    int m_unk060;
    int m_unk064;
    int m_unk068;
    int m_unk06c;
    int m_unk070;
    int m_unk074;
    int m_unk078;
    int m_unk07c;
    int m_unk080;
    int m_unk084;
    int m_unk088;
    int m_unk08c;
    int m_unk090;
    int m_unk094;
    int m_unk098;
    int m_unk09c;
    int m_unk0a0;
    int m_unk0a4;
    int m_unk0a8;
    int m_unk0ac;
    int m_unk0b0;
    int m_unk0b4;
    int m_unk0b8;
    int m_unk0bc;
    int m_unk0c0;
    int m_unk0c4;
    int m_unk0c8;
    int m_unk0cc;
    int m_unk0d0;
    int m_unk0d4;
    int m_unk0d8;
    int m_unk0dc;
    int m_unk0e0;
    int m_unk0e4;
    int m_unk0e8;
    int m_unk0ec;
    int m_unk0f0;
    int m_unk0f4;
    int m_unk0f8;
    int m_unk0fc;
    int m_unk100;
    int m_unk104;
    int m_unk108;
    int m_unk10c;
    int m_unk110;
    int m_unk114;
    int m_unk118;
    int m_unk11c;
    int m_unk120;
    int m_unk124;
    int m_unk128;
    int m_unk12c;
    int m_unk130;
    int m_unk134;
    int m_unk138;
    int m_unk13c;
    int m_unk140;
    int m_unk144;
    int m_unk148;
    int m_unk14c;
    int m_unk150;
    int m_unk154;
    int m_unk158;
    int m_unk15c;
    int m_unk160;
    int m_unk164;
    int m_unk168;
    int m_unk16c;
    int m_unk170;
    int m_unk174;
    int m_unk178;
    int m_unk17c;
    int m_unk180;
    int m_unk184;
    int m_unk188;
    int m_unk18c;
    int m_unk190;
    int m_unk194;
    int m_unk198;
    int m_unk19c;
    int m_unk1a0;
    int m_unk1a4;
    int m_unk1a8;
    int m_unk1ac;
    int m_unk1b0;
    int m_unk1b4;
    int m_unk1b8;
    int m_unk1bc;
    int m_unk1c0;
    int m_unk1c4;
    int m_unk1c8;
    int m_unk1cc;
    int m_unk1d0;
    int m_unk1d4;
    int m_unk1d8;
    int m_unk1dc;
    int m_unk1e0;
    unsigned char m_unk1e4;
};

struct FUN_00c84d50_cls
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
    virtual void v41(void* object);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual int* v45(void*& object);

    int m_unk04;
    int m_unk08;
    int m_unk0c;
    unsigned int m_flags;

    void SaveSerializeData(void* arg);
    void bhkShape_SaveBinary(void* arg);
};

// @fnv 0x00c84d50
// src: XBOX_PDB 0x00c84d50
void FUN_00c84d50_cls::bhkShape_SaveBinary(void* arg)
{
    void* object;
    int* result = v45(object);
    unsigned int value = m_flags & 0x1fu;
    *result = value;

    FUN_00c84d50_arg* data = static_cast<FUN_00c84d50_arg*>(arg);
    if (data->m_unk1e4 != 1)
        *result = _byteswap_ulong(value);

    SaveSerializeData(arg);

    if (data->m_unk1e4 != 1)
        *result = _byteswap_ulong(*result);

    v41(object);
}

struct Out_00c85880
{
    int m_00;
    int m_04;
    unsigned char m_08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    int unk0C;
    int m_10;
};

struct Sub_00c85880
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned char m_18;
    int m_1C;
};

struct State_00c85880
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Sub_00c85880 m_10;
};

struct Owner_00c85880
{
    int unk00;
    int unk04;
    State_00c85880* m_08;

    void FillOutputFromState(Out_00c85880* o);
};

// Copies fields from the state's sub-structure into the output, then sets m_10 to 0 and m_00 from the sub-structure's m_1C or 0.
// @fnv 0x00c85880
void Owner_00c85880::FillOutputFromState(Out_00c85880* pOut)
{
    TlsGuard_t guard;

    State_00c85880* q = this->m_08;
    if (q)
    {
        Sub_00c85880* s = &q->m_10;
        if (s != 0)
        {
            pOut->m_04 = s->unk00;
            pOut->m_08 = s->m_18;
        }
    }

    pOut->m_10 = 0;

    State_00c85880* r = this->m_08;
    Sub_00c85880* sub = (r != 0) ? &r->m_10 : 0;
    pOut->m_00 = (sub != 0) ? sub->m_1C : 0;
}





struct WorldHolder
{
    int unk00;
    int unk04;
    bhkWorld* m_pOwningWorld;
};

struct PhantomData
{
    WorldHolder* m_holder;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_pCollisionShape;
};

struct WorldObjectX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    PhantomData m_data;
};

void __cdecl GetLayerColor(int shape, NiPoint3* out);

// Raw string-table handle scope: no bound game methods; SetName consumes it through the shared NiFixedString layout.
struct ScopedInternedName
{
    char* m_handle;
    ScopedInternedName(const char* text) : m_handle(NiGlobalStringTable::AddString(text)) {}
    __forceinline ~ScopedInternedName()
    {
        if (m_handle != _EmptyFS)
            InterlockedDecrement((long*)(m_handle - 8));
    }
};

// The shared bhkWorldObject supplies m_pHavokObject; its debug-node helper is not declared yet.
struct WorldObjectDebugView : bhkWorldObject
{
    NiNode* AddDebugNodeToWorld(NiNode* node);
};

// Ensures node has a name, computes a point via GetLayerColor and adds the node to the world's debug nodes, returning the node.
// @fnv 0x00c85d70
NiNode* WorldObjectDebugView::AddDebugNodeToWorld(NiNode* node)
{
    PhantomData* data;
    WorldHolder* holder;
    bhkWorld* world;
    if (this && reinterpret_cast<WorldObjectX*>(m_pHavokObject) && (data = &reinterpret_cast<WorldObjectX*>(m_pHavokObject)->m_data) != 0 && (holder = data->m_holder) != 0 &&
        (world = holder->m_pOwningWorld) != 0)
    {
        if (!node)
            node = new NiNode(0);
        if (!node->m_kName.m_kHandle)
        {
            ScopedInternedName name("bhkWorldObject");
            node->SetName(reinterpret_cast<const NiFixedString&>(name));
        }
        NiPoint3 pt;
        pt.x = 0.0f;
        pt.y = 0.0f;
        pt.z = 0.0f;
        PhantomData* pData2 = reinterpret_cast<WorldObjectX*>(m_pHavokObject) ? &reinterpret_cast<WorldObjectX*>(m_pHavokObject)->m_data : 0;
        GetLayerColor(pData2 ? pData2->m_pCollisionShape : 0, &pt);
        // bhkWorld.h leaves slot 53 (AddDebugNode) untyped; preserve its two-argument virtual call here.
        typedef void (__thiscall* AddDebugNode)(bhkWorld*, NiNode*, NiPoint3*);
        reinterpret_cast<AddDebugNode>((*reinterpret_cast<void***>(world))[53])(world, node, &pt);
        return node;
    }
    return node;
}

extern __declspec(thread) int g_iC88760AllocTag;

struct BC88760AllocTagScope
{
    int m_iSaved;

    BC88760AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC88760AllocTag;
        g_iC88760AllocTag = aiAllocationTag;
    }
    ~BC88760AllocTagScope()
    {
        g_iC88760AllocTag = m_iSaved;
    }
};

class BC88760CloningProcess;

class BC88760Base
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    BC88760Base();
    virtual ~BC88760Base();

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
};

class BC88760Derived : public BC88760Base
{
  public:
    BC88760Derived()
    {}
    virtual ~BC88760Derived();

    void CopyMemberData(BC88760Derived* pkDest, BC88760CloningProcess& kCloning);
    BC88760Derived* WeaponObject_CreateClone(BC88760CloningProcess& kCloning);
};

// @fnv 0x00c88760
// src: XBOX_PDB 0x00c88760
BC88760Derived* BC88760Derived::WeaponObject_CreateClone(BC88760CloningProcess& kCloning)
{
    BC88760AllocTagScope kScope(0x10);
    BC88760Derived* pkClone = new BC88760Derived;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

inline NiUpdateData::NiUpdateData() : fTime(0.0f), pad1(0), pad2(0), pad3(0), pad4(0), pad5(0) {}

struct FUN_00c88810_Collision
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
};

void bhkWorld_SetMotion(NiNode* apNode, int aiArg, bool abA, bool abB, bool abC);
// Updates apObject, then for each child of the Chain01 node's parent with a collision object, calls Unk_2A and FUN_00c6a350.
// @fnv 0x00c88810
void UpdateChainCollision(NiAVObject* apObject)
{
    NiNode* pkRoot = apObject->IsSceneNode();
    if (!pkRoot)
        return;
    NiAVObject* pkChain = static_cast<const NiNode*>(pkRoot)->GetObjectByName("Chain01");
    if (!pkChain)
        return;
    apObject->Update(NiUpdateData());
    NiNode* pkParent = pkChain->m_pkParent;
    if (!pkParent)
        return;
    for (unsigned int i = 0; i < pkParent->m_kChildren.m_usSize; i++)
    {
        NiAVObject* pkChild = pkParent->m_kChildren.m_pBase[i].m_pObject;
        if (pkChild)
        {
            FUN_00c88810_Collision* pkCollision = reinterpret_cast<FUN_00c88810_Collision*>(pkChild->m_spCollisionObject.m_pObject);
            if (pkCollision)
            {
                pkCollision->Unk_2A();
                bhkWorld_SetMotion((NiNode*)pkChild, 1, false, true, true);
            }
        }
    }
}

// LinkObject: resolve the two linked bodies and store their Havok entities in the constraint data.

class C8A910Body
{
  public:
    int unk00;
    int unk04;
    void* m_pkEntity;
};

struct C8A910ConstraintData
{
    int unk00;
    void* m_pkEntityA;
    void* m_pkEntityB;
};

class C8A910Constraint
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual C8A910ConstraintData* GetConstraintData(unsigned int& ruiType);

    void LinkObjectBase(NiStream& kStream);
    void bhkBinaryAction_LinkObject(NiStream& kStream);
};

// @fnv 0x00c8a910
// src: XBOX_PDB 0x00c8a910
void C8A910Constraint::bhkBinaryAction_LinkObject(NiStream& kStream)
{
    C8A910Body* pkBodyA = (C8A910Body*)kStream.GetLoadedObject();
    C8A910Body* pkBodyB = (C8A910Body*)kStream.GetLoadedObject();
    unsigned int uiType;
    C8A910ConstraintData* pkData = GetConstraintData(uiType);
    if (pkBodyA)
    {
        pkData->m_pkEntityA = pkBodyA->m_pkEntity;
        pkData->m_pkEntityB = pkBodyB ? pkBodyB->m_pkEntity : 0;
    }
    LinkObjectBase(kStream);
}

class Dispatcher
{
  public:
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
    virtual void Dispatch(void* p);
};

class Node1
{
  public:
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
};

class Mid
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Node1* m_18;
    Node1* m_1c;
};

class RefChainOwner
{
  public:
    int unk00;
    int unk04;
    Mid* m_08;
    void SaveSerializeData(Dispatcher* p);
    void DispatchChainNodes(Dispatcher* arg);
};

// Dispatches the m_0c payloads of the m_18 and m_1c nodes reached through m_08, then calls SaveSerializeData.
// @fnv 0x00c8aac0
void RefChainOwner::DispatchChainNodes(Dispatcher* pDispatcher)
{
    Node1* n = (this && m_08) ? m_08->m_18 : 0;
    void* q;
    switch (n != 0)
    {
    case 0:
        q = 0;
        break;
    default:
        q = n->m_0c;
        break;
    }
    pDispatcher->Dispatch(q);

    Node1* k = (this && m_08) ? m_08->m_1c : 0;
    void* r;
    switch (k != 0)
    {
    case 0:
        r = 0;
        break;
    default:
        r = k->m_0c;
        break;
    }
    pDispatcher->Dispatch(r);

    SaveSerializeData(pDispatcher);
}

extern void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_01030bf4;
extern int DAT_010c44e4;
extern int DAT_010c485c;
extern int DAT_012680f8;
extern int DAT_012686d0;
extern int DAT_012681a0;

struct Base_00c8ae60
{
    int* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void UpdateState_00c87c30();
    Base_00c8ae60()
    {
        UpdateState_00c87c30();
    }
};
struct Object_00c8ae60 : Base_00c8ae60
{
    static void* operator new(unsigned int bytes)
    {
        return Object_DispatchCommandFour(bytes);
    }
    Object_00c8ae60()
    {
        vtable = &DAT_01030bf4;
        unk0c = 0;
        unk10 = 0;
        ++DAT_012680f8;
        vtable = &DAT_010c44e4;
        ++DAT_012686d0;
        vtable = &DAT_010c485c;
        ++DAT_012681a0;
    }
};
// Allocates and constructs a new Object_00c8ae60, returning the pointer.
// @fnv 0x00c8ae60
// src: EXE 0x00c8ae60
Object_00c8ae60* __cdecl bhkListShape_CreateObject()
{
    return new Object_00c8ae60;
}

// Forward a call to every child wrapper of this group's Havok object.

class C8B4D0Wrapper
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Apply(int iArg1, int iArg2);
};

struct C8B4D0Child
{
    int unk00;
    int unk04;
    C8B4D0Wrapper* m_pkWrapper;
};

struct C8B4D0Slot
{
    C8B4D0Child* m_pkChild;
    int unk04;
    int unk08;
    int unk0C;
};

class C8B4D0Counter
{
  public:
    virtual void Unk_00();
    virtual int GetCount();
};

struct C8B4D0HavokGroup
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8B4D0Counter m_kCounter;
    int unk14;
    C8B4D0Slot* m_pkSlots;
};

class C8B4D0Group
{
  public:
    int unk00;
    int unk04;
    C8B4D0HavokGroup* m_pkHavok;

    C8B4D0HavokGroup* GetHavok()
    {
        return this ? m_pkHavok : 0;
    }
    int GetChildCount()
    {
        C8B4D0HavokGroup* pkHavok = GetHavok();
        return pkHavok ? pkHavok->m_kCounter.GetCount() : 0;
    }
    C8B4D0Child* GetChild(int i)
    {
        C8B4D0HavokGroup* pkHavok = GetHavok();
        return pkHavok ? pkHavok->m_pkSlots[i].m_pkChild : 0;
    }

    void ApplyToChildren(int iArg1, int iArg2);
};

// Iterates all children of the group's havok data and calls Apply(iArg1, iArg2) on each child's wrapper if present.
// @fnv 0x00c8b4d0
void C8B4D0Group::ApplyToChildren(int iArg1, int iArg2)
{
    int iChildCount = GetChildCount();
    for (int i = 0; i < iChildCount; i++)
    {
        C8B4D0Child* pkChild = GetChild(i);
        C8B4D0Wrapper* pkWrapper = pkChild ? pkChild->m_pkWrapper : 0;
        if (pkWrapper)
            pkWrapper->Apply(iArg1, iArg2);
    }
}

hkMemoryRouter* hkMemoryRouter_getInstance();

struct C8B8A0Alloc;

void hkArrayUtil__reserve(C8B8A0Alloc* allocator, hkArrayBase<int>* arr, int capacity, int elemSize);
static __forceinline void C8B8A0Array_GrowArrayCapacity(hkArrayBase<int>& self, C8B8A0Alloc& alloc, int n);

static __forceinline void C8B8A0Array__setSize(hkArrayBase<int>& self, C8B8A0Alloc& alloc, int n);

static __forceinline void C8B8A0Array_SetSizeAndGrow(hkArrayBase<int>& self, int n);

static __forceinline void C8B8A0Array_clear(hkArrayBase<int>& self);

static __forceinline void C8B8A0Array_GrowArrayCapacity(hkArrayBase<int>& self, C8B8A0Alloc& alloc, int n)
{
        const int capacity = self.getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, (&self), newSize, sizeof(int));
        }
    }

static __forceinline void C8B8A0Array__setSize(hkArrayBase<int>& self, C8B8A0Alloc& alloc, int n)
{
        C8B8A0Array_GrowArrayCapacity(self, alloc, n);
        self.m_iElementCount = n;
    }

static __forceinline void C8B8A0Array_SetSizeAndGrow(hkArrayBase<int>& self, int n)
{
        hkMemoryRouter* router = hkMemoryRouter_getInstance();
        C8B8A0Alloc* allocator = (C8B8A0Alloc*)router->m_heap;
        C8B8A0Array__setSize(self, *allocator, n);
    }

static __forceinline void C8B8A0Array_clear(hkArrayBase<int>& self)
{
        self.m_iElementCount = 0;
    }

struct C8B8A0Out
{
    int unk00;
    hkArrayBase<int> m_keys;
    hkArrayBase<int> m_iSlotIds;
};

struct C8B8A0Iface
{
    virtual void v00();
    virtual int GetCount();
    virtual void* GetFirst();
    virtual void* GetNext(void* it);
    virtual int GetValue(void* it);
};

struct C8B8A0Entry
{
    int m_key;
    int unk04;
    int unk08;
    int unk0C;
};

struct C8B8A0Map
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8B8A0Iface m_iface;
    int unk14;
    C8B8A0Entry* m_entries;
};

struct MyObj
{
    int unk00;
    int unk04;
    C8B8A0Map* m_map;
    void bhkShape_CopyCinfo(void* out);
    void FillKeyValueArrays(C8B8A0Out* out);
};

// Resizes the output key and value arrays to the map's entry count, then fills them with each entry's key and interface value.
// @fnv 0x00c8b8a0
void MyObj::FillKeyValueArrays(C8B8A0Out* out)
{
    bhkShape_CopyCinfo(out);
    C8B8A0Map* m;
    unsigned int n = (this && (m = m_map) != 0) ? m->m_iface.GetCount() : 0;
    C8B8A0Array_clear(out->m_keys);
    hkArrayBase<int>* keys = &out->m_keys;
    C8B8A0Array_SetSizeAndGrow((*(keys)), n);
    hkArrayBase<int>* values = &out->m_iSlotIds;
    C8B8A0Array_SetSizeAndGrow((*(values)), n);
    void* it = (this && (m = m_map) != 0) ? m->m_iface.GetFirst() : 0;
    for (unsigned int i = 0; i < n; i++)
    {
        keys->m_data[i] = (this && (m = m_map) != 0) ? m->m_entries[i].m_key : 0;
        values->m_data[i] = (this && (m = m_map) != 0) ? m->m_iface.GetValue(it) : 0;
        it = (this && (m = m_map) != 0) ? m->m_iface.GetNext(it) : 0;
    }
}

extern __declspec(thread) int g_C8B9E0AllocTag;

struct C8B9E0AllocTagScope
{
    int m_iSaved;

    C8B9E0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_C8B9E0AllocTag;
        g_C8B9E0AllocTag = aiAllocationTag;
    }
    ~C8B9E0AllocTagScope()
    {
        g_C8B9E0AllocTag = m_iSaved;
    }
};

extern MemoryManager g_kC8B9E0Heap;



class C8B9E0Listener
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return g_kC8B9E0Heap.Allocate(uiSize);
    }
    static void operator delete(void* pvMem);

    C8B9E0Listener() : m_pkOwnerManager(0)
    {}

    void* m_pkOwnerManager;
    hkArrayBase<void*> m_kAdded;
    hkArrayBase<void*> m_kRemoved;
};

class C8B9E0Owner
{
  public:
    int unk00;
    int unk04;
    void* m_pkWorld;
    C8B9E0Listener* m_pkListener;

    void AttachListener(C8B9E0Listener* pkListener);
    C8B9E0Listener* GetOrCreateListener(bool* pbCreated);
};

// Sets *pbCreated when m_pkListener is null, allocates a listener and attaches it if m_pkWorld is set, then returns m_pkListener.
// @fnv 0x00c8b9e0
C8B9E0Listener* C8B9E0Owner::GetOrCreateListener(bool* pbCreated)
{
    C8B9E0AllocTagScope kScope(0x10);
    *pbCreated = (m_pkListener == 0);
    if (*pbCreated)
    {
        m_pkListener = new C8B9E0Listener;
        if (m_pkWorld)
            AttachListener(m_pkListener);
    }
    return m_pkListener;
}

struct ListAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* data, int bytes);
};
struct ShapeArray
{
    FUN_00c8b000_Item** data;
    int size;
    int capacity;
    ShapeArray() : data(0), size(0), capacity(0x80000000)
    {}
    ~ShapeArray()
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        ListAllocator* alloc = (ListAllocator*)holder->m_heap;
        size = 0;
        if (!(capacity & 0x80000000))
        {
            alloc->Free(data, (capacity & 0x3fffffff) * 4);
        }
        data = 0;
        capacity = 0x80000000;
    }
    void swap(ShapeArray& other)
    {
        FUN_00c8b000_Item** oldData = data;
        data = other.data;
        other.data = oldData;
        int oldSize = size;
        size = other.size;
        other.size = oldSize;
        int oldCapacity = capacity;
        capacity = other.capacity;
        other.capacity = oldCapacity;
    }
};
struct ListShapeData
{
    unsigned int header;
    ShapeArray shapes;
    ShapeArray keys;
};
struct ListShapeSave
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
    virtual void v41();
    virtual void* GetSharedData();
    virtual void v43();
    virtual void v44();
    virtual ListShapeData* GetDataPosition(bool* owned);
    void bhkShape_SaveBinary(NiStream* stream);
    void SaveListShape(NiStream* stream);
};
void __cdecl SaveUIntArray(NiStream* stream, ShapeArray* array);
// @fnv 0x00c8baa0
void ListShapeSave::SaveListShape(NiStream* stream)
{
    bool owned;
    ListShapeData* data = GetDataPosition(&owned);
    ShapeArray shapes;
    ShapeArray keys;
    data->shapes.swap(shapes);
    data->keys.swap(keys);
    if (*((unsigned char*)stream + 0x1e4) != 1)
    {
        void* shared = GetSharedData();
        bhkStream_SwapHKArray(reinterpret_cast<char*>(data), shared, reinterpret_cast<char*>(&data->keys));
        bhkStream_SwapHKArray(reinterpret_cast<char*>(data), shared, reinterpret_cast<char*>(&data->shapes));
    }
    unsigned int count = shapes.size;
    C8A4B0SaveBinary(*stream, count);
    for (unsigned int i = 0; i < count; ++i)
    {
        FUN_00c8b000_Item* item = shapes.data[i];
        stream->SaveLinkID(reinterpret_cast<const NiObject*>(item ? reinterpret_cast<C8A4B0Object*>(item->m_08) : 0));
    }
    bhkShape_SaveBinary(stream);
    SaveUIntArray(stream, &keys);
    if (*((unsigned char*)stream + 0x1e4) != 1)
    {
        void* shared = GetSharedData();
        bhkStream_SwapHKArray(reinterpret_cast<char*>(data), shared, reinterpret_cast<char*>(&data->keys));
        bhkStream_SwapHKArray(reinterpret_cast<char*>(data), shared, reinterpret_cast<char*>(&data->shapes));
    }
}

// @fnv 0x00c8cdb0
unsigned int* __cdecl SwapEndianBlocks(unsigned int* auiData)
{
    volatile unsigned int* p = auiData + 2;
    int n = 3;
    do
    {
        p[-2] = _byteswap_ulong(p[-2]);
        p[-1] = _byteswap_ulong(p[-1]);
        p[0] = _byteswap_ulong(p[0]);
        p[1] = _byteswap_ulong(p[1]);
        p += 4;
    } while (--n != 0);
    return auiData;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

extern __declspec(thread) int g_iAllocTagC9A;

struct AllocTagScopeC9A
{
    int m_iSaved;

    AllocTagScopeC9A(int aiAllocationTag)
    {
        m_iSaved = g_iAllocTagC9A;
        g_iAllocTagC9A = aiAllocationTag;
    }
    ~AllocTagScopeC9A()
    {
        g_iAllocTagC9A = m_iSaved;
    }
};

inline void ObstacleData::IncRefCount()
{
    InterlockedIncrement((long volatile*)&m_uiRefCount);
}
inline void ObstacleData::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}



void __cdecl FreeNodeC9A(void* pvNode);

template <class T> __declspec(noinline) void BSSimpleList<T>::Remove(const T& kItem)
{
    for (BSSimpleList* pkNode = this; pkNode->m_pkNext; pkNode = pkNode->m_pkNext)
    {
        BSSimpleList* pkNext = pkNode->m_pkNext;
        if (pkNext->m_item.m_pObject == kItem.m_pObject)
        {
            pkNode->m_pkNext = pkNext->m_pkNext;
            FreeNodeC9A(pkNext);
            return;
        }
    }
}

class ObstacleManagerC9A
{
  public:
    int unk00;
    int unk04;
    int unk08;
    BSSimpleList<NiPointer<ObstacleData> > m_kObstacles;

    void bhkEntityListener_RemoveEntity(ObstacleData* pkData);
};

// Removes the given obstacle from m_kObstacles when pkData is non-null and its ref count is above zero.
// @fnv 0x00c9a520
// src: XBOX_PDB 0x00c9a520
void ObstacleManagerC9A::bhkEntityListener_RemoveEntity(ObstacleData* pkData)
{
    AllocTagScopeC9A kScope(0x10);
    if (pkData && pkData->m_uiRefCount > 0)
        m_kObstacles.Remove(pkData);
}

struct FUN_00c9abc0_cls
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    short unk0a;
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
    float unk50;
    float unk54;
    void __thiscall bhkBlendController_RestoreOriginalGains(int param2);
};

// If the flag bit in unk09 is set and unk50 is non-negative, writes unk50 and unk54 into param2 at offsets 0x18/0x1c and resets both to -1.0f.
// @fnv 0x00c9abc0
// src: COMMUNITY 0x00c9abc0
void __thiscall FUN_00c9abc0_cls::bhkBlendController_RestoreOriginalGains(int param2)
{
    if ((unk09 & 1) != 0 && unk50 >= 0.0f)
    {
        *(float*)(param2 + 0x18) = unk50;
        *(float*)(param2 + 0x1c) = unk54;
        unk50 = unk54 = -1.0f;
    }
    return;
}

struct FUN_00c9a6c0
{
    float time, value1, value2;
    FUN_00c9a6c0();
};
struct TargetFlags
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int flags;
};
struct TargetBody
{
    int unk00, unk04, unk08, unk0c;
    TargetFlags flags;
};
struct TargetLink
{
    int unk00, unk04;
    TargetBody* body;
    unsigned int GetFlags() const
    {
        TargetFlags* info = body ? &body->flags : 0;
        return info ? info->flags : 0;
    }
};
struct TargetExtra
{
    int unk00, unk04, unk08, unk0c;
    TargetLink* link;
    int unk14;
    float start, end;
    float GetStart() const
    {
        return start;
    }
    float GetEnd() const
    {
        return end;
    }
};
struct ExtraList
{
    TargetExtra* FUN_00653290(int* type);
};
struct TargetController
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
    virtual void v35(float time);
    int unk04;
    unsigned short flags;
    unsigned short unk0a;
    float frequency, phase, start, end;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    LargeArray_c9ac00 keys;
    int unk50, unk54;
    unsigned int mode;
    void Reset();
    void bhkBlendController_AddKey(FUN_00c9a6c0* key);
};
struct SceneNode;
struct SceneObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual SceneNode* AsNode();
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    ExtraList* extras;
    TargetController* NiObjectNET_GetController(int* type);
};
struct SceneNode : SceneObject
{
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
    SceneObject** children;
    unsigned short capacity, childCount;
};
struct TimeRange
{
    float start, end;
};
extern TimeRange DAT_011b1090[];
extern TimeRange DAT_011b0f90[];
extern int DAT_01267e64;
extern const float DAT_01015f5c;
// Returns the smaller of two values by comparing b < a and returning b when true, otherwise a.
// @fnv 0x00c9b250
template <class T> inline T Minimum(const T& a, const T& b)
{
    return b < a ? b : a;
}
// src: COMMUNITY 0x00c9b250
void bhkBlendController_DoHit(SceneObject* object, float middle, bool alternate)
{
    if (!object)
        return;
    if (object->extras)
    {
        TargetExtra* extra = object->extras->FUN_00653290(&DAT_01267e64);
        if (extra)
        {
            unsigned int flags = 0;
            if (extra->link)
                flags = extra->link->GetFlags();
            unsigned int index = (flags >> 8) & 31;
            float first, last;
            if (alternate)
            {
                first = DAT_011b1090[index].start;
                last = DAT_011b1090[index].end;
            }
            else
            {
                first = DAT_011b0f90[index].start;
                last = DAT_011b0f90[index].end;
            }
            float start = Minimum(first, extra->GetStart());
            float end = Minimum(last, extra->GetEnd());
            TargetController* controller = object->NiObjectNET_GetController(&DAT_012681f0);
            if (controller && controller->mode <= 1)
            {
                controller->Reset();
                controller->mode = 1;
                if (controller->keys.m_uiESize == 0)
                {
                    FUN_00c9a6c0 keys[3];
                    keys[0].value1 = start;
                    keys[0].value2 = end;
                    keys[0].time = 0.0f;
                    keys[1].value1 = first;
                    keys[1].value2 = last;
                    keys[1].time = 0.15f;
                    keys[2].value2 = keys[2].value1 = 1.0f;
                    keys[2].time = 0.5f;
                    controller->keys.Resize(3);
                    for (unsigned int i = 0; i < 3; ++i)
                        controller->bhkBlendController_AddKey(&keys[i]);
                    controller->start = 0.0f;
                    controller->end = 1.0f;
                    controller->frequency = 1.0f;
                    controller->phase = 0.0f;
                    controller->flags = (controller->flags & 0xfff5) | 0x1c5;
                    controller->v35(DAT_01015f5c);
                }
            }
        }
    }
    SceneNode* node = object->AsNode();
    if (node)
        for (unsigned int i = 0; i < node->childCount; ++i)
            bhkBlendController_DoHit(node->children[i], middle, alternate);
}

namespace fnv_00c9b470 {
struct LocalRTTI
{
};
extern LocalRTTI g_01267e64, g_012043f8, g_012681f0;
extern float DAT_011b1190[];
struct PairRange
{
    float hi, lo;
};
extern PairRange DAT_011b06d8[];
extern float DAT_01015f5c;
struct HavokPart
{
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
};
struct Entity
{
    unsigned int unk00, unk04;
    HavokPart* unk08;
    void bhkWorldObject_SetCollisionFilter(unsigned int);
};
struct Collision
{
    unsigned int unk00, unk04, unk08, unk0C;
    Entity* unk10;
};
struct Physics
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
    virtual void v57(int);
    bhkFilter bhkWorldObject_GetCollisionFilter();
};
struct CollisionPhysics
{
    unsigned int unk00, unk04, unk08, unk0C;
    Physics* unk10;
};
struct FUN_00c9a6c0
{
    float x, y, z;
    FUN_00c9a6c0();
};
struct ControllerArray
{
    void Resize(int);
};
struct Controller
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
    virtual void v35(float);
    unsigned int unk04;
    unsigned short flags;
    unsigned short unk0A;
    float unk0C, unk10, unk14, unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    ControllerArray unk38;
    unsigned int unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58;
    void Reset();
    void bhkBlendController_AddKey(FUN_00c9a6c0*);
};
struct CastSource
{
    void* FUN_00653290(const LocalRTTI*);
};
struct Scene
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Scene* v3();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    CastSource* unk1C;
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
    Scene** children;
    unsigned short cap, count;
    Controller* NiObjectNET_GetController(const LocalRTTI*);
};
// Looks up collision/physics data on the object, configures a controller with scaled key points, and recurses into child scenes.
// @fnv 0x00c9b470
void ApplyCollisionEffect(Scene* object, float time)
{
    if (!object)
        return;
    Collision* collision;
    if (object->unk1C && (collision = (Collision*)object->unk1C->FUN_00653290(&g_01267e64)) != 0)
    {
        unsigned int filter = 0;
        Entity* entity = collision->unk10;
        if (entity)
        {
            HavokPart* part = entity->unk08;
            HavokPart* pAdjustedPart = part ? (HavokPart*)((char*)part + 0x10) : 0;
            filter = pAdjustedPart ? pAdjustedPart->unk1C : 0;
            filter = (filter & ~0x77u) | 8;
            entity->bhkWorldObject_SetCollisionFilter(filter);
        }
        unsigned int layer = (filter >> 8) & 31;
        float scale = DAT_011b1190[layer];
        Controller* controller = object->NiObjectNET_GetController(&g_012681f0);
        if (controller && scale >= 0.0f)
        {
            float hi = DAT_011b06d8[layer].hi;
            float lo = DAT_011b06d8[layer].lo;
            controller->Reset();
            controller->unk58 = 2;
            if (!controller->unk48)
            {
                FUN_00c9a6c0 points[2];
                points[0].x = points[0].z = points[0].y = 0.0f;
                points[1].y = hi;
                points[1].z = lo;
                points[1].x = scale;
                controller->unk38.Resize(2);
                for (int i = 0; i < 2; ++i)
                    controller->bhkBlendController_AddKey(&points[i]);
                controller->flags = (controller->flags & 0xfef5) | 0xc5;
                controller->unk14 = time;
                controller->unk18 = scale;
                controller->unk10 = 0.0f;
                controller->unk0C = 1.0f;
                controller->v35(DAT_01015f5c);
            }
        }
    }
    else if (object->unk1C)
    {
        CollisionPhysics* pCollisionPhysics = (CollisionPhysics*)object->unk1C->FUN_00653290(&g_012043f8);
        if (pCollisionPhysics && pCollisionPhysics->unk10)
        {
            Physics* physics = pCollisionPhysics->unk10;
            unsigned int filter = physics->bhkWorldObject_GetCollisionFilter().value;
            unsigned int layer = filter & 0x7f;
            if ((layer != 8 && layer != 29) || (filter & 0x1f00) == 0x1400)
                physics->v57(4);
        }
    }
    Scene* node = object->v3();
    if (node)
        for (unsigned int i = 0; i < node->count; ++i)
            ApplyCollisionEffect(node->children[i], time);
}
}  // namespace fnv_00c9b470

struct Node253;
struct HavokObject253
{
    int unk00, unk04, unk08;
    Node253* owner;
};
struct PhysicsData253
{
    int unk00;
    HavokObject253* first;
    HavokObject253* second;
};
struct Map253
{
    bool FUN_00a53c30(Node253* key, void*& value);
};
struct CloneProcess253
{
    Map253* map;
};
struct Node253
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual Node253* Clone(void* process);
    int references;
    HavokObject253* object;
};
struct Owner253
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual PhysicsData253* GetData(bool* temporary);
    void bhkSerializable_CopyMembers(void* destination, void* process);
    void ClonePhysicsData(void* destination, void* process);
};
// @fnv 0x00c8a850
void Owner253::ClonePhysicsData(void* destination, void* process)
{
    bool temporary;
    PhysicsData253* data = GetData(&temporary);
    Node253* first = data->first ? data->first->owner : 0;
    Node253* second = data->second ? data->second->owner : 0;
    CloneProcess253* context = static_cast<CloneProcess253*>(process);
    data->first = 0;
    data->second = 0;
    if (context->map->FUN_00a53c30(first, process))
    {
        Node253* clone = static_cast<Node253*>(process);
        data->first = clone ? clone->object : 0;
    }
    if (second)
    {
        Node253* clone;
        if (context->map->FUN_00a53c30(second, process))
            clone = static_cast<Node253*>(process);
        else
            clone = second->Clone(context);
        data->second = clone ? clone->object : 0;
    }
    bhkSerializable_CopyMembers(destination, context);
}

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_012043f8;
extern GlobalObjectO2_00a7b610 g_0126818c;
struct Param5380d0;
struct This5380d0
{
    bool bhkWorld_RemoveBody(Param5380d0*);
};
void EnableConstraintsAndZeroArrays(void*, void*);
struct ControllerRTTI
{
    const char* name;
    const ControllerRTTI* base;
};
struct ControllerOwner
{
    unsigned int unkCur;
    unsigned int unkValue;
    unsigned int uNewnk;
    unsigned int unk00C;
    unsigned int uTmpnk;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    This5380d0* manager;
};
struct ControllerObject
{
    virtual void slot();
    virtual void slotCur();
    virtual void slotValue();
    virtual void sNewlot();
    virtual void sTmplot();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual unsigned int GetType();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
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
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual ControllerOwner* GetOwner();
};
struct ControllerLink
{
    unsigned int unk, unk04;
    void* active;
    ControllerObject* object;
    void Process()
    {
        EnableConstraintsAndZeroArrays(this, active);
    }
    bool IsActive() const
    {
        return active != 0;
    }
    void Update()
    {
        if (IsActive())
            Process();
    }
    void ProcessIfActive()
    {
        if (active)
            EnableConstraintsAndZeroArrays(this, active);
    }
};
struct ControllerFallback
{
    ControllerObject* object;
};
struct IdleController
{
    virtual void slot();
    virtual void DeleteThis();
    virtual const ControllerRTTI* GetRTTI();
    virtual void sNewlot();
    virtual void sTmplot();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
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
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void HandleControllerData(This5380d0*);
    virtual void slot28();
    virtual void slot29();
    virtual void slot2A();
    virtual void slot2B();
    virtual void slot2C();
    virtual void slot2D();
    virtual void slot2E();
    virtual void slot2F();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual ControllerLink* GetLink();
    long refs;
    ControllerLink* link;
    ControllerFallback* fallback;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
    bool IsKindOfType(const ControllerRTTI* wanted)
    {
        const ControllerRTTI* type = GetRTTI();
        while (type)
        {
            if (type == wanted)
                return true;
            type = type->base;
        }
        return false;
    }
    void ProcessActive()
    {
        if (link->active)
            link->Process();
    }
    ControllerObject* GetObject()
    {
        return link ? link->object : (fallback ? fallback->object : 0);
    }
};
struct ControllerPtr
{
    IdleController* m_pObject;
    __forceinline ControllerPtr(IdleController* p) : m_pObject(p)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    __forceinline ~ControllerPtr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    ControllerPtr& operator=(const ControllerPtr& other);
};
struct ControllerList
{
    ControllerPtr item;
    ControllerList* next;
    ~ControllerList();
    void RemoveNode(const ControllerPtr& key);
};
void ControllerList::RemoveNode(const ControllerPtr& key)
{
    if (!key.m_pObject)
        return;
    if (!next && !item.m_pObject)
        return;
    ControllerList* prev = this;
    ControllerList* cur = this;
    while (cur->item.m_pObject != key.m_pObject)
    {
        prev = cur;
        cur = cur->next;
        if (!cur)
            return;
    }
    if (cur == this)
    {
        ControllerList* pNext = next;
        if (pNext)
        {
            next = pNext->next;
            item = pNext->item;
            pNext->next = 0;
            pNext->~ControllerList();
            _g_memoryManager.Deallocate(pNext);
        }
        else if (item.m_pObject)
        {
            item.m_pObject->DecRefCount();
            item.m_pObject = 0;
        }
    }
    else
    {
        prev->next = cur->next;
        cur->next = 0;
        cur->~ControllerList();
        _g_memoryManager.Deallocate(cur);
    }
}
struct ControllerCollection
{
    unsigned int unk, unk04, unk08, unk0C, unk10;
    ControllerList head;
};
struct ControllerExtra
{
    unsigned int unk, unk04, unk08, unk0C;
    ControllerCollection* collection;
};
// Walks the node's controller collection, activating or removing controllers by type, then recurses into child nodes.
// @fnv 0x00c80700
void ProcessControllerList(WalkNode_cls* node)
{
    if (node)
    {
        if (node->m_1c)
        {
            ControllerExtra* extra = reinterpret_cast<ControllerExtra*>(
                reinterpret_cast<NiObject*>(node->m_1c)
                    ->DynamicCast(reinterpret_cast<const unsigned int*>(&g_012043f8)));
            if (extra && extra->collection)
            {
                ControllerList* entry = &extra->collection->head;
                while (entry && entry->item.m_pObject)
                {
                    IdleController* original = entry->item.m_pObject;
                    IdleController* controller =
                        original->IsKindOfType(reinterpret_cast<const ControllerRTTI*>(&g_0126818c)) ? original : 0;
                    if (controller)
                    {
                        switch (controller->GetObject()->GetType())
                        {
                        case 2:
                        case 7:
                        case 13:
                            if (!controller->link->active)
                            {
                                ControllerLink* link = controller->GetLink();
                                ControllerObject* object = link ? link->object : 0;
                                ControllerOwner* owner = object->GetOwner();
                                controller->HandleControllerData(owner ? owner->manager : 0);
                            }
                            if (controller->link->IsActive())
                                EnableConstraintsAndZeroArrays(controller->link, controller->link->active);
                            break;
                        case 8: {
                            ControllerLink* link = controller->GetLink();
                            ControllerObject* object = link ? link->object : 0;
                            if (object)
                            {
                                ControllerOwner* owner = object->GetOwner();
                                This5380d0* manager = owner ? owner->manager : 0;
                                manager->bhkWorld_RemoveBody(reinterpret_cast<Param5380d0*>(controller));
                            }
                            ControllerPtr spKey(controller);
                            entry->RemoveNode(spKey);
                        }
                        break;
                        }
                    }
                    entry = entry->next;
                }
            }
        }
        WalkNode_cls* children = node->v03();
        if (children)
        {
            for (unsigned int i = 0; i < children->m_a6; ++i)
                ProcessControllerList(children->m_a0[i]);
        }
    }
}

struct C817D0Node
{
    void UpdateWorldLoc();
};

struct C817D0RefNode
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_flags;
};

struct C817D0TlsBlock
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
    int m_2c0;
};

__declspec(thread) C817D0TlsBlock g_c817d0Tls;

struct C817D0Cls
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
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfA0();
    virtual void vfA4();

    unsigned int unk04;
    C817D0Node* m_08;
    unsigned short m_0c;
    unsigned short unk0e;
    C817D0RefNode* m_10;
    unsigned char m_14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    float m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;

    void UpdateNodeState(int);
    void bhkCollisionObject_NitohkTransform();
};

// @fnv 0x00c817d0
void C817D0Cls::UpdateNodeState(int)
{
    int state = g_c817d0Tls.m_2c0;
    if (state == 3)
        return;
    if (m_14 != 0)
    {
        if (m_08 != 0)
            m_08->UpdateWorldLoc();
        m_14 = 0;
        return;
    }
    C817D0RefNode* pRefNode = m_10;
    if (pRefNode == 0 || (bool)((pRefNode->m_flags >> 6) & 1) == 0)
    {
        if ((bool)((m_0c >> 6) & 1) != 0)
        {
            if (state != 2)
            {
                bhkCollisionObject_NitohkTransform();
                m_0c = (unsigned short)(m_0c & 0xffbf);
                return;
            }
        }
        else if ((bool)(m_0c & 1) != 0)
        {
            if (pRefNode != 0 || m_18 < 1.0f || m_20 == 1)
                vfA4();
            return;
        }
    }
    if (m_08 != 0)
        m_08->UpdateWorldLoc();
}

void __cdecl bhkSerializable_LinkObject(int* param_1, unsigned int param_2);

// @fnv 0x00c84cc0
// src: XBOX_PDB 0x00c84cc0
void __cdecl bhkShape_LinkObject(int* param_1, unsigned int param_2)
{
    bhkSerializable_LinkObject(param_1, param_2);
}

// Fallout: New Vegas — FUN_00c85620
// __cdecl aligned-allocation helper: requests an over-sized block from the
// heap object's virtual allocator, aligns the returned pointer up to the
// requested alignment, and stores a small header immediately below the
// aligned pointer: {owner, end, offset-to-raw}.

struct FUN_00c85620_heap
{
    virtual void v0();
    virtual void* Allocate(unsigned int uiSize);
};

// @fnv 0x00c85620
// src: HAVOK_LIB 0x00c85620
void* __cdecl hkMemoryRouter_alignedAlloc(FUN_00c85620_heap* pkHeap, unsigned int uiSize, unsigned int uiAlignment)
{
    unsigned int uiEnd = uiSize + uiAlignment;
    void* pvRaw = pkHeap->Allocate(uiEnd + 0x10);

    unsigned int uiAligned = (unsigned int)pvRaw + uiAlignment + 0xf;
    uiAligned &= ~(uiAlignment - 1);

    unsigned int* puiBlock = (unsigned int*)uiAligned;
    puiBlock[-3] = uiEnd;
    puiBlock[-4] = (unsigned int)pkHeap;
    puiBlock[-2] = uiAligned - (unsigned int)pvRaw;

    return (void*)uiAligned;
}

struct FUN_00ba87d0_holder
{
    bool BSAnimNotes_IsEqual();
};
// @fnv 0x00c85800
// src: XBOX_PDB 0x00c85800
void __cdecl bhkCharacterProxy_IsEqual()
{
    extern void __cdecl BSAnimNotes_IsEqual();
    BSAnimNotes_IsEqual();
}

struct FUN_00c87a40_ref
{
    void* unk00;
    void* unk04;
    void* unk08;
};

struct FUN_00c87a40_obj
{
    void* unk00;
    void* unk04;
    FUN_00c87a40_ref* unk08;

    void* __thiscall bhkWorldObject_GethkWorld();
};

// @fnv 0x00c87a40
// src: XBOX_PDB 0x00c87a40
void* __thiscall FUN_00c87a40_obj::bhkWorldObject_GethkWorld()
{
    if (unk08 != 0)
        return unk08->unk08;
    return 0;
}

extern void __cdecl FUN_00a5d3a0();
extern int DAT_010c5b54;
struct FUN_00c87c30_t
{
    int* pVTable;
    int unk04;
    int unk08;
    FUN_00c87c30_t* UpdateState_00c87c30();
};
// @fnv 0x00c87c30
// src: GUESS 0x00c87c30 (confidence: low)
FUN_00c87c30_t* FUN_00c87c30_t::UpdateState_00c87c30()
{
    FUN_00a5d3a0();
    pVTable = &DAT_010c5b54;
    unk08 = 0;
    return this;
}

struct FUN_00c87c50_cls
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
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
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
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot36(bool b);
    int unk04;
    NiObject* unk08;
    void bhkRefObject_SethkObject(NiObject* arg);
};
// @fnv 0x00c87c50
// src: XBOX_PDB 0x00c87c50
void FUN_00c87c50_cls::bhkRefObject_SethkObject(NiObject* apObject)
{
    if (unk08 != apObject)
    {
        slot36(false);
        unk08 = apObject;
        slot36(true);
    }
}

extern int DAT_01268160;

// @fnv 0x00c87c80
// src: COMMUNITY 0x00c87c80
int* __cdecl bhkRefObject_GetRTTI()
{
    return &DAT_01268160;
}

extern __declspec(thread) int DAT_tls_field;
struct MemoryContextGuard
{
    int previous;
    MemoryContextGuard() : previous(DAT_tls_field)
    {
        DAT_tls_field = 16;
    }
    ~MemoryContextGuard()
    {
        DAT_tls_field = previous;
    }
};
struct FUN_00c905b0_Class
{
    void FUN_00c905b0();
};
struct FUN_00a5d3d0
{
    virtual ~FUN_00a5d3d0();
};
struct FUN_00c87d20 : FUN_00a5d3d0
{
    int m_field04;
    FUN_00c905b0_Class* m_ref;
    virtual ~FUN_00c87d20();
};
// Destructor that enters a memory context and, if m_ref is set, calls FUN_00c905b0 on it.
// @fnv 0x00c87d20
FUN_00c87d20::~FUN_00c87d20()
{
    MemoryContextGuard guard;
    if (m_ref)
        m_ref->FUN_00c905b0();
}

struct FUN_00c87dc0_class
{
    void __thiscall FUN_00c87d20();
    unsigned int __thiscall FUN_00c87dc0(unsigned char param_2);
};

extern "C" void __cdecl operator delete(void*, unsigned int);

// Calls FUN_00c87d20, then deletes this (0xC bytes) when bit 0 of param_2 is set, and returns this as an unsigned int.
// @fnv 0x00c87dc0
unsigned int __thiscall FUN_00c87dc0_class::FUN_00c87dc0(unsigned char param_2)
{
    FUN_00c87d20();
    if ((param_2 & 1) != 0)
    {
        ::operator delete(this, 0xC);
    }
    return reinterpret_cast<unsigned int>(this);
}

namespace fnv_00c87de0 {
extern const char* DAT_01268160;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString_00a7d4d0(const char*, int);

// @fnv 0x00c87de0
extern "C" void AppendBhkRefBaseStrings();
void __fastcall AddBhkRefObjectDebugStrings(bhkRefObject* self, void*, ViewerStrings* pkStrings)
{
    MemContextScope kScope(16);

    ((void(__thiscall*)(bhkRefObject*, StrArr*))&AppendBhkRefBaseStrings)(self, (StrArr*)pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(DAT_01268160));

    char acBuffer[32];
    sprintf_s(acBuffer, 32, "0x%08X", (unsigned int)self->m_pHavokObject);
    pkStrings->Add(NiGetViewerString_00a7d5e0("hkObject", acBuffer));

    if (self->m_pHavokObject)
    {
        pkStrings->Add(NiGetViewerString_00a7d4d0("hkRefcount", self->m_pHavokObject->m_sReferenceCount));
    }
}
}  // namespace fnv_00c87de0

void __cdecl DispatchToTarget();
// @fnv 0x00c87fa0
// src: XBOX_PDB 0x00c87fa0
void __cdecl bhkCollisionObject_RegisterStreamables()
{
    DispatchToTarget();
}

void bhkNiCollisionObject_IsEqual();

// @fnv 0x00c87fb0
// src: XBOX_PDB 0x00c87fb0
void bhkCollisionObject_IsEqual()
{
    bhkNiCollisionObject_IsEqual();
}

extern int DAT_010c5dc0;

struct FUN_00c88430_t
{
    int* m_p0;
    int m_i4;
    int m_i8;
    int m_ic;
    int m_i10;
    FUN_00c88430_t();
};

// @fnv 0x00c88430
FUN_00c88430_t::FUN_00c88430_t()
{
    m_i4 = 0;
    m_i8 = 1;
    m_ic = 0;
    m_i10 = 0;
    m_p0 = &DAT_010c5dc0;
}

extern int DAT_01267b70;
struct Flagged_c891
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
    int flag30;
};
struct Facade_c891
{
    int unk00;
    int unk04;
    Flagged_c891* value08;
};
struct Result_c891
{
    Facade_c891* facade00;
    int unk04;
};
struct Elem_c891
{
    int unk00;
    int unk04;
    Elem_c891* unk08;
    Elem_c891* getE() const
    {
        return unk08;
    }
};
struct Holder_c891
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Elem_c891* elem10;
};
struct Heap_c891
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int bytes);
};
Holder_c891* __cdecl bhkUtilFunctions_FindNextCollisionObject(int);
struct Arr_c891
{
    Elem_c891** m_data;
    int m_iElementCount;
    int m_cap;
    Arr_c891() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
    Elem_c891*& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    ~Arr_c891()
    {
        hkMemoryRouter* r = hkMemoryRouter_getInstance();
        Heap_c891* heap = (Heap_c891*)r->m_heap;
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0)
            heap->ReturnMemory(m_data, (m_cap & 0x3fffffff) * 4);
    }
};
void __cdecl CollectTreeResultValues(int, Arr_c891*);
Result_c891* __cdecl bhkWorldObject_GetProperty(Result_c891*, Elem_c891*, int*);
struct Cls_c891
{
    int unk00;
    int unk04;
    int m_08;
    void WeaponObject_UpdateChildRB3D();
};
// @fnv 0x00c891c0
// src: XBOX_PDB 0x00c891c0
void Cls_c891::WeaponObject_UpdateChildRB3D()
{
    int obj = m_08;
    if (obj != 0)
    {
        Holder_c891* holder = bhkUtilFunctions_FindNextCollisionObject(obj);
        Elem_c891* target = holder ? holder->elem10 : 0;
        Arr_c891 arr;
        CollectTreeResultValues(obj, &arr);
        for (int i = 0; i < arr.GetLogicalSize(); i++)
        {
            if (!target)
                break;
            Elem_c891* t = target->unk08;
            if (arr[i] != t && arr[i]->unk08 == 0)
            {
                Elem_c891* e = arr[i];
                Result_c891 res;
                Facade_c891* f = bhkWorldObject_GetProperty(&res, e, &DAT_01267b70)->facade00;
                f->value08->flag30 |= 1;
            }
        }
    }
}

extern void FUN_00c87650();

// @fnv 0x00c896b0
// src: XBOX_PDB 0x00c896b0
void bhkConstraint_LoadBinary()
{
    FUN_00c87650();
}

struct FnvCpu_FUN_00c89720_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void Invoke();
    void bhkCharacterProxy_MarkRead();
};
// @fnv 0x00c89720
// src: XBOX_PDB 0x00c89720
void FnvCpu_FUN_00c89720_CpuInterface::bhkCharacterProxy_MarkRead()
{
    Invoke();
}

struct AttachObject;
struct AttachData;
struct AttachObject
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
    virtual AttachData* GetData();
    virtual void v38();
    virtual void Add(AttachObject*);
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
    virtual void Set(AttachObject*);
    virtual AttachObject* GetTarget();
    virtual AttachData* GetConstraint();
    int unk04;
    AttachData* owner;
    int unk0c;
    unsigned int flags;
    int unk14;
    unsigned int count;
    int unk1c;
    int unk20;
    AttachData* data24;
    int unk28;
    unsigned int id;
    void Object_DoNothing();
    bool AddOrRemoveConstraint(AttachObject* body, bool add);
};
struct AttachData
{
    unsigned char HasObjectOfType()
    {
        return object08 != 0;
    }
    int unk00;
    int unk04;
    AttachObject* object08;
    AttachObject* object0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    AttachObject* object24;
    int unk28;
    unsigned int id;
};
struct DiagFlag
{
    bool enabled;
    DiagFlag(bool value) : enabled(value)
    {}
    DiagFlag(const DiagFlag& other) : enabled(other.enabled)
    {}
};
struct DiagString
{
    int a, b, c;
    DiagString(char*, unsigned int, DiagFlag);
    void Append(const char*);
    ~DiagString();
};
struct DiagSink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Report(int, unsigned int, char*, const char*, int);
};
extern DiagSink* diagnosticSink;
// Adds or removes a constraint body on the target, fixing the constraint id and reporting when the target bodies are not yet in the world.
// @fnv 0x00c89f90
bool AttachObject::AddOrRemoveConstraint(AttachObject* body, bool add)
{
    MemContextScope scope(16);
    bool result = false;
    AttachData* constraint = GetConstraint();
    if (add)
    {
        if (constraint && constraint->object0c)
        {
            AttachObject* target = constraint->object0c;
            AttachData* owner = target->owner;
            bool present = false;
            if (owner)
            {
                target->Object_DoNothing();
                unsigned char b = owner->object08 != 0;
                present = b ? true : false;
                target->Object_DoNothing();
            }
            if (!present)
            {
                unsigned int t = GetTarget()->id;
                constraint->id = (t & 0xffff0000) | (unsigned short)constraint->id;
            }
            if (body->count <= 0)
            {
                target->Add(body);
                if (!target->GetData() && !(target->flags & 0x30))
                {
                    {
                        char buffer[512];
                        DiagString diagText(buffer, 512, DiagFlag(true));
                        diagText.Append(
                            "A Constraint is being added to the world before its target bodies have been added. Did an bad actor skeleton just switch from keyframed?\n");
                        diagnosticSink->Report(1, 0x234f24fc, buffer,
                                               "D:\\_Fallout3\\Platforms\\Common\\Code\\BSHavok\\bhkConstraint.cpp",
                                               749);
                    }
                    target->Set(body);
                }
            }
        }
        else
        {
            *(volatile bool*)&result = true;
            AttachData* data = body->GetData();
            AttachObject* object = 0;
            if (data)
                object = data->object24;
            Set(object);
        }
    }
    else
    {
        AttachData* data = body->GetData();
        AttachObject* object = 0;
        if (data)
            object = data->object24;
        if (constraint == (AttachData*)object)
            Set(0);
    }
    return result;
}

struct Alloc8b_c8b090
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int size);
    virtual void ReleaseBlock(void* p, int size);
};

struct hkThreadLocals_c8b090
{
    int value;
};
extern __declspec(thread) int g_hkTlsScopeValue;

struct TlsScope_c8b090
{
    int m_old;
    TlsScope_c8b090(int v)
    {
        m_old = g_hkTlsScopeValue;
        g_hkTlsScopeValue = v;
    }
    ~TlsScope_c8b090()
    {
        g_hkTlsScopeValue = m_old;
    }
};

struct hkRefObj_c8b090
{
    virtual void vf0();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    static void* operator new(unsigned int size)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        Alloc8b_c8b090* alloc = (Alloc8b_c8b090*)holder->m_heap;
        hkRefObj_c8b090* b = (hkRefObj_c8b090*)alloc->AllocateMemoryBlock(static_cast<int>(size));
        b->m_usMemSizeAndFlags = (unsigned short)size;
        return b;
    }
    static void operator delete(void* p, unsigned int size)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        Alloc8b_c8b090* alloc = (Alloc8b_c8b090*)holder->m_heap;
        alloc->ReleaseBlock(p, static_cast<int>(size));
    }
    void removeReference();
};

struct hkShapeContainer_c8b090
{
    virtual void v0();
    virtual int GetNumChildShapes();
    virtual int GetFirstKey();
    virtual int GetNextShapeKey(int key);
};

struct hkShape_c8b090
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct hkShapeBase_c8b090 : hkRefObj_c8b090
{
    int unk08;
    int unk0c;
};

struct hkListShape_c8b090 : hkShapeBase_c8b090, hkShapeContainer_c8b090
{
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
    hkListShape_c8b090(void* shapes, unsigned int count, int policy);
    void setChild(int key, int value);
};

struct ListInfo_c8b090
{
    int unk00;
    void* m_shapes;
    unsigned int m_numShapes;
    int unk0c;
    int* m_iSlotIds;
    unsigned int m_uiArrayCount;
};

struct bhkListOwner_c8b090
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
    virtual void SetShape(hkListShape_c8b090* shape);
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
    virtual void SetListInfo(ListInfo_c8b090* info);
    void SetListShape(ListInfo_c8b090* info);
};

// @fnv 0x00c8b090
void bhkListOwner_c8b090::SetListShape(ListInfo_c8b090* info)
{
    TlsScope_c8b090 scope(0x10);
    void* shapes = info->m_shapes;
    unsigned int count = info->m_numShapes;
    hkListShape_c8b090* shape = new hkListShape_c8b090(shapes, count, 1);
    int key = shape->GetFirstKey();
    if (!(count < info->m_uiArrayCount))
        count = info->m_uiArrayCount;
    for (unsigned int i = 0; i < count; i++)
    {
        shape->setChild(key, info->m_iSlotIds[i]);
        shape->GetNextShapeKey(key);
    }
    SetShape(shape);
    shape->removeReference();
    SetListInfo(info);
}

struct C8B540Selected;

class C8B540Wrapper
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual C8B540Selected* Select();
};

class C8B540Selected
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual int GetResult(int iArg);
};

struct C8B540Group : C8B4D0Group
{
    int unk0C;
    int m_iFallback;

    int GetSelectedResult(int iArg);
};

// Iterates children, calls Select on each child's wrapper and returns the first non-0x24 GetResult result, else m_iFallback masked with 0x1f.
// @fnv 0x00c8b540
int C8B540Group::GetSelectedResult(int iArg)
{
    int result = 0x24;
    unsigned int count = GetChildCount();
    for (unsigned int i = 0; i < count; i++)
    {
        if (result != 0x24)
            break;

        C8B4D0Child* pkChild = GetChild(i);
        C8B540Wrapper* pkWrapper = pkChild ? (C8B540Wrapper*)pkChild->m_pkWrapper : 0;
        C8B540Selected* pkSelected = pkWrapper->Select();
        if (pkSelected)
            result = pkSelected->GetResult(iArg);
    }

    if (result == 0x24)
        result = m_iFallback & 0x1f;

    return result;
}

extern int DAT_012681cc;

// @fnv 0x00c8ff70
// src: COMMUNITY 0x00c8ff70
int __cdecl bhkBlendCollisionObjectAddRotation_GetRTTI()
{
    return reinterpret_cast<int>(&DAT_012681cc);
}

void __cdecl bhkBlendCollisionObject_LoadBinary(int, int);

// @fnv 0x00c8ff80
// src: XBOX_PDB 0x00c8ff80
void __cdecl bhkBlendCollisionObjectAddRotation_LoadBinary(int param_1, int param_2)
{
    bhkBlendCollisionObject_LoadBinary(param_1, param_2);
}

struct FUN_00c819a0_holder
{
    static void InitFromFlags();
};

// @fnv 0x00c8ff90
// src: XBOX_PDB 0x00c8ff90
void __cdecl bhkBlendCollisionObjectAddRotation_LinkObject()
{
    FUN_00c819a0_holder::InitFromFlags();
}

extern "C" void __cdecl bhkBlendCollisionObject_RegisterStreamables();

// @fnv 0x00c8ffa0
// src: XBOX_PDB 0x00c8ffa0
void __cdecl bhkBlendCollisionObjectAddRotation_RegisterStreamables()
{
    bhkBlendCollisionObject_RegisterStreamables();
}

extern void __cdecl bhkBlendCollisionObject_SaveBinary();

// @fnv 0x00c8ffb0
// src: XBOX_PDB 0x00c8ffb0
void __cdecl bhkBlendCollisionObjectAddRotation_SaveBinary()
{
    bhkBlendCollisionObject_SaveBinary();
}

bool __cdecl bhkBlendCollisionObject_IsEqual(C815B0Constraint* pkOther);

// @fnv 0x00c8ffc0
// src: XBOX_PDB 0x00c8ffc0
bool __cdecl bhkBlendCollisionObjectAddRotation_IsEqual(C815B0Constraint* pkOther)
{
    return bhkBlendCollisionObject_IsEqual(pkOther);
}

struct C90160Matrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};
extern const C90160Matrix DAT_011a9448;

class C90160Derived : public BC88760Base
{
  public:
    C90160Matrix matrix;
    C90160Derived() : matrix(DAT_011a9448)
    {}
    virtual ~C90160Derived();

    void bhkBlendCollisionObject_CopyMembers(C90160Derived* destination, BC88760CloningProcess& cloning);
    C90160Derived* bhkBlendCollisionObjectAddRotation_CreateClone(BC88760CloningProcess& cloning);
};

// @fnv 0x00c90160
// src: XBOX_PDB 0x00c90160
C90160Derived* C90160Derived::bhkBlendCollisionObjectAddRotation_CreateClone(BC88760CloningProcess& cloning)
{
    BC88760AllocTagScope allocationCategory(16);
    C90160Derived* destination = new C90160Derived;
    bhkBlendCollisionObject_CopyMembers(destination, cloning);
    destination->matrix = matrix;
    return destination;
}

// @fnv 0x00c90330
// src: COMMUNITY 0x00c90330
void __cdecl nullsub_92()
{}

// @fnv 0x00c90340
// src: COMMUNITY 0x00c90340
void __cdecl nullsub_93()
{}

// 0x00c90350  xor eax,eax; ret
// @fnv 0x00c90350
// src: COMMUNITY 0x00c90350
int __cdecl retn_0_()
{
    return 0;
}

extern "C" int DAT_01268748;
extern "C" const char* __cdecl hkStatisticsCollectorUtil_hasContents(void** value, void* object);
extern "C" void __cdecl hkStatisticsCollectorUtil_addClassContentsAll(void* owner, void* object, void* context);
struct FunctionContext
{
    void __thiscall hkReferencedObject_calcContentStatistics(void* context, void* object);
};
// @fnv 0x00c90360
// src: HAVOK_LIB 0x00c90360
void __thiscall FunctionContext::hkReferencedObject_calcContentStatistics(void* context, void* object)
{
    void* const cachedObject = object;
    if (cachedObject != 0 && cachedObject != &DAT_01268748)
    {
        void* pointer;
        if (*hkStatisticsCollectorUtil_hasContents(&pointer, cachedObject))
        {
            hkStatisticsCollectorUtil_addClassContentsAll(this, cachedObject, context);
        }
    }
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection);
extern int DAT_0102e388;

struct FUN_00c90880_Srv
{
    virtual void m_00();
    virtual void m_04();
    virtual void m_08(void* p, unsigned short w);
};

struct FUN_00c90880_Class
{
    void* m_00;
    unsigned short m_04;

    void* FUN_00c90880(unsigned int flags);
};

// @fnv 0x00c90880
void* FUN_00c90880_Class::FUN_00c90880(unsigned int flags)
{
    DeleteCriticalSection((char*)this + 0x18);
    m_00 = &DAT_0102e388;
    if (flags & 1)
    {
        void* holder = hkMemoryRouter_getInstance();
        FUN_00c90880_Srv* pService = *(FUN_00c90880_Srv**)((char*)holder + 0x10);
        pService->m_08(this, m_04);
    }
    return this;
}

// @fnv 0x00c90e30
// src: GUESS 0x00c90e30 (confidence: high)
int __stdcall Runtime_ReturnZero_00c90e30(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8)
{
    return 0;
}

struct FUN_00c92b00_Entry
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    int value48;
    int value4c;
};

struct FUN_00c92b00_Class
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24;
    FUN_00c92b00_Entry** entries28;
    int count2c;
    int unk30;
    FUN_00c92b00_Entry** entries34;
    int count38;

    void hkpWorld_findInitialContactPoints(int first, int second);
    void ApplyEntries();
};

// Calls FUN_00c92a80 with value48 and value4c for every entry in entries28 (count2c) and entries34 (count38).
// @fnv 0x00c92b00
void FUN_00c92b00_Class::ApplyEntries()
{
    for (int i = 0; i < count2c; ++i)
    {
        FUN_00c92b00_Entry* entry = entries28[i];
        hkpWorld_findInitialContactPoints(entry->value48, entry->value4c);
    }
    for (int i = 0; i < count38; ++i)
    {
        FUN_00c92b00_Entry* entry = entries34[i];
        hkpWorld_findInitialContactPoints(entry->value48, entry->value4c);
    }
}

struct FUN_00c9a620_Obj
{
    float unk00;
    float unk04;
    float unk08;

    int __thiscall BLENDKEY_IsEqual(float* other);
};

// Returns 1 if the three floats at unk00, unk04 and unk08 all equal the corresponding elements of other, otherwise 0.
// @fnv 0x00c9a620
// src: COMMUNITY 0x00c9a620
int __thiscall FUN_00c9a620_Obj::BLENDKEY_IsEqual(float* other)
{
    if (unk00 == other[0] && unk04 == other[1] && unk08 == other[2])
    {
        return 1;
    }
    return 0;
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
void hkBaseSystem_quitThread();
struct ArenaReleaseAllocator : ArenaAllocator
{
    virtual void Deallocate(void* p, unsigned int bytes);
};
struct ArenaRegistryRelease
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Release(TemporaryArena* arena, ArenaRegistrationFlag flag);
};
struct ArenaManagedOwner
{
    TemporaryArena* arena;
    void* buffer;
    unsigned long threadId;
};
// Frees the owner's buffer from its temporary arena, resets the arena state, and releases the arena registration under a critical section.
// @fnv 0x00c80240
// src: XBOX_PDB 0x00c80240
void DoThreadShutdown(ArenaManagedOwner* owner)
{
    if (owner->arena)
    {
        ArenaEnterCriticalSection(&DAT_01267e48);
        TemporaryArena* arena = owner->arena;
        ArenaReleaseAllocator* allocator = static_cast<ArenaReleaseAllocator*>(arena->allocator);
        allocator->Deallocate(owner->buffer, 0x5000);
        owner->buffer = 0;
        if (GetCurrentThreadId() == owner->threadId)
            hkBaseSystem_quitThread();
        ArenaRegistryRelease* registry = (ArenaRegistryRelease*)hkMemorySystem_getInstance();
        registry->Release(arena, ArenaRegistrationFlag());
        arena->cursor = 0;
        arena->start = 0;
        arena->end = 0;
        owner->arena = 0;
        ArenaLeaveCriticalSection(&DAT_01267e48);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);



extern MemoryManager g_kMemoryManager0AA0;

class ListNode0AA0
{
  public:
    static void* operator new(unsigned int uiSize) throw()
    {
        return g_kMemoryManager0AA0.Allocate(uiSize);
    }
    ListNode0AA0(const NiPointer<NiRefObject>& spRetainedObject) : m_pReferencedObject(spRetainedObject)
    {
        m_pkNext = 0;
    }
    void AppendRetainedObject(const NiPointer<NiRefObject>& spRetainedObject);

    NiPointer<NiRefObject> m_pReferencedObject;
    ListNode0AA0* m_pkNext;
};

// Appends spRetainedObject to the tail of the linked list, reusing the last node's slot if it is empty.
// @fnv 0x00c80aa0
// src: GUESS 0x00c80aa0 (confidence: medium)
void ListNode0AA0::AppendRetainedObject(const NiPointer<NiRefObject>& spRetainedObject)
{
    if (!spRetainedObject)
        return;
    ListNode0AA0* pkNode = this;
    while (pkNode->m_pkNext)
        pkNode = pkNode->m_pkNext;
    if (pkNode->m_pReferencedObject)
        pkNode->m_pkNext = new ListNode0AA0(spRetainedObject);
    else
        pkNode->m_pReferencedObject = spRetainedObject;
}

class FUN_00c819f0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_18;
    unsigned int m_1c;
    void Callee65820(int a1);
    void bhkBlendCollisionObject_SaveBinary(int a1);
};

// Calls Callee65820, then twice calls the m_0c callback of the stream at a1+0x250 on m_18 and m_1c (4 bytes each), adding each result to the stream's m_04.
// @fnv 0x00c819f0
// src: XBOX_PDB 0x00c819f0
void FUN_00c819f0_cls::bhkBlendCollisionObject_SaveBinary(int a1)
{
    char* obj = (char*)a1;
    NiBinaryStream* __restrict o;
    unsigned int(__cdecl * fn)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int* cnt = (unsigned int*)&a1;
    Callee65820(a1);
    o = *(NiBinaryStream**)(obj + 0x250);

    *(unsigned int*)((char*)o + 4) += (*(NiBinaryStream::WriteFunction*)((char*)o + 12))((a1 = 4, o), &m_18, 4, cnt, 1);
    o = *(NiBinaryStream**)(obj + 0x250);

    *(unsigned int*)((char*)o + 4) += (*(NiBinaryStream::WriteFunction*)((char*)o + 12))((a1 = 4, o), &m_1c, 4, cnt, 1);
}

struct MeshMemoryScope
{
    int saved;
    MeshMemoryScope()
    {
        saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 16;
    }
    ~MeshMemoryScope()
    {
        g_tlsBlock.m_2b4 = saved;
    }
};
inline void* __cdecl operator new[](unsigned int size)
{
    return DAT_011f6238.Allocate(size);
}
struct FourFloatComponents
{
    float unk00, unk04, unk08, unk0c;
};
struct SourceTriangle
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct SourceMesh
{
    FourFloatComponents* unk00;
    unsigned int unk04;
    unsigned int unk08;
    SourceTriangle* unk0c;
    unsigned int unk10;
};
void __cdecl FUN_00458620(NiPoint3*, const FourFloatComponents*);
// The shared NiGeometryData header does not yet declare this normals helper.
struct GeometryData
{
    void EnsureNormals(bool);
};
void __cdecl AttachEmissiveMaterial(NiTriShape*, unsigned int, unsigned int, unsigned int);
struct MeshBuilder
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    void BuildTriShape(unsigned int unused, SourceMesh* mesh, unsigned int arg2, const char* name);
};
// Copies SourceMesh vertex and triangle data into a new NiTriShape, sets its name, ensures normals, and attaches an emissive material.
// @fnv 0x00c84fa0
void MeshBuilder::BuildTriShape(unsigned int unused, SourceMesh* mesh, unsigned int arg2, const char* name)
{
    MeshMemoryScope scope;
    if (mesh)
    {
        unsigned int vertexCount = mesh->unk04;
        unsigned int triangleCount = mesh->unk10;
        if (vertexCount && triangleCount)
        {
            NiPoint3* vertices = new NiPoint3[vertexCount];
            unsigned short* indices = new unsigned short[triangleCount * 3];
            for (unsigned int i = 0; i < vertexCount; ++i)
                FUN_00458620(&vertices[i], &mesh->unk00[i]);
            for (unsigned int j = 0; j < triangleCount; ++j)
            {
                SourceTriangle triangle = mesh->unk0c[j];
                indices[j * 3] = (unsigned short)triangle.unk00;
                indices[j * 3 + 1] = (unsigned short)triangle.unk04;
                indices[j * 3 + 2] = (unsigned short)triangle.unk08;
            }
            NiTriShape* shape = new NiTriShape((unsigned short)vertexCount, vertices, 0, (void*)0, (void*)0, 0, 0,
                                               (unsigned short)triangleCount, indices);
            if (name)
                shape->SetName(NiFixedString(name));
            reinterpret_cast<GeometryData*>(shape->m_spModelData.m_pObject)->EnsureNormals(true);
            AttachEmissiveMaterial(shape, unused, unk10 & 31, arg2);
        }
    }
}

struct PropertyKey
{
    unsigned int first, second;
};
extern PropertyKey DAT_011f4280;
struct PropertyValue
{
    int value;
    unsigned int extra;
};
struct PropertyEntry
{
    void* key;
    unsigned int flags;
    PropertyValue data;
};
struct PropertyStore
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    PropertyEntry* entries;
    int count;
    PropertyValue FindEntry(void* key, int flags);
};
struct PropertyOwner
{
    unsigned int unknown00, unknown04;
    PropertyStore* store;
    int ReadProperty(void* key);
    int bhkWorldObject_GetAVObject(void* key);
};
__forceinline int PropertyOwner::ReadProperty(void* key)
{
    PropertyStore* object = store;
    int result = 0;
    if (object)
        result = object->FindEntry(key, 0).value;
    return result;
}
// Defaults key to DAT_011f4280 if null; if a store entry has that key, returns ReadProperty(key), otherwise 0.
// @fnv 0x00c85c80
// src: XBOX_PDB 0x00c85c80
int PropertyOwner::bhkWorldObject_GetAVObject(void* key)
{
    int result = 0;
    if (!key)
        key = &DAT_011f4280;
    PropertyStore* object = store;
    if (object)
    {
        int count = object->count;
        int i = 0;
        if (count > 0)
        {
            PropertyEntry* current = object->entries;
            do
            {
                if (current->key == key)
                {
                    result = ReadProperty(key);
                    break;
                }
                ++i;
                ++current;
            } while (i < count);
        }
    }
    return result;
}

struct ObjectController
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
    virtual void* v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();

    void* unk04;
    void* m_pObject;
    void SetObject(void* replacement);
    void bhkRefObject_SethkObject(void* replacement);
};

// If replacement differs from m_pObject, calls v28() when v25()'s state has a nonzero field at 0x350, then calls FUN_00c87c50(replacement).
// @fnv 0x00c87760
void ObjectController::SetObject(void* replacement)
{
    void* current = this ? m_pObject : 0;
    if (replacement != current)
    {
        if (current)
        {
            void* state = v25();
            if (state && *reinterpret_cast<int*>(static_cast<char*>(state) + 0x350))
                v28();
        }
        bhkRefObject_SethkObject(replacement);
    }
}

struct FUN_00c87a50_t
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* bhkWorldObject_GethkWorldRw();
};

// @fnv 0x00c87a50
// src: XBOX_PDB 0x00c87a50
void* FUN_00c87a50_t::bhkWorldObject_GethkWorldRw()
{
    if (this && unk08)
    {
        return *(void**)((char*)unk08 + 8);
    }
    return 0;
}

struct C87c90HkRef
{
    void FUN_00c90510();
};

// Releases the reference held in unk08, calling FUN_00c90510 when b is true or removeReference when false.
// @fnv 0x00c87c90
void FUN_00c899d0_Class::ReleaseReference(bool b)
{
    TlsGuard_t guard;
    if (unk08)
    {
        if (b)
        {
            ((C87c90HkRef*)unk08)->FUN_00c90510();
        }
        else
        {
            ((hkReferencedObject*)unk08)->removeReference();
        }
    }
}

struct Mat364
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

    bool _Call_4d9ae0(const Mat364& other) const;
};

extern unsigned char DAT_011f426c;
extern unsigned char DAT_011f4270;
extern unsigned char DAT_011f4274;

struct Target_00c88450
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
    Mat364 unk34;
    NiPlane unk58;
};

struct Cinfo_00c88450
{
    int unk00;
    int unk04;
    Target_00c88450* unk08;

    void __thiscall UpdateNodeState(void* arg);
    void __thiscall WeaponObject_UpdateWorldData(void* arg);
};

// If unk08's plane equals DAT_011f426c or its matrix check against DAT_011a9448 fails, sets both to those values; then always calls UpdateNodeState(arg).
// @fnv 0x00c88450
// src: XBOX_PDB 0x00c88450
void __thiscall Cinfo_00c88450::WeaponObject_UpdateWorldData(void* arg)
{
    Target_00c88450* target = unk08;

    if (target != 0)
    {
        NiPlane* plane = &target->unk58;

        if (*plane == *reinterpret_cast<NiPlane const*>(&DAT_011f426c) ||
            !target->unk34._Call_4d9ae0(*reinterpret_cast<Mat364 const*>(&DAT_011a9448)))
        {
            target->unk34 = *reinterpret_cast<Mat364 const*>(&DAT_011a9448);
            *reinterpret_cast<int*>(&plane->x) = *reinterpret_cast<int*>(&DAT_011f426c);
            *reinterpret_cast<int*>(&plane->y) = *reinterpret_cast<int*>(&DAT_011f4270);
            *reinterpret_cast<int*>(&plane->z) = *reinterpret_cast<int*>(&DAT_011f4274);
        }
    }

    UpdateNodeState(arg);
}

struct Process89730
{
    Map253* map;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScale;
};
struct Poly89730
{
    virtual void slot0();
    virtual void Scale(int iUnused, Process89730* pkProcess);
};
struct CloneCinfoSubobject
{
    int unk00;
};
// 0x00c89730 copies a scalable physics cinfo with two Havok body pointers at 0x0c/0x10; include/Data.h is non-polymorphic skill/category data.
struct CloneBodyPairCinfo : public Poly89730, public CloneCinfoSubobject
{
    int unk08;
    HavokObject253* m_pkFirst;
    HavokObject253* m_pkSecond;
};
struct Owner89730
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual CloneCinfoSubobject* GetData(bool* pbTemporary);
    void bhkSerializable_CopyMembers(void* pkDestination, Process89730* pkProcess);
    void bhkConstraint_CopyMembers(void* pkDestination, Process89730* pkProcess);
};

// Scales the data from GetData if pkProcess->m_fScale is not 1, re-links its two object pointers via the process map or Clone, then calls FUN_00c87600.
// @fnv 0x00c89730
// src: XBOX_PDB 0x00c89730
void Owner89730::bhkConstraint_CopyMembers(void* pkDestination, Process89730* pkProcess)
{
    bool bTemporary;
    CloneBodyPairCinfo* pkData = static_cast<CloneBodyPairCinfo*>(GetData(&bTemporary));
    if (pkProcess->m_fScale != 1.0f)
        pkData->Scale(0, pkProcess);
    Node253* pkFirstOwner = pkData->m_pkFirst ? pkData->m_pkFirst->owner : 0;
    Node253* pkSecondOwner = pkData->m_pkSecond ? pkData->m_pkSecond->owner : 0;
    pkData->m_pkFirst = 0;
    pkData->m_pkSecond = 0;
    if (pkFirstOwner)
    {
        void* pkClone;
        if (pkProcess->map->FUN_00a53c30(pkFirstOwner, pkClone))
            pkData->m_pkFirst = pkClone ? ((Node253*)pkClone)->object : 0;
        if (pkSecondOwner)
        {
            Node253* pkSecondClone;
            if (pkProcess->map->FUN_00a53c30(pkSecondOwner, pkClone))
                pkSecondClone = (Node253*)pkClone;
            else
                pkSecondClone = pkSecondOwner->Clone(pkProcess);
            pkData->m_pkSecond = pkSecondClone ? pkSecondClone->object : 0;
        }
    }
    bhkSerializable_CopyMembers(pkDestination, pkProcess);
}

struct FUN_00d53200_class
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    int unk04;
    int unk08;
    void hkConstraintCinfo_LoadBinary(NiStream& kStream);
};
// Calls FUN_00a64670 on kStream, calls vfn10, then calls ReadBinaryValue(&kStream, unk08).
// @fnv 0x00c8a230
// src: XBOX_PDB 0x00c8a230
void FUN_00d53200_class::hkConstraintCinfo_LoadBinary(NiStream& kStream)
{
    ((FileContext*)&kStream)->NiStream_ReadMultipleLinkIDs();
    vfn10();
    ReadBinaryValue(&kStream, unk08);
}

extern int DAT_01268194;

struct ActorBase
{
    virtual ~ActorBase();
};
struct FUN_00c8a720 : ActorBase
{
    virtual ~FUN_00c8a720();
    void bhkSerializable_Kill();
};
// @fnv 0x00c8a720
FUN_00c8a720::~FUN_00c8a720()
{
    bhkSerializable_Kill();
    --DAT_01268194;
}

class C8AAResult
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
};

class C8AASub
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    C8AAResult* m_18;
    C8AAResult* m_1c;
};

class C8AAHost
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    C8AASub* m_08;
    C8AAResult* GetA()
    {
        C8AAResult* r;
        if (this && m_08)
            r = m_08->m_18;
        else
            r = 0;
        return r;
    }
    C8AAResult* GetOther()
    {
        C8AAResult* r;
        if (this && m_08)
            r = m_08->m_1c;
        else
            r = 0;
        return r;
    }
    int GetResultValue(char c);
};

// Returns the m_0c field of the C8AAResult selected by c ('A'/'a' picks GetA, otherwise GetOther), or 0 if the result is null.
// @fnv 0x00c8aa00
int C8AAHost::GetResultValue(char c)
{
    C8AAResult* y;
    if (c == 'A' || c == 'a')
        y = GetA();
    else
        y = GetOther();
    return y ? y->m_0c : 0;
}

extern "C" void _ReadWriteBarrier(void);

struct FUN_00c8aa80_cls : BaseThunk
{
    int unk00;
    int unk04;
    Mid* m_08;
    void bhkBinaryAction_RegisterStreamables(NiStream* a);
};

// Looks up m_08->m_1c, calls v15(a) on its m_0c object if present, then calls FUN_00a81fe0 on the stream.
// @fnv 0x00c8aa80
// src: XBOX_PDB 0x00c8aa80
void FUN_00c8aa80_cls::bhkBinaryAction_RegisterStreamables(NiStream* apStream)
{
    Node1* node = this && m_08 ? m_08->m_1c : 0;
    _ReadWriteBarrier();
    if (node)
    {
        C_t* t = (C_t*)node->m_0c;
        if (t)
            t->v15(apStream);
    }
    BSTextureSet_RegisterStreamables(*apStream);
}

extern unsigned int DAT_010c6234;

struct Ffd0base
{
    void Initialize();
};

struct Arr9
{
    int v[9];
};

struct FUN_00c8ffd0
{
    void* m_vtbl;
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
    Arr9 tab;
    FUN_00c8ffd0();
};

// Initializes the base class, sets the vtable pointer, and copies a 9-element array from a global data location.
// @fnv 0x00c8ffd0
FUN_00c8ffd0::FUN_00c8ffd0()
{
    ((Ffd0base*)this)->Initialize();
    m_vtbl = &DAT_010c6234;
    tab = *(const Arr9*)&DAT_011a9448;
}

namespace fnv_00c90000 {
extern int DAT_010c6234;
void __cdecl FUN_00aa1460(void* object, unsigned int size);
struct FUN_00c90000_Object
{
    int* m_vftable;
    void __thiscall SetVtableAndProcessState_00c81550();
    FUN_00c90000_Object* __thiscall FUN_00c90000(unsigned int flags);
};
// Sets m_vftable to DAT_010c6234, calls FUN_00c81550, and if bit 0 of flags is set calls FUN_00aa1460(this, 0x50); returns this.
// @fnv 0x00c90000
FUN_00c90000_Object* FUN_00c90000_Object::FUN_00c90000(unsigned int flags)
{
    m_vftable = &DAT_010c6234;
    SetVtableAndProcessState_00c81550();
    if (flags & 1)
        FUN_00aa1460(this, 0x50);
    return this;
}
}  // namespace fnv_00c90000

// @fnv 0x00c910c0
// src: GUESS 0x00c910c0 (confidence: high)
void Object_DoNothing_00c910c0()
{}

// @fnv 0x00c911c0
// src: GUESS 0x00c911c0 (confidence: high)
bool Object_ReturnTrue()
{
    return true;
}

struct OperationPacket
{
    unsigned char operation;
    void* target;
    unsigned int value;
};
struct CommandTarget
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Receive(unsigned int value);
};
struct CommandDispatcher
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
    void hkpWorld_queueOperation(OperationPacket* packet);
    CommandTarget* DispatchCommand(CommandTarget* target, unsigned int value);
};
// If unk94 is set, builds an OperationPacket with operation 0x24 and calls FUN_00c91160; otherwise calls target->Receive(value) and returns target.
// @fnv 0x00c92a30
CommandTarget* CommandDispatcher::DispatchCommand(CommandTarget* target, unsigned int value)
{
    if (unk94)
    {
        OperationPacket packet;
        packet.operation = 0x24;
        packet.target = target;
        packet.value = value;
        hkpWorld_queueOperation(&packet);
    }
    else
    {
        target->Receive(value);
    }
    return target;
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection);

hkMemoryRouter* hkMemoryRouter_getInstance() throw();

struct C99F10Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiBytes) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiBytes) throw();
};

struct C99F10Array
{
    void** m_ppData;
    int m_uiLogicalSize;
    int m_iCapacity;
    ~C99F10Array() throw()
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        C99F10Allocator* pAlloc = (C99F10Allocator*)pHolder->m_heap;
        m_uiLogicalSize = 0;
        if (!(m_iCapacity & 0x80000000))
        {
            pAlloc->FreeArray(m_ppData, (m_iCapacity & 0x3fffffff) * 4);
        }
        m_ppData = 0;
        m_iCapacity = 0x80000000;
    }
};

struct C99F10Base
{
    virtual ~C99F10Base() throw()
    {}
    int unk04;
};

struct FUN_00c99f10 : C99F10Base
{
    C99F10Array m_kArray;
    void* m_pUserData;
    virtual ~FUN_00c99f10() throw();
};

// Deletes the critical section stored in m_pUserData and frees its 0x18-byte allocation via the spawned allocator.
// @fnv 0x00c99f10
FUN_00c99f10::~FUN_00c99f10() throw()
{
    void* pCS = m_pUserData;
    if (pCS)
    {
        DeleteCriticalSection(pCS);
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        C99F10Allocator* pAlloc = (C99F10Allocator*)pHolder->m_heap;
        pAlloc->Free(pCS, 0x18);
    }
}

struct FUN_00c9a520_shell
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
    virtual void* v9(void* pvArg);

    void bhkEntityListener_RemoveEntity(void* pvData);
    void bhkEntityListener_entityRemovedCallback(void* pvArg);
};

// @fnv 0x00c9a5e0
// src: XBOX_PDB 0x00c9a5e0
void FUN_00c9a520_shell::bhkEntityListener_entityRemovedCallback(void* pvArg)
{
    bhkEntityListener_RemoveEntity(v9(pvArg));
}

struct DispatchObject;
typedef int(__thiscall* DispatchAction)(DispatchObject*, void*);
struct DispatchObject
{
    void** vtable;
    void* unk04;
    DispatchObject* unk08;
    int type;
    int Dispatch(void* argument)
    {
        return reinterpret_cast<DispatchAction>(vtable[0x38])(this, argument);
    }
};
struct DispatchContainer
{
    void* unk00;
    void* argument;
    void* unk08;
    void* objectLink;
};
typedef void*(__thiscall* GetTarget)(DispatchObject*);
// Finds a target from container->objectLink (or container) by object type 8/10 via vtable slot 4, or type 9 via unk08; returns target->Dispatch(argument) or 0x24.
// @fnv 0x00c80020
// src: XBOX_PDB 0x00c80020
int __cdecl bhkUtilFunctions_GetMaterialValue(DispatchContainer* container)
{
    void* link = container->objectLink;
    if (!link)
        link = container;
    DispatchObject* target = 0;
    if (link)
    {
        DispatchObject* object = *reinterpret_cast<DispatchObject**>(link);
        int type = object->type;
        if (type == 8 || type == 10)
        {
            void* result = reinterpret_cast<GetTarget>(object->vtable[4])(object);
            if (result)
            {
                char* wrapper = static_cast<char*>(result) - 0x10;
                if (wrapper)
                    target = *reinterpret_cast<DispatchObject**>(wrapper + 8);
                else
                    target = 0;
            }
            else
                target = 0;
        }
        else
        {
            DispatchObject* checked = *reinterpret_cast<DispatchObject**>(link);
            if (checked && type == 9)
                target = checked->unk08;
        }
    }
    int result = 0x24;
    if (target)
        result = target->Dispatch(container->argument);
    return result;
}

// FUN_00c80090: cdecl, one pointer arg; probes nested object chain.
class ProbeX;
class ProbeY;
class ProbeZ;
class ProbeE;
class ProbeD;
class ProbeC;
class ProbeObj;

extern int DAT_012681c0;

ProbeE* __cdecl GetExtraDataChecked(ProbeObj* o);
struct PackedPropertyByte
{
    unsigned char value;
    PackedPropertyByte()
    {}
    inline bool operator!=(int rhs) const
    {
        return value != rhs;
    }
};
class ProbeZ
{
  public:
    PackedPropertyByte isActive_00c9bff0() const;
};

class ProbeX
{
  public:
    ProbeY* FUN_00653290(const void* type);
};

class ProbeY
{
  public:
    int unk00;
    int unk04;
    ProbeZ* m_08;
};

struct SelectedBits
{
    unsigned int bits;
    inline operator bool() const
    {
        return bits != 0;
    }
};
class ProbeE
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_0c;
    inline SelectedBits SelectedFlag() const
    {
        SelectedBits result = {m_0c & 2};
        return result;
    }
};

class ProbeD
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ProbeX* m_10;
};

class ProbeC
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
    virtual ProbeD* GetD();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ProbeC* m_1c;
};

class ProbeObj
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ProbeC* m_1c;
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
    ProbeC** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
    inline unsigned int ChildCount() const
    {
        return m_a6;
    }
    inline ProbeC* FirstChild() const
    {
        return ChildCount() <= 0 ? 0 : *m_a0;
    }
};

static inline bool CheckBody(ProbeD* body, ProbeObj*& obj)
{
    ProbeX* object = body->m_10;
    if (object)
    {
        ProbeY* rigid = object->FUN_00653290(&DAT_012681c0);
        if (rigid && rigid->m_08)
            return rigid->m_08->isActive_00c9bff0() != 0;
    }
    return false;
}
// Gets a body via obj->m_1c->GetD(), or via the first child's m_1c when extra data bit 1 is set; returns whether CheckBody is true for it.
// @fnv 0x00c80090
// src: COMMUNITY 0x00c80090
bool bhkUtilFunctions_IsRigidBodyActive(ProbeObj* obj)
{
    bool result = false;
    ProbeC* c = obj->m_1c;
    ProbeD* body = c ? c->GetD() : 0;
    if (!body)
    {
        ProbeE* extra = GetExtraDataChecked(obj);
        unsigned int sel = extra ? extra->m_0c & 2 : 0;
        if (sel)
        {
            ProbeC* collision = obj->FirstChild()->m_1c;
            if (collision)
                body = collision->GetD();
        }
    }
    if (body)
    {
        if (CheckBody(body, obj))
            result = true;
        else
            result = false;
    }
    return result;
}

struct WalkBits_c804
{
    union
    {
        unsigned int raw;
        struct
        {
            unsigned int lo : 7;
            unsigned int hi : 25;
        };
    };
    WalkBits_c804()
    {}
    WalkBits_c804(unsigned int r) : raw(r)
    {}
    void SetLo(unsigned int f)
    {
        lo = f;
    }
};

class WalkLookup_c804
{
  public:
    void* Find(const void* key);
};

class WalkMid_c804
{
  public:
    void Apply(unsigned int value);
    void Apply2(WalkBits_c804 value);
};

struct WalkHit_c804
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    WalkMid_c804* m_10;
};

struct WalkSub_c804
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    unsigned int m_1c;
};

struct WalkNode_c804
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual WalkNode_c804* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    WalkLookup_c804* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    WalkNode_c804** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

// For node and recursively each child, looks up DAT_012043f8 in m_1c and, if found, applies a value with its low 7 bits set to flag via Apply2.
// @fnv 0x00c804d0
// src: COMMUNITY 0x00c804d0
void bhkUtilFunctions_SetLayer(WalkNode_c804* node, unsigned int flag)
{
    if (node == 0)
    {
        return;
    }
    if (node->m_1c != 0)
    {
        WalkHit_c804* hit = (WalkHit_c804*)node->m_1c->Find(&DAT_012043f8);
        if (hit != 0 && hit->m_10 != 0)
        {
            WalkMid_c804* mid = hit->m_10;
            char* q = *(char**)((char*)mid + 8);
            WalkSub_c804* sub = 0;
            if (q != 0)
            {
                sub = (WalkSub_c804*)(q + 0x10);
            }
            WalkBits_c804 b(sub ? sub->m_1c : 0);
            b.SetLo(flag);
            mid->Apply2(b);
        }
    }
    WalkNode_c804* child = node->v03();
    if (child != 0)
    {
        unsigned int i = 0;
        while (i < child->m_a6)
        {
            WalkNode_c804** arr = child->m_a0;
            WalkNode_c804* item = arr[i];
            bhkUtilFunctions_SetLayer(item, flag);
            ++i;
        }
    }
}

extern unsigned int DAT_012043f8;

struct WorkNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    NiObject* unk1C;
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
    WorkNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

struct NodeDepth
{
    WorkNode_cls* node;
    unsigned int depth;
};

struct WorkStack_cls
{
    unsigned int unk00;
    unsigned int* m_04;
    unsigned int m_08;
    void __thiscall InsertItemAt(int a1, NodeDepth* a2);
};

// Recursively searches a work stack for a node matching a dynamic cast, pushing children with increased depth when no match is found.
// @fnv 0x00c80c00
// src: COMMUNITY 0x00c80c00
NiObject* __cdecl bhkUtilFunctions_FindCollisionObjectBFSRec(WorkNode_cls* apNode, WorkStack_cls* apStack, unsigned int uiMaxDepth,
                               unsigned int uiDepth)
{
    NiObject* result;
    if (apNode->unk1C == 0)
        result = 0;
    else
        result = apNode->unk1C->DynamicCast((unsigned int const*)&DAT_012043f8);

    _ReadWriteBarrier();
    if (result == 0)
    {
        if (apNode->v03() != 0 && uiDepth < uiMaxDepth)
        {
            unsigned int index = 0;
            while (index < apNode->m_a6)
            {
                WorkNode_cls* item = apNode->m_a0[index];
                if (item != 0)
                {
                    NodeDepth entry;
                    entry.node = item;
                    entry.depth = uiDepth + 1;
                    apStack->InsertItemAt(0, &entry);
                }
                ++index;
            }
        }
    }
    if (apStack->m_08 != 0 && result == 0)
    {
        unsigned int count = apStack->m_08;
        unsigned int* entries = apStack->m_04;
        unsigned int uiNodePtr = entries[count * 2 - 2];
        unsigned int high = entries[count * 2 - 1];
        apStack->m_08 = count - 1;
        result = bhkUtilFunctions_FindCollisionObjectBFSRec((WorkNode_cls*)uiNodePtr, apStack, uiMaxDepth, high);
    }
    return result;
}

// FUN_00c81890 (unit_a1df186ed60f.cpp) - 95B, /MT /O2 /GS /EHsc /Gy
// v4: extern __declspec(thread) int DAT_tls_0x2c0 (probe-exact a1+64 8b 0d+8b 14 81+8b 82 c0020000);
//     uchar bitfield f6/f0 (probe-exact mov cl/shr/test forms); m_bits word AND per v3 match
extern __declspec(thread) int DAT_tls_0x2c0;  // TLS slot +0x2C0 (module index 0x126fd98)
struct FUN_00c65b00_holder
{
    int __thiscall bhkCollisionObject_NitohkTransform();
};
struct FUN_00a68bf0_holder
{
    int __thiscall FUN_00a68bf0();
};  // ?UpdateWorldLoc@NiAVObject@@QAEXXZ

typedef int(__thiscall* FN_00c81890_VT)(void*);

union U_00c81890
{
    unsigned short m_bits;  // +0xC word member
    struct
    {
        unsigned char f0 : 1;
        unsigned char : 5;
        unsigned char f6 : 1;
        unsigned char : 1;
    } bf;
};

struct E_T
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
    virtual int va4();
    void* m_p4;
    void* m_p8;
    U_00c81890 u_c;

    bool GetBit(int n) const
    {
        return (u_c.m_bits >> n) & 1;
    }
    void ClearBit(int n)
    {
        u_c.m_bits &= ~(1 << n);
    }
    int __thiscall bhkBlendCollisionObject_ForceUpdateWorldData();
};

// Returns DAT_tls_0x2c0 if it is 3; otherwise calls FUN_00c65b00 (clearing bit 6), va4, or m_p8->FUN_00a68bf0 depending on bits 6 and 0, else returns it.
// @fnv 0x00c81890
// src: XBOX_PDB 0x00c81890
int __thiscall E_T::bhkBlendCollisionObject_ForceUpdateWorldData()
{
    int result = DAT_tls_0x2c0;
    if (result != 3)
    {
        if (GetBit(6))
        {
            if (result != 2)
            {
                result = ((FUN_00c65b00_holder*)this)->bhkCollisionObject_NitohkTransform();
                ClearBit(6);
                return result;
            }
        }
        else if (GetBit(0))
            return va4();
        if (m_p8)
            return ((FUN_00a68bf0_holder*)m_p8)->FUN_00a68bf0();
    }
    return result;
}

struct A50Inner
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
    unsigned char m_e8;
};
class A50Obj
{
  public:
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
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4(int t);
    int m_04;
    A50Inner* m_08;
};
struct A50Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    A50Obj* m_10;
    int unk14;
    int unk18;
    int unk1c;
    int m_20;
    void __thiscall bhkBlendCollisionObject_SynchronizeMotionType();
};
// If m_10 is set, calls its ve4(m_20) when m_20 is 4 and kind m_08->m_e8 is not 4, or m_20 is 1 and kind is 4 or 5; a null m_08 also calls.
// @fnv 0x00c81a50
// src: COMMUNITY 0x00c81a50
void A50Cls::bhkBlendCollisionObject_SynchronizeMotionType()
{
    A50Obj* p = m_10;
    if (!p)
        return;
    if (m_20 == 4)
    {
        A50Inner* q = p->m_08;
        int kind = q ? q->m_e8 : 0;
        if (!q)
            goto call;
        if (kind != m_20)
            goto call;
    }
    if (m_20 == 1)
    {
        A50Inner* q = p->m_08;
        int kind = q ? q->m_e8 : 0;
        if (!q)
            goto call;
        if (kind == 4)
            goto call;
        if (kind != 5)
            return;
    }
    else
    {
        return;
    }
call:
    p->ve4(m_20);
}

namespace fnv_00c828f0 {
void FUN_00ec61c0(void*, int, unsigned int);
extern unsigned int DAT_01268078[32];
extern unsigned __int64 DAT_01267f20[43];
extern int DAT_01267e70[43];
extern int DAT_01267ea4;
extern int DAT_01267e94;
extern int DAT_01267e9c;

inline void SetSelectionMask(unsigned int uiA, unsigned int uiB, bool bSelected)
{
    if (bSelected)
    {
        DAT_01267f20[uiA] |= (unsigned __int64)1 << uiB;
        DAT_01267f20[uiB] |= (unsigned __int64)1 << uiA;
    }
    else
    {
        DAT_01267f20[uiA] &= ~((unsigned __int64)1 << uiB);
        DAT_01267f20[uiB] &= ~((unsigned __int64)1 << uiA);
    }
}

void FUN_00c82870(unsigned int uiLayer, unsigned __int64 uiMask);

inline void SetFlagPair(unsigned int uiA, unsigned int uiB, bool bSelected)
{
    if (bSelected)
    {
        DAT_01268078[uiA] |= 1 << uiB;
        DAT_01268078[uiB] |= 1 << uiA;
    }
    else
    {
        DAT_01268078[uiA] &= ~(1 << uiB);
        DAT_01268078[uiB] &= ~(1 << uiA);
    }
}

// Zeroes DAT_01268078 and DAT_01267e70, fills DAT_01267f20 with 0xFF, applies many pair flag and mask updates, calls FUN_00c82870(34, ...), and sets three ints.
// @fnv 0x00c828f0
void InitializeSelectionMasks()
{
    FUN_00ec61c0(DAT_01268078, 0, sizeof(DAT_01268078));
    FUN_00ec61c0(DAT_01267f20, 0xFF, sizeof(DAT_01267f20));
    FUN_00ec61c0(DAT_01267e70, 0, sizeof(DAT_01267e70));
    SetFlagPair(6, 1, true);
    SetFlagPair(12, 1, true);
    SetFlagPair(7, 1, true);
    SetFlagPair(13, 1, true);
    SetFlagPair(17, 1, true);
    SetFlagPair(6, 2, true);
    SetFlagPair(12, 2, true);
    SetFlagPair(7, 2, true);
    SetFlagPair(13, 2, true);
    SetFlagPair(6, 3, true);
    SetFlagPair(12, 3, true);
    SetFlagPair(7, 3, true);
    SetFlagPair(13, 3, true);
    SetFlagPair(4, 6, true);
    SetFlagPair(4, 12, true);
    SetFlagPair(4, 7, true);
    SetFlagPair(4, 13, true);
    SetFlagPair(4, 17, true);
    SetFlagPair(5, 12, true);
    SetFlagPair(6, 12, true);
    SetFlagPair(13, 5, true);
    SetFlagPair(6, 13, true);
    SetFlagPair(6, 17, true);
    SetFlagPair(6, 8, true);
    SetFlagPair(6, 14, true);
    SetFlagPair(7, 13, true);
    SetFlagPair(7, 8, true);
    SetFlagPair(7, 14, true);
    SetFlagPair(7, 9, true);
    SetFlagPair(18, 13, true);
    SetFlagPair(18, 8, true);
    SetFlagPair(18, 14, true);
    SetFlagPair(18, 9, true);
    SetFlagPair(15, 7, true);
    SetFlagPair(8, 14, true);
    SetFlagPair(7, 10, true);
    SetFlagPair(18, 15, true);
    SetFlagPair(9, 15, true);
    SetFlagPair(10, 18, true);
    SetFlagPair(16, 7, true);
    SetFlagPair(14, 9, true);
    SetFlagPair(16, 18, true);
    SetFlagPair(10, 14, true);
    SetFlagPair(10, 15, true);
    SetFlagPair(6, 11, true);
    SetFlagPair(7, 11, true);
    SetFlagPair(12, 6, true);
    SetFlagPair(12, 7, true);
    SetFlagPair(12, 17, true);
    SetFlagPair(12, 14, true);
    SetFlagPair(12, 8, true);
    SetFlagPair(13, 8, true);
    SetFlagPair(13, 14, true);
    SetFlagPair(13, 9, true);
    SetFlagPair(13, 15, true);
    SetFlagPair(10, 13, true);
    SetFlagPair(16, 13, true);
    SetFlagPair(8, 15, true);
    SetFlagPair(16, 8, true);
    SetFlagPair(16, 9, true);
    SetFlagPair(22, 7, true);
    SetFlagPair(22, 5, true);
    SetFlagPair(22, 6, true);
    SetFlagPair(22, 13, true);
    SetFlagPair(22, 11, true);
    SetFlagPair(22, 12, true);
    SetFlagPair(22, 1, true);
    SetFlagPair(22, 4, true);
    SetFlagPair(22, 3, true);
    SetFlagPair(22, 2, true);
    SetFlagPair(22, 8, true);
    SetFlagPair(22, 9, true);
    SetFlagPair(22, 10, true);
    SetFlagPair(22, 14, true);
    SetFlagPair(15, 22, true);
    SetFlagPair(16, 22, true);
    SetFlagPair(18, 22, true);
    SetFlagPair(20, 22, true);
    SetFlagPair(21, 22, true);
    SetFlagPair(17, 22, true);
    SetFlagPair(24, 4, true);
    SetFlagPair(24, 3, true);
    SetFlagPair(24, 8, true);
    SetFlagPair(24, 9, true);
    SetFlagPair(24, 10, true);
    SetFlagPair(24, 14, true);
    SetFlagPair(24, 15, true);
    SetFlagPair(24, 16, true);
    SetFlagPair(2, 24, true);
    SetSelectionMask(19, 3, false);
    SetSelectionMask(19, 26, false);
    SetSelectionMask(19, 28, false);
    SetSelectionMask(19, 6, false);
    SetSelectionMask(19, 7, false);
    SetSelectionMask(19, 8, false);
    SetSelectionMask(19, 12, false);
    SetSelectionMask(19, 15, false);
    SetSelectionMask(19, 16, false);
    SetSelectionMask(19, 18, false);
    SetSelectionMask(19, 30, false);
    SetSelectionMask(31, 19, false);
    SetSelectionMask(19, 35, false);
    SetSelectionMask(19, 33, false);
    SetSelectionMask(19, 36, false);
    SetSelectionMask(19, 37, false);
    SetSelectionMask(38, 19, false);
    SetSelectionMask(42, 19, false);
    SetSelectionMask(19, 11, false);
    SetSelectionMask(20, 15, false);
    SetSelectionMask(20, 16, false);
    SetSelectionMask(20, 18, false);
    SetSelectionMask(20, 37, false);
    SetSelectionMask(20, 11, false);
    SetSelectionMask(8, 20, false);
    SetSelectionMask(21, 1, false);
    SetSelectionMask(21, 2, false);
    SetSelectionMask(21, 3, false);
    SetSelectionMask(21, 26, false);
    SetSelectionMask(21, 28, false);
    SetSelectionMask(21, 4, false);
    SetSelectionMask(21, 5, false);
    SetSelectionMask(21, 6, false);
    SetSelectionMask(21, 7, false);
    SetSelectionMask(21, 8, false);
    SetSelectionMask(21, 29, false);
    SetSelectionMask(21, 9, false);
    SetSelectionMask(21, 10, false);
    SetSelectionMask(21, 11, false);
    SetSelectionMask(21, 12, false);
    SetSelectionMask(21, 13, false);
    SetSelectionMask(21, 14, false);
    SetSelectionMask(21, 15, false);
    SetSelectionMask(21, 17, false);
    SetSelectionMask(21, 21, false);
    SetSelectionMask(21, 16, false);
    SetSelectionMask(21, 30, true);
    SetSelectionMask(21, 31, false);
    SetSelectionMask(21, 35, false);
    SetSelectionMask(21, 33, true);
    SetSelectionMask(37, 21, false);
    SetSelectionMask(38, 21, false);
    SetSelectionMask(39, 21, false);
    SetSelectionMask(30, 8, false);
    SetSelectionMask(21, 40, false);
    SetSelectionMask(21, 41, false);
    SetSelectionMask(21, 0, false);
    SetSelectionMask(21, 27, false);
    SetSelectionMask(30, 29, false);
    SetSelectionMask(18, 1, false);
    SetSelectionMask(30, 11, true);
    SetSelectionMask(18, 2, false);
    SetSelectionMask(18, 3, false);
    SetSelectionMask(18, 26, false);
    SetSelectionMask(18, 28, false);
    SetSelectionMask(18, 4, false);
    SetSelectionMask(18, 5, false);
    SetSelectionMask(18, 6, false);
    SetSelectionMask(18, 7, false);
    SetSelectionMask(18, 8, false);
    SetSelectionMask(18, 29, false);
    SetSelectionMask(18, 9, false);
    SetSelectionMask(18, 10, false);
    SetSelectionMask(18, 11, false);
    SetSelectionMask(18, 12, false);
    SetSelectionMask(18, 13, false);
    SetSelectionMask(18, 14, false);
    SetSelectionMask(18, 15, false);
    SetSelectionMask(18, 17, false);
    SetSelectionMask(18, 18, false);
    SetSelectionMask(18, 16, false);
    SetSelectionMask(18, 30, false);
    SetSelectionMask(18, 31, false);
    SetSelectionMask(18, 35, false);
    SetSelectionMask(18, 37, false);
    SetSelectionMask(29, 8, false);
    SetSelectionMask(38, 18, false);
    SetSelectionMask(39, 18, false);
    SetSelectionMask(40, 18, false);
    SetSelectionMask(41, 18, false);
    SetSelectionMask(8, 5, false);
    SetSelectionMask(8, 4, false);
    SetSelectionMask(10, 8, false);
    SetSelectionMask(15, 1, false);
    SetSelectionMask(15, 2, false);
    SetSelectionMask(15, 3, false);
    SetSelectionMask(15, 26, false);
    SetSelectionMask(15, 28, false);
    SetSelectionMask(15, 4, false);
    SetSelectionMask(15, 5, false);
    SetSelectionMask(15, 6, false);
    SetSelectionMask(15, 7, false);
    SetSelectionMask(15, 8, false);
    SetSelectionMask(15, 29, false);
    SetSelectionMask(15, 9, false);
    SetSelectionMask(15, 10, false);
    SetSelectionMask(15, 11, false);
    SetSelectionMask(15, 12, false);
    SetSelectionMask(15, 13, false);
    SetSelectionMask(15, 14, false);
    SetSelectionMask(15, 15, false);
    SetSelectionMask(15, 17, false);
    SetSelectionMask(15, 16, false);
    SetSelectionMask(15, 30, false);
    SetSelectionMask(15, 31, false);
    SetSelectionMask(15, 35, false);
    SetSelectionMask(15, 37, false);
    SetSelectionMask(15, 38, false);
    SetSelectionMask(15, 39, false);
    SetSelectionMask(15, 40, false);
    SetSelectionMask(15, 41, false);
    SetSelectionMask(33, 1, false);
    SetSelectionMask(33, 2, false);
    SetSelectionMask(33, 3, false);
    SetSelectionMask(33, 26, false);
    SetSelectionMask(33, 28, false);
    SetSelectionMask(33, 4, false);
    SetSelectionMask(33, 5, false);
    SetSelectionMask(33, 6, false);
    SetSelectionMask(33, 7, false);
    SetSelectionMask(33, 8, false);
    SetSelectionMask(33, 29, false);
    SetSelectionMask(33, 9, false);
    SetSelectionMask(33, 10, false);
    SetSelectionMask(33, 11, true);
    SetSelectionMask(33, 12, false);
    SetSelectionMask(33, 13, false);
    SetSelectionMask(33, 14, false);
    SetSelectionMask(33, 33, false);
    SetSelectionMask(33, 17, false);
    SetSelectionMask(33, 15, false);
    SetSelectionMask(33, 16, false);
    SetSelectionMask(33, 30, false);
    SetSelectionMask(33, 31, false);
    SetSelectionMask(33, 35, false);
    SetSelectionMask(33, 37, false);
    SetSelectionMask(33, 38, false);
    SetSelectionMask(33, 39, false);
    SetSelectionMask(33, 40, false);
    SetSelectionMask(33, 41, false);
    SetSelectionMask(35, 5, false);
    SetSelectionMask(35, 7, false);
    SetSelectionMask(35, 12, false);
    SetSelectionMask(35, 35, false);
    SetSelectionMask(35, 11, false);
    SetSelectionMask(35, 6, false);
    SetSelectionMask(36, 7, false);
    SetSelectionMask(36, 12, false);
    SetSelectionMask(36, 11, false);
    SetSelectionMask(37, 3, false);
    SetSelectionMask(37, 26, false);
    SetSelectionMask(37, 28, false);
    SetSelectionMask(37, 7, false);
    SetSelectionMask(37, 11, false);
    SetSelectionMask(37, 12, false);
    SetSelectionMask(37, 30, false);
    SetSelectionMask(38, 31, false);
    SetSelectionMask(38, 4, false);
    SetSelectionMask(38, 5, false);
    SetSelectionMask(38, 6, false);
    SetSelectionMask(38, 7, false);
    SetSelectionMask(38, 8, false);
    SetSelectionMask(38, 29, false);
    SetSelectionMask(38, 30, false);
    SetSelectionMask(38, 10, false);
    SetSelectionMask(38, 35, false);
    SetSelectionMask(38, 12, false);
    SetSelectionMask(38, 14, false);
    SetSelectionMask(38, 16, false);
    SetSelectionMask(38, 41, false);
    SetSelectionMask(38, 36, false);
    SetSelectionMask(38, 37, false);
    SetSelectionMask(31, 31, false);
    SetSelectionMask(31, 1, false);
    SetSelectionMask(31, 4, false);
    SetSelectionMask(31, 5, false);
    SetSelectionMask(31, 6, false);
    SetSelectionMask(31, 7, false);
    SetSelectionMask(31, 8, false);
    SetSelectionMask(31, 29, false);
    SetSelectionMask(31, 9, false);
    SetSelectionMask(31, 10, false);
    SetSelectionMask(31, 11, false);
    SetSelectionMask(31, 13, false);
    SetSelectionMask(31, 15, false);
    SetSelectionMask(31, 17, false);
    SetSelectionMask(31, 35, false);
    SetSelectionMask(31, 41, false);
    SetSelectionMask(31, 36, false);
    SetSelectionMask(31, 37, false);
    SetSelectionMask(41, 3, false);
    SetSelectionMask(41, 26, false);
    SetSelectionMask(41, 28, false);
    SetSelectionMask(41, 7, false);
    SetSelectionMask(41, 11, false);
    SetSelectionMask(41, 35, false);
    SetSelectionMask(41, 36, false);
    SetSelectionMask(41, 37, false);
    SetSelectionMask(41, 39, false);
    SetSelectionMask(41, 40, false);
    SetSelectionMask(41, 38, false);
    SetSelectionMask(41, 41, false);
    SetSelectionMask(6, 7, false);
    SetSelectionMask(6, 16, false);
    SetSelectionMask(6, 3, false);
    SetSelectionMask(12, 1, false);
    SetSelectionMask(12, 2, false);
    SetSelectionMask(12, 3, false);
    SetSelectionMask(12, 26, false);
    SetSelectionMask(12, 28, false);
    SetSelectionMask(12, 9, false);
    SetSelectionMask(12, 10, false);
    SetSelectionMask(12, 11, false);
    SetSelectionMask(12, 12, false);
    SetSelectionMask(12, 13, false);
    SetSelectionMask(12, 15, false);
    SetSelectionMask(12, 16, false);
    SetSelectionMask(12, 17, false);
    SetSelectionMask(12, 22, false);
    SetSelectionMask(12, 32, false);
    SetSelectionMask(12, 38, false);
    SetSelectionMask(12, 42, false);
    SetSelectionMask(12, 37, false);
    SetSelectionMask(12, 36, false);
    SetSelectionMask(12, 41, false);
    SetSelectionMask(22, 1, false);
    SetSelectionMask(22, 2, false);
    SetSelectionMask(22, 3, false);
    SetSelectionMask(22, 26, false);
    SetSelectionMask(22, 4, false);
    SetSelectionMask(22, 5, false);
    SetSelectionMask(22, 6, false);
    SetSelectionMask(22, 7, false);
    SetSelectionMask(22, 8, false);
    SetSelectionMask(22, 29, false);
    SetSelectionMask(22, 9, false);
    SetSelectionMask(22, 10, false);
    SetSelectionMask(22, 11, false);
    SetSelectionMask(22, 12, false);
    SetSelectionMask(22, 13, false);
    SetSelectionMask(22, 14, false);
    SetSelectionMask(22, 15, false);
    SetSelectionMask(22, 16, false);
    SetSelectionMask(22, 17, false);
    SetSelectionMask(22, 18, false);
    SetSelectionMask(22, 19, false);
    SetSelectionMask(22, 20, false);
    SetSelectionMask(22, 22, false);
    SetSelectionMask(22, 23, false);
    SetSelectionMask(22, 25, false);
    SetSelectionMask(22, 31, false);
    SetSelectionMask(22, 32, false);
    SetSelectionMask(22, 33, false);
    SetSelectionMask(22, 35, false);
    SetSelectionMask(22, 36, false);
    SetSelectionMask(22, 37, false);
    SetSelectionMask(22, 38, false);
    SetSelectionMask(22, 41, false);
    SetSelectionMask(22, 42, false);
    SetSelectionMask(22, 27, false);
    SetSelectionMask(22, 34, false);
    SetSelectionMask(22, 0, false);
    SetSelectionMask(23, 1, false);
    SetSelectionMask(23, 2, false);
    SetSelectionMask(23, 3, false);
    SetSelectionMask(23, 26, false);
    SetSelectionMask(23, 28, false);
    SetSelectionMask(23, 4, false);
    SetSelectionMask(23, 5, false);
    SetSelectionMask(23, 7, false);
    SetSelectionMask(23, 8, false);
    SetSelectionMask(23, 29, false);
    SetSelectionMask(23, 9, false);
    SetSelectionMask(23, 10, false);
    SetSelectionMask(23, 11, false);
    SetSelectionMask(23, 12, false);
    SetSelectionMask(23, 13, false);
    SetSelectionMask(23, 14, false);
    SetSelectionMask(23, 15, false);
    SetSelectionMask(23, 16, false);
    SetSelectionMask(23, 17, false);
    SetSelectionMask(23, 18, false);
    SetSelectionMask(23, 19, false);
    SetSelectionMask(23, 20, false);
    SetSelectionMask(23, 22, false);
    SetSelectionMask(23, 23, false);
    SetSelectionMask(23, 25, false);
    SetSelectionMask(23, 30, false);
    SetSelectionMask(23, 31, false);
    SetSelectionMask(23, 32, false);
    SetSelectionMask(23, 33, false);
    SetSelectionMask(23, 35, false);
    SetSelectionMask(23, 36, false);
    SetSelectionMask(23, 37, false);
    SetSelectionMask(23, 38, false);
    SetSelectionMask(23, 41, false);
    SetSelectionMask(23, 42, false);
    SetSelectionMask(24, 1, false);
    SetSelectionMask(24, 2, false);
    SetSelectionMask(24, 3, false);
    SetSelectionMask(24, 26, false);
    SetSelectionMask(24, 28, false);
    SetSelectionMask(24, 4, false);
    SetSelectionMask(24, 5, false);
    SetSelectionMask(24, 7, false);
    SetSelectionMask(24, 8, false);
    SetSelectionMask(24, 29, false);
    SetSelectionMask(24, 9, false);
    SetSelectionMask(24, 10, false);
    SetSelectionMask(24, 11, false);
    SetSelectionMask(24, 12, false);
    SetSelectionMask(24, 13, false);
    SetSelectionMask(24, 14, false);
    SetSelectionMask(24, 15, false);
    SetSelectionMask(24, 16, false);
    SetSelectionMask(24, 17, false);
    SetSelectionMask(24, 18, false);
    SetSelectionMask(24, 19, false);
    SetSelectionMask(24, 20, false);
    SetSelectionMask(24, 21, false);
    SetSelectionMask(24, 22, false);
    SetSelectionMask(24, 23, false);
    SetSelectionMask(24, 24, false);
    SetSelectionMask(24, 25, false);
    SetSelectionMask(24, 31, false);
    SetSelectionMask(24, 32, false);
    SetSelectionMask(24, 33, false);
    SetSelectionMask(24, 35, false);
    SetSelectionMask(24, 36, false);
    SetSelectionMask(24, 37, false);
    SetSelectionMask(24, 38, false);
    SetSelectionMask(24, 42, false);
    SetSelectionMask(25, 3, false);
    SetSelectionMask(25, 26, false);
    SetSelectionMask(25, 28, false);
    SetSelectionMask(25, 6, false);
    SetSelectionMask(25, 7, false);
    SetSelectionMask(25, 8, false);
    SetSelectionMask(25, 12, false);
    SetSelectionMask(25, 15, false);
    SetSelectionMask(25, 16, false);
    SetSelectionMask(25, 18, false);
    SetSelectionMask(25, 30, false);
    SetSelectionMask(25, 31, false);
    SetSelectionMask(25, 35, false);
    SetSelectionMask(25, 36, false);
    SetSelectionMask(25, 37, false);
    SetSelectionMask(25, 38, false);
    SetSelectionMask(25, 42, false);
    SetSelectionMask(25, 11, false);
    SetSelectionMask(7, 7, false);
    SetSelectionMask(7, 16, false);
    SetSelectionMask(7, 3, false);
    SetSelectionMask(7, 26, false);
    SetSelectionMask(7, 28, false);
    SetSelectionMask(42, 4, false);
    SetSelectionMask(42, 6, false);
    SetSelectionMask(42, 5, false);
    SetSelectionMask(42, 11, false);
    SetSelectionMask(42, 29, false);
    SetSelectionMask(42, 31, false);
    SetSelectionMask(42, 38, false);
    SetSelectionMask(42, 35, false);
    SetSelectionMask(42, 41, false);
    SetSelectionMask(42, 37, false);
    SetSelectionMask(27, 19, false);
    SetSelectionMask(27, 25, false);
    SetSelectionMask(27, 31, false);
    SetSelectionMask(27, 32, false);
    SetSelectionMask(27, 33, false);
    SetSelectionMask(27, 35, false);
    SetSelectionMask(27, 37, false);
    SetSelectionMask(27, 42, false);
    SetSelectionMask(27, 5, false);
    SetSelectionMask(3, 0, false);
    SetSelectionMask(3, 13, false);
    FUN_00c82870(34, 0x10000004);
    DAT_01267ea4 = 2;
    DAT_01267e94 = 3;
    DAT_01267e9c = 4;
}
}  // namespace fnv_00c828f0

struct FUN_00c84d00_obj
{
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
    unsigned char unk1E4;
    unsigned char m_1e5;
};

struct FUN_00c84d00_cls
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
    virtual int* vGet(FUN_00c84d00_obj** pp);
    void FUN_00c87650(FUN_00c84d00_obj* a);
    void bhkShape_LoadBinary(FUN_00c84d00_obj* a1);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    int m_10;
};

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

// @fnv 0x00c84d00
// src: XBOX_PDB 0x00c84d00
void FUN_00c84d00_cls::bhkShape_LoadBinary(FUN_00c84d00_obj* apObj)
{
    FUN_00c87650(apObj);
    FUN_00c84d00_obj* out;
    int* p = vGet(&out);
    if (apObj->m_1e5 != 1)
    {
        *p = (int)_byteswap_ulong((unsigned long)*p);
    }
    if (*p >= 0x24)
    {
        *p = 0;
    }
    m_10 = *p;
    *p = 0;
}

class Obj
{
  public:
    virtual void* v00();
    virtual void* v01();
    virtual void* v02();
    virtual void* v03();
    virtual void* v04();
    virtual void* v05();
    virtual void* v06();
    virtual void* v07();
    virtual void* v08();
    virtual void* v09();
    virtual void* v0a();
    virtual void* v0b();
    virtual void* v0c();
    virtual void* v0d();
    virtual void* v0e();
    virtual void* v0f();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v1a();
    virtual void* v1b();
    virtual void* v1c();
    virtual void* v1d();
    virtual void* v1e();
    virtual void* v1f();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    unsigned int unk04;
    Obj* m_08;
    void bhkWorld_Add_00c6b0a0(Obj* p);
    bool bhkWorldObject_Add(Obj* a);
};
// If m_08 is set: with a null, calls v28; otherwise if v25() differs from a->m_08, calls v28, passes m_08 to a->FUN_00c6b0a0 and returns true.
// @fnv 0x00c85810
// src: XBOX_PDB 0x00c85810
bool Obj::bhkWorldObject_Add(Obj* a)
{
    Obj* p = this ? m_08 : 0;
    bool r = false;
    if (p)
    {
        if (a)
        {
            Obj* w = (Obj*)this->v25();
            if (w != a->m_08)
            {
                this->v28();
                a->bhkWorld_Add_00c6b0a0(p);
                r = true;
            }
        }
        else
        {
            this->v28();
        }
    }
    return r;
}

extern int DAT_012682e8;
extern int DAT_012682dc;

struct FUN_00a63430_class
{
    void* FUN_00a63430();
};

struct FUN_00653290_class
{
    int FUN_00653290(int* arg);
};

struct FUN_00cca4e0
{
    void* m_00;
    void* m_04;
    void* m_08;
    int m_0c;
    int m_10;
    FUN_00cca4e0(void* value);
    static void* operator new(unsigned int bytes)
    {
        return Object_DispatchCommandFour(bytes);
    }
};

struct FUN_00c87670_class
{
    void bhkSerializable_LinkObject(unsigned int value);
};

struct S00c859e0_holder
{
    void* m_00;
    void* m_04;
};

typedef S00c859e0_holder*(__thiscall* S00c859e0_slot45)(void*, unsigned int*);

struct S00c859e0_cls
{
    void bhkWorldObject_LinkObject(unsigned int value);
};

// Calls vtable slot 45 for a holder, sets its m_04 from FUN_00a63430's result (or a new FUN_00cca4e0's m_08 under type checks), then calls FUN_00c87670.
// @fnv 0x00c859e0
// src: XBOX_PDB 0x00c859e0
void S00c859e0_cls::bhkWorldObject_LinkObject(unsigned int value)
{
    unsigned int id = value;
    _ReadWriteBarrier();
    void* found = reinterpret_cast<FUN_00a63430_class*>(id)->FUN_00a63430();
    void** table = *reinterpret_cast<void***>(this);
    S00c859e0_holder* holder = reinterpret_cast<S00c859e0_slot45>(table[45])(this, &value);
    if (found != 0)
    {
        holder->m_04 = reinterpret_cast<void**>(found)[2];
        if (reinterpret_cast<FUN_00653290_class*>(this)->FUN_00653290(&DAT_012681c0) != 0)
        {
            if (reinterpret_cast<FUN_00653290_class*>(found)->FUN_00653290(&DAT_012682e8) != 0 ||
                reinterpret_cast<FUN_00653290_class*>(found)->FUN_00653290(&DAT_012682dc) != 0)
            {
                FUN_00cca4e0* created = new FUN_00cca4e0(found);
                void* tail = created ? created->m_08 : 0;
                if (created != 0)
                {
                    holder->m_04 = tail;
                }
            }
        }
    }
    reinterpret_cast<FUN_00c87670_class*>(this)->bhkSerializable_LinkObject(id);
}

extern __declspec(thread) unsigned int t_uiMemContextC877;

inline unsigned int GetMemContextC877()
{
    return t_uiMemContextC877;
}

inline void SetMemContextC877(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextC877 = m_uiGeometryShaderFlags;
}

inline AutoMemContext::AutoMemContext(int context)
{
    m_eMemoryContext = (MEM_CONTEXT)GetMemContextC877();
    SetMemContextC877(context);
}
inline AutoMemContext::~AutoMemContext()
{
    SetMemContextC877(m_eMemoryContext);
}

struct BlockPool_c877
{
    void MemoryManager_Deallocate(void* pvBlock);
};

class PoolOwnerBase_c877
{
  public:
    virtual void v00();
    ~PoolOwnerBase_c877();
    int unk04;
    int unk08;
};

class FUN_00c877b0 : public PoolOwnerBase_c877
{
  public:
    virtual void v00();
    ~FUN_00c877b0();
    void* m_pvBlock;
};

// Sets the thread memory context to 0x10 while freeing m_pvBlock through the allocator at DAT_011f6238, then nulls m_pvBlock and restores the context.
// @fnv 0x00c877b0
FUN_00c877b0::~FUN_00c877b0()
{
    AutoMemContext kContext(0x10);
    void* pvBlock = m_pvBlock;
    ((BlockPool_c877*)&DAT_011f6238)->MemoryManager_Deallocate(pvBlock);
    m_pvBlock = 0;
}

struct C89AC0_Owner;
struct C89AC0_Child
{
    int unk00;
    int unk04;
    C89AC0_Owner* m_pSharedOwner;
    void FUN_00c905b0();
    void FUN_00c90510();
};
struct C89AC0_Owner
{
    int unk00;
    C89AC0_Child* m_pChildObject;
    void SetChildObject(C89AC0_Child* child);
};
// @fnv 0x00c89ac0
void C89AC0_Owner::SetChildObject(C89AC0_Child* child)
{
    MemoryContextGuard guard;
    if (m_pChildObject)
    {
        m_pChildObject->m_pSharedOwner = 0;
        m_pChildObject->FUN_00c905b0();
    }
    if (child)
    {
        child->FUN_00c90510();
        child->m_pSharedOwner = this;
    }
    m_pChildObject = child;
}

struct ThreadData674
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned int context;
};
extern __declspec(thread) ThreadData674 g_threadData;
struct Context674
{
    unsigned int previous;
    Context674()
    {
        previous = g_threadData.context;
        g_threadData.context = 16;
    }
    ~Context674()
    {
        g_threadData.context = previous;
    }
};

struct Heap674
{
    virtual void v0();
    virtual void* Allocate(unsigned int);
};

struct Base674
{
    virtual ~Base674();
    unsigned short size;
    unsigned short flags;
    static void* operator new(unsigned int size)
    {
        hkMemoryRouter* r = hkMemoryRouter_getInstance();
        Heap674* heap = (Heap674*)r->m_heap;
        Base674* b = (Base674*)heap->Allocate(size);
        b->size = (unsigned short)size;
        return b;
    }
    static void operator delete(void* memory);
};
struct FUN_00cf4190_class : Base674
{
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    FUN_00cf4190_class();
    void bhkPositionConstraintMotor_LoadBinary(NiStream*);
};
struct FUN_00cf43b0_class : Base674
{
    int unk08, unk0C, unk10, unk14, unk18, unk1C;
    FUN_00cf43b0_class();
    void bhkVelocityConstraintMotor_LoadBinary(NiStream*);
};
struct FUN_00cf45d0_class : Base674
{
    int unk08, unk0C, unk10, unk14, unk18;
    FUN_00cf45d0_class();
    void SaveToArchive(NiStream*);
};
// Reads a type byte and, for types 1 to 3, allocates the matching Base674 subclass, calls its stream method and returns it; otherwise returns null.
// @fnv 0x00c8a330
// src: XBOX_PDB 0x00c8a330
void* __stdcall hkConstraintCinfo_LoadMotor(NiStream* stream)
{
    Context674 context;
    Base674* result = 0;

    unsigned char type = 0;
    ReadStream(*stream)->Read(&type, 1);
    switch (type)
    {
    case 1: {
        FUN_00cf4190_class* o = new FUN_00cf4190_class;
        o->bhkPositionConstraintMotor_LoadBinary(stream);
        result = o;
        break;
    }
    case 2: {
        FUN_00cf43b0_class* o = new FUN_00cf43b0_class;
        o->bhkVelocityConstraintMotor_LoadBinary(stream);
        result = o;
        break;
    }
    case 3: {
        FUN_00cf45d0_class* o = new FUN_00cf45d0_class;
        o->SaveToArchive(stream);
        result = o;
        break;
    }
    }
    return result;
}

struct C8AC00_Info
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
    int id;
};

struct C8AC00_Target
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
    virtual C8AC00_Info* GetInfo();
};

struct C8AC00_Owner
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
    C8AC00_Target* target;
};

struct C8AC00_Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int id;
    void SetRefObject(int);
};

struct C8AC00_Self
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
    virtual C8AC00_Owner* GetOwner();
    int unk04;
    C8AC00_Sub* sub;
    bool bhkAction_Remove();
    bool bhkBinaryAction_Remove();
};

extern "C" void _ReadWriteBarrier(void);
extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);

// Returns false if the owner has no target; otherwise returns FUN_00c87b40(), first calling sub->SetRefObject(0) if sub's id equals the target info's id.
// @fnv 0x00c8ac00
// src: XBOX_PDB 0x00c8ac00
bool C8AC00_Self::bhkBinaryAction_Remove()
{
    ScopedMemoryCategory guard;
    C8AC00_Owner* owner = GetOwner();
    C8AC00_Target* target = owner ? owner->target : 0;
    _ReadWriteBarrier();
    if (target)
    {
        bool result = bhkAction_Remove();
        int id = sub ? sub->id : 0;
        C8AC00_Info* info = target->GetInfo();
        int infoId = 0;
        if (info)
            infoId = info->id;
        if (id == infoId)
        {
            if (sub)
            {
                sub->SetRefObject(0);
                return result;
            }
            return result;
        }
        return result;
    }
    return false;
}

namespace fnv_00c8af10 {
extern __declspec(thread) unsigned int memoryCategory;
extern int DAT_01030bf4, DAT_010c44e4, DAT_010c485c;
extern int DAT_012680f8, DAT_012686d0, DAT_012681a0;
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct NewShape
{
    int* vtable;
    int field04, field08, field0c, field10;
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    void __thiscall UpdateState_00c87c30();
    NewShape()
    {
        UpdateState_00c87c30();
        vtable = &DAT_01030bf4;
        field0c = 0;
        field10 = 0;
        ++DAT_012680f8;
        vtable = &DAT_010c44e4;
        ++DAT_012686d0;
        vtable = &DAT_010c485c;
        ++DAT_012681a0;
    }
};
struct MemoryCategoryScope
{
    unsigned int previous;
    MemoryCategoryScope() : previous(memoryCategory)
    {
        memoryCategory = 16;
    }
    ~MemoryCategoryScope()
    {
        memoryCategory = previous;
    }
};
struct FUN_00c8af10_holder
{
    unsigned int* __thiscall bhkListShape_CreateClone(unsigned int param);
};
// Allocates and constructs a NewShape, calls this object's virtual at slot 49 with it and param, and returns the new object.
// @fnv 0x00c8af10
// src: XBOX_PDB 0x00c8af10
unsigned int* __thiscall FUN_00c8af10_holder::bhkListShape_CreateClone(unsigned int param)
{
    MemoryCategoryScope scope;
    bhkSerializable_CloneCritLock();
    NewShape* result = new NewShape;
    typedef void(__thiscall * Dispatch)(FUN_00c8af10_holder*, NewShape*, unsigned int);
    void** vtable = *(void***)this;
    ((Dispatch)vtable[49])(this, result, param);
    bhkSerializable_CloneCritUnlock();
    return (unsigned int*)result;
}
}  // namespace fnv_00c8af10

struct AllocLocal;
inline void DeallocateLocal(AllocLocal* a, void* p, int const& n);
struct TypeInfoLocal
{
    const char* name;
    TypeInfoLocal* base;
};
extern TypeInfoLocal g_012682e8, g_012682dc, g_012686a0, g_01268264;
struct ShapeLocal
{
    virtual void v0();
    virtual void v1();
    virtual TypeInfoLocal* GetType();
    int reference;
    ShapeLocal* object;
    ShapeLocal* FUN_00653290(const TypeInfoLocal*);
    bool IsType(const TypeInfoLocal* type)
    {
        const TypeInfoLocal* current = GetType();
        while (current)
        {
            if (current == type)
                return true;
            current = current->base;
        }
        return false;
    }
};
struct WrapperLocal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    static void* operator new(unsigned int);
    WrapperLocal(ShapeLocal*);
};

struct AllocLocal;
struct AllocTableLocal
{
    void(__thiscall* v0)(AllocLocal*);
    void(__thiscall* v1)(AllocLocal*);
    void(__thiscall* v2)(AllocLocal*);
    void(__thiscall* v3)(AllocLocal*);
    void(__thiscall* free)(AllocLocal*, void*, int);
};
struct AllocViewLocal
{
    AllocTableLocal* table;
};
struct AllocLocal
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*, int);
    void Clear(SpawnedPtrArray& arr)
    {
        int cap = arr.m_uiCapacity;
        arr.m_uiCount = 0;
        if (!(cap & 0x80000000))
        {
            void* p = arr.m_pData;
            DeallocateLocal(this, p, cap & 0x3fffffff);
        }
        arr.m_pData = 0;
        arr.m_uiCapacity = 0x80000000;
    }
};
inline void DeallocateLocal(AllocLocal* a, void* p, int const& n)
{
    a->Free(p, n * 4);
}
void hkArrayUtil__reserve(void*, SpawnedPtrArray*, int, int);
template <class T> inline void ConstructLocal(T* dest, int n, const T& value)
{
    for (int k = 0; k < n; ++k)
        dest[k] = value;
}
struct ArrayLocal : SpawnedPtrArray
{
    void Clear(AllocLocal& allocator)
    {
        m_uiCount = 0;
        if ((int)m_uiCapacity >= 0)
            allocator.Free(m_pData, (m_uiCapacity & 0x3fffffff) * 4);
        m_pData = 0;
        m_uiCapacity = 0x80000000;
    }
    void Reserve(void* allocator, int count)
    {
        int capacity = m_uiCapacity & 0x3fffffff;
        if (capacity < count)
        {
            int desired = capacity * 2;
            if (count >= desired)
                desired = count;
            hkArrayUtil__reserve(allocator, this, desired, 4);
        }
    }
    void Append(hkMemoryRouter* holder, ShapeLocal* raw)
    {
        if (m_uiCount == (m_uiCapacity & 0x3fffffff))
            ResizeAudioStream(holder->m_heap, this, 4);
        ConstructLocal(m_pData + m_uiCount, 1, (void*)raw);
        ++m_uiCount;
    }
};

struct ListLocal
{
    int unk00;
    ArrayLocal items;
};
struct LoaderLocal
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
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual ListLocal* GetList(bool*);
    void bhkShape_LinkObject(NiStream*);
    void LoadShapes(NiStream*);
};
// Refills items with shapes read from stream (some wrapped in WrapperLocal), builds an old-version message when version < 17, then calls FUN_00c84cc0.
// @fnv 0x00c8b5e0
void LoaderLocal::LoadShapes(NiStream* stream)
{
    MemContextScope context(16);
    bool shared;
    ListLocal* list = GetList(&shared);
    unsigned int count = stream->GetLinkID();
    ArrayLocal& items = list->items;
    hkMemoryRouter* h1 = hkMemoryRouter_getInstance();
    ((AllocLocal*)h1->m_heap)->Clear(items);
    hkMemoryRouter* h2 = hkMemoryRouter_getInstance();
    items.Reserve(h2->m_heap, count);
    if (count > 0)
    {
        unsigned int remaining = count;
        do
        {
            ShapeLocal* object = (ShapeLocal*)stream->GetLoadedObject();
            if (object)
            {
                ShapeLocal* converted = object->IsType(&g_012682e8) ? object : 0;
                if (converted || object->FUN_00653290(&g_012682dc))
                {
                    WrapperLocal* wrapper = new WrapperLocal(object);
                    if (wrapper)
                        object = (ShapeLocal*)wrapper;
                }
                ShapeLocal* raw = object ? object->object : 0;
                items.Append(hkMemoryRouter_getInstance(), raw);
            }
        } while (--remaining);
    }
    if (*(unsigned int*)((char*)stream + 4) < 17)
    {
        unsigned int size = list->items.m_uiCount;
        unsigned int index = 0;
        for (; index < size; ++index)
        {
            ShapeLocal* entry = (ShapeLocal*)items.m_pData[index];
            if (entry && entry->object)
            {
                ShapeLocal* shape = entry->object;
                if (!shape->IsType(&g_012686a0) && !shape->IsType(&g_01268264))
                    goto finished;
            }
        }
        {
            char message[1000];
            sprintf_s(message, 1000,
                      "HAVOK: %s contains an old (Havok 3.3) hkpConvexListShape (%d) and should be re-exported to 17.",
                      (char*)stream + 0xe0, *(unsigned int*)((char*)stream + 4));
        }
    }
finished:
    bhkShape_LinkObject(stream);
}

class S00c8bf40_Flags
{
  public:
    bool bhkShape_IsEqual(const S00c8bf40_Flags* pkOther) const;
    bool bhkBvTreeShape_IsEqual(const S00c8bf40_Flags* pkOther) const;
};

// @fnv 0x00c8bf40
// src: XBOX_PDB 0x00c8bf40
bool S00c8bf40_Flags::bhkBvTreeShape_IsEqual(const S00c8bf40_Flags* pkOther) const
{
    return bhkShape_IsEqual(pkOther);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct FUN_00c6c290
{
    void bhkNiCollisionObject_SetWorldObject(int);
};
struct S00c90090_Ptr
{
    NiRefObject* p;
    S00c90090_Ptr(NiRefObject* q) : p(q)
    {
        if (p)
            InterlockedIncrement((long volatile*)&p->m_uiRefCount);
    }
    ~S00c90090_Ptr()
    {
        if (p)
        {
            if (!InterlockedDecrement((long volatile*)&p->m_uiRefCount))
                p->DeleteThis();
        }
    }
};
struct S00c90090_Self
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
    virtual void vf8C(int i);
    int m_p4;
    int m_p8;
    int m_pc;
    NiRefObject* m_p10;
    int m_p14;
    float m_f18;
    float m_f1c;
    int m_p20;
    int m_p24;
    float GetF1C() const
    {
        return m_f1c;
    }
    void SetF1C(float f)
    {
        m_f1c = f;
    }
    float GetF18() const
    {
        return m_f18;
    }
    void SetF18(float f)
    {
        m_f18 = f;
    }
    void bhkBlendCollisionObjectAddRotation_CopyFrom(S00c90090_Self* src);
};
// Copies src's m_p10 object (via FUN_00c6b980), the two floats and m_p24, then calls vf8C with src->m_p8.
// @fnv 0x00c90090
// src: XBOX_PDB 0x00c90090
void S00c90090_Self::bhkBlendCollisionObjectAddRotation_CopyFrom(S00c90090_Self* src)
{
    S00c90090_Ptr r(src->m_p10);
    ((FUN_00c6c290*)src)->bhkNiCollisionObject_SetWorldObject(0);
    ((FUN_00c6c290*)this)->bhkNiCollisionObject_SetWorldObject((int)r.p);
    SetF1C(src->GetF1C());
    SetF18(src->GetF18());
    int t24 = src->m_p24;
    m_p24 = t24;
    int n = src->m_p8;
    vf8C(n);
}



// 0x00c90240 reports AdditionalRotation after the blend fields at 0x18/0x1c; bhkTransformShape derives from bhkShape and has no such blend base.
struct BlendAdditionalRotationViewer : FUN_00c825b0_cls
{
    int unk28;
    NiMatrix3 m_kAdditionalRotation;

    void bhkBlendCollisionObjectAddRotation_AddViewerStrings(ViewerStrings* pkStrings);
};

// Calls AddToViewerStrings, adds a debug string made from DAT_012681cc, then adds m_kAdditionalRotation formatted as AdditionalRotation to pkStrings.
// @fnv 0x00c90240
// src: XBOX_PDB 0x00c90240
void BlendAdditionalRotationViewer::bhkBlendCollisionObjectAddRotation_AddViewerStrings(ViewerStrings* pkStrings)
{
    TlsGuard_t guard;
    AddToViewerStrings(pkStrings);
    pkStrings->Add(CreateDebugString((const char*)DAT_012681cc));
    pkStrings->Add(m_kAdditionalRotation.GetViewerString("AdditionalRotation"));
}

extern const float DAT_01017870;
extern const float DAT_010177e8;
extern const float DAT_01018180;
extern const float DAT_01056528;

struct MotionSettings
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
    float first;
    float second;
    int mode;
    void SetPreset(int preset);
};

// Sets first, second, and mode fields from preset-specific constants based on the preset index.
// @fnv 0x00c90a60
void MotionSettings::SetPreset(int preset)
{
    switch (preset)
    {
    case 1:
        first = DAT_01017870;
        mode = 2;
        second = DAT_010177e8;
        break;
    case 2:
        first = DAT_01018180;
        mode = 2;
        second = 1.0f;
        break;
    case 3:
        mode = 2;
        first = DAT_010177e8;
        second = DAT_01056528;
        break;
    case 4:
        first = DAT_01017870;
        mode = 4;
        second = DAT_010177e8;
        break;
    case 5:
        first = DAT_01018180;
        mode = 4;
        second = 1.0f;
        break;
    case 6:
        mode = 4;
        first = DAT_010177e8;
        second = DAT_01056528;
        break;
    case 7:
        first = DAT_01017870;
        mode = 8;
        second = DAT_010177e8;
        break;
    case 8:
        first = DAT_01018180;
        mode = 8;
        second = 1.0f;
        break;
    case 9:
        mode = 8;
        first = DAT_010177e8;
        second = DAT_01056528;
        break;
    }
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

extern "C" void __cdecl enumerateAllPhantomsInWorld(void*);
extern "C" void __cdecl enumerateAllActionsInWorld(void*, void*);
extern "C" double clobber_c929e0(double);

struct FUN_00c929e0_Alloc
{
    virtual void vf00();
    virtual void* vf04(unsigned int size);
};

struct FUN_00d065e0_class
{
    void* FUN_00d065e0();
};

// src: HAVOK_LIB 0x00c927c0
static __declspec(noinline) void enumerateAllEntitiesInWorld(void* p, void* q)
{
    volatile int sink = 0;
    char* s = (char*)hkMemoryRouter_getInstance();
    if (p)
        sink = 1;
    if (q)
        sink = 2;
    clobber_c929e0(1.0);
    sink += s[0];
    if (p)
        sink = 3;
    if (q)
        sink = 4;
    if (p)
        sink = 5;
}

static __declspec(noinline) void InvokeOnAllOwners(void* a, void* b)
{
    volatile int sink = 0;
    if (a)
        sink = 1;
    clobber_c929e0(2.0);
    if (a)
        sink = 2;
    if (b)
        sink = 3;
}

class FUN_00c929e0_ThisClass
{
  public:
    void* hkpWorld_getWorldAsOneSystem();
};

// Allocates 0x44 bytes from the holder's allocator, sets its size field, constructs it via FUN_00d065e0, runs setup calls with this, and returns it.
// @fnv 0x00c929e0
// src: HAVOK_LIB 0x00c929e0
void* FUN_00c929e0_ThisClass::hkpWorld_getWorldAsOneSystem()
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    FUN_00c929e0_Alloc* alloc = *(FUN_00c929e0_Alloc**)((char*)holder + 0x10);
    void* b = alloc->vf04(0x44);
    *(unsigned short*)((char*)b + 4) = 0x44;
    void* ret = ((FUN_00d065e0_class*)b)->FUN_00d065e0();
    enumerateAllEntitiesInWorld(ret, ret);
    enumerateAllPhantomsInWorld(ret);
    InvokeOnAllOwners(this, ret);
    enumerateAllActionsInWorld(this, ret);
    return ret;
}

struct SmartC9
{
    NiRefObject* pointer;
    SmartC9(NiRefObject* p = 0) : pointer(p)
    {
        if (pointer)
            pointer->IncRefCount();
    }
    SmartC9(const SmartC9& other) : pointer(other.pointer)
    {
        if (pointer)
            pointer->IncRefCount();
    }
    ~SmartC9()
    {
        if (pointer)
            pointer->DecRefCount();
    }
    SmartC9& operator=(const SmartC9& other)
    {
        if (pointer != other.pointer)
        {
            if (pointer)
                pointer->DecRefCount();
            pointer = other.pointer;
            if (pointer)
                pointer->IncRefCount();
        }
        return *this;
    }
};
struct ListC9
{
    SmartC9 item;
    ListC9* next;
    ListC9(const SmartC9& p) : item(p), next(0)
    {}
// src: XBOX_PDB 0x00631540
    __declspec(noinline) void BSSimpleList_NiPointer_bhkAction_AddHead(const SmartC9& p)
    {
        if (!p.pointer)
            return;
        if (item.pointer)
        {
            ListC9* node = new ListC9(item);
            node->next = next;
            next = node;
        }
        item = p;
    }
};
struct OwnerC9Body
{
    int unk00, unk04, unk08;
    ListC9 list;
    void AddObject(NiRefObject* object);
};
// Adds a reference-counted object to the owner's list, wrapping it in a SmartC9 and delegating to the list's insert routine.
// @fnv 0x00c9a460
void OwnerC9Body::AddObject(NiRefObject* object)
{
    TlsGuard_t context;
    if (object)
        list.BSSimpleList_NiPointer_bhkAction_AddHead(SmartC9(object));
}

extern const float DAT_01012054;
extern const double DAT_01017a40;
struct BLENDKEY
{
    float fA;
    float fB;
    float fC;
    void Set(float a, float b, float c)
    {
        fA = a;
        fB = b;
        fC = c;
    }
    void Set3(float a, float p)
    {
        float z = (float)(p / 100.0);
        fA = a;
        fB = z;
        fC = z;
    }
};
static inline float Pct(float f)
{
    return (float)(f / 100.0);
}
static inline float Pct2(int f)
{
    return (float)(f / 100.0);
}


// Resets all entries to (-1, 0, 0) and zeroes the count and allocated capacity.
// @fnv 0x00c9a6e0
// src: GUESS 0x00c9a6e0 (confidence: medium)
void BlendKeyArrayReset::ResetEntriesAndCapacity()
{
    for (unsigned int i = 0; i < m_uiSize; i++)
    {
        float fZero = Pct(0.0f);
        m_pBase[i].Set(-1.0f, fZero, fZero);
    }
    m_uiSize = 0;
    m_uiESize = 0;
}

namespace fnv_00c9a730 {
extern float DAT_01012054;
extern double DAT_01017a40;

class FNVVec3Elem
{
  public:
    bool Helper660(float* out);
    bool Helper620(float* out);
    float m_uiX;
    float m_uiY;
    float m_uiZ;
};

class FNVVec3Range
{
  public:
    void* unk00;
    FNVVec3Elem* m_pBase;
    unsigned int unk08;
    unsigned int m_uiSize;
    int m_iArrayLength;
    void SetElement(unsigned int index, FNVVec3Elem* v);
};

// @fnv 0x00c9a730
void FNVVec3Range::SetElement(unsigned int index, FNVVec3Elem* apElem)
{
    FNVVec3Elem dir;
    dir.m_uiX = DAT_01012054;
    double rest = 0.0 / DAT_01017a40;
    if (index >= m_uiSize)
    {
        float r = (float)rest;
        dir.m_uiY = r;
        dir.m_uiZ = r;
        m_uiSize = index + 1;
        if (apElem->Helper660((float*)&dir))
            m_iArrayLength++;
    }
    else
    {
        float t = (float)rest;
        dir.m_uiY = t;
        dir.m_uiZ = t;
        bool ok = apElem->Helper660((float*)&dir);
        dir.m_uiX = DAT_01012054;
        float u = (float)rest;
        dir.m_uiY = u;
        dir.m_uiZ = u;
        if (ok)
        {
            if (m_pBase[index].Helper620((float*)&dir))
                m_iArrayLength++;
        }
        else
        {
            if (m_pBase[index].Helper660((float*)&dir))
                m_iArrayLength--;
        }
    }
    FNVVec3Elem* dst = &m_pBase[index];
    dst->m_uiX = apElem->m_uiX;
    dst->m_uiY = apElem->m_uiY;
    dst->m_uiZ = apElem->m_uiZ;
}
}  // namespace fnv_00c9a730

float __cdecl NiInterpScalar_Linear(float t, float a, float b);
struct KeyPair
{
    float time;
    float first;
    float second;
};
struct KeyPairInterpolator
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    int unk1C, unk20, unk24, unk28, unk2C, unk30;
    unsigned int lastIndex;
    int unk38;
    KeyPair* keys;
    int unk40, unk44;
    unsigned int count;
    bool Interpolate(float time, float& first, float& second);
};
// Finds the keys bracketing time, advancing a cached index, and interpolates first and second between them via FUN_00a42050; returns false if there are no keys.
// @fnv 0x00c9a8c0
bool KeyPairInterpolator::Interpolate(float time, float& first, float& second)
{
    if (count)
    {
        if (count == 1)
        {
            first = keys[0].first;
            second = keys[0].second;
            return true;
        }
        unsigned int last = count - 1;
        float previousTime = keys[lastIndex].time;
        if (time < previousTime)
        {
            lastIndex = 0;
            previousTime = keys[0].time;
        }
        float nextTime = previousTime;
        unsigned int next;
        next = lastIndex + 1;
        __assume(next <= last);
        for (; next <= last; ++next)
        {
            nextTime = keys[next].time;
            if (time <= nextTime)
                break;
            ++lastIndex;
            previousTime = nextTime;
        }
        float delta = nextTime - previousTime;
        float firstValue = keys[lastIndex].first;
        float secondValue = keys[lastIndex].second;
        if (delta != 0.0f)
        {
            float ratio = (time - previousTime) / delta;
            float nextFirst = keys[next].first;
            first = NiInterpScalar_Linear(ratio, firstValue, nextFirst);
            float nextSecond = keys[next].second;
            second = NiInterpScalar_Linear(ratio, secondValue, nextSecond);
        }
        else
        {
            first = firstValue;
            second = secondValue;
        }
        return true;
    }
    return false;
}

extern __declspec(thread) int DAT_012722b4;

struct TlsGuardS00c9_t
{
    int m_saved;

    TlsGuardS00c9_t()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }

    ~TlsGuardS00c9_t()
    {
        DAT_012722b4 = m_saved;
    }
};

struct HeldSub_t
{
    void* NiObjectNET_GetController(const void* key);
    void NiObjectNET_RemoveController(void* entry);
};

struct S00c9ade0_Obj
{
    int unk00;
    int unk04;
    unsigned char m_08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    HeldSub_t* m_2c;

    bool bhkBlendController_ClearForceController();
};

extern int DAT_012683f4;

// If the high bit of m_08 is set, look up DAT_012683f4 in m_2c and call FUN_00a5c480 on the found entry, returning true on success.
// @fnv 0x00c9ade0
// src: XBOX_PDB 0x00c9ade0
bool S00c9ade0_Obj::bhkBlendController_ClearForceController()
{
    TlsGuardS00c9_t guard;
    bool result = false;
    unsigned char flag = m_08 >> 7;
    unsigned char keep = flag;
    if ((flag & keep & 1) != 0)
    {
        HeldSub_t* sub = m_2c;
        void* entry = sub->NiObjectNET_GetController(&DAT_012683f4);
        if (entry)
        {
            sub->NiObjectNET_RemoveController(entry);
            result = true;
        }
    }
    return result;
}

// @fnv 0x00c9e3e0
// src: GUESS 0x00c9e3e0 (confidence: low)
void __cdecl Object_ComputeValue_00c9e3e0(void)
{
    return;
}

#include <stdlib.h>
__declspec(noinline) bool __fastcall FilterHasSelectedLayer(bhkFilter* filter);

extern unsigned __int64 selected_target_masks[];

extern unsigned int DAT_01268078[];

__forceinline bool Mask135(unsigned int a, unsigned int b)
{
    return (DAT_01268078[(a >> 8) & 31] & (1 << ((b >> 8) & 31))) != 0;
}

// Returns whether values a and b pass a check using their low 7 layer bits, flag bits, and Mask135 or selected_target_masks lookups.
// @fnv 0x00c84740
// src: XBOX_PDB 0x00c84740
bool bhkCollisionFilter_IsCollisionEnabled(unsigned int a, unsigned int b)
{

    unsigned int cachedA = a;

    unsigned int cachedB = b;

    unsigned int layerA = cachedA & 0x7f;

    if (layerA != 40 && (((unsigned char)(cachedA >> 14) & 1) || ((unsigned char)(cachedB >> 14) & 1)))
        return false;

    if (!(cachedA & 0xffff0000) || !(cachedB & 0xffff0000))
        return true;

    unsigned int different = (cachedA ^ cachedB) & 0xffff0000;

    unsigned int layerB = cachedB & 0x7f;

    if (layerA == 8 && layerB == layerA && !different)
    {

        return Mask135(cachedA, cachedB);
    }

    if (layerA == 8 && layerB == layerA)
        return false;
    if (different)
        return (selected_target_masks[layerA] & (1ULL << layerB)) != 0;

    if ((cachedA & cachedB) & 0x8000)
    {

        if (!(selected_target_masks[layerA] & (1ULL << layerB)))
            return false;

        return abs(int((cachedA >> 8) & 31) - int((cachedB >> 8) & 31)) != 1;
    }

    if (!FilterHasSelectedLayer((bhkFilter*)&a) || !FilterHasSelectedLayer((bhkFilter*)&b))
        return false;

    return Mask135(cachedA, cachedB);
}

__declspec(noinline) bool __fastcall FilterHasSelectedLayer(bhkFilter* filter)
{
    unsigned int layer = filter->value & 127;
    return layer == 8 || layer == 29;
}

// @fnv 0x00c85d20
struct B0
{
    int a, b, c, d;
};
struct F
{
    unsigned a, b, c, d, e, f, g, bits;
};
struct O : B0, F
{
};
unsigned Apply(unsigned bits, char on)
{
    if (on == 0)
        bits |= 0x4000u;
    else
        bits &= ~0x4000u;
    return bits;
}
struct C
{
    void** vt;
    int x;
    O* object;
    void bhkWorldObject_EnableCollision(char active);
};
// src: XBOX_PDB 0x00c85d20
void C::bhkWorldObject_EnableCollision(char active)
{
    O* item = object;
    F* part = item;
    unsigned bits = part ? part->bits : 0;
    bits = Apply(bits, active);
    part = item;
    if (part)
        part->bits = bits;
    typedef void(__thiscall * Fn)(C*);
    ((Fn*)vt)[49](this);
}

extern "C" unsigned long __readfsdword(unsigned long);
extern volatile unsigned long DAT_0126fd98;

struct MemoryCategoryScope_00c89dd0
{
    int previous;
    MemoryCategoryScope_00c89dd0(int* block) : previous(block[0x2b4 / 4])
    {
        block[0x2b4 / 4] = 16;
    }
    ~MemoryCategoryScope_00c89dd0()
    {
        previous = 0;
    }
};

struct PendingAllocation_00c89dd0
{
    void* pointer;
    PendingAllocation_00c89dd0(void* value) : pointer(value)
    {}
    ~PendingAllocation_00c89dd0()
    {
        pointer = 0;
    }
};

struct Allocator_00c89dd0
{
    virtual void reserved();
    virtual void* allocate(unsigned int bytes);
};
hkMemoryRouter* hkMemoryRouter_getInstance();

struct CloneData_00c89dd0
{
    int unknown00;
    void* first;
    void* second;
    void* third;
    void* fourth;
};
struct Instance_00c89dd0
{
    Instance_00c89dd0* FUN_00cf3ea0(void* first, void* second, void* third, void* fourth);
};
struct RefCounted_00c89dd0
{
    void FUN_00c905b0();
};
struct Dispatch_00c89dd0
{
    virtual void reserved00();
    virtual void reserved01();
    virtual void reserved02();
    virtual void reserved03();
    virtual void reserved04();
    virtual void reserved05();
    virtual void reserved06();
    virtual void reserved07();
    virtual void reserved08();
    virtual void reserved09();
    virtual void VirtualFunction10();
    virtual void ReplaceImpactData();
    virtual void reserved12();
    virtual void VirtualFunction13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void reserved18();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void VirtualFunction22();
    virtual void VirtualFunction23();
    virtual void VirtualFunction24();
    virtual void VirtualFunction25();
    virtual void VirtualFunction26();
    virtual void VirtualFunction27();
    virtual void VirtualFunction28();
    virtual void VirtualFunction29();
    virtual void reserved30();
    virtual void reserved31();
    virtual void reserved32();
    virtual void reserved33();
    virtual void reserved34();
    virtual void attach(Instance_00c89dd0*);
    virtual void reserved36();
    virtual void reserved37();
    virtual void reserved38();
    virtual void reserved39();
    virtual void reserved40();
    virtual void reserved41();
    virtual void reserved42();
    virtual void reserved43();
    virtual void reserved44();
    virtual void reserved45();
    virtual void reserved46();
    virtual void finish(int);
    void SpawnAndAttach(int data);
};

// Allocates an instance from CloneData, attaches it to the dispatch, releases the refcount, and calls finish with the original data.
// @fnv 0x00c89dd0
void Dispatch_00c89dd0::SpawnAndAttach(int data)
{
    Dispatch_00c89dd0* owner = this;
    unsigned int slot = DAT_0126fd98;
    int* block = (int*)((void**)__readfsdword(0x2c))[slot];
    MemoryCategoryScope_00c89dd0 memoryScope(block);
    CloneData_00c89dd0* clone = data ? (CloneData_00c89dd0*)(data - 4) : 0;
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    Allocator_00c89dd0* allocator = (Allocator_00c89dd0*)holder->m_heap;
    void* memory = allocator->allocate(0x38);
    *(unsigned short*)((char*)memory + 4) = 0x38;
    Instance_00c89dd0* instance;
    {
        PendingAllocation_00c89dd0 pending(memory);
        void* argFourth = clone->fourth;
        void* argFirst = clone->third;
        void* argLast = clone->second;
        void* argThird = clone->first;
        instance = ((Instance_00c89dd0*)memory)->FUN_00cf3ea0(argFirst, argFourth, argThird, argLast);
    }
    owner->attach(instance);
    ((RefCounted_00c89dd0*)instance)->FUN_00c905b0();
    owner->finish(data);
    block[0x2b4 / 4] = memoryScope.previous;
}

#include <string.h>
struct FUN_00c90030_Matrix
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
};

struct FUN_00c90030_Transform
{
    void* __thiscall FUN_0043f8d0(void* a, void* b, void* c, void* d);
};

struct FUN_00c90030_Result
{
    void* __thiscall FUN_0043f8d0();
};

struct FUN_00c90030_Outer
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
    FUN_00c90030_Transform unk68;
};

struct FUN_00c90030_Source
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

    void __thiscall FUN_00a68bf0();
};

struct FUN_00c90030_holder
{
    void* unk00;
    void* unk04;
    FUN_00c90030_Source* unk08;
    void* unk0C;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    FUN_00c90030_Matrix unk2C;

    void __thiscall UpdateNodeState(int value);
    void __thiscall bhkBlendCollisionObjectAddRotation_UpdateWorldData(int value);
};

// If unk10 is set, calls UpdateNodeState; otherwise calls FUN_00a68bf0 on unk08, then computes a transform and copies 9 ints into source at offset 0x68.
// @fnv 0x00c90030
// src: XBOX_PDB 0x00c90030
void __thiscall FUN_00c90030_holder::bhkBlendCollisionObjectAddRotation_UpdateWorldData(int aiState)
{
    FUN_00c90030_Matrix local00;
    FUN_00c90030_Matrix local24;

    if (unk10 != 0)
    {
        UpdateNodeState(aiState);
    }
    else if (unk08 != 0)
    {
        unk08->FUN_00a68bf0();
    }

    FUN_00c90030_Source* source = unk08;
    FUN_00c90030_Outer* outer = *reinterpret_cast<FUN_00c90030_Outer**>(reinterpret_cast<char*>(source) + 0x18);

    void* result = outer->unk68.FUN_0043f8d0(&local24, reinterpret_cast<char*>(source) + 0x34, &local00, &unk2C);

    FUN_00c90030_Result* resultObject = reinterpret_cast<FUN_00c90030_Result*>(result);

    void* matrix = resultObject->FUN_0043f8d0();

    memcpy(reinterpret_cast<char*>(source) + 0x68, matrix, 9 * sizeof(int));
}

extern char DAT_010c6b0c[];

void* __cdecl NiMalloc(unsigned int size);

template <class T, class TAlloc> inline NiTLargeArray<T, TAlloc>::NiTLargeArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    m_uiMaxSize = uiMaxSize;
    m_uiGrowBy = uiGrowBy;
    m_uiSize = 0;
    m_uiESize = 0;
    if (m_uiMaxSize > 0)
        m_pBase = (T*)NiMalloc(sizeof(T) * m_uiMaxSize);
    else
        m_pBase = 0;
}

template <class T> inline NiTLargePrimitiveArray<T>::NiTLargePrimitiveArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
    : NiTLargeArray<T, NiTMallocInterface<T> >(uiMaxSize, uiGrowBy)
{
}

struct BaseC9
{
    virtual void v00();
    int unk04[0xc];
    BaseC9();
    ~BaseC9();
};

struct FUN_00c9aeb0 : BaseC9
{
    int unk34;
    NiTLargePrimitiveArray<BLENDKEY> m_kArray;
    float unk50;
    float unk54;
    int unk58;

    virtual void v00();
    FUN_00c9aeb0();
};

// Initializes the FUN_00c9aeb0 object by zeroing unk34, setting unk50 and unk54 to -1.0f, and zeroing unk58.
// @fnv 0x00c9aeb0
FUN_00c9aeb0::FUN_00c9aeb0()
{
    unk34 = 0;
    unk50 = -1.0f;
    unk54 = -1.0f;
    unk58 = 0;
}

extern int DAT_011f4428;

struct S00c81c50_Obj;
struct S00c81c50_Arr
{
    S00c81c50_Obj** data;
    unsigned short cap;
    unsigned short size;
    unsigned short esize;
    unsigned short grow;
    unsigned short GetSize() const
    {
        return size;
    }
    S00c81c50_Obj* GetAt(unsigned int i) const
    {
        return data[i];
    }
};

struct S00c81c50_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S00c81c50_Obj* IsSceneNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S00c81c50_Obj* collision;
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
    S00c81c50_Arr children;

    S00c81c50_Obj* FUN_00653290(int* rtti);

    __forceinline S00c81c50_Obj* GetCollision()
    {
        S00c81c50_Obj* c = collision;
        if (!c)
            return 0;
        return c->FUN_00653290(&DAT_01267e64);
    }
    __forceinline S00c81c50_Obj* FirstNode()
    {
        S00c81c50_Obj* c = children.size > 0 ? children.data[0] : 0;
        if (!c)
            return 0;
        return c->FUN_00653290(&DAT_011f4428);
    }
};

struct S00c81c50_Ptr
{
    S00c81c50_Obj* m_p;
    S00c81c50_Ptr(S00c81c50_Obj* p) : m_p(p)
    {}
    S00c81c50_Ptr& operator=(S00c81c50_Obj* p)
    {
        m_p = p;
        return *this;
    }
    operator S00c81c50_Obj*() const
    {
        return m_p;
    }
};

// Returns pkNode's collision object, else searches its first node, a child chosen by esize, and that child's children for one; returns null if none.
// @fnv 0x00c81c50
// src: XBOX_PDB 0x00c81c50
void* __cdecl bhkBlendCollisionObject_GetFirstCollisionObject(S00c81c50_Obj* pkNode)
{
    S00c81c50_Ptr pkResult = 0;
    if (pkNode)
    {
        pkResult = pkNode->GetCollision();
        if (!pkResult)
        {
            S00c81c50_Obj* pkParent = pkNode;
            pkNode = pkParent->FirstNode();
            if (pkNode)
                pkResult = pkNode->GetCollision();
            if (!pkResult)
            {
                pkNode = pkParent->FirstNode();
                if (pkNode)
                    pkResult = pkNode->GetCollision();
            }
            if (!pkNode)
                pkNode = pkParent;
            if (!pkResult)
            {
                unsigned int idx = pkNode->children.esize != 1;
                if (pkNode->children.size > idx)
                {
                    pkNode = pkNode->children.data[idx];
                    if (pkNode)
                    {
                        pkResult = pkNode->GetCollision();
                        if (!pkResult)
                        {
                            S00c81c50_Obj* pkNodeNode = pkNode->IsSceneNode();
                            if (pkNodeNode)
                            {
                                for (unsigned int i = 0; i < pkNodeNode->children.GetSize(); i++)
                                {
                                    pkResult = pkNodeNode->children.data[i]->GetCollision();
                                    if (pkResult)
                                        break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return pkResult;
}

struct C8AB30_Sub
{
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c();
    virtual void v20(), v24(), v28(), v2c(), v30(), v34(), v38(), v3c();
    virtual void v40(), v44(), v48(), v4c(), v50(), v54(), v58(), v5c();
    virtual void v60(), v64(), v68(), v6c(), v70(), v74(), v78(), v7c();
    virtual void v80(), v84(), v88(), v8c(), v90(), v94(), v98();
    virtual bool v9c(int a);
};

struct C8AB30_Mid
{
    int unk00;
    int unk04;
    int unk08;
    C8AB30_Sub* m_0c;
};

struct C8AB30_Ref
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    C8AB30_Mid* m_1c;
};

struct C8AB30_Cls
{
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c();
    virtual void v20(), v24(), v28(), v2c(), v30(), v34(), v38(), v3c();
    virtual void v40(), v44(), v48(), v4c(), v50(), v54(), v58(), v5c();
    virtual void v60(), v64(), v68(), v6c(), v70(), v74(), v78(), v7c();
    virtual void v80(), v84(), v88(), v8c(), v90(), v94(), v98(), v9c();
    virtual void vA0();

    int unk04;
    C8AB30_Ref* m_08;

    bool bhkAction_Add(int a);
    bool bhkBinaryAction_Add(int a);
};

// For nonzero a, returns FUN_00c87a70(a) unless the sub-object's v9c(a) fails; for zero a, calls vA0() and returns false (requires this and m_08).
// @fnv 0x00c8ab30
// src: XBOX_PDB 0x00c8ab30
bool C8AB30_Cls::bhkBinaryAction_Add(int a)
{
    TlsGuard_t kGuard;
    bool bResult = false;
    if (this != 0 && m_08 != 0)
    {
        if (a != 0)
        {
            C8AB30_Ref* pRef = m_08;
            _ReadWriteBarrier();
            C8AB30_Mid* pMid = pRef ? pRef->m_1c : 0;
            _ReadWriteBarrier();
            bool bSubOk = true;
            if (pMid != 0)
            {
                C8AB30_Sub* pSub = pMid->m_0c;
                if (pSub != 0)
                    bSubOk = pSub->v9c(a);
            }
            if (bSubOk)
                bResult = bhkAction_Add(a);
        }
        else
        {
            vA0();
        }
    }
    return bResult;
}

extern float DAT_010c7948[];

struct Z577
{
    unsigned char index;
    void __thiscall FindFloatTableIndex(float* value);
};

struct Y577
{
    unsigned char unk00[0xbd];
    Z577 z;
};

struct A577
{
    Y577* __thiscall hkpRigidBody_getStoredDynamicMotion_00ca86c0();
    unsigned char unk00[0x19d];
    unsigned char unk19d;
};

struct S_00c8cd20_object
{
    unsigned int unk00;
    unsigned int unk04;
    A577* unk08;

    float __thiscall GetFloatValue();
};

// Returns the DAT_010c7948 entry for a Z577's index (from the owner's FUN_00ca86c0 result, or a local one filled via FUN_00ca9360), else 0.0.
// @fnv 0x00c8cd20
float __thiscall S_00c8cd20_object::GetFloatValue()
{
    volatile float ret;
    if (this && this->unk08)
    {
        A577* owner = this->unk08;
        Y577* result = owner->hkpRigidBody_getStoredDynamicMotion_00ca86c0();
        Z577* z;
        Z577 local_z;
        if (result)
        {
            z = &result->z;
        }
        else
        {
            ret = DAT_010c7948[owner->unk19d];
            local_z.FindFloatTableIndex((float*)&ret);
            z = &local_z;
        }
        ret = DAT_010c7948[z->index];
        return ret;
    }
    ret = 0.0f;
    return ret;
}

extern __declspec(thread) int g_tlsMemContext;

struct S00c89ec0_Scope
{
    int saved;
    S00c89ec0_Scope()
    {
        saved = g_tlsMemContext;
        g_tlsMemContext = 0x10;
    }
    ~S00c89ec0_Scope()
    {
        g_tlsMemContext = saved;
    }
};

struct S00c89ec0_Res
{
    bool bhkWorld_Remove_00c68d50(int key);
};

struct S00c89ec0_Owner
{
    int unk00;
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
    S00c89ec0_Res* unk350;
    S00c89ec0_Res* GetRes()
    {
        return unk350;
    }
};

struct S00c89ec0_cls
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
    virtual S00c89ec0_Owner* getOwner();
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
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void process(S00c89ec0_Res* r, int flag);
    int unk04;
    int unk08;
    bool bhkConstraint_Remove();
};

// Gets the owner's resource; if present, calls FUN_00c68d50 on it with unk08, then process(res, 0), and returns FUN_00c68d50's result, else false.
// @fnv 0x00c89ec0
// src: XBOX_PDB 0x00c89ec0
bool S00c89ec0_cls::bhkConstraint_Remove()
{
    S00c89ec0_Scope scope;
    S00c89ec0_Owner* owner = getOwner();
    S00c89ec0_Res* res = owner ? owner->GetRes() : 0;
    if (res)
    {
        bool r = res->bhkWorld_Remove_00c68d50(unk08);
        process(res, 0);
        return r;
    }
    return false;
}

__declspec(noinline) int __stdcall bhkShape_CanShare(void* apObject);

struct ShareChildShape
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
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
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual bool V52(int a1);
};

struct ShareChildObject
{
    int unk0;
    int unk4;
    ShareChildShape* shape;
};

class ListShapeSharingView : public ListShapeViewer
{
  public:
    __forceinline hkpListShape* GetNode()
    {
        return this != 0 ? (hkpListShape*)m_pHavokObject : 0;
    }

    unsigned char bhkListShape_CanShare(int a1);
};

// Returns FUN_00c84ec0(a1) ANDed with V52(a1) of each non-null child shape in the list, stopping early once the result is zero.
// @fnv 0x00c8b440
// src: XBOX_PDB 0x00c8b440
unsigned char ListShapeSharingView::bhkListShape_CanShare(int a1)
{
    unsigned char result = (unsigned char)::bhkShape_CanShare((void*)a1);
    while (true)
    {
        if (result == 0)
        {
            break;
        }
        int count;
        if (hkpListShape* pNode = GetNode())
        {
            count = static_cast<hkpShapeContainer*>(pNode)->GetNumChildShapes();
        }
        else
        {
            count = 0;
        }
        int i = 0;
        do
        {
            if (i >= count)
            {
                break;
            }
            if (hkpListShape* pNode = GetNode())
            {
                ShareChildObject* pObj = reinterpret_cast<ShareChildObject*>(const_cast<hkpShape*>(pNode->m_kChildInfoList.m_data[i].m_pCollisionShape));
                if (pObj != 0)
                {
                    ShareChildShape* q = pObj->shape;
                    if (q != 0)
                    {
                        result &= (unsigned char)q->V52(a1);
                    }
                }
            }
            i++;
        } while (result != 0);
        break;
    }
    return result;
}

struct c9b090_material
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    float first, second;
};
struct c9b090_owner
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    NiObject* helper;
};
struct Target_c9b090
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
    virtual float compute(float);
    unsigned int unk04;
    unsigned short flags, unk0a;
    unsigned int unk0c, unk10, unk14;
    float time;
    unsigned int unk1c;
    float lastTime;
    unsigned int unk24, unk28;
    c9b090_owner* object;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44;
    void* data;
    unsigned int unk4c;
    float savedFirst, savedSecond;
    bool IsActive() const
    {
        return (flags >> 3) & 1;
    }
    bool MustReset() const
    {
        return (flags >> 6) & 1;
    }
    void bhkBlendController_Update(float* input);
};
// @fnv 0x00c9b090
// src: XBOX_PDB 0x00c9b090
void Target_c9b090::bhkBlendController_Update(float* apTime)
{
    if (!object || !IsActive() || !data)
        return;
    if (object->helper)
    {
        c9b090_material* mat = (c9b090_material*)object->helper->DynamicCast((unsigned int const*)&DAT_01267e64);
        if (mat)
        {
            float value = compute(*apTime);
            float first, second;
            if (((KeyPairInterpolator*)this)->Interpolate(value, first, second))
            {
                if (savedFirst < 0.0f)
                {
                    savedFirst = mat->first;
                    savedSecond = mat->second;
                }
                mat->first = first;
                mat->second = second;
            }
            if (value == time && (flags & 6) == 4)
            {
                if (MustReset())
                    ((FUN_00c9a820_class*)this)->Reset();
                ((S00c9ade0_Obj*)this)->bhkBlendController_ClearForceController();
                ((FUN_00c9abc0_cls*)this)->bhkBlendController_RestoreOriginalGains((int)mat);
                v90();
            }
            return;
        }
    }
    lastTime = *apTime;
}
