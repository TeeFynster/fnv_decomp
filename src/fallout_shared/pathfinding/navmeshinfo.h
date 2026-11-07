
#include "navmeshinfo_decls.h"
// @fnv 0x0069ad00
bool NavMeshInfo::ResolveNavMesh(NavMeshPtr& out)
{
    if (NavMeshInfo_GetDisabled())
        return false;
    ProcessWithScopedRef(out, m_pLocationNavMesh);
    return out.Modelloader_GetReferencedThis() ? true : false;
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
