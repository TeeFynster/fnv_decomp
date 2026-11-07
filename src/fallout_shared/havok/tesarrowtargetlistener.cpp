
// src/fallout_shared/havok/tesarrowtargetlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/tesarrowtargetlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Obj;
extern Obj DAT_011e0e80;
extern int DAT_012681c0;

struct Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual bool v224();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int MaskWithField(int a);
    Obj* Bipedanim_GetReferenceFlagsOrZero();
    Obj* FUN_0044ddc0();
    unsigned int ProcessArray_GetProcessLevelTail(int a);
    Obj* ProcessArray_GetItem(unsigned int i);
    bool Projectile_IsFlagSet(int a);
    int FUN_00401170();
    Obj* GetNodeItem();
    int MissileProjectile_GetImpactResult();
    void Projectile_Kill();
    Obj* FUN_00717e50();
};

Obj* bhkEntity_Getbhk(int a);
Obj* NiObject_DynamicCast(int* dat, Obj* o_tmp);
Obj* FUN_004b5a20(Obj* o_tmp);
int TESObjectREFR_FindReferenceFor3D(Obj* o_tmp);

struct FUN_0062a510_cls
{
    void TESArrowTargetListener_entityRemovedCallback(int a1);
};

// @fnv 0x0062a510
// src: XBOX_PDB 0x0062a510
void FUN_0062a510_cls::TESArrowTargetListener_entityRemovedCallback(int a1)
{
    Obj* o_tmp = bhkEntity_Getbhk(a1);
    Obj* p = NiObject_DynamicCast(&DAT_012681c0, o_tmp);
    if (p != 0 && p->MaskWithField(0x100) != 0)
    {
        Obj* m_tmp = FUN_004b5a20(p->Bipedanim_GetReferenceFlagsOrZero());
        Obj* r = (m_tmp != 0) ? m_tmp->FUN_0044ddc0() : 0;
        int g_tmp = TESObjectREFR_FindReferenceFor3D(r);
        Obj* t = DAT_011e0e80.FUN_00717e50();
        for (unsigned int i = 0; i < t->ProcessArray_GetProcessLevelTail(0); ++i)
        {
            Obj* e = t->ProcessArray_GetItem(i);
            if (e != 0)
            {
                if (e->v224())
                {
                    Obj* u = e;
                    if (u != 0)
                    {
                        if (u->Projectile_IsFlagSet(0x80))
                        {
                            if (u->FUN_00401170() == 0x3d)
                            {
                                if (((int)u->FUN_0044ddc0() & 0x20) == 0)
                                {
                                    Obj* v = u->GetNodeItem();
                                    if (v->unk1c == a1)
                                    {
                                        if (u->MissileProjectile_GetImpactResult() == 4)
                                        {
                                            u->Projectile_Kill();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

struct UnknownBlock
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct ListNodeHelper
{
    void* item;
    void** FUN_006815c0();
};
struct Owner_0062a670
{
    UnknownBlock prefix00;
    UnknownBlock prefix10;
    UnknownBlock prefix20;
    UnknownBlock prefix30;
    UnknownBlock prefix40;
    UnknownBlock prefix50;
    UnknownBlock prefix60;
    UnknownBlock prefix70;
    unsigned int unk80, unk84;
    ListNodeHelper node;
    void* GetNodeItem();
};
// @fnv 0x0062a670
void* Owner_0062a670::GetNodeItem()
{
    return *node.FUN_006815c0();
}

namespace fnv_0062a690 {
struct S_0062a690_Extra
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct S_0062a690_Actor
{
    virtual void unk_000();
    virtual void unk_001();
    virtual void unk_002();
    virtual void unk_003();
    virtual void unk_004();
    virtual void unk_005();
    virtual void unk_006();
    virtual void unk_007();
    virtual void unk_008();
    virtual void unk_009();
    virtual void unk_010();
    virtual void unk_011();
    virtual void unk_012();
    virtual void unk_013();
    virtual void unk_014();
    virtual void unk_015();
    virtual void unk_016();
    virtual void unk_017();
    virtual void unk_018();
    virtual void unk_019();
    virtual void unk_020();
    virtual void unk_021();
    virtual void unk_022();
    virtual void unk_023();
    virtual void unk_024();
    virtual void unk_025();
    virtual void unk_026();
    virtual void unk_027();
    virtual void unk_028();
    virtual void unk_029();
    virtual void unk_030();
    virtual void unk_031();
    virtual void unk_032();
    virtual void unk_033();
    virtual void unk_034();
    virtual void unk_035();
    virtual void unk_036();
    virtual void unk_037();
    virtual void unk_038();
    virtual void unk_039();
    virtual void unk_040();
    virtual void unk_041();
    virtual void unk_042();
    virtual void unk_043();
    virtual void unk_044();
    virtual void unk_045();
    virtual void unk_046();
    virtual void unk_047();
    virtual void unk_048();
    virtual void unk_049();
    virtual void unk_050();
    virtual void unk_051();
    virtual void unk_052();
    virtual void unk_053();
    virtual void unk_054();
    virtual void unk_055();
    virtual void unk_056();
    virtual void unk_057();
    virtual void unk_058();
    virtual void unk_059();
    virtual void unk_060();
    virtual void unk_061();
    virtual void unk_062();
    virtual void unk_063();
    virtual void unk_064();
    virtual void unk_065();
    virtual void unk_066();
    virtual void unk_067();
    virtual void unk_068();
    virtual void unk_069();
    virtual void unk_070();
    virtual void unk_071();
    virtual void unk_072();
    virtual void unk_073();
    virtual void unk_074();
    virtual void unk_075();
    virtual void unk_076();
    virtual void unk_077();
    virtual void unk_078();
    virtual void unk_079();
    virtual void unk_080();
    virtual void unk_081();
    virtual void unk_082();
    virtual void unk_083();
    virtual void unk_084();
    virtual void unk_085();
    virtual void unk_086();
    virtual void unk_087();
    virtual void unk_088();
    virtual void unk_089();
    virtual void unk_090();
    virtual void unk_091();
    virtual void unk_092();
    virtual void unk_093();
    virtual void unk_094();
    virtual void unk_095();
    virtual void unk_096();
    virtual void unk_097();
    virtual void unk_098();
    virtual void unk_099();
    virtual void unk_100();
    virtual void unk_101();
    virtual void unk_102();
    virtual void unk_103();
    virtual void unk_104();
    virtual void unk_105();
    virtual void unk_106();
    virtual void unk_107();
    virtual void unk_108();
    virtual void unk_109();
    virtual void unk_110();
    virtual void unk_111();
    virtual void unk_112();
    virtual void unk_113();
    virtual void unk_114();
    virtual void unk_115();
    virtual void unk_116();
    virtual void unk_117();
    virtual void unk_118();
    virtual void unk_119();
    virtual void unk_120();
    virtual void unk_121();
    virtual void unk_122();
    virtual void unk_123();
    virtual void unk_124();
    virtual void unk_125();
    virtual void unk_126();
    virtual void unk_127();
    virtual void unk_128();
    virtual void unk_129();
    virtual void unk_130();
    virtual void unk_131();
    virtual void unk_132();
    virtual void unk_133();
    virtual void unk_134();
    virtual void unk_135();
    virtual void unk_136();
    virtual bool vfn_0224();

    bool __thiscall Projectile_IsFlagSet(unsigned int flag);
    unsigned int __thiscall FUN_00401170();
    S_0062a690_Extra* __thiscall GetNodeItem();
    int __thiscall MissileProjectile_GetImpactResult();
    void __thiscall Projectile_Kill();
};

struct S_0062a690_ProcessArray
{
    unsigned int __thiscall ProcessArray_GetProcessLevelTail(int param);
    S_0062a690_Actor* __thiscall ProcessArray_GetItem(unsigned int idx);
};

struct S_0062a690_ProcessLists
{
    S_0062a690_ProcessArray* __thiscall FUN_00717e50();
};

extern S_0062a690_ProcessLists DAT_011e0e80;
extern int DAT_012681c0;

struct S_0062a690_A
{
    int __thiscall MaskWithField(unsigned int flag);
    void* __thiscall Bipedanim_GetReferenceFlagsOrZero();
};

struct S_0062a690_B
{
    void* __thiscall FUN_0044ddc0();
};

void* __cdecl bhkEntity_Getbhk(int id);
S_0062a690_A* __cdecl NiObject_DynamicCast(void* rtti, void* obj);
S_0062a690_B* __cdecl FUN_004b5a20(void* p);
void* __cdecl TESObjectREFR_FindReferenceFor3D(void* p);

struct S_0062a690_Class
{
    void TESArrowTargetListener_entityDeletedCallback(int arg0);
};

// @fnv 0x0062a690
// src: XBOX_PDB 0x0062a690
void S_0062a690_Class::TESArrowTargetListener_entityDeletedCallback(int arg0)
{
    void* v_08 = bhkEntity_Getbhk(arg0);
    S_0062a690_A* v_04 = NiObject_DynamicCast(&DAT_012681c0, v_08);
    if (v_04 && v_04->MaskWithField(0x100))
    {
        S_0062a690_B* v_18 = FUN_004b5a20(v_04->Bipedanim_GetReferenceFlagsOrZero());
        void* ptr = v_18 ? v_18->FUN_0044ddc0() : 0;
        void* v_0c = TESObjectREFR_FindReferenceFor3D(ptr);
        S_0062a690_ProcessArray* v_14 = DAT_011e0e80.FUN_00717e50();

        for (unsigned int v_1c = 0; v_1c < v_14->ProcessArray_GetProcessLevelTail(0); v_1c++)
        {
            S_0062a690_Actor* v_20 = v_14->ProcessArray_GetItem(v_1c);
            if (v_20 && v_20->vfn_0224())
            {
                S_0062a690_Actor* v_24 = v_20;
                if (v_24 && v_24->Projectile_IsFlagSet(0x80) && v_24->FUN_00401170() == 0x3d)
                {
                    S_0062a690_Extra* v_28 = v_24->GetNodeItem();
                    if (v_28->unk1c == arg0 && v_24->MissileProjectile_GetImpactResult() == 4)
                    {
                        v_24->Projectile_Kill();
                    }
                }
            }
        }
    }
}
}  // namespace fnv_0062a690
