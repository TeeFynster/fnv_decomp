#include "../../../../include/NiRangeLODData.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiLODData.h"

struct LODObject;
class D60Stream;

// These methods are not declared by the shared header. This adapter adds no data;
// the shared NiRangeLODData remains the sole definition of the object layout.
class RangeLODDataOperations : public NiRangeLODData
{
  public:
    void UpdateWorldRanges(const LODObject* pkLOD);
    void SaveRanges(D60Stream& kStream);
};

// src/gamebryo2.2/corelibs/nimain/nirangeloddata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nirangeloddata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_011f5ef8;

// @fnv 0x00a976f0
// src: COMMUNITY 0x00a976f0
GlobalObjectO2_00a7b610* __cdecl NiRangeLODData_GetRTTI()
{
    return &g_011f5ef8;
}

extern "C" void* __cdecl _memmove(void* dst, const void* src, unsigned int size);

// @fnv 0x00a97ba0
void NiRangeLODData::CopyTo(NiRangeLODData* pkDest, CloningProcess* kCloning)
{
    pkDest->m_kCenter = this->m_kCenter;
    pkDest->m_kWorldCenter = this->m_kWorldCenter;
    pkDest->SetRangeCount(this->m_uiRangeCount);
    _memmove(pkDest->m_pRanges, this->m_pRanges, this->m_uiRangeCount << 4);
}

void* __cdecl NiMalloc(unsigned int size);
void __cdecl NiFreeAlias(void* ptr);

// Reallocates the range array to uiNumRanges entries, copying the overlapping existing ranges and freeing the old buffer.
// @fnv 0x00a978a0
void NiRangeLODData::SetRangeCount(unsigned int uiNumRanges)
{
    if (uiNumRanges != m_uiRangeCount)
    {
        if (!uiNumRanges)
        {
            NiFreeAlias(m_pRanges);
            m_pRanges = 0;
            m_uiRangeCount = 0;
            return;
        }
        NiRangeLODData::Range* pkNewRanges = (NiRangeLODData::Range*)NiMalloc(uiNumRanges << 4);
        if (m_pRanges)
            _memmove(pkNewRanges, m_pRanges,
                     ((int)m_uiRangeCount < (int)uiNumRanges ? m_uiRangeCount : uiNumRanges) << 4);
        NiFreeAlias(m_pRanges);
        m_pRanges = pkNewRanges;
        m_uiRangeCount = uiNumRanges;
    }
}

// @fnv 0x00a97690
bool __fastcall RangeLODDataEquals(NiRangeLODData* self, int, NiObject* pkObject)
{
    if (self->m_uiRangeCount != ((NiRangeLODData*)pkObject)->m_uiRangeCount)
        return false;
    NiRangeLODData* pkLOD = (NiRangeLODData*)pkObject;
    unsigned int i;
    for (i = 0; i < self->m_uiRangeCount; i++)
    {
        if (pkLOD->m_pRanges[i].m_fNearPlane != self->m_pRanges[i].m_fNearPlane)
            return false;
        if (pkLOD->m_pRanges[i].m_fFarPlane != self->m_pRanges[i].m_fFarPlane)
            return false;
    }
    return true;
}

extern int DAT_010a073c;
extern NiPoint3 _NiPoint3_ZERO;
struct BaseCall
{
    void FUN_00aa09a0();
};
// Calls the base initializer, installs the vtable, resets m_kCenter to zero and clears two fields, then returns this.
// @fnv 0x00a97700
NiRangeLODData* NiRangeLODData::InitializeRangeLODData()
{
    ((BaseCall*)this)->FUN_00aa09a0();
    *(int*)this = (int)&DAT_010a073c;
    m_kCenter = *(const NiPoint3*)&_NiPoint3_ZERO;
    m_uiRangeCount = 0;
    m_pRanges = 0;
    return this;
}

