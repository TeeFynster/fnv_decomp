// gamebryo2.2/corelibs/niparticle/nipsysdragmodifier.cpp: NiPSysDragModifier (8 functions)

#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiStream.h"

// The shared stream declaration does not expose its transfer fields. Keep
// these inline implementations here using the original stream ABI offsets.
__forceinline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiBytes,
                                                       unsigned int* puiComponentSizes, unsigned int uiComponents)
{
    unsigned int uiRead = (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 8))(
        this, pvBuffer, uiBytes, puiComponentSizes, uiComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += uiRead;
    return uiRead;
}

__forceinline unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiBytes,
                                                        unsigned int* puiComponentSizes, unsigned int uiComponents)
{
    unsigned int uiWritten = (*reinterpret_cast<NIBINARYSTREAM_WRITEFN*>(reinterpret_cast<char*>(this) + 12))(
        this, pvBuffer, uiBytes, puiComponentSizes, uiComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += uiWritten;
    return uiWritten;
}

template <class T>
__forceinline void NiBinaryStreamLoad(NiBinaryStream& kStream, T* pkValue, unsigned int uiNumEls = 1)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(pkValue, sizeof(T) * uiNumEls, &uiComponentSize, 1);
}

template <class T> __forceinline void ReadBinaryValue(NiStream& kStream, T& kValue)
{
    // NiStream keeps this input-stream field opaque in the shared declaration.
    NiBinaryStreamLoad(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x24C), &kValue, 1);
}

struct StreamArray;

class NiPSysDragModifier : public NiPSysModifier
{
  public:
    __declspec(noinline) __declspec(nothrow) NiPSysDragModifier();
    virtual void LoadBinary(NiStream& kStream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    NiObject* CloneDragModifier(CloningProcess* process);
    void GetDragViewerStrings(StreamArray& array);

    NiAVObject* m_pParent;
    NiPoint3 m_kDragDirection;
    float m_fDragStrength;
    float m_fFirstLightParameter;
    float m_fSecondLightParameter;
};

typedef char DragLayoutCheck104[(sizeof(NiPSysModifier) == 0x18) ? 1 : -1];
typedef char DragLayoutCheck108[(sizeof(NiPSysDragModifier) == 0x34) ? 1 : -1];
typedef char DragLayoutCheck109[(offsetof(NiPSysDragModifier, m_kDragDirection) == 0x1C) ? 1 : -1];
typedef char DragLayoutCheck110[(offsetof(NiPSysDragModifier, m_fDragStrength) == 0x28) ? 1 : -1];
typedef char DragLayoutCheck111[(offsetof(NiPSysDragModifier, m_fFirstLightParameter) == 0x2C) ? 1 : -1];
typedef char DragLayoutCheck112[(offsetof(NiPSysDragModifier, m_fSecondLightParameter) == 0x30) ? 1 : -1];

// @fnv 0x00C2C450
void NiPSysDragModifier::LoadBinary(NiStream& kStream)
{
    NiPSysModifier::LoadBinary(kStream);
    kStream.ResetStreamState();
    m_kDragDirection.LoadBinary(kStream);
    ReadBinaryValue(kStream, m_fDragStrength);
    ReadBinaryValue(kStream, m_fFirstLightParameter);
    ReadBinaryValue(kStream, m_fSecondLightParameter);
}


// @fnv 0x00c2c080
// src: EXE 0x00c2c080
void* __cdecl NiPSysDragModifier_CreateObject()
{
    return new NiPSysDragModifier;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_01202768;
// @fnv 0x00c2c0a0
// src: COMMUNITY 0x00c2c0a0
void* __cdecl NiPSysDragModifier_GetRTTI()
{
    return &g_01202768;
}

// @fnv 0x00c2c0b0
NiObject* NiPSysDragModifier::CloneDragModifier(CloningProcess* kCloning)
{
    NiPSysDragModifier* pkObject = new NiPSysDragModifier;
    NiPSysModifier::CopyMemberData(pkObject, *kCloning);
    pkObject->m_kDragDirection = m_kDragDirection;
    pkObject->m_fDragStrength = m_fDragStrength;
    pkObject->m_fFirstLightParameter = m_fFirstLightParameter;
    pkObject->m_fSecondLightParameter = m_fSecondLightParameter;
    return pkObject;
}

extern const NiPoint3 g_UNIT_X;
static const float s_fInfinity = 3.402823466e+38F;

// @fnv 0x00c2c030
NiPSysDragModifier::NiPSysDragModifier()
    : m_pParent(0), m_kDragDirection(g_UNIT_X), m_fDragStrength(0.05f), m_fFirstLightParameter(s_fInfinity),
      m_fSecondLightParameter(s_fInfinity)
{}

template <class T> __forceinline void WriteBinaryValue(NiBinaryStream& stream, T* value)
{
    unsigned int size = sizeof(T);
    stream.BinaryWrite(value, sizeof(T), &size, 1);
}

// Declaration-only call adapter: the shared NiPSysModifier header lacks the
// viewer-string override implemented by nipsysmodifier.cpp at 0x00c319e0.
struct ParticleViewerStringsCall
{
    void GetViewerStrings(StreamArray& array);
};

// @fnv 0x00c2c4f0
void NiPSysDragModifier::SaveBinary(NiStream& stream)
{
    NiPSysModifier::FUN_00c31950(stream);
    stream.SaveLinkID(reinterpret_cast<const NiObject*>(m_pParent));
    m_kDragDirection.SaveBinary(&stream);
    // NiStream keeps this output-stream field opaque in the shared declaration.
    WriteBinaryValue(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x250), &m_fDragStrength);
    WriteBinaryValue(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x250), &m_fFirstLightParameter);
    WriteBinaryValue(**reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x250), &m_fSecondLightParameter);
}

