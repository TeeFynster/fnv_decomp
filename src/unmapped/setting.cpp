
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "layout_support.h"
#include "../../include/SETTING_VALUE.h"
#include "../../include/AutoMemHelper.h"
#include "../../include/DummyPointerMap.h"
#include "../../include/GameSettingCollection.h"
#include "../../include/SettingCollectionMap.h"

extern void __cdecl FUN_0044f700();
extern void* DAT_0101772c;
struct FUN_0044f600_class
{
    void* vtbl;
    void __thiscall FUN_0044f700();
    void* __thiscall InitializeVtbl();
};
// @fnv 0x0044f600
void* __thiscall FUN_0044f600_class::InitializeVtbl()
{
    FUN_0044f700();
    vtbl = &DAT_0101772c;
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_00877a10_Class
{
    void __thiscall ForwardCall_00877a10();
};
struct FUN_0044f620_class
{
    void* __thiscall FUN_0044f620(unsigned int flags);
};
// Calls FUN_00877a10 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0044f620
void* __thiscall FUN_0044f620_class::FUN_0044f620(unsigned int flags)
{
    ((FUN_00877a10_Class*)this)->ForwardCall_00877a10();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_0044f6d0 {
struct FUN_00877a10_Class
{
    void __thiscall FUN_0044f650();
    void* __thiscall FUN_0044f6d0(unsigned int flags);
};
extern void __cdecl Deallocate(void*);
// Calls FUN_0044f650, then deallocates this object if bit 0 of flags is set, and returns this.
// @fnv 0x0044f6d0
void* __thiscall FUN_00877a10_Class::FUN_0044f6d0(unsigned int flags)
{
    FUN_0044f650();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_0044f6d0

struct FUN_00404920
{
    FUN_00404920(int, int);
    ~FUN_00404920();
};
struct FUN_0040e0b0
{
    virtual void v0();
    virtual void v1(void*);
    static const void* vftable;
};
struct FUN_0040c150 : FUN_00404920
{
    FUN_0040c150(int a, int b);
};
// @fnv 0x0040c150
FUN_0040c150::FUN_0040c150(int aiArg1, int aiArg2) : FUN_00404920(aiArg1, aiArg2)
{
    *(int*)this = (int)&FUN_0040e0b0::vftable;
    GameSettingCollection::Instance()->v1(this);
}

struct FUN_0040e130
{
    FUN_0040e130(int, float);
    ~FUN_0040e130();
    virtual void v0();
    virtual void v1(void*);
};
struct FUN_0044f440 : FUN_0040e130
{
    FUN_0044f440(int a, float b);
    virtual void v0();
    virtual void v1(void*);
};
struct FUN_0044f560
{
    static void* __cdecl GetCollection();
    virtual void v0();
    virtual void v1(void*);
};
// @fnv 0x0044f440
FUN_0044f440::FUN_0044f440(int aiValue, float afValue) : FUN_0040e130(aiValue, afValue)
{
    ((FUN_0044f560*)FUN_0044f560::GetCollection())->v1(this);
}

extern int _data_011c16bc;
extern char const str_010121d0[];
extern char const str_01012220[];


// Exe 0x00404de0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct SettingOffset08View
{
    unsigned int __thiscall GetFlags();
};


struct TESGlobalMap
{
    void __thiscall SetAt(char const*, TESGlobal*);
};

void __cdecl Object_ProcessAndReturnValue_00c335a0(char const*, ...);


// @fnv 0x00404de0
template <>
void __thiscall SettingCollectionMap<Setting>::AddSetting(Setting* apSetting)
{
    AutoMemHelper tempMemContext(9, true, str_01012220, 539);

    if (apSetting && reinterpret_cast<SettingOffset08View*>(apSetting)->GetFlags())
    {
        unsigned int key;
        if (reinterpret_cast<DummyPointerMap*>(reinterpret_cast<char*>(this) + 0x10c)
                ->GetAt(reinterpret_cast<SettingOffset08View*>(apSetting)->GetFlags(), key))
        {
            Object_ProcessAndReturnValue_00c335a0(str_010121d0, reinterpret_cast<SettingOffset08View*>(apSetting)->GetFlags());
        }
        else
        {
            reinterpret_cast<TESGlobalMap*>(reinterpret_cast<char*>(this) + 0x10c)
                ->SetAt(reinterpret_cast<char const*>(reinterpret_cast<SettingOffset08View*>(apSetting)->GetFlags()),
                        reinterpret_cast<TESGlobal*>(apSetting));
        }
    }
}

namespace fnv_00c335a0 {
#include <stdarg.h>

int C335A0Report(int iLevel, const char* pcFormat, va_list args);

// @fnv 0x00c335a0
// src: GUESS 0x00c335a0 (confidence: low)
int Object_ProcessAndReturnValue_00c335a0(const char* pcFormat, ...)
{
    va_list args;
    va_start(args, pcFormat);
    int iResult = C335A0Report(1, pcFormat, args);
    va_end(args);
    return iResult;
}
}  // namespace fnv_00c335a0

struct SettingName
{
    char* FUN_0044ddc0();
};
struct SettingNode
{
    SettingName** FUN_006815c0();
    SettingNode* FUN_00726070();
};
struct SettingStore : SettingNode
{
    bool FUN_008256d0();
    void FUN_005ae3d0(SettingName**);
};
int __cdecl BSstricmp(const char*, const char*);
extern const char str_0101608c[];
struct Registry
{
    void AddSettingKey(SettingName*);
};
// @fnv 0x0044f770
void Registry::AddSettingKey(SettingName* key)
{
    AutoMemHelper scope(9, true, str_0101608c, 765);
    if (!((SettingStore*)((char*)this + 0x10c))->FUN_008256d0())
    {
        SettingNode* position = (SettingNode*)((char*)this + 0x10c);
        while (position)
        {
            SettingName* entry = *position->FUN_006815c0();
            if (BSstricmp((const char*)entry->FUN_0044ddc0(), (const char*)key->FUN_0044ddc0()) == 0)
            {
                Object_ProcessAndReturnValue_00c335a0("DEFAULT: Setting key '%s' already used in list.\nSetting keys must be unique.\n",
                             (const char*)key->FUN_0044ddc0());
                return;
            }
            position = position->FUN_00726070();
        }
    }
    ((SettingStore*)((char*)this + 0x10c))->FUN_005ae3d0(&key);
}

extern const char str_0101608c[];

struct DataListEntry
{
    int* FUN_006815c0();
};
struct EntryEnumerator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual bool v14(int data);
    bool FUN_00404d30();
    DataListEntry* SettingCollectionList_Setting_Head();
    DataListEntry* SettingCollectionList_Setting_Next(DataListEntry* current);
    bool SettingCollectionList_Setting_ReadSettings();
};
// @fnv 0x0044f9c0
// src: XBOX_PDB 0x0044f9c0
bool EntryEnumerator::SettingCollectionList_Setting_ReadSettings()
{
    AutoMemHelper guard(9, true, str_0101608c, 0x357);
    bool succeeded = FUN_00404d30();
    if (succeeded)
    {
        DataListEntry* current = SettingCollectionList_Setting_Head();
        while (current != 0)
        {
            if (*current->FUN_006815c0() != 0)
            {
                succeeded = succeeded & v14(*current->FUN_006815c0());
            }
            current = SettingCollectionList_Setting_Next(current);
        }
    }
    return succeeded;
}

template <class T> class SettingCollection
{
  public:
    virtual ~SettingCollection();
    char path[260];
    void* handle;
};
class FUN_0044f650 : public SettingCollection<Setting>
{
  public:
    BSSimpleList<Setting*> settings;
    virtual ~FUN_0044f650();
};
// Removes all entries from the settings list during destruction of the SettingCollection subclass.
// @fnv 0x0044f650
FUN_0044f650::~FUN_0044f650()
{
    settings.RemoveAll();
}

class FUN_00404d00_class
{
  public:
    FUN_00404d00_class();
    virtual ~FUN_00404d00_class();
    char unk004[0x108];
};

class StrList
{
  public:
    StrList();
    void* m_pkHead;
    void* m_pkTail;
};

class FUN_0044f700 : public FUN_00404d00_class
{
  public:
    StrList m_kList;

    FUN_0044f700();
    virtual ~FUN_0044f700();
};

// Default constructor for a container that holds a StrList member.
// @fnv 0x0044f700
FUN_0044f700::FUN_0044f700()
{}
