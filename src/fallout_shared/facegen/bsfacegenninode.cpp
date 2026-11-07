// fallout_shared/facegen/bsfacegenninode.cpp: FaceNode, FaceGenNode, DumpNode (33 functions)

#include <stddef.h>

#include "../../../include/DIALOGUE_EMOTION.h"
#include "../../../include/PACKAGE_OBJECT_TYPE.h"
#include "../../../include/SIT_SLEEP_STATE.h"
#include "../../../include/PROCESS_TYPE.h"
#include "../../../include/BSFaceGenAnimationData.h"
#include "../../../include/BSFaceGenNiNode.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/Setting.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/MobileObject.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiTriBasedGeom.h"
#include "../../../include/BSFaceGenMorphData.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (pkNew != 0)
            pkNew->IncRefCount();
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
    }
    return *this;
}

// @fnv 0x006629e0
const NiRTTI* BSFaceGenNiNode::GetRTTI() const
{
    return &ms_kRTTI;
}

// @fnv 0x006629f0
BSFaceGenAnimationData* BSFaceGenNiNode::GetAnimationData()
{
    return spAnimationData;
}

// @fnv 0x00439920
void BSFaceGenNiNode::SetAnimationData(BSFaceGenAnimationData* apData)
{
    spAnimationData = apData;
}

// @fnv 0x00662a60
void BSFaceGenNiNode::SetAnimationUpdate(bool abUpdate)
{
    bAnimationUpdate = abUpdate;
}

// @fnv 0x0097ce70
void BSFaceGenNiNode::SetApplyRotToParent(bool abApply)
{
    bApplyRotationToParent = abApply;
}

extern NiNode* DAT_011d59ec;
extern const NiPoint3 _NiPoint3_ZERO;

// @fnv 0x006633f0
// src: XBOX_PDB 0x006633f0
const NiPoint3& BSFaceGenManager_GetCameraPosition()
{
    return DAT_011d59ec ? static_cast<const NiNode*>(DAT_011d59ec)->NiAVObject_GetWorldTranslate() : _NiPoint3_ZERO;
}

struct GeometryVertexBuffer
{
    char b[12];
    GeometryVertexBuffer();
};
struct FUN_00663430
{
    char* ptri;
    GeometryVertexBuffer iter;
    FUN_00663430();
};
// @fnv 0x00663430
FUN_00663430::FUN_00663430()
{}

// @fnv 0x006639f0
// src: XBOX_PDB 0x006639f0
char __fastcall BSFaceGenAnimationData_ShouldHeadTrack(char* pThis)
{
    return pThis[0x189];
}

struct FUN_00663a10_shell : public BSFaceGenAnimationData
{
    void BSFaceGenAnimationData_SetShouldHeadTrack(bool);
};

// @fnv 0x00663a10
// src: COMMUNITY 0x00663a10
void FUN_00663a10_shell::BSFaceGenAnimationData_SetShouldHeadTrack(bool abShouldHeadTrack)
{
    *((bool*)((char*)this + 0x189)) = abShouldHeadTrack;
}

// 0x00408d60 is a folded byte-pointer getter (also ProcessLists::GetLifeStateControlFlag); g_011d5a5c and g_011df6d0
// are not the ProcessLists singleton 0x011e0e80
class FlagGetterView
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

extern FlagGetterView g_011d5a5c;

// @fnv 0x00663a30
// src: XBOX_PDB 0x00663a30
unsigned char BSFaceGenManager_GetUseLOD()
{
    return *g_011d5a5c.GetLifeStateControlFlag();
}

// @fnv 0x00663a50
char __fastcall GetByteAt1D(char* pThis)
{
    return pThis[0x1d];
}

namespace fnv_00663a70 {
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
struct FUN_00663a70_shell : public BSFaceGenNiNode
{
    void UpdateFaceGenNode(NiUpdateData*, unsigned int);
};

struct Stand663
{
    void UpdateFaceGenAnimation(NiUpdateData*);
};
// @fnv 0x00663a70
void FUN_00663a70_shell::UpdateFaceGenNode(NiUpdateData* UpdateData, unsigned int uFlags)
{
    if (!((NiAVObject*)this)->GetAppCulled_00456610())
        ((Stand663*)this)->UpdateFaceGenAnimation(UpdateData);
    ((NiNode*)this)->NiNode::UpdateDownwardPass(*UpdateData, uFlags);
}
}  // namespace fnv_00663a70

struct BSFadeNode;
struct BSMultiBoundNode;
struct BSResizableTriShape;
struct BSSegmentedTriShape;
struct NiCullingProcess;
struct NiGeometry;
struct NiLines;
struct NiParticles;
struct NiTriShape;
struct NiTriStrips;
struct NiVisibleArray;
struct bhkBlendCollisionObject;
struct bhkLimitedHingeConstraint;
struct bhkNiCollisionObject;
struct bhkRigidBody;
#include "../../../include/NiMemObject.h"
#include "../../../include/ProcessLists.h"
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_00663ae0_shell : public BSFaceGenNiNode
{
    void CullWithBoundAccum(NiCullingProcess*);
};

struct NiBound;

struct DummyAccum
{
    int GetField19C();
    void RenderBound(NiBound&, int);
    void DispatchBatchRenderer();
};

DummyAccum* __fastcall GetStringAtOffsetC4(NiCullingProcess*);

// @fnv 0x00663ae0
void FUN_00663ae0_shell::CullWithBoundAccum(NiCullingProcess* arCuller)
{
    DummyAccum* paccum = GetStringAtOffsetC4(arCuller);
    int kmode = GetStringAtOffsetC4(arCuller)->GetField19C();
    if (kmode == 0)
    {
        paccum->RenderBound(((NiAVObject*)this)->GetBoundingVolume(), 0);
    }
    ((NiNode*)this)->NiNode::OnVisible(*arCuller);
    if (kmode == 0)
    {
        paccum->DispatchBatchRenderer();
    }
}

struct BSStrHelper663
{
    operator const char*() const;
};
// @fnv 0x00663b40
const char* __fastcall GetStringAtOffsetC4(void* p)
{
    return *(BSStrHelper663*)((char*)p + 0xc4);
}

// @fnv 0x00663b60
unsigned int __fastcall GetField19C(char* pThis)
{
    return *(unsigned int*)(pThis + 0x19c);
}

struct FUN_00662a40_shell
{
    char __thiscall GetByteAtOffsetD6();
};

// @fnv 0x00662a40
char __thiscall FUN_00662a40_shell::GetByteAtOffsetD6()
{
    return *(char*)((char*)this + 0xd6);
}

struct GlobalObject_0044f440
{
    void FUN_00450410(void);
};

GlobalObject_0044f440 g_011d5b28;

// @fnv 0x006633d0
// src: COMMUNITY 0x006633d0
void BSFaceGenManager_GetLODDistance(void)
{
    g_011d5b28.FUN_00450410();
}

