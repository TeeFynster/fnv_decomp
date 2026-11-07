// src/staging/blk_00c00000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00c00000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00c00000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/MemoryManager.h"
#include "../../include/ImageSpaceTexture.h"
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
#include "../../include/NiBound.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiShaderConstantMapEntry.h"
#include "../../include/StrArr.h"
#include "../../include/BSShaderPPLightingProperty.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiScreenElements.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiTObjectArray.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern MemoryManager g_memoryManager;
void __cdecl FUN_00c03270();
struct FUN_00c033f0_class
{
    void* __thiscall FUN_00c033f0(int);
};
extern int(__stdcall* DAT_00fdf1c4)(void*);
extern int(__stdcall* DAT_00fdf1c0)(void*);
struct RefObject
{
    virtual void Unused0();
    virtual void DeleteThis();
    int m_iObjectReferenceCount;

    void DecRefCount(int(__stdcall* pfnDec)(void*))
    {
        if (pfnDec(&m_iObjectReferenceCount) == 0)
            DeleteThis();
    }
    void IncRefCount()
    {
        DAT_00fdf1c0(&m_iObjectReferenceCount);
    }
};
struct Arg_00c04090
{
    char pad00[0x4c];
    RefObject* m_sp4c;
    RefObject* m_sp50;
};
struct Target_00c04090
{
    char pad00[0x30];
    RefObject* m_sp30;
    RefObject* m_sp34;
    char pad38[0xcc - 0x38];
    Arg_00c04090* m_pCC;

    void AssignRefObjects(Arg_00c04090* arg);
};
extern "C" void __cdecl BSShaderManager_ReturnVelocityBuffers();
struct FUN_00c04960_class
{
    void ResetArrayElement();
};
struct FUN_00c04d50_class
{
    unsigned char b[0x58];
    void CopyByteAndStoreInt(int a);
};
extern "C" unsigned char _DAT_011F941E;
struct FUN_00c04d60_class
{
    unsigned char pad[0x60];
    int m_0x60;
    int __thiscall ImageSpaceEffectCinematic_IsActive();
};
struct FUN_00c04d80_cls
{
    void __thiscall SetByteValue(char v);
};
extern char DAT_011f9422;
struct FUN_00c05350_class
{
    int ImageSpaceEffectBloom_IsActive();
};
extern void* DAT_010bcb60;
void __cdecl Runtime_UpdateState_00bb45b0();
extern "C" void __cdecl _delete(void*, unsigned int);
struct FUN_00c058c0
{
    void* vtbl;
    __thiscall FUN_00c058c0(bool flag);
};
extern "C" void __cdecl ShadowLightShader_EnableConstantsForPass(int, int);
void __stdcall SpeedTreeBranchShader_EnableConstantsForPass(unsigned short ausValue);
void __fastcall FUN_00a89760(void*);
extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010bcdc8;
struct FUN_00a74480_holder
{
    void FUN_00a74480(unsigned int);
};
struct FUN_00c1a660_holder : FUN_00a74480_holder
{
    FUN_00c1a660_holder* InitializeFields_00c1a660(unsigned int a);
};
extern int DAT_011f9530;
struct FUN_00c0bb20_class
{
    void Lighting30Shader_SetHairMaps(int a, int b);
};
extern NiShaderConstantMapEntry* DAT_011fec44;
extern NiShaderConstantMapEntry* DAT_011fec6c;
void __cdecl UpdateFlagHolders(int);
void SetShaderConstantMapEntryFlags(int a);
struct FUN_00c036e0_class
{
    void __thiscall ImageSpaceEffectBloom_SetRadius(int a);
};
int PackBits(char a, char b, char c, char d, char e, char f, char g, char h);
struct FUN_00c06ee0_class
{
    char pad00[0x34];
    RefObject* m_sp34;

    void __thiscall NiPSEmitParticlesCtlr_SetBirthRateInterpolator(RefObject* p);
};
struct FUN_00c06f30_class
{
    char pad[0x48];
    RefObject* m_sp48;
    void __thiscall NiD3DPass_SetPixelShader_00c06f30(RefObject* p);
};
struct FUN_00c0d1b0_class
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
    void ParallaxShader_PresetPasses();
};
struct FUN_00c1a640_class
{
    unsigned short __thiscall TallGrassTriStrips_SetCount(unsigned short a);
};
extern float DAT_011ae6cc;
extern float DAT_011ae6c8;
extern float _DAT_012003c4;
struct ImageSpaceShaderParam
{
    void __thiscall SetShaderConstantVector4(int a, float b, float c, float d, float e);
};
struct FUN_00c053c0_class
{
    char pad00[0x1c];
    ImageSpaceShaderParam* m_pParam;
    char pad20[0x58 - 0x20];
    char* m_p58;

    bool __thiscall UpdateShaderParam(int);
};
struct FUN_00c03260_class
{
    char pad[0x58];
    ImageSpaceTexture m_tex;
    void AddRenderedTexture_Thunk();
};
extern float DAT_012023f4;
extern float DAT_012023f8;
extern int DAT_011ae680;
struct FUN_00c03350_class
{
    char pad00[0x1c];
    FUN_00c053c0_class* m_pParam;
    char pad20[0x58 - 0x20];
    char* m_p58;
    bool __thiscall ImageSpaceEffectSunbeams_UpdateParams(int);
};
struct FUN_00c03390_class
{
    void __thiscall ImageSpaceEffectSunbeams_BorrowTextures(int);
};
struct BeamStage
{
    char pad00[8];
    void* m_p08;
    char pad0c[0x54];
    int m_iObjectReferenceCount;
};
struct StageReturn : BeamStage
{
    void __thiscall ReturnToPool();
};
struct UnkBA38F0
{
    void __thiscall ImageSpaceTexture_SetupTexture(BeamStage*);
};
extern int DAT_0126f74c;
struct FUN_00c04310_class
{
    char pad00[0x98];
    UnkBA38F0** m_ppStages;
    char pad9c[2];
    unsigned short m_usStageCount;

    void __thiscall ReleaseStagePasses(int);
};
extern int DAT_010bca64;
struct FUN_00c046e0_holder
{
    ImageSpaceShaderParam* m_pParam;
};
struct FUN_00c046e0_class
{
    unsigned char pad00[0x1c];
    FUN_00c046e0_holder* m_pHolder;
    unsigned char pad20[0x3c];
    float m_f5c;

    bool __thiscall ImageSpaceEffectMenuBG_UpdateParams(int);
};
struct FUN_00c054a0_class
{
    void FUN_00c05250();
    void* FUN_00c054a0(unsigned char a);
};
struct FUN_00c056a0_class
{
    void __thiscall FUN_00c056a0();
    FUN_00c056a0_class* __thiscall FUN_00c05760(char flag);
};
extern int DAT_010bcc90;
struct FUN_00c1a480_class
{
    int m_vtbl;
    int m_iWordAt04;
    int __thiscall NiTriStrips_NiTriStrips(int);
    int __thiscall SetVirtualTable_00c1a480(int a);
};
struct FUN_00a7fb20_class
{
    char* __thiscall GetViewerString_00a7fb20(char const* name);
};
struct Holder
{
    unsigned char pad00[0xC4];
    unsigned short m_instanceCount;
    unsigned char padC6[2];
    FUN_00a7fb20_class m_bound;

    void __thiscall AppendString(StrArr* strings);
    void __thiscall AppendBoundInfo(StrArr* strings);
};
char* __cdecl NiGetViewerString_00a7d490(char const* name, unsigned short value);
struct NiTransformDummy
{
    int pad[4];
};
struct FUN_00c1a680_class
{
    void __thiscall TallGrassTriShape_UpdateWorldBound();
};
struct FnvObj;
struct FnvHolder
{
    virtual void vt00();
    virtual void vt04();
    virtual void vt08();
    virtual void vt0c();
    virtual void vt10();
    virtual void vt14();
    virtual void vt18();
    virtual void vt1c();
    virtual void vt20();
    virtual void vt24();
    virtual void vt28();
    virtual void vt2c();
    virtual void vt30();
    virtual void vt34();
    virtual void vt38();
    virtual void vt3c();
    virtual void vt40();
    virtual void vt44();
    virtual void vt48();
    virtual void vt4c();
    virtual void vt50();
    virtual void vt54();
    virtual void vt58();
    virtual void vt5c();
    virtual void vt60();
    virtual void vt64();
    virtual void vt68();
    virtual void vt6c();
    virtual void vt70();
    virtual void vt74();
    virtual void vt78();
    virtual void vt7c();
    virtual void vt80();
    virtual void vt84();
    virtual void vt88();
    virtual void vt8c();
    virtual void vt90();
    virtual void vt94();
    virtual void vt98();
    virtual void vt9c();
    virtual void vta0();
    virtual void vta4();
    virtual void vta8();
    virtual void vtac();
    virtual void vtb0();
    virtual void vtb4();
    virtual void vtb8();
    virtual void vtbc();
    virtual void vtc0();
    virtual void vtc4();
    virtual FnvObj* vtc8();
};
struct FnvObj
{
    virtual void vt00();
    virtual void vt04();
    virtual void vt08();
    virtual void vt0c();
    virtual void vt10();
    virtual void vt14();
    virtual void vt18();
    virtual void vt1c();
    virtual void vt20();
    virtual void vt24();
    virtual void vt28();
    virtual void vt2c();
    virtual void vt30();
    virtual void vt34();
    virtual void vt38();
    virtual void vt3c();
    virtual void vt40();
    virtual void vt44();
    virtual void vt48();
    virtual void vt4c();
    virtual void vt50();
    virtual void vt54();
    virtual void vt58();
    virtual void vt5c();
    virtual void vt60();
    virtual void vt64();
    virtual void vt68();
    virtual void vt6c();
    virtual void vt70();
    virtual void vt74();
    virtual void vt78();
    virtual void vt7c();
    virtual void vt80();
    virtual void vt84();
    virtual void vt88();
    virtual void vt8c();
    virtual unsigned int vt90(int);
};
extern FnvHolder* g_pFnvHolder;
struct FUN_00c02d40_cls
{
    int unk00[0x17];
    float m_f5c;
    float ImageSpaceEffectMotionBlur_GetObjectBlurConst();
};
extern unsigned int DAT_011a9bd0;
extern unsigned int DAT_011a9bd4;
extern unsigned int DAT_011a9bd8;
extern unsigned int DAT_011a9bdc;
extern float DAT_01018f5c;
extern unsigned int DAT_011fa2d0;
extern unsigned int DAT_011fa2d4;
extern unsigned int DAT_011fa2d8;
extern unsigned int DAT_011fa2dc;
class FUN_00c02d90_tgt
{
  public:
    unsigned char unk00[0x24];
    unsigned char m_24;
    unsigned char unk25[0x38 - 0x25];
    float m_38;
};
class FUN_00c02d90_cls
{
  public:
    unsigned char unk00[0xa8];
    FUN_00c02d90_tgt* m_a8;
};
class FUN_00c02d90_loc
{
  public:
    float m_00;
    float m_04;
    float m_08;
    unsigned int m_0c;
};
void __stdcall ShadowLightShader_UpdateTogglesConstant(FUN_00c02d90_cls* a1, int a2, FUN_00c02d90_tgt* a3);
struct FlagHolderB5649
{
    char pad00[8];
    unsigned char m_flag08;
};
extern unsigned int DAT_011febdc;
extern unsigned int DAT_011fec34;
extern unsigned int DAT_011fec8c;
extern unsigned int DAT_011fcc80;
extern unsigned int DAT_011fc0a0;
void UpdateFlagHolders(unsigned int uiIndex);
extern int DAT_010bc8a4;
struct Base03270
{
    ~Base03270();
};
struct Obj03270
{
    virtual void Release(int flags);
};
struct Holder03270
{
    Obj03270* m_iWordAt00;
    Obj03270* m_iWordAt04;
};
struct Table03270
{
    void SetAt(unsigned int index, Obj03270*& value);
    unsigned int m_u00;
};
struct Ptr03270
{
    Obj03270* m_p;
    Ptr03270()
    {}
    ~Ptr03270()
    {}
};
struct Sub03270
{
    ~Sub03270();
};
struct FUN_00c03270 : Base03270
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    Table03270 m_18;
    Holder03270* m_1c;
    unsigned int unk20[14];
    Sub03270 m_58;

    ~FUN_00c03270();
};
extern unsigned char g_unk012023f0;
unsigned char __cdecl ImageSpaceEffectSunbeams_IsActive();
struct FUN_00c033c0
{
    FUN_00c033c0();
};
struct DestroyableReference
{
    virtual ~DestroyableReference();
};
struct Handle
{
    void FUN_00ba3a00();
};
struct HandlePool
{
    void MemoryManager_Deallocate(Handle* handle);
};
extern HandlePool DAT_011f6238;
struct RefMapEntries
{
    int m_zero;
    DestroyableReference* m_pHeadNode;
    int m_eight;
    DestroyableReference* m_third;
};
struct HandleMapEntries
{
    int m_zero;
    int m_four;
    Handle* m_iSecondInteger;
    Handle* m_third;
};
struct ElementMap
{
    int m_unknown;
    void* m_entries;
    int m_uiItemCount;
    int m_pRayCursor;
    void FUN_00ba3aa0(unsigned int index, int* newValue);
};
struct Entry
{
    int m_zero;
    int m_four;
    int m_eight;
    int m_twelve;
    ~Entry();
};
struct Parent
{
    virtual ~Parent();
};
struct FUN_00c03580 : Parent
{
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    ElementMap m_refs;
    ElementMap m_handles;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    Entry m_entries[2];

