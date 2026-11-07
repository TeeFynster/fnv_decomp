#include <string.h>
#include "../../../include/BSTreeNode.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/BGSBodyPart.h"
#include "../../../include/NiRTTI.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiObject.h"
#include "../../../include/bhkCapsuleShape.h"
#include "../../../include/bhkCollisionObject.h"
// bhkLimitedHingeVector_bstreenode_o2_nood_variant_rtm_variant: local type (was include/bhkLimitedHingeVector.h, which had no evidence of one real class); its methods are 0x004b4db0 bhkVector4::operator=
class bhkLimitedHingeVector_bstreenode_o2_nood_variant_rtm_variant
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
#include "../../../include/bhkTransformShape.h"
// src/fallout_shared/speedtree/bstreenode_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/speedtree/bstreenode_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/fallout_shared/speedtree/bstreenode_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy /GF (unit src/fallout_shared/speedtree/bstreenode.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/fallout_shared/speedtree/bstreenode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/speedtree/bstreenode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00622430_shell
{
    unsigned int __thiscall bhkTransformShape_GetCInfoSize();
};
struct NiRTTI;
extern NiRTTI g_011d5e70;
struct NiCullingProcess;
extern "C" unsigned char __cdecl BSTreeManager_GetTreesEnabled();
struct FUN_00c6c290_holder
{
    void FUN_00c6c290();
};
struct FUN_0066d410_shell : public FUN_00c6c290_holder
{
    void ForwardCall_0066d410();
};
extern const NiRTTI g_012683d0;
struct FUN_0066d430_shell
{
    const NiRTTI* GetRTTI() const;
};
void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);
struct FUN_0066d440_shell
{
    void ForwardCall_0066d470();
    void* FUN_0066d440(unsigned int flags);
};
struct FUN_0066d470_shell
{
    void ForwardCall_0066d410();
    void ForwardCall_0066d470();
};
struct FUN_0066d510_shell
{
    const void* bhkMultiSphereShape_GetRTTI();
};
extern const void* g_012683e0;
struct FUN_0066d520_shell
{
    void FUN_00cb78b0();
    void* FUN_0066d520(unsigned int flags);
};
void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);
struct GlobalObjectO2_00a7b610
{
};
GlobalObjectO2_00a7b610 g_012681b4;
struct FUN_0066d610_shell
{
    GlobalObjectO2_00a7b610* GetGlobalObject();
};
struct FUN_0066da50_t
{
    void FUN_0066da50();
};
struct FUN_0066d7a0_shell
{
    int m0;
    FUN_0066da50_t m1;
    void RunInner();
};
struct Flt
{
    operator unsigned int() const;
};
struct NiTriBasedGeom;
extern const char* const g_012683d0_arg1;
struct FUN_0066d400_shell
{
    const char* const* GetArg1Ptr();
};
struct FUN_0066d3d0_shell
{
    void __thiscall bhkPCollisionObject_bhkPCollisionObject(void*);
};
extern int DAT_01066acc;
struct FUN_0066d3a0_shell
{
    void* __thiscall bhkSPCollisionObject_bhkSPCollisionObject(void*);
};
extern "C" void __cdecl hkActionCinfo_hkActionCinfo();
extern "C" void __cdecl FUN_0056e270();
struct FUN_0056e120_shell
{
    void __thiscall bhkTransform_setIdentity();
};
struct FUN_0066d550_shell
{
    void* Initialize();
};
struct FUN_00c8bed0_holder
{
    void __thiscall FUN_00c8bed0();
};
void __cdecl _delete(void*, unsigned int);
struct FUN_0066d740_owner
{
    void __thiscall FUN_00caacf0();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
void __cdecl _delete(void* p, unsigned int size);
struct FUN_0056e900_shell
{
    void __thiscall StepAndReturnThis();
};
struct FUN_006299a0_shell
{
    void __thiscall ProcessAndReturnValue_006299a0();
};
struct FUN_0066d770_shell
{
    void* __thiscall hkMultiSphereShapeCinfo_hkMultiSphereShapeCinfo();
};
struct FUN_0094db80_shell
{
    void NiAlphaProperty_SetTestRef(unsigned char);
};
struct FUN_0066bf80_data
{
    float time;
};
struct NiCamera;
extern double gModifierZero;
extern "C" unsigned int __cdecl BSTreeManager_GetCamera();
extern bool __cdecl NodeInFrustum(NiAVObject*, NiCamera*);
#include "../../../include/MEM_CONTEXT.h"
class NiTexture;
struct bhkWorldObject;
extern char g_01268444_arg1;
NiObject* __cdecl NiObject_DynamicCast(const NiRTTI* apRTTI, NiObject* apObject);
struct FUN_0066d7c0_cls
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
    virtual BGSBodyPart* GetPart();
    NiObject* FUN_0066d7c0();
};
struct ItemList
{
    unsigned short GetCount();
};
struct SmartPtr
{
    void* m_pObject;
    void* Get();
};
struct S_0066ba30_Str
{
    char* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    S_0066ba30_Str();
    ~S_0066ba30_Str();
};
struct S_0066ba30_Model
{
    unsigned short FUN_006699d0();
};
struct S_0066ba30_Obj;
template <class T> struct S_0066ba30_Ptr
{
    T* m_pObject;
    operator T*() const;
    T* operator->() const;
    S_0066ba30_Ptr& operator=(T* p);
};
struct VisNodeAlpha70
{
    void Method0094db80(unsigned char aAlpha);
};
extern char DAT_01066c5c;
extern unsigned int DAT_012683dc;
struct FUN_0066d490_base
{
    FUN_0066d490_base();
    ~FUN_0066d490_base();
};
struct FUN_0066d490_cls : FUN_0066d490_base
{
    void* m_vptr;
    void bhkMultiSphereShape_Init(unsigned int a1);
    FUN_0066d490_cls(unsigned int a1);
};
extern char DAT_01066d44;
extern unsigned int DAT_012681b0;
struct FUN_0066d590_base
{
    FUN_0066d590_base();
    ~FUN_0066d590_base();
};
struct FUN_0066d590_cls : FUN_0066d590_base
{
    void* m_vptr;
    void bhkTransformShape_Init(unsigned int a1);
    FUN_0066d590_cls(unsigned int a1);
};
extern "C" int __cdecl BSsprintf(char* text, unsigned size, const char* fmt, ...);
extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* s);
struct S_0066d880_List
{
    void FUN_0096a610(char** item);
};
struct S_0066d880_Obj
{
    unsigned char CombatProcedure_GetFinished();
    int FUN_008d6f30();
};
struct S_0066d880_Holder
{
    S_0066d880_Obj* Modelloader_GetReferencedThis();
};
#include <xmmintrin.h>
struct Inner
{
    unsigned char unk00[0x14];
    void* m14;
    unsigned char unk18[0x18];
    __m128 rows[4];
};
struct Param
{
    unsigned char unk00[4];
    void* m4;
    unsigned char unk08[8];
    bhkLimitedHingeVector_bstreenode_o2_nood_variant_rtm_variant vecs[4];
};
extern const __m128 g_01268370[4];
struct MyObj
{
    unsigned char unk00[8];
    Inner* m8;
    void __thiscall bhkShape_CopyCinfo(void*);
    void __thiscall bhkTransformShape_CopyCinfo(void*);
};
struct Alloc
{
    virtual void v0();
    virtual void* Alloc_(unsigned int);
};
struct Holder
{
    int unk00, unk04, unk08, unk0c;
    Alloc* unk10;
};
struct AudioTlsState
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
struct Data8
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float unk20[4], unk30[4];
};
struct Output
{
    int unk00;
    float unk04;
    int unk08, unk0c;
    NiPoint3 unk10, unk20;
    int unk30;
    int unk34;
    int unk38;
};
struct FUN_00d22dc0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    int unk04;
    void* unk08;
    FUN_00d22dc0(const __m128&, const __m128&, float, int, int);
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
    static void* operator new(unsigned int n);
    static void operator delete(void*);
};
struct Obj
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
    virtual void Call(void*, void*, void*, const char*);
    int unk04;
    Data8* unk08;
    void bhkConvexShape_CopyCinfo(Output*);
    void bhkCapsuleShape_BuildDisplayGeometry(void*, void*);
};
extern unsigned int DAT_0126fd98;
extern float DAT_010c72bc;
extern float DAT_01267e30[];
Holder* __cdecl hkMemoryRouter_getInstance();
void* FUN_00d22dc0::operator new(unsigned int n)
{
    Holder* h = hkMemoryRouter_getInstance();
    Alloc* allocator = h->unk10;
    void* p = allocator->Alloc_(n);
    *(short*)((char*)p + 4) = (short)n;
    return p;
}
extern __declspec(thread) AudioTlsState tls;
struct TlsRestore
{
    int old;
    TlsRestore()
    {
        AudioTlsState* td = &tls;
        old = td->unk2b4;
        td->unk2b4 = 0x10;
    }
    ~TlsRestore()
    {
        tls.unk2b4 = old;
    }
};
struct SpawnedSource
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
};
struct SpawnedSourceOwner
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
    virtual void Apply(SpawnedSource* apSource);

    void bhkCapsuleShape_Init(__m128* apA, __m128* apB, float afT);
    void bhkCapsuleShape_Init_00cab820(SpawnedSource* apSource);
};
#include <xmmintrin.h>
#include <xmmintrin.h>
extern "C" unsigned long __readfsdword(unsigned long);

