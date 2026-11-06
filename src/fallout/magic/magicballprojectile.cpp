#include "../../../include/Actor.h"
#include "../../../include/TESSaveLoadGame.h"
// ActorDeletionQueue_magicballprojectile: local type (was include/ActorDeletionQueue.h, which had no evidence of one real class); its methods are 0x0096d450 ProcessLists::AddReference, 0x0096d470 ProcessLists::RemoveReference, 0x0096d490 ProcessLists::GetSystemTimeClock
// PathfindQueueStorage_magicballprojectile: local type (was include/PathfindQueueStorage.h, which had no evidence of one real class); its methods are 0x0096aaf0 ProcessArray::RemoveActor
class MobileObject;

class PathfindQueueStorage_magicballprojectile
{
public:
    void FUN_0096aaf0(MobileObject* apObject, int aeLevel);
};

class MobileObject;
class ActorSV;
struct ReferenceView;

class ActorDeletionQueue_magicballprojectile
{
public:
    unsigned int pad;
    PathfindQueueStorage_magicballprojectile storage;
    unsigned char unk05[3];

    void FUN_0096d470(MobileObject*, int);
    void FUN_0096d470(ActorSV*, int);
    void FUN_0096d470(ReferenceView*, int);
    float FUN_0096d490();
    void FUN_0096d450(MobileObject*, int, bool, bool, bool);
    void FUN_0096d450(ActorSV*, int, bool, bool, ActorSV*);
};
#include "../../../include/AlchemyItem.h"
#include "../../../include/ContinuousBeamProjectile.h"
#include "../../../include/MagicBallProjectile.h"
#include "../../../include/Projectile.h"
#include "../../../include/ActorPackageContext.h"
#include "../../../include/DialoguePackage.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/EnchantmentItem.h"
#include "../../../include/MobileObject.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiControllerManager.h"
#include "../../../include/NiControllerSequence.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/NiObjectNET.h"
#include "../../../include/NiPoint3.h"
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
#include "../../../include/NiTimeController.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/Setting.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESSound.h"
#include "../../../include/NiMatrix3.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/Vec4.h"
#include "../../../include/EffectItem.h"

// src/fallout/magic/magicballprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicballprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00810a80_shell
{
    float GetFloatAtOffset53C();
};

// @fnv 0x00810a80
float FUN_00810a80_shell::GetFloatAtOffset53C()
{
    return ((float*)((char*)this + 0x53c))[0];
}

extern double _gModifierZero;
// Preserve the timer call absent from the approved ActorPackageContext header.
float __fastcall GetProjectileFadeTimer(ActorPackageContext*);

struct FUN_00822a20_shell
{
    void CheckModifierNonZero(float a);
};

// @fnv 0x00822a20
void FUN_00822a20_shell::CheckModifierNonZero(float a)
{
    if (a != _gModifierZero)
    {
    }
}

void _Deallocate(void*);

// @fnv 0x0080f7e0
void* MagicBallProjectile::FUN_0080f7e0(unsigned int flags)
{
    FUN_0080fb30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct RefH
{
    bool IsDeleted() const;
};
struct FUN_00811030_shell
{
    bool FUN_00811030();
};
// Returns true when the int at offset 0xac is not 2 and the object is not deleted.
// @fnv 0x00811030
bool FUN_00811030_shell::FUN_00811030()
{
    return *reinterpret_cast<const int*>(reinterpret_cast<const char*>(this) + 0xac) != 2 &&
           !reinterpret_cast<const RefH*>(this)->IsDeleted();
}

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_0081e830_shell
{
    unsigned short GetSaveRecordSize(unsigned int);
};

struct FUN_00811070_shell
{
    unsigned short eState;
    unsigned short FUN_00811070(unsigned int aiFlags);
};

// @fnv 0x00811070
unsigned short FUN_00811070_shell::FUN_00811070(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += ((FUN_0081e830_shell*)this)->GetSaveRecordSize(aiFlags);
    isize += 4;
    isize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() < 0x64)
        isize += 4;
    isize += 4;
    isize += 4;
    if (*(unsigned int*)((char*)this + 0xac) == 2)
        isize += 4;
    return isize;
}

struct FUN_008229d0_shell
{
    void FUN_00822a00();
    void* FUN_008229d0(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_00822a00, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x008229d0
void* FUN_008229d0_shell::FUN_008229d0(unsigned int flags)
{
    FUN_00822a00();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0081de70_shell
{
    void FUN_0081de70();
};
struct FUN_00822a00_shell
{
    void FUN_00822a00();
};
// @fnv 0x00822a00
void FUN_00822a00_shell::FUN_00822a00()
{
    reinterpret_cast<FUN_0081de70_shell*>(this)->FUN_0081de70();
}

struct FUN_008cac30_shell
{
    void* FUN_008cac30(unsigned int flags);
    void FUN_008cac60();
};
// @fnv 0x008cac30
void* FUN_008cac30_shell::FUN_008cac30(unsigned int flags)
{
    FUN_008cac60();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_008cf740 {
extern TESSaveLoadGame* g_TESSaveLoadGame;
void _Deallocate(void*);
struct S00932750
{
    void FUN_00932750(int);
};
struct Owner008cf740
{
    char _pad[0x88];
    void* f88;
    void FUN_008cf740(int);
};
// Calls FUN_00932750 with a, then if g_TESSaveLoadGame->FUN_0055f5b0() is true, deallocates f88 and sets it to 0.
// @fnv 0x008cf740
void Owner008cf740::FUN_008cf740(int a)
{
    ((S00932750*)this)->FUN_00932750(a);
    if (g_TESSaveLoadGame->FUN_0055f5b0())
    {
        if (f88 != 0)
        {
            void* tmp = f88;
            _Deallocate(tmp);
        }
        f88 = 0;
    }
}
}  // namespace fnv_008cf740

struct Twin_0084d030
{
    float GetStoredFloatValue();
};
extern Twin_0084d030 g_timeGlobal;
struct FUN_008cb380_shell
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
    virtual void v190(float);
    void FUN_008cb380(float);
};
// @fnv 0x008cb380
void FUN_008cb380_shell::FUN_008cb380(float afUnused)
{
    float fTime = g_timeGlobal.GetStoredFloatValue();
    v190(fTime);
}

struct PC7d
{
    void FUN_00484ce0(void*, int);
};

struct SaveManager
{
    unsigned char FUN_008df040();
};

struct TESSaveLoadGameHelper
{
    void FUN_008579b0(void*, int);
};

struct FUN_0081e8c0_shell_standin
{
    void FUN_0081e8c0(unsigned int);
};

struct FUN_00811110_shell
{
    void FUN_00811110(unsigned int);
};

extern SaveManager* DAT_011de45c;

// @fnv 0x00811110
void FUN_00811110_shell::FUN_00811110(unsigned int aiFlags)
{
    reinterpret_cast<FUN_0081e8c0_shell_standin*>(this)->FUN_0081e8c0(aiFlags);

    reinterpret_cast<PC7d*>(this)->FUN_00484ce0(reinterpret_cast<char*>(this) + 0xa8, 4);
    reinterpret_cast<PC7d*>(this)->FUN_00484ce0(reinterpret_cast<char*>(this) + 0x88, 4);

    if (DAT_011de45c->FUN_008df040() < 100)
    {
        reinterpret_cast<PC7d*>(this)->FUN_00484ce0(reinterpret_cast<char*>(this) + 0x8c, 4);
    }

    reinterpret_cast<TESSaveLoadGameHelper*>(g_TESSaveLoadGame)->FUN_008579b0(reinterpret_cast<char*>(this) + 0xac, 4);

    reinterpret_cast<PC7d*>(this)->FUN_00484ce0(reinterpret_cast<char*>(this) + 0xb0, 4);

    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xac) == 2)
    {
        float ffadeTimer;
        ffadeTimer = 0.0f;

        if (*reinterpret_cast<ActorPackageContext**>(reinterpret_cast<char*>(this) + 0xc0))
        {
            ffadeTimer =
                GetProjectileFadeTimer(*reinterpret_cast<ActorPackageContext**>(reinterpret_cast<char*>(this) + 0xc0));
        }

        reinterpret_cast<PC7d*>(this)->FUN_00484ce0(&ffadeTimer, 4);
    }
}

namespace fnv_008111e0 {
struct STR00
{
    void FUN_00484d00(void*, unsigned int);
};


struct SaveManager
{
    unsigned char FUN_008df040();
};

extern SaveManager* DAT_011de45c;

struct TESSaveLoadGameLoadData
{
    void ReadTypedData(void*, unsigned int);
};

struct FUN_008111e0_vtable
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
};

struct FUN_008111e0_shell : FUN_008111e0_vtable
{
    unsigned char padding[0xa8];
    int eState;

    void LoadFromSave(unsigned int, unsigned int);
};

void* __memcpy(void*, const void*, unsigned int);

// @fnv 0x008111e0
void FUN_008111e0_shell::LoadFromSave(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    float ffadeTimer;

    this->v113();

    reinterpret_cast<Projectile*>(this)->FUN_0081e980(aiFlags, aiCurrentFlags);

    reinterpret_cast<STR00*>(this)->FUN_00484d00(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa8), 4);

    reinterpret_cast<STR00*>(this)->FUN_00484d00(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x88), 4);

    if (DAT_011de45c->FUN_008df040() < 100)
    {
        reinterpret_cast<STR00*>(this)->FUN_00484d00(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x8c), 4);
    }

    reinterpret_cast<TESSaveLoadGameLoadData*>(DAT_011de45c)
        ->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xac), 4);

    reinterpret_cast<STR00*>(this)->FUN_00484d00(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xb0), 4);

    if (this->eState == 2)
    {
        reinterpret_cast<STR00*>(this)->FUN_00484d00(&ffadeTimer, 4);

        __memcpy(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xc0), &ffadeTimer, 4);
    }
}
}  // namespace fnv_008111e0

struct ProjectileFlags
{
    unsigned value;
    void SetFlag4000(bool);
};
struct ProjectileInfo
{
    ProjectileFlags FUN_0070c440();
    void FUN_00810ff0(unsigned);
};
struct ImpactPoint
{
    float x, y, z;
};
struct AreaSound
{
    unsigned GetFormID();
};
struct ProjectileEffect
{
    AreaSound* GetAreaSound();
};
struct ImpactHandle
{
    unsigned id, flags, state;
    ~ImpactHandle();
    bool FUN_00ad8b60(float, float, float);
    bool FUN_00ad8830(bool);
};
struct ImpactAudio
{
    ImpactHandle FUN_00ad73b0(unsigned, unsigned);
};
ImpactAudio* __cdecl FUN_00453a70();
struct ProjectileEvent
{
    void ApplySpellEffects(int, void*, ImpactPoint, void*, int, int, float, float);
};
struct ProjectileImpact
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual ImpactPoint& position();
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
    float elapsed, duration;
    int unkb0, mode;
    ProjectileInfo* FUN_009306d0();
    void* GetParentCell();
    int GetArchetype();
    ProjectileEvent* FUN_009185e0();
    ProjectileEffect* FUN_004fd400();
    void TriggerImpact(int, int, int, int, int, bool);
};
// @fnv 0x0081a760
void ProjectileImpact::TriggerImpact(int aiUnused1, int aiUnused2, int aiUnused3, int aiUnused4, int aiEventArg,
                                     bool abSuppress)
{
    ProjectileFlags a = FUN_009306d0()->FUN_0070c440();
    a.SetFlag4000(true);
    FUN_009306d0()->FUN_00810ff0(a.value);
    mode = 1;
    float b = (duration - elapsed) / duration;
    if (!abSuppress && b > 0.0)
    {
        FUN_009185e0()->ApplySpellEffects(GetArchetype(), GetParentCell(), position(), this, aiEventArg, 0, b, 1.0f);
    }
    if (FUN_004fd400()->GetAreaSound() && !abSuppress)
    {
        unsigned e = FUN_004fd400()->GetAreaSound()->GetFormID();
        ImpactHandle d = FUN_00453a70()->FUN_00ad73b0(e, 0x102);
        ImpactPoint c = position();
        d.FUN_00ad8b60(c.x, c.y, c.z);
        d.FUN_00ad8830(false);
    }
}

void* FormHeap_Allocate(unsigned int);
extern ActorDeletionQueue_magicballprojectile DAT_011e0e80;
struct Obj
{
    virtual ~Obj();
    virtual void v1(Obj*);
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
    int FUN_0045cd60();
};
struct FUN_008d7510 : Obj
{
    int unk04[282];
    FUN_008d7510();
};
struct Self
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual void s116();
    virtual void s117();
    virtual void s118();
    virtual void s119();
    virtual void s120();
    virtual void s121();
    virtual void s122();
    virtual void s123();
    virtual void s124();
    virtual void s125();
    virtual void s126();
    virtual void s127(int);
    char pad[0x64];
    Obj* m68;
    bool FUN_008cf7a0();
};
// @fnv 0x008cf7a0
bool Self::FUN_008cf7a0()
{
    if (m68 && !m68->FUN_0045cd60())
        return true;
    Obj* n;
    int r7 = m68->FUN_0045cd60();
    DAT_011e0e80.FUN_0096d470(reinterpret_cast<MobileObject*>(this), r7);
    n = new FUN_008d7510;
    n->v1(m68);
    delete m68;
    m68 = n;
    DAT_011e0e80.FUN_0096d450(reinterpret_cast<MobileObject*>(this), 0, false, false, false);
    s127(0);
    m68->v18();
    return true;
}

