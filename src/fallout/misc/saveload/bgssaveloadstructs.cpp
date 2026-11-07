#include "../../../../include/BaseProcess.h"
#include "../../../../include/MobileObject.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TESQuest.h"
#include "../../../../include/TESTopicInfo.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/BSFile.h"
#include "../../../../include/DummyPointerMap.h"
#include "../../../../include/SL.h"
#include "../../../../include/TESFullName.h"

// src/fallout/misc/saveload/bgssaveloadstructs.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/saveload/bgssaveloadstructs.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00847db0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    void BGSSaveGameBuffer_ClearPosition();
};

// @fnv 0x00847db0
// src: XBOX_PDB 0x00847db0
void FUN_00847db0_shell::BGSSaveGameBuffer_ClearPosition()
{
    m_0C = 0;
    m_10 = 0;
}

struct FUN_00853dc0_shell
{
    int GetDifference();
};

// @fnv 0x00853dc0
int __thiscall FUN_00853dc0_shell::GetDifference()
{
    return *(int*)((char*)this + 0xc) - *(int*)((char*)this + 0x10);
}

struct FUN_008547f0_shell
{
    unsigned char m_auiShapeKeys[8];
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int __thiscall GetSum();
};

// @fnv 0x008547f0
int __thiscall FUN_008547f0_shell::GetSum()
{
    return m_kPointA + m_kPointB + m_iThirdValue;
}

struct FUN_00854810_shell
{
    int __thiscall GetSumOfFields();
};

// @fnv 0x00854810
int __thiscall FUN_00854810_shell::GetSumOfFields()
{
    return ((int*)this)[0x41] + ((int*)this)[0x42];
}

struct FUN_00854880_shell
{
    unsigned int m_iElementCount;
    unsigned int m_kMinimumCorner;
    unsigned int m_kMaximumCorner;
    unsigned int m_sum;
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
    void AccumulateStats(unsigned int a, unsigned int b, unsigned int c);
};

// Increments a counter, adds a, b and c to three running totals, and tracks the minimum and maximum of their sum.
// @fnv 0x00854880
void __thiscall FUN_00854880_shell::AccumulateStats(unsigned int auiValueA, unsigned int auiValueB,
                                                    unsigned int auiValueC)
{
    this->m_iElementCount = this->m_iElementCount + 1;
    this->m_kMinimumCorner = this->m_kMinimumCorner + auiValueA;
    this->m_kMaximumCorner = this->m_kMaximumCorner + auiValueB;
    this->m_sum = this->m_sum + auiValueC;
    unsigned int uiSum = auiValueA + auiValueB + auiValueC;
    if (uiSum < this->m_ucLowNibble)
        this->m_ucLowNibble = uiSum;
    if (uiSum > this->m_ucHighNibble)
        this->m_ucHighNibble = uiSum;
}

struct FUN_00854900_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int SizeTracker_GetTotalSize();
};

// @fnv 0x00854900
// src: XBOX_PDB 0x00854900
int FUN_00854900_shell::SizeTracker_GetTotalSize()
{
    return m_04 + m_08 + m_0c;
}

extern int DAT_011a2428[];

// Masks the low 6 bits of the first byte and returns the entry at that index from DAT_011a2428.
// @fnv 0x00853640
// src: XBOX_PDB 0x00853640
int __fastcall BGSSaveLoadFormInfo_GetFormType(unsigned char* pData)
{
    unsigned char v = pData[0] & 0x3f;
    return DAT_011a2428[v];
}

extern int DAT_011a11fc[1000];
extern int DAT_011a216c[1000];

// Returns DAT_011a216c[index] when index is below 1000, otherwise DAT_011a11fc[index - 1000].
// @fnv 0x00853de0
// src: COMMUNITY 0x00853de0
int BGSSaveLoadGlobalData_GetGlobalDataName(unsigned int index)
{
    int result;
    if (index >= 1000)
        result = DAT_011a11fc[index - 1000];
    else
        result = DAT_011a216c[index];
    return result;
}

