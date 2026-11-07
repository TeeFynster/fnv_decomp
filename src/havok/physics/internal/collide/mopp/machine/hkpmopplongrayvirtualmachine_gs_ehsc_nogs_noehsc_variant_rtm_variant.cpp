#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// src/havok/physics/internal/collide/mopp/machine/hkpmopplongrayvirtualmachine_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/mopp/machine/hkpmopplongrayvirtualmachine_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/internal/collide/mopp/machine/hkpmopplongrayvirtualmachine_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/mopp/machine/hkpmopplongrayvirtualmachine.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/internal/collide/mopp/machine/hkpmopplongrayvirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmopplongrayvirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkVector4.h"
extern "C" void _ReadWriteBarrier(void);

__forceinline hkVector4::hkVector4(const hkVector4& src)
{
    reinterpret_cast<unsigned*>(this)[0] = reinterpret_cast<const unsigned*>(&src)[0];
    reinterpret_cast<unsigned*>(this)[1] = reinterpret_cast<const unsigned*>(&src)[1];
    reinterpret_cast<unsigned*>(this)[2] = reinterpret_cast<const unsigned*>(&src)[2];
    reinterpret_cast<unsigned*>(this)[3] = reinterpret_cast<const unsigned*>(&src)[3];
}
__forceinline hkSimdReal::hkSimdReal(float value)
{
    m_vValue = _mm_load_ss(&value);
}
__forceinline __m128& hkVector4::getQuad()
{
    return m_vComponents;
}
__forceinline const __m128& hkVector4::getQuad() const
{
    return m_vComponents;
}
__forceinline void hkVector4::operator=(const __m128& src)
{
    m_vComponents = src;
}
__forceinline float& hkVector4::operator()(int n)
{
    return m_vComponents.m128_f32[n];
}
__forceinline const float& hkVector4::operator()(int n) const
{
    return m_vComponents.m128_f32[n];
}
__forceinline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}
__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
__forceinline void hkVector4::mul4s(const hkSimdReal& s)
{
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), m_vComponents);
}
__forceinline void hkVector4::mul4(const hkSimdReal& s)
{
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), m_vComponents);
}
extern "C" __m128 DAT_010ec7f0;
__forceinline void hkVector4::setInterpolate4(const hkVector4& a, const hkVector4& b,
                                             const hkSimdReal& factor)
{
    __m128 t = _mm_shuffle_ps(factor.m_vValue, factor.m_vValue, 0);
    __m128 rest = _mm_sub_ps(DAT_010ec7f0, t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(rest, a.m_vComponents), _mm_mul_ps(t, b.m_vComponents));
}

struct LongRayBool
{
    char m_cBooleanValue;
    LongRayBool()
    {}
    LongRayBool& operator=(bool value)
    {
        m_cBooleanValue = char(value);
        return *this;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    LongRayBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct LongRayCodeInfo
{
    hkVector4 m_offset;
};
struct LongRayCode
{
    int m_00, m_04, m_08, m_0c;
    LongRayCodeInfo m_info;
    const unsigned char* m_data;
};

struct LongRayInput
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    unsigned int m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};

struct LongRayQueryInt
{
    hkVector4 m_offset;
    int m_iIndex;
    float m_FtoBoxScale;
    unsigned int m_uiPropertyCount;
    unsigned int m_properties0;
};

struct LongRayQueryFloat
{
    hkVector4 m_rayStart;
    hkVector4 m_rayEnd;
};

struct LongRayVm
{
    int m_00, m_04, m_08, m_0c;
    const LongRayCode* m_pMoppCode;
    float m_vRayDirectionVector;
    int m_18, m_1c;
    LongRayInput m_kRayCastVector;
    LongRayBool m_bRayCastEnabled;
    float m_fEarlyOutHitFraction;
    void* m_kCollector;
    int m_5c, m_60;
    const void* m_pShapeCollection;
    int m_iCurrentChunkId;

