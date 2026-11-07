// fallout_shared/pathfinding/navmeshrender.cpp: NavMeshObstacleManager, ObstacleTask, NavRenderX, RenderTask and more (12 functions)

#include "../../../include/NiPointer.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshPtr.h"
#include "navmeshrender_decls.h"
// Keep the shared scene graph's dependency templates separate from layout_support.h.
#include "../../../include/NiTArray.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"
#include "../../../include/BSShaderNoLightingProperty.h"

#include "../../../include/GO.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/TES.h"
#include "../../../include/TESWorldSpace.h"
#include "../../../include/NavMeshTriangle.h"

// The PC spans supplied for this unit are obstacle-management methods. The
// legacy PaddedBooleanState labels disagree with their member layouts and lifetimes.

// Iterates the obstacle list, looks up each rigid body's ObstacleData, skips ones already in the active list, and adds the rest to its head.
// @fnv 0x006c49e0
void NavMeshObstacleManager::ProcessActivatedObstacles()
{
    unsigned int count = m_kActivatedRigidBodies.GetCount();
    for (unsigned int uiIndex = 0; uiIndex < count; ++uiIndex)
    {
        bhkRigidBody* body;
        m_kActivatedRigidBodies.LockFreeQueue_bhkRigidBody_Pop(body);
        NiPointer<ObstacleData> obstacle(0);
        if (RigidBodyObstacleLookup.GetAt(body, obstacle))
        {
            if (m_kActiveObstacles.Contains(obstacle))
                continue;
            m_kActiveObstacles.AddHead(obstacle);
        }
    }
}

// Stores the obstacle pointer, task type and navmesh pointer into the object's fields.
// @fnv 0x006c7d70
ObstacleTask::ObstacleTask(const NiPointer<ObstacleData>& obstacle, OBSTACLE_TASK_TYPE type, const NavMeshPtr& navMesh)
    : m_spRegisteredObstacle(0)
{
    m_spRegisteredObstacle = obstacle;
    eType = type;
    apSearchNavMesh = navMesh;
}

extern int DAT_010159d4;

struct Dummy0042f800
{
    void FUN_0042fcb0(int, int);
};

// @fnv 0x0049f1c0
// src: GUESS 0x0049f1c0 (confidence: low)
void* __fastcall Object_InitializeFields_0049f1c0(int** pThis)
{
    *pThis = &DAT_010159d4;
    reinterpret_cast<Dummy0042f800*>(pThis)->FUN_0042fcb0(0, 0);
    return pThis;
}

typedef char _sizecheck_NavMeshTriangle[sizeof(NavMeshTriangle) == 16 ? 1 : -1];
struct FUN_006a5ec0_shell : public NavMeshTriangle
{
    bool NavMeshTriangle_IsWater();
};

// @fnv 0x006a5ec0
// src: XBOX_PDB 0x006a5ec0
bool FUN_006a5ec0_shell::NavMeshTriangle_IsWater()
{
    return GetFlag(0x200);
}

struct FUN_006a5b30_shell
{
    short m_uiX;
    short m_uiY;
    short m_uiZ;
    void GetTripleShorts(short* a, short* b, short* c);
};

// Copies the three short fields of this object into the three output pointers.
// @fnv 0x006a5b30
void __thiscall FUN_006a5b30_shell::GetTripleShorts(short* pFirst, short* pSecond, short* pThird)
{
    *pFirst = this->m_uiX;
    *pSecond = this->m_uiY;
    *pThird = this->m_uiZ;
}

struct FUN_006a5b70_shell
{
    short m_00;
    short m_02;
    short m_04;
    short m_06;
    short m_08;
    short m_0A;
    void NavMeshTriangle_GetSides(short* a, short* b, short* c);
};

// Copies the shell's m_06, m_08 and m_0A shorts into the three output pointers.
// @fnv 0x006a5b70
// src: COMMUNITY 0x006a5b70
void FUN_006a5b70_shell::NavMeshTriangle_GetSides(short* a, short* b, short* c)
{
    *a = m_06;
    *b = m_08;
    *c = m_0A;
}

extern float runtimeInitializationFloat369;
// Clamps a to 0xF and returns it multiplied by runtimeInitializationFloat369.
// @fnv 0x006a5af0
float ScaleClampedValue(unsigned int auiValue)
{
    if (auiValue > 0xF)
        auiValue = 0xF;
    return auiValue * runtimeInitializationFloat369;
}



extern GO g_011d6e5c;

struct PaddedBooleanState
{
    unsigned char padding[0x210];
    bool m_bState;

    void NavMeshRender_SetDraw(bool);
};

