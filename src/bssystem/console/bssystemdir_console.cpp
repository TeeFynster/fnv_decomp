// bssystem/console/bssystemdir_console.cpp: DirectoryIterator (3 functions)

#include "bssystemdir_console_decls.h"

// @fnv 0x00b00720
BSSystemFile__ErrorCode DirectoryIterator::NextEntry(bool& finished)
{
    if (m_pFindHandle == 0)
    {
        m_pFindHandle = DAT_00fdf070(m_acSearchPath, &m_kFindData);
        if (m_pFindHandle == (void*)-1)
            m_eErrorCode = EC_FAILED;
        else
            m_eErrorCode = EC_NONE;
        return m_eErrorCode;
    }
    if (m_pFindHandle == (void*)-1)
    {
        m_eErrorCode = EC_FAILED;
        return m_eErrorCode;
    }
    finished = !DAT_00fdf068(m_pFindHandle, &m_kFindData);
    return m_eErrorCode;
}

extern "C" __declspec(dllimport) int __stdcall FindClose(void*);
struct FUN_00b007d0_shell
{
    int BSSystemDir_DoClose();
};
// Closes the handle stored at the start of the object unless it is -1, then returns the int at offset 0x248.
// @fnv 0x00b007d0
// src: COMMUNITY 0x00b007d0
int FUN_00b007d0_shell::BSSystemDir_DoClose()
{
    if (*(int*)this != -1)
        FindClose(*(void**)this);
    return *(int*)((char*)this + 0x248);
}

extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char*, void*);
// @fnv 0x00b00800
int __cdecl CreateDirectoryChecked(const char* apcPath)
{
    return CreateDirectoryA(apcPath, 0) ? 0 : 4;
}
