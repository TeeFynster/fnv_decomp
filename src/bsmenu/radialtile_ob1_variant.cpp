
// src/bsmenu/radialtile_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/bsmenu/radialtile.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/bsmenu/radialtile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsmenu/radialtile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../include/Tile.h"
#include "../../include/TileImage.h"
#include "../../include/BSString.h"

#include <math.h>

extern unsigned int BSStringLength(const char*);
inline unsigned int BSStringCapacityMaximum(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}
extern void* __memcpy(void*, const void*, unsigned int);
void* operator new(unsigned int);
void operator delete(void*);

inline BSString::BSString(unsigned int len)
{
    m_data = 0;
    SetBufLen(len);
    SetDataLen(len);
}

inline BSString::~BSString()
{
    Set(0, 0);
}

inline bool BSString::Set(const char* text, unsigned int requested)
{
    unsigned int inputLength = text ? BSStringLength(text) : 0;
    unsigned int length = inputLength;
    unsigned int capacity = BSStringCapacityMaximum(length, requested);
    if (capacity <= GetMaxLength())
    {
        if (capacity)
        {
            if (text)
                __memcpy(m_data, text, length + 1);
            else
                m_data[0] = 0;
        }
        else
        {
            if (m_data)
                delete[] m_data;
            m_data = 0;
            capacity = 0;
            SetDataLen(capacity);
        }
    }
    else
    {
        char* oldData = m_data;
        char* allocation = new char[capacity + 1];
        m_data = allocation;
        if (text)
            __memcpy(m_data, text, length + 1);
        else
            m_data[0] = 0;
        if (oldData)
            delete[] oldData;
        SetDataLen(capacity);
    }
    SetBufLen(length);
    return length != 0;
}

extern float FUN_00706e40();
extern Tile* FUN_00706cd0();
extern int BSStringT_char_SPrintF(BSString*, const char*, ...);
extern void Warning_005b5e40(const char*);

// @fnv 0x00a216b0
// src: XBOX_PDB 0x00a216b0
bool Tile::RadialTile_SpecialBoundsCheck(float x, float y)
{
    float a = this->FUN_00a011b0(0x1004);
    float h = this->FUN_00a011b0(0x1005);
    float q = this->FUN_00a011b0(0x1006);
    float a7 = this->FUN_00a011b0(0x1007);
    float f = this->FUN_00a011b0(0x1008);
    float p = this->FUN_00a011b0(0x1009);

    float scale = FUN_00706e40();
    if (scale == 0.0f)
    {
        scale = 1.0f;
    }

    Tile* s = FUN_00706cd0();
    if (s)
    {
        Tile::Value* t34 = (Tile::Value*)s->Tile_GetValue(0xfb1);
        if (t34)
        {
            scale = t34->fValue / scale;
        }
        else
        {
            scale = 1.0f;
        }
    }
    else
    {
        scale = 1.0f;
    }

    x *= scale;
    y *= scale;
    x -= a;
    y -= h;

    float angle8;
    if (y != 0.0f)
    {
        angle8 = atan(-x / y);
    }
    else
    {
        if (x > 0.0f)
        {
            angle8 = 1.57075f;
        }
        else
        {
            angle8 = 4.71238f;
        }
    }

    if (y > 0.0f)
    {
        angle8 += 3.14159;
    }

    if (x < 0.0f && y < 0.0f)
    {
        angle8 += 6.28318;
    }

    if (q <= angle8 && angle8 <= a7)
    {

        float mag5 = sqrt(x * x + y * y);

        BSString b(0);
        BSStringT_char_SPrintF(&b, "--- fx %f fy %f  --- Magnitude: %f ", x, y, mag5);
        Warning_005b5e40(b.m_data);

        if (f <= mag5 && mag5 <= p)
        {
            return true;
        }
    }
    return false;
}