    ~FUN_00c03580();
};
extern float DAT_01202400;
extern float DAT_0120240c;
int __cdecl ImageSpaceEffectGetHit_IsActive();
class FUN_00c036f0_sub28;
class FUN_00c036f0_sub5c;
class FUN_00c036f0_sub28
{
  public:
    void FUN_00ba3aa0(int aiMode, FUN_00c036f0_sub5c** appRef);
};
class FUN_00c036f0_sub5c
{
  public:
    void ImageSpaceTexture_BorrowRenderedTexture(int aiValue);
};
class FUN_00c036f0_cls
{
  public:
    void InitSubObjects(int aUnused);
};
class SpawnedPrimary_c03a20
{
  public:
    virtual void Vslot00();
    int unk04, unk08, unk0C, unk10, unk14, unk18;
    int unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48;
    int unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68;
    virtual ~SpawnedPrimary_c03a20();
};
class SpawnedSecondary_c03a20
{
  public:
    virtual void Vslot00();
    int unk04, unk08, unk0C, unk10, unk14, unk18;
    int unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48;
    int unk4C, unk50, unk54;
    virtual ~SpawnedSecondary_c03a20();
};
class FUN_00c03a20_cls : public SpawnedPrimary_c03a20, public SpawnedSecondary_c03a20
{
  public:
    NiPointer<NiRefObject> m_c4;
    NiPointer<NiRefObject> m_c8;
    virtual ~FUN_00c03a20_cls();
};
struct ShaderObj
{
    virtual void Unused0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_iObjectReferenceCount) == 0)
            DeleteThis();
    }
};
struct ShaderDesc
{
    const char* m_pFile;
    int m_04;
};
void BuildShaderPath(const char* file, char* out);
int sprintf_s(char* buf, unsigned int size, const char* fmt, ...);
struct ShaderOwner
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
    NiPointer<ShaderObj> m_spVertexShaderObject;
    NiPointer<ShaderObj> m_spPixelShaderObject;

    ShaderObj* CreateVertexShader(char* path, int* desc, void* p, char* name);
    ShaderObj* CreatePixelShader(char* path, int* desc, void* p, char* name);
    void ImageSpaceShader_LoadShaders(ShaderDesc* vsDesc, ShaderDesc* psDesc, const char* name, void* vsArg, void* psArg);
};
// FUN_00c03d70 : copies a member into a global and returns.
//   mov eax,[ecx+0x5c] / mov [0x126f74c],eax / ret 4
extern int g_00c03d70;
struct Cls_00c03d70
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
    void __thiscall ImageSpaceShader_InitPass(int a);
};
struct FUN_00c04030_renderer
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c(int a, int b, int c, int d, int e);
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
};
struct FUN_00c04030_class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0(FUN_00c04030_renderer* renderer);

    void __thiscall SetupRenderer();
};
extern FUN_00c04030_renderer* DAT_011f9508;
FUN_00c04030_renderer* __cdecl NiDX9ShaderDeclaration_Create(FUN_00c04030_renderer* renderer, int a, int b);
// FUN_00c043f0: thiscall, one stack arg, two guarded virtual calls on this->m_30 / this->m_34.
struct B4630X;
struct B4630Y;
struct B4630Holder
{
    B4630X* m_00;
};
struct B4630G;
struct B4630X
{
    void* unk00_vptr;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    const char* m_20;
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
    int m_68;
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
    struct B4630Y* m_b8;
};
struct B4630Y
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
    int m_34;
};
struct B4630G
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
    void* m_44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    void* m_5c;
};
extern int DAT_011f91e0;
extern char DAT_011f4288;
struct B4630Obj
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
    virtual void v78(void* a0, void* a1, int a2, int a3, int a4, int a5, int a6, void* a7, const char* a8, int a9,
                     int a10);
};
class FUN_00c043f0_cls
{
  public:
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
    struct B4630Obj* m_30;
    struct B4630Obj* m_34;
    void __thiscall ImageSpaceShader_SetupGeometryConstants(int a1);
};
class C04620Object
{
  public:
    virtual ~C04620Object();
};
class C04620Base
{
  public:
    virtual ~C04620Base();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    NiTPrimitiveArray<C04620Object*> m_kThirdFollowingStreamField;
    NiTPrimitiveArray<C04620Object*> m_kTextureSwapList;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
};
class FUN_00c04620 : public C04620Base
{
  public:
    virtual ~FUN_00c04620();

    ImageSpaceTexture* m_pkTexture;
};
class FUN_00c048b0_base
{
  public:
    virtual void unk00();
    ~FUN_00c048b0_base();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct SpawnedSub18
{
    void unk00(int flag, unsigned int* pOut);
};
struct SpawnedSub68
{
    ~SpawnedSub68();
};
struct SpawnedInner
{
    virtual void Release(int flag);
};
class FUN_00c048b0 : public FUN_00c048b0_base
{
  public:
    virtual ~FUN_00c048b0();
    SpawnedSub18 m_18;
    SpawnedInner** m_1c;
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
    SpawnedSub68 m_68;
};
extern "C" int fnv_particle_shader_renderer_level;
extern bool g_bC04990Enabled;
class C04990Geometry
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
    float m_fAlpha;

    bool IsAlphaVisible();
};
extern float DAT_01016248;
extern void* DAT_010bcaac;
struct FUN_00ba4080_class
{
    void FUN_00ba4080();
    FUN_00ba4080_class()
    {
        FUN_00ba4080();
    }
    ~FUN_00ba4080_class();
};
struct FUN_00a90180_class
{
    unsigned int unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54;
    void FUN_00a90180(unsigned int);
};
struct FourFloats
{
    float x, y, z, w;
    FourFloats() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
    {}
    FourFloats(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
struct TailC049C0
{
    unsigned int flags;
    TailC049C0() : flags(0)
    {}
    ~TailC049C0();
};
struct FUN_00c049c0 : FUN_00ba4080_class
{
    void* vtable;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    FUN_00a90180_class region;
    FourFloats color;
    unsigned char m68, m69, m6a, m6b;
    unsigned int m6c, m70;
    TailC049C0 m74;
    FUN_00c049c0();
};
extern "C" void __cdecl FUN_00ba4080();
extern unsigned char DAT_010bcae8;
extern char str_011ae684;
extern unsigned char DAT_011ae694;
struct FUN_00c04d20_class
{
    void* m_vtbl;
    unsigned char pad04[0x54];
    unsigned char m_58;
    char* m_5c;
    unsigned char* m_60;
    unsigned int m_64;

    FUN_00c04d20_class();
};
struct FUN_00c050b0_cls
{
    char unk00[0x5];
    unsigned char m_05;
    char unk06[0x60 - 0x06];
    int m_60;
    int m_64;
    float m_68;
    float m_6c;
    float m_70;
    float m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;

    void Init(int a, unsigned int b);
};
struct S_00c05250_Obj
{
    virtual ~S_00c05250_Obj();
};
struct S_00c05250_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~S_00c05250_Elem();
};
struct _Base_00ba3d30
{
    virtual ~_Base_00ba3d30();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NiTPrimitiveArray<S_00c05250_Obj*> m_18;
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
};
struct FUN_00c05250 : _Base_00ba3d30
{
    S_00c05250_Elem m_5c[2];
    ~FUN_00c05250();
};
struct Property
{
    int value00;
    int value04;
    int value08;
    int value0c;
    void ImageSpaceTexture_BorrowRenderedTexture(int count);
};
struct PropertyCollection
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    void FUN_00ba3aa0(int index, Property** entry);
};
struct EffectProperties
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    PropertyCollection collection;
    Property first;
    Property second;
    void InitProperties(int unused);
};
// Constructor-like method: base call, vtable store, field init, flag bit.
struct FUN_00c05880_cls
{
    void* m_pVTable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int m_1c;
    unsigned int unk20;
    unsigned int m_24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int m_38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int m_58;
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
    unsigned int m_100;
    void FUN_00bb4520();
    FUN_00c05880_cls* InitializeFields_00c05880();
};
struct ShaderEntry
{
    unsigned int unknown00;
    unsigned int unknown04;
    void* value;
};
struct ShaderEntryTable
{
    unsigned int unknown00, unknown04, unknown08, unknown0c;
    unsigned int unknown10, unknown14, unknown18, unknown1c, unknown20;
    ShaderEntry** entries;
};
struct ShaderInterface
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void* GetValue(int kind, int flags);
};
struct ShaderUpdater
{
    void Lighting30Shader_SetTextureMode(ShaderEntry*, ShaderInterface*);
    void UpdateShaderEntry(ShaderEntryTable*, ShaderInterface*, int);
};
// CopyOwnerValuesToItems candidate
class Cb50Item
{
  public:
    unsigned int unk00;
    unsigned int m_04;
    unsigned int m_08;
};
class Cb50Hold
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Cb50Item* m_10;
    Cb50Item* m_14;
    Cb50Item* m_18;
};
class Cb50Ctx
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    Cb50Hold* m_24;
};
class Cb50Owner
{
  public:
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0c();
    virtual void vSlot10();
    virtual void vSlot14();
    virtual void vSlot18();
    virtual void vSlot1c();
    virtual void vSlot20();
    virtual void vSlot24();
    virtual void vSlot28();
    virtual void vSlot2c();
    virtual void vSlot30();
    virtual void vSlot34();
    virtual void vSlot38();
    virtual void vSlot3c();
    virtual void vSlot40();
    virtual void vSlot44();
    virtual void vSlot48();
    virtual void vSlot4c();
    virtual void vSlot50();
    virtual void vSlot54();
    virtual void vSlot58();
    virtual void vSlot5c();
    virtual void vSlot60();
    virtual void vSlot64();
    virtual void vSlot68();
    virtual void vSlot6c();
    virtual void vSlot70();
    virtual void vSlot74();
    virtual void vSlot78();
    virtual void vSlot7c();
    virtual void vSlot80();
    virtual void vSlot84();
    virtual void vSlot88();
    virtual void vSlot8c();
    virtual void vSlot90();
    virtual void vSlot94();
    virtual void vSlot98();
    virtual void vSlot9c();
    virtual void vSlota0();
    virtual void vSlota4();
    virtual void vSlota8();
    virtual void vSlotac();
    virtual void vSlotb0();
    virtual void vSlotb4();
    virtual void vSlotb8();
    virtual void vSlotbc();
    virtual void vSlotc0();
    virtual void vSlotc4();
    virtual void vSlotc8();
    virtual void vSlotcc();
    virtual void vSlotd0();
    virtual void vSlotd4();
    virtual void vSlotd8();
    virtual void vSlotdc();
    virtual void vSlote0();
    virtual void vSlote4();
    virtual void vSlote8();
    virtual void vSlotec();
    virtual void vSlotf0();
    virtual unsigned int vSlotf4(unsigned int a, unsigned int b);
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    Cb50Item* m_ac;
    Cb50Item* m_b0;
};
void __stdcall CopyOwnerValuesToItems(Cb50Ctx* ctx, Cb50Owner* owner, unsigned char flag);
struct S_00c0bba0_Dst
{
    int unk00;
    int unk04;
    int unk08;
};
struct S_00c0bba0_A
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
    S_00c0bba0_Dst** unk24;
};
struct S_00c0bba0_B
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
    int* unkb0;
};
extern int DAT_011f9510;
void __stdcall SetDstValueFromB(S_00c0bba0_A* a, S_00c0bba0_B* pValueHolder);
struct FUN_00c0bbd0_Value
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
};
struct FUN_00c0bbd0_Entry
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    FUN_00c0bbd0_Value* unk08;
    FUN_00c0bbd0_Value* unk0c;
};
struct FUN_00c0bbd0_Arg
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    char unk08;
    char unk09;
    char unk0a;
    char unk0b;
    char unk0c;
    char unk0d;
    char unk0e;
    char unk0f;
    char unk10;
    char unk11;
    char unk12;
    char unk13;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    char unk18;
    char unk19;
    char unk1a;
    char unk1b;
    char unk1c;
    char unk1d;
    char unk1e;
    char unk1f;
    char unk20;
    char unk21;
    char unk22;
    char unk23;
    FUN_00c0bbd0_Entry* unk24;
};
extern int DAT_011f95e4;
extern int DAT_011f95e8;
void __stdcall Lighting30Shader_SetProjShadowMaps(FUN_00c0bbd0_Arg* arg);
struct FNV_Target
{
    int unk00;
    int unk04;
    int m_p08;
};
struct FNV_Mid
{
    int unk00;
    FNV_Target* m_p04;
};
struct FNV_A1
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
    FNV_Mid* m_p24;
};
struct FNV_Node
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual void vF0();
    virtual int v3D(int a, int b);
    unsigned char Method15(int a);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_flags20;
};
struct FNV_Mgr
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
    int m_194;
};
extern unsigned int DAT_011f9544;
extern unsigned int DAT_011f95d4;
extern unsigned char DAT_011f9427;
FNV_Mgr* __cdecl Callee1();
void __stdcall SetNodeResultValue(FNV_A1* a1, FNV_Node* apNode, int aiCode);
struct C0BC90Texture;
struct C0BC90Geometry
{
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual C0BC90Texture* GetProperty(int iType, int iIndex);

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
    float m_fAlpha;
};
struct C0BC90TextureStage
{
    int unk00;
    int unk04;
    C0BC90Texture* m_pkTexture;
};
struct C0BC90StageList
{
    int unk00;
    int unk04;
    int unk08;
    C0BC90TextureStage* m_pkStage;
};
extern C0BC90Texture* g_pkC0BC90DefaultTexture;
class C0BC90ShaderBase
{
  public:
    void SetupTextureStage(C0BC90TextureStage* pkStage, C0BC90Geometry* pkGeometry);
};
class C0BC90Shader : public C0BC90ShaderBase
{
  public:
    static float ms_fTextureBlend;
    static float ms_fAlpha;

