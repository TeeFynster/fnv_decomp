#pragma once

#include "BSCoreMessage.h"

class MessageHandler : public BSCoreMessage
{
public:
    virtual ~MessageHandler();

    bool bStatic;

    static MessageHandler* pHandler;
    static MessageHandler& Handler();
    static void SetWarningCount(int count);

    const char* GetWarningFileName();
    float GetSpeechProgress();
    void vprintf(const char* format, ...);
    void FUN_00aa4c40(unsigned int);
    void* __thiscall FUN_00aa4c60();
    MessageHandler* __thiscall FUN_00c3bcf0(bool b);
    void* __thiscall DestroyAndFree(unsigned int flags);
};
