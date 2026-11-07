
// src/staging/blk_00a00000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/MemoryManager.h"


extern MemoryManager g_memoryManager;

struct FUN_00a1c020_Class
{
    void* AllocateShifted(unsigned int size);
};

// Allocates size << 5 bytes through g_memoryManager and returns the resulting pointer.
// @fnv 0x00a1c020
void* FUN_00a1c020_Class::AllocateShifted(unsigned int size)
{
    void* result = g_memoryManager.Allocate(size << 5);
    return result;
}

namespace fnv_00a1c050 {


struct FUN_00a1c050_Class
{
    void* Reallocate_Thunk(void* p, unsigned int n);
};

// @fnv 0x00a1c050
// src: GUESS 0x00a1c050 (confidence: medium)
void* __thiscall FUN_00a1c050_Class::Reallocate_Thunk(void* p, unsigned int n)
{
    return g_memoryManager.Reallocate(p, n << 5);
}
}  // namespace fnv_00a1c050

struct FUN_00a1e720_class
{
    void __thiscall BSMapBase_unsigned_int_ScrapHeap_SetValue(int a, int b, int c);
};

// @fnv 0x00a1e720
// src: COMMUNITY 0x00a1e720
void __thiscall FUN_00a1e720_class::BSMapBase_unsigned_int_ScrapHeap_SetValue(int pObject, int b, int c)
{
    *(int*)((char*)pObject + 4) = b;
    *(int*)((char*)pObject + 8) = c;
}

extern void* NiFreeAlias(void*);
extern int DAT_01095524;

struct FUN_00a1e1a0_class
{
    int m_vtbl;
    int m_field;
    void __thiscall ReleaseStorage_00a1e1a0();
};

// Sets the vtable pointer to DAT_01095524 and frees the m_field pointer via NiFreeAlias.
// @fnv 0x00a1e1a0
// src: GUESS 0x00a1e1a0 (confidence: medium)
void __thiscall FUN_00a1e1a0_class::ReleaseStorage_00a1e1a0()
{
    m_vtbl = (int)&DAT_01095524;
    void* p = (void*)m_field;
    NiFreeAlias(p);
}

