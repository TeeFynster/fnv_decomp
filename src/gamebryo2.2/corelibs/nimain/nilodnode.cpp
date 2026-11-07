#include "../../../../include/StrArr.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiRangeLODData.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiLODNode.h"
#include "../../../../include/NiLODData.h"
#include "../../../../include/NiCullingProcess.h"

// src/gamebryo2.2/corelibs/nimain/nilodnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nilodnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

inline unsigned int LODGetFileVersion(const NiStream* stream)
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(stream) + 0xd8);
}

inline NiBinaryStream* LODGetBinaryStream(NiStream* stream)
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(stream) + 0x24c);
}

inline void NiRangeLODData::SetGridPosition(const NiPoint3& c)
{
    m_kCenter = c;
}

inline void NiRangeLODData::SetRange(unsigned int i, float fNear, float fFar)
{
    if (i >= m_uiRangeCount)
        SetRangeCount(i + 1);
    m_pRanges[i].m_fNearPlane = fNear;
    m_pRanges[i].m_fFarPlane = fFar;
}

extern "C" const void* g_011f5f1c;

// @fnv 0x00a994c0
// src: COMMUNITY 0x00a994c0
const void* __cdecl NiLODNode_GetRTTI()
{
    return &g_011f5f1c;
}

extern int DAT_010a0b64;

// Allocates a NiLODNode, initializes its base, LOD data, switch index and modifier flag.
// @fnv 0x00a99710
// src: EXE 0x00a99710
void* __cdecl NiLODNode_CreateObject()
{
    void* p = BSFadeNode::operator new(0xd4);
    if (p)
    {
        NiLODNode* n = static_cast<NiLODNode*>(p);
        n->FUN_00a94360();
        *(void**)p = &DAT_010a0b64;
        n->m_spLODData.m_pObject = 0;
        n->m_iIndex = 0;
        n->m_bLODActive = true;
        return p;
    }
    return 0;
}

// @fnv 0x00a992e0
// src: XBOX_PDB 0x00a992e0
bool __thiscall NiLODNode::RegisterStreamables_00a992e0(NiStream* stream)
{
    if (!NiBSPNode_RegisterStreamables(stream))
        return false;
    NiLODData* node = m_spLODData.m_pObject;
    if (node)
        node->RegisterStreamables(*stream);
    return true;
}

// Calls FUN_00a99470, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00a99670
NiLODNode* __thiscall NiLODNode::FUN_00a99670(unsigned int flags)
{
    FUN_00a99470();
    if (flags & 1)
        operator delete(this, 0xd4);
    return this;
}

// Updates world data, then the referenced LOD data.
// NiLODData's vf36 declaration lacks its NiLODNode parameter; retain the call signature here.
// @fnv 0x00a99110
// src: XBOX_PDB 0x00a99110
void __thiscall NiLODNode::UpdateWorldData_00a99110(NiUpdateData& UpdateData)
{
    ((NiAVObject*)this)->NiAVObject::UpdateWorldData(UpdateData);
    NiLODData* p = m_spLODData.m_pObject;
    if (p)
        reinterpret_cast<void(__thiscall*)(NiLODData*, NiLODNode*)>((*reinterpret_cast<void***>(p))[36])(p, this);
}

// NiSwitchNode's stream and copy overrides are not declared in the shared header yet.
extern "C" void FUN_00a94610();
extern "C" void NiSwitchNode_CopyMembers();
extern "C" void NiSwitchNode_LoadBinary();
extern "C" void FUN_00a94680();
// @fnv 0x00a99310
// src: XBOX_PDB 0x00a99310
void NiLODNode::SaveBinary_00a99310(NiStream& kStream)
{
    reinterpret_cast<void(__thiscall*)(NiSwitchNode*, NiStream&)>(&FUN_00a94610)(
        reinterpret_cast<NiSwitchNode*>(this), kStream);
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_spLODData.m_pObject));
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<long volatile*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<long volatile*>(&m_uiRefCount));
}
// Replaces m_sp with p, releasing the old object and incrementing the new one's reference count when they differ.
// @fnv 0x00a99340
void NiLODNode::AssignRefCounted(Obj* apObj)
{
    NiRefObject*& referencedObject = reinterpret_cast<NiRefObject*&>(m_spLODData.m_pObject);
    NiRefObject* old = referencedObject;
    NiRefObject* replacement = reinterpret_cast<NiRefObject*>(apObj);
    if (old != replacement)
    {
        if (old)
            old->DecRefCount();
        referencedObject = replacement;
        if (replacement)
            replacement->IncRefCount();
    }
}

// Initialization remains at the call site, as in this unit's original inline code.
inline NiUpdateData::NiUpdateData()
{}

