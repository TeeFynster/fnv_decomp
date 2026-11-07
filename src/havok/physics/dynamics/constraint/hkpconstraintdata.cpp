
// src/havok/physics/dynamics/constraint/hkpconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/hkpconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkpAngConstraintAtom.h"
#include "../../../../../include/hkpAngFrictionConstraintAtom.h"
#include "../../../../../include/hkpConstraintAtom.h"
#include "../../../../../include/hkpSimpleContactConstraintAtom.h"

extern "C" void __cdecl hkString_memSet(void* dst, int n, int len);

struct FUN_00d21a30_class
{
    void __thiscall hkpConstraintData_addInstance(int a, int b, int c);
};

// @fnv 0x00d21a30
// src: HAVOK_LIB 0x00d21a30
void __thiscall FUN_00d21a30_class::hkpConstraintData_addInstance(int a, int pBuffer, int uiLength)
{
    if (pBuffer)
        hkString_memSet((void*)pBuffer, 0, uiLength);
}

// @fnv 0x00d21a50
// src: GUESS 0x00d21a50 (confidence: low)
int __stdcall hkpConstraintData_GetA(int a)
{
    return a;
}

extern "C" void _ReadWriteBarrier(void);
struct GenericConstraintAtomScheme
{
    int maxSizeOfSchema, sizeOfSchemas, numSolverResults, numSolverElemTemps;
    const hkpConstraintAtom* atoms;
    int sizeOfAllAtoms;
};
inline void addSolverSchema(GenericConstraintAtomScheme* info, int schema, int results, int temps)
{
    info->sizeOfSchemas += schema;
    info->numSolverResults += results;
    info->numSolverElemTemps += temps;
    _ReadWriteBarrier();
}
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
inline void addAngularFriction(GenericConstraintAtomScheme* out, int schema, int rows, int temps)
{
    out->sizeOfSchemas += schema;
    out->numSolverResults += rows;
    out->numSolverElemTemps += temps;
}
// Fills a GenericConstraintAtomScheme with solver schema sizes, result counts, and temps by walking the hkpConstraintAtom array.
// @fnv 0x00d21a60
// src: HAVOK_LIB 0x00d21a60
void __cdecl hkpConstraintData_getConstraintInfoUtil(const hkpConstraintAtom* atoms, int sizeOfAllAtoms, GenericConstraintAtomScheme* info)
{
    info->atoms = atoms;
    info->sizeOfAllAtoms = sizeOfAllAtoms;
    info->maxSizeOfSchema = 0;
    info->sizeOfSchemas = 0;
    info->numSolverResults = 0;
    info->numSolverElemTemps = 0;
    if (atoms->m_type == hkpConstraintAtom::CONTACT)
    {
        int iContactPoints = reinterpret_cast<const hkpSimpleContactConstraintAtom*>(atoms)->m_usNumContactPoints;
        int schema = 128 + 112 * (iContactPoints >> 1) + 48 * (iContactPoints & 1);
        info->sizeOfSchemas = schema;
        info->maxSizeOfSchema = schema + 32;
        info->numSolverResults = iContactPoints + 2;
        info->numSolverElemTemps = iContactPoints + 3;
        if (iContactPoints >= 2)
        {
            ++info->numSolverResults;
            ++info->numSolverElemTemps;
            info->sizeOfSchemas = schema + 32;
        }
        return;
    }
    const char* cursor = reinterpret_cast<const char*>(atoms);
    info->sizeOfSchemas = 16;
    const char* end = cursor + sizeOfAllAtoms;
    while (cursor < end)
    {
        int tempsDelta;

    dispatchAlignedAtom:
        const hkpConstraintAtom* atom = reinterpret_cast<const hkpConstraintAtom*>(cursor);
        switch (atom->m_type)
        {
        case hkpConstraintAtom::INVALID:
            cursor = reinterpret_cast<const char*>((reinterpret_cast<unsigned long>(cursor) + 15) & ~15UL);
            goto dispatchAlignedAtom;
        case hkpConstraintAtom::BALL_SOCKET:
            addSolverSchema(info, 144, 3, 3);
            cursor += 8;
            break;
        case hkpConstraintAtom::STIFF_SPRING:
            addSolverSchema(info, 48, 1, 1);
            cursor += 8;
            break;
        case hkpConstraintAtom::LIN:
            addSolverSchema(info, 48, 1, 1);
            cursor += 4;
            break;
        case hkpConstraintAtom::LIN_SOFT:
        case hkpConstraintAtom::LIN_LIMIT:
            addSolverSchema(info, 64, 1, 1);
            cursor += 12;
            break;
        case hkpConstraintAtom::LIN_FRICTION:
            addSolverSchema(info, 64, 1, 2);
            cursor += 8;
            break;
        case hkpConstraintAtom::LIN_MOTOR:
            info->sizeOfSchemas += 80;
            info->numSolverResults += 1;
            tempsDelta = 3;
            goto sharedContribution;
        case hkpConstraintAtom::ANG_2D:
            addSolverSchema(info, 96, 2, 2);
            cursor += 4;
            break;
        case hkpConstraintAtom::ANG: {
            addSolverSchema(info, 48 * static_cast<const hkpAngConstraintAtom*>(atom)->m_ucNumConstrainedAxes,
                            static_cast<const hkpAngConstraintAtom*>(atom)->m_ucNumConstrainedAxes,
                            static_cast<const hkpAngConstraintAtom*>(atom)->m_ucNumConstrainedAxes);
            cursor += 4;
            break;
        }
        case hkpConstraintAtom::ANG_LIMIT:
            addSolverSchema(info, 48, 1, 1);
            cursor += 16;
            break;
        case hkpConstraintAtom::TWIST_LIMIT:
        case hkpConstraintAtom::CONE_LIMIT:
            addSolverSchema(info, 48, 1, 1);
            cursor += 20;
            break;
        case hkpConstraintAtom::ANG_FRICTION: {
            int axes = static_cast<const hkpAngFrictionConstraintAtom*>(atom)->m_ucNumFrictionAxes;
            int temps = 2 * static_cast<const hkpAngFrictionConstraintAtom*>(atom)->m_ucNumFrictionAxes;
            addAngularFriction(info, 48 * axes, axes, temps);
            cursor += 12;
            break;
        }
        case hkpConstraintAtom::ANG_MOTOR:
            addSolverSchema(info, 64, 1, 3);
            cursor += 20;
            break;
        case hkpConstraintAtom::RAGDOLL_MOTOR:
            info->sizeOfSchemas += 192;
            info->numSolverResults += 3;
            tempsDelta = 9;
            goto sharedContribution;
        case hkpConstraintAtom::PULLEY:
            addSolverSchema(info, 64, 1, 1);
            cursor += 64;
            break;
        case hkpConstraintAtom::SET_LOCAL_TRANSFORMS:
            cursor += 144;
            break;
        case hkpConstraintAtom::SET_LOCAL_ROTATIONS:
            cursor += 112;
            break;
        case hkpConstraintAtom::SET_LOCAL_TRANSLATIONS:
            cursor += 48;
            break;
        case hkpConstraintAtom::BRIDGE:
        case hkpConstraintAtom::MODIFIER_SOFT_CONTACT:
        case hkpConstraintAtom::MODIFIER_MASS_CHANGER:
        case hkpConstraintAtom::MODIFIER_VISCOUS_SURFACE:
        case hkpConstraintAtom::MODIFIER_MOVING_SURFACE:
        case hkpConstraintAtom::MODIFIER_IGNORE:
            return;
        default:
            break;
        }
        continue;
    sharedContribution:
        if (tempsDelta == 3)
        {
            info->numSolverElemTemps += 3;
            _ReadWriteBarrier();
            cursor += 16;
        }
        else
        {
            info->numSolverElemTemps += 9;
            _ReadWriteBarrier();
            cursor += 80;
        }
    }
}
