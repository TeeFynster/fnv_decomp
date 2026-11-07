#include "../../include/InterfaceManager.h"
// fallout_shared/bgsprojectile.cpp: BGSProjectile, BGSProjectileFloatNode (22 functions)

#include "../../include/BGSProjectile.h"
#include "../../include/BSFadeNode.h"
#include "../../include/TESCreature.h"
#include <malloc.h>
#include <stddef.h>
#include "../../include/BGSExplosion.h"
#include "../../include/BGSPreloadable.h"
#include "../../include/BGSImpactData.h"
#include "../../include/EffectSetting.h"
#include "../../include/ProjectileProperties.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESObjectACTI.h"
#include "../../include/TESObjectLIGH.h"
#include "../../include/TESSound.h"
#include "../../include/TESChallenge.h"
#include "../../include/TESObjectWEAP.h"

#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]

class TESRace;
template <class T> class BSSimpleList;
void* operator new(unsigned int size);

class BGSProjectileFloatNode
{
  public:
    float value;
    BGSProjectileFloatNode* next;
    BGSProjectileFloatNode(const BGSProjectileFloatNode& other);
    void AddHead(const float& value);
};



struct S_004fdfb0_Obj;
struct ProjResult;
struct ProjRef;

// These methods are not yet declared in the shared header. This extension adds
// declarations only; all projectile storage and base classes come from it.
class BGSProjectileMethods : public BGSProjectile
{
public:
    void* DestroyIfFlagged(unsigned int flags);
    void CopyFromProjectile(TESForm* copy);
    bool IsNotEqual(TESForm* compare);
    virtual void QueueResourceLoad(IO_TASK_PRIORITY a, QueuedFile* b);
    int GetProjectileCloneCount(TESObjectWEAP* sourceWeapon);
    int GetKind();
    int GetKindCode();
    S_004fdfb0_Obj* GetPreloadObject();
    ProjResult* CreateOrClone(ProjRef* ref, bool value);
    ProjResult* Create(ProjRef* ref, bool value);
    void Release(ProjRef* ref);
    void WriteProjectileSave();
};

FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(sizeof(BGSPreloadable) == 4);
FNV_STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 8);
FNV_STATIC_ASSERT(sizeof(ProjectileProperties) == 84);
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 0x30);
FNV_STATIC_ASSERT(sizeof(BGSProjectile::Properties) == 84);
FNV_STATIC_ASSERT(sizeof(TESBoundObject) + sizeof(TESFullName) + sizeof(TESModel) + sizeof(BGSPreloadable) +
                      sizeof(BGSDestructibleObjectForm) ==
                  0x60);
FNV_STATIC_ASSERT(offsetof(BGSProjectile, Data) == 0x60);
FNV_STATIC_ASSERT(offsetof(BGSProjectile, m_kProjectileModel) == 0xB4);
FNV_STATIC_ASSERT(offsetof(BGSProjectile, m_eSoundLevel) == 0xCC);
FNV_STATIC_ASSERT(sizeof(BGSProjectile) == 0xD0);

class Tile;


// @fnv 0x004fd090
void BGSProjectile::ClearData()
{
    m_kProjectileModel.Free();
}

// @fnv 0x004fd050
void BGSProjectile::ResetFormData()
{
    reinterpret_cast<ProjectileProperties*>(reinterpret_cast<TESDataHandler*>(this)->GetTESRaceList())
        ->InitializeDefaults();
    m_kProjectileModel.Init();
    m_eSoundLevel = static_cast<SOUND_LEVEL>(1);
}

