#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// src/staging/blk_00cc0000_od_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00cc0000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


#include <windows.h>
// src/staging/blk_00cc0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00cc0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.
// src/staging/blk_00cc0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
// Keep the unit's intrinsic storage declaration: VC9 treats the SDK's
// additional byte arrays as stack buffers and emits different /GS code.
#define _INCLUDED_MM2
// Exe 0x00ccbf00 FUN_00ccbf00: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
// hkMonitorStream as the original's two-joint solver reads it: bare members with the cursor typed as a timer record, and a
// flat timer record. The real header's hkPadSpu members and Command-based record change FUN_00cdbae0's code.
// src: HAVOK_SRC (shape)
struct hkMonitorStream_raw
{
    struct TimerCommand { const char* m_commandAndMonitor; unsigned int m_time0; unsigned int m_time1; void setTime(); };
    char* m_start;
    TimerCommand* m_end;
    char* m_capacity;
    TimerCommand* m_capacityMinus16;
};
#include "../../include/NiPoint3.h"
#include "../../include/hkBool.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkaSkeleton.h"
#include "../../include/hkpConvexShape.h"
#include "../../include/hkpShape.h"
#include "../../include/AutoMemContext.h"
#include "../../include/hkAabb.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiPoint3.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkVector4.h"
#include "../../include/hkTransform.h"
#include "../../include/hkMemoryRouter.h"
// hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant: local type (was include/hkVec4Q.h, which had no evidence of one real class); no method of it is bound to a named game function
__if_not_exists(__m128)
{
#include <xmmintrin.h>
}

extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);

struct hkMat3Q;

class hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant
{
public:
    LocalM128 m_vComponents;

    __forceinline LocalM128 getSimdAt(int) const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }

    __forceinline void addMul4(LocalM128 r, const hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r, r, 0), a.m_vComponents));
    }

    __forceinline void setSub4(const hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant& a, const hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }

    __forceinline void setCross(const hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant& v1, const hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant& v2)
    {
        LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                  _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                  _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }

    __forceinline void setMul4(const hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant& a, const hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }

    __forceinline void add4(const hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }

    __forceinline LocalM128 dot3(const hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant& a) const
    {
        LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        LocalM128 result = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), result);
    }

    void _setRotatedDir(const struct hkMat3Q& r, const hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant& b);
    void _setRotatedInverseDir(const struct hkMat3Q& r, const hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant& b);
};
#include "../../include/hkQsTransform.h"

extern "C" {
LocalM128 _mm_rcp_ps(LocalM128); LocalM128 _mm_mul_ps(LocalM128,LocalM128);
LocalM128 _mm_sub_ps(LocalM128,LocalM128); LocalM128 _mm_add_ps(LocalM128,LocalM128);
}
extern "C" __declspec(thread) int tls_memContext;
struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext) { m_iSaved = tls_memContext; tls_memContext = aiMemoryContext; }
    ~MemContextGuard() { tls_memContext = m_iSaved; }
};

// The per-thread router accessor is 0x00c85750; its heap allocator is at +0x10.



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

    __forceinline Cd2Collection* GetCollection() { return this ? m_pShapeCollection : 0; }
    bool bhkShapeCollection_CanShare(void* key);
};
extern "C" {
LocalM128 _mm_add_ps(LocalM128, LocalM128);
LocalM128 _mm_add_ss(LocalM128, LocalM128);
LocalM128 _mm_and_ps(LocalM128, LocalM128);
LocalM128 _mm_load_ps(float const*);
LocalM128 _mm_mul_ps(LocalM128, LocalM128);
LocalM128 _mm_rcp_ps(LocalM128);
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
void _mm_store_ps(float*, LocalM128);
LocalM128 _mm_sub_ps(LocalM128, LocalM128);
LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
LocalM128 _mm_xor_ps(LocalM128, LocalM128);
}
extern "C" const LocalM128 DAT_010c71e0;
extern "C" const LocalM128 DAT_010c44d0;
extern "C" const LocalM128 DAT_010c4c00;
extern "C" const LocalM128 DAT_010c7170;
extern "C" const LocalM128 DAT_010c4c10;
struct __declspec(align(16)) PoseVector {
    union { LocalM128 value; float lane[4]; };
    PoseVector() {}
    PoseVector(LocalM128 x):value(x) {}
    PoseVector(const PoseVector& x):value(x.value) {}
    PoseVector& operator=(const PoseVector& x) { value=x.value; return *this; }
    __forceinline LocalM128 dot(const PoseVector& other) const {
        LocalM128 a=_mm_mul_ps(value,other.value);
        LocalM128 b=_mm_add_ss(_mm_shuffle_ps(a,a,0x55),a);
        return _mm_add_ss(_mm_shuffle_ps(a,a,0xaa),b);
    }
    __forceinline LocalM128 dotLoaded(const PoseVector& other) const {
        LocalM128 a=_mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&value)),other.value);
        LocalM128 b=_mm_add_ss(_mm_shuffle_ps(a,a,0x55),a);
        return _mm_add_ss(_mm_shuffle_ps(a,a,0xaa),b);
    }
    __forceinline void cross(const PoseVector& a,const PoseVector& b) {
        LocalM128 first=_mm_mul_ps(_mm_shuffle_ps(a.value,a.value,0xc9),_mm_shuffle_ps(b.value,b.value,0xd2));
        LocalM128 second=_mm_mul_ps(_mm_shuffle_ps(a.value,a.value,0xd2),_mm_shuffle_ps(b.value,b.value,0xc9));
        value=_mm_sub_ps(first,second);
    }
    __forceinline void addProduct(const PoseVector& a,const PoseVector& b) {value=_mm_add_ps(_mm_mul_ps(a.value,b.value),value);}
    __forceinline void rotate(const PoseVector& q,const PoseVector& v) {
        LocalM128 real=_mm_shuffle_ps(q.value,q.value,0xff);
        PoseVector square(_mm_add_ps(_mm_mul_ps(real,real),DAT_010c71e0));
        PoseVector accum(_mm_mul_ps(v.value,square.value));
        LocalM128 dot3=q.dotLoaded(v);
        PoseVector dotSplat(_mm_shuffle_ps(dot3,dot3,0));
        accum.addProduct(dotSplat,q);
        PoseVector product;product.cross(q,v);
        PoseVector realV(real);accum.addProduct(realV,product);
        value=_mm_add_ps(accum.value,accum.value);
    }
    __forceinline void rotateBack(const PoseVector& q,const PoseVector& v) {
        LocalM128 real=_mm_shuffle_ps(q.value,q.value,0xff);
        PoseVector square(_mm_add_ps(_mm_mul_ps(real,real),DAT_010c71e0));
        PoseVector accum(_mm_mul_ps(v.value,square.value));
        LocalM128 dot3=q.dot(v);
        PoseVector dotSplat(_mm_shuffle_ps(dot3,dot3,0));
        accum.addProduct(dotSplat,q);
        PoseVector product;product.cross(v,q);
        PoseVector realV(real);accum.addProduct(realV,product);
        value=_mm_add_ps(accum.value,accum.value);
    }
};
struct PoseQuaternion {PoseVector vector; void setMul(const PoseQuaternion&,const PoseQuaternion&);};
extern "C" unsigned int __security_cookie;
extern "C" void __fastcall __security_check_cookie(unsigned int);
struct QuaternionProduct {LocalM128 quad;};
// src: COMMUNITY 0x00c66320
__declspec(noinline) void PoseQuaternion::setMul(const PoseQuaternion& a,const PoseQuaternion& b) {
    unsigned int cookie=__security_cookie;
    PoseVector cross;cross.cross(a.vector,b.vector);
    LocalM128 aw=_mm_shuffle_ps(a.vector.value,a.vector.value,0xff);
    LocalM128 bw=_mm_shuffle_ps(b.vector.value,b.vector.value,0xff);
    LocalM128 xyz=_mm_add_ps(_mm_add_ps(_mm_mul_ps(aw,b.vector.value),cross.value),_mm_mul_ps(bw,a.vector.value));
    LocalM128 product=_mm_mul_ps(a.vector.value,b.vector.value);
    LocalM128 sum=_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
    sum=_mm_add_ss(_mm_shuffle_ps(product,product,0xaa),sum);
    LocalM128 real=_mm_sub_ps(product,_mm_shuffle_ps(sum,sum,0));
    QuaternionProduct result;
    result.quad=_mm_shuffle_ps(xyz,_mm_unpackhi_ps(xyz,real),0xc4);
    vector.value=result.quad;
    __security_check_cookie(cookie);
}
struct PoseTransform {
    PoseVector translation;
    PoseQuaternion rotation;
    PoseVector scale;
    PoseTransform& operator=(const PoseTransform& o) {translation=o.translation;rotation.vector=o.rotation.vector;scale=o.scale;return *this;}
    __forceinline void inverse(const PoseTransform& p) {
        translation.rotateBack(p.rotation.vector,p.translation);
        translation.value=_mm_xor_ps(translation.value,DAT_010c44d0);
        rotation.vector.value=_mm_xor_ps(p.rotation.vector.value,DAT_010c4c00);
        LocalM128 input=_mm_shuffle_ps(p.scale.value,_mm_unpackhi_ps(p.scale.value,DAT_010c7170),0xc4);
        LocalM128 seed=_mm_rcp_ps(input);
        LocalM128 correction=_mm_mul_ps(_mm_mul_ps(input,seed),seed);
        scale.value=_mm_and_ps(_mm_sub_ps(_mm_add_ps(seed,seed),correction),DAT_010c4c10);
    }
    __forceinline void multiply(const PoseTransform& a,const PoseTransform& b) {
        PoseVector moved;moved.rotate(a.rotation.vector,b.translation);
        translation.value=_mm_add_ps(a.translation.value,moved.value);
        rotation.setMul(a.rotation,b.rotation);
        scale.value=_mm_mul_ps(a.scale.value,b.scale.value);
    }
    __forceinline void relative(const PoseTransform& a,const PoseTransform& b) {
        PoseTransform inverseParent;inverseParent.inverse(a);multiply(inverseParent,b);
    }
};
struct SkeletonData {
    int unk00,unk04,unk08;short* parents;
    int unk10,unk14,unk18;int count;
};
struct PoseState {
    SkeletonData* skeleton;PoseTransform* local;int unk08,unk0c;
    PoseTransform* world;int unk14,unk18;int* flags;int unk20,unk24;
    bool synchronized;
    const PoseTransform& hkaPose_calculateBoneModelSpace(int);
    __forceinline const PoseTransform& getWorld(int i) {
        if(!(flags[i]&2))return world[i];
        return hkaPose_calculateBoneModelSpace(i);
    }
    __forceinline const PoseTransform& getLocal(int i) {
        if(flags[i]&1) {
            const PoseTransform& boneWorld=world[i];
            short parent=skeleton->parents[i];
            if(parent!=-1) {const PoseTransform& parentWorld=getWorld(parent);local[i].relative(parentWorld,boneWorld);}
            else local[i]=boneWorld;
            flags[i]&=~1;
        }
        return local[i];
    }
    __forceinline void prepareChildren(int index) {
        const int count=skeleton->count;
        flags[index]|=4;
        for(int bone=index+1;bone<count;++bone) {
            short parent=skeleton->parents[bone];
            if(parent!=-1 && (flags[parent]&4)) {
                getLocal(bone);flags[bone]|=4;synchronized=false;
            }
        }
        for(int bone=index+1;bone<count;++bone) {
            int state=flags[bone];
            if(state&4) {state|=2;state&=~4;flags[bone]=state;}
        }
    }
    PoseTransform& hkaPose_accessBoneLocalSpace(int index);
};
struct SpawnAllocator {
    virtual void v00();
    virtual void* Alloc(unsigned int size);
};
struct SpawnHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnAllocator* m_pAllocator;
};
struct FUN_00d4f2a0 {
    int unk00;
    unsigned short m_iElementCount;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    LocalM128 m_20;
    LocalM128 m_30;
    LocalM128 m_40;
    LocalM128 m_50;
    LocalM128 m_60;
    LocalM128 m_70;
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
    static void operator delete(void* p) throw() {}
    static __forceinline void* operator new(unsigned int size) throw() {
        SpawnHolder* h = (SpawnHolder*)&hkMemoryRouter::getInstance();
        void* p = h->m_pAllocator->Alloc(size);
        ((FUN_00d4f2a0*)p)->m_iElementCount = (unsigned short)size;
        return p;
    }
};
struct FUN_00cc5f30_cls {
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
    LocalM128 unk80;
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
    LocalM128 unk10;
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
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
union hkVec4 { LocalM128 m_vComponents; char m_bytes[16]; };
struct BytePair { char a; char b; };
struct EntityCinfo {
    int unk00, unk04, unk08, unk0C;
    float m_vContactPosition[4];
    float m_rotation[4];
    float unk30, unk34, unk38;
    char unk3C, unk3D;
};
struct EntityObj {
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C;
    float unk50, unk54, unk58;
    char unk5C, unk5D;
    static void* operator new(unsigned int nbytes) {
        EntityObj* p=(EntityObj*)hkMemoryRouter::getInstance().heap().blockAlloc(nbytes);
        p->m_usMemSizeAndFlags=(unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);
    EntityObj(int a,int b,int c);
    void SetPivots(const hkVector4& position,const hkVector4& rotation);
    void removeReference();
};
struct EntityOwner {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34();
    virtual void HandleNode(EntityObj* obj);
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46();
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
    LocalM128 unk4f0;
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
struct ShapeVector
{
    hkVec4 m_v;
    ShapeVector(float x, float y, float z, float w) { m_v.m_vComponents = _mm_setr_ps(x, y, z, w); }
};
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

