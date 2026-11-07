#include "../../../../include/NiTStringPointerMap.h"
// gamebryo2.2/corelibs/nimain/ninode.cpp: NiNode, ChildNode, ChildArray, NiPointLight and more (37 functions)

#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiTArray.h"
#include "../../../../include/NiTStringPointerMap.h"
#include "../../../../include/NiMemObject.h"
#include "../../../../include/BGSDecalNode.h"
#include "../../../../include/BSBlastNode.h"
#include "../../../../include/BSNiNode.h"
#include "../../../../include/BSRangeNode.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiPointLight.h"
#include "../../../../include/NiPropertyState.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiStream.h"

// Supporting declarations formerly supplied by ninode_packet_decls.h.

extern MemoryManager g_memoryManager;
inline void* operator new(unsigned int, void* memory)
{
    return memory;
}

// The shared update packet stores the controller and force-update flags as chars.
// Preserve the boolean accesses at offsets 4 and 5 used by these functions.
inline bool& UpdateControllersFlag(NiUpdateData& data)
{
    return reinterpret_cast<bool&>(data.pad1);
}
inline bool& ForceUpdateFlag(NiUpdateData& data)
{
    return reinterpret_cast<bool&>(data.pad2);
}

inline void DestroyPropertyState(NiPropertyState* p)
{
    if (p)
    {
        p->ReleaseAllRefs();
        g_memoryManager.Deallocate(p);
    }
}

// Accessors for fields kept opaque by the shared stream declaration.
inline unsigned int NiStream::GetFileVersion() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

class NiNode;
class NiAVObject;
class NiFixedString;
class NiCullingProcess;
class NiBound;
class CloningProcess;
class ShaderBufferRecord;

class CloningProcess
{
  public:
    NiTStringPointerMap<ShaderBufferRecord*>* m_pCloneMap;
};

__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
__forceinline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

extern NiBound DAT_011f4288;
inline const NiBound& GetBound(NiAVObject* object)
{
    return object->m_kWorldBound ? *(NiBound*)object->m_kWorldBound : DAT_011f4288;
}
inline unsigned char NiAVObject::SelectedFlag() const { return (m_uFlags >> 1) & 1; }
inline unsigned char NiAVObject::RigidFlag() const { return (m_uFlags >> 4) & 1; }
inline unsigned char NiAVObject::TransformFlag() const { return (m_uFlags >> 2) & 1; }
inline unsigned char NiAVObject::BoundFlag13() const { return (m_uFlags >> 13) & 1; }
inline unsigned char NiAVObject::BoundFlag19() const { return (m_uFlags >> 19) & 1; }
inline void NiBound::SetCenterAndRadius(const NiPoint3& center, float radius)
{
    m_kCenter = center;
    m_fRadius = radius;
}
inline unsigned int StrArr::AddInline(char* str)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, str);
    return index;
}

// The approved NiAVObject header does not yet declare these two overrides.
// Declare only their direct-call interface here, without duplicating the class layout.
struct NiAVObjectBaseCalls
{
    void ProcessClone(CloningProcess& process);
    void LoadBinary(NiStream& stream);
};

// Searches this node's children recursively for an object matching name, returning the first match or null.
// @fnv 0x00a5e560
NiAVObject* NiNode::GetObjectByName(const NiFixedString& name) const
{
    NiAVObject* result = NiAVObject::GetObjectByName(name);
    if (result)
        return result;
    for (unsigned int i = 0; i < m_kChildren.m_usSize; ++i)
    {
        NiAVObject* child = m_kChildren.m_pBase[i].m_pObject;
        if (child)
        {
            result = child->GetObjectByName(name);
            if (result)
                return result;
        }
    }
    return 0;
}

// @fnv 0x00a5dc80
void NiNode::CopyMemberData(NiNode* target, CloningProcess& process)
{
    NiAVObject::CopyMembers_00a5ac90(target, process);
    for (unsigned int i = 0; i < m_kChildren.m_usSize; ++i)
    {
        NiAVObject* child = m_kChildren.m_pBase[i].m_pObject;
        if (child)
        {
            NiAVObject* clone = (NiAVObject*)child->MakeClone(process);
            target->ReplaceNthObject(i, clone);
        }
    }
}

// Applies the property state to this node, propagates it to all children, and destroys the temporary state if one was created.
// @fnv 0x00a5db60
void NiNode::UpdatePropertiesDownwardPass(NiPropertyState* state)
{
    NiAVObject::UpdatePropertiesDownwardPass(state);
    NiPropertyState* pLocalState = 0;
    BuildPropertyState(state, true, pLocalState);
    for (unsigned int i = 0; i < m_kChildren.m_usSize; ++i)
    {
        NiAVObject* child = m_kChildren.m_pBase[i].m_pObject;
        if (child)
            child->UpdatePropertiesDownwardPass(pLocalState);
    }
    if (state != pLocalState)
        DestroyPropertyState(pLocalState);
}

// Updates world data when the transform flag is set, recurses into children, and recomputes or merges m_kWorldBound from child bounds.
// @fnv 0x00a5e0b0
void NiNode::UpdateTransformAndBounds(NiUpdateData& data)
{
    if (TransformFlag())
        UpdateWorldData(data);
    unsigned int count = m_kChildren.m_usSize;
    unsigned int i = 0;
    if (BoundFlag19())
    {
        if (!BoundFlag13())
        {
            if (m_kWorldBound)
                ((NiBound*)m_kWorldBound)->m_fRadius = 0.0f;
            for (; i < count; ++i)
            {
                NiAVObject* child = m_kChildren.m_pBase[i].m_pObject;
                if (child)
                {
                    child->UpdateTransformAndBounds(data);
                    if (child->m_kWorldBound && ((NiBound*)child->m_kWorldBound)->m_fRadius != 0.0f)
                    {
                        EnsureWorldBound();
                        const NiBound& bound = ::GetBound(child);
                        ((NiBound*)m_kWorldBound)->SetCenterAndRadius(bound.m_kCenter, bound.m_fRadius);
                        ++i;
                        break;
                    }
                }
            }
        }
        else
            EnsureWorldBound();
    }
    for (; i < count; ++i)
    {
        NiAVObject* child = m_kChildren.m_pBase[i].m_pObject;
        if (child)
        {
            child->UpdateTransformAndBounds(data);
            if (!BoundFlag13() && BoundFlag19())
            {
                NiBound* bound = (NiBound*)child->m_kWorldBound;
                if (bound && bound->m_fRadius != 0.0f)
                    ((NiBound*)m_kWorldBound)->Merge(bound);
            }
        }
    }
}

