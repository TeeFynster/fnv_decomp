#pragma once

#include "hkReferencedObject.h"
#include "hkStringPtr.h"
#include "hkaAnimation.h"

class hkpFirstPersonGun : public hkReferencedObject
{
public:
    enum Type
    {
        WEAPON_TYPE_INVALID = 0,
        WEAPON_TYPE_BALLGUN = 1,
        WEAPON_TYPE_GRENADEGUN = 2,
        WEAPON_TYPE_GRAVITYGUN = 3,
        WEAPON_TYPE_MOUNTEDBALLGUN = 4,
        WEAPON_TYPE_TWEAKERGUN = 5,
        WEAPON_TYPE_MISSILEGUN = 6,
        WEAPON_TYPE_RAYCASTGUN = 7,
        WEAPON_TYPE_SPHEREGUN = 8,
        WEAPON_TYPE_STICKYGUN = 9,
        WEAPON_TYPE_NUM_TYPES = 10
    };

    enum KeyboardKey
    {
        KEY_F1 = 112,
        KEY_F2 = 113,
        KEY_F3 = 114,
        KEY_F4 = 115,
        KEY_F5 = 116,
        KEY_F6 = 117,
        KEY_F7 = 118,
        KEY_F8 = 119,
        KEY_F9 = 120,
        KEY_F10 = 121,
        KEY_F11 = 122,
        KEY_F12 = 123
    };

    hkpFirstPersonGun() throw();
    hkpFirstPersonGun(FinishingFlag);
    hkpFirstPersonGun(void* pkWorld);
    virtual ~hkpFirstPersonGun() throw();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();

    unsigned char m_type;
    char pad9[3];
    hkStringPtr m_name;
    unsigned char m_uiKeyboardKey;
    char pad11[3];
    hkArray<void*> m_kListeners;
};
