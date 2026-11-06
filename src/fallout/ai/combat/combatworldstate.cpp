// fallout/ai/combat/combatworldstate.cpp: CombatWorldStateListNode, CombatWorldStateArray, WorldStateManager (8 functions)

#include "../../../../include/BSSimpleList.h"
#include "../../../../include/Actor.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/CombatWorldStateListNode.h"
#include "../../../../include/CombatWorldStateArray.h"

// @fnv 0x0062d990
CombatWorldStateListNode* CombatWorldStateListNode::GetNext()
{
    return reinterpret_cast<CombatWorldStateListNode*>(reinterpret_cast<BSSimpleList<UnsignedIdHandle*>*>(this)->GetNext());
}

struct FUN_009aad60_shell
{
    CombatWorldStateListNode* __thiscall FUN_009aad60(int index);
};
// @fnv 0x009aad60
CombatWorldStateListNode* __thiscall FUN_009aad60_shell::FUN_009aad60(int index)
{
    return (CombatWorldStateListNode*)((char*)this + index * 8 + 0x1ac);
}

class CombatAction;
extern BSSimpleList<CombatAction*>* DAT_011f13d0[];
// @fnv 0x009957f0
BSSimpleList<CombatAction*>* FUN_009957f0(int index)
{
    return DAT_011f13d0[index];
}

struct FUN_009aad00Class
{
    void __thiscall FUN_009aad00(int index, int value);
};
// @fnv 0x009aad00
void __thiscall FUN_009aad00Class::FUN_009aad00(int index, int value)
{
    ((int*)this)[index] = value;
}

struct FUN_009aad40_shell
{
    bool IsFlagSet();
};
// @fnv 0x009aad40
bool FUN_009aad40_shell::IsFlagSet()
{
    return ((char*)this)[0x73] != 0;
}

void* __cdecl __memcpy(void* _Dst, const void* _Src, unsigned int _Size);
// Copies 0x50 bytes from apWorldStateArray into this, then 0xC bytes into this+0x50 from apWorldStateArray+0x50.
// @fnv 0x009aad80
void __thiscall CombatWorldStateArray::CopyFrom(CombatWorldStateArray* apWorldStateArray)
{
    __memcpy(this, apWorldStateArray, 0x50);
    __memcpy((char*)this + 0x50, (char*)apWorldStateArray + 0x50, 0xC);
}

struct FUN_009aad20_shell
{
    char gap[0x3FFF8];
    CombatWorldStateListNode* items[1];
    void __thiscall SetItem(int index, CombatWorldStateListNode* value);
};
// @fnv 0x009aad20
void __thiscall FUN_009aad20_shell::SetItem(int index, CombatWorldStateListNode* value)
{
    items[index] = value;
}

