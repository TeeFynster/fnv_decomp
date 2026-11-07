// gamebryo2.2/corelibs/niconsolerenderer/nid3drenderstategroup.cpp: D3DRenderStateGroup, RenderOwner, StateGroup, StateGroupE7F5 (12 functions)

#include "nid3drenderstategroup_decls.h"
#include "../../../../include/NiDX9RenderState.h"
// Returns the render state group from DAT_0126f718, setting its flag to true if it was false.
// @fnv 0x00e7f5d0
D3DRenderStateGroup* D3DRenderStateGroup::GetCurrentRenderStateGroup()
{
    D3DRenderStateGroup* group = DAT_0126f718->Get();
    if (!group->m_bHasBeenApplied)
        group->m_bHasBeenApplied = true;
    return group;
}

struct Entry00e7ef40
{
    int m_iFadeIndex;
    int m_iPad;
    Entry00e7ef40* m_pkNext;
};
// DAT_0126f714 is NiDX9Renderer::pRenderState, assigned by NiD3DPass::SetActiveRenderer (0x00e7eea0).
extern NiDX9RenderState* DAT_0126f714;

// The shared header leaves the render-state cache at 0x124 in its padding and slot 26 untyped.
inline int GetCachedRenderState(NiDX9RenderState* state, int key)
{
    return reinterpret_cast<int*>(state->_pad + 0x124 - sizeof(NiD3DRenderState))[key * 2];
}

inline void SetCachedRenderState(NiDX9RenderState* state, int key, int value, int save, int force)
{
    typedef void (__thiscall* SetState)(NiDX9RenderState*, int, int, int, int);
    reinterpret_cast<SetState>((*reinterpret_cast<void***>(state))[26])(state, key, value, save, force);
}

struct Group00e7ef40
{
    char _pad0[16];
    Entry00e7ef40* m_pkSaved;
    unsigned int NiD3DRenderStateGroup_RestoreRenderStates();
};
// @fnv 0x00e7ef40
// src: XBOX_PDB 0x00e7ef40
unsigned int Group00e7ef40::NiD3DRenderStateGroup_RestoreRenderStates()
{
    Entry00e7ef40* pkRSEntry = m_pkSaved;
    while (pkRSEntry)
    {
        int iState = pkRSEntry->m_iFadeIndex;
        NiDX9RenderState* pRenderer = DAT_0126f714;
        int iVal = GetCachedRenderState(pRenderer, iState);
        SetCachedRenderState(pRenderer, iState, iVal, 0, 0);
        pkRSEntry = pkRSEntry->m_pkNext;
    }
    return 0;
}

struct Group00e7eed0
{
    char _pad0[16];
    Entry00e7ef40* m_pkSaved;
    unsigned int ApplyGroupEntries();
};
// Iterates the group's entry list calling DAT_0126f714->Set with flag 0, then the saved list with flag 1, and returns 0.
// @fnv 0x00e7eed0
unsigned int Group00e7eed0::ApplyGroupEntries()
{
    Entry00e7ef40* entry = *(Entry00e7ef40**)((char*)this + 8);
    while (entry)
    {
        SetCachedRenderState(DAT_0126f714, entry->m_iFadeIndex, entry->m_iPad, 0, 0);
        entry = entry->m_pkNext;
    }
    entry = m_pkSaved;
    while (entry)
    {
        SetCachedRenderState(DAT_0126f714, entry->m_iFadeIndex, entry->m_iPad, 1, 0);
        entry = entry->m_pkNext;
    }
    return 0;
}

struct Helper00b8d460;
Helper00b8d460* SpawnHelper00b8d460();

struct Helper00b8d460
{
    void Init(int a, int b, int c);
};

struct Sub00b8d460
{
    char _pad0[0x30];
    Helper00b8d460* m_pHelper;
};

struct Owner00b8d460
{
    char _pad0[0x5c];
    Sub00b8d460* m_pSub;

