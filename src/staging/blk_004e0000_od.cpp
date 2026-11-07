
// src/staging/blk_004e0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

// Isolate legacy support declarations that shared headers also define.
#define _ULARGE_INTEGER LegacySupport__ULARGE_INTEGER
#include "../../include/layout_support.h"
#undef _ULARGE_INTEGER
#include "../../include/BSTextureManager.h"
#include "../../include/NiPointer.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/Setting.h"
// NiNodeHolder_blk_004e0000_od: local type (was include/NiNodeHolder.h, which had no evidence of one real class); its methods are 0x00559450 NiPointer<PathingSolution>::operator->, 0x0066b0d0 NiPointer<PathingSolution>::operator=
#include "../../include/NiRefObject.h"

class NiNode;
class CleanupObject;

class NiNodeHolder_blk_004e0000_od
{
public:
    NiRefObject* value;

    NiNodeHolder_blk_004e0000_od(NiRefObject* p);
    ~NiNodeHolder_blk_004e0000_od();
    operator NiNode*() const;
    void FUN_0066b0d0(CleanupObject* object);
    CleanupObject* Modelloader_GetReferencedThis();
};
#include "../../include/NiAVObject.h"
#include "../../include/NiNode.h"
#include "../../include/NiInterpController.h"
#include "../../include/MagicTarget.h"
// NiTexture and NiNode currently declare different NiTArray interfaces.
#include "../../include/NiSourceTexture.h"
#include "../../include/AnimIdle.h"
#include "../../include/BGSPlaceableWater.h"
#include "../../include/BGSProjectile.h"
#include "../../include/BGSTalkingActivator.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESSound.h"
#include "../../include/TESLandTexture.h"
#include "../../include/TESObjectACTI.h"
#include "../../include/TESObjectMISC.h"
#include "../../include/BGSConstructibleObject.h"
#include "../../include/TESDescription.h"


#include "../../include/BSTempEffect.h"
#include "../../include/DummyPointerMap.h"
#include "../../include/GO.h"
#include "../../include/MagicProjectile.h"
#include "../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../include/TESForm.h"
#include "../../include/NiPoint3.h"
#include "../../include/SL.h"
#include "../../include/TESRegionData.h"

// Returns the smaller of the two arguments: a if a is less than b, otherwise b.
// @fnv 0x004e2050
// src: COMMUNITY 0x004e2050
double MinOrEq(float afValue, double b)
{
    double result;
    if (afValue < b)
        result = afValue;
    else
        result = b;
    return result;
}

struct FUN_004e2100_Class
{
    void SetByteAtOffset166(int value);
};

// @fnv 0x004e2100
void FUN_004e2100_Class::SetByteAtOffset166(int value)
{
    ((unsigned char*)this)[0x166] = (unsigned char)value;
}



struct FUN_004e3280_shell
{
    BGSPlaceableWater* p;
    void BGSPlaceableWater_GetRefractionEnabled();
};

// @fnv 0x004e3280
// src: COMMUNITY 0x004e3280
void FUN_004e3280_shell::BGSPlaceableWater_GetRefractionEnabled()
{
    reinterpret_cast<BGSPlaceableWater*>(this)->HasFlags(0x200);
}

namespace fnv_004e3300 {


struct FUN_004e3300_shell : BGSPlaceableWater
{
    void BGSPlaceableWater_GetSilhouetteReflections();
};

// @fnv 0x004e3300
// src: COMMUNITY 0x004e3300
void FUN_004e3300_shell::BGSPlaceableWater_GetSilhouetteReflections()
{
    HasFlags(0x40000);
}
}  // namespace fnv_004e3300

void ClearField();

struct FUN_004e3c00_Class
{
    void BSShaderProperty_ClearRenderPasses();
};

// @fnv 0x004e3c00
// src: COMMUNITY 0x004e3c00
void FUN_004e3c00_Class::BSShaderProperty_ClearRenderPasses()
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3c))
    {
        reinterpret_cast<void(__thiscall*)(void*)>(ClearField)(
            reinterpret_cast<void*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3c)));
    }
}

struct FUN_004e3c20_class
{
    void ClearField();
};

// @fnv 0x004e3c20
void FUN_004e3c20_class::ClearField()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) = 0;
}




// @fnv 0x004e3c50
// src: COMMUNITY 0x004e3c50
bool BGSPlaceableWater::GetReflectionEnabled()
{
    return HasFlags(1);
}


namespace fnv_004e3c70 {




struct FUN_004e3c70_shell : BGSPlaceableWater
{
    bool BGSPlaceableWater_GetUnderwaterFog();
};

// @fnv 0x004e3c70
// src: COMMUNITY 0x004e3c70
bool FUN_004e3c70_shell::BGSPlaceableWater_GetUnderwaterFog()
{
    return !HasFlags(0x80000000);
}
}  // namespace fnv_004e3c70



// @fnv 0x004e3ca0
// src: COMMUNITY 0x004e3ca0
void BGSPlaceableWater::GetObjectTexCoordsEnabled()
{
    HasFlags(0x20000000);
}


struct FUN_004e3cc0_Class
{
    float GetFloatAtOffset9C();
};

// @fnv 0x004e3cc0
float FUN_004e3cc0_Class::GetFloatAtOffset9C()
{
    return *(float*)((char*)this + 0x9c);
}

struct FUN_004e3ce0_class
{
    float TESWaterForm_GetFogScale() const;
};

// @fnv 0x004e3ce0
// src: COMMUNITY 0x004e3ce0
float FUN_004e3ce0_class::TESWaterForm_GetFogScale() const
{
    return *(const float*)((const char*)this + 0x108);
}

struct FUN_004e3d20_class
{
    float GetFloatAtOffset128();
};

// @fnv 0x004e3d20
float FUN_004e3d20_class::GetFloatAtOffset128()
{
    return *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x128);
}

struct FUN_004e3d40_Class
{
    float __thiscall GetFloatAtOffset12C();
};

// @fnv 0x004e3d40
float __thiscall FUN_004e3d40_Class::GetFloatAtOffset12C()
{
    return *(float*)((char*)this + 0x12c);
}

float FUN_004e44d0(float);

// @fnv 0x004e44b0
// src: XBOX_PDB 0x004e44b0
float sin_004e44b0(float value)
{
    return FUN_004e44d0(value);
}

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011c7ac4;
// @fnv 0x004e89e0
// src: COMMUNITY 0x004e89e0
unsigned char Water_bUseWaterDisplacements_Get()
{
    return *g_011c7ac4.Bool();
}


extern NiPointer<NiNode> g_011d86bc;
struct Flt
{
    operator unsigned int();
};
struct FUN_004ea9e0_Class
{
    NiNode* __thiscall BGSTerrainManager_GetTreeNode();
};
// @fnv 0x004ea9e0
// src: COMMUNITY 0x004ea9e0
NiNode* __thiscall FUN_004ea9e0_Class::BGSTerrainManager_GetTreeNode()
{
    return (NiNode*)((Flt*)&g_011d86bc)->operator unsigned int();
}

extern "C" void* DAT_010231f4;
struct FUN_004ed7a0_class
{
    void* m_ptr;
    void __thiscall FUN_004ed960(void* a);
    void* __thiscall InitializeFields_004ed7a0(void* a);
};
// Calls FUN_004ed960(a), sets m_ptr to &DAT_010231f4, and returns this.
// @fnv 0x004ed7a0
// src: GUESS 0x004ed7a0 (confidence: low)
void* __thiscall FUN_004ed7a0_class::InitializeFields_004ed7a0(void* apArg)
{
    FUN_004ed960(apArg);
    m_ptr = &DAT_010231f4;
    return this;
}

extern int DAT_01023214;

struct FUN_004ed7d0_class
{
    int* p;
    void NiTMapBase_NiTPointerAllocator_unsigned_int_TESWaterForm_bool_NiTMapBase_NiTPointerAllocator_unsigned_int_TESWaterForm_bool(int a);
    FUN_004ed7d0_class* UpdateState_004ed7d0(int a);
};

// Calls FUN_004eda60 with a, sets p to point at DAT_01023214, and returns this.
// @fnv 0x004ed7d0
// src: GUESS 0x004ed7d0 (confidence: low)
FUN_004ed7d0_class* FUN_004ed7d0_class::UpdateState_004ed7d0(int a)
{
    NiTMapBase_NiTPointerAllocator_unsigned_int_TESWaterForm_bool_NiTMapBase_NiTPointerAllocator_unsigned_int_TESWaterForm_bool(a);
    p = &DAT_01023214;
    return this;
}

extern "C" void __cdecl NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_WadingWaterData_NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_WadingWaterData(int);
extern int DAT_01023234;

struct FUN_004ed800Class
{
    int* p;
    void __thiscall NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_WadingWaterData_NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_WadingWaterData(int arg);
    FUN_004ed800Class* __thiscall InitializeFields_004ed800(int arg);
};

// Calls FUN_004edb60 with arg, sets p to point at DAT_01023234, and returns this.
// @fnv 0x004ed800
// src: GUESS 0x004ed800 (confidence: low)
FUN_004ed800Class* __thiscall FUN_004ed800Class::InitializeFields_004ed800(int aiValue)
{
    this->NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_WadingWaterData_NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_WadingWaterData(aiValue);
    p = &DAT_01023234;
    return this;
}

struct FUN_0043ba10_shell
{
    FUN_0043ba10_shell* AssignInternedString(FUN_0043ba10_shell*);
};

struct FUN_004eeae0_shell
{
    void ForwardCall_004eeae0(int arg);
};

// @fnv 0x004eeae0
// src: GUESS 0x004eeae0 (confidence: low)
void FUN_004eeae0_shell::ForwardCall_004eeae0(int arg)
{
    ((FUN_0043ba10_shell*)((char*)this + 0x5c))->AssignInternedString((FUN_0043ba10_shell*)arg);
}

struct FUN_00456630_helper
{
    bool NiAVObject_GetBit(unsigned int);
};



// @fnv 0x004f0140
// src: XBOX_PDB 0x004f0140
bool NiAVObject::GetSelectiveUpdate()
{
    return ((FUN_00456630_helper*)this)->NiAVObject_GetBit(2);
}

struct FUN_004f0360_class
{
    bool HasFlag(unsigned short mask);
};
// @fnv 0x004f0360
bool FUN_004f0360_class::HasFlag(unsigned short mask)
{
    return (*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 8) & mask) != 0;
}

struct FUN_004f05a0_Class
{
    void HasFlag(int);
    void NiTimeController_GetActive();
};

// @fnv 0x004f05a0
// src: XBOX_PDB 0x004f05a0
void FUN_004f05a0_Class::NiTimeController_GetActive()
{
    HasFlag(8);
}

struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool enabled, unsigned int flag);
    void NiAVObject_SetRelevantImposter(bool enabled);
};

// @fnv 0x004f2620
// src: COMMUNITY 0x004f2620
void TaskQueueInterface::NiAVObject_SetRelevantImposter(bool enabled)
{
    SetTaskFlagDWord(enabled, 0x10000000);
}

struct FUN_004f2770_Class
{
    void* PlayerCharacter_GetAllOccupiedRegions();
};

// @fnv 0x004f2770
// src: COMMUNITY 0x004f2770
void* FUN_004f2770_Class::PlayerCharacter_GetAllOccupiedRegions()
{
    return reinterpret_cast<char*>(this) + 0x764;
}

struct GlobalObject_00633c90;
extern GlobalObject_00633c90 g_011c7ef8;
extern GlobalObject_00633c90 g_011c7f0c;


// @fnv 0x004f3310
void __cdecl ClearGlobalObjects()
{
    *(GO*)&g_011c7f0c = 0;
    *(GO*)&g_011c7ef8 = 0;
}

struct FUN_004f3660_class
{
    const char* p;
    int v;
    FUN_004f3660_class* InitializeFields_004f3660();
};

// Sets the object's p field to "p`r" and v to 0, then returns this.
// @fnv 0x004f3660
// src: GUESS 0x004f3660 (confidence: low)
FUN_004f3660_class* FUN_004f3660_class::InitializeFields_004f3660()
{
    p = "p`r";
    v = 0;
    return this;
}

struct S7010
{
    unsigned int Length();
    unsigned int GetLengthPlusOne();
};

// @fnv 0x004f4280
unsigned int S7010::GetLengthPlusOne()
{
    return Length() + 1;
}

struct FUN_004f6fc0_shell
{
    void TESRegionPoint_TESRegionPoint();
    FUN_004f6fc0_shell* ProcessAndReturnValue_004f87e0();
};

// @fnv 0x004f87e0
// src: GUESS 0x004f87e0 (confidence: low)
FUN_004f6fc0_shell* FUN_004f6fc0_shell::ProcessAndReturnValue_004f87e0()
{
    TESRegionPoint_TESRegionPoint();
    return this;
}

struct FUN_004f8a60_class
{
    void __thiscall SettingCollection_SetIniPath(int);
    void __thiscall SetField108(int);
};

// Calls FUN_004f8ac0(0) and stores a at offset 0x108 of this object.
// @fnv 0x004f8a60
void __thiscall FUN_004f8a60_class::SetField108(int aiValue)
{
    SettingCollection_SetIniPath(0);
    *(int*)((char*)this + 0x108) = aiValue;
}


struct FUN_004f8a90_Class
{
    void SettingCollectionMap_Setting_Get(unsigned int key, unsigned int& value);
};

// Looks up the value for key in the DummyPointerMap at offset 0x10c of this object and writes it to value.
// @fnv 0x004f8a90
// src: XBOX_PDB 0x004f8a90
void FUN_004f8a90_Class::SettingCollectionMap_Setting_Get(unsigned int key, unsigned int& value)
{
    ((DummyPointerMap*)((char*)this + 0x10c))->GetAt(key, value);
}