// If newValue is nonzero, sets value, or copies this node into a new node inserted after it and sets value.
// @fnv 0x004ff980
void BGSProjectileFloatNode::AddHead(const float& newValue)
{
    if (newValue == 0.0)
        return;
    {
        if (value != 0.0)
        {
            BGSProjectileFloatNode* inserted = new BGSProjectileFloatNode(*this);
            inserted->next = next;
            next = inserted;
            value = newValue;
        }
        else
        {
            value = newValue;
        }
    }
}
// @fnv 0x004fce60
BGSProjectile::BGSProjectile()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x33));
    ResetFormData();
}
// @fnv 0x004fd0c0
void BGSProjectile::InitItem()
{
    if (GetInitialized())
        return;
    BGSDestructibleObjectForm::InitItem(this);
    unsigned int formID;
    formID = (unsigned int)reinterpret_cast<EffectSetting*>(this)->GetLight();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetLight(
            dynamic_cast<TESObjectLIGH*>(TESForm::GetFormByID(formID)));
    }
    formID = (unsigned int)reinterpret_cast<TESChallenge*>(this)->GetFormOne();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<TESObjectACTI*>(this)->SetLoopingSound(
            reinterpret_cast<TESSound*>(dynamic_cast<TESObjectLIGH*>(TESForm::GetFormByID(formID))));
    }
    formID = (unsigned int)reinterpret_cast<EffectSetting*>(this)->GetBoltSound();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetBoltSound(
            reinterpret_cast<TESSound*>(dynamic_cast<BGSExplosion*>(TESForm::GetFormByID(formID))));
    }
    formID = (unsigned int)reinterpret_cast<EffectSetting*>(this)->GetHitSound();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetHitSound(
            dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
    }
    formID = (unsigned int)reinterpret_cast<EffectSetting*>(this)->GetArchetype();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetEffectID(
            (int)dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
    }
    formID = (unsigned int)reinterpret_cast<InterfaceManager*>(this)->CombatController_GetCombatState();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetAssociatedActorValue(
            (int)dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
    }
    formID = (unsigned int)reinterpret_cast<InterfaceManager*>(this)->GetAVEffect();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<InterfaceManager*>(this)->BGSTerminal_SetPassword(
            reinterpret_cast<Tile*>(dynamic_cast<TESObjectWEAP*>(TESForm::GetFormByID(formID))));
    }
    if (!GetHasExplosion())
        reinterpret_cast<EffectSetting*>(this)->SetBoltSound(0);
    SetInitializationState(true);
}
// @fnv 0x004fd6f0
bool BGSProjectile::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x33)
        return false;

    ClearData();
    reinterpret_cast<TESForm*>(this)->LoadRecordHeader(file);
    reinterpret_cast<TESForm*>(this)->SetInitializationState(false);

    int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {

        switch (chunkID)
        {
        case 0x44494445: {
            char* buffer = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(buffer, 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444E424F:
            readOBNDSubRecord(file);
            break;
        case 0x4C4C5546:
            TESFullName::LoadFullNameChunk(static_cast<TESFullName*>(this), file);
            break;
        case 0x4C444F4D:
        case 0x54444F4D: {
            TESModel::LoadModelData(static_cast<TESModel*>(this), file);
            break;
        }
        case 0x44545344:
        case 0x54534544: {
            BGSDestructibleObjectForm::LoadDestructibleData(static_cast<BGSDestructibleObjectForm*>(this), file);
            break;
        }
        case 0x41544144:
            reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, &Data, 0x54);
            break;
        case 0x314D414E: {
            if (file->GetChunkSize())
            {
                char* buffer = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(buffer, 0);
                m_kProjectileModel.SetModelFilePath(static_cast<const char*>(buffer));
            }
            break;
        }
        case 0x324D414E:
            if (file->GetChunkSize())
                TESModel::LoadTextureSwapData(&m_kProjectileModel, file);
            break;
        case 0x4D414E56: {
            unsigned int soundLevel;
            file->GetChunkData(&soundLevel);
            if (soundLevel > 3)
                m_eSoundLevel = static_cast<SOUND_LEVEL>(1);
            else
                m_eSoundLevel = static_cast<SOUND_LEVEL>(soundLevel);
            break;
        }
        }

        if (chunkID == 0x41544144 && file->IsEndianConversionRequired())
            Data.Endian();
        if (!file->NextChunk())
            break;
    }

    return true;
}

