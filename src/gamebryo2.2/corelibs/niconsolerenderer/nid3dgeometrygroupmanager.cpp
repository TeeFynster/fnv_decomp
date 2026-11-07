// gamebryo2.2/corelibs/niconsolerenderer/nid3dgeometrygroupmanager.cpp: NiD3DGeometryGroupManager (12 functions)

#include "../../../../include/NiD3DGeometryGroupManager.h"
#include "../../../../include/NiGeometryGroup.h"
#include "../../../../include/NiGeometryGroupManager.h"
// NiStreamLinkIDSet_nid3dgeometrygroupmanager: local type (was include/NiStreamLinkIDSet.h, which had no evidence of one real class); its methods are 0x00a311e0 NiTSet<NiScreenGeometryData::ScreenElement *,NiTMallocInterface<NiScreenGeometryData::ScreenElement *> >::Add, 0x00a543b0 NiTSet::Ptr::Add
class Item;
class NiGeomMorpherUpdateTask;
class D3DRenderStateGroup;

class NiStreamLinkIDSet_nid3dgeometrygroupmanager
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
#include "../../../../include/NiUnsharedGeometryGroup.h"
#include "../../../../include/NiGeometryBufferData.h"

class Direct3DDeviceInterface
{
  public:
    virtual void slot0() = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

extern void* DAT_010ef718[];

// Allocates and initialises a NiD3DGeometryGroupManager, stores the device and buffers, and AddRefs the device.
// @fnv 0x00e88eb0
NiD3DGeometryGroupManager* NiD3DGeometryGroupManager::Create(Direct3DDeviceInterface* device,
                                                             VertexDeclarationLayout* buffers)
{
    NiD3DGeometryGroupManager* p = (NiD3DGeometryGroupManager*)NiMemObject::operator new(28);
    if (p)
    {
        p->Initialize();
        *(void***)p = DAT_010ef718;
        p->m_04 = 0;
        p->m_08 = 0;
        p->m_0c = 0;
        p->m_10 = 0;
        p->m_14 = 0;
        p->m_18 = false;
    }
    else
        p = 0;
    p->m_10 = device;
    device->AddRef();
    p->m_14 = buffers;
    return p;
}

struct NiSkinInstance;
bool __fastcall ProcessCollector(void*, int, NiGeometryGroup*, NiGeometryData*, NiSkinInstance*, bool, unsigned int,
                                 unsigned int);

// Forwards the geometry group, data and skin instance to ProcessCollector along with the bool at pThis+0x18 and two zero arguments.
// @fnv 0x00e88fa0
// src: XBOX_PDB 0x00e88fa0
bool __fastcall NiD3DGeometryGroupManager_AddObjectToGroup(NiD3DGeometryGroupManager* pThis, int, NiGeometryGroup* pkGroup, NiGeometryData* pkData,
                             NiSkinInstance* pkSkinInstance)
{
    typedef bool(__thiscall * Fn)(void*, NiGeometryGroup*, NiGeometryData*, NiSkinInstance*, bool, unsigned int,
                                  unsigned int);
    return ((Fn)&ProcessCollector)(pThis, pkGroup, pkData, pkSkinInstance, pThis->m_18, 0, 0);
}

// @fnv 0x00e88c90
bool __fastcall IsGroupEmpty(NiD3DGeometryGroupManager*, int, NiGeometryGroup* pkGroup)
{
    return pkGroup->m_uiRefCount == 0;
}

struct FUN_00e88ca0_Data
{
    int _pad[7];
    int m1c;
};
// Returns false if pkData->m1c is nonzero; otherwise dispatches to the group and returns true.
// @fnv 0x00e88ca0
bool __fastcall CheckAndDispatch(NiD3DGeometryGroupManager*, int, NiGeometryGroup* pkGroup, FUN_00e88ca0_Data* pkData)
{
    if (pkData->m1c != 0)
        return false;
    pkGroup->vf01(reinterpret_cast<NiScreenTexture*>(pkData));
    return true;
}

// @fnv 0x00e88cc0
bool __fastcall RemoveScreenTexture(NiD3DGeometryGroupManager*, int, NiScreenTexture* pkScreenTexture)
{
    NiGeometryGroup* pkGroup;
    NiGeometryBufferData* pkBuffData;
    pkBuffData = *(NiGeometryBufferData**)((char*)pkScreenTexture + 0x1c);
    if (!pkBuffData)
        return false;
    pkGroup = pkBuffData->m_pkOwnerGroup;
    pkGroup->vf03(reinterpret_cast<NiGeometryData*>(pkScreenTexture));
    if (pkGroup->m_uiRefCount == 0)
        pkGroup->Purge();
    return true;
}

void __fastcall DestroyGeometryGroupManagerBase(NiD3DGeometryGroupManager*, int);
void __cdecl NiVBSet_DeleteBlocks();
void __cdecl _NiFreeAlias(void*);
// @fnv 0x00e88d60
void __fastcall DestroyGeometryGroupManager(NiD3DGeometryGroupManager* manager, int)
{
    unsigned int n = manager->m_0c;
    unsigned int i = 0;
    *(void***)manager = DAT_010ef718;
    for (; i < n; ++i)
    {
        NiGeometryGroup* e = reinterpret_cast<NiGeometryGroup**>(manager->m_04)[i];
        if (e)
            delete e;
    }
    NiVBSet_DeleteBlocks();
    if (manager->m_10)
        manager->m_10->Release();
    _NiFreeAlias(manager->m_04);
    typedef void (__thiscall* DestroyBase)(NiD3DGeometryGroupManager*);
    ((DestroyBase)&DestroyGeometryGroupManagerBase)(manager);
}

void __cdecl _delete(void*, unsigned int);
// Destroys the manager, frees it when flags has bit 1 set, and returns its address.
// @fnv 0x00e88e90
void* __fastcall DestroyIfOwned(NiD3DGeometryGroupManager* manager, int, unsigned int flags)
{
    typedef void (__thiscall* DestroyManager)(NiD3DGeometryGroupManager*);
    ((DestroyManager)&DestroyGeometryGroupManager)(manager);
    if (flags & 1)
        _delete(manager, 0x1c);
    return manager;
}

struct FUN_Elem
{
    unsigned char pad[0x28];
    NiGeometryBufferData* m_28;
};
struct FUN_P
{
    int m_00;
    int m_04;
    unsigned int m_08;
    FUN_Elem* m_0C;
};
// @fnv 0x00e88d00
// src: XBOX_PDB 0x00e88d00
bool __stdcall NiD3DGeometryGroupManager_RemoveSkinPartitionFromGroup(FUN_P* p)
{
    unsigned int cnt = p->m_08;
    FUN_Elem* e = p->m_0C;
    NiGeometryGroup* b = e->m_28->m_pkOwnerGroup;
    bool flag = false;
    if (cnt > 0)
    {
        unsigned int n = cnt;
        do
        {
            NiGeometryBufferData* a = e->m_28;
            if (a)
            {
                a->m_pkOwnerGroup->vf04(e);
                flag = true;
            }
            ++e;
            --n;
        } while (n != 0);
        if (flag && b->m_uiRefCount == 0)
            b->Purge();
    }
    return flag;
}

// @fnv 0x00e88c30
bool __fastcall RemoveElement(NiD3DGeometryGroupManager* manager, int, NiGeometryGroup* pElement)
{
    typedef bool (__thiscall* CheckGroup)(NiD3DGeometryGroupManager*, NiGeometryGroup*);
    if (pElement != 0 && ((CheckGroup)(*(void***)manager)[3])(manager, pElement))
    {
        unsigned int uiIndex = 0;
        unsigned int n = manager->m_0c;
        if (n > 0)
        {
            NiGeometryGroup** cur = reinterpret_cast<NiGeometryGroup**>(manager->m_04);
            do
            {
                if (*cur == pElement)
                {
                    goto found;
                }
                ++cur;
                ++uiIndex;
            } while (uiIndex < n);
        }
        uiIndex = 0xffffffff;
    found:

        unsigned int& cnt = manager->m_0c;
        --cnt;
        NiGeometryGroup** arr = reinterpret_cast<NiGeometryGroup**>(manager->m_04);
        arr[uiIndex] = arr[cnt];
        delete pElement;
        return true;
    }
    return false;
}

struct GeomOwner
{
    unsigned char pad[0x34];
    NiGeometryBufferData* m_34;
};

struct GeomRef
{
    unsigned char pad[0xc];
    void* m_0C;
};

// Removes the referenced geometry buffers, then purges the owner group if it is empty.
// @fnv 0x00e88e40
// src: XBOX_PDB 0x00e88e40
bool __stdcall NiD3DGeometryGroupManager_RemoveObjectFromGroup(GeomOwner* pGeomOwner, GeomRef* pGeomRef)
{
    if (pGeomRef == 0)
    {
        goto owner;
    }
    if (pGeomRef->m_0C == 0)
    {
        goto owner;
    }
    return NiD3DGeometryGroupManager_RemoveSkinPartitionFromGroup(reinterpret_cast<FUN_P*>(pGeomRef->m_0C));
owner:
    if (pGeomOwner->m_34 == 0)
    {
        return false;
    }
    NiGeometryGroup* pSlotB = pGeomOwner->m_34->m_pkOwnerGroup;
    pSlotB->vf05(reinterpret_cast<NiGeometryData*>(pGeomOwner));
    if (pSlotB->m_uiRefCount == 0)
    {
        pSlotB->Purge();
    }
    return true;
}

NiGeometryGroup* CreateStaticGroup();
NiGeometryGroup* CreateDynamicGroup();

inline int NiStreamLinkIDSet_nid3dgeometrygroupmanager::Find(unsigned int value)
{
    unsigned int index = 0;
    unsigned int count = m_pRayCursor;
    if (count > 0)
    {
        unsigned int* current = static_cast<unsigned int*>(m_kPointA);
        do
        {
            if (*current == value)
                return index;
            ++current;
            ++index;
        } while (index < count);
    }
    return -1;
}

static inline void AppendGroup(NiStreamLinkIDSet_nid3dgeometrygroupmanager* groups, NiGeometryGroup* const& group)
{
    if (groups->m_pRayCursor == groups->m_uiItemCount)
        groups->Realloc(groups->m_uiItemCount > 0 ? 2 * groups->m_uiItemCount : 1);
    static_cast<NiGeometryGroup**>(groups->m_kPointA)[groups->m_pRayCursor++] = group;
}

static inline void SetDevice(NiGeometryGroup* group, Direct3DDeviceInterface* device)
{
    group->m_pD3DDevice = device;
    device->AddRef();
}

static __forceinline void AddGroup(NiD3DGeometryGroupManager* manager, NiGeometryGroup* group)
{
    NiStreamLinkIDSet_nid3dgeometrygroupmanager* groups = reinterpret_cast<NiStreamLinkIDSet_nid3dgeometrygroupmanager*>(&manager->m_04);
    if (groups->Find(reinterpret_cast<unsigned int>(group)) >= 0)
        return;
    AppendGroup(groups, group);
    SetDevice(group, manager->m_10);
}

// Creates a geometry group for the given repacking behavior, adds it to the manager's set, and returns it (or null for an unknown behavior).
// @fnv 0x00e88f10
NiGeometryGroup* NiD3DGeometryGroupManager::CreateGroup(NiGeometryGroupManager::RepackingBehavior eBehavior)
{
    NiGeometryGroup* pkGroup = 0;
    switch (eBehavior)
    {
    case STATIC:
        pkGroup = CreateStaticGroup();
        break;
    case UNSHARED:
        pkGroup = NiUnsharedGeometryGroup::Create();
        break;
    case DYNAMIC:
        pkGroup = CreateDynamicGroup();
        break;
    }
    if (pkGroup)
        AddGroup(this, pkGroup);
    return pkGroup;
}

struct HkElem2c
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
};
struct HkInfo
{
    int unk00;
    int unk04;
    unsigned int unk08;
    HkElem2c* unk0c;
};
struct HkInput
{
    int unk00;
    int unk04;
    int unk08;
    HkInfo* unk0c;
};
struct HkBody
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
};
// Processes each element of the info array when enabled; otherwise calls Process once with null if body->unk34 is zero.
// @fnv 0x00e88dc0
bool __stdcall ProcessCollector(NiGeometryGroup* collector, HkBody* body, HkInput* input, bool flag, int unused1,
                                int unused2)
{
    // The shared vf02 declaration has no parameters; retain this unit's call signature.
    typedef void (__thiscall* Collect)(NiGeometryGroup*, HkBody*, HkInput*, HkElem2c*);
    if (input && flag && input->unk0c)
    {
        HkInfo* info = input->unk0c;
        HkElem2c* elem = info->unk0c;
        if (elem->unk28 != 0)
            return false;
        unsigned int count = info->unk08;
        for (unsigned int i = 0; i < count; ++i)
        {
            ((Collect)(*(void***)collector)[2])(collector, body, input, &elem[i]);
        }
        return true;
    }
    if (body->unk34 != 0)
        return false;
    ((Collect)(*(void***)collector)[2])(collector, body, input, 0);
    return true;
}
