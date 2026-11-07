
// src/staging/blk_008c0000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /Od /Oy- /GS /EHsc /Gy (unit src/staging/blk_008c0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_008c0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiMatrix3.h"
#include "../../include/hkVector4.h"
#include "../../include/Setting.h"
#include "../../include/bhkFilter.h"
#include "../../include/bhkCollisionObject.h"
#include "../../include/bhkRigidBody.h"

hkVector4* __cdecl NI2HK(hkVector4* destination, const NiPoint3* source);
class FUN_008c5d90_Class
{
  public:
    void bhkMouseSpringAction_SetMousePosition_hk(hkVector4* converted);
    void bhkMouseSpringAction_SetMousePosition(const NiPoint3* source);
};
// Preserve the original stack-cookie coverage after replacing the local vector representation.
#pragma strict_gs_check(push, on)
// @fnv 0x008c5d90
// src: XBOX_PDB 0x008c5d90
void FUN_008c5d90_Class::bhkMouseSpringAction_SetMousePosition(const NiPoint3* source)
{
    __declspec(align(16)) hkVector4 vector;
    bhkMouseSpringAction_SetMousePosition_hk(NI2HK(&vector, source));
}
#pragma strict_gs_check(pop)


struct __declspec(align(16)) Rotation_8cc740
{
    char m_acRotationData[16];
    Rotation_8cc740(const char* pcName);
    Rotation_8cc740 hkVector4_getSimdAt(int iFlags) const;
    float EvaluateValue_004586d0() const;
};

struct ProjectionData_8cc740
{
    int m_iFadeIndex;
    NiPoint3 m_kStartPoint;
    NiPoint3 m_kLightVector;
    NiPoint3 m_kValue;
    int m_iArrayLength;
    int m_iFlags;
    NiMatrix3 m_kRotationMatrix;
    ProjectionData_8cc740();
};

struct Source_8cc740
{
    const char* bhkCharacterProxy_GethkLinearVelocity();
};

struct Node_8cc740
{
    NiMatrix3* NiAVObject_GetWorldRotate();
};

struct Listener_8cc740;

struct ListenerHost_8cc740
{
    int unk000, unk004, unk008, unk00c, unk010, unk014;
};
struct ListenerHost30_8cc740
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c;
};
struct Listener_8cc740
{
    int unk00;
};
struct Emitter18_8cc740 : ListenerHost_8cc740, Listener_8cc740
{
};
struct Emitter30_8cc740 : ListenerHost30_8cc740, Listener_8cc740
{
};

class Sink_8cc740
{
  public:
    virtual void s000();
    virtual void s004();
    virtual void s008();
    virtual void s00c();
    virtual void s010();
    virtual void s014();
    virtual void s018();
    virtual void s01c();
    virtual void s020();
    virtual void s024();
    virtual void s028();
    virtual void s02c();
    virtual void s030();
    virtual void s034();
    virtual void s038();
    virtual void s03c();
    virtual void Attach(Listener_8cc740* pkListener);
    virtual void s044();
    virtual void SetActive(int iActive);
    void TryCast(void* pkObject);
};

class Effect_8cc740
{
  public:
    void FUN_008d0600(const NiPoint3& kPos, int iUnused);
};