namespace fnv_006633e0 {
struct GlobalObject_0044f440
{
    void FUN_00450410(void);
};

GlobalObject_0044f440 g_011d5b34;

// @fnv 0x006633e0
// src: COMMUNITY 0x006633e0
void BSFaceGenManager_GetTalkingDistance()
{
    g_011d5b34.FUN_00450410();
}
}  // namespace fnv_006633e0

struct FUN_00662aa0_shell : BSFaceGenNiNode
{
    void SetFixedNormals(bool abFixedNormals);
};

// @fnv 0x00662aa0
void FUN_00662aa0_shell::SetFixedNormals(bool abFixedNormals)
{
    *reinterpret_cast<char*>(reinterpret_cast<unsigned char*>(this) + 0xd5) = abFixedNormals;
}

namespace fnv_00663ab0 {

struct FUN_00663ab0_class : NiNode
{
    void UpdateFaceGenAnimation(NiUpdateData&);
    void BSFaceGenNiNode_UpdateTransformAndBounds(NiUpdateData&);
};

// Calls UpdateFaceGenAnimation with updateData, then NiNode::UpdateTransformAndBounds with updateData.
// @fnv 0x00663ab0
// src: XBOX_PDB 0x00663ab0
void FUN_00663ab0_class::BSFaceGenNiNode_UpdateTransformAndBounds(NiUpdateData& updateData)
{
    this->UpdateFaceGenAnimation(updateData);
    NiNode::UpdateTransformAndBounds(updateData);
}
}  // namespace fnv_00663ab0

struct Ret36
{
    unsigned int v[9];
};
struct FUN_00662a10_shell
{
    char _pad[0xB0];
    Ret36 _m;
    Ret36 GetRet36();
};
// Returns the stored Ret36 value (_m) by value.
// @fnv 0x00662a10
Ret36 FUN_00662a10_shell::GetRet36()
{
    return _m;
}

struct FUN_00662a80_shell : BSFaceGenNiNode
{
    unsigned char BSFaceGenNiNode_GetApplyRotToParent();
};

// @fnv 0x00662a80
// src: XBOX_PDB 0x00662a80
unsigned char FUN_00662a80_shell::BSFaceGenNiNode_GetApplyRotToParent()
{
    return *(unsigned char*)((char*)this + 0xd8);
}

struct FUN_009a0240_shell : BSFaceGenNiNode
{
    char GetFixedNormals();
};

// @fnv 0x009a0240
char FUN_009a0240_shell::GetFixedNormals()
{
    return reinterpret_cast<const unsigned char*>(this)[0xd5];
}

