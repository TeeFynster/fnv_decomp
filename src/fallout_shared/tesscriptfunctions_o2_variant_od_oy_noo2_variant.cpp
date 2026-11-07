#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/fallout_shared/tesscriptfunctions_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /GF /Oy- (unit src/fallout_shared/tesscriptfunctions_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/tesscriptfunctions_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesscriptfunctions.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "../../include/BGSListForm.h"
#include "../../include/NiPoint3.h"
#include "../../include/Script.h"
#include "../../include/TESFaction.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESQuest.h"
#include "../../include/NiProperty.h"
#include "../../include/StrArr.h"
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

typedef ::__m128 LocalM128;
extern "C" LocalM128 _mm_load_ss(float const* _A);

struct FUN_005dbf20
{
    LocalM128 m_vValue;
    FUN_005dbf20(float f);
};
// @fnv 0x005dbf20
FUN_005dbf20::FUN_005dbf20(float f)
{
    m_vValue = _mm_load_ss(&f);
}

float BSMIN(float, float);
struct __declspec(align(16)) ObjA
{
    LocalM128 rayFrom;
    LocalM128 rayTo;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    unsigned int shapeKeys[8];
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    void FUN_004a3c20();
    void bhkPickData_SetFilter(int);
    void bhkPickData_SetFrom(NiPoint3*);
    void bhkPickData_SetTo(NiPoint3*);
    void bhkPickData_NiCalcHitPoint(NiPoint3*);
};
struct S36
{
    float matrix[9];
    void GetRowFloats(unsigned int, float*, float*, float*);
};
struct MatrixS
{
    float matrix[9];
    void FUN_006815c0();
    void FUN_005df510(unsigned int, NiPoint3*);
    NiPoint3 FUN_004b4500(NiPoint3*);
};
struct AnimS
{
    void* GetAnimationData();
};
struct NodeS
{
    S36* NiAVObject_GetWorldRotate();
};
unsigned int Main_GetWorldSceneGraph();
NiPoint3* __fastcall PlayerCharacter_GetCameraPosition(void*);
struct StrSrc
{
    void* FUN_00931ed0(int*);
};
struct Src2
{
    unsigned int CFilter_GetGroup();
};
struct StrObj
{
    int m_00;
    StrObj(int);
    void CFilter_SetLayer(int);
    void CFilter_SetGroup(unsigned int);
};
struct TESX
{
    int TES_Pick(ObjA*);
    bool ContainsPoint(NiPoint3*);
};
struct HfS
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual unsigned int Get10();
};
struct ObjX
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
    virtual bool Gate100();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w4a();
    virtual void w4b();
    virtual void w4c();
    virtual void w4d();
    virtual void w4e();
    virtual void w4f();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void w58();
    virtual void w59();
    virtual void w5a();
    virtual void w5b();
    virtual void w5c();
    virtual void w5d();
    virtual void w5e();
    virtual void w5f();
    virtual void w60();
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void w64();
    virtual void w65();
    virtual void w66();
    virtual void w67();
    virtual void w68();
    virtual void w69();
    virtual void w6a();
    virtual void w6b();
    virtual void w6c();
    virtual void w6d();
    virtual void w6e();
    virtual void w6f();
    virtual void w70();
    virtual void w71();
    virtual void w72();
    virtual void w73();
    virtual void w74();
    virtual void w75();
    virtual void w76();
    virtual void w77();
    virtual void w78();
    virtual void w79();
    virtual void w7a();
    virtual void w7b();
    virtual void w7c();
    virtual void w7d();
    virtual void w7e();
    virtual void w7f();
    virtual void w80();
    virtual void w81();
    virtual void w82();
    virtual void w83();
    virtual void w84();
    virtual void w85();
    virtual void w86();
    virtual void w87();
    virtual void w88();
    virtual void w89();
    virtual void w8a();
    virtual void w8b();
    virtual void w8c();
    virtual void w8d();
    virtual void w8e();
    virtual void w8f();
    virtual void w90();
    virtual void w91();
    virtual void w92();
    virtual void w93();
    virtual void w94();
    virtual void w95();
    virtual void w96();
    virtual void w97();
    virtual void w98();
    virtual void w99();
    virtual void w9a();
    virtual void w9b();
    virtual void w9c();
    virtual void w9d();
    virtual void w9e();
    virtual void w9f();
    virtual void wa0();
    virtual void wa1();
    virtual void wa2();
    virtual void wa3();
    virtual void wa4();
    virtual void wa5();
    virtual void wa6();
    virtual void wa7();
    virtual void wa8();
    virtual void wa9();
    virtual void waa();
    virtual void wab();
    virtual void wac();
    virtual void wad();
    virtual void wae();
    virtual void waf();
    virtual void wb0();
    virtual void wb1();
    virtual void wb2();
    virtual void wb3();
    virtual void wb4();
    virtual void wb5();
    virtual void wb6();
    virtual void wb7();
    virtual void wb8();
    virtual void wb9();
    virtual void wba();
    virtual void wbb();
    virtual void wbc();
    virtual void wbd();
    virtual void wbe();
    virtual void wbf();
    virtual void wc0();
    virtual void wc1();
    virtual void wc2();
    virtual void wc3();
    virtual void wc4();
    virtual void wc5();
    virtual void wc6();
    virtual void wc7();
    virtual void wc8();
    virtual void wc9();
    virtual void wca();
    virtual void wcb();
    virtual void wcc();
    virtual void wcd();
    virtual void wce();
    virtual void wcf();
    virtual void wd0();
    virtual void wd1();
    virtual void wd2();
    virtual void wd3();
    virtual void wd4();
    virtual void wd5();
    virtual void wd6();
    virtual void wd7();
    virtual void wd8();
    virtual void wd9();
    virtual void wda();
    virtual void wdb();
    virtual void wdc();
    virtual void wdd();
    virtual void wde();
    virtual void wdf();
    virtual void we0();
    virtual void we1();
    virtual void we2();
    virtual void we3();
    virtual void we4();
    virtual void we5();
    virtual void we6();
    virtual void we7();
    virtual void we8();
    virtual void we9();
    virtual void wea();
    virtual void web();
    virtual void wec();
    virtual void wed();
    virtual void wee();
    virtual void wef();
    virtual void wf0();
    virtual void wf1();
    virtual void wf2();
    virtual void wf3();
    virtual void wf4();
    virtual void wf5();
    virtual void wf6();
    virtual void wf7();
    virtual void wf8();
    virtual void wf9();
    virtual void wfa();
    virtual void wfb();
    virtual void wfc();
    virtual void wfd();
    virtual void wfe();
    virtual void wff();
    virtual void w100();
    virtual void w101();
    virtual void w102();
    virtual void w103();
    virtual void w104();
    virtual void w105();
    virtual void w106();
    virtual void Gate41c(float);
    void FadeIn_008bcd20();
    void TESObjectREFR_SetHealth(float);
};
struct DataHandlerS
{
    ObjX* PlaceObjectReference(void*, NiPoint3*, void*, void*, void*);
};
struct PlayerS
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
    virtual NiPoint3* GetPos1f4();
    void* FUN_00430830();
    void* GetParentCell();
    void* TESObjectREFR_GetWorldSpace(int, int, int);
};
HfS* GetHealthForm(void*);
extern PlayerS* g_thePlayer;
extern TESX* g_TES;
extern DataHandlerS* g_dataHandler;