struct FUN_00854830_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    FUN_00854830_shell();
};

// @fnv 0x00854830
FUN_00854830_shell::FUN_00854830_shell()
{
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_0C = 0;
    m_10 = 0xffffffff;
    m_14 = 0;
}

int __fastcall BGSSaveLoadFormInfo_GetFormType(unsigned char* param_1);
struct FUN_00849220_shell
{
    unsigned char* p;
    int __thiscall BGSUnloadedFormBuffer_GetFormType();
};
// @fnv 0x00849220
// src: XBOX_PDB 0x00849220
int __thiscall FUN_00849220_shell::BGSUnloadedFormBuffer_GetFormType()
{
    return BGSSaveLoadFormInfo_GetFormType(p);
}

struct FormIDConverter
{
    unsigned int RegisterFormID(unsigned int);
};
// Exe 0x00853570: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BgssaveloadstructsOffset08View
{
    unsigned int GetFlags();
};
struct BGSSaveLoadGame;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct FUN_00853570_shell
{
    void WriteFormIDBytes(unsigned int numericID);
};
// @fnv 0x00853570
void FUN_00853570_shell::WriteFormIDBytes(unsigned int numericID)
{
    unsigned int iElementIndex = reinterpret_cast<FormIDConverter*>(reinterpret_cast<BgssaveloadstructsOffset08View*>(g_BGSSaveLoadGame)->GetFlags())
                              ->RegisterFormID(numericID);
    unsigned int ifileIndex = iElementIndex >> 24;
    if (ifileIndex == 0xFF)
        iElementIndex |= 0x800000;
    ((unsigned char*)this)[0] = (unsigned char)(iElementIndex >> 16);
    ((unsigned char*)this)[1] = (unsigned char)(iElementIndex >> 8);
    ((unsigned char*)this)[2] = (unsigned char)iElementIndex;
}

extern "C" void* memset(void*, int, unsigned int);
extern int DAT_011a2428[];
extern unsigned int DAT_011de3e0;
extern unsigned char DAT_011de360[];
// Fills DAT_011de360 with 255, sets DAT_011de3e0 to 55, then stores each index i at DAT_011de360[DAT_011a2428[i]].
// @fnv 0x008535e0
// src: XBOX_PDB 0x008535e0
void BGSSaveLoadFormInfo_InitSaveGameFormTypes()
{
    memset(&DAT_011de360, 255, 121);
    DAT_011de3e0 = 55;
    for (unsigned int uiIndex = 0; uiIndex < DAT_011de3e0; ++uiIndex)
        DAT_011de360[DAT_011a2428[uiIndex]] = uiIndex;
}

struct FUN_00853670_shell
{
    unsigned char m0;
    void __thiscall BGSSaveLoadFormInfo_SetFormType(int);
};
extern unsigned char DAT_011de360[];
extern unsigned int DAT_011de3e0;
char const* __cdecl GetStringForByte(unsigned char);
void __cdecl _fnv_call_845cc0(char const*, ...);
// @fnv 0x00853670
// src: COMMUNITY 0x00853670
void __thiscall FUN_00853670_shell::BGSSaveLoadFormInfo_SetFormType(int formType)
{
    unsigned char type = DAT_011de360[formType];
    if (type >= DAT_011de3e0)
    {
        _fnv_call_845cc0("Unknown form type %i %s in BGSSaveLoadFormInfo::SetFormType()", formType,
                         GetStringForByte((unsigned char)formType));
    }
    m0 = (m0 & ~0x3F) | type;
}

