// fallout_shared/tesmodeltextureswap_decls.h: shared game types and unit declarations
#ifndef TESMODELTEXTURESWAP_WORKER_DECLS_H
#define TESMODELTEXTURESWAP_WORKER_DECLS_H
#define FNV64_NIFIXEDSTRING_OWN_BODIES
#include "../../include/DFALL.h"
#include "../../include/BGSDehydrationStage.h"
#include "../../include/BGSTextureSet.h"
#include "../../include/BSShaderPPLightingProperty.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiNode.h"
#include "../../include/NiProperty.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESModel.h"

class PerkButtonEntry;
class BGSPerkEntry;
class DistantTreeTextureInfo;
class TESGrass;

class BSShaderTextureSet;

class DistantTreeTextureInfo
{
  public:
    unsigned int formID;
    int index;
    char objectName[128];
    DistantTreeTextureInfo();
};

const char kModelTextureSwapInitWarning[] =
    "MASTERFILE: Failed to find texture set (%08X) in model texture swap init for form '%s' (%08X).";

int __cdecl Warning(const char* format, ...);
void __cdecl operator delete(void* pointer);

class TESObjectREFR;
class CombatThreatRecord;
template <class K, class V> class BSMapBase
{
  public:
    unsigned int hashSize;
    void* hashTable;
    unsigned int count;
    BSMapBase(unsigned int);
    virtual ~BSMapBase();
    void SetAt(K, V);
};
template <class K, class V> class BSMap : public BSMapBase<K, V>
{
  public:
};

bool TESModel_IsModelChunk(int);
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)

int Warning();
unsigned int SetWarningState(bool);

class SpellItem;
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
void* __cdecl operator new(unsigned int);

extern NiFixedString EmptyFS;
void NiGlobalStringTable_IncRefCount(const NiFixedString&);
#endif
