#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#include "../../../include/hkVector4.h"
#include "../../../include/ExtraDataList.h"
#include "../../../include/BSOcclusionPlane.h"
#include "../../../include/BSThread.h"
#include "../../../include/TESDataHandler.h"

// src/fallout_shared/havok/teswaterlistener_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout_shared/havok/teswaterlistener_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/havok/teswaterlistener_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/teswaterlistener.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout_shared/havok/teswaterlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teswaterlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_0062e750_shell
{
    void* __thiscall FUN_0062e750(unsigned int flags);
    void __thiscall FUN_0062e860();
};
void __cdecl _Deallocate(void* p);
extern int DAT_011c7a3c;
void TESWaterSystem_SetCurrentWaterType(int value);
extern unsigned char DAT_011c7a5a;
void TESWaterSystem_SetCameraInPlaceableWater(unsigned char value);
extern float _DAT_011c7a5c;
void TESWaterSystem_SetCameraRelevantWaterHeight(float value);
unsigned int __cdecl GetOcclusionPlaneThreadID(BSOcclusionPlane* pPlane);
extern "C" float __cdecl ExpFloat(float);
float exp_00630aa0(float value);
extern "C" double __cdecl _exp(double);
float ExpFloat(float value);
extern float _gModifierZero;
float __cdecl SignOfFloat(float a);
struct FUN_005631e0_shell
{
    int __thiscall MaskWithField(int a);
    bool __thiscall IsNonZero(int a);
};
float __cdecl NI2HK_004a3e90(float);
struct FUN_0062e710_shell
{
    void __thiscall SetValueAt(float f, int a, int b);
};
struct FUN_006310c0_shell
{
    void __thiscall hkpRigidBody_getCenterOfMassInWorld();
};
struct FUN_00c9a460_shell
{
    void __thiscall AddObject(int a);
    void __thiscall bhkEntityListener_entityAddedCallback(int a);
};

#include <xmmintrin.h>
// @fnv 0x0062b0a0
hkSimdReal hkVector4::dot3(const hkVector4& v) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return hkSimdReal(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xy));
}

class NiPoint3E
{
  public:
    float x, y, z;
};

void __cdecl NI2HK(hkVector4* pkOut, const NiPoint3E* pkIn);
float __cdecl NI2HK_004a3e90(float fValue);
float __cdecl HK2NI(float fValue);

class SettingE
{
  public:
    float& GetValue();
};
extern SettingE g_kSpawnRadiusE;
extern SettingE g_kSpawnHeightE;

class FlagE
{
  public:
    bool* Get();
};
extern FlagE g_kPausedE;

class SoundE;
class ImpactObjE
{
  public:
    bool IsPlaying();
    void SetPlaying(bool bPlaying);
    void Attach(void* pvOwner, bool bFlag);
};

class AudioE
{
  public:
    void PlayIn(int a, ImpactObjE* pkObj, float m_fFadeDuration);
    void PlayOut(int a, ImpactObjE* pkObj, float m_fFadeDuration);
};

class AudioMgrE
{
  public:
    void ProcessActorWithFlag(int a, ImpactObjE* pkObj, float m_fFadeDuration);
    void SetPlaybackTime(int a, ImpactObjE* pkObj, float m_fFadeDuration);
};

class InterfaceE
{
  public:
    AudioMgrE* GetAudio();
};
extern InterfaceE* g_pkInterfaceE;

bool __cdecl AILinearTaskThreadManager_ShouldQueue3DTask();
AudioE* __cdecl FUN_004537b0();
ImpactObjE* __cdecl TESHavokUtilities_FindCollidableRef(void* pvObj);

class BodyE;
class RefE
{
  public:
    void* GetObject();
    BodyE* GetBody();
};

class RefPtrE
{
  public:
    RefE* operator->();
};

class ListNodeE
{
  public:
    RefPtrE* GetItem();
    bool IsEmpty();
    ListNodeE* GetNext();
};

class LockE
{
  public:
    void Lock();
    bool IsBlocked(BodyE* pkBody, bool* pbSkip);
};
extern LockE g_kSpawnLockE;

