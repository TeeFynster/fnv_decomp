// src/bsshader/bsshadernolightingproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/bsshadernolightingproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ArgObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual int GetCount();
};

struct ScopedRef
{
    int unk00;

    ScopedRef(ArgObject* apArg);
    ~ScopedRef();
};

struct Sub24Object
{
    void NiAVObject_AttachProperty_00439fd0(ScopedRef* apRef);
};

struct FUN_00439410_cls
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
    Sub24Object m_k24;

    void NiAVObject_AttachProperty(ArgObject* apArg);
};

// If apArg's count is below 7, constructs a ScopedRef from apArg and passes it to m_k24.FUN_00439fd0.
// @fnv 0x00439410
// src: XBOX_PDB 0x00439410
void FUN_00439410_cls::NiAVObject_AttachProperty(ArgObject* apArg)
{
    if (apArg->GetCount() < 7)
    {
        ScopedRef ref(apArg);
        m_k24.NiAVObject_AttachProperty_00439fd0(&ref);
    }
}
