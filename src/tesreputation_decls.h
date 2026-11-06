// tesreputation_decls.h: local TESReputation and loader declarations
#ifndef FNV_REPUTATION_LOCAL_H
#define FNV_REPUTATION_LOCAL_H

#include "TESForm.h"
#include "TESFullName.h"
#include "TESIcon.h"
#include "TESFile.h"
#include "../include/BGSMessageIcon.h"
#include "../include/ReputationLimitData.h"

// Retained locally: the shared GetReputationRank returns int, but the function
// at 0x00616950 returns unsigned char. It also lacks the message and change methods.
enum ReputationType
{
    ReputationType_REPUTATION_NEGATIVE = 0,
    ReputationType_REPUTATION_POSITIVE = 1
};

class TESReputation : public TESForm, public TESFullName, public TESIcon, public BGSMessageIcon
{
  public:
    ReputationLimitData data;
    float m_fFirstReputationValue;
    float m_fSecondReputationValue;
    ReputationType m_eReputationType;
    virtual void ResetFormData();
    virtual bool Load(TESFile* file);
    void ReadTypedData(TESFile* file, void* buffer, unsigned short size);
    float GetUnsignedIntegerPointer(ReputationType type);
    static unsigned int* GetUnsignedIntegerPointer(unsigned int* value);
};

class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* component, TESFile* file);
};
class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture* component, TESFile* file);
};
FNV_STATIC_ASSERT(sizeof(TESReputation) == 80);
FNV_STATIC_ASSERT(offsetof(TESReputation, data) == 64);
FNV_STATIC_ASSERT(offsetof(TESReputation, m_fFirstReputationValue) == 68);
FNV_STATIC_ASSERT(offsetof(TESReputation, m_fSecondReputationValue) == 72);
FNV_STATIC_ASSERT(offsetof(TESReputation, m_eReputationType) == 76);
#endif
