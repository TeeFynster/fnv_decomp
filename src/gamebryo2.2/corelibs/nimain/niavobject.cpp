#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiPropertyState.h"
#include "../../../../include/NiProperty.h"
#include "../../../../include/NiTListItem.h"
#include "../../../../include/GO.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiUpdateData.h"

// Access storage not yet named in the shared stream declarations.
template <class T> inline T& StreamField(NiStream& stream, unsigned int offset)
{
    return *reinterpret_cast<T*>(reinterpret_cast<char*>(&stream) + offset);
}

inline unsigned int NiBinaryStream::Read(void* destination, unsigned int bytes)
{
    unsigned int size = bytes;
    unsigned int transferred = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))
        (this, destination, bytes, &size, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += transferred;
    return transferred;
}

inline unsigned int NiBinaryStream::Write(const void* source, unsigned int bytes)
{
    unsigned int size = bytes;
    unsigned int transferred = (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 12))
        (this, source, bytes, &size, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += transferred;
    return transferred;
}

// AV overrides absent from the shared class remain ABI-compatible free functions.
// Relocated entry points retain base operations absent from the shared headers.
// Calls cast each address to its original member-call signature.
void __cdecl SaveNiObjectLinks();
void __cdecl RegisterNiObjectLinks();
void __cdecl CompareNiObjectNET();
NiObjectNET* __fastcall ConstructNiObjectNET(NiObjectNET* object);
extern const void* g_NiAVObject_vtable[];
void __cdecl LoadNiObjectNET();
void __cdecl LinkNiObjectNET();

// src/gamebryo2.2/corelibs/nimain/niavobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niavobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00a5a030
void __thiscall NiAVObject::UpdateControllers(NiUpdateData& data)
{
    NiAVObject::UpdateTimeControllers(data, true);
}

extern char const* const g_011f4428_arg1;

// @fnv 0x00a5a420
// src: COMMUNITY 0x00a5a420
char const* const* __cdecl NiAVObject_GetRTTI()
{
    return &g_011f4428_arg1;
}

extern const void* DAT_011f9140;

// @fnv 0x00b4e1d0
// src: XBOX_PDB 0x00b4e1d0
const void* __cdecl BSFadeNode_GetRTTI()
{
    return &DAT_011f9140;
}

extern MemoryManager g_memoryManager;

// @fnv 0x00a59dc0
void __fastcall SetAVObjectBound(NiAVObject* object, void*, NiBound* apBound)
{
    if (object->m_kWorldBound)
    {
        g_memoryManager.Deallocate(object->m_kWorldBound);
    }
    object->m_kWorldBound = reinterpret_cast<FourComponentFloatVector*>(apBound);
    if (apBound)
    {
        object->m_uFlags |= 0x80000;
    }
    else
    {
        object->m_uFlags &= 0xfff7ffff;
    }
}

// Calls the object's vtable slot 42 with the update data, then, if the object at offset 0x18 exists, calls its vtable slot 63.
// @fnv 0x00a59c90
void __thiscall NiAVObject::Update(NiUpdateData& aUpdateData)
{
    UpdateSelectedDownwardPass(aUpdateData, 0);
    if (m_pkParent)
        ((void(__thiscall*)(NiNode*))(*(void***)m_pkParent)[63])(m_pkParent);
}

typedef void(__thiscall* FUN_00a59d00_Fn)(NiNode*, void*);
// @fnv 0x00a59d00
void __thiscall NiAVObject::AssignParent(NiNode* pkParent)
{
    NiNode* pkOldParent = m_pkParent;
    if (pkOldParent)
    {
        (*(FUN_00a59d00_Fn*)((char*)*(void**)pkOldParent + 0xe8))(pkOldParent, this);
        m_pkParent = pkParent;
    }
    else
    {
        m_pkParent = pkParent;
    }
}

// Retrieves property 2 and, if present, passes it to the renderer's v61 method.
// @fnv 0x00a59e50
void __thiscall NiAVObject::PurgeRendererData(NiRenderer* apkRenderer)
{
    NiProperty* pkProperty = GetProperty(2);
    if (pkProperty)
        ((void(__thiscall*)(NiRenderer*, NiProperty*))(*(void***)apkRenderer)[61])(apkRenderer, pkProperty);
}

namespace fnv_00a59ec0 {
void __cdecl ProcessPropertyClones();

// @fnv 0x00a59ec0
void __fastcall ProcessAVObjectClone(NiAVObject* object, void*, CloningProcess& kCloning)
{
    object->NiObjectNET::ProcessClone(kCloning);
    if (object->m_kPropertyList.m_kItemCount.m_uiCount)
    {
        reinterpret_cast<void(__thiscall*)(NiAVObject*, void*, CloningProcess&)>(ProcessPropertyClones)
            (object, &object->m_kPropertyList, kCloning);
    }
    NiObjectNET* pkCollision = reinterpret_cast<NiObjectNET*>(object->m_spCollisionObject.m_pObject);
    if (pkCollision)
        pkCollision->ProcessClone(kCloning);
}
}  // namespace fnv_00a59ec0

struct Param
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual int Get();
};
struct Owner
{
    GO arr[8];
    void __thiscall SetSlot(Param* p);
};
// If p is non-null and p->Get() is at most 7, stores p into arr at index p->Get().
// @fnv 0x00a59f50
void __thiscall Owner::SetSlot(Param* pParam)
{
    if (pParam && pParam->Get() <= 7)
        arr[pParam->Get()] = pParam;
}

