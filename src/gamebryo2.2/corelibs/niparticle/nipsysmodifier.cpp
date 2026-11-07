// gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp: NiPSysModifier (12 functions)

#include "nipsysmodifier_decls.h"
#include "../../../../include/StrArr.h"

// @fnv 0x00C318B0
void NiPSysModifier::LoadBinary(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);
    if (kStream.m_uiNifFileVersion < 0x14010001)
        kStream.ReadFixedString(m_kName);
    else
        kStream.ReadStringTableEntry(m_kName);

    NiBinaryStreamLoad(*kStream.m_pkIstr, &m_uiUpdateOrder);
    kStream.ResetStreamState();
    unsigned char ucActive;
    NiBinaryStreamLoad(*kStream.m_pkIstr, &ucActive);
    m_bModifierActive = ucActive != 0;
}

// @fnv 0x00C31780
void NiPSysModifier::CopyMemberData(NiPSysModifier* pkDest, CloningProcess& kCloning)
{
    NiObject::CreateVertexBufferSet(pkDest, kCloning);
    char* pcName = m_kName.m_kHandle;
    if (pkDest->m_kName.m_kHandle != pcName)
    {
        if (pcName != EmptyFS.m_kHandle)
            InterlockedIncrement(reinterpret_cast<volatile long*>(pcName - 8));
        char* pcOldName = pkDest->m_kName.m_kHandle;
        if (pcOldName != EmptyFS.m_kHandle)
            InterlockedDecrement(reinterpret_cast<volatile long*>(pcOldName - 8));
        pkDest->m_kName.m_kHandle = pcName;
    }
    pkDest->m_uiUpdateOrder = m_uiUpdateOrder;
    pkDest->m_bModifierActive = m_bModifierActive;
}

// @fnv 0x00C317E0
void NiPSysModifier::ProcessClone(CloningProcess& kCloning)
{
    NiObject::ProcessClone(kCloning);
    NiObject* pkClone = 0;
    kCloning.m_pCloneMap->GetAt(this, pkClone);
    NiPSysModifier* pkDest = static_cast<NiPSysModifier*>(pkClone);
    kCloning.m_pCloneMap->GetAt(reinterpret_cast<NiObject*>(m_pkTarget), pkClone);
    pkDest->m_pkTarget = reinterpret_cast<NiParticleSystem*>(pkClone);
}

// @fnv 0x00C31650
void NiPSysModifier::LinkObject(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    kStream.GetLoadedObject();
}

// @fnv 0x00c31640
void NiPSysModifier::SetTargetSystem(NiParticleSystem* pkTarget)
{
    m_pkTarget = pkTarget;
}

extern const char* const g_01202528_arg1;

// @fnv 0x00c31710
// src: COMMUNITY 0x00c31710
const char* const* __cdecl NiPSysModifier_GetRTTI()
{
    return &g_01202528_arg1;
}

bool __stdcall IsSameAs(NiObject* pkObject);
// @fnv 0x00c31830
bool NiPSysModifier::IsEqual(NiObject* pkObject) const
{
    NiPSysModifier* pkDest = static_cast<NiPSysModifier*>(pkObject);
    if (::IsSameAs(pkObject) && m_kName.m_kHandle == pkDest->m_kName.m_kHandle &&
        m_uiUpdateOrder == pkDest->m_uiUpdateOrder && m_bModifierActive == pkDest->m_bModifierActive)
        return true;
    return false;
}

// @fnv 0x00c31670
bool NiPSysModifier::RegisterStreamables(NiStream& kStream)
{
    if (!NiObject::RegisterStreamables(kStream))
        return false;
    kStream.RegisterFixedString(m_kName);
    return true;
}

__forceinline void WriteComponents(NiBinaryStream* stream, const void* data, unsigned int bytes,
                                   unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int written = stream->m_pfnWrite(stream, data, bytes, componentSizes, componentCount);
    stream->m_uiAbsoluteCurrentPos += written;
}

