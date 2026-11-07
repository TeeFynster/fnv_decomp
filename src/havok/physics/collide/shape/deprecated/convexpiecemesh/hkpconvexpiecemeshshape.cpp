
// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkStatisticsCollector.h"
#include "../../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../../include/hkpConvexPieceMeshShape.h"

struct HkpStandIn;

struct HkpAllocator
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void release(HkpStandIn* object, unsigned short size) = 0;
};

struct HkpRouter
{
    void* reserved;
    unsigned char padding[12];
    HkpAllocator* allocator;
};

struct HkpStandIn
{
    virtual void v0() = 0;

    void ForwardCall_00e490d0();
    HkpStandIn* FUN_00e01010(int flags);

    unsigned short value;
};

HkpRouter* _D1A0E0GetMemoryRouter();

// Calls FUN_00e490d0, then if flags has bit 0 set, releases this through the memory router's allocator with this->value as size, and returns this.
// @fnv 0x00e01010
HkpStandIn* HkpStandIn::FUN_00e01010(int flags)
{
    this->ForwardCall_00e490d0();

    if (flags & 1)
    {
        HkpRouter* router = _D1A0E0GetMemoryRouter();
        HkpAllocator* allocator = router->allocator;
        allocator->release(this, this->value);
    }

    return this;
}

struct FUN_00e49100_t
{
    int GetNextKey(int key);
};

// @fnv 0x00e49100
int FUN_00e49100_t::GetNextKey(int key)
{
    void* shape = *(void**)((char*)this + 8);
    int iMaxKey = *(int*)((char*)shape + 0x24) + *(int*)((char*)shape + 0x18);
    int iNextKey = key + 1;
    if (iNextKey >= iMaxKey)
        iNextKey = -1;
    return iNextKey;
}

struct FUN_00e49290_Target
{
    // Virtual stub that returns 0 for the given int argument.
// @fnv 0x00e49290
    virtual int FUN_00e49290_f0(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f1(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f2(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f3(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f4(int)
    {
        return 0;
    }
};

struct FUN_00e49290_Owner
{
    unsigned char pad[0x10];
    FUN_00e49290_Target target;
};

struct FUN_00e49290_Data
{
    unsigned char pad0[8];
    int* p8;
    unsigned char pad1[8];
    int* p14;
    unsigned int count;
    unsigned char pad2[4];
    int* p20;
};

struct FUN_00e49290_Class
{
    unsigned char pad[8];
    FUN_00e49290_Data* data;
    FUN_00e49290_Owner* owner;

    int hkpConvexPieceMeshShape_getCollisionFilterInfo(unsigned int index);
};

// src: HAVOK_LIB 0x00e49290
int FUN_00e49290_Class::hkpConvexPieceMeshShape_getCollisionFilterInfo(unsigned int index)
{
    int result;

    if (index < this->data->count)
    {
        int i = this->data->p14[index];
        result = this->data->p8[i + 1];
    }
    else
    {
        result = this->data->p20[index - this->data->count];
    }

    return this->owner->target.FUN_00e49290_f4(result);
}

// @fnv 0x00e49030
// src: GUESS 0x00e49030 (confidence: high)
int hkpConvexPieceMeshShape_ReturnZero()
{
    return 0;
}

struct P
{
    virtual ~P()
    {}
    int a, b, c;
};
struct S
{
    virtual ~S()
    {}
    int d;
};
struct Ptr
{
    hkReferencedObject* p;
    ~Ptr()
    {
        p->removeReference();
    }
};
struct D : P, S
{
    Ptr m18;
    Ptr m1c;
    __forceinline ~D()
    {}
    void ForwardCall_00e490d0();
};
// Destroys the object by invoking its destructor.
// @fnv 0x00e490d0
// src: GUESS 0x00e490d0 (confidence: low)
void D::ForwardCall_00e490d0()
{
    this->D::~D();
}

extern hkClass g_01269198;

int __cdecl hkStatisticsCollector_getAllocatedSize(const void* pvChunk, int iNumBytes) throw();

template <class T> inline void CollectArray(hkStatisticsCollector* pkCollector, const char* pcName,
                                          const hkArray<T>& kArray)
{
    if ((kArray.m_iCapacityState & 0x80000000) == 0 || pkCollector->m_reportInplaceAllocations)
    {
        const T* pData = kArray.m_data;
        int iAllocated = hkStatisticsCollector_getAllocatedSize(pData, kArray.getCapacity() * sizeof(T));
        pkCollector->AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
    }
}

// The three uint32 arrays at +8/+0x14/+0x20 identify convex-piece stream data, not a mesh section; include/ has no header.
class hkpConvexPieceStreamData : public hkReferencedObject
{
  public:
    hkArray<hkUint32> m_pConvexPieceStreamData;
    hkArray<hkUint32> m_kSecondUInt32Array;
    hkArray<hkUint32> m_kThirdUInt32Array;
};

// The +0x18/+0x1c pointers and base statistics call at 0x00d213e0 identify a convex-piece mesh, not display geometry.
// The shared mesh header lacks calcContentStatistics and the collection statistics implementation declaration.

// Adds the three convex-piece stream arrays and the display mesh, then forwards to the collection statistics routine.
// @fnv 0x00e49410
void hkpConvexPieceMeshShape::calcContentStatistics(hkStatisticsCollector* pkCollector,
                                                  const hkClass* pkClass) const throw()
{
    CollectArray(pkCollector, "Stream", m_pConvexPieceStreamData->m_kSecondUInt32Array);
    CollectArray(pkCollector, "Stream", m_pConvexPieceStreamData->m_kThirdUInt32Array);
    CollectArray(pkCollector, "Stream", m_pConvexPieceStreamData->m_pConvexPieceStreamData);
    pkCollector->beginObject("DisplayMesh", m_pDisplayMesh, 0);
    CollectShapeStatistics(pkCollector, &g_01269198);
}

// Stores whether bit bitIndex % 31 of word bitIndex / 31, at bits[bits[0] + 1 + word], is set into *found, and returns found.
// @fnv 0x00e49040
// src: HAVOK_LIB 0x00e49040
unsigned char* __stdcall hkpConvexPieceMeshShape_vertexIsSet(unsigned char* pbResult, const int* bits, unsigned int bitIndex)
{
    unsigned int wordIndex = bitIndex / 31;
    unsigned int bitWithinWord = bitIndex % 31;
    unsigned int mask = 1u << bitWithinWord;
    *pbResult = (bits[bits[0] + wordIndex + 1] & mask) != 0;
    return pbResult;
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for a virtual declared by both bases.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00e01040();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00e01040();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e01040
// src: GUESS 0x00e01040 (confidence: low)
    virtual void AdjustThisAndForward_00e01040();
};

Derived::Derived()
{}
