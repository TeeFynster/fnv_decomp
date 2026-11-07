#include "../../../../include/Actor.h"
#include "../../../../include/BeamProjectile.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiGeometry.h"
#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiTriShape.h"
#include "../../../../include/TESGrass.h"
#include "../../../../include/EffectSetting.h"
#include "../../../../include/Script.h"
#include "../../../../include/Setting.h"
#include "../../../../include/BSSoundHandle.h"

// src/fallout/ai/combat/beamprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/beamprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00978ed0
// src: COMMUNITY 0x00978ed0
void Projectile::SetActorCause_00978ed0(ActorCause* apCause)
{
    m_pActorCause.operator=(apCause);
}

// @fnv 0x00979260
float Projectile::GetFirstLightParameter()
{
    return fImpulseRadiusSquared;
}

// @fnv 0x009795c0
// src: XBOX_PDB 0x009795c0
void BeamProjectile::Projectile_SetRange(float value)
{
    fImpulseRadiusSquared = value;
}

// @fnv 0x009abf10
// src: COMMUNITY 0x009abf10
void BeamProjectile::RevertBGS_009abf10(BGSLoadFormBuffer* apLoadGameBuffer)
{
    Projectile::RevertBGS_009c58e0(apLoadGameBuffer);
}

void BeamProjectile::LoadProjectile(BGSLoadFormBuffer* apLoadGameBuffer)
{}

// @fnv 0x009b4cf0
// src: XBOX_PDB 0x009b4cf0
void BeamProjectile::LoadGame_009b4cf0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    LoadProjectile(apLoadGameBuffer);
}

// @fnv 0x009bab00
// src: COMMUNITY 0x009bab00
void BeamProjectile::InitLoadGame_009bab00(BGSLoadFormBuffer* apBuffer)
{
    Projectile::InitLoadGame(apBuffer);
}

// @fnv 0x00979bb0
// src: XBOX_PDB 0x00979bb0
void BeamProjectile::SaveGame_00979bb0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    SaveProjectile(apSaveGameBuffer);
}

// Projectile.h lacks FUN_009c5870; this load helper still needs its local declaration.
struct S5870_Holder
{
    void Projectile_FinishLoadGame(BGSLoadFormBuffer*);
};
// @fnv 0x009abef0
// src: XBOX_PDB 0x009abef0
void BeamProjectile::FinishLoadGame_009abef0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((S5870_Holder*)this)->Projectile_FinishLoadGame(apLoadGameBuffer);
}

bool __cdecl NiObject_IsKindOf(NiRTTI const*, NiAVObject*);
extern const NiRTTI g_01202680_arg1;
extern const NiRTTI g_01202538_arg1;
extern const NiRTTI g_01202508;
extern NiPoint3 NiPoint3_ZERO;
struct FUN_004d7d50_StandIn
{
    unsigned int NiParticleSystem_GetModifierCount();
    NiAVObject* GetByIndex(unsigned int i);
};
struct CtlV
{
    CtlV* GetNext() const;
};

struct BeamCtl
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
    virtual bool v23();
};
// Trivial vertex storage preserves the original raw copies without invoking vector constructors.
struct BeamVertex
{
    float x, y, z;
};

