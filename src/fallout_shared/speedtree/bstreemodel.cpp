#include "../../../include/NiPointer.h"
#include "../../../include/BSStringT.h"
// the shared NiTArray first: NiNode.h then takes it (its own copy is only for units without one)
#include "../../../include/NiMemObject.h"
#include "../../../include/NiTArray.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiGeometry.h"
#include "../../../include/Setting.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TES.h"
#include "../../../include/BSMultiBoundSphere.h"
#include "../../../include/BSShaderTextureSet.h"
#include "../../../include/BSStream.h"
#include "../../../include/NiStream.h"
#include "../../../include/TESModel.h"
#include "../../../include/BSTreeModel.h"
#include "../../../include/NiPoint2.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/TESObjectTREE.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/NP.h"
#include "../../../include/NiTexture.h"
#include "../../../include/bhkCollisionObject.h"
#include "../../../include/NiAlphaProperty.h"

// src/fallout_shared/speedtree/bstreemodel.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/speedtree/bstreemodel.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Runs the destructor and, when bit 0 of flags is set, frees the object with operator delete, then returns this.
// @fnv 0x006667d0
void* BSTreeModel::DestroyAndFree(unsigned int flags)
{
    BSTreeModel::~BSTreeModel();
    if (flags & 1)
        BSTreeModel::operator delete(this, 0x50);
    return this;
}

// BSTreeModel.h still lacks the state/LOD methods and geometry fields used by the remaining model views.
struct FUN_00666f00_shell
{
    int m_04;
    int m_08;
    bool CombatProcedure_GetFinished();
};

// @fnv 0x00666f00
// src: XBOX_PDB 0x00666f00
bool FUN_00666f00_shell::CombatProcedure_GetFinished()
{
    return *(int*)(this + 1) == 2;
}

extern Setting g_011d5d14;

// @fnv 0x00666f20
// src: COMMUNITY 0x00666f20
float SpeedTree_fTreeForceCS_Get()
{
    return *g_011d5d14.Float();
}

namespace fnv_00666f40 {
extern Setting g_011d5db8;

// @fnv 0x00666f40
// src: COMMUNITY 0x00666f40
float SpeedTree_fTreeForceBranchDimming_Get()
{
    return *g_011d5db8.Float();
}
}  // namespace fnv_00666f40

namespace fnv_00666f60 {
extern Setting g_011d5d24;

// @fnv 0x00666f60
// src: COMMUNITY 0x00666f60
float SpeedTree_fTreeForceLeafDimming_Get()
{
    return *g_011d5d24.Float();
}
}  // namespace fnv_00666f60

namespace fnv_00666f80 {
extern Setting g_011d5c9c;

// @fnv 0x00666f80
// src: COMMUNITY 0x00666f80
float SpeedTree_fTreeForceMinBudAngle_Get()
{
    return g_011d5c9c.Float()[0];
}
}  // namespace fnv_00666f80

struct FUN_006684d0_shell
{
    void SetFields08And0C(int param1, unsigned short param2);
};

// Stores param1 at offset 8 and param2 at offset 0xC of this object.
// @fnv 0x006684d0
// src: GUESS 0x006684d0 (confidence: medium)
void FUN_006684d0_shell::SetFields08And0C(int param1, unsigned short param2)
{
    *(int*)((char*)this + 8) = param1;
    *(unsigned short*)((char*)this + 0xC) = param2;
}

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

// @fnv 0x006694c0
void FUN_006694c0_shell::SetPad5(float value)
{
    fPad5 = value;
}

struct CSpeedTreeRT
{
    unsigned short GetLowWordAtOffset0x78();
    unsigned short GetUnsignedShortValue();
};

// @fnv 0x00669990
// src: XBOX_PDB 0x00669990
unsigned short BSTreeModel::GetNumBranchLODLevels()
{
    return m_pTreeRuntime ? m_pTreeRuntime->GetLowWordAtOffset0x78() : 0;
}

struct FUN_006699d0_shell
{
    void* m_NiRefObject;
    void* m_auiShapeKeys;
    void* m_pAuxiliaryObject;
    CSpeedTreeRT* m_pTreeRuntime;
    unsigned short GetUnsignedShort();
};

// @fnv 0x006699d0
unsigned short FUN_006699d0_shell::GetUnsignedShort()
{
    return m_pTreeRuntime ? m_pTreeRuntime->GetUnsignedShortValue() : 0;
}

extern "C" void* __cdecl BSTreeManager_GetInstance(bool);

extern "C" unsigned char __cdecl GetByteAtOffset1B();

// @fnv 0x00669fb0
unsigned char __cdecl GetByteAtOffset1B()
{
    return ((unsigned char*)BSTreeManager_GetInstance(true))[0x1B];
}

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

// @fnv 0x0066a630
void FUN_0066a630_shell::ConvertFloatToUInt()
{
    m_flt.operator unsigned int();
}

extern Setting g_011d5c80;

// @fnv 0x00666fa0
// src: COMMUNITY 0x00666fa0
float SpeedTree_fTreeForceMaxBudAngle_Get()
{
    return *g_011d5c80.Float();
}

