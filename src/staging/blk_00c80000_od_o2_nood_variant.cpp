#define FNV64_HKVECTOR4_OWN_ASSIGN

// src/staging/blk_00c80000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00c80000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00c80000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/hkVector4.h"
#include "../../include/StrArr.h"
#include "../../include/hkMatrix4.h"
#include "../../include/NiPoint3.h"
#include "../../include/Transform.h"
#include "../../include/NiTransform.h"
#include "../../include/NiMatrix3.h"
#include "../../include/NiPoint3.h"
#include "../../include/hkRotation.h"
#include "../../include/hkTransform.h"
#include "../../include/hkVector4.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiTimeController.h"
// BaseCall_blk_00c80000_od_o2_nood_variant: local type (was include/BaseCall.h, which had no evidence of one real class); its methods are 0x00a51ca0 NiBSplineColorInterpolator::SaveBinary, 0x00a6d0f0 NiTimeController::RegisterStreamables, 0x00a6d290 NiTimeController::~NiTimeController, 0x00a6d830 NiTimeController::GetViewerStrings
#include "../../include/NiStream.h"
#include "../../include/StrArr.h"

class BaseCall_blk_00c80000_od_o2_nood_variant
{
public:
    void** vtable;
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

    void FUN_00a6d830(StrArr*);
    void NiBSplineColorInterpolator_SaveBinary(NiStream&);
    int Destroy();
    void FUN_00aa09a0();
};
#include "../../include/bhkFilter.h"
// bhkLimitedHingeVector_blk_00c80000_od_o2_nood_variant: local type (was include/bhkLimitedHingeVector.h, which had no evidence of one real class); its methods are 0x004b4db0 bhkVector4::operator=
class bhkLimitedHingeVector_blk_00c80000_od_o2_nood_variant
{
public:
    union
    {
        struct
        {
            int unk00;
            int unk04;
            int unk08;
            int unk0C;
        };
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        float value[4];
        unsigned char vecData[16];
    };

    void SetQuaternionComponentsFromVector(const float*);
};

#include <xmmintrin.h>
struct ScalarFactor
{
    __m128 value;
    __forceinline ScalarFactor(float x) : value(_mm_load_ss(&x))
    {}
};
struct ScaledVector
{
    __m128 value;
    __forceinline void Multiply(const ScalarFactor& factor)
    {
        value = _mm_mul_ps(_mm_shuffle_ps(factor.value, factor.value, 0), value);
    }
};
struct LocalTypeTag
{
    const char* name;
    LocalTypeTag* parent;
};
extern const LocalTypeTag DAT_012043f8;
extern const __m128 DAT_01267e30;
struct ScaledBackend
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
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
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
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    __m128 firstVector;
    __m128 secondVector;
    void OnTrigger(const __m128*);
    void hkpRigidBody_setAngularVelocity(const __m128*);
};
struct PhysicsWrapper
{
    unsigned int unk00, unk04;
    ScaledBackend* backend;
    void Object_DoNothing();
};
struct CollisionState
{
    unsigned int unk00, unk04, unk08, unk0c;
    PhysicsWrapper* physics;
};
struct CollisionBase
{
    CollisionState* FUN_00653290(const LocalTypeTag*);
};
struct SceneBranch;
struct SceneObject
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual SceneBranch* GetBranch();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    CollisionBase* collision;
};
struct SceneBranch : SceneObject
{
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
    SceneObject** children;
    unsigned short capacity;
    unsigned short count;
};
// @fnv 0x00c803a0
// src: COMMUNITY 0x00c803a0
void __cdecl bhkUtilFunctions_DampBodiesVelocity(SceneObject* object, float scale)
{
    if (object)
    {
        if (object->collision)
        {
            CollisionState* state = object->collision->FUN_00653290(&DAT_012043f8);
            if (state && state->physics)
            {
                PhysicsWrapper* wrapper = state->physics;
                ScaledBackend* backend = wrapper->backend;
                ScaledVector values[2];
                values[0].value = backend ? backend->firstVector : DAT_01267e30;
                values[1].value = backend ? backend->secondVector : DAT_01267e30;
                values[0].Multiply(ScalarFactor(scale));
                values[1].Multiply(ScalarFactor(scale));
                if (backend)
                {
                    wrapper->Object_DoNothing();
                    backend->OnTrigger(&values[0].value);
                    wrapper->Object_DoNothing();
                }
                backend = wrapper->backend;
                if (backend)
                {
                    wrapper->Object_DoNothing();
                    backend->hkpRigidBody_setAngularVelocity(&values[1].value);
                    wrapper->Object_DoNothing();
                }
            }
        }
        SceneBranch* branch = object->GetBranch();
        if (branch)
        {
            for (unsigned int index = 0; index < branch->count; ++index)
            {
                bhkUtilFunctions_DampBodiesVelocity(branch->children[index], scale);
            }
        }
    }
}

void __cdecl bhkUtilFunctions_ClosestBody_ClosestBody(void* first, const void* second, void* result, bool option);
union __declspec(align(16)) ResultBuffer
{
    void* hit;
    char storage[0x30];
    ResultBuffer() : hit(0)
    {}
};
// @fnv 0x00c806b0
// src: XBOX_PDB 0x00c806b0
void* bhkUtilFunctions_GetClosestBody(void* first, const void* second, bool option)
{
    ResultBuffer result;
    bhkUtilFunctions_ClosestBody_ClosestBody(first, second, &result, option);
    return result.hit;
}

