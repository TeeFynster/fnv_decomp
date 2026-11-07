// gamebryo2.2/corelibs/nimain/nitexturingproperty.cpp: Holder, NiTexturingProperty, Map, MyThis and more (44 functions)

#include "../../../../include/NiTexturingProperty.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/BSShaderLightingProperty.h"
#include "../../../../include/NiDynamicEffect.h"
#include "../../../../include/NiTexture.h"
#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiDX92DBufferData.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiTPrimitiveArray.h"
#include "../../../../include/MemoryManager.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern MemoryManager g_memoryManager;

// The shared declaration exposes the operations; retain this unit's inline transfers.
inline unsigned int NiBinaryStream::BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
{
    unsigned int read = (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 8))(
        this, p, n, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += read;
    return read;
}
inline unsigned int NiBinaryStream::Read(void* p, unsigned int n)
{
    unsigned int size = n;
    return BinaryRead(p, n, &size, 1);
}
inline unsigned int NiBinaryStream::BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
{
    unsigned int written = (*reinterpret_cast<NIBINARYSTREAM_WRITEFN*>(reinterpret_cast<char*>(this) + 12))(
        this, p, n, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += written;
    return written;
}

// The shared stream declaration keeps these fields opaque.
inline unsigned int NiStream::GetFileVersion() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}
inline NiBinaryStream* TexturingOutputStream(NiStream& stream)
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x250);
}
template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.GetBinaryStream()->Read(&value, sizeof(T));
}

// Keep the inline operations used by this unit available with the shared declarations.
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew) {}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}
// Map::~Map releases its texture explicitly.
template <> inline NiPointer<NiTexture>::~NiPointer() {}
inline void NiTexture::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiTexture::DecRefCount()
{
    if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
        DeleteThis();
}
inline void NiObjectNET::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiObjectNET::DecRefCount()
{
    if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
        DeleteThis();
}
template <class T, class TAlloc> inline void* NiTArray<T, TAlloc>::operator new(size_t size)
{
    return g_memoryManager.Allocate(size);
}
template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::SetAt(unsigned int i, const T& value)
{
    if (i >= m_usSize)
    {
        m_usSize = (unsigned short)(i + 1);
        if (value)
            ++m_usESize;
    }
    else if (value)
    {
        if (!m_pBase[i])
            ++m_usESize;
    }
    else if (m_pBase[i])
        --m_usESize;
    m_pBase[i] = value;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int i, const T& value)
{
    if (i >= m_usMaxSize)
        SetSize(i + m_usGrowBy);
    SetAt(i, value);
    return i;
}
template <class T, class TAlloc> inline T& NiTArray<T, TAlloc>::GetAt(unsigned int i)
{
    return m_pBase[i];
}

class TextureMapTransform
{
  public:
    unsigned char data[0x48];
    TextureMapTransform() throw();
    void LoadBinary(NiStream&);
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
};

extern NiFixedString EmptyFS;
inline NiFixedString& NiFixedString::operator=(const char* string)
{
    if (m_kHandle != string)
    {
        char* old = m_kHandle;
        m_kHandle = NiGlobalStringTable::AddString(string);
        if (old != EmptyFS.m_kHandle)
            InterlockedDecrement(reinterpret_cast<volatile long*>(old - 8));
    }
    return *this;
}

// Inline bodies of the shared texture-map declarations.
inline NiTexturingProperty::Map::TexturePtr::TexturePtr(NiTexture* pkTexture) : m_pObject(pkTexture)
{
}
inline NiTexturingProperty::Map::Map() : m_usFlags(0), m_spTexture(0), m_pTextureTransform(0)
{
    SetClampMode(WRAP_S_WRAP_T);
    SetFilterMode(FILTER_BILERP);
    SetTextureIndex(0);
}
inline void* NiTexturingProperty::Map::operator new(size_t n)
{
    return g_memoryManager.Allocate(n);
}
inline void NiTexturingProperty::Map::SetClampMode(ClampMode mode)
{
    unsigned int flags = m_usFlags;
    m_usFlags = (flags & ~0x3000) | (mode << 12);
}
inline void NiTexturingProperty::Map::SetFilterMode(FilterMode mode)
{
    m_usFlags = (m_usFlags & ~0x0f00) | (mode << 8);
}
inline void NiTexturingProperty::Map::SetTextureIndex(unsigned int i)
{
    m_usFlags = (m_usFlags & ~0xff) | i;
}
inline NiTexturingProperty::ShaderMap::ShaderMap(unsigned int id) : m_uiID(id)
{
}

inline void NiTexturingProperty::SetApplyMode(ApplyMode mode)
{
    m_uiObjectFlags = (m_uiObjectFlags & ~0xe) | (mode << 1);
}
inline void NiTexturingProperty::SetMultiTexture(bool multi)
{
    if (multi)
        m_uiObjectFlags |= 1;
    else
        m_uiObjectFlags &= ~1;
}
inline void NiTexturingProperty::UpdateMultiTexture()
{
    unsigned int size = m_kStringArray.m_usSize;
    for (unsigned int i = 1; i < size; ++i)
        if (m_kStringArray.m_pBase[i])
        {
            SetMultiTexture(true);
            return;
        }
    SetMultiTexture(false);
}
inline void SetMapAt(NiTPrimitiveArray<NiTexturingProperty::Map*>& maps, unsigned int i, NiTexturingProperty::Map*& map)
{
    maps.SetAt(i, map);
}

typedef char CheckPropertySize[sizeof(NiTexturingProperty) == 0x30 ? 1 : -1];
typedef char CheckMapSize[sizeof(NiTexturingProperty::Map) == 0x10 ? 1 : -1];

// This placement overload retains the original allocation and constructor calls without
// introducing cleanup through the sized delete inherited from the shared NiProperty.
enum TexturingPropertyAllocation { TEXTURING_PROPERTY_ALLOCATION };
inline void* operator new(size_t size, TexturingPropertyAllocation)
{
    return NiMemObject::operator new(size);
}

// NiMain has no C++ exceptions: the out-of-line constructor LoadBinary calls does not unwind (no cleanup of the new)
template <> NiTPrimitiveArray<NiTexturingProperty::ShaderMap*>::NiTPrimitiveArray(unsigned int uiMaxSize, unsigned int uiGrowBy) throw();