struct FUN_004f9ef0_shell
{
    int m0;
    int m1;
    FileEntryList m2;
    void CallInnerMethod();
};

// @fnv 0x004f9ef0
void FUN_004f9ef0_shell::CallInnerMethod()
{
    m2.FileEntryList::~FileEntryList();
}

struct FUN_004fb970_class
{
    unsigned char GetByteAtOffsetD9() const;
};

// @fnv 0x004fb970
unsigned char FUN_004fb970_class::GetByteAtOffsetD9() const
{
    return ((const unsigned char*)this)[0xd9];
}


// @fnv 0x004fd400
// src: XBOX_PDB 0x004fd400
EffectSetting* __thiscall MagicProjectile::GetAVEffect()
{
    return *(EffectSetting**)((char*)this + 0xa0);
}

struct FUN_004fd4f0_Class
{
    int __thiscall BGSProjectile_GetMotionType();
};

// @fnv 0x004fd4f0
// src: XBOX_PDB 0x004fd4f0
int __thiscall FUN_004fd4f0_Class::BGSProjectile_GetMotionType()
{
    return *(int*)((char*)this + 0x60) & 0x1f0000;
}



// @fnv 0x004fdf20
// src: COMMUNITY 0x004fdf20
bool BGSProjectile::GetCanTurnOff() const
{
    return GetFlag(0x20);
}




// @fnv 0x004fdf40
// src: COMMUNITY 0x004fdf40
bool BGSProjectile::GetCanPickup()
{
    return GetFlag(0x40);
}


struct FUN_004ffa60_class
{
    float f;
    int i;
    FUN_004ffa60_class* BSSimpleList_float_BSSimpleList_float(const FUN_004ffa60_class* src);
};

// Copies the float field from src into this object and resets the int field to zero, then returns this.
// @fnv 0x004ffa60
// src: COMMUNITY 0x004ffa60
FUN_004ffa60_class* FUN_004ffa60_class::BSSimpleList_float_BSSimpleList_float(const FUN_004ffa60_class* apSource)
{
    f = apSource->f;
    i = 0;
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_004ed830_Class
{
    void* __thiscall FUN_004ed830(unsigned int flags);
    void __thiscall FUN_004ed9d0();
};
// Calls FUN_004ed9d0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004ed830
void* __thiscall FUN_004ed830_Class::FUN_004ed830(unsigned int flags)
{
    FUN_004ed9d0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void* p);
struct FUN_004edad0_shell
{
    void __thiscall FUN_004edad0();
};
struct FUN_004ed860_class
{
    void* __thiscall FUN_004ed860(unsigned int flags);
};
// Calls FUN_004edad0 on this, deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x004ed860
void* __thiscall FUN_004ed860_class::FUN_004ed860(unsigned int flags)
{
    ((FUN_004edad0_shell*)this)->FUN_004edad0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void* p);
struct FUN_004ed890_Class
{
    void __thiscall FUN_004edbd0();
    void* __thiscall FUN_004ed890(unsigned int flags);
};
// Calls FUN_004edbd0, frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x004ed890
void* __thiscall FUN_004ed890_Class::FUN_004ed890(unsigned int flags)
{
    FUN_004edbd0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern unsigned int DAT_011c7870;
void __cdecl BSSleep(unsigned long);
// If DAT_011c7870 is nonzero, clamps it to 0x14, passes it to FUN_0040fca0, then resets DAT_011c7870 to 0.
// @fnv 0x004e1610
// src: COMMUNITY 0x004e1610
void SleepManager_RunSleep()
{
    if (DAT_011c7870 != 0)
    {
        if (DAT_011c7870 > 0x14)
        {
            DAT_011c7870 = 0x14;
        }
        BSSleep(DAT_011c7870);
        DAT_011c7870 = 0;
    }
}

// Returns the larger of the two arguments, comparing the float a against the double b.
// @fnv 0x004e2080
// src: COMMUNITY 0x004e2080
double MaxOrEq(float afValue, double b)
{
    double r;
    if (afValue > b)
        r = afValue;
    else
        r = b;
    return r;
}

extern unsigned char DAT_011ad7b4;

// @fnv 0x004e20b0
// src: COMMUNITY 0x004e20b0
void BSFadeNode_SetFadeEnabled(unsigned char value)
{
    DAT_011ad7b4 = value;
}

extern unsigned char DAT_011f91c4;
// @fnv 0x004e20f0
// src: COMMUNITY 0x004e20f0
void BSShaderManager_SetCurrentSceneGraph(unsigned char value)
{
    DAT_011f91c4 = value;
}

struct GlobalObject_00633c90;
extern GlobalObject_00633c90 g_011c7c28;

// @fnv 0x004e7ff0
// src: XBOX_PDB 0x004e7ff0
unsigned int TESWaterSystem_GetWaterRoot()
{
    return ((Flt*)&g_011c7c28)->operator unsigned int();
}

namespace fnv_004e8000 {
struct IdleCleanup { void NiNode_RemoveAllChildren(); };


extern GlobalObject_00633c90 g_011c7c28;

// If the global object holds a non-null pointer, calls FUN_004def90 on it, then assigns 0 to the global object.
// @fnv 0x004e8000
// src: COMMUNITY 0x004e8000
void TESWaterSystem_ClearWaterRoot()
{
    if (reinterpret_cast<Flt*>(&g_011c7c28)->operator unsigned int())
        reinterpret_cast<IdleCleanup*>(reinterpret_cast<Flt*>(&g_011c7c28)->operator unsigned int())->NiNode_RemoveAllChildren();
    reinterpret_cast<GO*>(&g_011c7c28)->operator=(0);
}
}  // namespace fnv_004e8000

struct FUN_004e8910_Class
{
    float f0;
    float f4;
    FUN_004e8910_Class* __thiscall Subtract(FUN_004e8910_Class* other);
};
// Subtracts the other object's f0 and f4 from this object's f0 and f4 and returns this.
// @fnv 0x004e8910
FUN_004e8910_Class* __thiscall FUN_004e8910_Class::Subtract(FUN_004e8910_Class* other)
{
    f0 -= other->f0;
    f4 -= other->f4;
    return this;
}

struct FUN_004f0110_Data
{
    int v[9];
};
struct FUN_004f0110_Holder
{
    char pad[0x2c];
    FUN_004f0110_Data d;
    void __thiscall bhkBlendCollisionObjectAddRotation_SetAdditionalRotation(FUN_004f0110_Data* src);
};
// Copies the nine-int data block pointed to by src into the holder's d field.
// @fnv 0x004f0110
// src: XBOX_PDB 0x004f0110
void __thiscall FUN_004f0110_Holder::bhkBlendCollisionObjectAddRotation_SetAdditionalRotation(FUN_004f0110_Data* pSource)
{
    d = *pSource;
}

struct Modifier
{
    float GetValue();
};
extern float DAT_01023900;
struct FUN_004f02e0_This
{
    unsigned char _pad[12];
    Modifier mod;
    bool NiQuatTransform_IsRotateValid();
};
// Returns true when the modifier's value differs from the negated DAT_01023900 constant.
// @fnv 0x004f02e0
// src: COMMUNITY 0x004f02e0
bool FUN_004f02e0_This::NiQuatTransform_IsRotateValid()
{
    return mod.GetValue() != -DAT_01023900;
}

extern "C" float DAT_01023900;
struct FUN_004f0320_class
{
    bool __thiscall NiQuatTransform_IsScaleValid();
};
// Returns whether the float at this+0x1c differs from the negation of DAT_01023900.
// @fnv 0x004f0320
// src: COMMUNITY 0x004f0320
bool __thiscall FUN_004f0320_class::NiQuatTransform_IsScaleValid()
{
    return *(float*)((char*)this + 0x1c) != -DAT_01023900;
}

struct FUN_004f32e0_class
{
    void __thiscall SetMaskedBits(unsigned short set, unsigned short clear, unsigned short shift);
};
// Clears the bits in clear and sets the shifted set bits in the 16-bit field at offset 4 of this object.
// @fnv 0x004f32e0
void __thiscall FUN_004f32e0_class::SetMaskedBits(unsigned short set, unsigned short clear, unsigned short shift)
{
    *(unsigned short*)((char*)this + 4) = (*(unsigned short*)((char*)this + 4) & ~clear) | (set << shift);
}

struct FUN_004f3330 : SL
{
    bool m_8;
    FUN_004f3330(bool v);
};
// Constructs the object and stores the given bool into m_8.
// @fnv 0x004f3330
FUN_004f3330::FUN_004f3330(bool abValue)
{
    m_8 = abValue;
}

struct FUN_004f5600_shell
{
    FUN_004f5600_shell();
};
extern int DAT_01023ec4;
struct FUN_004f5590 : FUN_004f5600_shell
{
    int m4;
    int m8;
    FUN_004f5590(int, int);
};
// @fnv 0x004f5590
FUN_004f5590::FUN_004f5590(int aiFirst, int aiSecond)
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_01023ec4);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4) = aiFirst;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 8) = aiSecond;
}

namespace fnv_004f5db0 {
struct FUN_004f5db0 : SL
{
    virtual ~FUN_004f5db0();
    unsigned char mC;
    int m10;
    FUN_004f5db0(unsigned char a);
};
// Initializes the object by storing the byte argument in mC and setting m10 to zero.
// @fnv 0x004f5db0
FUN_004f5db0::FUN_004f5db0(unsigned char aucValue)
{
    mC = aucValue;
    m10 = 0;
}
}  // namespace fnv_004f5db0

float __cdecl FUN_004f6e40(float);
struct Vec3i
{
    int x;
    int y;
    int z;
};
// @fnv 0x004f6e00
// src: XBOX_PDB 0x004f6e00
float TESRegionObject_ConvertNormalToAngle(int aiX, int aiY, int aiZ)
{
    Vec3i v;
    float len;
    v.x = aiX;
    v.y = aiY;
    v.z = aiZ;
    len = ((NiPoint3*)&v)->GetLengthSquared();
    return FUN_004f6e40(*(float*)&v.z / len);
}

struct BaseS
{
    int m0;
    int m1;
    BaseS();
};
struct FUN_004f7000 : BaseS
{
    FUN_004f7000(BaseS* p);
};
// @fnv 0x004f7000
FUN_004f7000::FUN_004f7000(BaseS* apSource) : BaseS()
{
    *(BaseS*)this = *apSource;
}

namespace fnv_004f7030 {
struct BaseS
{
    BaseS();
};
struct Modifier
{
    void __thiscall SetValue(float);
};
struct AlphaColor
{
    void __thiscall TESRegionPoint_SetX(float);
};
struct FUN_004f7030 : BaseS
{
    FUN_004f7030(float* p);
};
// Initializes the object by passing p[0] to FUN_0052ce20 and p[1] to SetValue.
// @fnv 0x004f7030
FUN_004f7030::FUN_004f7030(float* afPair)
{
    ((AlphaColor*)this)->TESRegionPoint_SetX(afPair[0]);
    ((Modifier*)this)->SetValue(afPair[1]);
}
}  // namespace fnv_004f7030

namespace fnv_004f7070 {
struct Modifier
{
    void __thiscall SetValue(float);
};
struct AlphaColor
{
    void __thiscall TESRegionPoint_SetX(float);
};
struct BaseS
{
    void __thiscall _ref_006815c0();
};
struct FUN_004f7070_shell
{
    void* __thiscall SetValues(float, float);
};
// Calls _ref_006815c0, then FUN_0052ce20 with a and SetValue with b, and returns this.
// @fnv 0x004f7070
void* __thiscall FUN_004f7070_shell::SetValues(float afFirst, float afSecond)
{
    ((BaseS*)this)->_ref_006815c0();
    ((AlphaColor*)this)->TESRegionPoint_SetX(afFirst);
    ((Modifier*)this)->SetValue(afSecond);
    return this;
}
}  // namespace fnv_004f7070

float __cdecl ConvertDoubleResult(float);
struct FUN_004f71f0_Class
{
    float SquaredDistanceTo(int);
    float EvaluateValue_004f71f0(int);
};
// @fnv 0x004f71f0
// src: GUESS 0x004f71f0 (confidence: low)
float FUN_004f71f0_Class::EvaluateValue_004f71f0(int a)
{
    if (a == 0)
        return -1.0f;
    return ConvertDoubleResult(SquaredDistanceTo(a));
}

namespace fnv_004f7230 {
struct RegionPoint
{
    float GetX() const;
};
struct Modifier
{
    float GetValue() const;
};
struct FUN_004f7230_Class
{
    float SquaredDistanceTo(RegionPoint* other) const;
};
// Returns the squared distance between this object and other using GetValue and GetX, or -1.0f when other is null.
// @fnv 0x004f7230
float FUN_004f7230_Class::SquaredDistanceTo(RegionPoint* other) const
{
    if (!other)
        return -1.0f;
    float fDeltaValue = ((Modifier*)this)->GetValue() - ((Modifier*)other)->GetValue();
    float fDeltaX = ((RegionPoint*)this)->GetX() - ((RegionPoint*)other)->GetX();
    return fDeltaValue * fDeltaValue + fDeltaX * fDeltaX;
}
}  // namespace fnv_004f7230

struct TaskQueueAttachHelper
{
    static void CopyStringToBuffer(char* dst, unsigned int len, const char* src);
};
// @fnv 0x004f8ac0
// src: COMMUNITY 0x004f8ac0
void __thiscall FUN_004f8a60_class::SettingCollection_SetIniPath(int apSource)
{
    if (apSource)
        TaskQueueAttachHelper::CopyStringToBuffer((char*)this + 4, 0x104, (const char*)apSource);
    else
        ((char*)this)[4] = 0;
}


