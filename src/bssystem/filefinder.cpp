#define FNV64_BSSIMPLELIST_CUSTOM_NEW
#define FNV64_BSSIMPLELIST_CUSTOM_DELETE
#include "../../include/BSSimpleList.h"
// bssystem/filefinder.cpp: FileFinder, Loader_S (12 functions)

#include "../../include/MemoryManager.h"
#include "../../include/BSFile.h"
#include "../../include/IOManager.h"
#include "../../include/OSGlobals.h"
#include "filefinder_filefinder_decls.h"

__forceinline void* BSFile::operator new(size_t size)
{
    return g_memoryManager.Allocate(size);
}

// Returns the file location from g_fileFinder's lookup for fileName, or NOTFOUND when g_fileFinder is null.
// @fnv 0x00456a20
FileFinder::FILE_LOCATION __cdecl FileFinder::Exist(const char* fileName, char* filePath, unsigned int flags,
                                                    unsigned int archiveType)
{
    FILE_LOCATION result;
    if (g_fileFinder)
        result = g_fileFinder->GetFileLocation((char*)fileName, filePath, flags, archiveType);
    else
        result = NOTFOUND;
    return result;
}

// @fnv 0x00afe0d0
FileFinder::FILE_LOCATION FileFinder::GetFileLocation(char* fileName, char* filePath, unsigned int flags,
                                                      unsigned int archiveType)
{
    char path[260];
    char unused[4];
    FILE_LOCATION result;

    if (archiveType == 0xffffffff)
        archiveType = 0xffff;
    unused[0] = 0;
    result = NOTFOUND;

    if (fileName[1] == ':')
    {
        flags |= 5;
    }
    else if (fileName[0] == '.' && fileName[1] == '\\')
    {
        flags |= 4;
        fileName += 2;
    }

    if (fileName[0] == '\\')
        strcpy_s(path, 260, fileName + 1);
    else
        strcpy_s(path, 260, fileName);

    result = (FILE_LOCATION)FileFinder_LookForFile(path, flags, archiveType);
    if (result == NOTFOUND)
    {
        if (filePath)
            filePath[0] = 0;
    }
    else if (filePath)
    {
        strcpy_s(filePath, 260, path);
    }
    return result;
}

// Resolves name through g_fileFinder and returns a BSFile or archive file for the given mode, buffer size and archive type, or null.
// @fnv 0x00afdf20
NiFile* FileFinder::GetFile(const char* name, NiFile::OpenMode mode, unsigned int bufferSize, unsigned int archiveType)
{
    // These local identifiers preserve MSVC9 stack-slot ordering.
    bool bFileFound;
    FILE_LOCATION pFile;     // Location returned by GetFileLocation.
    NiFile* pInputFile = 0;  // Resulting file stream.
    char cFileName[780];
    if (g_fileFinder)
    {
        if (mode == 1)
        {
            pInputFile = new BSFile(name, (int)mode, bufferSize, false);
        }
        else
        {
            pFile = g_fileFinder->GetFileLocation((char*)name, cFileName, 0, archiveType);
            bFileFound = false;
            if (pFile != NOTFOUND)
            {
                if (pFile == ARCHIVE)
                {
                    if (!pInputFile)
                        pInputFile = ArchiveManager::GetFile(cFileName, bufferSize, archiveType);
                    else
                        bFileFound = true;
                }
                else
                {
                    pInputFile = new BSFile(cFileName, (int)mode, bufferSize, false);
                    static_cast<BSFile*>(pInputFile)->Open(false, false);
                }
            }
        }
    }
    return pInputFile;
}

struct FUN_00afe220_shell : public FileFinder
{
    int FileFinder_LookForFile(char*, unsigned int, unsigned int);
};

bool __cdecl ArchiveManager_FindFile(int, int);
int __cdecl FUN_00ecbf05(const char*, int);
unsigned int __cdecl _strlen(const char*);
int __cdecl __strnicmp(const char*, const char*, unsigned int);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
int __cdecl _strcat_s(char*, unsigned int, const char*);
extern bool DAT_011acdf8;
extern bool DAT_011acdf9;
struct PathArr_S
{
    void* pVtbl;
    const char** pData;
    unsigned int uiSize;
    __forceinline unsigned int GetSize() const
    {
        unsigned int r = uiSize;
        return r;
    }
};
__forceinline unsigned int StrLenFI(const char* s)
{
    unsigned int n = _strlen(s);
    return n;
}
struct FinderCalls_S
{
    bool IsFlag2Clear(unsigned int, unsigned int);
    bool IsFlag4Clear(unsigned int, unsigned int);
};

