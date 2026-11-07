#include "../../include/BSStringT.h"

// src/staging/blk_00820000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BSAudio.h"
#include "../../include/BSSimpleList.h"
#include "../../include/CBSAStream.h"
#include "../../include/NiPoint3.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; this unit uses the stand-in's uint aliases xb/yb/zb or its weapon_audio::NiPoint3 interop, which NiPoint3 does not have.
#include "../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    weapon_audio::NiPoint3 operator-(const weapon_audio::NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void SetComponents(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other) const;
    bool HasEqualComponents(const char* other);
    void ScaleComponents(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void SubtractIntoVector();
    LocalVec3 SubtractIntoVector(const LocalVec3& other);
    LocalVec3 SubtractIntoVector(const LocalVec3& other) const;
    LocalVec3 SubtractIntoVector(LocalVec3* other);
    LocalVec3 SubtractIntoVector(const LocalVec3* other);
    void SubtractIntoVector(LocalVec3* output, const LocalVec3* other);
    LocalVec3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& other) const;
    LocalVec3 ProcessAndReturnValue_0053d280(float divisor);
    float NiPoint3_XYLength();
    float NiPoint3_XYLength() const;
    void ComputeValue_0063c8a0(const LocalVec3* other);
    void ComputeValue_0063c8a0(void* other);
    void FUN_006815c0();
    float CVec3_Distance(LocalVec3* other);
    float CVec3_Distance(const LocalVec3& other) const;
    LocalVec3 TransformPointByMatrix4(const Mat& matrix);
    LocalVec3 TransformPointByMatrix4(const Matrix4* matrix);
    void Normalize_00b12790();
    LocalVec3 Diff_00b13040(void* other);
    LocalVec3 Diff_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& AddComponents(void* other);
    void ProcessEntries_00ddc870();
    void FUN_00e0f6e0();
};
#include "../../include/TESSound.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/SL.h"
#include "../../include/StrMem.h"
#include "../../include/ActiveEffect.h"
#include "../../include/Actor.h"
#include "../../include/EffectSetting.h"
#include "../../include/MagicProjectile.h"
#include "../../include/MobileObject.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESQuest.h"
#include "../../include/TESTopicInfo.h"

#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSLoadGameBuffer.h"
#include "../../include/GO.h"
#include "../../include/RecursiveLock.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/TESForm.h"
#include "../../include/TESIdleForm.h"
#include "../../include/TESObject.h"
#include "../../include/TESTopic.h"

struct FUN_00821620_Class
{
    void __thiscall BoltShaderProperty_SetBoltsRadius(float value);
};

// @fnv 0x00821620
// src: XBOX_PDB 0x00821620
void __thiscall FUN_00821620_Class::BoltShaderProperty_SetBoltsRadius(float value)
{
    *(float*)((char*)this + 0x130) = value;
}

struct FUN_00821680_Class
{
    float TESObjectWEAP_GetFiringRumbleRightMotorStrength() const;
};

// @fnv 0x00821680
// src: COMMUNITY 0x00821680
float FUN_00821680_Class::TESObjectWEAP_GetFiringRumbleRightMotorStrength() const
{
    return *(const float*)((const char*)this + 0x140);
}

struct FUN_008216a0_class
{
    float GetValue() const;
};

// @fnv 0x008216a0
float FUN_008216a0_class::GetValue() const
{
    return *(const float*)((const char*)this + 0x148);
}

// @fnv 0x00824080
bool ActiveEffect::IsFlag200Set()
{
    return (iFlags & 0x200) != 0;
}

struct FUN_00827200_class
{
    void __thiscall _ref_006815c0();
    void __thiscall FUN_00cb26e0(int);
    FUN_00827200_class* __thiscall hkQuaternion_hkQuaternion(int a);
};
// Calls _ref_006815c0, then FUN_00cb26e0 with a, and returns this.
// @fnv 0x00827200
// src: XBOX_PDB 0x00827200
FUN_00827200_class* __thiscall FUN_00827200_class::hkQuaternion_hkQuaternion(int a)
{
    _ref_006815c0();
    FUN_00cb26e0(a);
    return this;
}

// @fnv 0x0082d660
char TESSound::GetByteAtOffset44()
{
    return (char)data.minAttenuation;
}

// @fnv 0x0082d6a0
unsigned short TESSound::GetShortAt(int index)
{
    return data.attenuationCurve[index];
}

// @fnv 0x0082d6c0
unsigned short __thiscall TESSound::GetShortAtOffset5A()
{
    return data.reverbAttenuation;
}

// @fnv 0x0082d700
// src: COMMUNITY 0x0082d700
unsigned char TESSound::GetEndTime_0082d700()
{
    return data.stopTime & 0xff;
}

// @fnv 0x0082d720
// src: COMMUNITY 0x0082d720
unsigned int __thiscall TESSound::GetPriority_0082d720()
{
    return data.unk18 & 0xff;
}

extern int DAT_0107ca44;
void __cdecl InitArray(int);
struct FUN_0082ee80_class
{
    int* m_p;
    void InitArray(int);
    FUN_0082ee80_class* InitializeWithGlobal(int a);
};
// Calls InitArray with the argument, stores the address of DAT_0107ca44 in m_p, and returns this.
// @fnv 0x0082ee80
FUN_0082ee80_class* FUN_0082ee80_class::InitializeWithGlobal(int a)
{
    InitArray(a);
    m_p = &DAT_0107ca44;
    return this;
}

extern "C" void* DAT_0107cb6c;

struct FUN_0082f140_class
{
    void SetVirtualTable_0082f140();
};

// @fnv 0x0082f140
// src: GUESS 0x0082f140 (confidence: low)
void __thiscall FUN_0082f140_class::SetVirtualTable_0082f140()
{
    *reinterpret_cast<void**>(this) = &DAT_0107cb6c;
}

void __fastcall NiCriticalSection_Lock(void*);

struct FUN_0082f190_class
{
    void CBSAStream_Lock();
};

// @fnv 0x0082f190
// src: COMMUNITY 0x0082f190
void FUN_0082f190_class::CBSAStream_Lock()
{
    NiCriticalSection_Lock(reinterpret_cast<char*>(this) + 0x10c);
}

// @fnv 0x0082f1d0
// src: COMMUNITY 0x0082f1d0
void CBSAStream::Unlock_0082f1d0()
{
    reinterpret_cast<RecursiveLock*>(reinterpret_cast<char*>(this) + 0x10c)->Leave();
}

namespace fnv_0082f240 {
extern int DAT_0107cb6c;

struct FUN_0082f240_class
{
    void* vtbl;
    FUN_0082f240_class();
};

// @fnv 0x0082f240
FUN_0082f240_class::FUN_0082f240_class()
{
    vtbl = &DAT_0107cb6c;
}
}  // namespace fnv_0082f240

void __fastcall NiCriticalSection_Lock(void*);

struct FUN_0082f520Class
{
    void* p;
    void* __thiscall ProcessAndReturnValue_0082f520(void* v);
};

// Stores v into p, calls FUN_0082f1b0 on p, and returns this.
// @fnv 0x0082f520
// src: GUESS 0x0082f520 (confidence: low)
void* __thiscall FUN_0082f520Class::ProcessAndReturnValue_0082f520(void* pValue)
{
    p = pValue;
    NiCriticalSection_Lock(p);
    return this;
}

namespace fnv_0082f550 {

// @fnv 0x0082f550
void __fastcall LeaveObject(void* p)
{
    ((RecursiveLock**)(int*)p)[0]->Leave();
}
}  // namespace fnv_0082f550

struct FUN_00831e00_class
{
    int __thiscall IsFlagSet();
};

// @fnv 0x00831e00
int __thiscall FUN_00831e00_class::IsFlagSet()
{
    return (*(int*)((char*)this + 8) & 1) != 0;
}

extern "C" void __stdcall ReceiveConnection(int, int, int);

struct FUN_00831f40_Class
{
    void ReceiveConnection_Thunk(int a, int b);
};

// @fnv 0x00831f40
// src: GUESS 0x00831f40 (confidence: medium)
void FUN_00831f40_Class::ReceiveConnection_Thunk(int aiArg1, int aiArg2)
{
    ReceiveConnection((int)this + 0x104, aiArg1, aiArg2);
}

struct FUN_008321c0_Class
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void FUN_00836030();
    void ForwardCall_008321c0();
};
// @fnv 0x008321c0
// src: GUESS 0x008321c0 (confidence: low)
void FUN_008321c0_Class::ForwardCall_008321c0()
{
    ((FUN_008321c0_Class*)((char*)this + 4))->FUN_00836030();
}

struct FUN_00836240
{
    void LoadGame(BGSLoadFormBuffer*);
};
struct FUN_00836630
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};
// @fnv 0x00836630
void FUN_00836630::LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadFormIdentifier(this);
    reinterpret_cast<FUN_00836240*>(reinterpret_cast<char*>(this) + 4)->LoadGame(buffer);
}

extern int DAT_011a1888[];
extern int DAT_011dd87c[];

// Returns the entry at index from DAT_011dd87c if non-zero, otherwise the entry at index from DAT_011a1888.
// @fnv 0x008374b0
// src: XBOX_PDB 0x008374b0
int __cdecl ImpactMixer_GetMaterialSoundName(int index)
{
    if (DAT_011dd87c[index])
        return DAT_011dd87c[index];
    return DAT_011a1888[index];
}

namespace fnv_008374e0 {
extern int DAT_011dd87c;

// @fnv 0x008374e0
void __cdecl SetGlobalPointerAtOffset(int aiOffset, const char* apValue)
{
    *(int*)(&DAT_011dd87c + aiOffset) = (int)apValue;
}
}  // namespace fnv_008374e0

extern "C" void __cdecl FalloutAudio_FUN_00839ab0();
extern unsigned char DAT_011dd85c;

// @fnv 0x00837500
// src: COMMUNITY 0x00837500
void ResetFootstepSounds()
{
    DAT_011dd85c = 0;
    FalloutAudio_FUN_00839ab0();
}

extern "C" void* DAT_0107d9c4;

struct FUN_0083b5e0_class
{
    void* m_ptr;
    void InitBuffer(int);
    void* NiTPointerMap_int_unsigned_int_NiTPointerMap(int a);
};

// Calls InitBuffer with the argument, sets m_ptr to DAT_0107d9c4, and returns this.
// @fnv 0x0083b5e0
// src: EXE 0x0083b5e0
void* FUN_0083b5e0_class::NiTPointerMap_int_unsigned_int_NiTPointerMap(int a)
{
    InitBuffer(a);
    m_ptr = &DAT_0107d9c4;
    return this;
}

struct S7010
{
    unsigned int Length();
};
struct FUN_0083dea0_class
{
    unsigned int TESTopic_HasDummyPrompt();
};
// @fnv 0x0083dea0
// src: XBOX_PDB 0x0083dea0
unsigned int FUN_0083dea0_class::TESTopic_HasDummyPrompt()
{
    return 0 < ((S7010*)((char*)this + 0x34))->Length();
}

namespace fnv_0083e0a0 {
struct S7010
{
    unsigned int Length();
};
struct FUN_0083e0a0_Class
{
    unsigned int GetLength();
};
// @fnv 0x0083e0a0
unsigned int FUN_0083e0a0_Class::GetLength()
{
    return ((S7010*)((char*)this + 0x18))->Length();
}
}  // namespace fnv_0083e0a0

extern "C" void* __cdecl _NiFreeAlias(void*);
extern void* DAT_0107ca64;

struct FUN_0082efb0
{
    void SetVtableAndProcessState_0082efb0();
};

// Sets the vtable pointer, clears the pointer map, and frees the pointer stored at offset 8.
// @fnv 0x0082efb0
// src: GUESS 0x0082efb0 (confidence: low)
void FUN_0082efb0::SetVtableAndProcessState_0082efb0()
{
    *(void**)((char*)this + 0) = (void*)&DAT_0107ca64;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    _NiFreeAlias(*(void**)(this + 8));
}

