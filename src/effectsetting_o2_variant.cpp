
// src/effectsetting_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/effectsetting.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../include/BaseFormComponent.h"
#include "../include/EffectSetting.h"
#include "../include/FileEntryList.h"
#include "../include/TESDescription.h"
#include "../include/TESEffectShader.h"
#include "../include/TESFile.h"
#include "../include/TESForm.h"
#include "../include/TESFullName.h"
#include "../include/TESIcon.h"
#include "../include/TESModel.h"
#include "../include/TESObjectLIGH.h"
#include "../include/TESSound.h"
#include "../include/TESTexture.h"

#include "effectsetting_decls.h"

struct BEB3890Body
{
    int unk00;
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
    float m_fBoundRadius;
};

static const float NI_INFINITY = 3.402823466e+38f;

class BEB3890Base
{
  public:
    BEB3890Base(float fA, float fB, float fC, int iD);
    virtual ~BEB3890Base();

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
};

class FUN_00eb3890_cls : public BEB3890Base
{
  public:
    FUN_00eb3890_cls(BEB3890Body* pkBodyA, BEB3890Body* pkBodyB, float fA, float fB, float fC, int iD);
    virtual ~FUN_00eb3890_cls();

    BEB3890Body* m_pkBodyA;
    BEB3890Body* m_pkBodyB;
    float m_fInvRadiusSq;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

// @fnv 0x00eb3890
FUN_00eb3890_cls::FUN_00eb3890_cls(BEB3890Body* pkBodyA, BEB3890Body* pkBodyB, float fA, float fB, float fC, int iD)
    : BEB3890Base(fA, fB, fC, iD), m_pkBodyA(pkBodyA), m_pkBodyB(pkBodyB)
{
    m_fInvRadiusSq = 1.0f / (pkBodyB->m_fBoundRadius * pkBodyB->m_fBoundRadius);
    m_fVectorY = NI_INFINITY;
    m_fVectorZ = NI_INFINITY;
    m_fScalarPart = NI_INFINITY;
}
