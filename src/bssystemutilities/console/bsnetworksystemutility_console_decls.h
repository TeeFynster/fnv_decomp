// bssystemutilities/console/bsnetworksystemutility_console_decls.h: declares NetworkSystemUtility

#include "../../../include/MemoryManager.h"

class NetworkSystemUtility
{
  public:
    enum NetEvent
    {
        NetworkStatusChanged = 0
    };
    bool m_bSteamRunning;
    void(__cdecl* m_callback)(NetEvent, unsigned int);
    void RegisterCallback(void(__cdecl* callback)(NetEvent, unsigned int));
    static NetworkSystemUtility& GetRandomGenerator();
    NetworkSystemUtility();
    static void* operator new(unsigned int size);
    static void operator delete(void* pointer);
};
extern MemoryManager g_memoryManager;
extern NetworkSystemUtility* DAT_011f7270;
__forceinline void* NetworkSystemUtility::operator new(unsigned int size)
{
    return g_memoryManager.Allocate(size);
}
__forceinline void NetworkSystemUtility::operator delete(void* pointer)
{
    g_memoryManager.Deallocate(pointer);
}
