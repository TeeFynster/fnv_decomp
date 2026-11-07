#include "../../../include/BGSTerrainChunkLoadTask.h"
#include "../../../include/NiGeometry.h"
#include "../../../include/NiGeometryData.h"
#include "../../../include/QueuedFile.h"
#include "../../../include/QueuedFileEntry.h"
#include "../../../include/Setting.h"

// Context variant for the terrain chunk load task.
struct AutoMemX
{
    int m;
    AutoMemX(int a, int b, const char* f, int l);
    ~AutoMemX();
};
struct Q28
{
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9();
    virtual struct TaskX* F28();
};
struct TaskX
{
    int GetFlagOrValue();
};
struct Obj18
{
    virtual void v0(), v1(), v2(), v3(), v4(), v5();
    virtual void* F18();
};
struct NodeX
{
    unsigned NiNode_GetChildCount();
    Obj18* FUN_0043b4a0(unsigned i);
};
struct RootX
{
    virtual void v0(), v1(), v2();
    virtual int Fc();
};
struct PN
{
    void* p;
    NodeX* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(void* q);
};
struct PQ
{
    void* p;
    Q28* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(void* q);
};
struct PV
{
    void* p;
    void FUN_0066b0d0(void* q);
};
struct StreamX
{
    char buf[0x5cc];
    StreamX();
    ~StreamX();
    bool BSStream_Load(int f);
    RootX* GetStringAt(unsigned i);
    unsigned GetRefAt21C();
};
extern Setting g_kTerrainChunkSetting;

// @fnv 0x006fbd00
void BGSTerrainChunkLoadTask::Run()
{
    AutoMemX kMemVal(
        0x23, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSTerrainChunk.cpp",
        0x298);
    BSFile* iFile = GetFile(0, 1);
    StreamX kStreamVal;
    // Preserve the original call's extra file argument and integer result ABI.
    if (kStreamVal.BSStream_Load(
            (this->*reinterpret_cast<int (QueuedFileEntry::*)(BSFile*)>(&QueuedFileEntry::GetFileName))(iFile)))
    {
        RootX* pkRoot = kStreamVal.GetStringAt(0);
        if (pkRoot->Fc())
        {
            reinterpret_cast<PN&>(unk54).FUN_0066b0d0(kStreamVal.GetStringAt(0));
            reinterpret_cast<PV&>(unk48).FUN_0066b0d0(
                reinterpret_cast<PN&>(unk54).Modelloader_GetReferencedThis()->FUN_0043b4a0(0));
            if (reinterpret_cast<PN&>(unk54).Modelloader_GetReferencedThis()->NiNode_GetChildCount() > 1 && *g_kTerrainChunkSetting.Bool())
            {
                reinterpret_cast<PQ&>(unk4c).FUN_0066b0d0(
                    reinterpret_cast<PN&>(unk54).Modelloader_GetReferencedThis()->FUN_0043b4a0(1)->F18());
                if (reinterpret_cast<PQ&>(unk4c).Modelloader_GetReferencedThis()->F28() &&
                    reinterpret_cast<PQ&>(unk4c).Modelloader_GetReferencedThis()->F28()->GetFlagOrValue() == 3)
                    reinterpret_cast<PQ&>(unk4c).FUN_0066b0d0(0);
            }
            if (reinterpret_cast<PN&>(unk54).Modelloader_GetReferencedThis()->NiNode_GetChildCount() > 2 && *g_kTerrainChunkSetting.Bool())
                reinterpret_cast<PV&>(unk50).FUN_0066b0d0(
                    reinterpret_cast<PN&>(unk54).Modelloader_GetReferencedThis()->FUN_0043b4a0(2)->F18());
        }
        else
        {
            reinterpret_cast<PV&>(unk48).FUN_0066b0d0(kStreamVal.GetStringAt(0));
            if (kStreamVal.GetRefAt21C() > 1)
                reinterpret_cast<PQ&>(unk4c).FUN_0066b0d0(kStreamVal.GetStringAt(1));
        }
    }
}