// @fnv 0x00c2c590
bool NiPSysDragModifier::IsEqual(NiObject* object) const
{
    NiPSysDragModifier* other = static_cast<NiPSysDragModifier*>(object);
    if (NiPSysModifier::IsEqual(other))
    {
        if (m_pParent && !other->m_pParent)
            return false;
        if (!m_pParent && other->m_pParent)
            return false;
        if (m_pParent && other->m_pParent && !m_pParent->IsEqual(other->m_pParent))
            return false;
        if (!(other->m_kDragDirection != m_kDragDirection) && other->m_fDragStrength == m_fDragStrength &&
            other->m_fFirstLightParameter == m_fFirstLightParameter &&
            other->m_fSecondLightParameter == m_fSecondLightParameter)
            return true;
    }
    return false;
}

// Reconstructed NiPSysDragModifier viewer-string routine.
struct StreamArray
{
    void** vtable;
    void* elements;
    unsigned short capacity;
    unsigned short size;
    unsigned short activeSize;
    unsigned short growBy;
    void FUN_0096ad30(unsigned int newCapacity);
    void FUN_0096ae90(unsigned int index, void* const* value);
    __forceinline void Append(void* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            FUN_0096ad30(index + growBy);
        FUN_0096ae90(index, &value);
    }
};
extern char DAT_0102909c;
extern char DAT_010bff18;
extern char DAT_010bff0c;
extern char DAT_010bff00;
extern char DAT_01062600;
extern char DAT_010bfef0;
void* __cdecl NiViewerStrings_NiGetViewerString_Title(void* object);
void* __cdecl NiGetViewerString_00a7d5e0(const void* typeName, const void* value);
void* __cdecl NiGetViewerString_00a7d550(const void* typeName, float value);
// Appends the base modifier strings, drag object name, drag axis, percentage, range and falloff to the viewer array.
// @fnv 0x00c2c620
void NiPSysDragModifier::GetDragViewerStrings(StreamArray& array)
{
    // NiPSysModifier does not yet declare its viewer-string override in the shared header.
    reinterpret_cast<ParticleViewerStringsCall*>(this)->GetViewerStrings(array);
    array.Append(NiViewerStrings_NiGetViewerString_Title(*reinterpret_cast<void**>(&g_01202768)));
    const char* name = m_pParent ? m_pParent->m_kName.m_kHandle : &DAT_0102909c;
    array.Append(NiGetViewerString_00a7d5e0(&DAT_010bff18, name));
    array.Append(m_kDragDirection.GetViewerString_00a59af0(&DAT_010bff0c));
    array.Append(NiGetViewerString_00a7d550(&DAT_010bff00, m_fDragStrength));
    array.Append(NiGetViewerString_00a7d550(&DAT_01062600, m_fFirstLightParameter));
    array.Append(NiGetViewerString_00a7d550(&DAT_010bfef0, m_fSecondLightParameter));
}