struct GeometryVertexBuffer
{
    int a, b, c;
    GeometryVertexBuffer();
    void NiGeometryDataIteratorNiPoint3_Get(unsigned int, NiPoint3&);
    void SetVertex(unsigned int, NiPoint3 const&);
};
struct FUN_0047d370_shell
{
    unsigned short FUN_0047d370();
};
struct BeamPair
{
    float a, b;
};
// Scales a NiAVObject's bound radius and center by scale, then scales child effect or geometry vertex data depending on the object's type.
// @fnv 0x009795e0
// src: COMMUNITY 0x009795e0
void BeamProjectile::ScaleBeamGeometryLength(NiAVObject* apObject, float scale)
{
    if (apObject)
    {
        ((NiTriShape*)apObject)->GetSourceFilesFromForm()->m_fRadius *= scale;
        ((NiTriShape*)apObject)->GetSourceFilesFromForm()->m_kCenter.ScaleComponents(scale);
        NiGeometryData* data = ((NiGeometry*)apObject)->GetModelData();
        if (data)
        {
            if (NiObject_IsKindOf(&g_01202680_arg1, (NiAVObject*)data))
            {
                if (NiObject_IsKindOf(&g_01202538_arg1, apObject))
                {
                    FUN_004d7d50_StandIn* node = (FUN_004d7d50_StandIn*)apObject;
                    for (unsigned int i = 0; i < node->NiParticleSystem_GetModifierCount(); i++)
                    {
                        NiAVObject* child = node->GetByIndex(i);
                        if (NiObject_IsKindOf(&g_01202508, child))
                        {
                            TESGrass* effect = (TESGrass*)child;
                            ((EffectSetting*)effect)->BSShaderProperty_SetDepthBias(effect->TESGrass::GetLowestAllowedSlope() * scale);
                        }
                    }
                }
            }
            else if (((CtlV*)data)->GetNext() && ((BeamCtl*)((CtlV*)data)->GetNext())->v23())
            {
                GeometryVertexBuffer vertexMap;
                {
                    FUN_0047d370_shell* ctl = (FUN_0047d370_shell*)((CtlV*)data)->GetNext();
                    if (data->IsGeometryDataStreamable(true))
                    {
                        data->NiGeometryData_GetVerticesIterator(vertexMap);
                        for (int iVertex = 0; iVertex < ctl->FUN_0047d370(); iVertex++)
                        {
                            BeamVertex vertex = *(const BeamVertex*)&NiPoint3_ZERO;
                            vertexMap.NiGeometryDataIteratorNiPoint3_Get(iVertex, (NiPoint3&)vertex);
                            vertex.y *= scale;
                            vertexMap.SetVertex(iVertex, (const NiPoint3&)vertex);
                        }
                        data->NiGeometryData_UnlockPackedVertexData();
                    }
                }
            }
            else if (data->GetVertices())
            {
                for (int k = 0; k < ((const NiGeometryData*)data)->GetVertexCount(); k++)
                {
                    data->GetVertices()[k].y *= scale;
                    ((BeamPair*)((Script*)data)->GetText())[k].b *= scale;
                }
            }
        }
    }
}

struct FUN_005de0a0_shell
{
    void Projectile_SetFlag(int, int);
};
struct FUN_009bda10_shell : FUN_005de0a0_shell
{
    void Projectile_Initialize();
};
struct FUN_005bfbd0_Class
{
    void FOHUDEffectManager_SetBlurIntensityHUD(float);
};
struct TargetObject : FUN_005bfbd0_Class
{
};
struct HandleField
{
    operator TargetObject*();
};
// @fnv 0x00979280
// src: XBOX_PDB 0x00979280
void __thiscall BeamProjectile::Initialize_00979280()
{
    ((FUN_005de0a0_shell*)this)->Projectile_SetFlag(0x10, 0);
    ((FUN_005de0a0_shell*)this)->Projectile_SetFlag(1, 1);
    ((FUN_005de0a0_shell*)this)->Projectile_SetFlag(2, 0);
    ((FUN_005de0a0_shell*)this)->Projectile_SetFlag(8, 1);
    ((FUN_005de0a0_shell*)this)->Projectile_SetFlag(0x20, 1);
    ((FUN_005de0a0_shell*)this)->Projectile_SetFlag(0x100, 1);
    ((FUN_005de0a0_shell*)this)->Projectile_SetFlag(0x80, 1);
    ((FUN_005de0a0_shell*)this)->Projectile_SetFlag(0x2000, 1);
    ((FUN_009bda10_shell*)this)->Projectile_Initialize();
    if (*(HandleField*)((char*)this + 0x150))
    {
        ((TargetObject*)*(HandleField*)((char*)this + 0x150))->FOHUDEffectManager_SetBlurIntensityHUD(GetFirstLightParameter());
    }
}

