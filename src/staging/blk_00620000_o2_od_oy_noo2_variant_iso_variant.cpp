// src/staging/blk_00620000_o2_od_oy_noo2_variant_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00620000_o2_od_oy_noo2_variant.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /GS /EHsc /Gy /Oy- (unit lists /MT /Od /GS /EHsc /Gy /Oy-). Declarations copied from that unit's skeleton.


// src/staging/blk_00620000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/staging/blk_00620000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00620000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/NiPoint3.h"
#include "../../include/bhkSphereShape.h"
#include "../../include/hkVector4.h"
// Collision object initialization with two filter descriptions.
#include "../../include/NiMemObject.h"
struct __declspec(align(16)) CollisionTransform
{
    float xx, xy, xz, xw;
    float yx, yy, yz, yw;
    float zx, zy, zz, zw;
    float tx, ty, tz, tw;
    void bhkTransform_setIdentity();
};
struct __declspec(align(16)) CollisionInfo
{
    void* filter;
    void* shape;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c;
    CollisionTransform transform;
    CollisionInfo();
    ~CollisionInfo();
};
struct CollisionFilter
{
    unsigned int value;
    CollisionFilter(int);
    void CFilter_SetLayer(int);
    void CFilter_SetGroup(unsigned int);
    void* Modelloader_GetReferencedThis() const;
};
class FUN_0056e2d0 : public NiMemObject
{
  public:
    void* vtable;
    unsigned int references;
    void* object;
    unsigned int flags, unk10, unk14;
    FUN_0056e2d0(const void*);
};
struct CollisionPointer
{
    FUN_0056e2d0* object;
    void operator=(FUN_0056e2d0*);
};
unsigned int __cdecl bhkCollisionFilter_GetNewSystemGroup();
struct CollisionPair
{
    CollisionPointer first;
    CollisionPointer second;
    void CameraCaster_Init(float radius, unsigned int filter);
};
struct xMemObj
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* p, unsigned int);
};
class __declspec(align(16)) xSub20
{
  public:
    float m_fVectorY, m_fVectorZ, m_fScalarPart, m_fVectorX;
    void Init();
};
class xCinfo
{
  public:
    unsigned int m_uiFilter;
    void* m_pShape;
    int m_aiPad[6];
    xSub20 m_kSub;
    int m_aiPad2[12];
    xCinfo* Construct();
    xCinfo()
    {
        Construct();
    }
    void Destroy();
    ~xCinfo()
    {
        Destroy();
    }
};
class xFilter
{
  public:
    unsigned int m_ui;
    xFilter(int i);
    void SetLayer(int i);
    void SetGroup(unsigned int ui);
    operator unsigned int();
};
class xPhantom : public xMemObj
{
  public:
    int m_ai[6];
    xPhantom(const void* pInfo);
};
template <class T> class xSP
{
  public:
    T* m_pObject;
    xSP& operator=(T* p);
};
class xPick
{
  public:
    int m_aiPad[0xe8];
    xSP<xPhantom> m_spPhantom;
    bool m_b3a4;
    unsigned int m_ui3a8;
    void HitCaster_Init(float fRadius, unsigned int uiLayer);
};
extern float DAT_0104e148;
extern float DAT_0104da48;
struct __declspec(align(16)) Box_006286f0
{
    hkVector4 lo;
    hkVector4 hi;
    Box_006286f0();
};
struct Shape_006286f0
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
    float unk28[3];
    float unk34[3];
    unsigned int GetKind();
};
struct Node_006286f0
{
    Shape_006286f0* GetShape();
};
struct Obj_006286f0
{
    Node_006286f0* Get3D();
};
struct Src_006286f0
{
    void GetBox(Box_006286f0* out);
};
struct Ptr_006286f0
{
    Src_006286f0* p;
    Src_006286f0* operator->() const;
};
// FUN_006286f0 unions six source AABBs; AddShape binds 0x00628df0 in loadedareabound.cpp.
struct LoadedAreaBoundsAccumulator
{
    int unk00;
    int unk04;
    Ptr_006286f0 sources[6];
    Obj_006286f0* unk20;
    void AddShape(Box_006286f0* box, unsigned int kind, Shape_006286f0* shape);
    void AddPoint(Box_006286f0* box, float* pt);
    void LoadedAreaBound_CheckForDynamicBodiesOutsideBound();
};
class TESForm620;
class bhkWorldObject620;
class CollisionInfo620
{
  public:
    CollisionInfo620* GetCollision();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    void* m_pvBodyA;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    void* m_pvBodyB;
    int m_iBodyIndex;
};
// The 0x00560dc0 accessor returns a physics hkVector4 in tesobjectrefr.cpp (fnv_00560d80).
class PhysicsVectorSource
{
  public:
    const void* GetPosition();
};
class bhkCharacter620
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
    virtual void* GetBody(int iIndex);
};
class bhkNode620
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
    virtual bhkCharacter620* GetCharacter();
    void* GetBody();
};
// Shape lookup at 0x004ae6a0 is also bound as bhkWorldObject::FUN_004ae6a0 in bipedanim.cpp.
class PhysicsShapeSource
{
  public:
    bhkNode620* GetNode();
};
class ImpactEvent620
{
  public:
    void SetCollision(CollisionInfo620* pkInfo);
    void SetBody(void* pvBody);
    void SetPosition(hkVector4* pkPos);
};
class FormRef620
{
  public:
    void* GetForm();
};
class ImpactHandler620
{
  public:
    virtual ImpactEvent620* CreateEvent(void* pvTarget, void* pvBody, void* pvInfo);
    FormRef620 m_kSource;
    ImpactEvent620* CreateEventDirect(void* pvTarget, void* pvBody, void* pvInfo);
};
void* __cdecl GetAVObjectForCollidable(void* pvBody);
void* __cdecl TESObjectREFR_FindReferenceFor3D(void* pvObject);
PhysicsVectorSource* __cdecl hkpGetRigidBody(void* pvForm);
void* __cdecl bhkEntity_Getbhk(const void* pvRef);
class ImpactManager620
{
  public:
    ImpactHandler620* FindHandler(void* pvSource, void* pvBody);
    ImpactHandler620* BGSZoneTargetListener_AddZoneTargetPair(CollisionInfo620* pkInfo, void* pvSource, void* pvTarget, void* pvData,
                                   bool bDirect);
};
void xFUN_004a3e00(hkVector4*, const NiPoint3&);
float xFUN_004a3e90(float);
const NiPoint3* __fastcall xFUN_0045bb80(void*);
struct xFltSetting
{
    float* Setting_Float_00403e20();
};
extern xFltSetting xg_11cc188;
struct xMid
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
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void v402();
    virtual void v403();
    virtual void v404();
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual void v413();
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void v426();
    virtual void v427();
    virtual void v428();
    virtual void v429();
    virtual void v430();
    virtual void v431();
    virtual void v432();
    virtual void v433();
    virtual void v434();
    virtual void v435();
    virtual void v436();
    virtual void* FUN_6d4();
};
struct xPlayer
{
    xMid* FUN_008d8520();
    void* FUN_009306d0();
};
extern xPlayer* xg_player_11dea3c;
struct xQty
{
    void FUN_00537e90(unsigned int);
    int m_q[3];
};
struct xEvent
{
    xEvent();
    void hkpCollisionInput_setTolerance(float);
    xQty m_iWordAt00;
    xQty m_iThirdValue;
    int m_rest[14];
};
struct xTag
{
    xTag();
    bool FUN_005609f0();
    char m_iThirdValue;
};
struct xCollector
{
    xCollector();
    ~xCollector();
    xTag hkpAllCdPointCollector_hasHit();
    int m_q[0xe8];
};
struct xNode;
struct xModel
{
    xNode* NiObjectNET_GetControllers();
};
struct xModelPtr
{
    xModel* Modelloader_GetReferencedThis();
};
struct xBody
{
    xModelPtr* GetSourceFilesFromObject();
    void bhkShapePhantom_SetPosition(hkVector4*);
};
struct xMotion
{
    float ActorPackage_GetPackageStartTime();
    void NiTimeController_SetPhase(float);
};
xMotion* __fastcall xFUN_004ae6c0(xBody*);
typedef void (*xCastFn)(xModelPtr*, xModelPtr*, xEvent*, xCollector*);
struct xEffect
{
    xCastFn GetIndexedValue(xNode*, xNode*);
    unsigned int FUN_00407840();
};
struct xEffItem
{
    xEffect* FUN_004fb070();
    unsigned int FUN_00407840();
};
struct xCaster2
{
    void DestroyDate();
    xEffItem* FUN_00541c80();
};
struct xSrc
{
    xModelPtr* TESDataHandler_GetWorldSpaceList();
};
struct xRef
{
    bool bhkCharacterController_QChaseBip();
    void* bhkCharacterProxy_GethkPosition();
    xSrc* bhkCharacterProxy_GethkShapePhantom();
    xCaster2* bhkCharacterController_GetWorld();
};
struct xBodyPtr
{
    xBody* Modelloader_GetReferencedThis();
    int m_iWordAt00;
};
struct xCaster
{
    xBodyPtr m_iWordAt00;
    xBodyPtr m_iWordAt04;
    bool CameraCaster_KeepOutOfCharacter(xRef* apRef, const NiPoint3& akPos, float afA, float afB);
};
struct __declspec(align(16)) MotionFrame
{
    __m128 value;
    float first, second;
    MotionFrame();
};
struct MotionOwner;
struct MotionWorld
{
    void InvokeInterfaceCall(hkVector4&, MotionFrame&, MotionOwner*, int);
};
struct MotionPointer
{
    MotionWorld* Modelloader_GetReferencedThis();
};
struct MotionStatus
{
    bool FUN_005609f0();
};
void NI2HK(void*, const void*);
struct MotionOwner
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Update();
    int unk004, unk008, unk00c, unk010;
    int unk014, unk018, unk01c, unk020;
    int unk024, unk028, unk02c, unk030;
    int unk034, unk038, unk03c, unk040;
    int unk044, unk048, unk04c, unk050;
    int unk054, unk058, unk05c, unk060;
    int unk064, unk068, unk06c, unk070;
    int unk074, unk078, unk07c, unk080;
    int unk084, unk088, unk08c, unk090;
    int unk094, unk098, unk09c, unk0a0;
    int unk0a4, unk0a8, unk0ac, unk0b0;
    int unk0b4, unk0b8, unk0bc, unk0c0;
    int unk0c4, unk0c8, unk0cc, unk0d0;
    int unk0d4, unk0d8, unk0dc, unk0e0;
    int unk0e4, unk0e8, unk0ec, unk0f0;
    int unk0f4, unk0f8, unk0fc, unk100;
    int unk104, unk108, unk10c, unk110;
    int unk114, unk118, unk11c, unk120;
    int unk124, unk128, unk12c, unk130;
    int unk134, unk138, unk13c, unk140;
    int unk144, unk148, unk14c, unk150;
    int unk154, unk158, unk15c, unk160;
    int unk164, unk168, unk16c, unk170;
    int unk174, unk178, unk17c, unk180;
    int unk184, unk188, unk18c, unk190;
    int unk194, unk198, unk19c, unk1a0;
    int unk1a4, unk1a8, unk1ac, unk1b0;
    int unk1b4, unk1b8, unk1bc, unk1c0;
    int unk1c4, unk1c8, unk1cc, unk1d0;
    int unk1d4, unk1d8, unk1dc, unk1e0;
    int unk1e4, unk1e8, unk1ec, unk1f0;
    int unk1f4, unk1f8, unk1fc, unk200;
    int unk204, unk208, unk20c, unk210;
    int unk214, unk218, unk21c, unk220;
    int unk224, unk228, unk22c, unk230;
    int unk234, unk238, unk23c, unk240;
    int unk244, unk248, unk24c, unk250;
    int unk254, unk258, unk25c, unk260;
    int unk264, unk268, unk26c, unk270;
    int unk274, unk278, unk27c, unk280;
    int unk284, unk288, unk28c, unk290;
    int unk294, unk298, unk29c, unk2a0;
    int unk2a4, unk2a8, unk2ac, unk2b0;
    int unk2b4, unk2b8, unk2bc, unk2c0;
    int unk2c4, unk2c8, unk2cc, unk2d0;
    int unk2d4, unk2d8, unk2dc, unk2e0;
    int unk2e4, unk2e8, unk2ec, unk2f0;
    int unk2f4, unk2f8, unk2fc, unk300;
    int unk304, unk308, unk30c, unk310;
    int unk314, unk318, unk31c, unk320;
    int unk324, unk328, unk32c, unk330;
    int unk334, unk338, unk33c, unk340;
    int unk344, unk348, unk34c, unk350;
    int unk354, unk358, unk35c, unk360;
    int unk364, unk368, unk36c, unk370;
    int unk374, unk378, unk37c, unk380;
    int unk384, unk388, unk38c, unk390;
    int unk394, unk398, unk39c;
    MotionPointer world;
    void DecalCaster_SetRadius(float);
    void FUN_006233c0(int);
    MotionStatus* hkpAllCdPointCollector_hasHit(bool&);
    void DecalCaster_GetNumCollisions();
    void DecalCaster_Pick(const void*, const void*, float);
};
class S006230f0_Source;
const hkVector4* __cdecl NI2HK(hkVector4* pOut, const S006230f0_Source* pSource);
class S006230f0_Object
{
  public:
    void bhkShapePhantom_SetPosition(const hkVector4* pValue);
    void bhkShapePhantom_setPositionNi(const S006230f0_Source* pSource);
};
class hkAabbB
{
  public:
    hkAabbB();
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};
class hkTransformB
{
  public:
    hkTransformB();
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_kColumn3;
};
class bhkShapeB;
class bhkWorldB
{
  public:
    virtual void vw000();
    virtual void vw004();
    virtual void vw008();
    virtual void vw00c();
    virtual void vw010();
    virtual void vw014();
    virtual void vw018();
    virtual void vw01c();
    virtual void vw020();
    virtual void vw024();
    virtual void vw028();
    virtual void vw02c();
    virtual void vw030();
    virtual void vw034();
    virtual void vw038();
    virtual void AddAabb(void* pvAabb);
};
class NiObjectB
{
  public:
    void* GetCollision();
};
class bhkCollisionB
{
  public:
    void* GetAabb(hkAabbB* pkOut);
};
class bhkRigidBodyB
{
  public:
    virtual void vr000();
    virtual void vr004();
    virtual void vr008();
    virtual void vr00c();
    virtual void vr010();
    virtual void vr014();
    virtual void vr018();
    virtual void vr01c();
    virtual void vr020();
    virtual void vr024();
    virtual void vr028();
    virtual void vr02c();
    virtual void vr030();
    virtual void vr034();
    virtual void vr038();
    virtual void vr03c();
    virtual void vr040();
    virtual void vr044();
    virtual void vr048();
    virtual void vr04c();
    virtual void vr050();
    virtual void vr054();
    virtual void vr058();
    virtual void vr05c();
    virtual void vr060();
    virtual void vr064();
    virtual void vr068();
    virtual void vr06c();
    virtual void vr070();
    virtual void vr074();
    virtual void vr078();
    virtual void vr07c();
    virtual void vr080();
    virtual void vr084();
    virtual void vr088();
    virtual void vr08c();
    virtual void vr090();
    virtual int IsFixed();
    virtual void vs098();
    virtual void vs09c();
    virtual void vs0a0();
    virtual void vs0a4();
    virtual void vs0a8();
    virtual void vs0ac();
    virtual void vs0b0();
    virtual void vs0b4();
    virtual void vs0b8();
    virtual void vs0bc();
    virtual void vs0c0();
    virtual void vs0c4();
    virtual void vs0c8();
    virtual void vs0cc();
    virtual void vs0d0();
    virtual void vs0d4();
    virtual void vs0d8();
    virtual void vs0dc();
    virtual void vs0e0();
    virtual void vs0e4();
    virtual void vs0e8();
    virtual void vs0ec();
    virtual void vs0f0();
    virtual void GetTransform(hkTransformB* pkOut);
    bhkCollisionB* GetCollisionObject();
    class ShapeOwnerB* GetOwner();
};
class bhkShapeB
{
  public:
    void CalcAabb(hkTransformB* pkTransform, float fTolerance, hkAabbB* pkOut);
};
class ShapeOwnerB
{
  public:
    bhkShapeB* GetShape();
};
class NiPointerB
{
  public:
    void* operator->();
};
class RefPtrB
{
  public:
    NiPointerB* Get(unsigned int i);
};
class BodyRefB
{
  public:
    bhkRigidBodyB* Get();
};
class BodyListB
{
  public:
    BodyRefB* GetAt(unsigned int i);
    unsigned int GetCount();
};
class CellObjectB
{
  public:
    BodyListB* GetBodies();
};
class CellB
{
  public:
    CellObjectB* GetObject();
};
class GridB
{
  public:
    unsigned int GetSize();
    CellB** GetContainingCell(unsigned int i, unsigned int j);
};
class PartB
{
  public:
    bhkCollisionB* GetCollision();
};
class PartRefB
{
  public:
    PartB* Get();
};
class PartListB
{
  public:
    int GetCount();
    PartB** GetAt(int i);
};
class SkeletonB
{
  public:
    PartListB* GetParts();
};
class Node3DB
{
  public:
    SkeletonB* GetSkeleton();
    bhkWorldB* GetWorld();
};
class RootB
{
  public:
    Node3DB* Get3D();
};
class TESObjectREFRB
{
  public:
    RootB* GetRoot();
    bool IsActor();
};
class SpawnAreaB
{
  public:
    bool LoadedAreaBound_GetBoundFromCell(TESObjectREFRB* pkRef, GridB* pkGrid, hkAabbB* pkOut);
};
const hkVector4& hkVector4_getZero();
// shared zero vector
struct S006288c0_Aabb
{
    S006288c0_Aabb(const hkVector4& min, const hkVector4& max);  // FUN_00628950
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};
class S006288c0_Shape
{
  public:
    const S006288c0_Aabb& hkpAabbPhantom_getAabb() const;
};
class S006288c0_Bounds
{
  public:
    void AssignFields_006281a0(const S006288c0_Aabb& aabb);
};
class S006288c0_Object
{
  public:
    S006288c0_Shape* Bipedanim_GetReferenceFlagsOrZero();
    void Object_DoNothing();
    void bhkAabbPhantom_GetAabb(S006288c0_Bounds* bounds);
};
struct __declspec(align(16)) Text628980
{
    char field_00[32];
    void Init();
};
struct List628980
{
    int field_00, field_04, field_08;
    List628980();
    ~List628980();
    int Count();
    void*& At(unsigned int);
    void Append(void* const*);
    int Find(void**, int, int);
};
struct Topic628980
{
    void* Topic();
    List628980* Responses();
};
struct Response628980
{
    void* Voice();
};
struct Voice628980
{
    int Valid();
    void* Effects();
};
struct Threshold628980
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
    virtual void Format(void*, Text628980*);
};
struct Challenge628980
{
    Threshold628980* Threshold();
};
struct Predicate628980
{
    bool Test();
};
struct Filter628980
{
    Predicate628980* Lookup(char*, Text628980*);
    int Check(Text628980*);
};
struct Owner628980
{
    void Expand(void*, List628980*);
    void ProcessEntries_00628980(Filter628980*, List628980*);
};
void* __cdecl hkpGetRigidBody(const void*);
void* __cdecl bhkEntity_Getbhk(const void*);
int __fastcall hkpRigidBody_getMotionType(void*);
struct S00628c50_Vector
{
    __m128 m_vComponents;
    void hkVector4Comparison_setAnd(const S00628c50_Vector* a, const S00628c50_Vector* b);  // setAnd
    bool hkVector4Comparison_allAreSet(int mask) const;
};
class S00628c50_Box
{
  public:
    void hkVector4_compareLessThanEqual4(S00628c50_Vector* out, const S00628c50_Vector* point) const;
    bool hkAabb_overlaps(const S00628c50_Box* other) const;