namespace fnv_0083b710 {
extern "C" void __cdecl _NiFreeAlias(void*);
extern void* DAT_0107d9e4;

struct FUN_0083b710_cls : public NiTPointerMap<int, int>
{
    void SetVtableAndProcessState_0083b710();
};

// @fnv 0x0083b710
// src: GUESS 0x0083b710 (confidence: low)
void FUN_0083b710_cls::SetVtableAndProcessState_0083b710()
{
    *reinterpret_cast<void**>(this) = &DAT_0107d9e4;
    RemoveAll();
    _NiFreeAlias(reinterpret_cast<void*>(reinterpret_cast<int*>(this)[2]));
}
}  // namespace fnv_0083b710

struct FUN_00438690
{
    ~FUN_00438690();
};
struct FUN_00822630
{
    ~FUN_00822630();
};
struct FUN_008224b0_Class
{
    FUN_00822630 a;
    int pad[3];
    FUN_00438690 b;
    ~FUN_008224b0_Class();
};
// @fnv 0x008224b0
FUN_008224b0_Class::~FUN_008224b0_Class()
{}

// Runs the destructor and, if flags has bit 0 set, frees the object; returns the pointer.
// @fnv 0x008228f0
GO* __thiscall GO::FUN_008228f0(unsigned int flags)
{
    GO::~GO();
    if (flags & 1)
        operator delete(this);
    return this;
}