class Controller_8cc740
{
  public:
    virtual void c000();
    virtual void c004();
    virtual void c008();
    virtual void c00c();
    virtual void c010();
    virtual void c014();
    virtual void c018();
    virtual void c01c();
    virtual void c020();
    virtual void c024();
    virtual void c028();
    virtual void c02c();
    virtual void c030();
    virtual void c034();
    virtual void c038();
    virtual void c03c();
    virtual void c040();
    virtual void c044();
    virtual void c048();
    virtual void c04c();
    virtual void c050();
    virtual void c054();
    virtual void c058();
    virtual void c05c();
    virtual void c060();
    virtual void c064();
    virtual void c068();
    virtual void c06c();
    virtual void c070();
    virtual void c074();
    virtual void c078();
    virtual void c07c();
    virtual void c080();
    virtual void c084();
    virtual void c088();
    virtual void c08c();
    virtual void c090();
    virtual void c094();
    virtual void c098();
    virtual void c09c();
    virtual void c0a0();
    virtual void c0a4();
    virtual void c0a8();
    virtual void c0ac();
    virtual void c0b0();
    virtual void c0b4();
    virtual void c0b8();
    virtual void c0bc();
    virtual void c0c0();
    virtual void c0c4();
    virtual void c0c8();
    virtual void c0cc();
    virtual void c0d0();
    virtual void c0d4();
    virtual void c0d8();
    virtual void c0dc();
    virtual void c0e0();
    virtual void c0e4();
    virtual void c0e8();
    virtual void c0ec();
    virtual void c0f0();
    virtual void c0f4();
    virtual void c0f8();
    virtual void c0fc();
    virtual void c100();
    virtual void c104();
    virtual void c108();
    virtual void c10c();
    virtual void c110();
    virtual void c114();
    virtual void c118();
    virtual void c11c();
    virtual void c120();
    virtual void c124();
    virtual void c128();
    virtual void c12c();
    virtual void c130();
    virtual void c134();
    virtual void c138();
    virtual void c13c();
    virtual void c140();
    virtual void c144();
    virtual void c148();
    virtual void c14c();
    virtual void c150();
    virtual void c154();
    virtual void c158();
    virtual void c15c();
    virtual void c160();
    virtual void c164();
    virtual void c168();
    virtual void c16c();
    virtual void c170();
    virtual void c174();
    virtual void c178();
    virtual void c17c();
    virtual void c180();
    virtual void c184();
    virtual void c188();
    virtual void c18c();
    virtual void c190();
    virtual void c194();
    virtual void c198();
    virtual void c19c();
    virtual void c1a0();
    virtual void c1a4();
    virtual void c1a8();
    virtual void c1ac();
    virtual void c1b0();
    virtual void c1b4();
    virtual void c1b8();
    virtual void c1bc();
    virtual void c1c0();
    virtual void c1c4();
    virtual void c1c8();
    virtual void c1cc();
    virtual void c1d0();
    virtual void c1d4();
    virtual void c1d8();
    virtual void c1dc();
    virtual void c1e0();
    virtual void c1e4();
    virtual void c1e8();
    virtual void c1ec();
    virtual void c1f0();
    virtual void c1f4();
    virtual void c1f8();
    virtual void c1fc();
    virtual void c200();
    virtual void c204();
    virtual void c208();
    virtual void c20c();
    virtual void c210();
    virtual void c214();
    virtual void c218();
    virtual void c21c();
    virtual void c220();
    virtual void c224();
    virtual void c228();
    virtual void c22c();
    virtual void c230();
    virtual void c234();
    virtual void c238();
    virtual void c23c();
    virtual void c240();
    virtual void c244();
    virtual void c248();
    virtual void c24c();
    virtual void c250();
    virtual void c254();
    virtual void c258();
    virtual void c25c();
    virtual void c260();
    virtual void c264();
    virtual void c268();
    virtual void c26c();
    virtual void c270();
    virtual void c274();
    virtual void c278();
    virtual void c27c();
    virtual void c280();
    virtual void c284();
    virtual void c288();
    virtual void c28c();
    virtual void c290();
    virtual void c294();
    virtual void c298();
    virtual void c29c();
    virtual void c2a0();
    virtual void c2a4();
    virtual void c2a8();
    virtual void c2ac();
    virtual void c2b0();
    virtual void c2b4();
    virtual void c2b8();
    virtual void c2bc();
    virtual void c2c0();
    virtual void c2c4();
    virtual void c2c8();
    virtual void c2cc();
    virtual void c2d0();
    virtual void c2d4();
    virtual void c2d8();
    virtual void c2dc();
    virtual void c2e0();
    virtual void c2e4();
    virtual void c2e8();
    virtual void c2ec();
    virtual void c2f0();
    virtual void c2f4();
    virtual void c2f8();
    virtual void c2fc();
    virtual void c300();
    virtual void c304();
    virtual void c308();
    virtual void c30c();
    virtual void c310();
    virtual void c314();
    virtual void c318();
    virtual void c31c();
    virtual void c320();
    virtual void c324();
    virtual void c328();
    virtual void c32c();
    virtual void c330();
    virtual void c334();
    virtual void c338();
    virtual void c33c();
    virtual void c340();
    virtual void c344();
    virtual void c348();
    virtual void c34c();
    virtual void c350();
    virtual void c354();
    virtual void c358();
    virtual void c35c();
    virtual void c360();
    virtual void c364();
    virtual void c368();
    virtual void c36c();
    virtual void c370();
    virtual void c374();
    virtual void c378();
    virtual void c37c();
    virtual void c380();
    virtual void c384();
    virtual void c388();
    virtual void c38c();
    virtual void c390();
    virtual void c394();
    virtual void c398();
    virtual void c39c();
    virtual void c3a0();
    virtual void c3a4();
    virtual void c3a8();
    virtual void c3ac();
    virtual void c3b0();
    virtual void c3b4();
    virtual void c3b8();
    virtual void c3bc();
    virtual void c3c0();
    virtual void c3c4();
    virtual void c3c8();
    virtual void c3cc();
    virtual void c3d0();
    virtual void c3d4();
    virtual void c3d8();
    virtual void c3dc();
    virtual void c3e0();
    virtual void c3e4();
    virtual void c3e8();
    virtual void c3ec();
    virtual void c3f0();
    virtual void c3f4();
    virtual void c3f8();
    virtual void c3fc();
    virtual void c400();
    virtual void c404();
    virtual void c408();
    virtual void c40c();
    virtual void c410();
    virtual void c414();
    virtual void c418();
    virtual void c41c();
    virtual void c420();
    virtual void c424();
    virtual Effect_8cc740* GetEffect();
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020;
    int unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040;
    int unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060;
    int unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080;
    int unk084;
    Sink_8cc740 m_kSink;
};

