// Authored reconstruction for the five Doc Speech30 aid-segment functions
// attributed to bsmain/messagehandler.h.
//
// The unit is a header unit: the five function bodies are defined and marked
// here, and messagehandler_h_unit.cpp only includes this header.
#ifndef BSMESSAGEHANDLER_H
#define BSMESSAGEHANDLER_H


#include "../../include/MessageHandler.h"

// Per-thread warning bookkeeping.  The warning queueing state is kept per
// thread because a message box is shown on the main thread while game logic
// runs elsewhere.  The block sits behind a long run of other thread-local
// objects, so only its tail (the disableWarningCount field) is this unit's.
struct MessageHandlerThreadState
{
    unsigned char priorThreadState[0x2b8];
    unsigned int disableWarningCount;
};

#include "messagehandler_tls.h"

// The message handler singleton.
MessageHandler* MessageHandler::pHandler = 0;

// @fnv 0x006259f0
MessageHandler& MessageHandler::Handler()
{
    return *pHandler;
}

int Warning();

// @fnv 0x0045a330
const char* MessageHandler::GetWarningFileName()
{
    // The report-name storage is not exposed by the shared declaration.
    return reinterpret_cast<const char*>(this) + 0x180;
}

// @fnv 0x004694c0
float MessageHandler::GetSpeechProgress()
{
    // Speech progress lives at this offset in the original game layout.
    return *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0x3dc);
}

#endif