// @fnv 0x006a36e0
// src: COMMUNITY 0x006a36e0
void PaddedBooleanState::NavMeshRender_SetDraw(bool abDraw)
{
    if (abDraw)
    {
        reinterpret_cast<NiAVObject*>(static_cast<const GO&>(g_011d6e5c).operator unsigned int())->UpdateSceneObject();

        NiUpdateData UpdateData(0.0f, false, false);
        reinterpret_cast<NiNode*>(static_cast<const GO&>(g_011d6e5c).operator unsigned int())->Update(UpdateData);
    }
    else
    {
        reinterpret_cast<NiNode*>(static_cast<const GO&>(g_011d6e5c).operator unsigned int())->NiNode_RemoveAllChildren();
        reinterpret_cast<NiAVObject*>(static_cast<const GO&>(g_011d6e5c).operator unsigned int())->UpdateSceneObject();

        NiUpdateData UpdateData(0.0f, false, false);
        reinterpret_cast<NiNode*>(static_cast<const GO&>(g_011d6e5c).operator unsigned int())->Update(UpdateData);

        reinterpret_cast<NiTPointerMap<NiNode*, NiNode*>*>(reinterpret_cast<char*>(this) + 0x200)->RemoveAll();
    }

    m_bState = abDraw;
}

namespace fnv_006a5ca0 {
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};

struct DoorH
{
    void* GetParentWorldSpace();
};

struct GlobalObject_0045cfe0
{
    int* Int();
};

struct PaddedBooleanState
{
    void NavMeshRender_SetDraw(bool value);
    void NavMeshRender_AddDrawOnlyNavMeshes(TESObjectCELL* cell, bool value);
    void NavMeshRender_UpdateRenderOnlyNavMeshes();
};

bool __fastcall FUN_00425fd0(TESObjectCELL* cell);
int __cdecl NavMeshRender_GetSingleton(void);

GlobalObject_0045cfe0 g_011c63cc;
int g_TES;

// @fnv 0x006a5ca0
// src: COMMUNITY 0x006a5ca0
void PaddedBooleanState::NavMeshRender_UpdateRenderOnlyNavMeshes()
{
    TESObjectCELL* pcellVal;
    int d8;
    int x9;
    int y3;
    TESObjectCELL* pgridCell4;

    NavMeshRender_SetDraw(false);
    pcellVal = reinterpret_cast<TES*>(g_TES)->GetDetailedActorPathHandler();
    if (pcellVal)
    {
        if (!FUN_00425fd0(pcellVal))
        {
            d8 = (g_011c63cc.Int()[0] - 1) / 2;
            x9 = reinterpret_cast<CellH*>(pcellVal)->GetCellGridX() - d8;
            for (; x9 <= reinterpret_cast<CellH*>(pcellVal)->GetCellGridX() + d8; ++x9)
            {
                y3 = reinterpret_cast<CellH*>(pcellVal)->GetCellGridY() - d8;
                for (; y3 <= reinterpret_cast<CellH*>(pcellVal)->GetCellGridY() + d8; ++y3)
                {
                    pgridCell4 = reinterpret_cast<TESWorldSpace*>(reinterpret_cast<DoorH*>(pcellVal)->GetParentWorldSpace())
                                     ->GetCellAtGridPosition(x9, y3);
                    NavMeshRender_AddDrawOnlyNavMeshes(pgridCell4, false);
                }
            }
        }
        else
        {
            reinterpret_cast<PaddedBooleanState*>(NavMeshRender_GetSingleton())->NavMeshRender_AddDrawOnlyNavMeshes(pcellVal, false);
        }
    }
    NavMeshRender_SetDraw(true);
}
}  // namespace fnv_006a5ca0

