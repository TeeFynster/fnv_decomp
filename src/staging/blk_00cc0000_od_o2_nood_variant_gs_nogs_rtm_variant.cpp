#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// src/staging/blk_00cc0000_od_o2_nood_variant_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00cc0000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


#include <windows.h>
// src/staging/blk_00cc0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00cc0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.
// src/staging/blk_00cc0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/AutoMemContext.h"
#include "../../include/hkAabb.h"
#include "../../include/Transform.h"
#include "../../include/MemoryManager.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint3.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkVector4.h"
#include "../../include/hkpConvexShape.h"
#include "../../include/hkpShape.h"
extern "C" __declspec(thread) int tls_memContext;
struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = tls_memContext;
        tls_memContext = aiMemoryContext;
    }
    ~MemContextGuard()
    {
        tls_memContext = m_iSaved;
    }
};
// The router at 0x00c85750 uses the shared prefix's heap allocator at +0x10.
struct TransformObj
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_v20;
    hkVector4 m_v30;
    hkVector4 m_v40;
    hkVector4 m_v50;
    hkVector4 m_v60;
    hkVector4 m_v70;
    int unk80;
    float m_f84;
    float m_f88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;

    static void* operator new(unsigned int nbytes)
    {
        TransformObj* p = (TransformObj*)hkMemoryRouter::getInstance().heap().blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);

    TransformObj();
};
struct TransformOwner
{
    int unk00;
    TransformObj* m_pSource;

    void ReleaseObject(TransformObj* pkObj, int iArg);
    void hkHingeLimitsConstraintCinfo_CloneData(TransformObj* pkObj, int iArg);
};
bool __stdcall bhkShape_CanShare(void* key);
struct Cd2Target
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
    virtual bool Accepts(void* key);
};
struct Cd2Entry
{
    int unk00;
    int unk04;
    Cd2Target* m_target;
};
struct Cd2Iterable
{
    virtual void v00();
    virtual void v04();
    virtual int GetFirst();
    virtual int GetNext(int i);
    virtual void v10();
    virtual Cd2Entry* GetEntry(int i, char* buffer);
};
struct Cd2Collection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Cd2Iterable m_items;
};
class Cd2Owner
{
  public:
    int unk00;
    int unk04;
    Cd2Collection* m_pShapeCollection;

