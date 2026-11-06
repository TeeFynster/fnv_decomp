#pragma once

#include "FinishingFlag.h"

class hkpConstraintAtom
{
public:
    enum AtomType
    {
        TYPE_INVALID = 0,
        TYPE_BRIDGE = 1,
        TYPE_SET_LOCAL_TRANSFORMS = 2,
        TYPE_SET_LOCAL_TRANSLATIONS = 3,
        TYPE_SET_LOCAL_ROTATIONS = 4,
        TYPE_BALL_SOCKET = 5,
        TYPE_STIFF_SPRING = 6,
        TYPE_LIN = 7,
        TYPE_LIN_SOFT = 8,
        TYPE_LIN_LIMIT = 9,
        TYPE_LIN_FRICTION = 10,
        TYPE_LIN_MOTOR = 11,
        TYPE_2D_ANG = 12,
        TYPE_ANG = 13,
        TYPE_ANG_LIMIT = 14,
        TYPE_TWIST_LIMIT = 15,
        TYPE_CONE_LIMIT = 16,
        TYPE_ANG_FRICTION = 17,
        TYPE_ANG_MOTOR = 18,
        TYPE_RAGDOLL_MOTOR = 19,
        TYPE_PULLEY = 20,
        TYPE_OVERWRITE_PIVOT = 21,
        TYPE_CONTACT = 22,
        TYPE_MODIFIER_SOFT_CONTACT = 23,
        TYPE_MODIFIER_MASS_CHANGER = 24,
        TYPE_MODIFIER_VISCOUS_SURFACE = 25,
        TYPE_MODIFIER_MOVING_SURFACE = 26,
        TYPE_MODIFIER_IGNORE_CONSTRAINT = 27,
        TYPE_MODIFIER_CENTER_OF_MASS_CHANGER = 28,
        TYPE_MAX = 29
    };

    enum CallbackRequest
    {
        CALLBACK_REQUEST_NONE = 0,
        CALLBACK_REQUEST_NEW_CONTACT_POINT = 1,
        CALLBACK_REQUEST_SETUP_PPU_ONLY = 2,
        CALLBACK_REQUEST_SETUP_CALLBACK = 4,
        CALLBACK_REQUEST_CONTACT_POINT_CALLBACK = 8
    };

    enum Type
    {
        INVALID = 0,
        BRIDGE = 1,
        SET_LOCAL_TRANSFORMS = 2,
        SET_LOCAL_TRANSLATIONS = 3,
        SET_LOCAL_ROTATIONS = 4,
        BALL_SOCKET = 5,
        STIFF_SPRING = 6,
        LIN = 7,
        LIN_SOFT = 8,
        LIN_LIMIT = 9,
        LIN_FRICTION = 10,
        LIN_MOTOR = 11,
        ANG_2D = 12,
        ANG = 13,
        ANG_LIMIT = 14,
        TWIST_LIMIT = 15,
        CONE_LIMIT = 16,
        ANG_FRICTION = 17,
        ANG_MOTOR = 18,
        RAGDOLL_MOTOR = 19,
        PULLEY = 20,
        RACK_AND_PINION = 21,
        CONTACT = 22,
        MODIFIER_SOFT_CONTACT = 23,
        MODIFIER_MASS_CHANGER = 24,
        MODIFIER_VISCOUS_SURFACE = 25,
        MODIFIER_MOVING_SURFACE = 26,
        MODIFIER_IGNORE = 27
    };

    __forceinline AtomType getType() const;
    hkpConstraintAtom(FinishingFlag f);

    unsigned short m_type;

protected:
    hkpConstraintAtom(AtomType type);

private:
    hkpConstraintAtom();
};
