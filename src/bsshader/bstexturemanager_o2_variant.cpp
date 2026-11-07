#include "../../include/NiTListItem.h"
#include "../../include/NiTPointerListBase.h"
#include "../../include/NiTListItem.h"
#include "../../include/NiTArray.h"

// src/bsshader/bstexturemanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/bstexturemanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/NiPointer.h"
#include "../../include/BSMultiBound.h"
#include "../../include/NiRenderer.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiDepthStencilBuffer.h"
// WaterTintRecord_bstexturemanager_o2_variant: local type (was include/WaterTintRecord.h, which had no evidence of one real class); no method of it is bound to a named game function
struct WaterTintRecord_bstexturemanager_o2_variant
{
    float r;
    float g;
    float b;
    float a;

    WaterTintRecord_bstexturemanager_o2_variant(float fR, float fG, float fB, float fA)
        : r(fR), g(fG), b(fB), a(fA)
    {}
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

// Preserve the reference-count operations that were inline in NiObject.h.
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}


// Preserve the smart-pointer operations that were inline in layout_support.h.
template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{}

template <class T> inline NiPointer<T>::NiPointer(T* pkNew)
{
    m_pObject = pkNew;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::NiPointer(const NiPointer<T>& kSrc)
{
    m_pObject = kSrc.m_pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

extern WaterTintRecord_bstexturemanager_o2_variant g_waterTintRecords[];
void SetWaterTintRecord(int index, WaterTintRecord_bstexturemanager_o2_variant tint);

extern MemoryManager _g_memoryManager;

struct FUN_00b6dd00_Item
{
    NiRefObject* m_pkRef;     // +0x00
    int m_iPad04;             // +0x04
    int m_iPad08;             // +0x08
    unsigned int m_uiValue1;  // +0x0c
    unsigned char m_uc10;     // +0x10
    char m_cPad11[3];
};

struct FUN_00b6dd00_Node
{
    FUN_00b6dd00_Node* m_pkNext;  // +0x00
    void* m_pvPad04;              // +0x04
    FUN_00b6dd00_Item* m_pkItem;  // +0x08
};

// The shared list base supplies the layout; this unit also needs RemovePos.
struct TextureResourceList : NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>
{
    char* RemovePos(void*& position);
};

struct FUN_00b6dd00_Owner
{
    char m_acPad[0x78];
    TextureResourceList m_kList;
    void BSTextureManager_Update(int iArg1, bool bArg2);
};

// @fnv 0x00b6dd00
// src: COMMUNITY 0x00b6dd00
void FUN_00b6dd00_Owner::BSTextureManager_Update(int iArg1, bool bArg2)
{
    void* pvPos = *(void**)((char*)this + 0x78);
    while (pvPos)
    {
        FUN_00b6dd00_Node* pkNode = (FUN_00b6dd00_Node*)pvPos;
        FUN_00b6dd00_Item* pkItem = pkNode->m_pkItem;
        if (bArg2)
        {
            pvPos = pkNode->m_pkNext;
        }
        else if (pkItem->m_uc10 != 0 || (pkItem->m_uiValue1 & 0x200) != 0)
        {
            pkItem->m_uc10 = 0;
            pvPos = pkNode->m_pkNext;
        }
        else
        {
            m_kList.RemovePos((void*&)pvPos);
            if (pkItem->m_pkRef)
                pkItem->m_pkRef->DecRefCount();
            _g_memoryManager.Deallocate(pkItem);
        }
    }
}

struct Resource : NiRefObject
{
};
struct Format
{
    int u00;
    int u04;
    int u08;
    int value;
};
struct Surface
{
    int u00;
    int u04;
    int u08;
    int u0c;
    Format* format;
};
struct RenderTarget
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual unsigned int size35(unsigned int);
    virtual unsigned int size36(unsigned int);
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void SetDepth(Resource*);
    virtual Surface* GetSurface(unsigned int);
    virtual Resource* GetDepth();
};
struct Renderer
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual Format* GetFormat(int, unsigned int, unsigned int);
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual RenderTarget* GetTarget();
};
extern Renderer* DAT_011f9508;
extern Renderer* formatRenderer;
extern int DAT_011bf400;
struct ResourceList
{
    int head;
    int tail;
    int count;
    ResourceList();
    ~ResourceList();
    void Clear();
};
struct EmptyList
{
    int head;
    int tail;
    int count;
    EmptyList()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
    ~EmptyList();
};
struct FUN_00b6dd80
{
    ResourceList active[5];
    ResourceList inactive[5];
    EmptyList list78;
    EmptyList list84;
    EmptyList list90;
    EmptyList list9c;
    NiPointer<Resource> depth;
    NiPointer<Resource> other;
    void Query(Renderer*, int, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*,
               unsigned int*);
    FUN_00b6dd80();
};
// @fnv 0x00b6dd80
FUN_00b6dd80::FUN_00b6dd80()
{
    Renderer* renderer = DAT_011f9508;
    unsigned int width, height, unused1, unused2, samples, mode;
    unsigned int width2, height2;
    Format* format;
    Query(renderer, 43, &width, &height, &unused1, &mode, &unused2, &samples);
    RenderTarget* target = renderer->GetTarget();
    switch (samples)
    {
    case 2:
        mode = 1;
        break;
    case 4:
        mode = 2;
        break;
    case 8:
        mode = 3;
        break;
    default:
        mode = 0;
    }
    if (target->GetDepth())
        depth = target->GetDepth();
    else if (mode == 0)
    {
        unsigned int targetWidth = target->size35(0);
        samples = width;
        if (width <= targetWidth)
            samples = targetWidth;
        unsigned int targetHeight = target->size36(0);
        mode = height;
        if (height <= targetHeight)
            mode = targetHeight;
        Surface* surface = target->GetSurface(0);
        format = formatRenderer->GetFormat(surface->format ? surface->format->value : 0, 32, 8);
        DAT_011bf400 = 0;
        depth = NiDepthStencilBuffer::Create(samples, mode, renderer, *format, 0);
        DAT_011bf400 = 1;
        target->SetDepth(depth);
    }
    else
    {
        Surface* surface = target->GetSurface(0);
        format = formatRenderer->GetFormat(surface->format ? surface->format->value : 0, 32, 8);
        DAT_011bf400 = 0;
        Resource* multisample =
            NiDepthStencilBuffer::Create(target->size35(0), target->size36(0), renderer, *format, mode);
        DAT_011bf400 = 1;
        target->SetDepth(multisample);
        Query(renderer, 4, &width2, &height2, &unused1, &mode, &unused2, &samples);
        unsigned int finalWidth = width > width2 ? width : width2;
        unsigned int finalHeight = height > height2 ? height : height2;
        DAT_011bf400 = 0;
        depth = NiDepthStencilBuffer::Create(finalWidth, finalHeight, renderer, *format, 0);
        DAT_011bf400 = 1;
    }
    other = 0;
    for (unsigned int index = 0; index < 5; ++index)
    {
        active[index].Clear();
        inactive[index].Clear();
    }
}

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
void* NiMalloc(unsigned int size);