void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_0082eee0_class
{
    void* __thiscall InitArray(int size);
};
// @fnv 0x0082eee0
void* __thiscall FUN_0082eee0_class::InitArray(int aiCount)
{
    *(void***)this = &DAT_0107ca64;
    ((int*)this)[1] = aiCount;
    ((int*)this)[3] = 0;
    unsigned int len = ((int*)this)[1] << 2;
    ((int*)this)[2] = (int)_NiMalloc(len);
    memset(*(void**)((int*)this + 2), 0, ((int*)this)[1] << 2);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_00831f80_class
{
    void __thiscall SetVtableAndProcessState_00831fb0();
    void* __thiscall FUN_00831f80(unsigned int flags);
};
// Calls FUN_00831fb0, then frees this with Deallocate if flags has bit 0 set, and returns this.
// @fnv 0x00831f80
void* __thiscall FUN_00831f80_class::FUN_00831f80(unsigned int flags)
{
    SetVtableAndProcessState_00831fb0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_0107cd54;
extern int DAT_0107cd6c;
extern int DAT_0107cdac;
extern "C" void __fastcall FUN_009fdc10(void*);
struct FUN_00831fb0_class
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    void __thiscall SetVtableAndProcessState_00831fb0();
};
// Sets the object's vtbl and two fields to the given globals, then calls FUN_009fdc10 on this.
// @fnv 0x00831fb0
// src: GUESS 0x00831fb0 (confidence: low)
void __thiscall FUN_00831fb0_class::SetVtableAndProcessState_00831fb0()
{
    vtbl = &DAT_0107cdac;
    c = (int)&DAT_0107cd6c;
    d = (int)&DAT_0107cd54;
    FUN_009fdc10(this);
}

struct FUN_00836600_class
{
    void __thiscall RadioEntry_Save(BGSLoadFormBuffer* buffer);
    void __thiscall RadioEntry_Data_Save(BGSLoadFormBuffer* buffer);
};
// @fnv 0x00836600
// src: COMMUNITY 0x00836600
void __thiscall FUN_00836600_class::RadioEntry_Save(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<BGSSaveFormBuffer*>(buffer)->SerializeFormData(
        reinterpret_cast<void*>(reinterpret_cast<int*>(this)[0]), 0);
    reinterpret_cast<FUN_00836600_class*>(reinterpret_cast<char*>(this) + 4)->RadioEntry_Data_Save(buffer);
}

struct FUN_00837280_Class
{
    char RadioConvTask_GetFileIndex();
};
// @fnv 0x00837280
// src: COMMUNITY 0x00837280
char FUN_00837280_Class::RadioConvTask_GetFileIndex()
{
    return 3;
}

namespace fnv_0083b640 {
extern "C" void* _NiMalloc(unsigned int size);
void* memset(void* dest, int c, unsigned int count);
extern "C" void* DAT_0107d9e4;
struct FUN_0083b640_class
{
    void* m_vt;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_0083b640_class* __thiscall InitBuffer(int a);
};
// Sets the vtable, stores a count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x0083b640
FUN_0083b640_class* __thiscall FUN_0083b640_class::InitBuffer(int aiCount)
{
    m_vt = &DAT_0107d9e4;
    m_uiItemCount = aiCount;
    m_auiShapeKeys = 0;
    unsigned int size = m_uiItemCount * 4;
    m_data = _NiMalloc(size);
    memset(m_data, 0, m_uiItemCount * 4);
    return this;
}
}  // namespace fnv_0083b640

void __cdecl Deallocate(void*);
struct FUN_0083b740_Class
{
    void* __thiscall FUN_0083b740(unsigned int flags);
    void __thiscall SetVtableAndProcessState_0083b710();
};
// Calls FUN_0083b710, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0083b740
void* __thiscall FUN_0083b740_Class::FUN_0083b740(unsigned int flags)
{
    SetVtableAndProcessState_0083b710();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0083b770
{
    BSSoundHandle a;
    BSSoundHandle b;
    FUN_0083b770();
};
// @fnv 0x0083b770
FUN_0083b770::FUN_0083b770()
{}

struct Date
{
    ~Date();
};
struct FUN_0083b7d0
{
    Date a;
    int b;
    int c;
    Date d;
    ~FUN_0083b7d0();
};
// Destructor for a structure holding two Date members and two ints; it performs no work.
// @fnv 0x0083b7d0
FUN_0083b7d0::~FUN_0083b7d0()
{}

void __cdecl Deallocate(void*);
struct FUN_0083c750_class
{
    void __thiscall FUN_0083c750();
    void* __thiscall FUN_0083c720(unsigned int flags);
};
// Calls FUN_0083c750, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0083c720
void* __thiscall FUN_0083c750_class::FUN_0083c720(unsigned int flags)
{
    FUN_0083c750();
    if (flags & 1)
        Deallocate(this);
    return this;
}

TESForm* __cdecl ref_004839c0(TESForm* p);
struct FUN_0083d0d0_Class
{
    void RefreshObjectRef(int a);
};
// Re-casts the TESForm pointer at offset 0x18 to TESObjectREFR via ref_004839c0, storing the result or null if the pointer was null.
// @fnv 0x0083d0d0
void FUN_0083d0d0_Class::RefreshObjectRef(int a)
{
    *(TESObjectREFR**)((char*)this + 0x18) =
        *(TESObjectREFR**)((char*)this + 0x18)
            ? (TESObjectREFR*)dynamic_cast<TESObjectREFR*>(ref_004839c0(*(TESForm**)((char*)this + 0x18)))
            : 0;
}

struct WeatherEntry
{
    int a;
    int b;
    int c;
    WeatherEntry();
};
struct G2
{
    void AddHead(WeatherEntry**);
};
struct FUN_00824290_class
{
    void __thiscall AddWeatherEntry(int a, int b, int c);
};
// Allocates a WeatherEntry storing the three arguments and adds it to the head of the list at this+8.
// @fnv 0x00824290
void __thiscall FUN_00824290_class::AddWeatherEntry(int aiFirst, int aiSecond, int aiThird)
{
    WeatherEntry* pEntry = new WeatherEntry;
    pEntry->a = aiFirst;
    pEntry->b = aiSecond;
    pEntry->c = aiThird;
    ((G2*)((char*)this + 8))->AddHead(&pEntry);
}

// If self is non-null and its sound data has a non-zero a or b, writes a and b to outA and outB and returns true; otherwise returns false.
// @fnv 0x0082d740
// src: COMMUNITY 0x0082d740
bool GetSoundLoopPoints(TESSound* self, int* outA, int* outB)
{
    if (!self)
        return false;
    TESSound* p = self;
    if (p->CopyBig().m_uiTrailingValue1 || p->CopyBig().m_uiTrailingValue2)
    {
        *outA = p->CopyBig().m_uiTrailingValue1;
        *outB = p->CopyBig().m_uiTrailingValue2;
        return true;
    }
    return false;
}

struct SndItem
{
    TESObject* obj;
    BSSoundHandle first;
    BSSoundHandle second;
    bool active;
};
int __fastcall FNV_GetFormType(TESForm*);
struct ContNode
{
    SndItem** ref_006815c0();
};
bool __fastcall FUN_008256d0(ContNode*);
ContNode* __fastcall FUN_00726070(ContNode*);
struct Q
{
    ~Q();
};
struct S_00836470
{
    Q* m_p;
    int m_iWordAt04;
    unsigned int m_uiCommandId;
    int m_uiItemCount;
    int m_10;
    int m_14;
    ContNode m_kNode;
    void UpdateSoundItems(int);
};

// @fnv 0x00836470
void S_00836470::UpdateSoundItems(int)
{
    if (BSAudio::GetSingleton()->GetSynchTime() < m_uiCommandId || m_uiItemCount <= 0)
    {
        m_uiCommandId = 0;
        m_uiItemCount = 1;
        delete m_p;
        m_p = 0;
    }
    else
    {
        m_uiCommandId = BSAudio::GetSingleton()->GetSynchTime() - m_uiCommandId;
    }
    ContNode* node = &m_kNode;
    while (node && !FUN_008256d0(node) && *node->ref_006815c0())
    {
        if (!(*node->ref_006815c0())->obj || !(*node->ref_006815c0())->obj->GetNext() ||
            (FNV_GetFormType((TESForm*)(*node->ref_006815c0())->obj->GetNext()) == 0x15 &&
             !((EffectSetting*)(*node->ref_006815c0())->obj->GetNext())->GetBoltSound()))
        {
            (*node->ref_006815c0())->first.Stop();
            (*node->ref_006815c0())->first.Clear();
            (*node->ref_006815c0())->second.Stop();
            (*node->ref_006815c0())->second.Clear();
            (*node->ref_006815c0())->active = false;
        }
        node = FUN_00726070(node);
    }
}

void* __cdecl operator new(unsigned int);

TESForm* __cdecl GetFormByID(unsigned int formID);
struct FUN_0083d1e0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    FUN_0083d1e0();
    void DialogueResponse_LoadGameBGS(BGSLoadFormBuffer* buffer);
};
struct DialogueResponseList
{
    FUN_0083d1e0* item;
    DialogueResponseList* next;
    void AddTail(FUN_0083d1e0* const& data);
};
struct DialogueItem_shell
{
    DialogueResponseList responses;
    unsigned int unk08;
    TESTopicInfo* topicInfo;
    TESTopic* topic;
    TESQuest* quest;
    unsigned int speaker;
    FUN_0083d1e0* GetResponseByIndex(short id);
    void FUN_0083c8a0(FUN_0083d1e0* response);
    void LoadDialogueItem(BGSLoadFormBuffer* buffer);
};
// Reads a response count and its responses, an optional current response id, topic info, topic, quest and speaker from the load buffer.
// @fnv 0x0083cf40
void DialogueItem_shell::LoadDialogueItem(BGSLoadFormBuffer* buffer)
{
    short currentID;
    {
        unsigned int count = ((BGSLoadGameBuffer*)buffer)->ReadElementCount();
        for (unsigned int i = 0; i < count; ++i)
        {
            FUN_0083d1e0* response = new FUN_0083d1e0;
            response->DialogueResponse_LoadGameBGS(buffer);
            responses.AddTail(response);
        }
    }
    currentID = -1;
    ((BGSLoadGameBuffer*)buffer)->ReadTypedData(&currentID, 2);
    if (currentID != -1)
        FUN_0083c8a0(GetResponseByIndex(currentID));
    topicInfo = dynamic_cast<TESTopicInfo*>(GetFormByID(((BGSLoadGameBuffer*)buffer)->ReadFormIdentifier()));
    topic = dynamic_cast<TESTopic*>(GetFormByID(((BGSLoadGameBuffer*)buffer)->ReadFormIdentifier()));
    quest = dynamic_cast<TESQuest*>(GetFormByID(((BGSLoadGameBuffer*)buffer)->ReadFormIdentifier()));
    buffer->ReadFormIdentifier(&speaker);
}

struct ListX
{
    ~ListX();
};
struct FUN_00836030_class
{
    Q* a;
    Q* b;
    int pad[4];
    ListX c;
    ~FUN_00836030_class();
};
// @fnv 0x00836030
FUN_00836030_class::~FUN_00836030_class()
{
    if (b != a)
    {
        delete b;
        b = 0;
    }
    b = 0;
    if (a)
    {
        delete a;
        a = 0;
    }
    a = 0;
}

struct FUN_00822a40_Class
{
    int* vtbl;
    unsigned char flag4;
    unsigned char flag5;
    SL sl;

    FUN_00822a40_Class();
};

extern int DAT_0107bc28;

// Initializes the object's vtable pointer to DAT_0107bc28 and clears flag4 and flag5.
// @fnv 0x00822a40
FUN_00822a40_Class::FUN_00822a40_Class() : vtbl(&DAT_0107bc28)
{
    flag4 = 0;
    flag5 = 0;
}

struct FUN_0080d930
{
    ~FUN_0080d930();
};
struct FUN_00825740 : FUN_0080d930
{
    ~FUN_00825740();
};
// @fnv 0x00825740
FUN_00825740::~FUN_00825740()
{}

struct BE
{
    void* vtable;
    void* field_04;
    void* field_08;

    BE(unsigned char value);
    ~BE();
};

struct BCaster_S
{
    void* vtable;
    void* field_04;
    void* field_08;

    BCaster_S();
    ~BCaster_S();
};

extern int DAT_0107be2c;
extern int DAT_0107be80;
extern int _data_011c16bc;

struct FUN_00825a10 : BE
{
    BCaster_S m_caster;
    int m_18;
    int m_1c;
    int m_20;

    FUN_00825a10();
};

// Initializes the object: sets both vtables, zeroes m_18, m_1c and m_20, and constructs the base with value 0x32.
// @fnv 0x00825a10
FUN_00825a10::FUN_00825a10() : BE((unsigned char)0x32), m_caster()
{
    this->vtable = reinterpret_cast<void*>(&DAT_0107be80);
    this->m_caster.vtable = reinterpret_cast<void*>(&DAT_0107be2c);
    this->m_20 = 0;
    this->m_18 = 0;
    this->m_1c = 0;
}

struct FUN_008260b0 : ActiveEffect
{
    FUN_008260b0(MagicCaster* caster, MagicItem* item, EffectItem* effect);
};
// Constructs the ActiveEffect base from caster, item and effect, then sets the vtable pointer to DAT_0107bf1c.
// @fnv 0x008260b0
FUN_008260b0::FUN_008260b0(MagicCaster* caster, MagicItem* item, EffectItem* effect)
    : ActiveEffect(caster, item, effect)
{

}

namespace fnv_00826260 {

// Allocates and constructs a FUN_008260b0 object from the three given arguments, returning the new instance.
// @fnv 0x00826260
FUN_008260b0* __cdecl CreateFUN008260b0(void* a, void* b, void* c)
{
    return new FUN_008260b0(static_cast<MagicCaster*>(a), static_cast<MagicItem*>(b), static_cast<EffectItem*>(c));
}
}  // namespace fnv_00826260

struct FUN_0082b370 : ActiveEffect
{
    unsigned char m_bFlag;
    unsigned char padding49[3];
    FUN_0082b370(MagicCaster* caster, MagicItem* item, EffectItem* effect);
};

// Allocates a FUN_0082b370 object by calling its constructor with the three arguments and returns the new pointer.
// @fnv 0x0082b6d0
FUN_0082b370* CreateFUN0082b370(int a, int b, int c)
{
    return new FUN_0082b370(reinterpret_cast<MagicCaster*>(a), reinterpret_cast<MagicItem*>(b), reinterpret_cast<EffectItem*>(c));
}

namespace fnv_0082cf80 {
class FUN_0082cf80 : public ActiveEffect
{
  public:
    FUN_0082cf80(MagicCaster* pkCaster, MagicItem* pkItem, EffectItem* pkEffect);
    virtual ~FUN_0082cf80();
};

}

// Allocates a FUN_0082cf80 object by calling its constructor with the three arguments and returns the pointer.
// @fnv 0x0082d090
void* __cdecl CreateFUN0082cf80(int a, int b, int c)
{
    return new fnv_0082cf80::FUN_0082cf80(reinterpret_cast<MagicCaster*>(a), reinterpret_cast<MagicItem*>(b), reinterpret_cast<EffectItem*>(c));
}

// @fnv 0x0082d6e0
unsigned char TESSound::GetHighByteOfField4E()
{
    return (unsigned char)((data.stopTime & 0xff00) >> 8);
}

struct GlobalObject_0082ee80
{
    ~GlobalObject_0082ee80();
    GlobalObject_0082ee80* __thiscall FUN_0082eeb0(unsigned int flags);
};
// Runs the destructor, frees the object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0082eeb0
GlobalObject_0082ee80* __thiscall GlobalObject_0082ee80::FUN_0082eeb0(unsigned int flags)
{
    this->GlobalObject_0082ee80::~GlobalObject_0082ee80();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0082efb0_Ext : FUN_0082efb0
{
    FUN_0082efb0* FUN_0082efe0(unsigned int flags);
};
// Initializes the object, deallocates it when bit 0 of flags is set, and returns this.
// @fnv 0x0082efe0
FUN_0082efb0* FUN_0082efb0_Ext::FUN_0082efe0(unsigned int flags)
{
    SetVtableAndProcessState_0082efb0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0082f160_class : public FUN_0082f140_class
{
    void* __thiscall FUN_0082f160(unsigned int flags);
};

// @fnv 0x0082f160
void* __thiscall FUN_0082f160_class::FUN_0082f160(unsigned int flags)
{
    SetVirtualTable_0082f140();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_0082f260_class
{
    void __thiscall FUN_0082f260();
    void* __thiscall FUN_0082f210(unsigned int flags);
};
// @fnv 0x0082f210
void* FUN_0082f260_class::FUN_0082f210(unsigned int flags)
{
    FUN_0082f260();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00831de0_Class
{
    char m_00[0x14];
    FUN_00831e00_class m_14;
    int ForwardToMember();
};

// @fnv 0x00831de0
int FUN_00831de0_Class::ForwardToMember()
{
    return m_14.IsFlagSet();
}

typedef void(__stdcall* FUN_00831eb0_callback)(void*, int, int);

// @fnv 0x00831eb0
// src: GUESS 0x00831eb0 (confidence: low)
void __stdcall BSSimpleList_UpdateState_00831eb0(void* object, int aiArg1, int aiArg2)
{
    BSSimpleList<ContNode>* next =
        reinterpret_cast<BSSimpleList<ContNode>*>(reinterpret_cast<char*>(object) - 0x0C)->GetNext();

    reinterpret_cast<FUN_00831eb0_callback>(*reinterpret_cast<void**>(*reinterpret_cast<void**>(next)))(next, aiArg1,
                                                                                                        aiArg2);
}

struct FUN_00831ee0_class
{
    virtual void FUN_00831ee0_virtual0();
    virtual void __stdcall FUN_00831ee0_virtual1();
};

// Retrieves the ContNode at p-0xc via FUN_00726070 and calls its first virtual method.
// @fnv 0x00831ee0
// src: GUESS 0x00831ee0 (confidence: low)
void __stdcall Object_UpdateFields_00831ee0(void* p)
{
    FUN_00831ee0_class* node = (FUN_00831ee0_class*)FUN_00726070((ContNode*)((char*)p - 0xc));

    node->FUN_00831ee0_virtual1();
}

// Deletion helper: 0x008373f0 is also bound as the radio unit's float-list destructor.
struct FloatListDeletion
{
    void* __thiscall DeleteThis(unsigned int flags);
};
// Destroys the float list and, when flags has bit 0 set, deallocates this object; returns this.
// @fnv 0x00837480
void* __thiscall FloatListDeletion::DeleteThis(unsigned int flags)
{
    reinterpret_cast<BSSimpleList<float>*>(this)->~BSSimpleList();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct GlobalObject_0083b5e0
{
    ~GlobalObject_0083b5e0();
    void* __thiscall FUN_0083b610(unsigned int flags);
};

// Runs the destructor, then frees the object with Deallocate when flags has bit 0 set, and returns the object pointer.
// @fnv 0x0083b610
void* GlobalObject_0083b5e0::FUN_0083b610(unsigned int flags)
{
    this->GlobalObject_0083b5e0::~GlobalObject_0083b5e0();
    if (flags & 1)
        Deallocate(this);
    return this;
}



struct BGSLoadGameBufferHelper
{
    char* __thiscall LoadString(char* destination);
};

TESForm* __cdecl _ref_004839c0(unsigned int formID);

struct FUN_0083d740_Class
{
    void __thiscall DialogueResponse_LoadGameBGS(BGSLoadGameBuffer* buffer);
};

// @fnv 0x0083d740
// src: COMMUNITY 0x0083d740
void __thiscall FUN_0083d740_Class::DialogueResponse_LoadGameBGS(BGSLoadGameBuffer* buffer)
{
    char text[1000];

    reinterpret_cast<BGSLoadGameBufferHelper*>(buffer)->LoadString(text);
    reinterpret_cast<::BSStringT<char>*>(this)->Set(text, 0);

    reinterpret_cast<BGSLoadGameBufferHelper*>(buffer)->LoadString(text);
    reinterpret_cast<::BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x10)->Set(text, 0);

    buffer->ReadTypedData(reinterpret_cast<char*>(this) + 8, 4);
    buffer->ReadTypedData(reinterpret_cast<char*>(this) + 0xc, 4);
    buffer->ReadTypedData(reinterpret_cast<char*>(this) + 0x24, 1);

    *reinterpret_cast<TESIdleForm**>(reinterpret_cast<char*>(this) + 0x18) =
        dynamic_cast<TESIdleForm*>(_ref_004839c0(buffer->ReadFormIdentifier()));

    *reinterpret_cast<TESIdleForm**>(reinterpret_cast<char*>(this) + 0x1c) =
        dynamic_cast<TESIdleForm*>(_ref_004839c0(buffer->ReadFormIdentifier()));

    *reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x20) =
        dynamic_cast<TESSound*>(_ref_004839c0(buffer->ReadFormIdentifier()));
}

namespace fnv_0083da50 {

struct FUN_0083da50 : StrMem
{
    // The owner stores its four flag bytes after the eight-byte string.
    unsigned char stringFlags[4];
    SL m_sl;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;

    FUN_0083da50();
};

extern char $SG3295[];

// @fnv 0x0083da50
FUN_0083da50::FUN_0083da50() : StrMem(), m_sl()
{
    m_20 = 0;
    m_14 = 0;
    m_28 = 0;
    m_18 = 0;
    Set($SG3295, 0);
    stringFlags[1] = 0;
    stringFlags[2] = 0;
}
}  // namespace fnv_0083da50

struct Str6a70
{
    Str6a70& __thiscall operator=(char const*);
};

struct BGSLoadGameBufferLoadStringHelper
{
    char* __thiscall LoadString(char*);
};

struct BGSLoadFormBufferHelper
{
    unsigned int __thiscall ReadFormIdentifier();
    void __thiscall ReadTypedData(void*, unsigned int);
};

TESForm* __cdecl _ref_004839c0(unsigned int formID);
extern void* _DAT_01183028;

struct FUN_0083fbe0_Class
{
    void __thiscall ExtraInfoGeneralTopic_Data_LoadGame(BGSLoadGameBuffer* buffer);
};

// @fnv 0x0083fbe0
// src: COMMUNITY 0x0083fbe0
void __thiscall FUN_0083fbe0_Class::ExtraInfoGeneralTopic_Data_LoadGame(BGSLoadGameBuffer* buffer)
{
    char string[500];

    reinterpret_cast<BGSLoadGameBufferLoadStringHelper*>(buffer)->LoadString(string);
    reinterpret_cast<Str6a70*>(this)->operator=(string);

    reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)->ReadTypedData(reinterpret_cast<char*>(this) + 0x08, 1);
    reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)->ReadTypedData(reinterpret_cast<char*>(this) + 0x24, 1);
    reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)->ReadTypedData(reinterpret_cast<char*>(this) + 0x25, 1);
    reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)->ReadTypedData(reinterpret_cast<char*>(this) + 0x09, 1);
    reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)->ReadTypedData(reinterpret_cast<char*>(this) + 0x0A, 1);

    *reinterpret_cast<TESQuest**>(reinterpret_cast<char*>(this) + 0x14) = dynamic_cast<TESQuest*>(
        _ref_004839c0(reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)->ReadFormIdentifier()));

    *reinterpret_cast<TESTopic**>(reinterpret_cast<char*>(this) + 0x28) = dynamic_cast<TESTopic*>(
        _ref_004839c0(reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)->ReadFormIdentifier()));

    *reinterpret_cast<TESTopic**>(reinterpret_cast<char*>(this) + 0x1C) = dynamic_cast<TESTopic*>(
        _ref_004839c0(reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)->ReadFormIdentifier()));

    *reinterpret_cast<TESTopicInfo**>(reinterpret_cast<char*>(this) + 0x18) = dynamic_cast<TESTopicInfo*>(
        _ref_004839c0(reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)->ReadFormIdentifier()));
}