// Updates controllers and world data, then recurses into children, merging or setting the world bound depending on bound flags.
// @fnv 0x00a5dd70
void NiNode::UpdateDownwardPass(NiUpdateData& aUpdateData, unsigned int flags)
{
    if (UpdateControllersFlag(aUpdateData))
        UpdateTimeControllers(aUpdateData, true);
    UpdateWorldData(aUpdateData);
    if (*(unsigned char*)&m_uFlags & 1)
        flags |= 1;
    unsigned int count = m_kChildren.m_usSize;
    unsigned int i = 0;
    if (BoundFlag19())
    {
        if (!BoundFlag13())
        {
            if (m_kWorldBound)
                ((NiBound*)m_kWorldBound)->m_fRadius = 0.0f;
            for (; i < count; ++i)
            {
                NiAVObject* child = m_kChildren.m_pBase[i].m_pObject;
                if (child)
                {
                    child->UpdateDownwardPass(aUpdateData, flags);
                    if (child->m_kWorldBound && ((NiBound*)child->m_kWorldBound)->m_fRadius != 0.0f)
                    {
                        EnsureWorldBound();
                        const NiBound& bound = ::GetBound(child);
                        ((NiBound*)m_kWorldBound)->SetCenterAndRadius(bound.m_kCenter, bound.m_fRadius);
                        ++i;
                        break;
                    }
                }
            }
        }
        else
            EnsureWorldBound();
    }
    for (; i < count; ++i)
    {
        NiAVObject* child = m_kChildren.m_pBase[i].m_pObject;
        if (child)
        {
            child->UpdateDownwardPass(aUpdateData, flags);
            if (!BoundFlag13() && BoundFlag19())
            {
                NiBound* bound = (NiBound*)child->m_kWorldBound;
                if (bound && bound->m_fRadius != 0.0f)
                    ((NiBound*)m_kWorldBound)->Merge(bound);
            }
        }
    }
}

// Updates selected child nodes' controllers and world bounds, recursing into selected children and merging their bounds into m_kWorldBound.
// @fnv 0x00a5ded0
void NiNode::UpdateSelectedDownwardPass(NiUpdateData& aUpdateData, unsigned int flags)
{
    bool bSavedControllers = UpdateControllersFlag(aUpdateData);
    UpdateControllersFlag(aUpdateData) = (m_uFlags >> 3) & 1;
    UpdateTimeControllers(aUpdateData, true);
    UpdateControllersFlag(aUpdateData) = bSavedControllers;
    bool updateBounds = !ForceUpdateFlag(aUpdateData);
    if (TransformFlag() && updateBounds)
        UpdateWorldData(aUpdateData);
    if (*(unsigned char*)&m_uFlags & 1)
        flags |= 1;
    unsigned int count = m_kChildren.m_usSize;
    unsigned int i = 0;
    if (BoundFlag19())
    {
        if (!BoundFlag13())
        {
            if (updateBounds && m_kWorldBound)
                ((NiBound*)m_kWorldBound)->m_fRadius = 0.0f;
            for (; i < count; ++i)
            {
                NiAVObject* child = m_kChildren.m_pBase[i].m_pObject;
                if (child)
                {
                    if (child->SelectedFlag())
                    {
                        if (child->RigidFlag())
                            child->UpdateRigidDownwardPass(aUpdateData, flags);
                        else
                            child->UpdateSelectedDownwardPass(aUpdateData, flags);
                    }
                    if (child->m_kWorldBound && ((NiBound*)child->m_kWorldBound)->m_fRadius != 0.0f && updateBounds)
                    {
                        EnsureWorldBound();
                        const NiBound& bound = ::GetBound(child);
                        ((NiBound*)m_kWorldBound)->SetCenterAndRadius(bound.m_kCenter, bound.m_fRadius);
                        ++i;
                        break;
                    }
                }
            }
        }
        else
            EnsureWorldBound();
    }
    for (; i < count; ++i)
    {
        NiAVObject* child = m_kChildren.m_pBase[i].m_pObject;
        if (child)
        {
            if (child->SelectedFlag())
            {
                if (child->RigidFlag())
                    child->UpdateRigidDownwardPass(aUpdateData, flags);
                else
                    child->UpdateSelectedDownwardPass(aUpdateData, flags);
            }
            if (!BoundFlag13() && BoundFlag19())
            {
                NiBound* bound = (NiBound*)child->m_kWorldBound;
                if (bound && bound->m_fRadius != 0.0f)
                    ((NiBound*)m_kWorldBound)->Merge(bound);
            }
        }
    }
}

#pragma optimize("", off)
// Stores the dimmer and updates the revision ID.
// @fnv 0x0050dd20
// src: XBOX_PDB 0x0050dd20
void NiPointLight::NiLight_SetDimmer(float afValue)
{
    m_fDimmer = afValue;
    FUN_004bc2c0();
}
#pragma optimize("", on)

struct BSTempEffect;
struct NiCullingProcess;

struct FUN_00a5db30_shell : public NiNode
{
    void NiNode_UpdateUpwardPass();
};

// Calls the object's virtual at offset 0xbc, then if the parent pointer at 0x18 is set, calls the parent's virtual at offset 0xfc.
// @fnv 0x00a5db30
// src: XBOX_PDB 0x00a5db30
void FUN_00a5db30_shell::NiNode_UpdateUpwardPass()
{
    int* pParent = *(int**)((char*)this + 0x18);
    (*(void(__thiscall**)(void*))(*(int*)this + 0xbc))(this);
    if (pParent)
    {
        (*(void(__thiscall**)(void*))(*pParent + 0xfc))(pParent);
    }
}

struct BSFadeNode;
struct BSMultiBoundNode;
struct BSResizableTriShape;
struct BSSegmentedTriShape;
struct NiCullingProcess;
struct NiGeometry;
struct NiLines;
struct NiParticles;
struct NiTriBasedGeom;
struct NiTriShape;
struct NiTriStrips;
struct NiVisibleArray;
struct bhkBlendCollisionObject;
struct bhkLimitedHingeConstraint;
struct bhkNiCollisionObject;
struct bhkRigidBody;

struct FUN_00a5dbe0_shell : public NiNode
{
    void NiNode_OnVisible(NiCullingProcess*);
};

// @fnv 0x00a5dbe0
// src: XBOX_PDB 0x00a5dbe0
void FUN_00a5dbe0_shell::NiNode_OnVisible(NiCullingProcess* kCuller)
{
    if (*(void**)((char*)this + 0x20) && *(float*)(*(char**)((char*)this + 0x20) + 0xc) != 0.0f)
    {
        unsigned int uiChildCount = *(unsigned short*)((char*)this + 0xa6);
        for (unsigned int i = 0; i < uiChildCount; i++)
        {
            NiAVObject* pkChild = (*(NiAVObject***)((char*)this + 0xa0))[i];
            if (pkChild)
                pkChild->Cull(*kCuller);
        }
    }
}

