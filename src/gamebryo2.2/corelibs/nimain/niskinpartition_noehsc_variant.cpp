
// src/gamebryo2.2/corelibs/nimain/niskinpartition_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/nimain/niskinpartition.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../../../include/NiAccumulator.h"
#include "../../../../include/NiSkinPartition.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiRenderer.h"
const void* g_011f5b1c;
const void* __cdecl NiSkinPartition_GetRTTI();
void __stdcall FUN_00a82600(int a, int b, float c);
struct Holder
{
    unsigned short* m_pusData;
    unsigned int m_u4;
    unsigned int m_uiCount;
    bool ContainsSortedSubset(const Holder* pkOther);
};
extern int DAT_0109e47c;
struct P03MM
{
    void __thiscall _DeallocateAlias(void* p);
};
extern P03MM g_memoryManager;
struct S : NiRefObject
{
    int f4;
    int f8;
    void* fC;
    void __thiscall SetVtableAndProcessState_00a824d0();
};
struct NiTAbstractPoolAllocator_unsigned_int
{
    struct LinkedListEntry* ms_pFreeList;
    struct RecursiveSpinLock* ms_kPoolState;
};
#include "../../../../include/RecursiveSpinLock.h"
extern RecursiveSpinLock g_011c5f80;
extern unsigned int DAT_011c5f84;
extern NiTAbstractPoolAllocator_unsigned_int NiTAbstractPoolAllocator_unsigned_int_instance;
void __stdcall PoolFreeUIntNode(void* a);
void* __cdecl NiMalloc(unsigned int);
void __cdecl NiFreeAlias(void*);
struct FUN_00a82710_shell
{
    void* m_p;
    unsigned int m_iElementCount;
    unsigned int m_uiItemCount;
    void NiTSet_UInt16_Add(unsigned int n);
};
struct FUN_00a82890_shell
{
    char __thiscall ContainsAllValues(void*);
    char __thiscall ContainsAllIndexedTriples(const unsigned short* a, const void* b);
};
void __cdecl _delete(void*, unsigned int);
struct FUN_00a82c70_holder
{
    void SetVtableAndProcessState_00a824d0();
    void* DestroyIfFlagged(unsigned int);
};
struct C082d30
{
    unsigned short* f0;
    unsigned int f4;
    unsigned int f8;
    void NiTSet_UInt16_Add(unsigned int);
    void AppendMatchingIndices(int, int*, unsigned int);
};
struct Dummy13
{
    int v[13];
};
struct MyCls
{
    void* vf;
    int _04;
    int _08;
    Dummy13 _0c;
    int _40;
    int _44;
    void _Call_a5d3a0();
    void NiSkinData_ComputeBoneBounds(int);
    MyCls* InitFromData(int, int, const Dummy13&, int);
};
extern int DAT_0109e574;
int __cdecl NiSkinData_ComputeBoneBounds();
void* __cdecl _NiMalloc(unsigned int);
void __cdecl _NiFree(void*);
struct FUN_00a826b0_shell
{
    void* m_p;
    unsigned int m_uiItemCount;
    unsigned int m_uiBufferCapacity;
    void ReleaseStorage_00a826b0(unsigned int n);
};
struct FUN_00a81ff0_elem
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    bool NiSkinPartition_Partition_IsEqual(const FUN_00a81ff0_elem* other);
};
struct FUN_00a81ff0_cls
{
    int m_00;
    int m_04;
    unsigned int m_uiItemCount;
    FUN_00a81ff0_elem* m_pElements;
    bool IsSameAs(const FUN_00a81ff0_cls* other);
    bool Equals(const FUN_00a81ff0_cls* other);
};
struct S_00a82050_Node
{
    S_00a82050_Node* pNext;
    int iValue;
    float fValue;
};
struct S_00a82050_Base
{
    virtual ~S_00a82050_Base();
};
struct S_00a82050_Class : S_00a82050_Base
{
    void* p04;
    S_00a82050_Node** ppNodes;
    unsigned int uCount;

    virtual int __thiscall GetIndex(int);
    virtual bool __thiscall Compare(int, int);
    virtual void __thiscall Initialize(S_00a82050_Node*, int, float);
    virtual void Unknown();
    virtual S_00a82050_Node* __thiscall GetNode();

