
// tesobjectcell_ctx3_variant.cpp: context variant of src/fallout_shared/tesobjectcell.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "tesobjectcell_packet.h"
#include "../../include/NavMesh.h"
#include "../../include/NavMeshPtr.h"
#include "../../include/SL.h"
#include "../../include/TESObjectLAND.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int TESTerrainLODManager_GetGrassNode();
NiAVObject* TESMain_GetWeatherRoot();

#include "../../include/NavMeshCollection.h"
int __fastcall GetReferenceFlags(void*);
NavMeshPtr __cdecl MakeNavMeshPointer(NavMesh*);
struct S004867a0
{
    TESForm* TESForm_CreateDuplicateForm(bool, void*);
};
struct CellX
{
    void SetLandscape(TESObjectLAND*);
    void AddReference(TESObjectREFR*, bool);
    void SetNavMeshArray(NavMeshCollection*);
};
struct CellH
{
    bool IsCellPersistent();
};
struct RefX
{
    bool GetReferencePersistence();
    void SetPersistentFlag(bool);
};
struct TempIsTemp
{
    bool IsTemporary() const;
};
struct ListX : SL
{
    ~ListX();
};
struct G2
{
    void AddHead(int*);
};
struct LNode
{
    bool FUN_008256d0();
    void** FUN_006815c0();
    LNode* GetNext();
};

struct FUN_005436e0_shell : TESObjectCELL
{
    TESForm* TESObjectCELL_CreateDuplicateForm(bool abCreateEditorID, void* apCopyMap);
};

// @fnv 0x005436e0
// src: XBOX_PDB 0x005436e0
TESForm* FUN_005436e0_shell::TESObjectCELL_CreateDuplicateForm(bool abCreateEditorID, void* apCopyMap)
{
    TESObjectCELL* pdupcell = 0;
    if (IsCellInterior())
    {
    }
    else
    {
        BSSimpleList<TESObjectREFR*>* pCurrentElementNext;
        pdupcell = dynamic_cast<TESObjectCELL*>(((S004867a0*)this)->TESForm_CreateDuplicateForm(false, apCopyMap));
        TESObjectLAND* pland;
        pland = *(TESObjectLAND**)((char*)this + 0x4c);
        if (pland)
        {
            TESObjectLAND* pdupland = dynamic_cast<TESObjectLAND*>(((TESForm*)pland)->CreateForm(0, apCopyMap));
            if (pdupland)
            {
                ((CellX*)pdupcell)->SetLandscape(pdupland);
                pdupland->InitializeForCell(pdupcell);
                ((TESForm*)pdupland)->SetAltered(true);
            }
        }
        if (*(NavMeshCollection**)((char*)this + 0x64))
        {
            ((CellX*)pdupcell)->SetNavMeshArray(new NavMeshCollection);
            NavMeshPtr spmesh;
            for (unsigned int i = 0; i < GetReferenceFlags(*(NavMeshCollection**)((char*)this + 0x64)); i++)
            {
                NavMesh* pmesh = (NavMesh*)(unsigned int)(*(NavMeshCollection**)((char*)this + 0x64))->GetNavMeshAt(i);
                if (pmesh && !((const TESForm*)pmesh)->IsDeleted())
                {
                    NavMesh* pdupMesh = dynamic_cast<NavMesh*>(((TESForm*)pmesh)->CreateForm(0, apCopyMap));
                    if (pdupMesh)
                    {
                        pdupMesh->m_pOwningCell = pdupcell;
                        spmesh = MakeNavMeshPointer(pdupMesh);
                        (*(NavMeshCollection**)((char*)pdupcell + 0x64))->AppendNavMesh(reinterpret_cast<const NiPointer<NavMesh>&>(spmesh));
                    }
                }
            }
        }
        CellRefLockEnter();
        ListX templist;
        pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)GetRefList_009604f0();
        while (pCurrentElementNext && !((LNode*)pCurrentElementNext)->FUN_008256d0())
        {
            TESObjectREFR* pref = (TESObjectREFR*)*((LNode*)pCurrentElementNext)->FUN_006815c0();
            if (!((TempIsTemp*)pref)->IsTemporary())
            {
                if (IsCellInterior() || ((CellH*)this)->IsCellPersistent() || !((RefX*)pref)->GetReferencePersistence())
                    ((G2*)&templist)->AddHead((int*)&pref);
            }
            pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)((LNode*)pCurrentElementNext)->GetNext();
        }
        CellRefLockLeave();
        pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)&templist;
        while (pCurrentElementNext && !((LNode*)pCurrentElementNext)->FUN_008256d0())
        {
            TESObjectREFR* pref = (TESObjectREFR*)*((LNode*)pCurrentElementNext)->FUN_006815c0();
            TESObjectREFR* pdupref = dynamic_cast<TESObjectREFR*>(((TESForm*)pref)->CreateForm(0, apCopyMap));
            if (pdupref)
            {
                ((RefX*)pdupref)->SetPersistentFlag(((CellH*)pdupcell)->IsCellPersistent());
                ((CellX*)pdupcell)->AddReference(pdupref, false);
                ((TESForm*)pdupref)->SetAltered(true);
            }
            pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)((LNode*)pCurrentElementNext)->GetNext();
        }
        templist.RemoveAll();
    }
    return (TESForm*)pdupcell;
}
