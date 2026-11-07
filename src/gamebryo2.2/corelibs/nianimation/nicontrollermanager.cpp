// gamebryo2.2/corelibs/nianimation/nicontrollermanager.cpp (40 functions)

#include "../../../../include/NiControllerManager.h"
#include "../../../../include/NiTFixedStringMap.h"
#include "../../../../include/NiControllerSequence.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiTFixedStringMap_NiAVObject___.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiTMapBase.h"
#include "../../../../include/NiTMapItem.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/NiTStringTemplateMap.h"
#include "../../../../include/NiTStringPointerMap.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiTArray.h"
#include "../../../../include/NiTPrimitiveArray.h"
#include <stddef.h>

__declspec(noinline) NiTPrimitiveArray<BSAnimNoteListener*>* __fastcall ConstructListenerArray(
    NiTPrimitiveArray<BSAnimNoteListener*>* array) throw();

template <>
__declspec(nothrow) unsigned int NiTArray<NiPointer<NiControllerSequence>, NiTNewInterface<NiPointer<NiControllerSequence> > >::AddFirstEmpty(
    const NiPointer<NiControllerSequence>& element);

// Unit-specific container helpers use the shared controller layouts.
#define FNV_JOIN_INNER(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_INNER(a, b)
#define FNV_STATIC_ASSERT(x) typedef char FNV_JOIN(fnv_assert_, __LINE__)[(x) ? 1 : -1]
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
FNV_STATIC_ASSERT(sizeof(NiRefObject) == 8);
FNV_STATIC_ASSERT(sizeof(NiPointer<NiControllerSequence>) == 4);
FNV_STATIC_ASSERT(sizeof(NiTObjectArray<NiPointer<NiControllerSequence> >) == 16);
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveSet<NiControllerSequence*>) == 12);
FNV_STATIC_ASSERT(sizeof(NiTStringPointerMap<NiControllerSequence*>) == 20);
FNV_STATIC_ASSERT(sizeof(NiUpdateData) == 12);
FNV_STATIC_ASSERT(sizeof(NiTimeController) == 0x34);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_uiObjectFlags) == 8);
FNV_STATIC_ASSERT(sizeof(NiControllerSequence) == 0x74);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_eAnimationState) == 0x44);
FNV_STATIC_ASSERT(sizeof(NiControllerManager) == 0x7c);
FNV_STATIC_ASSERT(offsetof(NiControllerManager, m_kPlayingSequences) == 0x44);
FNV_STATIC_ASSERT(offsetof(NiControllerManager, m_kSequenceSet) == 0x6c);
FNV_STATIC_ASSERT(offsetof(NiControllerManager, m_spControllerManager) == 0x78);

// These ABI adapters cover target/name overloads and a base post-link override
// absent from the approved headers. They introduce no controller stand-in types.
extern "C" void BindSequenceTarget();
extern "C" void SetSequenceRootName();
extern "C" void SetSequenceName();
extern "C" void PostLinkTimeController();
// ThisCallStub has no bases, so its member pointers are one code address (NiRefObject's NiMemObject base makes
// Ni class member pointers carry a this-adjustment).
struct ThisCallStub
{
};
__forceinline bool BindSequence(NiControllerSequence* sequence, int target)
{
    typedef bool (ThisCallStub::*BindTarget)(int);
    BindTarget method;
    *(void**)&method = (void*)&BindSequenceTarget;
    return (((ThisCallStub*)sequence)->*method)(target);
}

// @fnv 0x00a2e220
void NiControllerManager::Update(NiUpdateData& kData)
{
    if ((static_cast<unsigned char>(m_uiObjectFlags >> 3) & 1) != 0)
    {
        for (unsigned int i = 0; i < m_kPlayingSequences.m_uiUsed; ++i)
        {
            NiControllerSequence* pkSequence = m_kPlayingSequences.m_pBase[i];
            pkSequence->Update(kData.fTime, true);
            if (pkSequence->m_eAnimationState == NiControllerSequence::INACTIVE)
            {
                --m_kPlayingSequences.m_uiUsed;
                m_kPlayingSequences.m_pBase[i] = m_kPlayingSequences.m_pBase[m_kPlayingSequences.m_uiUsed];
                --i;
            }
        }
    }
}

extern bool DAT_011f369b;
extern unsigned char DAT_011f3763;
extern void* DAT_011f3ddc;
extern void* DAT_011f3a7c;
extern void* DAT_011f39ec;
extern void* DAT_011f395c;
extern void* DAT_011f38cc;

void __cdecl CreateVertexRecords();
void __cdecl Runtime_ApplyAnimationsToTarget();
void __cdecl Runtime_UpdateState_00a2a7b0();
void __cdecl AllocateTempArray();
void __cdecl NiStepPosKey_DeleteArray();
void __cdecl NiStepPosKey_InterpolateD1_RegisterSevenKeyHandlers(int, int);

// If not already initialized, marks it initialized, stores five function pointers into globals, sets a byte to 0x10, calls FUN_00a2d5b0(1, 5), and returns 1.
// @fnv 0x00a2d610
// src: GAMEBRYO_LIB 0x00a2d610
int __cdecl NiStepPosKey_RegisterLoader()
{
    if (DAT_011f369b)
        return 0;
    DAT_011f369b = true;
    DAT_011f3ddc = (void*)&CreateVertexRecords;
    DAT_011f3a7c = (void*)&Runtime_ApplyAnimationsToTarget;
    DAT_011f39ec = (void*)&Runtime_UpdateState_00a2a7b0;
    DAT_011f395c = (void*)&AllocateTempArray;
    DAT_011f38cc = (void*)&NiStepPosKey_DeleteArray;
    DAT_011f3763 = 0x10;
    NiStepPosKey_InterpolateD1_RegisterSevenKeyHandlers(1, 5);
    return 1;
}

extern int DAT_01096114;
extern int DAT_0109618c;
extern int DAT_01096284;

void __fastcall _Call_a5d3a0(void*);
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);
void __fastcall FUN_00a6e960(void*);

__forceinline void init_map(int* map, int size)
{
    map[0] = reinterpret_cast<int>(&DAT_01096114);
    map[1] = size;
    map[3] = 0;
    void* mem = _NiMalloc(size * 4);
    map[2] = reinterpret_cast<int>(mem);
    _fnv_zlib_memset(mem, 0, map[1] * 4);
    map[0] = reinterpret_cast<int>(&DAT_0109618c);
}

// @fnv 0x00a2ed80
// src: EXE 0x00a2ed80
int* __fastcall NiDefaultAVObjectPalette_NiDefaultAVObjectPalette(int* this_ptr, int, int arg1, int arg2)
{
    _Call_a5d3a0(this_ptr);
    this_ptr[0] = reinterpret_cast<int>(&DAT_01096284);
    init_map(this_ptr + 2, arg2);
    this_ptr[6] = arg1;
    FUN_00a6e960(this_ptr);
    return this_ptr;
}

struct HashItem
{
    HashItem* m_pkNext;
    unsigned int m_kControlPoint;
    void* m_val;
};

struct HashObj
{
    char pad[0xc];
    unsigned int m_uiHashSize;
    HashItem** m_ppkHashTable;
};

