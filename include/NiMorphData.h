#pragma once

#include "NiObject.h"
#include "NiMemObject.h"
#include "NiFixedString.h"
#include "NiAVObject.h"

class NiPoint3;
class NiInterpolator;

class NiMorphData : public NiObject
{
  public:
    class MorphTarget : public NiMemObject
    {
      public:
        NiPoint3* m_pkVertexPositions;
        NiFixedString m_kName;
        float m_fMorphWeight;
        NiPointer<NiInterpolator> m_spTargetInterpolator;

        const NiFixedString& GetName();
        void SetTargetInterpolator(NiInterpolator*);
    };

    virtual ~NiMorphData();

    MorphTarget* GetTarget(unsigned int uiIndex) const;

    unsigned int m_uiNumTargets;
    unsigned int m_uiNumVertsPerTarget;
    MorphTarget* m_pMorphTargets;
    bool m_bTargetsAreRelative;
    unsigned char m_aucPad[3];
};
