
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpballsocketdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpballsocketdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../../include/hkTransform.h"
#include "../../../../../../../../../include/hkVector4.h"

struct Motion
{
    hkVector4 v00;
    hkVector4 v10;
    hkVector4 v20;
};
struct Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Motion motion;
};
struct Body
{
    int unk00;
    int unk04;
    int unk08;
    Shape* shape;
};
struct Sub
{
    void hkpPrimitiveDrawer_setDisplayHandler(void* a);
};
struct Listener
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
    virtual void Fire(hkVector4* a, hkVector4* b, unsigned c, int d, int e);
};
struct Obj
{
    char pad[0x40];
    hkVector4 m40;
    hkVector4 m50;
    char pad2[0x60];
    Sub mC0;
    void hkpConstraintDrawer_updateCommonParameters(Body* b, hkTransform* t, hkTransform* r);
    void hkpConstraintDrawer_drawPivots(int a, int b);
    void hkpConstraintDrawer_drawBodyFrames(int a, int b);
    void FireMotionEvent(Body* b, Listener* l, int a, int c);
};

// Computes transforms from the body's shape motion, updates m40/m50 vectors, calls FUN_00de44c0/FUN_00de4530, then fires the listener with both vectors.
// @fnv 0x00de8090
void Obj::FireMotionEvent(Body* apBody, Listener* apListener, int aiArg, int aiArg2)
{
    Motion* pMotion = &apBody->shape->motion;
    mC0.hkpPrimitiveDrawer_setDisplayHandler(apListener);
    // Preserve uninitialized aligned storage; pointer arrays avoid adding a /GS cookie.
    __declspec(align(16)) void* rStorage[sizeof(hkTransform) / sizeof(void*)];
    __declspec(align(16)) void* tStorage[sizeof(hkTransform) / sizeof(void*)];
    hkTransform& r = *reinterpret_cast<hkTransform*>(rStorage);
    hkTransform& t = *reinterpret_cast<hkTransform*>(tStorage);
    hkpConstraintDrawer_updateCommonParameters(apBody, &t, &r);
    hkVector4* pVec40;
    hkVector4* pVec50;
    pVec50 = &m50;
    pVec50->setTransformedPos_00c7f640(t, pMotion->v20);   // 0x00c7f640 = hkVector4::_setTransformedPos
    pVec40 = &m40;
    pVec40->setTransformedPos_00c7f640(r, pMotion->v10);
    hkpConstraintDrawer_drawPivots(aiArg, aiArg2);
    hkpConstraintDrawer_drawBodyFrames(aiArg, aiArg2);
    apListener->Fire(pVec40, pVec50, 0xffff0000, aiArg, aiArg2);
}
