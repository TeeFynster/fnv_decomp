
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpconstraintdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpconstraintdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV_VEC4_SIMD
#include "../../../../../../../../../include/Vec4.h"

struct ResetField
{
    void __thiscall return_input_and_0_it_1();
};
struct EmbeddedState
{
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
};
struct FUN_00de4470_class
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    int unk18;
    float unk1C;
    EmbeddedState state;
    ResetField reset;
    void* __thiscall InitializeDefaults();
};
// Resets the embedded state, then sets the float fields to fixed values and unk18 to 24, returning this.
// @fnv 0x00de4470
void* __thiscall FUN_00de4470_class::InitializeDefaults()
{
    reset.return_input_and_0_it_1();
    unk08 = 0.25f;
    unk18 = 24;
    unk04 = 0.75f;
    unk00 = 1.0f;
    unk0C = 1.0f;
    unk10 = 0.5f;
    unk14 = 0.25f;
    unk1C = 1.0f;
    return this;
}

struct DE44C0Display
{
    void UpdateState_00e10bf0(const Vec4* a, const Vec4* b, float radius, unsigned int color, int id,
                      int tag);
};

struct DE44C0Object
{
    int unk00;
    int unk04;
    float m_vScale;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    float m_fSphereRadius;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    Vec4 m_vFirstVector;
    Vec4 m_vSecondVector;
    Vec4 m_dirA;
    Vec4 unk70;
    Vec4 unk80;
    Vec4 m_dirB;
    Vec4 unkA0;
    Vec4 unkB0;
    DE44C0Display m_display;

    float getScaledRadius() const
    {
        return m_fSphereRadius * m_vScale;
    }
    void hkpConstraintDrawer_drawPivots(int id, int tag);
};

// @fnv 0x00de44c0
// src: HAVOK_LIB 0x00de44c0
void DE44C0Object::hkpConstraintDrawer_drawPivots(int id, int tag)
{
    m_display.UpdateState_00e10bf0(&m_vFirstVector, &m_dirA, getScaledRadius(), 0xffff0000, id, tag);
    m_display.UpdateState_00e10bf0(&m_vSecondVector, &m_dirB, getScaledRadius(), 0xffffffff, id, tag);
}

struct FUN_00de4780_cls
{
    float m_fValue;

    void SetValue_00de4780(float afValue);
};

// @fnv 0x00de4780
// src: GUESS 0x00de4780 (confidence: medium)
void FUN_00de4780_cls::SetValue_00de4780(float afValue)
{
    m_fValue = afValue;
}

struct FUN_00de4790_Class
{
    int unk00;
    float value04;
    void SetValue04(float value);
};
// @fnv 0x00de4790
// src: GUESS 0x00de4790 (confidence: low)
void FUN_00de4790_Class::SetValue04(float value)
{
    value04 = value;
}

struct DE47B0Object
{
    int unk00;
    int unk04;
    float m_uiFilterValue;

    void SetFilterValue(float value);
};

// @fnv 0x00de47b0
// src: GUESS 0x00de47b0 (confidence: low)
void DE47B0Object::SetFilterValue(float value)
{
    m_uiFilterValue = value;
}

struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    float value;
    void SetValue_00de47c0(float input);
};
// @fnv 0x00de47c0
// src: GUESS 0x00de47c0 (confidence: medium)
void CpuObject::SetValue_00de47c0(float input)
{
    value = input;
}

struct FUN_00de47d0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float m_fValue;
    void hkpConstraintDrawer_setScale(float afValue);
};

// @fnv 0x00de47d0
// src: COMMUNITY 0x00de47d0
void FUN_00de47d0_cls::hkpConstraintDrawer_setScale(float afValue)
{
    m_fValue = afValue;
}

struct FUN_00de47a0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_18;

    void SetField18_00de47a0(unsigned int value);
};

// @fnv 0x00de47a0
// src: GUESS 0x00de47a0 (confidence: low)
void FUN_00de47a0_cls::SetField18_00de47a0(unsigned int value)
{
    m_18 = value;
}

extern float DAT_01016248;

unsigned int PackColorBigEndian(float r, float g, float b, float a);

struct Struct00e10d50
{
    void ComputeValues_00e10d50(const void* origin, const Vec4* from, const Vec4* to, unsigned int color, float width, int arg6,
                      int arg7);
};

