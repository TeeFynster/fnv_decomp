#pragma once

#include "bhkSphereRepShape.h"
#include "NiRTTI.h"

class hkpConvexShape;
class hkpShape;
class PhysicsShapeClass;

class bhkConvexShape : public bhkSphereRepShape
{
public:
    bhkConvexShape();
    virtual ~bhkConvexShape();

    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual void GetViewerStrings(NiViewerStringsArray* viewerStrings);

    hkpConvexShape* Gethk();
    hkpConvexShape* operator*();
    PhysicsShapeClass& GetCinfo();
    float GetRadius();
    void SetRadius(float radius);
    void CopyCinfo(PhysicsShapeClass& cinfo);
    void bhkBoxShape_Init(unsigned int);
    void bhkCapsuleShape_Init_00cab820(int a);

    static bhkConvexShape* GetFromRigidBody(const hkpShape* shape);

    static const NiRTTI ms_kRTTI;
    static unsigned int iCount;
};
