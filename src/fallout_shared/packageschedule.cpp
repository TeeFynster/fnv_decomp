// fallout_shared/packageschedule.cpp: PackedByteIntRecord, DurationData (9 functions)

#include "layout_support.h"
#include "../../include/QuestData.h"

class PackedByteIntRecord
{
  public:
    char m_cByte0;
    char m_cByte1;
    char m_cByte2;
    char m_cLastByteBeforePayloadItem;
    int m_iPayloadInteger;
    void* Endian();
};

// @fnv 0x0087eaa0
void* PackedByteIntRecord::Endian()
{
    return (void*)((char*)this + 0x40);
}

struct DurationData
{
    int GetStartMonth();
    void SetStartMonth(int);
    int GetStartDayOfWeek();
    void SetStartDayOfWeek(int);
    char GetStartDate();
    void SetStartDate(char);
    char GetStartTime();
    void SetStartTime(char);
    int GetDuration();
    void SetDuration(int);
    void Copy(DurationData*);
    bool Compare(DurationData*);
    void Save();
    char* GetDayOfWeekName();
    char* GetMonthName();
    void* __vecDelDtor(unsigned int);
    PackedByteIntRecord m_kScheduleData;
};
typedef char _sizecheck_PackageSchedule[sizeof(DurationData) == 8 ? 1 : -1];
struct FUN_0067fcb0_shell : public DurationData
{
    void ResetSchedule(PackedByteIntRecord*);
};

// @fnv 0x0067fcb0
DurationData* __fastcall ResetSchedule(DurationData* pThis)
{
    pThis->m_kScheduleData.m_cByte0 = -1;
    pThis->m_kScheduleData.m_cByte1 = -1;
    pThis->m_kScheduleData.m_cByte2 = 0;
    pThis->m_kScheduleData.m_cLastByteBeforePayloadItem = -1;
    pThis->m_kScheduleData.m_iPayloadInteger = 0;
    return pThis;
}

namespace fnv_0067fd40 {
struct DurationData
{
    int GetStartMonth();
    void SetStartMonth(int);
    int GetStartDayOfWeek();
    void SetStartDayOfWeek(int);
    char GetStartDate();
    void SetStartDate(char);
    char GetStartTime();
    void SetStartTime(char);
    int GetDuration();
    void SetDuration(int);
    void Copy(DurationData*);
    bool Compare(DurationData*);
    void Save();
    char* GetDayOfWeekName();
    char* GetMonthName();
    void* __vecDelDtor(unsigned int);
    PackedByteIntRecord m_kScheduleData;
};
typedef char _sizecheck_PackageSchedule[sizeof(DurationData) == 8 ? 1 : -1];
struct FUN_0067fd40_shell : public DurationData
{
    void PackageSchedule_Copy(DurationData*);
};

// Copies the start month, day of week, date, time and duration from apCopy into this schedule when apCopy is non-null.
// @fnv 0x0067fd40
// src: COMMUNITY 0x0067fd40
void FUN_0067fd40_shell::PackageSchedule_Copy(DurationData* apCopy)
{
    if (apCopy)
    {
        SetStartMonth(apCopy->GetStartMonth());
        SetStartDayOfWeek(apCopy->GetStartDayOfWeek());
        SetStartDate(apCopy->GetStartDate());
        SetStartTime(apCopy->GetStartTime());
        SetDuration(apCopy->GetDuration());
    }
}
}  // namespace fnv_0067fd40

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
// CombatCoverPointData_packageschedule: local type (was include/CombatCoverPointData.h, which had no evidence of one real class); its methods are 0x005dc960 Main::GameOver, 0x0067fdb0 PackageSchedule::SetStartDayOfWeek, 0x009a2ea0 CombatCoverLocation::LoadGameBGS
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;

class CombatCoverPointData_packageschedule
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;

    void Copy(void*);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    bool IsHideCover();
    bool IsCrouchCover();
    bool IsStandCover();
    bool IsLedgeCover();
    bool IsValidCover();
    unsigned char GetCoverHeight();
    bool IsReserved();
    void SetReserved(bool);
    bool IsDirty();
    void SetDirty(bool);
    void* __vecDelDtor(unsigned int);
};
typedef char _sizecheck_CombatCoverLocation[sizeof(CombatCoverPointData_packageschedule) == 120 ? 1 : -1];
struct FUN_0067fdb0_shell : public CombatCoverPointData_packageschedule
{
    void PackageSchedule_SetStartDayOfWeek(bool);
};

// @fnv 0x0067fdb0
// src: COMMUNITY 0x0067fdb0
void FUN_0067fdb0_shell::PackageSchedule_SetStartDayOfWeek(bool abValue)
{
    *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 1) = abValue;  // bReserved (+0x1); the shared CombatCoverPointData_packageschedule names no fields
}

extern "C" unsigned char __cdecl TESForm_QEndianSwapOnSave();
extern "C" void __cdecl AppendChunk(int, void*, int);

struct FUN_0067fec0_shell
{
    void Save();
};

// @fnv 0x0067fec0
void FUN_0067fec0_shell::Save()
{
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<QuestData*>(this)->Endian();
    AppendChunk(0x54445350, this, 8);
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<QuestData*>(this)->Endian();
}

struct FUN_0067fcf0_shell : PackedByteIntRecord
{
    FUN_0067fcf0_shell* AssignFrom(const FUN_0067fcf0_shell& other);
};
// Copies five fields from other into this and returns this.
// @fnv 0x0067fcf0
FUN_0067fcf0_shell* FUN_0067fcf0_shell::AssignFrom(const FUN_0067fcf0_shell& other)
{
    m_cByte0 = other.m_cByte0;
    m_cByte1 = other.m_cByte1;
    m_cByte2 = other.m_cByte2;
    m_cLastByteBeforePayloadItem = other.m_cLastByteBeforePayloadItem;
    m_iPayloadInteger = other.m_iPayloadInteger;
    return this;
}

struct FUN_0067fdd0_shell : PackedByteIntRecord
{
    void SetByteValue(unsigned char value);
};

// @fnv 0x0067fdd0
void FUN_0067fdd0_shell::SetByteValue(unsigned char value)
{
    m_cByte2 = value;
}

struct FUN_0067fdf0_shell
{
    void SetByteAtOffset3(unsigned char param_2);
};

// @fnv 0x0067fdf0
void FUN_0067fdf0_shell::SetByteAtOffset3(unsigned char aucValue)
{
    *(unsigned char*)((char*)this + 3) = aucValue;
}

namespace fnv_0067fe10 {
struct BoundHolder
{
    int GetBoundingRadius();
};
struct DurationData : BoundHolder
{
    int GetSecondByte();
    char Main_GameReset();
    char FUN_0086a460();
    int _ref_00726070();
    char EvaluateValue_0067fe10(DurationData* other);
};
// Returns 1 if other is null or any of five compared values differ, otherwise returns 0.
// @fnv 0x0067fe10
// src: GUESS 0x0067fe10 (confidence: low)
char DurationData::EvaluateValue_0067fe10(DurationData* other)
{
    if (!other)
        return 1;
    if (GetSecondByte() != other->GetSecondByte())
        return 1;
    if (GetBoundingRadius() != other->GetBoundingRadius())
        return 1;
    if (Main_GameReset() != other->Main_GameReset())
        return 1;
    if (FUN_0086a460() != other->FUN_0086a460())
        return 1;
    if (_ref_00726070() != other->_ref_00726070())
        return 1;
    return 0;
}
}  // namespace fnv_0067fe10