struct Grid_8cc740
{
    unsigned int TES_GetLandMaterialType(const NiPoint3& kPos);
};

void __cdecl FUN_00458620(NiPoint3* pkOut, const Rotation_8cc740* pkRot);

extern NiMatrix3 DAT_011a9448;
extern NiPoint3 DAT_011a9478;
extern NiPoint3 DAT_011f426c;
extern Grid_8cc740* DAT_011dea10;
extern float DAT_01085910;

class Owner_8cc740
{
  public:
    virtual void o000();
    virtual void o004();
    virtual void o008();
    virtual void o00c();
    virtual void o010();
    virtual void o014();
    virtual void o018();
    virtual void o01c();
    virtual void o020();
    virtual void o024();
    virtual void o028();
    virtual void o02c();
    virtual void o030();
    virtual void o034();
    virtual void o038();
    virtual void o03c();
    virtual void o040();
    virtual void o044();
    virtual void o048();
    virtual void o04c();
    virtual void o050();
    virtual void o054();
    virtual void o058();
    virtual void o05c();
    virtual void o060();
    virtual void o064();
    virtual void o068();
    virtual void o06c();
    virtual void o070();
    virtual void o074();
    virtual void o078();
    virtual void o07c();
    virtual void o080();
    virtual void o084();
    virtual void o088();
    virtual void o08c();
    virtual void o090();
    virtual void o094();
    virtual void o098();
    virtual void o09c();
    virtual void o0a0();
    virtual void o0a4();
    virtual void o0a8();
    virtual void o0ac();
    virtual void o0b0();
    virtual void o0b4();
    virtual void o0b8();
    virtual void o0bc();
    virtual void o0c0();
    virtual void o0c4();
    virtual void o0c8();
    virtual void o0cc();
    virtual void o0d0();
    virtual void o0d4();
    virtual void o0d8();
    virtual void o0dc();
    virtual void o0e0();
    virtual void o0e4();
    virtual void o0e8();
    virtual void o0ec();
    virtual void o0f0();
    virtual void o0f4();
    virtual void o0f8();
    virtual void o0fc();
    virtual void o100();
    virtual void o104();
    virtual void o108();
    virtual void o10c();
    virtual void o110();
    virtual void o114();
    virtual void o118();
    virtual void o11c();
    virtual void o120();
    virtual void o124();
    virtual void o128();
    virtual void o12c();
    virtual void o130();
    virtual void o134();
    virtual void o138();
    virtual void o13c();
    virtual void o140();
    virtual void o144();
    virtual void o148();
    virtual void o14c();
    virtual void o150();
    virtual void o154();
    virtual void o158();
    virtual void o15c();
    virtual void o160();
    virtual void o164();
    virtual void o168();
    virtual void o16c();
    virtual void o170();
    virtual void o174();
    virtual void o178();
    virtual void o17c();
    virtual void o180();
    virtual void o184();
    virtual void o188();
    virtual void o18c();
    virtual void o190();
    virtual void o194();
    virtual void o198();
    virtual void o19c();
    virtual void o1a0();
    virtual void o1a4();
    virtual void o1a8();
    virtual void o1ac();
    virtual void o1b0();
    virtual void o1b4();
    virtual void o1b8();
    virtual void o1bc();
    virtual void o1c0();
    virtual void o1c4();
    virtual void o1c8();
    virtual void o1cc();
    virtual Node_8cc740* GetNode();
    int unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020;
    int unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040;
    int unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060;
    int unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080;
    int unk084;
    ProjectionData_8cc740* m_pUserData;
    int m_iActive;
    int unk90, unk94;
    float m_fScale;
    int unk9c, unka0;
    Controller_8cc740* m_pkController;
    int unka8, unkac, unkb0;
    NiPoint3 m_kOffset;

