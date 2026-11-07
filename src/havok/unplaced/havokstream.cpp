#include "../../../include/BSAudio.h"
#include "../../../include/BSFile.h"
#include "../../../include/NiBinaryStream.h"
#include "../../../include/MessageHandler.h"
#include "../../../include/HavokError.h"
#include "../../../include/hkBool.h"
#include "../../../include/hkFileSystem.h"

// src/havok/unplaced/havokstream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/havokstream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct B1
{
    virtual ~B1();
};

struct FUN_0056d6c0_class : B1
{
    void DestroyFields_0056d6c0();
};

// @fnv 0x0056d6c0
// src: GUESS 0x0056d6c0 (confidence: medium)
void FUN_0056d6c0_class::DestroyFields_0056d6c0()
{
    B1::~B1();
}

// @fnv 0x00624e70
// src: COMMUNITY 0x00624e70
int hkFileSystem::return_1_0(const char*, void*)
{
    return 1;
}

struct FUN_006264d0
{
    void __thiscall FUN_006264d1();
};
// @fnv 0x00625650
// src: XBOX_PDB 0x00625650
void __thiscall HavokError::enableAll_00625650()
{
    ((FUN_006264d0*)((char*)this + 0x14))->FUN_006264d1();
}

extern "C" void __cdecl _FNV_Warning(int, const char*);
// @fnv 0x00625a80
// src: XBOX_PDB 0x00625a80
void HavokError::showString(const char* pcMessage)
{
    MessageHandler::Handler();
    _FNV_Warning(4, pcMessage);
}

struct FUN_00625bd0_class
{
    void FUN_006264f0();
    void ForwardCall_00625bd0();
};

// @fnv 0x00625bd0
// src: GUESS 0x00625bd0 (confidence: low)
void FUN_00625bd0_class::ForwardCall_00625bd0()
{
    FUN_006264f0();
}

extern int DAT_0104dfb4;
struct FUN_00538ef0_class
{
    void* UpdateState_00538ef0();
};
struct FUN_00625fc0_class : FUN_00538ef0_class
{
    void* vtbl;
    FUN_00625fc0_class();
};
// @fnv 0x00625fc0
FUN_00625fc0_class::FUN_00625fc0_class()
{
    UpdateState_00538ef0();
    vtbl = (void*)&DAT_0104dfb4;
}

namespace fnv_00625fe0 {
extern int DAT_0104dfe8;
struct FUN_00538ef0_class
{
    void* UpdateState_00538ef0();
    void* InitializeFields_00625fe0();
};
// @fnv 0x00625fe0
// src: GUESS 0x00625fe0 (confidence: low)
void* FUN_00538ef0_class::InitializeFields_00625fe0()
{
    UpdateState_00538ef0();
    *(int**)this = &DAT_0104dfe8;
    return this;
}
}  // namespace fnv_00625fe0

extern "C" void __cdecl FUN_00625fc0();

struct FUN_00626000_Class
{
    const char* pStr;
    unsigned char b;
    unsigned char pad[3];
    unsigned char flag;
    void FUN_00625fc0();
    FUN_00626000_Class* ProcessAndReturnValue_00626000(int);
};

// Calls FUN_00625fc0, sets pStr to "0`b", writes 1 at offset 0xc, and returns this.
// @fnv 0x00626000
// src: GUESS 0x00626000 (confidence: low)
FUN_00626000_Class* FUN_00626000_Class::ProcessAndReturnValue_00626000(int)
{
    FUN_00625fc0();
    pStr = "0`b";
    *(unsigned char*)((char*)this + 0xc) = 1;
    return this;
}


struct FUN_00626100_shell
{
    void* pad0;
    void* pad1;
    NiBinaryStream* m_stream;
    unsigned int ReadFromStream(void* buffer, unsigned int size);
};

// Reads size bytes from m_stream into buffer and returns the result of the stream's Read call.
// @fnv 0x00626100
unsigned int FUN_00626100_shell::ReadFromStream(void* buffer, unsigned int size)
{
    return m_stream->Read(buffer, size);
}