struct NiRTTI;

NiObject* FUN_00653270(const NiRTTI* pkRTTI, NiObject* pkObject);
void FUN_00c4b500(NiAVObject* pkObject);
extern NiRTTI DAT_011f36ac;
extern const float DAT_0107a510;
extern float DAT_011c3c08;

// @fnv 0x0080fcf0
void TESObjectREFR::ResetProjectileIdleAnimation()
{
    NiAVObject* pNode = GetNiNode();
    if (pNode)
    {
        pNode->FUN_00440490(*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xb0));
        pNode->FUN_00440460(*static_cast<const TESObjectREFR*>(this)->GetPos());
        NiPoint3 kAngles = GetAngleOnReference();
        NiMatrix3 kRotate;
        kRotate.FromEulerAnglesZXY(kAngles.z, kAngles.x, kAngles.y);
        pNode->FUN_0043fa80(&kRotate);
        FUN_00c4b500(pNode);
        NiControllerManager* pManager = (NiControllerManager*)FUN_00653270(&DAT_011f36ac, pNode->GetControllers());
        if (pManager)
        {
            NiControllerSequence* pSequence = pManager->FUN_0047a520(NiFixedString("SpecialIdle_Projectile"));
            if (pSequence)
            {
                pManager->FUN_0048fef0(0.0f);
                pManager->FUN_0047aab0(pSequence, 0, 0, 1.0f, 0.0f, 0);
                pManager->FUN_0047aa40(true);
                pSequence->FUN_0098adb0(-DAT_0107a510);
                NiUpdateData kUpdateData(DAT_011c3c08 - (double)0.1f, true, false);
                pNode->Update(static_cast<const NiUpdateData&>(kUpdateData));
            }
        }
    }
}

namespace fnv_008106d0 {

struct Sequence
{
    float FUN_00508120();
    float FUN_00508100();
    int FUN_008041a0();
};
struct Fixed
{
    const char* text;
    Fixed(const char*);
    ~Fixed();
};
struct Controller
{
    Sequence* FUN_0047a520(const Fixed&);
    void FUN_0048fef0(float);
};
struct Model
{
    void FUN_00440460(const NiPoint3*);
    Controller* FUN_0043b230();
};
struct Effect
{
    void UpdateLightFade(float);
};
struct Info
{
    float GetFloatAtOffset53C();
};

extern Setting originalRuntimeFUN_00403e20Setting1130;
extern int DAT_011f36ac;
Controller* FUN_00653270(const int*, Controller*);
double FUN_004587d0(float);
struct AreaProjectile
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
    virtual void Kill(int);
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
    virtual Model* GetModelFilePath();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const NiPoint3& Position();
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
    virtual void Move(float, NiPoint3*, int);
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
    virtual void SetPosition(NiPoint3, int, int, int);
    virtual void v194();
    virtual bool Active();
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
    float speed;
    float distance;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int state;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    Effect* effect;
    bool FUN_00440d80() const;
    Info* FUN_009306d0();
    void FUN_00484af0(int);
    void FUN_008106d0(float dt);
};
// Advances the projectile by dt: kills it on large dt, moves it along its speed, accumulates distance, and handles the idle/effect state.
// @fnv 0x008106d0
void AreaProjectile::FUN_008106d0(float afDeltaTime)
{
    if (afDeltaTime >= 60.0)
        Kill(1);
    if (afDeltaTime >= 0.0)
    {
        switch (state)
        {
        case 0:
            state = 1;
        case 1: {
            if (FUN_00440d80())
                break;
            if (FUN_004587d0(FUN_009306d0()->GetFloatAtOffset53C()) >= Position().z)
                SetPosition(Position(), 0, 0, 1);
            NiPoint3 newPosition(0.0f, speed * afDeltaTime, 0.0f);
            NiPoint3 oldPosition = Position();
            Move(afDeltaTime, &newPosition, 15);
            if (!Active())
                break;
            NiPoint3 velocity = Position();
            if (GetModelFilePath())
                GetModelFilePath()->FUN_00440460(&velocity);
            distance += (velocity - oldPosition).FUN_00457990();
            if (distance > *originalRuntimeFUN_00403e20Setting1130.FUN_00403e20())
                Kill(1);
            if (effect)
                effect->UpdateLightFade(afDeltaTime);
            break;
        }
        case 2: {
            Model* animation = GetModelFilePath();
            Controller* ctrl = animation ? animation->FUN_0043b230() : 0;
            Controller* swapModel = FUN_00653270(&DAT_011f36ac, ctrl);
            if (swapModel)
            {
                Sequence* sequence = swapModel->FUN_0047a520(Fixed("SpecialIdle_AreaEffect"));
                if (!sequence || (sequence && (sequence->FUN_00508120() > sequence->FUN_00508100() ||
                                               sequence->FUN_008041a0() == 0)))
                {
                    swapModel->FUN_0048fef0(0.0f);
                    FUN_00484af0(1);
                    Kill(1);
                }
            }
            else
            {
                Kill(1);
                FUN_00484af0(1);
            }
            if (effect)
                effect->UpdateLightFade(afDeltaTime);
            break;
        }
        }
    }
}
}  // namespace fnv_008106d0

struct Cls;
struct Ctrl;
struct Refr;
struct Refr2;
struct CollObj;
struct WorldObj;
struct SettingObj;

struct Filter
{
    unsigned int info;
    int FUN_004a3a20();
};

struct RetObj
{
    int f0;
    void FUN_004a39f0(int);
    void FUN_0059ce80(unsigned int);
};

struct Ctrl
{
    RetObj FUN_0070c440();
    void FUN_00810ff0(int);
};

struct Refr
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual void tv03();
    virtual void tv04();
    virtual void tv05();
    virtual void tv06();
    virtual void tv07();
    virtual void tv08();
    virtual void tv09();
    virtual void tv10();
    virtual Refr2* tv11();
};

struct Refr2
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual void tv03();
    virtual void tv04();
    virtual void tv05();
    virtual void tv06();
    virtual void tv07();
    virtual void tv08();
    virtual void tv09();
    virtual void tv10();
    virtual Refr2* tv11();
    virtual void tv12();
    virtual void tv13();
    virtual void tv14();
    virtual void tv15();
    virtual void tv16();
    virtual void tv17();
    virtual void tv18();
    virtual void tv19();
    virtual void tv20();
    virtual void tv21();
    virtual void tv22();
    virtual void tv23();
    virtual void tv24();
    virtual void tv25();
    virtual void tv26();
    virtual void tv27();
    virtual void tv28();
    virtual void tv29();
    virtual void tv30();
    virtual void tv31();
    virtual void tv32();
    virtual void tv33();
    virtual void tv34();
    virtual void tv35();
    virtual void tv36();
    virtual void tv37();
    virtual void tv38();
    virtual void tv39();
    virtual void tv40();
    virtual void tv41();
    virtual void tv42();
    virtual void tv43();
    virtual void tv44();
    virtual void tv45();
    virtual void tv46();
    virtual void tv47();
    virtual void tv48();
    virtual void tv49();
    virtual void tv50();
    virtual void tv51();
    virtual void tv52();
    virtual void tv53();
    virtual void tv54();
    virtual void tv55();
    virtual void tv56();
    virtual void tv57();
    virtual void tv58();
    virtual void tv59();
    virtual void tv60();
    virtual void tv61();
    virtual void tv62();
    virtual void tv63();
    virtual bool tv64();
    virtual void tv65();
    virtual void tv66();
    virtual void tv67();
    virtual void tv68();
    virtual void tv69();
    virtual void tv70();
    virtual void tv71();
    virtual void tv72();
    virtual void tv73();
    virtual void tv74();
    virtual void tv75();
    virtual void tv76();
    virtual void tv77();
    virtual void tv78();
    virtual void tv79();
    virtual void tv80();
    virtual void tv81();
    virtual void tv82();
    virtual void tv83();
    virtual void tv84();
    virtual void tv85();
    virtual void tv86();
    virtual void tv87();
    virtual void tv88();
    virtual void tv89();
    virtual void tv90();
    virtual void tv91();
    virtual void tv92();
    virtual void tv93();
    virtual void tv94();
    virtual void tv95();
    virtual void tv96();
    virtual void tv97();
    virtual void tv98();
    virtual void tv99();
    virtual void tv100();
    virtual void tv101();
    virtual void tv102();
    virtual void tv103();
    virtual void tv104();
    virtual void tv105();
    virtual void tv106();
    virtual void tv107();
    virtual void tv108();
    virtual void tv109();
    virtual void tv110();
    virtual void tv111();
    virtual void tv112();
    virtual void tv113();
    virtual void tv114();
    virtual void tv115();
    virtual void* tv116();
    Filter FUN_00931ed0();
};

struct CollObj
{
    WorldObj* FUN_006fa820();
};

struct WorldObj
{
    Filter FUN_0043b4f0();
};

struct SettingObj
{
    float* FUN_00403e20();
};

CollObj* FUN_004b5260(void*);
unsigned int FUN_005dbe10();
void FUN_0080fae0(float);

extern SettingObj DAT_011d1c28;
extern Refr2* DAT_011dea3c;

struct Cls
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual void tv03();
    virtual void tv04();
    virtual void tv05();
    virtual void tv06();
    virtual void tv07();
    virtual void tv08();
    virtual void tv09();
    virtual void tv10();
    virtual void tv11();
    virtual void tv12();
    virtual void tv13();
    virtual void tv14();
    virtual void tv15();
    virtual void tv16();
    virtual void tv17();
    virtual void tv18();
    virtual void tv19();
    virtual void tv20();
    virtual void tv21();
    virtual void tv22();
    virtual void tv23();
    virtual void tv24();
    virtual void tv25();
    virtual void tv26();
    virtual void tv27();
    virtual void tv28();
    virtual void tv29();
    virtual void tv30();
    virtual void tv31();
    virtual void tv32();
    virtual void tv33();
    virtual void tv34();
    virtual void tv35();
    virtual void tv36();
    virtual void tv37();
    virtual void tv38();
    virtual void tv39();
    virtual void tv40();
    virtual void tv41();
    virtual void tv42();
    virtual void tv43();
    virtual void tv44();
    virtual void tv45();
    virtual void tv46();
    virtual void tv47();
    virtual void tv48();
    virtual void tv49();
    virtual void tv50();
    virtual void tv51();
    virtual void tv52();
    virtual void tv53();
    virtual void tv54();
    virtual void tv55();
    virtual void tv56();
    virtual void tv57();
    virtual void tv58();
    virtual void tv59();
    virtual void tv60();
    virtual void tv61();
    virtual void tv62();
    virtual void tv63();
    virtual void tv64();
    virtual void tv65();
    virtual void tv66();
    virtual void tv67();
    virtual void tv68();
    virtual void tv69();
    virtual void tv70();
    virtual void tv71();
    virtual void tv72();
    virtual void tv73();
    virtual void tv74();
    virtual void tv75();
    virtual void tv76();
    virtual void tv77();
    virtual void tv78();
    virtual void tv79();
    virtual void tv80();
    virtual void tv81();
    virtual void tv82();
    virtual void tv83();
    virtual void tv84();
    virtual void tv85();
    virtual void tv86();
    virtual void tv87();
    virtual void tv88();
    virtual void tv89();
    virtual void tv90();
    virtual void tv91();
    virtual void tv92();
    virtual void tv93();
    virtual void tv94();
    virtual void tv95();
    virtual void tv96();
    virtual void tv97();
    virtual void tv98();
    virtual void tv99();
    virtual void tv100();
    virtual void tv101();
    virtual void tv102();
    virtual void tv103();
    virtual void tv104();
    virtual void tv105();
    virtual void tv106();
    virtual void tv107();
    virtual void tv108();
    virtual void tv109();
    virtual void tv110();
    virtual void tv111();
    virtual void tv112();
    virtual void tv113();
    virtual void tv114();
    virtual void tv115();
    virtual void* tv116();
    void UpdateFlags(int, int);
    Ctrl* FUN_009306d0();
    Refr* FUN_009185e0();
    void FUN_008115c0(int a1, int a2);
};

