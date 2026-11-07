
// src/gamebryo2.2/corelibs/niparticle/nipsysupdatectlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysupdatectlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/StrArr.h"

struct GlobalObjectO2_00a7b610;

extern GlobalObjectO2_00a7b610 g_01202690;

// @fnv 0x00c27130
// src: COMMUNITY 0x00c27130
GlobalObjectO2_00a7b610* __cdecl NiPSysUpdateCtlr_GetRTTI()
{
    return &g_01202690;
}

extern char const* const g_011dfe40_arg1;

// @fnv 0x00a6d280
// src: COMMUNITY 0x00a6d280
char const* const& __cdecl NiTimeController_GetRTTI()
{
    return g_011dfe40_arg1;
}

void __cdecl FUN_00a6d290();
void __cdecl _delete(void*, unsigned int);
struct S00c27140
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00a6d290, then deletes this with size 0x34 when bit 0 of a1 is set, and returns this.
// @fnv 0x00c27140
void* S00c27140::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00a6d290();
    if (auiFlags & 1)
        _delete(this, 0x34);
    return this;
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
extern char DAT_010be6b4[];

struct CtorBase_cls
{
    void ctorBase();
};

struct FUN_00c27160_cls
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    float m_14;
    float m_18;
    void FUN_00a6cfe0(void* obj, unsigned int a1);
    void* NiPSysUpdateCtlr_CreateClone(unsigned int a1);
};

// Allocates a 0x34-byte object, runs its base constructor, zeroes m_14/m_18, sets its vtable, then passes it to FUN_00a6cfe0 with a1 and returns it.
// @fnv 0x00c27160
// src: XBOX_PDB 0x00c27160
void* FUN_00c27160_cls::NiPSysUpdateCtlr_CreateClone(unsigned int a1)
{
    FUN_00c27160_cls* p = (FUN_00c27160_cls*)Object_DispatchCommandFour(0x34);
    if (p != 0)
    {
        ((CtorBase_cls*)p)->ctorBase();
        p->m_18 = 0.0f;
        p->m_14 = 0.0f;
        p->m_vtbl = (void*)&DAT_010be6b4;
    }
    else
    {
        p = 0;
    }
    this->FUN_00a6cfe0(p, a1);
    return p;
}

// Reconstruction of FUN_00c27290.
//
// thiscall member: `this` in ecx, one 4-byte stack argument (the callee
// pops it, so the body ends with `ret 4`).
//
// Shape of the body:
//   * hand the incoming argument to a helper that stores it into this+0x2c,
//   * if that slot is empty, stop;
//   * walk the chain hanging off the object's +0x0c slot, following the
//     +0x30 link, to the last element of the chain;
//   * if that last element is this object, stop;
//   * otherwise append this object to the chain and move the old +0x30
//     reference into the +0x0c slot of the object stored at +0x2c;
//   * drop the old +0x30 reference: decrement its counter and, when the
//     counter reaches zero, run the object's virtual slot 1, then clear
//     the slot.

struct FnvNode;

// Helper that stores its argument into this+0x2c.
struct FnvTarget
{
    void __thiscall SetTarget(FnvNode* p);
};

// Helper that stores its argument into this+0x30.
struct FnvF30Owner
{
    void __thiscall SetF30(FnvNode* p);
};

// Helper that stores its argument into this+0x0c.
struct FnvF0COwner
{
    void __thiscall SetF0C(FnvNode* p);
};

struct FnvNode
{
    // +0x00 holds the implicit virtual table pointer.
    long refcount;  // +0x04
    void* unk08;    // +0x08
    FnvNode* f0c;   // +0x0c
    void* unk10;    // +0x10
    void* unk14;    // +0x14
    void* unk18;    // +0x18
    void* unk1c;    // +0x1c
    void* unk20;    // +0x20
    void* unk24;    // +0x24
    void* unk28;    // +0x28
    FnvNode* f2c;   // +0x2c
    FnvNode* f30;   // +0x30
    virtual void v0();
    virtual void v1();
    void __thiscall NiPSysUpdateCtlr_SetTarget(FnvNode* arg);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);

