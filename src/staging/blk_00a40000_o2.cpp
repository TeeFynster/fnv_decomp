#include "../../include/NiTArray.h"
// staging/blk_00a40000_o2.cpp: Owner, Controller, Arr, ExtraOwner and more (111 functions)

#include <string.h>
// src/staging/blk_00a40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include <stddef.h>
#include "../../include/MemoryManager.h"
#include "../../include/NiRTTI.h"
#include "../../include/AnimIdle.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/NP.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiGPUProgram.h"
#include "../../include/NiObject.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiPointer.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiSequence.h"
#include "../../include/NiStream.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/NiTStringTemplateMap.h"
#include "../../include/NiTexture.h"
#include "../../include/NiTexturingProperty.h"
#include "../../include/NiVBSet.h"

class NiNode;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiPointer<NiSequence> > SequenceMapBase;
typedef NiTPointerMap<const char*, NiPointer<NiSequence> > SequencePointerMap;
typedef NiTStringTemplateMap<SequencePointerMap, NiPointer<NiSequence> > SequenceStringMap;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, NiNode*, unsigned int> NodeMapBase;
typedef NiTPointerMap<NiNode*, unsigned int> NodePointerMap;

// Preserve the container operations that were inline in this unit.
template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer<T>& kSrc) : m_pObject(kSrc.m_pObject)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}
template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

#include "../../include/NiTMapItem.h"
#include "../../include/NiTListItem.h"


extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

inline void NiRefObject::IncRefCount() { InterlockedIncrement((volatile long*)&m_uiRefCount); }
inline void NiRefObject::DecRefCount() { if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0) DeleteThis(); }
inline void NiGPUProgram::IncRefCount() throw() { InterlockedIncrement((volatile long*)&m_uiRefCount); }
inline void NiGPUProgram::DecRefCount() throw() { if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0) DeleteThis(); }
inline void AnimIdle::IncRefCount() { InterlockedIncrement((volatile long*)&m_uiRefCount); }
inline void AnimIdle::DecRefCount() { if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0) DeleteThis(); }
inline void NiBinaryStream::ReadGroupId(unsigned int* id)
{
    unsigned int length = 4;
    unsigned int& position = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4);
    position += (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 8))(this, id, 4, &length, 1);
}

extern "C" void __cdecl _ReadWriteBarrier(void);
__forceinline NP::~NP()
{
    NiRefObject* object = static_cast<NiRefObject*>(p);
    _ReadWriteBarrier();
    if (object)
    {
        if (InterlockedDecrement((volatile long*)&object->m_uiRefCount) == 0)
            object->DeleteThis();
    }
}

extern "C" void __fastcall NiBlendInterpolator_NiBlendInterpolator(void*);
extern int DAT_0109750c;
struct FUN_00a409b0_class
{
    void* vtbl;
    FUN_00a409b0_class();
};
// @fnv 0x00a409b0
FUN_00a409b0_class::FUN_00a409b0_class()
{
    NiBlendInterpolator_NiBlendInterpolator(this);
    vtbl = (void*)&DAT_0109750c;
}

void __fastcall NiBlendInterpolator_NiBlendInterpolator(void*);

// @fnv 0x00a409d0
// src: EXE 0x00a409d0
void* __cdecl NiBlendTransformInterpolator_CreateObject()
{
    void* p = NiObject::operator new(0x30);
    if (p)
    {
        NiBlendInterpolator_NiBlendInterpolator(p);
        *(void**)p = (void*)0x0109750c;
        return p;
    }
    return 0;
}

namespace fnv_00a411f0 {
int* __fastcall InitTimeController(int*);
extern int DAT_010975fc;

// Allocates a 0x40-byte BSFadeNode, initialises it via InitTimeController, sets its vtable to DAT_010975fc and returns it, or returns 0 on allocation failure.
// @fnv 0x00a411f0
// src: EXE 0x00a411f0
int* __cdecl NiFloatExtraDataController_CreateObject()
{
    int* p = static_cast<int*>(NiObject::operator new(0x40));
    if (p)
    {
        InitTimeController(p);
        *p = reinterpret_cast<int>(&DAT_010975fc);
        return p;
    }
    return 0;
}
}  // namespace fnv_00a411f0

// @fnv 0x00a42050
// src: GAMEBRYO_LIB 0x00a42050
float NiInterpScalar_Linear(float afT, float afFrom, float afTo)
{
    return afFrom * (1.0f - afT) + afTo * afT;
}

void __fastcall NiBlendInterpolator_NiBlendInterpolator(void*);
extern int DAT_01097904;

struct FUN_00a42f60
{
    void* m_pVTable;
    char m_auiShapeKeys[0x2C];
    float m_f;
    FUN_00a42f60();
};

// @fnv 0x00a42f60
FUN_00a42f60::FUN_00a42f60()
{
    NiBlendInterpolator_NiBlendInterpolator(this);
    m_f = 0.0f;
    m_pVTable = &DAT_01097904;
}

struct CloningProcess;

struct FUN_00a44850_holder : NiObject
{
    void* m_p;
    float m_f;
    void CopyMembersStreamAndFields(FUN_00a44850_holder* dst, CloningProcess* proc);
};
// Copies the stream members via CopyMembersStream, then copies m_p and m_f into dst.
// @fnv 0x00a44850
void FUN_00a44850_holder::CopyMembersStreamAndFields(FUN_00a44850_holder* dst, CloningProcess* proc)
{
    CopyMembersStream((unsigned int)dst, proc);
    dst->m_p = m_p;
    dst->m_f = m_f;
}

extern MemoryManager g_memoryManager;

void __cdecl NiFreeA4D(void* pvMem) throw();

template <> void SequenceMapBase::RemoveAll() throw();
template <> void NodeMapBase::RemoveAll() throw();

template <> __forceinline SequenceMapBase::~NiTMapBase()
{
    RemoveAll();
    NiFreeA4D(m_ppkHashTable);
}

template <> __forceinline SequencePointerMap::~NiTPointerMap()
{
    RemoveAll();
}

// Scalar-deleting entry points use ECX for the shared object and pop the flags argument.
// @fnv 0x00a4da00
void* __fastcall DeleteSequenceStringMap(SequenceStringMap* map, void*, int aiFlags)
{
    map->SequenceStringMap::~NiTStringTemplateMap();
    if (aiFlags & 1)
        g_memoryManager.Deallocate(map);
    return map;
}

void __fastcall FUN_00a57f80(void*);
void __cdecl _delete(void*, unsigned int);

struct FUN_00a51af0_class
{
    void* __thiscall FUN_00a51af0(unsigned char flags);
};

// Calls FUN_00a57f80 on this, then frees this with _delete when bit 0 of flags is set, and returns this.
// @fnv 0x00a51af0
void* __thiscall FUN_00a51af0_class::FUN_00a51af0(unsigned char flags)
{
    FUN_00a57f80(this);
    if (flags & 1)
        _delete(this, 0x34);
    return this;
}

void __cdecl NiFreeAlias(void*) throw();
template <> inline NodeMapBase::~NiTMapBase()
{
    RemoveAll();
    NiFreeAlias(m_ppkHashTable);
}

// @fnv 0x00a540a0
template <> NodePointerMap::~NiTPointerMap()
{
    RemoveAll();
}

extern "C" char* __cdecl _strcat_s(char* destination, unsigned int destinationSize, const char* source);

// @fnv 0x00a574e0
char* __cdecl SafeStrcat(char* destination, unsigned int destinationSize, const char* source)
{
    _strcat_s(destination, destinationSize, source);
    return destination;
}

extern const char* _EmptyFS;

struct FUN_00a57870_Class
{
    int m_iWordAt00;
    const char* m_cByteAtOffset1;
    void ReleaseString();
};

// @fnv 0x00a57870
void FUN_00a57870_Class::ReleaseString()
{
    if (m_cByteAtOffset1 != _EmptyFS)
        InterlockedDecrement((long*)(m_cByteAtOffset1 - 8));
}

// Allocates a 0x34-byte BSFadeNode, runs FUN_00a36890 on it, zeroes the float at offset 0x30, sets its vtable, and returns it (or null).
// @fnv 0x00a42f90
// src: EXE 0x00a42f90
void* __cdecl BSBlendTreadTransfInterpolator_CreateObject()
{
    void* p = NiObject::operator new(0x34);
    if (p)
    {
        NiBlendInterpolator_NiBlendInterpolator(p);
        *(float*)((char*)p + 0x30) = 0.0f;
        *(int*)p = (int)&DAT_01097904;
        return p;
    }
    return 0;
}

// @fnv 0x00a4d6d0
template <> unsigned int SequenceStringMap::KeyToHashIndex(const char* acString) const
{
    unsigned int h = 0;
    signed char c = *acString;
    while (c)
    {
        h = h * 33 + (unsigned int)(signed char)c;
        ++acString;
        c = *acString;
    }
    return h % m_uiHashSize;
}

extern "C" void NiFree(void*);
extern MemoryManager _g_memoryManager;
// @fnv 0x00a4d700
void* __fastcall DeleteSequenceMapBase(SequenceMapBase* map, void*, unsigned char flags)
{
    map->SequenceMapBase::~NiTMapBase();
    if (flags & 1)
        _g_memoryManager.Deallocate(map);
    return map;
}

extern int DAT_010997f4;
struct BaseHolder
{
    void FUN_00a57f20(int, int);
};
// Allocates a 0x24-byte BSFadeNode, initialises it via FUN_00a57f20, sets its vtable and a 0xffff field, and returns it (or null).
// @fnv 0x00a50ad0
// src: EXE 0x00a50ad0
void* __cdecl NiBSplineFloatInterpolator_CreateObject()
{
    void* p = NiObject::operator new(0x24);
    if (p)
    {
        ((BaseHolder*)p)->FUN_00a57f20(0, 0);
        *(int*)p = (int)&DAT_010997f4;
        *(int*)((char*)p + 0x20) = 0xffff;
        return p;
    }
    return 0;
}

void __fastcall _Call_a5d3a0(void*);
extern int DAT_01099e54;

