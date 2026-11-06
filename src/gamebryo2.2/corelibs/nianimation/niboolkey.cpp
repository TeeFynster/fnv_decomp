
// src/gamebryo2.2/corelibs/nianimation/niboolkey.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niboolkey.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct OutputStream
{
    unsigned int flags;
    unsigned int written;
    unsigned int capacity;
    int(__cdecl* write)(OutputStream*, const void*, unsigned int, const void*, unsigned int);
};
struct SStream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    OutputStream* output;
};
struct SObj
{
    unsigned int state;
    bool enabled;
};
void CallAnimCallback(SStream*, SObj*);
// Calls CallAnimCallback, then writes the object's enabled flag as one byte to the stream's output and adds the written count.
// @fnv 0x00a295f0
void WriteEnabledFlag(SStream* stream, SObj* object)
{
    CallAnimCallback(stream, object);
    bool enabled = object->enabled != 0;
    unsigned int size;
    OutputStream* output = stream->output;
    int(__cdecl * write)(OutputStream*, const void*, unsigned int, const void*, unsigned int) = output->write;
    size = 1;
    output->written += write(output, &enabled, 1, &size, 1);
}

#include "../../../../include/NiAnimationKey.h"

struct BooleanKey : public NiAnimationKey
{
    bool m_bValue;
};

typedef void(__cdecl* InterpFn)(float, const NiAnimationKey*, const NiAnimationKey*, void*);
extern InterpFn DAT_011f3d08[];

// Returns the single BooleanKey value for one key or sentinel time; otherwise interpolates between bracketing keys and returns the result.
// @fnv 0x00a29250
bool InterpolateBooleanKey(float fTime, const NiAnimationKey* pkKeys, unsigned int uiType, unsigned int uiNumKeys,
                           unsigned int* puiLastIdx, unsigned char ucKeySize)
{
    if (uiNumKeys == 1 || fTime == -3.4028234663852886e+38)
        return ((const BooleanKey*)pkKeys)[0].m_bValue;

    unsigned int uiNumKeysM1 = uiNumKeys - 1;
    unsigned int uiLastIdx = *puiLastIdx;
    float fLastTime = ((const NiAnimationKey*)((const char*)pkKeys + uiLastIdx * ucKeySize))->m_fTime;

    if (fTime < fLastTime)
    {
        uiLastIdx = 0;
        fLastTime = pkKeys->m_fTime;
    }

    float fNextTime = 0.0f;
    unsigned int i;
    i = uiLastIdx + 1;
    __assume(i <= uiNumKeysM1);
    for (; i <= uiNumKeysM1; i++)
    {
        const NiAnimationKey* pkKey = (const NiAnimationKey*)((const char*)pkKeys + i * ucKeySize);
        fNextTime = pkKey->m_fTime;
        if (fTime <= fNextTime)
            break;
        fLastTime = fNextTime;
        uiLastIdx++;
    }

    float fNormTime = (fTime - fLastTime) / (fNextTime - fLastTime);
    const NiAnimationKey* pkKey0 = (const NiAnimationKey*)((const char*)pkKeys + uiLastIdx * ucKeySize);
    const NiAnimationKey* pkKey1 = (const NiAnimationKey*)((const char*)pkKeys + i * ucKeySize);

    bool bResult;
    typedef void(__cdecl * InterpFnType)(float, const NiAnimationKey*, const NiAnimationKey*, void*);
    InterpFnType pfnInterp = DAT_011f3d08[uiType];
    pfnInterp(fNormTime, pkKey0, pkKey1, &bResult);

    *puiLastIdx = uiLastIdx;
    return bResult;
}

namespace sa27320 {

class BinaryStream
{
  public:
    virtual void v00();

    unsigned int m_uiStreamFlags;
    int unk08;
    unsigned int (*m_pfnWrite)(BinaryStream* pkStream, const void* pvBuffer, unsigned int uiBytes,
                               unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiWritten = m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiWritten;
        return uiWritten;
    }
};

struct Stream
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    BinaryStream* m_pBackingStream;
};

template <class T> inline void BinaryStreamSave(BinaryStream& kStream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryWrite(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

template <class T> inline void StreamSaveBinary(Stream& kStream, const T& kValue)
{
    BinaryStreamSave(*kStream.m_pBackingStream, &kValue, 1);
}

struct Key
{
    int unk00;
    int unk04;
    int m_iValue0;
    int m_iValue1;
};

void WriteFloatToStream(Stream& kStream, const Key* pkKey);

// For each key, calls WriteFloatToStream, then writes m_iValue0 and m_iValue1 with StreamSaveBinary.
// @fnv 0x00a27320
void SaveKeys(Stream& kStream, const Key* pkKeys, unsigned int uiNumKeys)
{
    for (unsigned int i = 0; i < uiNumKeys; i++)
    {
        WriteFloatToStream(kStream, &pkKeys[i]);
        StreamSaveBinary(kStream, pkKeys[i].m_iValue0);
        StreamSaveBinary(kStream, pkKeys[i].m_iValue1);
    }
}

}
