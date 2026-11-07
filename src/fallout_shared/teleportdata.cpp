#include "../../include/BSStringT.h"
// fallout_shared/teleportdata.cpp: BaseProcess, QuantityData, Thing, RefHandle and more (22 functions)
// include/TESFile.h needs the Windows types before layout_support.h stubs them.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "PointStorage.h"
#include "../../include/BaseProcess.h"
#include "../../include/BSExtraData.h"
#include "../../include/GO.h"
#include "teleportdata_decls.h"
#include "teleportdata_types_DoorTeleportData.h"

// @fnv 0x00717e50
ActorPackageContext* BaseProcess::GetCurrentProcessData(void) const
{
    return const_cast<ActorPackageContext*>(&m_kProcessData);
}

// @fnv 0x008b3bb0
TESForm* TeleportableReference::GetTeleportDestinationForm(void)
{
    return ((DoorTeleportSpaceOwner*)this)->receiver->IsPathingComplete();
}

// @fnv 0x0043a320
TESWorldSpace* TeleportableReference::GetTeleportWorldspace(void)
{
    TESWorldSpace* result = 0;
    if (m_pLinkedDoorReference)
    {
        DoorCell* cell = (DoorCell*)m_pLinkedDoorReference->GetParentCell();
        if (cell)
            result = cell->GetParentWorldSpace();
        else
        {
            cell = ((DoorCellProvider*)((char*)m_pLinkedDoorReference + 0x18))->vfn_0();
            if (cell)
                result = cell->GetParentWorldSpace();
        }
    }
    return result;
}

// @fnv 0x0043a210
void TeleportableReference::SetLinkedDoorReference(TESObjectREFR* reference, bool set)
{
    DoorCell* cell;
    if (reference)
    {
        cell = DoorTeleportData_GetTeleportCell();
        if (cell && cell->GetOwner())
            cell->SetTempPublic(set);
        cell = (DoorCell*)reference->GetParentCell();
        if (cell && cell->GetOwner())
            cell->SetTempPublic(set);
    }
}

// @fnv 0x0043a4e0
void TeleportableReference::Load(TESFile* file)
{
    if (file && file->GetChunkID() == 0x4c455458)
    {
        DoorTeleportLoadData data;
        memset(&data, 0, 32);
        file->GetChunkData(&data, 32);
        if (file->IsEndianConversionRequired())
            data.SwapEndian();
        m_pLinkedDoorReference = data.door;
        position = data.position;
        rotation = data.rotation;
        cFlags = data.flags;
    }
}

// @fnv 0x0043a2b0
// src: XBOX_PDB 0x0043a2b0
DoorCell* TeleportableReference::DoorTeleportData_GetTeleportCell(void)
{
    if (m_pLinkedDoorReference)
        return (DoorCell*)m_pLinkedDoorReference->GetParentCell();
    return 0;
}

template <int N> struct EndianSizeTag
{
};

void BSEndian(int*, EndianSizeTag<4>);

struct FUN_00414030_shell
{
    void SwapEndian();
};

// Swaps the byte order of seven consecutive 4-byte integers starting at this object's address using BSEndian.
// @fnv 0x00414030
void FUN_00414030_shell::SwapEndian()
{
    BSEndian((int*)this, EndianSizeTag<4>());
    BSEndian((int*)this + 1, EndianSizeTag<4>());
    BSEndian((int*)this + 2, EndianSizeTag<4>());
    BSEndian((int*)this + 3, EndianSizeTag<4>());
    BSEndian((int*)this + 4, EndianSizeTag<4>());
    BSEndian((int*)this + 5, EndianSizeTag<4>());
    BSEndian((int*)this + 6, EndianSizeTag<4>());
}

struct OwnershipExtraData : public BSExtraData
{
    int owner;
    OwnershipExtraData(int value);
};

struct ExtraListRemover
{
    void BaseExtraList_RemoveExtra(BSExtraData* extra, bool clear);
};

struct FUN_004197d0_shell : public BaseExtraList
{
    void SetExtraDataValue(int value);
};

