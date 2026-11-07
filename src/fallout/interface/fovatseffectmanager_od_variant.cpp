
// src/fallout/interface/fovatseffectmanager_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/interface/fovatseffectmanager.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

extern unsigned __int64 selected_target_masks[43];
#include "../../../include/ImageSpaceManager.h"
#include "../../../include/NiPoint3.h"
// The shared manager supplies NiPoint3; skip the legacy dependency copy.
#define FNV_NIPOINT3_H
#pragma optimize("", off)
#include "fovatseffectmanager_perks.h"
void ApplyPerkModifiers(int entryPoint, Actor* actor, ...);
#include "fovatseffectmanager_effects.h"
#include "../../../include/FOVATSEffectManager.h"

struct Struct801420
{
    int f0;
    void FOVATSEffectManager_DrawTarget(unsigned char a, int b);
    void FOVATSEffectManager_DrawSingleTarget(unsigned char a, int b);
    void FOVATSEffectManager_DrawMultipleTargets();
};
// @fnv 0x00801420
// src: COMMUNITY 0x00801420
void Struct801420::FOVATSEffectManager_DrawTarget(unsigned char a, int b)
{
    if (f0 == 0)
        FOVATSEffectManager_DrawSingleTarget(a, b);
    else
        FOVATSEffectManager_DrawMultipleTargets();
}

extern "C" unsigned char __cdecl Interface_GetIsVATSRescanning();

// Retained with this unit's FOVATSEffectManager stand-ins: the shared header lacks
// FUN_00801420, FUN_00801450, FUN_00801880, FUN_00800f30 and OnIdle's helper methods.

// @fnv 0x00801a60
// src: COMMUNITY 0x00801a60
void FOVATSEffectManager::PrepareEffect(int a, int b, int c, unsigned char d)
{
    if (Interface_GetIsVATSRescanning())
        return;
    if (reinterpret_cast<unsigned char*>(this)[0x129])
    {
        if (reinterpret_cast<unsigned char*>(this)[0x2b4])
        {
            PrepareScanEffect(a, b, c, d);
        }
        else
        {
            FOVATSEffectManager_PrepareHighlightEffect(a, b, c, d);
        }
    }
}

class ImageSpaceEffect
{
public:
    virtual void FUN_00000000();
    virtual void FUN_00000004();
    virtual void FUN_00000008();
    virtual void FUN_0000000C();
    virtual void FUN_00000010();
    virtual void Play();
    void SetFormType(int);
};

extern int DAT_012007fc;

// @fnv 0x008019d0
// src: COMMUNITY 0x008019d0
void FOVATSEffectManager::VATSEffect_ShutdownEffect()
{
    ImageSpaceManager::BSShaderManager_GetImageSpaceManager()->GetEffect_004ebbc0(0x0A)->SetFormType(0);
    ImageSpaceManager::BSShaderManager_GetImageSpaceManager()->GetEffect_004ebbc0(0x0B)->SetFormType(0);
    ImageSpaceManager::BSShaderManager_GetImageSpaceManager()->GetEffect_004ebbc0(0x0A)->Play();
    ImageSpaceManager::BSShaderManager_GetImageSpaceManager()->GetEffect_004ebbc0(0x0B)->Play();
    DAT_012007fc = 0;
}

struct NiAVObject;

struct RefLike
{
    unsigned int GetFlags();
};

struct FormLike
{
    unsigned int hkpCollidable_getCollisionFilterInfo();
};

struct NodeLike
{
    int hkpRigidBody_getPosition();
};

struct FilterLike
{
    int CFilter_GetGroup();
};

struct FilterHolder
{
    int val;
    FilterHolder(int a);
    int CFilter_GetGroup();
};

struct CellLike
{
    unsigned int NiAVObject_GetParent();
};

struct TESLike
{
    CellLike* TES_GetLandGeometry(NiPoint3* pos);
};

struct ExtraLike
{
    unsigned int bhkWorldObject_GetAVObject(int a);
};

extern TESLike* g_TES;

void* hkpGetRigidBody(const void* p);
void* hkpGetPhantom(const void* p);
RefLike* FUN_004b5a20(void* p);
void FUN_00458620(NiPoint3* out, int v);
void* bhkUtilFunctions_IsbhkPCollisionObject(NiAVObject* p);
void* bhkEntity_Getbhk(const void* p);

