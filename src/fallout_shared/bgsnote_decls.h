#include "../../include/BSSimpleList.h"
// Shared list declarations and private BGSNote helpers.
#ifndef FNV_BGSNOTE_DECLS_H
#define FNV_BGSNOTE_DECLS_H

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);




#include "../../include/BGSNote.h"
#include "../../include/TESDescription.h"
#include "../../include/TESTexture.h"
#include "../../include/TESQuest.h"
#include "../../include/TESSound.h"
#include "../../include/TESTopic.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESFile.h"

#include "../../include/ENUM_FORM_ID.h"

// TESFile::GetTESForm (0x00472660) as this unit's original calls it: the full eax is compared with the form type,
// while the shared header declares an unsigned char return.
class BGSNoteFormTypeReader
{
  public:
    ENUM_FORM_ID GetTESForm();
};

int Warning(const char*, ...);
template <class T> struct BGSNoteReference
{
    unsigned int id;
    T* form;
};
bool __cdecl IsChunkTypeIcon(int);
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)
#endif
