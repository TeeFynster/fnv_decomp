// fallout/ai/combat/combatgoal.cpp: CombatGoal (22 functions)

#include "../../../../include/CombatGoal.h"
#include "../../../../include/CombatGoalActivateCombatItem.h"
#include "../../../../include/CombatGoalAdvance.h"
#include "../../../../include/CombatGoalAmbush.h"
#include "../../../../include/CombatGoalAvoidThreats.h"
#include "../../../../include/CombatGoalCluster.h"
#include "../../../../include/CombatGoalFallBack.h"
#include "../../../../include/CombatGoalFindTarget.h"
#include "../../../../include/CombatGoalFlank.h"
#include "../../../../include/CombatGoalFlee.h"
#include "../../../../include/CombatGoalFlushTarget.h"
#include "../../../../include/CombatGoalGuard.h"
#include "../../../../include/CombatGoalHideFromTarget.h"
#include "../../../../include/CombatGoalKillTarget.h"
#include "../../../../include/CombatGoalReachDestination.h"
#include "../../../../include/CombatGoalStayInCombatArea.h"
#include "../../../../include/CombatGoalUseCombatItem.h"
#include "../../../../include/CombatWorldStateListNode.h"

int Warning(const char* format, ...);

// Creates and returns a new CombatGoal subclass instance matching eType, or warns and returns 0 for an unknown type.
// @fnv 0x00984490
CombatGoal* CombatGoal::CreateGoal(CombatGoal::COMBAT_GOAL eType)
{
    switch (eType)
    {
    case COMBAT_GOAL_KILL_TARGET:
        return new CombatGoalKillTarget(eType);
    case COMBAT_GOAL_FIND_TARGET:
        return new CombatGoalFindTarget(eType);
    case COMBAT_GOAL_AVOID_THREATS:
        return new CombatGoalAvoidThreats(eType);
    case COMBAT_GOAL_FLEE:
        return new CombatGoalFlee(eType);
    case COMBAT_GOAL_ACTIVATE_COMBAT_ITEM:
        return new CombatGoalActivateCombatItem(eType);
    case COMBAT_GOAL_USE_COMBAT_ITEM:
        return new CombatGoalUseCombatItem(eType);
    case COMBAT_GOAL_FLANK:
        return new CombatGoalFlank(eType);
    case COMBAT_GOAL_FALLBACK:
        return new CombatGoalFallBack(eType);
    case COMBAT_GOAL_AMBUSH:
        return new CombatGoalAmbush(eType);
    case COMBAT_GOAL_REACH_DESTINATION:
        return new CombatGoalReachDestination(eType);
    case COMBAT_GOAL_ADVANCE:
        return new CombatGoalAdvance(eType);
    case COMBAT_GOAL_GUARD:
        return new CombatGoalGuard(eType);
    case COMBAT_GOAL_CLUSTER:
        return new CombatGoalCluster(eType);
    case COMBAT_GOAL_HIDE_FROM_TARGET:
        return new CombatGoalHideFromTarget(eType);
    case COMBAT_GOAL_FLUSH_TARGET:
        return new CombatGoalFlushTarget(eType);
    case COMBAT_GOAL_STAY_IN_COMBAT_AREA:
        return new CombatGoalStayInCombatArea(eType);
    default:
        Warning("COMBAT: Could not create combat goal of type %i", eType);
        return 0;
    }
}

extern int DAT_0108d47c;
struct FUN_00984ba0
{
    FUN_00984ba0(int);
    ~FUN_00984ba0();
    virtual void vfn_0();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
};
struct FUN_00984b20 : public FUN_00984ba0
{
    FUN_00984b20(int a);
};
// Constructs the base with a, then calls FUN_0097ade0(3, 0) and FUN_00984390(0, 1).
// @fnv 0x00984b20
FUN_00984b20::FUN_00984b20(int aiValue) : FUN_00984ba0(aiValue)
{
    FUN_0097ade0(3, 0);
    FUN_00984390(0, 1);
}

struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
};
struct FUN_00984e60 : CGBase
{
    FUN_00984e60(int t);
};
// @fnv 0x00984e60
FUN_00984e60::FUN_00984e60(int aiValue) : CGBase(aiValue)
{
    FUN_0097ade0(0x16, 0xffff0017);
    FUN_00984390(0x10, 0xffff0017);
}

namespace fnv_00984ee0 {
struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
    void SetProcedureType(int);
};
struct FUN_00984ee0 : CGBase
{
    FUN_00984ee0(int t);
};
// @fnv 0x00984ee0
FUN_00984ee0::FUN_00984ee0(int t) : CGBase(t)
{
    FUN_0097ade0(0x13, 1);
    FUN_00984390(1, 4);
    SetProcedureType(1);
}
}  // namespace fnv_00984ee0

namespace fnv_00984f80 {
struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
    void SetProcedureType(int);
};
struct FUN_00984f80 : CGBase
{
    FUN_00984f80(int t);
};
// @fnv 0x00984f80
FUN_00984f80::FUN_00984f80(int t) : CGBase(t)
{
    FUN_0097ade0(0x13, 2);
    FUN_00984390(1, 5);
    SetProcedureType(2);
}
}  // namespace fnv_00984f80