struct S_00666910
{
    void ReleaseStorage_00b03b30();
    void* FUN_00666910(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_00b03b30, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x00666910
void* S_00666910::FUN_00666910(unsigned int flags)
{
    ReleaseStorage_00b03b30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// The shared unsized operator delete changes the constructor-failure unwind at 0x00f001c0.
// @fnv 0x006698f0
// src: COMMUNITY 0x006698f0
NiAlphaProperty* BSTreeModel_CreateAlphaProperty()
{
    NiAlphaProperty* pAlphaProperty = new NiAlphaProperty;
    pAlphaProperty->NiAlphaProperty_SetAlphaBlending(false);
    pAlphaProperty->SetFlag512(true);
    pAlphaProperty->SetFlags(4);
    pAlphaProperty->NiAlphaProperty_SetTestRef(0x54);
    return pAlphaProperty;
}

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
// Releases the object's data and deletes pData, clearing the pointer.
// @fnv 0x00666800
FUN_00666800::~FUN_00666800()
{
    ReleaseData();
    if (pData)
    {
        delete pData;
        pData = 0;
    }
}

struct ColorAX
{
    float r, g, b, a;
    ColorAX();
    ColorAX(float afR, float afG, float afB, float afA);
};

struct MemObjX
{
    static void* operator new(unsigned int auiSize);
    static void operator delete(void* apMem, unsigned int);
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
    StripsDataX(unsigned int a1, NiPoint3* a2, NiPoint3* a3, unsigned int a4, NiPoint2* a5, unsigned int a6,
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

// Rebuilds per-LOD leaf geometry and shapes from the SpeedTree geometry, remapping strip indices and copying vertex, normal, tangent, texcoord and color data.
// @fnv 0x00667470
// src: XBOX_PDB 0x00667470
void TreeModelX::BSTreeModel_CreateBranchGeometry()
{
    unsigned int qfTOqo;
    unsigned short qsSDDgz;
    unsigned short qrEZrs;
    GeometryX qpqRa;
    unsigned short qSVM;
    unsigned short qdqWL;
    if (!m_pTreeRuntime || CombatProcedure_GetFinished())
    {
        return;
    }
    if (pLeafGeometry)
    {
        delete[] pLeafGeometry;
        pLeafGeometry = 0;
    }
    if (pLeafShapes)
    {
        delete[] pLeafShapes;
        pLeafShapes = 0;
    }
    qdqWL = GetNumBranchLODLevels();
    if (qdqWL <= 0)
    {
        return;
    }
    m_pTreeRuntime->CSpeedTreeRT_GetGeometry(qpqRa, 1, -1, -1, -1);
    if (!qpqRa.pCoords || !qpqRa.pNormals || !qpqRa.pTexCoords || !qpqRa.pColors || !qpqRa.pLodFade ||
        !qpqRa.pWindIndices)
    {
        return;
    }
    qSVM = qpqRa.usVertexCount;
    if (qSVM <= 0)
    {
        return;
    }
    pLeafGeometry = new PtrX<StripsDataX>[qdqWL];
    pLeafShapes = new PtrX<LeafShapeX>[qdqWL];
    for (qsSDDgz = 0; qsSDDgz < qdqWL; qsSDDgz++)
    {
        pLeafGeometry[qsSDDgz] = 0;
        pLeafShapes[qsSDDgz] = 0;
    }
    if (qpqRa.pTangents && qpqRa.pBinormals)
    {
        NiPoint3* qxQHW = (NiPoint3*)qpqRa.pNormals;
        for (int qJDuOZ = 0; qJDuOZ < qSVM; qJDuOZ++)
        {
            NiPoint3 qpia = qxQHW[qJDuOZ];
            if (xIsNaN(qpia.x) || xIsNaN(qpia.y) || xIsNaN(qpia.z))
            {
                qxQHW[qJDuOZ] = xDAT_011a9484;
            }
        }
    }
    for (qsSDDgz = 0; qsSDDgz < qdqWL; qsSDDgz++)
    {
        m_pTreeRuntime->CSpeedTreeRT_GetGeometry(qpqRa, 1, qsSDDgz, -1, -1);
        qSVM = qpqRa.usVertexCount;
        if (qSVM <= 0 || !qpqRa.pStripCount || !qpqRa.ppStrips)
        {
            continue;
        }
        unsigned short* qCihG = (unsigned short*)xNiMalloc(2);
        *qCihG = *qpqRa.pStripCount;
        unsigned short* qDpUK = (unsigned short*)xNiMalloc(*qCihG * 2);
        xmemcpy(qDpUK, *qpqRa.ppStrips, *qCihG * 2);
        unsigned char* qpDOY = new unsigned char[qpqRa.usVertexCount];
        xmemset(qpDOY, 0, qpqRa.usVertexCount);
        for (qfTOqo = 0; qfTOqo < *qCihG; qfTOqo++)
        {
            qpDOY[qDpUK[qfTOqo]] = 1;
        }
        UIntArrayX qEMUOs(0, 1);
        for (qrEZrs = 0; qrEZrs < qpqRa.usVertexCount; qrEZrs++)
        {
            if (qpDOY[qrEZrs])
            {
                qEMUOs.AddFirstEmpty(qrEZrs);
            }
        }
        delete[] qpDOY;
        for (qrEZrs = 0; qrEZrs < qEMUOs.GetSize(); qrEZrs++)
        {
            unsigned int qbfQdhM = *qEMUOs.GetAt(qrEZrs);
            for (qfTOqo = 0; qfTOqo < *qCihG; qfTOqo++)
            {
                if ((*qpqRa.ppStrips)[qfTOqo] == qbfQdhM)
                {
                    qDpUK[qfTOqo] = qrEZrs;
                }
            }
        }
        NiPoint3* qArJcY = new NiPoint3[qEMUOs.GetSize()];
        NiPoint2* qYTC = new NiPoint2[qEMUOs.GetSize()];
        NiPoint3* qIpA = 0;
        NiPoint3* qMBds = 0;
        NiPoint3* qqtISP = 0;
        bool qdKdHaf;
        if (qpqRa.pTangents && qpqRa.pBinormals)
        {
            qIpA = new NiPoint3[qEMUOs.GetSize() * 3];
            qqtISP = qIpA + qEMUOs.GetSize();
            qMBds = qIpA + qEMUOs.GetSize() * 2;
            qdKdHaf = true;
        }
        else
        {
            qIpA = new NiPoint3[qEMUOs.GetSize()];
            qdKdHaf = false;
        }
        for (qrEZrs = 0; qrEZrs < qEMUOs.GetSize(); qrEZrs++)
        {
            unsigned int qxDeKK = *qEMUOs.GetAt(qrEZrs);
            int qYePyBl = qxDeKK * 3;
            int qAvPUtC = qxDeKK * 3 + 1;
            int qUfv = qxDeKK * 3 + 2;
            int qOqnE = qxDeKK * 2;
            int qAXSCg = qxDeKK * 2 + 1;
            qArJcY[qrEZrs] = NiPoint3(qpqRa.pCoords[qYePyBl], qpqRa.pCoords[qAvPUtC], qpqRa.pCoords[qUfv]);
            qIpA[qrEZrs] = NiPoint3(qpqRa.pNormals[qYePyBl], qpqRa.pNormals[qAvPUtC], qpqRa.pNormals[qUfv]);
            qYTC[qrEZrs] = NiPoint2(qpqRa.pTexCoords[qOqnE], qpqRa.pTexCoords[qAXSCg]);
            if (qdKdHaf)
            {
                qMBds[qrEZrs] = NiPoint3(qpqRa.pTangents[qYePyBl], qpqRa.pTangents[qAvPUtC], qpqRa.pTangents[qUfv]);
                qqtISP[qrEZrs] = NiPoint3(qpqRa.pBinormals[qYePyBl], qpqRa.pBinormals[qAvPUtC], qpqRa.pBinormals[qUfv]);
            }
        }
        ColorAX* qXMUYT = new ColorAX[qEMUOs.GetSize()];
        for (qrEZrs = 0; qrEZrs < qEMUOs.GetSize(); qrEZrs++)
        {
            unsigned int qBLsiu = *qEMUOs.GetAt(qrEZrs);
            float qYdAnhh = ((qpqRa.pColors[qBLsiu] & 0xff00) >> 8) / 255.0;
            qXMUYT[qrEZrs] = ColorAX(qpqRa.pLodFade[qBLsiu], (float)(qpqRa.pWindIndices[qBLsiu] * 4), qYdAnhh, 0.0f);
        }
        PtrX<LeafDataX> qCFhl(new LeafDataX);
        ((LeafDataX*)qCFhl)->SetFields08And0C(qXMUYT, qEMUOs.GetSize());
        pLeafGeometry[qsSDDgz] = new StripsDataX(qEMUOs.GetSize(), qArJcY, qIpA, 0, qYTC, 1, qdKdHaf ? 0x1000 : 0,
                                                 *qpqRa.pStripCount - 2, 1, qCihG, qDpUK);
        ((StripsDataX*)pLeafGeometry[qsSDDgz])->FUN_00a67050(0x4000);
        ((StripsDataX*)pLeafGeometry[qsSDDgz])->SetByteAtOffset38(0x11);
        ((StripsDataX*)pLeafGeometry[qsSDDgz])->SetCompressFlags(1);
        pLeafShapes[qsSDDgz] = new LeafShapeX(qCFhl);
    }
    m_pTreeRuntime->UpdateState_00b08750();
    qpqRa.pColors = 0;
    m_pTreeRuntime->ProcessState_00b08780();
    qpqRa.pLodFade = 0;
    qpqRa.pWindIndices = 0;
}

struct ModelHolder_b5531
{
    void FUN_00633c90(unsigned int flags);
    void NiPointer_Empty();
};

// @fnv 0x006694e0
// src: COMMUNITY 0x006694e0
void ModelHolder_b5531::NiPointer_Empty()
{
    FUN_00633c90(0);
}

namespace fnv_00669500 {

struct SavedState
{
    int unk00;
    int unk04;
    int unk08;
};

void __cdecl SaveState(SavedState* a, SavedState* b);
void __cdecl RestoreState(SavedState* a, SavedState* b);

struct LocalCamera
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    LocalCamera();
    ~LocalCamera();
};

struct TreeData
{
    void SetAlpha(float value);
};



using ::NiPointer;

struct NiProp
{
    int unk00;
};


struct TreeGeom
{
    int GetType();
    void* GetSkin();
};

// 0x004030b0 is NiGeometry::GetGeometryShaderObject (shader at 0xC0), not a NiNode child accessor.

struct TexturingProp
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    TexturingProp(NiTexture* tex);
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int);
};

struct ShaderProp
{
    ShaderProp();
    virtual void v00();
    void SetName(const char* prefix, const char* name);
    void SetFlag(unsigned int flag, bool on);
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int);
};

struct ShaderPropV
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void SetE4(int a);
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void Set100(int a, void* b);
    ShaderPropV();
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    void SetName(const char* prefix, const char* name);
    void SetFlag(unsigned int flag, bool on);
};

struct Renderer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void PrecacheGeometry(NiGeometry* node, int a, int b, void* skin);
    void PerformPrecache();
};

