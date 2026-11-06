#ifndef FNV_TASK_BGSBODYPARTDATA_COPY_H
#define FNV_TASK_BGSBODYPARTDATA_COPY_H

#include "layout_support.h"
#include "../../include/TESFile.h"

#include "../../include/IO_TASK_PRIORITY.h"

// This unit compares the full 32-bit record type returned by the game.
struct TESFileFormInt : public TESFile
{
    int GetTESForm();
};

int Warning();
int Warning(const char* format, ...);
#endif
