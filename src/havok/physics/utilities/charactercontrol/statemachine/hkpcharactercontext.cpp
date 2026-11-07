#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form

// src/havok/physics/utilities/charactercontrol/statemachine/hkpcharactercontext.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/charactercontrol/statemachine/hkpcharactercontext.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpCharacterContext.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkVector4.h"

extern int DAT_0102e388;
extern int DAT_010c8198;
// These helpers have no member declarations in the shared context header.
// Keep the original this pointer in ECX and stack arguments in their original slots.
// @fnv 0x00ca95e0
// src: GUESS 0x00ca95e0 (confidence: low)
__declspec(noinline) void __fastcall hkpCharacterContext_UpdateFields_00ca95e0(hkpCharacterContext* context)
{
    *reinterpret_cast<int**>(context) = &DAT_010c8198;
    static_cast<hkReferencedObject*>(context->unk0C)->removeReference();
    *reinterpret_cast<int**>(context) = &DAT_0102e388;
}

// @fnv 0x00ca9670
// src: HAVOK_LIB 0x00ca9670
void __fastcall hkpCharacterContext_setFilterParameters(hkpCharacterContext* context, void*, float a, float b, float c)
{
    context->unk24 = a;
    context->unk20 = b;
    context->unk1C = c;
}

// @fnv 0x00ca9660
// src: GUESS 0x00ca9660 (confidence: low)
void __fastcall hkpCharacterContext_SetUnk18_00ca9660(hkpCharacterContext* context, void*, unsigned char value)
{
    context->unk18 = value;
}

// @fnv 0x00ca9690
// src: GUESS 0x00ca9690 (confidence: low)
void __fastcall hkpCharacterContext_UpdateState_00ca9690(hkpCharacterContext* context, void*, int value)
{
    context->unk08 = value;
}

// @fnv 0x00ca9580
hkpCharacterContext* hkpCharacterContext::Initialize(void* arg0, int arg1)
{
    m_sReferenceCount = 1;
    unk0C = arg0;
    *reinterpret_cast<int**>(this) = &DAT_010c8198;
    unk10 = arg1;
    unk14 = arg1;
    unk08 = 0;
    unk18 = 1;

    float& f20 = unk20;
    f20 = 20.0f;
    unk1C = 625.0f;
    unk24 = 1.0f;
    static_cast<hkReferencedObject*>(unk0C)->addReference();

    return this;
}

// @fnv 0x00ca9600
// src: XBOX_PDB 0x00ca9600
int __fastcall hkpCharacterContext_getState(hkpCharacterContext* context)
{
    return context->unk10;
}

struct PhysicsDataBlock;
struct Vector4Data;

// Transition-call view: 0x00ca9610 uses slots 0x10/0x14; this omits the real state's hkReferencedObject base.
class CharacterTransitionDispatch
{
  public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void enterState(hkpCharacterContext& kContext, int iPrevState, const PhysicsDataBlock& kInput,
                            Vector4Data& kOutput) throw();
    virtual void leaveState(hkpCharacterContext& kContext, int iNextState, const PhysicsDataBlock& kInput,
                            Vector4Data& kOutput) throw();
};

// Lookup-call view: 0x00cbc510 reads states at +0x08 in the owning unit; this declares no object layout.
class CharacterStateLookup
{
  public:
    CharacterTransitionDispatch* GetIndexedValue_00cbc510(int iState) const throw();
};

// Leaves the current state, stores the new state id, then enters the new state via the state manager.
// @fnv 0x00ca9610
void __fastcall SetState(hkpCharacterContext* context, void*, int iState,
                         const PhysicsDataBlock& kInput, Vector4Data& kOutput)
{
    int iPrevState = context->unk10;
    static_cast<const CharacterStateLookup*>(context->unk0C)
        ->GetIndexedValue_00cbc510(context->unk10)->leaveState(*context, iState, kInput, kOutput);
    context->unk10 = iState;
    static_cast<const CharacterStateLookup*>(context->unk0C)
        ->GetIndexedValue_00cbc510(iState)->enterState(*context, iPrevState, kInput, kOutput);
}