struct FUN_00626320
{
    void* p;
    void* unused;
    BSFile* file;
    void Method(const void* data, unsigned int size);
};

// @fnv 0x00626320
void FUN_00626320::Method(const void* data, unsigned int size)
{
    file->NiBinaryStream_Write(data, size);
}

extern "C" BSAudio* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkMemoryRouter_easyFree(void* a, void* b);
// @fnv 0x00626760
// src: GUESS 0x00626760 (confidence: low)
void __cdecl Object_UpdateFields_00626760(void* a)
{
    BSAudio* p = hkMemoryRouter_getInstance();
    hkMemoryRouter_easyFree(p->GetAudioBackendData(), a);
}

struct FUN_006264b0_Class
{
    void hkPointerMap_int_int_hkContainerHeapAllocator_remove(int);
};
struct FUN_00626470_Class
{
    void hkPointerMap_int_int_hkContainerHeapAllocator_insert(int, int);
};
// HavokError: shared header lacks the SetErrorCodeEnabled override used here.
struct FUN_006255d0_class
{
    char pad[0x14];
    void HavokError_setEnabled(int a, int b);
};
// Converts the hkBool stored in b; if true forwards a to FUN_006264b0 at this+0x14, otherwise calls FUN_00626470 with a and 1.
// @fnv 0x006255d0
// src: XBOX_PDB 0x006255d0
void FUN_006255d0_class::HavokError_setEnabled(int a, int b)
{
    if (reinterpret_cast<const hkBool*>(&b)->operator bool())
        ((FUN_006264b0_Class*)((char*)this + 0x14))->hkPointerMap_int_int_hkContainerHeapAllocator_remove(a);
    else
        ((FUN_00626470_Class*)((char*)this + 0x14))->hkPointerMap_int_int_hkContainerHeapAllocator_insert(a, 1);
}

void __cdecl Tesland_UpdateState_00538eb0(void*);
struct FUN_00625f80_class : FUN_0056d6c0_class
{
    FUN_00625f80_class* FUN_00625f80(unsigned int flags);
};
// @fnv 0x00625f80
FUN_00625f80_class* FUN_00625f80_class::FUN_00625f80(unsigned int flags)
{
    DestroyFields_0056d6c0();
    if (flags & 1)
        Tesland_UpdateState_00538eb0(this);
    return this;
}

void __cdecl Tesland_UpdateState_00538eb0(void*);
struct FUN_00626030_class
{
    void __thiscall FUN_00626060();
    void* __thiscall FUN_00626030(unsigned int flags);
};
// Calls FUN_00626060, then if the low flag bit is set calls FUN_00538eb0 on this, and returns this.
// @fnv 0x00626030
void* __thiscall FUN_00626030_class::FUN_00626030(unsigned int flags)
{
    FUN_00626060();
    if (flags & 1)
        Tesland_UpdateState_00538eb0(this);
    return this;
}

void __cdecl Tesland_UpdateState_00538eb0(void*);
struct FUN_00626250_class
{
    void __thiscall FUN_00626280();
    void* __thiscall FUN_00626250(unsigned int flags);
};
// Calls FUN_00626280, then if bit 0 of flags is set calls FUN_00538eb0 on this, and returns this.
// @fnv 0x00626250
void* __thiscall FUN_00626250_class::FUN_00626250(unsigned int flags)
{
    FUN_00626280();
    if (flags & 1)
        Tesland_UpdateState_00538eb0(this);
    return this;
}

int __fastcall BSFile_Tell(char*);

struct FUN_00626390_class
{
    void* pad0;
    void* pad1;
    BSFile* pFile;
    int HavokFileStreambufReader_tell();
};

// Returns the result of FUN_004720a0 on pFile, or 0 when pFile is null.
// @fnv 0x00626390
// src: COMMUNITY 0x00626390
int FUN_00626390_class::HavokFileStreambufReader_tell()
{
    return pFile ? BSFile_Tell(reinterpret_cast<char*>(pFile)) : 0;
}

