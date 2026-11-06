
// src/fallout/ai/arrowprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/arrowprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/arrowprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/arrowprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/arrowprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/arrowprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV_VEC4_SIMD
#include <xmmintrin.h>
#include "../../../include/Vec4.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiPoint3.h"

void __cdecl FUN_004a3e00(Vec4* out, const NiPoint3& in);

struct Filter
{
    int v;
    Filter();
    int __thiscall FUN_0043b4d0();
    int __thiscall FUN_006240b0();
};

struct Shape;
struct EObj;
struct WorldObj
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void GetTransform(EObj*);
    Shape* __thiscall FUN_004ae6a0();
    Filter __thiscall FUN_0043b4f0();
    bool __thiscall FUN_008cffa0();
    void* __thiscall FUN_00436aa0();
    void* __thiscall FUN_00891170();
};

struct CollObj
{
    WorldObj* __thiscall FUN_006fa820();
    float __thiscall FUN_004a7bd0();
};

CollObj* __cdecl FUN_0043b610(void* p);
bool __cdecl FUN_0043b300(const void* rtti, void* obj);
extern char RTTI_01267e64;
extern char RTTI_012683c8;

struct EObj
{
    struct RawVector
    {
        __m128 quad;
    };
    RawVector storage[4];
    EObj();
    void __thiscall FUN_00cb2240(void* g, void* f);
    void __thiscall FUN_008cd6a0(void* x, void* y);
};

struct GObj
{
    struct RawVector
    {
        __m128 quad;
    };
    RawVector storage[4];
    GObj(EObj* e);
};

void __cdecl FUN_0056df80(EObj* e, void* child);

struct CSub
{
    __m128 quad;
    void __thiscall FUN_00c7f690(EObj* e, Vec4* v);
};

struct __declspec(align(16)) CObj
{
    CSub m0;
    CSub m1;
    unsigned int flags20, filter24;
    void __thiscall FUN_00632ca0();
};

struct Sub2;
struct DObj;
struct ResObj
{
    void* __thiscall ForwardToV8(Sub2*, CObj*, DObj*);
};

struct Sub2
{
    bool value;
    bool __thiscall FUN_005609f0();
};

struct __declspec(align(16)) DObj
{
    float normalX, normalY, normalZ, normalW;
    float fraction;
    int m_uiExtraInfo, unk18, unk1c;
    unsigned int shapeKeys[8];
    void* rootCollidable;
    void __thiscall FUN_004a3d20();
    Sub2* __thiscall FUN_00632c60(Sub2* b);
};

struct Shape
{
    ResObj* __thiscall FUN_004ae750();
};

struct P1Obj
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual NiNode* getNode();
    void* __thiscall FUN_00461130();
};

// @fnv 0x008cfbc0
void* __cdecl FUN_008cfbc0(void* p1, NiPoint3 a, NiPoint3 b, float* p4, bool p5)
{
    bool flag = false;
    if (p1)
    {
        CollObj* coll = FUN_0043b610(p1);
        if (coll)
        {
            WorldObj* world = coll->FUN_006fa820();
            Shape* shape = world ? world->FUN_004ae6a0() : 0;
            if (shape)
            {
                if (world->FUN_0043b4f0().FUN_0043b4d0() == 8)
                {
                    if (world->FUN_0043b4f0().FUN_006240b0() != 0x12)
                    {
                        if (world->FUN_0043b4f0().FUN_006240b0() != 0x13)
                        {
                            if (!p5 || world->FUN_0043b4f0().FUN_006240b0() != 1)
                            {
                                Vec4 va;
                                FUN_004a3e00(&va, a);
                                Vec4 vb;
                                FUN_004a3e00(&vb, a.FUN_00439e90(b.ApplyScaled(*p4)));
                                CObj oc;
                                oc.FUN_00632ca0();
                                DObj od;
                                od.FUN_004a3d20();
                                EObj oe;
                                if (FUN_0043b300(&RTTI_01267e64, coll))
                                {
                                    CollObj* scaledColl = coll;
                                    if (!world->FUN_008cffa0() || scaledColl->FUN_004a7bd0() == 1.0)
                                    {
                                        FUN_0056df80(&oe, ((P1Obj*)p1)->FUN_00461130());
                                        if (FUN_0043b300(&RTTI_012683c8, world))
                                        {
                                            WorldObj* transformedWorld = world;
                                            EObj of;
                                            GObj og(&oe);
                                            of.FUN_008cd6a0(transformedWorld->FUN_00891170(),
                                                            transformedWorld->FUN_00436aa0());
                                            oe.FUN_00cb2240(&og, &of);
                                        }
                                    }
                                    else
                                    {
                                        world->GetTransform(&oe);
                                    }
                                }
                                else
                                {
                                    world->GetTransform(&oe);
                                }
                                oc.m0.FUN_00c7f690(&oe, &va);
                                oc.m1.FUN_00c7f690(&oe, &vb);
                                Sub2 bt;
                                shape->FUN_004ae750()->ForwardToV8(&bt, &oc, &od);
                                Sub2 bt2;
                                if (od.FUN_00632c60(&bt2)->FUN_005609f0())
                                {
                                    *p4 *= od.fraction;
                                    flag = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        NiNode* node = ((P1Obj*)p1)->getNode();
        if (node)
        {
            unsigned int i;
            for (i = 0; i < node->FUN_0043b480(); i++)
            {
                void* childItem = node->FUN_0043b4a0(i);
                void* r = FUN_008cfbc0(childItem, a, b, p4, p5);
                if (r)
                    return r;
            }
        }
    }
    if (flag)
        return p1;
    return 0;
}
