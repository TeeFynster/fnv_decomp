// fallout_shared/bgsdecalmanager.cpp: BGSDecalManager and decal helpers (61 functions)

// Use the checked layouts in place of the generated legacy base layouts.
#include "layout_support.h"
#define FNV_NIOBJECT_H
#define FNV_NIREFOBJECT_H
#define FNV_NIPOINT3_H
#include "../../include/NiColorA.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiGeometryData.h"
#include "../../include/NiTriBasedGeomData.h"
#include "../../include/NiPoint3.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/NiMatrix3.h"
#include "../../include/NiPoint3.h"
#include "../../include/hkVector4.h"

// The decal interfaces keep their own pointer/list wrappers (DecalNiPointer, DecalNiTPointerListBase, ...).
#include "bgsdecalmanager_decls.h"
#include "bgsdecalmanager_types_BGSDecalManager.h"
#include "bgsdecalmanager_types_BSTempEffectSimpleDecal.h"
#include "../../include/GO.h"
#include "../../include/RecursiveLock.h"
#include "../../include/Setting.h"
#include "../../include/TESForm.h"
#include "../../include/BSCullingProcess.h"

// @fnv 0x004a0030
void BGSDecalManager::RenderDecals()
{
    if (reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(&m_kSimpleDecalList)->GetSize() > 0)
    {
        NiXenonRenderer_GetRenderer()->StartScene();
        struct IteratorState
        {
            unsigned int previous;
            unsigned int position;
        } iterator;
        iterator.position = reinterpret_cast<unsigned int>(static_cast<BSFaceGenAnimationData*>(
            *reinterpret_cast<DecalNiPointer<BSFaceGenAnimationData>*>(&m_kSimpleDecalList)));
        while (iterator.position != 0)
        {
            iterator.previous = iterator.position;
            BSTempEffectSimpleDecal* decal = reinterpret_cast<BSTempEffectSimpleDecal*>(
                static_cast<BSFaceGenAnimationData*>(reinterpret_cast<DecalNiPointer<BSFaceGenAnimationData>&>(
                    reinterpret_cast<DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>, DecalNiPointer<NiProperty> >*>(
                        &m_kSimpleDecalList)
                        ->GetNext(reinterpret_cast<void*&>(iterator.position)))));
            if (decal != 0)
            {
                if (decal->m_bNeedsManagerUpdate)
                {
                    RemoveDecal(decal);
                    decal->m_bNeedsManagerUpdate = false;
                }

                if (decal->m_pRenderQuery != 0)
                {
                    if (decal->ReleaseTextureObject())
                    {
                        if (decal->m_uiTextureReferenceCount > 0)
                        {
                            if (*DAT_011c5904.FUN_00408d60())
                                Warning(DAT_0101e1c8, reinterpret_cast<FirstPointerStringView_0043b1b0*>(decal->BSTempEffectSimpleDecal_GetDecalParent()->GetLinkToList())->FUN_0043b1b0());
                            reinterpret_cast<DecalVtableCall*>(decal)->vfn_8c();
                        }
                        else
                        {
                            if (*DAT_011c5904.FUN_00408d60())
                                Warning(DAT_0101e19c, reinterpret_cast<FirstPointerStringView_0043b1b0*>(decal->BSTempEffectSimpleDecal_GetDecalParent()->GetLinkToList())->FUN_0043b1b0());
                            decal->bWasPlaying = true;
                        }
                    }
                }
                else
                {
                    reinterpret_cast<DecalVtableCall*>(decal)->vfn_8c();
                }

                if (decal->m_bTextureDirty && !decal->bWasPlaying)
                    decal->CreateDecalTexture();

                if (decal->bWasPlaying)
                {
                    if (decal->GetByteAt2D())
                    {
                        ++DAT_011c57ec;
                        if (*DAT_011c5904.FUN_00408d60())
                            Warning(DAT_0101e174, DAT_011c57ec, reinterpret_cast<FirstPointerStringView_0043b1b0*>(decal->BSTempEffectSimpleDecal_GetDecalParent()->GetLinkToList())->FUN_0043b1b0());

                        if (DAT_011c57f4 & 1)
                        {
                            NiColorA color(0.0f, 1.0f, 0.0f, 1.0f);
                            decal->SetDecalTint(reinterpret_cast<NiColorA&>(color), true);
                        }
                        if (DAT_011c57f4 & 2)
                        {
                            NiColorA color(0.0f, 1.0f, 0.0f, 0.25f);
                            decal->SetDecalTint(reinterpret_cast<NiColorA&>(color), false);
                        }
                    }
                    else if (DAT_011c57f4 & 0x10)
                    {
                        if (DAT_011c57f4 & 1)
                        {
                            NiColorA color(1.0f, 0.0f, 0.0f, 1.0f);
                            decal->SetDecalTint(reinterpret_cast<NiColorA&>(color), true);
                        }
                        if (DAT_011c57f4 & 2)
                        {
                            NiColorA color(1.0f, 0.0f, 0.0f, 0.25f);
                            decal->SetDecalTint(reinterpret_cast<NiColorA&>(color), false);
                        }
                    }
                    reinterpret_cast<DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>, DecalNiPointer<NiProperty> >*>(
                        &m_kSimpleDecalList)
                        ->RemovePos(reinterpret_cast<void*&>(iterator.previous));
                }
            }
        }
        NiXenonRenderer_GetRenderer()->FinishScene();
    }
}

// @fnv 0x00460140
// src: XBOX_PDB 0x00460140
int __fastcall TESDataHandler_GetWorldSpaceList(int apBase)
{
    return apBase + 0x10;
}

struct NiStream;
// @fnv 0x004769c0
void NiMatrix3::SetCol(unsigned int uiCol, const float* col)
{
    ((float(*)[3])&m_pEntry[0][0])[0][uiCol] = col[0];
    ((float(*)[3])&m_pEntry[0][0])[1][uiCol] = col[1];
    ((float(*)[3])&m_pEntry[0][0])[2][uiCol] = col[2];
}

class Date
{
  public:
    ~Date();
};

void __fastcall NiCriticalSection_Lock(void*);
int __fastcall CallNestedAtOffset80(void*);

// @fnv 0x004a0370
// src: XBOX_PDB 0x004a0370
void __fastcall NiXenonRenderer_LockRenderer(char* pThis)
{
    NiCriticalSection_Lock(pThis + 0x80);
    if (CallNestedAtOffset80(pThis) == 1)
    {
        ((Date*)pThis)->Date::~Date();
    }
}

namespace fnv_004a03c0 {
struct Date
{
    ~Date();
};
struct DD : Date
{
    int CallNestedAtOffset80();
    void NiXenonRenderer_UnlockRenderer();
};
// @fnv 0x004a03c0
// src: XBOX_PDB 0x004a03c0
void DD::NiXenonRenderer_UnlockRenderer()
{
    if (CallNestedAtOffset80() == 1)
        Date::~Date();
    ((RecursiveLock*)((char*)this + 0x80))->Leave();
}
}  // namespace fnv_004a03c0

// Writes the negated x, y and z components into out and returns out.
// @fnv 0x004a0bd0
// src: GUESS 0x004a0bd0 (confidence: high)
NiPoint3* NiPoint3::GetNegatedVector(NiPoint3* out)
{
    out->Set(-x, -y, -z);
    return out;
}

// @fnv 0x004a0d10
// src: COMMUNITY 0x004a0d10
void* __fastcall TESDataHandler_GetImpactDataSetList(char* pThis)
{
    return pThis + 0x100;
}

template <> class DecalNiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    DecalNiPointer<NiNode>& operator=(NiNode*);
};

struct FUN_004a0fd0_shell
{
    char pad[0xc4];
    DecalNiPointer<NiNode> m_pController;
    void BSCullingProcess_SetAccumulator(NiNode* apNode);
};

// @fnv 0x004a0fd0
// src: COMMUNITY 0x004a0fd0
void FUN_004a0fd0_shell::BSCullingProcess_SetAccumulator(NiNode* apNode)
{
    m_pController = apNode;
}

struct BSA_
{
    void BSShaderAccumulator_SetShadowSceneNode(void*);
};
// @fnv 0x004a1020
// src: XBOX_PDB 0x004a1020
void BSA_::BSShaderAccumulator_SetShadowSceneNode(void* p)
{
    *(void**)((char*)this + 0x194) = p;
}

struct FUN_004a1040_Helper
{
    char pad[0x19c];
    int field_19c;
    void Set(int val);
};

// @fnv 0x004a1040
void FUN_004a1040_Helper::Set(int val)
{
    field_19c = val;
}

struct Fake_FUN_004a2020
{
    char pad[0x20];
    unsigned int ulFlags[2];
    bool GetFlag(unsigned int aiFlag) const;
};

static bool (Fake_FUN_004a2020::*pfn_FUN_004a2020)(unsigned int) const = &Fake_FUN_004a2020::GetFlag;

// Tests whether the bit for aiFlag is set in the ulFlags bit array, indexing by aiFlag>>5 and masking with 1<<(aiFlag%32).
// @fnv 0x004a2020
bool Fake_FUN_004a2020::GetFlag(unsigned int aiFlag) const
{
    unsigned int uiindex = aiFlag >> 5;
    unsigned int uibit = aiFlag % 32;
    unsigned int uimask = 1 << uibit;
    return (ulFlags[uiindex] & uimask) > 0;
}

#include "../../include/BGSTerrainManager.h"
// Returns 0 for a null pointer, otherwise returns whether GetMinLevel() is between 1 and 12.
// @fnv 0x004a2c20
// src: XBOX_PDB 0x004a2c20
int __cdecl BSSM_ShaderPropertyIsLighting(BGSTerrainManager* apShaderProp)
{
    if (!apShaderProp)
    {
        return 0;
    }
    int itp = apShaderProp->GetMinLevel();
    return itp >= 1 && itp <= 12;
}



struct NiPoint3_local
{
    float x, y, z;
};