// Exe 0x004fee20: unit-local ArrSI view; declarations and layout are preserved.
struct BlkOffset08View
{
    bool HasFlag10000000();
};
struct S_004fee20
{
    bool BGSTalkingActivator_IsNonPipboyRadioStation_0();
};
// Returns true when the talking activator is a radio station and the associated check succeeds.
// @fnv 0x004fee20
// src: COMMUNITY 0x004fee20
bool S_004fee20::BGSTalkingActivator_IsNonPipboyRadioStation_0()
{
    return ((BGSTalkingActivator*)this)->IsRadioStation() && ((BlkOffset08View*)this)->HasFlag10000000();
}

namespace fnv_004fee60 {

struct FUN_004fee20_shell
{
    bool BGSTalkingActivator_IsNonPipboyRadioStation_0() const;
};
// Returns true if form is a talking activator (type 0x16) that is a radio station and passes the FUN_004fee20 check.
// @fnv 0x004fee60
bool IsRadioStationTalkingActivator(TESForm* form)
{
    bool result = false;
    if (form && form->GetFormType() == 0x16)
    {
        BGSTalkingActivator* activator = (BGSTalkingActivator*)form;
        if (activator->IsRadioStation() && ((FUN_004fee20_shell*)activator)->BGSTalkingActivator_IsNonPipboyRadioStation_0())
            result = true;
    }
    return result;
}
}  // namespace fnv_004fee60

struct FUN_004e83e0_class
{
    bool __thiscall IsPlayerNearWaterActor(void* arg);
};
struct ReferenceList4e
{
    void* DereferenceIfNotNull(void*);
};
struct FUN_006317a0_struct
{
    int AddEight(int);
};
struct FUN_004e8950_class
{
    bool __thiscall TESWaterSystem_CheckUpdateActorsInWater();
};
// Iterates the list at offset 0x3c and returns true if IsPlayerNearWaterActor accepts any referenced object, otherwise false.
// @fnv 0x004e8950
// src: COMMUNITY 0x004e8950
bool __thiscall FUN_004e8950_class::TESWaterSystem_CheckUpdateActorsInWater()
{
    if (Water_bUseWaterDisplacements_Get())
    {
        unsigned int count = *reinterpret_cast<Flt*>(reinterpret_cast<unsigned char*>(this) + 0x3c);
        void* next = 0;
        while (count)
        {
            next = reinterpret_cast<ReferenceList4e*>(reinterpret_cast<unsigned char*>(this) + 0x3c)
                       ->DereferenceIfNotNull(reinterpret_cast<void*>(count));
            if (count)
            {
                TESObjectREFR* item = *reinterpret_cast<TESObjectREFR**>(
                    reinterpret_cast<FUN_006317a0_struct*>(reinterpret_cast<unsigned char*>(this) + 0x3c)
                        ->AddEight(count));
                if (reinterpret_cast<FUN_004e83e0_class*>(this)->IsPlayerNearWaterActor(item))
                    return true;
            }
            count = reinterpret_cast<unsigned int>(next);
        }
    }
    return false;
}

struct RDLItem
{
    virtual ~RDLItem();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual RDLItem* Clone();
};
struct RDLNode
{
    RDLItem** FUN_006815c0();
    RDLNode* FUN_00726070();
};
struct RDL_004f3330
{
    int list[2];
    bool owns;
    RDL_004f3330(bool owns);
    bool TESRegionDataList_Add(RDLItem* item);
    RDL_004f3330* TESRegionDataList_Copy(RDL_004f3330* dest);
};
// Copies each item of the node list into dest (or a new list), cloning items when the list owns them, and returns the destination list.
// @fnv 0x004f3470
// src: COMMUNITY 0x004f3470
RDL_004f3330* RDL_004f3330::TESRegionDataList_Copy(RDL_004f3330* dest)
{
    RDLNode* node = (RDLNode*)this;
    {
        RDL_004f3330* result = dest ? dest : new RDL_004f3330(owns);
        {
            RDLItem* copy = 0;
            while (node)
            {
                if (result->owns)
                {
                    copy = (*node->FUN_006815c0())->Clone();
                    if (!result->TESRegionDataList_Add(copy))
                        delete copy;
                }
                else
                {
                    result->TESRegionDataList_Add(*node->FUN_006815c0());
                }
                node = node->FUN_00726070();
            }
            return result;
        }
    }
}

struct RegionPoint
{
    float GetX();
    float GetY();
    float GetZ();
};
bool __cdecl FloatEQ(float, float, float);
struct FUN_004f70b0_Class
{
    bool j_8TESRegionPoint_QEBA_NAEBV0_Z(RegionPoint* other);
};
// @fnv 0x004f70b0
// src: COMMUNITY 0x004f70b0
bool FUN_004f70b0_Class::j_8TESRegionPoint_QEBA_NAEBV0_Z(RegionPoint* other)
{
    if (FloatEQ(((RegionPoint*)this)->GetX(), other->GetX(), 0.001f) &&
        FloatEQ(((RegionPoint*)this)->GetY(), other->GetY(), 0.001f))
        return true;
    return false;
}




// @fnv 0x004f93b0
BGSConstructibleObject::BGSConstructibleObject()
{
    SetFormType(0x32);
    InitializeData();
}

class ActorCombatGroup;
extern int DAT_010232b4;
struct FUN_004edf70
{
    int* vtbl;
    void* data;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    FUN_004edf70(unsigned short x, unsigned short y);
};
// Sets the vtable, stores x and y into a and d, zeroes b and c, and allocates a bytes for data when a is greater than zero, otherwise sets data to null.
// @fnv 0x004edf70
FUN_004edf70::FUN_004edf70(unsigned short ausSize, unsigned short y)
{
    vtbl = &DAT_010232b4;
    a = ausSize;
    d = y;
    b = 0;
    c = 0;
    if (a > 0)
        data = NiTMallocInterface<ActorCombatGroup*>::Allocate(a);
    else
        data = 0;
}

namespace fnv_004edfe0 {
extern int DAT_010232c4;
struct FUN_004edfe0
{
    int* p;
    ActorCombatGroup** data;
    unsigned short count;
    unsigned short m0a;
    unsigned short m0c;
    unsigned short m0e;
    FUN_004edfe0(unsigned short a, unsigned short b);
};
// @fnv 0x004edfe0
FUN_004edfe0::FUN_004edfe0(unsigned short ausCount, unsigned short b)
{
    p = &DAT_010232c4;
    count = ausCount;
    m0e = b;
    m0a = 0;
    m0c = 0;
    if (count > 0)
        data = NiTMallocInterface<ActorCombatGroup*>::Allocate(count);
    else
        data = 0;
}
}  // namespace fnv_004edfe0


extern unsigned int DAT_011d6a20;
struct GlobalObject_004ee810
{
    void Remove(const NiPointer<NiRefObject>&);
};
extern GlobalObject_004ee810 g_011d6a30;

// Wraps p in a NiPointer, removes it from g_011d6a30, then decrements DAT_011d6a20.
// @fnv 0x004ee2e0
// src: COMMUNITY 0x004ee2e0
void __cdecl BSTempEffect_RemoveDecalFromList(void* apObject)
{
    {
        NiPointer<NiRefObject> tmp(static_cast<NiRefObject*>(apObject));
        g_011d6a30.Remove(tmp);
    }
    DAT_011d6a20 -= 1;
}

struct FUN_004ede90_Class
{
    void* m0;  // +0x0
    int m4;    // +0x4
    int m8;    // +0x8
    void* __thiscall InsertBefore(void* a, void** b);
};

// Links b into the doubly linked list before a, fixes the head pointer when a has no predecessor, and increments the count.
// @fnv 0x004ede90
void* __thiscall FUN_004ede90_Class::InsertBefore(void* apNode, void** apNewNode)
{
    void* local = apNode;
    *apNewNode = local;
    *((void**)((char*)apNewNode + 4)) = *((void**)((char*)local + 4));
    if (*((void**)((char*)local + 4)) != 0)
    {
        *((void**)*((void**)((char*)local + 4))) = apNewNode;
    }
    else
    {
        this->m0 = apNewNode;
    }
    *((void**)((char*)local + 4)) = apNewNode;
    this->m8 = this->m8 + 1;
    return apNewNode;
}












// Call declarations for target-list helpers not exposed by the shared controller.
struct InterpControllerTargetAccess
{
    unsigned short NiMultiTargetTransformController_HasTarget(unsigned int value);
    void NiMultiTargetTransformController_SetInterpolatorTarget(unsigned short index, TaskQueueInterface* queue);
};

// @fnv 0x004f0640
// src: COMMUNITY 0x004f0640
void NiInterpController::NiMultiTargetTransformController_RemoveNodeRecurse(NiAVObject* object)
{
    if (object)
    {
        unsigned short index;
        index = reinterpret_cast<InterpControllerTargetAccess*>(this)->NiMultiTargetTransformController_HasTarget(reinterpret_cast<unsigned int>(object));

        if (index != NiInterpController::INVALID_INDEX)
        {
            reinterpret_cast<InterpControllerTargetAccess*>(this)->NiMultiTargetTransformController_SetInterpolatorTarget(index, 0);
        }
    }

    NiNode* node;
    node = object->IsSceneNode();
    if (node)
    {
        unsigned int i;
        for (i = 0; i < node->GetNumChildren(); ++i)
        {
            this->NiMultiTargetTransformController_RemoveNodeRecurse(node->GetAt(i));
        }
    }
}












class FUN_00a35fc0_shell
{
  public:
    void SetSlotValue(unsigned short index, void* data);
};

class FUN_00a35910_shell : public FUN_00a35fc0_shell
{
  public:
    unsigned short FindIndexByValue(NiAVObject* object);
    void BSMultiTargetTreadTransfController_RemoveNodeRecurse(NiAVObject* object);
};

// @fnv 0x004f06d0
// src: COMMUNITY 0x004f06d0
void FUN_00a35910_shell::BSMultiTargetTreadTransfController_RemoveNodeRecurse(NiAVObject* object)
{
    NiNode* node;
    {
        FUN_00a35910_shell* self = this;

        if (object)
        {
            unsigned short index = self->FindIndexByValue(object);
            if (index != NiInterpController::INVALID_INDEX)
                self->SetSlotValue(index, 0);
        }

        node = object->IsSceneNode();
        if (node)
        {
            for (unsigned int i = 0; i < node->GetNumChildren(); ++i)
                this->BSMultiTargetTreadTransfController_RemoveNodeRecurse(node->GetAt(i));
        }
    }
}

struct FUN_00564f00_shell
{
    bool TESObjectREFR_GetIsImposter();
};

struct FUN_00564f40_shell
{
    void TESObjectREFR_SetIsImposter(int value);
};

void _FNV_Warning(int value1, const char* value2, const char* value3, unsigned int value4);

// @fnv 0x004f24e0
// src: COMMUNITY 0x004f24e0
void TESRegionDataImposter_SetImposterVisible(TESObjectREFR* object, bool visible, bool useDefault)
{
    if (object == 0)
        return;

    if (!reinterpret_cast<FUN_00564f00_shell*>(object)->TESObjectREFR_GetIsImposter())
    {
        reinterpret_cast<FUN_00564f40_shell*>(object)->TESObjectREFR_SetIsImposter(1);
        _FNV_Warning(0xe, "SetImposterVisible: ObjectREFR is not flagged as an imposter (%s:%X)", object->GetName(),
                     object->GetFormID());
    }

    TaskQueueInterface* task = 0;
    if (object->GetNiNode())
        task = reinterpret_cast<TaskQueueInterface*>(object->GetNiNode()->IsFadeNode());

    if (task == 0)
        useDefault = true;

    if (useDefault)
    {
        if (object && object->GetNiNode())
        {
            object->GetNiNode()->SetAppCulled(!visible);
            reinterpret_cast<TaskQueueInterface*>(object->GetNiNode())->NiAVObject_SetRelevantImposter(visible);
        }
    }
    else if (visible)
    {
        object->GetNiNode()->SetAppCulled(false);
        task->NiAVObject_SetRelevantImposter(true);
    }
    else
    {
        task->NiAVObject_SetRelevantImposter(false);
    }
}

extern unsigned char DAT_011c7a58;

// @fnv 0x004e3c40
// src: COMMUNITY 0x004e3c40
unsigned char TESWaterListener_GetUnderwater()
{
    return DAT_011c7a58;
}

struct GlobalObject_00633c90 : BSStringT<char>
{
};
extern GlobalObject_00633c90 g_011d86a8;
struct FUN_004ea9a0_Class
{
    const char* BGSTerrainManager_GetLODLandRoot();
};
// @fnv 0x004ea9a0
// src: COMMUNITY 0x004ea9a0
const char* FUN_004ea9a0_Class::BGSTerrainManager_GetLODLandRoot()
{
    return g_011d86a8.String();
}

namespace fnv_004ea9c0 {
struct GlobalObject_00633c90
{
    void* operator->() const;
};

extern GlobalObject_00633c90 g_011d8690;

struct GlobalNodeAccessor
{
    void* BGSTerrainManager_GetLODObjectRoot();
};

// @fnv 0x004ea9c0
// src: COMMUNITY 0x004ea9c0
void* GlobalNodeAccessor::BGSTerrainManager_GetLODObjectRoot()
{
    return g_011d8690.operator->();
}
}  // namespace fnv_004ea9c0