    __forceinline Cd2Collection* GetCollection()
    {
        return this ? m_pShapeCollection : 0;
    }
    bool bhkShapeCollection_CanShare(void* key);
};
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_load_ps(float const*);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_rcp_ps(__m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    void _mm_store_ps(float*, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
}
extern "C" const __m128 DAT_010c71e0;
extern "C" const __m128 DAT_010c44d0;
extern "C" const __m128 DAT_010c4c00;
extern "C" const __m128 DAT_010c7170;
extern "C" const __m128 DAT_010c4c10;
struct __declspec(align(16)) PoseVector
{
    union
    {
        __m128 value;
        float lane[4];
    };
    PoseVector()
    {}
    PoseVector(__m128 x) : value(x)
    {}
    PoseVector(const PoseVector& x) : value(x.value)
    {}
    PoseVector& operator=(const PoseVector& x)
    {
        value = x.value;
        return *this;
    }
    __forceinline __m128 dot(const PoseVector& other) const
    {
        __m128 a = _mm_mul_ps(value, other.value);
        __m128 b = _mm_add_ss(_mm_shuffle_ps(a, a, 0x55), a);
        return _mm_add_ss(_mm_shuffle_ps(a, a, 0xaa), b);
    }
    __forceinline __m128 dotLoaded(const PoseVector& other) const
    {
        __m128 a = _mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&value)), other.value);
        __m128 b = _mm_add_ss(_mm_shuffle_ps(a, a, 0x55), a);
        return _mm_add_ss(_mm_shuffle_ps(a, a, 0xaa), b);
    }
    __forceinline void cross(const PoseVector& a, const PoseVector& b)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(first, second);
    }
    __forceinline void addProduct(const PoseVector& a, const PoseVector& b)
    {
        value = _mm_add_ps(_mm_mul_ps(a.value, b.value), value);
    }
    __forceinline void rotate(const PoseVector& q, const PoseVector& v)
    {
        __m128 real = _mm_shuffle_ps(q.value, q.value, 0xff);
        PoseVector square(_mm_add_ps(_mm_mul_ps(real, real), DAT_010c71e0));
        PoseVector accum(_mm_mul_ps(v.value, square.value));
        __m128 dot3 = q.dotLoaded(v);
        PoseVector dotSplat(_mm_shuffle_ps(dot3, dot3, 0));
        accum.addProduct(dotSplat, q);
        PoseVector product;
        product.cross(q, v);
        PoseVector realV(real);
        accum.addProduct(realV, product);
        value = _mm_add_ps(accum.value, accum.value);
    }
    __forceinline void rotateBack(const PoseVector& q, const PoseVector& v)
    {
        __m128 real = _mm_shuffle_ps(q.value, q.value, 0xff);
        PoseVector square(_mm_add_ps(_mm_mul_ps(real, real), DAT_010c71e0));
        PoseVector accum(_mm_mul_ps(v.value, square.value));
        __m128 dot3 = q.dot(v);
        PoseVector dotSplat(_mm_shuffle_ps(dot3, dot3, 0));
        accum.addProduct(dotSplat, q);
        PoseVector product;
        product.cross(v, q);
        PoseVector realV(real);
        accum.addProduct(realV, product);
        value = _mm_add_ps(accum.value, accum.value);
    }
};
struct PoseQuaternion
{
    PoseVector vector;
    void setMul(const PoseQuaternion&, const PoseQuaternion&);
};
extern "C" unsigned int __security_cookie;
extern "C" void __fastcall __security_check_cookie(unsigned int);
struct QuaternionProduct
{
    __m128 quad;
};
// src: COMMUNITY 0x00c66320
__declspec(noinline) void PoseQuaternion::setMul(const PoseQuaternion& a, const PoseQuaternion& b)
{
    unsigned int cookie = __security_cookie;
    PoseVector cross;
    cross.cross(a.vector, b.vector);
    __m128 aw = _mm_shuffle_ps(a.vector.value, a.vector.value, 0xff);
    __m128 bw = _mm_shuffle_ps(b.vector.value, b.vector.value, 0xff);
    __m128 xyz = _mm_add_ps(_mm_add_ps(_mm_mul_ps(aw, b.vector.value), cross.value), _mm_mul_ps(bw, a.vector.value));
    __m128 product = _mm_mul_ps(a.vector.value, b.vector.value);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    __m128 real = _mm_sub_ps(product, _mm_shuffle_ps(sum, sum, 0));
    QuaternionProduct result;
    result.quad = _mm_shuffle_ps(xyz, _mm_unpackhi_ps(xyz, real), 0xc4);
    vector.value = result.quad;
    __security_check_cookie(cookie);
}
struct PoseTransform
{
    PoseVector translation;
    PoseQuaternion rotation;
    PoseVector scale;
    PoseTransform& operator=(const PoseTransform& o)
    {
        translation = o.translation;
        rotation.vector = o.rotation.vector;
        scale = o.scale;
        return *this;
    }
    __forceinline void inverse(const PoseTransform& p)
    {
        translation.rotateBack(p.rotation.vector, p.translation);
        translation.value = _mm_xor_ps(translation.value, DAT_010c44d0);
        rotation.vector.value = _mm_xor_ps(p.rotation.vector.value, DAT_010c4c00);
        __m128 input = _mm_shuffle_ps(p.scale.value, _mm_unpackhi_ps(p.scale.value, DAT_010c7170), 0xc4);
        __m128 seed = _mm_rcp_ps(input);
        __m128 correction = _mm_mul_ps(_mm_mul_ps(input, seed), seed);
        scale.value = _mm_and_ps(_mm_sub_ps(_mm_add_ps(seed, seed), correction), DAT_010c4c10);
    }
    __forceinline void multiply(const PoseTransform& a, const PoseTransform& b)
    {
        PoseVector moved;
        moved.rotate(a.rotation.vector, b.translation);
        translation.value = _mm_add_ps(a.translation.value, moved.value);
        rotation.setMul(a.rotation, b.rotation);
        scale.value = _mm_mul_ps(a.scale.value, b.scale.value);
    }
    __forceinline void relative(const PoseTransform& a, const PoseTransform& b)
    {
        PoseTransform inverseParent;
        inverseParent.inverse(a);
        multiply(inverseParent, b);
    }
};
struct SkeletonData
{
    int unk00, unk04, unk08;
    short* parents;
    int unk10, unk14, unk18;
    int count;
};
struct PoseState
{
    SkeletonData* skeleton;
    PoseTransform* local;
    int unk08, unk0c;
    PoseTransform* world;
    int unk14, unk18;
    int* flags;
    int unk20, unk24;
    bool synchronized;
    const PoseTransform& hkaPose_calculateBoneModelSpace(int);
    __forceinline const PoseTransform& getWorld(int i)
    {
        if (!(flags[i] & 2))
            return world[i];
        return hkaPose_calculateBoneModelSpace(i);
    }
    __forceinline const PoseTransform& getLocal(int i)
    {
        if (flags[i] & 1)
        {
            const PoseTransform& boneWorld = world[i];
            short parent = skeleton->parents[i];
            if (parent != -1)
            {
                const PoseTransform& parentWorld = getWorld(parent);
                local[i].relative(parentWorld, boneWorld);
            }
            else
                local[i] = boneWorld;
            flags[i] &= ~1;
        }
        return local[i];
    }
    __forceinline void prepareChildren(int index)
    {
        const int count = skeleton->count;
        flags[index] |= 4;
        for (int bone = index + 1; bone < count; ++bone)
        {
            short parent = skeleton->parents[bone];
            if (parent != -1 && (flags[parent] & 4))
            {
                getLocal(bone);
                flags[bone] |= 4;
                synchronized = false;
            }
        }
        for (int bone = index + 1; bone < count; ++bone)
        {
            int state = flags[bone];
            if (state & 4)
            {
                state |= 2;
                state &= ~4;
                flags[bone] = state;
            }
        }
    }
    PoseTransform& hkaPose_accessBoneLocalSpace(int index);
};
struct FUN_00d4f2a0
{
    int unk00;
    unsigned short m_iElementCount;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 m_20;
    __m128 m_30;
    __m128 m_40;
    __m128 m_50;
    __m128 m_60;
    __m128 m_70;
    int unk80;
    int unk84;
    float m_88;
    float m_8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    float m_a0;
    int unkA4;
    int unkA8;
    int unkAC;
    float m_b0;
    float m_b4;
    int unkB8;
    int unkBC;