// FUN_00822440 - 0x00822440, 99 bytes.
//
// The constructor of the game class that owns
//   +0x00  BSSimpleArray<void*, 0xEAA>   (vftable 0x0107b84c, ctor 0x00822600,
//                                          dtor 0x00822630)
//   +0x10  BSSimpleArray<int, 0xEAA>     (vftable 0x01016024, ctor 0x00438660,
//                                          dtor 0x00438690)
//   +0x20  int                           (zeroed by the constructor)
//
// The class itself is NOT polymorphic: the original's constructor never writes
// a vftable pointer of its own, the vtable at +0x00 comes from the
// BSSimpleArray<void*> MEMBER constructor at 0x00822600.  The matching
// destructor is 0x008224b0; it destroys the members in reverse order
// (0x00438690 at +0x10 first, then 0x00822630 at +0x00).
//
// The original's code:
//   push ebp / mov ebp,esp / push -1 / push __ehhandler$ / mov eax,fs:[0] /
//   push eax / push ecx / mov eax,[__security_cookie] / xor eax,ebp /
//   push eax / lea eax,[ebp-0xc] / mov fs:[0],eax
//   mov  [ebp-0x10],ecx                 ; the /Od home slot of `this`
//   mov  ecx,[ebp-0x10] / call 0x822600 ; BSSimpleArray<void*> ctor
//   mov  dword ptr [ebp-4],0           ; EH state variable
//   mov  ecx,[ebp-0x10] / add ecx,0x10 / call 0x438660 ; BSSimpleArray<int> ctor
//   mov  eax,[ebp-0x10] / mov dword ptr [eax+0x20],0
//   mov  dword ptr [ebp-4],-1          ; EH state variable
//   mov  eax,[ebp-0x10] / mov ecx,[ebp-0xc] / mov fs:[0],ecx /
//   pop ecx / mov esp,ebp / pop ebp / ret
//
// The class name has to carry the FUN_00822440 tag (the constructor's mangled
// name is the only symbol the checker can find), so the destructor is DECLARED
// but never defined: an undefined destructor is never emitted into the object
// file, which keeps exactly ONE defined function symbol carrying the tag.

// Stand-in for BSSimpleArray<void*, 0xEAA>.
struct FnvSimpleArrayPtr
{
    void** m_ppVirtualMethodTable;
    void* m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReservedSize;
    FnvSimpleArrayPtr();
    ~FnvSimpleArrayPtr();
};

// Stand-in for BSSimpleArray<int, 0xEAA>.
struct FnvSimpleArrayInt
{
    void** m_ppVirtualMethodTable;
    int* m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReservedSize;
    FnvSimpleArrayInt();
    ~FnvSimpleArrayInt();
};

struct FUN_00822440_Class
{
    FnvSimpleArrayPtr m_arrPtr;  // +0x00
    FnvSimpleArrayInt m_arrInt;  // +0x10
    int m_unk20;                 // +0x20
    FUN_00822440_Class();
    ~FUN_00822440_Class();
};

// Constructs the object, default-initializing m_arrPtr and m_arrInt and setting m_unk20 to 0.
// @fnv 0x00822440
FUN_00822440_Class::FUN_00822440_Class() : m_arrPtr(), m_arrInt(), m_unk20(0)
{}

struct PrimaryBase_b5774
{
    virtual ~PrimaryBase_b5774();
    unsigned int unk04;
    unsigned int unk08;
};

struct SecondaryBase_b5774
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    ~SecondaryBase_b5774();
};

struct GlobalMgr_b5774
{
    bool TESDataHandler_GetClearingData();
};

extern GlobalMgr_b5774* DAT_011c3f2c;

struct Holder_b5774
{
    void Release();
};

class FUN_00825b60 : public PrimaryBase_b5774, public SecondaryBase_b5774
{
  public:
    Holder_b5774* m_20;
    virtual ~FUN_00825b60();
    void Cleanup();
};

// If the global manager check fails, releases m_20 when non-null and calls Cleanup.
// @fnv 0x00825b60
FUN_00825b60::~FUN_00825b60()
{
    if (!DAT_011c3f2c->TESDataHandler_GetClearingData())
    {
        if (m_20 != 0)
        {
            m_20->Release();
        }
        Cleanup();
    }
}

struct S_00825ea0_A
{
    unsigned char unk04;
    int unk08;
    S_00825ea0_A(unsigned char c);
    virtual ~S_00825ea0_A();
};
struct S_00825ea0_B
{
    unsigned char unk04;
    unsigned char unk05;
    int unk08;
    int unk0c;
    S_00825ea0_B();
    virtual ~S_00825ea0_B();
};
struct S_00825ea0_P
{
    int unk00;
    int unk04;
    S_00825ea0_P();
};
struct FUN_00825ea0 : S_00825ea0_A, S_00825ea0_B
{
    int unk1c;
    S_00825ea0_P unk20;
    FUN_00825ea0();
    virtual ~FUN_00825ea0();
};
// Initializes the base subobject with 0x33 and sets unk1c to 0.
// @fnv 0x00825ea0
FUN_00825ea0::FUN_00825ea0() : S_00825ea0_A(0x33)
{
    unk1c = 0;
}

struct DataHandler
{
    TESSound* LookupSound(unsigned int formID);
};
extern DataHandler* g_dataHandler;

int CopySoundPath(char* dest, unsigned int size, const char* src);

// @fnv 0x0082d150
bool GetSoundPathAndFlags(unsigned int formID, char* path, unsigned int* flags, TESSound** outSound)
{
    TESSound* sound = g_dataHandler->LookupSound(formID);
    if (sound && sound->TESSound_GetFilename() && path)
    {
        CopySoundPath(path, 0x104, sound->TESSound_GetFilename());
    }
    else
    {
        return false;
    }
    if (sound->CopyBig().iFlags & 0x40)
    {
        *flags |= 1;
        *flags &= ~2;
    }
    else if (!(*flags & 1) && !(*flags & 2))
    {
        *flags |= 2;
        *flags &= ~1;
    }
    if (sound->CopyBig().iFlags & 1)
    {
        *flags |= 0x40;
    }
    if (sound->CopyBig().iFlags & 0x800)
    {
        *flags |= 0x8000000;
    }
    *flags |= TESSound::GetPlaybackFlags(sound->CopyBig().iFlags);
    *outSound = sound;
    return true;
}

struct Base_82efb0
{
    virtual ~Base_82efb0();
};

struct FUN_0082ef50 : public Base_82efb0
{
    void RemoveAll();
    virtual ~FUN_0082ef50();
};

// @fnv 0x0082ef50
FUN_0082ef50::~FUN_0082ef50()
{
    RemoveAll();
}

extern "C" void __cdecl FUN_00406d30(char*, unsigned int, const char*);
extern "C" void* __cdecl FUN_00afdf20(const char*, int, int, int);
struct FNVHandle
{
    virtual ~FNVHandle();
    bool TESAnimGroup_GetDecal();
};
struct FUN_0082f240
{
    FUN_0082f240();
    virtual ~FUN_0082f240();
};
struct FUN_0044fae0
{
    FUN_0044fae0();
    ~FUN_0044fae0();
    unsigned int state00;
    unsigned int state04;
    unsigned int state08;
    unsigned int state0c;
    unsigned int state10;
    unsigned int state14;
    unsigned int state18;
    unsigned int state1c;
    unsigned int state20;
};
struct FUN_0082f010 : FUN_0082f240
{
    char path[0x104];
    FNVHandle* handle;
    FUN_0044fae0 lock;
    unsigned __int64 counter;
    FUN_0082f010(const char* pathName);
    virtual ~FUN_0082f010();
};

// @fnv 0x0082f010
FUN_0082f010::FUN_0082f010(const char* pathName)
{
    counter = 0;
    FUN_00406d30(path, 0x104, pathName);
    handle = (FNVHandle*)FUN_00afdf20(path, 0, 0x4000, 8);
    if (!handle || !handle->TESAnimGroup_GetDecal())
    {
        if (handle)
        {
            delete handle;
        }
        handle = 0;
    }
}

extern int DAT_010a2480;
struct ProbeTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14(int a, int b);
    bool TESAnimGroup_GetDecal();
};
class FUN_0082f310_cls
{
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    ProbeTarget* m_108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    __int64 m_128;
    __int64 m_130;

  public:
    int CBSAStream_Seek(__int64 value);
};
// Validates value against m_128 and the m_108 probe, then stores it in m_130 and calls m_108->v14(value, DAT_010a2480); returns 1 on failure, 0 on success.
// @fnv 0x0082f310
// src: COMMUNITY 0x0082f310
int FUN_0082f310_cls::CBSAStream_Seek(__int64 value)
{
    if (value < 0 || value > this->m_128 || this->m_108 == 0 || this->m_108->TESAnimGroup_GetDecal() == 0)
    {
        return 1;
    }
    else
    {
        this->m_130 = value;
        this->m_108->v14((int)value, DAT_010a2480);
        return 0;
    }
}

struct StreamLock
{
    void* m_cs;
    StreamLock(void* cs);
    ~StreamLock();
};

struct StreamFile
{
    bool IsValid();
    unsigned int Read(void* buffer, unsigned int size);
};

struct ArchiveStream
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    StreamFile* file;
    int lock;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    __int64 size;
    __int64 pos;
    int CBSAStream_Read(void* buffer, unsigned int count, int unused, unsigned int* bytesRead);
};

// @fnv 0x0082f3c0
// src: COMMUNITY 0x0082f3c0
int ArchiveStream::CBSAStream_Read(void* buffer, unsigned int count, int unused, unsigned int* bytesRead)
{
    StreamLock guard(&lock);
    if (!file || !file->IsValid())
        return 1;
    unsigned int uiToAdvance;
    if (pos + count > size)
        uiToAdvance = (unsigned int)(size - pos);
    else
        uiToAdvance = count;
    *bytesRead = file->Read(buffer, count);
    pos += uiToAdvance;
    return 0;
}

// FUN_0082f6c0 @ 0x0082f6c0 (size 150)
// Base-object destructor of a thread-like class: clears the "running" flag bit,
// signals the object at +0x34, waits for the worker thread to leave, closes its
// handle, then runs the base class destructor.

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);

void __cdecl BSSleep(int milliseconds);

struct FUN_00aa63c0
{
    virtual ~FUN_00aa63c0();
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
};

struct FUN_0082f6c0 : FUN_00aa63c0
{
    void* unk30;
    int unk34;
    int unk38;
    unsigned int unk3C;

    void CopyAndSleep(void* arg);
    virtual ~FUN_0082f6c0();
};

// Clears the low bit of unk3C, calls CopyAndSleep on unk34, waits while bit 1 of unk3C is set, then closes unk30.
// @fnv 0x0082f6c0
FUN_0082f6c0::~FUN_0082f6c0()
{
    unk3C &= 0xFFFFFFFE;
    CopyAndSleep(&unk34);
    while (unk3C & 2)
        BSSleep(10);
    CloseHandle(unk30);
}