    ShapeObj(int iType, const ShapeVector& kVec, float fA, float fB);
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
struct S00cc4610_Ref { void __thiscall FUN_00c905b0(); };
struct S00cc4610_Out {
    int unk00; unsigned short m_iElementCount; unsigned short unk06; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    LocalM128 q20;
    float m_30;
    float m_34;
    int unk38; int unk3C;
    S00cc4610_Out(int a, int b, int c);
    void* operator new(unsigned int n) {
        hkMemoryAllocator& a = hkMemoryRouter::getInstance().heap();
        void* p = a.blockAlloc(n);
        ((S00cc4610_Out*)p)->m_iElementCount = (unsigned short)n;
        return p;
    }
};
struct S00cc4610_In {
    int unk00; int m_04; int m_08; int unk0C;
    float m_10; float m_14; float m_18; float m_1c; float m_20; float m_24;
};
struct S00cc4610_Scope {
    int saved;
    S00cc4610_Scope() { saved = tls_memContext; tls_memContext = 0x10; }
    ~S00cc4610_Scope() { tls_memContext = saved; }
};
static inline void s00cc4610_copy(LocalM128& d, const LocalM128& s) { d = s; }
struct S00cc4610_Self {
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
struct Cc7Bool { char value; };
struct Cc7Local {
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
struct __declspec(align(16)) Cc7Vector { unsigned char lanes[16]; };
struct Cc7Tmp {
    Cc7Vector column0, column1, column2;
    Cc7Vector translation;
    void hkTransform_setMulInverseMul(void* base, void* arg);
};
extern const float g_011c5c70_arg1;
struct Cc7Owner {
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
struct TypeHeader { unsigned int unk00, unk04, unk08, typeCode; };
struct TypeAttributes { unsigned int attributes; };
struct ObjectType : TypeHeader, TypeAttributes {};
union __declspec(align(16)) Lane128Q { float f32[4]; unsigned __int64 u64[2]; __int8 i8[16]; };
struct ScratchGeometry {
    Lane128Q dimensions;
    float tolerance, radius, margin;
    unsigned char useA, useB, specialShape, useD, useE;
    void FUN_00d54de0();
};
struct LunaAction {
    unsigned int id;
    ObjectType* source;
    void* result;
    float defaultValue;
    ScratchGeometry scratch;
};
struct LunaArgument {
    int unk00, unk04;
    ObjectType* value;
    int unk0c;
};
struct LunaTarget { unsigned int bhkMoppBvTreeShape_Init(LunaArgument* argument); };
extern void* __cdecl hkpMoppUtility_buildCode(const void*, ScratchGeometry*, unsigned int);
union Quaternion525 {
    LocalM128 value;
    char bytes[16]; // the real xmmintrin __m128 also overlays __int8 m128_i8[16]
    Quaternion525() {}
    Quaternion525& operator=(const Quaternion525& other) { value=other.value; return *this; }
};
struct RotationSource525 { unsigned int unk00,unk04,unk08,unk0c; Quaternion525 rotation; };
struct StringArray525 : NiTObjectArray<char*> {
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int,char* const&);
    void append(char* const& value) {
        unsigned int index=m_usSize;
        if(index>=m_usMaxSize) FUN_0096ad30(index+m_usGrowBy);
        FUN_0096ae90(index,value);
    }
};
class PositionText525 {
public:
    float x,y,z;
    char* GetViewerString_00a59af0(const char*);
};
extern void* DAT_01268670;
extern const char DAT_0101c29c[];
extern const char DAT_010ca6a4[];
char* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
char* __cdecl NiGetViewerString_00a7d550(const char*,float);
void __cdecl FUN_00458620(PositionText525*,const Quaternion525*);
struct RotationOwner525 {
    unsigned int unk00,unk04;
    RotationSource525* source;
    void bhkHeightFieldShape_GetViewerStrings(StringArray525*);
    void bhkPlaneShape_GetViewerStrings(StringArray525*);
};
struct TlsState { int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; };
extern __declspec(thread) TlsState g_tlsState;
extern MemoryManager _g_memoryManager;
struct Holder;
struct CinfoVector {
    hkVec4 value;
    __forceinline CinfoVector(LocalM128 vector) { value.m_vComponents = vector; }
};
extern "C" LocalM128 _mm_set_ps1(float);
struct CachedObj {
    int unk00;
    int unk04;
    float unk08;
    int unk0c;
    LocalM128 unk10;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct Holder {
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

struct Mat { float xx,xy,xz,yx,yy,yz,zx,zy,zz; };
struct NodeTransform { Mat rotation; NiPoint3 translation; float scale; };
union __declspec(align(16)) BodyTransform { struct { LocalM128 a,b,c,d; }; char bytes[64]; };
struct TLSData {
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
int context; };
extern __declspec(thread) TLSData g_tlsBlock;
struct Context {
 unsigned int previous;
 Context() { previous=g_tlsBlock.context; g_tlsBlock.context=0x10; }
 ~Context() { g_tlsBlock.context=previous; }
};
struct ConvexShapeNode {
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
virtual void attach(ConvexShapeNode*,int);
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
Mat rotation; NiPoint3 position;
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
ConvexShapeNode(unsigned short); static void* operator new(unsigned int); void SetParentObject(const struct Name&); };
extern char* emptyString;
struct Name { char* value; static char* InternString(const char*); Name(const char* s):value(InternString(s)){} ~Name(){if(value!=emptyString) InterlockedDecrement(reinterpret_cast<volatile long*>(value)-2);} };
struct Target {
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
virtual void finish(ConvexShapeNode*,void*); };
struct Owner { int unk00,unk04; Target* target; };
struct Body { int unk00,unk04,unk08,unk0c,unk10,unk14; Owner* owner; int unk1c; BodyTransform transform; };
extern BodyTransform identity;
extern const char nodeName[];
void HK2NI_00624b10(Mat*,BodyTransform*);
void FUN_00458620(NiPoint3*,LocalM128*);
struct Subject { int unk00,unk04; Body* body; void bhkConvexTransformShape_BuildDisplayGeometry(ConvexShapeNode*,void*); };
extern "C" {
LocalM128 _mm_set_ps1(float);
LocalM128 _mm_min_ps(LocalM128, LocalM128);
LocalM128 _mm_max_ps(LocalM128, LocalM128);
}
extern float DAT_0104da48;
extern float DAT_0104e148;
struct BoundsVector : hkVector4
{
    __forceinline const LocalM128& Get() const { return m_vComponents; }
    __forceinline void SetAll(float value) { m_vComponents = _mm_set_ps1(value); }
    __forceinline void Min(const BoundsVector& a, const BoundsVector& b)
    {
        m_vComponents = _mm_min_ps(a.Get(), b.Get());
    }
    __forceinline void Max(const BoundsVector& a, const BoundsVector& b)
    {
        m_vComponents = _mm_max_ps(a.Get(), b.Get());
    }
};
struct BoundsEntry
{
    BoundsVector translation;
    BoundsVector rotation;
    BoundsVector scale;
};
struct BoundsBox
{
    BoundsVector m_kMinimumCorner;
    BoundsVector m_kMaximumCorner;
    __forceinline void Include(const BoundsVector& point)
    {
        m_kMinimumCorner.Min(m_kMinimumCorner, point);
        m_kMaximumCorner.Max(m_kMaximumCorner, point);
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
struct S00cc2530_ScopedHeap306 {
 unsigned int old;
 S00cc2530_ScopedHeap306(unsigned int n) {old=DAT_tls_field;DAT_tls_field=n;}
 ~S00cc2530_ScopedHeap306() {DAT_tls_field=old;}
};
struct S00cc2530_Alloc306 {virtual void f0();virtual void* Allocate(int);virtual void Free(void*,int);};
struct S00cc2530_Router306 {int unk00,unk04,unk08,unk0c;S00cc2530_Alloc306* heap; S00cc2530_Alloc306* GetAllocator() {return heap;}};
namespace Memory306 {extern "C" S00cc2530_Router306* hkMemoryRouter_getInstance();}
struct S00cc2530_Source306 {int a,b,unk08,unk0c,unk10,unk14,unk18,unk1c;float m[16];};
struct __declspec(align(16)) Transform306 {float m[16];};
struct S00cc2530_FUN_00d4ce10 {
 virtual ~S00cc2530_FUN_00d4ce10();
 unsigned short memorySize;short references;
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

 S00cc2530_FUN_00d4ce10(int, const LocalM128*,int);
 void removeReference();
 static void* operator new(unsigned int n) {
  void* p=Memory306::hkMemoryRouter_getInstance()->GetAllocator()->Allocate(n);
  static_cast<S00cc2530_FUN_00d4ce10*>(p)->memorySize=(unsigned short)n;
  return p;
 }
 static void operator delete(void* p) {Memory306::hkMemoryRouter_getInstance()->GetAllocator()->Free(p,0x170);}
};
__forceinline LocalM128* BuildTransform306(S00cc2530_Source306* src,LocalM128* t) {
t[0]=_mm_setr_ps(src->m[0],src->m[1],src->m[2],src->m[3]);
t[1]=_mm_setr_ps(src->m[4],src->m[5],src->m[6],src->m[7]);
t[2]=_mm_setr_ps(src->m[8],src->m[9],src->m[10],src->m[11]);
t[3]=_mm_setr_ps(src->m[12],src->m[13],src->m[14],src->m[15]);
return t;}
struct S00cc2530_Owner306 {
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
struct SourceGeometry {
    unsigned int type;
    unsigned int owner;
    unsigned int count;
    unsigned int options;
    LocalM128 dimensions;
    unsigned int material;
    volatile unsigned int flags;
    void FUN_00c905b0();
};
struct InitializePathingRequestFromPosition {
    unsigned int id;
    ObjectType* type;
    SourceGeometry* cachedGeometry;
    float scale;
};
struct RefCountedObject {
    void FUN_00c905b0();
};
namespace fnvc_adapt { extern SourceGeometry* __cdecl hkpMoppUtility_buildCode(const void* attributes,
                                              ScratchGeometry* scratch,
                                              unsigned int options); }
extern int DAT_0102e368;
struct Shape : RefCountedObject {
    const void** volatile methods;
    unsigned short size;
    volatile unsigned short state;
    unsigned int unk08, unk0c;
    LocalM128 dimensions;
    unsigned int material;
    volatile unsigned int flags;
    unsigned int combinedFlags;
    unsigned char kind;
    static void* operator new(unsigned int bytes) {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        Shape* result = static_cast<Shape*>(router->heap().blockAlloc(bytes));
        result->size = (unsigned short)bytes;
        return result;
    }
    Shape(const LocalM128& scaled, unsigned int materialValue, unsigned int shapeFlags) {
        methods = reinterpret_cast<const void**>(&DAT_0102e368);
        state = 1;
        dimensions = scaled;
        flags = shapeFlags;
        material = materialValue;
        combinedFlags = shapeFlags | 0x80000000u;
        kind = 2;
    }
};
struct FUN_00cc9d00 : RefCountedObject {
    unsigned int unk00;
    unsigned short size;
    volatile unsigned short state;
    unsigned int unk08, unk0c;
    LocalM128 dimensions;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    FUN_00cc9d00(ObjectType* type, Shape* shape, SourceGeometry* geometry);
    static void* operator new(unsigned int bytes) {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        FUN_00cc9d00* result = static_cast<FUN_00cc9d00*>(router->heap().blockAlloc(bytes));
        result->size = (unsigned short)bytes;
        return result;
    }
    static void operator delete(void* memory);
};
struct OutputHandler {
    void bhkMoppBvTreeShape_Init_00cca6f0(InitializePathingRequestFromPosition* request);
};
typedef void (__thiscall *OutputMethod)(OutputHandler*, void*);
typedef void (__thiscall *RequestMethod)(OutputHandler*, InitializePathingRequestFromPosition*);
struct ThreadTlsBlock {
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
struct TlsFlagGuard {
    ThreadTlsBlock* m_blk;
    unsigned int m_saved;
    TlsFlagGuard() { unsigned int index = DAT_0126fd98; m_blk = reinterpret_cast<ThreadTlsBlock**>(__readfsdword(0x2c))[index]; m_saved = m_blk->m_2b4; m_blk->m_2b4 = 0x10; }
    ~TlsFlagGuard() { m_blk->m_2b4 = m_saved; }
};
extern unsigned int DAT_01268694;
extern float DAT_010c72bc;
struct NameArr {
    virtual ~NameArr();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int n);
    void FUN_0096ae90(unsigned int i, const unsigned int& v);
};
struct __declspec(align(16)) Blk {
    int i0;
    float f4;
    float f8;
    float fc;
    float v0, v1, v2, v3;
    float w0, w1, w2, w3;
    float z0;
    float z1, z2;
};
struct TagObj {
    float x, y, z;
    unsigned int GetViewerString_00a59af0(const char* s);
};
unsigned int __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int v);
namespace fnvc_adapt { unsigned int __cdecl NiGetViewerString_00a7d550(const char* s, float f); }
void __cdecl HK2NINS(TagObj* t, const LocalM128* v);
extern const char g_011d3e74_arg1[];
extern const char str_010ca918[];
extern const char str_010ca914[];
class NamedShape {
public:
    unsigned int unk00;
    void WriteLimitedHingeData(Blk* b);
    void bhkConvexShape_GetViewerStrings(NameArr* arr);
    void bhkCylinderShape_GetViewerStrings(NameArr* arr);
};
static void AddName(NameArr* arr, const unsigned int& v) {
    unsigned int n = arr->m_usSize;
    if (n >= arr->m_usMaxSize) {
        arr->FUN_0096ad30(n + arr->m_usGrowBy);
    }
    arr->FUN_0096ae90(n, v);
}
extern "C" void _mm_store_ss(float*, LocalM128);
struct AlignedPairData {
    hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant m_vContactPosition;
    hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int m_type;
    int unk28;
    int unk2C;
    hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant unk30;
    hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant unk40;
    hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant unk50;
    hkVec4Q_blk_00cc0000_od_o2_nood_variant_rtm_variant unk60;
};
template <int ELEMENTSIZE>
__forceinline void memCpyOneAligned(void* dst, const void* src)
{
    int i = 0;
    do {
        static_cast<unsigned __int64*>(dst)[i] = static_cast<const unsigned __int64*>(src)[i];
    } while (++i < int(ELEMENTSIZE / 8));
}
struct ContactArray {
    AlignedPairData* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline AlignedPairData& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpyOneAligned<sizeof(AlignedPairData)>(m_data + index, m_data + m_iElementCount);
    }
};
struct ContactManifold {
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
extern "C" LocalM128 _mm_setzero_ps();
extern float DAT_011b153c;
union hkVecQ3E
{
    LocalM128 m_vComponents;
    char m_bytes[16];
    __forceinline hkVecQ3E() {}
    __forceinline hkVecQ3E(float x, float y, float z, float w) { m_vComponents = _mm_setr_ps(x, y, z, w); }
};
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


__forceinline hkpShape::hkpShape(hkpShapeType iType) { m_ulUserData = 0; *(unsigned int*)&m_type = iType; }
__forceinline hkpConvexShape::hkpConvexShape(int iType, float fRadius) : hkpShape((hkpShapeType)iType) { m_fSphereRadius = fRadius; }
struct ShapeObj_SI : hkpConvexShape
{
    unsigned short unk14;
    unsigned char unk16;
    unsigned char unk17;
    hkVecQ3E m_v20;
    hkVecQ3E m_v30;
    hkVecQ3E m_v40;
    hkVecQ3E m_v50;

    __forceinline ShapeObj_SI(const hkVecQ3E& a, const hkVecQ3E& b, const hkVecQ3E& c, float fRadius = DAT_011b153c)
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
struct ParamSrc {
 int unk00, unk04, unk08, unk0c;
 float m_10, m_14, m_18, m_1c;
 float m_20, m_24, m_28, m_2c;
 float m_30;
};
class CylinderInitOwner {
public:
 virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
 virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
 virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
 virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
 virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
 virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
 virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
 virtual void v44(); virtual void v45(); virtual void v46();
 virtual void v47(ParamSrc*);
 void __thiscall CreateAndDispatchObject(const LocalM128& lo, const LocalM128& hi, float f);
 void __thiscall bhkCylinderShape_Init(ParamSrc*);
};
void* __cdecl FUN_00ec44d0(void*, const void*, unsigned);
void* __cdecl Object_DispatchCommandFour(unsigned);
void __cdecl FreeStorage(void*);
using ::MemoryManager;
using ::_g_memoryManager;
struct ExtendedMeshFloat {
    float value;
    static void* operator new[](unsigned size) { return _g_memoryManager.Allocate(size); }
};
struct ExtendedMeshIndex {
    unsigned short value;
    static void* operator new[](unsigned size) { return _g_memoryManager.Allocate(size); }
};
struct Triangle { unsigned short a,b,c,unk06; };
struct Region { unsigned value; unsigned count; unsigned other; };
struct Geometry {

    unsigned unk00,unk04;

    unsigned short triangleCount,unk0A,unk0C,unk0E,regionCount,unk12;

    Triangle* triangles;

    NiPoint3* vertices;

    unsigned unk1C,unk20;

    Region* regions;

    __forceinline bool GetTriangle(unsigned short index,Triangle*& out) {

        out=&triangles[index];

        return index>=triangleCount;

    }

};
struct ExtendedMeshInput {

    unsigned unk00;

    Geometry* geometry;

    float scale;

    unsigned unk0C;

    LocalM128 transform;

};
struct MeshPart {
    static void* operator new[](unsigned size) { return _g_memoryManager.Allocate(size); }

    unsigned vertexCount;

    NiPoint3* vertices;

    unsigned triangleCount;

    unsigned short* indices;

    struct hkAabb* bounds;

    MeshPart();

    ~MeshPart();

};
struct FUN_00a5d3a0 {

    FUN_00a5d3a0();

    virtual ~FUN_00a5d3a0();

    unsigned references;

};
struct Mesh : FUN_00a5d3a0 {

    unsigned count;

    MeshPart* parts;

    static void* operator new(unsigned n) { return Object_DispatchCommandFour(n); }

    Mesh() : count(0), parts(0) {}

    virtual ~Mesh();

};
extern void* indexVtable[];
struct IndexArray {

    void** vtable;

    ~IndexArray() { FreeStorage(data); }

    unsigned short* data;

    unsigned short capacity,size,used,grow;

    IndexArray() { capacity=0; grow=1; size=0; used=0; data=0; vtable=indexVtable; }

    void Resize(unsigned);

    __forceinline void Append(unsigned short value) { SetAt(size,value); }

    __forceinline void SetAt(unsigned index,unsigned short value) {

        if(index>=capacity) Resize(index+grow);

        if(index>=size) {

            size=index+1;

            if(value) ++used;

        } else if(value) {

            if(!data[index]) ++used;

        } else {

            if(data[index]) --used;

        }

        data[index]=value;

    }

    void Clear() {

        unsigned short* values=data;

        unsigned short count=size;

        for(unsigned short index=0;index<count;++index) values[index]=0;

        size=0; used=0;

    }

};
struct __declspec(align(16)) ExtendedMeshStoredVector {
    hkVec4 lanes;
    __forceinline ExtendedMeshStoredVector& operator=(LocalM128 v) { _mm_store_ps(reinterpret_cast<float*>(&lanes.m_bytes[0]),v);return *this; }
    __forceinline operator const LocalM128&() const { return *reinterpret_cast<const LocalM128*>(&lanes.m_bytes[0]); }
};
struct Result {

    Mesh* mesh;

    unsigned unk04;

    float scale;

    unsigned unk0C;

    ExtendedMeshStoredVector transform;

    Result(Mesh*);

    ~Result();

};
struct ExtendedMeshBuilder {

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
__declspec(noinline) void IndexArray::Resize(unsigned requested) {

    if(requested==capacity) return;

    if(requested<size) {

        for(unsigned short i=(unsigned short)requested;i<size;++i) {

            if(data[i]) {data[i]=0;--used;}

        }

        size=(unsigned short)requested;

    }

    unsigned short* old=data;

    capacity=(unsigned short)requested;

    if(requested>0) {

        data=(unsigned short*)NiMalloc((unsigned short)requested*2);

        for(unsigned short i=0;i<size;++i) data[i]=old[i];

        for(unsigned short i=size;i<capacity;++i) data[i]=0;

    } else data=0;

    FreeStorage(old);

}
struct FUN_00ccea00Block
{
    LocalM128 m_v0;
    LocalM128 m_v1;
    LocalM128 m_v2;
    LocalM128 m_v3;
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

struct ThreadBlock {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int allocationType;
};
extern "C" { extern __declspec(thread) ThreadBlock s_tlsData; }
struct AllocationTypeScope {
    unsigned int previous;
    AllocationTypeScope(unsigned int type) : previous(s_tlsData.allocationType) {s_tlsData.allocationType=type;}
    ~AllocationTypeScope() {s_tlsData.allocationType=previous;}
};
struct RouterHeap {
    virtual void Unk00();
    virtual void* Allocate(int bytes);
    virtual void Release(void* memory,int bytes);
};
extern "C" LocalM128 _mm_load_ss(float const*);
struct SimdReal { hkVec4 m; SimdReal(float f){ m.m_vComponents=_mm_load_ss(&f);} };
union __declspec(align(16)) MotionVector {LocalM128 quad;hkVec4 storage;
    void Mul(const SimdReal& r){ quad=_mm_mul_ps(_mm_shuffle_ps(r.m.m_vComponents,r.m.m_vComponents,0),quad);}
    void Mul(float f){ LocalM128 s=_mm_load_ss(&f); quad=_mm_mul_ps(_mm_shuffle_ps(s,s,0),quad);}
};
class FUN_00d4edc0 {
public:
    void* vtable;
    unsigned short allocatedBytes;
    short references;
    int unk08,unk0c;
    MotionVector state10,state20,state30,state40,state50,state60,state70,state80,state90;
    float unkA0,valueA4,valueA8,unkAC,valueB0,valueB4,unkB8,unkBC;
    MotionVector stateC0,stateD0,stateE0,stateF0,state100,state110,state120,state130,state140,state150;
    FUN_00d4edc0();
    static void* operator new(size_t bytes) {
        void* memory=hkMemoryRouter::getInstance().heap().blockAlloc((int)bytes);
        ((FUN_00d4edc0*)memory)->allocatedBytes=(unsigned short)bytes;
        return memory;
    }
    static void operator delete(void* memory) {
        FUN_00d4edc0* motion=(FUN_00d4edc0*)memory;
        RouterHeap* heap=(RouterHeap*)hkMemoryRouter::getInstance().m_heap;
        heap->Release(memory,motion->allocatedBytes);
    }
};
struct MotionScale {int unk00,unk04,unk08,unk0c;float factor;};
class MotionOwner {
public:
    int unk00;
    FUN_00d4edc0* motion;
    void ReleaseObject(FUN_00d4edc0* output,MotionScale* scale);
    void hkWheelConstraintCinfo_CloneData(FUN_00d4edc0* output,MotionScale* scale);
};
// @fnv 0x00cc51e0
// src: XBOX_PDB 0x00cc51e0
void MotionOwner::hkWheelConstraintCinfo_CloneData(FUN_00d4edc0* output,MotionScale* scale) {
    AllocationTypeScope allocation(0x10);
    FUN_00d4edc0* source=motion;
    if(!output)output=new FUN_00d4edc0;
    output->state50.quad=source->state50.quad;
    output->state90.quad=source->state90.quad;
    output->valueA4=source->valueA4;
    output->valueA8=source->valueA8;
    output->valueB0=source->valueB0;
    output->valueB4=source->valueB4;
    float factor=scale->factor;
    if(factor!=1.0f) {
        output->state50.Mul(SimdReal(factor));
        output->state90.Mul(SimdReal(factor));
    }
    ReleaseObject(output,scale);
}

extern "C" LocalM128 _mm_load_ss(const float*);
struct BlockAllocator {
    virtual void unknown00();
    virtual void* allocate(int);
    virtual void release(void*, int);
};
struct Motor513 {
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual Motor513* clone();
    void FUN_00c905b0();
};
// Constraint frames use the four SIMD columns of hkTransform, with hkVector4 translation.
inline void hkTransform::operator=(const hkTransform& transform)
{
    m_kColumn0 = transform.m_kColumn0;
    m_kColumn1 = transform.m_kColumn1;
    m_kColumn2 = transform.m_kColumn2;
    m_vTranslation = transform.m_vTranslation;
}
inline void hkVector4::mul4(const float& scale)
{
    hkVec4 scalar;
    scalar.m_vComponents = _mm_load_ss(&scale);
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(scalar.m_vComponents, scalar.m_vComponents, 0), m_vComponents);
}
struct ConstraintReference513 {
    virtual void unknown00();
    unsigned short memorySize, referenceCount;
    unsigned int userData,unk0c;
};
struct FUN_00d4fe80 : ConstraintReference513 {
    unsigned int atom10,unk14,unk18,unk1c;
    hkTransform transformA,transformB;
    unsigned char a0,a1,motorEnabled,a3;
    unsigned int unkA4;
    float a8;
    Motor513* motor;
    unsigned int unkB0;
    float b4;
    unsigned int unkB8,unkBc,unkC0;
    unsigned short unkC4;
    unsigned char unkC6,unkC7;
    float minimum,maximum;
    FUN_00d4fe80();
    static void* allocate(hkMemoryAllocator& heap,unsigned int size) {
        FUN_00d4fe80* result=(FUN_00d4fe80*)heap.blockAlloc(size);
        result->memorySize=(unsigned short)size;
        return result;
    }
    static void* operator new(unsigned int size) {
        return allocate(hkMemoryRouter::getInstance().heap(),size);
    }
    static void operator delete(void* p) { ((BlockAllocator*)hkMemoryRouter::getInstance().m_heap)->release(p,((FUN_00d4fe80*)p)->memorySize); }
    void SetReferencedObject(Motor513*);
};
struct CloneData513 { unsigned int unk00,unk04,unk08,unk0c; float scale; };
struct CloneOwner513 {
    unsigned int unk00;
    FUN_00d4fe80* source;
    void ReleaseObject(FUN_00d4fe80*, CloneData513*);
    void hkPrismaticConstraintCinfo_CloneData(FUN_00d4fe80*, CloneData513*);
};
// @fnv 0x00cc7600
// src: XBOX_PDB 0x00cc7600
void CloneOwner513::hkPrismaticConstraintCinfo_CloneData(FUN_00d4fe80* output, CloneData513* data) {
    MemContextGuard memoryClass(16);
    FUN_00d4fe80* input=source;
    if (!output) output=new FUN_00d4fe80;
    output->transformA=input->transformA;
    output->transformB=input->transformB;
    output->maximum=input->maximum;
    output->minimum=input->minimum;
    output->b4=input->b4;
    float scale=data->scale;
    if(scale!=1.0f) {
        output->transformA.position.mul4(scale);
        output->transformB.position.mul4(scale);
        float& minimum=output->minimum;
        minimum=minimum*scale;
        output->maximum=scale*output->maximum;
    }
    Motor513* motor=input->motor;
    if(motor) {
        Motor513* copy=motor->clone();
        output->SetReferencedObject(copy);
        copy->FUN_00c905b0();
        output->motorEnabled=input->motorEnabled;
    }
    ReleaseObject(output,data);
}

extern "C" LocalM128 _mm_load_ss(float const*_A);


struct S00cc96b0_ScaleObject {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    LocalM128 vector20;
    LocalM128 vector30;
};

__forceinline void scale(LocalM128& v, float f)
{
    LocalM128 q = _mm_load_ss(&f);
    v = _mm_mul_ps(_mm_shuffle_ps(q, q, 0), v);
}

// @fnv 0x00cc96b0
// src: COMMUNITY 0x00cc96b0
void __cdecl hkBallAndSocketConstraintCinfo_ApplyScale(float value, S00cc96b0_ScaleObject* object)
{
    if (object && value != 1.0f) {
        scale(object->vector20, value);
        scale(object->vector30, value);
    }
}

extern "C" LocalM128 _mm_load_ss(const float*);


struct RefObjStandIn
{
    virtual ~RefObjStandIn();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

struct QuadHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    LocalM128 m_vComponents;
};

struct ScaleArg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float unk10;
};

struct TargetArg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    NiPointer<RefObjStandIn> unk14;
};

class ScaledNode
{
public:
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c();
    virtual void v20(), v24(), v28(), v2c(), v30(), v34(), v38(), v3c();
    virtual void v40(), v44(), v48(), v4c(), v50(), v54(), v58(), v5c();
    virtual void v60(), v64(), v68(), v6c(), v70(), v74(), v78(), v7c();
    virtual void v80(), v84(), v88(), v8c(), v90(), v94(), v98(), v9c();
    virtual void va0(), va4(), va8(), vac(), vb0();
    virtual QuadHolder* vb4(bool* pbFlag);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    NiPointer<RefObjStandIn> unk14;

    void bhkShape_CopyMembers(TargetArg* pkTarget, ScaleArg* pkArg);
    void bhkExtendedMeshShape_CopyMembers(TargetArg* pkTarget, ScaleArg* pkArg);
};

// @fnv 0x00ccbf00
// src: XBOX_PDB 0x00ccbf00
void ScaledNode::bhkExtendedMeshShape_CopyMembers(TargetArg* pkTarget, ScaleArg* pkArg)
{
    TargetArg* pkDst = *(TargetArg* volatile*)&pkTarget;
    ScaleArg* volatile pkScale = pkArg;
    bool bFlag;
    QuadHolder* pkQuad = vb4(&bFlag);
    float fScale = pkArg->unk10;
    LocalM128 x = _mm_load_ss(&fScale);
    pkQuad->m_vComponents = _mm_mul_ps(_mm_shuffle_ps(x, x, 0), pkQuad->m_vComponents);
    pkDst->unk14 = unk14;
    bhkShape_CopyMembers(pkDst, pkScale);
}

extern "C" {
LocalM128 _mm_sub_ss(LocalM128,LocalM128);
LocalM128 _mm_load_ss(const float*);
void _mm_store_ss(float*,LocalM128);
void _ReadBarrier();
void _ReadWriteBarrier();
}
struct Motion;
struct FUN_00c6cba0_class { void bhkCharacterController_UpdateState(); };
struct MotionVtable {
void* slot00;
void* slot04;
void* slot08;
void* slot0c;
void* slot10;
void* slot14;
void* slot18;
void* slot1c;
void* slot20;
void* slot24;
void* slot28;
void* slot2c;
void* slot30;
void* slot34;
void* slot38;
void* slot3c;
void* slot40;
void* slot44;
void* slot48;
void* slot4c;
void* slot50;
void* slot54;
void* slot58;
void* slot5c;
void* slot60;
void* slot64;
void* slot68;
void* slot6c;
void* slot70;
void* slot74;
void* slot78;
void* slot7c;
void* slot80;
void* slot84;
void* slot88;
void* slot8c;
void* slot90;
BodyTransform* (__thiscall *getTransform)(Motion*);
};
struct Motion {
MotionVtable* vtable;
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
LocalM128 vec4a0;
LocalM128 vec4b0;
LocalM128 vec4c0;
LocalM128 vec4d0;
float value4e0; float value4e4; float value4e8; float value4ec;
LocalM128 vec4f0;
LocalM128 vec500;
LocalM128 vec510;
int state;
float value524;
float value528;
float value52c;
float value530;
float value534;
float value538;
float value53c;
float value540;
float value544;
float value548;
float value54c;
void SubtractVectors(LocalM128*);
void bhkCharacterController_UpdateState();
};

struct __declspec(align(16)) StoredVector {
    unsigned char lanes[16];
    __forceinline StoredVector& operator=(LocalM128 v) { _mm_store_ps(reinterpret_cast<float*>(&lanes[0]),v);return *this; }
    __forceinline operator const LocalM128&() const { return *reinterpret_cast<const LocalM128*>(&lanes[0]); }
};
struct Step { float time; LocalM128 surfaceVelocity; LocalM128 up; LocalM128 normal; LocalM128 oldVelocity; LocalM128 gravity; float limit; LocalM128 basis; };
extern "C" void __cdecl hkpCharacterMovementUtil_calculateMovement(Step*, LocalM128*);

extern LocalM128 DAT_010c7160;
extern float DAT_01011d78;
__forceinline void transferScalar(float& destination, float source) {
    *static_cast<volatile float*>(&destination)=source;
}
// @fnv 0x00cd3cb0
// src: COMMUNITY 0x00cd3cb0
void __stdcall bhkCharacterStateProjectile_Update(Motion* object) {
    float b,z;
    Step scale;
    StoredVector amount;
    _mm_store_ss(&b,object->vec4f0);
    scale.surfaceVelocity = object->vec4d0;
    StoredVector cv;
    scale.up = object->vec4c0;
    scale.normal = object->vec4c0;
    if (b < -100000000.0f) {
        (*(0 + object->vec4f0.m128_f32)) = 0.0f;
        scale.oldVelocity = object->vec4f0;
        scale.time = 1.0f;
        _mm_store_ss(&b,_mm_shuffle_ps(object->vec510,object->vec510,0xaa));
        transferScalar(z,b);
        _mm_store_ss(&b,object->vec510);
        transferScalar(b,b);
        _mm_store_ss(((0)[&scale.gravity.m128_f32]),_mm_shuffle_ps(object->vec510,object->vec510,0x55));
        scale.gravity = _mm_setr_ps(scale.gravity.m128_f32[0],b,z,0.0f);
        scale.limit = 100000.0f;
        scale.basis = object->vec4a0;
        hkpCharacterMovementUtil_calculateMovement(&scale,&object->vec4f0);
    } else {
        *static_cast<volatile float*>(&scale.time)=object->value534;
        scale.oldVelocity = object->vec4f0;
        _mm_store_ss(&z,_mm_shuffle_ps(object->vec510,object->vec510,0xaa));
        transferScalar(b,z);
        _mm_store_ss(&z,object->vec510);
        transferScalar(z,z);
        _mm_store_ss(((&scale.gravity.m128_f32)[0]),_mm_shuffle_ps(object->vec510,object->vec510,0x55));
        scale.gravity = _mm_setr_ps((((scale.gravity.m128_f32)[(0)])),z,b,0.0f);
        scale.limit = 100000.0f;
        scale.basis = object->vec4a0;
        hkpCharacterMovementUtil_calculateMovement(&scale,&object->vec4f0);
        b = object->value54c;
        if (b > 0.0f) {
            LocalM128 normal=object->vec4c0;
            LocalM128 n=_mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&normal)),object->vec4f0);
            LocalM128 v=_mm_add_ss(_mm_shuffle_ps(n,n,0x55),n);
            LocalM128 product;
            LocalM128 idx=_mm_add_ss(_mm_shuffle_ps(n,n,0xaa),v);
            _ReadBarrier();
            product = _mm_sub_ss(DAT_010c7160,idx);
                    object->vec4f0=_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(product,product,0),normal),object->vec4f0);
            _ReadWriteBarrier();
            normal=object->vec4c0;
            n=_mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&normal)),scale.oldVelocity);
            v=_mm_add_ss(_mm_shuffle_ps(n,n,0x55),n);
            idx=_mm_add_ss(_mm_shuffle_ps(n,n,0xaa),v);
            object->vec4f0=_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(idx,idx,0),normal),object->vec4f0);
        }
        LocalM128 y;
        object->SubtractVectors(reinterpret_cast<LocalM128*>(&amount));
        y = amount;
        _mm_store_ss(&z,_mm_shuffle_ps(y,y,0xaa));
        if (z > object->value53c) {
            object->vtable->getTransform(object);
            cv = object->vtable->getTransform(object)->b;
            object->vtable->getTransform(object);
            LocalM128 pForm=_mm_load_ss(&b);
            transferScalar(z,object->value4e8);
            LocalM128 q=_mm_load_ss(&z);
            object->vec4f0 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(pForm,pForm,0),cv),_mm_shuffle_ps(q,q,0)),object->vec4f0);
        }
    }
    if (11 != object->state) reinterpret_cast<FUN_00c6cba0_class*>(object)->bhkCharacterController_UpdateState();
}