    void SetupPassTextureStage(NiD3DPass* pkPass, C0BC90Geometry* pkGeometry);
};
struct TexStage
{
    int unk00;
    int unk04;
    int m_08;
    int m_0c;
    int unk10[20];
    int m_iObjectReferenceCount;  // 0x60
    void ReturnToPool();
    void DecRef()
    {
        if (--m_iObjectReferenceCount == 0)
            ReturnToPool();
    }
};
struct TexStagePtr
{
    TexStage* m_p;
    TexStagePtr() : m_p(0)
    {}
    ~TexStagePtr()
    {
        if (m_p)
            m_p->DecRef();
    }
};
struct RefTex
{
    virtual void v00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
struct RenderStateGroup
{
    static RenderStateGroup* __cdecl GetFree();
    void SetRenderState(int state, int value, bool save);
};
struct ShaderPass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    RenderStateGroup* m_30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    RefTex* m_44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    RefTex* m_5c;
    int unk60;
    int m_iObjectReferenceCount;  // 0x64

    static void __cdecl CreateStage(TexStagePtr* out);
    void SetStage(unsigned int idx, TexStage* stage);
    void Destroy();

    RenderStateGroup* GetRSG()
    {
        if (m_30 == 0)
            m_30 = RenderStateGroup::GetFree();
        return m_30;
    }
};
void __cdecl SetupStage(TexStage* stage, unsigned int idx, int a, int b, int c);
extern int DAT_011f9534;
extern int DAT_011fd084;
extern int DAT_011fd088;
extern int DAT_011fd08c;
extern int DAT_011fd0b8;
extern int DAT_011fd0bc;
extern int DAT_011fd0e4;
extern int DAT_011fd0e8;
extern int DAT_011fd110;
extern int DAT_011fd114;
extern int DAT_011fc4a4;
extern int DAT_011fc4a8;
extern int DAT_011fc4ac;
extern int DAT_011fc4d8;
extern int DAT_011fc4dc;
extern int DAT_011fc504;
extern int DAT_011fc508;
extern int DAT_011fc530;
extern int DAT_011fc534;
struct ShaderPassPtr
{
    ShaderPass* m_p;
    ShaderPassPtr() : m_p(0)
    {}
    ~ShaderPassPtr()
    {
        if (m_p)
        {
            if (--m_p->m_iObjectReferenceCount == 0)
                m_p->Destroy();
        }
    }
    void operator=(const ShaderPassPtr& sp)
    {
        if (m_p != sp.m_p)
        {
            if (m_p)
            {
                if (--m_p->m_iObjectReferenceCount == 0)
                    m_p->Destroy();
            }
            m_p = sp.m_p;
            if (m_p)
                ++m_p->m_iObjectReferenceCount;
        }
    }
    ShaderPass* operator->() const
    {
        return m_p;
    }
};
extern ShaderPassPtr DAT_01202250;
extern ShaderPassPtr DAT_01202254;
extern ShaderPassPtr DAT_01202258;
extern ShaderPassPtr DAT_0120225c;
extern ShaderPassPtr DAT_01202260;
extern ShaderPassPtr DAT_01202264;
extern ShaderPassPtr DAT_01202268;
extern ShaderPassPtr DAT_0120226c;
extern ShaderPassPtr DAT_01202270;
static __forceinline void AssignTex(RefTex*& dst, RefTex* src)
{
    RefTex* old = dst;
    if (old != src)
    {
        if (old)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
        }
        dst = src;
        if (src)
            InterlockedIncrement(&src->m_iObjectReferenceCount);
    }
}
struct FUN_00c0e630_cls
{
    int unk00[0x8c / 4];
    RefTex* m_8c;
    RefTex* m_90;
    RefTex* m_94;
    RefTex* m_98;
    int unk9c[(0xdc - 0x9c) / 4];
    RefTex* m_dc;
    RefTex* m_e0;
    RefTex* m_e4;
    RefTex* m_e8;
    RefTex* m_ec;
    RefTex* m_f0;
    RefTex* m_f4;
    RefTex* m_f8;
    RefTex* m_fc;

    void ParallaxShader_PresetADTPasses_2x();
};
static __forceinline void SetupStages(ShaderPassPtr& spRenderPass, TexStagePtr& spStage)
{
    unsigned int n = spRenderPass->m_18;
    if (n < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 0, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
}
static __forceinline void SetupRenderStates(ShaderPassPtr& spRenderPass)
{
    spRenderPass->GetRSG()->SetRenderState(0x1b, 0, true);
    spRenderPass->GetRSG()->SetRenderState(0xf, 0, true);
    spRenderPass->GetRSG()->SetRenderState(7, 1, true);
    spRenderPass->GetRSG()->SetRenderState(0x17, 4, true);
    spRenderPass->GetRSG()->SetRenderState(0xe, 1, true);
}
struct RefHandle
{
    RefObject* object;
    explicit RefHandle(RefObject* ptr = 0) : object(ptr)
    {}
    ~RefHandle()
    {
        if (object != 0)
            object->DecRefCount(DAT_00fdf1c4);
    }
    operator RefObject*() const
    {
        return object;
    }
};
extern RefHandle DAT_011fda48[208];
RefObject* __cdecl Object_ProcessAndReturnValue_00c163a0(unsigned int index);
struct CpuOpaque;
extern CpuOpaque DAT_012024b8;
CpuOpaque* __cdecl TallGrassTriStrips_GetRTTI();
class C1A3B0Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};
struct C1A3B0Point3
{
    float x;
    float y;
    float z;
};
extern "C" C1A3B0Point3 _NiPoint3_ZERO;
class C1A3B0Bound
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return reinterpret_cast<C1A3B0Heap&>(g_memoryManager).Allocate(uiSize);
    }

    C1A3B0Bound& operator=(const C1A3B0Bound& kBound)
    {
        m_kCenter = kBound.m_kCenter;
        m_fBoundRadius = kBound.m_fBoundRadius;
        return *this;
    }

    const C1A3B0Point3& GetNavMeshData() const
    {
        return m_kCenter;
    }
    float GetRadius() const
    {
        return m_fBoundRadius;
    }
    void SetCenterAndRadius(const C1A3B0Point3& kTargetCenter, float fRadius)
    {
        m_kCenter = kTargetCenter;
        m_fBoundRadius = fRadius;
    }

    C1A3B0Point3 m_kCenter;
    float m_fBoundRadius;
};
class C1A3B0Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void SetObjectBound(C1A3B0Bound* pkBound);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    C1A3B0Bound* m_pkBound;
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
    C1A3B0Bound m_kWorldBound;

    void SetWorldBound(C1A3B0Bound kBound);
};
struct FUN_00c1a500_out
{
    unsigned int m_i00;
    unsigned int m_i04;
    unsigned int m_i08;
    float m_f0c;
};
class FUN_00c1a500_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    FUN_00c1a500_out* m_pOut20;
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
    unsigned short m_wC4;
    unsigned short unkC6;
    unsigned int m_iC8;
    unsigned int m_iCC;
    unsigned int m_iD0;
    float m_fD4;
    void FUN_00a71d30(unsigned int a1);
    void UpdateOutput(unsigned int a1);
};
class NiRenderer;
struct C1A550Point3
{
    float x;
    float y;
    float z;
};
class C1A550Bound
{
  public:
    const C1A550Point3& GetNavMeshData() const
    {
        return m_kCenter;
    }
    float GetRadius() const
    {
        return m_fBoundRadius;
    }
    void SetCenterAndRadius(const C1A550Point3& kTargetCenter, float fRadius)
    {
        m_kCenter = kTargetCenter;
        m_fBoundRadius = fRadius;
    }

    C1A550Point3 m_kCenter;
    float m_fBoundRadius;
};
class C1A550Object
{
  public:
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    C1A550Bound* m_pkBound;
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
    unsigned short m_usActive;
    unsigned short unkC6;
    C1A550Bound m_kWorldBound;

    void RenderImmediate(NiRenderer* pkRenderer);
    void RenderIfActive(NiRenderer* pkRenderer);
};
extern int DAT_012024c0;
int* __cdecl TallGrassTriShape_GetRTTI();
struct FUN_00c1a6a0_out
{
    int m_00;
    int m_04;
    int m_08;
    float m_0c;
};
struct FUN_00c1a6a0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FUN_00c1a6a0_out* m_pOutput;
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
    unsigned short m_c4;
    unsigned short unkC6;
    int m_c8;
    int m_cc;
    int m_d0;
    float m_d4;
    void CopyStateToOutput(int a1);
    void unkTail(int a1);
};
struct S_00c1a6f0_Dst
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    float f;
};
struct S_00c1a6f0_Self
{
    char p00[0x20];
    S_00c1a6f0_Dst* m_20;
    char p24[0xc4 - 0x24];
    unsigned short m_c4;
    char pc6[0xc8 - 0xc6];
    unsigned int m_c8;
    unsigned int m_cc;
    unsigned int m_d0;
    float m_d4;

    void __thiscall FUN_00a74600(int p);
    void __thiscall CopyStateToDestination(int p);
};
extern long g_liveObjectCount;
struct CountedObjectBase
{
    virtual ~CountedObjectBase();
    int m_iRefCount;

