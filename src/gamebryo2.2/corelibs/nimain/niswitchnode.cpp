#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiSwitchNode.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiBound.h"


// src/gamebryo2.2/corelibs/nimain/niswitchnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niswitchnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern char const* const g_011f5f1c_arg1;

// @fnv 0x00a943f0
// src: COMMUNITY 0x00a943f0
char const* const* __cdecl NiSwitchNode_GetNiRTTI()
{
    return &g_011f5f1c_arg1;
}


// Switch-specific trailing state and undeclared helper methods remain local.
// Calls FUN_00a5e600, then returns true only if m_0b0 matches and the low bit of m_0ac matches the other object's.
// @fnv 0x00a94000
// src: XBOX_PDB 0x00a94000
bool __thiscall NiSwitchNode::IsEqual_00a94000(NiObject* other)
{
    if (!NiNode_IsEqual(other) || m_0b0 != static_cast<NiSwitchNode*>(other)->m_0b0 || (m_0ac ^ static_cast<NiSwitchNode*>(other)->m_0ac) & 1)
        return false;
    return true;
}

extern unsigned char DAT_011f4380;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

// Locks DAT_011f4380, deletes the extra data at index a1 if it is below the count at offset 0x14, and returns whether it was removed.
// @fnv 0x00a5bf50
// src: COMMUNITY 0x00a5bf50
bool __thiscall NiObjectNET::RemoveExtraDataAt(unsigned short ausIndex)
{
    EnterCriticalSection(&DAT_011f4380);
    if (ausIndex < m_usExtraDataSize)
    {
        DeleteExtraData(ausIndex);
        LeaveCriticalSection(&DAT_011f4380);
        return true;
    }
    LeaveCriticalSection(&DAT_011f4380);
    return false;
}

struct FUN_00a93c00_shell : NiSwitchNode
{
    void __thiscall NiSwitchNode_CopyMembers(NiSwitchNode*, CloningProcess&);
};
// @fnv 0x00a93c00
// src: COMMUNITY 0x00a93c00
void __thiscall FUN_00a93c00_shell::NiSwitchNode_CopyMembers(NiSwitchNode* pkDest, CloningProcess& kCloning)
{
    NiNode::CopyMemberData(pkDest, kCloning);
    pkDest->m_usFlags = m_usFlags;
    pkDest->m_0b0 = m_0b0;
}

struct NiNodeHack
{
    void UpdateChildControllers(NiUpdateData&);
};
struct SwitchHack : public NiSwitchNode
{
    void NiSwitchNode_UpdateControllers(NiUpdateData&);
};
// @fnv 0x00a94300
// src: XBOX_PDB 0x00a94300
void SwitchHack::NiSwitchNode_UpdateControllers(NiUpdateData& data)
{
    if (m_0ac & 1)
    {
        if (m_iIndex >= 0)
        {
            ((NiAVObject*)this)->UpdateTimeControllers(data, true);
            NiAVObject* pkChild = ((NiAVObject**)m_kChildren.m_pBase)[m_iIndex];
            if (pkChild)
                pkChild->UpdateControllers(data);
        }
    }
    else
    {
        ((NiNodeHack*)this)->UpdateChildControllers(data);
    }
}

namespace fnv_00a94500 {

struct NiSwitchNode_Helper
{
    NiSwitchNode* __thiscall FUN_00a94360();
};
struct FUN_00a94500_Holder : NiSwitchNode
{
    NiObject* __thiscall CloneSwitchNode(CloningProcess&);
};
// @fnv 0x00a94500
NiObject* __thiscall FUN_00a94500_Holder::CloneSwitchNode(CloningProcess& kCloning)
{
    NiSwitchNode* pkObject;
    void* pMemory = BSFadeNode::operator new(0xCC);
    if (pMemory)
        pkObject = ((NiSwitchNode_Helper*)pMemory)->FUN_00a94360();
    else
        pkObject = 0;
    NiNode::CopyMemberData(pkObject, kCloning);
    pkObject->m_usFlags = m_usFlags;
    pkObject->m_iIndex = m_iIndex;
    return pkObject;
}
}  // namespace fnv_00a94500