    Source_8cc740* FUN_009306d0();
    void ArrowProjectile_PlayArrowCollisionSound(float fScaleMultiplier, NiPoint3 kPos, int iZero, unsigned int uiType);
    Emitter18_8cc740* DialoguePackage_GetCurrentDialogItem();
    Emitter30_8cc740* DialoguePackage_GetActorStartedConversation();
    Emitter18_8cc740* FUN_004f9bf0();
    void* BGSSaveFormBuffer_GetForm();
    void ArrowProjectile_Bounce(const NiPoint3& kPos, const NiPoint3& kWorldPosition);
    void EffectSetting_SetAreaSound(int iState);
    void ArrowProjectile_CollideTerrain(const NiPoint3& kPos, const NiPoint3& kWorldPosition);
};

// @fnv 0x008cc740
// src: XBOX_PDB 0x008cc740
void Owner_8cc740::ArrowProjectile_CollideTerrain(const NiPoint3& kPos, const NiPoint3& kWorldPosition)
{
    m_pUserData = new ProjectionData_8cc740;
    NiPoint3 kIntersectionOffset = m_kOffset;
    NiPoint3::NiPoint3_UnitizeVector(kIntersectionOffset);
    kIntersectionOffset *= 24.0f;
    m_pUserData->m_iFadeIndex = 2;
    m_pUserData->m_iFlags = 0;
    m_pUserData->m_iArrayLength = 0;
    m_pUserData->m_kLightVector = kWorldPosition;
    m_pUserData->m_kStartPoint = kPos + kIntersectionOffset;
    m_pUserData->m_kRotationMatrix = DAT_011a9448;
    m_pUserData->m_kValue = DAT_011f426c;
    if (FUN_009306d0())
    {
        Rotation_8cc740 kRot(FUN_009306d0()->bhkCharacterProxy_GethkLinearVelocity());
        if (kRot.hkVector4_getSimdAt(0).EvaluateValue_004586d0() == -DAT_01085910)
        {
            if (GetNode())
                m_pUserData->m_kValue = GetNode()->NiAVObject_GetWorldRotate()->operator*(DAT_011a9478 * m_fScale);
        }
        else
            FUN_00458620(&m_pUserData->m_kValue, &kRot);
    }
    unsigned int uiType = DAT_011dea10->TES_GetLandMaterialType(kPos);
    switch (uiType)
    {
    case 0:
    case 3:
    case 5:
    case 10:
    case 11:
    case 13:
    case 15:
        ArrowProjectile_Bounce(kPos, kWorldPosition);
        break;
    }
    m_iActive = 1;
    ArrowProjectile_PlayArrowCollisionSound(m_pUserData->m_kValue.Length(), kPos, 0, uiType);
    if (m_pkController && m_pkController->GetEffect())
        m_pkController->GetEffect()->FUN_008d0600(kPos, 0);
    if (m_pkController)
    {
        if (DialoguePackage_GetCurrentDialogItem())
        {
            m_pkController->m_kSink.Attach(DialoguePackage_GetCurrentDialogItem());
            m_pkController->m_kSink.SetActive(0);
            m_pkController->m_kSink.TryCast(BGSSaveFormBuffer_GetForm());
        }
        if (DialoguePackage_GetActorStartedConversation())
        {
            m_pkController->m_kSink.Attach(DialoguePackage_GetActorStartedConversation());
            m_pkController->m_kSink.SetActive(0);
            m_pkController->m_kSink.TryCast(BGSSaveFormBuffer_GetForm());
        }
        if (FUN_004f9bf0())
        {
            m_pkController->m_kSink.Attach(FUN_004f9bf0());
            m_pkController->m_kSink.SetActive(0);
            m_pkController->m_kSink.TryCast(BGSSaveFormBuffer_GetForm());
        }
    }
    if (DialoguePackage_GetCurrentDialogItem())
        EffectSetting_SetAreaSound(3);
}

extern NiPoint3 xg_11a9478;
extern NiMatrix3 xg_11a9448;
extern const float xg_1085910;
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4(const NiPoint3&);
    xVec4 hkVector4_getSimdAt(int) const;
    float EvaluateValue_004586d0() const;
};
struct xData
{
    xData();
    int m_iWordAt00;
    NiPoint3 m_iWordAt04;
    NiPoint3 m_10;
    NiPoint3 m_1c;
    int m_28;
    int m_2c;
    NiMatrix3 m_30;
};
struct xHolder
{
    const NiPoint3* bhkCharacterProxy_GethkLinearVelocity();
};
struct xDHOwner
{
    NiMatrix3* NiAVObject_GetWorldRotate();
};
void xFUN_00458620(NiPoint3*, xVec4*);
struct xActor
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
    virtual xDHOwner* FUN_1d0();
    char m_pad04[0x84];
    xData* m_88;
    int m_8c;
    int m_90, m_94;
    float m_98;
    xHolder* FUN_009306d0();
    void ArrowProjectile_Bounce(const NiPoint3& akA, const NiPoint3& akB);
};

