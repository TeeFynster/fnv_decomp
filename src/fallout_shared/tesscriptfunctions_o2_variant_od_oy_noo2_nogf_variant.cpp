
// src/fallout_shared/tesscriptfunctions_o2_variant_od_oy_noo2_nogf_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout_shared/tesscriptfunctions_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/tesscriptfunctions_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesscriptfunctions.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "../../include/BSSoundHandle.h"
#include "tesscriptfunctions_layout_support.h"
#include "../../include/NiPointer.h"
#include "../../include/NiProperty.h"
#include "../../include/StrArr.h"
// The layout support header already defines these shared template layouts.
#define FNV64_BSSIMPLELIST_DEFINED
#define FNV64_BSSTRINGT_DEFINED
#include "../../include/BGSListForm.h"
#include "../../include/Script.h"
#include "../../include/TESFaction.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESQuest.h"
class ScriptParameter;
#include "../../include/OBJECT_ACTION.h"
class BGSMusicType;
class FalloutAudioMedia
{
  public:
    static void PlayMedia(BGSMusicType*);
    static void EndMediaUpdate();
    static void Update();
};
class ScriptLocals;
extern bool ExtractArgs(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*,
                        ScriptLocals*, ...);
void* _NiMalloc(unsigned int);
struct Map;
struct StrArrP : StrArr
{
    StrArrP(unsigned int a, unsigned int b) : StrArr(a, b)
    {}
    virtual void V0();
};
struct FUN_00a6aa40 : NiProperty
{
    unsigned short m_uiObjectFlags;
    StrArrP m_kStringArray;
    int m_iArrayLength;
    FUN_00a6aa40();
    virtual void V0();
};

#include <xmmintrin.h>
class NiPoint3C4
{
  public:
    NiPoint3C4();
    NiPoint3C4(float fX, float fY, float fZ);
    NiPoint3C4 operator+(const NiPoint3C4& kPt) const;
    NiPoint3C4 operator-(const NiPoint3C4& kPt) const;
    NiPoint3C4 operator*(float fScale) const;
    NiPoint3C4& operator+=(const NiPoint3C4& kPt);
    NiPoint3C4& operator-=(const NiPoint3C4& kPt);
    NiPoint3C4& operator*=(float fScale);
    void Unitize();
    float x;
    float y;
    float z;
};

class NiMatrix3C4
{
  public:
    float GetEntry(unsigned int uiRow, unsigned int uiCol) const;
    float m_afEntries[3][3];
};

class NodeC4
{
  public:
    const NiMatrix3C4& GetWorldRotate();
    const NiPoint3C4& GetWorldTranslate();
};

float __cdecl FUN_005c5420();
float __cdecl NiSin_005c53d0(float fAngleDifference);
float __cdecl NiCos(float fAngleDifference);

class HitFlagC4
{
  public:
    HitFlagC4();
    bool IsHit();
    char m_cValue;
};

class HitC4
{
  public:
    HitFlagC4 GetFlag();
    __m128 m_kData[2];
};

class PickFlagsC4
{
  public:
    PickFlagsC4(int iValue);
    void SetType(int iType);
    void SetLayer(int iLayer);
    int m_iValue;
};

class PickQueryC4
{
  public:
    PickQueryC4();
    void SetFlags(PickFlagsC4 kFlags);
    void SetOrigin(const NiPoint3C4& akStart);
    void SetEnd(const NiPoint3C4& kEnd);
    __m128 m_akA[3];
    HitC4 m_kHit;
    __m128 m_akB[6];
};

class PickWorldC4
{
  public:
    bool IsInWorld(const NiPoint3C4* pkPoint);
    void* Pick(PickQueryC4& kQuery);
};
extern PickWorldC4* g_pkPickWorldC4;