// @fnv 0x008115c0
void Cls::FUN_008115c0(int aiArg1, int aiArg2)
{
    UpdateFlags(aiArg1, aiArg2);
    Ctrl* ctrl4 = FUN_009306d0();
    if (ctrl4)
    {
        unsigned int _result;
        if (FUN_009185e0() && FUN_009185e0()->tv11())
        {
            Refr2* obj4 = FUN_009185e0()->tv11();
            Refr2* filtered = obj4->tv64() ? obj4 : 0;
            if (filtered)
            {
                _result = filtered->FUN_00931ed0().FUN_004a3a20();
            }
            else
            {
                CollObj* co = FUN_004b5260(obj4->tv116());
                WorldObj* world1;
                world1 = co ? co->FUN_006fa820() : 0;
                _result = world1 ? world1->FUN_0043b4f0().FUN_004a3a20() : FUN_005dbe10();
            }
        }
        else
        {
            CollObj* co5 = FUN_004b5260(tv116());
            WorldObj* world3;
            world3 = co5 ? co5->FUN_006fa820() : 0;
            _result = world3 ? world3->FUN_0043b4f0().FUN_004a3a20() : FUN_005dbe10();
        }
        RetObj retObjTmp = ctrl4->FUN_0070c440();
        retObjTmp.FUN_004a39f0(7);
        retObjTmp.FUN_0059ce80(_result);
        ctrl4->FUN_00810ff0(retObjTmp.f0);
    }
    Refr2* tailObjVal;
    tailObjVal = FUN_009185e0() ? FUN_009185e0()->tv11() : 0;
    if (tailObjVal != DAT_011dea3c)
    {
        FUN_0080fae0(*DAT_011d1c28.FUN_00403e20());
    }
}

extern NiPoint3 NiPoint3_ZERO;
struct Matrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    Matrix();
    void FUN_00a59780(float, float, float);
};
struct Node
{
    NiPoint3& FUN_0045bb80();
    NiPoint3& FUN_0043c490();
    void FUN_0043fa80(const Matrix*);
    void FUN_004f00e0(const NiPoint3*);
};
struct Flags
{
    unsigned value;
    void SetFlag4000(bool);
};
struct Controller
{
    float GetFloatAtOffset53C();
    void FUN_00812b00(NiPoint3&);
    Flags FUN_0070c440();
    void FUN_00810ff0(unsigned);
};
struct Anim
{
    unsigned char FUN_00813370();
    int FUN_008d8b80();
    float GetFloatAt144();
    void DispatchFloatPair(float, float, float, bool);
    bool FUN_00ee8990();
};
template <class T> struct Ptr
{
    T* ptr;
    operator T*() const;
    Ptr& operator=(T*);
};
struct Link
{
    Ptr<Anim> anim;
    Ptr<Node> node;
    int unk08, unk0c, unk10;
    Ptr<Node> first, second;
    Link* next;
    ~Link();
};
struct Owner
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
    virtual void Detach(Node*);
};
struct ParentNode : Node
{
    Owner* FUN_009611e0();
};
struct FloatSetting
{
    float* FUN_00403e20();
};
extern FloatSetting originalRuntimeFloatSetting1130;
struct IntSetting
{
    int* FUN_0043d4d0();
};
extern IntSetting g_011d1afc;
extern bool DAT_011dc55c;
float FUN_004587d0(float);
float FUN_004b5550(float, float);
struct Sound
{
    unsigned id, flags, state;
    bool FUN_00ad8ce0();
    void FUN_00ad88f0();
    void FUN_00ad8d10();
};
// The legacy magic fields share the storage described by the shared impact layout.
// Advances the projectile each frame: moves it, updates its animation and links, rotates toward the target, and marks it for removal when finished.
// @fnv 0x00812b60
void Projectile::UpdateMotion(float delta)
{
    if (delta == 0.0)
        return;
    if (FUN_00440d80())
        return;
    NiPoint3 original = reinterpret_cast<Node*>(GetNiNode())->FUN_0043c490();
    if ((Anim*)reinterpret_cast<Ptr<Anim>&>(m_kImpactTransform.m_Rotate.m_pEntry[1][2]) && reinterpret_cast<int&>(m_kImpactTransform.m_Rotate.m_pEntry[2][0]) == 0)
    {
        if (FUN_004587d0(FUN_009306d0()->GetFloatAtOffset53C()) >= (*reinterpret_cast<NiPoint3*>(static_cast<const TESObjectREFR*>(this)->GetPos())).z)
            reinterpret_cast<void (__thiscall*)(Projectile*, NiPoint3, int, int, int)>((*reinterpret_cast<void***>(this))[193])(this, (*reinterpret_cast<NiPoint3*>(static_cast<const TESObjectREFR*>(this)->GetPos())), 0, 0, 1);
        NiPoint3 movementVal(0.0f, reinterpret_cast<NiPoint2&>(kImpacts).x * delta, 0.0f);
        NiPoint3 before = NiPoint3_ZERO;
        if (FUN_009306d0())
            FUN_009306d0()->FUN_00812b00(before);
        static_cast<MobileObject*>(this)->Move(delta, reinterpret_cast<NiPoint3*>(&movementVal), 15);
        NiPoint3 after = NiPoint3_ZERO;
        if (FUN_009306d0())
            FUN_009306d0()->FUN_00812b00(after);
        reinterpret_cast<NiPoint2&>(kImpacts).y += (after - before).FUN_00457990();
        if (reinterpret_cast<NiPoint2&>(kImpacts).y > *originalRuntimeFloatSetting1130.FUN_00403e20())
            MarkForDeletion(true);
        if (!reinterpret_cast<bool (__thiscall*)(Projectile*)>((*reinterpret_cast<void***>(this))[195])(this))
            return;
    }
    else if (reinterpret_cast<int&>(m_kImpactTransform.m_Rotate.m_pEntry[2][0]) == 1)
    {
        Link* current3 = reinterpret_cast<Link*&>(m_kImpactTransform.m_Rotate.m_pEntry[2][1]);
        Link* previousTmp = 0;
        Link* next = 0;
        while (current3)
        {
            FUN_00812700(delta, current3);
            next = current3->next;
            if (((Anim*)current3->anim)->FUN_00813370())
            {
                Owner* owner = ((ParentNode*)(Node*)current3->node)->FUN_009611e0();
                if (owner)
                    owner->Detach(current3->node);
                if (previousTmp == 0)
                    reinterpret_cast<Link*&>(m_kImpactTransform.m_Rotate.m_pEntry[2][1]) = current3->next;
                else
                    previousTmp->next = current3->next;
                current3->node = 0;
                current3->anim = 0;
                current3->first = 0;
                current3->second = 0;
                delete current3;
            }
            else
                previousTmp = current3;
            current3 = next;
        }
    }
    if (*g_011d1afc.FUN_0043d4d0() > 0 || DAT_011dc55c)
    {
    }
    else
    {
        bool moving = reinterpret_cast<int&>(m_kImpactTransform.m_Rotate.m_pEntry[2][0]) != 0;
        if ((ParentNode*)reinterpret_cast<Ptr<ParentNode>&>(m_kImpactTransform.m_Translate.y))
        {
            NiPoint3 difference2 = ((ParentNode*)reinterpret_cast<Ptr<ParentNode>&>(m_kImpactTransform.m_Translate.y))->FUN_0045bb80() - original;
            if (!moving ||
                GetField90Float() * reinterpret_cast<NiPoint2&>(kImpacts).x > ((Anim*)reinterpret_cast<Ptr<Anim>&>(m_kImpactTransform.m_Rotate.m_pEntry[1][2]))->FUN_008d8b80() * ((Anim*)reinterpret_cast<Ptr<Anim>&>(m_kImpactTransform.m_Rotate.m_pEntry[1][2]))->GetFloatAt144())
                ((Anim*)reinterpret_cast<Ptr<Anim>&>(m_kImpactTransform.m_Rotate.m_pEntry[1][2]))->DispatchFloatPair(delta, difference2.FUN_00457990(), reinterpret_cast<NiPoint2&>(kImpacts).x, moving);
            Matrix rotation;
            float vertical = difference2.z;
            difference2.z = 0.0f;
            float horizontal_ = difference2.FUN_00457990();
            rotation.FUN_00a59780(FUN_004b5550(difference2.x, difference2.y), 0.0f,
                                  -FUN_004b5550(vertical, horizontal_));
            ((Node*)reinterpret_cast<Ptr<Node>&>(m_kImpactTransform.m_Rotate.m_pEntry[2][2]))->FUN_0043fa80(&rotation);
        }
        else if (FUN_009306d0())
        {
            NiPoint3 position;
            FUN_009306d0()->FUN_00812b00(position);
            float length = (original - position).FUN_00457990();
            if (!moving ||
                GetField90Float() * reinterpret_cast<NiPoint2&>(kImpacts).x > ((Anim*)reinterpret_cast<Ptr<Anim>&>(m_kImpactTransform.m_Rotate.m_pEntry[1][2]))->FUN_008d8b80() * ((Anim*)reinterpret_cast<Ptr<Anim>&>(m_kImpactTransform.m_Rotate.m_pEntry[1][2]))->GetFloatAt144())
                ((Anim*)reinterpret_cast<Ptr<Anim>&>(m_kImpactTransform.m_Rotate.m_pEntry[1][2]))->DispatchFloatPair(delta, length, reinterpret_cast<NiPoint2&>(kImpacts).x, moving);
            if (((Anim*)reinterpret_cast<Ptr<Anim>&>(m_kImpactTransform.m_Rotate.m_pEntry[1][2]))->FUN_00ee8990())
            {
                FUN_008133d0(2);
                Flags state = FUN_009306d0()->FUN_0070c440();
                state.SetFlag4000(true);
                FUN_009306d0()->FUN_00810ff0(state.value);
            }
        }
    }
    if ((Node*)reinterpret_cast<Ptr<Node>&>(m_kImpactTransform.m_Translate.z))
        ((Node*)reinterpret_cast<Ptr<Node>&>(m_kImpactTransform.m_Translate.z))->FUN_004f00e0(&(*reinterpret_cast<NiPoint3*>(static_cast<const TESObjectREFR*>(this)->GetPos())));
    if (((Anim*)reinterpret_cast<Ptr<Anim>&>(m_kImpactTransform.m_Rotate.m_pEntry[1][2]))->FUN_00813370() || (reinterpret_cast<int&>(m_kImpactTransform.m_Rotate.m_pEntry[2][0]) == 1 && GetUnka4() - start > 3.0))
    {
        if (reinterpret_cast<Sound&>(iFlags).FUN_00ad8ce0())
        {
            reinterpret_cast<Sound&>(iFlags).FUN_00ad88f0();
            reinterpret_cast<Sound&>(iFlags).FUN_00ad8d10();
        }
        if (!reinterpret_cast<Link*&>(m_kImpactTransform.m_Rotate.m_pEntry[2][1]))
            MarkForDeletion(true);
    }
}

namespace fnv_0081a320 {

struct FUN_008106b0_shell : FUN_00810a80_shell
{
    void FUN_008106b0(float strength);
};

struct FUN_0081c320_shell
{
    void UpdateLightFade(float);
};

struct FUN_00ad8ce0_shell
{

    unsigned char FUN_00ad8ce0();

    void FUN_00ad89e0(float strength);

    unsigned int unkBC, unkC0, unkC4, unkC8;
};

struct FUN_00817160_shell
{
    void ApplySpellEffects();
};

extern Setting DAT_011d1ad8, DAT_011d1d00, DAT_011d17f4;

extern double DAT_01012638, DAT_01012060, DAT_01020998, DAT_01011590;

extern NiPoint3 DAT_011f426c;

double __cdecl FUN_004587d0(float);

float __cdecl FUN_00406cc0(float);

int __cdecl FUN_00ec62c0();

struct FUN_0081a320_class;

struct FUN_009306d0_shell
{
    FUN_008106b0_shell* FUN_009306d0();
};

struct FUN_0081a320_class
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

    virtual void v49(int value);

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

    virtual NiAVObject* v116();

    virtual void v117();

    virtual void v118();

    virtual void v119();

    virtual void v120();

    virtual void v121();

    virtual void v122();

    virtual void v123();

    virtual void v124();

    virtual NiPoint3* v125();

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

    virtual void v148(float time, NiPoint3* aim, int flags);

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

    virtual void v193(NiPoint3 point, int a, int b, int c);

    virtual void v194();

    virtual unsigned char v195();

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

    float m_88;

    float m_8c;

    unsigned int unk090;

    unsigned int unk094;

    unsigned int unk098;

    unsigned int unk09c;

    unsigned int unk0a0;

    unsigned int unk0a4;

    float m_a8;

    float m_ac;

    unsigned int unk0b0;

    int m_b4;

    unsigned int unk0b8;

    FUN_00ad8ce0_shell m_bc;

    FUN_0081c320_shell* m_cc;

    int FUN_008d6f30(NiPoint3 position, FUN_0081a320_class* owner, int x, int y, float ratio, float weight);

    int FUN_00810fd0(int);

    FUN_00817160_shell* FUN_009185e0(int);

    void FUN_0081a320(float dt);
};