// @fnv 0x004fcc00
BGSProjectile::Properties::Properties()
{
    InitializeDefaults();
}

struct FUN_004fcc20_shell : public ProjectileProperties
{
    void InitializeDefaults();
};

extern float DAT_01022958;

// @fnv 0x004fcc20
void FUN_004fcc20_shell::InitializeDefaults()
{
    *(int*)((char*)this + 0x00) = 0x10000;
    *(float*)((char*)this + 0x04) = 0.0f;
    *(float*)((char*)this + 0x08) = 1000.0f;
    *(float*)((char*)this + 0x0c) = DAT_01022958;
    *(float*)((char*)this + 0x18) = 0.0f;
    *(float*)((char*)this + 0x1c) = 0.0f;
    *(float*)((char*)this + 0x20) = 0.0f;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0x14) = 0;
    *(int*)((char*)this + 0x24) = 0;
    *(int*)((char*)this + 0x28) = 0;
    *(float*)((char*)this + 0x2c) = 0.0f;
    *(float*)((char*)this + 0x30) = 0.5f;
    *(float*)((char*)this + 0x34) = 0.0f;
    *(int*)((char*)this + 0x38) = 0;
    *(int*)((char*)this + 0x3c) = 0;
    *(int*)((char*)this + 0x40) = 0;
    *(float*)((char*)this + 0x44) = 0.0f;
    *(float*)((char*)this + 0x48) = 0.0f;
    *(float*)((char*)this + 0x4c) = 0.0f;
    *(float*)((char*)this + 0x50) = 1.0f;
}

// @fnv 0x004fd360
// src: XBOX_PDB 0x004fd360
bool BGSProjectile::GetHasExplosion()
{
    return GetFlag(2);
}

// @fnv 0x004fd420
bool BGSProjectile::GetFlag(unsigned int aeFlag) const
{
    return (*(int*)((TESDataHandler*)this)->GetTESRaceList() & aeFlag) ? true : false;
}

// @fnv 0x00821640
// src: XBOX_PDB 0x00821640
float TESCreature::TESObjectWEAP_GetShotsPerSecond()
{
    return m_fFirstCreatureStat;
}

void _Deallocate(void*);
// Calls FUN_004fcf80, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x004fcf50
void* BGSProjectileMethods::DestroyIfFlagged(unsigned int flags)
{
    BGSProjectile::~BGSProjectile();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

int __cdecl MinInt(int, int);
// @fnv 0x004fe080
int BGSProjectileMethods::GetProjectileCloneCount(TESObjectWEAP* apSourceWeapon)
{
    int icloneCount = 5;
    if (GetKind() == 0x40000 ||
        GetKind() == 0x100000 ||
        GetKind() == 0x80000)
    {
        icloneCount = 0;
    }
    else if (apSourceWeapon)
    {
        int iprojectiles = (int)((TESCreature*)apSourceWeapon)->TESObjectWEAP_GetShotsPerSecond() *
                           apSourceWeapon->GetDamageForActor(false, false, 0);
        int iprojectilesPerSecond7 = iprojectiles * 3;
        if (GetKind() != 0x20000)
            iprojectilesPerSecond7 =
                MinInt(iprojectilesPerSecond7, apSourceWeapon->GetClipRounds(false));
        if (this->GetFlag(0x100))
            iprojectilesPerSecond7 *= 4;
        icloneCount = iprojectilesPerSecond7;
    }
    return icloneCount;
}

template <int N> struct EndianSizeTag
{
    unsigned char value;
};

void BSEndian(unsigned char*, EndianSizeTag<0>);

struct FUN_004fccf0_shell
{
    void SwapEndianFields();
};

// @fnv 0x004fccf0
void FUN_004fccf0_shell::SwapEndianFields()
{
    BSEndian(reinterpret_cast<unsigned char*>(this), EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 4, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 8, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 12, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 24, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 28, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 32, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 44, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 48, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 52, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 68, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 72, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 76, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 80, EndianSizeTag<0>());
}

void* __memcpy(void*, const void*, unsigned int);

struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
};