int __cdecl strcat_s(char*, unsigned int, const char*);
int __cdecl FUN_00462d40(const char*, int, int, int, int, char*, int, char*, int);
char* __cdecl hkString_strDup_00cb1410(const char*);
struct FUN_00626420_shell
{
    char* p;
    int aiLine;
};
struct ErrorFileList
{
    char* __thiscall UpdateFields_00626420(FUN_00626420_shell*);
};
// @fnv 0x00625e70
// src: XBOX_PDB 0x00625e70
void HavokError::disableReport(const char* apFile, int aiLine)
{
    char pfile[128];
    char pext[32];
    FUN_00626420_shell ap;
    FUN_00462d40(apFile, 0, 0, 0, 0, pfile, 128, pext, 32);
    strcat_s(pfile, 128, pext);
    ap.p = hkString_strDup_00cb1410(pfile);
    ap.aiLine = aiLine;
    ((ErrorFileList*)((char*)this + 8))->UpdateFields_00626420(&ap);
}

struct $SG2686
{
    virtual ~$SG2686();
};
struct FUN_00626060 : FUN_0056d6c0_class
{
    void* pad;
    void* p;
    unsigned char flag;
    virtual ~FUN_00626060();
};
// @fnv 0x00626060
FUN_00626060::~FUN_00626060()
{
    if (p && flag)
        delete static_cast<$SG2686*>(p);
}

struct FUN_00626280_shell : FUN_0056d6c0_class
{
    const char* pStr;
    void* p;
    unsigned char b;
    virtual ~FUN_00626280_shell();
};
// If p is set and b is true, deletes the object pointed to by p.
// @fnv 0x00626280
FUN_00626280_shell::~FUN_00626280_shell()
{
    if (p && b)
        delete (FUN_00626280_shell*)p;
}

void __cdecl FNV_Warning(int, const char*, const char*, int, const char*, const char*);
// @fnv 0x006259b0
void HavokError::ReportWarning(const char* apWhat, int aiID, const char* apDescription, const char* apFile,
                                       int aiLine)
{
    MessageHandler::Handler();
    FNV_Warning(0, "%s:%d: %s : %s'", apFile, aiLine, apWhat, apDescription);
}

// Reports a Havok error by calling _FNV_Warning with the file, line, description and what text.
// @fnv 0x00625a40
void __thiscall HavokError::ReportError(const char* apDescription, int aiID, const char* apWhat,
                                                const char* apFile, int aiLine)
{
    MessageHandler::Handler();
    FNV_Warning(2, "%s:%d: %s : %s'", apFile, aiLine, apDescription, apWhat);
}

// HavokError: retain the deleting-destructor stand-in until its member layout is shared.
struct FUN_00625b40_class : HavokError
{
    virtual ~FUN_00625b40_class();
    void* __thiscall FUN_00625b10(unsigned int flags);
};
// @fnv 0x00625b10
void* __thiscall FUN_00625b40_class::FUN_00625b10(unsigned int flags)
{
    this->FUN_00625b40_class::~FUN_00625b40_class();
    if (flags & 1)
        Tesland_UpdateState_00538eb0(this);
    return this;
}

struct CalleeObj
{
    void UpdateState_00622570(bool);
};
struct FUN_00626160
{
    void* pad0;
    void* pad1;
    void* pFile;
    bool TESAnimGroup_GetDecal();
    CalleeObj* Method(CalleeObj*);
};
// Calls FUN_00622570 on o with the result of FUN_008905f0 on pFile, or false when pFile is null, and returns o.
// @fnv 0x00626160
CalleeObj* FUN_00626160::Method(CalleeObj* apCallee)
{
    apCallee->UpdateState_00622570(pFile ? ((FUN_00626160*)pFile)->TESAnimGroup_GetDecal() : false);
    return apCallee;
}

extern "C" void* __cdecl Object_AllocateStorage_0056d280(unsigned int size);