// @fnv 0x00a59f90
void __thiscall NiAVObject::UpdateDownwardPass(NiUpdateData& kData, unsigned int uiFlags)
{
    if ((*reinterpret_cast<bool*>(&kData.pad1)))
        UpdateTimeControllers(kData, true);
    UpdateWorldData(kData);
    UpdateWorldBound();
}

// Returns whether any attached property has a controller.
// @fnv 0x00a5a110
bool __thiscall NiAVObject::GetHasPropertyController() const
{
    NiTListItem<NiObjectNET*>* pNode = reinterpret_cast<NiTListItem<NiObjectNET*>*>(m_kPropertyList.m_pkHead);
    while (pNode)
    {
        NiObjectNET** pp = &pNode->m_element;
        pNode = pNode->m_pkNext;
        NiObjectNET* d = *pp;
        if (d && d->m_spControllers)
            return true;
    }
    return false;
}

void __fastcall ReleaseStorage_00a5a390(void*);
void __cdecl _delete(void*, unsigned int);

// Calls FUN_00a5a390 on this, frees this with _delete when bit 0 of a1 is set, and returns this.
// @fnv 0x00a5aa90
void* __fastcall DeleteAVObject(NiAVObject* object, void*, unsigned int auiFlags)
{
    ReleaseStorage_00a5a390(object);
    if (auiFlags & 1)
        _delete(object, 0x9c);
    return object;
}

// Updates with a temporary parent before attachment.
// @fnv 0x00a59cc0
void __thiscall NiAVObject::PreAttachUpdate(NiNode* pEventualParent, NiUpdateData& UpdateData)
{
    m_pkParent = pEventualParent;
    UpdateDownwardPass(UpdateData, false);
    m_pkParent = 0;
}

// @fnv 0x00a59db0
void __thiscall NiAVObject::FinalizeAttachUpdate(NiNode* arg)
{
    m_pkParent = 0;
}

namespace fnv_00a59e20 { extern int EmptyFS; }
using fnv_00a59e20::EmptyFS;

// @fnv 0x00a59e20
// src: GAMEBRYO_LIB 0x00a59e20
int NiAVObject::GetObjectByName_00a59e20(int param)
{
    int handle = *reinterpret_cast<int*>(param);
    if (handle == EmptyFS)
        return 0;
    int diff = reinterpret_cast<int>(m_kName.m_kHandle) != handle;
    return (diff - 1) & reinterpret_cast<int>(this);
}

// @fnv 0x00a5a430
void NiAVObject::SetEventualParent(NiNode* pEventualParent)
{
    this->m_pkParent = pEventualParent;
    NiAVObject::UpdateSceneObject();
    this->m_pkParent = 0;
}

class A59CF0Node
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
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void UpdateSceneObject();
};

// @fnv 0x00a59cf0
void NiAVObject::CompleteAttachUpdate()
{
    reinterpret_cast<A59CF0Node*>(m_pkParent)->UpdateSceneObject();
}

// Updates world data and bounds when selective updates are enabled.
// @fnv 0x00a59d80
void __thiscall NiAVObject::UpdateTransformAndBounds(NiUpdateData& pArg)
{
    unsigned char flags = (unsigned char)(m_uFlags >> 2);
    if (flags & 1)
    {
        UpdateWorldData(pArg);
        UpdateWorldBound();
    }
}

// @fnv 0x00a59e00
void NiAVObject::OnVisible(NiCullingProcess& culler)
{
    if (!(m_uFlags & 1))
        ((void(__thiscall*)(NiCullingProcess*, NiAVObject*))(*(void***)&culler)[17])(&culler, this);
}

struct ItemBase
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26(void* arg) = 0;
};

struct ListOwner
{
    unsigned int unk00;
    NiTListItem<ItemBase*>* m_04;
};

struct Filter
{
    bool __thiscall FUN_00b63170(ItemBase* item, ListOwner*& owner);
};

struct Holder
{
    unsigned int unk00;
    Filter* m_04;
};

inline ItemBase* const& GetNext(NiTListItem<ItemBase*>*& pos)
{
    ItemBase* const& element = pos->m_element;
    pos = pos->m_pkPrev;
    return element;
}

// @fnv 0x00a59e70
// src: XBOX_PDB 0x00a59e70
void __stdcall NiAVObject_ProcessPropertyClones(ListOwner* owner, Holder* holder)
{
    NiTListItem<ItemBase*>* node = owner->m_04;
    while (node != 0)
    {
        ItemBase* item = GetNext(node);
        if (holder->m_04->FUN_00b63170(item, owner) == false)
        {
            item->v26(holder);
        }
    }
}

struct FUN_00a59f00_obj
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
    virtual void v21(void* p)
    {}
};

// Registers the base object, attached properties and collision object.
// @fnv 0x00a59f00
bool __fastcall RegisterAVObjectLinks(NiAVObject* object, void*, NiStream& stream)
{
    if (!reinterpret_cast<bool(__thiscall*)(NiObjectNET*, NiStream&)>(RegisterNiObjectLinks)(object, stream))
    {
        return false;
    }
    NiTListItem<FUN_00a59f00_obj*>* node = reinterpret_cast<NiTListItem<FUN_00a59f00_obj*>*>(object->m_kPropertyList.m_pkHead);
    while (node != 0)
    {
        FUN_00a59f00_obj*& pObj = node->m_element;
        node = node->m_pkNext;
        if (pObj != 0)
        {
            pObj->v21(&stream);
        }
    }
    FUN_00a59f00_obj* pLastObj = reinterpret_cast<FUN_00a59f00_obj*>(object->m_spCollisionObject.m_pObject);
    if (pLastObj != 0)
    {
        pLastObj->v21(&stream);
    }
    return true;
}

