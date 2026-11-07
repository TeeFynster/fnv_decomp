#include "../../../../include/NiTArray.h"
#include "../../../../include/NiBoneLODController.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiSkinInstance.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTMapBase.h"
#include "../../../../include/NiTMapItem.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiUpdateData.h"

// NiStreamLinkIDSet_nibonelodcontroller: local type (was include/NiStreamLinkIDSet.h, which had no evidence of one real class); its methods are 0x00a311e0 NiTSet<NiScreenGeometryData::ScreenElement *,NiTMallocInterface<NiScreenGeometryData::ScreenElement *> >::Add, 0x00a543b0 NiTSet::Ptr::Add
class Item;
class NiGeomMorpherUpdateTask;
class D3DRenderStateGroup;

class NiStreamLinkIDSet_nibonelodcontroller
{
public:
    void* m_kPointA;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;

    void Realloc(unsigned int);
    void ProcessEntries_00a56e60(unsigned int ItemUpdateArray);
    unsigned int Find(Item* item);
    int Find(unsigned int value);
    void Add(Item* item);
    void Add(NiGeomMorpherUpdateTask* pkTask);
    void Add(D3DRenderStateGroup* p);
    void AddUnique(Item* item);
};

// src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl _NiFreeAlias(void*);
extern int DAT_0109a2a4;

struct FUN_00a543f0_shell
{
    void* m_kPointA;
    void* m_ptr;
    void ReleaseStorage_00a543f0();
};

// @fnv 0x00a543f0
// src: GUESS 0x00a543f0 (confidence: low)
void FUN_00a543f0_shell::ReleaseStorage_00a543f0()
{
    void* p = m_ptr;
    m_kPointA = &DAT_0109a2a4;
    _NiFreeAlias(p);
}

struct GlobalObjectO2_00a7b610
{
};

extern GlobalObjectO2_00a7b610 g_011f405c;

// @fnv 0x00a55120
// src: COMMUNITY 0x00a55120
GlobalObjectO2_00a7b610* __cdecl NiBoneLODController_GetRTTI()
{
    return &g_011f405c;
}

extern MemoryManager g_memoryManager;

inline void __cdecl operator delete(void* object)
{
    g_memoryManager.Deallocate(object);
}

// The original destructor has no exception cleanup around RemoveAll.
template <>
__declspec(nothrow) void NiTMapBase<NiTPointerAllocator<unsigned int>, NiNode*, unsigned int>::RemoveAll();

template <class TAlloc, class TKEY, class TVAL>
inline NiTMapBase<TAlloc, TKEY, TVAL>::~NiTMapBase()
{
    RemoveAll();
    _NiFreeAlias(m_ppkHashTable);
}

// @fnv 0x00a54370 (scalar deleting destructor)
template <class TKEY, class TVAL>
inline NiTPointerMap<TKEY, TVAL>::~NiTPointerMap()
{
    RemoveAll();
}

template class NiTPointerMap<NiNode*, unsigned int>;

// Grows the set's storage when full, then stores the given value at the end and increments the count.
// @fnv 0x00a543b0
void NiStreamLinkIDSet_nibonelodcontroller::Add(Item* item)
{
    unsigned int* value = reinterpret_cast<unsigned int*>(item);
    NiStreamLinkIDSet_nibonelodcontroller* set = this;
    if (set->m_pRayCursor == set->m_uiItemCount)
    {
        unsigned int size = set->m_uiItemCount;
        if (size > 0)
            size *= 2;
        else
            size = 1;
        set->Realloc(size);
    }
    unsigned int* puiData = reinterpret_cast<unsigned int*>(set->m_kPointA);
    puiData[set->m_pRayCursor] = *value;
    set->m_pRayCursor++;
}

