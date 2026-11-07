#include "../../../../../../../../include/hkArray.h"

// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpumoppaabbjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpumoppaabbjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <xmmintrin.h>
#include <windows.h>
inline void* __cdecl operator new(unsigned int, void* where) throw()
{
    return where;
}

extern DWORD DAT_0126835c;

struct S_00df7010_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        volatile unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = t;
    }
};

struct S_00df7010_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00df7010_MonitorStream& GetMonitorStream()
    {
        return *(S_00df7010_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    void timer(const char* name)
    {
        if (memoryAvailable())
        {
            S_00df7010_TimerCommand* h = (S_00df7010_TimerCommand*)m_kRayEnd;
            h->m_pCommandName = name;
            _ReadWriteBarrier();
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};

struct S_00df7010_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00df7010_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00df7010_Allocator* m_pStreamAllocator;
    S_00df7010_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00df7010_Router* hkMemoryRouter_getInstance() throw();
void ResizeAudioStream(S_00df7010_Allocator& alloc, void* array, int sizeElem) throw();

static __forceinline void S_00df7010_HitArray_destroy(hkArrayBase<unsigned int>& self) throw();

static __forceinline void S_00df7010_HitArray__clearAndDeallocate(hkArrayBase<unsigned int>& self, S_00df7010_Allocator& alloc);

static __forceinline void S_00df7010_HitArray__pushBack(hkArrayBase<unsigned int>& self, S_00df7010_Allocator& alloc, const unsigned int& e);

static __forceinline void S_00df7010_HitArray_AddBack(hkArrayBase<unsigned int>& self, const unsigned int& e);

static __forceinline void S_00df7010_HitArray_destroy(hkArrayBase<unsigned int>& self) throw()
{
        S_00df7010_HitArray__clearAndDeallocate(self, hkMemoryRouter_getInstance()->heap());
    }

static __forceinline void S_00df7010_HitArray__clearAndDeallocate(hkArrayBase<unsigned int>& self, S_00df7010_Allocator& alloc)
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(unsigned int));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

static __forceinline void S_00df7010_HitArray__pushBack(hkArrayBase<unsigned int>& self, S_00df7010_Allocator& alloc, const unsigned int& e)
{
        if (self.m_iElementCount == self.getCapacity())
            ResizeAudioStream(alloc, (&self), sizeof(unsigned int));
        new (self.m_data + self.m_iElementCount) unsigned int(e);
        self.m_iElementCount++;
    }

static __forceinline void S_00df7010_HitArray_AddBack(hkArrayBase<unsigned int>& self, const unsigned int& e)
{
        S_00df7010_HitArray__pushBack(self, hkMemoryRouter_getInstance()->heap(), e);
    }

struct S_00df7010_HitArrayPolicy
{
    static __forceinline void destroy(hkArrayBase<unsigned int>& self) { S_00df7010_HitArray_destroy(self); }
};

struct S_00df7010_Aabb
{
    float m_kMinimumCorner[4];
    float m_kMaximumCorner[4];
};

struct S_00df7010_Query
{
    S_00df7010_Aabb m_kBounds;
    unsigned int* m_pResultBuffer;
    int unk24;
    int unk28;
    int unk2C;
};

struct S_00df7010_Vector4
{
    __m128 m_vComponents;
    S_00df7010_Vector4& operator=(const S_00df7010_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};

static __forceinline void S_00df7010_ByteArray_set(hkArrayBase<const unsigned char>& self, const unsigned char* d, int size, int cap);

static __forceinline void S_00df7010_ByteArray_set(hkArrayBase<const unsigned char>& self, const unsigned char* d, int size, int cap)
{
        self.m_data = d;
        self.m_iElementCount = size;
        self.m_iCapacityState = cap;
    }

struct S_00df7010_MoppCode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00df7010_Vector4 m_offset;
    hkArrayBase<const unsigned char> m_data;
    unsigned char m_eBuildType;
};

struct S_00df7010_Input
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S_00df7010_Vector4 m_codeOffset;
    const unsigned char* m_codeData;
    int unk34;
    S_00df7010_Query* m_queries;
    int m_numQueries;
};

struct S_00df7010_VirtualMachine
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
    void hkpMoppObbVirtualMachine_queryAabb(const S_00df7010_MoppCode* code, const S_00df7010_Aabb& aabb, hkArray<unsigned int, S_00df7010_HitArrayPolicy>* hits) throw();
};

struct S_00df7010_Output
{
    void ProcessCallback(const S_00df7010_Input* a, const S_00df7010_Input* b, int c) throw();
};

// Runs MOPP AABB queries against the input code data, appending a sentinel to each result buffer, then forwards the input to the output.
// @fnv 0x00df7010
void __cdecl ExecuteMoppAabbQuery(S_00df7010_Output* out, const S_00df7010_Input* input) throw()
{
    S_00df7010_MonitorStream::GetMonitorStream().timer("TtCollQueryMoppAabbQuery");

    // aligned storage for a stand-in MOPP code object (non-char buffer: no GS cookie)
    unsigned int buffer[16];
    S_00df7010_MoppCode* code = (S_00df7010_MoppCode*)(((unsigned int)buffer + 15) & ~15);
    code->m_offset = input->m_codeOffset;
    S_00df7010_ByteArray_set(code->m_data, input->m_codeData, 0x200, 0x200);
    code->m_eBuildType = 2;

    for (int i = 0; i < input->m_numQueries; i++)
    {
        S_00df7010_Query& query = input->m_queries[i];
        hkArray<unsigned int, S_00df7010_HitArrayPolicy> hits(query.m_pResultBuffer, 0, 0x1000);
        S_00df7010_VirtualMachine vm;
        vm.hkpMoppObbVirtualMachine_queryAabb(code, query.m_kBounds, &hits);
        S_00df7010_HitArray_AddBack(hits, 0xffffffff);
    }

    S_00df7010_MonitorStream::GetMonitorStream().timer("Et");
    out->ProcessCallback(input, input, 0);
}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    __if_exists(A::destroy) { A::destroy(*this); }
    __if_not_exists(A::destroy) { clearAndDeallocate(); }
}