struct FUN_00626000
{
    static void operator delete(void*);
    unsigned int source;
    unsigned int flags;
    unsigned int counter;
    unsigned int state;
    FUN_00626000(int index);
    static __forceinline void* operator new(unsigned int size)
    {
        return Object_AllocateStorage_0056d280(size);
    }
};

struct FUN_00624e90_Class
{
    FUN_00626000* HavokStreambufFactory_openReader(int index);
};

// Allocates and constructs a FUN_00626000 object with the given index, returning the new object.
// @fnv 0x00624e90
// src: XBOX_PDB 0x00624e90
FUN_00626000* FUN_00624e90_Class::HavokStreambufFactory_openReader(int index)
{
    return new FUN_00626000(index);
}

class B625F10Base
{
  public:
    B625F10Base();
    virtual ~B625F10Base();

    int unk04;
};

class B625F10List
{
  public:
    B625F10List();

    void* m_pvItem;
    B625F10List* m_pkNext;
};

class FUN_00625f10_cls : public B625F10Base, public B625F10List
{
  public:
    FUN_00625f10_cls();
    virtual ~FUN_00625f10_cls();
};

// @fnv 0x00625f10
FUN_00625f10_cls::FUN_00625f10_cls()
{}

extern void __cdecl bhkWorld_QuitSystem();

// @fnv 0x00625fb0
// src: COMMUNITY 0x00625fb0
void __cdecl HavokSystem_Kill()
{
    bhkWorld_QuitSystem();
}

struct FUN_00626120_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int v10();
};

struct FUN_00626120_cls
{
    void* pad0;
    void* pad1;
    FUN_00626120_obj* m_08;
    int GetV10OrMinusOne();
};
// Returns the result of calling v10 on m_08 if m_08 is non-null, otherwise returns -1.
// @fnv 0x00626120
int FUN_00626120_cls::GetV10OrMinusOne()
{
    return m_08 != 0 ? m_08->v10() : -1;
}

struct FUN_00625fe0
{
    FUN_00625fe0();
    ~FUN_00625fe0();
};

struct FUN_00b00260
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    FUN_00b00260(void* a, int b, int c, int d);
};

struct FUN_006261a0 : FUN_00625fe0
{
    const char* pStr;
    int unk04;
    FUN_00b00260* m_08;
    unsigned char m_0c;

    FUN_006261a0(void* arg);
};

// Initializes the object: sets pStr to a string literal, sets m_0c to 1, and allocates a FUN_00b00260 with arg, 1, 0x4000, 0.
// @fnv 0x006261a0
FUN_006261a0::FUN_006261a0(void* arg)
{
    pStr = "Pbb";
    m_0c = 1;
    m_08 = new FUN_00b00260(arg, 1, 0x4000, 0);
}

class C626340Handler
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void Handle(int iA, int iB);
};

class C626340Dispatcher
{
  public:
    int unk00;
    int unk04;
    C626340Handler* m_pkHandler;

    int DispatchToHandler(int iA, int iB);
};

// Calls m_pkHandler->Handle(iA, iB) if the handler is set and returns 0, otherwise returns 1.
// @fnv 0x00626340
int C626340Dispatcher::DispatchToHandler(int iA, int iB)
{
    int iResult = 1;
    if (m_pkHandler)
    {
        m_pkHandler->Handle(iA, iB);
        iResult = 0;
    }
    return iResult;
}

// Calls MessageHandler::Handler, then logs a warning with file, line, message and type via FNV_Warning.
// @fnv 0x00625a00
void HavokError::WarnWithLocation(const char* message, int unused, const char* type, const char* file, int line)
{
    MessageHandler::Handler();
    FNV_Warning(1, "%s:%d: %s : %s'", file, line, message, type);
}

class C624F90Base
{
  public:
    C624F90Base();
    virtual ~C624F90Base();

    int unk04;
};

class C624F90HandlerList
{
  public:
    C624F90HandlerList();
    ~C624F90HandlerList();

    int unk00;
    int unk04;
    int unk08;
};