namespace fnv_00a54410 {
extern int DAT_0109a2ac;
extern MemoryManager g_memoryManager;
struct FUN_00a54410_shell
{
    void* m_kPointA;
    void* m_ptr;
    void* FreeAndMaybeDeallocate(unsigned int);
};
// @fnv 0x00a54410
void* FUN_00a54410_shell::FreeAndMaybeDeallocate(unsigned int flags)
{
    void* tmp = m_ptr;
    m_kPointA = (void*)&DAT_0109a2ac;
    _NiFreeAlias(tmp);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00a54410

// @fnv 0x00a552c0
// src: XBOX_PDB 0x00a552c0
NiBoneLODController* NiBoneLODController::CreateClone_00a552c0(CloningProcess& kCloning)
{
    NiBoneLODController* pkObject = static_cast<NiBoneLODController*>(BSFadeNode::operator new(0x68));
    if (pkObject)
        pkObject = pkObject->FUN_00a550b0();
    else
        pkObject = 0;
    FUN_00a6cfe0(pkObject, &kCloning);
    pkObject->m_iLOD = m_iLOD;
    pkObject->m_uiNumLODs = m_uiNumLODs;
    return pkObject;
}

extern int DAT_0109a2ac;
extern int DAT_0109a2d4;

void _delete(void*, unsigned int);

// @fnv 0x00a553f0
void* NiBoneLODController::FUN_00a553f0(unsigned int flags)
{
    *(void**)this = (void*)&DAT_0109a2d4;
    ClearEntries();
    _NiFreeAlias(*(void**)((char*)this + 0x5c));
    void* p1 = *(void**)((char*)this + 0x50);
    *(void**)((char*)this + 0x4c) = (void*)&DAT_0109a2ac;
    _NiFreeAlias(p1);
    void* p2 = *(void**)((char*)this + 0x40);
    *(void**)((char*)this + 0x3c) = (void*)&DAT_0109a2a4;
    _NiFreeAlias(p2);
    reinterpret_cast<NiTimeController*>(this)->NiTimeController::~NiTimeController();
    if (flags & 1)
        _delete(this, 0x68);
    return this;
}

// Calls NiObject::LinkObject, saves m_iLOD, sets m_iLOD to -1, then passes the saved value to FUN_00a541f0.
// @fnv 0x00a54340
// src: GAMEBRYO_LIB 0x00a54340
void NiBoneLODController::PostLinkObject_00a54340(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    int iLOD = m_iLOD;
    m_iLOD = -1;
    FUN_00a541f0(iLOD);
}

extern NiRTTI DAT_011f4428;

// Checks whether m_target's RTTI chain contains DAT_011f4428, returning false if m_target or its RTTI is null.
// @fnv 0x00a55130
bool NiBoneLODController::IsTargetOfType() const
{
    NiObject* pkTarget = reinterpret_cast<NiObject*>(m_pkTarget);
    if (!pkTarget)
        return false;
    const NiRTTI* pkRTTI = pkTarget->GetRTTI();
    if (!pkRTTI)
        return false;
    do
    {
        if (pkRTTI == &DAT_011f4428)
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    } while (pkRTTI);
    return false;
}

extern int DAT_011a90c4;

// Clamps the global LOD value to the controller's LOD count and, if it differs from the current LOD, applies it via FUN_00a541f0.
// @fnv 0x00a55160
void NiBoneLODController::UpdateLOD(NiUpdateData& UpdateData)
{
    int iNewLOD = DAT_011a90c4;
    if (iNewLOD == -1)
        return;
    if (iNewLOD == m_iLOD)
        return;
    if (iNewLOD > (int)m_uiNumLODs)
        iNewLOD = m_uiNumLODs - 1;
    if (iNewLOD == m_iLOD)
        return;
    FUN_00a541f0(iNewLOD);
}

// @fnv 0x00a55300
NiBoneLODController* CreateBoneLODController()
{
    NiBoneLODController* p = (NiBoneLODController*)BSFadeNode::operator new(0x68);
    if (p)
        return p->FUN_00a550b0();
    return 0;
}

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}
template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

class GeometrySkinInstancePair
{
  public:
    NiTriBasedGeom* m_pkGeom;
    NiPointer<NiSkinInstance> m_spInstance;
};

// Calls the base RegisterStreamables, then registers the skin instance of every skin info in each LOD skin info set, returning false if the base call fails.
// @fnv 0x00a53d00
// src: XBOX_PDB 0x00a53d00
bool NiBoneLODController::RegisterStreamables_00a53d00(NiStream& kStream)
{
    if (!NiTimeController::RegisterStreamables(kStream))
        return false;

    for (unsigned int ui = 0; ui < m_kSkinInfoSets.GetSize(); ui++)
    {
        SkinInfoSet* pkSkinInfoSet = m_kSkinInfoSets.GetAt(ui);
        if (pkSkinInfoSet)
        {
            for (unsigned int uj = 0; uj < pkSkinInfoSet->GetSize(); uj++)
            {
                GeometrySkinInstancePair* pkSkinInfo = pkSkinInfoSet->GetAt(uj);
                if (pkSkinInfo->m_spInstance)
                    pkSkinInfo->m_spInstance->RegisterStreamables(kStream);
            }
        }
    }

    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

struct LODNode
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
    volatile unsigned int stateFlags;
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
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    unsigned int unknown8c;
    unsigned int unknown90;
    unsigned int unknown94;
    unsigned int unknown98;
    unsigned int unknown9c;
    unsigned int unknowna0;
    unsigned int unknowna4;
    unsigned int unknowna8;
    unsigned int unknownac;
    unsigned int unknownb0;
    unsigned int unknownb4;
    unsigned int unknownb8;
    NiRefObject* volatile activeReference;
};
struct NodeCollection
{
    LODNode** elements;
    unsigned int capacity;
    unsigned int count;
};
struct LinkPair
{
    LODNode* node;
    NiRefObject* reference;
};
struct PairCollection
{
    LinkPair** elements;
    unsigned int capacity;
    unsigned int count;
};

// The shared declaration discards the result; this method-only extension retains
// the original boolean-returning implementation without duplicating its layout.
struct BoneLODLevelMethods : NiBoneLODController
{
    bool SetLOD(int desiredLOD);
};
// Switches the LOD level: toggles stateFlags on group and default nodes, updates link-group references, and stores the new LOD if it differs and is valid.
// @fnv 0x00a541f0
bool BoneLODLevelMethods::SetLOD(int desiredLOD)
{
    unsigned short& groupCount = m_kBoneSetArray.m_usSize;
    NodeCollection**& nodeGroups = reinterpret_cast<NodeCollection**&>(m_kBoneSetArray.m_pBase);
    PairCollection**& linkGroups = reinterpret_cast<PairCollection**&>(m_kSkinInfoSets.m_pBase);
    unsigned int& defaultNodeCount = m_kShapeGroups.m_uiUsed;
    LODNode**& defaultNodes = reinterpret_cast<LODNode**&>(m_kShapeGroups.m_pBase);
    if (m_uiNumLODs > 0 && m_iLOD != desiredLOD &&
        (desiredLOD == -1 || (desiredLOD > -1 && (unsigned int)desiredLOD < m_uiNumLODs)))
    {

        bool enableFollowing = false;
        for (unsigned int groupIndex = 0; groupIndex < groupCount; ++groupIndex)
        {
            NodeCollection* group = nodeGroups[groupIndex];
            if (group)
            {
                if (groupIndex == (unsigned int)desiredLOD)
                    enableFollowing = true;
                for (unsigned int i = 0; i < group->count; ++i)
                {
                    LODNode* node = group->elements[i];
                    if (enableFollowing)
                        node->stateFlags |= 2;
                    else
                        node->stateFlags &= ~2u;
                }
            }
        }

        for (unsigned int i = 0; i < defaultNodeCount; ++i)
        {
            LODNode* node = defaultNodes[i];
            node->stateFlags = (node->stateFlags & ~2u) | 1u;
        }

        if (desiredLOD != -1)
        {
            PairCollection* group = linkGroups[desiredLOD];
            if (group)
            {
                for (unsigned int i = 0; i < group->count; ++i)
                {
                    LODNode* node = group->elements[i]->node;
                    node->stateFlags = (node->stateFlags & ~1u) | 2u;
                    NiRefObject* newRef = group->elements[i]->reference;
                    NiRefObject* oldRef = node->activeReference;
                    if (oldRef != newRef)
                    {
                        if (oldRef && InterlockedDecrement(reinterpret_cast<volatile long*>(&oldRef->m_uiRefCount)) == 0)
                            oldRef->DeleteThis();
                        node->activeReference = newRef;
                        if (newRef)
                            InterlockedIncrement(reinterpret_cast<volatile long*>(&newRef->m_uiRefCount));
                    }
                }
            }
        }

        m_iLOD = desiredLOD;
        return true;
    }
    return false;
}

struct MemoryAllocator
{
    void MemoryManager_Deallocate(void* object);
};
extern MemoryAllocator g_011f6238;
extern "C" void __cdecl _NiFree_00aa10f0(void* object);
extern "C" long __declspec(dllimport) __stdcall InterlockedDecrement(volatile long* addend);

struct FirstEntry
{
    void* allocation;
};

struct NestedEntry
{
    void* object;
    NiRefObject* reference;
};
struct EntryGroup
{
    NestedEntry** objects;
    unsigned int reserved;
    unsigned int count;
};

// Frees every small and large entry, nulls the entry arrays, resets their counts and capacities, and clears current.
// @fnv 0x00a55190
void NiBoneLODController::ClearEntries()
{
    for (unsigned int i = 0; i < m_kBoneSetArray.m_usSize; ++i)
    {
        FirstEntry* entry = reinterpret_cast<FirstEntry**>(m_kBoneSetArray.m_pBase)[i];
        if (entry)
        {
            _NiFree_00aa10f0(entry->allocation);
            g_011f6238.MemoryManager_Deallocate(entry);
        }
    }
    for (unsigned short i = 0; i < m_kBoneSetArray.m_usSize; ++i)
        reinterpret_cast<FirstEntry**>(m_kBoneSetArray.m_pBase)[i] = 0;
    m_kBoneSetArray.m_usSize = 0;
    m_kBoneSetArray.m_usESize = 0;

    for (unsigned int i = 0; i < m_kSkinInfoSets.m_usSize; ++i)
    {
        EntryGroup* group = reinterpret_cast<EntryGroup**>(m_kSkinInfoSets.m_pBase)[i];
        if (group)
        {
            for (unsigned int j = 0; j < group->count; ++j)
            {
                NestedEntry* object = group->objects[j];
                if (object)
                {
                    NiRefObject* reference = object->reference;
                    if (reference && InterlockedDecrement(reinterpret_cast<volatile long*>(&reference->m_uiRefCount)) == 0)
                        reference->DeleteThis();
                    g_011f6238.MemoryManager_Deallocate(object);
                }
            }
            _NiFree_00aa10f0(group->objects);
            g_011f6238.MemoryManager_Deallocate(group);
        }
    }
    for (unsigned short i = 0; i < m_kSkinInfoSets.m_usSize; ++i)
        reinterpret_cast<EntryGroup**>(m_kSkinInfoSets.m_pBase)[i] = 0;
    m_kSkinInfoSets.m_usSize = 0;
    m_kSkinInfoSets.m_usESize = 0;
    *(volatile unsigned int*)&m_kShapeGroups.m_uiUsed = 0;
}

template <class T, class TAlloc> inline unsigned int NiTArray<T,TAlloc>::SetAtGrow(unsigned int i, const T& e) { if (i >= m_usMaxSize) SetSize(i + m_usGrowBy); SetAt(i,e); return i; }
template <class T, class TAlloc> inline unsigned int NiTArray<T,TAlloc>::Add(const T& e) { return SetAtGrow(m_usSize,e); }
typedef NiTArray<char*, NiTMallocInterface<char*> > BA55320StringArray;

extern const char* g_pcA55320ClassName;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
char* __cdecl A55320GetViewerStringInt(const char* pcPrefix, int iValue);
char* __cdecl A55320GetViewerStringUInt(const char* pcPrefix, unsigned int uiValue);

// Appends the class name and formatted m_iLOD and m_uiNumLODs strings to pkStrings.
// @fnv 0x00a55320
void NiBoneLODController::AppendViewerStrings(NiViewerStringsArray* strings)
{
    BA55320StringArray* pkStrings = reinterpret_cast<BA55320StringArray*>(strings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(g_pcA55320ClassName));
    pkStrings->Add(A55320GetViewerStringInt("m_iLOD", m_iLOD));
    pkStrings->Add(A55320GetViewerStringUInt("m_uiNumLODs", m_uiNumLODs));
}

template <class T> class EqPointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
struct EqSkinInfo
{
    NiObject* m_pkGeom;
    EqPointer<NiObject> m_spInstance;
};

// local form of NiTPrimitiveSet: 0x00a53ea0 needs the local accessor/inheritance split (shared trial is 430 bytes, exe 438).
template <class T> class EqPrimitiveSet
{
  public:
    unsigned int GetSize() const
    {
        return m_uiUsed;
    }
    T& GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }

