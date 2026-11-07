// gamebryo2.2/corelibs/nimain/nimaterialproperty.cpp (8 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiMaterialProperty.h"
#include "../../../../include/NiPlane.h"
#include "../../../../include/NiProperty.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/NiStream.h"

// These overrides are not declared by the shared property headers yet.
// Call their external entry points with the game's member-function ABI.
extern "C" void NiProperty_SaveBinary();
extern "C" void NiProperty_IsEqual();
extern "C" void NiProperty_GetViewerStrings();
extern "C" void NiMaterialProperty_CopyMemberData();

inline NiColor::NiColor() : r(0.0f), g(0.0f), b(0.0f)
{}

inline unsigned int NiBinaryStream::Read(void* buffer, unsigned int bytes,
                                        unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int read = (*m_pfnRead)(this, buffer, bytes, componentSizes, componentCount);
    m_uiAbsoluteCurrentPos += read;
    return read;
}

inline unsigned int NiBinaryStream::Read(void* buffer, unsigned int bytes)
{
    unsigned int componentSize = bytes;
    return Read(buffer, bytes, &componentSize, 1);
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes,
                                               unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int written = m_pfnWrite(this, buffer, bytes, componentSizes, componentCount);
    m_uiAbsoluteCurrentPos += written;
    return written;
}

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.m_pkIstr->Read(&value, sizeof(T));
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

// Preserve the property unit's inlined reference-count operations.
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

extern int DAT_0109d6c4;
void __fastcall DestroyFogProperty(void*);

struct NiMemObject_Del
{
    static void __cdecl operator delete(void*, size_t);
};

// @fnv 0x00a756f0
void* __fastcall NiMaterialProperty_Destructor(NiMaterialProperty* pThis, int, unsigned int flags)
{
    *(int**)pThis = &DAT_0109d6c4;
    if (NiRenderer::ms_pRenderer)
        (*(void(__thiscall**)(NiRenderer*, NiMaterialProperty*))(*(int*)NiRenderer::ms_pRenderer + 0xf4))(
            NiRenderer::ms_pRenderer, pThis);
    DestroyFogProperty(pThis);
    if (flags & 1)
        NiMemObject_Del::operator delete(pThis, 0x4c);
    return pThis;
}

// Loads a NiMaterialProperty from a stream, reading two colors and two or three floats depending on the stream version.
// @fnv 0x00a75790
void NiMaterialProperty::LoadBinary(NiStream& stream)
{
    NiProperty::LoadBinary(stream);
    if (stream.m_kHeader.m_uiVersion < 26)
    {
        NiColor kDummy;
        kDummy.LoadBinary(stream);
        kDummy.LoadBinary(stream);
        reinterpret_cast<NiColor*>(&unk1c)->LoadBinary(stream);
        reinterpret_cast<NiColor*>(&unk28)->LoadBinary(stream);
        ReadBinaryValue(stream, *reinterpret_cast<float*>(&unk38));
        ReadBinaryValue(stream, *reinterpret_cast<float*>(&unk3c));
    }
    else
    {
        reinterpret_cast<NiColor*>(&unk1c)->LoadBinary(stream);
        reinterpret_cast<NiColor*>(&unk28)->LoadBinary(stream);
        ReadBinaryValue(stream, *reinterpret_cast<float*>(&unk38));
        ReadBinaryValue(stream, *reinterpret_cast<float*>(&unk3c));
        ReadBinaryValue(stream, *reinterpret_cast<float*>(&unk40));
    }
}

void* __fastcall Lighting30shaderproperty_StoreAndAddReference_00a75650(void* pThis);
extern void* DAT_011f4a64;

// @fnv 0x00a759e0
// src: XBOX_PDB 0x00a759e0
void __cdecl NiMaterialProperty__SDMInit()
{
    void* pMemory = BSFadeNode::operator new(0x4c);
    NiRefObject* pFadeNode = (NiRefObject*)(pMemory ? Lighting30shaderproperty_StoreAndAddReference_00a75650(pMemory) : 0);
    if ((NiRefObject*)DAT_011f4a64 != pFadeNode)
    {
        if (DAT_011f4a64)
            ((NiRefObject*)DAT_011f4a64)->DecRefCount();
        DAT_011f4a64 = pFadeNode;
        if (pFadeNode)
            pFadeNode->IncRefCount();
    }
}

