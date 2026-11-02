// fallout/interface/fopipboymanager.cpp: FOPipboyManager, FOPipboyManagerPC, SystemColorManager, Interface and more (29 functions)

#include "fopipboymanager_decls.h"

// @fnv 0x007f9070
void FOPipboyManager::UpdatePipBoyButton()
{
    NiAVObject* button = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("PipBoyButton01"));
    if (!button)
        button = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("PipBoyButton01:0"));
    if (button)
    {
        NiNode* node;
        node = (NiNode*)NiDynamicCast(&DAT_011f4428,
                                      g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("PipBoyButton01")));
        if (!node)
            node = (NiNode*)NiDynamicCast(
                &DAT_011f4428, g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("PipBoyButton01:0")));
        m_cPipBoyButtonAvailability[0] = node->FUN_0045bc00(0);
        node = (NiNode*)NiDynamicCast(&DAT_011f4428,
                                      g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("PipBoyButton02")));
        if (!node)
            node = (NiNode*)NiDynamicCast(
                &DAT_011f4428, g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("PipBoyButton02:0")));
        m_cPipBoyButtonAvailability[1] = node->FUN_0045bc00(0);
        node = (NiNode*)NiDynamicCast(&DAT_011f4428,
                                      g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("PipBoyButton03")));
        if (!node)
            node = (NiNode*)NiDynamicCast(
                &DAT_011f4428, g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("PipBoyButton03:0")));
        m_cPipBoyButtonAvailability[2] = node->FUN_0045bc00(0);
    }
    button = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("StatsGlow"));
    if (!button)
        button = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("StatsGlow:0"));
    if (button)
    {
        m_pButtonGlowObjects[0] = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("StatsGlow"));
        if (!m_pButtonGlowObjects[0])
            m_pButtonGlowObjects[0] = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("StatsGlow:0"));
        m_pButtonGlowObjects[1] = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("ItemsGlow"));
        if (!m_pButtonGlowObjects[1])
            m_pButtonGlowObjects[1] = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("ItemsGlow:0"));
        m_pButtonGlowObjects[2] = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("DataGlow"));
        if (!m_pButtonGlowObjects[2])
            m_pButtonGlowObjects[2] = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("DataGlow:0"));
        SetDataGlowEnabled(false);
    }
}

// @fnv 0x007f99d0
void FOPipboyManager::UpdateScrollKnob()
{
    NiAVObject* pObject = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("ScrollKnob"));
    if (!pObject)
        pObject = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("ScrollKnob:0"));
    if (pObject && pObject->IsSceneNode())
        m_pGaugeObjects[0] = pObject->IsSceneNode()->GetAt(0);
    m_pGaugeObjects[1] = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("RadNeedle"));
    if (!m_pGaugeObjects[1])
        m_pGaugeObjects[1] = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("RadNeedle:0"));
    m_pGaugeObjects[2] = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("TabKnob"));
    if (!m_pGaugeObjects[2])
        m_pGaugeObjects[2] = g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("TabKnob:0"));
    m_fTabKnobPositions[0] = DAT_011db33c.Float()->f;
    m_fTabKnobPositions[4] = DAT_011db34c.Float()->f;
    float fStep = (m_fTabKnobPositions[4] - m_fTabKnobPositions[0]) / 4.0;
    for (unsigned int i = 1; i < 4; ++i)
        m_fTabKnobPositions[i] = m_fTabKnobPositions[i - 1] + fStep;
    m_fChartFirstPoint[2] = m_fTabKnobPositions[0];
    m_fChartSecondPoint[2] = m_fTabKnobPositions[0];
    m_fGaugeValues2[2] = 0.0f;
    m_fChartSecondPoint[1] = g_thePlayer ? 1.5707963267948966 - g_thePlayer->actorValues.GetCurrentActorValue(54) /
                                                                    StatsMenu::GetChartScale() * 3.1415927410125732
                                         : 0.0;
    m_fChartFirstPoint[1] = m_fChartSecondPoint[1];
    m_fGaugeValues2[1] = 0.0f;
    ThreeByThreeMatrix kLocalRotate;
    ThreeByThreeMatrix kParentRotate;
    if (m_pGaugeObjects[0])
    {
        kLocalRotate = m_pGaugeObjects[0]->GetRotate();
        kParentRotate = m_pGaugeObjects[0]->GetParent()->GetRotate();
        m_pGaugeObjects[0]->GetParent()->SetLocalRotation(kParentRotate * kLocalRotate);
        m_pGaugeObjects[0]->SetLocalRotation(m_fChartFirstPoint[0], 1.0f, 0.0f, 0.0f);
    }
    if (m_pGaugeObjects[1])
        m_pGaugeObjects[1]->SetLocalRotation(m_fChartFirstPoint[1], 0.0f, 0.0f, 1.0f);
    if (m_pGaugeObjects[2])
        m_pGaugeObjects[2]->SetLocalRotation(m_fChartFirstPoint[2], 0.0f, 0.0f, 1.0f);
}