// @fnv 0x00afe220
// src: COMMUNITY 0x00afe220
int FUN_00afe220_shell::FileFinder_LookForFile(char* apFilePath, unsigned int aiFlags, unsigned int aiArchiveType)
{
    char acFullPath[260];
    if (!(aiFlags & 1) && ArchiveManager_FindFile((int)apFilePath, aiArchiveType))
        return 2;
    if (!DAT_011acdf8 || DAT_011acdf9)
        aiFlags = 0;
    if (reinterpret_cast<FinderCalls_S*>(this)->IsFlag2Clear(aiFlags, aiArchiveType) &&
        FUN_00ecbf05(apFilePath, 0) != -1)
        return 1;
    if (reinterpret_cast<FinderCalls_S*>(this)->IsFlag4Clear(aiFlags, aiArchiveType))
    {
        unsigned int uiPathCount = reinterpret_cast<PathArr_S*>(this)->GetSize();
        for (unsigned int uiIndex = 0; uiIndex < uiPathCount; uiIndex++)
        {
            const char* pcPrefix = reinterpret_cast<PathArr_S*>(this)->pData[uiIndex];
            if (pcPrefix && __strnicmp(apFilePath, pcPrefix, StrLenFI(pcPrefix)))
            {
                _strcpy_s(acFullPath, 0x104, pcPrefix);
                _strcat_s(acFullPath, 0x104, apFilePath);
                if (FUN_00ecbf05(acFullPath, 0) != -1)
                {
                    _strcpy_s(apFilePath, 0x104, acFullPath);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
__declspec(dllimport) int __stdcall SetWindowTextA(void*, const char*);
bool __cdecl TESRenderer_GetFullScreen();
// The shared classes lack these out-of-line accessors; a single fastcall argument preserves their ECX-only ABI.
// IOManager's 0x18 getter and 0x64 queue call bind to 0x004491f0 and 0x00446da0; OSGlobals' window getter is 0x0044ddc0.
int __fastcall GetBackgroundLoadingCount(IOManager* manager);
int __fastcall GetPendingLoadingTaskCount(IOManager* manager);
void* __fastcall GetLoadingStatusWindow(OSGlobals* globals);
extern IOManager* DAT_01202d98;
extern OSGlobals* g_osGlobals;
extern const char* DAT_011a2fe8;
extern bool DAT_011c3bfc;
struct Loader_S
{
    int CallVirtual17();
    int ModelLoader_GetBackgroundCloningCount();
    void UpdateLoadingStatus();
};

// @fnv 0x00446cb0
void Loader_S::UpdateLoadingStatus()
{
    if (!TESRenderer_GetFullScreen())
    {
        int iPost = CallVirtual17();
        int iRefs = ModelLoader_GetBackgroundCloningCount();
        int iBackground = GetBackgroundLoadingCount(DAT_01202d98);
        int iTasks = GetPendingLoadingTaskCount(DAT_01202d98);
        if (iBackground || iRefs || iPost || iTasks)
        {
            char buffer[260];
            _sprintf_s(buffer, 0x104,
                       "Loading %d references( %d background cloning ) and %d tasks( %d post processing )", iPost,
                       iRefs, iBackground, iTasks);
            DAT_011c3bfc = true;
        }
        else if (DAT_011c3bfc)
        {
            DAT_011c3bfc = false;
            SetWindowTextA(GetLoadingStatusWindow(g_osGlobals), DAT_011a2fe8);
        }
    }
}

struct FUN_00afe1f0_shell : public FileFinder
{
    unsigned int FindFile(char*, unsigned int);
};

// @fnv 0x00afe1f0
unsigned int FUN_00afe1f0_shell::FindFile(char* pcPath, unsigned int uiFlags)
{
    return this->FileFinder_LookForFile(pcPath, uiFlags, 0xffff);
}

int __cdecl FileFinder_BuildFileList(int a1, int a2, int a3, int a4);

// @fnv 0x00afe400
// src: COMMUNITY 0x00afe400
int __cdecl FileFinder_BuildFileList_(int a2, int a1)
{
    return FileFinder_BuildFileList(a2, a1, 0xffff, 0);
}

int __cdecl FileFinder_BuildFileList(int, int, unsigned int, int);

// @fnv 0x00afe590
// src: COMMUNITY 0x00afe590
int __cdecl FileFinder_BuildSingleFileList_1(int a1, int a2, int a3)
{
    return FileFinder_BuildFileList(a1, a2, 0xffffu, a3);
}

struct _FILETIME
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};
struct FileFinderHack
{
    static bool __cdecl GetFileTime(char const*, _FILETIME&, unsigned int);
};
// @fnv 0x00afe7b0
// src: GUESS 0x00afe7b0 (confidence: medium)
bool __cdecl FileFinder_GetFileTime_Thunk(char const* a, _FILETIME& b)
{
    return FileFinderHack::GetFileTime(a, b, 0xffff);
}

namespace fnv_00afe7d0 {
struct _FILETIME
{
    unsigned int dwLowDateTime;
    unsigned int dwHighDateTime;
};
void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);
struct FileEntryTmp
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual const char* f6();
};
FileEntryTmp* __cdecl FindArchiveForFile(const char*, unsigned int);
bool __cdecl File_GetLastWriteTime(const char*, _FILETIME*);
// @fnv 0x00afe7d0
// src: COMMUNITY 0x00afe7d0
bool __cdecl ArchiveManager_GetLastWriteTimeForFile(const char* apFileName, _FILETIME& arFileTime, unsigned int aiMode)
{
    _fnv_zlib_memset(&arFileTime, 0, 8);
    FileEntryTmp* pkEntry = FindArchiveForFile(apFileName, aiMode);
    if (pkEntry)
        apFileName = pkEntry->f6();
    return File_GetLastWriteTime(apFileName, &arFileTime);
}
}  // namespace fnv_00afe7d0

inline void DeadQ6()
{
    int a[6];
}
class Actor;
bool __cdecl FileFinder_PlatformFindSingleFile(const char*);
unsigned int __cdecl strlen(const char*);
const char* __cdecl strrchr(const char*, int);
void* __cdecl _memmove(void*, const void*, unsigned int);
void __cdecl strcat_s(char*, unsigned int, const char*);
#include "../../include/BSSimpleList.h"
template <class T> inline BSSimpleList<T>::BSSimpleList() { m_item = 0; m_pkNext = 0; }
template <class T> inline BSSimpleList<T>::~BSSimpleList() { RemoveAll(); }
template <class T> inline bool BSSimpleList<T>::IsEmpty() { return (m_pkNext == 0 && m_item == 0) ? 1 : 0; }
template <class T> inline void* BSSimpleList<T>::operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
template <class T> inline void BSSimpleList<T>::operator delete(void* p) { g_memoryManager.Deallocate(p); }
inline void* __cdecl operator new[](unsigned int n)
{
    return g_memoryManager.Allocate(n);
}
inline void CopyQ(char* d, const char* s, unsigned int n)
{
    _memmove(d, s, n);
}
inline void CatQ(char* d, unsigned int n, const char* s)
{
    strcat_s(d, n, s);
}
// Validates a path and name, builds a combined string, adds it to a BSSimpleList, and returns the list or null if empty.
// @fnv 0x00afe5b0
// src: COMMUNITY 0x00afe5b0
BSSimpleList<Actor*>* __cdecl FileFinder_BuildSingleFileList(const char* path, const char* name, int x, BSSimpleList<Actor*>* apList)
{
    BSSimpleList<Actor*>* list7 = apList;
    if (!list7)
        list7 = new BSSimpleList<Actor*>;
    bool ok = false;
    if (!DAT_011acdf8 || DAT_011acdf9)
        ok = FileFinder_PlatformFindSingleFile(path);
    if (!ok)
        ok = ArchiveManager_FindFile((int)path, x);
    if (ok)
    {
        unsigned int len5 = strlen(name);
        const char* s6 = strrchr(name, '\\');
        const char* sA = strrchr(path, '\\');
        if (s6 && sA)
        {
            len5 -= strlen(s6 + 1);
            unsigned int total = len5 + strlen(sA + 1) + 1;
            char* buf = new char[total];
            CopyQ(buf, name, len5);
            buf[len5] = 0;
            CatQ(buf, total, sA + 1);
            list7->AddHead((Actor* const&)buf);
        }
    }
    if (list7->IsEmpty())
    {
        delete list7;
        list7 = 0;
    }
    DeadQ6();
    return list7;
}

char* __cdecl strstr(const char*, const char*);
struct FileMatchList
{
    void* data;
    FileMatchList* next;
    FileMatchList()
    {
        data = 0;
        next = 0;
    }
    ~FileMatchList()
    {
        RemoveAll();
    }
    void RemoveAll()
    {
        while (next)
        {
            FileMatchList* following = next->next;
            next->next = 0;
            delete next;
            next = following;
        }
        data = 0;
    }
    bool IsEmpty() const
    {
        return next == 0 && data == 0;
    }
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void* object)
    {
        g_memoryManager.Deallocate(object);
    }
};
FileMatchList* FileFinder_BuildSingleFileList(const char*, const char*, unsigned int, FileMatchList*);
void CollectDirectoryEntries(const char*, const char*, FileMatchList*);
void ArchiveManager_AddToFileList(FileMatchList*, const char*, const char*, unsigned int);
// Finds files matching a pattern in a directory, using wildcards or exact match, and returns a list of matches.
// @fnv 0x00afe420
// src: COMMUNITY 0x00afe420
FileMatchList* FileFinder_BuildFileList(const char* pattern, const char* directory, unsigned int flags, FileMatchList* existing)
{
    if (!pattern || !directory)
        return 0;
    if (!strstr(pattern, "*") && !strstr(pattern, "?"))
        return FileFinder_BuildSingleFileList(pattern, directory, flags, existing);
    FileMatchList* matches = existing;
    if (!matches)
        matches = new FileMatchList;
    if (!DAT_011acdf8 || DAT_011acdf9)
        CollectDirectoryEntries(pattern, directory, matches);
    ArchiveManager_AddToFileList(matches, pattern, directory, flags);
    if (matches->IsEmpty())
    {
        delete matches;
        matches = 0;
    }
    return matches;
}
