// fallout_shared/tesgrass.cpp: TESGrass, TESGrass__GRASS_DATA (36 functions)

#include "tesgrass_decls.h"
#include "../../include/PathingRequest.h"
#include <malloc.h>

// Checks the form type is 0x24, clears Data, loads the record header and iterates chunks (EDID, OBND, MODL/MODT, DATA) until none remain, returning true.
// @fnv 0x00509f80
bool TESGrass::LoadForm(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x24)
        return false;
    memset(&Data, 0, sizeof(Data));
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:  // MODL
        case 0x54444f4d:  // MODT
            TESModel::LoadModelData(this, file);
            break;
        case 0x41544144:  // DATA
            reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, &Data, sizeof(Data));
            break;
        }
        if (chunk == 0x41544144 && file->IsEndianConversionRequired())
            Data.ResetGrassData();
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Initializes the grass Data fields to default values: 30, 0, 90, 0, GWS_ABOVE_ONLY_ATLEAST, 32.0f, 0.2f, 0.5f, 10.0f, and clears cFlags.
// @fnv 0x00509ee0
void TESGrass::ResetFormData()
{
    Data.m_ucDensity = 30;
    Data.m_ucMinSlope = 0;
    Data.m_ucMaxSlope = 90;
    Data.m_usUnitsFromSurface = 0;
    Data.m_eWaterState = TESGrass__GRASS_WATER_STATE_GWS_ABOVE_ONLY_ATLEAST;
    Data.m_fPositionRange = 32.0f;
    Data.m_fHeightRange = 0.2f;
    Data.m_fWavePeriod = 0.5f;
    Data.m_fWavePhase = 10.0f;
    Data.cFlags = 0;
}

// @fnv 0x007cfd00
unsigned char TESGrass::GetMinimumSlopeDegrees()
{
    return Data.m_ucMinSlope;
}

// @fnv 0x00639b20
float TESGrass::GetLowestAllowedSlope()
{
    return Data.m_fWavePeriod;
}

// @fnv 0x00509f50
void TESGrass::InitItem()
{
    if (GetInitialized())
        return;
    SetInitializationState(true);
}

struct FUN_005081b0_shell
{
    float GetFloatAtOffset58();
};
// @fnv 0x005081b0
float FUN_005081b0_shell::GetFloatAtOffset58()
{
    return *(float*)((char*)this + 0x58);
}

struct FUN_00509aa0_shell : TESGrass
{
    unsigned char TESGrass_GetMaxSlopeDegrees();
};

// @fnv 0x00509aa0
// src: COMMUNITY 0x00509aa0
unsigned char FUN_00509aa0_shell::TESGrass_GetMaxSlopeDegrees()
{
    return ((unsigned char*)this)[0x4a];
}

struct TESGrass_shell
{
    char m_auiShapeKeys[0x4c];
    unsigned short m_4c;
    void TESGrass_SetDistanceFromWaterLevel(unsigned short state);
};

// @fnv 0x00509b20
// src: COMMUNITY 0x00509b20
void TESGrass_shell::TESGrass_SetDistanceFromWaterLevel(unsigned short state)
{
    m_4c = state;
}

struct FUN_00509bb0_shell
{
    char _pad[0x64];
    char m_flags;
    bool IsFlag2Set();
};

// @fnv 0x00509bb0
bool FUN_00509bb0_shell::IsFlag2Set()
{
    return (m_flags & 2) ? true : false;
}

struct FUN_00509bd0_shell
{
    char pad[0x64];
    char m_64;  // +0x64
    void __thiscall SetFlag2(bool value);
};

// Sets or clears bit 2 of the byte at offset 0x64 according to value.
// @fnv 0x00509bd0
void __thiscall FUN_00509bd0_shell::SetFlag2(bool abSet)
{
    abSet ? m_64 |= 2 : m_64 &= ~2;
}

struct FUN_00509c20_shell
{
    bool IsFlag4Set();
};

// @fnv 0x00509c20
bool FUN_00509c20_shell::IsFlag4Set()
{
    return (((char*)this)[0x64] & 4) ? true : false;
}