    FUN_00d4f2a0();
    static void operator delete(void* p) throw()
    {}
    static __forceinline void* operator new(unsigned int size) throw()
    {
        hkMemoryRouter& h = hkMemoryRouter::getInstance();
        void* p = h.heap().blockAlloc(size);
        ((FUN_00d4f2a0*)p)->m_iElementCount = (unsigned short)size;
        return p;
    }
};
struct FUN_00cc5f30_cls
{
    int unk00;
    FUN_00d4f2a0* m_pSrc;

    void hkRagdollLimitsConstraintCinfo_CloneData(FUN_00d4f2a0* dst, int a2);
    void ReleaseObject(FUN_00d4f2a0* dst, int a2);
};
struct S_00ccbce0_Source
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
    __m128 unk80;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
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
    float unkE4;
};
struct S_00ccbce0_Ref
{
    virtual void FUN_00ccbce0_ref0();
    virtual void FUN_00ccbce0_ref1();

    LONG unk04;
};
struct S_00ccbce0_Output
{
    int unk00;
    S_00ccbce0_Ref* unk04;
    float unk08;
    int unk0c;
    __m128 unk10;
};
struct S_00ccbce0_Owner
{
    int unk00;
    int unk04;
    S_00ccbce0_Source* unk08;
    int unk0c;
    int unk10;
    S_00ccbce0_Ref* unk14;

