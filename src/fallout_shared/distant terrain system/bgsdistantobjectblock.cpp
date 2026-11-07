#include "../../../include/MEM_CONTEXT.h"
#include "../../../include/TileWorkList.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/BSStream.h"
#include "../../../include/BSFaceGenNiNode.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESWorldSpace.h"
#include "../../../include/BGSDistantObjectBlockLoadTask.h"


// src/fallout_shared/distant terrain system/bgsdistantobjectblock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsdistantobjectblock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* object);



// Formats a NIF path into apOutput from the world's high-priority stinger block file name, level and cell coordinates.
// @fnv 0x006f5730
void __cdecl FormatStingerBlockPath(char* apOutput, TESWorldSpace* apWorld, int aiLevel, short asCellX, short asCellY)
{
    _sprintf_s(apOutput, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\Stinger\\%s.Level%i.High.X%i.Y%i.NIF",
               apWorld->GetName(), apWorld->GetName(), aiLevel,
               asCellX, asCellY);
}

struct FUN_006f6070_shell
{
    unsigned char GetByteAtOffset35();
};

// @fnv 0x006f6070
unsigned char FUN_006f6070_shell::GetByteAtOffset35()
{
    return ((unsigned char*)this)[0x23];
}

struct FUN_006f6520_shell
{
    char GetByteAtOffset();
};

// @fnv 0x006f6520
char FUN_006f6520_shell::GetByteAtOffset()
{
    return ((char*)this)[0xdf2];
}

extern void __cdecl _Deallocate(void*);

// Destroys the task, deallocates it if flags has bit 0 set, and returns this.
// @fnv 0x006f6fb0
void* BGSDistantObjectBlockLoadTask::FUN_006f6fb0(unsigned int flags)
{
    this->BGSDistantObjectBlockLoadTask::~BGSDistantObjectBlockLoadTask();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// If the byte at offset 0x50 is unset, sets it to 1 and calls FUN_00c3cb70 with the task state and owner; otherwise does nothing.
// @fnv 0x006f71a0
void BGSDistantObjectBlockLoadTask::RunOnce(void* apTaskState, void* apTaskOwner)
{
    if (m_bLoadComplete)
    {
    }
    else
    {
        m_bLoadComplete = 1;
        this->QueuedFile_Cancel(apTaskState, apTaskOwner);
    }
}

struct FUN_006f73b0_shell
{
    void SetFlag();
};

// @fnv 0x006f73b0
void FUN_006f73b0_shell::SetFlag()
{
    ((char*)this)[0x24] = 1;
}

// Formats a landscape LOD block NIF path from the worldspace's stinger block file name, level and cell coordinates into apOutput.
// @fnv 0x006f55f0
void FormatLODBlockFileName(char* apOutput, TESWorldSpace* apWorld, int aiLevel, short asCellX, short asCellY)
{
    _sprintf_s(apOutput, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\Blocks\\%s.Level%i.X%i.Y%i.NIF",
               apWorld->GetName(), apWorld->GetName(), aiLevel,
               asCellX, asCellY);
}

// Formats a landscape LOD block NIF path from the worldspace's stinger block file name, level, and cell coordinates into apOutput.
// @fnv 0x006f5640
void __cdecl BuildLODBlockFilePath(char* apOutput, TESWorldSpace* apWorld, int aiLevel, short asCellX, short asCellY)
{
    _sprintf_s(apOutput, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\Blocks\\%s.Level%i.High.X%i.Y%i.NIF",
               apWorld->GetName(), apWorld->GetName(), aiLevel,
               asCellX, asCellY);
}

// Formats a landscape LOD block NIF path into apOutput from the worldspace's stinger block file name, level, and cell coordinates.
// @fnv 0x006f5690
void __cdecl BuildLODBlockFileName(char* apOutput, TESWorldSpace* apWorld, int aiLevel, short asCellX, short asCellY)
{
    _sprintf_s(apOutput, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\Blocks\\%s.Level%i.X%i.Y%i.PostApocalypse.NIF",
               apWorld->GetName(), apWorld->GetName(), aiLevel,
               asCellX, asCellY);
}

// @fnv 0x006f57c0
// src: XBOX_PDB 0x006f57c0
void __cdecl BGSDistantObjectBlock_BuildBlockNormalTextureFileName(char* apOutput, TESWorldSpace* apWorld)
{
    _sprintf_s(apOutput, 0x104, "Data\\Textures\\Landscape\\LOD\\%s\\Blocks\\%s.Buildings_n.dds",
               apWorld->GetName(), apWorld->GetName());
}

struct Flt
{
    operator unsigned int();
};

struct FUN_006f5800_shell
{
    unsigned int __thiscall GetSelectedValue(bool abFlag);
};

// Returns the value at offset 0x10 when abFlag is set, otherwise the value at offset 8.
// @fnv 0x006f5800
unsigned int __thiscall FUN_006f5800_shell::GetSelectedValue(bool abFlag)
{
    Flt* pFlt = abFlag ? (Flt*)((char*)this + 0x10) : (Flt*)((char*)this + 8);
    return *pFlt;
}

// placeholder declarations

struct Model
{
    NiNode* GetObject3D(void);
};
struct FUN_00528820_shell
{
    void ClearField(void);
};


struct GlobalObject2_0096a2d0
{
    TESObjectCELL** __thiscall _ref_006815c0();
    GlobalObject2_0096a2d0* __thiscall _ref_00726070();
};
extern GlobalObject2_0096a2d0 g_011d8524;

// @fnv 0x006f5840
// src: COMMUNITY 0x006f5840
void __cdecl BGSDistantObjectBlock_ResetCullResults(void)
{
    GlobalObject2_0096a2d0* pEntry = &g_011d8524;
    while (pEntry)
    {
        TESObjectCELL* cell = *pEntry->_ref_006815c0();
        if (cell && !cell->GetField24())
        {
            NiNode* obj = cell->GetSelectedValue(0);
            if (obj)
            {
                ((FUN_00528820_shell*)((Model*)((BSFaceGenNiNode*)obj)->BSFaceGenNiNode::GetAnimationData())->GetObject3D())->ClearField();
            }
            obj = cell->GetSelectedValue(1);
            if (obj)
            {
                ((FUN_00528820_shell*)((Model*)((BSFaceGenNiNode*)obj)->BSFaceGenNiNode::GetAnimationData())->GetObject3D())->ClearField();
            }
        }
        pEntry = pEntry->_ref_00726070();
    }
}

namespace fnv_006f6090 {
struct SoundListView
{
    void __thiscall AddTail(char* const&);
};

struct GlobalObject2_0096a2d0
{
    void __thiscall AddTail(char* const&);
};

extern GlobalObject2_0096a2d0 g_011d8524;

struct FUN_006f6090_shell
{
    void AddSelfToGlobalList();
};

// Adds the this pointer to the global list g_011d8524.
// @fnv 0x006f6090
void FUN_006f6090_shell::AddSelfToGlobalList()
{
    char* p = (char*)this;
    g_011d8524.AddTail(p);
}
}  // namespace fnv_006f6090

// Formats a landscape LOD stinger NIF path from the worldspace's stinger block file name, level and cell coordinates into apOutput.
// @fnv 0x006f56e0
void BuildStingerNifPath(char* apOutput, TESWorldSpace* apWorld, int aiLevel, short asCellX, short asCellY)
{
    _sprintf_s(apOutput, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\Stinger\\%s.Level%i.X%i.Y%i.NIF",
               apWorld->GetName(), apWorld->GetName(), aiLevel,
               asCellX, asCellY);
}

// Formats a DDS path for the worldspace's high-priority stinger block buildings LOD texture into apOutput.
// @fnv 0x006f5780
void __cdecl FormatBuildingsLODTexturePath(char* apOutput, TESWorldSpace* apWorld)
{
    _sprintf_s(apOutput, 0x104, "Data\\Textures\\Landscape\\LOD\\%s\\Blocks\\%s.Buildings.dds",
               apWorld->GetName(), apWorld->GetName());
}

struct FUN_006f60c0_shell
{
    bool IsInCellList();
    void RunLoop();
};
struct _Ref905330_shell
{
    void _ref_00905330(FUN_006f60c0_shell* const&);
};
// Repeatedly calls IsInCellList and, while it returns true, passes this to _ref_00905330 via g_011d8524.
// @fnv 0x006f60c0
void FUN_006f60c0_shell::RunLoop()
{
    while (IsInCellList())
    {
        ((_Ref905330_shell*)&g_011d8524)->_ref_00905330(this);
    }
}

struct FUN_006f6100_shell
{
    bool __thiscall IsInCellList();
};
// Walks the g_011d8524 list and returns true if this object is found among the cells it references.
// @fnv 0x006f6100
bool __thiscall FUN_006f6100_shell::IsInCellList()
{
    GlobalObject2_0096a2d0* iter = &g_011d8524;
    while (iter)
    {
        TESObjectCELL* cell = *iter->_ref_006815c0();
        if (cell && (FUN_006f6100_shell*)cell == this)
            return true;
        iter = iter->_ref_00726070();
    }
    return false;
}

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

// Formats the block's X, Y and level into apDescription with _sprintf_s and returns true.
// @fnv 0x006f74b0
bool BGSDistantObjectBlockLoadTask::GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    _sprintf_s(apDescription, aiBufferSize, "Object LOD Task for block ( %i, %i ) at level ( %i )", iX, iY, iLevel);
    return true;
}