// Looks up a key in the hash table by key modulo hash size, walking the bucket chain and returning the matching item's value or 0.
// @fnv 0x00a2ee00
// src: XBOX_PDB 0x00a2ee00
void* __fastcall NiDefaultAVObjectPalette_GetAVObject(HashObj* pThis, int, const unsigned int* pKey)
{
    unsigned int key = *pKey;
    if (key)
    {
        HashItem* item = pThis->m_ppkHashTable[key % pThis->m_uiHashSize];
        while (item)
        {
            if (key == item->m_kControlPoint)
                return item->m_val;
            item = item->m_pkNext;
        }
    }
    return 0;
}

extern int DAT_0109607c;
extern int DAT_01096114;
extern int DAT_0109618c;
extern int DAT_01096284;

__declspec(nothrow) void __cdecl _NiFreeAlias(void*);
void __cdecl FUN_00aa1460(void*, unsigned int);


struct NiObject_Helper
{
    void FUN_00a5d3d0();
};

// @fnv 0x00a2ee70
void* __fastcall FUN_00a2ee70(int* pThis, int, unsigned int flags)
{
    int* pMap = pThis + 2;
    *pThis = (int)&DAT_01096284;
    *pMap = (int)&DAT_0109618c;
    reinterpret_cast<NiTFixedStringMap_NiAVObject___*>(pMap)->RemoveAll();
    *pMap = (int)&DAT_01096114;
    reinterpret_cast<NiTFixedStringMap_NiAVObject___*>(pMap)->RemoveAll();
    _NiFreeAlias(reinterpret_cast<void*>(pMap[2]));
    *pThis = (int)&DAT_0109607c;
    reinterpret_cast<NiObject_Helper*>(pThis)->FUN_00a5d3d0();
    if (flags & 1)
    {
        FUN_00aa1460(pThis, 0x1c);
    }
    return pThis;
}

void __fastcall NiTObjectArray_UpdateReferenceState_00a2ebb0(void* pThis);
void __cdecl FUN_00aa1460(void* p, size_t size);

// @fnv 0x00a2ef80
void* __fastcall FUN_00a2ef80(void* pThis, int, unsigned int flags)
{
    NiTObjectArray_UpdateReferenceState_00a2ebb0(pThis);
    if (flags & 1)
    {
        FUN_00aa1460(pThis, 0x7c);
    }
    return pThis;
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];

extern int DAT_011f49e0;

struct CloneableObj
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
    virtual CloneableObj* MakeClone(CloningProcess* kCloning);
    volatile long m_uiRefCount;

    void FUN_00a6cfe0(NiControllerManager* pkDest, CloningProcess* kCloning);
    bool AttachSeqToOwner(void* pkSequence, void* kName, int bStoreTargets);
};

// Clones the controller manager into pkDest: copies the flag at 0x68, clones each sequence and the palette, and updates reference counts.
// @fnv 0x00a2f380
void NiControllerManager::CloneControllerManager(NiControllerManager* pkDest, CloningProcess* kCloning)
{
    ((CloneableObj*)this)->FUN_00a6cfe0(pkDest, kCloning);
    *(bool*)((char*)pkDest + 0x68) = *(bool*)((char*)this + 0x68);

    for (unsigned int ui = 0; ui < *(unsigned short*)((char*)this + 0x3e); ui++)
    {
        CloneableObj* pkSequence = (*(CloneableObj***)((char*)this + 0x38))[ui];
        if (pkSequence)
        {
            CloneableObj* pkNewSequence = pkSequence->MakeClone(kCloning);
            ((CloneableObj*)pkDest)->AttachSeqToOwner(pkNewSequence, &DAT_011f49e0, 0);
        }
    }

    CloneableObj* pkPalette = *(CloneableObj**)((char*)this + 0x78);
    if (pkPalette)
    {
        CloneableObj* pkNewPalette = pkPalette->MakeClone(kCloning);
        CloneableObj* pkOldPalette = *(CloneableObj**)((char*)pkDest + 0x78);
        if (pkOldPalette != pkNewPalette)
        {
            if (pkOldPalette)
            {
                if (InterlockedDecrement(&pkOldPalette->m_uiRefCount) == 0)
                    pkOldPalette->DeleteThis();
            }
            *(CloneableObj**)((char*)pkDest + 0x78) = pkNewPalette;
            if (pkNewPalette)
                InterlockedIncrement(&pkNewPalette->m_uiRefCount);
        }
    }
}

extern const char g_011f4a04_arg1[];
// @fnv 0x00a2e1e0
// src: COMMUNITY 0x00a2e1e0
const char* __cdecl NiAVObjectPalette_GetRTTI()
{
    return g_011f4a04_arg1;
}


// @fnv 0x00a2e420
// src: XBOX_PDB 0x00a2e420
unsigned char __fastcall NiControllerManager_StopTransSourceSequence(NiControllerManager* self, int, float f)
{
    unsigned int i = 0;
    while (i < *(unsigned int*)((char*)self + 0x4c))
    {
        void* p = *(void**)((char*)*(void**)((char*)self + 0x44) + i * 4);
        if (*(unsigned int*)((char*)p + 0x44) == 4)
        {
            void** vtbl = (void**)p;
            void* obj = *vtbl;
            void** v2 = (void**)((char*)obj + 0x8c);
            (*(void(__thiscall**)(void*, float, unsigned int))v2)(p, f, 0);
        }
        ++i;
    }
    return 0;
}

extern MemoryManager g_memoryManager;

inline void __cdecl operator delete(void* object)
{
    g_memoryManager.Deallocate(object);
}

// RTTI vftables 0x01096124 / 0x01096144 identify this pointer-map specialization.
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiControllerSequence*> SequenceMapBase;
typedef NiTPointerMap<const char*, NiControllerSequence*> SequencePointerMap;
typedef NiTStringTemplateMap<SequencePointerMap, NiControllerSequence*> SequenceStringMap;

template <>
__declspec(nothrow) void SequenceMapBase::RemoveAll();

// @fnv 0x00a2e4d0 (scalar deleting destructor)
template <class TAlloc, class TKEY, class TVAL>
inline NiTMapBase<TAlloc, TKEY, TVAL>::~NiTMapBase()
{
    RemoveAll();
    _NiFreeAlias(m_ppkHashTable);
}

// @fnv 0x00a2e510 (scalar deleting destructor)
template <class TKEY, class TVAL>
inline NiTPointerMap<TKEY, TVAL>::~NiTPointerMap()
{
    RemoveAll();
}

// @fnv 0x00a2e460
// The string layer owns copied keys and releases them before the map nodes.
template <class TPARENT, class TVAL>
__declspec(noinline) NiTStringTemplateMap<TPARENT, TVAL>::~NiTStringTemplateMap()
{
    if (m_bCopy != 0)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            NiTMapItem<const char*, TVAL>* node = m_ppkHashTable[i];
            while (node != 0)
            {
                NiTMapItem<const char*, TVAL>* cur = node;
                const char* key = cur->m_key;
                node = cur->m_pkNext;
                _NiFreeAlias((void*)key);
            }
        }
    }
}

template class NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiControllerSequence*>;
template class NiTPointerMap<const char*, NiControllerSequence*>;



// @fnv 0x00a2e550 (scalar deleting destructor)
template <class TVAL>
inline NiTStringPointerMap<TVAL>::~NiTStringPointerMap()
{}