class Actor;
class PlayerCharacter;
namespace fnv_00663510 {
extern PlayerCharacter* g_thePlayer;

class FaceGenAnimData
{
  public:
    virtual void va000();
    virtual void va004();
    virtual void va008();
    virtual void va00c();
    virtual void va010();
    virtual void va014();
    virtual void va018();
    virtual void va01c();
    virtual void va020();
    virtual void va024();
    virtual void va028();
    virtual void va02c();
    virtual void va030();
    virtual void va034();
    virtual void va038();
    virtual void va03c();
    virtual void va040();
    virtual void va044();
    virtual void va048();
    virtual void va04c();
    virtual void va050();
    virtual void va054();
    virtual void va058();
    virtual void va05c();
    virtual void va060();
    virtual void va064();
    virtual void va068();
    virtual void va06c();
    virtual void va070();
    virtual void va074();
    virtual void va078();
    virtual void va07c();
    virtual void va080();
    virtual void va084();
    virtual void va088();
    virtual void va08c();
    virtual void va090();
    virtual void va094();
    virtual void va098();
    virtual void va09c();
    virtual void va0a0();
    virtual void va0a4();
    virtual void va0a8();
    virtual void va0ac();
    virtual void va0b0();
    virtual void va0b4();
    virtual void va0b8();
    virtual void va0bc();
    virtual void va0c0();
    virtual void va0c4();
    virtual bool UpdateMorphs();
    virtual bool NeedsUpdate();
    virtual void SetUpdated(bool);
    virtual bool IsDead();
    virtual void vb000();
    virtual void vb004();
    virtual void vb008();
    virtual void vb00c();
    virtual void vb010();
    virtual void vb014();
    virtual void vb018();
    virtual void vb01c();
    virtual void vb020();
    virtual void vb024();
    virtual void vb028();
    virtual void vb02c();
    virtual void vb030();
    virtual void vb034();
    virtual void vb038();
    virtual void vb03c();
    virtual void vb040();
    virtual void vb044();
    virtual void vb048();
    virtual void vb04c();
    virtual bool UpdateAnimation(float);
    bool BSFaceGenAnimationData_UpdateEyeTracking(float, unsigned int);
};
struct FUN_00663a10_shell
{
    void BSFaceGenAnimationData_SetShouldHeadTrack(bool);
};

class FaceGenNode
{
  public:
    virtual void vn000();
    virtual void vn004();
    virtual void vn008();
    virtual void vn00c();
    virtual void vn010();
    virtual void vn014();
    virtual void vn018();
    virtual void vn01c();
    virtual void vn020();
    virtual void vn024();
    virtual void vn028();
    virtual void vn02c();
    virtual void vn030();
    virtual void vn034();
    virtual void vn038();
    virtual void vn03c();
    virtual void vn040();
    virtual void vn044();
    virtual void vn048();
    virtual void vn04c();
    virtual void vn050();
    virtual void vn054();
    virtual void vn058();
    virtual void vn05c();
    virtual void vn060();
    virtual void vn064();
    virtual void vn068();
    virtual void vn06c();
    virtual void vn070();
    virtual void vn074();
    virtual void vn078();
    virtual void vn07c();
    virtual void vn080();
    virtual void vn084();
    virtual void vn088();
    virtual void vn08c();
    virtual void vn090();
    virtual void vn094();
    virtual void vn098();
    virtual void vn09c();
    virtual void vn0a0();
    virtual void vn0a4();
    virtual void vn0a8();
    virtual void vn0ac();
    virtual void vn0b0();
    virtual void vn0b4();
    virtual void vn0b8();
    virtual void vn0bc();
    virtual void vn0c0();
    virtual void vn0c4();
    virtual void vn0c8();
    virtual void vn0cc();
    virtual void vn0d0();
    virtual void vn0d4();
    virtual void vn0d8();
    virtual void vn0dc();
    virtual void vn0e0();
    virtual void vn0e4();
    virtual void vn0e8();
    virtual void vn0ec();
    virtual void vn0f0();
    virtual void vn0f4();
    virtual void vn0f8();
    virtual void vn0fc();
    virtual FaceGenAnimData* GetAnimationData();
    bool GetByteAtOffsetE1();
    void UpdateStateByDistance(int);
    void BSFaceGenNiNode_UpdateAllChildrenMorphData(bool);
};
class Calendar
{
  public:
    unsigned int GetDaysPassed();
};
class Twin_0084d030
{
  public:
    float GetStoredFloatValue();
};
// Exe 0x00663510: unit-local Interface view; declarations and layout are preserved.
class BsfacegenninodeInterfaceView
{
  public:
    static bool __cdecl IsSaveLoadActive();
};
extern Setting g_011c5724;
extern Twin_0084d030 g_timeGlobal;
extern FlagGetterView g_011df6d0;
extern ProcessLists DAT_011e0e80;
unsigned char __cdecl BSFaceGenManager_GetUseLOD();
unsigned char __fastcall BSFaceGenAnimationData_ShouldHeadTrack(char*);
unsigned char __fastcall GetByteAt1D(char*);
void __cdecl BSFaceGenManager_CycleFaceGenCoordValue(Actor*);

struct FUN_00663510_t
{
    void UpdateFaceGenAnimation(NiUpdateData* UpdateData);
};

// @fnv 0x00663510
void FUN_00663510_t::UpdateFaceGenAnimation(NiUpdateData* UpdateData)
{
    if (((NiAVObject*)this)->GetAppCulled_00456610())
        return;

    bool bchanged = false;
    bool bdead = ((FaceGenNode*)this)->GetAnimationData()->IsDead();

    if (BSFaceGenManager_GetUseLOD() && !((FaceGenNode*)this)->GetByteAtOffsetE1() && UpdateData->fTime > 0.0)
        ((FaceGenNode*)this)->UpdateStateByDistance(-1);

    // NiUpdateData has its controller flag at +4; FaceGenUpdateData is a separate 32-byte morph context.
    if (!((FaceGenNode*)this)->GetAnimationData() ||
        (!*reinterpret_cast<const bool*>(reinterpret_cast<const char*>(UpdateData) + 4) &&
         !((FaceGenNode*)this)->GetAnimationData()->NeedsUpdate()))
        return;

    *(float*)((char*)this + 0xdc) = UpdateData->fTime;
    if (((BSFaceGenNiNode*)this)->bAnimationUpdate)
    {
        ((FaceGenNode*)this)->GetAnimationData()->SetUpdated(false);
        if (GetByteAt1D((char*)&g_timeGlobal))
            bchanged = ((FaceGenNode*)this)->GetAnimationData()->UpdateAnimation(0.0f);
        else
            bchanged = ((FaceGenNode*)this)
                           ->GetAnimationData()
                           ->UpdateAnimation(g_timeGlobal.GetStoredFloatValue() * *g_011c5724.Float());
    }
    else
    {
        bchanged = ((FaceGenNode*)this)->GetAnimationData()->UpdateMorphs();
    }

    if (((BSFaceGenNiNode*)this)->bAnimationUpdate && *(Actor**)((char*)this + 0xe8) &&
        ((MobileObject*)*(Actor**)((char*)this + 0xe8))->GetCurrentAIProcess() &&
        ((MobileObject*)*(Actor**)((char*)this + 0xe8))->GetCurrentAIProcess()->GetPrimaryTargetReference() &&
        BSFaceGenAnimationData_ShouldHeadTrack((char*)((FaceGenNode*)this)->GetAnimationData()) &&
        ((BSFaceGenNiNode*)this)->bApplyRotationToParent && !*g_011df6d0.GetLifeStateControlFlag() &&
        ((NiAVObject*)this)->GetSelectiveUpdate())
    {
        bool beyeTrackingChanged;
        if (GetByteAt1D((char*)&g_timeGlobal))
            beyeTrackingChanged =
                ((FaceGenNode*)this)->GetAnimationData()->BSFaceGenAnimationData_UpdateEyeTracking(0.0f, ((Calendar*)this)->GetDaysPassed());
        else
            beyeTrackingChanged =
                ((FaceGenNode*)this)
                    ->GetAnimationData()
                    ->BSFaceGenAnimationData_UpdateEyeTracking(g_timeGlobal.GetStoredFloatValue(), ((Calendar*)this)->GetDaysPassed());
        bchanged = bchanged || beyeTrackingChanged;
    }

    if (bchanged || *(bool*)((char*)this + 0xe4))
    {
        int inumallowedtoupdate = 10;
        bool bupdate = false;
        if (((NiAVObject*)this)->GetSelectiveUpdate())
        {
            if (((FaceGenNode*)this)->GetAnimationData()->IsDead() ||
                DAT_011e0e80.CanAddActorToList(*(Actor**)((char*)this + 0xe8), inumallowedtoupdate) ||
                *(Actor**)((char*)this + 0xe8) == (Actor*)g_thePlayer || BsfacegenninodeInterfaceView::IsSaveLoadActive())
                bupdate = true;
            if (*(Actor**)((char*)this + 0xe8) &&
                !((MobileObject*)*(Actor**)((char*)this + 0xe8))->GetCurrentProcessLevel() &&
                ((MobileObject*)*(Actor**)((char*)this + 0xe8))->GetCurrentAIProcess()->IsAsleep() &&
                ((MobileObject*)*(Actor**)((char*)this + 0xe8))->GetCurrentAIProcess()->GetMobileObject() &&
                ((MobileObject*)*(Actor**)((char*)this + 0xe8))->GetCurrentAIProcess()->GetMobileObject() ==
                    (::MobileObject*)g_thePlayer)
                bupdate = true;
        }
        if (bupdate || *(bool*)((char*)this + 0xe4))
        {
            ((FaceGenNode*)this)->BSFaceGenNiNode_UpdateAllChildrenMorphData(bchanged);
        }
        else
        {
            *(bool*)((char*)this + 0xd4) = true;
            *(bool*)((char*)this + 0xe4) = true;
        }
    }

    ((FUN_00663a10_shell*)((FaceGenNode*)this)->GetAnimationData())->BSFaceGenAnimationData_SetShouldHeadTrack(true);
    if (*(bool*)((char*)this + 0xec) && *(Actor**)((char*)this + 0xe8))
        BSFaceGenManager_CycleFaceGenCoordValue(*(Actor**)((char*)this + 0xe8));
}
}  // namespace fnv_00663510

struct CloningProcess
{
};

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

struct FUN_006628c0 : A51BF0Base
{
    FUN_006628c0();

    void BSFaceGenNiNode_CopyMembers(FUN_006628c0* pnode, CloningProcess& cloneData);

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
    virtual void v26(CloningProcess& cloneData);

    unsigned char padding[0xec];

    FUN_006628c0* BSFaceGenNiNode_CreateClone(CloningProcess& cloneData);
};

// @fnv 0x00663b80
// src: XBOX_PDB 0x00663b80
FUN_006628c0* FUN_006628c0::BSFaceGenNiNode_CreateClone(CloningProcess& cloneData)
{
    FUN_006628c0* pnode = new FUN_006628c0;

    BSFaceGenNiNode_CopyMembers(pnode, cloneData);
    v26(cloneData);

    return pnode;
}

struct Helper62d0
{
    void* operator=(void const*);
    void* value;
};

