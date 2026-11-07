#define FNV64_NIPOINTER_COMPARE_DECLS // Exe 0x004b04f0 retains out-of-line pointer comparison.
#include "../../../../include/NiTArray.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/TESActorBaseData.h"

// src/gamebryo2.2/corelibs/nimain/niavobject_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niavobject.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/nimain/niavobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niavobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../include/NiMemObject.h"
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
extern char const* const g_011f4428_arg1;
char const* const* __cdecl NiAVObject_GetRTTI();
extern const void* DAT_011f9140;
const void* __cdecl BSFadeNode_GetRTTI();
extern MemoryManager g_memoryManager;

// @fnv 0x00438220
// src: XBOX_PDB 0x00438220
int __cdecl NiShadeProperty_GetType()
{
    return 3;
}

struct Flt
{
    operator unsigned int() const;
};
struct FUN_00456650_shell
{
    unsigned short NiGeometry_GetVertexCount() const;
};
// @fnv 0x00456650
// src: XBOX_PDB 0x00456650
unsigned short FUN_00456650_shell::NiGeometry_GetVertexCount() const
{
    return ((TESActorBaseData*)((const Flt*)((const char*)this + 0xb8))->operator unsigned int())->GetFatigue();
}

struct FUN_004a51b0_shell
{
    const float* __thiscall GetFloatElementPointer(int i) const;
};

// @fnv 0x004a51b0
// src: GUESS 0x004a51b0 (confidence: high)
const float* __thiscall FUN_004a51b0_shell::GetFloatElementPointer(int i) const
{
    const float* base = (const float*)this;
    return base + i;
}

struct FUN_0094db80_shell
{
    void __thiscall NiAlphaProperty_SetTestRef(unsigned char ucRef);
};
// @fnv 0x0094db80
// src: XBOX_PDB 0x0094db80
void __thiscall FUN_0094db80_shell::NiAlphaProperty_SetTestRef(unsigned char ucRef)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x1a) = ucRef;
}

struct NiObjectStub;

typedef NiPointer<NiObjectStub> ObjPtr;

ObjPtr* __cdecl NiTObjectArray_NiPointer_NiTexture_NiTObjectArray_NiPointer_NiTexture(unsigned int auiCount);
void __cdecl j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(ObjPtr* pArray);

typedef NiTArray<ObjPtr, NiTMallocInterface<ObjPtr> > ObjPtrArray;


// @fnv 0x004afc80
template <> void NiTArray<ObjPtr, NiTMallocInterface<ObjPtr> >::RemoveAll()
{
    if (m_usESize == m_usSize)
        return;

    if (m_usESize)
    {
        for (unsigned short i = 0, j = 0; i < m_usSize; i++)
        {
            if (m_pBase[i] != ObjPtr(0))
            {
                if (m_pBase[j] != m_pBase[i])
                    m_pBase[j] = m_pBase[i];
                j++;
            }
        }
    }

    ObjPtr* pSaveBase = m_pBase;
    m_usMaxSize = m_usSize = m_usESize;
    if (m_usMaxSize > 0)
    {
        m_pBase = NiTObjectArray_NiPointer_NiTexture_NiTObjectArray_NiPointer_NiTexture(m_usMaxSize);
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
    }
    else
    {
        m_pBase = 0;
    }
    j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(pSaveBase);
}
