
// src/havok/unplaced/specificitemcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/specificitemcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __fastcall Object_ForwardCall_0059cee0(void*);
void __cdecl Deallocate(void*);

struct FUN_0062a2f0
{
    void* DeleteThis(unsigned int flags);
};

// Calls FUN_0059cee0 on this, frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0062a2f0
void* FUN_0062a2f0::DeleteThis(unsigned int flags)
{
    Object_ForwardCall_0059cee0(this);
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct S_0062a320_Key
{
    unsigned int m_uiFilterValue;
    S_0062a320_Key(unsigned int v);
    unsigned int CFilter_GetLayer();
    unsigned int CFilter_GetGroup();
};

struct S_0062a320_Node
{
    unsigned int hkpCollidable_getCollisionFilterInfo();
};

struct S_0062a320_Arg
{
    S_0062a320_Node* GetLastNode();
};

struct S_0062a320_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
};

struct S_0062a320
{
    char pad[0x70];
    S_0062a320_Key unk70;
    float unk74;
    void SpecificItemCollector_addRayHit(S_0062a320_Arg* arg, S_0062a320_Data* data);
    void hkpClosestRayHitCollector_addRayHit(S_0062a320_Arg* arg, S_0062a320_Data* data);
};

// @fnv 0x0062a320
// src: XBOX_PDB 0x0062a320
void S_0062a320::SpecificItemCollector_addRayHit(S_0062a320_Arg* arg, S_0062a320_Data* data)
{
    S_0062a320_Node* node = arg->GetLastNode();
    if (node)
    {
        S_0062a320_Key nodeKey(node->hkpCollidable_getCollisionFilterInfo());
        if (nodeKey.CFilter_GetLayer() != unk70.CFilter_GetLayer() || nodeKey.CFilter_GetGroup() == unk70.CFilter_GetGroup())
        {
            if (unk74 <= data->unk10)
            {
                hkpClosestRayHitCollector_addRayHit(arg, data);
            }
        }
    }
}
