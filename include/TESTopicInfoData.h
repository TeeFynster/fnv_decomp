#pragma once

#include "MagicTarget.h"

class TESForm;
class TESTopic;
class TESTopicInfo;

class TESTopicInfoData
{
public:
    BSSimpleList<TESTopic*> m_kLinkFromList;
    BSSimpleList<TESTopic*> m_kLinkToList;
    BSSimpleList<TESTopicInfo*> m_kFollowUpInfoList;

    TESTopicInfoData();
    ~TESTopicInfoData();
    BSSimpleList<TESTopic*>* GetLinkFromList();
    void InitItem(TESForm* owner);
    void Copy(TESTopicInfo* info, TESTopicInfoData* data);
    BSSimpleList<TESTopic*>* GetLinkToList();
    BSSimpleList<TESTopicInfo*>* GetFollowUpInfoList();
};