struct LodObject;

struct LodNode
{
    unsigned int GetArrayCount();
    LodObject* GetAt(unsigned int i);
};

struct LodObject
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual LodNode* IsSceneNode();
    void SetAppCulled(bool bAppCulled);
};

// Recursively sets the app-culled flag on obj and all child LodObjects to the inverse of bShow.
// @fnv 0x006f58e0
void __cdecl SetObjectVisible(LodObject* obj, bool bShow)
{
    if (obj)
        obj->SetAppCulled(!bShow);
    if (obj->IsSceneNode())
    {
        LodNode* node = obj->IsSceneNode();
        for (unsigned int i = 0; i < node->GetArrayCount(); i++)
            SetObjectVisible(node->GetAt(i), bShow);
    }
}

namespace fnv_006f5970 {
struct LodPoint3
{
    float x;
    float y;
    float z;
};

struct LodCell
{
    unsigned char PathingRequestCover_GetSortDistanceFromTarget();
};

struct LodWorld
{
    LodCell* GetCellFromWorldCoord(const LodPoint3& pos);
};

struct LodTES
{
    LodWorld* FUN_004fd3e0();
    bool FUN_004511e0(LodCell* cell, int unk);
};
extern LodTES* g_LodTES;

struct LodObject;

struct LodNode
{
    unsigned int GetArrayCount();
    LodObject* GetAt(unsigned int i);
};

struct LodObject
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual LodNode* IsSceneNode();
    const LodPoint3& GetWorldTranslate();
};

void __cdecl SetObjectVisible(LodObject* obj, int flag);

struct LodVisitor
{
    void UpdateLodVisibility(LodObject* obj, int a, unsigned short b, unsigned short c);
};

// Recursively walks the object's children, or for a leaf finds the cell at its world position and sets its visibility flag based on the cell check.
// @fnv 0x006f5970
void LodVisitor::UpdateLodVisibility(LodObject* obj, int a, unsigned short b, unsigned short c)
{
    if (obj->IsSceneNode())
    {
        LodNode* node = obj->IsSceneNode();
        for (unsigned int i = 0; i < node->GetArrayCount(); i++)
        {
            LodObject* child = node->GetAt(i);
            if (child)
                UpdateLodVisibility(child, a, b, c);
        }
    }
    else
    {
        LodPoint3 pos = obj->GetWorldTranslate();
        LodCell* cell = g_LodTES->FUN_004fd3e0()->GetCellFromWorldCoord(pos);
        if (g_LodTES->FUN_004511e0(cell, 1) && cell->PathingRequestCover_GetSortDistanceFromTarget())
            SetObjectVisible(obj, 0);
        else
            SetObjectVisible(obj, 1);
    }
}
}  // namespace fnv_006f5970

struct SceneNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual TileWorkList* GetChildren();

    void FUN_00450f90(int aiFlag);
};

struct NodeVisitor
{
    void VisitNodeTree(SceneNode* apNode);
};

// @fnv 0x006f5a70
void NodeVisitor::VisitNodeTree(SceneNode* apNode)
{
    if (apNode != 0)
        apNode->FUN_00450f90(0);

    if (apNode->GetChildren() != 0)
    {
        TileWorkList* pList = apNode->GetChildren();
        for (unsigned int uiIndex = 0; uiIndex < pList->NiNode_GetChildCount(); uiIndex++)
            VisitNodeTree(pList->NiNode_GetAtChecked(uiIndex));
    }
}