struct FUN_00663c30_shell : NiNode
{
    struct Block36
    {
        int values[9];
    };

    Helper62d0 helper;
    Block36 block;
    unsigned char value_d4;
    unsigned char value_d5;
    unsigned char value_d6;
    unsigned char value_d7;
    unsigned char padding_d8[4];
    float value_dc;
    unsigned char value_e0;
    unsigned char value_e1;

    void BSFaceGenNiNode_CopyMembers(FUN_00663c30_shell*, void*);
};

// @fnv 0x00663c30
// src: XBOX_PDB 0x00663c30
void FUN_00663c30_shell::BSFaceGenNiNode_CopyMembers(FUN_00663c30_shell* pDest, void* pCloneData)
{
    if (pDest == 0)
    {
    }
    else
    {
        NiNode::CopyMemberData(pDest, *static_cast<CloningProcess*>(pCloneData));

        pDest->helper.operator=(&helper);

        pDest->block = block;

        pDest->value_d4 = value_d4;
        pDest->value_d5 = value_d5;
        pDest->value_d6 = value_d6;
        pDest->value_d7 = value_d7;

        pDest->value_dc = value_dc;

        pDest->value_e0 = value_e0;
        pDest->value_e1 = value_e1;
    }
}

struct FUN_00662b70_cls
{
    struct Block36
    {
        int values[9];
    };

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
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual unsigned int v108(unsigned int* out);

    unsigned char unk04[0xac];
    Block36 block;
    unsigned char unkD4;
    unsigned char unkD5;
    unsigned char unkD6;
    unsigned char flagD7;

    void SetRotate_0043fa80(unsigned int value);
    void BSFaceGenNiNode_SetBaseRotation(Block36* src);
};

// Copies the 36-byte block from src, sets flagD7 to 1, then calls FUN_0043fa80 with the result of v108(&local).
// @fnv 0x00662b70
// src: XBOX_PDB 0x00662b70
void FUN_00662b70_cls::BSFaceGenNiNode_SetBaseRotation(Block36* apBlock)
{
    unsigned int pad1;
    unsigned int pad2;
    unsigned int pad3;
    unsigned int pad4;
    unsigned int pad5;
    unsigned int pad6;
    unsigned int pad7;
    unsigned int pad8;
    {
        unsigned int local;
        block = *apBlock;
        flagD7 = 1;
        SetRotate_0043fa80(v108(&local));
    }
}

// ApplyParamValues candidate
class FUN_00662bc0_Sub;
class FUN_00662bc0_Holder
{
  public:
    void ApplyMorph(int a0, int a1, void* a2, int a3, float a4);
};
class FUN_00662bc0_Obj
{
  public:
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
    virtual float v37(int i);
};
class FUN_00662bc0_Param
{
  public:
    void* m_00;
    int m_04;
    int unk08;
    int unk0c;
    FUN_00662bc0_Holder* m_10;
    int m_14;
    int unk18;
    unsigned char m_1c;
};
extern "C" void __cdecl BSFaceGenUtils_RefreshMeshFromBaseMorphExtraData(void* a, void* b);
extern const double DAT_01012060;
extern const double DAT_01012070;
class FUN_00662bc0_cls
{
  public:
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
    virtual void v62();
    virtual void v63();
    virtual FUN_00662bc0_Obj* v64();
    void ApplyParamValues(FUN_00662bc0_Param* p);
};
// @fnv 0x00662bc0
void FUN_00662bc0_cls::ApplyParamValues(FUN_00662bc0_Param* p)
{
    for (int i = 0; i < 15; i++)
    {
        float val;
        val = v64()->v37(i);
        if (val > DAT_01012060 && val >= DAT_01012060 && val <= DAT_01012070)
        {
            if (p->m_1c == 0)
            {
                BSFaceGenUtils_RefreshMeshFromBaseMorphExtraData(p->m_00, &p->m_04);
                p->m_1c = 1;
            }
            p->m_10->ApplyMorph(1, i, p->m_00, p->m_14, val);
        }
    }
}

struct Sub10Obj;
struct FUN_00662f70_cls;
struct FUN_00662f70_arg;
struct FUN_00662f70_p
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual float v2B(int);
};

struct Sub10Obj
{
    void ApplyMorph(int, int, int, int, float);
};

struct FUN_00662f70_arg
{
    int m_00;
    int m_04;
    int unk08;
    int unk0c;
    Sub10Obj* m_10;
    int m_14;
    int unk18;
    unsigned char m_1c;
};

struct FUN_00662f70_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
    virtual FUN_00662f70_p* v40();
    void BSFaceGenNiNode_ApplyFacialCustomMorphs(FUN_00662f70_arg* a1);
};

void __cdecl BSFaceGenUtils_RefreshMeshFromBaseMorphExtraData(int a, int b);

// @fnv 0x00662f70
// src: COMMUNITY 0x00662f70
void FUN_00662f70_cls::BSFaceGenNiNode_ApplyFacialCustomMorphs(FUN_00662f70_arg* a1)
{
    int i;
    float f;
    for (i = 0; i < 1; i++)
    {
        f = this->v40()->v2B(i);
        if (f > 0.0 && f >= 0.0 && f <= 1.0)
        {
            if (a1->m_1c == 0)
            {
                BSFaceGenUtils_RefreshMeshFromBaseMorphExtraData(a1->m_00, (int)&a1->m_04);
                a1->m_1c = 1;
            }
            a1->m_10->ApplyMorph(3, i, a1->m_00, a1->m_14, f);
        }
    }
}


const NiPoint3& B663450GetCenter();
float B663450GetRadius();

class B663450Actor;

void __cdecl BSFaceGenManager_ReplaceFaceMeshLOD(B663450Actor* pkActor, int iState);

class B663450Actor
{
  public:
    const NiPoint3& GetPosition();
    bool GetByteAtE0();
    void UpdateStateByDistance(int iState);
};

// Compares the actor's distance to the center against the radius plus or minus a margin and calls FUN_00653e50 with state 0 or 1 accordingly.
// @fnv 0x00663450
void B663450Actor::UpdateStateByDistance(int iState)
{
    NiPoint3 kCenter3 = B663450GetCenter();
    float fMargin = 10.0f;
    float fDist = (kCenter3 - GetPosition()).Length();
    if ((fDist > B663450GetRadius() + fMargin && !GetByteAtE0()) || iState == 0)
        BSFaceGenManager_ReplaceFaceMeshLOD(this, 0);
    else if ((fDist < B663450GetRadius() - fMargin && GetByteAtE0()) || iState == 1)
        BSFaceGenManager_ReplaceFaceMeshLOD(this, 1);
}

struct FUN_00662ca0_Data
{
    float GetValue(int i);
};
class FUN_00662ca0_cls
{
  public:
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
    virtual void v62();
    virtual void v63();
    virtual FUN_00662ca0_Data* GetData();
    void ApplyParameterValues(FUN_00662bc0_Param* p);
};
void __cdecl SplitSignedDifference(float a, float b, float* pA, float* pB);

