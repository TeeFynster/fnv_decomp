#pragma once

#include <stddef.h>

enum BGSCameraShot__CAM_ACTION
{
    BGSCameraShot__CAM_ACTION_CA_SHOOT = 0,
    BGSCameraShot__CAM_ACTION_CA_FLY = 1,
    BGSCameraShot__CAM_ACTION_CA_HIT = 2,
    BGSCameraShot__CAM_ACTION_CA_ZOOM = 3,
    BGSCameraShot__CAM_ACTION_CA_COUNT = 4
};

enum BGSCameraShot__CAM_OBJECT
{
    BGSCameraShot__CAM_OBJECT_CO_ATTACKER = 0,
    BGSCameraShot__CAM_OBJECT_CO_PROJECTILE = 1,
    BGSCameraShot__CAM_OBJECT_CO_TARGET = 2,
    BGSCameraShot__CAM_OBJECT_CO_COUNT = 3
};

class BGSCameraShot__CAMERA_SHOT_DATA
{
public:
    void ProcessState_0058c3c0();

    BGSCameraShot__CAM_ACTION m_eAction;
    BGSCameraShot__CAM_OBJECT pInputFile;
    BGSCameraShot__CAM_OBJECT m_eAttacker;
    unsigned int iFlags;
    float m_fMinTime;
    float m_fTargetPercent;
    float m_fTimeMultiplier;
    float fMaxTime;
    float m_fCameraValue1;
    float m_fCameraValue2;
};

typedef char BGSCameraShotCameraShotDataSizeCheck[(sizeof(BGSCameraShot__CAMERA_SHOT_DATA) == 40) ? 1 : -1];
typedef char BGSCameraShotCameraShotDataActionCheck[(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_eAction) == 0) ? 1 : -1];
typedef char BGSCameraShotCameraShotDataInputFileCheck[(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, pInputFile) == 4) ? 1 : -1];
typedef char BGSCameraShotCameraShotDataAttackerCheck[(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_eAttacker) == 8) ? 1 : -1];
typedef char BGSCameraShotCameraShotDataFlagsCheck[(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, iFlags) == 12) ? 1 : -1];
typedef char BGSCameraShotCameraShotDataMinTimeCheck[(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_fMinTime) == 16) ? 1 : -1];
typedef char BGSCameraShotCameraShotDataTargetPercentCheck[(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_fTargetPercent) == 20) ? 1 : -1];
typedef char BGSCameraShotCameraShotDataTimeMultiplierCheck[(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_fTimeMultiplier) == 24) ? 1 : -1];
typedef char BGSCameraShotCameraShotDataMaxTimeCheck[(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, fMaxTime) == 28) ? 1 : -1];
typedef char BGSCameraShotCameraShotDataCameraValue1Check[(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_fCameraValue1) == 32) ? 1 : -1];
typedef char BGSCameraShotCameraShotDataCameraValue2Check[(offsetof(BGSCameraShot__CAMERA_SHOT_DATA, m_fCameraValue2) == 36) ? 1 : -1];