struct Scene
{
};
struct Node
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual void method52();
    virtual void method53();
    virtual void method54();
    virtual void method55();
    virtual void method56();
    virtual void method57();
    virtual void Detach(Scene*);
};
struct Parent
{
    Node* BGSTerrainManager_GetLODObjectRoot();
};
struct ParentRef
{
    Parent* value;
    Parent* Modelloader_GetReferencedThis();
};
struct SceneRef
{
    Scene* value;
    Scene* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(Scene*);
};
struct TaskRef
{
    void* value;
    void AssignTaskReference(void*);
};
extern int DAT_011d8510;
struct Block
{
    ParentRef* parent;
    SceneRef first, second, third, fourth, fifth;
    TaskRef mainTask, secondaryTask;
    int unk20;
    bool active;
    void RunLoop();
    void BGSDistantObjectBlock_Detach();
};
// Calls RunLoop, decrements DAT_011d8510 if scenes are set, detaches them from the parent node, clears the scene and task refs, and sets active to false.
// @fnv 0x006f5af0
// src: COMMUNITY 0x006f5af0
void Block::BGSDistantObjectBlock_Detach()
{
    RunLoop();
    if (second.Modelloader_GetReferencedThis() || first.Modelloader_GetReferencedThis() || fourth.Modelloader_GetReferencedThis())
        --DAT_011d8510;
    if (second.Modelloader_GetReferencedThis() || first.Modelloader_GetReferencedThis())
    {
        parent->Modelloader_GetReferencedThis()->BGSTerrainManager_GetLODObjectRoot()->Detach(second.Modelloader_GetReferencedThis());
        parent->Modelloader_GetReferencedThis()->BGSTerrainManager_GetLODObjectRoot()->Detach(first.Modelloader_GetReferencedThis());
        parent->Modelloader_GetReferencedThis()->BGSTerrainManager_GetLODObjectRoot()->Detach(third.Modelloader_GetReferencedThis());
        second.FUN_0066b0d0(0);
        first.FUN_0066b0d0(0);
        third.FUN_0066b0d0(0);
        mainTask.AssignTaskReference(0);
    }
    if (fourth.Modelloader_GetReferencedThis())
    {
        parent->Modelloader_GetReferencedThis()->BGSTerrainManager_GetLODObjectRoot()->Detach(fourth.Modelloader_GetReferencedThis());
        fourth.FUN_0066b0d0(0);
        fifth.FUN_0066b0d0(0);
        secondaryTask.AssignTaskReference(0);
    }
    active = false;
}

struct TargetObject
{
    bool BSTask_int64_GetTaskFinished();
    void AssignValue(void* destination);
    void BGSDistantObjectBlockLoadTask_GetWaterGeometry(void* destination);
};
struct SmartRef
{
    void* value;
    TargetObject* Modelloader_GetReferencedThis();
    void AssignTaskReference(int value);
};
struct Owner
{
    int unk00;
    void* firstDestination;
    void* secondDestination;
    int unk0c;
    void* thirdDestination;
    int unk14;
    SmartRef firstReference;
    SmartRef secondReference;
    bool completed;
    void UpdateReferences(bool update);
};
// @fnv 0x006f6150
void Owner::UpdateReferences(bool update)
{
    if (firstReference.Modelloader_GetReferencedThis() != 0)
    {
        if (firstReference.Modelloader_GetReferencedThis()->BSTask_int64_GetTaskFinished())
        {
            if (update)
            {
                firstReference.Modelloader_GetReferencedThis()->AssignValue(&firstDestination);
                firstReference.Modelloader_GetReferencedThis()->BGSDistantObjectBlockLoadTask_GetWaterGeometry(&secondDestination);
            }
            firstReference.AssignTaskReference(0);
            if (secondReference.Modelloader_GetReferencedThis() == 0)
                completed = true;
        }
    }
    if (secondReference.Modelloader_GetReferencedThis() != 0)
    {
        if (secondReference.Modelloader_GetReferencedThis()->BSTask_int64_GetTaskFinished())
        {
            if (update)
                secondReference.Modelloader_GetReferencedThis()->BGSDistantObjectBlockLoadTask_GetWaterGeometry(&thirdDestination);
            secondReference.AssignTaskReference(0);
            if (firstReference.Modelloader_GetReferencedThis() == 0)
                completed = true;
        }
    }
}

// Clears the loaded node references before destroying the queued file entry.
// @fnv 0x006f6fe0
BGSDistantObjectBlockLoadTask::~BGSDistantObjectBlockLoadTask()
{
    m_spNode = 0;
    m_spLand = 0;
}

namespace fnv_006f71e0 {

struct Node
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Node* AsNode();
    Node* NiNode_GetAtChecked(unsigned int);
};

int __cdecl FUN_00456a20(const char*, int, int, int);
struct BlockTask
{
    unsigned char GetByteAtOffset35();
    void SetFlag();
};
}  // namespace fnv_006f71e0

// Preserve the original stack protection for the stream object.
#pragma strict_gs_check(on)
// @fnv 0x006f71e0
void BGSDistantObjectBlockLoadTask::LoadDistantObjectBlock()
{
    AutoMemContext mode(
        (MEM_CONTEXT)MEM_CONTEXT_MEM_CONTEXT_LODBUILDINGS, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSDistantObjectBlock.cpp",
        922);
    int memory = (int)GetFile(0, 1);
    int canLoad = 1;
    if (memory == 0 && !fnv_006f71e0::FUN_00456a20(GetFileName(), 0, 6, 1))
        canLoad = 0;
    BSStream stream;
    // Preserve the recovered call's extra argument without duplicating QueuedFileEntry.
    if (canLoad && stream.BSStream_Load(
            (this->*reinterpret_cast<char* (QueuedFileEntry::*)(int)>(&QueuedFileEntry::GetFileName))(memory)))
    {
        fnv_006f71e0::Node* node = (fnv_006f71e0::Node*)stream.GetStringAt(0);
        if (node->AsNode())
        {
            m_spLand = (NiAVObject*)stream.GetStringAt(0);
            m_spNode = (NiAVObject*)((fnv_006f71e0::Node*)(NiAVObject*)m_spLand)->NiNode_GetAtChecked(0);
        }
        else
        {
            m_spNode = (NiAVObject*)stream.GetStringAt(0);
        }
    }
    else
    {
        if (((fnv_006f71e0::BlockTask*)m_pParent)->GetByteAtOffset35())
            ((fnv_006f71e0::BlockTask*)m_pParent)->SetFlag();
    }
}
#pragma strict_gs_check(off)


