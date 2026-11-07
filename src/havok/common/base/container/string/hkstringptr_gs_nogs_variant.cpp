#include "../../../../../../include/hkStringPtr.h"

// src/havok/common/base/container/string/hkstringptr_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/base/container/string/hkstringptr.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/container/string/hkstringptr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/string/hkstringptr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
int __cdecl hkString_strLen(const char* s);
char* __cdecl AllocateWithHeader(void* alloc, int size);
void __cdecl hkString_strCpy(char* dst, const char* src);
char* __cdecl hkString_strDup(const char* s, void* alloc);
extern void* g_01268358;
struct FUN_00cb0a60
{
    void* unk00;
    FUN_00cb0a60();
};
int __cdecl hkMemoryRouter_easyFree(int, int);
int __cdecl CallSwappedArgs(unsigned int arg0, unsigned int arg1);

typedef char* hk_va_list;

struct hkMemoryAllocatorq
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct hkMemoryRouterq
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorq* m_pStreamAllocator;

    __forceinline hkMemoryAllocatorq& heap()
    {
        return *m_pStreamAllocator;
    }
};

void* __cdecl hkMemoryRouter_getInstance() throw();

static __forceinline hkMemoryRouterq& hkGetMemoryRouter()
{
    return *(hkMemoryRouterq*)hkMemoryRouter_getInstance();
}

int __cdecl hkArrayUtil__reserve(hkMemoryAllocatorq& alloc, void* array, int numElements, int sizeElement) throw();
int __cdecl hkString_vsnprintf(char* buf, int n, const char* fmt, hk_va_list args) throw();

template <class T, int N> struct hkInplaceArrayq
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];

    __forceinline hkInplaceArrayq() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(N | 0x80000000)
    {}
    __forceinline ~hkInplaceArrayq()
    {
        hkMemoryAllocatorq& alloc = hkGetMemoryRouter().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocatorq& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void reserve(int n)
    {
        GrowArrayCapacity(hkGetMemoryRouter().heap(), n);
    }
};


// @fnv 0x00cb0c70
// src: HAVOK_LIB 0x00cb0c70
void hkStringPtr::printf_00cb0c70(const char* fmt, ...)
{
    hkInplaceArrayq<char, 255> buf;
    hk_va_list args = (hk_va_list)&fmt + sizeof(fmt);
    while (1)
    {
        int size = buf.getCapacity();
        int nchars = hkString_vsnprintf(buf.begin(), size, fmt, args);
        if (nchars >= 0 && nchars < size)
        {
            break;
        }
        else if (nchars < 0)
        {
            buf.reserve(buf.getCapacity() * 2);
        }
        else
        {
            buf.reserve(nchars);
        }
    }
    *this = buf.begin();
    *this = buf.begin();
}