// Reads components 0, 1 and 2 of arhkV into arNiP.x, arNiP.y and arNiP.z and returns arNiP.
// @fnv 0x004a3970
// src: XBOX_PDB 0x004a3970
NiPoint3_local& __cdecl HK2NINS(NiPoint3_local& arNiPoint, const hkVector4& arHkVector)
{
    __declspec(align(16)) char t0[16], t1[16], t2[16];
    arNiPoint.x = arHkVector.hkVector4_getSimdAt(*reinterpret_cast<hkSimdReal*>(t0), 0).getReal();
    arNiPoint.y = arHkVector.hkVector4_getSimdAt(*reinterpret_cast<hkSimdReal*>(t1), 1).getReal();
    arNiPoint.z = arHkVector.hkVector4_getSimdAt(*reinterpret_cast<hkSimdReal*>(t2), 2).getReal();
    return arNiPoint;
}

struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
typedef char _sizecheck_CFilter[sizeof(CFilter) == 4 ? 1 : -1];
struct FUN_004a39f0_shell : public CFilter
{
    void CFilter_SetLayer(int);
};

// Clears the low 7 bits of iFilter and stores the low 7 bits of aeLayer into them.
// @fnv 0x004a39f0
// src: XBOX_PDB 0x004a39f0
void FUN_004a39f0_shell::CFilter_SetLayer(int aeLayer)
{
    iFilter &= ~0x7f;
    iFilter |= (aeLayer & 0x7f);
}

namespace fnv_004a3a20 {
struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
typedef char _sizecheck_CFilter[sizeof(CFilter) == 4 ? 1 : -1];
struct FUN_004a3a20_shell : public CFilter
{
    unsigned int CFilter_GetGroup();
};

// @fnv 0x004a3a20
// src: XBOX_PDB 0x004a3a20
unsigned int FUN_004a3a20_shell::CFilter_GetGroup()
{
    return (iFilter >> 16) & 0xFFFF;
}
}  // namespace fnv_004a3a20


// Returns the flags of apRef, or 0 when apRef is null.
// @fnv 0x004a3a40
// src: XBOX_PDB 0x004a3a40
unsigned int __cdecl bhkShape_Getbhk(TESObjectREFR* apRef)
{
    return apRef ? apRef->GetFlags() : 0;
}

void __fastcall hkpAllRayHitCollector_reset(void*);

struct Base_004a3b30
{
    int pad[3];
    Base_004a3b30();
    virtual ~Base_004a3b30();
};

struct Member_004a4730
{
    Member_004a4730(int);
    ~Member_004a4730();
};

struct FUN_004a3a70 : Base_004a3b30
{
    Member_004a4730 m;
    FUN_004a3a70();
    virtual ~FUN_004a3a70();
};

// Initializes the base subobject, constructs member m with 0, then calls FUN_004a3b70 on this.
// @fnv 0x004a3a70
FUN_004a3a70::FUN_004a3a70() : m(0)
{
    hkpAllRayHitCollector_reset(this);
}