// Loads the texturing property from a stream: apply mode, map array, optional shader maps, then calls UpdateMultiTexture.
// @fnv 0x00a6ad60
void NiTexturingProperty::LoadBinary(NiStream& stream)
{
    NiProperty::LoadBinary(stream);
    if (stream.GetFileVersion() < 0x14010002)
    {
        ApplyMode mode;
        ReadBinaryValue(stream, mode);
        SetApplyMode(mode);
    }
    else
    {
        ReadBinaryValue(stream, m_uiObjectFlags);
        m_uiObjectFlags &= ~0xff0;
    }
    unsigned int count;
    ReadBinaryValue(stream, count);
    unsigned int size = count;
    if (stream.GetFileVersion() < 0x14020005 && size > 6)
        size += 2;
    m_kStringArray.SetSize(size);
    if (stream.GetFileVersion() < 0x0303000d)
        stream.SetLinkIDCount(count + 1);
    else
        stream.SetLinkIDCount(count);
    for (unsigned int i = 0; i < count; ++i)
    {
        // Legacy streams store a four-byte presence value. A present entry
        // is replaced by its constructed map before insertion in the array.
        union
        {
            unsigned int presence;
            Map* map;
        } mapEntry;
        mapEntry.map = 0;
        unsigned int index = i;
        bool exists;
        if (stream.GetFileVersion() < 0x04010000)
        {
            ReadBinaryValue(stream, mapEntry.presence);
            exists = (mapEntry.presence != 0);
        }
        else
            ReadBinaryValue(stream, exists);
        if (stream.GetFileVersion() < 0x0303000d)
        {
            if (i >= 5)
            {
                stream.SetLinkIDCount(0);
                index++;
            }
        }
        else if (i == 5)
        {
            stream.SetLinkIDCount(exists);
            if (exists)
            {
                mapEntry.map = new BumpMap;
                mapEntry.map->LoadBinary(stream);
            }
            SetMapAt(m_kStringArray, 5, mapEntry.map);
            continue;
        }
        else if (i == 7 && stream.GetFileVersion() >= 0x14020005)
        {
            stream.SetLinkIDCount(exists);
            if (exists)
            {
                mapEntry.map = new ParallaxMap;
                mapEntry.map->LoadBinary(stream);
            }
            SetMapAt(m_kStringArray, 7, mapEntry.map);
            continue;
        }
        stream.SetLinkIDCount(exists);
        if (exists)
        {
            mapEntry.map = new Map;
            mapEntry.map->LoadBinary(stream);
        }
        m_kStringArray.SetAtGrow(index, mapEntry.map);
    }
    if (stream.GetFileVersion() >= 0x05000011)
    {
        ReadBinaryValue(stream, count);
        stream.SetLinkIDCount(count);
        if (count)
        {
            m_pShaderMaps = new NiTPrimitiveArray<ShaderMap*>(count);
            for (unsigned int i = 0; i < count; ++i)
            {
                bool exists;
                ReadBinaryValue(stream, exists);
                stream.SetLinkIDCount(exists);
                ShaderMap* map = 0;
                if (exists)
                {
                    ShaderMap* pLoadedShaderMap = new ShaderMap;
                    pLoadedShaderMap->LoadBinary(stream);
                    map = pLoadedShaderMap;
                }
                m_pShaderMaps->SetAt(i, map);
            }
        }
    }
    UpdateMultiTexture();
}

// @fnv 0x00a6b410
void NiTexturingProperty::InitializePoint3()
{
    ms_pDefaultProperty = ::new (TEXTURING_PROPERTY_ALLOCATION) NiTexturingProperty;
    ms_kTextureMapNames[0] = "Base";
    ms_kTextureMapNames[1] = "Dark";
    ms_kTextureMapNames[2] = "Detail";
    ms_kTextureMapNames[3] = "Gloss";
    ms_kTextureMapNames[4] = "Glow";
    ms_kTextureMapNames[5] = "Bump";
    ms_kTextureMapNames[6] = "Normal";
    ms_kTextureMapNames[7] = "Parallax";
    ms_kTextureMapNames[8] = "Decal";
    ms_kTextureMapNames[9] = "Shader";
}

// Reads a texture map's clamp mode, filter mode, texture index, and optional transform from the stream based on its version.
// @fnv 0x00a6b640
void NiTexturingProperty::Map::LoadBinary(NiStream& stream)
{
    stream.ResetStreamState();
    if (stream.GetFileVersion() < 0x14010002)
    {
        {
            ClampMode clamp;
            ReadBinaryValue(stream, clamp);
            SetClampMode(clamp);
        }
        {
            FilterMode filter;
            ReadBinaryValue(stream, filter);
            SetFilterMode(filter);
        }
        unsigned int index;
        ReadBinaryValue(stream, index);
        SetTextureIndex(index);
    }
    else
        ReadBinaryValue(stream, m_usFlags);
    if (stream.GetFileVersion() < 0x0a030004)
    {
        unsigned short unused;
        ReadBinaryValue(stream, unused);
        ReadBinaryValue(stream, unused);
    }
    if (stream.GetFileVersion() < 0x04010010)
    {
        unsigned short unused;
        ReadBinaryValue(stream, unused);
    }
    if (stream.GetFileVersion() >= 0x0a00010a)
    {
        m_pTextureTransform = 0;
        bool hasTransform;
        ReadBinaryValue(stream, hasTransform);
        if (hasTransform == true)
        {
            m_pTextureTransform = new TextureMapTransform;
            m_pTextureTransform->LoadBinary(stream);
        }
    }
}

void __fastcall NiDynamicEffect_DetachAllUnaffectedNodes(void* pThis);
void __fastcall ReleaseStorage_00a5a390(void* pThis);

extern const void* const g_NiDynamicEffectVTable[];

// @fnv 0x00a69030
void __fastcall DestroyDynamicEffect(NiDynamicEffect* apEffect)
{
    *reinterpret_cast<const void* const**>(apEffect) = g_NiDynamicEffectVTable;
    NiDynamicEffect_DetachAllUnaffectedNodes(apEffect);
    reinterpret_cast<BSShaderLightingProperty*>(&apEffect->unaffectedNodes)->ClearLights();
    reinterpret_cast<BSShaderLightingProperty*>(&apEffect->shadowGenerator)->ClearLights();
    ReleaseStorage_00a5a390(apEffect);
}

bool __fastcall VisitSkinGraphLinks(void* pThis, int, NiStream& kStream);

// @fnv 0x00a6c680
// src: XBOX_PDB 0x00a6c680
bool __fastcall BSDismemberSkinInstance_RegisterStreamables(void* pThis, int edx, NiStream& kStream)
{
    if (!VisitSkinGraphLinks(pThis, edx, kStream))
        return false;
    return true;
}

extern const char* const g_011f4a28_arg1;
// @fnv 0x00a69060
// src: COMMUNITY 0x00a69060
const char* const* NiDynamicEffect_GetRTTI()
{
    return &g_011f4a28_arg1;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct FUN_00a69e00
{
    unsigned short m_usFlags;
    void* m_spTexture;
    void* m_pkXform;
    FUN_00a69e00(void* tex, unsigned short a, short b, unsigned short c, void* xf);
    virtual void Dummy();
};
// @fnv 0x00a69e00
FUN_00a69e00::FUN_00a69e00(void* apTexture, unsigned short ausLowFlags, short asMidFlags, unsigned short ausHighFlags,
                           void* apXform)
{
    m_usFlags = 0;
    m_spTexture = apTexture;
    if (apTexture)
        InterlockedIncrement(reinterpret_cast<volatile long*>(reinterpret_cast<unsigned char*>(apTexture) + 4));
    m_pkXform = apXform;
    m_usFlags = (((((asMidFlags << 4) | ausHighFlags) << 8) | (m_usFlags & 0xc0ff)) & 0xff00) | ausLowFlags;
}

// @fnv 0x00a6a000
// src: COMMUNITY 0x00a6a000
int NiShadeProperty_Type()
{
    return 3;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f49a4;
// @fnv 0x00a6a140
// src: COMMUNITY 0x00a6a140
GlobalObjectO2_00a7b610* NiTexturingProperty_GetRTTI()
{
    return &g_011f49a4;
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];

struct TexturingPropertyCopyOperation
{
    void CloneTo(NiTexturingProperty*, CloningProcess*);
};
// @fnv 0x00a6c610
NiObject* __fastcall CloneTexturingProperty(NiTexturingProperty* self, int, CloningProcess* pCloningProcess)
{
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(self) + 0xc))
    {
        NiTexturingProperty* p = ::new (TEXTURING_PROPERTY_ALLOCATION) NiTexturingProperty;
        reinterpret_cast<TexturingPropertyCopyOperation*>(self)->CloneTo(p, pCloningProcess);
        return p;
    }
    self->CopyMembersStream(self, pCloningProcess);
    return self;
}

struct Elem4
{
    unsigned char a;
    unsigned char b;
    unsigned short c;
};
struct EqObj
{
    bool FUN_00a864d0(EqObj*);
    unsigned int m_auiShapeKeys[13];
    unsigned int m_uiCount;
    Elem4* m_pElems;
};
// Returns true if the base comparison passes, the counts match, and every element's a, b and c fields are equal.
// @fnv 0x00a6c6a0
// src: XBOX_PDB 0x00a6c6a0
bool __fastcall BSDismemberSkinInstance_IsEqual(EqObj* self, int, EqObj* other)
{
    if (!self->FUN_00a864d0(other))
        return false;
    if (self->m_uiCount != other->m_uiCount)
        return false;
    for (unsigned int i = 0; i < self->m_uiCount; i++)
    {
        const Elem4& x = other->m_pElems[i];
        const Elem4& y = self->m_pElems[i];
        if (y.a != x.a || y.b != x.b || y.c != x.c)
            return false;
    }
    return true;
}