struct VObj
{
    virtual void V00()
    {}
    virtual void V01()
    {}
    virtual void V02()
    {}
    virtual void V03()
    {}
    virtual void V04()
    {}
    virtual void V05()
    {}
    virtual void V06()
    {}
    virtual void V07()
    {}
    virtual void V08()
    {}
    virtual void V09()
    {}
    virtual void V10()
    {}
    virtual void V11()
    {}
    virtual void V12()
    {}
    virtual void V13()
    {}
    virtual void V14()
    {}
    virtual void V15()
    {}
    virtual void V16()
    {}
    virtual void V17()
    {}
    virtual void V18()
    {}
    virtual void V19()
    {}
    virtual void V20()
    {}
    virtual void V21()
    {}
    virtual void V22()
    {}
    virtual void V23()
    {}
    virtual void V24()
    {}
    virtual void V25()
    {}
    virtual void V26()
    {}
    virtual void V27()
    {}
    virtual void V28()
    {}
    virtual void V29()
    {}
    virtual void V30()
    {}
    virtual void V31()
    {}
    virtual void V32()
    {}
    virtual void V33()
    {}
    virtual void V34()
    {}
    virtual void V35()
    {}
    virtual void V36()
    {}
    virtual void V37()
    {}
    virtual void V38()
    {}
    virtual void V39()
    {}
    virtual void V40()
    {}
    virtual void V41()
    {}
    virtual void V42()
    {}
    virtual void V43()
    {}
    virtual void V44()
    {}
    virtual void V45()
    {}
    virtual void V46()
    {}
    virtual void V47()
    {}
    virtual void V48()
    {}
    virtual void V49()
    {}
    virtual void V50()
    {}
    virtual void V51()
    {}
    virtual void V52()
    {}
    virtual void V53()
    {}
    virtual void V54()
    {}
    virtual void V55(void* p, int b)
    {}
    virtual void V56()
    {}
    virtual void V57()
    {}
    virtual void V58(void* p)
    {}
};

struct C_00559450
{
    C_00559450* Modelloader_GetReferencedThis();
};
struct C_004ea9c0
{
    VObj* BGSTerrainManager_GetLODObjectRoot();
};
struct C_009611e0
{
    void* NiAVObject_GetParent();
};
struct C_0066b0d0
{
    void FUN_0066b0d0(unsigned int v);
};
struct C_006f6090
{
    void AddSelfToGlobalList();
};
struct C_006f66e0
{
    void UpdateMenuNodes();
};

extern int DAT_011d8510;
extern int DAT_011d8514;

struct FUN_006f5ca0_cls
{
    unsigned int unk00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned char unk20;
    unsigned char m_21;
    void BGSDistantObjectBlock_Attach();
};

// @fnv 0x006f5ca0
// src: COMMUNITY 0x006f5ca0
void FUN_006f5ca0_cls::BGSDistantObjectBlock_Attach()
{
    if (((C_00559450*)&m_04)->Modelloader_GetReferencedThis() == 0 && ((C_00559450*)&m_10)->Modelloader_GetReferencedThis() == 0)
        return;
    if (m_21 == 0)
    {
        ((FUN_006f60c0_shell*)this)->RunLoop();
        if (((C_00559450*)&m_0c)->Modelloader_GetReferencedThis() != 0)
        {
            if (((C_00559450*)&m_08)->Modelloader_GetReferencedThis() != 0)
            {
                ((C_004ea9c0*)((C_00559450*)this)->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis())
                    ->BGSTerrainManager_GetLODObjectRoot()
                    ->V58(((C_009611e0*)((C_00559450*)&m_0c)->Modelloader_GetReferencedThis())->NiAVObject_GetParent());
                ((C_004ea9c0*)((C_00559450*)this)->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis())
                    ->BGSTerrainManager_GetLODObjectRoot()
                    ->V55(((C_00559450*)&m_08)->Modelloader_GetReferencedThis(), 1);
            }
            else
            {
                ((C_004ea9c0*)((C_00559450*)this)->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis())
                    ->BGSTerrainManager_GetLODObjectRoot()
                    ->V58(((C_00559450*)&m_0c)->Modelloader_GetReferencedThis());
                ((C_004ea9c0*)((C_00559450*)this)->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis())
                    ->BGSTerrainManager_GetLODObjectRoot()
                    ->V55(((C_00559450*)&m_04)->Modelloader_GetReferencedThis(), 1);
            }
        }
        else
        {
            if (((C_00559450*)&m_08)->Modelloader_GetReferencedThis() != 0)
                ((C_004ea9c0*)((C_00559450*)this)->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis())
                    ->BGSTerrainManager_GetLODObjectRoot()
                    ->V55(((C_00559450*)&m_08)->Modelloader_GetReferencedThis(), 1);
            else if (((C_00559450*)&m_04)->Modelloader_GetReferencedThis() != 0)
                ((C_004ea9c0*)((C_00559450*)this)->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis())
                    ->BGSTerrainManager_GetLODObjectRoot()
                    ->V55(((C_00559450*)&m_04)->Modelloader_GetReferencedThis(), 1);
        }
        if (((C_00559450*)&m_14)->Modelloader_GetReferencedThis() != 0)
        {
            if (((C_00559450*)&m_10)->Modelloader_GetReferencedThis() != 0)
            {
                ((C_004ea9c0*)((C_00559450*)this)->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis())
                    ->BGSTerrainManager_GetLODObjectRoot()
                    ->V58(((C_00559450*)&m_14)->Modelloader_GetReferencedThis());
                ((C_004ea9c0*)((C_00559450*)this)->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis())
                    ->BGSTerrainManager_GetLODObjectRoot()
                    ->V55(((C_00559450*)&m_10)->Modelloader_GetReferencedThis(), 1);
            }
        }
        else if (((C_00559450*)&m_10)->Modelloader_GetReferencedThis() != 0)
        {
            ((C_004ea9c0*)((C_00559450*)this)->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis())
                ->BGSTerrainManager_GetLODObjectRoot()
                ->V55(((C_00559450*)&m_10)->Modelloader_GetReferencedThis(), 1);
        }
        if (((FUN_006f6070_shell*)this)->GetByteAtOffset35())
        {
            if (((C_00559450*)&m_0c)->Modelloader_GetReferencedThis() != 0 || ((C_00559450*)&m_14)->Modelloader_GetReferencedThis() != 0)
                DAT_011d8510 = DAT_011d8510 - 1;
            if (((C_00559450*)&m_04)->Modelloader_GetReferencedThis() != 0 || ((C_00559450*)&m_10)->Modelloader_GetReferencedThis() != 0)
                DAT_011d8514 = DAT_011d8514 + 1;
        }
        else
        {
            if (((C_00559450*)&m_0c)->Modelloader_GetReferencedThis() != 0 || ((C_00559450*)&m_14)->Modelloader_GetReferencedThis() != 0)
                DAT_011d8514 = DAT_011d8514 - 1;
            if (((C_00559450*)&m_04)->Modelloader_GetReferencedThis() != 0 || ((C_00559450*)&m_10)->Modelloader_GetReferencedThis() != 0)
                DAT_011d8510 = DAT_011d8510 + 1;
        }
        ((C_006f66e0*)this)->UpdateMenuNodes();
        if (((C_00559450*)&m_04)->Modelloader_GetReferencedThis() != 0 || ((C_00559450*)&m_10)->Modelloader_GetReferencedThis() != 0)
        {
            if (!((FUN_006f6100_shell*)this)->IsInCellList())
                ((C_006f6090*)this)->AddSelfToGlobalList();
        }
        ((C_0066b0d0*)&m_0c)->FUN_0066b0d0(0);
        ((C_0066b0d0*)&m_14)->FUN_0066b0d0(0);
        m_21 = 1;
    }
}

