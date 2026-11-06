#pragma once

#include "BaseFormComponent.h"

namespace ActorValue
{
    enum Index;
}

class BGSSaveFormBuffer;
class BGSLoadFormBuffer;

class TESAttributes : public BaseFormComponent
{
public:
    TESAttributes();
    ~TESAttributes();
    TESAttributes& operator=(const TESAttributes& other);

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    unsigned int Save(void* buffer);
    unsigned int Load(void* buffer);
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    unsigned int GetAttributeDataSize();
    unsigned char GetAttributeValue(int index);
    unsigned char GetAttributeValue(ActorValue::Index index);
    void SetAttributeValue(int index, unsigned char value, bool force);
    void SetAttributeValue(ActorValue::Index index, unsigned char value, bool force);
    void SetAttributeValue(unsigned char index, unsigned char value, bool force);
    void SetAttributeValue(unsigned int index, unsigned char value, bool force);
    void SetAttribute(unsigned char index);
    unsigned char GetAttributeStrength();
    unsigned char GetPerception();
    unsigned char GetEndurance();
    unsigned char GetCharisma();
    unsigned char GetIntelligence();
    unsigned char GetAgility();
    unsigned char GetLuck();
    unsigned char GetAttributeValue5();
    unsigned char GetAttributeValue7();
    unsigned char GetAttributeValue10();
    void SetStrength(unsigned char value);
    void SetPerception(unsigned char value);
    void SetEndurance(unsigned char value);
    void SetCharisma(unsigned char value);
    void SetIntelligence(unsigned char value);
    void SetAgility(unsigned char value);
    void SetLuck(unsigned char value);
    unsigned short GetSaveSize(unsigned int flags);
    void SaveGame(BGSSaveFormBuffer* buffer);
    void SaveGame(unsigned int buffer);
    void LoadGame(BGSLoadFormBuffer* buffer);
    void LoadGame(unsigned int buffer, unsigned int flags);
    void LoadDataIfChanged(BGSLoadFormBuffer* buffer);


    unsigned char cAttribute[7];
    unsigned char layoutPaddingB[1];
};