// Sets the value of extra data type 0x22, removing it when zero or creating and adding it when absent.
// @fnv 0x004197d0
void FUN_004197d0_shell::SetExtraDataValue(int value)
{
    BSExtraData* extra = GetExtraData(0x22);
    if (extra)
    {
        if (!value)
        {
            ((ExtraListRemover*)this)->BaseExtraList_RemoveExtra(extra, true);
        }
        else
        {
            static_cast<OwnershipExtraData*>(extra)->owner = value;
        }
    }
    else if (value)
    {
        extra = new OwnershipExtraData(value);
        AddExtra(extra);
    }
}

extern float DAT_01016450;
struct R6815c0
{
    void _ref_006815c0();
};
NiPoint3* __fastcall SetComponents(NiPoint3*, float, float, float);

// Sets the first four bytes and the byte at offset 0x1c to zero, then assigns two NiPoint3 values built from DAT_01016450.
// @fnv 0x0043a160
// src: GUESS 0x0043a160 (confidence: low)
TeleportableReference* __fastcall Object_InitializeFields_0043a160(TeleportableReference* self)
{
    PointStorage a;
    PointStorage b;
    ((R6815c0*)((char*)self + 4))->_ref_006815c0();
    ((R6815c0*)((char*)self + 0x10))->_ref_006815c0();
    *(int*)self = 0;
    ((char*)self)[0x1c] = 0;
    *(NiPoint3*)((char*)self + 4) = *SetComponents(&reinterpret_cast<NiPoint3&>(a), DAT_01016450, DAT_01016450, DAT_01016450);
    *(NiPoint3*)((char*)self + 0x10) = *SetComponents(&reinterpret_cast<NiPoint3&>(b), DAT_01016450, DAT_01016450, DAT_01016450);
    return self;
}

struct FUN_0043a280_shell
{
    char pad[0x10];
    NiPoint3 m_vec;
    void SetVec(const NiPoint3& arVec);
};

// Assigns arVec to m_vec.
// @fnv 0x0043a280
void FUN_0043a280_shell::SetVec(const NiPoint3& arVec)
{
    m_vec = arVec;
}


extern const char $SG4382[];
struct FUN_00578870_host
{
    void TESObjectREFR_GetMapNameForLocation(::BSStringT<char>*);
};
struct FUN_0043a2e0_host
{
    FUN_00578870_host* m;
    void SetString(::BSStringT<char>*);
};
// If m is non-null, calls m->FUN_00578870(a); otherwise calls a->Set($SG4382, 0).
// @fnv 0x0043a2e0
void FUN_0043a2e0_host::SetString(::BSStringT<char>* apStr)
{
    if (m)
        m->TESObjectREFR_GetMapNameForLocation(apStr);
    else
        apStr->Set($SG4382, 0);
}

struct UnkArg
{
    void FUN_0043a3c0(ActorPackageContext*, int);
};
struct UnkThis : BaseProcess
{
    int DoorTeleportData_GetTeleportSpace();
    UnkArg* DoorTeleportData_GetTeleportWorldLocation(UnkArg*);
};
// Calls a->FUN_0043a3c0 with BaseProcess::GetCurrentProcessData() and FUN_0043a3f0(), then returns a.
// @fnv 0x0043a390
// src: COMMUNITY 0x0043a390
UnkArg* UnkThis::DoorTeleportData_GetTeleportWorldLocation(UnkArg* apArg)
{
    apArg->FUN_0043a3c0(BaseProcess::GetCurrentProcessData(), DoorTeleportData_GetTeleportSpace());
    return apArg;
}

struct FUN_0043a3c0
{
    PointStorage Point;  // the original constructor builds no point here
    TESForm* m_pPathingCell;
    FUN_0043a3c0(const NiPoint3& aPoint, TESForm* aSpace);
};

// @fnv 0x0043a3c0
FUN_0043a3c0::FUN_0043a3c0(const NiPoint3& aPoint, TESForm* aSpace)
{
    reinterpret_cast<NiPoint3&>(Point) = aPoint;
    m_pPathingCell = aSpace;
}

struct Callee_575ca0
{
    int TESObjectREFR_GetSpace();
};
struct Caller_43a3f0
{
    Callee_575ca0* p;
    int DoorTeleportData_GetTeleportSpace();
};
// Returns the result of calling FUN_00575ca0 on p when p is non-null, otherwise returns 0.
// @fnv 0x0043a3f0
// src: XBOX_PDB 0x0043a3f0
int Caller_43a3f0::DoorTeleportData_GetTeleportSpace()
{
    return p ? p->TESObjectREFR_GetSpace() : 0;
}

