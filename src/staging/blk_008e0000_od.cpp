
// src/staging/blk_008e0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_008e95a0_Class
{
    char GetByteAtBD();
};

// @fnv 0x008e95a0
char FUN_008e95a0_Class::GetByteAtBD()
{
    return *(char*)((char*)this + 0xbd);
}

struct FUN_008e95e0_Class
{
    unsigned char __thiscall GetByteAtOffsetC0();
};

// @fnv 0x008e95e0
unsigned char __thiscall FUN_008e95e0_Class::GetByteAtOffsetC0()
{
    return *(unsigned char*)((char*)this + 0xc0);
}

struct FUN_008e9600_Class
{
    void SetByteAtOffsetC2(char value);
};

// @fnv 0x008e9600
void FUN_008e9600_Class::SetByteAtOffsetC2(char value)
{
    ((char*)this)[0xc2] = value;
}

class SlotHost;
extern float DAT_01012054;
class SlotHost
{
  public:
    virtual void vf000();
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
    virtual void vf118(int a);
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual bool vf13c(SlotHost* a, int b, float c, int d);
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
    virtual void vf20c();
    virtual void vf210();
    virtual int vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual void vf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void vf264();
    virtual void vf268();
    virtual void vf26c();
    virtual void vf270();
    virtual void vf274();
    virtual void vf278();
    virtual SlotHost* vf27c();
    virtual void vf280();
    virtual void vf284(int a);
    virtual void vf288();
    virtual void vf28c();
    virtual void vf290();
    virtual void vf294(SlotHost* a);
};
class FUN_008f3550_cls : public SlotHost
{
  public:
    bool HighProcess_ProcessSleepOneHour(SlotHost* a1, int a2);
};
// @fnv 0x008f3550
// src: COMMUNITY 0x008f3550
bool FUN_008f3550_cls::HighProcess_ProcessSleepOneHour(SlotHost* a1, int a2)
{
    SlotHost* p = this->vf27c();
    if (p == 0)
    {
        return false;
    }
    this->vf294(a1);
    if (p->vf13c(a1, 0, DAT_01012054, 0) || a1->vf214() == 9)
    {
        this->vf118(1);
        return false;
    }
    else
    {
        this->vf284(0);
    }
    return false;
}

class C8F3600Actor;

class C8F3600Process
{
  public:
    virtual void pv000();
    virtual void pv001();
    virtual void pv002();
    virtual void pv003();
    virtual void pv004();
    virtual void pv005();
    virtual void pv006();
    virtual void pv007();
    virtual void pv008();
    virtual void pv009();
    virtual void pv00A();
    virtual void pv00B();
    virtual void pv00C();
    virtual void pv00D();
    virtual void pv00E();
    virtual void pv00F();
    virtual void pv010();
    virtual void pv011();
    virtual void pv012();
    virtual void pv013();
    virtual void pv014();
    virtual void pv015();
    virtual void pv016();
    virtual void pv017();
    virtual void pv018();
    virtual void pv019();
    virtual void pv01A();
    virtual void pv01B();
    virtual void pv01C();
    virtual void pv01D();
    virtual void pv01E();
    virtual void pv01F();
    virtual void pv020();
    virtual void pv021();
    virtual void pv022();
    virtual void pv023();
    virtual void pv024();
    virtual void pv025();
    virtual void pv026();
    virtual void pv027();
    virtual void pv028();
    virtual void pv029();
    virtual void pv02A();
    virtual void pv02B();
    virtual void pv02C();
    virtual void pv02D();
    virtual void pv02E();
    virtual void pv02F();
    virtual void pv030();
    virtual void pv031();
    virtual void pv032();
    virtual void pv033();
    virtual void pv034();
    virtual void pv035();
    virtual void pv036();
    virtual void pv037();
    virtual void pv038();
    virtual void pv039();
    virtual void pv03A();
    virtual void pv03B();
    virtual void pv03C();
    virtual void pv03D();
    virtual void pv03E();
    virtual void pv03F();
    virtual void pv040();
    virtual void pv041();
    virtual void pv042();
    virtual void pv043();
    virtual void pv044();
    virtual void pv045();
    virtual void pv046();
    virtual void pv047();
    virtual void pv048();
    virtual void pv049();
    virtual void pv04A();
    virtual void pv04B();
    virtual void pv04C();
    virtual void pv04D();
    virtual void pv04E();
    virtual bool StartCombat(class C8F3600Actor* pkTarget, int iA, float fImpulseRadiusSquared, int iB);
};

