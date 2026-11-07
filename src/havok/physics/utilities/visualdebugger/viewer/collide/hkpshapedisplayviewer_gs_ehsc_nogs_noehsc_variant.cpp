#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkProcessFactory.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkArray.h"


// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

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
void* __cdecl hkMemoryRouter_getInstance();
struct FUN_00d657d0_class
{
    FUN_00d657d0_class* hkpShapeDisplayViewer_hkpShapeDisplayViewer(int);
};
void* __cdecl hkpShapeDisplayViewer_create(void* context);
struct GlobalObjectO2_00d472a0
{
};
extern hkProcessFactory* hkProcessFactory_registerProcess;
extern GlobalObjectO2_00d472a0 g_01268f2c;
extern void* __cdecl hkpShapeDisplayViewer_create(void*);
void RegisterShapesProcess();
struct Target
{
    void hkpShapeDisplayViewer_addWorld();
};
struct Adjustor
{
    void ForwardCall_00d65fb0();
};
extern int g_D661D0Value;
int __cdecl Hkpshapedisplayviewer_GetD661D0Value();
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
extern int vftbl_010d1b04;
extern int vftbl_010d1ae4;
extern int vftbl_010d1ad4;
extern int vftbl_010d1ab8;
extern int vftbl_010d1aa8;
extern int vftbl_010ccf7c;
extern int vftbl_0102f13c;
struct BSAudio;
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
void* __cdecl GetProperty1134(D66180Entity* entity);
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
        hkMemoryAllocator* alloc = reinterpret_cast<hkMemoryAllocator*>((&holder->heap()));
        return alloc->blockAlloc(size);
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
static inline bool HasProperty(const S_00c6d840* props, int key)
{
    for (int i = 0; i < props->m_uiItemCount; i++)
    {
        if (props->m_entries[i].m_key == key)
            return true;
    }
    return false;
}
static int _getProxyShape(S_00c6d840* props, bool checkOverride, bool* usedDefault);
int PropertyQueryCaller(S_00c6d840* props, bool checkOverride, bool* usedDefault);
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
inline hkMemoryAllocator& getMemory_d65f()
{
    return *reinterpret_cast<hkMemoryAllocator*>(&static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->heap());
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
        getMemory_d65f().blockFree(p, sizeof(Node_d65f));
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

#include <xmmintrin.h>
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/BSAudio.h"
__forceinline hkMemoryRouter& s65Router()
{
    return *static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
}

__forceinline hkMemoryAllocator& s65Heap()
{
    return *reinterpret_cast<hkMemoryAllocator*>(&static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->heap());
}

struct S65_Pair
{
    unsigned __int64 bits;
    S65_Pair()
    {}

    int integer() const
    {
        return (int)bits;
    }
    void* pointer() const
    {
        return (void*)(unsigned long)bits;
    }
};
struct S65_Param : S_00c6d840
{
    int p80;
    int p84;
    int p88;
    int p8c;
    int p90;
    int p94;
    int p98;
    int p9c;
    int pa0;
    int pa4;
    int pa8;
    int pac;
    int pb0;
    int pb4;
    int pb8;
    int pbc;
    int pc0;
    int pc4;
    int pc8;
    int pcc;
    int pd0;
    int pd4;
    int pd8;
    int pdc;
    int pe0;
    int pe4;
    unsigned char motionType;
    unsigned char pe9;
    unsigned char pea;
    unsigned char peb;
    int pec;
    int transform;
    S65_Pair FindEntry(int key, int unused);
    __forceinline void* pointerProperty(int key)
    {
        return FindEntry(key, 0).pointer();
    }
    __forceinline int integerProperty(int key)
    {
        return FindEntry(key, 0).integer();
    }
    S65_Pair hkpWorldObject_removeProperty(int key);
    bool has(int key) const
    {
        for (int i = 0; i < m_uiItemCount; ++i)
            if (m_entries[i].m_key == key)
                return true;
        return false;
    }
};

struct S65_Map
{
    int s00;
    int s04;
    int s08;
    unsigned int LookupHashEntry(void* key, int def);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryAllocator* a, void* key, int val);
    __forceinline void insert(void* key, int val)
    {
        hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(&s65Heap(), key, val);
    }
};
struct S65_Ref
{
    void FUN_00c905b0();
};
struct S65_Val
{
    int phi;
    int theta;
    void hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment();
};
struct S65_Str
{
    int s00;
    int s04;
    int s08;
    void FUN_00cb1600(char* buf, int size);
    void ProcessAndReturnValue_00cc01c0(const char* s);
    void FUN_00cc00e0();
};
struct S65_Elem
{
    virtual ~S65_Elem();
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
};
struct S65_Vec
{
    S65_Elem** data;
    int count;
    int cap;
    S65_Elem* inlineBuf[8];
};
struct S65_Work
{
    int w00;
    int w04;
    int w08;
    int w0c;
    int w10;
    void hkpShapeDisplayBuilder_hkpShapeDisplayBuilder(S65_Val* p);
    void UpdateState_00de0f90(void* v, S65_Vec* vec);
};
union S65_V4
{
    __m128 q;
    float f[4];
};
struct S65_NewObj
{
    int n00;
    short s04;
    short s06;
    int n08;
    int n0c;
    S65_V4 c0;
    S65_V4 c1;
    S65_V4 c2;
    S65_V4 t;
    S65_NewObj* FUN_00de1d20(void* v);
    float& cell(int row, int col)
    {
        return ((float*)&c0)[col * 4 + row];
    }
};
struct S65_Host
{
    virtual void v00();
    virtual void v04(S65_Vec* out, void* arg, void* nv, int glob, void* saved);
    virtual void v08(int a, void* arg, void* nv, int glob, void* saved);
    virtual void v0c(int val, void* nv, int glob);
};
struct S65_Err
{
    virtual void d00();
    virtual void d04();
    virtual void d08();
    virtual void d0c(int a, int b, const char* buf, const char* s, int n);
};
struct S65_IntArr
{
    int* data;
    int count;
    int cap;
};
struct S65_Item
{
    int i00;
    S65_IntArr arr;
};

