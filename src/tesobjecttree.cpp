#include "../include/BSStringT.h"
#include "../include/Setting.h"
// 0x00408d60 returns the setting value at +4 (or a fallback byte for null this).

// tesobjecttree.cpp: TESObjectTREE, BSShaderTextureSet, BGSImpactData, BSFadeNode and more (45 functions)
#include "../include/NiColorA.h"

// include/TESFile.h needs the Windows types before layout_support.h stubs them.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "../include/TESObjectTREE.h"
#include "../include/NiTPrimitiveArray.h"
// IsFormInitialized through a const view (the original calls the const member)
class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};

// @fnv 0x0043b5d0
TreeRecordData* TESObjectTREE::GetData()
{
    return &Data;
}

// @fnv 0x006e29d0
void TESObjectTREE::UpdateRustleSpeed(const float speed)
{
    Data.m_fRustleSpeed = speed;
}

// If the form is not yet initialized, calls BGSDestructibleObjectForm::InitItem and marks this form as initialized.
// @fnv 0x0051bb80
void TESObjectTREE::InitItem()
{
    if (((const TESFormInitFlag*)this)->IsFormInitialized())
        return;
    BGSDestructibleObjectForm::InitItem(this);
    SetInitializationState(true);
}

#include "TESFile.h"
#include <malloc.h>
#include <string.h>
#include "../include/AutoMemContext.h"
#include "../include/BSShaderTextureSet.h"
#include "../include/NiObject.h"
#include "../include/NiPoint3.h"
#include "../include/BSSoundHandle.h"

template <int size> struct EndianSizeTag
{
};
void BSEndian(unsigned int* value, EndianSizeTag<4>);
void BSEndian(float* value, EndianSizeTag<4>);

// the record chunk tags TESObjectTREE::LoadForm reads
#include "../include/CHUNK_ID.h"

