
// src/havok/common/visualize/process/hkstatisticsprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/process/hkstatisticsprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/Pair.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Havok visualizer code: uses the stand-in's uint aliases (xb/yb/zb) and expand/FUN_00ddc870/FUN_00e0f6e0 members, which NiPoint3 does not have.
#include "../../../../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void SetComponents(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other) const;
    bool HasEqualComponents(const char* other);
    void ScaleComponents(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void SubtractIntoVector();
    LocalVec3 SubtractIntoVector(const LocalVec3& other);
    LocalVec3 SubtractIntoVector(const LocalVec3& other) const;
    LocalVec3 SubtractIntoVector(LocalVec3* other);
    LocalVec3 SubtractIntoVector(const LocalVec3* other);
    void SubtractIntoVector(LocalVec3* output, const LocalVec3* other);
    LocalVec3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& other) const;
    LocalVec3 ProcessAndReturnValue_0053d280(float divisor);
    float NiPoint3_XYLength();
    float NiPoint3_XYLength() const;
    void ComputeValue_0063c8a0(const LocalVec3* other);
    void ComputeValue_0063c8a0(void* other);
    void FUN_006815c0();
    float CVec3_Distance(LocalVec3* other);
    float CVec3_Distance(const LocalVec3& other) const;
    LocalVec3 TransformPointByMatrix4(const Mat& matrix);
    LocalVec3 TransformPointByMatrix4(const Matrix4* matrix);
    void Normalize_00b12790();
    LocalVec3 Diff_00b13040(void* other);
    LocalVec3 Diff_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& AddComponents(void* other);
    void ProcessEntries_00ddc870();
    void FUN_00e0f6e0();
};
#include "../../../../../include/Vec4.h"

// The shared allocator declarations do not expose the virtual dispatch slots yet.
__forceinline void FreeAudioArray(hkMemoryAllocator* allocator, void* memory, unsigned int capacity) throw()
{
    typedef void (__thiscall *FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
    (*reinterpret_cast<FreeFunction**>(allocator))[4](allocator, memory, capacity);
}

__forceinline void FreeAudioBlock(hkMemoryAllocator* allocator, void* memory, unsigned int size)
{
    typedef void (__thiscall *FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
    (*reinterpret_cast<FreeFunction**>(allocator))[2](allocator, memory, size);
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct ArrayMember
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~ArrayMember() throw()
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            FreeAudioArray(pAllocator, m_pData, uCapacity & 0x3fffffff);
        m_pData = 0;
        m_uCapacity = 0x80000000;
    }
};

struct PtrArrayMember
{
    void** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~PtrArrayMember() throw()
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            FreeAudioArray(pAllocator, m_ppData, (uCapacity & 0x3fffffff) * 4);
        m_ppData = 0;
        m_uCapacity = 0x80000000;
    }
};

struct FirstBase
{
    virtual void a00();
    int m_i04;

    virtual ~FirstBase() throw()
    {}
};

struct SecondBase
{
    virtual void b00();

    virtual ~SecondBase() throw()
    {}
};

struct FUN_00ddc0b0 : FirstBase, SecondBase
{
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    PtrArrayMember m_kFirst;
    ArrayMember m_kSecond;
    ArrayMember m_kThird;

    virtual ~FUN_00ddc0b0() throw();
};

// Destructor of a container holding three array members, which are freed by their own destructors.
// @fnv 0x00ddc0b0
FUN_00ddc0b0::~FUN_00ddc0b0() throw()
{}

extern int DAT_01269cd8;

// @fnv 0x00ddc820
// src: GUESS 0x00ddc820 (confidence: low)
int Object_GetDAT_01269cd8_00ddc820()
{
    return DAT_01269cd8;
}

