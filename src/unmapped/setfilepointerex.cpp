
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
class O
{
  public:
    char m_auiShapeKeys[12];
    bool m_bFlag;
    HANDLE m_hFile;
    int BSSystemFile_DoSeek(__int64 dist, DWORD method, LARGE_INTEGER* newPosPtr);
};

// Calls SetFilePointerEx on m_hFile and stores the new position; returns 0 on success, a mapped error code on failure, or 4 without seeking if m_bFlag is set.
// @fnv 0x00afeef0
// src: XBOX_PDB 0x00afeef0
int O::BSSystemFile_DoSeek(__int64 llOffset, DWORD method, LARGE_INTEGER* pNewPos)
{
    DWORD dwMethod = method;
    LARGE_INTEGER newPos;
    newPos.QuadPart = 0;
    int res = 0;
    LARGE_INTEGER off;
    unsigned int okVal;
    DWORD dwErr;
    int nCode;
    if (m_bFlag)
    {
        res = 4;
    }
    else
    {
        off.QuadPart = llOffset;
        okVal = (unsigned int)SetFilePointerEx(m_hFile, off, &newPos, dwMethod);
        if (okVal <= 0)
        {
            dwErr = GetLastError();
            switch (dwErr)
            {
            case 0:
                nCode = 0;
                break;
            case 2:
                nCode = 1;
                break;
            case 3:
                nCode = 2;
                break;
            case 19:
                nCode = 3;
                break;
            default:
                nCode = 4;
                break;
            }
            res = nCode;
        }
        else
        {
            res = 0;
            *pNewPos = newPos;
        }
    }
    return res;
}