struct FUN_00a944a0_shell : public NiSwitchNode
{
    void __thiscall SetChildAtIndex(unsigned int, NiAVObject*, NiPointer<NiAVObject>&);
};
// @fnv 0x00a944a0
void FUN_00a944a0_shell::SetChildAtIndex(unsigned int uiIndex, NiAVObject* pkChild, NiPointer<NiAVObject>& spobject)
{
    NiTPrimitiveArray<unsigned int>* arr = &m_kChildRevID;
    m_uiRevID = 1;
    unsigned int p = 0;
    if (uiIndex >= arr->m_usMaxSize)
        arr->SetSize(arr->m_usGrowBy + uiIndex);
    arr->SetAt(uiIndex, p);
    NiNode::SetAtAlt(uiIndex, pkChild, spobject);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

template <> __declspec(nothrow) inline NiPointer<NiRefObject>::NiPointer() : m_pObject(0)
{
}

template <> __declspec(nothrow) inline NiPointer<NiRefObject>& NiPointer<NiRefObject>::operator=(const NiPointer<NiRefObject>& other)
{
    NiRefObject* old = m_pObject;
    if (old != other.m_pObject)
    {
        if (old && !InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)))
            old->DeleteThis();
        m_pObject = other.m_pObject;
        if (m_pObject)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&m_pObject->m_uiRefCount));
    }
    return *this;
}

template <> __declspec(nothrow) inline NiPointer<NiRefObject>::~NiPointer()
{
    if (m_pObject)
    {
        NiRefObject* old = m_pObject;
        if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)))
            old->DeleteThis();
    }
}
struct S2
{
    void __thiscall NiNode_DetachChild_00a5e780(NiRefObject*, NiPointer<NiRefObject>&) throw();
};
struct Target : NiSwitchNode
{
    void __thiscall NiSwitchNode_DetachChild(NiRefObject*, NiPointer<NiRefObject>&);
};
// @fnv 0x00a93ca0
// src: XBOX_PDB 0x00a93ca0
void Target::NiSwitchNode_DetachChild(NiRefObject* child, NiPointer<NiRefObject>& out)
{
    m_uiRevID = 1;
    unsigned int uiIndex = 0;
    while (uiIndex < m_kChildren.m_usSize)
    {
        if (child == ((NiRefObject**)m_kChildren.m_pBase)[uiIndex])
        {
            if (uiIndex < m_kChildRevID.m_usSize)
            {
                unsigned int old = m_kChildRevID.m_pBase[uiIndex];
                m_kChildRevID.m_pBase[uiIndex] = 0;
                if (old)
                    --m_kChildRevID.m_usESize;
                if (uiIndex == (unsigned int)(unsigned short)(m_kChildRevID.m_usSize - 1))
                    --m_kChildRevID.m_usSize;
            }
            break;
        }
        ++uiIndex;
    }
    NiPointer<NiRefObject> refTemp;
    ((S2*)this)->NiNode_DetachChild_00a5e780(child, refTemp);
    int active = m_iIndex;
    if (active > -1 && (active >= (int)m_kChildren.m_usSize || !((NiRefObject**)m_kChildren.m_pBase)[active]))
        m_iIndex = -1;
    out = refTemp;
}

__declspec(nothrow) inline void IncChildRefCount(NiAVObject* object)
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount));
}

__declspec(nothrow) inline void DecChildRefCount(NiAVObject* object)
{
    if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)))
        object->DeleteThis();
}

template <> __declspec(nothrow) inline NiPointer<NiAVObject>::NiPointer() : m_pObject(0)
{
}

template <> __declspec(nothrow) inline NiPointer<NiAVObject>::~NiPointer()
{
    if (m_pObject)
        DecChildRefCount(m_pObject);
}

template <> __declspec(nothrow) inline NiPointer<NiAVObject>& NiPointer<NiAVObject>::operator=(const NiPointer<NiAVObject>& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject)
            DecChildRefCount(m_pObject);
        m_pObject = other.m_pObject;
        if (m_pObject)
            IncChildRefCount(m_pObject);
    }
    return *this;
}

namespace fnv_00a93dd0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plValue);

struct A93DD0Node : NiSwitchNode
{
    void DetachChildInternal(unsigned int uiIndex, NiPointer<NiAVObject>& spChild) throw();
    void RemoveChild(unsigned int uiIndex, NiPointer<NiAVObject>& spChild);
};

