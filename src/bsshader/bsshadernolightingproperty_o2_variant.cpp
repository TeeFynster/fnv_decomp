
// src/bsshader/bsshadernolightingproperty_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/bsshadernolightingproperty.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/bsshader/bsshadernolightingproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/bsshadernolightingproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00b6fa40_Link
{
    int unk00, unk04, unk08, unk0c;
    int unk10;
};
struct S_00b6fa40_Prop
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int unk1c;
    unsigned int unk20;
    int unk24, unk28, unk2c, unk30, unk34;
    int unk38;
    S_00b6fa40_Link* unk3c;
    void CopySourceValues(const float* f);
};
struct S_00b6fa40_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S_00b6fa40_Obj* v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
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
    S_00b6fa40_Obj** unka0;
    short unka4;
    unsigned short unka6;
    S_00b6fa40_Prop* FUN_00a59d30(int mode);
};

static inline int IsLighting(S_00b6fa40_Prop* p)
{
    if (!p)
        return 0;
    return p->unk1c == 0x15;
}

// @fnv 0x00b6fa40
// src: XBOX_PDB 0x00b6fa40
void __cdecl BSShaderNoLightingProperty_SetFalloffRecurse(S_00b6fa40_Obj* obj, const float* pf)
{
    if (!obj)
        return;
    if (obj->v7())
    {
        S_00b6fa40_Prop* p = obj->FUN_00a59d30(3);
        if (!IsLighting(p))
            return;
        if (*pf != -1.0f)
        {
            if (!((char)p->unk20 & 0x40))
            {
                p->unk38 = 0;
            }
            p->unk20 |= 0x40;
            p->CopySourceValues(pf);
        }
        else
        {
            if ((char)p->unk20 & 0x40)
            {
                p->unk38 = 0;
            }
            p->unk20 &= ~0x40;
        }
        if (p->unk3c)
        {
            p->unk3c->unk10 = 0;
        }
        return;
    }
    S_00b6fa40_Obj* n = obj->v3();
    if (n)
    {
        unsigned int count = n->unka6;
        for (unsigned int i = 0; i < count; i++)
        {
            S_00b6fa40_Obj* c = n->unka0[i];
            if (c)
            {
                BSShaderNoLightingProperty_SetFalloffRecurse(c, pf);
            }
        }
    }
}