struct Descriptor
{
};
struct Form
{
    int FUN_00401170();
};
struct Reference
{
    Descriptor* TESSound_GetFilename(int);
};
struct Base
{
    bool GetCanTurnOff();
    Reference* CombatController_GetCombatState();
};
struct SoundManager
{
    BSSoundHandle BSAudio_GetSoundHandleByFilename(Descriptor*, Reference*);
};
SoundManager* BSAudio_QInstance();
struct Controller
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual void method52();
    virtual void method53();
    virtual void method54();
    virtual void method55();
    virtual void method56();
    virtual void method57();
    virtual void method58();
    virtual void method59();
    virtual void method60();
    virtual void method61();
    virtual void method62();
    virtual void method63();
    virtual void method64();
    virtual void method65();
    virtual void method66();
    virtual void method67();
    virtual void method68();
    virtual void method69();
    virtual void method70();
    virtual void method71();
    virtual void method72();
    virtual void method73();
    virtual void method74();
    virtual void method75();
    virtual void method76();
    virtual void method77();
    virtual void method78();
    virtual void method79();
    virtual void method80();
    virtual void method81();
    virtual void method82();
    virtual void method83();
    virtual void method84();
    virtual void method85();
    virtual void method86();
    virtual void method87();
    virtual void method88();
    virtual void method89();
    virtual void method90();
    virtual void method91();
    virtual void method92();
    virtual void method93();
    virtual void method94();
    virtual void method95();
    virtual void method96();
    virtual void method97();
    virtual void method98();
    virtual void method99();
    virtual void method100();
    virtual void method101();
    virtual void method102();
    virtual void method103();
    virtual void method104();
    virtual void method105();
    virtual void method106();
    virtual void method107();
    virtual void method108();
    virtual void method109();
    virtual void method110();
    virtual void method111();
    virtual void method112();
    virtual void method113();
    virtual void method114();
    virtual void method115();
    virtual void method116();
    virtual void method117();
    virtual void method118();
    virtual void method119();
    virtual void method120();
    virtual void method121();
    virtual void method122();
    virtual void method123();
    virtual void method124();
    virtual void method125();
    virtual void method126();
    virtual void method127();
    virtual void method128();
    virtual void method129();
    virtual void method130();
    virtual void method131();
    virtual void method132();
    virtual void method133();
    virtual void method134();
    virtual void method135();
    virtual void method136();
    virtual void method137();
    virtual void method138();
    virtual void method139();
    virtual void method140();
    virtual void method141();
    virtual void method142();
    virtual void method143();
    virtual void method144();
    virtual void method145();
    virtual void method146();
    virtual void method147();
    virtual void method148();
    virtual void method149();
    virtual void method150();
    virtual void method151();
    virtual void method152();
    virtual void method153();
    virtual void method154();
    virtual void method155();
    virtual void method156();
    virtual void method157();
    virtual void method158();
    virtual void method159();
    virtual void method160();
    virtual void method161();
    virtual void method162();
    virtual void method163();
    virtual void method164();
    virtual void method165();
    virtual void method166();
    virtual void method167();
    virtual void method168();
    virtual void method169();
    virtual void method170();
    virtual void method171();
    virtual void method172();
    virtual void method173();
    virtual void method174();
    virtual void method175();
    virtual void method176();
    virtual void method177();
    virtual void method178();
    virtual void method179();
    virtual void method180();
    virtual void method181();
    virtual void method182();
    virtual void method183();
    virtual void method184();
    virtual void method185();
    virtual void method186();
    virtual void method187();
    virtual void method188();
    virtual void method189();
    virtual void method190();
    virtual void method191();
    virtual void method192();
    virtual void method193();
    virtual void method194();
    virtual void method195();
    virtual void method196();
    virtual void method197();
    virtual void method198();
    virtual void method199();
    virtual void method200();
    virtual void method201();
    virtual void method202();
    virtual void method203();
    virtual void method204();
    virtual void method205();
    virtual void method206();
    virtual void method207();
    virtual void method208();
    virtual void method209();
    virtual void method210();
    virtual void method211();
    virtual void method212();
    virtual void method213();
    virtual void method214();
    virtual void method215();
    virtual void method216();
    virtual void method217();
    virtual void method218();
    virtual void method219();
    virtual void method220();
    virtual void method221();
    virtual void method222();
    virtual void method223();
    virtual void method224();
    virtual void method225();
    virtual void method226();
    virtual void method227();
    virtual void method228();
    virtual void method229();
    virtual void method230();
    virtual void method231();
    virtual void method232();
    virtual void method233();
    virtual void method234();
    virtual void method235();
    virtual void method236();
    virtual void method237();
    virtual void method238();
    virtual void method239();
    virtual void method240();
    virtual void method241();
    virtual void method242();
    virtual void method243();
    virtual void method244();
    virtual void method245();
    virtual void method246();
    virtual void method247();
    virtual void method248();
    virtual void method249();
    virtual void method250();
    virtual void method251();
    virtual void method252();
    virtual void method253();
    virtual void method254();
    virtual void method255();
    virtual void method256();
    virtual void method257();
    virtual void method258();
    virtual void method259();
    virtual void method260();
    virtual void method261();
    virtual void method262();
    virtual void method263();
    virtual void method264();
    virtual void method265();
    virtual void method266();
    virtual void method267();
    virtual void method268();
    virtual void method269();
    virtual void method270();
    virtual void method271();
    virtual void method272();
    virtual void method273();
    virtual void method274();
    virtual void method275();
    virtual void method276();
    virtual void method277();
    virtual void method278();
    virtual void method279();
    virtual void method280();
    virtual void method281();
    virtual void method282();
    virtual void method283();
    virtual void method284();
    virtual void method285();
    virtual void method286();
    virtual void method287();
    virtual void method288();
    virtual void method289();
    virtual void Action(int);
};
extern Controller* DAT_011dea3c;
extern Setting DAT_011cecdc;
void FUN_004d5c60(int);
struct BeamEffect
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual void method52();
    virtual void method53();
    virtual void method54();
    virtual void method55();
    virtual void method56();
    virtual void method57();
    virtual void method58();
    virtual void method59();
    virtual void method60();
    virtual void method61();
    virtual void method62();
    virtual void method63();
    virtual void method64();
    virtual void method65();
    virtual void method66();
    virtual void method67();
    virtual void method68();
    virtual void method69();
    virtual void method70();
    virtual void method71();
    virtual void method72();
    virtual void method73();
    virtual void method74();
    virtual void method75();
    virtual void method76();
    virtual void method77();
    virtual void method78();
    virtual void method79();
    virtual void method80();
    virtual void method81();
    virtual void method82();
    virtual void method83();
    virtual void method84();
    virtual void method85();
    virtual void method86();
    virtual void method87();
    virtual void method88();
    virtual void method89();
    virtual void method90();
    virtual void method91();
    virtual void method92();
    virtual void method93();
    virtual void method94();
    virtual void method95();
    virtual void method96();
    virtual void method97();
    virtual void method98();
    virtual void method99();
    virtual void method100();
    virtual void method101();
    virtual void method102();
    virtual void method103();
    virtual void method104();
    virtual void method105();
    virtual void method106();
    virtual void method107();
    virtual void method108();
    virtual void method109();
    virtual void method110();
    virtual void method111();
    virtual void method112();
    virtual void method113();
    virtual void method114();
    virtual void method115();
    virtual void method116();
    virtual void method117();
    virtual void method118();
    virtual void method119();
    virtual void method120();
    virtual void method121();
    virtual void method122();
    virtual void method123();
    virtual void method124();
    virtual const NiPoint3& GetScene();
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
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    float lifetime;
    int unkE8, unkEC, unkF0, unkF4, unkF8;
    Actor* actor;
    Base* FUN_004181e0();
    bool Projectile_IsFlagSet(int);
    void StopSound();
    void Projectile_SetFlag(int, bool);
    Form* TESObjectREFR_GetOwner();
    bool IsFightReactionAllowed(int, Actor*, Form*);
    bool Projectile_DisarmPlacedExplosives(int, bool);
};
// @fnv 0x009c43e0
// src: COMMUNITY 0x009c43e0
bool BeamEffect::Projectile_DisarmPlacedExplosives(int value, bool silent)
{
    bool result = false;
    if (FUN_004181e0()->GetCanTurnOff() && !Projectile_IsFlagSet(0x200))
    {
        StopSound();
        if (!silent)
        {
            Reference* owner = FUN_004181e0()->CombatController_GetCombatState();
            if (owner)
            {
                BSSoundHandle sound = BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(owner->TESSound_GetFilename(0x4102), owner);
                sound.SetPosition(GetScene());
                sound.Play(false);
            }
        }
        Projectile_SetFlag(0x200, true);
        {
            Form* container;
            {
                Actor* shooter = 0;
                container = 0;
                if (actor && actor->IsActor())
                    shooter = actor;
                else
                {
                    Form* parent = TESObjectREFR_GetOwner();
                    if (parent)
                    {
                        int iParentType = parent->FUN_00401170();
                        if (iParentType == 8)
                            container = parent;
                    }
                }
                if (!silent &&
                    (lifetime != 3.4028234663852886e+38 || IsFightReactionAllowed(value, shooter, container)))
                {
                    FUN_004d5c60(11);
                    if (*DAT_011cecdc.Setting_Int() > 0)
                        DAT_011dea3c->Action(*DAT_011cecdc.Setting_Int());
                }
            }
        }
        result = true;
    }
    return result;
}

