// gamebryo2.2/corelibs/nimain/nialphaaccumulator.cpp: NiAlphaAccumulator (17 functions)

#include "../../../../include/NiAccumulator.h"
#include "../../../../include/NiAlphaAccumulator.h"
#include "../../../../include/NiBackToFrontAccumulator.h"

extern "C" unsigned int kVtbl_NiBackToFrontAccumulator;

// Initializes the shared accumulator layout using the original constructor's register ABI.
NiAccumulator* __fastcall InitializeAccumulator(NiAccumulator*) throw();

// @fnv 0x00aa0f00
__declspec(noinline) NiBackToFrontAccumulator* __fastcall InitializeBackToFrontAccumulator(NiBackToFrontAccumulator* self)
{
    InitializeAccumulator(self);
    *(volatile unsigned int*)self = (unsigned int)&kVtbl_NiBackToFrontAccumulator;
    volatile NiBackToFrontAccumulator* fields = self;
    fields->m_kItems.m_kItemCount.m_uiCount = 0;
    fields->m_kItems.m_pkHead = 0;
    fields->m_kItems.m_pkTail = 0;
    fields->m_kItemsToSortAndRender = 0;
    fields->m_iNumItems = 0;
    fields->m_iMaxItems = 0;
    fields->m_ppkItems = 0;
    fields->m_pfDepths = 0;
    return self;
}

extern float DAT_01096b8c;
extern int EmptyFS;
extern int DAT_011a8400;
extern int DAT_011a8404;
extern int DAT_011a8408;
extern int DAT_011f3704;
extern int DAT_011f3708;
extern int DAT_011f370c;
extern int DAT_011f3710;

struct DummyObj
{
    int f00, f04, f08;
    int f0c, f10, f14, f18;
    float f1c;
    int f20, f24, f28;
    int f2c, f30, f34, f38;
    float f3c;
    int f40;
};

// @fnv 0x00a433b0
DummyObj* __fastcall InitFromGlobals(DummyObj* pThis)
{
    pThis->f00 = DAT_011a8400;
    pThis->f04 = DAT_011a8404;
    pThis->f08 = DAT_011a8408;
    pThis->f0c = DAT_011f3704;
    pThis->f10 = DAT_011f3708;
    pThis->f14 = DAT_011f370c;
    pThis->f18 = DAT_011f3710;
    pThis->f1c = DAT_01096b8c;
    pThis->f20 = DAT_011a8400;
    pThis->f24 = DAT_011a8404;
    pThis->f28 = DAT_011a8408;
    pThis->f2c = DAT_011f3704;
    pThis->f30 = DAT_011f3708;
    pThis->f34 = DAT_011f370c;
    pThis->f38 = DAT_011f3710;
    pThis->f3c = DAT_01096b8c;
    pThis->f40 = EmptyFS;
    return pThis;
}

struct FUN_00a43350_shell
{
    unsigned int BSTreadTransfInterpolator_GetKeyContent(unsigned short usChannel);
};
// @fnv 0x00a43350
// src: XBOX_PDB 0x00a43350
unsigned int FUN_00a43350_shell::BSTreadTransfInterpolator_GetKeyContent(unsigned short usChannel)
{
    return usChannel ? 6 : 0;
}

struct GlobalObjectO2_00a7b610
{
    char c;
};
extern GlobalObjectO2_00a7b610 g_011f3ed8;
// Returns the address of the global object g_011f3ed8.
// @fnv 0x00a43360
// src: COMMUNITY 0x00a43360
GlobalObjectO2_00a7b610* __cdecl BSTreadTransfInterpolator_GetRTTI()
{
    return &g_011f3ed8;
}

struct FUN_00a43450_fs
{
    char* pszString;
};
struct FUN_00a43450_stream
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void RegisterFixedString(FUN_00a43450_fs* kString);
};
struct FUN_00a43450_data
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual bool RegisterStreamables(FUN_00a43450_stream& kStream);
};
struct FUN_00a43450_link
{
    char pad[0x40];
    FUN_00a43450_fs kName;
};
struct FUN_00aa0ad0_base
{
    bool BSPackedAdditionalGeometryData_RegisterStreamables(FUN_00a43450_stream* arStream);
};
struct FUN_00a43450_shell : FUN_00aa0ad0_base
{
    char pad[0xc - 1];
    FUN_00a43450_link* Links;
    unsigned int m_uiLinkCount;
    char pad2[0x20 - 0x14];
    FUN_00a43450_data* m_pData;
    bool BSTreadTransfInterpolator_RegisterStreamables(FUN_00a43450_stream* arStream);
};
// Calls the base register, then registers each link's name string and the data object's streamables with the stream; returns the base result.
// @fnv 0x00a43450
// src: XBOX_PDB 0x00a43450
bool FUN_00a43450_shell::BSTreadTransfInterpolator_RegisterStreamables(FUN_00a43450_stream* arStream)
{
    bool bret = BSPackedAdditionalGeometryData_RegisterStreamables(arStream);
    if (bret)
    {
        for (unsigned int ui = 0; ui < m_uiLinkCount; ui++)
            arStream->RegisterFixedString(&Links[ui].kName);
        FUN_00a43450_data* pkLerp = m_pData;
        if (pkLerp)
            pkLerp->RegisterStreamables(*arStream);
    }
    return bret;
}