class ActorC4
{
  public:
    virtual void a000();
    virtual void a001();
    virtual void a002();
    virtual void a003();
    virtual void a004();
    virtual void a005();
    virtual void a006();
    virtual void a007();
    virtual void a008();
    virtual void a009();
    virtual void a00a();
    virtual void a00b();
    virtual void a00c();
    virtual void a00d();
    virtual void a00e();
    virtual void a00f();
    virtual void a010();
    virtual void a011();
    virtual void a012();
    virtual void a013();
    virtual void a014();
    virtual void a015();
    virtual void a016();
    virtual void a017();
    virtual void a018();
    virtual void a019();
    virtual void a01a();
    virtual void a01b();
    virtual void a01c();
    virtual void a01d();
    virtual void a01e();
    virtual void a01f();
    virtual void a020();
    virtual void a021();
    virtual void a022();
    virtual void a023();
    virtual void a024();
    virtual void a025();
    virtual void a026();
    virtual void a027();
    virtual void a028();
    virtual void a029();
    virtual void a02a();
    virtual void a02b();
    virtual void a02c();
    virtual void a02d();
    virtual void a02e();
    virtual void a02f();
    virtual void a030();
    virtual void a031();
    virtual void a032();
    virtual void a033();
    virtual void a034();
    virtual void a035();
    virtual void a036();
    virtual void a037();
    virtual void a038();
    virtual void a039();
    virtual void a03a();
    virtual void a03b();
    virtual void a03c();
    virtual void a03d();
    virtual void a03e();
    virtual void a03f();
    virtual void a040();
    virtual void a041();
    virtual void a042();
    virtual void a043();
    virtual void a044();
    virtual void a045();
    virtual void a046();
    virtual void a047();
    virtual void a048();
    virtual void a049();
    virtual void a04a();
    virtual void a04b();
    virtual void a04c();
    virtual void a04d();
    virtual void a04e();
    virtual void a04f();
    virtual void a050();
    virtual void a051();
    virtual void a052();
    virtual void a053();
    virtual void a054();
    virtual void a055();
    virtual void a056();
    virtual void a057();
    virtual void a058();
    virtual void a059();
    virtual void a05a();
    virtual void a05b();
    virtual void a05c();
    virtual void a05d();
    virtual void a05e();
    virtual void a05f();
    virtual void a060();
    virtual void a061();
    virtual void a062();
    virtual void a063();
    virtual void a064();
    virtual void a065();
    virtual void a066();
    virtual void a067();
    virtual void a068();
    virtual void a069();
    virtual void a06a();
    virtual void a06b();
    virtual void a06c();
    virtual void a06d();
    virtual void a06e();
    virtual void a06f();
    virtual void a070();
    virtual void a071();
    virtual void a072();
    virtual void a073();
    virtual void a074();
    virtual void a075();
    virtual void a076();
    virtual void a077();
    virtual void a078();
    virtual void a079();
    virtual void a07a();
    virtual void a07b();
    virtual void a07c();
    virtual void a07d();
    virtual void a07e();
    virtual void a07f();
    virtual void a080();
    virtual void a081();
    virtual void a082();
    virtual void a083();
    virtual void a084();
    virtual void a085();
    virtual void a086();
    virtual void a087();
    virtual void a088();
    virtual void a089();
    virtual void a08a();
    virtual void a08b();
    virtual void a08c();
    virtual void a08d();
    virtual void a08e();
    virtual void a08f();
    virtual void a090();
    virtual void a091();
    virtual void a092();
    virtual void a093();
    virtual void a094();
    virtual void a095();
    virtual void a096();
    virtual void a097();
    virtual void a098();
    virtual void a099();
    virtual void a09a();
    virtual void a09b();
    virtual void a09c();
    virtual void a09d();
    virtual void a09e();
    virtual void a09f();
    virtual void a0a0();
    virtual void a0a1();
    virtual void a0a2();
    virtual void a0a3();
    virtual void a0a4();
    virtual void a0a5();
    virtual void a0a6();
    virtual void a0a7();
    virtual void a0a8();
    virtual void a0a9();
    virtual void a0aa();
    virtual void a0ab();
    virtual void a0ac();
    virtual void a0ad();
    virtual void a0ae();
    virtual void a0af();
    virtual void a0b0();
    virtual void a0b1();
    virtual void a0b2();
    virtual void a0b3();
    virtual void a0b4();
    virtual void a0b5();
    virtual void a0b6();
    virtual void a0b7();
    virtual void a0b8();
    virtual void a0b9();
    virtual void a0ba();
    virtual void a0bb();
    virtual void a0bc();
    virtual void a0bd();
    virtual void a0be();
    virtual void a0bf();
    virtual void a0c0();
    virtual void a0c1();
    virtual void a0c2();
    virtual void a0c3();
    virtual void a0c4();
    virtual void a0c5();
    virtual void a0c6();
    virtual void a0c7();
    virtual void a0c8();
    virtual void a0c9();
    virtual void a0ca();
    virtual void a0cb();
    virtual void a0cc();
    virtual void a0cd();
    virtual void a0ce();
    virtual void a0cf();
    virtual void a0d0();
    virtual void a0d1();
    virtual void a0d2();
    virtual void a0d3();
    virtual void a0d4();
    virtual void a0d5();
    virtual void a0d6();
    virtual void a0d7();
    virtual void a0d8();
    virtual void a0d9();
    virtual void a0da();
    virtual void a0db();
    virtual void a0dc();
    virtual void a0dd();
    virtual void a0de();
    virtual void a0df();
    virtual void a0e0();
    virtual void a0e1();
    virtual void a0e2();
    virtual void a0e3();
    virtual void a0e4();
    virtual void a0e5();
    virtual void a0e6();
    virtual void a0e7();
    virtual void a0e8();
    virtual void a0e9();
    virtual void a0ea();
    virtual void a0eb();
    virtual void a0ec();
    virtual void a0ed();
    virtual void a0ee();
    virtual void a0ef();
    virtual void a0f0();
    virtual void a0f1();
    virtual void a0f2();
    virtual void a0f3();
    virtual void a0f4();
    virtual void a0f5();
    virtual void a0f6();
    virtual void a0f7();
    virtual void a0f8();
    virtual void a0f9();
    virtual void a0fa();
    virtual void a0fb();
    virtual void a0fc();
    virtual void a0fd();
    virtual void a0fe();
    virtual void a0ff();
    virtual void a100();
    virtual void a101();
    virtual void a102();
    virtual void a103();
    virtual void a104();
    virtual void a105();
    virtual void a106();
    virtual void SetAlpha(float fAlpha);
    void Reset3D();
};

