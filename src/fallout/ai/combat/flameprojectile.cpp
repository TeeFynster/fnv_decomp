#include "../../../../include/FlameProjectile.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/BeamProjectile.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/TESGlobal.h"
#include "../../../../include/BGSLoadFormBuffer.h"

// src/fallout/ai/combat/flameprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/flameprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Flt
{
    operator unsigned int() const;
};

// @fnv 0x009b3cb0
unsigned int __fastcall FlameProjectileGetEffectValue(FlameProjectile* self)
{
    return ((Flt*)((char*)self + 0x11c))->operator unsigned int();
}


// Loads the base BeamProjectile data, then reads two 4-byte values from the buffer into this+0x150 and this+0x154.
// @fnv 0x009b3f00
// src: XBOX_PDB 0x009b3f00
void FlameProjectile::LoadGame_009b3f00(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<BeamProjectile*>(this)->BeamProjectile::LoadProjectile(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x150, 4);
    apLoadGameBuffer->ReadTypedData((char*)this + 0x154, 4);
}

// Calls the base Projectile load routine, then zeroes the two floats at offsets 0x150 and 0x154.
// @fnv 0x009b3f50
// src: COMMUNITY 0x009b3f50
void FlameProjectile::RevertBGS_009b3f50(BGSLoadFormBuffer* apLoadGameBuffer)
{
    Projectile::RevertBGS_009c58e0(apLoadGameBuffer);
    *(float*)((char*)this + 0x150) = 0.0f;
    *(float*)((char*)this + 0x154) = 0.0f;
}

// placeholder declarations
struct FUN_005de0a0_shell
{
    void Projectile_SetFlag(int, int);
};

struct FUN_009bda10_shell
{
    void Projectile_Initialize();
};

// Calls FUN_005de0a0 with several bit flags and values, then calls FUN_009bda10.
// @fnv 0x009b32b0
void __fastcall FlameProjectileConfigureFlags(FlameProjectile* self)
{
    ((FUN_005de0a0_shell*)self)->Projectile_SetFlag(0x10, 0);
    ((FUN_005de0a0_shell*)self)->Projectile_SetFlag(1, 0);
    ((FUN_005de0a0_shell*)self)->Projectile_SetFlag(2, 0);
    ((FUN_005de0a0_shell*)self)->Projectile_SetFlag(8, 1);
    ((FUN_005de0a0_shell*)self)->Projectile_SetFlag(0x20, 0);
    ((FUN_005de0a0_shell*)self)->Projectile_SetFlag(0x80, 1);
    ((FUN_005de0a0_shell*)self)->Projectile_SetFlag(0x100, 1);
    ((FUN_009bda10_shell*)self)->Projectile_Initialize();
}

// The shared header has no save declaration. A value argument keeps the
// buffer on the stack while __fastcall passes the projectile in ECX.
struct FlameProjectileSaveArgs
{
    BGSSaveFormBuffer* buffer;
};

// @fnv 0x009b3eb0
void __fastcall FlameProjectileSave(FlameProjectile* self, FlameProjectileSaveArgs args)
{
    reinterpret_cast<BeamProjectile*>(self)->BeamProjectile::SaveProjectile(args.buffer);
    args.buffer->SaveData((char*)self + 0x150, 4, 0);
    args.buffer->SaveData((char*)self + 0x154, 4, 0);
}

// @fnv 0x009b3f80
void __fastcall FlameProjectileReset(FlameProjectile* self)
{
    self->FUN_009bc470();
}

namespace fnv_005de0a0 {
struct FUN_005de0a0_shell
{
    char _pad[0xc8];
    unsigned int m_flags;
    void Projectile_SetFlag(unsigned int aFlags, bool abSet);
};

// Sets or clears the given flag bits in m_flags depending on abSet.
// @fnv 0x005de0a0
// src: XBOX_PDB 0x005de0a0
void FUN_005de0a0_shell::Projectile_SetFlag(unsigned int aFlags, bool abSet)
{
    if (abSet)
        m_flags |= aFlags;
    else
        m_flags &= ~aFlags;
}
}  // namespace fnv_005de0a0