// @fnv 0x008ccce0
// src: XBOX_PDB 0x008ccce0
void xActor::ArrowProjectile_Bounce(const NiPoint3& akA, const NiPoint3& akB)
{
    if (m_88)
    {
        if (akB != NiPoint3::ZERO)
            m_88->m_10 = akB;
        if (akA != NiPoint3::ZERO)
            m_88->m_iWordAt04 = akA;
        m_88->m_iWordAt00 = 3;
        m_88->m_28 = 0;
        return;
    }
    m_88 = new xData;
    m_88->m_iWordAt00 = 3;
    m_88->m_2c = 0;
    m_88->m_28 = 0;
    m_88->m_10 = akB;
    m_88->m_iWordAt04 = akA;
    m_88->m_30 = xg_11a9448;
    m_88->m_1c = NiPoint3::ZERO;
    if (FUN_009306d0())
    {
        xVec4 V(*FUN_009306d0()->bhkCharacterProxy_GethkLinearVelocity());
        if (V.hkVector4_getSimdAt(0).EvaluateValue_004586d0() == -xg_1085910)
        {
            if (FUN_1d0())
                m_88->m_1c = FUN_1d0()->NiAVObject_GetWorldRotate()->operator*(xg_11a9478 * m_98);
        }
        else
            xFUN_00458620(&m_88->m_1c, &V);
    }
    m_8c = 1;
}

namespace fnv_008ccfb0 {
extern NiPoint3 xg_11a9478;
extern NiMatrix3 xg_11a9448;
extern const float xg_1085910;
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4(const NiPoint3&);
    xVec4 hkVector4_getSimdAt(int) const;
    float EvaluateValue_004586d0() const;
};
struct xData
{
    xData();
    int m_iWordAt00;
    NiPoint3 m_iWordAt04;
    NiPoint3 m_10;
    NiPoint3 m_1c;
    int m_28;
    int m_2c;
    NiMatrix3 m_30;
};
struct xHolder
{
    const NiPoint3* bhkCharacterProxy_GethkLinearVelocity();
};
struct xDHOwner
{
    NiMatrix3* NiAVObject_GetWorldRotate();
};
void xFUN_00458620(NiPoint3*, xVec4*);
struct xActor
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
    virtual xDHOwner* FUN_1d0();
    char m_pad04[0x84];
    xData* m_88;
    int m_8c;
    int m_90, m_94;
    float m_98;
    xHolder* FUN_009306d0();
    void ArrowProjectile_Simulate(int aiValue);
};

// @fnv 0x008ccfb0
// src: XBOX_PDB 0x008ccfb0
void xActor::ArrowProjectile_Simulate(int aiValue)
{
    if (m_88)
        m_88->m_iWordAt00 = 4;
    else
    {
        m_88 = new xData;
        m_88->m_iWordAt00 = 4;
        m_88->m_2c = 0;
        m_88->m_28 = aiValue;
        m_88->m_10 = NiPoint3::ZERO;
        m_88->m_iWordAt04 = NiPoint3::ZERO;
        m_88->m_30 = xg_11a9448;
        m_88->m_1c = NiPoint3::ZERO;
        if (FUN_009306d0())
        {
            xVec4 V(*FUN_009306d0()->bhkCharacterProxy_GethkLinearVelocity());
            if (V.hkVector4_getSimdAt(0).EvaluateValue_004586d0() == -xg_1085910)
            {
                if (FUN_1d0())
                    m_88->m_1c = FUN_1d0()->NiAVObject_GetWorldRotate()->operator*(xg_11a9478 * m_98);
            }
            else
                xFUN_00458620(&m_88->m_1c, &V);
        }
    }
    m_8c = 1;
}
}  // namespace fnv_008ccfb0

#include <xmmintrin.h>

class SpellHandle8CD
{
  public:
    SpellHandle8CD(int iType, int iValue, int iFlags);
    void SetFlags(int iFlags);
    int m_iHandle;
};