struct FUN_00a5e930
{
    virtual void ReservedVirtual();
    ~FUN_00a5e930();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
};
struct ListCursor
{
    void* Modelloader_GetReferencedThis();
};
struct FUN_004ee360
{
    bool BSSimpleList_NiRefObjectPtr_IsEmpty();
    ListCursor* FUN_006815c0();
    void PopHead();
    ~FUN_004ee360();
};
struct GlobalRemovalList
{
    void RemoveMatchingItem(void** object);
};
extern GlobalRemovalList g_011c7d20;
void __cdecl BSTempEffect_RemoveDecalFromList(void* item);

struct FUN_004ee1e0 : FUN_00a5e930
{
    FUN_004ee360* entries;
    virtual ~FUN_004ee1e0();
};
// @fnv 0x004ee1e0
FUN_004ee1e0::~FUN_004ee1e0()
{
    FUN_004ee1e0* self = this;
    g_011c7d20.RemoveMatchingItem((void**)&self);
    if (entries)
    {
        while (!entries->BSSimpleList_NiRefObjectPtr_IsEmpty())
        {
            BSTempEffect_RemoveDecalFromList(entries->FUN_006815c0()->Modelloader_GetReferencedThis());
            entries->PopHead();
        }
        delete entries;
        entries = 0;
    }
}

extern int DAT_011c61d4;

// @fnv 0x004ee440
// src: XBOX_PDB 0x004ee440
int __cdecl FixedStrings_QDecalNode()
{
    return DAT_011c61d4;
}

class SubObjectAC
{
  public:
    void BSSimpleList_NiPointer_bhkAction_RemoveAll();
};
class FUN_004ee770_cls
{
  public:
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60(int index);
    unsigned int FUN_0043b480();
    int unk04;
    int unk08;
    int unk0C;
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
    SubObjectAC* m_ac;
    void BGSDecalNode_RemoveDecals();
};
// Calls FUN_004ee920 on m_ac if set, then invokes v60 for every index up to FUN_0043b480().
// @fnv 0x004ee770
// src: COMMUNITY 0x004ee770
void FUN_004ee770_cls::BGSDecalNode_RemoveDecals()
{
    if (m_ac != 0)
    {
        m_ac->BSSimpleList_NiPointer_bhkAction_RemoveAll();
    }
    for (unsigned int i = 0; i < FUN_0043b480(); ++i)
    {
        v60((int)i);
    }
}

struct EmptyBase_b4473
{
    ~EmptyBase_b4473();
};

struct SubObj_b4473
{
    ~SubObj_b4473();
};

struct FUN_004ee840_cls : EmptyBase_b4473
{
    SubObj_b4473 m_00;
    ~FUN_004ee840_cls();
};

// Destructor for the class; destroys its embedded sub-object and base.
// @fnv 0x004ee840
FUN_004ee840_cls::~FUN_004ee840_cls()
{}

class B4EFE80UpdateData
{
  public:
    B4EFE80UpdateData(float fTime, bool m_bUpdateEnabled, bool bForceUpdate);

    float m_fTime;
    bool m_bUpdate;
    bool m_bForceUpdate;
    int m_iFlags;
};

struct B4EFE80RTTI
{
    const char* m_pcName;
    const B4EFE80RTTI* m_pBaseRTTI;
};

class B4EFE80Controller
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void Update(B4EFE80UpdateData& kData);

    B4EFE80Controller* GetNext() const;
};

class B4EFE80Node
{
  public:
    void FUN_004eff50(B4EFE80UpdateData& kData, bool bFlag);
};

extern B4EFE80RTTI g_kB4EFE80RTTIA;
extern B4EFE80RTTI g_kB4EFE80RTTIB;

bool __cdecl NiObject_IsExactKindOf(const B4EFE80RTTI* pkRTTI, B4EFE80Controller* pkObject);
void __cdecl bhkNiCollisionObject_SetSyncMode(int iMode);

class B4EFE80Object
{
  public:
    B4EFE80Controller* GetControllers();
    void UpdateControllers(float fTime, B4EFE80Node* pkNode);
};

// @fnv 0x004efe80
void B4EFE80Object::UpdateControllers(float fTime, B4EFE80Node* pkNode)
{
    bhkNiCollisionObject_SetSyncMode(3);
    for (B4EFE80Controller* pkController = GetControllers(); pkController; pkController = pkController->GetNext())
    {
        bool bExcluded = NiObject_IsExactKindOf(&g_kB4EFE80RTTIA, pkController);
        bExcluded = bExcluded | NiObject_IsExactKindOf(&g_kB4EFE80RTTIB, pkController);
        if (!bExcluded)
        {
            B4EFE80UpdateData kData(fTime, false, false);
            pkController->Update(kData);
            break;
        }
    }
    if (pkNode)
    {
        B4EFE80UpdateData kNodeData(fTime, true, false);
        pkNode->FUN_004eff50(kNodeData, true);
    }
    bhkNiCollisionObject_SetSyncMode(0);
}

struct FUN_004f1730_obj
{
    virtual int v00(int flags);
};

struct FUN_004f1730_base
{
    virtual ~FUN_004f1730_base();
};

struct FUN_004f1730 : FUN_004f1730_base
{
    int unk04;
    FUN_004f1730_obj* m_08;

    virtual ~FUN_004f1730();
};

// @fnv 0x004f1730
FUN_004f1730::~FUN_004f1730()
{
    if (m_08 != 0)
    {
        FUN_004f1730_obj* pObj = m_08;
        FUN_004f1730_obj* pCur = pObj;
        pCur != 0 ? pCur->v00(1) : 0;
    }
}

struct NodeHeader
{
    unsigned int unk00;
};
struct NodeHolder : NodeHeader, RDLNode
{
};
struct QueryContext
{
    void* unk00;
    void* unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
struct RegionList
{
    RDLNode* FUN_00413f40();
};
struct RegionContainer
{
    RegionList* TESRegionDataList_Find();
};
struct RegionEntry
{
    RegionContainer* NiAVObject_GetParent(unsigned int);
};
struct InnerRegion
{
    NodeHolder* FUN_00547110();
};
struct RegionSource
{
    InnerRegion* BGSWorldLocation_GetCell();
};
struct RegionPlayer
{
    NodeHolder* PlayerCharacter_GetAllOccupiedRegions();
    RegionSource* TESObjectREFR_GetWorldLocation(QueryContext*, bool);
};
extern TESObjectREFR* _g_thePlayer;

// Walks the player's region node list and returns true if any child list contains target.
// @fnv 0x004f2640
// src: COMMUNITY 0x004f2640
bool __cdecl TESObjectREFR_IsImposterInActiveRegionList(RDLItem* target)
{
    RDLNode* regionNode = reinterpret_cast<RegionPlayer*>(_g_thePlayer)->PlayerCharacter_GetAllOccupiedRegions();
    RDLItem* listEntry;
    RegionList* childList;
    RegionList* listReference;
    RDLNode* entryNode;
    QueryContext queryBuffer;
    if (regionNode == 0 || *regionNode->FUN_006815c0() == 0)
    {
        regionNode = reinterpret_cast<RegionPlayer*>(_g_thePlayer)
                         ->TESObjectREFR_GetWorldLocation(&queryBuffer, true)
                         ->BGSWorldLocation_GetCell()
                         ->FUN_00547110();
    }
    while (regionNode != 0 && *regionNode->FUN_006815c0() != 0)
    {
        listEntry = *regionNode->FUN_006815c0();
        if (listEntry != 0)
        {
            childList = reinterpret_cast<RegionEntry*>(listEntry)->NiAVObject_GetParent(8)->TESRegionDataList_Find();
            if (childList != 0)
            {
                listReference = childList;
                entryNode = listReference->FUN_00413f40();
                while (entryNode != 0)
                {
                    if (*entryNode->FUN_006815c0() != 0 && *entryNode->FUN_006815c0() == target)
                        return true;
                    entryNode = entryNode->FUN_00726070();
                }
            }
        }
        regionNode = regionNode->FUN_00726070();
    }
    return false;
}

struct ActionItem
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual bool CheckState();
};
struct ActionIterator
{
    ActionItem** FUN_006815c0();
    bool CheckAllActionStates();
};
// Walks the iterator's action items and returns false as soon as one item's CheckState fails, otherwise true.
// @fnv 0x004f3610
// src: GUESS 0x004f3610 (confidence: high)
bool ActionIterator::CheckAllActionStates()
{
    ActionIterator* pIterator = this;
    while (pIterator != 0 && *pIterator->FUN_006815c0() != 0)
    {
        if (!(*pIterator->FUN_006815c0())->CheckState())
            return false;
    }
    return true;
}

class FUN_004f50e0_sub
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ~FUN_004f50e0_sub();
};

class FUN_004f50e0_base
{
  public:
    virtual void Update();
    unsigned int m_04;
    ~FUN_004f50e0_base();
};

class FUN_004f50e0_cls : public FUN_004f50e0_base
{
  public:
    FUN_004f50e0_sub m_08;
    ~FUN_004f50e0_cls();
};

// Destructor for FUN_004f50e0_cls; empty body, base and member destructors run implicitly.
// @fnv 0x004f50e0
FUN_004f50e0_cls::~FUN_004f50e0_cls()
{}

struct SL_4f6320
{
    int _0;
    int _4;
    SL_4f6320();
    ~SL_4f6320();
};

struct PooledObj_4f6320
{
    virtual ~PooledObj_4f6320();
};

struct PoolEntry_4f6320
{
    PooledObj_4f6320* first;
    PooledObj_4f6320* second;
};

extern PoolEntry_4f6320 g_poolEntries_4f6320[9];
extern int g_poolInitCount_4f6320;

struct FUN_004f6320 : SL_4f6320
{
    bool owns;
    virtual ~FUN_004f6320();
    FUN_004f6320(bool owns);
};

// Stores the ownership flag; if owned and the pool is uninitialised, deletes both objects in each of the 9 pool entries and increments the pool init count.
// @fnv 0x004f6320
FUN_004f6320::FUN_004f6320(bool abOwns)
{
    owns = abOwns;
    if (owns)
    {
        if (g_poolInitCount_4f6320 == 0)
        {
            PooledObj_4f6320* second = 0;
            PooledObj_4f6320* first = 0;
            for (unsigned int i = 0; i < 9; i++)
            {
                first = g_poolEntries_4f6320[i].first;
                if (first)
                {
                    g_poolEntries_4f6320[i].first = 0;
                    delete first;
                }
                second = g_poolEntries_4f6320[i].second;
                if (second)
                {
                    g_poolEntries_4f6320[i].second = 0;
                    delete second;
                }
            }
        }
        g_poolInitCount_4f6320++;
    }
}

struct FUN_004f6640_item
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int flag);
};

struct FUN_004f6640_node
{
    int m_unk00;
    int m_unk04;
    FUN_004f6640_item** FUN_006815c0();
    void FUN_0063f7b0();
};

struct FUN_004f6640_cls
{
    int m_unk00;
    FUN_004f6640_node m_node;
    unsigned char m_flag0c;
    void TESRegionList_Clear();
};

// @fnv 0x004f6640
// src: XBOX_PDB 0x004f6640
void FUN_004f6640_cls::TESRegionList_Clear()
{
    FUN_004f6640_item* item = *m_node.FUN_006815c0();
    while (item != 0)
    {
        m_node.FUN_0063f7b0();
        if (m_flag0c != 0)
        {
            FUN_004f6640_item* tmp = item;
            FUN_004f6640_item* cur = tmp;
            (cur != 0) ? cur->v4(1) : 0;
        }
        item = *m_node.FUN_006815c0();
    }
}

// FUN_004f6850 worker4 v2: v1 + real new-expr for the collection (EH frame + state stores)
struct NiMemObject4f
{
    static void* operator new(unsigned int);
};
struct RDLItemX : RDLItem
{
    bool FUN_00440d80();
    int BGSSaveFormBuffer_GetForm();
    struct MidX* NiAVObject_GetParent(int);
    bool _GetByte05();
    bool TESRegionData_GetOverride();
    unsigned char TESRegionData_GetPriority();
    RDLNode* FUN_00441110();
    bool TESRegionPointList_IsInsideRegion(int);
};
struct MidX
{
    RDLItem* TESRegionDataList_Find();
};
struct RDLItemV7 : RDLItem
{
    virtual void v6x();
    virtual void FUN_v7(RDLItem* a0, void* a1);
};
struct Sub470
{
    void FUN_00470470();
    void* FUN_005ae380();
};
struct Coll : NiMemObject4f
{
    virtual ~Coll();
    int m4;
    int m8;
    int mc;
    Coll(int);
    void AddRegion(RDLItem* itemB);
    bool HasEqualListContents(Coll* other);
};
struct DataBufferInfo
{
    RDLItem* first;
    Coll* second;
};
extern DataBufferInfo DAT_011c7f80[];

struct FUN_004f6850_Class
{
    int m0;
    RDLNode m_node;
    RDLItem* TESRegionList_GetDerivedData(int arg0, int arg1, int arg2);
};

