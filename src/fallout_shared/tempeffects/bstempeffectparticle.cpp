#include <string.h>
#pragma intrinsic(memcpy)
#include "../../../include/BSFadeNode.h"
#include "../../../include/BSTempEffect.h"
#include "../../../include/BSTempEffectParticle.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiControllerManager.h"
#include "../../../include/NiControllerSequence.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiTransform.h"
#include "../../../include/Transform.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/GO.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/NiRTTI.h"
#include "../../../include/NiUpdateData.h"

// src/fallout_shared/tempeffects/bstempeffectparticle.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tempeffects/bstempeffectparticle.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x0068a850
void BSTempEffectParticle::StopSounds()
{
    if (m_5c.IsValid())
    {
        m_5c.Stop();
        if (m_5c.IsValid())
            m_5c.Release();
    }
    if (m_68.IsValid())
    {
        m_68.Stop();
        if (m_68.IsValid())
            m_68.Release();
    }
}

extern int* DAT_011c61ec;

// @fnv 0x00891350
// src: XBOX_PDB 0x00891350
int* __cdecl FixedStrings_QWeapon()
{
    return DAT_011c61ec;
}

struct GlobalObject_00a7b610 : public NiRTTI
{
};
extern GlobalObject_00a7b610 g_011d6b84;

// @fnv 0x00688f80
const NiRTTI* __thiscall BSTempEffectParticle::GetRTTI() const
{
    return &g_011d6b84;
}

// Returns true when pFilename is non-null and m_flt converts to a non-zero unsigned int, otherwise false.
// @fnv 0x00689af0
// src: COMMUNITY 0x00689af0
bool BSTempEffectParticle::CheckShouldSave()
{
    if (!(pFilename && (unsigned int)m_flt))
        return false;
    return true;
}

void __cdecl TESObjectREFR_RemoveMasterParticleAddonNodes(NiNode*);
// Gets the node from m_flt via f3 and, if non-null, passes it to FUN_00578170.
// @fnv 0x006896c0
// src: COMMUNITY 0x006896c0
void BSTempEffectParticle::Detach_006896c0()
{
    NiNode* pnode = m_flt ? ((NiNode*)(unsigned int)m_flt)->IsSceneNode() : 0;
    if (pnode)
        TESObjectREFR_RemoveMasterParticleAddonNodes(pnode);
}

// @fnv 0x0068a8d0
// src: COMMUNITY 0x0068a8d0
void __thiscall BSTempEffectParticle::PlayImpactDataSounds(void* pValue)
{
    m_58 = pValue;
    InitLoopSounds();
}

struct Model
{
    NiNode* GetObject3D();
};

extern NiRTTI DAT_011f36ac;

NiControllerManager* _UseSaveGameBlocks(const NiRTTI*, NiNode*);

// @fnv 0x00689920
// src: XBOX_PDB 0x00689920
void BSTempEffectParticle::PlaySequence(const char* name)
{
    NiControllerManager* controllerManager =
        _UseSaveGameBlocks(&DAT_011f36ac, reinterpret_cast<Model*>(m_flt.operator unsigned int())->GetObject3D());

    if (controllerManager)
    {
        NiControllerSequence* controllerSequence = controllerManager->FindSequenceByName(NiFixedString(name));

        if (controllerSequence)
        {
            controllerManager->ActivateControllerSequence(controllerSequence, 0, false, 1.0f, 0.0f, (NiControllerSequence*)0);

            float duration = controllerSequence->GetEndKeyTime_00508100();
            if (duration > m_fParticleParameter5)
            {
                m_fParticleParameter5 = duration;
            }
        }
    }
}

struct Tgt;
struct Yv
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
    virtual void v3a(Tgt*);
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
};
struct Tgt;
struct Sub18
{
    Tgt* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(int);
};
struct Mgr
{
    void ModelLoader_ReleaseModel(Tgt*, int, int);
};
extern Mgr* DAT_011c3b3c;
struct Fn
{
    Yv* NiAVObject_GetParent();
};
// @fnv 0x00689720
BSTempEffectParticle::~BSTempEffectParticle()
{
    StopSounds();
    if ((Tgt*)pFilename)
        DAT_011c3b3c->ModelLoader_ReleaseModel((Tgt*)pFilename, 0, 1);
    if (reinterpret_cast<Sub18*>(&m_flt)->Modelloader_GetReferencedThis())
    {
        if (((Fn*)reinterpret_cast<Sub18*>(&m_flt)->Modelloader_GetReferencedThis())->NiAVObject_GetParent())
        {
            ((Fn*)reinterpret_cast<Sub18*>(&m_flt)->Modelloader_GetReferencedThis())->NiAVObject_GetParent()->v3a(reinterpret_cast<Sub18*>(&m_flt)->Modelloader_GetReferencedThis());
        }
    }
    reinterpret_cast<Sub18*>(&m_flt)->FUN_0066b0d0(0);
}

