#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/BSAudio.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkProcessFactory.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkArray.h"

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d65970_stub
{
    void hkpShapeDisplayViewer_addWorld(int);
};
struct FUN_00d65f70_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void ProcessEntries_00d65f70();
};
// If m_1c is set, iterates its count at offset 0x70 and calls FUN_00d65970 on each entry from the array at 0x6c.
// @fnv 0x00d65f70
// src: GUESS 0x00d65f70 (confidence: low)
void FUN_00d65f70_class::ProcessEntries_00d65f70()
{
    if (m_1c)
    {
        for (int i = 0; i < *(int*)(m_1c + 0x70); ++i)
            ((FUN_00d65970_stub*)((char*)this - 8))->hkpShapeDisplayViewer_addWorld(*(*(int**)(m_1c + 0x6c) + i));
    }
}

struct S_00c6d840_Pair
{
    int m_kPointA;
    int m_kPointB;
    S_00c6d840_Pair(int a, int b) : m_kPointA(a), m_kPointB(b)
    {}
};

struct S_00c6d840_Entry
{
    int m_key;
    int unk04;
    S_00c6d840_Pair m_uiFilterValue;
};

struct S_00c6d840
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
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    S_00c6d840_Entry* m_entries;
    int m_uiItemCount;
    S_00c6d840_Pair FindEntry(int key, int unused);
};

// @fnv 0x00c6d840
S_00c6d840_Pair S_00c6d840::FindEntry(int key, int unused)
{
    for (int i = 0; i < m_uiItemCount; i++)
    {
        if (m_entries[i].m_key == key)
        {
            return m_entries[i].m_uiFilterValue;
        }
    }
    return S_00c6d840_Pair(0, 0);
}

struct FUN_00cb1a60_t
{
    void ResetEntries();
};

struct FUN_00d653e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    FUN_00cb1a60_t sub54;
    void ResetEntries_Thunk();
};

// @fnv 0x00d653e0
// src: GUESS 0x00d653e0 (confidence: medium)
void FUN_00d653e0_cls::ResetEntries_Thunk()
{
    sub54.ResetEntries();
}

struct FUN_00d655e0_Item
{
    int key;
};
struct FUN_00d655e0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    FUN_00d655e0_Item** items30;
    int count34;
    int FindItemIndex(int key);
};
// Scans the items array for an entry whose key equals key and returns its index, or -1 if none matches.
// @fnv 0x00d655e0
int FUN_00d655e0_class::FindItemIndex(int key)
{
    for (int i = 0; i < count34; ++i)
        if (items30[i]->key == key)
            return i;
    return -1;
}

struct Allocator
{
    virtual void reserved();
    virtual void* allocate(unsigned int);
};
void* __cdecl hkMemoryRouter_getInstance();
struct FUN_00d657d0_class
{
    FUN_00d657d0_class* hkpShapeDisplayViewer_hkpShapeDisplayViewer(int);
};
// Allocates a 0x74-byte object from the audio allocator, initializes it with context, and returns a pointer 8 bytes into it, or null on failure.
// @fnv 0x00d65910
// src: HAVOK_LIB 0x00d65910
void* __cdecl hkpShapeDisplayViewer_create(void* context)
{
    hkMemoryRouter* audio = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    FUN_00d657d0_class* result = (FUN_00d657d0_class*)audio->m_heap->blockAlloc(0x74);
    *(unsigned short*)((char*)result + 4) = 0x74;
    result = result->hkpShapeDisplayViewer_hkpShapeDisplayViewer((int)context);
    if (result)
        return (char*)result + 8;
    return 0;
}

struct GlobalObjectO2_00d472a0
{
};
extern hkProcessFactory* hkProcessFactory_registerProcess;
extern GlobalObjectO2_00d472a0 g_01268f2c;
extern void* __cdecl hkpShapeDisplayViewer_create(void*);

// @fnv 0x00d65950
void RegisterShapesProcess()
{
    void* process = hkProcessFactory_registerProcess->RegisterProcess("Shapes", (void*)&hkpShapeDisplayViewer_create);
    *(void**)((char*)&g_01268f2c + 0xB4) = process;
}

struct Target
{
    void hkpShapeDisplayViewer_addWorld();
};
struct Adjustor
{
    void ForwardCall_00d65fb0();
};
// @fnv 0x00d65fb0
// src: GUESS 0x00d65fb0 (confidence: low)
void Adjustor::ForwardCall_00d65fb0()
{
    ((Target*)((char*)this - 0x20))->hkpShapeDisplayViewer_addWorld();
}

extern int g_D661D0Value;

// @fnv 0x00d661d0
// src: GUESS 0x00d661d0 (confidence: low)
int __cdecl Hkpshapedisplayviewer_GetD661D0Value()
{
    return g_D661D0Value;
}

struct FUN_00d652a0_cls
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void v10(int a, int b) = 0;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    void hkpShapeDisplayViewer_synchronizeTransforms(int arg);
};