extern "C" void _ReadBarrier(void);
#pragma intrinsic(_ReadBarrier)
extern "C" float _mm_cvtss_f32(LocalM128 _A);
extern "C" LocalM128 _mm_load_ss(float const*_A);
extern "C" void _mm_store_ss(float *_V, LocalM128 _A);
extern "C" LocalM128 _mm_sub_ss(LocalM128 _A, LocalM128 _B);

extern float DAT_011b0140;
extern float DAT_01267bbc;
extern float DAT_01011d78;
extern LocalM128 DAT_010c7160;

struct S00cd3fb0_RealValue { float value; };


__forceinline void hkVector4::set(float x,float y,float z,float w) { m_vComponents = _mm_setr_ps(x,y,z,w); }
__forceinline void hkVector4::addMul4(LocalM128 s,const hkVector4& b) { m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s,s,0),b.m_vComponents),m_vComponents); }
struct S00cd3fb0_MotionTransform {
    hkVector4 m_pHeadNode;
    hkVector4 m_direction;
};

struct S00cd3fb0_MotionParams {
    float m_factor;
    char unk04[12];
    hkVector4 m_v10;
    hkVector4 m_vHitNormal;
    hkVector4 m_normal2;
    hkVector4 m_fVelocity;
    hkVector4 m_v50;
    float m_vScale;
    float unk64;
    float unk68;
    float unk6c;
    hkVector4 m_v70;
};

extern void __cdecl IntegrateMotion(S00cd3fb0_MotionParams* params, hkVector4* velocity);

class S00cd3fb0_MotionObject;
struct S00cd3fb0_MotionVtable {
    void* slot00;
    void* slot04;
    void* slot08;
    void* slot0c;
    void* slot10;
    void* slot14;
    void* slot18;
    void* slot1c;
    void* slot20;
    void* slot24;
    void* slot28;
    void* slot2c;
    void* slot30;
    void* slot34;
    void* slot38;
    void* slot3c;
    void* slot40;
    void* slot44;
    void* slot48;
    void* slot4c;
    void* slot50;
    void* slot54;
    void* slot58;
    void* slot5c;
    void* slot60;
    void* slot64;
    void* slot68;
    void* slot6c;
    void* slot70;
    void* slot74;
    void* slot78;
    void* slot7c;
    void* slot80;
    void* slot84;
    void* slot88;
    void* slot8c;
    void* slot90;
    S00cd3fb0_MotionTransform* (__thiscall *GetResult)(S00cd3fb0_MotionObject*);
};
struct S00cd3fb0_FUN_00c70550_class { float bhkCharacterController_GetFallDistance(); };
struct S00cd3fb0_FUN_00c6cba0_class { void bhkCharacterController_UpdateState(); };
struct S00cd3fb0_FUN_00c6e2e0_cls { void bhkCharacterController_UpdateFalling(); };
struct S00cd3fb0_FUN_00c6e300_class { void SubtractVectors(LocalM128*); };
extern void __cdecl hkpCharacterMovementUtil_calculateMovement(S00cd3fb0_MotionParams*, hkVector4*);