// @fnv 0x00662ca0
void FUN_00662ca0_cls::ApplyParameterValues(FUN_00662bc0_Param* pParam)
{
    float aFValue;
    float fFirst;
    float fSecond;
    for (int iIndex = 0; iIndex < 17; iIndex++)
    {
        switch (iIndex)
        {
        case 14:
        case 15:
        case 16:
            continue;
        case 8:
        case 11:
            SplitSignedDifference(GetData()->GetValue(8), GetData()->GetValue(11), &fFirst, &fSecond);
            aFValue = (iIndex == 8) ? fFirst : fSecond;
            break;
        case 9:
        case 10:
            SplitSignedDifference(GetData()->GetValue(9), GetData()->GetValue(10), &fFirst, &fSecond);
            aFValue = (iIndex == 9) ? fFirst : fSecond;
            break;
        default:
            aFValue = GetData()->GetValue(iIndex);
            break;
        }
        if (aFValue > DAT_01012060 && aFValue >= DAT_01012060 && aFValue <= 1.0)
        {
            if (!pParam->m_1c)
            {
                BSFaceGenUtils_RefreshMeshFromBaseMorphExtraData(pParam->m_00, &pParam->m_04);
                pParam->m_1c = 1;
            }
            pParam->m_10->ApplyMorph(2, iIndex, pParam->m_00, pParam->m_14, aFValue);
        }
    }
}

struct BoneName
{
    const char* FUN_0043b1b0();
};
struct SceneNode;
struct SkinData
{
    unsigned int FUN_008041a0();
};
struct SkinInstance
{
    SkinData* FUN_005585e0();
    SceneNode** FUN_00825c00();
    void SetBone(unsigned int, SceneNode*);
    void FUN_00437730(void*);
};
struct Geometry
{
    SkinInstance* NiGeometry_GetSkinInstance();
};
struct SceneNode
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual Geometry* AsGeometry();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4c();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5c();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6c();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7c();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8c();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual SceneNode* FindBone(BoneName*);
    BoneName* FUN_00413f40();
};
void FNV_Warning(const char*, ...);
struct FaceNode
{
    unsigned int FUN_0043b480();
    SceneNode* FUN_0043b4a0(unsigned int);
    void AttachBones(SceneNode*, bool);
};
// @fnv 0x006642e0
void FaceNode::AttachBones(SceneNode* parent, bool warn)
{
    unsigned int numBones, count, i;
    SceneNode* j;
    unsigned int bones;
    Geometry* skin;
    SkinInstance* bone;
    SceneNode** geometry;
    SceneNode* child;
    if (!parent)
        return;
    numBones = FUN_0043b480();
    for (count = 0; count < numBones; count++)
    {
        j = FUN_0043b4a0(count);
        if (!j)
            continue;
        skin = j->AsGeometry();
        if (!skin)
            continue;
        bone = skin->NiGeometry_GetSkinInstance();
        if (!bone || !bone->FUN_005585e0())
            continue;
        bones = bone->FUN_005585e0()->FUN_008041a0();
        geometry = bone->FUN_00825c00();
        if (!geometry || !bones)
            continue;
        for (i = 0; i < bones; i++)
        {
            child = parent->FindBone(geometry[i]->FUN_00413f40());
            if (child)
                bone->SetBone(i, child);
            else if (warn)
                FNV_Warning("MODELS: Could not find bone \"%s\" for the head node.",
                            geometry[i]->FUN_00413f40()->FUN_0043b1b0());
        }
        bone->FUN_00437730(this);
    }
}

namespace fnv_00663050 {
class MorphGeometryData
{
  public:
    bool FUN_00a67360(bool);
    void NiGeometryData_GetVerticesIterator(BSFaceGenMorphData::Buffers*);
    void NiGeometryData_UnlockPackedVertexData();
};
struct FUN_00663430
{
    NiTriBasedGeom* geometry;
    BSFaceGenMorphData::Buffers morph;
    FUN_00663430();
};
class AnimationState
{
  public:
    virtual void Unk_000();
    virtual void Unk_004();
    virtual void Unk_008();
    virtual void Unk_00c();
    virtual void Unk_010();
    virtual void Unk_014();
    virtual void Unk_018();
    virtual void Unk_01c();
    virtual void Unk_020();
    virtual void Unk_024();
    virtual void Unk_028();
    virtual void Unk_02c();
    virtual void Unk_030();
    virtual void Unk_034();
    virtual void Unk_038();
    virtual void Unk_03c();
    virtual void Unk_040();
    virtual void Unk_044();
    virtual void Unk_048();
    virtual void Unk_04c();
    virtual void Unk_050();
    virtual void Unk_054();
    virtual void Unk_058();
    virtual void Unk_05c();
    virtual void Unk_060();
    virtual void Unk_064();
    virtual void Unk_068();
    virtual void Unk_06c();
    virtual void Unk_070();
    virtual void Unk_074();
    virtual void Unk_078();
    virtual void Unk_07c();
    virtual void Unk_080();
    virtual void Unk_084();
    virtual void Unk_088();
    virtual void Unk_08c();
    virtual void Unk_090();
    virtual void Unk_094();
    virtual void Unk_098();
    virtual void Unk_09c();
    virtual void Unk_0a0();
    virtual void Unk_0a4();
    virtual void Unk_0a8();
    virtual void Unk_0ac();
    virtual void Unk_0b0();
    virtual void Update(float, bool, bool, bool, bool, bool);
    virtual void Unk_0b8();
    virtual void Unk_0bc();
    virtual void Unk_0c0();
    virtual void Unk_0c4();
    virtual void Unk_0c8();
    virtual void Unk_0cc();
    virtual void Unk_0d0();
    virtual bool IsActive();
    float BSFaceGenAnimationData_GetModifierValue(int);
};
class FaceGenParent
{
  public:
    virtual void Unk_000();
    virtual void Unk_004();
    virtual void Unk_008();
    virtual void Unk_00c();
    virtual int IsReady();
};
class FaceGenNode
{
  public:
    virtual void Unk_000();
    virtual void Unk_004();
    virtual void Unk_008();
    virtual void Unk_00c();
    virtual void Unk_010();
    virtual void Unk_014();
    virtual void Unk_018();
    virtual void Unk_01c();
    virtual void Unk_020();
    virtual void Unk_024();
    virtual void Unk_028();
    virtual void Unk_02c();
    virtual void Unk_030();
    virtual void Unk_034();
    virtual void Unk_038();
    virtual void Unk_03c();
    virtual void Unk_040();
    virtual void Unk_044();
    virtual void Unk_048();
    virtual void Unk_04c();
    virtual void Unk_050();
    virtual void Unk_054();
    virtual void Unk_058();
    virtual void Unk_05c();
    virtual void Unk_060();
    virtual void Unk_064();
    virtual void Unk_068();
    virtual void Unk_06c();
    virtual void Unk_070();
    virtual void Unk_074();
    virtual void Unk_078();
    virtual void Unk_07c();
    virtual void Unk_080();
    virtual void Unk_084();
    virtual void Unk_088();
    virtual void Unk_08c();
    virtual void Unk_090();
    virtual void Unk_094();
    virtual void Unk_098();
    virtual void Unk_09c();
    virtual void Unk_0a0();
    virtual void Unk_0a4();
    virtual void Unk_0a8();
    virtual void Unk_0ac();
    virtual void Unk_0b0();
    virtual void Unk_0b4();
    virtual void Unk_0b8();
    virtual void Unk_0bc();
    virtual void Unk_0c0();
    virtual void Unk_0c4();
    virtual void Unk_0c8();
    virtual void Unk_0cc();
    virtual void Unk_0d0();
    virtual void Unk_0d4();
    virtual void Unk_0d8();
    virtual void Unk_0dc();
    virtual void Unk_0e0();
    virtual void Unk_0e4();
    virtual void Unk_0e8();
    virtual void Unk_0ec();
    virtual void Unk_0f0();
    virtual void Unk_0f4();
    virtual void Unk_0f8();
    virtual void Unk_0fc();
    virtual AnimationState* GetAnimation();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    bool resetMorph;
    bool unkD5, unkD6, unkD7;
    unsigned int unkD8, unkDC;
    bool unkE0, unkE1;
    bool forceUpdate, skipUpdate, refreshMorph;
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int);
    const NiPoint3& NiAVObject_GetWorldTranslate() const;
    FaceGenParent* NiAVObject_GetParent();
    void BSFaceGenNiNode_ApplyFacialPhonemes(FUN_00663430*);
    void ApplyParamValues(FUN_00663430*);
    void ApplyParameterValues(FUN_00663430*);
    void BSFaceGenNiNode_ApplyFacialCustomMorphs(FUN_00663430*);
    void BSFaceGenNiNode_UpdateAllChildrenMorphData(bool);
};
void* BSFaceGenUtils_GetFaceGenMorphDataHead(void*);
NiExtraData* GetExtraDataIfPresent(NiAVObject*);
void BSFaceGenUtils_RefreshMeshFromBaseMorphExtraData(NiTriBasedGeom*, BSFaceGenMorphData::Buffers*);
const NiPoint3& BSFaceGenManager_GetCameraPosition();
float BSFaceGenManager_GetLODDistance();
float BSFaceGenManager_GetTalkingDistance();
unsigned char Main_GetSceneIsComplex();
bool Interface_IsInMenuMode();