struct S_00979140_Mat3
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    S_00979140_Mat3 FUN_004b45b0() const;
    S_00979140_Mat3 FUN_0043f8d0(const S_00979140_Mat3& other) const;
};

struct S_00979140_UpdateData
{
    float unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    S_00979140_UpdateData(float time, bool a, bool b);
};

struct S_00979140_Node
{
    virtual ~S_00979140_Node();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vfb8(S_00979140_UpdateData* data);
    const S_00979140_Mat3& NiAVObject_GetWorldRotate() const;
};

struct S_00979140_Holder
{
    virtual ~S_00979140_Holder();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual S_00979140_Node* vf20c();
};


// @fnv 0x00979140
// src: COMMUNITY 0x00979140
void BeamProjectile::Process3D()
{
    S_00979140_Node* node2 = (S_00979140_Node*)GetNiNode();
    if (node2)
    {
        S_00979140_Node* other = ((Actor*)this)->Projectile_GetShooter() ? ((S_00979140_Holder*)((Actor*)this)->Projectile_GetShooter())->vf20c() : 0;
        if (other)
        {
            S_00979140_UpdateData data(0.0f, false, false);
            node2->vfb8(&data);
            *(S_00979140_Mat3*)&m_kImpactTransform = ((S_00979140_Node*)GetNiNode())->NiAVObject_GetWorldRotate().FUN_0043f8d0(other->NiAVObject_GetWorldRotate().FUN_004b45b0());
        }
        float t2 = GetFirstLightParameter();
        if (t2 < 1.0)
            t2 = 1.0f;
        ScaleNode((NiAVObject*)node2, t2, 0.0f);
    }
}

