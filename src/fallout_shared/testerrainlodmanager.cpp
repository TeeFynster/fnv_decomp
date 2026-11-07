// fallout_shared/testerrainlodmanager.cpp: free functions (11 functions)

#include "../../include/MEM_CONTEXT.h"
#include "layout_support.h"
#include "../../include/AutoMemContext.h"
#include "../../include/AutoMemHelper.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiAdditionalGeometryData.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiBound.h"
#include "../../include/NiRenderer.h"
#include "../../include/Setting.h"
#include "../../include/NiNode.h"
#include "../../include/NiPlane.h"
#include "../../include/BSFogProperty.h"
#include "../../include/NiFrustum.h"

extern "C" void* __cdecl memcpy(void*, const void*, size_t);
#pragma intrinsic(memcpy)

extern NiFixedString* DAT_011c6224;

// @fnv 0x0057d090
// src: COMMUNITY 0x0057d090
NiFixedString* FixedStrings_GetGrass()
{
    return DAT_011c6224;
}

extern float DAT_01200500;
extern float DAT_01200504;

// @fnv 0x0057ce70
void __cdecl SetWindMagnitudeRange(float afWindMagMin, float afWindMagMax)
{
    DAT_01200500 = afWindMagMin;
    DAT_01200504 = afWindMagMax;
}

float tanf_0057dd90(float value);

// @fnv 0x0057dd70
// src: XBOX_PDB 0x0057dd70
float tan_0057dd70(float value)
{
    return tanf_0057dd90(value);
}

extern "C" double __cdecl FUN_00eca590(double);

// @fnv 0x0057dd90
// src: XBOX_PDB 0x0057dd90
float tanf_0057dd90(float value)
{
    return static_cast<float>(FUN_00eca590(value));
}

extern void* DAT_011ca43c;
extern void* DAT_011ca440;
extern int DAT_011ca444;

struct FUN_0057ce90_shell
{
    ~FUN_0057ce90_shell();
};

// Decrements DAT_011ca444; when it reaches zero, deletes DAT_011ca43c and DAT_011ca440 and clears both pointers.
// @fnv 0x0057ce90
FUN_0057ce90_shell::~FUN_0057ce90_shell()
{
    if (--DAT_011ca444 == 0)
    {
        if (DAT_011ca43c)
        {
            void* p = DAT_011ca43c;
            operator delete(p);
            DAT_011ca43c = 0;
        }
        if (DAT_011ca440)
        {
            void* q = DAT_011ca440;
            operator delete(q);
            DAT_011ca440 = 0;
        }
    }
}

float __cdecl FloatFloor(float);
// Truncates p[0] and p[1] to ints via FUN_00404040 and packs x into the high 16 bits and y into the low 16 bits.
// @fnv 0x0057ddb0
int __cdecl PackFloatPairToInt(float* afValues)
{
    int x;
    int y;
    x = (int)FloatFloor(afValues[0]);
    y = (int)FloatFloor(afValues[1]);
    return (x << 16) | (y & 0xffff);
}

struct TallGrassShaderProperty
{
    static int __cdecl GetCacheIdentifier();
};
void __cdecl SetWindMagnitudeRange(float, float);
extern void* DAT_011ca43c;
extern void* DAT_011ca440;
extern int DAT_011ca444;
extern Setting g_011ca48c;
extern Setting g_011ca510;
extern Setting g_011ca524;

struct FUN_0057cd10
{
    char _pad_0[1];
    FUN_0057cd10();
};

// @fnv 0x0057cd10
FUN_0057cd10::FUN_0057cd10()
{
    if (!DAT_011ca444)
    {
        int isizecap = (TallGrassShaderProperty::GetCacheIdentifier() << 8) / *g_011ca524.Int();
        if (!DAT_011ca43c)
            DAT_011ca43c = new NiPoint3[isizecap * isizecap];
        if (!DAT_011ca440)
            DAT_011ca440 = new int[isizecap * isizecap];
    }
    DAT_011ca444++;
    SetWindMagnitudeRange(*g_011ca48c.Float(), *g_011ca510.Float());
}

