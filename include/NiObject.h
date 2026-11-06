#pragma once

#include "NiRefObject.h"

class NiRTTI;
class NiNode;
class BSFadeNode;
class BSMultiBoundNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class BSResizableTriShape;
class NiParticles;
class NiLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;
class CloningProcess;
class NiStream;
class NiBound;
class NiObjectGroup;
class NiControllerManager;
template <class T> class NiPointer;
template <class T> class NiTPrimitiveArray;
typedef NiTPrimitiveArray<const char*> NiViewerStringsArray;

class NiObject : public NiRefObject
{
  public:
    NiObject();
    virtual ~NiObject();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* IsSceneNode() const;
    virtual BSFadeNode* IsFadeNode() const;
    virtual BSMultiBoundNode* IsMultiBoundNode() const;
    virtual NiGeometry* IsGeometry() const;
    virtual NiTriBasedGeom* IsTriBasedGeometry() const;
    virtual NiTriStrips* IsTriStrips() const;
    virtual NiTriShape* IsTriShape() const;
    virtual BSSegmentedTriShape* IsSegmentedTriShape() const;
    virtual BSResizableTriShape* IsResizableTriShape() const;
    virtual NiParticles* IsParticlesGeom() const;
    virtual NiLines* IsLineGeometry() const;
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject() const;
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject() const;
    virtual bhkRigidBody* IsBhkRigidBody() const;
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual void AddViewerStrings(NiViewerStringsArray* apStrings);
    virtual void ProcessClone(CloningProcess& arCloning);
    virtual void PostLinkObject(NiStream& arStream);
    virtual bool StreamCanSkip();
    virtual const NiRTTI* GetStreamableRTTI();
    virtual void SetObjectBound(NiBound* apNewBound);
    virtual unsigned int GetBlockAllocationSize();
    virtual NiObjectGroup* GetGroup();
    virtual void SetGroup(NiObjectGroup* apGroup);
    virtual NiControllerManager* IsControllerManager() const;

    NiObject* Clone();
    NiObject* CloneObject(CloningProcess&);
    void ResolveObjectPointer(NiPointer<NiObject>&);
    NiObject* DynamicCast(const NiRTTI*);
    NiObject* DynamicCast(const NiRTTI*) const;
    NiObject* DynamicCast(const void*);
    NiObject* DynamicCast(const unsigned int*);
    bool IsKindOfType(const NiRTTI*) const;
    bool IsSameAs(NiObject*);
    void CopyMembersStream(unsigned int, void*);
    void CopyMembersStream(NiObject*, void*);
    void CopyMembersStream(NiObject*, CloningProcess*);
    void CopyMemberData(NiObject*, CloningProcess&);
    void CreateVertexBufferSet(NiObject*, CloningProcess&);
    float GetFloatAtOffsetB0();
    const NiRTTI* QueryRTTI();
    void Update(unsigned int);
    unsigned short MeshChildCount() const;
    unsigned short ChildCount() const;
    NiObject** MeshChildren() const;
    NiObject** Children() const;
    void ApplyToAllObjects(unsigned int);

    void* FUN_00621a40();
    void FUN_00b4dec0(int);
    void FUN_00a5d3d0();
    void FUN_00528ce0(NiObject*);
    void FUN_00a809b0(unsigned int);
    void FUN_00c21cb0(unsigned int);
    void FUN_00c62140();
    void FUN_00c61f30(NiStream&);
    void FUN_00c64950(NiStream*);
    void FUN_00c64aa0(NiStream&);

};