    void hkpMoppLongRayVirtualMachine_queryRayOnTree(const LongRayQueryInt* query, const unsigned char* PC, LongRayQueryFloat* fq, int level);
    LongRayBool UpdateState_00dd2df0(const void* collection, const LongRayCode* code, const LongRayInput& input,
                             void* collector);
};

// @fnv 0x00dd2df0
// src: GUESS 0x00dd2df0 (confidence: low)
LongRayBool LongRayVm::UpdateState_00dd2df0(const void* collection, const LongRayCode* code, const LongRayInput& input,
                                    void* collector)
{
    m_fEarlyOutHitFraction = 1.0f;
    m_pShapeCollection = collection;
    m_pMoppCode = code;
    m_kCollector = collector;
    const unsigned char* PC = code->m_data;
    LongRayQueryInt query;
    query.m_offset.setZero4();
    _ReadWriteBarrier();
    m_vRayDirectionVector = 1.0f / code->m_info.m_offset.w;
    query.m_FtoBoxScale = (float)(code->m_info.m_offset.w * (1.0 / 65536.0));
    {
        LongRayQueryFloat fq;
        fq.m_rayStart.setSub4(input.m_vFrom, code->m_info.m_offset);
        fq.m_rayEnd.setSub4(input.m_vTo, code->m_info.m_offset);
        fq.m_rayStart.mul4s(query.m_FtoBoxScale);
        fq.m_rayEnd.mul4s(query.m_FtoBoxScale);

        m_kRayCastVector = input;
        m_bRayCastEnabled = false;
        query.m_uiPropertyCount = 0;
        query.m_iIndex = 0;
        query.m_properties0 = 0;
        m_iCurrentChunkId = (*PC == 0xd) ? -1 : 0;
        hkpMoppLongRayVirtualMachine_queryRayOnTree(&query, PC, &fq, 0);
        return m_bRayCastEnabled;
    }
}

extern void continueRayTraversal(LongRayVm*, const LongRayQueryInt*, const unsigned char*, LongRayQueryFloat*, int);
// src: XBOX_PDB 0x00dd1f30
__declspec(noinline) void LongRayVm::hkpMoppLongRayVirtualMachine_queryRayOnTree(const LongRayQueryInt* query, const unsigned char* PC,
                                                  LongRayQueryFloat* fq, int level)
{
    LongRayQueryFloat ray = *fq;
    continueRayTraversal(this, query, PC, &ray, level);
}

namespace LongRayTreeDetail {
static __forceinline int readTriple(const unsigned char* q)
{
    int x = q[0] << 8;
    int y = q[1];
    y += x;
    y <<= 8;
    y += q[2];
    return y;
}
extern "C" __m128 DAT_010ec7f0;
extern "C" float DAT_01011d78;
extern "C" const char DAT_010d5100[];
extern "C" const char DAT_010d7b2c[];
struct BoolResult
{
    char value;
    BoolResult()
    {}
    BoolResult(bool b) : value((char)b)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct RayPair
{
    hkVector4 ends[2];
};
struct RayInput
{
    hkVector4 start;
    hkVector4 end;
};
struct RayState
{
    hkVector4 offset;
    int shift;
    float scale;
    unsigned primitiveOffset;
    unsigned properties[1];
    void FUN_00dd1f00(const RayState*);
};
struct MoppData
{
    hkVector4 unk00;
    hkVector4 translation;
    unsigned char* code;
};
struct HitStack
{
    hkVector4 unk00;
    float fraction;
    int unk14;
    int unk18;
    int unk1c;
    int keys[8];
    int depth;
};
struct HitOutput
{
    int unk00;
    float fraction;
};
struct Pair3Pool;
struct CdBody
{
    const Pair3Pool* shape;
    unsigned key;
    const void* motion;
    const CdBody* parent;
    __forceinline CdBody(const CdBody* outer)
    {
        parent = outer;
        motion = outer->motion;
    }
    __forceinline void setLeaf(const Pair3Pool* s, unsigned k)
    {
        shape = s;
        key = k;
    }
};
struct Pair3Pool;
struct Container
{
    virtual void unused00();
    virtual void unused04();
    virtual void unused08();
    virtual void unused0c();
    virtual void unused10();
    virtual Pair3Pool* getLeaf(int key, void* buffer);
};
struct Filter
{
    virtual BoolResult accept(RayInput*, Pair3Pool*, Container*, int);
};
struct Pair3Pool
{
    virtual void unused00();
    virtual void unused04();
    virtual void unused08();
    virtual void unused0c();
    virtual void unused10();
    virtual void unused14();
    virtual void unused18();
    virtual void unused1c();
    virtual BoolResult cast(RayInput*, HitStack*);
    virtual void castOutput(RayInput*, CdBody*, HitOutput*);
};
struct ErrorText
{
    int unk00;
    int unk04;
    void* writer;
    void FUN_00cb1600(void*, int);
    void ProcessAndReturnValue_00cc01c0(const char*);
    void FUN_00cc00e0();
};
struct ErrorLogger
{
    virtual void unused00();
    virtual void unused04();
    virtual void unused08();
    virtual int report(int, int, const char*, const char*, int);
};
extern "C" ErrorLogger* DAT_01268360;
extern "C" unsigned char DAT_01269cbd;
void __cdecl FUN_00df22f0(unsigned char*);
struct MoppMachine
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    MoppData* data;
    float scale;
    int unk18;
    int unk1c;
    RayInput ray;
    int unk40;
    Filter* filter;
    int unk48;
    int unk4c;
    char hit;
    float fraction;
    HitStack* stack;
    HitOutput* output;
    const CdBody* context;
    Container* container;
    int keyMask;
    float getFraction() const
    {
        return fraction;
    }
    __forceinline void GetHitDistance(unsigned, const unsigned*);
    void hkpMoppLongRayVirtualMachine_queryRayOnTree(const RayState*, const unsigned char*, RayPair*, int);
};
// @fnv 0x00dd1f30
// src: XBOX_PDB 0x00dd1f30
void MoppMachine::hkpMoppLongRayVirtualMachine_queryRayOnTree(const RayState* state, const unsigned char* code, RayPair* ray, int codeOffset)
{
    RayState localState;
    if (!DAT_01269cbd)
    {
        FUN_00df22f0(&DAT_01269cbd);
        if (!DAT_01269cbd)
            return;
    }
    __assume((reinterpret_cast<unsigned>(ray) & 15) == 0);
    for (;;)
    {
        unsigned int command = *code;
        int axis = 999;
        float lower, upper, from, to;
        int skipLeft, skipRight;
        int property, value;
        switch (command)
        {
        case 19:
            lower = (float)(int)(2 * code[1]);
            upper = (float)(int)(2 * code[2]);
            from = ray->ends[0](2) + ray->ends[0](1);
            to = ray->ends[1](2) + ray->ends[1](1);
            goto shortSplit;
        case 20:
            lower = (float)(int)(2 * code[1] - 255);
            upper = (float)(int)(2 * code[2] - 255);
            from = ray->ends[0](1) - ray->ends[0](2);
            to = ray->ends[1](1) - ray->ends[1](2);
            goto shortSplit;
        case 21:
            lower = (float)(int)(2 * code[1]);
            upper = (float)(int)(2 * code[2]);
            from = ray->ends[0](2) + ray->ends[0](0);
            to = ray->ends[1](2) + ray->ends[1](0);
            goto shortSplit;
        case 22:
            lower = (float)(int)(2 * code[1] - 255);
            upper = (float)(int)(2 * code[2] - 255);
            from = ray->ends[0](0) - ray->ends[0](2);
            to = ray->ends[1](0) - ray->ends[1](2);
            goto shortSplit;
        case 23:
            lower = (float)(int)(2 * code[1]);
            upper = (float)(int)(2 * code[2]);
            from = ray->ends[0](1) + ray->ends[0](0);
            to = ray->ends[1](1) + ray->ends[1](0);
            goto shortSplit;
        case 24:
            lower = (float)(int)(2 * code[1] - 255);
            upper = (float)(int)(2 * code[2] - 255);
            from = ray->ends[0](0) - ray->ends[0](1);
            to = ray->ends[1](0) - ray->ends[1](1);
            goto shortSplit;
        case 25:
            lower = (float)(int)(3 * code[1]);
            upper = (float)(int)(3 * code[2]);
            from = ray->ends[0](1) + ray->ends[0](0) + ray->ends[0](2);
            to = ray->ends[1](1) + ray->ends[1](0) + ray->ends[1](2);
            goto shortSplit;
        case 26:
            lower = (float)(int)(3 * (code[1] - 85));
            upper = (float)(int)(3 * (code[2] - 85));
            from = ray->ends[0](1) + ray->ends[0](0) - ray->ends[0](2);
            to = ray->ends[1](1) + ray->ends[1](0) - ray->ends[1](2);
            goto shortSplit;
        case 27:
            lower = (float)(int)(3 * (code[1] - 85));
            upper = (float)(int)(3 * (code[2] - 85));
            from = ray->ends[0](0) - ray->ends[0](1) + ray->ends[0](2);
            to = ray->ends[1](0) - ray->ends[1](1) + ray->ends[1](2);
            goto shortSplit;
        case 28:
            lower = (float)(int)(3 * (code[1] - 170));
            upper = (float)(int)(3 * (code[2] - 170));
            from = ray->ends[0](0) - ray->ends[0](1) - ray->ends[0](2);
            to = ray->ends[1](0) - ray->ends[1](1) - ray->ends[1](2);
            goto shortSplit;
        case 32:
        case 33:
        case 34:
            axis = command - 32;
            upper = (float)(int)code[1];
            lower = (float)(1.0 + upper);
            from = ray->ends[0](axis);
            to = ray->ends[1](axis);
            code += 3;
            skipRight = code[-1];
            goto zeroLeft;
        case 35:
        case 36:
        case 37:
            axis = command - 35;
            lower = (float)(int)code[1];
            upper = (float)(int)code[2];
            from = ray->ends[0](axis);
            to = ray->ends[1](axis);
            skipLeft = (code[3] << 8) + code[4];
            code += 7;
            skipRight = (code[-2] << 8) + code[-1];
            goto split;
        case 16:
        case 17:
        case 18:
            axis = command - 16;
            lower = (float)(int)code[1];
            upper = (float)(int)code[2];
            from = ray->ends[0](axis);
            to = ray->ends[1](axis);
        shortSplit:
            code += 4;
            skipRight = code[-1];
        zeroLeft:
            skipLeft = 0;
        split: {
            if (to < upper && from < upper)
            {
                code += skipLeft;
                continue;
            }
            code += skipRight;
            if (lower < from && lower < to)
            {
                continue;
            }
            float fromLower = from - lower;
            float fromUpper = from - upper;
            float toLower = to - lower;
            float toUpper = to - upper;
            RayPair branch;
            branch.ends[0] = ray->ends[0];
            branch.ends[1] = ray->ends[1];

            if (fromLower < toLower)
            {
                if (toLower * fromLower < 0.0)
                {
                    float ratio = fromLower / (fromLower - toLower);
                    branch.ends[1].setInterpolate4(ray->ends[0], ray->ends[1], ratio);
                }
                hkpMoppLongRayVirtualMachine_queryRayOnTree(state, code + skipLeft - skipRight, &branch, codeOffset);
                if (toUpper * fromUpper < 0.0)
                {
                    float ratio = fromUpper / (fromUpper - toUpper);
                    ray->ends[0].setInterpolate4(ray->ends[0], ray->ends[1], ratio);
                }
                if (fraction < 1.0f)
                {
                    float f = fraction;
                    hkVector4 point;
                    point.setInterpolate4(this->ray.start, this->ray.end, f);
                    ray->ends[1].setSub4(point, data->translation);
                    ray->ends[1].mul4(hkSimdReal(state->scale));
                    ray->ends[1].sub4(state->offset);
                    if (axis < 3 && ray->ends[1](axis) < upper)
                        return;
                }
            }
            else
            {
                if (toUpper * fromUpper < 0.0)
                {
                    float ratio = fromUpper / (fromUpper - toUpper);
                    branch.ends[1].setInterpolate4(ray->ends[0], ray->ends[1], ratio);
                }
                hkpMoppLongRayVirtualMachine_queryRayOnTree(state, code, &branch, codeOffset);
                if (toLower * fromLower < 0.0)
                {
                    float ratio = fromLower / (fromLower - toLower);
                    ray->ends[0].setInterpolate4(ray->ends[0], ray->ends[1], ratio);
                }
                if (fraction < 1.0f)
                {
                    float f = fraction;
                    hkVector4 point;
                    point.setInterpolate4(this->ray.start, this->ray.end, f);
                    ray->ends[1].setSub4(point, data->translation);
                    ray->ends[1].mul4(hkSimdReal(state->scale));
                    ray->ends[1].sub4(state->offset);
                    if (axis < 3 && ray->ends[1](axis) > lower)
                        return;
                }
                code += skipLeft - skipRight;
            }
            continue;
        }
        case 41:
        case 42:
        case 43: {
            axis = command - 41;
            int hi = readTriple(code + 1);
            int lo = (((code[4] << 8) + code[5]) << 8) + code[6];
            float h = (float)hi * scale;
            h = h * state->scale;
            upper = h - state->offset(axis);
            float l = (float)lo * scale;
            l = l * state->scale;
            code += 7;
            lower = l - state->offset(axis);
            goto clip;
        }
        case 38:
        case 39:
        case 40:
            axis = command - 38;
            upper = (float)(int)code[1];
            lower = (float)(int)code[2];
            code += 3;
        clip: {
            from = ray->ends[0](axis);
            to = ray->ends[1](axis);
            int direction;
            if (from < to)
            {
                if (upper > to)
                    return;
                if (lower < from)
                    return;
                direction = 0;
            }
            else
            {
                if (upper > from)
                    return;
                if (lower < to)
                    return;
                direction = 1;
            }
            hkVector4 a = ray->ends[0];
            hkVector4 b = ray->ends[1];
            float x = from - lower;
            float y = to - lower;
            if (x * y < 0.0f)
            {
                ray->ends[1 - direction].setInterpolate4(a, b, x / (x - y));
            }
            float x2 = from - upper;
            float y2 = to - upper;
            if (x2 * y2 < 0.0f)
            {
                ray->ends[direction].setInterpolate4(a, b, x2 / (x2 - y2));
            }
            continue;
        }
        case 5:
            code += code[1] + 2;
            continue;
        case 6:
            code += (code[1] << 8) + code[2] + 3;
            continue;
        case 7:
            code += (((code[1] << 8) + code[2]) << 8) + code[3] + 4;
            continue;
        case 12:
            codeOffset = ((code[1] << 8) | code[2]) << 9;
            goto jumpCode;
        case 112:
            codeOffset = (code[1] << 24) + (code[2] << 16) + (code[3] << 8) + code[4];
        jumpCode:
            code = data->code + codeOffset;
            continue;
        case 13:
            code += 5;
            continue;
        case 1:
        case 2:
        case 3:
        case 4: {
            hkVector4 dv;
            dv.set((float)(int)code[1], (float)(int)code[2], (float)(int)code[3], DAT_01011d78);
            __m128 d = dv.getQuad();
            float factor = (float)(1 << command);
            ray->ends[0].sub4(dv);
            ray->ends[1].sub4(dv);
            ray->ends[0].mul4(hkSimdReal(factor));
            ray->ends[1].mul4(hkSimdReal(factor));
            localState.offset.setAdd4(state->offset, dv);
            localState.offset.mul4(hkSimdReal(factor));
            localState.shift = state->shift + command;
            localState.scale = state->scale * factor;
            code += 4;
            localState.properties[0] = state->properties[0];
            localState.primitiveOffset = state->primitiveOffset;
            state = &localState;
            continue;
        }
        case 9: {
            int value = code[1];
            if (state != &localState)
            {
                localState.FUN_00dd1f00(state);
                state = &localState;
            }
            localState.primitiveOffset += value;
            code += 2;
            continue;
        }
        case 10: {
            int value = (code[1] << 8) + code[2];
            if (state != &localState)
            {
                localState.FUN_00dd1f00(state);
                state = &localState;
            }
            localState.primitiveOffset += value;
            code += 3;
            continue;
        }
        case 11: {
            int value = (((((code[1] << 8) + code[2]) << 8) + code[3]) << 8) + code[4];
            if (state != &localState)
            {
                localState.FUN_00dd1f00(state);
                state = &localState;
            }
            localState.primitiveOffset = value;
            code += 5;
            continue;
        }
        case 96:
        case 97:
        case 98:
        case 99:
            value = code[1];
            code += 2;
            localState.properties[command - 96] = value;
            goto setProperty;
        case 100:
        case 101:
        case 102:
        case 103:
            value = (code[1] << 8) + code[2];
            localState.properties[command - 100] = value;
            code += 3;
            goto setProperty;
        case 104:
        case 105:
        case 106:
        case 107:
            value = (((((code[1] << 8) + code[2]) << 8) + code[3]) << 8) + code[4];
            localState.properties[command - 104] = value;
            code += 5;
        setProperty: {
            int saved = localState.properties[0];
            if (state != &localState)
            {
                localState.FUN_00dd1f00(state);
                state = &localState;
            }
            localState.properties[0] = saved;
            continue;
        }
        default: {
            __declspec(align(16)) char buffer[512];
            ErrorText message;
            message.FUN_00cb1600(buffer, 512);
            message.ProcessAndReturnValue_00cc01c0(DAT_010d5100);
            if (DAT_01268360->report(3, 0x1298fedd, buffer, DAT_010d7b2c, 554))
            {
                __debugbreak();
                message.FUN_00cc00e0();
            }
            else
            {
                message.FUN_00cc00e0();
            }
            continue;
        }
        case 0:
            return;
            {
                int primitive;
            case 80:
                primitive = code[1];
                goto leaf;
            case 81:
                primitive = (code[1] << 8) + code[2];
                goto leaf;
            case 82:
                primitive = (((code[1] << 8) + code[2]) << 8) + code[3];
                goto leaf;
            case 83:
                primitive = code[1];
                primitive <<= 24;
                {
                    int high = code[2];
                    high <<= 16;
                    primitive += high;
                    high = code[3];
                    primitive = code[4] + primitive;
                    high <<= 8;
                    primitive += high;
                }
                goto leaf;
            case 48:
            case 49:
            case 50:
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            case 56:
            case 57:
            case 58:
            case 59:
            case 60:
            case 61:
            case 62:
            case 63:
            case 64:
            case 65:
            case 66:
            case 67:
            case 68:
            case 69:
            case 70:
            case 71:
            case 72:
            case 73:
            case 74:
            case 75:
            case 76:
            case 77:
            case 78:
            case 79:
                primitive = command - 48;
            leaf:
                primitive += state->primitiveOffset;
                unsigned chunk = codeOffset >> 9;
                unsigned remapped = ((chunk << 8) & keyMask) | primitive;
                GetHitDistance(remapped, (const unsigned*)state->properties);
                return;
            }
        }
    }
}
__forceinline void MoppMachine::GetHitDistance(unsigned key, const unsigned* properties)
{
    __declspec(align(16)) char leafBuffer[512];
    Pair3Pool* leaf = container->getLeaf(key, leafBuffer);
    if (filter && !filter->accept(&this->ray, leaf, container, key).value)
        return;
    if (stack)
    {
        ++stack->depth;
        BoolResult result = leaf->cast(&this->ray, stack);
        --stack->depth;
        if (result)
        {
            hit = result.value;
            fraction = stack->fraction;
            stack->keys[stack->depth] = key;
        }
    }
    else
    {
        CdBody body(context);
        body.setLeaf(leaf, key);
        leaf->castOutput(&this->ray, &body, output);
        fraction = output->fraction;
    }
}
}