    void ImageSpaceShaderVolumetricFog_SetState();
};

// Ensures m_pSub->m_pHelper exists, then initialises it three times with (0x34,1,1), (0x38,3,1) and (0x39,1,1).
// @fnv 0x00b8d460
// src: COMMUNITY 0x00b8d460
void Owner00b8d460::ImageSpaceShaderVolumetricFog_SetState()
{
    Sub00b8d460* pSub = m_pSub;
    if (pSub->m_pHelper == 0)
    {
        pSub->m_pHelper = SpawnHelper00b8d460();
    }
    pSub->m_pHelper->Init(0x34, 1, 1);

    pSub = m_pSub;
    if (pSub->m_pHelper == 0)
    {
        pSub->m_pHelper = SpawnHelper00b8d460();
    }
    pSub->m_pHelper->Init(0x38, 3, 1);

    pSub = m_pSub;
    if (pSub->m_pHelper == 0)
    {
        pSub->m_pHelper = SpawnHelper00b8d460();
    }
    pSub->m_pHelper->Init(0x39, 1, 1);
}

extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
extern "C" char str_010b0158;
extern "C" char str_010b5c70;
extern "C" char str_010b5c64;
extern "C" char str_010a93ec;
extern "C" char str_010a93cc;

struct RenderBuffer
{
    void* typeInfo;
    unsigned int state;
    unsigned int state08;
    unsigned int state0c;
    unsigned int state10;
    unsigned int state14;
    unsigned int state18;
    unsigned int state1c;
    unsigned int state20;
    unsigned int state24;
    unsigned int state28;
    unsigned int state2c;
    unsigned int state30;
    unsigned int state34;
    unsigned int state38;
    unsigned int state3c;
    unsigned int state40;
    unsigned int state44;
    unsigned int state48;
};

struct RenderState
{
    void SetNodeValue(unsigned int state, unsigned int value, unsigned int enabled);
};
extern "C" RenderState* __cdecl FUN_00e7f5d0();

struct GroupState
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    RenderState* state;
};

struct RenderOwner
{
    void** virtualTable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    GroupState* group;
    void ApplyRenderState();
};

typedef void(__thiscall* ApplyState)(RenderOwner*, RenderBuffer*, RenderBuffer*, const void*, const void*, const void*);
typedef void(__thiscall* CommitState)(RenderOwner*);

// Builds two RenderBuffers, applies and commits them via virtual calls, then sets render states 0x1b, 0x13 and 0x14 on the group's state.
// @fnv 0x00b925b0
void RenderOwner::ApplyRenderState()
{
    RenderBuffer currentBuffer;
    currentBuffer.typeInfo = &str_010b0158;
    currentBuffer.state = 0;
    FUN_00ec61c0(&currentBuffer.state08, 0, 0x44);

    RenderBuffer fallbackBuffer;
    fallbackBuffer.typeInfo = &str_010b5c70;
    fallbackBuffer.state = 0;
    FUN_00ec61c0(&fallbackBuffer.state08, 0, 0x44);

    reinterpret_cast<ApplyState>(virtualTable[0x13c / sizeof(void*)])(this, &currentBuffer, &fallbackBuffer,
                                                                      &str_010b5c64, &str_010a93ec, &str_010a93cc);
    reinterpret_cast<CommitState>(virtualTable[0x14c / sizeof(void*)])(this);

    GroupState* stateOwner = group;
    if (!stateOwner->state)
        stateOwner->state = FUN_00e7f5d0();
    stateOwner->state->SetNodeValue(0x1b, 1, 1);

    GroupState* nextOwner = group;
    if (!nextOwner->state)
        nextOwner->state = FUN_00e7f5d0();
    nextOwner->state->SetNodeValue(0x13, 5, 1);

    if (!nextOwner->state)
        nextOwner->state = FUN_00e7f5d0();
    nextOwner->state->SetNodeValue(0x14, 6, 1);
}