// @fnv 0x007f8ba0
void FOPipboyManager::OnMenuOpen()
{
    NiNode* screenNode;
    if (DAT_011db2cc.Bool()->b && !IsUnk28Set() && g_thePlayer && g_thePlayer->GetNode(true))
    {
        {
            struct Screens
            {
                NiAVObject* thirdPerson;
                NiAVObject* firstPerson;
            } screenObjects;
            screenObjects.thirdPerson = 0;
            screenObjects.firstPerson = 0;
            screenNode = 0;
            screenNode = (NiNode*)NiDynamicCast(
                &DAT_011f4428, g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("pipboyscreen")));
            if (!screenNode)
                screenNode = (NiNode*)NiDynamicCast(
                    &DAT_011f4428, g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("pipboyscreen:0")));
            FORenderedMenu::OnMenuOpen();
            FUN_00705fc0(Interface::FUN_004b7210()->GetRoot());
            if (screenNode)
            {
                screenObjects.firstPerson = screenNode->FUN_0045bc00(0);
                m_pPipBoyObject0 = screenNode->GetParent();
            }
            else
            {
                screenObjects.firstPerson = NiDynamicCast(
                    &DAT_011f4acc, g_thePlayer->GetNode(true)->GetObjectByName(NiFixedString("pipboyscreen:0")));
                if (screenObjects.firstPerson)
                    m_pPipBoyObject0 = screenObjects.firstPerson->GetParent();
            }
            FUN_004dc540(g_thePlayer->GetNode(true));
            if (screenNode)
            {
                screenObjects.thirdPerson = NiDynamicCast(&DAT_011f4acc, screenNode->FUN_0045bc00(0));
                m_pPipBoyObject1 = screenNode->GetParent();
                m_pPipBoyObject2 = screenObjects.thirdPerson;
            }
            else if (screenObjects.firstPerson)
            {
                screenObjects.thirdPerson = screenObjects.firstPerson;
                m_pPipBoyObject1 = screenObjects.firstPerson->GetParent();
                m_pPipBoyObject2 = screenObjects.thirdPerson;
            }
            if (screenObjects.firstPerson && screenObjects.thirdPerson)
            {
                FUN_007fc2d0(screenObjects.firstPerson);
                FUN_007fc2d0(screenObjects.thirdPerson);
                SetScreen(screenObjects.firstPerson);
            }
            UpdatePipBoyButton();
            UpdateScrollKnob();
            InitializeMenuLight();
            if (m_pPipBoyObject0)
            {
                NiUpdateData updateData(0.0f, false, false);
                m_pPipBoyObject0->Update(updateData);
                m_pPipBoyObject0->UpdateSceneObject();
            }
            if (m_pPipBoyObject1)
            {
                NiUpdateData updateData(0.0f, false, false);
                m_pPipBoyObject1->Update(updateData);
                m_pPipBoyObject1->UpdateSceneObject();
            }
        }
        RgbaColor kColor(0.0f, 0.0f, 0.0f, 0.0f);
        if (SystemColorManager::GetSingleton()->GetColor(4, kColor))
        {
            SetQuad(kColor);
            FUN_007f7fb0(kColor);
        }
        SetBlurIntensity(DAT_011db2dc.Float()->f);
        FUN_00444020(DAT_011db328.Float()->f);
        SetScanlines(true, DAT_011db274.Float()->f);
        FUN_00810530(true);
        SetPipBoyObjectVisibility(false, false, true);
        SetPipBoyObjectVisibility(true, false, true);
    }
}

// @fnv 0x007fa310
void FOPipboyManager::SetPipBoyObjectVisibility(bool thirdPerson, bool show, bool updateState)
{
    NiNode* pRoot = (thirdPerson ? m_pPipBoyObject1 : m_pPipBoyObject0);
    if (pRoot)
    {
        NiAVObject* pEffect = pRoot->GetObjectByName(NiFixedString("PipboyLightEffect"));
        if (!pEffect)
            pEffect = pRoot->GetObjectByName(NiFixedString("PipboyLightEffect:0"));
        if (pEffect)
        {
            pEffect->FUN_00450f90(!show);
            if (updateState)
            {
                if (thirdPerson)
                {
                    b1stPersonLightOn = show;
                }
                else
                {
                    b3rdPersonLightOn = show;
                    NiNode* pNode = pEffect->IsSceneNode();
                    if (pNode && pNode->FUN_00453470())
                    {
                        NiGeometry* m_pShaderGeometry = pNode->GetAt(0)->IsGeometry();
                        if (m_pShaderGeometry)
                        {
                            NiProperty* pProperty = m_pShaderGeometry->GetProperty(FUN_004af350());
                            if (pProperty)
                                pProperty->FUN_0068c9f0((float)show);
                            else
                            {
                                BSShaderProperty* pShaderProperty =
                                    (BSShaderProperty*)m_pShaderGeometry->GetProperty(FUN_00438220());
                                pShaderProperty->SetAlpha((float)show);
                            }
                            m_pShaderGeometry->UpdateSceneObject();
                        }
                    }
                }
            }
        }
    }
    else if (updateState)
    {
        if (thirdPerson)
            b1stPersonLightOn = show;
        else
            b3rdPersonLightOn = show;
    }
}

// The callers receive Interface::FUN_004b7210() and then access the Pipboy manager.
// @fnv 0x00704370
FOPipboyManager* Interface::GetPipboyManager()
{
    return pPipboyManager;
}

// @fnv 0x007f9840
void FOPipboyManager::InitializeMenuLight()
{
    if (!CreateMenuLight("Omni01", 0))
        CreateMenuLight("Omni01:0", 0);
    NiPointLight* light = (NiPointLight*)((BGSBodyPart*)this)->GetPartName();
    struct PointStorage
    {
        float x, y, z;
    } rgb;
    if (light)
    {
        light->SetEffectColor(NiPoint3(0.0f, 0.0f, 0.0f));
        light->FUN_004bc280(NiPoint3(0.0f, 0.0f, 0.0f));
        light->FUN_0050c630(0.0f);
        light->FUN_0050c660(0.0f);
        light->FUN_0050c690(0.0f);
        light->FUN_0050dd20(1.0f);
        light->FUN_0050dd50(NiPoint3(DAT_011db514.Float()->f, 0.0f, 0.0f));
        RgbaColor color(0.0f, 0.0f, 0.0f, 0.0f);
        SystemColorManager::GetSingleton()->GetColor(4, color);
        ((NiPoint3*)&rgb)->NiPoint3::NiPoint3(color.r, color.g, color.b);
        ((PathingGraphNode*)this)->FUN_006b0570((const NiPoint3&)rgb);
        SetIntensity(1.0f);
        SetScreenLightFlickerIntensity(1.0f);
    }
}
// @fnv 0x007f9050
void FOPipboyManager::SetScanlines(bool enabled, float scale)
{
    doScanlines = enabled;
    scanlineScale = scale;
}
// @fnv 0x007f9010
void FOPipboyManager::SetScreen(NiAVObject* apScreen)
{
    screen = apScreen;
}
// @fnv 0x007f99b0
void FOPipboyManager::SetScreenLightFlickerIntensity(float value)
{
    flicker = value;
}
// @fnv 0x007f9030
void FOPipboyManager::SetBlurIntensity(float value)
{
    blurIntensity = value;
}