// @fnv 0x00a51e10
// src: EXE 0x00a51e10
void* __cdecl NiBSplineData_CreateObject()
{
    void* p = NiObject::operator new(0x18);
    if (p)
    {
        _Call_a5d3a0(p);
        *(int*)((char*)p + 8) = 0;
        *(int*)((char*)p + 12) = 0;
        *(int*)((char*)p + 16) = 0;
        *(int*)((char*)p + 20) = 0;
        *(int*)p = (int)&DAT_01099e54;
        return p;
    }
    return 0;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl fnv_zlib_memset(void* dst, void* src, unsigned int size);

// @fnv 0x00a54060
template <> NodeMapBase::NiTMapBase(unsigned int size)
{
    m_uiHashSize = size;
    m_kItemCount.m_uiCount = 0;
    m_ppkHashTable = static_cast<EntryType**>(NiMalloc(size * 4));
    fnv_zlib_memset(m_ppkHashTable, 0, m_uiHashSize * 4);
}

// @fnv 0x00a540d0
void* __fastcall DeleteNodeMapBase(NodeMapBase* map, void*, unsigned char flags)
{
    map->NodeMapBase::~NiTMapBase();
    if (flags & 1)
        g_memoryManager.Deallocate(map);
    return map;
}

extern int DAT_0109a2a4;
extern MemoryManager g_memoryManager;
void __cdecl NiFree(void*);
struct FUN_00a54160_class
{
    void* vtbl;
    void* p;
    void* __thiscall FUN_00a54160(unsigned char flags);
};
// @fnv 0x00a54160
void* __thiscall FUN_00a54160_class::FUN_00a54160(unsigned char flags)
{
    void* old = p;
    vtbl = &DAT_0109a2a4;
    NiFree(old);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

void __cdecl NiStandardizeFilePath(NiFixedString*);
void __cdecl NiImageConverter_ConvertFilenameToPlatformSpecific_(void*, void*);

struct FUN_00a5fba0_class
{
    void __thiscall NiSourceTexture_SetFilePath(const NiFixedString* kFilename);
};
// Assigns kFilename's handle to the NiFixedString at this+0x30 with refcount updates, then calls FUN_00a57500 and FUN_00a76960 on it.
// @fnv 0x00a5fba0
// src: COMMUNITY 0x00a5fba0
void __thiscall FUN_00a5fba0_class::NiSourceTexture_SetFilePath(const NiFixedString* kFilename)
{
    const char* kHandle = kFilename->m_kHandle;
    NiFixedString* pDest = (NiFixedString*)((char*)this + 0x30);
    if (pDest->m_kHandle != kHandle)
    {
        if (kHandle != _EmptyFS)
            InterlockedIncrement((volatile long*)(kHandle - 8));
        if (pDest->m_kHandle != _EmptyFS)
            InterlockedDecrement((volatile long*)(pDest->m_kHandle - 8));
        pDest->m_kHandle = const_cast<char*>(kHandle);
    }
    NiStandardizeFilePath(pDest);
    NiImageConverter_ConvertFilenameToPlatformSpecific_(pDest, (char*)this + 0x34);
}

// Hashes the first len&~3 bytes of s four at a time with h*33+c, then hashes remaining chars until NUL, returning h % 513.
// @fnv 0x00a5b270
// src: XBOX_PDB 0x00a5b270
unsigned int __stdcall NiGlobalStringTable_HashFunction(const char* pcString, unsigned int uiLength)
{
    unsigned int h = 0;
    uiLength &= 0xfffffffc;
    if (uiLength > 0)
    {
        unsigned int count = (uiLength - 1) / 4 + 1;
        do
        {
            h = h * 33 + (unsigned int)(signed char)pcString[0];
            h = h * 33 + (unsigned int)(signed char)pcString[1];
            h = h * 33 + (unsigned int)(signed char)pcString[2];
            h = h * 33 + (unsigned int)(signed char)pcString[3];
            pcString += 4;
            --count;
        } while (count);
    }
    while (pcString[0])
    {
        h = h * 33 + (unsigned int)(signed char)pcString[0];
        pcString++;
    }
    return h % 513;
}

extern "C" unsigned int __cdecl _strcpy_s(char* dst, unsigned int size, const char* src);
void __cdecl _fnv_StandardizeFilePath(char*);
// @fnv 0x00a57500
// src: COMMUNITY 0x00a57500
void __cdecl NiStandardizeFilePath(NiFixedString* apString)
{
    char path[0x104];
    _strcpy_s(path, sizeof(path), apString->m_kHandle);
    _fnv_StandardizeFilePath(path);
    const char* old = apString->m_kHandle;
    if (old != path)
    {
        apString->m_kHandle = NiGlobalStringTable::AddString(path);
        if (old != _EmptyFS)
            InterlockedDecrement((long*)old - 2);
    }
}

extern int DAT_0109b00c;
struct FUN_004a4650_ListBase
{
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll();
};
struct FUN_00a5a390_shell
{
    void ReleaseStorage_00a5a390();
    void DestroyFogProperty();
};

// @fnv 0x00a5a390
// src: GUESS 0x00a5a390 (confidence: low)
void FUN_00a5a390_shell::ReleaseStorage_00a5a390()
{
    char* p = (char*)this;
    void* old = *(void**)(p + 0x20);
    *(void**)p = &DAT_0109b00c;
    if (old)
        _g_memoryManager.Deallocate(old);
    *(unsigned int*)(p + 0x30) &= 0xfff7ffff;
    *(void**)(p + 0x20) = 0;
    ((FUN_004a4650_ListBase*)(p + 0x24))->NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll();
    char* obj = (char*)*(void**)(p + 0x1c);
    if (obj)
    {
        if (InterlockedDecrement((long*)(obj + 4)) == 0)
            (*(void(__thiscall*)(void*))(*(void***)obj)[1])(obj);
        *(void**)(p + 0x1c) = 0;
    }
    ((FUN_004a4650_ListBase*)(p + 0x24))->NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll();
    obj = (char*)*(void**)(p + 0x1c);
    if (obj)
    {
        if (InterlockedDecrement((long*)(obj + 4)) == 0)
            (*(void(__thiscall*)(void*))(*(void***)obj)[1])(obj);
    }
    DestroyFogProperty();
}

extern char DAT_010976ec;

struct FUN_00a414c0_class
{
    void* m_pVTable;
    void* m_p;
    FUN_00a414c0_class* __thiscall FUN_00a414c0(unsigned char flags);
};

// @fnv 0x00a414c0
FUN_00a414c0_class* __thiscall FUN_00a414c0_class::FUN_00a414c0(unsigned char flags)
{
    m_pVTable = &DAT_010976ec;
    NiFree(m_p);
    if (flags & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

extern int DAT_010976fc;

struct A51BF0
{
    void* vtbl;
    int pad;
    int a;
    int b;
    int c;
    bool d;
    void FUN_00a5d3a0();
};
// @fnv 0x00a415a0
A51BF0* CreateA51BF0()
{
    A51BF0* p = (A51BF0*)NiObject::operator new(0x18);
    if (p)
    {
        p->FUN_00a5d3a0();
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = false;
        p->vtbl = (void*)&DAT_010976fc;
    }
    else
    {
        p = 0;
    }
    return p;
}

// @fnv 0x00a42070
// src: GUESS 0x00a42070 (confidence: low)
float Runtime_UpdateState_00a42070(float param_1, float param_2, float param_3, float param_4, float param_5)
{
    float fTerm1 = (param_5 + param_3) - (param_4 - param_2) * 2.0f;
    float fTerm2 = (param_4 - param_2) * 3.0f - (param_3 * 2.0f + param_5);
    return param_2 + ((param_1 * fTerm1 + fTerm2) * param_1 + param_3) * param_1;
}

struct FUN_00a44f90_class
{
    void* vtbl;
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
    float m_38;
    float m_3c;
    float m_40;
    float m_44;
    char m_48;
    char m_49;
    char m_4a;
    char m_4b;
    FUN_00a44f90_class();
};

extern int DAT_01097f84;

// @fnv 0x00a44f90
FUN_00a44f90_class::FUN_00a44f90_class()
{
    _Call_a5d3a0(this);
    m_38 = 0.0f;
    m_3c = 0.0f;
    m_08 = 0;
    m_0c = 0;
    m_40 = 1.0f;
    m_10 = 0;
    m_14 = 0;
    m_44 = 1.0f;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    m_48 = 0;
    m_49 = 0;
    m_4a = 0;
    m_4b = 0;
    vtbl = &DAT_01097f84;
}

namespace fnv_00a47f20 {

// @fnv 0x00a47f20
// src: EXE 0x00a47f20
void* NiSequence_CreateObject()
{
    NiSequence* p = static_cast<NiSequence*>(NiObject::operator new(0x34));

    if (p)
        return p->Initialize(0, 0xc, 0xc);

    return 0;
}
}  // namespace fnv_00a47f20

void __cdecl _NiFree(void*);

// @fnv 0x00a4d740
void* __fastcall DeleteSequencePointerMap(SequencePointerMap* map, void*, unsigned int flags)
{
    map->SequencePointerMap::~NiTPointerMap();
    if (flags & 1)
        _g_memoryManager.Deallocate(map);
    return map;
}

namespace fnv_00a50aa0 {
struct A51BF0Base
{
    void* __thiscall FUN_00a57fd0(void* dst, void* proc);
};
struct FUN_00a50aa0_class : A51BF0Base
{
    void NiBSplineFloatInterpolator_CopyMembers(void* dst, void* proc);
};
// Copies the base part via FUN_00a57fd0, then copies the float at offset 0x1c and the int at offset 0x20 from this into dst.
// @fnv 0x00a50aa0
// src: GAMEBRYO_LIB 0x00a50aa0
void FUN_00a50aa0_class::NiBSplineFloatInterpolator_CopyMembers(void* apDest, void* proc)
{
    FUN_00a57fd0(apDest, proc);
    *(float*)((char*)apDest + 0x1c) = *(float*)((char*)this + 0x1c);
    *(int*)((char*)apDest + 0x20) = *(int*)((char*)this + 0x20);
}
}  // namespace fnv_00a50aa0

namespace fnv_00a537f0 {
extern int DAT_0109a1d4;

struct FUN_00a5d3a0_class : NiObject
{
    int m_8;
    int m_iThirdValue;
    int m_10;
    char m_14;
};

// @fnv 0x00a537f0
// src: EXE 0x00a537f0
void* NiBoolData_CreateObject()
{
    FUN_00a5d3a0_class* p = (FUN_00a5d3a0_class*)NiObject::operator new(0x18);
    if (p)
    {
        _Call_a5d3a0(p);
        p->m_8 = 0;
        p->m_iThirdValue = 0;
        p->m_10 = 0;
        p->m_14 = 0;
        *reinterpret_cast<void**>(p) = &DAT_0109a1d4;
    }
    else
    {
        p = 0;
    }
    return p;
}
}  // namespace fnv_00a537f0

struct FUN_00a57890_shell
{
    void* m_iWordAt00;
    const char* m_cByteAtOffset1;
    void __thiscall AssignStringRef(const char** s);
};

// @fnv 0x00a57890
void __thiscall FUN_00a57890_shell::AssignStringRef(const char** apsSource)
{
    const char* t = *apsSource;
    if (m_cByteAtOffset1 != t)
    {
        if (t != _EmptyFS)
            InterlockedIncrement((volatile long*)(t - 8));
        if (m_cByteAtOffset1 != _EmptyFS)
            InterlockedDecrement((volatile long*)(m_cByteAtOffset1 - 8));
        m_cByteAtOffset1 = t;
    }
}

extern int DAT_011f4500;
extern int DAT_011f4504;
extern char DAT_011f4580;

struct CRITICAL_SECTION_STUB
{
    int a;
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION_STUB*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION_STUB*);

// @fnv 0x00a5f7b0
// src: COMMUNITY 0x00a5f7b0
void __fastcall NiTexture_AddTextureToList(int pNode)
{
    EnterCriticalSection((CRITICAL_SECTION_STUB*)&DAT_011f4580);
    if (DAT_011f4500 == 0)
    {
        DAT_011f4500 = pNode;
    }
    if (DAT_011f4504 != 0)
    {
        *(int*)(DAT_011f4504 + 0x2c) = pNode;
        *(int*)(pNode + 0x28) = DAT_011f4504;
    }
    else
    {
        *(int*)(pNode + 0x28) = 0;
    }
    DAT_011f4504 = pNode;
    *(int*)(pNode + 0x2c) = 0;
    LeaveCriticalSection((CRITICAL_SECTION_STUB*)&DAT_011f4580);
}

struct ControllerAllocation
{
    ControllerAllocation* FUN_00a40520(void* target, float value, unsigned int flags);
};

// @fnv 0x00a411c0
// src: COMMUNITY 0x00a411c0
ControllerAllocation* __stdcall NiGeomMorpherController_CreateBlendInterpolator(unsigned int auiUnused1, void* target, unsigned int unused2, float value,
                                             unsigned int flags)
{
    ControllerAllocation* controller = static_cast<ControllerAllocation*>(NiObject::operator new(52));
    if (controller)
        return controller->FUN_00a40520(target, value, flags);
    return 0;
}

struct FUN_00a413d0_pair
{
    unsigned int m_key0;
    unsigned int m_key1;
};

struct FUN_00a413d0_cls
{
    unsigned int m_unk00;
    FUN_00a413d0_pair** m_ppItems;
    unsigned short m_unk08;
    unsigned short m_uiItemCount;
    int FindPairIndex(unsigned int key0, unsigned int key1);
};

// @fnv 0x00a413d0
int FUN_00a413d0_cls::FindPairIndex(unsigned int key0, unsigned int key1)
{
    int result = -1;
    for (unsigned int i = 0; i < m_uiItemCount; ++i)
    {
        FUN_00a413d0_pair* item = m_ppItems[i];
        if (item->m_key0 == key0 && item->m_key1 == key1)
        {
            result = (int)i;
        }
    }
    return result;
}

class HandlerObject
{
  public:
    virtual void unk00();
    virtual void Handle(void* pArg);
};

struct HandlerEntry
{
    unsigned int m_key;
    HandlerObject* m_pEntryObject;
};

struct HandlerArg
{
    int unk00;
    int unk04;
    unsigned int m_key;
};

class FUN_00a41410_cls
{
  public:
    int unk00;
    HandlerEntry** m_ppEntries;
    unsigned short unk08;
    unsigned short m_uiItemCount;

    void DispatchByKey(HandlerArg* a1);
};

// Iterates the entry table and calls Handle on each entry whose m_key matches the argument's m_key.
// @fnv 0x00a41410
void FUN_00a41410_cls::DispatchByKey(HandlerArg* a1)
{
    for (unsigned int i = 0; i < m_uiItemCount; ++i)
    {
        HandlerEntry* e = m_ppEntries[i];
        if (e->m_key == a1->m_key)
        {
            e->m_pEntryObject->Handle(a1);
        }
    }
}

struct S_00a42290_Q : NiObject
{
    int unk08;
    int unk0c;
    int unk10;
    bool unk14;
    S_00a42290_Q() throw() : unk08(0), unk0c(0), unk10(0), unk14(false)
    {}
    virtual ~S_00a42290_Q() throw()
    {}
    void FUN_00a3ccb0(void* a, unsigned int b, int c);
};
template <> NiPointer<S_00a42290_Q>&
NiPointer<S_00a42290_Q>::operator=(S_00a42290_Q* object);

struct S_00a42290_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NiPointer<S_00a42290_Q> m10;
    int unk14;
    void NiFloatInterpolator_SetKeys(void* a, unsigned int b, int c);
};
// @fnv 0x00a42290
// src: COMMUNITY 0x00a42290
void S_00a42290_Cls::NiFloatInterpolator_SetKeys(void* a, unsigned int b, int c)
{
    if (b > 0)
    {
        if (m10.m_pObject == 0)
        {
            S_00a42290_Q* q = new S_00a42290_Q;
            m10 = q;
        }
        m10.m_pObject->FUN_00a3ccb0(a, b, c);
        unk14 = 0;
    }
    else if (m10.m_pObject != 0)
    {
        m10.m_pObject->FUN_00a3ccb0(0, 0, 0);
    }
}

class A42380Owner
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
    NiPointer<NiRefObject> m_spTransformData;

    void UpdateFields_00a42380(NiRefObject* pkData);
};

// @fnv 0x00a42380
// src: GUESS 0x00a42380 (confidence: low)
void A42380Owner::UpdateFields_00a42380(NiRefObject* pkData)
{
    if (pkData)
        m_spTransformData = pkData;
    else
        m_spTransformData = 0;
}

extern const NiRTTI NiNodeRTTI_a42b70;
extern const NiRTTI CtrlRTTI_A_a42b70;
extern const NiRTTI CtrlRTTI_B_a42b70;
extern const NiRTTI CtrlRTTI_C_a42b70;

struct StubController : NiObject
{
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
    StubController* m_pkNext;
};

struct StubAVObject;

struct StubChildArray
{
    void* m_pVTable;
    StubAVObject** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};

struct StubAVObject : NiObject
{
    int unk08;
    StubController* m_pControllers;
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
    StubChildArray m_kChildList;
};

static inline bool IsKindOfRTTI(const NiRTTI* pkTarget, const NiObject* pkObj)
{
    for (const NiRTTI* r = pkObj->GetRTTI(); r; r = r->m_pBaseRTTI)
        if (r == pkTarget)
            return true;
    return false;
}

void __cdecl NiOldAnimationConverter_ConvertRollController(StubController* p);
void __cdecl CreateInterpolator(StubController* p);
void __cdecl ConvertLegacyController(StubController* p);

// @fnv 0x00a42b70
// src: COMMUNITY 0x00a42b70
void __cdecl NiOldAnimationConverter_RecurseScene(void* pArg, StubAVObject* pkObject)
{
    if (!pkObject)
        return;
    if (!IsKindOfRTTI(&NiNodeRTTI_a42b70, pkObject))
        return;

    StubController* pkCtrl = pkObject->m_pControllers;
    while (pkCtrl)
    {
        StubController* pkNext = pkCtrl->m_pkNext;
        if (IsKindOfRTTI(&CtrlRTTI_A_a42b70, pkCtrl))
            NiOldAnimationConverter_ConvertRollController(pkCtrl);
        else if (IsKindOfRTTI(&CtrlRTTI_B_a42b70, pkCtrl))
            CreateInterpolator(pkCtrl);
        else if (IsKindOfRTTI(&CtrlRTTI_C_a42b70, pkCtrl))
            ConvertLegacyController(pkCtrl);
        pkCtrl = pkNext;
    }

    if (pkObject->IsSceneNode())
    {
        for (unsigned int i = 0; i < pkObject->m_kChildList.m_usSize; i++)
            NiOldAnimationConverter_RecurseScene(pArg, pkObject->m_kChildList.m_pBase[i]);
    }
}

extern int DAT_011f4304;

struct FUN_00a42c80_virtual
{
    virtual void f00();
    virtual void f01();
    virtual int* f02();
};

void __cdecl NiOldAnimationConverter_RecurseScene(void* a1, void* a2);

// @fnv 0x00a42c80
// src: COMMUNITY 0x00a42c80
void __cdecl NiOldAnimationConverter_Convert(int* param1, FUN_00a42c80_virtual* pVirtual)
{
    if (*(unsigned int*)((char*)param1 + 0xD8) >= 0xA010068u)
        return;

    if (pVirtual == 0)
        return;

    int* node = pVirtual->f02();
    if (node == 0)
        return;

    while (node != 0)
    {
        if (node == &DAT_011f4304)
        {
            NiOldAnimationConverter_RecurseScene(param1, pVirtual);
            break;
        }

        node = *(int**)((char*)node + 4);
    }
}

struct FUN_00a42f80_base
{
    virtual ~FUN_00a42f80_base();
};

struct FUN_00a42f80_cls : FUN_00a42f80_base
{
    virtual ~FUN_00a42f80_cls();
};

// @fnv 0x00a42f80
FUN_00a42f80_cls::~FUN_00a42f80_cls()
{}

struct FUN_00a44830_base
{
    virtual ~FUN_00a44830_base();
};

struct FUN_00a44830_cls : FUN_00a44830_base
{
    virtual ~FUN_00a44830_cls();
};

// @fnv 0x00a44830
FUN_00a44830_cls::~FUN_00a44830_cls()
{}

namespace fnv_00a44ff0 {
struct ControllerAllocation : FUN_00a44f90_class

{
    static void* operator new(unsigned int size) { return NiObject::operator new(size); }
    ControllerAllocation() throw();
};

// @fnv 0x00a44ff0
ControllerAllocation* CreateControllerAllocation()
{
    return new ControllerAllocation;
}
}  // namespace fnv_00a44ff0

extern "C" void _NiFreeAlias(void*);
extern "C" void __cdecl ReleaseObjectArray(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefItem
{
    virtual void unused() throw();
    virtual void Release() throw();
    volatile long count;
    void IncRefCount();
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&count))
            Release();
    }
};

