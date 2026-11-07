#include "../../include/NiFrustum.h"

// src/staging/blk_00700000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

// The legacy layout support header also defines NiFile and scene containers.
// Keep only the list API needed here, before its shared users.
#include "../../include/BSStringT.h"

#include "../../include/BSSimpleList.h"
#include "../../include/GO.h"
#include "../../include/SL.h"
#include "../../include/StrMem.h"
#include "../../include/BSFile.h"
#include "../../include/DialogMenu.h"
#include "../../include/HUDMainMenu.h"
#include "../../include/Menu.h"
#include "../../include/NiCamera.h"
#include "../../include/NiFrustum.h"
#include "../../include/NiPick.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/OSGlobals.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESHealthForm.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/Tile.h"
#include "../../include/TileMenu.h"

struct FUN_00700270_class
{
    unsigned char Equals(int);
    bool operator==(int other);
};

// Returns true when Equals returns zero for the given value.
// @fnv 0x00700270
bool FUN_00700270_class::operator==(int other)
{
    return !Equals(other);
}





// Returns true when this string compares equal to s using a case-sensitive comparison.
// @fnv 0x007002a0
template <> int BSStringT<char>::Equals(const char* s)
{
    return !StrCmp(s, true);
}

struct FUN_007002d0_Class
{
    void __thiscall FUN_00700480(int, int);
    FUN_007002d0_Class* __thiscall BGSMenuPacker_BGSMenuPacker();
};

// Calls FUN_00700480 with 0 and 1, clears the byte at offset 0x21, and returns this.
// @fnv 0x007002d0
// src: COMMUNITY 0x007002d0
FUN_007002d0_Class* __thiscall FUN_007002d0_Class::BGSMenuPacker_BGSMenuPacker()
{
    FUN_00700480(0, 1);
    *(char*)((char*)this + 0x21) = 0;
    return this;
}

// @fnv 0x00700300
// src: XBOX_PDB 0x00700300
const char* Tile::GetName_00700300()
{
    return StringProvider.String();
}

extern "C" void* __cdecl DAT_0106e8d4;

struct FUN_00700560
{
    FUN_00700560(void* a, void* b);
};

struct FUN_00700480 : FUN_00700560
{
    FUN_00700480(void* a, void* b);
};

// @fnv 0x00700480
FUN_00700480::FUN_00700480(void* apArg, void* apArg2) : FUN_00700560(apArg, apArg2)
{
    *reinterpret_cast<void**>(this) = &DAT_0106e8d4;
}

struct FUN_007004e0_class
{
    void __thiscall UpdateFields_00700500();
    void __thiscall ForwardCall_007004e0();
};

// @fnv 0x007004e0
// src: GUESS 0x007004e0 (confidence: low)
void __thiscall FUN_007004e0_class::ForwardCall_007004e0()
{
    UpdateFields_00700500();
}

void __cdecl Deallocate(void*);
struct FUN_00702220
{
    void* m;
    ~FUN_00702220();
};
// Destructor that reads the stored pointer m and passes it to Deallocate.
// @fnv 0x00702220
FUN_00702220::~FUN_00702220()
{
    void* p = m;
    Deallocate(p);
}

struct FUN_00703470_Class
{
    unsigned char GetByteAt110();
};

// @fnv 0x00703470
unsigned char FUN_00703470_Class::GetByteAt110()
{
    return *(unsigned char*)((char*)this + 0x110);
}

struct FUN_00703960_Class
{
    void __thiscall SetByteAtOffsetEC(char value);
};

// @fnv 0x00703960
void __thiscall FUN_00703960_Class::SetByteAtOffsetEC(char value)
{
    ((char*)this)[0xec] = value;
}

// @fnv 0x00705fc0
// src: XBOX_PDB 0x00705fc0
void NiPick::SetTarget_00705fc0(void* p)
{
    reinterpret_cast<GO&>(root) = p;
}

// @fnv 0x00709a20
bool Tile::IsSpecial()
{
    return (uiFlags & 0x2000) != 0;
}

extern float g_011d86e0_arg1;

// @fnv 0x00709ac0
float __cdecl GetGlobalArg1()
{
    float v = g_011d86e0_arg1;
    return v;
}

void __cdecl HUDMainMenu_ShowDDTIcon(bool);

// @fnv 0x00709c60
// src: XBOX_PDB 0x00709c60
void Interface_ShowDDTIcon(bool a)
{
    HUDMainMenu_ShowDDTIcon(a);
}

extern "C" void __cdecl UpdateTileOnFlag(bool);

// @fnv 0x00709c80
// src: XBOX_PDB 0x00709c80
void Interface_ShowEnemyDDTIcon(bool abValue)
{
    UpdateTileOnFlag(abValue);
}

void __cdecl MapMenu_SetRootMapSpace(int);

// @fnv 0x00709d20
// src: XBOX_PDB 0x00709d20
void __cdecl Interface_SetRootMapSpace(int aiValue)
{
    MapMenu_SetRootMapSpace(aiValue);
}

extern void* DAT_0106edec;
struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
    AX* __thiscall BSSimpleArray_Tile_Value_8_BSSimpleArray(unsigned int a, unsigned int b);
};
// @fnv 0x00709e80
// src: EXE 0x00709e80
AX* __thiscall AX::BSSimpleArray_Tile_Value_8_BSSimpleArray(unsigned int auiFirst, unsigned int auiSecond)
{
    *reinterpret_cast<void**>(this) = &DAT_0106edec;
    BSSimpleArray_float_1024_InitialSetup(auiFirst, auiSecond);
    return this;
}

namespace fnv_00709eb0 {
extern int DAT_0106edec;
struct GlobalObject_00869f00
{
    void Clear(bool b);
};
struct FUN_00709eb0_Class
{
    void* m;
    void InitAndClear();
};
// @fnv 0x00709eb0
void FUN_00709eb0_Class::InitAndClear()
{
    m = &DAT_0106edec;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_00709eb0

struct TgtOps
{
    void* GetPosition();
};

struct FUN_00700350_Class
{
    void BGSMenuPacker_DumpInfo();
};

struct FUN_00717e30_Class
{
    void InterfaceManager_DumpMenuPackingInfo();
};

// Calls GetPosition on the TgtOps at offset 0x178 and invokes FUN_00700350 on the returned object.
// @fnv 0x00717e30
// src: COMMUNITY 0x00717e30
void FUN_00717e30_Class::InterfaceManager_DumpMenuPackingInfo()
{
    ((FUN_00700350_Class*)((TgtOps*)((char*)this + 0x178))->GetPosition())->BGSMenuPacker_DumpInfo();
}

extern int DAT_0106f448;

struct FUN_00719390_class
{
    void __thiscall ConstructAndInit();
    void __thiscall SetVtableAndProcessState_00719390();
};

// @fnv 0x00719390
// src: GUESS 0x00719390 (confidence: low)
void __thiscall FUN_00719390_class::SetVtableAndProcessState_00719390()
{
    *reinterpret_cast<int**>(this) = &DAT_0106f448;
    ConstructAndInit();
}

struct FUN_00719b00_class
{
    bool PlayerCharacter_GetIsDebounceWASD();
};
// @fnv 0x00719b00
// src: COMMUNITY 0x00719b00
bool FUN_00719b00_class::PlayerCharacter_GetIsDebounceWASD()
{
    return (reinterpret_cast<signed char*>(reinterpret_cast<char*>(this) + 0x66d)[0] & 4) != 0;
}

extern unsigned int DAT_0106f798;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_00719be0
{
    unsigned int* p;
    void Initialize();
};
// @fnv 0x00719be0
void FUN_00719be0::Initialize()
{
    p = &DAT_0106f798;
    ((GlobalObject_00869f00*)this)->Clear(true);
}


// @fnv 0x0071aa60
// src: XBOX_PDB 0x0071aa60
void Tile::SetSpeechChallengeFailure_0071aa60(bool value)
{
    m_bSpeechChallengeFailure = value;
}

extern "C" void __cdecl FUN_00ecb849(int, int, int);

// @fnv 0x0071cfd0
// src: COMMUNITY 0x0071cfd0
void __cdecl _mbsnbcmp_(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_00ecb849(aiArg1, aiArg2, aiArg3);
}

void __cdecl FUN_00ecba8e(int a, int b, int c);

// @fnv 0x0071cff0
// src: COMMUNITY 0x0071cff0
void __cdecl _mbsnbicmp_(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_00ecba8e(aiArg1, aiArg2, aiArg3);
}

struct FUN_0071d010_Class
{
    void SetByteAtOffset20(unsigned char v);
};

// @fnv 0x0071d010
void FUN_0071d010_Class::SetByteAtOffset20(unsigned char aucValue)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x20) = aucValue;
}

struct FUN_0071e0d0_Class
{
    void CreateInstance();
    void TextNode_Create_();
};

// @fnv 0x0071e0d0
// src: COMMUNITY 0x0071e0d0
void FUN_0071e0d0_Class::TextNode_Create_()
{
    ((FUN_0071e0d0_Class*)((char*)this + 8))->CreateInstance();
}

