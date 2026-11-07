
// src/staging/blk_009a0000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/staging/blk_009a0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_009a0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include "../../include/NiPoint3.h"
#include "../../include/Setting.h"
#include "../../include/hkVector4.h"
void __cdecl FUN_00458620(NiPoint3* pDest, const hkVector4* pSrc);
extern Setting g_kSettingE70;
extern Setting g_kSettingDBC;
extern Setting g_kSettingC9C;
extern Setting g_kSettingF64;
extern Setting g_kSetting2EC;
struct HandleB09
{
    int m_iValue;
    bool CFilter_QBipLayer();
    int CFilter_GetLayer();
};
struct FormB09
{
    void* FUN_0044ddc0();
};
struct ProcessB09
{
    float FUN_009b0bd0();
};
struct RefB09
{
    virtual void vr000();
    virtual void vr001();
    virtual void vr002();
    virtual void vr003();
    virtual void vr004();
    virtual void vr005();
    virtual void vr006();
    virtual void vr007();
    virtual void vr008();
    virtual void vr009();
    virtual void vr00a();
    virtual void vr00b();
    virtual void vr00c();
    virtual void vr00d();
    virtual void vr00e();
    virtual void vr00f();
    virtual void vr010();
    virtual void vr011();
    virtual void vr012();
    virtual void vr013();
    virtual void vr014();
    virtual void vr015();
    virtual void vr016();
    virtual void vr017();
    virtual void vr018();
    virtual void vr019();
    virtual void vr01a();
    virtual void vr01b();
    virtual void vr01c();
    virtual void vr01d();
    virtual void vr01e();
    virtual void vr01f();
    virtual void vr020();
    virtual void vr021();
    virtual void vr022();
    virtual void vr023();
    virtual void vr024();
    virtual void vr025();
    virtual void vr026();
    virtual void vr027();
    virtual void vr028();
    virtual void vr029();
    virtual void vr02a();
    virtual void vr02b();
    virtual void vr02c();
    virtual void vr02d();
    virtual void vr02e();
    virtual void vr02f();
    virtual void vr030();
    virtual void vr031();
    virtual void vr032();
    virtual void vr033();
    virtual void vr034();
    virtual void vr035();
    virtual void vr036();
    virtual void vr037();
    virtual void vr038();
    virtual void SetFlagE4(int iValue);
    virtual void vr03a();
    virtual void vr03b();
    virtual hkVector4* GetPosF0(hkVector4* pOut);
    HandleB09* bhkWorldObject_GetCollisionFilter(HandleB09* pOut);
    void* Bipedanim_GetReferenceFlagsOrZero();
    void bhkRigidBody_ApplyLinearImpulseNi(const NiPoint3& kImpulse);
    void bhkRigidBody_ApplyAngularImpulseNi(const NiPoint3& kImpulse);
};
FormB09* __cdecl FUN_004b5a20(void* pBase);
void* __cdecl TESObjectREFR_FindReferenceFor3D(void* pForm);
float __cdecl TESHavokUtilities_ScaleGameplayImpulseForce(float fValue, RefB09* pRef, int iFlag);
float __cdecl BSMIN(float fA, float fB);
float __cdecl FUN_00476b70(float fMin, float fScaledValue);
struct OwnerB09
{
    virtual void vo000();
    virtual void vo001();
    virtual void vo002();
    virtual void vo003();
    virtual void vo004();
    virtual void vo005();
    virtual void vo006();
    virtual void vo007();
    virtual void vo008();
    virtual void vo009();
    virtual void vo00a();
    virtual void vo00b();
    virtual void vo00c();
    virtual void vo00d();
    virtual void vo00e();
    virtual void vo00f();
    virtual void vo010();
    virtual void vo011();
    virtual void vo012();
    virtual void vo013();
    virtual void vo014();
    virtual void vo015();
    virtual void vo016();
    virtual void vo017();
    virtual void vo018();
    virtual void vo019();
    virtual void vo01a();
    virtual void vo01b();
    virtual void vo01c();
    virtual void vo01d();
    virtual void vo01e();
    virtual void vo01f();
    virtual void vo020();
    virtual void vo021();
    virtual void vo022();
    virtual void vo023();
    virtual void vo024();
    virtual void vo025();
    virtual void vo026();
    virtual void vo027();
    virtual void vo028();
    virtual void vo029();
    virtual void vo02a();
    virtual void vo02b();
    virtual void vo02c();
    virtual void vo02d();
    virtual void vo02e();
    virtual void vo02f();
    virtual void vo030();
    virtual void vo031();
    virtual void vo032();
    virtual void vo033();
    virtual void vo034();
    virtual void vo035();
    virtual void vo036();
    virtual void vo037();
    virtual void vo038();
    virtual void vo039();
    virtual void vo03a();
    virtual void vo03b();
    virtual void vo03c();
    virtual void vo03d();
    virtual void vo03e();
    virtual void vo03f();
    virtual void vo040();
    virtual void vo041();
    virtual void vo042();
    virtual void vo043();
    virtual void vo044();
    virtual void vo045();
    virtual void vo046();
    virtual void vo047();
    virtual void vo048();
    virtual void vo049();
    virtual void vo04a();
    virtual void vo04b();
    virtual void vo04c();
    virtual void vo04d();
    virtual void vo04e();
    virtual void vo04f();
    virtual void vo050();
    virtual void vo051();
    virtual void vo052();
    virtual void vo053();
    virtual void vo054();
    virtual void vo055();
    virtual void vo056();
    virtual void vo057();
    virtual void vo058();
    virtual void vo059();
    virtual void vo05a();
    virtual void vo05b();
    virtual void vo05c();
    virtual void vo05d();
    virtual void vo05e();
    virtual void vo05f();
    virtual void vo060();
    virtual void vo061();
    virtual void vo062();
    virtual void vo063();
    virtual void vo064();
    virtual void vo065();
    virtual void vo066();
    virtual void vo067();
    virtual void vo068();
    virtual void vo069();
    virtual void vo06a();
    virtual void vo06b();
    virtual void vo06c();
    virtual void vo06d();
    virtual void vo06e();
    virtual void vo06f();
    virtual void vo070();
    virtual void vo071();
    virtual void vo072();
    virtual void vo073();
    virtual void vo074();
    virtual void vo075();
    virtual void vo076();
    virtual void vo077();
    virtual void vo078();
    virtual void vo079();
    virtual void vo07a();
    virtual void vo07b();
    virtual void vo07c();
    virtual NiPoint3* GetPos1F4();
    ProcessB09* FUN_004181e0();
    void* QUserData();
    void Explosion_PushRigidBody(RefB09* pRef);
};

