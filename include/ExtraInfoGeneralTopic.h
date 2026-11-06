#pragma once

#include "BSExtraData.h"

namespace extra_save
{
class SForm;
}

class ExtraInfoGeneralTopic : public BSExtraData
{
public:
    ExtraInfoGeneralTopic(void* topic);
    virtual ~ExtraInfoGeneralTopic();

    void* FUN_00432440(unsigned int flags);

    extra_save::SForm* topic;
};