// @fnv 0x004b5820
// src: XBOX_PDB 0x004b5820
unsigned int GetAVObjectForCollidable(FormLike* form)
{
    unsigned int result5 = 0;
    if (form)
    {
        void* node_ = hkpGetRigidBody(form);
        void* objTmp = !node_ ? hkpGetPhantom(form) : 0;
        if (node_)
        {
            RefLike* ref = FUN_004b5a20(node_);
            if (ref)
            {
                result5 = ref->GetFlags();
            }
            else if (FilterHolder(form->hkpCollidable_getCollisionFilterInfo()).CFilter_GetGroup() == 1)
            {
                NiPoint3 pos4;
                FUN_00458620(&pos4, ((NodeLike*)node_)->hkpRigidBody_getPosition());
                CellLike* cellA = g_TES->TES_GetLandGeometry(&pos4);
                if (cellA && cellA->NiAVObject_GetParent())
                {
                    result5 = cellA->NiAVObject_GetParent();
                }
            }
        }
        else
        {
            RefLike* ref2 = (RefLike*)bhkUtilFunctions_IsbhkPCollisionObject((NiAVObject*)objTmp);
            if (ref2)
            {
                result5 = ref2->GetFlags();
            }
            if (!result5)
            {
                ExtraLike* extra5 = (ExtraLike*)bhkEntity_Getbhk(objTmp);
                if (extra5)
                {
                    result5 = extra5->bhkWorldObject_GetAVObject(0);
                }
            }
        }
    }
    return result5;
}

struct VQueryObj
{
    ~VQueryObj();
    unsigned char BSOcclusionQuery_GetResult(unsigned int* result, int wait);
};

struct VRenderer
{
    void NiXenonRenderer_LockRenderer();
    void NiXenonRenderer_UnlockRenderer();
};
VRenderer* __cdecl NiXenonRenderer_GetRenderer();

struct VTimeGlobal
{
    unsigned int FUN_00825c00();
};
extern VTimeGlobal g_timeGlobal;

struct VTarget
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual void v224();
    virtual void v228();
    virtual bool v22c(int a);
};

struct VNodePtr
{
    void* ptr;
    operator void*() const;
};

void __cdecl VDebugPrint(const char* fmt, ...);

struct VATSEffectStub
{
    int state;
    VTarget* target;
    VNodePtr node;
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    unsigned char unk118;
    unsigned char pending[16];
    unsigned char unk129;
    unsigned char unk12a;
    unsigned char unk12b;
    VQueryObj* queriesB[16];
    VQueryObj* queriesA[16];
    unsigned char done[16];
    unsigned int resultA[16];
    unsigned int resultB[16];
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    unsigned char unk284;
    unsigned char unk285;
    unsigned char unk286;
    unsigned char unk287;
    int unk288;
    int unk28c;
    int unk290;
    float unk294;
    unsigned char unk298;
    unsigned char unk299;
    unsigned char unk29a;
    unsigned char unk29b;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    unsigned char unk2b4;
    unsigned char unk2b5;
    unsigned char unk2b6;
    unsigned char unk2b7;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    unsigned int unk2c8;

    void FOVATSEffectManager_OnIdle();
    void FOVATSEffectManager_TriggerDistort();
    void FOVATSEffectManager_UpdateBurst(float t);
    void SetScaledValues(float t);
    void FOVATSEffectManager_UpdateTargetPulse(float t);
    void UpdateProgress(float t);
    void FOVATSEffectManager_UpdateScan(float t);
    void FOVATSEffectManager_SetTarget(int a, int b, int c);
};

