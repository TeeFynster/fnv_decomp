#pragma once

#include "BSExtraData.h"

class FactionReaction;
class TESFaction;
template <class T> class BSSimpleList;

class ExtraFactionChanges : public BSExtraData
{
public:
    ExtraFactionChanges();
    virtual ~ExtraFactionChanges();
    void* DestroyAndFree(unsigned int flags);

    bool HasFactionEntry(TESFaction* faction);
    bool HasMatchingValue(TESFaction* faction);
    void RemoveFaction(TESFaction* faction);
    void SetFactionRank(TESFaction* faction, int rank);
    void AddToFaction(TESFaction* faction, int rank);

    BSSimpleList<FactionReaction*>* m_pFactionChanges;
};
