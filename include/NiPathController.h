#pragma once

#include "NiTimeController.h"

class StrArr;
class SpawnedArg;
class PositionKey;
class NiMatrix3;

class NiPathController : public NiTimeController
{
public:
    NiPathController();
    virtual ~NiPathController();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void Update(NiUpdateData& update);

    void AppendString(StrArr* strings);
    void ReadFromStream(NiStream* stream);
    void LoadFromStream(NiStream& stream);
    void SetSpawnedArgs(SpawnedArg* args);
    void FUN_00a6d500(SpawnedArg* args);
    NiPathController* CreatePathObject(int value);
    void CopyMembers_00a4b0b0(NiPathController* destination, void* cloning);
    void CopyMembers_00a4b0b0(NiPathController* destination, int cloning);
    bool IsEqual_00a4a710(NiObject* object);

    void* InvokeIndexedCallback(void* result, int first, int second, float time);
    void InvokeIndexedCallback(NiPoint3* result, int first, int second, float time);
    float GetKeyDerivativeLength(int first, int second, float time);
    float GetKeyDerivativeLength(unsigned int first, unsigned int second, float time);
    float PathLength(int first, int second, float scale);
    double PathLength(unsigned int first, unsigned int second, float scale);
    float GetTotalLength();
    void GetLengths(unsigned int* keys, unsigned int* count, int* type, unsigned char* stride);
    PositionKey* GetKeys(unsigned int& count, int& type, unsigned char& stride) const;
    void GetPercentLoc_00a4a980(float time, unsigned int* first, unsigned int* second, float* position);
    void GetPercentLoc_00a4a980(float time, unsigned int& first, unsigned int& second, float& position);
    void GetLoc(float time, int* first, int* second, float* position);
    void GetLoc(float time, unsigned int& first, unsigned int& second, float& position);
    void CalcRefFrame(int first, int second, float time, NiMatrix3* rotation);
    void CalcRefFrame(unsigned int first, unsigned int second, float time, NiMatrix3& rotation);
    void UpdatePathTarget(float* time);

    bool GetFollow() const;
    bool IsFollow() const;
    bool IsReverse() const;
    bool IsBank() const;
    bool IsFlag1() const;
    bool GetBit(int bit) const;
    void SetBit(bool value, unsigned short mask);
    void SetConstVelocity(bool value);

    union
    {
        unsigned short m_usFlags;
        unsigned short m_uiObjectFlags;
        unsigned short flags;
        unsigned short m34;
        unsigned short m_34;
    };
    unsigned short unk36;
    union
    {
        unsigned int lastIdx;
        int m38;
        int unk38;
    };
    union
    {
        unsigned int m_uiPercentKeyCount;
        int m3c;
        int unk3c;
    };
    NiPointer<NiTimeController> m_pPathObject;
    NiPointer<NiTimeController> m_pPathInterp;
    union
    {
        float* m_pfPathLengths;
        float* lengths;
        unsigned int* m_pkPartLengths;
        void* m48;
        int unk48;
    };
    union
    {
        float m_fTotalPathLength;
        float totalLength;
        float m4c;
        float m_4c;
        float unk4c;
    };
    union
    {
        float bankAngle;
        float m50;
        float unk50;
        unsigned int m_50;
    };
    union
    {
        float smoothing;
        float m54;
        float unk54;
        unsigned int m_54;
    };
    union
    {
        short axis;
        short unk58;
        unsigned short m58;
        unsigned short m_58;
    };
    short unk5a;
    union
    {
        float maxCurvature;
        float m5c;
        float m_5c;
        float unk5c;
    };
    union
    {
        int bankDirection;
        int m60;
        int unk60;
        unsigned int m_60;
    };
};