struct FUN_004dc540_shell : public FORenderedMenu
{
    void FUN_004dc540(NiAVObject*);
};

// @fnv 0x004dc540
void FUN_004dc540_shell::FUN_004dc540(NiAVObject* apScreenParent)
{
    *(NiPointer<NiNode>*)((char*)this + 8) = (NiNode*)apScreenParent;
}

struct NiStream;
struct NiColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, NiColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
};
typedef char _sizecheck_NiColor[sizeof(NiColor) == 12 ? 1 : -1];
struct FUN_006b0570_shell : public FORenderedMenu
{
    void FUN_006b0570(NiColor*);
};

// Copies the NiColor pointed to by the argument into the field at offset 0x2c of this object.
// @fnv 0x006b0570
void FUN_006b0570_shell::FUN_006b0570(NiColor* apColor)
{
    *(NiColor*)((char*)this + 0x2c) = *apColor;
}

struct FUN_007f86f0_shell : public FOPipboyManager
{
    void SetKnobTargetAndRate(int, float, float);
};

// Stores afTarget and afRate into the per-knob arrays at offsets 0x118 and 0x124 for index aiKnob.
// @fnv 0x007f86f0
void FUN_007f86f0_shell::SetKnobTargetAndRate(int aiKnob, float afTarget, float afRate)
{
    ((float*)((char*)this + 0x118))[aiKnob] = afTarget;
    ((float*)((char*)this + 0x124))[aiKnob] = afRate;
}

struct FUN_00965580_shell : public FORenderedMenu
{
    void SetIntensity(float);
};

// @fnv 0x00965580
void FUN_00965580_shell::SetIntensity(float afIntensity)
{
    *(float*)((char*)this + 0x38) = afIntensity;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_007f7cb0(unsigned int flags);
};
// Calls the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x007f7cb0
void* DelStandIn::FUN_007f7cb0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

class NiScreenElements : public NiGeometry
{
};

struct SoundPlaybackHandle
{
    unsigned int uiID;
    bool m_bLooping;
    unsigned int uiState;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
};

struct FUN_007fad10 : public FORenderedMenu
{
    void FUN_007fadf0();
};

struct FOPipboyManagerPC : public FUN_007fad10
{
    NiPointer<NiNode> m_pPipBoyObject0;
    NiPointer<NiNode> m_pPipBoyObject1;
    NiPointer<NiAVObject> m_pPipBoyObject2;
    NiPointer<NiScreenElements> m_pScreenGeometry;
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];
    NiPointer<NiAVObject> m_pButtonGlowObjects[3];
    NiPointer<NiGeometry> m_pGaugeObjects[3];
    float m_fChartFirstPoint[3];
    float m_fChartSecondPoint[3];
    float m_fGaugeValues2[3];
    float m_fTabKnobPositions[5];
    bool m_bUseMenuImageSpaceEffects;
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    SoundPlaybackHandle m_kPipBoyLightData;
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool m_bPipBoyLightOn;
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    bool m_bPipBoyLightEnabled;
    void FUN_007f7e00();
};

// Clears the pipboy node pointers, per-index arrays and screen elements, then calls FUN_007fadf0.
// @fnv 0x007f7e00
void FOPipboyManagerPC::FUN_007f7e00()
{
    m_pPipBoyObject0 = 0;
    m_pPipBoyObject1 = 0;
    m_pScreenGeometry = 0;
    for (int i = 0; i < 3; i++)
    {
        m_cPipBoyButtonAvailability[i] = 0;
        m_pButtonGlowObjects[i] = 0;
        m_pGaugeObjects[i] = 0;
        m_fChartFirstPoint[i] = 0;
        m_fChartSecondPoint[i] = 0;
        m_fGaugeValues2[i] = 0;
    }
    m_pPipBoyObject2 = 0;
    FUN_007fadf0();
}

namespace fnv_007f8610 {
class NiScreenElements : public NiGeometry
{
};

struct SoundPlaybackHandle
{
    unsigned int uiID;
    bool m_bLooping;
    unsigned int uiState;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle& rhs);
    bool Play(bool abUnk);
};

struct BSAudio
{
    static BSAudio* GetSingleton();
    SoundPlaybackHandle GetSoundHandleByEditorID(const char* apEditorID, unsigned int auiFlags);
};

struct FOPipboyManagerPC : public FORenderedMenu
{
    enum Knobs
    {
    };
    NiPointer<NiNode> m_pPipBoyObject0;
    NiPointer<NiNode> m_pPipBoyObject1;
    NiPointer<NiAVObject> m_pPipBoyObject2;
    NiPointer<NiScreenElements> m_pScreenGeometry;
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];
    NiPointer<NiAVObject> m_pButtonGlowObjects[3];
    NiPointer<NiGeometry> m_pGaugeObjects[3];
    float m_fChartFirstPoint[3];
    float m_fChartSecondPoint[3];
    float m_fGaugeValues2[3];
    float m_fTabKnobPositions[5];
    bool m_bUseMenuImageSpaceEffects;
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    SoundPlaybackHandle m_kPipBoyLightData;
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool m_bPipBoyLightOn;
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    bool m_bPipBoyLightEnabled;
    void FUN_007f8610(Knobs aiKnob, float afAmount, float afRate, bool abPlaySound);
};