// @fnv 0x00800370
// src: COMMUNITY 0x00800370
void VATSEffectStub::FOVATSEffectManager_OnIdle()
{
    if (!node)
    {
        unk2b4 = 0;
        unk2b5 = 0;
        return;
    }
    float time = (float)g_timeGlobal.FUN_00825c00();
    if (unk2b4)
    {
        FOVATSEffectManager_UpdateScan(time);
    }
    else
    {
        if (unk284)
        {
            UpdateProgress(time);
        }
        else if (time > unk294)
        {
            FOVATSEffectManager_TriggerDistort();
        }
        SetScaledValues(time);
        if (state == 1 && unk10 != -1)
        {
            FOVATSEffectManager_UpdateTargetPulse(time);
        }
    }
    if (unk298)
    {
        FOVATSEffectManager_UpdateBurst(time);
    }
    if (target && target->v22c(0))
    {
        FOVATSEffectManager_SetTarget(0, -1, 0);
    }
    VDebugPrint("====== VATSEffectOnIdle ======");
    for (unsigned int i = 0; i < 16; i++)
    {
        if (node && queriesA[i] && queriesB[i])
        {
            NiXenonRenderer_GetRenderer()->NiXenonRenderer_LockRenderer();
            unsigned int a;
            unsigned int b;
            if (queriesA[i]->BSOcclusionQuery_GetResult(&a, 1) && queriesB[i]->BSOcclusionQuery_GetResult(&b, 1) && !done[i])
            {
                delete queriesA[i];
                queriesA[i] = 0;
                delete queriesB[i];
                queriesB[i] = 0;
                done[i] = 1;
                pending[i] = 0;
                resultA[i] = a;
                resultB[i] = b * unk2c8;
            }
            NiXenonRenderer_GetRenderer()->NiXenonRenderer_UnlockRenderer();
        }
    }
}

struct Str8
{
    int p;
    int len;
    operator const char*() const;
};
struct Renderer
{
    void M4e9bb0(void* anim);
};
Renderer* GetRenderer();
struct AnimData
{
    void* M45bbe0();
};
struct Obj
{
    void M4a0fd0(const char* s);
    void M41fd00(AnimData* a);
    void Ma694a0(void* p);
};
struct FaceNode
{
    Obj* M8d80e0();
    AnimData* GetAnimationData();
};
FaceNode* GetFacialAnimationNode();
void __cdecl SetFlag(const char* s, int f, int on);
void __cdecl ApplyAnim(AnimData* a, const char* s, Obj* o);
void __cdecl ApplyAnim2(AnimData* a, const char* s, int z);
struct S801880
{
    int unk00;
    int unk04;
    int unk08;
    int count;
    int selected;
    int unk14;
    Str8 names[80];
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    Str8 name;
    void FOVATSEffectManager_DrawMultipleTargets();
};

// @fnv 0x00801880
// src: COMMUNITY 0x00801880
void S801880::FOVATSEffectManager_DrawMultipleTargets()
{
    if (this->count > 0)
    {
        Renderer* renderer = GetRenderer();
        FaceNode* node5 = GetFacialAnimationNode();
        int unk5 = this->unk04;
        Obj* objTmp = node5->M8d80e0();
        objTmp->M4a0fd0(this->name);
        AnimData* anim = node5->GetAnimationData();
        GetRenderer()->M4e9bb0(anim);
        objTmp->M41fd00(anim);
        objTmp->Ma694a0(anim->M45bbe0());
        bool found6 = false;
        const char* sel3 = 0;
        for (int i4 = 0; i4 < this->count; i4++)
        {
            const char* s4 = this->names[i4];
            if (i4 == this->selected)
            {
                SetFlag(s4, 0x31, 1);
                sel3 = s4;
                found6 = true;
            }
            ApplyAnim(anim, s4, objTmp);
        }
        ApplyAnim2(anim, this->name, 0);
        objTmp->M4a0fd0(0);
        if (found6)
            SetFlag(sel3, 0x31, 0);
    }
}

struct Vec4Tmp_00801ad0
{
    unsigned int d0;
    unsigned int d1;
    unsigned int d2;
    unsigned int d3;
    void FUN_00414430(float a, float b, float c, float d);
};

struct Holder_00801ad0
{
    float* Setting_Float_00403e20();
};

struct Obj719_00801ad0
{
    void FUN_00719060();
};

struct Obj6e5_00801ad0
{
    void FUN_006e5cc0(void* p);
};

struct Obj0664_00801ad0
{
    void FUN_0066b0d0(void* p);
};

// 0x004bc320 selects a rendered texture (also bound by imagespacetexture and watershader), not an Actor method.
struct RenderedTextureSource
{
    void* BSRenderedTexture_GetTexture(int a);
};

extern Holder_00801ad0 DAT_011db7b4;
extern Holder_00801ad0 DAT_011db694;
extern int DAT_01201f40;
extern int DAT_01201f44;
extern unsigned int DAT_01201f30;
extern unsigned int DAT_01201f34;
extern unsigned int DAT_01201f38;
extern unsigned int DAT_01201f3c;
extern float DAT_01201f2c;
extern float DAT_011ae614;
extern float DAT_011ae618;