    __m128 unk00;
    S00628c50_Vector m_kCenter;
};
void __cdecl NI2HK(hkVector4* pkOut, const NiPoint3* pkIn);
class TESObjectCELLP;
class TESObjectREFRP
{
  public:
    virtual void vr000();
    virtual void vr004();
    virtual void vr008();
    virtual void vr00c();
    virtual void vr010();
    virtual void vr014();
    virtual void vr018();
    virtual void vr01c();
    virtual void vr020();
    virtual void vr024();
    virtual void vr028();
    virtual void vr02c();
    virtual void vr030();
    virtual void vr034();
    virtual void vr038();
    virtual void vr03c();
    virtual void vr040();
    virtual void vr044();
    virtual void vr048();
    virtual void vr04c();
    virtual void vr050();
    virtual void vr054();
    virtual void vr058();
    virtual void vr05c();
    virtual void vr060();
    virtual void vr064();
    virtual void vr068();
    virtual void vr06c();
    virtual void vr070();
    virtual void vr074();
    virtual void vr078();
    virtual void vr07c();
    virtual void vr080();
    virtual void vr084();
    virtual void vr088();
    virtual void vr08c();
    virtual void vr090();
    virtual void vr094();
    virtual void vr098();
    virtual void vr09c();
    virtual void vr0a0();
    virtual void vr0a4();
    virtual void vr0a8();
    virtual void vr0ac();
    virtual void vr0b0();
    virtual void vr0b4();
    virtual void vr0b8();
    virtual void vr0bc();
    virtual void vr0c0();
    virtual void vr0c4();
    virtual void vr0c8();
    virtual void vr0cc();
    virtual void vr0d0();
    virtual void vr0d4();
    virtual void vr0d8();
    virtual void vr0dc();
    virtual void vr0e0();
    virtual void vr0e4();
    virtual void vr0e8();
    virtual void vr0ec();
    virtual void vr0f0();
    virtual void vr0f4();
    virtual void vr0f8();
    virtual void vr0fc();
    virtual bool IsActor();
    virtual void vs000();
    virtual void vs004();
    virtual void vs008();
    virtual void vs00c();
    virtual void vs010();
    virtual void vs014();
    virtual void vs018();
    virtual void vs01c();
    virtual void vs020();
    virtual void vs024();
    virtual void vs028();
    virtual void vs02c();
    virtual void vs030();
    virtual bool PickPoint(NiPoint3* pkPos, NiPoint3* pkNormal, int* piCell, int iFlags);
    virtual void vt000();
    virtual void vt004();
    virtual void vt008();
    virtual void vt00c();
    virtual void vt010();
    virtual void vt014();
    virtual void vt018();
    virtual void vt01c();
    virtual void vt020();
    virtual void vt024();
    virtual void vt028();
    virtual void vt02c();
    virtual void vt030();
    virtual void vt034();
    virtual void vt038();
    virtual void vt03c();
    virtual void vt040();
    virtual void vt044();
    virtual void vt048();
    virtual void vt04c();
    virtual void vt050();
    virtual void vt054();
    virtual void vt058();
    virtual void vt05c();
    virtual void vt060();
    virtual void vt064();
    virtual void vt068();
    virtual void vt06c();
    virtual void vt070();
    virtual void vt074();
    virtual void vt078();
    virtual void vt07c();
    virtual void vt080();
    virtual void vt084();
    virtual void vt088();
    virtual void vt08c();
    virtual void vt090();
    virtual void vt094();
    virtual void vt098();
    virtual void vt09c();
    virtual void vt0a0();
    virtual void vt0a4();
    virtual void vt0a8();
    virtual void vt0ac();
    virtual void vt0b0();
    virtual void vt0b4();
    virtual void vt0b8();
    virtual void vt0bc();
    virtual void vt0c0();
    virtual void vt0c4();
    virtual void vt0c8();
    virtual void vt0cc();
    virtual void vt0d0();
    virtual void vt0d4();
    virtual void vt0d8();
    virtual void vt0dc();
    virtual void vt0e0();
    virtual void vt0e4();
    virtual void vt0e8();
    virtual void vt0ec();
    virtual void vt0f0();
    virtual void vt0f4();
    virtual void vt0f8();
    virtual void vt0fc();
    virtual void vt100();
    virtual void vt104();
    virtual void vt108();
    virtual void vt10c();
    virtual void vt110();
    virtual void vt114();
    virtual void vt118();
    virtual void vt11c();
    virtual void vt120();
    virtual void vt124();
    virtual void vt128();
    virtual void vt12c();
    virtual void vt130();
    virtual void vt134();
    virtual void vt138();
    virtual void vt13c();
    virtual void vt140();
    virtual void vt144();
    virtual void vt148();
    virtual void vt14c();
    virtual void vt150();
    virtual void vt154();
    virtual void vt158();
    virtual TESObjectCELLP* GetParentCell();
    virtual NiPoint3 GetPosition();
};
class TESObjectCELLP
{
  public:
    void* GetLandData();
    void ResolvePoint(NiPoint3* pkOut, NiPoint3* pkNormal);
};
bool __cdecl Pathing_GetNavMeshZForLocation(NiPoint3* pkPos, TESObjectCELLP* pkCell, void* pvLand, float* pfZ);
class RegionP
{
  public:
    int GetType();
};
class RegionListP
{
  public:
    RegionP* FindRegion(NiPoint3 kPos);
};
extern RegionListP* g_pkRegionsP;
struct ShapeTransformP
{
    float m_afRow[4];
};
class ShapeP
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ShapeTransformP m_kTransform;
};
class NodeP
{
  public:
    ShapeP* GetShape();
};
class BodyP
{
  public:
    NodeP* GetNode();
};
class BodyPtrP
{
  public:
    BodyP* operator->();
};
class ShapeCastP
{
  public:
    ShapeCastP();
    void Reset();
    void AddShape(const void* pvShape);
    int Cast(hkVector4* pkFrom);
    __m128 m_kFrom;
    __m128 m_kTo;
};
class SpawnPlacerP
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    BodyPtrP m_spBodyA;
    unsigned int unk14;
    unsigned int unk18;
    BodyPtrP m_spBodyB;
    TESObjectCELLP* m_pkCell;

    void LoadedAreaBound_GetGroundPos(TESObjectREFRP* pkRef, const NiPoint3* pkPos, NiPoint3* pkOut);
};
struct S00629930_Vector
{
    __m128 m_vComponents;
    void hkVector4Comparison_setAnd(const S00629930_Vector* a, const S00629930_Vector* b);  // setAnd
    bool hkVector4Comparison_allAreSet(int mask) const;
};
class S00629930_Box
{
  public:
    void hkVector4_compareLessThanEqual4(S00629930_Vector* out, const S00629930_Vector* point) const;
    bool hkAabb_containsPoint(const S00629930_Box* other) const;

