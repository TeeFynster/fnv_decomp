
// src/havok/common/serialize/util/hkstructurelayout.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkstructurelayout.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dc1680
{
    int m_uiFilterValue;

    FUN_00dc1680(const FUN_00dc1680& other);
};

// @fnv 0x00dc1680
FUN_00dc1680::FUN_00dc1680(const FUN_00dc1680& other) : m_uiFilterValue(other.m_uiFilterValue)
{}

struct Provider
{
    int unk00, unk04, value8;
    __declspec(noinline) int FUN_00d470d0();
};
struct Owner
{
    unsigned int unk00;
    Provider* provider4;
    unsigned int unk08;
    unsigned char unk0c, tag0d;
    unsigned short unk0e;
    __declspec(noinline) int FUN_00d86b30();
    __declspec(noinline) Provider* FUN_00d86910();
    int GetTagValue();
};
struct DataBufferInfo
{
    short value;
    unsigned short unk02;
    unsigned int unk04, unk08;
};
extern "C" DataBufferInfo g_011b6ab8[];
__declspec(noinline) int Owner::FUN_00d86b30()
{
    return tag0d;
}
__declspec(noinline) Provider* Owner::FUN_00d86910()
{
    return provider4;
}
__declspec(noinline) int Provider::FUN_00d470d0()
{
    return value8;
}
// Returns -1 for tags 0x18/0x1f, the provider's value8 for tag 0x19, otherwise g_011b6ab8[tag].value.
// @fnv 0x00d86b40
int Owner::GetTagValue()
{
    if (FUN_00d86b30() == 0x18 || FUN_00d86b30() == 0x1f)
        return -1;
    if (FUN_00d86b30() != 0x19)
        return g_011b6ab8[FUN_00d86b30()].value;
    return FUN_00d86910()->FUN_00d470d0();
}

struct SizeNode;

struct SizeNodeList
{
    int FUN_00d46f00();
    SizeNode* getMember(int index);
};

struct SizeNode
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned short unk0E;
    unsigned short unk10;

    int GetAlignment();
    SizeNodeList* FUN_00d86910();
};

// Returns a value for the node based on its type, recursing for types 19 and 25, then clamps it to a minimum derived from node->unk10 flags.
// @fnv 0x00dc1850
extern "C" int __cdecl GetNodeValue(SizeNode* node, int type, int fallback)
{
    int result = -1;
    switch (type)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 24:
    case 31:
    case 32:
        result = node->GetAlignment();
        break;
    case 20:
    case 21:
    case 22:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 33:
        result = fallback;
        break;
    case 19: {
        int t = node->unk0D;
        result = GetNodeValue(node, t, fallback);
    }
    break;
    case 25: {
        int best = 1;
        SizeNodeList* list = node->FUN_00d86910();
        for (int iIndex = 0; iIndex < list->FUN_00d46f00(); iIndex++)
        {
            SizeNode* child = list->getMember(iIndex);
            int t = child->unk0C;
            int r = GetNodeValue(child, t, fallback);
            if (r > best)
                best = r;
        }
        result = best;
        break;
    }
    }
    int flags = node->unk10 & 0x180;
    if (flags)
    {
        int minimum = (flags == 0x100) ? 16 : 8;
        if (minimum > result)
            result = minimum;
    }
    return result;
}

struct Log_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int a, unsigned int b, char* c, const char* d, int e);
};

struct StrBuf_cls
{
    int m_00;
    int m_04;
    int m_08;
    void Init(void* buf, unsigned int n);
    void Assign(const char* s);
    void Free();
};

struct Lay_cls
{
    int unk00;
    int unk04;
    int unk08;
    char unk0c;
    unsigned char m_type;
    int F86980();
    int F86940();
    int F86910();
};
struct Mem_cls
{
    int F470d0();
};

extern Log_cls* DAT_01268360;
int GetMemberSize(Lay_cls* a1, unsigned char* a2, int a3);

