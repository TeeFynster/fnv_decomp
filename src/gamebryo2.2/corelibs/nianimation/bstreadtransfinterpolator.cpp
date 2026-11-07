
// src/gamebryo2.2/corelibs/nianimation/bstreadtransfinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/bstreadtransfinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSTreadTransfInterpolator.h"
#include "../../../../include/NiFloatData.h"
#include <windows.h>

// @fnv 0x00a43560
unsigned int BSTreadTransfInterpolator::GetColorKeyCount(unsigned short arg) const
{
    if (arg == 0)
    {
        if (reference.m_pObject)
        {
            return *reinterpret_cast<int*>(reinterpret_cast<char*>(reference.m_pObject) + 8);
        }
    }
    return 0;
}

// @fnv 0x00a43580
// src: XBOX_PDB 0x00a43580
void* BSTreadTransfInterpolator::GetKeyType(unsigned short flag)
{
    if (!flag)
    {
        void* p = reference.m_pObject;
        if (p)
            return *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(p) + 0x10);
    }
    return 0;
}

// @fnv 0x00a435a0
NiAnimationKey* BSTreadTransfInterpolator::GetChannelKeys(unsigned short arg1) const
{
    if (arg1 != 0)
        return 0;
    void* obj = reference.m_pObject;
    if (obj)
        return *reinterpret_cast<NiAnimationKey**>(reinterpret_cast<char*>(obj) + 0xc);
    return 0;
}

extern "C" void __cdecl __Dummy_00b6fef0(void* ptr, unsigned int flags);

// @fnv 0x00a43a50
void* BSTreadTransfInterpolator::FUN_00a43a50(unsigned int flags)
{
    this->BSTreadTransfInterpolator::~BSTreadTransfInterpolator();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x24);
    return this;
}

// @fnv 0x00a435c0
unsigned char BSTreadTransfInterpolator::GetColorKeySize(unsigned short arg) const
{
    if (arg != 0)
        return 0;
    void* p = reference.m_pObject;
    if (p)
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(p) + 0x14);
    return 0;
}

struct TrackFlags
{
    unsigned char value;
};
float __cdecl InterpolateKey(float, float*, float*, unsigned int, unsigned int*, TrackFlags);
// Samples the track, updates the sample index and value delta, and stores the current value and time.
// @fnv 0x00a434b0
bool BSTreadTransfInterpolator::UpdateSampleValue(float time, int, int)
{
    NiFloatData* pTrack = reinterpret_cast<NiFloatData*>(reference.m_pObject);
    unsigned int count = pTrack->m_uiNumKeys;
    float* values = reinterpret_cast<float*>(pTrack->m_eRequestType);
    TrackFlags flags;
    flags.value = pTrack->m_ucKeyDataSize;
    float* times = reinterpret_cast<float*>(pTrack->m_pKeyArray);
    if (count > 0)
    {
        unsigned int index = unk1c;
        float value = InterpolateKey(time, times, values, count, &index, flags);
        unk1c = index;
        if (m_fLastTime > time && firstValue > value)
        {
            secondValue = (1.0f - firstValue) + value;
        }
        else
        {
            secondValue = value - firstValue;
        }
        firstValue = value;
    }
    m_fLastTime = time;
    return true;
}

// @fnv 0x00a435e0
// src: XBOX_PDB 0x00a435e0
bool BSTreadTransfInterpolator::GetChannelPosed(int arg)
{
    if (reference.m_pObject != 0)
    {
        GetColorKeyCount(static_cast<unsigned short>(arg));
    }
    return false;
}

class A43600BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A43600BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A43600BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class A43600Object;

class A43600Stream
{
  public:
    void SerializeString(void* pkString);
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
    virtual void SaveLinkID(A43600Object* pkObject);
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
    A43600BinaryStream* m_pBackingStream;
};

template <class T>
inline void A43600BinaryStreamSave(A43600BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A43600SaveBinary(A43600Stream& kStream, const T& value)
{
    A43600BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class A43600Color
{
  public:
    float r;
    float g;
    float b;
    float a;

    void SaveBinary(A43600Stream& kStream);
};

struct TreadTransformEntry
{
    A43600Color m_kColor0;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    A43600Color m_kColor1;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    void* m_kName;
};

// The approved base header does not declare this stream helper.
class A43600Base
{
  public:
    void SaveBinaryBase(A43600Stream& kStream);
};

// Saves the base data, entry count, each entry's name and two colors, then the target link ID to the stream.
// @fnv 0x00a43600
void BSTreadTransfInterpolator::SaveBinary(NiStream& arStream)
{
    A43600Stream& kStream = reinterpret_cast<A43600Stream&>(arStream);
    reinterpret_cast<A43600Base*>(this)->SaveBinaryBase(kStream);
    A43600SaveBinary(kStream, count);
    for (unsigned int i = 0; i < count; i++)
    {
        kStream.SerializeString(&entries[i].m_kName);
        entries[i].m_kColor0.SaveBinary(kStream);
        entries[i].m_kColor1.SaveBinary(kStream);
    }
    kStream.SaveLinkID(reinterpret_cast<A43600Object*>(reference.m_pObject));
}

template <class T> inline NiPointer<T>::NiPointer()
    : m_pObject(0)
{}

template <class T> __declspec(nothrow) inline NiPointer<T>::~NiPointer()
{
    T* pkNew = m_pObject;
    if (pkNew && InterlockedDecrement((long volatile*)&pkNew->m_uiRefCount) == 0)
        pkNew->DeleteThis();
}

inline BSTreadTransfInterpolator::BSTreadTransfInterpolator() throw()
    : entries(0), count(0), firstValue(0.0f), secondValue(0.0f), unk1c(0)
{}

// Allocates a clone and copies the interpolator data.
// @fnv 0x00a439e0
// src: XBOX_PDB 0x00a439e0
BSTreadTransfInterpolator* BSTreadTransfInterpolator::CreateClone_00a439e0(void* kCloning)
{
    BSTreadTransfInterpolator* pkClone = new BSTreadTransfInterpolator;
    FUN_00a43690(pkClone, kCloning);
    return pkClone;
}

extern void* DAT_0109b220;

struct a43840_Mem
{
    __declspec(nothrow) void __thiscall _DeallocateAlias(void*);
};

extern a43840_Mem DAT_011f6238;

// Frees the entry array; member and base destructors release the reference and interpolator data.
// @fnv 0x00a43840
BSTreadTransfInterpolator::~BSTreadTransfInterpolator()
{
    TreadTransformEntry* pElements = entries;
    if (pElements != 0)
    {
        int i = ((int*)pElements)[-1];
        TreadTransformEntry* p = pElements + i;
        i = i - 1;
        if (i >= 0)
        {
            do
            {
                p = p - 1;
                void* e = p->m_kName;
                if (e != DAT_0109b220)
                {
                    InterlockedDecrement((long volatile*)((char*)e - 8));
                }
            } while (--i >= 0);
        }
        DAT_011f6238._DeallocateAlias((char*)pElements - 4);
    }
}
