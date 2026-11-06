#include "../../../../include/NiUpdateData.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/BGSProjectile.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/BeamProjectile.h"
#include "../../../../include/MissileProjectile.h"
#include "../../../../include/Projectile.h"
#include "../../../../include/bhkHingeConstraint.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/PathingRequest.h"
#include "../../../../include/Setting.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/bhkConstraint.h"
#include "../../../../include/BGSLoadFormBuffer.h"

// Helpers absent from the shared class declarations. Calls retain their original ABI.
namespace MissileLocal {
void __cdecl Detonate();
void __cdecl GetDetonationDelay();
void __cdecl GetElapsedTime();
void __cdecl GetName();
void __cdecl GetScaleDivisor();
void __cdecl GetSceneObject();
void __cdecl GetSpeed();
void __cdecl GetTargetReference();
void __cdecl IsDeleted();
void __cdecl IsImpactFlagSet();
void __cdecl IsImpactResponseSuppressed();
void __cdecl MoveProjectile();
void __cdecl ProcessHit();
void __cdecl SetImpactFlag();
void __cdecl SetImpactFlagInt();
void __cdecl SetOrientationFromDirection();
void __cdecl SetPosAndScale();
void __cdecl SetPosition();
void __cdecl SetPositionAndDirection();
void __cdecl SetWorldTransform();
void __cdecl UpdateBeamState();
void __cdecl UpdateDetonation();
void __cdecl UpdateNodeTransformBool();
void __cdecl UpdateNodeTransformInt();
}

namespace ImpactResponse { struct ImpactVector; }
namespace fnv_009ba660 { struct MissileVector; }

// The shared Projectile API lacks the direction getter. This declaration-only
// call interface preserves its member-function structure-return ABI; it carries
// no projectile layout or inheritance.
struct ProjectileDirectionAccess
{
    ImpactResponse::ImpactVector GetContactDirection();
    fnv_009ba660::MissileVector GetMissileDirection();
};

// src/fallout/ai/combat/missileprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/missileprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_011c6278;

// @fnv 0x009b7cb0
int __cdecl FUN_009b7cb0()
{
    return DAT_011c6278;
}

extern char const* const g_01268310_arg1;

struct FUN_009ba4d0_shell
{
    char const* const* GetArg1Ptr();
};

// @fnv 0x009ba4d0
char const* const* __thiscall FUN_009ba4d0_shell::GetArg1Ptr()
{
    return &g_01268310_arg1;
}

extern "C" void __cdecl FUN_00c89640(void*);
extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);

// @fnv 0x009ba4e0
void* bhkConstraint::DestroyConstraint(unsigned int flags)
{
    this->bhkConstraint::~bhkConstraint();
    if (flags & 1)
        __Dummy_00b6fef0(this, 16);
    return this;
}

// Calls the base BeamProjectile load routine, then reads 4 bytes from the load buffer into this+0x150.
// @fnv 0x009baad0
void MissileProjectile::FUN_009baad0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<BeamProjectile*>(this)->BeamProjectile::LoadProjectile(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x150), 4);
}

void Projectile::FUN_009c58e0(BGSLoadFormBuffer* apLoadGameBuffer)
{}

// @fnv 0x009bab70
void MissileProjectile::FUN_009bab70(BGSLoadFormBuffer* apLoadGameBuffer)
{
    FUN_009c58e0(apLoadGameBuffer);
    ((int*)this)[0x150 / 4] = 0;
}

struct FUN_009b7c90_shell : BGSProjectile
{
    bool FUN_009b7c90();
};

// @fnv 0x009b7c90
bool FUN_009b7c90_shell::FUN_009b7c90()
{
    return GetFlag(0x100);
}

extern "C" void __cdecl _delete(void*, unsigned int);

