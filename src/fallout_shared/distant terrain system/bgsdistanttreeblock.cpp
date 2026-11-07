#include <string.h>
#pragma intrinsic(memcpy)
#include "../../../include/AutoMemHelper.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/BGSDistantTreeBlock.h"
#include "../../../include/BGSDistantTreeBlockLoadTask.h"
#include "../../../include/DummyPointerMap.h"
#include "../../../include/GO.h"
#include "../../../include/IOManager.h"
#include "../../../include/IOTask.h"
#include "../../../include/MiddleHighProcess.h"
#include "../../../include/NP.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/NiBinaryStream.h"
#include "../../../include/NiBound.h"
#include "../../../include/NiFile.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiPoint2.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiTPointerMap.h"
#include "../../../include/PathingSolution.h"
#include "../../../include/QueuedFileEntry.h"

// src/fallout_shared/distant terrain system/bgsdistanttreeblock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsdistanttreeblock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern NP DAT_012007c4;

// @fnv 0x006f7a60
// src: COMMUNITY 0x006f7a60
void BSDistantTreeShader_SetTextureAtlas(void* p)
{
    DAT_012007c4.operator=(p);
}

void* __cdecl _Deallocate(void*);

// Calls FUN_006f94a0, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x006f9470
void* BGSDistantTreeBlockLoadTask::Destroy(unsigned int flags)
{
    FUN_006f94a0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Sets the byte at this+0x44 to 1, then calls FUN_00c3cb70 with the given arguments.
// @fnv 0x006f9540
// src: XBOX_PDB 0x006f9540
void BGSDistantTreeBlockLoadTask::Cancel_006f9540(int aiArg, void* apArg)
{
    m_bCancelled = true;
    QueuedFile_Cancel(aiArg, apArg);
}

extern int _sprintf_s(char*, unsigned int, const char*, ...);

// Writes the block coordinates and level into apDescription with _sprintf_s and returns true.
// @fnv 0x006f9640
bool BGSDistantTreeBlockLoadTask::FormatDescription(char* apDescription, unsigned int aiBufferSize)
{
    _sprintf_s(apDescription, aiBufferSize, "Tree LOD Task for block ( %i, %i ) at level ( %i )", iX, iY, iLevel);
    return true;
}

struct Helper8
{
    void BSSimpleArray_BGSDistantTreeBlock_InstanceData_1024_BSSimpleArray_BGSDistantTreeBlock_InstanceData_1024();
};
struct FUN_006f8650
{
    int unk0;
    GO unk4;
    Helper8 unk8;
    FUN_006f8650();
};
// Constructor: initializes unk4 with 0 and calls FUN_006f9740 on unk8.
// @fnv 0x006f8650
FUN_006f8650::FUN_006f8650() : unk4(0)
{
    unk8.BSSimpleArray_BGSDistantTreeBlock_InstanceData_1024_BSSimpleArray_BGSDistantTreeBlock_InstanceData_1024();
}

struct FUN_006b3140_shell
{
    void AddElement(void*);
    void* FUN_006b3140();
};
extern FUN_006b3140_shell g_011d85d0;
void BuildNavMeshGeometry(void*);
// @fnv 0x006f86b0
// src: COMMUNITY 0x006f86b0
void BGSDistantTreeBlock_TreeTypes_Append(void* a1)
{
    g_011d85d0.AddElement(a1);
    BuildNavMeshGeometry(g_011d85d0.FUN_006b3140());
}

struct FUN_006f8800_shell
{
    void FUN_006f8830();
    void* BGSDistantTreeBlock_TreeGroup_Destroy(unsigned int flags);
};

// Calls FUN_006f8830, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006f8800
// src: COMMUNITY 0x006f8800
void* FUN_006f8800_shell::BGSDistantTreeBlock_TreeGroup_Destroy(unsigned int flags)
{
    FUN_006f8830();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_006f8830 {
struct H9770
{
    void SetVtableAndProcessState_006f9770();
};
struct FUN_006f8830
{
    int _00;
    GO _04;
    H9770 _08;
    ~FUN_006f8830();
};
// Destructor that calls FUN_006f9770 on the member at offset 0x08.
// @fnv 0x006f8830
FUN_006f8830::~FUN_006f8830()
{
    _08.SetVtableAndProcessState_006f9770();
}
}  // namespace fnv_006f8830

struct Flt
{
    operator unsigned int();
};
void BGSTerrainManager_SetNeedsImmediateUpdate();
struct QIdlePtr
{
    QIdlePtr& operator=(void*);
};
struct FUN_006f88e0_shell
{
    void BGSDistantTreeBlock_FinishLoad();
};
// Sets the byte at offset 0x48 to 1, calls FUN_00929260(1) on the process at offset 0x44, then clears the pointer at offset 0.
// @fnv 0x006f88e0
// src: COMMUNITY 0x006f88e0
void FUN_006f88e0_shell::BGSDistantTreeBlock_FinishLoad()
{
    *(char*)(this + 0x48) = 1;
    reinterpret_cast<void (__thiscall*)(MiddleHighProcess*, unsigned char)>(&BGSTerrainManager_SetNeedsImmediateUpdate)(
        (MiddleHighProcess*)((Flt*)(*(void**)((char*)this + 0x44)))->operator unsigned int(), 1);
    ((QIdlePtr*)this)->operator=(0);
}

namespace fnv_006f91a0 {
// Exe 0x006f91a0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BgsdistanttreeblockOffset08View
{
    unsigned int GetFlags();
    unsigned int* GetAt(int);
};
struct Flt
{
    operator unsigned int();
};
struct PropHelper
{
    void* GetProperty(unsigned int);
};
unsigned int __cdecl NiShadeProperty_GetType();
struct FUN_006f90a0_shell
{
    void UpdateInstances(void* a, void* b);
};
struct FUN_006f91a0_shell : BgsdistanttreeblockOffset08View
{
    void BGSDistantTreeBlock_UpdateShaderPropertyRecurse();
};
// Iterates the array at this+4, and for each unflagged entry with a nonzero value, looks up a property and passes it with the entry to UpdateInstances.
// @fnv 0x006f91a0
// src: COMMUNITY 0x006f91a0
void FUN_006f91a0_shell::BGSDistantTreeBlock_UpdateShaderPropertyRecurse()
{
    for (unsigned int i = 0; i < ((BgsdistanttreeblockOffset08View*)((char*)this + 4))->GetFlags(); ++i)
    {
        void* p = *((void**)((BgsdistanttreeblockOffset08View*)((char*)this + 4))->GetAt(i));
        if (!(*(unsigned char*)((char*)p + 0x1c)) && ((Flt*)((char*)p + 4))->operator unsigned int())
        {
            void* property =
                ((PropHelper*)((Flt*)((char*)p + 4))->operator unsigned int())->GetProperty(NiShadeProperty_GetType());
            if (property)
                ((FUN_006f90a0_shell*)this)->UpdateInstances(property, p);
        }
    }
}
}  // namespace fnv_006f91a0

// @fnv 0x006f94c0
// src: XBOX_PDB 0x006f94c0
void BGSDistantTreeBlockLoadTask::QueueMe()
{
    unk30[4] = true;
    OnChildCompletion();
}

struct Block88
{
    void BGSDistantTreeBlock_FinishLoad();
};
// If loading completed without cancellation, notify the tree block.
// @fnv 0x006f9610
void BGSDistantTreeBlockLoadTask::Finish()
{
    if (m_bLoadComplete && !m_bCancelled)
        (*(Block88**)unk30)->BGSDistantTreeBlock_FinishLoad();
}

struct InstanceData
{
    int f[8];
};
struct FakeArray
{
    int _0;
    InstanceData* _4;
    unsigned int __thiscall GetNextIndex();
    void __thiscall ConstructElements(void*, int);
    unsigned int __thiscall AppendInstance(InstanceData*);
};
// @fnv 0x006f9800
unsigned int __thiscall FakeArray::AppendInstance(InstanceData* apInstance)
{
    unsigned int uiNewIndex;
    uiNewIndex = GetNextIndex();
    ConstructElements(&_4[uiNewIndex], 1);
    _4[uiNewIndex] = *apInstance;
    return uiNewIndex;
}

struct NavMeshSearchLOSArray
{
    void FUN_006a8500();
    void BSSimpleArray_PathingLocation_1024_DestructItems(void*, unsigned int);
};
struct ShaderProp
{
    void __thiscall ProcessEntries_006fa090(void* a, void* b);
};
struct FUN_006f9c70_shell
{
    void BGSDistantTreeBlock_TreeTypes_FreeAll(bool freeStorage);
};
// @fnv 0x006f9c70
// src: COMMUNITY 0x006f9c70
void FUN_006f9c70_shell::BGSDistantTreeBlock_TreeTypes_FreeAll(bool freeStorage)
{
    if (*(void**)((char*)this + 4))
    {
        ((ShaderProp*)this)->ProcessEntries_006fa090(*(void**)((char*)this + 4), *(void**)((char*)this + 8));
        if (freeStorage)
        {
            ((NavMeshSearchLOSArray*)this)->FUN_006a8500();
            *(void**)((char*)this + 4) = 0;
            *(unsigned int*)((char*)this + 0xc) = 0;
        }
        *(unsigned int*)((char*)this + 8) = 0;
    }
}

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
struct Fake076
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetStr();
};
// Formats a Data\Meshes\Landscape\LOD tree DTL path into a1 using a2's string, a3, a4 and a5, and returns _sprintf_s's result.
// @fnv 0x006f8890
int __cdecl FormatTreeLodDtlPath(char* pcBuffer, Fake076* a2, int iLevel, short iX, short iY)
{
    return _sprintf_s(pcBuffer, 260, "Data\\Meshes\\Landscape\\LOD\\%s\\Trees\\%s.Level%i.X%i.Y%i.DTL", a2->GetStr(),
                      a2->GetStr(), iLevel, iX, iY);
}

class BGSDistantTreeBlock::InstanceData
{
public:
    unsigned char pad[0x18];
    int f18;
    unsigned char f1c;
};
// Looks up aID in map; if found, clears f1c on the instance and on the instance referenced by arr at f18.
// @fnv 0x006f92a0
void BGSDistantTreeBlock::ClearInstanceFlag(unsigned int aID)
{
    bool bfound;
    InstanceData* pinst = 0;
    bfound = map.GetAt(aID, (unsigned int&)pinst);
    if (bfound)
    {
        pinst->f1c = 0;
        ((InstanceData*)arr.GetAt(pinst->f18))->f1c = 0;
    }
}

// Iterates over every entry in mArray, passes each element to MarkTreeInstance, then calls FUN_006f7780.
// @fnv 0x006f9300
void BGSDistantTreeBlock::ProcessAllTrees()
{
    unsigned int i;
    for (i = 0; i < mArray.GetSize(); i++)
    {
        MarkTreeInstance(*mArray.GetAtPointer((int)i), false);
    }
    BGSDistantTreeBlock_ClearQueuedTrees();
}

class BSSoundHandle;
extern IOManager* DAT_01202d98;
// @fnv 0x006f94e0
void BGSDistantTreeBlockLoadTask::DispatchToManager()
{
    if (((IOTask*)this)->QueuedFile_GetAllChildrenFinished() && unk30[4])
    {
        if (((NiTPointerMap<unsigned int, BSSoundHandle*>*)this)->IsEmpty())
            DAT_01202d98->AddTask(reinterpret_cast<QIOTask*>(this));
        else
            ((IOTask*)this)->NotifyParents();
    }
}


struct InstanceDataB
{
    unsigned char b1c;
};
// @fnv 0x006f9230
void BGSDistantTreeBlock::MarkTreeInstance(unsigned int aID, bool abQueue)
{
    unsigned int pinst = 0;
    bool bfound = map.GetAt(aID, pinst);
    if (bfound)
    {
        ((InstanceDataB*)((char*)pinst + 0x1c))->b1c = 1;
        ((InstanceDataB*)((char*)arr.GetAt((int)*(unsigned int*)((char*)pinst + 0x18))) + 0x1c)
            ->b1c = 0;
    }
    else if (abQueue)
        ((BSSimpleArray<unsigned int>*)&mArray)->Add(aID);
}

struct FUN_006b3120_helper
{
    unsigned char* __thiscall GetElementAt(int);
};

extern NP g_011d85bc;
extern NP g_011d85c4;
extern NP g_011d85e0;
extern unsigned char DAT_011d85a0;

// Clears each element's field at offset 0x1c, resets g_011d85bc, g_011d85c4, g_011d85e0, calls FUN_006f7a60(0) and clears DAT_011d85a0.
// @fnv 0x006f83f0
// src: COMMUNITY 0x006f83f0
void BGSDistantTreeBlock_DeallocateStaticData()
{
    int i;

    for (i = 0; i < ((BGSDistantTreeBlock::TreeIndexArray*)&g_011d85d0)->GetSize(); ++i)
    {
        ((NP*)(((FUN_006b3120_helper*)&g_011d85d0)->GetElementAt(i) + 0x1c))->operator=((void*)0);
    }

    g_011d85bc = (void*)0;
    g_011d85c4 = (void*)0;
    g_011d85e0 = (void*)0;
    BSDistantTreeShader_SetTextureAtlas(0);
    DAT_011d85a0 = 0;
}



// The serialized tree instance contains a bound followed by 16 bytes of instance data.
struct TreeInstanceRecord
{
    NiBound bound;
    unsigned int data[4];

    __forceinline TreeInstanceRecord()
    {}
};


extern const char str_0106dd30[];

struct FUN_006f8b40_shell
{
    void ClearEntries();
    void AddTreeInstance(unsigned int type, void* instance);
    void ReadGroups(NiFile* apInputFile);
};

// Reads a group count from the file, then for each group reads a type and size and reads that many tree instance records, passing each to AddTreeInstance.
// @fnv 0x006f8b40
void FUN_006f8b40_shell::ReadGroups(NiFile* apInputFile)
{
    AutoMemHelper tempMemContext(0x25, true, str_0106dd30, 0x204);

    this->ClearEntries();

    unsigned int uinumGroups;
    apInputFile->Read(&uinumGroups, 4);

    for (unsigned int i = 0; i < uinumGroups; ++i)
    {
        unsigned int uitype;
        unsigned int uisize;
        apInputFile->Read(&uitype, 4);
        apInputFile->Read(&uisize, 4);

        for (unsigned int j = 0; j < uisize; ++j)
        {
            TreeInstanceRecord instance;
            apInputFile->Read(&instance, 0x20);
            this->AddTreeInstance(uitype, &instance);
        }
    }
}

struct FUN_00bb7290_shell
{
    void SetEntry(unsigned int, float, float, float, float, float);
};

struct FUN_006b3120_shell
{
    void* GetElementAt(int);
};

struct FUN_006f90a0_instance
{
    float f0;
    float f1;
    float f2;
    float f3;
    float f4;
    char _pad[8];
    unsigned char flag;
};

struct FUN_006f90a0_owner
{
    char _pad[0x1c];
    unsigned char flag;
};

struct FUN_006f90a0_params
{
    FUN_00bb7290_shell* renderer;
    FUN_006f90a0_owner* owner;
};

struct FUN_006f90a0_shell
{
    void UpdateInstances(FUN_006f90a0_params params);
};

unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
unsigned int __cdecl BSDistantTreeShader_GetMaxInstances(void);

// @fnv 0x006f90a0
void FUN_006f90a0_shell::UpdateInstances(FUN_006f90a0_params params)
{
    unsigned int count = FUN_0042f5a0(
        reinterpret_cast<BGSDistantTreeBlock::TreeIndexArray*>(reinterpret_cast<unsigned char*>(params.owner) + 8)->GetSize(), BSDistantTreeShader_GetMaxInstances());

    for (unsigned int i = 0; i < count; ++i)
    {
        FUN_006f90a0_instance* instance = reinterpret_cast<FUN_006f90a0_instance*>(
            reinterpret_cast<FUN_006b3120_shell*>(reinterpret_cast<unsigned char*>(params.owner) + 8)->GetElementAt(i));

        params.renderer->SetEntry(i, instance->f0, instance->f1, instance->f2, instance->f3,
                                  instance->flag ? 0.0f : instance->f4);
    }

    for (unsigned int j = count; j < BSDistantTreeShader_GetMaxInstances(); ++j)
    {
        params.renderer->SetEntry(j, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    }

    params.owner->flag = 1;
}

#include "../../../include/NiMemObject.h"
struct Obj44 : NiMemObject
{
    char _pad[44];
    Obj44(unsigned short);
    void SetSize_Thunk(int);
    void NiAdditionalGeometryData_SetDataStreamCount(int);
    void NiAdditionalGeometryData_SetDataBlock(int, void*, int, int);
    void NiAdditionalGeometryData_SetDataStream(int, int, int, int, unsigned short, int, int);
};
struct Obj88 : NiMemObject
{
    char _pad[88];
    Obj88(unsigned short, NiPoint3*, NiPoint3*, int, NiPoint2*, int, int, unsigned short, unsigned short*);
};
// Exe 0x0066b0d0 / 0x0045cec0: shared retain/release and destructor; scene references use an erased NiRefObject pointee.
#include "../../../include/NiRefObject.h"
#include "../../../include/NiPointer.h"
template <> NiPointer<NiRefObject>::NiPointer() FNV64_NIPOINTER_EXCEPTION_SPEC;
template <> NiPointer<NiRefObject>::~NiPointer() FNV64_NIPOINTER_EXCEPTION_SPEC;
template <> NiPointer<NiRefObject>& NiPointer<NiRefObject>::operator=(NiRefObject*) FNV64_NIPOINTER_EXCEPTION_SPEC;

class NiGPUProgram;
struct NiGPUProgramOwner
{
    void SetProgram(NiGPUProgram*);
};
int __fastcall Modelloader_GetReferencedThis(int*);
struct InParam
{
    int unk0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    NavMeshPtr m1c;
};
extern const float DAT_01012054;
float __cdecl NiSqrt_004579e0(float);
// @fnv 0x006f7a80
void BuildNavMeshGeometry(void* pInParam)
{
    AutoMemHelper helper0(0x25, true, str_0106dd30, 0x95);
    float sB3;
    Obj44* obj304;
    NiPoint3* arrA3;
    unsigned short* idx2;
    float raw8h;
    float rawCa;
    float raw182;
    NiPoint2* arrB5;
    float sAh;
    NiPoint3* arrCy;
    unsigned int tB;
    unsigned int ju;
    unsigned int iy;
    float raw42;
    float raw145;
    float raw103;
    float tmpF1;
    unsigned int cntA3;
    unsigned int cntB;
    float* arrFk;
    unsigned short w4;
    cntA3 = BSDistantTreeShader_GetMaxInstances() << 2;
    cntB = BSDistantTreeShader_GetMaxInstances() << 3;
    arrA3 = new NiPoint3[cntB];
    arrB5 = new NiPoint2[cntB];
    arrCy = new NiPoint3[cntB];
    idx2 = new unsigned short[cntA3 * 3];
    raw42 = ((InParam*)pInParam)->f4;
    sAh = (float)(raw42 * 0.5);
    raw8h = ((InParam*)pInParam)->f8;
    sB3 = (float)(raw8h * 0.5);
    rawCa = ((InParam*)pInParam)->fc;
    raw103 = ((InParam*)pInParam)->f10;
    raw145 = ((InParam*)pInParam)->f14;
    raw182 = ((InParam*)pInParam)->f18;
    tmpF1 = NiSqrt_004579e0(2.0f);
    for (iy = 0; iy < cntB; iy += 8)
    {
        arrA3[iy].x = -sAh;
        arrA3[iy].y = 0.0f;
        arrA3[iy].z = raw8h;
        arrB5[iy].x = rawCa;
        arrB5[iy].y = raw103;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        arrCy[iy].Unitize_004a0c10();
        arrA3[iy + 1].x = sAh;
        arrA3[iy + 1].y = 0.0f;
        arrA3[iy + 1].z = raw8h;
        arrB5[iy + 1].x = raw145;
        arrB5[iy + 1].y = raw103;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        arrCy[iy].Unitize_004a0c10();
        arrA3[iy + 2].x = -sAh;
        arrA3[iy + 2].y = 0.0f;
        arrA3[iy + 2].z = 0.0f;
        arrB5[iy + 2].x = rawCa;
        arrB5[iy + 2].y = raw182;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        arrCy[iy].Unitize_004a0c10();
        arrA3[iy + 3].x = sAh;
        arrA3[iy + 3].y = 0.0f;
        arrA3[iy + 3].z = 0.0f;
        arrB5[iy + 3].x = raw145;
        arrB5[iy + 3].y = raw182;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        arrCy[iy].Unitize_004a0c10();
        arrA3[iy + 4].x = 0.0f;
        arrA3[iy + 4].y = -sAh;
        arrA3[iy + 4].z = raw8h;
        arrB5[iy + 4].x = rawCa;
        arrB5[iy + 4].y = raw103;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        arrCy[iy].Unitize_004a0c10();
        arrA3[iy + 5].x = 0.0f;
        arrA3[iy + 5].y = sAh;
        arrA3[iy + 5].z = raw8h;
        arrB5[iy + 5].x = raw145;
        arrB5[iy + 5].y = raw103;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        arrCy[iy].Unitize_004a0c10();
        arrA3[iy + 6].x = 0.0f;
        arrA3[iy + 6].y = -sAh;
        arrA3[iy + 6].z = 0.0f;
        arrB5[iy + 6].x = rawCa;
        arrB5[iy + 6].y = raw182;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        arrCy[iy].Unitize_004a0c10();
        arrA3[iy + 7].x = 0.0f;
        arrA3[iy + 7].y = sAh;
        arrA3[iy + 7].z = 0.0f;
        arrB5[iy + 7].x = raw145;
        arrB5[iy + 7].y = raw182;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        arrCy[iy].Unitize_004a0c10();
    }
    w4 = 0;
    for (ju = 0; ju < cntA3 * 3; ju += 6)
    {
        idx2[ju] = w4;
        idx2[ju + 1] = w4 + 1;
        idx2[ju + 2] = w4 + 2;
        idx2[ju + 3] = w4 + 1;
        idx2[ju + 4] = w4 + 3;
        idx2[ju + 5] = w4 + 2;
        w4 = w4 + 4;
    }
    arrFk = new float[cntB];
    for (tB = 0; tB < cntB; ++tB)
        arrFk[tB] = (float)(tB >> 3);
    obj304 = new Obj44((unsigned short)cntB);
    obj304->SetSize_Thunk(1);
    obj304->NiAdditionalGeometryData_SetDataStreamCount(1);
    obj304->NiAdditionalGeometryData_SetDataBlock(0, arrFk, (int)(cntB * 4), 1);
    obj304->NiAdditionalGeometryData_SetDataStream(0, 0, 0, 1, (unsigned short)cntB, 4, 4);
    delete[] arrFk;
    GO refObj((int)new Obj88((unsigned short)cntB, arrA3, arrCy, 0, arrB5, 1, 0, (unsigned short)cntA3, idx2));
    ((NiGPUProgramOwner*)Modelloader_GetReferencedThis((int*)&refObj))->SetProgram((NiGPUProgram*)obj304);
    ((InParam*)pInParam)->m1c = *(NavMeshPtr*)&refObj;
    ((NiPointer<NiRefObject>*)&refObj)->operator=(static_cast<NiRefObject*>(0));
}

void FNV_Warning(const char* fmt, ...);

struct TreeInstance
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int uiID;
    int iBlockIndex;
    unsigned char bFlag;
};

struct TreeInstanceArray
{
    int unk00;
    TreeInstance* pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
    unsigned int GetSize();
    void SetCapacity(unsigned int);
    unsigned int AddInstance(TreeInstance* apInstance);
    TreeInstance* GetInstance(int);
};

struct TreeTypeArray
{
    unsigned int GetSize();
    void* GetType(unsigned int);
};
extern TreeTypeArray g_TreeTypes;

struct TreeBlock
{
    void* pType;
    int unk04;
    TreeInstanceArray kInstances;
    int iIndex;
    unsigned char bFull;
    TreeBlock();
};

struct TreeBlockArray
{
    unsigned int Add(TreeBlock*& arpBlock);
    unsigned int GetSize();
};

struct TreeBlockMap
{
    bool GetAt(unsigned int auiKey, TreeBlock*& arpVal);
    void SetAt(unsigned int auiKey, TreeBlock* apVal);
};

struct TreeInstanceMap
{
    void SetAt(unsigned int auiKey, TreeInstance* apVal);
};

struct TreeLODManager
{
    int unk00;
    TreeBlockArray kBlocks;
    int unk08;
    int unk0C;
    int unk10;
    TreeInstanceMap kInstanceMap;
    int unk18;
    int unk1C;
    int unk20;
    TreeBlockMap kBlockMap;
    void AddTreeInstance(unsigned int auiType, TreeInstance* apInstance);
};

// Finds or creates the tree block for auiType, adds apInstance to it, sets the instance's block index and flag, and registers it in kInstanceMap by ID.
// @fnv 0x006f8470
void TreeLODManager::AddTreeInstance(unsigned int auiType, TreeInstance* apInstance)
{
    AutoMemHelper kMem(0x25, true, str_0106dd30, 0x14b);
    TreeBlock* pBlock = 0;
    bool bFound8 = kBlockMap.GetAt(auiType, pBlock);
    if (!bFound8 || !pBlock || pBlock->kInstances.GetSize() == BSDistantTreeShader_GetMaxInstances())
    {
        if (auiType >= g_TreeTypes.GetSize())
        {
            FNV_Warning("Invalid LOD tree type %i found. TreeTypes file may be out of date or corrupt.", auiType);
            return;
        }
        pBlock = new TreeBlock;
        pBlock->pType = g_TreeTypes.GetType(auiType);
        kBlocks.Add(pBlock);
        kBlockMap.SetAt(auiType, pBlock);
        pBlock->iIndex = kBlocks.GetSize() - 1;
        pBlock->kInstances.SetCapacity(BSDistantTreeShader_GetMaxInstances());
        pBlock->bFull = 0;
    }
    pBlock->kInstances.AddInstance(apInstance);
    int iLast = pBlock->kInstances.GetSize() - 1;
    TreeInstance* pInst6 = pBlock->kInstances.GetInstance(iLast);
    pInst6->iBlockIndex = pBlock->iIndex;
    pInst6->bFlag = 0;
    kInstanceMap.SetAt(pInst6->uiID, pInst6);
}


template <class T> struct NiPtrS
{
    T* m_pObject;
    operator T*() const;
    NiPtrS& operator=(T* p);
};



struct RootHolderS
{
    NiNode* GetRootNode();
};

struct SimpleArrS
{
    int unk0;
    int unk4;
    int unk8;
    void Clear(bool abFree);
};

struct TreeBlockEntryS
{
    int unk0;
    NiPtrS<NiAVObject> m_pController;
    SimpleArrS kInstances;
    ~TreeBlockEntryS();
};

struct EntryArrS
{
    TreeBlockEntryS*& GetAt(unsigned int auiIndex);
    unsigned int GetSize();
    void Clear(bool abFree);
};

struct TreeOwnerS
{
    int unk0;
    EntryArrS kEntries;
    NiPtrS<RootHolderS>& GetHolder();
    void ClearEntries();
};

// @fnv 0x006f86e0
void TreeOwnerS::ClearEntries()
{
    for (unsigned int i = 0; i < kEntries.GetSize(); i++)
    {
        kEntries.GetAt(i)->kInstances.Clear(true);
        if (kEntries.GetAt(i)->m_pController)
        {
            ((RootHolderS*)GetHolder())->GetRootNode()->RemoveObject(kEntries.GetAt(i)->m_pController);
            kEntries.GetAt(i)->m_pController = 0;
        }
        delete kEntries.GetAt(i);
    }
    kEntries.Clear(true);
}

struct TreeScopeGuard
{
    void* p;
    TreeScopeGuard(int line, int flags, const char* file, int size);
    ~TreeScopeGuard();
};

struct TreeRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    TreeRecord();
    ~TreeRecord();
};