unsigned int __fastcall _FNV_GetFormID(TESObjectREFR* object);
bool _FUN_00401500();
void _FUN_00485990(unsigned int type, void* data, unsigned int size);

struct FUN_0043a420_shell : public DoorTeleportLoadData
{
    void SaveDoorTeleportData();
};

// Copies the door FormID, position, rotation, and flags into data, conditionally calls SwapEndian, and passes data to _FUN_00485990.
// @fnv 0x0043a420
// src: GUESS 0x0043a420 (confidence: medium)
void FUN_0043a420_shell::SaveDoorTeleportData()
{
    if (!door)
        return;

    DoorTeleportLoadData data;
    memset(&data, 0, sizeof(data));

    *reinterpret_cast<unsigned int*>(&data.door) = _FNV_GetFormID(door);
    data.position = position;
    data.rotation = rotation;
    data.flags = flags;

    if (_FUN_00401500())
        data.SwapEndian();

    _FUN_00485990(0x4c455458, &data, sizeof(data));

    if (_FUN_00401500())
        data.SwapEndian();
}

struct QuantityData
{
    char _pad[0x1C];
    unsigned char byte1C;
    void SetQuantity(unsigned int);
    void FUN_006f4ed0(ActorPackageContext*);
    void SetVec(BSSimpleList<TESFile*>*);
    void CopyFrom(void*);
};
// @fnv 0x0043a810
void QuantityData::CopyFrom(void* apOther)
{
    SetQuantity(reinterpret_cast<GO*>(apOther)->operator unsigned int());
    FUN_006f4ed0(((BaseProcess*)apOther)->BaseProcess::GetCurrentProcessData());
    SetVec(((TESForm*)apOther)->GetSourceFiles());
    byte1C = ((QuantityData*)apOther)->byte1C;
}

struct Call_439090
{
    bool _Call_439090(void* pObject);
};

struct FUN_0043a860_shell
{
    bool DoorTeleportData_Compare(TeleportableReference* apCompare);
};

// Returns true if the GO value, process data, source files, or the byte at offset 0x1c differ between this and apCompare.
// @fnv 0x0043a860
// src: XBOX_PDB 0x0043a860
bool FUN_0043a860_shell::DoorTeleportData_Compare(TeleportableReference* apCompare)
{
    if (reinterpret_cast<const GO*>(this)->operator unsigned int() !=
        reinterpret_cast<const GO*>(apCompare)->operator unsigned int())
        return true;

    if (reinterpret_cast<Call_439090*>(reinterpret_cast<BaseProcess*>(this)->BaseProcess::GetCurrentProcessData())
            ->_Call_439090(reinterpret_cast<BaseProcess*>(apCompare)->BaseProcess::GetCurrentProcessData()))
        return true;

    if (reinterpret_cast<Call_439090*>(reinterpret_cast<TESForm*>(this)->GetSourceFiles())
            ->_Call_439090(reinterpret_cast<TESForm*>(apCompare)->GetSourceFiles()))
        return true;

    if (*(reinterpret_cast<unsigned char*>(this) + 0x1c) != *(reinterpret_cast<unsigned char*>(apCompare) + 0x1c))
        return true;

    return false;
}

struct FUN_0043a8f0_shell
{
    unsigned short __thiscall ExtraTeleport_GetSaveSize();
};

// Returns 0x1c, computed by adding 0xc, 0xc, and 4 to an unsigned short initialized to zero.
// @fnv 0x0043a8f0
// src: COMMUNITY 0x0043a8f0
unsigned short __thiscall FUN_0043a8f0_shell::ExtraTeleport_GetSaveSize()
{
    unsigned short v = 0;
    v += 0xc;
    v += 0xc;
    v += 4;
    return v;
}

