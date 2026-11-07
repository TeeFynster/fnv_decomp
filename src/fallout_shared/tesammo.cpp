#include "../../include/TESAmmo.h"
#include "../../include/BSStringT.h"
// fallout_shared/tesammo.cpp: TESAmmo, AmmoMethods, AmmoSave (18 functions)

#include "tesammo_load.h"
#include <malloc.h>
#include <string.h>

// @fnv 0x005026b0
TESAmmo::TESAmmo()
{
    SetFormType(ENUM_FORM_ID_AMMO_ID);
    ResetFormData();
}

// @fnv 0x005029f0
void TESAmmo::ResetFormData()
{
    memset(&data, 0, sizeof(data));
    memset(&m_kProjectileData, 0, sizeof(m_kProjectileData));
    m_kPrimaryString.Set(0, 0);
    m_kSecondaryString.Set(0, 0);
}

// Initializes the ammo's scriptable, destructible, model, pickup sound and projectile/effect forms, resolving each form ID and warning on failure.
// @fnv 0x00502a50
void TESAmmo::InitItem()
{
    struct InitItemLocals
    {
        unsigned int formID;
        void* resolved;
        BSSimpleList<TESAmmoEffect*>* node;
    } locals;

    if (IsFormInitialized())
        return;

    ((TESScriptableForm*)((char*)this + 0x9C))->InitItem((TESForm*)this);
    ((BGSDestructibleObjectForm*)((char*)this + 0x88))->InitItem((TESForm*)this);
    ((TESModelTextureSwap*)((char*)this + 0x3C))->InitItem((TESForm*)this);
    ((BGSPickupPutdownSounds*)((char*)this + 0x90))->InitItem((TESForm*)this);

    locals.formID = ((TESAmmoProjectileField*)this)->GetProcessInteger();
    if (locals.formID)
    {
        TESForm::RemapFormIDForFile(locals.formID, GetFile(-1));
        ((TESAmmoProjectileField*)this)
            ->SetProcessInteger((int)dynamic_cast<BGSProjectile*>(TESForm::GetFormByID(locals.formID)));
        if (!((TESAmmoProjectileField*)this)->GetProcessInteger())
        {
            Warning(DAT_01026288, locals.formID, GetName(), GetFormID());
        }
    }

    locals.formID = ((TESAmmoInitCalls*)this)->GetFieldBC();
    if (locals.formID)
    {
        TESForm::RemapFormIDForFile(locals.formID, GetFile(-1));
        ((TESAmmoInitCalls*)this)->SetAmmoConsumed(TESForm::GetFormByID(locals.formID));
        if (!((TESAmmoInitCalls*)this)->GetFieldBC())
        {
            Warning(DAT_01026238, locals.formID, GetName(), GetFormID());
        }
    }

    locals.node = (BSSimpleList<TESAmmoEffect*>*)((TESAmmoInitCalls*)this)->TESAmmo_GetAmmoEffectList();
    locals.resolved = 0;
    while (locals.node && locals.node->GetItem())
    {
        locals.formID = (unsigned int)locals.node->GetItem();
        if (locals.formID)
        {
            TESForm::RemapFormIDForFile(locals.formID, GetFile(-1));
            locals.resolved = dynamic_cast<TESAmmoEffect*>(TESForm::GetFormByID(locals.formID));
            if (!locals.resolved)
            {
                Warning(DAT_010261e8, locals.formID, GetName(), GetFormID());
            }
            locals.node->GetItem() = (TESAmmoEffect*)locals.resolved;
        }
        locals.node = locals.node->GetNext();
    }

    SetInitializationState(true);
}