struct TreeTemp
{
    int v;
    TreeTemp(int v);
};

struct TreeHost
{
    void ReadBytes(void* buf, unsigned int n);
};

// Reads a 4-byte record count from the host, then reads and processes that many 0x20-byte TreeRecords.
// @fnv 0x006f8f80
void ReadTreeRecords(TreeHost* host)
{
    TreeScopeGuard guardX(
        0x25, 1,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSDistantTreeBlock.cpp",
        0x27e);
    ((FUN_006f9c70_shell*)&g_011d85d0)->BGSDistantTreeBlock_TreeTypes_FreeAll(true);
    unsigned int count = 0;
    host->ReadBytes(&count, 4);
    for (unsigned int i = 0; i < count; i++)
    {
        TreeRecord rec;
        host->ReadBytes(&rec, 0x20);
        TreeTemp tmp(0);
        BGSDistantTreeBlock_TreeTypes_Append(&rec);
    }
}

struct C6F9060Member
{
    int unk00;

    C6F9060Member(int value);
};

struct FUN_006f9060
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C6F9060Member m_kMember;

    FUN_006f9060();
};

// @fnv 0x006f9060
FUN_006f9060::FUN_006f9060() : m_kMember(0)
{}

struct Callee
{
    void FUN_0045cec0();
};