class S00cd3fb0_MotionObject {
public:
    S00cd3fb0_MotionVtable* vtable;
    unsigned int unknown004;
    unsigned int unknown008;
    unsigned int unknown00c;
    unsigned int unknown010;
    unsigned int unknown014;
    unsigned int unknown018;
    unsigned int unknown01c;
    unsigned int unknown020;
    unsigned int unknown024;
    unsigned int unknown028;
    unsigned int unknown02c;
    unsigned int unknown030;
    unsigned int unknown034;
    unsigned int unknown038;
    unsigned int unknown03c;
    unsigned int unknown040;
    unsigned int unknown044;
    unsigned int unknown048;
    unsigned int unknown04c;
    unsigned int unknown050;
    unsigned int unknown054;
    unsigned int unknown058;
    unsigned int unknown05c;
    unsigned int unknown060;
    unsigned int unknown064;
    unsigned int unknown068;
    unsigned int unknown06c;
    unsigned int unknown070;
    unsigned int unknown074;
    unsigned int unknown078;
    unsigned int unknown07c;
    unsigned int unknown080;
    unsigned int unknown084;
    unsigned int unknown088;
    unsigned int unknown08c;
    unsigned int unknown090;
    unsigned int unknown094;
    unsigned int unknown098;
    unsigned int unknown09c;
    unsigned int unknown0a0;
    unsigned int unknown0a4;
    unsigned int unknown0a8;
    unsigned int unknown0ac;
    unsigned int unknown0b0;
    unsigned int unknown0b4;
    unsigned int unknown0b8;
    unsigned int unknown0bc;
    unsigned int unknown0c0;
    unsigned int unknown0c4;
    unsigned int unknown0c8;
    unsigned int unknown0cc;
    unsigned int unknown0d0;
    unsigned int unknown0d4;
    unsigned int unknown0d8;
    unsigned int unknown0dc;
    unsigned int unknown0e0;
    unsigned int unknown0e4;
    unsigned int unknown0e8;
    unsigned int unknown0ec;
    unsigned int unknown0f0;
    unsigned int unknown0f4;
    unsigned int unknown0f8;
    unsigned int unknown0fc;
    unsigned int unknown100;
    unsigned int unknown104;
    unsigned int unknown108;
    unsigned int unknown10c;
    unsigned int unknown110;
    unsigned int unknown114;
    unsigned int unknown118;
    unsigned int unknown11c;
    unsigned int unknown120;
    unsigned int unknown124;
    unsigned int unknown128;
    unsigned int unknown12c;
    unsigned int unknown130;
    unsigned int unknown134;
    unsigned int unknown138;
    unsigned int unknown13c;
    unsigned int unknown140;
    unsigned int unknown144;
    unsigned int unknown148;
    unsigned int unknown14c;
    unsigned int unknown150;
    unsigned int unknown154;
    unsigned int unknown158;
    unsigned int unknown15c;
    unsigned int unknown160;
    unsigned int unknown164;
    unsigned int unknown168;
    unsigned int unknown16c;
    unsigned int unknown170;
    unsigned int unknown174;
    unsigned int unknown178;
    unsigned int unknown17c;
    unsigned int unknown180;
    unsigned int unknown184;
    unsigned int unknown188;
    unsigned int unknown18c;
    unsigned int unknown190;
    unsigned int unknown194;
    unsigned int unknown198;
    unsigned int unknown19c;
    unsigned int unknown1a0;
    unsigned int unknown1a4;
    unsigned int unknown1a8;
    unsigned int unknown1ac;
    unsigned int unknown1b0;
    unsigned int unknown1b4;
    unsigned int unknown1b8;
    unsigned int unknown1bc;
    unsigned int unknown1c0;
    unsigned int unknown1c4;
    unsigned int unknown1c8;
    unsigned int unknown1cc;
    unsigned int unknown1d0;
    unsigned int unknown1d4;
    unsigned int unknown1d8;
    unsigned int unknown1dc;
    unsigned int unknown1e0;
    unsigned int unknown1e4;
    unsigned int unknown1e8;
    unsigned int unknown1ec;
    unsigned int unknown1f0;
    unsigned int unknown1f4;
    unsigned int unknown1f8;
    unsigned int unknown1fc;
    unsigned int unknown200;
    unsigned int unknown204;
    unsigned int unknown208;
    unsigned int unknown20c;
    unsigned int unknown210;
    unsigned int unknown214;
    unsigned int unknown218;
    unsigned int unknown21c;
    unsigned int unknown220;
    unsigned int unknown224;
    unsigned int unknown228;
    unsigned int unknown22c;
    unsigned int unknown230;
    unsigned int unknown234;
    unsigned int unknown238;
    unsigned int unknown23c;
    unsigned int unknown240;
    unsigned int unknown244;
    unsigned int unknown248;
    unsigned int unknown24c;
    unsigned int unknown250;
    unsigned int unknown254;
    unsigned int unknown258;
    unsigned int unknown25c;
    unsigned int unknown260;
    unsigned int unknown264;
    unsigned int unknown268;
    unsigned int unknown26c;
    unsigned int unknown270;
    unsigned int unknown274;
    unsigned int unknown278;
    unsigned int unknown27c;
    unsigned int unknown280;
    unsigned int unknown284;
    unsigned int unknown288;
    unsigned int unknown28c;
    unsigned int unknown290;
    unsigned int unknown294;
    unsigned int unknown298;
    unsigned int unknown29c;
    unsigned int unknown2a0;
    unsigned int unknown2a4;
    unsigned int unknown2a8;
    unsigned int unknown2ac;
    unsigned int unknown2b0;
    unsigned int unknown2b4;
    unsigned int unknown2b8;
    unsigned int unknown2bc;
    unsigned int unknown2c0;
    unsigned int unknown2c4;
    unsigned int unknown2c8;
    unsigned int unknown2cc;
    unsigned int unknown2d0;
    unsigned int unknown2d4;
    unsigned int unknown2d8;
    unsigned int unknown2dc;
    unsigned int unknown2e0;
    unsigned int unknown2e4;
    unsigned int unknown2e8;
    unsigned int unknown2ec;
    unsigned int unknown2f0;
    unsigned int unknown2f4;
    unsigned int unknown2f8;
    unsigned int unknown2fc;
    unsigned int unknown300;
    unsigned int unknown304;
    unsigned int unknown308;
    unsigned int unknown30c;
    unsigned int unknown310;
    unsigned int unknown314;
    unsigned int unknown318;
    unsigned int unknown31c;
    unsigned int unknown320;
    unsigned int unknown324;
    unsigned int unknown328;
    unsigned int unknown32c;
    unsigned int unknown330;
    unsigned int unknown334;
    unsigned int unknown338;
    unsigned int unknown33c;
    unsigned int unknown340;
    unsigned int unknown344;
    unsigned int unknown348;
    unsigned int unknown34c;
    unsigned int unknown350;
    unsigned int unknown354;
    unsigned int unknown358;
    unsigned int unknown35c;
    unsigned int unknown360;
    unsigned int unknown364;
    unsigned int unknown368;
    unsigned int unknown36c;
    unsigned int unknown370;
    unsigned int unknown374;
    unsigned int unknown378;
    unsigned int unknown37c;
    unsigned int unknown380;
    unsigned int unknown384;
    unsigned int unknown388;
    unsigned int unknown38c;
    unsigned int unknown390;
    unsigned int unknown394;
    unsigned int unknown398;
    unsigned int unknown39c;
    unsigned int unknown3a0;
    unsigned int unknown3a4;
    unsigned int unknown3a8;
    unsigned int unknown3ac;
    unsigned int unknown3b0;
    unsigned int unknown3b4;
    unsigned int unknown3b8;
    unsigned int unknown3bc;
    unsigned int unknown3c0;
    unsigned int unknown3c4;
    unsigned int unknown3c8;
    unsigned int unknown3cc;
    unsigned int unknown3d0;
    unsigned int unknown3d4;
    unsigned int unknown3d8;
    unsigned int unknown3dc;
    unsigned int unknown3e0;
    unsigned int unknown3e4;
    unsigned int unknown3e8;
    unsigned int unknown3ec;
    unsigned int unknown3f0;
    unsigned int unknown3f4;
    unsigned int unknown3f8;
    unsigned int unknown3fc;
    unsigned int unknown400;
    unsigned int unknown404;
    unsigned int unknown408;
    unsigned int unknown40c;
    unsigned int unknown410;
    unsigned int m_flags;
    unsigned int unknown418;
    unsigned int unknown41c;
    unsigned int unknown420;
    unsigned int unknown424;
    unsigned int unknown428;
    unsigned int unknown42c;
    unsigned int unknown430;
    unsigned int unknown434;
    unsigned int unknown438;
    unsigned int unknown43c;
    unsigned int unknown440;
    unsigned int unknown444;
    unsigned int unknown448;
    unsigned int unknown44c;
    unsigned int unknown450;
    unsigned int unknown454;
    unsigned int unknown458;
    unsigned int unknown45c;
    unsigned int unknown460;
    unsigned int unknown464;
    unsigned int unknown468;
    unsigned int unknown46c;
    unsigned int unknown470;
    unsigned int unknown474;
    unsigned int unknown478;
    unsigned int unknown47c;
    unsigned int unknown480;
    unsigned int unknown484;
    unsigned int unknown488;
    unsigned int unknown48c;
    unsigned int unknown490;
    unsigned int unknown494;
    unsigned int unknown498;
    unsigned int unknown49c;
    hkVector4 m_v4a0;
    unsigned int unknown4b0;
    unsigned int unknown4b4;
    unsigned int unknown4b8;
    unsigned int unknown4bc;
    hkVector4 m_vHitNormal;
    hkVector4 m_v4d0;
    unsigned int unknown4e0;
    unsigned int unknown4e4;
    float m_scale4e8;
    unsigned int unknown4ec;
    hkVector4 m_fVelocity;
    unsigned int unknown500;
    unsigned int unknown504;
    unsigned int unknown508;
    unsigned int unknown50c;
    hkVector4 m_v510;
    int m_uiContentCount;
    unsigned int unknown524;
    unsigned int unknown528;
    unsigned int unknown52c;
    unsigned int unknown530;
    float m_uiCommandId;
    unsigned int unknown538;
    unsigned int unknown53c;
    unsigned int unknown540;
    unsigned int unknown544;
    float m_factor;
    float m_scale54c;
    unsigned int unknown550;
    unsigned int unknown554;
    unsigned int unknown558;
    unsigned int unknown55c;
    unsigned int unknown560;
    unsigned int unknown564;
    unsigned int unknown568;
    unsigned int unknown56c;
    unsigned int unknown570;
    unsigned int unknown574;
    unsigned int unknown578;
    unsigned int unknown57c;
    unsigned int unknown580;
    unsigned int unknown584;
    unsigned int unknown588;
    unsigned int unknown58c;
    unsigned int unknown590;
    unsigned int unknown594;
    unsigned int unknown598;
    unsigned int unknown59c;
    unsigned int unknown5a0;
    unsigned int unknown5a4;
    unsigned int unknown5a8;
    unsigned int unknown5ac;
    unsigned int unknown5b0;
    unsigned int unknown5b4;
    unsigned int unknown5b8;
    unsigned int unknown5bc;
    unsigned int unknown5c0;
    unsigned int unknown5c4;
    unsigned int unknown5c8;
    unsigned int unknown5cc;
    unsigned int unknown5d0;
    unsigned int unknown5d4;
    unsigned int unknown5d8;
    unsigned int unknown5dc;
    unsigned int unknown5e0;
    unsigned int unknown5e4;
    unsigned int unknown5e8;
    unsigned int unknown5ec;
    unsigned int unknown5f0;
    unsigned int unknown5f4;
    unsigned int unknown5f8;
    unsigned int unknown5fc;
    unsigned int unknown600;
    unsigned int unknown604;
    unsigned int unknown608;
    unsigned int unknown60c;
    unsigned char m_bSlotEnabled;
    unsigned char unknown611;
    unsigned short unknown612;
    unsigned int unknown614;
    unsigned int unknown618;
    unsigned int unknown61c;
    hkVector4 m_v620;

    __forceinline S00cd3fb0_RealValue scale54c() const { S00cd3fb0_RealValue r = { m_scale54c }; return r; }
    __forceinline float scale4e8() const { return m_scale4e8; }
    __forceinline float getX510() const { LocalM128 value = m_v510.m_vComponents; _ReadBarrier(); return _mm_cvtss_f32(value); }
    float GetAnimationSpeed();
    void Reset();
    void Finish();
    void GetAudioPosition(hkVector4* out);
};

struct S00cd3fb0_MotionContext {
    unsigned int unk00;
    unsigned int unk04;
    float m_vScale;
    void bhkCharacterStateInAir_Update(S00cd3fb0_MotionObject* object);
};

struct S00cd3fb0_MotionScalarLane { LocalM128 value; __forceinline S00cd3fb0_MotionScalarLane(float v) { value = _mm_load_ss(&v); } __forceinline S00cd3fb0_MotionScalarLane(S00cd3fb0_RealValue v) { value=_mm_load_ss(&v.value); } __forceinline LocalM128 broadcast() const { return _mm_shuffle_ps(value,value,0); } };
// @fnv 0x00cd3fb0
// src: XBOX_PDB 0x00cd3fb0
void S00cd3fb0_MotionContext::bhkCharacterStateInAir_Update(S00cd3fb0_MotionObject* object)
{
    if ((unsigned char)(object->m_flags >> 8) & 1) {
        object->m_uiContentCount = 0;
        const_cast<volatile unsigned int&>(object->m_flags) |= 0x80;
    }
    if (object->m_uiContentCount == 11 && object->m_factor > 1.0f && ((S00cd3fb0_FUN_00c70550_class*)object)->bhkCharacterController_GetFallDistance() < 0.10000000149011612) {
        object->m_uiContentCount = 0;
        object->m_bSlotEnabled = 1;
        LocalM128 v;
        ((S00cd3fb0_FUN_00c6e300_class*)object)->SubtractVectors(&v);
        object->m_v620.m_vComponents = v;
    }
    if (object->m_uiContentCount != 11) {
        if (object->m_uiContentCount != 1) {
            object->m_factor = 0.0f;
            ((S00cd3fb0_FUN_00c6cba0_class*)object)->bhkCharacterController_UpdateState();
            return;
        }
        object->m_uiContentCount = 11;
    }
    if (object->m_uiCommandId > 0.0f) {
        S00cd3fb0_MotionParams params;
        params.m_factor = (object->m_flags & 0x1800) ? 1.0f : object->m_uiCommandId * DAT_011b0140 + DAT_01267bbc;
        params.m_v10 = object->m_v4d0;
        params.m_vScale = m_vScale;
        params.m_vHitNormal = object->m_vHitNormal;
        params.m_normal2 = object->m_vHitNormal;
        params.m_v70 = object->m_v4a0;
        params.m_fVelocity = object->m_fVelocity;
        {
            float x = object->getX510();
            LocalM128 source = object->m_v510.m_vComponents;
            _ReadBarrier();
            _mm_store_ss(&params.m_v50.m_vComponents.m128_f32[0], _mm_shuffle_ps(source,source,0x55));
            params.m_v50.set(params.m_v50.m_vComponents.m128_f32[0],x,DAT_01011d78,DAT_01011d78);
        }
        hkVector4* vel = &object->m_fVelocity;
        hkpCharacterMovementUtil_calculateMovement(&params, vel);
        LocalM128 normal = object->m_vHitNormal.m_vComponents;
        LocalM128 product = _mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&normal)),object->m_fVelocity.m_vComponents);
        LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
        LocalM128 dot = _mm_add_ss(_mm_shuffle_ps(product,product,0xaa),sum);
        LocalM128 neg = _mm_sub_ss(DAT_010c7160,dot);
        vel->m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(neg,neg,0),normal),vel->m_vComponents);
        normal = object->m_vHitNormal.m_vComponents;
        product = _mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&normal)),params.m_fVelocity.m_vComponents);
        sum = _mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
        dot = _mm_add_ss(_mm_shuffle_ps(product,product,0xaa),sum);
        vel->m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(dot,dot,0),normal),vel->m_vComponents);
    }
    object->vtable->GetResult(object);
    LocalM128 dir = object->vtable->GetResult(object)->m_direction.m_vComponents;
    object->vtable->GetResult(object);
    S00cd3fb0_MotionScalarLane s1(object->scale54c());
    LocalM128 a = s1.broadcast();
    S00cd3fb0_MotionScalarLane s2(object->scale4e8());
    LocalM128 result = _mm_mul_ps(a,dir);
    result = _mm_mul_ps(result,s2.broadcast());
    object->m_fVelocity.m_vComponents = _mm_add_ps(result,object->m_fVelocity.m_vComponents);
    ((S00cd3fb0_FUN_00c6e2e0_cls*)object)->bhkCharacterController_UpdateFalling();
}

extern "C" {
void _ReadWriteBarrier();
LocalM128 _mm_mul_ps(LocalM128, LocalM128);
LocalM128 _mm_add_ps(LocalM128, LocalM128);
LocalM128 _mm_add_ss(LocalM128, LocalM128);
LocalM128 _mm_mul_ss(LocalM128, LocalM128);
LocalM128 _mm_sub_ss(LocalM128, LocalM128);
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
LocalM128 _mm_rsqrt_ss(LocalM128);
LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
LocalM128 _mm_set_ss(float);
LocalM128 _mm_set_ps1(float);
LocalM128 _mm_load_ps(const float*);
float _mm_cvtss_f32(LocalM128);
LocalM128 _mm_load_ss(const float*);
void _mm_store_ss(float*, LocalM128);
}
extern "C" double __cdecl fabs(double);
extern "C" double __cdecl sqrt(double);

struct MotionData {
    LocalM128 orientation;
    LocalM128 direction;
};
struct ProxyHolder { const char* hkpCharacterProxy_getLinearVelocity(); };
struct MotionController;
struct MotionListener {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void update(MotionController* controller);
};
struct ListenerTable { MotionListener* GetIndexedValue_00cbc510(unsigned int index); };
struct MotionVTable {
    void* slot00;
    void* slot01;
    void* slot02;
    void* slot03;
    void* slot04;
    void* slot05;
    void* slot06;
    void* slot07;
    void* slot08;
    void* slot09;
    void* slot10;
    void* slot11;
    void* slot12;
    void* slot13;
    void* slot14;
    void* slot15;
    void* slot16;
    void* slot17;
    void* slot18;
    void* slot19;
    void* slot20;
    void* slot21;
    void* slot22;
    void* slot23;
    void* slot24;
    void* slot25;
    void* slot26;
    void* slot27;
    void* slot28;
    void* slot29;
    void* slot30;
    void* slot31;
    void* slot32;
    void* slot33;
    void* slot34;
    void* slot35;
    void* slot36;
    MotionData* (__thiscall *getMotionData)(MotionController*);
};
struct MotionController {
    MotionVTable* vtable;
    unsigned int unk004;
    ProxyHolder* proxy;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    ListenerTable* listeners;
    unsigned int listenerIndex;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int flags;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    LocalM128 velocity;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    int state;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    float acceleration;
    float heading;
    unsigned int unk548;
    float directionScale;
    void bhkCharacterController_UpdateState();
    const void* bhkCharacterProxy_MarkRead();
    void SubtractVectors(LocalM128* result);
};
extern float DAT_01267e30;
extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;
void __cdecl FUN_00458620(LocalM128* result, const LocalM128* vector);

union __declspec(align(16)) GsVec4 { LocalM128 v; float f[4]; char c[16]; };


static __forceinline LocalM128 splatFloat(const float* f) {
    LocalM128 v = _mm_load_ss(f);
    return _mm_shuffle_ps(v, v, 0);
}

__forceinline LocalM128 invLength(LocalM128 value)
{
    LocalM128 squared = _mm_mul_ps(value, value);
    LocalM128 partial = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared);
    LocalM128 sum = partial;
    sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), partial);
    LocalM128 reciprocal = _mm_rsqrt_ss(sum);
    LocalM128 correction = _mm_mul_ss(_mm_mul_ss(sum, reciprocal), reciprocal);
    LocalM128 zeroMask = _mm_cmpeq_ss(sum, _mm_set_ss(DAT_01011d78));
    correction = _mm_sub_ss(_mm_set_ss(DAT_01017718), correction);
    reciprocal = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), reciprocal), correction);
    reciprocal = _mm_andnot_ps(zeroMask, reciprocal);
    return reciprocal;
}