struct FUN_00de4530Owner
{
    int unk00;
    int unk04;
    int unk08;
    float unk0c;
    int unk10;
    int unk14;
    int unk18;
    float unk1c;
    Vec4 unk20;
    Vec4 unk30;
    Vec4 unk40;
    Vec4 unk50;
    Vec4 unk60;
    Vec4 unk70;
    Vec4 unk80;
    Vec4 unk90;
    Vec4 unka0;
    Vec4 unkb0;
    Struct00e10d50 unkc0;

    void hkpConstraintDrawer_drawBodyFrames(int arg1, int arg2);
};

// Draws two triangles as six lines through unkc0.FUN_00e10d50, with width unk1c * unk0c * 0.2 and fixed or PackColorBigEndian colors.
// @fnv 0x00de4530
// src: COMMUNITY 0x00de4530
void FUN_00de4530Owner::hkpConstraintDrawer_drawBodyFrames(int arg1, int arg2)
{
    unsigned int color1 = PackColorBigEndian(1.0f, 1.0f, 0.0f, 1.0f);
    unsigned int color2 = PackColorBigEndian(1.0f, DAT_01016248, 0.0f, 1.0f);
    unsigned int color3 = PackColorBigEndian(1.0f, 0.0f, 1.0f, 1.0f);

    Vec4 a0;
    Vec4 a1;
    Vec4 a2;
    Vec4 b0;
    Vec4 b1;
    Vec4 b2;
    *(__m128*)&a0 = *(const __m128*)&unk60;
    *(__m128*)&a1 = *(const __m128*)&unk70;
    *(__m128*)&a2 = *(const __m128*)&unk80;
    *(__m128*)&b0 = *(const __m128*)&unk90;
    *(__m128*)&b1 = *(const __m128*)&unka0;
    *(__m128*)&b2 = *(const __m128*)&unkb0;

    float width;
    width = unk1c * unk0c;
    width = width * (double)0.2f;
    unkc0.ComputeValues_00e10d50(&unk20, &a0, &a1, 0xffff0000, width, arg1, arg2);
    width = unk1c * unk0c;
    width = width * (double)0.2f;
    unkc0.ComputeValues_00e10d50(&unk20, &a1, &a2, 0xff008000, width, arg1, arg2);
    width = unk1c * unk0c;
    width = width * (double)0.2f;
    unkc0.ComputeValues_00e10d50(&unk20, &a2, &a0, 0xff0000ff, width, arg1, arg2);
    width = unk1c * unk0c;
    width = width * (double)0.2f;
    unkc0.ComputeValues_00e10d50(&unk30, &b0, &b1, color1, width, arg1, arg2);
    width = unk1c * unk0c;
    width = width * (double)0.2f;
    unkc0.ComputeValues_00e10d50(&unk30, &b1, &b2, color2, width, arg1, arg2);
    width = unk1c * unk0c;
    width = width * (double)0.2f;
    unkc0.ComputeValues_00e10d50(&unk30, &b2, &b0, color3, width, arg1, arg2);
}

class FUN_00de47e0_cls
{
  public:
    void hkpConstraintDrawer_updateCommonParameters(char* a1, __m128* a2, __m128* a3);
};

// Copies 16-byte blocks from two objects at offset 0xf0 into a2 and a3, then stores them into this object at scattered offsets.
// @fnv 0x00de47e0
// src: COMMUNITY 0x00de47e0
void FUN_00de47e0_cls::hkpConstraintDrawer_updateCommonParameters(char* a1, __m128* apOutA, __m128* apOutB)
{
    char* pFirst = *(char**)(a1 + 0x18);
    char* pSecond = *(char**)(a1 + 0x14);
    __m128* pSrcA = (__m128*)(pFirst + 0xf0);
    apOutA[0] = pSrcA[0];
    apOutA[1] = pSrcA[1];
    apOutA[2] = pSrcA[2];
    apOutA[3] = pSrcA[3];
    __m128* pSrcB = (__m128*)(pSecond + 0xf0);
    apOutB[0] = pSrcB[0];
    apOutB[1] = pSrcB[1];
    apOutB[2] = pSrcB[2];
    apOutB[3] = pSrcB[3];
    *(__m128*)((char*)this + 0x90) = apOutA[0];
    *(__m128*)((char*)this + 0xa0) = apOutA[1];
    *(__m128*)((char*)this + 0xb0) = apOutA[2];
    *(__m128*)((char*)this + 0x60) = apOutB[0];
    *(__m128*)((char*)this + 0x70) = apOutB[1];
    *(__m128*)((char*)this + 0x80) = apOutB[2];
    *(__m128*)((char*)this + 0x30) = apOutA[3];
    *(__m128*)((char*)this + 0x20) = apOutB[3];
}