class Caster8CD
{
  public:
    virtual void vc000();
    virtual void vc004();
    virtual void vc008();
    virtual void vc00c();
    virtual void vc010();
    virtual void vc014();
    virtual void vc018();
    virtual void vc01c();
    virtual void vc020();
    virtual void vc024();
    virtual void vc028();
    virtual void vc02c();
    virtual void vc030();
    virtual void vc034();
    virtual void vc038();
    virtual void vc03c();
    virtual void vc040();
    virtual void vc044();
    virtual void vc048();
    virtual void vc04c();
    virtual void vc050();
    virtual void vc054();
    virtual void vc058();
    virtual void vc05c();
    virtual void vc060();
    virtual void vc064();
    virtual void vc068();
    virtual void vc06c();
    virtual void vc070();
    virtual void vc074();
    virtual void vc078();
    virtual void vc07c();
    virtual void vc080();
    virtual void vc084();
    virtual void vc088();
    virtual void vc08c();
    virtual void vc090();
    virtual void vc094();
    virtual void vc098();
    virtual void vc09c();
    virtual void vc0a0();
    virtual void vc0a4();
    virtual void vc0a8();
    virtual void vc0ac();
    virtual void vc0b0();
    virtual void vc0b4();
    virtual void vc0b8();
    virtual void vc0bc();
    virtual void vc0c0();
    virtual void vc0c4();
    virtual void vc0c8();
    virtual void vc0cc();
    virtual void vc0d0();
    virtual void vc0d4();
    virtual void vc0d8();
    virtual void vc0dc();
    virtual void vc0e0();
    virtual void vc0e4();
    virtual void vc0e8();
    virtual void vc0ec();
    virtual void GetTransform(hkVector4& kOut);
    void SetHandle(SpellHandle8CD kHandle);
};

class Listener8CD
{
  public:
    void Add(void* const& rpvSource);
};

class ListenerList8CD
{
  public:
    Listener8CD* Get();
};
extern ListenerList8CD g_kListeners8CD;

class Target8CD
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
    int m_iActive;
    void* m_pvTarget;
};

void* __cdecl FindFirstCollisionObject(void* pvTarget);
void __cdecl bhkWorld_SetMotion(void* pvSource, int a, int b, int c, int d);
void __cdecl TESArrowTargetListener_AddArrowTarget(hkVector4* pkTransform, void* pvTarget);
void __cdecl Warning_005b5e40(const char* pcMessage);

// 0x008cd520 binds ArrowProjectile::HandleType1; its collision pointer is at +0x88, unlike Projectile.
class ArrowImpactHandler
{
  public:
    virtual void vp000();
    virtual void vp004();
    virtual void vp008();
    virtual void vp00c();
    virtual void vp010();
    virtual void vp014();
    virtual void vp018();
    virtual void vp01c();
    virtual void vp020();
    virtual void vp024();
    virtual void vp028();
    virtual void vp02c();
    virtual void vp030();
    virtual void vp034();
    virtual void vp038();
    virtual void vp03c();
    virtual void vp040();
    virtual void vp044();
    virtual void vp048();
    virtual void vp04c();
    virtual void vp050();
    virtual void vp054();
    virtual void vp058();
    virtual void vp05c();
    virtual void vp060();
    virtual void vp064();
    virtual void vp068();
    virtual void vp06c();
    virtual void vp070();
    virtual void vp074();
    virtual void vp078();
    virtual void vp07c();
    virtual void vp080();
    virtual void vp084();
    virtual void vp088();
    virtual void vp08c();
    virtual void vp090();
    virtual void vp094();
    virtual void vp098();
    virtual void vp09c();
    virtual void vp0a0();
    virtual void vp0a4();
    virtual void vp0a8();
    virtual void vp0ac();
    virtual void vp0b0();
    virtual void vp0b4();
    virtual void vp0b8();
    virtual void vp0bc();
    virtual void vp0c0();
    virtual void vp0c4();
    virtual void vp0c8();
    virtual void vp0cc();
    virtual void vp0d0();
    virtual void vp0d4();
    virtual void vp0d8();
    virtual void vp0dc();
    virtual void vp0e0();
    virtual void vp0e4();
    virtual void vp0e8();
    virtual void vp0ec();
    virtual void vp0f0();
    virtual void vp0f4();
    virtual void vp0f8();
    virtual void vp0fc();
    virtual void vp100();
    virtual void vp104();
    virtual void vp108();
    virtual void vp10c();
    virtual void vp110();
    virtual void vp114();
    virtual void vp118();
    virtual void vp11c();
    virtual void vp120();
    virtual void vp124();
    virtual void vp128();
    virtual void vp12c();
    virtual void vp130();
    virtual void vp134();
    virtual void vp138();
    virtual void vp13c();
    virtual void vp140();
    virtual void vp144();
    virtual void vp148();
    virtual void vp14c();
    virtual void vp150();
    virtual void vp154();
    virtual void vp158();
    virtual void vp15c();
    virtual void vp160();
    virtual void vp164();
    virtual void vp168();
    virtual void vp16c();
    virtual void vp170();
    virtual void vp174();
    virtual void vp178();
    virtual void vp17c();
    virtual void vp180();
    virtual void vp184();
    virtual void vp188();
    virtual void vp18c();
    virtual void vp190();
    virtual void vp194();
    virtual void vp198();
    virtual void vp19c();
    virtual void vp1a0();
    virtual void vp1a4();
    virtual void vp1a8();
    virtual void vp1ac();
    virtual void vp1b0();
    virtual void vp1b4();
    virtual void vp1b8();
    virtual void vp1bc();
    virtual void vp1c0();
    virtual void vp1c4();
    virtual void vp1c8();
    virtual void vp1cc();
    virtual void* GetSource();
    virtual void vq000();
    virtual void vq004();
    virtual void vq008();
    virtual void vq00c();
    virtual void vq010();
    virtual void vq014();
    virtual void vq018();
    virtual void vq01c();
    virtual void vq020();
    virtual void vq024();
    virtual void vq028();
    virtual void vq02c();
    virtual void vq030();
    virtual void vq034();
    virtual void vq038();
    virtual void vq03c();
    virtual void vq040();
    virtual void vq044();
    virtual void vq048();
    virtual void vq04c();
    virtual void vq050();
    virtual void vq054();
    virtual void vq058();
    virtual void vq05c();
    virtual void vq060();
    virtual void vq064();
    virtual void vq068();
    virtual void vq06c();
    virtual void vq070();
    virtual void vq074();
    virtual void vq078();
    virtual void vq07c();
    virtual void vq080();
    virtual void vq084();
    virtual void vq088();
    virtual void vq08c();
    virtual void vq090();
    virtual void vq094();
    virtual void vq098();
    virtual void vq09c();
    virtual void vq0a0();
    virtual void vq0a4();
    virtual void vq0a8();
    virtual void vq0ac();
    virtual void vq0b0();
    virtual void vq0b4();
    virtual void vq0b8();
    virtual void vq0bc();
    virtual void vq0c0();
    virtual void vq0c4();
    virtual void vq0c8();
    virtual void Prepare();
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
    Target8CD* m_pkTarget;