// @fnv 0x00d652a0
// src: HAVOK_LIB 0x00d652a0
void FUN_00d652a0_cls::hkpShapeDisplayViewer_synchronizeTransforms(int arg)
{
    v10(m_18, arg);
}

extern int vftbl_010d1b04;
extern int vftbl_010d1ae4;
extern int vftbl_010d1ad4;
extern int vftbl_010d1ab8;
extern int vftbl_010d1aa8;
extern int vftbl_010ccf7c;
extern int vftbl_0102f13c;




struct SpawnedBuf
{
    int unk00;
    int unk04;
    int unk08;

    void ProcessArgument(hkMemoryAllocator* apAlloc);
    void Object_DoNothing();
};

struct FUN_00d66080_cls
{
    int m_vptr00;
    int unk04;
    int m_vptr08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_vptr20;
    int unk24;
    int m_vptr28;
    int m_vptr2c;
    int* m_pData;
    int m_iArrayLength;
    unsigned int m_uiObjectFlags;
    SpawnedBuf m_buf3c;
    SpawnedBuf m_buf48;
    SpawnedBuf m_buf54;

    void hkpShapeDisplayViewer_removeWorld(int aiIndex);
    void FUN_00ddcc60();
    void Destroy();
};

// @fnv 0x00d66080
void FUN_00d66080_cls::Destroy()
{
    m_vptr00 = (int)&vftbl_010d1b04;
    m_vptr08 = (int)&vftbl_010d1ae4;
    m_vptr20 = (int)&vftbl_010d1ad4;
    m_vptr28 = (int)&vftbl_010d1ab8;
    m_vptr2c = (int)&vftbl_010d1aa8;

    for (int i = m_iArrayLength - 1; i >= 0; --i)
    {
        hkpShapeDisplayViewer_removeWorld(i);
    }

    {
        SpawnedBuf* pBuf = &m_buf54;
        hkMemoryRouter* pHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        pBuf->ProcessArgument(reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap));
        pBuf->Object_DoNothing();
    }
    {
        SpawnedBuf* pBuf = &m_buf48;
        hkMemoryRouter* pHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        pBuf->ProcessArgument(reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap));
        pBuf->Object_DoNothing();
    }
    {
        SpawnedBuf* pBuf = &m_buf3c;
        hkMemoryRouter* pHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        pBuf->ProcessArgument(reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap));
        pBuf->Object_DoNothing();
    }

    hkMemoryRouter* pHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uiFlags = m_uiObjectFlags;
    m_iArrayLength = 0;
    if ((uiFlags & 0x80000000u) == 0)
    {
        ((hkMemoryAllocator*)pAllocator)->bufFree(m_pData, (int)((uiFlags & 0x3fffffffu) * 4));
    }
    m_pData = 0;
    // the original stores the new flag value AFTER the m_pData=0 store and
    // BEFORE the pop edi; writing it through a reference keeps MSVC from
    // sinking the constant store past the register restore.
    {
        unsigned int& ruiFlags = m_uiObjectFlags;
        ruiFlags = 0x80000000u;
    }
    m_vptr2c = (int)&vftbl_010ccf7c;
    m_vptr28 = (int)&vftbl_0102f13c;
    FUN_00ddcc60();
}

struct OwnerObject
{
    int FindItemIndex(int);
    void hkpShapeDisplayViewer_removeWorld(int);
};

struct FUN_00d66160_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void UpdateFields_00d66160(int arg);
};

// Calls FindItemIndex on the owner object at this-0x20 and, if the result is non-negative, passes it to FUN_00d65fc0.
// @fnv 0x00d66160
// src: GUESS 0x00d66160 (confidence: low)
void FUN_00d66160_cls::UpdateFields_00d66160(int arg)
{
    OwnerObject* pOwner = (OwnerObject*)((char*)this - 0x20);
    int result = pOwner->FindItemIndex(arg);
    if (result >= 0)
    {
        pOwner->hkpShapeDisplayViewer_removeWorld(result);
    }
}

struct D66180PropertyValue
{
    void* m_ptr;
    int m_extra;

    D66180PropertyValue()
    {}
};

struct D66180Property
{
    unsigned int m_key;
    int m_uiAlignmentPadding;
    int m_value0;
    int m_value1;
};

struct D66180Entity
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
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    D66180Property* m_kProperties;
    int m_iPropertyCount;

    D66180PropertyValue getProperty(unsigned int key, void* lockCheck = 0) const;
};

// Scans the entity's property array for key 0x1134 and returns that property's pointer, or a pointer to unk10 if not found.
// @fnv 0x00d66180
void* __cdecl GetProperty1134(D66180Entity* entity)
{
    for (int i = 0; i < entity->m_iPropertyCount; i++)
    {
        if (entity->m_kProperties[i].m_key == 0x1134)
            return entity->getProperty(0x1134).m_ptr;
    }
    return &entity->unk10;
}


struct SpawnSub
{
    virtual void v00();
    virtual void v04(void* p);
};

struct SpawnList
{
    void** m_data;
    int m_uiItemCount;
    unsigned int m_capBits;
};

