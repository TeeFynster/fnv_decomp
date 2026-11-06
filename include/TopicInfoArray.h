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
    unsigned int FUN_005be5c0(int a);
    unsigned int FUN_005de0f0(unsigned int index);
    Actor *FUN_00968670(unsigned int index);
};
