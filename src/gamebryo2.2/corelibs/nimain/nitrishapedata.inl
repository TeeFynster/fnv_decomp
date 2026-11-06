
class NiTriShapeData__SNAMemBlock {
public:
    NiTriShapeData__SNAMemBlock();
    unsigned short* m_pIndices;
    unsigned short* m_pCurrentIndex;
    unsigned int m_uiIndexCapacity;
    unsigned int m_uiUsedIndexCount;
    NiTriShapeData__SNAMemBlock* m_pkNext;
};

// MSVC emits its vector constructor iterator for this array initialization.
// @fnv 0x00401050
static NiTriShapeData__SNAMemBlock s_SNAMemBlocks[2];
