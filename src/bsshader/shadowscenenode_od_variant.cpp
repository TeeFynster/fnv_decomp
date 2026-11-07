
// src/bsshader/shadowscenenode_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/shadowscenenode.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/NiPoint3.h"
#include "../../include/Setting.h"

struct FUN_00c5b5a0_cls
{
    int __thiscall BSPortalGraph_GetAlwaysRenderAt(int idx);
};

// @fnv 0x00c5b5a0
// src: COMMUNITY 0x00c5b5a0
int __thiscall FUN_00c5b5a0_cls::BSPortalGraph_GetAlwaysRenderAt(int idx)
{
    int* p = *(int**)((char*)this + 0x40) + idx;
    int result = *p;
    return result;
}

extern "C" char DAT_01203144, DAT_01203150, DAT_011f9426, DAT_011f9434, DAT_01016264, DAT_01023128, DAT_01070c80,
    DAT_01070c70;
struct Rect2180
{
    float x[4];
    Rect2180(float, float, float, float);
};
struct Frustum2180
{
    float left, right, top, bottom, nearz, farz;
    bool ortho;
    Frustum2180(bool);
};
struct Update2180
{
    int data[3];
    void FUN_0043d410(float, bool, bool);
};
struct String2180
{
    int value;
    String2180(const char*);
    ~String2180();
};
struct Provider2180
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual float get();
};
Provider2180* Main_GetWorldSceneGraph();
int Renderer_GetScreenHeight();
int Renderer_GetScreenWidth();
float tan_0057dd70(float);
struct FUN_00a712f0
{
    int bytes[0x114 / 4];
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    FUN_00a712f0();
    void FUN_00712e60(const Rect2180&);
    void NiCamera_SetMaxFarNearRatio(float);
    void FUN_00a6faf0(const Frustum2180&);
    void SetLookAt(const NiPoint3&, const NiPoint3&);
    void NiCamera_SetMinNearPlaneDist(float);
    void NiAVObject_Update(const Update2180&);
    void AssignFixedString(const String2180&);
};
struct Target2180
{
    FUN_00a712f0* BlackJackMenu_SetupCamera();
};
// @fnv 0x007c2180
// src: COMMUNITY 0x007c2180
FUN_00a712f0* Target2180::BlackJackMenu_SetupCamera()
{
    FUN_00a712f0* camera5 = new FUN_00a712f0;
    Rect2180 rect(0.0f, 1.0f, 1.0f, 0.0f);
    camera5->FUN_00712e60(rect);
    Frustum2180 frustum5(false);
    frustum5.farz = Main_GetWorldSceneGraph()->get();
    frustum5.nearz = *((Setting*)&DAT_01203144)->Setting_Float_00403e20();
    camera5->NiCamera_SetMaxFarNearRatio(frustum5.farz / frustum5.nearz);
    float ratio3 = (double)(*(unsigned char*)&DAT_011f9426 ? *(int*)&DAT_011f9434 : Renderer_GetScreenHeight()) / Renderer_GetScreenWidth();
    float nearz = *(float*)&DAT_01016264;
    float angle = *((Setting*)&DAT_01203150)->Setting_Float_00403e20() * *(double*)&DAT_01023128 * *(double*)&DAT_01070c80;
    frustum5.left = -tan_0057dd70(angle) * nearz;
    frustum5.right = tan_0057dd70(angle) * nearz;
    frustum5.bottom = -tan_0057dd70(angle) * ratio3 * nearz;
    frustum5.top = tan_0057dd70(angle) * ratio3 * nearz;
    frustum5.ortho = false;
    camera5->FUN_00a6faf0(frustum5);
    camera5->SetLookAt(NiPoint3(0.0f, 0.0f, 1.0f), NiPoint3(0.0f, 0.0f, 1.0f));
    camera5->NiCamera_SetMinNearPlaneDist(1.0f);
    Update2180 update2;
    update2.FUN_0043d410(0.0f, false, false);
    camera5->NiAVObject_Update(update2);
    camera5->AssignFixedString(String2180(&DAT_01070c70));
    return camera5;
}
