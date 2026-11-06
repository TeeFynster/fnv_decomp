#include "../../../../include/NiTStringPointerMap.h"
// Supporting declarations for ninode_od_oy_noo2_variant.cpp.
#ifndef NINODE_PACKET_DECLS_H
#define NINODE_PACKET_DECLS_H

#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiPropertyState.h"
#include "../../../../include/NiTStringPointerMap.h"

extern MemoryManager g_memoryManager;
inline void DestroyPropertyState(NiPropertyState* p)
{
    if (p)
    {
        p->ReleaseAllRefs();
        g_memoryManager.Deallocate(p);
    }
}

class ShaderBufferRecord;

class CloningProcess
{
  public:
    NiTStringPointerMap<ShaderBufferRecord*>* m_pCloneMap;
};

extern NiBound DAT_011f4288;
inline const NiBound& GetBound(NiAVObject* object)
{
    return object->m_kWorldBound ? *reinterpret_cast<const NiBound*>(object->m_kWorldBound) : DAT_011f4288;
}

#endif