namespace fnv_009aa4e0 {
struct Pos
{
    float x, y, z, w;
    Pos();
    NiPoint3* FUN_006815c0();
    double FUN_00527a40(const Pos&);
};
struct RefType
{
    unsigned char type, disabled;
};
struct Entry
{
    int value;
    unsigned int bit;
    bool FUN_009373f0();
};
struct Weapon
{
    int FUN_00522c80();
};
struct Stamp
{
    float time;
    float FUN_00435e00();
};
struct Form
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
    virtual int Type();
    bool IsField8One();
    void* FUN_0044edb0();
    bool FUN_00666f00();
};
struct BasePart
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual bool Valid();
};
struct ActorBase
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    BasePart part;
};
struct Process
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
    virtual void v22c();
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
    virtual void v384();
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
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual bool Ready();
};
struct Caster
{
    void* FUN_0045cd60();
    int GetFieldOrZero(Actor*);
    bool FUN_0097ef30();
};
struct State
{
    Entry* GetFieldValue();
    Entry* GetActionAtIndex(unsigned int);
    bool FUN_0097fd40();
    bool FUN_009a02a0(Pos*, int, int);
    RefType* FUN_007058c0();
    unsigned char FUN_00662a80();
    float FUN_00644790();
    void* FUN_00407820();
    bool FUN_0097ee90();
    bool FUN_00998980();
    bool FUN_008b3c10();
    unsigned char GetByteAtOffset114();
    Stamp GetValue94();
    bool IsFlagSet();
    Weapon* FUN_0097c150(int);
    int GetField38();
    int GetField1BC();
    int GetAt(unsigned int);
    State* FUN_009aad60(unsigned int);
    bool FUN_008d7f80();
    bool FUN_009a1380();
    int FUN_00516bf0();
};
struct Context
{
    void ValidateCurrentWeapon();
    State* FUN_00586150();
    Actor* GetFieldBC();
    Actor* FUN_004030b0();
    Caster* FUN_004fb070();
    Form* FUN_004fd3c0();
    Form* FUN_004fd3e0();
    bool FUN_009a0240();
};
struct FloatSetting
{
    float* FUN_00403e20();
};
struct IntSetting
{
    int* FUN_0043d4d0();
};
extern FloatSetting originalRuntimeFloatSetting481, originalRuntimeFloatSetting413;
extern IntSetting g_011ce0b4;
extern double DAT_0108cb08;
void FUN_005b5e40(const char*, ...);
void FUN_009a9370(Context*, Entry*, NiPoint3*, int);
struct WorldStateManager
{
    void FUN_009aa4b0();
    void FUN_009aad00(int, int);
    void SetItem(int, int);
    void __thiscall UpdateWorldState(Context* context);
};
// @fnv 0x009aa4e0
void WorldStateManager::UpdateWorldState(Context* context)
{
    FUN_009aa4b0();
    context->ValidateCurrentWeapon();
    State* stateB = context->FUN_00586150();
    Actor* actor15 = context->GetFieldBC();
    Actor* target9 = context->FUN_004030b0();
    Pos position6 = actor15->FUN_00575650<Pos>();
    Pos targetPositions5;
    if (target9)
        targetPositions5 = target9->FUN_00575650<Pos>();
    Caster* local4 = context->FUN_004fb070();
    unsigned int q = 0;
    Form* bolt9 = context->FUN_004fd3c0();
    Form* localX = context->FUN_004fd3e0();
    Entry* entry7 = stateB->GetFieldValue();
    if (entry7 && !entry7->FUN_009373f0())
    {
        if (localX && localX->Type() == 7)
        {
            if (!localX->IsField8One())
                q |= 1 << entry7->bit;
        }
        else
        {
            NiPoint3 point4;
            FUN_009a9370(context, entry7, &point4, 0);
            NiPoint3 delta = point4 - *position6.FUN_006815c0();
            delta.z *= 0.10000000149011612;
            if (static_cast<const NiPoint3&>(delta).FUN_004a7290() < 1024.0)
                q |= 1 << entry7->bit;
        }
    }
    if (bolt9 && !bolt9->IsField8One() && bolt9->Type() == 8)
    {
        Form* boltTarget = bolt9;
        if (boltTarget->FUN_0044edb0())
        {
            for (unsigned int index = 0; index < 5; ++index)
            {
                Entry* candidate = stateB->GetActionAtIndex(index);
                if (candidate && (void*)candidate->value == boltTarget->FUN_0044edb0())
                    q |= 1 << (index + 17);
            }
        }
    }
    if (target9 && targetPositions5.FUN_00527a40(position6) < DAT_0108cb08 && !stateB->FUN_0097fd40() &&
        stateB->FUN_009a02a0(&targetPositions5, 1, 0))
        q |= 2;
    q |= 128;
    q |= 256;
    q |= 512;
    q |= 65536;
    RefType* refrA = stateB->FUN_007058c0();
    if (refrA && !refrA->disabled)
    {
        switch (refrA->type)
        {
        case 0:
            q &= ~128u;
            break;
        case 1:
            q &= ~256u;
            break;
        case 2:
            q &= ~512u;
            break;
        case 3:
            q &= ~65536u;
            break;
        default:
            FUN_005b5e40("COMBAT: Unsupported target ref type %i in world state update", refrA->type);
            break;
        }
    }
    if (stateB->FUN_00662a80() == 2)
        q |= 4096;
    if (localX && localX->Type() == 9 && !localX->IsField8One() && !localX->FUN_00666f00())
        q |= 1024;
    FUN_009aad00(1, q);
    FUN_009aad00(2, ~q);
    FUN_009aad00(14, stateB->FUN_00644790() > *originalRuntimeFloatSetting481.FUN_00403e20() ? 1 : 0);
    FUN_009aad00(8, (bool)(stateB->FUN_00407820() != 0));
    if (target9)
    {
        FUN_009aad00(4, stateB->FUN_0097ee90());
        FUN_009aad00(5, stateB->FUN_00998980() && !stateB->FUN_008b3c10() ? 1 : 0);
        FUN_009aad00(6, stateB->GetByteAtOffset114());
        FUN_009aad00(7, stateB->FUN_008b3c10());
        FUN_009aad00(3, stateB->GetValue94().FUN_00435e00() > *originalRuntimeFloatSetting413.FUN_00403e20() ? 1 : 0);
        FUN_009aad00(9, stateB->IsFlagSet());
    }
    else
        FUN_009aad00(3, 1);
    Weapon* weapon0 = reinterpret_cast<Weapon*>(actor15->FUN_008a1710());
    int weapon4 = weapon0 ? weapon0->FUN_00522c80() : 6;
    if (weapon0 && weapon0 != stateB->FUN_0097c150(weapon4))
        weapon4 = 7;
    FUN_009aad00(11, weapon4);
    SetItem(-65512, weapon4);
    FUN_009aad00(10, reinterpret_cast<Process*>(actor15->FUN_008d8520())->Ready() ? weapon4 : 7);
    FUN_009aad00(12, stateB->GetField38());
    for (unsigned int first = 0; first < 5; ++first)
    {
        if (stateB->GetActionAtIndex(first))
        {
            SetItem(-65514, first + 17);
            break;
        }
    }
    FUN_009aad00(13, stateB->GetField1BC());
    for (unsigned int second = 0; second < 2; ++second)
    {
        if (stateB->GetAt(second) && stateB->FUN_009aad60(second)->FUN_008d7f80())
        {
            bool usable = false;
            switch (second + 17)
            {
            case 17:
                if (actor15->GetHealthFraction() * 100.0 < *g_011ce0b4.FUN_0043d4d0())
                    usable = true;
                break;
            case 18:
                usable = true;
                break;
            }
            if (usable)
            {
                SetItem(-65513, second + 17);
                break;
            }
        }
    }
    FUN_009aad00(15, stateB->FUN_009a1380());
    void* magicTarget3 = local4->FUN_0045cd60();
    if (magicTarget3)
        FUN_009aad00(19, local4->GetFieldOrZero(actor15));
    int flags28 = stateB->FUN_00516bf0();
    if (local4->FUN_0097ef30())
        flags28 |= 65536;
    if (context->FUN_009a0240())
        flags28 |= 131072;
    if (!target9 || !reinterpret_cast<ActorBase*>(target9->FUN_004181e0())->part.Valid())
        flags28 |= 262144;
    FUN_009aad00(18, flags28);
}
}  // namespace fnv_009aa4e0
