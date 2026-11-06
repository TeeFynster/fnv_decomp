#pragma once

#include "hkBool.h"

typedef unsigned char hkUint8;

class hkProcess
{
public:
    class CommandArgument;

    hkProcess(hkBool selectable);

    virtual ~hkProcess() throw();
    virtual int GetOperationType();
    virtual void CollectProcessCommands(hkUint8*& commands, int& numCommands);
    virtual void ExecuteCommand(hkUint8 command);
    virtual bool isActive();
    virtual void init();
    virtual void step(float frameTimeInMs);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