// Reads a TESObjectTREE record from the file, dispatching EDID, OBND, MODL/MODT, ICON, DEST/DSTD, SNAM, CNAM and BNAM chunks until the chunk list ends.
// @fnv 0x0051bbc0
bool TESObjectTREE::LoadForm(TESFile* file)
{
    unsigned char form = file->GetTESForm();
    if (form != 37)
        return false;
    LoadRecordHeader(file);
    while (CHUNK_ID chunk = (CHUNK_ID)file->GetChunkID())
    {
        switch (chunk)
        {
        case CHUNK_ID_EDID_ID: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case CHUNK_ID_OBND_ID:
            readOBNDSubRecord(file);
            break;
        case CHUNK_ID_MODL_ID:
        case CHUNK_ID_MODT_ID:
            TESModel::LoadModelData(this, file);
            break;
        case CHUNK_ID_ICON_ID:
            TESTexture::ReadTextureData(this, file);
            break;
        case CHUNK_ID_DEST_ID:
        case CHUNK_ID_DSTD_ID:
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case CHUNK_ID_SNAM_ID: {
            struct SeedBuffer
            {
                unsigned int count;
                unsigned int* values;
            } seeds;
            seeds.values = 0;
            unsigned int chunkSize = file->GetChunkSize();
            if (!chunkSize)
                break;
            if (chunkSize % sizeof(unsigned int))
                break;
            seeds.count = chunkSize / sizeof(unsigned int);
            seeds.values = new unsigned int[seeds.count];
            memset(seeds.values, 0, chunkSize);
            file->GetChunkData(seeds.values, chunkSize);
            m_kSeedArray.RemoveAll();
            for (unsigned int i = 0; i < seeds.count; ++i)
            {
                if (file->IsEndianConversionRequired())
                    BSEndian(&seeds.values[i], EndianSizeTag<4>());
                if (seeds.values[i] > 0)
                    m_kSeedArray.AddFirstEmpty(seeds.values[i]);
            }
            delete[] seeds.values;
            break;
        }
        case CHUNK_ID_CNAM_ID: {
            unsigned int dataSize = file->GetChunkSize();
            if (dataSize != sizeof(TreeRecordData))
                break;
            file->GetChunkData(&Data, dataSize);
            if (file->IsEndianConversionRequired())
                Data.Endian();
            if (Data.m_iShadowRadius < 0)
                Data.m_iShadowRadius = 128;
            break;
        }
        case CHUNK_ID_BNAM_ID: {
            unsigned int billboardSize = file->GetChunkSize();
            if (billboardSize != sizeof(NiPoint2))
                break;
            file->GetChunkData(&m_kBillboardDimensions, billboardSize);
            if (file->IsEndianConversionRequired())
            {
                BSEndian(&m_kBillboardDimensions.x, EndianSizeTag<4>());
                BSEndian(&m_kBillboardDimensions.y, EndianSizeTag<4>());
            }
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct _Fake_FUN_004a7090
{
    void f();
};
void (_Fake_FUN_004a7090::*const _force_FUN_004a7090)() = &_Fake_FUN_004a7090::f;
// @fnv 0x004a7090
void _Fake_FUN_004a7090::f()
{
    reinterpret_cast<NiObject*>(this)->FUN_00a5d3d0();
}


struct FUN_004a7090
{
    int a;
    int b;
    ~FUN_004a7090();
};
struct FUN_0051d1c0 : public FUN_004a7090
{
    ::BSStringT<char> textures[6];
    ~FUN_0051d1c0();
};
// Destructor for the texture set: destroys the six ::BSStringT<char> texture entries and the base object.
// @fnv 0x0051d1c0
FUN_0051d1c0::~FUN_0051d1c0()
{}

struct FUN_0051b830_shell
{
    unsigned int __thiscall TESTexture1024_GetMaxAllowedSize();
};

// @fnv 0x0051b830
// src: COMMUNITY 0x0051b830
unsigned int __thiscall FUN_0051b830_shell::TESTexture1024_GetMaxAllowedSize()
{
    return 1024;
}

struct FUN_0051b950_shell : TESModel
{
    void DestroySubobject_0051b950();
};

// @fnv 0x0051b950
// src: GUESS 0x0051b950 (confidence: low)
void FUN_0051b950_shell::DestroySubobject_0051b950()
{
    TESModel::~TESModel();
}

struct NiPoint2_shell : NiPoint2
{
    bool HasEqualFloatPair(const NiPoint2&) const;
    bool ForwardCall_0051c330(const NiPoint2& other) const;
};

// @fnv 0x0051c330
// src: GUESS 0x0051c330 (confidence: low)
bool NiPoint2_shell::ForwardCall_0051c330(const NiPoint2& other) const
{
    return !HasEqualFloatPair(other);
}

struct NiRTTI;

extern const NiRTTI g_0120044c;


// @fnv 0x0051d150
const NiRTTI* BSShaderTextureSet::GetNiRTTI() const
{
    return &g_0120044c;
}

extern const char* const g_0120044c_arg1;

struct FUN_0051d1b0_shell
{
    const char* const* GetArg1Ptr();
};

// @fnv 0x0051d1b0
const char* const* FUN_0051d1b0_shell::GetArg1Ptr()
{
    return &g_0120044c_arg1;
}

void __cdecl Deallocate(void*);

struct FUN_0051d400_shell
{
    void __thiscall ReleaseStorage_0051d400();
};

// Frees the two pointers stored at offsets 0x14 and 0x18 of this object via Deallocate.
// @fnv 0x0051d400
// src: GUESS 0x0051d400 (confidence: medium)
void __thiscall FUN_0051d400_shell::ReleaseStorage_0051d400()
{
    void* p2 = *(void**)((char*)this + 0x14);
    Deallocate(p2);
    void* p1 = *(void**)((char*)this + 0x18);
    Deallocate(p1);
}



struct GlobalObject_0045cf30 : Setting
{
};

extern GlobalObject_0045cf30 g_011d5ce8;

// @fnv 0x0051d740
unsigned char GetFirstProcessListByte()
{
    return g_011d5ce8.FUN_00408d60()[0];
}

struct FUN_006447b0_shell
{
    float GetField84Float();
};

// @fnv 0x006447b0
float FUN_006447b0_shell::GetField84Float()
{
    return *reinterpret_cast<float*>(this + 0x84);
}

// float field getter at +0x38 (no RTTI evidence for its class)
struct FUN_009a9350_shell
{
    float TESCombatStyle_GetWeaponMinRangeMult() const;
};

// @fnv 0x009a9350
// src: XBOX_PDB 0x009a9350
float FUN_009a9350_shell::TESCombatStyle_GetWeaponMinRangeMult() const
{
    return *(const float*)((const char*)this + 0x38);
}

struct FUN_009acce0_shell
{
    char _pad_c8[0xc8];
    unsigned int _m_c8;
    unsigned int GetFieldC8();
};

// @fnv 0x009acce0
unsigned int FUN_009acce0_shell::GetFieldC8()
{
    return _m_c8;
}

#include "../include/BSFadeNode.h"

// @fnv 0x009ad610
// src: XBOX_PDB 0x009ad610
unsigned int BSFadeNode::QUserData()
{
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xCC);
}

struct FUN_0051b8c0_shell : TESObjectTREE
{
    void SkyShaderProperty_SetBlendValue(float value);
};

// @fnv 0x0051b8c0
// src: COMMUNITY 0x0051b8c0
void FUN_0051b8c0_shell::SkyShaderProperty_SetBlendValue(float value)
{
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x84) = value;
}

extern int DAT_0102be94;

struct FUN_0051b970_shell : TESTexture1024
{
    FUN_0051b970_shell();
};

// @fnv 0x0051b970
FUN_0051b970_shell::FUN_0051b970_shell()
{}

extern unsigned int __cdecl DialogueRandom(void);

struct FUN_0051c360_shell
{
    unsigned int TESObjectTREE_GetRandomSeed();
};

// Returns a random element from the seed array at offset 0x5c, or 0 when the array is empty.
// @fnv 0x0051c360
// src: COMMUNITY 0x0051c360
unsigned int FUN_0051c360_shell::TESObjectTREE_GetRandomSeed()
{
    unsigned int index = reinterpret_cast<NiTPrimitiveArray<unsigned int>*>(reinterpret_cast<char*>(this) + 0x5c)->GetSize();
    if (!index)
        return 0;
    unsigned int size = DialogueRandom() % index;
    return reinterpret_cast<NiTPrimitiveArray<unsigned int>*>(reinterpret_cast<char*>(this) + 0x5c)->GetAt(size);
}

namespace fnv_0051d220 {
struct FUN_004a7090
{
    virtual ~FUN_004a7090();
};

extern "C" void _delete(void* p, unsigned int size);

struct FUN_0051d220_shell : FUN_004a7090
{
    void* DestroyAndFree(unsigned int flags);
};

// Calls the base destructor, then frees this with _delete when bit 0 of flags is set, and returns this.
// @fnv 0x0051d220
void* FUN_0051d220_shell::DestroyAndFree(unsigned int flags)
{
    this->FUN_004a7090::~FUN_004a7090();
    if (flags & 1)
        _delete(this, 8);
    return this;
}
}  // namespace fnv_0051d220

struct FUN_00821600_shell
{
    void TileShaderProperty_SetTileAlpha(float value);
};

// @fnv 0x00821600
// src: COMMUNITY 0x00821600
void FUN_00821600_shell::TileShaderProperty_SetTileAlpha(float value)
{
    *(float*)((char*)this + 0x78) = value;
}

struct NiMemObject;
struct FUN_009b0900_shell
{
    unsigned int __thiscall GetFieldE0();
};
// @fnv 0x009b0900
unsigned int __thiscall FUN_009b0900_shell::GetFieldE0()
{
    return *(unsigned int*)((char*)this + 0xe0);
}

struct FUN_0051b8a0_shell
{
    void TESObjectTREE_SetShadowRadius(float f);
};
// @fnv 0x0051b8a0
// src: COMMUNITY 0x0051b8a0
void FUN_0051b8a0_shell::TESObjectTREE_SetShadowRadius(float afValue)
{
    *(int*)((char*)this + 0x80) = (int)afValue;
}

struct S_0051b900
{
    void FUN_0051b9d0();
    void* FUN_0051b900(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_0051b9d0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0051b900
void* S_0051b900::FUN_0051b900(unsigned int flags)
{
    this->FUN_0051b9d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

#include "../include/TESIcon.h"

struct FUN_0051b990_shell : public TESIcon
{
    void DestroySubobject_0051b990();
};

// @fnv 0x0051b990
// src: GUESS 0x0051b990 (confidence: low)
void FUN_0051b990_shell::DestroySubobject_0051b990()
{
    TESIcon::~TESIcon();
}

#include "../include/NiBillboardNode.h"
void __cdecl _delete(void*, unsigned int);
// @fnv 0x0051cfa0
void* NiBillboardNode::Destroy(unsigned int flags)
{
    this->ForwardCall_0051cfe0();
    if (flags & 1)
        _delete(this, 0xB4);
    return this;
}

namespace fnv_0051ba90 {
struct Holder
{
    char _pad[0x5c];
    NiTPrimitiveArray<unsigned int> arr;
    unsigned char FindIndex(unsigned int aiIndex);
};
// Searches arr for the first element equal to aiIndex and returns its index, or 0xff if not found.
// @fnv 0x0051ba90
unsigned char Holder::FindIndex(unsigned int aiIndex)
{
    unsigned char idx = 0xff;
    for (unsigned int uiIndex = 0; uiIndex < arr.GetSize(); ++uiIndex)
    {
        if (arr.GetAt(uiIndex) == aiIndex)
        {
            idx = uiIndex;
            break;
        }
    }
    return idx;
}
}  // namespace fnv_0051ba90

namespace fnv_0051b6e0 {
struct FUN_0050f7a0
{
    FUN_0050f7a0();
    virtual ~FUN_0050f7a0();
    char pad[0x2c];
};
struct FUN_0051b930
{
    FUN_0051b930();
    virtual ~FUN_0051b930();
    char pad[0x14];
};
struct FUN_0051b970_shell
{
    FUN_0051b970_shell();
    virtual ~FUN_0051b970_shell();
    char pad[0x8];
};
struct B006815c0 : public NiPoint2
{
    B006815c0();
};
extern const float g_011c3ec0_arg1;
extern const float runtimeFloatSettingDefault696;
extern const float g_011c3d00_arg1;
extern NiPoint2 DAT_011f4980;

struct FUN_0051b6e0 : public FUN_0050f7a0,
                      public FUN_0051b930,
                      public FUN_0051b970_shell,
                      public BGSDestructibleObjectForm
{
    NiTPrimitiveArray<unsigned int> m5c;
    float f6c;
    float f70;
    float f74;
    float f78;
    float f7c;
    unsigned int u80;
    float f84;
    float f88;
    B006815c0 p8c;
    FUN_0051b6e0();
    virtual ~FUN_0051b6e0();
};

// @fnv 0x0051b6e0
FUN_0051b6e0::FUN_0051b6e0() : m5c(0, 1)
{
    reinterpret_cast<TESForm*>(this)->SetFormType(static_cast<ENUM_FORM_ID>(0x25));
    f6c = g_011c3ec0_arg1;
    f70 = 5.0f;
    f74 = runtimeFloatSettingDefault696;
    f78 = 0.5f;
    f7c = g_011c3d00_arg1;
    f84 = 1.0f;
    f88 = 1.0f;
    u80 = 0x80;
    static_cast<NiPoint2&>(p8c) = DAT_011f4980;
}
}  // namespace fnv_0051b6e0

namespace fnv_0051baf0 {
struct FUN_0051baf0_shell
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void va0();
    virtual void va1();
    virtual void va2();
    virtual void va3();
    virtual void va4();
    virtual void va5();
    virtual void va6();
    virtual void va7();
    virtual void va8();
    virtual void va9();
    virtual void vaa();
    virtual void vab();
    virtual void vac();
    virtual void vad();
    virtual void vae();
    virtual void vaf();
    virtual void vb0();
    virtual void vb1();
    virtual void vb2();
    virtual void vb3();
    virtual void vb4();
    virtual void vb5();
    virtual void vb6();
    virtual void vb7();
    virtual void vb8();
    virtual void vb9();
    virtual void vba();
    virtual void vbb();
    virtual void vbc();
    virtual void vbd();
    virtual void vbe();
    virtual void vbf();
    virtual void vc0();
    virtual void vc1();
    virtual void vc2();
    virtual void vc3();
    virtual void vc4();
    virtual void vc5();
    virtual void vc6();
    virtual void vc7();
    virtual void vc8();
    virtual void vc9();
    virtual void vca();
    virtual void vcb();
    virtual void vcc();
    virtual void vcd();
    virtual void vce();
    virtual void vcf();
    virtual void vd0();
    virtual void vd1();
    virtual void vd2();
    virtual void vd3();
    virtual void vd4();
    virtual void vd5();
    virtual void vd6();
    virtual void vd7();
    virtual void vd8();
    virtual void vd9();
    virtual void vda();
    virtual void vdb();
    virtual void vdc();
    virtual void vdd();
    virtual void vde();
    virtual void vdf();
    virtual void ve0();
    virtual void ve1();
    virtual void ve2();
    virtual void ve3();
    virtual void ve4();
    virtual void ve5();
    virtual void ve6();
    virtual void ve7();
    virtual void ve8();
    virtual void ve9();
    virtual void vea();
    virtual void veb();
    virtual void vec();
    virtual void ved();
    virtual void vee();
    virtual void vef();
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vfa();
    virtual void vfb();
    virtual void vfc();
    virtual void vfd();
    virtual void vfe();
    virtual void vff();
    virtual void va0_();
    virtual void va1_();
    virtual void va2_();
    virtual void va3_();
    virtual void va4_();
    virtual void va5_();
    virtual void va6_();
    virtual void va7_();
    virtual void va8_();
    virtual void va9_();
    virtual void vaa_();
    virtual void vab_();
    virtual void vac_();
    virtual void vad_();
    virtual void vae_();
    virtual void vaf_();
    virtual void vb0_();
    virtual void vb1_();
    virtual void vb2_();
    virtual void vb3_();
    virtual void vb4_();
    virtual void vb5_();
    virtual void vb6_();
    virtual void vb7_();
    virtual void vb8_();
    virtual void vb9_();
    virtual void vba_();
    virtual void vbb_();
    virtual void vbc_();
    virtual void vbd_();
    virtual void vbe_();
    virtual void vbf_();
    virtual void vc0_();
    virtual void vc1_();
    virtual void vc2_();
    virtual void vc3_();
    virtual void vc4_();
    virtual void vc5_();
    virtual void vc6_();
    virtual void vc7_();
    virtual void vc8_();
    virtual void vc9_();
    virtual void vca_();
    virtual void vcb_();
    virtual void vcc_();
    virtual void vcd_();
    virtual void vce_();
    virtual void vcf_();
    virtual void vd0_();
    virtual void vd1_();
    virtual void vd2_();
    virtual void vd3_();
    virtual void vd4_();
    virtual void vd5_();
    virtual void vd6_();
    virtual void vd7_();
    virtual void vd8_();
    virtual void vd9_();
    virtual void vda_();
    virtual void vdb_();
    virtual void vdc_();
    virtual void vdd_();
    virtual void vde_();
    virtual void vdf_();
    virtual void ve0_();
    virtual void ve1_();
    virtual void ve2_();
    virtual void ve3_();
    virtual void ve4_();
    virtual void ve5_();
    virtual void ve6_();
    virtual void ve7_();
    virtual void ve8_();
    virtual void ve9_();
    virtual void vea_();
    virtual void veb_();
    virtual void vec_();
    virtual void ved_();
    virtual void vee_();
    virtual void vef_();
    virtual void vf0_();
    virtual void vf1_();
    virtual void vf2_();
    virtual void vf3_();
    virtual void vf4_();
    virtual void vf5_();
    virtual void vf6_();
    virtual void vf7_();
    virtual void vf8_();
    virtual void vf9_();
    virtual void vfa_();
    virtual void vfb_();
    virtual void vfc_();
    virtual void vfd_();
    virtual void vfe_();
    virtual void vff_();
    unsigned int GetEntryByIndex(unsigned char index);
};
// @fnv 0x0051baf0
unsigned int FUN_0051baf0_shell::GetEntryByIndex(unsigned char index)
{
    unsigned int result;
    if (index == 0xFF || !((NiTPrimitiveArray<unsigned int>*)((char*)this + 0x5c))->GetSize())
    {
        result = ((unsigned int(__thiscall*)(void*))(*(void***)(this))[0x190 / 4])(this);
    }
    else
    {
        if (index >= ((NiTPrimitiveArray<unsigned int>*)((char*)this + 0x5c))->GetSize())
            index = index % ((NiTPrimitiveArray<unsigned int>*)((char*)this + 0x5c))->GetSize();
        result = ((NiTPrimitiveArray<unsigned int>*)((char*)this + 0x5c))->GetAt(index);
    }
    return result;
}
}  // namespace fnv_0051baf0

struct Struct_004b0680
{
    void* m0;
    void* m4;
    Struct_004b0680(float* a, float* b);
};
struct SoundListView
{
    void AddTail(char* const& item);
    void AddSoundEntry(float* a, float* b);
};
// Allocates a Struct_004b0680 from the two float pointers and appends it to the list via AddTail.
// @fnv 0x009aa2b0
void SoundListView::AddSoundEntry(float* apFirst, float* apSecond)
{
    char* item = (char*)new Struct_004b0680(apFirst, apSecond);
    AddTail(item);
}

namespace fnv_0051c220 {
struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm*);
};

struct NiPoint2_shell
{
    bool ForwardCall_0051c330(NiPoint2 const&) const;
};

struct FUN_0051c220_vtable
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual void f68() = 0;
    virtual void f69() = 0;
    virtual void f70() = 0;
    virtual void f71() = 0;
    virtual void f72() = 0;
    virtual void f73() = 0;
    virtual void f74() = 0;
    virtual void f75() = 0;
    virtual void f76() = 0;
    virtual void f77() = 0;
    virtual void f78() = 0;
    virtual void f79() = 0;
    virtual void f80() = 0;
    virtual void f81() = 0;
    virtual void f82() = 0;
    virtual void f83() = 0;
    virtual void f84() = 0;
    virtual void f85() = 0;
    virtual void f86() = 0;
    virtual void f87() = 0;
    virtual void f88() = 0;
    virtual void f89() = 0;
    virtual void f90() = 0;
    virtual void f91() = 0;
    virtual void f92() = 0;
    virtual void f93() = 0;
    virtual void f94() = 0;
    virtual void f95() = 0;
    virtual void f96() = 0;
    virtual void f97() = 0;
    virtual void f98() = 0;
    virtual const void* get_value() = 0;
};

struct FUN_0051c220_shell : TESObjectTREE
{
    bool IsNotEqual(TESForm*);
};

// @fnv 0x0051c220
bool FUN_0051c220_shell::IsNotEqual(TESForm* apCompare)
{
    TESObjectTREE* i = dynamic_cast<TESObjectTREE*>(apCompare);
    if (!i)
        return true;

    if (memcmp(reinterpret_cast<const void*>(reinterpret_cast<const char*>(this) + 0x6c),
               reinterpret_cast<FUN_0051c220_vtable*>(i)->get_value(), 0x20))
        return true;

    if (reinterpret_cast<NiPoint2_shell*>(reinterpret_cast<char*>(this) + 0x8c)
            ->ForwardCall_0051c330(*reinterpret_cast<NiPoint2 const*>(reinterpret_cast<const char*>(i) + 0x8c)))
        return true;

    unsigned int isize = reinterpret_cast<NiTPrimitiveArray<unsigned int>*>(reinterpret_cast<char*>(this) + 0x5c)->GetSize();
    if (isize != reinterpret_cast<NiTPrimitiveArray<unsigned int>*>(reinterpret_cast<char*>(i) + 0x5c)->GetSize())
        return true;

    unsigned int pcomp = 0;
    for (; pcomp < isize; ++pcomp)
    {
        if (reinterpret_cast<NiTPrimitiveArray<unsigned int>*>(reinterpret_cast<char*>(this) + 0x5c)->GetAt(pcomp) !=
            reinterpret_cast<NiTPrimitiveArray<unsigned int>*>(reinterpret_cast<char*>(i) + 0x5c)->GetAt(pcomp))
            return true;
    }

    if (reinterpret_cast<FUN_005e79a0_t*>(this)->TESForm_CompareAllComponents(i))
        return true;

    return false;
}
}  // namespace fnv_0051c220

class FUN_0051b880_cls
{
  public:
    int unk00;
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
    int m_80;
    double GetValue();
};
// @fnv 0x0051b880
double FUN_0051b880_cls::GetValue()
{
    return m_80;
}

struct SpawnedBase
{
    virtual void v00();
    SpawnedBase();
};

struct FUN_0051b930 : SpawnedBase
{
    virtual void v00();

    FUN_0051b930();
};

// @fnv 0x0051b930
FUN_0051b930::FUN_0051b930() : SpawnedBase()
{}

// FUN_0051b9b0 - TESTexture1024::TESTexture1024()
// Runs the base TESTexture constructor, then installs the class vtable pointer.
extern int DAT_0102beb4;  // vtable of TESTexture1024

class TESTextureBase
{
  public:
    void* m_pVTable;   // +0x00
    TESTextureBase();  // out-of-line base constructor
};

class FUN_0051b9b0_cls : public TESTextureBase
{
  public:
    FUN_0051b9b0_cls();
};

// @fnv 0x0051b9b0
FUN_0051b9b0_cls::FUN_0051b9b0_cls() : TESTextureBase()
{
    m_pVTable = &DAT_0102beb4;
}

extern double DAT_01012060;
extern double DAT_010179e0;
extern double DAT_0102c188;

struct FUN_0051d250_Class
{
    int unk00;
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
    float unk8C;
    float unk90;

    bool __thiscall TESObjectTREE_IsLargeEnoughForDistantLOD();
};

// Returns false if unk8C or unk90 falls within their respective ranges above DAT_01012060, otherwise true.
// @fnv 0x0051d250
// src: XBOX_PDB 0x0051d250
bool __thiscall FUN_0051d250_Class::TESObjectTREE_IsLargeEnoughForDistantLOD()
{
    if ((this->unk8C > DAT_01012060 && this->unk8C <= DAT_010179e0) ||
        (this->unk90 > DAT_01012060 && this->unk90 <= DAT_0102c188))
    {
        return false;
    }

    return true;
}

class BS9AA340Item
{
  public:
    int GetOwner();
    static void operator delete(void* pvMem);
};

class BS9AA340List
{
  public:
    BS9AA340Item** GetItem();
    BS9AA340List* GetNext();
    void RemoveItem(BS9AA340Item** ppkItem);
    void RemoveItemByOwner(int iOwner);
};

// Walks the list and, for the first item whose owner equals iOwner, removes it from its node and deletes it.
// @fnv 0x009aa340
void BS9AA340List::RemoveItemByOwner(int iOwner)
{
    BS9AA340List* pkNode = this;
    while (pkNode)
    {
        BS9AA340Item* pkItem = *pkNode->GetItem();
        if (pkItem && pkItem->GetOwner() == iOwner)
        {
            pkNode->RemoveItem(&pkItem);
            delete pkItem;
            return;
        }
        pkNode = pkNode->GetNext();
    }
}

struct FUN_004891d0_shell
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    void WriteToBuffer(unsigned int, unsigned int);
};
struct FUN_0048e370_obj
{
    int unk00, unk04, unk08;
    void TESTexture_Save(unsigned int);
};
struct S_00477f20
{
    int unk00, unk04;
    void FUN_00477f20();
};
struct TreeData
{
    float unk00, unk04, unk08, unk0c, unk10;
    int unk14;
    float unk18, unk1c;
    void FUN_00414290();
};
bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl TESForm_AddChunkArray_00485710(unsigned int, unsigned int*, unsigned int);
void __cdecl AppendChunk(unsigned int, void*, unsigned int);
void __cdecl ourMemset(void*, int, unsigned int);
struct SaveTree
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    FUN_004891d0_shell model;
    FUN_0048e370_obj icon;
    S_00477f20 destruct;
    NiTPrimitiveArray<unsigned int> seeds;
    TreeData data;
    float billboardX, billboardY;
    void BeginFormRecord();
    void FinishFormRecord();
    void TESObjectTREE_Save();
};
// @fnv 0x0051bfb0
// src: XBOX_PDB 0x0051bfb0
void SaveTree::TESObjectTREE_Save()
{
    BeginFormRecord();
    model.WriteToBuffer(0x4c444f4d, 0x54444f4d);
    icon.TESTexture_Save(0x4e4f4349);
    destruct.FUN_00477f20();
    if (seeds.GetSize() > 0)
    {
        unsigned int* count = 0;
        unsigned int values = seeds.GetSize();
        unsigned int index = values * sizeof(unsigned int);
        count = new unsigned int[values];
        ourMemset(count, 0, index);
        unsigned int uiSeedValue;
        for (unsigned int value = 0; value < values; value++)
        {
            uiSeedValue = seeds.GetAt(value);
            if (uiSeedValue > 0)
                count[value] = uiSeedValue;
        }
        TESForm_AddChunkArray_00485710(0x4d414e53, count, values);
    }
    if (data.unk14 < 0)
        data.unk14 = 128;
    if (TESForm_QEndianSwapOnSave())
        data.FUN_00414290();
    AppendChunk(0x4d414e43, &data, 32);
    if (TESForm_QEndianSwapOnSave())
        data.FUN_00414290();
    TESForm_AddChunkArray_00485710(0x4d414e42, (unsigned int*)&billboardX, 2);
    FinishFormRecord();
}

