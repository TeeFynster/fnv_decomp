
// src/havok/physics/dynamics/phantom/hkpphantombroadphaselistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpphantombroadphaselistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CF6DE0Collidable;

struct CF6DE0Phantom
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void AddOverlappingCollidable(CF6DE0Collidable* collidable);
};

struct CF6DE0Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;

    void* getOwner() const
    {
        return (char*)this + m_iOwnerOffset;
    }
};

struct CF6DE0TypedBroadPhaseHandle
{
    int unk00;
    char m_type;
    signed char m_iOwnerOffset;

    void* getOwner() const
    {
        return (char*)this + m_iOwnerOffset;
    }
};

struct CF6DE0HandlePair
{
    CF6DE0TypedBroadPhaseHandle* m_kPointA;
    CF6DE0TypedBroadPhaseHandle* m_kPointB;
};

struct CF6DE0PhantomBroadPhaseListener
{
    void UpdateFields_00cf6de0(CF6DE0HandlePair& pair);
};

// @fnv 0x00cf6de0
// src: GUESS 0x00cf6de0 (confidence: low)
void CF6DE0PhantomBroadPhaseListener::UpdateFields_00cf6de0(CF6DE0HandlePair& pair)
{
    if (pair.m_kPointA->m_type == 2)
    {
        CF6DE0Collidable* collA = (CF6DE0Collidable*)pair.m_kPointA->getOwner();
        CF6DE0Collidable* collB = (CF6DE0Collidable*)pair.m_kPointB->getOwner();
        ((CF6DE0Phantom*)collA->getOwner())->AddOverlappingCollidable(collB);
    }
    if (pair.m_kPointB->m_type == 2)
    {
        CF6DE0Collidable* collA = (CF6DE0Collidable*)pair.m_kPointA->getOwner();
        CF6DE0Phantom* phantom = (CF6DE0Phantom*)((CF6DE0Collidable*)pair.m_kPointB->getOwner())->getOwner();
        phantom->AddOverlappingCollidable(collA);
    }
}

struct RefRec
{
    int unk00;
    unsigned char tag;
    signed char off;
};

struct RefPair
{
    RefRec* pFirst;
    RefRec* pSecond;
};

struct DispatchTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24(void* apArg);
};

// For each pair member whose tag is 2, resolves a relative target and calls its v24 with the other member's offset-adjusted pointer.
// @fnv 0x00cf6e40
void __stdcall DispatchPairTargets(RefPair* apPair)
{
    if (apPair->pFirst->tag == 2)
    {
        RefRec* pA = apPair->pFirst;
        char* pBase = (char*)pA + pA->off;
        int iRelOffset = *(signed char*)(pBase + 0x10);
        RefRec* pB = apPair->pSecond;
        void* arg = (char*)pB + pB->off;
        DispatchTarget* pTarget = (DispatchTarget*)(pBase + iRelOffset);
        pTarget->v24(arg);
    }
    if (apPair->pSecond->tag == 2)
    {
        RefRec* pB = apPair->pSecond;
        char* pBase = (char*)pB + pB->off;
        int iRelOffset = *(signed char*)(pBase + 0x10);
        RefRec* pA = apPair->pFirst;
        void* arg = (char*)pA + pA->off;
        DispatchTarget* pTarget = (DispatchTarget*)(pBase + iRelOffset);
        apPair = (RefPair*)arg;
        pTarget->v24(apPair);
    }
}