// Destroys the constraint and, when flags has bit 0 set, frees the 0x10-byte object; returns this.
// @fnv 0x009ba520
void* bhkHingeConstraint::FUN_009ba520(unsigned int flags)
{
    this->bhkHingeConstraint::~bhkHingeConstraint();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

void __cdecl _Deallocate(void*);
// @fnv 0x009b7a20
void* MissileProjectile::FUN_009b7a20(unsigned int flags)
{
    FUN_009b7bc0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_009ba320_shell
{
    void FUN_009ba320(unsigned int a, unsigned int b);
    void FUN_009ba350(unsigned int);
    void FUN_009ba390(unsigned int);
};
// Calls FUN_009ba350 with a and FUN_009ba390 with b.
// @fnv 0x009ba320
void FUN_009ba320_shell::FUN_009ba320(unsigned int auiFirst, unsigned int auiSecond)
{
    FUN_009ba350(auiFirst);
    FUN_009ba390(auiSecond);
}

// 0x004ae750 null-checks and reads this+8 via 0x00620b80; ScriptLocals::GetLocalData is 0x00541c80.
struct NullableObjectDataAccess
{
    void* GetObjectData();
};

struct FUN_009ba350_shell
{
    void* m_p;
    void FUN_009ba350(NullableObjectDataAccess* p);
};
// @fnv 0x009ba350
void FUN_009ba350_shell::FUN_009ba350(NullableObjectDataAccess* p)
{
    *(void**)((char*)this + 0xc) = p ? p->GetObjectData() : 0;
}

namespace fnv_009ba390 {
struct FUN_009ba390_shell
{
    void FUN_009ba390(NullableObjectDataAccess*);
};
// @fnv 0x009ba390
void FUN_009ba390_shell::FUN_009ba390(NullableObjectDataAccess* apObjectData)
{
    *(void**)((char*)this + 0x10) = apObjectData ? apObjectData->GetObjectData() : 0;
}
}  // namespace fnv_009ba390

struct FUN_00cbe240_shell
{
    void __thiscall SetLocalTransforms(int a, int b, int c, int d);
};

struct FUN_009ba3d0_shell
{
    int m_iWordAt00;
    int m_iWordAt04;
    void FUN_009ba3d0(int a, int b, int c, int d);
};

// If the object stored at this+4 is non-null, forwards the four arguments to its SetLocalTransforms method.
// @fnv 0x009ba3d0
void FUN_009ba3d0_shell::FUN_009ba3d0(int a, int b, int c, int d)
{
    int obj = *(int*)((char*)this + 4);
    if (obj)
        ((FUN_00cbe240_shell*)obj)->SetLocalTransforms(a, b, c, d);
}

struct FUN_004b5120
{
    FUN_004b5120();
};
extern int DAT_0108febc;
extern int DAT_01268188;
struct FUN_009ba4a0 : FUN_004b5120
{
    int* m_iWordAt00;
    FUN_009ba4a0();
};
// Points the object's pointer at DAT_0108febc and increments DAT_01268188.
// @fnv 0x009ba4a0
FUN_009ba4a0::FUN_009ba4a0() : FUN_004b5120()
{
    m_iWordAt00 = &DAT_0108febc;
    DAT_01268188++;
}

extern int DAT_0108ffb4;
struct BaseS
{
    int a;
    int b;
    int c;
    int d;
    BaseS();
};
struct FUN_009ba570
{
    int v0;
    BaseS m;
    FUN_009ba570();
};
// Initializes v0 to the address of DAT_0108ffb4 and sets the embedded BaseS fields to 0, 1, 0, 0.
// @fnv 0x009ba570
FUN_009ba570::FUN_009ba570()
{
    v0 = (int)&DAT_0108ffb4;
    m.a = 0;
    m.b = 1;
    m.c = 0;
    m.d = 0;
}

void __cdecl operator delete(void*);

struct FUN_009ba5c0_shell
{
    void FUN_009ba5f0();
    void* __thiscall FUN_009ba5c0(unsigned int flags);
};

// Calls FUN_009ba5f0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x009ba5c0
void* __thiscall FUN_009ba5c0_shell::FUN_009ba5c0(unsigned int flags)
{
    FUN_009ba5f0();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_0108ffb4;

struct FUN_009ba5f0_shell
{
    void* p;
    void __thiscall FUN_009ba5f0();
    void __thiscall SetChildObject(int);
};

// @fnv 0x009ba5f0
void __thiscall FUN_009ba5f0_shell::FUN_009ba5f0()
{
    p = &DAT_0108ffb4;
    this->SetChildObject(0);
}

namespace fnv_009ba610 {
struct FUN_009ba5f0_shell
{
    void FUN_009ba5f0();
    void __thiscall FUN_009ba610();
};
// @fnv 0x009ba610
void __thiscall FUN_009ba5f0_shell::FUN_009ba610()
{
    FUN_009ba5f0();
}
}  // namespace fnv_009ba610

struct FUN_009ba630_shell
{
    void __thiscall FUN_009ba610();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_009ba610, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x009ba630
void* __thiscall FUN_009ba630_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_009ba610();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl SaveProjectile(BGSLoadFormBuffer*);
// @fnv 0x009baaa0
void MissileProjectile::FUN_009baaa0(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<void(__thiscall*)(void*, BGSLoadFormBuffer*)>(::SaveProjectile)(this, buffer);
    reinterpret_cast<BGSSaveFormBuffer*>(buffer)->SaveData(reinterpret_cast<char*>(this) + 0x150, 4, 0);
}

void __cdecl LoadMissileFormBase();
// Loads the base projectile, then processes impacts if 3D exists or marks them pending.
// @fnv 0x009bab20
void MissileProjectile::Unk_21(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<void(__thiscall*)(void*, BGSLoadFormBuffer*)>(LoadMissileFormBase)(this , apLoadGameBuffer);
    if (GetNiNode())
        FUN_009babe0();
    else
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x154) = 1;
}

// Exe 0x009b7cc0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct MissileprojectileOffset08View
{
    unsigned int GetFlags();
};

struct FUN_009a7f00_obj
{
    float FUN_00966980();
    bool FUN_009a7f80() const;
};

int DAT_011f2250;
extern double _DAT_01012060;

// Computes flags from the actor base's pathing/target state and the global flags, then sets each beam flag via FUN_005de0a0 and calls FUN_009bda10.
// @fnv 0x009b7cc0
void MissileProjectile::UpdateBeamFlags()
{
    bool bTime = reinterpret_cast<MissileprojectileOffset08View*>(&DAT_011f2250)->GetFlags() == 4;

    bool bTarget = reinterpret_cast<PathingRequest*>(FUN_004181e0())
                       ->IsRandomBelowRadiusThreshold();

    bool bPathing =
        bTime ? false
              : reinterpret_cast<FUN_009a7f00_obj*>(FUN_004181e0())->FUN_009a7f80();

    bool bNewGame =
        reinterpret_cast<FUN_009a7f00_obj*>(FUN_004181e0())->FUN_00966980() > 0.0;

    reinterpret_cast<void(__thiscall*)(void*, int, bool)>(MissileLocal::SetImpactFlag)(this, 0x10, bTarget);
    reinterpret_cast<void(__thiscall*)(void*, int, bool)>(MissileLocal::SetImpactFlag)(this, 1, bPathing);
    reinterpret_cast<void(__thiscall*)(void*, int, bool)>(MissileLocal::SetImpactFlag)(this, 8, bPathing);
    reinterpret_cast<void(__thiscall*)(void*, int, bool)>(MissileLocal::SetImpactFlag)(this, 0x20, bTarget && bPathing);
    reinterpret_cast<void(__thiscall*)(void*, int, bool)>(MissileLocal::SetImpactFlag)(this, 2, !bTarget && bPathing);
    reinterpret_cast<void(__thiscall*)(void*, int, bool)>(MissileLocal::SetImpactFlag)(this, 0x40, bNewGame && !bPathing);
    reinterpret_cast<void(__thiscall*)(void*, int, bool)>(MissileLocal::SetImpactFlag)(this, 0x100, true);
    reinterpret_cast<void(__thiscall*)(void*, int, bool)>(MissileLocal::SetImpactFlag)(this, 0x8000, !bPathing);
    reinterpret_cast<void(__thiscall*)(void*, int, bool)>(MissileLocal::SetImpactFlag)(this, 0x2000, bPathing);

    reinterpret_cast<void(__thiscall*)(void*)>(MissileLocal::UpdateBeamState)(this);
}

struct FUN_009babe0_object
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
    virtual bool Check();
};

struct FUN_009babe0_impact
{
    FUN_009babe0_object* pObject;
};

struct FUN_009babe0_list
{
    FUN_009babe0_impact** _ref_006815c0();
    FUN_009babe0_list* _ref_00726070();
};

// @fnv 0x009babe0
void MissileProjectile::FUN_009babe0()
{
    FUN_009babe0_impact* pimpact;

    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) == 4 ||
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) == 3)
    {
        pimpact = *reinterpret_cast<FUN_009babe0_list*>(&kImpacts)->_ref_006815c0();

        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) == 4)
        {
            pimpact = reinterpret_cast<FUN_009babe0_list*>(&kImpacts)->_ref_00726070()
                          ? *reinterpret_cast<FUN_009babe0_list*>(&kImpacts)
                                 ->_ref_00726070()
                                 ->_ref_006815c0()
                          : 0;
        }

        if (pimpact && pimpact->pObject && pimpact->pObject->Check())
            FUN_009b90b0();
    }

    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) == 4)
        HandleMissileImpact();
}