// The base equality thunk returns a byte, which the alpha override normalizes.
char __stdcall NiBackToFrontAccumulator_IsEqual(NiObject*);
// @fnv 0x00a9b510
bool NiAlphaAccumulator::IsEqual(NiObject* pkObject) const
{
    bool b = NiBackToFrontAccumulator_IsEqual(pkObject) != 0;
    return b;
}

extern const char* const g_011fa000_arg1;
// @fnv 0x00a9b530
const NiRTTI* NiAlphaAccumulator::GetRTTI() const
{
    return (const NiRTTI*)&g_011fa000_arg1;
}

void* __cdecl Object_DispatchCommandFour(unsigned int);

struct Base0_a43370
{
    virtual void v0();
    int unk04;
    int unk08;
    Base0_a43370() throw();
};

struct Base1_a43370 : Base0_a43370
{
    int unk0c;
    int unk10;
    float unk14;
    float unk18;
    int unk1c;
    Base1_a43370() throw() : unk0c(0), unk10(0), unk14(0.0f), unk18(0.0f), unk1c(0)
    {}
};

struct Ptr_a43370
{
    void* p;
    Ptr_a43370() throw() : p(0)
    {}
};

struct Derived_a43370 : Base1_a43370
{
    Ptr_a43370 unk20;
    Derived_a43370() throw()
    {}
    static void* __cdecl operator new(unsigned int s) throw()
    {
        return Object_DispatchCommandFour(s);
    }
};

// Allocates and default-constructs a Derived_a43370 object via its operator new and returns the pointer.
// @fnv 0x00a43370
Derived_a43370* __cdecl CreateDerivedA43370()
{
    return new Derived_a43370();
}

extern int DAT_011f4748;

struct FUN_00b58570_Class
{
    void* __thiscall NiTPointerListBase_AddTail(void* arg);
};

struct FUN_00a9b850_Prop
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    union
    {
        unsigned char unk18;
        unsigned short unk18w;
    };
};

struct FUN_00a9b850_Obj
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00C();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01C();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02C();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03C();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04C();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05C();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06C();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07C();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08C();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09C();
    virtual void vfn_0A0();
    virtual void vfn_0A4();
    virtual void vfn_0A8();
    virtual void vfn_0AC();
    virtual void vfn_0B0();
    virtual void vfn_0B4();
    virtual void vfn_0B8();
    virtual void vfn_0BC();
    virtual void vfn_0C0();
    virtual void vfn_0C4();
    virtual void vfn_0C8();
    virtual void vfn_0CC();
    virtual void vfn_0D0();
    virtual void vfn_0D4();
    virtual void vfn_0D8();
    virtual void vfn_0DC(int arg);
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
    unsigned int unk30;
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
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    FUN_00a9b850_Prop* m9c;
};

// @fnv 0x00a9b850
bool NiAlphaAccumulator::RegisterObject(NiGeometry* pkObject)
{
    FUN_00a9b850_Obj*& pObject = reinterpret_cast<FUN_00a9b850_Obj*&>(pkObject);
    FUN_00a9b850_Prop* p = pObject->m9c;
    int g = DAT_011f4748;
    if ((p->unk18 & 1) && (!m_bObserveNoSortHint || !((unsigned char)(p->unk18w >> 13) & 1)) &&
        ((unsigned char)~(pObject->unk30 >> 6) & 1))
    {
        reinterpret_cast<FUN_00b58570_Class*>(&m_kItems)->NiTPointerListBase_AddTail(&pObject);
        return true;
    }
    pObject->vfn_0DC(g);
    return true;
}

void NiKeyBasedInterpolator_LinkObject();
// @fnv 0x00a43330
// src: COMMUNITY 0x00a43330
void j_j_j_nullsub_3()
{
    NiKeyBasedInterpolator_LinkObject();
}

struct C8CCC0Base
{
    bool IsEqual(const C8CCC0Base&) const;
};
struct FUN_00a43340 : C8CCC0Base
{
    bool IsEqual(const FUN_00a43340&);
};
// @fnv 0x00a43340
bool FUN_00a43340::IsEqual(const FUN_00a43340& apObject)
{
    return C8CCC0Base::IsEqual(apObject);
}