struct FnvCpu_FUN_00ca9810_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00ca9810_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00ca9810_CpuAllocator* allocator;
};
FnvCpu_FUN_00ca9810_CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
// Calls FUN_00ca95e0, then if bit 0 of flags is set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00ca9810
hkpCharacterContext* __fastcall Destroy(hkpCharacterContext* context, void*, unsigned int flags)
{
    hkpCharacterContext_UpdateFields_00ca95e0(context);
    if (flags & 1)
    {
        FnvCpu_FUN_00ca9810_CpuAllocatorHolder* pAllocatorHolder = hkMemoryRouter_getInstance();
        pAllocatorHolder->allocator->Invoke(context, context->m_usMemSizeAndFlags);
    }
    return context;
}

inline hkSimdReal::hkSimdReal()
{}

inline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x)
{}

inline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}

inline float hkSimdReal::getReal() const
{
    float r;
    _mm_store_ss(&r, m_vValue);
    return r;
}

inline hkSimdReal::operator float() const
{
    return getReal();
}

typedef const hkSimdReal& hkSimdRealParameter;


inline hkVector4::hkVector4(__m128 q) : m_vComponents(q)
{}

inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}

inline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

inline void hkVector4::mul4(hkSimdRealParameter r)
{
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), m_vComponents);
}

inline void hkVector4::addMul4(hkSimdRealParameter r, const hkVector4& a)
{
    m_vComponents =
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), a.m_vComponents), m_vComponents);
}

inline hkSimdReal hkVector4::length3() const
{
    __m128 mul = _mm_mul_ps(m_vComponents, m_vComponents);
    __m128 y = _mm_shuffle_ps(mul, mul, 0x55);
    __m128 z = _mm_shuffle_ps(mul, mul, 0xaa);
    __m128 sum = _mm_add_ss(z, _mm_add_ss(y, mul));
    return _mm_sqrt_ss(sum);
}

struct PhysicsDataBlock
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
    float m_pStepInfo;
    float m_fSecondScalar;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    hkVector4 m_fVelocity;
};

struct Vector4Data
{
    hkVector4 m_fVelocity;
};

struct State
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void change(hkpCharacterContext* ctx, const PhysicsDataBlock& input, Vector4Data& output);
    virtual void update(hkpCharacterContext* ctx, const PhysicsDataBlock& input, Vector4Data& output);
};

struct StateManager
{
    State* GetReferenceTimeStep(int state);
};

// @fnv 0x00ca96a0
// src: GUESS 0x00ca96a0 (confidence: low)
void __fastcall hkpCharacterContext_UpdateFields_00ca96a0(hkpCharacterContext* context, void*, const PhysicsDataBlock& input, Vector4Data& output)
{
    output.m_fVelocity = input.m_fVelocity;

    static_cast<StateManager*>(context->unk0C)->GetReferenceTimeStep(context->unk10)->update(context, input, output);

    if (context->unk10 == context->unk14)
    {
        static_cast<StateManager*>(context->unk0C)->GetReferenceTimeStep(context->unk10)->change(context, input, output);
    }

    context->unk14 = context->unk10;

    if (context->unk18)
    {
        float length = output.m_fVelocity.length3();
        if (length > context->unk20)
        {
            float fClampScale = context->unk20 / length;
            output.m_fVelocity.mul4(hkSimdReal(fClampScale));
        }

        float grav = input.m_fSecondScalar;
        hkVector4 vDelta;
        vDelta.setSub4(output.m_fVelocity, input.m_fVelocity);
        vDelta.mul4(hkSimdReal(grav));
        float fDeltaLength = vDelta.length3();
        float fDeltaRatio = fDeltaLength / context->unk1C;
        output.m_fVelocity = input.m_fVelocity;

        float fBlendFactor;
        if (fDeltaRatio > 1.0f && context->unk10 != 1)
        {
            fBlendFactor = (input.m_pStepInfo * context->unk24) / fDeltaRatio;
        }
        else
        {
            fBlendFactor = input.m_pStepInfo * context->unk24;
        }

        output.m_fVelocity.addMul4(fBlendFactor, vDelta);
    }
}
