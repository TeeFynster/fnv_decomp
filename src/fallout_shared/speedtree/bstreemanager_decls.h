// fallout_shared/speedtree/bstreemanager_decls.h: shared types and tree-manager declarations
#ifndef BSTREEMANAGER_DECLS_H
#define BSTREEMANAGER_DECLS_H

#include "layout_support.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/MemoryManager.h"
#include "../../../include/TES.h"
#include <new>
#include "../../../include/BSTreeManager.h"
#include "../../../include/NiPointer.h"
extern BSTreeManager* DAT_011d5c48;
extern TES* g_TES;
void BSTreeManager_Destroy_();
void* BSTreeManager_GetInstance(bool);
void SetGlobalValue(bool);
void SetGlobalFloatFromUInt(unsigned int);
void ClampAndStoreValue(float);
extern float DAT_011fd890;
extern float DAT_011adce0;
#endif
