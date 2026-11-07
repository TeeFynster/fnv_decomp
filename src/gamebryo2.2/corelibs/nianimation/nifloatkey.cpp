#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"

// src/gamebryo2.2/corelibs/nianimation/nifloatkey.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nifloatkey.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00a26f30: this prefix is eight bytes; time/value accesses use the derived record.
struct FloatKeyPrefixView
{ // distinct from AnimationKey: 0x00a26f30 uses an 8-byte float-key prefix before tangent floats at +8/+12.
    int _00;
    int _04;
};
struct TimedAnimationKey : FloatKeyPrefixView
{
    float _08;
    float _0c;
};
bool __cdecl AreRecordsEqual(const FloatKeyPrefixView&, const FloatKeyPrefixView&);
// Returns false if AreRecordsEqual rejects the keys, otherwise compares the two float fields of the keys for equality.
// @fnv 0x00a26f30
// src: GAMEBRYO_LIB 0x00a26f30
bool NiBezFloatKey_Equal(const FloatKeyPrefixView& key0, const FloatKeyPrefixView& key1)
{
    const TimedAnimationKey* pKey1Floats = (const TimedAnimationKey*)&key1;
    const TimedAnimationKey* pKey0Floats = (const TimedAnimationKey*)&key0;
    if (!AreRecordsEqual(key0, key1))
        return false;
    return pKey0Floats->_08 == pKey1Floats->_08 && pKey0Floats->_0c == pKey1Floats->_0c;
}

// The shared header declares these helpers but does not yet expose the stream state.
inline void NiBinaryStream::Read(void* data)
{
    NiBinaryStream* __restrict input = this;
    unsigned int size = 4;
    reinterpret_cast<unsigned int*>(input)[1] +=
        (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(input) + 8))(
            input, data, 4, &size, 1);
}

inline void NiBinaryStream::Write(void* buffer)
{
    NiBinaryStream* __restrict output = this;
    unsigned int size = 4;
    reinterpret_cast<unsigned int*>(output)[1] +=
        (*reinterpret_cast<NIBINARYSTREAM_WRITEFN*>(reinterpret_cast<char*>(output) + 12))(
            output, buffer, 4, &size, 1);
}
// NiStream keeps its binary stream pointers in the opaque shared state.
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24C);
}
// Reads 4 bytes from the stream's input into pValue and advances the input position by the bytes read.
// @fnv 0x00a26df0
// src: XBOX_PDB 0x00a26df0
void NiStreamLoadBinary_float(NiStream* pkStream, void* pValue)
{
    pkStream->GetBinaryStream()->Read(pValue);
}

struct Base_00a26eb0
{
    int _0;
    void AccumulateAnimSink(NiStream&);
};
struct Holder_00a26eb0 : Base_00a26eb0
{
    float m;
    void LoadBaseAndMemberValue(NiStream&);
};
// Calls the base stream reader, then reads 4 bytes from the input stream into m and advances the stream position by the bytes read.
// @fnv 0x00a26eb0
// src: GUESS 0x00a26eb0 (confidence: medium)
void Holder_00a26eb0::LoadBaseAndMemberValue(NiStream& stream)
{
    Base_00a26eb0::AccumulateAnimSink(stream);
    stream.GetBinaryStream()->Read(static_cast<void*>(&m));
}

struct SObj
{
    char pad[4];
    float v;
};
void __cdecl CallAnimCallback(NiStream*, SObj*);
// Calls CallAnimCallback, then writes the float at a2->v and advances the output stream position by the bytes written.
// @fnv 0x00a26ef0
void WriteFloatToStream(NiStream* pStream, SObj* pObj)
{
    CallAnimCallback(pStream, pObj);
    NiBinaryStream* output =
        *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(pStream) + 0x250);
    output->Write(static_cast<void*>(&pObj->v));
}

typedef void(__cdecl* BA26E20Func)(void*);

void __cdecl CreateFloatKeys(void* pvKeys);
void __cdecl DeleteFloatKeys(void* pvKeys);
void __cdecl EqualFloatKeys(void* pvKeys);
void __cdecl SaveFloatKeys(void* pvKeys);
void __cdecl CopyFloatKeys(void* pvKeys);
void __cdecl InsertFloatKey(void* pvKeys);
void __cdecl InterpFloatKey(void* pvKeys);
void __cdecl IsPosedFloatKey(void* pvKeys);

extern bool g_bA26E20Registered;
extern BA26E20Func g_apfnA26E20CurvesCopy[];
extern BA26E20Func g_apfnA26E20Interp1[];
extern BA26E20Func g_apfnA26E20Interp2[];
extern BA26E20Func g_apfnA26E20Cubic[];
extern BA26E20Func g_apfnA26E20Create[];
extern BA26E20Func g_apfnA26E20Delete[];
extern BA26E20Func g_apfnA26E20Equal[];
extern BA26E20Func g_apfnA26E20Save[];
extern BA26E20Func g_apfnA26E20Copy[];
extern unsigned char g_aucA26E20KeySize[];
extern BA26E20Func g_apfnA26E20Insert[];
extern BA26E20Func g_apfnA26E20Interp[];
extern BA26E20Func g_apfnA26E20IsPosed[];

