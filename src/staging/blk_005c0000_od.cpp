
// src/staging/blk_005c0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/BGSProjectile.h"
#include "../../include/EffectSetting.h"
#include "../../include/Reset3DMobIterator.h"

struct FUN_005c1ae0_class
{
    void CombatController_ForceStopCombat();
};

// @fnv 0x005c1ae0
// src: XBOX_PDB 0x005c1ae0
void FUN_005c1ae0_class::CombatController_ForceStopCombat()
{
    *reinterpret_cast<char*>(this + 0x125) = 1;
}

extern "C" void* __cdecl GetObjectScale(void* a, void* b, void* c, void* d);

// @fnv 0x005c1b60
void* __cdecl CallWithZeroedArgs(void* apArg1, void* apArg2, void* apArg3, void* apArg4, void* apArg5, void* apArg6,
                                 void* apArg7)
{
    return GetObjectScale(apArg3, 0, 0, apArg7);
}

extern int g_TES;
extern unsigned char DAT_011c7a64;
unsigned char __cdecl TESWaterSystem_GetWaterEnabled(void);
// @fnv 0x005d2a50
// src: EXE 0x005d2a50
unsigned char Cmd_ToggleWaterRadius_Execute()
{
    ((EffectSetting*)g_TES)->GetEffectID();
    if (TESWaterSystem_GetWaterEnabled())
        DAT_011c7a64 = 1;
    return 1;
}

// @fnv 0x005d8af0
Reset3DMobIterator::Reset3DMobIterator()
{
}

extern "C" float __cdecl _logf(float);

// @fnv 0x005dc330
float __cdecl LogFloat(float value)
{
    return _logf(value);
}

float _logf_005dc460(float);
// @fnv 0x005dc440
// src: COMMUNITY 0x005dc440
float log_005dc440(float value)
{
    return _logf_005dc460(value);
}

extern "C" double __cdecl FUN_00eca920(double);

// @fnv 0x005dc460
// src: COMMUNITY 0x005dc460
float _logf_005dc460(float value)
{
    return static_cast<float>(FUN_00eca920(value));
}

struct FUN_005dd520_class
{
    void SetByteAtOffsetD4(char v);
};

// @fnv 0x005dd520
void FUN_005dd520_class::SetByteAtOffsetD4(char acValue)
{
    *(char*)((char*)this + 0xd4) = acValue;
}

struct FUN_005dd540_Class
{
    void SetByteAtOffsetE3(unsigned char value);
};

// @fnv 0x005dd540
void FUN_005dd540_Class::SetByteAtOffsetE3(unsigned char value)
{
    *(unsigned char*)((char*)this + 0xe3) = value;
}

// @fnv 0x005de080
// src: XBOX_PDB 0x005de080
bool BGSProjectile::GetHasExplosionDetonates_005de080()
{
    return GetFlag(0x400);
}