struct FUN_00c86660_cls
{
    __m128 m_v00;
    __m128 m_v10;
    __m128 m_v20;
    __m128 m_v30;
    __m128 m_v40;
    __m128 m_v50;
    __m128 m_v60;
    __m128 m_v70;
    __m128 m_v80;
    __m128 m_v90;
    float m_fA0;
    float m_fA4;
    float m_fA8;
    unsigned char m_bAC;
    unsigned char m_bAD;
    unsigned char m_bAE;

    FUN_00c86660_cls* hkMotionState_Copy(const FUN_00c86660_cls* src);
};

// @fnv 0x00c86660
// src: COMMUNITY 0x00c86660
FUN_00c86660_cls* FUN_00c86660_cls::hkMotionState_Copy(const FUN_00c86660_cls* src)
{
    m_v00 = src->m_v00;
    m_v10 = src->m_v10;
    m_v20 = src->m_v20;
    m_v30 = src->m_v30;
    m_v40 = src->m_v40;
    m_v50 = src->m_v50;
    m_v60 = src->m_v60;
    m_v70 = src->m_v70;
    m_v80 = src->m_v80;
    m_v90 = src->m_v90;
    m_fA0 = src->m_fA0;
    m_fA4 = src->m_fA4;
    m_fA8 = src->m_fA8;
    m_bAC = src->m_bAC;
    m_bAD = src->m_bAD;
    m_bAE = src->m_bAE;
    return this;
}

class Vec4Tmp
{
  public:
    __m128 v;
    void hkRotation_renormalize();
};

class bhkLimitedHingeVectorSet
{
  public:
    bhkLimitedHingeVector_blk_00c80000_od_o2_nood_variant m_v0;
    bhkLimitedHingeVector_blk_00c80000_od_o2_nood_variant m_v1;
    bhkLimitedHingeVector_blk_00c80000_od_o2_nood_variant m_v2;
    void bhkMatrix3_Renormalize();
};

// @fnv 0x00c8bf50
// src: XBOX_PDB 0x00c8bf50
void bhkLimitedHingeVectorSet::bhkMatrix3_Renormalize()
{
    bhkLimitedHingeVector_blk_00c80000_od_o2_nood_variant& v1 = m_v1;
    bhkLimitedHingeVector_blk_00c80000_od_o2_nood_variant& v2 = m_v2;
    Vec4Tmp a;
    a.v = _mm_setr_ps(m_v0.x, m_v0.y, m_v0.z, m_v0.w);
    Vec4Tmp b;
    b.v = _mm_setr_ps(v1.x, v1.y, v1.z, v1.w);
    Vec4Tmp c;
    c.v = _mm_setr_ps(v2.x, v2.y, v2.z, v2.w);
    a.hkRotation_renormalize();
    m_v0.SetQuaternionComponentsFromVector((const float*)&a);
    v1.SetQuaternionComponentsFromVector((const float*)&b);
    v2.SetQuaternionComponentsFromVector((const float*)&c);
}

extern int DAT_010c69f4;

struct FUN_00c99ff0_base
{
    void FUN_00c69010(void* arg);
    char m_auiShapeKeys[0xa0];
};

struct FUN_00c99ff0_cls : FUN_00c99ff0_base
{
    __m128 m_a0;
    __m128 m_b0;
    __m128 m_c0;
    FUN_00c99ff0_cls* SetVtableAndProcessState_00c99ff0(void* a1, __m128* a2, __m128* a3);
};

// @fnv 0x00c99ff0
// src: GUESS 0x00c99ff0 (confidence: low)
FUN_00c99ff0_cls* FUN_00c99ff0_cls::SetVtableAndProcessState_00c99ff0(void* a1, __m128* a2, __m128* a3)
{
    ((FUN_00c99ff0_base*)this)->FUN_00c69010(a1);
    *(int*)this = (int)&DAT_010c69f4;
    m_a0 = *a2;
    m_b0 = *a3;
    m_c0 = *(__m128*)((char*)a1 + 0x40);
    return this;
}


struct Obj00c9ec00
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
    hkMatrix4 m_mat;
};

struct Owner00c9ec00
{
    int unk00;
    int unk04;
    Obj00c9ec00* unk08;
    void Noop00a29680();
    void bhkShapePhantom_GetTransform(hkMatrix4* out);
};

// @fnv 0x00c9ec00
// src: COMMUNITY 0x00c9ec00
void Owner00c9ec00::bhkShapePhantom_GetTransform(hkMatrix4* out)
{
    if (!this)
        return;
    Obj00c9ec00* p = unk08;
    if (!p)
        return;
    Noop00a29680();
    out->m_kColumn0.m_vComponents = p->m_mat.m_kColumn0.m_vComponents;
    out->m_kColumn1.m_vComponents = p->m_mat.m_kColumn1.m_vComponents;
    out->m_kColumn2.m_vComponents = p->m_mat.m_kColumn2.m_vComponents;
    out->m_kColumn3.m_vComponents = p->m_mat.m_kColumn3.m_vComponents;
    Noop00a29680();
}

void __stdcall bhkShapePhantom_GetTransform(hkTransform* pkTransform);
void __cdecl HK2NI_00624b10(NiMatrix3* pkOut, const hkRotation* pkRotation);
void __cdecl FUN_00458620(NiPoint3* pkOut, const hkVector4* pkVector);

