
// src/fallout/ai/playercharacter_gf_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /Od /Oy- /GS /EHsc /Gy /GF (unit src/fallout/ai/playercharacter.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

#include "PlayerCharacter.h"

#include <xmmintrin.h>
extern float DAT_011e0768;
extern float DAT_011e07dc;
extern float DAT_011e0b5c;
extern unsigned char DAT_011e07c2;
extern unsigned char DAT_011e07c3;
extern unsigned char DAT_011e07b9;
extern unsigned char DAT_011e07b8;
extern float DAT_011a3b38;
extern unsigned char DAT_011a3b32;
extern NiPoint3 DAT_011e0808;
extern float DAT_0108b0a0f;
extern NiPoint3* DAT_011e07d0;
struct SettingShell
{
    float* __thiscall Setting_Float_00403e20();
};
extern SettingShell DAT_011ccfd8;
extern SettingShell DAT_011cda94;
extern SettingShell DAT_011cde14;
extern SettingShell DAT_011cdd60;
extern SettingShell DAT_011cd3d8;
extern SettingShell DAT_011cd288;
extern SettingShell DAT_011cd568;
extern SettingShell DAT_011e0934;
extern SettingShell DAT_011e0a84;
extern SettingShell DAT_011e09c8;
struct TimeShell
{
    float __thiscall FUN_0084d030();
};
extern TimeShell DAT_011f6394;
struct VecInit
{
    void __thiscall FUN_006815c0();
};
struct PtLen
{
    float __thiscall FUN_00457910();
};
struct StoreShell
{
    NiPoint3* __thiscall ComputeValue_0063c8a0(void* p);
};
struct __declspec(align(16)) BigObj
{
    __m128 position;
    __m128 normal;
    int unk20, unk24;
    unsigned int shapeKeysA[8];
    int unk48, unk4c;
    unsigned int shapeKeysB[8];
    void __thiscall ProcessAndReturnValue_00621c40();
};
struct PointSubtract
{
    void __thiscall Subtract(const NiPoint3&);
};
struct Field21c
{
    int __thiscall CameraCaster_GetWorld();
    void __thiscall CameraCaster_Add(int x);
    unsigned char __thiscall CameraCaster_Pick(NiPoint3* a, NiPoint3* b, BigObj* c);
    unsigned char __thiscall CameraCaster_KeepOutOfCharacter(void* o, NiPoint3* p, float a, float b);
};
struct Obj621ad0
{
    int __thiscall bhkCharacterController_GetWorld();
};
struct ModeShell
{
    int __thiscall FUN_0044ddc0();
};
struct TObjShell
{
    float __thiscall GetActorHeight();
};
struct ListShell
{
    void* __thiscall NiAVObject_GetWorldTranslate();
};
extern ModeShell DAT_011f2250;
bool __cdecl Interface_IsMenuIDVisible(int a, unsigned int b);
struct ThisShell
{
    int f_000;
    int f_004;
    int f_008;
    int f_00c;
    int f_010;
    int f_014;
    int f_018;
    int f_01c;
    int f_020;
    int f_024;
    int f_028;
    int f_02c;
    int f_030;
    int f_034;
    int f_038;
    int f_03c;
    int f_040;
    int f_044;
    int f_048;
    int f_04c;
    int f_050;
    int f_054;
    int f_058;
    int f_05c;
    int f_060;
    int f_064;
    int f_068;
    int f_06c;
    int f_070;
    int f_074;
    int f_078;
    int f_07c;
    int f_080;
    int f_084;
    int f_088;
    int f_08c;
    int f_090;
    int f_094;
    int f_098;
    int f_09c;
    int f_0a0;
    int f_0a4;
    int f_0a8;
    int f_0ac;
    int f_0b0;
    int f_0b4;
    int f_0b8;
    int f_0bc;
    int f_0c0;
    int f_0c4;
    int f_0c8;
    int f_0cc;
    int f_0d0;
    int f_0d4;
    int f_0d8;
    int f_0dc;
    int f_0e0;
    int f_0e4;
    int f_0e8;
    int f_0ec;
    int f_0f0;
    int f_0f4;
    int f_0f8;
    int f_0fc;
    int f_100;
    int f_104;
    int f_108;
    int f_10c;
    int f_110;
    int f_114;
    int f_118;
    int f_11c;
    int f_120;
    int f_124;
    int f_128;
    int f_12c;
    int f_130;
    int f_134;
    int f_138;
    int f_13c;
    int f_140;
    int f_144;
    int f_148;
    int f_14c;
    int f_150;
    int f_154;
    int f_158;
    int f_15c;
    int f_160;
    int f_164;
    int f_168;
    int f_16c;
    int f_170;
    int f_174;
    int f_178;
    int f_17c;
    int f_180;
    int f_184;
    int f_188;
    int f_18c;
    int f_190;
    int f_194;
    int f_198;
    int f_19c;
    int f_1a0;
    int f_1a4;
    int f_1a8;
    int f_1ac;
    int f_1b0;
    int f_1b4;
    int f_1b8;
    int f_1bc;
    int f_1c0;
    int f_1c4;
    int f_1c8;
    int f_1cc;
    int f_1d0;
    int f_1d4;
    int f_1d8;
    int f_1dc;
    int f_1e0;
    int f_1e4;
    int f_1e8;
    int f_1ec;
    int f_1f0;
    int f_1f4;
    int f_1f8;
    int f_1fc;
    int f_200;
    int f_204;
    int f_208;
    int f_20c;
    int f_210;
    int f_214;
    int f_218;
    Field21c* field21c;
    int f_220;
    int f_224;
    int f_228;
    int f_22c;
    int f_230;
    int f_234;
    int f_238;
    int f_23c;
    int f_240;
    int f_244;
    int f_248;
    int f_24c;
    int f_250;
    int f_254;
    int f_258;
    int f_25c;
    int f_260;
    int f_264;
    int f_268;
    int f_26c;
    int f_270;
    int f_274;
    int f_278;
    int f_27c;
    int f_280;
    int f_284;
    int f_288;
    int f_28c;
    int f_290;
    int f_294;
    int f_298;
    int f_29c;
    int f_2a0;
    int f_2a4;
    int f_2a8;
    int f_2ac;
    int f_2b0;
    int f_2b4;
    int f_2b8;
    int f_2bc;
    int f_2c0;
    int f_2c4;
    int f_2c8;
    int f_2cc;
    int f_2d0;
    int f_2d4;
    int f_2d8;
    int f_2dc;
    int f_2e0;
    int f_2e4;
    int f_2e8;
    int f_2ec;
    int f_2f0;
    int f_2f4;
    int f_2f8;
    int f_2fc;
    int f_300;
    int f_304;
    int f_308;
    int f_30c;
    int f_310;
    int f_314;
    int f_318;
    int f_31c;
    int f_320;
    int f_324;
    int f_328;
    int f_32c;
    int f_330;
    int f_334;
    int f_338;
    int f_33c;
    int f_340;
    int f_344;
    int f_348;
    int f_34c;
    int f_350;
    int f_354;
    int f_358;
    int f_35c;
    int f_360;
    int f_364;
    int f_368;
    int f_36c;
    int f_370;
    int f_374;
    int f_378;
    int f_37c;
    int f_380;
    int f_384;
    int f_388;
    int f_38c;
    int f_390;
    int f_394;
    int f_398;
    int f_39c;
    int f_3a0;
    int f_3a4;
    int f_3a8;
    int f_3ac;
    int f_3b0;
    int f_3b4;
    int f_3b8;
    int f_3bc;
    int f_3c0;
    int f_3c4;
    int f_3c8;
    int f_3cc;
    int f_3d0;
    int f_3d4;
    int f_3d8;
    int f_3dc;
    int f_3e0;
    int f_3e4;
    int f_3e8;
    int f_3ec;
    int f_3f0;
    int f_3f4;
    int f_3f8;
    int f_3fc;
    int f_400;
    int f_404;
    int f_408;
    int f_40c;
    int f_410;
    int f_414;
    int f_418;
    int f_41c;
    int f_420;
    int f_424;
    int f_428;
    int f_42c;
    int f_430;
    int f_434;
    int f_438;
    int f_43c;
    int f_440;
    int f_444;
    int f_448;
    int f_44c;
    int f_450;
    int f_454;
    int f_458;
    int f_45c;
    int f_460;
    int f_464;
    int f_468;
    int f_46c;
    int f_470;
    int f_474;
    int f_478;
    int f_47c;
    int f_480;
    int f_484;
    int f_488;
    int f_48c;
    int f_490;
    int f_494;
    int f_498;
    int f_49c;
    int f_4a0;
    int f_4a4;
    int f_4a8;
    int f_4ac;
    int f_4b0;
    int f_4b4;
    int f_4b8;
    int f_4bc;
    int f_4c0;
    int f_4c4;
    int f_4c8;
    int f_4cc;
    int f_4d0;
    int f_4d4;
    int f_4d8;
    int f_4dc;
    int f_4e0;
    int f_4e4;
    int f_4e8;
    int f_4ec;
    int f_4f0;
    int f_4f4;
    int f_4f8;
    int f_4fc;
    int f_500;
    int f_504;
    int f_508;
    int f_50c;
    int f_510;
    int f_514;
    int f_518;
    int f_51c;
    int f_520;
    int f_524;
    int f_528;
    int f_52c;
    int f_530;
    int f_534;
    int f_538;
    int f_53c;
    int f_540;
    int f_544;
    int f_548;
    int f_54c;
    int f_550;
    int f_554;
    int f_558;
    int f_55c;
    int f_560;
    int f_564;
    int f_568;
    int f_56c;
    int f_570;
    int f_574;
    int f_578;
    int f_57c;
    int f_580;
    int f_584;
    int f_588;
    int f_58c;
    int f_590;
    int f_594;
    int f_598;
    int f_59c;
    int f_5a0;
    int f_5a4;
    int f_5a8;
    int f_5ac;
    int f_5b0;
    int f_5b4;
    int f_5b8;
    int f_5bc;
    int f_5c0;
    int f_5c4;
    int f_5c8;
    int f_5cc;
    int f_5d0;
    int f_5d4;
    int f_5d8;
    int f_5dc;
    int f_5e0;
    int f_5e4;
    int f_5e8;
    int f_5ec;
    int f_5f0;
    int f_5f4;
    int f_5f8;
    int f_5fc;
    int f_600;
    int f_604;
    int f_608;
    int f_60c;
    int f_610;
    int f_614;
    int f_618;
    int f_61c;
    int f_620;
    int f_624;
    int f_628;
    int f_62c;
    int f_630;
    int f_634;
    int f_638;
    int f_63c;
    int f_640;
    int f_644;
    short f_648;
    unsigned char byte64a;
    unsigned char unk64b;
    bool bThirdPerson;
    unsigned char byte64d;
    void __thiscall PlayerCharacter_UpdateChaseCamera(NiPoint3* p1, NiPoint3* p2, unsigned char flag);
    void __thiscall FUN_008c4640();
    void* __thiscall FUN_009306d0();
};
// @fnv 0x0094a0c0
// src: XBOX_PDB 0x0094a0c0
void ThisShell::PlayerCharacter_UpdateChaseCamera(NiPoint3* p1, NiPoint3* p2, unsigned char flag)
{
    NiPoint3 vec;
    signed char state = (signed char)((unsigned char)bThirdPerson - byte64a);
    float f = 1.0f;
    if (state != 0)
    {
        if (flag || DAT_011e07c3)
            state = 0;
        else
            f = *DAT_011ccfd8.Setting_Float_00403e20() + ((DAT_011e0b5c - *DAT_011cda94.Setting_Float_00403e20()) /
                                                (*DAT_011cde14.Setting_Float_00403e20() - *DAT_011cda94.Setting_Float_00403e20())) *
                                                   *DAT_011cdd60.Setting_Float_00403e20();
    }
    if (flag || DAT_011e07c3)
    {
        vec = *p1;
        DAT_011e0808 = vec;
    }
    else
    {
        vec = *p1;
        if (DAT_011e07b9)
        {
            ((StoreShell*)&DAT_011e0808)
                ->ComputeValue_0063c8a0(&((vec - DAT_011e0808) * *DAT_011cd3d8.Setting_Float_00403e20() * DAT_011f6394.FUN_0084d030()));
            vec = DAT_011e0808;
        }
        else
            DAT_011e0808 = vec;
    }
    NiPoint3 v60 = vec - *p2;
    float len = ((PtLen*)&v60)->FUN_00457910();
    DAT_011e07c2 = 0;
    if (field21c)
    {
        NiPoint3 a70 = *p2;
        NiPoint3 a7c = vec;
        BigObj big;
        big.ProcessAndReturnValue_00621c40();
        if (field21c->CameraCaster_GetWorld() == 0)
        {
            int handle = FUN_009306d0() ? ((Obj621ad0*)FUN_009306d0())->bhkCharacterController_GetWorld() : 0;
            field21c->CameraCaster_Add(handle);
        }
        if (field21c->CameraCaster_Pick(&a70, &a7c, &big))
        {
            ((PointSubtract*)&a7c)->Subtract(a70);
            if (len - a7c.Length() > 2.0)
                DAT_011e07c2 = 1;
            len = a7c.Length() - *DAT_011e0934.Setting_Float_00403e20() * 0.5;
        }
    }
    float scaled = *DAT_011cd288.Setting_Float_00403e20() * DAT_011f6394.FUN_0084d030() * f;
    float lim = *DAT_011cd568.Setting_Float_00403e20();
    if (DAT_011e07b8)
        lim = *DAT_011cde14.Setting_Float_00403e20();
    if (state != 0)
    {
        if (state == 1 && len < DAT_011e0768 + state * scaled)
        {
            DAT_011e0768 = len;
            DAT_011e07dc = 0.0f;
            state = 0;
        }
        else
            DAT_011e0768 += state * scaled;
        if (DAT_011e0768 > lim)
        {
            DAT_011e0768 = lim;
            DAT_011e07dc = 0.0f;
            state = 0;
        }
        else if (DAT_011e0768 < 0.0)
        {
            DAT_011e0768 = 0.0f;
            DAT_011e07dc = 0.0f;
            state = 0;
        }
    }
    else if (flag || DAT_011e07c3)
    {
        DAT_011e0768 = len;
        DAT_011e07c3 = 0;
    }
    else
    {
        if (len <= DAT_011e0768)
            DAT_011e0768 = len;
        else if (len < DAT_011e0768 + scaled)
            DAT_011e0768 = len;
        else
            DAT_011e0768 += scaled;
        if (!DAT_011e07c2 && DAT_011e0768 < *DAT_011cda94.Setting_Float_00403e20())
            DAT_011e0768 = *DAT_011cda94.Setting_Float_00403e20();
        if (DAT_011e0768 > lim)
            DAT_011e0768 = lim;
    }
    NiPoint3 v128 = *p2 + v60 * DAT_011e0768;
    bool ok = false;
    if (state != 0 || DAT_011f2250.FUN_0044ddc0() == 4)
    {
        if (state < 0)
        {
            if (DAT_011e0768 < *DAT_011e0a84.Setting_Float_00403e20())
            {
                DAT_011e0768 = 0.0f;
                DAT_011e07dc = 0.0f;
                state = 0;
            }
        }
        else if (DAT_011e0768 < *DAT_011e0a84.Setting_Float_00403e20())
            DAT_011e0768 = *DAT_011e0a84.Setting_Float_00403e20();
    }
    else if (!Interface_IsMenuIDVisible(0x40c, 0) && DAT_011f2250.FUN_0044ddc0() != 4)
    {
        void* o = FUN_009306d0();
        float ft = ((TObjShell*)this)->GetActorHeight() - 124.0;
        if (field21c->CameraCaster_KeepOutOfCharacter(o, &v128, *DAT_011e09c8.Setting_Float_00403e20(), ft))
            ok = true;
    }
    if (ok && !byte64d)
    {
        if (DAT_011a3b38 > 0.0 && !DAT_011a3b32)
        {
            DAT_011a3b38 -= DAT_011f6394.FUN_0084d030() * 4.0;
            if (DAT_011a3b38 < 0.0)
                DAT_011a3b38 = 0.0f;
            FUN_008c4640();
        }
    }
    else
    {
        if (DAT_011a3b38 < 1.0)
        {
            DAT_011a3b38 += DAT_011f6394.FUN_0084d030() * 4.0;
            if (DAT_011a3b38 > 1.0 || (state != 0 || DAT_011f2250.FUN_0044ddc0() == 4))
                DAT_011a3b38 = 1.0f;
            FUN_008c4640();
        }
        DAT_011a3b32 = 0;
    }
    NiPoint3 v14c = *p2 + v60 * DAT_011e0768;
    if (state != 0)
    {
        NiPoint3 v158 = *p1 - v14c;
        DAT_011e07dc = v158.Length() / DAT_011f6394.FUN_0084d030();
        if (state == -1)
        {
            NiPoint3 v16c = *p1 - *(NiPoint3*)((ListShell*)DAT_011e07d0)->NiAVObject_GetWorldTranslate();
            if (v158.Length() >= v16c.Length())
            {
                DAT_011e07dc = 0.0f;
                DAT_011e0768 = 0.0f;
            }
        }
    }
    *p1 = v14c;
}