int NiSprintf(char* dst, int size, const char* fmt, ...);
void* NiMalloc(unsigned int size);
extern "C" size_t __cdecl strlen(const char*);

// Allocates a string and formats prefix with a texture address-mode suffix selected by mode, defaulting to UNKNOWN!!!.
// @fnv 0x00a69b90
char* BuildTextureAddressModeString(const char* prefix, int mode)
{
    char* result;
    unsigned int len;
    {
        len = strlen(prefix);
    }
    result = (char*)NiMalloc(len + 0x14);
    switch (mode)
    {
    case 0:
        NiSprintf(result, len + 0x14, "%s = CLAMP_S_CLAMP_T", prefix);
        break;
    case 1:
        NiSprintf(result, len + 0x14, "%s = CLAMP_S_WRAP_T", prefix);
        break;
    case 2:
        NiSprintf(result, len + 0x14, "%s = WRAP_S_CLAMP_T", prefix);
        break;
    case 3:
        NiSprintf(result, len + 0x14, "%s = WRAP_S_WRAP_T", prefix);
        break;
    default:
        NiSprintf(result, len + 0x14, "%s = UNKNOWN!!!", prefix);
        break;
    }
    return result;
}

int _NiStricmp(const char*, const char*);
inline bool MapNameEqual(const char* a, const char* b)
{
    if (a == b)
        return true;
    if (!b || !a)
        return false;
    return _NiStricmp(a, b) == 0;
}
// Searches the ten texture map handles for one matching pkName and, on a match, stores its index in puiID and returns true.
// @fnv 0x00a69d80
bool FindTextureMapIndexByName(NiFixedString* pkName, unsigned int* puiID)
{
    for (unsigned int i = 0; i < 10; i++)
    {
        if (MapNameEqual(NiTexturingProperty::ms_kTextureMapNames[i].m_kHandle, pkName->m_kHandle))
        {
            *puiID = i;
            return true;
        }
    }
    return false;
}

struct S8
{
    int _p[4];
    int _v;
    bool IsEquivalent(S8*);
    unsigned char IsEquivalentIncludingValue(S8*);
};
// Returns 0 if IsEquivalent fails, otherwise returns whether _v equals o->_v.
// @fnv 0x00a69f50
// src: GUESS 0x00a69f50 (confidence: medium)
unsigned char S8::IsEquivalentIncludingValue(S8* pOther)
{
    if (!IsEquivalent(pOther))
        return 0;
    return _v == pOther->_v;
}

void __cdecl _NiFreeAlias(void*);
struct DeallocHelper
{
    void _DeallocateAlias(void*);
};
extern int DAT_0109c394;
// The scalar deleting destructors use the shared array layouts. Keep the
// entry-point wrappers here because C++ cannot name a scalar deleting destructor.
// @fnv 0x00a6a050
void* __fastcall DestroyTextureMapArrayBase(
    NiTArray<NiTexturingProperty::Map*, NiTMallocInterface<NiTexturingProperty::Map*> >* self,
    int, unsigned int flags)
{
    void* elements = self->m_pBase;
    *reinterpret_cast<void**>(self) = &DAT_0109c394;
    _NiFreeAlias(elements);
    if (flags & 1)
        reinterpret_cast<DeallocHelper*>(&g_memoryManager)->_DeallocateAlias(self);
    return self;
}

extern int DAT_0109c39c;
// @fnv 0x00a6a080
void* __fastcall DestroyShaderMapArrayBase(
    NiTArray<NiTexturingProperty::ShaderMap*, NiTMallocInterface<NiTexturingProperty::ShaderMap*> >* self,
    int, unsigned int flags)
{
    void* elements = self->m_pBase;
    *reinterpret_cast<void**>(self) = &DAT_0109c39c;
    _NiFreeAlias(elements);
    if (flags & 1)
        reinterpret_cast<DeallocHelper*>(&g_memoryManager)->_DeallocateAlias(self);
    return self;
}

void __fastcall NiTexturingPropertyDestructor(NiTexturingProperty*);
void __cdecl _delete(void*, unsigned int);
// @fnv 0x00a6ab90
void* __fastcall DestroyTexturingProperty(NiTexturingProperty* self, int, unsigned int flags)
{
    NiTexturingPropertyDestructor(self);
    if (flags & 1)
        _delete(self, 0x30);
    return self;
}

struct MyThis
{
    void LoadMapBinary(NiStream&);
};
// Loads the base map from the stream, then reads a 4-byte value into the object at offset 0x10.
// @fnv 0x00a6ba80
void MyThis::LoadMapBinary(NiStream& stream)
{
    ((NiTexturingProperty::Map*)this)->NiTexturingProperty::Map::LoadBinary(stream);
    NiBinaryStream* __restrict input = stream.GetBinaryStream();
    unsigned int size = 4;
    input->BinaryRead((char*)this + 0x10, 4, &size, 1);
}

// NiDX92DBufferData::ms_apkCurrentBuffer and ms_uiNumBuffers.
extern void* DAT_0126f580[];
extern int DAT_0126f594;
struct FakeVT
{
    void* _p[37];
    long(__stdcall* SetRenderTarget)(void*, unsigned int, void*);
};
struct FakeDev
{
    FakeVT* vt;
};
// Makes the MSAA surface, else the surface, render target uiTarget of the device unless it already is.
// @fnv 0x00e7cd50
bool NiDX92DBufferData::SetRenderTarget(IDirect3DDevice9* pkD3DDevice9, unsigned int uiTarget)
{
    void* pDev = pkD3DDevice9;
    void* pSurface = m_pkSurface;
    if (pSurface)
    {
        if (uiTarget > (unsigned int)DAT_0126f594)
            return false;
        if (m_pkMSAASurface)
            pSurface = m_pkMSAASurface;
        if (pSurface != DAT_0126f580[uiTarget])
        {
            long hr = ((FakeDev*)pDev)->vt->SetRenderTarget(pDev, uiTarget, pSurface);
            if (hr < 0)
                return false;
            DAT_0126f580[uiTarget] = pSurface;
        }
        return true;
    }
    return false;
}

struct S_A69F80
{
    char _pad[16];
    float m_10;
    bool IsEquivalent(S_A69F80*);
    bool MatchesValue(S_A69F80*);
};
// Returns true if IsEquivalent succeeds and m_10 equals pkObject->m_10, otherwise false.
// @fnv 0x00a69f80
bool S_A69F80::MatchesValue(S_A69F80* pkObject)
{
    if (!IsEquivalent(pkObject))
        return false;
    if (m_10 != pkObject->m_10)
        return false;
    return true;
}

namespace fnv_00a6bac0 {
struct MapBase
{
    void NiTexturingProperty_Map_SaveBinary(NiStream&);
};
struct Holder
{
    char _pad[16];
    int _v;
    void WriteToStream(NiStream&);
};
// Calls the base class stream writer, then writes the 4-byte value at this+16 to the stream and advances its position.
// @fnv 0x00a6bac0
void Holder::WriteToStream(NiStream& aStream)
{
    ((MapBase*)this)->NiTexturingProperty_Map_SaveBinary(aStream);
    NiBinaryStream* __restrict ostr = TexturingOutputStream(aStream);
    unsigned int size = 4;
    ostr->BinaryWrite(&this->_v, 4, &size, 1);
}
}  // namespace fnv_00a6bac0

