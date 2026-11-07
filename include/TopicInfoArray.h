#pragma once

#include "NiTLargePrimitiveArray.h"

class Actor;
class TESTopicInfo;

class TopicInfoArray : public NiTLargePrimitiveArray<TESTopicInfo *>
{
public:
    TopicInfoArray();
    virtual ~TopicInfoArray();

    void InsertInfoAt(unsigned int index, TESTopicInfo *info);
    unsigned int ProcessArray_GetProcessLevelTail(int a);
    unsigned int ProcessArray_GetProcessLevelHead(unsigned int index);
    Actor *ProcessArray_GetItem(unsigned int index);
};