struct Str6a70
{
    char c[8];
    Str6a70& operator=(const char*);
};
struct FUN_0071e1a0_cls
{
    void UpdateFields_0071e1a0(const void*);
};
struct FUN_0071e0f0_cls
{
    void UpdateState_0071e0f0(const char* arg);
};
// @fnv 0x0071e0f0
// src: GUESS 0x0071e0f0 (confidence: low)
void FUN_0071e0f0_cls::UpdateState_0071e0f0(const char* arg)
{
    ((Str6a70*)((char*)arg + 8))->operator=(0);
    ((FUN_0071e1a0_cls*)((char*)this + 8))->UpdateFields_0071e1a0(arg);
}


struct FUN_0071e230
{
    char pad[8];
    StrMem m;
    void* Init();
};

// @fnv 0x0071e230
void* FUN_0071e230::Init()
{
    m.StrMem::StrMem();
    return this;
}

struct FUN_0071e250_class
{
    void DestroyBSS();
    void DestroyBSS_Thunk();
};

// @fnv 0x0071e250
// src: GUESS 0x0071e250 (confidence: medium)
void FUN_0071e250_class::DestroyBSS_Thunk()
{
    DestroyBSS();
}

// @fnv 0x0071f520
char __cdecl HasThirdFieldNonZero(void* a)
{
    return ((int*)a)[2] != 0 ? 1 : 0;
}

extern int DAT_01070028;
struct FUN_0071f5d0
{
    int m;
    SL s;
    FUN_0071f5d0();
};
// Constructor that stores the address of DAT_01070028 into m and default-constructs s.
// @fnv 0x0071f5d0
FUN_0071f5d0::FUN_0071f5d0() : s()
{
    m = (int)&DAT_01070028;
}

struct FUN_0071fb20_Class
{
    int __thiscall TextEditMenu_GetMenuID();
};

// @fnv 0x0071fb20
// src: COMMUNITY 0x0071fb20
int __thiscall FUN_0071fb20_Class::TextEditMenu_GetMenuID()
{
    return 0x41b;
}

struct FUN_0071fbc0_Class
{
    void SetSlotValue(int index, int value);
};

// Stores value into the int slot at offset 0x28 plus index*4 when index is between 0 and 2.
// @fnv 0x0071fbc0
void FUN_0071fbc0_Class::SetSlotValue(int index, int value)
{
    if (index >= 0 && index < 3)
        *(int*)((char*)this + 0x28 + index * 4) = value;
}