// @fnv 0x0081a320
void FUN_0081a320_class::FUN_0081a320(float afDeltaTime)
{

    if (afDeltaTime >= DAT_01012638)
        v49(1);

    if (afDeltaTime >= DAT_01012060)
    {

        switch (m_b4)
        {
        case 0: {

            if (reinterpret_cast<MobileObject*>(this)->FUN_00440d80())
                return;

            if (FUN_004587d0(((FUN_009306d0_shell*)this)->FUN_009306d0()->GetFloatAtOffset53C()) >= v125()->z)
                v193(reinterpret_cast<const NiPoint3&>(*v125()), 0, 0, 1);

            float distanceTraveled;
            float aim[3];

            reinterpret_cast<NiPoint3*>(aim)->FUN_00416870(0.0f, m_88 * afDeltaTime, 0.0f);

            ((FUN_009306d0_shell*)this)
                ->FUN_009306d0()
                ->FUN_008106b0(1.0f - afDeltaTime * *DAT_011d1ad8.FUN_00403e20());

            NiPoint3 start = reinterpret_cast<const NiPoint3&>(*v125());

            v148(afDeltaTime, reinterpret_cast<NiPoint3*>(aim), 15);

            if (!v195())
            {
            }
            else
            {

                NiPoint3 vCurrentPosition = reinterpret_cast<const NiPoint3&>(*v125());

                v116()->FUN_00440460(reinterpret_cast<NiPoint3*>(&vCurrentPosition));
                distanceTraveled = reinterpret_cast<NiPoint3&>(vCurrentPosition).FUN_00439ef0(reinterpret_cast<NiPoint3*>(&start)).FUN_00457990();

                m_8c += distanceTraveled;

                if (m_8c > *DAT_011d1d00.FUN_00403e20())
                    v49(1);

                if ((double)(distanceTraveled / afDeltaTime) < DAT_01020998)
                    v193(reinterpret_cast<const NiPoint3&>(DAT_011f426c), 0, 0, 0);
            }
        }
        break;
        }
        float fPreviousTime = m_a8;

        m_a8 += afDeltaTime;

        if (m_a8 > m_ac)
        {
            v49(1);
        }
        else
        {

            if (m_cc)
                m_cc->UpdateLightFade(afDeltaTime);

            if (m_bc.FUN_00ad8ce0())
            {

                float fSegmentTime = (float)(m_ac / DAT_01011590);

                if (m_a8 > fSegmentTime)
                    m_bc.FUN_00ad89e0(1.0f * (1.0f - ((m_a8 - fSegmentTime) / fSegmentTime)));
            }

            if ((int)FUN_00406cc0(fPreviousTime / *DAT_011d17f4.FUN_00403e20()) !=
                (int)FUN_00406cc0(m_a8 / *DAT_011d17f4.FUN_00403e20()))
            {

                float ratio = (m_ac - m_a8) / m_ac;

                if (DAT_01012060 < ratio)
                {

                    FUN_009185e0(FUN_00810fd0(FUN_008d6f30(reinterpret_cast<const NiPoint3&>(*v125()), this, 0, 0, ratio, 1.0f)))->ApplySpellEffects();
                }
            }
        }
    }
}
}  // namespace fnv_0081a320

struct SaveStream
{

    int __thiscall FUN_00825c00();

    bool __thiscall FUN_00862110();

    unsigned char __thiscall FUN_008df040();

    void __thiscall FUN_008579b0(const void*, int);

    void* __thiscall FUN_004fd3e0();
};

struct SaveFlag
{

    unsigned char* __thiscall FUN_00408d60();
};

extern SaveFlag DAT_011de4e8;

extern unsigned char UNK_0101536c, UNK_010153a0, UNK_01015318, UNK_01085d58;

extern "C" void __cdecl FUN_0040fbe0(const void*, ...);

extern "C" void __cdecl FUN_005b5e40(const void*, const void*, int);

extern "C" int __cdecl FUN_004839c0(int);

extern "C" int __cdecl FUN_004a8b00(int);

extern "C" unsigned short __cdecl FUN_004b66d0(int, int, int, int);

extern "C" unsigned short __cdecl FilterByFlags(int, int, int, int, int);

struct SaveHandle
{

    int __thiscall FUN_0084e3a0();
};

struct StateProcessor
{

    int __thiscall FUN_0043fcd0();
};

struct Vec3f
{
    float x, y, z;
};

struct MotionStateRecord
{

    int type;

    Vec3f origin;

    Vec3f axis;

    Vec3f velocity;

    StateProcessor* handle;

    int packed;

    char extended[16];
};

struct FourInts
{

    int x0, x1, x2, x3;

    void __thiscall FUN_006815c0();

    void __thiscall FUN_00a6df40(void*);
};

struct FUN_008ce610_owner : PC7d
{

    void __thiscall SaveProcess(int);

    void __thiscall ForwardToSaveLoadGame(void*, int);

    void __thiscall FUN_008ce610(int);
};