// @fnv 0x00502cd0
bool TESAmmo::LoadForm(TESFile* file)
{
    unsigned char type = file->GetTESForm();
    if (type != 41)
        return false;
    ((BSSimpleList<ActorCause*>*)((TESAmmoInitCalls*)this)->TESAmmo_GetAmmoEffectList())->RemoveAll();
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* pEditorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(pEditorID, 512);
            SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            struct SwapLocals
            {
                unsigned int size;
                void* swap;
            } TextureChunk;
            TextureChunk.size = file->GetChunkSize();
            TextureChunk.swap = _alloca(TextureChunk.size);
            file->GetChunkData(TextureChunk.swap, TextureChunk.size);
            ParseTextureSwapData(TextureChunk.swap, TextureChunk.size, ((TESFileFormVersion*)file)->GetFormVersion());
            break;
        }
        case 0x4e4f4349:
            TESTextureLoader::ReadTextureData(this, file);
            break;
        case 0x4f43494d:
            BGSMessageIcon::LoadMessageIconChunk(this, file);
            break;
        case 0x49524353: {
            unsigned int script = 0;
            file->GetChunkData(&script);
            ((CombatProcedure*)((char*)this + 0x9c))->Initialize((CombatController*)script);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x54534544:
        case 0x44545344:
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 0x4d414e59: {
            unsigned int pickup = 0;
            file->GetChunkData(&pickup);
            ((CombatProcedure*)((char*)this + 0x90))->Initialize((CombatController*)pickup);
            break;
        }
        case 0x4d414e5a: {
            unsigned int putdown = 0;
            file->GetChunkData(&putdown);
            ((TESRegionGrassObject*)((char*)this + 0x90))->AssignLandTexture((TESLandTexture*)putdown);
            break;
        }
        case 0x41544144:
            ((BGSImpactData*)this)->ReadTypedData(file, &data, 8);
            break;
        case 0x32544144:
            file->GetChunkData(&m_kProjectileData, 20);
            if (file->IsEndianConversionRequired())
                ((TESAmmoNVEndian*)&m_kProjectileData)->SwapEndianFields();
            break;
        case 0x4d414e4f: {
            char* pDescription = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(pDescription, 0);
            m_kPrimaryString.Set(pDescription, 0);
            break;
        }
        case 0x4d414e51: {
            char* pAbbreviation = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(pAbbreviation, 0);
            m_kSecondaryString.Set(pAbbreviation, 0);
            break;
        }
        case 0x4c494352: {
            unsigned int effect = 0;
            file->GetChunkData(&effect);
            ((BSSimpleList<ScriptVariableInfo*>*)((TESAmmoInitCalls*)this)->TESAmmo_GetAmmoEffectList())
                ->AddTail((ScriptVariableInfo*)effect);
            break;
        }
        }
        if (chunk == 0x41544144 && file->IsEndianConversionRequired())
            ((EncounterZoneData*)&data)->Endian();
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_00502cb0_shell : public TESAmmo
{
    void SetAmmoConsumed(TESForm*);
};

// @fnv 0x00502cb0
// src: GUESS 0x00502cb0 (confidence: medium)
void FUN_00502cb0_shell::SetAmmoConsumed(TESForm* apAmmoConsumed)
{
    *(TESForm**)((char*)this + 0xbc) = apAmmoConsumed;
}

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<4>);

struct FUN_00503240_shell
{
    void SwapEndianFields();
};

// Byte-swaps the 4-byte values at offsets 8 and 0x10 of this object via BSEndian.
// @fnv 0x00503240
void FUN_00503240_shell::SwapEndianFields()
{
    BSEndian(reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 8), EndianSizeTag<4>());
    BSEndian(reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10), EndianSizeTag<4>());
}

struct FUN_00504420_shell
{
    void __thiscall TESForm_LoadGame(unsigned int, unsigned int);
    void __thiscall LoadGame_0048ea10(unsigned int, unsigned int);
    void __thiscall TESAmmo_LoadGame(unsigned int aiFlags, unsigned int aiCurrentFlags);
};

// Calls FUN_00484c50 on this and FUN_0048ea10 on the object at this+0x78, passing the same two flags.
// @fnv 0x00504420
// src: XBOX_PDB 0x00504420
void __thiscall FUN_00504420_shell::TESAmmo_LoadGame(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    TESForm_LoadGame(aiFlags, aiCurrentFlags);
    ((FUN_00504420_shell*)((char*)this + 0x78))->LoadGame_0048ea10(aiFlags, aiCurrentFlags);
}

struct FUN_00504450_shell
{
    void TESAmmo_SaveGame(unsigned int);
};

struct FUN_00484d60_holder
{
    void SaveIfChanged(unsigned int);
};

struct FUN_0048ea40_holder
{
    void SaveGameBGS_0048ea40(unsigned int);
};