inline NiObjectNET* const& GetNextData(NiTListItem<NiObjectNET*>*& pos)
{
    NiObjectNET* const& element = pos->m_element;
    pos = pos->m_pkNext;
    return element;
}

// @fnv 0x00a5a140
void __fastcall UpdateAVPropertyControllerFlag(NiAVObject* object, void*, int unused)
{
    NiTListItem<NiObjectNET*>* pos = reinterpret_cast<NiTListItem<NiObjectNET*>*>(object->m_kPropertyList.m_pkHead);
    while (pos != 0)
    {
        NiObjectNET* d = GetNextData(pos);
        if (d != 0 && d->m_spControllers != 0)
        {
            object->m_uFlags |= 0x40000;
            return;
        }
    }
    object->m_uFlags &= 0xfffbffff;
}

namespace fnv_00a5a900 {
void* __cdecl NiMalloc(unsigned int);
void __cdecl NiFree(void*);

template <class T> inline void SerializeValue(NiStream& kStream, const T& value)
{
    StreamField<NiBinaryStream*>(kStream, 0x250)->Write(&value, sizeof(T));
}

struct Sub34
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
    void ReadMatrixFromStream(NiStream&);
};

// Saves base data, flags, local transform, property links and the collision link.
// @fnv 0x00a5a900
void __fastcall SaveAVObject(NiAVObject* object, void*, NiStream& kStream)
{
    reinterpret_cast<void(__thiscall*)(NiObjectNET*, NiStream&)>(SaveNiObjectLinks)(object, kStream);
    SerializeValue(kStream, object->m_uFlags);
    reinterpret_cast<NiColor*>(&object->m_kLocal.m_Translate)->SaveBinary(kStream);
    reinterpret_cast<Sub34*>(&object->m_kLocal.m_Rotate)->ReadMatrixFromStream(kStream);
    SerializeValue(kStream, object->m_kLocal.m_fScale);
    long iNumObjects = object->m_kPropertyList.m_kItemCount.m_uiCount;
    SerializeValue(kStream, iNumObjects);
    if (0 < iNumObjects)
    {
        NiObject** ppkObjects = (NiObject**)NiMalloc(iNumObjects * 4);
        NiTListItem<NiObject*>* pos = reinterpret_cast<NiTListItem<NiObject*>*>(object->m_kPropertyList.m_pkHead);
        NiObject** pp = ppkObjects;
        while (pos)
        {
            NiObject*& tmp = pos->m_element;
            pos = pos->m_pkNext;
            *pp++ = tmp;
        }
        for (int i = iNumObjects - 1; i >= 0; i--)
            kStream.SaveLinkID(reinterpret_cast<const NiObject*>(ppkObjects[i]));
        NiFree(ppkObjects);
    }
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>(object->m_spCollisionObject.m_pObject));
}
}  // namespace fnv_00a5a900

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* p);

struct Child
{
    virtual void v00();
    virtual void v01();
    int m_04;
};

struct Sub34
{
    int s00, s04, s08, s0c, s10, s14, s18, s1c, s20, s24, s28, s2c, s30;
    void Reset();
};

// @fnv 0x00a5aa20
NiAVObject* __fastcall ConstructAVObject(NiAVObject* object)
{
    ConstructNiObjectNET(object);
    *reinterpret_cast<const void***>(object) = g_NiAVObject_vtable;
    (*reinterpret_cast<Child* volatile*>(&object->m_spCollisionObject.m_pObject)) = 0;
    Sub34* sub = reinterpret_cast<Sub34*>(&object->m_kLocal);
    (*reinterpret_cast<volatile int*>(&object->m_kPropertyList.m_kItemCount.m_uiCount)) = 0;
    (*reinterpret_cast<volatile int*>(&object->m_kPropertyList.m_pkHead)) = 0;
    (*reinterpret_cast<volatile int*>(&object->m_kPropertyList.m_pkTail)) = 0;
    object->m_pkParent = 0;
    object->m_uFlags = 0;
    sub->Reset();
    reinterpret_cast<Sub34*>(&object->m_kWorld)->Reset();
    int flags = object->m_uFlags;
    object->m_kWorldBound = 0;
    *(volatile int*)&object->m_uFlags = (flags & 0xffffffef) | 0x8000e;

    Child* p = (*reinterpret_cast<Child* volatile*>(&object->m_spCollisionObject.m_pObject));
    if (p != 0)
    {
        if (!IsBadCodePtr(&p->m_04))
            p->v01();
        (*reinterpret_cast<Child* volatile*>(&object->m_spCollisionObject.m_pObject)) = 0;
    }
    return object;
}

struct FUN_00a71b70_cls
{
    char _pad_00[0x18];
    unsigned char m_18;
    FUN_00a71b70_cls* SetField18(unsigned char v);
};

// @fnv 0x00a71b70
// src: GUESS 0x00a71b70 (confidence: low)
FUN_00a71b70_cls* FUN_00a71b70_cls::SetField18(unsigned char v)
{
    m_18 = v;
    return this;
}

class B4E150SortAdjustNode
{
  public:
    B4E150SortAdjustNode(unsigned int uiChildren);
    virtual ~B4E150SortAdjustNode();

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
};

struct B4E150Array
{
    void* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiGrowBy;

    B4E150Array() : m_pBase(0), m_uiMaxSize(0), m_uiSize(0), m_uiGrowBy(0)
    {}
};

class FUN_00b4e150 : public B4E150SortAdjustNode
{
  public:
    float m_fNearPlane;
    float m_fFarPlane;
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
    float m_fD;
    int m_iE;
    int unkC8;
    int m_iF;
    int m_iG;
    B4E150Array m_kUnsortedGeometryList;