struct SpawnOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char* m_20;
    int unk24;
    char** m_28;
    int m_2c;
    int unk30;
    char** m_34;
    int m_38;

    void hkpWorld_addEntityListener(void* p);
    void hkpWorld_addWorldPostSimulationListener(void* p);
};

struct SpawnSublist
{
    void** m_data;
    int m_uiItemCount;
};

void __cdecl ResizeAudioStream(void* allocator, void* list, unsigned int elemSize);

struct PendingNode
{
    SpawnOwner* m_pSharedOwner;
    int m_04;
    int m_08;
    unsigned int m_0c;

    PendingNode()
    {
        m_04 = 0;
        m_08 = 0;
        m_0c = 0x80000000u;
    }
    void* operator new(unsigned int size) throw()
    {
        hkMemoryRouter* holder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        Allocator* alloc = reinterpret_cast<Allocator*>(holder->m_heap);
        return alloc->allocate(size);
    }
};

template <class T> inline void hkArrayConstruct(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}

struct FUN_00d64650_cls
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
    SpawnSub m_28;
    int m_2c;
    SpawnList m_30;

    void hkpSweptTransformDisplayViewer_addWorld(SpawnOwner* a1);
};

// @fnv 0x00d64650
// src: HAVOK_LIB 0x00d64650
void FUN_00d64650_cls::hkpSweptTransformDisplayViewer_addWorld(SpawnOwner* apOwner)
{
    void* pSubA;
    if (this != 0)
    {
        pSubA = &m_28;
    }
    else
    {
        pSubA = 0;
    }
    apOwner->hkpWorld_addEntityListener(pSubA);
    void* pSubB;
    if (this != 0)
    {
        pSubB = &m_2c;
    }
    else
    {
        pSubB = 0;
    }
    apOwner->hkpWorld_addWorldPostSimulationListener(pSubB);

    PendingNode* node = new PendingNode();
    node->m_pSharedOwner = apOwner;

    SpawnList* list = &m_30;
    hkMemoryRouter* holder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    if (list->m_uiItemCount == (int)(list->m_capBits & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_heap, list, 4);
    }
    hkArrayConstruct((PendingNode**)list->m_data + list->m_uiItemCount, 1, node);
    list->m_uiItemCount++;

    for (int i = 0; i < apOwner->m_2c; i++)
    {
        char* item = apOwner->m_28[i];
        SpawnSublist* pSublist = (SpawnSublist*)(item + 0x48);
        for (int j = 0; j < pSublist->m_uiItemCount; j++)
        {
            m_28.v04(pSublist->m_data[j]);
        }
    }

    for (int i = 0; i < apOwner->m_38; i++)
    {
        char* item = apOwner->m_34[i];
        SpawnSublist* pSublist = (SpawnSublist*)(item + 0x48);
        for (int j = 0; j < pSublist->m_uiItemCount; j++)
        {
            m_28.v04(pSublist->m_data[j]);
        }
    }

    SpawnSublist* tail = (SpawnSublist*)(apOwner->m_20 + 0x48);
    for (int j = 0; j < tail->m_uiItemCount; j++)
    {
        m_28.v04(tail->m_data[j]);
    }
}

extern int DAT_01268fe0;
struct D65610Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* a, void* b, int c);
};
struct D65610Prim
{
    virtual void p00();
    D65610Obj* m_pEntryObject;
    int unk08, unk0c, unk10, unk14;
};
struct D65610Sec
{
    virtual void hkpShapeDisplayViewer_inactiveEntityMovedCallback(D66180Entity* e);
};
struct D65610Self : D65610Prim, D65610Sec
{
    void hkpShapeDisplayViewer_inactiveEntityMovedCallback(D66180Entity* e);
};

// Calls v10 on the stored object with the entity's offset 0xf0 pointer, the result of GetProperty1134(e), and DAT_01268fe0.
// @fnv 0x00d65610
// src: HAVOK_LIB 0x00d65610
void D65610Self::hkpShapeDisplayViewer_inactiveEntityMovedCallback(D66180Entity* pEntity)
{
    D65610Obj* obj = m_pEntryObject;
    char* p = (char*)pEntity;
    obj->v10(p + 0xf0, GetProperty1134(pEntity), DAT_01268fe0);
}

static inline bool HasProperty(const S_00c6d840* props, int key)
{
    for (int i = 0; i < props->m_uiItemCount; i++)
    {
        if (props->m_entries[i].m_key == key)
            return true;
    }
    return false;
}

// Returns the value of the first present entry among 0x1234 (if checkOverride), 0x1235 and 0x1135; sets *usedDefault and returns 0 if that value is 0.
// @fnv 0x00d652c0
// src: HAVOK_LIB 0x00d652c0
static int _getProxyShape(S_00c6d840* props, bool checkOverride, bool* usedDefault)
{
    int base = props->FindEntry(0x1135, 0).m_kPointA;
    int level = props->FindEntry(0x1235, 0).m_kPointA;
    int iOverride = props->FindEntry(0x1234, 0).m_kPointA;
    int result = 0;
    *usedDefault = false;
    if (checkOverride && HasProperty(props, 0x1234))
    {
        if (iOverride == 0)
        {
            *usedDefault = true;
            return 0;
        }
        result = iOverride;
    }
    else if (HasProperty(props, 0x1235))
    {
        if (level == 0)
        {
            *usedDefault = true;
            return 0;
        }
        result = level;
    }
    else if (HasProperty(props, 0x1135))
    {
        if (base == 0)
        {
            *usedDefault = true;
            return 0;
        }
        result = base;
    }
    return result;
}

