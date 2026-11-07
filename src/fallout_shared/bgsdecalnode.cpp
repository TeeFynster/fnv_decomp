#include "../../include/GO.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiPoint3.h"
#include "../../include/BSTempEffect.h"
#include "../../include/EffectSetting.h"
#include "../../include/NiObject.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiNode.h"
#include "../../include/BGSDecalNode.h"

// src/fallout_shared/bgsdecalnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgsdecalnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef struct GlobalObject_00a7b610
{
    int data;
} GlobalObject_00a7b610;

GlobalObject_00a7b610 g_011c7d34;

struct FUN_004ee0d0_shell
{
    GlobalObject_00a7b610* GetGlobalObject();
};

// @fnv 0x004ee0d0
GlobalObject_00a7b610* FUN_004ee0d0_shell::GetGlobalObject()
{
    return &g_011c7d34;
}


// Calls FUN_004ee1e0 on this, frees the node with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x004ee0e0
void* BGSDecalNode::DestroyDecalNode(unsigned int flags)
{
    this->FUN_004ee1e0();
    if (flags & 1)
        BGSDecalNode::operator delete(this, 0xb4);
    return this;
}

// @fnv 0x004ee4d0
// src: XBOX_PDB 0x004ee4d0
void BGSDecalNode::AttachChild_004ee4d0(NiAVObject* apAVObj, bool abFirstAvailableSlot)
{
    NiNode::AttachChildInAvailableSlot(apAVObj, abFirstAvailableSlot);
}

// @fnv 0x004ee560
// src: GUESS 0x004ee560 (confidence: low)
void BGSDecalNode::ProcessState_004ee560(int aiValue)
{
    GO g(0);
    InsertChild(reinterpret_cast<BSTempEffect*>(aiValue), &g);
}

// @fnv 0x004ee450
// src: XBOX_PDB 0x004ee450
void BGSDecalNode::AttachChild(BSTempEffect* apAVObj, bool abFlag)
{
    void* prop = apAVObj->Get3D()->GetProperty(3);
    if (prop != 0)
    {
        ((EffectSetting*)prop)->BSShaderProperty_SetDepthBias(1.0f);
    }
    NiNode::AttachChildInAvailableSlot(apAVObj->Get3D(), abFlag);
}

struct S2
{
    void NiNode_DetachChild_00a5e780(void*);
};
struct VirtParam
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void* v38(void*);
};
// Calls RemoveEffect with a, then calls FUN_00a5e780 with the result of a->v38(b).
// @fnv 0x004ee5d0
void BGSDecalNode::InsertChild(BSTempEffect* pEffect, void* b)
{
    RemoveEffect(pEffect);
    ((S2*)this)->NiNode_DetachChild_00a5e780(reinterpret_cast<VirtParam*>(pEffect)->v38(b));
}

// Removes the given effect from the list stored at offset 0xac of this node.
// @fnv 0x004ee4f0
void BGSDecalNode::RemoveEffect(void* apEffect)
{
    GO tmp((int)apEffect);
    pList->Remove(tmp);
}


struct GlobalObject_004ee810
{
    int data[2];
    GlobalObject_004ee810();
};

NiFixedString const& FixedStrings_QSkinnedDecalNode();
NiFixedString const& FixedStrings_QDecalNode();

// Allocates a GlobalObject_004ee810 and sets the object's name from one of two fixed strings depending on flag.
// @fnv 0x004ee390
void BGSDecalNode::InitNameAndData()
{
    pList = reinterpret_cast<BSSimpleList<GO>*>(new GlobalObject_004ee810);

    if (flag)
        SetName(FixedStrings_QSkinnedDecalNode());
    else
        SetName(FixedStrings_QDecalNode());
}


extern int _data_011c16bc;

// Allocates and constructs a new BGSDecalNode and returns it as a NiObject pointer.
// @fnv 0x004ee6f0
NiObject* BGSDecalNode::MakeClone(CloningProcess& arCloneData)
{
    BGSDecalNode* pNewNode = new BGSDecalNode;
    return pNewNode;
}

struct Callback
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55(void* object, int enabled);
    void NiAVObject_Update(NiPoint3* offset);
};
struct EffectsList
{
    void FUN_005ae3d0(BGSDecalNode**);
};
extern EffectsList g_011c7d20;
// @fnv 0x004ee120
BGSDecalNode::BGSDecalNode(NiNode* parent, unsigned char flag) : NiNode(0)
{
    this->flag = flag;
    InitNameAndData();
    reinterpret_cast<Callback*>(parent)->v55(this, 1);

    float vecOffset[3];
    reinterpret_cast<NiPoint3*>(vecOffset)->FUN_0043d410(0.0f, 0, 0);
    reinterpret_cast<Callback*>(parent)->NiAVObject_Update(reinterpret_cast<NiPoint3*>(vecOffset));
    BGSDecalNode* pSelf = this;
    g_011c7d20.FUN_005ae3d0(&pSelf);
}

struct FUN_004ee610_view
{
    BSTempEffect* Modelloader_GetReferencedThis();
    void FUN_00a59e00(int aValue);
};

struct FUN_004ee610_node
{
    FUN_004ee610_view* FUN_006815c0();
    bool BSSimpleList_NiRefObjectPtr_IsEmpty();
    FUN_004ee610_node* FUN_00726070();
};

// @fnv 0x004ee610
// src: XBOX_PDB 0x004ee610
void BGSDecalNode::OnVisible_004ee610(int a1)
{
    if (IsVisualObject())
    {
        FUN_004ee610_node* node = reinterpret_cast<FUN_004ee610_node*>(pList);
        while (node != 0 && !node->BSSimpleList_NiRefObjectPtr_IsEmpty())
        {
            {
                GO local((int)node->FUN_006815c0()->Modelloader_GetReferencedThis()->Get3D());
                if (reinterpret_cast<FUN_004ee610_view*>(&local)->Modelloader_GetReferencedThis())
                {
                    reinterpret_cast<FUN_004ee610_view*>(reinterpret_cast<FUN_004ee610_view*>(&local)->Modelloader_GetReferencedThis())
                        ->FUN_00a59e00(a1);
                }
                node = node->FUN_00726070();
            }
        }
    }
}

struct DecalListNode
{
    void* vtable;
    DecalListNode* next;
    ~DecalListNode();
};
struct DecalListManager
{
    int unk00;
    DecalListNode* head;
    void FUN_006e5cc0(DecalListNode* node);
    void FUN_0066b0d0(int state);
    void PopHead();
};
// Removes the head node from the list, frees it, or calls FUN_0066b0d0(0) when the list is empty.
// @fnv 0x004ee8a0
void DecalListManager::PopHead()
{
    if (head != 0)
    {
        DecalListNode* node = head;
        head = node->next;
        FUN_006e5cc0(node);
        node->next = 0;
        delete node;
    }
    else
    {
        FUN_0066b0d0(0);
    }
}

namespace s4ee050 {

struct NodeList
{
    void FUN_005ae3d0(NiNode* const& pkNode);
};

extern NodeList DAT_011c7d20;

}

// @fnv 0x004ee050
BGSDecalNode::BGSDecalNode() : NiNode(0)
{
    InitNameAndData();
    s4ee050::DAT_011c7d20.FUN_005ae3d0(this);
}