// @fnv 0x00a991d0
void NiLODNode::UpdateChildrenWorldData()
{
    NiUpdateData UpdateData;
    UpdateData.fTime = m_fSavedTime;
    UpdateData.pad1 = (static_cast<unsigned char>(m_usFlags) >> 1) & 1;
    UpdateData.pad2 = false;
    UpdateData.pad3 = false;
    UpdateData.pad4 = false;
    UpdateData.pad5 = false;

    for (int iIndex = 0; iIndex < m_kChildren.m_usSize; ++iIndex)
    {
        NiAVObject* pkChild = m_kChildren.m_pBase[iIndex].m_pObject;

        if (pkChild)
        {
            if (m_kChildRevID.GetAt(iIndex) != m_uiRevID)
            {
                m_kChildRevID.SetAt(static_cast<unsigned int>(iIndex), m_uiRevID);

                pkChild->UpdateDownwardPass(UpdateData, 0);
            }
        }
    }
}

// @fnv 0x00a99390
// src: XBOX_PDB 0x00a99390
void NiLODNode::CopyMembers_00a99390(NiSwitchNode* pkDest, CloningProcess& kCloning)
{
    reinterpret_cast<void(__thiscall*)(NiSwitchNode*, NiSwitchNode*, CloningProcess&)>(&NiSwitchNode_CopyMembers)(
        this, pkDest, kCloning);

    NiLODData* pObj = m_spLODData.m_pObject;
    if (pObj)
    {
        // The shared vf37 declaration lacks its return type.
        NiLODData* p = reinterpret_cast<NiLODData*(__thiscall*)(NiLODData*)>(
            (*reinterpret_cast<void***>(pObj))[37])(pObj);
        static_cast<NiLODNode*>(pkDest)->AssignRefCounted((Obj*)p);
    }
    else
    {
        NiRefObject* pOld = reinterpret_cast<NiRefObject*>(static_cast<NiLODNode*>(pkDest)->m_spLODData.m_pObject);
        if (pOld)
        {
            if (InterlockedDecrement(reinterpret_cast<long volatile*>(&pOld->m_uiRefCount)) == 0)
                pOld->DeleteThis();
            static_cast<NiLODNode*>(pkDest)->m_spLODData.m_pObject = 0;
        }
    }
}

extern int DAT_011abdf4;

// If enabled and a target is set, recomputes m_iIndex via v35/v38 and walks it down to a valid array slot, then calls UpdateSwitchChild.
// @fnv 0x00a99140
void NiLODNode::UpdateTargetIndex(Arg99* arg)
{
    NiLODData*& m_pkTarget = m_spLODData.m_pObject;
    if (m_bLODActive && m_pkTarget)
    {
        const NiCamera* camera = reinterpret_cast<const NiCullingProcess*>(arg)->m_pkCamera;
        // The shared vf35/vf38 declarations lack these parameters and return types.
        m_iIndex = reinterpret_cast<int(__thiscall*)(NiLODData*, const NiCamera*, NiLODNode*)>(
            (*reinterpret_cast<void***>(m_pkTarget))[35])(m_pkTarget, camera, this);
        int iGlobalIndex = DAT_011abdf4;
        if (iGlobalIndex >= 0)
            m_iIndex = reinterpret_cast<int(__thiscall*)(NiLODData*, int)>(
                (*reinterpret_cast<void***>(m_pkTarget))[38])(m_pkTarget, iGlobalIndex);
        if (m_iIndex >= 0)
        {
            int n = m_kChildren.m_usSize;
            while (m_iIndex >= 0 && (m_iIndex >= n || m_kChildren.m_pBase[m_iIndex].m_pObject == 0))
                m_iIndex--;
        }
    }
    UpdateSwitchChild(arg);
}

void __cdecl NiFree(void* pvMem) throw();

template <> inline NiPointer<NiLODData>::~NiPointer()
{
    if (m_pObject)
        static_cast<NiRefObject*>(m_pObject)->DecRefCount();
}

template <>
inline NiTArray<unsigned int, NiTMallocInterface<unsigned int> >::~NiTArray()
{
    NiFree(m_pBase);
}

// Destructor for the class; the body is empty, member cleanup is handled by the compiler-generated member destructors.
// @fnv 0x00a99470
NiLODNode::~NiLODNode() throw()
{}

// @fnv 0x00a996a0
NiLODNode* NiLODNode::CreateCloneLODNode(CloningProcess& process)
{
    void* memory = BSFadeNode::operator new(0xd4);
    NiLODNode* clone;
    if (memory)
    {
        clone = static_cast<NiLODNode*>(memory);
        clone->FUN_00a94360();
        *reinterpret_cast<void**>(clone) = &DAT_010a0b64;
        clone->m_spLODData.m_pObject = 0;
    }
    else
    {
        clone = 0;
    }
    if (clone)
    {
        clone->m_iIndex = 0;
        clone->m_bLODActive = true;
    }
    CopyMembers_00a99390(reinterpret_cast<NiSwitchNode*>(clone), process);
    return clone;
}

extern "C" const void* g_011f5f1c;
extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(const void* pvName);

inline unsigned int LODAddViewerString(StrArr* strings, const char* const& value)
{
    unsigned int index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, const_cast<char* const&>(value));
    return index;
}