struct FUN_006f9080_owner
{
    char unk1b[0x1c];
    Callee callee;

    void ForwardCall_006f9080();
};

void Callee::FUN_0045cec0()
{}

// @fnv 0x006f9080
// src: GUESS 0x006f9080 (confidence: low)
void FUN_006f9080_owner::ForwardCall_006f9080()
{
    callee.FUN_0045cec0();
}

struct Fake076;
int __cdecl FormatTreeLodDtlPath(char* a1, Fake076* a2, int a3, short a4, short a5);

// Initializes a QueuedFileEntry task for a distant tree block: stores the block, cell coordinates and LOD level, builds a path and sets the task name and flag.
// @fnv 0x006f9360
BGSDistantTreeBlockLoadTask::BGSDistantTreeBlockLoadTask(
    BGSDistantTreeBlock* apBlock, Fake076* apWorld, int aiCellX, int aiCellY, int aiLODLevel, int aiUnused)
    : QueuedFileEntry(3)
{
    *(BGSDistantTreeBlock**)unk30 = apBlock;
    unk30[4] = false;
    iX = aiCellX;
    iY = aiCellY;
    iLevel = aiLODLevel;
    m_bCancelled = false;
    char acPath[260];
    FormatTreeLodDtlPath(acPath, apWorld, aiLODLevel, (short)aiCellX, (short)aiCellY);
    SetFileName_00c3cee0(acPath + 5);
    LookupFileEntry(0);
    m_bLoadComplete = false;
}