// @fnv 0x00a93dd0
void A93DD0Node::RemoveChild(unsigned int uiIndex, NiPointer<NiAVObject>& spChildOut)
{
    m_uiRevID = 1;
    if (uiIndex < m_kChildren.m_usSize)
        m_kChildRevID.RemoveAt(uiIndex);

    NiPointer<NiAVObject> spChild;
    DetachChildInternal(uiIndex, spChild);

    if (m_iIndex > -1 && (m_iIndex >= m_kChildren.m_usSize || !reinterpret_cast<NiAVObject**>(m_kChildren.m_pBase)[m_iIndex]))
        m_iIndex = -1;

    spChildOut = spChild;
}
}  // namespace fnv_00a93dd0

struct SwitchChildB10050 : NiAVObject
{
    void __thiscall FUN_00a59e00(unsigned int);
};

struct SwitchOutB10050
{
    float m_00;
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    unsigned char m_08;
};

struct FUN_00a93ef0_cls : public NiSwitchNode
{
    void __thiscall UpdateSwitchChild(unsigned int arg);
};

// @fnv 0x00a93ef0
void __thiscall FUN_00a93ef0_cls::UpdateSwitchChild(unsigned int arg)
{
    int idx = m_iIndex;
    if (idx >= 0)
    {
        SwitchChildB10050* child = (SwitchChildB10050*)((void**)m_kChildren.m_pBase)[idx];
        if (child != 0)
        {
            SwitchOutB10050 block;
            if (m_kChildRevID.m_pBase[idx] != m_uiRevID)
            {
                m_kChildRevID.SetAt((unsigned int)idx, m_uiRevID);
                block.m_00 = m_fSavedTime;
                block.m_04 = (unsigned char)(((unsigned char)m_0ac >> 1) & 1);
                block.m_05 = 0;
                block.m_06 = 0;
                block.m_07 = 0;
                block.m_08 = 0;
                child->UpdateDownwardPass(*reinterpret_cast<NiUpdateData*>(&block), 0);
            }
            child->FUN_00a59e00(arg);
        }
    }
}

// 0x00a93f90 copies NiAVObject::m_kWorldBound (center at 0, radius at 12), a NiBound rather than a Vec4.
extern NiBound g_default_011f4288;

struct FUN_00a93f90_cls : public NiSwitchNode
{
    void UpdateFromActiveChild();
    void UpdateWorldBoundFromChildren();
};

// If the switch flag is set, copies the active child's m_kWorldBound vector into m_kWorldBound (or zeroes w when there is no child); otherwise calls UpdateWorldBoundFromChildren.
// @fnv 0x00a93f90
void FUN_00a93f90_cls::UpdateFromActiveChild()
{
    if ((m_0ac & 1) != 0)
    {
        int idx = m_iIndex;
        NiAVObject* child = 0;
        if (idx >= 0)
            child = (NiAVObject*)((void**)m_kChildren.m_pBase)[idx];
        if (child != 0)
        {
            void* p = child->m_kWorldBound;
            NiBound* src = p != 0 ? static_cast<NiBound*>(p) : &g_default_011f4288;
            NiBound* dst = reinterpret_cast<NiBound*>(m_kWorldBound);
            float radius = src->m_fRadius;
            reinterpret_cast<unsigned int&>(dst->m_kCenter.x) = reinterpret_cast<unsigned int&>(src->m_kCenter.x);
            reinterpret_cast<unsigned int&>(dst->m_kCenter.y) = reinterpret_cast<unsigned int&>(src->m_kCenter.y);
            reinterpret_cast<unsigned int&>(dst->m_kCenter.z) = reinterpret_cast<unsigned int&>(src->m_kCenter.z);
            dst->m_fRadius = radius;
            return;
        }
        reinterpret_cast<NiBound*>(m_kWorldBound)->m_fRadius = 0.0f;
        return;
    }
    UpdateWorldBoundFromChildren();
}

struct FNV_UpdateFlags
{
    float time;
    unsigned char shouldActivate;
};
struct FNV_Color4
{
    unsigned int first, second, third;
    float fourth;
};
extern FNV_Color4 DAT_011f4288;
extern "C" void __stdcall FUN_004eff50(FNV_UpdateFlags*, unsigned int);