    CountedObjectBase()
    {
        m_iRefCount = 0;
        InterlockedIncrement((volatile long*)&g_liveObjectCount);
    }
};
struct FUN_00c1cf20 : CountedObjectBase
{
    int m_iValue;
    FUN_00c1cf20();
    virtual ~FUN_00c1cf20();
};
struct FUN_00c1f4e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned char m_b14;

    void __thiscall NiPSysModifier_SetActive(unsigned char value);
};
struct DecompPass266
{
    void* unk00;
    void* unk04;
    void* m_resource;
    void ApplyPairToState(unsigned int value);
    void NiD3DTextureStage_SetFilterMode(unsigned int value);
};
struct ShaderPasses
{
    DecompPass266* m_primary;
    DecompPass266* m_secondary;
    DecompPass266* m_tertiary;
};
struct GlobalShader
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    ShaderPasses* m_passes;
};
extern unsigned int DAT_011f91e4;
struct ObjectHandle
{
    void* m_object;
};
struct Renderer
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual unsigned int getProperty();
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    ObjectHandle* m_primary;
    ObjectHandle* m_secondary;
    unsigned short FUN_00b704b0();
};
struct TextureGenerator
{
    void* BSRenderedTexture_GetTexture(unsigned int code);
};
struct ShaderResource
{
    unsigned int unk00;
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned char m_bSlotEnabled;
    unsigned char unkED, unkEE, unkEF;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    TextureGenerator* m_generator;
};
struct ResourceHandle
{
    ShaderResource* m_resource;
};
struct RenderOptions
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned char unk08;
    unsigned char m_bSlotEnabled;
    unsigned short unk0a;
    ResourceHandle* m_handle;
};
void __stdcall ApplyRendererToShaderPasses(unsigned int opcode, Renderer* renderer);
struct C08
{
    float r, g, b;
};
struct V08
{
    float r, g, b, a;
};
extern C08 DAT_011f4998;
extern V08 DAT_011fa0c0;
struct M08c
{
    int unk00, unk04, unk08;
    float unk0c;
};
struct M08b
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    M08c* unk6c;
};
struct M08a
{
    int unk00;
    M08b* unk04;
};
struct M08
{
    int unk00, unk04;
    M08a* unk08;
};
extern M08* DAT_011f91ac;
struct L08
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    C08 color;
    C08* ptr;
    int unk38, unk3c;
    float dimmer;
};
void __stdcall AccumulateLightColor(L08* light);
struct FUN_00c05730_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FUN_00c046e0_holder* m_pHolder;
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
    float m_fRed;
    float m_fGreen;
    float m_fBlue;

    bool SetColor(int);
};
struct RefTex111
{
    virtual void Unused0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
struct ElemObj
{
    void __thiscall SetNodeValue(int a, int b, int c);
};
ElemObj* __cdecl FUN_00e7f5d0();
void __cdecl AssignStageFromPool(StageReturn*& p);
struct RefPtr
{
    RefTex111* m_pObject;
};
static __forceinline void AssignRef(RefTex111*& dst, RefTex111* src)
{
    RefTex111* old = dst;
    if (old != src)
    {
        if (old)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
        }
        dst = src;
        if (src)
            InterlockedIncrement(&src->m_iObjectReferenceCount);
    }
}
struct StagePtr
{
    StageReturn* m_pObject;
    StagePtr() : m_pObject(0)
    {}
    static __forceinline void Release(StageReturn* p)
    {
        --p->m_iObjectReferenceCount;
        if (p->m_iObjectReferenceCount == 0)
            p->ReturnToPool();
    }
    ~StagePtr()
    {
        if (m_pObject)
            Release(m_pObject);
    }
};
struct ClusterObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_18;
    unsigned int GetCount() const
    {
        return m_18;
    }
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    ElemObj* m_30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    RefPtr m_44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    RefPtr m_5c;
    unsigned int unk60;
    int m_64;
    void __thiscall NiD3DPass_SetStage(int idx, StageReturn* s);
    void __thiscall FUN_00e80190();
};
struct ClusterPtr
{
    ClusterObj* m_pObject;
    ClusterPtr() : m_pObject(0)
    {}
    ClusterObj* operator->()
    {
        return m_pObject;
    }
    void operator=(ClusterObj* const& p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
            {
                if (--m_pObject->m_64 == 0)
                    m_pObject->FUN_00e80190();
            }
            m_pObject = p;
            if (m_pObject)
                ++m_pObject->m_64;
        }
    }
    ~ClusterPtr()
    {
        if (m_pObject)
        {
            if (--m_pObject->m_64 == 0)
                m_pObject->FUN_00e80190();
        }
    }
};
struct StageFields
{
    unsigned int unk00;
    unsigned int unk04;
    int m_08;
    int m_0c;
};
extern ClusterObj* DAT_01202230;
extern ClusterObj* DAT_01202234;
extern ClusterObj* DAT_01202238;
extern ClusterObj* DAT_0120223c;
extern ClusterObj* DAT_01202240;
extern ClusterObj* DAT_01202244;
extern ClusterObj* DAT_01202248;
extern ClusterObj* DAT_0120224c;
extern int DAT_011f9534;
extern int DAT_011fcfe4;
extern int DAT_011fc404;
extern int DAT_011fcfe8;
extern int DAT_011fc408;
extern int DAT_011fd008;
extern int DAT_011fc428;
extern int DAT_011fd00c;
extern int DAT_011fc42c;
extern int DAT_011fd02c;
extern int DAT_011fc44c;
extern int DAT_011fd030;
extern int DAT_011fc450;
extern int DAT_011fd050;
extern int DAT_011fc470;
extern int DAT_011fd054;
extern int DAT_011fc474;
struct FUN_00c0d200_class
{
    unsigned int unk00;
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    RefTex111* m_ac;
    RefTex111* m_b0;
    RefTex111* m_b4;
    RefTex111* m_b8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    RefTex111* m_110;
    RefTex111* m_114;
    RefTex111* m_118;
    RefTex111* m_11c;
    RefTex111* m_120;
    RefTex111* m_124;
    RefTex111* m_128;
    RefTex111* m_12c;
    void InitClusterStages();
};
void __cdecl ConfigureBeamStage(FUN_00c0d200_class* self, int a, int b, int c, int d);
extern ShaderPassPtr DAT_01202294;
extern ShaderPassPtr DAT_01202298;
extern int DAT_011fd150;
extern int DAT_011fc570;
extern int DAT_011fd180;
extern int DAT_011fc5a0;
struct TargetShader
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    RefTex* m_bc;
    RefTex* m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    RefTex* m_130;
    RefTex* m_134;
    void ParallaxShader_PresetDiffusePtPasses_2x();
};
static __forceinline void SetupFourStages(ShaderPassPtr& pass, TexStagePtr& stage)
{
    unsigned int count = pass->m_18;
    if (count < 4)
    {
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(0, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 1, 1, 2, 1);
        pass->SetStage(1, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 2, 1, 2, 1);
        pass->SetStage(2, stage.m_p);
        ShaderPass::CreateStage(&stage);
        stage.m_p->m_08 = DAT_011f9534;
        stage.m_p->m_0c = 1;
        SetupStage(stage.m_p, 3, 3, 0, 1);
        pass->SetStage(3, stage.m_p);
    }
}
struct C16400Shader
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    RefTex* m_8c;
    RefTex* m_90;
    RefTex* m_94;
    RefTex* m_98;
    RefTex* m_9c;
    RefTex* m_a0;
    RefTex* m_a4;
    RefTex* m_a8;
    RefTex* m_ac;
    RefTex* m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    RefTex* m_104;
    RefTex* m_108;
    RefTex* m_10c;
    RefTex* m_110;
    RefTex* m_114;
    RefTex* m_118;
    RefTex* m_11c;
    RefTex* m_120;
    RefTex* m_124;
    RefTex* m_128;
    void SpeedTreeBranchShader_Func_87();
};
extern int DAT_011f950c;
extern int DAT_011f9534;
extern int DAT_011f9538;
extern int DAT_011faa40;
extern int DAT_011faa60;
extern int DAT_011faa70;
extern int DAT_011faac8;
extern int DAT_011faacc;
extern int DAT_011faad0;
extern int DAT_011faad8;
extern int DAT_011faadc;
extern int DAT_011fad90;
extern int DAT_011fad94;
extern int DAT_011fada0;
extern int DAT_011fada4;
extern int DAT_011fae08;
extern int DAT_011fae24;
extern int DAT_011fae30;
extern int DAT_011fae34;
extern int DAT_011fae40;
extern int DAT_011fae44;
extern int DAT_011fb228;
extern int DAT_011fb238;
extern int DAT_011fb620;
extern int DAT_011fb640;
extern int DAT_011fb650;
extern int DAT_011fb6a8;
extern int DAT_011fb6ac;
extern int DAT_011fb6b0;
extern int DAT_011fb6b8;
extern int DAT_011fb6bc;
extern int DAT_011fb970;
extern int DAT_011fb974;
extern int DAT_011fb980;
extern int DAT_011fb984;
extern int DAT_011fb9e8;
extern int DAT_011fba04;
extern int DAT_011fba10;
extern int DAT_011fba14;
extern int DAT_011fba20;
extern int DAT_011fba24;
extern int DAT_011fbe08;
extern int DAT_011fbe18;
extern int DAT_011fc200;
extern int DAT_011fc220;
extern int DAT_011fc230;
extern int DAT_011fc288;
extern int DAT_011fc28c;
extern int DAT_011fc290;
extern int DAT_011fc298;
extern int DAT_011fc29c;
extern int DAT_011fc550;
extern int DAT_011fc554;
extern int DAT_011fc560;
extern int DAT_011fc564;
extern int DAT_011fc5c8;
extern int DAT_011fc5e4;
extern int DAT_011fc5f0;
extern int DAT_011fc5f4;
extern int DAT_011fc600;
extern int DAT_011fc604;
extern int DAT_011fc9e8;
extern int DAT_011fc9f8;
extern int DAT_011fcde0;
extern int DAT_011fce00;
extern int DAT_011fce10;
extern int DAT_011fce68;
extern int DAT_011fce6c;
extern int DAT_011fce70;
extern int DAT_011fce78;
extern int DAT_011fce7c;
extern int DAT_011fd130;
extern int DAT_011fd134;
extern int DAT_011fd140;
extern int DAT_011fd144;
extern int DAT_011fd1a8;
extern int DAT_011fd1c4;
extern int DAT_011fd1d0;
extern int DAT_011fd1d4;
extern int DAT_011fd1e0;
extern int DAT_011fd1e4;
extern int DAT_011fd5c8;
extern int DAT_011fd5d8;
extern ShaderPassPtr DAT_01202350;
extern ShaderPassPtr DAT_01202354;
extern ShaderPassPtr DAT_01202358;
extern ShaderPassPtr DAT_0120235c;
extern ShaderPassPtr DAT_01202360;
extern ShaderPassPtr DAT_01202364;
extern ShaderPassPtr DAT_01202368;
extern ShaderPassPtr DAT_0120236c;
extern ShaderPassPtr DAT_01202370;
extern ShaderPassPtr DAT_01202374;
static __forceinline void SetupC16400Stages1(ShaderPassPtr& pass, TexStagePtr& stage)
{
    unsigned int count = pass->m_18;
    if (count < 1)
    {
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(pass->unk14, stage.m_p);
    }
}
static __forceinline void SetupC16400Stages2(ShaderPassPtr& pass, TexStagePtr& stage)
{
    unsigned int count = pass->m_18;
    if (count < 2)
    {
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(pass->unk14, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(pass->unk14, stage.m_p);
    }
}
static __forceinline void SetupC16400Stages4(ShaderPassPtr& pass, TexStagePtr& stage)
{
    unsigned int count = pass->m_18;
    if (count < 4)
    {
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 0, 1, 2, 1);
        pass->SetStage(pass->unk14, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 1, 3, 2, 1);
        stage.m_p->m_08 = DAT_011f9534;
        pass->SetStage(pass->unk14, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 2, 3, 2, 1);
        stage.m_p->m_08 = DAT_011f9538;
        pass->SetStage(pass->unk14, stage.m_p);
        ShaderPass::CreateStage(&stage);
        SetupStage(stage.m_p, 3, 1, 2, 1);
        stage.m_p->m_08 = DAT_011f950c;
        pass->SetStage(pass->unk14, stage.m_p);
    }
}
extern int _DAT_012024fc;
extern int _DAT_012024f8;
extern char UNK_00fdd3b0;
void __cdecl FUN_00ec658f(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
struct FNVSampler
{
    void __thiscall SetNodeValue(int attribute, int mode, int enabled);
};
struct FNVFace
{

    unsigned int unk000;

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

    void __thiscall NiD3DTextureStage_ReturnStageToPool();
    void DecRef()
    {
        if (--unk060 == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct FNVCubeSurface
{

    unsigned int unk00;

    unsigned int unk04;

    unsigned int unk08;

    unsigned int unk0c;

    unsigned int unk10;

    void* m_currentFace;

    unsigned int m_faceCount;

    unsigned int unk1c;

    unsigned int unk20;

    unsigned int unk24;

    unsigned int unk28;

    unsigned int unk2c;

    FNVSampler* m_sampler;

    unsigned int unk34;

    unsigned int unk38;

    unsigned int unk3c;

    unsigned int unk40;

    RefObject* m_colorTarget;

    unsigned int unk48;

    unsigned int unk4c;

    unsigned int unk50;

    unsigned int unk54;

    unsigned int unk58;

    RefObject* m_depthTarget;

    unsigned int unk60;

    unsigned int m_iObjectReferenceCount;

    unsigned int GetNumberOfFaces() const
    {
        return m_faceCount;
    }
    void __thiscall FUN_00e80190();

    void __thiscall NiD3DPass_SetStage(void* currentFace, FNVFace* replacement);
};
struct FNVRenderManager
{

    unsigned int unk000;

    unsigned int unk004;

    unsigned int m_faceFormat;

    unsigned int m_faceFlags;

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

    unsigned int unk0ac;

    unsigned int unk0b0;

    unsigned int unk0b4;

    unsigned int unk0b8;

    unsigned int unk0bc;

    unsigned int unk0c0;

    unsigned int unk0c4;

    RefObject* m_depthTarget0;

    RefObject* m_depthTarget1;

    RefObject* m_depthTarget2;

    RefObject* m_depthTarget3;

    RefObject* m_depthTarget4;

    unsigned int unk0dc;

    unsigned int unk0e0;

    unsigned int unk0e4;

    unsigned int unk0e8;

    unsigned int unk0ec;

    unsigned int unk0f0;

    unsigned int unk0f4;

    unsigned int unk0f8;

    unsigned int unk0fc;

    unsigned int unk100;

    unsigned int unk104;

    unsigned int unk108;

    unsigned int unk10c;

    unsigned int unk110;

    unsigned int unk114;

    unsigned int unk118;

    unsigned int unk11c;

    unsigned int unk120;

    unsigned int unk124;

    unsigned int unk128;

    unsigned int unk12c;

    unsigned int unk130;

    unsigned int unk134;

    unsigned int unk138;

    RefObject* m_colorTarget0;

    RefObject* m_colorTarget1;

    RefObject* m_colorTarget2;

    RefObject* m_colorTarget3;

    RefObject* m_colorTarget4;

    void __thiscall SetupCubeSurfaces();
};
extern FNVCubeSurface* DAT_012022a0;
extern FNVCubeSurface* DAT_012022a4;
extern FNVCubeSurface* DAT_012022a8;
extern FNVCubeSurface* DAT_012022ac;
extern FNVCubeSurface* DAT_012022b0;
extern unsigned int DAT_011fd1f0, DAT_011fd208, DAT_011fd220, DAT_011fd238, DAT_011fd250;
extern unsigned int DAT_011fc610, DAT_011fc628, DAT_011fc638, DAT_011fc640, DAT_011fc650, DAT_011fc658, DAT_011fc668,
    DAT_011fc670;
extern void __cdecl AssignStageFromPool(FNVFace** destination);
extern void __cdecl ConfigureBeamStage(FNVFace* target, int face, int enabled, int channel, int layer);
struct FNVFaceRef
{

    FNVFace* face;

    FNVFaceRef() : face(0)
    {}

    ~FNVFaceRef()
    {

        if (face)
            face->DecRef();
    }
};
struct FNVCubeRef
{

    FNVCubeSurface* surface;

    FNVCubeRef() : surface(0)
    {}

    ~FNVCubeRef()
    {
        if (surface && --surface->m_iObjectReferenceCount == 0)
            surface->FUN_00e80190();
    }

    void operator=(FNVCubeSurface* const& next)
    {

        if (surface == next)
            return;

        if (surface && --surface->m_iObjectReferenceCount == 0)
            surface->FUN_00e80190();

        surface = next;

        if (surface)
            ++surface->m_iObjectReferenceCount;
    }
};
static __forceinline void AssignTarget(RefObject*& dst, RefObject* src)
{
    RefObject* old = dst;
    if (old != src)
    {
        if (old && InterlockedDecrement((volatile long*)&old->m_iObjectReferenceCount) == 0)
            old->DeleteThis();
        dst = src;
        if (src)
            InterlockedIncrement((volatile long*)&src->m_iObjectReferenceCount);
    }
}
struct Color374
{
    float r, g, b, a;
    Color374(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha)
    {}
};
extern Color374 _DAT_011fa270;
extern unsigned char DAT_011F941E;
struct Settings374
{
    unsigned int unk00, unk04, unk08;
    float scale;
};
struct Material374
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    Settings374* settings;
};
struct Group374
{
    unsigned int unk00;
    Material374* material;
};
struct Manager374
{
    unsigned int unk00, unk04;
    Group374* group;
};
extern Manager374* _DAT_011f91ac;
struct Source374
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    NiPoint3 fallback;
    const NiPoint3* color;
    unsigned int unk38, unk3c;
    float multiplier;
};
void __stdcall ApplySourceColor(Source374* source);
extern "C" void __cdecl BSShaderManager_ReturnVelocityBuffers();
void __cdecl ImageSpaceEffectMotionBlur_Shutdown();
struct FUN_00c04da0 : _Base_00ba3d30
{
    ~FUN_00c04da0();
};
float __cdecl Runtime_EvaluateValue_00c05870();
extern "C" unsigned int __cdecl _rotl(unsigned int, int);
struct ConstantEntryStandin
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned flags;
};
class RefObjectStandin
{
  public:
    virtual ~RefObjectStandin();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <class T> class PointerStandin
{
  public:
    T* m_pObject;
    PointerStandin<T>& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct State
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
    PointerStandin<NiD3DShaderConstantMap> pixel;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    PointerStandin<NiD3DShaderConstantMap> vertex;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int refs;
    void DestroyState();
};
struct StatePtr
{
    State* p;
    StatePtr() : p(0)
    {}
    ~StatePtr()
    {
        if (p && --p->refs == 0)
            p->DestroyState();
    }
    StatePtr& operator=(const StatePtr& other)
    {
        if (p != other.p)
        {
            if (p && --p->refs == 0)
                p->DestroyState();
            p = other.p;
            if (p)
                ++p->refs;
        }
        return *this;
    }
};
extern StatePtr DAT_01200ec0[112];
extern unsigned DAT_01200a28[112];
extern unsigned DAT_01200868[112];
extern ConstantEntryStandin* DAT_01201080[17];
extern ConstantEntryStandin* DAT_012010c4[10];
struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* renderer;
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
    NiD3DShaderConstantMap* pixel;
    NiD3DShaderConstantMap* vertex;
    void InitShaderConstantMaps();
};
void __cdecl FUN_00a74640();
void __cdecl TallGrassTriShape_CreateClone();
extern "C" void _ReadWriteBarrier();
struct P440Light;
struct P440Pass;
struct P440Camera;
struct P440Renderer;
struct P440Material;
struct P440Geometry;
struct P440List;
struct P440Extra;
struct P440LightFlags;
struct P440Position
{
    float x, y, z, r;
};
struct P440Vector
{
    float x, y, z;
    float FUN_00457990();
};
struct P440LightFlags
{
    unsigned int unk00;
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
    unsigned int flags;
};
struct P440Light
{
    unsigned int unk00;
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    float alpha;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    bool special;
    char unked;
    short unkee;
    unsigned int unkf0;
    unsigned int unkf4;
    P440LightFlags* settings;
};
struct P440Pass
{
    unsigned int unk00;
    unsigned short shader;
    unsigned char blend;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char count;
    unsigned char capacity;
    unsigned char unk0b;
    P440Light** lights;
    void BSShaderProperty_RenderPass_ClearSceneLights();
    void AllocateElemArray(unsigned char);
};
struct P440List
{
    unsigned int unk00;
    P440Pass** passes;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int count;
    void FUN_00ba9ee0(P440Geometry*, unsigned int, bool, unsigned char, P440Light*, P440Light*, P440Light*, P440Light*);
};
struct P440Material
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    int skinned;
};
struct P440PropertyState
{
    P440LightFlags* flags;
    unsigned int unk04;
    P440Light* fade;
};
struct P440Geometry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    P440Position* position;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    P440PropertyState properties;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    P440Material* material;
    unsigned int unkbc;
};
struct P440Camera
{
    unsigned int unk00;
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    P440Light* defaultLight;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    float scale;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned char mode;
    char unk121;
    short unk122;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    P440Light* depthLight;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    P440Vector position;
    P440Vector GetPosition() const
    {
        return position;
    }
    const P440Vector& GetPositionRef() const
    {
        return position;
    }
};
struct P440Renderer
{
    unsigned int unk00;
    unsigned int unk04;
    P440Camera* active;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    int mode;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    float scale;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    P440Camera* camera;
    const P440Vector& GetCameraPosition() const
    {
        return camera->position;
    }
};
struct P440Extra
{
    unsigned int unk00;
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    int enabled;
};
struct P440Shader
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int flags;
    unsigned int flags2;
    float alpha;
    float opacity;
    unsigned int unk30;
    float distance;
    unsigned int cacheKey;
    P440List* passes;
    P440List* depthPasses;
    P440List* normalPasses;
    P440List* shadowPasses;
    unsigned int unk4c;
    unsigned int unk50;
    P440List* specialPasses;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    bool dirty;
    char unk75;
    short unk76;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    int* materialFlags;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    P440Extra* extra;
    __declspec(noinline) bool FUN_004a2020(int index)
    {
        unsigned int word = (unsigned int)index >> 5;
        unsigned int bit = (unsigned int)index % 32;
        return ((word == 0 ? flags : flags2) & (1u << bit)) > 0;
    }
    void BSShaderProperty_SetFlag(int, bool);
    void EnsureNewObj(int);
    void EnsureBa9740Obj(int);
    void EnsureAllocated(int);
    void CreateSpawnedObjectIfMissing(int);
    void FUN_00ba95e0(int);
    void BSShaderProperty_SetAlpha(float);
    void SortShadowSceneLights(P440Position*);
    P440Light* FUN_00b70590(void**);
    P440Light* BSShaderLightingProperty_GetNextActiveLight(void**);
    P440Light* BSShaderLightingProperty_GetFirstActiveNonShadowLight(void**);
    P440Light* BSShaderLightingProperty_GetNextActiveNonShadowLight(void**);
    P440List* GetPasses(P440Geometry*, unsigned int, int, unsigned int, P440Renderer*, int);
};
extern P440Renderer* DAT_011f4748;
extern float DAT_011f9458, DAT_011f9460, DAT_011f9468, DAT_011f946c;
extern float DAT_011f9470;
extern unsigned char DAT_011f91a7;
P440Renderer* __cdecl BSShaderManager_GetAccumulator();
bool __cdecl IsParticleShaderRendererEnabled();
int __cdecl GetGlobalFloatAsUInt();
bool __cdecl BSShaderManager_GetShadows();
float __cdecl LinearInterpolate(float, float, float, float, float);
struct FUN_00c02c30_Obj
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual unsigned short v3B();
    char p04[0xc4 - 4];
    unsigned char* m_c4;
};
extern unsigned int DAT_011a9bd0;
extern unsigned int DAT_011a9bd4;
extern unsigned int DAT_011a9bd8;
extern unsigned int DAT_011a9bdc;
extern unsigned int DAT_011fa2d0;
extern unsigned int DAT_011fa2d4;
extern unsigned int DAT_011fa2d8;
extern unsigned int DAT_011fa2dc;
struct S00c02c30_ColorA
{
    float r, g, b, a;
};
void __stdcall ShadowLightShader_UpdateTogglesConstantLand(unsigned int param_1, int param_2, FUN_00c02c30_Obj* param_3, int param_4);
int __stdcall ShadowLightShader_GetCubeMap(FNV_Node* a2, int a3);
struct S00c03c80_entry;
struct S00c03c80_item
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void v10() = 0;
    virtual void v14() = 0;
    virtual void v18() = 0;
    virtual void v1c() = 0;
    virtual void v20() = 0;
    virtual void v24() = 0;
    virtual void v28() = 0;
    virtual void v2c() = 0;
    virtual void v30() = 0;
    virtual void v34() = 0;
    virtual void v38() = 0;
    virtual void v3c() = 0;
    virtual void v40() = 0;
    virtual void v44() = 0;
    virtual void v48() = 0;
    virtual void v4c() = 0;
    virtual void v50() = 0;
    virtual void v54() = 0;
    virtual void v58() = 0;
    virtual void v5c() = 0;
    virtual void v60() = 0;
    virtual void v64() = 0;
    virtual void v68() = 0;
    virtual void v6c() = 0;
    virtual void v70() = 0;
    virtual void v74() = 0;
    virtual void v78() = 0;
    virtual void v7c() = 0;
    virtual void v80() = 0;
    virtual void v84() = 0;
    virtual void v88() = 0;
    virtual void v8c() = 0;
    virtual void v90() = 0;
    virtual int Get94();
    virtual int Get98();
};
struct S00c03c80_entry
{
    S00c03c80_item* __thiscall ImageSpaceTexture_GetTexture();
};
struct S00c03c80_meta
{
    int unk00;
    int unk04;
    int value08;
    void* value0c;
};
struct S00c03c80_provider
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void v10() = 0;
    virtual void v14() = 0;
    virtual void v18() = 0;
    virtual void v1c() = 0;
    virtual void v20() = 0;
    virtual void v24() = 0;
    virtual void v28() = 0;
    virtual void v2c() = 0;
    virtual void v30() = 0;
    virtual void v34() = 0;
    virtual void v38() = 0;
    virtual void v3c() = 0;
    virtual void v40() = 0;
    virtual void v44() = 0;
    virtual void v48() = 0;
    virtual void v4c() = 0;
    virtual void v50() = 0;
    virtual void v54() = 0;
    virtual void v58() = 0;
    virtual void v5c() = 0;
    virtual void v60() = 0;
    virtual void v64() = 0;
    virtual void v68() = 0;
    virtual void v6c() = 0;
    virtual void v70() = 0;
    virtual void v74() = 0;
    virtual void v78() = 0;
    virtual void v7c() = 0;
    virtual void v80() = 0;
    virtual void v84() = 0;
    virtual void v88() = 0;
    virtual void v8c() = 0;
    virtual void v90() = 0;
    virtual void v94() = 0;
    virtual void v98() = 0;
    virtual void v9c() = 0;
    virtual void va0() = 0;
    virtual void va4() = 0;
    virtual void va8() = 0;
    virtual void vac() = 0;
    virtual S00c03c80_meta* GetMeta(int);
};
struct S00c03c80_manager
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void v10() = 0;
    virtual void v14() = 0;
    virtual void v18() = 0;
    virtual void v1c() = 0;
    virtual void v20() = 0;
    virtual void v24() = 0;
    virtual void v28() = 0;
    virtual void v2c() = 0;
    virtual void v30() = 0;
    virtual void v34() = 0;
    virtual void v38() = 0;
    virtual void v3c() = 0;
    virtual void v40() = 0;
    virtual void v44() = 0;
    virtual void v48() = 0;
    virtual void v4c() = 0;
    virtual void v50() = 0;
    virtual void v54() = 0;
    virtual void v58() = 0;
    virtual void v5c() = 0;
    virtual void v60() = 0;
    virtual void v64() = 0;
    virtual void v68() = 0;
    virtual void v6c() = 0;
    virtual void v70() = 0;
    virtual void v74() = 0;
    virtual void v78() = 0;
    virtual void v7c() = 0;
    virtual void v80() = 0;
    virtual void v84() = 0;
    virtual void v88() = 0;
    virtual void v8c() = 0;
    virtual void v90() = 0;
    virtual void v94() = 0;
    virtual void v98() = 0;
    virtual void v9c() = 0;
    virtual void va0() = 0;
    virtual void va4() = 0;
    virtual void va8() = 0;
    virtual void vac() = 0;
    virtual void vb0() = 0;
    virtual void vb4() = 0;
    virtual void vb8() = 0;
    virtual void vbc() = 0;
    virtual void vc0() = 0;
    virtual void vc4() = 0;
    virtual S00c03c80_provider* GetProvider();
};
extern S00c03c80_manager* _DAT_011f4748;
struct S00c03c80_processor
{
    void __thiscall ImageSpaceShaderParam_SetTextureOffsets(unsigned int, int, void*);
};
struct S00c03c80_cls
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
    S00c03c80_entry** m_entries;
    unsigned short unk9c;
    unsigned short m_uiItemCount;
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
    S00c03c80_processor* m_processor;
    void __thiscall ProcessEntries();
};
struct S00c04f50_V4
{
    float x;
    float y;
    float z;
    float w;
};
struct S00c04f50_P3
{
    float x;
    float y;
    float z;