void __cdecl _Deallocate(void*);
struct FUN_007004b0_Class : FUN_007004e0_class
{
    void* __thiscall FUN_007004b0(unsigned int);
};
// Calls FUN_007004e0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007004b0
void* __thiscall FUN_007004b0_Class::FUN_007004b0(unsigned int flags)
{
    ForwardCall_007004e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct StandIn_700530
{
    void* __thiscall FUN_00700530(unsigned int flags);
};
// Calls FUN_00700500 on this, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x00700530
void* __thiscall StandIn_700530::FUN_00700530(unsigned int flags)
{
    ((FUN_007004e0_class*)this)->UpdateFields_00700500();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Modifier
{
    unsigned char GetKey();
};
struct FUN_009bdf60_class
{
    void InterfaceManager_SetCrosshairRef(int);
};
extern "C" void* __cdecl InterfaceManager_GetSingleton();

// If FUN_004b7210 returns an object whose GetKey is nonzero, calls FUN_009bdf60 on it with arg.
// @fnv 0x00703310
// src: COMMUNITY 0x00703310
void Interface_SetCrosshairRef(int arg)
{
    if (InterfaceManager_GetSingleton() && ((Modifier*)InterfaceManager_GetSingleton())->GetKey())
        ((FUN_009bdf60_class*)InterfaceManager_GetSingleton())->InterfaceManager_SetCrosshairRef(arg);
}

namespace fnv_00703430 {
void* __cdecl InterfaceManager_GetSingleton();
struct Modifier
{
    unsigned char GetKey();
};
// @fnv 0x00703430
// src: COMMUNITY 0x00703430
unsigned char __cdecl Interface_IsActivatePickFuzzy()
{
    if (InterfaceManager_GetSingleton() && ((Modifier*)InterfaceManager_GetSingleton())->GetKey())
        return ((FUN_00703470_Class*)InterfaceManager_GetSingleton())->GetByteAt110();
    return 0;
}
}  // namespace fnv_00703430

namespace fnv_007038e0 {
struct Modifier
{
    unsigned char GetKey();
};
void* __cdecl InterfaceManager_GetSingleton();
struct FUN_00715ec0_Class
{
    void __thiscall SetSafeZone(int a);
};
// If FUN_004b7210 returns a non-null object whose GetKey is nonzero, calls SetSafeZone on it with param.
// @fnv 0x007038e0
// src: COMMUNITY 0x007038e0
void Interface_ToggleSafeZone(int param)
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
        reinterpret_cast<FUN_00715ec0_Class*>(InterfaceManager_GetSingleton())->SetSafeZone(param);
}
}  // namespace fnv_007038e0

namespace fnv_00703920 {
struct Modifier
{
    unsigned char GetKey();
};
void* __cdecl InterfaceManager_GetSingleton();
// If FUN_004b7210 returns a non-null object whose GetKey is nonzero, calls SetByteAtOffsetEC(1) on it and Tile::UpdateAll(false).
// @fnv 0x00703920
// src: COMMUNITY 0x00703920
void __cdecl Interface_SetFirstChanceTextureRelease()
{
    if (InterfaceManager_GetSingleton() && reinterpret_cast<Modifier*>(InterfaceManager_GetSingleton())->GetKey())
    {
        reinterpret_cast<FUN_00703960_Class*>(InterfaceManager_GetSingleton())->SetByteAtOffsetEC(1);
        Tile::UpdateAll(false);
    }
}
}  // namespace fnv_00703920

struct FUN_00703be0_Class
{
    unsigned char __thiscall GetByteAt(int, int);
};
// Returns the byte at offset 0x1b94 plus b*28 plus a within this object.
// @fnv 0x00703be0
unsigned char __thiscall FUN_00703be0_Class::GetByteAt(int a, int b)
{
    return *((unsigned char*)this + (b * 28 + a) + 0x1b94);
}

namespace fnv_007062e0 {
struct Modifier
{
    unsigned char GetKey();
};
Modifier* __cdecl InterfaceManager_GetSingleton();
// @fnv 0x007062e0
// src: COMMUNITY 0x007062e0
bool __cdecl Interface_SetInfoForRef(TESObjectREFR* apRefr, bool abFlag1, bool abFlag2)
{
    if (InterfaceManager_GetSingleton() && InterfaceManager_GetSingleton()->GetKey())
    {
        return HUDMainMenu::UpdateTargetReference(apRefr, abFlag1, abFlag2);
        goto done;
    }
    return 0;
done:;
}
}  // namespace fnv_007062e0

class InterfaceManager;
namespace fnv_00707b30 {
InterfaceManager* InterfaceManager_GetSingleton();
void InterfaceManager_IsCurrentRenderedMenuTopmost();
// @fnv 0x00707b30
// src: COMMUNITY 0x00707b30
void Interface_IsActiveMenuTheRenderedMenu()
{
    InterfaceManager_GetSingleton();
    InterfaceManager_IsCurrentRenderedMenuTopmost();
}
}  // namespace fnv_00707b30

extern char vftable_TileMenu;
// Initializes a TileMenu: runs the base constructor, installs the TileMenu vtable, and zeroes the field at offset 0x3c.
// @fnv 0x00709810
TileMenu* __thiscall TileMenu::TileMenuConstructor(int aiUnused1, int aiUnused2)
{
    this->TileRect::TileRect();
    *(void**)this = (void*)&vftable_TileMenu;
    pMenu = 0;
    return this;
}

extern int g_011d8950;
extern int DAT_011d8954;
extern int g_011d8998;
extern int DAT_011d899c;

// @fnv 0x00709a90
// src: COMMUNITY 0x00709a90
void __cdecl Interface_ClearMenuQueue()
{
    g_011d8950 = 0;
    DAT_011d8954 = 0;
    g_011d8998 = 0;
    DAT_011d899c = 0;
}

struct S00709b80
{
    void __thiscall SetParams();
};
S00709b80* __stdcall _FUN_004b7210(unsigned char, float, float, int);
// @fnv 0x00709b50
// src: COMMUNITY 0x00709b50
void __cdecl Interface_SetQueuedPipboyTab(unsigned char a, float afParam1, float afParam2, int aiParam)
{
    _FUN_004b7210(a, afParam1, afParam2, aiParam)->SetParams();
}

struct FUN_00709b80_Class
{
    void __thiscall SetParams(char a, float b, float c, int d);
};
// Stores a char at offset 0x4b4, two floats at 0x4ac and 0x4b0, and an int at 0x4b8 of this object.
// @fnv 0x00709b80
void __thiscall FUN_00709b80_Class::SetParams(char a, float afValue1, float afValue2, int aiValue)
{
    *(char*)((char*)this + 0x4b4) = a;
    *(float*)((char*)this + 0x4ac) = afValue1;
    *(float*)((char*)this + 0x4b0) = afValue2;
    *(int*)((char*)this + 0x4b8) = aiValue;
}

extern "C" void* __cdecl _pme;

// Returns 1 if _pme is non-null and the byte at offset 0x1fc is set, otherwise 0.
// @fnv 0x00709cc0
// src: COMMUNITY 0x00709cc0
unsigned char __cdecl HUDMainMenu_IsGunScopeVisible()
{
    int result;
    if (_pme && *(unsigned char*)((char*)_pme + 0x1fc))
        result = 1;
    else
        result = 0;
    return result;
}

void __cdecl InitAndClear();

struct FUN_00709ed0_Class
{
    void __thiscall InitAndClear();
    void* __thiscall FUN_00709ed0(unsigned int flags);
};

// @fnv 0x00709ed0
void* __thiscall FUN_00709ed0_Class::FUN_00709ed0(unsigned int flags)
{
    InitAndClear();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct Dummy_00718c90
{
    void __thiscall ProcessEntries_00719010();
    void* __thiscall FUN_00718c40(int);
};
extern Dummy_00718c90* DAT_011d8a88;
// Calls FUN_00719010 on DAT_011d8a88, obtains a value via FUN_00718c40(1) if non-null, then clears DAT_011d8a88.
// @fnv 0x00718bf0
// src: GUESS 0x00718bf0 (confidence: low)
void __cdecl Runtime_UpdateState_00718bf0()
{
    DAT_011d8a88->ProcessEntries_00719010();
    Dummy_00718c90* q = DAT_011d8a88;
    Dummy_00718c90* p = q;
    void* r;
    if (p)
        r = p->FUN_00718c40(1);
    else
        r = 0;
    DAT_011d8a88 = 0;
}

void __cdecl Deallocate(void*);

struct FUN_00718c40_class
{
    void __thiscall FUN_00718c70();
    void* __thiscall FUN_00718c40(unsigned int flags);
};

// @fnv 0x00718c40
void* __thiscall FUN_00718c40_class::FUN_00718c40(unsigned int flags)
{
    FUN_00718c70();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct ArrHelper
{
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() const;
    void* RemoveHead();
};
struct VObj
{
    virtual int vf0(int);
};
struct FUN_00719010_Class
{
    void ProcessEntries_00719010();
};
// @fnv 0x00719010
// src: GUESS 0x00719010 (confidence: low)
void FUN_00719010_Class::ProcessEntries_00719010()
{
    while (!((ArrHelper*)this)->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        void* item = ((ArrHelper*)this)->RemoveHead();
        void* tmp = item;
        tmp ? ((VObj*)tmp)->vf0(1) : 0;
    }
}

void __cdecl _Deallocate(void*);
struct FUN_00719200_Cls
{
    void* __thiscall FUN_00719200(unsigned int);
};
// Calls ConstructAndInit on this, then frees this via _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00719200
void* __thiscall FUN_00719200_Cls::FUN_00719200(unsigned int flags)
{
    ((FUN_00719390_class*)this)->ConstructAndInit();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern "C" void* __cdecl DAT_0106f430;
struct FUN_00719250_class
{
    void* vtbl;
    void* a;
    void* b;
    int c;
    void __thiscall FUN_00719160(int, int);
    FUN_00719250_class* __thiscall Construct(int, int, int);
};
// Calls FUN_00719160 with p2 and p4, sets vtbl to DAT_0106f430 and c to p3, then returns this.
// @fnv 0x00719250
FUN_00719250_class* __thiscall FUN_00719250_class::Construct(int aiArg1, int aiValue, int aiArg2)
{
    FUN_00719160(aiArg1, aiArg2);
    vtbl = &DAT_0106f430;
    c = aiValue;
    return this;
}

void __cdecl SetVirtualTableAndProcessState_007192c0();
struct FUN_00719290_class
{
    void __thiscall SetVirtualTableAndProcessState_007192c0();
    FUN_00719290_class* __thiscall FUN_00719290(unsigned int flags);
};
// Calls FUN_007192c0, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00719290
FUN_00719290_class* __thiscall FUN_00719290_class::FUN_00719290(unsigned int flags)
{
    SetVirtualTableAndProcessState_007192c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_0106f448;
struct FUN_007192e0_Class
{
    void* vtbl;
    void* m_iWordAt00;
    void* m1;
    void* m_0c;
    void* m_10;
    void* m_14;
    void __thiscall FUN_00719160(int, int);
    FUN_007192e0_Class(void* a, void* b, void* c);
};
// Calls FUN_00719160 with a and c, sets vtbl to &DAT_0106f448 and stores b in m_0c.
// @fnv 0x007192e0
FUN_007192e0_Class::FUN_007192e0_Class(void* a, void* b, void* c)
{
    FUN_00719160((int)a, (int)c);
    vtbl = &DAT_0106f448;
    m_0c = b;
}

struct GlobalObject_00719b80
{
    void __thiscall Initialize();
    ~GlobalObject_00719b80();
    void* __thiscall InitializeAndMaybeDeallocate(unsigned int flags);
};
// @fnv 0x00719bb0
void* __thiscall GlobalObject_00719b80::InitializeAndMaybeDeallocate(unsigned int flags)
{
    Initialize();
    if (flags & 1)
        Deallocate(this);
    return this;
}

// Exe 0x00719da0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BlkOffset08View
{
    unsigned int __thiscall GetFlags();
};
int __fastcall _FNV_GetFormType(unsigned int);
// Returns 1 if p is non-null and its form type from GetFlags equals 0x28, otherwise 0.
// @fnv 0x00719da0
// src: COMMUNITY 0x00719da0
unsigned char __cdecl InventoryList_IsWeapon(BlkOffset08View* p)
{
    int result;
    if (p != 0 && _FNV_GetFormType(p->GetFlags()) == 0x28)
        result = 1;
    else
        result = 0;
    return (unsigned char)result;
}

namespace fnv_00719de0 {
int __fastcall FNV_GetFormType(unsigned int form);
// Exe 0x00719de0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BlkOffset08View
{
    unsigned int GetFlags();
};
// Returns 1 if arg is non-null and its form type is 0x1a or 0x18, otherwise 0.
// @fnv 0x00719de0
// src: COMMUNITY 0x00719de0
char InventoryList_IsApparel(void* arg)
{
    int result;
    if (arg &&
        (FNV_GetFormType(((BlkOffset08View*)arg)->GetFlags()) == 0x1a || FNV_GetFormType(((BlkOffset08View*)arg)->GetFlags()) == 0x18))
        result = 1;
    else
        result = 0;
    return (char)result;
}
}  // namespace fnv_00719de0

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
};
struct Holder
{
    void __thiscall MenuConsole_SetFileOutputName(char const*);
};
// @fnv 0x0071dd50
// src: COMMUNITY 0x0071dd50
void __thiscall Holder::MenuConsole_SetFileOutputName(char const* a)
{
    if (a != 0)
        TaskQueueInterface::CopyStringToBuffer((char*)this + 0x810, 0x104, a);
    else
        *((char*)this + 0x810) = 0;
}

struct A71e0d0
{
    void* __thiscall TextNode_Create_();
};
struct B49fa20
{
    void __thiscall NiTListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddNodeHead(void*);
};
struct S71df20
{
    void __thiscall AssignString(const BSStringT<char>&);
};
// Gets a pointer via FUN_0071e0d0, assigns a to the object at offset 8, then passes the pointer to FUN_0049fa20.
// @fnv 0x0071df20
void __thiscall S71df20::AssignString(const BSStringT<char>& aString)
{
    void* tmp = ((A71e0d0*)this)->TextNode_Create_();
    ((BSStringT<char>*)((char*)tmp + 8))->operator=(aString);
    ((B49fa20*)this)->NiTListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddNodeHead(tmp);
}

struct FUN_0071e200_Helper
{
    int __thiscall FUN_0071e200(int);
};
// If arg is non-null, calls FUN_0071e200 on it with 1; otherwise does nothing.
// @fnv 0x0071e1a0
// src: GUESS 0x0071e1a0 (confidence: low)
void FUN_0071e1a0_cls::UpdateFields_0071e1a0(const void* apObject)
{
    FUN_0071e200_Helper* b;
    {
        const void* a;
        a = apObject;
        b = (FUN_0071e200_Helper*)a;
    }
    b ? b->FUN_0071e200(1) : 0;
}

void __cdecl _Deallocate(void*);
struct S_0071e200
{
    void* __thiscall FUN_0071e200(unsigned int);
};
// @fnv 0x0071e200
void* __thiscall S_0071e200::FUN_0071e200(unsigned int flags)
{
    ((FUN_0071e250_class*)this)->DestroyBSS_Thunk();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_0106ff84;
extern int DAT_011db088;
struct S
{
    void __thiscall DestroyMenu();
};
// Resets the vtable pointer to DAT_0106ff84, clears DAT_011db088, then calls the Menu destructor on this.
// @fnv 0x0071f310
void __thiscall S::DestroyMenu()
{
    *(int*)this = (int)&DAT_0106ff84;
    DAT_011db088 = 0;
    ((Menu*)this)->Menu::~Menu();
}

char __cdecl HasThirdFieldNonZero(void*);
struct FUN_0071f4a0
{
    int m0;
    int m4;
    int m8;
    char(__cdecl* mpC)(void*);
    FUN_0071f4a0();
};
// @fnv 0x0071f4a0
FUN_0071f4a0::FUN_0071f4a0()
{
    m0 = 0;
    m4 = 0;
    m8 = 0;
    mpC = HasThirdFieldNonZero;
}

struct FUN_0071f900_Class
{
    int __thiscall FUN_0071f900(int);
};
extern FUN_0071f900_Class* DAT_011dace4;
// Calls FUN_0071f900(1) on DAT_011dace4 if non-null, then sets DAT_011dace4 to null.
// @fnv 0x0071f8c0
// src: GUESS 0x0071f8c0 (confidence: low)
void Object_UpdateFields_0071f8c0()
{
    FUN_0071f900_Class* b = DAT_011dace4;
    FUN_0071f900_Class* a = b;
    a ? a->FUN_0071f900(1) : 0;
    DAT_011dace4 = 0;
}

namespace fnv_0071f900 {
void __cdecl Deallocate(void*);
struct FUN_0071f900_Class
{
    void* __thiscall FUN_0071f900(unsigned int flags);
    void __thiscall FUN_0071f930();
};
// Calls FUN_0071f930, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0071f900
void* __thiscall FUN_0071f900_Class::FUN_0071f900(unsigned int flags)
{
    FUN_0071f930();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_0071f900

struct FUN_0071fb30_Class
{
    void __thiscall FUN_0071fb60();
    void* __thiscall FUN_0071fb30(unsigned int flags);
};

// Calls FUN_0071fb60, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x0071fb30
void* __thiscall FUN_0071fb30_Class::FUN_0071fb30(unsigned int flags)
{
    FUN_0071fb60();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_0071fb60 {
struct FUN_00716a10_Class
{
    void FUN_00716a10();
};
struct FUN_0071fb60_Class : Menu
{
    ~FUN_0071fb60_Class();
};
// @fnv 0x0071fb60
FUN_0071fb60_Class::~FUN_0071fb60_Class()
{
    ((FUN_00716a10_Class*)((char*)this + 0x34))->FUN_00716a10();
}
}  // namespace fnv_0071fb60

struct FUN_007001f0_Class
{
    int __thiscall AnimatingText_GetParent();
};
// Returns the value at offset 4 of the object stored at this+8 or this+0xc when both agree, or of whichever is non-null; otherwise 0.
// @fnv 0x007001f0
// src: XBOX_PDB 0x007001f0
int FUN_007001f0_Class::AnimatingText_GetParent()
{
    if (*(void**)((char*)this + 8) && *(void**)((char*)this + 0xc) &&
        *(void**)((char*)(*(void**)((char*)this + 8)) + 4) == *(void**)((char*)(*(void**)((char*)this + 0xc)) + 4))
    {
        return *(int*)((char*)(*(void**)((char*)this + 8)) + 4);
    }
    else if (*(void**)((char*)this + 8) && !*(void**)((char*)this + 0xc))
    {
        return *(int*)((char*)(*(void**)((char*)this + 8)) + 4);
    }
    else if (!*(void**)((char*)this + 8) && *(void**)((char*)this + 0xc))
    {
        return *(int*)((char*)(*(void**)((char*)this + 0xc)) + 4);
    }
    else
    {
        return 0;
    }
}

struct PerfEntry
{
    unsigned char b;
    int i;
    float f;
    GO g;
};
extern PerfEntry DAT_011d8840[3];
struct PerfMgr
{
    void ClearThreePerformanceEntries();
};
// Clears the byte, int, float and GO fields of each of the three PerfEntry records in DAT_011d8840.
// @fnv 0x00700650
// src: GUESS 0x00700650 (confidence: medium)
void PerfMgr::ClearThreePerformanceEntries()
{
    for (int i = 0; i < 3; i++)
    {
        ((unsigned char*)DAT_011d8840)[i * 0x1c] = 0;
        *((int*)((unsigned char*)DAT_011d8840 + i * 0x1c + 8)) = 0;
        *((float*)((unsigned char*)DAT_011d8840 + i * 0x1c + 12)) = 0.0f;
        ((GO*)((unsigned char*)DAT_011d8840 + i * 0x1c + 16))->operator=(0);
    }
}

class ActorCombatGroup;

extern int DAT_0106e8dc;

// @fnv 0x00700560
FUN_00700560::FUN_00700560(void* ausSize, void* b)
{
    *(void**)this = &DAT_0106e8dc;
    *(unsigned short*)((char*)this + 0x08) = (unsigned short)(unsigned int)ausSize;
    *(unsigned short*)((char*)this + 0x0e) = (unsigned short)(unsigned int)b;
    *(unsigned short*)((char*)this + 0x0a) = 0;
    *(unsigned short*)((char*)this + 0x0c) = 0;
    if (*(unsigned short*)((char*)this + 0x08) > 0)
    {
        *(void**)((char*)this + 0x04) = NiTMallocInterface<ActorCombatGroup*>::Allocate(*(unsigned short*)((char*)this + 0x08));
    }
    else
    {
        *(void**)((char*)this + 0x04) = 0;
    }
}

void __cdecl BlackJackMenu_DrawScene();

// @fnv 0x00709b10
// src: COMMUNITY 0x00709b10
void __cdecl Interface_DrawBlackJackMenu3D()
{
    BlackJackMenu_DrawScene();
}

struct GlobalObject_0048f200
{
    ~GlobalObject_0048f200();
};
struct FUN_00718c70 : GlobalObject_0048f200
{
    ~FUN_00718c70();
};
// @fnv 0x00718c70
FUN_00718c70::~FUN_00718c70()
{}

struct FUN_007192c0_class
{
    void* vtbl;
    void SetVirtualTableAndProcessState_007192c0();
};
// @fnv 0x007192c0
// src: GUESS 0x007192c0 (confidence: low)
void FUN_007192c0_class::SetVirtualTableAndProcessState_007192c0()
{
    vtbl = &DAT_0106f430;
    ((FUN_00719390_class*)this)->ConstructAndInit();
}

// Returns 1 if p is non-null and its form type is one of 0x1f, 0x29, 0x67, 0x32, 0x6c, 0x74 or 0x73; otherwise 0.
// @fnv 0x00719e30
// src: COMMUNITY 0x00719e30
unsigned char __cdecl InventoryList_IsMisc(BlkOffset08View* apForm)
{
    int result;

    if (apForm && (_FNV_GetFormType(apForm->GetFlags()) == 0x1f || _FNV_GetFormType(apForm->GetFlags()) == 0x29 ||
                   _FNV_GetFormType(apForm->GetFlags()) == 0x67 || _FNV_GetFormType(apForm->GetFlags()) == 0x32 ||
                   _FNV_GetFormType(apForm->GetFlags()) == 0x6c || _FNV_GetFormType(apForm->GetFlags()) == 0x74 ||
                   _FNV_GetFormType(apForm->GetFlags()) == 0x73))
        result = 1;
    else
        result = 0;

    return result;
}


struct FUN_0071e250
{
    char pad[8];
    ::BSStringT<char> s;
    void DestroyBSS();
};
// @fnv 0x0071e270
void FUN_0071e250::DestroyBSS()
{
    s.BSStringT<char>::~BSStringT();
}

struct FUN_00701500_Sub
{
    int m0;
    void __thiscall Reset();
};

struct FUN_00701500_cls
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    FUN_00701500_Sub m18;
    void ResetSub();
};

// @fnv 0x00701500
void FUN_00701500_cls::ResetSub()
{
    m18.Reset();
}

extern "C" void* __cdecl InterfaceManager_GetSingleton();

struct FUN_009373f0_StandIn
{
    unsigned char __thiscall TESTextureList_GetTextureCount();
};

struct FUN_009b7010_StandIn
{
    void __thiscall Projectile_GetMovementDirection(int*);
};

extern int DAT_011f426c;

struct ThreeInts
{
    int a;
    int b;
    int c;
};

// If the singleton exists and its check passes, forwards arg to its method; otherwise copies the three ints from DAT_011f426c into arg. Returns arg.
// @fnv 0x007033d0
// src: COMMUNITY 0x007033d0
int* __cdecl Interface_GetActivatePickLocation(int* pOut)
{
    if (InterfaceManager_GetSingleton() && ((FUN_009373f0_StandIn*)InterfaceManager_GetSingleton())->TESTextureList_GetTextureCount())
    {
        ((FUN_009b7010_StandIn*)InterfaceManager_GetSingleton())->Projectile_GetMovementDirection(pOut);
        return pOut;
    }

    *(ThreeInts*)pOut = *(const ThreeInts*)&DAT_011f426c;
    return pOut;
}

extern int g_011d96b4;

// @fnv 0x007038a0
// src: COMMUNITY 0x007038a0
int __cdecl Interface_GetDetectionLevel()
{
    return g_011d96b4;
}

void GetHUDMainMenuValue();

// @fnv 0x007038d0
// src: COMMUNITY 0x007038d0
void Interface_GetEnemyActor()
{
    GetHUDMainMenuValue();
}

extern void __cdecl MessageMenu_ProcessYesToAll();
// @fnv 0x00703fd0
// src: COMMUNITY 0x00703fd0
void __cdecl Interface_MessageMenuYesToAll()
{
    MessageMenu_ProcessYesToAll();
}

extern void __cdecl UpdateSurgeryScene();
// @fnv 0x00709ae0
// src: COMMUNITY 0x00709ae0
void __cdecl Interface_DrawSurgeryMenu3D()
{
    UpdateSurgeryScene();
}

void __cdecl LockPickMenu_DrawScene();

// @fnv 0x00709af0
// src: COMMUNITY 0x00709af0
void __cdecl Interface_DrawLockpickMenu3D()
{
    LockPickMenu_DrawScene();
}

void __cdecl SlotMachineMenu_DrawScene();

// @fnv 0x00709b00
// src: COMMUNITY 0x00709b00
void __cdecl Interface_DrawSlotMachineMenu3D()
{
    SlotMachineMenu_DrawScene();
}

void RouletteMenu_DrawScene();

// @fnv 0x00709b20
// src: COMMUNITY 0x00709b20
void Interface_DrawRouletteMenu3D()
{
    RouletteMenu_DrawScene();
}

void __cdecl FUN_00740f30_callee(void);

// @fnv 0x00709b30
// src: COMMUNITY 0x00709b30
void __cdecl Interface_DrawCaravanMenu3D(void)
{
    FUN_00740f30_callee();
}

void RenderFaceGenScene();

// @fnv 0x00709b40
// src: COMMUNITY 0x00709b40
void __cdecl Interface_DrawHUDMenu3D()
{
    RenderFaceGenScene();
}

void HUDMainMenu_ClearGunScope();

// @fnv 0x00709ca0
// src: XBOX_PDB 0x00709ca0
void Interface_ClearGunScope()
{
    HUDMainMenu_ClearGunScope();
}

unsigned char __cdecl HUDMainMenu_IsGunScopeVisible();

// @fnv 0x00709cb0
// src: COMMUNITY 0x00709cb0
void __cdecl Interface_IsGunScopeVisible()
{
    HUDMainMenu_IsGunScopeVisible();
}

void __cdecl VATSMenu_GetIsARescan();

// @fnv 0x00709d00
// src: COMMUNITY 0x00709d00
void __cdecl Interface_GetIsVATSRescanning()
{
    VATSMenu_GetIsARescan();
}

namespace fnv_00709d10 {
extern bool g_flag;

// @fnv 0x00709d10
// src: COMMUNITY 0x00709d10
bool __cdecl VATSMenu_GetIsARescan()
{
    return g_flag;
}
}  // namespace fnv_00709d10






struct SettingF
{
    float* Float();
};
extern SettingF g_01203150;

bool __cdecl is_bEyeFinity();
float __cdecl GetGlobalArg1();
double __cdecl Get_1280();
double __cdecl Get_720();
float __cdecl tan_0057dd70(float);

// Sets the camera's near plane and builds a frustum from the FOV, aspect ratio and near distance, then applies it to the camera.
// @fnv 0x00709d50
void __cdecl UpdateCameraFrustum(NiCamera* pCamera, float fFOV)
{
    float fAspect;
    if (pCamera && is_bEyeFinity())
    {
        float fNear = GetGlobalArg1();
        pCamera->SetMinNearPlaneDist(fNear, false);
        fAspect = Get_1280() / Get_720();
        float fHalfFOV = (fFOV * *g_01203150.Float() * (double)0.017453292f * (double)1.1f < (double)1.5393804f)
                             ? fFOV * *g_01203150.Float() * (double)0.017453292f * (double)1.1f
                             : (double)1.5393804f;
        NiFrustum kFrustum;
        kFrustum.Init(false);
        kFrustum.m_fLeftBound = -tan_0057dd70(fHalfFOV) * fNear * fAspect;
        kFrustum.m_fRightBound = tan_0057dd70(fHalfFOV) * fNear * fAspect;
        kFrustum.m_fBottomBound = -tan_0057dd70(fHalfFOV) * fNear;
        kFrustum.m_fTopBound = tan_0057dd70(fHalfFOV) * fNear;
        kFrustum.m_bOrthographic = false;
        kFrustum.m_fNearPlane = 1.0f;
        kFrustum.m_fFarPlane = 5000.0f;
        pCamera->UpdateViewFrustum(kFrustum);
    }
}

struct StrHolderSub
{
    int unk00;
    StrHolderSub();
    ~StrHolderSub();
    void Reset();
    int Get();
};

void FormatInto(StrHolderSub* p, const char* fmt, const char* s);
void ReleaseWith(int r, int a);

class FUN_00719160_cls
{
  public:
    virtual void Unk00();
    StrHolderSub m_04;

    FUN_00719160_cls(const char* a1, int a2);
};

// Formats "&%s;" into m_04, resets it, then calls ReleaseWith with m_04.Get() and a2.
// @fnv 0x00719160
FUN_00719160_cls::FUN_00719160_cls(const char* a1, int a2)
{
    FormatInto(&m_04, "&%s;", a1);
    m_04.Reset();
    ReleaseWith(m_04.Get(), a2);
}

extern char vftable_FUN_00719390;

struct FUN_004037d0_Class
{
    void __thiscall FUN_004037d0();
};

// @fnv 0x00719230
void FUN_00719390_class::ConstructAndInit()
{
    reinterpret_cast<void**>(this)[0] = reinterpret_cast<void*>(&vftable_FUN_00719390);
    reinterpret_cast<FUN_004037d0_Class*>(reinterpret_cast<char*>(this) + 4)->FUN_004037d0();
}

class FUN_00719ca0_cls
{
  public:
    int GetKey();
};

// Compares two objects by their GetKey() values, returning -1, 1, or 0.
// @fnv 0x00719ca0
// src: COMMUNITY 0x00719ca0
int __cdecl InventoryList_SortByQty(FUN_00719ca0_cls* apLeft, FUN_00719ca0_cls* apRight)
{
    if (apLeft->GetKey() < apRight->GetKey())
    {
        return -1;
    }
    else
    {
        if (apLeft->GetKey() > apRight->GetKey())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

struct SrcObj
{
    TESBoundObject* FUN_0044ddc0();
};

// @fnv 0x00719cf0
// src: COMMUNITY 0x00719cf0
int __cdecl InventoryList_SortByHealth(SrcObj* apSrcObjA, SrcObj* apSrcObjB)
{
    TESHealthForm* y;
    TESHealthForm* x;
    x = dynamic_cast<TESHealthForm*>(apSrcObjA->FUN_0044ddc0());
    y = dynamic_cast<TESHealthForm*>(apSrcObjB->FUN_0044ddc0());
    if (x->GetHealth() < y->GetHealth())
    {
        return -1;
    }
    else
    {
        if (x->GetHealth() > y->GetHealth())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

struct FUN_0071dec0_Base
{
    void RemoveAll();
    ~FUN_0071dec0_Base();
};

struct FUN_0071dec0 : FUN_0071dec0_Base
{
    ~FUN_0071dec0();
};

// @fnv 0x0071dec0
FUN_0071dec0::~FUN_0071dec0()
{
    RemoveAll();
}

struct FUN_00501c10_Class
{
    void __thiscall CallAndReturnSelf(int value);
};

struct FUN_0071df60_Class
{
    void* __thiscall TextNode_Create_();
    void __thiscall NiTListBase_NiTPointerAllocator_unsigned_int_BSFaceGenKeyframe_AddNodeTail(void* value);
    void __thiscall NiTPointerListBase_DFALL_NiTListItem_BSStringT_char_BSStringT_char_AddTail(int value);
};

// Retrieves an object via FUN_0071e0d0, passes value to the object at offset 8, then forwards the object to FUN_00559a70.
// @fnv 0x0071df60
// src: COMMUNITY 0x0071df60
void __thiscall FUN_0071df60_Class::NiTPointerListBase_DFALL_NiTListItem_BSStringT_char_BSStringT_char_AddTail(int value)
{
    void* result = this->TextNode_Create_();

    reinterpret_cast<FUN_00501c10_Class*>(reinterpret_cast<unsigned char*>(result) + 8)->CallAndReturnSelf(value);

    this->NiTListBase_NiTPointerAllocator_unsigned_int_BSFaceGenKeyframe_AddNodeTail(result);
}

class C71DFA0String
{
  public:
    C71DFA0String(const C71DFA0String& kOther);
    ~C71DFA0String();

    char* m_pcData;
    unsigned short m_usLength;
    unsigned short m_usCapacity;
};

struct C71DFA0Node
{
    C71DFA0Node* m_pkNext;
    C71DFA0Node* m_pkPrev;
    C71DFA0String m_kValue;
};

class C71DFA0StringQueue
{
  public:
    C71DFA0Node* m_pkHead;
    C71DFA0Node* m_pkTail;
    unsigned int m_uiCount;

    void FreeNode(C71DFA0Node* pkNode);
    C71DFA0String PopFront();
};

// Removes the head node from the queue, copies its string value, frees the node, decrements the count and returns the value.
// @fnv 0x0071dfa0
C71DFA0String C71DFA0StringQueue::PopFront()
{
    C71DFA0Node* pkNode = m_pkHead;
    m_pkHead = m_pkHead->m_pkNext;
    if (m_pkHead)
        m_pkHead->m_pkPrev = 0;
    else
        m_pkTail = 0;
    C71DFA0String kValue(pkNode->m_kValue);
    FreeNode(pkNode);
    m_uiCount--;
    return kValue;
}

struct FUN_0071e1e0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_0071e1e0();
};
struct Factory_0071e120
{
    FUN_0071e1e0* CreateInstance();
};
// Allocates and constructs a new FUN_0071e1e0 object, returning its pointer.
// @fnv 0x0071e120
FUN_0071e1e0* Factory_0071e120::CreateInstance()
{
    return new FUN_0071e1e0;
}

struct FUN_0071f4e0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    void* m_08;
    void UpdateFields_0071f4e0();
};

struct Fun4459Callee
{
    void* __thiscall FUN_004459e0(int flag);
};

// If m_08 is non-null, calls FUN_004459e0 with flag 1 on it.
// @fnv 0x0071f4e0
// src: GUESS 0x0071f4e0 (confidence: low)
void FUN_0071f4e0_cls::UpdateFields_0071f4e0()
{
    void* v = this->m_08;
    void* w = v;
    w != 0 ? reinterpret_cast<Fun4459Callee*>(w)->FUN_004459e0(1) : 0;
}

struct FUN_00406de0
{
    ~FUN_00406de0();
};

struct FUN_0071f570
{
    ~FUN_0071f570();
};

struct FUN_0071f9f0
{
    int unk00;
    FUN_00406de0 unk04;
    int unk08;
    int unk0c;
    FUN_0071f570 unk10;

    ~FUN_0071f9f0();
};

// Destructor for the object; it destroys its member objects and returns.
// @fnv 0x0071f9f0
FUN_0071f9f0::~FUN_0071f9f0()
{}

void __cdecl ourMemset(void* p, int value, unsigned int size);

class GlobalTaskQueue
{
  public:
    void Submit(int a, int b);
};

extern GlobalTaskQueue g_taskQueue;

class TaskSubObject
{
  public:
    TaskSubObject();
    ~TaskSubObject();
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
};

class FUN_0071fa80_base
{
  public:
    virtual void unk00();
    FUN_0071fa80_base();
    ~FUN_0071fa80_base();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
};

class FUN_0071fa80 : public FUN_0071fa80_base
{
  public:
    virtual void unk00();
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    TaskSubObject m_34;
    unsigned int m_58;
    FUN_0071fa80();
};

// Zeroes the 12-byte block at m_28, submits a task to g_taskQueue, and sets m_58 to 0.
// @fnv 0x0071fa80
FUN_0071fa80::FUN_0071fa80()
{
    ourMemset(&m_28, 0, 0xc);
    g_taskQueue.Submit(0, 0);
    m_58 = 0;
}

struct StandIn_700500
{
    void* m_ppVirtualMethodTable;
    void* m_data;
};

void __cdecl NiTMallocInterface_unsigned_int_Deallocate(void*);

// @fnv 0x00700500
// src: GUESS 0x00700500 (confidence: low)
void FUN_007004e0_class::UpdateFields_00700500()
{
    ((StandIn_700500*)this)->m_ppVirtualMethodTable = &DAT_0106e8dc;
    NiTMallocInterface_unsigned_int_Deallocate(((StandIn_700500*)this)->m_data);
}

struct DbgRef
{
    unsigned int GetRefID();
    const char* GetFullName();
};
struct DbgIface
{
    bool IsDebugTextOn();
    void SetDebugRef(DbgRef* ref);
};
DbgIface* __cdecl GetDbgIface();
struct IntSetting
{
    int* Int();
};
extern IntSetting g_fontSetting;
extern IntSetting g_debugTextX;
struct DbgFont
{
    float GetLineHeight();
};
struct DbgFontMgr
{
    static DbgFontMgr* Instance();
    DbgFont* GetFont(int id);
};
struct DbgColor;
struct DbgText
{
    static DbgText* __cdecl Instance(bool create);
    int Print(const char* text, float x, float y, int a, int b, float dur, int c, const DbgColor* color);
};

static const char kRefFmt[] = "\"%s\" (%08x)";

// @fnv 0x007031e0
// src: XBOX_PDB 0x007031e0
void Interface_SetTargetREFR(DbgRef* ref)
{
    if (GetDbgIface() && GetDbgIface()->IsDebugTextOn())
    {
        BSStringT<char> text;
        if (ref)
        {
            text.PrintfString(kRefFmt, ref->GetFullName(), ref->GetRefID());
            int height = (int)DbgFontMgr::Instance()->GetFont(*g_fontSetting.Int() - 1)->GetLineHeight() + 3;
            int x = *g_debugTextX.Int();
            DbgText::Instance(true)->Print(text.String(), 640.0f, (float)x, 2, -1, -1.0f, 0, 0);
        }
        GetDbgIface()->SetDebugRef(ref);
    }
}

extern "C" void* __cdecl InterfaceManager_GetSingleton();
extern "C" void* __cdecl Tile_GetMenuByClass(int);




// If a modifier key is held, looks up tile 0x3f1's menu as a DialogMenu and returns its cast sound, otherwise null.
// @fnv 0x00705190
TESSound* GetDialogCastSound()
{
    if (InterfaceManager_GetSingleton() && ((Modifier*)InterfaceManager_GetSingleton())->GetKey())
    {
        Tile* pTile = (Tile*)Tile_GetMenuByClass(0x3f1);
        DialogMenu* pDialogMenu = pTile != 0 ? dynamic_cast<DialogMenu*>(pTile->GetMenu()) : 0;
        if (pDialogMenu != 0)
            return pDialogMenu->GetCastSound();
    }
    return 0;
}

bool __cdecl FUN_00705ea0();
bool __cdecl StartMenu_MainMenuIsActive();
struct ConsoleSetting
{
    int* Setting_Int();
};
extern ConsoleSetting g_011d8d38;
extern ConsoleSetting g_011d8cf0;
struct ConsoleFont
{
    int Font_LineBreakText(BSStringT<char>*, int*, int*, int, int);
};
struct ConsoleFontManager
{
    ConsoleFont* FUN_005bd5c0(int);
};
ConsoleFontManager* __cdecl FUN_005bd5b0();
struct ConsoleTextQueue
{
    void* head;
    void* tail;
    int count;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int FUN_0044ddc0();
    void NiTPointerListBase_DFALL_NiTListItem_BSStringT_char_BSStringT_char_AddTail(const BSStringT<char>&);
    BSStringT<char> PopFront();
};
struct ConsoleText
{
    int unk00;
    ConsoleTextQueue lines;
    int currentLine;
    void WriteLine(const char*);
    void DrawConsoleLines();
    void Console_Print(const char*, char*);
};
// Formats the text, appends it to the console line queue, wraps it into lines using the console font, and trims overflow lines.
// @fnv 0x0071d0a0
// src: COMMUNITY 0x0071d0a0
void ConsoleText::Console_Print(const char* format, char* arguments)
{
    if (FUN_00705ea0() && !StartMenu_MainMenuIsActive())
        return;
    BSStringT<char> a;
    a.VSPrintF(format, arguments);
    WriteLine(a.String());
    int s = 1200;
    int p = 0;
    int h = FUN_005bd5b0()->FUN_005bd5c0(*g_011d8d38.Setting_Int() - 1)->Font_LineBreakText(&a, &s, &p, 0, 0);
    if (h == 0)
        return;
    char i[2048];
    unsigned int eb;
    for (eb = 0; eb <= a.Length(); ++eb)
        i[eb] = a.String()[eb];
    char* f = i;
    for (int q = 0; q < h; ++q)
    {
        bool j = false;
        if (currentLine == lines.FUN_0044ddc0())
            j = true;
        BSStringT<char> l;
        l = f;
        lines.NiTPointerListBase_DFALL_NiTListItem_BSStringT_char_BSStringT_char_AddTail(l);
        if (j)
            currentLine = lines.FUN_0044ddc0();
        while (lines.FUN_0044ddc0() > *g_011d8cf0.Setting_Int())
        {
            lines.PopFront();
            currentLine--;
        }
        if (q + 1 < h)
        {
            while (*f)
                ++f;
            ++f;
        }
    }
    if (currentLine == lines.FUN_0044ddc0())
        DrawConsoleLines();
}

namespace fnv_0071f340 {
struct ListElem
{
    ListElem();
    ~ListElem();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct Sub68
{
    Sub68();
    ~Sub68();
    int unk00;
    int unk04;
    int unk08;
};
struct Sub84
{
    Sub84();
    ~Sub84();
    int unk00;
    int unk04;
    int unk08;
};
struct Block90
{
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
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
};
struct T721060
{
    T721060();
    ~T721060();
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
};
struct T721850
{
    T721850();
    ~T721850();
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
};
struct T722000
{
    T722000();
    ~T722000();
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
};
struct T7227b0
{
    T7227b0();
    ~T7227b0();
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
};
struct T722f60
{
    T722f60();
    ~T722f60();
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
};

class FUN_0071f340 : public Menu
{
  public:
    ListElem unk28[4];
    Sub68 unk68;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    Sub84 unk84;
    Block90 unk90;
    T721060 unk180;
    T721060 unk1B0;
    T721850 unk1E0;
    T722000 unk210;
    T7227b0 unk240;
    T722f60 unk270;
    char unk2A0;
    char unk2A1;
    FUN_0071f340();
    virtual ~FUN_0071f340();
};
// Zeroes the unk90 block, initializes unk74, unk78, unk80, unk7C, unk2A1 and unk2A0 to zero.
// @fnv 0x0071f340
FUN_0071f340::FUN_0071f340()
{
    ourMemset(&unk90, 0, sizeof(unk90));
    unk74 = 0;
    unk78 = 0;
    unk80 = 0;
    unk7C = 0;
    unk2A1 = 0;
    unk2A0 = 0;
}
}  // namespace fnv_0071f340

class List71F
{
  public:
    ~List71F();

    void* m_pkItem;
    List71F* m_pkNext;
};

class FUN_0071f570_ModelList
{
  public:
    virtual ~FUN_0071f570_ModelList();

    void Clear();

    List71F m_kModels;
};

// @fnv 0x0071f570
FUN_0071f570_ModelList::~FUN_0071f570_ModelList()
{
    Clear();
}

struct Base
{
    virtual void v();
};

struct FUN_0071f600 : Base
{
    BSSimpleList<int> m_kNode;
    void __thiscall StatsMenu_StatusEffectList_Flush();
    ~FUN_0071f600();
};

// @fnv 0x0071f600
FUN_0071f600::~FUN_0071f600()
{
    StatsMenu_StatusEffectList_Flush();
}

namespace fnv_0071fbf0 {
class GlobalObject_0041a250
{
  public:
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    unsigned int value;
    bool active;
    void* object;
};
class GlobalObject_00633c90
{
  public:
    GlobalObject_00633c90();
    GlobalObject_00633c90(int);
    ~GlobalObject_00633c90();
    GlobalObject_00633c90& operator=(int);
    void* object;
};
extern GlobalObject_00633c90 g_011dadb4, g_011dade8, g_011dae5c;
struct MenuPoint2
{
    MenuPoint2();
    float x, y;
};
struct MenuPoint3
{
    MenuPoint3();
    float x, y, z;
};
class FUN_0071fbf0 : public Menu
{
  public:
    virtual ~FUN_0071fbf0();
    unsigned int m28;
    void* tile2c;
    void* tile30;
    void* tile34;
    void* tile38;
    void* tile3c;
    void* tile40;
    void* tile44;
    void* tile48;
    void* tile4c;
    void* tile50;
    void* tile54;
    void* tile58;
    void* tile5c;
    void* tile60;
    void* tile64;
    void* tile68;
    void* tile6c;
    void* tile70;
    MenuPoint2 point74, point7c;
    float m84;
    int m88, m8c;
    bool m90, m91;
    GlobalObject_0041a250 handle94, handlea0;
    float mac;
    int mb0, mb4, mb8, mbc, mc0, mc4;
    GlobalObject_00633c90 nodes[6];
    int me0, me4, me8;
    float mec;
    GlobalObject_00633c90 nodef0, nodef4;
    MenuPoint3 pointf8, point104;
    int m110, m114, m118, m11c, m120, m124;
    MenuPoint3 point128;
    int m134, m138, m13c, m140, m144, m148;
    float m14c;
    MenuPoint3 point150;
    bool m15c, m15d;
    FUN_0071fbf0();
};
// @fnv 0x0071fbf0
FUN_0071fbf0::FUN_0071fbf0() : nodef0(0), nodef4(0)
{
    ourMemset(&tile2c, 0, 0x48);
    g_011dadb4 = 0;
    g_011dade8 = 0;
    g_011dae5c = 0;
    nodef0 = 0;
    nodef4 = 0;
    for (int i = 0; i < 6; ++i)
        nodes[i] = 0;
    me0 = 0;
    me4 = 0;
    mbc = 0;
    me8 = 0;
    mec = 0.0f;
    m84 = 0.0f;
    mac = 0.0f;
    m14c = 0.0f;
    mb8 = 1000;
    m88 = 0;
    m8c = 0;
    mb0 = 0;
    mb4 = 0;
    mb8 = 0;
    m90 = false;
    m91 = false;
    m15c = false;
    m15d = false;
    point7c.x = 0.0f;
    point7c.y = 0.0f;
    point74.x = 0.0f;
    point74.y = 0.0f;
    mc0 = 27;
    mc4 = 1;
    m28 = 0;
}
}  // namespace fnv_0071fbf0

struct ScopedMenuAccess
{
    int handle;
    ScopedMenuAccess(int kind, int enabled, const char* fileName, int line);
    ~ScopedMenuAccess();
};
struct MenuFrame;
struct MenuFrameProvider
{
    MenuFrame* Main_GetControls();
};
struct MenuFrame
{
    void Controls_ClearKeystrokes();
};
extern MenuFrameProvider* DAT_011dea0c;
struct MenuGate
{
    bool TES_CellTestRunning();
};
extern MenuGate* DAT_011dea10;
extern char DAT_0106ef50;
extern double DAT_01012070;
extern int DAT_011d8a90;

struct MenuComponent
{
    virtual ~MenuComponent();
    bool FUN_00712380();
    bool IsTraitNonZero(int);
    void FUN_00700320(int trait, int enable);
    MenuComponent* GetModel_0056c7f0();
    void FUN_00450f90(int);
    void Tile_UpdateTile(int);
    void ImageSpaceManager_SetMenuBGBlendValue();
    void ImageSpaceManager_SetMenuBGBlendEnabled();
};
struct MenuActor
{
    MenuComponent* FUN_00726070();
    int FUN_0059bb30();
    void FUN_007037c0(int mode);
};
struct MenuSource
{
    MenuActor* Tile_GetMenu();
};
// distinct from MenuList: 0x00711ea0 walks this nonvirtual pointer-list access view via GetNext 0x0057cbe0; the shared MenuList is a virtual UI list box.
struct BlkMenuListView
{
    int Modelloader_GetReferencedThis();
    MenuSource** NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(int* frame);
};
struct MenuCollection
{
    int bookkeeping;
    BlkMenuListView list;
};
struct MenuState
{
    MenuCollection* CombatController_GetCombatState();
    int FUN_00714f00();
    int FUN_00714f70(int);
    void SetNodeAlpha(MenuComponent* source, float amount, float offset);
    void UpdateMenuSelection();
};
float __cdecl InterfaceManager_GetMenuFade(MenuActor*);
double __cdecl FUN_00408840(float);
MenuComponent* __stdcall BSShaderManager_GetImageSpaceManager(float);
MenuComponent* __stdcall BSShaderManager_GetImageSpaceManager(int);
bool __cdecl InterfaceManager_Has360Controller();

// @fnv 0x00711ea0
void MenuState::UpdateMenuSelection()
{
    ScopedMenuAccess scope(13, 1, &DAT_0106ef50, 0xca1);
    MenuFrame* cursor = DAT_011dea0c->Main_GetControls();
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x11) = 0;
    int frame = CombatController_GetCombatState()->list.Modelloader_GetReferencedThis();
    while (frame != 0)
    {
        MenuSource* pSource = *CombatController_GetCombatState()->list.NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&frame);
        MenuActor* actor = 0;
        if (pSource)
            actor = pSource->Tile_GetMenu();
        if (actor && actor->FUN_00726070() && !actor->FUN_00726070()->FUN_00712380())
        {
            float amount = InterfaceManager_GetMenuFade(actor);
            bool leftSlot = FUN_00408840(amount) == DAT_01012070;
            int selection = actor->FUN_0059bb30();
            int rightSlot = FUN_00714f00();
            int direction = FUN_00714f70(0);
            int threshold = FUN_00714f70(1);
            if (selection == 2)
            {
                bool shouldUpdate =
                    ((rightSlot == 0 && direction == 0) || (direction != 0 && threshold == 0 && direction == 1001));
                if (actor && leftSlot)
                {
                    actor->FUN_007037c0(4);
                    if (actor->FUN_00726070()->IsTraitNonZero(0x1772))
                    {
                        if (actor->FUN_00726070())
                        {
                            delete actor->FUN_00726070();
                        }
                        actor = 0;
                        frame = 0;
                    }
                    else
                    {
                        actor->FUN_00726070()->FUN_00700320(0xfa3, 0);
                        SetNodeAlpha(actor->FUN_00726070()->GetModel_0056c7f0(), 0.0f, 0.0f);
                        if (shouldUpdate)
                        {
                            BSShaderManager_GetImageSpaceManager(0.0f)->ImageSpaceManager_SetMenuBGBlendValue();
                            BSShaderManager_GetImageSpaceManager(0)->ImageSpaceManager_SetMenuBGBlendEnabled();
                        }
                    }
                }
                else
                {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x11) = 1;
                    actor->FUN_00726070()->FUN_00700320(0xfa3, 1);
                    SetNodeAlpha(actor->FUN_00726070()->GetModel_0056c7f0(), 1.0f - amount, 0.0f);
                    if (shouldUpdate)
                        BSShaderManager_GetImageSpaceManager(1.0f - amount)->ImageSpaceManager_SetMenuBGBlendValue();
                }
            }
            else if (selection == 8)
            {
                bool shouldUpdate = ((rightSlot != 0 && direction == rightSlot && rightSlot != 1001) ||
                                     (threshold != 0 && threshold == rightSlot && direction == 1001));
                if (leftSlot)
                {
                    actor->FUN_00726070()->FUN_00700320(0xfa3, 1);
                    SetNodeAlpha(actor->FUN_00726070()->GetModel_0056c7f0(), 1.0f, 0.0f);
                    actor->FUN_007037c0(1);
                    if (shouldUpdate)
                    {
                        BSShaderManager_GetImageSpaceManager(1.0f)->ImageSpaceManager_SetMenuBGBlendValue();
                        BSShaderManager_GetImageSpaceManager(0)->ImageSpaceManager_SetMenuBGBlendEnabled();
                    }
                }
                else
                {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x11) = 1;
                    actor->FUN_00726070()->FUN_00700320(0xfa3, 1);
                    SetNodeAlpha(actor->FUN_00726070()->GetModel_0056c7f0(), amount, 0.0f);
                    if (shouldUpdate)
                        BSShaderManager_GetImageSpaceManager(amount)->ImageSpaceManager_SetMenuBGBlendValue();
                }
            }
        }
    }
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc) == 4 &&
        (!*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x11) || DAT_011dea10->TES_CellTestRunning()))
    {
        cursor->Controls_ClearKeystrokes();
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc) = 1;
        if (!InterfaceManager_Has360Controller() || *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x7d))
        {
            reinterpret_cast<MenuComponent*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x28))
                ->GetModel_0056c7f0()
                ->FUN_00450f90(1);
            reinterpret_cast<MenuComponent*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x28))
                ->FUN_00700320(0xfa3, 0);
        }
        reinterpret_cast<MenuComponent*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x28))
            ->Tile_UpdateTile(1);
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x14c) = 0;
    }
    DAT_011d8a90 = 99;
}