struct StateNode
{
    unsigned int key;
    unsigned int value;
    StateNode* prev;
    StateNode* next;
};
extern ObjectPool<StateNode, NiTNewInterface<StateNode> >* DAT_0126f71c;
struct StateGroup
{
    int unk00;
    unsigned int countA;
    StateNode* tailA;
    unsigned int countB;
    StateNode* tailB;
    StateNode* FindNodeByKey(unsigned int, bool&);
    void NiD3DRenderStateGroup_RemoveRSEntryFromSavedList(StateNode*);
    void NiD3DRenderStateGroup_RemoveRSEntryFromNoSaveList(StateNode*);
    void AddA(StateNode* node)
    {
        if (tailA)
        {
            tailA->next = node;
            node->prev = tailA;
        }
        node->next = 0;
        ++countA;
        tailA = node;
    }
    void AddB(StateNode* node)
    {
        if (tailB)
        {
            tailB->next = node;
            node->prev = tailB;
        }
        node->next = 0;
        ++countB;
        tailB = node;
    }
    void SetNodeValue(unsigned int, unsigned int, bool);
};
// @fnv 0x00e7f430
void StateGroup::SetNodeValue(unsigned int key, unsigned int value, bool target)
{
    bool foundType = false;
    StateNode* node = FindNodeByKey(key, foundType);
    if (node)
    {
        bool currentType = foundType;
        node->value = value;
        if (currentType != target)
        {
            if (currentType)
            {
                NiD3DRenderStateGroup_RemoveRSEntryFromSavedList(node);
                AddA(node);
            }
            else
            {
                NiD3DRenderStateGroup_RemoveRSEntryFromNoSaveList(node);
                AddB(node);
            }
        }
    }
    else
    {
        StateNode* fresh = DAT_0126f71c->Get();
        fresh->prev = 0;
        fresh->next = 0;
        fresh->key = key;
        fresh->value = value;
        if (target)
            AddB(fresh);
        else
            AddA(fresh);
    }
}

extern char DAT_011ad832;
struct Holder_b92d20
{
    char pad[0x30];
    RenderState* pState;
    RenderState* Get()
    {
        if (!pState)
            pState = FUN_00e7f5d0();
        return pState;
    }
};
struct B92D20Obj
{
    char pad[0x5c];
    Holder_b92d20* pHolder;
    void ConfigureRenderState();
};
// @fnv 0x00b92d20
void B92D20Obj::ConfigureRenderState()
{
    if (DAT_011ad832)
    {
        pHolder->Get()->SetNodeValue(0x34, 1, 1);
        pHolder->Get()->SetNodeValue(0x38, 3, 1);
        pHolder->Get()->SetNodeValue(0x39, 1, 1);
    }
}

struct StateNodePoolE7F5
{
    void FindOrAdd(StateNode* const& pkNode);
    void ReleaseObject(StateNode* pkNode)
    {
        FindOrAdd(pkNode);
    }
};

struct StateGroupE7F5 : public StateGroup
{
    void RemoveA(StateNode* pkNode)
    {
        StateNode* pkPrev = pkNode->prev;
        StateNode* pkNext = pkNode->next;
        if (pkPrev)
        {
            pkPrev->next = pkNext;
        }
        if (pkNext)
        {
            pkNext->prev = pkPrev;
        }
        if (pkNode == tailA)
        {
            tailA = pkPrev;
        }
        --countA;
        pkNode->prev = 0;
        pkNode->next = 0;
    }
    void RemoveB(StateNode* pkNode)
    {
        StateNode* pkPrev = pkNode->prev;
        StateNode* pkNext = pkNode->next;
        if (pkPrev)
        {
            pkPrev->next = pkNext;
        }
        if (pkNext)
        {
            pkNext->prev = pkPrev;
        }
        if (pkNode == tailB)
        {
            tailB = pkPrev;
        }
        --countB;
        pkNode->prev = 0;
        pkNode->next = 0;
    }
    void RemoveNodeByKey(unsigned int uiKey);
};