    T* m_pBase;
    unsigned int m_uiAlloced;
    unsigned int m_uiUsed;
};
typedef EqPrimitiveSet<NiObject*> EqNodeSet;
typedef EqPrimitiveSet<EqSkinInfo*> EqSkinInfoSet;

// The shared controller header also omits its IsEqual override.
class NiTimeControllerEqualityMethods : public NiTimeController
{
  public:
    bool BaseIsEqual(NiObject* pkObject);
};

// Compares LOD, LOD counts, node/skin/shape sets and their elements against pkObject after BaseIsEqual, returning false on any mismatch.
// @fnv 0x00a53ea0
// src: XBOX_PDB 0x00a53ea0
bool NiBoneLODController::IsEqual_00a53ea0(NiObject* pkObject)
{
    if (!reinterpret_cast<NiTimeControllerEqualityMethods*>(this)->BaseIsEqual(pkObject))
        return false;

    NiBoneLODController* pkDest = (NiBoneLODController*)pkObject;

    if (m_iLOD != pkDest->m_iLOD || m_uiNumLODs != pkDest->m_uiNumLODs ||
        m_kBoneSetArray.GetSize() != pkDest->m_kBoneSetArray.GetSize() ||
        m_kSkinInfoSets.GetSize() != pkDest->m_kSkinInfoSets.GetSize() ||
        m_kShapeGroups.GetSize() != pkDest->m_kShapeGroups.GetSize())
    {
        return false;
    }

    unsigned int ui;
    for (ui = 0; ui < m_kBoneSetArray.GetSize(); ui++)
    {
        EqNodeSet* pkSet = reinterpret_cast<EqNodeSet*>(m_kBoneSetArray.GetAt(ui));
        EqNodeSet* pkDestSet = reinterpret_cast<EqNodeSet*>(pkDest->m_kBoneSetArray.GetAt(ui));
        if ((pkSet && !pkDestSet) || (!pkSet && pkDestSet))
            return false;
        if (pkSet && pkDestSet)
        {
            if (pkSet->GetSize() != pkDestSet->GetSize())
                return false;
            for (unsigned int uj = 0; uj < pkSet->GetSize(); uj++)
            {
                if (!static_cast<const NiObject*>(pkSet->GetAt(uj))->IsEqual(pkDestSet->GetAt(uj)))
                    return false;
            }
        }
    }

    for (ui = 0; ui < m_kSkinInfoSets.GetSize(); ui++)
    {
        EqSkinInfoSet* pkSet = reinterpret_cast<EqSkinInfoSet*>(m_kSkinInfoSets.GetAt(ui));
        EqSkinInfoSet* pkDestSet = reinterpret_cast<EqSkinInfoSet*>(pkDest->m_kSkinInfoSets.GetAt(ui));
        if ((pkSet && !pkDestSet) || (!pkSet && pkDestSet))
            return false;
        if (pkSet && pkDestSet)
        {
            if (pkSet->GetSize() != pkDestSet->GetSize())
                return false;
            for (unsigned int uj = 0; uj < pkSet->GetSize(); uj++)
            {
                EqSkinInfo* pkInfo = pkSet->GetAt(uj);
                EqSkinInfo* pkDestInfo = pkDestSet->GetAt(uj);
                if (!static_cast<const NiObject*>(pkInfo->m_pkGeom)->IsEqual(pkDestInfo->m_pkGeom))
                    return false;
                if (!static_cast<const NiObject*>(pkInfo->m_spInstance.m_pObject)->IsEqual(pkDestInfo->m_spInstance))
                    return false;
            }
        }
    }

    for (ui = 0; ui < m_kShapeGroups.GetSize(); ui++)
    {
        if (!static_cast<const NiObject*>(reinterpret_cast<EqPrimitiveSet<NiObject*>&>(m_kShapeGroups).GetAt(ui))->IsEqual(reinterpret_cast<EqPrimitiveSet<NiObject*>&>(pkDest->m_kShapeGroups).GetAt(ui)))
            return false;
    }

    return true;
}