// @fnv 0x007f8610
void FOPipboyManagerPC::FUN_007f8610(Knobs aiKnob, float afAmount, float afRate, bool abPlaySound)
{
    if (abPlaySound && aiKnob == 0)
    {
        SoundPlaybackHandle soundHandle;
        soundHandle = BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIPipBoyScroll", 0x121);
        soundHandle.Play(false);
    }
    m_fChartSecondPoint[aiKnob] += afAmount;
    m_fGaugeValues2[aiKnob] = afRate;
}
}  // namespace fnv_007f8610

namespace fnv_007f8a80 {
float __cdecl RandomFloat0To1();

class FORenderedMenuPC : public FORenderedMenu
{
  public:
    void StartBurst(float, float, float);
    void FUN_007fb250(float, float);
    void FUN_007fb2b0(float, float, float);
};

extern SettingT_GameSettingCollection_ g_011db3b0;
extern SettingT_GameSettingCollection_ g_011db3bc;
extern SettingT_GameSettingCollection_ g_011db3fc;
extern SettingT_GameSettingCollection_ g_011db414;
extern SettingT_GameSettingCollection_ g_011db43c;
extern SettingT_GameSettingCollection_ g_011db480;
extern SettingT_GameSettingCollection_ g_011db4b4;
extern SettingT_GameSettingCollection_ g_011db4e0;
extern SettingT_GameSettingCollection_ g_011db4ec;

struct FOPipboyManagerPC : public FOPipboyManager
{
    void FUN_007f8a80();
};

// @fnv 0x007f8a80
void FOPipboyManagerPC::FUN_007f8a80()
{
    float fchance;

    fchance = RandomFloat0To1();
    if (fchance < g_011db4b4.Float()->f)
        ((FORenderedMenuPC*)Interface::FUN_004b7210()->GetPipboyManager())
            ->FUN_007fb250(g_011db4ec.Float()->f, g_011db3fc.Float()->f);
    if (fchance >= g_011db4b4.Float()->f && fchance < g_011db4b4.Float()->f + g_011db4e0.Float()->f)
        ((FORenderedMenuPC*)Interface::FUN_004b7210()->GetPipboyManager())
            ->FUN_007fb2b0(g_011db414.Float()->f, g_011db3bc.Float()->f, g_011db3b0.Float()->f);
    ((FORenderedMenuPC*)Interface::FUN_004b7210()->GetPipboyManager())
        ->StartBurst(g_011db480.Float()->f, g_011db43c.Float()->f, 0.5f);
}
}  // namespace fnv_007f8a80

namespace fnv_007fa220 {
class Actor;
class TESAnimGroup
{
  public:
    unsigned int GetType();
};
class NiControllerSequence
{
};
class BSAnimGroupSequence : public NiControllerSequence
{
  public:
    TESAnimGroup* GetAnimGroup() const;
};
enum ACTION_FLAGS
{
};
enum ANIM_GROUP_SECTION
{
};
class Animation
{
  public:
    NiControllerSequence* GetControllerSequence(int);
    void Update(Actor*, float, float);
    void UpdateMovement(Actor*);
    bool IsGroupQueued(unsigned short);
    BSAnimGroupSequence* PlayGroup(unsigned short, ACTION_FLAGS, int, ANIM_GROUP_SECTION);
    void FUN_008eeaa0(int);
};
class PlayerCharacterPC : public PlayerCharacter
{
  public:
    Animation* GetAnimation(bool) const;
};
struct FUN_00424940_shell
{
    char FUN_00424940();
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
extern Twin_0084d030 g_timeGlobal;
bool __cdecl IsConsoleActive();

struct FOPipboyManagerPC : public FOPipboyManager
{
    void FUN_007fa220();
};

// @fnv 0x007fa220
void FOPipboyManagerPC::FUN_007fa220()
{
    BSAnimGroupSequence* pIdleSequence;
    Animation* panim;

    if (IsConsoleActive())
        return;
    if (*(int*)((char*)Interface::FUN_004b7210() + 0x4bc) != 3)
        return;
    if (((FUN_00424940_shell*)Interface::FUN_004b7210())->FUN_00424940() == 4)
        return;
    panim = ((PlayerCharacterPC*)g_thePlayer)->GetAnimation(true);
    pIdleSequence = (BSAnimGroupSequence*)panim->GetControllerSequence(0);
    if (pIdleSequence && pIdleSequence->GetAnimGroup()->GetType() != 1 && panim->IsGroupQueued(1))
        panim->PlayGroup(1, (ACTION_FLAGS)1, -1, (ANIM_GROUP_SECTION)-1);
    panim->FUN_008eeaa0(0x17);
    panim->Update((Actor*)g_thePlayer, g_timeGlobal.GetStoredFloatValue(), -1.0f);
    panim->UpdateMovement((Actor*)g_thePlayer);
}
}  // namespace fnv_007fa220

namespace fnv_007fa810 {
class NiScreenElements : public NiGeometry
{
};

struct SoundPlaybackHandle
{
    unsigned int uiID;
    bool m_bLooping;
    unsigned int uiState;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
};

struct ReferenceLightData
{
    NiPointer<NiPointLight> m_pMenuLight;
};

float __cdecl FUN_00404010(float, float);
float __cdecl FUN_0040ebd0(float, float);
ReferenceLightData* __fastcall FUN_00572750(PlayerCharacter* apPlayer);
extern double _gModifierZero;
extern SettingT_GameSettingCollection_ g_011db308;

struct FOPipboyManagerPC : public FORenderedMenu
{
    NiPointer<NiNode> m_pPipBoyObject0;
    NiPointer<NiNode> m_pPipBoyObject1;
    NiPointer<NiAVObject> m_pPipBoyObject2;
    NiPointer<NiScreenElements> m_pScreenGeometry;
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];
    NiPointer<NiAVObject> m_pButtonGlowObjects[3];
    NiPointer<NiGeometry> m_pGaugeObjects[3];
    float m_fChartFirstPoint[3];
    float m_fChartSecondPoint[3];
    float m_fGaugeValues2[3];
    float m_fTabKnobPositions[5];
    bool m_bUseMenuImageSpaceEffects;
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    SoundPlaybackHandle m_kPipBoyLightData;
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool m_bPipBoyLightOn;
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    bool m_bPipBoyLightEnabled;
    void UpdatePipboyLightFade(float afTime);
};

// @fnv 0x007fa810
void FOPipboyManagerPC::UpdatePipboyLightFade(float afTime)
{
    ReferenceLightData* plightref;
    float ffade;
    float fdelta;

    fdelta = afTime - m_fFirstPersonLightIntensity;
    ffade = FUN_0040ebd0(fdelta / g_011db308.Float()->f, 1.0f);
    ffade = FUN_00404010(0.0f, ffade);
    if (m_fThirdPersonLightIntensity == 0.0)
        ffade = 1.0f - ffade;
    plightref = FUN_00572750(g_thePlayer);
    if (plightref && plightref->m_pMenuLight)
        ((NiPointLight*)plightref->m_pMenuLight)->FUN_0050dd20(ffade);
}
}  // namespace fnv_007fa810

