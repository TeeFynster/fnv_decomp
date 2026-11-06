#pragma once

#include "BSSimpleArray.h"
#include "TopicInfoArray.h"

class Actor;
class INFO_LINK_ELEMENT;
class TESQuest;

class QuestDialogueInfo
{
public:
    TESQuest* pQuest;                                     // +0x0
    TopicInfoArray infoArray;                             // +0x4
    BSSimpleArray<INFO_LINK_ELEMENT, 1024> m_kInfoLinks;  // +0x1C
    TESQuest* m_pAlternateQuest;                          // +0x2C
    bool bInitialized;                                    // +0x30

    int FindCrime(Actor*, int, int);
    TopicInfoArray* GetInfoArray();
};