Renderer* GetRenderer();
NiAlphaProperty* CreateAlphaProp();
void* GetShaderDefault();
void __cdecl UpdateNode(NiGeometry* node, int a, int b);

struct LoaderX
{
    void LoadTexture(int a, NiPointer<NiTexture>* out);
};

struct TreeModelX
{
    int unk00;
    int unk04;
    int unk08;
    TreeData* unk0c;
    int unk10;
    int unk14;
    int unk18;
    NiPointer<NiGeometry> m_pController;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    ::BSStringT<char> name;
    bool CombatProcedure_GetFinished();
    void BSTreeModel_CreateBillboardGeometry(LoaderX* loader);
};

// Loads a texture, builds a TexturingProp node with alpha and shader properties, updates it, and precaches its geometry if a valid TreeGeom is found.
// @fnv 0x00669500
// src: XBOX_PDB 0x00669500
void TreeModelX::BSTreeModel_CreateBillboardGeometry(LoaderX* loader)
{
    LocalCamera camera;
    // These raw camera-state vectors must not run the shared point default constructor.
    float origin_2[3];
    origin_2[0] = 0.0f;
    origin_2[1] = 0.0f;
    origin_2[2] = 0.0f;
    float dir5[3];
    dir5[0] = 0.0f;
    dir5[1] = -1.0f;
    dir5[2] = 0.0f;
    if (!unk0c || CombatProcedure_GetFinished() || !loader)
        return;
    SavedState saveA2;
    SavedState saveB;
    SaveState(&saveA2, &saveB);
    RestoreState((SavedState*)&origin_2, (SavedState*)&dir5);
    unk0c->SetAlpha(0.0f);
    NiPointer<NiTexture> spTexA(0);
    loader->LoadTexture(0, &spTexA);
    ((NiTexture*)spTexA)->SetFlag4000(0x4000);
    ((NiTexture*)spTexA)->SetApply(0x11);
    ((NiTexture*)spTexA)->SetFilter(1);
    m_pController = (NiGeometry*)new TexturingProp(spTexA);
    NiPointer<NiAlphaProperty> spAlpha_2(CreateAlphaProp());
    if (spAlpha_2)
        ((NiGeometry*)m_pController)->AttachProperty((NiAlphaProperty*)spAlpha_2);
    ShaderPropV* shader = new ShaderPropV();
    ((NiGeometry*)m_pController)->AttachProperty((NiObject*)shader);
    shader->SetName("STBB", name);
    shader->Set100(0, GetShaderDefault());
    shader->SetE4(0);
    shader->SetFlag(0xd, true);
    shader->SetFlag(0x16, true);
    UpdateNode(m_pController, 0, 0);
    TreeGeom* first2 = (TreeGeom*)((NiGeometry*)m_pController)->GetGeometryShaderObject();
    TreeGeom* geom = !first2 ? 0 : ((first2->GetType() >= 1 && first2->GetType() <= 5) ? first2 : 0);
    if (geom)
    {
        GetRenderer()->PrecacheGeometry(m_pController, 0, 0, geom->GetSkin());
        GetRenderer()->PerformPrecache();
    }
    RestoreState(&saveA2, &saveB);
}
}  // namespace fnv_00669500

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