class C624F90HandlerMap
{
  public:
    C624F90HandlerMap();
    ~C624F90HandlerMap();

    int unk00;
    int unk04;
    int unk08;
};

class C624F90Handler
{
  public:
    C624F90Handler(bool bEnabled);
    C624F90Handler(const C624F90Handler& kOther);

    int m_iFadeIndex;
};

extern const char g_ac624F90EventName[];

// HavokError: shared header lacks this constructor and its handler/event members.
class FUN_00624f90 : public C624F90Base
{
  public:
    FUN_00624f90();
    virtual ~FUN_00624f90();

    void AddHandler(unsigned int uiHash, C624F90Handler kHandler);
    void AddEvent(const char* pcName, int m_uiSoundID);

    C624F90HandlerList m_kHandlers;
    C624F90HandlerMap m_kEvents;
    bool m_bModifierActive;
};

// @fnv 0x00624f90
FUN_00624f90::FUN_00624f90()
{
    AddHandler(0x6E8D163B, C624F90Handler(false));
    AddHandler(0x6CEE9071, C624F90Handler(false));
    AddHandler(0xF0DE4355, C624F90Handler(false));
    AddHandler(0x2FF8C16F, C624F90Handler(false));
    AddHandler(0xF0FE4356, C624F90Handler(false));
    AddHandler(0x275EC1FD, C624F90Handler(false));
    AddHandler(0x1ADAAD0E, C624F90Handler(false));
    AddHandler(0x70DC41CB, C624F90Handler(false));
    AddHandler(0x1FF88F0E, C624F90Handler(false));
    AddHandler(0x475D86B1, C624F90Handler(false));
    AddHandler(0x6FE84A9B, C624F90Handler(false));
    AddHandler(0x21C8AB2A, C624F90Handler(false));
    AddHandler(0x309314D9, C624F90Handler(false));
    AddHandler(0xAD67FA3A, C624F90Handler(false));
    AddHandler(0xAD67FA3A, C624F90Handler(false));
    AddHandler(0xF032DE34, C624F90Handler(false));
    AddHandler(0x34DF5494, C624F90Handler(false));
    AddHandler(0xF02E32E1, C624F90Handler(false));
    AddHandler(0xF02E32E2, C624F90Handler(false));
    AddHandler(0xF02E32DF, C624F90Handler(false));
    AddHandler(0xF043D534, C624F90Handler(false));
    AddHandler(0xF02184ED, C624F90Handler(false));
    AddHandler(0xF02DE43E, C624F90Handler(false));
    AddHandler(0xF02E32E0, C624F90Handler(false));
    AddHandler(0xF02132DF, C624F90Handler(false));
    AddHandler(0xF02132FF, C624F90Handler(false));
    AddHandler(0x54006467, C624F90Handler(false));
    AddHandler(0x717C3B1D, C624F90Handler(false));
    AddHandler(0xF032DF30, C624F90Handler(false));
    AddHandler(0x0F0213DE, C624F90Handler(false));
    AddHandler(0xAD8966AA, C624F90Handler(false));
    AddHandler(0x2A1DB936, C624F90Handler(false));
    AddHandler(0x68C4E1DC, C624F90Handler(false));
    AddHandler(0x38F1276D, C624F90Handler(false));
    AddHandler(0xF03243DF, C624F90Handler(false));
    AddHandler(0x2FF8C16D, C624F90Handler(false));
    AddHandler(0xABBAEFBF, C624F90Handler(false));
    AddHandler(0x761EC287, C624F90Handler(false));
    AddHandler(0x53FE2EBC, C624F90Handler(false));
    AddHandler(0x1F0690F0, C624F90Handler(false));
    AddHandler(0x56F80833, C624F90Handler(false));
    AddEvent(g_ac624F90EventName, 38);
    AddEvent(g_ac624F90EventName, 86);
    AddEvent(g_ac624F90EventName, 93);
    AddEvent(g_ac624F90EventName, 106);
    AddEvent(g_ac624F90EventName, 110);
    AddEvent(g_ac624F90EventName, 115);
    AddEvent(g_ac624F90EventName, 126);
    AddEvent(g_ac624F90EventName, 133);
    AddEvent(g_ac624F90EventName, 191);
    AddEvent(g_ac624F90EventName, 246);
    AddEvent(g_ac624F90EventName, 277);
    m_bModifierActive = false;
}

