#pragma once

#include "hkArray.h"
#include "hkBool.h"
#include "hkQsTransform.h"

class hkaSkeleton;

class hkaPose
{
public:
    enum
    {
        F_DIRTY_LOCAL = 0x1,
        F_DIRTY_MODEL = 0x2,
        F_INTERNAL1 = 0x4
    };

    hkaSkeleton* m_pSkeleton;
    hkArrayBase<hkQsTransform> m_pLocalPose;
    hkArrayBase<hkQsTransform> m_pModelPose;
    hkArrayBase<unsigned int> m_pBoneFlags;
    hkBool m_bPoseFlag;
    hkBool m_bPoseInitialized;

    const hkQsTransform& hkaPose_calculateBoneModelSpace(int boneIdx);
    const hkQsTransform& GetBoneModelSpace(int boneIdx);
    void syncLocalSpace();
    hkQsTransform& accessBoneModelSpace(int boneIdx, int propagate);

    void makeFirstChildrenModelSpace(int boneIdx);
    const hkQsTransform& calculateBoneLocalSpace(int boneIdx);
    void makeAllChildrenLocalSpace(int boneIdx);

    __forceinline int isFlagOn(int boneIdx, int flag) const
    {
        return m_pBoneFlags[boneIdx] & flag;
    }

    __forceinline void setFlag(int boneIdx, unsigned int flag)
    {
        m_pBoneFlags[boneIdx] |= flag;
    }

    __forceinline void clearFlag(int boneIdx, unsigned int flag)
    {
        m_pBoneFlags[boneIdx] &= ~flag;
    }
};