class RefC4
{
  public:
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual NodeC4* Get3D();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual const NiPoint3C4* GetPos();
    const NiPoint3C4& GetAngle();
    void* GetContainingCell();
    void* GetParentWorldspace();
    int GetLevel(int iValue);
    void SetScaleC4(float fScale);
};

class DataHandlerC4
{
  public:
    RefC4* PlaceRef(void* pvForm, NiPoint3C4* pkPos, NiPoint3C4* pkAngle, void* pvCell, void* pvWorld, void* pv0,
                    void* pv1, void* pv2);
};
extern DataHandlerC4* g_pkDataHandlerC4;

struct LevEntryC4
{
    int m_iArrayLength;
    void* m_pkForm;
};

class LevNodeC4
{
  public:
    LevEntryC4** GetItem();
    bool IsEmpty();
    LevNodeC4* GetNext();
};

class LevResultC4
{
  public:
    LevResultC4();
    ~LevResultC4();
    LevNodeC4* GetHead();
    void* m_pResource[3];
};

class LevListC4
{
  public:
    void CalculateLeveled(unsigned short usLevel, unsigned short m_usPassCountLocal, LevResultC4& kResult, int iFlags);
};


class LevCreatureC4 : public TESForm
{
  public:
    char m_acPad[0x30 - sizeof(TESForm)];
    LevListC4 m_kList;
};