namespace flame_particle {
struct RTTI;
struct Particle
{
    unsigned int NiParticleSystem_GetModifierCount();
    NiObject* GetByIndex(unsigned int index);
};


bool __cdecl NiObject_IsKindOf(RTTI const* rtti, NiObject* object);

extern void* g_01202560;
extern int g_01202500_arg1;
extern double _DAT_01012060;

float GetMaxParticleGlobalValue(NiNode* node);

// @fnv 0x009b3da0
float GetMaxParticleGlobalValue(NiNode* node)
{
    float result = 0.0f;

    if (node)
    {
        NiNode* root;

        if (NiObject_IsKindOf(reinterpret_cast<RTTI const*>(&g_01202560), node))
        {
            Particle* particle = reinterpret_cast<Particle*>(node);

            for (unsigned int i = 0; result == _DAT_01012060 && i < particle->NiParticleSystem_GetModifierCount(); ++i)
            {
                NiObject* object = particle->GetByIndex(i);

                if (object && NiObject_IsKindOf(reinterpret_cast<RTTI const*>(&g_01202500_arg1), object))
                {
                    TESGlobal* global = reinterpret_cast<TESGlobal*>(object);
                    result = global->GetValue();
                }
            }
        }

        root = node->IsSceneNode();

        if (root)
        {
            for (unsigned int i = 0; i < root->GetNumChildren(); ++i)
            {
                float childValue = GetMaxParticleGlobalValue(reinterpret_cast<NiNode*>(root->GetAt(i)));

                if (childValue > result)
                    result = childValue;
            }
        }
    }

    return result;
}

} // namespace flame_particle

using flame_particle::GetMaxParticleGlobalValue;