namespace fnv_00a2ebb0 {
extern int DAT_0109619c;
extern int DAT_01096184;
void __cdecl NiFree(void*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RC
{
    virtual void V0();
    virtual void Del();
    long refs;
};
extern MemoryManager g_memoryManager;
void __cdecl ReleaseObjectArray(void*);
struct S450
{
    void ClearAndDestroy();
};
struct S290
{
    void FUN_00a6d290();
};

// @fnv 0x00a2ebb0
// src: GUESS 0x00a2ebb0 (confidence: low)
void __fastcall NiTObjectArray_UpdateReferenceState_00a2ebb0(char* self)
{
    char* b = self + 0x34;
    *(void**)self = &DAT_0109619c;
    reinterpret_cast<NiTObjectArray<NiPointer<NiControllerSequence> >*>(b)->RemoveAll();
    S450* p = *(S450**)(self + 0x64);
    *(int*)(self + 0x74) = 0;
    if (p)
    {
        p->ClearAndDestroy();
        g_memoryManager._DeallocateAlias(p);
    }
    RC* o = *(RC**)(self + 0x78);
    if (o)
        if (InterlockedDecrement(&o->refs) == 0)
            o->Del();
    ReleaseObjectArray(*(void**)(self + 0x6c));
    ((SequenceStringMap*)(self + 0x50))->SequenceStringMap::~NiTStringTemplateMap();
    NiFree(*(void**)(self + 0x44));
    *(void**)b = &DAT_01096184;
    ReleaseObjectArray(*(void**)(b + 4));
    ((S290*)self)->FUN_00a6d290();
}
}  // namespace fnv_00a2ebb0

extern NiRTTI DAT_011f36ac;
// @fnv 0x00a2ec40
// src: COMMUNITY 0x00a2ec40
const NiRTTI* __cdecl NiControllerManager_GetRTTI()
{
    return &DAT_011f36ac;
}

struct GlobalObjectO2_00a7b610
{
    int x;
};
extern GlobalObjectO2_00a7b610 g_011f4a04;
// @fnv 0x00a2ede0
// src: COMMUNITY 0x00a2ede0
GlobalObjectO2_00a7b610* __cdecl NiDefaultAVObjectPalette_GetRTTI()
{
    return &g_011f4a04;
}

// @fnv 0x00a2edf0
// src: XBOX_PDB 0x00a2edf0
void __fastcall NiDefaultAVObjectPalette_SetScene(char* self, int edx, void* scene)
{
    *(void**)(self + 0x18) = scene;
}

struct Stub
{
    void NiTStringPointerMap_NiAVObject_RemoveAt(NiFixedString&);
};
typedef NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString, const char*> >, const char*> Map;

// @fnv 0x00a2ee40
// src: GAMEBRYO_LIB 0x00a2ee40
void __fastcall NiDefaultAVObjectPalette_SetAVObject(char* self, int edx, NiFixedString& name, const char* obj)
{
    if (!obj)
    {
        ((Stub*)(self + 8))->NiTStringPointerMap_NiAVObject_RemoveAt(name);
        return;
    }
    ((Map*)(self + 8))->SetAt(name, obj);
}

class NiShader;
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern int EmptyFS;

// @fnv 0x00a2f0c0
bool __fastcall AttachSeqToOwner(NiControllerManager* pOwner, int edx, NiControllerSequence* s, int* name, NiControllerSequence* flag)
{
    if (pOwner && s->m_pkOwnerManager)
        return false;
    s->m_pkOwnerManager = pOwner;
    if (s->m_kAccumulationRootName.m_kHandle == 0)
    {
        typedef bool (ThisCallStub::*SetRoot)(int);
        SetRoot method;
        *(void**)&method = (void*)&SetSequenceRootName;
        (((ThisCallStub*)s)->*method)(*(int*)&pOwner->m_pkTarget + 8);
    }
    // Use the target-pointer ABI; the shared bool overload narrows this argument.
    typedef bool (ThisCallStub::*BindTarget)(int);
    BindTarget bind;
    *(void**)&bind = (void*)&BindSequenceTarget;
    if ((char)(int)flag && !(((ThisCallStub*)s)->*bind)(*(int*)&pOwner->m_pkTarget))
    {
        s->m_pkOwnerManager = 0;
        return false;
    }
    if (*name != EmptyFS)
    {
        typedef void (ThisCallStub::*SetName)(int*);
        SetName method;
        *(void**)&method = (void*)&SetSequenceName;
        (((ThisCallStub*)s)->*method)(name);
    }
    flag = s;
    InterlockedIncrement((volatile long*)&s->m_uiRefCount);
    pOwner->m_kSequences.AddFirstEmpty(reinterpret_cast<const NiPointer<NiControllerSequence>&>(flag));
    if (InterlockedDecrement((volatile long*)&s->m_uiRefCount) == 0)
        s->DeleteThis();
    ((NiTStringPointerMap<NiControllerSequence*>*)((char*)pOwner + 0x50))->SetAt(s->m_kName.m_kHandle, s);
    return true;
}

namespace fnv_00a2f850 {
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];


// @fnv 0x00a2f850
// src: XBOX_PDB 0x00a2f850
NiObject* __fastcall NiControllerManager_CreateClone(NiControllerManager* self, int, CloningProcess* kCloning)
{
    BSFadeNode* mem = (BSFadeNode*)BSFadeNode::operator new(0x7c);
    NiObject* pkObject;
    if (mem)
    {
        pkObject = (NiObject*)mem->FUN_00a2eed0();
    }
    else
    {
        pkObject = 0;
    }
    self->CloneControllerManager((NiControllerManager*)pkObject, (::CloningProcess*)kCloning);
    return pkObject;
}
}  // namespace fnv_00a2f850

namespace fnv_00a2e2e0 {

// @fnv 0x00a2e2e0
// src: XBOX_PDB 0x00a2e2e0
void __fastcall NiControllerManager_PostLinkObject(NiControllerManager* self, int, NiStream* kStream)
{
    ((void (__thiscall*)(NiTimeController*, ::NiStream&))&PostLinkTimeController)(self, *kStream);
    NiAVObject* pkRoot;
    unsigned int ui;
    NiControllerSequence* pkSequence;
    pkRoot = *(NiAVObject**)((char*)self + 0x2c);
    for (ui = 0; ui < *(unsigned short*)((char*)self + 0x3e); ui++)
    {
        pkSequence = (*(NiControllerSequence***)((char*)self + 0x38))[ui];
        if (pkSequence)
            BindSequence(pkSequence, (int)pkRoot);
    }
}
}  // namespace fnv_00a2e2e0

// @fnv 0x00a2f6c0
// src: EXE 0x00a2f6c0
void* __cdecl NiControllerManager_CreateObject()
{
    BSFadeNode* p = (BSFadeNode*)BSFadeNode::operator new(0x7c);
    if (p)
        return p->FUN_00a2eed0();
    return 0;
}

namespace fnv_00a2eb40 {
void _NiFreeAlias(void*);
extern MemoryManager g_memoryManager;
extern int DAT_01096114;
extern int DAT_0109618c;
}  // namespace fnv_00a2eb40

// @fnv 0x00a2eb40
void* NiTFixedStringMap_NiAVObject___::Destroy(int auiFlags)
{
    *(void**)this = &fnv_00a2eb40::DAT_0109618c;
    RemoveAll();
    *(void**)this = &fnv_00a2eb40::DAT_01096114;
    RemoveAll();
    fnv_00a2eb40::_NiFreeAlias(*(void**)((char*)this + 8));
    if (auiFlags & 1)
        fnv_00a2eb40::g_memoryManager.Deallocate(this);
    return this;
}

