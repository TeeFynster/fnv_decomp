// Local support declarations for bgsdestructibleobjectform.cpp.
#ifndef BGSDESTRUCTIBLEOBJECTFORM_DECLS_H
#define BGSDESTRUCTIBLEOBJECTFORM_DECLS_H

#include "../../include/IO_TASK_PRIORITY.h"
#include "../../include/Setting.h"

class TimeGlobal
{
  public:
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
extern Setting g_011c3ea4;

extern BGSReconstructFormsInAllFilesMap g_011c4104;
class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
    void QueueReferenceFloatTask(TESForm*, float, bool);
};

extern unsigned char DAT_01183108;
extern unsigned char DAT_011831e8;
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

class ModelLoader
{
  public:
    void ProcessModelRequest(TESModel*, int, QueuedFile*, int, bool, bool, bool);
};
extern ModelLoader* g_modelLoader;

struct DestructionStage
{
    unsigned char base[8];
    BGSExplosion* explosion;
    BGSDebris* debris;
    unsigned int count;
    TESModel* model;
};
class DestructibleData
{
  public:
    unsigned int health;
    unsigned char count;
    unsigned char flags;
    unsigned short pad;
    DestructionStage** stages;
};

int __cdecl Warning(const char*, ...);
#endif
