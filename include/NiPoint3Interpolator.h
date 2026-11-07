#pragma once

#include "NiKeyBasedInterpolator.h"
#include "NiPoint3.h"

class NiPosData;
class StateNode;
class ImageSpaceModifierInstanceDOF;
class TESBoundObject;
class ExtraDataList;

class NiPoint3Interpolator : public NiKeyBasedInterpolator
{
  public:
    NiPoint3Interpolator() throw();
    NiPoint3Interpolator(NiPosData* pkPosData);
    NiPoint3Interpolator(NiPoint3 kPoseValue) throw();
    virtual ~NiPoint3Interpolator();
    NiPoint3Interpolator& operator=(const NiPoint3Interpolator&);

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual bool UpdatePoint3(float time, NiObjectNET* target, NiPoint3& value);
    virtual bool IsPoint3ValueSupported() const;
    virtual void Collapse();
    virtual void SetActiveTimeRange(float afStartTime, float afEndTime);
    virtual NiInterpolator* CloneForTimeRange(float afStartTime, float afEndTime);

    virtual unsigned short GetKeyChannelCount() const;
    virtual unsigned int GetColorKeyCount(unsigned short usChannel) const;
    virtual void vf57();
    virtual void vf58();
    virtual NiAnimationKey* GetChannelKeys(unsigned short usChannel) const;
    virtual unsigned char GetColorKeySize(unsigned short usChannel) const;
    virtual void vf61(unsigned short usChannel);

    bool Update(float time, NiObjectNET* target, NiPoint3& value);
    void CreateObject(int mode, bool force);
    void CopyMemberData(NiPoint3Interpolator* pkDest, CloningProcess& kCloning);
    void CopyMemberData(NiPoint3Interpolator* pkDest, void* pvCloning);
    void CloneTo(NiPoint3Interpolator* pkDest, CloningProcess& kCloning);
    NiPoint3Interpolator* CreateClone_00a49b30(void* pvCloning);
    NiPoint3Interpolator* CreateRangeInterpolator(float startTime, float endTime);
    void CollapseConstantPosData();
    void SetPoseValue(NiPoint3 value);

    union
    {
        struct
        {
            NiPoint3 m_kValue;
            NiPosData* m_spPosData;
            unsigned int m_uiLastKeyIndex;
        };
        struct
        {
            void* state0c;
            StateNode* state10;
            float state14;
            float state18;
            int state1c;
            int state20;
            int state24;
            ImageSpaceModifierInstanceDOF* state28;
            ImageSpaceModifierInstanceDOF* state2c;
            int state30;
            int state34;
            bool state38;
            char pad39[3];
            int state3c;
            TESBoundObject* state40;
            ExtraDataList* state44;
        };
    };
};