// Returns the byte size of a structure member based on its type code, recursing for type 18 and logging an error for unknown types.
// @fnv 0x00dc1690
int GetMemberSize(Lay_cls* pLayout, unsigned char* pMemberData, int iType)
{
    int r = 0;
    switch (iType - 1)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 23:
    case 30:
    case 31:
        r = pLayout->F86980();
        break;
    case 19:
    case 20:
    case 28:
    case 29:
    case 32: {
        int m = *pMemberData;
        r = (pLayout->F86940() != 0 ? pLayout->F86940() : 1) * m;
        break;
    }
    case 27:
        r = *pMemberData * 2;
        break;
    case 21:
        r = 4;
    case 25:
        r = r + *pMemberData + 4;
        break;
    case 24: {
        int m = ((Mem_cls*)(pLayout->F86910()))->F470d0();
        r = (pLayout->F86940() != 0 ? pLayout->F86940() : 1) * m;
        break;
    }
    case 22:
        break;
    case 18: {
        int t = pLayout->m_type;
        r = GetMemberSize(pLayout, pMemberData, t);
        break;
    }
    case 26:
        r = *pMemberData * 2 + 4;
        break;
    default: {
        unsigned int buf[0x80];
        StrBuf_cls s;
        s.Init(buf, 0x200);
        s.Assign("Unknown class member type in structureLayout::getMemberSize().");
        if (DAT_01268360->v3(3, 0x50a18b58, (char*)buf, ".\\Util\\hkStructureLayout.cpp", 0xc3))
            __debugbreak();
        s.Free();
        break;
    }
    }
    return r;
}

struct FUN_00cb18f0_Obj
{
    int unk00;
    int unk04;
    int unk08;

    int __thiscall FindSlot(int value);
};

extern "C" void __cdecl Object_ComputeMemberLayoutRecursively(unsigned int value1, void* value2, void* value3, int value4);

class FUN_00dc1bb0_Class
{
  public:
    void UpdateState_00dc1bb0(unsigned int param1, unsigned int param2, int param3);
};

// Calls FindSlot on the object with param1 and, if the result exceeds object->unk08, calls FUN_00dc1960 with this, object and param3.
// @fnv 0x00dc1bb0
// src: GUESS 0x00dc1bb0 (confidence: low)
void FUN_00dc1bb0_Class::UpdateState_00dc1bb0(unsigned int uiValue, unsigned int pObject, int param3)
{
    FUN_00cb18f0_Obj* object = reinterpret_cast<FUN_00cb18f0_Obj*>(pObject);
    int result = object->FindSlot(uiValue);

    if (result > object->unk08)
    {
        Object_ComputeMemberLayoutRecursively(uiValue, this, object, param3);
    }
}