// Sets the missile form type and clears the missile-specific state at offsets 0x150 through 0x15c.
// @fnv 0x009b7a50
MissileProjectile::MissileProjectile(unsigned char a) : Projectile(*reinterpret_cast<bool*>(&a))
{
    SetFormType(0x3d);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) = 0;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x154) = 0;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x158) = 0.0f;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x15c) = 0.0f;
}

// Initializes the projectile base, then clears the missile-specific state.
// @fnv 0x009b7af0
MissileProjectile::MissileProjectile(int a, int b, int c, NiPoint3 position, float magnitude, float duration)
    : Projectile(a, b, c, position, magnitude, duration)
{
    SetFormType(61);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) = 0;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x154) = 0;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x158) = 0.0f;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x15c) = 0.0f;
}

struct Obj_b9999
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
    virtual Obj_b9999* v39(int);
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
    virtual void v58(Obj_b9999*);
    Obj_b9999* Probe3();
};

// @fnv 0x009b7bc0
MissileProjectile::~MissileProjectile()
{
    Obj_b9999* r;
    if (reinterpret_cast<FUN_009b7c90_shell*>(FUN_004181e0())->FUN_009b7c90())
    {
        Obj_b9999* s;
        if (reinterpret_cast<void*(__thiscall*)(void*)>(MissileLocal::GetSceneObject)(this) != 0)
        {
            r = reinterpret_cast<Obj_b9999*>(reinterpret_cast<void*(__thiscall*)(void*)>(MissileLocal::GetSceneObject)(this))->v39(FUN_009b7cb0());
            if (r != 0)
            {
                s = r->Probe3();
                s->v58(r);
            }
        }
    }
}

extern NiRTTI DAT_011f4428;
extern double _DAT_01012060;

// POD snapshot: 0x009b7e40 copies four words; NiBound's declared copy constructor adds a call.
struct ProjectileBoundSnapshot
{
    float center[3];
    float radius;
};

bool FUN_0043b300(const NiRTTI* rtti, NiAVObject* obj);

struct PathReq
{
    float GetRadiusVal();
};

// Updates the projectile's 3D node: toggles child culling by flag 0x10, rescales and repositions it from its bounds, and culls it when value A exceeds value B.
// @fnv 0x009b7e40
void MissileProjectile::UpdateProjectileNodeVisibility()
{
    NiAVObject* p3D = GetNiNode();
    if (p3D && FUN_0043b300(&DAT_011f4428, p3D))
    {
        NiNode* pNode5 = static_cast<NiNode*>(p3D);
        pNode5->SetAppCulled(false);
        if (reinterpret_cast<PathReq*>(FUN_004181e0())->GetRadiusVal() > _DAT_01012060)
        {
            if (pNode5->FUN_0045bc00(0u))
                pNode5->GetAt(0)->SetAppCulled(reinterpret_cast<bool(__thiscall*)(void*, int)>(MissileLocal::IsImpactFlagSet)(this, 0x10));
            if (pNode5->FUN_0045bc00(1u))
                pNode5->GetAt(1)->SetAppCulled(!reinterpret_cast<bool(__thiscall*)(void*, int)>(MissileLocal::IsImpactFlagSet)(this, 0x10));
        }
        if (reinterpret_cast<bool(__thiscall*)(void*, int)>(MissileLocal::IsImpactFlagSet)(this, 0x10))
        {
            ProjectileBoundSnapshot bound5 = *reinterpret_cast<const ProjectileBoundSnapshot*>(&pNode5->GetBoundingVolume());
            NiPoint3 diff2 = pNode5->FUN_0043c490() - reinterpret_cast<NiBound&>(bound5).GetNavMeshData();
            float fLen = diff2.Length() + reinterpret_cast<NiBound&>(bound5).GetRadius();
            float fScale3 = fLen / reinterpret_cast<float(__thiscall*)(void*)>(MissileLocal::GetScaleDivisor)(this);
            reinterpret_cast<void(__thiscall*)(void*, float, NiPoint3)>(MissileLocal::SetPosAndScale)(this, fScale3, NiPoint3(0.0f, fLen, 0.0f));
            reinterpret_cast<void(__thiscall*)(void*, int, int)>(MissileLocal::UpdateNodeTransformInt)(this, 0, 1);
            NiUpdateData data(0.0f, false, false);
            pNode5->UpdateWorldData(data);
            if (reinterpret_cast<float(__thiscall*)(void*)>(MissileLocal::GetElapsedTime)(this) > reinterpret_cast<float(__thiscall*)(void*)>(MissileLocal::GetDetonationDelay)(this))
                pNode5->SetAppCulled(true);
        }
    }
}

