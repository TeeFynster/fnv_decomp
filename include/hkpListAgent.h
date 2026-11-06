#pragma once

#include "hkpCollisionAgent.h"

class hkpCdBody;
class hkpCdBodyPairCollector;
struct CollisionAgentContext;

class hkpListAgent : public hkpCollisionAgent
{
public:
    virtual void vf03(const hkpCdBody&, const hkpCdBody&,
                      const CollisionAgentContext&, hkpCdBodyPairCollector&);
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09(void* arg);
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();

    char m0[0x10];
};