void __cdecl operator delete(void*);
struct FUN_00853880_shell
{
    void __thiscall FUN_008538b0();
    void* __thiscall Destroy(unsigned int flags);
};
// Calls FUN_008538b0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00853880
void* __thiscall FUN_00853880_shell::Destroy(unsigned int flags)
{
    FUN_008538b0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct Dummy008539e0
{
    virtual int Func(int);
};
struct FUN_008539e0_holder
{
    int _pad[6];
    Dummy008539e0* m_ptr;
    void BGSSaveLoadStatsMap_DestroyFile();
};
// Calls Func(1) on m_ptr if it is non-null, then sets m_ptr to 0.
// @fnv 0x008539e0
// src: COMMUNITY 0x008539e0
void FUN_008539e0_holder::BGSSaveLoadStatsMap_DestroyFile()
{
    Dummy008539e0* b = m_ptr;
    Dummy008539e0* a = b;
    a ? a->Func(1) : 0;
    m_ptr = 0;
}

struct FUN_00854920_shell : FUN_00854900_shell
{
    float __thiscall GetRatio();
};
// @fnv 0x00854920
float __thiscall FUN_00854920_shell::GetRatio()
{
    return (float)((double)(unsigned int)SizeTracker_GetTotalSize() / (double)(unsigned int)m_00);
}

// Compares the values returned by calling GetSum on both objects, returning -1 if the first is greater, 1 if less, else 0.
// @fnv 0x00854960
// src: GUESS 0x00854960 (confidence: medium)
int Object_CompareSumsDescending(FUN_008547f0_shell* pFirst, FUN_008547f0_shell* pSecond)
{
    unsigned int x = pFirst->GetSum();
    unsigned int y = pSecond->GetSum();
    {
        int r;
        if (x > y)
            r = -1;
        else
            r = x < y;
        return r;
    }
}


struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
};

unsigned int __cdecl _BSStringLength(char const*);

struct FormNameEntry
{
    unsigned int iFormID;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    TESForm* pForm;
    unsigned int m_18;

    void __thiscall BuildFormName(char* apName, unsigned int aiNameSize);
};

// @fnv 0x008536d0
void __thiscall FormNameEntry::BuildFormName(char* apName, unsigned int aiNameSize)
{
    MobileObject* pRefr;
    TESTopicInfo* pTopicInfo;

    if (!this->pForm)
    {
        TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, "UNLOADED");
        return;
    }

    pRefr = this->pForm->GetIsReference() ? static_cast<MobileObject*>(this->pForm) : 0;

    if (pRefr)
    {
        TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, pRefr->GetFullName());
    }
    else
    {
        TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, TESFullName::GetFullName(this->pForm));
    }

    if (_BSStringLength(apName) == 0)
    {
        TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, this->pForm->GetName());
    }

    if (_BSStringLength(apName) == 0)
    {
        switch (this->pForm->FNV_GetFormType())
        {
        case 0x46:
            pTopicInfo = static_cast<TESTopicInfo*>(this->pForm);
            TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, pTopicInfo->GetParentQuest()->GetEditorName());
            break;
        }
    }
}

void* operator new(unsigned int);

int __cdecl Object_CompareSumsDescending(FUN_008547f0_shell*, FUN_008547f0_shell*);

struct AEList
{
    void* m_auiShapeKeys[2];

    void Insert(void*, int(__cdecl*)(void*, void*));
};



struct SetAtHelper
{
    void SetAt(unsigned int, unsigned int);
};

struct FUN_00854af0
{
    unsigned char m_data[25];

    FUN_00854af0();
};

struct FUN_008549b0_shell
{
    void __thiscall BGSSaveLoadStatsMap_AddForm(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                                 unsigned int, unsigned char);
};

// @fnv 0x008549b0
// src: COMMUNITY 0x008549b0
void __thiscall FUN_008549b0_shell::BGSSaveLoadStatsMap_AddForm(unsigned int p0, unsigned int p1, unsigned int uiKey, unsigned int p3,
                                                 unsigned int p4, unsigned int p5, unsigned int p6, unsigned char p7)
{
    FUN_00854af0* form = new FUN_00854af0();

    reinterpret_cast<unsigned int*>(form)[0] = p0;
    reinterpret_cast<unsigned int*>(form)[5] = p1;
    reinterpret_cast<unsigned int*>(form)[1] = p3;
    reinterpret_cast<unsigned int*>(form)[2] = p4;
    reinterpret_cast<unsigned int*>(form)[3] = p5;
    reinterpret_cast<unsigned int*>(form)[4] = p6;
    form->m_data[0x18] = p7;

    {
        unsigned int list = 0;

        if (!reinterpret_cast<DummyPointerMap*>(this)->GetAt(uiKey, list))
        {
            list = reinterpret_cast<unsigned int>(new SL());
            reinterpret_cast<SetAtHelper*>(this)->SetAt(uiKey, list);
        }

        reinterpret_cast<AEList*>(list)->Insert(form, reinterpret_cast<int(__cdecl*)(void*, void*)>(Object_CompareSumsDescending));
    }
}

