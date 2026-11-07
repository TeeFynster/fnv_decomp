#include "../../include/NiTMapItem.h"

// src/staging/blk_00a00000_od_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/staging/blk_00a00000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00a00000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/BSSimpleList.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiFixedString.h"
#include "../../include/StrMem.h"
#include <string.h>
#include "../../include/NiAVObject.h"
#include "../../include/Tile3D.h"
struct FUN_00a1c020_Class
{
    void* AllocateShifted(unsigned int size);
};
struct FUN_00a1e720_class
{
    void __thiscall BSMapBase_unsigned_int_ScrapHeap_SetValue(int a, int b, int c);
};
extern void* NiFreeAlias(void*);
extern int DAT_01095524;
struct FUN_00a1e1a0_class
{
    int m_vtbl;
    int m_field;
    void __thiscall ReleaseStorage_00a1e1a0();
};
struct FUN_00a11d80_Class
{
    void __thiscall InitAndClear();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
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
struct FUN_00a1c080_Class
{
    FUN_00a1c080_Class* m_next;
    int m_field;
    int m_uiItemCount;
    int PopFront();
};
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
extern int DAT_01094e5c;
struct FUN_00a0d710_class
{
    int* m_vtbl;
    int m_iElementCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00a0d710_class* __thiscall NiTMapBase_NiTPointerAllocator_unsigned_int_int_int_Init(unsigned int size);
};
extern void __cdecl _NiFree(void*);
struct FUN_00a1ee60_class
{
    int* m_vtbl;
    void* m_data;
    FUN_00a1ee60_class(unsigned short c);
    FUN_00a1ee60_class* __thiscall FUN_00a1ee60(int freeMem);
};
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
struct _BSAHelper
{
    void Clear(bool);
};
extern unsigned int DAT_0109504c;
struct FUN_00a1e520_class
{
    int* m_vtbl;
    int* m_data;
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short m_live;
    void __thiscall Resize(unsigned int size);
};
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
void NiFree(void*);
struct FUN_00a1e880_class : S00a0d390
{
    void* m_data;
    void SetVirtualTable_00a1e880();
};
// FUN_00a1ea70 (unit_1a635d660b3a.cpp) - 48B scalar-deleting-destructor shape
// v0: verbatim transcription of IDA a1ea70..0xa1eaa0 (push ebp/mov/sub esp,20h/
// mov[ebp-20h],ecx; call FUN_00a1e900(this); if(a2&1) MemoryManager::_g_memoryManager.Deallocate(this); return this)
// frame pinned via unused Q7 struct (probe2/probe3 verified sub esp,20h + this@-20h, zero extra insns)
struct FUN_00a1e900_Class
{
    int __thiscall FUN_00a1e900();
};
extern MemoryManager _g_memoryManager;
struct Q7
{
    int v4, v8, vC, v10, v14, v18, v1C;
};
struct FUN_00a1ea70_Class
{
    void* __thiscall FUN_00a1ea70(unsigned int a2);
};
struct FUN_00a0c7a0_shell
{
    BSSimpleList<unsigned char*> m_kNode;
    void ClearList();
};
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
struct FUN_00a0d790_class : S00a0d390
{
    void* m_data;
    void UpdateState_00a0d790();
};
extern int DAT_01094e9c;
extern void* __cdecl _NiFree_00aa10f0(void*);
struct FUN_00a0d990_cls : S00a0d390
{
    void* m_data;
    int __thiscall FUN_00a0d990(int arg);
};
struct FUN_00a1ebc0
{
    int m_field;
    void* m_data;
    virtual ~FUN_00a1ebc0();
};

struct CountedRange
{
    void* data;
    unsigned short count, capacity;
};
struct FloatBounds
{
    float left, top, right, bottom;
};

static __inline unsigned short SaturateU16(unsigned int v)
{
    return v <= 0xffffu ? (unsigned short)v : 0xffffu;
}

struct FUN_00a0beb0 : CountedRange
{
    CountedRange second, third;
    FloatBounds bounds;
    FUN_00a0beb0();
};

// @fnv 0x00a0beb0
FUN_00a0beb0::FUN_00a0beb0()
{
    CountedRange* a;
    CountedRange* b;
    FloatBounds* c;
    data = 0;
    count = SaturateU16(0);
    capacity = SaturateU16(0);
    a = &second;
    a->data = 0;
    a->count = SaturateU16(0);
    a->capacity = SaturateU16(0);
    b = &third;
    b->data = 0;
    b->count = SaturateU16(0);
    b->capacity = SaturateU16(0);
    c = &bounds;
    c->left = 0.0f;
    c->top = 0.0f;
    c->right = 0.0f;
    c->bottom = 0.0f;
}

struct S00a0d7f0 : S00a0d390
{
    void* m_data;
    int m_live;