// @fnv 0x00cd4280
// src: XBOX_PDB 0x00cd4280
void __stdcall bhkCharacterStateJumping_Update(MotionController* controller)
{
    if (controller->state != 11 && (controller->state == 0 || controller->state == 3)) {
        controller->bhkCharacterController_UpdateState();
        return;
    }
    controller->flags |= 0x2000; _ReadWriteBarrier();
    controller->vtable->getMotionData(controller);
    GsVec4 reciprocal;
    {
        LocalM128 direction = controller->vtable->getMotionData(controller)->direction;
        controller->vtable->getMotionData(controller);
        struct { float s; float scale; } tmp;
        tmp.scale = controller->directionScale;
        LocalM128 scaleVec = _mm_set_ps1(tmp.scale);
        tmp.scale = (float)fabs(controller->acceleration);
        double absAccel = tmp.scale;
        direction = _mm_mul_ps(scaleVec, direction);
        reciprocal.v = invLength(direction);
        LocalM128 squared = _mm_mul_ps(direction, direction);
        LocalM128 length = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared);
        length = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), length);
        reciprocal.v = _mm_shuffle_ps(reciprocal.v, reciprocal.v, 0);
        length = _mm_mul_ss(length, reciprocal.v);
        _mm_store_ss(&tmp.s, length); float magnitude = -(float)sqrt((float)((tmp.s + tmp.s) * absAccel));
        LocalM128 norm = _mm_mul_ps(reciprocal.v, direction);
        direction = _mm_mul_ps(splatFloat(&magnitude), norm);
        ProxyHolder* proxy = controller->proxy;
        const float* reference = &DAT_01267e30;
        LocalM128 dir;
        if (proxy) {
            controller->bhkCharacterProxy_MarkRead();
            reference = reinterpret_cast<const float*>(proxy->hkpCharacterProxy_getLinearVelocity());
            controller->bhkCharacterProxy_MarkRead();
            dir = direction;
        } else {
            dir = direction;
        }
        direction = _mm_load_ps(reference);
        direction.m128_f32[2] = 0.0f;
        controller->velocity = _mm_add_ps(_mm_load_ps(direction.m128_f32), dir);
    }
    {
        LocalM128 outBuf;
        controller->SubtractVectors(&reciprocal.v);
        FUN_00458620(&outBuf, &reciprocal.v);
        controller->heading = outBuf.m128_f32[2];
    }
    controller->state = 2;
    controller->bhkCharacterController_UpdateState();
    controller->flags &= 0xfffdfeff; _ReadWriteBarrier();
    controller->listeners->GetIndexedValue_00cbc510(controller->listenerIndex)->update(controller);
}

extern "C" LocalM128 _mm_load_ss(const float*);

class CCEAE0Node;

struct CCEAE0Vector {
    float x, y, z, w;
};

class CCEAE0Arg {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_10;
};

class CCEAE0Node {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17();
    virtual CCEAE0Node* v18(CCEAE0Arg* a);
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44();
    virtual CCEAE0Node* v45(bool* flag);
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51();
    virtual bool v52(CCEAE0Arg* a);

    int unk04;
    CCEAE0Node* m_08;
    int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    CCEAE0Vector m_40;

    void bhkShape_CopyMembers(void* a1, CCEAE0Arg* a2);
    void bhkConvexTransformShape_CopyMembers(void* a1, CCEAE0Arg* a2);
};

// @fnv 0x00cceae0
// src: XBOX_PDB 0x00cceae0
void CCEAE0Node::bhkConvexTransformShape_CopyMembers(void* a1, CCEAE0Arg* a2)
{
    bool flag;
    CCEAE0Node* p = v45(&flag);
    CCEAE0Node* q = p->m_08 ? p->m_08->m_08 : 0;
    float f = a2->m_10;
    if (f != 1.0f) {
        hkVec4 s;
        s.m_vComponents = _mm_load_ss(&f);
        s.m_vComponents = _mm_shuffle_ps(s.m_vComponents, s.m_vComponents, 0);
        *reinterpret_cast<LocalM128*>(&p->m_40) = _mm_mul_ps(s.m_vComponents, *reinterpret_cast<LocalM128*>(&p->m_40));
    } else if (!q || q->v52(a2)) {
        goto done;
    }
    {
        CCEAE0Node* r = q->v18(a2);
        p->m_08 = r ? r->m_08 : 0;
    }
done:
    bhkShape_CopyMembers(a1, a2);
}

template<class T> struct NativeArray {
    T* data;int size,capacity;
    __forceinline const T& operator[](int i) const {return data[i];}
    __forceinline T& operator[](int i) {return data[i];}
};
extern "C" {
::LocalM128 _mm_load_ss(const float*);
::LocalM128 _mm_setzero_ps();
void _ReadWriteBarrier();
}
extern const ::LocalM128  DAT_010c71e0;
extern const ::LocalM128  DAT_010c44d0;
extern const ::LocalM128  DAT_010c4c00;
extern const ::LocalM128  DAT_010c7170;
extern const ::LocalM128  DAT_010c4c10;
extern const ::LocalM128  DAT_010ec7f0;

struct NScalar {
private:
    ::LocalM128 bits;
public:
    inline const ::LocalM128& bitsValue() const {return bits;}
    NScalar(const ::LocalM128& a):bits(a) {}
    NScalar(float a) {bits=_mm_load_ss(&a);}
    operator float() const { float a;(::_mm_store_ss)(&a,bits);return a; }
    __forceinline ::LocalM128 splat() const {return _mm_shuffle_ps(bits,bits,0);}
};
class NQuaternion;
struct NTransform;
class NVector {
    union {::LocalM128 data;float lanes[4];};
public:
    __forceinline void operator=(const NVector& a) {data=a.data;}
    __forceinline void operator=(const ::LocalM128& a) {data=a;}
    __forceinline float& operator()(int i) {return lanes[i];}
    __forceinline const ::LocalM128& quad() const {return data;}
    __forceinline ::LocalM128& quad() {return data;}
    __forceinline NScalar dot3(const NVector& a) const {
        ::LocalM128 p=_mm_mul_ps(data,a.data);
        ::LocalM128 y=_mm_add_ss(_mm_shuffle_ps(p,p,0x55),p);
        return _mm_add_ss(_mm_shuffle_ps(p,p,0xaa),y);
    }
    __forceinline operator ::LocalM128() const {return data;}
    __forceinline void negAll(const NVector& a) {data=_mm_xor_ps(a.data,DAT_010c44d0);}
    __forceinline void negThree(const NVector& a) {data=_mm_xor_ps(a.data,DAT_010c4c00);}
    __forceinline void xyzZero(const NVector& a) {data=_mm_and_ps(a,DAT_010c4c10);}
    __forceinline void splatFrom(const NVector& a,int i) {if(i==0)data=_mm_shuffle_ps(a.data,a.data,0);else if(i==1)data=_mm_shuffle_ps(a.data,a.data,0x55);else if(i==2)data=_mm_shuffle_ps(a.data,a.data,0xaa);else if(i==3)data=_mm_shuffle_ps(a.data,a.data,0xff);}
    __forceinline void setZero4() {data=_mm_setzero_ps();}
    __forceinline void setMul4(const NVector& a,const NVector& b) {data=_mm_mul_ps(a.data,b.data);}
    __forceinline void setAdd4(const NVector& a,const NVector& b) {data=_mm_add_ps(a.data,b.data);}
    __forceinline void setSub4(const NVector& a,const NVector& b) {data=_mm_sub_ps(a.data,b.data);}
    __forceinline void addMul4(const NVector& a,const NVector& b) {data=_mm_add_ps(data,_mm_mul_ps(a.data,b.data));}
    __forceinline void triple(const NVector& a,const NVector& b,const NVector& c) {data=_mm_add_ps(a.data,_mm_mul_ps(b.data,c.data));}
    __forceinline void broadcast(int i) {splatFrom(*this,i);}
    __forceinline void add4(const NVector& a) {*this=_mm_add_ps(static_cast<::LocalM128>(*this),static_cast<::LocalM128>(a));}
    __forceinline void mul4(const NVector& a) {data=_mm_mul_ps(data,a.data);}
    __forceinline void mul4(const NScalar& a) {data=_mm_mul_ps(a.splat(),data);}
    __forceinline void addMul4(const NScalar& a,const NVector& b) {data=_mm_add_ps(data,_mm_mul_ps(a.splat(),b.data));}
    __forceinline void subMul4(const NScalar& a,const NVector& b) {data=_mm_sub_ps(data,_mm_mul_ps(a.splat(),b.data));}
    __forceinline void setAddMul4(const NVector& a,const NVector& b,const NScalar& c) {data=_mm_add_ps(a.data,_mm_mul_ps(c.splat(),b.data));}
    __forceinline void setInterpolate4(const NVector& a,const NVector& b,const NScalar& c) {
        ::LocalM128 t=c.splat();
        data=_mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0,t),a.data),_mm_mul_ps(t,b.data));
    }
    __forceinline void cross(const NVector& a,const NVector& b) {
        ::LocalM128 first=_mm_mul_ps(_mm_shuffle_ps(a.data,a.data,0xc9),_mm_shuffle_ps(b.data,b.data,0xd2));
        ::LocalM128 second=_mm_mul_ps(_mm_shuffle_ps(a.data,a.data,0xd2),_mm_shuffle_ps(b.data,b.data,0xc9));
        data=_mm_sub_ps(first,second);
    }
    __forceinline void SetRotatedDirection(const NQuaternion&,const NVector&);
    __forceinline void inverseRotate(const NQuaternion&,const NVector&);
    __forceinline void _setTransformedPos(const NTransform&,const NVector&);
};
class NQuaternion {
public:
    NVector m_vec;
    NQuaternion() {}
    inline void operator=(const NQuaternion& a) {m_vec=a.m_vec;}
    inline const NVector& imag() const {return m_vec;}
    __forceinline void SetConjugate(const NQuaternion& q) {m_vec.negThree(q.imag());}
    void ComputeValues_00cd9d10(const NVector&,const NVector&);
    void setMul(const NQuaternion&,const NQuaternion&);
    void normalize_005611c0();
};
__forceinline void NVector::SetRotatedDirection(const NQuaternion& q,const NVector& a) {
    NVector half;half.quad()=DAT_010c71e0;
    NVector real;real.splatFrom(q.m_vec,3);
    NVector scale;scale.triple(half,real,real);
    NVector accum;accum.setMul4(a,scale);
    NVector dot;dot.quad()=q.imag().dot3(a).bitsValue();
    dot.broadcast(0);
    accum.addMul4(dot,q.imag());
    NVector cp;cp.cross(q.imag(),a);
    accum.addMul4(real,cp);
    setAdd4(accum,accum);
}
__forceinline void NVector::inverseRotate(const NQuaternion& q,const NVector& a) {
    NVector half;half.quad()=DAT_010c71e0;
    NVector real;real.splatFrom(q.m_vec,3);
    NVector scale;scale.triple(half,real,real);
    NVector accum;accum.setMul4(a,scale);
    NVector dot;dot.quad()=q.imag().dot3(a).bitsValue();
    dot.broadcast(0);
    accum.addMul4(dot,q.imag());
    NVector cp;cp.cross(a,q.imag());
    accum.addMul4(real,cp);
    setAdd4(accum,accum);
}
static __forceinline ::LocalM128 reciprocalValue(::LocalM128 a) {::LocalM128 seed=_mm_rcp_ps(a);::LocalM128 error=_mm_mul_ps(_mm_mul_ps(a,seed),seed);return _mm_sub_ps(_mm_add_ps(seed,seed),error);}
// local form of hkQsTransform: 0x00cd8d90 needs inline construction/copy, getters and SetConjugate; shared form gives 4108 bytes vs exe 3959.
struct NTransform {
    NVector m_vTranslation;
    NQuaternion m_rotation;
    NVector m_vScale;
    NTransform() {}
    NTransform(const NTransform& a) {m_vTranslation=a.m_vTranslation;m_rotation=a.m_rotation;m_vScale=a.m_vScale;}
    __forceinline const NVector& getTranslation() const {return m_vTranslation;}
    __forceinline const NQuaternion& getRotation() const {return m_rotation;}
    __forceinline void SetBodyOrientation(const NQuaternion& a) {m_rotation=a;}
    __forceinline void SetConjugate(const NTransform& a) {
        m_vTranslation.inverseRotate(a.m_rotation,a.m_vTranslation);
        m_vTranslation.negAll(m_vTranslation);
        m_rotation.SetConjugate(a.m_rotation);
        NVector ones;ones.quad()=DAT_010c7170;
        NVector withW;
        withW.quad()=_mm_shuffle_ps(a.m_vScale.quad(),_mm_unpackhi_ps(a.m_vScale.quad(),ones.quad()),0xc4);
        NVector inv;inv.quad()=reciprocalValue(withW.quad());
        m_vScale.xyzZero(inv);
    }
};
__forceinline void NVector::_setTransformedPos(const NTransform& a,const NVector& b) {
    NVector v(b);v.mul4(a.m_vScale);SetRotatedDirection(a.m_rotation,v);add4(a.m_vTranslation);
}
struct NativeBool {char value;NativeBool(){}NativeBool(bool a):value(a){}operator bool() const {return value!=0;}NativeBool& operator=(bool a){value=a;return *this;}};

extern "C" ::LocalM128 _mm_cmple_ps(::LocalM128,::LocalM128);
extern "C" int _mm_movemask_ps(::LocalM128);
template<class T> static __forceinline T valueMax(T a,T b) {return a>b?a:b;}
template<class T> static __forceinline T valueMin(T a,T b) {return a<b?a:b;}
struct NativePose {
    void* skeleton;NativeArray<NTransform> locals,transforms;NativeArray<unsigned> flags;
    bool modelSync,localSync;
    const NTransform& hkaPose_calculateBoneModelSpace(int) const;
    NTransform& accessBoneModelSpace(int,int);
    __forceinline const NTransform& get(int i) const {
        if(!(flags[i]&2))return transforms[i];
        return hkaPose_calculateBoneModelSpace(i);
    }
};
struct NativeInput {
    NTransform desired;
    NTransform world;
    bool enabled;
    void* query;
    float blend, rise, fall, speed0, speed1, decay;
    unsigned filter;
    bool useFilter;
};
struct NativeOutput { float error; bool active; };
struct NativeSetup {
    short bone0,bone1,bone2,twist0,twist1;
    NVector axis;
    float gain,limit,weight,weight2,weight3;
    NVector point;NQuaternion targetRotation;NVector offset;
    NQuaternion rotation;
    NativeBool positionOn,rotationOn;
    NativeSetup() {FUN_00c74ed0();}
    void FUN_00c74ed0();
};
NativeBool hkaTwoJointsIkSolver_solve(const NativeSetup&,NativePose&);
struct NativeSettings {
    void* skeleton;
    short bone0,bone1,bone2;
    NVector axis,localPoint,direction,plane;
    float offset,minDistance,maxDistance,lowerLimit,upperLimit,gain,limit,unk7c,unk80;
    bool lock;

};
struct NativeSolver {
    int unk00,unk04,unk08,unk0c;
    NativeSettings settings;
    float weight,correction;
    NVector oldNormal;
    float previous;
    NativeBool cached;
    NVector cachePoint,cacheTarget,drift;
    bool RayCast(const NativeInput&,const NVector&,const NVector&,float&,NVector&) const;
    bool hkaFootPlacementIkSolver_castFoot(const NativeInput&,const NVector&,const NVector&,NVector&,NVector&) const;
};

extern const float  DAT_01017d00;
extern const ::LocalM128 DAT_01017d10;
// src: XBOX_PDB 0x00cd8a50
__declspec(noinline) bool NativeSolver::hkaFootPlacementIkSolver_castFoot(const NativeInput& a,const NVector& foot,const NVector& toe,NVector& projected,NVector& normal) const {
    float above=settings.unk7c, below=settings.unk80;
    float span=above+below;
    float fraction0=::DAT_0104da48,fraction1=::DAT_0104da48;
    NVector start,end,n0,n1;
    start.setAddMul4(foot,settings.direction,above);
    end.setAddMul4(foot,settings.direction,-below);
    bool hit0=RayCast(a,start,end,fraction0,n0),hit1=false;
    ::LocalM128 delta=_mm_and_ps(_mm_sub_ps(toe.quad(),foot.quad()),DAT_01017d10);
    ::LocalM128 epsilonVector=_mm_set_ps1(DAT_01017d00);
    if ((_mm_movemask_ps(_mm_cmple_ps(delta,epsilonVector))&7)!=7) {
        start.setAddMul4(toe,settings.direction,above);
        end.setAddMul4(toe,settings.direction,-below);
        hit1=RayCast(a,start,end,fraction1,n1);
        if (hit1) {
            float up=n1.dot3(settings.direction);
            if(up<=0.0f)hit1=false;
            else {
                NVector position,ray;
                ray.setSub4(end,start);position.setAddMul4(start,ray,fraction1);
                float planeHeight=-float(position.dot3(n1));
                start.setAddMul4(foot,settings.direction,above);
                float height=start.dot3(n1);
                fraction1=-(planeHeight+height)/(-span*up);
            }
        }
    }
    if(!hit0&&!hit1)return false;
    if(hit0&&fraction0<=fraction1) {normal=n0;fraction1=fraction0;}
    else normal=n1;
    projected.setAddMul4(foot,settings.direction,-(fraction1*span-above));
    return true;
}