struct FUN_004fdcf0_subobject
{
    virtual void FUN_004fdcf0_dummy1();
    virtual void FUN_004fdcf0_dummy2();
    virtual void FUN_004fdcf0_copy(FUN_004fdcf0_subobject*);
};

// @fnv 0x004fdcf0
void BGSProjectileMethods::CopyFromProjectile(TESForm* apCopy)
{
    BGSProjectile* pcopy;

    pcopy = dynamic_cast<BGSProjectile*>(apCopy);
    if (!pcopy)
        return;

    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(pcopy);

    ((FUN_004fdcf0_subobject*)((char*)this + 0xB4))->FUN_004fdcf0_copy((FUN_004fdcf0_subobject*)((char*)pcopy + 0xB4));

    *(unsigned int*)((char*)this + 0xCC) = *(unsigned int*)((char*)pcopy + 0xCC);

    __memcpy(((TESDataHandler*)this)->GetTESRaceList(), ((TESDataHandler*)pcopy)->GetTESRaceList(), 0x54);
}

struct FUN_005e79a0_t
{
  public:
    bool TESForm_CompareAllComponents(TESForm* pForm);
};

struct FUN_004fdd80_field
{
  public:
    virtual void FUN_004fdd80_v1();
    virtual void FUN_004fdd80_v2();
    virtual void FUN_004fdd80_v3();
    virtual bool FUN_004fdd80_v4(void* pObject);
};

int _memcmp(const void* pLeft, const void* pRight, unsigned int nCount);

// Compares this projectile against apCompare: returns true if the cast fails or any of several fields differ, false if all match.
// @fnv 0x004fdd80
bool BGSProjectileMethods::IsNotEqual(TESForm* apCompare)
{
    BGSProjectile* pcomp = dynamic_cast<BGSProjectile*>(apCompare);

    if (!pcomp)
        return true;

    if (reinterpret_cast<FUN_005e79a0_t*>(this)->TESForm_CompareAllComponents(pcomp))
        return true;

    if (_memcmp(reinterpret_cast<const void*>(reinterpret_cast<char*>(this) + 0x60),
                reinterpret_cast<TESDataHandler*>(pcomp)->GetTESRaceList(), 0x54) != 0)
        return true;

    if (reinterpret_cast<FUN_004fdd80_field*>(reinterpret_cast<char*>(this) + 0xb4)
            ->FUN_004fdd80_v4(reinterpret_cast<char*>(pcomp) + 0xb4))
        return true;

    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xcc) !=
        reinterpret_cast<BSFadeNode*>(pcomp)->QUserData())
        return true;

    return false;
}

// @fnv 0x004fcf80
BGSProjectile::~BGSProjectile()
{
    ClearData();
}

struct CloningProcess
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float fScale;
    CloningProcess(float afScale);
    ~CloningProcess();
};

struct ProjNiObject
{
    void* Clone(CloningProcess* apCloning);
};

struct ProjFlagHolder
{
    void SetFlag(bool abVal);
};

struct ProjResult
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual ProjFlagHolder* v10();
};

struct ProjBase;

struct ProjRef
{
    struct ProjBaseHolder* GetBase();
    unsigned int GetID();
};

struct ProjBase
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual ProjNiObject* Get3D(ProjRef* apRef);
};

struct ProjBaseHolder
{
    ProjBase* GetBaseObj();
};

struct ProjDataHandler
{
    bool IsValid(unsigned int aID);
};
extern ProjDataHandler* g_dataHandler;

struct ProjSaveLoad
{
    bool IsLoading();
};
extern ProjSaveLoad* g_BGSSaveLoadGame;

struct ProjCache
{
    ProjResult* Make(ProjNiObject* apObj);
};
ProjCache* GetProjCache(bool abCreate);

