#pragma once

#include "SeenData.h"

class IntSeenData : public SeenData
{
public:
    signed char field_24;
    signed char field_25;
    unsigned short field_26;
    IntSeenData* field_28;

    IntSeenData();
    IntSeenData(char x, char y);
    IntSeenData(unsigned char x, unsigned char y);

    virtual ~IntSeenData();
    virtual void AddToNode(NiNode* pNode, NiPoint3& kPos, bool bFlag) override;
    virtual unsigned short GetSaveSize(bool abRecursing) override;
    virtual void SaveGame_0087a060(bool abRecursing) override;
    virtual void LoadGame(BGSLoadFormBuffer* buffer) override;
    virtual void LoadGame_0087a090(unsigned short count) override;

    void SaveToBuffer(BGSSaveFormBuffer* buffer);
    void* FUN_0087a140(unsigned int flags);
};