void __cdecl NiKeyBasedInterpolator_LoadBinary();
// @fnv 0x00a9b4f0
// src: XBOX_PDB 0x00a9b4f0
void __cdecl NiAlphaAccumulator_LoadBinary()
{
    NiKeyBasedInterpolator_LoadBinary();
}

void __cdecl BSPackedAdditionalGeometryData_RegisterStreamables();
// @fnv 0x00a9b500
// src: XBOX_PDB 0x00a9b500
void __cdecl NiAlphaAccumulator_RegisterStreamables()
{
    BSPackedAdditionalGeometryData_RegisterStreamables();
}

struct S00a9b570_Pt
{
    float x, y, z;
};
struct S00a9b570_Bound
{
    S00a9b570_Pt m_kCenter;
    float m_fBoundRadius;
};
extern S00a9b570_Bound DAT_011f4288;
void __cdecl _NiFree_00aa10f0(void* p);
void* __cdecl _NiMalloc_00aa1070(unsigned int n);

inline float S00a9b570_Dot(const S00a9b570_Pt& a, const S00a9b570_Pt& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline float S00a9b570_Closest(const float& r, const S00a9b570_Pt& c, const S00a9b570_Pt& d)
{
    return S00a9b570_Dot(c, d) - r;
}

struct S00a9b570_Mat
{
    float m_afEntries[3][3];
    void GetCol(unsigned int c, S00a9b570_Pt& p) const
    {
        p.x = m_afEntries[0][c];
        p.y = m_afEntries[1][c];
        p.z = m_afEntries[2][c];
    }
};

struct S00a9b570_Cam
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
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    S00a9b570_Mat m_kRotate;
    S00a9b570_Pt GetWorldTranslation() const
    {
        S00a9b570_Pt d;
        m_kRotate.GetCol(0, d);
        return d;
    }
};

struct S00a9b570_Geom
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    S00a9b570_Bound* volatile m_pkBound;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    int unk84, unk88, unk8c;
    float m_fFogDepth;
    const S00a9b570_Bound& GetBoundingVolume() const
    {
        const S00a9b570_Bound* p = m_pkBound;
        return p ? *p : DAT_011f4288;
    }
};

class ItemListNode
{
  public:
    ItemListNode* m_pkNext;
    ItemListNode* m_pkPrev;
    NiGeometry* m_element;
};

static inline NiGeometry* const& GetNext(ItemListNode*& pos)
{
    NiGeometry* const& e = pos->m_element;
    pos = pos->m_pkNext;
    return e;
}

// @fnv 0x00a9b570
void NiAlphaAccumulator::Sort()
{
    if (!m_kItemsToSortAndRender)
        m_kItemsToSortAndRender = &m_kItems;
    m_iNumItems = m_kItemsToSortAndRender->m_kItemCount.m_uiCount;
    if (m_iNumItems == 0)
        return;
    if (m_iNumItems > m_iMaxItems)
    {
        _NiFree_00aa10f0(m_ppkItems);
        m_iMaxItems = m_iNumItems;
        m_ppkItems = (NiGeometry**)_NiMalloc_00aa1070(m_iMaxItems * sizeof(NiGeometry*));
        _NiFree_00aa10f0(m_pfDepths);
        m_pfDepths = (float*)_NiMalloc_00aa1070(m_iMaxItems * sizeof(float));
    }
    ItemListNode* kPos = m_kItemsToSortAndRender->m_pkHead;
    S00a9b570_Pt kViewDir = reinterpret_cast<const S00a9b570_Cam*>(m_pkCamera)->GetWorldTranslation();
    int i;
    if (m_bInterfaceSort)
    {
        for (i = 0; i < m_iNumItems; i++)
        {
            m_ppkItems[i] = GetNext(kPos);
            m_pfDepths[i] = reinterpret_cast<S00a9b570_Geom*>(m_ppkItems[i])->m_fFogDepth;
        }
    }
    else if (m_bSortByClosestPoint)
    {
        for (i = 0; i < m_iNumItems; i++)
        {
            m_ppkItems[i] = GetNext(kPos);
            S00a9b570_Geom* g = reinterpret_cast<S00a9b570_Geom*>(m_ppkItems[i]);
            m_pfDepths[i] =
                S00a9b570_Closest(g->GetBoundingVolume().m_fBoundRadius, g->GetBoundingVolume().m_kCenter, kViewDir);
        }
    }
    else
    {
        for (i = 0; i < m_iNumItems; i++)
        {
            m_ppkItems[i] = GetNext(kPos);
            m_pfDepths[i] = S00a9b570_Dot(reinterpret_cast<S00a9b570_Geom*>(m_ppkItems[i])->GetBoundingVolume().m_kCenter, kViewDir);
        }
    }
    QuickSort(0, m_iNumItems - 1);
}