#include <windows.h>
extern DWORD DAT_0126835c;
struct TlsBuf
{
    int* m_pCurrent;
    int* m_pRecordEnd;
};
struct Allocator
{
    virtual void a0();
    virtual void a1();
    virtual void a2(void* p, int bytes);
    virtual void* Alloc(int* pBytes);
    virtual void Free(void* p, int bytes);
};
__forceinline hkMemoryRouter* GetSingleton()
{
    return reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
}
void __cdecl ResizeAudioStream(Allocator* ctx, void* pVec, int elem);
void __cdecl hkArrayUtil__reserve(Allocator* ctx, void* pVec, int sz, int elem);
struct IntVec
{
    int* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};
struct SrcArr
{
    int* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};
struct Entry
{
    int m_00;
    int m_04;
    SrcArr m_08;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    SrcArr m_2c;
};
struct ObjA
{
    Pair* m_pData;
    int m_04;
    int m_iArrayLength;
    void EnsureCapacity(Allocator* ctx, int zero);
    void ProcessArgument(Allocator* ctx);
    void Object_DoNothing();
    __forceinline int first() const
    {
        int i;
        for (i = 0; i <= m_iArrayLength; ++i)
            if (m_pData[i].a != -1)
                break;
        return i;
    }
    __forceinline int next(int previous) const
    {
        int i;
        for (i = previous + 1; i <= m_iArrayLength; ++i)
            if (m_pData[i].a != -1)
                break;
        return i;
    }
    __forceinline bool valid(int i) const
    {
        return i <= m_iArrayLength;
    }
};
void __cdecl ProcessRecords(int a, int b, ObjA* o);
struct Sub8
{
    int m_00;
    int m_04;
    void UpdateState_00cb0c10(int a);
};
struct Elem16
{
    long long m_00;
    Sub8 m_08;
    void FUN_00e0bf20();
};
// This array uses the shared LocalVec3's three words as data, length, and capacity.
__forceinline Elem16& LocalVec3::expand(Allocator& allocator)
{
    Elem16*& data = reinterpret_cast<Elem16*&>(xb);
    int& length = reinterpret_cast<int&>(yb);
    int& capacity = reinterpret_cast<int&>(zb);
    if (length == (capacity & 0x3fffffff))
        ResizeAudioStream(&allocator, this, 0x10);
    Elem16* item = data + length;
    if (item != 0)
        item->FUN_00e0bf20();
    return data[length++];
}

extern char DAT_010c9368;
extern char DAT_0102e388;
extern char DAT_010d6ae8;
extern char DAT_0126c830;
struct CharVec
{
    char* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};
