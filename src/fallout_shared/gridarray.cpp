// fallout_shared/gridarray.cpp: GridArray (7 functions)

#include "../../include/GridArray.h"

// @fnv 0x004b9e70
void GridArray::Init()
{
    iCenterPixelY = -10000;
    iHorizontalPixelCenterObj = -10000;
}

// @fnv 0x004b9eb0
void GridArray::DetachAllCells()
{
    for (unsigned int i = 0; i < uiDimension; ++i)
    {
        for (unsigned int j = 0; j < uiDimension; ++j)
        {
            Detach(i, j);
        }
    }
}

// @fnv 0x004b9e50
GridArray::~GridArray()
{
}

// @fnv 0x004b9e90
void GridArray::AttachAllCells()
{
    DetachAllCells();
}

// Computes the offset from the current cell to (aiX, aiY), shifts by it, and returns whether the offset was non-zero.
// @fnv 0x004b9f10
bool GridArray::SetGridPosition(int aiX, int aiY)
{
    int ioffX = aiX - static_cast<const GridArray*>(this)->GetCenterX();
    int ioffY = aiY - m_fCenterY();
    Shift(ioffX, ioffY);
    if (ioffX || ioffY)
        return true;
    else
        return false;
}

int FUN_00ec7d40(int);
// @fnv 0x004b9f70
void GridArray::Shift(int aiShiftX, int aiShiftY)
{
    unsigned int j = 0;
    unsigned int i = 0;
    iHorizontalPixelCenterObj += aiShiftX;
    iCenterPixelY += aiShiftY;
    if ((unsigned int)FUN_00ec7d40(aiShiftX) >= uiDimension || (unsigned int)FUN_00ec7d40(aiShiftY) >= uiDimension)
    {
        DetachAllCells();
        return;
    }
    while (aiShiftX != 0)
    {
        if (aiShiftX < 0)
        {
            for (i = 0; i < uiDimension; ++i)
            {
                j = uiDimension - 1;
                Detach(j, i);
                for (; j > 0; --j)
                    MoveItem(j - 1, i, j, i);
                ClearTileExtraPair(j, i);
            }
            ++aiShiftX;
        }
        else
        {
            for (i = 0; i < uiDimension; ++i)
            {
                j = 0;
                Detach(j, i);
                for (; j < uiDimension - 1; ++j)
                    MoveItem(j + 1, i, j, i);
                ClearTileExtraPair(j, i);
            }
            --aiShiftX;
        }
    }
    while (aiShiftY != 0)
    {
        if (aiShiftY < 0)
        {
            for (j = 0; j < uiDimension; ++j)
            {
                i = uiDimension - 1;
                Detach(j, i);
                for (; i > 0; --i)
                    MoveItem(j, i - 1, j, i);
                ClearTileExtraPair(j, i);
            }
            ++aiShiftY;
        }
        else
        {
            for (j = 0; j < uiDimension; ++j)
            {
                i = 0;
                Detach(j, i);
                for (; i < uiDimension - 1; ++i)
                    MoveItem(j, i + 1, j, i);
                ClearTileExtraPair(j, i);
            }
            --aiShiftY;
        }
    }
}