class FormArrayE
{
  public:
    unsigned int GetCount();
    void** GetAt(unsigned int i);
};

class LinkE
{
  public:
    LinkE* GetNext();
    ImpactObjE* GetOwnerObj();
};

class SpawnListBaseE
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

class SpawnListE : public SpawnListBaseE, public LinkE
{
  public:
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
    FormArrayE m_kForms;
};

class CellLinkE
{
  public:
    CellLinkE* GetNext();
};

class CellBaseE
{
  public:
    int unk00;
};

class SpawnCellE : public CellBaseE, public CellLinkE
{
  public:
    SpawnListE* GetFirstList();
};

BodyE* __cdecl hkpGetRigidBody(void* pvForm);

class ProcessE
{
  public:
    float UpdateTESState();
    void* GetWaterForm();
};

class PlayerE
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
    virtual void vp1d0();
    virtual void vp1d4();
    virtual void vp1d8();
    virtual void vp1dc();
    virtual void vp1e0();
    virtual void vp1e4();
    virtual void vp1e8();
    virtual void vp1ec();
    virtual void vp1f0();
    virtual const NiPoint3E* GetPosition();
    ProcessE* GetProcess();
};
extern PlayerE* g_pkPlayerE;

class CameraE
{
  public:
    const NiPoint3E* GetPosition();
};
CameraE* __cdecl Main_WorldRootCamera();
void __cdecl TESWaterSystem_SetCurrentWaterType(void* pvWater);

class SpawnManagerE
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ListNodeE m_kActive;
    int unk10;
    int unk14;
    SpawnCellE* m_pkCells;
    float m_fTimer;

    bool IsEnabled();
    bool TESWaterListener_ShouldProcessRigidBody(BodyE* pkBody, const hkVector4& kTarget, float fRadius, SpawnCellE* pkCell, float* pfHeight);
    int Update(BodyE* pkBody, float m_fGlyphExtent, float fTimeDelta, int iFlag);
    void Finish(int a, int b, int c);
    void TESWaterListener_Update(float fTimeDelta);
};