extern S65_Err* DAT_01268360;
extern const char str_010d196c[];
extern const char str_010d1b18[];

// src: HAVOK_LIB 0x00d652c0
static __declspec(noinline) void* _getProxyShape(S65_Param* p, bool flag, unsigned char* out)
{
    void* base = p->pointerProperty(0x1135);
    void* alt = p->pointerProperty(0x1235);
    void* over = p->pointerProperty(0x1234);
    *out = 0;
    if (flag && p->has(0x1234))
    {
        if (!over)
            *out = 1;
        return (void*)over;
    }
    if (p->has(0x1235))
    {
        if (!alt)
            *out = 1;
        return (void*)alt;
    }
    if (p->has(0x1135))
    {
        if (!base)
            *out = 1;
        return (void*)base;
    }
    return 0;
}

struct S65_Prim
{
    virtual void p00();
    int o04;
    int o08;
    int o0c;
    int f10;
    int f14;
    S65_Host* host;
    int o1c;
    int o20;
    int o24;
    int FindItemIndex(int key);
};
struct S65_Sec
{
    virtual void hkpShapeDisplayViewer_entityAddedCallback(S65_Param* param);
};
struct S65_Self : S65_Prim, S65_Sec
{
    int t04;
    S65_Item** m_items;
    int t0c;
    int t10;
    S65_Map sub14;
    S65_Map sub20;
    S65_Map sub2c;
    unsigned char b38;
    unsigned char b39;
    unsigned char b3a;
    unsigned char b3b;
    unsigned char b3c;
    unsigned char b3d;
    unsigned char b3e;
    unsigned char b3f;
    int t40;
    int f44;
    int f48;
    void hkpShapeDisplayViewer_entityAddedCallback(S65_Param* param);
};

inline void* operator new(unsigned int, void* p)
{
    return p;
}