namespace fnv_0057cf00 {
extern double DAT_01011588;
extern Setting DAT_011ca450;
extern Setting g_011ca4ac;
extern Setting g_011ca498;
extern Setting g_011c63cc;
extern float DAT_011ca434;
extern NiNode* DAT_011ca438;
extern bool DAT_011ca430;

// Computes a clamped max range from settings and stores it, then creates a named NiNode, attaches it at index 6, and sets a flag.
// @fnv 0x0057cf00
void UpdateTerrainLODMaxRange()
{
    AutoMemHelper tempMemContext(
        0x1c, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESTerrainLODManager.cpp", 0x90);
    float fmaxrange = 0.0f;
    if (*DAT_011ca450.Float() >= *g_011ca4ac.Float() + 0.5f)
        fmaxrange = *DAT_011ca450.Float() + *g_011ca498.Float();
    if (fmaxrange > (float)(unsigned int)(*g_011c63cc.Int() << 12))
        fmaxrange = (float)(unsigned int)(*g_011c63cc.Int() << 12);
    DAT_011ca434 = fmaxrange;
    ShadowSceneNode* pbasenode = NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0);
    DAT_011ca438 = new NiNode(0);
    DAT_011ca438->SetName(*FixedStrings_GetGrass());
    pbasenode->ReplaceNthObject(6, DAT_011ca438);
    DAT_011ca438->UpdateSceneObject();
    DAT_011ca430 = true;
}
}  // namespace fnv_0057cf00