// @fnv 0x00a75960
bool __fastcall NiMaterialProperty_IsEqual(const NiMaterialProperty* pThis, void*, NiObject* apObject)
{
    const NiMaterialProperty* other = static_cast<const NiMaterialProperty*>(apObject);
    if (reinterpret_cast<bool(__thiscall*)(const NiProperty*, NiObject*)>(NiProperty_IsEqual)(pThis, apObject))
    {
        NiPlane* pPlaneA = (NiPlane*)&pThis->unk1c;
        NiPlane* b = (NiPlane*)&other->unk1c;
        if (!pPlaneA->operator==(*b))
        {
            NiPlane* pPlaneC = (NiPlane*)&pThis->unk28;
            NiPlane* pPlaneD = (NiPlane*)&other->unk28;
            if (!pPlaneC->operator==(*pPlaneD))
            {
                if (pThis->unk34 == other->unk34)
                {
                    if (*reinterpret_cast<const float*>(&pThis->unk38) == *reinterpret_cast<const float*>(&other->unk38))
                    {
                        if (*reinterpret_cast<const float*>(&pThis->unk3c) == *reinterpret_cast<const float*>(&other->unk3c))
                        {
                            if (*reinterpret_cast<const float*>(&pThis->unk40) == *reinterpret_cast<const float*>(&other->unk40))
                                return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

extern void* DAT_011f4a64;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Holder
{
    virtual void f0();
    virtual void f1();
};
// If DAT_011f4a64 is set, decrements its reference count at offset 4 and calls f1() when it reaches zero, then clears DAT_011f4a64.
// @fnv 0x00a75a40
void ReleaseGlobalHolder()
{
    if (DAT_011f4a64)
    {
        Holder* pHolder = (Holder*)DAT_011f4a64;
        if (InterlockedDecrement((volatile long*)((char*)DAT_011f4a64 + 4)) == 0)
            pHolder->f1();
        DAT_011f4a64 = 0;
    }
}

// @fnv 0x00a75730
NiObject* __fastcall NiMaterialProperty_MakeClone(NiMaterialProperty* pThis, void*, CloningProcess& kCloning)
{
    if (pThis->m_spControllers)
    {
        void* memory = NiProperty::operator new(sizeof(NiMaterialProperty));
        NiMaterialProperty* pkClone = static_cast<NiMaterialProperty*>(memory ? Lighting30shaderproperty_StoreAndAddReference_00a75650(memory) : 0);
        reinterpret_cast<void(__thiscall*)(NiMaterialProperty*, NiMaterialProperty*, CloningProcess&)>(
            NiMaterialProperty_CopyMemberData)(pThis, pkClone, kCloning);
        return pkClone;
    }
    pThis->NiObject::CopyMembersStream(pThis, &kCloning);
    return pThis;
}

template <class T>
inline void BinaryStreamSave(NiBinaryStream& stream, const T* value, unsigned int count = 1)
{
    unsigned int size = sizeof(T);
    stream.BinaryWrite(value, count * size, &size, 1);
}

template <class T> inline void SaveBinaryValue(NiStream& stream, const T& value)
{
    BinaryStreamSave(*stream.m_pkOstr, &value);
}

// Saves the base property, ambient and diffuse colors, shine, alpha and emit multiplier to the stream.
// @fnv 0x00a758c0
void __fastcall NiMaterialProperty_SaveBinary(NiMaterialProperty* pThis, void*, NiStream& kStream)
{
    reinterpret_cast<void(__thiscall*)(NiProperty*, NiStream&)>(NiProperty_SaveBinary)(pThis, kStream);
    reinterpret_cast<NiColor*>(&pThis->unk1c)->SaveBinary(kStream);
    reinterpret_cast<NiColor*>(&pThis->unk28)->SaveBinary(kStream);
    SaveBinaryValue(kStream, *reinterpret_cast<float*>(&pThis->unk38));
    SaveBinaryValue(kStream, *reinterpret_cast<float*>(&pThis->unk3c));
    SaveBinaryValue(kStream, *reinterpret_cast<float*>(&pThis->unk40));
}

struct MaterialViewerStringsArray
{
    void* m_ppVirtualMethodTable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& element);
    unsigned int Add(char* const& element)
    {
        unsigned int idx = m_usSize;
        if (idx >= m_usMaxSize)
            SetSize(idx + m_usGrowBy);
        SetAt(idx, element);
        return idx;
    }
};

extern NiRTTI g_011f4a5c;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcText);
char* __cdecl NiGetViewerString_00a7d550(const char* pcPrefix, float fValue);

// Appends the RTTI name, spec, emit (external or local), shine, alpha and emit multiplier strings to the viewer strings array.
// @fnv 0x00a75a70
void __fastcall NiMaterialProperty_GetViewerStrings(NiMaterialProperty* pThis, void*, MaterialViewerStringsArray* pkStrings)
{
    reinterpret_cast<void(__thiscall*)(NiProperty*, MaterialViewerStringsArray*)>(
        NiProperty_GetViewerStrings)(pThis, pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(g_011f4a5c.m_pcName));
    pkStrings->Add(reinterpret_cast<NiColor*>(&pThis->unk1c)->GetFormattedString("m_spec"));
    NiColor* externalEmit = reinterpret_cast<NiColor*>(pThis->unk34);
    if (externalEmit)
        pkStrings->Add(externalEmit->GetFormattedString("m_external_emit"));
    else
        pkStrings->Add(reinterpret_cast<NiColor*>(&pThis->unk28)->GetFormattedString("m_emit"));
    pkStrings->Add(NiGetViewerString_00a7d550("m_fShine", *reinterpret_cast<float*>(&pThis->unk38)));
    pkStrings->Add(NiGetViewerString_00a7d550("m_fAlpha", *reinterpret_cast<float*>(&pThis->unk3c)));
    pkStrings->Add(NiGetViewerString_00a7d550("m_fEmitMult", *reinterpret_cast<float*>(&pThis->unk40)));
}