    S00629930_Vector m_kStartPoint;
    S00629930_Vector m_kCenter;
};
class hkSimdRealV
{
  public:
    hkSimdRealV(float f);
    __m128 m_vValue;
};
class hkQuaternionV
{
  public:
    __m128 m_vec;
};
const hkQuaternionV& __cdecl hkQuaternion_getIdentity();
class hkTransformV
{
  public:
    hkTransformV();
    hkTransformV(const hkQuaternionV& kRot, const hkVector4& kPos);
    void SetConjugate(const hkTransformV& t);
    void SetProduct(const hkTransformV& a, const hkTransformV& b);
    const hkVector4& getTranslation() const;
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_kColumn3;
};
class SettingV
{
  public:
    float& GetValue();
};
extern SettingV g_kSmoothTimeV;
class MotionV
{
  public:
    void SetLinearVelocity(const hkVector4& kMotionVelocity);
    void Activate();
};
class BodyV
{
  public:
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
    virtual void vb050();
    virtual void vb054();
    virtual void vb058();
    virtual void vb05c();
    virtual void vb060();
    virtual void vb064();
    virtual void vb068();
    virtual void vb06c();
    virtual void vb070();
    virtual void vb074();
    virtual void vb078();
    virtual void vb07c();
    virtual void vb080();
    virtual void vb084();
    virtual void vb088();
    virtual void vb08c();
    virtual void vb090();
    virtual void vb094();
    virtual void vb098();
    virtual void vb09c();
    virtual void vb0a0();
    virtual void vb0a4();
    virtual void vb0a8();
    virtual void vb0ac();
    virtual void vb0b0();
    virtual void vb0b4();
    virtual void vb0b8();
    virtual void vb0bc();
    virtual void vb0c0();
    virtual void vb0c4();
    virtual void vb0c8();
    virtual void vb0cc();
    virtual void vb0d0();
    virtual void vb0d4();
    virtual void vb0d8();
    virtual void vb0dc();
    virtual void vb0e0();
    virtual void vb0e4();
    virtual void vb0e8();
    virtual void GetLinearVelocityVector(hkVector4& kOut);
    virtual void vbf0();
    virtual void GetTransform(hkTransformV& kOut);
    float GetTime();
    MotionV* GetMotion();
};
class NodeV
{
  public:
    BodyV* GetBody();
};
NodeV* __cdecl FUN_0043b610(void* pvRef);
struct SmoothEntryV
{
    static void* operator new(unsigned int uiSize);
    BodyV* m_pkBody;
    void* m_pvRef;
    float m_fTime;
    int m_iArrayLength;
};
class SmoothListV
{
  public:
    bool IsEmpty();
    SmoothEntryV** GetItem();
    SmoothListV* GetNext();
    void AddHead(SmoothEntryV* const& rpkEntry);
};
extern SmoothListV g_kSmoothListV;
void __cdecl TESArrowTargetListener_AddArrowTarget(const hkVector4& kTarget, void* pvRef);
hkVector4& NI2HK(hkVector4& out, const NiPoint3& in);
void TESHavokUtilities_AddAngularVelocity_0062bae0(void* obj, hkVector4& v, int flag);
void TESHavokUtilities_AddAngularVelocity(void* obj, const NiPoint3& pos, bool flag);
// These arguments are hkVector4: component access binds 0x00560d30 and addition binds 0x00553f70.
struct WorldObject62BAE0
{
    void* bhkRigidBody_GetAngularVelocity();
    void bhkRigidBody_SetAngularVelocity_005617c0(hkVector4& kVector);
};
struct Collision62BAE0
{
    WorldObject62BAE0* bhkNiCollisionObject_GetWorldObject();
};
struct Node62BAE0;
struct Object62BAE0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Node62BAE0* GetAsNode();
};
struct Node62BAE0 : public Object62BAE0
{
    unsigned int FUN_0043b480();
    Object62BAE0* FUN_0043b4a0(unsigned int i);
};
Collision62BAE0* __cdecl FUN_0043b610(Object62BAE0* pkObject);
void __cdecl TESHavokUtilities_AddAngularVelocity_0062bae0(Object62BAE0* pkObject, hkVector4* pkPoint, bool bLocal);
class S00632b40_Rotation
{
  public:
    S00632b40_Rotation();  // FUN_0056df00
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};
class FUN_00632b40 : public S00632b40_Rotation
{
  public:
    FUN_00632b40(const FUN_00632b40& t);
    hkVector4& getColumn(int i) const;  // FUN_004b4cf0