    void RemoveAll()
    {
        unsigned int i;
        void* pkSave;
        for (i = 0; i < (unsigned int)m_field; i++)
        {
            if (((void**)m_data)[i] != 0)
            {
                pkSave = ((void**)m_data)[i];
                ((void**)m_data)[i] = *(void**)pkSave;
                NiFree(pkSave);
            }
        }
        m_live = 0;
    }

    void* __thiscall FUN_00a0d7f0(unsigned int flags);
};

// @fnv 0x00a0d7f0
void* __thiscall S00a0d7f0::FUN_00a0d7f0(unsigned int flags)
{
    m_vtbl = (int*)&DAT_01094e5c;
    RemoveAll();
    NiFree(m_data);
    if (flags & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

extern NiFixedString* DAT_011f34cc;
extern const char* DAT_0109b220;

inline void NiFixedString::operator delete(void* pvMem)
{
    _g_memoryManager.Deallocate(pvMem);
}


// @fnv 0x00a1c790
// src: GUESS 0x00a1c790 (confidence: low)
void __cdecl Runtime_ReleaseStorage_00a1c790()
{
    delete DAT_011f34cc;
}

__forceinline void StrMem::SetLength(unsigned int n)
{
    length = n <= 0xffff ? (unsigned short)n : 0xffff;
}

__forceinline void StrMem::SetMaxLength(unsigned int n)
{
    capacity = n <= 0xffff ? (unsigned short)n : 0xffff;
}

__forceinline StrMem::StrMem()
{
    text = 0;
    SetLength(0);
    SetMaxLength(0);
}

// Tile3D's constructor; derived from Tile (whose constructor 0x00709860 it calls) because this unit's StrMem carries the
// inline string constructors the original expands for +0x40/+0x48, which the shared Tile3D's BSStringT members lack here.
struct FUN_00a0bc80 : Tile
{
    void* m_pParent;
    int unk3C;
    StrMem str40;
    StrMem str48;
    FUN_00a0bc80();
    __forceinline void Dead2()
    {
        int aiF[2];
    }
    virtual ~FUN_00a0bc80();
};

// @fnv 0x00a0bc80
FUN_00a0bc80::FUN_00a0bc80()
{
    int aiD[7];
    Dead2();
    m_pRenderedNodeEntry = 0;
    m_pParent = 0;
    unk3C = 0;
}

void __cdecl FUN_00ec30e8();
struct StrTraitsB
{
    static char* copy_s(char* _First1, unsigned int _Size_in_bytes, const char* _First2, unsigned int _Count,
                        _Secure_char_traits_tag _Tg)
    {
        _FUN_00ec7c66(_First1, _Size_in_bytes, _First2, _Count);
        return _First1;
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline _Secure_char_traits_tag _Char_traits_cat()
{
    _Secure_char_traits_tag _Cat;
    return _Cat;
}
struct StrTraitsHelperB
{
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        int aiD[6];
        return StrTraitsB::copy_s(_First1, _Size, _First2, _Count, _Char_traits_cat());
    }
};
struct StrB
{
    int _Alval;
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    bool _Grow(unsigned int, bool _Trim = false);
    unsigned int size() const
    {
        return _Mysize;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        StrTraitsB::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    StrB& UpdateState_00a0c570(const StrB& _Right, unsigned int _Roff, unsigned int _Count);
};
// @fnv 0x00a0c570
// src: GUESS 0x00a0c570 (confidence: low)
StrB& StrB::UpdateState_00a0c570(const StrB& _Right, unsigned int _Roff, unsigned int _Count)
{
    if (_Right.size() < _Roff)
        FUN_00ec30e8();
    unsigned int _Num = _Right.size() - _Roff;
    if (_Num < _Count)
        _Count = _Num;
    if (DAT_010173f0 - _Mysize <= _Count || _Mysize + _Count < _Mysize)
        FUN_00ec30b0();
    if (0 < _Count && _Grow(_Num = _Mysize + _Count))
    {
        StrTraitsHelperB::copy_s(_Myptr() + _Mysize, _Myres - _Mysize, _Right._Myptr() + _Roff, _Count);
        _Eos(_Num);
    }
    return *this;
}

struct FUN_00a1bc70_Base
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
// @fnv 0x00a1bc70
    FUN_00a1bc70_Base()
    {
        m_08 = 0;
        m_00 = 0;
        m_04 = 0;
    }
};

struct FUN_00a1bc70_Sub
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~FUN_00a1bc70_Sub();
};

class FUN_00a1bc70 : public FUN_00a1bc70_Base
{
  public:
    FUN_00a1bc70_Sub m_10;
    unsigned int m_20[8];
    unsigned int m_40;

    FUN_00a1bc70(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4);
    int CallStep(unsigned int a, unsigned int b);
};

FUN_00a1bc70::FUN_00a1bc70(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
    m_10.m_00 = 0;
    m_10.m_04 = a3;
    m_10.m_08 = a4;
    m_40 = a1;
    for (int i = 0; i < 8; i++)
    {
        m_20[i] = 0;
    }
    m_10.m_0c = 0x23;
    CallStep(a2, 0);
}

extern "C" int __cdecl memcmp(const void* a, const void* b, unsigned int n);

struct CharTraitsQ
{
    static bool eq(const char& _Left, const char& _Right)
    {
        return _Left == _Right;
    }
    static int compare(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
    }
};

struct StringQ
{
    enum
    {
        _BUF_SIZE = 16
    };
    int _Alval;
    union
    {
        char _Buf[_BUF_SIZE];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;

    static const unsigned int npos;

    const char* _Myptr() const
    {
        return (_BUF_SIZE <= _Myres ? _Bx._Ptr : _Bx._Buf);
    }

    unsigned int std_string_rfind(const char* _Ptr, unsigned int _Off, unsigned int _Count) const;
};

// @fnv 0x00a0c300
// src: COMMUNITY 0x00a0c300
unsigned int StringQ::std_string_rfind(const char* _Ptr, unsigned int _Off, unsigned int _Count) const
{
    if (_Count == 0)
        return (_Off < _Mysize ? _Off : _Mysize);
    if (_Count <= _Mysize)
    {
        const char* _Uptr = _Myptr() + (_Off < _Mysize - _Count ? _Off : _Mysize - _Count);
        for (;; --_Uptr)
            if (CharTraitsQ::eq(*_Uptr, *_Ptr) && CharTraitsQ::compare(_Uptr, _Ptr, _Count) == 0)
                return (_Uptr - _Myptr());
            else if (_Uptr == _Myptr())
                break;
    }

    return (npos);
}

struct S00a1bc20_Guard
{
    ~S00a1bc20_Guard()
    {
        int u1;
        int u2;
    }
};

class S00a1bc20_Obj
{
  public:
    void ClearLinkedNodes();
    void ProcessState_00a1bc20();
};

// @fnv 0x00a1bc20
// src: GUESS 0x00a1bc20 (confidence: low)
void S00a1bc20_Obj::ProcessState_00a1bc20()
{
    S00a1bc20_Guard guard;
    this->ClearLinkedNodes();
}

void __cdecl NiFreeE900(void* pvMem);



class MapBaseE900
{
  public:
    virtual ~MapBaseE900()
    {
        RemoveAll();
        NiFreeE900(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(NiTMapItem<const char*, void*>* pkItem, const char* key, void* val);
    virtual void ClearValue(NiTMapItem<const char*, void*>* pkItem);
    virtual NiTMapItem<const char*, void*>* NewItem();
    virtual void DeleteItem(NiTMapItem<const char*, void*>* pkItem);

    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, void*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }

    unsigned int m_uiHashSize;
    NiTMapItem<const char*, void*>** m_ppkHashTable;
    unsigned int m_uiCount;
};

class PointerMapE900 : public MapBaseE900
{
  public:
    virtual ~PointerMapE900()
    {
        RemoveAll();
    }
};

class FUN_00a1e900 : public PointerMapE900
{
  public:
    virtual ~FUN_00a1e900();
    bool m_bCopy;
};

// @fnv 0x00a1e900
FUN_00a1e900::~FUN_00a1e900()
{
    if (m_bCopy)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            NiTMapItem<const char*, void*>* pkItem = m_ppkHashTable[i];
            while (pkItem)
            {
                NiTMapItem<const char*, void*>* pkSave = pkItem;
                pkItem = pkItem->m_pkNext;
                NiFreeE900((char*)pkSave->m_key);
            }
        }
    }
}

void __cdecl NiFreeE9F0(void* pvMem);



class MapBaseE9F0
{
  public:
    virtual ~MapBaseE9F0()
    {
        RemoveAll();
        NiFreeE9F0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(NiTMapItem<const char*, void*>* pkItem, const char* key, void* val);
    virtual void ClearValue(NiTMapItem<const char*, void*>* pkItem);
    virtual NiTMapItem<const char*, void*>* NewItem();
    virtual void DeleteItem(NiTMapItem<const char*, void*>* pkItem);

    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, void*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }

    unsigned int m_uiHashSize;
    NiTMapItem<const char*, void*>** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00a1e9f0 : public MapBaseE9F0
{
  public:
    virtual ~FUN_00a1e9f0();
};

// @fnv 0x00a1e9f0
FUN_00a1e9f0::~FUN_00a1e9f0()
{
    RemoveAll();
}

struct BucketNode
{
    BucketNode* next;
    void* key;
};

struct PointerArrayBase
{
    unsigned int bucketCount;
    BucketNode** buckets;
    unsigned int itemCount;
    virtual ~PointerArrayBase()
    {
        ClearAll();
        _NiFree_00aa10f0(buckets);
    }
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void ReleaseValue(BucketNode* node);
    virtual void Reserved5();
    virtual void FreeNode(BucketNode* node);
    void ClearAll()
    {
        for (unsigned int index = 0; index < bucketCount; ++index)
        {
            while (buckets[index])
            {
                BucketNode* node = buckets[index];
                buckets[index] = node->next;
                ReleaseValue(node);
                FreeNode(node);
            }
        }
        itemCount = 0;
    }
};

struct KeyMapBase : PointerArrayBase
{
    virtual ~KeyMapBase()
    {
        ClearAll();
    }
};

struct FUN_00a1ec70 : KeyMapBase
{
    bool freeKeys;
    virtual ~FUN_00a1ec70();
};

// @fnv 0x00a1ec70
FUN_00a1ec70::~FUN_00a1ec70()
{
    if (freeKeys)
    {
        for (unsigned int i = 0; i < bucketCount; ++i)
        {
            BucketNode* node = buckets[i];
            while (node)
            {
                BucketNode* saved = node;
                node = node->next;
                _NiFree_00aa10f0(saved->key);
            }
        }
    }
}

namespace fnv_00a1ed60 {
struct WeightedMapNode
{
    WeightedMapNode* next;
};

struct PointerArrayBase
{
    unsigned int bucketCount;
    WeightedMapNode** buckets;
    unsigned int itemCount;
    virtual ~PointerArrayBase()
    {
        ClearAll();
        _NiFree_00aa10f0(buckets);
    }
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void ReleaseValue(WeightedMapNode* node);
    virtual void Reserved5();
    virtual void FreeNode(WeightedMapNode* node);
    void ClearAll()
    {
        for (unsigned int index = 0; index < bucketCount; ++index)
        {
            while (buckets[index])
            {
                WeightedMapNode* node = buckets[index];
                buckets[index] = node->next;
                ReleaseValue(node);
                FreeNode(node);
            }
        }
        itemCount = 0;
    }
};

struct FUN_00a1ed60 : PointerArrayBase
{
    virtual ~FUN_00a1ed60();
};

// @fnv 0x00a1ed60
FUN_00a1ed60::~FUN_00a1ed60()
{
    ClearAll();
}
}  // namespace fnv_00a1ed60

void __cdecl NiFreeD4D0(void* pvMem);




class FUN_00a0d4d0
{
  public:
    static void operator delete(void* pvMem)
    {
        _g_memoryManager.Deallocate(pvMem);
    }

// @fnv 0x00a0d4d0
    virtual ~FUN_00a0d4d0()
    {
        RemoveAll();
        NiFreeD4D0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(NiTMapItem<const char*, void*>* pkItem, const char* key, void* val);
    virtual void ClearValue(NiTMapItem<const char*, void*>* pkItem);
    virtual NiTMapItem<const char*, void*>* NewItem();
    virtual void DeleteItem(NiTMapItem<const char*, void*>* pkItem);

    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, void*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }

    unsigned int m_uiHashSize;
    NiTMapItem<const char*, void*>** m_ppkHashTable;
    unsigned int m_uiCount;
};

void* MakeMapD4D0()
{
    return new FUN_00a0d4d0;
}

void __cdecl NiFreeD520(void* pvMem);




class MapBaseD520
{
  public:
    static void operator delete(void* pvMem)
    {
        _g_memoryManager.Deallocate(pvMem);
    }
    virtual ~MapBaseD520()
    {
        RemoveAll();
        NiFreeD520(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(NiTMapItem<const char*, void*>* pkItem, const char* key, void* val);
    virtual void ClearValue(NiTMapItem<const char*, void*>* pkItem);
    virtual NiTMapItem<const char*, void*>* NewItem();
    virtual void DeleteItem(NiTMapItem<const char*, void*>* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, void*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    NiTMapItem<const char*, void*>** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00a0d520 : public MapBaseD520
{
// @fnv 0x00a0d520
  public:
    __forceinline FUN_00a0d520()
    {}
    virtual ~FUN_00a0d520()
    {
        RemoveAll();
    }
};

void* MakeMapD520()
{
    return new FUN_00a0d520;
}

void __cdecl NiFreeD840(void* pvMem);




class MapBaseD840
{
  public:
    static void operator delete(void* pvMem)
    {
        _g_memoryManager.Deallocate(pvMem);
    }
    virtual ~MapBaseD840()
    {
        RemoveAll();
        NiFreeD840(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(NiTMapItem<const char*, void*>* pkItem, const char* key, void* val);
    virtual void ClearValue(NiTMapItem<const char*, void*>* pkItem);
    virtual NiTMapItem<const char*, void*>* NewItem();
    virtual void DeleteItem(NiTMapItem<const char*, void*>* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, void*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    NiTMapItem<const char*, void*>** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00a0d840 : public MapBaseD840
{
// @fnv 0x00a0d840
  public:
    __forceinline FUN_00a0d840()
    {}
    virtual ~FUN_00a0d840()
    {
        RemoveAll();
    }
};

void* MakeMapD840()
{
    return new FUN_00a0d840;
}

void __cdecl NiFreeE7E0(void* pvMem);




class MapBaseE7E0
{
  public:
    static void operator delete(void* pvMem)
    {
        _g_memoryManager.Deallocate(pvMem);
    }
    virtual ~MapBaseE7E0()
    {
        RemoveAll();
        NiFreeE7E0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(NiTMapItem<const char*, void*>* pkItem, const char* key, void* val);
    virtual void ClearValue(NiTMapItem<const char*, void*>* pkItem);
    virtual NiTMapItem<const char*, void*>* NewItem();
    virtual void DeleteItem(NiTMapItem<const char*, void*>* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, void*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    NiTMapItem<const char*, void*>** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00a1e7e0 : public MapBaseE7E0
{
// @fnv 0x00a1e7e0
  public:
    __forceinline FUN_00a1e7e0()
    {}
    virtual ~FUN_00a1e7e0()
    {
        RemoveAll();
    }
};

void* MakeMapE7E0()
{
    return new FUN_00a1e7e0;
}

void __cdecl NiFreeE8B0(void* pvMem);




class FUN_00a1e8b0
{
  public:
    static void operator delete(void* pvMem)
    {
        _g_memoryManager.Deallocate(pvMem);
    }

// @fnv 0x00a1e8b0
    virtual ~FUN_00a1e8b0()
    {
        RemoveAll();
        NiFreeE8B0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(NiTMapItem<const char*, void*>* pkItem, const char* key, void* val);
    virtual void ClearValue(NiTMapItem<const char*, void*>* pkItem);
    virtual NiTMapItem<const char*, void*>* NewItem();
    virtual void DeleteItem(NiTMapItem<const char*, void*>* pkItem);

    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, void*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }

    unsigned int m_uiHashSize;
    NiTMapItem<const char*, void*>** m_ppkHashTable;
    unsigned int m_uiCount;
};

void* MakeMapE8B0()
{
    return new FUN_00a1e8b0;
}

struct C_00a1eb20
{
    int m_uiItemCount;
    void** m_data;
    int m_live;
    virtual void v10(void* p)
    {}
    virtual void v18(void* p)
    {}
    void RemoveAll()
    {
        for (int i = 0; i < m_uiItemCount; i++)
        {
            if (m_data[i])
            {
                void* pkSave = m_data[i];
                m_data[i] = *(void**)m_data[i];
                v10(pkSave);
                v18(pkSave);
            }
        }
        m_live = 0;
    }
    virtual ~C_00a1eb20()
    {
        RemoveAll();
        NiFree(m_data);
    }
};

inline void operator delete(void* p)
{
    _g_memoryManager.Deallocate(p);
}

struct FUN_00a1eb20 : C_00a1eb20
{
// @fnv 0x00a1eb20
    virtual ~FUN_00a1eb20()
    {
        RemoveAll();
    }
};

void make_00a1eb20()
{
    new FUN_00a1eb20;
}

#include <string.h>
unsigned int __cdecl BSStringLength(const char*);
unsigned int __cdecl BSStringCapacityMaximum(unsigned int, unsigned int);
inline bool StrMem::Set(const char* source, unsigned int requested)
{
    unsigned int len = source ? BSStringLength(source) : 0;
    unsigned int max = BSStringCapacityMaximum(len, requested);
    if (max <= MaxLength())
    {
        if (max)
        {
            if (source)
                memcpy(text, source, len + 1);
            else
                text[0] = 0;
        }
        else
        {
            if (text)
            {
                char* released = text;
                delete[] released;
            }
            text = 0;
            max = 0;
            SetMaxLength(max);
        }
    }
    else
    {
        char* old = text;
        text = new char[max + 1];
        if (source)
            memcpy(text, source, len + 1);
        else
            text[0] = 0;
        if (old)
        {
            char* released = old;
            delete[] released;
        }
        SetMaxLength(max);
    }
    SetLength(len);
    return len != 0;
}
inline StrMem::~StrMem()
{
    Set(0, 0);
}

class FUN_00a0bb50
{
  public:
    StrMem first, second, third;
    ~FUN_00a0bb50();
};
// @fnv 0x00a0bb50
FUN_00a0bb50::~FUN_00a0bb50()
{}

struct Base670
{
    int m_field;
    void* m_data;
    void ClearAll()
    {
        while (m_field)
        {
            void* p1 = m_data;
            _NiFree_00aa10f0(p1);
            void* p2 = m_data;
            _NiFree_00aa10f0(p2);
            m_field--;
        }
    }
    static void operator delete(void* p)
    {
        _g_memoryManager.Deallocate(p);
    }
    virtual ~Base670()
    {
        ClearAll();
        _NiFree_00aa10f0(m_data);
    }
};
struct FUN_00a0d670 : Base670
{
// @fnv 0x00a0d670
    virtual ~FUN_00a0d670()
    {
        ClearAll();
    }
};
void Make670()
{
    delete new FUN_00a0d670;
}

struct TNode_a1be10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    void* unk2c;
};

static __forceinline void Dead8()
{
    int aiD[8];
}

struct ListHead_a1be10
{
    int m_00;
    int m_04;
    int m_08;
    ListHead_a1be10()
    {
        m_08 = 0;
        m_00 = 0;
        m_04 = 0;
        Dead8();
    }
    ~ListHead_a1be10();
};

struct Owner_a1be10
{
    ListHead_a1be10 m_kNode;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20[8];
    int m_40;

    Owner_a1be10(int p1, TNode_a1be10* p2, int p3, int p4);
    void AddItem(const void* p);
};

// @fnv 0x00a1be10
Owner_a1be10::Owner_a1be10(int p1, TNode_a1be10* p2, int p3, int p4)
{
    m_10 = p2->unk18 + p2->unk14;
    m_14 = p3;
    m_18 = p4;
    m_40 = p1;
    AddItem(&p2);
    m_1c = 0x23;
    p2->unk2c = this;
    for (int i = 0; i < 8; ++i)
        m_20[i] = 0;
}