// FUN_006f6250: __thiscall (this in ecx), callee pops 4 bytes (1 stack parameter)
struct FUN_006e5cc0_shell
{
    void __thiscall FUN_006e5cc0(void* apObject);
};

// The shared task header does not yet declare this one-argument member.
struct FUN_006f6250_shell
{
    void BGSDistantObjectBlockLoadTask_GetWaterGeometry(FUN_006e5cc0_shell* apObject);
};

// @fnv 0x006f6250
// src: COMMUNITY 0x006f6250
void FUN_006f6250_shell::BGSDistantObjectBlockLoadTask_GetWaterGeometry(FUN_006e5cc0_shell* apObject)
{
    apObject->FUN_006e5cc0((void*)((char*)this + 0x4c));
}

namespace fnv_006f6270 {
extern char str_0106da18[];

struct VObj
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
};

struct FUN_006e5cc0_shell
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_006e5cc0(void* p);
};

struct FUN_00559450_shell
{
    unsigned int unk00;
    unsigned int unk04;
    VObj* Modelloader_GetReferencedThis();
    void AssignTaskReference(BGSDistantObjectBlockLoadTask* p);
};

struct FUN_00404ee0_shell
{
    void FUN_00404eb0(unsigned int a, int b, const char* c, unsigned int d);
    void FUN_00404ee0();
};

struct ScopeLock : FUN_00404ee0_shell
{
    void FUN_00404eb0_unused();
    unsigned int unk00;
    ScopeLock(unsigned int a, int b, const char* c, unsigned int d);
    __forceinline ~ScopeLock()
    {
        FUN_00404ee0();
    }
};


struct BlockLoader
{
    unsigned int unk00;
    unsigned int m_04;
    unsigned int unk08;
    FUN_006e5cc0_shell m_0c;
    FUN_00559450_shell m_18;
    unsigned char m_20;
    unsigned char m_21;

    void BGSDistantObjectBlock_CreateApocalypseTask(void* apOutput, void* apWorld, short asX, short asY);
};

// @fnv 0x006f6270
// src: COMMUNITY 0x006f6270
void BlockLoader::BGSDistantObjectBlock_CreateApocalypseTask(void* apOutput, void* apWorld, short asX, short asY)
{
    ScopeLock lock(0x24, 1, str_0106da18, 0x240);
    m_0c.FUN_006e5cc0(&m_04);
    m_18.AssignTaskReference(new BGSDistantObjectBlockLoadTask(this, apOutput, asX, asY, apWorld, 1, 1, 0));
    m_18.Modelloader_GetReferencedThis()->V8();
    m_20 = 0;
    m_21 = 0;
}
}  // namespace fnv_006f6270

struct S_006f6370_AutoMem
{
    int unk00;
    S_006f6370_AutoMem(int context, bool push, const char* file, int line);
    ~S_006f6370_AutoMem();
};

struct S_006f6370_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
};

struct S_006f6370_Ptr
{
    S_006f6370_Obj* unk00;
    operator S_006f6370_Obj*() const;
    S_006f6370_Obj* operator->() const;
    S_006f6370_Ptr& operator=(const S_006f6370_Ptr& other);
    S_006f6370_Ptr& operator=(S_006f6370_Obj* p);
};

struct S_006f6370_Mgr;


struct S_006f6370_Streamer
{
    void BSTaskManager_CancelTask(S_006f6370_Obj* task, int flag);
};

struct S_006f6370_Player
{
    unsigned char GetByteAtOffset();
};

extern S_006f6370_Streamer* DAT_01202d98;
extern S_006f6370_Player* DAT_011dea3c;

struct S_006f6370_Mgr
{
    int unk00;
    S_006f6370_Ptr unk04;
    int unk08;
    S_006f6370_Ptr unk0c;
    S_006f6370_Ptr unk10;
    S_006f6370_Ptr unk14;
    S_006f6370_Ptr unk18;
    S_006f6370_Ptr unk1c;
    unsigned char unk20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    int unk24;
    int unk28;
    void ResetAndCreateTask(TESWorldSpace* world, int level, short x, short y);
};

// @fnv 0x006f6370
void S_006f6370_Mgr::ResetAndCreateTask(TESWorldSpace* world, int level, short x, short y)
{
    S_006f6370_AutoMem ctx(
        0x24, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSDistantObjectBlock.cpp",
        0x250);
    unk0c = unk04;
    unk14 = unk10;
    if (unk18)
    {
        DAT_01202d98->BSTaskManager_CancelTask(unk18, 0);
        unk18 = 0;
    }
    if (unk1c)
    {
        DAT_01202d98->BSTaskManager_CancelTask(unk1c, 0);
        unk1c = 0;
    }
    unk18 = (S_006f6370_Obj*)new BGSDistantObjectBlockLoadTask(this, world, x, y, (void*)level, DAT_011dea3c->GetByteAtOffset(), 0, 0);
    unk28 = 0;
    unk18->vf20();
    unk20 = 0;
    unk21 = 0;
    unk23 = 0;
    unk22 = 0;
}

namespace fnv_006f6540 {
extern char str_0106da18[];

struct VObj
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
};

struct FUN_006e5cc0_shell
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_006e5cc0(void* p);
};

struct FUN_00559450_shell
{
    unsigned int unk00;
    unsigned int unk04;
    VObj* Modelloader_GetReferencedThis();
    void AssignTaskReference(BGSDistantObjectBlockLoadTask* p);
};

struct FUN_00404ee0_shell
{
    void FUN_00404eb0(unsigned int a, int b, const char* c, unsigned int d);
    void FUN_00404ee0();
};

struct ScopeLock : FUN_00404ee0_shell
{
    void FUN_00404eb0_unused();
    unsigned int unk00;
    ScopeLock(unsigned int a, int b, const char* c, unsigned int d);
    __forceinline ~ScopeLock()
    {
        FUN_00404ee0();
    }
};



struct FUN_0044ac40_owner
{
    void BSTaskManager_CancelTask(VObj* a, int b);
};
extern FUN_0044ac40_owner* DAT_01202d98;