class NiAVObject;
class hkpPhantom;
class hkpRigidBody;
namespace fnv_004a3da0 {
struct FourComponentNumericValue;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct blob16
{
    char b[16];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
typedef char _sizecheck_hkpWorldRayCastInput[sizeof(WorldRayCastInput) == 48 ? 1 : -1];
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
typedef char _sizecheck_hkpShapeRayCastCollectorOutput[sizeof(RayCastHitResult) == 32 ? 1 : -1];
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
typedef char _sizecheck_hkpShapeRayCastOutput[sizeof(ShapeRayCastOutput) == 80 ? 1 : -1];
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
typedef char _sizecheck_hkpWorldRayCastOutput[sizeof(WorldRayCastOutput) == 96 ? 1 : -1];
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
typedef char _sizecheck_bhkPickData[sizeof(BhkPickData) == 176 ? 1 : -1];
struct FUN_004a3da0_shell : public BhkPickData
{
    void bhkPickData_SetFrom(void*);
};


struct FUN_0056d340_helper
{
    void bhkPickData_SetFrom_0056d340(hkVector4&);
};

hkVector4& __cdecl NI2HK(hkVector4&, NiPoint3 const&);

// Converts the NiPoint3 at arFrom into a hkVector4 and passes it to FUN_0056d340 on this object.
// @fnv 0x004a3da0
// src: XBOX_PDB 0x004a3da0
void FUN_004a3da0_shell::bhkPickData_SetFrom(void* arFrom)
{
    // Raw storage preserves the original initialization call and stack protection.
    __declspec(align(16)) char hkv[16];
    reinterpret_cast<hkVector4*>(hkv)->FUN_006815c0();
    ((FUN_0056d340_helper*)this)->bhkPickData_SetFrom_0056d340(NI2HK(*reinterpret_cast<hkVector4*>(hkv), *(const NiPoint3*)arFrom));
}
}  // namespace fnv_004a3da0

void* hkVector4_getZero();
struct T_
{
    void SetValue(void*);
};
struct PD_
{
    void ForwardToSubObject(void*);
    void bhkPickData_SetTo_004a3f40(void*);
};
// Calls ForwardToSubObject with the result of FUN_00458b20, then forwards p to FUN_004a3f10 on the object at this+0x10.
// @fnv 0x004a3f40
// src: XBOX_PDB 0x004a3f40
void PD_::bhkPickData_SetTo_004a3f40(void* p)
{
    ForwardToSubObject(hkVector4_getZero());
    ((T_*)((char*)this + 0x10))->SetValue(p);
}

struct Flt
{
    int v;
    operator unsigned int() const;
};
// @fnv 0x004a3f70
// src: XBOX_PDB 0x004a3f70
void __fastcall bhkPickData_SetFilter(char* self, Flt f)
{
    *(unsigned int*)(self + 0x24) = (unsigned int)f;
}

struct NiAVObject;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
typedef char _sizecheck_hkpWorldRayCastInput[sizeof(WorldRayCastInput) == 48 ? 1 : -1];
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
typedef char _sizecheck_hkpShapeRayCastCollectorOutput[sizeof(RayCastHitResult) == 32 ? 1 : -1];
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
typedef char _sizecheck_hkpShapeRayCastOutput[sizeof(ShapeRayCastOutput) == 80 ? 1 : -1];
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
typedef char _sizecheck_hkpWorldRayCastOutput[sizeof(WorldRayCastOutput) == 96 ? 1 : -1];
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
typedef char _sizecheck_bhkPickData[sizeof(BhkPickData) == 176 ? 1 : -1];
struct FUN_004a3fb0_shell : public BhkPickData
{
    void bhkPickData_SetAllCollector(hkpAllRayHitCollector*);
};

// @fnv 0x004a3fb0
// src: XBOX_PDB 0x004a3fb0
void FUN_004a3fb0_shell::bhkPickData_SetAllCollector(hkpAllRayHitCollector* apCollector)
{
    m_pAllCollector = apCollector;
    m_pClosestCollector = 0;
}

struct NiSourceTexture;
struct ScriptCompiler;
struct ConsoleManager
{
    static ConsoleManager* Instance(bool);
    static void Release();
    ScriptCompiler* QConsoleCompiler();
    void Init();
    void DoThis(char*);
    bool Idle(int);
    void PrintFormatted(char*, ...);
    void PrintFormatted(char*, char*);
    void ScrollBy(int);
    void ResetOutputState();
    bool GetLastMenuMode();
    int GetConsoleLineSpacing();
    void SetOutputFilename(char*);
    void WriteToOutputFile(char*);
    bool IsOutputFileEnabled();
    bool IsVisible();
    void SetVisible(char);
    void OnEnterMenuMode();
    void OnLeaveMenuMode();
    void DumpTextureList();
    bool ShouldDumpTexture(NiSourceTexture*);
    void* __vecDelDtor(unsigned int);
    ScriptCompiler* m_pScriptCompiler;
    char m_kOutputLines[12];
    char m_kCommandHistory[12];
    int m_iCommandHistoryPosition;
    int m_iScrollPosition;
    int m_iOutputLineCount;
    bool m_bVisible;
    char _pad_29[3];
    int iConsoleLineSpacing;
    int m_iConsoleX;
    int m_iConsoleY;
    char cVisible;
    bool bIsActive;
    bool m_bRecordingBatch;
    char _pad_3b[1];
    int m_iBatchCommandCount;
    char m_aacCommandHistory[2000];
    char m_acOutputFilename[260];
};
typedef char _sizecheck_MenuConsole[sizeof(ConsoleManager) == 2324 ? 1 : -1];
struct FUN_004a4020_shell : public ConsoleManager
{
    bool MenuConsole_IsVisible();
};

// @fnv 0x004a4020
// src: XBOX_PDB 0x004a4020
bool FUN_004a4020_shell::MenuConsole_IsVisible()
{
    return cVisible > 0;
}

// @fnv 0x004b4660
void NiMatrix3::SetCol(unsigned int uiIndex, float afValue0, float afValue1, float afValue2)
{
    *(float*)((char*)this + uiIndex * 4) = afValue0;
    *(float*)((char*)this + uiIndex * 4 + 12) = afValue1;
    *(float*)((char*)this + uiIndex * 4 + 24) = afValue2;
}

struct S3e60
{
    bool GetFlag(unsigned int) const;
    bool bhkPickData_SetFrom_0056d340(unsigned int f);
};
// @fnv 0x0056d340
// src: XBOX_PDB 0x0056d340
bool S3e60::bhkPickData_SetFrom_0056d340(unsigned int auiFlag)
{
    return GetFlag(auiFlag);
}

class NiAVObject;
class hkpPhantom;
class hkpRigidBody;
namespace fnv_008cdd90 {
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
typedef char _sizecheck_hkpWorldRayCastInput[sizeof(WorldRayCastInput) == 48 ? 1 : -1];
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
typedef char _sizecheck_hkpShapeRayCastCollectorOutput[sizeof(RayCastHitResult) == 32 ? 1 : -1];
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
typedef char _sizecheck_hkpShapeRayCastOutput[sizeof(ShapeRayCastOutput) == 80 ? 1 : -1];
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
typedef char _sizecheck_hkpWorldRayCastOutput[sizeof(WorldRayCastOutput) == 96 ? 1 : -1];
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
typedef char _sizecheck_bhkPickData[sizeof(BhkPickData) == 176 ? 1 : -1];
struct FUN_008cdd90_shell : public BhkPickData
{
    hkpAllRayHitCollector* DialoguePackage_GetCurrentDialogItem();
};

// @fnv 0x008cdd90
// src: XBOX_PDB 0x008cdd90
hkpAllRayHitCollector* FUN_008cdd90_shell::DialoguePackage_GetCurrentDialogItem()
{
    return m_pAllCollector;
}
}  // namespace fnv_008cdd90

struct BSCompoundFrustum;
struct BSFadeNode;
struct BSMultiBoundNode;
struct BSResizableTriShape;
struct BSSegmentedTriShape;
struct NiAVObject;
struct NiAccumulator;
struct NiCullingProcess;
struct NiLines;
struct NiNode;
struct NiParticles;
struct NiTriBasedGeom;
struct NiTriShape;
struct NiTriStrips;
struct NiVisibleArray;
struct bhkBlendCollisionObject;
struct bhkLimitedHingeConstraint;
struct bhkNiCollisionObject;
struct bhkRigidBody;

struct FUN_00a69400
{
    FUN_00a69400(NiVisibleArray*);
    virtual ~FUN_00a69400();
    char pad04[0x8c];
};
class FUN_004a0eb0 : public FUN_00a69400
{
  public:
    int i90;
    char pad94[0x28];
    int ibc;
    int ic0;
    GO go;
    FUN_004a0eb0(NiVisibleArray* apVisibleSet);
    virtual ~FUN_004a0eb0();
};
// @fnv 0x004a0eb0
FUN_004a0eb0::FUN_004a0eb0(NiVisibleArray* apVisibleSet) : FUN_00a69400(apVisibleSet), i90(0), ibc(0), ic0(0), go(0)
{}

struct FUN_004a4440
{
    ~FUN_004a4440();
};
struct FUN_004a3ae0
{
    virtual ~FUN_004a3ae0();
    char pad04[0xc];
};
class FUN_004a3bc0 : public FUN_004a3ae0
{
  public:
    FUN_004a4440 hits;
    virtual ~FUN_004a3bc0();
};
// @fnv 0x004a3bc0
FUN_004a3bc0::~FUN_004a3bc0()
{}

extern int g_012030a8;

struct FUN_004a0f50_shell
{
    int* __thiscall GetGlobalIntPtr();
};

// @fnv 0x004a0f50
int* FUN_004a0f50_shell::GetGlobalIntPtr()
{
    return &g_012030a8;
}

struct GlobalObject_0044f440
{
    float FUN_00450410(void);
};

GlobalObject_0044f440 g_011c77a8;

// @fnv 0x004a19f0
// src: COMMUNITY 0x004a19f0
float Display_fDecalLOD0_Get()
{
    return g_011c77a8.FUN_00450410();
}

namespace fnv_004a1a00 {
struct GlobalObject_0044f440
{
    void FUN_00450410();
};

GlobalObject_0044f440 g_011c7588;

// @fnv 0x004a1a00
// src: XBOX_PDB 0x004a1a00
void __cdecl Renderer_GetSkinnedDecalLODStart()
{
    g_011c7588.FUN_00450410();
}
}  // namespace fnv_004a1a00

void __fastcall FUN_004a47b0(int __this);

// @fnv 0x004a1a30
// src: GUESS 0x004a1a30 (confidence: low)
void __fastcall Bgsdecalmanager_ForwardCall_004a1a30(int __this)
{
    FUN_004a47b0(__this);
}

// @fnv 0x004a3b50
// src: XBOX_PDB 0x004a3b50
void __fastcall hkpRayHitCollector_reset(void* thisPtr)
{
    ((float*)thisPtr)[1] = 1.0f;
}

struct FUN_00acbb70_shell
{
    void Return_0();
};

// src: COMMUNITY 0x00acbb70
void FUN_00acbb70_shell::Return_0()
{}

struct FUN_004a03a0_shell
{
    void CallNestedAtOffset80();
};

// @fnv 0x004a03a0
void FUN_004a03a0_shell::CallNestedAtOffset80()
{
    ((FUN_00acbb70_shell*)((char*)this + 0x80))->Return_0();
}

struct FUN_004a0d30_shell
{
    char m_auiShapeKeys[0x34];
    NiPoint3 m_kPoint;
    NiPoint3& BSTempEffectSimpleDecal_GetOrigin(NiPoint3& akDest);
};

// Copies the stored NiPoint3 into akDest and returns akDest.
// @fnv 0x004a0d30
// src: COMMUNITY 0x004a0d30
NiPoint3& FUN_004a0d30_shell::BSTempEffectSimpleDecal_GetOrigin(NiPoint3& akDest)
{
    akDest = m_kPoint;
    return akDest;
}

struct NiPoint3_Set
{
    void Set(float x, float y, float z);
};

// Multiplies pA and pB component-wise, stores the result into pDest via Set, and returns pDest.
// @fnv 0x004a1f90
NiPoint3* MultiplyComponents(NiPoint3* pResult, const NiPoint3* pLeft, const NiPoint3* pRight)
{
    ((NiPoint3_Set*)pResult)->Set(pLeft->x * pRight->x, pLeft->y * pRight->y, pLeft->z * pRight->z);
    return pResult;
}

extern int DAT_0101e594;

struct FUN_004a3ae0_shell
{
    void SetVirtualTable_004a3ae0();
};

// @fnv 0x004a3ae0
// src: GUESS 0x004a3ae0 (confidence: low)
void FUN_004a3ae0_shell::SetVirtualTable_004a3ae0()
{
    *(int*)this = (int)&DAT_0101e594;
}

extern int DAT_0101e594;
void __fastcall hkpRayHitCollector_reset(void*);

struct FUN_004a3b30_shell
{
    int* m_vftable;
    void* InitializeVftable();
};

// @fnv 0x004a3b30
void* __thiscall FUN_004a3b30_shell::InitializeVftable()
{
    m_vftable = &DAT_0101e594;
    hkpRayHitCollector_reset(this);
    return this;
}

void __fastcall hkArrayBase_hkpRootCdBodyPair_clear(void* p);
void __fastcall hkpRayHitCollector_reset(void* p);

// @fnv 0x004a3b70
// src: XBOX_PDB 0x004a3b70
void __fastcall hkpAllRayHitCollector_reset(void* p)
{
    hkArrayBase_hkpRootCdBodyPair_clear((char*)p + 0x10);
    hkpRayHitCollector_reset(p);
}

namespace fnv_004a3f90 {
struct T_
{
    void SetValue(void*);
    void ForwardToSubObject(void*);
};

// @fnv 0x004a3f90
void __thiscall T_::ForwardToSubObject(void* apParam)
{
    ((T_*)((char*)this + 0x90))->SetValue(apParam);
}
}  // namespace fnv_004a3f90

namespace bsrandom_singleton {
struct MersenneTwister
{
    static MersenneTwister* __cdecl GetRandomGenerator(void);
    void __thiscall AddGeometryDecal(void* a, int b, char c);
};
}

struct FUN_004a3fe0_shell
{
    void __thiscall TESObjectCELL_AddDecal(void* a, int b, char c);
};

// @fnv 0x004a3fe0
// src: XBOX_PDB 0x004a3fe0
void __thiscall FUN_004a3fe0_shell::TESObjectCELL_AddDecal(void* pObject, int b, char c)
{
    if (*(int*)((char*)pObject + 0x48) == 0)
    {
        *(int*)((char*)pObject + 0x48) = (int)this;
    }
    bsrandom_singleton::MersenneTwister::GetRandomGenerator()->AddGeometryDecal(pObject, b, c);
}

void __cdecl FUN_00ec6f20(int, int, int, int);
struct FUN_0049f560_Holder
{
    int _00;
    int _04;
    int _08;
    void CallWithTwelve(int);
};
// Calls FUN_00ec6f20 with the holder's _04 and _08 fields, the constant 12, and a1.
// @fnv 0x0049f560
void FUN_0049f560_Holder::CallWithTwelve(int a1)
{
    FUN_00ec6f20(_04, _08, 12, a1);
}

void __cdecl BGSDecalManager_ClearDecalsThisFrame();
struct S004a03f0
{
    void CleanupDecalEmitters();
};
// @fnv 0x0049fff0
// src: COMMUNITY 0x0049fff0
void __fastcall BGSDecalManager_UpdateDecals(BGSDecalManager* p)
{
    BGSDecalManager_ClearDecalsThisFrame();
    p->RenderDecals();
    ((S004a03f0*)p)->CleanupDecalEmitters();
}

void _Deallocate(void*);
struct StandIn
{
    void FUN_004a2cf0();
    void* FUN_004a0490(unsigned int);
};
// Calls FUN_004a2cf0, then if bit 0 of flags is set calls _Deallocate on this, and returns this.
// @fnv 0x004a0490
void* StandIn::FUN_004a0490(unsigned int flags)
{
    FUN_004a2cf0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void _Deallocate(void*);
// Calls FUN_004a0f60, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004a0ff0
void* BSCullingProcess::FUN_004a0ff0(unsigned int flags)
{
    FUN_004a0f60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl SetSelectionMask(int, int, int);
struct Unk
{
    void __thiscall DecalCaster_SetCollision(int, unsigned char);
};
// @fnv 0x004a1a10
// src: XBOX_PDB 0x004a1a10
void __thiscall Unk::DecalCaster_SetCollision(int aiArg, unsigned char b)
{
    SetSelectionMask(0x27, aiArg, b);
}

namespace fnv_004a3b00 {
void _Deallocate(void*);
struct FUN_004a3ae0
{
    virtual ~FUN_004a3ae0();
    void* DestroyAndFree(unsigned int);
};
// Runs the destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x004a3b00
void* FUN_004a3ae0::DestroyAndFree(unsigned int flags)
{
    this->FUN_004a3ae0::~FUN_004a3ae0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_004a3b00

namespace fnv_004a3b90 {
void __cdecl _Deallocate(void*);
struct FUN_004a3bc0
{
    virtual ~FUN_004a3bc0();
};
struct XHolder : FUN_004a3bc0
{
    void* DestroyAndMaybeDeallocate(unsigned int);
};
// Runs the base destructor, then frees this object via _Deallocate when bit 0 of flags is set, and returns this.
// @fnv 0x004a3b90
void* XHolder::DestroyAndMaybeDeallocate(unsigned int flags)
{
    this->FUN_004a3bc0::~FUN_004a3bc0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_004a3b90

struct FUN_004a0350_shell
{
    char bUnk2d;
    char GetByteAt2D();
};

// @fnv 0x004a0350
char FUN_004a0350_shell::GetByteAt2D()
{
    return *(char*)((char*)this + 0x2d);
}

struct FUN_00456630_helper
{
    bool NiAVObject_GetBit(unsigned int);
};

struct FUN_004a19d0_shell
{
    void NiAVObject_GetNoDecals();
};

// @fnv 0x004a19d0
// src: XBOX_PDB 0x004a19d0
void FUN_004a19d0_shell::NiAVObject_GetNoDecals()
{
    reinterpret_cast<FUN_00456630_helper*>(this)->NiAVObject_GetBit(0x400);
}

namespace fnv_004a1a50 {
struct M788
{
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(void*);
};
struct bsrandom_singleton
{
    struct MersenneTwister
    {
        static bsrandom_singleton::MersenneTwister* GetRandomGenerator();
    };
};
// @fnv 0x004a1a50
// src: COMMUNITY 0x004a1a50
void __cdecl BGSDecalManager_AddEmitter(void* apEmitter)
{
    if (apEmitter)
        ((M788*)((char*)bsrandom_singleton::MersenneTwister::GetRandomGenerator() + 0x14))->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(&apEmitter);
}
}  // namespace fnv_004a1a50

namespace fnv_004a0330 {
struct Flt
{
    operator unsigned int() const;
};

struct FUN_004a0330_shell
{
    char pad[0x10c];
    Flt f;
    unsigned int BSTempEffectSimpleDecal_GetDecalParent();
};

// @fnv 0x004a0330
// src: XBOX_PDB 0x004a0330
unsigned int FUN_004a0330_shell::BSTempEffectSimpleDecal_GetDecalParent()
{
    return static_cast<unsigned int>(f);
}
}  // namespace fnv_004a0330

// Calls GetModelData and invokes the triangle data normal operation.
// @fnv 0x004a1ff0
void NiGeometry::CalculateNormals()
{
    static_cast<NiTriBasedGeomData*>(GetModelData())->vf42();
}

namespace fnv_004a2c00 {

struct FUN_004a2c00_shell
{
    char pad[0x34];
    GO m_go;
    void AssignGo(void* arg);
};

// @fnv 0x004a2c00
void FUN_004a2c00_shell::AssignGo(void* arg)
{
    m_go = arg;
}
}  // namespace fnv_004a2c00

struct FUN_004a3cc0_Class
{
    FUN_004a3cc0_Class* hkpWorldRayCastInput_hkpWorldRayCastInput(void);
};

struct Holder
{
    void FUN_004a3c90(Holder*);
};

void* __fastcall hkpWorldRayCastOutput_hkpWorldRayCastOutput(void*);
void* __cdecl hkVector4_getZero(void);

struct FUN_004a3c20
{
    FUN_004a3c20();
    ~FUN_004a3c20();
};

// Constructor: initializes subobjects at offsets 0x00, 0x30 and 0x90, then zeroes fields at 0xa0, 0xa4, 0xa8 and 0xac.
// @fnv 0x004a3c20
FUN_004a3c20::FUN_004a3c20()
{
    ((FUN_004a3cc0_Class*)((char*)this + 0x00))->hkpWorldRayCastInput_hkpWorldRayCastInput();
    hkpWorldRayCastOutput_hkpWorldRayCastOutput((char*)this + 0x30);
    ((Holder*)((char*)this + 0x90))->FUN_004a3c90((Holder*)hkVector4_getZero());
    *(int*)((char*)this + 0xa0) = 0;
    *(int*)((char*)this + 0xa4) = 0;
    *(int*)((char*)this + 0xa8) = 0;
    *(char*)((char*)this + 0xac) = 0;
}

struct StatefulObject
{
    void BGSDecalEmitter_Update();
    bool TESRegionData_GetOverride();
    ~StatefulObject();
};

struct DecalEmitterNode
{
    StatefulObject* emitter;
    DecalEmitterNode* next;
};

struct BGSDecalEmitterList
{
    DecalEmitterNode* head;
    DecalEmitterNode* tail;
    unsigned int count;
    DecalEmitterNode* Modelloader_GetReferencedThis();
    StatefulObject** NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(DecalEmitterNode** cursor);
    void FUN_0049f590(DecalEmitterNode** cursor);
};

struct PendingDecalList
{
    void* head;
    void* tail;
    unsigned int count;
};

struct DecalCleanupOwner
{
    void* queryTexture;
    unsigned int clearQueryTexture;
    PendingDecalList pendingSimpleDecals;
    BGSDecalEmitterList decalEmitters;
    void CleanupDecalEmitters();
};

// Walks the decal emitter list, calls FUN_004a2d50 on each emitter, and deletes those for which FUN_004f1540 returns true.
// @fnv 0x004a03f0
void DecalCleanupOwner::CleanupDecalEmitters()
{
    DecalEmitterNode* cursor = decalEmitters.Modelloader_GetReferencedThis();
    while (cursor != 0)
    {
        DecalEmitterNode* previous = cursor;
        StatefulObject* emitter = *decalEmitters.NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&cursor);
        if (emitter != 0)
        {
            emitter->BGSDecalEmitter_Update();
            if (emitter->TESRegionData_GetOverride())
            {
                decalEmitters.FUN_0049f590(&previous);
                delete emitter;
                emitter = 0;
            }
        }
    }
}

class FUN_004a0f60_sub
{
  public:
    ~FUN_004a0f60_sub();
};

class FUN_004a0f60_base
{
  public:
    virtual void Update();
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
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    virtual ~FUN_004a0f60_base();
};

class FUN_004a0f60_cls : public FUN_004a0f60_base
{
  public:
    FUN_004a0f60_sub m_c4;
    virtual ~FUN_004a0f60_cls();
};

// Destructor of the class; destroys the embedded m_c4 sub-object and the base.
// @fnv 0x004a0f60
FUN_004a0f60_cls::~FUN_004a0f60_cls()
{}

namespace CameraPass {
struct Matrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    void FUN_006815c0();
    void FUN_004a0c90(float);
    Matrix FUN_0043f8d0(const Matrix&);
    void FUN_00476930(int, NiPoint3&);
    void FUN_004769c0(int, const NiPoint3&);
};
void BSUtilities_GetRotationZToVector(Matrix*, NiPoint3);
struct Frustum
{
    float left, right, top, bottom, nearValue, farValue;
    bool ortho;
    Frustum(int);
};
struct Update
{
    unsigned int unk0, unk4, unk8;
    Update(float, int, int);
};
struct Color
{
    float r, g, b, a;
    Color(float, float, float, float);
};
struct Name
{
    const char* FUN_0043b1b0();
};
struct Ref
{
    float NiAVObject_GetWorldScale();
    Name* FUN_00413f40();
};
struct Query
{
    unsigned int unk0;
    Query();
    void BSOcclusionQuery_Begin();
    void BSOcclusionQuery_End();
};
struct Input
{
    unsigned int unk0, unk4, unk8, unkc, unk10, unk14;
    char unk18, unk19, unk1a;
    bool alternate;
    Query* query;
    NiPoint3 BSTempEffectSimpleDecal_GetDirection();
    NiPoint3 BSTempEffectSimpleDecal_GetOrigin();
    float Animation_GetGlobalTimeMultiplier();
    float FUN_00507b20();
    float GetField11C();
    float GetFloatAt120();
    Ref* BSTempEffectSimpleDecal_GetDecalParent();
};
struct Scene
{
    void NiAVObject_SetTranslate(const NiPoint3&);
    void SetRotate_0043fa80(const Matrix&);
    void FUN_00a6faf0(const Frustum&);
    void NiAVObject_Update(Update*);
    NiPoint3 FUN_0045bba0();
    void* TESDataHandler_GetImpactDataSetList();
};
struct ScenePtr
{
    Scene* ptr;
    Scene* Modelloader_GetReferencedThis();
};
struct Node
{
    void BSShaderAccumulator_SetShadowSceneNode(void*);
    void FUN_004a1040(int);
};
struct NodePtr
{
    Node* ptr;
    Node* Modelloader_GetReferencedThis();
};
struct Render
{
    void* FUN_00b6b260();
};
struct RenderPtr
{
    Render* ptr;
    Render* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(Render*);
};
struct Factory
{
    Render* BSTextureManager_BorrowRenderedTexture();
};
int __stdcall BSShaderManager_GetRenderer(int);
Factory* __stdcall BSShaderManager_GetTextureManager(int, int, int, int);
void BSRenderedTexture_StartOffscreen(int, void*);
struct Resource
{
    void NiRenderer_SetScreenSpaceCameraData();
};
Resource* __stdcall NiXenonRenderer_GetRenderer(void*);
void* FUN_00450b80(int);
struct Cull
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    Cull(int);
    ~Cull();
    void BSCullingProcess_SetAccumulator(Node*);
};
void BSShaderUtil_AccumulateScene(Scene*, Ref*, Cull*);
void FUN_00b6c0d0(Scene*, Node*, int);
void FUN_00b6b790();
extern Setting DAT_011c5904;
extern unsigned int DAT_011c57f4;
extern float DAT_0101b268, DAT_0101e2bc, DAT_01018f5c;
extern double DAT_01011590, DAT_0101e2c0;
extern char DAT_0101e298, DAT_0101e274, DAT_0101e24c, DAT_0101e1f8;
void Warning_005b5e40(const char*, ...);
void* MakeLine(const NiPoint3&, const Color&, const NiPoint3&, const Color&, int);
struct World
{
    void FUN_00458e20(void*, float);
};
extern World* DAT_011dea10;
struct Camera
{
    RenderPtr render;
    unsigned int unk4, unk8, unkc, unk10, unk14, unk18, unk1c;
    NodePtr node;
    ScenePtr scene;
    void UpdateCamera(Input*);
};
// @fnv 0x004a04c0
void Camera::UpdateCamera(Input* input)
{
    NiPoint3 directionSlot1Slot0 = input->BSTempEffectSimpleDecal_GetDirection();
    directionSlot1Slot0.Unitize_004a0c10();
    directionSlot1Slot0.ScaleComponents(DAT_0101b268);
    NiPoint3 originSlot13 = input->BSTempEffectSimpleDecal_GetOrigin().FUN_00439e90(directionSlot1Slot0);
    Matrix rotationSlot17Slot12;
    BSUtilities_GetRotationZToVector(&rotationSlot17Slot12, directionSlot1Slot0.GetNegatedVector());
    Matrix scaleSlot22Slot0Slot10;
    scaleSlot22Slot0Slot10.FUN_006815c0();
    scaleSlot22Slot0Slot10.FUN_004a0c90(input->Animation_GetGlobalTimeMultiplier());
    rotationSlot17Slot12 = scaleSlot22Slot0Slot10.FUN_0043f8d0(rotationSlot17Slot12);
    NiPoint3 column0Slot30Slot0;
    NiPoint3 column1Slot41Slot18;
    rotationSlot17Slot12.FUN_00476930(0, column0Slot30Slot0);
    rotationSlot17Slot12.FUN_00476930(1, column1Slot41Slot18);
    rotationSlot17Slot12.FUN_00476930(2, directionSlot1Slot0);
    Matrix basisSlot28Slot36;
    basisSlot28Slot36.FUN_006815c0();
    basisSlot28Slot36.FUN_004769c0(0, directionSlot1Slot0);
    basisSlot28Slot36.FUN_004769c0(1, column0Slot30Slot0);
    basisSlot28Slot36.FUN_004769c0(2, column1Slot41Slot18);
    NiPoint3 startSlot14Slot30;
    NiPoint3 endSlot11;
    float widthSlot15Slot25 = (input->FUN_00507b20() / DAT_01011590) * (1.0f / input->BSTempEffectSimpleDecal_GetDecalParent()->NiAVObject_GetWorldScale());
    float heightSlot21 = (input->GetField11C() / DAT_01011590) * (1.0f / input->BSTempEffectSimpleDecal_GetDecalParent()->NiAVObject_GetWorldScale());
    float farPlaneSlot12Slot43 = input->GetFloatAt120() + DAT_0101e2c0;
    Frustum frustumSlot18Slot39(0);
    frustumSlot18Slot39.ortho = true;
    frustumSlot18Slot39.nearValue = DAT_0101e2bc;
    frustumSlot18Slot39.left = -widthSlot15Slot25;
    frustumSlot18Slot39.right = widthSlot15Slot25;
    frustumSlot18Slot39.top = heightSlot21;
    frustumSlot18Slot39.bottom = -heightSlot21;
    frustumSlot18Slot39.farValue = farPlaneSlot12Slot43;
    scene.Modelloader_GetReferencedThis()->NiAVObject_SetTranslate(originSlot13);
    scene.Modelloader_GetReferencedThis()->SetRotate_0043fa80(basisSlot28Slot36);
    scene.Modelloader_GetReferencedThis()->FUN_00a6faf0(frustumSlot18Slot39);
    Update updateSlot12(0.0f, 0, 0);
    scene.Modelloader_GetReferencedThis()->NiAVObject_Update(&updateSlot12);
    void* lineSlot0Slot21;
    if (DAT_011c57f4 & 4)
    {
        startSlot14Slot30 = originSlot13;
        endSlot11 = originSlot13.FUN_00439e90(scene.Modelloader_GetReferencedThis()->FUN_0045bba0().ApplyScaled(farPlaneSlot12Slot43));
        lineSlot0Slot21 =
            MakeLine(startSlot14Slot30, Color(0.0f, 0.0f, 1.0f, 1.0f), endSlot11, Color(1.0f, 0.0f, 0.0f, 1.0f), 1);
        DAT_011dea10->FUN_00458e20(lineSlot0Slot21, DAT_01018f5c);
    }
    if (*DAT_011c5904.FUN_00408d60())
    {
        NiPoint3 look = scene.Modelloader_GetReferencedThis()->FUN_0045bba0();
        Warning_005b5e40(&DAT_0101e298, input->BSTempEffectSimpleDecal_GetDecalParent()->FUN_00413f40()->FUN_0043b1b0());
        Warning_005b5e40(&DAT_0101e274, originSlot13.x, originSlot13.y, originSlot13.z);
        Warning_005b5e40(&DAT_0101e24c, look.x, look.y, look.z);
        Warning_005b5e40(&DAT_0101e1f8, farPlaneSlot12Slot43, -widthSlot15Slot25, widthSlot15Slot25, heightSlot21,
                     -heightSlot21);
    }
    if (!render.Modelloader_GetReferencedThis())
        render.FUN_0066b0d0(BSShaderManager_GetTextureManager(BSShaderManager_GetRenderer(0x33), 0, 0, 0)->BSTextureManager_BorrowRenderedTexture());
    if (input->alternate)
        BSRenderedTexture_StartOffscreen(7, render.Modelloader_GetReferencedThis()->FUN_00b6b260());
    else
        BSRenderedTexture_StartOffscreen(0, render.Modelloader_GetReferencedThis()->FUN_00b6b260());
    input->query = new Query;
    input->query->BSOcclusionQuery_Begin();
    NiXenonRenderer_GetRenderer(scene.Modelloader_GetReferencedThis()->TESDataHandler_GetImpactDataSetList())->NiRenderer_SetScreenSpaceCameraData();
    Cull cullSlot18Slot33(0);
    cullSlot18Slot33.BSCullingProcess_SetAccumulator(node.Modelloader_GetReferencedThis());
    node.Modelloader_GetReferencedThis()->BSShaderAccumulator_SetShadowSceneNode(FUN_00450b80(0));
    node.Modelloader_GetReferencedThis()->FUN_004a1040(15);
    BSShaderUtil_AccumulateScene(scene.Modelloader_GetReferencedThis(), input->BSTempEffectSimpleDecal_GetDecalParent(), &cullSlot18Slot33);
    FUN_00b6c0d0(scene.Modelloader_GetReferencedThis(), node.Modelloader_GetReferencedThis(), 0);
    cullSlot18Slot33.BSCullingProcess_SetAccumulator(0);
    input->query->BSOcclusionQuery_End();
    FUN_00b6b790();
}
}

class Refr_C
{
  public:
    TESForm* GetAcousticSpace();
};

// Returns false when the reference's acoustic space form type is 35, 42, 43 or 51; otherwise returns true.
// @fnv 0x004a1060
bool __cdecl IsAcousticSpaceFormTypeAllowed(Refr_C* apRef, int aiArg)
{
    int iUnused = aiArg;
    switch (apRef->GetAcousticSpace()->GetFormType())
    {
    case 35:
    case 42:
    case 43:
    case 51:
        return false;
    }
    return true;
}

// QueryPerformanceFrequency/QueryPerformanceCounter come from <windows.h> (read by include/TESFile.h)

namespace DecalAdd {

struct DecalPoint
{
    float x, y, z;
    void FUN_006815c0();
    DecalPoint SubtractIntoVector(const DecalPoint& arOther) const;
    DecalPoint FUN_00439e90(const DecalPoint& arOther) const;
    float FUN_00457990() const;
    void Unitize_004a0c10();
    DecalPoint ApplyScaled(float afScale) const;
};

union DecalTicks
{
    struct
    {
        unsigned int LowPart;
        int HighPart;
    };
    __int64 QuadPart;
};

struct DecalRotation
{
    DecalPoint GetNegatedVector() const;
};

struct DecalBound
{
    float fData[4];
    DecalPoint* FUN_006815c0();
    float FUN_0084d030();
};

struct DecalNode
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual DecalNode* GetNode();
    bool NiAVObject_GetNoDecals();
    DecalBound* NiAVObject_GetWorldBound();
    void* TESObjectCELL_GetbhkWorld();
};

struct DecalHolder
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual DecalNode* Get3D();
};

struct DecalPlayer
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual DecalPoint* GetPos();
};

struct DecalRequest
{
    DecalPoint kPos;
    DecalPoint kWorldPosition;
    char pad18[0xc];
    DecalHolder* pHolder;
    DecalNode* pTarget;
    char pad2c[0xc];
    float m_fGlyphWidthInPixels;
    float m_fGlyphExtent;
    char pad40[8];
    DecalNode* pParent;
    char pad4c[0x25];
    unsigned char bRefresh;
    char pad72[5];
    unsigned char bForce;
};

struct DecalHitList
{
    int iData[3];
    DecalHitList();
    ~DecalHitList();
    int FUN_0049c680(DecalNode** appNode, int aiFlags);
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddHead(DecalNode** appNode);
    void FUN_004ed900();
};

struct DecalEmitter
{
    void DecalCaster_SetCollision(int aiFlag, int aiValue);
    void DecalCaster_Add(void* apNode);
    int DecalCaster_Pick(DecalRequest* apRequest, const DecalPoint& arPos, float afRange);
    DecalNode* GetCollisionFlags(int aiIndex);
    void SetTileSetValues(int aiIndex, DecalPoint* apPos, DecalPoint* apNormal);
};

struct DecalMemContext
{
    int iOldContext;
    DecalMemContext(int aiContext, bool abPush, const char* apFile, int aiLine);
    ~DecalMemContext();
};

struct DecalBoolSetting
{
    unsigned char* FUN_00408d60();
};
struct DecalIntSetting
{
    unsigned int* Setting_Int();
};

extern DecalPlayer* DAT_011dea3c;
extern DecalBoolSetting DAT_011c5834;
extern DecalBoolSetting DAT_011c5884;
extern DecalBoolSetting DAT_011c58bc;
extern DecalBoolSetting DAT_011c5904;
extern DecalIntSetting DAT_011c58e4;
extern unsigned int DAT_011c57f0;
extern DecalEmitter* DAT_011c57e0;
extern DecalRotation DAT_011a9484;

float __cdecl Display_fDecalLOD0_Get();
float __cdecl Renderer_GetSkinnedDecalLODStart();
int __cdecl Warning_005b5e40(const char* apFormat, ...);
int __cdecl BSsprintf(char* apBuffer, unsigned int auiSize, const char* apFormat, ...);
void __cdecl ProgramFlow(const char* apText, int aiFlags);
float __cdecl BSMAX_00404010(float a, float b);
DecalEmitter* __cdecl FUN_00622a70(float afSize, int aiFlags);
void* __cdecl TESObjectREFR_FindReferenceFor3D(DecalNode* apNode);
bool __cdecl IsAcousticSpaceFormTypeAllowed(void* apGeometry, int aiFlags);

static const char s_szSourceFile[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSDecalManager.cpp";
static const char s_szSimpleDecal[] = "DECAL: Simple Decal Instantiated";
static const char s_szTiming[] = "AddGeometryDecalRecurse: Ticks: %I64d, Microseconds: %f";
static const char s_szSkinLimit[] = "DECAL: Reached Max Skin Decal Limit! : %d";

struct DecalManager
{
    int iPad00;
    bool m_bDecalsEnabled;

    void BGSDecalManager_AddGeometryDecalRecurse(DecalRequest* apRequest);
    void BGSDecalManager_AddProjectedDecalRecurse(DecalRequest* apRequest);
    void AddGeometryDecal(DecalRequest* apRequest, int aiType, bool abForce);
};

// Handles decal requests by type, checking distance and force flags in some cases and processing collision hits in another.
// @fnv 0x004a10d0
void DecalManager::AddGeometryDecal(DecalRequest* apRequest, int aiType, bool abForce)
{
    __int64 llEnd;
    DecalPoint kCameraIn;
    float fDistance;
    __int64 llFrequencyCount;
    int iUnused;
    DecalTicks kStartNext;
    double dFrequency;
    DecalMemContext kMemContextRef(7, true, s_szSourceFile, 0x1b8);
    m_bDecalsEnabled = true;
    switch (aiType)
    {
    case 1:
        if (*DAT_011c5834.FUN_00408d60() && apRequest->pTarget && !apRequest->pTarget->NiAVObject_GetNoDecals())
        {
            kCameraIn = *DAT_011dea3c->GetPos();
            fDistance = apRequest->kPos.SubtractIntoVector(kCameraIn).FUN_00457990();
            dFrequency = 1000.0;
            iUnused = 0;
            kStartNext.LowPart = 0;
            char acBuffer[256];
            __int64 llTicks;
            if (*DAT_011c5884.FUN_00408d60())
            {
                QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&llFrequencyCount));
                dFrequency = llFrequencyCount * 1e-06;
                QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&kStartNext.QuadPart));
            }
            if (Display_fDecalLOD0_Get() >= fDistance || apRequest->bForce || abForce)
            {
                if (*DAT_011c5904.FUN_00408d60())
                    Warning_005b5e40(s_szSimpleDecal);
                BGSDecalManager_AddGeometryDecalRecurse(apRequest);
            }
            if (*DAT_011c5884.FUN_00408d60())
            {
                QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&llEnd));
                llTicks = llEnd - kStartNext.QuadPart;
                BSsprintf(acBuffer, 0xff, s_szTiming, llTicks, llTicks / dFrequency);
                ProgramFlow(acBuffer, 0);
            }
        }
        break;
    case 4:
        if (*DAT_011c5834.FUN_00408d60() && apRequest->pTarget && !apRequest->pTarget->NiAVObject_GetNoDecals())
        {
            apRequest->bRefresh = 1;
            BGSDecalManager_AddGeometryDecalRecurse(apRequest);
        }
        break;
    case 2:
        if (*DAT_011c58bc.FUN_00408d60() && apRequest->pTarget && !apRequest->pTarget->NiAVObject_GetNoDecals())
        {
            DecalPoint kEyeOut = *DAT_011dea3c->GetPos();
            DecalBound kBound = *apRequest->pTarget->NiAVObject_GetWorldBound();
            float fBoundDistance = kBound.FUN_006815c0()->SubtractIntoVector(kEyeOut).FUN_00457990() - kBound.FUN_0084d030();
            if ((Renderer_GetSkinnedDecalLODStart() >= fBoundDistance && DAT_011c57f0 < *DAT_011c58e4.Setting_Int()) || abForce)
                BGSDecalManager_AddProjectedDecalRecurse(apRequest);
            else if (DAT_011c57f0 >= *DAT_011c58e4.Setting_Int() && *DAT_011c5904.FUN_00408d60())
                Warning_005b5e40(s_szSkinLimit, *DAT_011c58e4.Setting_Int());
        }
        else if (*DAT_011c58bc.FUN_00408d60() && apRequest->pHolder)
        {
            DecalPoint kViewerNew = *DAT_011dea3c->GetPos();
            DecalBound kHolderBoundCur = *apRequest->pHolder->Get3D()->NiAVObject_GetWorldBound();
            float fHolderDistance = kHolderBoundCur.FUN_006815c0()->SubtractIntoVector(kViewerNew).FUN_00457990() -
                                    kHolderBoundCur.FUN_0084d030();
            DecalNode* pObject = apRequest->pHolder->Get3D();
            DecalNode* pNode = pObject ? pObject->GetNode() : 0;
            if (pNode && !pObject->NiAVObject_GetNoDecals())
            {
                apRequest->pTarget = pNode;
                if ((Renderer_GetSkinnedDecalLODStart() >= fHolderDistance && DAT_011c57f0 < *DAT_011c58e4.Setting_Int()) || abForce)
                    BGSDecalManager_AddProjectedDecalRecurse(apRequest);
                else if (DAT_011c57f0 >= *DAT_011c58e4.Setting_Int() && *DAT_011c5904.FUN_00408d60())
                    Warning_005b5e40(s_szSkinLimit, *DAT_011c58e4.Setting_Int());
            }
        }
        else if (*DAT_011c5834.FUN_00408d60())
        {
            apRequest->kWorldPosition.Unitize_004a0c10();
            if (!DAT_011c57e0)
                DAT_011c57e0 = FUN_00622a70(BSMAX_00404010(apRequest->m_fGlyphExtent, apRequest->m_fGlyphWidthInPixels), 1);
            DAT_011c57e0->DecalCaster_SetCollision(8, 0);
            DAT_011c57e0->DecalCaster_SetCollision(0x1d, 0);
            DAT_011c57e0->DecalCaster_Add(apRequest->pParent->TESObjectCELL_GetbhkWorld());
            int iCount = DAT_011c57e0->DecalCaster_Pick(
                apRequest, apRequest->kPos.FUN_00439e90(apRequest->kWorldPosition.ApplyScaled(80.0f)), 32.0f);
            if (iCount == 0)
            {
                DecalPoint kNewDir =
                    apRequest->kWorldPosition.FUN_00439e90(DAT_011a9484.GetNegatedVector().ApplyScaled(2.0f));
                kNewDir.Unitize_004a0c10();
                apRequest->kWorldPosition = kNewDir;
                iCount = DAT_011c57e0->DecalCaster_Pick(apRequest, apRequest->kPos.FUN_00439e90(kNewDir.ApplyScaled(80.0f)),
                                                    32.0f);
            }
            DecalHitList kHits;
            for (int i = 0; i < iCount; i++)
            {
                DecalPoint kHitPos;
                DecalPoint kHitNormal;
                kHitPos.FUN_006815c0();
                kHitNormal.FUN_006815c0();
                DecalNode* pHitTmp = DAT_011c57e0->GetCollisionFlags(i);
                if (pHitTmp)
                {
                    DAT_011c57e0->SetTileSetValues(i, &kHitPos, &kHitNormal);
                    kHitNormal.Unitize_004a0c10();
                    void* m_pShaderGeometry = TESObjectREFR_FindReferenceFor3D(pHitTmp);
                    if (pHitTmp->NiAVObject_GetNoDecals() || !m_pShaderGeometry ||
                        !IsAcousticSpaceFormTypeAllowed(m_pShaderGeometry, 1))
                        continue;
                    if (!kHits.FUN_0049c680(&pHitTmp, 0))
                    {
                        apRequest->kPos = kHitPos;
                        apRequest->kWorldPosition = kHitNormal;
                        apRequest->pTarget = pHitTmp;
                        BGSDecalManager_AddGeometryDecalRecurse(apRequest);
                        kHits.NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddHead(&pHitTmp);
                    }
                }
            }
            kHits.FUN_004ed900();
        }
        break;
    }
}

}