namespace fnv_00a2efa0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
void __fastcall FUN_00a6d220(void*);
extern void* DAT_0109619c;
extern void* DAT_01096258;
extern void* DAT_01096124;
extern void* DAT_01096260;
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct CtrlRefObj
{
    virtual void v0();
    virtual void DeleteThis();
    long m_uiRefCount;
    CtrlRefObj* NiDefaultAVObjectPalette_NiDefaultAVObjectPalette(NiObjectNET*, int);
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct CtrlPtr
{
    CtrlRefObj* m_pObject;
    CtrlPtr& operator=(CtrlRefObj* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
// 0x01096258 is the sequence-array vftable; initialize the shared layout in constructor order.
inline void InitializeSequenceArray(NiTObjectArray<NiPointer<NiControllerSequence> >& array,
                                    unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    array.m_usMaxSize = (unsigned short)uiMaxSize;
    array.m_usGrowBy = (unsigned short)uiGrowBy;
    array.m_usSize = 0;
    array.m_usESize = 0;
    if (array.m_usGrowBy == 0)
        array.m_usGrowBy = 1;
    if (array.m_usMaxSize > 0)
        array.m_pBase = (NiPointer<NiControllerSequence>*)_NiMalloc(array.m_usMaxSize * 4);
    else
        array.m_pBase = 0;
    *(void***)&array = (void**)&DAT_01096258;
}
inline void InitializeSequenceMap(NiTStringPointerMap<NiControllerSequence*>* map, unsigned int uiHashSize)
{
    *(void***)map = (void**)&DAT_01096124;
    map->m_uiHashSize = uiHashSize;
    map->m_kItemCount.m_uiCount = 0;
    map->m_ppkHashTable = (SequenceMapBase::EntryType**)_NiMalloc(uiHashSize * 4);
    fnv_zlib_memset(map->m_ppkHashTable, 0, map->m_uiHashSize * 4);
    map->m_bCopy = false;
    *(void***)map = (void**)&DAT_01096260;
}
struct NiListStandin
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    void Construct()
    {
        m_pkHead = 0;
        m_pkTail = 0;
        m_uiCount = 0;
    }
};

// @fnv 0x00a2efa0
// src: EXE 0x00a2efa0
NiControllerManager* __fastcall NiControllerManager_NiControllerManager(NiControllerManager* self, int, NiObjectNET* pkTarget, bool bCumulative)
{
    FUN_00a6d220(self);
    *(void***)self = (void**)&DAT_0109619c;
    InitializeSequenceArray(self->m_kSequences, 0, 10);
    self->m_kPlayingSequences.m_pBase = 0;
    self->m_kPlayingSequences.m_uiAlloced = 0;
    self->m_kPlayingSequences.m_uiUsed = 0;
    InitializeSequenceMap(&self->m_kObjectMap, 0x25);
    self->m_bUseCumulativeAnimation = bCumulative;
    ((NiListStandin*)&self->m_kSequenceSet)->Construct();
    self->m_spControllerManager.m_pObject = 0;
    self->NiTimeController::SetTarget(pkTarget);
    void* pControllerMem = BSFadeNode::operator new(0x1c);
    *(CtrlPtr*)&self->m_spControllerManager = pControllerMem ? ((CtrlRefObj*)pControllerMem)->NiDefaultAVObjectPalette_NiDefaultAVObjectPalette(pkTarget, 0x4f) : 0;
    void* pLookupMem = g_memoryManager.Allocate(0x10);
    self->m_pAudioListener = (BSAnimNoteListener*)(pLookupMem ? ConstructListenerArray((NiTPrimitiveArray<BSAnimNoteListener*>*)pLookupMem) : 0);
    return self;
}
}  // namespace fnv_00a2efa0

namespace fnv_00a2f6e0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern char* EmptyFS;

struct FS543
{
    char* m_kHandle;
    FS543& operator=(const FS543& o)
    {
        if (m_kHandle != o.m_kHandle)
        {
            char* h = o.m_kHandle;
            if (h != EmptyFS)
                InterlockedIncrement((long*)(h - 8));
            if (m_kHandle != EmptyFS)
                InterlockedDecrement((long*)(m_kHandle - 8));
            m_kHandle = h;
        }
        return *this;
    }
};
extern FS543 DAT_011f49e0;

struct CtrlHelper543
{
    void LinkObject(NiStream&);
};
// @fnv 0x00a2f6e0
// src: XBOX_PDB 0x00a2f6e0
void __fastcall NiControllerManager_LinkObject(NiControllerManager* self, int, NiStream* kStream)
{
    NiControllerManager* pkThis = (NiControllerManager*)self;
    ((CtrlHelper543*)self)->LinkObject(*kStream);
    unsigned int uiNumSequences = kStream->GetLinkID();
    pkThis->m_kSequences.SetSize(uiNumSequences);
    for (unsigned int ui = 0; ui < uiNumSequences; ui++)
    {
        NiControllerSequence* pkSequence = (NiControllerSequence*)kStream->GetLoadedObject();
        if (pkThis && pkSequence->m_pkOwnerManager)
            continue;
        pkSequence->m_pkOwnerManager = pkThis;
        if (!pkSequence->m_kAccumulationRootName.m_kHandle)
            *(FS543*)&pkSequence->m_kAccumulationRootName = *(FS543*)&pkThis->m_pkTarget->m_kName;
        if (DAT_011f49e0.m_kHandle != EmptyFS)
            *(FS543*)&pkSequence->m_kName = DAT_011f49e0;
        NiControllerSequence* pSequenceRef = pkSequence;
        InterlockedIncrement((volatile long*)&pkSequence->m_uiRefCount);
        pkThis->m_kSequences.AddFirstEmpty(reinterpret_cast<const NiPointer<NiControllerSequence>&>(pSequenceRef));
        if (InterlockedDecrement((volatile long*)&pkSequence->m_uiRefCount) == 0)
            pkSequence->DeleteThis();
        pkThis->m_kObjectMap.SetAt(pkSequence->m_kName.m_kHandle, pkSequence);
    }
}
}  // namespace fnv_00a2f6e0

extern int DAT_01096164;
extern int DAT_01096144;
extern int DAT_01096124;

void __cdecl _NiFree_00aa10f0(void* p);
void __fastcall NiTPointerMap_RemoveAll_00b601a0(void* self);

struct ItemBinding
{
    int m_iId;
    int unk04;
    int unk08;
    int unk0c;
};

// @fnv 0x00a2e570
NiControllerSequence* __fastcall FindItemByBindingId(NiControllerManager* self, int, int aiBindingId, bool abRequireFlag)
{
    unsigned int uiIndex = 0;

    while (uiIndex < self->m_kSequences.m_usSize)
    {
        NiControllerSequence* pItem = self->m_kSequences.m_pBase[uiIndex].m_pObject;

        if (pItem != 0)
        {
            InterlockedIncrement((volatile long*)&pItem->m_uiRefCount);

            if (!abRequireFlag || pItem->m_eAnimationState != 0)
            {
                unsigned int uiBindingIndex = 0;

                while (uiBindingIndex < pItem->m_uiNumControlledBlocks)
                {
                    ItemBinding* pBinding = ((ItemBinding*)pItem->m_pInterpArray) + uiBindingIndex;
                    int iBindingId = pBinding->m_iId;

                    if (iBindingId != 0 && iBindingId == aiBindingId)
                    {
                        if (InterlockedDecrement((volatile long*)&pItem->m_uiRefCount) == 0)
                        {
                            pItem->DeleteThis();
                        }

                        return pItem;
                    }

                    ++uiBindingIndex;
                }
            }

            if (InterlockedDecrement((volatile long*)&pItem->m_uiRefCount) == 0)
            {
                pItem->DeleteThis();
            }
        }

        ++uiIndex;
    }

    return 0;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
                                                unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesWritten;
    return uiBytesWritten;
}

