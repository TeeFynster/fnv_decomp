#include "../../../../include/NiTArray.h"

// src/gamebryo2.2/corelibs/nimain/niadditionalgeometrydata_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niadditionalgeometrydata.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/MemoryManager.h"

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;

// @fnv 0x00a72510
// src: COMMUNITY 0x00a72510
void* __stdcall NiAdditionalGeometryData_NiAGDDataBlock_AllocateBuffer(unsigned int size)
{
    if (size)
        return g_memoryManager.Allocate(size);
    return 0;
}

namespace fnv_00a727c0 {
struct P03MM
{
    void* __thiscall Allocate(unsigned int size);
};
extern P03MM g_memoryManager;
extern int DAT_0109cf58;
struct NiAGDDataBlock
{
    void* m_pData;
    int m_uiLogicalSize;
    int m_iArrayLength;
    unsigned char m_bFlag;
};
// @fnv 0x00a727c0
// src: XBOX_PDB 0x00a727c0
NiAGDDataBlock* __cdecl NiAdditionalGeometryData_CreateAGDDataBlock()
{
    NiAGDDataBlock* block = static_cast<NiAGDDataBlock*>(g_memoryManager.Allocate(16));
    if (block)
    {
        block->m_pData = &DAT_0109cf58;
        block->m_uiLogicalSize = 0;
        block->m_iArrayLength = 0;
        block->m_bFlag = 0;
        return block;
    }
    return 0;
}
}  // namespace fnv_00a727c0

namespace fnv_00a73080 {
extern int DAT_0102e274;
extern MemoryManager g_memoryManager;
void _NiFreeAlias(void*);
struct S
{
    void RemoveObject(int, int);
    void ReleaseEntries_00a73080();
    char _pad[0x28];
};
// @fnv 0x00a73080
// src: GUESS 0x00a73080 (confidence: medium)
void S::ReleaseEntries_00a73080()
{
    *(void**)this = (void*)&DAT_0102e274;
    for (unsigned int i = 0; i < *(unsigned short*)((char*)this + 0x26); ++i)
        RemoveObject(i, 1);
    void* p = *(void**)((char*)this + 0x14);
    if (p)
        g_memoryManager.Deallocate(p);
    void* q = *(void**)((char*)this + 0x20);
    *(const char**)((char*)this + 0x1c) = "@\nT";
    _NiFreeAlias(q);
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
}
}  // namespace fnv_00a73080

struct S00a72330
{
    int pad;
    unsigned int type;
    void NiAdditionalGeometryData_NiAGDDataStream_FillInByteSizeArray(unsigned int* out, unsigned int* idx, unsigned int unused);
};
// @fnv 0x00a72330
// src: GAMEBRYO_LIB 0x00a72330
void S00a72330::NiAdditionalGeometryData_NiAGDDataStream_FillInByteSizeArray(unsigned int* out, unsigned int* idx, unsigned int)
{
    switch (type)
    {
    case 4:
    case 8:
    case 12:
        out[(*idx)++] = 4;
    case 3:
    case 7:
    case 11:
        out[(*idx)++] = 4;
    case 2:
    case 6:
    case 10:
        out[(*idx)++] = 4;
    case 1:
    case 5:
    case 9:
        out[(*idx)++] = 4;
        return;
    case 16:
    case 20:
        out[(*idx)++] = 2;
    case 15:
    case 19:
        out[(*idx)++] = 2;
    case 14:
    case 18:
        out[(*idx)++] = 2;
    case 13:
    case 17:
        out[(*idx)++] = 2;
        return;
    case 24:
    case 28:
    case 32:
        out[(*idx)++] = 1;
    case 23:
    case 27:
    case 31:
        out[(*idx)++] = 1;
    case 22:
    case 26:
    case 30:
        out[(*idx)++] = 1;
    case 21:
    case 25:
    case 29:
        out[(*idx)++] = 1;
    }
}

struct FUN_00aa4060_owner
{
    void __thiscall MemoryManager_Deallocate(unsigned int value);
};

extern FUN_00aa4060_owner DAT_011f6238;

class FUN_00a72530_owner
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char unk0c;

    void __thiscall NiAdditionalGeometryData_NiAGDDataBlock_FreeBuffer(unsigned int value);
};

