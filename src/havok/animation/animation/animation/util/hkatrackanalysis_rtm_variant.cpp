// src/havok/animation/animation/animation/util/hkatrackanalysis_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/animation/animation/animation/util/hkatrackanalysis.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/animation/animation/animation/util/hkatrackanalysis.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/util/hkatrackanalysis.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"

struct TrackAnalysis
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int count;
    int sum;
    int max;
};
void AnalyzeTrackBits(const unsigned short* values, unsigned int count, TrackAnalysis* result);
void AnalyzeTrackBits(const unsigned short* values, unsigned int count, TrackAnalysis* result);
void AnalyzeTrackWithZeroCount(const unsigned short* aFirstValues, const unsigned short* values,
                               unsigned int firstCount, unsigned int count, TrackAnalysis* result);
struct TraceSink
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void write(int, int, const char*, const char*, int);
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void begin(unsigned int, const char*);
    virtual void end();
};
extern TraceSink* DAT_01268360;
extern const char str_010ec758[];
extern const char str_010ec724[];
extern const char str_010ec74c[];
extern const char str_010ec70c[];
extern const char str_010ec6f4[];
extern const char str_010ec6e0[];
extern const char str_010ec6cc[];
extern const char str_010ec6b4[];
extern const char str_010ec69c[];
extern const char str_010ec688[];
extern const char str_010ec670[];
extern const char str_010ec658[];
extern const char str_010ec644[];
extern const char str_010ec6f40[];
extern const char str_010ec624[];
struct TextBuilder
{
    int state;
    int length;
    int bufferCapacity;
    void FUN_00cb1600(char*, unsigned int);
    TextBuilder* ProcessAndReturnValue_00cc01c0(const char*, int);
    TextBuilder* ProcessAndReturnValue_00cc01c0(const char*, float);
    void EvaluateValue_00cc02d0();
    void WriteFloat();
    void FUN_00cc00e0();
};
struct TrackStatistics
{
    int field0;
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    int field6;
    int field7;
    int field8;
    int field9;
    int field10;
    int total0;
    int total1;
    float rate;
    void LogStatistics();
};
// hkMemoryRouter is the shared router: GetMonitorStream binds to 0x00c85750
// in hkjobqueue_ehsc_noehsc_variant.cpp; its heap pointer is at +0x10.

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}

template <class T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kAllocator, int n)
{
    const int iCapacity = getCapacity();
    if (iCapacity < n)
    {
        int iCap = 2 * iCapacity;
        int iNewSize = (n < iCap) ? iCap : n;
        hkArrayUtil::_reserve(kAllocator, this, iNewSize, sizeof(T));
    }
}

template <class T>
__forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& kAllocator, int n)
{
    GrowArrayCapacity(kAllocator, n);
    m_iElementCount = n;
}
struct TrackHeader_e50650
{
    int m_iUnk00;
    int m_iArrayLength;
    int m_iUnk08;
};
struct TrackSource_e50650
{
    TrackHeader_e50650 m_kHeader;
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
    float m_fD;
    unsigned char m_ucE;
};
struct TrackBuffers_e50650
{
    TrackHeader_e50650 m_kHeader;
    hkArray<float> m_kA;
    hkArray<float> m_kB;
    hkArray<float> m_kC;
    hkArray<float> m_kCubicCoefficient;
    hkArray<unsigned char> m_kE;

    void ReleaseFiveArrays();
};
void hkaTrackAnalysis_analyzeQsTransform(TrackBuffers_e50650* pkBuffers, void* pkArg, void* pkArgCur, hkBool bFlag);
void ExpandTrackSource(const TrackSource_e50650* pkSource, void* pkArg, void* pkArgCur);
struct StatsB0
{
    unsigned int m_iWordAt00, m_iWordAt04, m_8, m_iThirdValue, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30;
    float m_34;
};
__declspec(noinline) void __cdecl Analyze(const unsigned short* p, unsigned int count, StatsB0* s)
{
    for (unsigned int i = 0; i < count; i++)
        s->m_1c += p[i] & 3;
}
__declspec(noinline) void __cdecl CountTail(const unsigned short* p, void* a1, unsigned int count, unsigned int a3,
                                            StatsB0* s)
{
    Analyze(p, count, s);
    Analyze((const unsigned short*)a1, a3, s);
}
void __cdecl hkaTrackAnalysis_calcStats(const unsigned short* p, void* a1, unsigned int count, unsigned int a3, StatsB0* s);
#include <xmmintrin.h>
#include <math.h>
struct PerTransformIn
{
    const void* boneData;
    unsigned int numberOfTransformTracks;
    unsigned int numberOfPoses;
};
struct PerFloatIn
{
    const float* floatData;
    unsigned int numberOfFloatTracks;
    unsigned int numberOfPoses;
    hkArray<float> absoluteTolerance;
};
static __forceinline void ClearStatistics(TrackStatistics& s)
{
    s.field0 = 0;
    s.field1 = 0;
    s.field2 = 0;
    s.field3 = 0;
    s.field4 = 0;
    s.field5 = 0;
    s.field6 = 0;
    s.field7 = 0;
    s.field8 = 0;
    s.field9 = 0;
    s.field10 = 0;
    s.total0 = 0;
    s.total1 = 0;
    s.rate = 0.0f;
}
struct PassBool
{
    unsigned char value;
    PassBool(bool b) : value(b)
    {}
    PassBool(const PassBool& other) : value(other.value)
    {}
};
typedef void(__cdecl* QsAnalyzeFn)(TrackBuffers_e50650*, void*, void*, PassBool);
void __cdecl hkaTrackAnalysis_calcStatsQsTransform(const unsigned short* mask, unsigned int count, TrackStatistics* result);
void __cdecl hkaTrackAnalysis_calcStats(const unsigned short* maskT, const unsigned short* maskF, unsigned int numT,
                          unsigned int numF, TrackStatistics* result);
