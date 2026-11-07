#pragma once

#include "TESPackageData.h"

class FollowPackageField;

class TESFollowPackageData : public TESPackageData
{
public:
    TESFollowPackageData(float afValue);
    virtual ~TESFollowPackageData();
    virtual void Copy(TESPatrolPackageData* source);
    virtual bool vf02(TESPackageData* other);
    virtual void vf03();
    virtual void InitItem(TESForm* item);
    virtual void SaveToBuffer(BGSSaveFormBuffer* buffer);
    virtual void vf06(BGSLoadFormBuffer* buffer);
    virtual void vf07(BGSLoadFormBuffer* buffer);

    FollowPackageField* m_04;
    float m_08;

    TESFollowPackageData* Construct(float afValue);
    void* DestroyIfFlagged(unsigned int flags);
    void SaveFloatRecord();
    void FUN_0067c080();
    void Copy_0067c110(TESPackageData* other);
    bool Compare_0067c220(TESPackageData* arg);
};