// @fnv 0x004f6850
// src: COMMUNITY 0x004f6850
RDLItem* FUN_004f6850_Class::TESRegionList_GetDerivedData(int arg0, int arg1, int arg2)
{
    bool foundC = false;
    unsigned short bestPrioB = 0;
    RDLItem* curB = 0;
    RDLItem* bestE = 0;
    RDLItem* itemB = 0;
    RDLItem* resultD = 0;
    RDLNode* nodeB = this ? &this->m_node : 0;
    RDLNode* node2C = 0;
    Coll* collH = new Coll(0);

    while (nodeB != 0 && *nodeB->FUN_006815c0() != 0)
    {
        curB = *nodeB->FUN_006815c0();
        if (((RDLItemX*)curB)->FUN_00440d80())
        {
            nodeB = nodeB->FUN_00726070();
            continue;
        }
        if (arg2 != 0 && arg2 != ((RDLItemX*)curB)->BGSSaveFormBuffer_GetForm())
        {
            nodeB = nodeB->FUN_00726070();
            continue;
        }
        itemB = ((RDLItemX*)curB)->NiAVObject_GetParent(arg0)->TESRegionDataList_Find();
        if (itemB == 0 || ((RDLItemX*)itemB)->_GetByte05())
        {
            nodeB = nodeB->FUN_00726070();
            continue;
        }
        if (arg1 != 0)
        {
            node2C = ((RDLItemX*)curB)->FUN_00441110();
            while (node2C != 0 && *node2C->FUN_006815c0() != 0)
            {
                if (((RDLItemX*)*node2C->FUN_006815c0())->TESRegionPointList_IsInsideRegion(arg1))
                {
                    collH->AddRegion(curB);
                    break;
                }
                node2C = node2C->FUN_00726070();
            }
        }
        else
        {
            collH->AddRegion(curB);
        }
        nodeB = nodeB->FUN_00726070();
    }

    if (DAT_011c7f80[arg0].first != 0 && DAT_011c7f80[arg0].second != 0 &&
        DAT_011c7f80[arg0].second->HasEqualListContents(collH))
    {
        ((Sub470*)((char*)collH + 4))->FUN_00470470();
        delete collH;
        return DAT_011c7f80[arg0].first;
    }
    else
    {
        Coll* oldSecondA = 0;
        RDLItem* oldFirstD = 0;
        oldFirstD = DAT_011c7f80[arg0].first;
        if (oldFirstD != 0)
        {
            DAT_011c7f80[arg0].first = 0;
            delete oldFirstD;
        }
        oldSecondA = DAT_011c7f80[arg0].second;
        if (oldSecondA != 0)
        {
            DAT_011c7f80[arg0].second = 0;
            delete oldSecondA;
        }
    }

    nodeB = collH ? (RDLNode*)((char*)collH + 4) : 0;
    while (nodeB != 0 && *nodeB->FUN_006815c0() != 0)
    {
        itemB = ((RDLItemX*)*nodeB->FUN_006815c0())->NiAVObject_GetParent(arg0)->TESRegionDataList_Find();
        if (itemB == 0)
        {
            nodeB = nodeB->FUN_00726070();
            continue;
        }
        if (((RDLItemX*)itemB)->TESRegionData_GetOverride())
        {
            foundC = true;
            if (resultD != 0)
            {
                delete resultD;
                resultD = 0;
            }
            if (((RDLItemX*)itemB)->TESRegionData_GetPriority() > bestPrioB)
            {
                bestE = itemB;
                bestPrioB = (unsigned short)((RDLItemX*)itemB)->TESRegionData_GetPriority();
            }
        }
        else if (!foundC)
        {
            if (resultD != 0)
            {
                ((RDLItemV7*)resultD)->FUN_v7(itemB, ((Sub470*)((char*)collH + 4))->FUN_005ae380());
            }
            else
            {
                resultD = itemB->Clone();
            }
        }
        nodeB = nodeB->FUN_00726070();
    }

    if (foundC)
    {
        resultD = bestE->Clone();
    }
    if (resultD != 0)
    {
        if (DAT_011c7f80[arg0].first != 0)
        {
            delete DAT_011c7f80[arg0].first;
        }
        DAT_011c7f80[arg0].first = resultD;
        if (DAT_011c7f80[arg0].second != 0)
        {
            ((Sub470*)((char*)DAT_011c7f80[arg0].second + 4))->FUN_00470470();
            delete DAT_011c7f80[arg0].second;
        }
        DAT_011c7f80[arg0].second = collH;
        collH = 0;
    }
    if (collH != 0)
    {
        ((Sub470*)((char*)collH + 4))->FUN_00470470();
        delete collH;
    }
    return resultD;
}




class FUN_004f6f70_cls
{
  public:
    unsigned int unk00;
    TESForm* m_04;

    unsigned char IsLandTexture();
};
// Returns whether m_04 is non-null and casts to TESLandTexture.
// @fnv 0x004f6f70
unsigned char FUN_004f6f70_cls::IsLandTexture()
{
    return m_04 != 0 ? (unsigned char)(dynamic_cast<TESLandTexture*>(m_04) != 0) : (unsigned char)0;
}

class SpawnedObject
{
  public:
    SpawnedObject();
    void TESRegionPoint_SetX(float v);
    void FUN_004f5d90(float v);
    int unk00;
    int unk04;
};

class FUN_004f7130_cls
{
  public:
    float AStarSearch_EvaluateValue_006a7f50();
    float CombatTimer_GetTargetTime();
    SpawnedObject* TESRegionPoint_Copy(SpawnedObject* src);
};

// Creates a SpawnedObject if src is null, sets its two float values from FUN_006a7f50 and FUN_006b9130, and returns it.
// @fnv 0x004f7130
// src: COMMUNITY 0x004f7130
SpawnedObject* FUN_004f7130_cls::TESRegionPoint_Copy(SpawnedObject* src)
{
    SpawnedObject* obj = src ? src : new SpawnedObject();
    obj->TESRegionPoint_SetX(this->AStarSearch_EvaluateValue_006a7f50());
    obj->FUN_004f5d90(this->CombatTimer_GetTargetTime());
    return obj;
}

class FUN_004ff0e0_arg
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048(int);
    virtual void vf04C(int);
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09C();
    virtual void vf0A0();
    virtual void vf0A4();
    virtual void vf0A8();
    virtual void vf0AC();
    virtual void vf0B0();
    virtual void vf0B4();
    virtual void vf0B8();
    virtual void vf0BC();
    virtual void vf0C0();
    virtual void vf0C4();
    virtual void vf0C8();
    virtual void vf0CC();
    virtual void vf0D0();
    virtual void vf0D4();
    virtual void vf0D8();
    virtual void vf0DC();
    virtual void vf0E0();
    virtual void vf0E4();
    virtual void vf0E8();
    virtual void vf0EC();
    virtual void vf0F0();
    virtual void vf0F4();
    virtual void vf0F8();
    virtual void vf0FC();
    virtual unsigned char vf100();
};
class FUN_004ff0e0_cls
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048(int);
    virtual void vf04C(int);
    unsigned int m_04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    FUN_004ff0e0_arg* m_090;
    void BGSTalkingActivator_SetTempRef(FUN_004ff0e0_arg* a1);
};
// @fnv 0x004ff0e0
// src: COMMUNITY 0x004ff0e0
void FUN_004ff0e0_cls::BGSTalkingActivator_SetTempRef(FUN_004ff0e0_arg* a1)
{
    if (a1 == 0 || a1->vf100() != 0)
    {
        m_090 = a1;
        if (a1 != 0)
        {
            vf048(0x800000);
        }
        else
        {
            vf04C(0x800000);
        }
    }
}





class FUN_00a5ecb0 : public AnimIdle
{
  public:
    char pad00[0xa4];
    FUN_00a5ecb0(unsigned int uiValue);
    static void operator delete(void*, unsigned int);
};

class FUN_006815c0
{
  public:
    float x;
    float y;
    FUN_006815c0();
};

class FUN_0048f200
{
  public:
    char pad00[0xc];
    FUN_0048f200();
    ~FUN_0048f200();
};

class FUN_004ed7a0
{
  public:
    char pad00[0x10];
    FUN_004ed7a0(int iSize);
    ~FUN_004ed7a0();
};

class FUN_004ed7d0
{
  public:
    char pad00[0x10];
    FUN_004ed7d0(int iSize);
    ~FUN_004ed7d0();
};

class FUN_004ed800
{
  public:
    char pad00[0x10];
    FUN_004ed800(int iSize);
    ~FUN_004ed800();
};

class FUN_0041a250
{
  public:
    char pad00[0xc];
    FUN_0041a250();
    ~FUN_0041a250();
};

class FUN_00414430
{
  public:
    float r;
    float g;
    float b;
    float a;
    FUN_00414430(float fR, float fG, float fB, float fA);
};

class FUN_00438170
{
  public:
    void* m_pResource;
    FUN_00438170(const char* pcName);
};


struct Value4e1
{
    int& Setting_Int();
};


struct TES4e1
{
    NiNode* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

extern TES4e1* DAT_011dea10;
extern Setting DAT_011c7bbc;
extern bool DAT_011ff100;
extern bool DAT_011ad86e;
extern const float DAT_01016248;
extern const float DAT_0101e2bc;
extern FUN_00414430 DAT_011ff3b8;
extern FUN_00414430 DAT_011ff3c8;
extern FUN_00414430 DAT_011ff3d8;
extern int DAT_011c7a3c;
extern FUN_006815c0 DAT_011f4980;
extern FUN_00438170* DAT_011c7a54;
extern Value4e1 DAT_011c7bec;
extern Value4e1 DAT_011c7afc;
extern int DAT_011c7a44;
extern int DAT_011c7a40;

unsigned int __cdecl TESWaterSystem_GetWaterRoot();

class FUN_004e1650
{
  public:
    int m00;
    int m04;
    NiPointer<AnimIdle> sp08;
    NiPointer<AnimIdle> sp0c;
    NiPointer<AnimIdle> sp10;
    NiPointer<AnimIdle> sp14;
    NiPointer<AnimIdle> sp18;
    NiPointer<AnimIdle> sp1c;
    NiPointer<AnimIdle> sp20;
    float f24;
    FUN_006815c0 kPoint28;
    int m30;
    bool b34;
    float f38;
    FUN_0048f200 k3c;
    int m48;
    FUN_004ed7a0 k4c;
    FUN_004ed7a0 k5c;
    FUN_004ed7d0 k6c;
    FUN_004ed800 k7c;
    FUN_0041a250 k8c;
    float f98;
    bool b9c;

    FUN_004e1650();
};

// @fnv 0x004e1650
FUN_004e1650::FUN_004e1650()
    : sp08(0), sp0c(0), sp10(0), sp14(0), sp18(0), sp1c(0), sp20(0), k4c(0x25), k5c(0x25), k6c(0x25), k7c(0x25)
{
    f24 = 0.0f;
    DAT_011ff100 = *DAT_011c7bbc.FUN_00408d60();
    DAT_011ad86e = 0;
    if (!TESWaterSystem_GetWaterRoot())
    {
        *(NiPointer<AnimIdle>*)&g_011c7c28 = new FUN_00a5ecb0(0);
        DAT_011dea10->GetHavokWorldObjectCountInSceneGraph_0084e3a0()->AttachChildInAvailableSlot(reinterpret_cast<NiAVObject*>(static_cast<AnimIdle*>(*(NiPointer<AnimIdle>*)&g_011c7c28)), true);
    }
    DAT_011ff3b8 = FUN_00414430(0.0f, DAT_01016248, DAT_01016248, 1.0f);
    DAT_011ff3c8 = FUN_00414430(0.0f, 0.0f, DAT_0101e2bc, 1.0f);
    DAT_011ff3d8 = FUN_00414430(1.0f, 1.0f, 1.0f, 1.0f);
    DAT_011c7a3c = 0;
    m30 = 0;
    f38 = 0.0f;
    b34 = 0;
    sp18 = 0;
    kPoint28 = DAT_011f4980;
    m00 = 0;
    DAT_011c7a54 = new FUN_00438170("WATER");
    m48 = 0;
    f98 = 0.0f;
    b9c = 0;
    DAT_011c7a44 = DAT_011c7bec.Setting_Int();
    DAT_011c7a40 = DAT_011c7afc.Setting_Int();
}

namespace fnv_004e19c0 {
struct TexName_4e19c0
{
    TexName_4e19c0& operator=(const char* text);
    operator const char*() const;
};
struct TexList_4e19c0
{
    void RemoveAll();
};
BSTextureManager* __stdcall BSShaderManager_GetTextureManager();

extern TexName_4e19c0 g_011c7be8;
extern TexName_4e19c0 g_011c7cb8;
extern TexName_4e19c0 g_011c7c2c;
extern TexName_4e19c0 g_011c7ad4;
extern TexName_4e19c0 g_011c7b68;
extern TexList_4e19c0 g_011c7bcc;
extern TexList_4e19c0 g_011c7c30;
extern TexList_4e19c0 g_011c7ce4;
extern TexList_4e19c0 g_011c7b80;

struct Owned_4e19c0
{
    int unk00;
    ~Owned_4e19c0();
};
extern Owned_4e19c0* DAT_011c7a54;

struct Ptr_4e19c0
{
    void* m_pObject;
    ~Ptr_4e19c0();
};
struct ListA_4e19c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~ListA_4e19c0();
};
struct ListB_4e19c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~ListB_4e19c0();
};
struct ListC_4e19c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~ListC_4e19c0();
};
struct ListD_4e19c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~ListD_4e19c0();
};
struct ListE_4e19c0
{
    int unk00;
    ~ListE_4e19c0();
};

struct FUN_004e19c0
{
    int unk00;
    int unk04;
    Ptr_4e19c0 m_08;
    Ptr_4e19c0 m_0c;
    Ptr_4e19c0 m_10;
    Ptr_4e19c0 m_14;
    Ptr_4e19c0 m_18;
    Ptr_4e19c0 m_1c;
    Ptr_4e19c0 m_20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    ListA_4e19c0 m_3c;
    ListB_4e19c0 m_4c;
    ListB_4e19c0 m_5c;
    ListC_4e19c0 m_6c;
    ListD_4e19c0 m_7c;
    ListE_4e19c0 m_8c;
    void Shutdown(int a, int b);
    ~FUN_004e19c0();
};

