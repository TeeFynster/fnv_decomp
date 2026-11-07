#pragma once

#include "hkpDynamicsContactMgr.h"
#include "hkpConstraintData.h"
#include "hkpConstraintInstance.h"
#include "hkpSimpleContactConstraintAtom.h"
#include "hkArray.h"

class hkpWorld;
class hkpRigidBody;
class hkpCdBody;
struct GskAgentInput;
class WorldOperationEntry;
class ConvexFeaturePairCache;
class hkContactPoint;
class hkpContactPointPropertiesCFD;
struct hkRigidBodyStub;
struct hkCdBodyStub;
struct hkProcessCollisionInputStub;
struct hkProcessCollisionOutputStub;
struct hkGskCacheStub;
struct hkCPProperties;
struct hkContactPt;

#include "hkpSimpleContactConstraintData.h"

class hkpSimpleConstraintContactMgr : public hkpDynamicsContactMgr
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void calcContentStatistics_00cfd5e0(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const throw();
    virtual hkUint16 addContactPointImpl(const hkCdBodyStub& a, const hkCdBodyStub& b,
                               const hkProcessCollisionInputStub& input,
                               hkProcessCollisionOutputStub& output,
                               const hkGskCacheStub* contactCache, hkContactPt& cp);
    virtual void vf10();
    virtual void removeContactPointImpl(hkUint16 id, hkpConstraintOwner* owner);
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();

    void vf08();
    void vf0C();
    void vf0c();

    __forceinline void removeContactPoint(unsigned int id, void* constraintOwner)
    {
        removeContactPointImpl(static_cast<hkUint16>(id), static_cast<hkpConstraintOwner*>(constraintOwner));
    }

    unsigned int processContactPoint(const hkpCdBody& a, const hkpCdBody& b,
                                    const GskAgentInput& input, WorldOperationEntry& output,
                                    const ConvexFeaturePairCache* contactCache, hkContactPoint& cp);
    hkRigidBodyStub* setContactPointProperties(const hkCdBodyStub& a, const hkCdBodyStub& b,
                                int maxImpulse, hkCPProperties* cpi);
    void removeContactPointImpl_00cfd320(hkUint16 cpId, hkpConstraintOwner& kOwner) throw();

    int unk04;
    union
    {
        char pad8[0x78];
        struct
        {
            int unk08;
            hkpWorld* m_pOwningWorld;
            unsigned short m_uiContactPointCount;
            unsigned short m_usNextProcessCallbackDelay;
            hkpSimpleContactConstraintData m_kSimpleContactConstraintData;
            hkpConstraintInstance m_pHavokConstraint;
            unsigned char unk7C[4];
        };
        struct
        {
            unsigned int : 32;
            unsigned int : 32;
            hkpRigidBody* m_pEntityA;
            hkpRigidBody* m_pEntityB;
            unsigned short m_nextProcessCollideDelay;
            unsigned char unk1A[0x66];
        };
    };
};