void* __cdecl _NiMalloc_00aa1070(unsigned int);
void __cdecl _NiFree_00aa10f0(void*);

inline unsigned int NiBinaryStream::Read(void* data, unsigned int size)
{
    unsigned int amount = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(this, data, size, &size, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += amount;
    return amount;
}
static inline void ReadLOD32(NiStream& stream, void* data)
{
    NiBinaryStream* file = *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x24c);
    file->Read(data, 4);
}

struct LODPool
{
    void* Game_DoHeapAlloc(unsigned int);
};
extern LODPool DAT_011f6238;
template <class T> struct LinkGroup
{
    T* data;
    unsigned int capacity;
    unsigned int count;
    static void* operator new(unsigned int size)
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
    LinkGroup() : data(0), capacity(0), count(0)
    {}
    void Reserve(unsigned int size)
    {
        if (size != capacity)
        {
            T* replacement;
            if (size > 0)
            {
                replacement = (T*)_NiMalloc_00aa1070(size * sizeof(T));
                for (unsigned int i = 0; i < count; i++)
                    replacement[i] = data[i];
            }
            else
                replacement = 0;
            _NiFree_00aa10f0(data);
            data = replacement;
            capacity = size;
        }
    }
    void Add(T const& element)
    {
        if (count == capacity)
            Reserve(capacity > 0 ? capacity * 2 : 1);
        data[count] = element;
        count++;
    }
};
struct LinkSkinInfo
{
    void* object;
    void* skin;
    static void* operator new(unsigned int size)
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
    LinkSkinInfo() : skin(0)
    {}
};
template <class T> struct LinkGroupArray
{
    void* vtable;
    LinkGroup<T>** data;
    unsigned short capacity, size, used, growBy;
    void FUN_00a90180(unsigned int);
    __forceinline void SetAt(unsigned int index, LinkGroup<T>* const& group)
    {
        if (index >= capacity)
            FUN_00a90180(index + growBy);
        if (index >= size)
        {
            size = (unsigned short)(index + 1);
            if (group)
                used++;
        }
        else
        {
            if (group)
            {
                if (!data[index])
                    used++;
            }
            else if (data[index])
                used--;
        }
        data[index] = group;
    }
};