namespace TerrainLOD {
extern const char DAT_010310d8[];
struct TwoComponentVector
{
    float x, y;
    TwoComponentVector(float, float);
};
struct UpdateData
{
    float time;
    unsigned int flags, unk08;
    UpdateData(float, bool, bool);
};
struct FixedName;
FixedName* FixedStrings_GetGrass();
struct TerrainNode
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual TerrainNode* Find(FixedName*);
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void Attach(TerrainNode*, bool);
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
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    TerrainNode(unsigned short);
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void AssignFixedString(FixedName*);
    void FUN_00b5d9f0(TerrainNode*, int);
    void NiAVObject_Update(UpdateData*);
    void UpdateProperties();
};
struct Cell
{
    float TESObjectCELL_GetDistanceFromPoint(NiPoint3*);
    int FUN_00544c60();
    int FUN_00544c30();
};
struct World
{
    void* FUN_005f36f0();
    Cell* FUN_00451900(int, int);
};
extern World* DAT_011dea10;
extern Setting DAT_011ca4f0, DAT_011ca480, DAT_011ca450, DAT_011ca498, DAT_011ca4ac;
extern bool DAT_0118c000, DAT_011ca430, DAT_011f9ef0;
extern TerrainNode* DAT_011ca438;
TerrainNode* FUN_00450b80(int);
void FUN_00b62970();
void UpdateTerrainLODMaxRange();
void TallGrassShaderProperty_SetFadeParameters(float, float, float, float);
void TESTerrainLODManager_UpdateGrassForCell(Cell*, TerrainNode*, NiPoint3, NiPoint3, float, float, float);
void TallGrassShaderProperty_RemoveFromCell(int, int);
// @fnv 0x0057d0a0
// src: XBOX_PDB 0x0057d0a0
void TESTerrainLODManager_UpdateGrass(NiPoint3 position, NiPoint3 direction, float scale)
{
    AutoMemContext contextSlot1(28, true, DAT_010310d8, 177);
    if (DAT_011dea10->FUN_005f36f0() || !*DAT_011ca4f0.FUN_00408d60() || !DAT_0118c000)
    {
        FUN_00b62970();
        return;
    }
    if (!DAT_011ca430)
        UpdateTerrainLODMaxRange();
    DAT_011f9ef0 = *DAT_011ca480.FUN_00408d60();
    float farDistanceSlot0 = *DAT_011ca450.Setting_Float_00403e20() + *DAT_011ca498.Setting_Float_00403e20();
    float nearDistanceSlot2 = *DAT_011ca450.Setting_Float_00403e20();
    if (*DAT_011ca450.Setting_Float_00403e20() < *DAT_011ca4ac.Setting_Float_00403e20() + 0.5f)
        return;
    if (!DAT_011ca438)
    {
        TerrainNode* rootSlot0 = FUN_00450b80(0);
        TerrainNode* foundSlot8 = rootSlot0->Find(FixedStrings_GetGrass());
        DAT_011ca438 = foundSlot8;
        if (!DAT_011ca438)
        {
            DAT_011ca438 = new TerrainNode(0);
            DAT_011ca438->AssignFixedString(FixedStrings_GetGrass());
            rootSlot0->Attach(DAT_011ca438, true);
        }
    }
    TallGrassShaderProperty_SetFadeParameters(0, 0, nearDistanceSlot2, farDistanceSlot0);
    if (true)
    {
        int cellXSlot13 = 0;
        int cellYSlot13 = 0;
        cellXSlot13 = (int)position.x / 4096;
        cellYSlot13 = (int)position.y / 4096;
        if (position.x < 0.0)
            --cellXSlot13;
        if (position.y < 0.0)
            --cellYSlot13;
        Cell* cellSlot17 = DAT_011dea10->FUN_00451900(cellXSlot13, cellYSlot13);
        TwoComponentVector relativeSlot42(position.x, position.y);
        relativeSlot42.x -= float(cellXSlot13 << 12);
        relativeSlot42.y -= float(cellYSlot13 << 12);
        for (int row = 0; row < 5; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                cellSlot17 = DAT_011dea10->FUN_00451900(cellXSlot13 + row - 2, cellYSlot13 + column - 2);
                if (cellSlot17)
                {
                    bool skip = true;
                    if (row != 0 && row != 4 && column != 0 && column != 4 &&
                        farDistanceSlot0 > cellSlot17->TESObjectCELL_GetDistanceFromPoint(&position))
                    {
                        TESTerrainLODManager_UpdateGrassForCell(cellSlot17, DAT_011ca438, position, direction, nearDistanceSlot2, farDistanceSlot0,
                                     scale);
                        skip = false;
                    }
                    if (skip)
                        TallGrassShaderProperty_RemoveFromCell(cellSlot17->FUN_00544c30(), cellSlot17->FUN_00544c60());
                }
            }
        }
    }
    if (DAT_011ca480.GetBoolValue())
        FUN_00450b80(0)->FUN_00b5d9f0(DAT_011ca438, 0);
    if (DAT_011ca438)
    {
        UpdateData update(0, false, false);
        DAT_011ca438->NiAVObject_Update(&update);
        DAT_011ca438->UpdateProperties();
    }
}
}

