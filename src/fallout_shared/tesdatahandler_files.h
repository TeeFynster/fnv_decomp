// Unit file, loading, queue, and thread declarations.
#ifndef FNV_TESDATAHANDLER_FILES_H
#define FNV_TESDATAHANDLER_FILES_H

struct TESRecordHeader
{
    unsigned int type, size, flags, formID;
};
void ProgramFlow(const char*, ...);
void MessageHandler_IncDisableWarningCount(bool);
const char* PrepareScriptMessage(const char*, bool);
class CompileWarningSetting
{
  public:
    const char* GetText();
};
extern CompileWarningSetting DAT_011c4024, DAT_011c4048;
extern bool DAT_011c54b9;
extern unsigned int DAT_011c3f24, DAT_011c3f28;
extern TESObjectCELL* DAT_011c3f30;
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
char* strrchr_0040ab30(char*, int);
class Archive;
class ArchiveManager
{
  public:
    static Archive* PluginFile(const char*, unsigned short, bool);
};
Archive* FindArchiveByName(const char*);
class PlayerBase
{
  public:
    void CharacterProgression_InitializeData();
};
extern PlayerCharacter* g_thePlayer;
class IdleAnimationManager
{
  public:
    void InitializeIdleAnimations();
};
extern IdleAnimationManager* DAT_011cb6a0;
void EffectSettingCollection_InitItems();
void ValidateFactionReactions();

class Calendar
{
  public:
    void ResetCachedValues();
    void Calendar_InitGlobals();
};
extern Calendar g_calendar;
extern TESDataHandler* g_dataHandler;

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern ActorDeletionQueue_tesdatahandler DAT_011e0e80;
template <int N> struct EndianSizeTag
{
};
void BSEndian(unsigned int*, EndianSizeTag<3>);
bool FUN_00484b40(unsigned int);
struct FormTypeDescription
{
    const char* name;
    unsigned int data[2];
};
extern FormTypeDescription DAT_01187004[];
extern TESWorldSpace* DAT_011c3f34;
extern TESTopic* g_loadingTopic;
extern TESTopicInfo* DAT_011c3f38;
extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)

NiPointer<NavMesh> MakeNavMeshPointer(NavMesh*);

int strcat_s(char*, unsigned int, const char*);
char* strchr(char*, int);
int FUN_00ec4835(const void*, const void*, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" int* _errno();

extern "C" int _mbsnicmp(const unsigned char*, const unsigned char*, unsigned int);
extern "C" int _mbsicmp(const unsigned char*, const unsigned char*);
int BSstricmp(const char*, const char*);
// DataHandlerLock: unit-local 8-byte lock, not the 32-byte RecursiveSpinLock: FAMThread's at +0x34 (0x0082f610
// constructs it with the folded two-dword ctor 0x0096a2d0, state at +0x3c) and DAT_011c4000; Lock/Unlock are the out-of-line 0x0040fbf0/0x0040fba0
class DataHandlerLock
{
  public:
    DataHandlerLock();
    void Lock(const char*);
    void Unlock();
    unsigned int thread, count;
};
extern DataHandlerLock DAT_011c4000;
class BSFlags
{
  public:
    unsigned int flags;
    void Clear(unsigned int);
};

class FAMThread : public BSThread
{
  public:
    FAMThread();
    virtual void Run();
    void* event;
    DataHandlerLock lock;
    unsigned int state;
    void* work;
    void* result;
    unsigned int threadID;
};

#endif