namespace fnv_00985080 {
extern int DAT_0108d47c;
struct FUN_00984ba0
{
    FUN_00984ba0(int);
    ~FUN_00984ba0();
    virtual void vfn_0();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
};
struct FUN_00985080 : public FUN_00984ba0
{
    FUN_00985080(int a);
};
// Constructs the base with a, then calls FUN_0097ade0(2, 7) and FUN_00984390(1, 7).
// @fnv 0x00985080
FUN_00985080::FUN_00985080(int aiValue) : FUN_00984ba0(aiValue)
{
    FUN_0097ade0(2, 7);
    FUN_00984390(1, 7);
}
}  // namespace fnv_00985080

namespace fnv_00985180 {
extern int DAT_0108d47c;
struct FUN_00984ba0
{
    FUN_00984ba0(int);
    ~FUN_00984ba0();
    virtual void vfn_0();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
};
struct FUN_00985180 : public FUN_00984ba0
{
    FUN_00985180(int a);
};
// Constructs the object via FUN_00984ba0(a), then calls FUN_0097ade0(2, 8) and FUN_00984390(1, 8).
// @fnv 0x00985180
FUN_00985180::FUN_00985180(int a) : FUN_00984ba0(a)
{
    FUN_0097ade0(2, 8);
    FUN_00984390(1, 8);
}
}  // namespace fnv_00985180

namespace fnv_00985200 {
struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
};
struct FUN_00985200 : CGBase
{
    FUN_00985200(int t);
};
// Constructs the base with t, then calls FUN_0097ade0(2, 9) and FUN_00984390(1, 9).
// @fnv 0x00985200
FUN_00985200::FUN_00985200(int aiValue) : CGBase(aiValue)
{
    FUN_0097ade0(2, 9);
    FUN_00984390(1, 9);
}
}  // namespace fnv_00985200

namespace fnv_00985280 {
struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
};
struct FUN_00985280 : CGBase
{
    FUN_00985280(int t);
};
// Constructs the object via CGBase(t), then calls FUN_0097ade0(3, 0) and FUN_00984390(0x11, 0x3c).
// @fnv 0x00985280
FUN_00985280::FUN_00985280(int aiValue) : CGBase(aiValue)
{
    FUN_0097ade0(3, 0);
    FUN_00984390(0x11, 0x3c);
}
}  // namespace fnv_00985280

namespace fnv_00985390 {
struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
};
struct FUN_00985390 : CGBase
{
    FUN_00985390(int t);
};
// Constructs the object via CGBase(t), then calls FUN_0097ade0(2, 0x10) and FUN_00984390(1, 0x10).
// @fnv 0x00985390
FUN_00985390::FUN_00985390(int t) : CGBase(t)
{
    FUN_0097ade0(2, 0x10);
    FUN_00984390(1, 0x10);
}
}  // namespace fnv_00985390

namespace ol4_00985000 {
struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
    void SetProcedureType(int);
};
struct FUN_00985000 : CGBase
{
    FUN_00985000(int t);
};
// @fnv 0x00985000
FUN_00985000::FUN_00985000(int t) : CGBase(t)
{
    FUN_0097ade0(0x13, 3);
    FUN_00984390(0x11, 0xf);
    SetProcedureType(3);
}
}

namespace fnv_00985300 {
class CGBase
{
  public:
    CGBase(int);
    ~CGBase();
    virtual void v0();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
};
class FUN_00985300 : public CGBase
{
  public:
    FUN_00985300(int aeType);
};
// Constructs the object with CGBase(aeType), then calls FUN_0097ade0(3,0), FUN_0097ade0(9,0) and FUN_00984390(9,1).
// @fnv 0x00985300
FUN_00985300::FUN_00985300(int aeType) : CGBase(aeType)
{
    FUN_0097ade0(3, 0);
    FUN_0097ade0(9, 0);
    FUN_00984390(9, 1);
}
}  // namespace fnv_00985300

namespace fnv_00984c20 {
extern int DAT_0108d488;
class CGBase
{
  public:
    void** m_ppVirtualMethodTable;
    CGBase(int);
    ~CGBase();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
};
class FUN_00984c20 : public CGBase
{
  public:
    FUN_00984c20(int aeType);
};
// @fnv 0x00984c20
FUN_00984c20::FUN_00984c20(int aeType) : CGBase(aeType)
{
    m_ppVirtualMethodTable = (void**)&DAT_0108d488;
    FUN_0097ade0(0x12, 0x10);
    FUN_0097ade0(3, 1);
    FUN_00984390(3, 0);
}
}  // namespace fnv_00984c20

namespace fnv_00984cb0 {
extern int DAT_0108d494;

class CGBase
{
  public:
    void** m_ppVirtualMethodTable;
    CGBase(int);
    ~CGBase();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
};
class FUN_00984cb0 : public CGBase
{
  public:
    FUN_00984cb0(int aeType);
};
// @fnv 0x00984cb0
FUN_00984cb0::FUN_00984cb0(int aeType) : CGBase(aeType)
{
    m_ppVirtualMethodTable = (void**)&DAT_0108d494;
    FUN_0097ade0(0xe, 1);
    FUN_0097ade0(0xf, 0);
    FUN_00984390(0xe, 0);
}
}  // namespace fnv_00984cb0