    hkVector4 m_vTranslation;
};
class InitFloats
{
  public:
    hkVector4 m_kTo;
    float m_fCoefficientA;
    float m_fB;

    InitFloats();
};
struct xHitFlag
{
    char c;
};
struct xHitRes
{
    bool FUN_005609f0();
};
class ShapePhantom;
template <class T> class ShapeCastPointer
{
  public:
    T* m_pObject;
    T* Modelloader_GetReferencedThis() const;
};
class ShapePhantom
{
  public:
    void InvokeInterfaceCall(hkVector4* pFrom, InitFloats* pRay, class ShapeCaster* pCollector, int i);
};
void NI2HK(void* pOut, const NiPoint3& kIn);
class ShapeCaster
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void Reset2();
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
    ShapeCastPointer<ShapePhantom> m_spWorld;
    void HitCaster_SetCustomPickCollisions();
    xHitRes* hkpAllCdPointCollector_hasHit(xHitFlag* pFlag);
    void hkpAllCdPointCollector_sortHits();
    bool HitCaster_CastShape(const NiPoint3& kFrom, const NiPoint3& kWorldPosition, float fDist);
};
extern "C" __m128 _mm_min_ps(__m128, __m128);
const __m128* __fastcall FUN_006815c0(const void* obj);
extern "C" __m128 __cdecl _mm_set_ss(float);
extern "C" __m128 __cdecl _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 __cdecl _mm_rsqrt_ss(__m128);
extern "C" __m128 __cdecl _mm_mul_ss(__m128, __m128);
extern "C" __m128 __cdecl _mm_sub_ss(__m128, __m128);
extern "C" __m128 __cdecl _mm_andnot_ps(__m128, __m128);
extern float DAT_01016248;
extern float DAT_01017718;
extern float DAT_01011d78;


class S0062aea0_Result
{
  public:
    void hkSimdReal_broadcast();
};


// Declaration for the helper missing from hkVector4.h; no vector layout is duplicated.
struct VectorNormalizeOperations
{
    S0062aea0_Result* hkVector4_lengthInverse3(hkVector4* temp, hkVector4* scale) const;
};

// @fnv 0x0062aea0
// src: XBOX_PDB 0x0062aea0
void hkVector4::normalize3_0062aea0()
{
    // The helper writes these SIMD temporaries without calling vector constructors.
    __m128 kScale;
    __m128 kTemp;
    reinterpret_cast<const VectorNormalizeOperations*>(this)->hkVector4_lengthInverse3(
        reinterpret_cast<hkVector4*>(&kTemp), reinterpret_cast<hkVector4*>(&kScale))->hkSimdReal_broadcast();
    m_vComponents = _mm_mul_ps(kScale, m_vComponents);
}