struct HitItem
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    bool flag;
};
struct HitList
{
    HitItem* value;
    void* next;
    bool FUN_008256d0();
    HitItem** FUN_006815c0();
};
struct Collider890
{
    int FUN_0043b540();
};
struct CF845
{
    int value;
    CF845(int);
    int FUN_0043b4d0();
};
bool CanProjectileHit(int, Collider890*, MissileProjectile*, void*);
// Checks the hit list and collider state, then calls ProcessHit and FUN_009b8a20 when the kind and collider conditions pass, returning true on success.
// @fnv 0x009b8900
bool MissileProjectile::FUN_009b8900(int aiArg1, int aiArg2, int aiArg3, Collider890* collider, int aiArg5, int aiArg6)
{
    bool p = reinterpret_cast<HitList*>(&kImpacts)->FUN_008256d0() || (*reinterpret_cast<HitList*>(&kImpacts)->FUN_006815c0())->flag;
    int h = collider ? CF845(collider->FUN_0043b540()).FUN_0043b4d0() : 0;
    if (p && CanProjectileHit(aiArg1, collider, this, FUN_004181e0()) &&
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150) != 3 || h == 1 || h == 2 || h == 9 || h == 17 || h == 13 || h == 20) &&
        reinterpret_cast<bool(__thiscall*)(void*, int, int, int, Collider890*, int, int)>(MissileLocal::ProcessHit)(this, aiArg1, aiArg2, aiArg3, collider, aiArg5, aiArg6))
    {
        FUN_009b8a20();
        return true;
    }
    return false;
}

class BA410Base
{
  public:
    BA410Base();
    virtual ~BA410Base();
};

class BA410Interface
{
  public:
    int unk00;
};

class BA410Source : public BA410Interface
{
  public:
    int unk04;
};

class BA410SourceLink
{
  public:
    int unk00;
};

class BA410Target : public BA410SourceLink, public BA410Source
{
};

class FUN_009ba410 : public BA410Base
{
  public:
    FUN_009ba410(BA410Target* pkTarget);
    virtual ~FUN_009ba410();

    void SetSource(BA410Source* pkSource);

    static unsigned int ms_uiInstances;
};

// Stores pkTarget as the source via SetSource and increments the static instance counter.
// @fnv 0x009ba410
FUN_009ba410::FUN_009ba410(BA410Target* pkTarget)
{
    SetSource(pkTarget);
    ++ms_uiInstances;
}

struct SpawnedBase
{
    virtual ~SpawnedBase();
    SpawnedBase();
};

struct FUN_009ba550 : SpawnedBase
{
    FUN_009ba550();
    virtual ~FUN_009ba550();
};

// @fnv 0x009ba550
FUN_009ba550::FUN_009ba550()
{}