// Shared vector unions need strict GS checking to retain the original stack cookies.
#pragma strict_gs_check(push, on)
// @fnv 0x009b0920
// src: COMMUNITY 0x009b0920
void OwnerB09::Explosion_PushRigidBody(RefB09* pRef)
{
    if (pRef)
    {
        float fForce = FUN_004181e0()->FUN_009b0bd0();
        if (fForce > 0.0)
        {
            hkVector4 kPos;
            NiPoint3 kRefPos;
            FUN_00458620(&kRefPos, pRef->GetPosF0(&kPos));
            NiPoint3 kWorldPosition = kRefPos - *GetPos1F4();
            kWorldPosition.Unitize();
            HandleB09 kHandle;
            if (pRef->bhkWorldObject_GetCollisionFilter(&kHandle)->CFilter_QBipLayer())
                kWorldPosition[2] += *g_kSettingE70.GetFloat();
            bool bMatched = false;
            if (QUserData())
            {
                FormB09* pForm = FUN_004b5a20(pRef->Bipedanim_GetReferenceFlagsOrZero());
                void* pBase = pForm ? pForm->FUN_0044ddc0() : 0;
                void* pOther = TESObjectREFR_FindReferenceFor3D(pBase);
                if (pOther && pOther == QUserData())
                {
                    HandleB09 kHandle2;
                    if (pRef->bhkWorldObject_GetCollisionFilter(&kHandle2)->CFilter_GetLayer() == 20)
                        pRef->SetFlagE4(1);
                    fForce *= *g_kSettingDBC.GetFloat();
                    bMatched = true;
                }
            }
            fForce = TESHavokUtilities_ScaleGameplayImpulseForce(fForce, pRef, 1);
            if (!bMatched)
                fForce = BSMIN(fForce, *g_kSettingC9C.GetFloat());
            pRef->bhkRigidBody_ApplyLinearImpulseNi(kWorldPosition * fForce * *g_kSettingF64.GetFloat());
            NiPoint3 kRandom(FUN_00476b70(-1.0f, 1.0f), FUN_00476b70(-1.0f, 1.0f), FUN_00476b70(-1.0f, 1.0f));
            pRef->bhkRigidBody_ApplyAngularImpulseNi(kRandom * fForce * *g_kSetting2EC.GetFloat());
        }
    }
}