// @fnv 0x00663050
// src: COMMUNITY 0x00663050
void FaceGenNode::BSFaceGenNiNode_UpdateAllChildrenMorphData(bool update)
{
    FUN_00663430 context_2;
    unsigned int count4 = FUN_0043b480();
    unsigned int index_;
    __declspec(align(4)) bool done2;  // Whether the morph was refreshed.
    NiAVObject* aUnknownObject;
    void* data8;          // Face data.
    NiExtraData* extra2;  // Geometry extra data.
    unsigned int kTotal;  // Vertex count.
    for (index_ = 0; index_ < count4; index_++)
    {
        done2 = false;
        aUnknownObject = FUN_0043b4a0(index_);
        if (!aUnknownObject)
            continue;
        context_2.geometry = aUnknownObject->IsTriBasedGeometry();
        if (!context_2.geometry)
            continue;
        if (!((MorphGeometryData*)context_2.geometry->GetModelData()))
            continue;
        data8 = BSFaceGenUtils_GetFaceGenMorphDataHead(context_2.geometry);
        if (!data8)
            continue;
        extra2 = GetExtraDataIfPresent((NiAVObject*)context_2.geometry);
        if (!extra2)
            continue;
        if (!((MorphGeometryData*)context_2.geometry->GetModelData())->FUN_00a67360(true))
            continue;
        ((MorphGeometryData*)context_2.geometry->GetModelData())->NiGeometryData_GetVerticesIterator(&context_2.morph);
        kTotal = context_2.geometry->GetVertexCount();
        if (update || resetMorph)
        {
            BSFaceGenUtils_RefreshMeshFromBaseMorphExtraData(context_2.geometry, &context_2.morph);
            done2 = true;
            resetMorph = false;
        }
        bool updated4 = false;  // Full update completed.
        bool active5 = false;   // Partial update completed.
        NiPoint3 origin6 = BSFaceGenManager_GetCameraPosition();
        float radius3 = 10.0f;
        float kRadius = (origin6 - NiAVObject_GetWorldTranslate()).FUN_00457990();
        float radiusX = BSFaceGenManager_GetLODDistance();
        float aMaximum = BSFaceGenManager_GetTalkingDistance();
        if (Main_GetSceneIsComplex())
        {
            radiusX *= 0.25;
            aMaximum *= 0.25;
        }
        bool aOverrideFlag_2 = false;  // Within the far update range.
        bool active = false;           // Within the near update range.
        if (kRadius <= aMaximum + radius3 || forceUpdate || Interface_IsInMenuMode())
        {
            aOverrideFlag_2 = true;
            if (kRadius <= radiusX + radius3 || forceUpdate || Interface_IsInMenuMode())
                active = true;
        }
        if (refreshMorph && !done2)
        {
            BSFaceGenUtils_RefreshMeshFromBaseMorphExtraData(context_2.geometry, &context_2.morph);
            done2 = true;
        }
        if (aOverrideFlag_2 && !skipUpdate)
        {
            BSFaceGenNiNode_ApplyFacialPhonemes(&context_2);
            active5 = true;
            if (active)
            {
                ApplyParamValues(&context_2);
                ApplyParameterValues(&context_2);
                BSFaceGenNiNode_ApplyFacialCustomMorphs(&context_2);
                updated4 = true;
            }
        }
        if (GetAnimation()->IsActive())
        {
            if (!updated4 && GetAnimation()->BSFaceGenAnimationData_GetModifierValue(0) > 0.0 && NiAVObject_GetParent()->IsReady())
            {
                ApplyParameterValues(&context_2);
                updated4 = true;
            }
        }
        else if (!active5 && kRadius > BSFaceGenManager_GetLODDistance() - radius3)
        {
            GetAnimation()->Update(0.0f, true, true, true, true, false);
        }
        ((MorphGeometryData*)context_2.geometry->GetModelData())->NiGeometryData_UnlockPackedVertexData();
    }
    refreshMorph = false;
}
}  // namespace fnv_00663050