    FUN_00b4e150();
    virtual ~FUN_00b4e150();
};

// @fnv 0x00b4e150
FUN_00b4e150::FUN_00b4e150() : B4E150SortAdjustNode(0)
{
    m_fNearPlane = 3.402823466e+38f;
    m_fFarPlane = 3.402823466e+38f;
    m_uiValue1 &= ~0x2c000;
    m_iG = 0;
    m_fCoefficientA = 0.0f;
    m_fB = 0.0f;
    m_fC = 0.0f;
    m_fD = 0.0f;
    m_iE = 0;
    m_iF = 0;
}

struct FUN_0040fbf0_shell
{
    void BSSpinLock_Lock(char* name);
};

struct FUN_00a5e3a0_Helper
{
    void NiNode_UpdatePropertiesUpward(NiPropertyState*& ps);
    NiPropertyState* FUN_00a89ab0();
    void* Game_DoHeapAlloc(unsigned int size);
};

extern unsigned int DAT_011f42a0;
extern unsigned int DAT_011f42a4;
extern unsigned int DAT_011f6238;

// @fnv 0x00a5a040
// src: XBOX_PDB 0x00a5a040
void NiAVObject::UpdateProperties()
{
    NiPropertyState* ps = 0;
    ((FUN_0040fbf0_shell*)&DAT_011f42a0)->BSSpinLock_Lock(0);
    if (reinterpret_cast<FUN_00a5e3a0_Helper*>(m_pkParent) != 0)
    {
        reinterpret_cast<FUN_00a5e3a0_Helper*>(m_pkParent)->NiNode_UpdatePropertiesUpward(ps);
    }
    else
    {
        void* pAlloc = ((FUN_00a5e3a0_Helper*)&DAT_011f6238)->Game_DoHeapAlloc(28);
        if (pAlloc != 0)
        {
            ps = ((FUN_00a5e3a0_Helper*)pAlloc)->FUN_00a89ab0();
        }
        else
        {
            ps = 0;
        }
    }
    UpdatePropertiesDownwardPass(ps);
    NiPropertyState* p = ps;
    if (p != 0)
    {
        p->ReleaseAllRefs();
        ((MemoryManager*)&DAT_011f6238)->Deallocate(p);
    }
    DAT_011f42a4--;
    if (DAT_011f42a4 == 0)
    {
        DAT_011f42a0 = 0;
    }
}

__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct LoadedRef
{
    virtual ~LoadedRef();
    virtual void DeleteThis() throw();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
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
    virtual void ReadVersion(unsigned int, int);
    volatile long count;
};
struct LoadedPtr
{
    LoadedRef* pointer;
    LoadedPtr(LoadedRef* value) throw() : pointer(value)
    {
        if (value)
            InterlockedIncrement(&value->count);
    }

    void FUN_0066b0d0(LoadedRef*);
};
struct LoadedArray
{
    void FUN_00a5a310(const LoadedPtr&) throw();
    void NiAVObject_AttachProperty_00439fd0(const LoadedPtr&) throw();
};

// Reads a child count from the stream and loads each child into children, then loads the controller for newer versions.
// @fnv 0x00a5a7f0
void __fastcall LinkAVObject(NiAVObject* object, void*, NiStream* stream)
{
    reinterpret_cast<void(__thiscall*)(NiObjectNET*, NiStream*)>(LinkNiObjectNET)(object, stream);
    unsigned int count = stream->GetLinkID();
    if (StreamField<unsigned int>(*stream, 0xd8) < 0x04010008)
    {
        while (count)
        {
            count--;
            LoadedRef* raw = reinterpret_cast<LoadedRef*>(stream->GetLoadedObject());
            LoadedPtr child = raw;
            reinterpret_cast<LoadedArray*>(&object->m_kPropertyList)->FUN_00a5a310(child);
            if (raw && !InterlockedDecrement(&raw->count))
                raw->DeleteThis();
        }
    }
    else
    {
        while (count)
        {
            count--;
            LoadedRef* raw = reinterpret_cast<LoadedRef*>(stream->GetLoadedObject());
            LoadedPtr child = raw;
            reinterpret_cast<LoadedArray*>(&object->m_kPropertyList)->NiAVObject_AttachProperty_00439fd0(child);
            if (raw && !InterlockedDecrement(&raw->count))
                raw->DeleteThis();
        }
        if (StreamField<unsigned int>(*stream, 0xd8) >= 0x05000013)
        {
            reinterpret_cast<LoadedPtr*>(&object->m_spCollisionObject)->FUN_0066b0d0(reinterpret_cast<LoadedRef*>(stream->GetLoadedObject()));
            LoadedRef* pController = reinterpret_cast<LoadedPtr*>(&object->m_spCollisionObject)->pointer;
            if (pController)
                pController->ReadVersion(StreamField<unsigned int>(*stream, 0xd8), 0);
        }
    }
}

