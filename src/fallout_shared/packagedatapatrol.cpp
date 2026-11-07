
// src/fallout_shared/packagedatapatrol.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedatapatrol.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/TESPatrolPackageData.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/MagicCaster.h"
// PackageEventActionData_packagedatapatrol: local type (was include/PackageEventActionData.h, which had no evidence of one real class); its methods are 0x0067da80 PackageEventAction::~PackageEventAction, 0x0067dad0 PackageEventAction::Copy, 0x0067dbf0 PackageEventAction::Compare, 0x0067dc80 TESPackageOnBeginEndOrChange_Save
class TESIdleForm;
class Script;
class TESTopic;
class TESForm;
class TESFile;
enum PACK_EVENT_ACTION_TYPE;

class PackageEventActionData_packagedatapatrol
{
public:
    TESIdleForm* m_pIdleForm;
    Script* m_pScript;
    TESTopic* pTopic;
    PACK_EVENT_ACTION_TYPE eType;

    PackageEventActionData_packagedatapatrol();
    void Clear();
    void CopyFrom(PackageEventActionData_packagedatapatrol* apCopy);
    bool IsDifferentFrom(PackageEventActionData_packagedatapatrol* apParam);
    void Save(int aeChunk);
    void* GetScript();
    void InitItem(TESForm* owner);
    void InitItem(int item);
    void Load(TESFile* file);
};

// Writes the two bytes at offsets 4 and 5 of this object into the save buffer via SaveData.
// @fnv 0x0067c5e0
void TESPatrolPackageData::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData(&m_bPrimaryComparisonFlag, 1, 0);
    apSaveGameBuffer->SaveData(&m_bSecondaryComparisonFlag, 1, 0);
}


// Reads two single bytes from the load buffer into the object at offsets 4 and 5.
// @fnv 0x0067c620
void __thiscall TESPatrolPackageData::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_bPrimaryComparisonFlag), 1);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_bSecondaryComparisonFlag), 1);
}

struct FUN_0067c650_shell
{
    float f;
    PackageEventActionData_packagedatapatrol sub;
    FUN_0067c650_shell();
};

// Initializes f to 0.0f and constructs the action data.
// @fnv 0x0067c650
FUN_0067c650_shell::FUN_0067c650_shell() : f(0.0f), sub()
{}

struct FUN_0067c670_shell
{
    void CallNestedMethod();
};

// @fnv 0x0067c670
void FUN_0067c670_shell::CallNestedMethod()
{
    reinterpret_cast<PackageEventActionData_packagedatapatrol*>(reinterpret_cast<char*>(this) + 4)->Clear();
}

// The shared header does not yet declare the two-byte constructor at 0x0067c450.
// Keep its local implementation until that declaration is available.
struct Base6450
{
    void __thiscall FUN_0067ad20();
};
extern int DAT_010689e4;
struct Param6450
{
    unsigned char a;
    unsigned char b;
};
struct S6450 : Base6450
{
    S6450* __thiscall TESPatrolPackageData_TESPatrolPackageData(Param6450 v);
};
// Calls FUN_0067ad20, stores a pointer to DAT_010689e4 at offset 0 and copies v.a and v.b into bytes at offsets 4 and 5, then returns this.
// @fnv 0x0067c450
// src: EXE 0x0067c450
S6450* __thiscall S6450::TESPatrolPackageData_TESPatrolPackageData(Param6450 aParams)
{
    FUN_0067ad20();
    *reinterpret_cast<unsigned int*>(this) = reinterpret_cast<unsigned int>(&DAT_010689e4);
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 4) = aParams.a;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5) = aParams.b;
    return this;
}

struct FUN_0067c690_t
{
    float m_fPatrolValue;
    PackageEventActionData_packagedatapatrol sub;
    FUN_0067c690_t(void* p);
};
// @fnv 0x0067c690
FUN_0067c690_t::FUN_0067c690_t(void* apValue)
    : m_fPatrolValue(*static_cast<float*>(apValue)), sub()
{}

