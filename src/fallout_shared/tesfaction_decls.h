#ifndef TESFACTION_DECLS_H
#define TESFACTION_DECLS_H


class ReactionInfo
{
  public:
    char data[12];
    void Endian();
};
#include "../../include/TESFaction.h"
#include "tesfaction_types_RANK_DATA.h"
#include "TESReactionForm.h"

class TESDataHandler;

class TESDataHandlerAccess
{
  public:
    TESReputation* GetReputation(unsigned int);
};

void* __cdecl Allocate(unsigned int);
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESReactionFormLoader
{
  public:
    BSSimpleList<ReactionInfo*>* GetReactionList();
};
#endif