class LevCharacterC4 : public TESForm
{
  public:
    char m_acPad[0x30 - sizeof(TESForm)];
    LevListC4 m_kList;
};

class BoundC4 : public TESForm
{
  public:
    float GetRadius();
};

class CountC4
{
  public:
    virtual void c000();
    virtual void c001();
    virtual void c002();
    virtual void c003();
    virtual unsigned int GetCount();
};
CountC4* __cdecl GetHealthForm(BoundC4* pkBound);

// @fnv 0x005c4b30
// src: COMMUNITY 0x005c4b30
RefC4* __cdecl PlaceAtMe(RefC4* pkRef, TESForm* pkForm, int iCount, int iDistance, int iMode, float fScale)
{
    RefC4* pkNew = 0;
    if (pkRef && pkForm)
    {
        NiPoint3C4 kAngle = pkRef->GetAngle();
        NiPoint3C4 kPos = *pkRef->GetPos();
        if (iDistance)
        {
            NodeC4* pkNode = pkRef->Get3D();
            if (pkNode)
            {
                NiPoint3C4 kWorldPosition(0.0f, 0.0f, 0.0f);
                NiMatrix3C4 kRotate = pkNode->GetWorldRotate();
                kPos = pkNode->GetWorldTranslate();
                switch (iMode)
                {
                case 2:
                case 3:
                    kWorldPosition.x = kRotate.GetEntry(0, 0);
                    kWorldPosition.y = kRotate.GetEntry(1, 0);
                    kWorldPosition.z = kRotate.GetEntry(2, 0);
                    break;
                default:
                    kWorldPosition.x = kRotate.GetEntry(0, 1);
                    kWorldPosition.y = kRotate.GetEntry(1, 1);
                    kWorldPosition.z = kRotate.GetEntry(2, 1);
                    break;
                }
                kWorldPosition *= (float)iDistance;
                switch (iMode)
                {
                case 1:
                case 2:
                    kPos -= kWorldPosition;
                    break;
                default:
                    kPos += kWorldPosition;
                    break;
                }
            }
        }
        NiPoint3C4 akPos[9];
        int iIndex = 0;
        akPos[iIndex] = kPos;
        iIndex++;
        float fAngleDifference = FUN_005c5420() * 0.785398185253143310546875;
        for (int i = 0; i < 8; i++)
        {
            akPos[iIndex] =
                kPos + NiPoint3C4(NiCos(fAngleDifference), NiSin_005c53d0(fAngleDifference), 0.0f) * 100.0f;
            iIndex++;
            fAngleDifference += 0.785398185253143310546875;
        }
        if (pkForm->GetFormType() == 0x2c || pkForm->GetFormType() == 0x2d)
        {
            int iLevel = pkRef->GetLevel(0);
            LevResultC4 kResult;
            if (pkForm->GetFormType() == 0x2c)
            {
                LevCreatureC4* pkLev = (LevCreatureC4*)pkForm;
                pkLev->m_kList.CalculateLeveled(iLevel, iCount, kResult, 0);
            }
            else
            {
                LevCharacterC4* pkLev = (LevCharacterC4*)pkForm;
                pkLev->m_kList.CalculateLeveled(iLevel, iCount, kResult, 0);
            }
            LevNodeC4* pkIter = kResult.GetHead();
            while (pkIter && !pkIter->IsEmpty())
            {
                LevEntryC4* pkEntry = *pkIter->GetItem();
                if (pkEntry && pkEntry->m_pkForm)
                {
                    while (pkEntry->m_iArrayLength > 0)
                    {
                        pkNew =
                            g_pkDataHandlerC4->PlaceRef(pkEntry->m_pkForm, &kPos, &kAngle, pkRef->GetContainingCell(),
                                                        pkRef->GetParentWorldspace(), 0, 0, 0);
                        if (pkNew && pkNew->IsActor())
                        {
                            ActorC4* pkActor = (ActorC4*)pkNew;
                            pkActor->SetAlpha(0.0f);
                            pkActor->Reset3D();
                        }
                        pkEntry->m_iArrayLength--;
                    }
                }
                pkIter = pkIter->GetNext();
            }
        }
        // The original calls TESForm virtual slot 0x39.
        else if (pkForm->IsActor_InEditor())
        {
            BoundC4* pkBound = (BoundC4*)pkForm;
            CountC4* pkCountObj = GetHealthForm(pkBound);
            bool bOutside = false;
            if (!g_pkPickWorldC4->IsInWorld(pkRef->GetPos()))
                bOutside = true;
            iIndex = 0;
            for (int j = 0; j < iCount; j++)
            {
                if (iIndex && !bOutside && g_pkPickWorldC4->IsInWorld(&akPos[iIndex]))
                {
                    PickQueryC4 kQuery;
                    PickFlagsC4 kFlags(0);
                    kFlags.SetType(0x26);
                    kFlags.SetLayer(3);
                    kQuery.SetFlags(kFlags);
                    NiPoint3C4 kStart = *pkRef->GetPos();
                    kStart.z += 64.0;
                    NiPoint3C4 kEnd = akPos[iIndex];
                    kEnd.z += 64.0;
                    kQuery.SetOrigin(kStart);
                    kQuery.SetEnd(kEnd);
                    g_pkPickWorldC4->Pick(kQuery);
                    if (kQuery.m_kHit.GetFlag().IsHit())
                    {
                        NiPoint3C4 kDelta = kEnd - kStart;
                        kDelta.Unitize();
                        kPos = kEnd - kDelta * pkBound->GetRadius();
                    }
                    else
                    {
                        kPos = kEnd;
                    }
                    kPos.z = pkRef->GetPos()->z;
                }
                else
                {
                    kPos = *pkRef->GetPos();
                }
                pkNew = g_pkDataHandlerC4->PlaceRef(pkBound, &kPos, &kAngle, pkRef->GetContainingCell(),
                                                    pkRef->GetParentWorldspace(), 0, 0, 0);
                if (!pkNew)
                    return 0;
                if (pkNew->IsActor())
                {
                    ActorC4* pkActor = (ActorC4*)pkNew;
                    pkActor->SetAlpha(0.0f);
                    pkActor->Reset3D();
                }
                if (pkCountObj)
                {
                    float fNewScale = (float)pkCountObj->GetCount();
                    fNewScale *= fScale;
                    pkNew->SetScaleC4(fNewScale);
                }
                iIndex++;
                if (iIndex == 9)
                    iIndex = 0;
            }
        }
    }
    return pkNew;
}

