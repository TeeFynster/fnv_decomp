
// src/havok/physics/dynamics/constraint/motor/springdamper/hkpspringdamperconstraintmotor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/motor/springdamper/hkpspringdamperconstraintmotor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpSpringDamperConstraintMotor.h"

class S00d862a0_Heap
{
  public:
    virtual ~S00d862a0_Heap() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct S00d862a0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S00d862a0_Heap* m_pStreamAllocator;

    S00d862a0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace S00d862a0_Rt {
extern "C" S00d862a0_Router& __cdecl hkMemoryRouter_getInstance() throw();
}

class S00d862a0_Base
{
  public:
    virtual ~S00d862a0_Base() throw();
};

class S00d862a0_Ref : public S00d862a0_Base
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    S00d862a0_Ref() throw()
    {
        m_sReferenceCount = 1;
    }
    S00d862a0_Ref(const S00d862a0_Ref&) throw()
    {
        m_sReferenceCount = 1;
    }

    static void* operator new(unsigned int nbytes)
    {
        S00d862a0_Ref* b = static_cast<S00d862a0_Ref*>(S00d862a0_Rt::hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
};

class S00d862a0_Motor : public S00d862a0_Ref
{
  public:
    char m_type;
    char unk09;
    char unk0A;
    char unk0B;

    S00d862a0_Motor(const S00d862a0_Motor& o) throw() : S00d862a0_Ref(o), m_type(o.m_type)
    {}
};

class S00d862a0_Limited : public S00d862a0_Motor
{
  public:
    float m_fMinForce;
    float m_fMaxForce;

    S00d862a0_Limited(const S00d862a0_Limited& o) throw()
        : S00d862a0_Motor(o), m_fMinForce(o.m_fMinForce), m_fMaxForce(o.m_fMaxForce)
    {}
};

class S00d862a0_Spring : public S00d862a0_Limited
{
  public:
    float m_fSpringConstant;
    float m_fSpringDamping;

    S00d862a0_Spring(const S00d862a0_Spring& o) throw()
        : S00d862a0_Limited(o), m_fSpringConstant(o.m_fSpringConstant), m_fSpringDamping(o.m_fSpringDamping)
    {}

    S00d862a0_Spring* hkpSpringDamperConstraintMotor_clone() const;
};

// Allocates a new S00d862a0_Spring via the Havok heap and initializes it as a copy of the current object.
// @fnv 0x00d862a0
// src: HAVOK_LIB 0x00d862a0
S00d862a0_Spring* S00d862a0_Spring::hkpSpringDamperConstraintMotor_clone() const
{
    return new S00d862a0_Spring(*this);
}