// Reads the current LOD, LOD count, node groups, skin groups and extra links from the stream, building the group arrays.
// @fnv 0x00a54c40
void NiBoneLODController::ReadFromStream(NiStream* stream)
{
    unsigned int i;
    FUN_00a6d5e0(stream);
    ReadLOD32(*stream, &m_iLOD);
    ReadLOD32(*stream, &m_uiNumLODs);
    unsigned int nodeCount = 0;
    ReadLOD32(*stream, &nodeCount);
    for (i = 0; i < nodeCount; i++)
    {
        LinkGroup<void*>* group = new LinkGroup<void*>;
        reinterpret_cast<LinkGroupArray<void*>&>(m_kBoneSetArray).SetAt(i, group);
        unsigned int childCount = 0;
        ReadLOD32(*stream, &childCount);
        for (unsigned int j = 0; j < childCount; j++)
        {
            void* object = this;
            group->Add(object);
            stream->ReadLinkIDStub();
        }
    }
    unsigned int skinCount = 0;
    ReadLOD32(*stream, &skinCount);
    for (i = 0; i < skinCount; i++)
    {
        LinkGroup<LinkSkinInfo*>* group = new LinkGroup<LinkSkinInfo*>;
        reinterpret_cast<LinkGroupArray<LinkSkinInfo*>&>(m_kSkinInfoSets).SetAt(i, group);
        unsigned int childCount = 0;
        ReadLOD32(*stream, &childCount);
        for (unsigned int j = 0; j < childCount; j++)
        {
            LinkSkinInfo* info = new LinkSkinInfo;
            group->Add(info);
            stream->ReadLinkIDStub();
            stream->ReadLinkIDStub();
        }
    }
    unsigned int extraCount = 0;
    ReadLOD32(*stream, &extraCount);
    for (i = 0; i < extraCount; i++)
    {
        void* object = this;
        reinterpret_cast<LinkGroup<void*>&>(m_kShapeGroups).Add(object);
        stream->ReadLinkIDStub();
    }
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
    unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesWritten = (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 0xc))(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += uiBytesWritten;
    return uiBytesWritten;
}

template <class T> inline void SerializeValue(NiBinaryStream& binstream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    binstream.BinaryWrite(&value, sizeof(T), &uiSize, 1);
}

// The shared controller header does not declare its SaveBinary override.
// This method-only extension supplies that call without copying the base layout.
struct NiTimeControllerStreamMethods : NiTimeController
{
    void SaveBinary(NiStream& stream);
};

template <class T> inline void SaveStream(NiStream& kStream, const T& value)
{
    SerializeValue(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x250), value);
}
// Serializes the LOD level, node groups, skin groups, and default nodes of a bone LOD entry to the stream.
// @fnv 0x00a549d0
// src: XBOX_PDB 0x00a549d0
void NiBoneLODController::SaveBinary_00a549d0(NiStream& stream)
{
    reinterpret_cast<NiTimeControllerStreamMethods*>(this)->NiTimeControllerStreamMethods::SaveBinary(stream);
    NiTPrimitiveArray<BoneSet*>& nodes = m_kBoneSetArray;
    NiTPrimitiveArray<SkinInfoSet*>& skins = m_kSkinInfoSets;
    NodeCollection& defaultNodes = reinterpret_cast<NodeCollection&>(m_kShapeGroups);
    SaveStream(stream, m_iLOD);
    SaveStream(stream, m_uiNumLODs);
    {
        unsigned int uiNumNodeGroups = nodes.GetSize();
        SaveStream(stream, uiNumNodeGroups);
    }
    unsigned int i;
    for (i = 0; i < nodes.GetSize(); i++)
    {
        NodeCollection* pkSet = reinterpret_cast<NodeCollection*>(nodes.GetAt(i));
        if (pkSet)
        {
            unsigned int uiElementCount = pkSet->count;
            SaveStream(stream, uiElementCount);
            for (unsigned int j = 0; j < pkSet->count; j++)
                stream.SaveLinkID(reinterpret_cast<const NiObject*>(pkSet->elements[j]));
        }
        else
        {
            unsigned int uiElementCount = 0;
            SaveStream(stream, uiElementCount);
        }
    }
    {
        unsigned int uiNumSkinGroups = skins.GetSize();
        SaveStream(stream, uiNumSkinGroups);
    }
    for (i = 0; i < skins.GetSize(); i++)
    {
        PairCollection* pkSet = reinterpret_cast<PairCollection*>(skins.GetAt(i));
        if (pkSet)
        {
            unsigned int uiElementCount = pkSet->count;
            SaveStream(stream, uiElementCount);
            for (unsigned int j = 0; j < pkSet->count; j++)
            {
                LinkPair* pkPair = pkSet->elements[j];
                stream.SaveLinkID(reinterpret_cast<const NiObject*>(pkPair->node));
                stream.SaveLinkID(reinterpret_cast<const NiObject*>(pkPair->reference));
            }
        }
        else
        {
            unsigned int uiElementCount = 0;
            SaveStream(stream, uiElementCount);
        }
    }
    {
        unsigned int uiNumDefaultNodes = defaultNodes.count;
        SaveStream(stream, uiNumDefaultNodes);
    }
    for (i = 0; i < defaultNodes.count; i++)
        stream.SaveLinkID(reinterpret_cast<const NiObject*>(defaultNodes.elements[i]));
}