// Shuts down the object, clears texture name globals, releases two textures by name, empties four lists and deletes DAT_011c7a54.
// @fnv 0x004e19c0
FUN_004e19c0::~FUN_004e19c0()
{
    Shutdown(1, 1);
    g_011c7be8 = 0;
    g_011c7cb8 = 0;
    if (g_011c7c2c)
        BSShaderManager_GetTextureManager()->ReleaseByName(g_011c7c2c);
    g_011c7c2c = 0;
    if (g_011c7ad4)
        BSShaderManager_GetTextureManager()->ReleaseByName(g_011c7ad4);
    g_011c7ad4 = 0;
    g_011c7b68 = 0;
    g_011c7bcc.RemoveAll();
    g_011c7c30.RemoveAll();
    g_011c7ce4.RemoveAll();
    g_011c7b80.RemoveAll();
    delete DAT_011c7a54;
    DAT_011c7a54 = 0;
}
}  // namespace fnv_004e19c0

struct CleanupObject
{
    unsigned int FUN_00726070();
    void ClearTextureAndShaderTextures();
    void BSTextureManager_ReturnRenderedTexture();
};

namespace fnv_004ed3e0 {
struct GlobalObject_0048f200
{
    void* head;
    void* tail;
    unsigned int count;
    ~GlobalObject_0048f200();
    void FUN_004ed900();
};
struct CleanupOwner
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    NiNodeHolder_blk_004e0000_od node;
};
struct CleanupRegistry
{
    CleanupObject* DetailedActorPathHandler_GetCurrentNodeIndex(void* object, int mode, int flags);
};
extern CleanupRegistry* DAT_011dea10;
CleanupObject* __stdcall BSShaderManager_GetTextureManager(CleanupObject* object);
struct CleanupManager
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
    virtual void Release(CleanupObject* object);
};
struct FUN_004ed3e0
{
    CleanupOwner* owner;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    GlobalObject_0048f200 list24;
    GlobalObject_0048f200 list30;
    GlobalObject_0048f200 list3c;
    GlobalObject_0048f200 list48;
    NiNodeHolder_blk_004e0000_od ptr54;
    NiNodeHolder_blk_004e0000_od ptr58;
    unsigned int unk5c, unk60;
    GlobalObject_0048f200 list64;
    GlobalObject_0048f200 list70;
    GlobalObject_0048f200 list7c;
    GlobalObject_0048f200 list88;
    NiNodeHolder_blk_004e0000_od ptr94;
    NiNodeHolder_blk_004e0000_od ptr98;
    unsigned int unk9c, unka0;
    NiNodeHolder_blk_004e0000_od ptra4;
    NiNodeHolder_blk_004e0000_od ptra8;
    ~FUN_004ed3e0();
};

// @fnv 0x004ed3e0
FUN_004ed3e0::~FUN_004ed3e0()
{
    ptr94.FUN_0066b0d0(0);
    ptr98.FUN_0066b0d0(0);
    DAT_011dea10->DetailedActorPathHandler_GetCurrentNodeIndex(this, 1, 0)->ClearTextureAndShaderTextures();
    if (owner && owner->node.Modelloader_GetReferencedThis() && owner->node.Modelloader_GetReferencedThis()->FUN_00726070() == 2)
    {
        BSShaderManager_GetTextureManager(owner->node.Modelloader_GetReferencedThis())->BSTextureManager_ReturnRenderedTexture();
        owner->node.FUN_0066b0d0(0);
    }
    list30.FUN_004ed900();
    list3c.FUN_004ed900();
    if (ptr58.Modelloader_GetReferencedThis())
    {
        ((CleanupManager*)TESWaterSystem_GetWaterRoot())->Release(ptr58.Modelloader_GetReferencedThis());
        ptr58.FUN_0066b0d0(0);
    }
}
}  // namespace fnv_004ed3e0

class Handle4EE
{
  public:
    Handle4EE(int iValue);
    ~Handle4EE();
    void Reset(const void* pvObject);

    void* m_pvObject;
};

class CopyInfo4EE
{
  public:
    CopyInfo4EE(unsigned int uiFlags);
    ~CopyInfo4EE();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class Base4EE;

class Source4EE
{
  public:
    void* GetList();
    const char* GetName();
    int GetInterval();
    int GetMode();
    void Register(Base4EE* pkObject, CopyInfo4EE& kInfo);
};

class Base4EE
{
  public:
    Base4EE(void* pvList, int iFirst, int iSecond);
    virtual ~Base4EE();

    bool SetMode(int iMode);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Handle4EE m_kName;
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
    int m_iInterval;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
};

class FUN_004ee9f0 : public Base4EE
{
  public:
    FUN_004ee9f0(const void* pvTarget, Source4EE* pkSource);
    virtual ~FUN_004ee9f0();

    Handle4EE m_kRoomNode;
};

// Initializes a Base4EE-derived object from a source: stores target and source name handles, copies interval and mode, then registers with the source.
// @fnv 0x004ee9f0
FUN_004ee9f0::FUN_004ee9f0(const void* pvTarget, Source4EE* pkSource)
    : Base4EE(pkSource->GetList(), 0, 1), m_kRoomNode(0)
{
    m_kRoomNode.Reset(pvTarget);
    m_kName.Reset(pkSource->GetName());
    m_iInterval = pkSource->GetInterval();
    SetMode(pkSource->GetMode());
    CopyInfo4EE kInfo(0x101);
    pkSource->Register(this, kInfo);
}


struct FUN_004f5e20
{
    FUN_004f5e20(int flag);
    ~FUN_004f5e20();
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

struct FUN_004f15f0 : TESRegionData
{
    FUN_004f15f0();
    ~FUN_004f15f0();
    virtual void v0();
    FUN_004f5e20* m_08;
};

// Constructs the object and allocates a new FUN_004f5e20 with flag 1, storing it in m_08.
// @fnv 0x004f15f0
FUN_004f15f0::FUN_004f15f0()
{
    m_08 = new FUN_004f5e20(1);
}

class Base4F4
{
  public:
    Base4F4();
    virtual ~Base4F4();

    int unk04;
};

// Region sound collection state: constructor 0x004f43c0 builds list members; shared Data::Data is 0x0067ff70.
class RegionSoundCollectionState
{
  public:
    RegionSoundCollectionState();
    ~RegionSoundCollectionState();

    int m_iFirst;
    int unk04;
    int unk08;
    int m_iLast;
};

class List4F4
{
  public:
    void RemoveAll();

    void* m_pkHead;
    void* m_pkNext;
};

class FUN_004f42a0 : public Base4F4
{
  public:
    FUN_004f42a0();
    virtual ~FUN_004f42a0();

    RegionSoundCollectionState m_kData;
    List4F4 m_kList;
};

// Initializes the data range to zero and clears the list.
// @fnv 0x004f42a0
FUN_004f42a0::FUN_004f42a0()
{
    m_kData.m_iFirst = 0;
    m_kData.m_iLast = 0;
    m_kList.RemoveAll();
}

class B4F72A0Point
{
  public:
    float GetValue();
    float GetTime();
};

// Linearly interpolates between two points' values at fTime using their times, returning 0 if either point is null.
// @fnv 0x004f72a0
// src: COMMUNITY 0x004f72a0
float __cdecl TESRegionPoint_XIntercept(B4F72A0Point* pkCurrentObject, B4F72A0Point* pkSecond, float fTime)
{
    if (!pkCurrentObject || !pkSecond)
        return 0.0f;
    float fSecondValue = pkSecond->GetValue();
    float fSecondTime = pkSecond->GetTime();
    return fSecondValue -
           (fSecondTime - fTime) * ((pkCurrentObject->GetValue() - fSecondValue) / (pkCurrentObject->GetTime() - fSecondTime));
}

// Returns false if any point is null or the segments' bounding boxes don't overlap, then tests the segment intersection parameters against the denominator.
// @fnv 0x004f7310
// src: COMMUNITY 0x004f7310
bool __cdecl TESRegionPoint_LineSegmentsIntersect(NiPoint3* apSeg1Start, NiPoint3* apSeg1End, NiPoint3* apSeg2Start, NiPoint3* apSeg2End)
{
    if (!apSeg1Start || !apSeg1End || !apSeg2Start || !apSeg2End)
        return false;
    float dx3 = apSeg1End->GetX() - apSeg1Start->GetX();
    float dx2 = apSeg2Start->GetX() - apSeg2End->GetX();
    float minx, maxx2;
    if (dx3 < 0.0)
    {
        minx = apSeg1Start->GetX();
        maxx2 = apSeg1End->GetX();
    }
    else
    {
        minx = apSeg1End->GetX();
        maxx2 = apSeg1Start->GetX();
    }
    if (dx2 > 0.0)
    {
        if (minx < apSeg2End->GetX() || maxx2 > apSeg2Start->GetX())
            return false;
    }
    else
    {
        if (minx < apSeg2Start->GetX() || maxx2 > apSeg2End->GetX())
            return false;
    }
    float dy1 = apSeg1End->GetY() - apSeg1Start->GetY();
    float dy2 = apSeg2Start->GetY() - apSeg2End->GetY();
    float miny6, maxy;
    if (dy1 < 0.0)
    {
        miny6 = apSeg1Start->GetY();
        maxy = apSeg1End->GetY();
    }
    else
    {
        miny6 = apSeg1End->GetY();
        maxy = apSeg1Start->GetY();
    }
    if (dy2 > 0.0)
    {
        if (miny6 < apSeg2End->GetY() || maxy > apSeg2Start->GetY())
            return false;
    }
    else
    {
        if (miny6 < apSeg2Start->GetY() || maxy > apSeg2End->GetY())
            return false;
    }
    float rx = apSeg1Start->GetX() - apSeg2Start->GetX();
    float ry = apSeg1Start->GetY() - apSeg2Start->GetY();
    float denom8 = dy1 * dx2 - dx3 * dy2;
    float numer9 = dx3 * ry - dy1 * rx;
    float numer3 = dy2 * rx - dx2 * ry;
    if (denom8 == 0.0)
    {
        return true;
    }
    else if (denom8 > 0.0)
    {
        if (numer3 < 0.0 || numer3 > denom8)
            return false;
        if (numer9 < 0.0 || numer9 > denom8)
            return false;
    }
    else
    {
        if (numer3 > 0.0 || numer3 < denom8)
            return false;
        if (numer9 > 0.0 || numer9 < denom8)
            return false;
    }
    return true;
}

struct PolygonPoint
{
    float AStarSearch_EvaluateValue_006a7f50();
    float CombatTimer_GetTargetTime();
};
struct PolygonNode
{
    PolygonNode* FUN_00726070();
    PolygonPoint** FUN_006815c0();
};
float TESRegionPoint_XIntercept(PolygonPoint*, PolygonPoint*, float);
struct Polygon : PolygonNode
{
    unsigned int FUN_0059bb30();
    float TESRegionPointList_GetMinX();
    float TESRegionPointList_GetMaxX();
    float GetMinimumY();
    float GetMaxY();
    bool TESRegionPointList_IsInsideRegion(PolygonPoint*);
};
// NiPoint3-in-polygon test (even-odd crossing rule) after a bounding-box reject.
// @fnv 0x004f8360
// src: COMMUNITY 0x004f8360
bool Polygon::TESRegionPointList_IsInsideRegion(PolygonPoint* pPoint)
{
    PolygonPoint* a2;
    PolygonPoint* b_;
    float bx;
    float ax;
    float yB;
    float ay_;
    int count7 = 0;
    bool _crossing = false;
    if (!pPoint || FUN_0059bb30() < 3)
        return false;
    float x = pPoint->AStarSearch_EvaluateValue_006a7f50();
    float by = pPoint->CombatTimer_GetTargetTime();
    if (x < TESRegionPointList_GetMinX() || x > TESRegionPointList_GetMaxX() || by < GetMinimumY() || by > GetMaxY())
        return false;
    PolygonNode* node6 = this;
    PolygonNode* nextX = 0;
    do
    {
        nextX = node6->FUN_00726070();
        if (!nextX)
            nextX = this;
        a2 = *node6->FUN_006815c0();
        b_ = *nextX->FUN_006815c0();
        bx = a2->AStarSearch_EvaluateValue_006a7f50();
        ax = b_->AStarSearch_EvaluateValue_006a7f50();
        if (bx > x && ax > x)
            _crossing = true;
        else if (bx > x || ax > x)
        {
            if (x < TESRegionPoint_XIntercept(a2, b_, by))
                _crossing = true;
            else
                _crossing = false;
        }
        else
            _crossing = false;
        if (_crossing)
        {
            ay_ = a2->CombatTimer_GetTargetTime();
            yB = b_->CombatTimer_GetTargetTime();
            if ((ay_ > by && by >= yB) || (ay_ <= by && by < yB))
                count7++;
        }
        node6 = nextX;
    } while (node6 != this);
    if (count7 % 2 == 0)
        return false;
    return true;
}

struct RegionPointMatch
{
    float SquaredDistanceTo(RegionPointMatch* other);
    float EvaluateValue_004f71f0(RegionPointMatch* other);
    void TESRegionPoint_Copy(void* destination);
};
struct RegionNodeMatch
{
    RegionPointMatch* point;
    RegionNodeMatch* next;
    RegionPointMatch** FUN_006815c0();
    RegionNodeMatch* FUN_00726070();
};
struct FUN_004f87e0
{
    FUN_004f87e0();
    int x;
    int y;
    float range;
    float value;
    bool IsInRegion(RegionPointMatch* point, float range);
};
struct RegionMatch : RegionNodeMatch
{
    FUN_004f87e0* cache;
    bool TESRegionPointList_IsInsideRegion(RegionPointMatch* point);
    float ComputeRegionValue(RegionPointMatch* point, float range);
};
// @fnv 0x004f8560
float RegionMatch::ComputeRegionValue(RegionPointMatch* point, float range)
{
    float j;             // squared distance to the current endpoint
    float a;             // squared distance to the following endpoint
    bool d;              // the final, closing edge has been reached
    float e;             // distance projected along the edge
    bool h;              // point is inside the region
    RegionNodeMatch* l;  // following list node
    float b;             // squared edge length
    float i;             // resulting blend weight
    float f;             // minimum squared distance
    float k;             // squared distance to this edge
    RegionNodeMatch* g;  // current list node
    float c;             // edge length
    d = false;
    if (cache && cache->IsInRegion(point, range))
        return cache->value;
    h = TESRegionPointList_IsInsideRegion(point);
    if (!point || !h)
        return 0.0f;
    if (range < 1.0 && h)
        return 1.0f;
    f = 3.402823466e+38F;
    g = this;
    do
    {
        l = g->FUN_00726070();
        if (!l)
        {
            l = this;
            d = true;
        }
        j = point->SquaredDistanceTo(*g->FUN_006815c0());
        a = point->SquaredDistanceTo(*l->FUN_006815c0());
        c = (*g->FUN_006815c0())->EvaluateValue_004f71f0(*l->FUN_006815c0());
        b = (*g->FUN_006815c0())->SquaredDistanceTo(*l->FUN_006815c0());
        e = b - a + j;
        e /= (2.0 * c);
        if (e >= c)
            k = a;
        else if (e <= 0.0)
            k = j;
        else
            k = j - e * e;
        if (k < f)
            f = k;
        g = l;
    } while (!d);
    f = ConvertDoubleResult(f);
    if (f >= range)
        i = 1.0f;
    else
        i = f / range;
    if (cache)
        delete cache;
    cache = new FUN_004f87e0;
    point->TESRegionPoint_Copy(cache);
    cache->range = range;
    cache->value = i;
    return i;
}

class ExtraOwner4FF
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_iValue;
};

class Ref4FF;

class ExtraList4FF
{
  public:
    void AddOwner(void* pkOwner, Ref4FF* pkRef);
    ExtraOwner4FF* GetOwner();
};

class Ref4FF
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void SetFlag(unsigned int uiFlag);