// @fnv 0x00a72530
// src: XBOX_PDB 0x00a72530
void __thiscall FUN_00a72530_owner::NiAdditionalGeometryData_NiAGDDataBlock_FreeBuffer(unsigned int value)
{
    if (value == 0 && unk0c != 0)
        value = unk08;

    DAT_011f6238.MemoryManager_Deallocate(value);
}

// The shared stream is opaque; retain this unit's inlined transfer operations.
inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(
        this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += uiBytesRead;
    return uiBytesRead;
}


template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* pkStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiCompSize = sizeof(T);
    pkStream->BinaryRead(pValue, uiNumEls * uiCompSize, &uiCompSize, 1);
}

template <class T> inline void LoadBinary(NiStream& kStream, T& val)
{
    NiBinaryStreamLoad(kStream.m_pkIstr, &val, 1);
}

template <class T> inline void LoadBinaryArray(NiStream& kStream, T* pVal, unsigned int uiElementCount)
{
    NiBinaryStreamLoad(kStream.m_pkIstr, pVal, uiElementCount);
}

inline unsigned int ReadUInt(NiStream& kStream)
{
    unsigned int uiValue;
    LoadBinary(kStream, uiValue);
    return uiValue;
}

inline unsigned int SumSizes(const unsigned int* p, unsigned int n)
{
    unsigned int s = 0;
    for (unsigned int j = 0; j < n; j++)
        s += p[j];
    return s;
}

class DataBlockStub
{
  public:
    virtual void Unk00();
    virtual char* Allocate(unsigned int uiSize);
    virtual void Finish(int a, int b);
    unsigned int m_uiSize;
    char* m_pcData;
    unsigned char m_bLoadComplete;
    unsigned char m_bOld;

    void NiAdditionalGeometryData_NiAGDDataBlock_LoadBinary(NiStream& kStream, int a2, int a3, int a4, unsigned short m_usPassCountLocal);
};

// @fnv 0x00a72eb0
// src: COMMUNITY 0x00a72eb0
void DataBlockStub::NiAdditionalGeometryData_NiAGDDataBlock_LoadBinary(NiStream& kStream, int a2, int a3, int a4, unsigned short m_usPassCountLocal)
{
    LoadBinary(kStream, m_uiSize);
    m_bOld = m_usPassCountLocal < 0x40;
    m_pcData = Allocate(m_uiSize);
    m_bLoadComplete = 1;

    unsigned int uiNumBlocks;
    LoadBinary(kStream, uiNumBlocks);
    unsigned int auiOffsets[32];
    LoadBinaryArray(kStream, auiOffsets, uiNumBlocks);

    for (unsigned int i = 0; i < uiNumBlocks; i++)
    {
        unsigned int uiNumComps = ReadUInt(kStream);
        unsigned int auiCompSizes[32];
        LoadBinaryArray(kStream, auiCompSizes, uiNumComps);

        char* pcDest = m_pcData + auiOffsets[i];
        NiBinaryStream* pkIstr = kStream.m_pkIstr;
        unsigned int uiStride = SumSizes(auiCompSizes, uiNumComps);
        pkIstr->BinaryRead(pcDest, uiStride * m_usPassCountLocal, auiCompSizes, uiNumComps);
    }

    Finish(0, 0);
}

namespace fnv_00a730e0 {
struct FixedAllocator
{
    void* Alloc(unsigned int size);
    void Free(void* p);
};
extern FixedAllocator DAT_011f6238;

struct SceneElem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;

    SceneElem() throw();
    static void* operator new[](unsigned int size) throw()
    {
        return DAT_011f6238.Alloc(size);
    }
    static void operator delete[](void* p) throw()
    {
        DAT_011f6238.Free(p);
    }
};

struct FUN_00a730e0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int m_pRayCursor;
    SceneElem* m_data;

    void NiAdditionalGeometryData_SetDataStreamCount(unsigned int newCount);
};

extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int n);

// @fnv 0x00a730e0
// src: COMMUNITY 0x00a730e0
void FUN_00a730e0_cls::NiAdditionalGeometryData_SetDataStreamCount(unsigned int newCount)
{
    SceneElem* oldData = m_data;
    SceneElem* newData = new SceneElem[newCount];
    m_data = newData;
    if (oldData != 0)
    {
        memcpy(newData, oldData, m_pRayCursor * 0x1c);
        delete[] oldData;
    }
    m_pRayCursor = newCount;
}
}  // namespace fnv_00a730e0