template <class T, class TAlloc>
__declspec(nothrow) inline NiTArray<T, TAlloc>::NiTArray(unsigned int size, unsigned int grow)
{
    m_usMaxSize = (unsigned short)size;
    m_usGrowBy = (unsigned short)grow;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = (T*)_NiMalloc_00aa1070(m_usMaxSize * sizeof(T));
    else
        m_pBase = 0;
}

template <class T>
__declspec(nothrow) inline NiTPrimitiveArray<T>::NiTPrimitiveArray(unsigned int size, unsigned int grow)
    : NiTArray<T, NiTMallocInterface<T> >(size, grow)
{}

template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetSize() const { return m_usSize; }
template <class T, class TAlloc> inline T& NiTArray<T, TAlloc>::GetAt(unsigned int index) { return m_pBase[index]; }
template <class T, class TAlloc> inline unsigned int NiTSet<T, TAlloc>::GetSize() const { return m_uiUsed; }
template <class T, class TAlloc> inline T& NiTSet<T, TAlloc>::GetAt(unsigned int index) { return m_pBase[index]; }
template <class T, class TAlloc> __declspec(nothrow) inline NiTSet<T, TAlloc>::NiTSet(unsigned int size)
    : m_pBase(0), m_uiAlloced(0), m_uiUsed(0) {}
template <class T> __declspec(nothrow) inline NiTPrimitiveSet<T>::NiTPrimitiveSet(unsigned int size)
    : NiTSet<T, NiTMallocInterface<T> >(size) {}

extern int DAT_0109a2c8;

template <>
__declspec(nothrow) inline NiTPrimitiveArray<NiBoneLODController::SkinInfoSet*>::NiTPrimitiveArray(unsigned int size, unsigned int grow)
{
    m_usMaxSize = (unsigned short)size;
    m_usGrowBy = (unsigned short)grow;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = (NiBoneLODController::SkinInfoSet**)_NiMalloc_00aa1070(m_usMaxSize * sizeof(NiBoneLODController::SkinInfoSet*));
    else
        m_pBase = 0;
    *reinterpret_cast<void**>(this) = &DAT_0109a2c8;
}

// @fnv 0x00a550b0
NiBoneLODController::NiBoneLODController() : m_iLOD(-1), m_uiNumLODs(0)
{
    m_kShapeGroups.m_pBase = 0;
    m_kShapeGroups.m_uiAlloced = 0;
    m_kShapeGroups.m_uiUsed = 0;
}

typedef NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, NiObject*> CloneMap;
typedef NiTMapItem<NiObject*, NiObject*> CloneMapItem;