// @fnv 0x006f94a0
BGSDistantTreeBlockLoadTask::~BGSDistantTreeBlockLoadTask()
{}

class B6F9570File
{
  public:
    virtual ~B6F9570File();
};

class B6F9570FileFinder
{
  public:
    static B6F9570File* GetFile(const char* pcName, int eMode, unsigned int uiBufferSize, unsigned int uiFlags);
};

class B6F9570TreeBlock
{
  public:
    void ReadGroups(B6F9570File* pkFile);
    void ProcessAllTrees();
};

// Opens the loader's filename as a file, loads it into the tree block if not cancelled, and sets the success flag.
// @fnv 0x006f9570
void BGSDistantTreeBlockLoadTask::Run()
{
    B6F9570File* pkFile = B6F9570FileFinder::GetFile(GetFileName(), 0, 0x800, 1);
    if (pkFile && !m_bCancelled)
    {
        (*(B6F9570TreeBlock**)unk30)->ReadGroups(pkFile);
        delete pkFile;
        m_bLoadComplete = true;
        (*(B6F9570TreeBlock**)unk30)->ProcessAllTrees();
    }
    else
    {
        m_bLoadComplete = false;
    }
}

struct Lod77Foo1
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Lod77Foo1();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct Lod77Foo2
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Lod77Foo2();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct Lod77Elem
{
    void Step0();
    void Step1();
    void Step2();
    void Step3();
    void Step4();
};

