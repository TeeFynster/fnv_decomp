
// src/fallout_shared/pathfinding/navmeshobstaclemanager_nogf_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout_shared/pathfinding/navmeshobstaclemanager.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.


#include <xmmintrin.h>
struct V3
{
    float x, y, z;
    void FUN_006815c0();
    V3* FUN_00439ef0(V3* ret, const V3* other);
    float FUN_004a7290();
};
struct S006c4ad0_Obs
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    V3 pos;
};
struct S006c4ad0_Ptr
{
    S006c4ad0_Obs* p;
    S006c4ad0_Ptr(S006c4ad0_Obs* q);
    void FUN_0045cec0();
    S006c4ad0_Obs* FUN_00559450();
    ~S006c4ad0_Ptr();
};
struct S006c4ad0_Body;
struct S006c4ad0_Ref2
{
    void* FUN_004b4ec0();
};
struct S006c4ad0_Queue
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual unsigned int Count();
    void FUN_006c6030(S006c4ad0_Body** out);
};
struct S006c4ad0_Body
{
    S006c4ad0_Ref2* GetReferenceFlags();
};
struct S006c4ad0_Map
{
    bool FUN_006c62d0(S006c4ad0_Body* k, S006c4ad0_Ptr* out);
};
struct S006c4ad0_List
{
    void FUN_00631620(const S006c4ad0_Ptr* p);
};
__declspec(align(16)) struct S006c4ad0_Holder3
{
    __m128 q;
    void FUN_004a3c90(void* n);
};
extern "C" void __cdecl FUN_00458620(V3* out, S006c4ad0_Holder3* in);
extern const float kObsDist;
struct ObsMgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    S006c4ad0_List list3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    S006c4ad0_Queue queueA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    S006c4ad0_Map mapE0;
    void FUN_006c1760(S006c4ad0_Ptr* sp);
    void FUN_006c4ad0();
};

// @fnv 0x006c4ad0
void ObsMgr::FUN_006c4ad0()
{
    unsigned int count = queueA0.Count();
    for (unsigned int i = 0; i < count; i++)
    {
        S006c4ad0_Body* body;
        queueA0.FUN_006c6030(&body);
        S006c4ad0_Ptr sp(0);
        if (mapE0.FUN_006c62d0(body, &sp))
        {
            S006c4ad0_Holder3 h;
            h.FUN_004a3c90(body->GetReferenceFlags()->FUN_004b4ec0());
            V3 v;
            v.FUN_006815c0();
            FUN_00458620(&v, &h);
            V3 tmp;
            if (v.FUN_00439ef0(&tmp, &sp.FUN_00559450()->pos)->FUN_004a7290() > kObsDist)
                FUN_006c1760(&sp);
            list3C.FUN_00631620(&sp);
        }
    }
}