struct UpdateVec
{
    float x, y, z;
    UpdateVec operator-(const UpdateVec&) const;
    float FUN_00457990();
};
struct UpdateMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    UpdateMatrix();
    void FUN_00524ac0(float);
    void FUN_0043f850(float);
    void FUN_004a0c90(float);
    UpdateMatrix FUN_0043f8d0(const UpdateMatrix&);
};
struct UpdateTransform
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    UpdateVec translation;
    float scale;
    UpdateTransform FUN_0062c250(const UpdateTransform&);
};
struct UpdateNode
{
    void FUN_0043fa80(const void*);
    void FUN_00440460(UpdateVec*);
    void FUN_00a68bf0();
    void FUN_00450f90(bool);
    UpdateMatrix* FUN_006a9540();
};
struct UpdateRef
{
    void* FUN_00460140();
    UpdateTransform* FUN_00461130();
    UpdateVec GetTargetPosition();
};
struct UpdateImpact
{
    unsigned int unk00;
    UpdateVec position;
    unsigned int unk10, unk14, unk18;
    UpdateRef* reference;
    unsigned int unk20, unk24;
    bool flag;
};
struct UpdateList
{
    UpdateImpact* value;
    void* next;
    bool FUN_008256d0();
    UpdateImpact** FUN_006815c0();
};
struct UpdateBase
{
    bool FUN_009b88e0();
    float GetUnka4();
    float FUN_009b88a0();
    float FUN_009b88c0();
};
struct UpdateFloatSetting
{
    float* FUN_00403e20();
};
struct UpdateBoolSetting
{
    bool* FUN_00408d60();
};
extern UpdateFloatSetting DAT_011cff34, DAT_011f210c, DAT_011ce684;
extern UpdateBoolSetting DAT_011f20ec;
struct UpdateWorld
{
    void FUN_00458e20(void*, float);
};
extern UpdateWorld* DAT_011dea10;
extern const char DAT_0108fd78[];
UpdateRef* __cdecl FUN_004b5820(void*);
void* __cdecl FUN_004b3890(const UpdateVec*, const void*, const UpdateVec*, const void*, int);
void __cdecl FUN_005b5e40(int, const char*, ...);
struct UpdateColor
{
    float r, g, b, a;
    UpdateColor(float, float, float, float);
};
// @fnv 0x009b8030
void MissileProjectile::FUN_009b8030(float afDeltaTime)
{
    if ((*reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x154)) && reinterpret_cast<UpdateNode*>(GetNiNode()))
        FUN_009babe0();
    if (reinterpret_cast<float(__thiscall*)(void*)>(MissileLocal::GetElapsedTime)(this) > reinterpret_cast<float(__thiscall*)(void*)>(MissileLocal::GetDetonationDelay)(this) && (reinterpret_cast<UpdateList*>(&kImpacts)->FUN_008256d0() || m_bHasImpactData))
        reinterpret_cast<void(__thiscall*)(void*)>(MissileLocal::Detonate)(this);
    if (FUN_00440d80() || reinterpret_cast<bool(__thiscall*)(void*)>(MissileLocal::IsDeleted)(this))
        return;
    if ((*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150)) == 4)
    {
        (*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x158)) -= afDeltaTime;
        if ((*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x158)) <= 0.0)
            reinterpret_cast<void(__thiscall*)(void*)>(MissileLocal::Detonate)(this);
    }
    if (reinterpret_cast<bool(__thiscall*)(void*, int)>(MissileLocal::IsImpactFlagSet)(this, 128) && (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150)) == 4)
    {
        UpdateImpact* impact = *reinterpret_cast<UpdateList*>(&kImpacts)->FUN_006815c0();
        if (impact)
        {
            UpdateRef* node = impact->reference ? FUN_004b5820(impact->reference->FUN_00460140()) : 0;
            UpdateNode* reference = reinterpret_cast<UpdateNode*>(GetNiNode());
            if (node && reference)
            {
                UpdateTransform worldTransform = node->FUN_00461130()->FUN_0062c250(*reinterpret_cast<UpdateTransform*>(&m_kImpactTransform));
                reference->FUN_0043fa80(&worldTransform);
                reinterpret_cast<void(__thiscall*)(void*, UpdateTransform*)>(MissileLocal::SetWorldTransform)(this, &worldTransform);
                reference->FUN_00440460(&worldTransform.translation);
                reinterpret_cast<void(__thiscall*)(void*, const UpdateVec*)>(MissileLocal::SetPosition)(this, &worldTransform.translation);
            }
            reinterpret_cast<void(__thiscall*)(void*, bool, bool)>(MissileLocal::UpdateNodeTransformBool)(this, true, false);
        }
    }
    else if (!m_bHasImpactData || reinterpret_cast<bool(__thiscall*)(void*, int)>(MissileLocal::IsImpactFlagSet)(this, 1) || (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150)) == 3)
    {
        bool stopped = !(reinterpret_cast<float(__thiscall*)(void*)>(MissileLocal::GetSpeed)(this) > 0.0);
        bool skipPosition = false;
        if (reinterpret_cast<UpdateRef*(__thiscall*)(void*)>(MissileLocal::GetTargetReference)(this))
        {
            reinterpret_cast<void(__thiscall*)(void*, UpdateVec)>(MissileLocal::SetOrientationFromDirection)(this, reinterpret_cast<UpdateRef*(__thiscall*)(void*)>(MissileLocal::GetTargetReference)(this)->GetTargetPosition());
        }
        if (!stopped)
        {
            if (reinterpret_cast<UpdateRef*(__thiscall*)(void*)>(MissileLocal::GetTargetReference)(this))
            {
                UpdateVec positionDelta = reinterpret_cast<UpdateRef*(__thiscall*)(void*)>(MissileLocal::GetTargetReference)(this)->GetTargetPosition() - *reinterpret_cast<UpdateVec*>(static_cast<const MissileProjectile*>(this)->GetPos());
                if (positionDelta.FUN_00457990() > *DAT_011cff34.FUN_00403e20())
                    skipPosition = true;
            }
            if (*DAT_011f20ec.FUN_00408d60())
            {
                UpdateVec newPosition = *reinterpret_cast<UpdateVec*>(static_cast<const MissileProjectile*>(this)->GetPos());
                reinterpret_cast<void(__thiscall*)(void*, float)>(MissileLocal::MoveProjectile)(this, afDeltaTime);
                UpdateVec color = *reinterpret_cast<UpdateVec*>(static_cast<const MissileProjectile*>(this)->GetPos());
                UpdateColor debugColor(1.0f, 1.0f, 0.0f, 1.0f);
                void* pDebugLine = FUN_004b3890(&newPosition, &debugColor, &color, &debugColor, 1);
                DAT_011dea10->FUN_00458e20(pDebugLine, *DAT_011f210c.FUN_00403e20());
            }
            else
                reinterpret_cast<void(__thiscall*)(void*, float)>(MissileLocal::MoveProjectile)(this, afDeltaTime);
        }
        bool nearby = reinterpret_cast<UpdateList*>(&kImpacts)->FUN_008256d0() || (*reinterpret_cast<UpdateList*>(&kImpacts)->FUN_006815c0())->flag;
        if (!nearby && (!reinterpret_cast<bool(__thiscall*)(void*, int)>(MissileLocal::IsImpactFlagSet)(this, 1) || reinterpret_cast<float(__thiscall*)(void*)>(MissileLocal::GetElapsedTime)(this) > reinterpret_cast<float(__thiscall*)(void*)>(MissileLocal::GetDetonationDelay)(this)))
            reinterpret_cast<void(__thiscall*)(void*, const UpdateVec*)>(MissileLocal::SetPosition)(this, &(*reinterpret_cast<UpdateList*>(&kImpacts)->FUN_006815c0())->position);
        reinterpret_cast<void(__thiscall*)(void*, bool, bool)>(MissileLocal::UpdateNodeTransformBool)(this, skipPosition, !stopped);
        if (reinterpret_cast<UpdateNode*>(GetNiNode()))
            reinterpret_cast<UpdateNode*>(GetNiNode())->FUN_00a68bf0();
        if (reinterpret_cast<UpdateBase*>(Projectile::FUN_004181e0())->FUN_009b88e0())
        {
            UpdateMatrix rotation;
            if (reinterpret_cast<UpdateBase*>(Projectile::FUN_004181e0())->GetUnka4() > 0.0)
            {
                (reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x158)->y) += reinterpret_cast<UpdateBase*>(Projectile::FUN_004181e0())->GetUnka4() * afDeltaTime;
                rotation.FUN_00524ac0(reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x158)->y);
            }
            else if (reinterpret_cast<UpdateBase*>(Projectile::FUN_004181e0())->FUN_009b88a0() > 0.0)
            {
                (reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x158)->y) += reinterpret_cast<UpdateBase*>(Projectile::FUN_004181e0())->FUN_009b88a0() * afDeltaTime;
                rotation.FUN_0043f850(reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x158)->y);
            }
            else if (reinterpret_cast<UpdateBase*>(Projectile::FUN_004181e0())->FUN_009b88c0() > 0.0)
            {
                (reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x158)->y) += reinterpret_cast<UpdateBase*>(Projectile::FUN_004181e0())->FUN_009b88c0() * afDeltaTime;
                rotation.FUN_004a0c90(reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x158)->y);
            }
            if (reinterpret_cast<UpdateNode*>(GetNiNode()))
            {
                UpdateMatrix matrix = *reinterpret_cast<UpdateNode*>(GetNiNode())->FUN_006a9540();
                matrix = matrix.FUN_0043f8d0(rotation);
                reinterpret_cast<UpdateNode*>(GetNiNode())->FUN_0043fa80(&matrix);
            }
            else
                FUN_005b5e40(11, DAT_0108fd78, reinterpret_cast<const char*(__thiscall*)(void*)>(MissileLocal::GetName)(this));
        }
    }
    reinterpret_cast<void(__thiscall*)(void*, float)>(MissileLocal::UpdateDetonation)(this, afDeltaTime);
    if (reinterpret_cast<float(__thiscall*)(void*)>(MissileLocal::GetSpeed)(this) > *DAT_011ce684.FUN_00403e20() && (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x150)) != 4)
        reinterpret_cast<void(__thiscall*)(void*)>(MissileLocal::Detonate)(this);
    if (reinterpret_cast<float(__thiscall*)(void*)>(MissileLocal::GetElapsedTime)(this) > reinterpret_cast<float(__thiscall*)(void*)>(MissileLocal::GetDetonationDelay)(this) && (reinterpret_cast<UpdateList*>(&kImpacts)->FUN_008256d0() || m_bHasImpactData))
    {
        if (reinterpret_cast<UpdateNode*>(GetNiNode()))
            reinterpret_cast<UpdateNode*>(GetNiNode())->FUN_00450f90(true);
        reinterpret_cast<void(__thiscall*)(void*)>(MissileLocal::Detonate)(this);
    }
}

