#include "../../include/BSStringT.h"
#include "../../include/InterfaceManager.h"
// fallout_shared/tesworldspace.cpp: TESWorldSpace, TESObjectCELL, TESRegion, InterfaceManager and more (90 functions)

#include "../../include/BGSAcousticSpace.h"
#include "../../include/EffectSetting.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESFile.h"
#include "../../include/TESObjectACTI.h"
#include "../../include/TESRegion.h"
#include "../../include/BSOcclusionPlane.h"
#include "../../include/StartMenu.h"
#include "../../include/TESClimate.h"
#include "../../include/TESFullName.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESTexture.h"
#include "../../include/TESWorldSpace.h"
#include "../../include/NiTPointerMap.h"

class BGSTerrainManager;
extern TESDataHandler* g_dataHandler;
extern NiTPointerMap<unsigned int, TESObjectREFR*>* DAT_011c40b0;

class Tile;

class TESSound;
class TESQuest;
class TESEffectShader;
extern "C" void* memset(void*, int, unsigned int);
extern float DAT_01031920;
extern const char DAT_010187a0[];
int Warning(const char*, ...);
#include "../../include/AutoMemHelper.h"
#include "../../include/DummyPointerMap.h"
#include "../../include/GO.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint3.h"
#include "../../include/SL.h"
#include "../../include/StrMem.h"
// These methods are not yet declared by the shared cell header.
struct CellRuntimeMethods : TESObjectCELL
{
    void SetFlag400(int);
    void ResetCellData();
    void SetWorldSpace(TESWorldSpace*);
    void MoveReferencesToWorldCells(TESWorldSpace*);
    bool FUN_00550200(TESObjectREFR*);
    bool TESObjectCELL_EnumReferencesCloseToPoint(const NiPoint3*, float, const NiPoint3*, float, int, unsigned int);
    float TESObjectCELL_GetDistanceFromPoint(const NiPoint3*);
};

// @fnv 0x00425fd0
bool TESObjectCELL::IsCellInterior() const
{
    return (reinterpret_cast<const unsigned char*>(this)[0x24] & 1) ? true : false;
}
// Sets the world space's map name from the given string and returns true.
// @fnv 0x00583330
bool TESWorldSpace::SetDateTimeText(const char* name)
{
    mapName.Set(name, 0);
    return true;
}
// Returns the terrain manager of the parent world space if one exists, otherwise this world space's own terrain.
// @fnv 0x00586170
BGSTerrainManager* TESWorldSpace::GetWorldTerrainManager()
{
    if (GetParentWorld(PU_LOD))
        return GetParentWorld(PU_LOD)->GetWorldTerrainManager();
    return terrain;
}
// Returns parent if it exists and GetParentUseFlag(flag) is set, otherwise returns null.
// @fnv 0x00586390
TESWorldSpace* TESWorldSpace::GetParentWorld(PARENT_USE_FLAG aeParentUseFlag)
{
    if (parent && !GetParentUseFlag(aeParentUseFlag))
        return 0;
    return parent;
}
// Looks up key in cellMap and returns the stored reference cast to TESObjectCELL, or null if not found.
// @fnv 0x00587630
TESObjectCELL* TESWorldSpace::GetCellByKey(unsigned int key)
{
    TESObjectREFR* cell = 0;
    if (cellMap->GetAt(key, cell))
        return (TESObjectCELL*)cell;
    return 0;
}
// If ref is non-null and not temporary, creates a persistent cell and adds ref to it.
// @fnv 0x00587ff0
void TESWorldSpace::AddPersistentReference(TESObjectREFR* ref)
{
    if (ref && !ref->IsTemporary())
    {
        TESObjectCELL* cell = CreatePersistentCell();
        cell->AddReference(ref, false);
    }
}
// @fnv 0x004f1260
void TESRegion::AssignWorldSpace(TESWorldSpace* apWorldSpace)
{
    m_pContainingWorldspace = apWorldSpace;
    if (m_pContainingWorldspace && IsConstantGlobal() && !g_dataHandler->LoadDescriptionForForm())
        m_pContainingWorldspace->SetHasRegions(true);
}
// @fnv 0x00473ff0
bool TESWorldSpace::IsFormIDOwnedByFile(unsigned int key, TESFile* file)
{
    bool result = true;
    if (DAT_011c40b0 && key)
    {
        TESObjectREFR* value = 0;
        if (DAT_011c40b0->GetAt(key, value) && value)
        {
            TESFile* parent = file->GetThreadSafeRootFile();
            if (!parent)
                parent = file;
            if (value != (TESObjectREFR*)parent)
                result = false;
        }
    }
    return result;
}
// Clears night and looping sounds, effect shader, calls three helpers, resets the full name and zeroes 16 bytes at offset 0x80.
// @fnv 0x00586480
void TESWorldSpace::ClearWorldSpaceReferences()
{
    ((BGSAcousticSpace*)this)->SetNightSound(0);
    ((TESObjectACTI*)this)->SetLoopingSound(0);
    ((EffectSetting*)this)->SetEffectShader(0);
    SetWaterLODHeight(0.0f);
    SetDefaultLandHeight(DAT_01031920);
    Projectile_SetPower(0.0f);
    ((TESFullName*)((char*)this + 0x24))->SetFullName((const char*)0);
    memset((char*)this + 0x80, 0, 16);
}
// Validates x and y are within -32768..32767, builds a key from them, and looks up the cell in cellMap, returning it or null.
// @fnv 0x005875a0
TESObjectCELL* TESWorldSpace::GetCellAtGridPosition(int x, int y)
{
    if (x > 32767 || y > 32767 || x < -32768 || y < -32768)
    {
        Warning(DAT_010187a0, -32768, 32767);
        return 0;
    }
    TESObjectREFR* pCell;
    int iKey = BuildCellKey((unsigned short)x, (unsigned short)y);
    pCell = 0;
    if (cellMap->GetAt(iKey, pCell))
        return (TESObjectCELL*)pCell;
    return 0;
}
// @fnv 0x00586150
// src: XBOX_PDB 0x00586150
Tile* InterfaceManager::CombatController_GetCombatState()
{
    return pMenuRoot;
}
// @fnv 0x00584bc0
void TESWorldSpace::SetFieldD0(unsigned int value)
{
    fieldD0 = value;
}
// @fnv 0x00586110
// src: COMMUNITY 0x00586110
void TESWorldSpace::SetDefaultLandHeight(float value)
{
    fC8 = value;
}
// @fnv 0x00586130
// src: COMMUNITY 0x00586130
void TESWorldSpace::Projectile_SetPower(float value)
{
    fCC = value;
}
// @fnv 0x005861b0
bool TESWorldSpace::GetSmallWorld()
{
    if (flags4C & 1)
        return true;
    return false;
}
// @fnv 0x005862e0
bool TESWorldSpace::IsFlag4C20Set()
{
    if (flags4C & 0x20)
        return true;
    return false;
}
// Sets parent to world and clears field4E when world is null.
// @fnv 0x005863d0
void TESWorldSpace::SetParent(TESWorldSpace* world)
{
    parent = world;
    if (!world)
        field4E = 0;
}
// @fnv 0x00588270
// src: COMMUNITY 0x00588270
void TESWorldSpace::BuildTeleportDoorList(BSSimpleArray<TESObjectREFR*, 1024>& doors)
{
    TESObjectCELL* cell = GetInteriorCell();
    if (cell)
        cell->AppendCellReferences(doors);
}

// Sets or clears bit 0 of the byte at offset 0x4c on this TESWorldSpace based on abVal.
// @fnv 0x005861d0
void TESWorldSpace::SetFlagBit0(bool abVal)
{
    if (abVal)
        *(unsigned char*)((char*)this + 0x4c) |= 1;
    else
        *(unsigned char*)((char*)this + 0x4c) &= ~1;
}

// Packs two shorts into one int: asX shifted left 16 bits, OR'd with the low 16 bits of asY.
// @fnv 0x00587410
int __cdecl PackShortPair(short asHigh, short asLow)
{
    int key = asHigh;
    key <<= 16;
    key |= (unsigned short)(asLow & 0xFFFF);
    return key;
}

struct NiStream;
struct blob12
{
    char b[12];
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];

int __cdecl TruncateFloatToInt(float);
int __cdecl _FNV_Finite(double);
int __cdecl _FNV_IsNaN(double);

// @fnv 0x00587440
// src: XBOX_PDB 0x00587440
int __cdecl TESWorldSpace_GetKeyForWorldCoord(const NiPoint3* aCoord)
{
    int icellx;
    int icelly;

    if (!_FNV_Finite(aCoord->x) || !_FNV_Finite(aCoord->y) || !_FNV_Finite(aCoord->z) || _FNV_IsNaN(aCoord->x) ||
        _FNV_IsNaN(aCoord->y) || _FNV_IsNaN(aCoord->z))
    {
        return 0x7fff7fff;
    }

    icellx = TruncateFloatToInt(aCoord->x) >> 12;
    icelly = TruncateFloatToInt(aCoord->y) >> 12;
    return TESWorldSpace::BuildCellKey((short)icellx, (short)icelly);
}

void* __fastcall _FNV_GetObjectReference(void*);
int __fastcall _FNV_GetFormType(void*);

// Returns true if apRef is non-null and its object reference's form type is one of the listed types.
// @fnv 0x00587c80
// src: COMMUNITY 0x00587c80
bool __cdecl TESWorldSpace_IsFixedRef(void* apRef)
{
    bool bretval = false;
    if (apRef && _FNV_GetObjectReference(apRef))
    {
        switch (_FNV_GetFormType(_FNV_GetObjectReference(apRef)))
        {
        case 0x0d:
        case 0x15:
        case 0x1b:
        case 0x1c:
        case 0x20:
        case 0x21:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x2c:
        case 0x2d:
            bretval = true;
            break;
        }
    }
    return bretval;
}

// If apRef is non-null, gets the interior cell and calls RemoveReference on it with apRef.
// @fnv 0x00588030
// src: XBOX_PDB 0x00588030
void TESWorldSpace::RemovePersistentRef(TESObjectREFR* apRef)
{
    if (apRef)
    {
        TESObjectCELL* poldcell = GetInteriorCell();
        if (poldcell)
        {
            poldcell->RemoveReference(apRef);
        }
    }
}

void* __cdecl operator new(unsigned int);
extern float const DAT_01015f5c;

struct OFFSET_DATA_24
{
    unsigned int pCellOffsets;
    NiPoint2 m_kFirstPoint;
    NiPoint2 m_kEndPoint;
    unsigned int uiFileOffset;

    OFFSET_DATA_24();
};

// @fnv 0x00588b00
void* TESWorldSpace::GetOrCreateCellOffsetData(TESFile* apFile)
{
    OFFSET_DATA_24* pdata = 0;
    TESFile* pmainfile = apFile;
    while (pmainfile && pmainfile->GetThreadSafeRootFile())
    {
        pmainfile = pmainfile->GetThreadSafeRootFile();
    }
    if (!((DummyPointerMap*)((char*)this + 0xb0))->GetAt((unsigned int)pmainfile, (unsigned int&)pdata) || !pdata)
    {
        pdata = new OFFSET_DATA_24;
        pdata->pCellOffsets = 0;
        pdata->uiFileOffset = 0;
        pdata->m_kFirstPoint = NiPoint2(3.4028234663852886e+38f, 3.4028234663852886e+38f);
        pdata->m_kEndPoint = NiPoint2(DAT_01015f5c, DAT_01015f5c);
        ((DummyPointerMap*)((char*)this + 0xb0))->SetAt((unsigned int)pmainfile, (unsigned int)pdata);
    }
    return pdata;
}

void __fastcall _ref_006815c0(void* pThis);

// Calls _ref_006815c0 on the two sub-objects at offsets 4 and 0xC of pThis and returns pThis.
// @fnv 0x00588c50
// src: COMMUNITY 0x00588c50
char* __fastcall TESWorldSpace_OFFSET_DATA_OFFSET_DATA(char* pThis)
{
    _ref_006815c0(pThis + 4);
    _ref_006815c0(pThis + 0xC);
    return pThis;
}

extern int DAT_01031fac;

struct FUN_00588fa0_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_00588fa0_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00588fa0
// src: EXE 0x00588fa0
int* __fastcall NiTPointerMap_unsigned_int_BSSimpleList_TESObjectREFR_NiTPointerMap(int* self, FUN_00588fa0_arg a)
{
    FUN_005890c0(self, a);
    *self = (int)&DAT_01031fac;
    return self;
}

void __fastcall _ref_00726070(void*);

// @fnv 0x006698d0
// src: COMMUNITY 0x006698d0
void __fastcall TESPackage_GetOnChangeIdle(char* pThis)
{
    _ref_00726070(pThis + 0x6c);
}

struct Flt
{
    operator unsigned int() const;
};
// Returns the unsigned int at offset 0xc0 as a char pointer, or an empty string when that value is zero.
// @fnv 0x005832f0
char* TESWorldSpace::GetName() const
{
    return ((Flt*)((char*)this + 0xc0))->operator unsigned int()
               ? (char*)((Flt*)((char*)this + 0xc0))->operator unsigned int()
               : "";
}