// @fnv 0x00d65ad0
// src: XBOX_PDB 0x00d65ad0
void S65_Self::hkpShapeDisplayViewer_entityAddedCallback(S65_Param* param)
{
    unsigned char done;
    bool flag = (f10 == 0 && f14 == 0) ? true : false;
    void* ret = _getProxyShape(param, flag, &done);
    if (done)
        return;
    int idx = FindItemIndex(param->unk08);
    if (idx < 0)
        return;
    S65_Item* item = m_items[idx];
    void* key = ret;
    if (!key)
        key = (void*)param->unk10;
    if (!key)
        return;
    bool isNew = false;
    if (b3a)
    {
        unsigned int r = sub2c.LookupHashEntry(key, 0);
        isNew = r > 0;
        if (!r)
            sub2c.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(reinterpret_cast<hkMemoryAllocator*>(s65Router().m_heap), key, 1);
    }
    int existing = 0;
    if (b39)
        existing = sub14.LookupHashEntry(key, 0);
    S65_Vec vec;
    vec.data = vec.inlineBuf;
    vec.count = 0;
    vec.cap = (int)0x80000008;
    bool keep = true;
    if (!existing && !isNew && b3b && b3c)
    {
        void* a = param->pointerProperty(0x1136);
        void* alt = param->pointerProperty(0x1131);
        if (!a && !alt)
        {
            S65_Val val;
            val.hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment();
            S65_Work work;
            work.hkpShapeDisplayBuilder_hkpShapeDisplayBuilder(&val);
            work.UpdateState_00de0f90(key, &vec);
            for (int i = vec.count - 1; i >= 0; i--)
            {
                S65_Elem* e = vec.data[i];
                if (e->f50 == 6 && e->f08 == 0)
                {
                    __declspec(align(16)) char buf[0x200];
                    S65_Str str;
                    str.FUN_00cb1600(buf, 0x200);
                    str.ProcessAndReturnValue_00cc01c0(str_010d196c);
                    DAT_01268360->d0c(0, -1, buf, str_010d1b18, 0x13c);
                    str.FUN_00cc00e0();
                    vec.count--;
                    if (vec.count != i)
                        vec.data[i] = vec.data[vec.count];
                }
            }
            void* v = param->pointerProperty(0x1135);
            if (v && (void*)v == ret)
            {
                ((S65_Ref*)v)->FUN_00c905b0();
                param->hkpWorldObject_removeProperty(0x1135);
            }
        }
        else
        {
            keep = a == 0;
            if (alt)
                param->hkpWorldObject_removeProperty(0x1131);
            S65_NewObj* mem = (S65_NewObj*)s65Heap().blockAlloc(0x60);
            mem->s04 = (short)0x60;
            S65_NewObj* obj = mem->FUN_00de1d20(a ? a : alt);
            obj->c0.q = _mm_setzero_ps();
            obj->c1.q = _mm_setzero_ps();
            obj->c2.q = _mm_setzero_ps();
            obj->cell(0, 0) = 1.0f;
            obj->cell(1, 1) = 1.0f;
            obj->cell(2, 2) = 1.0f;
            obj->t.q = _mm_setzero_ps();
            hkArrayConstruct(vec.data + vec.count, 1, (S65_Elem*)obj);
            ++vec.count;
        }
    }
    void* nv = GetProperty1134((D66180Entity*)param);
    S65_IntArr* arr = &item->arr;
    hkMemoryRouter* heap = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    if (arr->count == (arr->cap & 0x3fffffff))
        ResizeAudioStream(heap->m_heap, arr, 4);
    int* slot = arr->data + arr->count;
    __assume(slot != 0);
    new (slot) int((int)nv);
    arr->count++;
    if (!existing)
    {
        if (vec.count > 0 || isNew || !b3c)
        {
            host->v04(&vec, &param->transform, nv, DAT_01268fe0, key);
            if (b39)
            {
                sub14.insert(key, (int)nv);
                sub20.insert(key, 1);
            }
            int val = param->integerProperty(0x1130);
            if (b3d)
            {
                if (b3e || !val)
                    val = (param->motionType == 5) ? f44 : f48;
            }
            if (val)
                host->v0c(val, nv, DAT_01268fe0);
        }
    }
    else
    {
        int n = sub20.LookupHashEntry(key, 1) + 1;
        sub20.insert(key, n);
        host->v08(existing, &param->transform, nv, DAT_01268fe0, key);
    }
    for (int i = 0; i < vec.count; i++)
    {
        if (!keep)
            vec.data[i]->f08 = 0;
        delete vec.data[i];
    }
    hkMemoryAllocator& al = s65Heap();
    vec.count = 0;
    if ((vec.cap & 0x80000000) == 0)
        al.bufFree(vec.data, (vec.cap & 0x3fffffff) * 4);
}
