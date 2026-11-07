// src/havok/common/base/math/util/hkmathutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/util/hkmathutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
extern float DAT_01011d78;
extern float DAT_01012068;

struct __declspec(align(16)) S_c7a410_Vec
{
    float x, y, z, w;
};
struct S_c7a410_A
{
    void FUN_00cb26e0(const void* p);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_c7a410_B
{
    void hkRotation_set(const void* p);
    __m128 r[3];
};
struct S_c7a410_C
{
    void setMul(const void* p, S_c7a410_A* a);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_c7a410_D
{
    void hkQuaternion_setInverseMul(S_c7a410_A* b, S_c7a410_C* c);
    void hkQuaternion_decomposeRestAxis(const S_c7a410_Vec* v, const void* o, float* out);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct S_c7a410_Node
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int GetType();
    S_c7a410_Node* hkpMalleableConstraintData_getWrappedConstraintData();
    void hkpRagdollConstraintData_setTarget(S_c7a410_B* t);
};
struct S_c7a410_Item
{
    int unk00;
    int unk04;
    int unk08;
    S_c7a410_Node* unk0c;
};
struct S_c7a410_Cnt
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct S_c7a410_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_c7a410_Item** unk14;
    int unk18;
    int unk1c;
    int* unk20;
    int unk24;
    int unk28;
    S_c7a410_Cnt* unk2c;
};

// Iterates indexed items, dispatches on node type, and reads per-item data from arr at 0x10 plus 0x30-byte strides.
// @fnv 0x00c7a410
// src: XBOX_PDB 0x00c7a410
void bhkRagdollController_bhkRagdollPoweredConstraintController_driveToPose(S_c7a410_Obj* obj, char* apBuffer)
{
    int iCount = obj->unk2c->unk1c;
    for (int iIndex = 0; iIndex < iCount; iIndex++)
    {
        int iArrayIndex = obj->unk20[iIndex] - 1;
        if (iArrayIndex < 0)
            continue;
        S_c7a410_Item* pItem = obj->unk14[iArrayIndex];
        if (!pItem)
            continue;
        S_c7a410_Node* p = pItem->unk0c;
        if (p->GetType() == 13)
            p = p->hkpMalleableConstraintData_getWrappedConstraintData();
        switch (p->GetType())
        {
        case 7: {
            S_c7a410_B tTransform;
            tTransform.hkRotation_set(apBuffer + 0x10 + iIndex * 0x30);
            p->hkpRagdollConstraintData_setTarget(&tTransform);
            break;
        }
        case 2: {
            S_c7a410_A a;
            a.FUN_00cb26e0((char*)p + 0x20);
            S_c7a410_A b;
            b.FUN_00cb26e0((char*)p + 0x60);
            S_c7a410_C c;
            c.setMul(apBuffer + 0x10 + iIndex * 0x30, &a);
            S_c7a410_D d;
            d.hkQuaternion_setInverseMul(&b, &c);
            S_c7a410_Vec v;
            _mm_store_ps(&v.x, _mm_setr_ps(DAT_01012068, DAT_01011d78, DAT_01011d78, DAT_01011d78));
            float out;
            S_c7a410_A o;
            d.hkQuaternion_decomposeRestAxis(&v, &o, &out);
            *(float*)((char*)p + 0xac) = out;
            break;
        }
        }
    }
}
