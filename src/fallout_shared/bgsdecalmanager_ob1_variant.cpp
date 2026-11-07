
// src/fallout_shared/bgsdecalmanager_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout_shared/bgsdecalmanager.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../include/BSCullingProcess.h"
#include "../../include/NiCullingProcess.h"
#include "../../include/NiAccumulator.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiCamera.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiRenderer.h"
#include "../../include/NiPointer.h"

struct HostV;
struct ObjV
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19();
    virtual void v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(), v32(), v33(),
        v34(), v35(), v36(), v37(), v38(), v39();
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(), v48(), v49(), v50(), v51(), v52();
    virtual void Attach(HostV* pkHost);
    char pad04[0x2c];
    unsigned int m_uiValue1;
    bool TestFlag(unsigned int uiMask) const
    {
        return (m_uiValue1 & uiMask) != 0;
    }
};
struct CtrlV
{
    char pad[0x28];
    int m_i28;
    bool IsEmpty() const
    {
        return m_i28 == 0;
    }
    int BuildEntryValueArray();
    bool BSCompoundFrustum_Process(ObjV* pkObj);
    void SetActorList(int iState);
};
struct HostV
{
    char pad[0x8c];
    void* m_pv8c;
    int m_iFadeIndex;
    char pad94[0x2c];
    CtrlV* m_pkCtrl;
    bool HasX() const
    {
        return (bool)m_pv8c;
    }
    void NiCullingProcess_DoCulling(ObjV* pkObj);
    void BSCullingProcess_Process(ObjV* pkObj);
};
// @fnv 0x00c4ee90
// src: XBOX_PDB 0x00c4ee90
void HostV::BSCullingProcess_Process(ObjV* pkObj)
{
    if (m_iFadeIndex != 2 && m_iFadeIndex != 1)
    {
        ObjV* pkTmp = pkObj;
        if (pkTmp->TestFlag(0x1000))
        {
            if (!pkTmp->TestFlag(0x100000))
                pkObj->Attach(this);
        }
        else if (!m_pkCtrl || m_pkCtrl->IsEmpty() || m_iFadeIndex == 3)
        {
            if (pkObj->TestFlag(0x800) || !HasX())
                pkObj->Attach(this);
            else
                NiCullingProcess_DoCulling(pkObj);
        }
        else if (pkObj->TestFlag(0x800) || ((!m_pkCtrl || m_pkCtrl->IsEmpty()) && !HasX()))
        {
            pkObj->Attach(this);
        }
        else
        {
            int iState = m_pkCtrl->BuildEntryValueArray();
            if (m_pkCtrl->BSCompoundFrustum_Process(pkObj))
                pkObj->Attach(this);
            m_pkCtrl->SetActorList(iState);
        }
    }
    else if (m_iFadeIndex == 1)
    {
        pkObj->Attach(this);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__forceinline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

__forceinline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

inline NiAccumulator* GetRoot()
{
    NiRenderer* m = NiRenderer::ms_pRenderer;
    int u1;
    int u2;
    return *reinterpret_cast<NiAccumulator**>(m->m_spAccum);
}

template <> __forceinline NiPointer<NiAccumulator>::NiPointer()
{
    m_pObject = 0;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <> __forceinline NiPointer<NiAccumulator>::~NiPointer()
{
    int u3;
    int u4;
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <> __forceinline NiAccumulator* NiPointer<NiAccumulator>::operator->() const
{
    return m_pObject;
}

template <> __forceinline NiPointer<NiAccumulator>::operator NiAccumulator*() const
{
    return m_pObject;
}

// The shared declaration retains an opaque NiNodeX*: this parameter is a camera, while renderer +8 is an accumulator.
// @fnv 0x00c4f070
// src: XBOX_PDB 0x00c4f070
void NiCullingProcess::BSCullingProcess_Process_00c4f070(NiNodeX* a, NiAVObject* b, int c)
{
    if (!a || !b)
        return;
    m_pkCamera = (const NiCamera*)a;
    NiCullingProcess_SetFrustum((char*)m_pkCamera + 0xdc);
    void* saved = 0;
    if (c)
    {
        saved = m_pkVisibleSet;
        m_pkVisibleSet = (void*)c;
    }
    NiPointer<NiAccumulator> sp;
    if (!m_pkVisibleSet)
    {
        sp = *reinterpret_cast<NiPointer<NiAccumulator>*>((char*)this + 0xc4);
        if (!sp)
            sp = GetRoot();
        if (sp)
            sp->StartAccumulating(reinterpret_cast<const NiCamera*>(a));
    }
    b->Cull(*this);
    if (c)
        m_pkVisibleSet = saved;
}

void __cdecl Object_DoNothing(const char* pcFormat, ...);

inline NiFixedString::operator const char*() const
{
    return m_kHandle;
}

inline const char* NiGeometry::GetName() const
{
    return m_kName;
}

// @fnv 0x00c4f1d0
// src: XBOX_PDB 0x00c4f1d0
void BSCullingProcess::AppendVirtual(NiGeometry& kVisible)
{
    bool bRegistered = false;
    if (m_acRendererDataA)
    {
        if (m_acRendererDataA->RegisterObject(&kVisible))
            bRegistered = true;
    }
    if (!bRegistered)
    {
        Object_DoNothing("NiCullingProcess::Append> Geometry failed RegisterObject, not rendering: %s\n",
                     kVisible.GetName() ? kVisible.GetName() : "NULL");
    }
}
