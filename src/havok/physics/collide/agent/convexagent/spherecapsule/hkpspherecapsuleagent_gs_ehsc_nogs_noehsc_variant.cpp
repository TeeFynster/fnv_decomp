
// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00d3ef70_CdBody;
struct S_00d3ef70_Input;
struct S_00d3ef70_Agent;
struct S_00d3ef70_Collector;
typedef S_00d3ef70_Agent* (*S_00d3ef70_CreateFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&,
                                                   const S_00d3ef70_Input&, void*);
typedef void (*S_00d3ef70_GetPenetrationsFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&,
                                               const S_00d3ef70_Input&, S_00d3ef70_Collector&);
typedef void (*S_00d3ef70_GetClosestPointsFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&,
                                                const S_00d3ef70_Input&, S_00d3ef70_Collector&);
typedef void (*S_00d3ef70_LinearCastFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&,
                                          S_00d3ef70_Collector&, S_00d3ef70_Collector*);
struct S_00d3ef70_AgentFuncs
{
    S_00d3ef70_CreateFunc m_pCreateFunc;
    S_00d3ef70_GetPenetrationsFunc m_pQueryPenetrationsFunc;
    S_00d3ef70_GetClosestPointsFunc m_getClosestPointsFunc;
    S_00d3ef70_LinearCastFunc m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};
struct S_00d3ef70_Dispatcher
{
    void registerCollisionAgent(S_00d3ef70_AgentFuncs& f, int typeA, int typeB);
};
S_00d3ef70_Agent* hkpSphereCapsuleAgent_createCapsuleSphereAgent(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, void*);
void Object_UpdateFields_00d3f040(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void Object_ProcessAndReturnValue_00d3f4c0(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void Object_UpdateFields_00d3ac80(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&,
                  S_00d3ef70_Collector*);
S_00d3ef70_Agent* hkMemoryRouter_getInstance_AllocateAndInitializeObject16(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, void*);
void hkpSphereCapsuleAgent_staticGetPenetrations(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void FUN_00d3ebe0(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void Object_ProcessEntries_00daf8e0(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&,
                  S_00d3ef70_Collector*);
void hkpSphereCapsuleAgent_registerAgent(S_00d3ef70_Dispatcher* dispatcher);
class InnerCls
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned short a, int b);
};
inline void InnerCls::v0()
{}
inline void InnerCls::v1()
{}
inline void InnerCls::v2()
{}
inline void InnerCls::v3()
{}
inline void InnerCls::v4()
{}
inline void InnerCls::v5(unsigned short a, int b)
{
    a;
    b;
}
class FUN_00d3e2b0_cls
{
  public:
    virtual void v0(int a);
    int m_i04;
    InnerCls* m_pInner;
    unsigned short m_w0c;
    void hkpSphereCapsuleAgent_cleanup(int a1);
};
#include "../../../../../../../include/hkMemoryRouter.h"
struct ObjAllocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};
struct SmallRecord
{
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    unsigned short m_w0C;
};
extern char DAT_010cf018[];
hkMemoryRouter* hkMemoryRouter_getInstance();
void __cdecl hkpSphereCapsuleAgent_createCapsuleSphereAgent(int a, int b, int c, int d);
void __cdecl hkpSphereCapsuleAgent_staticGetPenetrations(int a, int b, int c, int d);
void __stdcall hkpSphereCapsuleAgent_getPenetrations(int a, int b, int c, int d);
extern char DAT_010ce81c;
struct FUN_00d3f040_tmp
{
    const char* str;
    unsigned char flag;
    unsigned int value;
};
void __cdecl hkpSphereCapsuleAgent_staticGetPenetrations(unsigned int a, unsigned int b, unsigned int c, FUN_00d3f040_tmp* p);
void __cdecl Object_UpdateFields_00d3f040(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3);
extern char DAT_010ce81c;
struct AgentDispatchDescriptor
{
    const void* dispatchTable;
    unsigned char isFlipped;
    volatile unsigned int tag;
};
struct CollisionDispatcher
{
    void hkpSphereCapsuleAgent_getPenetrations(void* bodyB, void* bodyA, void* input, AgentDispatchDescriptor* descriptor);
    void hkpSymmetricAgentLinearCast_hkpSphereCapsuleAgent_getPenetrations(void* bodyA, void* bodyB, void* volatile input, unsigned int tag);
};