namespace fnv_00984d40 {
extern int DAT_0108d4a0;

class CGBase
{
  public:
    void** m_ppVirtualMethodTable;
    CGBase(int);
    ~CGBase();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
};
class FUN_00984d40 : public CGBase
{
  public:
    FUN_00984d40(int aeType);
};
// @fnv 0x00984d40
FUN_00984d40::FUN_00984d40(int aeType) : CGBase(aeType)
{
    m_ppVirtualMethodTable = (void**)&DAT_0108d4a0;
    FUN_0097ade0(0xf, 1);
    FUN_0097ade0(1, 8);
    FUN_0097ade0(1, 7);
    FUN_00984390(0xf, 0);
}
}  // namespace fnv_00984d40

namespace fnv_00985100 {
extern int DAT_0108d4f4;
namespace ol4_00985000 {
class CGBase
{
  public:
    void SetProcedureType(int);
};
}
class CGBase
{
  public:
    void** m_ppVirtualMethodTable;
    CGBase(int);
    ~CGBase();
    void FUN_0097ade0(int, int);
    void FUN_00984390(int, int);
};
class FUN_00985100 : public CGBase
{
  public:
    FUN_00985100(int aeType);
};
// @fnv 0x00985100
FUN_00985100::FUN_00985100(int aeType) : CGBase(aeType)
{
    m_ppVirtualMethodTable = (void**)&DAT_0108d4f4;
    FUN_0097ade0(0x13, 4);
    FUN_00984390(1, 6);
    ((ol4_00985000::CGBase*)this)->SetProcedureType(4);
}
}  // namespace fnv_00985100

extern CombatGoal* DAT_011f17a0[16];

// @fnv 0x00984a50
void InitCombatGoalTable()
{
    for (unsigned int i = 0; i < 0x10; ++i)
    {
        CombatGoal* pCombatGoal = CombatGoal::CreateGoal((CombatGoal::COMBAT_GOAL)i);
        DAT_011f17a0[i] = pCombatGoal;
    }
}

struct FUN_00984470_Class
{
    CombatGoal* GetCombatGoal(int index);
};

// @fnv 0x00984470
CombatGoal* FUN_00984470_Class::GetCombatGoal(int index)
{
    return *reinterpret_cast<CombatGoal**>(reinterpret_cast<char*>(this) + 0x3fff8 + index * 4);
}

extern CombatGoal* DAT_011f17a0[16];
struct S
{
    int DestroyIfFlagged(int);
};
// Iterates the 16 entries of DAT_011f17a0 and, for each non-null CombatGoal, calls DestroyIfFlagged with 1.
// @fnv 0x00984a90
// src: GUESS 0x00984a90 (confidence: medium)
void CombatGoal_DestroyGlobalCombatGoals()
{
    unsigned int i;
    {
        CombatGoal* pGoalCopy;
        {
            CombatGoal* a;
            {
                int iResult;
                for (i = 0; i < 0x10; ++i)
                {
                    a = DAT_011f17a0[i];
                    pGoalCopy = a;
                    if (pGoalCopy)
                        iResult = ((S*)pGoalCopy)->DestroyIfFlagged(1);
                    else
                        iResult = 0;
                }
            }
        }
    }
}

struct S_984af0
{
    void FUN_00984290();
    void* DestroyIfFlagged(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_00984290, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00984af0
void* S_984af0::DestroyIfFlagged(unsigned int flags)
{
    FUN_00984290();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00984ba0 {
struct CondS
{
    int m_field0;
    int m_field1;

    CondS();
    ~CondS()
    {}
};

extern int DAT_0108d440;

struct FUN_00984ba0
{
    int* m_vftable;
    CondS m_condition0;
    CondS m_condition1;
    int m_uiFilterValue;
    int m_zero;

    FUN_00984ba0(int value);
};

// @fnv 0x00984ba0
FUN_00984ba0::FUN_00984ba0(int value) : m_vftable(&DAT_0108d440), m_condition0(), m_condition1(), m_uiFilterValue(value)
{
    m_zero = 0;
}
}  // namespace fnv_00984ba0

struct CombatGoalStub_b4510
{
    CombatGoalStub_b4510(int eType);
    virtual ~CombatGoalStub_b4510();
    virtual void vfn_0();
    void FUN_0097ade0(int a1, int a2);
    void FUN_00984390(int a1, int a2);
};

struct FUN_00984dd0 : CombatGoalStub_b4510
{
    FUN_00984dd0(int eType);
    virtual ~FUN_00984dd0();
};

// @fnv 0x00984dd0
FUN_00984dd0::FUN_00984dd0(int eType) : CombatGoalStub_b4510(eType)
{
    FUN_0097ade0(0x16, 0xffff0016);
    FUN_0097ade0(0xf, 0);
    FUN_00984390(0xd, 0xffff0016);
}