namespace fnv_00a5dce0 {

using ::NiMemObject;
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_00a5dce0_shell : public NiNode
{
    void NiNode_ProcessClone(CloningProcess*);
};

// Processes the clone of this node and recursively processes each child node through the cloning map.
// @fnv 0x00a5dce0
// src: XBOX_PDB 0x00a5dce0
void FUN_00a5dce0_shell::NiNode_ProcessClone(CloningProcess* kCloning)
{
    ((NiAVObjectBaseCalls*)this)->ProcessClone(*kCloning);

    NiObject* pkClone;
    kCloning->m_pCloneMap->GetAt((const char*)this, (ShaderBufferRecord*&)pkClone);

    for (unsigned int i = 0; i < *(unsigned short*)((char*)this + 0xa6); ++i)
    {
        NiAVObject* pkChild = (*(NiAVObject***)((char*)this + 0xa0))[i];
        if (pkChild)
            pkChild->ProcessClone(*kCloning);
    }
}
}  // namespace fnv_00a5dce0

class BSTempEffect;
class NiCullingProcess;
namespace fnv_00a5dd40 {

struct FUN_00a5dd40_shell : public NiNode
{
    void NiNode_LoadBinary(NiStream*);
};

// @fnv 0x00a5dd40
// src: XBOX_PDB 0x00a5dd40
void FUN_00a5dd40_shell::NiNode_LoadBinary(NiStream* kStream)
{
    ((NiAVObjectBaseCalls*)this)->LoadBinary(*kStream);
    kStream->ReadUnsignedInteger();
    kStream->ReadUnsignedInteger();
    *(unsigned int*)((char*)this + 0x30) &= ~0x00200000;
}
}  // namespace fnv_00a5dd40

bool __fastcall HasNodeWithNonZeroValue(NiAVObject* pThis);

struct FUN_00a5e3a0_Helper
{
    void NiNode_UpdatePropertiesUpward(NiPropertyState*& pkState);
};

// @fnv 0x00a5e3a0
// src: XBOX_PDB 0x00a5e3a0
void __fastcall NiNode_UpdatePropertiesUpward(NiAVObject* pThis, int, NiPropertyState*& pkState)
{
    NiPropertyState* pkParentState = 0;

    if (HasNodeWithNonZeroValue(pThis))
        *(unsigned int*)((char*)pThis + 0x30) |= 0x40000;
    else
        *(unsigned int*)((char*)pThis + 0x30) &= ~0x40000;

    FUN_00a5e3a0_Helper* pkParent = *(FUN_00a5e3a0_Helper**)((char*)pThis + 0x18);
    if (pkParent)
    {
        pkParent->NiNode_UpdatePropertiesUpward(pkParentState);
    }
    else
    {
        void* pkMem = g_memoryManager.Allocate(sizeof(NiPropertyState));
        if (pkMem)
            pkParentState = ::new (pkMem) NiPropertyState;
        else
            pkParentState = 0;
    }

    pThis->BuildPropertyState(pkParentState, false, pkState);

    if (pkParentState != pkState)
    {
        NiPropertyState* pkTemp = pkParentState;
        if (pkTemp)
        {
            pkTemp->ReleaseAllRefs();
            g_memoryManager.Deallocate(pkTemp);
        }
    }
}

void __fastcall UpdateFields_00c5faa0(void* pThis);

#include "../../../../include/NiMemObject.h"

// Calls FUN_00a5e930 on pThis, then frees pThis with NiMemObject::operator delete when flags has bit 0 set, and returns pThis.
// @fnv 0x00a5ece0
void* __fastcall FUN_00a5ece0(void* pThis, int, unsigned int flags)
{
    UpdateFields_00c5faa0(pThis);
    if (flags & 1)
    {
        NiMemObject::operator delete(pThis, 0xAC);
    }
    return pThis;
}

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct NodeStub
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
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void V55();
    virtual void V56();
    virtual void V57();
    virtual void V58();
    virtual void RemoveChildAt(unsigned int i, NiRefObject*& spChild);
};

// Retrieves the child reference at index i from node and decrements its reference count if non-null.
// @fnv 0x00a5d8a0
void __fastcall ReleaseChildRef(NiNode* node, int, unsigned int uiIndex)
{
    NiRefObject* spRetainedObject = 0;
    ((NodeStub*)node)->RemoveChildAt(uiIndex, spRetainedObject);
    if (spRetainedObject)
        spRetainedObject->DecRefCount();
}

namespace fnv_00a5d8f0 {
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct NodeStub
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
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void V55();
    virtual void V56();
    virtual void InsertChild(NiAVObject* pkChild, NiRefObject*& spChild);
};

// @fnv 0x00a5d8f0
// src: XBOX_PDB 0x00a5d8f0
void __fastcall NiNode_DetachChild(NiNode* node, int, NiAVObject* pkChild)
{
    NiRefObject* spRetainedObject = 0;
    ((NodeStub*)node)->InsertChild(pkChild, spRetainedObject);
    if (spRetainedObject)
        spRetainedObject->DecRefCount();
}
}  // namespace fnv_00a5d8f0

struct NiRenderer;
struct ChildStub
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
    virtual void V52();
    virtual void V53();
    virtual void PurgeRendererData(NiRenderer* pkRenderer);
};
struct BaseStub
{
    void FUN_00a59e50(NiRenderer*);
};

// Calls FUN_00a59e50 on the node, then calls PurgeRendererData on each non-null child in the node's child array.
// @fnv 0x00a5dc30
// src: XBOX_PDB 0x00a5dc30
void __fastcall NiNode_PurgeRendererData(NiNode* node, int, NiRenderer* pkRenderer)
{
    ((BaseStub*)node)->FUN_00a59e50(pkRenderer);
    for (unsigned int i = 0; i < *(unsigned short*)((char*)node + 0xa6); i++)
    {
        ChildStub* c = (*(ChildStub***)((char*)node + 0xa0))[i];
        if (c)
            c->PurgeRendererData(pkRenderer);
    }
}

// @fnv 0x00a5e1f0
// src: XBOX_PDB 0x00a5e1f0
void __fastcall NiNode_UpdateRigidDownwardPass(NiNode* node, int, NiUpdateData& kData, unsigned int uFlags)
{
    unsigned int nodeFlags = *(unsigned int*)((char*)node + 0x30);
    bool bOldUpdateControllers = UpdateControllersFlag(kData);
    UpdateControllersFlag(kData) = ((nodeFlags >> 3) & 1) != 0;
    node->UpdateTimeControllers(kData, true);
    UpdateControllersFlag(kData) = bOldUpdateControllers;
    unsigned int uiFlags = *(unsigned int*)((char*)node + 0x30);
    bool bWorld = (bool)((uiFlags >> 2) & 1);
    if (bWorld)
        node->UpdateWorldData(kData);
    if (*(unsigned int*)((char*)node + 0x30) & 1)
        uFlags |= 1;
    unsigned int n = *(unsigned short*)((char*)node + 0xa6);
    for (unsigned int i = 0; i < n; i++)
    {
        NiAVObject* c = (*(NiAVObject***)((char*)node + 0xa0))[i];
        if (!c)
            continue;
        unsigned int uiChildFlags = *(unsigned int*)((char*)c + 0x30);
        bool bRigid = (bool)((uiChildFlags >> 1) & 1);
        if (bRigid)
            c->UpdateRigidDownwardPass(kData, uFlags);
    }
}