namespace fnv_007ff960 {
class NiColor
{
  public:
    float r, g, b;
    NiColor(float, float, float);
};

ShadowSceneNode* __cdecl FUN_00450b80(int);
void __cdecl _FNV_Warning(const char*);

extern SettingT_GameSettingCollection_ g_011db5f8;
extern SettingT_GameSettingCollection_ g_011db608;
extern SettingT_GameSettingCollection_ g_011db644;
extern SettingT_GameSettingCollection_ g_011db650;
extern SettingT_GameSettingCollection_ g_011db668;

class NiAVObjectPC : public NiAVObject
{
  public:
    void Update(NiUpdateData&);
};

struct FOPipboyManagerPC : public FOPipboyManager
{
    NiPointLight* GetLight();
    void FUN_006b0570(const NiColor&);
    void CreateTerminalLight();
};

// @fnv 0x007ff960
void FOPipboyManagerPC::CreateTerminalLight()
{
    NiPointLight* plight;

    if (!CreateMenuLight("Omni01", FUN_00450b80(1)))
    {
        _FNV_Warning("MENUS: Failed to create terminal light.  Terminal will only receive ambient light.");
        return;
    }
    plight = GetLight();
    if (plight)
    {
        plight->FUN_004bc280(NiPoint3(0, 0, 0));
        plight->FUN_0050c630(0);
        plight->FUN_0050c660(0);
        plight->FUN_0050c690(0);
        plight->FUN_0050dd20(1.0f);
        plight->FUN_0050dd50(NiPoint3(g_011db644.Float()->f, 0, 0));
        {
            NiColor screenLightColor(g_011db608.Float()->f, g_011db668.Float()->f, g_011db5f8.Float()->f);
            FUN_006b0570(screenLightColor);
        }
        SetIntensity(g_011db650.Float()->f);
        SetScreenLightFlickerIntensity(1.0f);
        NiUpdateData updateData(0, false, false);
        ((NiAVObjectPC*)plight)->Update(updateData);
    }
}
}  // namespace fnv_007ff960

struct AnimIdle
{
    int GetSection();
};
struct GameTimerRecord
{
    int dummy;
};
extern GameTimerRecord g_timeGlobal;
struct S07f7ee0
{
    bool UpdateScreenEffect();
    void FUN_007f8320(float);
    void FUN_007fa220();
    bool FUN_007f7ee0();
};
// @fnv 0x007f7ee0
bool S07f7ee0::FUN_007f7ee0()
{
    float fappTime;
    if (!this->UpdateScreenEffect())
        return false;
    fappTime = (float)(unsigned int)((AnimIdle*)&g_timeGlobal)->GetSection();
    this->FUN_007f8320(fappTime);
    this->FUN_007fa220();
    return true;
}

void __cdecl FUN_007ffe40();
void* __cdecl FUN_004b7210();
struct Im7181
{
    void SetRenderedMenu(int);
};
namespace ol4_00985000 {
struct CGBase
{
    void SetProcedureType(int);
};
}
struct VTab
{
    virtual int VFn(int);
};
struct FUN_007ffd50_shell
{
    void Close();
};
// Calls FUN_007ffe40, invokes VFn(1) on the parent if present, then sets procedure type 0 and calls SetRenderedMenu(0) on the FUN_004b7210 result.
// @fnv 0x007ffd50
void FUN_007ffd50_shell::Close()
{
    VTab* parent;
    FUN_007ffe40();
    {
        NiNode* obj = ((NiAVObject*)this)->GetParent();
        parent = (VTab*)obj;
    }
    parent ? parent->VFn(1) : 0;
    ((ol4_00985000::CGBase*)this)->SetProcedureType(0);
    ((Im7181*)FUN_004b7210())->SetRenderedMenu(0);
}

// FUN_007fa990: thiscall; calls on two module globals, three far virtual calls
struct G02d98
{
    void FUN_00c3dfa0(int);
};
class G11dea3c
{
  public:
    struct Obj* FUN_008d8520();
};

