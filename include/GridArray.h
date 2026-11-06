#pragma once

class TESForm;
class GridVector;

class GridArray
{
public:
    GridArray();

    virtual ~GridArray();
    virtual void Init();
    virtual void DetachAllCells();
    virtual void AttachAllCells();
    virtual bool SetGridPosition(int x, int y);
    virtual void Shift(int x, int y);
    virtual void Detach(unsigned int, unsigned int);
    virtual void ClearTileExtraPair(unsigned int, unsigned int);
    virtual void MoveItem(unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void SwapTileExtraPair(unsigned int, unsigned int, unsigned int, unsigned int);

    int GetCenterX() const;
    TESForm* GetCenterX();
    int m_fCenterY() const;
    unsigned int GetGridDimension() const;
    unsigned int GetGridDimension();
    void SetDimension(unsigned int dimension);

    __forceinline int size() const
    {
        return iHorizontalPixelCenterObj;
    }

    __forceinline GridVector& operator[](int i)
    {
        return *reinterpret_cast<GridVector*>(
            reinterpret_cast<char*>(*reinterpret_cast<GridVector**>(this)) + i * 16);
    }

    union
    {
        int iHorizontalPixelCenterObj;
        GridVector* data;
    };
    union
    {
        int iCenterPixelY;
        int count;
    };
    unsigned int uiDimension;
};