int __cdecl NI2HK(hkVector4*, int);
struct S009b0bf0_Obj
{
    void bhkRigidBody_ApplyLinearImpulse(int);
    void bhkRigidBody_ApplyLinearImpulseNi(int a0);
};
// @fnv 0x009b0bf0
// src: COMMUNITY 0x009b0bf0
void S009b0bf0_Obj::bhkRigidBody_ApplyLinearImpulseNi(int a0)
{
    hkVector4 box;
    bhkRigidBody_ApplyLinearImpulse(NI2HK(&box, a0));
}

hkVector4& NI2HK(hkVector4& out, const NiPoint3& in);
struct S_009b0c90
{
    int unk00;
    void bhkRigidBody_ApplyAngularImpulse(const hkVector4& v);
    void bhkRigidBody_ApplyAngularImpulseNi(const NiPoint3& p);
};
// @fnv 0x009b0c90
// src: COMMUNITY 0x009b0c90
void S_009b0c90::bhkRigidBody_ApplyAngularImpulseNi(const NiPoint3& p)
{
    hkVector4 v;
    bhkRigidBody_ApplyAngularImpulse(NI2HK(v, p));
}

#pragma strict_gs_check(pop)

typedef __m128 ContactVector369;
// A 112-byte root contact: two vectors and each root body / shape-key path.
struct FUN_00621c40
{
    ContactVector369 position, normal;
    void* rootA;
    unsigned int keyA;
    unsigned int shapePathA[8];
    void* rootB;
    unsigned int keyB;
    unsigned int shapePathB[8];
    FUN_00621c40();
    FUN_00621c40& InitializeFields_006212c0(const FUN_00621c40&);
};
struct Predicate369
{
    bool flag;
    int CompareBool(const FUN_00621c40&, const FUN_00621c40&) const;
};
// @fnv 0x009b2ed0
// src: XBOX_PDB 0x009b2ed0
void hkAlgorithm_quickSortRecursive_hkpRootCdPoint_hkAlgorithm_less_hkpRootCdPoint(FUN_00621c40* base, int lo, int hi, Predicate369 predicate)
{
    FUN_00621c40 pivot;
// Reuse the pivot while iterating the right partition (tail recursion).
restart: {
    int j = hi;
    int i = lo;
    pivot.InitializeFields_006212c0(base[(lo + hi) >> 1]);
    do
    {
        while (predicate.CompareBool(base[i], pivot))
            ++i;
        while (predicate.CompareBool(pivot, base[j]))
            --j;
        if (j >= i)
        {
            if (j != i)
            {
                FUN_00621c40 temp;
                FUN_00621c40* high = &base[j];
                FUN_00621c40* low = &base[i];
                temp.InitializeFields_006212c0(*high);
                high->InitializeFields_006212c0(*low);
                low->InitializeFields_006212c0(temp);
            }
            --j;
            ++i;
        }
    } while (i <= j);
    if (lo < j)
        hkAlgorithm_quickSortRecursive_hkpRootCdPoint_hkAlgorithm_less_hkpRootCdPoint(base, lo, j, predicate);
    if (i < hi)
    {
        lo = i;
        goto restart;
    }
}
}