int PropertyQueryCaller(S_00c6d840* props, bool checkOverride, bool* usedDefault)
{
    return _getProxyShape(props, checkOverride, usedDefault);
}

struct ShapeList
{
    struct ShapeItem** data;
    int count;
};

struct ShapeItem
{
    virtual void v00()
    {}
    virtual void* GetDesc()
    {
        return 0;
    }
};

struct ShapeSub
{
    int m_00;
    int m_04;
    int m_08;
    void EnsureCapacity(int value, int zero);
};

extern char DAT_0102f13c[];
extern char DAT_010ccf7c[];
extern char DAT_010d1b04[];
extern char DAT_010d1ae4[];
extern char DAT_010d1ad4[];
extern char DAT_010d1ab8[];
extern char DAT_010d1aa8[];
extern float DAT_01012054;
extern int DAT_01268fe8;
extern int DAT_01268fe4;

void* __cdecl hkMemoryRouter_getInstance();
int __cdecl hkString_strCmp(const char* name, void* obj);

struct FUN_00d657d0_cls
{
    void* m_vptr00;
    int unk04;
    void* m_vptr08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_vptr20;
    int unk24;
    void* m_vptr28;
    void* m_vptr2c;
    int m_30;
    int m_34;
    unsigned int m_38;
    ShapeSub m_3c;
    ShapeSub m_48;
    ShapeSub m_54;
    unsigned char m_60;
    unsigned char m_61;
    unsigned char m_62;
    unsigned char m_63;
    unsigned char m_64;
    unsigned char m_65;
    unsigned char m_66;
    float m_68;
    int m_6c;
    int m_70;

    void FUN_00ddccb0(ShapeList* a1);
    FUN_00d657d0_cls* hkpShapeDisplayViewer_hkpShapeDisplayViewer(ShapeList* a1);
};

// Initializes vtables, ShapeSub members, and flags, then searches a1 for a ShapeDisplayViewerOptions item to set m_60.
// @fnv 0x00d657d0
// src: HAVOK_LIB 0x00d657d0
FUN_00d657d0_cls* FUN_00d657d0_cls::hkpShapeDisplayViewer_hkpShapeDisplayViewer(ShapeList* apShapes)
{
    int i;
    FUN_00ddccb0(apShapes);
    *(void* volatile*)&m_vptr28 = (void*)DAT_0102f13c;
    *(void* volatile*)&m_vptr2c = (void*)DAT_010ccf7c;
    m_vptr00 = (void*)DAT_010d1b04;
    m_vptr08 = (void*)DAT_010d1ae4;
    m_vptr20 = (void*)DAT_010d1ad4;
    *(void* volatile*)&m_vptr28 = (void*)DAT_010d1ab8;
    *(void* volatile*)&m_vptr2c = (void*)DAT_010d1aa8;
    *(int volatile*)&m_30 = 0;
    *(int volatile*)&m_34 = 0;
    m_38 = 0x80000000;
    ShapeSub* pShapeSub1 = &m_3c;
    pShapeSub1->m_00 = 0;
    pShapeSub1->m_04 = 0;
    pShapeSub1->m_08 = -1;
    {
        void* h1 = hkMemoryRouter_getInstance();
        int val1 = ((int*)h1)[4];
        pShapeSub1->EnsureCapacity(val1, 0);
    }
    ShapeSub* pShapeSub2 = &m_48;
    pShapeSub2->m_00 = 0;
    pShapeSub2->m_04 = 0;
    pShapeSub2->m_08 = -1;
    {
        void* h2 = hkMemoryRouter_getInstance();
        int val2 = ((int*)h2)[4];
        pShapeSub2->EnsureCapacity(val2, 0);
    }
    ShapeSub* pShapeSub3 = &m_54;
    pShapeSub3->m_00 = 0;
    pShapeSub3->m_04 = 0;
    pShapeSub3->m_08 = -1;
    {
        void* h3 = hkMemoryRouter_getInstance();
        int val3 = ((int*)h3)[4];
        pShapeSub3->EnsureCapacity(val3, 0);
    }

    FUN_00d657d0_cls* __restrict self = this;
    *(unsigned char volatile*)&self->m_60 = 1;
    *(unsigned char volatile*)&self->m_61 = 0;
    *(unsigned char volatile*)&self->m_62 = 0;
    *(unsigned char volatile*)&self->m_63 = 1;
    *(unsigned char volatile*)&self->m_64 = 1;
    *(unsigned char volatile*)&self->m_65 = 1;
    *(unsigned char volatile*)&self->m_66 = 0;
    *(float volatile*)&self->m_68 = -1.0f;
    *(int volatile*)&self->m_6c = DAT_01268fe8;
    m_70 = DAT_01268fe4;
    int count = apShapes->count;
    for (i = 0; i < count; ++i)
    {
        ShapeItem* item = apShapes->data[i];
        void* desc = item->GetDesc();
        if (hkString_strCmp("ShapeDisplayViewerOptions", desc) == 0)
            goto found;
    }
    return this;
found: {
    char* o = (char*)apShapes->data[i];
    m_60 = ((o != 0) ? o - 8 : (char*)0)[0x58];
}
    return this;
}