    S00c04f50_P3& operator=(const S00c04f50_P3& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        return *this;
    }
};
struct S00c04f50_Src
{
    S00c04f50_P3 pos;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
};
struct S00c04f50_I4
{
    int x;
    int y;
    int z;
    int w;
};
struct S00c04f50_Tmp
{
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
    float f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    float f28;
    float f2c;
    float f30;
    float f34;
};
struct S00c04f50_Mat
{
    S00c04f50_P3 m00;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
    float m30;
    float m31;
    float m32;
    float m33;
};
template <class T> inline T S00c04f50_Max(T a, T b)
{
    return (a > b) ? a : b;
}
struct S00c04f50_cls
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
    bool m_58;
    char unk59;
    char unk5a;
    char unk5b;
    S00c04f50_V4* m_5c;
    S00c04f50_Src* m_60;
    int unk64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    S00c04f50_Mat m_88;

    S00c04f50_Mat& ImageSpaceEffectCinematic_Func_08();
};
struct EffectBaseX
{
    int m_04;
    int m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c, m_50, m_54;
    virtual void vBase();
    EffectBaseX();
};
struct ZeroFour
{
    float m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger;
    __forceinline ZeroFour() : m_kPointA(0.0f), m_kPointB(0.0f), m_iThirdValue(0.0f), m_iFourthElementInteger(0.0f)
    {}
};
struct FUN_00c05680 : EffectBaseX
{
    ZeroFour m_zero;
    FUN_00c05680();
};
void EffectBaseX::vBase()
{}
namespace ShaderSelection {
struct Binding
{
    void FUN_00a5f860(void*);
};
extern void* DAT_01200ec0;
extern void* DAT_01200ec4;
extern void* DAT_01200ec8;
extern void* DAT_01200ecc;
extern void* DAT_01200ed0;
extern void* DAT_01200ed4;
extern void* DAT_01200ed8;
extern void* DAT_01200edc;
extern void* DAT_01200ee0;
extern void* DAT_01200ee4;
extern void* DAT_01200ee8;
extern void* DAT_01200eec;
extern void* DAT_01200ef0;
extern void* DAT_01200ef4;
extern void* DAT_01200ef8;
extern void* DAT_01200efc;
extern void* DAT_01200f00;
extern void* DAT_01200f04;
extern void* DAT_01200f08;
extern void* DAT_01200f0c;
extern void* DAT_01200f10;
extern void* DAT_01200f14;
extern void* DAT_01200f18;
extern void* DAT_01200f1c;
extern void* DAT_01200f20;
extern void* DAT_01200f24;
extern void* DAT_01200f28;
extern void* DAT_01200f2c;
extern void* DAT_01200f30;
extern void* DAT_01200f34;
extern void* DAT_01200f38;
extern void* DAT_01200f3c;
extern void* DAT_01200f40;
extern void* DAT_01200f44;
extern void* DAT_01200f48;
extern void* DAT_01200f4c;
extern void* DAT_01200f50;
extern void* DAT_01200f54;
extern void* DAT_01200f58;
extern void* DAT_01200f5c;
extern void* DAT_01200f60;
extern void* DAT_01200f64;
extern void* DAT_01200f68;
extern void* DAT_01200f6c;
extern void* DAT_01200f70;
extern void* DAT_01200f74;
extern void* DAT_01200f78;
extern void* DAT_01200f7c;
extern void* DAT_01200f80;
extern void* DAT_01200f84;
extern void* DAT_01200f88;
extern void* DAT_01200f8c;
extern void* DAT_01200f90;
extern void* DAT_01200f94;
extern void* DAT_01200f98;
extern void* DAT_01200f9c;
extern void* DAT_01200fa0;
extern void* DAT_01200fa4;
extern void* DAT_01200fa8;
extern void* DAT_01200fac;
extern void* DAT_01200fb0;
extern void* DAT_01200fb4;
extern void* DAT_01200fb8;
extern void* DAT_01200fbc;
extern void* DAT_01200fc0;
extern void* DAT_01200fc4;
extern void* DAT_01200fc8;
extern void* DAT_01200fcc;
extern void* DAT_01200fd0;
extern void* DAT_01200fd4;
extern void* DAT_01200fd8;
extern void* DAT_01200fdc;
extern void* DAT_01200fe0;
extern void* DAT_01200fe4;
extern void* DAT_01200fe8;
extern void* DAT_01200fec;
extern void* DAT_01200ff0;
extern void* DAT_01200ff4;
extern void* DAT_01200ff8;
extern void* DAT_01200ffc;
extern void* DAT_01201000;
extern void* DAT_01201004;
extern void* DAT_01201008;
extern void* DAT_0120100c;
extern void* DAT_01201010;
extern void* DAT_01201014;
extern void* DAT_01201018;
extern void* DAT_0120101c;
extern void* DAT_01201020;
extern void* DAT_01201024;
extern void* DAT_01201028;
extern void* DAT_0120102c;
extern void* DAT_01201030;
extern void* DAT_01201034;
extern void* DAT_01201038;
extern void* DAT_0120103c;
extern void* DAT_01201040;
extern void* DAT_01201044;
extern void* DAT_01201048;
extern void* DAT_0120104c;
extern void* DAT_01201050;
extern void* DAT_01201054;
extern void* DAT_01201058;
extern void* DAT_0120105c;
extern void* DAT_01201060;
extern void* DAT_01201064;
extern void* DAT_01201068;
extern void* DAT_0120106c;
extern void* DAT_01201070;
extern void* DAT_01201074;
extern void* DAT_01201078;
extern void* DAT_0120107c;
struct Shader
{
    void* field0;
    void* field4;
    void* field8;
    void* fieldc;
    void* field10;
    void* field14;
    void* field18;
    void* field1c;
    void* field20;
    void* field24;
    Binding binding;
    void* field2c;
    void* field30;
    void* field34;
    void* field38;
    void* field3c;
    void* field40;
    void* field44;
    void* field48;
    void* field4c;
    void* field50;
    void* field54;
    void* field58;
    void* field5c;
    void* field60;
    void* field64;
    void* field68;
    void* field6c;
    void* field70;
    void* field74;
    void* field78;
    void* field7c;
    void* field80;
    void* field84;
    void* field88;
    void* field8c;
    void* field90;
    void* field94;
    void* Lighting30Shader_SelectPass(unsigned int);
};
// @fnv 0x00c0abd0
// src: COMMUNITY 0x00c0abd0
void* Shader::Lighting30Shader_SelectPass(unsigned int pass)
{
    void* result = 0;
    switch (pass)
    {
    case 10:
        result = DAT_01200ec4;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 11:
        result = DAT_01200ec8;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 12:
        result = DAT_01200ecc;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 13:
        result = DAT_01200ed0;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 14:
        result = DAT_01200ed4;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 15:
        result = DAT_01200ed8;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 376:
        result = DAT_01200ec0;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 383:
        result = DAT_01200edc;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 384:
        result = DAT_01200ee0;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 385:
        result = DAT_01200ee4;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 386:
        result = DAT_01200ee8;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 387:
        result = DAT_01200eec;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 388:
        result = DAT_01200ef0;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 389:
        result = DAT_01200ef4;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 390:
        result = DAT_01200ef8;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 391:
        result = DAT_01200efc;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 392:
        result = DAT_01200f00;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 393:
        result = DAT_01200f04;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 394:
        result = DAT_01200f08;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 395:
        result = DAT_01200f0c;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 396:
        result = DAT_01200f10;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 397:
        result = DAT_01200f14;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 398:
        result = DAT_01200f18;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 399:
        result = DAT_01200f1c;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 400:
        result = DAT_01200f20;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 401:
        result = DAT_01200f24;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 402:
        result = DAT_01200f28;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 403:
        result = DAT_01200f2c;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 404:
        result = DAT_01200f30;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 405:
        result = DAT_01200f34;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 406:
        result = DAT_01200f38;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 407:
        result = DAT_01200f3c;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 408:
        result = DAT_01200f40;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 409:
        result = DAT_01200f44;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 410:
        result = DAT_01200f48;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 411:
        result = DAT_01200f4c;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 412:
        result = DAT_01200f50;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 413:
        result = DAT_01200f54;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 414:
        result = DAT_01200f58;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 415:
        result = DAT_01200f5c;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 416:
        result = DAT_01200f60;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 417:
        result = DAT_01200f64;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 418:
        result = DAT_01200f68;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 419:
        result = DAT_01200f6c;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 420:
        result = DAT_01200f70;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 421:
        result = DAT_01200f74;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 422:
        result = DAT_01200f78;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 423:
        result = DAT_01200f7c;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 424:
        result = DAT_01200f80;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 425:
        result = DAT_01200f84;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 426:
        result = DAT_01200f88;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 427:
        result = DAT_01200f8c;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 428:
        result = DAT_01200f90;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 429:
        result = DAT_01200f94;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 430:
        result = DAT_01200f98;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 431:
        result = DAT_01200f9c;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 432:
        result = DAT_01200fa0;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 433:
        result = DAT_01200fa4;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 434:
        result = DAT_01200fa8;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 435:
        result = DAT_01200fac;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 436:
        result = DAT_01200fb0;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 437:
        result = DAT_01200fb4;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 438:
        result = DAT_01200fb8;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 439:
        result = DAT_01200fbc;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 440:
        result = DAT_01200fc0;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 441:
        result = DAT_01200fc4;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 442:
        result = DAT_01200fc8;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 445:
        result = DAT_01200fd4;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 446:
        result = DAT_01200fd8;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 447:
        result = DAT_01200fdc;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 448:
        result = DAT_01200fe0;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 449:
        result = DAT_01200fe4;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 450:
        result = DAT_01200fe8;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 451:
        result = DAT_01200fec;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 730:
        result = DAT_01201060;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 731:
        result = DAT_01201064;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 736:
        result = DAT_01201068;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 737:
        result = DAT_0120106c;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 742:
        result = DAT_01201070;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 743:
        result = DAT_01201074;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 748:
        result = DAT_01201078;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 749:
        result = DAT_0120107c;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 452:
        result = DAT_01200ff0;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 453:
        result = DAT_01200ff4;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 454:
        result = DAT_01200ff8;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 455:
        result = DAT_01200ffc;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 480:
        result = DAT_01201058;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 481:
        result = DAT_0120105c;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 456:
        binding.FUN_00a5f860(field7c);
        result = DAT_01201000;
        goto finished;
    case 457:
        binding.FUN_00a5f860(field84);
        result = DAT_01201004;
        goto finished;
    case 458:
        result = DAT_01201008;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 459:
        result = DAT_0120100c;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 460:
        binding.FUN_00a5f860(field7c);
        result = DAT_01201010;
        goto finished;
    case 461:
        binding.FUN_00a5f860(field84);
        result = DAT_01201010;
        goto finished;
    case 462:
        result = DAT_01201014;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 463:
        result = DAT_01201014;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 464:
        binding.FUN_00a5f860(field7c);
        result = DAT_01201018;
        goto finished;
    case 465:
        binding.FUN_00a5f860(field7c);
        result = DAT_0120101c;
        goto finished;
    case 466:
        result = DAT_01201020;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 443:
        result = DAT_01200fcc;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 444:
        result = DAT_01200fd0;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 467:
        result = DAT_01201024;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 468:
        result = DAT_01201028;
        binding.FUN_00a5f860(field84);
        goto finished;
    case 469:
        result = DAT_0120102c;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 470:
        result = DAT_01201030;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 471:
        binding.FUN_00a5f860(field7c);
        result = DAT_01201034;
        goto finished;
    case 472:
        binding.FUN_00a5f860(field84);
        result = DAT_01201038;
        goto finished;
    case 473:
        result = DAT_0120103c;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 474:
        result = DAT_01201040;
        binding.FUN_00a5f860(field94);
        goto finished;
    case 475:
        result = DAT_01201044;
        binding.FUN_00a5f860(field7c);
        goto finished;
    case 476:
        result = DAT_01201048;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 477:
        binding.FUN_00a5f860(field7c);
        result = DAT_0120104c;
        goto finished;
    case 478:
        result = DAT_01201050;
        binding.FUN_00a5f860(field8c);
        goto finished;
    case 479:
        binding.FUN_00a5f860(field7c);
        result = DAT_01201054;
        goto finished;
    }
finished:
    return result;
}
}
struct TextureReceiver
{
    TextureReceiver* BSRenderedTexture_GetTexture(int code);
};
struct C0CD80Pass
{
    unsigned int NiD3DTextureStage_SetFilterMode(unsigned int code);
    unsigned int ApplyPairToState(unsigned int code);
};
struct C0CD80Rdr
{
    unsigned short FUN_00b704b0();
};
struct C0CD80Item
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8;
    unsigned char unkEC;
    int unkF0, unkF4, unkF8, unkFC, unk100, unk104, unk108;
    TextureReceiver* m_gen;
};
struct C0CD80Mgr
{
    unsigned char unk00, unk01, unk02, unk03, unk04, unk05, unk06, unk07, unk08, unk09;
    C0CD80Item** m_kNode;
};
extern unsigned int DAT_011f91b0;
extern long DAT_01201c7c;
struct C0CD80Shader
{
    void Lighting30Shader_SetTextureMode(ShaderEntry* entry, ShaderInterface* iface);
    void Lighting30Shader_UpdateDiffuseNormalStages(unsigned int technique, Renderer* renderer);
};
struct SplatterItem
{
    int unk00;
    int unk04;
};
struct SplatterGeom
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8;
    SplatterItem* unkAC;
    SplatterItem* unkB0;
    int* unkB4;
};
struct BloodUpdater : ShaderUpdater
{
    void SetupTextureStages(SplatterGeom* geom, ShaderEntryTable* table);
    void ApplyTextureStages(SplatterGeom* geom, ShaderEntryTable* table);
    void Lighting30Shader_SetProjShadowMaps(ShaderEntryTable* table);
    void CopyOwnerValuesToItems(ShaderEntryTable* table, SplatterGeom* geom, int flag);
    void SetNodeResultValue(ShaderEntryTable* table, SplatterGeom* geom, int kind);
    void ApplyTextureStage(ShaderEntryTable* table, SplatterGeom* geom, int zero);
    void SetDstValueFromB(ShaderEntryTable* table, SplatterGeom* geom);
    void Lighting30Shader_SetHairMaps(ShaderEntryTable* table, SplatterGeom* geom);
    void SetupPassTextureStage(ShaderEntryTable* table, SplatterGeom* geom);
    void Lighting30Shader_UpdatePassTextureStages(unsigned int kind, SplatterGeom* geom);
};
extern ClusterObj* DAT_01202230;
extern "C" void __cdecl FUN_00e804d0(void* pSlot);
struct C0D170Self
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void at158();
    bool ProcessEntries_00c0d170();
};
struct ColorA_c1a310
{
    float r, g, b, a;
};
struct Obj_c1a310
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
    float unk38;
};
void __stdcall SpeedTreeBranchShader_UpdateTogglesConstant(int a, int b, Obj_c1a310* p);
extern "C" void __cdecl CreateTriStripsObject();
void __cdecl TallGrassTriStrips_CreateClone();
namespace ShaderBias {
struct RefObject
{
    virtual void slot0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
    }
};
struct RenderStateBlock
{
    void SetNodeValue(unsigned int, unsigned int, bool);
};
RenderStateBlock* FUN_00e7f5d0();
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    int references;
    void NiD3DTextureStage_ReturnStageToPool();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void AssignStageFromPool(ShaderStagePointer*);