unsigned int __fastcall _ref_0084e3a0(void*);
// @fnv 0x00587670
// src: XBOX_PDB 0x00587670
bool TESWorldSpace::AddCell(TESObjectCELL* apCell)
{
    int key;
    TESObjectCELL* ignore;
    if (!apCell || apCell->IsCellInterior())
        return false;
    if (apCell->IsCellPersistent())
    {
        if (*(TESObjectCELL**)((char*)this + 0x34))
            return false;
        *(TESObjectCELL**)((char*)this + 0x34) = apCell;
    }
    else
    {
        key = TESWorldSpace::BuildCellKey(apCell->GetCellGridX(), apCell->GetCellGridY());
        if ((*(DummyPointerMap**)((char*)this + 0x30))->GetAt(key, (unsigned int&)ignore))
        {
            Warning("CELLS: Cell (%08X) %s already exists at coord (%i, %i ).", _ref_0084e3a0(ignore),
                    ((const char*(__thiscall*)(TESObjectCELL*))(*(void***)ignore)[0x130 / 4])(ignore),
                    apCell->GetCellGridX(), apCell->GetCellGridY());
            return false;
        }
        (*(DummyPointerMap**)((char*)this + 0x30))->SetAt(key, (unsigned int)apCell);
    }
    ((CellRuntimeMethods*)apCell)->SetWorldSpace(this);
    return true;
}

template <class T> struct WorldReferenceList
{
    T item;
    WorldReferenceList<T>* next;
    ~WorldReferenceList();
    void operator delete(void*);
};
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
extern ATM g_011ca60c;
struct WsH
{
    static int __cdecl GetKeyForWorldCoord(const NiPoint3&);
};
struct ListH
{
    void _ref_00905330(TESObjectREFR**);
    bool _ref_008256d0();
};
struct MapH
{
    bool RemoveAt(unsigned int);
};
bool __cdecl TESWorldSpace_IsFixedRef(void*);
// @fnv 0x00587e40
// src: COMMUNITY 0x00587e40
void TESWorldSpace::RemoveFromPersistentRefData(TESObjectREFR* apRef)
{
    unsigned int ikey;
    WorldReferenceList<const char*>* preflist;
    if (apRef && !apRef->IsTemporary())
    {
        g_011ca60c.QueryPerformanceCounter(0);
        if (!TESWorldSpace_IsFixedRef(apRef))
        {
            ((ListH*)((char*)this + 0x60))->_ref_00905330(&apRef);
        }
        else
        {
            ikey = WsH::GetKeyForWorldCoord(
                *((NiPoint3 * (__thiscall*)(TESObjectREFR*))(*(void***)apRef)[0x1f4 / 4])(apRef));
            preflist = 0;
            ((DummyPointerMap*)((char*)this + 0x50))->GetAt(ikey, (unsigned int&)preflist);
            if (preflist)
            {
                ((ListH*)preflist)->_ref_00905330(&apRef);
                if (((ListH*)preflist)->_ref_008256d0())
                {
                    delete preflist;
                    ((MapH*)((char*)this + 0x50))->RemoveAt(ikey);
                }
            }
        }
        g_011ca60c.WaitForTasksDuringRendering();
    }
}

// Returns the TESObjectCELL stored at offset 0x34, creating and initializing it first if it is null.
// @fnv 0x00588070
TESObjectCELL* TESWorldSpace::GetOrCreateCell()
{
    if (!*(TESObjectCELL**)((char*)this + 0x34))
    {
        *(TESObjectCELL**)((char*)this + 0x34) = new TESObjectCELL;
        (*(CellRuntimeMethods**)((char*)this + 0x34))->SetFlag400(1);
        (*(CellRuntimeMethods**)((char*)this + 0x34))->ResetCellData();
    }
    return *(TESObjectCELL**)((char*)this + 0x34);
}

struct FormIDData
{
    unsigned int pad0[5];
    unsigned int formID;
};

extern unsigned int __fastcall _ref_00472660(void*);
extern unsigned int __fastcall _ref_0084e3a0(void*);
extern unsigned char DAT_0118730c;

struct WorldSpaceFileMethods : TESWorldSpace
{
    FormIDData* __thiscall TESWorldSpace_GetOffsetData(TESFile* apFile);
    bool IsFileFormIDMatching(TESFile* apFile);
};

// @fnv 0x005858b0
bool WorldSpaceFileMethods::IsFileFormIDMatching(TESFile* apFile)
{
    FormIDData* pdata = TESWorldSpace_GetOffsetData(apFile);
    if (apFile && apFile->IsMasterFile() && pdata && pdata->formID)
    {
        if (apFile->SetOffset(pdata->formID))
        {
            if (_ref_00472660(apFile) == DAT_0118730c)
            {
                if (apFile->GetFormID() == _ref_0084e3a0(this))
                    return true;
            }
        }
    }
    return false;
}

// Returns the climate of the parent world if one exists, otherwise the climate stored at offset 0x40 of this world space.
// @fnv 0x00585fe0
// src: COMMUNITY 0x00585fe0
TESClimate* TESWorldSpace::GetClimate()
{
    if (GetParentWorld(PARENT_USE_FLAG(4)))
        return GetParentWorld(PARENT_USE_FLAG(4))->GetClimate();
    return climate;
}

// Missing worldspace methods are declared in adapters without duplicated fields.
struct WorldSpaceImageMethods : TESWorldSpace
{
    TESWorldSpace* GetWorldSpaceOrParentWorld();
};

// Returns field44 if set, otherwise recurses into the parent world space obtained via GetParentWorld with flag 5, or returns null.
// @fnv 0x00586020
TESWorldSpace* WorldSpaceImageMethods::GetWorldSpaceOrParentWorld()
{
    TESWorldSpace* result = reinterpret_cast<TESWorldSpace*>(imageSpace);
    if (!result)
    {
        if (GetParentWorld(static_cast<TESWorldSpace::PARENT_USE_FLAG>(5)))
        {
            result =
                reinterpret_cast<WorldSpaceImageMethods*>(GetParentWorld(static_cast<TESWorldSpace::PARENT_USE_FLAG>(5)))
                    ->GetWorldSpaceOrParentWorld();
        }
    }
    return result;
}

// Flag accessors not yet declared in the shared header.
struct WorldSpaceFlagMethods : TESWorldSpace
{
    bool HasFlag2();
    bool IsFlag8Set();
    void SetFlag8(bool);
    bool IsFlagSet();
    char IsFlag80Set();
    bool TESWorldSpace_IsAllowNPCFallDamage();
};

// @fnv 0x00586210
bool WorldSpaceFlagMethods::HasFlag2()
{
    if (((unsigned char)(*((unsigned char*)this + 0x4c)) & 2))
        return true;
    return false;
}

// Exe 0x00586230: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct TesworldspaceOffset08View
{
    unsigned int GetFlags(void);
    char HasFlag80000();
};

// @fnv 0x00586230
char TesworldspaceOffset08View::HasFlag80000()
{
    unsigned int flags = GetFlags();
    if (flags & 0x80000)
        return 1;
    return 0;
}

// @fnv 0x00586260
bool WorldSpaceFlagMethods::IsFlag8Set()
{
    if (((unsigned char*)this)[0x4c] & 8)
        return 1;
    return 0;
}

// Sets or clears bit 3 (0x8) of the byte at offset 0x4c on this object based on bFlag.
// @fnv 0x00586280
void WorldSpaceFlagMethods::SetFlag8(bool bFlag)
{
    if (bFlag)
        ((unsigned char*)this)[0x4c] |= 8;
    else
        ((unsigned char*)this)[0x4c] &= ~8;
}

// @fnv 0x005862c0
bool WorldSpaceFlagMethods::IsFlagSet()
{
    if (((unsigned char*)((char*)this + 0x4c))[0] & 0x10)
        return 1;
    return 0;
}

// Returns 1 if the byte at offset 0x4c has bit 0x80 set, otherwise 0.
// @fnv 0x00586300
char WorldSpaceFlagMethods::IsFlag80Set()
{
    if ((*(unsigned char*)((char*)this + 0x4c) & 0x80) != 0)
        return 1;
    return 0;
}

// @fnv 0x00586320
// src: COMMUNITY 0x00586320
bool WorldSpaceFlagMethods::TESWorldSpace_IsAllowNPCFallDamage()
{
    if ((*(unsigned char*)((char*)this + 0x4c) & 0x40) != 0)
        return false;
    return true;
}

// Returns the full name of the parent worldspace if one exists, otherwise the full name of this worldspace.
// @fnv 0x00586440
// src: XBOX_PDB 0x00586440
const char* TESWorldSpace::GetWorldMapTextureName()
{
    if (this->GetParentWorld(static_cast<TESWorldSpace::PARENT_USE_FLAG>(2)))
    {
        return (reinterpret_cast<TESFullName*>(
                    reinterpret_cast<char*>(this->GetParentWorld(static_cast<TESWorldSpace::PARENT_USE_FLAG>(2))) +
                    0x24))
            ->GetFullName();
    }
    return (reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(this) + 0x24))->GetFullName();
}

extern StartMenu g_011ca130;

// @fnv 0x00586980
// src: COMMUNITY 0x00586980
char const* TESObjectCELL_GetDefaultCellName()
{
    return reinterpret_cast<const char*>(g_011ca130.GetMenuTitle());
}

// Splits a 32-bit value into its high and low 16-bit halves, storing the high half in *b and the low half in *c.
// @fnv 0x00587520
void SplitUInt32(unsigned int auiValue, unsigned short* b, unsigned short* c)
{
    *b = (unsigned short)((auiValue >> 0x10) & 0xffff);
    *c = (unsigned short)(auiValue & 0xffff);
}

namespace fnv_00587550 {
extern "C"
{
    int __cdecl TruncateFloatToInt(float);
}

}  // namespace fnv_00587550

// @fnv 0x00587550
// src: XBOX_PDB 0x00587550
TESObjectCELL* TESWorldSpace::GetCellFromWorldCoord(const NiPoint3& aCoord)
{

    int icellx = fnv_00587550::TruncateFloatToInt(aCoord.x) >> 12;
    int icelly = fnv_00587550::TruncateFloatToInt(aCoord.y) >> 12;
    return GetCellAtGridPosition(icellx, icelly);
}

extern "C"
{
    struct TESWaterForm;
}

extern TESWaterForm* DAT_011ca53c;

// @fnv 0x00586070
// src: COMMUNITY 0x00586070
TESWaterForm* __fastcall TESWorldSpace_GetWaterType(TESWorldSpace* apWorldSpace)
{
    if (apWorldSpace->GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)3))
        return TESWorldSpace_GetWaterType(apWorldSpace->GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)3));
    if (*(TESWorldSpace**)((char*)apWorldSpace + 0x74))
        return (TESWaterForm*)*(TESWorldSpace**)((char*)apWorldSpace + 0x74);
    return DAT_011ca53c;
}

template <class T> class WorldReferenceList;

struct FUN_0054b8c0_shell
{
    void AddStaticRefsToList(WorldReferenceList<const char*>*);
};

struct WorldSpaceStaticReferenceMethods : TESWorldSpace
{
    void TESWorldSpace_AddAudioMarkersToList(WorldReferenceList<const char*>*);
};

// If list is non-null, gets the interior cell from this world space and forwards the list to the cell's method.
// @fnv 0x00588520
// src: COMMUNITY 0x00588520
void __thiscall WorldSpaceStaticReferenceMethods::TESWorldSpace_AddAudioMarkersToList(WorldReferenceList<const char*>* list)
{
    if (list)
    {
        TESObjectCELL* cell = ((TESWorldSpace*)this)->GetInteriorCell();
        if (cell)
        {
            ((FUN_0054b8c0_shell*)cell)->AddStaticRefsToList(list);
        }
    }
}

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<2>);
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);

struct FUN_005840b0_shell
{
    void __thiscall SwapIntegerAndShortByteOrder();
};

// Byte-swaps the two ints and four shorts stored in this object via BSEndian.
// @fnv 0x005840b0
// src: GUESS 0x005840b0 (confidence: medium)
void __thiscall FUN_005840b0_shell::SwapIntegerAndShortByteOrder()
{
    BSEndian((int*)this, EndianSizeTag<2>());
    BSEndian((int*)(this + 4), EndianSizeTag<2>());
    BSEndian((unsigned short*)(this + 8), EndianSizeTag<2>());
    BSEndian((unsigned short*)(this + 0xa), EndianSizeTag<2>());
    BSEndian((unsigned short*)(this + 0xc), EndianSizeTag<2>());
    BSEndian((unsigned short*)(this + 0xe), EndianSizeTag<2>());
}

struct Modifier
{
    void SetValue(float);
};
struct AlphaColor
{
    void TESRegionPoint_SetX(float);
};
struct FUN_004f6fc0_shell
{
    int _a;
    int _b;
    void TESRegionPoint_TESRegionPoint();
};
struct FUN_004f6850_shell
{
    void TESRegionList_GetDerivedData(void*, FUN_004f6fc0_shell*, void*);
};
struct FUN_004f6800_shell
{
    void TESRegionList_GetDerivedData_(void*, float*, void*);
};
// @fnv 0x004f6800
// src: COMMUNITY 0x004f6800
void FUN_004f6800_shell::TESRegionList_GetDerivedData_(void* a1, float* a2, void* a3)
{
    FUN_004f6fc0_shell tmp;
    tmp.TESRegionPoint_TESRegionPoint();
    ((AlphaColor*)&tmp)->TESRegionPoint_SetX(a2[0]);
    ((Modifier*)&tmp)->SetValue(a2[1]);
    ((FUN_004f6850_shell*)this)->TESRegionList_GetDerivedData(a1, &tmp, a3);
}