struct RawArray
{
    virtual ~RawArray() throw()
    {
        _NiFreeAlias(data);
    }
    void** data;
    unsigned short maxSize, size, used, grow;
    void* RemoveAt(unsigned i) throw()
    {
        if (i >= size)
            return 0;
        void* p = data[i];
        data[i] = 0;
        if (p)
            --used;
        if (i == (unsigned short)(size - 1))
            --size;
        return p;
    }
};
struct RefArray
{
    virtual ~RefArray() throw()
    {
        ReleaseObjectArray(data);
    }
    NiPointer<RefItem>* data;
    unsigned short maxSize, size, used, grow;
    NiPointer<RefItem> FUN_00a47540(unsigned) throw();
};

struct FUN_00a478f0 : NiRefObject
{
    void* raw;
    RawArray rawArray;
    RefArray refArray;
    NiPointer<RefItem> reference;
    virtual void unused();
    ~FUN_00a478f0() throw();
};
// Frees raw, then clears each refArray slot and frees the matching rawArray element for every index below refArray.size.
// @fnv 0x00a478f0
FUN_00a478f0::~FUN_00a478f0() throw()
{
    _NiFreeAlias(raw);
    for (unsigned i = 0; i < refArray.size; ++i)
    {
        refArray.FUN_00a47540(i) = (RefItem*)0;
        _NiFreeAlias(rawArray.RemoveAt(i));
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern int DAT_0109893c;
struct RefObject
{
    virtual void GetRTTI();
    virtual void DeleteThis();
    volatile long referenceCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            DeleteThis();
    }
};
struct RefPointer
{
    RefObject* object;
    void Clear()
    {
        if (object)
        {
            object->DecRefCount();
            object = 0;
        }
    }
    void Release()
    {
        if (object)
            object->DecRefCount();
    }
};
struct ParentData
{
    void* vtable;
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
    void FUN_00a6d290();
};
void __cdecl _NiFree_00aa10f0(void*);
struct FUN_00a49d60 : public ParentData
{
    RefPointer first;
    RefPointer second;
    void* resource;
    ~FUN_00a49d60();
};
// @fnv 0x00a49d60
FUN_00a49d60::~FUN_00a49d60()
{
    vtable = &DAT_0109893c;
    first.Clear();
    second.Clear();
    _NiFree_00aa10f0(resource);
    second.Release();
    first.Release();
    ParentData::FUN_00a6d290();
}

struct FUN_00a53c90_Node
{
    FUN_00a53c90_Node* m_pNext;
    unsigned int m_uiKey;
    unsigned char m_ucFlag;
};

class FUN_00a53c90_cls
{
  public:
    virtual void* vSlot0();
    virtual unsigned int vSlot1(unsigned int key);
    unsigned int m_uiCount;
    FUN_00a53c90_Node** m_ppItems;
    void GetNextEntry(FUN_00a53c90_Node** ppCur, unsigned int* pKey, unsigned char* pFlag);
};

// Reads the current node's key and flag, advances the cursor to the next node or the next non-empty bucket, and clears it when exhausted.
// @fnv 0x00a53c90
void FUN_00a53c90_cls::GetNextEntry(FUN_00a53c90_Node** ppCursor, unsigned int* pKeyOut, unsigned char* pFlagOut)
{
    FUN_00a53c90_Node* node = *ppCursor;
    *pKeyOut = node->m_uiKey;
    *pFlagOut = node->m_ucFlag;
    if (node->m_pNext != 0)
    {
        *ppCursor = node->m_pNext;
        return;
    }
    unsigned int i = vSlot1(node->m_uiKey) + 1;
    if (i >= m_uiCount)
    {
        *ppCursor = 0;
        return;
    }
    FUN_00a53c90_Node** p = m_ppItems + i;
    do
    {
        FUN_00a53c90_Node* item = *p;
        if (item != 0)
        {
            *ppCursor = item;
            return;
        }
        ++i;
        ++p;
    } while (i < m_uiCount);
    *ppCursor = 0;
}

extern void* __cdecl _NiMalloc_00aa1070(unsigned int size);

struct FUN_00a54110
{
    int* pBuffer;
    unsigned int reservedSize;
    unsigned int size;

    FUN_00a54110(unsigned int count);
};

// Allocates a buffer of count ints (or null when count is 0), sets reservedSize to count and size to 0.
// @fnv 0x00a54110
FUN_00a54110::FUN_00a54110(unsigned int count)
{
    if (count > 0)
    {
        pBuffer = static_cast<int*>(_NiMalloc_00aa1070(count * sizeof(int)));
    }
    else
    {
        pBuffer = 0;
    }
    reservedSize = count;
    size = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

extern const char* g_pcNullString572;

class NiObjectBase572
{
  public:
    virtual ~NiObjectBase572() throw();

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

class FUN_00a572d0 : public NiObjectBase572
{
  public:
    virtual ~FUN_00a572d0() throw();

    NiPointer<NiRefObject> m_spFirst;
    NiFixedString m_kName;
    NiPointer<NiRefObject> m_spSecond;
};

// Destructor for FUN_00a572d0; releases m_spSecond, m_kName and m_spFirst via their member destructors.
// @fnv 0x00a572d0
FUN_00a572d0::~FUN_00a572d0() throw()
{}

struct FUN_00a57580_cls
{
    int m_iWordAt00;
    int m_uiItemCount;
    int(__cdecl* m_fn)(FUN_00a57580_cls*, int, int, int*, int);
};

// @fnv 0x00a57580
int __cdecl InvokeAndAccumulate(FUN_00a57580_cls* pObj, int iValue)
{
    int n = 1;
    int r = pObj->m_fn(pObj, iValue, 1, &n, 1);
    pObj->m_uiItemCount += r;
    return r;
}

struct FUN_00a575b0_Object
{
    void* unk00;
    int unk04;
    int(__cdecl* unk08)(void*, int, int, int*, int);
};

// @fnv 0x00a575b0
// src: COMMUNITY 0x00a575b0
void __cdecl NiStreamLoadBinary_00a575b0(FUN_00a575b0_Object* object, int value)
{
    int result = 4;
    object->unk04 += object->unk08(object, value, 4, &result, 1);
}

struct FUN_00a59c60_target
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
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
};

class FUN_00a59c60_cls
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
    virtual void v41(int a, int b);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00a59c60_target* m_18;
    void NiAVObject_Update(int a1);
};

// Calls v41 with the given argument and 0, then calls v63 on m_18 if it is non-null.
// @fnv 0x00a59c60
// src: XBOX_PDB 0x00a59c60
void FUN_00a59c60_cls::NiAVObject_Update(int aiValue)
{
    v41(aiValue, 0);
    if (m_18 != 0)
        m_18->v63();
}

struct SingletonTarget
{
    void __thiscall NiGlobalStringTable_FreeStrings();
};
extern SingletonTarget* g_011f42c0;

// @fnv 0x00a5b460
// src: COMMUNITY 0x00a5b460
void __cdecl NiGlobalStringTable_FreeUnusedStrings()
{
    g_011f42c0->NiGlobalStringTable_FreeStrings();
}

extern void __cdecl _NiFree_00aa10f0(char* psz);
extern int DAT_0102102c;

struct Ent
{
    void* m_f0;
    char* m_str;
    int m_unk8;
    int m_unkC;
};

inline char* GetStr(Ent* e)
{
    return e->m_str;
}

struct CSImpl
{
    void* m_iFourthElementInteger[6];
};
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CSImpl* pcs);

struct FUN_00a5b470_cls
{
    int m_pad4;
    int m_pad8;
    int m_padC;
    Ent m_entries[0x200];
    char m_gap[0x74];
    CSImpl m_cs;
    void ResetEntries();
};

// @fnv 0x00a5b470
void FUN_00a5b470_cls::ResetEntries()
{
    DeleteCriticalSection(&m_cs);
    Ent* p = (Ent*)this + 0x201;
    for (int i = 0x200; i >= 0; --i)
    {
        p = p - 1;
        p->m_f0 = &DAT_0102102c;
        _NiFree_00aa10f0(GetStr(p));
    }
}

__declspec(dllimport) void __stdcall InitializeCriticalSection(void* pkSection);

extern int g_iA5B530Default;

struct A5B530Entry
{
    int* m_piSource;
    int m_iValue;
    short m_sA;
    short m_sB;
    short m_sC;
    short m_sCount;

    A5B530Entry()
    {
        m_sA = 0;
        m_sCount = 1;
        m_sB = 0;
        m_sC = 0;
        m_iValue = 0;
        m_piSource = &g_iA5B530Default;
    }
};

struct A5B530CriticalSection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class FUN_00a5b530
{
  public:
    A5B530Entry m_akEntries[0x201];
    int unk2010;
    int unk2014;
    int unk2018;
    int unk201C;
    int unk2020;
    int unk2024;
    int unk2028;
    int unk202C;
    int unk2030;
    int unk2034;
    int unk2038;
    int unk203C;
    int unk2040;
    int unk2044;
    int unk2048;
    int unk204C;
    int unk2050;
    int unk2054;
    int unk2058;
    int unk205C;
    int unk2060;
    int unk2064;
    int unk2068;
    int unk206C;
    int unk2070;
    int unk2074;
    int unk2078;
    int unk207C;
    A5B530CriticalSection m_kLock;

    FUN_00a5b530();
};

// Initializes the critical section and sets m_sCount to 10 for all 0x201 entries.
// @fnv 0x00a5b530
FUN_00a5b530::FUN_00a5b530()
{
    InitializeCriticalSection(&m_kLock);
    for (unsigned int i = 0; i < 0x201; i++)
        m_akEntries[i].m_sCount = 10;
}

class A5B660Heap
{
  public:
    void Deallocate(void* pvMem);
};

class A5B660StringTable
{
  public:
    ~A5B660StringTable();

    static void operator delete(void* pvMem)
    {
        reinterpret_cast<A5B660Heap&>(g_memoryManager).Deallocate(pvMem);
    }

    static A5B660StringTable* ms_pStringTable;

    static void ClearStaticStringTable();
};

// Deletes the static string table instance and clears the pointer to null.
// @fnv 0x00a5b660
// src: GUESS 0x00a5b660 (confidence: medium)
void A5B660StringTable::ClearStaticStringTable()
{
    delete ms_pStringTable;
    ms_pStringTable = 0;
}

struct FUN_00a5b870_cls
{
    int unk00;
    unsigned short* m_pData;
    unsigned short unk08;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    void __thiscall SetEntry(unsigned int index, unsigned short* value);
};

// Grows the tracked size to cover index, adjusts a non-zero entry counter when the stored value changes, then writes value at index.
// @fnv 0x00a5b870
void __thiscall FUN_00a5b870_cls::SetEntry(unsigned int index, unsigned short* pusValue)
{
    if (index >= m_usSize)
    {
        m_usSize = (unsigned short)(index + 1);
        if (*pusValue != 0)
        {
            m_usElementCount++;
        }
    }
    else
    {
        if (*pusValue != 0)
        {
            unsigned short* data = m_pData;
            if (data[index] == 0)
            {
                m_usElementCount++;
            }
        }
        else
        {
            unsigned short* data = m_pData;
            if (data[index] != 0)
            {
                m_usElementCount += 0xffff;
            }
        }
    }
    m_pData[index] = *pusValue;
}

// Clone
// @fnv 0x00a5d2c0
NiObject* NiObject::CloneObject(CloningProcess& kCloning)
{
    NiObject* pkClone = MakeClone(kCloning);
    ProcessClone(kCloning);
    return pkClone;
}

// NiRefObject

// @fnv 0x00a5d3d0
__declspec(noinline) NiRefObject::~NiRefObject()
{
    InterlockedDecrement((volatile long*)&ms_lObjectCount);
}