extern unsigned int DAT_011dd1f4;

void __cdecl FormHeapFreeAndLog_00401030(unsigned int p);

struct FUN_0082f9c0_obj
{
    virtual int unk00(int a);
};

// @fnv 0x0082f9c0
// src: COMMUNITY 0x0082f9c0
void __cdecl FalloutAudioMedia_Shutdown()
{
    unsigned int a = DAT_011dd1f4;
    unsigned int b_2 = a;
    unsigned int c7 = b_2;
    unsigned int r_2;
    unsigned int s;
    if (c7 != 0)
    {
        if (*(unsigned int*)(c7 - 4) != 0)
        {
            r_2 = (unsigned int)((FUN_0082f9c0_obj*)b_2)->unk00(3);
        }
        else
        {
            FormHeapFreeAndLog_00401030(c7 - 4);
            r_2 = 0;
        }
        s = r_2;
    }
    else
    {
        s = 0;
    }
    DAT_011dd1f4 = 0;
}

// FUN_00831f70: stdcall stub taking one stack argument and returning 0.
// @fnv 0x00831f70
// src: GUESS 0x00831f70 (confidence: high)
int __stdcall Runtime_ReturnZero(int unused)
{
    return 0;
}

namespace weapon_audio {

struct Entry
{
    BSSoundHandle ch0;
    BSSoundHandle ch1;
    void* f18;
    unsigned int f1c;
    float f20;
};
struct Weap
{
    TESSound* __thiscall TESObjectWEAP_GetAttackSound(bool v);
    void* __thiscall GetPointerByFlag(bool v);
    TESSound* __thiscall GetValueByFlag(bool v);
};
struct VObj1d0
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void* VCall1d0();
};
struct VObj148
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void* VCall148();
};
struct ProcResult
{
    bool __thiscall HasEffect(int v);
};
struct Cell
{
    bool __thiscall FUN_00425fd0();
    bool __thiscall FUN_00454b10();
};
struct Player
{
    Cell* __thiscall FUN_008d6f30();
    VObj148* __thiscall FUN_008d8520();
};
struct ListObj
{
    LocalVec3* __thiscall NiAVObject_GetWorldTranslate();
};
struct SettingObj
{
    float* __thiscall Setting_Float_00403e20();
};
bool __cdecl ImpactMixer_GetGunshotsInitialized();
bool __fastcall PlayerCharacter_IsActually3rdPerson(void* p);
unsigned int __cdecl Cmd_GetSessionTime_Execute();
bool __cdecl FUN_0082eca0(void* snd, LocalVec3 pos, float v);
extern Player* DAT_011dea3c;
extern LocalVec3 DAT_011f426c;
extern const float DAT_01016970;
extern SettingObj DAT_011dd008;
extern SettingObj DAT_011dd034;
extern SettingObj DAT_011dd0ac;
extern SettingObj DAT_011dcff4;
extern Entry DAT_011dd9e8[20];
// @fnv 0x0083ac30
void __cdecl PlayWeaponSound(Weap* apWeapon, VObj1d0* apSource, ListObj* apListObj, bool a3)
{
    if (!ImpactMixer_GetGunshotsInitialized())
        return;
    BSSoundHandle bobj24;
    BSSoundHandle iobj48;
    LocalVec3 jvec = DAT_011f426c;
    bool ib15 = false;
    int iflags = 0;
    bool kb52 = !PlayerCharacter_IsActually3rdPerson(DAT_011dea3c);
    bool b83d = false;
    ::NiPoint3 cpt;
    float ef60 = DAT_01016970;
    Entry* aentry140 = 0;
    Entry* mentry3c = 0;
    Entry* tentry64 = 0;
    Entry* sentry58 = 0;
    bool ab51 = true;
    float cf38 = 1.0f;
    float yf50 = 1.0f;
    float if68 = 1.0f;
    float cf4c = 1.0f;
    unsigned char gb31 = 0;
    unsigned char qb75 = 0;
    unsigned char cg59 = 0;
    unsigned char sb0d = 0;
    if (DAT_011dea3c->FUN_008d6f30() != 0)
    {
        if (DAT_011dea3c->FUN_008d6f30()->FUN_00425fd0())
        {
            if (!DAT_011dea3c->FUN_008d6f30()->FUN_00454b10())
            {
                cf38 = *DAT_011dd008.Setting_Float_00403e20();
                if68 = *DAT_011dd034.Setting_Float_00403e20();
                yf50 = *DAT_011dd0ac.Setting_Float_00403e20();
                cf4c = *DAT_011dcff4.Setting_Float_00403e20();
            }
        }
    }
    if (a3)
    {
        iflags = iflags | 0x200000;
        if (DAT_011dea3c->FUN_008d8520() != 0)
        {
            if (DAT_011dea3c->FUN_008d8520()->VCall148() != 0)
            {
                ProcResult* res84 = (ProcResult*)DAT_011dea3c->FUN_008d8520()->VCall148();
                if (res84 != 0)
                {
                    if (res84->HasEffect(11) || res84->HasEffect(16))
                    {
                        b83d = true;
                    }
                }
            }
        }
    }
    if (apWeapon != 0)
    {
        if (a3)
        {
            if (apWeapon->GetPointerByFlag(false) != 0)
                ib15 = true;
        }
        if (ib15)
        {
            iflags = 0x20181;
        }
        else if (a3 && kb52)
        {
            iflags = 0x60182;
        }
        else
        {
            iflags = 0x20182;
        }
        if (!a3 && apListObj != 0)
        {
            // Use the shared point layout for the original trivial 12-byte copy.
            reinterpret_cast<::NiPoint3&>(jvec) = reinterpret_cast<const ::NiPoint3&>(*apListObj->NiAVObject_GetWorldTranslate());
        }
        else if (apSource->VCall1d0() != 0)
        {
            reinterpret_cast<::NiPoint3&>(jvec) =
                reinterpret_cast<const ::NiPoint3&>(*((ListObj*)apSource->VCall1d0())->NiAVObject_GetWorldTranslate());
        }
        if (apWeapon->TESObjectWEAP_GetAttackSound(b83d) != 0)
        {
            TESSound* sndA = 0;
            TESSound* sndB = 0;
            if (ib15)
            {
                sndA = (TESSound*)apWeapon->GetPointerByFlag(b83d);
            }
            else
            {
                sndA = apWeapon->TESObjectWEAP_GetAttackSound(b83d);
                sndB = apWeapon->GetValueByFlag(b83d);
            }
            bool a86 = FUN_0082eca0(sndA, jvec, yf50);
            bool b85 = FUN_0082eca0(sndB, jvec, cf4c);
            if (!a86 && !b85)
                return;
            if (!a86)
                sndA = 0;
            if (!b85)
                sndB = 0;
            // The audio header still names the old point type; use the shared return layout.
            cpt = jvec -
                  (BSAudio::BSAudio_QInstance()->*reinterpret_cast<::NiPoint3 (BSAudio::*)()>(&BSAudio::BSAudio_GetListenerPosition))();
            ef60 = cpt.x * cpt.x + cpt.y * cpt.y + cpt.z * cpt.z;
            int ai;
            for (ai = 0; ai < 20; ai++)
            {
                if (DAT_011dd9e8[ai].f18 == apSource)
                {
                    sentry58 = &DAT_011dd9e8[ai];
                    if (!a3)
                        break;
                }
                if (mentry3c == 0)
                {
                    mentry3c = &DAT_011dd9e8[ai];
                }
                else if (DAT_011dd9e8[ai].f1c <= mentry3c->f1c)
                {
                    mentry3c = &DAT_011dd9e8[ai];
                }
                if (!a3 || DAT_011dd9e8[ai].f18 == DAT_011dea3c)
                    continue;
                if (tentry64 == 0)
                {
                    tentry64 = &DAT_011dd9e8[ai];
                }
                else if (tentry64->f20 < DAT_011dd9e8[ai].f20 && ef60 < DAT_011dd9e8[ai].f20)
                {
                    tentry64 = &DAT_011dd9e8[ai];
                }
            }
            if (mentry3c != 0)
                ab51 = mentry3c->ch0.IsValid();
            if (mentry3c != 0 && !ab51)
            {
                aentry140 = mentry3c;
                mentry3c->f18 = apSource;
                mentry3c->f1c = Cmd_GetSessionTime_Execute();
                mentry3c->f20 = ef60;
            }
            else if (sentry58 != 0)
            {
                aentry140 = sentry58;
                sentry58->f1c = Cmd_GetSessionTime_Execute();
                sentry58->f20 = ef60;
            }
            else if (tentry64 != 0)
            {
                aentry140 = tentry64;
                tentry64->f18 = apSource;
                tentry64->f1c = Cmd_GetSessionTime_Execute();
                tentry64->f20 = ef60;
            }
            if (aentry140 != 0)
            {
                if (sndA != 0)
                {
                    aentry140->ch0.SetVolume(0.0f);
                    aentry140->ch0.Stop();
                    // Adapt the legacy BSAudio return declaration to the shared 12-byte handle.
                    aentry140->ch0 =
                        (BSAudio::BSAudio_QInstance()->*reinterpret_cast<BSSoundHandle (BSAudio::*)(const char*, unsigned int, unsigned int)>(
                            static_cast<BSSoundHandle (BSAudio::*)(const char*, unsigned int, unsigned int)>(&BSAudio::BSAudio_GetSoundHandleByFilename)))(
                                sndA->TESSound_GetFilename(), (unsigned int)iflags, (unsigned int)sndA);
                    gb31 = (unsigned char)sndA->GetByteAtOffset44();
                    cg59 = sndA->GetField45();
                }
                if (sndB != 0)
                {
                    aentry140->ch1.SetVolume(0.0f);
                    aentry140->ch1.Stop();
                    aentry140->ch1 =
                        (BSAudio::BSAudio_QInstance()->*reinterpret_cast<BSSoundHandle (BSAudio::*)(const char*, unsigned int, unsigned int)>(
                            static_cast<BSSoundHandle (BSAudio::*)(const char*, unsigned int, unsigned int)>(&BSAudio::BSAudio_GetSoundHandleByFilename)))(
                                sndB->TESSound_GetFilename(), (unsigned int)iflags, (unsigned int)sndB);
                    qb75 = (unsigned char)sndB->GetByteAtOffset44();
                    sb0d = sndB->GetField45();
                }
                if (!a3 && apListObj != 0)
                {
                    aentry140->ch0.SetObjectToFollow(reinterpret_cast<NiAVObject*>(apListObj));
                    aentry140->ch1.SetObjectToFollow(reinterpret_cast<NiAVObject*>(apListObj));
                }
                else if (apSource->VCall1d0() != 0)
                {
                    if (!(a3 && kb52))
                    {
                        aentry140->ch0.SetObjectToFollow(reinterpret_cast<NiAVObject*>(apSource->VCall1d0()));
                        aentry140->ch1.SetObjectToFollow(reinterpret_cast<NiAVObject*>(apSource->VCall1d0()));
                    }
                }
                if (sndA != 0)
                {
                    aentry140->ch0.SetPriority(1);
                    aentry140->ch0.SetPosition(jvec.x, jvec.y, jvec.z);
                    aentry140->ch0.SetVolume(cf38);
                    aentry140->ch0.Play(false);
                }
                if (sndB != 0)
                {
                    aentry140->ch1.SetPriority(1);
                    aentry140->ch1.SetPosition(jvec.x, jvec.y, jvec.z);
                    aentry140->ch1.SetVolume(if68);
                    aentry140->ch1.Play(false);
                }
                if (!ib15)
                {
                    aentry140->ch0.SetMinMax((float)gb31 * 5.0, (float)cg59 * yf50 * 100.0);
                    aentry140->ch1.SetMinMax((float)gb31 * 5.0, (float)cg59 * yf50 * 100.0);
                    aentry140->ch0.SetPosition(jvec.x, jvec.y, jvec.z);
                    aentry140->ch1.SetPosition(jvec.x, jvec.y, jvec.z);
                }
            }
        }
    }
}

} // namespace weapon_audio