class TreeNameView
{
  public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual char* GetName();
};

class FUN_0051c3b0_cls : public TESObjectTREE
{
  public:
    void BuildBillboardTexturePath(char* dst);
};

// Writes the billboard texture folder path, appends the tree name up to its extension, then adds ".dds" and a null terminator.
// @fnv 0x0051c3b0
void FUN_0051c3b0_cls::BuildBillboardTexturePath(char* dst)
{
    const char* src2 = "Textures\\Trees\\Billboards";
    char* out4 = dst;
    for (; *src2 != 0; src2++, out4++)
    {
        *out4 = *src2;
    }
    char* name = ((TreeNameView*)((char*)this + 0x30))->GetName();
    for (; *name != '.' && *name != 0; name++, out4++)
    {
        *out4 = *name;
    }
    if (*name == '.')
    {
        *out4 = '.';
        out4++;
        *out4 = 'd';
        out4++;
        *out4 = 'd';
        out4++;
        *out4 = 's';
        out4++;
    }
    *out4 = 0;
}

class P2
{
  public:
    float x;
    float y;
    P2();
    P2(float, float);
};
// Gamebryo NiMemObject with its sized operator delete (the shared NiMemObject declares the unsized one)
class SizedNiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class CreatedObj : public SizedNiMemObject
{
  public:
    int cf00;
    int cf04;
    int cf08;
    int cf0c;
    int cf10;
    int cf14;
    int cf18;
    int cf1c;
    int cf20;
    int cf24;
    int cf28;
    int cf2c;
    int cf30;
    int cf34;
    int cf38;
    int cf3c;
    int cf40;
    int cf44;
    int cf48;
    int cf4c;
    int cf50;
    int cf54;
    CreatedObj(int, NiPoint3*, NiPoint3*, NiColorA*, P2*, int, int, int, unsigned short*);
};
template <class T> class SpPtr
{
  public:
    T* m_ptr;
    SpPtr(T*);
    ~SpPtr();
    SpPtr& operator=(const SpPtr&);
};
void* NiMalloc(unsigned int);
void* memcpy(void*, const void*, unsigned int);
extern double DAT_01012060;
class TreeObj
{
  public:
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    NiPoint2 m_kBillboardDimensions;
    void CreateTreeGeometry(bool flag, SpPtr<CreatedObj>* out);
};
// @fnv 0x0051c490
void TreeObj::CreateTreeGeometry(bool abVertical, SpPtr<CreatedObj>* out)
{
    AutoMemContext ctx3((MEM_CONTEXT)0x23, true,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectTREE.cpp", 409);
    float buf[36];
    buf[0] = 0.0f;
    buf[1] = 1.0f;
    buf[2] = 0.0f;
    buf[3] = 0.0f;
    buf[4] = 1.0f;
    buf[5] = 0.0f;
    buf[6] = 0.0f;
    buf[7] = 1.0f;
    buf[8] = 0.0f;
    buf[9] = 0.0f;
    buf[10] = 1.0f;
    buf[11] = 0.0f;
    buf[12] = 0.0f;
    buf[13] = 0.0f;
    buf[14] = -1.0f;
    buf[15] = 0.0f;
    buf[16] = 0.0f;
    buf[17] = -1.0f;
    buf[18] = 0.0f;
    buf[19] = 0.0f;
    buf[20] = -1.0f;
    buf[21] = 0.0f;
    buf[22] = 0.0f;
    buf[23] = -1.0f;
    buf[24] = 1.0f;
    buf[25] = 0.0f;
    buf[26] = 0.0f;
    buf[27] = 1.0f;
    buf[28] = 0.0f;
    buf[29] = 0.0f;
    buf[30] = 1.0f;
    buf[31] = 0.0f;
    buf[32] = 0.0f;
    buf[33] = 1.0f;
    buf[34] = 0.0f;
    buf[35] = 0.0f;
    NiPoint3* pA = new NiPoint3[4];
    NiPoint2 bsize = m_kBillboardDimensions;
    if (bsize.y <= DAT_01012060)
    {
        bsize.y = 1400.0f;
    }
    bsize.x = (float)(bsize.y / 2.0);
    pA[0] = NiPoint3(-bsize.x, 0.0f, 0.0f);
    pA[3] = NiPoint3(bsize.x, 0.0f, 0.0f);
    if (abVertical)
    {
        pA[1] = NiPoint3(-bsize.x, 0.0f, bsize.y);
        pA[2] = NiPoint3(bsize.x, 0.0f, bsize.y);
    }
    else
    {
        pA[1] = NiPoint3(-bsize.x, bsize.y, 0.0f);
        pA[2] = NiPoint3(bsize.x, bsize.y, 0.0f);
    }
    NiPoint3* pB2 = new NiPoint3[12];
    memcpy(pB2, buf, 0x90);
    P2* pCA = new P2[4];
    pCA[0] = P2(1.0f, 1.0f);
    pCA[1] = P2(1.0f, 0.0f);
    pCA[2] = P2(0.0f, 0.0f);
    pCA[3] = P2(0.0f, 1.0f);
    NiColorA* pDB = new NiColorA[4];
    pDB[0] = NiColorA(1.0f, 1.0f, 1.0f, 0.0f);
    pDB[1] = NiColorA(1.0f, 1.0f, 1.0f, 0.0f);
    pDB[2] = NiColorA(1.0f, 1.0f, 1.0f, 0.0f);
    pDB[3] = NiColorA(1.0f, 1.0f, 1.0f, 0.0f);
    unsigned short* pE = (unsigned short*)NiMalloc(12);
    pE[0] = 0;
    pE[1] = 2;
    pE[2] = 1;
    pE[3] = 0;
    pE[4] = 3;
    pE[5] = 2;
    SpPtr<CreatedObj> sp(new CreatedObj(4, pA, pB2, pDB, pCA, 1, 0x1000, 2, pE));
    *out = sp;
}

namespace fnv_0051cba0 {
// Gamebryo NiMemObject with its sized operator delete (the shared NiMemObject declares the unsized one)
class SizedNiMemObject
{
  public:
    static void* operator new(unsigned int size);
    static void operator delete(void* pointer, unsigned int);
};
// the reference-count view of the billboard NiSourceTexture
class BillboardTexture
{
  public:
    void IncRefCount();
    void DecRefCount();
};
class TreeSceneObject : public SizedNiMemObject
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
    virtual void GetTexture(unsigned int index, NiPointer<BillboardTexture>* texture);
    virtual void SetTexture(unsigned int index, const char* path);
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
    virtual void AttachChildInAvailableSlot(TreeSceneObject* child, bool firstAvailable);
    virtual void v56();
    virtual void UpdateShader(int flags);
};
class FUN_00a74480 : public TreeSceneObject
{
  public:
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
    FUN_00a74480(unsigned int texture);
    void AttachProperty(NiObject* property);
};
class FUN_00ba8630 : public TreeSceneObject
{
  public:
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
    FUN_00ba8630();
    void BSShaderPPLightingProperty_LoadTextureSet(const char* name, TreeSceneObject* object);
};
class FUN_0051d0d0 : public TreeSceneObject
{
  public:
    unsigned int referenceCount;
    BSStringT<char> textures[6];
    FUN_0051d0d0();
};
class FUN_0051cf00 : public TreeSceneObject
{
  public:
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
    FUN_0051cf00();
    void SetMode_0051d000(int mode);
};
extern const char treeSourceFile[];
// NiPointer<NiSourceTexture>::operator==(NiSourceTexture*) (0x00822510); the shared NiPointer declares no operator==
struct BillboardTexturePointerCompare
{
    BillboardTexture* m_pObject;
    bool operator==(BillboardTexture* object) const;
};
TreeSceneObject* GetFloatAsUInt();
class TreeBillboardBuilder : public FUN_0051d250_Class
{
  public:
    void CreateTreeGeometry(bool variant, NiPointer<BillboardTexture>* texture);
    void BuildBillboardTexturePath(char* path);
    TreeSceneObject* CreateBillboardSceneObject(bool variant);
};
// @fnv 0x0051cba0
TreeSceneObject* TreeBillboardBuilder::CreateBillboardSceneObject(bool variant)
{
    if (!TESObjectTREE_IsLargeEnoughForDistantLOD())
        return 0;
    AutoMemContext eb(0x23, true, treeSourceFile, 470);
    NiPointer<BillboardTexture> a(0);
    CreateTreeGeometry(variant, &a);
    FUN_00a74480* h = new FUN_00a74480((unsigned int)(BillboardTexture*)a);
    TreeSceneObject* f = GetFloatAsUInt();
    if (f)
        h->AttachProperty((NiObject*)f);
    FUN_00ba8630* i = new FUN_00ba8630;
    h->AttachProperty((NiObject*)i);
    char q[260];
    BuildBillboardTexturePath(q);
    FUN_0051d0d0* cf = new FUN_0051d0d0;
    cf->SetTexture(0, q);
    i->BSShaderPPLightingProperty_LoadTextureSet("STBB", cf);
    i->UpdateShader(0);
    NiPointer<BillboardTexture> p(0);
    cf->GetTexture(0, &p);
    if (reinterpret_cast<BillboardTexturePointerCompare&>(p) == 0)
        return 0;
    FUN_0051cf00* s = new FUN_0051cf00;
    s->SetMode_0051d000(5);
    s->AttachChildInAvailableSlot(h, true);
    return s;
}
}  // namespace fnv_0051cba0