template <class T> struct TreeModelPointer
{
    T* object;
    TreeModelPointer();
    ~TreeModelPointer();
    TreeModelPointer& operator=(const TreeModelPointer&);
    TreeModelPointer& operator=(T*);
    operator T*();
    static void* operator new[](unsigned int);
    static void operator delete[](void*);
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
    TreeModelPointer<TreeCloneView> source;
    TreeModelPointer<NiNode>* branchGeometry;
    TreeModelPointer<NiNode>* leafGeometry;
    TreeModelPointer<NiNode> billboard;
    TreeModelPointer<NiNode> unk20;
    TreeModelPointer<NiNode>* branchNodes;
    TreeModelPointer<NiNode>* leafNodes;
    TreeModelPointer<NiNode> unk2c, unk30, unk34;
    TreeModelPointer<NiNode> collision;
    float unk3c;
    unsigned int unk40, unk44;
    float unk48, unk4c;
    bool CombatProcedure_GetFinished();
    unsigned short GetNumBranchLODLevels();
    unsigned short FUN_006699d0();
    bool CloneFromModel(TreeCloneView*);
};
// @fnv 0x0066a650
bool TreeCloneView::CloneFromModel(TreeCloneView* model)
{
    g_011d5df8.BSCriticalSection_Enter(0);
    AutoMemContext context_2(
        31, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeModel.cpp", 1041);
    if (!model || !model->runtime || model->CombatProcedure_GetFinished() || initialized)
    {
        g_011d5df8.WaitForTasksDuringRendering();
        return false;
    }
    runtime = model->runtime->CSpeedTreeRT_MakeInstance();
    if (!runtime)
    {
        g_011d5df8.WaitForTasksDuringRendering();
        return false;
    }
    source = model;
    initialized = 2;
    unk2c = model->unk2c;
    unk30 = model->unk30;
    unk34 = model->unk34;
    unk20 = model->unk20;
    unk3c = model->unk3c;
    unk40 = model->unk40;
    unk48 = model->unk48;
    unk4c = model->unk4c;
    if (model->collision)
    {
        TreeCloneProcess process(1.0f);
        collision = static_cast<NiNode*>(model->collision)->CloneWithProcess(&process);
    }
    else
        collision = 0;
    unsigned short index;
    unsigned short count4 = GetNumBranchLODLevels();
    if (count4 > 0 && model->branchGeometry && model->branchNodes)
    {
        branchGeometry = new TreeModelPointer<NiNode>[count4];
        branchNodes = new TreeModelPointer<NiNode>[count4];
        for (index = 0; index < count4; ++index)
        {
            branchGeometry[index] = model->branchGeometry[index];
            if (model->branchNodes[index])
                branchNodes[index] = static_cast<NiNode*>(model->branchNodes[index])->Clone();
            else
                branchNodes[index] = 0;
        }
    }
    count4 = FUN_006699d0();
    if (count4 > 0 && model->leafGeometry && model->leafNodes)
    {
        leafGeometry = new TreeModelPointer<NiNode>[count4];
        leafNodes = new TreeModelPointer<NiNode>[count4];
        for (index = 0; index < count4; ++index)
        {
            leafGeometry[index] = model->leafGeometry[index];
            if (model->leafNodes[index])
                leafNodes[index] = static_cast<NiNode*>(model->leafNodes[index])->Clone();
            else
                leafNodes[index] = 0;
        }
    }
    if (model->billboard)
    {
        treeCloneActive = 1;
        billboard = static_cast<NiNode*>(model->billboard)->Clone();
        treeCloneActive = 0;
    }
    g_011d5df8.WaitForTasksDuringRendering();
    return true;
}

namespace fnv_0066ac40 {
extern const char treePrefix[];
int CopyTreeString(char*, unsigned int, const char*);
int AppendTreeString(char*, unsigned int, const char*);
void Warning_005b5e40(const char*, ...);
float BSTreeManager_GetSizeConversion();
float fTreeFarDistanceBase_Get();
float fTreeNearDistance_Get();
struct FUN_00b02e20
{
    unsigned int unk00;
    unsigned int leafMaps;
    unsigned int unk08, unk0c, unk10, unk14, unk18;
    FUN_00b02e20();
    ~FUN_00b02e20();
};
struct CSpeedTreeRT_Load
{
    unsigned int unk00;
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
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    CSpeedTreeRT_Load();
    static void* operator new(unsigned int);
    ~CSpeedTreeRT_Load();
    bool CSpeedTreeRT_LoadTree(const char*);
    void GetTextures_00b0d040(FUN_00b02e20*);
    void CSpeedTreeRT_SetLeafRockingState(int);
    void SetField14(bool);
    void CSpeedTreeRT_GetTreeSize(float*, float*);
    void CSpeedTreeRT_SetTreeSize(float, float);
    float CSpeedTreeRT_SetWindStrength(float, float, float);
    void CSpeedTreeRT_SetLocalMatrices(int, int);
    void FUN_00984f60(bool);
    void CSpeedTreeRT_SetBranchWindMethod(int);
    void CSpeedTreeRT_SetFrondWindMethod(int);
    void CSpeedTreeRT_SetLeafWindMethod(int);
    void CSpeedTreeRT_SetBranchLightingMethod(int);
    void CSpeedTreeRT_SetFrondLightingMethod(int);
    void CSpeedTreeRT_SetLeafLightingMethod(int);
    void CSpeedTreeRT_SetNearFarDists(float, float);
    bool CSpeedTreeRT_Compute(int, int, bool);
    void ReleaseStorage_00b087d0();
    unsigned int CSpeedTreeRT_GetSeed();
    float GetNestedFloatOrZero_00b07440();
    float GetNestedFloatOrZero();
    void CSpeedTreeRT_DeleteTransientData();
    void DeleteBranchGeometry();
    void CSpeedTreeRT_DeleteFrondGeometry();
};
struct TreeName
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual const char* Name();
};
struct TreeModelInput
{
    unsigned int unk00;
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
    TreeName name;
};
struct TreeModelLoader
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void Setup(TreeModelInput*);
    virtual void slot5();
    virtual void Finish(TreeModelInput*);
    int unk04;
    int initialized;
    CSpeedTreeRT_Load* tree;
    unsigned int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40;
    unsigned int unk44;
    float unk48, unk4c;
    bool BSTreeModel_InitFromBase(TreeModelInput*, int);
};
// @fnv 0x0066ac40
// src: COMMUNITY 0x0066ac40
bool TreeModelLoader::BSTreeModel_InitFromBase(TreeModelInput* model, int seed)
{
    if (model && model->name.Name() && *model->name.Name() && !initialized)
    {
        AutoMemContext context4(
            31, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeModel.cpp", 1139);
        char szPath[260];
        CopyTreeString(szPath, 260, treePrefix);
        AppendTreeString(szPath, 260, model->name.Name());
        CSpeedTreeRT_Load* pTree = new CSpeedTreeRT_Load;
        if (pTree->CSpeedTreeRT_LoadTree(szPath))
        {
            FUN_00b02e20 treeInfo;
            pTree->GetTextures_00b0d040(&treeInfo);
            if (treeInfo.leafMaps <= 3)
                pTree->CSpeedTreeRT_SetLeafRockingState(2);
            else
            {
                pTree->CSpeedTreeRT_SetLeafRockingState(1);
                if (treeInfo.leafMaps > 6)
                    Warning_005b5e40(
                        "MODELS: Tree %s has too many leaf maps (greater than six).  Leaves may not display properly.",
                        model->name.Name());
            }
            pTree->SetField14(true);
            float sizeB, variance;
            pTree->CSpeedTreeRT_GetTreeSize(&sizeB, &variance);
            pTree->CSpeedTreeRT_SetTreeSize(sizeB * BSTreeManager_GetSizeConversion(), variance * BSTreeManager_GetSizeConversion());
            pTree->CSpeedTreeRT_SetWindStrength(0.0f, -1.0f, -1.0f);
            pTree->CSpeedTreeRT_SetLocalMatrices(0, 4);
            pTree->FUN_00984f60(true);
            pTree->CSpeedTreeRT_SetBranchWindMethod(0);
            pTree->CSpeedTreeRT_SetFrondWindMethod(0);
            pTree->CSpeedTreeRT_SetLeafWindMethod(0);
            pTree->CSpeedTreeRT_SetBranchLightingMethod(0);
            pTree->CSpeedTreeRT_SetFrondLightingMethod(0);
            pTree->CSpeedTreeRT_SetLeafLightingMethod(0);
            pTree->CSpeedTreeRT_SetNearFarDists(fTreeNearDistance_Get(), fTreeFarDistanceBase_Get());
        }
        else
        {
            delete pTree;
            return false;
        }
        initialized = 1;
        tree = pTree;
        Setup(model);
        if (!pTree->CSpeedTreeRT_Compute(0, seed, true))
            return false;
        pTree->ReleaseStorage_00b087d0();
        unk40 = pTree->CSpeedTreeRT_GetSeed();
        unk48 = pTree->GetNestedFloatOrZero_00b07440();
        unk4c = pTree->GetNestedFloatOrZero();
        Finish(model);
        pTree->CSpeedTreeRT_DeleteTransientData();
        pTree->DeleteBranchGeometry();
        pTree->CSpeedTreeRT_DeleteFrondGeometry();
    }
    return true;
}
}  // namespace fnv_0066ac40

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
// Initializes the pathing solution object: zeroes counters, handles and floats, sets unk40 to 1 and unk44 to false.
// @fnv 0x00666650
FUN_00666650::FUN_00666650() : a(0), b(0), c(0), d(0), e(0), f(0), g(0)
{
    unk0c = 0;
    unk08 = 0;
    unk14 = 0;
    unk18 = 0;
    b = 0;
    c = 0;
    unk24 = 0;
    unk28 = 0;
    d = 0;
    e = 0;
    f = 0;
    unk3c = 0.0f;
    unk40 = 1;
    unk44 = false;
    unk48 = 0.0f;
    unk4c = 0.0f;
}

