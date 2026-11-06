// fallout_shared/tesconditionitem_packet.h: condition evaluation support declarations
#ifndef TESCONDITIONITEM_PACKET_H
#define TESCONDITIONITEM_PACKET_H

struct FUNCTION_DATA
{
    unsigned short function;
    unsigned short pad;
    TESObjectREFR* param;
    void* param2;
};
template <class T> class BSSimpleList;
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};
struct CommandInfo
{
    const char* name;
    char pad[12];
    bool needsRef;
    char pad11[15];
    bool(__cdecl* eval)(TESObjectREFR*, TESObjectREFR*, void*, double&);
    unsigned int tail;
};
extern CommandInfo g_scriptCommands[];
class ScriptFunctionData
{
  public:
    static void InitItem(TESForm*, FUNCTION_DATA*);
    static bool GetParamIsReference(FUNCTION_DATA*, unsigned int);
};
bool Compare(int, float, float);

int Warning(const char*, ...);
extern "C" int sprintf(char*, const char*, ...);
int FUN_00eca38d(char*, unsigned int, const char*, ...);
extern const char g_011c72c0_arg1[];
extern const char DAT_0104cae0[], DAT_01069378[], DAT_010693d8[], DAT_01069440[], DAT_01069458[], DAT_010694b0[];
#endif
