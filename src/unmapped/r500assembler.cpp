
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BSFile.h"
#include "../../include/SL.h"
#include "../../include/StartMenu.h"

struct FUN_0085fbb0 : public BSFile
{
    void Method_0085fbb0();
};

// @fnv 0x0085fbb0
void FUN_0085fbb0::Method_0085fbb0()
{
    BSFile::~BSFile();
}

extern "C" __declspec(dllimport) char* __stdcall lstrcpy(char*, const char*);
extern "C" __declspec(dllimport) char* __stdcall lstrcatA(char*, const char*);
struct FindData_t
{
    unsigned long dwFileAttributes;
    unsigned long ftCreationTime[2];
    unsigned long ftLastAccessTime[2];
    unsigned long ftLastWriteTime[2];
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};
struct _WIN32_FIND_DATAA;
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char*, _WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void*, _WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) int __stdcall FindClose(void*);
struct DebrisData;
extern StartMenu g_011c3f74;
const char* __cdecl PrepareScriptMessage(const char*, bool);
char* __cdecl BSUtilities_GetPersonalPath();
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
struct AEList
{
    void Insert(DebrisData*, int(__cdecl*)(DebrisData*, DebrisData*));
};
struct FUN_0085fb40
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    FUN_0085fb40(const char* path, int mode, int bufSize);
};
int __cdecl CompareFileWriteTimes(DebrisData*, DebrisData*);
struct SaveLoadList
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    SL* list;
    void DeleteAllItems();
    void LoadSaveFiles();
};
// @fnv 0x0085f900
void SaveLoadList::LoadSaveFiles()
{
    char path[260];
    {
        char fullPath[260];
        {
            FUN_0085fb40* file;
            {
                FindData_t findData;
                {
                    void* handle;
                    if (list)
                        DeleteAllItems();
                    list = new SL;
                    lstrcpy(path, BSUtilities_GetPersonalPath());
                    lstrcatA(path, PrepareScriptMessage(static_cast<const StartMenu&>(g_011c3f74).GetMenuTitle(), false));
                    lstrcatA(path, "*.ess");
                    handle = FindFirstFileA(path, (_WIN32_FIND_DATAA*)&findData);
                    if (handle != (void*)-1)
                    {
                        do
                        {
                            if (findData.nFileSizeHigh || findData.nFileSizeLow)
                            {
                                _sprintf_s(fullPath, 260, "%s%s%s", BSUtilities_GetPersonalPath(),
                                           PrepareScriptMessage(static_cast<const StartMenu&>(g_011c3f74).GetMenuTitle(), false), findData.cFileName);
                                file = new FUN_0085fb40(fullPath, 0, 0x20000);
                                ((AEList*)list)->Insert((DebrisData*)file, CompareFileWriteTimes);
                            }
                        } while (FindNextFileA(handle, (_WIN32_FIND_DATAA*)&findData));
                        FindClose(handle);
                    }
                }
            }
        }
    }
}

extern "C" char DAT_01081a5c;

struct SpawnedObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned char m_158;
    void Init(int a, int b, int c, int d);
    SpawnedObject* InitializeFields_0085fb40(int a1, int a2, int a3);
};

// @fnv 0x0085fb40
// src: GUESS 0x0085fb40 (confidence: low)
SpawnedObject* SpawnedObject::InitializeFields_0085fb40(int a1, int a2, int a3)
{
    this->Init(a1, a2, a3, 0);
    *(void* volatile*)this = &DAT_01081a5c;
    this->m_158 = 0;
    return this;
}

struct Item
{
    virtual ~Item();
};

// Exe 0x0085fbd0: unit-local ListNode view; declarations and layout are preserved.
struct R500assemblerListNodeView
{
    Item** GetItem();
    R500assemblerListNodeView* GetNext();
};

struct List
{
    void RemoveAll();
    ~List();
};

struct FUN_0085fbd0_class
{
    char pad[0x70];
    List* m_kNode;

    void __thiscall DeleteAllItems();
};

// Iterates the list, deletes each item, clears the list, deletes the list, and nulls the pointer.
// @fnv 0x0085fbd0
void __thiscall FUN_0085fbd0_class::DeleteAllItems()
{
    if (m_kNode)
    {
        R500assemblerListNodeView* node = (R500assemblerListNodeView*)m_kNode;
        while (node)
        {
            Item* item = *node->GetItem();
            if (item)
            {
                delete item;
            }
            node = node->GetNext();
        }
        m_kNode->RemoveAll();
        delete m_kNode;
        m_kNode = 0;
    }
}

void __cdecl operator delete(void*);

struct SaveGameFileDeleteEntry85 : public FUN_0085fbb0
{
    void* __thiscall FUN_0085fb80(unsigned int flags);
};

// Calls Method_0085fbb0 of the base, deletes this when bit 0 of flags is set, and returns this.
// @fnv 0x0085fb80
void* __thiscall SaveGameFileDeleteEntry85::FUN_0085fb80(unsigned int flags)
{
    FUN_0085fbb0::Method_0085fbb0();
    if (flags & 1)
        ::operator delete(this);
    return this;
}