int CopyTreeString(char* apDst, unsigned int auiSize, const char* apSrc);
int AppendTreeString(char* apDst, unsigned int auiSize, const char* apSrc);
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

struct NiRTTI;
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

// Loads the tree's collision NIF from Data\Meshes\Trees, stores its collision object, and falls back to a generated collision node when none is found.
// @fnv 0x00667190
void FUN_00667190_shell::LoadTreeCollision(TESObjectTREE* apTree)
{
    if (!runtime || CombatProcedure_GetFinished())
        return;

    BSTreeModel_CreateBranchGeometry();
    BSTreeModel_CreateLeafGeometry(apTree);
    if (apTree->TESObjectTREE_IsLargeEnoughForDistantLOD())
        BSTreeModel_CreateBillboardGeometry(apTree);

    collision = 0;

    ModelName kModelName;
    CopyTreeString(kModelName.acName, 0x104, apTree->GetModelFilePath());
    int iLengthValue = BSStringLength(kModelName.acName);
    if (iLengthValue > 4)
        kModelName.acName[iLengthValue - 4] = 0;

    BSStream kStream;
    char acPath[0x104];
    CopyTreeString(acPath, 0x104, "Data\\Meshes\\Trees");
    AppendTreeString(acPath, 0x104, kModelName.acName);
    AppendTreeString(acPath, 0x104, ".NIF");
    if (FileFinder::Exist(acPath, 0, 6, 1) && kStream.BSStream_Load(acPath, false) && kStream.NiStream::GetRefAt21C() == 1)
    {
        NiAVObject* pObject = kStream.NiStream::GetStringAt(0);
        NiNode* kNode = (NiNode*)NiDynamicCast(&DAT_011f4280, pObject);
        bhkCollisionObject* pCollisionObjectCur = bhkNiCollisionObject_GetbhkNiCollisionObject(kNode);
        bhkWorldObject* pWorldObject = pCollisionObjectCur ? pCollisionObjectCur->bhkNiCollisionObject_GetWorldObject() : 0;
        NiNode* pCollisionNode = (NiNode*)pWorldObject;
        if (pCollisionNode)
            collision = pCollisionNode;
    }

    if (!(NiNode*)collision && unk48 > 64.0)
        collision = NiNode_ProcessAndReturnValue_00c81380(unk48, unk4c / 2.0);
}

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
    static void operator delete(void*, unsigned int);
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
    static void operator delete(void*, unsigned int);
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
// Builds a Tree from the model's branches and leaves, creating geometry and shaders for each, then applies the billboard, updates and returns it.
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

struct FUN_00b02e20
{
    const char* branchMaps[2];
    const char** leafMaps;
    unsigned int leafCount;
    const char** billboardMaps;
    const char* compositeMap;
    const char* shadowMap;
    FUN_00b02e20();
    ~FUN_00b02e20();
};
struct TexturePtr
{
    BSShaderTextureSet* object;
    BSShaderTextureSet* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(BSShaderTextureSet*);
};
struct SourcePtr
{
    void* object;
    void* Modelloader_GetReferencedThis();
};
struct FullNameComponent
{
    unsigned int FUN_0048cee0();
    const char* TESModel_GetModel();
};
struct TreeInput
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void slot3d();
    virtual void slot3e();
    virtual void slot3f();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot4a();
    virtual void slot4b();
    virtual void slot4c();
    virtual void slot4d();
    virtual void slot4e();
    virtual void slot4f();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot5a();
    virtual void slot5b();
    virtual void slot5c();
    virtual void slot5d();
    virtual void slot5e();
    virtual void slot5f();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual float Get194();
    virtual void slot66();
    virtual float Get19c();
    virtual void slot68();
    virtual float Get1a4();
    virtual void slot6a();
    virtual float Get1ac();
    virtual void slot6c();
    virtual float Get1b4();
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
    FullNameComponent leafName;
    void BuildBillboardTexturePath(char*);
};
struct TreeRuntime
{
    void SetField9C(float);
    void SetField98(float);
    void FUN_00b07490(float);
    void SetFieldD0(float);
    void GetTextures_00b0d040(FUN_00b02e20*);
};
struct TreeTarget
{
    int unk00, unk04, initialized;
    TreeRuntime* runtime;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    TexturePtr branches;
    SourcePtr leaves;
    TexturePtr billboards;
    int unk38;
    float scale;
    bool CombatProcedure_GetFinished();
    void ApplyInput(TreeInput*);
};

