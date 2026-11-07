
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

void __cdecl NI2HK(Vec4* out, const NiPoint3& in);

struct Filter
{
    int v;
    Filter();
    int __thiscall CFilter_GetLayer();
    int __thiscall CFilter_GetBipedPart();
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
    Shape* __thiscall bhkWorldObject_GetShape();
    Filter __thiscall bhkWorldObject_GetCollisionFilter();
    bool __thiscall bhkWorldObject_IsAddedToWorld();
    void* __thiscall FUN_00436aa0();
    void* __thiscall FUN_00891170();
};

struct CollObj
{
    WorldObj* __thiscall bhkNiCollisionObject_GetWorldObject();
    float __thiscall FUN_004a7bd0();
};

CollObj* __cdecl FUN_0043b610(void* p);
bool __cdecl NiObject_IsKindOf(const void* rtti, void* obj);
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
    void __thiscall hkTransform_setMul(void* g, void* f);
    void __thiscall hkTransform_set(void* x, void* y);
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
    void __thiscall hkVector4_setTransformedInversePos(EObj* e, Vec4* v);
};

struct __declspec(align(16)) CObj
{
    CSub m0;
    CSub m1;
    unsigned int flags20, filter24;
    void __thiscall hkpShapeRayCastInput_hkpShapeRayCastInput();
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
    void __thiscall hkpShapeRayCastOutput_hkpShapeRayCastOutput();
    Sub2* __thiscall hkpShapeRayCastCollectorOutput_hasHit(Sub2* b);
};

struct Shape
{
    ResObj* __thiscall Bipedanim_GetReferenceFlagsOrZero();
};

struct P1Obj
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual NiNode* getNode();
    void* __thiscall NiAVObject_GetWorldRotate();
};

// @fnv 0x008cfbc0
// src: COMMUNITY 0x008cfbc0
void* __cdecl ArrowProjectile_PickSceneGraph(void* p1, NiPoint3 a, NiPoint3 b, float* p4, bool p5)
{
    bool flag = false;
    if (p1)
    {
        CollObj* coll = FUN_0043b610(p1);
        if (coll)
        {
            WorldObj* world = coll->bhkNiCollisionObject_GetWorldObject();
            Shape* shape = world ? world->bhkWorldObject_GetShape() : 0;
            if (shape)
            {
                if (world->bhkWorldObject_GetCollisionFilter().CFilter_GetLayer() == 8)
                {
                    if (world->bhkWorldObject_GetCollisionFilter().CFilter_GetBipedPart() != 0x12)
                    {
                        if (world->bhkWorldObject_GetCollisionFilter().CFilter_GetBipedPart() != 0x13)
                        {
                            if (!p5 || world->bhkWorldObject_GetCollisionFilter().CFilter_GetBipedPart() != 1)
                            {
                                Vec4 va;
                                NI2HK(&va, a);
                                Vec4 vb;
                                NI2HK(&vb, a.FUN_00439e90(b.ApplyScaled(*p4)));
                                CObj oc;
                                oc.hkpShapeRayCastInput_hkpShapeRayCastInput();
                                DObj od;
                                od.hkpShapeRayCastOutput_hkpShapeRayCastOutput();
                                EObj oe;
                                if (NiObject_IsKindOf(&RTTI_01267e64, coll))
                                {
                                    CollObj* scaledColl = coll;
                                    if (!world->bhkWorldObject_IsAddedToWorld() || scaledColl->FUN_004a7bd0() == 1.0)
                                    {
                                        FUN_0056df80(&oe, ((P1Obj*)p1)->NiAVObject_GetWorldRotate());
                                        if (NiObject_IsKindOf(&RTTI_012683c8, world))
                                        {
                                            WorldObj* transformedWorld = world;
                                            EObj of;
                                            GObj og(&oe);
                                            of.hkTransform_set(transformedWorld->FUN_00891170(),
                                                            transformedWorld->FUN_00436aa0());
                                            oe.hkTransform_setMul(&og, &of);
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
                                oc.m0.hkVector4_setTransformedInversePos(&oe, &va);
                                oc.m1.hkVector4_setTransformedInversePos(&oe, &vb);
                                Sub2 bt;
                                shape->Bipedanim_GetReferenceFlagsOrZero()->ForwardToV8(&bt, &oc, &od);
                                Sub2 bt2;
                                if (od.hkpShapeRayCastCollectorOutput_hasHit(&bt2)->FUN_005609f0())
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
                void* r = ArrowProjectile_PickSceneGraph(childItem, a, b, p4, p5);
                if (r)
                    return r;
            }
        }
    }
    if (flag)
        return p1;
    return 0;
}