// distinct from NiTArray<void*, NiTMallocInterface<void*> >: legacy vftable 0x010b9d24 calls dtor 0x00ba3ce0; shared RTTI vftable 0x010edae4 calls 0x00e6eb70.
template <class T> struct BaseArray
{
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    BaseArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = (T*)NiMalloc(sizeof(T) * m_usMaxSize);
        else
            m_pBase = 0;
    }
    virtual ~BaseArray();
};

template <class T> struct PrimArray : BaseArray<T>
{
    PrimArray(unsigned int uiMaxSize, unsigned int uiGrowBy) : BaseArray<T>(uiMaxSize, uiGrowBy)
    {}
    virtual ~PrimArray();
};

struct OwnedPtr
{
    void* m_p;
    OwnedPtr() : m_p(0)
    {}
};

struct Handle1E4
{
    unsigned char m_bFlag;
    int m_iUnk04;
    int m_iHandle;
    Handle1E4() : m_bFlag(0), m_iHandle(-1)
    {}
};

struct List1F0
{
    int m_iUnk00;
    int m_iUnk04;
    int m_iUnk08;
    unsigned char m_bUnk0C;
    List1F0() : m_iUnk00(0), m_iUnk04(0), m_iUnk08(0), m_bUnk0C(0)
    {}
    ~List1F0();
};

struct Block200
{
    int m_iUnk00;
    unsigned char m_bUnk04;
    unsigned char m_bUnk05;
    unsigned char m_bUnk06;
    Block200() : m_iUnk00(0), m_bUnk04(0), m_bUnk05(0), m_bUnk06(0)
    {}
    ~Block200();
};