namespace fnv_0051d440 {
struct Texture;
struct TexturePtr
{
    Texture* value;
    TexturePtr(Texture*);
    ~TexturePtr();
    operator Texture*() const;
};
struct TreeWork
{
    virtual ~TreeWork();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    TreeWork(void*, int, int, int, int, int, int);
};
struct TextureInfo
{
    int flags;
    TreeWork* work;
    unsigned int id;
    TextureInfo();
};
struct Loader
{
    void Queue(char*, TreeWork*);
};
extern Loader* g_modelLoader;
unsigned char GetFirstProcessListByte();
bool IsTextureReady(unsigned int);
void CopyTexturePath(char*, char*, unsigned int);
bool fnv_NiStreamGetTexture(char*, TexturePtr*);
void ProcessTexture(int, int, int, TextureInfo*, int, int, unsigned short);
struct TreeTexture
{
    bool Valid();
    unsigned int Deallocate();
    void GetPath(char*);
    TreeWork* Load(int);
    void ProcessTreeTexture(int, int, int, int, int, int, int, int);
};
// Validates inputs and texture readiness, loads or queues the tree texture, then processes it and deletes the work object.
// @fnv 0x0051d440
void TreeTexture::ProcessTreeTexture(int a, int unused, int c, int d, int e, int f, int g, int unused2)
{
    AutoMemContext context4(0x23, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectTREE.cpp",
                            0x228);
    if (!g || !a || !c || !d)
        return;
    if (!GetFirstProcessListByte())
        return;
    if (!Valid())
        return;
    TreeWork* work2 = 0;
    if (!IsTextureReady(Deallocate()))
    {
        char path3[260];
        char normalized[260];
        GetPath(path3);
        CopyTexturePath(path3, normalized, 260);
        TexturePtr texture5(0);
        fnv_NiStreamGetTexture(normalized, &texture5);
        if (!texture5)
        {
            TreeWork* request = new TreeWork(this, e, f, g, d, a, c);
            g_modelLoader->Queue(normalized, request);
            return;
        }
        else
        {
            work2 = Load(1);
        }
        if (!work2)
            return;
    }
    TextureInfo info2;
    info2.id = Deallocate();
    info2.work = work2;
    info2.flags = 0;
    ProcessTexture(e, f, g, &info2, a, c, (unsigned short)d);
    delete info2.work;
}
}  // namespace fnv_0051d440