extern const float DAT_01012054;
float __cdecl BSMAX_00404010(float lhs, float rhs);

struct TrailEntry
{
    double FUN_004a7bd0();
    double FUN_0047c860();
    TrailEntry* NiTimeController_GetNext();
};

struct TraversalItem
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual TraversalItem* v3();
    TrailEntry* NiObjectNET_GetControllers();
    int NiNode_GetChildCount();
    TraversalItem* FUN_0043b4a0(int index);
};

// @fnv 0x00689840
float BSTempEffectParticle::ComputeTraversalValue(TraversalItem* entry)
{
    float accumulator = DAT_01012054;
    TrailEntry* pTrail = entry->NiObjectNET_GetControllers();
    while (pTrail != 0)
    {
        accumulator = BSMAX_00404010(accumulator, static_cast<float>(pTrail->FUN_004a7bd0() - pTrail->FUN_0047c860()));
        pTrail = pTrail->NiTimeController_GetNext();
    }

    TraversalItem* children = entry->v3();
    if (children != 0)
    {
        int iChildCount = children->NiNode_GetChildCount();
        for (int i = 0; i < iChildCount; ++i)
        {
            TraversalItem* child = children->FUN_0043b4a0(i);
            if (child != 0)
                accumulator = BSMAX_00404010(accumulator, ComputeTraversalValue(child));
        }
    }
    return accumulator;
}

struct DataModel
{
    void* __thiscall NiObjectNET_GetControllers();
};
struct DataHandle
{
    DataModel* __thiscall Modelloader_GetReferencedThis();
};
struct GlobalState
{
    bool __thiscall TESSaveLoadGame_UseSaveGameBlocks();
    void* __thiscall FUN_004fd3e0();
};
struct LoggingFlag
{
    unsigned char* __thiscall FUN_00408d60();
};
struct LoggingObject
{
    void** vtable;
};
extern GlobalState* DAT_011de45c;
extern LoggingFlag DAT_011de4e8;
extern char DAT_01012c78[];
extern char DAT_01012cb0[];
extern char DAT_01069d20[];
extern "C" int __cdecl BSstrlen(char const*);
extern "C" void* __cdecl NiObject_DynamicCast(void*, void*);
extern "C" unsigned short __cdecl TESObjectREFR_GetControllerManagerSaveSize(void*);
extern "C" LoggingObject* __cdecl TESForm_GetFormByNumericID(void*);
extern "C" void __cdecl ProgramFlow(char const*, ...);
typedef void*(__thiscall* LogMethod)(LoggingObject*);
// @fnv 0x00689b20
unsigned short BSTempEffectParticle::GetSaveSize()
{
    unsigned short previous = 0;
    unsigned short total = previous;
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        previous += 4;
        previous += 2;
    }
    previous += BSTempEffect::GetSaveSize();
    previous += 1;
    previous += BSstrlen(pFilename);
    previous += 0x10;
    previous += 0xc;
    previous += 4;
    previous += 2;
    void* active = NiObject_DynamicCast(&DAT_011f36ac, reinterpret_cast<DataHandle*>(&m_flt)->Modelloader_GetReferencedThis()->NiObjectNET_GetControllers());
    if (active != 0)
    {
        previous += TESObjectREFR_GetControllerManagerSaveSize(active);
    }
    if (*DAT_011de4e8.FUN_00408d60())
    {
        void* entry = DAT_011de45c->FUN_004fd3e0();
        if (entry)
        {
            LoggingObject* writer = TESForm_GetFormByNumericID(*(void**)entry);
            ProgramFlow(DAT_01012cb0, previous - total, *(void**)entry, ((LogMethod*)writer->vtable)[76](writer),
                         *(void**)((char*)entry + 5), 0x174, DAT_01069d20);
        }
        else
        {
            ProgramFlow(DAT_01012c78, previous - total, 0x174, DAT_01069d20);
        }
    }
    return previous;
}

struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void FUN_004a0c90(float);
    void FUN_0043f8d0(Matrix&, const Matrix&);
};
struct ParticleRotationMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    ParticleRotationMatrix();
    void FUN_004a0c90(float);
};
float __cdecl RandomFloatTwoPi();
struct Rotation
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Rotation();
    void FUN_0043f8d0(Matrix&, const ParticleRotationMatrix&);
};
Rotation __cdecl BSUtilities_GetRotationZToVectorTranspose(NiPoint3);
struct World
{
    void* FUN_00456fc0(int);
};
struct Manager
{
    void ProcessLists_AddTempEffect(BSTempEffectParticle*);
};
extern Manager DAT_011e0e80;
// @fnv 0x006890b0
// src: XBOX_PDB 0x006890b0
BSTempEffectParticle* __cdecl BSTempEffectParticle_Spawn(World* world, float duration, int kind, NiPoint3 rotation, NiPoint3 position, float scale,
                                       int flags, int extra)
{
    BSTempEffectParticle* pEffect = 0;
    if (world)
    {
        pEffect = new BSTempEffectParticle(reinterpret_cast<TESObjectCELL*>(world), duration,
                                           reinterpret_cast<const char*>(kind), reinterpret_cast<void*>(extra));
        float node = RandomFloatTwoPi();
        ParticleRotationMatrix matrix2;
        matrix2.FUN_004a0c90(node);
        Matrix a;
        BSUtilities_GetRotationZToVectorTranspose(rotation).FUN_0043f8d0(a, matrix2);
        void* transform = world->FUN_00456fc0(4);
        pEffect->AttachModel(transform, a, position, scale, flags);
        DAT_011e0e80.ProcessLists_AddTempEffect(pEffect);
    }
    return pEffect;
}

struct Block9
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    unsigned int i;
};
struct Block3
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};
struct FUN_00456fc0_cls
{
    void* FUN_00456fc0(unsigned int a);
};
struct GlobalObject_0096d020
{
    void ProcessLists_AddTempEffect(void* a);
};
extern GlobalObject_0096d020 g_011e0e80;

// @fnv 0x00689210
// src: XBOX_PDB 0x00689210
void* __cdecl BSTempEffectParticle_Spawn_00689210(void* a, float fValue, unsigned int uiFlags, Block9 d, Block3 e, float fParam,
                           unsigned int uiParam, unsigned int uiExtra)
{
    BSTempEffectParticle* pNewObject = 0;
    if (a != 0)
    {
        pNewObject = new BSTempEffectParticle(reinterpret_cast<TESObjectCELL*>(a), fValue,
                                              reinterpret_cast<const char*>(uiFlags), reinterpret_cast<void*>(uiExtra));
        void* pArgument = ((FUN_00456fc0_cls*)a)->FUN_00456fc0(4);
        pNewObject->AttachModel(pArgument, d, e, fParam, uiParam);
        g_011e0e80.ProcessLists_AddTempEffect(pNewObject);
    }
    return pNewObject;
}