// Terrain LOD grass/object sampling pass: builds a culling frustum from the camera, then walks the
// loaded cells' height samples and dispatches matching object records.
struct CellForm
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c();
    virtual void v020(), v024(), v028(), v02c(), v030(), v034(), v038(), v03c();
    virtual void v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c();
    virtual void v060(), v064(), v068(), v06c(), v070(), v074(), v078(), v07c();
    virtual void v080(), v084(), v088(), v08c(), v090(), v094(), v098();
    virtual unsigned char IsInFrustum(void* apPlanes);
    virtual void v0a0(), v0a4(), v0a8(), v0ac(), v0b0(), v0b4(), v0b8(), v0bc();
    virtual void v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(), v0dc();
    virtual void v0e0(), v0e4(), v0e8(), v0ec(), v0f0(), v0f4(), v0f8(), v0fc();
    virtual void v100(), v104(), v108(), v10c(), v110(), v114(), v118(), v11c();
    virtual void v120(), v124(), v128(), v12c(), v130(), v134(), v138(), v13c();
    virtual void v140(), v144(), v148(), v14c(), v150(), v154(), v158(), v15c();
    virtual void v160(), v164(), v168(), v16c(), v170(), v174(), v178(), v17c();
    virtual void v180(), v184();
    virtual unsigned char Get188();
    virtual void v18c();
    virtual unsigned char Get190();
    virtual void v194(), v198(), v19c();
    virtual unsigned short Get1a0();
    virtual void v1a4();
    virtual int Get1a8();
};
struct FUN_0045c620
{
    NiPlane m_akPlanes[6];
    unsigned int m_uiActive;
    unsigned int m_uiPad;
    FUN_0045c620();
    void SetFromFrustum(const void* apFrustum, void* apTransform);
};
struct Tmp53a510
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    void FUN_0053a510();
};
NiRenderer* NiXenonRenderer_GetRenderer();
struct CamNode
{
    const NiFrustum& GetViewFrustum();
    void* NiAVObject_GetWorldRotate();
};
struct ModelOps
{
    CellForm* NiObjectNET_GetControllers();
};
struct Node45
{
    ModelOps* FUN_006629f0();
    float BSSceneGraph_GetCameraFOV();
};
Node45* Main_GetWorldSceneGraph();
struct CellObj
{
    const NiBound& NiAVObject_GetWorldBound();
};
struct Obj30
{
    NiPoint3 TESObjectLAND_GetVertexLocation(unsigned char, unsigned short, int, int);
    int** TESObjectLAND_GetGrassParameters(int, int);
};
struct NiNodeHelper
{
    Node45* FUN_0043b4a0();
};
struct FormKind
{
    int FUN_0044ddc0();
};
struct Mgr
{
    int FUN_0054ddd0();
    Obj30* TESObjectCELL_GetLand();
    float TESObjectCELL_GetWaterHeight();
    int FUN_00544c30();
    int FUN_00544c60();
    CellObj* GetCellNodeAt(unsigned int);
    NiNodeHelper* FUN_00456fc0(int, unsigned int);
};
extern unsigned char DAT_011ca534;
int FUN_0057ce60();
bool _TallGrassShaderProperty_ContainsChunk(const char*, const char*);
CellForm* _ref_004839c0(int);
void TallGrassShaderProperty_RemoveFromTerrainChunk(int);
float __cdecl tan_0057dd70(float);
int __cdecl PackFloatPairToInt(float*);
void __cdecl GenerateGrassPositions(int, int, int, Obj30*, int, const NiPoint3*, int, NiPoint3, int*, int*, float,
                                    float, unsigned short, int, float, unsigned char, unsigned char);