enum MemberKind
{
    KindNone = 0
};
template <class E, class S> struct EnumStorage
{
    S value;
    EnumStorage()
    {}
    EnumStorage(E v) : value((S)v)
    {}
    operator E() const
    {
        return (E)value;
    }
};
struct ByteBool
{
    char value;
    ByteBool(bool v) : value((char)v)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct LayoutOptions
{
    unsigned char pointerBytes, littleEndian, reusePadding, emptyBase;
};
extern "C" void _ReadWriteBarrier();
struct Allocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* ptr, int size);
};
struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    Allocator* allocator;
    void* unk10;
};
extern "C" Manager* __cdecl hkMemoryRouter_getInstance();
struct NodeListEx;
struct NodeEx
{
    const char* name;
    const NodeListEx* child;
    const void* enumeration;
    EnumStorage<MemberKind, unsigned char> unk0C;
    EnumStorage<MemberKind, unsigned char> unk0D;
    unsigned short unk0E;
    unsigned short unk10;
    unsigned short unk12;
    int ReadWorldData() const
    {
        return unk12;
    }
    void SetOffset(int v)
    {
        unk12 = (unsigned short)v;
    }
    MemberKind ReadType() const
    {
        return (MemberKind)unk0C;
    }
    int GetAlignment();
    NodeListEx* FUN_00d86910();
};
struct NodeListEx
{
    const char* name;
    const NodeListEx* parent;
    int objectSize;
    int interfaceCount;
    const void* enums;
    int enumCount;
    const NodeEx* members;
    int memberCount;
    const void* defaults;
    const void* attributes;
    unsigned int flags;
    int version;
    int FUN_00d46f00() const;
    const NodeEx& FUN_00d46f60(int index) const;
    const NodeListEx* FUN_00d46d50() const;
    int GetUnk0C_00d46e20() const;
    int FUN_00d46f70() const;
    const NodeEx& FUN_00d46f80(int index) const;
    int FUN_00d470d0() const;
    void FUN_00d470e0(int val);
};
struct Arg2
{
    int unk00;
    int unk04;
    int unk08;
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void* unk10, NodeListEx* list, int zero);
    int FindSlot(NodeListEx* sublist);
    ByteBool Valid(int i) const
    {
        return i <= unk08;
    }
    ByteBool IsMissing(NodeListEx* p)
    {
        return !Valid(FindSlot(p));
    }
};
struct Array
{
    NodeListEx** m_data;
    int m_iElementCount;
    int m_pRayCursor;
    void CallWithFlag(Allocator* allocator, int index, NodeListEx* const& item);
    void Free()
    {
        Manager* mgr = hkMemoryRouter_getInstance();
        Allocator* alloc = mgr->allocator;
        int cap = m_pRayCursor;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc->Free(m_data, (cap & 0x3fffffff) * sizeof(NodeListEx*));
        }
    }
};
// Recursively visits child node lists, then computes and stores member offsets and total size for each node list based on layout options.
// @fnv 0x00dc1960
// src: GUESS 0x00dc1960 (confidence: medium)
void __cdecl Object_ComputeMemberLayoutRecursively(NodeListEx& root, const LayoutOptions& options, Arg2& visited, int arg3)
{
    Manager* i = hkMemoryRouter_getInstance();
    visited.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(i->unk10, (&root), 0);
    if (0 != arg3)
    {
        int fallback = root.FUN_00d46f00();
        long r;
        r = 0;
        if (0 < fallback)
        {
            do
            {
                NodeEx* tmp;
                tmp = const_cast<NodeEx*>(&root.FUN_00d46f60(r));
                if (tmp->child)
                {
                    if (visited.IsMissing(tmp->FUN_00d86910()))
                    {
                        Object_ComputeMemberLayoutRecursively(*tmp->FUN_00d86910(), options, visited, arg3);
                    }
                }
                r++;
            } while (r < fallback);
        }
    }
    Array nodeArray;
    nodeArray.m_data = 0;
    nodeArray.m_iElementCount = 0;
    nodeArray.m_pRayCursor = 0x80000000;
    NodeListEx* pNodeList = (&root);
    while (pNodeList)
    {
        NodeListEx* pCurrent = pNodeList;
        Manager* m = hkMemoryRouter_getInstance();
        nodeArray.CallWithFlag(m->allocator, 0, pCurrent);
        pNodeList = const_cast<NodeListEx*>(pNodeList->FUN_00d46d50());
    }
    int iPointerSize;
    arg3 = 1;
    iPointerSize = options.pointerBytes;
    int n = 0;
    for (int tmp = 0; tmp < nodeArray.m_iElementCount; ++tmp)
    {
        NodeListEx* idx = nodeArray.m_data[tmp];
        for (int r = 0; r < idx->GetUnk0C_00d46e20(); ++r)
        {
            int iRemainder = n % iPointerSize;
            if (iRemainder != 0)
            {
                n += iPointerSize - iRemainder;
            }
            n += iPointerSize;
            if (iPointerSize > arg3)
            {
                arg3 = iPointerSize;
            }
        }
        for (int k = 0; k < idx->FUN_00d46f70(); ++k)
        {
            NodeEx* kIter = const_cast<NodeEx*>(&idx->FUN_00d46f80(k));
            if (0 == n && tmp != 0 && options.emptyBase == 0)
            {
                n = 1;
            }
            int iSize = GetNodeValue((SizeNode*)kIter, kIter->ReadType(), options.pointerBytes);
            if (iSize > arg3)
            {
                arg3 = iSize;
            }
            int iRemainder;
            iRemainder = n % iSize;
            if (0 != iRemainder)
            {
                n += iSize - iRemainder;
            }
            if (kIter->ReadWorldData() != n)
            {
                kIter->SetOffset(n);
            }
            n += GetMemberSize((Lay_cls*)kIter, ((unsigned char*)&options), kIter->ReadType());
        }
        int j = n % arg3;
        int kIter = n;
        if (j)
        {
            kIter = arg3 - j;
        }
        if (j)
        {
            kIter += n;
        }
        long c = kIter ? kIter : 1;
        if (idx->FUN_00d470d0() != c)
        {
            idx->FUN_00d470e0(c);
        }
        if (options.reusePadding == 0)
        {
            n = kIter;
        }
    }
    nodeArray.Free();
}