__forceinline void ReserveChars(Allocator& allocator, CharVec* array, int count)
{
    int cap = array->m_iCapacity & 0x3fffffff;
    if (cap < count)
    {
        int grown = cap + cap;
        hkArrayUtil__reserve(&allocator, array, count < grown ? grown : count, 1);
    }
}
struct Elem12
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};
struct MiniStr
{
    char* m_00;
    void FUN_00dc1680(void* p);
};
struct SObj
{
    void* m_00;
    short m_04;
    short m_06;
    CharVec* m_08;
    int m_0c;
    int m_10;
};
void __cdecl hkObjectSerialize_writeObject(SObj* s, MiniStr* ms, int a, int b, LocalVec3* v3, void* g, Vec4* v4);
struct Stream
{
    void hkOArchive_write32u(int total);
    void hkOArchive_write8u(int a);
    void WriteInt(int a);
    void hkOArchive_writeRaw(int a, int b);
};
struct ThisCls
{
    int m_00;
    int m_04;
    int m_08;
    Stream* m_0c;
    int m_10;
    int m_14;
    Entry** m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    CharVec m_30;
    Stream* m_0c_ptr()
    {
        return (Stream*)m_0c;
    }
    void WriteToStream(int arg);
};
// When sum is positive, writes m_24 data, m_30 text, and ranges derived from m_18 to m_0c, then frees local buffers.
// @fnv 0x00ddc1c0
void ThisCls::WriteToStream(int aiUnused)
{
    if (m_0c == 0)
        return;
    // Only the shared Vec4 array view is used here: data, length, and capacity.
    int vec4Storage[3];
    Vec4& vec4 = *reinterpret_cast<Vec4*>(vec4Storage);
    IntVec vecStarts;
    IntVec vecEnds;
    vec4.m_iCapacity = (int)0x80000000;
    vecStarts.m_iCapacity = (int)0x80000000;
    vecEnds.m_iCapacity = (int)0x80000000;
    vec4.m_pData = 0;
    vec4.m_iArrayLength = 0;
    vecStarts.m_pData = 0;
    vecStarts.m_iArrayLength = 0;
    vecEnds.m_pData = 0;
    vecEnds.m_iArrayLength = 0;
    int count = m_1c;
    {
        for (int i = 0; i < count; i++)
        {
            if (m_18[i]->m_08.m_iArrayLength > 0)
            {
                SrcArr* pSrcStarts = &m_18[i]->m_08;
                hkMemoryRouter* s = GetSingleton();
                Allocator* alloc = reinterpret_cast<Allocator*>(s->m_heap);
                if ((vecStarts.m_iCapacity & 0x3fffffff) < pSrcStarts->m_iArrayLength)
                {
                    if ((vecStarts.m_iCapacity & 0x80000000u) == 0)
                        alloc->Free(vecStarts.m_pData, (vecStarts.m_iCapacity & 0x3fffffff) * 4);
                    int bytes = pSrcStarts->m_iArrayLength * 4;
                    vecStarts.m_pData = (int*)alloc->Alloc(&bytes);
                    vecStarts.m_iCapacity = bytes / 4;
                }
                {
                    int iCopyCount = pSrcStarts->m_iArrayLength;
                    vecStarts.m_iArrayLength = iCopyCount;
                    int* pSrcData = pSrcStarts->m_pData;
                    int* pDstData = vecStarts.m_pData;
                    for (int k = 0; k < iCopyCount; k++)
                        pDstData[k] = pSrcData[k];
                }
                SrcArr* pSrcEnds = &m_18[i]->m_2c;
                hkMemoryRouter* pSingleton2 = GetSingleton();
                Allocator* pAllocator2 = reinterpret_cast<Allocator*>(pSingleton2->m_heap);
                if ((vecEnds.m_iCapacity & 0x3fffffff) < pSrcEnds->m_iArrayLength)
                {
                    if ((vecEnds.m_iCapacity & 0x80000000u) == 0)
                        pAllocator2->Free(vecEnds.m_pData, (vecEnds.m_iCapacity & 0x3fffffff) * 4);
                    int bytes2 = pSrcEnds->m_iArrayLength * 4;
                    vecEnds.m_pData = (int*)pAllocator2->Alloc(&bytes2);
                    vecEnds.m_iCapacity = bytes2 / 4;
                }
                {
                    int iCopyCount2 = pSrcEnds->m_iArrayLength;
                    vecEnds.m_iArrayLength = iCopyCount2;
                    int* pSrcData2 = pSrcEnds->m_pData;
                    int* pDstData2 = vecEnds.m_pData;
                    for (int k = 0; k < iCopyCount2; k++)
                        pDstData2[k] = pSrcData2[k];
                }
                break;
            }
        }
    }
    if (vecStarts.m_iArrayLength == 0)
    {
        TlsBuf* pTlsBuf = (TlsBuf*)TlsGetValue(DAT_0126835c);
        int cur = (int)pTlsBuf->m_pCurrent;
        int end = (int)pTlsBuf->m_pRecordEnd;
        hkMemoryRouter* s = GetSingleton();
        if (vecStarts.m_iArrayLength == (vecStarts.m_iCapacity & 0x3fffffff))
            ResizeAudioStream(reinterpret_cast<Allocator*>(s->m_heap), &vecStarts, 4);
        vecStarts.m_pData[vecStarts.m_iArrayLength] = cur;
        vecStarts.m_iArrayLength++;
        hkMemoryRouter* pSingleton2 = GetSingleton();
        if (vecEnds.m_iArrayLength == (vecEnds.m_iCapacity & 0x3fffffff))
            ResizeAudioStream(reinterpret_cast<Allocator*>(pSingleton2->m_heap), &vecEnds, 4);
        vecEnds.m_pData[vecEnds.m_iArrayLength] = end;
        vecEnds.m_iArrayLength++;
    }
    CharVec* pOutText = &m_30;
    {
        ReserveChars(*reinterpret_cast<Allocator*>(GetSingleton()->m_heap), pOutText, 0);
        pOutText->m_iArrayLength = 0;
    }
    int iTotalRangeLen = 0;
    ObjA objRecords;
    objRecords.m_pData = 0;
    objRecords.m_04 = 0;
    objRecords.m_iArrayLength = -1;
    hkMemoryRouter* pSingleton4 = GetSingleton();
    objRecords.EnsureCapacity(reinterpret_cast<Allocator*>(pSingleton4->m_heap), 0);
    int vecProcessedStorage[sizeof(LocalVec3) / sizeof(int)];
    LocalVec3& vecProcessed = *reinterpret_cast<LocalVec3*>(vecProcessedStorage);
    vecProcessed.FUN_00e0f6e0();
    for (int i = 0; i < vecStarts.m_iArrayLength; i++)
    {
        ProcessRecords(vecStarts.m_pData[i], vecEnds.m_pData[i], &objRecords);
        iTotalRangeLen += vecEnds.m_pData[i] - vecStarts.m_pData[i];
    }
    {
        int iRecordIdx = objRecords.first();
        while (objRecords.valid(iRecordIdx))
        {
            Elem16* pElem = &vecProcessed.expand(*reinterpret_cast<Allocator*>(GetSingleton()->m_heap));
            pElem->m_00 = (long long)objRecords.m_pData[iRecordIdx].a;
            pElem->m_08.UpdateState_00cb0c10(objRecords.m_pData[iRecordIdx].b);
            iRecordIdx = objRecords.next(iRecordIdx);
        }
    }
    int iTextLen = pOutText->m_iArrayLength;
    SObj objStr;
    objStr.m_06 = 1;
    objStr.m_00 = &DAT_010c9368;
    objStr.m_08 = pOutText;
    objStr.m_0c = iTextLen;
    objStr.m_10 = 1;
    int need = objStr.m_08->m_iArrayLength + 1;
    ReserveChars(*reinterpret_cast<Allocator*>(GetSingleton()->m_heap), pOutText, need);
    objStr.m_08->m_pData[objStr.m_08->m_iArrayLength] = 0;
    MiniStr ms;
    ms.FUN_00dc1680(&DAT_010d6ae8);
    hkObjectSerialize_writeObject(&objStr, &ms, 1, 0, &vecProcessed, &DAT_0126c830, &vec4);
    objStr.m_00 = &DAT_010c9368;
    if (objStr.m_10 == 0)
    {
        CharVec* pCharVec = objStr.m_08;
        if (pCharVec != 0)
        {
            hkMemoryRouter* pSingleton7 = GetSingleton();
            Allocator* pAllocator7 = reinterpret_cast<Allocator*>(pSingleton7->m_heap);
            int cap = pCharVec->m_iCapacity;
            pCharVec->m_iArrayLength = 0;
            if ((cap & 0x80000000u) == 0)
                pAllocator7->Free(pCharVec->m_pData, cap & 0x3fffffff);
            pCharVec->m_pData = 0;
            pCharVec->m_iCapacity = (int)0x80000000;
            hkMemoryRouter* pSingleton7b = GetSingleton();
            pSingleton7b->m_heap->blockFree(pCharVec, 12);
        }
    }
    objStr.m_00 = &DAT_0102e388;
    vecProcessed.ProcessEntries_00ddc870();
    {
        hkMemoryRouter* pSingleton8 = GetSingleton();
        objRecords.ProcessArgument(reinterpret_cast<Allocator*>(pSingleton8->m_heap));
    }
    objRecords.Object_DoNothing();
    if (iTotalRangeLen < 1)
    {
        hkMemoryRouter* pSingleton9 = GetSingleton();
        Allocator* pAllocator9 = reinterpret_cast<Allocator*>(pSingleton9->m_heap);
        int cap2 = vecEnds.m_iCapacity;
        vecEnds.m_iArrayLength = 0;
        if ((cap2 & (int)0x80000000) == 0)
            pAllocator9->Free(vecEnds.m_pData, (cap2 & 0x3fffffff) * 4);
        vecEnds.m_pData = 0;
        vecEnds.m_iCapacity = (int)0x80000000;
        hkMemoryRouter* pSingleton10 = GetSingleton();
        Allocator* pAllocator10 = reinterpret_cast<Allocator*>(pSingleton10->m_heap);
        int cap1 = vecStarts.m_iCapacity;
        vecStarts.m_iArrayLength = 0;
        if ((cap1 & (int)0x80000000) == 0)
            pAllocator10->Free(vecStarts.m_pData, (cap1 & 0x3fffffff) * 4);
        vecStarts.m_pData = 0;
        vecStarts.m_iCapacity = (int)0x80000000;
        {
            hkMemoryRouter* pSingleton11 = GetSingleton();
            Allocator* pAllocator11 = reinterpret_cast<Allocator*>(pSingleton11->m_heap);
            int cap4 = vec4.m_iCapacity;
            vec4.m_iArrayLength = 0;
            if ((cap4 & (int)0x80000000) == 0)
                pAllocator11->Free(vec4.m_pData, (cap4 & 0x3fffffff) * sizeof(Elem12));
        }
        return;
    }
    else
    {
        int numRanges = vecStarts.m_iArrayLength;
        int iDataLen = m_28;
        int iTextLen2 = m_30.m_iArrayLength;
        m_0c->hkOArchive_write32u(iTextLen2 + numRanges * 4 + iDataLen + iTotalRangeLen + 0xd);
        m_0c->hkOArchive_write8u(10);
        m_0c->WriteInt(iDataLen);
        if (iDataLen > 0)
            m_0c->hkOArchive_writeRaw(m_24, iDataLen);
        m_0c->WriteInt(iTextLen2);
        if (iTextLen2 > 0)
            m_0c->hkOArchive_writeRaw((int)pOutText->m_pData, iTextLen2);
        m_0c->WriteInt(numRanges);
        for (int i = 0; i < numRanges; i++)
        {
            int diff = vecEnds.m_pData[i] - vecStarts.m_pData[i];
            m_0c->WriteInt(diff);
            if (diff > 0)
                m_0c->hkOArchive_writeRaw(vecStarts.m_pData[i], diff);
        }
        hkMemoryRouter* pSingleton9 = GetSingleton();
        Allocator* pAllocator9 = reinterpret_cast<Allocator*>(pSingleton9->m_heap);
        int cap2 = vecEnds.m_iCapacity;
        vecEnds.m_iArrayLength = 0;
        if ((cap2 & (int)0x80000000) == 0)
            pAllocator9->Free(vecEnds.m_pData, (cap2 & 0x3fffffff) * 4);
        vecEnds.m_pData = 0;
        vecEnds.m_iCapacity = (int)0x80000000;
        hkMemoryRouter* pSingleton10 = GetSingleton();
        Allocator* pAllocator10 = reinterpret_cast<Allocator*>(pSingleton10->m_heap);
        int cap1 = vecStarts.m_iCapacity;
        vecStarts.m_iArrayLength = 0;
        if ((cap1 & (int)0x80000000) == 0)
            pAllocator10->Free(vecStarts.m_pData, (cap1 & 0x3fffffff) * 4);
        vecStarts.m_pData = 0;
        vecStarts.m_iCapacity = (int)0x80000000;
    }
    {
        hkMemoryRouter* pSingleton11 = GetSingleton();
        Allocator* pAllocator11 = reinterpret_cast<Allocator*>(pSingleton11->m_heap);
        int cap4 = vec4.m_iCapacity;
        vec4.m_iArrayLength = 0;
        if ((cap4 & (int)0x80000000) == 0)
            pAllocator11->Free(vec4.m_pData, (cap4 & 0x3fffffff) * sizeof(Elem12));
    }
    (void)aiUnused;
    (void)iTotalRangeLen;
    (void)vecProcessed;
}