extern float DAT_01268170;
extern float DAT_01016248;
extern float DAT_01012054;
extern int DAT_01267b80;
extern int DAT_01267b84;
struct S00c880f0_ScalarC880
{
    __m128 r;
    S00c880f0_ScalarC880(float f) : r(_mm_load_ss(&f))
    {}
    __m128 splat() const
    {
        return _mm_shuffle_ps(r, r, 0);
    }
};
union S00c880f0_VecC880
{
    S00c880f0_VecC880& operator=(const S00c880f0_VecC880& o)
    {
        v = o.v;
        return *this;
    }
    __m128 v;
    struct
    {
        float x, y, z, w;
    };
    void sub(const S00c880f0_VecC880& o)
    {
        v = _mm_sub_ps(v, o.v);
    }
    void scale(const S00c880f0_ScalarC880& f)
    {
        v = _mm_mul_ps(f.splat(), v);
    }
    void plus(const S00c880f0_VecC880& o)
    {
        v = _mm_add_ps(v, o.v);
    }
};
inline void makePosition(S00c880f0_VecC880& result, const NiPoint3& p)
{
    result.x = p.x * DAT_01268170;
    result.y = p.y * DAT_01268170;
    result.z = p.z * DAT_01268170;
    result.w = 0.0f;
}

