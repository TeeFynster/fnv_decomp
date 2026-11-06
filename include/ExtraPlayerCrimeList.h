#pragma once

#include "BSExtraData.h"

template <class T> class BSSimpleList;
class MenuTopic;

class ExtraPlayerCrimeList : public BSExtraData
{
public:
    ExtraPlayerCrimeList();
    ExtraPlayerCrimeList(BSSimpleList<MenuTopic*>* apTopicList);
    virtual ~ExtraPlayerCrimeList();
};