Obj719_00801ad0* __stdcall SystemColorManager_GetInstance(int, Vec4Tmp_00801ad0*);

// @fnv 0x00801ad0
// src: COMMUNITY 0x00801ad0
void FOVATSEffectManager::PrepareScanEffect(int a0, int a1, int a2, unsigned char a3)
{
    Vec4Tmp_00801ad0 tmp;
    tmp.FUN_00414430(0.0f, 0.0f, 0.0f, 0.0f);
    SystemColorManager_GetInstance(1, &tmp)->FUN_00719060();
    DAT_01201f2c = *(float*)((char*)this + 0x2bc);
    DAT_011ae614 = *DAT_011db7b4.Setting_Float_00403e20();
    DAT_011ae618 = *DAT_011db694.Setting_Float_00403e20();
    DAT_01201f30 = tmp.d0;
    DAT_01201f34 = tmp.d1;
    DAT_01201f38 = tmp.d2;
    DAT_01201f3c = tmp.d3;
    ((Obj6e5_00801ad0*)&DAT_01201f40)->FUN_006e5cc0((char*)this + 0x2c4);
    ((Obj0664_00801ad0*)&DAT_01201f44)->FUN_0066b0d0(((RenderedTextureSource*)a1)->BSRenderedTexture_GetTexture(0));
    ImageSpaceManager::BSShaderManager_GetImageSpaceManager()->GetEffect_004ebbc0(0xb)->SetFormType(1);
}

