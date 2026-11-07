#include "../../../include/NiPointer.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/hkVector4.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/BSStream.h"
#include "../../../include/NiStream.h"
#include "../../../include/BSTreeModel.h"
#include "../../../include/NiAlphaProperty.h"
#include "../../../include/TESModel.h"
#include "../../../include/TESObjectTREE.h"
#include "../../../include/bhkCollisionObject.h"

// src/fallout_shared/speedtree/bstreemodel_o2_nood_nogf_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/fallout_shared/speedtree/bstreemodel.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/fallout_shared/speedtree/bstreemodel.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/speedtree/bstreemodel.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00666f00_shell
{
    int m_04;
    int m_08;
    bool CombatProcedure_GetFinished();
};
struct GlobalObject_0044f440
{
    struct
    {
        float f;
    }* Float();
};
extern GlobalObject_0044f440 g_011d5d14;
float SpeedTree_fTreeForceCS_Get();
struct FUN_006684d0_shell
{
    void SetFields08And0C(int param1, unsigned short param2);
};
struct FUN_006694c0_shell
{
    float fPad0;
    float fPad1;
    float fPad2;
    float fPad3;
    float fPad4;
    float fPad5;
    void SetPad5(float value);
};
struct CSpeedTreeRT
{
    unsigned short GetUnsignedShortValue();
};
struct FUN_006699d0_shell
{
    void* m_NiRefObject;
    void* m_auiShapeKeys;
    void* m_pAuxiliaryObject;
    CSpeedTreeRT* m_pTreeRuntime;
    unsigned short GetUnsignedShort();
};
extern "C" void* __cdecl BSTreeManager_GetInstance(bool);
extern "C" unsigned char __cdecl GetByteAtOffset1B();
unsigned char __cdecl GetByteAtOffset1B();
struct Flt
{
    operator unsigned int() const;
};
struct FUN_0066a630_shell
{
    char m_auiShapeKeys[0x38];
    Flt m_flt;
    void ConvertFloatToUInt();
};
GlobalObject_0044f440 g_011d5c80;
float SpeedTree_fTreeForceMaxBudAngle_Get();
struct S_00666910
{
    void ReleaseStorage_00b03b30();
    void* FUN_00666910(unsigned int);
};
void _Deallocate(void*);
NiAlphaProperty* BSTreeModel_CreateAlphaProperty();
struct RefBase
{
    virtual ~RefBase();
    unsigned int m_uiRefCount;
};

