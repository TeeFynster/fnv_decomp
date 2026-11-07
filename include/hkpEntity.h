#pragma once

#include "hkpWorldObject.h"
#include "hkpMaterial.h"
#include "hkpEntitySmallArraySerializeOverrideType.h"
#include "hkpEntitySpuCollisionCallback.h"
#include "hkpMaxSizeMotion.h"

class hkBoolH;
class hkLocalFrame;
class hkpAction;
class hkpBreakableBody;
class hkpConstraintInstance;
class hkpEntityExtendedListeners;
class hkpEntityListener;
class hkpSimulationIsland;
class SpringVector;
struct ConstraintRuntimeInfo;
template <typename T> class ResizableArray;
template <typename T> class hkSmallArray;

class hkpEntity : public hkpWorldObject
{
public:
    enum SpuCollisionCallbackEventFilter
    {
        SPU_SEND_NONE = 0x00,
        SPU_SEND_CONTACT_POINT_ADDED = 0x01,
        SPU_SEND_CONTACT_POINT_PROCESS = 0x02,
        SPU_SEND_CONTACT_POINT_REMOVED = 0x04,
        SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS =
            SPU_SEND_CONTACT_POINT_ADDED | SPU_SEND_CONTACT_POINT_PROCESS
    };

    typedef hkpEntitySmallArraySerializeOverrideType SmallArraySerializeOverrideType;
    typedef hkpEntitySpuCollisionCallback SpuCollisionCallback;
    typedef hkpEntityExtendedListeners ExtendedListeners;

    class ActionArray
    {
    public:
        hkpAction** m_data;
        hkUint16 m_iElementCount;
        hkUint16 m_iCapacityState;

        int indexOf(hkpAction* action) const
        {
            for (int i = 0; i < (int)m_iElementCount; ++i)
            {
                if (m_data[i] == action)
                    return i;
            }
            return -1;
        }

        void removeAt(int index)
        {
            m_iElementCount--;
            m_data[index] = m_data[m_iElementCount];
        }
    };

    static const ClassMemberDescriptor Members[];

    hkpEntity(FinishingFlag flag);
    virtual ~hkpEntity() throw();
    virtual void vf05();

    int getNumConstraints() throw();
    int GetEntryAt(int i) throw();
    hkBoolH isFixed() const;
    hkUint32 GetUid() const;
    const ResizableArray<ConstraintRuntimeInfo>& getConstraintMastersImpl() const;
    hkpSimulationIsland* GetSimulationIsland() const;
    void __thiscall hkpRigidBody_getPointVelocity(const SpringVector* point, SpringVector* velocity);
    unsigned char* __thiscall isActive_00c9bff0(unsigned char* out);
    void __thiscall activate_00c9c1d0();
    void removeEntityListener_00c9c670(void* arg1);
    void ApplyForceAtPoint(float dt, const hkVector4& force, const SpringVector& point);
    void __thiscall AddContactListener(void* listener);
    void __thiscall RemoveContactListener(void* listener);
    void __thiscall AddEntityListener(void* listener);
    void __thiscall RemoveEntityListener(void* listener);
    // Havok 7.1 hkpEntity::addEntityListener (0x00c9c5b0) / removeEntityListener (0x00c9c670). The void*
    // declarations above predate them: AddEntityListener is bound to 0x00c9c670 (removeEntityListener),
    // RemoveEntityListener to 0x00c9c0f0 (removeEntityActivationListener), FUN_00c9c670 = removeEntityListener.
    void addEntityListener(hkpEntityListener* el);
    void removeEntityListener(hkpEntityListener* el);
    // Creates m_pExtendedListeners on first use; the body is in hkpEntityExtendedListeners.h (hkpEntity.inl).
    inline const hkSmallArray<hkpEntityListener*>& getEntityListeners() const;
    void RetainReference();
    void removeReference();
    void activate();
    void deactivate();

    hkpMaterial m_iMaterialIndex;
    void* m_pEntityUserData;
    hkReal m_fBulletSpread;
    hkpBreakableBody* m_pShape;
    hkUint32 m_uiFilterInfo;
    hkUint16 m_usStorageIndex;
    hkUint16 m_usNextProcessCallbackDelay;
    hkpEntitySmallArraySerializeOverrideType m_eSmallArraySerializeOverrideType;
    hkArray<hkpConstraintInstance*> m_kSlaveConstraints;
    hkArray<hkUint8> m_pByteBuffer;
    hkpSimulationIsland* m_pSimulationIsland;
    hkInt8 m_iAutoRemoveLevel;
    hkUint8 m_ucNumShapeKeysInContactPointProperties;
    hkUint8 m_ucResponseModifierFlags;
    char padD3[1];
    hkUint32 m_uiUniqueId;
    hkpEntitySpuCollisionCallback m_kSpuCollisionCallback;
    hkpMaxSizeMotion m_pMotionState;
    hkpEntitySmallArraySerializeOverrideType m_kContactListeners;
    ActionArray m_ppActions;
    hkLocalFrame* m_pLocalFrame;
    mutable hkpEntityExtendedListeners* m_pExtendedListeners;
    char pad218[8];
};
