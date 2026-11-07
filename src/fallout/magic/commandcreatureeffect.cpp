
// src/fallout/magic/commandcreatureeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/commandcreatureeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_0080b3a0_Obj
{
    S_0080b3a0_Obj(int a, int b, int c);
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    int unk44;
};

struct S_0080b3a0
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0A();
    virtual void vf0B();
    virtual void vf0C();
    virtual void vf0D();
    virtual void vf0E();
    virtual void vf0F();
    virtual void vf10();
    virtual void vf44(S_0080b3a0_Obj* obj);
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    S_0080b3a0_Obj* CreateObject();
};

// Allocates an S_0080b3a0_Obj from unk28, unk8 and unkC, passes it to vf44, and returns it.
// @fnv 0x0080b3a0
S_0080b3a0_Obj* S_0080b3a0::CreateObject()
{
    S_0080b3a0_Obj* obj = new S_0080b3a0_Obj(unk28, unk8, unkC);
    vf44(obj);
    return obj;
}

struct SpawnedObject
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0A();
    virtual void vf0B();
    virtual void vf0C();
    virtual void vf0D();
    virtual void vf0E();
    virtual void vf0F();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1A();
    virtual void vf1B();
    virtual void vf1C();
    virtual void vf1D();
    virtual void vf1E();
    virtual void vf1F();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2A();
    virtual void vf2B();
    virtual void vf2C();
    virtual void vf2D();
    virtual void vf2E();
    virtual void vf2F();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf3A();
    virtual void vf3B();
    virtual void vf3C();
    virtual void vf3D();
    virtual void vf3E();
    virtual void vf3F();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf4A();
    virtual void vf4B();
    virtual void vf4C();
    virtual void vf4D();
    virtual void vf4E();
    virtual void vf4F();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf5A();
    virtual void vf5B();
    virtual void vf5C();
    virtual void vf5D();
    virtual void vf5E();
    virtual void vf5F();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf6A();
    virtual void vf6B();
    virtual void vf6C();
    virtual void vf6D();
    virtual void vf6E();
    virtual void vf6F();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf7A();
    virtual void vf7B();
    virtual void vf7C();
    virtual void vf7D();
    virtual void vf7E();
    virtual void vf7F();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual bool vf87();
    int unk4;
};

SpawnedObject* __fastcall FUN_00822b40(int p);
float __fastcall GetFloatAtOffset1C(void* self);
unsigned short __fastcall GetLevel_0087f9f0(SpawnedObject* obj);
bool __cdecl MagicFormulas_CheckTargetLevelMagnitude(unsigned short a, float b);

struct FUN_0080b450_cls
{
    bool CommandCreatureEffect_CheckTarget(int p);
    int unk0;
};

// @fnv 0x0080b450
// src: XBOX_PDB 0x0080b450
bool FUN_0080b450_cls::CommandCreatureEffect_CheckTarget(int p)
{
    SpawnedObject* a = p != 0 ? FUN_00822b40(p) : 0;
    SpawnedObject* b = (a != 0 && a->vf87()) ? a : 0;
    if (b == 0)
    {
        return false;
    }
    return MagicFormulas_CheckTargetLevelMagnitude(GetLevel_0087f9f0(b), GetFloatAtOffset1C(this));
}
