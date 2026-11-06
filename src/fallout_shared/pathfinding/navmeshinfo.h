
#include "navmeshinfo_decls.h"
// @fnv 0x0069ad00
bool NavMeshInfo::ResolveNavMesh(NavMeshPtr& out)
{
    if (FUN_0068f320())
        return false;
    ProcessWithScopedRef(out, m_pLocationNavMesh);
    return out.FUN_00559450() ? true : false;
}
// @fnv 0x006dd6a0
bool PathingLocation::HasValidTriangle()
{
    if (m_pLocationNavMesh == 0)
        return false;
    if (!m_pLocationNavMesh->HasNonZeroAtOffset54())
        return false;
    if (m_usTriangleID == 0xffff)
        return false;
    return true;
}