// @fnv 0x008ce610
void FUN_008ce610_owner::FUN_008ce610(int arg)
{

    SaveProcess(arg);

    unsigned short idB = 0;

    unsigned short* pLength = 0;

    int start = reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00825c00();

    if (*DAT_011de4e8.FUN_00408d60())
    {

        start = reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00825c00();
    }

    if (reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00862110())
    {

        unsigned int magic = 0x424c4f4b;

        reinterpret_cast<TESSaveLoadGameHelper*>(DAT_011de45c)->FUN_008579b0(&magic, 4);

        pLength = reinterpret_cast<unsigned short*>(reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00825c00());

        reinterpret_cast<TESSaveLoadGameHelper*>(DAT_011de45c)->FUN_008579b0(&idB, 2);
    }

    reinterpret_cast<TESSaveLoadGameHelper*>(DAT_011de45c)->FUN_008579b0(reinterpret_cast<char*>(this) + 0x8c, 4);

    FUN_00484ce0(reinterpret_cast<char*>(this) + 0x90, 4);

    FUN_00484ce0(reinterpret_cast<char*>(this) + 0x94, 4);

    FUN_00484ce0(reinterpret_cast<char*>(this) + 0x98, 4);

    FUN_00484ce0(reinterpret_cast<char*>(this) + 0x9c, 4);

    FUN_00484ce0(reinterpret_cast<char*>(this) + 0xa0, 4);

    FUN_00484ce0(reinterpret_cast<char*>(this) + 0xb4, 12);

    unsigned int hasState = 0;

    if (*reinterpret_cast<SaveHandle**>(reinterpret_cast<char*>(this) + 0xa4))
        hasState = (*reinterpret_cast<SaveHandle**>(reinterpret_cast<char*>(this) + 0xa4))->FUN_0084e3a0();

    ForwardToSaveLoadGame(&hasState, 4);

    unsigned int idA = 0;

    if (*reinterpret_cast<SaveHandle**>(reinterpret_cast<char*>(this) + 0xa8))
        idA = (*reinterpret_cast<SaveHandle**>(reinterpret_cast<char*>(this) + 0xa8))->FUN_0084e3a0();

    ForwardToSaveLoadGame(&idA, 4);

    unsigned int blockLength = 0;

    if (*reinterpret_cast<SaveHandle**>(reinterpret_cast<char*>(this) + 0xb0))
        blockLength = (*reinterpret_cast<SaveHandle**>(reinterpret_cast<char*>(this) + 0xb0))->FUN_0084e3a0();

    ForwardToSaveLoadGame(&blockLength, 4);

    bool idC = false;

    if (*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))
        idC = true;

    FUN_00484ce0(&idC, 1);

    if (idC)
    {

        reinterpret_cast<TESSaveLoadGameHelper*>(DAT_011de45c)
            ->FUN_008579b0((*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88)), 4);

        FUN_00484ce0(&(*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->origin, 12);

        FUN_00484ce0(&(*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->axis, 12);

        FUN_00484ce0(&(*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->velocity, 12);

        if (DAT_011de45c->FUN_008df040() >= 0x50)
        {

            FourInts transform;

            transform.FUN_006815c0();

            transform.FUN_00a6df40(
                &(*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->extended);

            reinterpret_cast<TESSaveLoadGameHelper*>(DAT_011de45c)->FUN_008579b0(&transform, 16);
        }

        if ((*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->type == 1 ||
            (*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->type == 0)
        {

            unsigned int handleID = 0;

            if ((*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->handle)
                handleID = reinterpret_cast<SaveHandle*>(
                               (*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->handle)
                               ->FUN_0084e3a0();

            ForwardToSaveLoadGame(&handleID, 4);

            unsigned short low = 0;

            short high = -1;

            if ((*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->handle &&
                (*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->packed)
            {

                if (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xc0) == 0)
                {

                    bool invert =
                        (*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->type == 0;

                    low = FUN_004b66d0((*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))
                                           ->handle->FUN_0043fcd0(),
                                       invert, invert, 1);

                    int prepared = FUN_004a8b00(
                        (*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->packed);

                    high = FilterByFlags((*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))
                                             ->handle->FUN_0043fcd0(),
                                         prepared, invert, invert, 1);
                }
                else
                {

                    unsigned int packedValue =
                        (*reinterpret_cast<MotionStateRecord**>(reinterpret_cast<char*>(this) + 0x88))->packed;

                    low = static_cast<unsigned short>(packedValue >> 16);

                    high = static_cast<unsigned short>((packedValue << 16) >> 16);
                }
            }

            FUN_00484ce0(&low, 2);

            FUN_00484ce0(&high, 2);
        }
    }

    if (DAT_011de45c->FUN_008df040() >= 0x54)
    {

        FUN_00484ce0(reinterpret_cast<char*>(this) + 0xc1, 1);
    }

    if (DAT_011de45c->FUN_008df040() >= 0x55)
    {

        FUN_00484ce0(reinterpret_cast<char*>(this) + 0xc2, 1);
    }

    if (*DAT_011de4e8.FUN_00408d60())
    {

        int info = reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00825c00();

        unsigned int* finished =
            static_cast<unsigned int*>(reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_004fd3e0());

        if (finished)
        {

            int manager = FUN_004839c0(*finished);

            typedef int(__thiscall * LogFunction)(void*);

            FUN_0040fbe0(&UNK_010153a0, info - start, *finished,

                         reinterpret_cast<LogFunction>((*reinterpret_cast<void***>(manager))[76])(
                             reinterpret_cast<void*>(manager)),

                         *reinterpret_cast<int*>(reinterpret_cast<char*>(finished) + 5), 0x8ea, &UNK_01085d58);
        }
        else
        {

            FUN_0040fbe0(&UNK_0101536c, info - start, 0x8ea, &UNK_01085d58);
        }
    }

    if (reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00862110())
    {

        int lengthFieldPointer = reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00825c00();

        unsigned short* info = pLength;

        if (static_cast<unsigned int>(lengthFieldPointer) > reinterpret_cast<unsigned int>(info) + 0xffffU)
        {

            FUN_005b5e40(&UNK_01015318, &UNK_01085d58, 0x8ea);
        }

        *pLength = static_cast<unsigned short>(lengthFieldPointer - reinterpret_cast<int>(info));
    }
}

namespace fnv_008ceb50 {
static const char underrunMessage[] =
    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X";
static const char overrunMessage[] =
    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X";
struct Matrix
{
    float a, b, c, d, e, f, g, h, i;
    Matrix();
};
extern Matrix DAT_011a9448;

struct ExtraData
{
    int kind;
    float x, y, z, rx, ry, rz, sx, sy, sz;
    unsigned ref;
    void* name;
    Matrix matrix;
    ExtraData();
};
struct Record
{
    unsigned id;
    unsigned char kind;
    char payload0, payload1, payload2, payload3;
    unsigned char subtype;
};
struct Word
{
    unsigned value;
};
struct Form
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
    virtual const char* describe();
};
Form* lookup(unsigned);
struct Loader
{
    bool active();
    void read(void*, unsigned);
    Record* record();
    unsigned position();
    unsigned char version();
    void skip(unsigned);
};
extern Loader* loaderState;
void warning(const char*, ...);
void* __cdecl operator new(unsigned);
void* __cdecl memset(void*, int, unsigned);
struct Loaded
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
    ExtraData* extra;
    unsigned mode, a90, a94, a98, a9c, aa0, refA, refB, unknownAc, refC;
    float x, y, z;
    unsigned char c0, c1, c2;
    void baseLoad(void*, void*);
    void read(void*, unsigned);
    void readRef(unsigned*, unsigned);
    void FUN_008ceb50(void*, void*);
};
// Loads the block header, mode, refs, position and extra data (with optional rotation and name) from the loader, then warns on buffer overrun or underrun.
// @fnv 0x008ceb50
void Loaded::FUN_008ceb50(void* arg1, void* arg2)
{
    baseLoad(arg1, arg2);
    unsigned short a = 0;
    unsigned i = 0;
    if (loaderState->active())
    {
        unsigned tag;
        loaderState->read(&tag, 4);
        if (tag != 0x424c4f4b)
        {
            Record* rec = loaderState->record();
            if (rec)
            {
                Form* form = lookup(rec->id);
                warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\ArrowProjectile.cpp", 0x8f5, rec->id,
                    form->describe(), rec->subtype, ((Word*)&rec->payload0)->value);
            }
            else
                warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\ArrowProjectile.cpp", 0x8f5,
                    loaderState->version());
        }
        i = loaderState->position();
        loaderState->read(&a, 2);
    }
    loaderState->read(&mode, 4);
    read(&a90, 4);
    read(&a94, 4);
    read(&a98, 4);
    read(&a9c, 4);
    read(&aa0, 4);
    read(&x, 12);
    unsigned h;
    readRef(&h, 4);
    refA = h;
    unsigned f;
    readRef(&f, 4);
    refB = f;
    unsigned s;
    readRef(&s, 4);
    refC = s;
    if (loaderState->version() < 32)
        loaderState->skip(8);
    bool p = false;
    if (loaderState->version() >= 32)
        read(&p, 1);
    if (loaderState->version() < 32)
        p = mode == 1 || mode == 2;
    if (p)
    {
        extra = new ExtraData;
        extra->name = 0;
        extra->ref = 0;
        extra->matrix = DAT_011a9448;
        loaderState->read(&extra->kind, 4);
        read(&extra->x, 12);
        read(&extra->rx, 12);
        read(&extra->sx, 12);
        if (loaderState->version() >= 80)
        {
            Vec4 rotation;
            loaderState->read(&rotation, 16);
            Matrix temp;
            rotation.convert(reinterpret_cast<::Matrix*>(&extra->matrix));
        }
        if (extra->kind == 1 || extra->kind == 0)
        {
            unsigned ref;
            readRef(&ref, 4);
            extra->ref = ref;
            if (loaderState->version() >= 32)
            {
                unsigned short h;
                short p;
                read(&h, 2);
                read(&p, 2);
                unsigned a = (h << 16) + p;
                extra->name = (void*)a;
            }
            if (loaderState->version() < 32)
            {
                unsigned char p;
                read(&p, 1);
                char* h = (char*)operator new(p + 1);
                memset(h, 0, p + 1);
                read(h, p);
                extra->name = h;
            }
        }
    }
    if (loaderState->version() >= 84)
        read(&c1, 1);
    if (loaderState->version() >= 85)
        read(&c2, 1);
    if (loaderState->active())
    {
        unsigned end = loaderState->position();
        Record* recEnd = loaderState->record();
        if (recEnd)
        {
            Form* formEnd = lookup(recEnd->id);
            if (end > i + a)
                warning(overrunMessage, end - (i + a),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\ArrowProjectile.cpp", 0x965, recEnd->id,
                        formEnd->describe(), recEnd->subtype, ((Word*)&recEnd->payload0)->value);
            else if (end < i + a)
                warning(underrunMessage, i + a - end,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\ArrowProjectile.cpp", 0x965, recEnd->id,
                        formEnd->describe(), recEnd->subtype, ((Word*)&recEnd->payload0)->value);
        }
        else
        {
            if (end > i + a)
                warning("SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                        end - (i + a), "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\ArrowProjectile.cpp",
                        0x965, loaderState->version());
            else if (end < i + a)
                warning("SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                        i + a - end, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\ArrowProjectile.cpp", 0x965,
                        loaderState->version());
        }
    }
}
}  // namespace fnv_008ceb50

namespace fnv_008cf440 {
struct Mid;
struct Node;
struct FlagObj
{
    unsigned int FUN_0044ddc0();
};
struct Node
{
    void* FUN_0043fcd0();
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual int slot76();
    bool FUN_00440da0();
    bool FUN_00440d80();
    unsigned int FUN_0084e3a0();
};
struct Mid
{
    int f00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    Node* f28;
    int f2c;
};
struct Mgr85
{
    void AddActorToList(int*);
};
unsigned short __cdecl FUN_004b66d0(void*, int, int, int);
FlagObj* __cdecl FUN_004b6980(void*, int, int, int, int);
void* __cdecl FUN_004aae30(void*, int);
int __cdecl FUN_005b5e40(const char*, ...);
extern char DAT_01085d9c[];
struct Cls
{
    void* FUN_0043fcd0();
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual void slot49(int);
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    Mid* f88;
    int u8c;
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    int fa4;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    int ub8;
    int ubc;
    unsigned char fc0;
    unsigned char uc1;
    unsigned char uc2;
    unsigned char uc3;
    int fc4;
    void FUN_0046a010(int);
    void FUN_008caea0(int, float);
    void UpdateFlags(int, int);
    void FUN_008cf440(int, int);
};

// @fnv 0x008cf440
void Cls::FUN_008cf440(int a1, int a2)
{
    void* saved;
    int saved2c5;
    int result;
    unsigned short wordres;
    int hi5;
    int lo_;
    bool _flag;
    FUN_0046a010(0);
    saved = FUN_0043fcd0();
    if (!FUN_0043fcd0())
    {
        if (f88 != 0 && f88->f28 != 0 && f88->f28->FUN_00440da0() && f88->f28->FUN_00440d80())
        {
            slot49(1);
            f88->f2c = 0;
            return;
        }
        fc0 = 1;
        fc4 = a1;
        return;
    }
    FUN_008caea0(fa4, 1.0f);
    UpdateFlags(a1, a2);
    if (f88 != 0 && (f88->f00 == 1 || f88->f00 == 0))
    {
        if ((int)DAT_011de45c->FUN_008df040() >= 0x20)
        {
            _flag = f88->f00 == 0;
            lo_ = f88->f2c;
            hi5 = (int)((unsigned int)f88->f2c >> 0x10);
            f88->f2c = 0;
            if (f88->f28 != 0)
            {
                wordres = FUN_004b66d0(f88->f28->FUN_0043fcd0(), _flag, _flag, 1);
                if (hi5 != (int)wordres)
                {
                    FUN_005b5e40(DAT_01085d9c, f88->f28->slot76(), f88->f28->FUN_0084e3a0());
                }
                else if (lo_ != -1)
                {
                    result = (int)FUN_004b6980(f88->f28->FUN_0043fcd0(), lo_, _flag, _flag, 1);
                    if (result != 0)
                    {
                        f88->f2c = ((FlagObj*)result)->FUN_0044ddc0();
                    }
                }
            }
        }
        if ((int)DAT_011de45c->FUN_008df040() < 0x20)
        {
            saved2c5 = f88->f2c;
            if (f88->f28 != 0)
            {
                f88->f2c = (int)FUN_004aae30(f88->f28->FUN_0043fcd0(), saved2c5);
            }
            else
            {
                f88->f2c = 0;
            }
            _Deallocate((void*)saved2c5);
        }
        if (f88->f2c == 0)
        {
            f88->f00 = 3;
        }
    }
    ((Mgr85*)DAT_011de45c)->AddActorToList((int*)this);
}
}  // namespace fnv_008cf440

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct SpinLock_931710
{
    void Lock(const char*);
    void Unlock();
};
extern SpinLock_931710 DAT_011f11a0;

struct Self_931710 : Self
{
    bool FUN_00931710();
};

// @fnv 0x00931710
bool Self_931710::FUN_00931710()
{
    int level = this->m68->FUN_0045cd60();
    DAT_011f11a0.Lock(0);
    DAT_011e0e80.FUN_0096d470(reinterpret_cast<MobileObject*>(this), level);
    Obj* newProc2 = new FUN_008d7510();
    newProc2->v1(this->m68);
    delete this->m68;
    this->m68 = newProc2;
    DAT_011e0e80.FUN_0096d450(reinterpret_cast<MobileObject*>(this), 0, false, false, false);
    DAT_011f11a0.Unlock();
    this->s127(0);
    this->m68->v18();
    return true;
}

namespace fnv_00935820 {
extern const double DAT_0101db88;
extern const float DAT_0101e704;
extern const float DAT_0101e340;

extern "C" int FUN_004b5470(NiPoint3* point, float value);

struct ProjectileImpactCandidate : ProjectileImpact
{
    bool IsPointWithinImpactRange(const NiPoint3& point, float value, bool adjust, int unused_stack);
};

// @fnv 0x00935820
bool ProjectileImpactCandidate::IsPointWithinImpactRange(const NiPoint3& point, float value, bool adjust,
                                                         int unused_stack)
{
    float upper;
    float lower;
    float upperBase;
    {
        // Preserve the original implicit three-word copy.
        NiPoint3 origin = reinterpret_cast<const NiPoint3&>(this->position());
        NiPoint3 result = reinterpret_cast<NiPoint3&>(origin) - point;

        upper = DAT_0101e704;
        lower = origin.z - DAT_0101db88;
        upperBase = origin.z + upper + DAT_0101db88;
        if (point.z > lower && point.z < upperBase)
        {
            result.z = 0.0f;
        }
        if (adjust)
        {
            float adjustment = DAT_0101e340;
            value += adjustment;
        }
        return FUN_004b5470(&result, value) <= 0;
    }
}
}  // namespace fnv_00935820

struct SaveState
{
    bool FUN_00862110();
    unsigned char FUN_008df040();
    struct ValueReferencePair* GetHitSound();
};

struct ValueReferencePair
{
    unsigned id;
    unsigned char kind;
    unsigned char flags0, flags1, flags2, flags3;
};
struct SaveSetting
{
    bool* Bool();
};
extern SaveSetting g_011de4e8;
struct SaveForm
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
    virtual const char* GetName();
};
SaveForm* __cdecl FUN_004839c0(unsigned);
void __cdecl SaveLog(const char*, ...);
struct ProjectileData
{
    int type;
};
struct ArrowSave
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
    ProjectileData* data;
    unsigned short FUN_00931ff0(unsigned);
    unsigned short FUN_008ce3b0(unsigned);
};
// Computes the serialized save size of an ArrowSave, adding field sizes conditionally on save version and projectile type, and logs the result.
// @fnv 0x008ce3b0
unsigned short ArrowSave::FUN_008ce3b0(unsigned flags)
{
    unsigned short size7 = 0;
    size7 += FUN_00931ff0(flags);
    unsigned short start = size7;
    if (((SaveState*)g_TESSaveLoadGame)->FUN_00862110())
    {
        size7 += 4;
        size7 += 2;
    }
    size7 += 4;
    size7 += 4;
    size7 += 4;
    size7 += 4;
    size7 += 4;
    size7 += 4;
    size7 += 12;
    size7 += 4;
    size7 += 4;
    size7 += 4;
    bool present = false;
    if (data != 0)
        present = true;
    size7 += 1;
    if (present)
    {
        size7 += 4;
        size7 += 12;
        size7 += 12;
        size7 += 12;
        if (((SaveState*)g_TESSaveLoadGame)->FUN_008df040() >= 80)
            size7 += 16;
        if (data->type == 1 || data->type == 0)
        {
            size7 += 4;
            size7 += 2;
            size7 += 2;
        }
    }
    if (((SaveState*)g_TESSaveLoadGame)->FUN_008df040() >= 84)
        size7 += 1;
    if (((SaveState*)g_TESSaveLoadGame)->FUN_008df040() >= 85)
        size7 += 1;
    if (*g_011de4e8.Bool())
    {
        ValueReferencePair* entry = ((SaveState*)g_TESSaveLoadGame)->GetHitSound();
        if (entry)
        {
            SaveForm* form = FUN_004839c0(entry->id);
            SaveLog("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", size7 - start,
                    entry->id, form->GetName(), *(unsigned*)&entry->flags0, 2174,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\ArrowProjectile.cpp");
        }
        else
        {
            SaveLog("GetSaveSize(): %-5i ending at line %i in file %s", size7 - start, 2174,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\ArrowProjectile.cpp");
        }
    }
    return size7;
}

extern const double DAT_0101de30;
extern NiPoint3 DAT_011a9478;
extern FloatSetting originalRuntimeFloatSetting1137;
extern FloatSetting originalRuntimeFloatSetting1138;
extern FloatSetting originalRuntimeFloatSetting1139;


struct CustomFlags
{
    unsigned int value;
    CustomFlags()
    {}
    CustomFlags(const CustomFlags& o) : value(o.value)
    {}
    void SetFlag4000(bool);
};

struct Sub410
{
    int FUN_00621270(int);
};

struct ProjectileNodeStandin
{
    int unks_000;
    int unks_004;
    int unks_008;
    int unks_00c;
    int unks_010;
    int unks_014;
    int unks_018;
    int unks_01c;
    int unks_020;
    int unks_024;
    int unks_028;
    int unks_02c;
    int unks_030;
    int unks_034;
    int unks_038;
    int unks_03c;
    int unks_040;
    int unks_044;
    int unks_048;
    int unks_04c;
    int unks_050;
    int unks_054;
    int unks_058;
    int unks_05c;
    int unks_060;
    int unks_064;
    int unks_068;
    int unks_06c;
    int unks_070;
    int unks_074;
    int unks_078;
    int unks_07c;
    int unks_080;
    int unks_084;
    int unks_088;
    int unks_08c;
    int unks_090;
    int unks_094;
    int unks_098;
    int unks_09c;
    int unks_0a0;
    int unks_0a4;
    int unks_0a8;
    int unks_0ac;
    int unks_0b0;
    int unks_0b4;
    int unks_0b8;
    int unks_0bc;
    int unks_0c0;
    int unks_0c4;
    int unks_0c8;
    int unks_0cc;
    int unks_0d0;
    int unks_0d4;
    int unks_0d8;
    int unks_0dc;
    int unks_0e0;
    int unks_0e4;
    int unks_0e8;
    int unks_0ec;
    int unks_0f0;
    int unks_0f4;
    int unks_0f8;
    int unks_0fc;
    int unks_100;
    int unks_104;
    int unks_108;
    int unks_10c;
    int unks_110;
    int unks_114;
    int unks_118;
    int unks_11c;
    int unks_120;
    int unks_124;
    int unks_128;
    int unks_12c;
    int unks_130;
    int unks_134;
    int unks_138;
    int unks_13c;
    int unks_140;
    int unks_144;
    int unks_148;
    int unks_14c;
    int unks_150;
    int unks_154;
    int unks_158;
    int unks_15c;
    int unks_160;
    int unks_164;
    int unks_168;
    int unks_16c;
    int unks_170;
    int unks_174;
    int unks_178;
    int unks_17c;
    int unks_180;
    int unks_184;
    int unks_188;
    int unks_18c;
    int unks_190;
    int unks_194;
    int unks_198;
    int unks_19c;
    int unks_1a0;
    int unks_1a4;
    int unks_1a8;
    int unks_1ac;
    int unks_1b0;
    int unks_1b4;
    int unks_1b8;
    int unks_1bc;
    int unks_1c0;
    int unks_1c4;
    int unks_1c8;
    int unks_1cc;
    int unks_1d0;
    int unks_1d4;
    int unks_1d8;
    int unks_1dc;
    int unks_1e0;
    int unks_1e4;
    int unks_1e8;
    int unks_1ec;
    int unks_1f0;
    int unks_1f4;
    int unks_1f8;
    int unks_1fc;
    int unks_200;
    int unks_204;
    int unks_208;
    int unks_20c;
    int unks_210;
    int unks_214;
    int unks_218;
    int unks_21c;
    int unks_220;
    int unks_224;
    int unks_228;
    int unks_22c;
    int unks_230;
    int unks_234;
    int unks_238;
    int unks_23c;
    int unks_240;
    int unks_244;
    int unks_248;
    int unks_24c;
    int unks_250;
    int unks_254;
    int unks_258;
    int unks_25c;
    int unks_260;
    int unks_264;
    int unks_268;
    int unks_26c;
    int unks_270;
    int unks_274;
    int unks_278;
    int unks_27c;
    int unks_280;
    int unks_284;
    int unks_288;
    int unks_28c;
    int unks_290;
    int unks_294;
    int unks_298;
    int unks_29c;
    int unks_2a0;
    int unks_2a4;
    int unks_2a8;
    int unks_2ac;
    int unks_2b0;
    int unks_2b4;
    int unks_2b8;
    int unks_2bc;
    int unks_2c0;
    int unks_2c4;
    int unks_2c8;
    int unks_2cc;
    int unks_2d0;
    int unks_2d4;
    int unks_2d8;
    int unks_2dc;
    int unks_2e0;
    int unks_2e4;
    int unks_2e8;
    int unks_2ec;
    int unks_2f0;
    int unks_2f4;
    int unks_2f8;
    int unks_2fc;
    int unks_300;
    int unks_304;
    int unks_308;
    int unks_30c;
    int unks_310;
    int unks_314;
    int unks_318;
    int unks_31c;
    int unks_320;
    int unks_324;
    int unks_328;
    int unks_32c;
    int unks_330;
    int unks_334;
    int unks_338;
    int unks_33c;
    int unks_340;
    int unks_344;
    int unks_348;
    int unks_34c;
    int unks_350;
    int unks_354;
    int unks_358;
    int unks_35c;
    int unks_360;
    int unks_364;
    int unks_368;
    int unks_36c;
    int unks_370;
    int unks_374;
    int unks_378;
    int unks_37c;
    int unks_380;
    int unks_384;
    int unks_388;
    int unks_38c;
    int unks_390;
    int unks_394;
    int unks_398;
    int unks_39c;
    int unks_3a0;
    int unks_3a4;
    int unks_3a8;
    int unks_3ac;
    int unks_3b0;
    int unks_3b4;
    int unks_3b8;
    int unks_3bc;
    int unks_3c0;
    int unks_3c4;
    int unks_3c8;
    int unks_3cc;
    int unks_3d0;
    int unks_3d4;
    int unks_3d8;
    int unks_3dc;
    int unks_3e0;
    int unks_3e4;
    int unks_3e8;
    int unks_3ec;
    int unks_3f0;
    int unks_3f4;
    int unks_3f8;
    int unks_3fc;
    int unks_400;
    int unks_404;
    int unks_408;
    int unks_40c;
    Sub410 sub410;
    CustomFlags FUN_0070c440();
    void FUN_00810ff0(unsigned int);
};


struct NodeEffect
{
    void FUN_0081c470(bool, float);
};


// Preserve the by-value three-float ABI independently of NiPoint3 copy construction.
void EmitProjectileAreaEffect();
// NiMatrix3::operator*(const NiPoint3&) const (0x004b4500) seen through this unit's NiPoint3.
struct FUN_004b4500_Vec3View : public NiMatrix3
{
    NiPoint3 operator*(const NiPoint3& point) const;
};

// @fnv 0x00810aa0
void ContinuousBeamProjectile::ApplyAreaEffect(NiPoint3 point, unsigned int variant, TESObjectREFR* target, bool silent)
{
    Actor* pActor2 = (target && ((Actor*)target)->IsActor()) ? (Actor*)target : 0;
    if (pActor2 && pActor2->GetGhost())
        return;

    m_kImpactTransform.m_Rotate.m_pEntry[2][1] = (float)((double)this->FUN_00586150()->GetArea() * *originalRuntimeFloatSetting1137.FUN_00403e20());
    if (m_kImpactTransform.m_Rotate.m_pEntry[2][1] > *originalRuntimeFloatSetting1138.FUN_00403e20())
    {
        m_kImpactTransform.m_Rotate.m_pEntry[2][1] = *originalRuntimeFloatSetting1138.FUN_00403e20();
    }
    else if (m_kImpactTransform.m_Rotate.m_pEntry[2][1] < *originalRuntimeFloatSetting1139.FUN_00403e20())
    {
        m_kImpactTransform.m_Rotate.m_pEntry[2][1] = *originalRuntimeFloatSetting1139.FUN_00403e20();
    }

    this->FUN_00575830(&point);

    NiAVObject* pNode2 = this->GetNiNode();
    if (pNode2)
    {
        reinterpret_cast<void (__thiscall*)(ContinuousBeamProjectile*, NiPoint3, NiPoint3, unsigned int)>(&EmitProjectileAreaEffect)(
            this, point, reinterpret_cast<const NiPoint3&>(
                (const FUN_004b4500_Vec3View&)pNode2->FUN_00461130().m_Rotate * reinterpret_cast<const NiPoint3&>(DAT_011a9478)), variant);
    }

    if (pNode2 && !silent)
    {
        pNode2->FUN_00440460(point);
        NiAVObject* effect20 = pNode2->GetObjectByName(NiFixedString("AreaEffect"));
        if (effect20)
        {
            effect20->FUN_00440490(m_kImpactTransform.m_Rotate.m_pEntry[2][1]);
        }
    }

    if (reinterpret_cast<Sound&>(m_kImpactTransform.m_Rotate.m_pEntry[2][2]).FUN_00ad8ce0())
        reinterpret_cast<Sound&>(m_kImpactTransform.m_Rotate.m_pEntry[2][2]).FUN_00ad88f0();

    if (this->FUN_009306d0() && !silent)
    {
        if (this->FUN_009306d0()->sub410.FUN_00621270(0x8000))
        {
            reinterpret_cast<void (__thiscall*)(ContinuousBeamProjectile*)>((*reinterpret_cast<void***>(this))[196])(this);
        }
        CustomFlags aFlags3 = this->FUN_009306d0()->FUN_0070c440();
        aFlags3.SetFlag4000(true);
        this->FUN_009306d0()->FUN_00810ff0(aFlags3.value);
    }

    reinterpret_cast<int&>(m_kImpactTransform.m_Rotate.m_pEntry[2][0]) = 2;
    if (!silent)
    {
        this->FUN_009185e0()->ApplySpellEffects(this->GetArchetype(), this->FUN_008d6f30(),
                                                *(ImpactPoint*)static_cast<const TESObjectREFR*>(this)->GetPos(), this, (int)target, 0, 1.0f, 1.0f);
    }

    NiAVObject* pRoot4 = this->GetNiNode();
    NiTimeController* pCtrl5 = pRoot4 ? pRoot4->GetControllers() : 0;
    NiControllerManager* pManagerTmp = (NiControllerManager*)FUN_00653270(&DAT_011f36ac, pCtrl5);
    if (pManagerTmp)
    {
        NiControllerSequence* aPSeq5 = (NiControllerSequence*)pManagerTmp->FUN_0047a520(NiFixedString("SpecialIdle_AreaEffect"));
        if (aPSeq5)
        {
            pManagerTmp->FUN_0048fef0(0.0f);
            pManagerTmp->FUN_0047aab0((NiControllerSequence*)aPSeq5, 0, 0, 1.0f, 0.0f, 0);
            pManagerTmp->FUN_0047aa40(true);
            aPSeq5->FUN_0098adb0(-DAT_0107a510);
            if (reinterpret_cast<NodeEffect*&>(m_kImpactTransform.m_Translate.z))
            {
                reinterpret_cast<NodeEffect*&>(m_kImpactTransform.m_Translate.z)->FUN_0081c470(false, (float)(aPSeq5->FUN_00508100() * DAT_0101de30));
            }
        }
    }

    if (this->FUN_004fd400()->GetAreaSound() && !silent)
    {
        unsigned int soundID3 = this->FUN_004fd400()->GetAreaSound()->GetFormID();
        ImpactHandle handleA = FUN_00453a70()->FUN_00ad73b0(soundID3, 0x102);
        NiPoint3 aEPos = *static_cast<const TESObjectREFR*>(this)->GetPos();
        handleA.FUN_00ad8b60(aEPos.x, aEPos.y, aEPos.z);
        handleA.FUN_00ad8830(false);
    }
}

struct NiRTTI;
extern NiRTTI DAT_011f36ac;
struct Val
{
    float FUN_004d50e0(int);
    unsigned int FUN_00559450();
};
struct Sub;
struct MyCtrl
{
    Sub* FUN_0047a520(void*);
    void FUN_0047b220(Sub*, float);
};
struct AVNode : public NiAVObject
{
    MyCtrl* FUN_00a5c570(NiRTTI*);
};
struct AVObj
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
    virtual AVNode* v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
};
struct Proc
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
    virtual void v437();
    virtual void v438();
    virtual void v439();
    virtual void v440();
    virtual void v441();
    virtual void v442();
    virtual void v443();
    virtual void v444();
    virtual void v445();
    virtual void v446();
    virtual void v447();
    virtual void v448();
    virtual void v449();
    virtual void v450();
    virtual void v451();
    virtual void v452();
    virtual void v453();
    virtual void v454();
    virtual void v455();
    virtual void v456();
    virtual void v457();
    virtual void v458();
    virtual void v459();
    virtual void v460();
    virtual void v461();
    virtual void v462();
    virtual void v463();
    virtual void v464();
    virtual void v465(int);
    virtual Val* v466();
    virtual void v467(int);
    virtual unsigned int v468();
};
unsigned int __fastcall FUN_00825c00(void* self);
void* __cdecl FUN_00935ef0();
void __cdecl SetSequenceProgress(float, MyCtrl*, Sub*);

struct Host
{
    int fld00;
    int fld01;
    int fld02;
    int fld03;
    int fld04;
    int fld05;
    int fld06;
    int fld07;
    int fld08;
    int fld09;
    int fld10;
    int fld11;
    int fld12;
    int fld13;
    int fld14;
    int fld15;
    int fld16;
    int fld17;
    int fld18;
    int fld19;
    int fld20;
    int fld21;
    int fld22;
    int fld23;
    int fld24;
    int fld25;
    int fld26;
    AVObj* m6c;
    bool FUN_00574900();
    Proc* FUN_008d8520();
    void FUN_00936b20(int);
};

// If active, finds the controller and sequence for the global time, advances the sequence by the elapsed time, and updates the node.
// @fnv 0x00936b20
void Host::FUN_00936b20(int aiUnused)
{
    if (FUN_00574900())
    {
        AVObj* pSceneObject = m6c;
        if (pSceneObject->v116())
        {
            MyCtrl* pkCtrl = pSceneObject->v116()->FUN_00a5c570(&DAT_011f36ac);
            if (pkCtrl)
            {
                Sub* pkSeq = pkCtrl->FUN_0047a520(FUN_00935ef0());
                if (pkSeq)
                {
                    unsigned int uiDiff = 0;
                    if (FUN_00825c00(&g_timeGlobal) > FUN_008d8520()->v468())
                        uiDiff = (FUN_00825c00(&g_timeGlobal) - FUN_008d8520()->v468()) / 33;
                    if (FUN_008d8520()->v466())
                    {
                        float fWeight = FUN_008d8520()->v466()->FUN_004d50e0(uiDiff);
                        if (fWeight < (double)0.01f)
                            fWeight = 0.01f;
                        SetSequenceProgress(fWeight, pkCtrl, pkSeq);
                        if (uiDiff > FUN_008d8520()->v466()->FUN_00559450())
                        {
                            SetSequenceProgress(0.0f, pkCtrl, pkSeq);
                            pkCtrl->FUN_0047b220(pkSeq, 0.0f);
                            FUN_008d8520()->v465(0);
                            FUN_008d8520()->v467(0);
                        }
                        else
                        {
                            SetSequenceProgress(fWeight, pkCtrl, pkSeq);
                        }
                    }
                }
            }
            m6c->v120();
            NiUpdateData uData((float)((double)FUN_00825c00(&g_timeGlobal) / 1000.0), true, false);
            pSceneObject->v116()->Update(uData);
        }
    }
}

unsigned int FUN_004873d0(BaseForm* pkForm);


// @fnv 0x005722c0
bool Actor::FUN_005722c0(int iUnused)
{
    bool bResult = false;
    if (IsActor() && FUN_0084e3a0() != 7)
    {
        float fValue = FUN_004873d0(FUN_007af430());
        if (fValue <= 0.0)
            bResult = true;
    }
    else if (FUN_00477ba0())
    {
        bResult = true;
    }
    return bResult;
}

#include <xmmintrin.h>
// Destruction of the reference and its transient physics/actor state.
extern int DAT_01085954, DAT_01085948;
extern int DAT_011dfc98;
struct __declspec(align(16)) CleanupVector
{
    __m128 components;
    void FUN_006815c0();
};
struct CleanupWorld
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
    virtual void GetAudioPosition(CleanupVector&);
};
struct CleanupCollision
{
    CleanupWorld* FUN_006fa820();
};
struct CleanupProcess
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
    virtual void RemoveReference(void*);
};
struct CleanupActor
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
    virtual bool IsActor();
    CleanupProcess* FUN_008d8520();
};
struct CleanupData
{
    int kind;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    CleanupActor* actor;
    void* worldHandle;
};
struct FUN_0092ec40
{
    virtual void Primary();
    int unk04, unk08, unk0c, unk10, unk14;
    ~FUN_0092ec40();
};
struct CleanupSecondary
{
    virtual void Secondary();
};
struct CleanupReference : FUN_0092ec40, CleanupSecondary
{
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84;
    CleanupData* data;
    int unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    bool detached;
    void* FUN_0043fcd0();
    void Set3D(void*, bool);
    void FUN_0092ed60(bool);
};
struct CleanupList
{
    void FUN_00905330(FUN_0092ec40* const&);
};
// Declarations missing from the shared queue; inherit its layout without copying it.
struct ActorDeletionQueueUnitMethods : ActorDeletionQueue_magicballprojectile
{
    CleanupList* GetOffset70Ptr();
    void FUN_0096e870(void*);
    void FUN_008d0600(int, int);
};
struct CleanupHandler
{
    bool FUN_004226e0();
};
extern CleanupHandler* DAT_011c3f2c;
void FUN_0062ab60(CleanupVector&, void*);
struct FUN_008cac60 : CleanupReference
{
    virtual ~FUN_008cac60();
};