struct FUN_006f6540_cls
{
    unsigned int unk00;
    unsigned int m_04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned char m_20;
    unsigned char m_21;
    unsigned char m_22;
    unsigned char m_23;
    unsigned int unk24;
    unsigned int m_28;

    void BGSDistantObjectBlock_SwitchToHigh(void* apOutput, void* apWorld, short asX, short asY);
};

// @fnv 0x006f6540
// src: COMMUNITY 0x006f6540
void FUN_006f6540_cls::BGSDistantObjectBlock_SwitchToHigh(void* apOutput, void* apWorld, short asX, short asY)
{
    ScopeLock lock(0x24, 1, str_0106da18, 0x272);
    ((FUN_006e5cc0_shell*)&unk0C)->FUN_006e5cc0(&m_04);
    ((FUN_006e5cc0_shell*)&unk14)->FUN_006e5cc0(&unk10);
    if (((FUN_00559450_shell*)&unk18)->Modelloader_GetReferencedThis())
    {
        DAT_01202d98->BSTaskManager_CancelTask(((FUN_00559450_shell*)&unk18)->Modelloader_GetReferencedThis(), 0);
        ((FUN_00559450_shell*)&unk18)->AssignTaskReference(0);
    }
    if (((FUN_00559450_shell*)&unk1C)->Modelloader_GetReferencedThis())
    {
        DAT_01202d98->BSTaskManager_CancelTask(((FUN_00559450_shell*)&unk1C)->Modelloader_GetReferencedThis(), 0);
        ((FUN_00559450_shell*)&unk1C)->AssignTaskReference(0);
    }
    ((FUN_00559450_shell*)&unk18)->AssignTaskReference(new BGSDistantObjectBlockLoadTask(this, apOutput, asX, asY, apWorld, 0, 1, 0));
    m_28 = 0;
    ((FUN_00559450_shell*)&unk18)->Modelloader_GetReferencedThis()->V8();
    m_20 = 0;
    m_21 = 0;
    m_23 = 1;
    m_22 = 0;
}
}  // namespace fnv_006f6540

void* __cdecl Object_DispatchCommandFour(unsigned int uiSize);
void __cdecl MmFree(void* pvMem);

struct MmNode;
struct MmProperty;

struct MmTexturing
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();

    virtual MmTexturing* Clone(MmNode* pkNode, int a2, int a3);
    void BSShaderProperty_SetFlag(int iFlag, int iValue);
    void* FUN_006286d0();
};

struct MmAlpha
{
    MmAlpha();
    static void* operator new(unsigned int uiSize)
    {
        return Object_DispatchCommandFour(uiSize);
    }
    static void operator delete(void* pvMem, unsigned int)
    {
        MmFree(pvMem);
    }
    int unk00[7];
    void FUN_004393c0(int i);
    void NiAlphaProperty_SetAlphaBlending(int i);
    void NiAlphaProperty_SetTestRef(int i);
    void FUN_004393e0(int i);
};

struct MmWorldBound
{
    void SetByteAtOffset38(int i);
    void FUN_00a67050(int i);
    void FUN_004410f0(int i);
};

struct MmUpdater
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void* Register(MmNode* pkNode, MmTexturing* pkTex);
};
struct MmScene
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void Add(MmNode* pkNode, int a2, int a3, void* pkData);
    void NiDX9Renderer_PerformPrecache();
};
MmScene* __cdecl NiXenonRenderer_GetRenderer();
int __cdecl MagicSystem_CheckEffectFlares();
void* __cdecl NiShadeProperty_GetType();
void* __cdecl BSShaderManager_GetShader(void* pkData);

struct MmTransform
{
    int unk00, unk04, unk08;
    MmTransform(float f, int a, int b);
};

struct MmNode
{
    void NiAVObject_RemoveProperty(int i);
    void NiAVObject_AttachProperty(void* pkProperty);
    MmTexturing* FUN_00a59d30(void* pkType);
    void FUN_00874460(void* pkData);
    void UpdateProperties();
    void NiAVObject_Update(MmTransform* pkTransform);
    MmWorldBound* NiGeometry_GetModelData();
    MmUpdater* CombatController_GetTarget();
};

template <class T> struct MmPtr
{
    T* m_pObject;
    T* Modelloader_GetReferencedThis() const;
    bool IsNotEqual(const MmPtr& kOther) const;
};

struct MmOwner
{
    void BGSTerrainNode_UpdateBlockVisibility(int i);
};

struct MenuModelImpl
{
    MmOwner* m_pkOwnerManager;
    MmPtr<MmNode> m_spNodeA;
    int unk08;
    MmPtr<MmNode> m_spNodeB;
    MmPtr<MmNode> m_spNodeC;
    MmPtr<MmNode> m_spNodeD;
    int unk18[2];
    unsigned short unk20;
    bool m_bValueAt0C;

    void ApplyShaderSetup(MmNode* pkNode);
    void UpdateMenuNodes();
};

