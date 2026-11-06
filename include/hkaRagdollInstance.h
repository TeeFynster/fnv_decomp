#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

class hkaSkeleton;
class hkpConstraintInstance;
class hkpRigidBody;
struct hkQsTransform;

class hkaRagdollInstance : public hkReferencedObject
{
public:
    hkaRagdollInstance(const hkArray<hkpRigidBody*>& rigidBodies,
                      const hkArray<hkpConstraintInstance*>& constraints,
                      const hkaSkeleton* skeleton);
    hkaRagdollInstance(const hkArray<hkpRigidBody*>& rigidBodies,
                      const hkArray<hkpConstraintInstance*>& constraints,
                      const hkaSkeleton* skeleton,
                      const hkArray<hkInt32>& boneToRigidBodyMap) throw();
    virtual ~hkaRagdollInstance() throw();
    virtual hkaRagdollInstance* FUN_00ce2730(int cloneMode) const throw();

    void FUN_00ce1560(const hkQsTransform* pose);
    int FUN_00ce1680(void* world, unsigned char flag);
    void FUN_00ce1760(hkQsTransform* poseOut, const hkQsTransform& root,
                      const hkQsTransform* localPose);
    void FUN_00ce18d0(hkQsTransform* poseOut);
    void getWorldPose(hkQsTransform* poseOut);
    void FUN_00ce18f0(hkQsTransform* poseOut, const hkQsTransform& worldFromModel);
    void FUN_00ce1ad0(const hkQsTransform* pose, const hkQsTransform& worldFromModel);
    void FUN_00ce1ca0(const hkQsTransform* poseA, const hkQsTransform& worldFromModelA,
                      const hkQsTransform* poseB, const hkQsTransform& worldFromModelB,
                      float deltaTime);
    void FUN_00ce2000(int bone, hkQsTransform& out);
    void FUN_00ce2150(int bone, float time, hkQsTransform& out);
    void FUN_00ce2150(int bone, float time, void* out);
    void FUN_00ce22c0(const hkArray<hkpRigidBody*>& rigidBodies,
                      const hkArray<hkpConstraintInstance*>& constraints,
                      hkaSkeleton* skeleton);
    void ApplyValueToTransforms(float value, hkQsTransform* transforms);
    hkaRagdollInstance* FUN_00ce2470(const hkArray<hkpRigidBody*>& rigidBodies,
                                    const hkArray<hkpConstraintInstance*>& constraints,
                                    hkaSkeleton* skeleton);
    void FUN_00ce26f0(hkQsTransform* transforms);

    const hkaSkeleton* getSkeleton() const { return m_pSkeleton; }
    hkpRigidBody* getRigidBodyOfBone(int bone) const
    {
        int body = m_kBoneMap.m_data[bone];
        return body < 0 ? 0 : static_cast<hkpRigidBody*>(m_ppRigidBodies.m_data[body]);
    }

    hkArray<void*> m_ppRigidBodies;
    hkArray<hkpConstraintInstance*> m_ppConstraints;
    hkArray<hkInt32> m_kBoneMap;
    hkaSkeleton* m_pSkeleton;
};