    bool ArrowProjectile_ProcessCollisionReference(Caster8CD* pkCaster);
};

// Preserve the original stack-cookie coverage after replacing the local vector representation.
#pragma strict_gs_check(push, on)
// @fnv 0x008cd520
// src: XBOX_PDB 0x008cd520
bool ArrowImpactHandler::ArrowProjectile_ProcessCollisionReference(Caster8CD* pkCaster)
{
    Prepare();
    if (m_pkTarget->m_iActive)
    {
        bhkCollisionObject* pkRef = (bhkCollisionObject*)FindFirstCollisionObject(m_pkTarget->m_pvTarget);
        if (!pkRef)
            return false;
        bhkRigidBody* pkItem = static_cast<bhkRigidBody*>(pkRef->bhkNiCollisionObject_GetWorldObject());
        bhkWorld_SetMotion(GetSource(), 4, 1, 0, 1);
        SpellHandle8CD kHandle(6, pkItem->bhkWorldObject_GetCollisionFilter().CFilter_GetGroup(), 0);
        if (pkItem->bhkWorldObject_GetCollisionFilter().CFilter_GetLayer() != 4)
            kHandle.SetFlags(0xf);
        pkCaster->SetHandle(kHandle);
        Listener8CD* pkListener = g_kListeners8CD.Get();
        if (pkListener)
            pkListener->Add((void*)this);
        if (pkCaster)
        {
            if (pkItem->GetBodyMass() > 0.0)
            {
                hkVector4 kTransform;
                pkCaster->GetTransform(kTransform);
                TESArrowTargetListener_AddArrowTarget(&kTransform, m_pkTarget->m_pvTarget);
            }
        }
    }
    else
    {
        Warning_005b5e40(
            "AI: An arrow thinks it is colliding with an Reference, but there is no Reference in the collision data!");
        return false;
    }
    return true;
}
#pragma strict_gs_check(pop)