class B3B6B0MapBase
{
  public:
    virtual ~B3B6B0MapBase();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_0083b6b0 : public B3B6B0MapBase
{
  public:
    virtual ~FUN_0083b6b0();
};

// @fnv 0x0083b6b0
FUN_0083b6b0::~FUN_0083b6b0()
{
    RemoveAll();
}

namespace fnv_0083d130 {
struct S_0083d130_Str
{
    const char* __thiscall Modelloader_GetReferencedThis();
};
struct S_0083d130_Obj
{
    S_0083d130_Str* ref_006815c0();
    S_0083d130_Str* __thiscall TESDataHandler_GetWorldSpaceList();
};
struct S_0083d130_Node
{
    S_0083d130_Obj** ref_006815c0();
};
unsigned int __cdecl BSstrlen(const char* s);
bool __fastcall FUN_008256d0(S_0083d130_Node*);
S_0083d130_Node* __fastcall FUN_00726070(S_0083d130_Node*);

struct S_0083d130_Class : S_0083d130_Node
{
    void ProcessNodeChain();
};

// @fnv 0x0083d130
void S_0083d130_Class::ProcessNodeChain()
{
    S_0083d130_Node* node = this;
    while (node && !FUN_008256d0(node))
    {
        if ((*node->ref_006815c0())->ref_006815c0()->Modelloader_GetReferencedThis())
        {
            if (BSstrlen((*node->ref_006815c0())->ref_006815c0()->Modelloader_GetReferencedThis()) > 1)
            {
                BSAudio::BSAudio_QInstance()->Precache_00ad8100((unsigned int)(*node->ref_006815c0())->TESDataHandler_GetWorldSpaceList()->Modelloader_GetReferencedThis(), 0x20100001, 0);
            }
        }
        node = FUN_00726070(node);
    }
}
}  // namespace fnv_0083d130

struct FUN_0083da30_cls
{
    int m_00;

    int ApplyMaskedOffset(int aValue);
};

// @fnv 0x0083da30
int FUN_0083da30_cls::ApplyMaskedOffset(int aValue)
{
    return (((m_00 != 0) ? -1 : 0) & aValue) + (unsigned int)m_00;
}

struct EffectTime
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    float time38;
    unsigned int unk3C, unk40, unk44;
    float time48;
    void AdvanceParticleTimes(float);
};
struct EffectHandle
{
    EffectTime* Modelloader_GetReferencedThis();
};
struct SpellTimes
{
    float FUN_009a7c40();
    float NiPSysSpawnModifier_GetLifeSpan();
};
struct EffectCollection
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int FUN_0044ddc0();
    EffectHandle* BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
};
float BSMAX_00404010(float, float);
struct FUN_008216c0_shell
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    bool reset;
    unsigned int unk2C;
    SpellTimes* spell;
    float time;
    EffectCollection effects;
    EffectHandle active;
    void UpdateEffectTimes();
};
// Computes a time from the active effect's times (or zero if reset), scales it by the spell's times, and applies it to every effect in the collection.
// @fnv 0x008216c0
void FUN_008216c0_shell::UpdateEffectTimes()
{
    float value = 0.0f;
    if (active.Modelloader_GetReferencedThis())
        value = BSMAX_00404010(active.Modelloader_GetReferencedThis()->time38, active.Modelloader_GetReferencedThis()->time48);
    if (reset)
    {
        value = 0.0f;
        active.Modelloader_GetReferencedThis()->time38 = 0.0f;
        active.Modelloader_GetReferencedThis()->time48 = 0.0f;
    }
    if (value < spell->FUN_009a7c40())
        time = spell->NiPSysSpawnModifier_GetLifeSpan() * (value / spell->FUN_009a7c40());
    else
        time = spell->NiPSysSpawnModifier_GetLifeSpan();
    for (unsigned int i = 0; i < effects.FUN_0044ddc0(); ++i)
        effects.BSSimpleArray_NiAVObject_1024_GetAt(i)->Modelloader_GetReferencedThis()->AdvanceParticleTimes(time);
}

// Minimal declarations for the process list and its polymorphic entries.

#include "../../include/MobileObjectProcessArray.h"
struct ProcessRegistry
{
    MobileObjectProcessArray* FUN_00717e50();
};
extern ProcessRegistry DAT_011e0e80;
extern Actor* g_thePlayer;
struct CasterUpdate : BE, BCaster_S
{
    void UpdateCasters();
};

// Iterates the process list's groups 0 and 1, calling FUN_008c4f10 on actors and UpdateCaster on magic projectiles, then updates the player.
// @fnv 0x00825c20
void CasterUpdate::UpdateCasters()
{
    MobileObjectProcessArray* pProcessList = DAT_011e0e80.FUN_00717e50();
    for (unsigned int i = 0; i < pProcessList->ProcessArray_GetProcessLevelTail(0); ++i)
    {
        MagicProjectile* object;
        MobileObject* pMobileObject = pProcessList->ProcessArray_GetItem(i);
        Actor* actor = pMobileObject && pMobileObject->IsActor() ? static_cast<Actor*>(pMobileObject) : 0;
        object =
            pMobileObject && pMobileObject->IsProjectile() ? dynamic_cast<MagicProjectile*>(pMobileObject) : 0;
        if (actor)
            actor->Actor_CheckDeletedCaster(this);
        else if (object)
            object->UpdateCaster(this);
    }
    for (unsigned int j = pProcessList->ProcessArray_GetProcessLevelHead(1); j < pProcessList->ProcessArray_GetProcessLevelTail(1); ++j)
    {
        MobileObject* pMobileObject2 = pProcessList->ProcessArray_GetItem(j);
        Actor* actor2 = pMobileObject2 && pMobileObject2->IsActor() ? static_cast<Actor*>(pMobileObject2) : 0;
        MagicProjectile* pMagicProjectile2 =
            pMobileObject2 && pMobileObject2->IsProjectile() ? dynamic_cast<MagicProjectile*>(pMobileObject2) : 0;
        if (actor2)
            actor2->Actor_CheckDeletedCaster(this);
        else if (pMagicProjectile2)
            pMagicProjectile2->UpdateCaster(this);
    }
    if (g_thePlayer)
        g_thePlayer->Actor_CheckDeletedCaster(this);
}

namespace fnv_0082cf80 {
// Constructs the object by forwarding the caster, item and effect pointers to the ActiveEffect base constructor.
// @fnv 0x0082cf80
FUN_0082cf80::FUN_0082cf80(MagicCaster* pkCaster, MagicItem* pkItem, EffectItem* pkEffect)
    : ActiveEffect(pkCaster, pkItem, pkEffect)
{}
}  // namespace fnv_0082cf80


// The shared TESSound declaration does not expose the accessor at 0x0082d680.
unsigned short __fastcall GetSoundStaticAttenuation(TESSound* sound);

// @fnv 0x0082d400
unsigned int __cdecl ApplySoundFormToGameSound(BSSoundHandle* apSound, void* apForm, unsigned int* apFlags)
{
    unsigned int uiMax2;
    unsigned int uiMin;
    TESSound* SoundAssetTmp;
    unsigned int uiFlags;

    if (!apForm)
        return 0;

    uiFlags = 0;
    SoundAssetTmp = (TESSound*)apForm;
    apSound->SetStaticAttenuation(GetSoundStaticAttenuation(SoundAssetTmp));
    uiMin = (unsigned char)SoundAssetTmp->GetByteAtOffset44();
    uiMax2 = SoundAssetTmp->GetField45();
    if (!uiMin)
        uiMin = 0xe;
    if (!uiMax2)
        uiMax2 = 0x3c;
    if (SoundAssetTmp->GetHighByteOfField4E() || SoundAssetTmp->GetEndTime_0082d700())
        apSound->SetTimeConstraints(SoundAssetTmp->GetHighByteOfField4E(), SoundAssetTmp->GetEndTime_0082d700());
    apSound->SetMinMax(uiMin * 5.0, uiMax2 * 100.0);
    apSound->SetAttenuationCurve(SoundAssetTmp->GetShortAt(0), SoundAssetTmp->GetShortAt(1), SoundAssetTmp->GetShortAt(2), SoundAssetTmp->GetShortAt(3),
                          SoundAssetTmp->GetShortAt(4));
    apSound->SetReverbAttenuation(SoundAssetTmp->GetShortAtOffset5A());
    apSound->SetPriority((unsigned char)SoundAssetTmp->GetPriority_0082d720());
    if (SoundAssetTmp->CopyBig().iFlags & 1)
    {
        uiFlags |= 0x40;
        apSound->SetFrequencyVariance((unsigned char)SoundAssetTmp->CopyBig().m_cPitchAdjustment);
    }
    if (SoundAssetTmp->CopyBig().iFlags & 0x800)
        uiFlags |= 0x8000000;
    if (apFlags)
    {
        if (SoundAssetTmp->CopyBig().iFlags & 0x1000)
            *apFlags |= 1;
        if (SoundAssetTmp->CopyBig().iFlags & 0x2000)
            *apFlags |= 2;
    }
    uiFlags |= TESSound::GetPlaybackFlags(SoundAssetTmp->CopyBig().iFlags);
    return uiFlags;
}

class Thread82F
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual unsigned int GetPosition();

    bool IsRunning();
};

// If the thread is running, stores its position in (*reinterpret_cast<unsigned __int64*>(reinterpret_cast<char*>(this) + 0x128)) and in puiPosition and returns it; otherwise writes 0 and returns 0.
// @fnv 0x0082f570
unsigned __int64 CBSAStream::GetStreamPosition(unsigned __int64* puiPosition)
{
    if (!(*reinterpret_cast<Thread82F**>(reinterpret_cast<char*>(this) + 0x108)) || !(*reinterpret_cast<Thread82F**>(reinterpret_cast<char*>(this) + 0x108))->IsRunning())
    {
        *puiPosition = 0;
        return 0;
    }
    (*reinterpret_cast<unsigned __int64*>(reinterpret_cast<char*>(this) + 0x128)) = (*reinterpret_cast<Thread82F**>(reinterpret_cast<char*>(this) + 0x108))->GetPosition();
    *puiPosition = (*reinterpret_cast<unsigned __int64*>(reinterpret_cast<char*>(this) + 0x128));
    return (*reinterpret_cast<unsigned __int64*>(reinterpret_cast<char*>(this) + 0x128));
}

struct AudGuid
{
    unsigned long d0;
    unsigned long d1;
    unsigned long d2;
    unsigned long d3;
};

extern "C" __declspec(dllimport) long __stdcall CoInitializeEx(void* reserved, unsigned long flags);

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* handle, unsigned long ms);

struct IAudUnk
{
    virtual long __stdcall QueryInterface(const AudGuid& iid, void** out);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct IAudGraph : IAudUnk
{
    virtual long __stdcall AddFilter(IAudUnk* filter, const wchar_t* name);
};
struct IAudBuilder : IAudUnk
{
    virtual long __stdcall v0C();
    virtual long __stdcall v10();
    virtual long __stdcall v14();
    virtual long __stdcall v18();
    virtual long __stdcall v1C();
    virtual long __stdcall v20();
    virtual long __stdcall v24();
    virtual long __stdcall v28();
    virtual long __stdcall v2C();
    virtual long __stdcall Render(IAudUnk* pin);
};
struct IAudDispatch : IAudUnk
{
    virtual long __stdcall d0C();
    virtual long __stdcall d10();
    virtual long __stdcall d14();
    virtual long __stdcall d18();
};
struct IAudBasicAudio : IAudDispatch
{
    virtual long __stdcall put_Volume(long volume);
};
struct IAudControl : IAudDispatch
{
    virtual long __stdcall Run();
    virtual long __stdcall Pause();
    virtual long __stdcall Stop();
};
struct IAudPosition : IAudDispatch
{
    virtual long __stdcall get_Duration(double* len);
    virtual long __stdcall put_CurrentPosition(double t);
    virtual long __stdcall get_CurrentPosition(double* t);
};
struct IAudEvent : IAudDispatch
{
    virtual long __stdcall e1C();
    virtual long __stdcall GetEvent(long* code, long* p1, long* p2, long timeout);
    virtual long __stdcall e24();
    virtual long __stdcall e28();
    virtual long __stdcall e2C();
    virtual long __stdcall FreeEventParams(long code, long p1, long p2);
};

struct AudMediaType
{
    AudGuid majortype;
    AudGuid subtype;
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
    AudMediaType();
    ~AudMediaType();
};

struct AudReader
{
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
    AudReader(char* path);
    virtual ~AudReader();
    bool IsOpen();
};

struct AudPinBase
{
    virtual void p00();
    int unk04;
    int unk08;
};
struct AudPin : AudPinBase, IAudUnk
{
};

struct AudFilterBase
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0C();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual AudPin* GetPin(int index);
    int unk04;
    int unk08;
};
struct AudFilter : AudFilterBase, IAudUnk
{
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
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    AudFilter(AudReader* reader, AudMediaType* mt, long* hr);
};

