// fallout_shared/tesactorbasedata.cpp: actor base attributes and data

#include "layout_support.h"
#include "../../include/ActorBaseAttributes.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/Actor.h"
#include "../../include/BGSVoiceType.h"
#include "../../include/RecursiveSpinLock.h"
#include "../../include/SettingT_GameSettingCollection_.h"
#include "../../include/StartMenu.h"
#include "../../include/TESAttackDamageForm.h"
#include "../../include/TESContainer.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESFaction.h"
#include "../../include/TESForm.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESFullName.h"
#include "../../include/TESLevItem.h"
#include "../../include/TESReactionForm.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/SETTING_VALUE.h"
#include "../../include/TESChildCell.h"

// @fnv 0x0047c700
TESActorBaseData::TESActorBaseData()
{
    InitializeComponent();
}

// @fnv 0x0047c880
TESActorBaseData::~TESActorBaseData()
{
    ClearComponent();
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting18;
extern SettingT_GameSettingCollection_ g_011c5074;
extern SettingT_GameSettingCollection_ g_011c50d8;

// @fnv 0x0047c8e0
void TESActorBaseData::InitializeComponent()
{
    actorData.m_uiActorFlags = 0;
    actorData.m_usField04 = (unsigned short)originalRuntimeFloatSetting18.Float()->f;
    actorData.m_usField06 = 0;
    actorData.sLevel = 1;
    actorData.m_usField0A = 0;
    actorData.m_usField0C = 0;
    actorData.m_usField0E = 100;
    actorData.m_fField10 = g_011c5074.Float()->f;
    actorData.m_usField14 = (unsigned short)*g_011c50d8.Setting_Int();
    m_kFactionList = 0;
    m_pBaseTemplateForm = 0;
    m_ppTemplateForms = 0;
    actorData.m_usField16 = 0;
    m_pDeathItem = 0;
}

class NiColor;

void __cdecl operator delete(void*);
bool __fastcall _ref_008256d0(void*);
void** __fastcall _ref_006815c0(void*);
void __fastcall _ref_0063f7b0(void*);

// Deletes every faction entry in the actor base list.
// @fnv 0x0047c9d0
void TESActorBaseData::RemoveAllFactions()
{
    void* pList = GetFactionList();
    while (pList && !_ref_008256d0(pList))
    {
        void* item = *_ref_006815c0(pList);
        operator delete(item);
        _ref_0063f7b0(pList);
    }
}

// @fnv 0x0047cca0
bool TESActorBaseData::QCopiedTemplate()
{
    return GetTemplateUseFlag(0xf);
}

// @fnv 0x0047ccc0
void TESActorBaseData::SetCopiedTemplate(bool abVal)
{
    SetTemplateUseFlag(0xf, abVal);
}

// Sets or clears bit `index` in the 16-bit flags field when index is in [0,16).
// @fnv 0x0047cce0
void TESActorBaseData::SetTemplateUseFlag(int index, bool set)
{
    if (index >= 0 && index < 16)
    {
        unsigned short mask = 1 << index;
        if (set)
            actorData.m_usField16 |= mask;
        else
            actorData.m_usField16 &= ~mask;
    }
}

// Returns true if the 16-bit flag word at offset 0x1a has the bit for aeFlag set; out-of-range flags return true.
// @fnv 0x0047cd40
bool TESActorBaseData::GetTemplateUseFlag(int aeFlag)
{
    if (aeFlag >= 0 && aeFlag < 16)
    {
        unsigned short usFlagMask = 1 << aeFlag;
        if (actorData.m_usField16 & usFlagMask)
            return true;
        return false;
    }
    return true;
}

// @fnv 0x0047cd90
void TESActorBaseData::SetTemplateUseFlags(unsigned short asVal)
{
    actorData.m_usField16 = asVal;
}

// @fnv 0x0047cdb0
bool TESActorBaseData::GetUsesLeveledTemplate()
{
    bool bretval = IsTemplateLeveled();
    return bretval;
}

int __fastcall _FNV_GetFormType(void*);

// Returns true if the pointer at offset 0x24 is non-null and its form type is 0x2c or 0x2d.
// @fnv 0x0047cdd0
bool TESActorBaseData::IsTemplateLeveled()
{
    bool bretval = false;
    if (m_ppTemplateForms)
    {
        switch (_FNV_GetFormType(m_ppTemplateForms))
        {
        case 0x2c:
        case 0x2d:
            bretval = true;
            break;
        }
    }
    return bretval;
}

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
int __fastcall _FNV_GetFormType(TESActorBase*);

struct DummyActorBase : TESBoundAnimObject, TESActorBaseData
{
};

// @fnv 0x0047d130
// src: COMMUNITY 0x0047d130
TESActorBase* __cdecl TESActorBaseData_CreateTemplateActorBase(TESActorBase* apOriginalBase, TESActorBase* apTemplateBase)
{
    DummyActorBase* pnewbase;
    bool breset = g_BGSSaveLoadGame->SetThreadAllowChanges(false);
    pnewbase = (DummyActorBase*)TESDataHandler::CreateFormForType(_FNV_GetFormType(apOriginalBase));
    pnewbase->CopyFrom(reinterpret_cast<TESForm*>(apOriginalBase));
    pnewbase->CopyFromTemplateForm(apTemplateBase);
    g_BGSSaveLoadGame->SetThreadAllowChanges(breset);
    return (TESActorBase*)pnewbase;
}

// @fnv 0x0047d1a0
TESForm* __cdecl FindFirstNonActorBaseTemplate(TESForm* apBase, unsigned short* aiOutCompositeTemplateUseFlags)
{
    TESForm* pNonActorBase = 0;
    *aiOutCompositeTemplateUseFlags = 0xFFFF;
    TESForm* pCurrent = apBase;
    while (pCurrent)
    {
        if (pCurrent->Unk_3E())
        {
            TESForm* ptempbase = pCurrent;
            *aiOutCompositeTemplateUseFlags &= *(unsigned short*)((char*)ptempbase + 0x4A);
            pCurrent = ((TESActorBaseData*)((char*)ptempbase + 0x30))->QTemplateForm();
        }
        else
        {
            pNonActorBase = pCurrent;
            pCurrent = 0;
        }
    }
    return pNonActorBase;
}

// @fnv 0x0047d370
unsigned short TESActorBaseData::GetLevelExact()
{
    return actorData.sLevel;
}

// @fnv 0x0047d390
// src: COMMUNITY 0x0047d390
unsigned short TESActorBaseData::GetCalcLevelMin_0047d390()
{
    return actorData.m_usField0A;
}

namespace fnv_0047d680 {
struct FACTION_RANK_local
{
    TESFaction* faction;
    signed char rank;
};

FACTION_RANK_local** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
bool __fastcall HasFactionFlag8(TESFaction*);

}  // namespace fnv_0047d680

// @fnv 0x0047d680
int TESActorBaseData::GetFactionRank(TESFaction* apFaction, bool abPC)
{
    using namespace fnv_0047d680;
    void* pList = GetFactionList();
    while (pList && *fnv_0047d680::_ref_006815c0(pList))
    {
        FACTION_RANK_local* prank = *fnv_0047d680::_ref_006815c0(pList);
        if (abPC)
        {
            if (prank && !fnv_0047d680::HasFactionFlag8(prank->faction) && prank->faction == apFaction)
                return prank->rank;
        }
        else
        {
            if (prank && prank->faction == apFaction)
                return prank->rank;
        }
        pList = fnv_0047d680::_ref_00726070(pList);
    }
    return -1;
}

// Stores aiNewFlags into the field at offset 4 of this and calls AddFormChange with 2.
// @fnv 0x0047dd30
void TESActorBaseData::SetFlags(int aiNewFlags)
{
    actorData.m_uiActorFlags = aiNewFlags;
    AddFormChange(2);
}

// Updates the minimum calculated level and records the change.
// @fnv 0x0047de40
void TESActorBaseData::SetCalcLevelMin(unsigned short ausValue)
{
    actorData.m_usField0A = ausValue;
    AddFormChange(2);
}

// Stores the given value in v and calls AddFormChange with 2.
// @fnv 0x0047de70
void TESActorBaseData::SetCalcLevelMax(unsigned short ausValue)
{
    actorData.m_usField0C = ausValue;
    AddFormChange(2);
}

// Stores the given value in v and calls AddFormChange with 2.
// @fnv 0x0047dfe0
void TESActorBaseData::SetLevel(unsigned short ausValue)
{
    actorData.sLevel = ausValue;
    AddFormChange(2);
}

// Stores the given value in v and calls AddFormChange with 2.
// @fnv 0x0047e010
void TESActorBaseData::SetFatigue(unsigned short ausValue)
{
    actorData.m_usField04 = ausValue;
    AddFormChange(2);
}

extern StartMenu* DAT_01186d20[][50];
extern const char DAT_01011584[];
unsigned int __cdecl TESActorBaseData_GetAlignmentForKarma(float);
// @fnv 0x0047e0e0
// src: XBOX_PDB 0x0047e0e0
const char* TESActorBaseData_GetKarmicTitle(Actor* actor)
{
    const char* result = 0;
    if (actor)
    {
        unsigned int kind;
        int level;
        level = actor->GetLevel();
        level = level - 1;
        if (level > 0x31)
            level = 0x31;
        if (level < 0)
            level = 0;
        kind = TESActorBaseData_GetAlignmentForKarma((float)actor->GetActorValue(static_cast<ActorValue::Index>(0x17)));
        if (kind > 2)
        {
            if (kind == 3)
                kind = 0;
            else
                kind = 2;
        }
        if (DAT_01186d20[kind][level])
            result = static_cast<const StartMenu*>(DAT_01186d20[kind][level])->GetMenuTitle();
    }
    if (!result)
        result = DAT_01011584;
    return result;
}

namespace fnv_0047e1c0 {

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting25;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting24;
}  // namespace fnv_0047e1c0

// Clamps karma to the runtime settings and records the change.
// @fnv 0x0047e1c0
void TESActorBaseData::SetKarmaValue(float afValue)
{
    using namespace fnv_0047e1c0;
    actorData.m_fField10 = afValue;
    if (actorData.m_fField10 > originalRuntimeFloatSetting25.Float()->f)
        actorData.m_fField10 = originalRuntimeFloatSetting25.Float()->f;
    else if (actorData.m_fField10 < originalRuntimeFloatSetting24.Float()->f)
        actorData.m_fField10 = originalRuntimeFloatSetting24.Float()->f;
    AddFormChange(2);
}

// Updates barter gold and records the change.
// @fnv 0x0047e240
void TESActorBaseData::SetBarterGold(unsigned short asValue)
{
    actorData.m_usField06 = asValue;
    AddFormChange(2);
}

// Stores asSpeedMult at offset 0x12 of this object and calls AddFormChange with this and 2.
// @fnv 0x0047e270
void TESActorBaseData::SetSpeedMult(unsigned short asSpeedMult)
{
    actorData.m_usField0E = asSpeedMult;
    AddFormChange(2);
}

// @fnv 0x0047e2a0
void TESActorBaseData::AddFormChange(int aiChangeFlags)
{
    ::TESActorBase* pactbase = this ? reinterpret_cast<::TESActorBase*>(reinterpret_cast<char*>(this) - 0x30) : 0;
    TESForm* pform = reinterpret_cast<TESForm*>(pactbase);
    if (pform)
    {
        pform->MarkAsModified(aiChangeFlags);
    }
}

// @fnv 0x0047e340
void TESActorBaseData::AddFormChangeFlags(int aiChangeFlags)
{
    m_pDeathItem |= aiChangeFlags;
}

// Calls the flag-bit helper on this object with flag 0x200, clearing it when param1 is false and passing param2 as the value.
// @fnv 0x005f7b50
void TESActorBaseData::UpdateRunsInLow(bool param1, bool abValue)
{
    UpdateFlagBit(0x200, param1 == 0, abValue);
}

class NiColor;
namespace fnv_0047ca20 {
struct FactionReaction
{
    void Endian();
    TESFaction* pFaction;
    char m_ucRank;
    char _pad_5[3];
};
typedef char _sizecheck_FACTION_RANK[sizeof(FactionReaction) == 8 ? 1 : -1];
void* __cdecl memcpy(void*, const void*, unsigned int);
struct SoundListView
{
    void AddTail(char* const&);
};

void** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
}  // namespace fnv_0047ca20

// Clears the faction list, then copies the source faction ranks into new entries.
// @fnv 0x0047ca20
void TESActorBaseData::CopyFactionList(TESActorBaseData* apCopy)
{
    using namespace fnv_0047ca20;
    RemoveAllFactions();
    SoundListView* pList = (SoundListView*)GetFactionList();
    SoundListView* pCopyList = (SoundListView*)apCopy->GetFactionList();
    while (pCopyList)
    {
        fnv_0047ca20::FactionReaction* prank = *(fnv_0047ca20::FactionReaction**)fnv_0047ca20::_ref_006815c0(pCopyList);
        if (prank)
        {
            fnv_0047ca20::FactionReaction* pFacRank = new fnv_0047ca20::FactionReaction;
            fnv_0047ca20::memcpy(pFacRank, prank, 8);
            pList->AddTail((char* const&)pFacRank);
        }
        SoundListView* tempList = (SoundListView*)fnv_0047ca20::_ref_00726070(pList);
        if (tempList)
            pList = tempList;
        pCopyList = (SoundListView*)fnv_0047ca20::_ref_00726070(pCopyList);
    }
}

namespace fnv_0047e040 {

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting20;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting21;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting22;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting23;

// Maps a karma value to a level code (0-4) by comparing it against four runtime float thresholds.
// @fnv 0x0047e040
// src: XBOX_PDB 0x0047e040
int TESActorBaseData_GetAlignmentForKarma(float afKarma)
{
    int iLevel = 1;
    if (afKarma <= originalRuntimeFloatSetting20.Float()->f)
    {
        if (afKarma <= originalRuntimeFloatSetting22.Float()->f)
            iLevel = 4;
        else
            iLevel = 2;
    }
    else
    {
        if (afKarma >= originalRuntimeFloatSetting21.Float()->f)
        {
            if (afKarma >= originalRuntimeFloatSetting23.Float()->f)
                iLevel = 3;
            else
                iLevel = 0;
        }
    }
    return iLevel;
}
}  // namespace fnv_0047e040

// @fnv 0x0047c850
bool TESActorBaseData::GetCanBeAllRaces() const
{
    return false;
}

// @fnv 0x0047d7e0
// src: XBOX_PDB 0x0047d7e0
bool __fastcall TESFaction_GetSpecialCombat(const TESFaction* faction)
{
    return (faction->data.iFlags & 4) ? true : false;
}

// @fnv 0x0047e360
void __thiscall TESActorBaseData::ClearChangeFlags(int mask)
{
    m_pDeathItem &= ~mask;
}

// @fnv 0x0047c790
bool TESActorBaseData::GetNoVATSranged() const
{
    return ((const TESActorBaseData*)this)->GetFlag(0x200000);
}

// @fnv 0x0047c7b0
bool TESActorBaseData::GetAllowPickpocket() const
{
    return GetFlag(0x10000000);
}

// @fnv 0x0047c9b0
void TESActorBaseData::ClearComponent()
{
    RemoveAllFactions();
}

// @fnv 0x0047d720
bool __fastcall HasFactionFlag8(const TESFaction* faction)
{
    return (faction->data.iFlags & 8) ? true : false;
}

// @fnv 0x0047d7c0
// src: XBOX_PDB 0x0047d7c0
bool TESFaction::GetEvil()
{
    return (data.iFlags & 2) ? true : false;
}

struct SoundH
{
    void* Deallocate();
};
void __cdecl TESForm_AddChunk_00485910(int, int);
void __cdecl AppendChunk(int, void*, int);
bool __cdecl TESForm_QEndianSwapOnSave();
// @fnv 0x0047cac0
void TESActorBaseData::Save()
{
    if (TESForm_QEndianSwapOnSave())
        actorData.SwapEndianness();
    AppendChunk(0x53424341, (char*)this + 4, 0x18);
    if (TESForm_QEndianSwapOnSave())
        actorData.SwapEndianness();
    if (m_pBaseTemplateForm)
    {
        unsigned int itempint = (unsigned int)((SoundH*)m_pBaseTemplateForm)->Deallocate();
        TESForm_AddChunk_00485910(0x4d414e49, itempint);
    }
    if (m_kFactionList)
    {
        unsigned int itempint = (unsigned int)((SoundH*)m_kFactionList)->Deallocate();
        TESForm_AddChunk_00485910(0x4b435456, itempint);
    }
    if (m_ppTemplateForms)
    {
        unsigned int itempint = (unsigned int)((SoundH*)m_ppTemplateForms)->Deallocate();
        TESForm_AddChunk_00485910(0x544c5054, itempint);
    }
}

void TESActorBaseData::CopyFromBase(BaseFormComponent* apCopyFC)
{
    TESActorBaseData* pCopy = dynamic_cast<TESActorBaseData*>(apCopyFC);
    if (!pCopy)
        return;
    SetFlags(*pCopy->GetFlags());
    SetFatigue(static_cast<const TESActorBaseData*>(pCopy)->GetFatigue());
    SetKarmaValue(static_cast<const TESActorBaseData*>(pCopy)->GetHealthRegeneration());
    SetBarterGold(pCopy->GetBarterGold());
    SetLevel(pCopy->GetLevelExact());
    SetCalcLevelMin(pCopy->GetCalcLevelMin_0047d390());
    SetCalcLevelMax(pCopy->GetAnimGroupType_0047d3b0());
    SetSpeedMult(pCopy->GetShortAtOffset12());
    SetBaseDisposition(pCopy->GetBaseDisposition());
    CopyFactionList(pCopy);
    FUN_0050f9a0(pCopy->GetDeathItem());
    SetVoiceType(static_cast<const TESActorBaseData*>(pCopy)->GetVoiceType());
    SetTemplateForm(pCopy->QTemplateForm());
    ((TESActorBaseData*)this)->actorData.m_usField16 = pCopy->actorData.m_usField16;
}

#include "../../include/TESSaveLoadGame.h"
namespace fnv_0047e380 {
struct FormIDEntry
{
    unsigned int iFormID;
    unsigned char padding[5];
};

struct BSSimpleListTESRaceSize
{
    int __thiscall GetSize();
};

// Exe 0x0047e380: unit-local Interface view; declarations and layout are preserved.
struct TesactorbasedataInterfaceView
{
    static void __cdecl PrintDebugMessage(const char*, ...);
};

extern TESSaveLoadGame* DAT_011de45c;
extern SettingT_GameSettingCollection_ g_011de4e8;
TESForm* __cdecl _ref_004839c0(unsigned int);

}  // namespace fnv_0047e380

// Computes the save size of the actor base data from flags and race list, optionally logging the size and form details.
// @fnv 0x0047e380
unsigned short TESActorBaseData::GetSaveSize(unsigned int aiFlags)
{
    using namespace fnv_0047e380;
    unsigned short pform;
    unsigned short pheader;
    FormIDEntry* isize;
    TESForm* itempStartSize;

    pform = 0;
    pheader = pform;

    if (fnv_0047e380::DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        pform += 4;
        pform += 2;
    }

    if (aiFlags & 2)
        pform += 0x18;

    pform += 2;
    pform += reinterpret_cast<BSSimpleListTESRaceSize*>(reinterpret_cast<unsigned char*>(this) + 0x2c)->GetSize() * 5;

    if (*g_011de4e8.FUN_00408d60())
    {
        isize = static_cast<FormIDEntry*>(fnv_0047e380::DAT_011de45c->GetHitSound());
        if (isize)
        {
            itempStartSize = _ref_004839c0(isize->iFormID);
            fnv_0047e380::TesactorbasedataInterfaceView::PrintDebugMessage(
                "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", pform - pheader,
                isize->iFormID, itempStartSize->GetName(),
                *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(isize) + 5), 0xC4E,
                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp");
        }
        else
        {
            fnv_0047e380::TesactorbasedataInterfaceView::PrintDebugMessage(
                "GetSaveSize(): %-5i ending at line %i in file %s", pform - pheader, 0xC4E,
                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp");
        }
    }

    return pform;
}

// @fnv 0x0047c770
bool TESActorBaseData::GetNoVATSmelee() const
{
    return GetFlag(0x100000);
}

struct EndianTag
{
};

void SwapInt(int* p, EndianTag t);
void SwapShort(short* p, EndianTag t);

// Byte-swaps every integer and short field of the header structure to convert its endianness.
// @fnv 0x0047cb90
void ActorBaseAttributes::SwapEndianness()
{
    SwapInt(reinterpret_cast<int*>(&m_uiActorFlags), EndianTag());
    SwapShort(reinterpret_cast<short*>(&m_usField04), EndianTag());
    SwapShort(reinterpret_cast<short*>(&m_usField06), EndianTag());
    SwapShort(reinterpret_cast<short*>(&sLevel), EndianTag());
    SwapShort(reinterpret_cast<short*>(&m_usField0A), EndianTag());
    SwapShort(reinterpret_cast<short*>(&m_usField0C), EndianTag());
    SwapShort(reinterpret_cast<short*>(&m_usField0E), EndianTag());
    SwapInt(reinterpret_cast<int*>(&m_fField10), EndianTag());
    SwapShort(reinterpret_cast<short*>(&m_usField14), EndianTag());
    SwapShort(reinterpret_cast<short*>(&m_usField16), EndianTag());
}

struct FactionLink
{
    TESFaction* pFaction;
};

class FormNode
{
  public:
    bool FUN_008256d0();
    FactionLink** FUN_006815c0();
    FormNode* FUN_00726070();
    };

// Checks the actor base faction list and its linked factions.
// @fnv 0x0047d740
bool TESActorBaseData::CanBeDetected()
{
    bool bValid = true;
    FormNode* p = (FormNode*)GetFactionList();
    if (p->FUN_008256d0())
    {
        bValid = false;
    }
    while (p != 0 && bValid)
    {
        FactionLink* x = *p->FUN_006815c0();
        if (x != 0)
        {
            if (!x->pFaction->GetEvil())
            {
                bValid = false;
            }
        }
        p = p->FUN_00726070();
    }
    return bValid;
}

struct NameRef
{
    unsigned int m_00;
    NameRef(const char* s);
    NameRef(const NameRef& o) : m_00(o.m_00)
    {}
};

struct GlobalMgr
{
    unsigned char Test(int value, NameRef name);
};

extern GlobalMgr* DAT_011ddf38;

extern const char DAT_01183028[];
extern const char DAT_01186cb4[];

int __cdecl FUN_00ec43fb(TESActorBaseData* self, int a, const char* b, const char* c, int d);

// @fnv 0x0047dd50
void TESActorBaseData::UpdateFlagBit(int aMask, bool aSet, bool aForce)
{
    unsigned char cur = (actorData.m_uiActorFlags & aMask) != 0;
    if (cur != aSet)
    {
        if (aMask == 1)
        {
            int r = FUN_00ec43fb(this, 0, DAT_01186cb4, DAT_01183028, 0);
            if (r != 0)
            {
                if (!DAT_011ddf38->Test(r, NameRef("")))
                {
                    AddFormChange(reinterpret_cast<int>(""));
                }
                else
                {
                    RemoveFormChange(reinterpret_cast<int>(""));
                }
            }
        }
        else if (aForce)
        {
            AddFormChange(2);
        }
    }
    (aSet ? (actorData.m_uiActorFlags |= aMask) : (actorData.m_uiActorFlags = (~aMask) & actorData.m_uiActorFlags));
}

// Casts this interface pointer to the derived form and, if non-null, calls Apply on it with pArg.
// @fnv 0x0047e2f0
void TESActorBaseData::RemoveFormChange(int pArg)
{
    TESBoundAnimObject* pkDerived = this ? reinterpret_cast<TESBoundAnimObject*>(reinterpret_cast<char*>(this) - 0x30) : 0;
    TESForm* pkForm3 = pkDerived;
    if (pkForm3)
        pkForm3->MarkAsUnmodified(static_cast<unsigned int>(pArg));
}

// Returns the attack-damage virtual result, or 0 if the component cast fails.
// @fnv 0x0047fef0
int __cdecl GetAttackDamageResult(TESForm* form)
{
    TESAttackDamageForm* found = dynamic_cast<TESAttackDamageForm*>(form);
    if (found != 0)
    {
        // Preserve the original full EAX result; GetAttackDamage declares a 16-bit return.
        typedef int (__thiscall* GetDamage)(TESAttackDamageForm*);
        return reinterpret_cast<GetDamage>((*reinterpret_cast<void***>(found))[4])(found);
    }
    else
    {
        return 0;
    }
}

struct FUN_0047d410_link
{
    void* pFaction;
    signed char rank;
};

struct FUN_0047d410_node
{
    FUN_0047d410_node* FUN_00726070();
    FUN_0047d410_link** FUN_006815c0();
    int FUN_005ae380();
};

// Compares this actor base data against another component field by field, returning true on the first mismatch and false when all compared values match.
// @fnv 0x0047d410
bool TESActorBaseData::CompareWithBase(BaseFormComponent* component)
{
    TESActorBaseData* other = (TESActorBaseData*)dynamic_cast<TESActorBaseData*>(component);
    if (other == 0)
    {
        return true;
    }
    if (*(int*)this->GetFlags() != *(int*)other->GetFlags())
    {
        return true;
    }
    if (static_cast<const TESActorBaseData*>(this)->GetFatigue() != static_cast<const TESActorBaseData*>(other)->GetFatigue())
    {
        return true;
    }
    if (static_cast<const TESActorBaseData*>(this)->GetHealthRegeneration() != static_cast<const TESActorBaseData*>(other)->GetHealthRegeneration())
    {
        return true;
    }
    if (this->GetBarterGold() != other->GetBarterGold())
    {
        return true;
    }
    if (this->GetLevelExact() != other->GetLevelExact())
    {
        return true;
    }
    if (this->GetCalcLevelMin_0047d390() != other->GetCalcLevelMin_0047d390())
    {
        return true;
    }
    if (this->GetAnimGroupType_0047d3b0() != other->GetAnimGroupType_0047d3b0())
    {
        return true;
    }
    if (this->GetDeathItem() != other->GetDeathItem())
    {
        return true;
    }
    if (this->GetShortAtOffset12() != other->GetShortAtOffset12())
    {
        return true;
    }
    if (this->GetBaseDisposition() != other->GetBaseDisposition())
    {
        return true;
    }
    if (((FUN_0047d410_node*)this->GetFactionList())->FUN_005ae380() != ((FUN_0047d410_node*)other->GetFactionList())->FUN_005ae380())
    {
        return true;
    }
    FUN_0047d410_node* node2 = ((FUN_0047d410_node*)this->GetFactionList());
    FUN_0047d410_link* link;
    while (node2 != 0)
    {
        link = *node2->FUN_006815c0();
        if (link != 0)
        {
            if (other->GetFactionRank((TESFaction*)link->pFaction, false) != link->rank)
            {
                return true;
            }
        }
        node2 = node2->FUN_00726070();
    }
    if (static_cast<const TESActorBaseData*>(this)->GetVoiceType() != static_cast<const TESActorBaseData*>(other)->GetVoiceType())
    {
        return true;
    }
    if (this->QTemplateForm() != other->QTemplateForm())
    {
        return true;
    }
    if ((unsigned short)this->actorData.m_usField16 != (unsigned short)other->actorData.m_usField16)
    {
        return true;
    }
    return false;
}

// ExtraShell_tesactorbasedata: local type (was include/ExtraShell.h, which had no evidence of one real class); its methods are 0x00411ec0 ExtraDataList::CopyList, 0x004127e0 ExtraDataList::CompareList, 0x00418520 ExtraDataList::GetContainerChanges, 0x00418750 ExtraDataList::HasLeveledItem
#include "../../include/ExtraDataList.h"

class OpacityFadeState;
class RefNode;
class RefrShell;

class ExtraShell_tesactorbasedata : public ExtraDataList
{
public:
    ExtraShell_tesactorbasedata();

    int FUN_00418520();
    bool FUN_00418750();
    short ExtraDataList_GetCount();
    bool ExtraDataList_CompareList(ExtraShell_tesactorbasedata*);
    void ExtraDataList_SetCount(int);
    void ExtraDataList_CopyList(ExtraShell_tesactorbasedata*);
    signed char GetExtraByteValue();
    void ExtraDataList_RemoveHotkey();
    OpacityFadeState* GetOffsetC();
    void FUN_0041aeb0();
    void ExtraDataList_RemoveScript();
    void* ExtraDataList_GetModelSwap();
    RefNode* ExtraDataList_GetDroppedItemList();
    void ExtraDataList_RemoveDroppedItemList();
    void ExtraDataList_SetItemDropper(int a);
    RefrShell* ExtraDataList_GetAshPileRef();
};
namespace fnv_0047ce10 {
struct LeveledShell
{
    char x;
    void AddLeveledItemsToContainer(class RefShell*, class TESContainer*);
};
struct NPCShell : TESBoundAnimObject, LeveledShell
{
};
struct CreatureShell : TESBoundAnimObject, LeveledShell
{
};
struct ItemShell
{
    int pad;
    void* value;
};
struct ListShell
{
    ItemShell** FUN_006815c0();
};

class RefShell
{
  public:
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15(),
        v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(),
        v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(),
        v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55(), v56(), v57(), v58(), v59(), v60(), v61(), v62();
    virtual bool isActor();
    virtual bool isOther();
    virtual void v65(), v66(), v67(), v68(), v69(), v70(), v71(), v72(), v73(), v74(), v75(), v76(), v77(), v78(),
        v79(), v80(), v81(), v82(), v83(), v84(), v85(), v86(), v87(), v88(), v89(), v90(), v91(), v92(), v93(), v94(),
        v95(), v96(), v97(), v98(), v99(), v100(), v101(), v102(), v103(), v104(), v105(), v106(), v107(), v108(),
        v109(), v110(), v111(), v112(), v113(), v114();
    virtual void reset(int, int);
    virtual void v116(), v117(), v118(), v119(), v120(), v121(), v122(), v123(), v124(), v125(), v126(), v127(), v128(),
        v129(), v130(), v131(), v132(), v133(), v134(), v135(), v136(), v137(), v138(), v139(), v140(), v141(), v142(),
        v143(), v144();
    virtual void update();
    bool TESObjectREFR_HasLeveledCreatureCalced();
    void* FUN_008d8520();
    ExtraShell_tesactorbasedata* BSFile_GetDevice();
    void SetWalkRunFlagDirty();
    void* BGSSaveFormBuffer_GetForm();
    void TESObjectREFR_SetLeveledCreature(void*, void*);
    void TESObjectREFR_SetObjectReference(void*);
    void TESObjectREFR_InitScript();
};
struct GlobalShell
{
    bool BGSSaveLoadGame_GetReconstructingForms();
};
struct StateShell
{
    int Modelloader_GetReferencedThis();
    void PathManager_CancelCurrentPathsAndPause_0(int);
};
struct InvShell
{
    void InventoryChanges_InitLeveledItems();
    void InventoryChanges_InitFromContainerExtra();
    void InventoryChanges_InitScripts();
    bool InventoryChanges_IsEmpty();
};
extern "C" char DAT_011ddf38;
StateShell* GetPathManager();
void* TESActorBaseData_CreateTemplateActorBase(void*, void*);
InvShell* FUN_004bf220(RefShell*);
}  // namespace fnv_0047ce10

// @fnv 0x0047ce10
void TESActorBaseData::SetTemplateReference(::TESObjectREFR* ref)
{
    using namespace fnv_0047ce10;
    if (!ref || !GetUsesLeveledTemplate() || ((RefShell*)ref)->TESObjectREFR_HasLeveledCreatureCalced())
        return;
    LeveledShell* level = 0;
    if (QTemplateForm()->FUN_00401170() == 45)
    {
        NPCShell* npc2 = (NPCShell*)QTemplateForm();
        level = npc2;
    }
    else if (QTemplateForm()->FUN_00401170() == 44)
    {
        CreatureShell* creature3 = (CreatureShell*)QTemplateForm();
        level = creature3;
    }
    if (level)
    {
        TESContainer container;
        level->AddLeveledItemsToContainer((RefShell*)ref, &container);
        void* base6 = (*reinterpret_cast<fnv_0047ce10::ListShell*>(container.FUN_00717e50())->FUN_006815c0())->value;
        if (!*(GlobalShell**)&fnv_0047ce10::DAT_011ddf38 || !(*(GlobalShell**)&fnv_0047ce10::DAT_011ddf38)->BGSSaveLoadGame_GetReconstructingForms())
        {
            if (((RefShell*)ref)->isActor())
            {
                RefShell* actor4 = (RefShell*)ref;
                if (actor4->FUN_008d8520())
                    actor4->update();
            }
            ((RefShell*)ref)->reset(0, 1);
        }
        if (GetPathManager()->Modelloader_GetReferencedThis())
            GetPathManager()->PathManager_CancelCurrentPathsAndPause_0(((RefShell*)ref)->BSFile_GetDevice()->FUN_00418520());
        ((RefShell*)ref)->BSFile_GetDevice()->FUN_0041aeb0();
        ((RefShell*)ref)->BSFile_GetDevice()->ExtraDataList_RemoveScript();
        if (((RefShell*)ref)->isOther())
        {
            RefShell* other3 = (RefShell*)ref;
            other3->SetWalkRunFlagDirty();
        }
        void* oldbase2 = ((RefShell*)ref)->BGSSaveFormBuffer_GetForm();
        void* newbase = fnv_0047ce10::TESActorBaseData_CreateTemplateActorBase(oldbase2, base6);
        ((RefShell*)ref)->TESObjectREFR_SetLeveledCreature(oldbase2, base6);
        ((RefShell*)ref)->TESObjectREFR_SetObjectReference(newbase);
        ((RefShell*)ref)->TESObjectREFR_InitScript();
        InvShell* inventory = FUN_004bf220((RefShell*)ref);
        inventory->InventoryChanges_InitLeveledItems();
        inventory->InventoryChanges_InitFromContainerExtra();
        inventory->InventoryChanges_InitScripts();
        if (inventory->InventoryChanges_IsEmpty())
        {
            ((RefShell*)ref)->BSFile_GetDevice()->FUN_0041aeb0();
            inventory = 0;
        }
    }
}

class FactionReaction
{
  public:
    TESFaction* pFaction;
    unsigned char ucRank;
};

class SaveRefRecord
{
  public:
    unsigned int formId;
};

class SaveGameBuffer
{
  public:
    unsigned char* GetWritePos();
    bool IsSaving();
    void WriteBytes(const void* p, unsigned int n);
    void WriteDword(const void* p, unsigned int n);
    SaveRefRecord* GetSavedRef();
};

extern SaveGameBuffer* DAT_011de45c;
extern SettingT_GameSettingCollection_ DAT_011de4e8;

void __cdecl Warning_005b5e40(const char* fmt, const char* file, int line);
int __cdecl ProgramFlow(const char* fmt, ...);
TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int formId);

// @fnv 0x0047e4a0
void TESActorBaseData::SaveGame(unsigned int flags)
{
    unsigned char* startPosP;
    unsigned char* blockPosY;
    unsigned short kBlockSize;
    kBlockSize = 0;
    blockPosY = 0;
    unsigned int magic;
    unsigned char* countPos_;
    unsigned short aCount;
    BSSimpleList<FactionReaction*>* nodeV;
    FactionReaction* itemL;
    unsigned int formIdQ;
    unsigned char rank;
    unsigned char* endPos;
    unsigned char* baseStart;
    unsigned char* endPosB;
    TESForm* _obj;
    SaveRefRecord* aRefF;

    startPosP = DAT_011de45c->GetWritePos();
    if (*DAT_011de4e8.FUN_00408d60())
    {
        startPosP = DAT_011de45c->GetWritePos();
    }
    if (DAT_011de45c->IsSaving())
    {
        magic = 0x424c4f4b;
        DAT_011de45c->WriteBytes(&magic, 4);
        blockPosY = DAT_011de45c->GetWritePos();
        DAT_011de45c->WriteBytes(&kBlockSize, 2);
    }
    if (flags & 2)
    {
        DAT_011de45c->WriteBytes(&actorData, 0x18);
    }
    aCount = 0;
    countPos_ = DAT_011de45c->GetWritePos();
    DAT_011de45c->WriteBytes(&aCount, 2);
    nodeV = (BSSimpleList<FactionReaction*>*)GetFactionList();
    while (nodeV)
    {
        itemL = nodeV->GetItem();
        if (itemL)
        {
            formIdQ = itemL->pFaction->GetFormID();
            rank = itemL->ucRank;
            DAT_011de45c->WriteDword(&formIdQ, 4);
            DAT_011de45c->WriteBytes(&rank, 1);
            aCount++;
        }
        nodeV = nodeV->GetNext();
    }
    *(unsigned short*)countPos_ = aCount;

    if (*DAT_011de4e8.FUN_00408d60())
    {
        endPos = DAT_011de45c->GetWritePos();
        aRefF = DAT_011de45c->GetSavedRef();
        if (aRefF)
        {
            _obj = TESForm_GetFormByNumericID(aRefF->formId);
            ProgramFlow("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         endPos - startPosP, aRefF->formId, _obj->GetName(),
                         *(unsigned int*)((unsigned char*)aRefF + 5), 0xc77,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp");
        }
        else
        {
            ProgramFlow("SaveGame(): %-5i ending at line %i in file %s", endPos - startPosP, 0xc77,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp");
        }
    }

    if (DAT_011de45c->IsSaving())
    {
        endPosB = DAT_011de45c->GetWritePos();
        baseStart = blockPosY;
        if (endPosB > baseStart + 0xffff)
        {
            Warning_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 0xc77);
        }
        *(unsigned short*)blockPosY = (unsigned short)(endPosB - baseStart);
    }
}

struct FACTION_RANK_Data
{
    TESFaction* m_pFaction;
    signed char m_rank;
    char pad[3];
};

class FactionNode
{
  public:
    FACTION_RANK_Data*& GetItem();
    FactionNode* GetNext();
    void RemoveHead();
    void AddHead(FACTION_RANK_Data*& item);
};

// Sets the rank of a faction in the linked list, removing the entry when rank is -1 and adding a new entry when the faction is not found.
// @fnv 0x0047d800
void TESActorBaseData::SetFactionRank(TESFaction* faction, char rank)
{
    if (faction == 0)
        return;

    FactionNode* pNode = (FactionNode*)GetFactionList();
    while (pNode != 0)
    {
        FACTION_RANK_Data* rankData = pNode->GetItem();
        if (rankData != 0 && rankData->m_pFaction == faction)
        {
            if (rank == -1)
                pNode->RemoveHead();
            else
                rankData->m_rank = rank;
            return;
        }
        pNode = pNode->GetNext();
    }

    FACTION_RANK_Data* rankData = new FACTION_RANK_Data;
    rankData->m_pFaction = faction;
    rankData->m_rank = rank;
    ((FactionNode*)GetFactionList())->AddHead(rankData);
}

namespace fnv_0047e6f0 {
struct LoadingFormHeader
{
    unsigned int flags;
    unsigned char version;
};

struct LoadingFormInfo
{
    unsigned int formID;
    const LoadingFormHeader* Header() const
    {
        return (const LoadingFormHeader*)((const char*)this + 5);
    }
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

class FactionReaction
{
  public:
    TESFaction* pFaction;
    char m_ucRank;
};

void* __cdecl operator new(unsigned int);
TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
void __cdecl FNV_Warning(const char*, ...);

}  // namespace fnv_0047e6f0

// Reads actor base data and faction rank entries from the save stream, then verifies the block size against the expected read size.
// @fnv 0x0047e6f0
void TESActorBaseData::LoadGame(unsigned int changeFlags, unsigned int pBuffer)
{
    using namespace fnv_0047e6f0;
    TESForm* formVal;
    unsigned int curOff;
    LoadingFormInfo* info;
    fnv_0047e6f0::FactionReaction* rank2;
    TESForm* form2;
    char val;
    unsigned int factID;
    unsigned short totalItems;
    int idx;
    TESForm* loadedForm;
    LoadingFormInfo* loadBuffer;
    unsigned int type;
    unsigned short readSize = 0;
    unsigned int offsetA = 0;

    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&type, 4);
        if (type != 0x424C4F4B)
        {
            loadBuffer = static_cast<LoadingFormInfo*>(g_TESSaveLoadGame->BGSProjectile_GetExplosion());
            if (loadBuffer)
            {
                loadedForm = fnv_0047e6f0::TESForm_GetFormByNumericID(loadBuffer->formID);
                fnv_0047e6f0::FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 3200,
                    loadBuffer->formID, loadedForm->GetName(),
                    ((LoadingFormHeader*)((char*)loadBuffer + 5))->version,
                    ((LoadingFormHeader*)((char*)loadBuffer + 5))->flags);
            }
            else
            {
                fnv_0047e6f0::FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 3200,
                    g_TESSaveLoadGame->FUN_008df040());
            }
        }
        offsetA = g_TESSaveLoadGame->FUN_00825c00();
        g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&readSize, 2);
    }

    if (changeFlags & 2)
    {
        g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&this->actorData, sizeof(this->actorData));
    }

    this->RemoveAllFactions();

    g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&totalItems, 2);
    for (idx = 0; idx < totalItems; ++idx)
    {
        g_TESSaveLoadGame->FUN_00857aa0(&factID, 4);
        g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&val, 1);
        form2 = fnv_0047e6f0::TESForm_GetFormByNumericID(factID);
        if (form2)
        {
            rank2 = new fnv_0047e6f0::FactionReaction;
            rank2->pFaction = (TESFaction*)form2;
            rank2->m_ucRank = val;
            ((BSSimpleList<fnv_0047e6f0::FactionReaction*>*)this->GetFactionList())->AddHead(rank2);
        }
    }

    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        curOff = g_TESSaveLoadGame->FUN_00825c00();
        info = static_cast<LoadingFormInfo*>(g_TESSaveLoadGame->BGSProjectile_GetExplosion());
        if (info)
        {
            formVal = fnv_0047e6f0::TESForm_GetFormByNumericID(info->formID);
            if (curOff > (unsigned int)(readSize + offsetA))
            {
                fnv_0047e6f0::FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    curOff - (readSize + offsetA),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 3234, info->formID,
                    formVal->GetName(), ((LoadingFormHeader*)((char*)info + 5))->version,
                    ((LoadingFormHeader*)((char*)info + 5))->flags);
            }
            else if (curOff < (unsigned int)(readSize + offsetA))
            {
                fnv_0047e6f0::FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    (readSize + offsetA) - curOff,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 3234, info->formID,
                    formVal->GetName(), ((LoadingFormHeader*)((char*)info + 5))->version,
                    ((LoadingFormHeader*)((char*)info + 5))->flags);
            }
        }
        else
        {
            if (curOff > (unsigned int)(readSize + offsetA))
            {
                fnv_0047e6f0::FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                    curOff - (readSize + offsetA),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 3234,
                    g_TESSaveLoadGame->FUN_008df040());
            }
            else if (curOff < (unsigned int)(readSize + offsetA))
            {
                fnv_0047e6f0::FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                    (readSize + offsetA) - curOff,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 3234,
                    g_TESSaveLoadGame->FUN_008df040());
            }
        }
    }
}