struct A54440Remap
{
    CloneMap* map;
};
struct A54440Heap : MemoryAllocator
{
    void* Game_DoHeapAlloc(unsigned int bytes);
};
void* __cdecl _NiMalloc_00aa1070(unsigned int);
struct A54440PointerGroup
{
    static void* operator new(unsigned int bytes)
    {
        return ((A54440Heap*)&g_011f6238)->Game_DoHeapAlloc(bytes);
    }
    A54440PointerGroup() : elements(0), capacity(0), count(0)
    {}
    void** elements;
    unsigned int capacity;
    unsigned int count;
    void NiTSet_NiScreenGeometryData_ScreenElement_NiTMallocInterface_NiScreenGeometryData_ScreenElement_Add(unsigned int nextCapacity);
    void Append(void* item)
    {
        if (count == capacity)
            NiTSet_NiScreenGeometryData_ScreenElement_NiTMallocInterface_NiScreenGeometryData_ScreenElement_Add(capacity > 0 ? capacity * 2 : 1);
        elements[count++] = item;
    }
};
struct A54440Link
{
    void* data;
    NiRefObject* ref;
};
struct A54440GrowGroup
{
    void** elements;
    unsigned int capacity;
    unsigned int count;
    __forceinline void Append(void* item)
    {
        if (count == capacity)
        {
            unsigned int newCapacity = 2 * (capacity);
            if (!(capacity > 0))
                newCapacity = 1;
            if (newCapacity != capacity)
            {
                void** newData;
                if (newCapacity > 0)
                {
                    newData = (void**)_NiMalloc_00aa1070(newCapacity * 4);
                    for (unsigned int j = 0; j < count; j++)
                        newData[j] = elements[j];
                }
                else
                    newData = 0;
                _NiFree_00aa10f0(elements);
                elements = newData;
                capacity = newCapacity;
            }
        }
        elements[(count)++] = item;
    }
};
struct A54440LinkGroup
{
    static void* operator new(unsigned int bytes)
    {
        return ((A54440Heap*)&g_011f6238)->Game_DoHeapAlloc(bytes);
    }
    A54440LinkGroup() : entries(0), capacity(0), count(0)
    {}
    __forceinline void Append(A54440Link* item)
    {
        if (count == capacity)
        {
            unsigned int newCapacity = 2 * (capacity);
            if (!(capacity > 0))
                newCapacity = 1;
            if (newCapacity != capacity)
            {
                A54440Link** newData;
                if (newCapacity > 0)
                {
                    newData = (A54440Link**)_NiMalloc_00aa1070(newCapacity * 4);
                    for (unsigned int j = 0; j < count; j++)
                        newData[j] = entries[j];
                }
                else
                    newData = 0;
                _NiFree_00aa10f0(entries);
                entries = newData;
                capacity = newCapacity;
            }
        }
        entries[(count)++] = item;
    }
    A54440Link** entries;
    unsigned int capacity;
    unsigned int count;
};
struct A54440Array
{
    void* vtable;
    void** elements;
    unsigned short capacity;
    unsigned short count;
    unsigned short elementSize;
    unsigned short growBy;
    void FUN_00a90180(unsigned int);
    void FUN_00ba3aa0(unsigned int, void* const*);
    void SetCloneGroup(unsigned int index, void* const& ptr)
    {
        if (index >= capacity)
            FUN_00a90180(index + growBy);
        FUN_00ba3aa0(index, &ptr);
    }
    __forceinline void SetAtGrow(unsigned int index, void* value)
    {
        if (index >= capacity)
            FUN_00a90180(index + growBy);
        if (index >= count)
        {
            count = (unsigned short)(index + 1);
            if (value)
                ++elementSize;
        }
        else
        {
            if (value)
            {
                if (!elements[index])
                    ++elementSize;
            }
            else if (elements[index])
                --elementSize;
        }
        elements[index] = value;
    }
};

static CloneMapItem* A54440Find(const CloneMap* hash, void* key)
{
    for (CloneMapItem* item = hash->m_ppkHashTable[hash->KeyToHashIndex(static_cast<NiObject*>(key))]; item; item = item->m_pkNext)
    {
        if (hash->IsKeysEqual(static_cast<NiObject*>(key), item->m_key))
            return item;
    }
    return 0;
}
static void* A54440Map(CloneMap* hash, void* key)
{
    CloneMapItem* item = A54440Find(hash, key);
    return item ? item->m_val : key;
}
struct A54440SourceLink
{
    static void* operator new(unsigned int bytes)
    {
        return ((A54440Heap*)&g_011f6238)->Game_DoHeapAlloc(bytes);
    }
    A54440SourceLink() : ref(0)
    {}
    void* source;
    NiRefObject* ref;
};
typedef NiRefObject*(__thiscall* A54440CopyRef)(NiRefObject*, A54440Remap*);
typedef void(__thiscall* A54440FinishRef)(NiRefObject*, A54440Remap*);
static NiRefObject* A54440Copy(NiRefObject* ref, A54440Remap* ctx)
{
    return reinterpret_cast<NiObject*>(ref)->MakeClone(*reinterpret_cast<CloningProcess*>(ctx));
}
static void A54440Finish(NiRefObject* ref, A54440Remap* ctx)
{
    reinterpret_cast<NiObject*>(ref)->ProcessClone(*reinterpret_cast<CloningProcess*>(ctx));
}

template <>
__declspec(noinline) bool NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, NiObject*>::GetAt(NiObject* source, NiObject*& out) const
{
    CloneMapItem* item = A54440Find(this, source);
    if (item)
    {
        out = item->m_val;
        return true;
    }
    return false;
}

static __forceinline bool A54440Lookup(CloneMap* hash, void* key, void*& replacement)
{
    CloneMapItem* entry = A54440Find(hash, key);
    if (entry)
    {
        replacement = entry->m_val;
        return true;
    }
    return false;
}

__declspec(noinline) void A54440Array::FUN_00ba3aa0(unsigned int index, void* const* pvalue)
{
    void* value = *pvalue;
    if (index >= count)
    {
        count = (unsigned short)(index + 1);
        if (value)
            ++elementSize;
    }
    else
    {
        if (value)
        {
            if (!elements[index])
                ++elementSize;
        }
        else if (elements[index])
            --elementSize;
    }
    elements[index] = value;
}

struct A54440CloneWork
{
    NiBoneLODController* clone;
    union
    {
        unsigned int boneIndex;
        A54440SourceLink* skinSource;
    };
    union
    {
        void* boneValue;
        unsigned int skinIndex;
    };
    union
    {
        A54440Array* boneArray;
        A54440LinkGroup* skinSet;
    };
};