struct FUN_00a94040_shell : NiSwitchNode
{
    void FUN_00a5dd70(FNV_UpdateFlags*, unsigned int);
    void UpdateSwitchState(FNV_UpdateFlags*, unsigned int);
};
// Updates the switch node's active state and time, notifies the selected child, and copies its color, or delegates to FUN_00a5dd70 when inactive.
// @fnv 0x00a94040
void FUN_00a94040_shell::UpdateSwitchState(FNV_UpdateFlags* update, unsigned int flags)
{
    unsigned short& state = *reinterpret_cast<unsigned short*>(&m_0ac);
    if (update->shouldActivate)
        state |= 2;
    else
        state &= ~2u;
    m_fSavedTime = update->time;
    if (m_0ac & 1)
    {
        ++m_uiRevID;
        unsigned int* count = &m_uiRevID;
        if (update->shouldActivate)
            FUN_004eff50(update, 1);
        reinterpret_cast<NiAVObject*>(this)->UpdateWorldData(*reinterpret_cast<NiUpdateData*>(update));
        if (m_iIndex >= 0)
        {
            NiAVObject* child = reinterpret_cast<NiAVObject**>(m_kChildren.m_pBase)[m_iIndex];
            if (child)
            {
                reinterpret_cast<NiAVObject*>(child)->UpdateDownwardPass(*reinterpret_cast<NiUpdateData*>(update), flags);
                m_kChildRevID.SetAt(m_iIndex, *count);
                NiAVObject* raw = reinterpret_cast<NiAVObject*>(child);
                FNV_Color4* color = raw->m_kWorldBound ? reinterpret_cast<FNV_Color4*>(raw->m_kWorldBound) : &DAT_011f4288;
                FNV_Color4* out = reinterpret_cast<FNV_Color4*>(m_kWorldBound);
                float alpha = color->fourth;
                out->first = color->first;
                out->second = color->second;
                out->third = color->third;
                out->fourth = alpha;
            }
        }
    }
    else
    {
        FUN_00a5dd70(update, flags);
    }
}

namespace fnv_00a94130 {
struct SwitchValX
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    float m_0c;
};

void __stdcall FUN_004eff50(NiUpdateData* upd, int value);
extern unsigned char DAT_011f4288;

struct FUN_00a94130_cls : NiSwitchNode
{
    void FUN_00a5ded0(NiUpdateData& upd, unsigned int flag);
    void NiSwitchNode_UpdateSelectedDownwardPass(NiUpdateData& upd, unsigned int flag);
};

// @fnv 0x00a94130
// src: XBOX_PDB 0x00a94130
void FUN_00a94130_cls::NiSwitchNode_UpdateSelectedDownwardPass(NiUpdateData& upd, unsigned int flag)
{
    unsigned char* pUpdBytes = (unsigned char*)&upd;
    m_fSavedTime = upd.fTime;
    if ((m_0ac & 1) != 0)
    {
        unsigned int flags = m_uFlags;
        m_uiRevID++;
        unsigned char ucSavedFlag = pUpdBytes[4];
        pUpdBytes[4] = (unsigned char)((flags >> 3) & 1);
        FUN_004eff50(&upd, 1);
        pUpdBytes[4] = ucSavedFlag;
        UpdateWorldData(upd);
        if (m_iIndex < 0)
        {
            return;
        }
        NiAVObject* child = reinterpret_cast<NiAVObject**>(m_kChildren.m_pBase)[m_iIndex];
        if (child == 0)
        {
            return;
        }
        unsigned int uiChildFlags = child->m_uFlags;
        unsigned char ucChildBit1 = (unsigned char)(uiChildFlags >> 1);
        if ((ucChildBit1 & 1) != 0)
        {
            unsigned char ucChildBit4 = (unsigned char)(uiChildFlags >> 4);
            if ((ucChildBit4 & 1) != 0)
            {
                child->UpdateRigidDownwardPass(upd, flag);
            }
            else
            {
                child->UpdateSelectedDownwardPass(upd, flag);
            }
        }
        m_kChildRevID.SetAt(m_iIndex, m_uiRevID);
        SwitchValX* src = reinterpret_cast<SwitchValX*>(child->m_kWorldBound);
        if (src == 0)
        {
            src = (SwitchValX*)&DAT_011f4288;
        }
        SwitchValX* dst = reinterpret_cast<SwitchValX*>(m_kWorldBound);
        float fValue = src->m_0c;
        dst->m_00 = src->m_00;
        dst->m_04 = src->m_04;
        unsigned int c = src->m_08;
        dst->m_08 = c;
        dst->m_0c = fValue;
    }
    else
    {
        FUN_00a5ded0(upd, flag);
    }
}
}  // namespace fnv_00a94130