struct FUN_00626490_Class
{
    int hkPointerMap_int_int_hkContainerHeapAllocator_getWithDefault(int a, int b);
};

// HavokError: shared header lacks the isEnabled override used here.
struct FUN_00625610_Class
{
    char unk00[0x14];
    FUN_00626490_Class m_sub;
    CalleeObj* HavokError_isEnabled(CalleeObj* obj, int b);
};

// Calls FUN_00626490(b, 0) on m_sub, passes whether the result equals 0 to obj->FUN_00622570, and returns obj.
// @fnv 0x00625610
// src: XBOX_PDB 0x00625610
CalleeObj* FUN_00625610_Class::HavokError_isEnabled(CalleeObj* obj, int b)
{
    obj->UpdateState_00622570(m_sub.hkPointerMap_int_int_hkContainerHeapAllocator_getWithDefault(b, 0) == 0);
    return obj;
}

// HavokError: shared header lacks FUN_00625c50 and the typed virtual isEnabled declaration.
struct ErrorHandler6256
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual hkBool IsEnabled(int aiSoundId);
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void ShowAssert(const char* pcType, int aiSoundId, const char* pcMessage, const char* pcFile, int iLine);
    virtual void ShowError(const char* pcType, int aiSoundId, const char* pcMessage, const char* pcFile, int iLine);
    virtual void ShowWarning(const char* pcType, int aiSoundId, const char* pcMessage, const char* pcFile, int iLine);
    virtual void ShowReport(const char* pcType, int aiSoundId, const char* pcMessage, const char* pcFile, int iLine);
    bool HavokError_isReportEnabled(const char* pcFile, int iLine);
    int ReportMessage(int iType, int aiSoundId, const char* pcMessage, const char* pcFile, int iLine);
};

// @fnv 0x00625670
int ErrorHandler6256::ReportMessage(int iType, int iMessageId, const char* pcMessage, const char* pcFile, int iLine)
{
    if (iMessageId == -1)
    {
        if (!HavokError_isReportEnabled(pcFile, iLine))
            return 0;
    }
    else if (!IsEnabled(iMessageId).operator bool())
        return 0;
    switch (iType)
    {
    case 0:
        ShowReport("Report", iMessageId, pcMessage, pcFile, iLine);
        break;
    case 1:
        ShowWarning("Warning", iMessageId, pcMessage, pcFile, iLine);
        break;
    case 2:
    case 3:
        ShowAssert("Assert", iMessageId, pcMessage, pcFile, iLine);
        break;
    default:
        ShowError("Error", iMessageId, pcMessage, pcFile, iLine);
        break;
    }
    return 1;
}

int __cdecl FUN_00406d30(char* pcDest, unsigned int uiSize, const char* pcSrc);
int __cdecl FUN_00406d50(char* pcDest, unsigned int uiSize, const char* pcSrc);
char* __cdecl FUN_00ec7750(const char* pcString, const char* pcFind);

struct LogStub6257
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int __cdecl Report(const char* pcFile, int iLine, const char* pcMessage);
};

LogStub6257* __cdecl BSCoreMessage_GetInstance();

struct FUN_00622570
{
    FUN_00622570(bool bValue);
    FUN_00622570(const FUN_00622570& kOther);
    int m_iValue;
};

// HavokError: shared header lacks the SDK path member and typed virtual Raise declaration.
struct ErrorHandler6257
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Raise(int aiSoundId, FUN_00622570 kResult);
    char m_acPad4[0x1c];
    char m_acSdkPath[0x104];
    void HavokError_assertMessage(const char* pcPrefix, int aiSoundId, const char* pcMessage, const char* pcFile, int iLine);
};