namespace fnv_00a5e280 {
struct ChildStub
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
    virtual void UpdateControllers(NiUpdateData& kData);
};

// @fnv 0x00a5e280
void __fastcall UpdateChildControllers(NiNode* node, int, NiUpdateData& kData)
{
    node->UpdateTimeControllers(kData, true);
    unsigned int n = *(unsigned short*)((char*)node + 0xa6);
    for (unsigned int i = 0; i < n; i++)
    {
        ChildStub* c = (*(ChildStub***)((char*)node + 0xa0))[i];
        if (c)
            c->UpdateControllers(kData);
    }
}
}  // namespace fnv_00a5e280

namespace fnv_00a5e5b0 {
struct ChildStub
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
    virtual void RegisterStreamables(NiStream& kStream);
};
struct BaseStub
{
    bool FUN_00a59f00(NiStream&);
};

// Calls FUN_00a59f00 on the node, then registers streamables for each of its child pointers, returning false if the base call fails.
// @fnv 0x00a5e5b0
bool __fastcall RegisterChildStreamables(NiNode* node, int, NiStream& kStream)
{
    if (!((BaseStub*)node)->FUN_00a59f00(kStream))
        return false;
    for (unsigned int i = 0; i < *(unsigned short*)((char*)node + 0xa6); i++)
    {
        ChildStub* c = (*(ChildStub***)((char*)node + 0xa0))[i];
        if (c)
            c->RegisterStreamables(kStream);
    }
    return true;
}
}  // namespace fnv_00a5e5b0

namespace fnv_00a89890 {
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct ArrStub
{
    NiRefObject* m_kPointA[7];
};

// @fnv 0x00a89890
void __fastcall ReleaseAllRefs(ArrStub* self)
{
    for (unsigned int i = 0; i < 7; i++)
    {
        if (self->m_kPointA[i])
        {
            self->m_kPointA[i]->DecRefCount();
            self->m_kPointA[i] = 0;
        }
    }
    NiRefObject** p = self->m_kPointA + 7;
    for (int j = 6; j >= 0; j--)
    {
        NiRefObject* o = *--p;
        if (o)
            o->DecRefCount();
    }
}
}  // namespace fnv_00a89890

namespace fnv_00a93ea0 {
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct NodeStub
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
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void V55();
    virtual void V56();
    virtual void V57();
    virtual void V58();
    virtual void V59();
    virtual void V60();
    virtual void SetAt(unsigned int i, NiAVObject* pkChild, NiRefObject*& spChild);
};

// Calls SetAt on the node with index i and pkChild, then decrements the ref count of the returned child if non-null.
// @fnv 0x00a93ea0
void __fastcall SetChildAt(NiNode* node, int, unsigned int uiIndex, NiAVObject* pkChild)
{
    NiRefObject* spRetainedObject = 0;
    ((NodeStub*)node)->SetAt(uiIndex, pkChild, spRetainedObject);
    if (spRetainedObject)
        spRetainedObject->DecRefCount();
}
}  // namespace fnv_00a93ea0

extern const char* DAT_011f4428;
char* __cdecl _FUN_00a7d330(const char*);
char* __cdecl NiGetViewerString(const char*, bool);

struct FUN_00a5ea70_t
{
    char pad_00[0x20];
    NiBound* m_kWorldBound;

    void FUN_00a5ad00(StrArr*);
    void NiNode_GetViewerStrings(StrArr* pkStrings);
};

// @fnv 0x00a5ea70
// src: XBOX_PDB 0x00a5ea70
void FUN_00a5ea70_t::NiNode_GetViewerStrings(StrArr* pkStrings)
{
    FUN_00a5ad00(pkStrings);
    pkStrings->AddInline(_FUN_00a7d330(DAT_011f4428));
    int bVisual = (m_kWorldBound && ((NiBound*)m_kWorldBound)->m_fRadius != 0.0f) ? 1 : 0;
    pkStrings->AddInline(NiGetViewerString("m_bVisual", bVisual != 0));
}

struct StandInPt3
{
    float x, y, z;
    StandInPt3()
    {}
    StandInPt3(float fx, float fy, float afDepth) : x(fx), y(fy), z(afDepth)
    {}
    StandInPt3 operator+(const StandInPt3& p) const
    {
        return StandInPt3(x + p.x, y + p.y, z + p.z);
    }
    StandInPt3 operator-(const StandInPt3& p) const
    {
        return StandInPt3(x - p.x, y - p.y, z - p.z);
    }
    StandInPt3 operator/(float s) const
    {
        float inv = 1.0f / s;
        return StandInPt3(x * inv, y * inv, z * inv);
    }
};

// NiMatrix3::operator*(const NiPoint3&) const, inlined here over this unit's StandInPt3.
struct NiMatrix3_StandInPt3View : public NiMatrix3
{
    StandInPt3 operator*(const StandInPt3& p) const
    {
        return StandInPt3(m_pEntry[0][0] * p.x + m_pEntry[0][1] * p.y + m_pEntry[0][2] * p.z,
                          m_pEntry[1][0] * p.x + m_pEntry[1][1] * p.y + m_pEntry[1][2] * p.z,
                          m_pEntry[2][0] * p.x + m_pEntry[2][1] * p.y + m_pEntry[2][2] * p.z);
    }
};

inline StandInPt3 operator*(const StandInPt3& p, const NiMatrix3& m)
{
    return StandInPt3(p.x * m.m_pEntry[0][0] + p.y * m.m_pEntry[1][0] + p.z * m.m_pEntry[2][0],
                      p.x * m.m_pEntry[0][1] + p.y * m.m_pEntry[1][1] + p.z * m.m_pEntry[2][1],
                      p.x * m.m_pEntry[0][2] + p.y * m.m_pEntry[1][2] + p.z * m.m_pEntry[2][2]);
}

struct StandInNode
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
    virtual void ApplyTransform(const NiMatrix3& kMat, const StandInPt3& kTrn, bool bOnLeft);
    char pad04[0x30];
    NiMatrix3 m_kOrientation;
    StandInPt3 m_kTranslation;
    float m_fScale;
    char pad68[0x38];
    StandInNode** m_children;
    unsigned short m_usCapacity;
    unsigned short m_usArraySize;
    void ApplyTransformToChildren(const NiMatrix3& kMat, const StandInPt3& kTrn, bool bOnLeft);
};