// @fnv 0x00c27290
// src: GAMEBRYO_LIB 0x00c27290
void FnvNode::NiPSysUpdateCtlr_SetTarget(FnvNode* pTarget)
{
    ((FnvTarget*)this)->SetTarget(pTarget);

    if (!f2c)
        return;

    FnvNode* t = f2c->f0c;
    while (t->f30)
        t = t->f30;

    if (t == this)
        return;

    ((FnvF30Owner*)t)->SetF30(this);
    ((FnvF0COwner*)f2c)->SetF0C(f30);

    FnvNode* p = f30;
    if (p)
    {
        if (InterlockedDecrement(&p->refcount) == 0)
            p->v1();
        f30 = 0;
    }
}

void __stdcall FUN_00a6d830(StrArr*);
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);

struct GlobalObjectO2_00a7b610
{
    const char* m_pcName;
};

// Appends the string returned by FUN_00a7d330(g_01202690.m_pcName) to pkStrings, growing it via SetSize when full and storing at index m_usSize.
// @fnv 0x00c27300
// src: XBOX_PDB 0x00c27300
void __stdcall NiPSysUpdateCtlr_GetViewerStrings(StrArr* pkStrings)
{
    FUN_00a6d830(pkStrings);
    char* str = NiViewerStrings_NiGetViewerString_Title(g_01202690.m_pcName);
    unsigned int size = pkStrings->m_usSize;
    if (size >= pkStrings->m_usMaxSize)
    {
        pkStrings->SetSize(size + pkStrings->m_usGrowBy);
    }
    pkStrings->SetAt(size, str);
}

struct S_a6d590_RefObject
{
    virtual ~S_a6d590_RefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct S_a6d590_Ptr
{
    T* m_pObject;
    ~S_a6d590_Ptr() throw()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
};

struct S_a6d590_Base
{
    virtual ~S_a6d590_Base() throw();
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct S_a6d590 : S_a6d590_Base
{
    S_a6d590_Ptr<S_a6d590_RefObject> m_pReferencedObject;
    __forceinline ~S_a6d590() throw()
    {}
    S_a6d590* DestroyAndFree(unsigned int uiFlags);
};

// Runs the destructor, then frees the object with _delete when bit 0 of uiFlags is set, and returns this.
// @fnv 0x00a6d590
S_a6d590* S_a6d590::DestroyAndFree(unsigned int uiFlags)
{
    this->S_a6d590::~S_a6d590();
    if (uiFlags & 1)
        _delete(this, sizeof(S_a6d590));
    return this;
}

namespace a6d2 {
const float DAT_0109c820 = 3.402823466e+38f;
const float DAT_01015f5c = -3.402823466e+38f;
}

struct NiPtrA6D2
{
    NiPtrA6D2() : m_pObject(0)
    {}
    void* m_pObject;
};

class FUN_00a5d3a0
{
  public:
    FUN_00a5d3a0() throw();
    virtual ~FUN_00a5d3a0() throw();
    int unk04;
};

inline void SetFieldA6D2(unsigned short& uFlags, unsigned short usValue, unsigned short usMask, unsigned short usPos)
{
    uFlags = (uFlags & ~usMask) | (usValue << usPos);
}

inline void SetBitA6D2(unsigned short& uFlags, bool bValue, unsigned short usMask)
{
    if (bValue)
        uFlags |= usMask;
    else
        uFlags &= ~usMask;
}

class FUN_00a6d220 : public FUN_00a5d3a0
{
  public:
    enum
    {
        ANIMTYPE_MASK = 0x0001,
        ANIMTYPE_POS = 0,
        CYCLETYPE_MASK = 0x0006,
        CYCLETYPE_POS = 1,
        ACTIVE_MASK = 0x0008,
        DIRECTION_MASK = 0x0010,
        COMPUTESCALEDTIME_MASK = 0x0040,
        FORCEUPDATE_MASK = 0x0080
    };

    FUN_00a6d220() throw();
    virtual ~FUN_00a6d220() throw();