extern const char DAT_01066238[];
struct DumpArray
{
    void FUN_0096a610(char* const&);
};
struct DumpAnimation
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
    virtual float v25(int);
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual float v29(int);
    float BSFaceGenAnimationData_GetModifierValue(int);
};
struct DumpPointer
{
    DumpAnimation* Modelloader_GetReferencedThis();
};
struct DumpActor
{
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct DumpString
{
    const char* Modelloader_GetReferencedThis();
};
extern DumpString DAT_011d5bf8;
char* NiViewerStrings_NiGetViewerString_Title(const char*);
char* NiGetViewerString_00a7d550(const char*, float);
const char* BSFaceGenManager_GetFaceGenExpressionText(int);
const char* BSFaceGenManager_GetFaceGenModifierText(int);
const char* BSFaceGenManager_GetFaceGenPhonemeText(int);
int BSsprintf(char*, int, const char*, ...);
struct DumpNode
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
    DumpPointer animation;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    unsigned char forceBaseMorph, fixedNormals, animationUpdate, rotatedLastUpdate;
    unsigned char applyRotationToParent, unkD9, unkDA, unkDB;
    float lastTime;
    unsigned char usingLoResHead, playerCharacter, inDialogue, unkE3;
    int unkE4;
    DumpActor* actor;
    void NiNode_GetViewerStrings(DumpArray*);
    void DumpToArray(DumpArray*);
};
// Appends formatted debug strings describing the node's flags, lastTime, actor, and animation data to the DumpArray.
// @fnv 0x00663d10
void DumpNode::DumpToArray(DumpArray* out)
{
    NiNode_GetViewerStrings(out);
    int i, k, buffer;
    char* j = NiViewerStrings_NiGetViewerString_Title(DAT_011d5bf8.Modelloader_GetReferencedThis());
    out->FUN_0096a610(j);
    char* title;
    title = new char[32];
    BSsprintf(title, 32, "bForceBaseMorph = %s", forceBaseMorph ? "true" : "false");
    out->FUN_0096a610(title);
    title = new char[32];
    BSsprintf(title, 32, "bFixedNormals = %s", fixedNormals ? "true" : "false");
    out->FUN_0096a610(title);
    title = new char[32];
    BSsprintf(title, 32, "bAnimationUpdate = %s", animationUpdate ? "true" : "false");
    out->FUN_0096a610(title);
    title = new char[32];
    BSsprintf(title, 32, "bRotatedLastUpdate = %s", rotatedLastUpdate ? "true" : "false");
    out->FUN_0096a610(title);
    title = new char[32];
    BSsprintf(title, 32, "bApplyRotationToParent = %s", applyRotationToParent ? "true" : "false");
    out->FUN_0096a610(title);
    title = new char[32];
    BSsprintf(title, 32, "bUsingLoResHead = %s", usingLoResHead ? "true" : "false");
    out->FUN_0096a610(title);
    title = new char[32];
    BSsprintf(title, 32, "bIAmPlayerCharacter = %s", playerCharacter ? "true" : "false");
    out->FUN_0096a610(title);
    title = new char[32];
    BSsprintf(title, 32, "bIAmInDialogue = %s", inDialogue ? "true" : "false");
    out->FUN_0096a610(title);
    title = new char[32];
    BSsprintf(title, 32, "fLastTime = %0.3f", lastTime);
    out->FUN_0096a610(title);
    title = new char[32];
    BSsprintf(title, 32, DAT_01066238, actor);
    out->FUN_0096a610(title);
    if (actor)
    {
        title = new char[32];
        BSsprintf(title, 32, "pActor->iFormID = %08X", actor->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
        out->FUN_0096a610(title);
    }
    title = new char[32];
    BSsprintf(title, 32, "spAnimationData = %08X", animation.Modelloader_GetReferencedThis());
    out->FUN_0096a610(title);
    if (animation.Modelloader_GetReferencedThis())
    {
        for (i = 0; i < 15; i++)
        {
            if (animation.Modelloader_GetReferencedThis()->v25(i) != 3.4028234663852886e+38)
            {
                out->FUN_0096a610(NiGetViewerString_00a7d550(BSFaceGenManager_GetFaceGenExpressionText(i), animation.Modelloader_GetReferencedThis()->v25(i)));
            }
        }
        for (k = 0; k < 17; k++)
        {
            if (animation.Modelloader_GetReferencedThis()->BSFaceGenAnimationData_GetModifierValue(k) != 3.4028234663852886e+38)
            {
                out->FUN_0096a610(NiGetViewerString_00a7d550(BSFaceGenManager_GetFaceGenModifierText(k), animation.Modelloader_GetReferencedThis()->BSFaceGenAnimationData_GetModifierValue(k)));
            }
        }
        for (buffer = 0; buffer < 16; buffer++)
        {
            if (animation.Modelloader_GetReferencedThis()->v29(buffer) != 3.4028234663852886e+38)
            {
                out->FUN_0096a610(NiGetViewerString_00a7d550(BSFaceGenManager_GetFaceGenPhonemeText(buffer), animation.Modelloader_GetReferencedThis()->v29(buffer)));
            }
        }
    }
}

// @fnv 0x00662b00
BSFaceGenNiNode::~BSFaceGenNiNode()
{
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xe8) = 0;
}

struct NiPtr6628
{
    void* m_pObject;
    NiPtr6628(void* p);
    ~NiPtr6628();
    NiPtr6628& operator=(void* p);
};

struct Block6628
{
    int v00;
    int v04;
    int v08;
    int v0C;
    int v10;
    int v14;
    int v18;
    int v1C;
    int v20;
    Block6628();
};

extern Block6628 DAT_011a9448;

namespace fg6628 {
struct FUN_006628c0 : NiNode
{
    FUN_006628c0();
    virtual ~FUN_006628c0();

    NiPtr6628 spAnimationData;
    Block6628 block;
    bool unkD4;
    bool unkD5;
    bool bAnimationUpdate;
    bool unkD7;
    bool bApplyRotationToParent;
    float unkDC;
    bool unkE0;
    bool unkE1;
    bool unkE2;
    int unkE4;
    int unkE8;
    bool unkEC;
};
}

// Constructs the node, initializes spAnimationData, copies DAT_011a9448 into block, and assigns the listed fields.
// @fnv 0x006628c0
fg6628::FUN_006628c0::FUN_006628c0() : NiNode(0), spAnimationData(0)
{
    unkD5 = false;
    unkD4 = false;
    bAnimationUpdate = true;
    unkD7 = true;
    bApplyRotationToParent = false;
    unkDC = -1.0f;
    unkE0 = false;
    unkE1 = false;
    spAnimationData = 0;
    block = DAT_011a9448;
    unkE2 = false;
    unkE8 = 0;
    unkEC = false;
}