// The shared stream keeps its backing-stream field in the opaque layout.
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

template <class T> inline unsigned int WriteStreamValue(NiBinaryStream* stream, const T* value)
{
    unsigned int uiSize = sizeof(T);
    return stream->BinaryWrite(value, sizeof(T), &uiSize, 1);
}

template <class T> inline void SerializeValue(NiStream& stream, const T& value)
{
    WriteStreamValue(stream.GetBinaryStream(), &value);
}

extern "C" void SaveTimeController();

// Calls FUN_00a6d730, writes m_bFlag and m_usArraySize, saves link IDs for each non-null m_ppArray entry and for m_pkLast.
// @fnv 0x00a2e9f0
// src: XBOX_PDB 0x00a2e9f0
void __fastcall NiControllerManager_SaveBinary(NiControllerManager* self, int, NiStream& stream)
{
    ((void (__thiscall*)(NiTimeController*, NiStream&))&SaveTimeController)(self, stream);
    bool bFlag = self->m_bUseCumulativeAnimation;
    SerializeValue(stream, bFlag);
    unsigned int uiSize = self->m_kSequences.m_usSize;
    SerializeValue(stream, uiSize);
    for (unsigned int i = 0; i < uiSize; i++)
    {
        void* pkObj = self->m_kSequences.m_pBase[i].m_pObject;
        if (pkObj)
            stream.SaveLinkID(reinterpret_cast<const NiObject*>(pkObj));
    }
    stream.SaveLinkID(reinterpret_cast<const NiObject*>(self->m_spControllerManager.m_pObject));
}

void __stdcall FUN_00a6d5e0(NiAVObject*);
struct SequenceNotifier
{
    void* unk00;
    int m_uiPending;
    int(__cdecl* m_pfnNotify)(SequenceNotifier*, unsigned char*, int, int*, int);
};
// @fnv 0x00a2eaa0
// src: XBOX_PDB 0x00a2eaa0
void __fastcall NiControllerManager_LoadBinary(NiControllerManager* self, int, NiAVObject* source)
{
    FUN_00a6d5e0(source);
    SequenceNotifier* notifier = *reinterpret_cast<SequenceNotifier**>(reinterpret_cast<char*>(source) + 0x24c);
    {
        int isActive = 1;
        unsigned char firstOutput;
        notifier->m_uiPending += notifier->m_pfnNotify(notifier, &firstOutput, 1, &isActive, 1);
        self->m_bUseCumulativeAnimation = firstOutput != 0;
    }
    source->NiStream_ReadMultipleLinkIDs();
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(source) + 0xd8) >= 0x0a010068u)
    {
        NiAVObjectPalette* replacement = source->FUN_00a64620();
        NiAVObjectPalette* old = self->m_spControllerManager.m_pObject;
        if (old != replacement)
        {
            if (old && InterlockedDecrement(reinterpret_cast<volatile long*>(reinterpret_cast<char*>(old) + 4)) == 0)
                reinterpret_cast<NiRefObject*>(old)->DeleteThis();
            self->m_spControllerManager.m_pObject = replacement;
            if (replacement)
                InterlockedIncrement(reinterpret_cast<volatile long*>(reinterpret_cast<char*>(replacement) + 4));
        }
    }
}

struct NiCtrlVt
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
    virtual void v21(int);
};

struct FnvStandInA
{
    bool NiTimeController_RegisterStreamables(int arg);
};

struct FnvStandInB
{
    int* NiDefaultAVObjectPalette_NiDefaultAVObjectPalette(int arg1, int arg2);
};

void* __cdecl Object_DispatchCommandFour(unsigned int size);


// @fnv 0x00a2f610
// src: XBOX_PDB 0x00a2f610
bool __fastcall NiControllerManager_RegisterStreamables(NiControllerManager* self, int, int arg)
{
    if (!((FnvStandInA*)self)->NiTimeController_RegisterStreamables(arg))
    {
        return false;
    }
    for (unsigned int i = 0; i < self->m_kSequences.m_usSize; i++)
    {
        NiCtrlVt* seq = (NiCtrlVt*)self->m_kSequences.m_pBase[i].m_pObject;
        if (seq)
        {
            seq->v21(arg);
        }
    }
    NiCtrlVt* pPalette = (NiCtrlVt*)self->m_spControllerManager.m_pObject;
    if (pPalette)
    {
        pPalette->v21(arg);
        return true;
    }

    NiRefObject* pNewPalette;
    void* mem = Object_DispatchCommandFour(0x1c);
    if (mem != 0)
    {
        int owner = (int)self->m_pkTarget;
        pNewPalette = (NiRefObject*)((FnvStandInB*)mem)->NiDefaultAVObjectPalette_NiDefaultAVObjectPalette(owner, 0x25);
    }
    else
    {
        pNewPalette = 0;
    }
    NiRefObject* old = (NiRefObject*)self->m_spControllerManager.m_pObject;
    if (old != pNewPalette)
    {
        if (old)
        {
            if (InterlockedDecrement((volatile long*)&old->m_uiRefCount) == 0)
            {
                old->DeleteThis();
            }
        }
        self->m_spControllerManager.m_pObject = (NiAVObjectPalette*)pNewPalette;
        if (pNewPalette)
        {
            InterlockedIncrement((volatile long*)&pNewPalette->m_uiRefCount);
        }
    }
    return true;
}

extern int ListenerArrayVftable;
// The original no-argument constructor ABI is retained while initializing the shared array type.
// @fnv 0x00a414f0
__declspec(noinline) NiTPrimitiveArray<BSAnimNoteListener*>* __fastcall ConstructListenerArray(
    NiTPrimitiveArray<BSAnimNoteListener*>* array) throw()
{
    array->m_usMaxSize = 0;
    array->m_usGrowBy = 1;
    array->m_usSize = 0;
    array->m_usESize = 0;
    array->m_pBase = 0;
    *(void**)array = &ListenerArrayVftable;
    return array;
}

template <class TAlloc, class TKEY, class TVAL>
__forceinline void* NiTMapBase<TAlloc, TKEY, TVAL>::GetFirstPos() const
{
    const unsigned int count = m_uiHashSize;
    unsigned int i = 0;
    if (count > 0)
    {
        EntryType** buckets = m_ppkHashTable;
        EntryType** current = buckets;
        do
        {
            if (*current != 0)
                return buckets[i];
            ++i;
            ++current;
        } while (i < count);
    }
    return 0;
}
struct FNV_Comparable
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
    virtual bool NiTimeController_IsEqual(FNV_Comparable* rhs);
};
struct FNV_EqualBase
{
    bool NiTimeController_IsEqual(FNV_EqualBase* rhs);
};

