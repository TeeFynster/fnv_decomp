
// src/fallout_shared/havok/cameracaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/cameracaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BSAudio.h"
#include "../../../include/bhkCharacterListener.h"
#include "../../../include/hkpAllCdPointCollector.h"

extern int DAT_0104da3c;

struct FUN_00621100_shell
{
    void SetVtable();
};

// @fnv 0x00621100
void __thiscall FUN_00621100_shell::SetVtable()
{
    *(int*)this = (int)&DAT_0104da3c;
}

// @fnv 0x00621270
unsigned int bhkCharacterListener::GetFlags(unsigned int aiFlags)
{
    return *(unsigned int*)unk04 & aiFlags;
}

extern float DAT_0104da4c;

struct FUN_00621290_shell
{
    void* InitFloats();
    void _ref_006815c0();
};

// Calls _ref_006815c0, then stores DAT_0104da4c into the floats at offsets 0x10 and 0x14 and returns this.
// @fnv 0x00621290
void* FUN_00621290_shell::InitFloats()
{
    _ref_006815c0();
    *(float*)((char*)this + 0x10) = DAT_0104da4c;
    *(float*)((char*)this + 0x14) = DAT_0104da4c;
    return this;
}

extern int DAT_0104da3c;
struct FUN_00621060_shell
{
    int* vtbl;
    void __thiscall SetValue();
    FUN_00621060_shell* __thiscall hkpCdPointCollector_hkpCdPointCollector();
};
// @fnv 0x00621060
// src: XBOX_PDB 0x00621060
FUN_00621060_shell* __thiscall FUN_00621060_shell::hkpCdPointCollector_hkpCdPointCollector()
{
    vtbl = &DAT_0104da3c;
    SetValue();
    return this;
}

struct TopicObj
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void Func(void* a, int b)
    {}
};
BSAudio* __cdecl _FUN_00c85750();
// If a1 is non-null, gets the object from _FUN_00c85750 and calls its Func with a1 and 8.
// @fnv 0x006210d0
// src: GUESS 0x006210d0 (confidence: low)
void Cameracaster_UpdateState_006210d0(void* a1)
{
    if (a1 != 0)
    {
        TopicObj* t = (TopicObj*)_FUN_00c85750()->GetAudioBackendData();
        t->Func(a1, 8);
    }
}

namespace fnv_00621170 {
BSAudio* __cdecl _FUN_00c85750();
struct Caller
{
    virtual void f0();
    virtual void f1();
    virtual void Foo(void*, int);
};
// @fnv 0x00621170
// src: GUESS 0x00621170 (confidence: low)
void Cameracaster_UpdateState_00621170(void* apArg)
{
    if (apArg != 0)
    {
        void* b = _FUN_00c85750()->GetAudioBackendData();
        ((Caller*)b)->Foo(apArg, 0x3a0);
    }
}
}  // namespace fnv_00621170

#include "../../../include/RootContactPoint.h"
typedef char _sizecheck_RootContactPoint[sizeof(RootContactPoint) == 112 ? 1 : -1];

struct FUN_006281a0_shell
{
    void AssignFields_006281a0(void*);
};

// @fnv 0x006212c0
// src: GUESS 0x006212c0 (confidence: low)
RootContactPoint* RootContactPoint::InitializeFields_006212c0(void* apSource)
{
    ((FUN_006281a0_shell*)this)->AssignFields_006281a0(apSource);
    m_pRootCollidableA = ((RootContactPoint*)apSource)->m_pRootCollidableA;
    m_uiShapeKeyA = ((RootContactPoint*)apSource)->m_uiShapeKeyA;
    for (unsigned int uiIndex = 0; uiIndex < 8; ++uiIndex)
        m_auiUnk28[uiIndex] = ((RootContactPoint*)apSource)->m_auiUnk28[uiIndex];
    m_pRootCollidableB = ((RootContactPoint*)apSource)->m_pRootCollidableB;
    m_uiShapeKeyB = ((RootContactPoint*)apSource)->m_uiShapeKeyB;
    for (unsigned int S2 = 0; S2 < 8; ++S2)
        m_auiUnk50[S2] = ((RootContactPoint*)apSource)->m_auiUnk50[S2];
    return this;
}