struct TreeData
{
    ~TreeData();
};
struct FUN_00666800 : RefBase
{
    int unk08;
    TreeData* pData;
    ::NiPointer< ::NiObject> spNode10;
    int unk14;
    int unk18;
    ::NiPointer< ::NiObject> spNode1C;
    ::NiPointer< ::NiObject> spNode20;
    int unk24;
    int unk28;
    ::NiPointer< ::NiObject> spNode2C;
    ::NiPointer< ::NiObject> spNode30;
    ::NiPointer< ::NiObject> spNode34;
    ::NiPointer< ::NiObject> spNode38;
    virtual ~FUN_00666800();
    void ReleaseData();
};
struct Point2X
{
    float x, y;
    Point2X();
    Point2X(float afX, float afY);
};
struct ColorAX
{
    float r, g, b, a;
    ColorAX();
    ColorAX(float afR, float afG, float afB, float afA);
};
struct MemObjX
{
    static void* operator new(unsigned int auiSize);
    static void operator delete(void* apMem);
};
struct LeafDataX : public MemObjX
{
    char _pad[0x10];
    LeafDataX();
    void SetFields08And0C(ColorAX* apColors, unsigned short ausCount);
};
struct StripsDataX : public MemObjX
{
    char _pad[0x50];
    StripsDataX(unsigned int a1, NiPoint3* a2, NiPoint3* a3, unsigned int a4, Point2X* a5, unsigned int a6,
                unsigned int a7, unsigned int a8, unsigned int a9, unsigned short* a10, unsigned short* a11);
    void FUN_00a67050(unsigned int auiFlags);
    void SetByteAtOffset38(unsigned char aucFlags);
    void SetCompressFlags(unsigned char aucFlags);
};
struct LeafShapeX : public MemObjX
{
    char _pad[0x108];
    LeafShapeX(LeafDataX* apData);
};
template <class T> struct PtrX
{
    T* m_pObject;
    PtrX();
    PtrX(T* apObject);
    ~PtrX();
    PtrX& operator=(T* apObject);
    operator T*() const;
};
struct GeometryX
{
    int _pad00[2];
    unsigned short* pStripCount;
    unsigned short** ppStrips;
    unsigned short usVertexCount;
    unsigned short _pad12;
    unsigned int* pColors;
    float* pNormals;
    float* pBinormals;
    float* pTangents;
    float* pCoords;
    float* pTexCoords;
    int _pad2c;
    float* pLodFade;
    unsigned char* pWindIndices;
    int _pad38[(0x130 - 0x38) / 4];
    GeometryX();
    ~GeometryX();
};
struct SpeedTreeX
{
    void CSpeedTreeRT_GetGeometry(GeometryX& arGeometry, int a2, int a3, int a4, int a5);
    void UpdateState_00b08750();
    void ProcessState_00b08780();
};
struct UIntArrayX
{
    void* pBase;
    unsigned short usMax;
    unsigned short usSize;
    unsigned short usESize;
    unsigned short usGrow;
    int iActionIndex;
    UIntArrayX(unsigned int auiMax, unsigned int auiGrow);
    ~UIntArrayX();
    unsigned int AddFirstEmpty(const unsigned int& arValue);
    unsigned int GetSize();
    unsigned int* GetAt(unsigned int auiIndex);
};
extern const NiPoint3 xDAT_011a9484;
extern "C" int xIsNaN(double adValue);
extern "C" void* xNiMalloc(unsigned int auiSize);
extern "C" void* xmemcpy(void* apDst, const void* apSrc, unsigned int auiSize);
extern "C" void* xmemset(void* apDst, int aiValue, unsigned int auiSize);
struct TreeModelX
{
    char _pad00[0xc];
    SpeedTreeX* m_pTreeRuntime;
    char _pad10[4];
    PtrX<StripsDataX>* pLeafGeometry;
    char _pad18[0xc];
    PtrX<LeafShapeX>* pLeafShapes;