struct CloneData
{
    int a, b, c, d, e, f, g;
    CloneData(float);
    ~CloneData();
};
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Obj* asNode();
    unsigned int Kind();
    Obj* Clone(CloneData*);
    void SetPosition(const NiPoint3&);
    void SetRotation(const NiMatrix3*);
    void SetScale(float);
    void Update();
    NiTransform& World();
};
struct Parent
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
    virtual void Attach(Obj*, bool);
};
struct Ptr
{
    Obj* p;
    Ptr(Obj*);
    ~Ptr();
    operator Obj*() const;
    Ptr& operator=(Obj*);
    Ptr& operator=(const Ptr&);
};
struct Loader
{
    Obj* LoadFile(const char*, int, bool, bool, bool, bool);
};
struct WorldMgr
{
    int TryLoad(Obj*, Ptr*);
};
extern WorldMgr* g_TES;
struct Queue
{
    static Queue* GetInstance();
    void Attach(Obj*, Parent*, bool, bool);
};
bool AILinearTaskThreadManager_ShouldQueue3DTask();
void TESObjectREFR_AddMasterParticleAddonNodes(Obj*);
void Post(Obj*);
// Loads the model file, resolves or clones it, applies position/rotation/scale, attaches it to dest or the queue, then computes the relative transform to parent.
// @fnv 0x00689310
void BSTempEffectParticle::AttachModel(Parent* apParent, NiMatrix3 rotation, NiPoint3 position, float afScale, unsigned int flags)
{
    Ptr loaded6(((Loader*)DAT_011c3b3c)->LoadFile(pFilename, 0, true, false, false, true));
    if (!(Obj*)loaded6)
        return;
    reinterpret_cast<Ptr&>(m_flt) = (Obj*)0;
    int success = 0;
    if ((flags & 1) && g_TES)
        success = g_TES->TryLoad(loaded6, &reinterpret_cast<Ptr&>(m_flt));
    if (!success)
    {
        if (((Obj*)loaded6)->Kind() <= 2)
            reinterpret_cast<Ptr&>(m_flt) = loaded6;
        else if (flags & 2)
        {
            CloneData clone2(1.0f);
            reinterpret_cast<Ptr&>(m_flt) = ((Obj*)loaded6)->Clone(&clone2);
        }
    }
    if (!(Obj*)reinterpret_cast<Ptr&>(m_flt))
        return;
    if (flags & 4)
    {
        float value5 = Calc(reinterpret_cast<Ptr&>(m_flt));
        if (value5 != -1.0)
        {
            if (value5 < 0.1f)
                value5 = 0.1f;
            m_fParticleParameter5 = value5;
        }
    }
    Obj* node_ = ((Obj*)reinterpret_cast<Ptr&>(m_flt))->asNode();
    if (node_)
        TESObjectREFR_AddMasterParticleAddonNodes(node_);
    ((Obj*)reinterpret_cast<Ptr&>(m_flt))->SetPosition(position);
    ((Obj*)reinterpret_cast<Ptr&>(m_flt))->SetRotation(&rotation);
    ((Obj*)reinterpret_cast<Ptr&>(m_flt))->SetScale(afScale);
    if (AILinearTaskThreadManager_ShouldQueue3DTask())
        Queue::GetInstance()->Attach(reinterpret_cast<Ptr&>(m_flt), apParent, true, true);
    else
    {
        apParent->Attach(reinterpret_cast<Ptr&>(m_flt), true);
        ((Obj*)reinterpret_cast<Ptr&>(m_flt))->Update();
    }
    Setup(reinterpret_cast<Ptr&>(m_flt));
    Post(reinterpret_cast<Ptr&>(m_flt));
    if ((Obj*)reinterpret_cast<Ptr&>(m_20))
    {
        NiTransform local;
        local.m_fScale = afScale;
        local.m_Rotate = rotation;
        *reinterpret_cast<Transform::PlainVec*>(&local.m_Translate) =
            reinterpret_cast<const Transform::PlainVec&>(position);
        // Preserve the original storage copies without invoking the shared matrix copy constructor.
        unsigned int world3[sizeof(NiTransform) / sizeof(unsigned int)];
        memcpy(world3, &((Obj*)reinterpret_cast<Ptr&>(m_20))->World(), sizeof(world3));
        NiTransform inverseTmp;
        reinterpret_cast<NiTransform*>(world3)->Invert(&inverseTmp);
        memcpy(&m_kMotionTransform, &(inverseTmp * local), sizeof(m_kMotionTransform));
    }
}

extern NiRTTI DAT_012024e0;
extern NiRTTI DAT_01202548;
struct NodeX
{
    unsigned int FUN_0043b480();
    NiNode* FUN_0043b4a0(int);
};
struct ArrP
{
    unsigned int NiParticleSystem_GetModifierCount();
    void* GetByIndex(int);
};
struct ObjQ
{
    int NiAVObject_GetParent();
};
struct ArrQ
{
    int* FUN_00877a30(int);
    void FUN_0096ae90(unsigned int, const int&);
};

// @fnv 0x0068a8f0
void __thiscall BSTempEffectParticle::CollectUniqueChildValues(NiNode* apNode, ArrQ* apValues, int* apiCount)
{
    if (apNode)
    {
        ArrP* p = (ArrP*)NiObject_DynamicCast(&DAT_012024e0, apNode);
        if (p)
        {
            unsigned int i;
            for (i = 0; i < p->NiParticleSystem_GetModifierCount(); ++i)
            {
                ObjQ* pObj = (ObjQ*)NiObject_DynamicCast(&DAT_01202548, p->GetByIndex(i));
                if (pObj)
                {
                    bool bUnique = true;
                    int iExisting;
                    for (iExisting = *apiCount - 1; bUnique && iExisting >= 0; --iExisting)
                    {
                        if (*apValues->FUN_00877a30(iExisting) == pObj->NiAVObject_GetParent())
                            bUnique = false;
                    }
                    if (bUnique)
                    {
                        apValues->FUN_0096ae90(*apiCount, pObj->NiAVObject_GetParent());
                        ++*apiCount;
                    }
                }
            }
        }
        NiNode* pChild = apNode->IsSceneNode();
        if (pChild)
        {
            unsigned int uiChildIndex;
            for (uiChildIndex = 0; uiChildIndex < ((NodeX*)pChild)->FUN_0043b480(); ++uiChildIndex)
            {
                CollectUniqueChildValues(((NodeX*)pChild)->FUN_0043b4a0(uiChildIndex), apValues, apiCount);
            }
        }
    }
}

struct R01Diagnostic
{
    int m_formID;
    unsigned char m_type;
    unsigned char m_payload0, m_payload1, m_payload2, m_payload3;
    unsigned char m_grade;
};