// @fnv 0x00c9ec60
// src: XBOX_PDB 0x00c9ec60
void __stdcall bhkShapePhantom_GetTransform_00c9ec60(NiTransform* pkOut)
{
    // The output callee fills the transform without a constructor call.
    __m128 transformStorage[sizeof(hkTransform) / sizeof(__m128)];
    hkTransform& kTransform = reinterpret_cast<hkTransform&>(transformStorage);
    bhkShapePhantom_GetTransform(&kTransform);
    HK2NI_00624b10(&pkOut->m_Rotate, &kTransform.m_rotation);
    FUN_00458620(&pkOut->m_Translate, reinterpret_cast<const hkVector4*>(&kTransform.m_vTranslation));
}

namespace fnv_00c9ecb0 {
struct HingeVectorSet
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    bhkLimitedHingeVector_blk_00c80000_od_o2_nood_variant m_akVectors[4];
};

struct FUN_00c9ecb0_cls
{
    void FillOutputFromState(HingeVectorSet* set);
    void bhkShapePhantom_GetTransform(hkMatrix4& m);
    void bhkShapePhantom_CopyCinfo(HingeVectorSet* set);
};

// The original local SIMD representation triggered /GS for this function.
#pragma strict_gs_check(push, on)
// @fnv 0x00c9ecb0
// src: COMMUNITY 0x00c9ecb0
void FUN_00c9ecb0_cls::bhkShapePhantom_CopyCinfo(HingeVectorSet* set)
{
    FillOutputFromState(set);
    // The callee fills this scratch matrix without constructing its columns.
    __m128 matrixStorage[4];
    hkMatrix4& m = reinterpret_cast<hkMatrix4&>(matrixStorage);
    bhkShapePhantom_GetTransform(m);
    bhkLimitedHingeVector_blk_00c80000_od_o2_nood_variant* vectors = set->m_akVectors;
    vectors[0].SetQuaternionComponentsFromVector(m.m_kColumn0.m_vComponents.m128_f32);
    vectors[1].SetQuaternionComponentsFromVector(m.m_kColumn1.m_vComponents.m128_f32);
    vectors[2].SetQuaternionComponentsFromVector(m.m_kColumn2.m_vComponents.m128_f32);
    vectors[3].SetQuaternionComponentsFromVector(m.m_kColumn3.m_vComponents.m128_f32);
}
#pragma strict_gs_check(pop)
}  // namespace fnv_00c9ecb0

#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier(void);
namespace fnv_00c88520 {
struct Quaternion
{
    float w, x, y, z;
    void FUN_00a6df40(const NiTransform& matrix);
};
struct SceneObject;
struct CastObject
{
    int unk00, unk04, unk08, unk0c;
    SceneObject* unk10;
    SceneObject* GetBody()
    {
        if (this)
            return unk10;
        return 0;
    }
    CastObject* FUN_00653290(const void* type);
};
struct SceneObject
{
    void** vtable;
    int unk04, unk08, unk0c, unk10, unk14;
    SceneObject* unk18;
    CastObject* unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c,
        unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94;
    float unk98;
};
struct Wrapper
{
    int unk00, unk04;
    SceneObject* unk08;
    int unk0c;
    SceneObject* unk10;
    SceneObject* GetSource()
    {
        if (this)
            return unk08;
        return 0;
    }
    SceneObject* GetDestination()
    {
        if (this)
            return unk10;
        return 0;
    }
};
struct LockObject
{
    unsigned int owner;
    unsigned int count;
    void BSSpinLock_Lock(const char*);
};

extern char DAT_012043f8;
extern unsigned int DAT_01267b80;
extern unsigned int DAT_01267b84;

Wrapper* __cdecl bhkUtilFunctions_FindNextCollisionObject(SceneObject*);
void __cdecl AccumulateParentTransforms(SceneObject*, SceneObject*, NiTransform*);
void __cdecl HK2NI_00624ad0(NiTransform*, hkMatrix4*);
void __cdecl NI2HK(hkVector4&, const NiPoint3&);

// @fnv 0x00c88520
// src: COMMUNITY 0x00c88520
void __cdecl WeaponObject_UpdateRigidBodyTransforms(SceneObject* a0, SceneObject* a1)
{
    Wrapper* p = a0 ? bhkUtilFunctions_FindNextCollisionObject(a0) : 0;
    SceneObject* source = p->GetSource();
    _ReadWriteBarrier();
    SceneObject* destination = p->GetDestination();
    CastObject* cast = a1 && a1->unk1c ? a1->unk1c->FUN_00653290(&DAT_012043f8) : 0;
    _ReadWriteBarrier();
    SceneObject* body = cast->GetBody();
    if (destination && body && source && a1 && a1->unk18)
    {
        // Keep the SIMD scratch storage trivial for the original stack layout.
        __m128 worldStorage[4];
        hkMatrix4& world = reinterpret_cast<hkMatrix4&>(worldStorage);
        // Both output transforms are filled by the callees without construction.
        float convertedStorage[sizeof(NiTransform) / sizeof(float)];
        float relativeStorage[sizeof(NiTransform) / sizeof(float)];
        NiTransform& converted = reinterpret_cast<NiTransform&>(convertedStorage);
        NiTransform& relative = reinterpret_cast<NiTransform&>(relativeStorage);
        ((void(__thiscall*)(SceneObject*, hkMatrix4*))body->vtable[61])(body, &world);
        HK2NI_00624ad0(&converted, &world);
        converted.m_fScale = a1->unk98;
        AccumulateParentTransforms(source, a1, &relative);
        NiTransform combined = converted.FUN_0062c250(relative);
        Quaternion q;
        q.FUN_00a6df40(combined);
        __m128 position;
        NI2HK(*reinterpret_cast<hkVector4*>(&position), reinterpret_cast<const NiPoint3&>(combined.m_Translate));
        __m128 rotation;
        rotation.m128_f32[0] = q.x;
        rotation.m128_f32[1] = q.y;
        rotation.m128_f32[2] = q.z;
        rotation.m128_f32[3] = q.w;
        reinterpret_cast<hkVector4*>(&rotation)->normalize_005611c0();
        reinterpret_cast<LockObject*>(&DAT_01267b80)->BSSpinLock_Lock(0);
        ((void(__thiscall*)(SceneObject*, hkVector4*, hkVector4*))destination->vtable[58])(
            destination, reinterpret_cast<hkVector4*>(&position), reinterpret_cast<hkVector4*>(&rotation));
        if (--DAT_01267b84 == 0)
            DAT_01267b80 = 0;
    }
}
}  // namespace fnv_00c88520