static __forceinline ::LocalM128 rawDot(::LocalM128 a,::LocalM128 b) {
    ::LocalM128 p=_mm_mul_ps(a,b);
    ::LocalM128 y=_mm_add_ss(_mm_shuffle_ps(p,p,0x55),p);
    return _mm_add_ss(_mm_shuffle_ps(p,p,0xaa),y);
}
static __forceinline void rotateFront(NVector& out,const NQuaternion& quat,const NVector& dir) {
    const ::LocalM128& q=quat.m_vec.quad();
    ::LocalM128 a=dir.quad();
    ::LocalM128 cross=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(q,q,0xc9),_mm_shuffle_ps(a,a,0xd2)),_mm_mul_ps(_mm_shuffle_ps(q,q,0xd2),_mm_shuffle_ps(a,a,0xc9)));
    ::LocalM128 r=_mm_shuffle_ps(q,q,0xff);
    ::LocalM128 h=_mm_add_ps(_mm_mul_ps(r,r),DAT_010c71e0);
    ::LocalM128 result=_mm_mul_ps(a,h);
    ::LocalM128 dot=rawDot(q,a);
    result=_mm_add_ps(result,_mm_mul_ps(_mm_shuffle_ps(dot,dot,0),q));
    result=_mm_add_ps(result,_mm_mul_ps(cross,r));
    out.quad()=_mm_add_ps(result,result);
}
extern "C" ::LocalM128 _mm_rsqrt_ps(::LocalM128);
extern "C" ::LocalM128 _mm_sqrt_ps(::LocalM128);
extern "C" ::LocalM128 _mm_cmpgt_ps(::LocalM128,::LocalM128);
extern "C" ::LocalM128 _mm_cmplt_ps(::LocalM128,::LocalM128);
static const ::LocalM128 quaternionUnit={{0.0f,0.0f,0.0f,1.0f}};
static const ::LocalM128 quaternionOne={{1.0f,1.0f,1.0f,1.0f}};
static const ::LocalM128 quaternionHalf={{0.5f,0.5f,0.5f,0.5f}};
static const ::LocalM128 quaternionThree={{3.0f,3.0f,3.0f,3.0f}};
static const ::LocalM128 parallelLimit={{0.99999f,0.99999f,0.99999f,0.99999f}};
static const ::LocalM128 opposedLimit={{-0.99999f,-0.99999f,-0.99999f,-0.99999f}};
static const ::LocalM128 correctionLimit={{-0.999f,-0.999f,-0.999f,-0.999f}};
static const ::LocalM128 axisFirst={{1.0f,0.0f,0.0f,0.0f}};
static const ::LocalM128 axisSecond={{0.0f,1.0f,0.0f,0.0f}};
static __forceinline ::LocalM128 inverseRoot(::LocalM128 value) {
    ::LocalM128 r=_mm_rsqrt_ps(value);
    return _mm_mul_ps(_mm_mul_ps(quaternionHalf,r),_mm_sub_ps(quaternionThree,_mm_mul_ps(_mm_mul_ps(value,r),r)));
}
static __forceinline ::LocalM128 normalizedQuaternion(::LocalM128 value) {
    ::LocalM128 p=_mm_mul_ps(value,value);
    ::LocalM128 sum=_mm_add_ps(p,_mm_shuffle_ps(p,p,0x4e));
    sum=_mm_add_ps(sum,_mm_shuffle_ps(sum,sum,0xb1));
    return _mm_mul_ps(value,inverseRoot(sum));
}
// src: GUESS 0x00cd9d10 (confidence: low)
inline void NQuaternion::ComputeValues_00cd9d10(const NVector& from,const NVector& to) {
    ::LocalM128 dot=rawDot(from.quad(),to.quad());
    dot=_mm_shuffle_ps(dot,dot,0);
    if (_mm_movemask_ps(_mm_cmpgt_ps(dot,parallelLimit))) m_vec.quad()=quaternionUnit;
    else if (_mm_movemask_ps(_mm_cmplt_ps(dot,opposedLimit))) {
        NVector axis;
        float x=from.quad().m128_f32[0];
        if(x> -0.5f && x<0.5f)axis.quad()=axisFirst;
        else axis.quad()=axisSecond;
        NVector perpendicular;perpendicular.cross(from,axis);
        perpendicular(3)=0.0f;
        m_vec.quad()=normalizedQuaternion(perpendicular.quad());
    } else {
        ::LocalM128 halfAngle=_mm_mul_ps(quaternionHalf,_mm_add_ps(quaternionOne,dot));
        ::LocalM128 invCosine=inverseRoot(halfAngle);
        NVector cross;cross.cross(from,to);
        ::LocalM128 factor=_mm_mul_ps(quaternionHalf,invCosine);
        if(_mm_movemask_ps(_mm_cmplt_ps(dot,correctionLimit))) {
            ::LocalM128 length=rawDot(cross.quad(),cross.quad());
            length=_mm_shuffle_ps(length,length,0);
            factor=_mm_mul_ps(_mm_sqrt_ps(_mm_sub_ps(halfAngle,dot)),inverseRoot(length));
        }
        ::LocalM128 imaginary=_mm_mul_ps(cross.quad(),factor);
        ::LocalM128 real=_mm_mul_ps(halfAngle,invCosine);
        m_vec.quad()=_mm_shuffle_ps(imaginary,_mm_unpackhi_ps(imaginary,real),0xc4);
    }
}

// src: COMMUNITY 0x00c66320
__declspec(noinline) void NQuaternion::setMul(const NQuaternion& a,const NQuaternion& b) {
    ::LocalM128 av=a.m_vec.quad(),bv=b.m_vec.quad();
    ::LocalM128 cp=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(av,av,0xc9),_mm_shuffle_ps(bv,bv,0xd2)),_mm_mul_ps(_mm_shuffle_ps(av,av,0xd2),_mm_shuffle_ps(bv,bv,0xc9)));
    ::LocalM128 xyz=_mm_add_ps(_mm_add_ps(cp,_mm_mul_ps(_mm_shuffle_ps(av,av,0xff),bv)),_mm_mul_ps(_mm_shuffle_ps(bv,bv,0xff),av));
    ::LocalM128 p=_mm_mul_ps(av,bv);::LocalM128 dot=rawDot(av,bv);
    ::LocalM128 w=_mm_sub_ps(p,_mm_shuffle_ps(dot,dot,0));
    m_vec.quad()=_mm_shuffle_ps(xyz,_mm_unpackhi_ps(xyz,w),0xc4);
}

static __forceinline float scalarDotValue(::LocalM128 a,::LocalM128 b) {float f;(::_mm_store_ss)(&f,rawDot(a,b));return f;}
static __forceinline void scalarDotStore(float& f,::LocalM128 a,::LocalM128 b){(::_mm_store_ss)(&f,rawDot(a,b));}

// @fnv 0x00cd8d90
// src: XBOX_PDB 0x00cd8d90
extern "C" void __fastcall hkaFootPlacementIkSolver_doFootPlacement(NativeSolver* self,void*,const NativeInput& a,NativeOutput& out,NativePose& pose) {
    const NTransform& world=a.world;
    NTransform inverse;
    inverse.SetConjugate(world);
    NVector localDirection;
    rotateFront(localDirection,inverse.getRotation(),self->settings.direction);
    out.active=true;
    float initialDistance=a.desired.getTranslation().dot3(self->settings.plane);
    const NQuaternion& originalRotation=a.desired.getRotation();
    NQuaternion inputRotation=pose.get(self->settings.bone2).getRotation();
    NTransform base(pose.get(self->settings.bone2));
    NVector target;
    const NVector& position=base.getTranslation();target._setTransformedPos(world,position);
    bool enabled=a.enabled;
    NVector savedNormal;
    NVector point;
    float adjustment,actual;

    if (!enabled) {
        out.active=false;
        savedNormal=self->oldNormal;
        point.setAddMul4(base.getTranslation(),localDirection,self->previous);
        actual=float(target.dot3(self->settings.direction))+self->previous-initialDistance;
        adjustment=actual;
        out.error=0.0f;

        self->cached=false;
    } else {
        const bool wasCached=self->cached;
        NVector normal;
        if (self->settings.lock) {
            self->cached=false;
            if (initialDistance<self->settings.minDistance) {
                if (wasCached) {
                    target=self->cachePoint;
                    base.m_vTranslation._setTransformedPos(inverse,target);
                } else {
                    self->cachePoint=target;
                    NVector local;
                    local._setTransformedPos(base,self->settings.localPoint);
                    self->cacheTarget._setTransformedPos(world,local);
                }
                self->cached=true;
            }
        }
        NVector local;
        local._setTransformedPos(base,self->settings.localPoint);
        NVector rayPoint;
        if (self->settings.lock && self->cached) rayPoint=self->cacheTarget;
        else rayPoint._setTransformedPos(world,local);
        bool hit=self->hkaFootPlacementIkSolver_castFoot(a,target,rayPoint,normal,savedNormal);
        if (!hit) {
            out.active=false;
            enabled=false;
            savedNormal=self->oldNormal;
            point.setAddMul4(base.getTranslation(),localDirection,self->previous);
            actual=float(target.dot3(self->settings.direction))+self->previous-initialDistance;
            adjustment=actual;
            out.error=0.0f;
    
            self->cached=false;
        } else {
            if (self->cached) {
                target=normal;
                self->cachePoint=normal;
                base.m_vTranslation._setTransformedPos(inverse,normal);
                NVector local;
                local._setTransformedPos(base,self->settings.localPoint);
                self->cacheTarget._setTransformedPos(world,local);
            }
            out.active=true;
            actual=normal.dot3(self->settings.direction);
            float distance=scalarDotValue(self->settings.direction.quad(),a.world.m_vTranslation.quad());out.error=actual-(self->settings.offset+distance);
            savedNormal(3)=0.0f;
const NVector& offset=self->drift;
            NVector perpendicular;
            perpendicular.setAddMul4(normal,self->settings.direction,-actual);
            float speed=1.0f-(initialDistance-self->settings.minDistance)/(self->settings.maxDistance-self->settings.minDistance);
            speed=valueMax<float>(0.0f,speed);
            speed=valueMin<float>(1.0f,speed);
            speed=speed*a.speed0+(1.0f-speed)*a.speed1;
            if (self->weight==0.0f) adjustment=actual;
            else {
                const float rate=self->correction>actual?a.fall:a.rise;
                const float factor=rate*speed;
                adjustment=(actual-self->correction)*factor+self->correction;
            }
            if (self->settings.lock) {
                if (self->cached) self->drift.setZero4();
                else {
                    if (wasCached) {
                        NVector delta;delta.setSub4(self->cachePoint,perpendicular);self->drift=delta;self->drift.subMul4(self->settings.direction.dot3(delta),self->settings.direction);
                    }
                    perpendicular.add4(offset);
                    self->drift.mul4(1.0f-a.decay);
                }
            }
            NVector movedWorld,movedLocal;
            movedWorld.setAddMul4(perpendicular,self->settings.direction,adjustment);
            movedLocal._setTransformedPos(inverse,movedWorld);
            point.setAddMul4(movedLocal,localDirection,initialDistance-self->settings.offset);
            const float low=self->settings.lowerLimit, high=self->settings.upperLimit;
            float projection=point.dot3(self->settings.plane);
            if (projection>low) point.addMul4(low-projection,self->settings.plane);
            if (high>projection) {
                out.active=false;
                enabled=false;
                savedNormal=self->oldNormal;
                point.setAddMul4(base.getTranslation(),localDirection,self->previous);
                adjustment=float(target.dot3(self->settings.direction))+self->previous-initialDistance;
                out.error=0.0f;
            }
            NVector delta;
            delta.setSub4(point,base.getTranslation());
            self->previous=delta.dot3(self->settings.plane);

        }
    }
    const float requested=enabled?1.0f:0.0f;
    self->weight+=(requested-self->weight)*a.blend;
    if (self->weight<0.01f) self->weight=0.0f;
    if (self->weight>0.0f) {
        {
            NativeSetup setup;
            setup.bone0=self->settings.bone0;setup.bone1=self->settings.bone1;setup.bone2=self->settings.bone2;
            setup.axis=self->settings.axis;setup.point=point;
            setup.limit=self->settings.limit;setup.gain=self->settings.gain;
            setup.weight=self->weight;setup.weight2=self->weight;setup.weight3=self->weight;
            hkaTwoJointsIkSolver_solve(setup,pose);
        }
        {
            const NVector& desiredUp=savedNormal;
            NVector localUp,localNormal;
            localUp.SetRotatedDirection(inverse.getRotation(),self->settings.direction);
            localNormal.SetRotatedDirection(inverse.getRotation(),desiredUp);
            NQuaternion rotation,combined,interpolated;
            rotation.ComputeValues_00cd9d10(localUp,localNormal);
            combined.setMul(rotation,originalRotation);
            interpolated.m_vec.setInterpolate4(originalRotation.m_vec,combined.m_vec,self->weight);
            interpolated.normalize_005611c0();
            pose.accessBoneModelSpace(self->settings.bone2,1).SetBodyOrientation(interpolated);
        }
    } else out.error=0.0f;
    self->oldNormal=savedNormal;
    self->correction=adjustment;
}

typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" {
::LocalM128 _mm_sub_ss(::LocalM128,::LocalM128);
::LocalM128 _mm_mul_ss(::LocalM128,::LocalM128);
::LocalM128 _mm_andnot_ps(::LocalM128,::LocalM128);
::LocalM128 _mm_cmpeq_ss(::LocalM128,::LocalM128);
::LocalM128 _mm_rsqrt_ss(::LocalM128);
::LocalM128 _mm_setzero_ps();
::LocalM128 _mm_load_ss(const float*);
void _mm_store_ss(float*,::LocalM128);
}
extern "C" ::LocalM128 _mm_set_ss(float);
extern "C" ::LocalM128 _mm_set_ps1(float);
extern "C" DWORD DAT_0126835c;
extern "C" unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);
extern "C" double __cdecl sqrt(double);

extern "C" const ::LocalM128 DAT_010c71b0; // (0,0,0,1)
extern "C" const ::LocalM128 DAT_010c71e0; // -0.5 splat
extern "C" const ::LocalM128 DAT_010c4c00; // sign mask xyz
extern "C" const ::LocalM128 DAT_010c44d0; // sign mask xyzw
extern "C" const ::LocalM128 DAT_010c4c10; // mask xyz
extern "C" const ::LocalM128 DAT_010c7170; // 1.0 splat

extern "C" const float DAT_01012068;
extern "C" __declspec(dllimport) int __stdcall IsBadWritePtr(void*,unsigned int);
static __forceinline void StoreTimer(DWORD& out) { DWORD stamp; __assume(!IsBadWritePtr(&stamp,sizeof(stamp)));
__asm {
rdtsc
mov dword ptr[stamp], eax
}
 out=stamp; }
static __forceinline void TimerLayer0(DWORD& out) { StoreTimer(out); }
static __forceinline void TimerLayer1(DWORD& out) { TimerLayer0(out); }
__forceinline void hkMonitorStream_raw::TimerCommand::setTime() { TimerLayer1((DWORD&)m_time0); }

static __forceinline unsigned __int64 GetTickCounter()
{
    return __rdtsc();
}

static __forceinline DWORD Tick()
{
    _ReadWriteBarrier();
    DWORD ticks=(DWORD)GetTickCounter();
    return ticks;
}

struct IkVector4
{
    ::LocalM128 m_vComponents;
    __forceinline IkVector4() {}
    __forceinline void operator=(const IkVector4& v) { m_vComponents = v.m_vComponents; }
    void FUN_00c7f7a0(const hkQsTransform& t, const IkVector4& v);
};

struct QuadWords { unsigned int x,y,z,w; };
static __forceinline void CopyIkRotation(hkQuaternion& out, const hkQuaternion& q) { *(QuadWords*)&out=*(const QuadWords*)&q; }
static __forceinline ::LocalM128& QuaternionQuad(hkQuaternion& q) { return *reinterpret_cast<::LocalM128*>(&q); }
static __forceinline const ::LocalM128& QuaternionQuad(const hkQuaternion& q) { return *reinterpret_cast<const ::LocalM128*>(&q); }
__forceinline hkQuaternion::hkQuaternion() {}
__forceinline hkQuaternion::hkQuaternion(const hkQuaternion& q) { QuaternionQuad(*this).m128_u64[0]=QuaternionQuad(q).m128_u64[0]; QuaternionQuad(*this).m128_u64[1]=QuaternionQuad(q).m128_u64[1]; }
__forceinline void hkQuaternion::operator=(const hkQuaternion& q) { QuaternionQuad(*this)=QuaternionQuad(q); }

float __cdecl ClampedAcos(float x);

static __forceinline ::LocalM128 Dot3(::LocalM128 a, ::LocalM128 b)
{
    ::LocalM128 x2 = _mm_mul_ps(a, b);
    ::LocalM128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
}

// Keep the IK scalar result as a plain aggregate to preserve VC9 SIMD scheduling.
struct IkDotResult { LocalM128 m_vValue; };

static __forceinline IkDotResult Dot3S(const ::LocalM128& a, const ::LocalM128& b)
{
    IkDotResult r;
    ::LocalM128 x2 = _mm_mul_ps(a, b);
    ::LocalM128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    r.m_vValue = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
    return r;
}
static __forceinline IkDotResult Dot3Srev(const ::LocalM128& a, const ::LocalM128& b)
{
    IkDotResult r;
    ::LocalM128 x2 = _mm_mul_ps(b, a);
    ::LocalM128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    r.m_vValue = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
    return r;
}

struct MathQuad {
 ::LocalM128 m_vComponents;
 __forceinline MathQuad() {}
 __forceinline MathQuad(const ::LocalM128& x):m_vComponents(x) {}
 template<int shuffle> __forceinline void component(const MathQuad& a) { m_vComponents=_mm_shuffle_ps(a.m_vComponents,a.m_vComponents,shuffle); }
 __forceinline void product(const MathQuad& a,const MathQuad& b) { m_vComponents=_mm_mul_ps(a.m_vComponents,b.m_vComponents); }
 __forceinline void sumProduct(const MathQuad& offset,const MathQuad& a,const MathQuad& b) { m_vComponents=_mm_add_ps(offset.m_vComponents,_mm_mul_ps(a.m_vComponents,b.m_vComponents)); }
 __forceinline void accumulate(const MathQuad& a,const MathQuad& b) { m_vComponents=_mm_add_ps(m_vComponents,_mm_mul_ps(a.m_vComponents,b.m_vComponents)); }
 __forceinline void crossed(const MathQuad& a,const MathQuad& b) {
  m_vComponents=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.m_vComponents,a.m_vComponents,0xc9),_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,0xd2)),_mm_mul_ps(_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,0xc9),_mm_shuffle_ps(a.m_vComponents,a.m_vComponents,0xd2)));
 }
 __forceinline IkDotResult dotted(const MathQuad& b) const { return Dot3S(m_vComponents,b.m_vComponents); }
 __forceinline void doubleValue(const MathQuad& a) { m_vComponents=_mm_add_ps(a.m_vComponents,a.m_vComponents); }
};

