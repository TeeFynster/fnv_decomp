// gamebryo2.2/corelibs/nimain/niglobalstringtable.cpp: NiGlobalStringTable, NiPlaybackFile (3 functions)

#include "niglobalstringtable_decls.h"

#pragma optimize("", off)
// @fnv 0x004f31b0
// Exe 0x004f31b0 increments NiPixelData revision at +0x68, not a string-table lock.
void NiPixelData::AddString()
{
    ++m_uiRevID;
}

#pragma intrinsic(strlen)
#pragma optimize("gt", on)
#pragma optimize("y", on)
// Looks up or allocates a reference-counted copy of s in the global string table under a critical section and returns the string pointer.
// @fnv 0x00a5b690
char* NiGlobalStringTable::AddString(const char* s)
{
    if (!s)
        return 0;
    unsigned len = strlen(s);
    EnterCriticalSection((char*)DAT_011f42c0 + 0x2080);
    char* result = DAT_011f42c0->NiGlobalStringTable_FindString(s, len);
    if (result)
    {
        InterlockedIncrement((long*)(result - 8));
        LeaveCriticalSection((char*)DAT_011f42c0 + 0x2080);
        return result;
    }
    unsigned tlsIndex = _tls_index;

    char* pTlsData = ((char**)__readfsdword(0x2c))[tlsIndex];
    volatile unsigned uiOldTlsValue = *(unsigned*)(pTlsData + 0x2b4);
    *(unsigned*)(pTlsData + 0x2b4) = 8;
    unsigned uiAllocSize = len + 9;
    unsigned uiRemainder = uiAllocSize & 3;
    if (uiRemainder)
        uiAllocSize += 4 - uiRemainder;
    unsigned* allocation = (unsigned*)_NiMalloc(uiAllocSize);
    result = (char*)(allocation + 2);
    allocation[0] = 1;
    allocation[1] = len;
    char* handle = result;
    fnv_zlib_memcpy(result, s, len + 1);
    DAT_011f42c0->NiGlobalStringTable_InsertString(&handle, len);
    LeaveCriticalSection((char*)DAT_011f42c0 + 0x2080);
    *(unsigned*)(pTlsData + 0x2b4) = uiOldTlsValue;
    return result;
}
#pragma optimize("", off)

#pragma function(strlen, strcpy)
// Checks a non-empty name, resolves its path, opens the Bink file with preload/force flags, warns on failure, and returns whether it opened.
// @fnv 0x00ec0ac0
bool NiPlaybackFile::FindString(const char* name, bool silent, bool preload, bool force)
{

    struct Local
    {
        unsigned uiCurrentThreadID;
        int* piTimestamp;
        NiPlaybackStat kStat;
        unsigned uiFlags;
        char pad[2];
        bool bSuccess;
        bool bOtherThread;
    } local;
    char acPath[260];

    if (!strlen(name))
        return false;
    if (!DAT_0126fac4->GetNameByKey(name, acPath))
    {
        strcpy(acPath, "Data\\Video\\");
        FUN_00ec6380(acPath, name);
    }
    local.uiFlags = 0;
    if (preload || force)
    {
        unsigned reserved;
        if (FUN_00ec923c(acPath, &local.kStat) != -1)
        {
            local.piTimestamp = &DAT_0126fad4 ? &DAT_0126fad4.timestamp : &(DAT_01202800 = 0);
            if (local.kStat.timestamp <= *local.piTimestamp || force)
                local.uiFlags |= 0x2000;
        }
    }
    local.bOtherThread = false;
    local.uiCurrentThreadID = GetCurrentThreadId();
    if (local.uiCurrentThreadID != DAT_0126fac4->vfn_3c())
    {
        local.bOtherThread = true;
        local.uiFlags |= 0x08000000;
    }
    DAT_0126fac4->vfn_14();
    handle = BinkOpen(acPath, local.uiFlags);
    local.bSuccess = true;
    if (!handle)
    {
        if (!handle)
        {
            if (!silent)
                Warning("Could not open %s for playback.", name);
            state = 0;
            local.bSuccess = false;
        }
    }
    if (local.bOtherThread)
        DAT_0126fac4->MoviePlayer_SignalBinkOpen();
    DAT_0126fac4->vfn_18();
    return local.bSuccess;
}