struct Lod77Container
{
    void Add(void* p);
    Lod77Elem* Get(int i);
    void* Get0();
};

struct LodFile
{
    virtual ~LodFile();
};

struct Lod77Mgr
{
    void Load(char* path, Lod77Container* c, int a, int b);
};

extern Lod77Container DAT_011d85bc;
extern Lod77Container DAT_011d85c4;
extern Lod77Container DAT_011d85e0;
extern Lod77Mgr* DAT_011dea10;

int __cdecl FUN_00ec8a19(const char* a, const char* b, int c);
void* __cdecl FileFinder_GetFile_(char* path, int mode, unsigned int size);
void __cdecl Warning_005b5e40(const char* msg);

// Builds the TreeTypes.lst mesh path and the tree LOD texture path, loads both, then populates the LOD containers and steps their elements.
// @fnv 0x006f77a0
void __cdecl LoadTreeLodResources(Fake076* self)
{
    char path[0x104];
    LodFile* f5;
    const char* texName;
    char texPath[0x104];

    _sprintf_s(path, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\Trees\\TreeTypes.lst", self->GetStr());
    f5 = (LodFile*)FileFinder_GetFile_(path, 0, 0x800);
    if (f5 != 0)
    {
        ReadTreeRecords((TreeHost*)f5);
        delete f5;
    }

    texName = "TreeDeadLOD.dds";
    if (!FUN_00ec8a19(self->GetStr(), "DLC4", 4))
    {
        texName = "TreeSwampLOD.dds";
    }
    _sprintf_s(texPath, 0x104, "\\Data\\Textures\\Landscape\\Trees\\%s", texName);
    DAT_011dea10->Load(texPath, &DAT_011d85e0, 1, 1);
    if (!DAT_011d85e0.Get0())
    {
        Warning_005b5e40("LOD tree texture atlas not found!");
    }
    BSDistantTreeShader_SetTextureAtlas(DAT_011d85e0.Get0());
    DAT_011d85a0 = 1;

    DAT_011d85bc.Add(new Lod77Foo1());
    DAT_011d85bc.Get(3)->Step0();

    DAT_011d85c4.Add(new Lod77Foo2());
    DAT_011d85c4.Get(1)->Step1();
    DAT_011d85c4.Get(0)->Step2();
    DAT_011d85c4.Get(0x80)->Step3();
    DAT_011d85c4.Get(4)->Step4();
}



struct TreeGeometry
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual NiBound* GetBound();
};
struct TreeGeometryPtr
{
    TreeGeometry* object;
    TreeGeometry* Modelloader_GetReferencedThis();
};
struct TreePositions
{
    unsigned int FUN_0044ddc0();
    NiPoint3* GetElementAt(unsigned int);
};
struct BoundTreeBlock
{
    int unk00;
    TreeGeometryPtr geometry;
    TreePositions instances;
};
float __cdecl BSMIN(float, float);
float __cdecl BSMAX_00404010(float, float);
struct TreeBoundsOwner
{
    NiBound* ComputeTreeBounds(NiBound* result, BoundTreeBlock* block);
};
// Computes the bounding sphere of a tree block: min/max of instance positions, center, and radius including the geometry bound.
// @fnv 0x006f8910
// Expose the original result pointer so the return retains its inline word copy.
NiBound* TreeBoundsOwner::ComputeTreeBounds(NiBound* result, BoundTreeBlock* block)
{
    unsigned int maximum;
    NiBound bound;
    // Local spellings preserve the original MSVC9 /Od stack layout.
    // minimum: largest finite float; count: lower corner; limit: upper corner.
    float minimum = 3.402823466e+38F;
    NiPoint3 count(minimum, minimum, minimum);
    NiPoint3 limit(-minimum, -minimum, -minimum);
    // maximum is the number of instance positions.
    maximum = block->instances.FUN_0044ddc0();
    for (unsigned int i = 0; i < maximum; ++i)
    {
        count.x = BSMIN(count.x, block->instances.GetElementAt(i)->x);
        limit.x = BSMAX_00404010(limit.x, block->instances.GetElementAt(i)->x);
        count.y = BSMIN(count.y, block->instances.GetElementAt(i)->y);
        limit.y = BSMAX_00404010(limit.y, block->instances.GetElementAt(i)->y);
        count.z = BSMIN(count.z, block->instances.GetElementAt(i)->z);
        limit.z = BSMAX_00404010(limit.z, block->instances.GetElementAt(i)->z);
    }
    NiPoint3 center = count + (limit - count).ProcessAndReturnValue_0053d280(2.0f);
    float radius = (limit - center).Length() + block->geometry.Modelloader_GetReferencedThis()->GetBound()->FUN_0084d030();
    bound.SetCenterAndRadius(reinterpret_cast<const NiPoint3&>(center), radius);
    memcpy(result, &bound, sizeof(bound));
    return result;
}