// Forwards aiFlags to the method at offset 0 and to the method at offset 0x78 of this object.
// @fnv 0x00504450
// src: XBOX_PDB 0x00504450
void FUN_00504450_shell::TESAmmo_SaveGame(unsigned int aiFlags)
{
    reinterpret_cast<FUN_00484d60_holder*>(this)->SaveIfChanged(aiFlags);
    reinterpret_cast<FUN_0048ea40_holder*>(reinterpret_cast<char*>(this) + 0x78)->SaveGameBGS_0048ea40(aiFlags);
}

struct BGSLoadFormBuffer;
// TESValueFormLoadGame_tesammo: local type (was include/TESValueFormLoadGame.h, which had no evidence of one real class); its methods are 0x0048ea80 TESValueForm::LoadGame
#include "../../include/BGSLoadFormBuffer.h"

class TESValueFormLoadGame_tesammo
{
public:
    void LoadGame(BGSLoadFormBuffer* buffer);
};
struct FUN_00503a40_shell : TESForm
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

// @fnv 0x00503a40
void FUN_00503a40_shell::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    ((TESValueFormLoadGame_tesammo*)(this) + 0x78)->LoadGame(buffer);
}

namespace fnv_00503210 {
template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(int*, EndianSizeTag<2>);
struct Unk
{
    void QuestPerkEntryData_Endian();
};
// Calls BSEndian on this object to byte-swap it as a 2-byte value.
// @fnv 0x00503210
// src: XBOX_PDB 0x00503210
void Unk::QuestPerkEntryData_Endian()
{
    BSEndian((int*)this, EndianSizeTag<2>());
}
}  // namespace fnv_00503210

struct FUN_00484bf0
{
    unsigned short GetSaveSize(unsigned int);
};
struct FUN_0048e9b0
{
    unsigned short GetSaveSize(unsigned int);
};
struct FUN_005039f0_class
{
    char _pad[0x78];
    FUN_0048e9b0 _o78;
    unsigned short TESAmmo_GetSaveSize(unsigned int);
};
// @fnv 0x005039f0
// src: XBOX_PDB 0x005039f0
unsigned short FUN_005039f0_class::TESAmmo_GetSaveSize(unsigned int aiFlags)
{
    unsigned short isize;
    isize = 0;
    isize += ((FUN_00484bf0*)this)->GetSaveSize(aiFlags);
    isize += _o78.GetSaveSize(aiFlags);
    return isize;
}

struct FUN_0051b070_shell
{
    void TESForm_SaveGame(unsigned int);
    void SaveGame_0048e9e0(unsigned int);
};
struct FUN_0059b850_shell
{
    FUN_0051b070_shell m0;
    char _pad[0x77];
    FUN_0051b070_shell m78;
    void TESAmmo_SaveGame_0059b850(unsigned int);
};
// Forwards aiFlags to FUN_00484c20 on m0 and to FUN_0048e9e0 on m78.
// @fnv 0x0059b850
// src: XBOX_PDB 0x0059b850
void FUN_0059b850_shell::TESAmmo_SaveGame_0059b850(unsigned int aiFlags)
{
    m0.TESForm_SaveGame(aiFlags);
    m78.SaveGame_0048e9e0(aiFlags);
}

// Stand-ins for TESAmmo's base components and members (destructor of TESAmmo).
struct AmmoBoundObjectPart
{
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
    virtual void Unk00();
    ~AmmoBoundObjectPart();
};
struct AmmoFullNamePart
{
    int unk04;
    int unk08;
    virtual void Unk00();
    ~AmmoFullNamePart();
};
struct AmmoModelTextureSwapPart
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    virtual void Unk00();
    ~AmmoModelTextureSwapPart();
};
struct AmmoIconPart
{
    int unk04;
    int unk08;
    virtual void Unk00();
    ~AmmoIconPart();
};
struct AmmoMessageIconPart
{
    int unk04;
    int unk08;
    int unk0C;
    virtual void Unk00();
    ~AmmoMessageIconPart();
};
struct AmmoValueFormPart
{
    int iValue;
    virtual void Unk00();
    ~AmmoValueFormPart();
};
struct AmmoClipRoundsPart
{
    unsigned char m_ucClipRounds;
    virtual void Unk00();
    ~AmmoClipRoundsPart();
};
struct AmmoDestructiblePart
{
    void* pData;
    virtual void Unk00();
    ~AmmoDestructiblePart();
};
struct AmmoPickupPutdownPart
{
    void* m_pPickupSound;
    void* m_pPutdownSound;
    virtual void Unk00();
    ~AmmoPickupPutdownPart();
};
struct AmmoScriptablePart
{
    void* m_pFormScript;
    bool m_bHasScript;
    virtual void Unk00();
};