// 0x004a1a70   /MT /Od /Oy- /GS /EHsc /Gy /GF
// thiscall (ret 4), bool return.
extern "C" int DAT_011c57e4;
extern "C" char DAT_011c5874;
extern "C" char DAT_011c5890;
extern "C" char DAT_011c58a8;
extern "C" char DAT_011c5904x;
extern "C" char DAT_011f4a20;
extern "C" char DAT_011c7d34[];
extern "C" double DAT_01012060;
extern "C" char DAT_0101e420[];
extern "C" char DAT_0101e450[];
extern "C" char DAT_0101e460[];
extern "C" char DAT_0101e468[];
extern "C" char DAT_0101e474[];
extern "C" char DAT_0101e47c[];
extern "C" char DAT_0101e484[];
extern "C" char DAT_0101e490[];

int Warning_005b5e40(const char* fmt, ...);
int FUN_00ec8a19(const char* text, const char* prefix, int len);

struct XObj
{
    NiPoint3& BSTempEffectSimpleDecal_GetOrigin(NiPoint3& out);
    float FUN_00507b20();
};
struct XItem
{
    XObj* Modelloader_GetReferencedThis();
};
struct XList
{
    bool IsEmpty();
    void* FUN_0043b1b0();
    XItem* FUN_006815c0();
    XList* FUN_00726070();
};
struct XObj3D
{
    bool GetFlag(unsigned int flag);
};
struct XNet
{
    XObj3D* GetObject3D();
};
struct XNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    bool GetAppCulled_00456610();
    XNet* FUN_0050d100();
    unsigned int FUN_0043b480();
    XNode* GetAt(unsigned int idx);
    unsigned short FUN_004a1ff0();
    XList* GetTESPackageList();
    char pad4[0xac - 4];
    XList* m_ac;
};
struct XTopicInfo
{
    unsigned int FUN_0043b480();
    XNode* GetAt(unsigned int idx);
};
struct XMenuTopic
{
    XTopicInfo* GetTopicInfo();
};
struct XSetting
{
    int* Int();
    unsigned char* Bool();
};
struct XGA
{
    float FUN_00450410();
};