struct FUN_00509c90_shell
{
    void FUN_00509cc0();
    void* DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_00509cc0, then deletes this if flags has bit 1 set, and returns this.
// @fnv 0x00509c90
void* FUN_00509c90_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_00509cc0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00509d30_shell
{
    char field_48;
    bool TESGrass_SetDensity(unsigned char a);
};

// Stores the byte argument into the field at offset 0x48 and returns true if it is at most 0x64, otherwise returns false.
// @fnv 0x00509d30
// src: COMMUNITY 0x00509d30
bool FUN_00509d30_shell::TESGrass_SetDensity(unsigned char aucValue)
{
    if (aucValue <= 0x64)
    {
        ((char*)this)[0x48] = (char)aucValue;
        return true;
    }
    return false;
}

struct FUN_00509d60_class
{
    bool TESGrass_SetMinSlopeDegrees(unsigned char value);
};

// Stores value at offset 0x49 and returns true when value is <= 0x5a and <= the byte at offset 0x4a; otherwise returns false.
// @fnv 0x00509d60
// src: COMMUNITY 0x00509d60
bool FUN_00509d60_class::TESGrass_SetMinSlopeDegrees(unsigned char value)
{
    if (value <= 0x5a && value <= ((unsigned char*)this)[0x4a])
    {
        ((unsigned char*)this)[0x49] = value;
        return true;
    }
    return false;
}

struct FUN_00509da0_shell
{
    char pad_49[0x49];
    unsigned char byte_49;
    unsigned char byte_4a;
    bool SetSlope(unsigned char slope);
};

// Stores slope in byte_4a and returns true when slope is at most 0x5a and at least byte_49; otherwise returns false.
// @fnv 0x00509da0
bool FUN_00509da0_shell::SetSlope(unsigned char slope)
{
    if (slope <= 0x5a && slope >= byte_49)
    {
        byte_4a = slope;
        return true;
    }
    return false;
}

struct FUN_0068a830_shell
{
    TESGrass* GetGrass();
};

// @fnv 0x0068a830
TESGrass* FUN_0068a830_shell::GetGrass()
{
    return *(TESGrass**)((char*)this + 0x50);
}

struct FUN_006fe520_shell
{
    char GetByteAtOffset48();
};

// @fnv 0x006fe520
char FUN_006fe520_shell::GetByteAtOffset48()
{
    return *(char*)(((char*)this) + 0x48);
}

struct FUN_009cdac0_shell
{
    float GetField60Float();
};

// @fnv 0x009cdac0
float FUN_009cdac0_shell::GetField60Float()
{
    return *(float*)((char*)this + 0x60);
}

struct FUN_009d1b50_shell
{
    float GetField54Float();
};

// @fnv 0x009d1b50
float FUN_009d1b50_shell::GetField54Float()
{
    return *(float*)((char*)this + 0x54);
}

struct FUN_00508140_shell
{
    void __thiscall TESEffectShader_AnimateEdgeEffectAlpha(float a, float b, float c, unsigned char d);
};
struct FUN_005082b0_shell
{
    void __thiscall UpdateEnvelope(float a, float b, float c, unsigned char d, float e, float f, float g, float h,
                                   float i);
};
// @fnv 0x00508140
// src: COMMUNITY 0x00508140
void __thiscall FUN_00508140_shell::TESEffectShader_AnimateEdgeEffectAlpha(float a, float b, float c, unsigned char d)
{
    reinterpret_cast<FUN_005082b0_shell*>(this)->UpdateEnvelope(
        a, b, c, d, reinterpret_cast<FUN_009d1b50_shell*>(this)->GetField54Float(),
        reinterpret_cast<TESGrass*>(this)->TESGrass::GetLowestAllowedSlope(),
        reinterpret_cast<FUN_005081b0_shell*>(this)->GetFloatAtOffset58(),
        reinterpret_cast<PathingRequest*>(this)->GetSmoothingRandomness(),
        reinterpret_cast<FUN_009cdac0_shell*>(this)->GetField60Float());
}

extern const double DAT_01023128;
struct Grass00509ac0
{
    char _pad[0x49];
    unsigned char m49;
    float TESGrass_GetMinSlope();
};
// Returns the product of m49 and DAT_01023128.
// @fnv 0x00509ac0
// src: COMMUNITY 0x00509ac0
float Grass00509ac0::TESGrass_GetMinSlope()
{
    return m49 * DAT_01023128;
}

struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct FUN_00485e00_shell
{
    void TESForm___SaveData(int, int);
};
extern "C" unsigned char __cdecl TESForm_QEndianSwapOnSave();
struct FUN_004891d0_shell
{
    void __thiscall WriteToBuffer(unsigned int a, unsigned int b);
};
struct FUN_0050a1d0_shell
{
    void TESGrass_Save();
};
// @fnv 0x0050a1d0
// src: XBOX_PDB 0x0050a1d0
void FUN_0050a1d0_shell::TESGrass_Save()
{
    ((FUN_004855a0*)this)->M();
    ((FUN_004891d0_shell*)((char*)this + 0x30))->WriteToBuffer(0x4c444f4d, 0x54444f4d);
    if (TESForm_QEndianSwapOnSave())
        ((TESGrass__GRASS_DATA*)((char*)this + 0x48))->ResetGrassData();
    ((FUN_00485e00_shell*)this)->TESForm___SaveData((int)((char*)this + 0x48), 0x20);
    if (TESForm_QEndianSwapOnSave())
        ((TESGrass__GRASS_DATA*)((char*)this + 0x48))->ResetGrassData();
    ((FUN_00485680*)this)->M();
}

struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
};
struct R00624700
{
    void* _ref_00624700();
};
void* __cdecl __memcpy(void*, const void*, unsigned int);
struct FUN_0050a240_shell
{
    void CopyGrassData(TESForm* apCopy);
};
// @fnv 0x0050a240
void FUN_0050a240_shell::CopyGrassData(TESForm* apCopy)
{
    TESGrass* pcopy;
    pcopy = dynamic_cast<TESGrass*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(pcopy);
    __memcpy(((R00624700*)this)->_ref_00624700(), ((R00624700*)pcopy)->_ref_00624700(), 0x20);
}