struct Obj
{
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003() = 0;
    virtual void v004() = 0;
    virtual void v005() = 0;
    virtual void v006() = 0;
    virtual void v007() = 0;
    virtual void v008() = 0;
    virtual void v009() = 0;
    virtual void v010() = 0;
    virtual void v011() = 0;
    virtual void v012() = 0;
    virtual void v013() = 0;
    virtual void v014() = 0;
    virtual void v015() = 0;
    virtual void v016() = 0;
    virtual void v017() = 0;
    virtual void v018() = 0;
    virtual void v019() = 0;
    virtual void v020() = 0;
    virtual void v021() = 0;
    virtual void v022() = 0;
    virtual void v023() = 0;
    virtual void v024() = 0;
    virtual void v025() = 0;
    virtual void v026() = 0;
    virtual void v027() = 0;
    virtual void v028() = 0;
    virtual void v029() = 0;
    virtual void v030() = 0;
    virtual void v031() = 0;
    virtual void v032() = 0;
    virtual void v033() = 0;
    virtual void v034() = 0;
    virtual void v035() = 0;
    virtual void v036() = 0;
    virtual void v037() = 0;
    virtual void v038() = 0;
    virtual void v039() = 0;
    virtual void v040() = 0;
    virtual void v041() = 0;
    virtual void v042() = 0;
    virtual void v043() = 0;
    virtual void v044() = 0;
    virtual void v045() = 0;
    virtual void v046() = 0;
    virtual void v047() = 0;
    virtual void v048() = 0;
    virtual void v049() = 0;
    virtual void v050() = 0;
    virtual void v051() = 0;
    virtual void v052() = 0;
    virtual void v053() = 0;
    virtual void v054() = 0;
    virtual void v055() = 0;
    virtual void v056() = 0;
    virtual void v057() = 0;
    virtual void v058() = 0;
    virtual void v059() = 0;
    virtual void v060() = 0;
    virtual void v061() = 0;
    virtual void v062() = 0;
    virtual void v063() = 0;
    virtual void v064() = 0;
    virtual void v065() = 0;
    virtual void v066() = 0;
    virtual void v067() = 0;
    virtual void v068() = 0;
    virtual void v069() = 0;
    virtual void v070() = 0;
    virtual void v071() = 0;
    virtual void v072() = 0;
    virtual void v073() = 0;
    virtual void v074() = 0;
    virtual void v075() = 0;
    virtual void v076() = 0;
    virtual void v077() = 0;
    virtual void v078() = 0;
    virtual void v079() = 0;
    virtual void v080() = 0;
    virtual void v081() = 0;
    virtual void v082() = 0;
    virtual void v083() = 0;
    virtual void v084() = 0;
    virtual void v085() = 0;
    virtual void v086() = 0;
    virtual void v087() = 0;
    virtual void v088() = 0;
    virtual void v089() = 0;
    virtual void v090() = 0;
    virtual void v091() = 0;
    virtual void v092(G11dea3c* a) = 0;
    virtual void v093() = 0;
    virtual void v094() = 0;
    virtual void v095() = 0;
    virtual void v096() = 0;
    virtual void v097() = 0;
    virtual void v098() = 0;
    virtual void v099() = 0;
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
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual void v139() = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void v168() = 0;
    virtual void v169() = 0;
    virtual void v170() = 0;
    virtual void v171() = 0;
    virtual void v172() = 0;
    virtual void v173() = 0;
    virtual void v174() = 0;
    virtual void v175() = 0;
    virtual void v176() = 0;
    virtual void v177() = 0;
    virtual void v178() = 0;
    virtual void v179() = 0;
    virtual void v180() = 0;
    virtual void v181() = 0;
    virtual void v182() = 0;
    virtual void v183() = 0;
    virtual void v184() = 0;
    virtual void v185() = 0;
    virtual void v186() = 0;
    virtual void v187() = 0;
    virtual void v188() = 0;
    virtual void v189() = 0;
    virtual void v190() = 0;
    virtual void v191() = 0;
    virtual void v192() = 0;
    virtual void v193() = 0;
    virtual void v194() = 0;
    virtual void v195() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual void v198() = 0;
    virtual void v199() = 0;
    virtual void v200() = 0;
    virtual void v201() = 0;
    virtual void v202() = 0;
    virtual void v203() = 0;
    virtual void v204() = 0;
    virtual void v205() = 0;
    virtual void v206() = 0;
    virtual void v207() = 0;
    virtual void v208() = 0;
    virtual void v209() = 0;
    virtual void v210() = 0;
    virtual void v211() = 0;
    virtual void v212() = 0;
    virtual void v213() = 0;
    virtual void v214() = 0;
    virtual void v215() = 0;
    virtual void v216() = 0;
    virtual void v217() = 0;
    virtual void v218() = 0;
    virtual void v219() = 0;
    virtual void v220() = 0;
    virtual void v221() = 0;
    virtual void v222() = 0;
    virtual void v223() = 0;
    virtual void v224() = 0;
    virtual void v225() = 0;
    virtual void v226() = 0;
    virtual void v227() = 0;
    virtual void v228() = 0;
    virtual void v229() = 0;
    virtual void v230() = 0;
    virtual void v231() = 0;
    virtual void v232() = 0;
    virtual void v233() = 0;
    virtual void v234() = 0;
    virtual void v235() = 0;
    virtual void v236() = 0;
    virtual void v237() = 0;
    virtual void v238() = 0;
    virtual void v239() = 0;
    virtual void v240() = 0;
    virtual void v241() = 0;
    virtual void v242() = 0;
    virtual void v243() = 0;
    virtual void v244() = 0;
    virtual void v245() = 0;
    virtual void v246() = 0;
    virtual void v247() = 0;
    virtual void v248() = 0;
    virtual void v249() = 0;
    virtual void v250() = 0;
    virtual void v251() = 0;
    virtual void v252() = 0;
    virtual void v253() = 0;
    virtual void v254() = 0;
    virtual void v255() = 0;
    virtual void v256() = 0;
    virtual void v257() = 0;
    virtual void v258() = 0;
    virtual void v259() = 0;
    virtual void v260() = 0;
    virtual void v261() = 0;
    virtual void v262() = 0;
    virtual void v263() = 0;
    virtual void v264() = 0;
    virtual void v265() = 0;
    virtual void v266() = 0;
    virtual void v267() = 0;
    virtual void v268() = 0;
    virtual void v269() = 0;
    virtual void v270() = 0;
    virtual void v271() = 0;
    virtual void v272() = 0;
    virtual void v273() = 0;
    virtual void v274() = 0;
    virtual void v275() = 0;
    virtual void v276() = 0;
    virtual void v277() = 0;
    virtual void v278() = 0;
    virtual void v279() = 0;
    virtual void v280() = 0;
    virtual void v281(G11dea3c* a) = 0;
    virtual void v282(int a) = 0;
};

