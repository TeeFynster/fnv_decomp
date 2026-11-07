
// src/bsshader/imagespaceeffectmap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffectmap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_Dst
{
    void FUN_00b8a790(int a, float b, float c, float d, float e);
};
struct S_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual unsigned int v94();
    virtual unsigned int v98();
};
struct S_Src
{
    S_Obj* ImageSpaceTexture_GetTexture();
};
struct S_Mid
{
    int unk0;
    S_Src* m4;
};
struct S_00baa330_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S_Dst** m1c;
    int unk20;
    int unk24;
    int unk28;
    S_Mid* m2c;
    bool ImageSpaceEffectMap_UpdateParams(int a);
};

// @fnv 0x00baa330
// src: COMMUNITY 0x00baa330
bool S_00baa330_Cls::ImageSpaceEffectMap_UpdateParams(int aiUnused)
{
    S_Dst* dst = *m1c;
    S_Obj* pObj = m2c->m4->ImageSpaceTexture_GetTexture();
    dst->FUN_00b8a790(0, 1.0f / (float)pObj->v94(), 1.0f / (float)pObj->v98(), 0.0f, 0.0f);
    return true;
}

struct Mid08_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int m_c0;
};

struct MemMgr_cls
{
    int unk00;
    void* Game_DoHeapAlloc(unsigned int size);
};

extern MemMgr_cls DAT_011f6238;

struct FUN_00b8a9e0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;

    FUN_00b8a9e0();
    static void* operator new(unsigned int size) throw()
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
    void FUN_00b8ab10(int a1, int a2);
    void FUN_00b8a790(int a1, float f0, float f1, float f2, float f3);
    void FUN_00b8a8d0(int a1, int a2);
};

struct Sub18_cls
{
    void* vtable;
    FUN_00b8a9e0** data;
    unsigned short capacity;
    unsigned short size;
    unsigned short effectiveSize;
    unsigned short growBy;
    void FUN_00ba3aa0(int index, FUN_00b8a9e0* const& value);
};

struct Sub28_cls
{
    int unk00;
    void FUN_00a90180(int a1);
};

struct FUN_00baa240_cls
{
    int unk00;
    int unk04;
    Mid08_cls* m_08;
    int unk0c;
    int unk10;
    int unk14;
    Sub18_cls m_18;
    Sub28_cls m_28;

    void SetTextureArraySize(int a1);
    void SetEffectParamAt(int a1, int a2, int a3);
    void FUN_00ba3c70(int a1, int a2, FUN_00b8a9e0* a3, int a4);
    void Initialize(FUN_00baa240_cls* a1, int a2);
};

// @fnv 0x00baa240
void FUN_00baa240_cls::Initialize(FUN_00baa240_cls* a1, int aiArg)
{
    SetTextureArraySize(1);
    m_28.FUN_00a90180(2);
    FUN_00b8a9e0* obj = new FUN_00b8a9e0();
    obj->FUN_00b8ab10(0, 1);
    obj->FUN_00b8a790(0, 1.0f, 1.0f, 1.0f, 1.0f);
    obj->FUN_00b8a8d0(0xa8, 0xf);
    {
        FUN_00b8a9e0* toStore = obj;
        m_18.FUN_00ba3aa0(0, toStore);
    }
    SetEffectParamAt(0, 1, 0);
    FUN_00ba3c70(0, a1->m_08->m_c0, obj, 0);
}