#include <string.h>
#include "../../include/MemoryManager.h"
#include "../../include/NiObject.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint3.h"
#include "../../include/hkSerializableCinfo.h"
extern __declspec(thread) int g_tlsMemContext;
inline int GetMemContext()
{
    return g_tlsMemContext;
}
inline void SetMemContext(int aiMemoryContext)
{
    g_tlsMemContext = aiMemoryContext;
}
struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = GetMemContext();
        SetMemContext(aiMemoryContext);
    }
    ~MemContextGuard()
    {
        SetMemContext(m_iSaved);
    }
};
__forceinline unsigned int StrArr::AddInline(char* value)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, value);
    return index;
}

__forceinline void StrArr::AppendInline(char* value)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    if (index >= m_usSize)
    {
        m_usSize = (unsigned short)(index + 1);
        if (value)
            ++m_usESize;
    }
    else if (value)
    {
        if (!m_pBase[index])
            ++m_usESize;
    }
    else if (m_pBase[index])
    {
        --m_usESize;
    }
    m_pBase[index] = value;
}
struct KeyData : BaseCall_blk_00c80000_od_o2_nood_variant
{
    NiPoint3* keys;
    unsigned int unk40, unk44;
    unsigned int count;
    void bhkBlendController_GetViewerStrings(StrArr* strings);
};
class GlobalObjectO2_00a7b610
{
  public:
    const char* name;
};
extern GlobalObjectO2_00a7b610 g_012681f0;
char* NiViewerStrings_NiGetViewerString_Title(const char*);
char* NiGetViewerString_00a7d510(const char*, unsigned int);
int _sprintf_s(char*, unsigned int, const char*, ...);
int _strcpy_s(char*, unsigned int, const char*);
extern MemoryManager g_memoryManager;

// @fnv 0x00c9bbb0
// src: XBOX_PDB 0x00c9bbb0
void KeyData::bhkBlendController_GetViewerStrings(StrArr* strings)
{
    MemContextGuard kGuard(16);
    FUN_00a6d830(strings);
    strings->AddInline(NiViewerStrings_NiGetViewerString_Title(g_012681f0.name));
    unsigned int uiNumKeys = count;
    strings->AddInline(NiGetViewerString_00a7d510("iKeys", uiNumKeys));
    for (unsigned int i = 0; i < count; ++i)
    {
        char buffer[64];
        const NiPoint3& kKey = keys[i];
        _sprintf_s(buffer, 64, "Key%d: %.4f, %.4f, %.4f", i, kKey.x, kKey.y, kKey.z);
        unsigned int length = strlen(buffer) + 1;
        char* copy = (char*)g_memoryManager.Allocate(length);
        _strcpy_s(copy, length, buffer);
        strings->AppendInline(copy);
    }
}

struct TlsBlock
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

    unsigned int unk0c8;

    unsigned int unk0cc;

    unsigned int unk0d0;

    unsigned int unk0d4;

    unsigned int unk0d8;

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

    unsigned int unk1a0;

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

    unsigned int unk1f0;

    unsigned int unk1f4;

    unsigned int unk1f8;

    unsigned int unk1fc;

    unsigned int unk200;

    unsigned int unk204;

    unsigned int unk208;

    unsigned int unk20c;

    unsigned int unk210;

    unsigned int unk214;

    unsigned int unk218;

    unsigned int unk21c;

    unsigned int unk220;

    unsigned int unk224;

    unsigned int unk228;

    unsigned int unk22c;

    unsigned int unk230;

    unsigned int unk234;

    unsigned int unk238;

    unsigned int unk23c;

    unsigned int unk240;

    unsigned int unk244;

    unsigned int unk248;

    unsigned int unk24c;

    unsigned int unk250;

    unsigned int unk254;

    unsigned int unk258;

    unsigned int unk25c;

    unsigned int unk260;

    unsigned int unk264;

    unsigned int unk268;

    unsigned int unk26c;

    unsigned int unk270;

    unsigned int unk274;

    unsigned int unk278;

    unsigned int unk27c;

    unsigned int unk280;

    unsigned int unk284;

    unsigned int unk288;

    unsigned int unk28c;

    unsigned int unk290;

    unsigned int unk294;

    unsigned int unk298;

    unsigned int unk29c;

    unsigned int unk2a0;

    unsigned int unk2a4;

    unsigned int unk2a8;

    unsigned int unk2ac;

    unsigned int unk2b0;

    unsigned int context;
};