// @fnv 0x005df040
// src: EXE 0x005df040
bool Cmd_PlaceAtReticle_Execute(const ScriptParameter* a0, const char* a1, TESObjectREFR* a2, TESObjectREFR* a3, Script* a4,
                  ScriptLocals* a5, double& result, unsigned int& a7)
{
    result = 0.0;
    void* form = 0;
    int i1 = 1;
    float f10 = 0.0f;
    float f14 = 0.0f;
    if (!ExtractArgs(a0, a1, &a7, a2, a3, a4, a5, &form, &i1, &f10, &f14))
        return false;
    f14 = BSMIN(f14, 50000.0f);
    ObjA objA;
    objA.FUN_004a3c20();
    NiPoint3 pt(0.0f, f14, 0.0f);
    // Use plain storage to preserve the original trivial point copies.
    float posStorage[3];
    reinterpret_cast<NiPoint3&>(posStorage) = *g_thePlayer->GetPos1f4();
    void* tmpEC = ((AnimS*)Main_GetWorldSceneGraph())->GetAnimationData();
    S36 s36 = *((NodeS*)tmpEC)->NiAVObject_GetWorldRotate();
    MatrixS p134;
    p134.FUN_006815c0();
    NiPoint3 p140;
    s36.GetRowFloats(0, &p140.y, &p140.z, &p140.x);
    p134.FUN_005df510(0, &p140);
    s36.GetRowFloats(1, &p140.y, &p140.z, &p140.x);
    p134.FUN_005df510(1, &p140);
    s36.GetRowFloats(2, &p140.y, &p140.z, &p140.x);
    p134.FUN_005df510(2, &p140);
    reinterpret_cast<NiPoint3&>(posStorage) = *PlayerCharacter_GetCameraPosition(g_thePlayer);
    pt = p134.FUN_004b4500(&pt) + reinterpret_cast<NiPoint3&>(posStorage);
    int out15c;
    ((StrSrc*)g_thePlayer)->FUN_00931ed0(&out15c);
    StrObj strObj(0);
    strObj.CFilter_SetLayer(6);
    int out164;
    strObj.CFilter_SetGroup(((Src2*)((StrSrc*)g_thePlayer)->FUN_00931ed0(&out164))->CFilter_GetGroup());
    objA.bhkPickData_SetFilter(strObj.m_00);
    objA.bhkPickData_SetFrom(&reinterpret_cast<NiPoint3&>(posStorage));
    objA.bhkPickData_SetTo(&pt);
    int res168 = g_TES->TES_Pick(&objA);
    (void)res168;
    NiPoint3 pt174;
    objA.bhkPickData_NiCalcHitPoint(&pt174);
    float pos180Storage[3];
    reinterpret_cast<NiPoint3&>(pos180Storage) = *g_thePlayer->GetPos1f4();
    if (((TESForm*)form)->IsActor_InEditor())
    {
        void* form2 = form;
        HfS* hf = GetHealthForm(form2);
        if (g_TES->ContainsPoint(&pt174))
        {
            reinterpret_cast<NiPoint3&>(pos180Storage) = pt174;
            result = 1.0;
            ObjX* objX =
                g_dataHandler->PlaceObjectReference(form2, &reinterpret_cast<NiPoint3&>(pos180Storage), g_thePlayer->FUN_00430830(),
                                                    g_thePlayer->GetParentCell(), g_thePlayer->TESObjectREFR_GetWorldSpace(0, 0, 0));
            if (!objX)
                return false;
            if (objX->Gate100())
            {
                ObjX* objX2 = objX;
                objX2->Gate41c(0.0f);
                objX2->FadeIn_008bcd20();
            }
            if (hf)
            {
                float fnc = (float)hf->Get10();
                fnc *= 100.0;
                objX->TESObjectREFR_SetHealth(fnc);
            }
        }
    }
    return true;
}