void* __cdecl NiMalloc(unsigned int uiSize) throw();
void __cdecl NiFree(void* pvMem) throw();

template <>
inline NiTArray<unsigned int, NiTMallocInterface<unsigned int> >::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    m_usMaxSize = (unsigned short)uiMaxSize;
    m_usGrowBy = (unsigned short)uiGrowBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = static_cast<unsigned int*>(NiMalloc(sizeof(unsigned int) * m_usMaxSize));
    else
        m_pBase = 0;
}

template <>
inline NiTArray<unsigned int, NiTMallocInterface<unsigned int> >::~NiTArray()
{
    NiFree(m_pBase);
}

template <>
inline NiTPrimitiveArray<unsigned int>::NiTPrimitiveArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
    : NiTArray<unsigned int, NiTMallocInterface<unsigned int> >(uiMaxSize, uiGrowBy)
{}

// NiSwitchNode's implicit scalar deleting destructor is 0x00a94400 (vftable slot 0).
// @fnv 0x00a94360
NiSwitchNode::NiSwitchNode()
    : NiNode(0), m_usFlags(0), m_iIndex(-1), m_fSavedTime(0.0f), m_uiRevID(1), m_kChildRevID(1, 1)
{
    m_usFlags |= 3;
}

struct Node_a94440 : NiSwitchNode
{
    void NiNode_AttachChild(void* a1, int a2);
    void NiSwitchNode_AttachChild(void* a1, int a2);
};

inline void AppendRevision(NiTPrimitiveArray<unsigned int>& array, const unsigned int& item)
{
    unsigned int index = array.m_usSize;
    if (index >= array.m_usMaxSize)
        array.SetSize(index + array.m_usGrowBy);
    array.SetAt(index, item);
}

// Calls FUN_00a5ed10 with the given arguments, sets m_b8 to 1, and appends a null entry to m_kArrBC.
// @fnv 0x00a94440
// src: XBOX_PDB 0x00a94440
void Node_a94440::NiSwitchNode_AttachChild(void* a1, int a2)
{
    NiNode_AttachChild(a1, a2);
    m_uiRevID = 1;
    AppendRevision(m_kChildRevID, 0);
}

void* __cdecl Object_DispatchCommandFour(unsigned int);

struct SwitchNode_a94550
{
    SwitchNode_a94550* FUN_00a94360();
};

// @fnv 0x00a94550
SwitchNode_a94550* __cdecl CreateSwitchNode()
{
    SwitchNode_a94550* p = (SwitchNode_a94550*)Object_DispatchCommandFour(0xcc);
    if (p)
        return p->FUN_00a94360();
    return 0;
}

inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int transferred = (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 8))(this, buffer, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += transferred;
    return transferred;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int transferred = (*reinterpret_cast<NIBINARYSTREAM_WRITEFN*>(reinterpret_cast<char*>(this) + 12))(this, buffer, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += transferred;
    return transferred;
}

template <class T> inline void BA94570BinaryStreamLoad(NiBinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BA94570LoadBinary(NiStream& kStream, T& value)
{
    BA94570BinaryStreamLoad(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x24c), &value);
}

struct FUN_00a94570_Node : NiSwitchNode
{
    void NiSwitchNode_LoadBinary(NiStream& stream);
};

// @fnv 0x00a94570
// src: XBOX_PDB 0x00a94570
void FUN_00a94570_Node::NiSwitchNode_LoadBinary(NiStream& kStream)
{
    NiNode::LoadBinary(kStream);

    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&kStream) + 0xd8) < 0x0A000102)
        m_usFlags = (*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(&kStream) + 0x284) >> 6) & 0x1ff;
    else
        BA94570LoadBinary(kStream, m_usFlags);

    BA94570LoadBinary(kStream, m_iIndex);
    m_usFlags |= 2;
}

extern char* DAT_011f5eb4;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char const*);
char* __cdecl NiGetViewerString_00a7d4d0(char const*, int);
char* __cdecl NiGetViewerString(char const*, bool);

