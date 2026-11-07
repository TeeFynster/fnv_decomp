
// src/bsshader/bsshaderutil_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00b6bee0: the skeleton of src/bsshader/bsshaderutil.cpp
// with declarations corrected to what the original code does (bsshaderutil_decls.h: virtual void vfn_48() = 0; -> virtual void vfn_48(void* a, void* b, int c) =; bsshaderutil_decls.h: virtual void Unk_2A() = 0; virtual void Un -> virtual void Unk_2A() = 0; virtual void Un). Move the function to its real unit once
// that unit declares it this way.

#include "bsshaderutil_decls_decl_bsshaderutil.h"
#include "../../include/NiRefObject.h"
// NiNodeHolder_bsshaderutil_decl_variant: local type (was include/NiNodeHolder.h, which had no evidence of one real class); its methods are 0x00559450 NiPointer<PathingSolution>::operator->, 0x0066b0d0 NiPointer<PathingSolution>::operator=
#include "../../include/NiRefObject.h"

class NiNode;
class CleanupObject;

class NiNodeHolder_bsshaderutil_decl_variant
{
public:
    NiRefObject* value;

    NiNodeHolder_bsshaderutil_decl_variant(NiRefObject* p);
    ~NiNodeHolder_bsshaderutil_decl_variant();
    operator NiNode*() const;
    void FUN_0066b0d0(CleanupObject* object);
    CleanupObject* Modelloader_GetReferencedThis();
};
#pragma optimize("", off)
#pragma optimize("", on)
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}
extern NiPointer<NiRefObject> g_spCurrentAccumulator;
void BSShaderManager_SetCurrentAccumulator(BSShaderAccumulatorView* accumulator);

extern __declspec(thread) int DAT_012722bc;
struct AccumulatorContext
{
    int unk00, unk04;
    NiRefObject* object;
    void NiTexturingProperty_Map_SetTexture(NiRefObject*);
};
extern AccumulatorContext* DAT_011f4748;
inline NiNodeHolder_bsshaderutil_decl_variant::NiNodeHolder_bsshaderutil_decl_variant(NiRefObject* p) : value(p)
{
    if (value)
        value->IncRefCount();
}
void BSShaderManager_SetAccumulator(NiRefObject*);
// @fnv 0x00b6bee0
// src: COMMUNITY 0x00b6bee0
void BSShaderUtil_AccumulateScene(void* first, void* second, BSShaderAccumulatorView* accumulator)
{
    if (DAT_011f4748 && first && second)
    {
        if (!DAT_012722bc)
        {
            NiNodeHolder_bsshaderutil_decl_variant guard(DAT_011f4748->object);
            DAT_011f4748->NiTexturingProperty_Map_SetTexture(accumulator->texture);
        }
        BSShaderManager_SetAccumulator(accumulator->texture);
        accumulator->vfn_48(first, second, 0);
    }
}