extern int DAT_010a073c;
void __cdecl _NiFreeAlias(void*);
void __cdecl _delete(void*, unsigned int);
struct FUN_00aa09c0_shell
{
    void __thiscall FUN_00aa09c0();
};
// Restores the base vtable, frees the stored pointer, runs base cleanup, and optionally deletes the object when flag bit 0 is set.
// @fnv 0x00a97740
void* __fastcall DestroyRangeLODData(NiRangeLODData* self, int, unsigned int auiFlags)
{
    void* pk = self->m_pRanges;
    *(void**)self = (void*)&DAT_010a073c;
    _NiFreeAlias(pk);
    ((FUN_00aa09c0_shell*)self)->FUN_00aa09c0();
    if (auiFlags & 1)
        _delete(self, 0x28);
    return self;
}

struct Base00aa09a0
{
    void FUN_00aa09a0();
};
extern int DAT_010a073c;
extern NiPoint3 _NiPoint3_ZERO;
// @fnv 0x00a97c00
NiRangeLODData* CreateRangeLODData()
{
    NiRangeLODData* p = (NiRangeLODData*)BSFadeNode::operator new(0x28);
    if (p)
    {
        ((Base00aa09a0*)p)->FUN_00aa09a0();
        *(int*)p = (int)&DAT_010a073c;
        p->m_kCenter = *(const NiPoint3*)&_NiPoint3_ZERO;
        p->m_uiRangeCount = 0;
        p->m_pRanges = 0;
        return p;
    }
    return 0;
}

// @fnv 0x00a97c50
NiRangeLODData* __fastcall CopyRangeLODData(NiRangeLODData* self, int)
{
    NiRangeLODData* pkData = (NiRangeLODData*)BSFadeNode::operator new(0x28);
    if (pkData)
    {
        ((BaseCall*)pkData)->FUN_00aa09a0();
        *(int*)((char*)pkData + 0) = (int)&DAT_010a073c;
        pkData->m_kCenter = *(const NiPoint3*)&_NiPoint3_ZERO;
        pkData->m_uiRangeCount = 0;
        pkData->m_pRanges = 0;
    }
    else
        pkData = 0;
    pkData->m_kCenter = self->m_kCenter;
    pkData->SetRangeCount(self->m_uiRangeCount);
    _memmove(pkData->m_pRanges, self->m_pRanges, self->m_uiRangeCount * 16);
    return pkData;
}

const float DAT_01015f5c = -3.402823466e+38F;
const float DAT_010a0730 = 3.402823466e+38F;
// @fnv 0x00a979e0
int __fastcall SelectLODRange(NiRangeLODData* self, int, int rank)
{
    if (rank <= 0)
        rank = 0;
    rank = rank < static_cast<int>(self->m_uiRangeCount) - 1 ? rank : static_cast<int>(self->m_uiRangeCount) - 1;
    float threshold = DAT_01015f5c;
    int selected = -1;
    for (int step = 0; step <= rank; ++step)
    {
        float nearest = DAT_010a0730;
        for (int index = 0; index < static_cast<int>(self->m_uiRangeCount); ++index)
        {
            if (self->m_pRanges[index].m_fNearPlane > threshold &&
                self->m_pRanges[index].m_fNearPlane <= nearest)
            {
                threshold = self->m_pRanges[index].m_fNearPlane;
                selected = index;
                nearest = self->m_pRanges[index].m_fNearPlane;
            }
        }
    }
    return selected;
}

extern const NiPoint3 g_kA97CE0Zero;

inline NiRangeLODData::NiRangeLODData() throw() : m_kCenter(g_kA97CE0Zero), m_uiRangeCount(0), m_pRanges(0)
{}

// @fnv 0x00a97ce0
// src: XBOX_PDB 0x00a97ce0
NiObject* NiRangeLODData::CreateClone_00a97ce0(CloningProcess& kCloning)
{
    NiRangeLODData* pkClone = new NiRangeLODData;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

class A97E20Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};

extern A97E20Heap g_memoryManager;

struct A97E20BinaryStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(A97E20BinaryStream* pkStream, void* pvBuffer, unsigned int uiSize, unsigned int* puiSizes,
                              unsigned int ItemUpdateArray);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};