struct FUN_00414430
{
    float r, g, b, a;
    FUN_00414430(float, float, float, float);
};
struct ExtraRefraction
{
    int unk00, unk04, unk08;
    float amount;
};
struct ExtraListRender
{
    ExtraRefraction* GetRefractionProperty();
};
struct RenderActor
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsActor();
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
    virtual void v224();
    virtual void v228();
    virtual bool IsHidden(int);
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void AssignActorValue(int, float);
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual float GetRefraction();
    ExtraListRender* BSFile_GetDevice();
};
struct RenderDevice
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void SetColor(FUN_00414430*);
    virtual void v0b0();
    virtual void GetColor(FUN_00414430*);
};
struct FUN_004a4410
{
    int handle;
    ~FUN_004a4410();
    void BSOcclusionQuery_Begin();
    void BSOcclusionQuery_End();
};
struct FUN_00c4ecf0
{
    int handle;
    FUN_00c4ecf0();
};
struct RenderAccumulator
{
    void FUN_004a1040(int);
};
struct AccumulatorPtr
{
    RenderAccumulator* value;
    RenderAccumulator* Modelloader_GetReferencedThis();
};
struct RenderTexture
{
    void* FUN_00b6b260();
};
extern unsigned char DAT_01200bf6, DAT_011fd86c;
extern Actor* DAT_011dea3c;
bool BSRenderedTexture_IsOutsideFrame();
void BSRenderedTexture_StartOffscreen(int, void*);
void FUN_00b6b790();
void FUN_00b4f450(int);
void Warning_005b5e40(const char*);
struct VATSRender : VATSEffectStub
{
    AccumulatorPtr accumulator;
    void FOVATSEffectManager_DrawTarget(unsigned char, int);
    void FOVATSEffectManager_DrawTargetToTexture(RenderTexture*, int, unsigned char, int, int, unsigned char);
};
// @fnv 0x00800f30
// src: COMMUNITY 0x00800f30
void VATSRender::FOVATSEffectManager_DrawTargetToTexture(RenderTexture* texture, int mode, unsigned char draw, int flags, int view,
                              unsigned char finish)
{
    if (((RenderActor*)target)->IsHidden(0))
        return;
    RenderDevice* restore = (RenderDevice*)NiXenonRenderer_GetRenderer();
    FUN_00414430 enabled(0.0f, 0.0f, 0.0f, 0.0f);
    restore->GetColor(&enabled);
    restore->SetColor(&FUN_00414430(0.0f, 0.0f, 0.0f, 0.0f));
    if (BSRenderedTexture_IsOutsideFrame())
        BSRenderedTexture_StartOffscreen(view, texture->FUN_00b6b260());
    DAT_01200bf6 = 1;
    DAT_011fd86c = 1;
    unsigned char refraction;
    unsigned char extra = unk118;
    refraction = 0;
    RenderActor* saved = ((RenderActor*)target)->IsActor() ? (RenderActor*)target : 0;
    float perk = saved ? saved->GetRefraction() : 1.0f;
    unsigned char actor;
    ExtraRefraction* amount = 0;
    float renderer = 0.0f;
    ApplyPerkModifiers(0x45, DAT_011dea3c, &renderer);
    if (saved && saved->BSFile_GetDevice() && renderer > 0.0)
        amount = saved->BSFile_GetDevice()->GetRefractionProperty();
    actor = 0;
    float issued = 0.0f;
    if (amount && saved)
    {
        issued = amount->amount;
        actor = 1;
        saved->AssignActorValue(0, 0.0f);
    }
    if (extra)
    {
        if (mode == 2)
        {
            if (queriesB[unk23c])
                delete (FUN_004a4410*)queriesB[unk23c];
            queriesB[unk23c] = (VQueryObj*)new FUN_00c4ecf0;
            refraction = 1;
            ((FUN_004a4410*)queriesB[unk23c])->BSOcclusionQuery_Begin();
        }
        else if (mode == 1)
        {
            if (queriesA[unk23c])
                delete (FUN_004a4410*)queriesA[unk23c];
            queriesA[unk23c] = (VQueryObj*)new FUN_00c4ecf0;
            refraction = 1;
            ((FUN_004a4410*)queriesA[unk23c])->BSOcclusionQuery_Begin();
        }
    }
    accumulator.Modelloader_GetReferencedThis()->FUN_004a1040(8);
    FUN_00b4f450(8);
    FOVATSEffectManager_DrawTarget(draw, flags);
    FUN_00b4f450(0);
    accumulator.Modelloader_GetReferencedThis()->FUN_004a1040(0);
    if (refraction)
    {
        if (mode == 2)
        {
            if (queriesB[unk23c])
            {
                ((FUN_004a4410*)queriesB[unk23c])->BSOcclusionQuery_End();
                pending[unk23c] = 1;
            }
            else
                Warning_005b5e40("pPartialLimbQuery is NULL even though we just issued one.  This should be impossible.");
        }
        else if (mode == 1)
        {
            if (queriesA[unk23c])
                ((FUN_004a4410*)queriesA[unk23c])->BSOcclusionQuery_End();
            else
                Warning_005b5e40("pEntireLimbQuery is NULL even though we just issued one.  This should be impossible.");
        }
    }
    if (finish)
        FUN_00b6b790();
    if (actor && saved)
        saved->AssignActorValue(1, issued);
    DAT_01200bf6 = 0;
    DAT_011fd86c = 0;
    restore->SetColor(&enabled);
}

