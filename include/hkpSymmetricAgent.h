#pragma once

class hkpCdBody;
class hkpCdBodyPairCollector;
struct CollisionAgentContext;
struct GskAgentInput;
struct Output;

template <class Agent>
class hkpSymmetricAgent
{
public:
    virtual void Destroy();
    virtual void vf01();
    virtual void vf02();
    virtual void ProcessSwappedCollisionBodies(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                            const CollisionAgentContext& input,
                            hkpCdBodyPairCollector& collector);
    virtual void vf04();
    virtual void vf05();
    virtual void ProcessEntries_00d434e0(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                            const GskAgentInput& input, Output& output);
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();

    hkpSymmetricAgent(void* a, void* b, void* c, void* d);
};