struct Flt
{
    operator unsigned int();
};
struct FUN_0050a550_shell
{
    char _pad[0x34];
    Flt _34;
    const char* TESGrass_GetModelPath();
};
// Returns the string pointer stored in _34, or an empty string when _34 is zero.
// @fnv 0x0050a550
// src: COMMUNITY 0x0050a550
const char* FUN_0050a550_shell::TESGrass_GetModelPath()
{
    return _34 ? (const char*)(unsigned int)_34 : "";
}

extern const double DAT_01023128;
struct FUN_00509af0_shell
{
    char _pad[0x4A];
    unsigned char m_4A;
    float GetFloatValue();
};
// Returns m_4A multiplied by DAT_01023128 as a float.
// @fnv 0x00509af0
float FUN_00509af0_shell::GetFloatValue()
{
    return (float)(m_4A * DAT_01023128);
}

struct FUN_00509b40_shell
{
    char _pad[0x64];
    char m_flags;
    bool IsFlagSet();
};
// @fnv 0x00509b40
bool FUN_00509b40_shell::IsFlagSet()
{
    return (m_flags & 1) ? true : false;
}

struct FUN_00509b60_Struct
{
    char _pad[0x64];
    char m_64;
    void SetFlag(bool value);
};
// Sets or clears bit 0 of m_64 according to value.
// @fnv 0x00509b60
void FUN_00509b60_Struct::SetFlag(bool abSet)
{
    abSet ? m_64 |= 1 : m_64 &= ~1;
}

struct FUN_00509c40_shell
{
    char _pad[0x64];
    char m_64;
    void TESGrass_SetFitToSlope(bool);
};
// @fnv 0x00509c40
// src: COMMUNITY 0x00509c40
void FUN_00509c40_shell::TESGrass_SetFitToSlope(bool abSet)
{
    abSet ? m_64 |= 4 : m_64 &= ~4;
}

extern double _gModifierZero;
struct FUN_00509de0_class
{
    char _pad[0x54];
    float m_54;
    bool TESGrass_SetPositionRange(float);
};
// Stores v in m_54 and returns true when v is between _gModifierZero and 512.0, otherwise returns false.
// @fnv 0x00509de0
// src: COMMUNITY 0x00509de0
bool FUN_00509de0_class::TESGrass_SetPositionRange(float afValue)
{
    if (afValue >= _gModifierZero && afValue <= 512.0)
    {
        m_54 = afValue;
        return true;
    }
    return false;
}

extern double _gModifierZero;

struct FUN_00509e20_shell
{
    char pad_58[0x58];
    float m_58;
    bool TESGrass_SetHeightRange(float value);
};

// Stores value in m_58 and returns true when value is between _gModifierZero and 1.0; otherwise returns false.
// @fnv 0x00509e20
// src: COMMUNITY 0x00509e20
bool FUN_00509e20_shell::TESGrass_SetHeightRange(float value)
{
    if (value >= _gModifierZero && value <= 1.0)
    {
        m_58 = value;
        return true;
    }
    return false;
}

extern double _gModifierZero;
struct FUN_00509e60_Holder
{
    char _pad[0x5c];
    float m_5c;
    bool TESGrass_SetColorRange(float v);
};
// Stores v in m_5c and returns true when v is between _gModifierZero and 1.0; otherwise returns false.
// @fnv 0x00509e60
// src: COMMUNITY 0x00509e60
bool FUN_00509e60_Holder::TESGrass_SetColorRange(float afValue)
{
    if (afValue >= _gModifierZero && afValue <= 1.0)
    {
        m_5c = afValue;
        return true;
    }
    return false;
}