class S005dbe60_Vector
{
  public:
    S005dbe60_Vector();  // FUN_006815c0
    LocalM128 m_vComponents;
};

void __cdecl FUN_00458620(NiPoint3* pTarget, const S005dbe60_Vector* pValue);

class S005dbe60_Object
{
  public:
    void bhkPickData_CalcHitPoint(S005dbe60_Vector* pOut) const;
    void bhkPickData_NiCalcHitPoint(NiPoint3* pTarget) const;
};

// @fnv 0x005dbe60
// src: COMMUNITY 0x005dbe60
void S005dbe60_Object::bhkPickData_NiCalcHitPoint(NiPoint3* pTarget) const
{
    S005dbe60_Vector kValue;
    bhkPickData_CalcHitPoint(&kValue);
    FUN_00458620(pTarget, &kValue);
}

class S005dbec0_SimdReal
{
  public:
    S005dbec0_SimdReal(float f);  // FUN_005dbf20
    LocalM128 m_vValue;
};

class S005dbec0_Vector
{
  public:
    LocalM128 m_vComponents;
};

class S005dbec0_Object;

class S005dbec0_Result
{
  public:
    void hkVector4_setInterpolate4(const S005dbec0_Object* pObject, const S005dbec0_Vector* pPoint,
                      const S005dbec0_SimdReal* pScale);
};

class S005dbec0_Object
{
  public:
    void bhkPickData_CalcHitPoint(S005dbec0_Result* pOut) const;

    LocalM128 unk00;
    S005dbec0_Vector m_kPoint;
    LocalM128 unk20;
    LocalM128 unk30;
    float m_fScale;
};

// @fnv 0x005dbec0
// src: COMMUNITY 0x005dbec0
void S005dbec0_Object::bhkPickData_CalcHitPoint(S005dbec0_Result* pOut) const
{
    S005dbec0_SimdReal kScale(m_fScale);
    pOut->hkVector4_setInterpolate4(this, &m_kPoint, &kScale);
}

namespace N {
typedef ::__m128 LocalM128;
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
}
}

extern const N::LocalM128 DAT_010ec7f0;
struct BlendSource
{
    void hkSimdReal_broadcast(N::LocalM128* pOut);
};
struct BlendTarget
{
    N::LocalM128 m_uiFilterValue;
    void hkVector4_setInterpolate4(const N::LocalM128* pA, const N::LocalM128* pB, BlendSource* pSource);
};
// @fnv 0x005dbf70
// src: XBOX_PDB 0x005dbf70
void BlendTarget::hkVector4_setInterpolate4(const N::LocalM128* pA, const N::LocalM128* pB, BlendSource* pSource)
{
    N::LocalM128 pos;
    pSource->hkSimdReal_broadcast(&pos);
    N::LocalM128 delta = N::_mm_sub_ps(DAT_010ec7f0, pos);
    m_uiFilterValue = N::_mm_add_ps(N::_mm_mul_ps(delta, *pA), N::_mm_mul_ps(pos, *pB));
}