// @fnv 0x008cac60
FUN_008cac60::~FUN_008cac60()
{
    --DAT_011dfc98;
    CleanupList* pCleanupList = static_cast<ActorDeletionQueueUnitMethods*>(&DAT_011e0e80)->GetOffset70Ptr();
    if (pCleanupList)
    {
        FUN_0092ec40* reference = this;
        pCleanupList->FUN_00905330(reference);
    }
    void* scene = FUN_0043fcd0();
    if (scene && data && data->kind == 1)
    {
        CleanupCollision* collision = reinterpret_cast<CleanupCollision*>(FUN_004b5260(scene));
        CleanupWorld* world = collision ? collision->FUN_006fa820() : 0;
        if (world)
        {
            CleanupVector audioVector;
            audioVector.FUN_006815c0();
            world->GetAudioPosition(audioVector);
            FUN_0062ab60(audioVector, data->worldHandle);
        }
    }
    if (!detached && data && data->kind == 0 && data->actor && data->actor->IsActor())
    {
        CleanupActor* actor = data->actor;
        if (actor && actor->FUN_008d8520())
        {
            CleanupProcess* process = actor->FUN_008d8520();
            process->RemoveReference(this);
        }
    }
    delete data;
    Set3D(0, true);
    if (!DAT_011c3f2c->FUN_004226e0())
        FUN_0092ed60(false);
}