extern double _gModifierZero;
extern double g_d100;
struct FUN_00509ea0_Class
{
    char _pad[0x60];
    float m_60;
    bool TESGrass_SetWavePeriod(float value);
};
// Stores value in m_60 and returns true when value is greater than _gModifierZero and at most g_d100; otherwise returns false.
// @fnv 0x00509ea0
// src: COMMUNITY 0x00509ea0
bool FUN_00509ea0_Class::TESGrass_SetWavePeriod(float value)
{
    if (value > _gModifierZero && value <= g_d100)
    {
        m_60 = value;
        return true;
    }
    return false;
}

struct CcSub
{
    virtual ~CcSub();
};

struct CcBase
{
    virtual ~CcBase();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
};

struct FUN_00509cc0 : CcBase, CcSub
{
    virtual ~FUN_00509cc0();
};

// Empty destructor for a class deriving from CcBase and CcSub.
// @fnv 0x00509cc0
FUN_00509cc0::~FUN_00509cc0()
{}

struct ResetState
{
    unsigned char value;
};
void __cdecl BSEndian_00407a90(void* destination, unsigned char reset);
void __cdecl BSEndian_00401080(void* destination, unsigned char reset);
// Resets the grass data members by calling FUN_00407a90 on one field and FUN_00401080 on five others with zero-initialized ResetState values.
// @fnv 0x0050a120
void TESGrass__GRASS_DATA::ResetGrassData()
{
    ResetState b0 = {};
    BSEndian_00407a90(&m_usUnitsFromSurface, b0.value);
    ResetState c0 = {};
    BSEndian_00401080(&m_eWaterState, c0.value);
    ResetState b2 = {};
    BSEndian_00401080(&m_fPositionRange, b2.value);
    ResetState b4 = {};
    BSEndian_00401080(&m_fHeightRange, b4.value);
    ResetState b3 = {};
    BSEndian_00401080(&m_fWavePeriod, b3.value);
    ResetState b1 = {};
    BSEndian_00401080(&m_fWavePhase, b1.value);
}

class B50F600UpdateData
{
  public:
    B50F600UpdateData(float fTime, bool m_bUpdateEnabled, bool bIsMultiThreaded);

    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    short unk06;
    int unk08;
};

class B50F600Node
{
  public:
    void UpdateProperties();
    void Update(const B50F600UpdateData& kData);
};

class B50F600ModelLoader
{
  public:
    void ModelLoader_ReleaseFile(const char* pcPath);
};

extern B50F600ModelLoader* g_pkB50F600ModelLoader;

class B50F600Ref;
const char* __cdecl TESModel_GetModel_004895b0(B50F600Ref* pkRef);

class B50F600Ref
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void VFunc0DC();
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void VFunc0E8();
    virtual void VFunc0EC();
    virtual void VFunc0F0();
    virtual void VFunc0F4();
    virtual void VFunc0F8();
    virtual void VFunc0FC();
    virtual void VFunc100();
    virtual void VFunc104();
    virtual void VFunc108();
    virtual void VFunc10C();
    virtual void VFunc110();
    virtual void VFunc114();
    virtual void VFunc118();
    virtual void VFunc11C();
    virtual void VFunc120();
    virtual void VFunc124();
    virtual void VFunc128();
    virtual void VFunc12C();
    virtual void VFunc130();
    virtual void VFunc134();
    virtual void VFunc138();
    virtual void VFunc13C();
    virtual void VFunc140();
    virtual void VFunc144();
    virtual void VFunc148();
    virtual void VFunc14C();
    virtual void VFunc150();
    virtual void VFunc154();
    virtual void VFunc158();
    virtual void VFunc15C();
    virtual void VFunc160();
    virtual void VFunc164();
    virtual void VFunc168();
    virtual void VFunc16C();
    virtual void VFunc170();
    virtual B50F600Node* Get3D(int iIndex);

    bool TESBoundObject_ReplaceModel_0050f600(int iUnused);
};

// @fnv 0x0050f600
// src: XBOX_PDB 0x0050f600
bool B50F600Ref::TESBoundObject_ReplaceModel_0050f600(int iUnused)
{
    g_pkB50F600ModelLoader->ModelLoader_ReleaseFile(TESModel_GetModel_004895b0(this));
    B50F600Node* pkNode2 = Get3D(0);
    pkNode2->UpdateProperties();
    B50F600UpdateData kUpdateData(0.0f, false, false);
    pkNode2->Update(kUpdateData);
    return true;
}

