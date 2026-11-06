#pragma once

#include "BSExtraData.h"
#include "ActorPackageData.h"

class ExtraPackageData : public BSExtraData
{
public:
    virtual ~ExtraPackageData();

    ExtraPackageData(ActorPackageData*);

    ActorPackageData* m_pActorPackageData;
};