// Copies this manager's groups, links, and defaults into its mapped clone, applying mapped references where available.
// @fnv 0x00a54440
void NiBoneLODController::CloneFrom(CloningProcess* process)
{
    unsigned int i;
    FUN_00a6d0c0(process);
    A54440Remap* remap = reinterpret_cast<A54440Remap*>(process);
    A54440Array& groups = reinterpret_cast<A54440Array&>(m_kBoneSetArray);
    A54440Array& links = reinterpret_cast<A54440Array&>(m_kSkinInfoSets);
    A54440GrowGroup& defaults = reinterpret_cast<A54440GrowGroup&>(m_kShapeGroups);
    A54440CloneWork work;
    remap->map->GetAt(this, reinterpret_cast<NiObject*&>(work.clone));
    i = 0;
    if (i < groups.count)
    {
        work.boneArray = reinterpret_cast<A54440Array*>(&work.clone->m_kBoneSetArray);
        do
        {
            A54440PointerGroup* boneSource = (A54440PointerGroup*)groups.elements[i];
            if (boneSource)
            {
                A54440PointerGroup* dst = new A54440PointerGroup;
                work.boneValue = dst;
                work.boneArray->SetCloneGroup(i, work.boneValue);
                for (work.boneIndex = 0; work.boneIndex < boneSource->count; work.boneIndex++)
                {
                    void* item = boneSource->elements[work.boneIndex];
                    CloneMapItem* entry = A54440Find(remap->map, item);
                    if (entry)
                        dst->Append(entry->m_val);
                    else
                        dst->Append(item);
                }
            }
            else
            {
                work.boneValue = 0;
                work.boneArray->SetCloneGroup(i, work.boneValue);
            }
        } while (++i < groups.count);
    }
    for (i = 0; i < links.count; i++)
    {
        work.skinSet = (A54440LinkGroup*)links.elements[i];
        if (work.skinSet)
        {
            A54440LinkGroup* dst = new A54440LinkGroup;
            reinterpret_cast<A54440Array&>(work.clone->m_kSkinInfoSets).SetAtGrow(i, dst);
            for (work.skinIndex = 0; work.skinIndex < work.skinSet->count; work.skinIndex++)
            {
                work.skinSource = (A54440SourceLink*)work.skinSet->entries[work.skinIndex];
                A54440SourceLink* skinCopy = new A54440SourceLink;
                dst->Append((A54440Link*)skinCopy);
                void* mapped;
                if (A54440Lookup(remap->map, work.skinSource->source, mapped))
                    skinCopy->source = mapped;
                else
                    skinCopy->source = work.skinSource->source;
                NiRefObject* newRef = A54440Copy(work.skinSource->ref, remap);
                if (skinCopy->ref != newRef)
                {
                    NiRefObject* oldRef = skinCopy->ref;
                    if (oldRef)
                    {
                        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&oldRef->m_uiRefCount)) == 0)
                            oldRef->DeleteThis();
                    }
                    skinCopy->ref = newRef;
                    if (newRef)
                        InterlockedIncrement(reinterpret_cast<volatile long*>(&newRef->m_uiRefCount));
                }
                A54440Finish(work.skinSource->ref, remap);
            }
        }
        else
        {
            reinterpret_cast<A54440Array&>(work.clone->m_kSkinInfoSets).SetAtGrow(i, 0);
        }
    }

    for (i = 0; i < defaults.count; i++)
    {
        void* node = defaults.elements[i];
        CloneMapItem* entry = A54440Find(remap->map, node);
        if (entry)
            reinterpret_cast<A54440GrowGroup&>(work.clone->m_kShapeGroups).Append(entry->m_val);
        else
            reinterpret_cast<A54440GrowGroup&>(work.clone->m_kShapeGroups).Append(node);
    }
    int lod = work.clone->m_iLOD;
    work.clone->m_iLOD = -1;
    work.clone->FUN_00a541f0(lod);
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

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* p)
{
    if (m_pObject != p)
    {
        if (m_pObject)
            m_pObject->NiRefObject::DecRefCount();
        m_pObject = p;
        if (m_pObject)
            m_pObject->NiRefObject::IncRefCount();
    }
    return *this;
}

// Calls the base LinkObject, then loads objects into bone sets, skin pair fields, and shape groups.
// @fnv 0x00a53d70
// src: GAMEBRYO_LIB 0x00a53d70
void NiBoneLODController::LinkObject_00a53d70(NiStream& kStream)
{
    NiTimeController::LinkObject(kStream);

    unsigned int i;
    for (i = 0; i < m_kBoneSetArray.GetSize(); i++)
    {
        NiTPrimitiveSet<NiNode*>* pkBones = m_kBoneSetArray.GetAt(i);
        if (pkBones)
        {
            for (unsigned int j = 0; j < pkBones->GetSize(); j++)
                {
                NiNode* node = (NiNode*)kStream.GetLoadedObject();
                if (j < pkBones->m_uiUsed)
                    pkBones->m_pBase[j] = node;
            }
        }
    }

    for (i = 0; i < m_kSkinInfoSets.GetSize(); i++)
    {
        NiTPrimitiveSet<GeometrySkinInstancePair*>* pkSkins = m_kSkinInfoSets.GetAt(i);
        if (pkSkins)
        {
            for (unsigned int j = 0; j < pkSkins->GetSize(); j++)
            {
                GeometrySkinInstancePair* pkInfo = pkSkins->GetAt(j);
                pkInfo->m_pkGeom = (NiTriBasedGeom*)kStream.GetLoadedObject();
                pkInfo->m_spInstance = (NiSkinInstance*)kStream.GetLoadedObject();
            }
        }
    }

    for (i = 0; i < m_kShapeGroups.GetSize(); i++)
        {
        NiTriBasedGeom* shape = (NiTriBasedGeom*)kStream.GetLoadedObject();
        if (i < m_kShapeGroups.m_uiUsed)
            m_kShapeGroups.m_pBase[i] = shape;
    }
}

