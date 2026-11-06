#pragma once

#include "IOTask.h"
#include "NiAVObject.h"

class TESObjectREFR;

class CheckWithinMultiBoundTask : public IOTask
{
public:
    CheckWithinMultiBoundTask(TESObjectREFR* pSource, NiAVObject* pObject);
    virtual ~CheckWithinMultiBoundTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void ProcessLoadedAnimIdle();
    virtual void GenerateKey();
    virtual void ChangePriority(IO_TASK_PRIORITY priority);

    void __thiscall FUN_0054ab60();
    void* __thiscall FUN_0054ab30(unsigned int flags);

    TESObjectREFR* unk18;
    NiPointer<NiAVObject> unk1c;
    NiPointer<NiAVObject> unk20;
    char unk24;
};