    void __thiscall bhkShape_CopyCinfo(S_00ccbce0_Output* value);
    void __thiscall bhkExtendedMeshShape_CopyCinfo(S_00ccbce0_Output* value);
};
extern "C" __m128 _mm_setr_ps(float, float, float, float);
struct BytePair
{
    char a;
    char b;
};
struct EntityCinfo
{
    int unk00, unk04, unk08, unk0C;
    float m_vContactPosition[4];
    float m_rotation[4];
    float unk30, unk34, unk38;
    char unk3C, unk3D;
};
struct EntityObj
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C;
    float unk50, unk54, unk58;
    char unk5C, unk5D;
    static void* operator new(unsigned int nbytes)
    {
        EntityObj* p = (EntityObj*)hkMemoryRouter::getInstance().heap().blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);
    EntityObj(int a, int b, int c);
    void SetPivots(const hkVector4& position, const hkVector4& rotation);
    void removeReference();
};
struct EntityOwner
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
    virtual void HandleNode(EntityObj* obj);
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
    virtual int AddCinfo(EntityCinfo* info);
    int bhkSpringAction_Init(EntityCinfo* info);
};
class S_00cd3c20_Obj
{
  public:
    void bhkCharacterController_UpdateState();
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
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    __m128 unk4f0;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    float unk514;
    int unk518;
    int unk51c;
    int unk520;
};
void __stdcall bhkCharacterStateClimbing_Update(S_00cd3c20_Obj* obj);
struct IntegerBlock18
{
    int unk00;
    int m_iType;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
};
struct ShapeObj
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;
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

    static void* operator new(unsigned int nbytes)
    {
        ShapeObj* p = (ShapeObj*)hkMemoryRouter::getInstance().heap().blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);

    ShapeObj(int iType, const hkVector4& kVec, float fA, float fB);
    void FUN_00c905b0();
};
struct ShapeOwner
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void addObject(struct ShapeObj* pkObj);
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void finish(struct IntegerBlock18* pkInfo);
    void bhkMotorAction_Init(IntegerBlock18* pkInfo);
};
struct S00cc4610_Ref
{
    void __thiscall FUN_00c905b0();
};
struct S00cc4610_Out
{
    int unk00;
    unsigned short m_iElementCount;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 q20;
    float m_30;
    float m_34;
    int unk38;
    int unk3C;
    S00cc4610_Out(int a, int b, int c);
    void* operator new(unsigned int n)
    {
        hkMemoryAllocator& a = hkMemoryRouter::getInstance().heap();
        void* p = a.blockAlloc(n);
        ((S00cc4610_Out*)p)->m_iElementCount = (unsigned short)n;
        return p;
    }
};
struct S00cc4610_In
{
    int unk00;
    int m_04;
    int m_08;
    int unk0C;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
};
struct S00cc4610_Scope
{
    int saved;
    S00cc4610_Scope()
    {
        saved = tls_memContext;
        tls_memContext = 0x10;
    }
    ~S00cc4610_Scope()
    {
        tls_memContext = saved;
    }
};
static inline void s00cc4610_copy(__m128& d, const __m128& s)
{
    d = s;
}
struct S00cc4610_Self
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
    virtual void v35(S00cc4610_Out* o);
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
    virtual void v47(S00cc4610_In* i);
    void bhkAngularDashpotAction_Init(S00cc4610_In* in);
};
struct Cc7Bool
{
    char value;
};
struct Cc7Local
{
    void* constraint;
    void* scheme;
    int stiffnessReference, dampingReference;
    Cc7Bool linearA[3], linearB[3];
    Cc7Bool angularA, angularB, pivotA, pivotB;
    void InitFromHelper(void* source);
    void ProcessAndReturnValue_00d52000(void* out);
    void UpdateState_00d51c30(void* tmp);
    void* ProcessAndReturnValue_00d520a0(void* out);
    void* ProcessAndReturnValue_00d51d40(void* tmp);
    void AddBridgeAtoms();
    void AppendEntryAndAdvance();
    void ProcessAndReturnValue_00d52ae0(float value);
    void hkpConstraintConstructionKit_restoreStrength();
    void AppendZeroItem();
};
struct __declspec(align(16)) Cc7Vector
{
    unsigned char lanes[16];
};
struct Cc7Tmp
{
    Cc7Vector column0, column1, column2;
    Cc7Vector translation;
    void hkTransform_setMulInverseMul(void* base, void* arg);
};
extern const float g_011c5c70_arg1;
struct Cc7Owner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    void* m04;
    void* m08;
    char* m0c;
    char* m10;
    void* m14;
    void* m18;
    void hkFixedConstraintCinfo_Fix(void* arg);
};
extern "C" void _ReadWriteBarrier();
struct TypeHeader
{
    unsigned int unk00, unk04, unk08, typeCode;
};
struct TypeAttributes
{
    unsigned int attributes;
};
struct ObjectType : TypeHeader, TypeAttributes
{
};
union __declspec(align(16)) Lane128Q
{
    float f32[4];
    unsigned __int64 u64[2];
    __int8 i8[16];
};
struct ScratchGeometry
{
    Lane128Q dimensions;
    float tolerance, radius, margin;
    unsigned char useA, useB, specialShape, useD, useE;
    void FUN_00d54de0();
};
struct LunaAction
{
    unsigned int id;
    ObjectType* source;
    void* result;
    float defaultValue;
    ScratchGeometry scratch;
};
struct LunaArgument
{
    int unk00, unk04;
    ObjectType* value;
    int unk0c;
};
struct LunaTarget
{
    unsigned int bhkMoppBvTreeShape_Init(LunaArgument* argument);
};
extern void* __cdecl hkpMoppUtility_buildCode(const void*, ScratchGeometry*, unsigned int);
union Quaternion525
{
    __m128 value;
    char bytes[16];  // the real xmmintrin __m128 also overlays __int8 m128_i8[16]
    Quaternion525()
    {}
    Quaternion525& operator=(const Quaternion525& other)
    {
        value = other.value;
        return *this;
    }
};
struct RotationSource525
{
    unsigned int unk00, unk04, unk08, unk0c;
    Quaternion525 rotation;
};
struct StringArray525 : NiTObjectArray<char*>
{
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char* const&);
    void append(char* const& value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        FUN_0096ae90(index, value);
    }
};
class PositionText525
{
  public:
    float x, y, z;
    char* GetViewerString_00a59af0(const char*);
};
extern void* DAT_01268670;
extern const char DAT_0101c29c[];
extern const char DAT_010ca6a4[];
char* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);
void __cdecl FUN_00458620(PositionText525*, const Quaternion525*);
struct RotationOwner525
{
    unsigned int unk00, unk04;
    RotationSource525* source;
    void bhkHeightFieldShape_GetViewerStrings(StringArray525*);
    void bhkPlaneShape_GetViewerStrings(StringArray525*);
};
struct TlsState
{
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
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
};
extern __declspec(thread) TlsState g_tlsState;
extern MemoryManager _g_memoryManager;
struct Holder;
extern "C" __m128 _mm_set_ps1(float);
struct CachedObj
{
    int unk00;
    int unk04;
    float unk08;
    int unk0c;
    __m128 unk10;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct Holder
{
    int unk00;
    int unk04;
    void* unk08;
    CachedObj* unk0c;
    int unk10;
    int unk14;
    void bhkExtendedMeshShape_CopyCinfo(void* p);
    CachedObj* bhkExtendedMeshShape_CreateCinfo(bool* created);
};
inline void* AllocAligned(unsigned int size)
{
    unsigned char* p = (unsigned char*)_g_memoryManager.Allocate(size);
    unsigned char pad = (unsigned char)(0x10 - ((unsigned int)p & 0xf));
    p += pad;
    p[-1] = pad;
    return p;
}
struct Mat
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};
struct NodeTransform
{
    Mat rotation;
    NiPoint3 translation;
    float scale;
};
struct TLSData
{
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
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int context;
};
extern __declspec(thread) TLSData g_tlsBlock;
struct Context
{
    unsigned int previous;
    Context()
    {
        previous = g_tlsBlock.context;
        g_tlsBlock.context = 0x10;
    }
    ~Context()
    {
        g_tlsBlock.context = previous;
    }
};
struct ConvexShapeNode
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void attach(ConvexShapeNode*, int);
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
    Mat rotation;
    NiPoint3 position;
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
    ConvexShapeNode(unsigned short);
    static void* operator new(unsigned int);
    void SetParentObject(const struct Name&);
};
extern char* emptyString;
struct Name
{
    char* value;
    static char* InternString(const char*);
    Name(const char* s) : value(InternString(s))
    {}
    ~Name()
    {
        if (value != emptyString)
            InterlockedDecrement(reinterpret_cast<volatile long*>(value) - 2);
    }
};
struct Target
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void finish(ConvexShapeNode*, void*);
};
struct Owner
{
    int unk00, unk04;
    Target* target;
};
struct Body
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Owner* owner;
    int unk1c;
    Transform transform;
};
extern Transform identity;
extern const char nodeName[];
void HK2NI_00624b10(Mat*, Transform*);
void FUN_00458620(NiPoint3*, __m128*);
struct Subject
{
    int unk00, unk04;
    Body* body;
    void bhkConvexTransformShape_BuildDisplayGeometry(ConvexShapeNode*, void*);
};
extern "C"
{
    __m128 _mm_set_ps1(float);
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
}
extern float DAT_0104da48;
extern float DAT_0104e148;
struct BoundsEntry
{
    hkVector4 translation;
    hkVector4 rotation;
    hkVector4 scale;
};
struct BoundsBox
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
    __forceinline void Include(const hkVector4& point)
    {
        m_kMinimumCorner.m_vComponents = _mm_min_ps(m_kMinimumCorner.m_vComponents, point.m_vComponents);
        m_kMaximumCorner.m_vComponents = _mm_max_ps(m_kMaximumCorner.m_vComponents, point.m_vComponents);
    }
};
class BoundsOwner
{
  public:
    SkeletonData* m_pSub;
    int unk04;
    int unk08;
    int unk0c;
    BoundsEntry* m_pEntries;
    void hkaPose_syncModelSpace();
    void ProcessEntries_00cda610(BoundsBox* out);
};
extern __declspec(thread) int DAT_tls_field;
struct S00cc2530_ScopedHeap306
{
    unsigned int old;
    S00cc2530_ScopedHeap306(unsigned int n)
    {
        old = DAT_tls_field;
        DAT_tls_field = n;
    }
    ~S00cc2530_ScopedHeap306()
    {
        DAT_tls_field = old;
    }
};
struct S00cc2530_Source306
{
    int a, b, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float m[16];
};
struct S00cc2530_FUN_00d4ce10
{
    virtual ~S00cc2530_FUN_00d4ce10();
    unsigned short memorySize;
    short references;
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
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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