class C8F3600Actor
{
  public:
    virtual void av000();
    virtual void av001();
    virtual void av002();
    virtual void av003();
    virtual void av004();
    virtual void av005();
    virtual void av006();
    virtual void av007();
    virtual void av008();
    virtual void av009();
    virtual void av00A();
    virtual void av00B();
    virtual void av00C();
    virtual void av00D();
    virtual void av00E();
    virtual void av00F();
    virtual void av010();
    virtual void av011();
    virtual void av012();
    virtual void av013();
    virtual void av014();
    virtual void av015();
    virtual void av016();
    virtual void av017();
    virtual void av018();
    virtual void av019();
    virtual void av01A();
    virtual void av01B();
    virtual void av01C();
    virtual void av01D();
    virtual void av01E();
    virtual void av01F();
    virtual void av020();
    virtual void av021();
    virtual void av022();
    virtual void av023();
    virtual void av024();
    virtual void av025();
    virtual void av026();
    virtual void av027();
    virtual void av028();
    virtual void av029();
    virtual void av02A();
    virtual void av02B();
    virtual void av02C();
    virtual void av02D();
    virtual void av02E();
    virtual void av02F();
    virtual void av030();
    virtual void av031();
    virtual void av032();
    virtual void av033();
    virtual void av034();
    virtual void av035();
    virtual void av036();
    virtual void av037();
    virtual void av038();
    virtual void av039();
    virtual void av03A();
    virtual void av03B();
    virtual void av03C();
    virtual void av03D();
    virtual void av03E();
    virtual void av03F();
    virtual void av040();
    virtual void av041();
    virtual void av042();
    virtual void av043();
    virtual void av044();
    virtual void av045();
    virtual void SetAlert(bool bAlert);
    virtual void av047();
    virtual void av048();
    virtual void av049();
    virtual void av04A();
    virtual void av04B();
    virtual void av04C();
    virtual void av04D();
    virtual void av04E();
    virtual void av04F();
    virtual void av050();
    virtual void av051();
    virtual void av052();
    virtual void av053();
    virtual void av054();
    virtual void av055();
    virtual void av056();
    virtual void av057();
    virtual void av058();
    virtual void av059();
    virtual void av05A();
    virtual void av05B();
    virtual void av05C();
    virtual void av05D();
    virtual void av05E();
    virtual void av05F();
    virtual void av060();
    virtual void av061();
    virtual void av062();
    virtual void av063();
    virtual void av064();
    virtual void av065();
    virtual void av066();
    virtual void av067();
    virtual void av068();
    virtual void av069();
    virtual void av06A();
    virtual void av06B();
    virtual void av06C();
    virtual void av06D();
    virtual void av06E();
    virtual void av06F();
    virtual void av070();
    virtual void av071();
    virtual void av072();
    virtual void av073();
    virtual void av074();
    virtual void av075();
    virtual void av076();
    virtual void av077();
    virtual void av078();
    virtual void av079();
    virtual void av07A();
    virtual void av07B();
    virtual void av07C();
    virtual void av07D();
    virtual void av07E();
    virtual void av07F();
    virtual void av080();
    virtual void av081();
    virtual void av082();
    virtual void av083();
    virtual void av084();
    virtual int GetLifeState();
    virtual void av086();
    virtual void av087();
    virtual void av088();
    virtual void av089();
    virtual void av08A();
    virtual void av08B();
    virtual void av08C();
    virtual void av08D();
    virtual void av08E();
    virtual void av08F();
    virtual void av090();
    virtual void av091();
    virtual void av092();
    virtual void av093();
    virtual void av094();
    virtual void av095();
    virtual void av096();
    virtual void av097();
    virtual void av098();
    virtual void av099();
    virtual void av09A();
    virtual void av09B();
    virtual void av09C();
    virtual void av09D();
    virtual void av09E();
    virtual C8F3600Process* GetProcess();
    virtual void av0A0();
    virtual void SetCombatTarget(int iTarget);
    virtual void av0A2();
    virtual void av0A3();
    virtual void av0A4();
    virtual void SetTarget(C8F3600Actor* pkTarget);

    bool StartCombatWithTarget(C8F3600Actor* pkTarget, int iUnused);
};

// @fnv 0x008f3600
bool C8F3600Actor::StartCombatWithTarget(C8F3600Actor* pkTarget, int iUnused)
{
    C8F3600Process* pkProcess = 0;
    pkProcess = GetProcess();
    if (!pkProcess)
        return false;
    SetTarget(pkTarget);
    if (pkProcess->StartCombat(pkTarget, 0, -1.0f, 0) || pkTarget->GetLifeState() == 4)
    {
        SetAlert(true);
        return false;
    }
    else
    {
        SetCombatTarget(0);
    }
    return true;
}

class FUN_008e26a0_C
{
  public:
    char unk00[0xe0];
    float m_fValue;

    float CombatController_GetCombatPosition();
};

// Returns m_fValue clamped to a minimum of 0.0f.
// @fnv 0x008e26a0
// src: XBOX_PDB 0x008e26a0
float FUN_008e26a0_C::CombatController_GetCombatPosition()
{
    return m_fValue < 0.0 ? 0.0f : m_fValue;
}