void __cdecl operator delete(void*);
struct ListNode7164
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ListNode7164* m_next;
};

class Owner7164
{
  public:
    int unk000;
    int unk004;
    int unk008;
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
    ListNode7164* m_kNode;
    void InterfaceManager_FreeTimerList();
};
// @fnv 0x00716450
// src: COMMUNITY 0x00716450
void Owner7164::InterfaceManager_FreeTimerList()
{
    ListNode7164* node = m_kNode->m_next;
    while (node)
    {
        ListNode7164* cur = node;
        node = node->m_next;
        delete cur;
    }
    delete m_kNode;
    m_kNode = 0;
}

class FUN_0071f930
{
  public:
    int unk00;
    BSSimpleList<int> m_akLists[6];

    ~FUN_0071f930();
};

// Removes all elements from each of the six BSSimpleList<int> members in m_akLists.
// @fnv 0x0071f930
FUN_0071f930::~FUN_0071f930()
{
    for (int i = 0; i < 6; i++)
        m_akLists[i].RemoveAll();
}

#include <stdio.h>
struct InventoryMenuSetting
{
    unsigned int type;
    const char* value;
    const char* name;
    const char* FUN_00403df0();
};
extern OSGlobals* g_osGlobals;
extern InventoryMenuSetting* DAT_011d5268[];
extern InventoryMenuSetting* DAT_011d5240[];
extern InventoryMenuSetting* DAT_011d52f0[];
extern InventoryMenuSetting* DAT_011d51b0[];
extern InventoryMenuSetting g_011d37b0;
extern InventoryMenuSetting g_011d4a08;
extern InventoryMenuSetting g_011d3fc4;
void ourStrcpy(char*, const char*);
bool InterfaceManager_Has360Controller();
int BSstristr(const char*, const char*);
// Looks up a setting for control and copies its string into output; if prefix is set, rewrites output as '%s %s' with a prefix string and that text.
// @fnv 0x007039b0
void __cdecl GetControlLabel(int control, char* output, bool prefix)
{
    if (control < 0 || control > 28)
        return;
    InventoryMenuSetting* setting = 0;
    *output = 0;
    if (InterfaceManager_Has360Controller())
    {
        setting = DAT_011d5268[reinterpret_cast<FUN_00703be0_Class*>(g_osGlobals->Main_GetControls())->GetByteAt(control, 3)];
    }
    else
    {
        unsigned char key = reinterpret_cast<FUN_00703be0_Class*>(g_osGlobals->Main_GetControls())->GetByteAt(control, 1);
        if (key >= 0 && key < 9)
        {
            setting = DAT_011d5240[key];
        }
        else
        {
            key = reinterpret_cast<FUN_00703be0_Class*>(g_osGlobals->Main_GetControls())->GetByteAt(control, 0);
            if (key >= 0 && key < 238)
            {
                setting = DAT_011d52f0[key];
            }
            else
            {
                key = reinterpret_cast<FUN_00703be0_Class*>(g_osGlobals->Main_GetControls())->GetByteAt(control, 2);
                if (key >= 0 && key < 8)
                    setting = DAT_011d51b0[key];
            }
        }
    }
    if (setting && setting->FUN_00403df0())
        ourStrcpy(output, setting->FUN_00403df0());
    if (prefix)
    {
        BSStringT<char> text;
        if (*output)
            text = output;
        else
            text = g_011d37b0.FUN_00403df0();
        if (setting && setting->name && BSstristr(setting->name, "trigger"))
            sprintf(output, "%s %s", g_011d4a08.FUN_00403df0(), text.String());
        else
            sprintf(output, "%s %s", g_011d3fc4.FUN_00403df0(), text.String());
    }
}

