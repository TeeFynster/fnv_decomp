#pragma once

#include "hkVector4.h"
#include "hkTransform.h"
#include "hkQsTransform.h"

class hkDisplayGeometry;
#include "hkArray.h"
enum hkResult;
typedef float hkReal;
typedef unsigned long __w64 hkUlong;

// Interface the debug display (and the visual debugger server) draws through. The slot order is the vftable's;
// the parameter names are ours. Slots 15-19 are not reached by our units yet.
class hkDebugDisplayHandler  // src: HAVOK_SRC (class and lower-case method names)
{
public:
    virtual ~hkDebugDisplayHandler();
    virtual hkResult AddDisplayGeometry(const hkArrayBase<hkDisplayGeometry*>& kGeoms, const hkTransform& kXform,
        hkUlong uId, int iTag, hkUlong uShapeHint) = 0;
    virtual hkResult ReplaceGeometry(hkUlong uOldId, const hkTransform& kXform, hkUlong uId, int iTag,
        hkUlong uShapeHint) = 0;
    virtual hkResult SetGeometryColor(int iRgba, hkUlong uId, int iTag) = 0;
    virtual hkResult m_bUpdateGeometry(const hkTransform& kXform, hkUlong uId, int iTag) = 0;
    virtual hkResult RemoveGeometry(hkUlong uId, int iTag, hkUlong uShapeHint) = 0;
    virtual hkResult DisplayCamera(const hkVector4& kEye, const hkVector4& kTarget, const hkVector4& kUp, hkReal fNear,
        hkReal fFar, hkReal fFov, const char* szName) = 0;
    typedef hkArrayBase<int> Ints;  // shorthand for the behaviour-graph lists below
    virtual hkResult DisplayBehaviorGraph(const Ints& kWordVars, const Ints& kWordStack, const Ints& kQuadVars,
        const hkArrayBase<hkVector4>& kQuadStack, const hkArrayBase<char*>& kNodes, const Ints& kStates,
        const Ints& kTransitions, const hkArrayBase<hkQsTransform>& kPoses) = 0;
    virtual hkResult DisplayPoint(const hkVector4& kAt, int iRgba, int iId, int iTag) = 0;
    virtual hkResult DisplayLine(const hkVector4& kFrom, const hkVector4& kTo, int iRgba, int iId, int iTag) = 0;
    virtual hkResult DisplayTriangle(const hkVector4& kA, const hkVector4& kB, const hkVector4& kC, int iRgba, int iId,
        int iTag) = 0;
    virtual hkResult displayText(const char* szText, int iRgba, int iId, int iTag) = 0;
    virtual hkResult Display3DText(const char* szText, const hkVector4& kAt, int iRgba, int iId, int iTag) = 0;
    virtual hkResult DisplayAnnotation(const char* szText, int iId, int iTag);
    virtual hkResult DisplayGeometryList(const hkArrayBase<hkDisplayGeometry*>& kGeoms, int iRgba, int iId,
        int iTag) = 0;
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
};
