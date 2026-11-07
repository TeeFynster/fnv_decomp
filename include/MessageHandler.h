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
    void BSCoreMessage_DisableContextMessages(unsigned int);
    void* __thiscall BSCoreMessage_BSCoreMessage();
    MessageHandler* __thiscall MessageHandler_00c3bcf0(bool b);
    void* __thiscall DestroyAndFree(unsigned int flags);
};