typedef NiTArray<int, NiTMallocInterface<int> > ArrayBase;
template <> inline NiTArray<int, NiTMallocInterface<int> >::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usGrowBy == 0)
            m_usGrowBy = 1;
        m_pBase = 0;
    }
template <> inline void NiTArray<int, NiTMallocInterface<int> >::RemoveAll()
{
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }

class PrimArray : public ArrayBase
{
  public:
    PrimArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) : ArrayBase(uiMaxSize, uiGrowBy)
    {}
    virtual void v0();
};

class FUN_00a734c0 : public NiObject
{
  public:
    FUN_00a734c0();
    virtual void v0();

    int m_08;
    unsigned short m_0c;
    int m_10;
    int m_14;
    int m_18;
    PrimArray m_kArray;
};

// @fnv 0x00a734c0
FUN_00a734c0::FUN_00a734c0()
{
    m_08 = 0;
    m_10 = 0;
    m_14 = 0;
    m_0c = 0;
    m_kArray.RemoveAll();
    m_18 = 0;
}

void* __cdecl Object_DispatchCommandFour(unsigned int);

struct Obj_a73e20
{
    Obj_a73e20* FUN_00a734c0();
};

// @fnv 0x00a73e20
// src: EXE 0x00a73e20
Obj_a73e20* __cdecl NiAdditionalGeometryData_CreateObject()
{
    Obj_a73e20* p = (Obj_a73e20*)Object_DispatchCommandFour(0x2c);
    if (p)
        return p->FUN_00a734c0();
    return 0;
}

struct Impl00a8a680
{
    Impl00a8a680(int a1, int a2, int a3, int a4, int a5, int a6, int a7) throw();
    static void* operator new(unsigned int size);
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
    int unk40;
};

struct Base00a804e0
{
    Base00a804e0(void* impl);
    virtual ~Base00a804e0();
    void* m_pClassImpl;
};

struct FUN_00a746e0 : Base00a804e0
{
    FUN_00a746e0(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    virtual ~FUN_00a746e0();
};

// @fnv 0x00a746e0
FUN_00a746e0::FUN_00a746e0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
    : Base00a804e0(new Impl00a8a680(a1, a2, a3, a4, a5, a6, a7))
{}

// Equality of two byte buffers: same size and identical contents.

extern "C" int __cdecl memcmp(const void* pvBuf1, const void* pvBuf2, unsigned int uiSize);

class A2440Buffer
{
  public:
    int unk00;
    unsigned int m_uiSize;
    unsigned char* m_pCompressedData;