// sub ecx,8; jmp FUN_00ddc840 == MSVC adjustor thunk for the secondary base's slot.
struct PrimaryBase
{
    virtual void FUN_00ddc830();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00ddc830();
};

struct AdjustDerived : PrimaryBase, SecondaryBase
{
    AdjustDerived();
// @fnv 0x00ddc830
    virtual void FUN_00ddc830();
};

AdjustDerived::AdjustDerived()
{}

namespace fnv_00ddc840 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct FUN_00ddc840
{
    unsigned short m_u04;
    unsigned short m_u06;
    FUN_00ddc840();
    virtual ~FUN_00ddc840();
    static void operator delete(void* apMemory)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        unsigned int uiSize = ((FUN_00ddc840*)apMemory)->m_u04;
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        FreeAudioBlock(pAllocator, apMemory, uiSize);
    }
};

// Initialises m_u04 and m_u06 to zero.
// @fnv 0x00ddc840
FUN_00ddc840::FUN_00ddc840()
{
    m_u04 = 0;
    m_u06 = 0;
}
}  // namespace fnv_00ddc840

struct Sbf00_Sub
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    void InitHeading();
};
struct Sbf00_Ctx
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Sbf00_Sub m_kSub;
    float m_f24;
    float m_f28;
    int unk2c;
    int unk30;
    int unk34;
    void FUN_00cc06f0(ArrayMember* apArr, int a2);
    void FUN_00cc0780();
};
struct Sbf00_Name
{
    int unk00;
    int unk04;
    void FUN_00dc1680(void* apStr);
};
struct Sbf00_Arr24
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;
    void Free()
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            FreeAudioArray(pAllocator, m_pData, (uCapacity & 0x3fffffff) * 24);
    }
};
struct Sbf00_B2
{
    void* m_pVtbl;
    unsigned char m_bFlag;
};
extern int DAT_010d1508;
extern int DAT_010d7e48;
extern int DAT_010d7e28;
extern int DAT_0126c860;
extern double DAT_01017b70;
unsigned __int64 __cdecl hkStopwatch_getTicksPerSecond();
void __cdecl hkObjectSerialize_writeObject(Sbf00_Ctx* a1, Sbf00_Name* a2, int a3, int a4, Sbf00_Sub* a5, void* a6, Sbf00_Arr24* a7);
struct SbfRef
{
    void* m_pVtbl;
    unsigned short unk04;
    unsigned short m_uRefCount;
    SbfRef() : m_uRefCount(1)
    {}
};
struct SbfProc
{
    void* m_pVtbl;
    unsigned char m_bFlag;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    SbfProc() : m_pVtbl(&DAT_010d1508), m_bFlag(1)
    {}
};
struct SbfBases : SbfRef, SbfProc
{
    SbfBases()
    {
        SbfRef::m_pVtbl = &DAT_010d7e48;
        SbfProc::m_pVtbl = &DAT_010d7e28;
    }
};
struct SbfPtrs
{
    void** m_ppData;
    int m_iArrayLength;
    unsigned m_uCapacity;
    SbfPtrs() : m_ppData(0), m_iArrayLength(0), m_uCapacity(0x80000000)
    {}
};
struct SbfBytes
{
    void* m_pData;
    int m_iArrayLength;
    unsigned m_uCapacity;
    SbfBytes() : m_pData(0), m_iArrayLength(0), m_uCapacity(0x80000000)
    {}
};
struct FUN_00ddbf00 : SbfBases
{
    SbfPtrs m_kFirst;
    SbfBytes m_kSecond;
    SbfBytes m_kThird;
    FUN_00ddbf00(PtrArrayMember* pSource);
};
// Copies pointer elements from pSource into m_kFirst, growing its backing array when the source count exceeds capacity.
// @fnv 0x00ddbf00
FUN_00ddbf00::FUN_00ddbf00(PtrArrayMember* pSource)
{
    FUN_00ddbf00* pThis = this;
    ArrayMember* pSecond = (ArrayMember*)&m_kSecond;
    Sbf00_Ctx kCtx;
    kCtx.m_kSub.InitHeading();
    kCtx.m_kSub.unk00 = 0;
    kCtx.m_kSub.unk0c = 0;
    kCtx.m_kSub.unk04 = 0;
    kCtx.m_kSub.unk08 = 1;
    {
        kCtx.m_f24 = (float)(DAT_01017b70 / (double)hkStopwatch_getTicksPerSecond());
    }
    kCtx.m_f28 = 1.0f;
    Sbf00_Arr24 kArr;
    kArr.m_pData = 0;
    kArr.m_iArrayLength = 0;
    kArr.m_uCapacity = 0x80000000;
    kCtx.FUN_00cc06f0(pSecond, 1);
    {
        Sbf00_Name kName;
        kName.FUN_00dc1680(&DAT_010d6ae8);
        hkObjectSerialize_writeObject(&kCtx, &kName, 1, 0, &kCtx.m_kSub, &DAT_0126c860, &kArr);
    }
    kCtx.FUN_00cc0780();
    kArr.Free();
    Allocator* pAlloc = reinterpret_cast<Allocator*>(hkMemoryRouter_getInstance()->m_heap);
    unsigned int uCap = pThis->m_kFirst.m_uCapacity;
    int iCap = uCap & 0x3fffffff;
    if (iCap < pSource->m_iArrayLength)
    {
        if ((uCap & 0x80000000) == 0)
            pAlloc->Free(pThis->m_kFirst.m_ppData, iCap * 4);
        int iBytes = pSource->m_iArrayLength * 4;
        pThis->m_kFirst.m_ppData = (void**)pAlloc->Alloc(&iBytes);
        pThis->m_kFirst.m_uCapacity = iBytes / 4;
    }
    int n = pSource->m_iArrayLength;
    void** pDst = pThis->m_kFirst.m_ppData;
    pThis->m_kFirst.m_iArrayLength = n;
    void** pSrc = pSource->m_ppData;
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

namespace fnv_00ddc870 {
struct FixedAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* p, unsigned int size);
};

