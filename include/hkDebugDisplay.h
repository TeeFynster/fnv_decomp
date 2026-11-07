#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkSingleton.h"
#include "hkDebugDisplayHandler.h"
#include "hkDisplayGeometry.h"
#include "hkVector4_S.h"
#include "hkBool.h"
#include "hkArray.h"

class PhysicsSimulationContext;
class hkTransform_S;
class hkQsTransform_S;
class hkAabb;
typedef float hkReal_S;
typedef signed short hkInt16_S;
typedef unsigned long __w64 hkUlong_S;
typedef hkBool hkBool_S;

// Havok's debug-display singleton: forwards every draw request to the registered handlers (m_kDebugDisplayHandlers).
// Method names: HAVOK_SRC where lower-case, our names where capitalised; non-virtual, so their order here is free.
class hkDebugDisplay : public hkReferencedObject, public hkSingleton<hkDebugDisplay>  // src: HAVOK_SRC (class)
{
    friend class hkSingleton<hkDebugDisplay>;

public:
    class CommandArgument;

    hkDebugDisplay();
    virtual ~hkDebugDisplay() throw();

    static void* __cdecl operator new(std::size_t uBytes);
    static void* __cdecl operator new(std::size_t uBytes, void* pWhere);
    static void* __cdecl operator new[](std::size_t uBytes, void* pWhere);
    static void __cdecl operator delete(void* pMem);
    static void __cdecl operator delete(void* pMem, void* pWhere);
    static void __cdecl operator delete[](void* pMem, void* pWhere);

    // handler list
    void addDebugDisplayHandler(hkDebugDisplayHandler* pHandler);
    void removeDebugDisplayHandler(hkDebugDisplayHandler* pHandler);
    void clear();

    // persistent geometry, addressed by (id, tag)
    void AddDisplayGeometry(const hkArray<hkDisplayGeometry*>& kGeoms, const hkTransform_S& kXform, hkUlong_S uId, int iTag, hkUlong_S uShapeHint);
    void ReplaceGeometry(hkUlong_S uOldId, const hkTransform_S& kXform, hkUlong_S uId, int iTag, hkUlong_S uShapeHint);
    void m_bUpdateGeometry(const hkTransform_S& kXform, hkUlong_S uId, int iTag);
    void SetGeometryColor(int iRgba, hkUlong_S uId, int iTag);
    void RemoveGeometry(hkUlong_S uId, int iTag, hkUlong_S uShapeHint);

    // immediate-mode geometry lists and boxes
    void DisplayGeometryList(const hkArrayBase<hkDisplayGeometry*>& kGeoms, int iRgba, int iId, int iTag);
    void DisplayGeometryList(const hkArrayBase<hkDisplayGeometry*>& kGeoms, const hkTransform_S& kXform, int iRgba, int iId, int iTag);
    void displayAabb(const hkAabb& kBox, int iRgba, int iId, int iTag);

    // immediate-mode primitives (world space, then the model-space forms)
    void DisplayPoint(const hkVector4_S& kAt, int iRgba, int iId, int iTag);
    void DisplayLine(const hkVector4_S& kFrom, const hkVector4_S& kTo, int iRgba, int iId, int iTag);
    void RenderLine(const hkVector4_S& kFrom, const hkVector4_S& kDir, int iRgba, int iId, int iTag);
    void displayRay(const hkVector4_S& kFrom, const hkVector4_S& kDir, int iRgba, int iId, int iTag);
    void displayStar(const hkVector4_S& kAt, hkReal_S fSize, int iRgba, int iId, int iTag);
    void DisplayPlane(const hkVector4_S& kPlane, const hkVector4_S& kOffset, hkReal_S fSize, int iRgba, int iId, int iTag);
    void DisplayTriangle(const hkVector4_S& kA, const hkVector4_S& kB, const hkVector4_S& kC, int iRgba, int iId, int iTag);
    void displayLitTriangle(const hkVector4_S& kA, const hkVector4_S& kB, const hkVector4_S& kC, int iRgba);
    void displayLineModelSpace(const hkTransform_S& kModelToWorld, const hkVector4_S& kFrom, const hkVector4_S& kTo, int iRgba, int iId, int iTag);
    void displayLineModelSpace(const hkQsTransform_S& kModelToWorld, const hkVector4_S& kFrom, const hkVector4_S& kTo, int iRgba, int iId, int iTag);
    void displayRayModelSpace(const hkTransform_S& kModelToWorld, const hkVector4_S& kFrom, const hkVector4_S& kDir, int iRgba, int iId, int iTag);
    void displayRayModelSpace(const hkQsTransform_S& kModelToWorld, const hkVector4_S& kFrom, const hkVector4_S& kDir, int iRgba, int iId, int iTag);
    void displayStarModelSpace(const hkTransform_S& kModelToWorld, const hkVector4_S& kAt, hkReal_S fSize, int iRgba, int iId, int iTag);
    void displayStarModelSpace(const hkQsTransform_S& kModelToWorld, const hkVector4_S& kAt, hkReal_S fSize, int iRgba, int iId, int iTag);
    void displayFrame(const hkTransform_S& kFrame, hkReal_S fSize, int iId, int iTag);
    void displayFrame(const hkQsTransform_S& kFrame, hkReal_S fSize, int iId, int iTag);

    // skeleton poses (defaults as the callers pass them)
    void displayModelSpacePose(int iBones, const hkInt16_S* psParents, const hkQsTransform_S* pkModelPose, const hkQsTransform_S& kModelToWorld,
        int iId, int iTag, int iRgba = 0x7fffffff, hkReal_S fAxisSize = 0.25f, hkBool_S bRootTranslation = false);
    void displayLocalSpacePose(int iBones, const hkInt16_S* psParents, const hkQsTransform_S* pkLocalPose, const hkQsTransform_S& kModelToWorld,
        int iId, int iTag, int iRgba = 0x7fffffff, hkReal_S fAxisSize = 0.25f, hkBool_S bRootTranslation = false);

    // text, camera, behaviour graph
    void displayText(const char* szText, int iRgba, int iId, int iTag);
    void Display3DText(const char* szText, const hkVector4_S& kAt, int iRgba, int iId, int iTag);
    void DisplayCamera(const hkVector4_S& kEye, const hkVector4_S& kTarget, const hkVector4_S& kUp, hkReal_S fNear, hkReal_S fFar, hkReal_S fFov, const char* szName);
    void DisplayBehaviorGraph(hkArray<int>& kWordVars, hkArray<int>& kWordStack, hkArray<int>& kQuadVars, hkArray<hkVector4_S>& kQuadStack,
        hkArray<char*>& kNodes, hkArray<int>& kStates, hkArray<int>& kTransitions, hkArray<hkQsTransform_S>& kPoses);

    hkArray<hkDebugDisplayHandler*> m_kDebugDisplayHandlers;
    mutable PhysicsSimulationContext* m_pPhysicsSimulationContext;
};
