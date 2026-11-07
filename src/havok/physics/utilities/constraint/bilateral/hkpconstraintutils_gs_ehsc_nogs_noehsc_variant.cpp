#include <xmmintrin.h>
typedef ::__m128 LocalM128;
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkReferencedObject.h"


// src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
typedef ::__m128 LocalM128;
struct BSAudio;
BSAudio* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}
struct Block5
{
    int unk00, unk04, unk08, unk0c, unk10;
};
struct Block5b
{
    int unk00;
    unsigned short unk04;
    unsigned char unk06;
    unsigned char unk07;
    int unk08, unk0c, unk10;
};
struct CloneDataBase : hkReferencedObject
{
    int unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    LocalM128 unk20, unk30, unk40, unk50, unk60, unk70;
};
struct CloneDataA : CloneDataBase
{
    Block5 unk80;
    Block5b unk94;
    Block5 unka8;
    CloneDataA* FUN_00d4f2a0();
    void hkpRagdollLimitsData_setConeLimitStabilization(hkBool flag);
};
struct CloneDataB : CloneDataBase
{
    Block5 unk80;
    CloneDataB* FUN_00d52fc0();
};
struct SourceDataHeader
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
};
struct SourceData : SourceDataHeader
{
    LocalM128 unk20, unk30, unk40, unk50, unk60, unk70, unk80;
};
struct SourceDataB : SourceData
{
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    Block5 unkc0;
};
struct SourceDataA : SourceData
{
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc,
        unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8;
    Block5 unkfc;
    Block5b unk110;
    Block5 unk124;
};
struct Instance;
struct Instance : hkReferencedObject
{
    int unk08;
    SourceData* unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    unsigned char unk1c;
    Instance* FUN_00cf3ea0(void* entityA, void* entityB, CloneDataBase* data, int priority);
};
inline void* hkAlloc(int size)
{
    hkReferencedObject* p = (hkReferencedObject*)audio()->heap().blockAlloc(size);
    p->m_usMemSizeAndFlags = (unsigned short)size;
    return p;
}
Instance* __cdecl CloneInstanceFromSource(Instance* src);
class FnvSink
{
  public:
    virtual void Slot0() throw();
    virtual void Slot1() throw();
    virtual void Slot2() throw();
    virtual void Write(int level, unsigned int hash, const char* msg, const char* file, int line) throw();
};
extern FnvSink* DAT_01268360;
class MsgWriter
{
  public:
    void Init(char* buf, unsigned int cap) throw();
    void Append(const char* s) throw();
    void Finish() throw();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};
class FnvInner
{
  public:
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0C() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1C() throw();
    virtual unsigned int GetKind() throw();

    char unk04[0x0c];
    LocalM128 m_20;
    LocalM128 m_30;
    char unk40[0x10];
    LocalM128 m_50;
    char unk60[0x30];
    LocalM128 m_90;
};
class FnvHolder
{
  public:
    char unk00[0x0c];
    FnvInner* m_0c;
};
int hkpConstraintUtils_getConstraintPivots(FnvHolder* a0, LocalM128* a1, LocalM128* a2);

struct Ent
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec;
    LocalM128 unkf0;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    LocalM128 unk120;
    int unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c;
    int unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c;
    int unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c;
    int unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    LocalM128 unk1b0;
    LocalM128 unk1c0;
    void hkpRigidBody_setPosition(LocalM128* v);
    void OnTrigger(int arg);
    void hkpRigidBody_setAngularVelocity(void* p);
};

struct FnvHolder2 : FnvHolder
{
    int unk10;
    Ent* unk14;
    Ent* unk18;
};

struct Conv
{
    LocalM128 m;
    void setTransformedPos_00c7f640(LocalM128* src, LocalM128* arg);
};

// Constraint pivots followed by their transformed positions.
struct WorkVectors
{
    LocalM128 va;
    LocalM128 vb;
    Conv cb;
    Conv ca;
};

extern "C"
{
using ::_mm_load_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_shuffle_ps;
using ::_mm_add_ss;
using ::_mm_set_ps1;
using ::_mm_store_ss;
}

extern "C"
{
    const LocalM128 DAT_010ec7f0 = {{1.0f, 1.0f, 1.0f, 1.0f}};
    const float DAT_010959f4 = 1e-6f;
}

// @fnv 0x00e5af80
// src: XBOX_PDB 0x00e5af80
bool* hkpConstraintUtils_checkAndFixConstraint(bool* out, FnvHolder2* h, float t, float t2)
{
    float d;
    WorkVectors v;
    Ent* a;
    Ent* b;

    if (hkpConstraintUtils_getConstraintPivots(h, &v.va, &v.vb) == 0)
    {
        {
            LocalM128 sq = _mm_mul_ps(v.va, v.va);
            LocalM128 lo = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
            LocalM128 hi = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), lo);
            _mm_store_ss(&d, hi);
        }
        if (d > DAT_010959f4)
        {
            char buf[0x200];
            MsgWriter w;
            w.Init(buf, 0x200);
            w.Append("Pivot of child rigid body (A) is expected to be aligned with the constraint at setup time.");
            DAT_01268360->Write(1, 0xabba5dffu, buf, ".\\Constraint\\Bilateral\\hkpConstraintUtils.cpp", 285);
            w.Finish();
        }
        b = h->unk18;
        a = h->unk14;
        v.cb.setTransformedPos_00c7f640(&b->unkf0, &v.vb);
        v.ca.setTransformedPos_00c7f640(&a->unkf0, &v.va);
        {
            LocalM128 cbv = v.cb.m;
            LocalM128 cav = v.ca.m;
            LocalM128 dd = _mm_sub_ps(cbv, cav);
            LocalM128 sq = _mm_mul_ps(dd, dd);
            LocalM128 lo = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
            LocalM128 hi = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), lo);
            _mm_store_ss(&d, hi);
        }
        if (d > t * t)
        {
            {
                LocalM128 t2v = _mm_set_ps1(t2);
                LocalM128 r = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, t2v), v.cb.m),
                                      _mm_mul_ps(_mm_load_ps(b->unk120.m128_f32), t2v));
                a->hkpRigidBody_setPosition(&r);
            }
            a->OnTrigger((int)&b->unk1b0);
            a->hkpRigidBody_setAngularVelocity(&b->unk1c0);
            *out = true;
            return out;
        }
    }
    *out = false;
    return out;
}