struct FUN_00854c80_shell
{
    virtual ~FUN_00854c80_shell();
    int m_04;
    int m_08;
    int m_0C;
    FUN_00854c80_shell(int formType);
};

struct FUN_0096a2d0_shell
{
    int m_10;
    int m_14;
    FUN_0096a2d0_shell();
};

struct FUN_00853810 : FUN_00854c80_shell
{
    FUN_0096a2d0_shell m_data;
    int m_18;
    FUN_00853810();
    virtual ~FUN_00853810();
};

// Constructs the object with base form type 0x25 and initializes m_18 to 0.
// @fnv 0x00853810
FUN_00853810::FUN_00853810() : FUN_00854c80_shell(0x25)
{
    m_18 = 0;
}

struct ResourceView
{
    virtual ~ResourceView();
};
struct StringListNode
{
    char* item;
    StringListNode* next;
    ~StringListNode();
    char** FUN_006815c0();
    StringListNode* FUN_00726070();
};
struct MapBase
{
    virtual void v0();
    int unk04;
    int unk08;
    int unk0c;
    ~MapBase();
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*&, unsigned int&, StringListNode*&);
};
struct FUN_008538b0 : MapBase
{
    StringListNode owned;
    ResourceView* resource;
    ~FUN_008538b0();
};
// Deletes resource, then frees every stored pointer in the map's buckets and in the owned list, walking each linked list.
// @fnv 0x008538b0
FUN_008538b0::~FUN_008538b0()
{
    delete resource;
    void* position = FUN_004b9ba0();
    while (position)
    {
        unsigned int key = 0;
        StringListNode* list = 0;
        FUN_006b7f20(position, key, list);
        while (list)
        {
            delete *list->FUN_006815c0();
            list = list->FUN_00726070();
        }
    }
    StringListNode* list = &owned;
    while (list)
    {
        delete *list->FUN_006815c0();
        list = list->FUN_00726070();
    }
}

// Prepare a dialogue response for the speaker: reset it, fill it from the speaker/topic, then notify.

class B4B10Response;

class B4B10DialogueManager
{
  public:
    int GetCurrentID();
};
extern B4B10DialogueManager* g_pkB4B10DialogueManager;

class B4B10Response
{
  public:
    void Reset();
    void Init(void* pvVoiceType, int iTopic, unsigned int uiFormType, int m_uiSoundID);
    void SetSpeaker(TESForm* pkSpeaker);
};

void __cdecl B4B10SetupResponse(B4B10Response* pkResponse, TESForm* pkSpeaker, int iTopic);

class B4B10Dialogue
{
  public:
    void SetupResponse(TESForm* pkSpeaker, int iTopic, B4B10Response* pkResponse);
};

// Resets and initialises the response from the speaker's voice type, form type and current dialogue ID, then sets the speaker and notifies it.
// @fnv 0x00854b10
void B4B10Dialogue::SetupResponse(TESForm* pkSpeaker, int iTopic, B4B10Response* pkResponse)
{
    pkResponse->Reset();
    pkResponse->Init(reinterpret_cast<void*>(pkSpeaker->GetHavokWorldObjectCountInSceneGraph_0084e3a0()), iTopic, static_cast<const TESForm*>(pkSpeaker)->FNV_GetFormType(),
                     g_pkB4B10DialogueManager->GetCurrentID());
    pkResponse->SetSpeaker(pkSpeaker);
    B4B10SetupResponse(pkResponse, pkSpeaker, iTopic);
    pkSpeaker->SaveGame(reinterpret_cast<BGSSaveFormBuffer*>(pkResponse));
}

