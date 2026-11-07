// fallout_shared/bgsmovablestatic.cpp: BGSMovableStatic, MovableRecord, MovableStaticFormComparison (11 functions)

#include "../../include/BGSMovableStatic.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectSTAT.h"
#include "../../include/TESFullName.h"
#include "../../include/TESChallenge.h"
#include "../../include/BGSDestructibleObjectForm.h"

// @fnv 0x004fbb50
void BGSMovableStatic::InitializeComponent()
{
    soundLoop = 0;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct TESSound;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob36
{
    char b[36];
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_004fbf00_shell : public BGSMovableStatic
{
    void MobileObject_SetTalkingActivatorRef(TESSound*);
};

// @fnv 0x004fbf00
// src: XBOX_PDB 0x004fbf00
void FUN_004fbf00_shell::MobileObject_SetTalkingActivatorRef(TESSound* apSound)
{
    *reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x6c) = apSound;
}

struct SFTX
{
    void SetFormType(int);
};
char* __fastcall MOVABLE_STATIC_DATA_MOVABLE_STATIC_DATA(char*);

struct MovableStaticObject : TESFullName, BGSDestructibleObjectForm, TESObjectSTAT
{
    MovableStaticObject();
    virtual ~MovableStaticObject();
};

// @fnv 0x004fba00
MovableStaticObject::MovableStaticObject()
{
    MOVABLE_STATIC_DATA_MOVABLE_STATIC_DATA((char*)this + 0x70);
    ((SFTX*)((char*)this + 0x14))->SetFormType(0x22);
    ((BGSMovableStatic*)this)->BGSMovableStatic::InitializeComponent();
}

struct FUN_004fc060_shell
{
    void __thiscall SetByteFromPtr(const unsigned char* src);
};

// @fnv 0x004fc060
void __thiscall FUN_004fc060_shell::SetByteFromPtr(const unsigned char* src)
{
    ((unsigned char*)this)[0] = *src;
}

struct Unk004fc130
{
    unsigned char m0;
    bool IsByteDifferent(unsigned char* p);
};
// Compares m0 with the byte pointed to by p and returns true if they differ.
// @fnv 0x004fc130
bool Unk004fc130::IsByteDifferent(unsigned char* pucByte)
{
    if (m0 != *pucByte)
        return true;
    return false;
}

void _Deallocate(void*);
struct Unk004fc170
{
    void FUN_004fbac0();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_004fbac0, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004fc170
void* Unk004fc170::DestroyIfFlagged(unsigned int flags)
{
    FUN_004fbac0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Date
{
    ~Date();
};
struct DoorPart68
{
    void FUN_00477f20();
};
struct DoorPart3c
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct FUN_00485e00_shell
{
    void TESForm___SaveData(Date*, int);
};
struct SoundH
{
    unsigned int Deallocate();
};
bool TESForm_QEndianSwapOnSave();
void TESForm_AddChunk_00485910(unsigned int, unsigned int);
struct FUN_004fbf20_shell
{
    void Destroy();
};
// @fnv 0x004fbf20
void FUN_004fbf20_shell::Destroy()
{
    unsigned int itempint;
    ((FUN_004855a0*)this)->M();
    ((TESFullName*)((char*)this - 0x14))->Save_00487010();
    ((DoorPart3c*)((char*)this + 0x30))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ((DoorPart68*)((char*)this - 8))->FUN_00477f20();
    if (TESForm_QEndianSwapOnSave())
        ((Date*)((char*)this + 0x5c))->Date::~Date();
    ((FUN_00485e00_shell*)this)->TESForm___SaveData((Date*)((char*)this + 0x5c), 1);
    if (TESForm_QEndianSwapOnSave())
        ((Date*)((char*)this + 0x5c))->Date::~Date();
    if (*(void**)((char*)this + 0x58))
    {
        itempint = (*(SoundH**)((char*)this + 0x58))->Deallocate();
        TESForm_AddChunk_00485910(0x4d414e53, itempint);
    }
    ((FUN_00485680*)this)->M();
}

// Empty destructor for the class; performs no work.
// @fnv 0x004fbac0
MovableStaticObject::~MovableStaticObject()
{}

extern "C" void* __cdecl _alloca(unsigned int);
struct AlchTexSwap
{
    unsigned int modelPath;
    unsigned int textureCount;
    unsigned int textures;
    unsigned int modelFlags;
    unsigned int modelBounds;
    unsigned int alternateTextures;
    unsigned int i;
    unsigned int modelSize;
    unsigned int modelUnknown;
    unsigned int modelReserved;
    unsigned int modelState;
    bool LoadTextureSwapList(void*, unsigned int, unsigned int);
};
void FUN_004892d0(AlchTexSwap*, TESFile*);
struct MovableRecord;
struct StaticRecord
{
    virtual bool LoadRecordChunks(TESFile*);
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void LoadBounds(TESFile*);
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void SetEditorID(const char*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    void LoadRecordHeader(TESFile*);
    void TESForm_LoadData(TESFile*, void*, unsigned short);
};
struct MovableRecord : TESFullName, BGSDestructibleObjectForm, StaticRecord, AlchTexSwap
{
    unsigned char data;
    virtual bool LoadRecordChunks(TESFile* file);
};
// Reads the record header, then loops over chunks dispatching editor ID, bounds, full name, models, destruction, data and sound chunks, returning true.
// @fnv 0x004fbc70
bool MovableRecord::LoadRecordChunks(TESFile* file)
{
    unsigned char p = file->GetTESForm();
    LoadRecordHeader(file);
    int h;
    char* a;
    void* i;
    unsigned int s;
    unsigned int f;
    while (h = file->GetChunkID())
    {
        switch (h)
        {
        case 0x44494445:
            a = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(a, 512);
            SetEditorID(a);
            break;
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x4c4c5546:
            TESFullName::LoadFullNameChunk(reinterpret_cast<TESFullName*>(this), file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            FUN_004892d0(this, file);
            break;
        case 0x53444f4d:
            s = file->GetChunkSize();
            i = _alloca(s);
            file->GetChunkData(i, s);
            this->LoadTextureSwapList(i, s, file->GetFormVersion());
            break;
        case 0x54534544:
        case 0x44545344:
            BGSDestructibleObjectForm::LoadDestructibleData(static_cast<BGSDestructibleObjectForm*>(this), file);
            break;
        case 0x41544144:
            TESForm_LoadData(file, &this->data, 1);
            break;
        case 0x4d414e53:
            f = 0;
            file->GetChunkData(&f);
            reinterpret_cast<FUN_004fbf00_shell*>(this)->MobileObject_SetTalkingActivatorRef(reinterpret_cast<TESSound*>(f));
            break;
        }
        if (!file->GetNextChunk())
            break;
    }
    return true;
}

class TESForm;
namespace fnv_004fbfe0 {
struct FUN_004fbf00_shell
{
    void MobileObject_SetTalkingActivatorRef(TESSound*);
};
struct FUN_004fc060_shell
{
    void SetByteFromPtr(const unsigned char*);
};
extern void* DAT_01183028;
extern void* DAT_01189d4c;

void* __cdecl FUN_00ec43fb(int, int, void*, void*, int);


struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
};

struct FUN_004fbfe0_shell : public TESObjectSTAT  // TESForm vftable slot 66 of BGSMovableStatic: this = TESObjectSTAT subobject (+0x14)
{
    void BGSMovableStatic_Copy(int);
};

// @fnv 0x004fbfe0
// src: COMMUNITY 0x004fbfe0
void FUN_004fbfe0_shell::BGSMovableStatic_Copy(int arg)
{
    int result = (int)FUN_00ec43fb(arg, 0, &DAT_01183028, &DAT_01189d4c, 0);

    if (result == 0)
        return;
    {
        reinterpret_cast<FUN_004fbf00_shell*>(reinterpret_cast<char*>(this) - 0x14)
            ->MobileObject_SetTalkingActivatorRef(reinterpret_cast<TESSound*>(reinterpret_cast<TESChallenge*>(result)->GetProgressValue()));

        reinterpret_cast<FUN_004fc060_shell*>(&reinterpret_cast<BGSMovableStatic*>(reinterpret_cast<char*>(this) - 0x14)->data)
            ->SetByteFromPtr(&reinterpret_cast<BGSMovableStatic*>(result)->data);

        reinterpret_cast<FUN_005e78f0_t*>(this)->TESForm_CopyAllComponents(
            result ? reinterpret_cast<::TESForm*>(reinterpret_cast<char*>(result) + 0x14) : 0);
    }
}
}  // namespace fnv_004fbfe0


struct MovableStaticComponentComparison
{
    bool TESForm_CompareAllComponents(::TESForm*);
};
struct MovableStaticDataComparison
{
    bool IsByteDifferent(unsigned char*);
};
struct MovableStaticSoundComparison
{
    ::TESSound* FUN_005e3fa0();
};
struct MovableStaticFormComparison : ::TESObjectSTAT  // TESForm vftable slot 67 of BGSMovableStatic: this = TESObjectSTAT subobject (+0x14)
{
    bool BGSMovableStatic_TESObjectSTAT_Compare(::TESForm* apCompare);
};
// Returns true if apCompare is not a BGSMovableStatic, either comparison helper returns true, or the sound results differ.
// @fnv 0x004fc080
// src: COMMUNITY 0x004fc080
bool MovableStaticFormComparison::BGSMovableStatic_TESObjectSTAT_Compare(::TESForm* apCompare)
{
    ::BGSMovableStatic* pMovableStatic = dynamic_cast< ::BGSMovableStatic*>(apCompare);
    if (!pMovableStatic)
        return true;
    if (((MovableStaticComponentComparison*)this)
            ->TESForm_CompareAllComponents(pMovableStatic ? (::TESForm*)((char*)pMovableStatic + 0x14) : 0))
        return true;
    if (((MovableStaticDataComparison*)&((::BGSMovableStatic*)((char*)this - 0x14))->data)->IsByteDifferent(&pMovableStatic->data))
        return true;
    if (((MovableStaticSoundComparison*)((char*)this - 0x14))->FUN_005e3fa0() !=
        ((MovableStaticSoundComparison*)pMovableStatic)->FUN_005e3fa0())
        return true;
    return false;
}