    S00cc2530_FUN_00d4ce10(int, const __m128*, int);
    void removeReference();
    static void* operator new(unsigned int n)
    {
        void* p = hkMemoryRouter::getInstance().heap().blockAlloc(n);
        static_cast<S00cc2530_FUN_00d4ce10*>(p)->memorySize = (unsigned short)n;
        return p;
    }
    static void operator delete(void* p)
    {
        hkMemoryRouter::getInstance().heap().blockFree(p, 0x170);
    }
};
__forceinline __m128* BuildTransform306(S00cc2530_Source306* src, __m128* t)
{
    t[0] = _mm_setr_ps(src->m[0], src->m[1], src->m[2], src->m[3]);
    t[1] = _mm_setr_ps(src->m[4], src->m[5], src->m[6], src->m[7]);
    t[2] = _mm_setr_ps(src->m[8], src->m[9], src->m[10], src->m[11]);
    t[3] = _mm_setr_ps(src->m[12], src->m[13], src->m[14], src->m[15]);
    return t;
}
struct S00cc2530_Owner306
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
    virtual void Set(S00cc2530_FUN_00d4ce10*);
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
    virtual void OnSource(S00cc2530_Source306*);
    void bhkCachingShapePhantom_Init(S00cc2530_Source306*);
};
struct SourceGeometry
{
    unsigned int type;
    unsigned int owner;
    unsigned int count;
    unsigned int options;
    __m128 dimensions;
    unsigned int material;
    volatile unsigned int flags;
    void FUN_00c905b0();
};
struct InitializePathingRequestFromPosition
{
    unsigned int id;
    ObjectType* type;
    SourceGeometry* cachedGeometry;
    float scale;
};
struct RefCountedObject
{
    void FUN_00c905b0();
};
namespace fnvc_adapt {
extern SourceGeometry* __cdecl hkpMoppUtility_buildCode(const void* attributes, ScratchGeometry* scratch, unsigned int options);
}
extern int DAT_0102e368;
struct Shape : RefCountedObject
{
    const void** volatile methods;
    unsigned short size;
    volatile unsigned short state;
    unsigned int unk08, unk0c;
    __m128 dimensions;
    unsigned int material;
    volatile unsigned int flags;
    unsigned int combinedFlags;
    unsigned char kind;
    static void* operator new(unsigned int bytes)
    {
        hkMemoryRouter& router = hkMemoryRouter::getInstance();
        Shape* result = static_cast<Shape*>(router.heap().blockAlloc(bytes));
        result->size = (unsigned short)bytes;
        return result;
    }
    Shape(const __m128& scaled, unsigned int materialValue, unsigned int shapeFlags)
    {
        methods = reinterpret_cast<const void**>(&DAT_0102e368);
        state = 1;
        dimensions = scaled;
        flags = shapeFlags;
        material = materialValue;
        combinedFlags = shapeFlags | 0x80000000u;
        kind = 2;
    }
};
struct FUN_00cc9d00 : RefCountedObject
{
    unsigned int unk00;
    unsigned short size;
    volatile unsigned short state;
    unsigned int unk08, unk0c;
    __m128 dimensions;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    FUN_00cc9d00(ObjectType* type, Shape* shape, SourceGeometry* geometry);
    static void* operator new(unsigned int bytes)
    {
        hkMemoryRouter& router = hkMemoryRouter::getInstance();
        FUN_00cc9d00* result = static_cast<FUN_00cc9d00*>(router.heap().blockAlloc(bytes));
        result->size = (unsigned short)bytes;
        return result;
    }
    static void operator delete(void* memory);
};
struct OutputHandler
{
    void bhkMoppBvTreeShape_Init_00cca6f0(InitializePathingRequestFromPosition* request);
};
typedef void(__thiscall* OutputMethod)(OutputHandler*, void*);
typedef void(__thiscall* RequestMethod)(OutputHandler*, InitializePathingRequestFromPosition*);
struct ThreadTlsBlock
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern volatile unsigned int DAT_0126fd98;
struct TlsFlagGuard
{
    ThreadTlsBlock* m_blk;
    unsigned int m_saved;
    TlsFlagGuard()
    {
        unsigned int index = DAT_0126fd98;
        m_blk = reinterpret_cast<ThreadTlsBlock**>(__readfsdword(0x2c))[index];
        m_saved = m_blk->m_2b4;
        m_blk->m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        m_blk->m_2b4 = m_saved;
    }
};
extern unsigned int DAT_01268694;
extern float DAT_010c72bc;
struct NameArr
{
    virtual ~NameArr();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int n);
    void FUN_0096ae90(unsigned int i, const unsigned int& v);
};
struct __declspec(align(16)) Blk
{
    int i0;
    float f4;
    float f8;
    float fc;
    float v0, v1, v2, v3;
    float w0, w1, w2, w3;
    float z0;
    float z1, z2;
};
struct TagObj
{
    float x, y, z;
    unsigned int GetViewerString_00a59af0(const char* s);
};
unsigned int __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int v);
namespace fnvc_adapt {
unsigned int __cdecl NiGetViewerString_00a7d550(const char* s, float f);
}
void __cdecl HK2NINS(TagObj* t, const __m128* v);
extern const char g_011d3e74_arg1[];
extern const char str_010ca918[];
extern const char str_010ca914[];
class NamedShape
{
  public:
    unsigned int unk00;
    void WriteLimitedHingeData(Blk* b);
    void bhkConvexShape_GetViewerStrings(NameArr* arr);
    void bhkCylinderShape_GetViewerStrings(NameArr* arr);
};
static void AddName(NameArr* arr, const unsigned int& v)
{
    unsigned int n = arr->m_usSize;
    if (n >= arr->m_usMaxSize)
    {
        arr->FUN_0096ad30(n + arr->m_usGrowBy);
    }
    arr->FUN_0096ae90(n, v);
}
extern "C" void _mm_store_ss(float*, __m128);
struct AlignedPairData
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int m_type;
    int unk28;
    int unk2C;
    hkVector4 unk30;
    hkVector4 unk40;
    hkVector4 unk50;
    hkVector4 unk60;
};
template <int ELEMENTSIZE> __forceinline void memCpyOneAligned(void* dst, const void* src)
{
    int i = 0;
    do
    {
        static_cast<unsigned __int64*>(dst)[i] = static_cast<const unsigned __int64*>(src)[i];
    } while (++i < int(ELEMENTSIZE / 8));
}
struct ContactArray
{
    AlignedPairData* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline AlignedPairData& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpyOneAligned<sizeof(AlignedPairData)>(m_data + index, m_data + m_iElementCount);
    }
};
struct ContactManifold
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int unk08;
    int unk0C;
    ContactArray m_kPoints;
    int unk1C;
    AlignedPairData m_kStorage[8];
    ContactManifold* m_other;

    void ProcessEntries_00cd3080();
};
extern "C" __m128 _mm_setzero_ps();
extern float DAT_011b153c;
struct ShapeInfo_SI
{
    int unk00;
    float m_fBoundRadius;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3C;
};
struct ShapeObj_SI : hkpConvexShape
{
    unsigned short unk14;
    unsigned char unk16;
    unsigned char unk17;
    hkVector4 m_v20;
    hkVector4 m_v30;
    hkVector4 m_v40;
    hkVector4 m_v50;

