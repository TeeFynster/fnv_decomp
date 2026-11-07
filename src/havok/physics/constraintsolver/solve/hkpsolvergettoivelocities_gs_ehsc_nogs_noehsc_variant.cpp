#define FNV64_HKVECTOR4_PACKET_BODIES
// src/havok/physics/constraintsolver/solve/hkpsolvergettoivelocities_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/constraintsolver/solve/hkpsolvergettoivelocities.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/constraintsolver/solve/hkpsolvergettoivelocities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/solve/hkpsolvergettoivelocities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "../../../../../include/hkVector4.h"
struct State
{
    int type;
    int index;
    float scale;
    float parameter;
    hkVector4 position, axis, basis0, basis1, basis2, extra0, extra1;
    void InitializeFields_00d72030(const State*);
};
struct Header
{
    int type;
    unsigned short first;
    unsigned short second;
    int flags;
    int size;
};
// hkp1Lin2AngJacobian (48 bytes): linear row then the two angular rows; evaluate() dots linear with the position
// difference and the angular rows with each body's axis. Not the console-command Command.
struct Lin2AngJacobian
{
    hkVector4 a, b, c;
};
extern unsigned char DAT_011b9414[];
static __forceinline float evaluate(const Lin2AngJacobian* command, const State* first, const State* second,
                                    bool firstTermFirst = false)
{
    __m128 sum;
    if (firstTermFirst)
        sum = _mm_add_ps(_mm_mul_ps(command->b.get(), first->axis.get()),
                         _mm_mul_ps(command->c.get(), second->axis.get()));
    else
        sum = _mm_add_ps(_mm_mul_ps(command->c.get(), second->axis.get()),
                         _mm_mul_ps(command->b.get(), first->axis.get()));
    sum = _mm_add_ps(sum, _mm_mul_ps(_mm_sub_ps(first->position.get(), second->position.get()), command->a.get()));
    __m128 y = _mm_shuffle_ps(sum, sum, 0x55);
    __m128 z = _mm_shuffle_ps(sum, sum, 0xaa);
    float value;
    _mm_store_ss(&value, _mm_add_ss(z, _mm_add_ss(y, sum)));
    return value;
}
static __forceinline float evaluatePair(const Lin2AngJacobian* command, const State* first, const State* second,
                                        bool firstTermFirst = false)
{
    __m128 sum =
        _mm_add_ps(_mm_mul_ps(command->b.get(), first->axis.get()), _mm_mul_ps(command->c.get(), second->axis.get()));
    sum = _mm_add_ps(sum, _mm_mul_ps(_mm_sub_ps(first->position.get(), second->position.get()), command->a.get()));
    __m128 y = _mm_shuffle_ps(sum, sum, 0x55);
    __m128 z = _mm_shuffle_ps(sum, sum, 0xaa);
    float value;
    _mm_store_ss(&value, _mm_add_ss(z, _mm_add_ss(y, sum)));
    return value;
}
static __forceinline float clampValue(float a)
{
    return 0.0f < a ? 0.0f : a;
}
// @fnv 0x00d9f6f0
// src: GUESS 0x00d9f6f0 (confidence: low)
int __cdecl hkVector4_ProcessEntries_00d9f6f0(void* unused, const Header* header, const State* states, int limit, float* output)
{
    const State* first = states + header->first;
    const State* second = states + header->second;
    int count = 0;
    const signed char* cursor = reinterpret_cast<const signed char*>(header + 1);
    int single = 1, pair = 2;
    State firstLocal, secondLocal;
    for (;;)
    {
        int opcode = *cursor;
        switch (opcode)
        {
        case 0:
        case 1:
        case 22:
        case 23:
        case 24:
            return count;
        case 3:
        case 8:
        case 9:
        case 10:
        case 12:
        case 13:
        case 14:
        case 15:
        case 25:
        case 26:
            do
            {
                cursor += DAT_011b9414[*cursor];
            } while (*cursor == static_cast<signed char>(opcode));
            break;
        case 27: {
            firstLocal.InitializeFields_00d72030(first);
            first = &firstLocal;
            secondLocal.InitializeFields_00d72030(second);
            second = &secondLocal;
            hkVector4 firstAxis, secondAxis, firstBasis, secondBasis;
            firstAxis.hkVector4_setMul3(cursor, &firstLocal.axis);
            secondAxis.hkVector4_setMul3(cursor + 48, &secondLocal.axis);
            firstBasis.hkVector4_setMul3(cursor, &firstLocal.basis2);
            secondBasis.hkVector4_setMul3(cursor + 48, &secondLocal.basis2);
            firstLocal.position.set(_mm_add_ps(firstLocal.position.get(), firstAxis.get()));
            firstLocal.basis1.set(_mm_add_ps(firstLocal.basis1.get(), firstBasis.get()));
            secondLocal.position.set(_mm_add_ps(secondLocal.position.get(), secondAxis.get()));
            secondLocal.basis1.set(_mm_add_ps(secondLocal.basis1.get(), secondBasis.get()));
            cursor += 96;
            break;
        }
        case 2:
            cursor += *reinterpret_cast<const int*>(cursor + 4);
            break;
        case 16:
        case 17:
        case 18:
        case 19: {
            if (single > limit)
                return count;
            ++pair;
            float value = evaluate(reinterpret_cast<const Lin2AngJacobian*>(cursor), first, second);
            ++count;
            ++single;
            *output++ = clampValue(value);
            cursor += 48;
            break;
        }
        case 20:
        case 21: {
            if (pair > limit)
                return count;
            pair += 2;
            const Lin2AngJacobian* command = reinterpret_cast<const Lin2AngJacobian*>(cursor);
            float value = evaluatePair(command, first, second);
            count += 2;
            single += 2;
            *output++ = clampValue(value);
            value = evaluatePair(command + 1, first, second);
            *output++ = clampValue(value);
            cursor += 112;
            break;
        }
        case 5:
        case 6:
            if (single > limit)
                return count;
            ++pair;
            *output = evaluate(reinterpret_cast<const Lin2AngJacobian*>(cursor), first, second);
            ++count;
            ++single;
            ++output;
            cursor += 48;
            break;
        case 7:
            if (single > limit)
                return count;
            ++pair;
            *output = evaluate(reinterpret_cast<const Lin2AngJacobian*>(cursor), first, second);
            ++count;
            ++single;
            ++output;
            cursor += 64;
            break;
        default:
            break;
        }
    }
}
