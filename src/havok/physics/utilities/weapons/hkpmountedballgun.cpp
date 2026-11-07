
// src/havok/physics/utilities/weapons/hkpmountedballgun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpmountedballgun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMountedBallGun.h"
#include "../../../../../include/hkMemoryAllocator.h"
// hkMemoryRouterQ_hkpmountedballgun: local type (was include/hkMemoryRouterQ.h, which had no evidence of one real class); no method of it is bound to a named game function

class hkMemoryRouterQ_hkpmountedballgun
{
public:
    int unk00;
    int unk04;
    int unk08;
    union
    {
        int unk0C;
        int unk0c;
    };
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }

    hkMemoryAllocator& debug();
};

#include <xmmintrin.h>
extern unsigned int DAT_010ec004;
extern float DAT_01011d78;
extern float DAT_01016410;

struct FUN_00e46f90_Obj
{
    void FUN_00e46f90(int a);
};
struct HKStr
{
    void* m_p;
    void operator=(const char* s);
};
union HKVec
{
    __m128 v;
    struct
    {
        float x, y, z, w;
    };
};

struct MBG
{
    void* vfptr;
    unsigned short unk04;
    short unk06;
    unsigned char m_type;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    HKStr m_name;
    unsigned char m_uiKeyboardKey;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    void** m_listenerData;
    int m_listenerCount;
    int m_listenerCap;
    float m_fBulletRadius;
    float m_fBulletVelocity;
    float m_fBulletMass;
    float m_fBulletSpread;
    int m_iBulletBatchCount;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    HKVec m_kBulletDirection;
    void* m_pBulletQueue;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    HKVec m_vContactPosition;
};

struct FUN_00e45150_class
{
    MBG* Initialize(int a);
};

// Calls FUN_00e46f90 with a, sets the vtable, type 4 and the name "MountedBallGun", and stores a vector from DAT_01011d78 and DAT_01016410 in the final member.
// @fnv 0x00e45150
MBG* FUN_00e45150_class::Initialize(int a)
{
    MBG* self = (MBG*)this;
    ((FUN_00e46f90_Obj*)this)->FUN_00e46f90(a);
    self->vfptr = (void*)&DAT_010ec004;
    self->m_type = 4;
    self->m_name = "MountedBallGun";
    __m128 v = _mm_setr_ps(DAT_01011d78, DAT_01016410, DAT_01011d78, DAT_01011d78);
    self->m_vContactPosition.v = v;
    return self;
}

void* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkString_memCpy(void* dst, const void* src, int numBytes);

inline hkMemoryRouterQ_hkpmountedballgun& getRouter()
{
    return *(hkMemoryRouterQ_hkpmountedballgun*)hkMemoryRouter_getInstance();
}

template <typename T> inline T* hkAllocateChunkQ(int n)
{
    return (T*)getRouter().heap().blockAlloc(n * sizeof(T));
}

template <typename T> inline void hkDeallocateChunkQ(T* p, int n)
{
    getRouter().heap().blockFree(p, n * sizeof(T));
}

struct hkpRigidBody;

template <typename T> struct hkQueueQ
{
    T* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    int getCapacity() const
    {
        return m_pRayCursor;
    }
    void releaseMemory()
    {
        if (m_pRayCursor)
            hkDeallocateChunkQ<T>(m_data, m_pRayCursor);
    }
    void hkQueue_hkpRigidBody_setCapacity(int n);
};

// Grows the queue buffer to at least n elements, copying existing nodes and updating the head and tail indices.
// @fnv 0x00e45460
// src: XBOX_PDB 0x00e45460
template <typename T> void hkQueueQ<T>::hkQueue_hkpRigidBody_setCapacity(int aiMinCapacity)
{
    if (getCapacity() < aiMinCapacity)
    {
        if (getCapacity() * 2 >= aiMinCapacity)
            aiMinCapacity = getCapacity() * 2;

        T* p = hkAllocateChunkQ<T>(aiMinCapacity);
        if (m_data != 0)
        {
            if (m_iNodeCount)
            {
                if (m_pTail <= m_pFirstNode)
                {
                    int numHead = m_pRayCursor - m_pFirstNode;
                    int numTail = m_pTail;
                    hkString_memCpy(p, m_data + m_pFirstNode, numHead * sizeof(T));
                    hkString_memCpy(p + numHead, m_data, numTail * sizeof(T));
                }
                else
                {
                    hkString_memCpy(p, m_data + m_pFirstNode, m_iNodeCount * sizeof(T));
                }
            }
            m_pFirstNode = 0;
            m_pTail = m_iNodeCount;
        }
        releaseMemory();
        m_data = p;
        m_pRayCursor = aiMinCapacity;
    }
}

template struct hkQueueQ<hkpRigidBody*>;