struct SavedBuffer
{
    void* vtable;
    void* data;
    unsigned int capacity;
    unsigned int position;
    unsigned int size;
    void* references;
    unsigned int referenceCount;
    unsigned char version;
    unsigned int flags;
    SavedBuffer();
    ~SavedBuffer();
    void BGSSaveGameBuffer_ClearPosition();
    unsigned char GetVersion();
    unsigned int TESMain_GetThread();
    unsigned int GetValuePlusNine();
    int GetDifference();
};
struct SavedDataView
{
    void* data;
    void* Modelloader_GetReferencedThis();
    unsigned char BGSUnloadedFormBuffer_GetVersion();
    unsigned int GetAdjustedValue();
    unsigned int BGSUnloadedFormBuffer_GetSize();
    int BGSUnloadedFormBuffer_GetFormType();
};
struct SavedEntry
{
    unsigned int topic;
    SavedDataView buffer;
};
struct SavedEntryMap
{
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*&, unsigned int&, SavedEntry*&);
};
TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
bool __cdecl BGSSaveLoadGlobalData_SaveGlobalData(unsigned int, SavedBuffer*);
struct SavedStats
{
    void LoadStats();
    void BGSSaveLoadStatsMap_AddForm(unsigned int, TESForm*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                      unsigned char);
    void SetupResponse(TESForm*, unsigned int, SavedBuffer*);
    void BGSSaveLoadStatsMap_AddMiscSaveStat(int, int, unsigned int);
};
// Iterates saved entries, applying each to stats via FUN_008549b0, then processes indices 0-11 and 1000 through FUN_0084bcd0 and FUN_00854c10.
// @fnv 0x00853b90
void SavedStats::LoadStats()
{
    SavedBuffer map;
    SavedEntryMap* buffer = g_BGSSaveLoadGame->Modelloader_GetReferencedThis();
    void* position = buffer->FUN_004b9ba0();
    while (position)
    {
        unsigned int entryId = 0;
        SavedEntry* pEntry = 0;
        buffer->FUN_006b7f20(position, entryId, pEntry);
        if (pEntry->buffer.Modelloader_GetReferencedThis())
        {
            BGSSaveLoadStatsMap_AddForm(entryId, 0, pEntry->buffer.BGSUnloadedFormBuffer_GetFormType(), pEntry->topic, pEntry->buffer.BGSUnloadedFormBuffer_GetSize(),
                         pEntry->buffer.GetAdjustedValue(), 0, pEntry->buffer.BGSUnloadedFormBuffer_GetVersion());
        }
        else
        {
            TESForm* form = TESForm_GetFormByNumericID(entryId);
            if (form)
            {
                SetupResponse(form, pEntry->topic, &map);
                BGSSaveLoadStatsMap_AddForm(entryId, form, form->FNV_GetFormType(), pEntry->topic, map.GetDifference(),
                             map.GetValuePlusNine(), map.TESMain_GetThread(), map.GetVersion());
            }
        }
    }
    for (unsigned int index = 0; index < 12; ++index)
    {
        map.BGSSaveGameBuffer_ClearPosition();
        if (BGSSaveLoadGlobalData_SaveGlobalData(index, &map))
            BGSSaveLoadStatsMap_AddMiscSaveStat(BGSSaveLoadGlobalData_GetGlobalDataName(index), map.GetDifference(), map.TESMain_GetThread());
    }
    for (unsigned int index = 1000; index < 1001; ++index)
    {
        map.BGSSaveGameBuffer_ClearPosition();
        if (BGSSaveLoadGlobalData_SaveGlobalData(index, &map))
            BGSSaveLoadStatsMap_AddMiscSaveStat(BGSSaveLoadGlobalData_GetGlobalDataName(index), map.GetDifference(), map.TESMain_GetThread());
    }
}

#include <windows.h>
int GameStrcpy(char* dst, unsigned int size, const char* src);
int GameStrcat(char* dst, unsigned int size, const char* src);
int FUN_00ecbf05(const char* path, int mode);