class NiPoint3DB
{
  public:
    NiPoint3DB();
    NiPoint3DB(float fX, float fY, float fZ);
    float x;
    float y;
    float z;
};

class NiMatrix3DB
{
  public:
    NiMatrix3DB();
    void ExtractEulerAnglesXYZ(float& fX, float& fY, float& fZ);
    float m_afEntries[3][3];
};
NiMatrix3DB __cdecl BSUtilities_GetRotationZToVectorTranspose(NiPoint3DB kNormal);

class NodeDB;
class SceneNodeDB
{
  public:
    void AddChildRef(void* pvRef);
};

class HitFlagDB
{
  public:
    HitFlagDB();
    bool IsHit();
    char m_cValue;
};

class HitDB
{
  public:
    HitFlagDB GetFlag();
    __m128 m_kData[2];
};
void __cdecl FUN_00458620(NiPoint3DB& kOut, const HitDB& kHit);

class ShapeDB;
class ContainerDB
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual ShapeDB* GetChildShape(int iKey, void* pvBuffer);
};

class ShapeDB
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual ContainerDB* GetContainer();
    int GetType();
};

class CollObjDB
{
  public:
    bool IsHavokFlag(unsigned int uiFlag);
    bool IsKeyFlag(int iKey, unsigned int uiFlag);
};
CollObjDB* __cdecl bhkShape_Getbhk(ShapeDB* pkShape);