extern void* __cdecl Object_DispatchCommandFour(unsigned int);
extern int DAT_0109b5ac;
extern int DAT_0101fbd4;
struct NiObjectBase
{
    void __thiscall FUN_00a5aa20();
};
struct ObjectState
{
    void* reference;
    unsigned int count;
    unsigned short first;
    unsigned short second;
    unsigned short third;
    unsigned short enabled;
};
// @fnv 0x00a5f030
// src: EXE 0x00a5f030
NiObjectBase* __cdecl NiNode_CreateObject()
{
    NiObjectBase* object = static_cast<NiObjectBase*>(Object_DispatchCommandFour(0xac));
    if (object)
    {
        object->FUN_00a5aa20();
        *reinterpret_cast<void**>(object) = &DAT_0109b5ac;
        ObjectState* state = reinterpret_cast<ObjectState*>(reinterpret_cast<char*>(object) + 0x9c);
        state->first = 0;
        state->enabled = 1;
        state->second = 0;
        state->third = 0;
        state->count = 0;
        state->reference = &DAT_0101fbd4;
        return object;
    }
    return 0;
}

// Constructor of a derived object: base ctor call, then a 16-bit field and the vtable pointer.
extern int DAT_0109b72c;

struct FUN_00a5f1e0_cls
{
    void* m_pVTable;       // +0x00
    int m_i04;             // +0x04
    int m_i08;             // +0x08
    int m_i0C;             // +0x0C
    int m_i10;             // +0x10
    unsigned short m_w14;  // +0x14
    unsigned short m_w16;  // +0x16
    unsigned short m_w18;  // +0x18

    void Init();  // base constructor (external)

    FUN_00a5f1e0_cls();
};

// @fnv 0x00a5f1e0
FUN_00a5f1e0_cls::FUN_00a5f1e0_cls()
{
    Init();
    m_w18 = 8;
    m_pVTable = &DAT_0109b72c;
}

class A5F4D0Property
{
  public:
    A5F4D0Property();
    virtual ~A5F4D0Property();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class FUN_00a5f4d0 : public A5F4D0Property
{
  public:
    unsigned short m_usFlags;

    FUN_00a5f4d0();
    virtual ~FUN_00a5f4d0();
};

// @fnv 0x00a5f4d0
FUN_00a5f4d0::FUN_00a5f4d0()
{
    m_usFlags = 0xf;
}

struct CountedRef
{
    virtual void Vslot00(int flags);
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};

extern int DAT_0109b9ec;
extern int DAT_0109b944;
extern int DAT_0109b220;

struct FUN_00a5fca0_cls
{
    void* m_vptr;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    CountedRef* m_24;
    int unk28, unk2C;
    int m_30;
    int m_34;
    CountedRef* m_38;
    CountedRef* m_3c;

    void NiTexture_RemoveTextureFromList();
    void DestroyFogProperty();
    void UpdateFields_00a5fca0();
};

// @fnv 0x00a5fca0
// src: GUESS 0x00a5fca0 (confidence: low)
void FUN_00a5fca0_cls::UpdateFields_00a5fca0()
{
    *(void* volatile*)&m_vptr = (void*)&DAT_0109b9ec;
    CountedRef* a = *(CountedRef* volatile*)&m_3c;
    if (a != 0)
    {
        if (InterlockedDecrement(&a->m_iObjectReferenceCount) == 0)
        {
            a->DeleteThis();
        }
        m_3c = 0;
    }
    CountedRef* b = m_38;
    if (b != 0)
    {
        if (InterlockedDecrement(&b->m_iObjectReferenceCount) == 0)
        {
            b->DeleteThis();
        }
        m_38 = 0;
    }
    CountedRef* c = m_3c;
    if (c != 0)
    {
        if (InterlockedDecrement(&c->m_iObjectReferenceCount) == 0)
        {
            c->DeleteThis();
        }
    }
    CountedRef* d = m_38;
    if (d != 0)
    {
        if (InterlockedDecrement(&d->m_iObjectReferenceCount) == 0)
        {
            d->DeleteThis();
        }
    }
    if (m_34 != DAT_0109b220)
    {
        InterlockedDecrement((long*)(m_34 - 8));
    }
    if (m_30 != DAT_0109b220)
    {
        InterlockedDecrement((long*)(m_30 - 8));
    }
    CountedRef* e = m_24;
    *(void* volatile*)&m_vptr = (void*)&DAT_0109b944;
    if (e != 0)
    {
        e->Vslot00(1);
    }
    NiTexture_RemoveTextureFromList();
    DestroyFogProperty();
}

// Destructor of an owning pointer array: remove and free every element, then the base frees the storage.

class A1450MemoryManager
{
  public:
    void Deallocate(void* pvMem) throw();
};
extern A1450MemoryManager g_kA1450MemoryManager;

void __cdecl A1450NiFree(void* pvMem);

struct A1450Element
{
    int unk00;

    static void operator delete(void* pvMem)
    {
        g_kA1450MemoryManager.Deallocate(pvMem);
    }
};

typedef NiTArray<A1450Element*, NiTMallocInterface<A1450Element*> > A1450Array;
template <> inline NiTArray<A1450Element*, NiTMallocInterface<A1450Element*> >::~NiTArray()
{
        A1450NiFree(m_pBase);
    }
template <> inline A1450Element* NiTArray<A1450Element*, NiTMallocInterface<A1450Element*> >::RemoveEnd()
{
        if (m_usSize == 0)
            return 0;
        m_usSize--;
        A1450Element* pkElement = m_pBase[m_usSize];
        m_pBase[m_usSize] = 0;
        if (pkElement)
            m_usESize--;
        return pkElement;
    }

class A1450OwnedArray : public A1450Array
{
  public:
    void ClearAndDestroy();
};

// Deletes every element by repeatedly calling RemoveEnd, then runs the base A1450Array destructor.
// @fnv 0x00a41450
void A1450OwnedArray::ClearAndDestroy()
{
    unsigned int uiSize = m_usSize;
    for (unsigned int i = 0; i < uiSize; i++)
        delete RemoveEnd();
    A1450Array::~A1450Array();
}

namespace fnv_00a42310 {
#include <windows.h>

class FUN_00a42310_cls
{
  public:
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
    NiRefObject* m_pObject;

    void NiLookAtInterpolator_SetTranslateInterpolator(NiRefObject* obj);
};

// Releases the current m_pObject and stores obj with an incremented reference count, or clears m_pObject when obj is null.
// @fnv 0x00a42310
// src: COMMUNITY 0x00a42310
void FUN_00a42310_cls::NiLookAtInterpolator_SetTranslateInterpolator(NiRefObject* apObject)
{
    if (apObject != 0)
    {
        if (m_pObject == apObject)
        {
            return;
        }
        if (m_pObject != 0)
        {
            m_pObject->DecRefCount();
        }
        m_pObject = apObject;
        apObject->IncRefCount();
    }
    else
    {
        if (m_pObject != 0)
        {
            m_pObject->DecRefCount();
            m_pObject = 0;
        }
    }
}
}  // namespace fnv_00a42310

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class FUN_00a423f0_cls
{
  public:
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
    NiRefObject* m_pObject;

    void NiLookAtInterpolator_SetScaleInterpolator(NiRefObject* obj);
};

// Releases the previous m_pObject reference and stores obj with an incremented ref count, or clears m_pObject when obj is null.
// @fnv 0x00a423f0
// src: COMMUNITY 0x00a423f0
void FUN_00a423f0_cls::NiLookAtInterpolator_SetScaleInterpolator(NiRefObject* apObject)
{
    if (apObject != 0)
    {
        if (m_pObject == apObject)
        {
            return;
        }
        if (m_pObject != 0)
        {
            m_pObject->DecRefCount();
        }
        m_pObject = apObject;
        apObject->IncRefCount();
    }
    else
    {
        if (m_pObject != 0)
        {
            m_pObject->DecRefCount();
            m_pObject = 0;
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern const NiRTTI DAT_011f36ec;

struct ConvertedController;
struct ControllerInterpolator;
struct ControllerHost
{
    ConvertedController* NiObjectNET_GetController(const NiRTTI*);
    void FUN_00a5c000(ConvertedController*);
    void NiObjectNET_RemoveController(StubController*);
};
struct ControllerFields
{
    virtual void Slot00();
    virtual void DeleteThis() throw();
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
    virtual void Slot16();
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
    virtual void SetTarget(ControllerHost*);
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Update();
    virtual void Slot48();
    virtual void* GetInterpolator(unsigned int);
    virtual void SetInterpolator(ControllerInterpolator*, unsigned int);
    unsigned int refCount;
    int unk08;
    unsigned short flags;
    unsigned short unk0e;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    float startTime;
    float stopTime;
    void IncRefCount() throw()
    {
        InterlockedIncrement((volatile long*)&refCount);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement((volatile long*)&refCount))
            DeleteThis();
    }
};
struct ConvertedController : ControllerFields
{
    NiPointer<ConvertedController> next;
    ConvertedController* NiTransformController_NiTransformController();
};
struct ControllerInterpolator : ControllerFields
{
    unsigned short cycle;
    unsigned short unk32;
    int unk34;
    int data;
    ControllerInterpolator* FUN_00a3f060(void*, void*);
    void UpdateIfFlagged();
    void SetFlag1(bool value)
    {
        if (value)
            flags |= 2;
        else
            flags &= (unsigned short)~2;
    }
    void SetFlag2(bool value)
    {
        if (value)
            flags |= 4;
        else
            flags &= (unsigned short)~4;
    }
    void SetFlag3(bool value)
    {
        if (value)
            flags |= 8;
        else
            flags &= (unsigned short)~8;
    }
    void SetFlag5(bool value)
    {
        if (value)
            flags |= 32;
        else
            flags &= (unsigned short)~32;
    }
    void SetFlag6(bool value)
    {
        if (value)
            flags |= 64;
        else
            flags &= (unsigned short)~64;
    }
    void SetFlag4(bool value)
    {
        if (value)
            flags |= 16;
        else
            flags &= (unsigned short)~16;
        if (value)
            UpdateIfFlagged();
    }
};
struct LegacyController : StubController
{
    unsigned short flags;
    unsigned short unk36;
    int unk38;
    int unk3c;
    void* firstData;
    void* secondData;
    int unk48;
    int unk4c;
    float startTime;
    float stopTime;
    unsigned short cycle;
    unsigned short unk5a;
    int unk5c;
    int data;
    bool Flag1() const
    {
        return (flags >> 1) & 1;
    }
    bool Flag2() const
    {
        return (flags >> 2) & 1;
    }
    bool Flag3() const
    {
        return (flags >> 3) & 1;
    }
    bool Flag4() const
    {
        return (flags >> 4) & 1;
    }
    bool Flag5() const
    {
        return (flags >> 5) & 1;
    }
    bool Flag6() const
    {
        return (flags >> 6) & 1;
    }
};
void __cdecl CopyControllerSettings(StubController*, ConvertedController*);

// Builds a ControllerInterpolator from the legacy controller's data and flags, attaches it to a converted controller, and links that controller into the host.
// @fnv 0x00a42900
void __cdecl ConvertLegacyController(StubController* p)
{
    LegacyController* old = static_cast<LegacyController*>(p);
    ControllerHost* host = reinterpret_cast<ControllerHost*>(old->unk2C);
    ConvertedController* controller = host->NiObjectNET_GetController(&DAT_011f36ec);
    if (controller)
        controller->IncRefCount();
    ControllerInterpolator* allocation = static_cast<ControllerInterpolator*>(NiObject::operator new(0x5c));
    ControllerInterpolator* interpolator;
    if (allocation)
    {
        void* percentData = old->secondData;
        void* pathData = old->firstData;
        interpolator = allocation->FUN_00a3f060(pathData, percentData);
    }
    else
        interpolator = 0;
    interpolator->SetFlag2(old->Flag2());
    interpolator->SetFlag3(old->Flag3());
    interpolator->data = old->data;
    interpolator->SetFlag4(old->Flag4());
    interpolator->SetFlag5(old->Flag5());
    interpolator->startTime = old->startTime;
    interpolator->stopTime = old->stopTime;
    interpolator->cycle = old->cycle;
    interpolator->SetFlag6(old->Flag6());
    interpolator->SetFlag1(old->Flag1());
    if (controller && !controller->GetInterpolator(0))
    {
        controller->SetInterpolator(interpolator, 0);
        CopyControllerSettings(p, controller);
    }
    else
    {
        ConvertedController* fresh = static_cast<ConvertedController*>(NiObject::operator new(0x38));
        fresh = fresh ? fresh->NiTransformController_NiTransformController() : 0;
        if (controller != fresh)
        {
            if (controller)
                controller->DecRefCount();
            controller = fresh;
            if (controller)
                controller->IncRefCount();
        }
        controller->SetInterpolator(interpolator, 0);
        controller->SetTarget(host);
        CopyControllerSettings(p, controller);
        host->FUN_00a5c000(controller->next);
        controller->next = reinterpret_cast<ConvertedController*>(old->m_pkNext);
        ConvertedController* previous = reinterpret_cast<ConvertedController*>(old->m_pkNext);
        if (previous != controller)
        {
            if (previous)
                previous->DecRefCount();
            old->m_pkNext = reinterpret_cast<StubController*>(controller);
            controller->IncRefCount();
        }
    }
    interpolator->Update();
    if (host)
        host->NiObjectNET_RemoveController(p);
    controller->DecRefCount();
}

namespace fnv_00a47420 {
#include <windows.h>

class FUN_00a47420_cls
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
    NiPointer<NiRefObject> m_pReferencedObject;

    void SetReferencedObject_00a47420(NiRefObject* obj);
};

// @fnv 0x00a47420
// src: GUESS 0x00a47420 (confidence: medium)
void FUN_00a47420_cls::SetReferencedObject_00a47420(NiRefObject* apObject)
{
    m_pReferencedObject = apObject;
}
}  // namespace fnv_00a47420

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RTT
{
    const char* name;
    const RTT* base;
};
extern RTT g_011f3f38, g_011f3f28, g_011f4a38, g_011f36ec;
struct Obj
{
    virtual void slot0() throw();
    virtual void DeleteThis() throw();
    virtual const RTT* GetType() const throw();
    volatile long refs;
    const char* name;
    Obj* controller;
    Obj** extras;
    unsigned short count;
    unsigned short capacity;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Obj* next;
    Obj* Cast(const RTT*) throw();
    bool RemoveExtraDataAt(unsigned short) throw();
    void ClearExtraData() throw();
    void IncRefCount() throw()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
template <> inline NiPointer<Obj>::NiPointer(Obj* q) throw() : m_pObject(q)
{
    if (m_pObject)
        m_pObject->IncRefCount();
}

template <> inline NiPointer<Obj>::~NiPointer() throw()
{
    if (m_pObject)
        m_pObject->DecRefCount();
}

template <> inline NiPointer<Obj>& NiPointer<Obj>::operator=(Obj* q) throw()
{
    if (m_pObject != q)
    {
        if (m_pObject)
            m_pObject->DecRefCount();
        m_pObject = q;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    return *this;
}

inline bool IsKind(const RTT* type, const Obj* object) throw()
{
    for (const RTT* r = object->GetType(); r; r = r->base)
        if (r == type)
            return true;
    return false;
}
inline Obj* CastInline(const RTT* type, Obj* object) throw()
{
    if (!object)
        return 0;
    return (int)IsKind(type, object) ? object : 0;
}

struct Result
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
    static void* operator new(unsigned int) throw();
    Result(const char*, int, int) throw();
    void SetReferencedObject_00a47420(Obj*) throw();
    void AddSeq(void*, Obj*) throw();
};
struct Stream
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
    Obj** objects;
    unsigned int unk224;
    unsigned int size;
};
// @fnv 0x00a47ce0
Result* __cdecl CreateResultFromStreamObject(Stream* stream, unsigned int index, const char* name)
{
    if (stream->unk0d8 >= 0x4010003)
        return 0;
    if (index >= stream->size)
        return 0;
    Obj* object = stream->objects[index];
    Obj* source = object ? object->Cast(&g_011f3f38) : 0;
    if (!source)
        return 0;
    if (!name)
        name = source->name;
    Result* result = new Result(name, 12, 12);
    result->unk30 = 0;
    for (unsigned int i = 0; i < source->count; ++i)
    {
        Obj* extra = source->extras[(unsigned short)i];
        Obj* found = extra ? extra->Cast(&g_011f3f28) : 0;
        if (found)
        {
            result->SetReferencedObject_00a47420(found);
            source->RemoveExtraDataAt((unsigned short)i);
            break;
        }
    }
    NiPointer<Obj> controller(source->controller);
    for (unsigned int j = 0; j < source->count; ++j)
    {
        Obj* extra = CastInline(&g_011f4a38, source->extras[(unsigned short)j]);
        result->AddSeq((void*)extra->controller, CastInline(&g_011f36ec, controller.m_pObject));
        NiPointer<Obj> next(controller.m_pObject->next);
        if (controller.m_pObject->next)
        {
            controller.m_pObject->next->DecRefCount();
            controller.m_pObject->next = 0;
        }
        controller = next.m_pObject;
    }
    source->ClearExtraData();
    return result;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

template <> __forceinline NiPointer<NiGPUProgram>::~NiPointer()
{
    if (m_pObject)
        m_pObject->DecRefCount();
}

template <> __declspec(noinline) NiPointer<NiGPUProgram>&
NiPointer<NiGPUProgram>::operator=(const NiPointer<NiGPUProgram>& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject)
            m_pObject->DecRefCount();
        m_pObject = other.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    return *this;
}

extern unsigned int g_011f3f48;
struct BinaryDataRecord
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
    unsigned int version;
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
    NiObject** objects;
    unsigned int unk224;
    unsigned int count;
};
NiGPUProgram* CreateResultFromStreamObject(BinaryDataRecord*, unsigned int, void*) throw();
// Looks up the GPU program at index in the stream (or via CreateResultFromStreamObject for older versions), optionally passes extra to it, and stores it in result.
// @fnv 0x00a47f40

void GetGPUProgram(BinaryDataRecord* stream, unsigned int index, NiPointer<NiGPUProgram>& result, void* extra) throw()
{
    NiPointer<NiGPUProgram> program;
    if (stream->version < 0x04010003)
    {
        program = CreateResultFromStreamObject(stream, index, extra);
    }
    else
    {
        if (index >= stream->count)
        {
            result = (NiGPUProgram*)0;
            return;
        }
        NiObject* object = stream->objects[index];
        program = !object ? 0 : (NiGPUProgram*)object->DynamicCast(static_cast<const void*>(&g_011f3f48));
    }
    if (program == (NiGPUProgram*)0)
    {
        result = (NiGPUProgram*)0;
        return;
    }
    if (extra)
        program.m_pObject->SetString(extra);
    result = program;
}

// Destructor that, when m_bCopy is set, walks every hash bucket and frees each item's key string.
// @fnv 0x00a4d660
template <> SequenceStringMap::~NiTStringTemplateMap()
{
    if (m_bCopy)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            EntryType* pkItem = m_ppkHashTable[i];
            while (pkItem)
            {
                EntryType* pkSave = pkItem;
                pkItem = pkItem->m_pkNext;
                NiFreeA4D((char*)pkSave->m_key);
            }
        }
    }
}

