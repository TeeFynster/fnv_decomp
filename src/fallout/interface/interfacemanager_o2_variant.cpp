
// src/fallout/interface/interfacemanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/interface/interfacemanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../include/NiRenderer.h"
#include "../../../include/NiDX9Renderer.h"

extern "C" __declspec(dllimport) unsigned int __stdcall XInputGetState(unsigned int dwUserIndex, void* pState);

// @fnv 0x009f996e
unsigned int __stdcall FUN_009f996e(unsigned int dwUserIndex, void* pState)
{
    return XInputGetState(dwUserIndex, pState);
}

void FUN_00714a40(int);
void FUN_00714a60(int);
void FUN_00714a80(int);
void FUN_00714aa0(int);
void FUN_00714ac0(int);
void FUN_00714ae0(int);
void FUN_00714b00(int);
void FUN_00714b20(int);
void FUN_00714b50(int);
void FUN_00714b80(int);
void FUN_00714bf0(int);
void FUN_00b985f0(int);
void FUN_004eb510(int);
void FUN_004ecb40(unsigned int);
void FUN_004eced0(unsigned int);

struct RenderStateEntry
{
    unsigned int savedValue;
    unsigned int currentValue;
};
class RenderStateManager
{
  public:
    virtual void UnknownVirtual00();
    virtual void UnknownVirtual01();
    virtual void UnknownVirtual02();
    virtual void UnknownVirtual03();
    virtual void UnknownVirtual04();
    virtual void UnknownVirtual05();
    virtual void UnknownVirtual06();
    virtual void UnknownVirtual07();
    virtual void UnknownVirtual08();
    virtual void UnknownVirtual09();
    virtual void UnknownVirtual10();
    virtual void UnknownVirtual11();
    virtual void UnknownVirtual12();
    virtual void UnknownVirtual13();
    virtual void UnknownVirtual14();
    virtual void UnknownVirtual15();
    virtual void UnknownVirtual16();
    virtual void UnknownVirtual17();
    virtual void UnknownVirtual18();
    virtual void UnknownVirtual19();
    virtual void UnknownVirtual20();
    virtual void UnknownVirtual21();
    virtual void UnknownVirtual22();
    virtual void UnknownVirtual23();
    virtual void UnknownVirtual24();
    virtual void UnknownVirtual25();
    virtual void SetRenderState(int state, unsigned int value, int option1, int option2);
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
    RenderStateEntry states[256];
};

extern NiRenderer* DAT_011f9508;

// @fnv 0x00b98610
void FUN_00b98610(int state, int value)
{
    switch (state)
    {
    case 7:
        FUN_00714a40(value);
        break;
    case 14:
        FUN_00714a60(value);
        break;
    case 23:
        FUN_00714a80(value);
        break;
    case 15:
        FUN_00714aa0(value);
        break;
    case 25:
        FUN_00714ac0(value);
        break;
    case 24:
        FUN_00714ac0(value);
        break;
    case 27:
        FUN_00714ae0(value);
        break;
    case 19:
        FUN_00714b00(value);
        break;
    case 20:
        FUN_00714b00(value);
        break;
    case 168:
        FUN_004eced0(value);
        break;
    case 190:
        FUN_00b985f0(value);
        break;
    case 52:
        FUN_004ecb40(value);
        break;
    case 59:
        FUN_00714b80(value);
        break;
    case 152:
        FUN_004eb510(value);
        break;
    case 53:
        FUN_00714b20(value);
        break;
    case 54:
        FUN_00714b20(value);
        break;
    case 55:
        FUN_00714b20(value);
        break;
    case 56:
        FUN_00714b50(value);
        break;
    case 57:
        FUN_00714b50(value);
        break;
    case 58:
        FUN_00714b50(value);
        break;
    case 195:
        FUN_00714bf0(value);
        break;
    default:
        RenderStateManager* manager = reinterpret_cast<RenderStateManager*>(static_cast<NiDX9Renderer*>(DAT_011f9508)->pRenderState);
        manager->SetRenderState(state, manager->states[state].savedValue, 0, 0);
        break;
    }
}