// Registers the float-key operations in the global function tables and key-size table, returning 1 on first registration and 0 if already registered.
// @fnv 0x00a26e20
int __cdecl RegisterFloatKeyOps()
{
    if (g_bA26E20Registered)
        return 0;

    g_bA26E20Registered = true;
    g_apfnA26E20CurvesCopy[0] = 0;
    g_apfnA26E20Interp1[0] = 0;
    g_apfnA26E20Interp2[0] = 0;
    g_apfnA26E20Cubic[0] = 0;
    g_apfnA26E20Create[0] = CreateFloatKeys;
    g_apfnA26E20Delete[0] = DeleteFloatKeys;
    g_apfnA26E20Equal[0] = EqualFloatKeys;
    g_apfnA26E20Save[0] = SaveFloatKeys;
    g_apfnA26E20Copy[0] = CopyFloatKeys;
    g_aucA26E20KeySize[0] = 8;
    g_apfnA26E20Insert[0] = InsertFloatKey;
    g_apfnA26E20Interp[0] = InterpFloatKey;
    g_apfnA26E20IsPosed[0] = IsPosedFloatKey;
    return 1;
}

// Local fallback: include/NiFloatKey.h is absent; +0 time/+4 value and
// InterpolatePosition at 0x00a26b40 agree with nirollcontroller.cpp bindings.
class NiFloatKey
{
  public:
    enum KeyType
    {
        NOINTERP,
        LINKEY,
        BEZKEY,
        TCBKEY,
        EULERKEY,
        STEPKEY
    };

    float GetTime() const
    {
        return m_fTime;
    }
    float GetValue() const
    {
        return m_fValue;
    }

    NiFloatKey* GetKeyPointerByIndex(unsigned int uiIndex, unsigned char ucKeySize)
    {
        return (NiFloatKey*)((char*)this + uiIndex * ucKeySize);
    }

    static float InterpolatePosition(float fTime, NiFloatKey* pkKeys, KeyType eType, unsigned int uiNumKeys,
                                     unsigned int& uiLastIdx, unsigned char ucSize);
    static float GetValueAtTime(float fTime, NiFloatKey* pkKeys, KeyType eType, unsigned int uiNumKeys,
                                unsigned char ucSize);

    float m_fTime;
    float m_fValue;
};

extern float g_fDefaultValueA26;

// Returns the key value at fTime, clamping to the first/last key outside the range and otherwise delegating to the interpolating lookup.
// @fnv 0x00a26d70
float NiFloatKey::GetValueAtTime(float fTime, NiFloatKey* pkKeys, KeyType eType, unsigned int uiNumKeys,
                                    unsigned char ucSize)
{
    if (uiNumKeys)
    {
        if (fTime < pkKeys->GetTime())
            return pkKeys->GetValue();

        if (fTime > pkKeys->GetKeyPointerByIndex(uiNumKeys - 1, ucSize)->GetTime())
            return pkKeys->GetKeyPointerByIndex(uiNumKeys - 1, ucSize)->GetValue();

        unsigned int uiLastIdx = 0;
        return InterpolatePosition(fTime, pkKeys, eType, uiNumKeys, uiLastIdx, ucSize);
    }
    return g_fDefaultValueA26;
}

typedef void(__cdecl* FloatKeyInterpolation)(float, const NiFloatKey*, const NiFloatKey*, float*);
extern FloatKeyInterpolation DAT_011f3c90[];

static inline const NiFloatKey& FloatKeyAt(const NiFloatKey* keys, unsigned int i, unsigned char keySize)
{
    return *(const NiFloatKey*)((const char*)keys + i * keySize);
}

// Selects a key interval for time, interpolates when a next key exists, and updates lastIndex on the multi-key path.
// @fnv 0x00a26b40
float NiFloatKey::InterpolatePosition(float time, NiFloatKey* keys, KeyType type, unsigned int count,
                                       unsigned int& lastIndex, unsigned char keySize)
{
    if (count == 1 || time == -3.4028234663852886e+38)
        return keys->m_fValue;

    unsigned int end = count - 1;
    unsigned int last = lastIndex;
    float lastTime = FloatKeyAt(keys, last, keySize).m_fTime;
    if (time < lastTime)
    {
        last = 0;
        lastTime = keys->m_fTime;
    }
    float nextTime = 0.0f;
    unsigned int next = last + 1;
    __assume(next <= end);
    for (; next <= end; next++)
    {
        nextTime = FloatKeyAt(keys, next, keySize).m_fTime;
        if (time <= nextTime)
            break;
        lastTime = nextTime;
        last++;
    }
    float result;
    if (next < count)
    {
        float t = (time - lastTime) / (nextTime - lastTime);
        DAT_011f3c90[type](t, &FloatKeyAt(keys, last, keySize), &FloatKeyAt(keys, next, keySize), &result);
    }
    else
        result = FloatKeyAt(keys, last, keySize).m_fValue;
    lastIndex = last;
    return result;
}