struct Stream
{
    void* vtable;
    unsigned int* values;
    unsigned short capacity;
    unsigned short length;
    unsigned short active;
    unsigned short growth;
    void FUN_0096ad30(unsigned int required);
    void FUN_0096ae90(unsigned int index, unsigned int* value);
    __forceinline void Add(unsigned int value)
    {
        unsigned int index = length;
        if (index >= capacity)
            FUN_0096ad30(index + growth);
        FUN_0096ae90(index, &value);
    }
};
struct SerializedField
{
    unsigned int state0;
    unsigned int state4;
    unsigned int state8;
    unsigned int stateC;
    unsigned int state10;
    unsigned int state14;
    unsigned int state18;
    unsigned int state1C;
    unsigned int state20;
    unsigned int GetViewerString_00a59af0(const char* name);
    unsigned int ToString(const char* name);
};
struct SmallField
{
    unsigned int state0;
    unsigned int state4;
    unsigned int state8;
    unsigned int GetViewerString_00a59af0(const char* name);
    unsigned int ToString(const char* name);
};
struct IndexedElement
{
    virtual void f0();
    virtual void f1();
    virtual unsigned int* GetValue();
};
inline IndexedElement* const& GetNextIndexed(NiTListItem<IndexedElement*>*& pos)
{
    IndexedElement* const& element = pos->m_element;
    pos = pos->m_pkNext;
    return element;
}
void __stdcall NiObjectNET_GetViewerStrings(Stream* stream);
unsigned int __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int source);
unsigned int __cdecl NiGetViewerString(const char* name, unsigned int value);
unsigned int __cdecl NiGetViewerString_00a7d550(const char* name, float value);
unsigned int __cdecl NiGetViewerString_00a7d5a0(unsigned int value, IndexedElement* element);
struct TextSource
{
    unsigned int GetViewerString_00a7fb20(const char* name);
};
extern unsigned int DAT_011f4280;
extern char DAT_011f4288;
extern char DAT_0109b204, DAT_0109b1f8, DAT_0109b1e4, DAT_0109b1d4, DAT_0109b1c4, DAT_0109b1b0;
extern char DAT_0109b1a0, DAT_0109b190, DAT_0109b184, DAT_0109b178, DAT_0109b164, DAT_0109b154;
extern char DAT_0109b138, DAT_0109b124, DAT_0109b118, DAT_0109b10c;

// @fnv 0x00a5ad00
void __fastcall GetAVViewerStrings(NiAVObject* object, void*, Stream* stream)
{
    NiObjectNET_GetViewerStrings(stream);
    stream->Add(NiViewerStrings_NiGetViewerString_Title(DAT_011f4280));
    union FlagWord
    {
        unsigned int word;
        unsigned char byte;
    } firstFlag;
    firstFlag.byte = static_cast<unsigned char>(object->m_uFlags) & 1;
    stream->Add(NiGetViewerString(&DAT_0109b204, firstFlag.word));
    unsigned char bFlag11 = static_cast<unsigned char>(object->m_uFlags >> 11) & 1;
    if (bFlag11)
    {
        union FlagWord
        {
            unsigned int word;
            unsigned char byte;
        } flag11;
        flag11.byte = bFlag11;
        stream->Add(NiGetViewerString(&DAT_0109b1f8, flag11.word));
    }
    stream->Add((*reinterpret_cast<SmallField*>(&object->m_kLocal.m_Translate)).GetViewerString_00a59af0(&DAT_0109b1e4));
    stream->Add((*reinterpret_cast<SerializedField*>(&object->m_kLocal.m_Rotate)).ToString(&DAT_0109b1d4));
    stream->Add(NiGetViewerString_00a7d550(&DAT_0109b1c4, object->m_kLocal.m_fScale));
    stream->Add((*reinterpret_cast<SmallField*>(&object->m_kWorld.m_Translate)).GetViewerString_00a59af0(&DAT_0109b1b0));
    stream->Add((*reinterpret_cast<SerializedField*>(&object->m_kWorld.m_Rotate)).ToString(&DAT_0109b1a0));
    stream->Add(NiGetViewerString_00a7d550(&DAT_0109b190, object->m_kWorld.m_fScale));
    stream->Add((reinterpret_cast<TextSource*>(object->m_kWorldBound) ? reinterpret_cast<TextSource*>(object->m_kWorldBound) : reinterpret_cast<TextSource*>(&DAT_011f4288))->GetViewerString_00a7fb20(&DAT_0109b184));
    union FlagWord1
    {
        unsigned int word;
        unsigned char byte;
    } flag1;
    flag1.byte = static_cast<unsigned char>(object->m_uFlags >> 1) & 1;
    stream->Add(NiGetViewerString(&DAT_0109b178, flag1.word));
    union FlagWord2
    {
        unsigned int word;
        unsigned char byte;
    } flag2;
    flag2.byte = static_cast<unsigned char>(object->m_uFlags >> 2) & 1;
    stream->Add(NiGetViewerString(&DAT_0109b164, flag2.word));
    union FlagWord4
    {
        unsigned int word;
        unsigned char byte;
    } flag4;
    flag4.byte = static_cast<unsigned char>(object->m_uFlags >> 4) & 1;
    stream->Add(NiGetViewerString(&DAT_0109b154, flag4.word));
    union FlagWord3
    {
        unsigned int word;
        unsigned char byte;
    } flag3;
    flag3.byte = static_cast<unsigned char>(object->m_uFlags >> 3) & 1;
    stream->Add(NiGetViewerString(&DAT_0109b138, flag3.word));
    if (object->m_kPropertyList.m_kItemCount.m_uiCount)
    {
        NiTListItem<IndexedElement*>* node = reinterpret_cast<NiTListItem<IndexedElement*>*>(object->m_kPropertyList.m_pkHead);
        while (node != 0)
        {
            IndexedElement* element = GetNextIndexed(node);
            unsigned int key = *element->GetValue();
            unsigned int next = NiGetViewerString_00a7d5a0(key, element);
            unsigned int index = stream->length;
            if (index >= stream->capacity)
                stream->FUN_0096ad30(index + stream->growth);
            if (index >= stream->length)
            {
                stream->length = index + 1;
                if (next != 0)
                    ++stream->active;
            }
            else if (next != 0)
            {
                if (stream->values[index] == 0)
                    ++stream->active;
            }
            else if (stream->values[index] != 0)
            {
                --stream->active;
            }
            stream->values[index] = next;
        }
    }
    if (object->m_spCollisionObject.m_pObject)
        stream->Add(NiGetViewerString_00a7d5a0((unsigned int)&DAT_0109b124, reinterpret_cast<IndexedElement*>(object->m_spCollisionObject.m_pObject)));
    unsigned char bFlag10 = static_cast<unsigned char>(object->m_uFlags >> 10) & 1;
    if (bFlag10)
    {
        union FlagWord10
        {
            unsigned int word;
            unsigned char byte;
        } flag10;
        flag10.byte = bFlag10;
        stream->Add(NiGetViewerString(&DAT_0109b118, flag10.word));
    }
    unsigned char bit13 = static_cast<unsigned char>(object->m_uFlags >> 13) & 1;
    if (bit13)
    {
        union FlagWord13
        {
            unsigned int word;
            unsigned char byte;
        } flag13;
        flag13.byte = bit13;
        stream->Add(NiGetViewerString(&DAT_0109b10c, flag13.word));
    }
}

