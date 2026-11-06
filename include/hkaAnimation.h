#pragma once

#include "hkReferencedObject.h"
#include "hkArray.h"

struct SampleRec;
class hkaAnimatedReferenceFrame;
class hkaAnnotationTrack;

typedef int hkInt32;
typedef float hkReal;


class hkaAnimation : public hkReferencedObject
{
public:
    enum HavokAnimationType
    {
        HK_UNKNOWN_ANIMATION = 0,
        HK_INTERLEAVED_ANIMATION = 1,
        HK_DELTA_COMPRESSED_ANIMATION = 2,
        HK_WAVELET_COMPRESSED_ANIMATION = 3,
        HK_MIRRORED_ANIMATION = 4,
        HK_SPLINE_COMPRESSED_ANIMATION = 5
    };

    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual unsigned int vf08();
    virtual void vf09();
    virtual void SampleIndividualTracks(int frame, float delta, SampleRec* recs, int count);
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();

    hkInt32 m_type;
    hkReal m_fAnimationDuration;
    hkInt32 m_iNumTransformTracks;
    hkInt32 m_iNumberOfFloatTracks;
    hkaAnimatedReferenceFrame* m_pExtractedMotion;
    hkArray<hkaAnnotationTrack> m_kAnnotationTracks;
};