    ExtraList4FF* GetExtraData();
};

class Owner4FF
{
  public:
    int BGSTalkingActivator_AddMobileObjectExtra(Ref4FF* pkRef);
};

// @fnv 0x004ff070
// src: XBOX_PDB 0x004ff070
int Owner4FF::BGSTalkingActivator_AddMobileObjectExtra(Ref4FF* pkRef)
{
    int iResult = 0;
    pkRef->GetExtraData()->AddOwner(this, pkRef);
    pkRef->SetFlag(0x80000000);
    if (pkRef->GetExtraData()->GetOwner())
        iResult = pkRef->GetExtraData()->GetOwner()->m_iValue;
    return iResult;
}

struct NodeLinkX
{
    int unk0;
    FUN_004ee360* m_pNext;
};
class ListX
{
  public:
    NiPointer<BSTempEffect> m_spNode;
    FUN_004ee360* m_pHead;
    void BSSimpleList_NiPointer_bhkAction_RemoveAll();
};
// Deletes all nodes in the m_pHead linked list and resets m_spNode to null.
// @fnv 0x004ee920
// src: XBOX_PDB 0x004ee920
void ListX::BSSimpleList_NiPointer_bhkAction_RemoveAll()
{
    while (m_pHead)
    {
        FUN_004ee360* pNext = ((NodeLinkX*)m_pHead)->m_pNext;
        ((NodeLinkX*)m_pHead)->m_pNext = 0;
        delete m_pHead;
        m_pHead = pNext;
    }
    m_spNode = NiPointer<BSTempEffect>(0);
}

class List_009e03e0
{
  public:
    void* m_pHead;
    void* m_pTail;
    ~List_009e03e0();
};

// The terminal description component follows the activator base at 0x90.
class FUN_004ffba0 : public TESObjectACTI, public TESDescription
{
  public:
    List_009e03e0 m_kList;

    void FUN_004ffc90();
    virtual ~FUN_004ffba0();
};

// Destructor that calls FUN_004ffc90.
// @fnv 0x004ffba0
FUN_004ffba0::~FUN_004ffba0()
{
    FUN_004ffc90();
}

struct xMemObj
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* p, unsigned int);
};

struct xPt3
{
    float x, y, z;
    xPt3();
    xPt3(float fX, float fY, float fZ);
    xPt3 operator+(const xPt3& kPt) const;
};

struct xPt2
{
    float x, y;
    xPt2();
    xPt2(float fX, float fY);
    xPt2 Scale(const xPt2& kPt) const;
};

struct xMat3
{
    float m[9];
    xMat3();
    void InitIdentity();
    xPt3 operator*(const xPt3& kPt) const;
};

struct xProp : public xMemObj
{
    int m_kNextStreamField[0x1c];
    xProp();
    void SetTex(int iIndex, void* pTileTexture);
};

struct xTriShape : public xMemObj
{
    int m_kNextStreamField[0x31];
    xTriShape(unsigned short usVerts, xPt3* pkVerts, xPt3* pkNormals, void* pkColors, xPt2* pkUVs,
              unsigned short usUVSets, unsigned int uiFlags, unsigned short usTris, unsigned short* pusTris);
    void AttachProperty(xProp* pkProp);
};

struct xNode : public xMemObj
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
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void AttachChildInAvailableSlot(xTriShape* pkChild, bool bFirst);
    int m_kNextStreamField[0x2a];
    xNode(unsigned short usChildren);
};

struct xSetting
{
    float* Float();
};
struct xTexPtr
{
    operator void*() const;
};

extern xSetting xS737;
extern xSetting xS738;
extern xSetting xS739;
extern xSetting xS980;
extern xSetting xS740;
extern xSetting xS920;
extern xSetting xS741;
extern xSetting xS743;
extern xTexPtr xTex0;
extern xTexPtr xTex1;
extern xTexPtr xTex2;
extern bool xFlag;
extern float xScaleX;
extern float xScaleY;

float xRand01();
float xRandomFloat(float fMin, float fScaledValue);
bool xChance(float afChance);
void xUpdate(xTriShape* pkShape, int a, int b);

// Creates a node with one or two triangle shapes of randomly scattered quads using settings and textures.
// @fnv 0x004e08a0
xNode* CreateScatterShapes(unsigned int aiQuadCount)
{
    xNode* qpTd = new xNode(0);
    xPt3* qdqWL = new xPt3[aiQuadCount * 4];
    xPt2* qbGYp = new xPt2[aiQuadCount * 4];
    unsigned short* qSVM = new unsigned short[aiQuadCount * 6];
    xPt3* qfTOqo = 0;
    xPt2* qvyWyw = 0;
    unsigned short* qpqRa = 0;
    if (xFlag)
    {
        qfTOqo = new xPt3[aiQuadCount * 4];
        qvyWyw = new xPt2[aiQuadCount * 4];
        qpqRa = new unsigned short[aiQuadCount * 6];
    }
    unsigned int qrEZrs;
    for (qrEZrs = 0; qrEZrs < aiQuadCount; qrEZrs++)
    {
        float qGfbX = xRand01() * xScaleX;
        float qRqUtp = xRand01() * xScaleY;
        xPt3 qsTDDg(qGfbX, qRqUtp, 0.0f);
        float qbXcw = xRandomFloat(*xS737.Float(), *xS738.Float());
        float qZAdkzg = xRandomFloat(*xS739.Float(), *xS980.Float());
        float qyjT = xRandomFloat(*xS740.Float(), *xS920.Float());
        xMat3 qBCzzXA;
        qBCzzXA.InitIdentity();
        if (xChance(*xS741.Float()))
            qZAdkzg = qyjT;
        float qrzAir = xRand01() > 0.0 ? 0.0 : 0.5;
        float qAhbO = xRand01() > 0.0 ? 0.0 : 0.5;
        xPt2 qrKBG(qrzAir, qAhbO);
        float qArxcFu = *xS743.Float();
        unsigned int qYGChgr = qrEZrs * 4;
        qdqWL[qYGChgr] = qBCzzXA * xPt3(-qbXcw, qbXcw, qZAdkzg) + qsTDDg;
        qdqWL[qYGChgr + 1] = qBCzzXA * xPt3(qbXcw, qbXcw, qZAdkzg) + qsTDDg;
        qdqWL[qYGChgr + 2] = qBCzzXA * xPt3(-qbXcw, -qbXcw, qZAdkzg) + qsTDDg;
        qdqWL[qYGChgr + 3] = qBCzzXA * xPt3(qbXcw, -qbXcw, qZAdkzg) + qsTDDg;
        if (xFlag)
        {
            qfTOqo[qYGChgr] = qBCzzXA * xPt3(-qArxcFu, qArxcFu, qZAdkzg) + qsTDDg;
            qfTOqo[qYGChgr + 1] = qBCzzXA * xPt3(qArxcFu, qArxcFu, qZAdkzg) + qsTDDg;
            qfTOqo[qYGChgr + 2] = qBCzzXA * xPt3(-qArxcFu, -qArxcFu, qZAdkzg) + qsTDDg;
            qfTOqo[qYGChgr + 3] = qBCzzXA * xPt3(qArxcFu, -qArxcFu, qZAdkzg) + qsTDDg;
        }
        qbGYp[qYGChgr] = xPt2(0.5f, 0.5f).Scale(qrKBG);
        qbGYp[qYGChgr + 1] = xPt2(0.0f, 0.5f).Scale(qrKBG);
        qbGYp[qYGChgr + 2] = xPt2(0.5f, 0.0f).Scale(qrKBG);
        qbGYp[qYGChgr + 3] = xPt2(0.0f, 0.0f).Scale(qrKBG);
        if (xFlag)
        {
            qvyWyw[qYGChgr] = xPt2(1.0f, 1.0f);
            qvyWyw[qYGChgr + 1] = xPt2(0.0f, 1.0f);
            qvyWyw[qYGChgr + 2] = xPt2(1.0f, 0.0f);
            qvyWyw[qYGChgr + 3] = xPt2(0.0f, 0.0f);
        }
        int qxQHW = qrEZrs * 6;
        qSVM[qxQHW] = qYGChgr;
        qSVM[qxQHW + 1] = qYGChgr + 2;
        qSVM[qxQHW + 2] = qYGChgr + 1;
        qSVM[qxQHW + 3] = qYGChgr + 1;
        qSVM[qxQHW + 4] = qYGChgr + 2;
        qSVM[qxQHW + 5] = qYGChgr + 3;
        if (xFlag)
        {
            qpqRa[qxQHW] = qYGChgr;
            qpqRa[qxQHW + 1] = qYGChgr + 2;
            qpqRa[qxQHW + 2] = qYGChgr + 1;
            qpqRa[qxQHW + 3] = qYGChgr + 1;
            qpqRa[qxQHW + 4] = qYGChgr + 2;
            qpqRa[qxQHW + 5] = qYGChgr + 3;
        }
    }
    xTriShape* qsSDDgz = new xTriShape(aiQuadCount * 4, qdqWL, 0, 0, qbGYp, 1, 0, aiQuadCount * 2, qSVM);
    xProp* qHXYKT = new xProp();
    qHXYKT->SetTex(0, xTex0);
    qHXYKT->SetTex(1, xTex1);
    qsSDDgz->AttachProperty(qHXYKT);
    xUpdate(qsSDDgz, 0, 0);
    qpTd->AttachChildInAvailableSlot(qsSDDgz, 1);
    if (xFlag)
    {
        qsSDDgz = new xTriShape(aiQuadCount * 4, qfTOqo, 0, 0, qvyWyw, 1, 0, aiQuadCount * 2, qpqRa);
        qHXYKT = new xProp();
        qHXYKT->SetTex(0, xTex2);
        qsSDDgz->AttachProperty(qHXYKT);
        xUpdate(qsSDDgz, 0, 0);
        qpTd->AttachChildInAvailableSlot(qsSDDgz, 1);
    }
    return qpTd;
}

struct FUN_004f09e0
{
    virtual ~FUN_004f09e0();
};
// @fnv 0x004f09e0
FUN_004f09e0::~FUN_004f09e0()
{}

namespace fnv_004f6fc0 {
struct Modifier
{
    void __thiscall SetValue(float);
};
struct AlphaColor
{
    void __thiscall TESRegionPoint_SetX(float);
};
struct Base006815c0
{
    void __thiscall _ref_006815c0();
};
struct MyClass004f6fc0
{
    MyClass004f6fc0* __thiscall TESRegionPoint_TESRegionPoint();
};
// Calls _ref_006815c0, then FUN_0052ce20 and SetValue each with 0.0f, and returns this.
// @fnv 0x004f6fc0
// src: XBOX_PDB 0x004f6fc0
MyClass004f6fc0* __thiscall MyClass004f6fc0::TESRegionPoint_TESRegionPoint()
{
    ((Base006815c0*)this)->_ref_006815c0();
    ((AlphaColor*)this)->TESRegionPoint_SetX(0.0f);
    ((Modifier*)this)->SetValue(0.0f);
    return this;
}
}  // namespace fnv_004f6fc0

