#pragma once

#include "DummyPointerMap.h"
#include "BSSimpleArray.h"

class BGSTerrainNode;

#pragma pack(push, 1)
class BGSDistantTreeBlock
{
public:
    class InstanceData;

    // Exe 0x006f91a0: array at +4, pointer buffer at +8 and count at +0xC.
    typedef BSSimpleArray<InstanceData*> TreeArray;
    // Exe 0x006f9300 / 0x006f7780: full 16-byte ID array at +0x34 (block extent 0x44), BSSimpleArray::Clear(true).
    typedef BSSimpleArray<unsigned int> TreeIndexArray;

    int unk00;
    TreeArray arr;
    DummyPointerMap map;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    TreeIndexArray mArray;

    BGSDistantTreeBlock(BGSTerrainNode* pNode, unsigned int uiTreeBlockIndex,
                        unsigned short sX, unsigned short sY);
    ~BGSDistantTreeBlock();

    bool IsLoaded();
    void Prepare();
    void Attach();
    void MarkTreeInstance(unsigned int);
    void MarkTreeInstance(unsigned int aID, bool update);
    void ClearInstanceFlag(unsigned int aID);
    void BGSDistantTreeBlock_ClearQueuedTrees();
    void ProcessAllTrees();
};
#pragma pack(pop)