struct TreeBase
{
    virtual ~TreeBase();
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
struct TreeModel
{
    virtual ~TreeModel();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
};
struct TreeIcon
{
    virtual ~TreeIcon();
    unsigned int unk04;
    unsigned int unk08;
};
struct TreeDestructible
{
    virtual ~TreeDestructible();
    unsigned int unk04;
};
struct FUN_0051b9d0 : TreeBase, TreeModel, TreeIcon, TreeDestructible
{
    NiTPrimitiveArray<unsigned int> seeds;
    virtual ~FUN_0051b9d0();
    void ClearData();
};
// Destructor: calls ClearData, then the NiTPrimitiveArray<unsigned int> member and base sub-objects are destroyed.
// @fnv 0x0051b9d0
FUN_0051b9d0::~FUN_0051b9d0()
{
    ClearData();
}

struct FUN_0066deb0_vec
{
    int field0;
    int field4;
    int field8;

    FUN_0066deb0_vec();
};

FUN_0066deb0_vec::FUN_0066deb0_vec()
{}

struct FUN_0051d2c0_shell
{
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    unsigned int count;
    FUN_0066deb0_vec* items;
    int* itemIDs;

    FUN_0051d2c0_shell* __thiscall Init(void* arg0, void* arg4, void* arg8, void* argC, unsigned int itemCount,
                                        const void* itemSource, const void* idSource);
};

void* __cdecl operator new(unsigned int);
void* __cdecl __memcpy(void* destination, const void* source, unsigned int size);
extern unsigned int _data_011c16bc;

// Initializes the shell object by copying four pointers, allocating and copying arrays of items and IDs, then returns this.
// @fnv 0x0051d2c0
FUN_0051d2c0_shell* FUN_0051d2c0_shell::Init(void* apField0, void* apField4, void* apField8, void* apFieldC,
                                             unsigned int itemCount, const void* itemSource, const void* idSource)
{
    field0 = apField0;
    field4 = apField4;
    field8 = apField8;
    fieldC = apFieldC;
    count = itemCount;

    items = new FUN_0066deb0_vec[count];
    __memcpy(items, itemSource, count * sizeof(FUN_0066deb0_vec));

    itemIDs = new int[count];
    __memcpy(itemIDs, idSource, count * sizeof(int));

    return this;
}

class TreeCopy : public TESObjectTREE
{
  public:
    void TESForm_CopyAllComponents(TESForm*);
    void TESObjectTREE_Copy(TESForm*);
};

typedef TreeRecordData*(__thiscall* TreeDataGetter)(TESObjectTREE*);

// Copies seed array, tree record data, and billboard dimensions from a source TESObjectTREE into this TreeCopy.
// @fnv 0x0051c140
// src: XBOX_PDB 0x0051c140
void TreeCopy::TESObjectTREE_Copy(TESForm* source)
{
    TESObjectTREE* tree;
    tree = dynamic_cast<TESObjectTREE*>(source);
    if (!tree)
        return;

    TESForm_CopyAllComponents(source);
    {
        unsigned int count;
        count = tree->m_kSeedArray.GetSize();
        m_kSeedArray.RemoveAll();
        {
            unsigned int index;
            for (index = 0; index < count; ++index)
                m_kSeedArray.Add(tree->m_kSeedArray.GetAt(index));
        }
    }
    Data = *reinterpret_cast<TreeDataGetter>((*reinterpret_cast<void***>(tree))[0x63])(tree);
    m_kBillboardDimensions = tree->m_kBillboardDimensions;
}