namespace fnv_00a69ed0 {
struct S8
{
    float m_kPointA[5];
    bool IsEquivalent(S8*);
    bool EvaluateValue_00a69ed0(S8*);
};

// @fnv 0x00a69ed0
// src: GUESS 0x00a69ed0 (confidence: low)
bool S8::EvaluateValue_00a69ed0(S8* apOther)
{
    if (IsEquivalent(apOther))
    {
        if (m_kPointA[4] == apOther->m_kPointA[4] && m_kPointA[5] == apOther->m_kPointA[5] && m_kPointA[6] == apOther->m_kPointA[6] &&
            m_kPointA[7] == apOther->m_kPointA[7] && m_kPointA[8] == apOther->m_kPointA[8] && m_kPointA[9] == apOther->m_kPointA[9])
            return true;
    }
    return false;
}
}  // namespace fnv_00a69ed0

void* _NiMalloc(unsigned int);
int _NiSprintf(char*, unsigned int, const char*, ...);

// Allocates a string sized to pcPrefix plus 30 and formats it as "<pcPrefix> = FILTER_..." based on eMode, defaulting to UNKNOWN!!!.
// @fnv 0x00a69c50
char* BuildFilterModeString(const char* pcPrefix, unsigned int eMode)
{
    char* pcString;
    unsigned int uiBufferSize;

    uiBufferSize = static_cast<unsigned int>(strlen(pcPrefix)) + 30;
    pcString = static_cast<char*>(_NiMalloc(uiBufferSize));

    switch (eMode)
    {
    case 0:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_NEAREST", pcPrefix);
        break;

    case 1:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_BILERP", pcPrefix);
        break;

    case 2:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_TRILERP", pcPrefix);
        break;

    case 3:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_NEAREST_MIPNEAREST", pcPrefix);
        break;

    case 4:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_NEAREST_MIPLERP", pcPrefix);
        break;

    case 5:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_BILERP_MIPNEAREST", pcPrefix);
        break;

    case 6:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_ANISO", pcPrefix);
        break;

    case 7:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_MAGLERP_MINANISO", pcPrefix);
        break;

    default:
        _NiSprintf(pcString, uiBufferSize, "%s = UNKNOWN!!!", pcPrefix);
        break;
    }

    return pcString;
}

// @fnv 0x00a6ad40
NiTexturingProperty* CreateTexturingProperty()
{
    return ::new (TEXTURING_PROPERTY_ALLOCATION) NiTexturingProperty;
}

// Initializes the map's luma scale/offset and bump matrix fields to their default values.
// @fnv 0x00a69fb0
NiTexturingProperty::BumpMap::BumpMap() throw()
    : m_fLumaScale(1.0f), m_fLumaOffset(0.0f), m_fBumpMat00(0.5f), m_fBumpMat01(0.0f), m_fBumpMat10(0.0f),
      m_fBumpMat11(0.5f)
{}

struct TexturingStreamableBase
{
    bool NiSequenceStreamHelper_RegisterStreamables(unsigned int);
};

// @fnv 0x00a6a560
bool NiTexturingProperty::RegisterStreamables(NiStream& stream)
{
    if (!reinterpret_cast<TexturingStreamableBase*>(this)->NiSequenceStreamHelper_RegisterStreamables(reinterpret_cast<unsigned int>(&stream)))
    {
        return false;
    }
    for (unsigned int i = 0; i < m_kStringArray.m_usSize; ++i)
    {
        NiTexturingProperty::Map* map = m_kStringArray.m_pBase[i];
        if (map != 0)
        {
            NiTexture* tex = map->m_spTexture.m_pObject;
            if (tex != 0)
            {
                tex->RegisterStreamables(stream);
            }
        }
    }
    if (m_pShaderMaps != 0)
    {
        for (unsigned int j = 0; j < m_pShaderMaps->m_usSize; ++j)
        {
            NiTexturingProperty::Map* map = m_pShaderMaps->m_pBase[j];
            if (map != 0)
            {
                NiTexture* tex = map->m_spTexture.m_pObject;
                if (tex != 0)
                {
                    tex->RegisterStreamables(stream);
                }
            }
        }
    }
    return true;
}

void* NiMalloc(unsigned int size);
NiTexture* NiSourceTexture_Create(void* pkPrefs, const char* pcName, void* pkOther);

struct TexMapStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    TexMapStub(NiTexture* pkTexture, unsigned int uiIndex, int eClamp, int eFilter,
               TextureMapTransform* pkXform) throw();
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
};

template <> inline NiTArray<NiTexturingProperty::Map*, NiTMallocInterface<NiTexturingProperty::Map*> >::NiTArray(
    unsigned int maxSize, unsigned int growBy)
{
    m_usMaxSize = (unsigned short)maxSize;
    m_usGrowBy = (unsigned short)growBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = (NiTexturingProperty::Map**)NiMalloc(sizeof(NiTexturingProperty::Map*) * m_usMaxSize);
    else
        m_pBase = 0;
}
template <> inline NiTPrimitiveArray<NiTexturingProperty::Map*>::NiTPrimitiveArray(unsigned int size, unsigned int grow) throw()
    : NiTArray<NiTexturingProperty::Map*, NiTMallocInterface<NiTexturingProperty::Map*> >(size, grow)
{}
inline void SetTexturingMapAt(NiTPrimitiveArray<NiTexturingProperty::Map*>& maps, unsigned int i, NiTexturingProperty::Map* map)
{
    SetMapAt(maps, i, map);
}

// The original constructor's initialization calls do not unwind.
__forceinline void InitializeTexturingProperty(NiTexturingProperty* self, NiPixelData* pkPrefs,
    const NiFixedString& kName, TextureFormatPreferences& kOther) throw()
{
    self->m_pShaderMaps = 0;
    const char* pcName = kName.m_kHandle;
    NiTexture* pkTexture = NiSourceTexture_Create(pkPrefs, pcName, &kOther);
    SetTexturingMapAt(self->m_kStringArray, 0, (NiTexturingProperty::Map*)new TexMapStub(pkTexture, 0, 3, 1, 0));
    SetTexturingMapAt(self->m_kStringArray, 1, 0);
    SetTexturingMapAt(self->m_kStringArray, 2, 0);
    SetTexturingMapAt(self->m_kStringArray, 3, 0);
    SetTexturingMapAt(self->m_kStringArray, 4, 0);
    SetTexturingMapAt(self->m_kStringArray, 5, 0);
    SetTexturingMapAt(self->m_kStringArray, 6, 0);
    SetTexturingMapAt(self->m_kStringArray, 7, 0);
    SetTexturingMapAt(self->m_kStringArray, 8, 0);
    self->m_uiObjectFlags &= 0xf00f;
    unsigned int size = self->m_kStringArray.m_usSize;
    unsigned int i;
    for (i = 1; i < size; ++i)
    {
        if (self->m_kStringArray.m_pBase[i])
        {
            self->m_uiObjectFlags |= 1;
            goto done;
        }
    }
    self->m_uiObjectFlags &= ~1;
done:
    self->m_uiObjectFlags = (self->m_uiObjectFlags & ~0xe) | (2 << 1);
}

// @fnv 0x00a6abb0
NiTexturingProperty::NiTexturingProperty(NiPixelData* pkPrefs, const NiFixedString& kName, TextureFormatPreferences& kOther)
    : m_uiObjectFlags(0), m_kStringArray(9, 1)
{
    InitializeTexturingProperty(this, pkPrefs, kName, kOther);
}

inline unsigned int NiBinaryWrite(NiBinaryStream* pkStr, const void* pvBuffer, unsigned int uiBytes)
{
    unsigned int uiSize = uiBytes;
    return pkStr->BinaryWrite(pvBuffer, uiBytes, &uiSize, 1);
}

template <class T> inline void SerializeValue(NiStream& kStream, const T& value)
{
    NiBinaryWrite(TexturingOutputStream(kStream), &value, sizeof(T));
}

struct NiPropertySaveStub
{
    void SaveBinary(NiStream& kStream);
};