    __forceinline ShapeObj_SI(const hkVector4& a, const hkVector4& b, const hkVector4& c, float fRadius = DAT_011b153c)
        : hkpConvexShape(3, fRadius)
    {
        m_v20.m_vComponents = a.m_vComponents;
        m_v30.m_vComponents = b.m_vComponents;
        m_v40.m_vComponents = c.m_vComponents;
        m_v50.m_vComponents = _mm_setzero_ps();
        unk14 = 0;
        unk17 = 0;
        unk16 = 6;
    }
    virtual ~ShapeObj_SI();
};
struct ShapeOwner_SI
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void addObject(hkReferencedObject* pkObj);
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void finish(ShapeInfo_SI* pkInfo);
    void bhkTriangleShape_Init(ShapeInfo_SI* pkInfo);
};
struct ParamSrc
{
    int unk00, unk04, unk08, unk0c;
    float m_10, m_14, m_18, m_1c;
    float m_20, m_24, m_28, m_2c;
    float m_30;
};
class CylinderInitOwner
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
    virtual void v47(ParamSrc*);
    void __thiscall CreateAndDispatchObject(const __m128& lo, const __m128& hi, float f);
    void __thiscall bhkCylinderShape_Init(ParamSrc*);
};
void* __cdecl FUN_00ec44d0(void*, const void*, unsigned);
void* __cdecl Object_DispatchCommandFour(unsigned);
void __cdecl FreeStorage(void*);
using ::MemoryManager;
using ::_g_memoryManager;
struct ExtendedMeshFloat
{
    float value;
    static void* operator new[](unsigned size)
    {
        return _g_memoryManager.Allocate(size);
    }
};
struct ExtendedMeshIndex
{
    unsigned short value;
    static void* operator new[](unsigned size)
    {
        return _g_memoryManager.Allocate(size);
    }
};
struct Triangle
{
    unsigned short a, b, c, unk06;
};
struct Region
{
    unsigned value;
    unsigned count;
    unsigned other;
};
struct Geometry
{