void ConfigureBeamStage(ShaderStage*, unsigned int, unsigned int, unsigned int, bool);
extern unsigned int DAT_011f9534;
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    void FUN_00e80190();
    void NiD3DPass_SetStage(unsigned int, ShaderStage*);
    __forceinline RenderStateBlock* const& GetState()
    {
        if (!state)
            state = FUN_00e7f5d0();
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            object->FUN_00e80190();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                object->FUN_00e80190();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern float DAT_01200458;
extern ShaderPass* DAT_011feb58;
extern RefObject *DAT_011fdfcc, *DAT_011fdc70;
extern unsigned int DAT_011fd7e0, DAT_011fcc00;
extern ShaderPass* DAT_011feb5c;
extern RefObject *DAT_011fdfd0, *DAT_011fdc70;
extern unsigned int DAT_011fd7e4, DAT_011fcc04;
extern ShaderPass* DAT_011feb70;
extern RefObject *DAT_011fdfd4, *DAT_011fdc74;
extern unsigned int DAT_011fd7f8, DAT_011fcc18;
extern ShaderPass* DAT_011feb74;
extern RefObject *DAT_011fdfd8, *DAT_011fdc74;
extern unsigned int DAT_011fd7fc, DAT_011fcc1c;
extern ShaderPass* DAT_011feb88;
extern RefObject *DAT_011fdfdc, *DAT_011fdc70;
extern unsigned int DAT_011fd810, DAT_011fcc30;
extern ShaderPass* DAT_011feb8c;
extern RefObject *DAT_011fdfe0, *DAT_011fdc70;
extern unsigned int DAT_011fd814, DAT_011fcc34;
extern ShaderPass* DAT_011feba0;
extern RefObject *DAT_011fdfe4, *DAT_011fdc74;
extern unsigned int DAT_011fd828, DAT_011fcc48;
extern ShaderPass* DAT_011feba4;
extern RefObject *DAT_011fdfe8, *DAT_011fdc74;
extern unsigned int DAT_011fd82c, DAT_011fcc4c;
inline unsigned int FloatBits(float value)
{
    return *(unsigned int*)&value;
}
// @fnv 0x00c02340
// src: COMMUNITY 0x00c02340
void ShadowLightShader_PresetWaterFogPasses_2x()
{
    ShaderPassPointer pass;
    ShaderStagePointer stage;
    pass = DAT_011feb58;
    pass->vertexShader = DAT_011fdfcc;
    pass->pixelShader = DAT_011fdc70;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd7e0 = 16388;
    DAT_011fcc00 = 0x140040;
    pass = DAT_011feb5c;
    pass->vertexShader = DAT_011fdfd0;
    pass->pixelShader = DAT_011fdc70;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd7e4 = 34816;
    DAT_011fcc04 = 0x140040;
    pass = DAT_011feb70;
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 1, 2, true);
    pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    pass->vertexShader = DAT_011fdfd4;
    pass->pixelShader = DAT_011fdc74;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd7f8 = 16388;
    DAT_011fcc18 = 0x140040;
    pass = DAT_011feb74;
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 1, 2, true);
    pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    pass->vertexShader = DAT_011fdfd8;
    pass->pixelShader = DAT_011fdc74;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd7fc = 34816;
    DAT_011fcc1c = 0x140040;
    pass = DAT_011feb88;
    pass->vertexShader = DAT_011fdfdc;
    pass->pixelShader = DAT_011fdc70;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd810 = 16388;
    DAT_011fcc30 = 0x140040;
    pass = DAT_011feb8c;
    pass->vertexShader = DAT_011fdfe0;
    pass->pixelShader = DAT_011fdc70;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd814 = 34816;
    DAT_011fcc34 = 0x140040;
    pass = DAT_011feba0;
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 1, 2, true);
    pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    pass->vertexShader = DAT_011fdfe4;
    pass->pixelShader = DAT_011fdc74;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd828 = 16388;
    DAT_011fcc48 = 0x140040;
    pass = DAT_011feba4;
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 1, 2, true);
    pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    pass->vertexShader = DAT_011fdfe8;
    pass->pixelShader = DAT_011fdc74;
    pass->GetState()->SetNodeValue(168, 3, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd82c = 34816;
    DAT_011fcc4c = 0x140040;
}
}
struct __declspec(novtable) ISBaseA
{
    virtual ~ISBaseA();
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
    void FUN_00be2200();
    void FUN_00be0870();
    ISBaseA()
    {
        FUN_00be2200();
    }
};
struct __declspec(novtable) ISBaseB
{
    virtual ~ISBaseB();
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
    void FUN_00ba4080();
    ISBaseB()
    {
        FUN_00ba4080();
    }
};
struct ISRefObj
{
    int unk00;
};
struct ISPtr
{
    ISRefObj* m_p;
    ISPtr() : m_p(0)
    {}
    ~ISPtr();
};
struct ISEffect : ISBaseA, ISBaseB
{
    ISPtr unkc4;
    ISPtr unkc8;
    virtual ~ISEffect();
    void SetupRenderer();
    ISEffect();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
struct Pass04120
{
    StageReturn* m_pObject;
    Pass04120() : m_pObject(0)
    {}
    ~Pass04120()
    {
        if (m_pObject && --m_pObject->m_iObjectReferenceCount == 0)
            m_pObject->ReturnToPool();
    }
};
void __cdecl FUN_00e804d0(void*);
void __cdecl AssignStageFromPool(Pass04120*);
void __cdecl ConfigureBeamStage(StageReturn*, unsigned int, int, int, int);
struct Target04120
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
    virtual void Configure();

    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    NiD3DPass* m_shader;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98;
    unsigned short m_stageCount;
    unsigned short unk9e;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    NiRefObject* m_texture;
    NiRefObject* m_property;

