
// src/unmapped/nitpointerlistbase_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/unmapped/nitpointerlistbase.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct A5E9C0RTTI
{
    const char* m_pcName;
    const A5E9C0RTTI* m_pBaseRTTI;
};

extern A5E9C0RTTI g_A5E9C0RTTI;

// @fnv 0x00a5e9c0
// src: COMMUNITY 0x00a5e9c0
const A5E9C0RTTI* __cdecl NiNode_GetRTTI()
{
    return &g_A5E9C0RTTI;
}

struct AlphaKey
{
    unsigned int value;
};

struct AlphaNode
{
    AlphaNode* next;
    unsigned int unk04;
    AlphaKey key;
};

struct AlphaList
{
    AlphaNode* head;

    unsigned int RemovePos(AlphaNode** pos);
    unsigned int NiTPointerListBase_Remove(unsigned int* keyPtr);
};

// @fnv 0x00e7db70
// src: COMMUNITY 0x00e7db70
unsigned int AlphaList::NiTPointerListBase_Remove(unsigned int* keyPtr)
{
    AlphaNode* sel;
    AlphaNode* node = head;
    if (node != 0)
    {
        unsigned int k = *keyPtr;
        do
        {
            AlphaKey* p = &node->key;
            sel = node;
            node = node->next;
            if (k == p->value)
            {
                goto found;
            }
        } while (node != 0);
    }
    sel = 0;
found:
    AlphaNode* pos = sel;
    if (pos != 0)
    {
        return RemovePos(&pos);
    }
    return *keyPtr;
}

#include <windows.h>
struct A5E930RefObject
{
    virtual ~A5E930RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void DecRefCount()
    {
        if (InterlockedDecrement((LONG*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

extern "C" void __cdecl j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(void* p);

struct A5E930Buffer
{
    virtual ~A5E930Buffer()
    {
        j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(m_pBase);
    }

    void* m_pBase;
};

class A5E930Base
{
  public:
    virtual ~A5E930Base();
    virtual void DeleteThis();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void GetChildAt(unsigned int uiIndex, A5E930RefObject*& pkChild);

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
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
};

class FUN_00a5e930 : public A5E930Base
{
  public:
    virtual ~FUN_00a5e930() throw();

    A5E930Buffer m_kBuffer;
    unsigned short unkA4;
    unsigned short m_usChildCount;
};

// @fnv 0x00a5e930
FUN_00a5e930::~FUN_00a5e930() throw()
{
    for (unsigned int i = 0; i < m_usChildCount; i++)
    {
        A5E930RefObject* pkChild = 0;
        static_cast<A5E930Base*>(this)->GetChildAt(i, pkChild);
        if (pkChild)
            pkChild->DecRefCount();
    }
}
