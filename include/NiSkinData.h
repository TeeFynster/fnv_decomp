#pragma once

#include "NiObject.h"
#include "NiTransform.h"
#include "GO.h"

class NiSkinPartition;
class NiPoint3;
struct SkinBoneData;
struct SkinMapContext;
struct SkinBoneContainer;

class NiSkinData : public NiObject
{
  public:
    union
    {
        struct
        {
            GO m_sp;
            NiTransform m_kSkinTransform;
            SkinBoneData* m_pBoneData;
            unsigned int m_uiBoneCount;
        };
        struct
        {
            SkinBoneContainer* bones;
            unsigned int unused;
            const char* root;
            const char** names;
        };
    };

    NiSkinData();
    virtual ~NiSkinData();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;

    unsigned int GetBoneCount();
    bool MapSkinData(SkinMapContext& context);
    bool Equals(NiSkinData* other);
    void NiSkinData_LinkObject(void* streamObject);
    void NiSkinData_LoadBinary(void* streamObject);
    void NiSkinData_SaveBinary(void* streamObject);
    void NiSkinData_ComputeBoneBounds(NiPoint3* vertices);
    void BaseCleanupA();
    void BaseCleanupB();
};
