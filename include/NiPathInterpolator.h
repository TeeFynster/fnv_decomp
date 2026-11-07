#pragma once

#include "NiKeyBasedInterpolator.h"
#include "NiQuaternion.h"
#include "NiPoint3.h"

class NiPosData;
class NiFloatData;
class PositionKeyInterpolator;
class NiMatrix3;
class StrArr;

class NiPathInterpolator : public NiKeyBasedInterpolator
{
  public:
    NiPathInterpolator(NiPosData* pkPathData = 0, NiFloatData* pkPctData = 0);
    virtual ~NiPathInterpolator();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual void ProcessClone(CloningProcess& arCloning);
    virtual bool UpdateTransform(float afTime, NiObjectNET* apTarget, NiQuatTransform& arValue);
    virtual void GetInterpolatorTimeRange(float& arBeginKeyTime, float& arEndKeyTime) const;
    virtual void SetActiveTimeRange(float afStartTime, float afEndTime);
    virtual NiInterpolator* CloneForTimeRange(float afStartTime, float afEndTime);
    virtual unsigned short GetKeyChannelCount() const;
    virtual unsigned int GetColorKeyCount(unsigned short usChannel) const;
    virtual void vf57();
    virtual void vf58();
    virtual NiAnimationKey* GetChannelKeys(unsigned short usChannel) const;
    virtual unsigned char GetColorKeySize(unsigned short usChannel) const;
    virtual void vf61(unsigned short usChannel);

    void GuaranteeTimeRange_00a3dc50(float m_fStartTime, float m_fMaximumDistance);
    void* GetKeyCount(short idx);
    int GetValueByIndex(short arg);
    int GetKeyArray(short arg);
    char GetKeyStride(unsigned short arg);
    int GetChannelIndex(unsigned short usChannel);
    void* GenPathInterp(void* pData, int i1, int i2, float fTime);
    NiPoint3 GenPathInterp(int i1, int i2, float fTime);
    void ProcessClone_00a3dc80(CloningProcess& kCloning);
    bool RegisterStreamables_00a3dcc0(void* pkStream);
    void GetRange(float* pfMin, float* pfMax);
    void ReadFromStream(NiStream* source);
    void WriteToStream(NiStream* pStream);
    void AppendString(StrArr* pkStrings);
    void CopyMemberData(NiPathInterpolator* pDest, CloningProcess& kCloning);
    void CopyMembers_00a3f2f0(NiPathInterpolator* pDest, CloningProcess& kCloning);
    void LinkObject_00a3ee80(NiStream& stream);
    bool IsEqual_00a3e7b0(NiObject* pkObject);
    bool BaseIsEqual(NiObject* pkObject);
    bool PartialLengthsEqual(NiPathInterpolator* pkPath);
    int GetPathKeys(int& uiNumKeys, int& eType, char& ucSize);
    PositionKeyInterpolator* GetPathKeys(unsigned int& count, unsigned int& type,
        unsigned char& stride) const;
    float CalcTotalLength();
    float GetAccumulatedValue();
    float NiPathInterpolator_PathLength(int i1, int i2, float t);
    float SampleLength(int i1, int i2, float t);
    void GetPercentLoc(float fTime, unsigned int& i1, unsigned int& i2, float& fNormTime);
    void FindKeyPair(float fTime, unsigned int& i1, unsigned int& i2, float& fNormTime);
    void FindKeyPair(float fTime, int& i1, int& i2, float& fNormTime);
    void EvaluateBasis(int i1, int i2, float fTime, NiMatrix3& kRot);
    void EvaluateBasis(unsigned int first, unsigned int second, float time,
        NiMatrix3* out);
    void SetBit(bool bVal, unsigned short uMask);
    bool GetBit(unsigned short uMask) const;
    unsigned short GetField(unsigned short uMask, unsigned short uPos) const;
    void SetConstVelocity(bool b);
    bool GetConstVelocity() const;
    bool GetCVDataNeedsUpdate() const;
    void SetCVDataNeedsUpdate(bool value);
    bool GetFollow() const;
    bool TimeHasChanged(float fTime) const;

    unsigned short m_uiObjectFlags;
    unsigned short unk0E;
    union
    {
        unsigned int m_uiPathKeyCount;
        int unk10;
    };
    union
    {
        unsigned int m_uiPercentKeyCount;
        int unk14;
    };
    NiPosData* m_pPathObject;
    void* m_pPathInterp;
    float* m_pfPathLengths;
    float m_fTotalPathLength;
    float m_fPreviousTime;
    float m_fLastPercent;
    short m_sLastPathIndex;
    short unk32;
    union
    {
        float m_fPathLength;
        int unk34;
    };
    int m_iPathPointCount;
    NiQuaternion m_kRotationMatrix;
    NiPoint3 m_kPathOffset;
    union
    {
        float m_fLast;
        float m_fZValue;
    };
};