struct FloatMatrix3
{
    float xx, xy, xz;
    float yx, yy, yz;
    float zx, zy, zz;
    int FUN_004b45b0();
    FloatMatrix3* FUN_0043f8d0(int);
};
struct GameNode
{
    FloatMatrix3* NiAVObject_GetWorldRotate(FloatMatrix3*);
};
struct OtherNode
{
    virtual void UnknownVirtual000();
    virtual void UnknownVirtual001();
    virtual void UnknownVirtual002();
    virtual void UnknownVirtual003();
    virtual void UnknownVirtual004();
    virtual void UnknownVirtual005();
    virtual void UnknownVirtual006();
    virtual void UnknownVirtual007();
    virtual void UnknownVirtual008();
    virtual void UnknownVirtual009();
    virtual void UnknownVirtual010();
    virtual void UnknownVirtual011();
    virtual void UnknownVirtual012();
    virtual void UnknownVirtual013();
    virtual void UnknownVirtual014();
    virtual void UnknownVirtual015();
    virtual void UnknownVirtual016();
    virtual void UnknownVirtual017();
    virtual void UnknownVirtual018();
    virtual void UnknownVirtual019();
    virtual void UnknownVirtual020();
    virtual void UnknownVirtual021();
    virtual void UnknownVirtual022();
    virtual void UnknownVirtual023();
    virtual void UnknownVirtual024();
    virtual void UnknownVirtual025();
    virtual void UnknownVirtual026();
    virtual void UnknownVirtual027();
    virtual void UnknownVirtual028();
    virtual void UnknownVirtual029();
    virtual void UnknownVirtual030();
    virtual void UnknownVirtual031();
    virtual void UnknownVirtual032();
    virtual void UnknownVirtual033();
    virtual void UnknownVirtual034();
    virtual void UnknownVirtual035();
    virtual void UnknownVirtual036();
    virtual void UnknownVirtual037();
    virtual void UnknownVirtual038();
    virtual void UnknownVirtual039();
    virtual void UnknownVirtual040();
    virtual void UnknownVirtual041();
    virtual void UnknownVirtual042();
    virtual void UnknownVirtual043();
    virtual void UnknownVirtual044();
    virtual void UnknownVirtual045();
    virtual void UnknownVirtual046();
    virtual void UnknownVirtual047();
    virtual void UnknownVirtual048();
    virtual void UnknownVirtual049();
    virtual void UnknownVirtual050();
    virtual void UnknownVirtual051();
    virtual void UnknownVirtual052();
    virtual void UnknownVirtual053();
    virtual void UnknownVirtual054();
    virtual void UnknownVirtual055();
    virtual void UnknownVirtual056();
    virtual void UnknownVirtual057();
    virtual void UnknownVirtual058();
    virtual void UnknownVirtual059();
    virtual void UnknownVirtual060();
    virtual void UnknownVirtual061();
    virtual void UnknownVirtual062();
    virtual void UnknownVirtual063();
    virtual void UnknownVirtual064();
    virtual void UnknownVirtual065();
    virtual void UnknownVirtual066();
    virtual void UnknownVirtual067();
    virtual void UnknownVirtual068();
    virtual void UnknownVirtual069();
    virtual void UnknownVirtual070();
    virtual void UnknownVirtual071();
    virtual void UnknownVirtual072();
    virtual void UnknownVirtual073();
    virtual void UnknownVirtual074();
    virtual void UnknownVirtual075();
    virtual void UnknownVirtual076();
    virtual void UnknownVirtual077();
    virtual void UnknownVirtual078();
    virtual void UnknownVirtual079();
    virtual void UnknownVirtual080();
    virtual void UnknownVirtual081();
    virtual void UnknownVirtual082();
    virtual void UnknownVirtual083();
    virtual void UnknownVirtual084();
    virtual void UnknownVirtual085();
    virtual void UnknownVirtual086();
    virtual void UnknownVirtual087();
    virtual void UnknownVirtual088();
    virtual void UnknownVirtual089();
    virtual void UnknownVirtual090();
    virtual void UnknownVirtual091();
    virtual void UnknownVirtual092();
    virtual void UnknownVirtual093();
    virtual void UnknownVirtual094();
    virtual void UnknownVirtual095();
    virtual void UnknownVirtual096();
    virtual void UnknownVirtual097();
    virtual void UnknownVirtual098();
    virtual void UnknownVirtual099();
    virtual void UnknownVirtual100();
    virtual void UnknownVirtual101();
    virtual void UnknownVirtual102();
    virtual void UnknownVirtual103();
    virtual void UnknownVirtual104();
    virtual void UnknownVirtual105();
    virtual void UnknownVirtual106();
    virtual void UnknownVirtual107();
    virtual void UnknownVirtual108();
    virtual void UnknownVirtual109();
    virtual void UnknownVirtual110();
    virtual void UnknownVirtual111();
    virtual void UnknownVirtual112();
    virtual void UnknownVirtual113();
    virtual void UnknownVirtual114();
    virtual void UnknownVirtual115();
    virtual void UnknownVirtual116();
    virtual void UnknownVirtual117();
    virtual void UnknownVirtual118();
    virtual void UnknownVirtual119();
    virtual void UnknownVirtual120();
    virtual void UnknownVirtual121();
    virtual void UnknownVirtual122();
    virtual void UnknownVirtual123();
    virtual void UnknownVirtual124();
    virtual void UnknownVirtual125();
    virtual void UnknownVirtual126();
    virtual void UnknownVirtual127();
    virtual void UnknownVirtual128();
    virtual void UnknownVirtual129();
    virtual void UnknownVirtual130();
    virtual GameNode* GetSecondary();
};
typedef GameNode*(__thiscall* NodeGetter)(void*);
typedef void(__thiscall* VectorSetter)(GameNode*, NiPoint3*);
typedef GameNode*(__thiscall* SecondaryGetter)(void*);
float GetMaxParticleGlobalValue(GameNode*);
extern double _DAT_0106b9e8;
struct ProjectileObject
{
    OtherNode* Projectile_GetShooter();
    void UpdateProjectileNode();
};
// Gets the projectile's node and secondary node, sets a zero vector on the node, copies a matrix into this+0x94, and stores a scaled value at this+0x154.
// @fnv 0x009b3320
void ProjectileObject::UpdateProjectileNode()
{
    GameNode* node = ((NodeGetter)(*reinterpret_cast<void***>(this))[0x1d0 / 4])(this);
    if (node)
    {
        GameNode* secondary = Projectile_GetShooter()->GetSecondary();
        if (secondary)
        {
            // Reserve storage without invoking NiPoint3's separate default constructor.
            float vec[sizeof(NiPoint3) / sizeof(float)];
            reinterpret_cast<NiPoint3*>(vec)->FUN_0043d410(0.0f, 0, 0);
            ((VectorSetter)(*reinterpret_cast<void***>(node))[0xb8 / 4])(node, reinterpret_cast<NiPoint3*>(vec));
            FloatMatrix3 firstMatrix;
            FloatMatrix3 second;
            *reinterpret_cast<FloatMatrix3*>(reinterpret_cast<char*>(this) + 0x94) = *(
                ((NodeGetter)(*reinterpret_cast<void***>(this))[0x1d0 / 4])(this)->NiAVObject_GetWorldRotate(&second)->FUN_0043f8d0(
                    secondary->NiAVObject_GetWorldRotate(&firstMatrix)->FUN_004b45b0()));
        }
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x154) =
            GetMaxParticleGlobalValue(node) * _DAT_0106b9e8;
    }
}

