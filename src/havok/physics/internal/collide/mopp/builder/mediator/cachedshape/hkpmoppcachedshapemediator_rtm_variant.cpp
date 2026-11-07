// src/havok/physics/internal/collide/mopp/builder/mediator/cachedshape/hkpmoppcachedshapemediator_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/mopp/builder/mediator/cachedshape/hkpmoppcachedshapemediator.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


#include "../../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../../include/Vec4.h"

int __stdcall InitIntToZero(int, int* piValue);
void __stdcall CopyFivePointers(const void* apSource, void* apUnused1, void* apUnused2, void* apUnused3, void* apDest);
struct S_00d54cd0_Base
{
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct S_00d54cd0_All : S_00d54cd0_Base
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    void* unk14;
    int unk18;
    S_00d54cd0_All(void* world) throw();
    ~S_00d54cd0_All() throw();
};
struct S_00d54cd0_Closest : S_00d54cd0_Base
{
    void* unk8;
    int unkC;
    S_00d54cd0_Closest(void* world) throw();
    ~S_00d54cd0_Closest() throw();
};
struct S_00d54cd0_Input
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    char unk1C;
    char unk1D;
    char unk1E;
    char unk1F;
    char unk20;
};
struct S_00d54cd0_Result
{
    int unk0;
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
    bool unk2C;
};
S_00d54cd0_Result* hkpMoppUtility_buildCodeInternal(S_00d54cd0_Base* col, void* world, S_00d54cd0_Input* in, void* out) throw();
S_00d54cd0_Result* hkpMoppUtility_buildCode(void* world, S_00d54cd0_Input* pInput, void* out);
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct Record
{
    int m_i00;
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
};
struct RecordArray
{
    Record* m_pRecords;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~RecordArray() throw()
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->bufFree(m_pRecords, (uCapacity & 0x3fffffff) * sizeof(Record));
        m_pRecords = 0;
        m_uCapacity = 0x80000000;
    }
};
struct RecordBase
{
    virtual void a00();
    int m_i04;

    virtual ~RecordBase() throw()
    {}
};
struct FUN_00dd5d90 : RecordBase
{
    RecordArray m_kArray;
    int m_iExtra;

    virtual ~FUN_00dd5d90() throw();
};
struct Item
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual bool v14();
};
struct Mgr
{
    virtual void v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c(int);
    virtual void v10();
    virtual Item* v14(int, int*);
};
class FUN_00dd5cd0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Mgr* m_pMgr;

    void ComputeAxisRanges(Item* item, int m, int a, int b);
    void ProcessItems(int a, int b);
};
class DD5D50ReferencedObject
{
  public:
    DD5D50ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct DD5D50Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    DD5D50Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct DD5D50Source
{
    virtual void unk00();
    virtual int getCount();
};
class FUN_00dd5d50 : public DD5D50ReferencedObject
{
  public:
    FUN_00dd5d50(DD5D50Source* source);
    virtual void unk00();

    DD5D50Array m_items;
    DD5D50Source* m_pObservedSource;
    int m_uiItemCount;
};
struct FUN_00dd5660_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int GetUnk18_00dd5660();
};
void __cdecl ResizeAudioStream(hkMemoryAllocator* apAllocator, void* apVector, int aiElemSize);
struct Src_00dd5b00
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual int v2c();
    virtual void v30(void* apDst);
};
struct Range_00dd5b00
{
    float m_fLo;
    float m_fHi;
};
struct Entry_00dd5b00
{
    int m_iOwnerObjectOffset;
    Range_00dd5b00 m_ranges[13];
};
struct Item_00dd5b00
{
    Vec4 m_kAxisEndPoints;
    Vec4 m_extra;
};
struct Vec_00dd5b00
{
    Entry_00dd5b00* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};
struct Obj_00dd5b00
{
    int unk00;
    int unk04;
    Vec_00dd5b00 m_kNode;

