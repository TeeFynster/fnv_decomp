
// src/gamebryo2.2/corelibs/nimain/nitristripsdata_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nitristripsdata.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiTriStripsData.h"
#include "../../../../include/NiStream.h"
extern "C" const NiRTTI DAT_011f4a70;

extern const void* DAT_0109d8ac;

NiTriBasedGeomData* __fastcall InitializeTriBasedGeomData(NiTriBasedGeomData* p);

// @fnv 0x00a75e20
// src: EXE 0x00a75e20
NiTriStripsData* __fastcall NiTriStripsData_NiTriStripsData(NiTriStripsData* self)
{
    InitializeTriBasedGeomData(self);
    unsigned int v = 0;
    self->m_usStrips = 0;
    self->m_pusStripLengths = reinterpret_cast<unsigned short*>(v);
    self->m_pusStripLists = reinterpret_cast<unsigned short*>(v);
    *reinterpret_cast<const void**>(self) = &DAT_0109d8ac;
    return self;
}

void _delete(void*, unsigned int);
// @fnv 0x00a75f10
unsigned short* NiTriStripsData::GetTriangleStripData()
{
    return m_pusStripLists;
}

struct SharedData_S
{
    char pad_00[0x0c];
    int refCount;
    void ForwardCall_00a8a670();
};

void _NiFree(void*);

// @fnv 0x00a760c0
// The shared header has no strip replacement member; preserve its thiscall ABI with an unused EDX argument.
void __fastcall SetTriangleStripData(NiTriStripsData* self, void*, unsigned short count,
                                     unsigned short* data1, unsigned short* data2)
{
    SharedData_S* sharedData = (SharedData_S*)self->GetGroup();
    if (sharedData)
    {
        if (data1 != self->m_pusStripLengths)
        {
            SharedData_S* releasedData = (SharedData_S*)self->GetGroup();
            if (--releasedData->refCount == 0)
            {
                releasedData->ForwardCall_00a8a670();
                _delete(releasedData, 0x10);
            }
        }

        if (data2 != self->m_pusStripLists)
        {
            SharedData_S* releasedData = (SharedData_S*)self->GetGroup();
            if (--releasedData->refCount == 0)
            {
                releasedData->ForwardCall_00a8a670();
                _delete(releasedData, 0x10);
            }
        }
    }
    else
    {
        if (data1 != self->m_pusStripLengths)
            _NiFree(self->m_pusStripLengths);

        if (data2 != self->m_pusStripLists)
            _NiFree(self->m_pusStripLists);
    }

    unsigned short total = 0;
    unsigned short i = 0;
    self->m_usStrips = count;
    self->m_pusStripLengths = data1;
    self->m_pusStripLists = data2;
    self->m_usTriangles = total;

    for (; i < count; ++i)
        self->m_usTriangles += data1[i] - 2;
}

// @fnv 0x00a75dc0
NiTriStripsData::NiTriStripsData(unsigned short vertices, NiPoint3* vertexData, NiPoint3* normalData,
                               NiColorA* colors, NiPoint2* textures, unsigned short textureSets,
                               NiGeometryData__DataFlags flags, unsigned short triangles,
                               unsigned short stripCount, unsigned short* lengths, unsigned short* lists)
    : NiTriBasedGeomData(vertices, vertexData, normalData, colors, textures, textureSets, flags, triangles),
      m_usStrips(stripCount), m_pusStripLengths(lengths), m_pusStripLists(lists)
{}

// The shared geometry header has no allocation-size override; this no-argument
// member at 0x00a66f90 uses the same ECX-only ABI as a one-argument fastcall.
unsigned int __fastcall GetGeometryBlockAllocationSize(NiGeometryData*);

// @fnv 0x00a76020
unsigned int __fastcall GetTriangleStripBlockAllocationSize(NiTriStripsData* self)
{
    unsigned short listLen = self->m_usTriangles + self->m_usStrips * 2;
    unsigned int size = (listLen + self->m_usStrips) * 2;
    return size + GetGeometryBlockAllocationSize(self);
}

class A76340BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A76340BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A76340BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n, unsigned int uiComponentSize)
    {
        unsigned int size = uiComponentSize;
        return BinaryWrite(p, n, &size, 1);
    }
};

// NiStream's shared definition keeps these fields in opaque storage.
inline A76340BinaryStream* A76340BackingStream(NiStream& stream)
{
    return *reinterpret_cast<A76340BinaryStream**>(reinterpret_cast<char*>(&stream) + 0x250);
}

