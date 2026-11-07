#include "../../../../include/BSSimpleList.h"
#include "../../../../include/SettingT.h"
#include "../../../../include/BSSimpleArray.h"
// fallout/misc/saveload/bgssaveloadhistory_decls.h: declares BGSSaveLoadHistoryNoteLocals
#ifndef BGSSAVELOADHISTORY_DECLS_H
#define BGSSAVELOADHISTORY_DECLS_H


void BGSSaveLoadGlobalData_RevertGlobalDataRange(unsigned int first, unsigned int second, unsigned char flags);
int BSvsprintf(char* buffer, const char* format, char* arguments);


class NavMeshInfo;


struct BGSSaveLoadHistoryNoteLocals
{
    char* allocation;
    char* note;
    char buffer[1024];
};

class InventoryStackRecord;
template <class T> class BSSimpleList;


class ActorCause;

#endif
