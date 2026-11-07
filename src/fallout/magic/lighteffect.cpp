#include "../../../include/SettingT.h"
#include "../../../include/LightEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/GameSettingCollection.h"
#include "../../../include/NiAdditionalGeometryData.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiPointLight.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/ShadowSceneNode.h"
#include "../../../include/TESObjectLIGH.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/MagicTarget.h"

// src/fallout/magic/lighteffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/lighteffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_0080ed20_shell
{
    float f0;
    float f1;
    float f2;
    FUN_0080ed20_shell* DivideByScalar(float divisor);
};

// Divides the three float components f0, f1 and f2 by divisor in place and returns this.
// @fnv 0x0080ed20
FUN_0080ed20_shell* FUN_0080ed20_shell::DivideByScalar(float divisor)
{
    f0 /= divisor;
    f1 /= divisor;
    f2 /= divisor;
    return this;
}

// @fnv 0x0080f030
void LightEffect::Revert(Actor* apActor)
{
    ActiveEffect::Revert(apActor);
    DetachLight();
}

// Constructs a light effect with no attached light.
// @fnv 0x0080e610
LightEffect::LightEffect(void* caster, void* item, void* effect)
    : ActiveEffect((MagicCaster*)caster, (MagicItem*)item, (EffectItem*)effect), m_spLight(0)
{
    m_spLight = 0;
}

// The constructor must emit its vtable store; the destructor must omit it.
// Apply novtable after the constructor to preserve both original code paths.
class __declspec(novtable) LightEffect;

// @fnv 0x0080e6d0
LightEffect::~LightEffect()
{}

// The shared ShadowSceneNode declaration does not expose this lookup.
extern "C" void FindExistingShadowSceneLight();
// @fnv 0x0080e8a0
void LightEffect::Update(float afSecondsElapsed)
{
    ShadowSceneNode* pnode;
    if ((NiPointLight*)m_spLight)
    {
        pnode = NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0);
        if (pnode)
        {
            if (!((int (__thiscall*)(ShadowSceneNode*, NiPointLight*))FindExistingShadowSceneLight)(pnode, m_spLight))
            {
                pnode->GetShadowSceneLight((NiLight*)(NiPointLight*)m_spLight, true);
            }
        }
    }
}

// @fnv 0x0080efd0
void LightEffect::FinishLoadGameTES(Actor* apActor)
{
    ActiveEffect::FinishLoadGameTES(apActor);
    Start();
}

// @fnv 0x0080f000
void LightEffect::ApplyLoadBuffer(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ActiveEffect::ApplyLoadBuffer(apLoadGameBuffer);
    Start();
}

// @fnv 0x0080e730
ActiveEffect* LightEffect::Copy()
{
    ActiveEffect* presult = new LightEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(presult);
    return presult;
}

// @fnv 0x0080ef50
LightEffect* CreateLightEffect(void* caster, void* item, void* effect)
{
    return new LightEffect(caster, item, effect);
}

// @fnv 0x0080e7e0
void LightEffect::CopyData(ActiveEffect* other)
{
    ActiveEffect::CopyData(other);
    LightEffect* effect = dynamic_cast<LightEffect*>(other);
    if (effect)
    {
        effect->m_spLight = m_spLight;
    }
}

struct Effect
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
    int unk88;
    int unk8c;
    int unk90;
    int field94;
};
void __cdecl LightEffect_AttachBestLightEffect(int* value);
// Gets an Effect via FUN_0059bb30()->FUN_00822b40() and, if non-null, passes its field94 to FUN_0080ee50.
// @fnv 0x0080e830
void LightEffect::Start()
{
    Effect* effect = FUN_0059bb30() ? (Effect*)FUN_0059bb30()->FUN_00822b40() : 0;
    if (effect)
        LightEffect_AttachBestLightEffect(effect ? &effect->field94 : 0);
}

void __cdecl LightEffect_AttachBestLightEffect(char* p);

// @fnv 0x0080e900
void LightEffect::Finish()
{
    DetachLight();
    char* a = FUN_0059bb30() != 0 ? (char*)FUN_0059bb30()->FUN_00822b40() : 0;
    if (a != 0)
    {
        LightEffect_AttachBestLightEffect(a != 0 ? a + 0x94 : 0);
    }
}

extern int DAT_011dc304;

struct EdCallee
{
    void* NiAVObject_GetParent();
    void ShadowSceneNode_RemoveLight(void* apArg);
    void TESObjectREFR_KillLight(int aiArg);
};

void* __cdecl FUN_00450b80(int aiArg);

typedef void(__thiscall* EdVirtual)(void* self, void* apArg);

// @fnv 0x0080ed60
// src: XBOX_PDB 0x0080ed60
void LightEffect::DetachLight()
{
    void* pActor2;
    void* pTmp;
    void* pObj;
    pActor2 = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;

    if ((NiPointLight*)m_spLight != 0)
    {
        pTmp = FUN_00450b80(0);
        if (pTmp != 0)
        {
            ((EdCallee*)pTmp)->ShadowSceneNode_RemoveLight((NiPointLight*)m_spLight);
        }
        pObj = ((EdCallee*)(NiPointLight*)m_spLight)->NiAVObject_GetParent();
        if (pObj != 0)
        {
            ((EdVirtual)(*(void***)pObj)[58])(pObj, (NiPointLight*)m_spLight);
        }
        if (pActor2 != 0)
        {
            ((EdCallee*)pActor2)->TESObjectREFR_KillLight(1);
        }
        m_spLight = 0;
        DAT_011dc304 = DAT_011dc304 - 1;
        if (DAT_011dc304 < 0)
        {
            DAT_011dc304 = 0;
        }
    }
}

