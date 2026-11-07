// tesregiondatasound.cpp: TESRegionDataSound, F4BD0Owner, RegionSoundWriter, RegionBlend (17 functions)

#include "tesregiondatasound_decls.h"
// @fnv 0x004f4860
bool TESRegionDataSound::LoadRegionSoundData(TESFile* file)
{
    unsigned int sound = 0;
    switch ((int)file->GetChunkID())
    {
    case 0x444d4452: {
        unsigned int music = 0;
        file->GetChunkData(&music, 0);
        break;
    }
    case 0x4f4d4452: {
        unsigned int unused = 0;
        {
            unsigned int id = 0;
            file->GetChunkData(&id);
            if (id)
            {
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<RegionDataEntry&>(sounds.pType).Endian();
                TESForm::RemapFormIDForFile(id, file);
                BGSMusicType* music = dynamic_cast<BGSMusicType*>(TESForm::GetFormByID(id));
                if (!music)
                    Warning("MASTERFILE: Unable to find music type (%08X).", id);
                SetMusicType(music);
            }
        }
        break;
    }
    case 0x49534452: {
        unsigned int id = 0;
        file->GetChunkData(&id);
        if (id)
            sounds.uiIncidentalMediaSet = id;
        break;
    }
    case 0x42534452: {
        unsigned int id = 0;
        file->GetChunkData(&id);
        reinterpret_cast<BSSimpleList<ScriptVariableInfo*>*>(&sounds.battleMediaSetList)->AddTail(
            reinterpret_cast<ScriptVariableInfo* const&>(id));
        break;
    }
    case 0x44534452: {
        unsigned int uiChunkSize = file->GetChunkSize();
        {
            unsigned int count;
            {
                unsigned int stride = sizeof(RegionSoundEntry);
                count = uiChunkSize / stride;
                if (uiChunkSize == 4)
                    return false;
                RegionSoundEntry* buffer = new RegionSoundEntry[count];
                file->GetChunkData(buffer, count * sizeof(RegionSoundEntry));
                {
                    RegionSoundEntry* entry;
                    for (unsigned int i = 0; i < count; i++)
                    {
                        entry = new RegionSoundEntry;
                        *entry = buffer[i];
                        if (file->IsEndianConversionRequired())
                            reinterpret_cast<ContainerItemExtraFileData*>(entry)->Endian();
                        TESForm::RemapFormIDForFile(entry->sound, file);
                        if (entry && entry->sound && g_dataHandler->FUN_004615d0(entry->sound))
                        {
                            sound = g_dataHandler->FUN_004615d0(entry->sound);
                            entry->sound = sound;
                            reinterpret_cast<BSSimpleList<ScriptVariableInfo*>*>(&sounds.soundList)->AddTail(
                                reinterpret_cast<ScriptVariableInfo* const&>(entry));
                        }
                        else
                            delete entry;
                    }
                }
                delete[] buffer;
            }
        }
        break;
    }
    default:
        return false;
    }
    return true;
}

struct MersenneTwister
{
    void Init(unsigned int);
    void Seed(unsigned int);
    void Kill();
    unsigned int GetRandomUInt(unsigned int, unsigned int);
    unsigned int GetRandomUInt();
    unsigned int GetRandomUInt(unsigned int);
    int Int(int, int);
    int Int();
    float Float(float, float);
    float Float0To1();
    float FloatNeg1To1();
    float FloatTwoPi();
    float FloatNegPiToPi();
    bool Bool(float);
    static MersenneTwister* GetRandomGenerator();
    unsigned int m_uiSeed;
    unsigned int m_uiLastValue;
    char mt[2496];
    unsigned int mti;
};
typedef char _sizecheck_BSRandom[sizeof(MersenneTwister) == 2508 ? 1 : -1];
struct FUN_00944480_shell : public MersenneTwister
{
    int IntInRange(int, int);
};

// @fnv 0x00944480
int FUN_00944480_shell::IntInRange(int aiMin, int aiMax)
{
    return GetRandomUInt(aiMax - aiMin) + aiMin;
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(int*, EndianSizeTag<4>);
struct Arg_004727f0
{
    int* out;
};
// Reads a 4-byte chunk value into a.out and byte-swaps it when endian conversion is required; returns whether the read succeeded.
// @fnv 0x004727f0
bool __fastcall ReadChunkInt(TESFile* self, Arg_004727f0 aChunkArg)
{
    bool ok = self->GetChunkData(aChunkArg.out, 4);
    if (self->IsEndianConversionRequired())
        BSEndian(aChunkArg.out, EndianSizeTag<4>());
    return ok;
}

extern "C" TESForm* __cdecl GetFormByID(unsigned int);

struct FUN_004f4330_shell : TESRegionDataSound
{
    TESForm* GetSoundForm();
};

// @fnv 0x004f4330
TESForm* FUN_004f4330_shell::GetSoundForm()
{
    return GetFormByID(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x14));
}

struct FUN_004f4830_shell
{
    int a;
    int b;
    int c;
    FUN_004f4830_shell* Reset();
};