void __cdecl ResolveFormID(unsigned int* pId, TESFile* pFile);

bool __cdecl FloatEQ(float a, float b, float c);

void __cdecl FNV_Warning(const char* fmt, ...);

extern const char DAT_01184704[];

extern const char DAT_01186318[];

extern const char DAT_01186f7c[];

extern float DAT_01186d08[];

extern int DAT_01186f78;

extern float DAT_011c52a4;

extern float DAT_011c52a0;

extern float DAT_011c529c;

extern SettingT_GameSettingCollection_ DAT_011c5090;

extern SettingT_GameSettingCollection_ DAT_011c4e54;

extern SettingT_GameSettingCollection_ DAT_011c5144;

extern SettingT_GameSettingCollection_ DAT_011c4f64;

// Updates faction and template pointers using the file from param->GetFile(-1), then adjusts actorData.m_fField10 for recognized values.
// @fnv 0x0047d8b0
void TESActorBaseData::InitItem(TESForm* param)

{

    TESFile* file4;

    TESForm* form4;

    FormNode* node2;

    FactionLink* link5;

    TESFaction* faction;

    int i2;

    node2 = ((FormNode*)GetFactionList());

    file4 = param ? param->GetFile(-1) : 0;

    while (node2 != 0)
    {

        link5 = *node2->FUN_006815c0();

        if (link5 != 0)
        {

            if (link5->pFaction != 0)
            {

                faction = link5->pFaction;

                ResolveFormID((unsigned int*)&faction, file4);

                link5->pFaction =
                    (TESFaction*)dynamic_cast< ::TESFaction*>((TESForm*)TESForm_GetFormByNumericID((unsigned int)faction));
            }

            if (link5->pFaction != 0)
            {

                node2 = node2->FUN_00726070();
            }
            else
            {

                _ref_0063f7b0(node2);
            }
        }
        else
        {

            node2 = node2->FUN_00726070();
        }
    }

    form4 = (TESForm*)m_kFactionList;

    if (form4 != 0)
    {

        ResolveFormID((unsigned int*)&form4, file4);

        m_kFactionList = (::BGSVoiceType*)dynamic_cast<BGSVoiceType*>((TESForm*)TESForm_GetFormByNumericID((unsigned int)form4));
    }

    form4 = (TESForm*)m_pBaseTemplateForm;

    if (form4 != 0)
    {

        ResolveFormID((unsigned int*)&form4, file4);

        m_pBaseTemplateForm = (::TESLevItem*)dynamic_cast<TESLevItem*>((TESForm*)TESForm_GetFormByNumericID((unsigned int)form4));

        if (m_pBaseTemplateForm == 0)
        {

            FNV_Warning("MASTERFILE: Unable to find death item (%08X) on ActorBase (%08X) '%s'.", (unsigned int)form4,
                        param->GetFormID(), param->GetName());
        }
    }

    form4 = m_ppTemplateForms;

    if (form4 != 0)
    {

        ResolveFormID((unsigned int*)&form4, file4);

        m_ppTemplateForms = (TESForm*)TESForm_GetFormByNumericID((unsigned int)form4);

        if (m_ppTemplateForms == 0)
        {

            FNV_Warning("MASTERFILE: Unable to find template form (%08X) on ActorBase (%08X) '%s'.",
                        (unsigned int)form4, param->GetFormID(), param->GetName());
        }
    }

    if (!(m_ppTemplateForms != 0 && GetTemplateUseFlag(0)))
    {

        if (DAT_01186f78 == -1)
        {

            for (i2 = 0; i2 < 5; i2++)
            {

                if ((int)TESActorBaseData_GetAlignmentForKarma(DAT_01186d08[i2]) != i2)
                {

                    DAT_01186f78 = 1;

                    DAT_011c52a4 = DAT_011c5090.Float()->f - DAT_011c4e54.Float()->f;

                    DAT_011c52a0 = DAT_011c4e54.Float()->f - DAT_011c5144.Float()->f;

                    DAT_011c529c = DAT_011c4f64.Float()->f - DAT_011c5144.Float()->f;

                    break;
                }
            }

            if (DAT_01186f78 != 1)
            {

                DAT_01186f78 = 0;
            }
        }

        if (DAT_01186f78 == 1)
        {

            if (FloatEQ(actorData.m_fField10, DAT_01186d08[1], 0.001f))
            {

                actorData.m_fField10 = DAT_011c4e54.Float()->f - DAT_011c52a0 * 0.5f;
            }
            else if (FloatEQ(actorData.m_fField10, DAT_01186d08[0], 0.001f))
            {

                actorData.m_fField10 = DAT_011c4e54.Float()->f + DAT_011c52a4 * 0.5f;
            }
            else if (FloatEQ(actorData.m_fField10, DAT_01186d08[2], 0.001f))
            {

                actorData.m_fField10 = DAT_011c5144.Float()->f + DAT_011c529c * 0.5f;
            }
            else if (FloatEQ(actorData.m_fField10, DAT_01186d08[3], 0.001f))
            {

                actorData.m_fField10 = DAT_011c5090.Float()->f + 100.0;
            }
            else if (FloatEQ(actorData.m_fField10, DAT_01186d08[4], 0.001f))
            {

                actorData.m_fField10 = DAT_011c4f64.Float()->f - 100.0;
            }
            else
            {

                FNV_Warning("Invalid karma value found. Unable to fix.");
            }
        }
    }
}

// @fnv 0x0047c7d0
bool TESActorBaseData::GetIsGhost() const
{
    return GetFlag(0x20000000);
}

// @fnv 0x0047c7f0
bool TESActorBaseData::GetIsInvulnerable() const
{
    return GetFlag(0x80000000);
}

// @fnv 0x0047c810
bool TESActorBaseData::GetNoKnockdowns() const
{
    return GetFlag(0x400000);
}

// @fnv 0x0047c830
bool TESActorBaseData::GetNoHeadTracking() const
{
    return GetFlag(0x800000);
}

// @fnv 0x0047c860
float TESActorBaseData::GetHealthRegeneration() const
{
    return actorData.m_fField10;
}

// @fnv 0x004a8ae0
unsigned short TESActorBaseData::GetFatigue() const
{
    return actorData.m_usField04;
}