// Applies a transform to each child node, composing the matrix and translation with this node's own when bOnLeft is set.
// @fnv 0x00a5d940
void StandInNode::ApplyTransformToChildren(const NiMatrix3& kMat, const StandInPt3& kTrn, bool bOnLeft)
{
    StandInNode* pkChild;
    unsigned int i;
    if (bOnLeft)
    {
        NiMatrix3 kM1 = m_kOrientation.TransposeTimes(kMat * m_kOrientation);
        StandInPt3 kT1 = (((const NiMatrix3_StandInPt3View&)kMat * m_kTranslation + kTrn - m_kTranslation) * m_kOrientation) / m_fScale;
        for (i = 0; i < m_usArraySize; i++)
        {
            pkChild = m_children[i];
            if (pkChild)
                pkChild->ApplyTransform(kM1, kT1, true);
        }
    }
    else
    {
        for (i = 0; i < m_usArraySize; i++)
        {
            pkChild = m_children[i];
            if (pkChild)
                pkChild->ApplyTransform(kMat, kTrn, true);
        }
    }
}

__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct ChildNode;

struct ChildObj
{
    virtual void V00();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ChildNode* m_pParentNode;
    void SetParentNode(ChildNode* pkParent);
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

struct NodeChildArray
{
    int unk00;
    ChildObj** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, ChildObj* const& element);
    void SetAtGrow(unsigned int uiIndex, ChildObj* const& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
    }
};

struct ChildNode
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
    NodeChildArray m_kChildList;
    void NiNode_SetAt(unsigned int i, ChildObj* pkChild, ChildObj*& spOld);
};

// @fnv 0x00a5ee30
// src: XBOX_PDB 0x00a5ee30
void ChildNode::NiNode_SetAt(unsigned int i, ChildObj* pkChild, ChildObj*& spOld)
{
    if (m_kChildList.m_usSize <= i)
    {
        if (pkChild)
            pkChild->SetParentNode(this);
        ChildObj* spChild = pkChild;
        if (pkChild)
            pkChild->IncRefCount();
        m_kChildList.SetAtGrow(i, spChild);
        if (pkChild)
            pkChild->DecRefCount();
        if (spOld)
        {
            spOld->DecRefCount();
            spOld = 0;
        }
    }
    else
    {
        ChildObj* pChild = m_kChildList.m_pBase[i];
        if (pChild)
        {
            pChild->IncRefCount();
            pChild->m_pParentNode = 0;
        }
        if (pkChild)
            pkChild->SetParentNode(this);
        {
            ChildObj* spChild = pkChild;
            if (pkChild)
                pkChild->IncRefCount();
            m_kChildList.SetAt(i, spChild);
            if (pkChild)
                pkChild->DecRefCount();
        }
        if (spOld != pChild)
        {
            if (spOld)
                spOld->DecRefCount();
            spOld = pChild;
            if (pChild)
                pChild->IncRefCount();
        }
        if (pChild)
            pChild->DecRefCount();
    }
}

// 0x0060bef0 is SetSize for NiTArray<NiPointer<NiAVObject>, NiTNewInterface<...>>;
// the former empty NiObjectA5E was the child object's reference-count interface.
__declspec(nothrow) inline void NiAVObject::IncRefCount()
{
    NiRefObject::IncRefCount();
}
__declspec(nothrow) __forceinline void NiAVObject::DecRefCount()
{
    NiRefObject::DecRefCount();
}

template <class T> __declspec(nothrow) inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> __declspec(nothrow) inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> __declspec(nothrow) inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& ptr)
{
    if (m_pObject != ptr.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = ptr.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T> __declspec(nothrow) inline NiPointer<T>::NiPointer(const NiPointer& ptr) : m_pObject(ptr.m_pObject)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T, class TAlloc>
__declspec(nothrow) __declspec(noinline) void NiTArray<T, TAlloc>::SetAt(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element.m_pObject)
            m_usESize++;
    }
    else if (element.m_pObject)
    {
        if (!m_pBase[uiIndex].m_pObject)
            m_usESize++;
    }
    else if (m_pBase[uiIndex].m_pObject)
    {
        m_usESize--;
    }
    m_pBase[uiIndex] = element;
}

template <class T, class TAlloc>
__declspec(nothrow) inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}

// Compare shared smart pointers without requiring a member operator== declaration.
template <class T> inline bool EqualObjectPointers(const NiPointer<T>& left, const NiPointer<T>& right)
{
    return left.m_pObject == right.m_pObject;
}

// The shared array has no InsertAt declaration; keep its implementation as a free function.
// Inserts a non-null element at uiIndex, shifting existing entries up by one and returning the index, or ~0 if the element is null.
// @fnv 0x00a5ebe0
unsigned int __fastcall InsertObjectArrayAt(
    NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >* array, int,
    unsigned int uiIndex, const NiPointer<NiAVObject>& element)
{
    if (EqualObjectPointers(element, NiPointer<NiAVObject>(0)))
        return (unsigned int)~0;

    unsigned int uiSize = array->m_usSize;
    for (unsigned int i = uiSize; i > uiIndex; i--)
    {
        NiPointer<NiAVObject> spElement = array->m_pBase[i - 1];
        if (i == uiSize)
            array->SetAtGrow(i, spElement);
        else
            array->SetAt(i, spElement);
    }

    array->SetAtGrow(uiIndex, element);
    return uiIndex;
}

class FUN_00a5edc0_sub
{
  public:
    void FUN_00a5ebe0(NiRefObject* a1, NiRefObject** slot);
};

class FUN_00a5edc0_cls
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
    FUN_00a5edc0_sub m_sub;

    void SetParent(void* owner);
    void NiNode_InsertChildAt(NiRefObject* a1, NiRefObject* a2);
};

// @fnv 0x00a5edc0
// src: XBOX_PDB 0x00a5edc0
void FUN_00a5edc0_cls::NiNode_InsertChildAt(NiRefObject* apArg, NiRefObject* apRefObject)
{
    if (apRefObject)
    {
        long(__stdcall * pfnIncRef)(volatile long*) = InterlockedIncrement;
        long(__stdcall * pfnDecRef)(volatile long*) = InterlockedDecrement;
        volatile long* rc = (volatile long*)&apRefObject->m_uiRefCount;
        pfnIncRef(rc);
        ((NiAVObject*)apRefObject)->AssignParent((NiNode*)this);
        NiRefObject* pRefObject = apRefObject;
        pfnIncRef(rc);
        m_sub.FUN_00a5ebe0(apArg, &pRefObject);
        if (pfnDecRef(rc) == 0)
        {
            apRefObject->DeleteThis();
        }
        if (pfnDecRef(rc) == 0)
        {
            apRefObject->DeleteThis();
        }
    }
}

class BA5EFA0CloningProcess;