extern Setting DAT_011ce3e4;
extern Setting DAT_011cecac;
extern Setting DAT_011cf9d4;
extern Setting DAT_011ce798;
extern Setting DAT_011cf114;
extern Setting DAT_011ce224;
struct BodyD0020
{
    void FUN_00483710();
};
struct ResultD0020
{
    void ApplyVirtualCall();
};
struct ObjectD0020
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
    virtual void va();
    virtual void vb();
    virtual void vc();
    virtual void vd();
    virtual void ve();
    virtual void vf();
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
    virtual BodyD0020* GetBody();
    bhkFilter bhkWorldObject_GetCollisionFilter();
    float bhkRigidBody_GetMass();
    ResultD0020* Bipedanim_GetReferenceFlagsOrZero(const hkVector4&, const hkVector4&);
};
struct TargetD0020
{
    bool GetByteAtOffsetC3();
    float NiAVObject_GetWorldScale();
    void SetByteAtOffsetC3(bool);
    void ArrowProjectile_ApplyCollisionForce(NiPoint3 position, NiPoint3 direction, ObjectD0020* object);
};
// Preserve the original stack-cookie coverage after replacing the local vector representation.
#pragma strict_gs_check(push, on)
// @fnv 0x008d0020
// src: XBOX_PDB 0x008d0020
void TargetD0020::ArrowProjectile_ApplyCollisionForce(NiPoint3 position, NiPoint3 direction, ObjectD0020* object)
{
    if (!object || GetByteAtOffsetC3())
        return;
    BodyD0020* body = object->GetBody();
    if (body)
    {
        float strength = NiAVObject_GetWorldScale();
        bhkFilter type = object->bhkWorldObject_GetCollisionFilter();
        switch (type.CFilter_GetLayer())
        {
        case 14:
            strength *= *DAT_011ce3e4.Setting_Float_00403e20();
            break;
        case 8:
            strength *= *DAT_011cecac.Setting_Float_00403e20();
            break;
        case 10:
            strength *= *DAT_011cf9d4.Setting_Float_00403e20();
            break;
        default:
            strength *= *DAT_011ce798.Setting_Float_00403e20();
            break;
        }
        float weight = object->bhkRigidBody_GetMass();
        if (weight < *DAT_011cf114.Setting_Float_00403e20())
            strength *= weight / *DAT_011cf114.Setting_Float_00403e20();
        strength *= *DAT_011ce224.Setting_Float_00403e20();
        hkVector4 dir;
        NI2HK(&dir, &direction);
        hkVector4 pos;
        NI2HK(&pos, &position);
        dir.normalize3_0062aea0();
        hkSimdReal scale(strength);
        dir.hkVector4_mul4(scale);
        body->FUN_00483710();
        object->Bipedanim_GetReferenceFlagsOrZero(dir, pos)->ApplyVirtualCall();
        body->FUN_00483710();
    }
    SetByteAtOffsetC3(true);
}
#pragma strict_gs_check(pop)

struct __declspec(align(16)) Quat08
{
    __m128 quad;
    void* hkVector4_hkVector4(float, float, float, float);
};
struct Row08
{
    float x, y, z, w;
    void SetValue(const void*);
};
struct Rec08
{
    Row08 a, b, c, d;
};
struct Data08
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
    Rec08* records;
    int count;
};
struct Col_0043b4f0
{
    int hkpCollidable_getCollisionFilterInfo();
};
struct Node08
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
    Col_0043b4f0* collision;
};
struct FUN_00807770_Class
{
    int EvaluateValue_00807770(int);
};
void* __cdecl hkpGetRigidBody(const void*);
void* __cdecl GetReferenceFromObject(Col_0043b4f0*);
struct FUN_0089f4e0_shell
{
    void* PlayerCharacter_GetGrabObject();
};
extern FUN_0089f4e0_shell* DAT_011dea3c;
struct Holder00807080
{
    const char* bhkCharacterProxy_GethkLinearVelocity();
    void ProcessEntries_008d1180(FUN_00807770_Class*, Data08*);
};
// @fnv 0x008d1180
// src: GUESS 0x008d1180 (confidence: low)
void Holder00807080::ProcessEntries_008d1180(FUN_00807770_Class* nodes, Data08* data)
{
    int count = data->count;
    for (int i = 0; i < count; i++)
    {
        Rec08* record = &data->records[i];
        Node08* node = (Node08*)nodes->EvaluateValue_00807770(i);
        void* collision = hkpGetRigidBody(node->collision);
        bhkFilter filter(node->collision->hkpCollidable_getCollisionFilterInfo());
        int layer = filter.CFilter_GetLayer();
        if (!collision)
        {
            if (layer != 30)
            {
                record->b.SetValue(bhkCharacterProxy_GethkLinearVelocity());
                Quat08 q;
                record->a.SetValue(q.hkVector4_hkVector4(0.0f, 0.0f, 0.0f, 1.0f));
            }
        }
        else
        {
            void* ref = GetReferenceFromObject(node->collision);
            if (ref && ref == DAT_011dea3c->PlayerCharacter_GetGrabObject())
            {
                record->b.SetValue(bhkCharacterProxy_GethkLinearVelocity());
                Quat08 q;
                record->a.SetValue(q.hkVector4_hkVector4(0.0f, 0.0f, 0.0f, 1.0f));
                break;
            }
        }
    }
}