inline bool GetAVSelectiveUpdate(const NiAVObject* object)
{
    return ((object->m_uFlags >> 2) & 1) != 0;
}
inline bool GetAVSelectiveTransforms(const NiAVObject* object)
{
    return ((object->m_uFlags >> 3) & 1) != 0;
}

// @fnv 0x00a59fd0
void NiAVObject::UpdateRigidDownwardPass(NiUpdateData& kData, unsigned int uiUnused)
{
    bool m_bUpdateEnabled = (*reinterpret_cast<bool*>(&kData.pad1));
    (*reinterpret_cast<bool*>(&kData.pad1)) = GetAVSelectiveTransforms(this);
    UpdateTimeControllers(kData, true);
    (*reinterpret_cast<bool*>(&kData.pad1)) = m_bUpdateEnabled;

    if (GetAVSelectiveUpdate(this) && !(*reinterpret_cast<bool*>(&kData.pad2)))
    {
        UpdateWorldData(kData);
        UpdateWorldBound();
    }
}

// 0x00c6c760  ret 0xc
// @fnv 0x00c6c760
// src: COMMUNITY 0x00c6c760
void __stdcall nullsub_34(int, int, int)
{}

// Returns the first attached property of the requested type.
// @fnv 0x00a59d30
NiProperty* NiAVObject::GetProperty(unsigned int type)
{
    int iType = static_cast<int>(type);
    if (iType >= 7)
        return 0;
    NiTListItem<NiPointer<NiProperty> >* kPos = m_kPropertyList.m_pkHead;
    while (kPos)
    {
        NiProperty* const& element = kPos->m_element.m_pObject;
        kPos = kPos->m_pkNext;
        NiProperty* pkItem = element;
        if (pkItem && pkItem->GetType() == iType)
            return pkItem;
    }
    return 0;
}

class TimeCtrlA5A4
{
  public:
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
    virtual bool IsTransformController() const;

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    TimeCtrlA5A4* m_spNextController;
};

// @fnv 0x00a5a0e0
bool __fastcall HasAVTransformController(const NiAVObject* object)
{
    TimeCtrlA5A4* p = reinterpret_cast<TimeCtrlA5A4*>(object->m_spControllers);
    while (p)
    {
        if (p->IsTransformController())
            return true;
        p = p->m_spNextController;
    }
    return false;
}

inline bool HasTransformController(const NiAVObject* object)
{
    for (TimeCtrlA5A4* p = reinterpret_cast<TimeCtrlA5A4*>(object->m_spControllers); p; p = p->m_spNextController)
        if (p->IsTransformController()) return true;
    return false;
}
inline bool GetAVBit(const NiAVObject* object, unsigned int mask, unsigned int position)
{
    return ((object->m_uFlags & mask) >> position) != 0;
}
inline void SetAVBit(NiAVObject* object, bool value, unsigned int mask)
{
    if (value) object->m_uFlags |= mask; else object->m_uFlags &= ~mask;
}

// @fnv 0x00a5a450
void NiAVObject::SetSelectiveUpdateFlags(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms, bool& bRigid)
{
    bRigid = !HasTransformController(this) && !GetAVBit(this, 0x80, 7);
    if (!bSelectiveUpdateTransforms)
        bSelectiveUpdateTransforms = !bRigid;
    bool bSelectiveUpdatePropertyControllers = GetHasPropertyController();
    if (bSelectiveUpdatePropertyControllers || bSelectiveUpdateTransforms || m_spControllers)
        bSelectiveUpdate = true;
    else
        bSelectiveUpdate = false;
    SetAVBit(this, bSelectiveUpdate, 2);
    SetAVBit(this, bSelectiveUpdateTransforms, 4);
    SetAVBit(this, bSelectiveUpdatePropertyControllers, 8);
    SetAVBit(this, true, 0x10);
}

struct A5a260CompareBase
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual bool FUN_00a5a260(A5a260CompareBase*) = 0;
};

struct A5a260CompareField
{
    bool __thiscall FUN_00a86c30(A5a260CompareField*);
};

inline A5a260CompareBase*& GetNext_a5a(NiTListItem<A5a260CompareBase*>*& pos)
{
    A5a260CompareBase*& element = pos->m_element;
    pos = pos->m_pkNext;
    return element;
}