extern unsigned int DAT_01202d98;
extern unsigned int DAT_011dea3c;

class FUN_007fa990_cls
{
  public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;   // +0x24
    virtual void v10() = 0;  // +0x28
    void FUN_007fa990();
    void FUN_005db4c0(int a);
};

// Calls FUN_00c3dfa0(5) on DAT_01202d98, obtains an object from DAT_011dea3c, invokes v092, v282(1) and v281 on it, then v10, v9 and FUN_005db4c0(0).
// @fnv 0x007fa990
void FUN_007fa990_cls::FUN_007fa990()
{
    reinterpret_cast<G02d98*>(DAT_01202d98)->FUN_00c3dfa0(5);
    Obj* obj = reinterpret_cast<G11dea3c*>(DAT_011dea3c)->FUN_008d8520();
    obj->v092(reinterpret_cast<G11dea3c*>(DAT_011dea3c));
    obj->v282(1);
    obj->v281(reinterpret_cast<G11dea3c*>(DAT_011dea3c));
    v10();
    v9();
    FUN_005db4c0(0);
}

struct PipBase
{
    PipBase();
    virtual ~PipBase();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
};
struct PipPointer
{
    void* object;
    PipPointer();
    PipPointer(void*);
    ~PipPointer();
    PipPointer& operator=(void*);
};
struct PipSound
{
    int id;
    int state;
    int flags;
    PipSound();
    ~PipSound();
};
struct FUN_007f7a70 : PipBase
{
    PipPointer root, thirdRoot, thirdScreen, partialGeometry;
    PipPointer buttons[3];
    PipPointer glow[3];
    PipPointer knobs[3];
    float positions[3];
    float targets[3];
    float rates[3];
    float tabPositions[5];
    bool scaled;
    float wheelRotation;
    float wheelTarget;
    bool up;
    PipSound sound;
    bool firstLight;
    bool thirdLight;
    bool fading;
    FUN_007f7a70();
    virtual ~FUN_007f7a70();
    void Init(bool);
};
// @fnv 0x007f7a70
FUN_007f7a70::FUN_007f7a70() : root(0), thirdRoot(0), thirdScreen(0), partialGeometry(0)
{
    root = 0;
    thirdRoot = 0;
    partialGeometry = 0;
    for (int index = 0; index < 3; ++index)
    {
        buttons[index] = 0;
        glow[index] = 0;
        knobs[index] = 0;
        positions[index] = 0.0f;
        targets[index] = 0.0f;
        rates[index] = 0.0f;
    }
    scaled = false;
    up = false;
    firstLight = false;
    thirdLight = false;
    Init(true);
    fading = false;
    thirdScreen = 0;
}

bool FUN_00705ea0();
void FUN_00703610();
struct PipboyBase
{
    virtual ~PipboyBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
};
struct PipboyPointer
{
    void* object;
    ~PipboyPointer();
};
struct FUN_007f7ce0 : PipboyBase
{
    PipboyPointer m_pPipBoyObject0;
    PipboyPointer m_pPipBoyObject1;
    PipboyPointer m_pPipBoyObject2;
    PipboyPointer m_pScreenGeometry;
    PipboyPointer m_cPipBoyButtonAvailability[3];
    PipboyPointer m_pButtonGlowObjects[3];
    PipboyPointer m_pGaugeObjects[3];
    float m_fChartFirstPoint[3];
    float m_fChartSecondPoint[3];
    float m_fGaugeValues2[3];
    float m_fTabKnobPositions[5];
    bool m_bUseMenuImageSpaceEffects;
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    SoundPlaybackHandle m_kPipBoyLightData;
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool m_bPipBoyLightOn;
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    bool m_bPipBoyLightEnabled;
    virtual ~FUN_007f7ce0();
};
// Destructor that, if FUN_00705ea0() returns true, calls FUN_00703610().
// @fnv 0x007f7ce0
FUN_007f7ce0::~FUN_007f7ce0()
{
    if (FUN_00705ea0())
        FUN_00703610();
}

