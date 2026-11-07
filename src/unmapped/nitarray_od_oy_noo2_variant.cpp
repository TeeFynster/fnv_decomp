#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/NiPointer.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiTObjectArray.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiD3DShaderFactory.h"
#include "../../include/NiD3DRenderState.h"

// src/unmapped/nitarray_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/unmapped/nitarray.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_009ba5f0_shell
{
    void SetChildObject(int);
};
struct FUN_00c89c80_obj
{
    void CopyFromSource(unsigned int uiMaxSize);
};
extern MemoryManager DAT_011f6238;
struct KeyPair
{
    void* m_pFirst;
    void* m_pSecond;

    static void* operator new(unsigned int auiSize) throw()
    {
        return DAT_011f6238.Allocate(auiSize);
    }

    KeyPair(void* apFirst, void* apSecond) throw() : m_pFirst(apFirst), m_pSecond(apSecond)
    {}
};
struct FUN_00a41520_cls
{
    int unk00;
    int unk04;
    unsigned short m_uCapacity;
    unsigned short m_uCount;
    unsigned short m_u0c;
    unsigned short m_uGrowStep;

    int FindPairIndex(void* apFirst, void* apSecond);
    void FUN_00a90180(unsigned int auiNewSize);
    void FUN_00ba3aa0(unsigned int auiIndex, KeyPair** appEntry);

    bool BSAnimNoteListener_Register(void* apFirst, void* apSecond);
};
void* __cdecl _NiMalloc_00aa1070(unsigned int auiSize);
void __cdecl _NiFree_00aa10f0(void* apMemory);
struct S_Interface
{
    static KeyPair** Allocate(unsigned int auiCount)
    {
        return (KeyPair**)_NiMalloc_00aa1070(sizeof(KeyPair*) * auiCount);
    }
};
struct C89CD0Target
{
    void process(void* arg);
};
struct C89CD0Holder
{
    int unk00;
    int unk04;
    C89CD0Target* m_pkTarget;

    void ProcessTarget(void* arg);
};
struct Target
{
    void UpdateState_00c89bf0(void* apArg);
};
struct FUN_00c89cf0_cls
{
    int unk00;
    int unk04;
    Target* m_pFlagTarget;

    void DispatchToTarget(void* apArg);
};

typedef NiPointer<NiRefObject> NiRefObjectPtr;

// @fnv 0x00869420
// src: COMMUNITY 0x00869420
void __cdecl j_CopyArrays_V_NiTObjectArray_V_NiPointer_VNiAVObject_GarbageCollector_KAXPBV_NiTObjectArray_V_NiPointer_VNiAVObject_PAV1_Z(NiTObjectArray<NiPointer<NiAVObject> >* apSource, NiTObjectArray<NiPointer<NiAVObject> >* apTarget)
{
    for (unsigned int i = 0; i < apSource->GetSize(); i = i + 1)
    {
        NiPointer<NiAVObject> spRef(apSource->GetAt(i));
        if (spRef)
        {
            apTarget->Add(spRef);
        }
    }
}

// @fnv 0x0060bef0
template <>
void NiTArray<NiRefObjectPtr, NiTNewInterface<NiRefObjectPtr> >::SetSize(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;

    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != NiRefObjectPtr(0))
            {
                m_pBase[i] = NiRefObjectPtr(0);
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }

    NiRefObjectPtr* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = NiTNewInterface<NiRefObjectPtr>::Allocate(m_usMaxSize);
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = NiRefObjectPtr(0);
    }
    else
    {
        m_pBase = 0;
    }
    NiTNewInterface<NiRefObjectPtr>::Deallocate(pSaveBase);
}

namespace fnv_009a5a70 {
struct ItemList
{
    unsigned int GetCount();
    void QueryItem(void** result);
};
struct SpawnedObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    SpawnedObject();
    ~SpawnedObject();
    void Fill(void* item);
    void Attach(ItemList* list);
};
struct FUN_009a5a70_cls
{
    void Dispatch(void* item, SpawnedObject* object);
    void CombatThreatMap_LoadGame(ItemList* list);
};
// @fnv 0x009a5a70
// src: COMMUNITY 0x009a5a70
void FUN_009a5a70_cls::CombatThreatMap_LoadGame(ItemList* list)
{
    unsigned int count = list->GetCount();
    for (unsigned int index = 0; index < count; ++index)
    {
        bool failed = false;
        SpawnedObject* object = new SpawnedObject;
        void* output;
        list->QueryItem(&output);
        object->Fill(output);
        object->Attach(list);
        if (output == 0)
            failed = true;
        if (!failed)
            Dispatch(output, object);
        else
            delete object;
    }
}
}  // namespace fnv_009a5a70