struct XRef
{
    char pad00[0x28];
    XNode* m28;
    char pad2c[0x0c];
    float m38;
    float m3c;
    char pad40[8];
    void* m48;
    char pad4c[0x10];
    float m5c;
    char pad60[0x12];
    unsigned char m72;
    char pad73[0x39];
    XList* m_ac;
    NiPoint3 PtOp(const NiPoint3& p) const;
};

struct XDoor;
struct XLoc
{
    XLoc(XDoor* d);
    ~XLoc();
    char pad[4];
};
struct XDoor
{
    XDoor(XObj* p, float f, XRef* r);
    static void* operator new(unsigned int sz);
    static void operator delete(void*, unsigned int);
    char pad0[0x1a];
    unsigned char m1a;
    unsigned char m1b;
    char pad2[0x144 - 0x1c];
};
struct XNL
{
    void DecalManager_AppendList08(const XLoc& o);
};
struct XMgr
{
    char pad0[4];
    unsigned char m4;
    char pad5[3];
    XNL m8;
    bool BGSDecalManager_AddGeometryDecalRecurse(XRef* ref);
};

bool NiObject_IsKindOf(const void* rtti, XNode* obj);
bool NiObject_IsExactKindOf(const void* name, XNode* obj);
struct NiPoint3Sq : NiPoint3
{
};
NiPoint3Sq MultiplyComponents(const NiPoint3& a, const NiPoint3& b);