struct FUN_00528560_Host
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual TESObjectCELL* v5(unsigned int) = 0;
    TESObjectCELL* GetCellAtGridCoord(unsigned short, unsigned short);
};
// Computes a grid key from the X and Y coordinates and returns the cell obtained from v5 for that key.
// @fnv 0x00528560
TESObjectCELL* FUN_00528560_Host::GetCellAtGridCoord(unsigned short ausGridX, unsigned short ausGridY)
{
    int key;
    key = TESWorldSpace::BuildCellKey(ausGridX, ausGridY);
    return v5(key);
}

void __cdecl _Deallocate(void*);

struct S_00583040
{
    void FUN_006fc980();
    void* FUN_00583040(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_006fc980, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00583040
void* S_00583040::FUN_00583040(unsigned int flags)
{
    FUN_006fc980();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00584530 {

struct FormIDData
{
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
};

struct WorldSpaceFileMethods : TESWorldSpace
{
    FormIDData* TESWorldSpace_GetOffsetData(TESFile*);
    int TESWorldSpace_GetIndexForCellCoord(TESFile* file, int x, int y);
};

// @fnv 0x00584530
// src: COMMUNITY 0x00584530
int WorldSpaceFileMethods::TESWorldSpace_GetIndexForCellCoord(TESFile* file, int x, int y)
{
    FormIDData* pdata = TESWorldSpace_GetOffsetData(file);
    if (!pdata)
        return -1;
    int iminX = (int)pdata->f4 >> 12;
    int iminY = (int)pdata->f8 >> 12;
    int imaxX = (int)pdata->fc >> 12;
    int imaxY = (int)pdata->f10 >> 12;
    if (x > imaxX || x < iminX || y > imaxY || y < iminY)
        return -1;
    return (imaxX - iminX + 1) * (y - iminY) + x - iminX;
}
}  // namespace fnv_00584530

class TESWaterForm;
extern TESWaterForm* DAT_011ca53c;

// @fnv 0x005860c0
// src: COMMUNITY 0x005860c0
TESWaterForm* TESWorldSpace::GetLODWaterType()
{
    if (GetParentWorld(TESWorldSpace::PU_LOD))
        return GetParentWorld(TESWorldSpace::PU_LOD)->GetLODWaterType();
    if (lodWater)
        return lodWater;
    return DAT_011ca53c;
}

// Returns true if a is outside 0..5 or if the bit for a is set in the 16-bit mask at offset 0x4E of this.
// @fnv 0x00586340
bool TESWorldSpace::GetParentUseFlag(PARENT_USE_FLAG aiIndex)
{
    if (aiIndex >= 0 && aiIndex < 6)
    {
        unsigned char mask = 1 << aiIndex;
        if (field4E & mask)
            return true;
        return false;
    }
    return true;
}

struct PointerPairData;

// Returns the parent world's result if GetParentWorld(2) is set, otherwise returns this object offset by 0x80.
// @fnv 0x00586400
// src: XBOX_PDB 0x00586400
PointerPairData* TESWorldSpace::GetWorldMapData()
{
    if (GetParentWorld((PARENT_USE_FLAG)2))
        return GetParentWorld((PARENT_USE_FLAG)2)->GetWorldMapData();
    return (PointerPairData*)((char*)this + 0x80);
}

// @fnv 0x00587760
void TESWorldSpace::RemoveCellFromMap(TESObjectCELL* cell)
{

    if (!cell || cell->IsCellInterior())
        return;

    unsigned int entry7;
    unsigned int key = TESWorldSpace::BuildCellKey((short)cell->GetCellGridX(),
                                                   (short)cell->GetCellGridY());

    if (reinterpret_cast<DummyPointerMap*>(cellMap)->GetAt(key, entry7) &&
        cell == reinterpret_cast<TESObjectCELL*>(entry7))
    {
        cellMap->RemoveAt(key);
        reinterpret_cast<CellRuntimeMethods*>(cell)->SetWorldSpace(0);
    }
}

namespace fnv_00587870 {
template <class T> struct WorldReferenceList
{
};
struct OverlapHolder : TESWorldSpace
{
    WorldReferenceList<TESObjectREFR*>* TESWorldSpace_GetOverlappedMultiBoundRefs(TESObjectCELL* apCell);
};
// Looks up the cell's key in map68 and returns the stored TESObjectREFR list, or null if map68 is unset.
// @fnv 0x00587870
// src: COMMUNITY 0x00587870
WorldReferenceList<TESObjectREFR*>* OverlapHolder::TESWorldSpace_GetOverlappedMultiBoundRefs(TESObjectCELL* apCell)
{
    WorldReferenceList<TESObjectREFR*>* preflist = 0;
    unsigned int ikey;
    if (reinterpret_cast<DummyPointerMap*>(m_pFourthTreePointer))
    {
        ikey = TESWorldSpace::BuildCellKey(apCell->GetCellGridX(), apCell->GetCellGridY());
        reinterpret_cast<DummyPointerMap*>(m_pFourthTreePointer)->GetAt(ikey, (unsigned int&)preflist);
    }
    return preflist;
}
}  // namespace fnv_00587870

struct WorldSpaceCellMoveMethods : TESWorldSpace
{
    void TESWorldSpace_AddPersistentReferences();
};
// Gets the interior cell from this worldspace and, if one exists, calls MoveReferencesToWorldCells on it with this worldspace.
// @fnv 0x00588120
// src: COMMUNITY 0x00588120
void WorldSpaceCellMoveMethods::TESWorldSpace_AddPersistentReferences()
{
    TESObjectCELL* cell = ((TESWorldSpace*)this)->GetInteriorCell();
    if (cell)
        ((CellRuntimeMethods*)cell)->MoveReferencesToWorldCells((TESWorldSpace*)this);
}

struct CellProxy
{
    void TESObjectCELL_GetMarkerDataRefs(TESObjectREFR*);
};
// If a1 is non-null and the world space has an interior cell, forwards a1 to that cell's FUN_0054b830.
// @fnv 0x005884e0
// src: COMMUNITY 0x005884e0
void TESWorldSpace::GetCurrentCellMarkerDataRefs(TESObjectREFR* apRef)
{
    TESObjectCELL* cell;
    if (apRef != 0)
    {
        cell = GetInteriorCell();
        if (cell != 0)
        {
            reinterpret_cast<CellProxy*>(cell)->TESObjectCELL_GetMarkerDataRefs(apRef);
        }
    }
}

namespace fnv_00588a90 {
struct FormIDData
{
    int dummy;
};
struct WorldSpaceFileLookupMethods : TESWorldSpace
{
    FormIDData* TESWorldSpace_GetOffsetData(TESFile* file);
};
// @fnv 0x00588a90
// src: COMMUNITY 0x00588a90
FormIDData* WorldSpaceFileLookupMethods::TESWorldSpace_GetOffsetData(TESFile* file)
{
    FormIDData* result = 0;
    TESFile* current = file;
    while (current && current->GetThreadSafeRootFile())
        current = current->GetThreadSafeRootFile();
    if (!((DummyPointerMap*)((char*)this + 0xb0))->GetAt((unsigned int)current, (unsigned int&)result))
        result = 0;
    return result;
}
}  // namespace fnv_00588a90

struct BGSCameraPath;
struct BGSCameraShot;
struct NiFormArray;
struct PerkEntryConditionSet;
struct CameraPathManager
{
    void InitializeCameraPaths();
    static BGSCameraPath* GetTextureResourcePath();
    void AddCameraPath(BGSCameraPath*);
    void UpdateCameraPaths();
    void ClearCameraPaths();
    NiFormArray* GetRootPathArray();
    BGSCameraPath* SetCameraPathEnabled(TESObjectREFR*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char m_kCameraPathArray[24];
    char m_kCameraPathList[16];
};
typedef char _sizecheck_BGSCameraPathManager[sizeof(CameraPathManager) == 40 ? 1 : -1];
struct FUN_0095f530_shell : public CameraPathManager
{
    BGSCameraPath* PlayerCharacter_SetControlsDisabled(TESObjectREFR*, TESObjectREFR*);
};

struct Caller_0095f590
{
    BGSCameraPath* __thiscall PlayerCharacter_SetControlsDisabled_0095f590(unsigned int);
};
// @fnv 0x0095f530
// src: XBOX_PDB 0x0095f530
BGSCameraPath* FUN_0095f530_shell::PlayerCharacter_SetControlsDisabled(TESObjectREFR* apActionRef, TESObjectREFR* apTargetRef)
{
    unsigned char nv;
    if ((unsigned char)apActionRef)
    {
        nv = *(unsigned char*)((char*)this + 0x680) | (unsigned int)apTargetRef;
    }
    else
    {
        nv = (unsigned char)~(unsigned char)apTargetRef;
        nv = *(unsigned char*)((char*)this + 0x680) & nv;
    }
    return ((Caller_0095f590*)this)->PlayerCharacter_SetControlsDisabled_0095f590(nv);
}

namespace worldspace_cell_map {
extern float _DAT_01015f5c;
}

// @fnv 0x00582c20
TESWorldSpace::TESWorldSpace() : m_kSecondTreeComponent(0x25), m_kFourthTreeComponent(0), OffsetDataMap(0x25)
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x41));
    m_pThirdTreePointer = 0;
    pCellNavMeshInfoMap = new NiTPointerMap<unsigned int, TESObjectREFR*>(0x25);
    m_pFourthTreePointer = 0;
    m_pCell = 0;
    m_kFirstPoint.y = 3.4028234663852886e+38f;
    m_kFirstPoint.x = 3.4028234663852886e+38f;
    m_kEndPoint.y = worldspace_cell_map::_DAT_01015f5c;
    m_kEndPoint.x = worldspace_cell_map::_DAT_01015f5c;
    InitializeData_00583070();
}

namespace fnv_005857b0 {
struct FileH
{
    int m_uiData;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;
};
struct WorldSpaceFileMethods : TESWorldSpace
{
    FileH* TESWorldSpace_GetOffsetData(int);
};
struct WorldSpaceOffsetMethods : WorldSpaceFileMethods
{
    int TESWorldSpace_GetIndexForCellCoord(int, int, int);
    void TESWorldSpace_AdjustCellOffsets(int a, int b);
};
// @fnv 0x005857b0
// src: COMMUNITY 0x005857b0
void WorldSpaceOffsetMethods::TESWorldSpace_AdjustCellOffsets(int a, int aiDelta)
{
    FileH* p = TESWorldSpace_GetOffsetData(a);
    if (p && p->m_uiData && aiDelta)
    {
        int i2 = (int)p->m_fVectorY >> 12;
        int i3 = (int)p->m_fVectorZ >> 12;
        int i1 = (int)p->m_fScalarPart >> 12;
        int i0 = (int)p->m_fVectorX >> 12;
        for (int i = i2; i <= i1; i++)
        {
            for (int j = i3; j <= i0; j++)
            {
                int k = TESWorldSpace_GetIndexForCellCoord(a, i, j);
                if (k >= 0 && ((int*)p->m_uiData)[k])
                    ((int*)p->m_uiData)[k] += aiDelta;
            }
        }
    }
}
}  // namespace fnv_005857b0

struct MapX
{
    void* GetFirstPos();
};
struct List_009e03e0
{
    ~List_009e03e0();
    void RemoveAll();
};
struct MyMap
{
    void RemoveAll();
    virtual ~MyMap();
};
struct WorldEntryMap
{
    void GetNext(void*&, unsigned int&, void*&);
};

// Iterates the map at this+0x68, deletes each non-null value list, then clears and deletes the map and nulls the pointer.
// @fnv 0x00587bb0
void TESWorldSpace::DestroyMapEntries()
{
    if (*(MapX**)((char*)this + 0x68))
    {
        void* pos = ((MapX*)*(MapX**)((char*)this + 0x68))->GetFirstPos();
        while (pos)
        {
            void* key = 0;
            void* val = 0;
            ((WorldEntryMap*)*(MapX**)((char*)this + 0x68))->GetNext(pos, (unsigned int&)key, val);
            if (val)
            {
                ((List_009e03e0*)val)->RemoveAll();
                delete (List_009e03e0*)val;
            }
        }
        ((MyMap*)*(MapX**)((char*)this + 0x68))->RemoveAll();
        delete (MyMap*)*(MapX**)((char*)this + 0x68);
        *(MapX**)((char*)this + 0x68) = 0;
    }
}

namespace fnv_00588c80 {
struct MapX
{
    void* GetFirstPos();
};
struct MyMap
{
    void RemoveAll();
};
// Unit-local view of NiTMap for 0x00588c80 (namespace fnv_00588c80): built on the shared NiTMap, that code does not compile or does not match.
struct NiTMap_00588c80
{
    void GetNext(void*&, unsigned int&, void*&);
};
void __cdecl _Deallocate(void*);

// Iterates the map at offset 0xb0, deallocating each entry's referenced object and the entry itself, then clears the map.
}  // namespace fnv_00588c80

// @fnv 0x00588c80
// src: COMMUNITY 0x00588c80
void TESWorldSpace::FreeOffsetMap()
{

    void* iterA = ((fnv_00588c80::MapX*)((char*)this + 0xb0))->GetFirstPos();
    while (iterA)
    {
        void* preflist9 = 0;
        unsigned int iignore5 = 0;
        ((fnv_00588c80::NiTMap_00588c80*)((char*)this + 0xb0))->GetNext(iterA, iignore5, preflist9);
        void* ref = *(void**)preflist9;
        fnv_00588c80::_Deallocate(ref);
        void* p2 = preflist9;
        fnv_00588c80::_Deallocate(p2);
    }
    ((fnv_00588c80::MyMap*)((char*)this + 0xb0))->RemoveAll();
}

namespace fnv_00583070 {

struct FormProxy : TESForm
{
    bool IsReservedFormID();
};

struct WorldSpaceVirtual
{
    virtual void Call();
};

}  // namespace fnv_00583070

// @fnv 0x00583070
// src: XBOX_PDB 0x00583070
void TESWorldSpace::InitializeData_00583070()
{

    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x70) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xd0) = 0;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x4c) = 0;
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x4e) = 0;

    if (!reinterpret_cast<fnv_00583070::FormProxy*>(this)->IsReservedFormID())
        SetFlagBit0(true);

    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x40) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x44) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x74) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x78) = 0;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x7c) = 0.0f;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x90) = 1.0f;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x94) = 0.0f;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x98) = 0.0f;

    ClearWorldSpaceReferences();

    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x9c) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x48) = 0;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xc8) = DAT_01031920;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc) = 0.0f;

    reinterpret_cast<GO*>(reinterpret_cast<char*>(this) + 0x6c)->operator=(0);

    reinterpret_cast<fnv_00583070::WorldSpaceVirtual*>(reinterpret_cast<char*>(this) + 0xd4)->Call();
    reinterpret_cast<fnv_00583070::WorldSpaceVirtual*>(reinterpret_cast<char*>(this) + 0xe0)->Call();
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