// Preserve the original /GS prologue with the shared union storage.
#pragma strict_gs_check(push, on)
// @fnv 0x0062ee60
// src: COMMUNITY 0x0062ee60
void SpawnManagerE::TESWaterListener_Update(float fTimeDelta)
{
    if (IsEnabled())
    {
        m_fTimer -= fTimeDelta;
        float fRadius = g_kSpawnRadiusE.GetValue();
        fRadius = fRadius * fRadius;
        fRadius = NI2HK_004a3e90(fRadius);
        float m_fGlyphExtent = NI2HK_004a3e90(g_kSpawnHeightE.GetValue());
        hkVector4 kPlayerPos;
        NI2HK(&kPlayerPos, g_pkPlayerE->GetPosition());
        hkVector4 kUnused;
        ListNodeE* pkNode = &m_kActive;
        float fFoundHeight = 0.0f;
        g_kSpawnLockE.Lock();
        while (!*g_kPausedE.Get() && pkNode && !pkNode->IsEmpty())
        {
            RefE* pkRef = pkNode->GetItem()->operator->();
            RefE* pkRef2 = pkRef;
            BodyE* pkBody = pkRef2->GetBody();
            int iResult = 0;
            if (TESWaterListener_ShouldProcessRigidBody(pkBody, kPlayerPos, fRadius, 0, &fFoundHeight))
                iResult = Update(pkBody, fFoundHeight, fTimeDelta, 0);
            if (iResult)
            {
                ImpactObjE* pkObj = TESHavokUtilities_FindCollidableRef(pkRef->GetObject());
                if (pkObj)
                {
                    fFoundHeight = HK2NI(fFoundHeight);
                    if (iResult == 1)
                    {
                        if (!pkObj->IsPlaying())
                        {
                            if (AILinearTaskThreadManager_ShouldQueue3DTask() && FUN_004537b0())
                                FUN_004537b0()->PlayIn(0, pkObj, fFoundHeight);
                            else
                                g_pkInterfaceE->GetAudio()->ProcessActorWithFlag(0, pkObj, fFoundHeight);
                        }
                        pkObj->SetPlaying(true);
                    }
                    else if (iResult == 2)
                    {
                        pkObj->SetPlaying(false);
                        if (!pkObj->IsPlaying())
                        {
                            if (AILinearTaskThreadManager_ShouldQueue3DTask() && FUN_004537b0())
                                FUN_004537b0()->PlayOut(0, pkObj, fFoundHeight);
                            else
                                g_pkInterfaceE->GetAudio()->SetPlaybackTime(0, pkObj, fFoundHeight);
                        }
                    }
                }
            }
            pkNode = pkNode->GetNext();
        }

        SpawnCellE* pkCell = m_pkCells;
        while (pkCell)
        {
            SpawnListE* pkList = pkCell->GetFirstList();
            while (pkList)
            {
                bool bSkip = false;
                for (unsigned int i = 0; i < pkList->m_kForms.GetCount(); i++)
                {
                    void* pvForm = *pkList->m_kForms.GetAt(i);
                    BodyE* pkBody = hkpGetRigidBody(pvForm);
                    int iResult = 0;
                    if (!g_kSpawnLockE.IsBlocked(pkBody, &bSkip) &&
                        TESWaterListener_ShouldProcessRigidBody(pkBody, kPlayerPos, fRadius, pkCell, &fFoundHeight))
                        iResult = Update(pkBody, fFoundHeight, fTimeDelta, 1);
                    if (iResult == 1)
                    {
                        pkList->GetOwnerObj()->SetPlaying(true);
                        pkList->GetOwnerObj()->Attach(pkCell, true);
                    }
                }
                pkList = static_cast<SpawnListE*>(pkList->LinkE::GetNext());
            }
            pkCell = static_cast<SpawnCellE*>(pkCell->CellLinkE::GetNext());
        }
        Finish(0, 1, 0);
    }
    if (Main_WorldRootCamera() && g_pkPlayerE->GetProcess())
    {
        if (Main_WorldRootCamera()->GetPosition()->z < g_pkPlayerE->GetProcess()->UpdateTESState())
            TESWaterSystem_SetCurrentWaterType(g_pkPlayerE->GetProcess()->GetWaterForm());
    }
}

#pragma strict_gs_check(pop)

class hkBoolW
{
  public:
    hkBoolW();
    operator bool() const;
    char m_cBooleanValue;
};

class NiPoint3W
{
  public:
    NiPoint3W();
    float x, y, z;
};

class TESObjectREFRW
{
  public:
    const hkVector4& GetHavokPosition() const;
    hkBoolW IsInactive() const;
};

class CharacterW
{
  public:
    void Reset();
};

class HeightSourceW
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float m_fOriginZ;
};

class GameSettingW
{
  public:
    float& GetValue();
};
extern GameSettingW g_kFloorOffsetW;

void* __cdecl bhkEntity_Getbhk(const void* pvRef);
NiPoint3W* __cdecl FUN_00458620(NiPoint3W* pkOut, const hkVector4* pkIn);
float __cdecl NI2HK_004a3e90(float fHavok);
int __cdecl FloatToInt(float fValue);

class HeightGridW
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
    unsigned int m_uiCells;
    int m_iOriginX;
    int m_iOriginY;

    float GetHeight(int iX, int iY);
    bool TESWaterListener_ShouldProcessRigidBody(TESObjectREFRW* pkRef, const hkVector4& kTarget, float fRadius, HeightSourceW* pkSource,
                      float* pfHeight);
};