struct FUN_00717e50_shell;
struct ProjMgr;
struct ProjObj
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
    virtual unsigned char v137();
};
struct FUN_004181e0_shell
{
    unsigned int FUN_004181e0();
};
struct FUN_00874480_shell
{
    unsigned int Projectile_GetShooter();
};
struct FUN_005be5c0_shell
{
    unsigned int ProcessArray_GetProcessLevelTail();
};
struct FUN_00968670_shell
{
    ProjObj* ProcessArray_GetItem();
};
struct ProjMgr
{
    unsigned int ProcessArray_GetProcessLevelTail();
    ProjObj* ProcessArray_GetItem();
};
struct FUN_00717e50_shell
{
    ProjMgr* FUN_00717e50(unsigned int index);
};
extern FUN_00717e50_shell DAT_011e0e80;

// Scans the project manager's objects for one whose v137 is set and whose FUN_004181e0 equals b and FUN_00874480 equals a, returning the first match or null.
// @fnv 0x009bd780
ProjObj* FindProjectObject(unsigned int a, unsigned int b)
{
    ProjObj* result = 0;
    for (unsigned int i = 0; result == 0 && i < DAT_011e0e80.FUN_00717e50(0)->ProcessArray_GetProcessLevelTail(); ++i)
    {
        ProjObj* pObj = DAT_011e0e80.FUN_00717e50(i)->ProcessArray_GetItem();
        if (pObj != 0)
        {
            if (pObj->v137() != 0)
            {
                ProjObj* pCandidate = pObj;
                if (((FUN_004181e0_shell*)pCandidate)->FUN_004181e0() == b)
                {
                    if (((FUN_00874480_shell*)pCandidate)->Projectile_GetShooter() == a)
                    {
                        result = pCandidate;
                    }
                }
            }
        }
    }
    return result;
}

class Ref9B3
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual bool IsDead();
};

struct HitEntry9B3
{
    Ref9B3* m_pkRef;
    int m_iArrayLength;
};

class HitNode9B3
{
  public:
    bool IsEmpty();
    HitEntry9B3** GetItem();
    HitNode9B3* GetNext();

    HitEntry9B3* m_pkItem;
    HitNode9B3* m_pkNext;
};

class ProjectileBase9B3;

bool __cdecl CanHit9B3(Ref9B3* pkTarget, int iPart, FlameProjectile* pkProjectile, ProjectileBase9B3* pkBase);

// Pass hit arguments by value to preserve the original stack layout.
struct FlameProjectileHitArgs
{
    Ref9B3* pkTarget;
    int iArg1;
    int iArg2;
    int iPart;
    int iArg4;
    int iArg5;
};

// @fnv 0x009b3cd0
bool __fastcall FlameProjectileCanProcessHit(FlameProjectile* self, FlameProjectileHitArgs args)
{
    if (CanHit9B3(args.pkTarget, args.iPart, self, reinterpret_cast<ProjectileBase9B3*>(self->GetProjectileBase())))
    {
        HitNode9B3* pkNode = reinterpret_cast<HitNode9B3*>(&self->kImpacts);
        while (pkNode && !pkNode->IsEmpty())
        {
            if (args.pkTarget == (*pkNode->GetItem())->m_pkRef)
            {
                if (args.pkTarget && args.pkTarget->IsDead())
                    return false;
                else
                    return true;
            }
            pkNode = pkNode->GetNext();
        }
        if (self->Projectile::OnCollision(reinterpret_cast<Actor*>(args.pkTarget),
                                          *reinterpret_cast<const NiPoint3*>(args.iArg1),
                                          *reinterpret_cast<const NiPoint3*>(args.iArg2),
                                          reinterpret_cast<hkpCollidable*>(args.iPart),
                                          args.iArg4, args.iArg5))
            return true;
    }
    return false;
}
