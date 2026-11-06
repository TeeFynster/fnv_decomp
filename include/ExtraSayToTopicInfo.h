#pragma once

#include "BSExtraData.h"

class TESTopic;
class TESTopicInfo;

struct ExtraSayToTopicInfo : public BSExtraData
{
public:
    ExtraSayToTopicInfo();
    ExtraSayToTopicInfo(TESTopicInfo*);
    ExtraSayToTopicInfo(int);
    virtual ~ExtraSayToTopicInfo();

    void __vslot_0();
    void SetTopic(TESTopic*);
    void SetVoiceDone(bool);

    TESTopicInfo* pInfo;
    TESTopic* pTopic;
    unsigned int m_uiTopicInfoValue;
    bool m_bTopicInfoFlag;
    char _pad_19[3];
};
