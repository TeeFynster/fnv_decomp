#pragma once

#include "BaseFormComponent.h"

class Actor;
class TESFile;
class TESForm;
class TESIdleForm;
class TESObjectREFR;
template <class T, unsigned int N> class BSSimpleArray;

class BGSIdleCollection : public BaseFormComponent
{
public:
    BGSIdleCollection();  // 0x00479790: BaseFormComponent(), vftable 0x0101aa98, InitializeComponent()
    ~BGSIdleCollection();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    unsigned int GetAvailableIdles(Actor* actor, TESObjectREFR* target,
                                   BSSimpleArray<TESIdleForm*, 1024>* idles);
    void Load(TESFile* file);
    void InitializeComponent();
    void InitItem(TESForm* form);
    void RemoveIdleEntry(unsigned int index);
    int GetPickType();

    unsigned char m_ucIdleCount;
    unsigned char m_ucPickType;
    unsigned char layoutPadding6[2];
    TESIdleForm** m_ppIdleForms;
    float m_fIdleChance;
};