void** BA5EFA0Allocate(unsigned int) throw();
typedef NiTArray<void*, NiTMallocInterface<void*> > BA5EFA0ChildArray;
template <> __forceinline NiTArray<void*, NiTMallocInterface<void*> >::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = BA5EFA0Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }

class BA5EFA0ObjectArray : public BA5EFA0ChildArray
{
  public:
    __forceinline BA5EFA0ObjectArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : BA5EFA0ChildArray(uiMaxSize, uiGrowBy)
    {}
    virtual ~BA5EFA0ObjectArray();
};

class BA5EFA0AVObject
{
  public:
    static void* operator new(unsigned int uiSize);

    BA5EFA0AVObject() throw();
    virtual ~BA5EFA0AVObject();

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
};

class BA5EFA0Node : public BA5EFA0AVObject
{
  public:
    __forceinline BA5EFA0Node()
    {}
    virtual ~BA5EFA0Node();

    void CopyMemberData(BA5EFA0Node* pkDest, BA5EFA0CloningProcess& kCloning);
    BA5EFA0Node* NiNode_CreateClone(BA5EFA0CloningProcess& kCloning);

    BA5EFA0ObjectArray m_kChildList;
};

// @fnv 0x00a5efa0
// src: XBOX_PDB 0x00a5efa0
BA5EFA0Node* BA5EFA0Node::NiNode_CreateClone(BA5EFA0CloningProcess& kCloning)
{
    BA5EFA0Node* pkClone = new BA5EFA0Node;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

namespace e2 {

struct Bnd
{
    NiPoint3 c;
    float r;
    void NiBound_Merge(const Bnd* b);
    void Set(const NiPoint3& cc, float rr)
    {
        c = cc;
        r = rr;
    }
};
extern Bnd DAT_011f4288;
struct AV
{
    char pad[0x20];
    Bnd* m_pWorldBound;
    char padCur[0x30 - 0x24];
    unsigned int m_uFlags;
    unsigned char F13() const
    {
        return (m_uFlags >> 13) & 1;
    }
    unsigned char F19() const
    {
        return (m_uFlags >> 19) & 1;
    }
    const Bnd& GetWB() const
    {
        return m_pWorldBound ? *m_pWorldBound : DAT_011f4288;
    }
};
}
using namespace e2;
class Node2 : public AV
{
  public:
    char kad[0xa0 - 0x34];
    AV** m_pBase;
    unsigned short m_usMax;
    unsigned short m_usSize;
    void FUN_005467e0();
    void UpdateWorldBoundFromChildren();
};
// @fnv 0x00a5e2d0
void Node2::UpdateWorldBoundFromChildren()
{
    if (!F13() && F19())
    {
        unsigned int count = m_usSize;
        unsigned int i = 0;
        while (i < count)
        {
            AV* c = m_pBase[i];
            if (c && c->m_pWorldBound && c->m_pWorldBound->r != 0.0f)
            {
                FUN_005467e0();
                const Bnd& b = c->GetWB();
                m_pWorldBound->Set(b.c, b.r);
                i++;
                while (i < count)
                {
                    AV* pOtherChild = m_pBase[i];
                    if (pOtherChild && pOtherChild->m_pWorldBound && pOtherChild->m_pWorldBound->r != 0.0f)
                        m_pWorldBound->NiBound_Merge(pOtherChild->m_pWorldBound);
                    i++;
                }
            }
            else
                i++;
        }
    }
}

struct S_00a5eb20_Obj
{
    virtual void unk_dtor() throw();
    virtual void DeleteThis() throw();
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
struct S_00a5eb20_Ptr
{
    S_00a5eb20_Obj* m_p;
    S_00a5eb20_Ptr(S_00a5eb20_Obj* p) throw() : m_p(p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    ~S_00a5eb20_Ptr() throw()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    S_00a5eb20_Ptr& operator=(const S_00a5eb20_Ptr& o) throw()
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = o.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
    bool operator==(const S_00a5eb20_Ptr& o) const throw()
    {
        return m_p == o.m_p;
    }
};
struct S_00a5eb20_Arr
{
    int unk00;
    S_00a5eb20_Ptr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usESize;
    unsigned short m_usElementCount;
    unsigned short m_usGrowBy;
    void FUN_0060bef0(unsigned int n);
    void FUN_004b0310(unsigned int i, const S_00a5eb20_Ptr& e);
    unsigned int NiTArray_NiPointer_NiAVObject_NiTNewInterface_NiPointer_NiAVObject_AddFirstEmpty(const S_00a5eb20_Ptr& e);
};
// Adds a ref-counted pointer to the array: reuses the first null slot or appends, growing the array if needed, and returns its index or -1 for a null pointer.
// @fnv 0x00a5eb20
// src: XBOX_PDB 0x00a5eb20
unsigned int S_00a5eb20_Arr::NiTArray_NiPointer_NiAVObject_NiTNewInterface_NiPointer_NiAVObject_AddFirstEmpty(const S_00a5eb20_Ptr& e)
{
    if (e == S_00a5eb20_Ptr(0))
        return (unsigned int)-1;
    for (unsigned short i = 0; i < m_usESize; ++i)
    {
        if (m_pBase[i] == S_00a5eb20_Ptr(0))
        {
            m_pBase[i] = e;
            ++m_usElementCount;
            return i;
        }
    }
    unsigned int index = m_usESize;
    if (index >= m_usMaxSize)
        FUN_0060bef0(m_usGrowBy + index);
    FUN_004b0310(index, e);
    return index;
}

struct NiEqAVObject
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
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual bool IsEqual(NiAVObject* pkObject);
};
struct NiNodeEq : NiNode
{
    bool FUN_00a5a260(NiAVObject* pkObject);
    bool NiNode_IsEqual(NiAVObject* pkObject);
};
// @fnv 0x00a5e600
// src: XBOX_PDB 0x00a5e600
bool NiNodeEq::NiNode_IsEqual(NiAVObject* pkObject)
{
    if (!FUN_00a5a260(pkObject))
        return false;

    NiNodeEq* pkNode = (NiNodeEq*)pkObject;

    unsigned int uiChildCount = m_kChildren.m_usSize;
    unsigned int uiOtherChildCount = pkNode->m_kChildren.m_usSize;
    if (uiChildCount != uiOtherChildCount)
        return false;

    for (unsigned int i = 0; i < uiChildCount; i++)
    {
        NiAVObject* pkChild0 = m_kChildren.m_pBase[i].m_pObject;
        NiAVObject* pkChild1 = pkNode->m_kChildren.m_pBase[i].m_pObject;
        if ((pkChild0 && !pkChild1) || (!pkChild0 && pkChild1))
            return false;

        if (pkChild0 && !((NiEqAVObject*)pkChild0)->IsEqual(pkChild1))
            return false;
    }

    return true;
}

class FUN_00a59dc0_shell
{
  public:
    void SetBoundObject(void*);
    void NiGeometry_SetBound(void*);
};

// @fnv 0x00a7fdb0
// src: XBOX_PDB 0x00a7fdb0
void FUN_00a59dc0_shell::NiGeometry_SetBound(void* pValue)
{
    SetBoundObject(pValue);
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
                                                 unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesWritten;
    return uiBytesWritten;
}

template <class T> inline void SaveStreamValue(NiBinaryStream& kStream, const T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&kValue, sizeof(T), &uiSize, 1);
}

class NodeA5E8
{
  public:
    int unk000[0xa0 / 4];
    NiObject** m_ppkChildren;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;

    void FUN_00a5a900(NiStream& kStream);
    void NiNode_SaveBinary(NiStream& kStream);
};

// Saves the node's size, child link IDs, and a terminating zero to the stream after calling the base save routine.
// @fnv 0x00a5e880
// src: XBOX_PDB 0x00a5e880
void NodeA5E8::NiNode_SaveBinary(NiStream& kStream)
{
    FUN_00a5a900(kStream);
    unsigned int ItemUpdateArray = m_usSize;
    SaveStreamValue(*kStream.GetBinaryStream(), ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        kStream.SaveLinkID(m_ppkChildren[i]);
    unsigned int uiZero = 0;
    SaveStreamValue(*kStream.GetBinaryStream(), uiZero);
}

struct SUNode
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
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void SetSelectiveUpdateFlags(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms, bool& bRigid);
    int unk04;
    int unk08;
    void* unk0C;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int m_uFlags;
    bool FUN_00a5a0e0();
    bool HasNodeWithNonZeroValue();
    void NiNode_SetSelectiveUpdateFlags(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms, bool& bRigid);
    bool GetSelectiveUpdateTransformsOverride() const
    {
        return (m_uFlags >> 7) & 1;
    }
    void SetSelectiveUpdate(bool b)
    {
        if (b)
            m_uFlags |= 2;
        else
            m_uFlags &= ~2;
    }
    void SetSelectiveUpdateTransforms(bool b)
    {
        if (b)
            m_uFlags |= 4;
        else
            m_uFlags &= ~4;
    }
    void SetSelectiveUpdatePropertyControllers(bool b)
    {
        if (b)
            m_uFlags |= 8;
        else
            m_uFlags &= ~8;
    }
    void SetSelectiveUpdateRigid(bool b)
    {
        if (b)
            m_uFlags |= 0x10;
        else
            m_uFlags &= ~0x10;
    }
    unsigned short GetSize();
};
struct SUArray
{
    void* vt;
    SUNode** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};

// Computes selective update flags from this node and child results, then stores them in this node's flag word.
// @fnv 0x00a5e440
// src: XBOX_PDB 0x00a5e440
void SUNode::NiNode_SetSelectiveUpdateFlags(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms, bool& bRigid)
{
    bool bTransformControllers = FUN_00a5a0e0();
    if (!bSelectiveUpdateTransforms)
        bSelectiveUpdateTransforms = bTransformControllers || GetSelectiveUpdateTransformsOverride();
    bSelectiveUpdate = bSelectiveUpdateTransforms;
    bRigid = true;
    SUArray& kChildren = *(SUArray*)((char*)this + 0x9c);
    for (unsigned int i = 0; i < kChildren.m_usSize; i++)
    {
        SUNode* pkChild = kChildren.m_pBase[i];
        if (pkChild)
        {
            bool bChildSelectiveUpdate = false;
            bool bChildRigid = true;
            pkChild->SetSelectiveUpdateFlags(bChildSelectiveUpdate, bSelectiveUpdateTransforms, bChildRigid);
            if (bChildSelectiveUpdate)
                bSelectiveUpdate = true;
            if (!bChildRigid)
                bRigid = false;
        }
    }
    bool bPropertyControllers = HasNodeWithNonZeroValue();
    if (bPropertyControllers || unk0C)
    {
        bSelectiveUpdate = true;
    }
    SetSelectiveUpdate(bSelectiveUpdate);
    SetSelectiveUpdateTransforms(bSelectiveUpdateTransforms);
    SetSelectiveUpdatePropertyControllers(bPropertyControllers);
    SetSelectiveUpdateRigid(bRigid);
    if (bTransformControllers)
        bRigid = false;
}

namespace fnv_00a5e690 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* p);