// @fnv 0x0057d4f0
// src: COMMUNITY 0x0057d4f0
void __cdecl TESTerrainLODManager_UpdateGrassForCell(Mgr* apMgr, int aiParam, NiPoint3 akPos, NiPoint3 akDir, float afParam1, float afRadius,
                          float afFov)
{
    int iQuad;
    if (DAT_011ca534)
        return;
    int** ppEntries = 0;
    int iEntry;
    BSSimpleList<const char*> kModelList;
    CellForm* pBase = 0;
    Tmp53a510 kHelper;
    kHelper.FUN_0053a510();
    unsigned short usW = 0;
    unsigned char bFlagA6 = 0;
    unsigned char bFlagB = 0;
    NiPoint3 kTmpPt;
    int iSampleIdx;
    NiPoint3 kPosB;
    NiPoint3 kPos;
    int iStart4 = FUN_0057ce60();
    int iDelta = iStart4 * 2;
    int iCount2 = 8;
    if (apMgr == 0 || apMgr->FUN_0054ddd0() == 0 || apMgr->TESObjectCELL_GetLand() == 0)
        return;
    float fScaleF4 = apMgr->TESObjectCELL_GetWaterHeight();
    Obj30* pData30 = apMgr->TESObjectCELL_GetLand();
    int m_iGridPositionX = apMgr->FUN_00544c30();
    int iLodLevel5 = apMgr->FUN_00544c60();
    iSampleIdx = 0;
    akDir.z = 0.0f;
    akDir.Unitize_004a0c10();
    afFov = afFov * 2.0f;
    NiFrustum kFrust;
    kFrust.Init(false);
    float fW = (float)NiXenonRenderer_GetRenderer()->FUN_004dee70();
    float fScreenH4 = (float)NiXenonRenderer_GetRenderer()->FUN_004dee10();
    float kFAspectRatio = fW / fScreenH4;
    float fFactorB = 0.75 / (fW / fScreenH4);
    float fTheta = Main_GetWorldSceneGraph()->BSSceneGraph_GetCameraFOV() * 0.01745329238474369 * 0.5 + afFov;
    kFrust.m_fLeftBound = -tan_0057dd70(fTheta) * fFactorB;
    kFrust.m_fRightBound = tan_0057dd70(fTheta) * fFactorB;
    kFrust.m_fBottomBound = -tan_0057dd70(fTheta) * kFAspectRatio * fFactorB;
    kFrust.m_fTopBound = tan_0057dd70(fTheta) * kFAspectRatio * fFactorB;
    NiFrustum kViewFrustum_2 = ((CamNode*)Main_GetWorldSceneGraph()->FUN_006629f0())->GetViewFrustum();
    kFrust.m_fFarPlane = kViewFrustum_2.m_fFarPlane;
    kFrust.m_fNearPlane = kViewFrustum_2.m_fNearPlane;
    FUN_0045c620 kTester;
    kTester.SetFromFrustum(&kFrust, ((CamNode*)Main_GetWorldSceneGraph()->FUN_006629f0())->NiAVObject_GetWorldRotate());
    for (iQuad = 0; iQuad < 4; iQuad++)
    {
        CellObj* pCell = apMgr->GetCellNodeAt(iQuad);
        if (pCell)
        {
            NiPoint3 kStartPt = pData30->TESObjectLAND_GetVertexLocation(0, 0, 0, 0);
            int iV1b8 = 0;
            // Copy the bound's representation without invoking its shared copy constructor.
            unsigned int kBounds[sizeof(NiBound) / sizeof(unsigned int)];
            memcpy(kBounds, &pCell->NiAVObject_GetWorldBound(), sizeof(NiBound));
            NiPoint3 kNone = NiPoint3::ZERO;
            float fDist = (akPos - *reinterpret_cast<NiBound*>(kBounds)->FUN_006815c0()).Length() -
                          reinterpret_cast<const NiBound*>(kBounds)->FUN_0084d030();
            Node45* pAt = apMgr->FUN_00456fc0(2, iQuad)->FUN_0043b4a0();
            int eState = ((FormKind*)pAt->FUN_006629f0()->NiObjectNET_GetControllers())->FUN_0044ddc0();
            unsigned char bProjectedOnScreen = pAt->FUN_006629f0()->NiObjectNET_GetControllers()->IsInFrustum(&kTester);
            if ((eState == 1 || eState == 0 || bProjectedOnScreen) && fDist < afRadius)
            {
                for (int iX = iStart4; iX < 0x10; iX += iDelta)
                {
                    for (int iY = iStart4; iY < 0x10; iY += iDelta)
                    {
                        iSampleIdx = iY * 0x11 + iX;
                        kPos = pData30->TESObjectLAND_GetVertexLocation((unsigned char)iQuad, (unsigned short)iSampleIdx, 0, 0);
                        kPos.z = akPos.z;
                        kPos.x = kPos.x - 256.0;
                        kPos.y = kPos.y - 256.0;
                        iV1b8 = PackFloatPairToInt(&kPos.x);
                        ppEntries = pData30->TESObjectLAND_GetGrassParameters(iQuad, iSampleIdx);
                        iEntry = 0;
                        while (ppEntries != 0 && ppEntries[iEntry] != 0 && iEntry < 0x10 && ppEntries[iEntry][0] != 0)
                        {
                            if (ppEntries[iEntry] != 0)
                            {
                                if (!_TallGrassShaderProperty_ContainsChunk((const char*)ppEntries[iEntry][1], (const char*)iV1b8))
                                {
                                    pBase = _ref_004839c0(ppEntries[iEntry][1]);
                                    if (pBase != 0)
                                    {
                                        usW = pBase->Get1a0();
                                        iCount2 = pBase->Get1a8();
                                        bFlagB = pBase->Get190();
                                        bFlagA6 = pBase->Get188();
                                    }
                                    GenerateGrassPositions(m_iGridPositionX, iLodLevel5, iQuad, pData30, iV1b8, &kPos, aiParam,
                                                           akPos, ppEntries[iEntry], ppEntries[iEntry] + 8, afParam1,
                                                           afRadius, usW, iCount2, fScaleF4, bFlagA6, bFlagB);
                                }
                            }
                            iEntry++;
                        }
                    }
                }
            }
            else
            {
                for (int iX2 = iStart4; iX2 < 0x10; iX2 += iDelta)
                {
                    for (int iY2 = iStart4; iY2 < 0x10; iY2 += iDelta)
                    {
                        iSampleIdx = iY2 * 0x11 + iX2;
                        kPos = pData30->TESObjectLAND_GetVertexLocation((unsigned char)iQuad, (unsigned short)iSampleIdx, 0, 0);
                        kPos.x = kPos.x - 256.0;
                        kPos.y = kPos.y - 256.0;
                        int iSample = PackFloatPairToInt(&kPos.x);
                        TallGrassShaderProperty_RemoveFromTerrainChunk(iSample);
                    }
                }
            }
        }
        kModelList.RemoveAll();
    }
}