extern TES* g_TES;
float SpeedTree_fTreeForceBranchDimming_Get();
float SpeedTree_fTreeForceLeafDimming_Get();
float SpeedTree_fTreeForceMinBudAngle_Get();
int CopyTreeString(char*, unsigned int, const char*);
int AppendTreeString(char*, unsigned int, const char*);
unsigned int BSstrlen(const char*);
void FUN_00b4f5e0(char*, const char*, const char*, bool);
// @fnv 0x00666940
void TreeTarget::ApplyInput(TreeInput* input)
{
    NP a(0);
    if (!input || !runtime || CombatProcedure_GetFinished())
        return;
    float valueHolder = SpeedTree_fTreeForceBranchDimming_Get();
    if (valueHolder < 0.0 || valueHolder > 1.0)
        valueHolder = input->Get1ac();
    if (valueHolder >= 0.0 && valueHolder <= 1.0)
        runtime->SetField9C(valueHolder);
    valueHolder = SpeedTree_fTreeForceLeafDimming_Get();
    if (valueHolder < 0.0 || valueHolder > 1.0)
        valueHolder = input->Get1b4();
    if (valueHolder >= 0.0 && valueHolder <= 1.0)
        runtime->SetField98(valueHolder);
    valueHolder = SpeedTree_fTreeForceCS_Get();
    if (valueHolder < 0.0)
        valueHolder = input->Get194();
    if (valueHolder >= 0.0)
        scale = valueHolder;
    float b = SpeedTree_fTreeForceMinBudAngle_Get();
    float c = SpeedTree_fTreeForceMaxBudAngle_Get();
    if (b < 0.0 || b > 90.0 || c < 0.0 || c > 90.0 || b > c)
    {
        b = input->Get19c();
        c = input->Get1a4();
    }
    if (b >= 0.0 && b <= 90.0 && c >= 0.0 && c <= 90.0 && b <= c)
    {
        runtime->FUN_00b07490(b);
        runtime->SetFieldD0(c);
    }
    AutoMemContext context(30, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeModel.cpp", 145);
    if (!branches.Modelloader_GetReferencedThis())
    {
        FUN_00b02e20 mapBank5;
        char branchPath[260];
        char normalPathA[260];
        unsigned int length2 = 0;
        runtime->GetTextures_00b0d040(&mapBank5);
        CopyTreeString(branchPath, 260, "Textures\\Trees\\Branches\\");
        AppendTreeString(branchPath, 260, mapBank5.branchMaps[0]);
        length2 = BSstrlen(branchPath);
        branchPath[length2 - 3] = 'd';
        branchPath[length2 - 2] = 'd';
        branchPath[length2 - 1] = 's';
        FUN_00b4f5e0(normalPathA, branchPath, "_n", true);
        branches.FUN_0066b0d0(new BSShaderTextureSet);
        branches.Modelloader_GetReferencedThis()->SetTexture(BSShaderProperty::TEXTYPE_DIFFUSE, branchPath);
        branches.Modelloader_GetReferencedThis()->SetTexture(BSShaderProperty::TEXTYPE_NORMAL, normalPathA);
    }
    if (!leaves.Modelloader_GetReferencedThis() && input->leafName.FUN_0048cee0())
    {
        char leafPath[260];
        CopyTreeString(leafPath, 260, "Textures\\Trees\\Leaves\\");
        AppendTreeString(leafPath, 260, input->leafName.TESModel_GetModel());
        g_TES->FUN_004568c0(leafPath, &leaves, true, false);
    }
    if (!billboards.Modelloader_GetReferencedThis())
    {
        char billboardPath[260];
        input->BuildBillboardTexturePath(billboardPath);
        billboards.FUN_0066b0d0(new BSShaderTextureSet);
        billboards.Modelloader_GetReferencedThis()->SetTexture(BSShaderProperty::TEXTYPE_DIFFUSE, billboardPath);
    }
}

struct Element226
{
    void* object;
    ~Element226();
    static void operator delete[](void*);
};
struct Ref226
{
    void* object;
    void FUN_0066b0d0(void*);
};
struct Owner226
{
    int unk00, unk04, unk08, unk0c, unk10;
    Element226* array14;
    Element226* array18;
    Ref226 ref1c, ref20;
    Element226* array24;
    Element226* array28;
    Ref226 ref2c, ref30, ref34, ref38;
    bool CombatProcedure_GetFinished();
    void ClearArrays();
};
// Deletes the object's array members and clears the reference members, resetting each pointer to null.
// @fnv 0x00666fc0
void Owner226::ClearArrays()
{
    if (array14)
    {
        if (CombatProcedure_GetFinished())
        {
        }
        delete[] array14;
        array14 = 0;
    }
    if (array18)
    {
        delete[] array18;
        array18 = 0;
    }
    ref1c.FUN_0066b0d0(0);
    ref20.FUN_0066b0d0(0);
    if (array24)
    {
        delete[] array24;
        array24 = 0;
    }
    if (array28)
    {
        delete[] array28;
        array28 = 0;
    }
    ref2c.FUN_0066b0d0(0);
    ref30.FUN_0066b0d0(0);
    ref34.FUN_0066b0d0(0);
    ref38.FUN_0066b0d0(0);
}

class NiGPUProgram;
namespace fnv_00668500 {
using ::NiMemObject;
// These virtuals belong to the leaf shader property, rather than the scene object.
// Keep its unshared interface here; NiObject supplies the common virtual slots.
class LeafShaderProperty : public NiObject
{
  public:
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void SetMaterial(NiAVObject*);
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual NiGPUProgram* GetProgram(int);
};
template <> struct TreeModelPointer<NiAVObject>
{
    NiAVObject* m_pObject;
    TreeModelPointer();
    TreeModelPointer(NiAVObject* pObject);
    ~TreeModelPointer();
    TreeModelPointer& operator=(NiAVObject* pObject);
    operator NiAVObject*() const;
    NiAVObject* operator->() const;
};
class NiGPUProgramOwner
{
  public:
    void SetProgram(NiGPUProgram* pProgram);
};
struct FUN_00414430
{
    float a, b, c, d;
    FUN_00414430();
    FUN_00414430(float fA, float fB, float fC, float fD);
};
void* NiMalloc(unsigned int uiSize);
int BSstrcmp(const char* pA, const char* pB);
unsigned int __fastcall TESMain_GetThread(void* pTree);
void __fastcall ActiveEffect_SetMagnitude(void* pObject, float fValue);

struct FUN_00792760_shell
{
    float QueuedModel_GetOverriddenVisualDistance();
};
struct FUN_0063f790_shell
{
    void FUN_0063f790(float fValue);
};
struct FUN_00621b20_Class
{
    void NiTimeController_SetPhase(float fValue);
};

struct FUN_00b029f0
{
    int m_aiPad00[0x84 / 4];
    unsigned short m_usNumLeaves;
    unsigned short m_usPad86;
    int m_iPad88;
    unsigned char* m_pucAngleIndices;
    NiPoint3* m_pkCenters;
    float** m_ppfTexCoords;
    int m_iPad98;
    unsigned int* m_puiColors;
    NiPoint3* m_pkNormals;
    int m_aiPadA4[2];
    float* m_pfWidths;
    unsigned char* m_pucSizes;
    int m_aiPadB4[(0x130 - 0xb4) / 4];
    FUN_00b029f0();
    ~FUN_00b029f0();
};
struct FUN_00b02e20
{
    int m_iPad00;
    unsigned short m_usValue;
    unsigned short m_usPad06;
    const char** m_ppTextures;
    int m_aiPad0C[4];
    FUN_00b02e20();
    ~FUN_00b02e20();
};
struct SpeedTreeRT
{
    float* CSpeedTreeRT_GetLeafLodSizeAdjustments();
    void GetTextures_00b0d040(FUN_00b02e20* pTextures);
    void CSpeedTreeRT_GetGeometry(FUN_00b029f0* m_pShaderGeometry, unsigned int uiBits, short sBranch, short sFrond, short sLeaf);
    void FreeLeafLODDataArrays();
};
struct FUN_00bb3950 : public NiMemObject
{
    int m_kNextStreamField[8];
    FUN_00bb3950();
};
struct FUN_00bb33c0 : public NiMemObject
{
    int m_kNextStreamField[4];
    FUN_00bb33c0();
};
struct FUN_00bb3ba0 : public NiMemObject
{
    int m_kNextStreamField[36];
    FUN_00bb3ba0(unsigned short usLod, NiAVObject* pData, NiAVObject* pMaterial);
};
struct FUN_00a7b630 : public NiMemObject
{
    int m_kNextStreamField[22];
    FUN_00a7b630(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, void* pkColor, NiPoint2* pkTexture,
                 unsigned short usNumTextureSets, int eNBTMethod, unsigned short usTriangles,
                 unsigned short* pusTriList);
};
class TreeLeafRef
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual float GetWidth();
    virtual void v1c8();
    virtual float GetHeight();
};
class TreeLeafModel
{
  public:
    int m_aiPad00[3];
    SpeedTreeRT* m_pLeafTreeRuntime;
    int m_aiPad10[2];
    TreeModelPointer<NiAVObject>* m_pspLeafGeometry;
    int m_iPad1C;
    TreeModelPointer<NiAVObject> m_spLeafMaterial;
    int m_iPad24;
    TreeModelPointer<NiAVObject>* m_pspLeafShaders;
    int m_iPad2C;
    TreeModelPointer<NiAVObject> m_spLeafTexture;
    int m_aiPad34[2];
    float m_fLeafScale;
    unsigned short FUN_006699d0();
    void BSTreeModel_CreateLeafGeometry(TreeLeafRef* pRef);
};

// Builds per-level leaf geometry, shaders and material from the SpeedTree data, allocating vertex, normal, UV and attribute arrays and triangle indices.
// @fnv 0x00668500
// src: XBOX_PDB 0x00668500
void TreeLeafModel::BSTreeModel_CreateLeafGeometry(TreeLeafRef* pRef)
{
    unsigned short usJ;
    FUN_00b029f0 kLeafGeom;
    unsigned short* pusTris;
    unsigned short usVertCount;
    unsigned short usLeafCount;
    unsigned short usLevels;
    unsigned short* pusIndex;
    unsigned short usTex;
    FUN_00b02e20 kTexData;
    NiPoint3* pkSrcPos = 0;
    NiPoint3* pkCardNormals = 0;
    float* pfCoords = 0;
    NiPoint3* pkVertex = 0;
    NiPoint3* pkNorm = 0;
    NiPoint2* pkUVCoords = 0;
    FUN_00414430* pkAttributes;
    unsigned short usNumNames;
    unsigned short usBaseVert;
    unsigned short usCornerIndex;
    TreeModelPointer<NiAVObject> spWindData = 0;
    unsigned short usI;
    bool bMultiTexture = false;
    unsigned short usCard;
    unsigned short usBaseIndex;
    float fCorner;
    float fLightness;

    if (!m_pLeafTreeRuntime || !m_pLeafTreeRuntime->CSpeedTreeRT_GetLeafLodSizeAdjustments() || ((FUN_00666f00_shell*)this)->CombatProcedure_GetFinished())
        return;

    if (m_pspLeafGeometry)
    {
        delete[] m_pspLeafGeometry;
        m_pspLeafGeometry = 0;
    }
    if (m_pspLeafShaders)
    {
        delete[] m_pspLeafShaders;
        m_pspLeafShaders = 0;
    }

    usLevels = FUN_006699d0();
    if (usLevels <= 0)
        return;

    m_pLeafTreeRuntime->GetTextures_00b0d040(&kTexData);
    usNumNames = kTexData.m_usValue;
    if (usNumNames <= 0)
        return;

    for (usTex = 0; usTex < usNumNames; usTex++)
    {
        for (usJ = usTex + 1; usJ < usNumNames; usJ++)
        {
            if (BSstrcmp(kTexData.m_ppTextures[usTex], kTexData.m_ppTextures[usJ]))
                bMultiTexture = true;
        }
    }

    m_pspLeafGeometry = new TreeModelPointer<NiAVObject>[usLevels];
    m_pspLeafShaders = new TreeModelPointer<NiAVObject>[usLevels];
    for (usI = 0; usI < usLevels; usI++)
    {
        m_pspLeafGeometry[usI] = 0;
        m_pspLeafShaders[usI] = 0;
    }

    m_spLeafMaterial = (NiAVObject*)new FUN_00bb3950;
    ((FUN_0063f790_shell*)(NiAVObject*)m_spLeafMaterial)->FUN_0063f790(m_fLeafScale);
    if (m_pLeafTreeRuntime && TESMain_GetThread(m_pLeafTreeRuntime))
    {
        ((FUN_00621b20_Class*)(NiAVObject*)m_spLeafMaterial)
            ->NiTimeController_SetPhase(((TESObjectREFR*)TESMain_GetThread(m_pLeafTreeRuntime))->GetScale());
        ((FUN_006694c0_shell*)(NiAVObject*)m_spLeafMaterial)
            ->SetPad5(((FUN_00792760_shell*)TESMain_GetThread(m_pLeafTreeRuntime))->QueuedModel_GetOverriddenVisualDistance());
        if (pRef)
        {
            ((BSMultiBoundSphere*)(NiAVObject*)m_spLeafMaterial)->CombatLocation_SetRadius(pRef->GetWidth());
            ActiveEffect_SetMagnitude((NiAVObject*)m_spLeafMaterial, pRef->GetHeight());
        }
    }

    for (usI = 0; usI < usLevels; usI++)
    {
        m_pLeafTreeRuntime->CSpeedTreeRT_GetGeometry(&kLeafGeom, 4, -1, -1, usI);
        usLeafCount = kLeafGeom.m_usNumLeaves;
        usVertCount = usLeafCount * 4;
        if (usLeafCount <= 0)
            continue;

        pkSrcPos = kLeafGeom.m_pkCenters;
        pkCardNormals = kLeafGeom.m_pkNormals;
        pkVertex = new NiPoint3[usVertCount];
        pkNorm = new NiPoint3[usVertCount];
        pkUVCoords = new NiPoint2[usVertCount];
        pkAttributes = new FUN_00414430[usVertCount];
        pusTris = (unsigned short*)NiMalloc(usLeafCount * 6 * sizeof(unsigned short));
        pusIndex = pusTris;

        for (usCard = 0; usCard < usLeafCount; usCard++)
        {
            usBaseVert = usCard * 4;
            usBaseIndex = usCard * 6;
            pkVertex[usBaseVert + 3] = pkSrcPos[usCard];
            pkVertex[usBaseVert + 2] = pkVertex[usBaseVert + 3];
            pkVertex[usBaseVert + 1] = pkVertex[usBaseVert + 2];
            pkVertex[usBaseVert] = pkVertex[usBaseVert + 1];
            pkNorm[usBaseVert + 3] = pkCardNormals[usCard];
            pkNorm[usBaseVert + 2] = pkNorm[usBaseVert + 3];
            pkNorm[usBaseVert + 1] = pkNorm[usBaseVert + 2];
            pkNorm[usBaseVert] = pkNorm[usBaseVert + 1];

            fLightness = ((kLeafGeom.m_puiColors[usCard] & 0xff00) >> 8) / 255.0;
            if (fLightness >= 1.0)
                fLightness = 0.99f;

            pfCoords = kLeafGeom.m_ppfTexCoords[usCard];
            for (usCornerIndex = 0; usCornerIndex < 4; usCornerIndex++)
            {
                if (bMultiTexture)
                    pkUVCoords[usBaseVert + usCornerIndex] =
                        NiPoint2(pfCoords[usCornerIndex * 2], pfCoords[(3 - usCornerIndex) * 2 + 1]);
                else
                    pkUVCoords[usBaseVert + usCornerIndex] =
                        NiPoint2(pfCoords[usCornerIndex * 2], pfCoords[usCornerIndex * 2 + 1]);

                fCorner = kLeafGeom.m_pucAngleIndices[usCard] * 4 + (usCornerIndex + 2) % 4;
                fCorner += fLightness;
                pkAttributes[usBaseVert + usCornerIndex] =
                    FUN_00414430(kLeafGeom.m_pfWidths[usCard], kLeafGeom.m_pucSizes[usCard] * 4, fCorner,
                                 m_pLeafTreeRuntime->CSpeedTreeRT_GetLeafLodSizeAdjustments()[usI]);
            }

            pusIndex[usBaseIndex] = usBaseVert + 3;
            pusIndex[usBaseIndex + 1] = usBaseVert + 1;
            pusIndex[usBaseIndex + 2] = usBaseVert + 2;
            pusIndex[usBaseIndex + 3] = usBaseVert;
            pusIndex[usBaseIndex + 4] = usBaseVert + 1;
            pusIndex[usBaseIndex + 5] = usBaseVert + 3;
        }

        m_pspLeafGeometry[usI] =
            (NiAVObject*)new FUN_00a7b630(usVertCount, pkVertex, pkNorm, 0, pkUVCoords, 1, 0, usLeafCount * 2, pusTris);
        spWindData = (NiAVObject*)new FUN_00bb33c0;
        ((FUN_006684d0_shell*)(NiAVObject*)spWindData)->SetFields08And0C((int)pkAttributes, usVertCount);
        m_pspLeafShaders[usI] = (NiAVObject*)new FUN_00bb3ba0(usI, spWindData, m_spLeafMaterial);
        ((LeafShaderProperty*)m_pspLeafShaders[usI].operator->())->SetMaterial(m_spLeafTexture);
        ((NiGPUProgramOwner*)(NiAVObject*)m_pspLeafGeometry[usI])->SetProgram(((LeafShaderProperty*)m_pspLeafShaders[usI].operator->())->GetProgram(0));
        ((NiAVObject*)m_pspLeafGeometry[usI])->FUN_00a67050(0x4000);
        ((NiAVObject*)m_pspLeafGeometry[usI])->SetByteAtOffset38(0x11);
        ((NiAVObject*)m_pspLeafGeometry[usI])->FUN_004410f0(1);
    }

    m_pLeafTreeRuntime->FreeLeafLODDataArrays();
}
}  // namespace fnv_00668500