#include <string.h>
extern int DAT_010a2488;

struct FUN_0071dd90_shell
{
    void WriteLine(const char* apText);
};

// If the path at offset 0x810 is non-empty and apText is not, opens it as a BSFile, seeks, and writes apText followed by CRLF.
// @fnv 0x0071dd90
void FUN_0071dd90_shell::WriteLine(const char* apText)
{
    if (!*((char*)this + 0x810))
        return;
    unsigned int uiLen = apText ? strlen(apText) : 0;
    if (!uiLen)
        return;
    BSFile file((char*)this + 0x810, 1, 0x2800, true);
    if (file.Open(false, true))
    {
        file.BSFile::Seek(0, DAT_010a2488);
        file.BSFile_WriteF(static_cast<const void*>(apText), uiLen);
        file.BSFile_WriteF(static_cast<const void*>("\r\n"), 2);
    }
    file.Close();
}

struct FUN_0071e1e0_cls
{
    void Step();
    FUN_0071e1e0_cls* ProcessAndReturnValue_0071e1e0();
};

// @fnv 0x0071e1e0
// src: GUESS 0x0071e1e0 (confidence: low)
FUN_0071e1e0_cls* FUN_0071e1e0_cls::ProcessAndReturnValue_0071e1e0()
{
    Step();
    return this;
}