// @fnv 0x00a99760
// src: XBOX_PDB 0x00a99760
void NiLODNode::GetViewerStrings_00a99760(NiViewerStringsArray* strings)
{
    StrArr* pkStrings = reinterpret_cast<StrArr*>(strings);
    reinterpret_cast<void(__thiscall*)(NiSwitchNode*, NiViewerStringsArray*)>(&FUN_00a94680)(
        reinterpret_cast<NiSwitchNode*>(this), strings);
    LODAddViewerString(pkStrings, NiViewerStrings_NiGetViewerString_Title(g_011f5f1c));
    NiObject* pkLODData = static_cast<NiObject*>(m_spLODData.m_pObject);
    if (pkLODData)
    {
        pkLODData->GetViewerStrings(strings);
    }
    else
    {
        LODAddViewerString(pkStrings, "NULL LOD Data");
    }
}

void __stdcall NiBSPNode_LinkObject(NiStream* stream);
// @fnv 0x00a99270
void NiLODNode::LoadRefFromStream(NiStream* stream)
{
    NiRefObject*& m_ref = reinterpret_cast<NiRefObject*&>(m_spLODData.m_pObject);
    NiBSPNode_LinkObject(stream);
    if (LODGetFileVersion(stream) >= 0x0a00010cu)
    {
        NiRefObject* replacement = static_cast<NiRefObject*>(stream->GetLoadedObject());
        NiRefObject* previous = m_ref;
        if (previous != replacement)
        {
            if (previous)
                previous->DecRefCount();
            m_ref = replacement;
            if (replacement)
                replacement->IncRefCount();
        }
    }
}

// Calls FUN_00a94000, checks m_sp nullness, then compares v02 results and calls v23 when they match.
// @fnv 0x00a99400
// src: XBOX_PDB 0x00a99400
bool NiLODNode::IsEqual_00a99400(Holder* other)
{
    if (!NiSwitchNode::IsEqual_00a94000(reinterpret_cast<NiObject*>(other)))
        return false;
    NiObject* pOtherProp = reinterpret_cast<NiObject*>(reinterpret_cast<NiLODNode*>(other)->m_spLODData.m_pObject);
    if ((m_spLODData.m_pObject && !pOtherProp) || (!m_spLODData.m_pObject && pOtherProp))
        return false;
    if (m_spLODData.m_pObject && pOtherProp)
    {
        NiObject* a = reinterpret_cast<NiObject*>(m_spLODData.m_pObject);
        if (a->GetRTTI() == pOtherProp->GetRTTI() && !static_cast<const NiObject*>(m_spLODData.m_pObject)->IsEqual(pOtherProp))
            return false;
    }
    return true;
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned);

// The shared stream is opaque; keep this unit's inline transfer through its read callback.
inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes,
    unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int bytesRead = (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 8))(
        this, buffer, bytes, componentSizes, componentCount);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += bytesRead;
    return bytesRead;
}
template <class T> inline unsigned LODBinaryStreamLoad(NiBinaryStream& binstream, T* pValue, unsigned uiNumEls)
{
    unsigned uiSize = sizeof(T);
    return binstream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void LODStreamLoadBinary(NiStream* s, T& v)
{
    LODBinaryStreamLoad(*LODGetBinaryStream(s), &v, 1);
}
inline void NiLODNode::SetLODData(NiRangeLODData* data)
{
    NiRefObject*& referencedObject = reinterpret_cast<NiRefObject*&>(m_spLODData.m_pObject);
    if (referencedObject != static_cast<NiRefObject*>(data))
    {
        if (referencedObject)
            referencedObject->DecRefCount();
        referencedObject = static_cast<NiRefObject*>(data);
        static_cast<NiRefObject*>(data)->IncRefCount();
    }
}
// @fnv 0x00a994d0
// src: XBOX_PDB 0x00a994d0
void __thiscall NiLODNode::LoadBinary_00a994d0(NiStream* pStream)
{
    NiStream* stream = (NiStream*)pStream;
    reinterpret_cast<void(__thiscall*)(NiSwitchNode*, NiStream*)>(&NiSwitchNode_LoadBinary)(
        reinterpret_cast<NiSwitchNode*>(this), stream);
    if (LODGetFileVersion(stream) <= 0xa00010b)
    {
        void* memory = Object_DispatchCommandFour(sizeof(NiRangeLODData));
        NiRangeLODData* data;
        if (memory)
            data = ((NiRangeLODData*)memory)->InitializeRangeLODData();
        else
            data = 0;

        NiPoint3 kTargetCenter;
        kTargetCenter.LoadBinary(stream);
        data->SetGridPosition(kTargetCenter);

        unsigned uiNumRanges;
        LODStreamLoadBinary(stream, uiNumRanges);
        if (uiNumRanges > 0)
        {
            data->SetRangeCount(uiNumRanges);
            for (unsigned i = 0; i < uiNumRanges; i++)
            {
                float fNear, fFar;
                LODStreamLoadBinary(stream, fNear);
                LODStreamLoadBinary(stream, fFar);
                data->SetRange(i, fNear, fFar);
            }
        }
        SetLODData(data);
    }
    else
    {
        stream->ReadLinkIDStub();
    }
}