struct AudSetting
{
    int* Get();
};
struct AudTimer
{
    unsigned int GetTime();
    bool IsPaused();
    void Reset();
};
AudTimer* __cdecl AudGetTimer();
unsigned int __cdecl AudMin(unsigned int a, unsigned int b);
void __cdecl AudLock();
void __cdecl AudUnlock();
void __cdecl AudStrCpy(char* dst, unsigned int size, const char* src);
void __cdecl AudPrint(const char* fmt, ...);
int __cdecl AudStrStr(char* s, const char* sub);
float __cdecl AudTargetVolume(int type, float value);
float __cdecl AudToDecibel(float value);

extern AudSetting DAT_011dcfd4;
extern int DAT_011dd370;
extern double DAT_01032980;
extern void* DAT_011dd3b0;
extern unsigned char DAT_011dd312;
extern AudGuid DAT_0107cae8;
extern AudGuid DAT_0107caf8;
extern AudGuid DAT_0107cb18;
extern AudGuid DAT_01093c0c;
extern AudGuid DAT_01093b5c;
extern AudGuid DAT_0107cad8;
extern AudGuid DAT_0107caa8;
extern AudGuid DAT_0107cac8;
extern AudGuid DAT_0107cab8;

extern float DAT_011dd300;
extern float DAT_011dd304;
extern float DAT_011dd308;
extern float DAT_011dd30c;
extern char DAT_011dd310;
extern int DAT_011dd314;
extern unsigned int DAT_011dd318;
extern unsigned int DAT_011dd31c;
extern unsigned int DAT_011dd320;
extern unsigned int DAT_011dd324;
extern unsigned int DAT_011dd328;
extern unsigned int DAT_011dd32c;
extern unsigned int DAT_011dd330;
extern int DAT_011dd334;
extern char DAT_011dd0f0[];

extern float DAT_011dd338;
extern float DAT_011dd33c;
extern float DAT_011dd340;
extern float DAT_011dd344;
extern char DAT_011dd311;
extern int DAT_011dd348;
extern unsigned int DAT_011dd34c;
extern unsigned int DAT_011dd350;
extern unsigned int DAT_011dd354;
extern unsigned int DAT_011dd358;
extern unsigned int DAT_011dd35c;
extern unsigned int DAT_011dd360;
extern unsigned int DAT_011dd364;
extern int DAT_011dd368;
extern char DAT_011dd1f8[];

// @fnv 0x00830b30
int __cdecl RunAudioChannel(int* param)
{
    unsigned int fadeTimeNow;
    unsigned int duration3;
    char flags;
    unsigned int position;
    IAudPosition* seeking;
    IAudEvent* events;
    unsigned int now;
    AudReader* reader4;
    int channel;
    int id2;
    char path8[0x104];
    float baseVolumeM;
    unsigned int startTime;
    IAudBasicAudio* audio3;
    AudFilter* filter6;
    double seconds;
    float targetParam3;
    IAudBuilder* builder3;
    IAudControl* controlTmp;
    unsigned int syncLimitTmp;
    bool ok4;
    float volumeA;
    unsigned int fadeEnd2;
    int curveType;
    IAudGraph* graphS;
    unsigned int totalLength2;

    channel = param[1];
    id2 = param[0];
    ok4 = true;
    now = 0;
    volumeA = 0.0f;
    baseVolumeM = 0.0f;
    targetParam3 = 0.0f;
    flags = 0;
    curveType = 9;
    startTime = 0;
    position = 0;
    duration3 = 0;
    totalLength2 = 0;
    fadeTimeNow = 0;
    fadeEnd2 = 0;

    syncLimitTmp = AudMin(500, *DAT_011dcfd4.Get() + 500);
    AudLock();
    DAT_011dd370 = DAT_011dd370 + 1;
    if ((channel == 0 && (id2 != DAT_011dd334 || (DAT_011dd310 & 1))) ||
        (channel == 1 && (id2 != DAT_011dd368 || (DAT_011dd311 & 1))))
    {
        ok4 = false;
    }
    now = AudGetTimer()->GetTime();
    if (channel == 0)
    {
        DAT_011dd300 = volumeA;
        DAT_011dd330 = now;
        DAT_011dd31c = position;
        DAT_011dd320 = duration3;
        DAT_011dd324 = totalLength2;
        baseVolumeM = DAT_011dd304;
        targetParam3 = DAT_011dd30c;
        flags = DAT_011dd310;
        curveType = DAT_011dd314;
        startTime = DAT_011dd318;
        fadeTimeNow = DAT_011dd328;
        fadeEnd2 = DAT_011dd32c;
        AudStrCpy(path8, 0x104, DAT_011dd0f0);
    }
    else
    {
        DAT_011dd338 = volumeA;
        DAT_011dd364 = now;
        DAT_011dd350 = position;
        DAT_011dd354 = duration3;
        DAT_011dd358 = totalLength2;
        baseVolumeM = DAT_011dd33c;
        targetParam3 = DAT_011dd344;
        flags = DAT_011dd311;
        curveType = DAT_011dd348;
        startTime = DAT_011dd34c;
        fadeTimeNow = DAT_011dd35c;
        fadeEnd2 = DAT_011dd360;
        AudStrCpy(path8, 0x104, DAT_011dd1f8);
    }
    AudUnlock();

    graphS = 0;
    builder3 = 0;
    audio3 = 0;
    reader4 = 0;
    filter6 = 0;
    seeking = 0;
    controlTmp = 0;
    events = 0;
    seconds = 0.0;

    reader4 = new AudReader(path8);
    if (!reader4->IsOpen())
    {
        AudPrint("FalloutAudioMedia: file not found");
        ok4 = false;
    }
    else
    {
        long hr = 0;
        AudMediaType mt;
        mt.majortype = DAT_0107cae8;
        if (AudStrStr(path8, ".mp3") != 0)
        {
            mt.subtype = DAT_0107caf8;
        }
        else
        {
            ok4 = false;
            AudPrint("FalloutAudioMedia: file format wrong %s", path8);
        }
        if (ok4)
        {
            filter6 = new AudFilter(reader4, &mt, &hr);
            filter6->AddRef();
            CoInitializeEx(0, 0);
            hr = CoCreateInstance(reinterpret_cast<const CLSID&>(DAT_0107cb18), 0, 1, reinterpret_cast<const IID&>(DAT_01093c0c), (void**)&graphS);
            if (hr < 0)
                ok4 = false;
            hr = graphS->AddFilter(filter6, 0);
            if (hr < 0)
                ok4 = false;
            hr = graphS->QueryInterface(DAT_01093b5c, (void**)&builder3);
            if (hr < 0)
                ok4 = false;
            IAudUnk* pin = filter6->GetPin(0);
            hr = builder3->Render(pin);
            if (hr < 0)
                ok4 = false;
            hr = builder3->QueryInterface(DAT_0107cad8, (void**)&audio3);
            if (hr < 0)
                ok4 = false;
            hr = graphS->QueryInterface(DAT_0107caa8, (void**)&controlTmp);
            if (hr < 0)
                ok4 = false;
            hr = builder3->QueryInterface(DAT_0107cac8, (void**)&seeking);
            if (hr < 0)
                ok4 = false;
            hr = builder3->QueryInterface(DAT_0107cab8, (void**)&events);
            if (hr < 0)
                ok4 = false;
        }
    }

    if (graphS != 0 && seeking != 0)
    {
        seeking->get_Duration(&seconds);
        totalLength2 = (unsigned int)(seconds * 1000.0);
    }
    else
    {
        totalLength2 = 0;
    }

    while (ok4)
    {
        long p1;
        float target;
        long p22;
        long codeC;
        WaitForSingleObject(DAT_011dd3b0, 100);
        AudLock();
        now = AudGetTimer()->GetTime();
        if (graphS != 0 && seeking != 0)
        {
            seeking->get_CurrentPosition(&seconds);
            position = (unsigned int)(seconds * 1000.0);
        }
        else
        {
            position = 0;
        }
        if (graphS != 0 && seeking != 0)
        {
            seeking->get_Duration(&seconds);
            duration3 = (unsigned int)(seconds * 1000.0);
        }
        else
        {
            duration3 = 0;
        }
        if (channel == 0)
        {
            DAT_011dd300 = volumeA;
            DAT_011dd330 = now;
            DAT_011dd31c = position;
            DAT_011dd320 = duration3;
            DAT_011dd324 = totalLength2;
            baseVolumeM = DAT_011dd304;
            targetParam3 = DAT_011dd30c;
            flags = DAT_011dd310;
            curveType = DAT_011dd314;
            startTime = DAT_011dd318;
            fadeTimeNow = DAT_011dd328;
            fadeEnd2 = DAT_011dd32c;
        }
        else
        {
            DAT_011dd338 = volumeA;
            DAT_011dd364 = now;
            DAT_011dd350 = position;
            DAT_011dd354 = duration3;
            DAT_011dd358 = totalLength2;
            baseVolumeM = DAT_011dd33c;
            targetParam3 = DAT_011dd344;
            flags = DAT_011dd311;
            curveType = DAT_011dd348;
            startTime = DAT_011dd34c;
            fadeTimeNow = DAT_011dd35c;
            fadeEnd2 = DAT_011dd360;
        }
        AudUnlock();

        target = (flags & 8) ? 0.0f : AudTargetVolume(curveType, targetParam3);
        if ((flags & 0x10) && now < fadeEnd2)
        {
            float fade = fadeTimeNow > 0 ? ((double)fadeEnd2 - (double)now) / (double)fadeTimeNow : 0.0;
            fade = fade < 1.0 ? fade : 1.0f;
            fade = fade > 0.0 ? fade : 0.0f;
            if (flags & 8)
            {
                volumeA = fade * baseVolumeM;
            }
            else
            {
                volumeA = (1.0f - fade) * (target - baseVolumeM) + baseVolumeM;
            }
        }
        else if (volumeA > target)
        {
            volumeA = volumeA - (double)0.05f;
            volumeA = volumeA > target ? volumeA : target;
        }
        else if (volumeA < target)
        {
            volumeA = volumeA + (double)0.05f;
            volumeA = volumeA < target ? volumeA : target;
        }
        if ((flags & 8) && volumeA < (double)0.01f)
        {
            ok4 = false;
        }
        if (audio3 != 0)
        {
            audio3->put_Volume(volumeA < DAT_01032980 ? -10000 : (int)(AudToDecibel(volumeA) * 2000.0));
        }
        if (startTime != 0)
        {
            unsigned int current3 = 0;
            if (graphS != 0 && seeking != 0)
            {
                seeking->get_CurrentPosition(&seconds);
                current3 = (unsigned int)(seconds * 1000.0);
            }
            else
            {
                current3 = 0;
            }
            unsigned int nowTime = AudGetTimer()->GetTime();
            unsigned int expected = nowTime - startTime;
            while (expected > duration3)
            {
                expected = expected - duration3;
            }
            if (nowTime < startTime)
            {
                expected = 0;
                AudPrint("FalloutAudioMedia Synch Error: correct position is negative %i %i", nowTime, startTime);
            }
            int drift = 0;
            if (current3 > expected)
            {
                drift = current3 - expected;
            }
            else
            {
                drift = expected - current3;
            }
            if (drift > syncLimitTmp)
            {
                if (drift < 80000 || current3 == 0)
                {
                    AudPrint("FalloutAudioMedia Synch: %i = abs(-/+ %i +/- %i)", drift, expected, current3);
                    expected = expected + 50;
                    if (graphS != 0 && seeking != 0)
                    {
                        seeking->put_CurrentPosition((double)expected / 1000.0);
                    }
                }
                else
                {
                    expected = current3;
                }
            }
        }
        if (flags & 2)
        {
            if (builder3 != 0 && controlTmp != 0)
            {
                controlTmp->Stop();
            }
        }
        else if ((flags & 4) || DAT_011dd312 || AudGetTimer()->IsPaused())
        {
            if (builder3 != 0 && controlTmp != 0)
            {
                controlTmp->Pause();
            }
        }
        else
        {
            if (seeking != 0 && controlTmp != 0)
            {
                controlTmp->Run();
            }
        }
        if (events != 0)
        {
            while (events->GetEvent(&codeC, &p1, &p22, 0) >= 0)
            {
                switch (codeC)
                {
                    break;
                case 1:
                case 2:
                case 3:
                    events->FreeEventParams(codeC, p1, p22);
                    if (flags & 0x20)
                    {
                        if (builder3 != 0 && controlTmp != 0)
                        {
                            controlTmp->Stop();
                        }
                        if (graphS != 0 && seeking != 0)
                        {
                            seeking->put_CurrentPosition(0.0);
                        }
                        if (!(flags & 2) && seeking != 0 && controlTmp != 0)
                        {
                            controlTmp->Run();
                        }
                    }
                    else
                    {
                        ok4 = false;
                    }
                    break;
                }
                events->FreeEventParams(codeC, p1, p22);
            }
        }
        else
        {
            ok4 = false;
        }
        AudLock();
        if ((channel == 0 && (id2 != DAT_011dd334 || (DAT_011dd310 & 1))) ||
            (channel == 1 && (id2 != DAT_011dd368 || (DAT_011dd311 & 1))))
        {
            ok4 = false;
        }
        AudUnlock();
    }

    AudLock();
    if (channel == 0 && id2 == DAT_011dd334)
    {
        DAT_011dd300 = 0.0f;
        DAT_011dd304 = 0.0f;
        DAT_011dd308 = 0.0f;
        DAT_011dd30c = 0.0f;
        DAT_011dd310 = 0;
        AudStrCpy(DAT_011dd0f0, 0x104, "NONE");
        DAT_011dd314 = 0;
        DAT_011dd318 = 0;
        DAT_011dd31c = 0;
        DAT_011dd320 = 0;
        DAT_011dd324 = 0;
        DAT_011dd328 = 0;
        DAT_011dd32c = 0;
        DAT_011dd330 = 0;
        DAT_011dd334 = 0;
    }
    else if (channel == 1 && id2 == DAT_011dd368)
    {
        DAT_011dd338 = 0.0f;
        DAT_011dd33c = 0.0f;
        DAT_011dd340 = 0.0f;
        DAT_011dd344 = 0.0f;
        DAT_011dd311 = 0;
        AudStrCpy(DAT_011dd1f8, 0x104, "NONE");
        DAT_011dd348 = 0;
        DAT_011dd34c = 0;
        DAT_011dd350 = 0;
        DAT_011dd354 = 0;
        DAT_011dd358 = 0;
        DAT_011dd35c = 0;
        DAT_011dd360 = 0;
        DAT_011dd364 = 0;
        DAT_011dd368 = 0;
    }
    DAT_011dd370 = DAT_011dd370 - 1;
    AudUnlock();

    if (events != 0)
    {
        events->Release();
        events = 0;
    }
    if (seeking != 0)
    {
        seeking->Release();
        seeking = 0;
    }
    if (controlTmp != 0)
    {
        controlTmp->Release();
        controlTmp = 0;
    }
    if (audio3 != 0)
    {
        audio3->Release();
        audio3 = 0;
    }
    if (builder3 != 0)
    {
        builder3->Release();
        builder3 = 0;
    }
    if (graphS != 0)
    {
        graphS->Release();
        graphS = 0;
    }
    if (filter6 != 0)
    {
        filter6->Release();
        filter6 = 0;
    }
    if (reader4 != 0)
    {
        delete reader4;
    }
    return 0;
}