namespace GrassCompare50A2A0Detail {
struct BaseComparison
{
    bool TESForm_CompareAllComponents(::TESForm*);
};

class VirtualView : public ::TESForm  // the TESForm vtable (78 slots) followed by the TESGrass slots this comparison calls
{
  public:
    virtual void UnknownVirtual138();
    virtual void UnknownVirtual13C();
    virtual void UnknownVirtual140();
    virtual void UnknownVirtual144();
    virtual void UnknownVirtual148();
    virtual void UnknownVirtual14C();
    virtual void UnknownVirtual150();
    virtual void UnknownVirtual154();
    virtual void UnknownVirtual158();
    virtual void UnknownVirtual15C();
    virtual void UnknownVirtual160();
    virtual void UnknownVirtual164();
    virtual void UnknownVirtual168();
    virtual void UnknownVirtual16C();
    virtual void UnknownVirtual170();
    virtual void UnknownVirtual174();
    virtual void UnknownVirtual178();
    virtual void UnknownVirtual17C();
    virtual bool GetMaximumSlopeLimit();
    virtual void UnknownVirtual184();
    virtual bool GetMinimumSlope();
    virtual void UnknownVirtual18C();
    virtual bool GetMaximumSlope();
    virtual void UnknownVirtual194();
    virtual void UnknownVirtual198();
    virtual void UnknownVirtual19C();
    virtual unsigned short GetWaterDistance();
    virtual void UnknownVirtual1A4();
    virtual unsigned int GetWaterState();
    virtual void UnknownVirtual1AC();
    virtual double GetPositionVariation();
    virtual void UnknownVirtual1B4();
    virtual double GetHeightVariation();
    virtual void UnknownVirtual1BC();
    virtual double GetColorVariation();
    virtual void UnknownVirtual1C4();
    virtual double GetDoubleAtVirtualOffset1C8();
    virtual void UnknownVirtual1CC();
    virtual bool GetBooleanAtVirtualOffset1D0();
    virtual void UnknownVirtual1D4();
    virtual bool GetBooleanAtVirtualOffset1D8();
    virtual void UnknownVirtual1DC();
    virtual bool GetFitSlope();
};

struct Argument
{
    ::TESForm* form;
};

}

// Returns true if the form is not TESGrass, base comparison reports a difference, or any compared accessor differs.
// @fnv 0x0050a2a0
// src: XBOX_PDB 0x0050a2a0
bool __fastcall TESGrass_Compare(::TESGrass* apGrass, GrassCompare50A2A0Detail::Argument apCompare)
{
    ::TESGrass* pCompareGrass = dynamic_cast< ::TESGrass*>(apCompare.form);
    if (pCompareGrass == 0)
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::BaseComparison*>(apGrass)->TESForm_CompareAllComponents(pCompareGrass))
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(apGrass)->GetMaximumSlopeLimit() !=
        reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(pCompareGrass)->GetMaximumSlopeLimit())
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(apGrass)->GetMinimumSlope() !=
        reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(pCompareGrass)->GetMinimumSlope())
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(apGrass)->GetMaximumSlope() !=
        reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(pCompareGrass)->GetMaximumSlope())
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(apGrass)->GetWaterDistance() !=
        reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(pCompareGrass)->GetWaterDistance())
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(apGrass)->GetWaterState() !=
        reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(pCompareGrass)->GetWaterState())
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(apGrass)->GetPositionVariation() !=
        reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(pCompareGrass)->GetPositionVariation())
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(apGrass)->GetHeightVariation() !=
        reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(pCompareGrass)->GetHeightVariation())
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(apGrass)->GetColorVariation() !=
        reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(pCompareGrass)->GetColorVariation())
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(apGrass)->GetDoubleAtVirtualOffset1C8() !=
        reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(pCompareGrass)->GetDoubleAtVirtualOffset1C8())
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(apGrass)->GetBooleanAtVirtualOffset1D0() !=
        reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(pCompareGrass)->GetBooleanAtVirtualOffset1D0())
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(apGrass)->GetBooleanAtVirtualOffset1D8() !=
        reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(pCompareGrass)->GetBooleanAtVirtualOffset1D8())
        return true;
    if (reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(apGrass)->GetFitSlope() !=
        reinterpret_cast<GrassCompare50A2A0Detail::VirtualView*>(pCompareGrass)->GetFitSlope())
        return true;
    return false;
}