struct TextDumpWriter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    TextDumpWriter();
    ~TextDumpWriter();
    void SetFile(BSFile* file);
    void WriteHeader();
    void WriteBody();
    void Close();
};

// Creates a .txt file from baseName, writes its header and body, then calls ShellExecuteA with the open verb.
// @fnv 0x00853a30
void DumpTextAndOpen(const char* baseName)
{
    TextDumpWriter writer;
    char path[260];
    GameStrcpy(path, 260, baseName);
    GameStrcat(path, 260, ".txt");
    if (FUN_00ecbf05(path, 0) != -1)
        DeleteFileA(path);
    writer.SetFile(new BSFile(path, 1, 0x4000, false));
    writer.WriteHeader();
    writer.WriteBody();
    writer.Close();
    ShellExecuteA(0, "open", path, 0, 0, 5);
}

namespace fnv_00853e10 {
void* _fnv_zlib_memset(void*, int, unsigned int);

int xSprintf(char*, unsigned int, const char*, ...);
int xStrcpy(char*, unsigned int, const char*);
int xStrcat(char*, unsigned int, const char*);
int xMbsnicmp(const char*, const char*, unsigned int);
const char* xFlagName(unsigned int, unsigned int, int);
struct xTypeName
{
    const char* m_name;
    int m_kPointA, m_kPointB;
};
extern xTypeName xg_TypeNames[];
struct xSizeArg
{
    xSizeArg(int);
    xSizeArg(const xSizeArg&);
    int m_v;
};
struct xSizer
{
    xSizer();
    ~xSizer();
    int GetSize();
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20;
};
struct xStats
{
    xStats();
    void Add(unsigned int, unsigned int, unsigned int);
    int GetTotal();
    float GetAverage();
    int m_uiItemCount, m_data, m_overhead, m_pDebugAllocator, m_kMinimumCorner, m_kMaximumCorner;
};
struct xChangeFlags
{
    bool Test(unsigned int) const;
    operator unsigned int();
    unsigned int m_v;
};
struct xChange
{
    unsigned int m_formID;
    xChangeFlags m_flags;
    unsigned int m_8, m_iThirdValue, m_10;
    TESForm* m_form;
    unsigned char m_ver;
    void Describe(char*, unsigned int);
    int GetSize();
};
struct xNodeL
{
    void** Head();
    xNodeL* Next();
    int m_kPointA, m_kPointB;
};
struct xMisc
{
    char m_name[0x104];
    unsigned int m_104, m_108;
    int GetCount();
};
struct xHistory
{
    const char* GetAt(unsigned int);
};
struct xSaveLoad
{
    xHistory* GetHistory();
};
extern xSaveLoad* xg_SaveLoad;
int __fastcall xHistoryCount(xHistory*);
struct SaveLoadStatsDump
{
    int m_00, m_04, m_08, m_0c;
    xNodeL m_10;
    void BGSSaveLoadStatsMap_OutputStats();
    void Write(const char*);
    void* GetFirstPos();
    void GetNext(void*&, unsigned int&, xNodeL*&);
    void Measure(TESForm*, xSizeArg, xSizer*);
};

// Writes a formatted dump of save/load form stats, misc stats, and save game history via Write.
// @fnv 0x00853e10
// src: XBOX_PDB 0x00853e10
void SaveLoadStatsDump::BGSSaveLoadStatsMap_OutputStats()
{
    void* qfTOqo;
    int qsSDDgz;
    xHistory* qSVM;
    int qpTd;
    xNodeL* qvyWyw;
    xSizer qpqRa;
    xStats qdqWL;
    char qHXYKT[0x3e8];
    xSprintf(qHXYKT, 0x3e8, "  %-8s %-5s %-8s %3s %-40s  %s\r\n\r\n", "Form ID", "Size", "Flags", "Ver", "Name",
             "Changes");
    Write(qHXYKT);
    qfTOqo = GetFirstPos();
    while (qfTOqo)
    {
        unsigned int qxQHW;
        xNodeL* qArxcFu;
        xStats qAhbO;
        qxQHW = 0;
        qArxcFu = 0;
        GetNext(qfTOqo, qxQHW, qArxcFu);
        xSprintf(qHXYKT, 0x3e8, "%ss:\r\n\r\n", xg_TypeNames[qxQHW].m_name);
        Write(qHXYKT);
        while (qArxcFu)
        {
            xChange* qJDuOZ = (xChange*)*qArxcFu->Head();
            if (qJDuOZ)
            {
                char qpia[0x3e8];
                qpia[0] = *"";
                _fnv_zlib_memset(qpia + 1, 0, sizeof(qpia) - 1);
                TESForm* qZWI;
                char qQGWBE[0x3e8];
                int qkJsUdT;
                char qIrY[0x3e8];
                char qdbVTq[0x3e8];
                qZWI = 0;
                qkJsUdT = 0;
                if (qJDuOZ->m_form)
                {
                    Measure(qJDuOZ->m_form, xSizeArg(0), &qpqRa);
                    qkJsUdT = qpqRa.GetSize();
                    if (qkJsUdT)
                    {
                        xStrcpy(qQGWBE, 0x3e8, "Base");
                        if (qJDuOZ->m_form->GetIsReference())
                        {
                            qZWI = qJDuOZ->m_form;
                            if (qZWI->IsMobileObject())
                            {
                                MobileObject* qIpA = static_cast<MobileObject*>(qZWI);
                                int qXMUYT = -1;
                                if (qIpA->FUN_008d8520())
                                    qXMUYT = qIpA->FUN_008d8520()->FUN_0045cd60();
                                switch (qXMUYT)
                                {
                                case -1:
                                    xStrcpy(qQGWBE, 0x3e8, "None");
                                    break;
                                case 3:
                                    xStrcpy(qQGWBE, 0x3e8, "Low");
                                    break;
                                case 2:
                                    xStrcpy(qQGWBE, 0x3e8, "Mid Low");
                                    break;
                                case 1:
                                    xStrcpy(qQGWBE, 0x3e8, "Mid High");
                                    break;
                                case 0:
                                    xStrcpy(qQGWBE, 0x3e8, "High");
                                    break;
                                }
                            }
                        }
                        xSprintf(qdbVTq, 0x3e8, "%s(%i)", qQGWBE, qkJsUdT);
                        xSprintf(qIrY, 0x3e8, "%-25s", qdbVTq);
                        xStrcat(qpia, 0x3e8, qIrY);
                    }
                }
                for (unsigned int qbfQdhM = 0; qbfQdhM < 0x20; qbfQdhM++)
                {
                    unsigned int qAXSCg = 1 << qbfQdhM;
                    if (qJDuOZ->m_flags.Test(qAXSCg))
                    {
                        xStrcpy(qQGWBE, 0x3e8, xFlagName(qAXSCg, qxQHW, 1));
                        if (qJDuOZ->m_form)
                        {
                            Measure(qJDuOZ->m_form, xSizeArg(qAXSCg), &qpqRa);
                            xSprintf(qdbVTq, 0x3e8, "%s(%i)", qQGWBE, qpqRa.GetSize() - qkJsUdT);
                        }
                        else
                            xSprintf(qdbVTq, 0x3e8, "%s", qQGWBE);
                        xSprintf(qIrY, 0x3e8, "%-25s", qdbVTq);
                        xStrcat(qpia, 0x3e8, qIrY);
                    }
                }
                xStrcpy(qQGWBE, 0x3e8, "");
                qJDuOZ->Describe(qQGWBE, 0x3e8);
                xSprintf(qHXYKT, 0x3e8, "  %08X %5i %08X %3i %-40s- %s\r\n", qJDuOZ->m_formID, qJDuOZ->GetSize(),
                         (unsigned int)qJDuOZ->m_flags, qJDuOZ->m_ver, qQGWBE, qpia);
                Write(qHXYKT);
            }
            qAhbO.Add(qJDuOZ->m_8, qJDuOZ->m_iThirdValue, qJDuOZ->m_10);
            qdqWL.Add(qJDuOZ->m_8, qJDuOZ->m_iThirdValue, qJDuOZ->m_10);
            qArxcFu = qArxcFu->Next();
        }
        xSprintf(
            qHXYKT, 0x3e8,
            "\r\nTotal %s Count: %i  Total %s Size: %i - Data: %i Overhead: %i Debug: %i Min %s Size: %i  Max %s Size: %i  Average %s Size: %.2f\r\n\r\n",
            xg_TypeNames[qxQHW].m_name, qAhbO.m_uiItemCount, xg_TypeNames[qxQHW].m_name, qAhbO.GetTotal(), qAhbO.m_data,
            qAhbO.m_overhead, qAhbO.m_pDebugAllocator, xg_TypeNames[qxQHW].m_name, qAhbO.m_kMinimumCorner,
            xg_TypeNames[qxQHW].m_name, qAhbO.m_kMaximumCorner, xg_TypeNames[qxQHW].m_name, qAhbO.GetAverage());
        Write(qHXYKT);
    }
    xSprintf(
        qHXYKT, 0x3e8,
        "\r\nTotal Form Count: %i  Total Form Size: %i - Data: %i Overhead: %i Debug: %i  Min Form Size: %i  Max Form Size: %i  Average Form Size: %.2f\r\n\r\n",
        qdqWL.m_uiItemCount, qdqWL.GetTotal(), qdqWL.m_data, qdqWL.m_overhead, qdqWL.m_pDebugAllocator,
        qdqWL.m_kMinimumCorner, qdqWL.m_kMaximumCorner, qdqWL.GetAverage());
    Write(qHXYKT);
    xStats qrEZrs;
    Write("\r\nMisc Stats:\r\n\r\n");
    qvyWyw = &m_10;
    while (qvyWyw)
    {
        xMisc* qBLsiu = (xMisc*)*qvyWyw->Head();
        if (qBLsiu)
        {
            xSprintf(qHXYKT, 0x3e8, "  %8i      %s\r\n", qBLsiu->GetCount(), qBLsiu);
            Write(qHXYKT);
            qrEZrs.Add(qBLsiu->m_104, 0, qBLsiu->m_108);
        }
        qvyWyw = qvyWyw->Next();
    }
    xSprintf(
        qHXYKT, 0x3e8,
        "\r\nTotal Misc Count: %i  Total Misc Size: %i - Data: %i Overhead: %i Debug: %i  Min Misc Size: %i  Max Misc Size: %i  Average Misc Size: %.2f\r\n\r\n",
        qrEZrs.m_uiItemCount, qrEZrs.GetTotal(), qrEZrs.m_data, qrEZrs.m_overhead, qrEZrs.m_pDebugAllocator,
        qrEZrs.m_kMinimumCorner, qrEZrs.m_kMaximumCorner, qrEZrs.GetAverage());
    Write(qHXYKT);
    qSVM = xg_SaveLoad->GetHistory();
    qpTd = xHistoryCount(qSVM);
    qsSDDgz = 0;
    if (qpTd)
    {
        Write("\r\n\r\nSave Game History:\r\n\r\n");
        for (unsigned int qrUCJDN = 0; qrUCJDN < (unsigned int)qpTd; qrUCJDN++)
        {
            const char* qpydTG = qSVM->GetAt(qrUCJDN);
            int qyFp = 0;
            if (!xMbsnicmp(qpydTG, "***", 3))
                qyFp = 1;
            else if (!xMbsnicmp(qpydTG, "---", 3))
            {
                qyFp = -1;
                qsSDDgz--;
            }
            for (int qhQRuW = 0; qhQRuW < qsSDDgz; qhQRuW++)
                Write("  ");
            Write(qyFp ? qpydTG + 3 : qpydTG);
            Write("\r\n");
            if (qyFp == 1)
                qsSDDgz++;
        }
    }
}
}  // namespace fnv_00853e10