    void __thiscall FUN_00a82050(int, float);
};
S_00a82050_Base::~S_00a82050_Base()
{}
// Candidate reconstruction of ContainsAllValues (0x00a821f0, 83 bytes).
//
// What the original does (read from the image):
//   * ebx = the stack argument (a pointer to a block of 8-byte records),
//     ebp = ebx->unk08 (the number of records), esi = the record index,
//     edi = this.
//   * For every record it takes the 16-bit field at offset 0 of the record,
//     stores it into a 32-bit scratch slot that lives in the (by then dead)
//     incoming-argument slot, and hands the address of that slot to a CRT
//     binary-search helper together with this->unk00 (the array that is
//     searched), this->unk08 (its element count), the element size 2 and the
//     game's 16-bit comparison routine at 0x00a81b80.
//   * A record that is NOT found makes the function return 0; if every record
//     is found it returns 1.
//
// The helper and the comparison routine are declared but never defined, so the
// checker binds both call targets from the original's own bytes.
extern "C" void* __cdecl FNV_search_821f0(const void* key, const void* base, unsigned int count, unsigned int size,
                                          int(__cdecl* cmp)(const void*, const void*));
extern "C" int __cdecl FNV_cmp_us_821f0(const void* a, const void* b);
// One record of the list that is handed in: the 16-bit key sits at +0 and the
// record is eight bytes wide.
struct FNV_Rec_821f0
{
    unsigned short usVal;
    unsigned int unk04;
};
// The list handed in by the caller.
struct FNV_Arg_821f0
{
    FNV_Rec_821f0* unk00;
    unsigned int unk04;
    unsigned int unk08;
};
// The object that owns the array that is searched.
struct FNV_This_821f0
{
    unsigned short* m_pusData;
    unsigned int unk04;
    unsigned int m_uCount;
    char __thiscall ContainsAllValues(FNV_Arg_821f0* pArg);
};
void* __cdecl NiMalloc(unsigned int);
struct TriIndexList
{
    unsigned short* m_pusTriangles;
};
struct GeomData
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
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void GetTriangleVertexIndices(unsigned short i, unsigned short& i0, unsigned short& i1,
                                          unsigned short& i2) const;
    int unk04;
    unsigned short m_usVertices;
};
struct PartitionEx : NiSkinPartition::Partition
{
    unsigned short* BuildVertexRemapTable(const TriIndexList& kTriangles, const GeomData* pkData);
};
struct WeightedEntry
{
    void* key;
    float weight;
};
struct EntryGroup
{
    WeightedEntry* entries;
    unsigned int unk04;
    unsigned int count;
};
struct WeightedMapNode
{
    WeightedMapNode* next;
    void* key;
    float weight;
};
struct WeightedMap
{
    virtual void ReservedVirtual();
    virtual unsigned int HashKey(void* key);
    virtual bool KeysEqual(void* left, void* right);
    unsigned int unk04;
    WeightedMapNode** buckets;
    void FUN_00a82050(void* key, float weight);
};
void __stdcall MergeGroupWeights(WeightedMap* map, const unsigned short* groupIndices, EntryGroup* __restrict groups);
struct ItemSet
{
    void** m_items;
    unsigned int m_u4;
    unsigned int m_uiItemCount;
};
int __cdecl FindMatchingItem(ItemSet* set, const unsigned short* a2, const void* a3, unsigned char* flags,
                             unsigned char key);
// FUN_00a833a0 : constructor of a three-dword value object; zeroes all members.
struct FUN_00a833a0_cls
{
    int m_i00;
    int m_i04;
    int m_i08;

    FUN_00a833a0_cls();
};
__forceinline bool EqualBuffers(const void* right, const void* left, unsigned int bytes)
{
    const unsigned int* second = (const unsigned int*)right;
    const unsigned int* first = (const unsigned int*)left;
    while (bytes >= 4)
    {
        if (*first != *second)
            return false;
        bytes -= 4;
        ++second;
        ++first;
    }
    const unsigned char* tailFirst = (const unsigned char*)first;
    const unsigned char* tailSecond = (const unsigned char*)second;
    if (bytes)
    {
        if (tailSecond[0] != tailFirst[0])
            return false;
        if (bytes > 1)
        {
            if (tailSecond[1] != tailFirst[1])
                return false;
            if (bytes > 2 && tailSecond[2] != tailFirst[2])
                return false;
        }
    }
    return true;
}
struct PartitionCompare : NiSkinPartition::Partition
{
    bool NiSkinPartition_Partition_IsEqual(const PartitionCompare* other);
};
struct CA82250IndexArray
{
    unsigned short* m_pusData;
    unsigned int unk04;
    unsigned int m_uiSize;

    unsigned short Get(unsigned int uiIndex) const
    {
        if (uiIndex < m_uiSize)
            return m_pusData[uiIndex];
        return 0xffff;
    }
};
class CA82250MergeIterator
{
  public:
    unsigned int m_uiFirstPos;
    unsigned int m_uiSecondPos;
    unsigned short m_usFirst;
    unsigned short m_usSecond;
    CA82250IndexArray* m_pkFirst;
    CA82250IndexArray* m_pkSecond;

