
// src/fallout_shared/pathfinding/navmeshobstaclemanager_nogf_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout_shared/pathfinding/navmeshobstaclemanager.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.


#include <xmmintrin.h>
struct V3
{
    float x, y, z;
    void FUN_006815c0();
    V3* SubtractIntoVector(V3* ret, const V3* other);
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
    S006c4ad0_Obs* Modelloader_GetReferencedThis();
    ~S006c4ad0_Ptr();
};
struct S006c4ad0_Body;
struct S006c4ad0_Ref2
{
    void* hkpRigidBody_getPosition();
};
struct S006c4ad0_Queue
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual unsigned int Count();
    void LockFreeQueue_bhkRigidBody_Pop(S006c4ad0_Body** out);
};
struct S006c4ad0_Body
{
    S006c4ad0_Ref2* GetReferenceFlags();
};
struct S006c4ad0_Map
{
    bool NiTMapBase_DFALL_NiTMapItem_bhkRigidBody_NiPointer_ObstacleData_bhkRigidBody_NiPointer_ObstacleData_GetAt(S006c4ad0_Body* k, S006c4ad0_Ptr* out);
};
struct S006c4ad0_List
{
    void BSSimpleList_NiPointer_bhkAction_Remove(const S006c4ad0_Ptr* p);
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
    void NavMeshObstacleManager_UpdateObstacle(S006c4ad0_Ptr* sp);
    void NavMeshObstacleManager_ProcessDeactivatedObstacles();
};

// @fnv 0x006c4ad0
// src: COMMUNITY 0x006c4ad0
void ObsMgr::NavMeshObstacleManager_ProcessDeactivatedObstacles()
{
    unsigned int count = queueA0.Count();
    for (unsigned int i = 0; i < count; i++)
    {
        S006c4ad0_Body* body;
        queueA0.LockFreeQueue_bhkRigidBody_Pop(&body);
        S006c4ad0_Ptr sp(0);
        if (mapE0.NiTMapBase_DFALL_NiTMapItem_bhkRigidBody_NiPointer_ObstacleData_bhkRigidBody_NiPointer_ObstacleData_GetAt(body, &sp))
        {
            S006c4ad0_Holder3 h;
            h.FUN_004a3c90(body->GetReferenceFlags()->hkpRigidBody_getPosition());
            V3 v;
            v.FUN_006815c0();
            FUN_00458620(&v, &h);
            V3 tmp;
            if (v.SubtractIntoVector(&tmp, &sp.Modelloader_GetReferencedThis()->pos)->FUN_004a7290() > kObsDist)
                NavMeshObstacleManager_UpdateObstacle(&sp);
            list3C.BSSimpleList_NiPointer_bhkAction_Remove(&sp);
        }
    }
}