struct R01SaveReader
{
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_LoadGameDataOLD(void*, unsigned int);
    unsigned int FUN_00825c00();
    R01Diagnostic* BGSProjectile_GetExplosion();
    unsigned char FUN_008df040();
    void FUN_00857bd0(unsigned short);
};

struct R01Matrix3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    void Init();
};

struct R01Point3
{
    float x, y, z;
    void Init();
};

struct R01ParticleTransform
{
    float x, y, z, w;
    void Init();
    void NiQuaternion_ToRotation(R01Matrix3*);
};

struct R01Node
{
    R01Node* Modelloader_GetReferencedThis();
    void NiAVObject_SetTranslate(R01Point3*);
    void SetRotate_0043fa80(R01Matrix3*);
    void NiAVObject_SetScale(float);
    void UpdateProperties();
    void* NiObjectNET_GetControllers();
    void NiAVObject_Update(NiUpdateData*);
};

struct R01NodeRef
{
    void FUN_0066b0d0(R01Node*);
    R01Node* Modelloader_GetReferencedThis();
};

struct R01SceneRoot
{
    R01Node* FUN_00a5d680();
};

struct R01SceneLink
{
    void* m_ptr;
    R01SceneLink(int);
    ~R01SceneLink();
    R01Node* Modelloader_GetReferencedThis();
};

struct R01Scene
{
    R01SceneRoot* ModelLoader_LoadFile(char*, int, int, int, int, int);
    void ModelLoader_FindModel(char*, R01SceneLink*);
};

struct R01CellDynamicNode
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
    virtual unsigned int AttachChildInAvailableSlot(R01Node*, int);
};

struct R01Cell
{
    R01CellDynamicNode* FUN_005497a0();
};

struct R01Form
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
    virtual const char* GetDebugName();
};

struct R01Rand
{
    unsigned int FUN_00825c00(int, int);
};

extern R01Rand DAT_011f6394;
extern const double DAT_01017b70;
extern const float DAT_01012054;
extern void __cdecl Warning_005b5e40(const char*, ...);
extern R01Form* __cdecl TESForm_GetFormByNumericID(int);
extern void __cdecl TESObjectREFR_LoadControllerManager(void*, R01Node*, float);
extern void __cdecl NiTimeController_StartAnimations(R01Node*);
extern void* __cdecl memset(void*, int, unsigned int);