    unsigned int GetNext();
};
// Build this partition's triangle list: fetch each source triangle and remap its vertex indices.
void* NiMalloc(unsigned int uiSize);
struct A2400TriangleSet
{
    unsigned short* m_pusTriangles;
};
class A2400Source
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void GetTriangle(unsigned short m_usTriangleID, unsigned short& rusI0, unsigned short& rusI1,
                             unsigned short& rusI2);
};
class A2400Partition
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short* m_pusTriList;
    int unk18;
    unsigned short unk1C;
    unsigned short m_usTriangles;

    void BuildTriangleList(A2400TriangleSet* pkSet, A2400Source* pkSource, unsigned short* pusRemap);
};
inline bool Degenerate(const unsigned short* indices)
{
    if (indices[0] == indices[1])
        return true;
    if (indices[1] == indices[2])
        return true;
    if (indices[2] == indices[0])
        return true;
    return false;
}
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int) throw();
struct SkinGeom
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
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual __declspec(nothrow) void GetTriangle(unsigned int, unsigned short&, unsigned short&,
                                                 unsigned short&) throw();
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    unsigned short triangleCount;
};
struct SkinEntry
{
    int unk00;
    int unk04;
    int unk08;
    int key;
};
struct SkinItems
{
    SkinEntry** items;
    unsigned int capacity;
    unsigned int count;
};
struct SkinMapNode
{
    SkinMapNode* next;
    int key;
    int value;
};
struct SkinMap
{
    virtual ~SkinMap() throw()
    {
        FUN_00438af0();
        NiFreeAlias(buckets);
    }
    virtual __declspec(nothrow) unsigned int Hash(int key) throw();
    virtual __declspec(nothrow) bool Equal(int left, int right) throw();
    unsigned int size;
    SkinMapNode** buckets;
    unsigned int count;
    SkinMap() throw() : size(37), count(0)
    {
        buckets = (SkinMapNode**)NiMalloc(size * sizeof(SkinMapNode*));
        fnv_zlib_memset(buckets, 0, size * sizeof(SkinMapNode*));
    }
    __declspec(nothrow) void FUN_00438af0() throw();
    __declspec(nothrow) void InsertOrUpdate(int key, int value) throw();
    __declspec(nothrow) bool FUN_00a53c30(int key, int& value) throw();
    __declspec(nothrow) int Lookup(int key) throw()
    {
        SkinMapNode* node = buckets[Hash(key)];
        while (node)
        {
            if (Equal(key, node->key))
                return node->value;
            node = node->next;
        }
        return -1;
    }
};
struct SkinPointerMap : SkinMap
{
    SkinPointerMap() throw()
    {}
    ~SkinPointerMap() throw()
    {
        FUN_00438af0();
    }
};
struct SkinBuilder
{
    int unk00;
    int unk04;
    unsigned int count;
    __declspec(nothrow) void BuildBoneLODControllerSets(SkinGeom*, void*, SkinItems*, int*) throw();
    __declspec(nothrow) void NiSkinPartition_MergeBoneSets(unsigned int, SkinItems*) throw();
    bool BuildTriangleSetMapping(SkinGeom*, void*, unsigned int, void*, SkinItems*, int**, int*) throw();
};
template <class T> class SkinTArray
{
  public:
    virtual ~SkinTArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != T(0))
                m_usESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(const T& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};
typedef SkinTArray<char*> SkinViewerStrings;
struct SkinRTTI
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};
extern SkinRTTI g_kSkinPartitionRTTI;
char* __cdecl SkinGetViewerString(const char* pcName);
int __cdecl SkinSprintf(char* pcDest, unsigned int uiDestSize, const char* pcFormat, ...);
class SkinObjectBase
{
  public:
    virtual ~SkinObjectBase();
    void GetViewerStrings(SkinViewerStrings* pkStrings);
};
class SkinPartitionOwner : public SkinObjectBase
{
  public:
    unsigned int m_uiRefCount;
    unsigned int m_uiPartitionCount;
    NiSkinPartition::Partition* m_pPartitions;