class A97E20Stream
{
  public:
    int unk000;
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
    A97E20BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void A97E20BinaryStreamLoad(A97E20BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A97E20LoadBinary(A97E20Stream& kStream, T& value)
{
    A97E20BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

struct A97E20Point3
{
    float x;
    float y;
    float z;

    void LoadBinary(A97E20Stream& kStream);
};

class A97E20LODData
{
  public:
    int unk00;
    int unk04;

    void LoadBinary(A97E20Stream& kStream);
};

// @fnv 0x00a97e20
void __fastcall LoadRangeLODData(NiRangeLODData* self, int, A97E20Stream& kStream)
{
    ((A97E20LODData*)self)->LoadBinary(kStream);
    ((A97E20Point3*)&self->m_kCenter)->LoadBinary(kStream);
    unsigned int uiNumRanges;
    A97E20LoadBinary(kStream, uiNumRanges);
    self->SetRangeCount(uiNumRanges);
    for (unsigned int i = 0; i < uiNumRanges; i++)
    {
        A97E20LoadBinary(kStream, self->m_pRanges[i].m_fNearPlane);
        A97E20LoadBinary(kStream, self->m_pRanges[i].m_fFarPlane);
    }
}

// @fnv 0x00aa09a0
__declspec(noinline) NiLODData::NiLODData()
{}

// SaveBinary: base data, the color, the key count, then the first two words of each 16-byte key.

class D60BinaryStream
{
  public:
    int unk00;
    unsigned int m_uiStreamFlags;
    int unk08;
    unsigned int(__cdecl* m_pfnWrite)(D60BinaryStream* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

template <class T> inline void D60SaveBinary(D60BinaryStream& kStream, const T& rValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&rValue, sizeof(T), &uiSize, 1);
}

class D60Stream
{
  public:
    int unk000;
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
    D60BinaryStream* m_pBackingStream;
};

class D60Color
{
  public:
    void SaveBinary(D60Stream& kStream);

    float r;
    float g;
    float b;
    float a;
};

class D60Base
{
  public:
    void SaveBinary(D60Stream& kStream);
};

// Saves the base data, color, key count and each key's time and value to the stream.
// @fnv 0x00a97d60
void RangeLODDataOperations::SaveRanges(D60Stream& kStream)
{
    ((D60Base*)this)->SaveBinary(kStream);
    ((D60Color*)&m_kCenter)->SaveBinary(kStream);
    D60SaveBinary(*kStream.m_pBackingStream, m_uiRangeCount);
    for (unsigned int i = 0; i < m_uiRangeCount; i++)
    {
        D60SaveBinary(*kStream.m_pBackingStream, m_pRanges[i].m_fNearPlane);
        D60SaveBinary(*kStream.m_pBackingStream, m_pRanges[i].m_fFarPlane);
    }
}

extern const char* DAT_011f5ef8;
struct A97EF0Strings
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& element);
    unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    void SetAtInline(unsigned int uiIndex, char* element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element)
                m_usESize++;
        }
        else
        {
            if (element)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int AddInline(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAtInline(uiIndex, element);
        return uiIndex;
    }
};
char* A97EF0GetViewerString(const char* pcName);
int A97EF0Sprintf(char* buf, unsigned int size, const char* fmt, ...);

// Appends formatted strings for m_kCenter, m_kWorldCenter, and each range entry to pkStrings.
// @fnv 0x00a97ef0
void __fastcall GetRangeLODDataViewerStrings(NiRangeLODData* self, int, A97EF0Strings* pkStrings)
{
    pkStrings->Add(A97EF0GetViewerString(DAT_011f5ef8));
    pkStrings->Add(((const NiPoint3*)&self->m_kCenter)->FormatToBuffer("m_kCenter"));
    pkStrings->Add(static_cast<const NiRangeLODData*>(self)->GetWorldCenter().FormatToBuffer("m_kWorldCenter"));
    for (unsigned int i = 0; i < self->m_uiRangeCount; i++)
    {
        char* pcRange = (char*)NiMalloc(0x80);
        A97EF0Sprintf(pcRange, 0x80, "range[%d] = %g   %g", i, self->m_pRanges[i].m_fNearPlane, self->m_pRanges[i].m_fFarPlane);
        pkStrings->AddInline(pcRange);
    }
}

struct WPoint3
{
    float x, y, z;
    WPoint3()
    {}
    WPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}
    __forceinline WPoint3 operator+(const WPoint3& p) const
    {
        return WPoint3(x + p.x, y + p.y, z + p.z);
    }
};

__forceinline WPoint3 operator*(float s, const WPoint3& p)
{
    return WPoint3(s * p.x, s * p.y, s * p.z);
}
struct WMatrix3
{
    float m_afEntries[3][3];
    __forceinline WPoint3 operator*(const WPoint3& p) const
    {
        return WPoint3(m_afEntries[0][0] * p.x + m_afEntries[0][1] * p.y + m_afEntries[0][2] * p.z,
                       m_afEntries[1][0] * p.x + m_afEntries[1][1] * p.y + m_afEntries[1][2] * p.z,
                       m_afEntries[2][0] * p.x + m_afEntries[2][1] * p.y + m_afEntries[2][2] * p.z);
    }
};
struct WTransform
{
    WMatrix3 m_kOrientation;
    WPoint3 m_kTranslation;
    float m_fScale;
    __forceinline WPoint3 operator*(const WPoint3& kPoint) const
    {
        return m_kOrientation * (m_fScale * kPoint) + m_kTranslation;
    }
};
struct LODObject
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
    WTransform m_kWorldSpaceTransform;
    const WTransform& GetWorldTransform() const
    {
        return m_kWorldSpaceTransform;
    }
    const WMatrix3& GetWorldRotate() const
    {
        return m_kWorldSpaceTransform.m_kOrientation;
    }
    const WPoint3& GetWorldTranslate() const
    {
        return m_kWorldSpaceTransform.m_kTranslation;
    }
    float GetWorldScale() const
    {
        return m_kWorldSpaceTransform.m_fScale;
    }
};