class Other
{
  public:
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

#include "../../include/TESSaveLoadGame.h"
extern TESSaveLoadGame* DAT_011de45c;

struct Thing
{
    Other* m_object;
    char m_data04[12];
    char m_data10[12];
    void Save();
};

// Saves the 12-byte data blocks and the form ID of m_object to the save stream via TESSaveLoadGame.
// @fnv 0x0043a930
void Thing::Save()
{
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(m_data04, 0xc);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(m_data10, 0xc);
    int formID = 0;
    if (m_object != 0)
        formID = m_object->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    DAT_011de45c->TESSaveLoadGame_SaveNumericID(&formID, 4);
}

TESForm* TESForm_GetFormByNumericID(unsigned int auiFormId);

namespace s835fe0 {

struct RefHandle
{
    TESObjectREFR* m_pkRef;

    void ResolveRef(void* pvUnused);
};

// Replaces m_pkRef with the result of FUN_004839c0 cast to TESObjectREFR, or null if m_pkRef is null.
// @fnv 0x00835fe0
void RefHandle::ResolveRef(void* pvUnused)
{
    m_pkRef = m_pkRef ? dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID((unsigned int)m_pkRef)) : 0;
}

}

struct CoordinateTriple
{
    bool BGSWorldLocation_IsLocationLoaded();
};

// src: XBOX_PDB 0x00527a00
bool CoordinateTriple::BGSWorldLocation_IsLocationLoaded()
{
    return false;
}

struct TESObjectREFR_ext : public TESObjectREFR
{
    bool GetReferencePersistence();
};

bool __thiscall TESObjectREFR_ext::GetReferencePersistence()
{
    return false;
}

// Returns true when either called predicate is true; otherwise returns false.
// @fnv 0x009a96f0
// src: XBOX_PDB 0x009a96f0
bool CombatUtilities_CanActorExistInSpace(TESObjectREFR* refr, CoordinateTriple* location)
{
    if (((TESObjectREFR_ext*)refr)->GetReferencePersistence())
        return true;
    if (location->BGSWorldLocation_IsLocationLoaded())
        return true;
    return false;
}

struct FUN_0043a590_shell : public TeleportableReference
{
    bool DoorTeleportData_InitItem(TESForm*);
};

void __cdecl FUN_00485d50(unsigned int* formID, TESFile* file);
TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int formID);
void __cdecl Warning_005b5e40(const char* fmt, ...);
int __cdecl FUN_00ec7595(double x);
int __cdecl FUN_00ec75b1(double x);

struct TeleportFormTypeName
{
    const char* name;
    int unk04;
    int unk08;
};

extern TeleportFormTypeName DAT_01187004[];

// Resolves the linked door, checks its form type, and resets position or rotation to zero when their checks fail.
// @fnv 0x0043a590
// src: XBOX_PDB 0x0043a590
bool FUN_0043a590_shell::DoorTeleportData_InitItem(TESForm* form)
{
    unsigned int formID = (unsigned int)m_pLinkedDoorReference;
    FUN_00485d50(&formID, form->GetFile(-1));
    m_pLinkedDoorReference = dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(formID));
    if (!m_pLinkedDoorReference)
    {
        Warning_005b5e40(FNV_NoDoor, formID);
        return false;
    }
    if (((TESFormTypeView*)m_pLinkedDoorReference->GetObjectReference())->GetFormType() != 0x1C)
    {
        Warning_005b5e40(FNV_InvalidDoor, formID,
                     DAT_01187004[((TESFormTypeView*)m_pLinkedDoorReference->GetObjectReference())->GetFormType()].name,
                     ((TESForm*)m_pLinkedDoorReference->GetObjectReference())->GetName(),
                     ((TESForm*)m_pLinkedDoorReference->GetObjectReference())->GetFormID());
        m_pLinkedDoorReference = 0;
        return false;
    }
    if (!FUN_00ec7595(position.x) || !FUN_00ec7595(position.y) || !FUN_00ec7595(position.z) ||
        FUN_00ec75b1(position.x) || FUN_00ec75b1(position.y) || FUN_00ec75b1(position.z))
    {
        Warning_005b5e40(FNV_BadLocation);
        position = NiPoint3::ZERO;
    }
    if (!FUN_00ec7595(rotation.x) || !FUN_00ec7595(rotation.y) || !FUN_00ec7595(rotation.z) ||
        FUN_00ec75b1(rotation.x) || FUN_00ec75b1(rotation.y) || FUN_00ec75b1(rotation.z))
    {
        Warning_005b5e40(FNV_BadAngle);
        rotation = NiPoint3::ZERO;
    }
    return true;
}