namespace ImpactResponse {
// NiPoint3 layout (x,y,z; methods at NiPoint3's 0x00416870/0x00439e90/0x00439ef0/0x00439180) but POD: this /Od unit's
// original has no default-constructor calls, which the shared NiPoint3's user constructor would add.
struct ImpactVector
{
    float x, y;

  private:
    float z;
    friend class ::MissileProjectile;
  public:
    void FUN_00416870(float, float, float);
    ImpactVector FUN_00439ef0(const ImpactVector&);
    ImpactVector FUN_00439e90(const ImpactVector&);
    void FUN_00439180(float);
    float DotProduct(const ImpactVector&);
};
ImpactVector FUN_004a3760(float, const ImpactVector&);
void FUN_00525340(ImpactVector&);
double FUN_00408820(float);
double SignOfFloat(float);
extern const float DAT_01012054, DAT_010162c0;
extern ImpactVector DAT_011f426c;
struct Matrix
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    Matrix();
    void FUN_004b46a0(Matrix&);
    ImpactVector FUN_004b4500(const ImpactVector&);
};
struct Update
{
    float time;
    int flags, unknown;
    Update(float, int, int);
};
struct Node
{
    void FUN_00440460(const ImpactVector&);
    void FUN_00a59c60(const Update&);
    Matrix* FUN_00461130();
};
struct Contact
{
    int unk00;
    ImpactVector position, normal;
};
struct ContactList
{
    bool FUN_008256d0();
    Contact** FUN_006815c0();
};
struct Physics
{
    void FUN_00573ed0(bool);
};
Physics* FUN_004b5260(Node*);
void FUN_00c6a350(Node*, int, int, int, int);
void FUN_00c6a3d0(Node*, int, int, int);
void FUN_00c6a0b0(Node*, int, int, int);
int FUN_005dbe10();
void FUN_0062b8d0(Node*, const ImpactVector&, int);
void FUN_0062ba80(Node*, const ImpactVector&, int);
struct Game
{
    bool FUN_0047c850();
};
extern Game* DAT_011de45c;
struct Selection
{
    MissileProjectile* FUN_007af430();
    void SetValue(int);
};
extern Selection DAT_011f2250;
extern Setting DAT_011ce1dc;
struct Base
{
    float GetFloatAtOffset68();
};
// If the node has contacts, clears the selection, refreshes, applies physics and impulse/angular responses, and returns true.
// @fnv 0x009b8c90
} // namespace ImpactResponse