struct FUN_00c5a9d0 : A51BF0Base
{
    unsigned char padding[0x78];
    FUN_00c5a9d0();
};

extern unsigned int _data_011c16bc;

struct WorldSpaceObjectMethods : TESWorldSpace
{
    unsigned int GetOrCreateObject();
};

// Returns the stored object pointer, allocating and storing a new FUN_00c5a9d0 first if it is null.
// @fnv 0x005831d0
unsigned int WorldSpaceObjectMethods::GetOrCreateObject()
{
    if (!static_cast<unsigned int>((*reinterpret_cast<GO*>(&m_kFourthTreeComponent))))
    {
        (*reinterpret_cast<GO*>(&m_kFourthTreeComponent)).operator=(new FUN_00c5a9d0());
    }

    return static_cast<unsigned int>((*reinterpret_cast<GO*>(&m_kFourthTreeComponent)));
}

namespace fnv_00588150 {

struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering(void);
};

extern ATM g_011ca60c;

struct WorldReferenceList
{
    bool _ref_008256d0();
    TESObjectREFR** _ref_006815c0();
    WorldReferenceList* _ref_00726070();
};

// Looks up the cell's reference list by key and adds each reference to the cell, filtering the second list by cull result and a cell check.
}  // namespace fnv_00588150

// @fnv 0x00588150
void TESWorldSpace::AddCellReferences(TESObjectCELL* cell)
{

    fnv_00588150::WorldReferenceList* pCurrentElementNext;
    unsigned int ikey;

    if (cell != 0)
    {
        fnv_00588150::g_011ca60c.QueryPerformanceCounter(0);
        ikey = TESWorldSpace::BuildCellKey(cell->GetCellGridX(),
                                           cell->GetCellGridY());

        {
            TESObjectREFR* pref;
            pCurrentElementNext = 0;
            reinterpret_cast<DummyPointerMap*>(reinterpret_cast<char*>(this) + 0x50)
                ->GetAt(ikey, reinterpret_cast<unsigned int&>(pCurrentElementNext));

            while (pCurrentElementNext != 0 && !pCurrentElementNext->_ref_008256d0())
            {
                pref = *pCurrentElementNext->_ref_006815c0();
                cell->AddReference(pref, false);
                pCurrentElementNext = pCurrentElementNext->_ref_00726070();
            }
        }

        {
            TESObjectREFR* pref;
            pCurrentElementNext = reinterpret_cast<fnv_00588150::WorldReferenceList*>(reinterpret_cast<char*>(this) + 0x60);

            while (pCurrentElementNext != 0 && !pCurrentElementNext->_ref_008256d0())
            {
                pref = *pCurrentElementNext->_ref_006815c0();

                if (reinterpret_cast<const BSOcclusionPlane*>(pref)->GetCullResult() != reinterpret_cast<int>(cell))
                {
                    if (reinterpret_cast<CellRuntimeMethods*>(cell)->FUN_00550200(
                            ((TESObjectREFR*(__thiscall*)(TESObjectREFR*))(*(void***)pref)[125])(pref)))
                    {
                        cell->AddReference(pref, false);
                    }
                }

                pCurrentElementNext = pCurrentElementNext->_ref_00726070();
            }
        }

        fnv_00588150::g_011ca60c.WaitForTasksDuringRendering();
    }
}

namespace fnv_00588560 {
// Unit-local view of NiTMap for 0x00588560 (namespace fnv_00588560): built on the shared NiTMap, that code does not compile or does not match.
class NiTMap_00588560
{
  public:
    void GetNext(void*& position, unsigned int& key, void*& value);
};

class MapX : public NiTMap_00588560
{
  public:
    void* GetFirstPos();
};

int _stricmp(const char* string1, const char* string2);

class FUN_00588560_entry
{
  public:
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual void f68() = 0;
    virtual void f69() = 0;
    virtual void f70() = 0;
    virtual void f71() = 0;
    virtual void f72() = 0;
    virtual void f73() = 0;
    virtual void f74() = 0;
    virtual void f75() = 0;
    virtual const char* f76() = 0;
};

struct WorldSpaceEntryMethods : TESWorldSpace
{
    void* FindEntryByName(const char* name);
};

// Iterates the map's entries and returns the first whose f76() string matches name case-insensitively, or null.
// @fnv 0x00588560
void* WorldSpaceEntryMethods::FindEntryByName(const char* name)
{
    void* result2 = 0;
    void* position;

    if (name)
    {
        position = reinterpret_cast<MapX*>(cellMap)->GetFirstPos();

        while (position && !result2)
        {
            void* value3 = 0;
            unsigned int key;
            reinterpret_cast<MapX*>(cellMap)->GetNext(position, key, value3);

            if (value3)
            {
                if (_stricmp(static_cast<FUN_00588560_entry*>(value3)->f76(), name) == 0)
                {
                    result2 = value3;
                }
            }
        }
    }

    return result2;
}
}  // namespace fnv_00588560

struct HelperAt6c
{
    void FUN_0066b0d0(int mode);
};
struct RefAt48
{
    void* FUN_0040f2a0(int deletionFlags);
};
// @fnv 0x00583180
// src: COMMUNITY 0x00583180
void TESWorldSpace::ClearData_00583180()
{
    reinterpret_cast<HelperAt6c*>(&m_kFourthTreeComponent)->FUN_0066b0d0(0);
    RefAt48* node = reinterpret_cast<RefAt48*>(data);
    RefAt48* doomed = node;
    doomed ? doomed->FUN_0040f2a0(1) : 0;
    data = 0;
}

struct FUN_00583270_sub_cls
{
    void* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(int);
};
struct FUN_00583270_mid_cls
{
    int ShadowSceneNode_QPortalGraph();
};
struct FUN_00583270_tgt_cls
{
    void FUN_00b5ddf0(int);
};
int __fastcall FUN_00726070_cb(void* p);
void* __cdecl FUN_00450b80_cb(int v);

struct WorldSpaceNodeMethods : TESWorldSpace
{
    void TESWorldSpace_ClearPortalGraph();
};

// @fnv 0x00583270
// src: XBOX_PDB 0x00583270
void WorldSpaceNodeMethods::TESWorldSpace_ClearPortalGraph()
{
    if ((*reinterpret_cast<FUN_00583270_sub_cls*>(&m_kFourthTreeComponent)).Modelloader_GetReferencedThis())
    {
        if (FUN_00726070_cb((*reinterpret_cast<FUN_00583270_sub_cls*>(&m_kFourthTreeComponent)).Modelloader_GetReferencedThis()) == 1)
        {
            if (reinterpret_cast<FUN_00583270_mid_cls*>(FUN_00450b80_cb(0))->ShadowSceneNode_QPortalGraph() == (int)(*reinterpret_cast<FUN_00583270_sub_cls*>(&m_kFourthTreeComponent)).Modelloader_GetReferencedThis())
            {
                reinterpret_cast<FUN_00583270_tgt_cls*>(FUN_00450b80_cb(0))->FUN_00b5ddf0(0);
            }
            (*reinterpret_cast<FUN_00583270_sub_cls*>(&m_kFourthTreeComponent)).FUN_0066b0d0(0);
        }
    }
}

// These legacy calls retain the original full-width result and form-skip entry point.
unsigned int __fastcall GetCurrentFormType(TESFile*);
void __fastcall SkipCurrentForm(TESFile*);

struct TypeGroupInfo
{
    unsigned int type;
    unsigned int unk04;
    unsigned int label;
    unsigned int groupType;
};
struct Offsets
{
    unsigned int* offsets;
    unsigned int unk04, unk08, unk0c, unk10;
    unsigned int base;
};
struct CellCoordinates
{
    int x, y, flags;
    void EXTERIOR_DATA_EXTERIOR_DATA();
    void TwoValues_Endian();
};
int GetCellCoordKey(int, int);
int TESObjectCELL_CalcExtGroupSubBlockKey(int, int);
extern unsigned int kGroupFormType;
extern unsigned int DAT_011872b4;
extern unsigned int DAT_01187338;
struct WorldSpaceCellReadMethods : TESWorldSpace
{
    Offsets* TESWorldSpace_GetOffsetData(TESFile*);
    int TESWorldSpace_GetIndexForCellCoord(TESFile*, int, int);
    bool SeekToCellInWorld(TESFile*, int, int);
};
// Seeks the file to the world block/sub-block for cell (x,y), scanning group headers and cell chunks until the matching cell is found.
// @fnv 0x005854f0
bool WorldSpaceCellReadMethods::SeekToCellInWorld(TESFile* file, int x, int y)
{
    if (file && file->IsMasterFile())
    {
        Offsets* offsets = TESWorldSpace_GetOffsetData(file);
        if (offsets && offsets->offsets)
        {
            int index = TESWorldSpace_GetIndexForCellCoord(file, x, y);
            if (index != -1)
            {
                unsigned int offset = offsets->offsets[index];
                if (offset)
                {
                    file->SetOffset(offset + offsets->base);
                    return true;
                }
            }
            return false;
        }
    }
    int subBlock;
    bool found = false;
    int block = GetCellCoordKey(x, y);
    subBlock = TESObjectCELL_CalcExtGroupSubBlockKey(x, y);
    if (file && file->FindForm(reinterpret_cast<TESForm*>(this)))
    {
        file->NextForm_00472150(true);
        bool done = false;
        TypeGroupInfo* header = reinterpret_cast<TypeGroupInfo*>(file->GetRecordHeader());
        while (header && !done)
        {
            if (header->type == kGroupFormType)
            {
                bool skip = true;
                done = true;
                switch (header->groupType)
                {
                case 1:
                    skip = false;
                case 4:
                    if (block == header->label)
                        skip = false;
                case 5:
                    if (subBlock == header->label)
                        skip = false;
                case 6:
                case 8:
                case 9:
                    done = false;
                }
                if (!done)
                {
                    if (skip)
                        file->IsGroupOpen();
                    else
                        file->NextForm_00472150(true);
                }
            }
            else if (header->type == DAT_011872b4)
            {
                CellCoordinates cellCoords;
                cellCoords.EXTERIOR_DATA_EXTERIOR_DATA();
                memset(&cellCoords, 0, 12);
                if (header->label & 0x400)
                    cellCoords.x = 0x7fffffff;
                else
                {
                    bool read = false;
                    int chunk = file->TESFile_GetTESChunk();
                    while (chunk && !read)
                    {
                        if (chunk == 0x434c4358)
                        {
                            file->FUN_00472890(&cellCoords, 12);
                            if (file->IsEndianConversionRequired())
                                cellCoords.TwoValues_Endian();
                            read = true;
                        }
                        if (file->NextChunk())
                            chunk = file->TESFile_GetTESChunk();
                        else
                            chunk = 0;
                    }
                }
                if (cellCoords.x == x && cellCoords.y == y)
                {
                    found = true;
                    done = true;
                    SkipCurrentForm(file);
                }
                else
                    file->NextForm_00472150(true);
            }
            else if (header->type == DAT_01187338)
            {
                file->NextForm_00472150(true);
            }
            else
                done = true;
        }
    }
    return found;
}

// The shared worldspace header does not declare the cell-map ownership query.
bool __fastcall IsWorldCellMapShared(TESWorldSpace*);

struct FUN_005877e0_Val5
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int v4(int);
};

// If Probe fails, iterates cellMap calling v4(1) on each entry, then always calls Done on cellMap.
// @fnv 0x005877e0
// src: COMMUNITY 0x005877e0
void TESWorldSpace::ClearCellMap()
{
    if (!IsWorldCellMapShared(this))
    {
        void* it = cellMap->GetFirstPos();
        while (it != 0)
        {
            FUN_005877e0_Val5* item;
            unsigned int key;
            FUN_005877e0_Val5* out4 = 0;
            cellMap->GetNext(it, key, reinterpret_cast<TESObjectREFR*&>(out4));
            FUN_005877e0_Val5* tmp4 = out4;
            item = tmp4;
            (item != 0) ? item->v4(1) : 0;
        }
    }
    cellMap->RemoveAll();
}

extern float const DAT_01016248;

float __fastcall GetWorldScale(void* apWorld);

