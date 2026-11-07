
// src/fallout_shared/pathfinding/pathsmoother.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathsmoother.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_006ed4e0_shell
{
    void ForwardCall_006ed510();
    void* DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_006ed510, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x006ed4e0
void* FUN_006ed4e0_shell::DestroyIfFlagged(unsigned int flags)
{
    ForwardCall_006ed510();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_006f25d0_shell
{
    void __thiscall FUN_006f25d0();
};

struct FUN_006ed510_shell
{
    void __thiscall ForwardCall_006ed510();
};

// @fnv 0x006ed510
// src: GUESS 0x006ed510 (confidence: low)
void __thiscall FUN_006ed510_shell::ForwardCall_006ed510()
{
    ((FUN_006f25d0_shell*)((char*)this + 0x2c))->FUN_006f25d0();
}

struct GlobalObject_00869f00
{
    virtual ~GlobalObject_00869f00();
    void Clear(bool);
};
struct FUN_006f25b0 : GlobalObject_00869f00
{
    ~FUN_006f25b0();
};
struct FUN_006f25d0 : FUN_006f25b0
{
    ~FUN_006f25d0();
};
// Destructor that calls Clear(true) on the global object.
// @fnv 0x006f25d0
FUN_006f25d0::~FUN_006f25d0()
{
    Clear(true);
}

struct PooledEntry
{
    void* DestroyIfFlagged(unsigned int uiFlags);
};

struct EntryPool
{
    int unk00, unk04, unk08, unk0c;
    ~EntryPool();
    void ScrapHeap_Deallocate(void* pvEntry);
};

struct EntryArrayBase
{
    void* m_vtbl;
    int unk04, unk08, unk0c, unk10;
    unsigned int FUN_0044ddc0();
    PooledEntry*& FUN_00877a30(unsigned int uiIndex);
    void FUN_008454f0(bool bFree);
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
    void BSSimpleArray_Actor_1024_RemoveFast(int a1, int a2);
};

struct EntryArrayA : EntryArrayBase
{
    ~EntryArrayA();
};
struct EntryArrayB : EntryArrayBase
{
    ~EntryArrayB();
};
struct EntryArrayC : EntryArrayBase
{
    ~EntryArrayC();
};
struct EntryTable
{
    int unk00;
    ~EntryTable();
};

struct FUN_006ed220
{
    char pad00[0x30];
    EntryPool m_kEntryPool;
    EntryArrayA m_kActive;
    EntryArrayA m_kPending;
    EntryArrayB m_kFreeA;
    EntryArrayB m_kFreeB;
    EntryArrayC m_kFreeC;
    EntryTable m_kTable;

    ~FUN_006ed220();
};

// @fnv 0x006ed220
FUN_006ed220::~FUN_006ed220()
{
    for (unsigned int i = 0; i < m_kActive.FUN_0044ddc0(); i++)
    {
        m_kActive.FUN_00877a30(i)->DestroyIfFlagged(0);
        m_kEntryPool.ScrapHeap_Deallocate(m_kActive.FUN_00877a30(i));
    }
    if (!m_kPending.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        m_kPending.BSSimpleArray_Actor_1024_RemoveFast(0, 1);
    if (!m_kPending.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        m_kPending.BSSimpleArray_Actor_1024_RemoveFast(0, 1);
    for (unsigned int j = 0; j < m_kPending.FUN_0044ddc0(); j++)
    {
        m_kPending.FUN_00877a30(j)->DestroyIfFlagged(0);
        m_kEntryPool.ScrapHeap_Deallocate(m_kPending.FUN_00877a30(j));
    }
    m_kActive.FUN_008454f0(true);
    m_kPending.FUN_008454f0(true);
    for (unsigned int k = 0; k < m_kFreeA.FUN_0044ddc0(); k++)
        m_kEntryPool.ScrapHeap_Deallocate(m_kFreeA.FUN_00877a30(k));
    for (unsigned int l = 0; l < m_kFreeB.FUN_0044ddc0(); l++)
        m_kEntryPool.ScrapHeap_Deallocate(m_kFreeB.FUN_00877a30(l));
    m_kFreeA.FUN_008454f0(true);
    m_kFreeB.FUN_008454f0(true);
    for (unsigned int m = 0; m < m_kFreeC.FUN_0044ddc0(); m++)
        m_kEntryPool.ScrapHeap_Deallocate(m_kFreeC.FUN_00877a30(m));
    m_kFreeC.FUN_008454f0(true);
}

struct Triple
{
    int unk00;
    int unk04;
    int unk08;
};

struct SubSlot
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    void BSSimpleArray_TESObjectREFR_1024_SetReservedSize(unsigned int aCount);
    void FUN_008454f0(unsigned int aCount);
};

struct ArgObj
{
    unsigned int FUN_0044ddc0();
    void* GetIndexedValue_006b3160(unsigned int aIndex);
};

struct Holder
{
    void* GetNavMeshInfo_0068efb0();
};

struct NodeA
{
    float GetFloatAtOffset68();
};

struct Gate
{
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
};

struct FUN_006ed530_cls
{
    Gate* m_00;
    NodeA* m_04;
    Triple m_08;
    Triple m_14;
    int m_20;
    int m_24;
    int m_28;
    float m_2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    SubSlot m_40;
    SubSlot m_54;
    SubSlot m_68;
    SubSlot m_7c;
    SubSlot m_90;

    void BuildInternalArrays();
    void PathSmoother_BuildShrunkEdgeLeftRightArrays();
    bool CheckEdges();
    void CopyNodePositions();
    void PathSmoother_ComputeCenters();
    void SmoothNodes();
    void FlattenPathPoints();
    void BuildLocations();
    void ClipPathAgainstObstacles();
    void AppendSegments(int aA, int aB);
    void SmoothPathDirections();
    void PathSmoother_AddPathingNode(Triple* apSrc, void* apRes);
    bool PathSmoother_SmoothPath(NodeA* a1, ArgObj* a2, ArgObj* a3, Triple* a4, Triple* a5, int a6, Gate* a7, unsigned char a8);
};

// @fnv 0x006ed530
// src: COMMUNITY 0x006ed530
bool FUN_006ed530_cls::PathSmoother_SmoothPath(NodeA* apNode, ArgObj* apArgObj, ArgObj* apArgObj2, Triple* apTripleA,
                                    Triple* apTripleB, int aiValue, Gate* apGate, unsigned char abForce)
{
    bool bResult;

    m_04 = apNode;
    m_08 = *apTripleA;
    m_14 = *apTripleB;
    m_20 = (int)apArgObj;
    m_24 = (int)apArgObj2;
    m_28 = aiValue;
    m_00 = apGate;
    m_2c = m_04->GetFloatAtOffset68();

    if (apArgObj->FUN_0044ddc0() == 1)
    {
        PathSmoother_AddPathingNode(apTripleA, (*(Holder**)apArgObj->GetIndexedValue_006b3160(0))->GetNavMeshInfo_0068efb0());
        PathSmoother_AddPathingNode(apTripleB, (*(Holder**)apArgObj->GetIndexedValue_006b3160(0))->GetNavMeshInfo_0068efb0());
        return true;
    }

    m_40.BSSimpleArray_TESObjectREFR_1024_SetReservedSize(apArgObj2->FUN_0044ddc0() << 1);
    m_54.BSSimpleArray_TESObjectREFR_1024_SetReservedSize(apArgObj2->FUN_0044ddc0() << 1);
    m_68.BSSimpleArray_TESObjectREFR_1024_SetReservedSize(apArgObj2->FUN_0044ddc0() << 1);
    m_7c.BSSimpleArray_TESObjectREFR_1024_SetReservedSize(apArgObj2->FUN_0044ddc0() << 1);
    m_90.BSSimpleArray_TESObjectREFR_1024_SetReservedSize(apArgObj2->FUN_0044ddc0() << 1);

    m_40.FUN_008454f0(0);
    m_54.FUN_008454f0(0);
    m_68.FUN_008454f0(0);
    m_7c.FUN_008454f0(0);
    m_90.FUN_008454f0(0);

    BuildInternalArrays();
    PathSmoother_BuildShrunkEdgeLeftRightArrays();
    bResult = CheckEdges();
    CopyNodePositions();
    PathSmoother_ComputeCenters();
    SmoothNodes();
    FlattenPathPoints();
    BuildLocations();
    ClipPathAgainstObstacles();

    if (abForce != 0 || apGate->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        AppendSegments(1, 1);
        SmoothPathDirections();
    }
    return bResult;
}