extern __declspec(thread) TlsBlock tlsBlock;

struct ContextScope
{

    unsigned int previous;

    ContextScope(unsigned int value)
    {
        previous = tlsBlock.context;
        tlsBlock.context = value;
    }

    ~ContextScope()
    {
        tlsBlock.context = previous;
    }
};

struct TypeInfo
{
    const char* name;
    TypeInfo* parent;
};

extern TypeInfo DAT_0126818c, DAT_01268158, DAT_012681f0, DAT_01267e64;

extern const float DAT_01050de4, DAT_0101e2bc, DAT_01016248, DAT_01017718, DAT_01011d78;

struct Backend
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

    unsigned int unk0c8;

    unsigned int unk0cc;

    unsigned int unk0d0;

    unsigned int unk0d4;

    unsigned int unk0d8;

    unsigned int unk0dc;

    unsigned int unk0e0;

    unsigned int unk0e4;

    unsigned int unk0e8;

    unsigned int unk0ec;

    __declspec(align(16)) Transform transform;
};

struct PhysicsObject;

struct PhysicsList
{
    PhysicsObject* object;
    PhysicsList* next;
    void PopAndRelease();
};

struct World;

struct Filter
{
    unsigned int value;
    __forceinline void Layer(unsigned x)
    {
        value = (value & ~0x7f) | (x & 0x7f);
    }
};

struct PhysicsObject
{

    virtual void slot00();

    virtual void slot04();

    virtual TypeInfo* GetType();

    virtual void slot0c();

    virtual void slot10();

    virtual void slot14();

    virtual void slot18();

    virtual void slot1c();

    virtual int GetKind();

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

    virtual World* GetWorld();

    virtual void slot98();

    virtual void slot9c();

    virtual void Detach();

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

    virtual void slote0();

    virtual void SetMotion(int);

    int unk04;

    Backend* underlying;

    PhysicsObject** alternate;

    int unk10;

    PhysicsList objects;

    int GetLinkedRecordValue();

    void* bhkWorldObject_GethkWorld();

    int bhkRigidBody_GetMotionType();

    void bhkRigidBody_AddActCon(void*);

    __declspec(noalias) Filter bhkWorldObject_GetCollisionFilter();

    void bhkWorldObject_SetCollisionFilter(unsigned int);

    bool bhkWorldObject_IsAddedToWorld();

    void UpdateMatchingNodes(World*);
};

struct Key
{
    float time, value, tangent;
};

struct Controller
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

    Key* keys;
    int unk40, unk44;
    unsigned int count;
};

struct SceneNode;

struct CollisionWrapper
{
    int unk00, unk04;
    SceneNode* host;
    int unk0c;
    PhysicsObject* body;
};

struct SceneNode
{
    int unk00, unk04;
    SceneNode* host;
    int unk0c;
    PhysicsObject* body;

    unsigned int unk014;

    unsigned int unk018;

    unsigned int unk01c;

    unsigned int unk020;

    World* world;

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

    NiTransform transform;

    Controller* NiObjectNET_GetController(TypeInfo*);
};

struct World
{
    void bhkWorld_Add(PhysicsObject*);
};

struct ConstraintData
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

    float strength;
    int unkc0;
    float tau, damping;

    void FUN_00cb8b60(Transform*, Transform*, __m128*, __m128*);
};


struct hkConstraintCinfo : hkSerializableCinfo
{

    __forceinline hkConstraintCinfo()
    {}

    virtual __forceinline ~hkConstraintCinfo()
    {
        SetChildObject(0);
    }

    void SetChildObject(int);
};

struct hkLimitedHingeConstraintCinfo : hkConstraintCinfo
{

    __forceinline hkLimitedHingeConstraintCinfo()
    {}

    virtual __forceinline ~hkLimitedHingeConstraintCinfo()
    {}

    void hkLimitedHingeConstraintCinfo_CreateData();

    void hkConstraintCinfo_SetEntities(PhysicsObject*, PhysicsObject*);
};

typedef hkLimitedHingeConstraintCinfo ConstraintInfo;

void* Object_DispatchCommandFour(unsigned int);

void FUN_00aa1450(void*);

struct FUN_00c88380
{

    int* vtable;
    int references;
    void* object;
    int unk0c;

    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }

    static void operator delete(void* p)
    {
        FUN_00aa1450(p);
    }

    FUN_00c88380(ConstraintInfo*);
};

void WeaponObject_UpdateRigidBodyTransforms(SceneNode*, SceneNode*);

CollisionWrapper* bhkUtilFunctions_FindNextCollisionObject(SceneNode*);

__declspec(noalias) unsigned char bhkRigidBody_IsMotionTypeDynamic(int*);

Transform* FUN_0056df80(Transform*, NiTransform*);

World* bhkWorld_Getbhk(World*);

SceneNode* NiObject_DynamicCast(TypeInfo*, CollisionWrapper*);

void UpdateChainCollision(SceneNode*, World*);

