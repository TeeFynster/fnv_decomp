// bssystemutilities/console/bsnetworksystemutility_console.cpp: NetworkSystemUtility (4 functions)

#include "bsnetworksystemutility_console_decls.h"
// @fnv 0x00af2d70
void NetworkSystemUtility::RegisterCallback(void(__cdecl* callback)(NetEvent, unsigned int))
{
    m_callback = callback;
    if (callback)
        callback(NetworkStatusChanged, m_bSteamRunning != 0);
}
// @fnv 0x00af2c90
NetworkSystemUtility& NetworkSystemUtility::GetRandomGenerator()
{
    if (!DAT_011f7270)
        DAT_011f7270 = new NetworkSystemUtility;
    return *DAT_011f7270;
}

// @fnv 0x00af2d40
// src: COMMUNITY 0x00af2d40
void* __fastcall BSNetworkSystemUtility_BSNetworkSystemUtility(void* pThis)
{
    *(bool*)pThis = false;
    *((void**)pThis + 1) = 0;
    return pThis;
}

struct FUN_00af2d60_Class
{
    void nullsub_327();
};
// @fnv 0x00af2d60
// src: COMMUNITY 0x00af2d60
void FUN_00af2d60_Class::nullsub_327()
{}