    bool CombatProcedure_GetFinished();
    unsigned short GetNumBranchLODLevels();
    void BSTreeModel_CreateBranchGeometry();
};
struct ModelHolder_b5531
{
    void FUN_00633c90(unsigned int flags);
    void NiPointer_Empty();
};
struct GlobalObject_0044fae0
{
    void BSCriticalSection_Enter(int);
    void WaitForTasksDuringRendering();
};
extern GlobalObject_0044fae0 g_011d5df8;
extern unsigned char treeCloneActive;
struct TreeCloneProcess
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    TreeCloneProcess(float);
    ~TreeCloneProcess();
};
struct TreeRuntimeCopy
{
    TreeRuntimeCopy* CSpeedTreeRT_MakeInstance();
};
struct TreeCloneView
{
    unsigned int unk00, unk04;
    int initialized;
    TreeRuntimeCopy* runtime;
    NiPointer<TreeCloneView> source;
    NiPointer<NiNode>* branchGeometry;
    NiPointer<NiNode>* leafGeometry;
    NiPointer<NiNode> billboard;
    NiPointer<NiNode> unk20;
    NiPointer<NiNode>* branchNodes;
    NiPointer<NiNode>* leafNodes;
    NiPointer<NiNode> unk2c, unk30, unk34;
    NiPointer<NiNode> collision;
    float unk3c;
    unsigned int unk40, unk44;
    float unk48, unk4c;
    bool CombatProcedure_GetFinished();
    unsigned short GetNumBranchLODLevels();
    unsigned short FUN_006699d0();
    bool CloneFromModel(TreeCloneView*);
};
struct PathingSolutionBase
{
    virtual ~PathingSolutionBase();
    unsigned int refs;
    PathingSolutionBase();
};
struct GlobalObject_00633c90
{
    void* p;
    GlobalObject_00633c90(int);
    ~GlobalObject_00633c90();
    GlobalObject_00633c90& operator=(void*);
};
struct FUN_00666650 : PathingSolutionBase
{
    unsigned int unk08, unk0c;
    GlobalObject_00633c90 a;
    unsigned int unk14, unk18;
    GlobalObject_00633c90 b, c;
    unsigned int unk24, unk28;
    GlobalObject_00633c90 d, e, f, g;
    float unk3c;
    unsigned int unk40;
    bool unk44;
    float unk48, unk4c;
    FUN_00666650();
    virtual ~FUN_00666650();
};
int strcpy_s(char* apDst, unsigned int auiSize, const char* apSrc);
int strcat_s(char* apDst, unsigned int auiSize, const char* apSrc);
template <class T> unsigned int BSStringLength(const T* apString);
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        FILE_NOT_FOUND
    };
    static FILE_LOCATION Exist(const char* apPath, char* apOut, unsigned int auiArg, unsigned int auiArgCur);
};
extern const NiRTTI DAT_011f4280;
NiAVObject* NiDynamicCast(const NiRTTI* apRTTI, NiAVObject* apObject);
struct bhkWorldObject;
bhkCollisionObject* bhkNiCollisionObject_GetbhkNiCollisionObject(NiNode* apNode);
NiNode* __cdecl NiNode_ProcessAndReturnValue_00c81380(float afArg, float afArgCur);
struct ModelName
{
    char acName[0x104];
};
struct FUN_00667190_shell : public TreeCloneView
{
    void BSTreeModel_CreateBranchGeometry();
    void BSTreeModel_CreateLeafGeometry(TESObjectTREE* apTree);
    void BSTreeModel_CreateBillboardGeometry(TESObjectTREE* apTree);
    void LoadTreeCollision(TESObjectTREE* apTree);
};
namespace TreeBuild {
struct Model;
struct Geometry;
struct GeometryData;
struct Object;
struct Property;
struct Shader;
template <class T> struct Handle
{
    T* object;
    Handle(T*);
    ~Handle();
    T* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(T*);
};
struct Scope
{
    int value;
    Scope(int, int, const char*, int);
    ~Scope();
};
extern const char DAT_010667b8[], DAT_01066830[];
extern const double DAT_010240c0, DAT_01012070, DAT_01011590;
struct UpdateData
{
    float time;
    int flags, unk08;
    UpdateData(float, int, int);
};
struct ShaderState
{
    int NiTimeController_GetNext();
    int FUN_005f36f0();
};
struct Property
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
    virtual Shader* CreateShader(Geometry*);
    void FUN_004393c0(int);
    void BSShaderProperty_FreeRenderPasses();
    void BSShaderPPLightingProperty_LoadTextureSet(const char*, Object*);
};
Property* BSTreeModel_CreateAlphaProperty();
void* BSShaderManager_GetShader(int);
struct Geometry
{
    virtual void v0();
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
    static void* operator new(unsigned int);
    static void operator delete(void*);
    Geometry(GeometryData*);
    void NiAVObject_AttachProperty(Property*);
    ShaderState* NiGeometry_GetModelData();
    void NiGeometry_SetAdditionalGeometryData(Shader*);
    void FUN_00874460(void*);
};
struct Leaves : Geometry
{
    Leaves(GeometryData*);
};
struct Renderer
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
    virtual void Prepare(Geometry*, int, int, int);
};
Renderer* NiXenonRenderer_GetRenderer();
void FUN_00b57e30(Geometry*, int, int);
struct Tree
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
    virtual void* GetBranches();
    virtual void v66();
    virtual void* GetLeaves();
    virtual Geometry* GetBranch(unsigned int);
    virtual void v69();
    virtual void v70();
    virtual void SetBranch(unsigned int, Geometry*);
    virtual void SetLeaf(unsigned int, Geometry*);
    virtual void SetBillboardObject(Object*);
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
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    static void* operator new(unsigned int);
    static void operator delete(void*);
    Tree(Model*, Object*);
    void UpdateProperties();
    void FUN_00a59c90(UpdateData*);
    void BSTreeNode_MakeHavokLeaves(void*, float);
};
Object* NiNode_ProcessAndReturnValue_00c81380(float, float);
struct Model
{
    int unk00, unk04, unk08;
    void* model;
    int unk10;
    Handle<GeometryData>* branches;
    Handle<GeometryData>* leaves;
    Handle<Object> billboard;
    int unk20;
    Handle<Property>* branchProperties;
    Handle<Property>* leafProperties;
    Handle<Object> extra;
    int unk30, unk34, unk38, unk3c, unk40, unk44;
    float radius, height;
    Object* ConvertFloatToUInt();
    unsigned short GetNumBranchLODLevels();
    unsigned short FUN_006699d0();
    bool CombatProcedure_GetFinished();
    Tree* CreateTree(float);
};
// @fnv 0x00669fd0
Tree* Model::CreateTree(float scale)
{
    Scope scope(30, 1, DAT_010667b8, 901);
    Tree* tree5 = 0;
    void* unusedB = 0;
    Handle<Object> shape(0);
    if (!model)
        return 0;
    if (radius > DAT_010240c0)
    {
        if (scale == DAT_01012070)
            shape.FUN_0066b0d0(ConvertFloatToUInt());
        else
            shape.FUN_0066b0d0(NiNode_ProcessAndReturnValue_00c81380(scale * radius, scale * height / DAT_01011590));
    }
    else
        shape.FUN_0066b0d0(0);
    tree5 = new Tree(this, shape.Modelloader_GetReferencedThis());
    unsigned short count3;
    unsigned short i;
    void* shader;
    Geometry* geometryX;
    Property* alpha;
    if (branches && branchProperties)
    {
        count3 = GetNumBranchLODLevels();
        shader = BSShaderManager_GetShader(4);
        unusedB = tree5->GetBranches();
        for (i = 0; i < count3; i++)
        {
            if (!branches[i].Modelloader_GetReferencedThis())
                continue;
            geometryX = new Geometry(branches[i].Modelloader_GetReferencedThis());
            alpha = BSTreeModel_CreateAlphaProperty();
            if (alpha)
            {
                alpha->FUN_004393c0(0);
                geometryX->NiAVObject_AttachProperty(alpha);
            }
            if (branchProperties[i].Modelloader_GetReferencedThis())
            {
                branchProperties[i].Modelloader_GetReferencedThis()->BSShaderProperty_FreeRenderPasses();
                geometryX->NiAVObject_AttachProperty(branchProperties[i].Modelloader_GetReferencedThis());
                if (!geometryX->NiGeometry_GetModelData()->NiTimeController_GetNext())
                {
                    Shader* created = branchProperties[i].Modelloader_GetReferencedThis()->CreateShader(geometryX);
                    geometryX->NiGeometry_SetAdditionalGeometryData(created);
                }
            }
            if (CombatProcedure_GetFinished())
                geometryX->FUN_00874460(shader);
            tree5->SetBranch(i, geometryX);
        }
        if (!CombatProcedure_GetFinished())
        {
            for (i = 0; i < count3; i++)
            {
                geometryX = tree5->GetBranch(i);
                if (!geometryX)
                    continue;
                branchProperties[i].Modelloader_GetReferencedThis()->BSShaderPPLightingProperty_LoadTextureSet(DAT_01066830, extra.Modelloader_GetReferencedThis());
                FUN_00b57e30(geometryX, 0, 0);
                geometryX->NiGeometry_SetAdditionalGeometryData(branchProperties[i].Modelloader_GetReferencedThis()->CreateShader(geometryX));
                if (!geometryX->NiGeometry_GetModelData()->FUN_005f36f0())
                    NiXenonRenderer_GetRenderer()->Prepare(geometryX, 0, 0, 0);
            }
        }
    }
    if (leaves && leafProperties)
    {
        count3 = FUN_006699d0();
        shader = BSShaderManager_GetShader(6);
        for (i = 0; i < count3; i++)
        {
            if (!leaves[i].Modelloader_GetReferencedThis())
                continue;
            geometryX = new Leaves(leaves[i].Modelloader_GetReferencedThis());
            alpha = BSTreeModel_CreateAlphaProperty();
            if (alpha)
                geometryX->NiAVObject_AttachProperty(alpha);
            if (leafProperties[i].Modelloader_GetReferencedThis())
            {
                leafProperties[i].Modelloader_GetReferencedThis()->BSShaderProperty_FreeRenderPasses();
                geometryX->NiAVObject_AttachProperty(leafProperties[i].Modelloader_GetReferencedThis());
            }
            tree5->SetLeaf(i, geometryX);
            geometryX->FUN_00874460(shader);
            NiXenonRenderer_GetRenderer()->Prepare(geometryX, 0, 0, 0);
        }
    }
    unusedB = tree5->GetLeaves();
    if (billboard.Modelloader_GetReferencedThis())
        tree5->SetBillboardObject(billboard.Modelloader_GetReferencedThis());
    tree5->UpdateProperties();
    UpdateData update(0.0f, 0, 0);
    tree5->FUN_00a59c90(&update);
    tree5->BSTreeNode_MakeHavokLeaves(model, scale);
    return tree5;
}
}