static __forceinline void Normalize3(__m128& v)
{

    __m128 h = _mm_set_ss(0.5f), t = _mm_set_ss(3.0f), z = _mm_set_ss(0.0f);
    __m128 p = _mm_mul_ps(v, v);

    __m128 a = _mm_shuffle_ps(p, p, 0x55);

    __m128 b = _mm_add_ss(a, p);

    __m128 n = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), b);

    __m128 mask = _mm_cmpeq_ss(n, z);

    __m128 r = _mm_rsqrt_ss(n);

    __m128 result = _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(h, r), _mm_sub_ss(t, _mm_mul_ss(_mm_mul_ss(n, r), r))));

    v = _mm_mul_ps(v, _mm_shuffle_ps(result, result, 0));
}

union AxisVector
{
    struct
    {
        float x, y, z, w;
    } f;
    __m128 q;
};

static __forceinline PhysicsObject* AsType(PhysicsObject* object, TypeInfo* target)
{

    TypeInfo* type = object->GetType();

    while (type)
    {
        if (type == target)
            return object;
        type = type->parent;
    }

    return 0;
}

__forceinline unsigned char DynamicValue(const int& m)
{
    return bhkRigidBody_IsMotionTypeDynamic(const_cast<int*>(&m));
}
// @fnv 0x00c88a40
// src: COMMUNITY 0x00c88a40
void __cdecl WeaponObject_Constrain(bool create, Filter filter, SceneNode* first, SceneNode* second, bool force)
{

    ContextScope contextScope(16);

    if (!first || !second)
        return;

    {

        WeaponObject_UpdateRigidBodyTransforms(first, second);

        CollisionWrapper* __restrict resolvedFirst = bhkUtilFunctions_FindNextCollisionObject(first);

        CollisionWrapper* resolvedSecond = bhkUtilFunctions_FindNextCollisionObject(second);

        if (resolvedFirst && resolvedSecond)
        {
            PhysicsObject* sourceBody = resolvedFirst->body;

            PhysicsObject* targetBody;

            targetBody = resolvedSecond->body;

            PhysicsList* listEntry;

            listEntry = &sourceBody->objects;

            bool skipped;

            skipped = false;

            while (listEntry)
            {

                PhysicsObject* listObject = listEntry->object;

                if (!listObject)
                    break;

                if (AsType(listObject, &DAT_0126818c))
                {

                    PhysicsObject* body;

                    body = listObject->underlying ? (PhysicsObject*)listObject->underlying->unk00c
                                                  : (listObject->alternate ? *listObject->alternate : 0);

                    if (body->GetKind() > 100 || body->GetKind() == 18 || body->GetKind() == 19)
                    {

                        skipped = true;

                        listEntry = listEntry->next;

                        continue;
                    }

                    if (listObject->GetLinkedRecordValue())
                        listObject->Detach();
                }
                else
                {

                    if (AsType(listObject, &DAT_01268158) && listObject->bhkWorldObject_GethkWorld())
                        listObject->Detach();
                }

                listEntry->PopAndRelease();
            }

            if (create)
            {

                ConstraintInfo info;

                info.hkLimitedHingeConstraintCinfo_CreateData();

                if (force)
                    sourceBody->SetMotion(4);

                else
                {

                    int sourceMotion = sourceBody->bhkRigidBody_GetMotionType();

                    int targetMotion = targetBody->bhkRigidBody_GetMotionType();

                    if (bhkRigidBody_IsMotionTypeDynamic(&sourceMotion) != bhkRigidBody_IsMotionTypeDynamic(&targetMotion))
                    {

                        long motionType;

                        Controller* controller = resolvedSecond->host->NiObjectNET_GetController(&DAT_012681f0);

                        if (controller && controller->count)
                        {

                            if (controller->keys[controller->count - 1].value < 1.0f)
                                motionType = 1;

                            else
                                motionType = 4;
                        }
                        else
                        {

                            motionType = DynamicValue(targetBody->bhkRigidBody_GetMotionType()) ? 1 : 4;
                        }

                        sourceBody->SetMotion(motionType);
                    }
                }

                info.hkConstraintCinfo_SetEntities(sourceBody, targetBody);

                __m128 sourceStorage[4];
                const Transform& sourceBodyTransform = (sourceBody ? sourceBody->underlying : 0)->transform;
                {
                    __m128 a = sourceBodyTransform.r[0], b = sourceBodyTransform.r[1],
                           c = sourceBodyTransform.r[2], d = sourceBodyTransform.r[3];
                    sourceStorage[0] = a;
                    sourceStorage[1] = b;
                    sourceStorage[2] = c;
                    sourceStorage[3] = d;
                }
                Transform& sourceTransform = reinterpret_cast<Transform&>(sourceStorage);

                __m128 targetStorage[4];
                const Transform& targetBodyTransform = (targetBody ? targetBody->underlying : 0)->transform;
                {
                    __m128 a = targetBodyTransform.r[0], b = targetBodyTransform.r[1],
                           c = targetBodyTransform.r[2], d = targetBodyTransform.r[3];
                    targetStorage[0] = a;
                    targetStorage[1] = b;
                    targetStorage[2] = c;
                    targetStorage[3] = d;
                }
                Transform& targetTransform = reinterpret_cast<Transform&>(targetStorage);

                __m128 convertedStorage[4];
                Transform& convertedTransform = reinterpret_cast<Transform&>(convertedStorage);

                FUN_0056df80(&convertedTransform, &first->transform);

                sourceTransform.hkRotation_renormalize();

                targetTransform.hkRotation_renormalize();

                info.data->tau = DAT_01050de4;

                info.data->damping = 0.1f;

                info.data->strength = 1.0f;

                NiPoint3 direction;

                direction.x = resolvedFirst->host->transform.m_Rotate.m_pEntry[0][0];

                direction.y = resolvedFirst->host->transform.m_Rotate.m_pEntry[1][0];

                direction.z = resolvedFirst->host->transform.m_Rotate.m_pEntry[2][0];

                AxisVector axis;

                axis.f.x = direction.x;

                axis.f.y = direction.y;

                axis.f.z = direction.z;

                axis.f.w = 0.0f;

                Normalize3(axis.q);

                info.data->FUN_00cb8b60(&sourceTransform, &targetTransform, &sourceTransform.r[3], &axis.q);

                FUN_00c88380* newConstraint = new FUN_00c88380(&info);

                sourceBody->bhkRigidBody_AddActCon(newConstraint);

                Filter sourceFilter = sourceBody->bhkWorldObject_GetCollisionFilter();

                unsigned layer = targetBody->bhkWorldObject_GetCollisionFilter().value & 0x7f;

                unsigned bits = (sourceFilter.value & 0xe080) | (filter.value & 0xffff1400) | 0x1400;

                bits = (bits & ~0x7f) | (layer & 0x7f);

                sourceBody->bhkWorldObject_SetCollisionFilter(bits);

                World* world = bhkWorld_Getbhk(targetBody->GetWorld());

                if (!world)
                {

                    SceneNode* fallbackNode;

                    fallbackNode = NiObject_DynamicCast(&DAT_01267e64, resolvedSecond);

                    if (fallbackNode)
                        world = fallbackNode->world;
                }

                if (world && targetBody->bhkWorldObject_IsAddedToWorld())
                {

                    if (!sourceBody->GetWorld())
                        world->bhkWorld_Add(sourceBody);

                    else
                        sourceBody->UpdateMatchingNodes(world);
                }

                if (skipped)
                    UpdateChainCollision(first, world);

                return;
            }

            return;
        }
        if (!resolvedFirst)
            return;
    }
}