template <class T>
inline void A76340BinaryStreamSave(A76340BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A76340SaveBinary(NiStream& kStream, const T& value)
{
    A76340BinaryStreamSave(*A76340BackingStream(kStream), &value);
}

template <class T> inline void A76340SaveBinary(NiStream& kStream, const T* pValues, unsigned int ItemUpdateArray)
{
    A76340BinaryStreamSave(*A76340BackingStream(kStream), pValues, ItemUpdateArray);
}

// @fnv 0x00a76340
void NiTriStripsData::SaveBinary(NiStream& kStream)
{
    NiTriBasedGeomData::SaveBinary(kStream);
    A76340SaveBinary(kStream, m_usStrips);
    if (m_usStrips > 0)
    {
        A76340SaveBinary(kStream, m_pusStripLengths, m_usStrips);
        bool bHasPoints = m_pusStripLists != 0;
        A76340SaveBinary(kStream, bHasPoints);
        if (bHasPoints)
            A76340SaveBinary(kStream, m_pusStripLists, (unsigned short)(m_usTriangles + 2 * m_usStrips));
    }
}

class StripViewerArray
{
  public:
    void* m_ppVirtualMethodTable;
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int size);
    void FUN_0096ae90(unsigned int index, const unsigned int* value);
};

extern "C" const char str_0109d984[];
extern "C" const char str_0109d970[];
extern "C" const char str_0109d960[];
unsigned int NiViewerStrings_NiGetViewerString_Title(const NiRTTI*);
unsigned int NiGetViewerString_00a7d490(const void*, unsigned short);
unsigned int NiGetViewerString_00a7d5a0(const void*, const void*);

// NiTriBasedGeomData's viewer-string override at 0x00a8aab0 is not declared
// in the shared header. EDX is ignored by its thiscall implementation.
void __fastcall AppendTriangleDataViewerStrings(NiTriBasedGeomData*, void*, StripViewerArray&);

// @fnv 0x00a76430
void __fastcall GetTriangleStripViewerStrings(NiTriStripsData* self, void* unused, StripViewerArray& stream)
{
    AppendTriangleDataViewerStrings(self, unused, stream);
    unsigned int entry = NiViewerStrings_NiGetViewerString_Title(*reinterpret_cast<const NiRTTI* const*>(&DAT_011f4a70));
    unsigned int count = stream.m_usSize;
    if (count >= (unsigned int)stream.m_usMaxSize)
    {
        stream.FUN_0096ad30(count + stream.m_usGrowBy);
    }
    stream.FUN_0096ae90(count, &entry);

    entry = NiGetViewerString_00a7d490(str_0109d984, self->m_usStrips);
    count = stream.m_usSize;
    if (count >= (unsigned int)stream.m_usMaxSize)
    {
        stream.FUN_0096ad30(count + stream.m_usGrowBy);
    }
    stream.FUN_0096ae90(count, &entry);

    entry = NiGetViewerString_00a7d5a0(str_0109d970, self->m_pusStripLengths);
    count = stream.m_usSize;
    if (count >= (unsigned int)stream.m_usMaxSize)
    {
        stream.FUN_0096ad30(count + stream.m_usGrowBy);
    }
    stream.FUN_0096ae90(count, &entry);

    entry = NiGetViewerString_00a7d5a0(str_0109d960, self->m_pusStripLists);
    count = stream.m_usSize;
    if (count >= (unsigned int)stream.m_usMaxSize)
    {
        stream.FUN_0096ad30(count + stream.m_usGrowBy);
    }
    stream.FUN_0096ae90(count, &entry);
}

namespace fnv_00a761c0 {
void* __cdecl _NiMalloc_00aa1070(unsigned int);
struct BinaryA
{
    int unk0;
    unsigned pos;
    unsigned(__cdecl* read)(BinaryA*, void*, unsigned, unsigned*, unsigned);
    void Read(void* dest, unsigned bytes, unsigned component)
    {
        unsigned size = component;
        pos += read(this, dest, bytes, &size, 1);
    }
};
inline BinaryA* InputStream(NiStream& stream)
{
    return *reinterpret_cast<BinaryA**>(reinterpret_cast<char*>(&stream) + 0x24c);
}
inline unsigned FileVersion(const NiStream& stream)
{
    return *reinterpret_cast<const unsigned*>(reinterpret_cast<const char*>(&stream) + 0xd8);
}
struct SharedView
{
    int unk0, unk4;
    unsigned char* current;
    int refs;
    void* Allocate(unsigned bytes)
    {
        unsigned char* old = current;
        refs++;
        current += bytes;
        return old;
    }
};
}  // namespace fnv_00a761c0