    bool ConfigureBeam();
};

extern int DAT_011fab34;
extern int DAT_011fab5c;
extern int DAT_011fab60;
extern int DAT_011fab88;
extern int DAT_011fab8c;
extern int DAT_011fabb4;
extern int DAT_011fabb8;
extern int DAT_011fabe0;
extern int DAT_011fac3c;
extern int DAT_011fac5c;
extern int DAT_011fac60;
extern int DAT_011fac80;
extern int DAT_011fac84;
extern int DAT_011faca4;
extern int DAT_011faca8;
extern int DAT_011facc8;
extern int DAT_011faccc;
extern int DAT_011fad00;
extern int DAT_011fad08;
extern int DAT_011fad30;
extern int DAT_011fad38;
extern int DAT_011fad5c;
extern int DAT_011fad64;
extern int DAT_011fad88;
extern int DAT_011fada8;
extern int DAT_011fadbc;
extern int DAT_011fadd8;
extern int DAT_011fadec;
extern int DAT_011fae48;
extern int DAT_011fae5c;
extern int DAT_011fae60;
extern int DAT_011fae74;
extern int DAT_011fb1a4;
extern int DAT_011fb1b0;
extern int DAT_011fb714;
extern int DAT_011fb73c;
extern int DAT_011fb740;
extern int DAT_011fb768;
extern int DAT_011fb76c;
extern int DAT_011fb794;
extern int DAT_011fb798;
extern int DAT_011fb7c0;
extern int DAT_011fb81c;
extern int DAT_011fb83c;
extern int DAT_011fb840;
extern int DAT_011fb860;
extern int DAT_011fb864;
extern int DAT_011fb884;
extern int DAT_011fb888;
extern int DAT_011fb8a8;
extern int DAT_011fb8ac;
extern int DAT_011fb8e0;
extern int DAT_011fb8e8;
extern int DAT_011fb910;
extern int DAT_011fb918;
extern int DAT_011fb93c;
extern int DAT_011fb944;
extern int DAT_011fb968;
extern int DAT_011fb988;
extern int DAT_011fb99c;
extern int DAT_011fb9b8;
extern int DAT_011fb9cc;
extern int DAT_011fba28;
extern int DAT_011fba3c;
extern int DAT_011fba40;
extern int DAT_011fba54;
extern int DAT_011fbd84;
extern int DAT_011fbd90;
extern int DAT_011fc2f4;
extern int DAT_011fc31c;
extern int DAT_011fc320;
extern int DAT_011fc348;
extern int DAT_011fc34c;
extern int DAT_011fc374;
extern int DAT_011fc378;
extern int DAT_011fc3a0;
extern int DAT_011fc3fc;
extern int DAT_011fc41c;
extern int DAT_011fc420;
extern int DAT_011fc440;
extern int DAT_011fc444;
extern int DAT_011fc464;
extern int DAT_011fc468;
extern int DAT_011fc488;
extern int DAT_011fc48c;
extern int DAT_011fc4c0;
extern int DAT_011fc4c8;
extern int DAT_011fc4f0;
extern int DAT_011fc4f8;
extern int DAT_011fc51c;
extern int DAT_011fc524;
extern int DAT_011fc548;
extern int DAT_011fc568;
extern int DAT_011fc57c;
extern int DAT_011fc598;
extern int DAT_011fc5ac;
extern int DAT_011fc608;
extern int DAT_011fc61c;
extern int DAT_011fc620;
extern int DAT_011fc634;
extern int DAT_011fc64c;
extern int DAT_011fc664;
extern int DAT_011fc67c;
extern int DAT_011fc964;
extern int DAT_011fc970;
extern int DAT_011fced4;
extern int DAT_011fcefc;
extern int DAT_011fcf00;
extern int DAT_011fcf28;
extern int DAT_011fcf2c;
extern int DAT_011fcf54;
extern int DAT_011fcf58;
extern int DAT_011fcf80;
extern int DAT_011fcfdc;
extern int DAT_011fcffc;
extern int DAT_011fd000;
extern int DAT_011fd020;
extern int DAT_011fd024;
extern int DAT_011fd044;
extern int DAT_011fd048;
extern int DAT_011fd068;
extern int DAT_011fd06c;
extern int DAT_011fd0a0;
extern int DAT_011fd0a8;
extern int DAT_011fd0d0;
extern int DAT_011fd0d8;
extern int DAT_011fd0fc;
extern int DAT_011fd104;
extern int DAT_011fd128;
extern int DAT_011fd148;
extern int DAT_011fd15c;
extern int DAT_011fd178;
extern int DAT_011fd18c;
extern int DAT_011fd1e8;
extern int DAT_011fd1fc;
extern int DAT_011fd200;
extern int DAT_011fd214;
extern int DAT_011fd218;
extern int DAT_011fd22c;
extern int DAT_011fd230;
extern int DAT_011fd244;
extern int DAT_011fd248;
extern int DAT_011fd25c;
extern int DAT_011fd544;
extern int DAT_011fd550;
extern RefTex* DAT_011fdb08;
extern RefTex* DAT_011fdb1c;
extern RefTex* DAT_011fdb34;
extern RefTex* DAT_011fdb40;
extern RefTex* DAT_011fdb4c;
extern RefTex* DAT_011fdb58;
extern RefTex* DAT_011fdb64;
extern RefTex* DAT_011fdb70;
extern RefTex* DAT_011fdb9c;
extern RefTex* DAT_011fdba4;
extern RefTex* DAT_011fdbac;
extern RefTex* DAT_011fdbb4;
extern ShaderPassPtr DAT_01202378;
extern ShaderPassPtr DAT_0120237c;
extern ShaderPassPtr DAT_01202380;
extern ShaderPassPtr DAT_01202384;
extern ShaderPassPtr DAT_01202388;
extern ShaderPassPtr DAT_0120238c;
extern ShaderPassPtr DAT_01202390;
extern ShaderPassPtr DAT_01202394;
extern ShaderPassPtr DAT_01202398;
extern ShaderPassPtr DAT_0120239c;
extern ShaderPassPtr DAT_012023a0;
extern ShaderPassPtr DAT_012023a4;
extern ShaderPassPtr DAT_012023a8;
extern ShaderPassPtr DAT_012023ac;
extern ShaderPassPtr DAT_012023b0;
extern ShaderPassPtr DAT_012023b4;
extern ShaderPassPtr DAT_012023b8;
extern ShaderPassPtr DAT_012023bc;
extern ShaderPassPtr DAT_012023c0;
extern ShaderPassPtr DAT_012023c4;
struct ShaderHandle
{
    RefTex* value;
};
struct PassMethods : ShaderPass
{
    void SetPixelShader(ShaderHandle);
    void SetVertexShader(RefTex*);
    void SetBlend(int source, int destination, bool save);
};
struct LocalPassPtr
{
    ShaderPass* m_p;
    LocalPassPtr()
    {
        *reinterpret_cast<ShaderPass* volatile*>(&m_p) = 0;
        m_p = 0;
    }
    void operator=(const ShaderPassPtr& sp)
    {
        if (m_p != sp.m_p)
        {
            if (m_p)
            {
                if (--m_p->m_iObjectReferenceCount == 0)
                    m_p->Destroy();
            }
            m_p = sp.m_p;
            if (m_p)
                ++m_p->m_iObjectReferenceCount;
        }
    }
    ~LocalPassPtr()
    {
        if (m_p && --m_p->m_iObjectReferenceCount == 0)
            m_p->Destroy();
    }
    ShaderPass* operator->() const
    {
        return m_p;
    }
    operator ShaderPassPtr&()
    {
        return reinterpret_cast<ShaderPassPtr&>(*this);
    }
};
struct C17510Shader
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
    RefTex* m_b4;
    RefTex* m_b8;
    RefTex* m_bc;
    RefTex* m_c0;
    RefTex* m_c4;
    RefTex* m_c8;
    RefTex* m_cc;
    RefTex* m_d0;
    RefTex* m_d4;
    RefTex* m_d8;
    RefTex* m_dc;
    RefTex* m_e0;
    RefTex* m_e4;
    RefTex* m_e8;
    RefTex* m_ec;
    RefTex* m_f0;
    RefTex* m_f4;
    RefTex* m_f8;
    RefTex* m_fc;
    RefTex* m_100;
    void SpeedTreeBranchShader_Func_88();
};

