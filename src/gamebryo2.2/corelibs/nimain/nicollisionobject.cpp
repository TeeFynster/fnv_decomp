// gamebryo2.2/corelibs/nimain/nicollisionobject.cpp: NiCollisionObject (10 functions)

#include "../../../../include/NiCollisionObject.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiStream.h"

// This unit's original collision assignment call does not unwind the constructor.
static inline void AssignCollisionObject(NiAVObject* object, NiCollisionObject* collision) throw()
{
    object->AssignCollisionObject(collision);
}

// @fnv 0x00a80fd0
void NiCollisionObject::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    stream.ResetStreamState();
}
// @fnv 0x00a80ff0
void NiCollisionObject::LinkObject(NiStream& stream)
{
    NiObject::LinkObject(stream);
    m_pkSceneObject = static_cast<NiAVObject*>(stream.GetLoadedObject());
}
// @fnv 0x00a810b0
void NiCollisionObject::SetSceneObject(NiAVObject* object)
{
    m_pkSceneObject = object;
    if (object && object->m_spCollisionObject.m_pObject != this)
        object->AssignCollisionObject(this);
}
// @fnv 0x00a810d0
NiCollisionObject::NiCollisionObject(NiAVObject* apSceneObject) : m_pkSceneObject(apSceneObject)
{
    if (apSceneObject && apSceneObject->m_spCollisionObject.m_pObject != this)
        AssignCollisionObject(apSceneObject, this);
}

extern char const* const g_01267b70_arg1;

// @fnv 0x00a810a0
// src: COMMUNITY 0x00a810a0
char const* const* __cdecl NiCollisionObject_GetRTTI()
{
    return &g_01267b70_arg1;
}

// @fnv 0x00a81010
bool NiCollisionObject::RegisterStreamables(NiStream& kStrm)
{
    if (!NiObject::RegisterStreamables(kStrm))
        return false;
    if (m_pkSceneObject != 0)
        m_pkSceneObject->RegisterStreamables(kStrm);
    return true;
}

// @fnv 0x00a81040
void NiCollisionObject::SaveBinary(NiStream& kStrm)
{
    NiObject::LinkObject(kStrm);
    kStrm.SaveLinkID(m_pkSceneObject);
}

// @fnv 0x00a81060
bool NiCollisionObject::IsEqual(NiObject* pkObject) const
{
    if (!NiObject::IsEqual(pkObject))
        return false;
    if (m_pkSceneObject && !pkObject)
        return false;
    if (!m_pkSceneObject && pkObject)
        return false;
    return true;
}

#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"
// Gamebryo NiTArray.inl bodies this unit's original inlines (the shared NiTArray declares them):
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    return SetAtGrow(m_usSize, element);
}

extern const char* g_pcA81100Name;
const char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
const char* __cdecl NiGetViewerString_00a7d5a0(char const* pcName, void* pvObj);

// @fnv 0x00a81100
void NiCollisionObject::GetViewerStrings(NiViewerStringsArray* pkStrings)
{
    NiObject::AddViewerStrings(pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(g_pcA81100Name));
    AddViewerStrings(pkStrings);
}

// @fnv 0x00a81160
void NiCollisionObject::AddViewerStrings(NiViewerStringsArray* pkStrings)
{
    {
        const char* p = NiViewerStrings_NiGetViewerString_Title(g_pcA81100Name);
        unsigned int uiPos = pkStrings->m_usSize;
        unsigned int uiSize = pkStrings->m_usMaxSize;
        if (uiPos >= uiSize)
        {
            pkStrings->SetSize(uiPos + pkStrings->m_usGrowBy);
        }
        pkStrings->SetAt(uiPos, p);
    }
    {
        const char* q = NiGetViewerString_00a7d5a0("m_pkSceneObject", m_pkSceneObject);
        unsigned int uiPos = pkStrings->m_usSize;
        unsigned int uiSize = pkStrings->m_usMaxSize;
        if (uiPos >= uiSize)
        {
            pkStrings->SetSize(uiPos + pkStrings->m_usGrowBy);
        }
        pkStrings->SetAt(uiPos, q);
    }
}