// Creates or clones a ProjResult for apRef depending on the object type and reference state, then sets a flag on the result if present.
// @fnv 0x004fd510
ProjResult* BGSProjectileMethods::CreateOrClone(ProjRef* apRef, bool abVal)
{
    ProjResult* pResult4 = 0;
    if (apRef)
    {
        switch (GetKind())
        {
        case 0x40000:
        case 0x100000:
            pResult4 = Create(apRef, true);
            break;
        default: {
            ProjRef* pRef8 = apRef;
            if (pRef8 && pRef8->GetBase() && pRef8->GetBase()->GetBaseObj())
            {
                ProjNiObject* pNodeVal = pRef8->GetBase()->GetBaseObj()->Get3D(0);
                CloningProcess kCloningA(1.0f);
                if (pNodeVal)
                    pResult4 = (ProjResult*)pNodeVal->Clone(&kCloningA);
            }
            else
            {
                ProjNiObject* p3D = reinterpret_cast<ProjNiObject*>(CreateNiNode(reinterpret_cast<TESObjectREFR*>(apRef)));
                if (p3D && g_dataHandler->IsValid(apRef->GetID()) && !g_BGSSaveLoadGame->IsLoading())
                {
                    pResult4 = GetProjCache(true)->Make(p3D);
                }
                if (!pResult4)
                {
                    pResult4 = Create(apRef, abVal);
                    if (p3D)
                        Release(apRef);
                }
            }
        }
        }
    }
    if (pResult4 && pResult4->v10())
        pResult4->v10()->SetFlag(true);
    return pResult4;
}

struct S_004fdfb0_Sub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, int b);
};
struct S_004fdfb0_Obj
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
    S_004fdfb0_Sub sub64;
};
struct S_004fdfb0_Mgr
{
    void ModelLoader_QueueModel(TESModel* model, int a, int b, int c, int d, int e, int f);
};
extern S_004fdfb0_Mgr* DAT_011c3b3c;
int __cdecl TES_GetLODMult(BGSProjectile* proj);

// @fnv 0x004fdfb0
void BGSProjectileMethods::QueueResourceLoad(IO_TASK_PRIORITY a, QueuedFile* b)
{
    if (TESModel::GetModelLength())
    {
        DAT_011c3b3c->ModelLoader_QueueModel(static_cast<TESModel*>(this), a, reinterpret_cast<int>(b), TES_GetLODMult(this), 1, 0, 0);
    }
    if (m_kProjectileModel.GetModelLength())
    {
        DAT_011c3b3c->ModelLoader_QueueModel(&this->m_kProjectileModel, a, reinterpret_cast<int>(b), 3, 1, 0, 0);
    }
    if (GetPreloadObject())
    {
        GetPreloadObject()->sub64.v4(a, reinterpret_cast<int>(b));
    }
}

// Returns the clip rounds, adding the weapon modifier when requested.
// @fnv 0x004fe160
int TESObjectWEAP::GetClipRounds(bool abAddExtra)
{
    if (abAddExtra)
    {
        return (unsigned char)GetModdedWeaponValue(static_cast<WEAPON_MOD_EFFECT>(2), 0) +
               BGSClipRoundsForm::GetClipRounds();
    }
    else
    {
        return BGSClipRoundsForm::GetClipRounds();
    }
}


// Maps the value returned by GetKind() to a code (0x3d-0x40, 0x69), returning 0 for any other kind.
// @fnv 0x004fe1d0
int BGSProjectileMethods::GetKindCode()
{
    switch (GetKind())
    {
    case 0x10000:
        return 0x3d;
    case 0x20000:
        return 0x3e;
    case 0x40000:
        return 0x3f;
    case 0x80000:
        return 0x40;
    case 0x100000:
        return 0x69;
    default:
        return 0;
    }
}