struct AmmoEffectList
{
    void* m_item;
    AmmoEffectList* m_pkNext;
    ~AmmoEffectList();
};

struct AmmoData
{
    float fSpeed;
    unsigned char cFlags;
};
struct AmmoDataNV
{
    unsigned char m_ucFlags;
    void* m_pProjectile;
    float m_fProjectileSpeed;
    void* m_pShellCasing;
    float m_fDamageMultiplier;
};



// Destructor for the ammo object; the body is empty and member destructors run implicitly.
// @fnv 0x00502880
TESAmmo::~TESAmmo()
{}

namespace fnv_00503670 {
struct AmmoEffectList : BSSimpleList<TESAmmoEffect*>
{
    unsigned int FUN_005ae380();
};
struct AmmoMethods : TESAmmo
{
    bool TESForm_CompareAllComponents(TESAmmo*);
    AmmoCharacteristics* GetBackTexture();
    AmmoProjectileData* hkpAabbPhantom_getAabb();
    AmmoEffectList* TESAmmo_GetAmmoEffectList();
    bool TESAmmo_Compare(TESForm* form);
};

// @fnv 0x00503670
// src: XBOX_PDB 0x00503670
bool AmmoMethods::TESAmmo_Compare(TESForm* form)
{
    TESAmmo* i;
    BSSimpleList<TESAmmoEffect*>* a;
    BSSimpleList<TESAmmoEffect*>* p;
    TESAmmoEffect* f;
    TESAmmoEffect* s;
    i = dynamic_cast<TESAmmo*>(form);
    if (!i)
        return true;
    if (TESForm_CompareAllComponents(i))
        return true;
    if (memcmp(&data, static_cast<AmmoMethods*>(i)->GetBackTexture(), 8))
        return true;
    if (memcmp(&m_kProjectileData, static_cast<AmmoMethods*>(i)->hkpAabbPhantom_getAabb(), 20))
        return true;
    if (reinterpret_cast<::BSStringT<char>*>(&m_kSecondaryString)->FUN_00501c90(&i->m_kSecondaryString, true))
        return true;
    if (reinterpret_cast<::BSStringT<char>*>(&m_kPrimaryString)->FUN_00501c90(&i->m_kPrimaryString, true))
        return true;
    if (TESAmmo_GetAmmoEffectList()->FUN_005ae380() != static_cast<AmmoMethods*>(i)->TESAmmo_GetAmmoEffectList()->FUN_005ae380())
        return true;
    a = TESAmmo_GetAmmoEffectList();
    p = static_cast<AmmoMethods*>(i)->TESAmmo_GetAmmoEffectList();
    while (p && !p->IsEmpty())
    {
        if (!a || a->IsEmpty())
            return true;
        f = a->GetItem();
        s = p->GetItem();
        if (f->Compare(s))
            return true;
        p = p->GetNext();
        a = a->GetNext();
    }
    return false;
}
}  // namespace fnv_00503670

bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl TESForm_AddChunkArray(unsigned int, const void*, unsigned int);
void __cdecl AppendChunk(unsigned int, void*, unsigned int);
void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);
struct AmmoSaveCalls
{
    void BeginFormRecord();
    void FinishFormRecord();
    void Save_00487010();
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
    void TESTexture_Save(unsigned int);
    void FUN_0047a240(unsigned int);
    void Save_0048cca0();
    void FUN_00477f20();
    void LogFormIDs();
    void QuestPerkEntryData_Endian();
    void TESForm___SaveData(void*, unsigned int);
    unsigned int BSStringT_char_Length();
};
struct AmmoSave
{
    TESBoundObject bound;
    TESFullName fullName;
    TESModelTextureSwap model;
    TESIcon icon;
    BGSMessageIcon messageIcon;
    TESValueForm value;
    BGSClipRoundsForm clipRounds;
    BGSDestructibleObjectForm destructible;
    BGSPickupPutdownSounds sounds;
    TESScriptableForm script;
    AmmoCharacteristics data;
    AmmoProjectileData m_kProjectileData;
    BSStringT<char> m_kPrimaryString;
    BSStringT<char> m_kSecondaryString;
    BSSimpleList<TESAmmoEffect*> m_kEffects;
    void Save();
};
// @fnv 0x00503280
void AmmoSave::Save()
{
    reinterpret_cast<AmmoSaveCalls*>(this)->BeginFormRecord();
    reinterpret_cast<AmmoSaveCalls&>(fullName).Save_00487010();
    reinterpret_cast<AmmoSaveCalls&>(model).ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<AmmoSaveCalls&>(icon).TESTexture_Save(0x4e4f4349);
    reinterpret_cast<AmmoSaveCalls&>(messageIcon).FUN_0047a240(0x4f43494d);
    reinterpret_cast<AmmoSaveCalls&>(script).Save_0048cca0();
    reinterpret_cast<AmmoSaveCalls&>(destructible).FUN_00477f20();
    reinterpret_cast<AmmoSaveCalls&>(sounds).LogFormIDs();
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<AmmoSaveCalls&>(data).QuestPerkEntryData_Endian();
    reinterpret_cast<AmmoSaveCalls*>(this)->TESForm___SaveData(&data, 8);
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<AmmoSaveCalls&>(data).QuestPerkEntryData_Endian();
    BGSProjectile* node = m_kProjectileData.m_pProjectile;
    TESForm* projectile = m_kProjectileData.m_pShellCasing;
    m_kProjectileData.m_pProjectile =
        m_kProjectileData.m_pProjectile ? reinterpret_cast<BGSProjectile*>(m_kProjectileData.m_pProjectile->GetFormID())
                                        : 0;
    m_kProjectileData.m_pShellCasing = m_kProjectileData.m_pShellCasing
                                           ? reinterpret_cast<TESForm*>(m_kProjectileData.m_pShellCasing->GetFormID())
                                           : 0;
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<TESAmmoNVEndian&>(m_kProjectileData).SwapEndianFields();
    AppendChunk(0x32544144, &m_kProjectileData, 20);
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<TESAmmoNVEndian&>(m_kProjectileData).SwapEndianFields();
    m_kProjectileData.m_pProjectile = node;
    m_kProjectileData.m_pShellCasing = projectile;
    if (reinterpret_cast<AmmoSaveCalls&>(m_kPrimaryString).BSStringT_char_Length())
        TESForm_AddChunkArray(0x4d414e4f, m_kPrimaryString.String(),
                     reinterpret_cast<AmmoSaveCalls&>(m_kPrimaryString).BSStringT_char_Length() + 1);
    if (reinterpret_cast<AmmoSaveCalls&>(m_kSecondaryString).BSStringT_char_Length())
        TESForm_AddChunkArray(0x4d414e51, m_kSecondaryString.String(),
                     reinterpret_cast<AmmoSaveCalls&>(m_kSecondaryString).BSStringT_char_Length() + 1);
    BSSimpleList<TESAmmoEffect*>* effect =
        reinterpret_cast<BSSimpleList<TESAmmoEffect*>*>(reinterpret_cast<TESAmmoInitCalls*>(this)->TESAmmo_GetAmmoEffectList());
    TESAmmoEffect* consumed = 0;
    while (effect && effect->GetItem())
    {
        consumed = effect->GetItem();
        effect = effect->GetNext();
        unsigned int formID = consumed->GetFormID();
        TESForm_AddChunk_00485910(0x4c494352, formID);
    }
    reinterpret_cast<AmmoSaveCalls*>(this)->FinishFormRecord();
}

int __fastcall FNV_GetFormType(TESForm* pkForm);
void* __memcpy(void* pvDest, const void* pvSrc, unsigned int uiSize);
void* __fastcall hkpAabbPhantom_getAabb(char* pcObject);

struct AmmoEffectNode503
{
    TESAmmoEffect* m_item;
    AmmoEffectNode503* m_pkNext;

    TESAmmoEffect*& FUN_006815c0();
    void FUN_0063f7b0();
    void FUN_00905820(TESAmmoEffect*& pkItem);
};