    unsigned unk00, unk04;

    unsigned short triangleCount, unk0A, unk0C, unk0E, regionCount, unk12;

    Triangle* triangles;

    NiPoint3* vertices;

    unsigned unk1C, unk20;

    Region* regions;

    __forceinline bool GetTriangle(unsigned short index, Triangle*& out)
    {

        out = &triangles[index];

        return index >= triangleCount;
    }
};
struct ExtendedMeshInput
{

    unsigned unk00;

    Geometry* geometry;

    float scale;

    unsigned unk0C;

    __m128 transform;
};
struct MeshPart
{
    static void* operator new[](unsigned size)
    {
        return _g_memoryManager.Allocate(size);
    }

    unsigned vertexCount;

    NiPoint3* vertices;

    unsigned triangleCount;

    unsigned short* indices;

    struct hkAabb* bounds;

    MeshPart();

    ~MeshPart();
};
struct FUN_00a5d3a0
{

    FUN_00a5d3a0();

    virtual ~FUN_00a5d3a0();

    unsigned references;
};
struct Mesh : FUN_00a5d3a0
{

    unsigned count;

    MeshPart* parts;

    static void* operator new(unsigned n)
    {
        return Object_DispatchCommandFour(n);
    }

    Mesh() : count(0), parts(0)
    {}

    virtual ~Mesh();
};
extern void* indexVtable[];
struct IndexArray
{

    void** vtable;

    ~IndexArray()
    {
        FreeStorage(data);
    }

    unsigned short* data;

    unsigned short capacity, size, used, grow;

    IndexArray()
    {
        capacity = 0;
        grow = 1;
        size = 0;
        used = 0;
        data = 0;
        vtable = indexVtable;
    }

    void Resize(unsigned);

    __forceinline void Append(unsigned short value)
    {
        SetAt(size, value);
    }

    __forceinline void SetAt(unsigned index, unsigned short value)
    {

        if (index >= capacity)
            Resize(index + grow);

        if (index >= size)
        {

            size = index + 1;

            if (value)
                ++used;
        }
        else if (value)
        {

            if (!data[index])
                ++used;
        }
        else
        {

            if (data[index])
                --used;
        }

        data[index] = value;
    }

    void Clear()
    {

        unsigned short* values = data;

        unsigned short count = size;

        for (unsigned short index = 0; index < count; ++index)
            values[index] = 0;

        size = 0;
        used = 0;
    }
};
struct __declspec(align(16)) ExtendedMeshStoredVector
{
    hkVector4 lanes;
    __forceinline ExtendedMeshStoredVector& operator=(__m128 v)
    {
        _mm_store_ps(lanes.m_f, v);
        return *this;
    }
    __forceinline operator const __m128&() const
    {
        return lanes.m_vComponents;
    }
};
struct Result
{

    Mesh* mesh;

    unsigned unk04;

    float scale;

    unsigned unk0C;

    ExtendedMeshStoredVector transform;

    Result(Mesh*);

    ~Result();
};
struct ExtendedMeshBuilder
{

    virtual void Slot00();

    virtual void Slot04();

    virtual void Slot08();

    virtual void Slot0C();

    virtual void Slot10();

    virtual void Slot14();

    virtual void Slot18();

    virtual void Slot1C();

    virtual void Slot20();

    virtual void Slot24();

    virtual void Slot28();

    virtual void Slot2C();

    virtual void Slot30();

    virtual void Slot34();

    virtual void Slot38();

    virtual void Slot3C();

    virtual void Slot40();

    virtual void Slot44();

    virtual void Slot48();

    virtual void Slot4C();

    virtual void Slot50();

    virtual void Slot54();

    virtual void Slot58();

    virtual void Slot5C();

    virtual void Slot60();

    virtual void Slot64();

    virtual void Slot68();

    virtual void Slot6C();

    virtual void Slot70();

    virtual void Slot74();

    virtual void Slot78();

    virtual void Slot7C();

    virtual void Slot80();