    void ComputeAxisRanges(Src_00dd5b00* apSource, int aiId, Item_00dd5b00* apItems, int aiCount);
};
inline float Dot3_00dd5b00(const __m128& a, const __m128& b)
{
    __m128 m = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(m, m, 0x55);
    __m128 yx = _mm_add_ss(y, m);
    __m128 z = _mm_shuffle_ps(m, m, 0xaa);
    __m128 s = _mm_add_ss(z, yx);
    float f;
    _mm_store_ss(&f, s);
    return f;
}
struct FUN_00dd5de0
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00dd5de0();
    virtual ~FUN_00dd5de0();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00dd5de0* b = static_cast<FUN_00dd5de0*>(p);
        reinterpret_cast<hkMemoryAllocator*>(hkMemoryRouter_getInstance()->m_heap)->bufFree(p, static_cast<int>(b->m_usMemSizeAndFlags));
    }
};
struct OutCollection
{
    virtual void Unknown0() = 0;
    virtual void Unknown1() = 0;
    virtual void* Begin() = 0;
    virtual void* Next(void*) = 0;
};
struct OutRecord
{
    void* handle;
    unsigned int index;
    unsigned int unk08, unk0c, unk10;
};
struct Owner
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    OutCollection* collection;
    int count;
    void hkpMoppCachedShapeMediator_getPrimitives(OutRecord* out);
};

struct Entry
{
    int unk00;
    int index;
    Range_00dd5b00 iv;
    int unk10;
};

struct IntervalSet : Obj_00dd5b00
{

    void GetRange(const Entry& e, int axis, float& lo, float& hi) const
    {
        lo = m_kNode.m_pData[e.index].m_ranges[axis].m_fLo;
        hi = m_kNode.m_pData[e.index].m_ranges[axis].m_fHi;
    }

    void hkpMoppCachedShapeMediator_projectPrimitives(int a1, int axis, Entry* entries, int count, float* outMin, float* outMax);
};

// @fnv 0x00dd5670
// src: HAVOK_LIB 0x00dd5670
void IntervalSet::hkpMoppCachedShapeMediator_projectPrimitives(int a1, int axis, Entry* entries, int count, float* outMin, float* outMax)
{
    float lo, hi;
    GetRange(entries[0], axis, lo, hi);
    entries[0].iv.m_fLo = lo;
    entries[0].iv.m_fHi = hi;
    float mn = lo;
    float mx = hi;
    for (int i = 1; i < count; i++)
    {
        GetRange(entries[i], axis, lo, hi);
        entries[i].iv.m_fLo = lo;
        entries[i].iv.m_fHi = hi;
        mn = (mn < lo) ? mn : lo;
        mx = (mx > hi) ? mx : hi;
    }
    *outMin = mn;
    *outMax = mx;
}

struct Ent
{
    int idx;
    int unk04, unk08, unk0c, unk10;
};
struct Lst
{
    int a;
    Ent e[1];
};
struct CachedRangeMediator : Obj_00dd5b00
{
    void __thiscall hkpMoppCachedShapeMediator_findExtents(int unused, int k, Lst* l, int count, float* outMin, float* outMax);
};
// @fnv 0x00dd58d0
// src: HAVOK_LIB 0x00dd58d0
void CachedRangeMediator::hkpMoppCachedShapeMediator_findExtents(int unused, int k, Lst* l, int count, float* outMin, float* outMax)
{
    float mn = m_kNode.m_pData[l->e[0].idx].m_ranges[k].m_fLo;
    float mx = m_kNode.m_pData[l->e[0].idx].m_ranges[k].m_fHi;
    Ent* p = l->e;
    for (int i = 1; i < count; i++)
    {
        float a0 = m_kNode.m_pData[p[i].idx].m_ranges[k].m_fLo;
        float a1 = m_kNode.m_pData[p[i].idx].m_ranges[k].m_fHi;
        if (!(mn < a0))
            mn = a0;
        if (!(mx > a1))
            mx = a1;
    }
    *outMin = mn;
    *outMax = mx;
}