// @fnv 0x00c17510
// src: COMMUNITY 0x00c17510
void C17510Shader::SpeedTreeBranchShader_Func_88()
{
    LocalPassPtr spRenderPass;
    TexStagePtr spStage;

    // Shader pass 0.
    spRenderPass = DAT_01202378;
    unsigned int count0 = spRenderPass->m_18;
    if (count0 < 7)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 3, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_b4);
    AssignTex(spRenderPass->m_44, DAT_011fdb9c);
    SetupRenderStates(spRenderPass);
    DAT_011fcffc = DAT_011fcfdc;
    DAT_011fc41c = DAT_011fc3fc;
    DAT_011fb83c = DAT_011fb81c;
    DAT_011fac5c = DAT_011fac3c;

    // Shader pass 1.
    spRenderPass = DAT_0120237c;
    if (spRenderPass->m_18 < 7)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 3, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_b8);
    AssignTex(spRenderPass->m_44, DAT_011fdba4);
    SetupRenderStates(spRenderPass);
    DAT_011fd020 = DAT_011fd000;
    DAT_011fc440 = DAT_011fc420;
    DAT_011fb860 = DAT_011fb840;
    DAT_011fac80 = DAT_011fac60;

    // Shader pass 2.
    spRenderPass = DAT_01202380;
    if (spRenderPass->m_18 < 7)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 3, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_bc);
    AssignTex(spRenderPass->m_44, DAT_011fdbac);
    SetupRenderStates(spRenderPass);
    DAT_011fd044 = DAT_011fd024;
    DAT_011fc464 = DAT_011fc444;
    DAT_011fb884 = DAT_011fb864;
    DAT_011faca4 = DAT_011fac84;

    // Shader pass 3.
    spRenderPass = DAT_01202384;
    if (spRenderPass->m_18 < 7)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 3, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_c0);
    AssignTex(spRenderPass->m_44, DAT_011fdbb4);
    SetupRenderStates(spRenderPass);
    DAT_011fd068 = DAT_011fd048;
    DAT_011fc488 = DAT_011fc468;
    DAT_011fb8a8 = DAT_011fb888;
    DAT_011facc8 = DAT_011faca8;

    // Shader pass 4.
    spRenderPass = DAT_01202388;
    unsigned int count4 = spRenderPass->m_18;
    if (count4 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_c4);
    AssignTex(spRenderPass->m_44, DAT_011fdb08);
    SetupRenderStates(spRenderPass);
    DAT_011fd0a0 = DAT_011fd06c;
    DAT_011fc4c0 = DAT_011fc48c;
    DAT_011fb8e0 = DAT_011fb8ac;
    DAT_011fad00 = DAT_011faccc;

    // Shader pass 5.
    spRenderPass = DAT_0120238c;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_c8);
    AssignTex(spRenderPass->m_44, DAT_011fdb1c);
    SetupRenderStates(spRenderPass);
    DAT_011fd0d0 = DAT_011fd0a8;
    DAT_011fc4f0 = DAT_011fc4c8;
    DAT_011fb910 = DAT_011fb8e8;
    DAT_011fad30 = DAT_011fad08;

    // Shader pass 6.
    spRenderPass = DAT_01202390;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_cc);
    AssignTex(spRenderPass->m_44, DAT_011fdb34);
    SetupRenderStates(spRenderPass);
    DAT_011fd0fc = DAT_011fd0d8;
    DAT_011fc51c = DAT_011fc4f8;
    DAT_011fb93c = DAT_011fb918;
    DAT_011fad5c = DAT_011fad38;

    // Shader pass 7.
    spRenderPass = DAT_01202394;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_d0);
    AssignTex(spRenderPass->m_44, DAT_011fdb40);
    SetupRenderStates(spRenderPass);
    DAT_011fd128 = DAT_011fd104;
    DAT_011fc548 = DAT_011fc524;
    DAT_011fb968 = DAT_011fb944;
    DAT_011fad88 = DAT_011fad64;

    // Shader pass 8.
    spRenderPass = DAT_01202398;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_d4);
    AssignTex(spRenderPass->m_44, DAT_011fdb4c);
    SetupRenderStates(spRenderPass);
    DAT_011fcefc = DAT_011fced4;
    DAT_011fc31c = DAT_011fc2f4;
    DAT_011fb73c = DAT_011fb714;
    DAT_011fab5c = DAT_011fab34;

    // Shader pass 9.
    spRenderPass = DAT_0120239c;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_d8);
    AssignTex(spRenderPass->m_44, DAT_011fdb58);
    SetupRenderStates(spRenderPass);
    DAT_011fcf28 = DAT_011fcf00;
    DAT_011fc348 = DAT_011fc320;
    DAT_011fb768 = DAT_011fb740;
    DAT_011fab88 = DAT_011fab60;

    // Shader pass 10.
    spRenderPass = DAT_012023a0;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_dc);
    AssignTex(spRenderPass->m_44, DAT_011fdb64);
    SetupRenderStates(spRenderPass);
    DAT_011fcf54 = DAT_011fcf2c;
    DAT_011fc374 = DAT_011fc34c;
    DAT_011fb794 = DAT_011fb76c;
    DAT_011fabb4 = DAT_011fab8c;

    // Shader pass 11.
    spRenderPass = DAT_012023a4;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 2, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 2, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    AssignTex(spRenderPass->m_5c, m_e0);
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(DAT_011fdb70);
    SetupRenderStates(spRenderPass);
    DAT_011fcf80 = DAT_011fcf58;
    DAT_011fc3a0 = DAT_011fc378;
    DAT_011fb7c0 = DAT_011fb798;
    DAT_011fabe0 = DAT_011fabb8;

    // Shader pass 12.
    spRenderPass = DAT_012023a8;
    if (spRenderPass->m_18 < 4)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_e4};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(Object_ProcessAndReturnValue_00c163a0(93)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd15c = DAT_011fd148;
    DAT_011fc57c = DAT_011fc568;
    DAT_011fb99c = DAT_011fb988;
    DAT_011fadbc = DAT_011fada8;

    // Shader pass 13.
    spRenderPass = DAT_012023ac;
    if (spRenderPass->m_18 < 4)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_e8};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(Object_ProcessAndReturnValue_00c163a0(94)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd18c = DAT_011fd178;
    DAT_011fc5ac = DAT_011fc598;
    DAT_011fb9cc = DAT_011fb9b8;
    DAT_011fadec = DAT_011fadd8;

    // Shader pass 14.
    spRenderPass = DAT_012023b0;
    if (spRenderPass->m_18 < 6)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->unk14, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_ec};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(Object_ProcessAndReturnValue_00c163a0(95)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd1fc = DAT_011fd1e8;
    DAT_011fc61c = DAT_011fc608;
    DAT_011fba3c = DAT_011fba28;
    DAT_011fae5c = DAT_011fae48;

    // Shader pass 15.
    spRenderPass = DAT_012023b4;
    if (spRenderPass->m_18 < 6)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->unk14, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_f0};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(Object_ProcessAndReturnValue_00c163a0(97)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd214 = DAT_011fd200;
    DAT_011fc634 = DAT_011fc620;
    DAT_011fba54 = DAT_011fba40;
    DAT_011fae74 = DAT_011fae60;

    // Shader pass 16.
    spRenderPass = DAT_012023b8;
    if (spRenderPass->m_18 < 6)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->unk14, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_f4};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(Object_ProcessAndReturnValue_00c163a0(99)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd22c = DAT_011fd218;
    DAT_011fc64c = DAT_011fc638;

    // Shader pass 17.
    spRenderPass = DAT_012023bc;
    if (spRenderPass->m_18 < 6)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->unk14, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_f8};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(Object_ProcessAndReturnValue_00c163a0(101)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd244 = DAT_011fd230;
    DAT_011fc664 = DAT_011fc650;

    // Shader pass 18.
    spRenderPass = DAT_012023c0;
    if (spRenderPass->m_18 < 6)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->unk14, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        SetupStage(spStage.m_p, 3, 3, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 1, 2, 1);
        spRenderPass->SetStage(5, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_fc};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(Object_ProcessAndReturnValue_00c163a0(103)));
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(2, 2, false);
    DAT_011fd25c = DAT_011fd248;
    DAT_011fc67c = DAT_011fc668;

    // Shader pass 19.
    spRenderPass = DAT_012023c4;
    if (spRenderPass->m_18 < 8)
    {
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 5, 3, 0, 1);
        spStage.m_p->m_08 = DAT_011f9534;
        spStage.m_p->m_0c = 1;
        spRenderPass->SetStage(5, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage.m_p);
        ShaderPass::CreateStage(&spStage);
        SetupStage(spStage.m_p, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage.m_p);
    }
    {
        ShaderHandle handle = {m_100};
        static_cast<PassMethods*>(spRenderPass.m_p)->SetPixelShader(handle);
    }
    static_cast<PassMethods*>(spRenderPass.m_p)->SetVertexShader(reinterpret_cast<RefTex*>(Object_ProcessAndReturnValue_00c163a0(200)));
    spRenderPass->GetRSG()->SetRenderState(0x1b, 1, true);
    static_cast<PassMethods*>(spRenderPass.m_p)->SetBlend(9, 1, false);
    spRenderPass->GetRSG()->SetRenderState(15, 0, true);
    spRenderPass->GetRSG()->SetRenderState(7, 1, true);
    spRenderPass->GetRSG()->SetRenderState(23, 4, true);
    spRenderPass->GetRSG()->SetRenderState(14, 0, true);
    DAT_011fd550 = DAT_011fd544;
    DAT_011fc970 = DAT_011fc964;
    DAT_011fbd90 = DAT_011fbd84;
    DAT_011fb1b0 = DAT_011fb1a4;
}