void __cdecl FUN_00a57130(int a1);
// @fnv 0x00a41220
// src: XBOX_PDB 0x00a41220
void __cdecl NiColorExtraDataController_SaveBinary(int a1)
{
    FUN_00a57130(a1);
}

// @fnv 0x00a420e0
// src: GAMEBRYO_LIB 0x00a420e0
void __cdecl NiInterpScalar_AdjustBezier(float a0, float a1, float* p2, float a3, float a4, float* p5, float a6, float a7, float* p8,
                          float* p9)
{
    float f = a3 - a0;
    float e = a4 - a1;
    float d = a6 - a1;
    float u = a4 - a6;
    float r = d / e;
    float h = *p2 - f * 2.0 + *p5;
    float fTermM = f * 3.0 - *p2 * 2.0 - *p5;
    float s = ((h * 3.0 * r + 2.0 * fTermM) * r + *p2) / e;
    *p8 = s;
    *p9 = s * u;
    *p8 *= d;
    *p2 *= d / e;
    *p5 *= u / e;
}

struct FUN_00a44840_stub
{
    void* __thiscall NiObject_CreateClone(unsigned int);
};
// @fnv 0x00a44840
// src: COMMUNITY 0x00a44840
void* __thiscall FUN_00a44840_stub::NiObject_CreateClone(unsigned int)
{
    return this;
}

namespace a47 {
struct Obj
{
    virtual void v00() throw();
    virtual void DeleteThis() throw();
    volatile long m_lRef;
    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_lRef);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&m_lRef))
            DeleteThis();
    }
};

typedef NiTArray<NiPointer<a47::Obj>, NiTNewInterface<NiPointer<a47::Obj> > > Arr;
// Returns the element at index i and clears it, decrementing m_usESize if non-null and m_usSize if i is the last index.
// @fnv 0x00a47540
}
template <> NiPointer<a47::Obj> NiTArray<NiPointer<a47::Obj>, NiTNewInterface<NiPointer<a47::Obj> > >::RemoveAt(unsigned int uiIndex) throw()
{
    if (uiIndex >= m_usSize)
        return NiPointer<a47::Obj>(0);
    NiPointer<a47::Obj> pElement = m_pBase[uiIndex];
    m_pBase[uiIndex] = NiPointer<a47::Obj>(0);
    if (pElement != NiPointer<a47::Obj>(0))
        m_usESize--;
    if (uiIndex == (unsigned short)(m_usSize - 1))
        m_usSize--;
    return pElement;
}
namespace a47 {

}

extern "C" void __cdecl FUN_00a39010();

// @fnv 0x00a57c00
// src: XBOX_PDB 0x00a57c00
void __cdecl NiBoolInterpController_SaveBinary()
{
    FUN_00a39010();
}

struct FUN_00a5d320_Class
{
    void __thiscall FUN_00a5d320(void* arg1, unsigned int arg2);
};

// @fnv 0x00a5d430
void NiObject::ProcessClone(CloningProcess& kCloning)
{

    void* map_ptr = *(void**)(reinterpret_cast<char*>(&kCloning) + 4);
    ((FUN_00a5d320_Class*)map_ptr)->FUN_00a5d320(this, 1);
}

// @fnv 0x00a5d450
__declspec(noinline) void NiObject::CopyMembersStream(unsigned int a, void* ppSet)
{
    NiVBSet* set = *(NiVBSet**)ppSet;
    set->Create((unsigned int)this, a);
}

// @fnv 0x00a5d610
void NiObject::LoadBinary(NiStream& arStream)
{
    NiStream* stream = &arStream;
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(stream) + 0xd8) >= 0x05000006 && *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(stream) + 0xd8) < 0x0a010072)
    {
        unsigned int groupId;
        (*reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(stream) + 0x24c))->ReadGroupId(&groupId);
        SetGroup(stream->GetObjectGroup(groupId));
    }
}

extern int g_011f36dc_arg1;

struct A5D6E0This : NiRefObject
{
    void AppendCameraPathEntries(NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >*);
};
extern void* __cdecl NiViewerStrings_NiGetViewerString_Title(int);
extern void* __cdecl NiGetViewerString_00a7d5a0(const char*, void*);
extern void* __cdecl NiGetViewerString_00a7d510(const char*, unsigned int);
// Appends three values obtained from FUN_00a7d330, FUN_00a7d5a0 and FUN_00a7d510 to the array, growing it via SetSize when full.
// @fnv 0x00a5d6e0
void A5D6E0This::AppendCameraPathEntries(NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >* apEntries)
{
    NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >* entries;
    unsigned int size;
    unsigned int maxSize;
    {
        BGSCameraPath* firstValue = (BGSCameraPath*)NiViewerStrings_NiGetViewerString_Title(g_011f36dc_arg1);
        entries = apEntries;
        size = entries->m_usSize;
        maxSize = entries->m_usMaxSize;
        if (size >= maxSize)
            reinterpret_cast<NiTPrimitiveArray<char*>*>(entries)->SetSize(
                size + entries->m_usGrowBy);
        entries->SetAt(size, firstValue);
    }
    {
        BGSCameraPath* currentValue = (BGSCameraPath*)NiGetViewerString_00a7d5a0("this", this);
        size = entries->m_usSize;
        maxSize = entries->m_usMaxSize;
        if (size >= maxSize)
            reinterpret_cast<NiTPrimitiveArray<char*>*>(entries)->SetSize(
                size + entries->m_usGrowBy);
        entries->SetAt(size, currentValue);
    }
    {
        unsigned int referenceCount = m_uiRefCount;
        BGSCameraPath* currentValue = (BGSCameraPath*)NiGetViewerString_00a7d510("m_uiRefCount", referenceCount);
        size = entries->m_usSize;
        maxSize = entries->m_usMaxSize;
        if (size >= maxSize)
            reinterpret_cast<NiTPrimitiveArray<char*>*>(entries)->SetSize(
                size + entries->m_usGrowBy);
        entries->SetAt(size, currentValue);
    }
}

extern void __cdecl NiObjectNET_CopyMembers();

// @fnv 0x00a5d7a0
// src: XBOX_PDB 0x00a5d7a0
void __cdecl NiProperty_CopyMembers()
{
    NiObjectNET_CopyMembers();
}

void __cdecl SaveNiObjectLinks();
// @fnv 0x00a5d7b0
// src: XBOX_PDB 0x00a5d7b0
void __cdecl NiSequenceStreamHelper_SaveBinary()
{
    SaveNiObjectLinks();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*) throw();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*) throw();
extern "C" void __cdecl _ReadWriteBarrier(void);

template <> NiPointer<AnimIdle>&
NiPointer<AnimIdle>::operator=(const NiPointer<AnimIdle>& other);

struct S654
{
    NiTListItem<NiPointer<AnimIdle> >* m_pkHead;
    NP NiTPointerListBase_NiPropertyPtr_Remove(NiPointer<AnimIdle>& item) throw();
};

struct ExtraOwner
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
    S654 list;
    void NiAVObject_RemoveProperty_0(int type, NiPointer<AnimIdle>& output);
};

// If type is under 7, removes the first list entry whose Type() equals type and stores it in output; otherwise, or if none matches, sets output to null.
// @fnv 0x00a5aac0
// src: COMMUNITY 0x00a5aac0
void ExtraOwner::NiAVObject_RemoveProperty_0(int type, NiPointer<AnimIdle>& output)
{
    if (type >= 7)
    {
        output = 0;
        return;
    }
    NiTListItem<NiPointer<AnimIdle> >* node = list.m_pkHead;
    // The loop manages this reference explicitly, including its release before returning.
    AnimIdle* currentObject;
    NiPointer<AnimIdle>& current = reinterpret_cast<NiPointer<AnimIdle>&>(currentObject);
    while (node)
    {
        NiPointer<AnimIdle>& el = node->m_element;
        node = node->m_pkNext;
        AnimIdle* p = el.m_pObject;
        current.m_pObject = p;
        if (p)
        {
            InterlockedIncrement((volatile long*)&p->m_uiRefCount);
            if (reinterpret_cast<int (__thiscall*)(AnimIdle*)>((*reinterpret_cast<void***>(p))[35])(p) == type)
            {
                {
                    NP removed = list.NiTPointerListBase_NiPropertyPtr_Remove(current);
                }
                NiPointer<AnimIdle>* pCurrent = &current;
                output = *pCurrent;
                AnimIdle* r = current.m_pObject;
                _ReadWriteBarrier();
                if (r)
                {
                    if (InterlockedDecrement((volatile long*)&r->m_uiRefCount) == 0)
                        r->DeleteThis();
                }
                return;
            }
            if (InterlockedDecrement((volatile long*)&p->m_uiRefCount) == 0)
                p->DeleteThis();
        }
    }
    output = 0;
}

extern int DAT_0101dce4;
extern char DAT_011f4400;
void __cdecl _delete(void*, unsigned int);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* Addend);

// Sets the vtable to DAT_0101dce4, decrements DAT_011f4400, and frees this if flags has bit 0 set.
// @fnv 0x00a5d4e0
void* __fastcall DeleteNiRefObject(NiRefObject* object, void*, unsigned char flags)
{
    *reinterpret_cast<void**>(object) = &DAT_0101dce4;
    InterlockedDecrement((long volatile*)&DAT_011f4400);
    if (flags & 1)
        _delete(object, 8);
    return object;
}

