
// src/havok/physics/dynamics/constraint/bilateral/ballandsocket/hkpballandsocketconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/ballandsocket/hkpballandsocketconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d541f0_class
{
    void __thiscall hkpBallAndSocketConstraintData_setBodyToNotify(int index);
};

// @fnv 0x00d541f0
// src: HAVOK_LIB 0x00d541f0
void __thiscall FUN_00d541f0_class::hkpBallAndSocketConstraintData_setBodyToNotify(int aiBitIndex)
{
    *(reinterpret_cast<char*>(this) + 0x42) = 1 << aiBitIndex;
}

extern void* __cdecl hkpConstraintData_getConstraintInfoUtil(void* a, int b, int c);
struct hkpBallAndSocketConstraintData
{
    void* hkpStiffSpringConstraintData_getConstraintInfo_00d54210(int a);
};
// @fnv 0x00d54210
// src: HAVOK_LIB 0x00d54210
void* hkpBallAndSocketConstraintData::hkpStiffSpringConstraintData_getConstraintInfo_00d54210(int a)
{
    return hkpConstraintData_getConstraintInfoUtil((void*)((char*)this + 0x10), 0x38, a);
}

extern double DAT_0104e138;
struct FUN_00d54230_class
{
    void __thiscall hkpBallAndSocketConstraintData_getRuntimeInfo(char a, int* b);
};
// If a is zero and the float at offset 0x44 equals DAT_0104e138, writes 0 and 0 to b; otherwise writes 3 and 0x18.
// @fnv 0x00d54230
// src: HAVOK_LIB 0x00d54230
void __thiscall FUN_00d54230_class::hkpBallAndSocketConstraintData_getRuntimeInfo(char abCondition, int* pOut)
{
    if (!abCondition && *(float*)((char*)this + 0x44) == DAT_0104e138)
    {
        pOut[1] = 0;
        pOut[0] = 0;
    }
    else
    {
        pOut[1] = 3;
        pOut[0] = 0x18;
    }
}

struct FUN_00d541d0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    float unk44;
    void __thiscall hkpBallAndSocketConstraintData_setMaxLinearImpulse(float value);
};

// @fnv 0x00d541d0
// src: HAVOK_LIB 0x00d541d0
void FUN_00d541d0_class::hkpBallAndSocketConstraintData_setMaxLinearImpulse(float value)
{
    unk44 = value;
}

struct FUN_00d54200_class
{
    unsigned char __thiscall hkpBallAndSocketConstraintData_getNotifiedBodyIndex();
};
// @fnv 0x00d54200
// src: XBOX_PDB 0x00d54200
unsigned char FUN_00d54200_class::hkpBallAndSocketConstraintData_getNotifiedBodyIndex()
{
    return *(unsigned char*)((char*)this + 0x42) >> 1;
}

struct D54270Bool
{
    char m_cBooleanValue;

    D54270Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct D54270Object
{
    virtual D54270Bool hkpBallAndSocketConstraintData_isValid() const;
};

// @fnv 0x00d54270
// src: XBOX_PDB 0x00d54270
D54270Bool D54270Object::hkpBallAndSocketConstraintData_isValid() const
{
    return true;
}

struct FUN_00d541e0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    float unk44;

    float __thiscall hkpBallAndSocketConstraintData_getMaxLinearImpulse();
};

// @fnv 0x00d541e0
// src: XBOX_PDB 0x00d541e0
float __thiscall FUN_00d541e0_class::hkpBallAndSocketConstraintData_getMaxLinearImpulse()
{
    return unk44;
}

// @fnv 0x00d54280
// src: GUESS 0x00d54280 (confidence: high)
int __cdecl Object_ReturnZero_00d54280()
{
    return 0;
}