struct Pt3X
{
    float x, y, z;
    Pt3X();
    Pt3X operator*(float afScale) const;
    Pt3X operator+(const Pt3X& arPt) const;
    Pt3X operator-(const Pt3X& arPt) const;
    void Unitize();
    Pt3X& operator*=(float afScale);
};
struct EmptyX
{
};
struct Pt3PodX : public EmptyX
{
    float x, y, z;
    Pt3PodX* Set(float afX, float afY, float afZ);
};
struct ColorX
{
    float r, g, b, a;
    ColorX();
    ColorX(float afR, float afG, float afB, float afA);
};
struct FixedText
{
    const char* pString;
    FixedText(const char* apString);
    ~FixedText();
};
// NiNode's shared allocation interface selects unsized constructor-failure
// cleanup. Retain this local node definition until that interface is supported.
struct NodeX : public NiAVObject
{
    NiTObjectArray<NiPointer<NiAVObject> > m_kChildren;
    NodeX(unsigned short children);
    static void operator delete(void* memory, size_t size);
};
struct LinesX : public NiAVObject
{
    static void operator delete(void* memory, size_t size);
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    LinesX(unsigned short ausVerts, Pt3X* apVerts, ColorX* apColors, int a, int b, int c, bool* apFlags);
};
struct TriShapeX : public NiAVObject
{
    static void operator delete(void* memory, size_t size);
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    TriShapeX(unsigned short ausVerts, Pt3X* apVerts, Pt3X* apNormals, ColorX* apColors, void* apUV,
              unsigned short ausUV, int aiFlags, unsigned short ausTris, unsigned short* apusList);
};
struct AlphaX : public NiObjectNET
{
    unsigned int unk018;
    AlphaX();
    void SetAlphaBlending(bool blend);
};
struct Pt3ArrX
{
    Pt3X* pData;
    int iSize, iAlloc, iGrow;
    Pt3ArrX(int aiSize);
    ~Pt3ArrX();
    Pt3X& GetAt(unsigned int auiIndex);
    void SetSize(int aiSize, int aiArg);
};
struct ColorArrX
{
    ColorX* pData;
    int iSize, iAlloc, iGrow;
    ColorArrX(int aiSize);
    ~ColorArrX();
    ColorX& GetAt(int aiIndex);
    void SetSize(int aiSize, int aiArg);
};
struct BoolArrX
{
    bool* pData;
    int iSize, iAlloc, iGrow;
    BoolArrX(int aiSize);
    ~BoolArrX();
    bool& GetAt(int aiIndex);
};
struct NavTriX
{
    bool GetFlag(int aiFlag);
    void GetVerts(unsigned short* apA, unsigned short* apB, unsigned short* apC);
    void GetTris(unsigned short* apA, unsigned short* apB, unsigned short* apC);
    bool EdgeHasExtraInfo(int aiEdge);
    void GetEdgeCoverData(unsigned short ausEdge, unsigned short* apusCover, bool* apbLeft, bool* apbRight);
};
// NavMesh::FUN_00691640 returns AvoidSphere; 0x004a7bd0/0x006815c0 match its radius/center accessors in pathsmootherpov.cpp.
class AvoidSphere
{
public:
    float GetRadius() const;
    const NiPoint3& FUN_006815c0();
};
struct NavInfoX
{
    bool IsLoaded() const;
    void GetMesh(NavMeshPtr& arMesh);
};
struct EdgeInfoX
{
    int iActionIndex;
    NavInfoX* pTarget;
    unsigned short usTri;
};
// Shared NavMesh lacks these two /Od accessor declarations; their ECX-only ABI
// is preserved by the free fastcall declarations (0x00990a60 and 0x00440da0).
unsigned int __fastcall NavMeshGetArrayFlags(NavMesh*);
bool __fastcall NavMeshIsDisabled(NavMesh*);
struct NavArrX
{
    NavMeshPtr GetAt(unsigned int auiIndex);
};
struct CellX
{
    NavArrX* GetNavMeshArray();
};
struct CellMapX
{
    bool GetAt(CellX* apCell, NiPointer<NodeX>& arNode);
    void SetAt(CellX* apCell, NiPointer<NodeX> aspNode);
};
struct NavRenderX
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    NiPointer<NiObject> spWireframe;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    NiPointer<NiObject> spVertexColor;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    ColorX aColors[11];
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    NiPointer<NiObject> spZBuffer;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    CellMapX kMap;
    int GetTriColor(NavTriX* apTri);
    void NavMeshRender_AddDrawOnlyNavMeshes(CellX* apCell, bool abUpdate);
};
unsigned int __fastcall xGetNavMeshCount(NavArrX* apArray);
void* __cdecl xNiMalloc(unsigned int auiSize);
float __cdecl xGetCoverHeight(unsigned int auiCover);
NiAVObject* __cdecl xMakeLine(Pt3X& arA, Pt3X& arB, float afA, float afB, float afHeight, float afOffset, ColorX& arColor,
                          int aiArg);