extern int DAT_011dea3c;
extern void* DAT_011c3b3c;

void* __cdecl FUN_004bf220(int arg);
void* __cdecl GetBipedModelTextureSwap(unsigned int a, int b);

struct GameObjStub
{
    void* FindEntryWithExtraListType(int index);
    unsigned int FUN_0044ddc0();
};

struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};

struct GameObjStub2
{
    void ModelLoader_ReleaseFile(void* arg);
    void* FUN_004459e0(int arg);
};


class FUN_00701520_cls
{
  public:
    void ProcessModelPaths();
};

// For each of 8 slots, resolves an object via FUN_00481090 or a TESModelTextureSwap cast and passes its model path to DAT_011c3b3c->FUN_0045a5e0.
// @fnv 0x00701520
// src: GUESS 0x00701520 (confidence: medium)
void FUN_00701520_cls::ProcessModelPaths()
{
    void* a = FUN_004bf220(DAT_011dea3c);

    for (int i = 0; i < 8; i++)
    {
        void* b = ((GameObjStub*)a)->FindEntryWithExtraListType(i);

        if (b != 0 && ((GameObjStub*)b)->FUN_0044ddc0() != 0)
        {
            void* c = GetBipedModelTextureSwap(((TESObjectREFR_GetFlags_Helper*)b)->CallGetFlags(), DAT_011dea3c);

            if (c == 0)
            {
                c = dynamic_cast<TESModelTextureSwap*>(
                    (TESBoundObject*)((TESObjectREFR_GetFlags_Helper*)b)->CallGetFlags());
            }

            if (c != 0)
            {
                ((GameObjStub2*)DAT_011c3b3c)->ModelLoader_ReleaseFile((void*)((TESModelTextureSwap*)c)->GetModelFilePath());
            }
        }

        {
            void* m = b;
            void* d = m;
            d != 0 ? ((GameObjStub2*)d)->FUN_004459e0(1) : 0;
        }
    }
}