// Transforms m_kCenter into m_kWorldCenter and scales each range's near and far planes by the LOD object's world scale.
// @fnv 0x00a97780
void RangeLODDataOperations::UpdateWorldRanges(const LODObject* pkLOD)
{
    const WTransform& kWorld = pkLOD->m_kWorldSpaceTransform;
    *(WPoint3*)&GetWorldCenter() = kWorld.m_kOrientation * (kWorld.m_fScale * *(const WPoint3*)&m_kCenter) + kWorld.m_kTranslation;
    for (unsigned int i = 0; i < m_uiRangeCount; i++)
    {
        ((float*)&m_pRanges[i])[2] = m_pRanges[i].m_fNearPlane * kWorld.m_fScale;
        ((float*)&m_pRanges[i])[3] = m_pRanges[i].m_fFarPlane * kWorld.m_fScale;
    }
}

#include <math.h>

struct S_00a97910_Object
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
    float unk68;
    int unk6c;
    int unk70;
    float unk74;
    int unk78;
    int unk7c;
    float unk80;
    int unk84;
    int unk88;
    float unk8c;
    float unk90;
    float unk94;
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDc;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEc;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    float unk110;
};

struct S_P3
{
    float x, y, z;
};
// Computes a scaled absolute dot product and returns the first index whose lower bound is at most it and upper bound is greater.
// @fnv 0x00a97910
int __fastcall FindRangeIndex(NiRangeLODData* self, int, S_00a97910_Object* object, float unused)
{
    S_P3 vOffset;
    vOffset.x = self->GetWorldCenter().x - object->unk8c;
    vOffset.y = self->GetWorldCenter().y - object->unk90;
    vOffset.z = self->GetWorldCenter().z - object->unk94;
    S_P3 r;
    r.x = object->unk68;
    r.y = object->unk74;
    r.z = object->unk80;
    float distance = r.y * vOffset.y + r.x * vOffset.x + r.z * vOffset.z;
    distance *= object->unk110;
    distance = fabs(distance);
    for (unsigned int i = 0; i < self->m_uiRangeCount; ++i)
    {
        NiRangeLODData::Range* range = self->m_pRanges + i;
        if (!(*(float*)&range->unusedA <= distance))
            continue;
        if (*(float*)&range->unusedB > distance)
            return (int)i;
    }
    return -1;
}