bool MissileProjectile::HandleContactResponse()
{
    using ImpactResponse::Node;
    using ImpactResponse::Contact;
    using ImpactResponse::ContactList;
    using ImpactResponse::Physics;
    using ImpactResponse::Update;
    using ImpactResponse::ImpactVector;
    using ImpactResponse::Matrix;
    using ImpactResponse::Base;
    using ImpactResponse::DAT_011f2250;
    using ImpactResponse::DAT_011de45c;
    using ImpactResponse::DAT_011f426c;
    using ImpactResponse::DAT_01012054;
    using ImpactResponse::DAT_010162c0;
    using ImpactResponse::DAT_011ce1dc;
    using ImpactResponse::FUN_004b5260;
    using ImpactResponse::FUN_00c6a350;
    using ImpactResponse::FUN_00c6a3d0;
    using ImpactResponse::FUN_00c6a0b0;
    using ImpactResponse::FUN_005dbe10;
    using ImpactResponse::FUN_0062b8d0;
    using ImpactResponse::FUN_0062ba80;
    using ImpactResponse::FUN_004a3760;
    using ImpactResponse::FUN_00525340;
    using ImpactResponse::FUN_00408820;
    using ImpactResponse::SignOfFloat;
    if (reinterpret_cast<Node*>(GetNiNode()) && !reinterpret_cast<ContactList*>(&kImpacts)->FUN_008256d0())
    {
        if (DAT_011f2250.FUN_007af430() == this)
            DAT_011f2250.SetValue(0);
        Node* node7 = reinterpret_cast<Node*>(GetNiNode());
        Contact* contact = *reinterpret_cast<ContactList*>(&kImpacts)->FUN_006815c0();
        reinterpret_cast<void(__thiscall*)(void*, int, int)>(MissileLocal::SetImpactFlagInt)(this, 4, 1);
        Unk_A9();
        Physics* physics = FUN_004b5260(node7);
        if (physics)
            physics->FUN_00573ed0(true);
        if (!DAT_011de45c->FUN_0047c850() && !reinterpret_cast<int(__thiscall*)(void*)>(MissileLocal::IsImpactResponseSuppressed)(this))
        {
            node7->FUN_00440460(contact->position);
            Update update(0.0f, 0, 0);
            node7->FUN_00a59c60(update);
        }
        FUN_00c6a350(node7, 1, 1, 0, 1);
        FUN_00c6a3d0(node7, FUN_005dbe10(), 1, 0);
        FUN_00c6a0b0(node7, 1, 1, 0);
        if (!DAT_011de45c->FUN_0047c850())
        {
            ImpactVector linear_ = DAT_011f426c;
            ImpactVector direction3;
            direction3 = FUN_004a3760(DAT_01012054, reinterpret_cast<ProjectileDirectionAccess*>(this)->GetContactDirection());
            direction3 = direction3;
            FUN_00525340(direction3);
            FUN_00525340(contact->normal);
            float dot = contact->normal.DotProduct(direction3);
            ImpactVector correctionTmp =
                FUN_004a3760(DAT_010162c0, FUN_004a3760(dot, contact->normal).FUN_00439ef0(direction3));
            linear_ = direction3.FUN_00439e90(correctionTmp);
            linear_.FUN_00439180(*DAT_011ce1dc.FUN_00403e20() * reinterpret_cast<Base*>(Projectile::FUN_004181e0())->GetFloatAtOffset68());
            FUN_0062b8d0(node7, linear_, 1);
            ImpactVector kAngular = DAT_011f426c;
            Matrix rotation;
            reinterpret_cast<Node*>(GetNiNode())->FUN_00461130()->FUN_004b46a0(rotation);
            ImpactVector local = rotation.FUN_004b4500(contact->normal);
            if (FUN_00408820(local.y) > FUN_00408820(local.z))
                local.z = FUN_00408820(local.y) * SignOfFloat(local.z);
            local.y = 0.0f;
            FUN_00525340(local);
            ImpactVector spin2;
            spin2.FUN_00416870(-local.z, 0.0f, -local.x);
            kAngular = node7->FUN_00461130()->FUN_004b4500(spin2);
            kAngular.FUN_00439180(*DAT_011ce1dc.FUN_00403e20());
            FUN_0062ba80(node7, kAngular, 1);
        }
    }
    return true;
}namespace fnv_009ba660 {
struct MissileNode;
struct MissileBody;
struct MissileVector
{
    float x, y, z;
    MissileVector FUN_00439e90() const;
    MissileVector ApplyScaled(float) const;
};
struct MissileTransform
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    MissileVector translation;
    float scale;
    MissileTransform();
    void FUN_004b4880(MissileTransform&);
    MissileTransform FUN_0062c250(const MissileTransform&) const;
};
struct MissileUpdate
{
    float time;
    int flags;
    int frame;
    MissileUpdate(float, bool, bool);
};
struct MissileHandle
{
    unsigned value;
    unsigned FUN_0043b4d0();
    void FUN_004a39f0(unsigned);
};
struct MissileBody
{
    MissileHandle FUN_0043b4f0();
    void FUN_00626cb0(unsigned);
    int FUN_00517630();
    void SetFlag(unsigned, bool);
};
struct MissileCollision
{
    MissileBody* FUN_006fa820();
};
struct MissileSetting
{
    float* FUN_00403e20();
};
extern MissileSetting DAT_011cfc8c;
struct MissilePause
{
    bool FUN_0042ce10();
};
extern MissilePause* DAT_011ddf38;
struct MissileVats
{
    MissileProjectile* FUN_007af430();
    void SetValue(int);
};
struct MissileQueue
{
    void FUN_005ae3d0(MissileProjectile* const&);
};
struct MissileManager
{
    MissileQueue* GetOffset70Ptr();
};
extern MissileManager DAT_011e0e80;
struct MissileReference
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual void Slot9C();
    virtual void SlotA0();
    virtual void SlotA4();
    virtual void SlotA8();
    virtual void SlotAC();
    virtual void SlotB0();
    virtual void SlotB4();
    virtual void SlotB8();
    virtual void SlotBC();
    virtual void SlotC0();
    virtual void SlotC4();
    virtual void SlotC8();
    virtual void SlotCC();
    virtual void SlotD0();
    virtual void SlotD4();
    virtual void SlotD8();
    virtual void SlotDC();
    virtual void SlotE0();
    virtual void SlotE4();
    virtual void SlotE8();
    virtual void SlotEC();
    virtual void SlotF0();
    virtual void SlotF4();
    virtual void SlotF8();
    virtual void SlotFC();
    virtual bool IsActor();
};
struct MissileHit
{
    MissileReference* reference;
    MissileVector position;
    int unk10, unk14, unk18;
    MissileNode* node;
};
struct MissileHitHandle
{
    unsigned value;
    bool FUN_008256d0();
    MissileHit** FUN_006815c0();
};
MissileNode* FUN_004b5820(void*);
MissileBody* FUN_004b5a80(MissileNode*);
MissileCollision* FUN_004b5260(MissileNode*);
void FUN_00c69f50(MissileNode*, int, int);
void FUN_00c6a350(MissileNode*, int, int, int, int);
int FUN_009b7cb0();
const float DAT_01017b78 = 10.0f;
struct MissileNode
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual MissileNode* Find(int);
    void* FUN_00460140();
    void FUN_00a59c60(MissileUpdate*);
    MissileTransform* FUN_00461130();
};
// @fnv 0x009ba660
} // namespace fnv_009ba660