struct BeamHitHandler
{
    unsigned char ProcessHit(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6);
};

struct FUN_00979510_sub88
{
    unsigned char FUN_008256d0();
};
struct FUN_00979510_obj
{
    void* SubtractIntoVector(float* out, void* x);
};
struct FUN_00979510_res
{
    float FUN_00457990();
};
unsigned char CanProjectileHit(void* a1, void* a4, void* self, void* r);

// @fnv 0x00979510
// src: XBOX_PDB 0x00979510
unsigned char BeamProjectile::AddImpact(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6)
{
    unsigned int unk04;
    unsigned int unk08;
    float fOut;
    if (((FUN_00979510_sub88*)((char*)this + 0x88))->FUN_008256d0())
    {
        if (CanProjectileHit(a1, a4, this, this->FUN_004181e0()))
        {
            if (((BeamHitHandler*)this)->ProcessHit(a1, a2, a3, a4, a5, a6))
            {
                Projectile_SetRange(((FUN_00979510_res*)((FUN_00979510_obj*)a2)->SubtractIntoVector(&fOut, ((const BeamProjectile*)this)->GetPos()))
                                       ->FUN_00457990());
                return 1;
            }
        }
    }
    return 0;
}

struct Cursor
{
    float m_00;
    float m_04;
    float m_08;
    void NiTConvertingStrideIterator_NiTConvertingStrideIterator();
    void NiGeometryDataIteratorNiPoint3_Get(int index, BeamVertex* out);
};

