#pragma once

#include "BSExtraData.h"

class RoomRefData;
class MagicItem;

class ExtraRoomRefData : public BSExtraData
{
public:
    virtual ~ExtraRoomRefData();
    virtual bool Compare(BSExtraData* apCompare);

    ExtraRoomRefData();
    void SetSelectedMagicItem(MagicItem* spell);

    void FUN_00420630();
    void* FUN_00420600(unsigned int flags);

    RoomRefData* pData;
};
