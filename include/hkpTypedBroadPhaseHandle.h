#pragma once

struct hkFinishLoadedObjectFlagCD2C;
struct ClassMemberDescriptor;

class hkpTypedBroadPhaseHandle
{
public:
    __forceinline hkpTypedBroadPhaseHandle(int type)
    {
        *(unsigned int*)pad0 = 0;
        m_type = (signed char)type;
        m_uiCollisionFilterData = 0;
        m_ucObjectQualityType = -1;
        m_iOwnerOffset = 0x7f;
    }

    hkpTypedBroadPhaseHandle(hkFinishLoadedObjectFlagCD2C);

    void SetOwnerPointer(void* pvOwner);
    void* getOwner() const;
    void setType(int type);

    static const ClassMemberDescriptor Members[];
    enum { OFFSET_INVALID = 127 };

    char pad0[0x4];
    signed char m_type;
    signed char m_iOwnerOffset;
    signed char m_ucObjectQualityType;
    char pad7[0x1];
    unsigned int m_uiCollisionFilterData;
};