namespace fnv_0057de00 {

// Unit-local view of NiPointer for 0x0057de00 (namespace fnv_0057de00): built on the shared NiPointer, that code does not compile or does not match.
template <class T> class NiPointer_0057de00
{
  public:
    T* m_pObject;
    NiPointer_0057de00(T* pObject = 0);
    ~NiPointer_0057de00();
};


class FUN_00414430_Color
{
  public:
    float r, g, b, a;
    FUN_00414430_Color(float fR, float fG, float fB, float fA);
};

class FUN_0053a510_LandData
{
  public:
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
    FUN_0053a510_LandData();
};

class LODLand
{
  public:
    bool TESPackage_GetLockDoorsAtStart();
    bool TESObjectLAND_GetCoordData(FUN_0053a510_LandData* pkData, NiPoint3* pkPos, int iUnused);
    void ComputeTerrainNormalAndTangent(FUN_0053a510_LandData* pkData, NiPoint3* pkNormal, NiPoint3* pkSlope);
    void GetLandColor_0(FUN_0053a510_LandData* pkData, FUN_00414430_Color* pkColor);
};

class LODWorld
{
  public:
    void GetLandHeightAt(NiPoint3* pkPos, float* pfHeight);
    void TES_GetLandNormal(NiPoint3* pkPos, NiPoint3* pkNormal, NiPoint3* pkSlope);
    void TES_GetLandColor(NiPoint3* pkPos, FUN_00414430_Color* pkColor);
};
extern LODWorld* DAT_011dea10;

struct LODSettings
{
    int unk00;
    int unk04;
    float m_fHorizontalSpacing;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    bool bSlopeOnly;
    bool unk1d;
    bool bUseSlope;
};

extern Setting DAT_011ca524;
extern NiPoint3* DAT_011ca43c;
extern float* DAT_011ca440;

float NiCosQ(float fAngleDifference);
int FUN_0057ce60();
bool TallGrassShaderProperty_ContainsChunk(LODSettings* pkSettings, void* pvOwner);
float RandomFloatNeg1To1();
float FloatFloor(float fValue);
int TruncateFloatToInt(float fValue);
int FUN_00944460(int iMin, int iMax);
void PopulateGrassInstances(void* pvOwner, int iA, int iB, int iC, LODSettings* pkSettings, NiPoint3* pkPositions,
                            float* pfValues, int iCount);

// Samples a grid over the land, tests density and height/slope filters, and stores accepted positions and luminance values for the owner.
// @fnv 0x0057de00
void GenerateGrassPositions(int iA, int iB, int iUnused08, LODLand* pkLand, void* pvOwner, const NiPoint3& kBase,
                            int iC, NiPoint3 akStart, LODSettings* pkSettings, float* afDensityGrid, int iUnused34,
                            float fRadius, unsigned short usRange, int iMode, float afHeight, unsigned char ucMinAngle,
                            unsigned char ucMaxAngle)
{
    AutoMemContext kMemContextRef(MEM_CONTEXT_MEM_CONTEXT_GRASS, true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESTerrainLODManager.cpp",
                                  522);
    NiPointer_0057de00<BSFogProperty> spProperty;
    NiPoint3 kUnusedRef;
    float fMinSlopeRes = NiCosQ(ucMinAngle * 0.017453292f);
    float fMaxSlopeValue = NiCosQ(ucMaxAngle * 0.017453292f);
    fRadius *= fRadius;
    void* pvLandOwnerPos = pvOwner;
    bool bNotLoadedNew = !TallGrassShaderProperty_ContainsChunk(pkSettings, pvLandOwnerPos);
    if (!bNotLoadedNew || !pkLand->TESPackage_GetLockDoorsAtStart())
        return;

    float fLodSize = FUN_0057ce60() << 8;
    unsigned short usSteps = (int)(fLodSize / pkSettings->m_fHorizontalSpacing);
    unsigned short usMaxStepsNew = (FUN_0057ce60() << 8) / *DAT_011ca524.Setting_Int();
    if (usSteps > usMaxStepsNew)
        usSteps = usMaxStepsNew;
    FUN_0053a510_LandData kTheLandData;
    unsigned short usCountOld = 0;
    for (int i = 0; i < usSteps; i++)
    {
        for (int j = 0; j < usSteps; j++)
        {
            NiPoint3 kPosPos = kBase + NiPoint3(i * (fLodSize / usSteps), j * (fLodSize / usSteps), 0.0f);
            float fNewV = j * (3.0 / usSteps);
            float fTextureCoordinateU = i * (3.0 / usSteps);
            int iColEntry = TruncateFloatToInt(fTextureCoordinateU);
            int iRowNew = TruncateFloatToInt(fNewV);
            fTextureCoordinateU -= iColEntry;
            fNewV -= iRowNew;
            float fDensityAtRowColumn = 0.0f;
            float fAdjacentDensityGridValue = 0.0f;
            float fH01Out = 0.0f;
            float fH11Info = 0.0f;
            fDensityAtRowColumn = afDensityGrid[iRowNew * 3 + iColEntry];
            if (fTextureCoordinateU > 0.01)
            {
                if (iColEntry < 2)
                    fAdjacentDensityGridValue = afDensityGrid[iRowNew * 3 + iColEntry + 1];
                else
                    fAdjacentDensityGridValue = afDensityGrid[iRowNew * 3 + iColEntry];
                if (fNewV > 0.01)
                {
                    if (iRowNew < 2)
                    {
                        if (iColEntry < 2)
                            fH11Info = afDensityGrid[(iRowNew + 1) * 3 + iColEntry + 1];
                        else
                            fH11Info = afDensityGrid[(iRowNew + 1) * 3 + iColEntry];
                    }
                    else
                    {
                        if (iColEntry < 2)
                            fH11Info = afDensityGrid[iRowNew * 3 + iColEntry + 1];
                        else
                            fH11Info = afDensityGrid[iRowNew * 3 + iColEntry];
                    }
                }
            }
            if (fNewV > 0.01)
            {
                if (iRowNew < 2)
                    fH01Out = afDensityGrid[(iRowNew + 1) * 3 + iColEntry];
                else
                    fH01Out = afDensityGrid[iRowNew * 3 + iColEntry];
            }
            float fDensityIn =
                ((1.0f - fTextureCoordinateU) * fDensityAtRowColumn + fAdjacentDensityGridValue * fTextureCoordinateU) *
                    (1.0f - fNewV) +
                ((1.0f - fTextureCoordinateU) * fH01Out + fH11Info * fTextureCoordinateU) * fNewV;
            int iChanceRes = (unsigned int)(fDensityIn * 32768.0);
            if (iChanceRes && FUN_00944460(0, 0x7fff) < iChanceRes)
            {
                float fGroundZ = 0.0f;
                float fRandTmp = RandomFloatNeg1To1();
                kPosPos.x += fRandTmp * pkSettings->m_fHorizontalSpacing;
                fRandTmp = RandomFloatNeg1To1();
                kPosPos.y += fRandTmp * pkSettings->m_fHorizontalSpacing;
                kPosPos.x = FloatFloor(kPosPos.x);
                kPosPos.y = FloatFloor(kPosPos.y);
                kPosPos.z = 0.0f;
                bool bOnLand = pkLand->TESObjectLAND_GetCoordData(&kTheLandData, &kPosPos, 0);
                DAT_011dea10->GetLandHeightAt(&kPosPos, &fGroundZ);
                switch (iMode)
                {
                case 0:
                    if (afHeight - usRange > fGroundZ)
                        continue;
                    break;
                case 1:
                    if (fGroundZ < afHeight || afHeight + usRange < fGroundZ)
                        continue;
                    break;
                case 2:
                    if (afHeight - usRange < fGroundZ)
                        continue;
                    break;
                case 3:
                    if (fGroundZ > afHeight || afHeight - usRange > fGroundZ)
                        continue;
                    break;
                case 4:
                    if (afHeight + usRange > fGroundZ && afHeight - usRange < fGroundZ)
                        continue;
                    break;
                case 5:
                    if (afHeight + usRange < fGroundZ || afHeight - usRange > fGroundZ)
                        continue;
                    break;
                }
                NiPoint3 kOffsetOld = kPosPos - akStart;
                kPosPos.z = FloatFloor(fGroundZ);
                NiPoint3 kNormal;
                NiPoint3 kSlopeValue;
                if (bOnLand)
                    pkLand->ComputeTerrainNormalAndTangent(&kTheLandData, &kNormal, &kSlopeValue);
                else
                    DAT_011dea10->TES_GetLandNormal(&kPosPos, &kNormal, &kSlopeValue);
                if (pkSettings->bUseSlope && pkSettings->bSlopeOnly)
                    kNormal = kSlopeValue;
                else if (pkSettings->bUseSlope && !pkSettings->bSlopeOnly)
                {
                    kNormal = kNormal + kSlopeValue;
                    kNormal.Unitize_004a0c10();
                }
                if (kNormal.z < fMaxSlopeValue || kNormal.z > fMinSlopeRes)
                    continue;
                kNormal.x = kNormal.x * 0.5 + 0.5;
                if (kNormal.x >= 0.97f)
                    kNormal.x = 0.97f;
                kNormal.y = kNormal.y * 0.5 + 0.5;
                if (kNormal.y >= 0.97f)
                    kNormal.y = 0.97f;
                kNormal.z = kNormal.z * 0.5 + 0.5;
                if (kNormal.z >= 0.97f)
                    kNormal.z = 0.97f;
                kPosPos.x += kNormal.x;
                kPosPos.y += kNormal.y;
                kPosPos.z += kNormal.z;
                FUN_00414430_Color kColor(0.0f, 0.0f, 0.0f, 0.0f);
                if (bOnLand)
                    pkLand->GetLandColor_0(&kTheLandData, &kColor);
                else
                    DAT_011dea10->TES_GetLandColor(&kPosPos, &kColor);
                float fLuminanceNum = kColor.r * 0.31 + kColor.g * 0.37 + kColor.b * 0.32;
                kOffsetOld = kPosPos - akStart;
                DAT_011ca43c[usCountOld] = kPosPos;
                DAT_011ca440[usCountOld] = fLuminanceNum;
                usCountOld++;
            }
        }
    }
    if (usCountOld > 0)
        PopulateGrassInstances(pvLandOwnerPos, iA, iB, iC, pkSettings, DAT_011ca43c, DAT_011ca440, usCountOld);
}
}  // namespace fnv_0057de00
