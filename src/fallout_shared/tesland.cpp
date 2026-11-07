// fallout_shared/tesland.cpp: TESLandFlagsView (7 functions)

#include "tesland_decls.h"
#include "../../include/BSStringT.h"
#include "../../include/NiPoint3.h"
#include "../../include/PathingActorData.h"
#include "../../include/TESForm.h"
#pragma optimize("", off)
int TruncateFloatToInt(float value);
// @fnv 0x005394a0
// src: XBOX_PDB 0x005394a0
bool TESLandFlagsView::TESPackage_GetLockDoorsAtStart()
{
    if (flags & 8)
        return true;
    else
        return false;
}

extern int DAT_0102de10;

struct FUN_00533240_helper
{
    int* vtable;
    FUN_00533240_helper* InitVtable();
};

// @fnv 0x00533240
FUN_00533240_helper* FUN_00533240_helper::InitVtable()
{
    this->vtable = &DAT_0102de10;
    return this;
}

// @fnv 0x00534550
// src: COMMUNITY 0x00534550
void* __fastcall NiTConvertingStrideIterator_NiTConvertingStrideIterator(PathingActorData* pThis)
{
    pThis->PathingActorData::PathingActorData();
    return pThis;
}

// Reads a BSStringT at thisPtr+0xb8, treats it as a TESForm and returns that form's source file list.
// @fnv 0x00537b10
BSSimpleList<TESFile*>* __fastcall GetSourceFilesFromForm(char* thisPtr)
{
    return ((TESForm*)(const char*)(*(BSStringT<char>*)(thisPtr + 0xb8)))->GetSourceFiles();
}

struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESFullName;
struct TESGlobal;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESObjectREFR;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};

CellMopp* __fastcall ExtraDataList_GetCellMopp(void* pThis);

// @fnv 0x00537b30
CellMopp* __fastcall GetCellMopp(char* pThis)
{
    return ExtraDataList_GetCellMopp(pThis + 0x28);
}

extern int DAT_0102e388;

struct FUN_00538e30_class
{
    int vtable;
    void SetVtable();
};

// @fnv 0x00538e30
void __fastcall SetVtable(FUN_00538e30_class* this_ptr)
{
    this_ptr->vtable = (int)&DAT_0102e388;
}

// Returns a new NiPoint3 with each component divided by denom.
// @fnv 0x0053d280
// src: GUESS 0x0053d280 (confidence: low)
NiPoint3 NiPoint3::ProcessAndReturnValue_0053d280(float denom) const
{
    float inv = 1.0f / denom;
    return NiPoint3(inv * this->x, inv * this->y, inv * this->z);
}
