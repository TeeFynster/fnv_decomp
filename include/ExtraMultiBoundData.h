#pragma once

#include "BSExtraData.h"

class Point3Offset;

class ExtraMultiBoundData : public BSExtraData
{
public:
    virtual ~ExtraMultiBoundData();
    virtual bool Compare(BSExtraData* extra);

    ExtraMultiBoundData();

    Point3Offset* pBound;
};