// These two actor light accessors are absent from the shared declaration.
extern "C" void GetActorEffectLight();
extern "C" void SetActorEffectLight();

// Shared TESObjectREFR::Unk_77 has a void return type, but this call requires
// a NiPoint3 returned through the x86 hidden result buffer. Keep this local
// virtual interface until the shared declaration exposes that signature.
struct ActorLightPositionView
{
    virtual void Reserved00();
    virtual void Reserved01();
    virtual void Reserved02();
    virtual void Reserved03();
    virtual void Reserved04();
    virtual void Reserved05();
    virtual void Reserved06();
    virtual void Reserved07();
    virtual void Reserved08();
    virtual void Reserved09();
    virtual void Reserved0A();
    virtual void Reserved0B();
    virtual void Reserved0C();
    virtual void Reserved0D();
    virtual void Reserved0E();
    virtual void Reserved0F();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved1A();
    virtual void Reserved1B();
    virtual void Reserved1C();
    virtual void Reserved1D();
    virtual void Reserved1E();
    virtual void Reserved1F();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved2A();
    virtual void Reserved2B();
    virtual void Reserved2C();
    virtual void Reserved2D();
    virtual void Reserved2E();
    virtual void Reserved2F();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved3A();
    virtual void Reserved3B();
    virtual void Reserved3C();
    virtual void Reserved3D();
    virtual void Reserved3E();
    virtual void Reserved3F();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved4A();
    virtual void Reserved4B();
    virtual void Reserved4C();
    virtual void Reserved4D();
    virtual void Reserved4E();
    virtual void Reserved4F();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved5A();
    virtual void Reserved5B();
    virtual void Reserved5C();
    virtual void Reserved5D();
    virtual void Reserved5E();
    virtual void Reserved5F();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual void Reserved64();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved6A();
    virtual void Reserved6B();
    virtual void Reserved6C();
    virtual void Reserved6D();
    virtual void Reserved6E();
    virtual void Reserved6F();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual void Reserved76();
    virtual NiPoint3 GetLightPosition();
};

extern PlayerCharacter* _g_thePlayer;

class GlobalObject2_0040c150
{
  public:
    int* Int();
};
extern GlobalObject2_0040c150 g_011d1d18;

class GlobalObject_0040e0b0
{
  public:
    float* Float();
};
extern GlobalObject_0040e0b0 g_011d1980;
extern GlobalObject_0040e0b0 g_011d1a30;

using ::SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1112;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1166;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1167;

void FNV_Warning(const char* fmt, ...);

struct FUN_005e3fc0_shell
{
    unsigned int Get();
};

// @fnv 0x0080e970
void LightEffect::AttachLightEffect()
{
    Actor* pTarget3 = this->FUN_0059bb30() ? this->FUN_0059bb30()->FUN_00822b40() : 0;
    if (!this->m_spLight && pTarget3 && !((int (__thiscall*)(Actor*))GetActorEffectLight)(pTarget3) && DAT_011dc304 <= *g_011d1d18.Int())
    {
        TESObjectLIGH* pLightTmp = GetEffectSetting()->GetLight();
        if (!pLightTmp)
        {
            FNV_Warning(
                "EDITOR: Light Effect has no Light object associated with it. Use the editor to select a light in the Magic Effects window for the Light effect.");
            return;
        }

        this->m_spLight = new NiPointLight();

        unsigned int color4 = ((FUN_005e3fc0_shell*)pLightTmp)->Get();
        NiPoint3 colorPoint4((float)(unsigned char)(color4 & 0xff),
                             (float)(unsigned char)(((unsigned short)color4 >> 8) & 0xff),
                             (float)(unsigned char)((color4 >> 16) & 0xff));
        ((FUN_0080ed20_shell*)&colorPoint4)->DivideByScalar(255.0f);
        this->m_spLight->SetEffectColor(colorPoint4);

        float fValX = (*g_011d1980.Float() + this->GetFloatAtOffset1C()) * *originalRuntimeFloatSetting1112.Float();
        NiPoint3 offsetPoint5(fValX, 0.0f, 0.0f);
        this->m_spLight->FUN_0050dd50(offsetPoint5);

        this->m_spLight->NiLight_SetDimmer(((PathingRequest*)pLightTmp)->GetFieldB4Float());

        ShadowSceneNode* aPScene = (ShadowSceneNode*)FUN_00450b80(0);
        if (aPScene)
        {
            aPScene->GetShadowSceneLight((NiLight*)(NiPointLight*)this->m_spLight, true);
        }

        float fX = *g_011d1a30.Float() * pTarget3->TESObjectREFR_GetScale_00567400();

        float fY = (((ActorLightPositionView*)pTarget3)->GetLightPosition().y + *originalRuntimeFloatSetting1166.Float()) *
                   pTarget3->TESObjectREFR_GetScale_00567400();
        float fZ = pTarget3->GetActorHeight() +
                   *originalRuntimeFloatSetting1167.Float() * pTarget3->TESObjectREFR_GetScale_00567400();

        this->m_spLight->NiAVObject_SetTranslate_004bc1f0(fX, fY, fZ);

        NiPointer<NiNode> spNode3((pTarget3 == (Actor*)_g_thePlayer) ? _g_thePlayer->GetNode(false)
                                                                     : pTarget3->GetNiNode());
        spNode3->AttachChildInAvailableSlot((NiAVObject*)(NiPointLight*)this->m_spLight, true);
        ((void (__thiscall*)(Actor*, NiPointLight*))SetActorEffectLight)(pTarget3, this->m_spLight);
        ++DAT_011dc304;
    }
}

