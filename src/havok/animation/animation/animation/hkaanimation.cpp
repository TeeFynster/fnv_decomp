
// src/havok/animation/animation/animation/hkaanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/hkaanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkReferencedObject.h"

typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;


// @fnv 0x00e2f270
// src: COMMUNITY 0x00e2f270
void __stdcall nullsub_85(int)
{}

struct FUN_00cb0c30_s
{
    char* m_pcString;
    void UpdateState_00cb0c30(const FUN_00cb0c30_s& kOther) throw();
};
class hkaAnnotationTrack
{
  public:
    struct Annotation
    {
        hkReal m_uiCommandId;
        FUN_00cb0c30_s m_pText;

        Annotation& operator=(const Annotation& kOther)
        {
            m_uiCommandId = kOther.m_uiCommandId;
            m_pText.UpdateState_00cb0c30(kOther.m_pText);
            return *this;
        }
    };
    hkaAnnotationTrack(const hkaAnnotationTrack& other);
    ~hkaAnnotationTrack();
    hkaAnnotationTrack& operator=(const hkaAnnotationTrack& other);

    FUN_00cb0c30_s m_kTrackName;
    hkArray<Annotation> m_kAnnotations;
};
class hkaAnimatedReferenceFrame;

template <class T> struct hkRefPtr
{
    T* m_pRetainedObject;

    hkRefPtr() : m_pRetainedObject(0) {}
    __forceinline void operator=(const hkRefPtr& other)
    {
        if (other.m_pRetainedObject)
            reinterpret_cast<hkReferencedObject*>(other.m_pRetainedObject)->addReference();
        if (m_pRetainedObject)
            reinterpret_cast<hkReferencedObject*>(m_pRetainedObject)->removeReference();
        m_pRetainedObject = other.m_pRetainedObject;
    }
};

// LocalhkaAnimation: include/hkaAnimation.h holds the extracted motion as a raw pointer; the copy constructor
// 0x00e2f500 copies it as a reference-counted hkRefPtr (11 bytes differ with the shared form).
class LocalhkaAnimation : public hkReferencedObject
{
  public:
    struct TrackAnnotation
    {
        hkUint16 m_usTrackIndex;
        hkaAnnotationTrack::Annotation m_kAnnotation;
    };

    virtual ~LocalhkaAnimation();
    LocalhkaAnimation(const LocalhkaAnimation& other) throw();
    int CountAnnotationsInRange(float from, float delta);
    hkUint32 GetAnnotationsInRange(hkReal fStartTime, hkReal fMoveElapsedTime,
                                  TrackAnnotation* pkAnnotationsOut, hkUint32 uiMaxAnnotations) const throw();

    int m_type;
    float m_fAnimationDuration;
    int m_iNumTransformTracks;
    int m_iNumberOfFloatTracks;
    hkRefPtr<hkaAnimatedReferenceFrame> m_pExtractedMotion;
    hkArray<hkaAnnotationTrack> m_kAnnotationTracks;
};

static const double kNegOne = -3.402820018375656e+38;

// @fnv 0x00e2f280
int LocalhkaAnimation::CountAnnotationsInRange(float from, float delta)
{
    float to = from + delta;
    float wrapped = (to > m_fAnimationDuration) ? (to - m_fAnimationDuration) : kNegOne;

    int count = 0;
    for (int i = 0; i < m_kAnnotationTracks.m_iElementCount; ++i)
    {
        hkaAnnotationTrack& track = m_kAnnotationTracks.m_data[i];
        for (int j = 0; j < track.m_kAnnotations.m_iElementCount; ++j)
        {
            if ((track.m_kAnnotations.m_data[j].m_uiCommandId >= from &&
                 track.m_kAnnotations.m_data[j].m_uiCommandId < to) ||
                track.m_kAnnotations.m_data[j].m_uiCommandId < wrapped)
            {
                count++;
            }
        }
    }
    return count;
}

// hkMemoryRouter: TLS accessor 0x00c85750; the heap allocator is at +0x10, as in hkstring.cpp.
// Retained locally because include/hkMemoryRouter.h is not available.
#include "../../../../../include/hkMemoryRouter.h"

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();