struct FUN_00a5ea70_Obj
{
    void NiNode_GetViewerStrings(StrArr* pkStrings);
};

__forceinline void AddString(StrArr* pkStrings, char* pStr)
{
    StrArr* pArr = pkStrings;
    unsigned int index = pArr->m_usSize;
    if (index >= pArr->m_usMaxSize)
        pArr->SetSize(index + pArr->m_usGrowBy);
    pArr->SetAt(index, pStr);
}

struct FUN_00a94680_shell : public NiSwitchNode
{
    void AppendDebugStrings(StrArr* pkStrings);
};

// Appends the base class strings plus the node's index and update-only-active flag to pkStrings.
// @fnv 0x00a94680
void FUN_00a94680_shell::AppendDebugStrings(StrArr* pkStrings)
{
    reinterpret_cast<FUN_00a5ea70_Obj*>(this)->NiNode_GetViewerStrings(pkStrings);
    AddString(pkStrings, NiViewerStrings_NiGetViewerString_Title(DAT_011f5eb4));
    AddString(pkStrings, NiGetViewerString_00a7d4d0("m_iIndex", m_iIndex));
    bool bUpdateOnlyActive = m_0ac & 1;
    AddString(pkStrings, NiGetViewerString("m_bUpdateOnlyActive", bUpdateOnlyActive));
}

// FNV_UpdateFlags, FNV_Color4, DAT_011f4288 and FUN_004eff50 are declared by the translation unit.

class SwitchNodeUpdate : public NiSwitchNode
{
  public:
    void NiNode_UpdateRigidDownwardPass(FNV_UpdateFlags* apData, unsigned int auiFlags);
    void NiSwitchNode_UpdateRigidDownwardPass(FNV_UpdateFlags* apData, unsigned int auiFlags);
};

// @fnv 0x00a94220
// src: XBOX_PDB 0x00a94220
void SwitchNodeUpdate::NiSwitchNode_UpdateRigidDownwardPass(FNV_UpdateFlags* apData, unsigned int auiFlags)
{
    m_fSavedTime = apData->time;
    if (m_usFlags & 1)
    {
        ++m_uiRevID;
        unsigned char bSavedActivate = apData->shouldActivate;
        apData->shouldActivate = (m_uFlags >> 3) & 1;
        FUN_004eff50(apData, 1);
        apData->shouldActivate = bSavedActivate;
        UpdateWorldData(*reinterpret_cast<NiUpdateData*>(apData));
        if (m_iIndex >= 0)
        {
            NiAVObject* pkChild = reinterpret_cast<NiAVObject**>(m_kChildren.m_pBase)[m_iIndex];
            if (pkChild)
            {
                if ((static_cast<unsigned char>(pkChild->m_uFlags >> 1) & 1) != 0)
                    pkChild->UpdateRigidDownwardPass(*reinterpret_cast<NiUpdateData*>(apData), auiFlags);
                m_kChildRevID.SetAt(m_iIndex, m_uiRevID);
                const FNV_Color4* pkBound = pkChild->m_kWorldBound ? reinterpret_cast<FNV_Color4*>(pkChild->m_kWorldBound) : &DAT_011f4288;
                float fFourth = pkBound->fourth;
                FNV_Color4* pkDest = reinterpret_cast<FNV_Color4*>(m_kWorldBound);
                pkDest->first = pkBound->first;
                pkDest->second = pkBound->second;
                pkDest->third = pkBound->third;
                pkDest->fourth = fFourth;
            }
        }
    }
    else
    {
        NiNode_UpdateRigidDownwardPass(apData, auiFlags);
    }
}

template <class T> inline void A946BinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A946SaveBinary(NiStream& kStream, const T& value)
{
    A946BinaryStreamSave(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x250), &value);
}

// The shared class lacks a SaveBinary override declaration; this body uses ECX and the same stack argument as __thiscall.
// Saves the base node, then writes m_usFlags and m_iIndex to the stream.
// @fnv 0x00a94610
void __fastcall SaveSwitchNodeBinary(NiSwitchNode* node, void*, NiStream& kStream)
{
    node->NiNode::SaveBinary(kStream);
    A946SaveBinary(kStream, node->m_usFlags);
    A946SaveBinary(kStream, node->m_iIndex);
}