struct S_00662e90_Result
{
    virtual void* f00()
    {
        return 0;
    }
    virtual void* f01()
    {
        return 0;
    }
    virtual void* f02()
    {
        return 0;
    }
    virtual void* f03()
    {
        return 0;
    }
    virtual void* f04()
    {
        return 0;
    }
    virtual void* f05()
    {
        return 0;
    }
    virtual void* f06()
    {
        return 0;
    }
    virtual void* f07()
    {
        return 0;
    }
    virtual void* f08()
    {
        return 0;
    }
    virtual void* f09()
    {
        return 0;
    }
    virtual void* f10()
    {
        return 0;
    }
    virtual void* f11()
    {
        return 0;
    }
    virtual void* f12()
    {
        return 0;
    }
    virtual void* f13()
    {
        return 0;
    }
    virtual void* f14()
    {
        return 0;
    }
    virtual void* f15()
    {
        return 0;
    }
    virtual void* f16()
    {
        return 0;
    }
    virtual void* f17()
    {
        return 0;
    }
    virtual void* f18()
    {
        return 0;
    }
    virtual void* f19()
    {
        return 0;
    }
    virtual void* f20()
    {
        return 0;
    }
    virtual void* f21()
    {
        return 0;
    }
    virtual void* f22()
    {
        return 0;
    }
    virtual void* f23()
    {
        return 0;
    }
    virtual void* f24()
    {
        return 0;
    }
    virtual void* f25()
    {
        return 0;
    }
    virtual void* f26()
    {
        return 0;
    }
    virtual void* f27()
    {
        return 0;
    }
    virtual void* f28()
    {
        return 0;
    }
    virtual void* f29()
    {
        return 0;
    }
    virtual void* f30()
    {
        return 0;
    }
    virtual void* f31()
    {
        return 0;
    }
    virtual void* f32()
    {
        return 0;
    }
    virtual void* f33()
    {
        return 0;
    }
    virtual void* f34()
    {
        return 0;
    }
    virtual void* f35()
    {
        return 0;
    }
    virtual void* f36()
    {
        return 0;
    }
    virtual void* f37()
    {
        return 0;
    }
    virtual void* f38()
    {
        return 0;
    }
    virtual void* f39()
    {
        return 0;
    }
    virtual void* f40()
    {
        return 0;
    }
    virtual float f41(int)
    {
        return 0.0f;
    }
};

struct S_00662e90_This
{
    virtual void* f00()
    {
        return 0;
    }
    virtual void* f01()
    {
        return 0;
    }
    virtual void* f02()
    {
        return 0;
    }
    virtual void* f03()
    {
        return 0;
    }
    virtual void* f04()
    {
        return 0;
    }
    virtual void* f05()
    {
        return 0;
    }
    virtual void* f06()
    {
        return 0;
    }
    virtual void* f07()
    {
        return 0;
    }
    virtual void* f08()
    {
        return 0;
    }
    virtual void* f09()
    {
        return 0;
    }
    virtual void* f10()
    {
        return 0;
    }
    virtual void* f11()
    {
        return 0;
    }
    virtual void* f12()
    {
        return 0;
    }
    virtual void* f13()
    {
        return 0;
    }
    virtual void* f14()
    {
        return 0;
    }
    virtual void* f15()
    {
        return 0;
    }
    virtual void* f16()
    {
        return 0;
    }
    virtual void* f17()
    {
        return 0;
    }
    virtual void* f18()
    {
        return 0;
    }
    virtual void* f19()
    {
        return 0;
    }
    virtual void* f20()
    {
        return 0;
    }
    virtual void* f21()
    {
        return 0;
    }
    virtual void* f22()
    {
        return 0;
    }
    virtual void* f23()
    {
        return 0;
    }
    virtual void* f24()
    {
        return 0;
    }
    virtual void* f25()
    {
        return 0;
    }
    virtual void* f26()
    {
        return 0;
    }
    virtual void* f27()
    {
        return 0;
    }
    virtual void* f28()
    {
        return 0;
    }
    virtual void* f29()
    {
        return 0;
    }
    virtual void* f30()
    {
        return 0;
    }
    virtual void* f31()
    {
        return 0;
    }
    virtual void* f32()
    {
        return 0;
    }
    virtual void* f33()
    {
        return 0;
    }
    virtual void* f34()
    {
        return 0;
    }
    virtual void* f35()
    {
        return 0;
    }
    virtual void* f36()
    {
        return 0;
    }
    virtual void* f37()
    {
        return 0;
    }
    virtual void* f38()
    {
        return 0;
    }
    virtual void* f39()
    {
        return 0;
    }
    virtual void* f40()
    {
        return 0;
    }
    virtual void* f41()
    {
        return 0;
    }
    virtual void* f42()
    {
        return 0;
    }
    virtual void* f43()
    {
        return 0;
    }
    virtual void* f44()
    {
        return 0;
    }
    virtual void* f45()
    {
        return 0;
    }
    virtual void* f46()
    {
        return 0;
    }
    virtual void* f47()
    {
        return 0;
    }
    virtual void* f48()
    {
        return 0;
    }
    virtual void* f49()
    {
        return 0;
    }
    virtual void* f50()
    {
        return 0;
    }
    virtual void* f51()
    {
        return 0;
    }
    virtual void* f52()
    {
        return 0;
    }
    virtual void* f53()
    {
        return 0;
    }
    virtual void* f54()
    {
        return 0;
    }
    virtual void* f55()
    {
        return 0;
    }
    virtual void* f56()
    {
        return 0;
    }
    virtual void* f57()
    {
        return 0;
    }
    virtual void* f58()
    {
        return 0;
    }
    virtual void* f59()
    {
        return 0;
    }
    virtual void* f60()
    {
        return 0;
    }
    virtual void* f61()
    {
        return 0;
    }
    virtual void* f62()
    {
        return 0;
    }
    virtual void* f63()
    {
        return 0;
    }
    virtual S_00662e90_Result* f64()
    {
        return 0;
    }
};

struct S_00662e90_Object
{
    void* unk00;
    void* unk04;
};

struct S_00662e90_Callee
{
    void __thiscall ApplyMorph(int, int, void*, int, float);
};

struct S_00662e90_Argument
{
    S_00662e90_Object* unk00;
    void* unk04;
    int unk08;
    int unk0c;
    S_00662e90_Callee* unk10;
    int unk14;
    int unk18;
    unsigned char unk1c;
};

class S_00662e90_Class : public S_00662e90_This
{
  public:
    void __thiscall BSFaceGenNiNode_ApplyFacialPhonemes(S_00662e90_Argument*);
};

// @fnv 0x00662e90
// src: COMMUNITY 0x00662e90
void S_00662e90_Class::BSFaceGenNiNode_ApplyFacialPhonemes(S_00662e90_Argument* pArg)
{
    int i8;
    float value;

    for (i8 = 0; i8 < 16; i8 = i8 + 1)
    {
        value = this->f64()->f41(i8);
        if (value > DAT_01012060 && value >= DAT_01012060 && value <= DAT_01012070)
        {
            if (!pArg->unk1c)
            {
                BSFaceGenUtils_RefreshMeshFromBaseMorphExtraData(pArg->unk00, &pArg->unk04);
                pArg->unk1c = 1;
            }
            pArg->unk10->ApplyMorph(0, i8, pArg->unk00, pArg->unk14, value);
        }
    }
}
