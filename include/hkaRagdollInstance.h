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
    virtual hkaRagdollInstance* hkaRagdollInstance_clone(int cloneMode) const throw();

    void ApplyPoseAndClearVelocities(const hkQsTransform* pose);
    int addToWorld(void* world, unsigned char flag);
    void hkaRagdollInstance_getPoseWorldSpace(hkQsTransform* poseOut, const hkQsTransform& root,
                      const hkQsTransform* localPose);
    void hkaRagdollInstance_getPoseWorldSpace_00ce18d0(hkQsTransform* poseOut);
    void getWorldPose(hkQsTransform* poseOut);
    void hkaRagdollInstance_getPoseModelSpace(hkQsTransform* poseOut, const hkQsTransform& worldFromModel);
    void hkaRagdollInstance_setPoseWorldSpace(const hkQsTransform* pose, const hkQsTransform& worldFromModel);
    void ProcessEntries_00ce1ca0(const hkQsTransform* poseA, const hkQsTransform& worldFromModelA,
                      const hkQsTransform* poseB, const hkQsTransform& worldFromModelB,
                      float deltaTime);
    void ProcessAndReturnValue_00ce2000(int bone, hkQsTransform& out);
    void hkaRagdollInstance_getApproxWorldFromBoneTransformAt(int bone, float time, hkQsTransform& out);
    void hkaRagdollInstance_getApproxWorldFromBoneTransformAt(int bone, float time, void* out);
    void hkaRagdollInstance_commonInit(const hkArray<hkpRigidBody*>& rigidBodies,
                      const hkArray<hkpConstraintInstance*>& constraints,
                      hkaSkeleton* skeleton);
    void ApplyValueToTransforms(float value, hkQsTransform* transforms);
    hkaRagdollInstance* hkaRagdollInstance_hkaRagdollInstance(const hkArray<hkpRigidBody*>& rigidBodies,
                                    const hkArray<hkpConstraintInstance*>& constraints,
                                    hkaSkeleton* skeleton);
    void hkaRagdollInstance_getApproxCurrentPoseWorldSpace(hkQsTransform* transforms);

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