// Saves the base map array and optional shader map array to the stream, writing a count and a presence flag plus data for each map.
// @fnv 0x00a6b250
void __fastcall SaveTexturingProperty(NiTexturingProperty* self, int, NiStream& kStream)
{
    reinterpret_cast<NiPropertySaveStub*>(self)->SaveBinary(kStream);

    SerializeValue(kStream, self->m_uiObjectFlags);

    unsigned int uiNumMaps = self->m_kStringArray.m_usSize;
    SerializeValue(kStream, uiNumMaps);
    unsigned int i;
    for (i = 0; i < uiNumMaps; i++)
    {
        NiTexturingProperty::Map* pkMap = self->m_kStringArray.m_pBase[i];
        bool bMap = (pkMap != 0);
        SerializeValue(kStream, bMap);
        if (bMap)
            pkMap->SaveBinary(kStream);
    }

    if (self->m_pShaderMaps)
    {
        uiNumMaps = self->m_pShaderMaps->m_usSize;
        SerializeValue(kStream, uiNumMaps);
        for (i = 0; i < uiNumMaps; i++)
        {
            NiTexturingProperty::ShaderMap* pkMap = self->m_pShaderMaps->m_pBase[i];
            bool bMap = (pkMap != 0);
            SerializeValue(kStream, bMap);
            if (bMap)
                pkMap->SaveBinary(kStream);
        }
    }
    else
    {
        uiNumMaps = 0;
        SerializeValue(kStream, uiNumMaps);
    }
}

class A6B830Object;

class A6B830Stream
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void SaveLinkID(A6B830Object* pkObject);
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
    int unk030;
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
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    NiBinaryStream* m_pBackingStream;
};

template <class T>
inline void NiBinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A6B830SaveBinary(A6B830Stream& kStream, const T& value)
{
    NiBinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class A6B830Child
{
  public:
    void SaveBinary(A6B830Stream& kStream);
};

class A6B830Helper
{
  public:
    void NiTexturingProperty_Map_SaveBinary(A6B830Stream& kStream);

    int unk00;
    unsigned short m_usFlags;
    short unk06;
    A6B830Object* m_pkTarget;
    A6B830Child* m_pkChild;
};

// Writes the target link ID, flags, a child-present flag and, if present, the child's binary data to the stream.
// @fnv 0x00a6b830
// src: COMMUNITY 0x00a6b830
void A6B830Helper::NiTexturingProperty_Map_SaveBinary(A6B830Stream& kStream)
{
    kStream.SaveLinkID(m_pkTarget);
    A6B830SaveBinary(kStream, m_usFlags);
    bool bHasChild = m_pkChild != 0;
    A6B830SaveBinary(kStream, bHasChild);
    if (m_pkChild)
        m_pkChild->SaveBinary(kStream);
}

// NiTexturingProperty::BumpMap::LoadBinary
class A6B8C0BumpMap : public NiTexturingProperty::BumpMap
{
  public:
    void NiTexturingProperty_BumpMap_LoadBinary(NiStream& kStream);
};

// Loads the base map data from kStream, then reads six float values into the bump map's luma and matrix fields.
// @fnv 0x00a6b8c0
// src: COMMUNITY 0x00a6b8c0
void A6B8C0BumpMap::NiTexturingProperty_BumpMap_LoadBinary(NiStream& kStream)
{
    Map::LoadBinary(kStream);
    ReadBinaryValue(kStream, m_fLumaScale);
    ReadBinaryValue(kStream, m_fLumaOffset);
    ReadBinaryValue(kStream, m_fBumpMat00);
    ReadBinaryValue(kStream, m_fBumpMat01);
    ReadBinaryValue(kStream, m_fBumpMat10);
    ReadBinaryValue(kStream, m_fBumpMat11);
}

struct S_00a6b9a0_Stream
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    NiBinaryStream* unk250;
};
struct S_00a6b9a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    void NiTexturingProperty_Map_SaveBinary(S_00a6b9a0_Stream*);
    void ReadFromStream(S_00a6b9a0_Stream* s);
};
// Calls FUN_00a6b830, then writes six 4-byte values from unk10 through unk24 to the stream.
// @fnv 0x00a6b9a0
void S_00a6b9a0::ReadFromStream(S_00a6b9a0_Stream* pStream)
{
    NiTexturingProperty_Map_SaveBinary(pStream);
    NiBinaryWrite(pStream->unk250, &unk10, 4);
    NiBinaryWrite(pStream->unk250, &unk14, 4);
    NiBinaryWrite(pStream->unk250, &unk18, 4);
    NiBinaryWrite(pStream->unk250, &unk1c, 4);
    NiBinaryWrite(pStream->unk250, &unk20, 4);
    NiBinaryWrite(pStream->unk250, &unk24, 4);
}

// Equality of two texture descriptors: equal source objects, same flags, and matching image data.

template <class T> class A9E60Pointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }

    T* m_pObject;
};

class A9E60Object
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual bool IsEqual(A9E60Object* pkOther);
};

class A9E60Data
{
  public:
    bool IsDifferent(A9E60Data* pkOther);
};

class A9E60Desc
{
  public:
    int unk00;
    unsigned short m_usFlags;
    unsigned short unk06;
    A9E60Pointer<A9E60Object> m_spSource;
    A9E60Pointer<A9E60Data> m_spTransformData;

    bool IsEquivalent(const A9E60Desc& kOther) const;
};

// @fnv 0x00a69e60
bool A9E60Desc::IsEquivalent(const A9E60Desc& kOther) const
{
    if (!m_spSource && kOther.m_spSource)
        return false;
    if (m_spSource && !m_spSource->IsEqual(kOther.m_spSource))
        return false;
    if (m_usFlags != kOther.m_usFlags)
        return false;
    if (m_spTransformData && kOther.m_spTransformData)
    {
        if (m_spTransformData->IsDifferent(kOther.m_spTransformData))
            return false;
    }
    else
    {
        if (!m_spTransformData && kOther.m_spTransformData)
            return false;
        if (m_spTransformData && !kOther.m_spTransformData)
            return false;
    }
    return true;
}

extern int DAT_0109c514;
// Sets the vtable, deletes the texture array elements and the second array, frees the base array and runs the NiProperty destructor.
// @fnv 0x00a6a0b0
void __fastcall NiTexturingPropertyDestructor(NiTexturingProperty* pThis)
{
    *reinterpret_cast<void**>(pThis) = &DAT_0109c514;
    for (unsigned int i = 0; i < pThis->m_kStringArray.m_usSize; ++i)
    {
        delete pThis->m_kStringArray.m_pBase[i];
    }
    if (pThis->m_pShaderMaps)
    {
        for (unsigned int i = 0; i < pThis->m_pShaderMaps->m_usSize; ++i)
        {
            delete pThis->m_pShaderMaps->m_pBase[i];
        }
        delete pThis->m_pShaderMaps;
    }
    *reinterpret_cast<void**>(&pThis->m_kStringArray) = &DAT_0109c394;
    _NiFreeAlias(pThis->m_kStringArray.m_pBase);
    pThis->NiProperty::~NiProperty();
}

struct Sub2c
{
    unsigned int unk00;
    void** m_04;
    unsigned char unk08[2];
    unsigned short m_0a;
};

struct Elem5
{
    bool EvaluateValue_00a69ed0(Elem5*);
};

struct TexturingEqualityBase
{
    bool NiSequenceStreamHelper_IsEqual(NiTexturingProperty*);
};