struct __declspec(align(16)) CapsuleParams
{
    int flags;
    float radius;
    int unk08, unk0c;
    hkVector4 endpoints[2];
};
struct FUN_0066d6a0 : MemObjX
{
    int unk00, unk04;
    void* shape;
    int unk0c, material;
    FUN_0066d6a0(CapsuleParams*);
};
struct AllocatorC813
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*, int);
};
struct MemoryC813
{
    int unk00, unk04, unk08, unk0c;
    AllocatorC813* allocator;
    AllocatorC813& heap()
    {
        return *allocator;
    }
};
MemoryC813* hkMemoryRouter_getInstance();
struct __declspec(align(16)) FUN_00c8f510
{
    int filter00;
    void* shape04;
    int unk08;
    void* data;
    int size;
    int capacity;
    int unk18;
    int unk1c;
    int filter20;
    void* shape24;
    int unk28;
    int unk2c;
    hkVector4 position;
    hkVector4 rotation;
    hkVector4 linearVelocity;
    hkVector4 angularVelocity;
    hkVector4 inertiaTensor[3];
    hkVector4 centerOfMass;
    float valueb0;
    int unkb4;
    int unkb8;
    int unkbc;
    float valuec0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    unsigned char motion, unkD5, unkD6, unkD7;
    int unkd8;
    int unkdc;
    FUN_00c8f510();
    void ClearAndRelease(AllocatorC813& alloc)
    {
        size = 0;
        if ((capacity & 0x80000000) == 0)
            alloc.Free(data, (capacity & 0x3fffffff) * 8);
    }
    ~FUN_00c8f510()
    {
        ClearAndRelease(hkMemoryRouter_getInstance()->heap());
    }
};
struct FUN_0056d380 : MemObjX
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    FUN_0056d380(FUN_00c8f510*);
};
extern float DAT_01267e44;
extern float DAT_01018180;
// hkVector4 has a constructor, so retain /GS coverage for the capsule buffer.
#pragma strict_gs_check(push, on)
// @fnv 0x00c81380
// src: GUESS 0x00c81380 (confidence: low)
NiNode* __cdecl NiNode_ProcessAndReturnValue_00c81380(float a, float b)
{
    CapsuleParams params;
    params.endpoints[0].m_vComponents.m128_f32[3] = 0.0f;
    params.endpoints[1].m_vComponents.m128_f32[3] = 0.0f;
    params.flags = 0;
    if (a <= b * 2.0f)
        a = (float)(b * 2.0f + 1.0);
    params.radius = DAT_01267e44 * b;
    params.endpoints[0].m_vComponents.m128_f32[0] = 0.0f;
    params.endpoints[0].m_vComponents.m128_f32[1] = 0.0f;
    float delta = a - b;
    params.endpoints[0].m_vComponents.m128_f32[2] = delta * DAT_01267e44;
    params.endpoints[1].m_vComponents.m128_f32[0] = 0.0f;
    params.endpoints[1].m_vComponents.m128_f32[1] = 0.0f;
    params.endpoints[1].m_vComponents.m128_f32[2] = params.radius;
    NiNode* result = 0;
    FUN_0066d6a0* desc = new FUN_0066d6a0(&params);
    if (desc)
    {
        desc->material = 9;
        FUN_00c8f510 block;
        void* shape = desc->shape;
        block.valueb0 = 0.0f;
        block.valuec0 = DAT_01018180;
        block.motion = 5;
        block.filter00 = 0x40009;
        block.filter20 = 0x40009;
        block.shape04 = shape;
        block.shape24 = shape;
        FUN_0056d380* obj = new FUN_0056d380(&block);
        result = (NiNode*)obj;
    }
    return result;
}
#pragma strict_gs_check(pop)
