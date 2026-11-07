
// src/fallout_shared/bgssceneinfo_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout_shared/bgssceneinfo_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/bgssceneinfo_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgssceneinfo.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout_shared/bgssceneinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgssceneinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../include/Script.h"

struct FUN_004a7cf0_shell
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int m_002c;
    int m_0030;
    int m_0034;
    int m_0038;
    int m_003c;

    int GetValueAt(int index);
};
struct Flt
{
    operator unsigned int() const;
};
struct FUN_004a8070_shell
{
    int GetScriptText();
};
extern unsigned char DAT_0118868c;
unsigned char __cdecl BGSSceneInfo_GetAggregateInstances();
int __cdecl MinInt(int iA, int iB);
struct FUN_004a8f50_shell
{
    void NiTMap_NiTexture_TEX_USER_DATA_NiTMap(int a);
    void* BGSTextureUseMap_BGSTextureUseMap();
};
struct GlobalObject2_0040c150
{
    int* Int();
};
struct GlobalObject2_0045cfe0
{
    int* Int();
};
GlobalObject2_0045cfe0 g_011c59e0;
int BGSSceneInfo_GetActorMemoryBudgetCap();
struct DummyArr
{
    int GetBufferElementAddress(unsigned int);
    int FUN_004a95b0(unsigned int);
};
struct FUN_004a9630_shell
{
    void* FUN_004a9630(unsigned int flags);
};
struct FUN_004a9850_shell
{
    void FUN_004a9850();
};
void __cdecl _Deallocate(void* p);

struct __declspec(align(16)) ChildBuffer
{
    char name[512];
};

struct Node;

// SceneChildListView: unit-local view of the children interface Node::GetChildren returns (virtual GetFirst/GetNext/GetAt walked by 0x004a9240), not the shared TileWorkList
struct SceneChildListView
{
    virtual void vf00();
    virtual void vf04();
    virtual int GetFirst();
    virtual int GetNext(int index);
    virtual void vf10();
    virtual Node* GetAt(int index, ChildBuffer* buffer);
};

struct Node
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual SceneChildListView* GetChildren();

    int NiObjectNET_GetControllers();
};

// @fnv 0x004a9240
// src: XBOX_PDB 0x004a9240
int __cdecl BGSSceneInfo_GetHavokFaceCount(Node* node)
{
    if (node == 0)
        return 0;
    int count = 0;
    switch (node->NiObjectNET_GetControllers())
    {
    case 3:
        return 1;
        break;
    case 10: {
        Node* obj = node;
        SceneChildListView* list = obj->GetChildren();
        int index = list->GetFirst();
        while (index != -1)
        {
            ChildBuffer buffer;
            Node* child = list->GetAt(index, &buffer);
            if (child == 0)
                break;
            count += BGSSceneInfo_GetHavokFaceCount(child);
            index = list->GetNext(index);
        }
        return count;
    }
    break;
    case 9: {
        Node* obj = node;
        SceneChildListView* list = obj->GetChildren();
        int index = list->GetFirst();
        while (index != -1)
        {
            ChildBuffer buffer;
            Node* child = list->GetAt(index, &buffer);
            if (child == 0)
                break;
            count += BGSSceneInfo_GetHavokFaceCount(child);
            index = list->GetNext(index);
        }
        return count;
    }
    break;
    case 22: {
        Node* obj = node;
        SceneChildListView* list = obj->GetChildren();
        int index = list->GetFirst();
        while (index != -1)
        {
            ChildBuffer buffer;
            Node* child = list->GetAt(index, &buffer);
            if (child == 0)
                break;
            count += BGSSceneInfo_GetHavokFaceCount(child);
            index = list->GetNext(index);
        }
        return count;
    }
    break;
    case 23: {
        Node* obj = node;
        SceneChildListView* list = obj->GetChildren();
        int index = list->GetFirst();
        while (index != -1)
        {
            ChildBuffer buffer;
            Node* child = list->GetAt(index, &buffer);
            if (child == 0)
                break;
            count += BGSSceneInfo_GetHavokFaceCount(child);
            index = list->GetNext(index);
        }
        return count;
    }
    break;
    default:
        return 10;
    }
}