struct Target0067c6f0
{
    float f;
    PackageEventActionData_packagedatapatrol c;
    void PatrolRefData_Copy(Target0067c6f0* src);
};
// @fnv 0x0067c6f0
// src: COMMUNITY 0x0067c6f0
void Target0067c6f0::PatrolRefData_Copy(Target0067c6f0* apSource)
{
    f = apSource->f;
    c.CopyFrom(&apSource->c);
}

struct FUN_0067c720_shell
{
    float m_fPatrolValue;
    void CallNestedMethod();
    bool PatrolRefData_Compare(const FUN_0067c720_shell* apCompare);
};
// @fnv 0x0067c720
// src: XBOX_PDB 0x0067c720
bool FUN_0067c720_shell::PatrolRefData_Compare(const FUN_0067c720_shell* apCompare)
{
    if (reinterpret_cast<PackageEventActionData_packagedatapatrol*>(reinterpret_cast<char*>(this) + 4)->IsDifferentFrom(
            reinterpret_cast<PackageEventActionData_packagedatapatrol*>(reinterpret_cast<char*>(const_cast<FUN_0067c720_shell*>(apCompare)) + 4)))
        return true;
    if (m_fPatrolValue != apCompare->m_fPatrolValue)
        return true;
    return false;
}


struct FUN_0067c6c0_shell
{
    char pad[4];
    MagicCaster caster;
    PackageEventActionData_packagedatapatrol action;
    void PatrolRefData_InitItem(int item);
};

// @fnv 0x0067c6c0
// src: XBOX_PDB 0x0067c6c0
void FUN_0067c6c0_shell::PatrolRefData_InitItem(int item)
{
    caster.SetSelectedMagicItem(3);
    reinterpret_cast<PackageEventActionData_packagedatapatrol*>(reinterpret_cast<char*>(this) + 4)->InitItem(item);
}

extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);
struct Date
{
    unsigned char b;
    unsigned short pad;
    ~Date();
};
bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl AppendChunk(unsigned int id, void* p, unsigned int size);

// @fnv 0x0067c570
// src: XBOX_PDB 0x0067c570
void TESPatrolPackageData::Save_0067c570()
{
    unsigned char patrolData[2];
    memset(patrolData, 0, 2);
    patrolData[0] = m_bPrimaryComparisonFlag;
    if (TESForm_QEndianSwapOnSave())
        ((Date*)patrolData)->Date::~Date();
    AppendChunk(0x54504b50, patrolData, 2);
    if (TESForm_QEndianSwapOnSave())
        ((Date*)patrolData)->Date::~Date();
}

// @fnv 0x0067c490
TESPatrolPackageData::~TESPatrolPackageData()
{}

// @fnv 0x0067da40
PackageEventActionData_packagedatapatrol::PackageEventActionData_packagedatapatrol()
{
    m_pIdleForm = 0;
    pTopic = 0;
    eType = static_cast<PACK_EVENT_ACTION_TYPE>(0);
    m_pScript = 0;
}

// @fnv 0x0067c500
// src: XBOX_PDB 0x0067c500
bool TESPatrolPackageData::Compare_0067c500(TESPackageData* apCompare)
{
    TESPatrolPackageData* pcomp = dynamic_cast<TESPatrolPackageData*>(apCompare);
    if (!pcomp)
        return true;
    if (m_bPrimaryComparisonFlag != pcomp->m_bPrimaryComparisonFlag)
        return true;
    if (m_bSecondaryComparisonFlag != pcomp->m_bSecondaryComparisonFlag)
        return true;
    return false;
}

// Copies the two boolean fields from a TESPatrolPackageData source into this TESPatrolPackageData instance.
// @fnv 0x0067c4b0
// src: XBOX_PDB 0x0067c4b0
void TESPatrolPackageData::Copy_0067c4b0(TESPackageData* apCopy)
{
    TESPatrolPackageData* pcopy;
    pcopy = dynamic_cast<TESPatrolPackageData*>(apCopy);
    if (!pcopy)
        return;
    m_bPrimaryComparisonFlag = pcopy->m_bPrimaryComparisonFlag;
    m_bSecondaryComparisonFlag = pcopy->m_bSecondaryComparisonFlag;
}