struct TreeEval
{
    TreeEval()
    {
        FUN_00b029f0();
    }
    ~TreeEval()
    {
        FUN_00b02ac0();
    }
    void FUN_00b029f0();
    void FUN_00b02ac0();
    unsigned int unk00;
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
    float leafScale;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned char leftEnabled, leftU79, leftU7a, leftU7b;
    float leftAlpha;
    int leftLevel;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned char rightEnabled, rightUb5, rightUb6, rightUb7;
    float rightAlpha;
    int rightLevel;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned char opacityEnabled, opacityF1, opacityF2, opacityF3;
    unsigned int unkf4;
    unsigned int unkf8;
    float opacity;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
};
struct RuntimeOps
{
    void CSpeedTreeRT_SetTreePosition(float, float, float);
    void CSpeedTreeRT_SetLodLevel(float);
    void CSpeedTreeRT_ComputeLodLevel();
    float CSpeedTreeRT_GetLodLevel();
    short GetIndexFromLevel(float);
    void CSpeedTreeRT_GetBSGeometryLODData(TreeEval*, float);
    RuntimeOps* CSpeedTreeRT_InstanceOf();
    RuntimeOps* CSpeedTreeRT_GetLeafBillboardTable(void*);
};
struct SceneNode
{
    void UpdateFields_00bb39e0(void*, void*);
};
struct NodeHandle
{
    SceneNode* Modelloader_GetReferencedThis();
};
struct TreeCallback
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual int IsReady();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void SetLeafEnabled(unsigned char);
    virtual void SetBranchEnabled(unsigned char);
    virtual void SetTopEnabled(unsigned char);
    virtual void SetLeafLod(unsigned short, unsigned char);
    virtual void SetBranchLod(unsigned short, unsigned char);
    virtual void SetTopAlpha(unsigned char);
    NiPoint3* NiAVObject_GetWorldTranslate();
};
unsigned char __cdecl BSTreeManager_GetTreesEnabled();
unsigned char __cdecl BSTreeManager_AreLeavesVisible();
struct TreeActor
{
    int unk00, unk04, unk08;
    RuntimeOps* runtime;
    int unk10, unk14, unk18, unk1c;
    NodeHandle handle;
    short GetNumBranchLODLevels();
    short FUN_006699d0();
    void UpdateTreeLod(TreeCallback*);
};
// Evaluates tree fade/LOD state and pushes top alpha, leaf and branch LOD levels to the receiver callback.
// @fnv 0x00669a10
void TreeActor::UpdateTreeLod(TreeCallback* pCallback)
{
    TreeEval info;
    float fade;
    unsigned char visible;
    short leaf;
    {
        NiPoint3 worldPos;
        void* pNode = 0;
        short levelCount;
        if (!pCallback || !pCallback->IsReady())
            return;
        if (!runtime)
            return;
        if (!BSTreeManager_GetTreesEnabled())
            return;
        worldPos = *pCallback->NiAVObject_GetWorldTranslate();
        runtime->CSpeedTreeRT_SetTreePosition(worldPos.x, worldPos.y, worldPos.z);

        if (GetByteAtOffset1B())
        {
            runtime->CSpeedTreeRT_SetLodLevel(1.0f);
            fade = 1.0f;
        }
        else
        {
            runtime->CSpeedTreeRT_ComputeLodLevel();
            fade = runtime->CSpeedTreeRT_GetLodLevel();
        }
        runtime->CSpeedTreeRT_GetBSGeometryLODData(&info, fade);
        visible = 0;
        if (info.opacityEnabled)
        {
            visible = 1;
            pCallback->SetTopAlpha((unsigned char)info.opacity);
        }
        pCallback->SetTopEnabled(visible);
        if (fade <= 0.0f)
        {
            pCallback->SetLeafEnabled(0);
            pCallback->SetBranchEnabled(0);
            return;
        }
        visible = 0;
        levelCount = GetNumBranchLODLevels();
        if (levelCount > 0)
        {
            short preferred = runtime->GetIndexFromLevel(runtime->CSpeedTreeRT_GetLodLevel());
            for (leaf = 0; leaf < levelCount; ++leaf)
            {
                if (preferred == leaf)
                {
                    visible = 1;
                    pCallback->SetLeafLod(leaf, (unsigned char)info.leafScale);
                }
                else
                {
                    pCallback->SetLeafLod(leaf, 255);
                }
            }
        }
        pCallback->SetLeafEnabled(visible);
        if (!BSTreeManager_AreLeavesVisible())
        {
            pCallback->SetBranchEnabled(0);
            return;
        }
        visible = 0;
        levelCount = FUN_006699d0();
        if (levelCount > 0)
        {
            if (info.leftEnabled || info.rightEnabled)
            {
                for (leaf = 0; leaf < levelCount; ++leaf)
                {
                    if (info.leftEnabled && info.leftLevel == leaf)
                    {
                        visible = 1;
                        pCallback->SetBranchLod(leaf, (unsigned char)info.leftAlpha);
                    }
                    else if (info.rightEnabled && info.rightLevel == leaf)
                    {
                        visible = 1;
                        pCallback->SetBranchLod(leaf, (unsigned char)info.rightAlpha);
                    }
                    else
                    {
                        pCallback->SetBranchLod(leaf, 255);
                    }
                }
            }
            if (handle.Modelloader_GetReferencedThis())
            {
                void* lightPtr = runtime->CSpeedTreeRT_InstanceOf() ? runtime->CSpeedTreeRT_InstanceOf()->CSpeedTreeRT_GetLeafBillboardTable(&pNode)
                                                         : runtime->CSpeedTreeRT_GetLeafBillboardTable(&pNode);
                handle.Modelloader_GetReferencedThis()->UpdateFields_00bb39e0(lightPtr, pNode);
            }
        }
        pCallback->SetBranchEnabled(visible);
    }
}
