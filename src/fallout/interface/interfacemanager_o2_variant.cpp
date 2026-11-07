
// src/fallout/interface/interfacemanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/interface/interfacemanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../include/NiRenderer.h"
#include "../../../include/NiDX9Renderer.h"

extern "C" __declspec(dllimport) unsigned int __stdcall XInputGetState(unsigned int dwUserIndex, void* pState);

// @fnv 0x009f996e
// src: COMMUNITY 0x009f996e
unsigned int __stdcall XInputGetState_009f996e(unsigned int dwUserIndex, void* pState)
{
    return XInputGetState(dwUserIndex, pState);
}

void BSRenderState_RestoreZEnable(int);
void BSRenderState_RestoreZWriteEnable(int);
void BSRenderState_RestoreZFunc(int);
void BSRenderState_RestoreAlphaTestEnable(int);
void BSRenderState_RestoreAlphaTestFuncRef(int);
void BSRenderState_RestoreAlphaBlendEnable(int);
void BSRenderState_RestoreAlphaBlendFunc(int);
void BSRenderState_RestoreStencilAction(int);
void BSRenderState_RestoreStencilFunc(int);
void BSRenderState_RestoreStencilWriteMask(int);
void BSRenderState_RestoreDepthBias(int);
void BSRenderState_RestoreColorWrites(int);
void BSRenderState_RestoreUserClipPlaneEnables(int);
void BSRenderState_RestoreStencilEnable(unsigned int);
void BSRenderState_RestoreColorWriteEnable(unsigned int);

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
// src: COMMUNITY 0x00b98610
void BSRenderState_RestoreState(int state, int value)
{
    switch (state)
    {
    case 7:
        BSRenderState_RestoreZEnable(value);
        break;
    case 14:
        BSRenderState_RestoreZWriteEnable(value);
        break;
    case 23:
        BSRenderState_RestoreZFunc(value);
        break;
    case 15:
        BSRenderState_RestoreAlphaTestEnable(value);
        break;
    case 25:
        BSRenderState_RestoreAlphaTestFuncRef(value);
        break;
    case 24:
        BSRenderState_RestoreAlphaTestFuncRef(value);
        break;
    case 27:
        BSRenderState_RestoreAlphaBlendEnable(value);
        break;
    case 19:
        BSRenderState_RestoreAlphaBlendFunc(value);
        break;
    case 20:
        BSRenderState_RestoreAlphaBlendFunc(value);
        break;
    case 168:
        BSRenderState_RestoreColorWriteEnable(value);
        break;
    case 190:
        BSRenderState_RestoreColorWrites(value);
        break;
    case 52:
        BSRenderState_RestoreStencilEnable(value);
        break;
    case 59:
        BSRenderState_RestoreStencilWriteMask(value);
        break;
    case 152:
        BSRenderState_RestoreUserClipPlaneEnables(value);
        break;
    case 53:
        BSRenderState_RestoreStencilAction(value);
        break;
    case 54:
        BSRenderState_RestoreStencilAction(value);
        break;
    case 55:
        BSRenderState_RestoreStencilAction(value);
        break;
    case 56:
        BSRenderState_RestoreStencilFunc(value);
        break;
    case 57:
        BSRenderState_RestoreStencilFunc(value);
        break;
    case 58:
        BSRenderState_RestoreStencilFunc(value);
        break;
    case 195:
        BSRenderState_RestoreDepthBias(value);
        break;
    default:
        RenderStateManager* manager = reinterpret_cast<RenderStateManager*>(static_cast<NiDX9Renderer*>(DAT_011f9508)->pRenderState);
        manager->SetRenderState(state, manager->states[state].savedValue, 0, 0);
        break;
    }
}