class DotValue {
 ::LocalM128 quad;
public:
 __forceinline DotValue(){}
 __forceinline DotValue(const ::LocalM128& x):quad(x){}
 __forceinline void operator=(const ::LocalM128& x){quad=x;}
 __forceinline operator ::LocalM128()const{return quad;}
};
class DotReference {
 ::LocalM128 quad;
public:
 __forceinline DotReference(){}
 __forceinline DotReference(const ::LocalM128& x):quad(x){}
 __forceinline void operator=(const ::LocalM128& x){quad=x;}
 __forceinline operator const ::LocalM128&()const{return quad;}
};
static __forceinline ::LocalM128 RotatedDir(const ::LocalM128& q,const ::LocalM128& v) {
MathQuad rotation(q);
MathQuad scalar; scalar.component<0xff>(rotation);

MathQuad input(v);
MathQuad bias(DAT_010c71e0);
MathQuad factor; factor.sumProduct(bias,scalar,scalar);
MathQuad value; value.product(input,factor);
DotValue wrapped(v);MathQuad projection(Dot3S(rotation.m_vComponents,(::LocalM128)wrapped).m_vValue); projection.component<0>(projection);
value.accumulate(projection,rotation);
MathQuad perpendicular; perpendicular.m_vComponents=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(rotation.m_vComponents,rotation.m_vComponents,0xc9),_mm_shuffle_ps(input.m_vComponents,input.m_vComponents,0xd2)),_mm_mul_ps(_mm_shuffle_ps(input.m_vComponents,input.m_vComponents,0xc9),_mm_shuffle_ps(rotation.m_vComponents,rotation.m_vComponents,0xd2)));
value.accumulate(scalar,perpendicular);
value.doubleValue(value);
return value.m_vComponents;
}
static __forceinline ::LocalM128 TargetRotation(const ::LocalM128& q, const ::LocalM128& v)
{
    MathQuad rotation(q), input(v), bias(DAT_010c71e0);
    MathQuad scalar; scalar.component<0xff>(rotation);
    MathQuad factor; factor.sumProduct(bias,scalar,scalar);
    MathQuad value; value.product(input,factor);
    MathQuad projection(rotation.dotted(input).m_vValue); projection.component<0>(projection);
    value.accumulate(projection,rotation);
    MathQuad perpendicular; perpendicular.crossed(rotation,input);
    value.accumulate(scalar,perpendicular);
    MathQuad result; result.doubleValue(value);
    return result.m_vComponents;
}
struct HingeScalar {
private: ::LocalM128 quad;
public:
 __forceinline HingeScalar() {}
 __forceinline HingeScalar(::LocalM128 x):quad(x) {}
 __forceinline operator ::LocalM128() const {return quad;}
 __forceinline ::LocalM128 raw() const {return quad;}
};
struct HingeVector {
 ::LocalM128 quad;
 __forceinline HingeVector() {}
 __forceinline HingeVector(const ::LocalM128& x):quad(x) {}
 __forceinline void mul(const HingeVector& a,const HingeVector& b) {quad=_mm_mul_ps(a.quad,b.quad);}
 __forceinline void addMul(const HingeVector& z,const HingeVector& a,const HingeVector& b) {quad=_mm_add_ps(z.quad,_mm_mul_ps(a.quad,b.quad));}
 __forceinline void accum(const HingeVector& a,const HingeVector& b) {quad=_mm_add_ps(quad,_mm_mul_ps(a.quad,b.quad));}
 __forceinline void plus(const HingeVector& a,const HingeVector& b) {quad=_mm_add_ps(a.quad,b.quad);}
 __forceinline HingeScalar dot(const HingeVector& b) const {::LocalM128 p=_mm_mul_ps(quad,b.quad);::LocalM128 sum=_mm_add_ss(_mm_shuffle_ps(p,p,0x55),p);return HingeScalar(_mm_add_ss(_mm_shuffle_ps(p,p,0xaa),sum));}
 __forceinline void cross(const HingeVector& a,const HingeVector& b) {quad=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.quad,a.quad,0xc9),_mm_shuffle_ps(b.quad,b.quad,0xd2)),_mm_mul_ps(_mm_shuffle_ps(b.quad,b.quad,0xc9),_mm_shuffle_ps(a.quad,a.quad,0xd2)));}
 __forceinline void splat(const HingeVector& a) {quad=_mm_shuffle_ps(a.quad,a.quad,0xff);}
 __forceinline void broadcast() {quad=_mm_shuffle_ps(quad,quad,0);}
};
static __forceinline ::LocalM128 HingeRotation(const ::LocalM128& q,const ::LocalM128& v) {
const HingeVector& rotation=*(const HingeVector*)&q;const HingeVector& input=*(const HingeVector*)&v;
HingeVector bias(DAT_010c71e0);
HingeVector w;w.splat(rotation);
HingeVector factor;factor.addMul(bias,w,w);
HingeVector value;value.mul(input,factor);
HingeVector projection(rotation.dot(input));projection.broadcast();
value.accum(projection,rotation);
HingeVector cross;cross.cross(rotation,input);
value.accum(w,cross);
HingeVector out;out.plus(value,value);
return out.quad;
}
static __forceinline ::LocalM128 ForwardDot(const ::LocalM128& a,const ::LocalM128& b) { const ::LocalM128 x=_mm_mul_ps(b,a); const ::LocalM128 xy=_mm_add_ss(_mm_shuffle_ps(x,x,0x55),x); const ::LocalM128 z=_mm_shuffle_ps(x,x,0xaa); return _mm_add_ss(z,xy); }
static __forceinline ::LocalM128 RotateForward(const ::LocalM128& q, const ::LocalM128& v)
{
    const ::LocalM128 w = _mm_shuffle_ps(q, q, 0xff);
    const ::LocalM128 dot=ForwardDot(q,v);
    ::LocalM128 cross;
    cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(q,q,0xc9),_mm_shuffle_ps(v,v,0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)));
    cross = _mm_mul_ps(cross, w);
    ::LocalM128 result;
    result = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q));
    cross = _mm_add_ps(cross, result);
    return _mm_add_ps(cross, cross);
}static __forceinline ::LocalM128 InitialForward(const hkQuaternion& rotation,const hkVector4& input) { const ::LocalM128& v=input.m_vComponents; const ::LocalM128& q=QuaternionQuad(rotation);
    const ::LocalM128 w = _mm_shuffle_ps(q, q, 0xff);
    const ::LocalM128 dot=ForwardDot(q,v);
    ::LocalM128 cross;
    cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(q,q,0xc9),_mm_shuffle_ps(v,v,0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)));
    cross = _mm_mul_ps(cross, w);
    ::LocalM128 result;
    result = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q));
    cross = _mm_add_ps(cross, result);
    return _mm_add_ps(cross, cross);
}
static __forceinline ::LocalM128 FirstRestoreForward(const ::LocalM128& v,::LocalM128 q) {
    const ::LocalM128 w = _mm_shuffle_ps(q, q, 0xff);
    const IkDotResult dot=Dot3S(v,q);
    ::LocalM128 cross;
    cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(q,q,0xc9),_mm_shuffle_ps(v,v,0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)));
    cross = _mm_mul_ps(cross, w);
    ::LocalM128 result;
    result = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(dot.m_vValue,dot.m_vValue,0), q));
    cross = _mm_add_ps(cross, result);
    return _mm_add_ps(cross, cross);
}

static __forceinline ::LocalM128 ContextForward(::LocalM128 q, ::LocalM128 v)
{
    const ::LocalM128 w = _mm_shuffle_ps(q, q, 0xff);
    const ::LocalM128 dot=ForwardDot(q,v);
    ::LocalM128 cross;
    cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(q,q,0xc9),_mm_shuffle_ps(v,v,0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)));
    cross = _mm_mul_ps(cross, w);
    ::LocalM128 result;
    result = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q));
    cross = _mm_add_ps(cross, result);
    return _mm_add_ps(cross, cross);
}

static __forceinline ::LocalM128 RotatedInverseDir(const ::LocalM128& q, const ::LocalM128& v)
{
    const ::LocalM128 w = _mm_shuffle_ps(q, q, 0xff);
    const IkDotResult d = Dot3S(q, v);
    IkVector4 c;
    c.m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9)));
    c.m_vComponents = _mm_mul_ps(c.m_vComponents, w);
    IkVector4 r;
    r.m_vComponents = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    r.m_vComponents = _mm_add_ps(r.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(d.m_vValue, d.m_vValue, 0), q));
    c.m_vComponents = _mm_add_ps(c.m_vComponents, r.m_vComponents);
    return _mm_add_ps(c.m_vComponents, c.m_vComponents);
}

static __forceinline ::LocalM128 Normalized3(const ::LocalM128& v)
{
    const ::LocalM128 lenSq = Dot3S(v, v).m_vValue;
    ::LocalM128 r = _mm_rsqrt_ss(lenSq);
    ::LocalM128 inv = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), r),
                            _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(lenSq, r), r)));
    inv = _mm_andnot_ps(_mm_cmpeq_ss(lenSq, _mm_set_ss(0.0f)), inv);
    return _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), v);
}

static __forceinline ::LocalM128 Normalized3Approx(const ::LocalM128& v)
{
    const ::LocalM128 lenSq = Dot3S(v, v).m_vValue;
    ::LocalM128 r = _mm_rsqrt_ss(lenSq);
    return _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v);
}

static __forceinline float ToReal(::LocalM128 x)
{
    float f; (_mm_store_ss)(&f,x); return f;
}

static __forceinline float Sqrt(float x)
{
    return (float)sqrt(x);
}

template <typename T> static __forceinline T Min2(T a, T b) { return b < a ? b : a; }
template <typename T> static __forceinline T Max2(T a, T b) { return a > b ? a : b; }


__declspec(noinline) void MultiplyQuaternions(const hkQuaternion& q0,const hkQuaternion& q1,hkQuaternion& out)
{
    const ::LocalM128 a=QuaternionQuad(q0);
    const ::LocalM128 dots=Dot3S(QuaternionQuad(q0),QuaternionQuad(q1)).m_vValue;
    const ::LocalM128 b=QuaternionQuad(q1);
    IkVector4 cross;
    cross.m_vComponents=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b,b,0xd2),_mm_shuffle_ps(a,a,0xc9)),_mm_mul_ps(_mm_shuffle_ps(b,b,0xc9),_mm_shuffle_ps(a,a,0xd2)));
    const ::LocalM128 aw=_mm_shuffle_ps(a,a,0xff);
    const ::LocalM128 bw=_mm_shuffle_ps(b,b,0xff);
    IkVector4 vec;
    vec.m_vComponents=_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(aw,aw,0),b),cross.m_vComponents);
    vec.m_vComponents=_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(bw,bw,0),a),vec.m_vComponents);
    const ::LocalM128 mul=_mm_mul_ps(b,a);
    const ::LocalM128 real=_mm_sub_ps(mul,_mm_shuffle_ps(dots,dots,0));
    const ::LocalM128 high=_mm_unpackhi_ps(vec.m_vComponents,real);
    QuaternionQuad(out)=_mm_shuffle_ps(vec.m_vComponents,high,0xc4);
}

// src: COMMUNITY 0x00c66320
__declspec(noinline) void hkQuaternion::setMul(const hkQuaternion& q0, const hkQuaternion& q1)
{ MultiplyQuaternions(q0,q1,*this); }

extern "C" {
::LocalM128 _mm_rsqrt_ps(::LocalM128);::LocalM128 _mm_cmpeq_ps(::LocalM128,::LocalM128);
::LocalM128 _mm_unpacklo_ps(::LocalM128,::LocalM128);::LocalM128 _mm_movelh_ps(::LocalM128,::LocalM128);
}
// src: COMMUNITY 0x005611c0
__declspec(noinline) void hkQuaternion::normalize_005611c0(){const ::LocalM128 half=_mm_set_ps1(0.5f),three=_mm_set_ps1(3.0f),zero=_mm_setzero_ps();

 const ::LocalM128 input=QuaternionQuad(*this);
 const ::LocalM128 x=_mm_shuffle_ps(input,input,0);
 const ::LocalM128 y=_mm_shuffle_ps(input,input,0x55);
 const ::LocalM128 z=_mm_shuffle_ps(input,input,0xaa);
 const ::LocalM128 w=_mm_shuffle_ps(input,input,0xff);
 const ::LocalM128 length=_mm_add_ps(_mm_add_ps(_mm_mul_ps(x,x),_mm_mul_ps(z,z)),_mm_add_ps(_mm_mul_ps(y,y),_mm_mul_ps(w,w)));
 const ::LocalM128 mask=_mm_cmpeq_ps(length,zero);
 const ::LocalM128 root=_mm_rsqrt_ps(length);
 const ::LocalM128 correction=_mm_sub_ps(three,_mm_mul_ps(_mm_mul_ps(length,root),root));
 const ::LocalM128 scale=_mm_andnot_ps(mask,_mm_mul_ps(_mm_mul_ps(half,root),correction));
 const ::LocalM128 lower=_mm_unpacklo_ps(_mm_mul_ps(x,scale),_mm_mul_ps(y,scale));
 const ::LocalM128 upper=_mm_unpacklo_ps(_mm_mul_ps(z,scale),_mm_mul_ps(w,scale));
 QuaternionQuad(*this)=_mm_movelh_ps(lower,upper);
}

__forceinline hkQsTransform::hkQsTransform() {}
__forceinline hkQsTransform::hkQsTransform(const hkQsTransform& t) { m_vTranslation=t.m_vTranslation; m_rotation=t.m_rotation; m_vScale=t.m_vScale; }
__forceinline void hkQsTransform::setIdentity()
    {
        m_vTranslation.m_vComponents = _mm_setzero_ps();
        QuaternionQuad(m_rotation) = DAT_010c71b0;
        m_vScale.m_vComponents = _mm_set_ps1(DAT_01012068);
    }
__forceinline void hkQsTransform::SetConjugate(const hkQsTransform& t)
    {
        m_vTranslation.m_vComponents = _mm_xor_ps(RotatedInverseDir(QuaternionQuad(t.m_rotation), t.m_vTranslation.m_vComponents), DAT_010c44d0);
        QuaternionQuad(m_rotation) = _mm_xor_ps(QuaternionQuad(t.m_rotation), DAT_010c4c00);
        ::LocalM128 s = t.m_vScale.m_vComponents;
        ::LocalM128 h = _mm_unpackhi_ps(s, DAT_010c7170);
        s = _mm_shuffle_ps(s, h, 0xc4);
        ::LocalM128 r = _mm_rcp_ps(s);
        ::LocalM128 rs = _mm_mul_ps(r, s);
        r = _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(rs, r));
        m_vScale.m_vComponents = _mm_and_ps(r, DAT_010c4c10);
    }
__forceinline void hkQsTransform::SetProduct(const hkQsTransform& a, const hkQsTransform& b)
    {
        m_vTranslation.m_vComponents = _mm_add_ps(RotateForward(QuaternionQuad(a.m_rotation),b.m_vTranslation.m_vComponents), a.m_vTranslation.m_vComponents);
        m_rotation.setMul(a.m_rotation, b.m_rotation);
        m_vScale.m_vComponents = _mm_mul_ps(a.m_vScale.m_vComponents, b.m_vScale.m_vComponents);
    }
__forceinline void hkQsTransform::setMulContext(const hkQsTransform& a, const hkQsTransform& b)
    {
        m_vTranslation.m_vComponents = _mm_add_ps(ContextForward(QuaternionQuad(a.m_rotation),b.m_vTranslation.m_vComponents), a.m_vTranslation.m_vComponents);
        m_rotation.setMul(a.m_rotation, b.m_rotation);
        m_vScale.m_vComponents = _mm_mul_ps(a.m_vScale.m_vComponents, b.m_vScale.m_vComponents);
    }
__forceinline void hkQsTransform::setRelativeContext(const hkQsTransform& a, const hkQsTransform& b)
    {
        hkQsTransform inv;
        inv.SetConjugate(a);
        setMulInitial(inv, b);
    }
__forceinline void hkQsTransform::setMulInitial(const hkQsTransform& a, const hkQsTransform& b)
    {
        m_vTranslation.m_vComponents = _mm_add_ps(InitialForward(a.m_rotation,b.m_vTranslation), a.m_vTranslation.m_vComponents);
        m_rotation.setMul(a.m_rotation, b.m_rotation);
        m_vScale.m_vComponents = _mm_mul_ps(a.m_vScale.m_vComponents, b.m_vScale.m_vComponents);
    }
__forceinline void hkQsTransform::setMulFirst(const hkQsTransform& a, const hkQsTransform& b)
    {
        m_vTranslation.m_vComponents = _mm_add_ps(FirstRestoreForward(b.m_vTranslation.m_vComponents,QuaternionQuad(a.m_rotation)), a.m_vTranslation.m_vComponents);
        m_rotation.setMul(a.m_rotation, b.m_rotation);
        m_vScale.m_vComponents = _mm_mul_ps(a.m_vScale.m_vComponents, b.m_vScale.m_vComponents);
    }
__forceinline void hkQsTransform::SetMulInverse(const hkQsTransform& a, const hkQsTransform& b)
    {
        hkQsTransform inv;
        inv.SetConjugate(a);
        SetProduct(inv, b);
    }
__forceinline void hkQsTransform::operator=(const hkQsTransform& t) { m_vTranslation=t.m_vTranslation; m_rotation=t.m_rotation; m_vScale=t.m_vScale; }

template<class T> struct IkArray {
 T* data; int size; int capacity;
 __forceinline T& operator[](const int& i) { return data[i]; }
 __forceinline const T& operator[](const int& i) const { return data[i]; }
};


// The skeleton's hkArray members read as a plain {data, size, capacity} record: through the shared hkArray's
// hkArrayBase subobject, FUN_00cdbae0's SSE register colours flip (12 bytes); the record reads match.
template<class T> struct SkeletonArrayRecord { T* m_data; int m_iElementCount; int m_iCapacityState; };
template<class T, class A> __forceinline const SkeletonArrayRecord<T>& SkeletonArrayView(const hkArray<T, A>& a) { return reinterpret_cast<const SkeletonArrayRecord<T>&>(a); }
struct SkeletonPoseData
{
    const hkaSkeleton* m_pSkeleton;
    IkArray<hkQsTransform> m_pLocalPose;
    hkQsTransform* m_pModelPose;
    int m_modelPoseSize;
    int m_modelPoseCap;
    unsigned int* m_pBoneFlags;
    int m_boneFlagsSize;
    int m_boneFlagsCap;
    bool m_bPoseFlag;
    bool m_bPoseInitialized;

