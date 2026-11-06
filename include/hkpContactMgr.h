#pragma once

#include <cstddef>
#include "hkReferencedObject.h"

class hkpCdBody;
class hkpCollidable;
class hkpConstraintOwner;
struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
class hkContactPoint;
struct GskAgentInput;
class WorldOperationEntry;
class ConvexFeaturePairCache;
class HeapContactFeatureCache;
class PhysicsMaterial;
class ContactDataPhysicsMaterial;
class CollisionContactResults;
enum hkResult;

typedef unsigned short hkContactPointId;
typedef float hkReal;
typedef hkReal hkTime;

class hkpContactMgr : public hkReferencedObject
{
public:
    enum Type
    {
        TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR,
        TYPE_REPORT_CONTACT_MGR,
        TYPE_CONVEX_LIST_CONTACT_MGR,
        TYPE_NULL_CONTACT_MGR,
        TYPE_USER_CONTACT_MGR,
        TYPE_MAX
    };

    enum ToiAccept
    {
        TOI_ACCEPT = 0,
        TOI_REJECT = 1
    };

    Type m_type;

    static void* __cdecl operator new(std::size_t uNbytes);

    __forceinline hkContactPointId addContactPoint(const hkpCdBody& kFirst, const hkpCdBody& kSecond,
                                                  const GskAgentInput& kInput, WorldOperationEntry& kOutput,
                                                  const ConvexFeaturePairCache* pContactCache, hkContactPoint& kCp);
    __forceinline void removeContactPoint(hkContactPointId kId, hkpConstraintOwner& kConstraintOwner);

    virtual hkContactPointId CreateContactPoint(const hkpCdBody& kFirst, const hkpCdBody& kSecond,
                                                const GskAgentInput& kInput, WorldOperationEntry& kOutput,
                                                const ConvexFeaturePairCache* pContactCache, hkContactPoint& kCp) = 0;
    virtual hkResult ReserveContactPoints(int iNumPoints) = 0;
    virtual void removeContactPointImpl(hkContactPointId kId, hkpConstraintOwner& kConstraintOwner) = 0;
    virtual void processContact(const hkpCdBody& kFirst, const hkpCdBody& kSecond,
                                const hkpProcessCollisionInput& kInput, hkpProcessCollisionOutput& kOutput);

    ToiAccept addToi(const hkpCdBody& kFirst, const hkpCdBody& kSecond,
                    const GskAgentInput& kInput, WorldOperationEntry& kOutput,
                    hkTime kToi, hkContactPoint& kCp,
                    const ConvexFeaturePairCache* pGskCache,
                    hkReal& kProjectedVelocity, PhysicsMaterial& kPropertiesOut);
    int addToi(const hkpCdBody& kFirst, const hkpCdBody& kSecond,
               const GskAgentInput& kInput, WorldOperationEntry& kOutput,
               hkTime kToi, hkContactPoint& kCp,
               const HeapContactFeatureCache* pGskCache,
               hkReal& kProjectedVelocity, ContactDataPhysicsMaterial& kPropertiesOut);
    void removeToi(hkpConstraintOwner& kConstraintOwner, PhysicsMaterial& kProperties);
    void removeToi(hkpConstraintOwner& kConstraintOwner, ContactDataPhysicsMaterial& kProperties);
    void processContact(const hkpCollidable& kFirst, const hkpCollidable& kSecond,
                        const GskAgentInput& kInput, CollisionContactResults& kCollisionData);
};