bool __fastcall FUN_008256d0(AmmoEffectNode503* pkNode);
AmmoEffectNode503* __fastcall FUN_00726070(AmmoEffectNode503* pkNode);

struct AmmoString503
{
    const char* Modelloader_GetReferencedThis() const;
};

struct FUN_00503510_shell : public TESAmmo
{
    void TESForm_CopyAllComponents(TESForm* pkForm);
    void* GetBackTexture();
    void FUN_004f15a0(int iType);
    AmmoEffectNode503* TESAmmo_GetAmmoEffectList();
    void CopyFromAmmo(TESForm* pkForm);
};

// @fnv 0x00503510
void FUN_00503510_shell::CopyFromAmmo(TESForm* pkForm)
{
    FUN_00503510_shell* pSourceAmmo = (FUN_00503510_shell*)dynamic_cast<TESAmmo*>(pkForm);
    if (!pSourceAmmo)
        return;
    TESForm_CopyAllComponents(pkForm);
    __memcpy(&data, pSourceAmmo->GetBackTexture(), 8);
    __memcpy(&m_kProjectileData, hkpAabbPhantom_getAabb((char*)pSourceAmmo), 0x14);
    FUN_004f15a0(::FNV_GetFormType(pSourceAmmo));
    m_kPrimaryString.Set(((AmmoString503*)&pSourceAmmo->m_kPrimaryString)->Modelloader_GetReferencedThis(), 0);
    m_kSecondaryString.Set(((AmmoString503*)&pSourceAmmo->m_kSecondaryString)->Modelloader_GetReferencedThis(), 0);
    while (!FUN_008256d0(TESAmmo_GetAmmoEffectList()))
        TESAmmo_GetAmmoEffectList()->FUN_0063f7b0();
    AmmoEffectNode503* pkNodeCur = pSourceAmmo->TESAmmo_GetAmmoEffectList();
    while (pkNodeCur && !FUN_008256d0(pkNodeCur))
    {
        TESAmmoEffect* pkEffect = pkNodeCur->FUN_006815c0();
        TESAmmo_GetAmmoEffectList()->FUN_00905820(pkEffect);
        pkNodeCur = ::FUN_00726070(pkNodeCur);
    }
}

namespace fnv_00503a70 {
template <class T> unsigned int BSStringLength(const T* pString);
int __cdecl FUN_00406d50(char* pcDest, unsigned int uiSize, const char* pcSrc);

struct AmmoEffect503
{
    void FormatDescription(char* pcBuffer, unsigned int uiSize);
};

struct AmmoEffectNode503
{
    AmmoEffect503** FUN_006815c0();
    AmmoEffectNode503* FUN_00726070();
};

struct AmmoEffectList503 : public TESAmmoInitCalls
{
    void TESAmmo_BuildMenuString(char* pcBuffer, unsigned int uiSize);
};

// @fnv 0x00503a70
// src: XBOX_PDB 0x00503a70
void AmmoEffectList503::TESAmmo_BuildMenuString(char* pcOutBuffer, unsigned int uiBufferSize)
{
    bool bAppended = false;
    pcOutBuffer[0] = 0;
    char acName[256];
    acName[0] = 0;

    AmmoEffectNode503* pkNode = (AmmoEffectNode503*)TESAmmo_GetAmmoEffectList();
    while (pkNode && *pkNode->FUN_006815c0())
    {
        (*pkNode->FUN_006815c0())->FormatDescription(acName, 0x100);
        AmmoEffect503* pkEffect = *pkNode->FUN_006815c0();
        pkNode = pkNode->FUN_00726070();
        pkEffect->FormatDescription(acName, 0x100);
        if (BSStringLength(acName) > 0)
        {
            if (bAppended)
            {
                FUN_00406d50(pcOutBuffer, uiBufferSize, "\n");
                FUN_00406d50(pcOutBuffer, uiBufferSize, acName);
            }
            else
            {
                FUN_00406d50(pcOutBuffer, uiBufferSize, acName);
                bAppended = true;
            }
        }
    }
}
}  // namespace fnv_00503a70

struct FUN_00502850
{
    virtual ~FUN_00502850();
};
// @fnv 0x00502850
FUN_00502850::~FUN_00502850()
{}
