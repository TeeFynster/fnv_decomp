
// src/havok/physics/collide/query/collector/pointcollector/hkpclosestcdpointcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/pointcollector/hkpclosestcdpointcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"

// Resets both times to the maximum real value and clears the counter.

const float C6D170_MAX_REAL = 3.40282e+38f;

class C6D170Timer
{
  public:
    int unk00;
    float m_fTime;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    float m_fRemaining;
    int m_iArrayLength;

    void Reset();
};

// @fnv 0x00c6d170
void C6D170Timer::Reset()
{
    m_fTime = m_fRemaining = C6D170_MAX_REAL;
    m_iArrayLength = 0;
}

#include <xmmintrin.h>
struct S_cd3b20_node
{
    unsigned int unk00;
    int m_04;
    unsigned int unk08;
    S_cd3b20_node* m_0c;
};

struct S_cd3b20_cls
{
    unsigned int unk00;
    float m_04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    float m_1c;
    S_cd3b20_node* m_20;
    S_cd3b20_node* m_24;
    unsigned int unk28;
    float m_2c;
    S_cd3b20_node* m_30;
    int m_34;
    int m_38[8];
    S_cd3b20_node* m_58;
    int m_5c;
    int m_60[8];

    void hkpClosestCdPointCollector_addCdPoint(S_cd3b20_cls* src);
};

static __forceinline S_cd3b20_node* Last(S_cd3b20_node* p)
{
    while (p->m_0c != 0)
        p = p->m_0c;
    return p;
}

// If m_30 is null or src->m_1c is less than m_2c, copies src state, setting m_30 and m_58 to the last nodes of src's two lists and recording their key paths.
// @fnv 0x00cd3b20
// src: HAVOK_SRC 0x00cd3b20
void S_cd3b20_cls::hkpClosestCdPointCollector_addCdPoint(S_cd3b20_cls* src)
{
    if (m_30 != 0 && !(src->m_1c < m_2c))
        return;

    *(__m128*)&unk10 = *(__m128*)&src->unk00;
    *(__m128*)&m_20 = *(__m128*)&src->unk10;

    m_30 = Last(src->m_20);
    m_34 = src->m_20->m_04;

    S_cd3b20_node* __restrict head = src->m_20;
    S_cd3b20_node* cur = head->m_0c;
    int count = 0;
    while (cur != 0)
    {
        cur = cur->m_0c;
        count++;
    }
    {
        S_cd3b20_node* q = src->m_20;
        m_38[count] = -1;
        for (int i = count - 1; i >= 0; i--)
        {
            m_38[i] = q->m_04;
            q = q->m_0c;
        }
    }

    m_58 = Last(src->m_24);
    m_5c = src->m_24->m_04;

    int n2 = 0;
    for (S_cd3b20_node* c2 = src->m_24->m_0c; c2 != 0; c2 = c2->m_0c)
        n2++;
    {
        S_cd3b20_node* q = src->m_24;
        m_60[n2] = -1;
        for (int i = n2 - 1; i >= 0; i--)
        {
            m_60[i] = q->m_04;
            q = q->m_0c;
        }
    }

    m_04 = src->m_1c;
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct FUN_00c6d9c0
{
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;

    FUN_00c6d9c0();

// @fnv 0x00c6d9c0
    virtual ~FUN_00c6d9c0()
    {}

    static void operator delete(void* apMemory)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        // This allocator dispatches Free through its third vtable slot.
        typedef void (__thiscall *FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
        FreeFunction freeMemory = reinterpret_cast<FreeFunction>(
            (*reinterpret_cast<void***>(pAllocator))[2]);
        freeMemory(pAllocator, apMemory, sizeof(FUN_00c6d9c0));
    }
};

FUN_00c6d9c0::FUN_00c6d9c0()
{
    m_i04 = 0;
}