struct NiRefA
{
    virtual void V0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    unsigned int m_unk08;
    unsigned int m_unk0C;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_i18;
};

struct S00a5e690_sub
{
    unsigned int m_u00;
    void __declspec(noinline) FUN_00869260(NiRefA*& out, unsigned int index);
};

struct S00a5e690_Obj
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
    S00a5e690_sub m_sub;
    NiRefA** m_children;
    unsigned short m_unkA4;
    unsigned short m_usEffectiveSize;

    void GetChild(unsigned int index, NiRefA** out);
};

void S00a5e690_sub::FUN_00869260(NiRefA*& out, unsigned int index)
{
    out = reinterpret_cast<NiRefA*>(index);
}

// Returns the child at index via out, releasing the previous value and any temporary reference.
// @fnv 0x00a5e690
void S00a5e690_Obj::GetChild(unsigned int index, NiRefA** out)
{
    if (index < m_usEffectiveSize)
    {
        unsigned int iIndex = index;
        NiRefA* n = m_children[iIndex];
        long(__stdcall * incFn)(volatile long*) = InterlockedIncrement;
        if (n != 0)
        {
            incFn(&n->m_uiRefCount);
            n->m_i18 = 0;
            NiRefA*& slot = reinterpret_cast<NiRefA*&>(index);
            m_sub.FUN_00869260(slot, iIndex);
            NiRefA* r = slot;
            if (r != 0)
            {
                if (InterlockedDecrement(&r->m_uiRefCount) == 0)
                    r->DeleteThis();
            }
        }
        NiRefA* old = *out;
        if (old != n)
        {
            if (old != 0)
            {
                if (InterlockedDecrement(&old->m_uiRefCount) == 0)
                    old->DeleteThis();
            }
            *out = n;
            if (n != 0)
                incFn(&n->m_uiRefCount);
        }
        if (n != 0)
        {
            if (InterlockedDecrement(&n->m_uiRefCount) == 0)
                n->DeleteThis();
        }
    }
    else
    {
        NiRefA* old = *out;
        if (old != 0)
        {
            if (InterlockedDecrement(&old->m_uiRefCount) == 0)
                old->DeleteThis();
            *out = 0;
        }
    }
}
}  // namespace fnv_00a5e690