    virtual void Slot84();

    virtual void Slot88();

    virtual void Slot8C();

    virtual void Slot90();

    virtual void Slot94();

    virtual void Slot98();

    virtual void Slot9C();

    virtual void SlotA0();

    virtual void SlotA4();

    virtual void SlotA8();

    virtual void SlotAC();

    virtual void Apply(Result*);

    void bhkExtendedMeshShape_Init_00ccc980(ExtendedMeshInput*);
};
void* __cdecl NiMalloc(unsigned);
__declspec(noinline) void IndexArray::Resize(unsigned requested)
{

    if (requested == capacity)
        return;

    if (requested < size)
    {

        for (unsigned short i = (unsigned short)requested; i < size; ++i)
        {

            if (data[i])
            {
                data[i] = 0;
                --used;
            }
        }

        size = (unsigned short)requested;
    }

    unsigned short* old = data;

    capacity = (unsigned short)requested;

    if (requested > 0)
    {

        data = (unsigned short*)NiMalloc((unsigned short)requested * 2);

        for (unsigned short i = 0; i < size; ++i)
            data[i] = old[i];

        for (unsigned short i = size; i < capacity; ++i)
            data[i] = 0;
    }
    else
        data = 0;

    FreeStorage(old);
}
struct FUN_00ccea00Block
{
    __m128 m_v0;
    __m128 m_v1;
    __m128 m_v2;
    __m128 m_v3;
};
struct FUN_00ccea00Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FUN_00ccea00Block m_20;
};
struct FUN_00ccea00Out
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00ccea00Block m_10;
};
extern FUN_00ccea00Block DAT_01268370;
struct FUN_00ccea00Holder
{
    int unk00;
    int unk04;
    FUN_00ccea00Inner* m_08;

    void bhkConvexShape_CopyCinfo(FUN_00ccea00Out* out);
    void bhkConvexTransformShape_CopyCinfo(FUN_00ccea00Out* out);
};

#include <math.h>
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, __m128);

extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;
extern const double DAT_01011588;
extern const double DAT_010cb650;
extern const double DAT_0109deb0;

inline float sqrt_cdb910(float x)
{
    return sqrt(x);
}

inline hkVector4::hkVector4(const hkVector4& o)
{
    m_vComponents = o.m_vComponents;
}
inline void hkVector4::operator=(const hkVector4& o)
{
    m_vComponents = o.m_vComponents;
}
__forceinline float hkVector4::dot3scalar(const hkVector4& o) const
{
    __m128 p = _mm_mul_ps(m_vComponents, o.m_vComponents);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    float r;
    _mm_store_ss(&r, s);
    return r;
}
__forceinline void hkVector4::setCross(const hkVector4& a, const hkVector4& b)
{
    __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                           _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
    __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                           _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(c0, c1);
}
__forceinline void hkVector4::mul4(const float& s)
{
    __m128 q = _mm_load_ss(&s);
    q = _mm_shuffle_ps(q, q, 0);
    m_vComponents = _mm_mul_ps(m_vComponents, q);
}
inline float& hkVector4::operator()(int i)
{
    return m_f[i];
}
__forceinline void hkVector4::normalize4()
{
    __m128 l = _mm_mul_ps(m_vComponents, m_vComponents);
    l = _mm_add_ps(_mm_shuffle_ps(l, l, 0x4e), l);
    l = _mm_add_ps(_mm_shuffle_ps(l, l, 0xb1), l);
    __m128 e = _mm_rsqrt_ss(l);
    __m128 zero = _mm_set_ss(DAT_01011d78);
    __m128 three = _mm_set_ss(DAT_01017718);
    __m128 half = _mm_set_ss(DAT_01016248);
    __m128 ree = _mm_mul_ss(_mm_mul_ss(l, e), e);
    __m128 mask = _mm_cmpeq_ss(l, zero);
    __m128 res = _mm_mul_ss(_mm_mul_ss(half, e), _mm_sub_ss(three, ree));
    res = _mm_andnot_ps(mask, res);
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(res, res, 0), m_vComponents);
}

extern const hkVector4 DAT_010c71b0;

struct Quat_cdb910
{
    hkVector4 m_vec;
    void hkQuaternionf_setFlippedRotation(const hkVector4& from);
    void UpdateState_00cdb910(float t, const hkVector4& from, const hkVector4& to);
};

// @fnv 0x00cdb910
// src: GUESS 0x00cdb910 (confidence: low)
void Quat_cdb910::UpdateState_00cdb910(float t, const hkVector4& from, const hkVector4& to)
{
    float d = from.dot3scalar(to);
    float c = t * d + (1.0f - t);
    float v = (1.0f + c) * DAT_01011588;
    if (v <= 0.0f || d < DAT_010cb650)
    {
        hkQuaternionf_setFlippedRotation(from);
        return;
    }
    {
        if (d > DAT_0109deb0)
        {
            m_vec = DAT_010c71b0;
            return;
        }
        float s = sqrt_cdb910(v);
        float scale = (t * DAT_01011588) / s;
        hkVector4 axis;
        axis.setCross(from, to);
        axis.mul4(scale);
        axis(3) = s;
        axis.normalize4();
        m_vec = axis;
    }
}