    bool NiAdditionalGeometryData_NiAGDDataStream_IsEqual(const A2440Buffer& kOther) const;
};

// @fnv 0x00a72440
// src: XBOX_PDB 0x00a72440
bool A2440Buffer::NiAdditionalGeometryData_NiAGDDataStream_IsEqual(const A2440Buffer& kOther) const
{
    if (m_uiSize != kOther.m_uiSize)
        return false;
    int iResult = memcmp(m_pCompressedData, kOther.m_pCompressedData, m_uiSize);
    if (iResult != 0)
        return false;
    return true;
}

template <class T> inline unsigned int LBBinaryStreamLoad(NiBinaryStream& arStream, T* apValue, unsigned int auiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    return arStream.BinaryRead(apValue, auiNumEls * sizeof(T), &uiComponentSize, 1);
}


template <class T> inline void LBStreamLoadBinary(NiStream& arStream, T& arValue)
{
    LBBinaryStreamLoad(*arStream.m_pkIstr, &arValue, 1);
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

struct LBKey
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    LBKey() throw();
    void LoadBinary(NiStream& arStream);
};

struct LBBlock
{
    void LoadBinary(NiStream& arStream, unsigned int auiIndex, LBKey* apKeys, unsigned int auiNumKeys,
                    unsigned short ausKeyType);
};

template <class T> struct LBTArray
{
    void* pVtable;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int auiMaxSize);
    void SetAt(unsigned int auiIndex, const T& arElement)
    {
        if (auiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(auiIndex + 1);
            if (arElement != 0)
                m_usESize++;
        }
        else
        {
            if (arElement != 0)
            {
                if (m_pBase[auiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[auiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[auiIndex] = arElement;
    }
};

struct LBObject : NiObject
{
    virtual void Unk8C();
    virtual LBBlock* CreateBlock();

    int unk08;
    unsigned short m_usKeyType;
    unsigned int m_uiNumKeys;
    LBKey* m_pKeyArray;
    int unk18;
    LBTArray<LBBlock*> m_kBlocks;

    // Legacy base loader at 0x00a5d610, distinct from NiObject::LoadBinary.
    void LoadBaseBinary(NiStream& arStream);
    void NiAdditionalGeometryData_LoadBinary(NiStream& arStream);
};

// @fnv 0x00a73160
// src: XBOX_PDB 0x00a73160
void LBObject::NiAdditionalGeometryData_LoadBinary(NiStream& arStream)
{
    LoadBaseBinary(arStream);
    LBStreamLoadBinary(arStream, m_usKeyType);
    LBStreamLoadBinary(arStream, m_uiNumKeys);
    if (m_uiNumKeys)
    {
        m_pKeyArray = new LBKey[m_uiNumKeys];
        for (unsigned int i = 0; i < m_uiNumKeys; i++)
            m_pKeyArray[i].LoadBinary(arStream);
    }

    unsigned int uiBlocks = 0;
    LBStreamLoadBinary(arStream, uiBlocks);
    m_kBlocks.SetSize(uiBlocks);
    for (unsigned int j = 0; j < uiBlocks; j++)
    {
        bool bHasBlock;
        LBStreamLoadBinary(arStream, bHasBlock);
        if (bHasBlock)
        {
            LBBlock* pBlock = CreateBlock();
            pBlock->LoadBinary(arStream, j, m_pKeyArray, m_uiNumKeys, m_usKeyType);
            m_kBlocks.SetAt(j, pBlock);
        }
        else
        {
            m_kBlocks.SetAt(j, 0);
        }
    }
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
                                                unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytes = (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 12))(
        this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += uiBytes;
    return uiBytes;
}

template <class T>
inline unsigned int WriteBinaryArray(NiBinaryStream& kStream, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryWrite(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}


template <class T> inline void SerializeValue(NiStream* kStream, const T& val)
{
    WriteBinaryArray(*kStream->m_pkOstr, &val, 1);
}

struct ChildElem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void NiAdditionalGeometryData_NiAGDDataStream_SaveBinary(NiStream* stream);
};

struct ChildObj
{
    void NiAdditionalGeometryData_NiAGDDataBlock_SaveBinary(NiStream* stream, unsigned int index, ChildElem* elems, unsigned int count, unsigned int flags);
};

struct FUN_00a73370Node
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short flags;
    unsigned short unk0e;
    unsigned int elemCount;
    ChildElem* elems;
    int unk18;
    int unk1c;
    ChildObj** children;
    unsigned short unk24;
    unsigned short childCount;
    void LinkObject(NiStream* stream);
    void NiAdditionalGeometryData_SaveBinary(NiStream* stream);
};

// @fnv 0x00a73370
// src: XBOX_PDB 0x00a73370
void FUN_00a73370Node::NiAdditionalGeometryData_SaveBinary(NiStream* stream)
{
    LinkObject(stream);
    SerializeValue(stream, flags);
    SerializeValue(stream, elemCount);
    for (unsigned int i = 0; i < elemCount; i++)
    {
        elems[i].NiAdditionalGeometryData_NiAGDDataStream_SaveBinary(stream);
    }
    SerializeValue(stream, (unsigned int)childCount);
    for (unsigned int j = 0; j < childCount; j++)
    {
        ChildObj* c = children[j];
        bool present = (c != 0);
        SerializeValue(stream, present);
        if (present)
            c->NiAdditionalGeometryData_NiAGDDataBlock_SaveBinary(stream, j, elems, elemCount, flags);
    }
}

struct ArrayArg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void FUN_0096ad30(unsigned int n);
    void FUN_0096ae90(unsigned int idx, void* out);
};

extern const char str_0109d2f4[];
extern const char str_0109d2dc[];
unsigned int __cdecl NiGetViewerString_00a7d510(const char* s, unsigned int v);
unsigned int __cdecl NiGetViewerString_00a7d5a0(const char* s, unsigned int v);

struct FUN_00a73d90_cls
{
    unsigned int unk00;
    unsigned int m_04;
    unsigned int m_08;
    void NiAdditionalGeometryData_NiAGDDataBlock_GetViewerStrings(ArrayArg* p);
};

static inline void AddVal(ArrayArg* p, unsigned int v)
{
    unsigned int idx = p->m_0a;
    if (idx >= p->m_08)
    {
        p->FUN_0096ad30(idx + p->m_0e);
    }
    p->FUN_0096ae90(idx, &v);
}

// @fnv 0x00a73d90
// src: XBOX_PDB 0x00a73d90
void FUN_00a73d90_cls::NiAdditionalGeometryData_NiAGDDataBlock_GetViewerStrings(ArrayArg* p)
{
    AddVal(p, NiGetViewerString_00a7d510(str_0109d2f4, m_04));
    AddVal(p, NiGetViewerString_00a7d5a0(str_0109d2dc, m_08));
}

#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"
// Gamebryo NiTArray.inl bodies this unit's original inlines (the shared NiTArray declares them):
template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::SetAt(unsigned int uiSlot, const T& kItem)
{
    if (uiSlot >= this->m_usSize)
    {
        this->m_usSize = (unsigned short)(uiSlot + 1);
        if (kItem != T(0))
            this->m_usESize++;
    }
    else
    {
        if (kItem != T(0))
        {
            if (this->m_pBase[uiSlot] == T(0))
                this->m_usESize++;
        }
        else
        {
            if (this->m_pBase[uiSlot] != T(0))
                this->m_usESize--;
        }
    }
    this->m_pBase[uiSlot] = kItem;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiSlot, const T& kItem)
{
    if (uiSlot >= this->m_usMaxSize)
        SetSize(uiSlot + this->m_usGrowBy);
    SetAt(uiSlot, kItem);
    return uiSlot;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& kItem)
{
    return SetAtGrow(this->m_usSize, kItem);
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetSize() const
{
    return this->m_usSize;
}
template <class T, class TAlloc> inline const T& NiTArray<T, TAlloc>::GetAt(unsigned int uiSlot) const
{
    return this->m_pBase[uiSlot];
}
template <class T, class TAlloc> inline T& NiTArray<T, TAlloc>::GetAt(unsigned int uiSlot)
{
    return this->m_pBase[uiSlot];
}

char* CreateDebugString(const char* pcName);
char* CreateDebugString(const char* pcName, unsigned short usValue);
char* CreateDebugString(const char* pcName, unsigned int uiValue);
char* CreateDebugString(const char* pcName, int iValue);
char* CreateDebugString(const char* pcName, const char* pcValue);

extern const char* g_pcAdditionalGeometryDataName;

class AdditionalGeometryDataRecord
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void GetViewerStrings(NiViewerStringsArray* pkStrings);
};

class NiAGDDataBlock
{
  public:
    void GetViewerStrings(NiViewerStringsArray* pkStrings);
};

class NiAGDViewer : public NiObject
{
  public:
    int m_uiRevID;
    unsigned short m_usVertexCount;
    unsigned int m_uiDataStreamCount;
    AdditionalGeometryDataRecord* m_aDataStreamEntries;
    int m_uiDataStreamEntryUnk;
    NiTPrimitiveArray<NiAGDDataBlock*> m_aDataBlocks;

    // This unit calls the legacy base viewer routine at 0x00a5d6e0.
    // The shared NiObject viewer declaration names a different routine.
    void AppendBaseViewerStrings(NiViewerStringsArray* pkStrings);
    void NiAdditionalGeometryData_GetViewerStrings(NiViewerStringsArray* pkStrings);
};

// @fnv 0x00a73e40
// src: XBOX_PDB 0x00a73e40
void NiAGDViewer::NiAdditionalGeometryData_GetViewerStrings(NiViewerStringsArray* pkStrings)
{
    AppendBaseViewerStrings(pkStrings);

    pkStrings->Add(CreateDebugString(g_pcAdditionalGeometryDataName));
    pkStrings->Add(CreateDebugString("m_usVertexCount", m_usVertexCount));
    pkStrings->Add(CreateDebugString("m_uiDataStreamCount", m_uiDataStreamCount));
    for (unsigned int ui = 0; ui < m_uiDataStreamCount; ui++)
    {
        pkStrings->Add(CreateDebugString("    DataStream Index", ui));
        m_aDataStreamEntries[ui].GetViewerStrings(pkStrings);
    }
    pkStrings->Add(CreateDebugString("m_aDataBlocks.GetSize()", m_aDataBlocks.GetSize()));
    for (unsigned int ui = 0; ui < m_aDataBlocks.GetSize(); ui++)
    {
        pkStrings->Add(CreateDebugString("    DataBlock Index", ui));
        NiAGDDataBlock* pkBlock = m_aDataBlocks.GetAt(ui);
        if (pkBlock)
        {
            pkBlock->GetViewerStrings(pkStrings);
        }
        else
        {
            pkStrings->Add(CreateDebugString("        m_uiDataBlockSize", 0));
            pkStrings->Add(CreateDebugString("        m_pucDataBlock", "NULL"));
        }
    }
}

// This legacy load path dispatches through the callback at offset 0x0c.
inline unsigned int ReadBinary517(NiBinaryStream* input, void* data, unsigned int size,
                                  unsigned int* components, unsigned int count)
{
    unsigned int n = (*reinterpret_cast<NiBinaryStream::ReadFunction*>(reinterpret_cast<char*>(input) + 12))(
        input, data, size, components, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(input) + 4) += n;
    return n;
}
struct Descriptor517
{
    unsigned int unk00, type, unk08, unk0c, stride, block, offset;
    void NiAdditionalGeometryData_NiAGDDataStream_FillInByteSizeArray(unsigned int*, unsigned int*, unsigned int);
};
class Owner517
{
  public:
    virtual void v0();
    unsigned int size;
    char* data;
    void NiAdditionalGeometryData_NiAGDDataBlock_SaveBinary(NiStream& stream, unsigned int block, Descriptor517* entries, unsigned int count,
                      unsigned short vertices);
};
template <class T> inline void BinaryLoad517(NiBinaryStream* input, T* value, unsigned int count)
{
    unsigned int component = sizeof(T);
    ReadBinary517(input, value, count * component, &component, 1);
}
template <class T> inline void Load517(NiStream& stream, T& v)
{
    BinaryLoad517(stream.m_pkOstr, &v, 1);
}
template <class T> inline void LoadArray517(NiStream& stream, T* v, unsigned int count)
{
    BinaryLoad517(stream.m_pkOstr, v, count);
}
inline void ReadComponents517(NiBinaryStream* input, void* destination, unsigned short vertices, unsigned int* components,
                              unsigned int count)
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < count; i++)
        sum += components[i];
    ReadBinary517(input, destination, sum * vertices, components, count);
}
// @fnv 0x00a728d0
// src: XBOX_PDB 0x00a728d0
void Owner517::NiAdditionalGeometryData_NiAGDDataBlock_SaveBinary(NiStream& stream, unsigned int block, Descriptor517* entries, unsigned int count,
                            unsigned short vertices)
{
    Descriptor517* idx = entries;
    unsigned int readCount;
    Load517(stream, size);
    Descriptor517* sorted[32];
    int starts[32];
    unsigned int offsets[32];
    int found;
    found = 0;
    Descriptor517* temp;
    unsigned int components[32];
    for (unsigned int i = 0; i < count; i++)
    {
        if (idx[i].block == block)
            sorted[found++] = &idx[i];
    }
    for (unsigned int i = 0; i < found; i++)
    {
        Descriptor517* entry = sorted[i];
        for (unsigned int j = 0; j < i; j++)
        {
            bool pData = sorted[j]->offset > entry->offset;
            bool iIndex = 0 != pData;
            if (0 != iIndex)
            {
                temp = sorted[j];
                sorted[j] = entry;
                entry = temp;
            }
        }
        sorted[i] = entry;
    }
    unsigned int groups = 1;
    Descriptor517* previous = sorted[0];
    starts[0] = 0;
    offsets[0] = 0;
    for (unsigned int i = 1; found > i; i++)
    {
        if (sorted[i]->offset > previous->offset + previous->stride * vertices)
        {
            starts[groups] = i;
            offsets[groups] = sorted[i]->offset;
            ++groups;
            previous = sorted[i];
        }
    }
    starts[groups] = found;
    Load517(stream, groups);
    LoadArray517(stream, offsets, groups);
    for (unsigned int i = 0; i < groups; i++)
    {
        unsigned int begin = starts[i];
        {
            unsigned int componentCount = 0;
            for (unsigned int j = begin; j < starts[i + 1]; j++)
                sorted[j]->NiAdditionalGeometryData_NiAGDDataStream_FillInByteSizeArray(components, &componentCount, 32);
            readCount = componentCount;
        }
        Load517(stream, readCount);
        LoadArray517(stream, components, readCount);

        ReadComponents517(stream.m_pkOstr, (sorted[begin]->offset + data), vertices, components, readCount);
    }
}

namespace fnv_00a724e0 {
struct DummyMM
{
    void _DeallocateAlias(void*);
};
extern DummyMM g_memoryManager;
struct FUN_00a724e0
{
    virtual ~FUN_00a724e0();
    void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};
// @fnv 0x00a724e0
FUN_00a724e0::~FUN_00a724e0()
{}
}  // namespace fnv_00a724e0

struct StringArray73530
{
    virtual void v0();
    const char** data;
    unsigned short capacity;
    unsigned short size;
    unsigned short effectiveSize;
    unsigned short growBy;
    void FUN_0096a610(const char* const* value);
    void FUN_0096ad30(unsigned int capacity);
    void FUN_0096ae90(unsigned int index, const char* const* value);
    void Append(const char* const& value)
    {
        unsigned int index = size;
        if (index >= capacity)
            FUN_0096ad30(index + growBy);
        FUN_0096ae90(index, &value);
    }
};
const char* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);
const char* __cdecl NiGetViewerString(const char*, bool);
struct Descriptor73530
{
    unsigned char flags;
    const char* GetConsistencyString() const
    {
        switch (flags & 6)
        {
        case 2:
            return NiGetViewerString_00a7d5e0("        Consistency", "MUTABLE");
        case 3:
            goto staticConsistency;
        default:
        staticConsistency:
            return NiGetViewerString_00a7d5e0("        Consistency", "STATIC");
        }
    }
    __forceinline void AppendConsistency(StringArray73530* output) const
    {
        const char* value;
        switch (flags & 6)
        {
        case 2:
            value = NiGetViewerString_00a7d5e0("        Consistency", "MUTABLE");
            output->Append(value);
            break;
        case 3:
            goto staticConsistency;
        default:
        staticConsistency:
            value = NiGetViewerString_00a7d5e0("        Consistency", "STATIC");
            output->Append(value);
            break;
        }
    }
    unsigned int type, unitSize, totalSize, stride, blockIndex, blockOffset;
    void NiAdditionalGeometryData_NiAGDDataStream_GetViewerStrings(StringArray73530* output);
};
// @fnv 0x00a73530
// src: XBOX_PDB 0x00a73530
void Descriptor73530::NiAdditionalGeometryData_NiAGDDataStream_GetViewerStrings(StringArray73530* output)
{
    const char* value;
    switch (type)
    {
    case 0:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_INVALID");
        output->FUN_0096a610(&value);
        break;
    case 1:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_FLOAT1");
        output->FUN_0096a610(&value);
        break;
    case 2:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_FLOAT2");
        output->FUN_0096a610(&value);
        break;
    case 3:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_FLOAT3");
        output->FUN_0096a610(&value);
        break;
    case 4:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_FLOAT4");
        output->FUN_0096a610(&value);
        break;
    case 5:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_LONG1");
        output->FUN_0096a610(&value);
        break;
    case 6:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_LONG2");
        output->FUN_0096a610(&value);
        break;
    case 7:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_LONG3");
        output->FUN_0096a610(&value);
        break;
    case 8:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_LONG4");
        output->FUN_0096a610(&value);
        break;
    case 9:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_ULONG1");
        output->FUN_0096a610(&value);
        break;
    case 10:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_ULONG2");
        output->FUN_0096a610(&value);
        break;
    case 11:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_ULONG3");
        output->FUN_0096a610(&value);
        break;
    case 12:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_ULONG4");
        output->FUN_0096a610(&value);
        break;
    case 13:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_SHORT1");
        output->FUN_0096a610(&value);
        break;
    case 14:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_SHORT2");
        output->FUN_0096a610(&value);
        break;
    case 15:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_SHORT3");
        output->FUN_0096a610(&value);
        break;
    case 16:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_SHORT4");
        output->FUN_0096a610(&value);
        break;
    case 17:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_USHORT1");
        output->FUN_0096a610(&value);
        break;
    case 18:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_USHORT2");
        output->FUN_0096a610(&value);
        break;
    case 19:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_USHORT3");
        output->FUN_0096a610(&value);
        break;
    case 20:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_USHORT4");
        output->FUN_0096a610(&value);
        break;
    case 21:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_BYTE1");
        output->FUN_0096a610(&value);
        break;
    case 22:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_BYTE2");
        output->FUN_0096a610(&value);
        break;
    case 23:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_BYTE3");
        output->FUN_0096a610(&value);
        break;
    case 24:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_BYTE4");
        output->FUN_0096a610(&value);
        break;
    case 25:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_UBYTE1");
        output->FUN_0096a610(&value);
        break;
    case 26:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_UBYTE2");
        output->FUN_0096a610(&value);
        break;
    case 27:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_UBYTE3");
        output->FUN_0096a610(&value);
        break;
    case 28:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_UBYTE4");
        output->FUN_0096a610(&value);
        break;
    case 29:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_BLEND1");
        output->FUN_0096a610(&value);
        break;
    case 30:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_BLEND2");
        output->FUN_0096a610(&value);
        break;
    case 31:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_BLEND3");
        output->FUN_0096a610(&value);
        break;
    case 32:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_BLEND4");
        output->FUN_0096a610(&value);
        break;
    case 33:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "AGD_NITYPE_COUNT");
        output->FUN_0096a610(&value);
        break;
    default:
        value = NiGetViewerString_00a7d5e0("        m_uiType", "UNKNOWN!!!");
        output->Append(value);
        break;
    }
    output->Append((const char*)NiGetViewerString_00a7d510("        m_uiUnitSize", unitSize));
    output->Append((const char*)NiGetViewerString_00a7d510("        m_uiTotalSize", totalSize));
    output->Append((const char*)NiGetViewerString_00a7d510("        m_uiStride", stride));
    output->Append((const char*)NiGetViewerString_00a7d510("        m_uiBlockIndex", blockIndex));
    output->Append((const char*)NiGetViewerString_00a7d510("        m_uiBlockOffset", blockOffset));
    bool keepValue = (flags & 1) != 0;
    output->Append(NiGetViewerString("        Keep", keepValue));
    AppendConsistency(output);
}

