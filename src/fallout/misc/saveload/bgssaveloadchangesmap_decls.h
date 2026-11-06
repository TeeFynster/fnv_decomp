// fallout/misc/saveload/bgssaveloadchangesmap_decls.h: declares FormChangeRecord, TESDataHandlerAccess, QuantityData
#ifndef FNV_BGSSAVELOADCHANGESMAP_DECLS_H
#define FNV_BGSSAVELOADCHANGESMAP_DECLS_H


#include "bgssaveloadchangesmap_types_BGSSaveLoadChangesMap.h"
#include "bgssaveloadchangesmap_types_BGSChangeFlags.h"
#include "bgssaveloadchangesmap_types_BGSUnloadedFormBuffer.h"

class FormChangeRecord : public FormChangeMask
{
  public:
    FormChangeMask flags;
    FormChangeRecord();
    ~FormChangeRecord();
    bool FUN_00562210(unsigned int flags);
    void FUN_00841100(char* buffer);
};

class TESDataHandlerAccess
{
  public:
    bool FormIDExists(unsigned int formID);
};

class QuantityData
{
  public:
    void SetQuantity(unsigned int quantity);
};

extern TESDataHandler* g_dataHandler;

#endif
