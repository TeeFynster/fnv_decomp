#pragma once

#include "bhkConvexShape.h"
#include "NiPoint3.h"

class hkpCapsuleShape;
class RigidBodyShape;
class hkVector4;
class hkSphere;
class hkTransform;
class hkContactPoint;
class hkGeometry;

class bhkCapsuleShape : public bhkConvexShape
{
public:
    bhkCapsuleShape();
    bhkCapsuleShape(const NiPoint3& point1, const NiPoint3& point2, float radius);
    virtual ~bhkCapsuleShape();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& cloningProcess);
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual void GetViewerStrings(NiViewerStringsArray* viewerStrings);
    virtual void vf41();
    virtual unsigned int slotA8();
    virtual MoppCodeHeader* slotB4(char* pAllocated);
    virtual void bhkShape_CopyMembers(void* object, ArgB* arg);
    virtual void BuildDisplayGeometry_00ca6b60(NiNode* parent, int arg);

    hkpCapsuleShape* Gethk();
    hkpCapsuleShape* operator*();
    RigidBodyShape& GetCinfo();
    NiPoint3 GetVertex(int which);
    const hkVector4& GethkVertex(int which);
    bool GetClosestPoints(const hkSphere& sphere, const hkTransform& transform, hkContactPoint& point);
    void GetDisplayGeometry(hkGeometry& geometry);
    void CopyCinfo(RigidBodyShape& cinfo);
    void bhkCapsuleShape_Init(const hkVector4& a, const hkVector4& b, float radius);
    int __thiscall InitializeCapsuleShape();
    unsigned int __thiscall retn_48() const;
    bhkCapsuleShape& operator=(const bhkCapsuleShape& other);

    static NiObject* __cdecl CreateObject();
    static bhkCapsuleShape* GetFromRigidBody(const hkpShape* shape);
    static const NiRTTI ms_kRTTI;
    static unsigned int iCount;
};