struct FloatLocalArray
{
    hkArray<float> values;
    float* localMemory;

    __forceinline void allocate(int n)
    {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        char* block = static_cast<char*>(router->m_stack.m_next.m_storage);
        router->m_stack.m_next.m_storage = block + ((n * 4 + 127) & ~127);
        values.m_iCapacityState = n | 0x80000000;
        values.m_data = (float*)block;
        localMemory = (float*)block;
    }

    __forceinline void freeStorage(hkMemoryAllocator& alloc)
    {
        int cap = values.m_iCapacityState;
        values.m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc.bufFree(values.m_data, (cap & 0x3fffffff) * 4);
        }
        values.m_data = 0;
        values.m_iCapacityState = 0x80000000;
    }

    __forceinline void release()
    {
        float* saved = localMemory;
        if (saved == values.m_data)
        {
            values.m_iElementCount = 0;
        }
        hkMemoryRouter::getInstance().m_stack.m_next.m_storage = saved;
        freeStorage(hkContainerHeapAllocator().get(&values));
    }
};
void __cdecl hkaTrackAnalysis_analyze(const PerTransformIn& input, const PerFloatIn& finput, unsigned short* staticMask,
                          float* staticDOFs, hkBool displayStatsReport);
struct StatisticsResult
{
    unsigned int field0, field1, field2, field3, field4, field5, field6, field7, field8, field9, field10, total0,
        total1;
    float rate;
    void LogStatistics();
};
__declspec(noinline) void AnalyzeTrackBits(const unsigned short* values, unsigned int count, StatisticsResult* result)
{
    result->field7 = 0;
    result->field8 = 0;
    result->field9 = 0;
    for (unsigned int i = 0; i < count; i++)
    {
        unsigned int v = values[i] >> 6;
        result->field7 += ((v >> 2) & 1) + ((v >> 1) & 1) + (v & 1);
        result->field8 += ((v >> 6) & 1) + ((v >> 5) & 1) + ((v >> 4) & 1) + ((v >> 3) & 1);
        result->field9 += ((v >> 9) & 1) + ((v >> 8) & 1) + ((v >> 7) & 1);
    }
}
void __cdecl hkaTrackAnalysis_calcStatsQsTransform(const unsigned short* mask, unsigned int count, StatisticsResult* result);

struct SplitVector
{
    float values[4];
    const float& operator()(int i) const
    {
        return values[i];
    }
};
struct SplitTransform
{
    SplitVector position, rotation, scale;
    const SplitVector& getPosition() const
    {
        return position;
    }
    const SplitVector& getRotation() const
    {
        return rotation;
    }
    const SplitVector& getScale() const
    {
        return scale;
    }
};
struct SplitInput
{
    const SplitTransform* transforms;
    unsigned transformCount;
    const float* floats;
    unsigned floatCount;
    unsigned frameCount;
    unsigned paddedCount;
    const unsigned short* masks;
};

// @fnv 0x00e4ecb0
// src: HAVOK_LIB 0x00e4ecb0
void hkaTrackAnalysis_channelSplit(const SplitInput& input, float* output)
{
    const unsigned frames = input.frameCount;
    const unsigned width = frames > input.paddedCount ? frames : input.paddedCount;
    const unsigned tracks = input.transformCount;
    unsigned channel = 0;
    for (unsigned track = 0; track < tracks; ++track)
    {
        const unsigned short mask = input.masks[track];
        const unsigned short selected = mask >> 6;
        if (!(mask & 3))
        {
            for (int component = 0; component < 3; ++component)
            {
                if (selected & (1 << (2 - component)))
                {
                    for (unsigned frame = 0; frame < frames; ++frame)
                        output[channel * width + frame] =
                            input.transforms[frame * tracks + track].getPosition()(component);
                    const unsigned last = (frames - 1) * tracks + track;
                    for (unsigned frame = frames; frame < width; ++frame)
                        output[channel * width + frame] = input.transforms[last].getPosition()(component);
                    ++channel;
                }
            }
        }
        if (!(mask & 12))
        {
            for (int component = 0; component < 4; ++component)
            {
                if (selected & (1 << (6 - component)))
                {
                    for (unsigned frame = 0; frame < frames; ++frame)
                        output[channel * width + frame] =
                            input.transforms[frame * tracks + track].getRotation()(component);
                    const unsigned last = (frames - 1) * tracks + track;
                    for (unsigned frame = frames; frame < width; ++frame)
                        output[channel * width + frame] = input.transforms[last].getRotation()(component);
                    ++channel;
                }
            }
        }
        if (!(mask & 48))
        {
            for (int component = 0; component < 3; ++component)
            {
                if (selected & (1 << (9 - component)))
                {
                    for (unsigned frame = 0; frame < frames; ++frame)
                        output[channel * width + frame] =
                            input.transforms[frame * tracks + track].getScale()(component);
                    const unsigned last = (frames - 1) * tracks + track;
                    for (unsigned frame = frames; frame < width; ++frame)
                        output[channel * width + frame] = input.transforms[last].getScale()(component);
                    ++channel;
                }
            }
        }
    }
    for (unsigned track = 0; track < input.floatCount; ++track)
    {
        if (input.masks[input.transformCount + track] == 0)
        {
            for (unsigned frame = 0; frame < frames; ++frame)
                output[channel * width + frame] = input.floats[frame * input.floatCount + track];
            const unsigned last = (frames - 1) * input.floatCount + track;
            for (unsigned frame = frames; frame < width; ++frame)
                output[channel * width + frame] = input.floats[last];
            ++channel;
        }
    }
}