struct Ptr208
{
    int m_iUnk00;
    Ptr208() : m_iUnk00(0)
    {}
    ~Ptr208();
};

struct FUN_00b97a80
{
    int unk000;
    PrimArray<void*> m_kArray;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    OwnedPtr m_kPtrAC;
    OwnedPtr m_kPtrB0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    Handle1E4 m_kHandle;
    List1F0 m_kList1F0;
    Block200 m_kBlock200;
    Ptr208 m_kPtr208;
    Ptr208 m_kPtr20C;
    Ptr208 m_kPtr210;
    float m_f214;
    float m_f218;
    float m_f21C;
    float m_f220;
    float m_f224;
    float m_f228;
    float m_f22C;
    float m_f230;
    int unk234;
    float m_f238;
    float m_f23C;
    float m_f240;
    float m_f244;
    float m_f248;
    float m_f24C;
    float m_f250;
    float m_f254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    float m_f2F8;
    float m_f2FC;
    float m_f300;
    float m_f304;
    float m_f308;
    float m_f30C;
    float m_f310;
    float m_f314;

    FUN_00b97a80();
    void Reset();
};

// @fnv 0x00b97a80
FUN_00b97a80::FUN_00b97a80() : m_kArray(0x74, 1)
{
    m_f214 = 0.0f;
    m_f218 = 0.0f;
    m_f21C = 0.0f;
    m_f220 = 0.0f;
    m_f224 = 0.0f;
    m_f228 = 0.0f;
    m_f22C = 0.0f;
    m_f230 = 0.0f;
    m_f238 = 0.0f;
    m_f23C = 0.0f;
    m_f240 = 0.0f;
    m_f244 = 0.0f;
    m_f248 = 0.0f;
    m_f24C = 0.0f;
    m_f250 = 0.0f;
    m_f254 = 0.0f;
    m_f2F8 = 0.0f;
    m_f2FC = 0.0f;
    m_f300 = 0.0f;
    m_f304 = 0.0f;
    m_f308 = 0.0f;
    m_f30C = 0.0f;
    m_f310 = 0.0f;
    m_f314 = 0.0f;
    fnv_zlib_memset(&unk014, 0, 0x98);
    Reset();
}

typedef NiTListItem<NiPointer<BSMultiBound> > MultiBoundListItem;

struct MultiBoundPool
{
    unsigned int m_uiCount;
    MultiBoundListItem* NiGeometry_AddProperty();
};
struct MultiBoundList
{
    MultiBoundListItem* m_pkHead;
    MultiBoundListItem* m_pkTail;
    MultiBoundPool m_pThreadAllocator;
    void AddTail(const NiPointer<BSMultiBound>& element);
    NiPointer<BSMultiBound> RemovePos(void*& position);
};

struct MultiBoundOwner
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    MultiBoundList m_kInactiveList;
    MultiBoundList m_kActiveList;
    void BSTextureManager_ReturnFrustumShadowTexture(BSMultiBound* pkBound);
};

// @fnv 0x00b6d4c0
// src: XBOX_PDB 0x00b6d4c0
void MultiBoundOwner::BSTextureManager_ReturnFrustumShadowTexture(BSMultiBound* pkBound)
{
    if (!pkBound)
        return;
    NiPointer<BSMultiBound> pMultiBound;
    MultiBoundListItem* pkItem = m_kActiveList.m_pkHead;
    void* pos = pkItem;
    while (pkItem)
    {
        pMultiBound = pkItem->m_element;
        if (pMultiBound == pkBound)
        {
            pos = pkItem;
            break;
        }
        pkItem = pkItem->m_pkNext;
        if (!pkItem)
        {
            pos = pkItem;
            break;
        }
    }
    if (pos)
    {
        m_kInactiveList.AddTail(pMultiBound);
        m_kActiveList.RemovePos((void*&)pos);
    }
}

void MultiBoundList::AddTail(const NiPointer<BSMultiBound>& element)
{
    MultiBoundListItem* item = m_pThreadAllocator.NiGeometry_AddProperty();
    item->m_element = element;
    item->m_pkNext = 0;
    item->m_pkPrev = m_pkTail;
    if (m_pkTail)
        m_pkTail->m_pkNext = item;
    else
        m_pkHead = item;
    ++m_pThreadAllocator.m_uiCount;
    m_pkTail = item;
}