struct Holder
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
    virtual bool v35();
    unsigned short FUN_0047d370();
};

extern char DAT_01202558;
extern char DAT_012024e0;
extern char DAT_01202508;
extern BeamVertex DAT_011f426c;

unsigned char __cdecl NiObject_IsKindOf(const void* typeDesc, const void* obj);


// @fnv 0x00979840
// src: COMMUNITY 0x00979840
float BeamProjectile::FindBeamGeometryLength(NiGeometry* arg)
{
    NiGeometryData* actor = arg->GetModelData();
    float best = 0.0f;
    if (actor != 0)
    {
        if (NiObject_IsKindOf(&DAT_01202558, actor))
        {
            if (NiObject_IsKindOf(&DAT_012024e0, arg))
            {
                FUN_004d7d50_StandIn* owner = (FUN_004d7d50_StandIn*)arg;
                for (unsigned int i = 0; best == 0.0f && i < owner->NiParticleSystem_GetModifierCount(); ++i)
                {
                    NiAVObject* item = owner->GetByIndex(i);
                    if (NiObject_IsKindOf(&DAT_01202508, item))
                    {
                        TESGrass* p = (TESGrass*)item;
                        best = p->TESGrass::GetLowestAllowedSlope();
                    }
                }
            }
        }
        else
        {
            if (((Holder*)((CtlV*)actor)->GetNext()) != 0 && ((Holder*)((CtlV*)actor)->GetNext())->v35())
            {
                {
                    Cursor c;
                    c.NiTConvertingStrideIterator_NiTConvertingStrideIterator();
                    Holder* bag = ((Holder*)((CtlV*)actor)->GetNext());
                    if (actor->IsGeometryDataStreamable(true))
                    {
                        for (int i = 0; i < bag->FUN_0047d370(); ++i)
                        {
                            BeamVertex vecTmp = DAT_011f426c;
                            actor->NiGeometryData_GetVerticesIterator((GeometryVertexBuffer&)c);
                            c.NiGeometryDataIteratorNiPoint3_Get(i, &vecTmp);
                            if (best < vecTmp.y)
                            {
                                best = vecTmp.y;
                            }
                        }
                        actor->NiGeometryData_UnlockPackedVertexData();
                    }
                }
            }
            else if (actor->GetVertices() != 0)
            {
                for (int k = 0; k < ((const NiGeometryData*)actor)->GetVertexCount(); ++k)
                {
                    BeamVertex vecEntry = DAT_011f426c;
                    vecEntry = ((BeamVertex*)actor->GetVertices())[k];
                    if (best < vecEntry.y)
                    {
                        best = vecEntry.y;
                    }
                }
            }
        }
    }
done:
    return best;
}

struct S_00979a70_Vec3
{
    float x, y, z;
    void ScaleComponents(float s);
};

struct S_00979a70_Obj;

struct S_00979a70_Group
{
    unsigned int FUN_0043b480();
    S_00979a70_Obj* FUN_0043b4a0(unsigned int index);
};

struct S_00979a70_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S_00979a70_Group* v3();
    S_00979a70_Vec3* GetTranslate_0043c490();
    void NiAVObject_SetTranslate(S_00979a70_Vec3* v);
};

