// fallout_shared/sky/skyobject.cpp: SkyObject, StandIn (4 functions)

#include "../../../include/SkyObject.h"
#include "../../../include/NiSortAdjustNode.h"

// @fnv 0x0063f830
SkyObject::SkyObject() : m_pRootNode(static_cast<NiNode*>(0))
{
    m_pRootNode = 0;
}

void _Deallocate(void*);
struct StandIn
{
    void FUN_0063f8d0();
    void* FUN_0063f8a0(unsigned int);
};
// Calls FUN_0063f8d0, then frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0063f8a0
void* StandIn::FUN_0063f8a0(unsigned int flags)
{
    FUN_0063f8d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Mem_63f8d0
{
    void Reset(int);
    ~Mem_63f8d0();
};
struct FUN_0063f8d0
{
    virtual void v0();
    Mem_63f8d0 m_mem;
    ~FUN_0063f8d0();
};
// Destructor that resets the contained Mem_63f8d0 by calling Reset(0).
// @fnv 0x0063f8d0
FUN_0063f8d0::~FUN_0063f8d0()
{
    m_mem.Reset(0);
}

class F940NodePtr
{
  public:
    void Reset(void* pvObject);
    NiSortAdjustNode* operator->();
    operator NiSortAdjustNode*();

    NiSortAdjustNode* m_pObject;
};

class F940Parent
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void AttachChildInAvailableSlot(NiSortAdjustNode* pkChild, bool abFirstAvailableSlot);
};

class F940Owner
{
  public:
    void CreateSortAdjustNode(F940Parent* pkParent);

    int unk00;
    F940NodePtr m_spNode;
};

// @fnv 0x0063f940
void F940Owner::CreateSortAdjustNode(F940Parent* pkParent)
{
    m_spNode.Reset(new NiSortAdjustNode(0u));
    m_spNode->SetSelectiveUpdate(true);
    m_spNode->SetSelectiveUpdateTransforms(true);
    pkParent->AttachChildInAvailableSlot(m_spNode, true);
}
