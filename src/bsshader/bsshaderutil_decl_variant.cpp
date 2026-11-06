
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
    CleanupObject* FUN_00559450();
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
void FUN_00b54b10(BSShaderAccumulatorView* accumulator);

extern __declspec(thread) int DAT_012722bc;
struct AccumulatorContext
{
    int unk00, unk04;
    NiRefObject* object;
    void FUN_004dc540(NiRefObject*);
};
extern AccumulatorContext* DAT_011f4748;
inline NiNodeHolder_bsshaderutil_decl_variant::NiNodeHolder_bsshaderutil_decl_variant(NiRefObject* p) : value(p)
{
    if (value)
        value->IncRefCount();
}
void FUN_00b54ac0(NiRefObject*);
// @fnv 0x00b6bee0
void FUN_00b6bee0(void* first, void* second, BSShaderAccumulatorView* accumulator)
{
    if (DAT_011f4748 && first && second)
    {
        if (!DAT_012722bc)
        {
            NiNodeHolder_bsshaderutil_decl_variant guard(DAT_011f4748->object);
            DAT_011f4748->FUN_004dc540(accumulator->texture);
        }
        FUN_00b54ac0(accumulator->texture);
        accumulator->vfn_48(first, second, 0);
    }
}
