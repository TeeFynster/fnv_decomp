#pragma once

#include "NiPSysFieldModifier.h"
#include "NiColor.h"
#include "NiPoint3.h"

class NiPSysGravityFieldModifier : public NiPSysFieldModifier
{
public:
    NiPSysGravityFieldModifier();
    virtual ~NiPSysGravityFieldModifier();

    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void Update(float time, NiPSysData* data);

    char IsEqual_00c26db0(NiPSysGravityFieldModifier* other);
    void FUN_00c267f0(NiStream& stream);
    void* DestroyIfFlagged(unsigned int flags);
    NiPSysGravityFieldModifier* Ctor();
    void ApplyGravityToParticles(float time, NiPSysData* data);
    void ApplyForceToParticles(float time, NiPSysData* data);

    union
    {
        struct
        {
            int unk30;
            int unk34;
            int unk38;
        };
        struct { NiPoint3 originalDirection; };
        struct { NiPoint3 m_kDirection; };
        struct { NiPoint3 m_kLightVector; };
    };
    union
    {
        struct
        {
            int unk3C;
            NiColor m_kFogTint;
        };
        struct { NiPoint3 normalizedDirection; };
        struct { NiPoint3 m_kUnitDirection; };
    };
    int unk4C;
    int unk50;
    int unk54;
    float m_f58;
    float m_f5C;
    bool m_b60;
    bool m_b61;
    bool m_b62;
    unsigned char unk63;
    float m_f64;
};