inline void memCpy4_d65f(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T, class Allocator> __forceinline hkArray<T, Allocator>::~hkArray() throw()
{
    hkMemoryAllocator& mem = reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter::getInstance().heap());
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        mem.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <class T> __forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        memCpy4_d65f(m_data + index, m_data + m_iElementCount, sizeof(T));
}

struct Listener_d65f;
struct Watch2_d65f
{
    virtual void w00();
};

struct Agent_d65f
{
    void hkpWorld_removeEntityListener(Listener_d65f* listener);
    void ClearValue(Watch2_d65f* watch);
};

struct Node_d65f
{
    Agent_d65f* m_pCollisionAgent;
    hkArray<int> m_items;
    static void operator delete(void* p) throw()
    {
        reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter::getInstance().heap()).blockFree(p, sizeof(Node_d65f));
    }
};

struct Base_d65f
{
    virtual void v00();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
};

struct Listener_d65f
{
    virtual void l00();
};

struct Watch_d65f
{
    int unk00;
};

struct Phantom_d65f : Base_d65f, Listener_d65f, Watch2_d65f
{
    hkArray<Node_d65f*> m_kNodeCollection;
    void hkpShapeDisplayViewer_removeAllGeometries(int index);
    void hkpShapeDisplayViewer_removeWorld(int index);
};

// Calls FUN_00c917a0 and ClearValue on the node's collision agent with this, calls FUN_00d65750, then deletes the node and removes it from m_kNodeCollection.
// @fnv 0x00d65fc0
// src: XBOX_PDB 0x00d65fc0
void Phantom_d65f::hkpShapeDisplayViewer_removeWorld(int index)
{
    m_kNodeCollection[index]->m_pCollisionAgent->hkpWorld_removeEntityListener(this);
    m_kNodeCollection[index]->m_pCollisionAgent->ClearValue(this);
    hkpShapeDisplayViewer_removeAllGeometries(index);
    delete m_kNodeCollection[index];
    m_kNodeCollection.removeAt(index);
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
struct TtShapeDisplayBase : FUN_00d652a0_cls
{
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
};

struct TtShapeDisplayOuter;

struct TtTlsRecord
{
    const char* m_name;
    unsigned int m_uiCommandId;
    int m_spare;
};

struct TtTlsData
{
    int unk00;
    TtTlsRecord* m_cur;
    int unk08;
    TtTlsRecord* m_kRayEnd;
};

extern unsigned int g_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

struct TtShapeDisplayInner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    bool m_flag34;

    TtShapeDisplayOuter* GetOuter();
    void hkpShapeDisplayViewer_postSimulationCallback(int arg);
};

struct TtShapeDisplayOuter : TtShapeDisplayBase, TtShapeDisplayInner
{
};

__forceinline TtShapeDisplayOuter* TtShapeDisplayInner::GetOuter()
{
    return (TtShapeDisplayOuter*)((char*)this - 0x2c);
}

static void __forceinline TtPushEvent(const char* name)
{
    TtTlsData* data = (TtTlsData*)TlsGetValue(g_0126835c);
    TtTlsRecord* rec = data->m_cur;
    if (rec < data->m_kRayEnd)
    {
        rec->m_name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        rec->m_uiCommandId = t;
        data->m_cur = rec + 1;
    }
}

// Pushes a TthkpShapeDisplayViewer event, returns early if m_flag34 is false, otherwise calls GetOuter()->v10 with m_18 and arg, then pushes an Et event.
// @fnv 0x00d65520
// src: HAVOK_LIB 0x00d65520
void TtShapeDisplayInner::hkpShapeDisplayViewer_postSimulationCallback(int arg)
{
    TtPushEvent("TthkpShapeDisplayViewer");
    if (!m_flag34)
    {
        TtPushEvent("Et");
        return;
    }
    GetOuter()->v10(GetOuter()->m_18, arg);
    TtPushEvent("Et");
}

