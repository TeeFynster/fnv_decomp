#include "../../../../include/NavMeshInfo.h"
// gamebryo2.2/corelibs/nimain/nitmapbase_decls.h: declares BaseFormComponent, TESFullName, NavMeshInfo, TESFile, NiUpdateData and more
#ifndef FNV_NITMAPBASE_DECLS_H
#define FNV_NITMAPBASE_DECLS_H

#include "layout_support.h"
#include "NiRefObject.h"
#include "NiRefObject_inline.h"
#include "../../../../include/TESFullName.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/FormChangeMap.h"
#include "../../../../include/BGSReconstructFormsInAllFilesMap.h"
#define _ULARGE_INTEGER FNV64_ULARGE_INTEGER_Unused
#include "../../../../include/TESFile.h"
#undef _ULARGE_INTEGER

class NiShader;
class RefCountedNamedObject;
class NiObject;

#include "../../../../include/NiPointer.h"
template <> inline NiPointer<RefCountedNamedObject>& NiPointer<RefCountedNamedObject>::operator=(const NiPointer<RefCountedNamedObject>& other)
{
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                reinterpret_cast<NiRefObject*>(m_pObject)->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                reinterpret_cast<NiRefObject*>(m_pObject)->IncRefCount();
        }
        return *this;
    }

// 0x00404d30 reads a count at 0x108: not a map.
struct FUN_00404d30_Owner
{
    char reserved[0x108];
    unsigned int count;
    bool GetFirstPos();
};
// 0x00845690: scalar deleting destructor around 0x008456c0.
struct FUN_00845690_Owner
{
    FUN_00845690_Owner* Destructor(unsigned int flags);
    void Object_ForwardCall_008456c0();
};
class TESObjectCELL;
class TESObjectCELL;
extern void* DAT_01031fec[];
// The NiTMapBase<NiTPointerAllocator<unsigned int>,int,TESObjectCELL *> constructor 0x005892c0.
struct FUN_005892c0_MapBase
{
    void InitArray(unsigned int size);
};
class TESForm;
extern void* DAT_01019a3c[];
// RTTI: vftable 0x01019a3c is NiTLargePrimitiveArray<TESForm *>; 0x004701d0 is its constructor over the NiTLargeArray
// constructor 0x004705e0.
struct FUN_004701d0_TESFormLargeArray
{
    void* vtable;
    FUN_004701d0_TESFormLargeArray(unsigned int size, unsigned int flags);
    void NiTLargeArray_TESForm_NiTMallocInterface_TESForm_NiTLargeArray(unsigned int size, unsigned int flags);
};
void operator delete(void* pointer);

const char* PrepareScriptMessage(const char*, bool);

#endif