// @fnv 0x00a9b540
NiAlphaAccumulator::~NiAlphaAccumulator()
{}

class NiRenderer;
namespace fnv_00a9b790 {
extern NiRenderer* DAT_011f4748;

struct S00a9b790_NodeAllocator
{
    ItemListNode* NiGeometry_AddProperty();
};

class S00a9b790_NiAlphaProperty
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short m_uiObjectFlags;
    bool GetAlphaBlending() const
    {
        return (m_uiObjectFlags & 1) != 0;
    }
    bool GetNoSorter() const
    {
        return ((m_uiObjectFlags >> 13) & 1) != 0;
    }
};

class S00a9b790_NiGeometry
{
  public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void RenderImmediate(NiRenderer* pkRenderer);

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
    unsigned int m_uiObjectFlags;
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
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    S00a9b790_NiAlphaProperty* m_pkAlpha;

    bool GetSortObject() const
    {
        return !((m_uiObjectFlags >> 6) & 1);
    }
    const S00a9b790_NiAlphaProperty* GetAlpha() const
    {
        return m_pkAlpha;
    }
};

class S00a9b790_NiVisibleArray
{
  public:
    S00a9b790_NiGeometry** m_ppSavableObjects;
    unsigned int m_uiNextBlockSize;
    unsigned int GetCount() const
    {
        return m_uiNextBlockSize;
    }
    S00a9b790_NiGeometry& GetAt(unsigned int i) const
    {
        return *m_ppSavableObjects[i];
    }
};

static inline void AddTail(NiAlphaAccumulator* self, S00a9b790_NiGeometry* pkObject)
{
    ItemListNode* pkNode = ((S00a9b790_NodeAllocator*)&self->m_kItems.m_kItemCount)->NiGeometry_AddProperty();
    pkNode->m_element = reinterpret_cast<NiGeometry*>(pkObject);
    pkNode->m_pkNext = 0;
    pkNode->m_pkPrev = self->m_kItems.m_pkTail;
    ItemListNode* pkTail = self->m_kItems.m_pkTail;
    if (pkTail)
        pkTail->m_pkNext = pkNode;
    else
        self->m_kItems.m_pkHead = pkNode;
    self->m_kItems.m_kItemCount.m_uiCount++;
    self->m_kItems.m_pkTail = pkNode;
}

}  // namespace fnv_00a9b790

// @fnv 0x00a9b790
void NiAlphaAccumulator::RegisterObjectArray(NiVisibleArray* array)
{
    using namespace fnv_00a9b790;
    S00a9b790_NiVisibleArray& kArray = reinterpret_cast<S00a9b790_NiVisibleArray&>(*array);
    ::NiRenderer* pkRenderer = fnv_00a9b790::DAT_011f4748;
    const unsigned int uiQuantity = kArray.GetCount();
    for (unsigned int i = 0; i < uiQuantity; i++)
    {
        S00a9b790_NiGeometry& kObject = kArray.GetAt(i);
        const S00a9b790_NiAlphaProperty* pkAlpha = kObject.GetAlpha();
        if (pkAlpha->GetAlphaBlending() && !(m_bObserveNoSortHint && pkAlpha->GetNoSorter()) &&
            kObject.GetSortObject())
        {
            AddTail(this, &kObject);
        }
        else
        {
            kObject.RenderImmediate(pkRenderer);
        }
    }
}

extern unsigned int kVtbl_NiAlphaAccumulator;

// Allocates a NiAlphaAccumulator clone, initializes it, copies skip flags, and returns the new object.
// @fnv 0x00a9b730
NiObject* NiAlphaAccumulator::MakeClone(CloningProcess& cloning)
{
    NiAlphaAccumulator* clone = (NiAlphaAccumulator*)Object_DispatchCommandFour(sizeof(NiAlphaAccumulator));
    if (clone)
    {
        InitializeBackToFrontAccumulator(clone);
        *(unsigned int*)clone = (unsigned int)&kVtbl_NiAlphaAccumulator;
        clone->m_bObserveNoSortHint = true;
        clone->m_bSortByClosestPoint = false;
        clone->m_bInterfaceSort = false;
    }
    else
    {
        clone = 0;
    }
    CopyMemberData(clone, cloning);
    clone->m_bObserveNoSortHint = m_bObserveNoSortHint;
    clone->m_bSortByClosestPoint = m_bSortByClosestPoint;
    return (NiObject*)clone;
}
