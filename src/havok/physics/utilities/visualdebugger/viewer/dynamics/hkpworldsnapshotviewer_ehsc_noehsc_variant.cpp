#include "../../../../../../../include/hkProcessHandler.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkpPhysicsContext.h"
#include "../../../../../../../include/hkArrayStreamWriter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkCharArray.h"

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern int DAT_010d16f0;
extern int DAT_010d1700;
extern int DAT_010d1720;
extern void __cdecl FUN_00ddcc60();
struct FUN_00d62fe0_cls
{
    void __thiscall UpdateFields_00d62fe0();
};
extern int DAT_01268fc0;
extern int DAT_01268fc4;
struct FUN_00d63210_class
{
    int GetValueByFlag();
};
typedef void(__cdecl* SnapshotFn)();
struct ProfileRegistry
{
    int hkProcessFactory_registerProcess(const char* apName, SnapshotFn apfnHandler);
};
extern ProfileRegistry* DAT_01269cd0;
extern int DAT_01268fc4;
extern int DAT_01268fc0;
void __cdecl hkpWorldSnapshotViewer_createNative();
void __cdecl AllocateRecordWithData();
void __cdecl RegisterSnapshotCommands();
struct FUN_00c7be20_cls;
struct FUN_00c7be20_src
{
    int unk00;
    int unk04;
    int* m_08;
    int m_0c;
};
struct FUN_00c7be20_arr
{
    int* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
};
void* __cdecl hkMemoryRouter_getInstance() throw();
struct FUN_00c7be20_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    FUN_00c7be20_src* m_48;

    void CopySourceArray(FUN_00c7be20_arr* out);
};
struct SubObj
{
    virtual void vfunc0();
    virtual void vfunc1(void* item);
};
struct FUN_00d62fa0_class
{
    char pad[0x18];
    SubObj m_subObj;
    hkpPhysicsContext* m_container;

    void __thiscall ProcessContainerItems();
};
extern int DAT_010d1794;
extern int DAT_010d1774;
extern int DAT_010d1764;
struct SubObject
{
    void Init(int a, int b);
};
struct FUN_00d63280_cls
{
    void* m_vtbl0;
    int unk04;
    void* m_vtbl8;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_vtbl20;
    int unk24;
    SubObject m_sub28;

    void Setup(int b);
    FUN_00d63280_cls* hkpWorldMemoryViewer_hkpWorldMemoryViewer(int a, int b);
};


void* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00c7be20_arr;

inline hkMemoryAllocator& containerHeap()
{
    return ((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
}

inline hkCharArray::~hkCharArray()
{
    hkMemoryAllocator& alloc = containerHeap();
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
    {
        alloc.bufFree(m_data, m_iCapacityState & 0x3fffffff);
    }
}

inline void hkCharArray::reserve(int n)
{
    hkMemoryAllocator& alloc = containerHeap();
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int cap2 = 2 * capacity;
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil__reserve(alloc, this, newSize, 1);
    }
}

inline void hkCharArray::SetSizeAndGrow(int n)
{
    reserve(n);
    m_iElementCount = n;
}


struct StructureLayoutRules
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};

extern StructureLayoutRules DAT_010d6ae8;
extern StructureLayoutRules DAT_011b7b88;
extern int DAT_01268fc0;
extern int DAT_01268fc4;

hkBool __cdecl hkpHavokSnapshot_save_00cc0d60(hkpWorld* world, hkArrayStreamWriter* writer, hkBool binary,
                            const StructureLayoutRules* rules, int aiFlags);

struct hkDisplaySerializeOStream
{
    void hkOArchive_write32u(int n);
    void hkOArchive_write8u(unsigned int b);
    void WriteInt(int n);
    void hkOArchive_writeRaw(const char* buf, int n);
};

inline int hkpPhysicsContext::getNumWorlds() const
{
    return m_numWorlds;
}

inline hkpWorld* hkpPhysicsContext::getWorld(int i) const
{
    return m_ppWorlds[i];
}

struct FUN_00d63040_cls
{
    int unk00;
    int unk04;
    int unk08;
    hkDisplaySerializeOStream* m_pDisplayStream;
    int unk10;
    hkProcessHandler* m_pProcessHandler;
    int unk18;
    hkpPhysicsContext* m_iValueAtOffset0C;
    hkBool m_convertToPC;

    void hkpWorldSnapshotViewer_step(float frameTimeInMs);
};

// @fnv 0x00d63040
// src: HAVOK_LIB 0x00d63040
void FUN_00d63040_cls::hkpWorldSnapshotViewer_step(float frameTimeInMs)
{
    if (m_pDisplayStream)
    {
        hkCharArray storage;
        storage.reserve(100 * 1024);
        hkArrayStreamWriter sw(&storage, 1);

        const StructureLayoutRules& rules = m_convertToPC.m_cBooleanValue ? DAT_010d6ae8 : DAT_011b7b88;
        for (int wi = 0; wi < m_iValueAtOffset0C->getNumWorlds(); ++wi)
        {
            storage.SetSizeAndGrow(0);
            hkpHavokSnapshot_save_00cc0d60(m_iValueAtOffset0C->getWorld(wi), &sw, true, &rules, 0);
            int length = storage.GetLogicalSize();
            if (length >= 1)
            {
                m_pDisplayStream->hkOArchive_write32u(length + 9);
                m_pDisplayStream->hkOArchive_write8u(0xd0);
                m_pDisplayStream->hkOArchive_write8u(rules.m_ucBytesInPointer);
                m_pDisplayStream->hkOArchive_write8u(rules.m_bLittleEndian);
                m_pDisplayStream->hkOArchive_write8u(rules.m_bReusePaddingOptimization);
                m_pDisplayStream->hkOArchive_write8u(rules.m_bEmptyBaseClassOptimization);
                m_pDisplayStream->WriteInt(length);
                m_pDisplayStream->hkOArchive_writeRaw(storage.begin(), length);
            }
        }
    }

    if (m_pProcessHandler)
    {
        m_pProcessHandler->deleteProcess(m_convertToPC.m_cBooleanValue ? DAT_01268fc0 : DAT_01268fc4);
    }
}