// Local method adapter for world transforms, absent from the shared header.
struct WorldPointTransformMethods : TESWorldSpace
{
    float GetOffsetX();
    float GetOffsetY();
    void TransformWorldPoint(NiPoint3*, bool);
};

// @fnv 0x00588e40
void WorldPointTransformMethods::TransformWorldPoint(NiPoint3* apPoint, bool abInverse)
{
    if (abInverse)
    {
        apPoint->x -= GetOffsetX();
        apPoint->y -= GetOffsetY();
    }
    if (GetWorldScale(this) != 1.0 && GetWorldScale(this) != 0.0)
    {
        NiPoint3 kCenter4;
        kCenter4.x = m_kFirstPoint.x + m_kEndPoint.x;
        kCenter4.y = m_kFirstPoint.y + m_kEndPoint.y;
        kCenter4.z = 0.0f;
        kCenter4 *= DAT_01016248;
        NiPoint3 kDelta = *apPoint - kCenter4;
        kDelta *= abInverse ? 1.0 / GetWorldScale(this) : GetWorldScale(this);
        *apPoint = kCenter4 + kDelta;
    }
    if (!abInverse)
    {
        apPoint->x += GetOffsetX();
        apPoint->y += GetOffsetY();
    }
}

struct WorldTerrain
{
    void BGSTerrainManager_DestroyNodeAndChildren();
    ~WorldTerrain();
};
struct WorldLandMap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~WorldLandMap();
};
extern TESWorldSpace* DAT_011c3f44;
// Clears the global worldspace pointer if it is this object, then releases terrain, cell and land maps and other owned resources.
// @fnv 0x00582e30
TESWorldSpace::~TESWorldSpace()
{
    if (DAT_011c3f44 == this)
        DAT_011c3f44 = 0;
    ClearAllLists();
    DestroyMapEntries();
    if (terrain)
    {
        reinterpret_cast<WorldTerrain*>(terrain)->BGSTerrainManager_DestroyNodeAndChildren();
        delete reinterpret_cast<WorldTerrain*>(terrain);
        terrain = 0;
    }
    ClearData_00583180();
    ClearCellMap();
    delete cellMap;
    cellMap = 0;
    delete reinterpret_cast<WorldLandMap*>(m_pCell);
    m_pCell = 0;
    FreeOffsetMap();
}

struct BoundsPoint
{
    float x, y;
    BoundsPoint();
};
struct BoundsOffsetData
{
    unsigned int cellOffsets;
    BoundsPoint minimum, maximum;
    unsigned int fileOffset;
};
void BSEndian(float*, EndianSizeTag<4>);
float BSMIN(float, float);
float BSMAX_00404010(float, float);
// Local method adapter: the shared header does not yet declare FUN_00583360.
struct WorldSpaceBoundsMethods : TESWorldSpace
{
    bool TESWorldSpace_LoadPartial(TESFile*);
};
// @fnv 0x00583360
// src: XBOX_PDB 0x00583360
bool WorldSpaceBoundsMethods::TESWorldSpace_LoadPartial(TESFile* file)
{
    unsigned int type = 0;
    while (type = file->TESFile_GetTESChunk())
    {
        switch (type)
        {
        case 0x304d414e: {
            ::BoundsPoint minimum;
            file->FUN_00472890(&minimum, 8);
            if (file->IsEndianConversionRequired())
            {
                BSEndian(&minimum.x, EndianSizeTag<4>());
                BSEndian(&minimum.y, EndianSizeTag<4>());
            }
            m_kFirstPoint.x = BSMIN(m_kFirstPoint.x, minimum.x);
            m_kFirstPoint.y = BSMIN(m_kFirstPoint.y, minimum.y);
            if (file->IsMasterFile())
            {
                BoundsOffsetData* data = reinterpret_cast<BoundsOffsetData*>(GetOrCreateCellOffsetData(file));
                data->minimum = minimum;
            }
            break;
        }
        case 0x394d414e: {
            ::BoundsPoint maximum;
            file->FUN_00472890(&maximum, 8);
            if (file->IsEndianConversionRequired())
            {
                BSEndian(&maximum.x, EndianSizeTag<4>());
                BSEndian(&maximum.y, EndianSizeTag<4>());
            }
            m_kEndPoint.x = BSMAX_00404010(m_kEndPoint.x, maximum.x);
            m_kEndPoint.y = BSMAX_00404010(m_kEndPoint.y, maximum.y);
            if (file->IsMasterFile())
            {
                BoundsOffsetData* data = reinterpret_cast<BoundsOffsetData*>(GetOrCreateCellOffsetData(file));
                data->maximum = maximum;
            }
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct SaveForm
{
    unsigned int GetFormID();
    void Save();
};
struct SaveFullName
{
    unsigned int unk00, unk04, unk08;
    void Save_00487010();
};
struct SaveTexture
{
    unsigned int unk00, unk04, unk08;
    void TESTexture_Save(unsigned int);
};
struct SaveMap
{
    unsigned int unk00, unk04, unk08, unk0c;
    void SwapIntegerAndShortByteOrder();
};
struct SaveOffset
{
    unsigned int unk00, unk04, unk08;
    void TESRegionSound_Endian();
};
struct SaveGameString
{
    unsigned int unk00, unk04, unk08;
    int FUN_0048cee0();
    int* TESModel_GetModel();
};
struct SavePair
{
    float land, water;
    void TwoValues_Endian();
};
bool TESForm_QEndianSwapOnSave();
void TESForm_AddChunk_00485910(unsigned int, unsigned int);
void _FUN_00485910(unsigned int, float);
void TESForm_AddChunk_00485950(unsigned int, unsigned int);
void AppendChunk(unsigned int, void*, unsigned int);
void TESForm_AddChunk_3(unsigned int, unsigned char);
void TESForm_AddChunkArray_00485710(unsigned int, unsigned int*, unsigned int);
void TESForm_AddChunkArray(unsigned int, void*, unsigned int);
// Saving helpers missing from the shared header; all fields come from TESWorldSpace.
struct WorldSpaceSaveMethods : TESWorldSpace
{
    ::SaveForm* TESWorldSpace_GetWaterType();
    float FUN_0045cd80();
    ::SaveForm* FUN_008041a0();
    ::SaveForm* CombatController_GetCombatState();
    void TESWorldSpace_Save();
};
// Writes the world record's encounter zone, parent, canopy, water noise, heights, map, offset, bounds and flags to the save stream.
// @fnv 0x00584170
// src: XBOX_PDB 0x00584170
void WorldSpaceSaveMethods::TESWorldSpace_Save()
{
    BeginFormRecord();
    TESFullName::Save_00487010();
    unsigned int formID = 0;
    if (reinterpret_cast<::SaveForm*>(fieldD0))
    {
        formID = reinterpret_cast<::SaveForm*>(fieldD0)->GetFormID();
        TESForm_AddChunk_00485910(0x4e5a4558, formID);
    }
    if (parent)
    {
        formID = parent->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e57, formID);
        TESForm_AddChunk_00485950(0x4d414e50, field4E);
    }
    if (!GetParentUseFlag(static_cast<PARENT_USE_FLAG>(4)) && GetClimate())
    {
        formID = reinterpret_cast<::SaveForm*>(GetClimate())->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e43, formID);
    }
    if (!GetParentUseFlag(static_cast<PARENT_USE_FLAG>(3)) && TESWorldSpace_GetWaterType())
    {
        formID = TESWorldSpace_GetWaterType()->GetFormID();
        TESForm_AddChunk_00485910(0x324d414e, formID);
    }
    if (!GetParentUseFlag(static_cast<PARENT_USE_FLAG>(1)) && GetLODWaterType())
    {
        formID = reinterpret_cast<::SaveForm*>(GetLODWaterType())->GetFormID();
        TESForm_AddChunk_00485910(0x334d414e, formID);
        _FUN_00485910(0x344d414e, FUN_0045cd80());
    }
    if (!GetParentUseFlag(static_cast<PARENT_USE_FLAG>(0)))
    {
        SavePair pairHeights;
        pairHeights.land = fC8;
        pairHeights.water = fCC;
        if (TESForm_QEndianSwapOnSave())
            pairHeights.TwoValues_Endian();
        AppendChunk(0x4d414e44, &pairHeights, 8);
        if (TESForm_QEndianSwapOnSave())
            pairHeights.TwoValues_Endian();
    }
    if (!GetParentUseFlag(static_cast<PARENT_USE_FLAG>(2)))
    {
        TESTexture::Save(0x4e4f4349);
        if (TESForm_QEndianSwapOnSave())
            (*reinterpret_cast<SaveMap*>(unk80)).SwapIntegerAndShortByteOrder();
        AppendChunk(0x4d414e4d, &(*reinterpret_cast<SaveMap*>(unk80)), 16);
        if (TESForm_QEndianSwapOnSave())
            (*reinterpret_cast<SaveMap*>(unk80)).SwapIntegerAndShortByteOrder();
    }
    if (TESForm_QEndianSwapOnSave())
        (*reinterpret_cast<SaveOffset*>(unk80 + 16)).TESRegionSound_Endian();
    AppendChunk(0x4d414e4f, &(*reinterpret_cast<SaveOffset*>(unk80 + 16)), 12);
    if (TESForm_QEndianSwapOnSave())
        (*reinterpret_cast<SaveOffset*>(unk80 + 16)).TESRegionSound_Endian();
    if (!GetParentUseFlag(static_cast<PARENT_USE_FLAG>(5)) && FUN_008041a0())
    {
        formID = FUN_008041a0()->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e49, formID);
    }
    TESForm_AddChunk_3(0x41544144, flags4C);
    TESForm_AddChunkArray_00485710(0x304d414e, &(*reinterpret_cast<unsigned int*>(&m_kFirstPoint.x)), 2);
    TESForm_AddChunkArray_00485710(0x394d414e, &(*reinterpret_cast<unsigned int*>(&m_kEndPoint.x)), 2);
    if (CombatController_GetCombatState())
    {
        formID = CombatController_GetCombatState()->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e5a, formID);
    }
    TESForm_AddChunkArray(0x4d414e4e, (*reinterpret_cast<SaveGameString*>(&CanopyShadowTexture)).TESModel_GetModel(), (*reinterpret_cast<SaveGameString*>(&CanopyShadowTexture)).FUN_0048cee0() + 1);
    TESForm_AddChunkArray(0x4d414e58, (*reinterpret_cast<SaveGameString*>(&m_kLeafShadowTexture)).TESModel_GetModel(), (*reinterpret_cast<SaveGameString*>(&m_kLeafShadowTexture)).FUN_0048cee0() + 1);
    if (reinterpret_cast<::SaveForm*>(data))
        reinterpret_cast<::SaveForm*>(data)->Save();
    FinishFormRecord();
}

extern "C" void* _FNV_DynamicCast(void*, int, const void*, const void*, int);
extern char _FNV_RTTI_TESForm;
extern char _FNV_RTTI_TESWorldSpace;
void* __cdecl memcpy(void*, const void*, unsigned int);
struct FUN_0058efd0
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    FUN_0058efd0();
    ~FUN_0058efd0();
    void CopyFrom(FUN_0058efd0*);
};
struct CopyArray
{
    virtual void Destroy();
    virtual void Clear();
    virtual void CopyFrom(const CopyArray&);
    unsigned int count, capacity;
};
// Copy helpers missing from the shared header; no local worldspace layout.
struct WorldSpaceCopyMethods : TESWorldSpace
{
    void TESWorldSpace_Copy(TESForm*);
    void CopyBase(TESForm*);
    TESClimate* GetWorldClimate();
    void* GetImageSpace();
    TESWaterForm* GetWater();
    TESWaterForm* GetLODWater();
    void SetWater(TESWaterForm*);
    void SetLODWater(TESWaterForm*);
    float GetHeight();
    void SetHeight(float);
    int GetMusic();
    void SetMusic(int);
};
// @fnv 0x00584fa0
// src: XBOX_PDB 0x00584fa0
void WorldSpaceCopyMethods::TESWorldSpace_Copy(TESForm* form)
{
    WorldSpaceCopyMethods* source = (WorldSpaceCopyMethods*)_FNV_DynamicCast(form, 0, &_FNV_RTTI_TESForm, &_FNV_RTTI_TESWorldSpace, 0);
    if (!source)
        return;
    CopyBase((TESForm*)source);
    flags4C = source->flags4C;
    field4E = source->field4E;
    parent = source->parent;
    fieldD0 = source->fieldD0;
    climate = source->GetWorldClimate();
    imageSpace = source->GetImageSpace();
    if (reinterpret_cast<FUN_0058efd0*&>(source->data))
    {
        if (!reinterpret_cast<FUN_0058efd0*&>(data))
            reinterpret_cast<FUN_0058efd0*&>(data) = new FUN_0058efd0;
        reinterpret_cast<FUN_0058efd0*&>(data)->CopyFrom(reinterpret_cast<FUN_0058efd0*&>(source->data));
    }
    else if (reinterpret_cast<FUN_0058efd0*&>(data))
    {
        delete reinterpret_cast<FUN_0058efd0*&>(data);
        reinterpret_cast<FUN_0058efd0*&>(data) = 0;
    }
    SetWater(source->GetWater());
    SetLODWater(source->GetLODWater());
    SetHeight(source->GetHeight());
    fC8 = source->fC8;
    fCC = source->fCC;
    memcpy(unk80, source->unk80, 16);
    memcpy(unk80 + 16, source->unk80 + 16, 12);
    SetMusic(source->GetMusic());
    cellMap->RemoveAll();
    void* position = source->cellMap->GetFirstPos();
    while (position)
    {
        unsigned int value = 0;
        unsigned int key;
        source->cellMap->GetNext(position, key, reinterpret_cast<TESObjectREFR*&>(value));
        cellMap->SetAt(key, reinterpret_cast<TESObjectREFR*>(value));
    }
    reinterpret_cast<CopyArray*>(&CanopyShadowTexture)->CopyFrom(*reinterpret_cast<CopyArray*>(&source->CanopyShadowTexture));
    reinterpret_cast<CopyArray*>(&m_kLeafShadowTexture)->CopyFrom(*reinterpret_cast<CopyArray*>(&source->m_kLeafShadowTexture));
}