// Returns false when the flag bit, field comparison, property list, or collision comparison does not match.
// @fnv 0x00a5a260
bool __fastcall CompareAVObjects(NiAVObject* object, void*, NiObject* pkObject)
{
    NiAVObject* other = static_cast<NiAVObject*>(pkObject);

    if (!reinterpret_cast<bool(__thiscall*)(NiObjectNET*, NiObject*)>(CompareNiObjectNET)(object, pkObject))
        return false;

    if ((static_cast<unsigned char>(object->m_uFlags) ^ *reinterpret_cast<volatile unsigned char*>(&other->m_uFlags)) & 1)
        return false;

    if (reinterpret_cast<A5a260CompareField*>(&object->m_kLocal)->FUN_00a86c30(reinterpret_cast<A5a260CompareField*>(&other->m_kLocal)))
        return false;

    unsigned int count = object->m_kPropertyList.m_kItemCount.m_uiCount;
    if (count != other->m_kPropertyList.m_kItemCount.m_uiCount)
        return false;

    if (count > 0)
    {
        NiTListItem<A5a260CompareBase*>* node0 = reinterpret_cast<NiTListItem<A5a260CompareBase*>*>(object->m_kPropertyList.m_pkHead);
        NiTListItem<A5a260CompareBase*>* node1 = reinterpret_cast<NiTListItem<A5a260CompareBase*>*>(other->m_kPropertyList.m_pkHead);
        while (node0)
        {
            A5a260CompareBase* property0 = GetNext_a5a(node0);
            A5a260CompareBase* property1 = GetNext_a5a(node1);
            if (property0 && !property1)
                return false;
            if (!property0 && property1)
                return false;
            if (property0 && !property0->FUN_00a5a260(property1))
                return false;
        }
    }

    A5a260CompareBase* collision0 = reinterpret_cast<A5a260CompareBase*>(object->m_spCollisionObject.m_pObject);
    A5a260CompareBase* collision1 = reinterpret_cast<A5a260CompareBase*>(other->m_spCollisionObject.m_pObject);
    if (collision0 && collision1)
    {
        if (!collision0->FUN_00a5a260(collision1))
            return false;
    }
    else if (collision0 != collision1)
    {
        return false;
    }
    return true;
}

#include <string.h>

extern const float DAT_011f426c;
struct LoadVector
{
    float x, y, z;
    void FUN_00a59be0(NiStream&);
    bool _Call_439090(const void*);
};
struct Matrix3x3
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    void LoadFromStream(NiStream&);
};
struct LegacyData;
struct LoadContext
{
    NiAVObject* object;
    NiStream* stream;
    bool enabled;
    unsigned short mode;
};
struct LegacyData
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
    virtual void LoadLegacy(LoadContext*);
    virtual void Convert(unsigned int, int);
};
LegacyData* __cdecl InvokeNamedFunction(const char*);

// Reads flags, translation, rotation, and scale, then handles legacy collision data and version-dependent flag updates.
// @fnv 0x00a5a510
void __fastcall LoadAVObject(NiAVObject* object, void*, NiStream& stream)
{
    reinterpret_cast<void(__thiscall*)(NiObjectNET*, NiStream&)>(LoadNiObjectNET)(object, stream);
    if (StreamField<unsigned int>(stream, 4) < 28)
    {
        unsigned short oldFlags;
        StreamField<NiBinaryStream*>(stream, 0x24c)->Read(&oldFlags, 2);
        object->m_uFlags = oldFlags;
    }
    else
    {
        StreamField<NiBinaryStream*>(stream, 0x24c)->Read(&object->m_uFlags, 4);
    }
    if (StreamField<unsigned int>(stream, 0xd8) < 0x0401000b)
    {
        unsigned short low = (unsigned short)object->m_uFlags;
        object->m_uFlags = (object->m_uFlags & ~7u) << 1;
        object->m_uFlags |= low & 7;
    }
    if (StreamField<unsigned int>(stream, 0xd8) < 0x0401000c)
    {
        unsigned short low = (unsigned short)object->m_uFlags;
        object->m_uFlags <<= 4;
        *reinterpret_cast<unsigned char*>(&object->m_uFlags) = 0;
        object->m_uFlags &= ~0x80u;
        object->m_uFlags |= low & 15;
        object->m_uFlags |= 0x70;
    }
    if (StreamField<unsigned int>(stream, 0xd8) < 0x05000001)
    {
        unsigned short low = (unsigned short)object->m_uFlags;
        object->m_uFlags = (object->m_uFlags & ~255u) << 1;
        object->m_uFlags |= (unsigned char)low;
    }
    reinterpret_cast<LoadVector*>(&object->m_kLocal.m_Translate)->FUN_00a59be0(stream);
    reinterpret_cast<Matrix3x3*>(&object->m_kLocal.m_Rotate)->LoadFromStream(stream);
    StreamField<NiBinaryStream*>(stream, 0x24c)->Read(&object->m_kLocal.m_fScale, 4);
    if (StreamField<unsigned int>(stream, 0xd8) < 0x05000013)
    {
        unsigned int mode = (object->m_uFlags >> 1) & 7;
        unsigned short low = (unsigned short)object->m_uFlags;
        object->m_uFlags = (object->m_uFlags >> 3) & 0xfffe;
        object->m_uFlags |= low & 1;
        LoadVector oldTranslation = {0.0f, 0.0f, 0.0f};
        oldTranslation.FUN_00a59be0(stream);
        stream.ReadUnsignedInteger();
        unsigned char enabled;
        unsigned int oldEnabled;
        if (StreamField<unsigned int>(stream, 0xd8) < 0x04010000)
        {
            StreamField<NiBinaryStream*>(stream, 0x24c)->Read(&oldEnabled, 4);
            enabled = oldEnabled != 0;
        }
        else
        {
            StreamField<NiBinaryStream*>(stream, 0x24c)->Read(&enabled, 1);
        }
        if (strcmp(reinterpret_cast<char*>(&stream) + 0x3bc, "NiCollisionSwitch") == 0 && !((unsigned char)(object->m_uFlags >> 3) & 1))
            mode = 4;
        if (enabled || oldTranslation._Call_439090(&DAT_011f426c) || (unsigned short)mode != 2)
        {
            LegacyData* data = InvokeNamedFunction("NiCollisionData");
            if (data)
            {
                reinterpret_cast<GO*>(&object->m_spCollisionObject)->operator=(data);
                LoadContext context;
                context.mode = (unsigned short)mode;
                context.enabled = enabled != 0;
                context.object = object;
                context.stream = &stream;
                ((LegacyData*)object->m_spCollisionObject.m_pObject)->LoadLegacy(&context);
            }
        }
    }
    else
    {
        stream.ReadUnsignedInteger();
        stream.ReadLinkIDStub();
    }
    if (StreamField<unsigned int>(stream, 0xd8) < 0x0a000102)
    {
        StreamField<unsigned short>(stream, 0x284) = (unsigned short)object->m_uFlags;
        object->m_uFlags &= 0x3f;
    }
    if (StreamField<unsigned int>(stream, 0xd8) < 0x0a000106 && object->m_spCollisionObject.m_pObject)
        ((LegacyData*)object->m_spCollisionObject.m_pObject)->Convert(StreamField<unsigned int>(stream, 0xd8), 0);
    if (StreamField<unsigned int>(stream, 0xd8) < 0x14000004)
        object->m_uFlags &= ~0x40u;
    object->m_uFlags = (object->m_uFlags & ~0x10u) | 0x8000e;
}