inline void* operator new(unsigned int, void* pvWhere)
{
    return pvWhere;
}
template <class T> __forceinline void destructArrayElements(T* pArr, int n)
{
    for (int i = 0; i < n; i++)
        pArr[i].~T();
}

template <class T> __forceinline void copyArrayElements(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

template <class T> __forceinline void constructArrayElements(T* pDst, int n, const T* pSrc)
{
    for (int i = 0; i < n; i++)
        ::new (static_cast<void*>(pDst + i)) T(pSrc[i]);
}

template <class T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kAlloc, int n)
{
    if (getCapacity() < n)
    {
        int iCap2 = 2 * getCapacity();
        int iNewSize = (n < iCap2) ? iCap2 : n;
        hkArrayUtil::_reserve(kAlloc, this, iNewSize, sizeof(T));
    }
}

template <class T, class Allocator>
__forceinline hkArray<T, Allocator>& hkArray<T, Allocator>::operator=(const hkArray& a)
{
    hkMemoryAllocator& kAlloc = hkMemoryRouter_getInstance().heap();
    const int iOldSize = m_iElementCount;
    const int iNewSize = a.m_iElementCount;
    int iCopiedSize = (iNewSize > iOldSize) ? iOldSize : iNewSize;
    GrowArrayCapacity(kAlloc, iNewSize);
    destructArrayElements(m_data + iNewSize, iOldSize - iNewSize);
    copyArrayElements(m_data, a.m_data, iCopiedSize);
    constructArrayElements(m_data + iCopiedSize, iNewSize - iCopiedSize, a.m_data + iCopiedSize);
    m_iElementCount = iNewSize;
    return *this;
}

// @fnv 0x00e2f500
LocalhkaAnimation::LocalhkaAnimation(const LocalhkaAnimation& other) throw()
{
    m_type = other.m_type;
    m_fAnimationDuration = other.m_fAnimationDuration;
    m_iNumTransformTracks = other.m_iNumTransformTracks;
    m_iNumberOfFloatTracks = other.m_iNumberOfFloatTracks;
    m_pExtractedMotion = other.m_pExtractedMotion;
    m_kAnnotationTracks = other.m_kAnnotationTracks;
}

// @fnv 0x00e2f3e0
hkUint32 LocalhkaAnimation::GetAnnotationsInRange(hkReal m_fStartTime, hkReal fMoveElapsedTime,
                                             TrackAnnotation* pkAnnotationsOut,
                                             hkUint32 uiMaxAnnotations) const throw()
{
    if (uiMaxAnnotations == 0)
        return 0;
    const hkReal m_fMaximumDistance = m_fStartTime + fMoveElapsedTime;
    const hkReal fWrappedEndTime =
        (m_fMaximumDistance > m_fAnimationDuration) ? m_fMaximumDistance - m_fAnimationDuration : -3.40282e+38f;
    hkUint32 uiNumAnnotations = 0;
    const int iNumTracks = m_kAnnotationTracks.m_iElementCount;
    for (hkUint16 i = 0; i < iNumTracks; i++)
    {
        const hkaAnnotationTrack& kTrack = m_kAnnotationTracks.m_data[i];
        const int iNumTrackAnnotations = kTrack.m_kAnnotations.m_iElementCount;
        for (int j = 0; j < iNumTrackAnnotations; j++)
        {
            const hkReal& fTime = kTrack.m_kAnnotations.m_data[j].m_uiCommandId;
            if ((fTime >= m_fStartTime && fTime < m_fMaximumDistance) || fTime < fWrappedEndTime)
            {
                pkAnnotationsOut[uiNumAnnotations].m_usTrackIndex = i;
                pkAnnotationsOut[uiNumAnnotations].m_kAnnotation = kTrack.m_kAnnotations.m_data[j];
                uiNumAnnotations++;
                if (uiNumAnnotations == uiMaxAnnotations)
                    return uiNumAnnotations;
            }
        }
    }
    return uiNumAnnotations;
}