namespace fnv_008112c0 {
struct EffB
{
    int FUN_0084e3a0();
};
struct EffA
{
    EffB* FUN_004fd3c0();
    EffB* FUN_004fd380();
};
struct Handle
{
    int h00;
    int h04;
    int h08;
    unsigned char FUN_00ad8ce0();
    void FUN_00ad8d10();
    void FUN_00418900(int);
};
struct V116
{
    void FUN_00440490(float);
    int FUN_0043b230();
};
struct C0Obj
{
    int c00;
    int c04;
    int c08;
    int c0c;
    int c10;
    int c14;
    int c18;
    C0Obj(int, void*);
    void FUN_0081c470(int, float);
    void FUN_00621b00(float);
};
struct Ret8d
{
    void FUN_00548230();
};
struct Obj30
{
    int o00;
    int o04;
    int o08;
    ~Obj30();
};
struct StrObj
{
    int s00;
    StrObj(const char*);
    ~StrObj();
};
struct Obj1c
{
    int FUN_0047a520(StrObj*);
};
struct Obj24
{
    float FUN_00508100();
};
void FUN_00401460(void*, void*, int);
void* FUN_00653270(void*, int);
extern int DAT_011f36ac;
extern double DAT_0101de30;

struct Cls8112c0
{
    virtual void virt_000();
    virtual void virt_001();
    virtual void virt_002();
    virtual void virt_003();
    virtual void virt_004();
    virtual void virt_005();
    virtual void virt_006();
    virtual void virt_007();
    virtual void virt_008();
    virtual void virt_009();
    virtual void virt_010();
    virtual void virt_011();
    virtual void virt_012();
    virtual void virt_013();
    virtual void virt_014();
    virtual void virt_015();
    virtual void virt_016();
    virtual void virt_017();
    virtual void virt_018();
    virtual void virt_019();
    virtual void virt_020();
    virtual void virt_021();
    virtual void virt_022();
    virtual void virt_023();
    virtual void virt_024();
    virtual void virt_025();
    virtual void virt_026();
    virtual void virt_027();
    virtual void virt_028();
    virtual void virt_029();
    virtual void virt_030();
    virtual void virt_031();
    virtual void virt_032();
    virtual void virt_033();
    virtual void virt_034();
    virtual void virt_035();
    virtual void virt_036();
    virtual void virt_037();
    virtual void virt_038();
    virtual void virt_039();
    virtual void virt_040();
    virtual void virt_041();
    virtual void virt_042();
    virtual void virt_043();
    virtual void virt_044();
    virtual void virt_045();
    virtual void virt_046();
    virtual void virt_047();
    virtual void virt_048();
    virtual void virt_049();
    virtual void virt_050();
    virtual void virt_051();
    virtual void virt_052();
    virtual void virt_053();
    virtual void virt_054();
    virtual void virt_055();
    virtual void virt_056();
    virtual void virt_057();
    virtual void virt_058();
    virtual void virt_059();
    virtual void virt_060();
    virtual void virt_061();
    virtual void virt_062();
    virtual void virt_063();
    virtual void virt_064();
    virtual void virt_065();
    virtual void virt_066();
    virtual void virt_067();
    virtual void virt_068();
    virtual void virt_069();
    virtual void virt_070();
    virtual void virt_071();
    virtual void virt_072();
    virtual void virt_073();
    virtual void virt_074();
    virtual void virt_075();
    virtual void virt_076();
    virtual void virt_077();
    virtual void virt_078();
    virtual void virt_079();
    virtual void virt_080();
    virtual void virt_081();
    virtual void virt_082();
    virtual void virt_083();
    virtual void virt_084();
    virtual void virt_085();
    virtual void virt_086();
    virtual void virt_087();
    virtual void virt_088();
    virtual void virt_089();
    virtual void virt_090();
    virtual void virt_091();
    virtual void virt_092();
    virtual void virt_093();
    virtual void virt_094();
    virtual void virt_095();
    virtual void virt_096();
    virtual void virt_097();
    virtual void virt_098();
    virtual void virt_099();
    virtual void virt_100();
    virtual void virt_101();
    virtual void virt_102();
    virtual void virt_103();
    virtual void virt_104();
    virtual void virt_105();
    virtual void virt_106();
    virtual void virt_107();
    virtual void virt_108();
    virtual void virt_109();
    virtual void virt_110();
    virtual void virt_111();
    virtual void virt_112();
    virtual void virt_113();
    virtual void virt_114();
    virtual void virt_115();
    virtual V116* virt_116();
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int m_ac;
    float m_b0;
    Handle m_b4;
    C0Obj* m_c0;
    void ResolveMagicReferences(int, int);
    void ResetProjectileIdleAnimation();
    Ret8d* FUN_008d6f30(Cls8112c0*, int);
    EffA* FUN_004fd400();
    Obj30 PlaySoundByFormID(int, int, int, int);
    void FUN_008112c0(int, int);
};

// Calls FUN_0081ea40 and FUN_0080fcf0, updates m_b4 from an Obj30 result, and may allocate C0Obj using the named SpecialIdle_AreaEffect entry.
// @fnv 0x008112c0
void Cls8112c0::FUN_008112c0(int aiParam1, int aiParam2)
{
    float f10;
    ResolveMagicReferences(aiParam1, aiParam2);
    ResetProjectileIdleAnimation();
    FUN_008d6f30(this, 0)->FUN_00548230();
    if (m_ac != 2)
    {
        if (FUN_004fd400()->FUN_004fd3c0())
        {
            int v14;
            v14 = FUN_004fd400()->FUN_004fd3c0()->FUN_0084e3a0();
            if (m_b4.FUN_00ad8ce0())
            {
                m_b4.FUN_00ad8d10();
            }
            {
                m_b4.FUN_00418900((int)&PlaySoundByFormID(v14, 1, 0x40000102, 1));
            }
        }
    }
    if (virt_116())
    {
        virt_116()->FUN_00440490(m_b0);
    }
    FUN_00401460(&f10, &m_c0, 4);
    m_c0 = 0;
    if (virt_116())
    {
        if (FUN_004fd400()->FUN_004fd380())
        {
            m_c0 = new C0Obj(FUN_004fd400()->FUN_004fd380()->FUN_0084e3a0(), virt_116());
            if (m_ac == 2 && m_c0 != 0)
            {
                V116* v20;
                int t18;
                Obj1c* foundEffect;
                int result;
                v20 = virt_116();
                t18 = v20 ? v20->FUN_0043b230() : 0;
                foundEffect = (Obj1c*)FUN_00653270(&DAT_011f36ac, t18);
                if (foundEffect)
                {
                    result = foundEffect->FUN_0047a520(&StrObj("SpecialIdle_AreaEffect"));
                    if (result)
                    {
                        m_c0->FUN_0081c470(0, ((Obj24*)result)->FUN_00508100() * DAT_0101de30);
                        m_c0->FUN_00621b00(f10);
                    }
                }
            }
        }
    }
}
}  // namespace fnv_008112c0

namespace fnv_008cb3c0 {

struct FloatMatrix3
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void FUN_00a59400(float*, float*, float*);
    void FUN_00a59660(float, float, float);
};
struct RefObject
{
    int FUN_0043fcd0();
    int FUN_008d6f30();
};
struct TrackedHandle
{
    int kind;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    RefObject* target;
};

struct PackageNodeHandler
{
    int FUN_0043c490();
    int FUN_0045bb80();
    void FUN_00440460(NiPoint3*);
    FloatMatrix3* FUN_006a9540();
    void FUN_0043fa80(FloatMatrix3*);
    void FUN_00a59c60(NiUpdateData*);
};
struct MotionController
{
    float GetFloatAtOffset53C();
    void FUN_008106b0(float);
};
struct SaveService
{
    void DetachProjectiles();
};
struct Clock
{
    const float* FUN_00403e20();
};
extern Clock DAT_011ce684;

extern const double DAT_01012060, DAT_01011588, DAT_01021928;
extern double __cdecl FUN_004587d0(float);
extern float __cdecl FUN_004b54c0(float);
extern void __cdecl FUN_00b6bb30(PackageNodeHandler*, float);

struct Controller
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
    virtual void v27(void*, int);
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
    virtual void v49(int);
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
    virtual struct PackageNodeHandler* v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* v125();
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
    virtual void v148(float, NiPoint3*, int);

    int unk4;
    int unk8;
    int unkc;
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
    TrackedHandle* handle;
    int phase;
    float fadeLeft, elapsed, velocity, acceleration, lifetime;
    int unkA4, unkA8, unkAC, unkB0;
    NiPoint3 lastDirection;
    unsigned char pending;
    unsigned char unkC1, unkC2, unkC3;
    void* releaseData;

    bool FUN_00440d80();
    MotionController* FUN_009306d0();
    void FUN_008ccfb0(int);
    bool ProcessImpact();
    int FUN_008d6f30();
    void FUN_00575830(int);
    void FUN_008cb3c0(float dt);
};

