// src/gamebryo2.2/corelibs/nianimation/bsanimnotelistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/bsanimnotelistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

static const float DAT_01015f5c = -3.4028234663852886e+38f;

struct FUN_00a32290_Child
{
    int m_00;
    float m_04;
    int m_08;
    int m_0c;
    float m_10;
    float m_14;
};

struct FUN_00a32290_Node
{
    int m_00;
    int m_04;
    int m_08;
    unsigned char m_0c;
    char m_0d;
    unsigned char m_0e;
    unsigned char m_0f;
    int m_10;
    FUN_00a32290_Child* m_14;
    int m_18;
    int m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
};

struct FUN_00a32290_Elem
{
    int m_00;
    int m_04;
    FUN_00a32290_Node* m_08;
    unsigned char m_0c;
    char m_0d;
    char m_0e;
    char m_0f;
};

struct FUN_00a32290_Cls
{
    int m_00;
    int m_04;
    int m_08;
    unsigned int m_0c;
    int m_10;
    FUN_00a32290_Elem* m_14;

    void NiControllerSequence_SetInterpsWeightAndTime(float a1, float a2, float a3);
};

// For each element, writes a3 (and a1/a2) into the node's child slot or its m_20, and resets the node's m_24/m_28/m_2c to DAT_01015f5c.
// @fnv 0x00a32290
// src: XBOX_PDB 0x00a32290
void FUN_00a32290_Cls::NiControllerSequence_SetInterpsWeightAndTime(float afValue1, float afValue2, float afValue3)
{
    for (unsigned int uiIndex = 0; uiIndex < m_0c; ++uiIndex)
    {
        FUN_00a32290_Elem* pElem = &m_14[uiIndex];
        FUN_00a32290_Node* pNode = pElem->m_08;
        if (pNode != 0)
        {
            unsigned char ucSlotIndex = pElem->m_0c;
            if (pNode->m_0e == 1 && ucSlotIndex == pNode->m_0f)
            {
                pNode->m_20 = afValue3;
            }
            else
            {
                pNode->m_14[ucSlotIndex].m_14 = afValue3;
                pNode->m_14[ucSlotIndex].m_04 = afValue1;
                pNode->m_14[ucSlotIndex].m_10 = afValue2;
                pNode->m_0c |= 4;
                pNode->m_24 = DAT_01015f5c;
                pNode->m_28 = DAT_01015f5c;
                pNode->m_2c = DAT_01015f5c;
            }
        }
    }
}
