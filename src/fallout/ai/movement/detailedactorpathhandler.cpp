#include "../../../../include/SettingT.h"
#include "../../../../include/Actor.h"
// fallout/ai/movement/detailedactorpathhandler.cpp (73 byte-matched functions)

// Approved-header blockers retained below:
// Actor: ::Actor needs virtual SetTarget(target) at slot 0x2C0;
// MobileObject.h declares this slot as Unk_B0() without arguments.
#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTNewInterface.h"
#include "../../../../include/NiTArray.h"
#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
// In-class bodies of the former NiPoint3_ext stand-in.
inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const
{
    return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const
{
    return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z);
}
inline float NiPoint3::operator*(const NiPoint3& point) const
{
    return x * point.x + y * point.y + z * point.z;
}
inline NiPoint3 operator*(float scalar, const NiPoint3& point)
{
    return NiPoint3(scalar * point.x, scalar * point.y, scalar * point.z);
}
#include "../../../../include/NiPoint3.h"
#include "../../../../include/PathingLocation.h"
#include "../../../../include/NiPoint3.h"

#include "../../../../include/PathingGraphNode.h"
#include "../../../../include/NavMeshTriangle.h"
#include "../../../../include/ProcessLists.h"
#include "../../../../include/BGSTerrainManager.h"
// The shared handler does not declare its ActorAvoidanceData value type yet.
// RTTI 0x01092640 identifies the array below as BSSimpleArray of this 8-byte payload.
struct ActorAvoidanceData
{
    Actor* pActor;
    float fValue;
    ActorAvoidanceData(Actor*, float);
};
#include "../../../../include/ActorMover.h"
#include "../../../../include/ActorPathHandler.h"

#include "../../../../include/CombatState.h"
// The former float CombatState query called Actor::FUN_008be1b0 (0x008be1b0).
#include "../../../../include/Setting.h"
#include "../../../../include/TESPackage.h"

// Animation.h is absent; checked calls 0x00494710 and 0x00495BE0 belong to Animation.
class Animation
{
public:
    bool IsGroupQueued(unsigned short);
    bool IsHighestPriority();
};
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/BSSimpleList.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/ActorValueOwner.h"
#include "../../../../include/AnimIdle.h"
#include "../../../../include/BGSCameraPath.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/BaseFormComponent.h"
#include "../../../../include/CachedValuesOwner.h"
#include "../../../../include/GO.h"
#include "../../../../include/MobileObject.h"
#include "../../../../include/NavMesh.h"
#include "../../../../include/NavMeshStaticAvoidNode.h"
#include "../../../../include/NavMeshClosedDoorInfo.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiTPrimitiveArray.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/BSSimpleArray.h"
#include "../../../../include/BSStringT.h"
#include "../../../../include/PathingRequest.h"
// The approved request header lacks the byte-preserving 0x9F accessor.
// Keep only that declaration on a layout-free extension of the shared class.
struct PathingRequestQueries : PathingRequest
{
    unsigned char GetByteAtOffset9F();
};
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/TES.h"
#include "../../../../include/TESChildCell.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/bhkCharacterController.h"


#pragma pack(push, 4)
#include "../../../../include/DetailedActorPathHandler.h"
#include "../../../../include/PathingSolution.h"
#pragma pack(pop)

// @fnv 0x009e0930
bool DetailedActorPathHandler::TurnToAngle(float angle, bool keepActorHeading)
{
    m_bPathFlag5 = false;
    eState = 5;
    m_iPathParameter1 = 3;
    m_iPathParameter2 = 1;
    m_fPathValue5 = 0.0f;
    m_fPathValue16 = 0.0f;
    m_fPathValue2 = 0.0f;
    (NiPointer<PathingSolution>&)pCurrentPathingSolution = (PathingSolution*)0;
    (NiPointer<PathingRequest>&)m_pPathingRequest = (PathingRequest*)0;
    m_bHasPathingSolution = false;
    m_bPathingRequestPending = false;
    m_fElapsedTime = 0.0f;

    if (StartTurningToAngle(angle, keepActorHeading, false))
    {
        eState = 6;
        return true;
    }

    eState = 5;
    return false;
}

// @fnv 0x009e39c0
void DetailedActorPathHandler::SetInitialPathState()
{
    m_kPathVector1 = NiPoint3::ZERO;
    ByteAndFlagState = m_pActorMover->GetPreferredMoveModeType();
    m_fPathValue16 = 0.0f;
    (NiPointer<PathingSolution>&)pCurrentPathingSolution = (PathingSolution*)0;
    (NiPointer<PathingRequest>&)m_pPathingRequest = (PathingRequest*)0;
    m_bPathFlag5 = false;
    m_iPathValue2 = 0;
    m_pPathTargetReference = 0;
    m_iPathParameter2 = 1;
    ActorAvoidEntryList.RemoveAll();
    eState = 5;
}

// Copies path state fields from a previous DetailedActorPathHandler when it can transition, remapping state 3 to 4 and moving its list items.
// @fnv 0x009e3380
void DetailedActorPathHandler::TransitionFrom(ActorPathHandler* previous)
{
    if (!previous || !previous->vfn_34())
        return;

    DetailedActorPathHandler* oldPath = (DetailedActorPathHandler*)previous;
    ByteAndFlagState = oldPath->ByteAndFlagState;
    m_iPathParameter1 = oldPath->m_iPathParameter1;
    m_fPathValue10 = oldPath->m_fPathValue10;
    m_fPathValue9 = oldPath->m_fPathValue9;
    m_fPathValue5 = oldPath->m_fPathValue5;

    if (oldPath->m_iPathParameter2 == 2)
    {
        m_iPathParameter2 = 2;
        m_fPathValue4 = oldPath->m_fPathValue4;
        m_fPathValue12 = oldPath->m_fPathValue12;
    }
    else if (oldPath->m_iPathParameter2 == 3)
    {
        m_iPathParameter2 = 4;
        m_fPathValue4 = oldPath->m_fPathValue4;
        m_fPathValue12 = 0.0f;
        while (oldPath->ActorAvoidEntryList.GetItem())
        {
            ActorAvoidEntryList.AddHead(oldPath->ActorAvoidEntryList.GetItem());
            oldPath->ActorAvoidEntryList.RemoveHead();
        }
    }

    m_bPathFlag6 = oldPath->m_bPathFlag6;
    m_fPathValue17 = oldPath->m_fPathValue17;
    if (oldPath->m_bPathFlag5)
    {
        m_bPathFlag5 = true;
        m_kPathVector4 = oldPath->m_kPathVector4;
        m_kPathVector3 = oldPath->m_kPathVector3;
    }
}

// @fnv 0x009e03e0
DetailedActorPathHandler::~DetailedActorPathHandler()
{
    (NiPointer<PathingSolution>&)pCurrentPathingSolution = (PathingSolution*)0;
    (NiPointer<PathingRequest>&)m_pPathingRequest = (PathingRequest*)0;
    ActorAvoidEntryList.RemoveAll();
}

void __cdecl NiSinCosQ(float, float*, float*);

// 0x009e1640 builds a Z rotation like NiMatrix3::MakeZRotation (0x004a0c90) but through the game's own sin/cos
// (0x00639730): a game helper, not the Gamebryo inline.
struct FUN_009e1640_ZRotation : public NiMatrix3
{
    void SetRotationMatrix(float afAngle);
};

// NiMatrix3::operator*(const NiPoint3&) const (0x004b4500) seen through this unit's NiPoint3.
struct FUN_004b4500_ExtView : public NiMatrix3
{
    NiPoint3 operator*(const NiPoint3& point) const;
};

// Computes sin/cos of the angle and writes a 3x3 rotation matrix into the object's first nine floats.
// @fnv 0x009e1640
void FUN_009e1640_ZRotation::SetRotationMatrix(float afAngle)
{
    float fSin;
    float fCos;
    NiSinCosQ(afAngle, &fSin, &fCos);

    m_pEntry[0][0] = fCos;
    m_pEntry[0][1] = fSin;
    m_pEntry[0][2] = 0.0f;
    m_pEntry[1][0] = -fSin;
    m_pEntry[1][1] = fCos;
    m_pEntry[1][2] = 0.0f;
    m_pEntry[2][0] = 0.0f;
    m_pEntry[2][1] = 0.0f;
    m_pEntry[2][2] = 1.0f;
}

namespace fnv_009e27e0 {
struct FUN_009e27e0_shell : public DetailedActorPathHandler
{
    bool DetailedActorPathHandler_ComputeMinTetherDistance();
};


extern double DAT_01011588;

// @fnv 0x009e27e0
// src: XBOX_PDB 0x009e27e0
bool FUN_009e27e0_shell::DetailedActorPathHandler_ComputeMinTetherDistance()
{
    *(float*)((char*)this + 0x14) = 10.0f;
    *(float*)((char*)this + 0x18) = 20.0f;
    *(float*)((char*)this + 0x18) =
        ((PathingRequest*)(const char*)(*(BSStringT<char>*)((char*)this + 0x10)))->GetFloatAtOffset68();
    *(float*)((char*)this + 0x14) = *(float*)((char*)this + 0x18) * DAT_01011588;
    return false;
}
}  // namespace fnv_009e27e0

// @fnv 0x009e32d0
int __fastcall GetField38(char* this_ptr)
{
    return *(int*)(this_ptr + 0x38);
}

// If the flag at offset 0xe2 is set, clears it, writes the vector at offset 0x1c to aDelta and returns true; otherwise writes NiPoint3::ZERO and returns false.
// @fnv 0x009e32f0
bool DetailedActorPathHandler::GetPathingDelta(NiPoint3* aDelta)
{
    if (*((bool*)this + 0xe2))
    {
        *((bool*)this + 0xe2) = false;
        *aDelta = *(NiPoint3*)((char*)this + 0x1c);
        return true;
    }
    else
    {
        *aDelta = NiPoint3::ZERO;
        return false;
    }
}

// Actor.h has no declaration for this query yet.
struct ActorLookAtQuery : public Actor
{
    bool GetLookAtPosition(void*);
};
struct S_009e3520
{
    int pad0;
    ActorLookAtQuery* pActor;
    char pad1[0x14];
    float a;
    float speed;
    void UpdateSpeed(float scale);
};
// @fnv 0x009e3520
void S_009e3520::UpdateSpeed(float scale)
{
    if (!pActor->GetLookAtPosition(&a))
        speed = pActor->GetCurrentMovementSpeed() * scale;
}

struct FUN_009e5480_shell : public DetailedActorPathHandler
{
    void ResetPathState();
};

// Clears the flag at offset 0xde and sets the float at offset 0x88 to 0.0f.
// @fnv 0x009e5480
void FUN_009e5480_shell::ResetPathState()
{
    *((bool*)this + 0xde) = false;
    *(float*)((char*)this + 0x88) = 0.0f;
}

struct ActiveEffect;
struct ActorCause;
struct AlchemyItem;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSImpactDataSet;
struct BGSLoadGameBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
class BSSoundHandle;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CellMopp;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;

struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;

struct Projectile;
struct QueuedFile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WaterZone;
struct WeaponObject;

struct bhkNiCollisionObject;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;

extern int* DAT_011a3ff0[];

struct Sky;


struct FakeProcess
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
    virtual TESObjectREFR* GetActorTargetReference();  // 74 * 4 = 0x128
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual TESPackage* GetCurrentPackage();  // 159 * 4 = 0x27c
    virtual int GetPackageState();          // 160 * 4 = 0x280
};


// Resolves the current process's package; if its type is 6 and the target reference is an actor, returns that actor as the follow leader, otherwise null.
// @fnv 0x009e55e0
// src: XBOX_PDB 0x009e55e0
Actor* __cdecl DetailedActorPathHandler_GetFollowLeader(TES* apActor)
{
    FakeProcess* pprocess;
    Actor* pfollowLeader = 0;
    pprocess = (FakeProcess*)apActor->GetLogDate();
    if (pprocess)
    {
        TESPackage* ppack = pprocess->GetCurrentPackage();
        if (ppack)
        {
            int iPackageType = DAT_011a3ff0[ppack->GetProcedureType()][pprocess->GetPackageState()];
            if (iPackageType == 6)
            {
                TESObjectREFR* ptarget = pprocess->GetActorTargetReference();
                if (ptarget && ptarget->IsActor())
                {
                    pfollowLeader = (Actor*)ptarget;
                }
            }
        }
    }
    return pfollowLeader;
}

struct FUN_009e7610_shell : public DetailedActorPathHandler
{
    bool TurnTowardGoalAngle(float, bool, bool);
};

float __cdecl fmod(float, float);
float __cdecl GetAngleDelta(float, float, float*);
void __cdecl WrapValueToRange(float&, float, float);
bool __fastcall GetTurretBehavior(void*);

namespace std {
float __cdecl abs(float);
}

class Date
{
  public:
    ~Date();
};

union SETTING_VALUE;
class GameSettingCollection;
using ::SettingT;

extern double _gModifierZero;
extern float DAT_010923dc;
extern float DAT_010923e0;
extern float DAT_010923e4;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting220;

struct VCallHelper_2bc
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual void d131();
    virtual void d132();
    virtual void d133();
    virtual void d134();
    virtual void d135();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual void d139();
    virtual void d140();
    virtual void d141();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void d146();
    virtual void d147();
    virtual void d148();
    virtual void d149();
    virtual void d150();
    virtual void d151();
    virtual void d152();
    virtual void d153();
    virtual void d154();
    virtual void d155();
    virtual void d156();
    virtual void d157();
    virtual void d158();
    virtual void d159();
    virtual void d160();
    virtual void d161();
    virtual void d162();
    virtual void d163();
    virtual void d164();
    virtual void d165();
    virtual void d166();
    virtual void d167();
    virtual void d168();
    virtual void d169();
    virtual void d170();
    virtual void d171();
    virtual void d172();
    virtual void d173();
    virtual void d174();
    virtual float v175(int);
};

// @fnv 0x009e7610
bool FUN_009e7610_shell::TurnTowardGoalAngle(float afGoalAngle, bool abForceTurn, bool abPathTransition)
{
    float fdir;
    float fabsoluteDelta;
    float fangledelta;
    float fepsilon;

    if (*reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0xc0))
        return false;

    if (afGoalAngle < _gModifierZero)
        afGoalAngle = fmod(float(afGoalAngle + 6.2831854820251465), 6.2831854820251465f);
    else if (afGoalAngle >= 6.2831854820251465)
        afGoalAngle = fmod(afGoalAngle, 6.2831854820251465f);

    fangledelta = GetAngleDelta((*reinterpret_cast<VCallHelper_2bc**>(reinterpret_cast<char*>(this) + 4))->v175(0),
                               afGoalAngle, &fdir);
    fabsoluteDelta = std::abs(fangledelta);
    fepsilon = DAT_010923dc;

    if (abForceTurn)
    {
        fepsilon = DAT_010923e4;
    }
    else if (abPathTransition &&
             ((*reinterpret_cast<ActorMover**>(reinterpret_cast<char*>(this) + 8))->GetPreferredMoveModeType() & 0x200))
    {
        fepsilon = DAT_010923e0;
    }

    if (fabsoluteDelta > fepsilon)
    {
        if (fdir > _gModifierZero)
            *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0xdd) = true;
        else
            *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0xdd) = false;

        *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0xdc) = true;
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x68) = afGoalAngle;
        WrapValueToRange(*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x68), -3.1415927410125732f,
                         3.1415927410125732f);

        if (!GetTurretBehavior(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 4)))
            *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x94) =
                *reinterpret_cast<float*>(originalRuntimeFloatSetting220.Float());

        (*reinterpret_cast<Date**>(reinterpret_cast<char*>(this) + 8))->Date::~Date();
        return true;
    }

    return false;
}

struct FUN_009e8790_shell : public DetailedActorPathHandler
{
    void ResetMoveState();
};

// Stores the mover's preferred move mode type at offset 0x60 and resets the vectors at 0x1c and 0xa0 and the float at 0x9c to zero.
// @fnv 0x009e8790
void FUN_009e8790_shell::ResetMoveState()
{
    *(unsigned int*)((char*)this + 0x60) = (*(ActorMover**)((char*)this + 0x8))->GetPreferredMoveModeType();
    *(NiPoint3*)((char*)this + 0x1c) = NiPoint3::ZERO;
    *(float*)((char*)this + 0x9c) = 0.0f;
    *(NiPoint3*)((char*)this + 0xa0) = NiPoint3::ZERO;
}

class ActiveEffect;
class AlchemyItem;
struct BGSEncounterZone;
class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
class BSAnimNoteReceiver;
class BSExtraData;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSMultiBound;
class BSMultiBoundRoom;
class BSSoundHandle;
class BaseProcess;
class CellMopp;
class EffectItem;
class ExtraDataList;
class ExtraLock;
class FormRecordHeader;
class FurnitureMark;
class HWND__;
struct InventoryChanges;
class InventoryStackRecord;
class MagicCaster;
class MagicItem;
class MagicProjectile;
class MagicTarget;
class NiAVObject;
class NiColor;
class NiControllerManager;
class NiControllerSequence;
class NiFixedString;
class NiGeometry;
class NiLight;
class NiNode;
class NiPointLight;
class NiQuaternion;
class PlacedObjectInfo;
class Script;
class ScriptLocals;
class SpellItem;
class TESActorBase;
class TESAmmo;
class TESBoundObject;
class TESContainer;
class TESFile;
class TESForm;
class TESGlobal;
class TESIdleForm;
class TESModel;
class TESObjectARMO;
class TESObjectCELL;
class TESObjectCLOT;
class TESObjectLIGH;
class TESObjectWEAP;
class TESPackage;
class TESSound;
class TESTopic;
class TESTopicInfo;
class TESWorldSpace;
class TargetEntry;
class bhkNiCollisionObject;
class hkVector4;
class hkpRigidBody;
namespace fnv_009e9390 {
struct ActorCause;
struct TwoIntegerValues;
struct MediaLocation;
struct ExplosionForm;
struct SaveLoadFile;
struct BipedAnim;
struct CHUNK;
struct GameFormRecord;
struct DialogueResponse;
struct TeleportableReference;
struct TESFileGroup;
struct BooleanIntegerAccessor;
struct CellDataNode;
struct MagicEffectCollection;
struct MapMarkerData;

struct Point3Offset;
struct AnimationInterpolator;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct TrapEntry;
struct WaterZone;

struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];

typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];
struct FUN_009e9390_shell : public DetailedActorPathHandler
{
    void DetailedActorPathHandler_LoadGame(BGSLoadFormBuffer*);
};


