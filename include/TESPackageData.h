#pragma once

class BGSSaveFormBuffer;
class BGSLoadFormBuffer;
class TESForm;
class TESPatrolPackageData;

class TESPackageData
{
public:
    TESPackageData();
    virtual ~TESPackageData();
    virtual void Copy(TESPatrolPackageData* source);
    virtual bool vf02(TESPackageData* other);
    virtual void vf03();
    virtual void InitItem(TESForm* item);
    virtual void SaveToBuffer(BGSSaveFormBuffer* buffer);
    virtual void vf06(BGSLoadFormBuffer* buffer);
    virtual void vf07(BGSLoadFormBuffer* buffer);

    void Save(int);
};