struct KnockDownNode;
struct CollisionObject;
struct RigidBody;
struct PhysicsBody;
class NiRTTI;

struct VirtualObject
{
    virtual void VirtualUnknown00();
    virtual void VirtualUnknown04();
    virtual void VirtualUnknown08();
    virtual KnockDownNode* GetNode();
    virtual void VirtualUnknown10();
    virtual void VirtualUnknown14();
    virtual void VirtualUnknown18();
    virtual void VirtualUnknown1c();
    virtual void VirtualUnknown20();
    virtual void VirtualUnknown24();
    virtual void VirtualUnknown28();
    virtual void VirtualUnknown2c();
    virtual void VirtualUnknown30();
    virtual void VirtualUnknown34();
    virtual void VirtualUnknown38();
    virtual void VirtualUnknown3c();
    virtual void VirtualUnknown40();
    virtual void VirtualUnknown44();
    virtual void VirtualUnknown48();
    virtual void VirtualUnknown4c();
    virtual void VirtualUnknown50();
    virtual void VirtualUnknown54();
    virtual void VirtualUnknown58();
    virtual void VirtualUnknown5c();
    virtual void VirtualUnknown60();
    virtual void VirtualUnknown64();
    virtual void VirtualUnknown68();
    virtual void VirtualUnknown6c();
    virtual void VirtualUnknown70();
    virtual void VirtualUnknown74();
    virtual void VirtualUnknown78();
    virtual void VirtualUnknown7c();
    virtual void VirtualUnknown80();
    virtual void VirtualUnknown84();
    virtual void VirtualUnknown88();
    virtual void Update(float);
    virtual void VirtualUnknown90();
    virtual void VirtualUnknown94();
    virtual void VirtualUnknown98();
    virtual void VirtualUnknown9c();
    virtual void VirtualUnknowna0();
    virtual void VirtualUnknowna4();
    virtual void VirtualUnknowna8();
    virtual void VirtualUnknownac();
    virtual void SetMotion(int, int, int);
    virtual void VirtualUnknownb4();
    virtual void VirtualUnknownb8();
    virtual void VirtualUnknownbc();
    virtual void VirtualUnknownc0();
    virtual void VirtualUnknownc4();
    virtual void VirtualUnknownc8();
    virtual void VirtualUnknowncc();
    virtual void VirtualUnknownd0();
    virtual void VirtualUnknownd4();
    virtual void VirtualUnknownd8();
    virtual void VirtualUnknowndc();
    virtual void VirtualUnknowne0();
    virtual void SetBodyMotion(int);
};
struct PhysicsBody
{
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int filterInfo;
};
struct RigidBody : public VirtualObject
{
    unsigned int unk04;
    PhysicsBody* body;
    bhkFilter bhkWorldObject_GetCollisionFilter();
    unsigned int GetFilter();
};
struct CollisionObject : public VirtualObject
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    RigidBody* rigidBody;
    unsigned int unk14;
    float beginValue, endValue;
    void ApplyMotion();
};
struct KnockDownNode
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
    NiAVObject** children;
    unsigned short capacity, childCount;
};
struct NiInterpControllerTriple
{
    float time, value, tangent;
    NiInterpControllerTriple();
};
struct ControllerKeys
{
    void* vtable;
    NiInterpControllerTriple* data;
    unsigned int capacity, size, effectiveSize, growBy;
    void Reserve(unsigned int count);
};
// Key storage belongs to the concrete controller, after the shared base.
struct KeyedTimeController : public NiTimeController
{
    unsigned int unk34;
    ControllerKeys keys;
    float unk50, unk54;
    unsigned int mode;
};
struct BodyState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    PhysicsBody physics;
};
inline unsigned int RigidBody::GetFilter()
{
    BodyState* state = (BodyState*)body;
    if (state)
    {
        PhysicsBody* physics = &state->physics;
        if (physics)
            return physics->filterInfo;
    }
    return 0;
}
extern unsigned int DAT_012683f4;
extern float DAT_011b1210[32];
extern float DAT_01015f5c, DAT_011b0f88, DAT_011b0f8c, DAT_011afe64;
hkVector4& NI2HK(hkVector4& result, const NiPoint3& point);
void bhkForceController_TestForce2(NiAVObject* object, const hkVector4& velocity, float scale);
struct PhysicsMotion
{
    void ApplyImpulse(float duration, const hkVector4& velocity);
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void* operator new[](unsigned int, void* p)
{
    return p;
}
struct PlainKey
{
    float time, value, tangent;
};
union KeyVectorStorage
{
    PlainKey keys[2];
    __m128 vector;
};
// @fnv 0x00c9b670
// src: XBOX_PDB 0x00c9b670
void __cdecl bhkBlendController_DoKnockDown(NiAVObject* object, const NiPoint3& velocity, unsigned int context, float time, bool disable)
{
    NiPoint3 sharedPoint;
    KeyVectorStorage work;
    if (object)
    {
        CollisionObject* collision = 0;
        if (object->m_spCollisionObject.m_pObject)
            collision = (CollisionObject*)((NiObject*)object->m_spCollisionObject.m_pObject)->DynamicCast((const NiRTTI*)&DAT_01267e64);
        if (collision)
        {
            collision->ApplyMotion();
            unsigned int filter = 0;
            if (collision->rigidBody)
                filter = collision->rigidBody->GetFilter();
            float speed = DAT_011b1210[(filter >> 8) & 31];
            KeyedTimeController* controller = static_cast<KeyedTimeController*>(object->GetController((const NiRTTI*)&DAT_012681f0));
            if (controller && speed >= 0.0f)
            {
                if (!disable)
                {
                    float begin = collision->beginValue;
                    float end = collision->endValue;
                    controller->Reset();
                    unsigned int count = 2;
                    controller->mode = count;
                    if (controller->keys.effectiveSize == 0)
                    {
                        NiInterpControllerTriple* values = new (&work.keys) NiInterpControllerTriple[2];
                        values[0].value = begin;
                        values[0].tangent = end;
                        values[0].time = 0.0f;
                        values[1].value = 0.0f;
                        values[1].tangent = 0.0f;
                        values[1].time = speed;
                        controller->keys.Reserve(2);
                        NiInterpControllerTriple* p = values;
                        do
                        {
                            controller->AddKey(*p);
                            ++p;
                        } while (--count != 0);
                        controller->m_fLoKeyTime = time;
                        controller->m_fHiKeyTime = speed;
                        controller->m_uiObjectFlags = (controller->m_uiObjectFlags & 0xfef5) | 0xc5;
                        controller->m_fPhase = 0.0f;
                        controller->m_fFrequency = 1.0f;
                        controller->Start(DAT_01015f5c);
                    }
                    NiAVObject* active = const_cast<NiAVObject* volatile&>(object);
                    if (!active->GetController((const NiRTTI*)&DAT_012683f4))
                    {
                        new (&sharedPoint) NiPoint3(reinterpret_cast<const NiPoint3&>(velocity) * DAT_011b0f88);
                        NiPoint3& scaled = sharedPoint;
                        bhkForceController_TestForce2(active, NI2HK(reinterpret_cast<hkVector4&>(work.vector), scaled), DAT_011b0f8c);
                    }
                }
                else
                {
                    collision->SetMotion(1, 0, 0);
                }
            }
        }
        else if (object->m_spCollisionObject.m_pObject)
        {
            CollisionObject* fallback = (CollisionObject*)((NiObject*)object->m_spCollisionObject.m_pObject)->DynamicCast((const NiRTTI*)&DAT_012043f8);
            if (fallback && fallback->rigidBody)
            {
                RigidBody* body = fallback->rigidBody;
                unsigned int filter = body->bhkWorldObject_GetCollisionFilter().value;
                unsigned int layer = filter & 0x7f;
                if ((layer != 8 && layer != 29) || (filter & 0x1f00) == 0x1400)
                {
                    body->SetBodyMotion(1);
                    if (!disable)
                    {
                        new (&sharedPoint) NiPoint3(reinterpret_cast<const NiPoint3&>(velocity) * DAT_011b0f88);
                        NiPoint3& scaled = sharedPoint;
                        ((PhysicsMotion*)body->body)->ApplyImpulse(DAT_011afe64, NI2HK(reinterpret_cast<hkVector4&>(work.vector), scaled));
                    }
                }
            }
        }
        KnockDownNode* node = (KnockDownNode*)object->IsSceneNode();
        if (node)
        {
            for (unsigned int i = 0; i < node->childCount; ++i)
                bhkBlendController_DoKnockDown(node->children[i], velocity, context, time, disable);
        }
    }
}
