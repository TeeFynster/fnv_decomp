#pragma once

#include "hkaAnimation.h"
#include "hkaInterleavedUncompressedAnimation.h"
#include "hkBool.h"
#include "hkVector4.h"

struct hkaAnimationDataChunk;

typedef short hkInt16;
typedef unsigned int hkUint32;
typedef unsigned char hkUint8;

class hkaSplineCompressedAnimation : public hkaAnimation
{
public:
    struct TrackCompressionParams
    {
        enum RotationQuantization
        {
            POLAR32 = 0,
            THREECOMP40 = 1,
            THREECOMP48 = 2,
            THREECOMP24 = 3,
            STRAIGHT16 = 4,
            UNCOMPRESSED = 5
        };

        enum ScalarQuantization
        {
            BITS8 = 0,
            BITS16 = 1
        };

        template <class E> struct Quantization
        {
            hkUint8 m_kStorage;

            operator E() const { return static_cast<E>(m_kStorage); }
            void operator=(E value) { m_kStorage = static_cast<hkUint8>(value); }
        };

        hkReal m_fRotationTolerance;
        hkReal m_fTranslationTolerance;
        hkReal m_fScaleTolerance;
        hkReal m_fFloatingTolerance;
        unsigned short m_iRotationDegree;
        unsigned short m_iTranslationDegree;
        unsigned short m_iScaleDegree;
        unsigned short m_iFloatingDegree;
        Quantization<RotationQuantization> m_eRotationQuantizationType;
        Quantization<ScalarQuantization> m_eTranslationQuantizationType;
        Quantization<ScalarQuantization> m_eScaleQuantizationType;
        Quantization<ScalarQuantization> m_eFloatQuantizationType;
    };

    struct PerTrackCompressionParams
    {
        hkArray<TrackCompressionParams> m_kTrackParams;
        hkArray<hkInt32> m_kFirstIntArray;
        hkArray<hkInt32> m_kSecondIntArray;
    };

    struct AnimationCompressionParams
    {
        unsigned short m_iMaxFramesPerBlock;
        hkBool m_bEnableSampleSingleTracks;
    };

    typedef TrackCompressionParams::RotationQuantization RotationQuantization;
    typedef TrackCompressionParams::ScalarQuantization ScalarQuantization;

    void GetDataChunks(hkUint32 frame, hkReal delta, hkaAnimationDataChunk* dataChunks,
                       int numDataChunks) const throw();
    void GetBlockAndTime(hkUint32 frame, hkReal delta, int& blockOut, hkReal& blockTimeOut,
                         hkUint8& quantizedTimeOut) const throw();
    __declspec(noalias) void GetBlockAndTime(hkUint32 frame, hkReal delta, hkUint32& blockOut,
                                             hkReal& blockTimeOut, hkUint8& quantizedTimeOut) const;
    __declspec(noalias) void hkaAnimation_getFrameAndDelta(hkReal time, hkUint32& frameOut, hkReal& deltaOut) const;
    void EvaluateSpline(hkReal blockTime, hkUint8 quantizedTime, hkUint8 mask, int quantization,
                        const hkUint8*& dataInOut, hkVector4& out) const;
    void ExtractFrame(hkReal blockTime, hkUint8 quantizedTime, hkUint8 mask, int quantization,
                      const hkUint8*& dataInOut, hkQuaternion& out) const;
    void ExtractFrame(hkReal time, int quantization, int numItems, void* out,
                      const hkUint8*& dataInOut, int stride);
    void sampleScale(hkReal blockTime, hkUint8 quantizedTime, hkUint8 mask, int quantization,
                      const hkUint8*& dataInOut, hkVector4& out) const;
    void hkaSplineCompressedAnimation_sampleFloat(hkReal blockTime, hkUint8 quantizedTime, hkUint8 mask, int quantization,
                      const hkUint8*& dataInOut, hkReal& out) const;
    void sampleIndividualTransformTracks(hkReal time, const hkInt16* tracks, hkUint32 numTracks,
                      hkQsTransform* transformTracksOut) const;
    void sampleIndividualFloatTracks(hkReal time, const hkInt16* tracks, hkUint32 numTracks,
                      hkReal* floatTracksOut) const;

    int getSizeInBytes() const;
    void AppendScaledValues(int n, int degree, const hkArray<hkReal>& knots);
    void AppendScaledValues(int n, int degree, hkArray<hkReal>& knots);
    void ProcessEntries_00e319e0(hkUint8 mask, RotationQuantization quantization,
                      const hkVector4& staticValue, int n, const hkArray<hkVector4>& points);
    void WriteCompressedAnimation(hkUint8 mask, ScalarQuantization quantization,
                                  const hkVector4& staticValue, const hkVector4& minValue,
                                  const hkVector4& maxValue, int n, const hkArray<hkVector4>& points);
    void hkaSplineCompressedAnimation_initialize(const hkaInterleavedUncompressedAnimation& raw,
                      const PerTrackCompressionParams& trackParams,
                      const AnimationCompressionParams& animationParams);

    static hkVector4 Runtime_ProcessEntries_00e31410(const hkArray<hkVector4>& data);
    static hkVector4 hkArrayBase_ProcessEntries_00e31470(const hkArray<hkVector4>& data);
    static hkVector4 hkArrayBase_ProcessEntries_00e314c0(const hkArray<hkVector4>& data);
    static hkUint8 hkaSplineCompressedAnimation_isStatic(const hkVector4& mean, const hkVector4& minValue,
                               const hkVector4& maxValue, hkReal tolerance, const hkVector4& identity);
    static hkUint8 PackBitFields(ScalarQuantization translation, RotationQuantization rotation,
                                ScalarQuantization scale);
    static hkUint8 hkaSplineCompressedAnimation_packMaskAndQuantizationType(hkUint8 mask, ScalarQuantization quantization);
    static void hkaSplineCompressedAnimation_writeZeros(int n, hkArray<hkUint8>& out);
    static void hkaSplineCompressedAnimation_writeAlign(int alignment, hkArray<hkUint8>& out);
    static void FillInterpolatedValues(int n, hkArray<hkReal>& values, hkReal first, hkReal last);
    static void hkVector4_ProcessEntries_00e310c0(const hkQsTransform* transforms, int numTracks, int numFrames,
                             int first, int track, hkArray<hkVector4>& translation,
                             hkArray<hkVector4>& rotation, hkArray<hkVector4>& scale);
    static void Object_ProcessEntries_00e31180(const hkReal* floats, int numTracks, int numFrames,
                             int first, int track, hkArray<hkVector4>& values);

    hkInt32 m_iFrameCount;
    hkInt32 m_iBlockCount;
    hkInt32 m_iMaxFramesPerBlock;
    hkInt32 m_iMaskAndQuantizationSize;
    hkReal m_fBlockDuration;
    hkReal m_fBlockInverseDuration;
    hkReal m_fPerFrameDuration;
    hkArray<hkUint32> m_kFirstUInt32Array;
    hkArray<hkUint32> m_kFloatBlockOffsets;
    hkArray<hkUint32> m_kTransformOffsets;
    hkArray<hkUint32> m_kFloatOffsets;
    hkArray<hkUint8> m_data;
    hkInt32 m_iEndian;
};

typedef hkaSplineCompressedAnimation::TrackCompressionParams
    hkaSplineCompressedAnimationTrackCompressionParams;
typedef hkaSplineCompressedAnimation::AnimationCompressionParams
    hkaSplineCompressedAnimationAnimationCompressionParams;