struct S00c880f0_Bounds
{
    S00c880f0_VecC880 min, max;
};
struct S00c880f0_Ifc
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18(S00c880f0_Bounds* out);
    void hkpAabbPhantom_setAabb(S00c880f0_Bounds* out);
};
struct S00c880f0_Node
{
    int unk00, unk04;
    S00c880f0_Ifc* m_08;
    void Object_DoNothing();
};
struct S00c880f0_Cls
{
    int unk00, unk04;
    NiAVObject* m_08;
    unsigned int m_0c;
    S00c880f0_Node* m_10;
    void bhkPCollisionObject_NitohkTransform();
};
struct S00c880f0_LockObj
{
    void BSSpinLock_Lock(int);
};
// @fnv 0x00c880f0
// src: XBOX_PDB 0x00c880f0
void S00c880f0_Cls::bhkPCollisionObject_NitohkTransform()
{
    NiAVObject* a = m_08;
    S00c880f0_Node* b = m_10;
    if (a)
    {
        a->UpdateWorldLoc();
        if (b)
        {
            S00c880f0_Ifc* c = b->m_08;
            if (c)
            {
                // Preserve the raw transform snapshot without invoking its copy constructor.
                float worldTransform[sizeof(NiTransform) / sizeof(float)];
                memcpy(worldTransform, &a->m_kWorld, sizeof(worldTransform));
                S00c880f0_VecC880 position;
                S00c880f0_Bounds out;
                c->v18(&out);
                out.max.sub(out.min);
                out.max.scale(S00c880f0_ScalarC880(0.5f));
                out.min = out.max;
                out.min.scale(S00c880f0_ScalarC880(-1.0f));
                makePosition(position, *reinterpret_cast<const NiPoint3*>(worldTransform + offsetof(NiTransform, m_Translate) / sizeof(float)));
                out.min.plus(position);
                out.max.plus(position);
                reinterpret_cast<S00c880f0_LockObj*>(&DAT_01267b80)->BSSpinLock_Lock(0);
                S00c880f0_Ifc* item = b->m_08;
                if (item)
                {
                    b->Object_DoNothing();
                    item->hkpAabbPhantom_setAabb(&out);
                    b->Object_DoNothing();
                }
                if (--DAT_01267b84 == 0)
                    DAT_01267b80 = 0;
            }
        }
    }
}
