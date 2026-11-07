
// src/havok/physics/vehicle/wheelcollide/rejectchassislistener/hkprejectchassislistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/rejectchassislistener/hkprejectchassislistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpRejectChassisListener.h"

extern "C" void* DAT_010c925c;
extern "C" void* DAT_0102e388;
struct FUN_00e360f0
{
    void* m_pVTable;
    int m_unk0;
    void* m_pListener;
    ~FUN_00e360f0();
};
// @fnv 0x00e360f0
FUN_00e360f0::~FUN_00e360f0()
{
    m_pListener = &DAT_010c925c;
    m_pVTable = &DAT_0102e388;
}

struct FUN_00e36100_StandIn
{
    int m_unk0;
    void hkpRejectChassisListener_collidableAddedCallback(int* pArg);
};

// @fnv 0x00e36100
// src: HAVOK_LIB 0x00e36100
void FUN_00e36100_StandIn::hkpRejectChassisListener_collidableAddedCallback(int* pArg)
{
    if (*(int*)(pArg + 1) == *(int*)(this + 1) || *((unsigned char*)*(int*)(pArg + 1) + 0x18) != 1)
        *(int*)(pArg + 2) = 1;
}

// @fnv 0x00e360e0
// src: GUESS 0x00e360e0 (confidence: high)
void __stdcall Object_DoNothing_00e360e0(int arg)
{}

// FUN_00dfbd70: this-adjusting thunk {adjustor 8} for the virtual FunAdjust_Host::FUN_00dfbd70
// reached through its secondary copy (shim base). The final overrider's body lives in its own
// translation unit, so it is only declared here.

struct FunAdjust_Plat
{
    void* m_unk00;
    virtual void vf0_aux(int* pArg);
};

struct FunAdjust_Host
{
    void* m_unk00;
    virtual void FUN_00dfbd70(int* pArg);
};

struct FunAdjust_Shim : FunAdjust_Host
{
    void* m_unk04;
};

struct FunAdjust_Derived : FunAdjust_Plat, FunAdjust_Host, FunAdjust_Shim
{
    FunAdjust_Derived();
// @fnv 0x00dfbd70
    void FUN_00dfbd70(int* pArg);
    void* m_unk10;
};

FunAdjust_Derived::FunAdjust_Derived()
{}

class hkMemoryAllocatorXdfbd40
{
  public:
    virtual ~hkMemoryAllocatorXdfbd40() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterXdfbd40
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXdfbd40* m_pStreamAllocator;

    hkMemoryAllocatorXdfbd40& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterXdfbd40& __cdecl hkMemoryRouter_getInstance() throw();

class hkObjdfbd40 : public hkpRejectChassisListener
{
  public:
    hkObjdfbd40* FUN_00dfbd40(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter_getInstance().heap().ReleaseBlock(p, static_cast<hkObjdfbd40*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return m_usMemSizeAndFlags;
    }
    void FUN_00e360f0() throw();
};

// Calls FUN_00e360f0, then calls operator delete on this if bit 0 of uiFlags is set, and returns this.
// @fnv 0x00dfbd40
hkObjdfbd40* hkObjdfbd40::FUN_00dfbd40(unsigned int uiFlags) throw()
{
    this->FUN_00e360f0();
    if (uiFlags & 1)
        hkObjdfbd40::operator delete(this);
    return this;
}