struct D661E0Primary
{
    virtual void vfunc00();
    virtual void AdjustThisAndForward_00d661e0();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct D661E0Secondary
{
    virtual void AdjustThisAndForward_00d661e0();
};

struct D661E0Object : D661E0Primary, D661E0Secondary
{
    D661E0Object();

// @fnv 0x00d661e0
// src: GUESS 0x00d661e0 (confidence: low)
    virtual void AdjustThisAndForward_00d661e0();
};

D661E0Object::D661E0Object()
{}

// sub ecx,8; jmp FUN_00d661f0: adjustor thunk from multiple inheritance.
struct PrimaryBase
{
    virtual void FUN_00d661f0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d661f0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d661f0
    virtual void FUN_00d661f0();
};

Derived::Derived()
{}

// FUN_00d66200 : MSVC this-adjusting thunk  (sub ecx, 0x28 ; jmp <impl>)
//
// Two bases declare the same virtual, so the derived class overrides one
// function for both of them and the compiler emits one adjustor thunk per
// secondary base.  The first base is padded to 40 bytes so the second
// base lands at +0x28.  The override is DECLARED ONLY, so this thunk
// is the single defined function symbol carrying the name FUN_00d66200; a defined
// key function makes the vftable that references the thunk be emitted here.
struct A1_00d66200
{
    A1_00d66200();
    virtual void AdjustThisAndForward_00d66200();
    char pad[0x24];
};

struct A2_00d66200
{
    A2_00d66200();
// @fnv 0x00d66200
// src: GUESS 0x00d66200 (confidence: low)
    virtual void AdjustThisAndForward_00d66200();
};

struct Own_00d66200 : A1_00d66200, A2_00d66200
{
    Own_00d66200();
    virtual void key_fn();  // key function - defined, so the vftable is emitted
    void AdjustThisAndForward_00d66200();    // the shared override - declared only
};

Own_00d66200::Own_00d66200()
{}
void Own_00d66200::key_fn()
{}

Own_00d66200* make_00d66200()
{
    static Own_00d66200 o;
    return &o;
}

namespace fnv_00d66210 {
// sub ecx,0x2c; jmp target == MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by sizeof(PrimaryBase) = 0x2c.
struct PrimaryBase
{
    virtual void FUN_00d66210();
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
};

struct SecondaryBase
{
    virtual void FUN_00d66210();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66210
    virtual void FUN_00d66210();
};

Derived::Derived()
{}
}  // namespace fnv_00d66210

namespace fnv_00d66220 {
struct S_00d66220_RefObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual ~S_00d66220_RefObject();
    static void operator delete(void* p, unsigned int)
    {
        S_00d66220_RefObject* o = static_cast<S_00d66220_RefObject*>(p);
        reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter::getInstance().heap()).blockFree(p, o->m_usMemSizeAndFlags);
    }
};

struct FUN_00d66220 : S_00d66220_RefObject
{
    FUN_00d66220();
    virtual ~FUN_00d66220();
};

// @fnv 0x00d66220
FUN_00d66220::FUN_00d66220()
{}
}  // namespace fnv_00d66220

struct OutVec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};

struct Visitor
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04(OutVec* out, const void* item, int g);
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
};

struct S8
{
    unsigned __int64 value;
    void* getPtr() const
    {
        return (void*)(unsigned int)value;
    }
};

struct Entry16
{
    int m_type;
    int unk04;
    void* m_p8;
    int m_iThirdValue;
};

struct SubObj
{
    void SweepTransform(float f, OutVec* out);
};

struct Item
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
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    Entry16* m_entries;
    int m_entryCount;
    bool hasProperty(int key) const
    {
        for (int i = 0; i < m_entryCount; ++i)
        {
            if (m_entries[i].m_type == key)
                return true;
        }
        return false;
    }
    S8 getProperty(int key) const
    {
        int n = m_entryCount;
        for (int i = 0; i < n; ++i)
        {
            if (m_entries[i].m_type == key)
            {
                return *(const S8*)&m_entries[i].m_p8;
            }
        }
        S8 s = {0};
        return s;
    }
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    SubObj m_e0;
};

struct ItemList
{
    Item** m_items;
    int m_uiItemCount;
};

struct Group
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
    ItemList m_kNode;
};

struct Node
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
    Group** m_28;
    int m_2c;
    float hkpWorld_getCurrentTime();
};

class S00d653f0_Obj
{
  public:
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
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    float m_68;
    void hkpShapeDisplayViewer_synchronizeTransforms_00d653f0(Visitor* a1, Node* a2);
};

// Calls a1->v04 with each item's SweepTransform result and property pointer, using m_68 (or a2->FUN_00c91020() if m_68 is not positive), between v18 and v19.
// @fnv 0x00d653f0
// src: HAVOK_LIB 0x00d653f0
void S00d653f0_Obj::hkpShapeDisplayViewer_synchronizeTransforms_00d653f0(Visitor* apVisitor, Node* apNode)
{
    float f = (m_68 > 0.0f) ? m_68 : apNode->hkpWorld_getCurrentTime();
    apVisitor->v18();
    int i = 0;
    if (apNode->m_2c > 0)
    {
        do
        {
            ItemList* pItemList = &apNode->m_28[i]->m_kNode;
            int j = 0;
            if (pItemList->m_uiItemCount > 0)
            {
                do
                {
                    Item* pItem = pItemList->m_items[j];

                    const void* p =
                        pItem->hasProperty(0x1134) ? pItem->getProperty(0x1134).getPtr() : (char*)pItem + 0x10;
                    __declspec(align(16)) OutVec sweptTransform;
                    pItem->m_e0.SweepTransform(f, &sweptTransform);
                    apVisitor->v04(&sweptTransform, p, DAT_01268fe0);
                    ++j;
                } while (j < pItemList->m_uiItemCount);
            }
            ++i;
        } while (i < apNode->m_2c);
    }
    apVisitor->v19();
}