struct UpdateDataX
{
    float time;
    bool a, b;
    int unk08;
    UpdateDataX(float, bool, bool);
};

// Four-float tree LOD sphere (16 bytes); shared Bounds is an eight-float box (32 bytes).
struct TreeLodBoundingSphere
{
    float x, y, z, r;
};
struct NodeX : NiMemObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void Attach(NodeX*, bool);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void SetObjectBound(TreeLodBoundingSphere);
    void SetSize(unsigned int);
    void AttachProperty(void*);
    void Finish();
    void Update(UpdateDataX&);
};
struct NewNodeX : NodeX
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    NewNodeX(void*);
};
struct PropertyX : NiMemObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    PropertyX();
};
// Tree LOD type record has a smart pointer at 0x1c; shared Type is only 12 bytes.
struct TreeLodTypeRecord
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    NiPtrS<void> name;
};
struct EntryX
{
    TreeLodTypeRecord* type;
    NiPtrS<NodeX> node;
    SimpleArrS instances;
};
struct ArrayX
{
    EntryX*& GetAt(unsigned int);
    unsigned int GetSize();
    int unk00, unk04, unk08, unk0c;
};
struct HolderX
{
    NodeX* GetRootNode();
    NodeX* GetMenuRoot();
};
struct OwnerX
{
    int unk00;
    ArrayX entries;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    bool loaded, built;
    NiPtrS<HolderX>& GetHolder();
    void Configure(PropertyX*, EntryX*);
    TreeLodBoundingSphere GetBound(EntryX*);
    void Refresh();
    void BGSDistantTreeBlock_Attach();
};
void __cdecl SetupNode(NodeX*, int, int);
// @fnv 0x006f8c40
// src: COMMUNITY 0x006f8c40
void OwnerX::BGSDistantTreeBlock_Attach()
{
    AutoMemHelper guard(0x25, true, str_0106dd30, 0x240);
    if (loaded && !built)
    {
        for (unsigned int index4 = 0; index4 < entries.GetSize(); ++index4)
        {
            EntryX* aA = entries.GetAt(index4);
            aA->node = new NewNodeX(entries.GetAt(index4)->type->name);
            ((NodeX*)aA->node)->SetSize(((ArrayX*)&aA->instances)->GetSize() * 4);
            PropertyX* propertyA = new PropertyX;
            Configure(propertyA, aA);
            ((NodeX*)aA->node)->AttachProperty(propertyA);
            SetupNode(aA->node, 0, 0);
            ((NodeX*)aA->node)->AttachProperty(((NiPtrS<void>*)&g_011d85bc)->operator void*());
            ((NodeX*)aA->node)->AttachProperty(((NiPtrS<void>*)&g_011d85c4)->operator void*());
            ((HolderX*)GetHolder())->GetRootNode()->Attach(aA->node, true);
            ((NodeX*)aA->node)->Finish();
            UpdateDataX firstUpdate(0.0f, false, false);
            ((NodeX*)aA->node)->Update(firstUpdate);
            UpdateDataX rootUpdate(0.0f, false, false);
            ((HolderX*)GetHolder())->GetMenuRoot()->Update(rootUpdate);
            ((NodeX*)aA->node)->SetObjectBound(GetBound(aA));
            UpdateDataX finalUpdate(0.0f, false, false);
            ((NodeX*)aA->node)->Update(finalUpdate);
        }
        built = true;
    }
    else if (loaded && built)
        Refresh();
}