// @fnv 0x00a6a5f0
bool __fastcall TexturingPropertiesEqual(NiTexturingProperty* self, int, NiTexturingProperty* other)
{
    if (!reinterpret_cast<TexturingEqualityBase*>(self)->NiSequenceStreamHelper_IsEqual(other))
        return false;
    if (self->m_uiObjectFlags != other->m_uiObjectFlags)
        return false;
    unsigned int uiOtherCount = other->m_kStringArray.m_usSize;
    unsigned int n = self->m_kStringArray.m_usSize;
    if (n != uiOtherCount)
        return false;
    for (unsigned int i = 0; i < n; ++i)
    {
        void* a = self->m_kStringArray.m_pBase[i];
        void* b = other->m_kStringArray.m_pBase[i];
        if (a != 0)
        {
            if (b == 0)
                goto fail;
            if (i == 5)
            {
                if (!reinterpret_cast<Elem5*>(a)->EvaluateValue_00a69ed0(reinterpret_cast<Elem5*>(b)))
                    goto fail;
            }
            else if (i == 7)
            {
                if (!reinterpret_cast<S_A69F80*>(a)->MatchesValue(reinterpret_cast<S_A69F80*>(b)))
                    goto fail;
            }
            else
            {
                if (!reinterpret_cast<S8*>(a)->IsEquivalent(reinterpret_cast<S8*>(b)))
                    goto fail;
            }
        }
        else if (b != 0)
        {
            goto fail;
        }
    }
    if (self->m_pShaderMaps != 0)
    {
        if (other->m_pShaderMaps == 0)
            return false;
        unsigned int uiSubCount = self->m_pShaderMaps->m_usSize;
        if (uiSubCount != other->m_pShaderMaps->m_usSize)
            return false;
        for (unsigned int i = 0; i < uiSubCount; ++i)
        {
            void* x = self->m_pShaderMaps->m_pBase[i];
            void* y = other->m_pShaderMaps->m_pBase[i];
            if (x != 0)
            {
                if (y == 0)
                    return false;
                if (!reinterpret_cast<S8*>(x)->IsEquivalentIncludingValue(reinterpret_cast<S8*>(y)))
                    return false;
            }
            else if (y != 0)
            {
                return false;
            }
        }
        return true;
    }
    if (other->m_pShaderMaps == 0)
        return true;
fail:
    return false;
}

void* NiMalloc(unsigned int size);

template <> inline NiTArray<NiTexturingProperty::ShaderMap*, NiTMallocInterface<NiTexturingProperty::ShaderMap*> >::NiTArray(
    unsigned int maxSize, unsigned int growBy)
{
    m_usMaxSize = (unsigned short)maxSize;
    m_usGrowBy = (unsigned short)growBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
    {
        unsigned int uiBytes = m_usMaxSize;
        m_pBase = (NiTexturingProperty::ShaderMap**)NiMalloc(sizeof(void*) * uiBytes);
    }
    else
        m_pBase = 0;
}

// Constructs the shader-map array with the original maximum size and growth increment.
// @fnv 0x00a6a990
template <> NiTPrimitiveArray<NiTexturingProperty::ShaderMap*>::NiTPrimitiveArray(unsigned int uiMaxSize, unsigned int uiGrowBy) throw()
    : NiTArray<NiTexturingProperty::ShaderMap*, NiTMallocInterface<NiTexturingProperty::ShaderMap*> >(uiMaxSize, uiGrowBy)
{}

// Preserve the viewer's inline append operations on the shared array layout.
__forceinline void AppendString(NiTPrimitiveArray<char*>* strings, char*& value)
{
    unsigned int index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);
}
__forceinline void AppendStringInline(NiTPrimitiveArray<char*>* strings, char* value)
{
    unsigned int index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    if (index >= strings->m_usSize)
    {
        strings->m_usSize = (unsigned short)(index + 1);
        if (value)
            ++strings->m_usESize;
    }
    else if (value)
    {
        if (!strings->m_pBase[index])
            ++strings->m_usESize;
    }
    else if (strings->m_pBase[index])
        --strings->m_usESize;
    strings->m_pBase[index] = value;
}

__forceinline void AddString(NiTPrimitiveArray<char*>* strings, char*& value)
{
    strings->AddFirstEmpty(value);
}

struct GlobalObjectO2_00a7b610
{
    char* m_pcName;
};
extern GlobalObjectO2_00a7b610 g_011f49a4;
int __cdecl NiSprintf(char*, unsigned int, const char*, ...);
char* BuildTextureAddressModeString(const char*, int);
char* BuildFilterModeString(const char*, int);
char* NiViewerStrings_NiGetViewerString_Title(char*);
char* NiGetViewerString_00a7d4d0(const char*, int);
char* NiGetViewerString_00a7d510(const char*, unsigned int);
char* NiGetViewerString_00a7d550(const char*, float);
char* NiGetViewerString_00a7d5a0(const char*, void*);
struct FUN_00a62a40_this
{
    void AppendString(NiTPrimitiveArray<char*>*);
};

struct MapEx : NiTexturingProperty::Map
{
    inline NiTexturingProperty::ClampMode GetClampMode() const
    {
        return (NiTexturingProperty::ClampMode)((m_usFlags >> 12) & 3);
    }
    inline NiTexturingProperty::FilterMode GetFilterMode() const
    {
        return (NiTexturingProperty::FilterMode)((m_usFlags >> 8) & 15);
    }
    inline unsigned int GetTextureIndex() const
    {
        return m_usFlags & 0xff;
    }
};

struct ShaderMapEx : NiTexturingProperty::ShaderMap
{
    inline NiTexturingProperty::ClampMode GetClampMode() const
    {
        return (NiTexturingProperty::ClampMode)((m_usFlags >> 12) & 3);
    }
    inline NiTexturingProperty::FilterMode GetFilterMode() const
    {
        return (NiTexturingProperty::FilterMode)((m_usFlags >> 8) & 15);
    }
    inline unsigned int GetTextureIndex() const
    {
        return m_usFlags & 0xff;
    }
};