// @fnv 0x009e9390
// src: XBOX_PDB 0x009e9390
void FUN_009e9390_shell::DetailedActorPathHandler_LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData((char*)this + 0x1c, 0xc);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x28, 0xc);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x34, 0xc);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x40, 0xc);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x4c, 0xc);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x60, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x64, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x68, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x6c, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x70, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x74, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x78, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x7c, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x80, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x84, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x88, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x8c, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x90, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x94, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x98, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x9c, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xac, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xb0, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xb4, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xb8, 4);
    if (apLoadGameBuffer->GetVersion() >= 4)
    {
        apLoadGameBuffer->ReadTypedData((char*)this + 0x14, 4);
        apLoadGameBuffer->ReadTypedData((char*)this + 0x18, 4);
    }
    apLoadGameBuffer->ReadTypedData((char*)this + 0xc8, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xcc, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xd0, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xd4, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xdc, 1);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xdd, 1);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xde, 1);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xdf, 1);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xe0, 1);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xe2, 1);
    apLoadGameBuffer->ReadTypedData((char*)this + 0xe1, 1);
    if (apLoadGameBuffer->GetVersion() >= 0xc)
    {
        apLoadGameBuffer->ReadTypedData((char*)this + 0xc0, 1);
        apLoadGameBuffer->ReadTypedData((char*)this + 0xc1, 1);
        apLoadGameBuffer->ReadTypedData((char*)this + 0xc4, 4);
    }
    if (apLoadGameBuffer->GetVersion() >= 0x12)
    {
        apLoadGameBuffer->ReadTypedData((char*)this + 0xa0, 0xc);
        apLoadGameBuffer->ReadTypedData((char*)this + 0xbc, 4);
    }
    apLoadGameBuffer->ReadFormIdentifier((char*)this + 0xd8);
    unsigned int uiFormCount = apLoadGameBuffer->ReadElementCount();
    for (unsigned int uiIndex = 0; uiIndex < uiFormCount; ++uiIndex)
    {
        const char* pForm = 0;
        apLoadGameBuffer->ReadFormIdentifier(&pForm);
        ((BSSimpleList<const char*>*)((char*)this + 0x58))->AddHead(pForm);
    }
}
}  // namespace fnv_009e9390

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_009e0160(unsigned int flags);
};
// Runs the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x009e0160
void* DelStandIn::FUN_009e0160(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace fnv_009e0470 {
float __cdecl BSMAX_00404010(float, float);
float __cdecl GetDirectionAngle(const NiPoint3&);
extern float DAT_01092470;
extern const float g_011e0994_arg1;
extern double DAT_0107d1b8;
extern double _gModifierZero;

namespace std {
float __cdecl abs(float);
}


// 0x009E0470 uses the shared handler layout; only these missing method declarations remain local.
struct PathTravelUpdate : public DetailedActorPathHandler
{
    void ResetMoveState();
    void DetailedActorPathHandler_ComputeMinTetherDistance();
    void UpdatePathTether(float afPercentTraveled);
    int UpdatePathingGoal();
    int UpdatePathTravel(float afPercentTraveled, float afDeltaT);
};

// Resets path-travel state, computes the goal angle from the actor's position and pathing solution, and updates the handler when afDeltaT is positive.
// @fnv 0x009e0470
int PathTravelUpdate::UpdatePathTravel(float afPercentTraveled, float afDeltaT)
{
    eState = 1;
    if (m_iPathParameter1 == 0)
        m_iPathParameter1 = 3;
    switch (m_iPathParameter2)
    {
    case 2:
    case 4:
        break;
    default:
        m_iPathParameter2 = 1;
        m_fPathValue4 = 0.0f;
        m_fPathValue12 = 0.0f;
    }
    m_kPathVector1 = NiPoint3::ZERO;
    m_bPathFlag1 = false;
    m_bPathFlag7 = false;
    m_bPathFlag3 = false;
    m_fPathValue8 = 0.0f;
    m_iPathValue1 = 0;
    m_fPathValue6 = 0.0f;
    m_fPathValue7 = 0.0f;
    m_fPathValue13 = 0.0f;
    m_kPathVector5 = NiPoint3::ZERO;
    m_kActorPosition = *((const Actor*)pActor)->GetPos();
    m_fPathValue15 = 0.0f;
    m_fPathValue11 = -1.0f;

    if (((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetObjectFlags() < 2)
    {
        ResetMoveState();
        m_bPathFlag5 = false;
        m_kPathVector3 = *((const Actor*)pActor)->GetPos();
        m_kPathVector4 = m_kPathVector3;
        eState = 5;
        return 5;
    }

    if (((NiPointer<PathingSolution>&)pCurrentPathingSolution)->IsIncomplete())
    {
        m_fPathValue14 = g_011e0994_arg1;
    }
    else
    {
        m_fPathValue14 = BSMAX_00404010(((NiPointer<PathingRequest>&)m_pPathingRequest)->GetCenterRadius() *
                                          ((NiPointer<PathingRequest>&)m_pPathingRequest)->GetCenterRadius(),
                                      0.1f);
        if (((PathingGraphNode*)((NiPointer<PathingSolution>&)pCurrentPathingSolution)->PathingSolution_GetLastNode())->PathingNode_IsTeleportDoorNode())
            m_fPathValue14 = DAT_01092470;
    }
    if (((PathingGraphNode*)((NiPointer<PathingSolution>&)pCurrentPathingSolution)->PathingSolution_GetLastNode())->IsTransitionNode())
        m_bPathFlag4 = true;

    DetailedActorPathHandler_ComputeMinTetherDistance();
    bool bpathTransition = m_bPathFlag5;
    UpdatePathTether(afPercentTraveled);
    m_bHasPathingSolution = false;
    m_bPathingRequestPending = false;
    m_fElapsedTime = 0.0f;
    if (!((Actor*)pActor)->HasCombatState() &&
        ((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetTotalPathLength() <
            *(float*)((char*)this + 0x18) &&
        !((ActorMover*)m_pActorMover)->HasLookAtTarget())
    {
        m_bHasPathingSolution = true;
        m_bPathingRequestPending = true;
        m_fElapsedTime = (float)((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetObjectFlags();
    }

    if (!UpdatePathingGoal())
    {
        float fgoalAngle;
        NiPoint3 dirVec;
        if (m_bPathFlag6 || !((ActorMover*)m_pActorMover)->GetLookAtTargetPosition((NiPoint3&)dirVec))
            (NiPoint3&)dirVec = m_kPathVector3;
        dirVec.Subtract(*((const Actor*)pActor)->GetPos());
        if (dirVec.Length() * DAT_0107d1b8 <= std::abs(dirVec.z))
            fgoalAngle = ((Actor*)pActor)->GetCurrentTargetDistance(false);
        else
            fgoalAngle = GetDirectionAngle(dirVec);
        if (!bpathTransition)
        {
            if (afPercentTraveled == _gModifierZero)
                StartTurningToAngle(fgoalAngle, false, bpathTransition);
            else
                ((Actor*)pActor)->SetFurnitureHeading(fgoalAngle);
        }
    }

    eState = 2;
    if (afDeltaT > _gModifierZero)
        return ((ActorPathHandler*)this)->vfn_0c(afDeltaT);
    return 0;
}
}  // namespace fnv_009e0470

namespace fnv_009e16e0 {
struct FUN_009e16e0_shell : public DetailedActorPathHandler
{
    int DetailedActorPathHandler_NoPathUpdate(float);
};


struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct GlobalObject_0041a250
{
    ~GlobalObject_0041a250();
};
namespace p07 {

float __cdecl GetDirectionAngle(const NiPoint3&);
}


struct FUN_009e8790_shell
{
    void ResetMoveState();
};
struct FUN_009e4c60_shell
{
    void UpdateLookingAngle(float, float);
};
struct FUN_009e7d70_shell
{
    float DetailedActorPathHandler_UpdateRotation(float);
};

namespace std {
float __cdecl abs(float);
}
float __cdecl WrapAngle(float);
struct FUN_005f0c80_shell
{
    bool IsImmobile();
};
bool __fastcall GetByteAtOffset70(void*);
bool __fastcall CombatState_GetHasTarget360LineOfSight(CombatState*);
NiPoint3 __cdecl CombatUtilities_GetAttackerFiringLocation(Actor*);
NiPoint3 __cdecl CombatUtilities_GetAngleToProjectedPoint(Actor*, NiPoint3);
extern double g_d100;
bool __fastcall GetTurretBehavior(void*);
float __cdecl GetAngleDelta(float, float, float*);
extern double _gModifierZero;
extern float DAT_010923dc;
extern Setting originalRuntimeFloatSetting220;
extern const double DAT_01023128;
extern double DAT_01092478;
extern Setting g_011f2ac4;
extern Setting g_011f2ad8;
extern Setting g_011f2b10;
extern Setting g_011f2c10;

// Runs the actor path handler's state machine, turning the actor toward its look-at target and updating move mode and timers.
// @fnv 0x009e16e0
// src: XBOX_PDB 0x009e16e0
int FUN_009e16e0_shell::DetailedActorPathHandler_NoPathUpdate(float afDeltaT)
{
    int eresult = -1;
    bool bimmobile = ((FUN_005f0c80_shell*)((Actor*)*(Actor**)((char*)this + 4))->GetActorBase())->IsImmobile();
    if (!fnv_009e16e0::GetTurretBehavior(*(Actor**)((char*)this + 4)) && !GetByteAtOffset70(*(void**)((char*)this + 8)) &&
        !CombatState_GetHasTarget360LineOfSight(*(CombatState**)((char*)this + 8)))
    {
        switch (*(unsigned int*)((char*)this + 0xc8))
        {
        case 3:
            ((ActorPathHandler*)this)->vfn_0c(afDeltaT);
            eresult = 0;
            break;
        case 7:
            ((FUN_009e8790_shell*)this)->ResetMoveState();
            *(unsigned int*)((char*)this + 0xc8) = 5;
            eresult = 5;
            break;
        case 6:
            (*(Actor**)((char*)this + 4))->SetFurnitureHeading(((FUN_009e7d70_shell*)this)->DetailedActorPathHandler_UpdateRotation(afDeltaT));
            *(NiPoint3*)((char*)this + 0x1c) = NiPoint3::ZERO;
            *(float*)((char*)this + 0x9c) = 0.0f;
            *(NiPoint3*)((char*)this + 0xa0) = NiPoint3::ZERO;
            *((char*)this + 0xe2) = 1;
            (*(GlobalObject_0041a250**)((char*)this + 8))->GlobalObject_0041a250::~GlobalObject_0041a250();
            if (!*((bool*)this + 0xdc))
                *(unsigned int*)((char*)this + 0xc8) = 7;
            eresult = 0;
            break;
        case 5:
            *(NP_0081c630*)((char*)this + 0xc) = 0;
            *(NP_0081c630*)((char*)this + 0x10) = 0;
        case 0:
        case 4:
            if (!(*(ActorMover**)((char*)this + 8))->HasLookAtTarget())
            {
                *(unsigned int*)((char*)this + 0x60) = (*(ActorMover**)((char*)this + 8))->GetPreferredMoveModeType();
                eresult = 5;
            }
            break;
        }
    }
    float flookingAngle = 0.0f;
    if (eresult == -1)
    {
        if (*((bool*)this + 0xe1))
        {
            *(float*)((char*)this + 0xb8) -= afDeltaT;
            if (*(float*)((char*)this + 0xb8) < _gModifierZero)
            {
                *((bool*)this + 0xe1) = false;
                eresult = 0;
            }
        }
        if (eresult == -1)
        {
            NiPoint3 lookatPoint;
            if ((*(ActorMover**)((char*)this + 8))->GetLookAtTargetPosition((NiPoint3&)lookatPoint) &&
                !((MobileObject*)*(Actor**)((char*)this + 4))->IsInDialogueWithPlayer())
            {
                float fCurrentAngle = WrapAngle((*(Actor**)((char*)this + 4))->GetCurrentTargetDistance(0));
                NiPoint3 firingLocation = CombatUtilities_GetAttackerFiringLocation(*(Actor**)((char*)this + 4));
                if (((NiPoint3*)&(firingLocation - lookatPoint))->GetSquaredXYLength() <
                    (*(Actor**)((char*)this + 4))->FUN_008be1b0() *
                        (*(Actor**)((char*)this + 4))->FUN_008be1b0() * 0.25)
                    eresult = 0;
                if (eresult == -1)
                {
                    float fdir;
                    NiPoint3 rot = CombatUtilities_GetAngleToProjectedPoint(*(Actor**)((char*)this + 4), lookatPoint);
                    float fgoalAngle = WrapAngle(rot.z);
                    float fgoalLookAngle = rot.x;
                    float fangleDelta;
                    if ((*(Actor**)((char*)this + 4))->FUN_008be1b0() >= g_d100)
                    {
                        NiPoint3 delta = lookatPoint - *((const Actor*)*(Actor**)((char*)this + 4))->GetPos();
                        delta.z = 0.0f;
                        fangleDelta = std::abs(GetAngleDelta(fCurrentAngle, p07::GetDirectionAngle((const NiPoint3&)delta), &fdir));
                    }
                    else
                    {
                        fangleDelta = std::abs(GetAngleDelta(fCurrentAngle, fgoalAngle, &fdir));
                    }
                    float frotateMax = (*(Actor**)((char*)this + 4))->GetMaxRotationSpeed() * DAT_01023128 * afDeltaT;
                    if (!(*(Actor**)((char*)this + 4))->IsCreature())
                        frotateMax *= ((Actor*)*(Actor**)((char*)this + 4))->HasCombatState() ? *g_011f2ac4.Float()
                                                                                                : *g_011f2ad8.Float();
                    else
                        frotateMax *= ((Actor*)*(Actor**)((char*)this + 4))->HasCombatState() ? *g_011f2b10.Float()
                                                                                                : *g_011f2c10.Float();
                    float fclampedAngleDelta = fangleDelta;
                    if (fclampedAngleDelta > frotateMax)
                        fclampedAngleDelta = frotateMax;
                    unsigned int inewMoveMode = *(unsigned int*)((char*)this + 0x60);
                    if (!bimmobile && *(float*)((char*)this + 0x94) > _gModifierZero)
                    {
                        *(float*)((char*)this + 0x94) -= afDeltaT;
                        fCurrentAngle += fclampedAngleDelta * fdir;
                    }
                    else if (fangleDelta > DAT_010923dc)
                    {
                        if (!bimmobile)
                            *(float*)((char*)this + 0x94) = *originalRuntimeFloatSetting220.Float() - afDeltaT;
                        if (fdir == 1.0)
                        {
                            inewMoveMode = (*(ActorMover**)((char*)this + 8))->GetPreferredMoveModeType() | 0x20;
                            fCurrentAngle += fclampedAngleDelta;
                        }
                        else if (fdir == -1.0)
                        {
                            inewMoveMode = (*(ActorMover**)((char*)this + 8))->GetPreferredMoveModeType() | 0x10;
                            fCurrentAngle -= fclampedAngleDelta;
                        }
                    }
                    else
                    {
                        inewMoveMode = (*(ActorMover**)((char*)this + 8))->GetPreferredMoveModeType();
                        fCurrentAngle += fclampedAngleDelta * fdir;
                    }
                    if (!CombatState_GetHasTarget360LineOfSight(*(CombatState**)((char*)this + 8)))
                        *(unsigned int*)((char*)this + 0x60) = inewMoveMode;
                    if (!bimmobile || std::abs(fgoalLookAngle) <= DAT_01092478)
                        (*(Actor**)((char*)this + 4))->SetFurnitureHeading(fCurrentAngle);
                    flookingAngle = fgoalLookAngle;
                    if (bimmobile)
                        ((FUN_009e4c60_shell*)this)->UpdateLookingAngle(afDeltaT, flookingAngle);
                    (*(GlobalObject_0041a250**)((char*)this + 8))->GlobalObject_0041a250::~GlobalObject_0041a250();
                }
            }
        }
        eresult = 0;
    }
    if (!bimmobile)
        ((FUN_009e4c60_shell*)this)->UpdateLookingAngle(afDeltaT, flookingAngle);
    return eresult;
}
}  // namespace fnv_009e16e0

namespace fnv_009e2aa0 {


class DetailedActorMover
{
  public:
    virtual void Vfn000();
    virtual void Vfn001();
    virtual void Vfn002();
    virtual void Vfn003();
    virtual void Vfn004();
    virtual void Vfn005();
    virtual void Vfn006();
    virtual unsigned int GetMovementFlags();
    bool HasLookAtTarget();
    bool GetLookAtTargetPosition(NiPoint3& kPoint);
};

class PathingRequestPath
{
  public:
    void GetLocationAtSplineParameter(float fDistance, NiPoint3& kPoint);
};

class PathingRequestPtr
{
  public:
    operator PathingRequestPath*() const;
};


namespace std {
float abs(float f);
}
double _fabs(double d);
float __cdecl WrapAngle(float fAngleDifference);
float __cdecl GetAngleDelta(float, float, float*);
float __cdecl GetDirectionAngle(const NiPoint3& kPt);
NiPoint3 __cdecl GetPitchYaw(NiPoint3 kFrom, NiPoint3 kTo);

struct FUN_009e2aa0_shell
{
    bool DetailedActorPathHandler_ComputeMoveMode(float fTimeDelta);
};

// Updates the actor's movement flags from look-at/pathing heading, animation state and a timed state machine, writing them to offset 0x60 and returning true.
// @fnv 0x009e2aa0
// src: XBOX_PDB 0x009e2aa0
bool FUN_009e2aa0_shell::DetailedActorPathHandler_ComputeMoveMode(float fTimeDelta)
{
    unsigned int uiMoveMode3;
    unsigned int uiMoveFlags3;
    unsigned int uiOldFlagsVal;

    if ((*(Actor**)((char*)this + 4))->Actor_IsRestrained() || (*(Actor**)((char*)this + 4))->Actor_IsUnConscious())
    {
        *(unsigned int*)((char*)this + 0x60) = 0;
        return true;
    }
    uiOldFlagsVal = *(unsigned int*)((char*)this + 0x60);
    if (*(bool*)((char*)this + 0xe1))
    {
        *(float*)((char*)this + 0xb8) -= fTimeDelta;
        if (*(float*)((char*)this + 0xb8) < 0.0)
        {
            *(bool*)((char*)this + 0xe1) = false;
            *(float*)((char*)this + 0x8c) = 1.0f;
        }
    }
    uiMoveMode3 = (*(ActorMover**)((char*)this + 8))->GetPreferredMoveModeType();
    uiMoveFlags3 = *(unsigned int*)((char*)this + 0x60) & 0x3f;
    if ((*(Actor**)((char*)this + 4))->IsSwimming_005a2030() && (*(Actor**)((char*)this + 4))->IsCreature())
    {
        *(unsigned int*)((char*)this + 0x60) = uiMoveMode3 | 1;
        return true;
    }
    if (!*(bool*)((char*)this + 0xe1) &&
        ((*(DetailedActorMover**)((char*)this + 8))->HasLookAtTarget() || *(bool*)((char*)this + 0xc0)))
    {
        NiPoint3 kPoint;
        float fDesiredHeading;
        float fDesiredHeading_2;
        float fDesiredHeadingAngle;
        float fDirection;
        if ((*(DetailedActorMover**)((char*)this + 8))->HasLookAtTarget())
        {
            (*(DetailedActorMover**)((char*)this + 8))->GetLookAtTargetPosition(kPoint);
            kPoint.Subtract(*(const NiPoint3*)((const MobileObject*)*(Actor**)((char*)this + 4))->GetPos());
            fDesiredHeading_2 = GetDirectionAngle(kPoint);
        }
        else if (*(bool*)((char*)this + 0xc1))
        {
            static_cast<NiPoint3&>(kPoint) = NiPoint3::ZERO;
            fDesiredHeading_2 = (*(Actor**)((char*)this + 4))->GetCurrentTargetDistance(false);
        }
        else if (*(PathingRequestPtr*)((char*)this + 0xc))
        {
            ((PathingRequestPath*)*(PathingRequestPtr*)((char*)this + 0xc))
                ->GetLocationAtSplineParameter(*(float*)((char*)this + 0xc4), kPoint);
            kPoint.Subtract(*(const NiPoint3*)((const MobileObject*)*(Actor**)((char*)this + 4))->GetPos());
            fDesiredHeading_2 = GetDirectionAngle(kPoint);
        }
        else
        {
            static_cast<NiPoint3&>(kPoint) = NiPoint3::ZERO;
            fDesiredHeading_2 = (*(Actor**)((char*)this + 4))->GetCurrentTargetDistance(false);
        }
        NiPoint3 kAngles = GetPitchYaw(*(const NiPoint3*)((const MobileObject*)*(Actor**)((char*)this + 4))->GetPos(), *(NiPoint3*)((char*)this + 0x34));
        if ((*(Actor**)((char*)this + 4))->IsSwimming_005a2030() &&
            _fabs(std::abs(kAngles.x) - 1.5707963267948966) < 0.2617993950843811)
            fDesiredHeadingAngle = fDesiredHeading_2;
        else
            fDesiredHeadingAngle = kAngles.z;
        fDirection = 1.0f;
        fDesiredHeadingAngle = WrapAngle(fDesiredHeadingAngle);
        fDesiredHeading = GetAngleDelta(fDesiredHeadingAngle, fDesiredHeading_2, &fDirection);
        if (*(float*)((char*)this + 0x8c) > 0.25)
        {
            if (std::abs(fDesiredHeading) > 0.01745329238474369)
            {
                float fDegrees2 = fDesiredHeading * 57.2957763671875;
                if (std::abs(fDegrees2) > 135.0 && ((Animation*)(*(Actor**)((char*)this + 4))->GetAnimData())->IsGroupQueued(4) &&
                    (_fabs(std::abs(kAngles.x) - 1.5707963267948966) >= 0.2617993950843811 ||
                     !(*(Actor**)((char*)this + 4))->IsSwimming_005a2030()))
                {
                    uiMoveFlags3 = 2;
                }
                else if (std::abs(fDegrees2) > 45.0)
                {
                    if (fDirection > 0.0)
                    {
                        if ((*(Actor**)((char*)this + 4))->IsCreature() &&
                            !((Animation*)(*(Actor**)((char*)this + 4))->GetAnimData())->IsGroupQueued(5))
                        {
                            uiMoveFlags3 = 1;
                            *(bool*)((char*)this + 0xe1) = true;
                            *(float*)((char*)this + 0xb8) = 1.0f;
                        }
                        else
                            uiMoveFlags3 = 4;
                    }
                    else
                    {
                        if ((*(Actor**)((char*)this + 4))->IsCreature() &&
                            !((Animation*)(*(Actor**)((char*)this + 4))->GetAnimData())->IsGroupQueued(6))
                        {
                            uiMoveFlags3 = 1;
                            *(bool*)((char*)this + 0xe1) = true;
                            *(float*)((char*)this + 0xb8) = 1.0f;
                        }
                        else
                            uiMoveFlags3 = 8;
                    }
                }
                else
                    uiMoveFlags3 = 1;
            }
            else
                uiMoveFlags3 = (*(DetailedActorMover**)((char*)this + 8))->GetMovementFlags() & 0x3f;
        }
        else
            *(float*)((char*)this + 0x8c) += fTimeDelta;
    }
    else
        uiMoveFlags3 = (*(DetailedActorMover**)((char*)this + 8))->GetMovementFlags() & 0x3f;

    switch (*(int*)((char*)this + 0xcc))
    {
    case 3:
        if ((uiMoveMode3 & 0x200) && (!(uiOldFlagsVal & 0x200) || ((uiOldFlagsVal & 0x30) && !(uiMoveFlags3 & 0x30))))
        {
            *(int*)((char*)this + 0xcc) = 1;
            *(float*)((char*)this + 0x90) = (*(Actor**)((char*)this + 4))->Actor_GetAnimGroupDuration(3) * 0.5;
        }
        else
            break;
    case 1:
        uiMoveMode3 &= ~0x200;
        uiMoveMode3 |= 0x100;
        *(float*)((char*)this + 0x90) -= fTimeDelta;
        if (*(float*)((char*)this + 0x90) < 0.0)
        {
            *(int*)((char*)this + 0xcc) = 2;
            *(float*)((char*)this + 0x90) = 0.0f;
        }
        break;
    case 2:
        *(int*)((char*)this + 0xcc) = 3;
        break;
    }
    *(unsigned int*)((char*)this + 0x60) = uiMoveFlags3 | uiMoveMode3;
    return true;
}
}  // namespace fnv_009e2aa0

struct NiStream;
class hkStatisticsCollector;
class hkVector4;
namespace fnv_009e3560 {
struct PhysicsSimulationContext;
struct CharacterProxyConfiguration;
struct Vector4Data;
struct hkpCharacterProxy;
struct CharacterPhysicsController;
struct blob1
{
    char b[1];
};
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
using ::NiMemObject;
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_009e3560_shell : public DetailedActorPathHandler
{
    void UpdatePathRotation(float);
};

struct TopicH
{
    NiPoint3* GetAddTopicList();
};


struct HighProcessVector
{
    void Subtract(NiPoint3*);
    void Unitize_004a0c10();
};

struct NiPoint3b
{
    float x, y, z;
    NiPoint3b();
};


float __cdecl GetDirectionAngle(NiPoint3 const&);
NiPoint3b __cdecl NiPoint3_TransformByMatrix3(NiPoint3 const&, float const*);
float __cdecl FUN_004f6e40(float);
void __cdecl BSClamp_float(float&, float, float);

extern double DAT_01011588;
extern double _gModifierZero;
extern double const DAT_01020998;
extern double _DAT_010241b0;
extern double const DAT_01064f50;

// Updates the handler's rotation toward the target point, adjusting for water height, controller offset and move-mode angle.
// @fnv 0x009e3560
void FUN_009e3560_shell::UpdatePathRotation(float afDeltaT)
{
    if (((MobileObject*)pActor)->IsSwimming_005a2030())
    {
        NiPoint3 deltaToTargetPoint = ((DetailedActorPathHandler*)this)->m_kPathVector3;
        float fwaterHeight = ((MobileObject*)pActor)->GetRelevantWaterHeight();
        if (fwaterHeight != _DAT_010241b0 && ((DetailedActorPathHandler*)this)->m_kPathVector3.z > fwaterHeight)
        {
            ((DetailedActorPathHandler*)this)->m_kPathVector3.z =
                ((MobileObject*)pActor)->GetRelevantWaterHeight() - DAT_01020998;
        }
        bhkCharacterController* pcon =
            ((MobileObject*)pActor)->GetPhysicsCharacterController();
        NiPoint3 actorLoc = *(((TopicH*)((MobileObject*)pActor))->GetAddTopicList());
        if (pcon)
        {
            actorLoc.z +=
                ((MobileObject*)pActor)->GetActorHeight() * DAT_01011588 * pcon->GetValue();
            ((HighProcessVector*)&deltaToTargetPoint)->Subtract(&actorLoc);
        }
        else
        {
            ((HighProcessVector*)&deltaToTargetPoint)
                ->Subtract((NiPoint3*)((const MobileObject*)((MobileObject*)pActor))->GetPos());
        }
        if (((DetailedActorPathHandler*)this)->m_kPathVector3.z >=
                actorLoc.z - ((MobileObject*)pActor)->GetActorHeight() &&
            ((DetailedActorPathHandler*)this)->m_kPathVector3.z < actorLoc.z)
        {
            deltaToTargetPoint.z = 0.0f;
        }
        NiMatrix3 rot;
        ((HighProcessVector*)&deltaToTargetPoint)->Unitize_004a0c10();
        BSClamp_float(deltaToTargetPoint.z, -1.0f, 1.0f);
        float fangle;
        if (deltaToTargetPoint.z >= _gModifierZero)
        {
            fangle = FUN_004f6e40(deltaToTargetPoint.z);
            fangle = DAT_01064f50 - fangle;
        }
        else
        {
            fangle = FUN_004f6e40(-deltaToTargetPoint.z);
            fangle = fangle - DAT_01064f50;
        }
        if (((DetailedActorPathHandler*)this)->m_kPathVector1.y < _gModifierZero &&
            (((DetailedActorPathHandler*)this)->ByteAndFlagState & 2))
        {
            rot.MakeXRotation(-fangle);
        }
        else
        {
            rot.MakeXRotation(fangle);
        }
        *(NiPoint3b*)&((DetailedActorPathHandler*)this)->m_kPathVector1 =
            NiPoint3_TransformByMatrix3(((DetailedActorPathHandler*)this)->m_kPathVector1, (const float*)&rot);
        return;
    }
    NiPoint3 deltaToTargetPoint = ((DetailedActorPathHandler*)this)->m_bPathFlag3
                                      ? ((DetailedActorPathHandler*)this)->m_kPathVector2
                                      : ((DetailedActorPathHandler*)this)->m_kPathVector3;
    ((HighProcessVector*)&deltaToTargetPoint)->Subtract((NiPoint3*)((const MobileObject*)((MobileObject*)pActor))->GetPos());
    deltaToTargetPoint.z = 0.0f;
    float fangleToTarget = GetDirectionAngle(deltaToTargetPoint);
    float fmoveModeAngle;
    switch (((DetailedActorPathHandler*)this)->GetActorStateFlags() & 0xf)
    {
    case 0:
    case 1:
        fmoveModeAngle = 0.0f;
        break;
    case 2:
        fmoveModeAngle = 3.1415927f;
        break;
    case 4:
        fmoveModeAngle = -1.5707964f;
        break;
    case 8:
        fmoveModeAngle = 1.5707964f;
        break;
    default:
        fmoveModeAngle = 0.0f;
        break;
    }
    float fworldSpaceMoveModeAngle = ((MobileObject*)pActor)->GetCurrentTargetDistance(false) + fmoveModeAngle;
    float fdeltaAngle = fangleToTarget - fworldSpaceMoveModeAngle;
    NiMatrix3 MoveModeRot;
    ((FUN_009e1640_ZRotation&)MoveModeRot).SetRotationMatrix(fdeltaAngle);
    ((DetailedActorPathHandler*)this)->m_kPathVector1 =
        ((const NiMatrix3&)MoveModeRot).operator*(((DetailedActorPathHandler*)this)->m_kPathVector1);
}
}  // namespace fnv_009e3560

namespace fnv_009e3d50 {
float __cdecl BSMAX_00404010(float, float);
extern double _gModifierZero;


// 0x009E3D50 uses the shared handler layout; UpdatePathing is absent from its header.
struct PathSplineUpdate : public DetailedActorPathHandler
{
    void UpdatePathing(float afDeltaT);
};

// Advances the pathing solution parameter along the path, checking direction and distance against the actor's position, and updates the cached point and index.
// @fnv 0x009e3d50
void PathSplineUpdate::UpdatePathing(float afDeltaT)
{
    if (((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetObjectFlags() == 0)
        return;
    if (((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetObjectFlags() > 0 &&
        m_uiPathPointIndex + 1 >= ((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetObjectFlags())
    {
        m_kPathVector3 =
            ((PathingGraphNode*)((NiPointer<PathingSolution>&)pCurrentPathingSolution)->PathingSolution_GetLastNode())->GetLocation().GetPoint<NiPoint3>();
        return;
    }
    if ((ByteAndFlagState & 1) && m_kPathVector1.y < _gModifierZero)
        return;
    if ((ByteAndFlagState & 2) && m_kPathVector1.y > _gModifierZero)
        return;
    if ((ByteAndFlagState & 4) && m_kPathVector1.x > _gModifierZero)
        return;
    if ((ByteAndFlagState & 8) && m_kPathVector1.x < _gModifierZero)
        return;

    NiMatrix3 kRotationBasis;
    ((FUN_009e1640_ZRotation&)kRotationBasis).SetRotationMatrix(((Actor*)pActor)->GetCurrentTargetDistance(false));
    NiPoint3 kForward = ((const NiMatrix3&)kRotationBasis).operator*(m_kPathVector1);
    float fDot;
    NiPoint3 kToTarget = ((const NiPoint3&)m_kPathVector3) - *((const Actor*)pActor)->GetPos();
    NiPoint3 kAhead;
    ((NiPointer<PathingSolution>&)pCurrentPathingSolution)
        ->GetLocationAtSplineParameter(m_fSplineParameter + 0.10000000149011612, kAhead);
    kAhead.Subtract(m_kPathVector3);
    kToTarget.z = 0.0f;
    fDot = ((const NiPoint3&)kForward).Dot(kToTarget);
    float fAheadDot = ((const NiPoint3&)kAhead).Dot(kToTarget);
    float fSqDist = kToTarget.SqrXYLength();
    float fTargetDistSqr = ((const NiPoint3&)m_kPathVector1).FUN_004a7290() * 4.0;
    fTargetDistSqr = BSMAX_00404010(fTargetDistSqr, *(float*)((char*)this + 0x14) * *(float*)((char*)this + 0x14));

    if (fDot < _gModifierZero || fAheadDot < _gModifierZero || fSqDist < fTargetDistSqr)
    {
        m_fPathValue16 = ((NiPointer<PathingSolution>&)pCurrentPathingSolution)
                             ->GetSplineLengthAtParameter(m_fSplineParameter);
        m_kPathVector4 = m_kPathVector3;
        if (((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetObjectFlags() - 1 <= m_fSplineParameter)
        {
            m_fSplineParameter =
                (float)(((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetObjectFlags() - 1);
            m_uiPathPointIndex = (int)m_fSplineParameter;
            m_kPathVector3 =
                ((PathingGraphNode*)((NiPointer<PathingSolution>&)pCurrentPathingSolution)->PathingSolution_GetLastNode())->GetLocation().GetPoint<NiPoint3>();
            return;
        }
        float fLastDot = fDot;
        m_fSplineParameter += 0.10000000149011612;
        ((NiPointer<PathingSolution>&)pCurrentPathingSolution)
            ->GetLocationAtSplineParameter(m_fSplineParameter, m_kPathVector3);
        ((NiPointer<PathingSolution>&)pCurrentPathingSolution)
            ->GetLocationAtSplineParameter(m_fSplineParameter + 0.10000000149011612, kAhead);
        kAhead.Subtract(m_kPathVector3);
        kToTarget = ((const NiPoint3&)m_kPathVector3) - *((const Actor*)pActor)->GetPos();
        kToTarget.z = 0.0f;
        fDot = ((const NiPoint3&)kForward).Dot(kToTarget);
        fAheadDot = ((const NiPoint3&)kAhead).Dot(kToTarget);
        fSqDist = kToTarget.SqrXYLength();
        while (1)
        {
            if (((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetObjectFlags() - 1 <=
                m_fSplineParameter)
            {
                m_fSplineParameter =
                    (float)(((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetObjectFlags() - 1);
                break;
            }
            if (fDot < _gModifierZero || fAheadDot < _gModifierZero)
            {
                if (fDot < fLastDot)
                    break;
            }
            else
            {
                if (fSqDist >= fTargetDistSqr)
                    break;
            }
            fLastDot = fDot;
            m_fSplineParameter += 0.10000000149011612;
            ((NiPointer<PathingSolution>&)pCurrentPathingSolution)
                ->GetLocationAtSplineParameter(m_fSplineParameter, m_kPathVector3);
            ((NiPointer<PathingSolution>&)pCurrentPathingSolution)
                ->GetLocationAtSplineParameter(m_fSplineParameter + 0.10000000149011612, kAhead);
            kAhead.Subtract(m_kPathVector3);
            kToTarget = ((const NiPoint3&)m_kPathVector3) - *((const Actor*)pActor)->GetPos();
            kToTarget.z = 0.0f;
            fDot = ((const NiPoint3&)kForward).Dot(kToTarget);
            fAheadDot = ((const NiPoint3&)kAhead).Dot(kToTarget);
            fSqDist = kToTarget.SqrXYLength();
        }
        m_uiPathPointIndex = (int)m_fSplineParameter;
        ((ActorMover*)m_pActorMover)->FUN_00483710();
    }
}
}  // namespace fnv_009e3d50

namespace std {
float __cdecl abs(float);
}

float __cdecl GetDirectionAngle(const NiPoint3&);
void __cdecl WrapValueToRange(float&, float, float);
void __cdecl BSClamp_float(float&, float, float);

extern const double DAT_01023128;
extern float DAT_010313d4;
extern const double DAT_010357e8;
extern const double DAT_01064f50;
extern const double DAT_0106efa0;
extern const double DAT_01092498;

namespace fnv_009e4800 {
struct NiPoint3_sub : public NiPoint3
{
    NiPoint3_sub operator-(const NiPoint3&) const;
    float Length() const;
    float GetSquaredXYLength() const;
};


struct Flt
{
    operator unsigned int() const;
};

struct DetailedActorPathHandlerRot : public DetailedActorPathHandler
{
    void GetPathAngles(float*, float*);
    void UpdateLookingAngle(float, float);
    float DetailedActorPathHandler_UpdateHeading(float, float*);
};

// @fnv 0x009e4800
// src: COMMUNITY 0x009e4800
float DetailedActorPathHandlerRot::DetailedActorPathHandler_UpdateHeading(float afDeltaT, float* pfRotateMult)
{
    float fPathHeading = 0.0f;
    float fSpeed = 0.0f;
    GetPathAngles(&fPathHeading, &fSpeed);
    float fCurrentHeading = (*(Actor**)((char*)this + 4))->GetCurrentTargetDistance(0);
    WrapValueToRange(fCurrentHeading, -3.1415927f, 3.1415927f);
    WrapValueToRange(fPathHeading, -3.1415927f, 3.1415927f);
    float fTimeSinceScaleStart = fPathHeading - fCurrentHeading;
    WrapValueToRange(fTimeSinceScaleStart, -3.1415927f, 3.1415927f);
    if (std::abs(fTimeSinceScaleStart) >= DAT_01023128)
    {
        float fScale = 1.0f;
        if ((unsigned int)*(Flt*)&pCurrentPathingSolution &&
            (*(Actor**)((char*)this + 4))->GetMaxRotationSpeed() > DAT_010357e8)
        {
            float fDist;
            float fLookAheadDist;
            float fMinRadius;
            float fAngleToTarget;
            float fTargetAngle;
            float fFacingAngle;
            fDist = (((const NiPoint3_sub&)m_kPathVector3) - *(*(const Actor**)((char*)this + 4))->GetPos()).Length();
            fMinRadius = (ByteAndFlagState & 0x200) ? (*(Actor**)((char*)this + 4))->GetRunSpeed()
                                            : (*(Actor**)((char*)this + 4))->GetWalkSpeed();
            fLookAheadDist = fMinRadius;
            NiPoint3 kGoal = m_kPathVector3;
            if (fDist < fLookAheadDist)
            {
                int iNode;
                ((PathingSolution*)(unsigned int)*(Flt*)&pCurrentPathingSolution)
                    ->FindPointOnPath(m_fSplineParameter, fLookAheadDist - fDist, 1, &iNode, &kGoal);
            }
            fFacingAngle = (*(Actor**)((char*)this + 4))->GetCurrentTargetDistance(0);
            NiPoint3_sub toTarget = ((const NiPoint3_sub&)kGoal) - *(*(const Actor**)((char*)this + 4))->GetPos();
            fTargetAngle = GetDirectionAngle(toTarget);
            fAngleToTarget = fTargetAngle - fFacingAngle;
            WrapValueToRange(fAngleToTarget, -3.1415927f, 3.1415927f);
            fScale = std::abs(fAngleToTarget) / DAT_01064f50;
            BSClamp_float(fScale, DAT_010313d4, 1.0f);
        }
        float fMaxTurn = (*(Actor**)((char*)this + 4))->GetMaxRotationSpeed() * DAT_01023128 * afDeltaT * 3.0 * fScale;
        if (std::abs(fTimeSinceScaleStart) > fMaxTurn)
        {
            if (std::abs(fTimeSinceScaleStart) > DAT_01092498)
                *pfRotateMult = 0.05f;
            else if (std::abs(fTimeSinceScaleStart) > 2.0)
                *pfRotateMult = 0.1f;
            else if (std::abs(fTimeSinceScaleStart) > DAT_0106efa0)
                *pfRotateMult = 0.2f;
            else if ((unsigned int)*(Flt*)&pCurrentPathingSolution && (unsigned int)*(Flt*)&m_pPathingRequest)
            {
                if ((*(*(const Actor**)((char*)this + 4))->GetPos() -
                     ((PathingGraphNode*)((PathingSolution*)(unsigned int)*(Flt*)&pCurrentPathingSolution)
                         ->PathingSolution_GetLastNode())
                         ->FUN_00717e50()
                         .FUN_005c3420<NiPoint3>())
                        .GetSquaredXYLength() <
                    (*(Actor**)((char*)this + 4))->FUN_008be1b0() * (*(Actor**)((char*)this + 4))->FUN_008be1b0())
                    *pfRotateMult = 0.5f;
            }
        }
        BSClamp_float(fTimeSinceScaleStart, -fMaxTurn, fMaxTurn);
        fPathHeading = fCurrentHeading + fTimeSinceScaleStart;
    }
    m_fPathValue18 = std::abs(fTimeSinceScaleStart);
    UpdateLookingAngle(afDeltaT, fSpeed);
    return fPathHeading;
}
}  // namespace fnv_009e4800

namespace fnv_009e5690 {


struct PC7d : public Actor
{
};


struct GlobalObject_0044f440 : public Setting
{
};

struct Twin_0084d030
{
    float GetStoredFloatValue();
};


Actor* __cdecl DetailedActorPathHandler_GetFollowLeader(Actor* apActor);
void __cdecl UpdateAliveActorList();
bool __cdecl DetailedActorPathHandler_CheckDetection(Actor* apActor, void* apData, Actor* apOther, NiPoint3* apPos, NiPoint3* apDir,
                          float afDist, float afCosAngle, float* apResult, bool abFlag);

extern double _gModifierZero;
extern const double DAT_01026998;
extern double DAT_0106b798;
extern float DAT_011a5cf4;
extern float DAT_011a5cfc;
extern PC7d* g_thePlayer;
extern unsigned int DAT_011f2aa0;
extern GlobalObject_0044f440 g_011f2b8c;
extern GlobalObject_0044f440 g_011f2b98;
extern NiTPrimitiveArray<Actor*> g_011f2bf8;
extern Twin_0084d030 g_timeGlobal;

// @fnv 0x009e5690
void EvaluateAvoidance(Actor* apActor, PathingRequest* apRequest, unsigned int auiFlags, const NiPoint3* apDir,
                       void* apData, BSSimpleArray<ActorAvoidanceData, 1024>* apList)
{
    float fTime;
    float fSpeed;
    float fScaleMultiplier;
    float fCosThreshold;
    float afValueAfterThirdFloat;
    float fDistance;
    Actor* pTargetActor;
    NiMatrix3 kRot;
    ((FUN_009e1640_ZRotation&)kRot).SetRotationMatrix(apActor->GetCurrentTargetDistance(false));
    NiPoint3 kIntersectionOffset = (const FUN_004b4500_ExtView&)kRot * *apDir;
    float fTravelTime;
    NiPoint3 kNormDir = kIntersectionOffset;
    // Raw scratch storage avoids default-constructor calls in this unoptimized function.
    float akStart[3];
    float fRadius;
    float fAheadDist;

    fTime = g_timeGlobal.GetStoredFloatValue();
    fSpeed = *g_011f2b98.Float();
    fScaleMultiplier = kNormDir.GetLengthSquared();
    fTravelTime = fScaleMultiplier / fTime;
    fAheadDist = fSpeed * fTravelTime;
    ((NiPoint3&)akStart) = (const NiPoint3&)*((const Actor*)apActor)->GetPos();
    fRadius = apRequest->GetFloatAtOffset68();
    fDistance = 0.0f;
    fCosThreshold = DAT_011a5cf4;
    afValueAfterThirdFloat = fRadius + fAheadDist;
    pTargetActor = DetailedActorPathHandler_GetFollowLeader(apActor);
    if (auiFlags & 0x200)
        fCosThreshold = DAT_011a5cfc;

    UpdateAliveActorList();
    for (unsigned int i = 0; i < DAT_011f2aa0; i++)
    {
        float fDistSq;
        float kDelta[3];
        float fLOS;
        Actor* pAvoidActor;
        pAvoidActor = g_011f2bf8.GetAt(i);
        if (pAvoidActor != apActor)
        {
            ((NiPoint3&)kDelta) = (const NiPoint3&)*((const Actor*)pAvoidActor)->GetPos();
            ((NiPoint3&)kDelta).Subtract(((NiPoint3&)akStart));
            fDistSq = ((NiPoint3&)kDelta).GetSquaredXYLength();
            if (fDistSq > DAT_0106b798)
                continue;
            fLOS = pAvoidActor->ProcessCoverLOSResult();
            if (fRadius * DAT_01026998 <= fLOS)
            {
                float kRelOffset[3];
                float fOffsetLength;
                float fAvoidDist;
                float fTimeToTarget;
                float fOtherDist;
                ((NiPoint3&)kRelOffset) = kIntersectionOffset;
                if (pAvoidActor->IsMoving_004938e0())
                {
                    NiMatrix3 kOtherRot;
                    ((FUN_009e1640_ZRotation&)kOtherRot).SetRotationMatrix(pAvoidActor->GetCurrentTargetDistance(false));
                    NiPoint3 kOtherOffset = (const FUN_004b4500_ExtView&)kOtherRot * (const NiPoint3&)pAvoidActor->GetCachedMoveDelta();
                    ((NiPoint3&)kRelOffset).Subtract(kOtherOffset);
                }
                fOffsetLength = ((NiPoint3&)kRelOffset).GetLengthSquared();
                if (fDistSq > *g_011f2b8c.Float() * *g_011f2b8c.Float())
                {
                    NiPoint3 kToOther = (const NiPoint3&)*((const Actor*)pAvoidActor)->GetPos();
                    kToOther.Subtract(((NiPoint3&)akStart));
                    NiPoint3 kToOtherDir = kToOther;
                    kToOtherDir.ComputeMagnitude();
                    if (kToOtherDir.Dot(kNormDir) < _gModifierZero)
                        continue;
                }
                fTimeToTarget = fOffsetLength / fTime;
                fOtherDist = fSpeed * fTimeToTarget;
                fAvoidDist = fRadius + fOtherDist;
                if (fAvoidDist < *g_011f2b8c.Float())
                    fAvoidDist = *g_011f2b8c.Float();
                if (DetailedActorPathHandler_CheckDetection(apActor, apData, pAvoidActor, &((NiPoint3&)akStart), &((NiPoint3&)kRelOffset), fAvoidDist, fCosThreshold,
                                 &fDistance, false))
                    apList->AppendElement(ActorAvoidanceData(pAvoidActor, fDistance));
            }
        }
    }

    if (DetailedActorPathHandler_CheckDetection(apActor, apData, g_thePlayer, &((NiPoint3&)akStart), &kIntersectionOffset, fAheadDist, fCosThreshold,
                     &fDistance, false))
        apList->AppendElement(ActorAvoidanceData(g_thePlayer, fDistance));
}
}  // namespace fnv_009e5690

namespace fnv_009e77d0 {

struct Flt
{
    operator PathingSolution*() const;
};
struct FUN_009e3c00_cls
{
    void AdvanceAlongPath(float);
};
bool __cdecl GetNavMeshHeight(PathingLocation*, float*);
extern const double DAT_01020998;
extern double _gModifierZero;
struct FUN_009e77d0_cls : public DetailedActorPathHandler
{
    void UpdatePathTether(float);
};

// @fnv 0x009e77d0
void FUN_009e77d0_cls::UpdatePathTether(float afPercentTraveled)
{
    m_fPathValue2 = ((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)->GetTotalPathLength();
    m_fSplineParameter = ((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)
                             ->FindSegmentAtFraction(afPercentTraveled, m_fPathValue2, &m_uiPathPointIndex);
    if (m_bPathFlag5)
    {
        m_bPathFlag5 = false;
        if (m_fPathValue2 == _gModifierZero)
        {
            m_uiPathPointIndex = ((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)->GetObjectFlags() - 1;
            m_fSplineParameter = (float)m_uiPathPointIndex;
            m_kPathVector3 =
                ((PathingGraphNode*)((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)->PathingSolution_GetLastNode())->FUN_00717e50().FUN_005c3420<NiPoint3>();
            m_kPathVector4 = *((const TESObjectREFR*)*(TESObjectREFR**)((char*)this + 4))->GetPos();
            m_bPathFlag5 = false;
            return;
        }
        NiPoint3 oldDirVec = ((const NiPoint3&)m_kPathVector3).SubtractIntoVector(m_kPathVector4);
        oldDirVec.z = 0;
        NiPoint3 actorLoc = *((const TESObjectREFR*)*(TESObjectREFR**)((char*)this + 4))->GetPos();
        NiPoint3 actorDirVec = ((const NiPoint3&)m_kPathVector3).SubtractIntoVector(actorLoc);
        float factDotCheck = actorDirVec.Dot((const NiPoint3&)oldDirVec);
        bool bpastGoal = factDotCheck < _gModifierZero;
        float fcheck5 = DAT_01020998 / m_fPathValue2;
        float fcheck20 = fcheck5 * 4.0;
        float fdot;
        float fbestSqrTetherDist = 3.402823466e+38f;
        float fbestSplineT = 0;
        unsigned int ibestNode = 0;
        NiPoint3 actorToTetherDir;
        NiPoint3 newTetherLoc;
        bool botherSide = false;
        unsigned int itempNode;
        float ftempSplineT;
        float fsqrDist;
        for (int i = 0; i < 4; i++)
        {
            ftempSplineT =
                ((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)
                    ->FindSegmentAtFraction(afPercentTraveled + fcheck5 + i * fcheck20, m_fPathValue2, &itempNode);
            ((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)
                ->GetLocationAtSplineParameter(ftempSplineT, (NiPoint3*)&newTetherLoc);
            actorToTetherDir = newTetherLoc.SubtractIntoVector(actorLoc);
            actorToTetherDir.z = 0;
            fdot = actorToTetherDir.Dot((const NiPoint3&)oldDirVec);
            fsqrDist = actorToTetherDir.GetSquaredXYLength();
            if ((!bpastGoal && fdot < _gModifierZero) || (bpastGoal && fdot > _gModifierZero))
            {
                if (botherSide)
                {
                    if (fsqrDist < fbestSqrTetherDist)
                    {
                        fbestSqrTetherDist = fsqrDist;
                        ibestNode = itempNode;
                        fbestSplineT = ftempSplineT;
                        fbestSqrTetherDist = fsqrDist;
                    }
                }
                else
                {
                    botherSide = true;
                    ibestNode = itempNode;
                    fbestSplineT = ftempSplineT;
                    fbestSqrTetherDist = fsqrDist;
                }
            }
            else if (fsqrDist < fbestSqrTetherDist)
            {
                ibestNode = itempNode;
                fbestSplineT = ftempSplineT;
                fbestSqrTetherDist = fsqrDist;
            }
        }
        ((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)
            ->GetLocationAtSplineParameter(fbestSplineT, &m_kPathVector3);
        m_uiPathPointIndex = ibestNode;
        m_fSplineParameter = fbestSplineT;
        m_kPathVector4 = actorLoc;
    }
    else
    {
        ((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)
            ->GetLocationAtSplineParameter(m_fSplineParameter, &m_kPathVector3);
        m_kPathVector4 = m_kPathVector3;
        if (afPercentTraveled > _gModifierZero)
        {
            PathingLocation tetherNavMeshLoc((const NiPoint3&)m_kPathVector3, *(::TESObjectREFR**)((char*)this + 4));
            NiPoint3 snapLocation = m_kPathVector3;
            GetNavMeshHeight(&tetherNavMeshLoc, &snapLocation.z);
            float fheading = (*(MobileObject**)((char*)this + 4))->GetCurrentTargetDistance(false);
            (*(TESObjectREFR**)((char*)this + 4))
                ->Actor_MoveActorAndFollowers(snapLocation, fheading, (*(TESObjectREFR**)((char*)this + 4))->GetParentCell(),
                               (*(TESObjectREFR**)((char*)this + 4))->GetParentWorldSpace(), 1, 1);
        }
        ((FUN_009e3c00_cls*)this)->AdvanceAlongPath(0.0f);
    }
}
}  // namespace fnv_009e77d0

namespace fnv_009e8000 {
struct FUN_009e8000_shell : public DetailedActorPathHandler
{
    int UpdatePathingGoal();
};

struct Flt
{
    operator unsigned int() const;
};
namespace std {
float abs(float);
}
float BSMIN(float, float);
unsigned int __fastcall GetObjectFlags(char*);
int ConstructAndCallMethod(unsigned int, unsigned int, unsigned int, const NiPoint3&);
bool __fastcall FUN_009e8670(unsigned int);
int Warning(const char*, ...);
extern double DAT_01092508;
extern float DAT_011a5d00;
extern double _gModifierZero;


struct LocS
{
    NiPoint3 GetLocation();
};
struct TeleportableReference
{
    const NiPoint3& GetPosition();
};
class PacketNodeRecord;


// Checks the actor's distance to its pathing goal or transition node and returns a pathing status code (0, 2 or 5).
// @fnv 0x009e8000
int FUN_009e8000_shell::UpdatePathingGoal()
{
    if (*(bool*)((char*)this + 0xdf))
    {
        if (*(unsigned int*)((char*)this + 0x64) + 2 >= GetObjectFlags((char*)(unsigned int)*(Flt*)((char*)this + 0xc)))
        {
            NiPoint3 diff;
            bool bPast = false;
            if (*(unsigned int*)((char*)this + 0x64) + 2 ==
                GetObjectFlags((char*)(unsigned int)*(Flt*)((char*)this + 0xc)))
                (NiPoint3&)diff =
                    ((LocS*)&((TeleportableReference*)((PathingSolution*)(unsigned int)*(Flt*)((char*)this + 0xc))
                                  ->GetNode_006e7970(*(unsigned int*)((char*)this + 0x64)))
                         ->GetPosition())
                        ->GetLocation() -
                    *(const NiPoint3*)((const MobileObject*)*(MobileObject**)((char*)this + 4))->GetPos();
            else
                bPast = true;
            if (bPast || diff.GetSquaredXYLength() <= DAT_01092508)
            {
                unsigned int icurrentSize = GetObjectFlags((char*)(unsigned int)*(Flt*)((char*)this + 0xc));
                unsigned int iupdateNode = *(unsigned short*)(*(char**)((char*)this + 8) + 0x42) > 0
                                               ? *(unsigned short*)(*(char**)((char*)this + 8) + 0x42) - 1
                                               : *(unsigned short*)(*(char**)((char*)this + 8) + 0x42);
                switch (ConstructAndCallMethod((unsigned int)*(Flt*)((char*)this + 0x10),
                                               (unsigned int)*(Flt*)((char*)this + 0xc), iupdateNode,
                                               *(const NiPoint3*)((const MobileObject*)*(MobileObject**)((char*)this + 4))->GetPos()))
                {
                case 2:
                case 3:
                    *(bool*)((char*)this + 0xdf) =
                        ((PathingGraphNode*)((PathingSolution*)(unsigned int)*(Flt*)((char*)this + 0xc))->PathingSolution_GetLastNode())->IsTransitionNode();
                    *(unsigned short*)(*(char**)((char*)this + 8) + 0x42) =
                        ((BGSTerrainManager*)(unsigned int)*(Flt*)((char*)this + 0xc))->GetMinLevel();
                    return 0;
                    break;
                case 0:
                    break;
                case 4:
                    break;
                case 1:
                    return 5;
                }
                *(bool*)((char*)this + 0xdf) = false;
            }
        }
    }
    else
    {
        bool bgoalReached = false;
        NiPoint3 goal;
        NiPoint3 diff;
        float fdistanceSqr = 3.402823466e+38f;
        float fgoalRadiusTestSqr;
        if (!((PathingSolution*)(unsigned int)*(Flt*)((char*)this + 0xc))->IsIncomplete() &&
            ((BGSTerrainManager*)(unsigned int)*(Flt*)((char*)this + 0xc))->GetMinLevel() ==
                ((PathingSolution*)(unsigned int)*(Flt*)((char*)this + 0xc))->GetVirtualNodeCount() - 1)
            goal =
                ((LocS*)&((TeleportableReference*)((PathingSolution*)(unsigned int)*(Flt*)((char*)this + 0xc))
                              ->GetVirtualNode(
                                  ((BGSTerrainManager*)(unsigned int)*(Flt*)((char*)this + 0xc))->GetMinLevel()))
                     ->GetPosition())
                    ->GetLocation();
        else
            goal =
                ((LocS*)&(
                     (TeleportableReference*)((PathingSolution*)(unsigned int)*(Flt*)((char*)this + 0xc))->PathingSolution_GetLastNode())
                     ->GetPosition())
                    ->GetLocation();
        (NiPoint3&)diff = goal - *(const NiPoint3*)((const MobileObject*)*(MobileObject**)((char*)this + 4))->GetPos();
        fdistanceSqr = diff.GetSquaredXYLength();
        fgoalRadiusTestSqr = *(float*)((char*)this + 0xac);
        bgoalReached = fdistanceSqr <= *(float*)((char*)this + 0xac);
        if (bgoalReached)
        {
            bool bvalidCheck = true;
            if (FUN_009e8670((unsigned int)*(Flt*)((char*)this + 0x10)) &&
                *(float*)((char*)this + 0xac) > DAT_011a5d00 && fdistanceSqr > DAT_011a5d00)
            {
                NiPoint3 tetherDir = *(NiPoint3*)((char*)this + 0x34) - *(NiPoint3*)((char*)this + 0x4c);
                tetherDir.z = 0.0f;
                NiPoint3 actorToTetherDir =
                    *(NiPoint3*)((char*)this + 0x34) - *(const NiPoint3*)((const MobileObject*)*(MobileObject**)((char*)this + 4))->GetPos();
                actorToTetherDir.z = 0.0f;
                float fdot = ((NiPoint3&)tetherDir).Dot(actorToTetherDir);
                if (fdot >= _gModifierZero && *(float*)((char*)this + 0x78) == _gModifierZero &&
                    *(float*)((char*)this + 0x88) == _gModifierZero)
                    bvalidCheck = false;
            }
            if (bvalidCheck)
            {
                if (!(*(MobileObject**)((char*)this + 4))->IsSwimming_005a2030())
                {
                    if (std::abs(diff.z) <=
                        ((PathingRequest*)(unsigned int)*(Flt*)((char*)this + 0x10))->GetSmoothingRandomness())
                    {
                        return 5;
                    }
                    else if (*(unsigned int*)((char*)this + 0x64) + 1 >=
                                 GetObjectFlags((char*)(unsigned int)*(Flt*)((char*)this + 0xc)) &&
                             !(*(MobileObject**)((char*)this + 4))->IsSwimming_005a2030())
                    {
                        Warning("PATHFINDING: Actor %s failed pathing due to goal Z difference %f, being too large",
                                ((BGSCameraPath*)*(MobileObject**)((char*)this + 4))->HasNameForWarning()
                                    ? (*(MobileObject**)((char*)this + 4))->GetName()
                                    : (*(MobileObject**)((char*)this + 4))->GetFullName(),
                                std::abs(diff.z));
                        return 2;
                    }
                }
                else
                {
                    float fzdeltaThresold = BSMIN(
                        ((PathingRequest*)(unsigned int)*(Flt*)((char*)this + 0x10))->GetSmoothingRandomness(),
                        ((Actor*)*(MobileObject**)((char*)this + 4))->GetActorHeight());
                    if (std::abs(diff.z) <= fzdeltaThresold)
                        return 5;
                }
            }
        }
    }
    return 0;
}
}  // namespace fnv_009e8000

extern "C" bool __cdecl InterfaceManager_Has360Controller(void);

// @fnv 0x00709d40
// src: COMMUNITY 0x00709d40
bool __cdecl Interface_Has360Controller()
{
    return InterfaceManager_Has360Controller();
}

unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);


// @fnv 0x00983720
template <>
void BSSimpleArray<ActorAvoidanceData, 1024>::RemoveAt(unsigned int auiIndex, unsigned int auiCount)
{
    unsigned int uiMoveCount;

    uiMoveCount = FUN_0042f5a0(iSize - auiIndex - auiCount, auiCount);
    ReleaseElements(pBuffer + auiIndex, auiCount);
    UpdateEntryValue(pBuffer + auiIndex, pBuffer + iSize - uiMoveCount, uiMoveCount);
    iSize -= auiCount;
}

namespace fnv_009a86e0 {


extern double DAT_0101ff58;

NiPoint3 CombatUtilities_GetAttackerFiringLocation(TESObjectREFR* apAttacker);
NiPoint3 CombatUtilities_GetAngleToProjectedTarget(NiPoint3 aFiringLocation, TESObjectREFR* apTarget, float afParam1, float afParam2,
                        int aiParam3);

// @fnv 0x009a86e0
NiPoint3 ComputeRelativeFiringAngle(TESObjectREFR* apAttacker, TESObjectREFR* apTarget, float afParam1,
                                      float afParam2, int aiParam3)
{
    NiPoint3 firingPos = CombatUtilities_GetAttackerFiringLocation(apAttacker);
    NiPoint3 kResult = CombatUtilities_GetAngleToProjectedTarget(firingPos, apTarget, afParam1, afParam2, aiParam3);
    kResult = kResult - apAttacker->GetAngleOnReference();
    kResult.y = 0;
    if (kResult.x <= DAT_0101ff58)
        kResult.x += (double)6.2831855f;
    else if (kResult.x > (double)3.1415927f)
        kResult.x -= (double)6.2831855f;
    if (kResult.z <= DAT_0101ff58)
        kResult.z += (double)6.2831855f;
    else if (kResult.z > (double)3.1415927f)
        kResult.z -= (double)6.2831855f;
    return kResult;
}
}  // namespace fnv_009a86e0


struct ClosedDoorPathFilter
{
    TESObjectREFR* pPathNodeDoor;
    bool bEnteredDoor;
    bool bExitedDoor;
    bool bStayedInDoor;

    virtual ~ClosedDoorPathFilter();
    bool CheckDoorTransition(NavMesh* apNavMesh1, unsigned short aTriangle1, unsigned int aEdge1, NavMesh* apNavMesh2,
                             unsigned short aTriangle2, unsigned int aEdge2);
};

// @fnv 0x009e26d0
bool ClosedDoorPathFilter::CheckDoorTransition(NavMesh* apNavMesh1, unsigned short aTriangle1, unsigned int aEdge1,
                                               NavMesh* apNavMesh2, unsigned short aTriangle2, unsigned int aEdge2)
{
    bool bInDoor1 = false;
    if (apNavMesh1->GetTriangle(aTriangle1)->GetFlag(0x1000))
    {
        NavMeshClosedDoorInfo* pDoorInfo1 = apNavMesh1->GetClosedDoorInfo(aTriangle1);
        if (pDoorInfo1 && ((TESObjectREFR*)pDoorInfo1->m_uiDoorFormID == pPathNodeDoor || pPathNodeDoor == 0))
            bInDoor1 = true;
    }
    bool bInDoor2 = false;
    if (apNavMesh2->GetTriangle(aTriangle2)->GetFlag(0x1000))
    {
        NavMeshClosedDoorInfo* pDoorInfo2 = apNavMesh2->GetClosedDoorInfo(aTriangle2);
        if (pDoorInfo2 && ((TESObjectREFR*)pDoorInfo2->m_uiDoorFormID == pPathNodeDoor || pPathNodeDoor == 0))
            bInDoor2 = true;
    }
    if (!bInDoor1)
        bStayedInDoor = false;
    if (!bInDoor2)
        bStayedInDoor = false;
    if (bInDoor1 && !bInDoor2)
        bExitedDoor = true;
    if (!bInDoor1 && bInDoor2)
        bEnteredDoor = true;
    return true;
}

class TESWorldSpace;
class TESObjectCELL;
namespace fnv_009e3110 {
struct TeleportableReference;

struct Flt
{
    operator unsigned int() const;
};


struct TeleportableReference
{
    TESObjectREFR* m_pLinkedDoorReference;
    TESObjectREFR* GetLinkedDoor() const;
};
struct TESHelper
{
    TESObjectCELL* IsCellInterior();
    TESWorldSpace* GetParentWorldSpace();
};
extern TESHelper* g_TES;

extern PlayerCharacter* g_thePlayer;

struct FUN_009e3110_t : public DetailedActorPathHandler
{
    bool IsPathReachableToPlayer() const;
};

// Scans pathing nodes from the current index onward, returning true if any node or its linked door lies in the player's cell or world space.
// @fnv 0x009e3110
bool FUN_009e3110_t::IsPathReachableToPlayer() const
{
    unsigned int iscanNodes;
    bool bcompareCells;
    unsigned int inumNodes;
    TESWorldSpace* pplayerWorld;
    TESObjectCELL* pplayerCell;

    if (!(unsigned int)*(const Flt*)&pCurrentPathingSolution ||
        !((PathingSolution*)(unsigned int)*(const Flt*)&pCurrentPathingSolution)->PathingSolution_IsValid())
        return false;

    inumNodes = ((PathingSolution*)(unsigned int)*(const Flt*)&pCurrentPathingSolution)->GetObjectFlags();
    iscanNodes = m_uiPathPointIndex + 1;
    bcompareCells = true;
    pplayerCell = (TESObjectCELL*)g_thePlayer->GetParentCell();
    pplayerWorld = (TESWorldSpace*)g_thePlayer->GetParentWorldSpace();
    if (!pplayerCell)
    {
        pplayerCell = g_TES->IsCellInterior();
        if (!pplayerCell)
            bcompareCells = false;
    }
    if (!bcompareCells && !pplayerWorld)
    {
        pplayerWorld = g_TES->GetParentWorldSpace();
        if (!pplayerWorld)
            return false;
    }

    for (; iscanNodes < inumNodes; ++iscanNodes)
    {
        const PathingGraphNode* pnode;
        const PathingLocation* ploc;

        pnode = (const PathingGraphNode*)((PathingSolution*)(unsigned int)*(const Flt*)&pCurrentPathingSolution)->GetNode_006e7970(iscanNodes);
        if (!pnode)
            continue;
        ploc = &pnode->FUN_00717e50();
        if (bcompareCells)
        {
            if (pplayerCell == (TESObjectCELL*)ploc->FUN_006dd4f0())
                return true;
        }
        else if (pplayerWorld == (TESWorldSpace*)ploc->FUN_00441110())
        {
            return true;
        }
        if (pnode->PathingNode_IsTeleportDoorNode())
        {
            TeleportableReference* ptel;
            TESObjectREFR* plinkedDoor;
            TESObjectREFR* pdoor;

            pdoor = pnode->GetField38();
            if (!pdoor)
                continue;
            ptel = (TeleportableReference*)pdoor->Set3DObject();
            if (!ptel)
                continue;
            plinkedDoor = ptel->GetLinkedDoor();
            if (!plinkedDoor)
                continue;
            if (bcompareCells)
            {
                if (pplayerCell == (TESObjectCELL*)plinkedDoor->GetParentCell())
                    return true;
            }
            else if (pplayerWorld == (TESWorldSpace*)plinkedDoor->GetParentWorldSpace())
            {
                return true;
            }
        }
    }
    return false;
}
}  // namespace fnv_009e3110

// @fnv 0x009e3970
float bhkCharacterController::GetValue()
{
    return *(float*)((char*)this + 0x560);
}

struct FUN_009e3a70_shell : public DetailedActorPathHandler
{
    NiPoint3 GetNextPathPoint();
};
// Returns the point of the next path node after the current index, the last node if none remain, or the actor's position when there is no path.
// @fnv 0x009e3a70
NiPoint3 FUN_009e3a70_shell::GetNextPathPoint()
{
    if (pCurrentPathingSolution && ((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetNodeCount() > 0)
    {
        if (m_uiPathPointIndex + 1 < ((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetNodeCount())
            return ((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetNode(m_uiPathPointIndex + 1)->GetLocation().GetPoint<NiPoint3>();
        else
            return ((NiPointer<PathingSolution>&)pCurrentPathingSolution)->GetLastNode().GetLocation().GetPoint<NiPoint3>();
    }
    else
    {
        return *(const NiPoint3*)((const Actor*)pActor)->GetPos();
    }
}

namespace std {
float __cdecl abs(float);
}

float __cdecl GetAngleDelta(float, float, float*);
extern double DAT_010924a0;

struct MobileObjectLookingHelper
{
    float GetLooking() const;
};
struct ST_00931e50
{
    void ClampLookAngle(float);
};

struct FUN_009e4c60_t : public DetailedActorPathHandler
{
    void UpdateLookingAngle(float afDeltaT, float afLookingAngle);
};

// @fnv 0x009e4c60
void FUN_009e4c60_t::UpdateLookingAngle(float afDeltaT, float afLookingAngle)
{
    float frotateMax;
    float fcurrentLooking;
    float fdir;
    float fclampedAngleDelta;
    float fangleDelta;

    fcurrentLooking = (*(MobileObjectLookingHelper**)((char*)this + 4))->GetLooking();
    frotateMax = afDeltaT * DAT_010924a0;
    fdir = 0;
    fangleDelta = std::abs(GetAngleDelta(fcurrentLooking, afLookingAngle, &fdir));
    fclampedAngleDelta = fangleDelta;
    if (fclampedAngleDelta > frotateMax)
        fclampedAngleDelta = frotateMax;
    fcurrentLooking = fclampedAngleDelta * fdir + fcurrentLooking;
    (*(ST_00931e50**)((char*)this + 4))->ClampLookAngle(fcurrentLooking);
}

struct FUN_009e5ab0_Class
{
    int m_iWordAt00;
    float m_iWordAt04;
    FUN_009e5ab0_Class* Init(int arg1, float arg2);
};

// @fnv 0x009e5ab0
FUN_009e5ab0_Class* FUN_009e5ab0_Class::Init(int aiValue, float afValue)
{
    m_iWordAt00 = aiValue;
    m_iWordAt04 = afValue;
    return this;
}


struct LH
{
    bool IsInList(Actor* const&);
    void _ref_00905330(Actor* const&);
    bool _ref_008256d0();
};


extern unsigned int DAT_011f2aa0;
extern NiTPrimitiveArray<Actor*> g_011f2bf8;

struct FUN_009e8690_shell : DetailedActorPathHandler
{
    void FUN_009e68c0();
    void RemoveRefFromPathHandler(TESObjectREFR* apRef);
};

// @fnv 0x009e8690
void FUN_009e8690_shell::RemoveRefFromPathHandler(TESObjectREFR* apRef)
{
    if (apRef == m_pPathTargetReference)
    {
        m_iPathValue2 = 0;
        m_pPathTargetReference = 0;
    }

    if (apRef->IsActor())
    {
        for (unsigned int i = 0; i < DAT_011f2aa0; ++i)
        {
            if (g_011f2bf8.GetAt(i) == apRef)
            {
                g_011f2bf8.RemoveAt(i);
                g_011f2bf8.Compact();
                DAT_011f2aa0--;
            }
        }

        if (((LH*)((char*)this + 0x58))->IsInList((Actor*)apRef))
        {
            ((LH*)((char*)this + 0x58))->_ref_00905330((Actor*)apRef);
            if (((LH*)((char*)this + 0x58))->_ref_008256d0())
                FUN_009e68c0();
        }
    }
}


// @fnv 0x009e20a0
unsigned char __thiscall PathingRequestQueries::GetByteAtOffset9F()
{
    return *(reinterpret_cast<unsigned char*>(this) + 0x9f);
}

struct LS3de0
{
    unsigned int Find(unsigned int& a, unsigned int b, bool(__cdecl* cmp)(int const*, int const*));
};

extern "C" unsigned int __cdecl _FUN_009a3830(unsigned int, unsigned int);

struct FUN_009e2660_Class
{
    bool Contains(unsigned int arg);
};

// Returns whether the container at offset 0x30 finds the given value, comparing against -1 to indicate presence.
// @fnv 0x009e2660
bool FUN_009e2660_Class::Contains(unsigned int auiValue)
{
    return ((LS3de0*)((char*)this + 0x30))->Find(auiValue, 0, (bool(__cdecl*)(int const*, int const*))_FUN_009a3830) !=
           -1;
}

struct Flt
{
    operator unsigned int() const;
};

struct DetailedPathDistanceQueries : DetailedActorPathHandler
{
    float GetFloatValue();
};

// @fnv 0x009e2830
float DetailedPathDistanceQueries::GetFloatValue()
{
    if (!(NiPointer<PathingSolution>&)pCurrentPathingSolution)
        return 0.0f;
    return m_fPathValue16;
}


struct DetailedPathPointQueries : DetailedActorPathHandler
{
    bool IsPointValid(NiPoint3& arPoint);
};

// Copies the NiPoint3 stored at offset 0x34 of this object into arPoint and returns true.
// @fnv 0x009e3990
bool DetailedPathPointQueries::IsPointValid(NiPoint3& arPoint)
{
    arPoint = m_kPathVector3;
    return true;
}

namespace fnv_009e68c0 {

struct DetailedPathResetQueries : DetailedActorPathHandler
{
    void Reset();
};

// Sets the flag at offset 0xd0 to 1, clears the list at 0x58, and zeroes the floats at 0x78 and 0x74.
// @fnv 0x009e68c0
void DetailedPathResetQueries::Reset()
{
    m_iPathParameter2 = 1;
    ActorAvoidEntryList.RemoveAll();
    m_fPathValue5 = 0.0f;
    m_fPathValue4 = 0.0f;
}
}  // namespace fnv_009e68c0

struct DetailedPathFlagQueries : DetailedActorPathHandler
{
    char GetMethod();
};

// @fnv 0x009e8670
char DetailedPathFlagQueries::GetMethod()
{
    return *(char*)&m_fPathValue13;
}

struct NiRTTI;

void* __cdecl hkVector4_getZero();
int __fastcall GetReferenceFlags(void*);
struct FUN_00cac910_shell
{
    void* hkpCharacterProxy_getPosition();
};
// Calls GetReferenceFlags on this, then FUN_00458b20; if the returned code is nonzero, invokes FUN_00cac910 on it and returns that result.
// @fnv 0x00621a40
// src: XBOX_PDB 0x00621a40
void* NiObject::bhkCharacterProxy_GethkPosition()
{
    int code;
    void* result;
    code = GetReferenceFlags(this);
    result = hkVector4_getZero();
    if (code != 0)
    {
        NiObject::GetStreamableRTTI();
        result = ((FUN_00cac910_shell*)code)->hkpCharacterProxy_getPosition();
        NiObject::GetStreamableRTTI();
    }
    return result;
}

// @fnv 0x008b3d50
// src: XBOX_PDB 0x008b3d50
const NiPoint3& Actor::GetCachedMoveDelta()
{
    return *(const NiPoint3*)((TESForm*)m_pActorMover)->GetSourceFiles();
}

void __fastcall SetVtable(void*);
extern int DAT_01092484;
struct FUN_009e2690
{
    void* f0;
    int f4;
    unsigned char f8;
    unsigned char f9;
    unsigned char f10;
    FUN_009e2690(int);
};
// Initializes the object: calls SetVtable, sets f0 to &DAT_01092484, stores a in f4, and sets f8, f9 to 0 and f10 to 1.
// @fnv 0x009e2690
FUN_009e2690::FUN_009e2690(int aiValue)
{
    SetVtable(this);
    f0 = &DAT_01092484;
    f4 = aiValue;
    f8 = 0;
    f9 = 0;
    f10 = 1;
}

float __cdecl BSMAX_00404010(float, float);
struct DetailedPathRemainingDistanceQueries : DetailedActorPathHandler
{
    float DetailedActorPathHandler_GetDistanceRemaining();
};
// @fnv 0x009e2860
// src: XBOX_PDB 0x009e2860
float DetailedPathRemainingDistanceQueries::DetailedActorPathHandler_GetDistanceRemaining()
{
    float flength;
    flength = m_fPathValue2 - vfn_18();
    flength = BSMAX_00404010(flength, 0.0f);
    return flength;
}

extern double _gModifierZero;
void __cdecl BSClamp_float(float&, float, float);
struct DetailedPathProgressQueries : DetailedActorPathHandler
{
    float DetailedActorPathHandler_GetPercentTraveled();
};
// @fnv 0x009e28a0
// src: XBOX_PDB 0x009e28a0
float DetailedPathProgressQueries::DetailedActorPathHandler_GetPercentTraveled()
{
    float fRatio;
    if (m_fPathValue2 <= _gModifierZero)
        return 1.0f;
    fRatio = vfn_18() / m_fPathValue2;
    BSClamp_float(fRatio, 0.0f, 1.0f);
    return fRatio;
}

struct DetailedPathModeQueries : DetailedActorPathHandler
{
    bool DetailedActorPathHandler_IsWaitingForAvoidance();
};

// @fnv 0x009e2a80
// src: XBOX_PDB 0x009e2a80
bool DetailedPathModeQueries::DetailedActorPathHandler_IsWaitingForAvoidance()
{
    return m_iPathParameter2 == 2;
}

struct DetailedPathMoveModeQueries : DetailedActorPathHandler
{
    void SetMode(unsigned int mode);
};

// @fnv 0x009e3360
void DetailedPathMoveModeQueries::SetMode(unsigned int mode)
{
    ByteAndFlagState = mode;
}

struct DetailedPathMovementQueries : DetailedActorPathHandler
{
    bool DetailedActorPathHandler_IsMovementBlocked();
};

// @fnv 0x009e3be0
// src: XBOX_PDB 0x009e3be0
bool DetailedPathMovementQueries::DetailedActorPathHandler_IsMovementBlocked()
{
    return m_bPathFlag3;
}


struct POD12
{
    int a;
    int b;
    int c;
};
struct FUN_009e6870
{
    POD12 f0;
    NiPoint3 fC;
    float f18;
    float f1C;
    int f20;
    FUN_009e6870(const POD12&, float, float, int);
};
// Initializes the object from a POD12 value and stores the two floats and the int into f18, f1C and f20.
// @fnv 0x009e6870
FUN_009e6870::FUN_009e6870(const POD12& aPOD12, float afValue1, float afValue2, int aiValue) : f0(aPOD12)
{
    f18 = afValue1;
    f1C = afValue2;
    f20 = aiValue;
}

extern int DAT_01092640;
// Sets the vtable to DAT_01092640, calls InitBuffer with 0 and 0, and returns this.
// @fnv 0x009e9950
template <>
BSSimpleArray<ActorAvoidanceData, 1024>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

// @fnv 0x009e9980
template <>
BSSimpleArray<ActorAvoidanceData, 1024>::~BSSimpleArray()
{
    Clear(true);
}

namespace fnv_009e2900 {

struct Flt : GO
{
    operator unsigned int();
};
struct SpObst : Flt
{
    SpObst(unsigned int*);
};
char __fastcall GetByteAtOffset70(char*);

struct Ref_009e2900
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual unsigned int GetFlags();
};

struct FUN_009e2900_t
{
    void* vtbl;
    TESObjectREFR* pActor;
    char* pRef;
    unsigned int pCurrentPathingSolution;
    char pad[0x70 - 0x10];
    float m_fSplineParameter;
    NiPoint3 GetPathingPosition(float afDeltaT) const;
};

// @fnv 0x009e2900
NiPoint3 FUN_009e2900_t::GetPathingPosition(float afDeltaT) const
{
    if (!(unsigned char)GetByteAtOffset70(pRef))
    {
        SpObst pPathingSolution((unsigned int*)&pCurrentPathingSolution);
        if (pPathingSolution && ((PathingSolution*)(unsigned int)pPathingSolution)->GetNodeCount())
        {
            float fdistance;
            float fspeed;
            if (((Ref_009e2900*)pRef)->GetFlags() & 0x200)
                fspeed = ((Actor*)pActor)->GetRunSpeed();
            else
                fspeed = ((Actor*)pActor)->GetWalkSpeed();
            fdistance = fspeed * afDeltaT;
            return ((PathingSolution*)(unsigned int)pPathingSolution)
                ->GetPointAtDistance(m_fSplineParameter, fdistance);
        }
        else
        {
            return *(const NiPoint3*)((const Actor*)pActor)->GetPos();
        }
    }
    else
    {
        return *(const NiPoint3*)((const Actor*)pActor)->GetPos();
    }
}
}  // namespace fnv_009e2900

namespace fnv_009e3c00 {
struct FUN_009e3c00_shell : public DetailedActorPathHandler
{
    void AdvanceAlongPath(float);
};


struct Flt
{
    operator unsigned int();
};
struct FUN_009e5480_shell
{
    void ResetPathState();
};
extern double gModifierZero;

// @fnv 0x009e3c00
void FUN_009e3c00_shell::AdvanceAlongPath(float afDist)
{
    if (!((PathingSolution*)pCurrentPathingSolution)->GetNodeCount())
        return;
    if (this->m_uiPathPointIndex + 1 >=
        ((PathingSolution*)pCurrentPathingSolution)->GetNodeCount())
        return;
    this->m_fPathValue16 =
        ((PathingSolution*)pCurrentPathingSolution)
            ->GetSplineLengthAtParameter(this->m_fSplineParameter);
    this->m_kPathVector4 = this->m_kPathVector3;
    ((FUN_009e5480_shell*)this)->ResetPathState();
    NiPoint3 newPoint;
    float fnewSplineT;
    if (afDist >= gModifierZero)
        ((PathingSolution*)pCurrentPathingSolution)
            ->FindPointOnPath(this->m_fSplineParameter, afDist, 1, (int*)&fnewSplineT,
                           (NiPoint3*)&newPoint);
    else
        ((PathingSolution*)pCurrentPathingSolution)
            ->FindPointOnPath(this->m_fSplineParameter, -afDist, 0, (int*)&fnewSplineT,
                           (NiPoint3*)&newPoint);
    this->m_fSplineParameter = fnewSplineT;
    this->m_kPathVector3 = (const NiPoint3&)newPoint;
    this->m_uiPathPointIndex = (int)this->m_fSplineParameter;
    m_pActorMover->FUN_00483710();
}
}  // namespace fnv_009e3c00

class GameTimerRecord;
namespace fnv_009e54a0 {


struct BSSimpleListTESRaceSize
{
    int GetSize();
};
struct FUN_007ff8e0_shell
{
    bool NiAVObject_QFadedIn();
};

// The approved controller lacks this query. Extend its declaration locally
// without repeating its layout or virtual table.
struct CharacterControllerQueries : public bhkCharacterController
{
    float bhkCharacterController_QLODDistance() const;
};

struct FUN_009e54a0_ref
{
    Actor** _ref_006815c0();
};
struct GlobalObject_0044f440;
extern int DAT_011e0e80;
extern int DAT_011f2a9c;
extern unsigned int DAT_011f2aa0;
extern int DAT_011f2aa4;
extern GlobalObject_0044f440 g_011f2bd0;
extern NiTPrimitiveArray<Actor*> g_011f2bf8;
extern GameTimerRecord g_timeGlobal;

// Rebuilds the actor list when the idle section changes: clears it, sizes it to the alive actor count, and adds qualifying actors.
// @fnv 0x009e54a0
bool UpdateAliveActorList()
{
    int section = ((AnimIdle*)&g_timeGlobal)->GetSection();
    if (DAT_011f2aa4 != section)
    {
        BSSimpleList<Actor*>* pActorList = ((ProcessLists*)&DAT_011e0e80)->GetAliveActorList();
        DAT_011f2aa4 = section;
        g_011f2bf8.RemoveAll();
        DAT_011f2a9c = ((BSSimpleListTESRaceSize*)pActorList)->GetSize();
        g_011f2bf8.SetSize(DAT_011f2a9c);
        DAT_011f2aa0 = 0;
        for (; pActorList; pActorList = pActorList->GetNext())
        {
            Actor* actor = *((FUN_009e54a0_ref*)pActorList)->_ref_006815c0();
            if (!actor)
                continue;
            NiNode* node = actor->GetNiNode();
            if (!node)
                continue;
            if (!((FUN_007ff8e0_shell*)node)->NiAVObject_QFadedIn())
                continue;
            if (actor->GetPhysicsCharacterController() && ((BSFadeNode*)node)->NiNode_QNotVisible() &&
                ((CharacterControllerQueries*)actor->GetPhysicsCharacterController())->bhkCharacterController_QLODDistance() >
                    *((Setting*)&g_011f2bd0)->Float())
                continue;
            DAT_011f2aa0++;
            g_011f2bf8.AddFirstEmpty(actor);
        }
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_009e54a0

class ActiveEffect;
class AlchemyItem;
struct BGSEncounterZone;
struct BGSImpactDataSet;
class BGSLoadGameBuffer;
class BGSPerk;
class BGSPerkEntry;
class BGSSaveGameBuffer;
class BGSTextureSet;
class BSAnimGroupSequence;
class BSAnimNote;
class BSAnimNoteReceiver;
class BSExtraData;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSMultiBound;
class BSMultiBoundRoom;
class BSSoundHandle;
class BaseProcess;
class CellMopp;
class CombatController;
class ActorCombatGroup;
class ContinuousBeamProjectile;
class EffectItem;
class ExtraDataList;
class ExtraLock;
class FormRecordHeader;
class FurnitureMark;
class HWND__;
class IDebugText;
struct InventoryChanges;
class InventoryStackRecord;
class MagicCaster;
class MagicItem;
class MagicProjectile;
class MagicTarget;
class NiAVObject;
class NiColor;
class NiControllerManager;
class NiControllerSequence;
class NiFixedString;
class NiGeometry;
class NiLight;
class NiNode;
class NiPointLight;
class PlacedObjectInfo;
class PathingAvoidNodeArray;
class Projectile;
class QueuedFile;
class Script;
class ScriptLocals;
class SpellItem;
class TESActorBase;
class TESAmmo;
class TESBoundObject;
class TESClass;
class TESCombatStyle;
class TESContainer;
class TESFaction;
class TESFile;
class TESForm;
class TESGlobal;
class TESIdleForm;
class TESModel;
class TESObject;
class TESObjectARMO;
class TESObjectBOOK;
class TESObjectCELL;
class TESObjectCLOT;
class TESObjectLIGH;
class TESObjectWEAP;
class TESPackage;
class TESRace;
class TESSkill;
class TESSound;
class TESTopic;
class TESTopicInfo;
class TESWorldSpace;
class TargetEntry;
class TrespassPackage;
class WeaponObject;
class bhkNiCollisionObject;
class bhkRagdollController;
class bhkRigidBody;
class hkpRigidBody;
namespace fnv_009e6ba0 {
struct ActorCause;
struct TwoIntegerValues;
struct MediaLocation;
struct ExplosionForm;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct TESFileGroup;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct CellDataNode;
struct MagicEffectCollection;
struct MapMarkerData;

struct Point3Offset;
struct AnimationInterpolator;
struct IndexedPointerCollection;
struct LocationDescriptor;

struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct TrapEntry;
struct WaterZone;

struct bhkRagdollPenetrationUtil;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
using ::NiMemObject;
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];

typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];

typedef char _sizecheck_CachedValuesOwner[sizeof(CachedValuesOwner) == 4 ? 1 : -1];
struct FUN_009e6ba0_shell : public DetailedActorPathHandler
{
    void UpdatePathingOrigin(PathingRequest*);
};

struct NiPoint3Ops : public NiPoint3
{
    NiPoint3Ops();
    NiPoint3Ops operator-(const NiPoint3& pt) const;
    NiPoint3Ops& operator-=(const NiPoint3& pt);
    float Length() const;
};

struct CellOps_9e6ba0
{
    bool IsInterior();
};

struct WorldOps_9e6ba0
{
    CellOps_9e6ba0* GetCellByWorldPosition(const NiPoint3& pt);
};


struct PlayerOps_9e6ba0
{
    bool IsSleepingOrResting();
};


struct PathingRequestOps
{
    PathingLocation* GetOrigin();
    PathingLocation* GetDestination();
    void SetOrigin(const PathingLocation& loc);
    void SetInitialTangent(float angle);
    void ClearInitialTangent();
};


template <class T> struct NiPointerOps
{
    T* m_pObject;
    operator T*() const;
};

template <class T> struct BSSimpleListOps
{
    T m_item;
    BSSimpleListOps<T>* m_pkNext;
    T& GetItem();
    BSSimpleListOps<T>* GetNext();
    bool IsEmpty();
};

struct PathHandlerOps : public ActorPathHandler
{
    void AdjustTether(float delta);
};

float __cdecl GetDirectionAngle(const NiPoint3& dir);
bool __cdecl NavMeshMath_SegmentCircleIntersection(const NiPoint3* start, const NiPoint3* end, const NiPoint3* avoidPos, float avoidRadius);

extern PlayerOps_9e6ba0* g_thePlayer;
extern Setting g_011f2b68;
extern double DAT_01011588;

// Validates the pathing solution and player state, then updates the tether and sets the request origin based on actor position, cell interior, and avoided actors.
// @fnv 0x009e6ba0
void FUN_009e6ba0_shell::UpdatePathingOrigin(PathingRequest* apRequest)
{
    if (!(PathingSolution*)(NiPointerOps<PathingSolution>&)((DetailedActorPathHandler*)this)->pCurrentPathingSolution ||
        !((PathingSolution*)(NiPointerOps<PathingSolution>&)((DetailedActorPathHandler*)this)->pCurrentPathingSolution)
             ->IsValid() ||
        g_thePlayer->IsSleepingOrResting())
    {
        ((DetailedActorPathHandler*)this)->eState = 0;
        return;
    }

    ((DetailedActorPathHandler*)this)->m_fPathValue16 = 0.0f;
    if (((DetailedActorPathHandler*)this)->m_bPathFlag5)
    {
        ((PathingRequestOps*)apRequest)
            ->SetOrigin(PathingLocation((const NiPoint3&)((DetailedActorPathHandler*)this)->m_kPathVector3,
                                        *(::TESObjectREFR**)((char*)this + 4)));
        return;
    }

    if (((DetailedActorPathHandler*)this)->eState != 2)
        return;

    ((DetailedActorPathHandler*)this)->m_bPathFlag5 = true;
    NiPoint3 actorCurrent = *(*(const TESObjectREFR**)((char*)this + 4))->GetPos();
    // The shared vfn_3c declaration returns void; this call consumes its bool result.
    if (((DetailedActorPathHandler*)this)->m_bPathFlag3 || ((bool (__thiscall**)(void*))*(void**)this)[15](this) ||
        ((DetailedActorPathHandler*)this)->m_bPathFlag1)
    {
        ((DetailedActorPathHandler*)this)->m_kPathVector3 = actorCurrent;
        ((DetailedActorPathHandler*)this)->m_kPathVector4 = actorCurrent;
        ((DetailedActorPathHandler*)this)->eState = 4;
        ((PathingRequestOps*)apRequest)->SetOrigin(PathingLocation(*(::TESObjectREFR**)((char*)this + 4)));
        return;
    }
    else
    {
        float fnewLen = (((PathingRequestOps*)apRequest)->GetOrigin()->GetLocation<NiPoint3Ops>() -
                         ((PathingRequestOps*)apRequest)->GetDestination()->GetLocation<NiPoint3Ops>())
                            .Length();
        float fwaitDist = *g_011f2b68.Float();
        if (((DetailedActorPathHandler*)this)->ByteAndFlagState & 0x200)
            fwaitDist += *g_011f2b68.Float();
        fwaitDist *= 2.0f;
        if (fnewLen < fwaitDist)
            fwaitDist = fnewLen * DAT_01011588;
        float fdiff =
            (static_cast<NiPoint3Ops&>(actorCurrent) - ((DetailedActorPathHandler*)this)->m_kPathVector3).Length();
        if (fdiff < fwaitDist)
        {
            float fupdateLen = fwaitDist - fdiff;
            ((PathHandlerOps*)this)->AdjustTether(fupdateLen);
        }
        else
        {
            float fupdateLen = fdiff - fwaitDist;
            ((PathHandlerOps*)this)->AdjustTether(-fupdateLen);
        }
    }

    bool bfixupTether = true;
    if ((*(TESObjectREFR**)((char*)this + 4))->GetParentCell() &&
        ((CellOps_9e6ba0*)(*(TESObjectREFR**)((char*)this + 4))->GetParentCell())->IsInterior())
        bfixupTether = false;
    else if ((*(TESObjectREFR**)((char*)this + 4))->GetParentWorldSpace() &&
             ((WorldOps_9e6ba0*)(*(TESObjectREFR**)((char*)this + 4))->GetParentWorldSpace())
                 ->GetCellByWorldPosition(((DetailedActorPathHandler*)this)->m_kPathVector3))
        bfixupTether = false;

    if (bfixupTether)
    {
        ((DetailedActorPathHandler*)this)->m_kPathVector3 = actorCurrent;
        ((DetailedActorPathHandler*)this)->m_kPathVector4 = actorCurrent;
        ((DetailedActorPathHandler*)this)->eState = 4;
    }
    else
    {
        ((DetailedActorPathHandler*)this)->m_kPathVector4 = actorCurrent;
        ((DetailedActorPathHandler*)this)->eState = 3;
        NiPoint3 newPathOrigin = ((DetailedActorPathHandler*)this)->m_kPathVector3;
        bool bSetInitialTangent = true;
        float finitialAngle;
        NiPoint3Ops tetherTangent;
        ((PathingSolution*)(NiPointerOps<PathingSolution>&)((DetailedActorPathHandler*)this)->pCurrentPathingSolution)
            ->GetPoint(((DetailedActorPathHandler*)this)->m_fSplineParameter + 0.10000000149011612, tetherTangent);
        tetherTangent -= ((DetailedActorPathHandler*)this)->m_kPathVector3;
        finitialAngle = (GetDirectionAngle)(tetherTangent);

        if (!((BSSimpleListOps<Actor*>*)&((DetailedActorPathHandler*)this)->ActorAvoidEntryList)->IsEmpty())
        {
            BSSimpleListOps<Actor*>* pCurrentElementNext =
                (BSSimpleListOps<Actor*>*)&((DetailedActorPathHandler*)this)->ActorAvoidEntryList;
            while (pCurrentElementNext)
            {
                Actor* pavoidActor = pCurrentElementNext->GetItem();
                pCurrentElementNext = pCurrentElementNext->GetNext();
                if (NavMeshMath_SegmentCircleIntersection((*(const TESObjectREFR**)((char*)this + 4))->GetPos(),
                                 &((DetailedActorPathHandler*)this)->m_kPathVector3, ((const Actor*)pavoidActor)->GetPos(),
                                 pavoidActor->FUN_008be1b0()))
                {
                    newPathOrigin = *(*(const TESObjectREFR**)((char*)this + 4))->GetPos();
                    bSetInitialTangent = false;
                    break;
                }
            }
        }

        ((PathingRequestOps*)apRequest)
            ->SetOrigin(PathingLocation((const NiPoint3&)newPathOrigin, *(::TESObjectREFR**)((char*)this + 4)));
        if (bSetInitialTangent)
            ((PathingRequestOps*)(NiPointerOps<PathingRequestOps>&)((DetailedActorPathHandler*)this)->m_pPathingRequest)
                ->SetInitialTangent(finitialAngle);
        else
            ((PathingRequestOps*)(NiPointerOps<PathingRequestOps>&)((DetailedActorPathHandler*)this)->m_pPathingRequest)
                ->ClearInitialTangent();
    }
}
}  // namespace fnv_009e6ba0

class ActiveEffect;
class AlchemyItem;
struct BGSEncounterZone;
class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
class BSAnimNoteReceiver;
class BSExtraData;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSMultiBound;
class BSMultiBoundRoom;
class BSSoundHandle;
class BaseProcess;
class CellMopp;
class EffectItem;
class ExtraDataList;
class ExtraLock;
class FormRecordHeader;
class FurnitureMark;
class HWND__;
struct InventoryChanges;
class InventoryStackRecord;
class MagicCaster;
class MagicItem;
class MagicProjectile;
class MagicTarget;
class NiAVObject;
class NiColor;
class NiControllerManager;
class NiControllerSequence;
class NiFixedString;
class NiGeometry;
class NiLight;
class NiNode;
class NiPointLight;
class NiQuaternion;
class PlacedObjectInfo;
class Script;
class ScriptLocals;
class SpellItem;
class TESActorBase;
class TESAmmo;
class TESBoundObject;
class TESContainer;
class TESFile;
class TESForm;
class TESGlobal;
class TESIdleForm;
class TESModel;
class TESObjectARMO;
class TESObjectCELL;
class TESObjectCLOT;
class TESObjectLIGH;
class TESObjectWEAP;
class TESPackage;
class TESSound;
class TESTopic;
class TESTopicInfo;
class TESWorldSpace;
class TargetEntry;
class bhkNiCollisionObject;
class hkVector4;
class hkpRigidBody;
namespace fnv_009e9760 {
struct ActorCause;
struct TwoIntegerValues;
struct MediaLocation;
struct ExplosionForm;
struct SaveLoadFile;
struct BipedAnim;
struct CHUNK;
struct GameFormRecord;
struct DialogueResponse;
struct TeleportableReference;
struct TESFileGroup;
struct BooleanIntegerAccessor;
struct CellDataNode;
struct MagicEffectCollection;
struct MapMarkerData;

struct Point3Offset;
struct AnimationInterpolator;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct TrapEntry;
struct WaterZone;

struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};

typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];

typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];
struct FUN_009e9760_shell : public DetailedActorPathHandler
{
    void DetailedActorPathHandler_InitLoadGame(BGSLoadFormBuffer*);
};


struct AvoidActorListNode
{
    ::Actor* m_item;
    AvoidActorListNode* m_pkNext;
    bool _ref_008256d0();
    ::Actor** _ref_006815c0();
    void _ref_00726c60(::Actor* const&);
    void _ref_00905330(::Actor* const&);
    AvoidActorListNode* _ref_00726070();
    void _ref_0063f7b0();
};

::TESForm* _ref_004839c0(unsigned int);

// @fnv 0x009e9760
// src: XBOX_PDB 0x009e9760
void FUN_009e9760_shell::DetailedActorPathHandler_InitLoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    AvoidActorListNode* pCurrentElementNext;
    AvoidActorListNode* plastList;

    m_pPathTargetReference = m_pPathTargetReference
                                 ? dynamic_cast< ::TESObjectREFR*>(_ref_004839c0((unsigned int)m_pPathTargetReference))
                                 : 0;
    pCurrentElementNext = (AvoidActorListNode*)&ActorAvoidEntryList;
    plastList = 0;
    while (pCurrentElementNext && !pCurrentElementNext->_ref_008256d0())
    {
        ::Actor* pForm;
        bool bremove;

        pForm = *pCurrentElementNext->_ref_006815c0();
        bremove = false;
        if (pForm)
        {
            pForm = pForm ? dynamic_cast< ::Actor*>(_ref_004839c0((unsigned int)pForm)) : 0;
            if (pForm)
                pCurrentElementNext->_ref_00726c60(pForm);
            else
                bremove = true;
        }
        else
        {
            bremove = true;
        }
        if (bremove)
        {
            if (plastList)
            {
                plastList->_ref_00905330(*pCurrentElementNext->_ref_006815c0());
                pCurrentElementNext = plastList->_ref_00726070();
            }
            else
            {
                pCurrentElementNext->_ref_0063f7b0();
            }
        }
        else
        {
            plastList = pCurrentElementNext;
            pCurrentElementNext = pCurrentElementNext->_ref_00726070();
        }
    }
    if (m_pPathTargetReference)
        ((TESObjectREFR*)m_pPathTargetReference)->TESObjectREFR_SetTargeted(true);
}
}  // namespace fnv_009e9760

struct Pair3
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct Pair3Pool
{
    Pair3* Fetch();
};

struct Mid
{
    Pair3Pool* Step();
};

struct Node
{
    unsigned int Count();
    Mid* Find(int key, unsigned int* out);
};

struct Ctx
{
    Node* Get();
};

struct FUN_009e3b60_cls
{
    int unk00;
    int unk04;
    int unk08;
    Ctx m_0c;

    bool GetPairByIndex(int a1, Pair3* a2);
};

// Looks up the entry for index a1 in the context node and copies its Pair3 into a2, returning true if found.
// @fnv 0x009e3b60
bool FUN_009e3b60_cls::GetPairByIndex(int aiIndex, Pair3* apPair)
{
    unsigned int out;
    unsigned int pad;
    unsigned int pad2;
    if (m_0c.Get() != 0 && (unsigned int)aiIndex < m_0c.Get()->Count())
    {
        *apPair = *m_0c.Get()->Find(aiIndex, &out)->Step()->Fetch();
        return true;
    }
    return false;
}

struct PathSerializationData : DetailedActorPathHandler
{
    void Serialize(BGSSaveFormBuffer* archive);
};
// @fnv 0x009e8f80
void PathSerializationData::Serialize(BGSSaveFormBuffer* archive)
{
    archive->FUN_00865e50(&m_kPathVector1, 12, 0);
    archive->FUN_00865e50(&m_kPathVector2, 12, 0);
    archive->FUN_00865e50(&m_kPathVector3, 12, 0);
    archive->FUN_00865e50(&m_kActorPosition, 12, 0);
    archive->FUN_00865e50(&m_kPathVector4, 12, 0);
    archive->FUN_00865e50(&ByteAndFlagState, 4, 0);
    archive->FUN_00865e50(&m_uiPathPointIndex, 4, 0);
    archive->FUN_00865e50(&m_fPathValue1, 4, 0);
    archive->FUN_00865e50(&m_fPathValue2, 4, 0);
    archive->FUN_00865e50(&m_fSplineParameter, 4, 0);
    archive->FUN_00865e50(&m_fPathValue4, 4, 0);
    archive->FUN_00865e50(&m_fPathValue5, 4, 0);
    archive->FUN_00865e50(&m_iPathValue1, 4, 0);
    archive->FUN_00865e50(&m_fPathValue6, 4, 0);
    archive->FUN_00865e50(&m_fPathValue7, 4, 0);
    archive->FUN_00865e50(&m_fPathValue8, 4, 0);
    archive->FUN_00865e50(&m_fPathValue9, 4, 0);
    archive->FUN_00865e50(&m_fPathValue10, 4, 0);
    archive->FUN_00865e50(&m_fPathValue11, 4, 0);
    archive->FUN_00865e50(&m_fPathValue12, 4, 0);
    archive->FUN_00865e50(&m_fPathValue13, 4, 0);
    archive->FUN_00865e50(&m_fPathValue14, 4, 0);
    archive->FUN_00865e50(&m_fPathValue15, 4, 0);
    archive->FUN_00865e50(&m_fPathValue16, 4, 0);
    archive->FUN_00865e50(&m_fPathValue17, 4, 0);
    archive->FUN_00865e50(pad14, 4, 0);
    archive->FUN_00865e50(pad14 + 4, 4, 0);
    archive->FUN_00865e50(&eState, 4, 0);
    archive->FUN_00865e50(&m_iPathParameter1, 4, 0);
    archive->FUN_00865e50(&m_iPathParameter2, 4, 0);
    archive->FUN_00865e50(&m_iPathValue2, 4, 0);
    archive->FUN_00865e50(&m_bPathFlag1, 1, 0);
    archive->FUN_00865e50(&m_bPathFlag2, 1, 0);
    archive->FUN_00865e50(&m_bPathFlag3, 1, 0);
    archive->FUN_00865e50(&m_bPathFlag4, 1, 0);
    archive->FUN_00865e50(&m_bPathFlag5, 1, 0);
    archive->FUN_00865e50(&m_bPathFlag7, 1, 0);
    archive->FUN_00865e50(&m_bPathFlag6, 1, 0);
    archive->FUN_00865e50(&m_bHasPathingSolution, 1, 0);
    archive->FUN_00865e50(&m_bPathingRequestPending, 1, 0);
    archive->FUN_00865e50(&m_fElapsedTime, 4, 0);
    archive->FUN_00865e50(&m_kPathVector5, 12, 0);
    archive->FUN_00865e50(&m_fPathValue18, 4, 0);
    archive->FUN_00865df0(m_pPathTargetReference, 0);
    unsigned int count = 0;
    unsigned int token = archive->StartVariableSizedValue();
    BSSimpleList<TESTopicInfo*>* node = &ActorAvoidEntryList;
    while (node != 0)
    {
        void* item = node->GetItem();
        if (item != 0)
        {
            archive->FUN_00865df0(item, 0);
            count = count + 1;
        }
        node = node->GetNext();
    }
    archive->SaveVariableSizedValue_00865ff0(count, token);
}


// @fnv 0x009e98d0
template <>
Actor* NiTArray<Actor*, NiTMallocInterface<Actor*> >::RemoveAt(unsigned int index)
{
    if (index >= m_usSize)
    {
        return 0;
    }
    Actor* item = m_pBase[index];
    m_pBase[index] = 0;
    if (item != 0)
    {
        m_usESize--;
    }
    if (index == (unsigned short)(m_usSize - 1))
    {
        m_usSize--;
    }
    return item;
}

// The approved smart pointer has no equality overload for the original 0x009e0190 call.
struct PathSolutionComparisonQueries : NiPointer<PathingSolution>
{
    bool operator==(void*) const;
};
extern const NiPoint3 pathZero;

// @fnv 0x009e0190
DetailedActorPathHandler::DetailedActorPathHandler(void* apActor, void* apMover, NiPointer<PathingSolution>* apPathPtr, void* apRequest)
    : ActorPathHandler(apActor, apMover, apPathPtr, apRequest), m_kPathVector1(pathZero), m_kPathVector3(pathZero),
      m_kActorPosition(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F), m_kPathVector4(pathZero)
{
    ByteAndFlagState = 0;
    m_fPathValue9 = 1.0f;
    m_fPathValue11 = -1.0f;
    m_fPathValue5 = 0.0f;
    m_fPathValue17 = 0.0f;
    m_bPathFlag4 = 0;
    m_bPathFlag5 = 0;
    m_bPathFlag7 = 0;
    m_bPathFlag6 = 0;
    if (*(PathSolutionComparisonQueries*)apPathPtr == 0 && apRequest == 0)
        eState = 5;
    else
        eState = 0;
    m_iPathParameter1 = 0;
    m_fPathValue10 = 0.0f;
    m_iPathParameter2 = 0;
    m_uiPathPointIndex = 0;
    m_fPathValue14 = 0.0f;
    m_fPathValue16 = 0.0f;
    m_fPathValue2 = 0.0f;
    m_fSplineParameter = 0.0f;
    *(float*)pad14 = 10.0f;
    *(float*)(pad14 + 4) = 20.0f;
    m_pPathTargetReference = 0;
    m_bHasPathingSolution = 0;
    m_bPathingRequestPending = 0;
    m_fElapsedTime = 0.0f;
    m_fPathValue18 = 0.0f;
}

struct P3Update
{
    float x, y, z;
    static const P3Update ZERO;
    P3Update operator-(const P3Update&) const;
    float Length() const;
    float Dot(const P3Update&) const;
    P3Update& operator*=(float);
    void Normalize();
};
struct PointLocation
{
    bool Valid();
    P3Update Point() const;
};
struct UpdateNode
{
    PointLocation* Location();
};
struct UpdateNodeList
{
    bool IsFinal();
    UpdateNode* Last();
    UpdateNode* Goal();
    unsigned Count();
};
struct UpdateRequest
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
    int unkac;
    UpdateRequest();
    static void* operator new(unsigned);
    void CopyTo(UpdateRequest*);
    void SetDestination(PointLocation*);
    PointLocation* Destination();
    void Prepare();
};
struct UpdatePtr
{
    UpdateRequest* ptr;
    UpdatePtr(UpdateRequest*);
    ~UpdatePtr();
    operator UpdateRequest*() const;
};
struct SolutionPtr
{
    UpdateNodeList* ptr;
    operator UpdateNodeList*() const;
    SolutionPtr& operator=(UpdateNodeList*);
};
struct RequestPtr
{
    UpdateRequest* ptr;
    operator UpdateRequest*() const;
};
struct UpdateController
{
    int Mode();
    float FallTime();
};
struct UpdateActor
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual P3Update& Position();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual float Heading(bool);
    virtual void slot176();
    virtual void SetFurnitureHeading(float);
    bool Active();
    UpdateController* Controller();
};
struct UpdatePlayer
{
    bool IsSleepingOrResting();
};
extern UpdatePlayer* _g_thePlayer;
struct UpdateFloatSetting
{
    float* Float();
};
struct UpdateBoolSetting
{
    bool* Bool();
};
extern UpdateFloatSetting g_011f2b2c;
extern UpdateBoolSetting g_011f2bb8;
struct UpdateMatrix
{
    float m0;
    float m1;
    float m2;
    float m3;
    float m4;
    float m5;
    float m6;
    float m7;
    float m8;
    UpdateMatrix();
    void SetAngle(float);
    P3Update Transform(const P3Update*);
};
struct UpdateHandler
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual int SleepingUpdate(float);
    UpdateActor* actor;
    ActorMover* mover;
    SolutionPtr path;
    RequestPtr request;
    int unk14;
    int unk18;
    P3Update delta, blocked, tether, last, lastTether;
    int avoidList0, avoidList1;
    unsigned moveMode, nodeIndex;
    float rotateGoal, pathLength, splineT, avoidanceTimer, detection;
    int unblock;
    float facing, blockedAngle, blockTime, timeAnim, runWalkTime, minRotate, waitTime, lastMinDelta;
    P3Update lastDelta;
    float goalRadius, fallTime, distance, ignoreTimer, rotation;
    bool ignoreInitial, keepHeading;
    float ignoreTether;
    int state, blend, avoidState, doorState;
    void* door;
    bool rotateMode, rotateCCW, movementBlocked, endUpdate, waiting, ignoreLook, computed;
    int UpdateMovementState(float dt);
    int CheckPath();
    void Clear();
    bool PathReady();
    void UpdatePath(float);
    float Rotate(float);
    void Angles(float*, float*);
    void ApplyRotation(float, float);
    int Detect(float);
    int CheckState();
    void UpdateMovement(float);
    bool CanMove(float);
    void ScaleMovement(float);
    float Speed(float, float*);
    void UpdateDelta(float);
};
// Runs the actor's per-frame movement update: checks state, controller, path and avoidance, then updates delta, rotation and movement.
// @fnv 0x009e0a00
int UpdateHandler::UpdateMovementState(float afDeltaTime)
{
    if (state == 5 || state == 6)
        return 5;

    if (!actor->Active())
    {
        if ((UpdateNodeList*)path)
        {
            int result = CheckPath();

            if (result == 5)
            {
                Clear();
                state = 5;
                return result;
            }
        }
        return 0;
    }
    computed = true;

    UpdateController* e = actor->Controller();

    if (afDeltaTime == 0.0 || e == 0)
    {
        Clear();
        return 0;
    }
    if (_g_thePlayer->IsSleepingOrResting())
        return SleepingUpdate(afDeltaTime);

    if (e->Mode() == 2)
    {
        fallTime = e->FallTime();

        if (fallTime > 0.40000000596046448)
        {
            Clear();
            return 0;
        }
    }
    else
    {
        if (fallTime > 0.64999997615814209)
        {
            Clear();
            return 4;
        }
        fallTime = 0.0f;
    }
    if (!rotateMode && !waiting)
    {
        int result = CheckPath();

        if (result != 0 && (result != 5 || !PathReady()))
        {
            Clear();
            state = 5;
            return result;
        }
    }
    if (!waiting)
        UpdatePath(afDeltaTime);

    if (ignoreInitial && splineT >= ignoreTether)
    {
        ignoreInitial = false;
        keepHeading = false;
        ignoreTether = 0.0f;
    }
    if (rotateMode)
    {
        float c = Rotate(afDeltaTime);
        actor->SetFurnitureHeading(c);

        float j = 0.0f;
        float e = 0.0f;

        Angles(&j, &e);
        ApplyRotation(afDeltaTime, e);

        delta = P3Update::ZERO;
        lastMinDelta = 0.0f;
        lastDelta = P3Update::ZERO;

        mover->FUN_00483710();
        return 0;
    }
    if (state == 4)
    {
        Clear();
        return 0;
    }
    if (avoidState == 2)
    {
        waitTime -= afDeltaTime;

        if (waitTime > 0.0)
        {
            int result = Detect(afDeltaTime);

            if (result == 0)
            {
                avoidanceTimer -= afDeltaTime;

                if (avoidanceTimer <= 0.0)
                {
                    waitTime = 0.0f;
                    avoidState = 1;
                }
            }
            else if (result == 3)
            {
                Clear();
                return 1;
            }
            else
                avoidanceTimer = *g_011f2b2c.Float();
        }
        else
        {
            waitTime = 0.0f;
            avoidState = 1;
        }
        Clear();
        return 0;
    }
    switch (CheckState())
    {
    case 1:
        Clear();
        return 0;
        break;

    case 2:
        Clear();
        return 3;
    }
    UpdateMovement(afDeltaTime);

    if (!CanMove(afDeltaTime))
    {
        if (state == 4)
        {
            Clear();
            return 0;
        }
        avoidState = 5;
        return 1;
    }
    ScaleMovement(afDeltaTime);

    if (*g_011f2bb8.Bool())
    {
        if (!movementBlocked)
        {
            int result = Detect(afDeltaTime);

            if (result != 0)
            {
                detection = 0.0f;

                switch (result)
                {
                case 3:
                    Clear();
                    return 1;
                    break;

                case 1:
                    avoidState = 2;
                    Clear();
                    return 0;
                    break;

                case 2: {
                    UpdatePtr newRequest = new UpdateRequest;

                    ((UpdateRequest*)request)->CopyTo(newRequest);

                    if (!(UpdateNodeList*)path)
                    {
                        avoidState = 2;
                        Clear();
                        return 0;
                    }
                    else
                    {
                        if (!((UpdateNodeList*)path)->IsFinal())
                            ((UpdateRequest*)newRequest)->SetDestination(((UpdateNodeList*)path)->Last()->Location());

                        else
                        {
                            if (!((UpdateRequest*)request)->Destination()->Valid())
                                ((UpdateRequest*)newRequest)->SetDestination(((UpdateRequest*)request)->Destination());

                            else
                                ((UpdateRequest*)newRequest)
                                    ->SetDestination(((UpdateNodeList*)path)->Last()->Location());
                        }
                    }
                    ((UpdateRequest*)newRequest)->Prepare();
                    avoidState = 3;

                    mover->BackGroundBuildPath((const PathingRequest*)(UpdateRequest*)newRequest);

                    if (mover->eState == 6)
                    {
                        Clear();
                        waiting = false;
                        state = 5;
                    }
                    if (waiting)
                    {
                        path = 0;

                        if (state == 4)
                        {
                            Clear();
                            return 0;
                        }
                    }
                    else
                        avoidState = 1;
                }
                break;
                }
            }
        }
        if (avoidState == 4)
        {
            avoidanceTimer -= afDeltaTime;

            if (avoidanceTimer < 0.0)
            {
                avoidanceTimer = 0.0f;
                avoidState = 1;
            }
        }
    }
    float j = 0.0f;

    float c = Speed(afDeltaTime, &j);
    actor->SetFurnitureHeading(c);

    mover->FUN_00483710();

    if (j > 0.0)
        delta *= j;

    UpdateDelta(afDeltaTime);

    lastMinDelta = delta.Length();

    UpdateMatrix l;

    l.SetAngle(actor->Heading(false));

    lastDelta = l.Transform(&delta);

    if (state == 3)
    {
        P3Update c = tether - lastTether;

        c.z = 0.0f;

        P3Update j = tether - actor->Position();

        j.z = 0.0f;

        float e = c.Dot(j);

        if (e <= 0.0)
            state = 4;

        return 0;
    }
    if ((UpdateNodeList*)path && nodeIndex + 1 >= ((UpdateNodeList*)path)->Count())
    {
        float remaining = (actor->Position() - ((UpdateNodeList*)path)->Goal()->Location()->Point()).Length();

        if (lastMinDelta > remaining)
        {
            float savedZ = delta.z;

            delta.Normalize();
            delta.x *= remaining;
            delta.y *= remaining;
            delta.z = savedZ;

            lastMinDelta = delta.Length();
            lastDelta = delta;
        }
    }
    return 0;
}

namespace fnv_009e20c0 {

struct RequestView
{
    bool Ready() const;
};
TESObjectREFR* LookupDoor(unsigned int);
int OpenState(TESObjectREFR*);
struct DoorHandler : DetailedActorPathHandler
{
    bool CanOpen(unsigned int);
    int UpdateDoorState();
};
// @fnv 0x009e20c0
int DoorHandler::UpdateDoorState()
{
    switch (m_iPathValue2)
    {
    case 0:
        if (m_pActorMover->unk2C)
        {
            TESForm* form = LookupDoor(m_pActorMover->unk2C);
            if (form && form->GetIsReference())
            {
                TESObjectREFR* door = (TESObjectREFR*)form;
                int status = OpenState(door);
                switch (status)
                {
                case 3:
                    if (!((RequestView*)((NiPointer<RequestView>&)m_pPathingRequest))->Ready() && CanOpen(door->GetHavokWorldObjectCountInSceneGraph_0084e3a0()))
                    {
                        if (!door->Activate(pActor, false, (TESBoundObject*)0, 1))
                            m_iPathValue2 = 2;
                        else
                        {
                            ((TESObjectREFR*&)m_pPathTargetReference) = door;
                            ((TESObjectREFR*&)m_pPathTargetReference)->TESObjectREFR_SetTargeted(true);
                            m_iPathValue2 = 1;
                        }
                    }
                    return m_iPathValue2;
                    break;
                default:
                    return 0;
                }
            }
        }
        break;
    case 1:
        if (!((TESObjectREFR*&)m_pPathTargetReference))
        {
            m_iPathValue2 = 2;
            return m_iPathValue2;
        }
        {
            int nextStatus = OpenState(((TESObjectREFR*&)m_pPathTargetReference));
            switch (nextStatus)
            {
            case 2:
                return 1;
                break;
            case 1:
                ((TESObjectREFR*&)m_pPathTargetReference) = 0;
                m_iPathValue2 = 0;
                return m_iPathValue2;
            default:
                return 0;
            }
        }
        break;
    case 2:
        return 2;
        break;
    default:
        m_iPathValue2 = 0;
        return m_iPathValue2;
    }
    m_iPathValue2 = 0;
    return m_iPathValue2;
}
}  // namespace fnv_009e20c0


struct FUN_006dcd70
{
    int aiData[10];
    FUN_006dcd70(TESObjectREFR* apRef);
    FUN_006dcd70(const NiPoint3& arPoint, TESObjectREFR* apRef);
    ~FUN_006dcd70();
    void FUN_006dd6f0(int a1);
    bool FUN_006dd640(NiPointer<NavMesh>& aspNavMesh, unsigned short& ausTriangle);
};

void __cdecl FUN_006d7490(FUN_006dcd70* apLocation, void* apPoint, int a3, FUN_009e2690* apFilter);
unsigned int __fastcall GetObjectFlags(char* apPath);

struct FUN_006e7a10_Class
{
    void GetLocationAtSplineParameter(float afT, NiPoint3& arPoint);
};

struct FUN_009e22d0_shell : public DetailedActorPathHandler
{
    bool DetailedActorPathHandler_IsDoorInPath(unsigned int auiFlags);
};

// @fnv 0x009e22d0
// src: XBOX_PDB 0x009e22d0
bool FUN_009e22d0_shell::DetailedActorPathHandler_IsDoorInPath(unsigned int auiFlags)
{
    if (!(PathingSolution*)pCurrentPathingSolution)
    {
        FUN_009e2690 kFilterTmp(auiFlags);
        FUN_006dcd70 _kLocation((TESObjectREFR*)pActor);
        _kLocation.FUN_006dd6f0(0);
        NiPointer<NavMesh> spNavMeshCur;
        unsigned short uTmpsTriangle;
        if (_kLocation.FUN_006dd640(spNavMeshCur, uTmpsTriangle))
        {
            NavMeshTriangle* pTriangle = ((NavMesh*)spNavMeshCur)->GetTriangle(uTmpsTriangle);
            if (!pTriangle)
            {
            }
            else
            {
                kFilterTmp.f10 = pTriangle->GetFlag(0x1000);
            }
        }
        FUN_006d7490(&_kLocation, &m_kPathVector3, 0, &kFilterTmp);
        if (kFilterTmp.f8 || kFilterTmp.f9 || kFilterTmp.f10)
            return true;
        else
            return false;
    }
    else
    {
        if (!((FUN_009e2660_Class*)(PathingSolution*)pCurrentPathingSolution)->Contains(auiFlags))
        {
            for (float aFT = 0.0f; GetObjectFlags((char*)(PathingSolution*)pCurrentPathingSolution) - 1.0 > aFT;
                 aFT += 0.5)
            {
                float fNextTCur = aFT + 0.5;
                NiPoint3 kStart4;
                NiPoint3 kEnd2;
                ((FUN_006e7a10_Class*)(PathingSolution*)pCurrentPathingSolution)
                    ->GetLocationAtSplineParameter(aFT, kStart4);
                ((FUN_006e7a10_Class*)(PathingSolution*)pCurrentPathingSolution)
                    ->GetLocationAtSplineParameter(fNextTCur, kEnd2);
                FUN_009e2690 kSegFilterCur(auiFlags);
                FUN_006dcd70 kSegLocation3(kStart4, (TESObjectREFR*)pActor);
                kSegLocation3.FUN_006dd6f0(0);
                NiPointer<NavMesh> spSegNavMeshCur;
                unsigned short usSegTriangle3;
                if (kSegLocation3.FUN_006dd640(spSegNavMeshCur, usSegTriangle3))
                {
                    NavMeshTriangle* pSegTriangle = ((NavMesh*)spSegNavMeshCur)->GetTriangle(usSegTriangle3);
                    if (!pSegTriangle)
                    {
                    }
                    else
                    {
                        kSegFilterCur.f10 = pSegTriangle->GetFlag(0x1000);
                    }
                }
                FUN_006d7490(&kSegLocation3, &kEnd2, 0, &kSegFilterCur);
                if (kSegFilterCur.f8 || kSegFilterCur.f9 || kSegFilterCur.f10)
                    return true;
            }
            return false;
        }
        else
            return true;
    }
}

struct PathAngleActor : Actor
{
    float FUN_008be1b0();
    bool IsSwimming_005a2030() const;
};
NiPoint3 __cdecl CombatUtilities_GetAttackerFiringLocation(Actor*);
NiPoint3 __cdecl CombatUtilities_GetAngleToProjectedPoint(Actor*, NiPoint3);
float __cdecl GetDirectionAngle(const NiPoint3&);
struct PathAngles : DetailedActorPathHandler
{
    void GetPathAngles(float&, float&);
};
// Computes a heading angle and a looking angle from the actor's pathing solution or mover and writes them to headingOut and lookingOut.
// @fnv 0x009e4450
void PathAngles::GetPathAngles(float& headingOut, float& lookingOut)
{
    float angle = 0.0f;
    float looking = 0.0f;
    if (m_bPathFlag3)
    {
        angle = m_fPathValue6;
    }
    else if (m_bHasPathingSolution)
    {
        if (m_bPathingRequestPending)
        {
            angle = pActor->GetCurrentTargetDistance(false);
        }
        else if (pCurrentPathingSolution)
        {
            NiPoint3 target;
            ((PathingSolution*)(PathingSolution*)pCurrentPathingSolution)
                ->GetLocationAtSplineParameter(m_fElapsedTime, (NiPoint3&)target);
            NiPoint3 delta = target.SubtractIntoVector(*(const NiPoint3*)((const Actor*)pActor)->GetPos());
            delta.z = 0.0f;
            angle = GetDirectionAngle((const NiPoint3&)delta);
        }
        else
        {
            angle = pActor->GetCurrentTargetDistance(false);
        }
    }
    else if (!m_bPathFlag6 && ((ActorMover*)m_pActorMover)->HasLookAtTarget())
    {
        NiPoint3 target;
        ((ActorMover*)m_pActorMover)->GetLookAtTargetPosition((NiPoint3&)target);
        NiPoint3 position = CombatUtilities_GetAttackerFiringLocation(pActor);
        if (position.SubtractIntoVector(target).GetSquaredXYLength() <
            ((PathAngleActor*)pActor)->FUN_008be1b0() * ((PathAngleActor*)pActor)->FUN_008be1b0() * 0.25)
        {
            angle = pActor->GetCurrentTargetDistance(false);
        }
        else
        {
            NiPoint3 angles = CombatUtilities_GetAngleToProjectedPoint(pActor, target);
            if (!((PathAngleActor*)pActor)->IsSwimming_005a2030())
                looking = angles.x;
            if (((PathAngleActor*)pActor)->FUN_008be1b0() >= 100.0)
            {
                NiPoint3 delta = target.SubtractIntoVector(*(const NiPoint3*)((const Actor*)pActor)->GetPos());
                delta.z = 0.0f;
                angle = GetDirectionAngle((const NiPoint3&)delta);
            }
            else
            {
                angle = angles.z;
            }
        }
    }
    else
    {
        NiPoint3 destination;
        if (pCurrentPathingSolution && ((PathingSolution*)pCurrentPathingSolution)->GetNodeCount() > 0)
        {
            ((PathingSolution*)(PathingSolution*)pCurrentPathingSolution)
                ->GetLocationAtSplineParameter(float(m_fSplineParameter + 0.10000000149011612), (NiPoint3&)destination);
        }
        else
        {
            (NiPoint3&)destination = m_kPathVector3;
        }
        NiPoint3 direction = destination.SubtractIntoVector(*(const NiPoint3*)((const Actor*)pActor)->GetPos());
        if (((PathAngleActor*)pActor)->IsSwimming_005a2030() &&
            direction.FUN_00457990() * 0.949999988079071 <= std::abs(direction.z))
        {
            angle = pActor->GetCurrentTargetDistance(false);
        }
        else
        {
            angle = GetDirectionAngle((const NiPoint3&)direction);
        }
        if (((PathAngleActor*)pActor)->IsSwimming_005a2030())
            looking = 0.0f;
    }
    headingOut = angle;
    lookingOut = looking;
}

struct MotionVec
{
    float x, y, z;
    MotionVec operator-(const MotionVec&) const;
    float Horizontal();
    float Length();
    float Squared();
    float FullLength();
    double Dot(const MotionVec&);
};

struct CollisionObjectView
{
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
    virtual bool IsObstacle();
};
struct CollidableView
{
    void* bhkCharacterController_GetNiObject();
};
struct ControllerView
{
    CollidableView* bhkCharacterController_GetBumpedCharacterController();
};
CollisionObjectView* __cdecl TESObjectREFR_FindReferenceFor3D(void*);
struct MotionActor
{
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
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual Animation* GetAnimation();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const MotionVec& GetPosition();
    bool IsSwimming_005a2030();
    ControllerView* FUN_009306d0();
    TESWorldSpace* TESObjectREFR_GetWorldSpace();
    TESObjectCELL* FUN_008d6f30();
};
struct RequestView
{
    float GetFloatAtOffset68(float);
};
struct RequestPtrView
{
    RequestView* operator->();
};
struct AvoidSphereView
{
    MotionVec& FUN_006815c0();
    float FUN_004a7bd0();
    float GetFloatAtOffset1C();
    void CombatLocation_SetRadius(float);
    void ActiveEffect_SetMagnitude(float);
};
struct MeshView
{
    void FUN_00691660(unsigned short, BSSimpleArray<NavMeshStaticAvoidNode*, 1024>&);
    void AddAvoidNode(const MotionVec&, unsigned short, float);
};
struct MeshPtrView
{
    MeshView* pointer;
    MeshPtrView();
    ~MeshPtrView();
    MeshView* operator->();
};
struct LocationView : PathingLocation
{
    LocationView(const MotionVec&, TESObjectCELL*, TESWorldSpace*);
    ~LocationView();
    bool FUN_006dd6f0(int);
    bool FUN_006dd640(MeshPtrView&, unsigned short&);
};
struct MotionTarget
{
    unsigned unk00;
    MotionActor* actor;
    ActorMover* mover;
    unsigned unk0c;
    RequestPtrView request;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    MotionVec target;
    MotionVec lastPosition;
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
    float timer;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    float radius;
    MotionVec lastDelta;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    unsigned unkc4;
    int state;
    unsigned unkcc;
    int mode;
    unsigned unkd4;
    unsigned unkd8;
    unsigned short unkdc;
    bool movementBlocked;
    bool unkdf;
    unsigned unke0;
    bool UpdateMotion(float);
};
// Updates the motion target's timer and blocked state from the actor's movement, and when blocked adjusts avoidance spheres and calls the mover.
// @fnv 0x009e4cf0
bool MotionTarget::UpdateMotion(float afDeltaTime)
{
    bool p = false;
    if (mode == 3 || mode == 4)
        return true;
    MotionVec eb = actor->GetPosition();
    MotionVec i = target - lastPosition;
    MotionVec h = target - eb;
    MotionVec f = eb - lastPosition;
    bool a = false;
    bool s = false;
    if (!actor->IsSwimming_005a2030())
    {
        float cf = 20.0f;
        float q = i.Horizontal();
        float b = i.Length();
        b += cf;
        b *= b;
        float ba = h.Horizontal();
        if (f.Dot(f) < radius * radius * 0.125)
        {
            ControllerView* k = actor->FUN_009306d0();
            if (k)
            {
                CollisionObjectView* j = 0;
                CollidableView* c = k->bhkCharacterController_GetBumpedCharacterController();
                void* e = c ? c->bhkCharacterController_GetNiObject() : 0;
                CollisionObjectView* l = TESObjectREFR_FindReferenceFor3D(e);
                j = l && l->IsObstacle() ? l : 0;
                if (j)
                    s = true;
            }
            a = true;
        }
    }
    else
    {
        float cf = 20.0f;
        float b = i.Squared();
        float q = i.FullLength();
        q += cf;
        q *= q;
        float ba = h.Squared();
        if (f.Dot(f) < lastDelta.Dot(lastDelta) * 0.125)
        {
            ControllerView* k = actor->FUN_009306d0();
            if (k)
            {
                CollisionObjectView* j = 0;
                CollidableView* c = k->bhkCharacterController_GetBumpedCharacterController();
                void* e = c ? c->bhkCharacterController_GetNiObject() : 0;
                CollisionObjectView* l = TESObjectREFR_FindReferenceFor3D(e);
                j = l && l->IsObstacle() ? l : 0;
                if (j)
                    s = true;
            }
            a = true;
        }
    }
    lastPosition = eb;
    if (a)
    {
        if (s)
            timer += afDeltaTime * 0.20000000298023224;
        else
            timer += afDeltaTime;
        if (state == 3)
        {
            state = 4;
            return false;
        }
    }
    else if (!movementBlocked)
    {
        timer = 0.0f;
        return true;
    }
    if (timer > 1.5 && actor->GetAnimation() && actor->GetAnimation()->IsHighestPriority())
        movementBlocked = true;
    if (movementBlocked)
    {
        p = true;
        if (mode == 0 || mode == 1 || mode == 5)
        {
            LocationView location(target, actor->FUN_008d6f30(), actor->TESObjectREFR_GetWorldSpace());
            if (location.FUN_006dd6f0(0))
            {
                MeshPtrView h;
                unsigned short p;
                if (location.FUN_006dd640(h, p))
                {
                    BSSimpleArray<NavMeshStaticAvoidNode*, 1024> f;
                    h->FUN_00691660(p, f);
                    bool eb = true;
                    if (!f.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
                    {
                        for (unsigned a = 0; a < f.GetSize(); ++a)
                        {
                            AvoidSphereView* i = (AvoidSphereView*)f.GetAt(a);
                            if ((i->FUN_006815c0() - target).Squared() < i->FUN_004a7bd0() * i->FUN_004a7bd0())
                            {
                                if (i->FUN_004a7bd0() < 128.0)
                                    i->CombatLocation_SetRadius(i->FUN_004a7bd0() * 2.0f);
                                else
                                    i->ActiveEffect_SetMagnitude(i->GetFloatAtOffset1C() * 10.0);
                                eb = false;
                            }
                        }
                    }
                    if (eb)
                        h->AddAvoidNode(target, p, request->GetFloatAtOffset68(1.0f));
                }
            }
        }
    }
    if (p)
        mover->FUN_00483710();
    return !p;
}

namespace fnv_009e5ae0 {
struct AvoidPoint
{
    float x, y, z;
    AvoidPoint();
    AvoidPoint(float, float, float);
    AvoidPoint operator-(const AvoidPoint&) const;
    AvoidPoint operator+(const AvoidPoint&) const;
    AvoidPoint ProcessAndReturnValue_0053d280(float) const;
    float Length() const;
    float FUN_004a7290() const;
    float GetSquaredXYLength() const;
};
struct AvoidLocation : PathingLocation
{
    AvoidLocation();
    AvoidLocation(void*);
    AvoidLocation(void*, float);
    AvoidLocation(const AvoidLocation&);
    ~AvoidLocation();
    bool IsWithinDistanceOfSameLocation(const AvoidLocation*);
};
struct AvoidanceVectorData
{
    AvoidLocation* FUN_00717e50();
};
struct AvoidPath
{
    AvoidanceVectorData* PathingSolution_GetLastNode();
};
struct AvoidArray;
struct AvoidRequest
{
    bool bhkPickData_GetPickFailed();
    void SetUseSoft(bool);
    float GetFloatAtOffset68();
    void AssignPathingLocation(const AvoidLocation*);
    void FUN_006d61e0(AvoidArray*);
};
struct AvoidFlags
{
    unsigned int value;
    unsigned int FUN_00621270(unsigned int);
};
struct AvoidController
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
    unsigned int unk050;
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
    unsigned int unk094;
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
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
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
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    AvoidFlags flags;
    float bhkCharacterController_QLODDistance() const;
    void* bhkCharacterProxy_GethkPosition();
};
struct AvoidActor
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
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual AvoidActor* v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const AvoidPoint& v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual int v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float v175(int);
    bool NiAVObject_QFadedIn();
    bool NiNode_QNotVisible() const;
    AvoidController* FUN_009306d0();
    float FUN_008be1b0();
    bool IsMoving_004938e0();
    bool DispatchToReceiver();
    bool Actor_GetCurrentPathfindingGoal_008b3860(AvoidLocation*);
    unsigned int GetVtbl20Result();
    bool FUN_008bc7d0(AvoidActor*);
    const AvoidPoint* GetCachedMoveDelta();
};
struct AvoidRefPath
{
    AvoidPath* p;
    operator AvoidPath*() const;
};
struct AvoidRefRequest
{
    AvoidRequest* p;
    operator AvoidRequest*() const;
};
struct AvoidList
{
    AvoidActor* actor;
    AvoidList* next;
    void FUN_00470470();
    void FUN_005ae3d0(AvoidActor* const&);
    AvoidActor** FUN_006815c0();
    AvoidList* FUN_00726070();
};
struct AvoidElement
{
    AvoidPoint point;
    NiPoint3 velocity;
    float distance;
    float timer;
    int mode;
    AvoidElement(const AvoidPoint&, float, float, int);
};
struct AvoidArray
{
    void* vtable;
    void* data;
    unsigned int size, capacity, grow, flags;
    static void* operator new(unsigned int);
    AvoidArray();
    void AppendNode(const AvoidElement*);
};
struct AvoidSetting
{
    float* Setting_Float_00403e20();
};
extern AvoidSetting g_011f2bd0, g_011f2b1c, g_011f2b74, g_011f2b2c, g_011f2b3c, g_011f2bc4, g_011f2b5c;
struct AvoidPlayer : AvoidActor
{
};
extern AvoidPlayer* g_thePlayer;
struct AvoidTime
{
    float FUN_0084d030();
};
extern AvoidTime g_timeGlobal;
struct __declspec(align(16)) AvoidQuaternion
{
    unsigned char components[16];
    void FUN_004a3c90(void*);
};
void __cdecl FUN_00458620(AvoidPoint*, const AvoidQuaternion*);
struct AvoidRotation
{
    float matrix[3][3];
    AvoidRotation();
    void SetRotationMatrix(float);
    AvoidPoint FUN_004b4500(const AvoidPoint*);
};
struct AvoidHandler
{
    void* vtable;
    AvoidActor* actor;
    ActorMover* mover;
    AvoidRefPath path;
    AvoidRefRequest request;
    unsigned int unk14, unk18;
    AvoidPoint moveDelta, blockedTarget, tetherTarget, lastLocation, lastTether;
    AvoidList actors;
    unsigned int moveMode, node;
    float rotateGoal, pathLength, splineT, avoidTimer, detectionValue;
    int unblockDirection;
    float alternateFacing, blockedStartAngle, blockTime, timeInAnim, runWalkTime, minRotateTime, waitTime,
        lastFrameMinDelta;
    AvoidPoint lastFrameDelta;
    float goalRadiusSqr, fallTime, distanceTraveled, ignoreLookAtTimer, lastRotation;
    bool ignoreInitialRotation, keepHeading;
    float tetherParam;
    int state, blendRunning, avoidState;
    int UpdateAvoidance(float deltaTime);
};
void __cdecl EvaluateAvoidance(AvoidActor*, AvoidRequest*, unsigned int, const AvoidPoint*, AvoidHandler*,
                               BSSimpleArray<ActorAvoidanceData, 1024>*);
// Evaluates nearby actors and obstacles to update detectionValue and avoidTimer, builds avoid nodes, and returns an avoidance state code (0-3).
// @fnv 0x009e5ae0
int AvoidHandler::UpdateAvoidance(float deltaTime)
{
    AvoidActor* target = actor->v116();
    if (!target || !target->NiAVObject_QFadedIn() ||
        (target->NiNode_QNotVisible() && actor->FUN_009306d0()->bhkCharacterController_QLODDistance() > *g_011f2bd0.Setting_Float_00403e20()))
        return 0;
    if (avoidState != 2 && moveDelta.GetSquaredXYLength() < 0.25)
        return 0;
    if (avoidState != 4 && avoidState != 3)
        actors.FUN_00470470();
    AvoidActor* destination = (AvoidActor*)DetailedActorPathHandler_GetFollowLeader((TES*)actor);
    BSSimpleArray<ActorAvoidanceData, 1024> contacts;
    AvoidPoint direction = moveDelta;
    if (avoidState == 2)
        direction = AvoidPoint(0.0f, 1.0f, 0.0f);
    EvaluateAvoidance(actor, request, moveMode, &direction, this, &contacts);
    BSSimpleArray<Actor*, 1024> nearbyActors;
    bool blocked = false;
    bool includesPlayer = false;
    for (unsigned int i = 0; i < contacts.GetSize(); ++i)
    {
        AvoidActor* obstacle = (AvoidActor*)contacts.GetElement(i).pActor;
        float weight = contacts.GetElement(i).fValue;
        if (obstacle == g_thePlayer)
        {
            if (g_thePlayer != destination)
            {
                if ((AvoidPath*)path)
                {
                    AvoidLocation end(*((AvoidPath*)path)->PathingSolution_GetLastNode()->FUN_00717e50());
                    if (end.IsWithinDistanceOfSameLocation(&AvoidLocation(g_thePlayer, g_thePlayer->FUN_008be1b0())))
                    {
                        if (((AvoidRequest*)request)->bhkPickData_GetPickFailed())
                            return 3;
                        else
                            ((AvoidRequest*)request)->SetUseSoft(false);
                    }
                }
                detectionValue += weight * deltaTime;
                nearbyActors.Add((Actor*)g_thePlayer);
                includesPlayer = true;
            }
        }
        else
        {
            bool moving = false;
            if (obstacle->IsMoving_004938e0() && !obstacle->DispatchToReceiver())
                moving = true;
            AvoidLocation location;
            if (obstacle->Actor_GetCurrentPathfindingGoal_008b3860(&location))
            {
                if (location.IsWithinDistanceOfSameLocation(
                        &AvoidLocation(actor, ((AvoidRequest*)request)->GetFloatAtOffset68())))
                    moving = false;
            }
            if (moving)
            {
                if (avoidState == 2)
                    return 1;
                detectionValue += weight * deltaTime;
                if (moveMode & 0x200)
                {
                    if (obstacle->GetVtbl20Result() & 0x200)
                        blocked = true;
                    else
                        nearbyActors.Add((Actor* const&)obstacle);
                }
                else if (!actor->FUN_008bc7d0(obstacle))
                {
                    blocked = true;
                    if (detectionValue >= *g_011f2b1c.Setting_Float_00403e20())
                        break;
                }
            }
            else
            {
                if (avoidState == 2)
                    continue;
                detectionValue += 2.0 * weight * deltaTime;
                if (destination && obstacle == destination)
                    blocked = true;
                if ((AvoidPath*)path)
                {
                    AvoidLocation end(*((AvoidPath*)path)->PathingSolution_GetLastNode()->FUN_00717e50());
                    if (end.IsWithinDistanceOfSameLocation(&AvoidLocation(obstacle, obstacle->FUN_008be1b0())))
                    {
                        if (((AvoidRequest*)request)->bhkPickData_GetPickFailed())
                            return 3;
                        else
                            ((AvoidRequest*)request)->SetUseSoft(false);
                    }
                }
                nearbyActors.Add((Actor* const&)obstacle);
            }
        }
    }
    if (avoidState == 2)
        return 0;
    if (detectionValue == 0.0)
        return 0;
    if (detectionValue >= *g_011f2b1c.Setting_Float_00403e20())
    {
        if (blocked)
        {
            waitTime = *g_011f2b74.Setting_Float_00403e20();
            avoidTimer = *g_011f2b2c.Setting_Float_00403e20();
            mover->FUN_00483710();
            return 1;
        }
        if (!nearbyActors.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        {
            if (avoidState != 4 && !includesPlayer && !(moveMode & 0x200))
                avoidTimer = *g_011f2b3c.Setting_Float_00403e20();
            else
                avoidTimer = BSMAX_00404010(avoidTimer, *g_011f2bc4.Setting_Float_00403e20());
            AvoidArray* avoidNodes = new AvoidArray;
            unsigned int count = nearbyActors.GetSize();
            for (unsigned int j = 0; j < count; ++j)
                actors.FUN_005ae3d0((AvoidActor* const&)nearbyActors.GetAt(j));
            float factor = (moveMode & 0x200) ? 1.75f : 1.5f;
            AvoidActor* current = 0;
            AvoidList* list = &actors;
            float radius = ((AvoidRequest*)request)->GetFloatAtOffset68();
            while (list)
            {
                current = *list->FUN_006815c0();
                list = list->FUN_00726070();
                float distanceFactor = 1.0f;
                float distance = (current->v125() - actor->v125()).Length();
                if (distance < current->FUN_008be1b0() + radius)
                    distanceFactor = 1.5f;
                float avoidRadius;
                int mode;
                if (current->v133() == 4 || current->v133() == 9)
                {
                    avoidRadius = current->FUN_008be1b0() * 0.5 * factor;
                    mode = 0;
                }
                else
                {
                    avoidRadius = current->FUN_008be1b0() * factor * distanceFactor;
                    mode = 2;
                }
                AvoidRotation rotation;
                rotation.SetRotationMatrix(current->v175(0));
                AvoidPoint velocity = rotation.FUN_004b4500(current->GetCachedMoveDelta());
                AvoidPoint delta = velocity.ProcessAndReturnValue_0053d280(g_timeGlobal.FUN_0084d030());
                if (delta.FUN_004a7290() > current->FUN_008be1b0())
                    avoidNodes->AppendNode(&AvoidElement(current->v125() + delta, avoidRadius, 2.0f, mode));
                AvoidPoint position = current->v125();
                AvoidController* controller = current->FUN_009306d0();
                if (controller && !controller->flags.FUN_00621270(0x8000000))
                {
                    AvoidQuaternion rotationValue;
                    rotationValue.FUN_004a3c90(controller->bhkCharacterProxy_GethkPosition());
                    AvoidPoint offset;
                    FUN_00458620(&offset, &rotationValue);
                    position.x = offset.x;
                    position.y = offset.y;
                }
                avoidNodes->AppendNode(&AvoidElement(position, avoidRadius, *g_011f2b5c.Setting_Float_00403e20(), mode));
            }
            ((AvoidRequest*)request)->AssignPathingLocation(&AvoidLocation(actor));
            ((AvoidRequest*)request)->FUN_006d61e0(avoidNodes);
            mover->FUN_00483710();
            return 2;
        }
    }
    if (!blocked && nearbyActors.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        detectionValue -= deltaTime;
        if (detectionValue < 0.0)
            detectionValue = 0.0f;
    }
    return 0;
}
}  // namespace fnv_009e5ae0

extern const double DAT_01023128;

class GlobalObject_0044f440
{
  public:
    float* Float();
};
extern GlobalObject_0044f440 g_011f2ac4;
extern GlobalObject_0044f440 g_011f2ad8;
extern GlobalObject_0044f440 g_011f2b10;
extern GlobalObject_0044f440 g_011f2c10;

struct FUN_008843a0_shell
{
    bool Actor_CanMove();
};

struct FUN_00493bb0_shell
{
    bool Actor_IsInCombat();
};


struct VCallHelper_354 : public VCallHelper_2bc
{
    virtual void e176();
    virtual void e177();
    virtual void e178();
    virtual void e179();
    virtual void e180();
    virtual void e181();
    virtual void e182();
    virtual void e183();
    virtual void e184();
    virtual void e185();
    virtual void e186();
    virtual void e187();
    virtual void e188();
    virtual void e189();
    virtual void e190();
    virtual void e191();
    virtual void e192();
    virtual void e193();
    virtual void e194();
    virtual void e195();
    virtual void e196();
    virtual void e197();
    virtual void e198();
    virtual void e199();
    virtual void e200();
    virtual void e201();
    virtual void e202();
    virtual void e203();
    virtual void e204();
    virtual void e205();
    virtual void e206();
    virtual void e207();
    virtual void e208();
    virtual void e209();
    virtual void e210();
    virtual void e211();
    virtual void e212();
    virtual float v213();
};

struct FUN_009e7d70_shell : public DetailedActorPathHandler
{
    float DetailedActorPathHandler_UpdateRotation(float a2);
};

// @fnv 0x009e7d70
// src: XBOX_PDB 0x009e7d70
float FUN_009e7d70_shell::DetailedActorPathHandler_UpdateRotation(float afDeltaTime)
{
    float var_8 = ((VCallHelper_2bc*)this->pActor)->v175(0);
    if (!((FUN_008843a0_shell*)this->pActor)->Actor_CanMove())
    {
        this->ByteAndFlagState = this->m_pActorMover->GetPreferredMoveModeType();
        return var_8;
    }
    WrapValueToRange(var_8, -3.1415927f, 3.1415927f);
    float var4 = this->m_fPathValue1 - var_8;
    WrapValueToRange(var4, -3.1415927f, 3.1415927f);
    bool var2 = var4 > _gModifierZero;
    if (std::abs(var4) > DAT_01023128)
    {
        float var_10 = ((VCallHelper_354*)this->pActor)->v213() * DAT_01023128 * afDeltaTime;
        if (!this->pActor->IsCreature())
        {
            var_10 *= ((FUN_00493bb0_shell*)this->pActor)->Actor_IsInCombat() ? *g_011f2ac4.Float() : *g_011f2ad8.Float();
        }
        else
        {
            var_10 *= ((FUN_00493bb0_shell*)this->pActor)->Actor_IsInCombat() ? *g_011f2b10.Float() : *g_011f2c10.Float();
        }
        if (var_10 > std::abs(var4))
        {
            var_8 = this->m_fPathValue1;
            if (this->m_fPathValue11 <= _gModifierZero)
            {
                this->m_bPathFlag1 = false;
                ((ActorMover*)this->m_pActorMover)->FUN_00483710();
            }
        }
        else
        {
            if (this->m_bPathFlag2)
            {
                this->ByteAndFlagState = this->m_pActorMover->GetPreferredMoveModeType() | 0x20;
                var_8 += var_10;
            }
            else
            {
                this->ByteAndFlagState = this->m_pActorMover->GetPreferredMoveModeType() | 0x10;
                var_8 -= var_10;
            }
        }
    }
    else
    {
        var_8 = this->m_fPathValue1;
        if (this->m_fPathValue11 <= _gModifierZero)
        {
            this->m_bPathFlag1 = false;
            ((ActorMover*)this->m_pActorMover)->FUN_00483710();
        }
    }
    this->m_fPathValue11 -= afDeltaTime;
    return var_8;
}

struct PosX
{
    float x, y, z;
    PosX SubtractIntoVector(const PosX& r) const;
    float NiPoint3_XYLength() const;
};

// The original calls 0x008BE350 with an x87 double result; Actor.h lacks that declaration.
struct PathClearanceQuery : Actor
{
    double Actor_GetLength();
};

struct LocX
{
    PosX FUN_005c3420();
};
struct CellX
{
    LocX* FUN_00717e50();
};
struct ProcX
{
    bool IsIncomplete();
    unsigned GetObjectFlags();
    CellX* PathingSolution_GetLastNode();
};
struct ProcPtr
{
    ProcX* p;
    ProcX* Modelloader_GetReferencedThis();
};
struct TgtX
{
    float GetFloatAtOffset68();
};
struct TgtPtr
{
    TgtX* p;
    TgtX* Modelloader_GetReferencedThis();
};
struct DoorX
{
    bool FUN_00691140(int i);
};
struct NodeX
{
    DoorX* FUN_005582f0(unsigned short us);
};
struct NodePtr
{
    NodeX* p;
    NodePtr();
    ~NodePtr();
    NodeX* Modelloader_GetReferencedThis();
};
struct ResultX
{
    int a, b;
    bool b8, b9, ba;
    char pad;
    ResultX(int i);
};
struct WalkX
{
    int pad[10];
    WalkX(Actor* p);
    ~WalkX();
    void FUN_006dd6f0(int i);
    bool FUN_006dd640(NodePtr* p, unsigned short* pus);
};
void __cdecl FUN_006d7490(WalkX* w, PosX* p, int i, ResultX* r);
struct PlanX
{
    void MoveActorToLocation(PosX* p);
};
struct PkgX
{
    int m0;
    Actor* m4;
    PlanX* m8;
    ProcPtr mc;
    TgtPtr m10;
    int pad14[8];
    PosX m34;
    void AdvanceAlongPath(float f);
    bool IsPathClear();
};
// Checks if the actor can advance to the target by verifying distance, cell proximity, and path walkability, updating the plan if clear.
// @fnv 0x009e8800
bool PkgX::IsPathClear()
{
    if (m10.Modelloader_GetReferencedThis() && m10.Modelloader_GetReferencedThis()->GetFloatAtOffset68() > 100.0)
        return false;
    float fNear_u = 64.0f;
    float fNearSq_chdcf = fNear_u * fNear_u;
    float fFar_nezo = 128.0f;
    float fFarSq_abpnoy = fFar_nezo * fFar_nezo;
    float fDistTmp = m34.SubtractIntoVector(*(PosX*)((const Actor*)m4)->GetPos()).NiPoint3_XYLength();
    float fMin_knckj = 0.0f;
    if (mc.Modelloader_GetReferencedThis()->IsIncomplete())
        fMin_knckj = ((PathClearanceQuery*)m4)->Actor_GetLength() * 0.6f;
    if (mc.Modelloader_GetReferencedThis()->GetObjectFlags() > 0)
    {
        if (fDistTmp < fFar_nezo)
            AdvanceAlongPath(fFar_nezo - fDistTmp);
        fDistTmp = m34.SubtractIntoVector(*(PosX*)((const Actor*)m4)->GetPos()).NiPoint3_XYLength();
        float fCell_kdfu =
            mc.Modelloader_GetReferencedThis()->PathingSolution_GetLastNode()->FUN_00717e50()->FUN_005c3420().SubtractIntoVector(m34).NiPoint3_XYLength();
        if (fDistTmp < fNear_u || fCell_kdfu < fMin_knckj)
        {
            return false;
        }
        else
        {
            ResultX kResult4(0);
            WalkX kWalk(m4);
            kWalk.FUN_006dd6f0(0);
            NodePtr aSpNode;
            unsigned short usIdx;
            if (kWalk.FUN_006dd640(&aSpNode, &usIdx))
            {
                DoorX* pkDoor3 = aSpNode.Modelloader_GetReferencedThis()->FUN_005582f0(usIdx);
                if (!pkDoor3)
                {
                }
                else
                {
                    kResult4.ba = pkDoor3->FUN_00691140(0x1000);
                }
            }
            FUN_006d7490(&kWalk, &m34, 0, &kResult4);
            if (kResult4.b8 || kResult4.b9 || kResult4.ba)
            {
                return false;
            }
            else
            {
                m8->MoveActorToLocation(&m34);
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}

namespace fnv_009e8b50 {

struct Obj4
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
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* v125();
};
struct Ctx
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void v5(int a, int b, const char* s, ...);
};
void __cdecl FUN_00406d30(char* d, int n, const char* s);
void __cdecl FUN_00406d50(char* d, int n, const char* s);
void __cdecl BSsprintf(char* d, int n, const char* s, ...);
struct PFThis
{
    int f00;
    Obj4* f04;
    int f008, f00c, f010, f014, f018, f01c, f020, f024, f028, f02c, f030, f034, f038, f03c, f040, f044, f048, f04c,
        f050, f054, f058, f05c, f060, f064, f068, f06c, f070, f074;
    float f78;
    int f07c, f080, f084, f088, f08c, f090, f094, f098, f09c, f0a0, f0a4, f0a8, f0ac, f0b0, f0b4, f0b8, f0bc, f0c0,
        f0c4;
    int fC8;
    int fCC;
    int fD0;
    int fD4;
    int fD8;
    bool bDC;
    bool bDD;
    bool bDE;
    bool bDF;
    void DetailedActorPathHandler_PrintCurrentStatus(Ctx* pOutput, int a2, int a3);
};
// Writes the actor's position, pathing state, and avoidance state to pOutput using formatted strings.
// @fnv 0x009e8b50
// src: XBOX_PDB 0x009e8b50
void PFThis::DetailedActorPathHandler_PrintCurrentStatus(Ctx* pOutput, int a2, int a3)
{
    char acDetailText[0x104];
    char acStateText[0x104];
    {
        NiPoint3 vPos = *(const NiPoint3*)f04->v125();
        pOutput->v5(a2, a3, "DetailedPathHandler: Actor's Position %1.f %1.f %1.f", (double)vPos.x, (double)vPos.y,
                    (double)vPos.z);
    }
    FUN_00406d30(acStateText, 0x104, "Pathing State: ");
    switch (fC8)
    {
    case 1:
        FUN_00406d50(acStateText, 0x104, "Initializing");
        break;
    case 2:
        if (bDC)
        {
            FUN_00406d50(acStateText, 0x104, "Rotating");
        }
        else if (bDE)
        {
            FUN_00406d50(acStateText, 0x104, "Static Avoidance");
        }
        else
        {
            FUN_00406d50(acStateText, 0x104, "Moving");
        }
        break;
    case 3:
        FUN_00406d50(acStateText, 0x104, "Moving While Waiting");
        break;
    case 4:
        FUN_00406d50(acStateText, 0x104, "Waiting For Updated Path");
        break;
    case 5:
        FUN_00406d50(acStateText, 0x104, "Goal Reached");
        break;
    case 6:
    case 7:
        FUN_00406d50(acStateText, 0x104, "Rotating without path");
        break;
    default:
        FUN_00406d50(acStateText, 0x104, "Invalid");
        break;
    }
    pOutput->v5(a2, a3, acStateText);
    FUN_00406d30(acStateText, 0x104, "Actor Avoid State: ");
    switch (fD0)
    {
    case 1:
        FUN_00406d50(acStateText, 0x104, "OK");
        if (f78 > 0.0)
        {
            BSsprintf(acDetailText, 0x104, " :detect %f", (double)f78);
            FUN_00406d50(acStateText, 0x104, acDetailText);
        }
        break;
    case 2:
        FUN_00406d50(acStateText, 0x104, "Waiting");
        break;
    case 3:
        FUN_00406d50(acStateText, 0x104, "Repathing (building)");
        break;
    case 4:
        FUN_00406d50(acStateText, 0x104, "Repath ignore");
        if (f78 > 0.0)
        {
            BSsprintf(acDetailText, 0x104, " :detect %f", (double)f78);
            FUN_00406d50(acStateText, 0x104, acDetailText);
        }
        break;
    case 5:
        FUN_00406d50(acStateText, 0x104, "Failed");
        break;
    default:
        FUN_00406d50(acStateText, 0x104, "Invalid");
        break;
    }
    pOutput->v5(a2, a3, acStateText);
}
}  // namespace fnv_009e8b50


extern NiPoint3 DAT_011f426c;
extern float DAT_01016970;
extern float DAT_01012054;
extern float DAT_01017b78;
extern float DAT_01017868;


// @fnv 0x009dff40
DetailedActorPathHandler::DetailedActorPathHandler(int a1, int a2)
    : ActorPathHandler(a1, a2), m_kPathVector1(DAT_011f426c), m_kPathVector3(DAT_011f426c), m_kActorPosition(DAT_01016970, DAT_01016970, DAT_01016970),
      m_kPathVector4(DAT_011f426c)
{
    ByteAndFlagState = 0;
    m_fPathValue9 = 1.0f;
    m_fPathValue11 = DAT_01012054;
    m_fPathValue5 = 0.0f;
    m_fPathValue17 = 0.0f;
    m_bPathFlag4 = 0;
    m_bPathFlag5 = 0;
    m_bPathFlag7 = 0;
    m_bPathFlag6 = 0;
    eState = 5;
    m_iPathParameter1 = 0;
    m_fPathValue10 = 0.0f;
    m_iPathParameter2 = 0;
    m_uiPathPointIndex = 0;
    m_fPathValue14 = 0.0f;
    m_fPathValue16 = 0.0f;
    m_fPathValue2 = 0.0f;
    m_fSplineParameter = 0.0f;
    *(float*)pad14 = DAT_01017b78;
    *(float*)(pad14 + 4) = DAT_01017868;
    m_pPathTargetReference = 0;
    m_bHasPathingSolution = 0;
    m_bPathingRequestPending = 0;
    m_fElapsedTime = 0.0f;
    m_fPathValue18 = 0.0f;
}

namespace fnv_009e6900 {

namespace std {
float __cdecl abs(float);
}

float __cdecl BSMAX_00404010(float, float);
void __cdecl BSClamp_float(float&, float, float);

struct SettingVal
{
    float* Float();
};
extern SettingVal g_011f2b8c;

struct Pkg
{
    int GetPackType();
};
struct PkgPtr
{
    Pkg* Get();
};

struct Ref;

struct Target
{
    int unk00;
    int unk04;
    Ref* GetOwner();
    Pkg* GetPkg();
};

struct Proc
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
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual Target* GetTarget();
};

struct Ref
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
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* GetPos();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual Ref* GetCombatTarget();
    float Actor_GetForwardLength();
    float FUN_008be1b0();
    bool Actor_IsInCombat();
    Proc* GetCurrentProcess();
};

struct RefList
{
    bool IsInList(Ref* const&);
};

struct Group
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    RefList list;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int state;
};

// Checks target range, vertical separation, package and direction conditions, and may write a computed value to apResult.
// @fnv 0x009e6900
// src: COMMUNITY 0x009e6900
bool __cdecl DetailedActorPathHandler_CheckDetection(Ref* apActor, Group* apGroup, Ref* apTarget, const NiPoint3& arPos, const NiPoint3& arDir,
                          float afExtra, float afMinDot, float* apResult, bool abCheckOnly)
{
    NiPoint3 kDelta;
    *apResult = 0.0f;
    if (apGroup && (apGroup->state == 4 || apGroup->state == 3) && apGroup->list.IsInList(apTarget))
        return false;

    kDelta = *apTarget->GetPos() - arPos;
    float fRadius3 = apActor->Actor_GetForwardLength();
    float fRange5 = apTarget->FUN_008be1b0() + afExtra + fRadius3;
    float fRangeSqr6 = fRange5 * fRange5;
    if (((const NiPoint3&)kDelta).GetSquaredXYLength() < fRangeSqr6)
    {
        if (std::abs(kDelta.z) < 180.0)
        {
            if (!apActor->Actor_IsInCombat() || apTarget != apActor->GetCombatTarget())
            {
                Target* pTarget = apActor->GetCurrentProcess() ? apActor->GetCurrentProcess()->GetTarget() : 0;
                if (pTarget && pTarget->GetOwner() == apTarget)
                {
                    bool bOkVal = false;
                    switch (pTarget->GetPkg()->GetPackType())
                    {
                    case 1:
                        bOkVal = true;
                    }
                    if (!bOkVal)
                        return false;
                }
                kDelta.z = 0.0f;
                float fDist = kDelta.Length2();
                bool bClose4 = false;
                if (fDist < *g_011f2b8c.Float())
                    bClose4 = true;
                fDist = fDist - fRadius3;
                fDist = BSMAX_00404010(fDist, 0.0f);
                float fDot_ = kDelta.Dot(arDir);
                if (fDot_ >= afMinDot || bClose4)
                {
                    if (abCheckOnly)
                        return true;
                    float fRatio5 = fDist / fRange5;
                    BSClamp_float(fRatio5, 0.0f, 1.0f);
                    int iPower5 = (int)(fRatio5 * 4.0);
                    float fValue3 = fDot_;
                    switch (iPower5)
                    {
                    case 3:
                    case 4:
                        fValue3 = fValue3 * fValue3;
                    case 2:
                        fValue3 = fValue3 * fValue3;
                    case 1:
                        fValue3 = fValue3 * fValue3;
                    }
                    *apResult = fValue3;
                    return true;
                }
            }
        }
    }
    return false;
}
}  // namespace fnv_009e6900

__if_not_exists(_g_thePlayer)
{
    extern TESObjectREFR* _g_thePlayer;
}
extern const double _DAT_01012640;

// 0x00867950 is Calendar::GetGameTimeScale; include/Calendar.h is not available.
class Calendar
{
  public:
    float GetGameTimeScale();
};
extern Calendar g_calendar;

float GetDirectionAngle(const NiPoint3& kVector);
float WrapAngle(float fAngleDifference);




// Actor virtual signature retained: approved MobileObject::Unk_B0 has no target argument.
namespace fnv_009e1d50 {

}  // namespace fnv_009e1d50




// Missing handler methods live on this extension; all fields and virtual slots are shared.
struct DetailedPathGoalUpdate : DetailedActorPathHandler
{
    void ResetPathState();
    void FUN_009e68c0();
    void ResetMoveState();
    int DetailedActorPathHandler_UpdateWhilePlayerWaits(int);
};


// Computes the actor's next move position and heading from the pathing solution, applies it, and returns the next state index.

// @fnv 0x009e1d50

// src: XBOX_PDB 0x009e1d50
int DetailedPathGoalUpdate::DetailedActorPathHandler_UpdateWhilePlayerWaits(int iUnused)

{

    bool bAtEnd;

    unsigned int uiCell6;

    PathingGraphNode* pvRef4;

    int iResultY2;

    float fHeading9;

    float fRateVal;

    PathingLocation* pkLocation8;

    float fSpeedB;

    unsigned int uiWorld3;

    float fElapsed9;


    ResetPathState();

    FUN_009e68c0();

    m_bPathFlag1 = false;

    eState = 2;

    m_iPathParameter1 = 3;

    m_fPathValue15 = 0.0f;

    if (((NiPointer<PathingRequestQueries>&)m_pPathingRequest) && ((PathingRequestQueries*)((NiPointer<PathingRequestQueries>&)m_pPathingRequest))->GetByteAtOffset9F())

    {

        ((::Actor*)pActor)->SetTarget((TESObjectREFR*)_g_thePlayer);

        return 0;

    }

    fElapsed9 = m_fPathValue2 - vfn_18();

    pvRef4 = (PathingGraphNode*)((PathingSolution*)pCurrentPathingSolution)->PathingSolution_GetLastNode();

    pkLocation8 = &pvRef4->FUN_00717e50();

    NiPoint3 kPos2 = pkLocation8->FUN_005c3420<NiPoint3>();

    fHeading9 = (GetDirectionAngle)(pvRef4->FUN_005d8a70());

    uiCell6 = (unsigned int)pkLocation8->FUN_006dd4f0();

    uiWorld3 = (unsigned int)pkLocation8->FUN_00441110();

    fRateVal = _DAT_01012640 / g_calendar.GetGameTimeScale();

    fSpeedB = pActor->GetCurrentMovementSpeed() * fRateVal;

    bAtEnd = (m_pActorMover->lastNode + 1) == ((PathingSolution*)pCurrentPathingSolution)->PathingSolution_GetVirtualNodeCount();

    if (((Actor*)pActor)->GetSitSleepState() == 4 && ((Actor*)pActor)->GetSitSleepState() == 9)

    {

    }

    else

    {

        if (((NiPointer<PathingRequestQueries>&)m_pPathingRequest) && ((PathingRequestQueries*)((NiPointer<PathingRequestQueries>&)m_pPathingRequest))->TESCombatStyle_GetPowerAttackF() && bAtEnd)

        {

            fHeading9 = ((PathingRequestQueries*)((NiPointer<PathingRequestQueries>&)m_pPathingRequest))->BGSProjectile_GetMuzzleFlashDuration();

        }

        else if (m_pActorMover->HasLookAtTarget())

        {

            NiPoint3 kTarget;

            m_pActorMover->GetLookAtTargetPosition((NiPoint3&)kTarget);

            NiPoint3 kTargetPt = CombatUtilities_GetAngleToProjectedPoint(((Actor*)pActor), kTarget);

            fHeading9 = WrapAngle(kTargetPt.z);

        }

        else

        {

            unsigned int ItemUpdateArray = ((PathingSolution*)pCurrentPathingSolution)->GetObjectFlags();

            if (ItemUpdateArray > 1)

            {

                NiPoint3 kPrevTmp = ((PathingGraphNode*)((PathingSolution*)pCurrentPathingSolution)

                                        ->GetNode_006e7970(ItemUpdateArray - 2))

                                        ->FUN_00717e50()

                                        .FUN_005c3420<NiPoint3>();

                NiPoint3 kLastX = ((PathingGraphNode*)((PathingSolution*)pCurrentPathingSolution)

                                      ->GetNode_006e7970(ItemUpdateArray - 1))

                                      ->FUN_00717e50()

                                      .FUN_005c3420<NiPoint3>();

                NiPoint3 kDiff = ((NiPoint3&)kLastX).SubtractIntoVector(kPrevTmp);

                fHeading9 = (GetDirectionAngle)(kDiff);

            }

            else

            {

                fHeading9 = ((Actor*)pActor)->GetCurrentTargetDistance(0);

            }

        }

    }

    pActor->Actor_MoveActorAndFollowers(kPos2, fHeading9, (int)uiCell6, (int)uiWorld3, 1, 0);

    iResultY2 = 5;

    ResetMoveState();

    eState = 5;

    if (!bAtEnd)

        iResultY2 = 6;

    return iResultY2;

}


struct EndRotateHandler : DetailedActorPathHandler

{

    bool DetailedActorPathHandler_CheckForEndRotate();

};


// @fnv 0x009e7550

// src: XBOX_PDB 0x009e7550
bool EndRotateHandler::DetailedActorPathHandler_CheckForEndRotate()

{

    if (((PathingRequestQueries*)((NiPointer<PathingRequest>&)m_pPathingRequest).operator->())->TESCombatStyle_GetPowerAttackF() &&

        ((ActorMover*)m_pActorMover)->lastNode + 1 ==

            ((PathingSolution*)((NiPointer<PathingSolution>&)pCurrentPathingSolution).operator->())->PathingSolution_GetVirtualNodeCount() &&

        pActor->GetSitSleepState() != 4 && pActor->GetSitSleepState() != 9)

    {

        StartTurningToAngle(((PathingRequestQueries*)((NiPointer<PathingRequest>&)m_pPathingRequest).operator->())->BGSProjectile_GetMuzzleFlashDuration(), false, false);

        return m_bPathFlag1;

    }


    return false;

}