template <class T> __forceinline void PrimitiveWrite(NiBinaryStream* stream, const T& value)
{
    unsigned int size = sizeof(T);
    WriteComponents(stream, &value, sizeof(T), &size, 1);
}
__forceinline void BooleanWrite(NiBinaryStream* stream, bool value)
{
    unsigned int size = 1;
    WriteComponents(stream, &value, 1, &size, 1);
}
// @fnv 0x00c31950
void NiPSysModifier::SaveBinary(NiStream& stream)
{
    NiObject::SaveBinary(stream);
    stream.SerializeString(reinterpret_cast<const char*>(&m_kName));
    PrimitiveWrite(stream.m_pkOstr, m_uiUpdateOrder);
    stream.SaveLinkID(reinterpret_cast<NiObject*>(m_pkTarget));
    BooleanWrite(stream.m_pkOstr, m_bModifierActive);
}

extern "C" char* DAT_0109b220;
extern "C" int DAT_010c09cc;
extern "C" void(__stdcall* DAT_00fdf1c0)(char*);
extern "C" void(__stdcall* DAT_00fdf1c4)(char*);
// Keep constructor entry points here until their overloads are declared by the shared headers.
void __fastcall ConstructNiObject(NiObject* object);
// @fnv 0x00c316a0
NiPSysModifier* __fastcall ConstructNiPSysModifier(NiPSysModifier* modifier, void*,
                                                char* volatile* newName, unsigned int newOrder)
{
    ConstructNiObject(modifier);
    *reinterpret_cast<void**>(modifier) = &DAT_010c09cc;
    modifier->m_kName.m_kHandle = DAT_0109b220;
    modifier->m_uiUpdateOrder = newOrder;
    modifier->m_pkTarget = 0;
    modifier->m_bModifierActive = true;
    char* pNewName = *newName;
    if (modifier->m_kName.m_kHandle != pNewName)
    {
        if (pNewName != DAT_0109b220)
            DAT_00fdf1c0(pNewName - 8);
        if (modifier->m_kName.m_kHandle != DAT_0109b220)
            DAT_00fdf1c4(modifier->m_kName.m_kHandle - 8);
        modifier->m_kName.m_kHandle = pNewName;
    }
    return modifier;
}

__forceinline void StrArr::AppendInline(char* pElement)
{
    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, pElement);
}
void __stdcall AppendCameraPathEntries(StrArr* apViewerStrings);
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcText);
char* __cdecl NiGetViewerString_00a7d5e0(const char* pcPrefix, const char* pcValue);
char* __cdecl NiGetViewerString_00a7d510(const char* pcPrefix, unsigned int uiValue);
char* __cdecl NiGetViewerString(const char* pcPrefix, bool bValue);
extern const char g_011d4e34_arg1[];

// Appends the modifier's name, order and active flag as formatted strings to the given string array.
// The shared class inherits GetViewerStrings without declaring this override.
// @fnv 0x00c319e0
void __fastcall GetNiPSysModifierViewerStrings(NiPSysModifier* modifier, void*, StrArr* apViewerStrings)
{
    AppendCameraPathEntries(apViewerStrings);
    apViewerStrings->AppendInline(NiViewerStrings_NiGetViewerString_Title(g_01202528_arg1));
    const char* pcName = modifier->m_kName.m_kHandle;
    apViewerStrings->AppendInline(NiGetViewerString_00a7d5e0(g_011d4e34_arg1, pcName));
    apViewerStrings->AppendInline(NiGetViewerString_00a7d510("Order", modifier->m_uiUpdateOrder));
    apViewerStrings->AppendInline(NiGetViewerString("Active", modifier->m_bModifierActive));
}

// The scalar deleting destructor keeps the modifier vtable installed while releasing its name.
// @fnv 0x00c31870
NiPSysModifier* __fastcall DestroyNiPSysModifier(NiPSysModifier* modifier, void*, unsigned int uiFlags)
{
    *reinterpret_cast<void**>(modifier) = &DAT_010c09cc;
    modifier->m_kName.~NiFixedString();
    modifier->NiRefObject::~NiRefObject();
    if (uiFlags & 1)
        NiPSysModifier::operator delete(modifier, sizeof(NiPSysModifier));
    return modifier;
}