// Finds a node by uiKey, removes it from list A or B, and releases it back to the pool.
// @fnv 0x00e7f550
void StateGroupE7F5::RemoveNodeByKey(unsigned int uiKey)
{
    bool bInB = false;
    StateNode* pkNode = FindNodeByKey(uiKey, bInB);
    if (pkNode)
    {
        if (bInB)
        {
            RemoveB(pkNode);
        }
        else
        {
            RemoveA(pkNode);
        }
        reinterpret_cast<StateNodePoolE7F5*>(DAT_0126f71c)->ReleaseObject(pkNode);
    }
}

struct RenderPassB71 : GroupState
{
    void NiD3DPass_SetRenderState(unsigned int stateKey, unsigned int value, int);
};

// Ensures state is initialized via FUN_00e7f5d0, then calls SetNodeValue on state with stateKey, value, and true.
// @fnv 0x00b71a10
// src: COMMUNITY 0x00b71a10
void RenderPassB71::NiD3DPass_SetRenderState(unsigned int stateKey, unsigned int value, int)
{
    if (!state)
        state = FUN_00e7f5d0();
    state->SetNodeValue(stateKey, value, true);
}

struct RenderStateCallB8F160
{
    void SetNodeValue(unsigned int state, unsigned int value, bool save);
};

struct RenderOwnerEntryB8F160 : RenderOwner
{
    void ImageSpaceShaderCopyRenderTarget1_Func_84();
};

// Ensures the group's state object exists, then sets render states 0xA8 to 0 and 0xBE to 0xF with save enabled.
// @fnv 0x00b8f160
// src: COMMUNITY 0x00b8f160
void RenderOwnerEntryB8F160::ImageSpaceShaderCopyRenderTarget1_Func_84()
{
    GroupState* pass = group;
    if (!pass->state)
        pass->state = FUN_00e7f5d0();
    ((RenderStateCallB8F160*)pass->state)->SetNodeValue(0xA8, 0, true);

    pass = group;
    if (!pass->state)
        pass->state = FUN_00e7f5d0();
    ((RenderStateCallB8F160*)pass->state)->SetNodeValue(0xBE, 0xF, true);
}

extern int DAT_011ae680;

// Ensures the owner's group state exists and sets node values 0x34, 0x38, and 0x39 to 1, 4, and DAT_011ae680 respectively.
// @fnv 0x00b8f2f0
// src: GUESS 0x00b8f2f0 (confidence: medium)
void __fastcall Nid3drenderstategroup_SetGroupNodeValues34And38And39(RenderOwner* owner)
{
    GroupState* group = owner->group;
    if (!group->state)
        group->state = FUN_00e7f5d0();
    group->state->SetNodeValue(0x34, 1, true);

    group = owner->group;
    if (!group->state)
        group->state = FUN_00e7f5d0();
    group->state->SetNodeValue(0x38, 4, true);

    group = owner->group;
    int reference = DAT_011ae680;
    if (!group->state)
        group->state = FUN_00e7f5d0();
    group->state->SetNodeValue(0x39, reference, true);
}

// If owner->group->state is null, assigns FUN_00e7f5d0() to it, then sets node values 14, 52, and 56.
// @fnv 0x00b8f4b0
// src: GUESS 0x00b8f4b0 (confidence: medium)
void __fastcall Nid3drenderstategroup_SetGroupNodeValues14And52And56(RenderOwner* owner)
{
    GroupState* group = owner->group;
    if (!group->state)
        group->state = FUN_00e7f5d0();
    group->state->SetNodeValue(14, 0, true);

    group = owner->group;
    if (!group->state)
        group->state = FUN_00e7f5d0();
    group->state->SetNodeValue(52, 1, true);

    group = owner->group;
    if (!group->state)
        group->state = FUN_00e7f5d0();
    group->state->SetNodeValue(56, 3, true);
}
