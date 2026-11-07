#pragma once

#include "BSExtraData.h"

class ActorValueInfo;
class ExtraRecordData;

class ExtraAudioBuoyMarker : public BSExtraData
{
public:
    ExtraAudioBuoyMarker(ExtraRecordData* apData);
    virtual ~ExtraAudioBuoyMarker();

    bool Compare(BSExtraData* extra) override;
    bool Compare_00431710(BSExtraData* apCompare);

    union
    {
        int unk0C;
        ActorValueInfo* m_pActorValueInfo;
        ExtraRecordData* pData;
    };
};