struct SaveRef
{
    SaveRef* Resolve();
};
bool IsEndian();
void WriteChunk(unsigned int, void*, unsigned int);
void WriteValue(unsigned int, int);
// @fnv 0x004fda00
void BGSProjectileMethods::WriteProjectileSave()
{
    BeginFormRecord();
    TESFullName::Save_00487010();
    TESModel::WriteToBuffer(0x4c444f4d, 0x54444f4d);
    BGSDestructibleObjectForm::Save();
    SaveRef* saved70 = reinterpret_cast<SaveRef*>(Data.apTargetLight);
    Data.apTargetLight = Data.apTargetLight ? reinterpret_cast<TESObjectLIGH*>(reinterpret_cast<SaveRef*>(Data.apTargetLight)->Resolve()) : 0;
    SaveRef* saved74 = reinterpret_cast<SaveRef*>(Data.m_pSecondLight);
    Data.m_pSecondLight = Data.m_pSecondLight ? reinterpret_cast<TESObjectLIGH*>(reinterpret_cast<SaveRef*>(Data.m_pSecondLight)->Resolve()) : 0;
    SaveRef* saved84 = reinterpret_cast<SaveRef*>(Data.ExplosionFadeData);
    Data.ExplosionFadeData = Data.ExplosionFadeData ? reinterpret_cast<BGSExplosion*>(reinterpret_cast<SaveRef*>(Data.ExplosionFadeData)->Resolve()) : 0;
    SaveRef* savedVal = reinterpret_cast<SaveRef*>(Data.m_pExplosionSound);
    Data.m_pExplosionSound = Data.m_pExplosionSound ? reinterpret_cast<TESSound*>(reinterpret_cast<SaveRef*>(Data.m_pExplosionSound)->Resolve()) : 0;
    SaveRef* saved4 = reinterpret_cast<SaveRef*>(Data.m_pFirstSound);
    Data.m_pFirstSound = Data.m_pFirstSound ? reinterpret_cast<TESSound*>(reinterpret_cast<SaveRef*>(Data.m_pFirstSound)->Resolve()) : 0;
    SaveRef* saved9c5 = reinterpret_cast<SaveRef*>(Data.m_pSecondSound);
    Data.m_pSecondSound = Data.m_pSecondSound ? reinterpret_cast<TESSound*>(reinterpret_cast<SaveRef*>(Data.m_pSecondSound)->Resolve()) : 0;
    SaveRef* saveda7 = reinterpret_cast<SaveRef*>(Data.m_pProjectileWeapon);
    Data.m_pProjectileWeapon = Data.m_pProjectileWeapon ? reinterpret_cast<TESObjectWEAP*>(reinterpret_cast<SaveRef*>(Data.m_pProjectileWeapon)->Resolve()) : 0;
    if (IsEndian())
        Data.Endian();
    TESForm___SaveData(&Data, 0x54);
    if (IsEndian())
        Data.Endian();
    Data.apTargetLight = reinterpret_cast<TESObjectLIGH*>(saved70);
    Data.m_pSecondLight = reinterpret_cast<TESObjectLIGH*>(saved74);
    Data.ExplosionFadeData = reinterpret_cast<BGSExplosion*>(saved84);
    Data.m_pExplosionSound = reinterpret_cast<TESSound*>(savedVal);
    Data.m_pFirstSound = reinterpret_cast<TESSound*>(saved4);
    Data.m_pSecondSound = reinterpret_cast<TESSound*>(saved9c5);
    Data.m_pProjectileWeapon = reinterpret_cast<TESObjectWEAP*>(saveda7);
    if (!m_kProjectileModel.GetModelLength())
    {
        WriteChunk(0x314d414e, const_cast<char*>(m_kProjectileModel.GetModelFilePath()), m_kProjectileModel.GetModelLength() + 1);
    }
    else
    {
        m_kProjectileModel.WriteToBuffer(0x314d414e, 0x324d414e);
    }
    WriteValue(0x4d414e56, m_eSoundLevel);
    FinishFormRecord();
}