// Appends the property name, apply mode, and per-map details (texture, clamp/filter mode, coord index) for each texture and shader map to strings.
// @fnv 0x00a6bdd0
void __fastcall AppendTexturingPropertyInfo(NiTexturingProperty* self, int, NiTPrimitiveArray<char*>* strings)
{
    reinterpret_cast<FUN_00a62a40_this*>(self)->AppendString(strings);
    {
        char* header = NiViewerStrings_NiGetViewerString_Title(g_011f49a4.m_pcName);
        AppendString(strings, header);
    }
    unsigned int count = self->m_kStringArray.m_usSize;
    char prefix[64];
    {
        union
        {
            char* text;
            float scalar;
        };
        char acApplyMode[64];
        char acDecalLabel[64];
        NiSprintf(acApplyMode, 64, "ApplyMode ");
        int mode = (self->m_uiObjectFlags >> 1) & 7;
        text = NiGetViewerString_00a7d4d0(acApplyMode, mode);
        AppendString(strings, text);
        for (unsigned int i = 0; i < count; ++i)
        {
            NiTexturingProperty::Map* map = self->m_kStringArray.m_pBase[i];
            if (!map)
                continue;
            switch (i)
            {
            case 0:
                text = NiGetViewerString_00a7d510("MultiTexture Base Map", i);
                AddString(strings, text);
                break;
            case 1:
                text = NiGetViewerString_00a7d510("MultiTexture Dark Map", i);
                AddString(strings, text);
                break;
            case 2:
                text = NiGetViewerString_00a7d510("MultiTexture Detail Map", i);
                AddString(strings, text);
                break;
            case 3:
                text = NiGetViewerString_00a7d510("MultiTexture Gloss Map", i);
                AddString(strings, text);
                break;
            case 4:
                text = NiGetViewerString_00a7d510("MultiTexture Glow Map", i);
                AddString(strings, text);
                break;
            case 5: {
                text = NiGetViewerString_00a7d510("MultiTexture Bump Map", i);
                AddString(strings, text);
                NiTexturingProperty::BumpMap* pBumpMap = static_cast<NiTexturingProperty::BumpMap*>(map);
                scalar = pBumpMap->m_fLumaScale;
                text = NiGetViewerString_00a7d550("m_fLumaScale", scalar);
                AddString(strings, text);
                scalar = pBumpMap->m_fLumaOffset;
                text = NiGetViewerString_00a7d550("m_fLumaOffset", scalar);
                AddString(strings, text);
                scalar = pBumpMap->m_fBumpMat00;
                text = NiGetViewerString_00a7d550("m_fBumpMat00", scalar);
                AddString(strings, text);
                scalar = pBumpMap->m_fBumpMat01;
                text = NiGetViewerString_00a7d550("m_fBumpMat01", scalar);
                AddString(strings, text);
                scalar = pBumpMap->m_fBumpMat10;
                text = NiGetViewerString_00a7d550("m_fBumpMat10", scalar);
                AddString(strings, text);
                scalar = pBumpMap->m_fBumpMat11;
                text = NiGetViewerString_00a7d550("m_fBumpMat11", scalar);
                AddString(strings, text);
                break;
            }
            case 6:
                text = NiGetViewerString_00a7d510("MultiTexture Normal Map", i);
                AddString(strings, text);
                break;
            case 7: {
                text = NiGetViewerString_00a7d510("MultiTexture Parallax Map", i);
                AddString(strings, text);
                scalar = static_cast<NiTexturingProperty::ParallaxMap*>(map)->m_fParallaxOffset;
                text = NiGetViewerString_00a7d550("m_fParallaxOffset", scalar);
                AddString(strings, text);
                break;
            }
            default: {
                NiSprintf(acDecalLabel, 64, "MultiTexture Decal Map %d", i - 8);
                text = NiGetViewerString_00a7d510(acDecalLabel, i);
                AppendString(strings, text);
                break;
            }
            }
            NiSprintf(prefix, 64, "m_spTexture ");
            void* tex = map->m_spTexture.m_pObject;
            text = NiGetViewerString_00a7d5a0(prefix, tex);
            AppendString(strings, text);
            NiSprintf(prefix, 64, "Clamp Mode ");
            text = BuildTextureAddressModeString(prefix, static_cast<MapEx*>(map)->GetClampMode());
            AppendString(strings, text);
            NiSprintf(prefix, 64, "Filter Mode");
            text = BuildFilterModeString(prefix, static_cast<MapEx*>(map)->GetFilterMode());
            AppendString(strings, text);
            NiSprintf(prefix, 64, "Texture Coord Index ");
            unsigned int uiTexCoordIndex = static_cast<MapEx*>(map)->GetTextureIndex();
            text = NiGetViewerString_00a7d510(prefix, uiTexCoordIndex);
            AppendString(strings, text);
        }
    }
    if (self->m_pShaderMaps)
    {
        count = self->m_pShaderMaps->m_usSize;
        for (unsigned int j = 0; j < count; ++j)
        {
            NiTexturingProperty::ShaderMap* map = self->m_pShaderMaps->m_pBase[j];
            if (!map)
                continue;
            AppendStringInline(strings, NiGetViewerString_00a7d510("Shader Map", j));
            unsigned int uiShaderID = map->m_uiID;
            AppendStringInline(strings, NiGetViewerString_00a7d510("m_uiID", uiShaderID));
            NiSprintf(prefix, 64, "m_spTexture ");
            void* pShaderTexture = map->m_spTexture.m_pObject;
            AppendStringInline(strings, NiGetViewerString_00a7d5a0(prefix, pShaderTexture));
            NiSprintf(prefix, 64, "Clamp Mode ");
            AppendStringInline(strings, 
                BuildTextureAddressModeString(prefix, static_cast<ShaderMapEx*>(map)->GetClampMode()));
            NiSprintf(prefix, 64, "Filter Mode");
            AppendStringInline(strings, BuildFilterModeString(prefix, static_cast<ShaderMapEx*>(map)->GetFilterMode()));
            NiSprintf(prefix, 64, "Texture Coord Index ");
            unsigned int uiShaderTexCoordIndex = static_cast<ShaderMapEx*>(map)->GetTextureIndex();
            AppendStringInline(strings, NiGetViewerString_00a7d510(prefix, uiShaderTexCoordIndex));
        }
    }
}

// Constructs a parallax map, initializing m_fParallaxOffset to 0.5f.
// @fnv 0x00a6a010
NiTexturingProperty::ParallaxMap::ParallaxMap() throw() : m_fParallaxOffset(0.5f)
{}

// Reads texture maps and shader maps from the stream, relocates maps 6 and 7 to slots 8 and 9 for older versions, and updates the flags count.
struct TexturingLinkBase
{
    void NiSequenceStreamHelper_LinkObject(NiStream&);
};
inline void IncrementTexturingMapCount(NiTexturingProperty* property)
{
    property->m_uiObjectFlags = (property->m_uiObjectFlags & 0xf00f) |
        (((((property->m_uiObjectFlags >> 4) & 255) + 1) << 4));
}

// @fnv 0x00a6a240
void __fastcall LinkTexturingProperty(NiTexturingProperty* self, int, NiStream& stream)
{
    reinterpret_cast<TexturingLinkBase*>(self)->NiSequenceStreamHelper_LinkObject(stream);
    unsigned int count = stream.GetLinkID();
    unsigned int i;
    self->m_uiObjectFlags &= 0xf00f;
    for (i = 0; i < count; ++i)
    {
        if (stream.GetLinkID())
        {
            NiTexturingProperty::Map*& map = self->m_kStringArray.m_pBase[i];
            reinterpret_cast<NiPointer<NiTexture>&>(map->m_spTexture) = static_cast<NiTexture*>(stream.FUN_00a63430());
            if (i >= 8)
                IncrementTexturingMapCount(self);
        }
    }
    if (stream.GetFileVersion() < 0x14020005)
    {
        NiTexturingProperty::Map* pFirstMap = 0;
        NiTexturingProperty::Map* pSecondMap = 0;
        if (self->m_kStringArray.m_usSize > 6)
            pFirstMap = self->m_kStringArray.m_pBase[6];
        if (self->m_kStringArray.m_usSize > 7)
            pSecondMap = self->m_kStringArray.m_pBase[7];
        if (pFirstMap || pSecondMap)
        {
            unsigned int added = 0;
            if (pFirstMap)
                added++;
            if (pSecondMap)
                added++;
            if ((self->m_uiObjectFlags & 0xff0) > 0 && added != 0)
            {
                for (unsigned int j = self->m_kStringArray.m_usSize - 1; j >= 8; --j)
                    self->m_kStringArray.SetAtGrow(added + j, self->m_kStringArray.m_pBase[j]);
            }
            if (pFirstMap)
            {
                self->m_kStringArray.SetAtGrow(8, pFirstMap);
                NiTexturingProperty::Map* empty = 0;
                self->m_kStringArray.SetAt(6, empty);
                IncrementTexturingMapCount(self);
            }
            else
            {
                NiTexturingProperty::Map* empty = 0;
                self->m_kStringArray.SetAt(8, empty);
            }
            if (pSecondMap)
            {
                self->m_kStringArray.SetAtGrow(9, pSecondMap);
                NiTexturingProperty::Map* empty = 0;
                self->m_kStringArray.SetAt(7, empty);
                IncrementTexturingMapCount(self);
            }
            else if (added == 2)
            {
                NiTexturingProperty::Map* empty = 0;
                self->m_kStringArray.SetAt(9, empty);
            }
        }
    }
    if (stream.GetFileVersion() >= 0x5000011)
    {
        count = stream.GetLinkID();
        for (i = 0; i < count; ++i)
        {
            if (stream.GetLinkID())
            {
                NiTexturingProperty::ShaderMap*& map = self->m_pShaderMaps->m_pBase[i];
                reinterpret_cast<NiPointer<NiTexture>&>(map->m_spTexture) = static_cast<NiTexture*>(stream.FUN_00a63430());
            }
        }
    }
}

// @fnv 0x00e7cd40
// src: COMMUNITY 0x00e7cd40
int __cdecl Ret0()
{
    return 0;
}

