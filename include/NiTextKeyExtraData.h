#pragma once

#include "NiExtraData.h"

class TimedTextEntry;

class NiTextKeyExtraData : public NiExtraData
{
  public:
    virtual ~NiTextKeyExtraData();

    TimedTextEntry* GetKeys(unsigned int& uiNumKeys) const;
    TimedTextEntry* GetKeys(unsigned int* uiNumKeys);
    TimedTextEntry* GetKeys_00495f30(unsigned int* uiNumKeys);

    unsigned int m_uiNumKeys;
    TimedTextEntry* m_pKeys;
};