    unsigned short m_uiObjectFlags;
    float m_fFrequency;
    float m_fPhase;
    float m_fLoKeyTime;
    float m_fHiKeyTime;
    float m_fStartTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fControllerTime;
    void* m_pkTarget;
    NiPtrA6D2 m_spNextController;
};

// Initializes the frequency, phase, and time fields, then updates the flags with (old flags & 0xff6c) | 0x4c.
// @fnv 0x00a6d220
FUN_00a6d220::FUN_00a6d220() throw()
    : m_uiObjectFlags(0), m_fFrequency(1.0f), m_fPhase(0.0f), m_fLoKeyTime(a6d2::DAT_0109c820),
      m_fHiKeyTime(a6d2::DAT_01015f5c), m_fStartTime(a6d2::DAT_01015f5c), m_fLastTime(a6d2::DAT_01015f5c),
      m_fWeightAdjustedLastTime(0.0f), m_fControllerTime(a6d2::DAT_01015f5c), m_pkTarget(0)
{
    unsigned short& uFlags = m_uiObjectFlags;
    uFlags = (uFlags & 0xff6c) | 0x4c;
}

extern "C" void _ReadWriteBarrier();
extern float g_01015f5c;
extern float g_010be6a8;
extern double g_010241b0;
extern char g_012024e8;

struct SpawnedTarget
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
    float m_48;
};

struct SpawnedItem
{
    virtual void v00();
    virtual void v01();
    virtual SpawnedItem* v02();
    SpawnedItem* m_04;
    unsigned short m_08;
    unsigned short unk0A;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    SpawnedItem* m_30;
    int unk34;
    int unk38;
    SpawnedTarget* m_3C;
};

struct SpawnedOwner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3A();
    virtual void v3B();
    virtual void v3C(float v);
    int unk04;
    int unk08;
    SpawnedItem* m_0C;
};

struct S00a36250
{
    bool DontDoUpdate(float v);
};

struct SpawnedController
{
    int unk00;
    int unk04;
    unsigned short m_08;
    unsigned short unk0A;
    int unk0C;
    int unk10;
    float m_14;
    float m_18;
    int unk1C;
    float m_20;
    float m_24;
    float m_28;
    SpawnedOwner* m_2C;
    void NiPSysUpdateCtlr_Update(const float* pos);
};

struct KindRtti
{
    const char* m_name;
    const KindRtti* m_base;
    const KindRtti* GetBaseRTTI() const
    {
        return m_base;
    }
};

__forceinline bool ObjIsKindOf(SpawnedItem* obj, const KindRtti* rtti)
{
    const KindRtti* tmp = (const KindRtti*)obj->v02();
    while (tmp)
    {
        if (tmp == rtti)
        {
            return true;
        }
        tmp = tmp->GetBaseRTTI();
    }
    return false;
}

__forceinline bool StaticIsKindOf(const KindRtti* rtti, SpawnedItem* obj)
{
    if (!obj)
    {
        return false;
    }
    return ObjIsKindOf(obj, rtti);
}

// @fnv 0x00c271c0
// src: XBOX_PDB 0x00c271c0
void SpawnedController::NiPSysUpdateCtlr_Update(const float* apPosition)
{
    unsigned short flags = m_08;
    m_14 = g_01015f5c;
    m_18 = g_010be6a8;
    m_08 = (unsigned short)((flags & 0xfffd) | 4);
    SpawnedItem* pItem = m_2C->m_0C;
    SpawnedItem* pHitItem = 0;
    SpawnedTarget* pTarget = 0;
    while (pItem)
    {
        if (StaticIsKindOf((const KindRtti*)&g_012024e8, pItem))
        {
            pHitItem = pItem;
            pTarget = pItem->m_3C;
            break;
        }
        pItem = pItem->m_30;
    }
    if (m_20 != -3.4028234663852886e+38)
    {
        if (pHitItem != 0 && (pHitItem->m_08 & 6) == 0)
        {
            if (*apPosition - m_20 > pTarget->m_48)
            {
                m_20 = *apPosition;
            }
        }
    }
    bool handled = reinterpret_cast<S00a36250*>(this)->DontDoUpdate(*apPosition);
    m_18 = 0.0f;
    m_14 = 0.0f;
    SpawnedOwner* owner = m_2C;
    if (owner != 0 && !handled)
    {
        owner->v3C(m_28);
    }
}