// Exe 0x00b6d5e0: unit-local RendererData view; declarations and layout are preserved.
struct BstexturemanagerRendererDataView
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual unsigned int GetWidth();
    virtual unsigned int GetHeight();
};

struct BufferPtr
{
    BstexturemanagerRendererDataView* ptr;
    operator BstexturemanagerRendererDataView*() const
    {
        return ptr;
    }
    BstexturemanagerRendererDataView* operator->() const
    {
        return ptr;
    }
};
class RenderTexture : public NiObject
{
  public:
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
    BufferPtr buffers[4];
    unsigned int GetWidth(unsigned int index = 0) const
    {
        return buffers[index] ? buffers[index]->GetWidth() : 0;
    }
    unsigned int GetHeight(unsigned int index = 0) const
    {
        return buffers[index] ? buffers[index]->GetHeight() : 0;
    }
};


struct RenderTargetGroup
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual unsigned int GetWidth(unsigned int uiIndex);
    virtual unsigned int GetHeight(unsigned int uiIndex);
};

// The original renderer entry is virtual at slot 50. Keep its dispatch local
// until the shared declaration describes the full renderer virtual interface.
inline RenderTargetGroup* NiRenderer::GetDefaultRenderTargetGroup()
{
    typedef RenderTargetGroup* (__thiscall *GetTarget)(NiRenderer*);
    return reinterpret_cast<GetTarget*>(*reinterpret_cast<void***>(this))[50](this);
}

extern MemoryManager DAT_011f6238;

struct RTEntry
{
    NiPointer<RenderTexture> m_spTexture;
    int m_eFormat;
    int m_iUsage;
    unsigned int m_uiValue1;
    bool m_bIsCubeMap;
    int m_iMultiSample;

    static void* operator new(unsigned int uiSize)
    {
        return DAT_011f6238.Allocate(uiSize);
    }
};

typedef NiTListItem<RTEntry* > RTNode;

struct RTAllocator
{
    void* Allocate();

};

typedef NiTPointerListBase<RTAllocator, RTEntry* > RTList;
template <> inline void* NiTListBase<RTAllocator, RTEntry* >::GetHeadPos() const
{
        return m_pkHead;
    }
template <> inline RTEntry* const& NiTPointerListBase<RTAllocator, RTEntry* >::Get(void* p) const
{
        return ((RTNode*)p)->m_element;
    }
template <> inline void* NiTListBase<RTAllocator, RTEntry* >::GetNextPos(void* p) const
{
        return ((RTNode*)p)->m_pkNext;
    }
template <> inline void NiTPointerListBase<RTAllocator, RTEntry* >::AddTail(RTEntry* const& element)
{
        RTNode* pkNode = (RTNode*)m_kItemCount.Allocate();
        pkNode->m_element = element;
        pkNode->m_pkNext = 0;
        pkNode->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkNode;
        else
            m_pkHead = pkNode;
        m_pkTail = pkNode;
        m_kItemCount.m_uiCount++;
    }

template <> inline RTEntry* NiTPointerListBase<RTAllocator, RTEntry* >::RemovePos(void*& position)
{
    RTNode* node = (RTNode*)position;
    if (node == m_pkHead)
    {
        position = node->m_pkNext;
        return RemoveHead();
    }
    if (node == m_pkTail)
    {
        position = 0;
        return RemoveTail();
    }
    RTNode* previous = node->m_pkPrev;
    RTNode* next = node->m_pkNext;
    position = next;
    if (previous)
        previous->m_pkNext = next;
    if (next)
        next->m_pkPrev = previous;
    RTEntry* result = node->m_element;
    DeleteItem(node);
    --m_kItemCount.m_uiCount;
    return result;
}
extern bool DAT_011f9194;
extern bool DAT_011f9195;
extern bool DAT_011f9196;
extern bool DAT_011f9197;
extern bool DAT_011f9198;
extern bool DAT_011f9199;
extern bool DAT_011f919a;
extern bool DAT_011f919b;
extern bool DAT_011f919c;
extern bool DAT_011f919d;
extern bool DAT_011f919e;
extern bool DAT_011f919f;
extern bool DAT_011f91a0;
extern bool DAT_011f91a1;
extern bool DAT_011f91a2;