namespace fnv_00d65750 {
struct ArrayStruct
{
    void** m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};

struct Entry
{
    int m_00;
    ArrayStruct m_aiIndexedValues;
};

struct Listener
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void FUN_v5(void* a, void* b, int c);
};

struct Singleton
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* volatile m_10;
};

extern void* g_01268fe0;
Singleton* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(void* a, ArrayStruct* arr, int sz, int elem);

struct Shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    Listener* m_pListener;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    Entry** m_pTable;
    void hkpShapeDisplayViewer_removeAllGeometries(int index);
};

// Invokes m_pListener->FUN_v5 for each item in m_pTable[index]->m_aiIndexedValues, then resets the array count to 0.
// @fnv 0x00d65750
// src: HAVOK_LIB 0x00d65750
void Shell::hkpShapeDisplayViewer_removeAllGeometries(int index)
{
    Entry* entry = m_pTable[index];
    for (int i = 0; i < entry->m_aiIndexedValues.m_iArrayLength; i++)
    {
        int nItem = (int)entry->m_aiIndexedValues.m_pData[i];
        m_pListener->FUN_v5(entry->m_aiIndexedValues.m_pData[i], g_01268fe0, *(int*)nItem);
    }
    ArrayStruct* arr = &entry->m_aiIndexedValues;
    Singleton* holder = hkMemoryRouter_getInstance();
    void* pContext = holder->m_10;
    int iCapacity = arr->m_iCapacity & 0x3fffffff;
    if (iCapacity < 0)
    {
        hkArrayUtil__reserve(pContext, arr, (iCapacity * 2) > 0 ? iCapacity * 2 : 0, 4);
    }
    arr->m_iArrayLength = 0;
}
}  // namespace fnv_00d65750

// Remove a displayed entity and its cached display geometry.
extern "C" void _ReadWriteBarrier();
// The voice object that receives the finished sample.
struct AudioVoiceHost
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(int iKey, int iGlobal, int iResult);
};
// The channel that owns a playback buffer.
struct AudioChannel
{
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(int iResult);
};
// The playback buffer itself.
struct AudioBuffer
{
    int LookupHashEntry(int iResult, int iUnused);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryAllocator* pAlloc, int iResult, int iCount);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(int iResult);
};
// One list of played items.
struct AudioItemList
{
    int unk00;
    int* m_pItems;
    int m_iArrayLength;

    __forceinline int find(int key) const
    {
        int count = m_iArrayLength;
        for (int i = 0; i < count; ++i)
        {
            if (m_pItems[i] == key)
                return i;
        }
        return -1;
    }
    __forceinline void removeAt(int i)
    {
        --m_iArrayLength;
        if (m_iArrayLength != i)
        {
            memCpy4_d65f(m_pItems + i, m_pItems + m_iArrayLength, sizeof(int));
        }
    }
};
// The sound that is being played.
struct AudioParam
{
    int unk00;
    int unk04;
    int m_i08;
    int unk0c;
    int m_i10;
    int unk14;
    int unk18;
    int unk1c;
};
// The flag the helper is given: it is a single byte but the helper reads it
// as a whole word.
union AudioFlag
{
    int m_iValue;
    char m_cValue;
};
// The sub object this method belongs to.
struct AudioNodeSub
{
    int unk00;
    int unk04;
    AudioItemList** m_pItemLists;
    int unk0c;
    int unk10;
    AudioChannel m_channel;
    int unk18;
    int unk1c;
    AudioBuffer m_buffer;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    unsigned char unk38;
    unsigned char m_bPlayed;