struct Q_FUN_005dbf20
{
    LocalM128 m_vValue;
    Q_FUN_005dbf20(float f);
};

// @fnv 0x005dbf20
Q_FUN_005dbf20::Q_FUN_005dbf20(float f)
{
    m_vValue = _mm_load_ss(&f);
}

namespace fnv_005df040 {
// @fnv 0x005df040
// src: EXE 0x005df040
bool Cmd_PlaceAtReticle_Execute(const ScriptParameter* a0, const char* a1, TESObjectREFR* a2, TESObjectREFR* a3, Script* a4,
                  ScriptLocals* a5, double& result, unsigned int& a7)
{
    result = 0.0;
    void* form = 0;
    int i1 = 1;
    float f10 = 0.0f;
    float f14 = 0.0f;
    if (!ExtractArgs(a0, a1, &a7, a2, a3, a4, a5, &form, &i1, &f10, &f14))
        return false;
    f14 = BSMIN(f14, 50000.0f);
    ObjA objA;
    objA.FUN_004a3c20();
    NiPoint3 pt(0.0f, f14, 0.0f);
    // Use plain storage to preserve the original trivial point copies.
    float posStorage[3];
    reinterpret_cast<NiPoint3&>(posStorage) = *g_thePlayer->GetPos1f4();
    void* tmpEC = ((AnimS*)Main_GetWorldSceneGraph())->GetAnimationData();
    S36 s36 = *((NodeS*)tmpEC)->NiAVObject_GetWorldRotate();
    MatrixS p134;
    p134.FUN_006815c0();
    NiPoint3 p140;
    s36.GetRowFloats(0, &p140.y, &p140.z, &p140.x);
    p134.FUN_005df510(0, &p140);
    s36.GetRowFloats(1, &p140.y, &p140.z, &p140.x);
    p134.FUN_005df510(1, &p140);
    s36.GetRowFloats(2, &p140.y, &p140.z, &p140.x);
    p134.FUN_005df510(2, &p140);
    reinterpret_cast<NiPoint3&>(posStorage) = *PlayerCharacter_GetCameraPosition(g_thePlayer);
    pt = p134.FUN_004b4500(&pt) + reinterpret_cast<NiPoint3&>(posStorage);
    int out15c;
    ((StrSrc*)g_thePlayer)->FUN_00931ed0(&out15c);
    StrObj strObj(0);
    strObj.CFilter_SetLayer(6);
    int out164;
    strObj.CFilter_SetGroup(((Src2*)((StrSrc*)g_thePlayer)->FUN_00931ed0(&out164))->CFilter_GetGroup());
    objA.bhkPickData_SetFilter(strObj.m_00);
    objA.bhkPickData_SetFrom(&reinterpret_cast<NiPoint3&>(posStorage));
    objA.bhkPickData_SetTo(&pt);
    int res168 = g_TES->TES_Pick(&objA);
    (void)res168;
    NiPoint3 pt174;
    objA.bhkPickData_NiCalcHitPoint(&pt174);
    float pos180Storage[3];
    reinterpret_cast<NiPoint3&>(pos180Storage) = *g_thePlayer->GetPos1f4();
    if (((TESForm*)form)->IsActor_InEditor())
    {
        void* form2 = form;
        HfS* hf = GetHealthForm(form2);
        if (g_TES->ContainsPoint(&pt174))
        {
            reinterpret_cast<NiPoint3&>(pos180Storage) = pt174;
            result = 1.0;
            ObjX* objX =
                g_dataHandler->PlaceObjectReference(form2, &reinterpret_cast<NiPoint3&>(pos180Storage), g_thePlayer->FUN_00430830(),
                                                    g_thePlayer->GetParentCell(), g_thePlayer->TESObjectREFR_GetWorldSpace(0, 0, 0));
            if (!objX)
                return false;
            if (objX->Gate100())
            {
                ObjX* objX2 = objX;
                objX2->Gate41c(0.0f);
                objX2->FadeIn_008bcd20();
            }
            if (hf)
            {
                float fnc = (float)hf->Get10();
                fnc *= 100.0;
                objX->TESObjectREFR_SetHealth(fnc);
            }
        }
    }
    return true;
}
}  // namespace fnv_005df040