struct CellOffsetData
{
    unsigned int* offsets;
    float minX, minY, maxX, maxY;
    unsigned int baseOffset;
};
void* FormHeap_Allocate(unsigned int);
void FormHeapFreeAndLog_00401030(void*);
void ourMemset(void*, int, unsigned int);
int BSstricmp(const char*, const char*);
struct WorldSpaceEditorLookupMethods : TESWorldSpace
{
    unsigned int GetSourceFileCount();
    TESFile* FUN_00484e60(unsigned int);
    CellOffsetData* TESWorldSpace_GetOffsetData(TESFile*);
    int TESWorldSpace_GetIndexForCellCoord(TESFile*, int, int);
    bool FindCellByEditorID(const char*, int*, int*);
};
// Scans every loaded worldspace cell grid for a cell whose EDID chunk matches editorID, writing its grid coordinates to outX/outY and returning true when found.
// @fnv 0x00585940
bool WorldSpaceEditorLookupMethods::FindCellByEditorID(const char* editorID, int* outX, int* outY)
{
    unsigned int count = GetSourceFileCount();
    for (unsigned int i = 0; i < count; i++)
    {
        TESFile* data = FUN_00484e60(i)->GetParentTESFile();
        CellOffsetData* file = TESWorldSpace_GetOffsetData(data);
        if (file)
        {
            int minX = ((int)file->minX) >> 12;
            int maxY = ((int)file->minY) >> 12;
            int minY = ((int)file->maxX) >> 12;
            int maxX = ((int)file->maxY) >> 12;
            for (int x = minX; x <= minY; x++)
            {
                for (int y = maxY; y <= maxX; y++)
                {
                    int index = TESWorldSpace_GetIndexForCellCoord(data, x, y);
                    if (index != -1)
                    {
                        unsigned int offset = file->offsets[index];
                        if (offset)
                        {
                            data->SetOffset(offset + file->baseOffset);
                            if (GetCurrentFormType(data) == 0x39)
                            {
                                unsigned int chunkID = data->TESFile_GetTESChunk();
                                if (chunkID == 0x44494445)
                                {
                                    unsigned int uiBufferSize = data->GetField25C() + 1;
                                    char* size = (char*)FormHeap_Allocate(uiBufferSize);
                                    ourMemset(size, 0, uiBufferSize);
                                    data->FUN_00472890(size, 0);
                                    if (!BSstricmp(size, editorID))
                                    {
                                        *outX = x;
                                        *outY = y;
                                        FormHeapFreeAndLog_00401030(size);
                                        return true;
                                    }
                                    FormHeapFreeAndLog_00401030(size);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

extern const char DAT_01031f18[];
extern const char DAT_01031ec0[];
struct CellOperations : CellRuntimeMethods
{
    bool GetHasTempData();
    void TESObjectCELL_SetInterior(bool);
    void SetExteriorCellCoordinates(int, int);
    bool TESObjectCELL_LoadTempDataFromFile(TESFile*);
    void TESObjectCELL_SetHasTempData(bool);
};
struct SaveLoadOperations
{
    void* RemoveCommand(unsigned int, int, int);
    bool FUN_0047c850();
    void FUN_004534f0(bool);
};
extern SaveLoadOperations* DAT_011de45c;
extern TESWorldSpace* DAT_011c3f34;
bool __cdecl FUN_004601d0(CellOperations*, TESFile*);
struct WorldSpaceCellLoadMethods : TESWorldSpace
{
    unsigned int GetSourceFileCount();
    TESFile* FUN_00484e60(unsigned int);
    bool SeekToCellInWorld(TESFile*, int, int);
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    CellOperations* TESWorldSpace_LoadCell(int x, int y);
};
// @fnv 0x00585b30
// src: XBOX_PDB 0x00585b30
CellOperations* WorldSpaceCellLoadMethods::TESWorldSpace_LoadCell(int x, int y)
{
    AutoMemHelper j(26, true, DAT_01031f18, 1942);
    bool i = true;
    CellOperations* p = reinterpret_cast<CellOperations*>(GetCellAtGridPosition(x, y));
    DAT_011c3f34 = reinterpret_cast<TESWorldSpace*>(this);
    if (!p || !p->GetHasTempData())
    {
        unsigned int fileCount = GetSourceFileCount();
        for (unsigned int fileIndex = 0; fileIndex < fileCount; ++fileIndex)
        {
            TESFile* file = FUN_00484e60(fileIndex)->GetParentTESFile();
            bool loaded = file && SeekToCellInWorld(file, x, y);
            if (loaded)
            {
                if (!p)
                {
                    p = reinterpret_cast<CellOperations*>(new TESObjectCELL);
                    p->TESObjectCELL_SetInterior(false);
                    p->ResetCellData();
                    p->SetExteriorCellCoordinates(x, y);
                    AddCell(reinterpret_cast<TESObjectCELL*>(p));
                    void* worldData = 0;
                    worldData = DAT_011de45c->RemoveCommand(GetHavokWorldObjectCountInSceneGraph_0084e3a0(), x, y);
                    if (worldData)
                        ((void(__thiscall*)(TESObjectCELL*, void*, bool))(*(void***)p)[74])(p, worldData, true);
                    i = FUN_004601d0(p, file);
                }
                else if (!(reinterpret_cast<TypeGroupInfo*>(file->GetRecordHeader())->label & 0x4000))
                {
                    FUN_004601d0(p, file);
                }
                if (!p->TESObjectCELL_LoadTempDataFromFile(file))
                    i = false;
            }
        }
        if (p)
        {
            p->TESObjectCELL_SetHasTempData(true);
            bool loading = DAT_011de45c->FUN_0047c850();
            DAT_011de45c->FUN_004534f0(!loading);
            ((void(__thiscall*)(TESObjectCELL*))(*(void***)p)[34])(p);
            DAT_011de45c->FUN_004534f0(loading);
            AddCellReferences(reinterpret_cast<TESObjectCELL*>(p));
        }
    }
    if (!i)
        Warning(DAT_01031ec0, x, y, GetName(), GetHavokWorldObjectCountInSceneGraph_0084e3a0());
    return p;
}

struct WorldSpaceParentFileMethods : public TESWorldSpace
{
    bool FindParentFile(int a1, int a2, unsigned int* a3, unsigned int* a4);
    int GetFileCount();
    TESFile* GetFileForm(int aIndex);
};

struct WorldSpaceParentReadMethods : TESWorldSpace
{
    bool ReadWorldData(TESFile* apFile, int a1, int a2);
};

bool __cdecl LoadedCheck(TESFile* apFile);

// @fnv 0x00585ee0
bool WorldSpaceParentFileMethods::FindParentFile(int a1, int a2, unsigned int* apuiFileOut, unsigned int* apuiOffsetOut)
{
    bool bFound = false;
    *apuiFileOut = 0;
    *apuiOffsetOut = 0;
    if (!GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)0))
    {
        int iFileCount = GetFileCount();
        if (iFileCount)
        {
            for (int iFileIndex = iFileCount - 1; iFileIndex >= 0; iFileIndex--)
            {
                TESFile* pParentFile = GetFileForm(iFileIndex)->GetParentTESFile();
                if (pParentFile && ((WorldSpaceParentReadMethods*)this)->ReadWorldData(pParentFile, a1, a2) && LoadedCheck(pParentFile))
                {
                    *apuiFileOut = (unsigned int)pParentFile;
                    *apuiOffsetOut = pParentFile->GetOffset();
                    bFound = true;
                    break;
                }
            }
        }
    }
    else
    {
        bFound = ((WorldSpaceParentFileMethods*)GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)0))
                     ->FindParentFile(a1, a2, apuiFileOut, apuiOffsetOut);
    }
    return bFound;
}

struct GlobalObject_006815c0
{
    GlobalObject_006815c0();
    float x, y, z;
};
typedef GlobalObject_006815c0 RegionSamplePoint;
struct RegionForm
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual unsigned char Weight();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual float Value108();
    virtual void v109();
    virtual float Value110();
    virtual void v111();
    virtual float Value112();
    virtual void v113();
    virtual float Value114();
    virtual void v115();
    virtual unsigned char Value116();
    virtual void v117();
    virtual unsigned char Value118();
    virtual void v119();
    virtual unsigned char Value120();
    const char* TESGrass_GetModelPath();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct Region
{
    virtual void v0();
    virtual RegionForm* Form();
    virtual void v2();
    virtual int Priority();
    virtual void v4();
    virtual void v5();
    virtual float Weight(RegionSamplePoint const&, TESWorldSpace*, bool);
};
struct Entry
{
    Region* region;
    float weight;
};
struct RegionNode
{
    Region* item;
    RegionNode* next;
    Region** FUN_006815c0();
    RegionNode* FUN_00726070();
};
struct Head
{
    int unk00;
};
struct RegionData : Head, RegionNode
{
};
struct Selection
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Selection* Select(void*);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual RegionData* GetList();
};
struct CellRegions
{
    void* TESRegionList_GetDerivedData_(int, RegionSamplePoint const&, TESWorldSpace*);
};
struct CellProxyNew
{
    CellRegions* GetRegionList(bool);
};
struct GlobalObject_0096a2d0
{
    GlobalObject_0096a2d0();
    Entry* item;
    GlobalObject_0096a2d0* next;
    Entry** FUN_006815c0();
    GlobalObject_0096a2d0* FUN_00726070();
    bool FUN_008256d0();
    void FUN_005ae3d0(Entry*&);
    void FUN_00470470();
};
struct RegionResult
{
    char* name;
    unsigned int formID;
    float a, b, c, time, d;
    unsigned char e, f, g, unk1f;
    float samples[9];
};
int __cdecl BSsprintf(char*, int, const char*, ...);
float __cdecl TESGrass_GetWaveOffsetRange();
struct WorldSpaceRegionMethods : TESWorldSpace
{
    void BuildRegionResults(float, float, float, float, RegionResult*, unsigned);
};
// Selects regions around the center of the given bounds, fills each result with region data and samples region weights at a 3x3 grid of points.
// @fnv 0x00586990
void WorldSpaceRegionMethods::BuildRegionResults(float minX, float minY, float maxX, float maxY, RegionResult* results, unsigned count)
{
    Entry* l = 0;
    Region** k = 0;
    Region* b = 0;
    RegionForm* a = 0;
    RegionSamplePoint s[9];
    RegionSamplePoint h;
    if (!g_dataHandler || !count)
        return;
    h.x = (minX + maxX) / 2.0;
    h.y = (minY + maxY) / 2.0;
    h.z = 0;
    float q = (maxX - minX) / 2.0;
    float c = (maxY - minY) / 2.0;
    CellProxyNew* e = reinterpret_cast<CellProxyNew*>(g_dataHandler->GetCellByWorldPosition(h.x, h.y, this, false));
    if (!e || !e->GetRegionList(true))
        return;
    unsigned i;
    for (i = 0; i < 9; i++)
    {
        s[i].x = minX + (i % 3) * q;
        s[i].y = minY + (i / 3) * c;
        s[i].z = 0;
    }
    Selection* eb =
        reinterpret_cast<Selection*>(g_dataHandler->GetRegionDataManager())->Select(e->GetRegionList(true)->TESRegionList_GetDerivedData_(6, h, this));
    if (!eb)
        return;
    GlobalObject_0096a2d0* cf = new GlobalObject_0096a2d0;
    RegionNode* f = eb->GetList();
    while (f)
    {
        b = *f->FUN_006815c0();
        a = b ? b->Form() : 0;
        if (b && b->Priority() && a && a->Weight() && b->Weight(h, this, false) != 0.0)
        {
            l = new Entry;
            l->region = b;
            l->weight = a->Weight() / 100.0;
            cf->FUN_005ae3d0(l);
        }
        f = f->FUN_00726070();
    }
    f = eb->GetList();
    while (f)
    {
        b = *f->FUN_006815c0();
        a = b ? b->Form() : 0;
        if (b && !b->Priority() && a && a->Weight() && b->Weight(h, this, false) != 0.0)
        {
            l = new Entry;
            l->region = b;
            l->weight = a->Weight() / 100.0;
            cf->FUN_005ae3d0(l);
        }
        f = f->FUN_00726070();
    }
    if (!cf || cf->FUN_008256d0())
    {
        delete (List_009e03e0*)cf;
        return;
    }
    k = new Region*[count];
    memset(k, 0, count * sizeof(Region*));
    GlobalObject_0096a2d0* ba = cf;
    unsigned p;
    for (p = 0; p < count; p++)
    {
        memset(results[p].samples, 0, sizeof(results[p].samples));
        if (results[p].name)
            delete[] results[p].name;
        results[p].name = 0;
        if (!ba)
            continue;
        l = *ba->FUN_006815c0();
        while (!l)
        {
            ba = ba->FUN_00726070();
            if (!ba)
                break;
            l = *ba->FUN_006815c0();
        }
        if (!l)
            continue;
        b = l->region;
        a = b->Form();
        k[p] = b;
        if (results[p].name)
            delete[] results[p].name;
        char* name = new char[260];
        BSsprintf(name, 260, "data/meshes/%s", a->TESGrass_GetModelPath());
        results[p].name = name;
        results[p].formID = a->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        results[p].a = a->Value108();
        results[p].b = a->Value110();
        results[p].c = a->Value112();
        results[p].d = a->Value114();
        results[p].e = a->Value116();
        results[p].f = a->Value118();
        results[p].g = a->Value120();
        results[p].time = TESGrass_GetWaveOffsetRange();
        ba = ba->FUN_00726070();
    }
    for (i = 0; i < 9; i++)
    {
        for (p = 0; p < count; p++)
        {
            if (!k[p] || !results[p].formID)
                continue;
            results[p].samples[i] = k[p]->Weight(s[i], this, true);
        }
    }
    delete[] k;
    {
        GlobalObject_0096a2d0* cleanup = cf;
        Entry* dead = 0;
        while (cleanup && *cleanup->FUN_006815c0())
        {
            dead = *cleanup->FUN_006815c0();
            cleanup = cleanup->FUN_00726070();
            delete dead;
        }
        cf->FUN_00470470();
        delete (List_009e03e0*)cf;
    }
}

struct WsNameList
{
    const char* item;
    WsNameList* next;
    WsNameList();
};

struct WsListNode
{
    TESWorldSpace** Item();
    WsListNode* GetNext();
};

struct WorldSpaceMapNameMethods : public TESWorldSpace
{
    void AddMapNames(WsNameList* apList);
    WsNameList* BuildMapNameList(bool abNoChildren);
};

// Builds a WsNameList from the parent world's list or a new list with this world's map names plus those of child worlds unless abNoChildren.
// @fnv 0x005883c0
WsNameList* WorldSpaceMapNameMethods::BuildMapNameList(bool abNoChildren)
{
    WsNameList* pNameList = 0;
    if (GetParentWorld((PARENT_USE_FLAG)2) && !abNoChildren)
    {
        pNameList = ((WorldSpaceMapNameMethods*)GetParentWorld((PARENT_USE_FLAG)2))->BuildMapNameList(false);
    }
    else
    {
        pNameList = new WsNameList;
        AddMapNames(pNameList);
        if (!abNoChildren)
        {
            WsListNode* pNode = reinterpret_cast<WsListNode*>(g_dataHandler->GetWorldSpaces());
            while (pNode)
            {
                TESWorldSpace* pWorld = *pNode->Item();
                if (pWorld && pWorld->GetParentWorld((PARENT_USE_FLAG)2) == this)
                {
                    ((WorldSpaceMapNameMethods*)pWorld)->AddMapNames(pNameList);
                }
                pNode = pNode->GetNext();
            }
        }
    }
    return pNameList;
}

extern const double DAT_010231b0;
struct WorldSpaceRadiusMethods : public TESWorldSpace
{
    void ProcessCellsInRadius(const NiPoint3* point, float distance, const NiPoint3* otherPoint, float otherDistance,
                              int options, unsigned int context);
};
// @fnv 0x005885f0
void WorldSpaceRadiusMethods::ProcessCellsInRadius(const NiPoint3* point, float distance, const NiPoint3* otherPoint,
                                       float otherDistance, int options, unsigned int context)
{
    if (options == 0)
        return;
    {
        int found = 1;
        int j = 0;
        int width = (int)point->x >> 12;
        int i;
        int x;
        {
            CellRuntimeMethods* cell;
            {
                int y = (int)point->y >> 12;
                cell = reinterpret_cast<CellRuntimeMethods*>(GetCellAtGridPosition(width, y));
                if (cell != 0)
                {
                    if (!cell->TESObjectCELL_EnumReferencesCloseToPoint(point, distance, otherPoint, otherDistance, options, context))
                        return;
                }
                {
                    while (found != 0)
                    {
                        width -= 1;
                        y -= 1;
                        j += 2;
                        found = 0;
                        for (i = 0; i < j; i++)
                        {
                            cell = reinterpret_cast<CellRuntimeMethods*>(GetCellAtGridPosition(width, y));
                            if (cell != 0 && (distance == DAT_010231b0 || cell->TESObjectCELL_GetDistanceFromPoint(point) < distance) &&
                                (otherDistance == DAT_010231b0 || cell->TESObjectCELL_GetDistanceFromPoint(otherPoint) < otherDistance))
                            {
                                found += 1;
                                if (!cell->TESObjectCELL_EnumReferencesCloseToPoint(point, distance, otherPoint, otherDistance, options, context))
                                    return;
                            }
                            width += 1;
                        }
                        for (x = 0; x < j; x++)
                        {
                            cell = reinterpret_cast<CellRuntimeMethods*>(GetCellAtGridPosition(width, y));
                            if (cell != 0 && (distance == DAT_010231b0 || cell->TESObjectCELL_GetDistanceFromPoint(point) < distance) &&
                                (otherDistance == DAT_010231b0 || cell->TESObjectCELL_GetDistanceFromPoint(otherPoint) < otherDistance))
                            {
                                found += 1;
                                if (!cell->TESObjectCELL_EnumReferencesCloseToPoint(point, distance, otherPoint, otherDistance, options, context))
                                    return;
                            }
                            y += 1;
                        }
                        for (i = 0; i < j; i++)
                        {
                            cell = reinterpret_cast<CellRuntimeMethods*>(GetCellAtGridPosition(width, y));
                            if (cell != 0 && (distance == DAT_010231b0 || cell->TESObjectCELL_GetDistanceFromPoint(point) < distance) &&
                                (otherDistance == DAT_010231b0 || cell->TESObjectCELL_GetDistanceFromPoint(otherPoint) < otherDistance))
                            {
                                found += 1;
                                if (!cell->TESObjectCELL_EnumReferencesCloseToPoint(point, distance, otherPoint, otherDistance, options, context))
                                    return;
                            }
                            width -= 1;
                        }
                        for (x = 0; x < j; x++)
                        {
                            cell = reinterpret_cast<CellRuntimeMethods*>(GetCellAtGridPosition(width, y));
                            if (cell != 0 && (distance == DAT_010231b0 || cell->TESObjectCELL_GetDistanceFromPoint(point) < distance) &&
                                (otherDistance == DAT_010231b0 || cell->TESObjectCELL_GetDistanceFromPoint(otherPoint) < otherDistance))
                            {
                                found += 1;
                                if (!cell->TESObjectCELL_EnumReferencesCloseToPoint(point, distance, otherPoint, otherDistance, options, context))
                                    return;
                            }
                            y -= 1;
                        }
                    }
                    cell = (CellRuntimeMethods*)GetInteriorCell();
                    if (cell != 0)
                        cell->TESObjectCELL_EnumReferencesCloseToPoint(point, distance, otherPoint, otherDistance, options, context);
                }
            }
        }
    }
}

struct QueryPoint2
{
    float x, y;
    QueryPoint2(float x, float y);
};
struct WorldSpacePointQueryMethods;
struct AreaQuery
{
    bool TESRegionPointList_IsInsideRegion(const QueryPoint2* point);
};
struct CellQuery;
template <class T> struct QueryLink
{
    T* item;
    QueryLink* next;
    T** FUN_006815c0();
    QueryLink* FUN_00726070();
};
struct QueryNodeHeader
{
    unsigned int unk00;
};
struct CellQueryNode : QueryNodeHeader, QueryLink<CellQuery>
{
};
struct QueryData
{
    CellQueryNode* TESDataHandler_GetRegionList();
};
extern QueryData* g_011c3f2c;
struct CellQuery
{
    bool TESForm_GetHasSpokenFlag();
    bool FUN_00440d80();
    WorldSpacePointQueryMethods* BGSSaveFormBuffer_GetForm();
    QueryLink<AreaQuery>* FUN_00441110();
};
struct WorldSpacePointQueryMethods : TESWorldSpace
{
    bool IsFlag8Set();
    bool ContainsPoint(const NiPoint3* position);
};

// @fnv 0x00588d10
bool WorldSpacePointQueryMethods::ContainsPoint(const NiPoint3* position)
{
    if (!IsFlag8Set())
        return true;
    QueryPoint2 point3(position->x, position->y);
    bool found = false;
    CellQueryNode* node2 = g_011c3f2c->TESDataHandler_GetRegionList();
    while (node2 && *node2->FUN_006815c0())
    {
        CellQuery* cell2 = *node2->FUN_006815c0();
        if (cell2->TESForm_GetHasSpokenFlag() && !cell2->FUN_00440d80() && cell2->BGSSaveFormBuffer_GetForm() == this)
        {
            QueryLink<AreaQuery>* link = cell2->FUN_00441110();
            while (link && *link->FUN_006815c0())
            {
                AreaQuery* area = *link->FUN_006815c0();
                if (area->TESRegionPointList_IsInsideRegion(&point3))
                    found = true;
                link = link->FUN_00726070();
            }
        }
        node2 = static_cast<CellQueryNode*>(node2->FUN_00726070());
    }
    return found;
}

namespace fnv_00583560 {
extern "C" void* _alloca(unsigned int);
void* operator new(unsigned int);
void operator delete(void*);
struct B006815c0
{
    float x, y;
    B006815c0();
};
// OFST/NAM0/NAM9 use a 24-byte cell-offset/bounds record; the unrelated OffsetData is 8 bytes.
struct WorldCellOffsetRecord
{
    unsigned int* offsets;
    B006815c0 minimum, maximum;
    unsigned int offset;
};
// DNAM holds two float heights and uses the 0x00462230 endian swap helper.
struct WorldDefaultHeightChunk
{
    float x, y;
    void TwoValues_Endian();
};
struct MapData583
{
    float x, y, z, w;
    void SwapIntegerAndShortByteOrder();
};
struct Extra583
{
    unsigned int x, y, z;
    void TESRegionSound_Endian();
};
void FUN_0048e3d0(TESTexture*, TESFile*);
void ReadFullName(TESFullName*, TESFile*);
void BSEndian_00401080(void*, bool);
float BSMIN(float, float);
float BSMAX_00404010(float, float);
class FUN_0058efd0
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    FUN_0058efd0();
    void FUN_0058f180(TESFile*);
};

// These loading entry points are not yet declared by the shared worldspace header.
class WorldSpaceLoadMethods : public TESWorldSpace
{
  public:
    void FUN_00484ab0(int);
    void TESWorldSpace_SetClimate(unsigned int);
    void FUN_008d8040(unsigned int);
    void FUN_004febb0(unsigned int);
    void FUN_00442a80(unsigned int);
    void SetAssociatedActorValue(unsigned int);
    bool FUN_00484e40();
    bool TESWorldSpace_Load(TESFile*);
};

struct EndianFlag583
{
    bool value;
};
// @fnv 0x00583560
// src: COMMUNITY 0x00583560
bool WorldSpaceLoadMethods::TESWorldSpace_Load(TESFile* file)
{
    int chunk;
    unsigned char type = file->GetTESForm();
    if (type != 0x41)
        return false;
    if (file->IsMasterFile())
    {
        WorldCellOffsetRecord* data = reinterpret_cast<WorldCellOffsetRecord*>(GetOrCreateCellOffsetData(file));
        data->offset = file->GetOffset();
    }
    LoadRecordHeader(file);
    FUN_00484ab0(0);
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4e4f4349:
            FUN_0048e3d0(this, file);
            break;
        case 0x4c4c5546:
            ReadFullName(this, file);
            break;
        case 0x41544144: {
            if (file->GetChunkSize() == 4)
            {
                unsigned int flags = 0;
                file->GetChunkData(&flags);
                flags4C = (unsigned char)flags;
            }
            else
                file->GetChunkData(&flags4C, 1);
            break;
        }
        case 0x5453464f: {
            unsigned int size = file->GetChunkSize();
            if (size)
            {
                WorldCellOffsetRecord* data;
                {
                    unsigned int count = size >> 2;
                    data = reinterpret_cast<WorldCellOffsetRecord*>(GetOrCreateCellOffsetData(file));
                    if (data->offsets)
                        delete data->offsets;
                    data->offsets = new unsigned int[count];
                    file->GetChunkData(data->offsets, 0);
                    if (file->IsEndianConversionRequired())
                    {
                        for (unsigned int i = 0; i < count; i++)
                            BSEndian_00401080(&data->offsets[i], EndianFlag583().value);
                    }
                }
            }
            break;
        }
        case 0x4e5a4558: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            fieldD0 = value;
            break;
        }
        case 0x4d414e43: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            TESWorldSpace_SetClimate(value);
            break;
        }
        case 0x4d414e49: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            FUN_008d8040(value);
            break;
        }
        case 0x324d414e: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            FUN_004febb0(value);
            break;
        }
        case 0x334d414e: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            FUN_00442a80(value);
            break;
        }
        case 0x344d414e: {
            float value = 0;
            file->GetChunkData(reinterpret_cast<unsigned int*>(&value));
            SetWaterLODHeight(value);
            break;
        }
        case 0x4d414e57: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            SetParent(reinterpret_cast<TESWorldSpace*>(value));
            field4E = 0xffff;
            break;
        }
        case 0x4d414e50:
            file->GetChunkData(&field4E);
            break;
        case 0x4d414e44: {
            WorldDefaultHeightChunk value;
            file->GetChunkData(&value, 8);
            if (file->IsEndianConversionRequired())
                value.TwoValues_Endian();
            fC8 = value.x;
            fCC = value.y;
            break;
        }
        case 0x4d414e4d:
            file->GetChunkData(&(*reinterpret_cast<MapData583*>(unk80)), 16);
            if (file->IsEndianConversionRequired())
                (*reinterpret_cast<MapData583*>(unk80)).SwapIntegerAndShortByteOrder();
            break;
        case 0x4d414e4f:
            file->GetChunkData(&(*reinterpret_cast<Extra583*>(unk80 + 16)), 12);
            if (file->IsEndianConversionRequired())
                (*reinterpret_cast<Extra583*>(unk80 + 16)).TESRegionSound_Endian();
            break;
        case 0x4d414e53: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            break;
        }
        case 0x4d414e5a: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            SetAssociatedActorValue(value);
            break;
        }
        case 0x46504d49:
        case 0x53504d49:
            if (!reinterpret_cast<FUN_0058efd0*&>(data))
                reinterpret_cast<FUN_0058efd0*&>(data) = new FUN_0058efd0;
            reinterpret_cast<FUN_0058efd0*&>(data)->FUN_0058f180(file);
            break;
        case 0x4d414e4e: {
            unsigned int size = file->GetChunkSize();
            if (size)
            {
                char* text = (char*)_alloca(size);
                file->GetChunkData(text, size);
                (*reinterpret_cast<TESFullName*>(&CanopyShadowTexture)).SetFullName(text);
            }
            break;
        }
        case 0x4d414e58: {
            unsigned int size = file->GetChunkSize();
            if (size)
            {
                char* text = (char*)_alloca(size);
                file->GetChunkData(text, size);
                (*reinterpret_cast<TESFullName*>(&m_kLeafShadowTexture)).SetFullName(text);
            }
            break;
        }
        case 0x304d414e: {
            B006815c0 value;
            file->GetChunkData(&value, 8);
            if (file->IsEndianConversionRequired())
            {
                BSEndian_00401080(&value.x, EndianFlag583().value);
                BSEndian_00401080(&value.y, EndianFlag583().value);
            }
            m_kFirstPoint.x = BSMIN(m_kFirstPoint.x, value.x);
            m_kFirstPoint.y = BSMIN(m_kFirstPoint.y, value.y);
            if (file->IsMasterFile())
            {
                WorldCellOffsetRecord* data = reinterpret_cast<WorldCellOffsetRecord*>(GetOrCreateCellOffsetData(file));
                data->minimum = value;
            }
            break;
        }
        case 0x394d414e: {
            B006815c0 value;
            file->GetChunkData(&value, 8);
            if (file->IsEndianConversionRequired())
            {
                BSEndian_00401080(&value.x, EndianFlag583().value);
                BSEndian_00401080(&value.y, EndianFlag583().value);
            }
            m_kEndPoint.x = BSMAX_00404010(m_kEndPoint.x, value.x);
            m_kEndPoint.y = BSMAX_00404010(m_kEndPoint.y, value.y);
            if (file->IsMasterFile())
            {
                WorldCellOffsetRecord* data = reinterpret_cast<WorldCellOffsetRecord*>(GetOrCreateCellOffsetData(file));
                data->maximum = value;
            }
            break;
        }
        }
        if (!file->GetNextChunk())
            break;
    }
    if (!cellMap->GetCount() && !GetSmallWorld())
    {
        delete cellMap;
        if (FUN_00484e40())
            cellMap = new NiTPointerMap<unsigned int, TESObjectREFR*>(7001);
        else
            cellMap = new NiTPointerMap<unsigned int, TESObjectREFR*>(701);
    }
    return true;
}
}  // namespace fnv_00583560