namespace fnv_007f8320 {
extern float DAT_011db370;

class NiAVObjectHelper : public NiAVObject
{
  public:
    void FUN_006404b0(float, float, float, float);
};

class S07f7ee0 : public FOPipboyManager
{
  public:
    void FUN_007f8320(float fTime);
};

// @fnv 0x007f8320
void S07f7ee0::FUN_007f8320(float fTime)
{
    bool bUpdated[3];
    float fMoveElapsedTime = fTime - DAT_011db370;
    bUpdated[0] = false;
    bUpdated[1] = false;
    bUpdated[2] = false;

    for (int i = 0; i < 3; i++)
    {
        if (m_fChartSecondPoint[i] > m_fChartFirstPoint[i])
        {
            m_fChartFirstPoint[i] += m_fGaugeValues2[i] * fMoveElapsedTime;
            if (m_fChartFirstPoint[i] > m_fChartSecondPoint[i])
            {
                m_fChartFirstPoint[i] = m_fChartSecondPoint[i];
            }
            bUpdated[i] = true;
        }
        if (m_fChartSecondPoint[i] < m_fChartFirstPoint[i])
        {
            m_fChartFirstPoint[i] -= m_fGaugeValues2[i] * fMoveElapsedTime;
            if (m_fChartFirstPoint[i] < m_fChartSecondPoint[i])
            {
                m_fChartFirstPoint[i] = m_fChartSecondPoint[i];
            }
            bUpdated[i] = true;
        }
    }

    if (m_pGaugeObjects[0] && bUpdated[0])
    {
        ((NiAVObjectHelper*)(NiAVObject*)m_pGaugeObjects[0])->FUN_006404b0(m_fChartFirstPoint[0], 1.0f, 0.0f, 0.0f);
        NiUpdateData updateData(0.0f, false, false);
        m_pGaugeObjects[0]->Update(updateData);
    }

    if (m_pGaugeObjects[1] && bUpdated[1])
    {
        ((NiAVObjectHelper*)(NiAVObject*)m_pGaugeObjects[1])->FUN_006404b0(m_fChartFirstPoint[1], 0.0f, 0.0f, 1.0f);
        NiUpdateData updateData(0.0f, false, false);
        m_pGaugeObjects[1]->Update(updateData);
    }

    if (m_pGaugeObjects[2] && bUpdated[2])
    {
        ((NiAVObjectHelper*)(NiAVObject*)m_pGaugeObjects[2])->FUN_006404b0(m_fChartFirstPoint[2], 0.0f, 0.0f, 1.0f);
        NiUpdateData updateData(0.0f, false, false);
        m_pGaugeObjects[2]->Update(updateData);
    }

    DAT_011db370 = fTime;
}
}  // namespace fnv_007f8320

extern SettingT_GameSettingCollection_ DAT_011db2bc;
float __cdecl FUN_0040ebd0(float, float);
float __cdecl FUN_00404010(float, float);
class FadeGeometry : public NiGeometry
{
  public:
    void FUN_00a5a040();
};
class PipboyFadeManager : public FORenderedMenu
{
  public:
    NiPointer<NiNode> m_pPipBoyObject0;
    NiPointer<NiNode> m_pPipBoyObject1;
    NiPointer<NiAVObject> m_pPipBoyObject2;
    void* m_pScreenGeometry;
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];
    NiPointer<NiAVObject> m_pButtonGlowObjects[3];
    NiPointer<NiAVObject> m_pGaugeObjects[3];
    float m_fChartFirstPoint[3];
    float m_fChartSecondPoint[3];
    float m_fGaugeValues2[3];
    float m_fTabKnobPositions[5];
    bool m_bUseMenuImageSpaceEffects;
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    unsigned int backgroundHum[3];
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool m_bPipBoyLightOn;
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    void UpdatePipboyLightFade(float);
    void FUN_007fa310(bool, bool, bool);
    void UpdateFade(float);
};
// @fnv 0x007fa540
void PipboyFadeManager::UpdateFade(float now)
{
    if (m_bPipBoyLightOn)
    {
        UpdatePipboyLightFade(now);
        FUN_007fa310(false, true, false);
        NiNode* aTarget = m_pPipBoyObject0;  // Root containing the light effect.
        float time = now - m_fFirstPersonLightIntensity;
        float result = FUN_0040ebd0(time / DAT_011db2bc.Float()->f, 1.0f);
        result = FUN_00404010(0.0f, result);
        if (m_fThirdPersonLightIntensity == 0.0)
            result = 1.0f - result;
        NiAVObject* effect = aTarget->GetObjectByName(NiFixedString("PipboyLightEffect"));
        if (!effect)
            effect = aTarget->GetObjectByName(NiFixedString("PipboyLightEffect:0"));
        NiNode* current = 0;
        if (effect)
            current = effect->IsSceneNode();
        if (current && current->FUN_00453470())
        {
            FadeGeometry* geometry = static_cast<FadeGeometry*>(current->GetAt(0)->IsGeometry());
            if (geometry)
            {
                NiProperty* property = geometry->GetProperty(FUN_004af350());
                if (property)
                    property->FUN_0068c9f0(result);
                else
                {
                    BSShaderProperty* shader = static_cast<BSShaderProperty*>(geometry->GetProperty(FUN_00438220()));
                    shader->SetAlpha(result);
                }
                geometry->FUN_00a5a040();
            }
        }
        if (result == m_fThirdPersonLightIntensity)
        {
            m_bPipBoyLightOn = false;
            if (m_fThirdPersonLightIntensity == 0.0)
                FUN_007fa310(false, false, false);
        }
    }
}

namespace fnv_007fa7a0 {
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};

extern TimeGlobal g_timeGlobal;

struct PipboyStub
{
    char m_auiShapeKeys[0x160];
    bool b1stPersonLightOn;  // 0x160
    char m_pad161;
    bool b3rdPersonLightOn;  // 0x162
    char m_pad163;
    float m_fFirstPersonLightIntensity;  // 0x164
    float m_fThirdPersonLightIntensity;  // 0x168
    void UpdatePipboyLight(bool b);
};

// @fnv 0x007fa7a0
void PipboyStub::UpdatePipboyLight(bool b)
{
    if (b1stPersonLightOn)
    {
        m_fFirstPersonLightIntensity = (float)g_timeGlobal.GetTimeStamp();
        b3rdPersonLightOn = true;
        if (b)
            m_fThirdPersonLightIntensity = 0.0f;
        else
            m_fThirdPersonLightIntensity = 1.0f;
    }
}
}  // namespace fnv_007fa7a0