// @fnv 0x006f66e0
void MenuModelImpl::UpdateMenuNodes()
{
    bool bRebuildNodeA =
        !m_bValueAt0C || (m_spNodeA.Modelloader_GetReferencedThis() && m_spNodeB.Modelloader_GetReferencedThis() && m_spNodeA.IsNotEqual(m_spNodeB));
    bool bRebuildNodeC =
        !m_bValueAt0C || (m_spNodeC.Modelloader_GetReferencedThis() && m_spNodeD.Modelloader_GetReferencedThis() && m_spNodeC.IsNotEqual(m_spNodeD));
    if (bRebuildNodeA && m_spNodeA.Modelloader_GetReferencedThis())
    {
        m_spNodeA.Modelloader_GetReferencedThis()->NiAVObject_RemoveProperty(MagicSystem_CheckEffectFlares());
        MmAlpha* pkAlphaPtr = new MmAlpha;
        pkAlphaPtr->FUN_004393c0(1);
        pkAlphaPtr->NiAlphaProperty_SetAlphaBlending(0);
        pkAlphaPtr->NiAlphaProperty_SetTestRef(0x80);
        pkAlphaPtr->FUN_004393e0(4);
        m_spNodeA.Modelloader_GetReferencedThis()->NiAVObject_AttachProperty(pkAlphaPtr);
        MmTexturing* pkTexX = m_spNodeA.Modelloader_GetReferencedThis()->FUN_00a59d30(NiShadeProperty_GetType());
        pkTexX->BSShaderProperty_SetFlag(0x22, 1);
        pkTexX->BSShaderProperty_SetFlag(0x21, 0);
        pkTexX->BSShaderProperty_SetFlag(0, 0);
        MmTexturing* pkCloneTmp2 = pkTexX->Clone(m_spNodeA.Modelloader_GetReferencedThis(), 0, 1);
        if (pkCloneTmp2)
        {
            m_spNodeA.Modelloader_GetReferencedThis()->NiAVObject_RemoveProperty(3);
            pkTexX = pkCloneTmp2;
            m_spNodeA.Modelloader_GetReferencedThis()->NiAVObject_AttachProperty(pkTexX);
        }
        m_spNodeA.Modelloader_GetReferencedThis()->FUN_00874460(BSShaderManager_GetShader(pkTexX->FUN_006286d0()));
        MmTransform kTransformTmp(0.0f, 0, 0);
        m_spNodeA.Modelloader_GetReferencedThis()->UpdateProperties();
        m_spNodeA.Modelloader_GetReferencedThis()->NiAVObject_Update(&kTransformTmp);
        m_pkOwnerManager->BGSTerrainNode_UpdateBlockVisibility(0);
        m_spNodeA.Modelloader_GetReferencedThis()->NiGeometry_GetModelData()->SetByteAtOffset38(0);
        m_spNodeA.Modelloader_GetReferencedThis()->NiGeometry_GetModelData()->FUN_00a67050(0x4000);
        m_spNodeA.Modelloader_GetReferencedThis()->NiGeometry_GetModelData()->FUN_004410f0(1);
        NiXenonRenderer_GetRenderer()->Add(m_spNodeA.Modelloader_GetReferencedThis(), 0, 0,
                            m_spNodeA.Modelloader_GetReferencedThis()->CombatController_GetTarget()->Register(m_spNodeA.Modelloader_GetReferencedThis(), pkTexX));
        NiXenonRenderer_GetRenderer()->NiDX9Renderer_PerformPrecache();
        m_bValueAt0C = true;
    }
    if (bRebuildNodeC && m_spNodeC.Modelloader_GetReferencedThis())
    {
        ApplyShaderSetup(m_spNodeC.Modelloader_GetReferencedThis());
        NiXenonRenderer_GetRenderer()->NiDX9Renderer_PerformPrecache();
        m_bValueAt0C = true;
    }
}

namespace fnv_006f6a90 {
struct GtPoint3
{
    float x, y, z;
    GtPoint3(float fX, int iY, int iZ);
};
struct GtNode;
struct GtGeometry;
struct GtAVObject
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual GtNode* IsSceneNode();
    virtual void v004();
    virtual void v005();
    virtual GtGeometry* IsGeometry();
};
struct GtNode : GtAVObject
{
    unsigned int NiNode_GetChildCount();
    GtAVObject* NiNode_GetAtChecked(unsigned int uiIndex);
};
struct GtFlags
{
    void SetByteAtOffset38(int i);
    void FUN_00a67050(int i);
    void FUN_004410f0(int i);
};
struct GtProperty
{
    char pad[0x1c];
    static void* operator new(unsigned int uiSize);
    static void operator delete(void*, unsigned int);
    GtProperty();
    void FUN_004393c0(int i);
    void NiAlphaProperty_SetAlphaBlending(int i);
    void NiAlphaProperty_SetTestRef(int i);
    void FUN_004393e0(int i);
};
struct GtShaderProp
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();

    virtual GtShaderProp* FUN_vb0(GtGeometry* pkGeomA, int i, int j);
    void BSShaderProperty_SetFlag(int iFlag, int iValue);
    int FUN_006286d0();
};
struct GtGeometry : GtAVObject
{
    GtShaderProp* FUN_00a59d30(int iType);
    void NiAVObject_RemoveProperty(int iType);
    void NiAVObject_AttachProperty(void* pkPropW);
    void FUN_00874460(int i);
    void UpdateProperties();
    void NiAVObject_Update(GtPoint3* pkPt);
    GtFlags* NiGeometry_GetModelData();
    struct GtShaderMgr* CombatController_GetTarget();
};
struct GtShaderMgr
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual int FUN_v118(GtGeometry* pkGeomA, GtShaderProp* pkPropW);
};
struct GtAccum
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void FUN_vec(GtGeometry* pkGeomA, int i, int j, int k);
};
struct GtOwner
{
    void BGSTerrainNode_UpdateBlockVisibility(int i);
};
int __cdecl NiShadeProperty_GetType();
int __cdecl MagicSystem_CheckEffectFlares();
int __cdecl BSShaderManager_GetShader(int i);
GtAccum* __cdecl NiXenonRenderer_GetRenderer();

struct FUN_006f6a90_Owner
{
    GtOwner* m_pkOwnerManager;
    void ApplyShaderSetup(GtAVObject* pkObject);
};

// @fnv 0x006f6a90
void FUN_006f6a90_Owner::ApplyShaderSetup(GtAVObject* pkObject)
{
    if (!pkObject)
        return;
    if (pkObject->IsSceneNode())
    {
        GtNode* pkNode = pkObject->IsSceneNode();
        for (unsigned int i = 0; i < pkNode->NiNode_GetChildCount(); i++)
            ApplyShaderSetup(pkNode->NiNode_GetAtChecked(i));
    }
    else
    {
        GtGeometry* pkGeomA = pkObject->IsGeometry();
        GtShaderProp* kPkOld = pkGeomA->FUN_00a59d30(NiShadeProperty_GetType());
        GtShaderProp* pkShaderZ = pkGeomA->FUN_00a59d30(NiShadeProperty_GetType());
        pkGeomA->NiAVObject_RemoveProperty(MagicSystem_CheckEffectFlares());
        GtProperty* pkPropW = new GtProperty;
        pkPropW->FUN_004393c0(1);
        pkPropW->NiAlphaProperty_SetAlphaBlending(0);
        pkPropW->NiAlphaProperty_SetTestRef(0x80);
        pkPropW->FUN_004393e0(4);
        pkGeomA->NiAVObject_AttachProperty(pkPropW);
        pkShaderZ->BSShaderProperty_SetFlag(0x22, 1);
        pkShaderZ->BSShaderProperty_SetFlag(0x37, 1);
        GtShaderProp* pkNewVal2 = pkShaderZ->FUN_vb0(pkGeomA, 0, 1);
        if (pkNewVal2)
        {
            pkGeomA->NiAVObject_RemoveProperty(3);
            pkShaderZ = pkNewVal2;
            pkGeomA->NiAVObject_AttachProperty(pkShaderZ);
        }
        pkGeomA->FUN_00874460(BSShaderManager_GetShader(pkShaderZ->FUN_006286d0()));
        GtPoint3 kZeroWork(0.0f, 0, 0);
        pkGeomA->UpdateProperties();
        pkGeomA->NiAVObject_Update(&kZeroWork);
        m_pkOwnerManager->BGSTerrainNode_UpdateBlockVisibility(0);
        pkGeomA->NiGeometry_GetModelData()->SetByteAtOffset38(0);
        pkGeomA->NiGeometry_GetModelData()->FUN_00a67050(0x4000);
        pkGeomA->NiGeometry_GetModelData()->FUN_004410f0(1);
        NiXenonRenderer_GetRenderer()->FUN_vec(pkGeomA, 0, 0, pkGeomA->CombatController_GetTarget()->FUN_v118(pkGeomA, pkShaderZ));
    }
}
}  // namespace fnv_006f6a90