class CloneMapA5d6
{
  public:
    virtual ~CloneMapA5d6();
};

class CloningProcess
{
  public:
    CloningProcess(unsigned int uiHashSize);

    CloneMapA5d6* m_pCloneMap;
    CloneMapA5d6* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
};

// Constructs a CloningProcess (0x101), calls this object's MakeClone and ProcessClone with it, deletes its two maps, and returns the clone.
// @fnv 0x00a5d680
NiObject* NiObject::Clone()
{
    CloningProcess kCloning(0x101);
    NiObject* pkClone = MakeClone(kCloning);
    ProcessClone(kCloning);
    delete kCloning.m_pCloneMap;
    delete kCloning.m_pProcessMap;
    return pkClone;
}

extern void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern char* __cdecl FUN_00a5b690(const char* text);
extern void __cdecl NiStandardizeFilePath(void* fixed);
extern void __cdecl NiImageConverter_ConvertFilenameToPlatformSpecific_(void* fixed, void* out);
extern int DAT_0109b220;
extern unsigned char DAT_011a9594;
extern void(__stdcall* DAT_00fdf1c0)(void*);
extern void(__stdcall* DAT_00fdf1c4)(void*);

struct FnvSourceTexture
{
    virtual void Delete(unsigned char);
    virtual void slot004();
    virtual void slot008();
    virtual void slot012();
    virtual void slot016();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot032();
    virtual void slot036();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot052();
    virtual void slot056();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot072();
    virtual void slot076();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot092();
    virtual void slot096();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot112();
    virtual void slot116();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot132();
    virtual void slot136();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot152();
    virtual void slot156();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual bool IsLoaded();

    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    int width;
    int height;
    int depth;
    int unk24;
    int unk28;
    int unk2c;
    char* filename;
    char* normalizedName;
    int unk38;
    int unk3c;
    unsigned char unk40;
    unsigned char flags;
    unsigned short unk42;
    int source;

    FnvSourceTexture* __thiscall NiSourceTexture_NiSourceTexture();
};

// Allocates a FnvSourceTexture, sets its dimensions, flags, source, and filename, then deletes it if not loaded when DAT_011a9594 is set.
// @fnv 0x00a5fe30
// src: COMMUNITY 0x00a5fe30
FnvSourceTexture* __cdecl NiSourceTexture_CreateTexture(int source, const char* name, const int* size, unsigned char flags)
{
    FnvSourceTexture* object = (FnvSourceTexture*)Object_DispatchCommandFour(0x48);
    if (object)
        object = object->NiSourceTexture_NiSourceTexture();
    else
        object = 0;

    object->width = size[0];
    object->height = size[1];
    object->depth = size[2];
    object->flags = flags;
    object->source = source;

    if (name)
    {
        char* value = FUN_00a5b690(name);
        void(__stdcall * release)(void*) = DAT_00fdf1c4;
        char** fixed = &object->filename;
        if (*fixed != value)
        {
            if (value != (char*)DAT_0109b220)
                DAT_00fdf1c0(value - 8);
            if (*fixed != (char*)DAT_0109b220)
                release(*fixed - 8);
            *fixed = value;
        }
        NiStandardizeFilePath(fixed);
        NiImageConverter_ConvertFilenameToPlatformSpecific_(fixed, &object->normalizedName);
        if (value != (char*)DAT_0109b220)
            release(value - 8);
    }
    if (DAT_011a9594 && !object->IsLoaded())
    {
        object->Delete(1);
        return 0;
    }
    return object;
}

namespace fnv_00a5ff10 {
extern void* __cdecl Object_DispatchCommandFour(unsigned int);
extern void* __cdecl FUN_00a5b690(void*);
extern int DAT_0109b220;
extern unsigned char DAT_011a9594;
typedef long(__stdcall* RefCounter)(volatile long*);
extern RefCounter DAT_00fdf1c0;
extern RefCounter DAT_00fdf1c4;

struct RefCounted
{
    virtual void Unused00();
    virtual void DeleteThis();
};

struct FUN_00a5fc10_class
{
    void* __thiscall NiSourceTexture_NiSourceTexture();
};
struct Texture
{
    virtual void DeleteObject(int);
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
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
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
    virtual bool CanPreload();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_pSharedOwner;
    void* m_pFlagTarget;
    void* m_pEntries;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    RefCounted* m_pParent;
};

struct OwnerTriple
{
    void* m_pSharedOwner;
    void* m_pFlagTarget;
    void* m_pEntries;
};

// Allocates a Texture, copies owner fields, updates the parent reference count, sets the filename, and deletes the object if preloading is not allowed.
// @fnv 0x00a5ff10
// src: XBOX_PDB 0x00a5ff10
Texture* __cdecl NiSourceTexture_Create(RefCounted* parent, void* filename, const OwnerTriple* apOwnerFields)
{
    void* memory = Object_DispatchCommandFour(0x48);
    Texture* object = memory ? static_cast<Texture*>(((FUN_00a5fc10_class*)memory)->NiSourceTexture_NiSourceTexture()) : 0;
    OwnerTriple* storage = reinterpret_cast<OwnerTriple*>(&object->m_pSharedOwner);
    storage->m_pSharedOwner = apOwnerFields->m_pSharedOwner;
    storage->m_pFlagTarget = apOwnerFields->m_pFlagTarget;
    RefCounter release = DAT_00fdf1c4;
    storage->m_pEntries = apOwnerFields->m_pEntries;
    RefCounted* previous = object->m_pParent;
    if (previous != parent)
    {
        if (previous)
        {
            if (!release((volatile long*)((char*)previous + 4)))
                previous->DeleteThis();
        }
        object->m_pParent = parent;
        if (parent)
            DAT_00fdf1c0((volatile long*)((char*)parent + 4));
    }
    if (filename)
    {
        const char* value = (const char*)FUN_00a5b690(filename);
        ((FUN_00a5fba0_class*)object)->NiSourceTexture_SetFilePath(reinterpret_cast<const NiFixedString*>(&value));
        if (value != (const char*)DAT_0109b220)
            release((volatile long*)(value - 8));
    }
    if (DAT_011a9594 && !object->CanPreload())
    {
        object->DeleteObject(1);
        return 0;
    }
    return object;
}
}  // namespace fnv_00a5ff10

extern const NiRTTI DAT_011f3f90;

inline bool NiObject::IsKindOfType(const NiRTTI* sought) const
{
    const NiRTTI* type = GetRTTI();
    while (type)
    {
        if (type == sought)
            return true;
        type = type->m_pBaseRTTI;
    }
    return false;
}
inline bool S00a427e0_NiIsKindOf(const NiRTTI* r, NiObject* o)
{
    if (!o)
        return false;
    return o->IsKindOfType(r);
}
struct S00a427e0_Interp
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    static void* operator new(unsigned int size) { return NiObject::operator new(size); }
    S00a427e0_Interp(void*) throw();
};
struct S00a427e0_Track : NiObject
{
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
    virtual void Slot45();
    virtual void Slot46();
    virtual void Reset();
    virtual void GetTimeRange(float&, float&);
    virtual void SetTimeRange(float, float);
    void UpdateFields_00a42380(S00a427e0_Interp*);
};
struct S00a427e0_Ctrl : NiObject
{
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
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual S00a427e0_Track* GetTrack(int);
    virtual void Slot50();
    virtual void Finish();
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
    S00a427e0_Ctrl* next;
};
struct S00a427e0_Seq;
struct S00a427e0_Mgr
{
    unsigned int unk00, unk04, unk08;
    S00a427e0_Ctrl* head;
    void NiObjectNET_RemoveController(S00a427e0_Seq*);
};
struct S00a427e0_Seq
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
    S00a427e0_Mgr* manager;
    unsigned int unk30, unk34;
    void* data;
};
void __cdecl CopyControllerSettings(S00a427e0_Seq*, S00a427e0_Ctrl*);
// Finds the first controller with a matching track, installs a new interpolator on the track, resets it, then calls manager->FUN_00a5c480(sequence).
// @fnv 0x00a427e0
// src: COMMUNITY 0x00a427e0
void __cdecl NiOldAnimationConverter_ConvertRollController(StubController* p)
{
    S00a427e0_Seq* sequence = (S00a427e0_Seq*)p;
    S00a427e0_Mgr* manager = sequence->manager;
    S00a427e0_Ctrl* controller = manager->head;
    while (controller)
    {
        if (S00a427e0_NiIsKindOf(&DAT_011f36ec, controller))
        {
            S00a427e0_Track* track = controller->GetTrack(0);
            if (S00a427e0_NiIsKindOf(&DAT_011f3f90, track))
            {
                void* data = sequence->data;
                track->UpdateFields_00a42380(new S00a427e0_Interp(data));
                CopyControllerSettings(sequence, controller);
                float start, end;
                track->GetTimeRange(start, end);
                track->SetTimeRange(start, end);
                controller->Finish();
                track->Reset();
                break;
            }
        }
        controller = controller->next;
    }
    manager->NiObjectNET_RemoveController(sequence);
}

// Stores the key and referenced sequence in a map entry.
// @fnv 0x00a4d5f0
template <> void SequenceMapBase::SetValue(EntryType* apItem, const char* key,
                                           NiPointer<NiSequence> obj) throw()
{
    apItem->m_key = key;
    apItem->m_val = obj;
}

void __cdecl _NiFree_00aa10f0(void*);

struct ArrayBuffer
{
    void* m_pBuffer;
    void _NiFree_00aa10f0_Thunk();
};

// @fnv 0x00a541e0
// src: GUESS 0x00a541e0 (confidence: medium)
void ArrayBuffer::_NiFree_00aa10f0_Thunk()
{
    _NiFree_00aa10f0(m_pBuffer);
}

struct FUN_00a5abe0_lock
{
    int m_pOwnerObject;
    int m_uiItemCount;
    void BSSpinLock_Lock(int mode);
};
extern FUN_00a5abe0_lock DAT_011f42a0;

struct FUN_00a5abe0_node
{
    int m_iWordAt00;
    FUN_00a5abe0_node* m_next;
    void* m_item;
};

struct FUN_00a5abe0_item
{
    virtual void vSlot00();
    virtual void vSlot01();
    virtual void vSlot02();
    virtual void vSlot03();
    virtual void vSlot04();
    virtual void vSlot05();
    virtual void vSlot06();
    virtual void vSlot07();
    virtual void vSlot08();
    virtual void vSlot09();
    virtual void vSlot10();
    virtual void vSlot11();
    virtual void vSlot12();
    virtual void vSlot13();
    virtual void vSlot14();
    virtual void vSlot15();
    virtual void vSlot16();
    virtual void vSlot17();
    virtual void vSlot18();
    virtual void vSlot19();
    virtual void vSlot20();
    virtual void vSlot21();
    virtual void vSlot22();
    virtual void vSlot23();
    virtual void vSlot24();
    virtual void vSlot25();
    virtual void vSlot26();
    virtual void vSlot27();
    virtual void vSlot28();
    virtual void vSlot29();
    virtual void vSlot30();
    virtual void vSlot31();
    virtual void vSlot32();
    virtual void vSlot33();
    virtual void vSlot34();
    virtual int vfn35();

    long m_iWordAt04;
    FUN_00a5abe0_item* FUN_00a5d3f0(void* ctx);
};

struct FUN_00a5abe0_sub
{
    void NiAVObject_AttachProperty_00439fd0(void** p);
};

struct FUN_00a5abe0_owner
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    FUN_00a5abe0_sub m_24;
};

struct FUN_00a5abe0_list
{
    int m_iWordAt00;
    FUN_00a5abe0_node* m_pFirstNode;
};

// Under a global lock, walks the list p2 and for each item with vfn35() below 7 resolves it with ctx and passes it to self->m_24.FUN_00439fd0.
// @fnv 0x00a5abe0
// src: XBOX_PDB 0x00a5abe0
void __stdcall NiAVObject_CloneProperties(FUN_00a5abe0_owner* apOwner, void* apList, void* volatile apContext)
{
    DAT_011f42a0.BSSpinLock_Lock(0);
    FUN_00a5abe0_node* node = ((FUN_00a5abe0_list*)apList)->m_pFirstNode;
    while (node != 0)
    {
        void** ppItem = &node->m_item;
        node = node->m_next;
        FUN_00a5abe0_item* item = (FUN_00a5abe0_item*)*ppItem;

        if (item == 0)
            continue;
        if (item->vfn35() >= 7)
            continue;
        item = item->FUN_00a5d3f0(apContext);
        if (item->vfn35() >= 7)
            continue;
        apList = item;
        InterlockedIncrement(&item->m_iWordAt04);
        apOwner->m_24.NiAVObject_AttachProperty_00439fd0(&apList);
        if (InterlockedDecrement(&item->m_iWordAt04) == 0)
        {
            item->vSlot01();
        }
    }
    DAT_011f42a0.m_uiItemCount--;
    if (DAT_011f42a0.m_uiItemCount == 0)
    {
        DAT_011f42a0.m_pOwnerObject = 0;
    }
}

class RefObjB
{
  public:
    virtual ~RefObjB() throw();
    virtual void DeleteThis() throw();
    long m_uiRefCount;
};

struct ExtraOwnerB
{
    void NiAVObject_RemoveProperty_0(int type, RefObjB*& output) throw();
    void NiAVObject_RemoveProperty(int type);
};

// Calls FUN_00a5aac0 with type to get a RefObjB, then decrements its reference count and calls DeleteThis if it reaches zero.
// @fnv 0x00a5b230
// src: XBOX_PDB 0x00a5b230
void ExtraOwnerB::NiAVObject_RemoveProperty(int type)
{
    RefObjB* out = 0;
    NiAVObject_RemoveProperty_0(type, out);
    RefObjB* p = *(RefObjB* volatile*)&out;
    if (p)
    {
        if (InterlockedDecrement(&p->m_uiRefCount) == 0)
            p->DeleteThis();
    }
}

struct FUN_00a5b790_cls
{
    unsigned int m_00;
    unsigned short* m_04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;

    void NiTArray_unsigned_short_NiTMallocInterface_unsigned_short_SetSize(unsigned int newSize);
};