    void hkpShapeDisplayViewer_entityRemovedCallback(AudioParam* pParam);
};
struct DisplayPrimary
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_override10;
    int m_override14;
    AudioVoiceHost* m_display;
    int unk1c;
    int unk20;
    int unk24;
};
struct DisplayOuter : DisplayPrimary, AudioNodeSub
{
};
static DisplayOuter* GetDisplayOuter(AudioNodeSub* p)
{
    return (DisplayOuter*)((char*)p - sizeof(DisplayPrimary));
}
extern int DAT_01268fe0;
struct S_00c6d840_Q : S_00c6d840
{
    S_00c6d840_Pair FindEntry(int key, int unused);
};
struct FUN_00d655e0_Q : FUN_00d655e0_class
{
    int FindItemIndex(int key);
};
void* __cdecl GetProperty1134(D66180Entity* e);
// Module local helper: it is called from exactly one place, so the compiler
// hands it the sound in EAX and keeps the two other arguments on the stack.
// Resolves a display result for pParam, notifies the voice host, adjusts the audio buffer, and removes the matching item from the item list.
// @fnv 0x00d65640
// src: HAVOK_LIB 0x00d65640
void AudioNodeSub::hkpShapeDisplayViewer_entityRemovedCallback(AudioParam* pParam)
{
    AudioNodeSub* self = this;
    int iResult;
    bool checkOverride = GetDisplayOuter(self)->m_override10 == 0 && GetDisplayOuter(self)->m_override14 == 0;
    bool usedDefault;
    iResult = _getProxyShape((S_00c6d840*)pParam, checkOverride, &usedDefault);

    FUN_00d655e0_Q* pList = (FUN_00d655e0_Q*)((char*)self - 0x28);
    int iIndex = pList->FindItemIndex(pParam->m_i08);
    if (iIndex < 0)
    {
        return;
    }

    AudioItemList* pItems = self->m_pItemLists[iIndex];
    int displayResult = iResult;
    if (!displayResult)
        displayResult = pParam->m_i10;

    iResult = displayResult;
    int iKey = (int)(size_t)GetProperty1134((D66180Entity*)pParam);
    AudioVoiceHost* pVoiceHost = GetDisplayOuter(self)->m_display;
    pVoiceHost->v14(iKey, DAT_01268fe0, iResult);

    if (self->m_bPlayed && iResult)
    {
        int iCount = self->m_buffer.LookupHashEntry(iResult, 0);
        iCount = iCount - 1;
        if (iCount == 0)
        {
            self->m_channel.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(iResult);
            self->m_buffer.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(iResult);
        }
        else
        {
            hkMemoryRouter* pHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
            self->m_buffer.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap), iResult, iCount);
        }
    }

    int i = pItems->find(iKey);
    if (i >= 0)
    {
        _ReadWriteBarrier();
        pItems->removeAt(i);
    }
}

struct S_00d65970_Item;

inline void* __cdecl operator new(unsigned int, void* where) throw()
{
    return where;
}



struct S_00d65970_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    hkArray<S_00d65970_Item*> items;
};

struct S_00d65970_B28;
struct S_00d65970_B2c;

struct S_00d65970_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00d65970_Elem* unk20;
    int unk24;
    S_00d65970_Elem** unk28;
    int unk2c;
    int unk30;
    S_00d65970_Elem** unk34;
    int unk38;
    void hkpWorld_addEntityListener(S_00d65970_B28* l);
    void hkpWorld_addWorldPostSimulationListener(S_00d65970_B2c* l);
};

struct S_00d65970_Node
{
    S_00d65970_Arg* arg;
    hkArray<S_00d65970_Item*> arr;
    S_00d65970_Node()
    {}
};



void ResizeAudioStream(hkMemoryAllocator* heap, void* arr, int elemSize);

struct S_00d65970_Base0
{
    virtual void vfn0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};

struct S_00d65970_B28
{
    virtual void vfn0();
    virtual void vfn1(S_00d65970_Item* item);
};

struct S_00d65970_B2c
{
    int unk00;
};

struct S_00d65970_Obj : S_00d65970_Base0, S_00d65970_B28, S_00d65970_B2c
{
    hkArray<S_00d65970_Node*> nodes;
    void hkpShapeDisplayViewer_addWorld(S_00d65970_Arg* arg);
};

// Creates a node from arg, appends it to the nodes array, and calls vfn1 on all items in arg's element arrays.
// @fnv 0x00d65970
// src: XBOX_PDB 0x00d65970
void S_00d65970_Obj::hkpShapeDisplayViewer_addWorld(S_00d65970_Arg* arg)
{
    arg->hkpWorld_addEntityListener(this);
    arg->hkpWorld_addWorldPostSimulationListener(this);
    hkMemoryAllocator& heap = reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter::getInstance().heap());
    void* mem = heap.blockAlloc(0x10);
    S_00d65970_Node* node = new (mem) S_00d65970_Node;
    node->arg = arg;
    hkArray<S_00d65970_Node*>& arr = nodes;
    hkMemoryRouter* router = &hkMemoryRouter::getInstance();
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&reinterpret_cast<hkMemoryAllocator&>(router->heap()), &arr, 4);
    S_00d65970_Node** p = arr.m_data + arr.m_iElementCount;
    for (int k = 0; k < 1; k++)
        p[k] = node;
    arr.m_iElementCount++;
    for (int i = 0; i < arg->unk2c; i++)
    {
        hkArray<S_00d65970_Item*>& items = arg->unk28[i]->items;
        for (int j = 0; j < items.m_iElementCount; j++)
            vfn1(items.m_data[j]);
    }
    for (int i = 0; i < arg->unk38; i++)
    {
        hkArray<S_00d65970_Item*>& items = arg->unk34[i]->items;
        for (int j = 0; j < items.m_iElementCount; j++)
            vfn1(items.m_data[j]);
    }
    S_00d65970_Elem* e = arg->unk20;
    if (e)
    {
        for (int j = 0; j < e->items.m_iElementCount; j++)
            vfn1(e->items.m_data[j]);
    }
}
