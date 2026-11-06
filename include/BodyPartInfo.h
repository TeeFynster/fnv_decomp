#pragma once

#include "NiPoint3.h"

class BGSDebris;
class BGSExplosion;
class BGSImpactDataSet;

class BodyPartInfo
{
public:
    BodyPartInfo();
    void SwapEndianFields();
    void Initialize();

    float m_fDamageMultiplier;
    unsigned char cFlags;
    unsigned char cType;
    unsigned char m_ucPartID;
    char m_cActorValue;
    unsigned char m_ucHealthPercent;
    unsigned char m_ucHitChance;
    unsigned char m_ucLimbReplacementType;
    unsigned char layoutPaddingB[1];
    BGSDebris* m_pExplosion;
    BGSExplosion* m_pDebrisObject;
    float m_fExplosionChance;
    float m_fDebrisScale;
    unsigned char m_ucSeverable;
    unsigned char layoutPadding1D[3];
    BGSDebris* m_pRelatedObject1;
    BGSExplosion* m_pRelatedObject2;
    float m_fValue3;
    NiPoint3 m_kPoint1;
    NiPoint3 m_kPoint2;
    BGSImpactDataSet* m_pRelatedObject3;
    BGSImpactDataSet* m_pRelatedObject4;
    unsigned char m_ucByte1;
    unsigned char m_ucByte2;
    unsigned char layoutPadding4E[2];
    float m_fValue4;
};