class CollidableDB
{
  public:
    ShapeDB* GetShape();
};

class KeyBufferDB
{
  public:
    KeyBufferDB(unsigned int uiSize, unsigned int uiFlags);
    ~KeyBufferDB();
    void* GetAt(int iIndex);
    void* m_pResource;
    unsigned int m_uiSize;
};

class PickFlagsDB
{
  public:
    PickFlagsDB(int iValue);
    void SetType(int iType);
    void SetTarget(void* pvTarget);
    int m_iValue;
};
void* __cdecl bhkCollisionFilter_GetNewSystemGroup();

class PickQueryDB
{
  public:
    PickQueryDB();
    void SetFlags(PickFlagsDB kFlags);
    void SetOrigin(const NiPoint3DB& akStart);
    void SetEnd(const NiPoint3DB& kEnd);
    void GetHitPoint(NiPoint3DB& kPoint);
    __m128 m_akA[3];
    HitDB m_kHit;
    int m_aiKeys[8];
    __m128 m_kB;
    CollidableDB* m_pkCollidable;
    int m_aiPad[11];
};

class PickWorldDB
{
  public:
    void* Pick(PickQueryDB& kQuery);
};
extern PickWorldDB* g_pkPickWorldDB;

class SurfaceDB
{
  public:
    SurfaceDB(TESObjectREFR* pkRef);
    ~SurfaceDB();
    char m_acData[0x28];
};
void __cdecl GetPathingLocationNormal(SurfaceDB& kSurface, NiPoint3DB& kNormal);
void __cdecl FUN_00c82870(int iLayer, unsigned __int64 ulMask);

class RefDB
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void SetFlagsDB(unsigned int uiFlags);
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
    virtual bool Is3DLoaded();
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
    virtual NodeDB* Get3D();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual const NiPoint3DB* GetPos();
    const NiPoint3DB& GetAngle();
    SceneNodeDB* GetLinkNode();
    void* GetContainingCell();
    void* GetParentWorldspace();
    void SetDisabledDB(bool bDisabled);
    void SetPersistDB(bool bPersist);
    void SetFlagDB(bool bFlag);
};

class DataHandlerDB
{
  public:
    RefDB* PlaceRef(void* pvForm, NiPoint3DB* pkPos, NiPoint3DB* pkAngle, void* pvCell, void* pvWorld, void* pv0,
                    void* pv1, void* pv2);
};
extern DataHandlerDB* g_pkDataHandlerDB;
extern void* g_pvFormA_DB;
extern void* g_pvFormB_DB;