namespace fnv_005878d0 {
class Pt
{
  public:
    float x;
    float y;
    float z;
    float Length() const;
};
class StrList
{
  public:
    int a;
    int b;
    StrList();
};
class SetAtHelper
{
  public:
    void FUN_005ae3d0(void**);
};
class RefObj
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Pt* v125();
    bool TESObjectREFR_IsMultiBoundRef();
    Pt* TESObjectREFR_GetMultiBoundHalfExtent();
};
bool BoundIntersectsCell(RefObj*, int, int);
int TruncateFloatToInt(float);
// Local method adapter for overlap references, absent from the shared header.
class WorldSpaceOverlapMethods : public TESWorldSpace
{
  public:
    void TESWorldSpace_AddMultiBoundRef(RefObj*);
};

// @fnv 0x005878d0
// src: XBOX_PDB 0x005878d0
void WorldSpaceOverlapMethods::TESWorldSpace_AddMultiBoundRef(RefObj* pRef)
{
    if (pRef)
    {
        if (pRef->TESObjectREFR_IsMultiBoundRef())
        {
            Pt ptPos3 = *pRef->TESObjectREFR_GetMultiBoundHalfExtent();
            float fLen7 = ptPos3.Length();
            int iXMin5 = TruncateFloatToInt(pRef->v125()->x - fLen7) >> 12;
            int iYMin8 = TruncateFloatToInt(pRef->v125()->y - fLen7) >> 12;
            int iXMax9 = TruncateFloatToInt(pRef->v125()->x + fLen7) >> 12;
            int iYMaxA = TruncateFloatToInt(pRef->v125()->y + fLen7) >> 12;
            int iCX3 = TruncateFloatToInt(pRef->v125()->x) >> 12;
            int iCY = TruncateFloatToInt(pRef->v125()->y) >> 12;
            for (int i_ = iXMin5; i_ <= iXMax9; ++i_)
            {
                for (int j2 = iYMin8; j2 <= iYMaxA; ++j2)
                {
                    if (i_ != iCX3 || j2 != iCY)
                    {
                        if (BoundIntersectsCell(pRef, i_, j2))
                        {
                            if (!reinterpret_cast<DummyPointerMap*&>(m_pFourthTreePointer))
                                reinterpret_cast<DummyPointerMap*&>(m_pFourthTreePointer) = new DummyPointerMap(0x25);
                            unsigned int key3 = TESWorldSpace::BuildCellKey((short)i_, (short)j2);
                            int val = 0;
                            reinterpret_cast<DummyPointerMap*&>(m_pFourthTreePointer)->GetAt(key3, val);
                            if (!val)
                            {
                                val = (int)new StrList();
                                reinterpret_cast<DummyPointerMap*&>(m_pFourthTreePointer)->SetAt(key3, val);
                            }
                            ((SetAtHelper*)val)->FUN_005ae3d0((void**)&pRef);
                        }
                    }
                }
            }
        }
    }
}
}  // namespace fnv_005878d0