extern Holder_00801ad0 DAT_011db6e4;
extern Holder_00801ad0 DAT_011db79c;
extern Holder_00801ad0 DAT_011db714;
extern Holder_00801ad0 DAT_011db720;
extern Holder_00801ad0 DAT_011db778;
extern Obj0664_00801ad0 DAT_01200818;
extern Obj6e5_00801ad0 DAT_01200810;
extern Vec4Tmp_00801ad0 DAT_01200800;
extern float DAT_012007f0, DAT_012007f4, DAT_012007e8;
extern unsigned char DAT_012007f8;
extern int DAT_012007ec;
extern float DAT_011ae5f8, DAT_011ae5ec, DAT_011ae5e8;
extern float DAT_011ae5fc, DAT_011ae5f0, DAT_011ae5f4;
extern const float DAT_01012054;
struct EffectModeSetup
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    bool enabled;
    unsigned char unk285;
    unsigned char unk286;
    unsigned char unk287;
    int unk288;
    float value28c;
    int unk290;
    int unk294;
    bool scaled;
    unsigned char unk299;
    unsigned char unk29a;
    unsigned char unk29b;
    int unk29c;
    int unk2a0;
    int unk2a4;
    float value2a8;
    float value2ac;
    float value2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    float value2c0;
    int unk2c4;
    void FOVATSEffectManager_PrepareHighlightEffect(int, RenderedTextureSource*, int, unsigned char);
};
// @fnv 0x00801bb0
// src: COMMUNITY 0x00801bb0
void EffectModeSetup::FOVATSEffectManager_PrepareHighlightEffect(int unused, RenderedTextureSource* actor, int unused2, unsigned char flag)
{
    Vec4Tmp_00801ad0 vector;
    vector.FUN_00414430(0.0f, 0.0f, 0.0f, 0.0f);
    SystemColorManager_GetInstance(1, &vector)->FUN_00719060();
    DAT_012007fc = 1;
    ImageSpaceManager::BSShaderManager_GetImageSpaceManager()->GetEffect_004ebbc0(10)->SetFormType(1);
    DAT_01200818.FUN_0066b0d0(actor->BSRenderedTexture_GetTexture(0));
    if (enabled)
    {
        DAT_012007f0 = *DAT_011db6e4.Setting_Float_00403e20();
        DAT_011ae5f8 = *DAT_011db79c.Setting_Float_00403e20();
        DAT_012007f4 = value28c;
        DAT_012007f8 = 0;
    }
    else
    {
        DAT_012007f0 = 0.0f;
        DAT_011ae5f8 = 0.0f;
        DAT_012007f4 = DAT_01012054;
    }
    DAT_012007e8 = 0.0f;
    DAT_01200810.FUN_006e5cc0(&unk2c4);
    DAT_01200800 = vector;
    DAT_011ae5ec = *DAT_011db714.Setting_Float_00403e20();
    DAT_011ae5e8 = *DAT_011db720.Setting_Float_00403e20();
    DAT_011ae5ec += value2ac;
    DAT_011ae5e8 += value2b0;
    if (scaled)
    {
        DAT_011ae5ec *= 1.0f + value2a8 * 0.5;
        DAT_011ae5e8 *= 1.0f + value2a8;
    }
    DAT_011ae5fc = value2c0;
    DAT_011ae5f0 = *DAT_011db778.Setting_Float_00403e20();
    DAT_011ae5f4 = 1.0f;
    DAT_012007ec = flag ? 1 : 0;
}

struct Obj9
{
    bool GetAppCulled_00456610();
    void FUN_00450f90(int);
    int SkyObject_GetNiNode();
};
struct Mid9
{
    Obj9* GetValueByIndex(int);
};
struct PtrObj9
{
    PtrObj9(int);
    ~PtrObj9();
    int v;
};
struct Wrap9
{
    PtrObj9* p;
    Wrap9(PtrObj9* q) : p(q)
    {}
};
struct Inner9
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void* vt9c(int);
};
struct Node9
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtbl050();
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual void vtbl063();
    virtual void vtbl064();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual Mid9* vt180();
};
struct Mgr9
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtbl050();
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual void vtbl063();
    virtual void vtbl064();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual void vtbl096();
    virtual void vtbl097();
    virtual void vtbl098();
    virtual void vtbl099();
    virtual Obj9* vt190(int);
};
struct Actor9
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtbl050();
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual void vtbl063();
    virtual bool vt100();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual void vtbl096();
    virtual void vtbl097();
    virtual void vtbl098();
    virtual void vtbl099();
    virtual void vtbl100();
    virtual void vtbl101();
    virtual void vtbl102();
    virtual void vtbl103();
    virtual void vtbl104();
    virtual void vtbl105();
    virtual void vtbl106();
    virtual void vtbl107();
    virtual void vtbl108();
    virtual void vtbl109();
    virtual void vtbl110();
    virtual void vtbl111();
    virtual void vtbl112();
    virtual void vtbl113();
    virtual void vtbl114();
    virtual void vtbl115();
    virtual Inner9* vt1d0();
    virtual void vtbl117();
    virtual void vtbl118();
    virtual void vtbl119();
    virtual void vtbl120();
    virtual void vtbl121();
    virtual int vt1e8();
    Mgr9* FUN_008d8520();
    Node9* FUN_004181e0();
};