// @fnv 0x005db870
// src: EXE 0x005db870
bool __cdecl Cmd_AttachAshPile_Execute(const ScriptParameter* paramInfo, const char* scriptData, RefDB* thisObj,
                          TESObjectREFR* containingObj, Script* scriptObj, ScriptLocals* eventList, double& result,
                          unsigned int& opcodeOffsetPtr)
{
    int iType = 0;
    if (!ExtractArgs(paramInfo, scriptData, &opcodeOffsetPtr, (TESObjectREFR*)thisObj, containingObj, scriptObj,
                     eventList, &iType))
        return false;
    if (thisObj && thisObj->Is3DLoaded())
    {
        NodeDB* pkNode = thisObj->Get3D();
        NiPoint3DB kPos = *thisObj->GetPos();
        NiPoint3DB kAngle(0.0f, 0.0f, thisObj->GetAngle().z);
        bool bAligned = false;
        unsigned int uiMask = 0x8022802;
        FUN_00c82870(0x27, uiMask);
        PickQueryDB kQuery;
        PickFlagsDB kFlags(0);
        kFlags.SetType(0x27);
        kFlags.SetTarget(bhkCollisionFilter_GetNewSystemGroup());
        kQuery.SetFlags(kFlags);
        NiPoint3DB kStart = kPos;
        kStart.z += 32.0;
        NiPoint3DB kEnd = kPos;
        kEnd.z -= 256.0;
        kQuery.SetOrigin(kStart);
        kQuery.SetEnd(kEnd);
        g_pkPickWorldDB->Pick(kQuery);
        if (kQuery.m_kHit.GetFlag().IsHit())
        {
            bool bSurface = false;
            ShapeDB* pkShape = kQuery.m_pkCollidable->GetShape();
            CollObjDB* pkObj = bhkShape_Getbhk(pkShape);
            bSurface = pkObj->IsHavokFlag(0x40);
            if (!bSurface)
            {
                ShapeDB* pkCur = pkShape;
                ShapeDB* pkLast = 0;
                int iKey = -1;
                KeyBufferDB kBuffer(8, 0);
                for (int i = 0; i < 8 && kQuery.m_aiKeys[i] != -1; i++)
                {
                    if (pkCur->GetType() == 10)
                    {
                        i++;
                        if (i >= 8 || kQuery.m_aiKeys[i] == -1)
                            break;
                    }
                    iKey = kQuery.m_aiKeys[i];
                    pkLast = pkCur;
                    pkCur = pkCur->GetContainer()->GetChildShape(kQuery.m_aiKeys[i], kBuffer.GetAt(i));
                }
                CollObjDB* pkLastObj = bhkShape_Getbhk(pkLast);
                if (pkLastObj)
                    bSurface = pkLastObj->IsKeyFlag(iKey, 0x40);
            }
            NiPoint3DB kNormal;
            if (bSurface)
            {
                SurfaceDB kSurface((TESObjectREFR*)thisObj);
                GetPathingLocationNormal(kSurface, kNormal);
            }
            else
            {
                FUN_00458620(kNormal, kQuery.m_kHit);
            }
            NiMatrix3DB kRotate = BSUtilities_GetRotationZToVectorTranspose(kNormal);
            kRotate.ExtractEulerAnglesXYZ(kAngle.x, kAngle.y, kAngle.z);
            bAligned = true;
            kQuery.GetHitPoint(kPos);
        }
        void* pvForm = iType == 2 ? g_pvFormA_DB : g_pvFormB_DB;
        RefDB* pkNew = g_pkDataHandlerDB->PlaceRef(pvForm, &kPos, &kAngle, thisObj->GetContainingCell(),
                                                   thisObj->GetParentWorldspace(), 0, 0, 0);
        pkNew->SetDisabledDB(!bAligned);
        pkNew->SetPersistDB(true);
        pkNew->SetFlagDB(true);
        pkNew->GetLinkNode()->AddChildRef(thisObj);
        thisObj->GetLinkNode()->AddChildRef(pkNew);
        pkNew->SetFlagsDB(0x80000000);
        thisObj->SetFlagsDB(0x80000000);
    }
    return true;
}

class NiPoint3DF
{
  public:
    NiPoint3DF();
    NiPoint3DF(float fX, float fY, float fZ);
    NiPoint3DF operator+(const NiPoint3DF& kPt) const;
    float x;
    float y;
    float z;
};

class NiMatrix3DF
{
  public:
    NiMatrix3DF();
    void GetRow(unsigned int uiRow, float& f0, float& f1, float& f2) const;
    void SetRow(unsigned int uiRow, const NiPoint3DF& kRow);
    NiPoint3DF operator*(const NiPoint3DF& kPt) const;
    float m_afEntries[3][3];
};

class SceneNodeDF
{
  public:
    const NiMatrix3DF& GetRotate();
};