NiAVObject* __cdecl xMakeSphere(float afRadius, int aiSlices, int aiStacks, ColorX* apColor);
void __cdecl xUpdateNode(NodeX* apNode);
void __cdecl xPrepareNode(NodeX* apNode, int a, int b);
extern "C" void* __cdecl memcpy(void* apDst, const void* apSrc, unsigned int auiSize);
extern NiPointer<NodeX> xspNavRoot;
extern bool xbShowPortals;
extern bool xbShowCover;
extern float xfCoverWidth, xfCoverScale, xfCoverOffset, xfCoverWidth2;
// Builds and attaches a navmesh debug render node for the cell: lines, cover lines, triangles and spheres, then updates the nav root if requested.
// @fnv 0x006a37a0
// src: XBOX_PDB 0x006a37a0
void NavRenderX::NavMeshRender_AddDrawOnlyNavMeshes(CellX* apCell, bool abUpdate)
{
    NavArrX* qfTOqo;
    unsigned int qQMZREG;
    if (!apCell)
        return;
    qfTOqo = apCell->GetNavMeshArray();
    if (!qfTOqo)
        return;
    qQMZREG = xGetNavMeshCount(qfTOqo);
    NiPointer<NodeX> qAhbO(0);
    if (!kMap.GetAt(apCell, qAhbO))
    {
        qAhbO = new NodeX(qQMZREG * 2);
        reinterpret_cast<NiNode*>(static_cast<NodeX*>(xspNavRoot))->AttachChildInAvailableSlot(static_cast<NiAVObject*>(static_cast<NodeX*>(qAhbO)), true);
        kMap.SetAt(apCell, qAhbO);
    }
    else
    {
        return;
    }
    NavMeshPtr qsSDDgz;
    for (unsigned int qbfQdhM = 0; qbfQdhM < qQMZREG; qbfQdhM++)
    {
        unsigned int qXMUYT;
        unsigned int qpia;
        ColorX* qJDuOZ;
        bool* qxQHW;
        unsigned int qIpA;
        unsigned int qArxcFu;
        unsigned int qMBds;
        unsigned short* qaGEwZ;
        Pt3X* qFffvLe;
        ColorX* qZAdkzg;
        bool qfCsmZ;
        unsigned int qVduN;
        Pt3X* qbXcw;
        unsigned int qBCzzXA;
        qsSDDgz = qfTOqo->GetAt(qbfQdhM);
        qMBds = static_cast<NavMesh*>(qsSDDgz)->NavMesh_GetTriangleCount();
        qBCzzXA = NavMeshGetArrayFlags(static_cast<NavMesh*>(qsSDDgz));
        if (!qMBds)
            continue;
        qfCsmZ = NavMeshIsDisabled(static_cast<NavMesh*>(qsSDDgz));
        Pt3ArrX qkJsUdT(qBCzzXA);
        ColorArrX qrEZrs(qBCzzXA);
        if (qfCsmZ)
        {
            for (unsigned int qAXSCg = 0; qAXSCg < qBCzzXA; qAXSCg++)
            {
                qkJsUdT.GetAt(qAXSCg) = reinterpret_cast<Pt3X&>(static_cast<NavMesh*>(qsSDDgz)->Vertices.GetAt(qAXSCg));
                qrEZrs.GetAt(qAXSCg) = aColors[10];
            }
        }
        else
        {
            for (unsigned int qBLsiu = 0; qBLsiu < qBCzzXA; qBLsiu++)
            {
                qkJsUdT.GetAt(qBLsiu) = reinterpret_cast<Pt3X&>(static_cast<NavMesh*>(qsSDDgz)->Vertices.GetAt(qBLsiu));
                qrEZrs.GetAt(qBLsiu) = aColors[0];
            }
        }
        qaGEwZ = (unsigned short*)xNiMalloc(qMBds * 3 * sizeof(unsigned short));
        qXMUYT = qBCzzXA;
        qVduN = 0;
        qIpA = qMBds * 6;
        Pt3ArrX qDdzMIp(qIpA);
        BoolArrX qHXYKT(qIpA);
        ColorArrX qGfbX(qIpA);
        qpia = 0;
        Pt3ArrX qZWI(qIpA);
        BoolArrX qrKBG(qIpA);
        ColorArrX qpqRa(qIpA);
        qArxcFu = 0;
        for (unsigned int qrUCJDN = 0; qrUCJDN < qMBds; qrUCJDN++)
        {
            NavTriX* qidnYUK = reinterpret_cast<NavTriX*>(static_cast<NavMesh*>(qsSDDgz)->GetTriangle(qrUCJDN));
            if (qidnYUK->GetFlag(0x20))
                continue;
            unsigned short qxWmVch[3];
            qidnYUK->GetVerts(&qxWmVch[0], &qxWmVch[1], &qxWmVch[2]);
            if (qfCsmZ)
            {
                qaGEwZ[qVduN] = qxWmVch[0];
                qVduN++;
                qaGEwZ[qVduN] = qxWmVch[1];
                qVduN++;
                qaGEwZ[qVduN] = qxWmVch[2];
                qVduN++;
            }
            else
            {
                int qhQRuW = GetTriColor(qidnYUK);
                if (qhQRuW)
                {
                    qkJsUdT.SetSize(qXMUYT + 3, 1);
                    qrEZrs.SetSize(qXMUYT + 3, 1);
                    qkJsUdT.GetAt(qXMUYT) = qkJsUdT.GetAt(qxWmVch[0]);
                    qrEZrs.GetAt(qXMUYT) = aColors[qhQRuW];
                    qaGEwZ[qVduN] = qXMUYT;
                    qVduN++;
                    qXMUYT++;
                    qkJsUdT.GetAt(qXMUYT) = qkJsUdT.GetAt(qxWmVch[1]);
                    qrEZrs.GetAt(qXMUYT) = aColors[qhQRuW];
                    qaGEwZ[qVduN] = qXMUYT;
                    qVduN++;
                    qXMUYT++;
                    qkJsUdT.GetAt(qXMUYT) = qkJsUdT.GetAt(qxWmVch[2]);
                    qrEZrs.GetAt(qXMUYT) = aColors[qhQRuW];
                    qaGEwZ[qVduN] = qXMUYT;
                    qVduN++;
                    qXMUYT++;
                }
                else
                {
                    qaGEwZ[qVduN] = qxWmVch[0];
                    qVduN++;
                    qaGEwZ[qVduN] = qxWmVch[1];
                    qVduN++;
                    qaGEwZ[qVduN] = qxWmVch[2];
                    qVduN++;
                }
            }
            unsigned short qpydTG[3];
            qidnYUK->GetTris(&qpydTG[0], &qpydTG[1], &qpydTG[2]);
            for (unsigned short qOFvKuu = 0; qOFvKuu < 3; qOFvKuu++)
            {
                unsigned int qxDeKK = qpia + 1;
                bool qZNIZJV = qidnYUK->EdgeHasExtraInfo(qOFvKuu);
                if (xbShowPortals && qpydTG[qOFvKuu] != 0xffff)
                {
                    NavMeshPtr qfpzU(qsSDDgz);
                    NavTriX* qYdAnhh = 0;
                    bool qoPB = false;
                    unsigned short qQGWBE = 0xffff;
                    if (qZNIZJV)
                    {
                        EdgeInfoX* qXSF = reinterpret_cast<EdgeInfoX*>(static_cast<NavMesh*>(qsSDDgz)->GetEdgeInfo(qrUCJDN, qOFvKuu));
                        if (qXSF && qXSF->pTarget && qXSF->pTarget->IsLoaded())
                        {
                            qXSF->pTarget->GetMesh(qfpzU);
                            unsigned int qgqKr = qXSF->usTri;
                            qYdAnhh = reinterpret_cast<NavTriX*>(static_cast<NavMesh*>(qfpzU)->GetTriangle(qgqKr));
                            unsigned short qGTHx[3];
                            qYdAnhh->GetTris(&qGTHx[0], &qGTHx[1], &qGTHx[2]);
                            for (int qBMjHz = 0; qBMjHz < 3; qBMjHz++)
                            {
                                if (qYdAnhh->EdgeHasExtraInfo(qBMjHz))
                                {
                                    EdgeInfoX* qoqcoe = reinterpret_cast<EdgeInfoX*>(static_cast<NavMesh*>(qfpzU)->GetEdgeInfo(qgqKr, qBMjHz));
                                    if (qoqcoe)
                                    {
                                        NavMeshPtr qVCM;
                                        qoqcoe->pTarget->GetMesh(qVCM);
                                        if (qVCM == qsSDDgz && qoqcoe->usTri == qrUCJDN)
                                        {
                                            qoPB = true;
                                            qQGWBE = qBMjHz;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        qYdAnhh = reinterpret_cast<NavTriX*>(static_cast<NavMesh*>(qsSDDgz)->GetTriangle(qpydTG[qOFvKuu]));
                        unsigned short qRBAdC[3];
                        qYdAnhh->GetTris(&qRBAdC[0], &qRBAdC[1], &qRBAdC[2]);
                        for (int qQirx = 0; qQirx < 3; qQirx++)
                        {
                            if (qRBAdC[qQirx] == qrUCJDN)
                            {
                                qoPB = true;
                                qQGWBE = qQirx;
                            }
                        }
                    }
                    if (qoPB)
                    {
                        unsigned int qdmSnI = qArxcFu + 1;
                        unsigned short qSuoDt = qxWmVch[qOFvKuu];
                        unsigned short qbGYp = qxWmVch[(qOFvKuu + 1) % 3];
                        Pt3X qzzQr = reinterpret_cast<Pt3X&>(static_cast<NavMesh*>(qsSDDgz)->Vertices.GetAt(qSuoDt));
                        Pt3X qsAu = reinterpret_cast<Pt3X&>(static_cast<NavMesh*>(qsSDDgz)->Vertices.GetAt(qbGYp));
                        Pt3X qArJcY = reinterpret_cast<Pt3X&>(static_cast<NavMesh*>(qsSDDgz)->Vertices.GetAt(qxWmVch[(qOFvKuu + 2) % 3]));
                        float qnuVZg = 0.37f;
                        float qqtISP = 0.33f;
                        float qdbVTq = 0.3f;
                        Pt3X qHVMR = qsAu * qnuVZg + qzzQr * qqtISP + qArJcY * qdbVTq;
                        unsigned short qhxpxJd[3];
                        qYdAnhh->GetVerts(&qhxpxJd[0], &qhxpxJd[1], &qhxpxJd[2]);
                        if (false && qQGWBE > 2)
                        {
                        }  // release build: index assert compiled out
                        Pt3X qyFp = reinterpret_cast<Pt3X&>(static_cast<NavMesh*>(qfpzU)->Vertices.GetAt(qhxpxJd[qQGWBE]));
                        Pt3X qVar = reinterpret_cast<Pt3X&>(static_cast<NavMesh*>(qfpzU)->Vertices.GetAt(qhxpxJd[(qQGWBE + 1) % 3]));
                        Pt3X qOqnE = reinterpret_cast<Pt3X&>(static_cast<NavMesh*>(qfpzU)->Vertices.GetAt(qhxpxJd[(qQGWBE + 2) % 3]));
                        Pt3X qkbsJ = qyFp * qnuVZg + qVar * qqtISP + qOqnE * qdbVTq;
                        qZWI.GetAt(qArxcFu) = qHVMR;
                        qZWI.GetAt(qdmSnI) = qkbsJ;
                        qrKBG.GetAt(qArxcFu) = true;
                        qrKBG.GetAt(qdmSnI) = false;
                        qpqRa.GetAt(qArxcFu) = aColors[2];
                        qpqRa.GetAt(qdmSnI) = aColors[9];
                        qArxcFu += 2;
                    }
                }
                if (qpydTG[qOFvKuu] > qrUCJDN || qZNIZJV)
                {
                    qDdzMIp.GetAt(qpia) = reinterpret_cast<Pt3X&>(static_cast<NavMesh*>(qsSDDgz)->Vertices.GetAt(qxWmVch[qOFvKuu]));
                    qDdzMIp.GetAt(qxDeKK) = reinterpret_cast<Pt3X&>(static_cast<NavMesh*>(qsSDDgz)->Vertices.GetAt(qxWmVch[(qOFvKuu + 1) % 3]));
                    qHXYKT.GetAt(qpia) = true;
                    qHXYKT.GetAt(qxDeKK) = false;
                    if (qpydTG[qOFvKuu] != 0xffff)
                    {
                        if (qZNIZJV)
                        {
                            qGfbX.GetAt(qpia) = aColors[0];
                            qGfbX.GetAt(qxDeKK) = aColors[0];
                        }
                        else
                        {
                            qGfbX.GetAt(qpia) = aColors[0];
                            qGfbX.GetAt(qxDeKK) = aColors[0];
                        }
                    }
                    else
                    {
                        unsigned short qXGDO = 0;
                        bool qnEqwa = false;
                        bool qtOMjSX = false;
                        if (qOFvKuu < 2u)
                            qidnYUK->GetEdgeCoverData(qOFvKuu, &qXGDO, &qnEqwa, &qtOMjSX);
                        switch (qXGDO)
                        {
                        case 0:
                            qGfbX.GetAt(qpia) = aColors[6];
                            qGfbX.GetAt(qxDeKK) = aColors[6];
                            break;
                        case 1:
                            qGfbX.GetAt(qpia) = aColors[10];
                            qGfbX.GetAt(qxDeKK) = aColors[10];
                            break;
                        case 2:
                            qGfbX.GetAt(qpia) = aColors[5];
                            qGfbX.GetAt(qxDeKK) = aColors[5];
                            break;
                        case 0xf:
                            qGfbX.GetAt(qpia) = aColors[9];
                            qGfbX.GetAt(qxDeKK) = aColors[9];
                            break;
                        default:
                            qGfbX.GetAt(qpia) = aColors[7];
                            qGfbX.GetAt(qxDeKK) = aColors[7];
                            break;
                        }
                        if (xbShowCover && qXGDO > 1u)
                        {
                            float qObI = xGetCoverHeight(qXGDO);
                            NiAVObject* qYePyBl = xMakeLine(qDdzMIp.GetAt(qpia), qDdzMIp.GetAt(qxDeKK), xfCoverWidth,
                                                        xfCoverWidth, qObI, 0.0f, qGfbX.GetAt(qpia), 0);
                            reinterpret_cast<NiNode*>(static_cast<NodeX*>(qAhbO))->AttachChildInAvailableSlot(qYePyBl, true);
                            Pt3X qZgNzZy = qDdzMIp.GetAt(qpia) - qDdzMIp.GetAt(qxDeKK);
                            qZgNzZy.Unitize();
                            qZgNzZy *= xfCoverScale;
                            if (qnEqwa)
                            {
                                Pt3X qqrLNms = qDdzMIp.GetAt(qxDeKK) - qZgNzZy;
                                Pt3X qYvz = qDdzMIp.GetAt(qxDeKK) + qZgNzZy;
                                NiAVObject* qrBzVM = xMakeLine(qqrLNms, qYvz, xfCoverWidth2, xfCoverWidth2,
                                                           qObI + xfCoverOffset, 0.0f, aColors[10], 0);
                                reinterpret_cast<NiNode*>(static_cast<NodeX*>(qAhbO))->AttachChildInAvailableSlot(qrBzVM, true);
                            }
                            if (qtOMjSX)
                            {
                                Pt3X qCVSV = qDdzMIp.GetAt(qpia) - qZgNzZy;
                                Pt3X qOPw = qDdzMIp.GetAt(qpia) + qZgNzZy;
                                NiAVObject* qjThF = xMakeLine(qCVSV, qOPw, xfCoverWidth2, xfCoverWidth2,
                                                          qObI + xfCoverOffset, 0.0f, aColors[10], 0);
                                reinterpret_cast<NiNode*>(static_cast<NodeX*>(qAhbO))->AttachChildInAvailableSlot(qjThF, true);
                            }
                        }
                    }
                    qpia += 2;
                }
            }
        }
        qbXcw = new Pt3X[qpia];
        qJDuOZ = new ColorX[qpia];
        qxQHW = new bool[qpia];
        memcpy(qbXcw, &qDdzMIp.GetAt(0), qpia * sizeof(Pt3X));
        memcpy(qJDuOZ, &qGfbX.GetAt(0), qpia * sizeof(ColorX));
        memcpy(qxQHW, &qHXYKT.GetAt(0), qpia);
        NiPointer<NiAVObject> qrzAir(new LinesX(qpia, qbXcw, qJDuOZ, 0, 0, 0, qxQHW));
        NiPointer<BSShaderNoLightingProperty> qdqWL(new BSShaderNoLightingProperty());
        ((BSShaderNoLightingProperty*)qdqWL)->SetFlag(0x20, false);
        ((NiAVObject*)qrzAir)->AttachProperty(qdqWL);
        ((NiAVObject*)qrzAir)->AttachProperty(spWireframe);
        ((NiAVObject*)qrzAir)->AttachProperty(spZBuffer);
        ((NiAVObject*)qrzAir)->NiAVObject_SetTranslate(reinterpret_cast<NiPoint3*>(Pt3PodX().Set(0.0f, 0.0f, 1.0f)));
        NiPointer<NiAVObject> qvyWyw(0);
        if (qArxcFu > 0)
        {
            Pt3X* qOHwfb = new Pt3X[qArxcFu];
            ColorX* qkPflib = new ColorX[qArxcFu];
            bool* qEXZLB = new bool[qArxcFu];
            memcpy(qOHwfb, &qZWI.GetAt(0), qArxcFu * sizeof(Pt3X));
            memcpy(qkPflib, &qpqRa.GetAt(0), qArxcFu * sizeof(ColorX));
            memcpy(qEXZLB, &qrKBG.GetAt(0), qArxcFu);
            qvyWyw = new LinesX(qArxcFu, qOHwfb, qkPflib, 0, 0, 0, qEXZLB);
            qdqWL = new BSShaderNoLightingProperty();
            ((BSShaderNoLightingProperty*)qdqWL)->SetFlag(0x20, false);
            ((NiAVObject*)qvyWyw)->AttachProperty(qdqWL);
            ((NiAVObject*)qvyWyw)->AttachProperty(spZBuffer);
            ((NiAVObject*)qvyWyw)->NiAVObject_SetTranslate(reinterpret_cast<NiPoint3*>(Pt3PodX().Set(0.0f, 0.0f, 3.0f)));
        }
        qFffvLe = new Pt3X[qXMUYT];
        qZAdkzg = new ColorX[qXMUYT];
        memcpy(qFffvLe, &qkJsUdT.GetAt(0), qXMUYT * sizeof(Pt3X));
        memcpy(qZAdkzg, &qrEZrs.GetAt(0), qXMUYT * sizeof(ColorX));
        NiPointer<NiAVObject> qpTd(new TriShapeX(qXMUYT, qFffvLe, 0, qZAdkzg, 0, 0, 0, qMBds, qaGEwZ));
        ((NiAVObject*)qpTd)->SetName(FixedText("NavMesh Triangles"));
        NiPointer<BSShaderNoLightingProperty> qSVM(new BSShaderNoLightingProperty());
        ((BSShaderNoLightingProperty*)qSVM)->SetFlag(0x20, false);
        ((NiAVObject*)qpTd)->AttachProperty(spVertexColor);
        ((NiAVObject*)qpTd)->AttachProperty(spZBuffer);
        ((NiAVObject*)qpTd)->AttachProperty(qSVM);
        ((NiAVObject*)qpTd)->NiAVObject_SetTranslate(reinterpret_cast<NiPoint3*>(Pt3PodX().Set(0.0f, 0.0f, 1.0f)));
        for (unsigned int qMFd = 0; qMFd < static_cast<NavMesh*>(qsSDDgz)->GetAvoidNodeCount(); qMFd++)
        {
            AvoidSphere* qsCroYH = &static_cast<NavMesh*>(qsSDDgz)->NavMesh_GetAvoidNode(qMFd);
            ColorX qODE(0.25f, 0.0f, 0.0f, 0.5f);
            NiPointer<NiAVObject> qFwpo(xMakeSphere(qsCroYH->GetRadius(), 10, 10, &qODE));
            NiPointer<AlphaX> qmgeiw(new AlphaX());
            ((AlphaX*)qmgeiw)->SetAlphaBlending(true);
            ((NiAVObject*)qFwpo)->AttachProperty(qmgeiw);
            ((NiAVObject*)qFwpo)->NiAVObject_SetTranslate(const_cast<NiPoint3*>(&qsCroYH->FUN_006815c0()));
            reinterpret_cast<NiNode*>(static_cast<NodeX*>(qAhbO))->AttachChildInAvailableSlot(qFwpo, true);
        }
        reinterpret_cast<NiNode*>(static_cast<NodeX*>(qAhbO))->AttachChildInAvailableSlot(qrzAir, true);
        reinterpret_cast<NiNode*>(static_cast<NodeX*>(qAhbO))->AttachChildInAvailableSlot(qpTd, true);
        if (qArxcFu > 0)
            reinterpret_cast<NiNode*>(static_cast<NodeX*>(qAhbO))->AttachChildInAvailableSlot(qvyWyw, true);
        xUpdateNode(qAhbO);
        xPrepareNode(qAhbO, 0, 0);
    }
    if (abUpdate)
    {
        NiUpdateData qBQkjNg(0.0f, false, false);
        ((NodeX*)xspNavRoot)->Update(qBQkjNg);
        ((NodeX*)xspNavRoot)->UpdateSceneObject();
    }
}

struct WorldPointer : public GO
{
    WorldPointer(NiAVObject* object = 0);
    ~WorldPointer();
};
struct QueryQueue
{
    bool NiTMapBase_DFALL_NiTMapItem_bhkRigidBody_NiPointer_ObstacleData_bhkRigidBody_NiPointer_ObstacleData_GetAt(int key, WorldPointer* result);
    void RemoveKey(int key);
};
struct RenderTask
{
    void UpdateChildByKey(int key);
};
// @fnv 0x006a5bb0
void RenderTask::UpdateChildByKey(int key)
{
    WorldPointer child(0);
    if (reinterpret_cast<QueryQueue*>(reinterpret_cast<char*>(this) + 0x200)->NiTMapBase_DFALL_NiTMapItem_bhkRigidBody_NiPointer_ObstacleData_bhkRigidBody_NiPointer_ObstacleData_GetAt(key, &child))
    {
        reinterpret_cast<NiNode*>(static_cast<unsigned int>(static_cast<const GO&>(g_011d6e5c)))
            ->RemoveObject(reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(static_cast<const GO&>(child))));
        NiUpdateData updateData(0.0f, false, false);
        reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(static_cast<const GO&>(g_011d6e5c)))->Update(updateData);
        reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(static_cast<const GO&>(g_011d6e5c)))->UpdateSceneObject();
        reinterpret_cast<QueryQueue*>(reinterpret_cast<char*>(this) + 0x200)->RemoveKey(key);
    }
}

struct NavTriStub
{
    unsigned short ObjCount();
    bool Flag(unsigned int);
    bool Check3b70();
    bool Check0e70();
    bool Check5ec0();
    bool Check3b90();
};

struct NavRenderStub
{
    int GetNavTriColor(NavTriStub* pTri);
};

// Returns a color code chosen from the triangle's object count and its flags/checks, defaulting to 0.
// @fnv 0x006a5da0
int NavRenderStub::GetNavTriColor(NavTriStub* pNavTri)
{
    int iColorCode = 0;
    if (pNavTri->ObjCount() > 0)
    {
        if (pNavTri->Flag(0x100))
        {
            iColorCode = 12;
        }
        else
        {
            iColorCode = 11;
        }
    }
    else if (pNavTri->Check3b70())
    {
        if (pNavTri->Check0e70())
        {
            iColorCode = 5;
        }
        else if (pNavTri->Check5ec0())
        {
            iColorCode = 8;
        }
        else
        {
            iColorCode = 13;
        }
    }
    else if (pNavTri->Check5ec0())
    {
        iColorCode = 7;
    }
    else if (pNavTri->Check3b90())
    {
        iColorCode = 14;
    }
    else if (pNavTri->Check0e70())
    {
        iColorCode = 4;
    }
    else if (pNavTri->Flag(0x1000))
    {
        iColorCode = 9;
    }
    else if (pNavTri->Flag(0x80000000))
    {
        iColorCode = 16;
    }
    return iColorCode;
}