class RenderTargetManager
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
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    RTList m_kFreeList;
    RTList m_kUsedList;

    RenderTexture* CreateRenderTarget(NiRenderer* pkRenderer, unsigned int uiWidth, unsigned int uiHeight, int eFormat,
                                      int iUsage, unsigned int uiFlags, int a7, int a8, int a9, int a10);
    RenderTexture* BSTextureManager_BorrowRenderedTexture_0(NiRenderer* pkRenderer, unsigned int uiWidth, unsigned int uiHeight,
                                unsigned int uiFlags, int eFormat, int iUsage, int a7, int a8, int a9, int a10);
};

// @fnv 0x00b6d5e0
// src: COMMUNITY 0x00b6d5e0
RenderTexture* RenderTargetManager::BSTextureManager_BorrowRenderedTexture_0(NiRenderer* pkRenderer, unsigned int uiWidth, unsigned int uiHeight,
                                                 unsigned int uiFlags, int eFormat, int iUsage, int a7, int a8, int a9,
                                                 int a10)
{
    RTEntry* pkFound = 0;
    unsigned int defaultWidth = pkRenderer->GetDefaultRenderTargetGroup()->GetWidth(0);
    unsigned int defaultHeight = pkRenderer->GetDefaultRenderTargetGroup()->GetHeight(0);

    if (eFormat && !(uiFlags & 8))
    {
        bool b = false;
        switch (eFormat)
        {
        case 23:
            if (DAT_011f9194)
                b = true;
            break;
        case 24:
            if (DAT_011f9195)
                b = true;
            break;
        case 25:
            if (DAT_011f9196)
                b = true;
            break;
        case 26:
            if (DAT_011f9197)
                b = true;
            break;
        case 81:
            if (DAT_011f9198)
                b = true;
            break;
        case 20:
            if (DAT_011f9199)
                b = true;
            break;
        case 21:
            if (DAT_011f919a)
                b = true;
            break;
        case 22:
            if (DAT_011f919b)
                b = true;
            break;
        case 114:
            if (DAT_011f919c)
                b = true;
            break;
        case 113:
            if (DAT_011f919d)
                b = true;
            break;
        case 36:
            if (DAT_011f919e)
                b = true;
            break;
        case 116:
            if (DAT_011f919f)
                b = true;
            break;
        case 0x32:
            if (DAT_011f91a0)
                b = true;
        case 0x22:
            if (DAT_011f91a1)
                b = true;
            break;
        case 0x70:
            if (DAT_011f91a2)
                b = true;
            break;
        }

        if (!b)
        {
            if (eFormat == 0x24)
                eFormat = 0x71;
        }
    }

    RTNode* kPos = (RTNode*)m_kFreeList.GetHeadPos();
    while (kPos && !pkFound)
    {
        RTEntry* pkEntry = m_kFreeList.Get(kPos);
        if ((pkEntry->m_spTexture->GetWidth() == uiWidth ||
             (!uiWidth && pkEntry->m_spTexture->GetWidth() == defaultWidth)) &&
            (pkEntry->m_spTexture->GetHeight() == uiHeight ||
             (!uiHeight && pkEntry->m_spTexture->GetHeight() == defaultHeight)) &&
            pkEntry->m_eFormat == eFormat && pkEntry->m_iUsage == iUsage &&
            ((a7 != 9 || pkEntry->m_iMultiSample == a7) && (a7 != 0x16 || pkEntry->m_iMultiSample == a7)) &&
            (pkEntry->m_uiValue1 | 0x22) == (uiFlags | 0x22))
        {
            pkFound = pkEntry;
        }
        else
        {
            kPos = (RTNode*)m_kFreeList.GetNextPos(kPos);
        }
    }

    if (!pkFound)
    {
        pkFound = new RTEntry;
        pkFound->m_eFormat = eFormat;
        pkFound->m_iUsage = iUsage;
        pkFound->m_uiValue1 = uiFlags;
        pkFound->m_bIsCubeMap = true;
        pkFound->m_spTexture =
            (uiWidth > 0 && uiHeight > 0)
                ? CreateRenderTarget(pkRenderer, uiWidth, uiHeight, eFormat, iUsage, uiFlags, a7, a8, a9, a10)
                : CreateRenderTarget(pkRenderer, defaultWidth, defaultHeight, eFormat, iUsage, uiFlags, a7, a8, a9,
                                     a10);
    }
    else
    {
        m_kFreeList.RemovePos((void*&)kPos);
        pkFound->m_bIsCubeMap = true;
    }

    m_kUsedList.AddTail(pkFound);
    return pkFound->m_spTexture;
}