// Preserve the original /GS prologue with the shared union storage.
#pragma strict_gs_check(push, on)
// @fnv 0x0062ff10
// src: COMMUNITY 0x0062ff10
bool HeightGridW::TESWaterListener_ShouldProcessRigidBody(TESObjectREFRW* pkRef, const hkVector4& kTarget, float fRadius, HeightSourceW* pkSource,
                               float* pfHeight)
{
    if (pkRef)
    {
        FUN_005631e0_shell* pkCharacter = (FUN_005631e0_shell*)bhkEntity_Getbhk(pkRef);
        if (!pkCharacter)
            return false;

        hkVector4 kPos(pkRef->GetHavokPosition());
        hkVector4 kDiff;
        kDiff.setSub4(kPos, kTarget);
        if (kDiff.lengthSquared3().getReal() > fRadius)
        {
            if (pkCharacter->IsNonZero(0x88))
            {
                if (pkRef->IsInactive())
                    ((CharacterW*)pkCharacter)->Reset();
            }
            return false;
        }

        if (pkSource)
        {
            *pfHeight = NI2HK_004a3e90(pkSource->m_fOriginZ);
        }
        else if (m_uiCells > 1)
        {
            NiPoint3W kPoint;
            FUN_00458620(&kPoint, &kPos);
            int iX = FloatToInt(kPoint.x) >> 12;
            int iY = FloatToInt(kPoint.y) >> 12;
            iX -= m_iOriginX;
            iY -= m_iOriginY;
            *pfHeight = GetHeight(iX, iY);
        }
        else
        {
            *pfHeight = GetHeight(0, 0);
        }

        float fProjectionAlongAim = NI2HK_004a3e90(g_kFloorOffsetW.GetValue());
        if (*pfHeight + fProjectionAlongAim < kPos.getComponent(2).getReal())
            return pkCharacter->IsNonZero(0x88);
        return true;
    }
    return false;
}

#pragma strict_gs_check(pop)

class S00630ae0_Source
{
  public:
    hkVector4 hkSimdReal_broadcast() const;
};

// @fnv 0x00630ae0
void hkVector4::setMul4(const hkSimdReal& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(reinterpret_cast<const S00630ae0_Source&>(a).hkSimdReal_broadcast().m_vComponents, b.m_vComponents);
}

// Emit the game entry point even though the shared declaration is inline.
hkSimdReal (hkVector4::*g_length3Implementation)() const = &hkVector4::length3;

// @fnv 0x00630b40
hkSimdReal hkVector4::length3() const
{
    return hkSimdReal(_mm_sqrt_ss(dot3(*this).getQuad()));
}

extern const __m128 DAT_010c71e0;

// Preserve the original /GS prologue with the shared union storage.
#pragma strict_gs_check(push, on)
// @fnv 0x00630bb0
void hkVector4::SetRotatedDirection(const hkVector4& source, const hkVector4& param)
{
    hkVector4 kA;
    kA.getQuad() = DAT_010c71e0;
    hkVector4 kB;
    kB.setBroadcast(source, 3);
    hkVector4 kC;
    kC.setAddMul4(kA, kB, kB);
    hkVector4 kD;
    kD.setMul4(param, kC);
    hkVector4 kE;
    kE.getQuad() = reinterpret_cast<const hkVector4&>(source.getQuad()).dot3(param).getQuad();
    kE.broadcast(0);
    kD.addMul4(kE, reinterpret_cast<const hkVector4&>(source.getQuad()));
    hkVector4 kF;
    kF.ComputeValues_00630df0(reinterpret_cast<const hkVector4&>(source.getQuad()), param);
    kD.addMul4(kB, kF);
    setAdd4(kD, kD);
}

#pragma strict_gs_check(pop)

// @fnv 0x00630ce0
void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}

// @fnv 0x00630d90
void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, const hkVector4& c)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(b.m_vComponents, c.m_vComponents));
}

// @fnv 0x00630df0
// src: GUESS 0x00630df0 (confidence: low)
void hkVector4::ComputeValues_00630df0(const hkVector4& a, const hkVector4& b)
{
    const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                     _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
    const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                     _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

// @fnv 0x00630ed0
void hkVector4::broadcast(int i)
{
    if (i == 0)
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x00);
    else if (i == 1)
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
    else if (i == 2)
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
    else if (i == 3)
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
}

// @fnv 0x00630fa0
void hkVector4::setBroadcast(const hkVector4& v, int i)
{
    if (i == 0)
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
    else if (i == 1)
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
    else if (i == 2)
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
    else if (i == 3)
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
}
