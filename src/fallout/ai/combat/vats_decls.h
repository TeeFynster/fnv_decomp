// fallout/ai/combat/vats_decls.h: declares Animation, TimeGlobal, PlayerCharacter, CameraPathManager, BGSCameraShot and more
#ifndef FNV_VATS_DECLS_H
#define FNV_VATS_DECLS_H


#include "layout_support.h"

class VATSCommand;
class Projectile;
class TESIdleForm;
class ImageSpaceModifierInstanceForm;
class ImageSpaceModifierInstanceRB;
class ShadowSceneLight;

class Animation
{
  public:
    void Animation_SetGlobalTimeMultiplier(float);
};

class TimeGlobal
{
  public:
    void ApplyGlobalTimeMultiplier();
};

// PC receiver view for the legacy VATS::Update identity. Its caller passes
// PlayerCharacter; the last write is at +0xE18 in the PC player layout.
class PlayerCharacter
{
  public:
    unsigned char layoutPadding0[0xE18];
    float fVATSTimer;
    unsigned char layoutPaddingE1C[0x34];
    bool PlayerCharacter_Is3rdPerson();
    Animation* GetAnimation(bool firstPerson);
    static bool UpdatePlayerStatus();
};
typedef char VATSPlayerTimerOffsetCheck[offsetof(PlayerCharacter, fVATSTimer) == 0xE18 ? 1 : -1];
typedef char VATSPlayerSizeCheck[sizeof(PlayerCharacter) == 0xE50 ? 1 : -1];

class CameraPathManager
{
  public:
    void SetCameraPathEnabled(bool enabled, unsigned int mask);
};
class InventoryStackRecord
{
  public:
    void SetEquipmentState(bool immediate, bool force);
};
class BGSCameraShot
{
  public:
    void ResetCameraShot();
    bool IsInitialized();
    float TESCombatStyle_GetTargetingFOV();
    char _pdbpad_1[55];
    char Data_pad37_pad37_pad37[40];
    char spLocationNode_pad5f_pad5f_pad5f[4];
    char spTargetNode_pad63_pad63_pad63[4];
    void* m_pReference;
    char m_spPositionNode[4];
    char m_pSceneObject[4];
    char m_bUpdateNodePosition;
    bool m_bFlag74;
    bool m_bFlag75;
    char _pdbpad_77[1];
};
class NiPoint3Interpolator
{
  public:
    void CreateObject(int mode, bool force);
};

class VATS
{
  public:
    BSSimpleList<VATSCommand*> m_kCommandList;
    int eMode;
    BSSimpleList<BGSCameraShot*>* m_pCameraShotList;
    BGSCameraShot* pCamera;
    float m_fCameraTime;
    float m_fCameraDuration;
    Projectile* m_pSource;
    Projectile* m_pTargetProjectile;
    TESIdleForm* m_pIdleForm;
    ImageSpaceModifierInstanceForm* m_pImagespaceModifier;
    ImageSpaceModifierInstanceRB* pTransitionImagespaceMod;
    bool bIsPlayer;
    unsigned char layoutPadding31[3];
    NiPointer<ShadowSceneLight> m_spShadowSceneLight;
    bool m_bShadowLightEnabled;
    unsigned char layoutPadding39[3];
    int m_iShadowLightState;
    TESBoundObject* m_pCurrentWeaponObject;
    ExtraDataList* m_pWeaponExtraData;
    void Update(int mode, bool force);
    float GetModeTimeMultiplier();
};
FNV_STATIC_ASSERT(sizeof(VATS) == 0x48);
FNV_STATIC_ASSERT(offsetof(VATS, eMode) == 8);
FNV_STATIC_ASSERT(offsetof(VATS, pCamera) == 0x10);

union SETTING_VALUE
{
  public:
    const char* str;
    int i;
    unsigned int u;
    float f;
    bool b;
    char c;
    unsigned char h;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
class hkpCharacterContext
{
  public:
    static float GetReferenceTimeStep();
};
float BSTimer_QGlobalTimeMultiplierTarget();

extern TimeGlobal g_timeGlobal;
extern PlayerCharacter* g_thePlayer;
extern VATS DAT_011f2250;
extern bool DAT_011f21d0;
extern SettingT_GameSettingCollection_ DAT_011cf374;

#endif