// Initialises the object's fields to a=0, b=0xf and c=0, then returns this.
// @fnv 0x004f4830
FUN_004f4830_shell* FUN_004f4830_shell::Reset()
{
    a = 0;
    b = 0xf;
    c = 0;
    return this;
}

struct FUN_004f4f70_shell
{
    int m_auiShapeKeys[2];
    int m_sounds;
    bool Validate();
};

// @fnv 0x004f4f70
bool FUN_004f4f70_shell::Validate()
{
    if (m_sounds)
        return false;
    return true;
}

struct MediaSet;
struct C0084e3a0
{
    unsigned int _ref_0084e3a0();
};
struct S004f4350
{
    void __thiscall SetMediaSet(MediaSet* ms);
};
// @fnv 0x004f4350
void __thiscall S004f4350::SetMediaSet(MediaSet* pMediaSet)
{
    *(unsigned int*)((char*)this + 0x14) = pMediaSet ? ((C0084e3a0*)pMediaSet)->_ref_0084e3a0() : 0;
}

struct F4390_standin
{
    void FUN_004f4520();
    void* FUN_004f4390(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_004f4520, then frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x004f4390
void* F4390_standin::FUN_004f4390(unsigned int flags)
{
    FUN_004f4520();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Not SL: a 12-byte member of the 0x004f43c0 object; built and destroyed by the folded BSSimpleList ctor 0x0096a2d0 / dtor 0x0046ffb0.
struct FUN_004f43c0_List
{
    int _00;
    int _04;
    int _08;
    FUN_004f43c0_List();
    ~FUN_004f43c0_List();
};
struct FUN_004f43c0
{
    int _00;
    FUN_004f43c0_List _04;
    FUN_004f43c0_List _10;
    FUN_004f43c0();
};
// @fnv 0x004f43c0
FUN_004f43c0::FUN_004f43c0()
{}

struct ListX
{
    int _00, _04, _08;
    ~ListX();
};
struct FUN_004f4420
{
    int _00;
    ListX _04;
    ListX _10;
    ~FUN_004f4420();
};
// Destructor for the object; destroys its two ListX members and returns.
// @fnv 0x004f4420
FUN_004f4420::~FUN_004f4420()
{}

struct FUN_004f4c40_shell
{
    char _pad[8];
    void* field8;
    bool TESRegionDataSound_SetMusicType(void* apType);
};
// Stores apType in field8 and returns true when apType is non-null and differs from the current field8; otherwise returns false.
// @fnv 0x004f4c40
// src: XBOX_PDB 0x004f4c40
bool FUN_004f4c40_shell::TESRegionDataSound_SetMusicType(void* apType)
{
    if (apType && apType != field8)
    {
        field8 = apType;
        return true;
    }
    return false;
}

// Copy constructor: copy the base, re-attach the source's owner, copy the id and start with an empty list.

class F4480Owner;

class F4480Base
{
  public:
    F4480Base(const F4480Base& kOther);
    virtual ~F4480Base();
    int unk04;
};

class F4480Children
{
  public:
    F4480Children();
    ~F4480Children();
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
};

class F4480List
{
  public:
    void RemoveAll();
    void* m_pkHead;
    void* m_pkTail;
};

class FUN_004f4480 : public F4480Base
{
  public:
    FUN_004f4480(const FUN_004f4480& kOther);
    virtual ~FUN_004f4480();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual F4480Owner* GetOwner() const;

    bool SetOwner(F4480Owner* pkOwner);

    F4480Children m_kChildList;
    int m_iID;
    F4480List m_kPending;
};

// Copy-constructs from kOther: copies the base, sets the owner, copies m_iID and clears m_kPending.
// @fnv 0x004f4480
FUN_004f4480::FUN_004f4480(const FUN_004f4480& kOther) : F4480Base(kOther)
{
    SetOwner(kOther.GetOwner());
    m_iID = kOther.m_iID;
    m_kPending.RemoveAll();
}

void __cdecl _Deallocate(void*);

struct F4BD0Item
{
    static void operator delete(void* pvMem)
    {
        _Deallocate(pvMem);
    }

    int unk00;
};

class F4BD0List
{
  public:
    F4BD0Item** GetItem();
    void RemoveHead();
    void Clear();

    F4BD0Item* m_pkItem;
    F4BD0List* m_pkNext;
};

class F4BD0Owner
{
  public:
    void ClearItems();

    int unk00;
    int unk04;
    int unk08;
    F4BD0List m_kUnsortedGeometryList;
};

// Repeatedly takes the head item from the list, deletes it, and finally clears the list.
// @fnv 0x004f4bd0
void F4BD0Owner::ClearItems()
{
    F4BD0List* pkList = &m_kUnsortedGeometryList;
    F4BD0Item* pkItem = 0;
    while (pkList && *pkList->GetItem())
    {
        pkItem = *pkList->GetItem();
        pkList->RemoveHead();
        delete pkItem;
        pkList = &m_kUnsortedGeometryList;
    }
    m_kUnsortedGeometryList.Clear();
}

struct SndBase
{
    virtual ~SndBase();
    unsigned int m_04;
};

struct FUN_004f4520_cls : SndBase
{
    FUN_004f4420 m_08;
    void Cleanup();
    virtual ~FUN_004f4520_cls();
};

// @fnv 0x004f4520
FUN_004f4520_cls::~FUN_004f4520_cls()
{
    Cleanup();
}

void __fastcall WriteSaveData(void*);
void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);
void __cdecl AppendChunk(unsigned int, void*, unsigned int);
bool __cdecl TESForm_QEndianSwapOnSave();
template <class T> struct RegionListAccess
{
    unsigned int FUN_005ae380();
    T& FUN_006815c0();
    RegionListAccess* FUN_00726070();
};
struct RegionSoundWriter : TESRegionDataSound
{
    void WriteRegionSoundData();
};
// Serializes the region's music type, sounds.uiIncidentalMediaSet sound, battle music IDs and sound records through FUN_00485910/AppendChunk.
// @fnv 0x004f4590
void RegionSoundWriter::WriteRegionSoundData()
{
    WriteSaveData(this);
    if (GetMusicType())
    {
        unsigned int musicID = ((C0084e3a0*)GetMusicType())->_ref_0084e3a0();
        TESForm_AddChunk_00485910(0x4f4d4452, musicID);
    }
    if (sounds.uiIncidentalMediaSet)
        TESForm_AddChunk_00485910(0x49534452, sounds.uiIncidentalMediaSet);
    unsigned int battleID = 0;
    unsigned int count = ((RegionListAccess<unsigned int>*)&sounds.battleMediaSetList)->FUN_005ae380();
    if (count)
    {
        RegionListAccess<unsigned int>* node = (RegionListAccess<unsigned int>*)&sounds.battleMediaSetList;
        for (unsigned int i = 0; node && node->FUN_006815c0() && i < count; i++)
        {
            TESForm_AddChunk_00485910(0x42534452, node->FUN_006815c0());
            node = node->FUN_00726070();
        }
    }
    RegionSoundEntry* sound = 0;
    count = ((RegionListAccess<RegionSoundEntry*>*)&sounds.soundList)->FUN_005ae380();
    if (count)
    {
        RegionListAccess<RegionSoundEntry*>* records = (RegionListAccess<RegionSoundEntry*>*)&sounds.soundList;
        RegionSoundEntry* node = new RegionSoundEntry[count];
        for (unsigned int i = 0; records && records->FUN_006815c0() && i < count; i++)
        {
            sound = records->FUN_006815c0();
            node[i] = *sound;
            records = records->FUN_00726070();
        }
        if (TESForm_QEndianSwapOnSave())
        {
            for (unsigned int i = 0; i < count; i++)
                ((ContainerItemExtraFileData*)&node[i])->Endian();
        }
        AppendChunk(0x44534452, node, count * sizeof(RegionSoundEntry));
        if (TESForm_QEndianSwapOnSave())
        {
            for (unsigned int i = 0; i < count; i++)
                ((ContainerItemExtraFileData*)&node[i])->Endian();
        }
        delete[] node;
    }
}

double __cdecl blendFloor(float);
class RegionBlend
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int Type();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void* Music();
    virtual void SetMusic(void*);
    unsigned char overrideFlag;
    unsigned char emptyFlag;
    unsigned char priority;
    unsigned char unk07;
    unsigned char Override();
    unsigned char Priority();
    void SetOverride(int);
    bool SetPriority(unsigned char);
    void BlendFrom(RegionBlend*, void*);
};
// Blends this region's override, priority and music from a type-7 source region, weighting priorities when neither overrides.
// @fnv 0x004f4cf0
void RegionBlend::BlendFrom(RegionBlend* source, void* context)
{
    RegionBlend* other = source;
    if (!source || source->Type() != 7 || !context)
        return;
    if (emptyFlag)
    {
        SetOverride(other->Override());
        SetPriority(other->Priority());
        SetMusic(other->Music());
    }
    else if (other->emptyFlag)
    {
        return;
    }
    else if (overrideFlag)
    {
        if (other->Override() && other->Priority() > Priority())
        {
            SetOverride(other->Override());
            SetPriority(other->Priority());
            SetMusic(other->Music());
        }
        return;
    }
    else if (other->Override())
    {
        SetOverride(other->Override());
        SetPriority(other->Priority());
        SetMusic(other->Music());
    }
    else
    {
        if (other->Priority() > Priority())
            SetMusic(other->Music());
        float weight = Priority() * Priority() + (100 - Priority()) * other->Priority();
        weight += (100 - other->Priority()) * Priority() + other->Priority() * other->Priority();
        weight *= 0.004999999888241291;
        SetPriority((unsigned char)blendFloor(weight));
    }
}

struct S004;
struct Obj4480
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Obj4480* FUN_004f4480(S004* owner);
    Obj4480(S004* owner)
    {
        FUN_004f4480(owner);
    }
};
struct S004
{
    Obj4480* CreateObj4480();
};
// Allocates a new Obj4480 instance with this S004 as owner and returns the pointer.
// @fnv 0x004f4c70
Obj4480* S004::CreateObj4480()
{
    Obj4480* result = new Obj4480(this);
    return result;
}