// Checks conditions on ref and related nodes, may construct an XDoor, and calls FUN_0057c590 when ref->m48 is non-null.
// @fnv 0x004a1a70
// src: XBOX_PDB 0x004a1a70
bool XMgr::BGSDecalManager_AddGeometryDecalRecurse(XRef* ref)
{
    const char* pName4;
    XNode* p9;
    XObj3D* objVal;
    XTopicInfo* info2;
    unsigned int i5;
    XNode* av_;
    XList* list;
    XObj* a5;
    XObj* b_;
    XNode* p4;
    XDoor* door3;
    XNode* hit2;
    bool foundVal;

    if (DAT_011c57e4 >= *((XSetting*)&DAT_011c5890)->Int())
    {
        if (((XSetting*)&DAT_011c5904x)->Bool()[0])
            Warning_005b5e40(DAT_0101e490);
        return false;
    }
    if (ref->m28)
    {
        pName4 = (const char*)ref->m28->GetTESPackageList()->FUN_0043b1b0();
        if (pName4 != 0 && (FUN_00ec8a19(pName4, DAT_0101e484, 10) == 0 || FUN_00ec8a19(pName4, DAT_0101e47c, 5) == 0 ||
                            FUN_00ec8a19(pName4, DAT_0101e474, 7) == 0 || FUN_00ec8a19(pName4, DAT_0101e468, 9) == 0 ||
                            FUN_00ec8a19(pName4, DAT_0101e460, 5) == 0 || FUN_00ec8a19(pName4, DAT_0101e450, 15) == 0))
            return true;
        if (NiObject_IsKindOf(&DAT_011f4a20, ref->m28) && !ref->m28->GetAppCulled_00456610())
        {
            p9 = ref->m28;
            if (p9 != 0)
            {
                objVal = p9->FUN_0050d100()->GetObject3D();
                if (objVal != 0 && objVal->GetFlag(0x1a))
                    return true;
            }
            info2 = ((XMenuTopic*)ref->m28)->GetTopicInfo();
            hit2 = 0;
            foundVal = false;
            if (info2 != 0)
            {
                for (i5 = 0; i5 < info2->FUN_0043b480(); i5++)
                {
                    av_ = info2->GetAt(i5);
                    if (av_ != 0)
                    {
                        if (NiObject_IsExactKindOf(&DAT_011c7d34, av_))
                        {
                            foundVal = true;
                            hit2 = av_;
                            break;
                        }
                    }
                }
            }
            else
            {
                return false;
            }
            if (foundVal && ref->m5c > DAT_01012060)
            {
                list = hit2->m_ac;
                while (list != 0 && !list->IsEmpty())
                {
                    a5 = list->FUN_006815c0()->Modelloader_GetReferencedThis();
                    b_ = a5;
                    list = list->FUN_00726070();
                    float pt9[3];
                    b_->BSTempEffectSimpleDecal_GetOrigin(*reinterpret_cast<NiPoint3*>(pt9));
                    float f9 = b_->FUN_00507b20();
                    NiPoint3 v7 = ref->PtOp(*reinterpret_cast<NiPoint3*>(pt9));
                    v7 = MultiplyComponents(v7, v7);
                    float qA;
                    if (ref->m38 > ref->m3c)
                        qA = ref->m38;
                    else
                        qA = ref->m3c;
                    double d = qA + f9;
                    d = d * d;
                    if (v7.x + v7.y + v7.z <= d / ref->m5c)
                        return false;
                }
            }
            DAT_011c57e4++;
            if (((XSetting*)&DAT_011c5904x)->Bool()[0])
                Warning_005b5e40(DAT_0101e420, DAT_011c57e4);
            door3 = new XDoor((XObj*)hit2, ((XGA*)&DAT_011c5874)->FUN_00450410(), ref);
            p4 = ref->m28;
            if (p4->FUN_004a1ff0() > 0x3e8 && ((XSetting*)&DAT_011c58a8)->Bool()[0] && ref->m72)
            {
                door3->m1a = 1;
                door3->m1b = m4;
                m4 = 0;
            }
            if (ref->m48)
                m8.DecalManager_AppendList08(door3);
        }
        else if (ref->m28->v3())
        {
            XNode* n2 = ref->m28;
            unsigned int _i2;
            XNode* child8;
            if (n2 != 0 && n2->GetAppCulled_00456610())
                return true;
            _i2 = 0;
            while (_i2 < n2->FUN_0043b480())
            {
                child8 = n2->GetAt(_i2);
                if (child8 != 0)
                {
                    ref->m28 = child8;
                    BGSDecalManager_AddGeometryDecalRecurse(ref);
                }
                _i2++;
            }
        }
    }
    return true;
}