class NiAGDStream
{
  public:
    unsigned char m_ucFlags;
    unsigned int m_uiType;
    unsigned int m_uiUnitSize;
    unsigned int m_uiTotalSize;
    unsigned int m_uiStride;
    unsigned int m_uiBlockIndex;
    unsigned int m_uiBlockOffset;

    bool IsEqual(const NiAGDStream& kOther) const
    {
        if (m_uiType != kOther.m_uiType || m_uiUnitSize != kOther.m_uiUnitSize ||
            m_uiTotalSize != kOther.m_uiTotalSize || m_uiStride != kOther.m_uiStride ||
            m_uiBlockIndex != kOther.m_uiBlockIndex || m_uiBlockOffset != kOther.m_uiBlockOffset ||
            m_ucFlags != kOther.m_ucFlags)
        {
            return false;
        }
        return true;
    }
};
class NiAGDObject : public NiObject
{
  public:
    int m_uiRevID;
    unsigned short m_usVertexCount;
    unsigned int m_uiDataStreamCount;
    NiAGDStream* m_aDataStreamEntries;
    int unk18;
    NiTPrimitiveArray<A2440Buffer*> m_aDataBlocks;

    bool NiAdditionalGeometryData_IsEqual(NiObject* pkObject);
};
// @fnv 0x00a727f0
// src: XBOX_PDB 0x00a727f0
bool NiAGDObject::NiAdditionalGeometryData_IsEqual(NiObject* pkObject)
{
    if (!NiObject::IsSameAs(pkObject))
        return false;

    NiAGDObject* pkOther = (NiAGDObject*)pkObject;

    if (m_usVertexCount != pkOther->m_usVertexCount || m_uiDataStreamCount != pkOther->m_uiDataStreamCount)
    {
        return false;
    }

    unsigned int ui;
    for (ui = 0; ui < m_uiDataStreamCount; ui++)
    {
        if (!m_aDataStreamEntries[ui].IsEqual(pkOther->m_aDataStreamEntries[ui]))
            return false;
    }

    unsigned int uiSize = m_aDataBlocks.GetSize();
    for (ui = 0; ui < uiSize; ui++)
    {
        A2440Buffer* pkBlock = m_aDataBlocks.GetAt(ui);
        A2440Buffer* pkOtherBlock = pkOther->m_aDataBlocks.GetAt(ui);
        if (!pkOtherBlock)
        {
            if (pkBlock)
                return false;
        }
        else
        {
            if (!pkBlock)
                return false;
            if (!pkBlock->NiAdditionalGeometryData_NiAGDDataStream_IsEqual(*pkOtherBlock))
                return false;
        }
    }

    return true;
}