struct FUN_00831f10_Target
{
    virtual void unk00();
    virtual void unk04();
    virtual void __stdcall unk08();
};
// @fnv 0x00831f10
void __stdcall CallVirtualOnContainedNode(char* a1)
{
    FUN_00831f10_Target* target = (FUN_00831f10_Target*)FUN_00726070((ContNode*)(a1 - 0xc));
    target->unk08();
}

struct SoundEntry
{
    TESSound* form;
};

struct SoundListNode
{
    SoundEntry** Data();
    SoundListNode* Next();
};

struct SoundQueue
{
    void SaveGame(BGSSaveFormBuffer* buffer);
};

struct SoundTimer
{
    SoundQueue* m_queue;
    int unk04;
    unsigned int m_uiStartTime;
    int m_fAnimationDuration;
    unsigned char m_flag10;
    unsigned char m_flag11;
    int unk14;
    SoundListNode m_kNode;
    void RadioEntry_Data_Save(BGSSaveFormBuffer* buffer);
};

// Writes elapsed time, timer fields, and queued sound forms to the buffer, patches the count, then saves the queue if present.
// @fnv 0x00836110
// src: COMMUNITY 0x00836110
void SoundTimer::RadioEntry_Data_Save(BGSSaveFormBuffer* buffer)
{
    int elapsed_2 = BSAudio::GetSingleton()->GetSynchTime() - m_uiStartTime;
    if (m_fAnimationDuration <= 0)
        elapsed_2 = 0;
    buffer->SaveData(&elapsed_2, 4u, 0);
    buffer->SaveData(&m_fAnimationDuration, 4u, 0);
    buffer->SaveData(&m_flag10, 1u, 0);
    buffer->SaveData(&m_flag11, 1u, 0);
    buffer->SaveData(&unk14, 4u, 0);
    int count = 0;
    unsigned int position = buffer->GetPos();
    SoundListNode* node3 = &m_kNode;
    while (node3)
    {
        SoundEntry* entry = *node3->Data();
        if (entry)
        {
            buffer->SerializeFormData(entry->form, 0);
            count++;
        }
        node3 = node3->Next();
    }
    buffer->SaveVariableSizedValue_00865ff0(count, position);
    bool hasQueue7 = (bool)(m_queue != 0);
    buffer->SaveData(&hasQueue7, 1u, 0);
    if (hasQueue7)
        m_queue->SaveGame(buffer);
}

extern int DAT_0107cdac;
extern int DAT_0107cd6c;
extern int DAT_0107cd54;

struct FUN_009f9d10_cls
{
    int CallAndReturnThis(int a);
};

struct SpawnedBase
{
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    void* unk0C;
    void* unk10;
    SpawnedBase(int a, int b, int c, int d);
    ~SpawnedBase();
};

struct FUN_00831e20 : SpawnedBase
{
    FUN_00831e20(int a, int b, int c);
};

// @fnv 0x00831e20
FUN_00831e20::FUN_00831e20(int aiArg1, int aiArg2, int aiArg3) : SpawnedBase(0, 0, aiArg1, aiArg3)
{
    unk00 = &DAT_0107cdac;
    unk0C = &DAT_0107cd6c;
    unk10 = &DAT_0107cd54;
    reinterpret_cast<FUN_009f9d10_cls*>(reinterpret_cast<char*>(this) + 0x1a0)->CallAndReturnThis(aiArg2);
}

class PrimaryBase8229
{
  public:
    virtual ~PrimaryBase8229();
    int unk04, unk08, unk0C, unk10, unk14;
};

class SecondaryBase8229
{
  public:
    virtual void vfn_00();
};

class FUN_0081dd00 : public PrimaryBase8229, public SecondaryBase8229
{
  public:
    FUN_0081dd00(int iParam1, int iParam2, int iParam3, int iParam4, NiPoint3 kPoint1, NiPoint3 kPoint2);
};

class FUN_00822920 : public FUN_0081dd00
{
  public:
    FUN_00822920(int iParam1, int iParam2, int iParam3, int iParam4, NiPoint3 kPoint1, NiPoint3 kPoint2);
    virtual ~FUN_00822920();
    void MobileObject_InitHavok();
};

// @fnv 0x00822920
FUN_00822920::FUN_00822920(int iParam1, int iParam2, int iParam3, int iParam4, NiPoint3 kPoint1,
                           NiPoint3 kPoint2)
    : FUN_0081dd00(iParam1, iParam2, iParam3, iParam4, kPoint1, kPoint2)
{
    MobileObject_InitHavok();
}

class List8321E0
{
  public:
    ~List8321E0();
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
};
class FUN_008321e0
{
  public:
    ~FUN_008321e0();
    int unk00;
    List8321E0 m_kFirst;
    List8321E0 m_kSecond;
};

// Destructor for the FUN_008321e0 class, which contains two List8321E0 members and an int field.
// @fnv 0x008321e0
FUN_008321e0::~FUN_008321e0()
{}

struct FUN_0082f260_tex
{
    virtual int v00(unsigned int flags);
};

struct FUN_0082f260_mem
{
    int unk00;
    ~FUN_0082f260_mem();
};

struct FUN_0082f260_base
{
    virtual ~FUN_0082f260_base();
    int unk04;
};

struct FUN_0082f260_cls : FUN_0082f260_base
{
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
    FUN_0082f260_tex* m_108;
    FUN_0082f260_mem m_10c;
    virtual ~FUN_0082f260_cls();
};

// Destructor: if m_108 is non-null, calls its virtual v00(1).
// @fnv 0x0082f260
FUN_0082f260_cls::~FUN_0082f260_cls()
{
    FUN_0082f260_tex* copy;
    FUN_0082f260_tex* tmp;
    if (m_108 != 0)
    {
        copy = m_108;
        tmp = copy;
        tmp != 0 ? tmp->v00(1) : 0;
    }
}

// FUN_00831fe0: __cdecl adjustor thunk (sub dword ptr [esp+4],4; jmp target).
// A __cdecl virtual member passes "this" as the first stack argument, so the
// multiple-inheritance adjustor thunk subtracts the secondary-base offset from
// that stack slot instead of from ecx. Primary base is 4 bytes (vptr only);
// the secondary base subobject sits at +4 inside Derived.
struct PrimaryBase_00831fe0
{
    virtual void __cdecl AdjustThisAndForward_00831fe0();
};

struct SecondaryBase_00831fe0
{
    virtual void __cdecl AdjustThisAndForward_00831fe0();
};

struct Derived_00831fe0 : PrimaryBase_00831fe0, SecondaryBase_00831fe0
{
    Derived_00831fe0();
// @fnv 0x00831fe0
// src: GUESS 0x00831fe0 (confidence: low)
    virtual void __cdecl AdjustThisAndForward_00831fe0();
};

Derived_00831fe0::Derived_00831fe0()
{}


struct FUN_0083c750 : ::BSStringT<char>
{
    char baseStringPadding[8];
    ::BSStringT<char> m_uiX;
    char memberStringPadding[8];
    ~FUN_0083c750();
};
// Destructor with an empty body; the m_uiX member and the ::BSStringT<char> base are destroyed implicitly.
// @fnv 0x0083c750
FUN_0083c750::~FUN_0083c750()
{}

namespace fnv_0082f1b0 {
#include <windows.h>

// Wrapper around the Win32 critical-section API: locks the section owned by
// the object passed in the fastcall register (ecx).
// @fnv 0x0082f1b0
// src: COMMUNITY 0x0082f1b0
void __fastcall NiCriticalSection_Lock(void* apCriticalSection)
{
    EnterCriticalSection((LPCRITICAL_SECTION)apCriticalSection);
}
}  // namespace fnv_0082f1b0

// FUN_0082b370 constructs its ActiveEffect base and clears the flag at +0x48.

// Constructs the ActiveEffect base and clears the derived flag.
// @fnv 0x0082b370
FUN_0082b370::FUN_0082b370(MagicCaster* caster, MagicItem* item, EffectItem* effect)
    : ActiveEffect(caster, item, effect)
{
    m_bFlag = 0;
}