extern float DAT_0104da48;
// @fnv 0x00621080
void __thiscall FUN_00621060_shell::SetValue()
{
    *(float*)((char*)this + 4) = DAT_0104da48;
}

void __fastcall hkArrayBase_hkpRootCdBodyPair_clear(void*);

struct FUN_00621120_shell : public FUN_00621060_shell
{
    void __thiscall hkpAllCdPointCollector_reset();
};

// @fnv 0x00621120
// src: XBOX_PDB 0x00621120
void __thiscall FUN_00621120_shell::hkpAllCdPointCollector_reset()
{
    hkArrayBase_hkpRootCdBodyPair_clear(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10));
    SetValue();
}

struct Cnt621210
{
    int _ref_00726070();
};
struct Rcv621210
{
    void UpdateState_00622570(bool);
};
struct Hld621210
{
    char _pad[16];
    Cnt621210 _c;
    Rcv621210* hkpAllCdPointCollector_hasHit(Rcv621210* p);
};
// Calls FUN_00622570 on p with whether _c._ref_00726070() is greater than zero, then returns p.
// @fnv 0x00621210
// src: COMMUNITY 0x00621210
Rcv621210* Hld621210::hkpAllCdPointCollector_hasHit(Rcv621210* apReceiver)
{
    apReceiver->UpdateState_00622570(_c._ref_00726070() > 0);
    return apReceiver;
}

struct DummyFlagsShell
{
    char _pad[0x410];
    bhkCharacterListener _flags;
    bool bhkCharacterController_QChaseBip();
};

// @fnv 0x00621240
// src: XBOX_PDB 0x00621240
bool DummyFlagsShell::bhkCharacterController_QChaseBip()
{
    return _flags.GetFlags(0x800) != 0;
}

struct FUN_006210a0_shell : FUN_00621100_shell
{
    void* __thiscall FUN_006210a0(unsigned int flags);
};

// @fnv 0x006210a0
void* __thiscall FUN_006210a0_shell::FUN_006210a0(unsigned int flags)
{
    SetVtable();
    if (flags & 1)
        Cameracaster_UpdateState_006210d0(this);
    return this;
}

void __cdecl Cameracaster_UpdateState_00621170(void*);
void FUN_006211b0(void*);
// @fnv 0x00621140
void* hkpAllCdPointCollector::FUN_00621140(unsigned int aiFlags)
{
    FUN_006211b0();
    if (aiFlags & 1)
        Cameracaster_UpdateState_00621170(this);
    return this;
}

struct Base_620ff0
{
    virtual void v00();

    int unk04;
    int unk08;
    int unk0C;

    Base_620ff0();
    ~Base_620ff0();
};

struct Sub_620ff0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    Sub_620ff0(int aValue);
    ~Sub_620ff0();
};

struct FUN_00620ff0 : Base_620ff0
{
    Sub_620ff0 m_10;

    FUN_00620ff0();
    virtual void v00();
    void hkpAllCdPointCollector_reset();
};

// @fnv 0x00620ff0
FUN_00620ff0::FUN_00620ff0() : m_10(0)
{
    hkpAllCdPointCollector_reset();
}

extern int DAT_0104da28;

class CdPointSubObj
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~CdPointSubObj();
};

class CdPointCollectorBase
{
  public:
    virtual void Update();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~CdPointCollectorBase();
};

class FUN_006211b0_cls : public CdPointCollectorBase
{
  public:
    CdPointSubObj m_sub10;
    ~FUN_006211b0_cls();
};

// Destructor for a CdPointCollectorBase-derived collector that owns a CdPointSubObj member; the body is empty.
// @fnv 0x006211b0
FUN_006211b0_cls::~FUN_006211b0_cls()
{}