void* __cdecl _NiMalloc_00aa1070(unsigned int size);
void __cdecl _NiFree_00aa10f0(void* p);

template <class T> struct Alloc
{
    static T* AllocMem(unsigned int n)
    {
        return (T*)_NiMalloc_00aa1070(n * sizeof(T));
    }
};

// Resizes the m_04 buffer to newSize, zeroing new slots, adjusting m_0c for cleared slots, and freeing the old buffer.
// @fnv 0x00a5b790
// src: COMMUNITY 0x00a5b790
void FUN_00a5b790_cls::NiTArray_unsigned_short_NiTMallocInterface_unsigned_short_SetSize(unsigned int newSize)
{
    if (newSize == m_08)
        return;
    if (newSize < m_0a)
    {
        for (unsigned short i = (unsigned short)newSize; i < m_0a; i++)
        {
            if (m_04[i] != 0)
            {
                m_04[i] = 0;
                m_0c += 0xffff;
            }
        }
        m_0a = (unsigned short)newSize;
    }

    unsigned short* old = m_04;
    m_08 = (unsigned short)newSize;
    if (newSize > 0)
    {
        m_04 = Alloc<unsigned short>::AllocMem(m_08);
        unsigned short i;
        for (i = 0; i < m_0a; i++)
        {
            m_04[i] = old[i];
        }
        for (i = m_0a; i < m_08; i++)
        {
            m_04[i] = 0;
        }
    }
    else
    {
        m_04 = 0;
    }
    _NiFree_00aa10f0(old);
}

// Invokes the virtual vf09 on pStream, passing this object as the owner argument.
// @fnv 0x00a5d2f0
bool NiObject::RegisterStreamables(NiStream& stream)
{
    return stream.RegisterSaveObject(this);
}

namespace sa5f8b0 {

class Task
{
  public:
    virtual ~Task();
};

class Owner;

class Manager
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
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual bool CanAttach(Owner* pkOwner);
};

extern Manager* DAT_011f4748;
extern bool DAT_011f4448;

class Owner
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
    virtual void OnAttach();

    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int m_iTarget;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    bool m_bVisible;
    unsigned char unk041;
    unsigned char unk042;
    unsigned char unk043;
    Task* m_pkTask;

    bool NiSourceTexture_CreateRendererData();
};

// Returns false if there is no manager, true if m_iTarget is set (deleting m_pkTask in both), else false if CanAttach fails or true after clearing m_pkTask.
// @fnv 0x00a5f8b0
// src: XBOX_PDB 0x00a5f8b0
bool Owner::NiSourceTexture_CreateRendererData()
{
    Manager* pkManager = DAT_011f4748;
    if (!pkManager)
    {
        if (m_pkTask)
        {
            delete m_pkTask;
            m_pkTask = 0;
        }
        return false;
    }
    if (m_iTarget)
    {
        if (m_pkTask)
        {
            delete m_pkTask;
            m_pkTask = 0;
        }
        return true;
    }
    if (!pkManager->CanAttach(this))
        return false;
    if (DAT_011f4448 && m_iTarget && m_bVisible)
        OnAttach();
    m_pkTask = 0;
    return true;
}

}

namespace sa5f940 {

struct Source
{
    int unk000;
    int unk004;
    int unk008;
    int m_iValue;
};

struct Ref64
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
    int* m_piValue;
};

struct Ref54
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
    int* m_piValue;
};

struct Owner
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
    Source* m_pkSource;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    Ref64* m_pkRef64;
    Ref54* m_pkRef54;

    int GetValue();
};

// Returns the value from m_pkSource, m_pkRef64, or m_pkRef54 in that priority order, or 0 if none are set.
// @fnv 0x00a5f940
int Owner::GetValue()
{
    if (m_pkSource)
        return m_pkSource->m_iValue;
    if (m_pkRef64)
        return *m_pkRef64->m_piValue;
    if (m_pkRef54)
        return *m_pkRef54->m_piValue;
    return 0;
}

}

namespace sa5f970 {

struct Source
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int m_iValue;
};

struct Ref68
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
    int* m_piValue;
};

struct Ref58
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
    int* m_piValue;
};

struct Owner
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
    Source* m_pkSource;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    Ref68* m_pkRef68;
    Ref58* m_pkRef58;

    int NiSourceTexture_GetHeight();
};

// @fnv 0x00a5f970
// src: XBOX_PDB 0x00a5f970
int Owner::NiSourceTexture_GetHeight()
{
    if (m_pkSource)
        return m_pkSource->m_iValue;
    if (m_pkRef68)
        return *m_pkRef68->m_piValue;
    if (m_pkRef58)
        return *m_pkRef58->m_piValue;
    return 0;
}

}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plValue);

namespace sa5f9a0 {

class RefObject
{
  public:
    virtual void v00();
    virtual void DeleteThis();

    long m_lRefCount;

    void IncRefCount();
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }
};

// The stream loader stores a link ID through the original thiscall helper.
void __cdecl StoreLinkID();

struct Stream
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
    unsigned int m_uiFileVersion;

    unsigned int FUN_00a63460();
    unsigned int FUN_00a63430();
};

struct Controller
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
    NiPointer<RefObject> m_spPrimary;
    NiPointer<RefObject> m_spSecondary;
    unsigned char unk040;
    unsigned char unk041;
    bool m_bUsePrimary;

    void NiSequenceStreamHelper_LinkObject(Stream* pkStream);
    void Load(Stream* pkStream);
};

// Calls FUN_00a47360; if FUN_00a63460 is nonzero, reads a link ID into m_spPrimary or m_spSecondary by file version and m_bUsePrimary, clearing the other.
// @fnv 0x00a5f9a0
void Controller::Load(Stream* pkStream)
{
    NiSequenceStreamHelper_LinkObject(pkStream);
    if (pkStream->FUN_00a63460())
    {
        if (pkStream->m_uiFileVersion >= 0x14020004 && m_bUsePrimary)
        {
            reinterpret_cast<void (__thiscall*)(NiPointer<RefObject>*, unsigned int)>(&StoreLinkID)(
                &m_spPrimary, pkStream->FUN_00a63430());
            m_spSecondary = 0;
        }
        else
        {
            reinterpret_cast<void (__thiscall*)(NiPointer<RefObject>*, unsigned int)>(&StoreLinkID)(
                &m_spSecondary, pkStream->FUN_00a63430());
            m_spPrimary = 0;
        }
    }
}

}

extern "C" void(__stdcall* DAT_00fdf05c)(CRITICAL_SECTION_STUB*);
extern "C" void(__stdcall* DAT_00fdf100)(CRITICAL_SECTION_STUB*);
extern CRITICAL_SECTION_STUB DAT_011f4800;

struct FUN_00a5fa50_Obj
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void vf3C()
    {}
    virtual void vf40()
    {}
    virtual void vf44()
    {}
    virtual void vf48()
    {}
    virtual void vf4C()
    {}
    virtual void vf50()
    {}
    virtual void vf54()
    {}
    virtual void vf58()
    {}
    virtual void vf5C()
    {}
    virtual void vf60()
    {}
    virtual void vf64()
    {}
    virtual void vf68()
    {}
    virtual void vf6C()
    {}
    virtual void vf70()
    {}
    virtual void vf74()
    {}
    virtual void vf78()
    {}
    virtual void vf7C()
    {}
    virtual void vf80()
    {}
    virtual void vf84()
    {}
    virtual void vf88()
    {}
    virtual void vf8C()
    {}
    virtual void vf90()
    {}
    virtual void vf94()
    {}
    virtual void vf98()
    {}
    virtual void vf9C()
    {}
    virtual void vfA0()
    {}
    virtual void vfA4()
    {}
    virtual void vfA8()
    {}
// src: XBOX_PDB 0x00a5f8b0
    virtual void NiSourceTexture_CreateRendererData()
    {}

    void NiSourceTexture_PostLinkObject(int param);
};

// If DAT_011a9594 is set, acquires DAT_011f4800, calls FUN_00a5f8b0, and releases the critical section.
// @fnv 0x00a5fa50
// src: XBOX_PDB 0x00a5fa50
void __thiscall FUN_00a5fa50_Obj::NiSourceTexture_PostLinkObject(int param)
{
    if (DAT_011a9594)
    {
        DAT_00fdf05c(&DAT_011f4800);
        NiSourceTexture_CreateRendererData();
        return DAT_00fdf100(&DAT_011f4800);
    }
}

namespace sa5fa90 {

struct Item;

class Listener
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
    virtual bool Attach(Item* pkItem);
};

struct Owner;

class Item
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
    virtual void SetOwnerData(void* pvData);
};

struct Owner
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
    int m_iData;
    int unk034;
    Listener* m_pkPrimary;
    Listener* m_pkSecondary;

    bool NiSequenceStreamHelper_RegisterStreamables(Item* pkItem);
    bool AttachToListener(Item* pkItem);
};

// Validates pkItem via FUN_00a62130, sets its owner data to m_iData, then attaches it to m_pkPrimary or m_pkSecondary listener.
// @fnv 0x00a5fa90
bool Owner::AttachToListener(Item* pkItem)
{
    if (!NiSequenceStreamHelper_RegisterStreamables(pkItem))
        return false;
    pkItem->SetOwnerData(&m_iData);
    Listener* pkListener = m_pkPrimary;
    if (pkListener)
        return pkListener->Attach(pkItem);
    pkListener = m_pkSecondary;
    if (pkListener)
        return pkListener->Attach(pkItem);
    return true;
}

}

namespace sa5fae0 {

class Object
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
    virtual bool IsEqual(Object* pkObject);
};


class Controller
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int m_i18;
    int m_i1c;
    int m_i20;
    int unk024;
    int unk028;
    int unk02c;
    int m_i30;
    int unk034;
    NiPointer<Object> m_spB;
    NiPointer<Object> m_spA;
    bool m_b40;
    bool m_b41;
    bool m_b42;

    bool NiSequenceStreamHelper_IsEqual(Controller* pkOther);
    bool NiSourceTexture_IsEqual(Controller* pkOther);
};

// Returns true if FUN_00a62140 passes and m_i18, m_i1c, m_i20, m_i30, the three bool flags, and objects m_spA and m_spB all match pkOther.
// @fnv 0x00a5fae0
// src: XBOX_PDB 0x00a5fae0
bool Controller::NiSourceTexture_IsEqual(Controller* pkOther)
{
    if (!NiSequenceStreamHelper_IsEqual(pkOther))
        return false;
    if (m_i30 != pkOther->m_i30)
        return false;
    if ((m_spA && !pkOther->m_spA) || (!m_spA && pkOther->m_spA))
        return false;
    if (m_spA && !m_spA->IsEqual(pkOther->m_spA))
        return false;
    if ((m_spB && !pkOther->m_spB) || (!m_spB && pkOther->m_spB))
        return false;
    if (m_spB && !m_spB->IsEqual(pkOther->m_spB))
        return false;
    if (m_i18 != pkOther->m_i18 || m_i20 != pkOther->m_i20 || m_i1c != pkOther->m_i1c)
        return false;
    if (m_b40 != pkOther->m_b40 || m_b41 != pkOther->m_b41 || m_b42 != pkOther->m_b42)
        return false;
    return true;
}

}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern int DAT_0109b220;

class PixelDataFFE0
{
  public:
    virtual void vf00();
    virtual void DeleteThis();

    long m_uiRefCount;
};

class ImageConverterFFE0
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual PixelDataFFE0* LoadPixelDataFromFile(const char* filename, PixelDataFFE0* existing, unsigned int flags);
};

ImageConverterFFE0* FUN_00a76640() throw();

class PixelDataHolderFFE0
{
  public:
    PixelDataFFE0* m_pObject;

    __declspec(noinline) void FUN_00c663d0(PixelDataFFE0** value) throw();
};

void PixelDataHolderFFE0::FUN_00c663d0(PixelDataFFE0** value) throw()
{
    m_pObject = *value;
}

class SourceTextureFFE0
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
    int m_iName;
    const char* m_pcFilename;
    void* m_pkPersistentData;
    PixelDataHolderFFE0 m_spPixelData;

    void LoadPixelData();
};

// If m_iName differs from DAT_0109b220 and m_spPixelData and m_pkPersistentData are null, loads pixel data from m_pcFilename into m_spPixelData.
// @fnv 0x00a5ffe0
void SourceTextureFFE0::LoadPixelData()
{
    if (m_iName != DAT_0109b220 && m_spPixelData.m_pObject == 0 && m_pkPersistentData == 0)
    {
        PixelDataHolderFFE0* pixelData = &m_spPixelData;
        ImageConverterFFE0* converter = FUN_00a76640();
        PixelDataFFE0* existing = pixelData->m_pObject;
        const char* filename = m_pcFilename;

        PixelDataFFE0* result = converter->LoadPixelDataFromFile(filename, existing, 0);

        if (result)
            InterlockedIncrement(&result->m_uiRefCount);

        if (pixelData->m_pObject != 0)
        {
            if (result != pixelData->m_pObject)
                pixelData->FUN_00c663d0(&result);
        }
        else
        {
            pixelData->FUN_00c663d0(&result);
        }

        if (result && InterlockedDecrement(&result->m_uiRefCount) == 0)
            result->DeleteThis();
    }
}

struct FUN_00a473d0_class
{
    void* m_vtbl;
    void* m_auiShapeKeys;
    NiFixedString m_str;
    void SetString(const char* s);
};
// Frees the current m_str.m_kHandle buffer, then allocates and copies s into it when s is non-null.
// @fnv 0x00a473d0
void FUN_00a473d0_class::SetString(const char* apString)
{
    NiFree((void*)m_str.m_kHandle);
    m_str.m_kHandle = 0;
    if (apString)
    {
        unsigned int len = strlen(apString);
        m_str.m_kHandle = (char*)NiMalloc(len + 1);
        strcpy_s((char*)m_str.m_kHandle, len + 1, apString);
    }
}