struct Tgt
{
    virtual void t00();
    virtual void t01();
    virtual void t02();
    virtual void t03();
    virtual void t04();
    virtual void t05();
    virtual void t06();
    virtual void t07();
    virtual void t08();
    virtual void t09();
    virtual void t0a();
    virtual void t0b();
    virtual void t0c();
    virtual void t0d();
    virtual void t0e();
    virtual void t0f();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual void t13();
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void t17();
    virtual void t18();
    virtual void t19();
    virtual void t1a();
    virtual void t1b();
    virtual void t1c();
    virtual void t1d();
    virtual void t1e();
    virtual void t1f();
    virtual void t20();
    virtual void t21();
    virtual void t22();
    virtual void t23();
    virtual void t24();
    virtual void t25();
    virtual void t26();
    virtual void t27();
    virtual void t28();
    virtual void t29();
    virtual void t2a();
    virtual void t2b();
    virtual void t2c();
    virtual void t2d();
    virtual void t2e();
    virtual void t2f();
    virtual void t30();
    virtual void t31();
    virtual void t32();
    virtual void t33();
    virtual void t34();
    virtual void t35();
    virtual void t36();
    virtual void t37();
    virtual void t38();
    virtual void t39();
    virtual void t3a();
    virtual void t3b();
    virtual void t3c();
    virtual void t3d();
    virtual void t3e();
    virtual void t3f();
    virtual void t40();
    virtual void t41();
    virtual void t42();
    virtual void t43();
    virtual void t44();
    virtual void t45();
    virtual void t46();
    virtual void t47();
    virtual void t48();
    virtual void t49();
    virtual void t4a();
    virtual void t4b();
    virtual void t4c();
    virtual void t4d();
    virtual void t4e();
    virtual void t4f();
    virtual void t50();
    virtual void t51();
    virtual void t52();
    virtual void t53();
    virtual void t54();
    virtual void t55();
    virtual void t56();
    virtual void t57();
    virtual void t58();
    virtual void t59();
    virtual void t5a();
    virtual void t5b();
    virtual void t5c();
    virtual void t5d();
    virtual void t5e();
    virtual void t5f();
    virtual void t60();
    virtual void t61();
    virtual void t62();
    virtual void t63();
    virtual void t64();
    virtual void t65();
    virtual void t66();
    virtual void t67();
    virtual void t68();
    virtual void t69();
    virtual void t6a();
    virtual void t6b();
    virtual void t6c();
    virtual void t6d();
    virtual void t6e();
    virtual void t6f();
    virtual void t70();
    virtual void t71();
    virtual void t72();
    virtual void t73();
    virtual void t74();
    virtual void t75();
    virtual void t76();
    virtual void t77();
    virtual void t78();
    virtual void t79();
    virtual void t7a();
    virtual void t7b();
    virtual void t7c();
    virtual void t7d();
    virtual void t7e();
    virtual void t7f();
    virtual void t80();
    virtual void t81();
    virtual void t82();
    virtual void t83();
    virtual void t84();
    virtual void t85();
    virtual void t86();
    virtual void t87();
    virtual void t88();
    virtual void t89();
    virtual void t8a();
    virtual void t8b();
    virtual void t8c();
    virtual void t8d();
    virtual void t8e();
    virtual void t8f();
    virtual void t90();
    virtual void t91();
    virtual void t92();
    virtual void t93();
    virtual void t94();
    virtual void t95();
    virtual void t96();
    virtual void t97();
    virtual void t98();
    virtual void t99();
    virtual void t9a();
    virtual void t9b();
    virtual void t9c();
    virtual void t9d();
    virtual void t9e();
    virtual void t9f();
    virtual void ta0();
    virtual void ta1();
    virtual void ta2();
    virtual void ta3();
    virtual void ta4();
    virtual void ta5();
    virtual void ta6();
    virtual void ta7();
    virtual void ta8();
    virtual void ta9();
    virtual void taa();
    virtual void tab();
    virtual void tac();
    virtual void tad();
    virtual void tae();
    virtual void taf();
    virtual void tb0();
    virtual void tb1();
    virtual void tb2();
    virtual void tb3();
    virtual void tb4();
    virtual void tb5();
    virtual void tb6();
    virtual void tb7();
    virtual void tb8();
    virtual void tb9();
    virtual void tba();
    virtual void tbb();
    virtual void tbc();
    virtual void tbd();
    virtual void tbe();
    virtual void tbf();
    virtual void tc0();
    virtual void tc1();
    virtual void tc2();
    virtual void tc3();
    virtual void Act(int a);
};
struct Res
{
    void Fin();
};
struct Src
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s0a();
    virtual void s0b();
    virtual void s0c();
    virtual void s0d();
    virtual void s0e();
    virtual void s0f();
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
    virtual void s1a();
    virtual void s1b();
    virtual void s1c();
    virtual void s1d();
    virtual void s1e();
    virtual void s1f();
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
    virtual void s2a();
    virtual void s2b();
    virtual void s2c();
    virtual void s2d();
    virtual void s2e();
    virtual void s2f();
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
    virtual void s3a();
    virtual void s3b();
    virtual void s3c();
    virtual void s3d();
    virtual void s3e();
    virtual void s3f();
    virtual unsigned char Test();
    Res* Pick(int id);
};
struct Mid
{
    Tgt* Get();
};
struct Me
{
    void MobDialogueFlagResetter_Operate(Src* p);
};
// @fnv 0x005d8a90
// src: COMMUNITY 0x005d8a90
void Me::MobDialogueFlagResetter_Operate(Src* pSource)
{
    if (pSource->Test())
    {
        Mid* pMid = (Mid*)pSource;
        if (Tgt* pTgt = pMid->Get())
            pTgt->Act(0);
    }
    pSource->Pick(0x73)->Fin();
}