struct Pos65
{
    float x, y, z;
    Pos65();
    bool HasEqualComponents(const Pos65&);
};
struct Point65
{
    float x, y;
    Point65(const Pos65&);
};
struct Area65
{
    bool TESRegionPointList_IsInsideRegion(const Point65&);
};
struct AreaList65
{
    Area65** FUN_006815c0();
    AreaList65* FUN_00726070();
    bool FUN_008256d0();
    void* TESRegionList_GetDerivedData_(int, const Pos65&, void*);
};
struct Data65
{
    bool TESRegionData_GetOverride();
    unsigned char TESRegionData_GetPriority();
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28(BSStringT<char>*);
};
struct Manager65
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual Data65* v10(void*);
};
struct RegionNode65
{
    TESRegion** FUN_006815c0();
    RegionNode65* FUN_00726070();
};
struct RegionPrefix65
{
    int unk00;
};
struct RegionHead65 : RegionPrefix65, RegionNode65
{
};
struct Type65
{
    void* TESRegionDataList_Find(int);
};
struct Cell65
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    TESFullName fullName;
    AreaList65* FUN_00547110(bool);
};
// Local method adapter: the shared header has no position-name lookup yet.
struct WorldSpacePositionNameMethods : TESWorldSpace
{
    bool TESWorldSpace_GetMapNameForLocation(BSStringT<char>*, Pos65);
};
// Selects a name for pos from its cell or matching regions, falls back to this world's full name or FUN_00586980, and reports whether output changed.
// @fnv 0x00586500
// src: XBOX_PDB 0x00586500
bool WorldSpacePositionNameMethods::TESWorldSpace_GetMapNameForLocation(BSStringT<char>* output, Pos65 pos)
{
    static BSStringT<char> lastName;
    static Pos65 lastPos;
    static WorldSpacePositionNameMethods* lastWorld;
    Data65* data7 = 0;
    if (!g_dataHandler)
        return false;
    if (lastWorld == this && lastPos.HasEqualComponents(pos))
    {
        output->Set((const char*)lastName, 0);
        return false;
    }
    if (lastWorld != this)
        lastName.Set("");
    lastWorld = this;
    lastPos = pos;
    output->Set("");
    Cell65* cellVal = reinterpret_cast<Cell65*>(g_dataHandler->GetCellByWorldPosition(pos.x, pos.y, reinterpret_cast<TESWorldSpace*>(this), false));
    if (cellVal)
    {
        data7 = cellVal->FUN_00547110(true) ? reinterpret_cast<Manager65*>(g_dataHandler->GetRegionDataManager())
                                                  ->v10(cellVal->FUN_00547110(true)->TESRegionList_GetDerivedData_(4, pos, this))
                                            : 0;
        if (data7)
            data7->v28(output);
        else
            output->Set(cellVal->fullName.GetFullName());
    }
    else
    {
        TESRegion* region4;
        Area65* area;
        RegionNode65* node5 = reinterpret_cast<RegionHead65*>(g_dataHandler->GetRegionList());
        AreaList65* areas = 0;
        Point65 point2(pos);
        int priority6 = -1;
        bool contains3 = false;
        bool aOverrideFlag = false;
        while (node5 && *node5->FUN_006815c0())
        {
            contains3 = false;
            region4 = *node5->FUN_006815c0();
            if (region4->IsDeleted() || region4->GetParentWorldSpace() != reinterpret_cast<TESWorldSpace*>(this) || !reinterpret_cast<AreaList65*>(region4->GetRegionPointLists()) ||
                reinterpret_cast<AreaList65*>(region4->GetRegionPointLists())->FUN_008256d0())
            {
                node5 = node5->FUN_00726070();
                continue;
            }
            data7 = reinterpret_cast<Manager65*>(g_dataHandler->GetRegionDataManager())
                        ->v10(((Type65*)region4->GetDataList())->TESRegionDataList_Find(4));
            if (!data7)
            {
                node5 = node5->FUN_00726070();
                continue;
            }
            areas = reinterpret_cast<AreaList65*>(region4->GetRegionPointLists());
            while (areas && *areas->FUN_006815c0())
            {
                area = *areas->FUN_006815c0();
                if (area->TESRegionPointList_IsInsideRegion(point2))
                {
                    contains3 = true;
                    break;
                }
                areas = areas->FUN_00726070();
            }
            if (!contains3)
            {
                node5 = node5->FUN_00726070();
                continue;
            }
            if (data7->TESRegionData_GetOverride())
            {
                if (aOverrideFlag && data7->TESRegionData_GetPriority() <= priority6)
                {
                    node5 = node5->FUN_00726070();
                    continue;
                }
            }
            else if (aOverrideFlag || data7->TESRegionData_GetPriority() <= priority6)
            {
                node5 = node5->FUN_00726070();
                continue;
            }
            aOverrideFlag = data7->TESRegionData_GetOverride();
            priority6 = data7->TESRegionData_GetPriority();
            data7->v28(output);
            node5 = node5->FUN_00726070();
        }
    }
    if (!output->Length())
        output->Set(TESFullName::GetFullName());
    if (!output->Length())
        output->Set(TESObjectCELL_GetDefaultCellName());
    if (output->StrCmp(lastName, true))
    {
        lastName.Set((const char*)*output, 0);
        return true;
    }
    return false;
}

struct ATM_587D10
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
struct Pt3_587D10
{
    float x, y, z;
};
struct RefV_587D10
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Pt3_587D10* GetPos();
};
namespace WsH_587D10 {
int __cdecl GetKeyForWorldCoord(Pt3_587D10 const&);
}
bool __cdecl TESWorldSpace_IsFixedRef(void*);
struct RefList_587D10
{
    int a;
    int b;
    void AddHead(int*);
};
struct RefListNode_587D10 : RefList_587D10
{
    RefListNode_587D10();
};

// Adds apRef to a list directly or to a coordinate-keyed list, skipping null and temporary references.
// @fnv 0x00587d10
// src: COMMUNITY 0x00587d10
void TESWorldSpace::AddToPersistentRefData(TESObjectREFR* apRef)
{
    if (apRef && !apRef->IsTemporary())
    {
        g_011ca60c.QueryPerformanceCounter(0);
        if (!TESWorldSpace_IsFixedRef(apRef))
        {
            ((RefList_587D10*)((char*)this + 0x60))->AddHead((int*)&apRef);
        }
        else
        {
            unsigned int ikey = WsH_587D10::GetKeyForWorldCoord(*((RefV_587D10*)apRef)->GetPos());
            RefListNode_587D10* preflist = 0;
            ((NiTPointerMap<unsigned int, unsigned int>*)((char*)this + 0x50))->GetAt(ikey, (unsigned int&)preflist);
            if (!preflist)
            {
                preflist = new RefListNode_587D10;
                ((NiTPointerMap<unsigned int, unsigned int>*)((char*)this + 0x50))->SetAt(ikey, (unsigned int)preflist);
            }
            preflist->AddHead((int*)&apRef);
        }
        g_011ca60c.WaitForTasksDuringRendering();
    }
}
