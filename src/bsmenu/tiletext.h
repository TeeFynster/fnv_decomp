// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/bsmenu/tiletext.h
//
// Covered function (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x00a0bbd0  TileText::GetType                  (16 bytes)
//
// TileText remains local until the shared header declares its rendering overrides.
#ifndef FNV_TILETEXT_H
#define FNV_TILETEXT_H


#include "layout_support.h"
#include "../../include/NiObject.h"
#include "../../include/NiFixedString.h"
#include "../../include/Tile.h"
#include "../../include/NiPoint3.h"

#pragma pack(push, 4)

class TextNode;

class TileText : public Tile
{
  public:
    virtual int GetType();
    virtual void Init(Tile* parent, const char* name, Tile* replacedChild);
    virtual Tile* SetTraitValue(int trait, float value, const char* text);
    virtual NiNode* CalculateNode();
    TextNode* GetNiNode();

    void SetPosition(const NiPoint3& p)
    {
        position = p;
    }

    unsigned int unk38;
    NiPoint3 position;
    bool multibyte;
};

#pragma pack(pop)

#endif
