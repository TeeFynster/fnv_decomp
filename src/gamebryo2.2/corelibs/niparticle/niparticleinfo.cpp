#include "../../../../include/NiPoint3.h"

// src/gamebryo2.2/corelibs/niparticle/niparticleinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/niparticleinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


struct Point3ParameterData
{
    NiPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
    bool __thiscall Equals(const Point3ParameterData& kData);
};

// Compares every member of this object with kData and returns true only if all of them are equal.
// @fnv 0x00c31e90
bool __thiscall Point3ParameterData::Equals(const Point3ParameterData& kData)
{
    if (m_kValue.x != kData.m_kValue.x || m_kValue.y != kData.m_kValue.y || m_kValue.z != kData.m_kValue.z ||
        m_fXValue != kData.m_fXValue || m_fYValue != kData.m_fYValue || m_fZValue != kData.m_fZValue ||
        m_usFirstValue != kData.m_usFirstValue || m_usSecondValue != kData.m_usSecondValue)
        return false;
    return true;
}

// Point3ParameterData-style particle info initialiser.
// The velocity is copied bitwise from a global default point, the three
// float fields are cleared and the two generation/code counters are zeroed.
extern NiPoint3 DAT_011f426c;

struct FUN_00c31e50_cls
{
    NiPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;

    FUN_00c31e50_cls();
};

// Initializes the point from DAT_011f426c and sets the three floats and two shorts to zero.
// @fnv 0x00c31e50
FUN_00c31e50_cls::FUN_00c31e50_cls()
{
    m_kValue = DAT_011f426c;
    m_fXValue = 0.0f;
    m_fYValue = 0.0f;
    m_fZValue = 0.0f;
    m_usFirstValue = 0;
    m_usSecondValue = 0;
}

struct C31F10BinaryStream
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(C31F10BinaryStream* pkStream, void* pvBuffer, unsigned int uiSize, unsigned int* puiSizes,
                              unsigned int ItemUpdateArray);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};

class C31F10Stream
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
    unsigned int m_uiNifVersion;
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
    C31F10BinaryStream* m_pUnderlyingStream;

    unsigned int GetFileVersion() const
    {
        return m_uiNifVersion;
    }
};

template <class T> inline void C31F10BinaryStreamLoad(C31F10BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void C31F10LoadBinary(C31F10Stream& kStream, T& value)
{
    C31F10BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

struct C31F10Point3
{
    float x;
    float y;
    float z;

    void LoadBinary(C31F10Stream& kStream);
};

struct C31F10ParticleInfo
{
    C31F10Point3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;

    void LoadParticleInfo(C31F10Stream& kStream);
};

// LoadBinary
// @fnv 0x00c31f10
// src: GUESS 0x00c31f10 (confidence: medium)
void C31F10ParticleInfo::LoadParticleInfo(C31F10Stream& kStream)
{
    m_kValue.LoadBinary(kStream);
    if (kStream.GetFileVersion() < 0x0a030005)
    {
        C31F10Point3 kRotationAxis;
        kRotationAxis.LoadBinary(kStream);
    }
    C31F10LoadBinary(kStream, m_fXValue);
    C31F10LoadBinary(kStream, m_fYValue);
    C31F10LoadBinary(kStream, m_fZValue);
    C31F10LoadBinary(kStream, m_usFirstValue);
    C31F10LoadBinary(kStream, m_usSecondValue);
}
