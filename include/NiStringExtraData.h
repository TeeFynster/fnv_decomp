#pragma once

#include "NiExtraData.h"

#pragma pack(push, 1)
class NiStringExtraData : public NiExtraData
{
  public:
    virtual ~NiStringExtraData();
    virtual void SaveBinary(NiStream& stream);

    const NiFixedString& GetString();
    virtual bool IsEqual(NiObject* other) const;
    char BSXFlags_IsEqual(const char* other);
    void SaveBinary_00a74200(NiStream& stream);

    union
    {
        char m_kStringBuffer[1];
        char* m_p;
    };
    unsigned char unk10[0x25];
};
#pragma pack(pop)
