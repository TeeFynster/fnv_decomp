// fallout_shared/facegen/bsfacegenninode.h: declares BSFaceGenAnimationData, BSFaceGenNiNode
#ifndef FNV_BSFACEGENNINODE_H
#define FNV_BSFACEGENNINODE_H


#include "layout_support.h"

class NiRTTI;

class BSFaceGenAnimationData
{
  public:
    void IncRefCount();
    void DecRefCount();
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;

    ~NiPointer()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    NiPointer<T>& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (object)
                object->IncRefCount();
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = object;
        }
        return *this;
    }
    operator T*() const;
};

#pragma pack(push, 4)

class BSFaceGenNiNode
{
  public:
    virtual ~BSFaceGenNiNode();
    virtual const NiRTTI* GetRTTI() const;

    virtual BSFaceGenAnimationData* GetAnimationData();
    virtual void SetAnimationData(BSFaceGenAnimationData* apData);
    virtual void Unk_108();
    virtual void Unk_10C();
    virtual void Unk_110();
    virtual void SetAnimationUpdate(bool abUpdate);
    virtual void Unk_118();
    virtual void SetApplyRotToParent(bool abApply);

    char pad04[0xA8];
    NiPointer<BSFaceGenAnimationData> spAnimationData;  // 0xAC
    char padB0[0x26];
    bool bAnimationUpdate;  // 0xD6
    char padD7[1];
    bool bApplyRotationToParent;  // 0xD8
    char padD9[0x17];

    static const NiRTTI ms_kRTTI;
};

#pragma pack(pop)

// @fnv 0x006629e0
const NiRTTI* BSFaceGenNiNode::GetRTTI() const
{
    return &ms_kRTTI;
}

// @fnv 0x006629f0
BSFaceGenAnimationData* BSFaceGenNiNode::GetAnimationData()
{
    return spAnimationData;
}

// @fnv 0x00439920
void BSFaceGenNiNode::SetAnimationData(BSFaceGenAnimationData* apData)
{
    spAnimationData = apData;
}

// @fnv 0x00662a60
void BSFaceGenNiNode::SetAnimationUpdate(bool abUpdate)
{
    bAnimationUpdate = abUpdate;
}

// @fnv 0x0097ce70
void BSFaceGenNiNode::SetApplyRotToParent(bool abApply)
{
    bApplyRotationToParent = abApply;
}

#endif