struct FUN_00a11d80_Class
{
    void __thiscall InitAndClear();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
// Calls InitAndClear, then deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00a11d80
void* __thiscall FUN_00a11d80_Class::DestroyIfFlagged(unsigned int flags)
{
    InitAndClear();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

namespace fnv_00a1c100 {


struct FUN_00a1c100_Class
{
    void __thiscall Reset();
    void* __thiscall FUN_00a1c100(unsigned int flags);
};

// @fnv 0x00a1c100
void* __thiscall FUN_00a1c100_Class::FUN_00a1c100(unsigned int flags)
{
    Reset();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00a1c100

namespace fnv_00a1e400 {
void NiFree(void*);

struct FUN_00a1e400_class
{
    int m_vtbl;
    int m_field;
    FUN_00a1e400_class* __thiscall FUN_00a1e400(int flags);
};

// Sets the vtable, frees m_field via NiFree, and if flags has bit 0 set deallocates this through the memory manager; returns this.
// @fnv 0x00a1e400
FUN_00a1e400_class* __thiscall FUN_00a1e400_class::FUN_00a1e400(int flags)
{
    void* old;
    m_vtbl = (int)&DAT_01095524;
    old = (void*)m_field;
    NiFree(old);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00a1e400

extern unsigned int DAT_010173f0;
void __cdecl FUN_00ec30b0();
int __cdecl _FUN_00ec7c66(void* dst, unsigned int size, const void* src, unsigned int count);
struct _Secure_char_traits_tag
{
    char _Dummy;
};
struct StrA
{
    int _Alval;
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    bool _Inside(const char*);
    bool _Grow(unsigned int, bool);
    StrA& UpdateState_00a0c570(const StrA&, unsigned int, unsigned int);
    StrA& std_string_append(const char* _Ptr, unsigned int _Count);
};
// Appends _Count characters from _Ptr to the string, growing the buffer if needed and handling self-referential input.
// @fnv 0x00a0c430
// src: COMMUNITY 0x00a0c430
StrA& StrA::std_string_append(const char* apChars, unsigned int auiCount)
{
    if (_Inside(apChars))
        return UpdateState_00a0c570(*this, apChars - (16 <= _Myres ? _Bx._Ptr : _Bx._Buf), auiCount);
    if (DAT_010173f0 - _Mysize <= auiCount || _Mysize + auiCount < _Mysize)
        FUN_00ec30b0();
    unsigned int uiNewSize;
    char acReserved[44];
    if (0 < auiCount && _Grow(uiNewSize = _Mysize + auiCount, false))
    {
        _Secure_char_traits_tag _Tag;
        _Secure_char_traits_tag _Tag2;
        {
            char* pDest;
            {
                unsigned int uiTailSize;
                pDest = (16 <= _Myres ? _Bx._Ptr : _Bx._Buf) + (uiTailSize = _Myres - _Mysize, _Mysize);
                _Tag2 = _Tag;
                _FUN_00ec7c66(pDest, uiTailSize, apChars, auiCount);
                char cNul = 0;
                _Mysize = uiNewSize;
                (16 <= _Myres ? _Bx._Ptr : _Bx._Buf)[uiNewSize] = cNul;
            }
        }
    }
    return *this;
}

void* __cdecl _NiMalloc(unsigned int);
void* __cdecl _fnv_zlib_memset(void* dst, int c, unsigned int n);
extern int DAT_01094e1c;
struct FUN_00a0d5f0_class
{
    int* m_vtbl;
    int m_iElementCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00a0d5f0_class* __thiscall NiTMapBase_NiTPointerAllocator_unsigned_int_char_const_int_NiTMapBase_NiTPointerAllocator_unsigned_int_char_const_int(unsigned int size);
};
// Sets the vtable, stores size, allocates size*4 bytes, zeroes them and stores the pointer in m_data.
// @fnv 0x00a0d5f0
// src: COMMUNITY 0x00a0d5f0
FUN_00a0d5f0_class* __thiscall FUN_00a0d5f0_class::NiTMapBase_NiTPointerAllocator_unsigned_int_char_const_int_NiTMapBase_NiTPointerAllocator_unsigned_int_char_const_int(unsigned int size)
{
    unsigned int iAllocationSize;
    unsigned int memsetSize;
    void* data2;
    m_vtbl = (int*)&DAT_01094e1c;
    m_iElementCount = size;
    m_auiShapeKeys = 0;
    iAllocationSize = m_iElementCount << 2;
    m_data = _NiMalloc(iAllocationSize);
    memsetSize = m_iElementCount << 2;
    data2 = m_data;
    _fnv_zlib_memset(data2, 0, memsetSize);
    return this;
}

void* _NiMalloc(unsigned int);
void* _fnv_zlib_memset(void* dest, int val, unsigned int size);
extern int DAT_01094e9c;
struct FUN_00a0d8e0
{
    int* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00a0d8e0(int count);
};
// Sets the vtable, stores count, allocates count*4 bytes, and zero-fills the buffer.
// @fnv 0x00a0d8e0
FUN_00a0d8e0::FUN_00a0d8e0(int count)
{
    m_vtbl = (int*)&DAT_01094e9c;
    m_uiItemCount = count;
    m_auiShapeKeys = 0;
    int sz3 = m_uiItemCount << 2;
    m_data = _NiMalloc(sz3);
    int sz2 = m_uiItemCount << 2;
    void* p2 = m_data;
    _fnv_zlib_memset(p2, 0, sz2);
}

struct FUN_00a1c080_Class
{
    FUN_00a1c080_Class* m_next;
    int m_field;
    int m_uiItemCount;
    int PopFront();
};
// Unlinks the head node from a singly linked list, clears its field, deallocates it, decrements the count and returns the node's stored value.
// @fnv 0x00a1c080
int FUN_00a1c080_Class::PopFront()
{
    FUN_00a1c080_Class* oldNext;
    FUN_00a1c080_Class* next6 = m_next;
    m_next = m_next->m_next;
    if (m_next)
        m_next->m_field = 0;
    else
        m_field = 0;
    int result5 = next6->m_uiItemCount;
    next6->m_uiItemCount = 0;
    oldNext = next6;
    g_memoryManager.Deallocate(oldNext);
    --m_uiItemCount;
    return result5;
}

void* __cdecl NiMalloc(unsigned int);

struct FUN_00a1e450_Class
{
    int* m_vtbl;
    void* m_data;
    unsigned short m_iElementCount;
    unsigned short m_auiShapeKeys;
    unsigned short m_uiX;
    unsigned short m_uiY;
    FUN_00a1e450_Class(unsigned short size, unsigned short x);
};

// Sets the vtable, stores size and x, zeroes two fields, and allocates size*4 bytes into m_data when size is greater than zero.
// @fnv 0x00a1e450
FUN_00a1e450_Class::FUN_00a1e450_Class(unsigned short size, unsigned short x)
{
    m_vtbl = (int*)&DAT_01095524;
    m_iElementCount = size;
    m_uiY = x;
    m_auiShapeKeys = 0;
    m_uiX = 0;
    if (m_iElementCount > 0)
    {
        unsigned int n = m_iElementCount;
        m_data = NiMalloc(n * 4);
    }
    else
    {
        m_data = 0;
    }
}

extern int DAT_010955e4;
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);
struct FUN_00a1eaa0
{
    int* vtbl;
    int count;
    int* data;
    int pad;
    FUN_00a1eaa0(int n);
};
// Sets the vtable, stores n as count, allocates count*4 bytes and zero-fills the data buffer.
// @fnv 0x00a1eaa0
FUN_00a1eaa0::FUN_00a1eaa0(int aiCount)
{
    int size;
    int size2;
    int* p3;
    vtbl = &DAT_010955e4;
    count = aiCount;
    pad = 0;
    size = count << 2;
    data = (int*)_NiMalloc(size);
    size2 = count << 2;
    p3 = data;
    _fnv_zlib_memset(p3, 0, size2);
}

extern int DAT_01095664;
void* __cdecl NiMalloc(unsigned int size);
void* __cdecl fnv_zlib_memset(void* dest, int c, unsigned int size);
struct FUN_00a1ede0
{
    int* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00a1ede0(int count);
};
// Sets the vtable, stores count and zeroes a newly allocated count*4-byte buffer.
// @fnv 0x00a1ede0
FUN_00a1ede0::FUN_00a1ede0(int count)
{
    m_vtbl = &DAT_01095664;
    m_uiItemCount = count;
    m_auiShapeKeys = 0;
    int sz2 = m_uiItemCount << 2;
    m_data = NiMalloc(sz2);
    int sz1 = m_uiItemCount << 2;
    void* p5 = m_data;
    fnv_zlib_memset(p5, 0, sz1);
}

extern void* NiMalloc(unsigned int);
extern int DAT_0109568c;

struct FUN_00a1eeb0_class
{
    void* vtbl;
    void* data;
    unsigned short count;
    unsigned short a;
    unsigned short stride;
    unsigned short b;
    FUN_00a1eeb0_class(unsigned short c, unsigned short s);
};

// Sets the vtable, stores count and s, zeroes a and stride, and allocates count*4 bytes for data when count > 0, otherwise data is null.
// @fnv 0x00a1eeb0
FUN_00a1eeb0_class::FUN_00a1eeb0_class(unsigned short ausCount, unsigned short s)
{
    vtbl = (void*)&DAT_0109568c;
    count = ausCount;
    b = s;
    a = 0;
    stride = 0;
    unsigned int sz;
    if (count > 0)
    {
        sz = count;
        data = NiMalloc(sz * 4);
    }
    else
    {
        data = 0;
    }
}

extern int DAT_01094e5c;
struct FUN_00a0d710_class
{
    int* m_vtbl;
    int m_iElementCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00a0d710_class* __thiscall NiTMapBase_NiTPointerAllocator_unsigned_int_int_int_Init(unsigned int size);
};
// @fnv 0x00a0d710
// src: COMMUNITY 0x00a0d710
FUN_00a0d710_class* FUN_00a0d710_class::NiTMapBase_NiTPointerAllocator_unsigned_int_int_int_Init(unsigned int size)
{
    unsigned int a;
    void* b;
    unsigned int c;
    m_vtbl = &DAT_01094e5c;
    m_iElementCount = size;
    m_auiShapeKeys = 0;
    a = m_iElementCount << 2;
    m_data = _NiMalloc(a);
    c = m_iElementCount << 2;
    b = m_data;
    _fnv_zlib_memset(b, 0, c);
    return this;
}

extern void __cdecl _NiFree(void*);
struct FUN_00a1ee60_class
{
    int* m_vtbl;
    void* m_data;
    FUN_00a1ee60_class(unsigned short c);
    FUN_00a1ee60_class* __thiscall FUN_00a1ee60(int freeMem);
};
// @fnv 0x00a1ee60
FUN_00a1ee60_class* FUN_00a1ee60_class::FUN_00a1ee60(int freeMem)
{
    m_vtbl = &DAT_0109568c;
    void* data = m_data;
    _NiFree(data);
    if (freeMem & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct S00a0d390
{
    int* m_vtbl;
    int m_field;
    void __thiscall ClearAll();
};

struct FUN_00a0d960_class : S00a0d390
{
    void* m_data;
    void ReleaseStorage_00a0d960();
};

// @fnv 0x00a0d960
// src: GUESS 0x00a0d960 (confidence: medium)
void FUN_00a0d960_class::ReleaseStorage_00a0d960()
{
    int unused;
    int padding;
    m_vtbl = &DAT_01094e9c;
    ClearAll();
    _NiFree(m_data);
}

struct _BSAHelper
{
    void Clear(bool);
};

extern unsigned int DAT_0109504c;

// Sets the object's vtable pointer to DAT_0109504c, then calls Clear(true) on the object.
// @fnv 0x00a11d00
void FUN_00a11d80_Class::InitAndClear()
{
    int unused;

    *reinterpret_cast<int**>(this) = reinterpret_cast<int*>(&DAT_0109504c);
    reinterpret_cast<_BSAHelper*>(this)->Clear(true);
}

struct FUN_00a1e520_class
{
    int* m_vtbl;
    int* m_data;
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short m_live;
    void __thiscall Resize(unsigned int size);
};

// @fnv 0x00a1e520
void FUN_00a1e520_class::Resize(unsigned int size)
{
    unsigned short b;
    unsigned int o;
    int* d;

    if (size == m_iElementCount)
    {
        return;
    }

    if (size < m_uiItemCount)
    {
        for (b = static_cast<unsigned short>(size); b < m_uiItemCount; b++)
        {
            if (m_data[b] != 0)
            {
                m_data[b] = 0;
                --m_live;
            }
        }
        m_uiItemCount = static_cast<unsigned short>(size);
    }

    d = m_data;
    m_iElementCount = static_cast<unsigned short>(size);

    if (size > 0)
    {
        o = m_iElementCount;
        m_data = static_cast<int*>(_NiMalloc(o * 4));

        for (b = 0; b < m_uiItemCount; b++)
        {
            m_data[b] = d[b];
        }

        for (b = m_uiItemCount; b < m_iElementCount; b++)
        {
            m_data[b] = 0;
        }
    }
    else
    {
        m_data = 0;
    }

    _NiFree(d);
}

struct FUN_00a0d2a0_Obj
{
    void FUN_00a0d2a0();
};



struct FUN_00a0d5c0_Local
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct FUN_00a0d5c0_Class
{
    int __thiscall FUN_00a0d5c0(int arg);
};

// Calls FUN_00a0d2a0 on this, then if bit 0 of arg is set calls FUN_00aa4060 on this, and returns this as an int.
// @fnv 0x00a0d5c0
int __thiscall FUN_00a0d5c0_Class::FUN_00a0d5c0(int aiFlags)
{
    FUN_00a0d5c0_Local local;

    reinterpret_cast<FUN_00a0d2a0_Obj*>(this)->FUN_00a0d2a0();

    if ((aiFlags & 1) != 0)
    {
        g_memoryManager.Deallocate(this);
    }

    return reinterpret_cast<int>(this);
}

struct FUN_00a0d7c0_Arg
{
    int unk00;
    int unk04;
    int m08;
};

struct FUN_00a0d7c0_Sub
{
    int unk00;
    void __thiscall Process(FUN_00a0d7c0_Arg* arg);
};

struct FUN_00a0d7c0_Locals
{
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_00a0d7c0_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00a0d7c0_Sub m0c;
    void ResetAndProcess(FUN_00a0d7c0_Arg* arg);
};

// Clears arg->m08 and forwards arg to m0c.Process.
// @fnv 0x00a0d7c0
void FUN_00a0d7c0_cls::ResetAndProcess(FUN_00a0d7c0_Arg* arg)
{
    FUN_00a0d7c0_Locals locals;
    arg->m08 = 0;
    m0c.Process(arg);
}

namespace fnv_00a11fa0 {


class FUN_00a11fa0_cls
{
  public:
    void* m_00;
    FUN_00a11fa0_cls* m_04;
    int m_08;

    int RemoveNextNode();
};

// Unlinks the node after this one, releases it to the pool, decrements the count and returns the removed node's value.
// @fnv 0x00a11fa0
int FUN_00a11fa0_cls::RemoveNextNode()
{
    FUN_00a11fa0_cls* node2 = this->m_04;
    this->m_04 = this->m_04->m_04;
    if (this->m_04 != 0)
    {
        this->m_04->m_00 = 0;
    }
    else
    {
        this->m_00 = 0;
    }
    int result2 = node2->m_08;
    node2->m_08 = 0;
    FUN_00a11fa0_cls* volatile released = node2;
    g_memoryManager.Deallocate(released);
    this->m_08 = this->m_08 - 1;
    return result2;
}
}  // namespace fnv_00a11fa0

void NiFree(void*);
struct FUN_00a1e880_class : S00a0d390
{
    void* m_data;
    void SetVirtualTable_00a1e880();
};
// @fnv 0x00a1e880
// src: GUESS 0x00a1e880 (confidence: low)
void FUN_00a1e880_class::SetVirtualTable_00a1e880()
{
    m_vtbl = (int*)&DAT_010955e4;
    void* pAssertA;
    void* pAssertB;  // only used by debug asserts in the original build
    ClearAll();
    NiFree(m_data);
}

// FUN_00a1ea70 (unit_1a635d660b3a.cpp) - 48B scalar-deleting-destructor shape
// v0: verbatim transcription of IDA a1ea70..0xa1eaa0 (push ebp/mov/sub esp,20h/
// mov[ebp-20h],ecx; call FUN_00a1e900(this); if(a2&1) g_memoryManager.Deallocate(this); return this)
// frame pinned via unused Q7 struct (probe2/probe3 verified sub esp,20h + this@-20h, zero extra insns)
struct FUN_00a1e900_Class
{
    int __thiscall FUN_00a1e900();
};

struct Q7
{
    int v4, v8, vC, v10, v14, v18, v1C;
};
struct FUN_00a1ea70_Class
{
    void* __thiscall FUN_00a1ea70(unsigned int a2);
};
// @fnv 0x00a1ea70
void* __thiscall FUN_00a1ea70_Class::FUN_00a1ea70(unsigned int auiFlags)
{
    Q7 q;
    (void)q;
    ((FUN_00a1e900_Class*)this)->FUN_00a1e900();
    if ((auiFlags & 1) != 0)
        g_memoryManager.Deallocate((void*)this);
    return this;
}

namespace fnv_00a1ebf0 {
extern int DAT_01095664;



struct FUN_00a1ebf0_Class : S00a0d390
{
    void* m_data;
    int m_auiShapeKeys;
    void* __thiscall FUN_00a1ebf0(int flags);
};

void _NiFree_00aa10f0(void* arg);

// @fnv 0x00a1ebf0
void* __thiscall FUN_00a1ebf0_Class::FUN_00a1ebf0(int flags)
{
    int _temp1;
    int _temp2;
    m_vtbl = &DAT_01095664;
    ClearAll();
    _NiFree_00aa10f0(m_data);
    if ((flags & 1) != 0)
    {
        g_memoryManager.Deallocate(this);
    }
    return this;
}
}  // namespace fnv_00a1ebf0

struct FUN_00a0c7a0_shell
{
    BSSimpleList<unsigned char*> m_kNode;
    void ClearList();
};
// @fnv 0x00a0c7a0
void FUN_00a0c7a0_shell::ClearList()
{
    int local_c;
    int local_8;
    int local_4;
    m_kNode.RemoveAll();
}

struct S_00a0c9f0_Node
{
    S_00a0c9f0_Node* m_pkNext;
    S_00a0c9f0_Node* m_pkPrev;
    int m_val;
};

struct S_00a0c9f0_Pool
{
    int m_uiCount;
    S_00a0c9f0_Node* NiGeometry_AddProperty();
};

class S_00a0c9f0
{
    S_00a0c9f0_Node* m_pkHead;
    S_00a0c9f0_Node* m_pkTail;
    S_00a0c9f0_Pool m_kNodePool;

  public:
    void __thiscall _NiTListBase_AddHead(int* pValue);
};

// @fnv 0x00a0c9f0
// src: COMMUNITY 0x00a0c9f0
void __thiscall S_00a0c9f0::_NiTListBase_AddHead(int* pValue)
{
    volatile int dummy_frame[7];
    S_00a0c9f0_Node* pNode = m_kNodePool.NiGeometry_AddProperty();
    pNode->m_val = *pValue;
    pNode->m_pkPrev = 0;
    pNode->m_pkNext = m_pkHead;

    if (m_pkHead)
    {
        m_pkHead->m_pkPrev = pNode;
    }
    else
    {
        m_pkTail = pNode;
    }

    m_pkHead = pNode;
    m_kNodePool.m_uiCount++;
    (void)dummy_frame;
}

struct FUN_00a0d790_class : S00a0d390
{
    void* m_data;
    void UpdateState_00a0d790();
};
// @fnv 0x00a0d790
// src: GUESS 0x00a0d790 (confidence: low)
void FUN_00a0d790_class::UpdateState_00a0d790()
{
    int unusedA;
    int unusedB;
    m_vtbl = &DAT_01094e5c;
    ClearAll();
    NiFree(m_data);
}

extern int DAT_01094e9c;
extern void* __cdecl _NiFree_00aa10f0(void*);

struct FUN_00a0d990_cls : S00a0d390
{
    void* m_data;
    int __thiscall FUN_00a0d990(int arg);
};

// @fnv 0x00a0d990
int __thiscall FUN_00a0d990_cls::FUN_00a0d990(int aiFlags)
{
    int a;
    int b;
    (void)a;
    (void)b;
    this->m_vtbl = reinterpret_cast<int*>(&DAT_01094e9c);
    this->ClearAll();
    _NiFree_00aa10f0(this->m_data);
    if ((aiFlags & 1) != 0)
    {
        g_memoryManager.Deallocate(this);
    }
    return reinterpret_cast<int>(this);
}

struct FUN_00a1ebc0
{
    int m_field;
    void* m_data;
    virtual ~FUN_00a1ebc0();
};

// @fnv 0x00a1ebc0
FUN_00a1ebc0::~FUN_00a1ebc0()
{
    unsigned int i;
    void* node;
    ((S00a0d390*)this)->ClearAll();
    _NiFree(m_data);
}

struct S
{
    int* m_vtbl;
    void Clear(bool);
    void Reset();
};
extern int DAT_0109527c;
// Sets m_vtbl to DAT_0109527c and calls Clear(true).
// @fnv 0x00a1bf80
void S::Reset()
{
    int unused;
    m_vtbl = &DAT_0109527c;
    Clear(true);
}


struct FUN_00a1ec40_Class
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    void __thiscall FUN_00a1ec70();
    FUN_00a1ec40_Class* FUN_00a1ec40(unsigned int flags);
};

// Calls FUN_00a1ec70, then if bit 0 of flags is set calls DAT_011f6238.FUN_00aa4060 on this, and returns this.
// @fnv 0x00a1ec40
FUN_00a1ec40_Class* FUN_00a1ec40_Class::FUN_00a1ec40(unsigned int flags)
{
    int l0, l1, l2, l3, l4, l5, l6;
    FUN_00a1ec70();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct S00a0ca70_Node
{
    S00a0ca70_Node* m_pkNext;
    void* m_pkPrev;
    unsigned int m_val;
};
struct S00a0ca70_Pool
{
    unsigned int m_uiCount;
    S00a0ca70_Node* NiGeometry_AddProperty();
};
struct S00a0ca70_Blk
{
    int v4, v8, vC, v10, v14, v18, v1C;
};
class S00a0ca70_List
{
  public:
    unsigned int m_unk00;
    S00a0ca70_Node* m_pkHead;
    S00a0ca70_Pool m_kNodePool;
    S00a0ca70_Node* AllocateAndInsertListNode(S00a0ca70_Node** pos, const unsigned int* value);
};
// Allocates a node from m_kNodePool, sets its m_val, and splices it into the linked list at the position pointed to by pos.
// @fnv 0x00a0ca70
// src: GUESS 0x00a0ca70 (confidence: high)
S00a0ca70_Node* S00a0ca70_List::AllocateAndInsertListNode(S00a0ca70_Node** pos, const unsigned int* value)
{
    S00a0ca70_Node** pForm;
    S00a0ca70_Blk blk;
    S00a0ca70_Node* node2;
    node2 = m_kNodePool.NiGeometry_AddProperty();
    node2->m_val = *value;
    pForm = pos;
    node2->m_pkPrev = pForm;
    node2->m_pkNext = *pForm;
    if (*pForm != 0)
    {
        (*pForm)->m_pkPrev = node2;
    }
    else
    {
        m_pkHead = node2;
    }
    *pForm = node2;
    m_kNodePool.m_uiCount = 1 + m_kNodePool.m_uiCount;
    return node2;
}
