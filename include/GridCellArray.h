#pragma once

#include "GridArray.h"

class GridCell;
class NiNode;
class Obj;
class TESObjectCELL;

// Exe GridCellArray helpers use an erased object reference with a Check(int) call; pointee identity is unproven.
struct GridCellObjectRefView
{
    Obj* p;

    GridCellObjectRefView(Obj*);
    ~GridCellObjectRefView();
    GridCellObjectRefView& operator=(Obj*);
    Obj* operator->() const;
    bool Check(int);
};

class GridCellArray : public GridArray
{
public:
    virtual ~GridCellArray();
    virtual void Init();
    virtual void AttachAllCells();
    virtual bool SetGridPosition(int x, int y);
    virtual void Detach(unsigned int gridX, unsigned int gridY);
    virtual void ClearTileExtraPair(unsigned int gridX, unsigned int gridY);
    virtual void MoveItem(unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void SwapTileExtraPair(unsigned int, unsigned int, unsigned int, unsigned int);

    GridCell* Get(unsigned int gridX, unsigned int gridY);
    void SetCellAtXY(unsigned int gridX, unsigned int gridY, GridCell* cell);
    void SetCellAt(unsigned int gridX, unsigned int gridY, TESObjectCELL* cell);
    bool IsOutdoorCell(unsigned int gridX, unsigned int gridY);
    void UpdateCellGrid(float value);
    void Clear();
    void ReleaseGridCells();
    bool SetGridCellPosition(int x, int y);
    void SetFrom(unsigned int, unsigned int, unsigned int, unsigned int);
    void SwapCells(unsigned int, unsigned int, unsigned int, unsigned int);
    void FUN_004ba600();
    void FUN_004ba7d0();
    void FUN_004ba960(NiNode* root, unsigned int gridX, unsigned int gridY);
    void FUN_004baab0();
    void FUN_004baba0();
    void FUN_004bac20();
    void FUN_004baca0(bool show);
    void FUN_004bad40();
    void FUN_004bae20(bool detach);
    void FUN_004baec0();
    void FUN_004baf10();

    GridCell* m_pGridCells;
    float fX;
    float fY;
    int unk1c;
    int unk20;
    GridCellObjectRefView spRT;
};