// Builds a prefix/message string, resolves the report file path against m_acSdkPath, reports it with the line number, and raises on result 5.
// @fnv 0x00625790
// src: XBOX_PDB 0x00625790
void ErrorHandler6257::HavokError_assertMessage(const char* pcPrefix, int aiSoundId, const char* pcMessage, const char* pcFile,
                                    int iLine)
{
    char acMsg[0x400];
    if (pcPrefix)
        FUN_00406d30(acMsg, 0x400, pcPrefix);
    else
        acMsg[0] = 0;
    if (pcMessage)
    {
        FUN_00406d50(acMsg, 0x400, " : ");
        FUN_00406d50(acMsg, 0x400, pcMessage);
    }
    int iLineNo = iLine;
    char acFileName[0x104];
    const char* pcReportFile = 0;
    if (m_acSdkPath[0])
    {
        pcReportFile = FUN_00ec7750(pcFile, "TES4");
        if (!pcReportFile)
            pcReportFile = FUN_00ec7750(pcFile, "tes4");
        if (pcReportFile)
        {
            FUN_00406d30(acFileName, 0x104, m_acSdkPath);
            FUN_00406d50(acFileName, 0x104, pcReportFile);
            pcReportFile = acFileName;
        }
        else if (pcFile[0] == '.' && pcFile[1] == '.')
        {
            FUN_00406d30(acFileName, 0x104, m_acSdkPath);
            FUN_00406d50(acFileName, 0x104, "TES4\\Havok\\SDK\\Include\\");
            FUN_00406d50(acFileName, 0x104, pcFile + 3);
            pcReportFile = acFileName;
        }
    }
    if (!pcReportFile)
    {
        pcReportFile = pcFile;
        iLineNo = iLine;
    }
    if (BSCoreMessage_GetInstance()->Report(pcReportFile, iLineNo, acMsg) == 5)
        Raise(aiSoundId, FUN_00622570(false));
}

const char* __cdecl hkString_strRchr(const char*, int);


// @fnv 0x00625aa0
// src: XBOX_PDB 0x00625aa0
const char* HavokError::hkGetFileBaseName(const char* apPath)
{
    const char* pSeparators = "/\\";
    for (int iIndex = 0; iIndex < 2; ++iIndex)
    {
        const char* pSeparatorPos = hkString_strRchr(apPath, pSeparators[iIndex]);
        if (!pSeparatorPos)
            apPath = pSeparatorPos;
        else
            apPath = pSeparatorPos + 1;
    }
    return apPath;
}

struct FUN_00625bf0_Item
{
    void* unk00;
    void* unk04;
};
struct FUN_00625bf0_Container
{
    int FUN_00726070();
    FUN_00625bf0_Item* ComputeValue_00626660(int index);
};
void __cdecl Object_UpdateFields_00626760(void* object);
struct FUN_00625bf0_Class
{
    void ProcessEntries_00625bf0(FUN_00625bf0_Container* container);
};
// Iterates the container's items and calls FUN_00626760 on each item's unk00 pointer.
// @fnv 0x00625bf0
// src: GUESS 0x00625bf0 (confidence: low)
void FUN_00625bf0_Class::ProcessEntries_00625bf0(FUN_00625bf0_Container* container)
{
    for (int index = 0; index < container->FUN_00726070(); ++index)
    {
        FUN_00625bf0_Item item = *container->ComputeValue_00626660(index);
        Object_UpdateFields_00626760(item.unk00);
    }
}

int __cdecl CompareStringsCaseInsensitive(const char* pcA, const char* pcB);

struct FileEntry625c
{
    const char* m_pcName;
    int m_iValue;
};

struct FileList625c
{
    int FUN_00726070();
    FileEntry625c* ComputeValue_00626660(int iIndex);
};

// HavokError: shared header lacks FUN_00625c50 and the file-list member.
struct FileFilter625c
{
    int unk00;
    int unk04;
    FileList625c m_kList;

    bool HavokError_isReportEnabled(const char* pcPath, int iValue);
};

