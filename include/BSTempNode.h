#pragma once

#include "NiNode.h"

class BSTempNode : public NiNode
{
public:
    BSTempNode(float value);
    void BSTempNodeManager_RemoveExpired(float value);
    void UpdateDownwardPass(NiUpdateData& data, unsigned int flags);
    void UpdateSelectedDownwardPass(NiUpdateData& data, unsigned int flags);
    void UpdateRigidDownwardPass(NiUpdateData& data, unsigned int flags);
    static void operator delete(void*, unsigned int);

    float UpdateTime(float value);
    NiAVObject* GetChild(unsigned int index);
    void SetTime(float value);
    bool Expired() const;

    union
    {
        float time;
        float fTime;
    };
};