// FUN_004e3d60 v05 - one-pass transcription from the packet alone (/Od /Oy-)
struct Vec4f
{
    float v[4];
};
struct VObj
{
    virtual int reserved0();
    virtual int reserved1();
    virtual int reserved2();
    virtual int reserved3();
    virtual int FunctionAtSlot4();
    virtual int FunctionAtSlot5();
    virtual int FunctionAtSlot6();
    virtual int VirtualFunction7();
    virtual int VirtualFunction8();
    virtual int VirtualFunction9();
    virtual int VirtualFunction10();
    virtual int ReplaceImpactData();
    virtual int reserved12();
    virtual int VirtualFunction13();
    virtual int reserved14();
    virtual int reserved15();
    virtual int reserved16();
    virtual int reserved17();
    virtual int reserved18();
    virtual int reserved19();
    virtual int reserved20();
    virtual int reserved21();
    virtual int VirtualFunction22();
    virtual int VirtualFunction23();
    virtual int VirtualFunction24();
    virtual int VirtualFunction25();
    virtual int VirtualFunction26();
    virtual int VirtualFunction27();
    virtual int VirtualFunction28();
    virtual int VirtualFunction29();
    virtual int reserved30();
    virtual int reserved31();
    virtual int reserved32();
    virtual int reserved33();
    virtual int reserved34();
    virtual int reserved35();
    virtual int reserved36();
    virtual int get37();
    virtual int get38();
};
struct BoundObj
{
    virtual int reserved0();
    virtual int reserved1();
    virtual int reserved2();
    virtual int reserved3();
    virtual int FunctionAtSlot4();
    virtual int FunctionAtSlot5();
    virtual int FunctionAtSlot6();
    virtual int VirtualFunction7();
    virtual int VirtualFunction8();
    virtual int VirtualFunction9();
    virtual int VirtualFunction10();
    virtual int ReplaceImpactData();
    virtual int reserved12();
    virtual int VirtualFunction13();
    virtual int reserved14();
    virtual int reserved15();
    virtual int reserved16();
    virtual int reserved17();
    virtual int reserved18();
    virtual int reserved19();
    virtual int reserved20();
    virtual int reserved21();
    virtual int VirtualFunction22();
    virtual int VirtualFunction23();
    virtual int VirtualFunction24();
    virtual int VirtualFunction25();
    virtual int VirtualFunction26();
    virtual int VirtualFunction27();
    virtual int VirtualFunction28();
    virtual int VirtualFunction29();
    virtual int reserved30();
    virtual int reserved31();
    virtual int reserved32();
    virtual int reserved33();
    virtual int reserved34();
    virtual int reserved35();
    virtual int reserved36();
    virtual int reserved37();
    virtual int reserved38();
    virtual int reserved39();
    virtual int reserved40();
    virtual int reserved41();
    virtual int reserved42();
    virtual int reserved43();
    virtual int reserved44();
    virtual int reserved45();
    virtual int reserved46();
    virtual int reserved47();
    virtual int reserved48();
    virtual int reserved49();
    virtual int reserved50();
    virtual int reserved51();
    virtual int reserved52();
    virtual int reserved53();
    virtual int reserved54();
    virtual int reserved55();
    virtual int reserved56();
    virtual int reserved57();
    virtual int reserved58();
    virtual int reserved59();
    virtual int reserved60();
    virtual int reserved61();
    virtual int reserved62();
    virtual int reserved63();
    virtual int reserved64();
    virtual int reserved65();
    virtual int reserved66();
    virtual int reserved67();
    virtual int reserved68();
    virtual int reserved69();
    virtual int reserved70();
    virtual int reserved71();
    virtual int reserved72();
    virtual int reserved73();
    virtual int reserved74();
    virtual int reserved75();
    virtual int reserved76();
    virtual int reserved77();
    virtual int reserved78();
    virtual int reserved79();
    virtual void* getObj80();
};
struct NavPtr
{
    void* p;
    void* Modelloader_GetReferencedThis();
    NavPtr& FUN_006e5cc0(const NavPtr& other);
    void FUN_0066b0d0(void* arg);
};
struct PropPtr
{
    VObj* p;
    VObj* Modelloader_GetReferencedThis();
};
struct Obj20
{
    int f00[12];
    NavPtr m_30;
    Vec4f m_34;
    Vec4f m_44;
    Vec4f m_54;
    unsigned int GetNoiseTextureNameLength();
    unsigned char GetByteAtOffset190();
    void GetNoiseTexture(void* arg);
    void* GetNoiseTextureName(void* arg, int a2, int a3);
    void SetByteAtOffset190(int arg);
    float GetFieldE8Float();
    float GetFieldEC();
    float Projectile_GetSpreadLooking();
    float GetField130();
    float TESObjectWEAP_GetShotsPerSecond();
    float GetFootWeight();
    float TESEffectShader_GetAddOnScaleStart();
    float TESObjectWEAP_GetFiringRumbleRightMotorStrength();
    float GetFloatAt144();
    float Sky_GetCurrentWeatherPct();
    float TESObjectWEAP_GetSpeed();
    float FUN_006447f0();
};
struct PropObj
{
    int f00[71];
    float m_11c;
    int f120[5];
    PropPtr m_134;
    NavPtr m_138;
};
struct Refr
{
    BoundObj* BGSSaveFormBuffer_GetForm();
};
struct StrList
{
    void* p;
    void* Modelloader_GetReferencedThis();
    void* DereferenceIfNotNull(void* zpos);
    Refr*& AddEight(void* zpos);
};
struct ParamObj
{
    int f00[9];
    StrList m_24;
};
struct ProcObj
{
    int FUN_008d8520();
};
struct ItemObj
{
    ProcObj* CombatController_GetTarget();
    PropObj* FUN_00a59d30(int arg);
};
struct G4680Obj
{
    unsigned char GetByteAtOffset2B8();
    void ImageSpaceEffectNoise_ShufflePermuationTable();
};
struct Map6c
{
    bool NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_bool_GetAt(Obj20* obj, bool& oflag);
    void NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_bool_SetAt(Obj20* obj, bool value);
};
extern GlobalObject_0045cf30 g_011c7b98;


struct TESObj
{
    void FUN_004568c0(void* arg);
};
struct ImgMgr
{
    void ImageSpaceManager_RenderEffect_2(int a1, void* a2, void* a3, void* a4, int a5, int a6);
    static ImgMgr* BSShaderManager_GetImageSpaceManager();
};
int __cdecl ImageSpaceEffectNoise_GetInstance();
float __cdecl BSShaderManager_GetTimer(bool arg);
float __cdecl sin_004e44b0(float value);
float __cdecl cos(float value);
float __cdecl FUN_004e4430(float value);
float __cdecl BSMAX_00404010(float a, float b);
void __cdecl WrapValueToRange(float* ptr, float a, float b);
void* __cdecl BSShaderManager_GetRenderer();
BSTextureManager* __stdcall BSShaderManager_GetTextureManager();
extern int DAT_011ad81c;
extern int DAT_011ad820;
extern float DAT_011ffe48;
extern Vec4f DAT_011ffe4c;
extern Vec4f DAT_011ffe5c;
extern Vec4f DAT_011ffe6c;
extern float DAT_011ffe7c;
extern float DAT_011ffe80;
extern float DAT_011ffe84;
extern float DAT_011ffe8c;
extern float DAT_011ffe90;
extern float DAT_011ffe94;
struct Self
{
    int f00[27];
    Map6c m_6c;
    ItemObj* TESWaterSystem_GetWaterGeometry(Refr* rrefr);
    void AssignMemberToSource(void* arg);
    void TESWaterSystem_UpdateWaterNoise(ParamObj* param);
};
// Iterates param's list; for entries whose ProcObj FUN_008d8520 returns 13, updates texture pointers and vectors and writes DAT_011ffe* globals.
// @fnv 0x004e3d60
// src: COMMUNITY 0x004e3d60
void Self::TESWaterSystem_UpdateWaterNoise(ParamObj* param)
{
    void* zpos = param->m_24.Modelloader_GetReferencedThis();
    void* next = 0;
    while (zpos != 0)
    {
        next = param->m_24.DereferenceIfNotNull(zpos);
        Refr* rrefr = param->m_24.AddEight(zpos);
        BoundObj* bound = rrefr->BGSSaveFormBuffer_GetForm();
        Obj20* obj = (Obj20*)bound->getObj80();
        if (obj != 0)
        {
            if (obj->GetNoiseTextureNameLength() != 0)
            {
                if (!((G4680Obj*)ImageSpaceEffectNoise_GetInstance())->GetByteAtOffset2B8())
                {
                    ((G4680Obj*)ImageSpaceEffectNoise_GetInstance())->ImageSpaceEffectNoise_ShufflePermuationTable();
                }
                ItemObj* item = TESWaterSystem_GetWaterGeometry(rrefr);
                if (item != 0)
                {
                    ItemObj* item3 = item;
                    ProcObj* proc = item3->CombatController_GetTarget();
                    if (proc != 0)
                    {
                        if (proc->FUN_008d8520() == 13)
                        {
                            PropObj* propTemp = item->FUN_00a59d30(3);
                            PropObj* pprop = propTemp;
                            if (*g_011c7b98.Bool())
                            {
                                if (pprop->m_134.Modelloader_GetReferencedThis() == 0)
                                {
                                    AssignMemberToSource(&pprop->m_134);
                                }
                            }
                            else
                            {
                                if (pprop->m_134.Modelloader_GetReferencedThis() == 0 || obj->GetByteAtOffset190())
                                {
                                    NiPointer<NiSourceTexture> localPtr(0);
                                    obj->GetNoiseTexture(&localPtr);
                                    if ((NiSourceTexture*)localPtr != 0)
                                    {
                                        obj->GetNoiseTexture(&pprop->m_134);
                                    }
                                    else
                                    {
                                        ((TESObj*)DAT_011dea10)->FUN_004568c0(obj->GetNoiseTextureName(&pprop->m_134, 1, 0));
                                    }
                                    obj->SetByteAtOffset190(0);
                                }
                            }
                            if (pprop->m_134.Modelloader_GetReferencedThis() != 0)
                            {
                                if (obj->m_30.Modelloader_GetReferencedThis() == 0)
                                {
                                    DAT_011ad81c = pprop->m_134.Modelloader_GetReferencedThis()->get37();
                                    DAT_011ad820 = pprop->m_134.Modelloader_GetReferencedThis()->get38();
                                    obj->m_30.FUN_0066b0d0(BSShaderManager_GetTextureManager()->BSTextureManager_BorrowRenderedTexture(BSShaderManager_GetRenderer(), 0x13, 0, 0, 0));
                                }
                            }
                            pprop->m_138.FUN_006e5cc0(obj->m_30);
                            bool oflag = false;
                            if (!m_6c.NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_bool_GetAt(obj, oflag))
                            {
                                if (pprop->m_134.Modelloader_GetReferencedThis() != 0)
                                {
                                    DAT_011ffe48 = pprop->m_11c;
                                    float f_44 = BSShaderManager_GetTimer(true);
                                    float f_40 = obj->GetFieldE8Float();
                                    float zf4c = obj->GetFieldEC();
                                    float f48 = obj->Projectile_GetSpreadLooking();
                                    obj->m_34.v[0] += (double)sin_004e44b0((float)(f_40 * 0.01745329238474369)) *
                                                      (obj->Sky_GetCurrentWeatherPct() * f_44);
                                    obj->m_34.v[1] +=
                                        (double)cos((float)(f_40 * 0.01745329238474369)) * (obj->Sky_GetCurrentWeatherPct() * f_44);
                                    obj->m_44.v[0] += (double)sin_004e44b0((float)(zf4c * 0.01745329238474369)) *
                                                      (obj->TESObjectWEAP_GetSpeed() * f_44);
                                    obj->m_44.v[1] +=
                                        (double)cos((float)(zf4c * 0.01745329238474369)) * (obj->TESObjectWEAP_GetSpeed() * f_44);
                                    obj->m_54.v[0] += (double)sin_004e44b0((float)(f48 * 0.01745329238474369)) *
                                                      (obj->FUN_006447f0() * f_44);
                                    obj->m_54.v[1] +=
                                        (double)cos((float)(f48 * 0.01745329238474369)) * (obj->FUN_006447f0() * f_44);
                                    WrapValueToRange(&obj->m_34.v[0], 0.0f, 1.0f);
                                    WrapValueToRange(&obj->m_34.v[1], 0.0f, 1.0f);
                                    WrapValueToRange(&obj->m_44.v[0], 0.0f, 1.0f);
                                    WrapValueToRange(&obj->m_44.v[1], 0.0f, 1.0f);
                                    WrapValueToRange(&obj->m_54.v[0], 0.0f, 1.0f);
                                    WrapValueToRange(&obj->m_54.v[1], 0.0f, 1.0f);
                                    DAT_011ffe4c = obj->m_34;
                                    DAT_011ffe5c = obj->m_44;
                                    DAT_011ffe6c = obj->m_54;
                                    DAT_011ffe7c = BSMAX_00404010(1.0f, FUN_004e4430(obj->GetField130() / 100.0));
                                    DAT_011ffe80 = BSMAX_00404010(1.0f, FUN_004e4430(obj->TESObjectWEAP_GetShotsPerSecond() / 100.0));
                                    DAT_011ffe84 = BSMAX_00404010(1.0f, FUN_004e4430(obj->GetFootWeight() / 100.0));
                                    DAT_011ffe8c = obj->TESEffectShader_GetAddOnScaleStart();
                                    DAT_011ffe90 = obj->TESObjectWEAP_GetFiringRumbleRightMotorStrength();
                                    DAT_011ffe94 = obj->GetFloatAt144();
                                    ImgMgr::BSShaderManager_GetImageSpaceManager()->ImageSpaceManager_RenderEffect_2(0x21, BSShaderManager_GetRenderer(),
                                                                         pprop->m_134.Modelloader_GetReferencedThis(),
                                                                         obj->m_30.Modelloader_GetReferencedThis(), 0, 1);
                                }
                                m_6c.NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_bool_SetAt(obj, true);
                            }
                        }
                    }
                }
            }
        }
        zpos = next;
    }
}