class SceneDF
{
  public:
    SceneNodeDF* GetNode();
};
SceneDF* __cdecl Main_GetWorldSceneGraph();

class HandleDF
{
  public:
    void* Get();
    unsigned int m_uiHandle;
};

class PlayerDF
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
    virtual const NiPoint3DF* GetLookAt();
    NiPoint3DF& GetEyePos();
    HandleDF GetHandle();
};
extern PlayerDF* g_pkPlayerDF;

class PickFlagsDF
{
  public:
    PickFlagsDF(int iValue);
    void SetType(int iType);
    void SetTarget(void* pvTarget);
    int m_iValue;
};

class PickQueryDF
{
  public:
    PickQueryDF();
    void SetFlags(PickFlagsDF kFlags);
    void SetOrigin(const NiPoint3DF& akStart);
    void SetEnd(const NiPoint3DF& kEnd);
    __m128 m_kData[11];
};

class PickWorldDF
{
  public:
    void* Pick(PickQueryDF& kQuery);
};
extern PickWorldDF* g_pkPickWorldDF;

class RefDF
{
  public:
    unsigned int GetRefID();
};
RefDF* __cdecl TESObjectREFR_FindReferenceFor3D(void* pvHit);
float __cdecl BSMIN(float fA, float fB);
void __cdecl FUN_005acc70(unsigned int* puiID, double& rdResult);

// @fnv 0x005df5d0
// src: EXE 0x005df5d0
bool __cdecl Cmd_ObjectUnderReticle_Execute(const ScriptParameter* paramInfo, const char* scriptData, TESObjectREFR* thisObj,
                          TESObjectREFR* containingObj, Script* scriptObj, ScriptLocals* eventList, double& result,
                          unsigned int& opcodeOffsetPtr)
{
    result = 0;
    int iUnused = 0;
    int iUnused2 = 1;
    float fAngleDifference = 0;
    float fDistance = 0;
    if (!ExtractArgs(paramInfo, scriptData, &opcodeOffsetPtr, thisObj, containingObj, scriptObj, eventList,
                     &fAngleDifference, &fDistance))
        return false;
    fDistance = BSMIN(fDistance, 50000.0f);
    PickQueryDF kQuery;
    NiPoint3DF kEnd(0.0f, fDistance, 0.0f);
    NiPoint3DF kStart = *g_pkPlayerDF->GetLookAt();
    SceneNodeDF* pkNode = Main_GetWorldSceneGraph()->GetNode();
    NiMatrix3DF kRotate = pkNode->GetRotate();
    NiMatrix3DF kSwizzled;
    NiPoint3DF kRow;
    kRotate.GetRow(0, kRow.y, kRow.z, kRow.x);
    kSwizzled.SetRow(0, kRow);
    kRotate.GetRow(1, kRow.y, kRow.z, kRow.x);
    kSwizzled.SetRow(1, kRow);
    kRotate.GetRow(2, kRow.y, kRow.z, kRow.x);
    kSwizzled.SetRow(2, kRow);
    kStart = g_pkPlayerDF->GetEyePos();
    kEnd = kSwizzled * kEnd + kStart;
    HandleDF kHandle = g_pkPlayerDF->GetHandle();
    PickFlagsDF kFlags(0);
    kFlags.SetType(6);
    kFlags.SetTarget(g_pkPlayerDF->GetHandle().Get());
    kQuery.SetFlags(kFlags);
    kQuery.SetOrigin(kStart);
    kQuery.SetEnd(kEnd);
    void* pvHit = g_pkPickWorldDF->Pick(kQuery);
    RefDF* pkRef = pvHit ? TESObjectREFR_FindReferenceFor3D(pvHit) : 0;
    if (pkRef)
    {
        unsigned int uiID = pkRef->GetRefID();
        FUN_005acc70(&uiID, result);
    }
    return true;
}