// Compares this controller manager with rhs: base equality, map entries by key, then each object pointer pair, returning false on any mismatch.
// @fnv 0x00a2e320
// src: XBOX_PDB 0x00a2e320
bool __fastcall NiControllerManager_IsEqual(NiControllerManager* self, int, NiControllerManager* apOther)
{
    NiControllerManager* other = apOther;
    if (!reinterpret_cast<FNV_EqualBase*>(self)->NiTimeController_IsEqual(reinterpret_cast<FNV_EqualBase*>(other)))
        return false;
    if (self->m_kSequences.m_usSize != other->m_kSequences.m_usSize)
        return false;

    SequenceMapBase* map = &self->m_kObjectMap;
    void* position = map->GetFirstPos();
    while (position != 0)
    {
        const char* key;
        FNV_Comparable* item;
        FNV_Comparable* matchedItem;
        SequenceMapBase* otherMap = &other->m_kObjectMap;
        map->GetNext(position, key, reinterpret_cast<NiControllerSequence*&>(item));
        if (!otherMap->GetAt(key, reinterpret_cast<NiControllerSequence*&>(matchedItem)))
            return false;
        if (!item->NiTimeController_IsEqual(matchedItem))
            return false;
    }

    for (unsigned int j = 0; j < self->m_kSequences.m_usSize; ++j)
    {
        FNV_Comparable* left = reinterpret_cast<FNV_Comparable*>(self->m_kSequences.m_pBase[j].m_pObject);
        FNV_Comparable* right = reinterpret_cast<FNV_Comparable*>(other->m_kSequences.m_pBase[j].m_pObject);
        if (left != 0 && right != 0)
        {
            if (!left->NiTimeController_IsEqual(right))
                return false;
        }
        else if (left != right)
        {
            return false;
        }
    }
    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct CloneProc;

struct CObj
{
    virtual void v00();
    virtual void DeleteThis() throw();
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
    virtual void ProcessClone(CloneProc& kCloning);
    volatile long m_uiRefCount;
    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> __forceinline void ReleaseCloneReference(T* object) throw()
{
    if (InterlockedDecrement((volatile long*)&object->m_uiRefCount) == 0)
        object->DeleteThis();
}

template <class T> struct SPtr
{
    T* m_pObject;
    SPtr(T* p) : m_pObject(p)
    {
        if (m_pObject)
            InterlockedIncrement((volatile long*)&m_pObject->m_uiRefCount);
    }
    ~SPtr()
    {
        if (m_pObject)
            ReleaseCloneReference(m_pObject);
    }
    SPtr& operator=(const SPtr& o)
    {
        if (m_pObject != o.m_pObject)
        {
            if (m_pObject)
                ReleaseCloneReference(m_pObject);
            m_pObject = o.m_pObject;
            if (m_pObject)
                InterlockedIncrement((volatile long*)&m_pObject->m_uiRefCount);
        }
        return *this;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

template <class T> struct CSet
{
    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    __declspec(nothrow) void Realloc(unsigned int uiNewSize);
    __forceinline unsigned int Add(const T& element) throw()
    {
        if (m_uiAllocatedCapacity == m_uiElementCount)
            Realloc(m_uiElementCount > 0 ? (2 * m_uiElementCount) : 1);
        m_pBase[m_uiAllocatedCapacity++] = element;
        return m_uiAllocatedCapacity - 1;
    }
};

typedef NiTPointerMap<NiObject*, NiObject*> CloneMap;

template <>
bool NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, NiObject*>::GetAt(NiObject* const key, NiObject*& val) const
{
    unsigned int uiIndex = KeyToHashIndex(key);
    EntryType* pkItem = m_ppkHashTable[uiIndex];
    while (pkItem)
    {
        if (IsKeysEqual(key, pkItem->m_key))
        {
            val = pkItem->m_val;
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }
    return false;
}

struct CloneProc
{
    CloneMap* m_pCloneMap;
};


// @fnv 0x00a2f420
// src: XBOX_PDB 0x00a2f420
void __fastcall NiControllerManager_ProcessClone(NiControllerManager* self, int, CloneProc& kCloning)
{
    self->NiTimeController::ProcessClone(*(CloningProcess*)&kCloning);
    for (unsigned int ui = 0; ui < self->m_kSequences.m_usSize; ui++)
    {
        NiControllerSequence* pkSeq = self->m_kSequences.m_pBase[ui].m_pObject;
        if (pkSeq)
        {
            pkSeq->ProcessClone(*(CloningProcess*)&kCloning);
            BindSequence(pkSeq, (int)self->m_pkTarget);
        }
    }

    NiControllerManager* pkDest;
    {
        NiObject* pkClone = 0;
        kCloning.m_pCloneMap->GetAt((NiObject*)self, pkClone);
        pkDest = (NiControllerManager*)pkClone;
    }

    for (unsigned int ui = 0; ui < self->m_kSequenceSet.m_uiUsed; ui++)
    {
        NiObject* pkSeqClone;
        NiControllerSequence* pkSeq = self->m_kSequenceSet.m_pBase[ui].m_pObject;
        if (kCloning.m_pCloneMap->GetAt((NiObject*)pkSeq, pkSeqClone))
            ((CSet<SPtr<NiControllerSequence> >*)&pkDest->m_kSequenceSet)->Add((NiControllerSequence*)pkSeqClone);
        else
            ((CSet<SPtr<NiControllerSequence> >*)&pkDest->m_kSequenceSet)->Add(((SPtr<NiControllerSequence>*)self->m_kSequenceSet.m_pBase)[ui]);
    }

    NiAVObjectPalette* palette = self->m_spControllerManager.m_pObject;
    if (palette)
        palette->ProcessClone(*(CloningProcess*)&kCloning);
}

struct CtrlSeqOwner
{
    void NiControllerManager_RemoveSequence(NiRefObject* pkObject, NiRefObject** ppkOut);
    void ReleaseObject(NiRefObject* pkObject);
};

// Looks up pkObject via FUN_00a2e7d0 and releases the returned NiRefObject, calling DeleteThis when its ref count reaches zero.
// @fnv 0x00a2ec50
void CtrlSeqOwner::ReleaseObject(NiRefObject* pkObject)
{
    NiRefObject* pkFound = 0;
    NiControllerManager_RemoveSequence(pkObject, &pkFound);
    NiRefObject* pkRef = *(NiRefObject* volatile*)&pkFound;
    if (pkRef)
    {
        if (InterlockedDecrement((volatile long*)&pkRef->m_uiRefCount) == 0)
            pkRef->DeleteThis();
    }
}

namespace sa2e280 {

extern "C" void StartSequenceWithIntegerArguments();

// Deactivates pkSource and starts pkDest with the given arguments when pkSource is active and pkDest is not.
// @fnv 0x00a2e280
// src: XBOX_PDB 0x00a2e280
bool __stdcall NiControllerManager_CrossFade(NiControllerSequence* pkSource, NiControllerSequence* pkDest, float fTime, int iArg0, int iArg1, float fDuration,
                            int iArg2)
{
    if (!pkSource->m_eAnimationState || pkDest->m_eAnimationState)
        return false;
    pkSource->Deactivate(fTime, 0);
    typedef bool (ThisCallStub::*Start)(int, int, float, float, int, int);
    Start method;
    *(void**)&method = (void*)&StartSequenceWithIntegerArguments;
    return (((ThisCallStub*)pkDest)->*method)(iArg0, iArg1, fDuration, fTime, iArg2, 0);
}

}

inline void AcquireSequenceReference(NiRefObject* object)
{
    InterlockedIncrement((volatile long*)&object->m_uiRefCount);
}
inline void ReleaseSequenceReference(NiRefObject* object)
{
    if (InterlockedDecrement((volatile long*)&object->m_uiRefCount) == 0)
        object->DeleteThis();
}
template <class T> __declspec(nothrow) inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject)
        AcquireSequenceReference(m_pObject);
}
template <class T> __declspec(nothrow) inline NiPointer<T>::~NiPointer()
{
    if (m_pObject)
        ReleaseSequenceReference(m_pObject);
}
inline bool operator==(const NiPointer<NiControllerSequence>& left, const NiPointer<NiControllerSequence>& right)
{
    return left.m_pObject == right.m_pObject;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& source)
{
    if (m_pObject != source.m_pObject)
    {
        if (m_pObject)
            ReleaseSequenceReference(m_pObject);
        m_pObject = source.m_pObject;
        if (m_pObject)
            AcquireSequenceReference(m_pObject);
    }
    return *this;
}

// @fnv 0x00a2ec90
template <>
__declspec(nothrow) unsigned int NiTArray<NiPointer<NiControllerSequence>, NiTNewInterface<NiPointer<NiControllerSequence> > >::AddFirstEmpty(
    const NiPointer<NiControllerSequence>& element)
{
    if (operator==(element, NiPointer<NiControllerSequence>(0)))
        return 0xffffffff;

    if (m_usESize < m_usSize)
    {
        unsigned short uiIndex = m_usSize;
        for (short i = (short)(m_usSize - 1); i >= 0; i--)
        {
            if (operator==(m_pBase[i], NiPointer<NiControllerSequence>(0)))
                uiIndex = i;
            else if ((short)uiIndex != m_usSize)
                break;
        }
        int iSlot = (short)uiIndex;
        if (iSlot != m_usSize)
        {
            m_pBase[iSlot] = element;
            m_usESize++;
            return iSlot;
        }
    }

    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}

// Visible here for the insertion caller's const-reference analysis; the earlier /O2 body calls SetAt out of line.
template <>
inline void NiTArray<NiPointer<NiControllerSequence>, NiTNewInterface<NiPointer<NiControllerSequence> > >::SetAt(
    unsigned int index, const NiPointer<NiControllerSequence>& value)
{
    if (index >= m_usMaxSize)
        return;
    if (index >= m_usSize)
    {
        m_usSize = (unsigned short)(index + 1);
        if (value.m_pObject)
            ++m_usESize;
    }
    else
    {
        if (value.m_pObject)
        {
            if (!m_pBase[index].m_pObject)
                ++m_usESize;
        }
        else
        {
            if (m_pBase[index].m_pObject)
                --m_usESize;
        }
    }
    m_pBase[index] = value;
}

namespace fnv_00a2f170 {
extern const char* __cdecl FUN_00a5b690(const char*);
void* __cdecl AllocateSequence(unsigned int size) throw();
// This constructor call must retain the fixed-string reference aliasing of the original.
// The shared char-handle constructor has a noalias annotation that changes stack reuse here.
extern "C" void ConstructSequence();

class S00a2f170_FS;
extern S00a2f170_FS DAT_0109b220;
class S00a2f170_FS
{
  public:
    const char* m_pString;
    S00a2f170_FS() throw()
    {}
    S00a2f170_FS& Make(const char* text) throw()
    {
        m_pString = FUN_00a5b690(text);
        return *this;
    }
    S00a2f170_FS(const S00a2f170_FS&) throw();
    ~S00a2f170_FS() throw();
    S00a2f170_FS& operator=(const S00a2f170_FS&) throw();
    S00a2f170_FS& operator=(const char*) throw();
    bool Exists() const
    {
        return m_pString != DAT_0109b220.m_pString;
    }
};
extern S00a2f170_FS DAT_0109b220;
extern S00a2f170_FS DAT_011f49e0;

inline S00a2f170_FS::S00a2f170_FS(const S00a2f170_FS& other) throw() : m_pString(other.m_pString)
{
    if (m_pString != DAT_0109b220.m_pString)
        InterlockedIncrement((volatile long*)(m_pString - 8));
}
inline S00a2f170_FS::~S00a2f170_FS() throw()
{
    if (m_pString != DAT_0109b220.m_pString)
        InterlockedDecrement((volatile long*)(m_pString - 8));
}
inline S00a2f170_FS& S00a2f170_FS::operator=(const S00a2f170_FS& other) throw()
{
    if (m_pString != other.m_pString)
    {
        const char* incoming = other.m_pString;
        if (incoming != DAT_0109b220.m_pString)
            InterlockedIncrement((volatile long*)(incoming - 8));
        if (m_pString != DAT_0109b220.m_pString)
            InterlockedDecrement((volatile long*)(m_pString - 8));
        m_pString = incoming;
    }
    return *this;
}
inline S00a2f170_FS& S00a2f170_FS::operator=(const char* incoming) throw()
{
    if (m_pString != incoming)
    {
        if (incoming != DAT_0109b220.m_pString)
            InterlockedIncrement((volatile long*)(incoming - 8));
        if (m_pString != DAT_0109b220.m_pString)
            InterlockedDecrement((volatile long*)(m_pString - 8));
        m_pString = incoming;
    }
    return *this;
}


template <class T> class S00a2f170_Ptr
{
  public:
    T* m_pObject;
    S00a2f170_Ptr(T*) throw();
    ~S00a2f170_Ptr() throw();
    S00a2f170_Ptr& operator=(const S00a2f170_Ptr&) throw();
    bool operator!() const
    {
        return m_pObject == 0;
    }
};



class S00a2f170_TmpSet
{
  public:
    S00a2f170_Ptr<NiControllerSequence>* m_pBase;
    unsigned m_uiElementCount, m_uiAllocatedCapacity;
    void FUN_00e8ea60(const S00a2f170_Ptr<NiControllerSequence>&) throw();
    void FUN_00e8e3a0(unsigned) throw();
};
template <class T> inline S00a2f170_Ptr<T>::S00a2f170_Ptr(T* object) throw() : m_pObject(object)
{
    if (m_pObject)
        InterlockedIncrement((volatile long*)&m_pObject->m_uiRefCount);
}
template <class T> inline S00a2f170_Ptr<T>::~S00a2f170_Ptr() throw()
{
    T* object = m_pObject;
    if (object && InterlockedDecrement((volatile long*)&object->m_uiRefCount) == 0)
        object->DeleteThis();
}

template <class T> inline S00a2f170_Ptr<T>& S00a2f170_Ptr<T>::operator=(const S00a2f170_Ptr& other) throw()
{
    if (m_pObject != other.m_pObject)
    {
        T* old = m_pObject;
        if (old && InterlockedDecrement((volatile long*)&old->m_uiRefCount) == 0)
            old->DeleteThis();
        m_pObject = other.m_pObject;
        if (m_pObject)
            InterlockedIncrement((volatile long*)&m_pObject->m_uiRefCount);
    }
    return *this;
}

inline void S00a2f170_TmpSet::FUN_00e8ea60(const S00a2f170_Ptr<NiControllerSequence>& value) throw()
{
    if (m_uiAllocatedCapacity == m_uiElementCount)
        FUN_00e8e3a0(m_uiElementCount ? m_uiElementCount * 2 : 1);
    m_pBase[m_uiAllocatedCapacity++] = value;
}

}  // namespace fnv_00a2f170

// Finds or creates an inactive sequence, associates it with this manager, and passes it to a method on source.
// @fnv 0x00a2f170
NiControllerSequence* NiControllerManager::GetTempBlendSequence(NiControllerSequence* apSourceSequence, unsigned int option)
{
    using namespace fnv_00a2f170;
    NiControllerSequence* sequence = 0;
    unsigned int arraySize = apSourceSequence->m_uiNumControlledBlocks;
    for (unsigned int i = 0; i < m_kSequenceSet.m_uiUsed; ++i)
    {
        NiControllerSequence* item = m_kSequenceSet.m_pBase[i].m_pObject;
        if (item->m_eAnimationState == 0)
        {
            sequence = item;
            break;
        }
    }
    bool reused = false;
    if (!sequence)
    {
        void* memory = AllocateSequence(sizeof(NiControllerSequence));
        typedef NiControllerSequence* (__thiscall* SequenceConstructor)(void*, const S00a2f170_FS&, unsigned int, unsigned int);
        sequence = memory ? ((SequenceConstructor)&ConstructSequence)(memory, S00a2f170_FS().Make("__TempBlendSequence__"), arraySize, 12) : 0;
        ((S00a2f170_TmpSet*)&m_kSequenceSet)->FUN_00e8ea60(sequence);
        if (!sequence->m_pkOwnerManager)
        {
            sequence->m_pkOwnerManager = this;
            if (!sequence->m_kAccumulationRootName.m_kHandle)
                *(S00a2f170_FS*)&sequence->m_kAccumulationRootName = *(S00a2f170_FS*)&m_pkTarget->m_kName;
            if (fnv_00a2f170::DAT_011f49e0.Exists())
                *(S00a2f170_FS*)&sequence->m_kName = fnv_00a2f170::DAT_011f49e0;
            m_kSequences.AddFirstEmpty(sequence);
            m_kObjectMap.SetAt(sequence->m_kName.m_kHandle, sequence);
        }
    }
    else
    {
        sequence->ReleaseItems();
        if (!sequence->m_pkOwnerManager)
            sequence->m_pkOwnerManager = this;
        *(S00a2f170_FS*)&sequence->m_kAccumulationRootName = *(S00a2f170_FS*)&m_pkTarget->m_kName;
        reused = true;
    }
    apSourceSequence->PopulatePoseSequence(sequence, arraySize, option, reused);
    return sequence;
}



NiControllerSequence* __stdcall GetTempBlendSequence(NiControllerSequence* seq, int key);

// If the sequence is inactive, look up the target by key and call its FUN_00a350d0 with the given parameters, returning the result.
// @fnv 0x00a2f800
// src: XBOX_PDB 0x00a2f800
bool __stdcall NiControllerManager_BlendFromPose(NiControllerSequence* seq, float a, float b, int c, int key)
{
    if (seq->m_eAnimationState != NiControllerSequence::INACTIVE)
    {
        return false;
    }
    NiControllerSequence* pTarget = GetTempBlendSequence(seq, key);
    return pTarget->StartBlend(seq, b, a, c, 1.0f, 1.0f, 0);
}

struct FUN_00a2e1f0 : NiRefObject
{
    virtual ~FUN_00a2e1f0();
    static void operator delete(void*, unsigned int);
};
// The destructor body is empty.
// @fnv 0x00a2e1f0
FUN_00a2e1f0::~FUN_00a2e1f0()
{}

namespace fnv_00a2eb80 {
void __cdecl ReleaseObjectArray(void*);
}
// @fnv 0x00a2eb80 (scalar deleting destructor)
template <class T, class TAlloc>
inline NiTArray<T, TAlloc>::~NiTArray()
{
    fnv_00a2eb80::ReleaseObjectArray(m_pBase);
}
template class NiTArray<NiPointer<NiControllerSequence>, NiTNewInterface<NiPointer<NiControllerSequence> > >;

extern "C" void _ReadWriteBarrier(void);
void* __cdecl _NiMalloc_00aa1070(unsigned int size) throw();
void* __cdecl FUN_00ec61c0(void* p, int value, unsigned int size) throw();

struct MgrPoolStub
{
    void* Alloc(unsigned int size) throw();
};
extern MgrPoolStub DAT_011f6238;



struct MgrBlendSet
{
    void* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    void* m_pObjectPalette;
};

inline void ClearSequenceArrayStorage(NiTObjectArray<NiPointer<NiControllerSequence> >& array) throw()
{
    array.m_pBase = 0;
}

inline void InitializeSequenceArrayTail(NiControllerManager* manager) throw()
{
    manager->m_kSequences.m_usMaxSize = 0;
    manager->m_kSequences.m_usGrowBy = 10;
    manager->m_kSequences.m_usSize = 0;
    manager->m_kSequences.m_usESize = 0;
    volatile NiTPrimitiveSet<NiControllerSequence*>& active = manager->m_kPlayingSequences;
    active.m_pBase = 0;
    active.m_uiAlloced = 0;
    active.m_uiUsed = 0;
}

inline void InitializeSequenceMap(NiTStringPointerMap<NiControllerSequence*>* map) throw()
{
    map->m_uiHashSize = 0x25;
    map->m_kItemCount.m_uiCount = 0;
    map->m_ppkHashTable = (SequenceMapBase::EntryType**)_NiMalloc_00aa1070(map->m_uiHashSize * 4);
    FUN_00ec61c0(map->m_ppkHashTable, 0, map->m_uiHashSize * 4);
    map->m_bCopy = false;
}

extern int DAT_0109619c;

// Constructs the controller manager and its sequence containers, then allocates its listener.
// @fnv 0x00a2eed0
NiControllerManager* __fastcall ConstructControllerManager(NiControllerManager* self) throw()
{
    fnv_00a2efa0::FUN_00a6d220(self);
    *(void**)self = &DAT_0109619c;
    _ReadWriteBarrier();
    NiTObjectArray<NiPointer<NiControllerSequence> >* array = &self->m_kSequences;
    ClearSequenceArrayStorage(*array);
    _ReadWriteBarrier();
    *(void**)array = &fnv_00a2efa0::DAT_01096258;
    InitializeSequenceArrayTail(self);
    NiTStringPointerMap<NiControllerSequence*>* map = &self->m_kObjectMap;
    *(void**)map = &fnv_00a2efa0::DAT_01096124;
    InitializeSequenceMap(map);
    *(void**)map = &fnv_00a2efa0::DAT_01096260;
    *(volatile bool*)&self->m_bUseCumulativeAnimation = false;
    _ReadWriteBarrier();
    volatile MgrBlendSet& sequences = *(volatile MgrBlendSet*)&self->m_kSequenceSet;
    sequences.m_pBase = 0;
    sequences.m_uiElementCount = 0;
    sequences.m_uiAllocatedCapacity = 0;
    sequences.m_pObjectPalette = 0;
    void* i = DAT_011f6238.Alloc(0x10);
    if (i != 0)
    {
        self->m_pAudioListener = (BSAnimNoteListener*)ConstructListenerArray((NiTPrimitiveArray<BSAnimNoteListener*>*)i);
    }
    else
    {
        self->m_pAudioListener = 0;
    }
    return self;
}
