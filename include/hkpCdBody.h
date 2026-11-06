#pragma once

#include <cstddef>

class hkpShape;
class hkpShapeV;
class hkMotionState;
class hkTransform;
class hkpCollidable;
struct hkFinishLoadedObjectFlagCD2C;

class hkpCdBody
{
public:
    const hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody* m_parent;

    hkpCdBody();
    hkpCdBody(const void* shape, const void* motionState)
    {
        m_pCollisionShape = static_cast<const hkpShape*>(shape);
        m_pMotionState = motionState;
        m_parent = 0;
        m_uiCollisionShapeKey = 0xffffffff;
    }
    explicit hkpCdBody(const hkpCdBody* parent);
    hkpCdBody(const hkpCdBody* parent, const void* motion);
    hkpCdBody(const hkpCdBody* parent, const hkTransform* t);
    hkpCdBody(hkFinishLoadedObjectFlagCD2C flag);

    const hkTransform& getTransform() const;
    const hkpShape* getShape() const;
    unsigned int getShapeKey() const;
    const hkMotionState* GetMotionState() const;
    const hkpCollidable* getRootCollidable() const;
    const hkpCdBody* getParent() const;
    void SetCollisionShapeAndKey(const hkpShape* shape, unsigned int key);
    void SetCollisionShapeAndKey(const hkpShapeV* shape, unsigned int key);

    static void* __cdecl operator new(std::size_t nbytes);
};