extern int DAT_011f4acc;
extern const double DAT_01012060;
bool __cdecl NiObject_IsKindOf(const void* rtti, S_00979a70_Obj* obj);


// Scales node's vector by a/b when b exceeds DAT_01012060, then scales the node or recurses into its children.
// @fnv 0x00979a70
void BeamProjectile::ScaleNode(NiAVObject* node, float fScale, float fDivisor)
{
    if (node)
    {
        if (fDivisor > DAT_01012060)
        {
            float s = fScale / fDivisor;
            S_00979a70_Vec3 v = *((S_00979a70_Obj*)node)->GetTranslate_0043c490();
            v.ScaleComponents(s);
            ((S_00979a70_Obj*)node)->NiAVObject_SetTranslate(&v);
        }
        if (NiObject_IsKindOf(&DAT_011f4acc, (S_00979a70_Obj*)node))
        {
            S_00979a70_Obj* p = (S_00979a70_Obj*)node;
            float den = (fDivisor > DAT_01012060) ? fDivisor : FindBeamGeometryLength((NiAVObject*)p);
            if (den != DAT_01012060)
            {
                float r = fScale / den;
                ScaleBeamGeometryLength((NiAVObject*)p, r);
            }
        }
        else
        {
            S_00979a70_Group* n = ((S_00979a70_Obj*)node)->v3();
            if (n)
            {
                for (unsigned int i = 0; i < n->FUN_0043b480(); i++)
                {
                    S_00979a70_Obj* child = n->FUN_0043b4a0(i);
                    ScaleNode((NiAVObject*)child, fScale, fDivisor);
                }
            }
        }
    }
}

extern const double DAT_0108fdd0;

namespace std {
double abs(float);
}

struct S9b8b10_Sub88
{
    unsigned char FUN_008256d0();
};

struct S9b8b10_Manager
{
    void* FUN_00441110();
    void* BGSSaveFormBuffer_GetForm();
    void VATS_SetFirstProjectile(int);
    void SetValue(int);
};
extern S9b8b10_Manager DAT_011f2250;

struct FUN_009b8b10_cls
{
    unsigned char unk00[0x88];
    S9b8b10_Sub88 m_k88;
    unsigned char unk89[0x90 - 0x89];
    bool m_b90;
    unsigned char unk91[0x150 - 0x91];
    int m_i150;

    bool MissileProjectile_ProcessImpacts();
    bool Projectile_IsFlagSet(int);
    float GetFirstLightParameter();
    double Projectile_GetSpeed();
    double GetE0();
    float Projectile_GetDistanceMoved();
    bool ProcessHits();
    void Projectile_Kill();
    void HandleContactResponse();
    void ProcessImpale();
    void HandleMissileImpact();
};

// @fnv 0x009b8b10
// src: XBOX_PDB 0x009b8b10
bool FUN_009b8b10_cls::MissileProjectile_ProcessImpacts()
{
    bool bResult = false;
    if (!m_b90 && !m_k88.FUN_008256d0())
    {
        bool bConditionMet = true;
        if (Projectile_IsFlagSet(1))
        {
            float fDiff = GetFirstLightParameter() - std::abs(Projectile_GetSpeed() * DAT_0108fdd0);
            bConditionMet = GetE0() <= DAT_01012060 || fDiff < Projectile_GetDistanceMoved();
        }
        if (bConditionMet)
            bResult = ProcessHits();
    }
    if (bResult)
    {
        if (DAT_011f2250.FUN_00441110() == this)
            DAT_011f2250.VATS_SetFirstProjectile(0);
        if (DAT_011f2250.BGSSaveFormBuffer_GetForm() == this)
            DAT_011f2250.SetValue(0);
        switch (m_i150)
        {
        case 1:
            Projectile_Kill();
            break;
        case 2:
            HandleContactResponse();
            break;
        case 3:
            ProcessImpale();
            break;
        case 4:
            HandleMissileImpact();
            break;
        }
    }
    return bResult;
}