    const hkQsTransform& hkaPose_calculateBoneModelSpace(int boneIdx);
    hkQsTransform& accessBoneModelSpace(int boneIdx, int propagate);

    __forceinline const hkQsTransform& getBoneModelSpace(int boneIdx)
    {
        if ((m_pBoneFlags[boneIdx] & 2) == 0)
        {
            return m_pModelPose[boneIdx];
        }
        return hkaPose_calculateBoneModelSpace(boneIdx);
    }

    __forceinline const hkQsTransform& getBoneLocalSpace(int boneIdx, bool externalRootCopy=false)
    {
        if (m_pBoneFlags[boneIdx] & 1)
        {
            const hkQsTransform& modelFromBone=m_pModelPose[boneIdx];
            const short parentIdx=SkeletonArrayView(m_pSkeleton->m_kParentIndices).m_data[boneIdx];
            if (parentIdx != -1) m_pLocalPose[boneIdx].SetMulInverse(getBoneModelSpace(parentIdx), modelFromBone);
            else { if(externalRootCopy) m_pLocalPose[boneIdx].CopyFromFloatArray(modelFromBone); else m_pLocalPose[boneIdx]=modelFromBone; }
            m_pBoneFlags[boneIdx] &= ~1;
        }
        return m_pLocalPose[boneIdx];
    }

    __forceinline void makeAllChildrenLocalSpace(int boneIdx, bool externalRootCopy=false)
    {
        const int numBones = SkeletonArrayView(m_pSkeleton->m_kBones).m_iElementCount;
        m_pBoneFlags[boneIdx] |= 4;
        for (int i = boneIdx + 1; i < numBones; ++i)
        {
            const short parentIdx = SkeletonArrayView(m_pSkeleton->m_kParentIndices).m_data[i];
            if (parentIdx == -1)
            {
                continue;
            }
            if ((m_pBoneFlags[parentIdx] & 4) == 0)
            {
                continue;
            }
            {
                getBoneLocalSpace(i,externalRootCopy);
                m_pBoneFlags[i] |= 4;
                m_bPoseFlag = false;
            }
        }
        for (int i = boneIdx + 1; i < numBones; ++i)
        {
            unsigned int& f = m_pBoneFlags[i];
            if (f & 4)
            {
                f = (f & ~4) | 2;
            }
        }
    }

    __forceinline void setBoneModelSpace(int boneIdx, const hkQsTransform& t, bool externalRootCopy=false)
    {
        makeAllChildrenLocalSpace(boneIdx,externalRootCopy);
        m_pModelPose[boneIdx] = t;
        m_pBoneFlags[boneIdx] = 1;
        m_bPoseInitialized = false;
    }
};

template<class T> struct ModelArray {T* data;int size;int capacity;
 __forceinline T& operator[](int i) {return data[i];}
 __forceinline const T& operator[](int i) const {return data[i];}};
struct hkaPoseTyped
{
    const hkaSkeleton* m_pSkeleton;
    ModelArray<hkQsTransform> m_pLocalPose;
    ModelArray<hkQsTransform> m_pModelPose;
    unsigned int* m_pBoneFlags;
    int m_boneFlagsSize;
    int m_boneFlagsCap;
    bool m_bPoseFlag;
    bool m_bPoseInitialized;

    __forceinline const hkQsTransform& getBoneModelSpace(int boneIdx)
    {
        if ((m_pBoneFlags[boneIdx] & 2) == 0)
        {
            return m_pModelPose[boneIdx];
        }
        return ((SkeletonPoseData*)this)->hkaPose_calculateBoneModelSpace(boneIdx);
    }

    __forceinline const hkQsTransform& getBoneLocalSpace(int boneIdx, bool externalRootCopy=false)
    {
        if (m_pBoneFlags[boneIdx] & 1)
        {
            const hkQsTransform& modelFromBone=m_pModelPose[boneIdx];
            const short parentIdx=SkeletonArrayView(m_pSkeleton->m_kParentIndices).m_data[boneIdx];
            if (parentIdx != -1) m_pLocalPose[boneIdx].SetMulInverse(getBoneModelSpace(parentIdx), modelFromBone);
            else { if(externalRootCopy) m_pLocalPose[boneIdx].CopyFromFloatArray(modelFromBone); else m_pLocalPose[boneIdx]=modelFromBone; }
            m_pBoneFlags[boneIdx] &= ~1;
        }
        return m_pLocalPose[boneIdx];
    }

    __forceinline void makeAllChildrenLocalSpace(int boneIdx, bool externalRootCopy=false)
    {
        const int numBones = SkeletonArrayView(m_pSkeleton->m_kBones).m_iElementCount;
        m_pBoneFlags[boneIdx] |= 4;
        for (int i = boneIdx + 1; i < numBones; ++i)
        {
            const short parentIdx = SkeletonArrayView(m_pSkeleton->m_kParentIndices).m_data[i];
            if (parentIdx == -1)
            {
                continue;
            }
            if ((m_pBoneFlags[parentIdx] & 4) == 0)
            {
                continue;
            }
            {
                getBoneLocalSpace(i,externalRootCopy);
                m_pBoneFlags[i] |= 4;
                m_bPoseFlag = false;
            }
        }
        for (int i = boneIdx + 1; i < numBones; ++i)
        {
            unsigned int& f = m_pBoneFlags[i];
            if (f & 4)
            {
                f = (f & ~4) | 2;
            }
        }
    }

    __forceinline void setBoneModelSpace(int boneIdx, const hkQsTransform& t, bool externalRootCopy=false)
    {
        makeAllChildrenLocalSpace(boneIdx,externalRootCopy);
        m_pModelPose[boneIdx] = t;
        m_pBoneFlags[boneIdx] = 1;
        m_bPoseInitialized = false;
    }
};

struct hkaTwoJointsIkSetup
{
    short m_sFirstJointIndex;
    short m_sSecondJointIndex;
    short m_sThirdJointIndex;
    short m_sFourthJointIndex;
    short m_sFifthJointIndex;
    short unk0A;
    int unk0C;
    IkVector4 m_vHingeAxisLS;
    float m_fFirstIkParameter;
    float m_fSecondIkParameter;
    float m_fThirdIkParameter;
    float m_fFourthIkParameter;
    float m_fFifthIkParameter;
    int unk34;
    int unk38;
    int unk3C;
    IkVector4 m_vFirstIkVector;
    hkQuaternion m_qFirstIkRotation;
    IkVector4 m_vSecondIkVector;
    hkQuaternion m_qSecondIkRotation;
    bool m_bFirstIkOption;
    bool m_bSecondIkOption;
};

extern "C" double __cdecl acos(double);
extern "C" double __cdecl fabs(double);
extern "C" const float DAT_0102b3c8;
__declspec(noinline) float __cdecl ClampedAcos(float x)
{
    if ((float)fabs(x)>=1.0f) return x<0.0f ? DAT_0102b3c8 : 0.0f;
    return (float)acos(x);
}
// @fnv 0x00cdbae0
// src: XBOX_PDB 0x00cdbae0
extern "C" hkBool __cdecl hkaTwoJointsIkSolver_solve(const hkaTwoJointsIkSetup& setup, SkeletonPoseData& pose)
{
IkVector4 secondTwist;
    {
        hkMonitorStream_raw* pBuf;
        pBuf = (hkMonitorStream_raw*)TlsGetValue(DAT_0126835c);
        if (pBuf->m_end < pBuf->m_capacityMinus16)
        {
            hkMonitorStream_raw::TimerCommand* firstMSRW;
            firstMSRW = (hkMonitorStream_raw::TimerCommand*)pBuf->m_end;
            firstMSRW->m_commandAndMonitor = "LtTWOJOINTSOLVER";
            firstMSRW[1].m_commandAndMonitor = "StINIT";
            firstMSRW->setTime();
            pBuf->m_end = (hkMonitorStream_raw::TimerCommand*)((char*)firstMSRW + 16);
        }
    }

    if (!setup.m_bFirstIkOption && !setup.m_bSecondIkOption) return hkBool(true);
    {
        hkQsTransform val;
        val.setIdentity();
        hkQsTransform secondPos;
        secondPos.setIdentity();

        if (setup.m_sFourthJointIndex >= 0)
        {
            const hkQsTransform& oldRot = pose.getBoneModelSpace(setup.m_sFourthJointIndex);
            const hkQsTransform& twistMS = pose.getBoneModelSpace(setup.m_sFirstJointIndex);
            val.setRelativeContext(twistMS,oldRot);
        }

        if (setup.m_sFifthJointIndex >= 0)
        {
            const hkQsTransform& oldRot = pose.getBoneModelSpace(setup.m_sFifthJointIndex);
            const hkQsTransform& twistMS = pose.getBoneModelSpace(setup.m_sSecondJointIndex);
            secondPos.setRelativeContext(twistMS,oldRot);
        }

        if (setup.m_bFirstIkOption)
        {
            IkVector4 ptr;
            {
                {
                    hkMonitorStream_raw* pBuf = (hkMonitorStream_raw*)TlsGetValue(DAT_0126835c);
                    if (pBuf->m_end < pBuf->m_capacityMinus16)
                    {
                        hkMonitorStream_raw::TimerCommand* firstMSRW;
                        firstMSRW = (hkMonitorStream_raw::TimerCommand*)pBuf->m_end;
                        firstMSRW->m_commandAndMonitor = "StFIXLENGTH";
                        firstMSRW->setTime();
                        pBuf->m_end = (hkMonitorStream_raw::TimerCommand*)(1 + firstMSRW);
                    }
                }

                const hkQsTransform& x = pose.getBoneModelSpace(setup.m_sFirstJointIndex);
                const hkQsTransform& currentCos = pose.getBoneModelSpace(setup.m_sSecondJointIndex);
                const hkQsTransform& endPos2 = pose.getBoneModelSpace(setup.m_sThirdJointIndex);

                if (0 == setup.m_bSecondIkOption)
                {
                    ptr = setup.m_vFirstIkVector;
                    secondTwist.FUN_00c7f7a0(endPos2, setup.m_vSecondIkVector);
                }
                else
                {
                    ::LocalM128 q = RotatedInverseDir(QuaternionQuad(setup.m_qSecondIkRotation), setup.m_vSecondIkVector.m_vComponents);
                    q = TargetRotation(QuaternionQuad(setup.m_qFirstIkRotation), q);
                    ptr.m_vComponents = _mm_sub_ps(setup.m_vFirstIkVector.m_vComponents, q);
                    secondTwist.m_vComponents = endPos2.m_vTranslation.m_vComponents;
                }

                float cosTheta;
                float a;
                {
                    const ::LocalM128 h2 = currentCos.m_vTranslation.m_vComponents;
                    const ::LocalM128 endPosMS = x.m_vTranslation.m_vComponents;
                    IkVector4 firstToSecond; firstToSecond.m_vComponents = _mm_sub_ps(h2, endPosMS);
                    IkVector4 secondToEnd; secondToEnd.m_vComponents = _mm_sub_ps(secondTwist.m_vComponents, h2);
                    IkVector4 firstToTarget; firstToTarget.m_vComponents = _mm_sub_ps(ptr.m_vComponents, endPosMS);

                    hkQuaternion firstPos;CopyIkRotation(firstPos,pose.getBoneModelSpace(setup.m_sSecondJointIndex).m_rotation);
                    firstPos.normalize_005611c0();
                    const ::LocalM128 hingeAxis = HingeRotation(QuaternionQuad(firstPos),setup.m_vHingeAxisLS.m_vComponents);

                    
                    const IkDotResult secondMSDot={Dot3(firstToSecond.m_vComponents,hingeAxis)}; const float secondMS=ToReal(secondMSDot.m_vValue);
                    const ::LocalM128 h1 = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&secondMS),_mm_load_ss(&secondMS),0), hingeAxis);
                    IkVector4 f2sProj; f2sProj.m_vComponents = _mm_sub_ps(firstToSecond.m_vComponents, h1);
                    const IkDotResult pRecDot={Dot3(secondToEnd.m_vComponents,hingeAxis)}; const float pRec=ToReal(pRecDot.m_vValue);
                    const ::LocalM128 firstMS2 = _mm_mul_ps(_mm_set_ps1(pRec), hingeAxis);
                    IkVector4 s2eProj; s2eProj.m_vComponents = _mm_sub_ps(secondToEnd.m_vComponents, firstMS2);
                    const ::LocalM128 endTargetMS = _mm_sub_ps(h1, firstMS2);
                    float oldRot2;
                    const ::LocalM128 squaredOffset=_mm_mul_ps(endTargetMS,endTargetMS);
                     
                     const float minLimit=setup.m_fSecondIkParameter;
const ::LocalM128 sy=_mm_shuffle_ps(squaredOffset,squaredOffset,0x55);
                    const ::LocalM128 sz=_mm_shuffle_ps(squaredOffset,squaredOffset,0xaa);
                    const ::LocalM128 xy=_mm_add_ss(sy,squaredOffset);
                    (_mm_store_ss)(&oldRot2,_mm_add_ss(sz,xy));

                    const float hingeLenSq = ToReal(Dot3(firstToTarget.m_vComponents, firstToTarget.m_vComponents)) - oldRot2;
                    const float hingeAxis2 = ToReal(Dot3(f2sProj.m_vComponents, f2sProj.m_vComponents));
                    const float secondMSRW = ToReal(Dot3(s2eProj.m_vComponents, s2eProj.m_vComponents));
                    cosTheta = Max2(setup.m_fFirstIkParameter, Min2((float)((hingeLenSq - hingeAxis2 - secondMSRW) / (-2.0 * Sqrt(hingeAxis2) * Sqrt(secondMSRW))),minLimit));

                    const ::LocalM128 y = _mm_xor_ps(Normalized3(f2sProj.m_vComponents), DAT_010c4c00);
                    const ::LocalM128 d1 = Normalized3(s2eProj.m_vComponents);
                    (_mm_store_ss)(&a, Dot3(y, d1));
                }
                {
                    hkQsTransform& secondRot = pose.accessBoneModelSpace(setup.m_sSecondJointIndex, 1);
                    IkVector4 pForm;
                    const hkQuaternion fromDir = secondRot.m_rotation; 
                    pForm.m_vComponents = Normalized3Approx(RotatedDir(QuaternionQuad(fromDir), setup.m_vHingeAxisLS.m_vComponents));

                    float firstMS;
                    firstMS = ClampedAcos(cosTheta) - ClampedAcos(a);
                    firstMS = setup.m_fFourthIkParameter * firstMS;
                    hkQuaternion s2eN;
                    s2eN.hkQuaternion_setAxisAngle(pForm, firstMS);
                    secondRot.m_rotation.setMul(s2eN, fromDir);
                    secondRot.m_rotation.normalize_005611c0();
                }
            }

                {
                    hkMonitorStream_raw* pBuf = (hkMonitorStream_raw*)TlsGetValue(DAT_0126835c);
                    if (pBuf->m_end < pBuf->m_capacityMinus16)
                    {
                        hkMonitorStream_raw::TimerCommand* firstMSRW;
                        firstMSRW = (hkMonitorStream_raw::TimerCommand*)pBuf->m_end;
                        firstMSRW->m_commandAndMonitor = "StFIXDIRECTION";
                        firstMSRW->setTime();
                        pBuf->m_end = (hkMonitorStream_raw::TimerCommand*)(1 + firstMSRW);
                    }
                }
            {

                IkVector4 endMS;
                const hkQsTransform& b = pose.getBoneModelSpace(setup.m_sFirstJointIndex);
                if (setup.m_bSecondIkOption)
                {
                    endMS.m_vComponents = pose.getBoneModelSpace(setup.m_sThirdJointIndex).m_vTranslation.m_vComponents;
                }
                else
                {
                    endMS.FUN_00c7f7a0(pose.getBoneModelSpace(setup.m_sThirdJointIndex), setup.m_vSecondIkVector);
                }

IkVector4 jointMS; jointMS.m_vComponents = Normalized3(_mm_sub_ps(endMS.m_vComponents, b.m_vTranslation.m_vComponents));
hkQuaternion kIter;
{ IkVector4 desired; desired.m_vComponents = Normalized3(_mm_sub_ps(ptr.m_vComponents, b.m_vTranslation.m_vComponents));
kIter.UpdateState_00cdb910(setup.m_fThirdIkParameter, jointMS, desired); }

                hkQsTransform& firstTwist = pose.accessBoneModelSpace(setup.m_sFirstJointIndex, 1);
                const hkQuaternion d2 = firstTwist.m_rotation;
                firstTwist.m_rotation.setMul(kIter, d2);
                firstTwist.m_rotation.normalize_005611c0();
            }
            }

        if (setup.m_bSecondIkOption)
        {
            hkQuaternion hd;
            hd.setMulInverse(setup.m_qFirstIkRotation, setup.m_qSecondIkRotation);
            const hkQsTransform& endPos2 = pose.getBoneModelSpace(setup.m_sThirdJointIndex);
            hkQsTransform j;
            j = endPos2;
            j.m_rotation.D3D_ComputeClearColor(endPos2.m_rotation, hd, setup.m_fFifthIkParameter);
            pose.setBoneModelSpace(setup.m_sThirdJointIndex, j);
        }

        if (setup.m_sFourthJointIndex >= 0)
        {
            hkQsTransform oldRot;
            oldRot.setMulFirst(pose.getBoneModelSpace(setup.m_sFirstJointIndex),val);
            ((hkaPoseTyped&)pose).setBoneModelSpace(setup.m_sFourthJointIndex, oldRot);
        }

        if (setup.m_sFifthJointIndex >= 0)
        {
            hkQsTransform oldRot;
            oldRot.setMulContext(pose.getBoneModelSpace(setup.m_sSecondJointIndex), secondPos);
            pose.setBoneModelSpace(setup.m_sFifthJointIndex, oldRot,true);
        }
    }

    {
        hkMonitorStream_raw* pBuf;
        pBuf = (hkMonitorStream_raw*)TlsGetValue(DAT_0126835c);
        if (pBuf->m_end < pBuf->m_capacityMinus16)
        {
            hkMonitorStream_raw::TimerCommand* firstMSRW;
            firstMSRW = (hkMonitorStream_raw::TimerCommand*)pBuf->m_end;
            firstMSRW->m_commandAndMonitor = "lt";
            firstMSRW->setTime();
            pBuf->m_end = firstMSRW + 1;
        }
    }
    return hkBool(true);
}
