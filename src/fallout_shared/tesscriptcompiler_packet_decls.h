// fallout_shared/tesscriptcompiler_packet_decls.h: declares CommandInfo
#ifndef TESSCRIPTCOMPILER_PACKET_DECLS_H
#define TESSCRIPTCOMPILER_PACKET_DECLS_H
extern bool DAT_011c40c8;
template <class T> unsigned int BSStringLength(const T*);
#include "../../include/TESForm.h"
#include "../../include/ScriptFunctionInfo.h"
struct CommandInfo
{
    char data[40];
};
extern ScriptFunctionInfo DAT_0118e8e0[];
extern CommandInfo g_scriptCommands[];
ScriptFunctionInfo* GetFunctionByOpcode(SCRIPT_OUTPUT output);
#endif