namespace fnv_00a89960 {
#include <windows.h>

struct WorkerProperty
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long references;
};
struct WorkerPointer
{
    WorkerProperty* object;
    WorkerPointer& operator=(WorkerProperty* value)
    {
        WorkerProperty* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->references) == 0)
                old->DeleteThis();
            object = value;
            if (object)
                InterlockedIncrement(&object->references);
        }
        return *this;
    }
};
extern WorkerProperty* DAT_011f4410;
extern WorkerProperty* DAT_011f5d28;
extern WorkerProperty* DAT_011f4a64;
extern WorkerProperty* DAT_011f5ae8;
extern WorkerProperty* DAT_011f4a14;
extern WorkerProperty* DAT_011f49ac;
struct WorkerProperties
{
    WorkerPointer alpha;
    WorkerPointer culling;
    WorkerPointer material;
    WorkerPointer shading;
    WorkerPointer stencil;
    WorkerPointer depth;
    void NiPropertyState_Reset();
};
// Assigns six global WorkerProperty pointers to the corresponding WorkerPointer members.
// @fnv 0x00a89960
// src: XBOX_PDB 0x00a89960
void WorkerProperties::NiPropertyState_Reset()
{
    alpha = DAT_011f4410;
    culling = DAT_011f5d28;
    material = DAT_011f4a64;
    shading = DAT_011f5ae8;
    stencil = DAT_011f4a14;
    depth = DAT_011f49ac;
}
}  // namespace fnv_00a89960

namespace fnv_00a5a170 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class A170Obj
{
  public:
    virtual void v00();
    virtual void DeleteThis();
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
    virtual int GetIndex();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

class A170Ptr
{
  public:
    A170Obj* m_pObject;
    A170Ptr& operator=(A170Obj* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
};

inline A170Obj* const& A170GetNext(NiTListItem<A170Obj*>*& pos)
{
    A170Obj* const& elem = pos->m_element;
    pos = pos->m_pkNext;
    return elem;
}

struct A170Lock
{
    int m_pOwnerObject;
    int m_uiItemCount;
    void __thiscall BSSpinLock_Lock(unsigned int);
    void Unlock()
    {
        if (--m_uiItemCount == 0)
            m_pOwnerObject = 0;
    }
};
extern A170Lock DAT_011f42a0;

struct A170Heap
{
    void* __thiscall Game_DoHeapAlloc(unsigned int);
};
extern A170Heap DAT_011f6238;

struct A170Set
{
    A170Set* __thiscall FUN_00a89810(A170Set* src);
};

}  // namespace fnv_00a5a170

// Copies attached properties into a new or existing property state.
// @fnv 0x00a5a170
void NiAVObject::BuildPropertyState(NiPropertyState* apSource, bool abAllocate, NiPropertyState*& apResult)
{
    if (!this->m_kPropertyList.m_kItemCount.m_uiCount)
    {
        apResult = apSource;
        return;
    }
    fnv_00a5a170::DAT_011f42a0.BSSpinLock_Lock(0);
    NiPropertyState* result;
    if (abAllocate)
    {
        void* p = fnv_00a5a170::DAT_011f6238.Game_DoHeapAlloc(0x1c);
        result = p ? reinterpret_cast<NiPropertyState*>(((fnv_00a5a170::A170Set*)p)->FUN_00a89810(reinterpret_cast<fnv_00a5a170::A170Set*>(apSource))) : 0;
    }
    else
    {
        result = apSource;
    }
    fnv_00a5a170::A170Ptr* slots = (fnv_00a5a170::A170Ptr*)result;
    NiTListItem<fnv_00a5a170::A170Obj*>* node = reinterpret_cast<NiTListItem<fnv_00a5a170::A170Obj*>*>(this->m_kPropertyList.m_pkHead);
    while (node)
    {
        fnv_00a5a170::A170Obj* pElement = fnv_00a5a170::A170GetNext(node);
        if (pElement && pElement->GetIndex() <= 7)
            slots[pElement->GetIndex()] = pElement;
    }
    fnv_00a5a170::DAT_011f42a0.Unlock();
    apResult = result;
}