namespace fnv_00a5e780 {
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefObj
{
    virtual void V00() throw();
    virtual void DeleteThis() throw();
    volatile long m_uiRefCount;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    void* m_pParentNode;
    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};
struct RefPtr
{
    RefObj* m_pObject;
    RefPtr(RefObj* p = 0) throw()
    {
        m_pObject = p;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    RefPtr(const RefPtr& p) throw()
    {
        m_pObject = p.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~RefPtr() throw()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    RefPtr& operator=(RefObj* p) throw()
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
    RefPtr& operator=(const RefPtr& p) throw()
    {
        if (m_pObject != p.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = p.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    operator RefObj*() const throw()
    {
        return m_pObject;
    }
    RefObj* operator->() const throw()
    {
        return m_pObject;
    }
};
struct RawPtr
{
    RefObj* m_p;
    RawPtr(const RawPtr& o) throw() : m_p(o.m_p)
    {}
    ~RawPtr() throw()
    {
        RefObj* p = *(RefObj* volatile*)&m_p;
        if (p)
            p->DecRefCount();
    }
};
struct ChildArray
{
    unsigned int unk00;
    RefObj** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usEffSize;
    unsigned short m_usGrowBy;
    unsigned int GetSize() const throw()
    {
        return m_usSize;
    }
    RefObj* GetAt(unsigned int i) const throw()
    {
        return m_pBase[i];
    }
    RawPtr FUN_00869260(unsigned int i) throw();
};
struct NodeStandIn
{
    virtual void V00();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    unsigned int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    unsigned int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    unsigned int unk84, unk88, unk8c, unk90, unk94, unk98;
    ChildArray m_kChildList;
    void NiNode_DetachChild_00a5e780(RefObj* pkChild, RefPtr& pChild);
};
// @fnv 0x00a5e780
// src: XBOX_PDB 0x00a5e780
void NodeStandIn::NiNode_DetachChild_00a5e780(RefObj* pkChild, RefPtr& spRemovedChild)
{
    for (unsigned int i = 0; i < m_kChildList.GetSize(); i++)
    {
        RefPtr spChild = m_kChildList.GetAt(i);
        if (spChild && spChild == pkChild)
        {
            spChild->m_pParentNode = 0;
            m_kChildList.FUN_00869260(i);
            spRemovedChild = spChild;
            return;
        }
    }
    spRemovedChild = 0;
}
}  // namespace fnv_00a5e780

namespace sa5e9d0 {

struct Object;



struct ObjectArray
{
    void FUN_0060bef0(unsigned int uiSize);
};

class Node
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
    virtual void SetAt(unsigned int uiIndex, Object* pkObject);

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
    ObjectArray m_kChildList;

    void ReadFromStream(NiStream* pkStream);
    void ReadChildListFromStream(NiStream* pkStream);
};

// Reads the child object count and objects from pkStream, then reads and discards uiEffects objects based on m_uiFileVersion.
// @fnv 0x00a5e9d0
void Node::ReadChildListFromStream(NiStream* pkStream)
{
    ReadFromStream(pkStream);
    unsigned int ItemUpdateArray = pkStream->GetLinkID();
    if (ItemUpdateArray)
    {
        m_kChildList.FUN_0060bef0(ItemUpdateArray);
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            Object* pkChild = reinterpret_cast<Object*>(pkStream->GetLoadedObject());
            SetAt(i, pkChild);
        }
    }
    unsigned int uiEffects = pkStream->GetLinkID();
    if (pkStream->GetFileVersion() < 0x4010008)
    {
        while (uiEffects--)
            pkStream->GetLoadedObject();
    }
    else
    {
        while (uiEffects--)
            pkStream->GetLoadedObject();
    }
}

}

namespace fnv_00a5ed10 {
struct HeldChild;
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct ChildNode;

struct ChildObj
{
    virtual void V00() throw();
    virtual void DeleteThis() throw();
    volatile long m_uiRefCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ChildNode* m_pParentNode;
    void SetParent(ChildNode* pkParent) throw();
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

struct ChildArray
{
    int unk00;
    ChildObj** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0060bef0(unsigned int uiSize) throw();
    void FUN_004b0310(unsigned int uiIndex, const HeldChild& element) throw();
    void NiTArray_NiPointer_NiAVObject_NiTNewInterface_NiPointer_NiAVObject_AddFirstEmpty(const HeldChild& element) throw();
    void Add(const HeldChild& element) throw()
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            FUN_0060bef0(uiIndex + m_usGrowBy);
        FUN_004b0310(uiIndex, element);
    }
};

struct ChildNode
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
    ChildArray m_kChildList;
    void NiNode_AttachChild(ChildObj* pkChild, bool firstAvailable) throw();
};

struct HeldChild
{
    ChildObj* object;
    HeldChild(ChildObj* p) throw() : object(p)
    {
        if (p)
            p->IncRefCount();
    }
    HeldChild(const HeldChild& other) throw() : object(other.object)
    {
        if (object)
            object->IncRefCount();
    }
    ~HeldChild() throw()
    {
        if (object)
            object->DecRefCount();
    }
    operator ChildObj*() const
    {
        return object;
    }
};

__declspec(noinline) void ChildArray::FUN_004b0310(unsigned int uiIndex, const HeldChild& element) throw()
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element.object)
            ++m_usESize;
    }
    else
    {
        if (element.object && !m_pBase[uiIndex])
            ++m_usESize;
        if (!element.object && m_pBase[uiIndex])
            --m_usESize;
    }
    ChildObj* previous = m_pBase[uiIndex];
    if (previous != element.object)
    {
        if (previous)
            previous->DecRefCount();
        m_pBase[uiIndex] = element.object;
        if (element.object)
            element.object->IncRefCount();
    }
}
// src: XBOX_PDB 0x00a5eb20
__declspec(noinline) void ChildArray::NiTArray_NiPointer_NiAVObject_NiTNewInterface_NiPointer_NiAVObject_AddFirstEmpty(const HeldChild& element) throw()
{
    if (!element.object)
        return;
    for (unsigned short i = 0; i < m_usSize; ++i)
    {
        if (!m_pBase[i])
        {
            ChildObj* previous = m_pBase[i];
            if (previous != element.object)
            {
                if (previous)
                    previous->DecRefCount();
                m_pBase[i] = element.object;
                if (element.object)
                    element.object->IncRefCount();
            }
            ++m_usESize;
            return;
        }
    }
    Add(element);
}

// Adds pkChild to m_kChildList, placing it in the first available slot if firstAvailable is true, otherwise appending it.
// @fnv 0x00a5ed10
// src: XBOX_PDB 0x00a5ed10
void ChildNode::NiNode_AttachChild(ChildObj* pkChild, bool firstAvailable)
{
    if (pkChild)
    {
        pkChild->IncRefCount();
        pkChild->SetParent(this);
        if (firstAvailable)
        {
            m_kChildList.NiTArray_NiPointer_NiAVObject_NiTNewInterface_NiPointer_NiAVObject_AddFirstEmpty(pkChild);
        }
        else
        {
            m_kChildList.Add(pkChild);
        }
        pkChild->DecRefCount();
    }
}
}  // namespace fnv_00a5ed10
