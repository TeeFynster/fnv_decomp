#define FNV64_HKVECTOR4_OWN_DEFAULT


// src/fallout_shared/teswater_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Ob1 /GF /Oy- (unit src/fallout_shared/teswater_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /Ob1 /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/teswater_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/teswater.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "../../include/NiRenderer.h"
#include "../../include/NiPoint3.h"
// LocalPoint3Ext: unit-local copy of the former shared stand-in NiPoint3_ext. Same layout as NiPoint3; with NiPoint3, 0x004ecef0 (NiPoint3.h's inline constructor/Dot change its code) does not match.
#include "../../include/NiPoint3.h"
class LocalPoint3Ext
{
  public:
    float x;
    float y;
    float z;

    typedef LocalPoint3Ext AimVector;

    __forceinline LocalPoint3Ext()
    {}
    LocalPoint3Ext(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    LocalPoint3Ext operator+(const LocalPoint3Ext& point) const
    {
        return LocalPoint3Ext(x + point.x, y + point.y, z + point.z);
    }
    LocalPoint3Ext operator-(const LocalPoint3Ext& point) const
    {
        return LocalPoint3Ext(x - point.x, y - point.y, z - point.z);
    }
    NiPoint3 operator-(const NiPoint3& point) const;
    float operator*(const LocalPoint3Ext& point) const
    {
        return x * point.x + y * point.y + z * point.z;
    }
    LocalPoint3Ext& operator*=(float scalar);
    LocalPoint3Ext& operator+=(const NiPoint3& point);
    friend LocalPoint3Ext operator*(float scalar, const LocalPoint3Ext& point)
    {
        return LocalPoint3Ext(scalar * point.x, scalar * point.y, scalar * point.z);
    }

    float Dot(const NiPoint3& point) const;
    float Dot(const LocalPoint3Ext& point) const;
    LocalPoint3Ext& Subtract(const LocalPoint3Ext& point);
    float GetLengthSquared();
    void ComputeMagnitude();
    float GetSquaredXYLength() const;
    float Length() const;

    AimVector SubtractIntoVector(const AimVector& point) const;
    LocalPoint3Ext SubtractIntoVector(const NiPoint3& point) const;
    NiPoint3* SubtractIntoVector(NiPoint3* output, const NiPoint3& point) const;
    AimVector FUN_00439e90(const AimVector& point) const;
    bool FUN_00439090(const AimVector& point) const;
    float FUN_00457990() const;
    void Unitize_004a0c10();
    void FUN_006815c0();
    float FUN_004a7290() const;
    float FUN_00457910();
    LocalPoint3Ext& ComputeValue_0063c8a0(const NiPoint3& point);
    NiPoint3 GetNegatedVector() const;
};
extern int DAT_0109cb9c;
void __fastcall ReleaseStorage_00a5a390(void* p);
struct FUN_00a6fae0_Class
{
    void __thiscall UpdateFields_00a6fae0();
};
// Lazily create the shader property for this geometry, picking the shader type by whether the geometry is skinned.
class B9F30MemoryManager
{
  public:
    void* Allocate(unsigned int uiSize);
    void Deallocate(void* pvMem);
};
extern B9F30MemoryManager g_kB9F30MemoryManager;
struct B9F30SkinData
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
    void* m_pkSkinInstance;
};
class B9F30Geometry
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
    B9F30SkinData* m_pkSkinData;
};
class B9F30Property
{
  public:
    B9F30Property(B9F30Geometry* pkGeometry, int m_iPassId, ...);

    static void* operator new(unsigned int uiSize)
    {
        return g_kB9F30MemoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        g_kB9F30MemoryManager.Deallocate(pvMem);
    }

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
class B9F30Owner
{
  public:
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
    B9F30Property* m_pkProperty;

    B9F30Property* WaterShaderProperty_GetWaterPass(B9F30Geometry* pkGeometry);
};

struct B006815c0
{
    float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
    B006815c0();
};
struct NiMatrix
{
    float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
    void* CopyFrom(const void*);
    NiMatrix ProcessAndReturnValue_004ed140(const NiMatrix&);
};
struct NiMatrixEx : NiMatrix
{
    float unk40, unk44;
};
#include "../../include/hkVector4.h"

struct CameraMatrixSource
{
    const void* GetOffset980();
    const void* GetOffsetPointer();
};
CameraMatrixSource* BSShaderManager_GetRenderer();
NiPoint3* BSShader_GetCameraWorldTranslate();
struct NiVec4
{
    float x, y, z, w;
};
NiRenderer* NiXenonRenderer_GetRenderer();
extern "C" void* __stdcall D3DXMatrixInverse(void*, float*, const void*);
extern "C" void* __stdcall D3DXMatrixTranspose(void*, const void*);
extern "C" hkVector4* __stdcall D3DXPlaneNormalize(hkVector4*, const hkVector4*);
extern "C" hkVector4* __stdcall D3DXPlaneTransform(hkVector4*, const hkVector4*, const void*);
struct WaterPlaneHost
{
    void TESWaterSystem_SetClipPlane(float, float, float, float, int);
};
// @fnv 0x004ecef0
// src: COMMUNITY 0x004ecef0
void WaterPlaneHost::TESWaterSystem_SetClipPlane(float x, float y, float z, float w, int unused)
{
    B006815c0 view, projection, inverse;
    NiMatrixEx translated;
    translated.CopyFrom(BSShaderManager_GetRenderer()->GetOffset980());
    translated.m41 =
        -reinterpret_cast<LocalPoint3Ext*>(BSShader_GetCameraWorldTranslate())->Dot(NiPoint3(translated.m11, translated.m21, translated.m31));
    translated.m42 =
        -reinterpret_cast<LocalPoint3Ext*>(BSShader_GetCameraWorldTranslate())->Dot(NiPoint3(translated.m12, translated.m22, translated.m32));
    translated.m43 =
        -reinterpret_cast<LocalPoint3Ext*>(BSShader_GetCameraWorldTranslate())->Dot(NiPoint3(translated.m13, translated.m23, translated.m33));
    NiMatrixEx project;
    project.CopyFrom(BSShaderManager_GetRenderer()->GetOffsetPointer());
    NiMatrix transform = translated.ProcessAndReturnValue_004ed140(project);
    D3DXMatrixInverse(&inverse, 0, &transform);
    D3DXMatrixTranspose(&transform, &inverse);
    hkVector4 plane, result;
    plane.x = x;
    plane.y = y;
    plane.z = z;
    plane.w = w;
    D3DXPlaneNormalize(&plane, &plane);
    D3DXPlaneTransform(&result, &plane, &transform);
    NiVec4 output;
    output.x = result.x;
    output.y = result.y;
    output.z = result.z;
    output.w = result.w;
    NiXenonRenderer_GetRenderer()->CallFooForEachElement(0, 1, &output);
}
