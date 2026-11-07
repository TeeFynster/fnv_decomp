#pragma once

enum BS_FACEGEN_MORPH_TYPE;

class BSFaceGenKeyframe
{
public:
    BSFaceGenKeyframe(BS_FACEGEN_MORPH_TYPE type);
    virtual ~BSFaceGenKeyframe();
    virtual void UnknownSlot1() = 0;
    virtual bool SetType(BS_FACEGEN_MORPH_TYPE type);
    virtual float vfn_0c();
    virtual bool vfn_10(float time);
    virtual void UnknownSlot5() = 0;
    virtual void UnknownSlot6() = 0;
    virtual void UnknownSlot7() = 0;
    virtual bool ClearData(bool initialize);
    virtual void UnknownSlot9() = 0;
    virtual void UnknownSlot10() = 0;
    virtual bool vfn_2c(BSFaceGenKeyframe* keyframe);
    virtual float GetAttributeStrength();
    virtual void UnknownSlot13() = 0;
    virtual void NormalizeFaceGenValues();
    virtual void UnknownSlot15() = 0;
    virtual bool HasNonzeroQuantity();
    virtual void UnknownSlot17() = 0;
    virtual void UnknownSlot18() = 0;

    float GetTime();
    bool SetTime(float time);
    double ActorPackage_GetPackageStartTime();
    bool FUN_006828a0(float fArg);
    bool BSTempEffectDebris_Update(float fArg);

    BS_FACEGEN_MORPH_TYPE eType;
    float fTime;
};