// Updates elapsed time, position, orientation, and fadeLeft, with phase-dependent calls to v27, v49, and other handlers.
// @fnv 0x008cb3c0
void Controller::FUN_008cb3c0(float afDelta)
{
    if (pending)
    {
        bool shouldRelease = true;
        if (handle && (handle->kind == 1 || handle->kind == 0) && handle->target)
        {
            if (!handle->target->FUN_0043fcd0())
            {
                shouldRelease = false;
            }
        }
        if (shouldRelease)
        {
            pending = 0;
            v27(releaseData, 0);
            reinterpret_cast<SaveService*>(DAT_011de45c)->DetachProjectiles();
        }
    }
    PackageNodeHandler* actor = v116();
    if (afDelta >= DAT_01012060)
    {
        elapsed = elapsed + afDelta;
        if (elapsed > *DAT_011ce684.FUN_00403e20())
        {
            phase = 3;
        }
        if (FUN_00440d80())
        {
            return;
        }
        if (phase == 0 && FUN_009306d0())
        {
            NiPoint3 delta_pos(0.0f, velocity * afDelta, 0.0f);
            NiPoint3 oldPosition = reinterpret_cast<const NiPoint3&>(*v125());
            if (FUN_004587d0(FUN_009306d0()->GetFloatAtOffset53C()) >= v125()->z)
            {
                float stepScale = (lifetime - 1.0f * afDelta) / lifetime;
                velocity = velocity * stepScale;
                acceleration = acceleration * stepScale;
                FUN_009306d0()->FUN_008106b0(stepScale);
                lifetime = lifetime - 1.0f * afDelta;
                if (lifetime < DAT_01011588)
                {
                    FUN_008ccfb0(0);
                    ProcessImpact();
                }
            }
            v148(afDelta, &delta_pos, 15);
            if (phase != 0)
            {
                int phase3 = (phase == 3) + 2;
                if (ProcessImpact())
                {
                    if (actor)
                    {
                        FUN_00575830(actor->FUN_0043c490());
                    }
                    phase = phase3;
                    return;
                }
            }
            NiPoint3 vPos = reinterpret_cast<const NiPoint3&>(*v125());
            if (actor)
            {
                actor->FUN_00440460(reinterpret_cast<NiPoint3*>(&vPos));
                FloatMatrix3 rot = *actor->FUN_006a9540();
                float roll, pitchNew, yawVal;
                rot.FUN_00a59400(&roll, &pitchNew, &yawVal);
                reinterpret_cast<NiPoint3&>(lastDirection) =
                    reinterpret_cast<NiPoint3&>(vPos) - reinterpret_cast<NiPoint3&>(oldPosition);
                float dirZ_ = lastDirection.z;
                float len = lastDirection.FUN_00457990();
                pitchNew = -FUN_004b54c0(dirZ_ / len);
                rot.FUN_00a59660(roll, pitchNew, yawVal);
                actor->FUN_0043fa80(&rot);
            }
        }
        else if (phase == 2 && handle)
        {
            int ref_kind = handle->kind;
            if (actor && ref_kind == 0)
            {
                FUN_00575830(actor->FUN_0045bb80());
                int refIndex = 0;
                if (handle->target)
                {
                    refIndex = handle->target->FUN_008d6f30();
                }
                if (refIndex != FUN_008d6f30())
                {
                    if (!refIndex)
                    {
                        v49(1);
                    }
                    else
                    {
                        static_cast<ActorDeletionQueueUnitMethods*>(&DAT_011e0e80)->FUN_0096e870(this);
                    }
                }
            }
            if (actor && ref_kind == 1 && (!handle || !handle->target || !handle->target->FUN_0043fcd0()))
            {
                v49(1);
            }
        }
        else if (phase == 3)
        {
            fadeLeft -= afDelta / DAT_01021928;
            if (fadeLeft <= DAT_01012060)
            {
                fadeLeft = 0.0f;
                v49(1);
            }
            if (actor)
            {
                FUN_00b6bb30(actor, fadeLeft);
            }
        }
    }
    if (actor)
    {
        NiUpdateData updateInfo(afDelta, 1, 0);
        actor->FUN_00a59c60(&updateInfo);
    }
}
}  // namespace fnv_008cb3c0

namespace fnv_009ae5d0 {
struct ItemA4
{
    int field0;
};

struct ListA4
{
    bool FUN_008256d0();
    ItemA4** FUN_006815c0();
};


struct FUN_004e3cc0_Class
{
    float GetFloatAtOffset9C();
};

struct FUN_009ae5d0_shell
{
    int unk00[36];
    float f90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    ListA4 listA4;
    int unka8[11];
    char padD4;
    bool bD5;
    char padD6[2];
    int unkd8;
    int unkdc;
    int unke0;
    int iE4;

    unsigned int GetFieldC8();
    float GetGoalZDelta();
    void UpdateMatchingActors();
    bool IsNotCulled();
    void FUN_009b13a0();
    void UpdateLightFade();
    float FUN_00507e10();
    FUN_004e3cc0_Class* GetActorBase();
    void FUN_009ac9a0();
    void FUN_009ae5d0(int a1);
};

// Checks iE4, goal Z delta, bD5, and actor-base values while conditionally calling four functions.
// @fnv 0x009ae5d0
void FUN_009ae5d0_shell::FUN_009ae5d0(int a1)
{
    if (iE4 == 0)
    {
        int val = 0;
        if (!listA4.FUN_008256d0())
        {
            val = (*listA4.FUN_006815c0())->field0;
        }
        static_cast<ActorDeletionQueueUnitMethods*>(&DAT_011e0e80)->FUN_008d0600(GetFieldC8(), val);
    }
    if (GetGoalZDelta() >= f90 && !bD5)
    {
        UpdateMatchingActors();
    }
    iE4 = iE4 + 1;
    if (!IsNotCulled())
    {
        FUN_009b13a0();
        UpdateLightFade();
    }
    if (GetGoalZDelta() > FUN_00507e10() && GetGoalZDelta() > GetActorBase()->GetFloatAtOffset9C())
    {
        FUN_009ac9a0();
    }
}
}  // namespace fnv_009ae5d0

struct DialogueActor;
struct DialogueProcess;
struct Animation
{
    void SpecialIdleFree(bool, bool);
};

struct DialogueProcess
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
    virtual void Start(DialogueActor*, int);
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
    virtual void* Active();
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
    virtual void Clear2(int);
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
    virtual void Clear(int);
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
    virtual void Partner(DialogueActor*);
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
    virtual void Reset(int);
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual DialogueActor* Find(int);
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
    virtual void v437();
    virtual void v438();
    virtual void v439();
    virtual void v440();
    virtual void v441();
    virtual void v442();
    virtual void v443();
    virtual void v444();
    virtual void v445();
    virtual void v446();
    virtual void v447();
    virtual void v448();
    virtual void v449();
    virtual void v450();
    virtual void v451();
    virtual void v452();
    virtual void Update(DialogueActor*);
};
struct DialogueActor
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
    virtual bool IsActor();
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
    virtual Animation* Anim();
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
    virtual TESPackage* Package();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void Cancel(int);
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
    DialogueActor* process;
    int unk6c;
    int unk70;
    float timer;
    int unk78;
    int unk7c;
    bool flag;
    DialogueProcess* GetCurrentProcess();
    TESPackage* GetCurrentPackage();
    bool Ready();
    DialogueActor* Ref();
    struct Extra* ExtraList();
    void FUN_00933d20();
};
struct Extra
{
    void Clear();
};
struct Save
{
    bool GetLoading();
    void DeleteForm(TESPackage*);
};
extern Save* saveState;
struct Handler
{
    bool Busy();
};
extern Handler* g_dataHandler;
struct Manager
{
    void Remove(DialogueActor*);
};
extern Manager manager;
extern ActorDeletionQueue_magicballprojectile actorQueue;
// Cancels the process; for package type 28, handles both participants, frees special idles, and deletes the dialogue package.
// @fnv 0x00933d20
void DialogueActor::FUN_00933d20()
{
    if (!process || saveState->GetLoading())
        return;
    process->Cancel(0);
    if (process->Package() && process->Package()->GetPackType() == 28)
    {
        DialoguePackage* dialogueB = dynamic_cast<DialoguePackage*>(process->Package());
        if (dialogueB)
        {
            if (reinterpret_cast<Sound*>(dialogueB->pad80)->FUN_00ad8ce0())
                dialogueB->Stop();
            DialogueActor* first7 = dialogueB->First();
            DialogueActor* second = dialogueB->Second();
            if (first7)
            {
                if (first7->IsActor())
                    manager.Remove(first7);
                first7->GetCurrentProcess()->Reset(1);
                first7->flag = true;
            }
            if (second)
            {
                if (second->IsActor())
                    manager.Remove(second);
                second->GetCurrentProcess()->Reset(1);
                second->flag = true;
            }
            if (first7 && second)
            {
                first7->GetCurrentProcess()->Partner(second);
                second->GetCurrentProcess()->Partner(first7);
                first7->timer = 1.0f;
                second->timer = 1.0f;
                first7->GetCurrentProcess()->Clear(0);
                second->GetCurrentProcess()->Clear(0);
            }
            Animation* animation6 = first7->Anim();
            if (animation6)
                animation6->SpecialIdleFree(true, false);
            animation6 = second->Anim();
            if (animation6)
                animation6->SpecialIdleFree(true, false);
            bool same9 = false;
            if (first7 && first7->GetCurrentProcess())
                first7->GetCurrentProcess()->Clear2(0);
            if (second && second->GetCurrentProcess())
                second->GetCurrentProcess()->Clear2(0);
            if (first7->GetCurrentPackage() == second->GetCurrentPackage())
                same9 = true;
            first7->GetCurrentProcess()->Update(first7);
            if (first7->IsActor() && !first7->GetCurrentProcess()->Active() && !g_dataHandler->Busy())
                first7->GetCurrentProcess()->Start(first7, 1);
            if (second && second->Ready() && second->GetCurrentProcess())
            {
                second->GetCurrentProcess()->Update(second);
                if (!g_dataHandler->Busy() && second->IsActor())
                    second->GetCurrentProcess()->Start(second, 1);
            }
            DialogueActor* target = dialogueB->Target();
            if (target)
            {
                DialogueActor* referenceA = target->Ref();
                referenceA->ExtraList()->Clear();
                target->Ref()->ExtraList()->Clear();
                actorQueue.FUN_0096d470(reinterpret_cast<MobileObject*>(target), 0);
                static_cast<ActorDeletionQueueUnitMethods*>(&actorQueue)->FUN_0096e870(target);
            }
            if (saveState->GetLoading())
                saveState->DeleteForm(dialogueB);
            else
                delete dialogueB;
        }
    }
    else
    {
        DialogueActor* partner2 = GetCurrentProcess()->Find(4);
        GetCurrentProcess()->Reset(1);
        GetCurrentProcess()->Partner(partner2);
        timer = 1.0f;
    }
}


struct Data88
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    TESObjectREFR* unk28;
};

// Calls FUN_00932490, resolves three form fields and unk88->unk28 through FUN_004839c0, then calls two functions on DAT_011e0e80.
// @fnv 0x008cf2c0
void MobileObject::FUN_008cf2c0(unsigned int auiArg1, unsigned int auiArg2)
{
    SetProcessFlags(auiArg1, auiArg2);
    // Legacy save-extension fields lie beyond the shared MobileObject base.
    unsigned int enchantment = (unsigned int)(*reinterpret_cast<Actor**>(reinterpret_cast<char*>(this) + 0xa4));
    if (enchantment)
        (*reinterpret_cast<Actor**>(reinterpret_cast<char*>(this) + 0xa4)) = dynamic_cast<Actor*>((TESForm*)FUN_004839c0(enchantment));
    unsigned int actor = (unsigned int)(*reinterpret_cast<EnchantmentItem**>(reinterpret_cast<char*>(this) + 0xa8));
    if (actor)
        (*reinterpret_cast<EnchantmentItem**>(reinterpret_cast<char*>(this) + 0xa8)) = dynamic_cast<EnchantmentItem*>((TESForm*)FUN_004839c0(actor));
    unsigned int alchemy = (unsigned int)(*reinterpret_cast<AlchemyItem**>(reinterpret_cast<char*>(this) + 0xb0));
    if (alchemy)
        (*reinterpret_cast<AlchemyItem**>(reinterpret_cast<char*>(this) + 0xb0)) = dynamic_cast<AlchemyItem*>((TESForm*)FUN_004839c0(alchemy));
    if ((*reinterpret_cast<Data88**>(reinterpret_cast<char*>(this) + 0x88)) && ((*reinterpret_cast<Data88**>(reinterpret_cast<char*>(this) + 0x88))->unk00 == 1 || (*reinterpret_cast<Data88**>(reinterpret_cast<char*>(this) + 0x88))->unk00 == 0))
    {
        unsigned int reference = (unsigned int)(*reinterpret_cast<Data88**>(reinterpret_cast<char*>(this) + 0x88))->unk28;
        if (reference)
            (*reinterpret_cast<Data88**>(reinterpret_cast<char*>(this) + 0x88))->unk28 = dynamic_cast<TESObjectREFR*>((TESForm*)FUN_004839c0(reference));
    }
    DAT_011e0e80.FUN_0096d470(this, FUN_00931850());
    DAT_011e0e80.FUN_0096d450(this, FUN_00931850(), false, false, false);
}