// NiTexturingProperty::Map constructor.
//
// Layout: vtable slot at 0, packed flag word (u16) at 4, texture pointer at
// 8, texture-transform pointer at 0xc.  The flag word is cleared first (the
// base NiFlags ctor), then the vtable is installed and both pointers are
// cleared; finally the default clamp/filter mode bits are installed in the
// flag word: (flags & 0xf100) | 0x3100 == WRAP_S_WRAP_T + FILTER_BILERP.
//
// _ReadWriteBarrier pins the store order (flag zero before the vtable store,
// vtable before the pointer clears, flag read between the two pointer
// clears) and keeps the flag read from folding into the zero store.

extern "C" void _ReadWriteBarrier();

const void* DAT_0109c4c4[];

class FUN_00a69dd0_cls
{
  public:
    const void** m_vtbl;
    unsigned short m_usFlags;
    void* m_spTexture;
    void* m_pTextureTransform;
    FUN_00a69dd0_cls();
};

// Initialises the object: sets m_vtbl, zeroes m_spTexture and m_pTextureTransform, and sets m_usFlags to 0x3100.
// @fnv 0x00a69dd0
FUN_00a69dd0_cls::FUN_00a69dd0_cls() : m_usFlags(0)
{
    _ReadWriteBarrier();
    m_vtbl = DAT_0109c4c4;
    _ReadWriteBarrier();
    m_spTexture = 0;
    _ReadWriteBarrier();
    unsigned short flags = m_usFlags;
    m_pTextureTransform = 0;
    m_usFlags = (unsigned short)((flags & ~0x0eff) | 0x3100);
}

struct TexturingMapUpdate
{
    void NiTexturingProperty_SetMultiTexture(NiTexturingProperty::Map* value);
};

// @fnv 0x00a6a150
void __fastcall SetTexturingDecalMap(NiTexturingProperty* self, int, unsigned int index, NiTexturingProperty::Map* map)
{
    NiTexturingProperty::Map* newMap;
    unsigned int position = index + 8;

    if (position < self->m_kStringArray.m_usSize)
    {
        NiTexturingProperty::Map* oldMap = self->m_kStringArray.m_pBase[position];

        if (map != 0)
        {
            if (oldMap == 0)
            {
                unsigned short flags = self->m_uiObjectFlags;
                unsigned int count = (flags >> 4) & 0xff;
                count += 1;
                self->m_uiObjectFlags = (unsigned short)((count << 4) | (flags & 0xf00f));
            }
        }
        else if (oldMap != 0)
        {
            unsigned short flags = self->m_uiObjectFlags;
            unsigned int count = (flags >> 4) & 0xff;
            count -= 1;
            self->m_uiObjectFlags = (unsigned short)((count << 4) | (flags & 0xf00f));
        }

        newMap = map;
        self->m_kStringArray.SetAt(position, map);

        if (oldMap != 0)
        {
            delete oldMap;
        }
    }
    else
    {
        NiTPrimitiveArray<NiTexturingProperty::Map*>* maps = &self->m_kStringArray;
        if (position >= self->m_kStringArray.m_usMaxSize)
        {
            maps->SetSize(position + maps->m_usGrowBy);
        }

        maps->SetAt(position, map);
        newMap = map;

        if (newMap != 0)
        {
            unsigned short flags = self->m_uiObjectFlags;
            unsigned int count = (flags >> 4) & 0xff;
            count += 1;
            self->m_uiObjectFlags = (unsigned short)((count << 4) | (flags & 0xf00f));
        }
    }

    reinterpret_cast<TexturingMapUpdate*>(self)->NiTexturingProperty_SetMultiTexture(newMap);
}

// The original map allocations have no constructor-failure cleanup.
enum TextureMapAllocation { TEXTURE_MAP_ALLOCATION };
inline void* operator new(size_t size, TextureMapAllocation)
{
    return g_memoryManager.Allocate(size);
}

namespace fnv_00a6bb00 {
struct CloneProc;
typedef NiTexturingProperty::Map TexMap;
typedef NiTexturingProperty::BumpMap TexBumpMap;
typedef NiTexturingProperty::ParallaxMap TexParallaxMap;
typedef NiTexturingProperty::ShaderMap TexShaderMap;
typedef NiTPrimitiveArray<TexMap*> TexMapArray;
typedef NiTPrimitiveArray<TexShaderMap*> TexShaderMapArray;

// The shared header has no property copy operation; keep its body local using
// the shared property layout and a declaration for the base operation only.
struct TexturingPropertyCopyBase
{
    void NiProperty_CopyMembers(NiTexturingProperty* pkDest, CloneProc& kCloning);
};
inline void SetTextureMapAtIndex(NiTexturingProperty* property, unsigned int i, TexMap* map)
{
    (&property->m_kStringArray)->SetAtGrow(i, map);
}
inline TexBumpMap* GetBumpMap(NiTexturingProperty* property)
{
    return (TexBumpMap*)(&property->m_kStringArray)->m_pBase[5];
}
inline TexParallaxMap* GetParallaxMap(NiTexturingProperty* property)
{
    return (TexParallaxMap*)(&property->m_kStringArray)->m_pBase[7];
}
// Copies texture map arrays and shader maps into the destination property.
// @fnv 0x00a6bb00
void __fastcall CopyTexturingProperty(NiTexturingProperty* self, int, NiTexturingProperty* pkDest, CloneProc& kCloning)
{
    reinterpret_cast<TexturingPropertyCopyBase*>(self)->NiProperty_CopyMembers(pkDest, kCloning);
    pkDest->m_uiObjectFlags = self->m_uiObjectFlags;
    unsigned int uiSize = (&self->m_kStringArray)->m_usSize;
    (&pkDest->m_kStringArray)->SetSize(uiSize);
    unsigned int i;
    for (i = 0; i < uiSize; i++)
    {
        if ((&self->m_kStringArray)->GetAt(i))
        {
            if (i == 5)
                SetTextureMapAtIndex(pkDest, 5, ::new (TEXTURE_MAP_ALLOCATION) TexBumpMap(*GetBumpMap(self)));
            else if (i == 7)
                SetTextureMapAtIndex(pkDest, 7, ::new (TEXTURE_MAP_ALLOCATION) TexParallaxMap(*GetParallaxMap(self)));
            else
                SetTextureMapAtIndex(pkDest, i, ::new (TEXTURE_MAP_ALLOCATION) TexMap(*(&self->m_kStringArray)->GetAt(i)));
        }
    }
    if (self->m_pShaderMaps)
    {
        if (!pkDest->m_pShaderMaps)
            pkDest->m_pShaderMaps = new TexShaderMapArray;
        uiSize = self->m_pShaderMaps->m_usSize;
        pkDest->m_pShaderMaps->SetSize(uiSize);
        for (i = 0; i < uiSize; i++)
        {
            if (self->m_pShaderMaps->m_pBase[i])
            {
                TexShaderMap* pkMap = ::new (TEXTURE_MAP_ALLOCATION) TexShaderMap(*self->m_pShaderMaps->m_pBase[i]);
                pkDest->m_pShaderMaps->SetAtGrow(i, pkMap);
            }
        }
    }
}
}  // namespace fnv_00a6bb00

struct DeallocHelper00aa4060
{
    void MemoryManager_Deallocate(void* p);
};

NiTexturingProperty::Map::~Map()
{
    reinterpret_cast<DeallocHelper00aa4060*>(&g_memoryManager)->MemoryManager_Deallocate(m_pTextureTransform);
    if (m_spTexture.m_pObject)
        m_spTexture.m_pObject->DecRefCount();
}

struct MapScalarDtorCandidate : NiTexturingProperty::Map
{
    void* FUN_00a6a9f0(unsigned int flags);
};

// Calls the base Map destructor, then frees this object via g_memoryManager when flags has bit 0 set, and returns this.
// @fnv 0x00a6a9f0
void* MapScalarDtorCandidate::FUN_00a6a9f0(unsigned int flags)
{
    this->NiTexturingProperty::Map::~Map();
    if (flags & 1)
        reinterpret_cast<DeallocHelper00aa4060*>(&g_memoryManager)->MemoryManager_Deallocate(this);
    return this;
}