// Builds a name-plus-extension string from pcPath, then returns false if any list entry matches it and has the same iValue; otherwise returns true.
// @fnv 0x00625c50
// src: XBOX_PDB 0x00625c50
bool FileFilter625c::HavokError_isReportEnabled(const char* pcPath, int iValue)
{
    if (m_kList.FUN_00726070())
    {
        char acExtBuf[32];
        char acName[128];
        FUN_00462d40(pcPath, 0, 0, 0, 0, acName, 0x80, acExtBuf, 0x20);
        strcat_s(acName, 0x80, acExtBuf);
        for (int i3 = 0; i3 < m_kList.FUN_00726070(); i3++)
        {
            FileEntry625c kEntry = *m_kList.ComputeValue_00626660(i3);
            if (!CompareStringsCaseInsensitive(acName, kEntry.m_pcName) && iValue == kEntry.m_iValue)
                return false;
        }
    }
    return true;
}

namespace fnv_00625d60 {
struct FileEntry625c
{
    const char* m_pcName;
    int m_iValue;
};

struct FileList625c
{
    int FUN_00726070();
    FileEntry625c* ComputeValue_00626660(int iIndex);
    void RemoveAt(int iIndex);
};

}  // namespace fnv_00625d60

// Builds a name from the path and extension, then removes the first list entry whose name matches and whose value equals iValue.
// @fnv 0x00625d60
void HavokError::RemoveEntryByPathAndValue(const char* pcPath, int iValue)
{
    char acExtBuf[32];
    char acName[128];
    FUN_00462d40(pcPath, 0, 0, 0, 0, acName, 0x80, acExtBuf, 0x20);
    strcat_s(acName, 0x80, acExtBuf);
    for (int i3 = 0; i3 < ((fnv_00625d60::FileList625c*)((char*)this + 8))->FUN_00726070(); i3++)
    {
        fnv_00625d60::FileEntry625c kEntry = *((fnv_00625d60::FileList625c*)((char*)this + 8))->ComputeValue_00626660(i3);
        if (!CompareStringsCaseInsensitive(acName, kEntry.m_pcName) && iValue == kEntry.m_iValue)
        {
            Object_UpdateFields_00626760((void*)kEntry.m_pcName);
            ((fnv_00625d60::FileList625c*)((char*)this + 8))->RemoveAt(i3);
            break;
        }
    }
}

// Representative of the native reference-counted stream base subobject.
struct StreamBase
{
    virtual void DestructorEntry();
    unsigned short memorySizeAndFlags;
    unsigned short referenceCount;
};
struct StreamObject : StreamBase
{
    BSFile* file;
    bool ownsFile;
    StreamObject(void* path);
    static __forceinline void* operator new(unsigned int size)
    {
        return Object_AllocateStorage_0056d280(size);
    }
};
struct StreamFactory
{
    StreamObject* CreateStreamObject(void* path);
};
// Allocates and returns a new StreamObject constructed from the given path.
// @fnv 0x00624f10
StreamObject* StreamFactory::CreateStreamObject(void* path)
{
    return new StreamObject(path);
}

class FUN_0056d6c0
{
  public:
    virtual ~FUN_0056d6c0();

    int unk04;
};

class FUN_0057c530
{
  public:
    ~FUN_0057c530();

    int unk00;
    int unk04;
    int unk08;
};

class FUN_00625bd0
{
  public:
    ~FUN_00625bd0();

    int unk00;
};

// HavokError: shared header lacks FUN_00625bf0 and the members requiring destruction.
class FUN_00625b40 : public FUN_0056d6c0
{
  public:
    virtual ~FUN_00625b40();

    void ProcessEntries_00625bf0(FUN_0057c530* pkList);

    FUN_0057c530 m_kList;
    FUN_00625bd0 m_kRef;
};

// Destructor that calls FUN_00625bf0 on m_kList before returning.
// @fnv 0x00625b40
FUN_00625b40::~FUN_00625b40()
{
    ProcessEntries_00625bf0(&m_kList);
}