hkMemoryRouter* hkMemoryRouter_getInstance();

struct ElemSub
{
    int unk00;
    int unk04;
    void Release();
};

struct Elem
{
    int unk00;
    int unk04;
    ElemSub m_08;
};

}  // namespace fnv_00ddc870

// @fnv 0x00ddc870
// src: GUESS 0x00ddc870 (confidence: low)
void LocalVec3::ProcessEntries_00ddc870()
{
    using namespace fnv_00ddc870;
    hkMemoryRouter* holder = fnv_00ddc870::hkMemoryRouter_getInstance();
    FixedAllocator* alloc = reinterpret_cast<FixedAllocator*>(holder->m_heap);
    int iCount = reinterpret_cast<int&>(yb);
    Elem* pItems = *reinterpret_cast<Elem* volatile*>(&xb);
    if (iCount > 0)
    {
        ElemSub* s = &pItems->m_08;
        int n = iCount;
        do
        {
            s->Release();
            s = (ElemSub*)((char*)s + 16);
        } while (--n != 0);
    }

    yb = 0;
    unsigned int cap = zb;
    if ((cap & 0x80000000u) == 0)
    {
        alloc->FreeArray(reinterpret_cast<Elem*>(xb), (cap & 0x3fffffffu) * 16);
    }
    zb = 0x80000000u;
    xb = 0;
}
