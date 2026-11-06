#pragma once

#include "TESPackageData.h"

class TESForm;
class TESTopic;
class TargetLocation;
struct PairOfBytes;

class TESDialoguePackageData : public TESPackageData
{
public:
    TESDialoguePackageData();
    TESDialoguePackageData(float initial, unsigned int object, PairOfBytes flags, float scale,
                           unsigned char enabled, unsigned int reference);

    virtual ~TESDialoguePackageData();
    virtual void Copy(TESPatrolPackageData* source);
    virtual bool vf02(TESPackageData* other);
    virtual void vf03();
    virtual void InitItem(TESForm* item);
    virtual void SaveToBuffer(BGSSaveFormBuffer* buffer);
    virtual void vf06(BGSLoadFormBuffer* buffer);
    virtual void vf07(BGSLoadFormBuffer* buffer);

    float m_fFirstFloat;
    TESTopic* pMenuTopicEntry;
    TargetLocation* m_pTargetLocation;
    bool m_bFirstFlag;
    bool m_bFollowingFlag;
    float m_fFloatValue;
    bool m_bThirdFlag;
    int m_iTrailingValue;

    TESDialoguePackageData* Construct(float initial, unsigned int object, PairOfBytes flags, float scale,
                                      unsigned char enabled, unsigned int reference);
    bool FUN_0067b470(void* object);
    void SaveTopicData();
    void SavePackageData(BGSSaveFormBuffer* apSaveGameBuffer);
    void FUN_0067b7d0(BGSLoadFormBuffer* apLoadGameBuffer);
    void FUN_0067b920(BGSLoadFormBuffer* apLoadGameBuffer);
};