struct TaskPlayer
{
    bool GetByteAtOffset();
};
extern TaskPlayer* g_thePlayer_011dea3c;

void __cdecl BuildLODBlockFilePath(char* pcPath, int iWorld, int iLevel, unsigned short usX, unsigned short usY);
void __cdecl FormatLODBlockFileName(char* pcPath, int iWorld, int iLevel, unsigned short usX, unsigned short usY);
void __cdecl BuildLODBlockFileName(char* pcPath, int iWorld, int iLevel, unsigned short usX, unsigned short usY);
void __cdecl FormatStingerBlockPath(char* pcPath, int iWorld, int iLevel, unsigned short usX, unsigned short usY);
void __cdecl BuildStingerNifPath(char* pcPath, int iWorld, int iLevel, unsigned short usX, unsigned short usY);
int __cdecl FUN_00456a20(const char* pcPath, int a2, int a3, int a4);

// @fnv 0x006f6d10
BGSDistantObjectBlockLoadTask::BGSDistantObjectBlockLoadTask(int iParent, int iWorld, int iX, int iY, int iLevel, bool bForce, bool bAlt, bool abLOD)
    : QueuedFileEntry(3), m_bDone(0), m_iX(iX), m_iY(iY), m_iZ(iLevel), m_pParent((BGSDistantObjectBlock*)iParent), m_pContainingWorldspace((TESWorldSpace*)iWorld),
      m_spNode(0), m_spLand(0), m_bLoadComplete(0), m_bLOD(abLOD)
{
    char acPath[0x104];
    if (!abLOD)
    {
        if (!bForce && !g_thePlayer_011dea3c->GetByteAtOffset())
        {
            if (bAlt)
                BuildLODBlockFilePath(acPath, (int)m_pContainingWorldspace, iLevel, (unsigned short)iX, (unsigned short)iY);
            else
                FormatLODBlockFileName(acPath, (int)m_pContainingWorldspace, iLevel, (unsigned short)iX, (unsigned short)iY);
        }
        else
        {
            if (bAlt)
            {
                BuildLODBlockFilePath(acPath, (int)m_pContainingWorldspace, iLevel, (unsigned short)iX, (unsigned short)iY);
            }
            else
            {
                BuildLODBlockFileName(acPath, (int)m_pContainingWorldspace, iLevel, (unsigned short)iX, (unsigned short)iY);
                if (!FUN_00456a20(acPath, 0, 0, -1))
                    FormatLODBlockFileName(acPath, (int)m_pContainingWorldspace, iLevel, (unsigned short)iX, (unsigned short)iY);
            }
        }
    }
    else
    {
        if (bAlt)
            FormatStingerBlockPath(acPath, (int)m_pContainingWorldspace, iLevel, (unsigned short)iX, (unsigned short)iY);
        else
            BuildStingerNifPath(acPath, (int)m_pContainingWorldspace, iLevel, (unsigned short)iX, (unsigned short)iY);
    }
    SetFileName_00c3cee0(acPath + 5);
    LookupFileEntryByArchive(0);
}

struct F7070ModelLoader
{
    void QueueTask(const char* pcPath, IO_TASK_PRIORITY ePriority, void* pkTask);
};

extern F7070ModelLoader* g_pModelLoader;

// @fnv 0x006f7070
void BGSDistantObjectBlockLoadTask::QueueLODModelLoads()
{
    char acFirstPath[260];
    char acSecondPath3[260];
    if (!bSkipLoad)
    {
        FormatBuildingsLODTexturePath(acFirstPath, m_pContainingWorldspace);
        g_pModelLoader->QueueTask(acFirstPath, IOTask_GetIOTaskPriority(), this);
        BGSDistantObjectBlock_BuildBlockNormalTextureFileName(acSecondPath3, m_pContainingWorldspace);
        g_pModelLoader->QueueTask(acSecondPath3, IOTask_GetIOTaskPriority(), this);
    }
    bFadeQueuedCur = true;
    OnChildCompletion();
}

// ---------------------------------------------------------------------------
// UpdateLoadingState - updates the distant object block of one cell.
//
// The task object keeps the block that is currently being loaded (+0x40), the
// two nodes the block refers to (+0x48 / +0x4c), the coordinates of the cell
// (+0x34 / +0x38 / +0x3c) and a flag (+0x50) that tells whether the block was
// already segmented.
//
// While the block is loaded the task asks the block to keep its load state
// (+0x40 -> SetLoading) and marks the segmented object of the block chain as
// segmented.  When the block is not segmented the game complains about it.
// Once the block was segmented both node references are dropped again.
// ---------------------------------------------------------------------------

// The object that carries the "segmented" flag at +0x28.
struct FnvDistantSegment
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
    unsigned char unk28;
    void SetSegmented(bool abFlag);
};

// One link of the reference chain of a block.
struct FnvDistantLink
{
    FnvDistantSegment* unk00;
    FnvDistantSegment* Get();
};

// The distant object block of one cell.
struct FnvDistantBlock
{
    FnvDistantLink* unk00;
    FnvDistantLink* Get();
    void SetLoading(bool abFlag);
};

// The game logs a warning with a printf style format string.
void __cdecl FNV_Warning(const char* apFormat, ...);

// @fnv 0x006f73d0
void BGSDistantObjectBlockLoadTask::UpdateLoadingState()
{
    if ((NiAVObject*)m_spNode != 0)
    {
        if (m_bLoadComplete == 0)
        {
            ((FnvDistantBlock*)m_pParent)->SetLoading(1);
            ((FnvDistantBlock*)m_pParent)->Get()->Get()->SetSegmented(1);

            if (((NiAVObject*)m_spNode)->IsSegmentedTriShape() == 0)
            {
                FNV_Warning("MODELS: Found a distant object block for %i:%i,%i but it is not segmented.", iLevel, iX,
                            iY);
            }
        }
        else
        {
            m_spNode = 0;
            m_spLand = 0;
        }
    }
    else
    {
        if (m_bLoadComplete == 0 && m_pParent != 0)
        {
            ((FnvDistantBlock*)m_pParent)->SetLoading(0);
        }
    }
}