#include <string.h>
namespace fnv_004a2070 {
struct DObj;
struct DArg;
struct DPtr;
struct DProp;
struct DArray;
struct CStringProvider;
struct DVec
{
    float x, y, z;
    DVec GetNegatedVector() const;
};
struct DUpdate
{
    float time;
    bool updateControllers, multithreaded;
    unsigned unk08;
    DUpdate(float, bool, bool);
};
struct DObj
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual DObj* IsSceneNode();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual DObj* IsGeometry();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unka();
    virtual void Unkb();
    virtual void Unkc();
    virtual void Unkd();
    virtual void Unke();
    virtual void Unkf();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1a();
    virtual void Unk1b();
    virtual void Unk1c();
    virtual void Unk1d();
    virtual void Unk1e();
    virtual void Unk1f();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Virtual8c();
    virtual void Unk24();
    virtual void Unk25();
    virtual DObj* Virtual98(bool);
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk2a();
    virtual void Unk2b();
    virtual void Unk2c();
    virtual void Unk2d();
    virtual void Unk2e();
    virtual void Unk2f();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Virtualdc(DObj*, bool);
    CStringProvider* FUN_00413f40();
    bool GetAppCulled_00456610();
    DProp* FUN_00a59d30(unsigned);
    void* CombatController_GetTarget();
    void* NiGeometry_GetSkinInstance();
    DArray* NiAVObject_GetParent();
    unsigned NiNode_GetChildCount();
    int FUN_0059e300();
    void AssignGo(DObj*);
    void AssignFixedString(CStringProvider*);
    void NiAVObject_Update(DUpdate&);
};
struct CStringProvider
{
    const char* FUN_0043b1b0();
};
struct DPtr
{
    DObj* ptr;
    DPtr(DObj*);
    ~DPtr();
    DObj* Modelloader_GetReferencedThis();
    DPtr& FUN_0066b0d0(DObj*);
};
struct DArray
{
    unsigned FUN_0043b480();
    DObj* FUN_0043b4a0(unsigned);
};
struct DProp
{
};
// Exe 0x004a2070: unit-local DList view; declarations and layout are preserved.
struct BgsdecalmanagerDListView
{
    void BSSimpleList_NiPointer_bhkAction_AddHead(const DPtr&);
};
struct DNode : DObj
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    BgsdecalmanagerDListView* effects;
    unsigned unkb0;
    static void* operator new(unsigned);
    static void operator delete(void*, unsigned int);
    DNode(DArray*, bool);
};
struct DOneArg
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual void Unk7();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Unk37();
    virtual void Unk38();
    virtual void Unk39();
    virtual void Unk40();
    virtual void Unk41();
    virtual void Unk42();
    virtual void Unk43();
    virtual void Unk44();
    virtual void Unk45();
    virtual void Unk46();
    virtual void Unk47();
    virtual void Unk48();
    virtual void Unk49();
    virtual void Unk50();
    virtual void Unk51();
    virtual void Unk52();
    virtual void Unk53();
    virtual void Unk54();
    virtual void Virtualdc(DObj*);
    void AssignFixedString(CStringProvider*);
};
struct DSkin : DOneArg
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    static void* operator new(unsigned);
    static void operator delete(void*, unsigned int);
    DSkin(unsigned);
};
struct DEffect : DObj
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    static void* operator new(unsigned);
    static void operator delete(void*, unsigned int);
    DEffect(unsigned, float, DArg*, DObj*, DVec, DVec, float, float, unsigned);
};
struct DParentInterface
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual void Unk7();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unka();
    virtual void Unkb();
    virtual void Unkc();
    virtual void Unkd();
    virtual void Unke();
    virtual void Unkf();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1a();
    virtual void Unk1b();
    virtual void Unk1c();
    virtual void Unk1d();
    virtual void Unk1e();
    virtual void Unk1f();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Get(unsigned, DPtr&);
};
struct DParent
{
    unsigned unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    DParentInterface interface30;
};
struct DArg
{
    DVec origin, normal;
    unsigned unk18, unk1c, unk20, unk24;
    DObj* object;
    DArray* children;
    DParent* parent;
    int tries;
    float scale;
    unsigned unk3c, unk40;
    float rotation;
    unsigned flags, unk4c;
    DOneArg* skin;
    unsigned unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
};
struct DSetting
{
    float* Setting_Float_00403e20();
    int* Setting_Int();
    bool* FUN_00408d60();
    float FUN_00450410();
};
extern DSetting DAT_011c5874, DAT_011c5858, DAT_011c589c;
extern int DAT_011c57e8, DAT_011c57f0;
extern unsigned DAT_011f444c, DAT_011c7d34;
struct DManager
{
    void ProcessLists_AddTempEffect(DObj*);
};
extern DManager DAT_011e0e80;
bool NiObject_IsKindOf(const void*, DObj*);
bool NiObject_IsExactKindOf(const void*, DObj*);
void Warning_005b5e40(const char*, ...);
CStringProvider* FixedStrings_QSkinnedDecalNode();
int BSSM_ShaderPropertyIsLighting(DProp*);
struct DWork
{
    bool BGSDecalManager_AddProjectedDecalRecurse(DArg*);
};
// Checks limits and object conditions, may create decal effects, and returns a status.
// @fnv 0x004a2070
// src: XBOX_PDB 0x004a2070
bool DWork::BGSDecalManager_AddProjectedDecalRecurse(DArg* arg)
{
    if (*DAT_011c5874.Setting_Float_00403e20() <= 0.0)
        return false;
    if (DAT_011c57e8 >= *DAT_011c5858.Setting_Int())
    {
        if (*DAT_011c5904.FUN_00408d60())
            Warning_005b5e40("DECAL: Reached max skinned decals per frame. Ignoring decal.");
        return true;
    }
    DPtr original(0);
    if (arg->parent)
    {
        DPtr p(0);
        arg->parent->interface30.Get(0, p);
        DObj* parent = p.Modelloader_GetReferencedThis();
        if (NiObject_IsKindOf(&DAT_011f444c, parent))
            original.FUN_0066b0d0(parent);
    }
    if (!original.Modelloader_GetReferencedThis())
        return false;
    if (arg->object)
    {
        const char* name = arg->object->FUN_00413f40()->FUN_0043b1b0();
        if (name)
        {
            if (!strncmp(name, "Decal", 5) || !strncmp(name, "FaceGen", 7) || !strncmp(name, "Bip01", 5) ||
                !strncmp(name, "BSFaceGen", 9) || !strncmp(name, "Hair", 4))
                return true;
        }
        if (arg->object->GetAppCulled_00456610())
            return true;
        if (arg->object->IsGeometry())
        {
            DObj* geometry = arg->object;
            if (arg->tries <= 0)
            {
                DProp* data = geometry->FUN_00a59d30(3);
                void* prop = geometry->CombatController_GetTarget();
                if (data && prop)
                {
                    DPtr effect(0);
                    if (geometry->NiGeometry_GetSkinInstance())
                    {
                        DArray* array = arg->object->NiAVObject_GetParent();
                        DNode* selected = 0;
                        for (unsigned i = 0; i < array->FUN_0043b480(); ++i)
                        {
                            DObj* child = array->FUN_0043b4a0(i);
                            if (child && NiObject_IsExactKindOf(&DAT_011c7d34, child))
                            {
                                selected = (DNode*)child;
                                break;
                            }
                        }
                        if (!selected)
                            selected = new DNode(array, true);
                        else
                        {
                            if (selected->NiNode_GetChildCount() >= (unsigned)*DAT_011c589c.Setting_Int())
                                return true;
                        }
                        ++DAT_011c57e8;
                        if (*DAT_011c5904.FUN_00408d60())
                            Warning_005b5e40("DECAL: Skinned decal count this frame: #%d", DAT_011c57e8);
                        DPtr decal(new DEffect(arg->flags, DAT_011c5874.FUN_00450410(), arg, geometry, arg->origin,
                                               arg->normal, arg->scale, arg->rotation, arg->unk6c));
                        bool accepted = false;
                        decal.Modelloader_GetReferencedThis()->Virtual8c();
                        if (decal.Modelloader_GetReferencedThis()->FUN_0059e300() > 0)
                        {
                            if (!arg->skin)
                            {
                                arg->skin = new DSkin(0);
                                arg->skin->AssignFixedString(FixedStrings_QSkinnedDecalNode());
                                selected->Virtualdc((DObj*)arg->skin, true);
                                ++DAT_011c57f0;
                                if (*DAT_011c5904.FUN_00408d60())
                                    Warning_005b5e40("DECAL: Placing Skin Decal #%d", DAT_011c57f0);
                            }
                            arg->skin->Virtualdc(decal.Modelloader_GetReferencedThis()->Virtual98(true));
                            decal.Modelloader_GetReferencedThis()->AssignGo((DObj*)arg->skin);
                            selected->effects->BSSimpleList_NiPointer_bhkAction_AddHead(decal.Modelloader_GetReferencedThis());
                            DUpdate update(0.0f, false, false);
                            selected->NiAVObject_Update(update);
                            DAT_011e0e80.ProcessLists_AddTempEffect(decal.Modelloader_GetReferencedThis());
                            effect.FUN_0066b0d0(decal.Modelloader_GetReferencedThis());
                        }
                        else
                            return true;
                    }
                    if (arg->children)
                    {
                        DObj* a = 0;
                        unsigned found = 0;
                        while (found < arg->children->FUN_0043b480() && !a)
                        {
                            DObj* child = arg->children->FUN_0043b4a0(found);
                            if (child)
                            {
                                if (child->IsGeometry())
                                    a = child;
                                else if (child->IsSceneNode())
                                {
                                    DArray* uiIndex = (DArray*)child;
                                    unsigned pArray = 0;
                                    while (pArray < uiIndex->FUN_0043b480() && !a)
                                    {
                                        DObj* candidate = uiIndex->FUN_0043b4a0(pArray);
                                        if (candidate && candidate->IsGeometry())
                                            a = candidate;
                                        ++pArray;
                                    }
                                }
                            }
                            ++found;
                        }
                        if (a)
                        {
                            DProp* data2 = a->FUN_00a59d30(3);
                            void* prop2 = a->CombatController_GetTarget();
                            if (data2 && prop2)
                            {
                                DProp* shader = BSSM_ShaderPropertyIsLighting(data2) ? data2 : 0;
                                if (shader)
                                {
                                    DPtr additional(0);
                                    if (geometry->NiGeometry_GetSkinInstance())
                                    {
                                        DEffect* pRawEffect =
                                            new DEffect(arg->flags, DAT_011c5874.FUN_00450410(), arg, a, arg->origin,
                                                        arg->normal.GetNegatedVector(), 1.0f, arg->rotation, arg->unk6c);
                                        additional.FUN_0066b0d0(pRawEffect);
                                        pRawEffect->Virtual8c();
                                    }
                                    if (additional.Modelloader_GetReferencedThis())
                                        DAT_011e0e80.ProcessLists_AddTempEffect(additional.Modelloader_GetReferencedThis());
                                }
                            }
                        }
                    }
                }
                if (arg->tries >= 0)
                    return false;
                else
                    return true;
            }
            else
            {
                --arg->tries;
                return true;
            }
        }
        else if (arg->object->IsSceneNode())
        {
            DArray* pArray = (DArray*)arg->object;
            unsigned uiIndex = 0;
            while (uiIndex < pArray->FUN_0043b480())
            {
                DObj* child = pArray->FUN_0043b4a0(uiIndex);
                if (child)
                {
                    arg->object = child;
                    bool result = BGSDecalManager_AddProjectedDecalRecurse(arg);
                    if (!result && arg->object)
                    {
                        if (arg->skin)
                        {
                            DArray* array = arg->object->NiAVObject_GetParent();
                            DNode* selected = 0;
                            for (unsigned d = 0; d < array->FUN_0043b480(); ++d)
                            {
                                DObj* entry = array->FUN_0043b4a0(d);
                                if (entry && NiObject_IsExactKindOf(&DAT_011c7d34, entry))
                                {
                                    selected = (DNode*)entry;
                                    break;
                                }
                            }
                            if (selected)
                                selected->Virtualdc((DObj*)arg->skin, true);
                        }
                        return false;
                    }
                }
                ++uiIndex;
            }
        }
    }
    return true;
}
}  // namespace fnv_004a2070