void MissileProjectile::HandleMissileImpact()
{
    using fnv_009ba660::MissileNode;
    using fnv_009ba660::MissileHitHandle;
    using fnv_009ba660::MissileHit;
    using fnv_009ba660::MissileVats;
    using fnv_009ba660::MissileBody;
    using fnv_009ba660::MissileCollision;
    using fnv_009ba660::MissileHandle;
    using fnv_009ba660::MissileVector;
    using fnv_009ba660::MissileUpdate;
    using fnv_009ba660::MissileQueue;
    using fnv_009ba660::MissileTransform;
    using fnv_009ba660::DAT_011cfc8c;
    using fnv_009ba660::DAT_011ddf38;
    using fnv_009ba660::DAT_011e0e80;
    using fnv_009ba660::DAT_01017b78;
    using fnv_009ba660::FUN_004b5820;
    using fnv_009ba660::FUN_004b5a80;
    using fnv_009ba660::FUN_004b5260;
    using fnv_009ba660::FUN_00c69f50;
    using fnv_009ba660::FUN_00c6a350;
    using fnv_009ba660::FUN_009b7cb0;
    static float impactScale = *DAT_011cfc8c.FUN_00403e20();
    bool paused = DAT_011ddf38->FUN_0042ce10();
    if (reinterpret_cast<MissileNode*>(GetNiNode()) && !reinterpret_cast<MissileHitHandle*>(&kImpacts)->FUN_008256d0())
    {
        if (((MissileVats*)&DAT_011f2250)->FUN_007af430() == this)
            ((MissileVats*)&DAT_011f2250)->SetValue(0);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x158) = DAT_01017b78;
        MissileHit* hit31 = *reinterpret_cast<MissileHitHandle*>(&kImpacts)->FUN_006815c0();
        if (!hit31 || !hit31->node)
            return;
        MissileNode* node3 = reinterpret_cast<MissileNode*>(GetNiNode());
        MissileNode* parent41 = FUN_004b5820(hit31->node->FUN_00460140());
        MissileBody* body20 = FUN_004b5a80(hit31->node);
        unsigned layer1 = body20 ? body20->FUN_0043b4f0().FUN_0043b4d0() : 0;
        if (body20 && layer1 != 19 && (!hit31->reference || !hit31->reference->IsActor()))
        {
            reinterpret_cast<void(__thiscall*)(void*, unsigned, bool)>(MissileLocal::SetImpactFlag)(this, 4, true);
            Unk_A9();
            MissileCollision* collision9 = FUN_004b5260(node3);
            MissileBody* ownBody53 = collision9 ? collision9->FUN_006fa820() : 0;
            if (ownBody53)
            {
                MissileHandle handle = ownBody53->FUN_0043b4f0();
                handle.FUN_004a39f0(15);
                ownBody53->FUN_00626cb0(handle.value);
            }
            if (!paused)
                reinterpret_cast<void(__thiscall*)(void*, const MissileVector&, const MissileVector&)>(MissileLocal::SetPositionAndDirection)(this, hit31->position.FUN_00439e90(), reinterpret_cast<ProjectileDirectionAccess*>(this)->GetMissileDirection().ApplyScaled(impactScale));
            reinterpret_cast<void(__thiscall*)(void*, int, int)>(MissileLocal::UpdateNodeTransformInt)(this, 0, 0);
            FUN_00c69f50(node3, 1, 1);
            MissileUpdate update53(0.0f, false, false);
            node3->FUN_00a59c60(&update53);
            if (body20->FUN_00517630() == 5)
                FUN_00c6a350(node3, 5, 1, 0, 1);
            else
            {
                FUN_00c6a350(node3, 4, 1, 0, 1);
                if (!reinterpret_cast<bool(__thiscall*)(void*, unsigned)>(MissileLocal::IsImpactFlagSet)(this, 128))
                {
                    reinterpret_cast<void(__thiscall*)(void*, unsigned, bool)>(MissileLocal::SetImpactFlag)(this, 128, true);
                    MissileQueue* queue = DAT_011e0e80.GetOffset70Ptr();
                    if (queue)
                        queue->FUN_005ae3d0(this);
                }
                body20->SetFlag(256, true);
                if (!paused && parent41)
                {
                    MissileTransform inverse;
                    parent41->FUN_00461130()->FUN_004b4880(inverse);
                    *reinterpret_cast<MissileTransform*>(&m_kImpactTransform) = inverse.FUN_0062c250(*node3->FUN_00461130());
                }
            }
            MissileNode* child2 = node3 ? node3->Find(FUN_009b7cb0()) : 0;
            if (child2)
                FUN_00c6a350(child2, 1, 1, 1, 1);
        }
        else
            HandleContactResponse();
    }
}