// Reads a particle temp effect from the save buffer, rebuilds its scene node and transform, and reports block header or buffer size errors.
// @fnv 0x00689f80
bool BSTempEffectParticle::LoadFromSave()
{
    bool aA4 = true;
    unsigned char aAF8;
    R01Matrix3 aAccuracy5;
    float aAction2;
    unsigned short a3_2;
    R01ParticleTransform a1c4_2;
    R01Point3 aAPGeom;
    {
        unsigned short aA2 = 0;
        unsigned int a1c2 = 0;
        if (reinterpret_cast<R01SaveReader*>(DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned int aA1c4;
            reinterpret_cast<R01SaveReader*>(DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&aA1c4, 4);
            if (aA1c4 != 0x424c4f4b)
            {
                R01Diagnostic* diag = reinterpret_cast<R01SaveReader*>(DAT_011de45c)->BGSProjectile_GetExplosion();
                if (diag)
                {
                    R01Form* form = TESForm_GetFormByNumericID(diag->m_formID);
                    Warning_005b5e40(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp",
                        0x1a4, diag->m_formID, form->GetDebugName(), diag->m_grade,
                        *reinterpret_cast<unsigned int*>(&diag->m_payload0));
                }
                else
                {
                    Warning_005b5e40(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp",
                        0x1a4, reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008df040());
                }
            }
            a1c2 = reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_00825c00();
            reinterpret_cast<R01SaveReader*>(DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&aA2, 2);
        }
        aA4 = BSTempEffect::LoadGame();
        reinterpret_cast<R01SaveReader*>(DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&aAF8, 1);
        char aActive8[0x104];
        memset(aActive8, 0, sizeof(aActive8));
        reinterpret_cast<R01SaveReader*>(DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(aActive8, aAF8);
        a1c4_2.Init();
        reinterpret_cast<R01SaveReader*>(DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&a1c4_2, 0x10);
        aAccuracy5.Init();
        a1c4_2.NiQuaternion_ToRotation(&aAccuracy5);
        aAPGeom.Init();
        reinterpret_cast<R01SaveReader*>(DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&aAPGeom, 0xc);
        reinterpret_cast<R01SaveReader*>(DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&aAction2, 4);
        reinterpret_cast<R01SaveReader*>(DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&a3_2, 2);
        if (aA4)
        {
            R01SceneRoot* a4_2 = reinterpret_cast<R01Scene*>(DAT_011c3b3c)->ModelLoader_LoadFile(aActive8, 0, 1, 0, 0, 0);
            if (a4_2)
            {
                reinterpret_cast<R01NodeRef*>(&m_flt)->FUN_0066b0d0(a4_2->FUN_00a5d680());
                if (reinterpret_cast<R01NodeRef*>(&m_flt)->Modelloader_GetReferencedThis())
                {
                    R01SceneLink aActorPos6(0);
                    reinterpret_cast<R01Scene*>(DAT_011c3b3c)->ModelLoader_FindModel(aActive8, &aActorPos6);
                    pFilename = reinterpret_cast<const char*>(aActorPos6.Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis());
                    reinterpret_cast<R01NodeRef*>(&m_flt)->Modelloader_GetReferencedThis()->NiAVObject_SetTranslate(&aAPGeom);
                    reinterpret_cast<R01NodeRef*>(&m_flt)->Modelloader_GetReferencedThis()->SetRotate_0043fa80(&aAccuracy5);
                    reinterpret_cast<R01NodeRef*>(&m_flt)->Modelloader_GetReferencedThis()->NiAVObject_SetScale(aAction2);
                    R01CellDynamicNode* aAFlags = reinterpret_cast<R01Cell*>(pCell)->FUN_005497a0();
                    aAFlags->AttachChildInAvailableSlot(reinterpret_cast<R01NodeRef*>(&m_flt)->Modelloader_GetReferencedThis(), 1);
                    reinterpret_cast<R01NodeRef*>(&m_flt)->Modelloader_GetReferencedThis()->UpdateProperties();
                    NiUpdateData aA148((float)((double)DAT_011f6394.FUN_00825c00(1, 0) / DAT_01017b70));
                    reinterpret_cast<R01NodeRef*>(&m_flt)->Modelloader_GetReferencedThis()->NiAVObject_Update(&aA148);
                    NiTimeController_StartAnimations(reinterpret_cast<R01NodeRef*>(&m_flt)->Modelloader_GetReferencedThis());
                    if (a3_2)
                    {
                        void* a1c4 = NiObject_DynamicCast(&DAT_011f36ac, reinterpret_cast<R01NodeRef*>(&m_flt)->Modelloader_GetReferencedThis()->NiObjectNET_GetControllers());
                        if (a1c4)
                        {
                            TESObjectREFR_LoadControllerManager(a1c4, reinterpret_cast<R01NodeRef*>(&m_flt)->Modelloader_GetReferencedThis(), DAT_01012054);
                        }
                        else
                        {
                            aA4 = false;
                        }
                    }
                }
                else
                {
                    aA4 = false;
                }
            }
            else
            {
                aA4 = false;
            }
        }
        if (!aA4 && a3_2)
        {
            reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_00857bd0(a3_2);
        }
        if (reinterpret_cast<R01SaveReader*>(DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned int a1cTmp = reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_00825c00();
            R01Diagnostic* diag = reinterpret_cast<R01SaveReader*>(DAT_011de45c)->BGSProjectile_GetExplosion();
            if (diag)
            {
                R01Form* form = TESForm_GetFormByNumericID(diag->m_formID);
                if (a1cTmp > a1c2 + (unsigned int)aA2)
                {
                    Warning_005b5e40(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        a1cTmp - (a1c2 + (unsigned int)aA2),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp",
                        0x1ec, diag->m_formID, form->GetDebugName(), diag->m_grade,
                        *reinterpret_cast<unsigned int*>(&diag->m_payload0));
                }
                else if (a1cTmp < a1c2 + (unsigned int)aA2)
                {
                    Warning_005b5e40(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        (a1c2 + (unsigned int)aA2) - a1cTmp,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp",
                        0x1ec, diag->m_formID, form->GetDebugName(), diag->m_grade,
                        *reinterpret_cast<unsigned int*>(&diag->m_payload0));
                }
            }
            else
            {
                if (a1cTmp > a1c2 + (unsigned int)aA2)
                {
                    Warning_005b5e40(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                        a1cTmp - (a1c2 + (unsigned int)aA2),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp",
                        0x1ec, reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008df040());
                }
                else if (a1cTmp < a1c2 + (unsigned int)aA2)
                {
                    Warning_005b5e40(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                        (a1c2 + (unsigned int)aA2) - a1cTmp,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp",
                        0x1ec, reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008df040());
                }
            }
        }
    }
    return aA4;
}

// Calls FUN_006828a0, clears parent when its refcount is 1, and applies the parent's transform multiplied by localTransform to object.
// @fnv 0x00689a10
bool BSTempEffectParticle::UpdateTransform(float time)
{
    bool result = BSTempEffect::Update(time);
    if (reinterpret_cast<NiPointer<NiAVObject>&>(m_20) && reinterpret_cast<NiPointer<NiAVObject>&>(m_20)->GetRefCount() == 1)
        reinterpret_cast<NiPointer<NiAVObject>&>(m_20) = 0;
    if (reinterpret_cast<NiPointer<NiAVObject>&>(m_flt) && reinterpret_cast<NiPointer<NiAVObject>&>(m_20))
    {
        NiTransform transform = reinterpret_cast<NiPointer<NiAVObject>&>(m_20)->NiAVObject_GetWorldRotate() * m_kMotionTransform;
        reinterpret_cast<NiPointer<NiAVObject>&>(m_flt)->NiAVObject_SetTranslate(transform.m_Translate);
        reinterpret_cast<NiPointer<NiAVObject>&>(m_flt)->SetRotate_0043fa80(transform.m_Rotate);
        reinterpret_cast<NiPointer<NiAVObject>&>(m_flt)->NiAVObject_SetScale(transform.m_fScale);
    }
    return result;
}

// Constructs a temporary effect that stores a node pointer, a filename, and an identity motion transform.
// @fnv 0x00688fc0
BSTempEffectParticle::BSTempEffectParticle(TESObjectCELL* cell, float radius, const char* filename, void* node)
    : BSTempEffect(cell, radius), m_flt(0), m_20(0), m_kMotionTransform(), m_5c(),
      m_68()
{
    m_flt = 0;
    m_20 = node;
    m_kMotionTransform.ResetToIdentity();
    pFilename = filename;
    m_58 = 0;
}

namespace fnv_00689cb0 {
struct SGBaseFormComponent
{
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(SGBaseFormComponent* component);
    virtual bool CompareWithBase(SGBaseFormComponent* component);
};

struct SGForm : public SGBaseFormComponent
{
    virtual ~SGForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07(void);
    virtual bool Load(void* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(void* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(void* modInfo);
    virtual void WriteFormInfo(void* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(void* form);
    virtual void* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned int changedFlags);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual unsigned int GetSaveSize(unsigned int changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned int changedFlags);
    virtual void LoadGame(void* arg);
    virtual void LoadGame2(unsigned int changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned int changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned int GetTypeID(void);
    virtual void GetDebugName(void* dst);
    virtual bool IsQuestItem(void);
    virtual bool Unk_26(void);
    virtual bool Unk_27(void);
    virtual bool Unk_28(void);
    virtual bool Unk_29(bool set);
    virtual bool Unk_2A(bool set);
    virtual bool Unk_2B(void);
    virtual bool Unk_2C(void);
    virtual bool Unk_2D(void);
    virtual bool Unk_2E(void);
    virtual void Unk_2F(bool set);
    virtual bool Unk_30(void);
    virtual void MarkForDeletion(bool set);
    virtual void SetAltered(bool set);
    virtual void SetQuestItem(bool set);
    virtual void Unk_34(bool set);
    virtual void Unk_35(bool set);
    virtual void Unk_36(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(void* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41(void);
    virtual void CopyFrom(void* form);
    virtual bool Compare(void* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned int formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned int refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
};

struct SGChangeRecord
{
    unsigned int auiFormId;
    unsigned char cType;
    unsigned char ucChangeFlags[4];
};

struct SGSaveLoadGame
{
    char* FUN_00825c00();
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_SaveGameDataOLD(void* apData, unsigned int auiSize);
    SGChangeRecord* FUN_004fd3e0();
};
extern SGSaveLoadGame* DAT_011de45c;

struct SGSettingBool
{
    unsigned char* FUN_00408d60();
};
extern SGSettingBool DAT_011de4e8;

struct SGPoint3
{
    float x;
    float y;
    float z;
};

struct SGMatrix3;

struct SGQuaternion
{
    float w;
    float x;
    float y;
    float z;
    SGQuaternion();
    void FUN_00a6df40(const SGMatrix3& arRotate);
};

struct SGObject
{
};
struct SGControllerManager;

struct SGAVObject
{
    const SGMatrix3& NiAVObject_GetRotate_006a9540();
    SGPoint3& GetTranslate_0043c490();
    float GetFloatAt64();
    SGObject* NiObjectNET_GetControllers();
};

struct SGNodePtr
{
    operator SGAVObject*() const;
};

SGControllerManager* __cdecl NiObject_DynamicCast(const NiRTTI* apRTTI, SGObject* apObject);
unsigned short __cdecl TESObjectREFR_GetControllerManagerSaveSize(SGControllerManager* apManager);
void __cdecl TESObjectREFR_SaveControllerManager(SGControllerManager* apManager, float afTime);
extern const float DAT_01012054;
SGForm* __cdecl TESForm_GetFormByNumericID(unsigned int auiFormID);
void __cdecl ProgramFlow(const char* apFormat, ...);
void __cdecl Warning_005b5e40(const char* apFormat, ...);
unsigned int __cdecl BSstrlen(const char* apString);

static const char s_szParticleFile[] =
    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp";

// Writes particle effect state (filename, transform, controller sequence) to the save stream and logs the block size.
// @fnv 0x00689cb0
}  // namespace fnv_00689cb0

void BSTempEffectParticle::SaveGame()
{
    using namespace fnv_00689cb0;
    unsigned short usBlockLen = 0;
    unsigned short* pSizeLoc = 0;
    char* pBeginPos = fnv_00689cb0::DAT_011de45c->FUN_00825c00();
    if (*fnv_00689cb0::DAT_011de4e8.FUN_00408d60())
    {
        pBeginPos = fnv_00689cb0::DAT_011de45c->FUN_00825c00();
    }
    if (fnv_00689cb0::DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiMarker = 'BLOK';
        fnv_00689cb0::DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&uiMarker, 4);
        pSizeLoc = (unsigned short*)fnv_00689cb0::DAT_011de45c->FUN_00825c00();
        fnv_00689cb0::DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&usBlockLen, 2);
    }

    BSTempEffect::SaveGame();
    unsigned char ucLength = (unsigned char)fnv_00689cb0::BSstrlen(pFilename);
    fnv_00689cb0::DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&ucLength, 1);
    fnv_00689cb0::DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD((void*)pFilename, ucLength);

    SGQuaternion kQuaternion;
    kQuaternion.FUN_00a6df40(((SGAVObject*)reinterpret_cast<SGNodePtr&>(m_flt))->NiAVObject_GetRotate_006a9540());
    fnv_00689cb0::DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&kQuaternion, 16);
    SGPoint3 kLocalTranslate = ((SGAVObject*)reinterpret_cast<SGNodePtr&>(m_flt))->GetTranslate_0043c490();
    fnv_00689cb0::DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&kLocalTranslate, 12);
    float fLocScale = ((SGAVObject*)reinterpret_cast<SGNodePtr&>(m_flt))->GetFloatAt64();
    fnv_00689cb0::DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&fLocScale, 4);

    unsigned short usSequence = 0;
    SGControllerManager* pController = fnv_00689cb0::NiObject_DynamicCast(&DAT_011f36ac, ((SGAVObject*)reinterpret_cast<SGNodePtr&>(m_flt))->NiObjectNET_GetControllers());
    if (pController)
    {
        usSequence = fnv_00689cb0::TESObjectREFR_GetControllerManagerSaveSize(pController);
    }
    fnv_00689cb0::DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&usSequence, 2);
    if (usSequence)
    {
        fnv_00689cb0::TESObjectREFR_SaveControllerManager(pController, fnv_00689cb0::DAT_01012054);
    }

    if (*fnv_00689cb0::DAT_011de4e8.FUN_00408d60())
    {
        char* pDebugEnd = fnv_00689cb0::DAT_011de45c->FUN_00825c00();
        SGChangeRecord* pChange = fnv_00689cb0::DAT_011de45c->FUN_004fd3e0();
        if (pChange)
        {
            SGForm* pForm = fnv_00689cb0::TESForm_GetFormByNumericID(pChange->auiFormId);
            fnv_00689cb0::ProgramFlow("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         pDebugEnd - pBeginPos, pChange->auiFormId, pForm->GetName(),
                         *(unsigned int*)pChange->ucChangeFlags, 411, s_szParticleFile);
        }
        else
        {
            fnv_00689cb0::ProgramFlow("SaveGame(): %-5i ending at line %i in file %s", pDebugEnd - pBeginPos, 411, s_szParticleFile);
        }
    }
    if (fnv_00689cb0::DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiEnd = (unsigned int)fnv_00689cb0::DAT_011de45c->FUN_00825c00();
        unsigned int uiStart = (unsigned int)pSizeLoc;
        if (uiEnd > uiStart + 0xFFFF)
        {
            fnv_00689cb0::Warning_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         s_szParticleFile, 411);
        }
        *pSizeLoc = (unsigned short)(uiEnd - uiStart);
    }
}