    virtual ~SkinPartitionOwner();
    void NiSkinPartition_GetViewerStrings(SkinViewerStrings* pkStrings);
};
inline unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
                                                unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesWritten;
    return uiBytesWritten;
}
template <class T>
inline unsigned int SerializeValue(NiBinaryStream& binstream, const T* pvValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return binstream.BinaryWrite(pvValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline unsigned int SerializeValue(NiStream& bstream, const T& value)
{
    return SerializeValue(*bstream.m_pkOstr, &value, 1);
}
template <class T> inline unsigned int SerializeValue(NiStream& bstream, const T* pvValue, unsigned int uiNumEls)
{
    return SerializeValue(*bstream.m_pkOstr, pvValue, uiNumEls);
}
struct PartitionSave : NiSkinPartition::Partition
{
    void WriteToStream(NiStream& kStream);
};
struct Skp_00a828d0_pair
{
    unsigned int key;
    float weight;
};
struct Skp_00a828d0_grp
{
    Skp_00a828d0_pair* items;
    unsigned int unk04;
    unsigned int count;
};
struct Skp_00a828d0_src
{
    unsigned short* data;
    unsigned int unk04;
    unsigned int count;
};
struct Skp_00a828d0_cls : NiSkinPartition::Partition
{
    unsigned short* SplitTriangles(GeomData* pkData, void* pkSet);
    void ExpandTriangles(void* pkSet, void* pkSource, unsigned short* pusRemap);
    void PopulateSkinData(GeomData* pkData, Skp_00a828d0_src* pkSrc, void* pkSet, Skp_00a828d0_grp* pkGroups,
                          bool bWeights, bool bZeroPalette, unsigned char ucBonesPerVertex, unsigned int uiBones);
};
void* __cdecl AllocBlock(unsigned int uiSize);
void __cdecl FreeBlock(void* p);
void* __cdecl NiMalloc(unsigned int);
typedef unsigned int(__cdecl* NiBinaryStreamReadFn)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                    unsigned int* puiComponentSizes, unsigned int uiNumComponents);
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return m_pkIstr;
}
template <class T> inline void ReadBinaryValue(NiStream& kStream, T* ptVal, unsigned int auiCount = 1)
{
    kStream.GetBinaryStream()->BinaryRead(ptVal, auiCount);
}
struct PartitionLoader : NiSkinPartition::Partition
{
    void NiSkinPartition_Partition_LoadBinary(NiStream& kStream);
};
template <class T> inline void NiBinaryStreamSave(NiBinaryStream& os, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    // The old save-stream stand-in called +0x0C: NiBinaryStream::m_pfnWrite, not m_pfnRead (+0x08).
    os.BinaryWrite(pValue, sizeof(T) * uiNumEls, &uiSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& kStream, T& value)
{
    NiBinaryStreamSave(*kStream.m_pkOstr, &value, 1);
}
class FUN_00a89af0_helper
{
  public:
    void nullsub_3(NiStream& kStream);
};
class ElemA83C
{
  public:
    void WriteToStream(NiStream& kStream);
    int unk00[11];
};
class SaverA83C : public FUN_00a89af0_helper
{
  public:
    int m_unk00[2];
    unsigned int m_uiCount;
    ElemA83C* m_pkElems;

    void NiSkinPartition_SaveBinary(NiStream& kStream);
};

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesRead;
    return uiBytesRead;
}

template <class T> inline unsigned int LoadBinaryValues(NiBinaryStream& arStream, T* apValue, unsigned int auiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    return arStream.BinaryRead(apValue, auiNumEls * sizeof(T), &uiComponentSize, 1);
}

template <class T> inline void LBStreamLoadBinary(NiStream& arStream, T& arValue)
{
    LoadBinaryValues(*arStream.GetBinaryStream(), &arValue, 1);
}

struct LBMemoryManager
{
    void* Allocate(unsigned int auiSize);
};

extern LBMemoryManager g_kLBMemoryManager;

inline void* __cdecl operator new[](unsigned int auiSize)
{
    return g_kLBMemoryManager.Allocate(auiSize);
}

struct LBObject
{
    virtual ~LBObject();
    int unk04;

    void LoadBinary(NiStream& arStream);
};

struct LBPartition
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

    LBPartition() throw();
    ~LBPartition();
    void LoadBinary(NiStream& arStream);
};

struct LBSkinPartition : LBObject
{
    unsigned int m_uiPartitionCount;
    LBPartition* m_pPartitions;

    void NiSkinPartition_LoadBinary(NiStream& arStream);
};

// @fnv 0x00a83c30
// src: XBOX_PDB 0x00a83c30
void LBSkinPartition::NiSkinPartition_LoadBinary(NiStream& arStream)
{
    LBObject::LoadBinary(arStream);
    LBStreamLoadBinary(arStream, m_uiPartitionCount);
    m_pPartitions = new LBPartition[m_uiPartitionCount];
    for (unsigned int i = 0; i < m_uiPartitionCount; i++)
        m_pPartitions[i].LoadBinary(arStream);
}
