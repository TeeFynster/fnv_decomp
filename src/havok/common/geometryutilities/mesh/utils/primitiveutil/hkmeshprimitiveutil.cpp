// src/havok/common/geometryutilities/mesh/utils/primitiveutil/hkmeshprimitiveutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/geometryutilities/mesh/utils/primitiveutil/hkmeshprimitiveutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Returns value multiplied or offset by a small factor depending on mode, or 0 for unknown modes.
// @fnv 0x00e60cb0
// src: XBOX_PDB 0x00e60cb0
int __cdecl hkMeshPrimitiveUtil_calculateNumIndices(int mode, int value)
{
    switch (mode)
    {
    case 1:
        return value;
    case 2:
        return value * 2;
    case 3:
        return value * 3;
    case 4:
        return value + 2;
    default:
        return 0;
    }
}