// NiSequence::NiSequence(const char* pcName, unsigned int uiArraySize, unsigned int uiArrayGrowBy)
// RTTI: NiSequence : NiObject : NiRefObject. Vtables not in the symbols DB are referenced by their data symbols.
extern const void* DAT_01098454[];  // NiSequence vftable
extern int DAT_01021024;            // NiTPrimitiveArray<char*> vftable
extern const void* DAT_010984e4[];  __forceinline void ConstructSequenceNames(StrArr* array, unsigned int maxSize, unsigned int growBy)
{
    array->m_usMaxSize = (unsigned short)maxSize;
    array->m_usGrowBy = (unsigned short)growBy;
    array->m_usSize = 0;
    array->m_usESize = 0;
    array->m_pBase = 0;
    array->vtable = &DAT_01021024;
}

// NiTObjectArray<NiPointer<NiTransformController> > vftable

// NiTArray<char*, NiTMallocInterface<char*> > / NiTPrimitiveArray<char*>

// NiTObjectArray<NiPointer<NiTransformController> >
struct NiSequenceControllerArray
{
    const void* m_vft;
    void** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    __forceinline void Construct(unsigned int uiMaxSize, unsigned int uiGrowBy)
    {
        // NiTArray(uiMaxSize, uiGrowBy)
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
        m_vft = DAT_010984e4;
    }
    void FUN_00a47770(unsigned int uiSize);  // SetSize
};

// Initializes the NiSequence, sets up name and controller arrays with the given size and grow-by, and copies pcName into m_pcName.
// @fnv 0x00a47bd0
NiSequence* NiSequence::Initialize(const char* pcName, unsigned int uiArraySize, unsigned int uiArrayGrowBy)
{
    _Call_a5d3a0(this);  // NiObject::NiObject
    *reinterpret_cast<const void**>(this) = DAT_01098454;
    StrArr& m_kNameArray = m_kStringArray;
    NiRefObject*& m_spTextKeyData = *reinterpret_cast<NiRefObject**>(pad + 0x10);

    ConstructSequenceNames(&m_kNameArray, 0, 1);
    NiSequenceControllerArray& m_kControllerArray = *reinterpret_cast<NiSequenceControllerArray*>(pad);
    m_kControllerArray.Construct(0, 1);
    m_spTextKeyData = 0;

    if (pcName)
    {
        unsigned int uiLen = strlen(pcName) + 1;
        m_pcName = (char*)NiMalloc(uiLen);
        _strcpy_s(m_pcName, uiLen, pcName);
    }
    else
    {
        m_pcName = 0;
    }

    m_kNameArray.SetSize(uiArraySize);
    const unsigned int growBy = uiArrayGrowBy;
    m_kStringArray.m_usGrowBy = (unsigned short)growBy;
    m_kControllerArray.FUN_00a47770(uiArraySize);
    *reinterpret_cast<unsigned short*>(pad + 0xe) = (unsigned short)growBy;

    // m_spTextKeyData = 0 (NiPointer assignment)
    if (m_spTextKeyData)
    {
        m_spTextKeyData->DecRefCount();
        m_spTextKeyData = 0;
    }
    m_uiSequenceValue = 0;
    return this;
}

extern "C" unsigned long __readfsdword(unsigned long);
extern "C" volatile unsigned long _tls_index;
extern unsigned int DAT_011f42c8;
extern unsigned int DAT_011f42c4;

struct ThreadedTableEntry
{
    void __thiscall NiTPrimitiveArray_DWORD_AddFirstEmpty(const char** key);
};

struct ThreadedTable
{
    unsigned int __thiscall NiGlobalStringTable_HashFunction(const char* key, unsigned int flags);
    void __thiscall NiGlobalStringTable_InsertString(const char** key, unsigned int flags);
};

// Temporarily sets per-thread field 0x2b4 to 8; under the lock calls FUN_00a5b4b0 on the entry indexed by FUN_00a5b270 and updates two counters.
// @fnv 0x00a5b5a0
// src: XBOX_PDB 0x00a5b5a0
void __thiscall ThreadedTable::NiGlobalStringTable_InsertString(const char** key, unsigned int flags)
{
    unsigned int tlsIndex = _tls_index;
    unsigned char* threadData = reinterpret_cast<unsigned char**>(__readfsdword(0x2c))[tlsIndex];
    const unsigned int previousMode = *reinterpret_cast<unsigned int*>(threadData + 0x2b4);
    *reinterpret_cast<unsigned int*>(threadData + 0x2b4) = 8;

    unsigned int index = NiGlobalStringTable_HashFunction(*key, flags);
    CRITICAL_SECTION_STUB* criticalSection =
        reinterpret_cast<CRITICAL_SECTION_STUB*>(reinterpret_cast<char*>(this) + 0x2080);
    EnterCriticalSection(criticalSection);

    const unsigned int entryOffset = index << 4;
    if (*reinterpret_cast<short*>(reinterpret_cast<char*>(this) + entryOffset + 0x0c) != 0)
        ++DAT_011f42c8;

    reinterpret_cast<ThreadedTableEntry*>(reinterpret_cast<char*>(this) + entryOffset)->NiTPrimitiveArray_DWORD_AddFirstEmpty(key);
    ++DAT_011f42c4;
    LeaveCriticalSection(criticalSection);
    *reinterpret_cast<unsigned int*>(threadData + 0x2b4) = previousMode;
}

// @fnv 0x00a5d310
const NiRTTI* NiObject::QueryRTTI()
{
    return GetRTTI();
}

// Returns false if object is null, otherwise whether the strings returned through vf08 of object and this compare equal with strcmp.
// @fnv 0x00a5d470
bool NiObject::IsSameAs(NiObject* object)
{
    if (!object)
        return false;

    const char* target = object->GetRTTI()->m_pcName;
    const char* self = this->GetRTTI()->m_pcName;

    return strcmp(self, target) ? false : true;
}

struct StringBucket169
{
    unsigned int unk00;
    char** entries;
    unsigned short capacity;
    unsigned short count;
    unsigned short used;
    unsigned short grow;
};
struct StringRecord169
{
    unsigned int refs;
    unsigned int length;
};
struct StringTable169
{
    StringBucket169 buckets[513];
    unsigned int unk2010;
    unsigned int unk2014;
    unsigned int unk2018;
    unsigned int unk201c;
    unsigned int unk2020;
    unsigned int unk2024;
    unsigned int unk2028;
    unsigned int unk202c;
    unsigned int unk2030;
    unsigned int unk2034;
    unsigned int unk2038;
    unsigned int unk203c;
    unsigned int unk2040;
    unsigned int unk2044;
    unsigned int unk2048;
    unsigned int unk204c;
    unsigned int unk2050;
    unsigned int unk2054;
    unsigned int unk2058;
    unsigned int unk205c;
    unsigned int unk2060;
    unsigned int unk2064;
    unsigned int unk2068;
    unsigned int unk206c;
    unsigned int unk2070;
    unsigned int unk2074;
    unsigned int unk2078;
    unsigned int unk207c;
    CRITICAL_SECTION_STUB lock;
    unsigned int NiGlobalStringTable_HashFunction(const char*, unsigned int);
    char* NiGlobalStringTable_FindString(const char* key, unsigned int length);
};
// Hashes key, locks the table, scans the bucket's entries for an exact match, and returns the stored string or null.
// @fnv 0x00a5b300
// src: XBOX_PDB 0x00a5b300
char* StringTable169::NiGlobalStringTable_FindString(const char* key, unsigned int length)
{
    unsigned int uiHash = NiGlobalStringTable_HashFunction(key, length);
    CRITICAL_SECTION_STUB* bucket = &lock;
    EnterCriticalSection(bucket);
    unsigned int idx = buckets[uiHash].count;
    for (unsigned int i = 0; i < idx; ++i)
    {
        char* tmp = buckets[uiHash].entries[i];
        if (tmp == key ||
            (tmp && (reinterpret_cast<const StringRecord169*>(tmp) - 1)->length == length && strcmp(tmp, key) == 0))
        {
            LeaveCriticalSection(bucket);
            return tmp;
        }
    }
    LeaveCriticalSection(bucket);
    return 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) void __stdcall fnv_EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall fnv_LeaveCriticalSection(void* cs);
extern unsigned char DAT_011f4380;
void* __cdecl _NiMalloc_00aa1070(unsigned int size);
void __cdecl NiFreeAlias(void*);
extern "C" void* __cdecl memmove(void* dst, const void* src, unsigned int n);
struct ExtraName
{
    const char* handle;
    operator const char*() const
    {
        return handle;
    }
};

struct Holder : NiObjectNET
{
    bool NiObjectNET_AddExtraData(NiTexture* p);
};
// Inserts p into the sorted texture array, growing it as needed, and returns false if a duplicate name is found.
// @fnv 0x00a5ba40
// src: COMMUNITY 0x00a5ba40
bool Holder::NiObjectNET_AddExtraData(NiTexture* p)
{
    if (!p)
        return false;
    InterlockedIncrement((volatile long*)&p->m_uiRefCount);
    fnv_EnterCriticalSection(&DAT_011f4380);
    if (m_usMaxSize < 1)
    {
        m_usExtraDataSize = m_usMaxSize = 1;
        m_ppkExtra = (NiExtraData**)_NiMalloc_00aa1070(4);
        m_ppkExtra[0] = (NiExtraData*)p;
        fnv_LeaveCriticalSection(&DAT_011f4380);
        return true;
    }
    if (m_usExtraDataSize == m_usMaxSize)
    {
        m_usMaxSize = (unsigned short)(m_usMaxSize * 2 + 1);
        NiTexture** newData = (NiTexture**)_NiMalloc_00aa1070(m_usMaxSize * 4);
        memmove(newData, m_ppkExtra, m_usExtraDataSize * 4);
        NiFreeAlias(m_ppkExtra);
        m_ppkExtra = (NiExtraData**)newData;
    }
    m_ppkExtra[m_usExtraDataSize] = (NiExtraData*)p;
    ++m_usExtraDataSize;
    unsigned short j;
    for (j = m_usExtraDataSize; j < m_usMaxSize; ++j)
        m_ppkExtra[j] = 0;
    for (j = (unsigned short)(m_usExtraDataSize - 1); j > 0; --j)
    {
        NiTexture**& data = reinterpret_cast<NiTexture**&>(m_ppkExtra);
        int diff = data[j - 1]->GetFilename_00a62660() - data[j]->GetFilename_00a62660();
        if (diff == 0)
        {
            DeleteExtraData(j);
            fnv_LeaveCriticalSection(&DAT_011f4380);
            return false;
        }
        if (diff <= 0)
            break;
        NiExtraData* tmp = m_ppkExtra[j - 1];
        m_ppkExtra[j - 1] = m_ppkExtra[j];
        m_ppkExtra[j] = tmp;
    }
    fnv_LeaveCriticalSection(&DAT_011f4380);
    return true;
}

#include <windows.h>

struct a53540_Counted
{
    virtual void v00();
    virtual void Release();
    int refCount;
};

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00a53540_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    a53540_Counted* m_pCounted;
    int unk14;
    int unk18;
    int unk1c;

    void BaseCleanup();
    FUN_00a53540_cls* NiFloatInterpolator_Destroy_deleting_destructor_(unsigned char acFlags);
};

// Releases the m_pCounted reference, calls BaseCleanup, and frees this memory if acFlags has bit 0 set.
// @fnv 0x00a53540
// src: COMMUNITY 0x00a53540
FUN_00a53540_cls* FUN_00a53540_cls::NiFloatInterpolator_Destroy_deleting_destructor_(unsigned char acFlags)
{
    a53540_Counted* pCounted = *(a53540_Counted* volatile*)&m_pCounted;
    if (pCounted != 0)
    {
        if (InterlockedDecrement((long volatile*)&pCounted->refCount) == 0)
        {
            pCounted->Release();
        }
    }
    BaseCleanup();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x18);
    }
    return this;
}

// Locks the table and, for each of its 513 buckets, frees string records whose refs is zero and clears their entry slots.
// @fnv 0x00a5b3c0
// src: COMMUNITY 0x00a5b3c0
void SingletonTarget::NiGlobalStringTable_FreeStrings()
{
    struct
    {
        CRITICAL_SECTION_STUB* m_pkLock;
        unsigned int m_uiLockCount;
    } kLock;
    // View of each StringBucket169 starting at its entries field (the bucket's vtable slot is never read here).
    struct BucketView
    {
        char** entries;
        unsigned short capacity;
        unsigned short count;
        unsigned short used;
        unsigned short grow;
        unsigned int nextVtable;
    };
    StringTable169* pkTable = (StringTable169*)this;
    kLock.m_pkLock = &pkTable->lock;
    EnterCriticalSection(kLock.m_pkLock);
    BucketView* pkBucket = (BucketView*)&pkTable->buckets[0].entries;
    unsigned int uiHash = 0x201;
    do
    {
        unsigned int uiSize = pkBucket->count;
        for (unsigned int ui = 0; ui < uiSize; ++ui)
        {
            char* pcString = pkBucket->entries[ui];
            if (pcString)
            {
                StringRecord169* pkRecord = (StringRecord169*)(pcString - 8);
                if (pkRecord->refs == 0)
                {
                    _NiFree_00aa10f0(pkRecord);
                    if (ui >= pkBucket->count)
                    {
                        pkBucket->count = ui + 1;
                    }
                    else if (pkBucket->entries[ui] != 0)
                    {
                        pkBucket->used--;
                    }
                    pkBucket->entries[ui] = 0;
                }
            }
        }
        pkBucket++;
    } while (--uiHash);
    LeaveCriticalSection(kLock.m_pkLock);
}

// Unlinks the given NiTexture node from the doubly linked list guarded by DAT_011f4580, updating head, tail and neighbour pointers.
// @fnv 0x00a5f800
// src: XBOX_PDB 0x00a5f800
void __fastcall NiTexture_RemoveTextureFromList(NiTexture* texture)
{
    EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION_STUB*>(&DAT_011f4580));
    if (DAT_011f4500 == reinterpret_cast<int>(texture))
    {
        DAT_011f4500 = reinterpret_cast<int>(texture->m_pkNext);
    }
    if (DAT_011f4504 == reinterpret_cast<int>(texture))
    {
        DAT_011f4504 = reinterpret_cast<int>(texture->m_pkPrev);
    }
    if (texture->m_pkPrev)
    {
        texture->m_pkPrev->m_pkNext = texture->m_pkNext;
    }
    if (texture->m_pkNext)
    {
        texture->m_pkNext->m_pkPrev = texture->m_pkPrev;
    }
    LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION_STUB*>(&DAT_011f4580));
}