struct Svc9
{
};
struct X10
{
    void BSCullingProcess_SetAccumulator(int);
    void SetImpactDataSet_004fb0b0(int);
};
struct Sub9
{
    int v;
    int Modelloader_GetReferencedThis();
};
struct P2Obj
{
    X10* FUN_008d80e0();
    Svc9* FUN_006629f0();
};
struct This9
{
    int state;
    Actor9* actor;
    Sub9 sub08;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    unsigned char unk128;
    unsigned char b129;
    unsigned char unk12a;
    unsigned char unk12b;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int f23c;
    int f240;
    int arr244[8];
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    unsigned char b2b4;
    unsigned char unk2b5;
    unsigned char unk2b6;
    unsigned char unk2b7;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    Sub9 sub2cc;
    void UpdateEquipmentVisibility();
    void FOVATSEffectManager_RestoreBodyParts();
};
P2Obj* __cdecl Main_GetWorldSceneGraph();
void __cdecl BSShaderUtil_AccumulateScene(Svc9*, void*, X10*);
void __cdecl FUN_00b6c0d0(Svc9*, int, int);

// @fnv 0x00801450
// src: COMMUNITY 0x00801450
void Struct801420::FOVATSEffectManager_DrawSingleTarget(unsigned char a, int b)
{
    if (((This9*)this)->actor)
    {
        if ((((This9*)this)->b129 && !(((This9*)this)->b2b4) || a) && b != 1)
            ((This9*)this)->UpdateEquipmentVisibility();
        VRenderer* ptr12 = NiXenonRenderer_GetRenderer();
        P2Obj* q23 = Main_GetWorldSceneGraph();
        Actor9* actor_ = ((This9*)this)->actor;
        X10* x102 = q23->FUN_008d80e0();
        x102->BSCullingProcess_SetAccumulator(((This9*)this)->sub2cc.Modelloader_GetReferencedThis());
        x102->SetImpactDataSet_004fb0b0(1);
        Svc9* svcX = q23->FUN_006629f0();
        Mgr9* mgr2X = 0;
        Obj9* o1z = 0;
        if (((This9*)this)->actor->vt100())
            mgr2X = actor_->FUN_008d8520();
        if (mgr2X)
            o1z = mgr2X->vt190(actor_->vt1e8());
        if (((This9*)this)->f23c == 0xe || b == 1)
        {
            if (((This9*)this)->actor->vt100())
            {
                if (!(((This9*)this)->b2b4) || a)
                {
                    if (o1z && mgr2X)
                        BSShaderUtil_AccumulateScene(svcX, o1z, x102);
                }
            }
        }
        if (((This9*)this)->f23c != 0xe || b == 1)
        {
            bool flag_ = 0;
            if (o1z)
            {
                flag_ = !o1z->GetAppCulled_00456610();
                o1z->FUN_00450f90(1);
            }
            BSShaderUtil_AccumulateScene(svcX, (void*)((This9*)this)->sub08.Modelloader_GetReferencedThis(), x102);
            if (((This9*)this)->actor->vt100())
            {
                Actor9* formA = ((This9*)this)->actor;
                Mid9* xmidX = formA->FUN_004181e0()->vt180();
                Obj9* rAX = xmidX->GetValueByIndex(((This9*)this)->f23c);
                void* res3cA;
                if (rAX)
                {
                    res3cA = formA->vt1d0()->vt9c((int)&PtrObj9(rAX->SkyObject_GetNiNode()));
                    if (res3cA)
                        BSShaderUtil_AccumulateScene(svcX, res3cA, x102);
                }
                if (((This9*)this)->f240 > 0)
                {
                    for (int i = 0; i < ((This9*)this)->f240; i++)
                    {
                        Mid9* m3A = formA->FUN_004181e0()->vt180();
                        Obj9* ares44C = m3A->GetValueByIndex(((This9*)this)->arr244[i]);
                        void* res4c_;
                        if (ares44C)
                        {
                            res4c_ = formA->vt1d0()->vt9c((int)&PtrObj9(ares44C->SkyObject_GetNiNode()));
                            if (res4c_)
                                BSShaderUtil_AccumulateScene(svcX, res4c_, x102);
                        }
                    }
                }
            }
            if (o1z && flag_)
                o1z->FUN_00450f90(0);
        }
        FUN_00b6c0d0(svcX, ((This9*)this)->sub2cc.Modelloader_GetReferencedThis(), 0);
        x102->BSCullingProcess_SetAccumulator(0);
        x102->SetImpactDataSet_004fb0b0(0);
        if ((((This9*)this)->b129 && !(((This9*)this)->b2b4) || a) && b != 1)
            ((This9*)this)->FOVATSEffectManager_RestoreBodyParts();
        (void)ptr12;
    }
}