// @fnv 0x00a761c0
void NiTriStripsData::LoadBinary(NiStream& stream)
{
    using namespace fnv_00a761c0;
    NiTriBasedGeomData::LoadBinary(stream);
    InputStream(stream)->Read(&m_usStrips, 2, 2);
    if (m_usStrips > 0)
    {
        if (GetGroup())
            m_pusStripLengths = (unsigned short*)((SharedView*)GetGroup())->Allocate(m_usStrips * sizeof(unsigned short));
        else
            m_pusStripLengths = (unsigned short*)_NiMalloc_00aa1070(m_usStrips * sizeof(unsigned short));
        InputStream(stream)->Read(m_pusStripLengths, m_usStrips * 2, 2);
        bool present;
        if (FileVersion(stream) >= 0x0a000111)
            InputStream(stream)->Read(&present, 1, 1);
        else
            present = true;
        if (present)
        {
            unsigned int count = (unsigned short)(m_usTriangles + 2 * m_usStrips);
            if (GetGroup())
                m_pusStripLists = (unsigned short*)((SharedView*)GetGroup())->Allocate(count * sizeof(unsigned short));
            else
                m_pusStripLists = (unsigned short*)_NiMalloc_00aa1070(count * sizeof(unsigned short));
            InputStream(stream)->Read(m_pusStripLists, count * 2, 2);
        }
    }
}

// The shared strip-data header has no triangle-index override.
// @fnv 0x00a75e40
void __fastcall GetTriangleStripIndices(const NiTriStripsData* self, void*, unsigned short i,
                                        unsigned short& i0, unsigned short& i1, unsigned short& i2)
{
    unsigned short* pusStripLists = self->m_pusStripLists;
    unsigned short* pusStripLengths = self->m_pusStripLengths;
    unsigned short usStrip = 0;
    unsigned short usTris = pusStripLengths[usStrip] - 2;
    while (i >= usTris)
    {
        i -= usTris;
        pusStripLists += pusStripLengths[usStrip];
        usStrip++;
        usTris = pusStripLengths[usStrip] - 2;
    }
    if (i & 1)
    {
        i0 = pusStripLists[i + 1];
        i1 = pusStripLists[i];
    }
    else
    {
        i0 = pusStripLists[i];
        i1 = pusStripLists[i + 1];
    }
    i2 = pusStripLists[i + 2];
}

// The base comparison at 0x00a8a9c0 checks NiTriBasedGeomData triangle counts;
// its override is absent from the shared base header. This declaration carries no layout.
struct TriangleCountComparison
{
    bool MatchesTriangleCount(NiObject* pkObject);
};

// @fnv 0x00a75f80
bool NiTriStripsData::IsEqual(NiObject* object) const
{
    NiTriStripsData* pkObject = static_cast<NiTriStripsData*>(object);
    if (!((TriangleCountComparison*)this)->MatchesTriangleCount(pkObject))
        return false;

    NiTriStripsData* pkData = pkObject;

    if (m_usStrips != pkData->m_usStrips)
        return false;

    unsigned int i;
    for (i = 0; i < m_usStrips; i++)
    {
        if (m_pusStripLengths[i] != pkData->m_pusStripLengths[i])
            return false;
    }

    for (i = 0; i < (unsigned short)(m_usTriangles + 2 * m_usStrips); i++)
    {
        if (m_pusStripLists[i] != pkData->m_pusStripLists[i])
            return false;
    }

    return true;
}

extern "C" void __cdecl operator_delete_sized(void* p, unsigned int uiSize) throw();
extern "C" void __cdecl _NiFreeAlias(void* p) throw();

struct NiSharedDataA76
{
    int unk00;
    int unk04;
    int unk08;
    int m_iRefCount;
    void ForwardCall_00a8a670() throw();
};

inline void ReleaseShared(NiSharedDataA76* pkShared) throw()
{
    if (--pkShared->m_iRefCount == 0)
    {
        pkShared->ForwardCall_00a8a670();
        operator_delete_sized(pkShared, 0x10);
    }
}

// GetGroup's implementation at 0x00a669c0 takes only ECX and cannot throw;
// the shared virtual declaration lacks that exception specification.
NiObjectGroup* __fastcall GetGeometryObjectGroup(NiObject*) throw();

// @fnv 0x00a76040
NiTriStripsData::~NiTriStripsData()
{
    if (GetGeometryObjectGroup(this))
    {
        ReleaseShared((NiSharedDataA76*)GetGeometryObjectGroup(this));
        ReleaseShared((NiSharedDataA76*)GetGeometryObjectGroup(this));
    }
    else
    {
        _NiFreeAlias(m_pusStripLengths);
        _NiFreeAlias(m_pusStripLists);
    }
}

// @fnv 0x00a75ec0
// src: EXE 0x00a75ec0
NiTriBasedGeomData* __fastcall NiTriStripsData_CreateObject(NiTriBasedGeomData*)
{
    NiTriStripsData* p = (NiTriStripsData*)BSFadeNode::operator new(sizeof(NiTriStripsData));
    if (p)
    {
        InitializeTriBasedGeomData(p);
        p->m_usStrips = 0;
        p->m_pusStripLengths = 0;
        p->m_pusStripLists = 0;
        *reinterpret_cast<const void**>(p) = &DAT_0109d8ac;
        return p;
    }
    return 0;
}
